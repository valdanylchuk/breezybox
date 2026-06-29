/*
 * ssh_server.c - SSH server for BreezyBox
 *
 * Single-connection SSH server. Each session runs in the server task itself:
 *   1. ssh_bind_accept blocks until a client connects
 *   2. Key exchange + auth negotiated via ssh_event_dopoll loop
 *   3. Shell REPL runs in the server task with _REENT->_stdout redirected
 *      to the SSH channel via a VFS, so all printf() from commands reaches
 *      the SSH client
 *   4. Input is read character-by-character from the channel with local echo
 *   5. On disconnect/exit the task loops back to accept
 *
 * Credentials: SSH_USERNAME / SSH_PASSWORD (see below)
 */

#include "ssh_server.h"

#include <libssh/libssh.h>
#include <libssh/server.h>
#include <libssh/callbacks.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "esp_vfs.h"
#include "esp_heap_caps.h"

#include <sys/reent.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>

static const char *TAG = "ssh_srv";

#define SSH_VFS_PATH    "/dev/sshcon"
#define SSH_USERNAME    "breezy"
#define SSH_PASSWORD    "breezy"
#define SSH_TASK_STACK  16384
#define SSH_TASK_PRIO   5

// Host key embedded by CMake EMBED_FILES; ESP-IDF appends a null byte.
extern const char ssh_host_ed25519_key_start[] asm("_binary_ssh_host_ed25519_key_start");

// ---- Per-connection state (single connection only) ---- //

typedef struct {
    ssh_session         session;
    ssh_channel         channel;
    volatile bool       authenticated;
    volatile bool       shell_requested;
    volatile bool       failed;
    int                 auth_tries;
} ssh_conn_t;

static ssh_conn_t s_conn;

// ---- Server state ---- //

static ssh_bind        s_sshbind       = NULL;
static TaskHandle_t    s_server_task   = NULL;
static volatile bool   s_running       = false;

// ---- Host integration hooks (injected by the host firmware) ---- //

static breezy_ssh_host_t s_host;

void ssh_server_set_host(const breezy_ssh_host_t *host)
{
    if (host) {
        s_host = *host;
    } else {
        memset(&s_host, 0, sizeof(s_host));
    }
}

// ---- SSH output VFS ---- //
// Only write matters here; read is a no-op placeholder.
// Translates \n → \r\n so SSH terminal clients see proper line breaks.

static ssize_t sshvfs_write(int fd, const void *data, size_t size)
{
    if (!s_conn.channel || ssh_channel_is_eof(s_conn.channel)) {
        return (ssize_t)size;  // discard gracefully
    }
    const char *p   = (const char *)data;
    const char *end = p + size;
    while (p < end) {
        const char *nl    = memchr(p, '\n', (size_t)(end - p));
        size_t      chunk = nl ? (size_t)(nl - p) : (size_t)(end - p);
        if (chunk > 0) {
            ssh_channel_write(s_conn.channel, p, (uint32_t)chunk);
        }
        if (nl) {
            ssh_channel_write(s_conn.channel, "\r\n", 2);
            p = nl + 1;
        } else {
            p = end;
        }
    }
    return (ssize_t)size;
}

static ssize_t sshvfs_read(int fd, void *data, size_t size)
{
    // Not used by the REPL (input comes via ssh_readline), but required by VFS.
    errno = EAGAIN;
    return -1;
}

static int sshvfs_open(const char *path, int flags, int mode) { return 0; }
static int sshvfs_close(int fd) { return 0; }
static int sshvfs_fstat(int fd, struct stat *st)
{
    memset(st, 0, sizeof(*st));
    st->st_mode = S_IFCHR;
    return 0;
}

static void register_sshvfs(void)
{
    static bool registered = false;
    if (registered) return;
    const esp_vfs_t vfs = {
        .flags = ESP_VFS_FLAG_DEFAULT,
        .write = sshvfs_write,
        .read  = sshvfs_read,
        .open  = sshvfs_open,
        .close = sshvfs_close,
        .fstat = sshvfs_fstat,
    };
    ESP_ERROR_CHECK(esp_vfs_register(SSH_VFS_PATH, &vfs, NULL));
    registered = true;
}

// ---- Auth callbacks ---- //

static int auth_none_cb(ssh_session session, const char *user, void *ud)
{
    ssh_set_auth_methods(session, SSH_AUTH_METHOD_PASSWORD);
    return SSH_AUTH_DENIED;
}

static int auth_password_cb(ssh_session session, const char *user,
                             const char *pass, void *ud)
{
    ssh_conn_t *c = ud;
    if (strcmp(user, SSH_USERNAME) == 0 && strcmp(pass, SSH_PASSWORD) == 0) {
        c->authenticated = true;
        return SSH_AUTH_SUCCESS;
    }
    if (++c->auth_tries >= 3) c->failed = true;
    return SSH_AUTH_DENIED;
}

// ---- Channel callbacks ---- //

static struct ssh_channel_callbacks_struct s_ch_cb;

static int s_ssh_rows = 24;
static int s_ssh_cols = 80;

static int pty_req_cb(ssh_session session, ssh_channel channel,
                      const char *term, int cols, int rows,
                      int py, int px, void *ud)
{
    ESP_LOGI(TAG, "PTY: %s %dx%d", term, cols, rows);
    s_ssh_rows = rows;
    s_ssh_cols = cols;
    return SSH_OK;
}

static int shell_req_cb(ssh_session session, ssh_channel channel, void *ud)
{
    ssh_conn_t *c = ud;
    c->shell_requested = true;
    return SSH_OK;
}

static ssh_channel channel_open_cb(ssh_session session, void *ud)
{
    ssh_conn_t *c = ud;
    if (c->channel) return NULL;  // reject second channel

    c->channel = ssh_channel_new(session);

    memset(&s_ch_cb, 0, sizeof(s_ch_cb));
    s_ch_cb.userdata                        = c;
    s_ch_cb.channel_pty_request_function    = pty_req_cb;
    s_ch_cb.channel_shell_request_function  = shell_req_cb;
    ssh_callbacks_init(&s_ch_cb);
    ssh_set_channel_callbacks(c->channel, &s_ch_cb);

    return c->channel;
}

// ---- Input: line reader with echo and backspace ---- //

// Reads one line from the SSH channel.
// Returns line length (0 for empty), or -1 on EOF/disconnect.
static int ssh_readline(ssh_conn_t *c, char *buf, int maxlen)
{
    int pos = 0;
    while (pos < maxlen - 1) {
        char ch;
        int n = ssh_channel_read(c->channel, &ch, 1, 0);
        if (n <= 0) return -1;

        if (ch == '\r' || ch == '\n') {
            ssh_channel_write(c->channel, "\r\n", 2);
            break;
        }
        if (ch == '\x03') {  // Ctrl+C: discard line
            ssh_channel_write(c->channel, "^C\r\n", 4);
            buf[0] = '\0';
            return 0;
        }
        if (ch == '\x7f' || ch == '\x08') {  // DEL / BS
            if (pos > 0) {
                pos--;
                ssh_channel_write(c->channel, "\x08 \x08", 3);
            }
            continue;
        }
        if (ch >= 0x20 && ch < 0x7f) {
            buf[pos++] = ch;
            ssh_channel_write(c->channel, &ch, 1);  // echo
        }
    }
    buf[pos] = '\0';
    return pos;
}

// ---- Console I/O overrides for SSH ---- //
// The host installs these (via breezy_ssh_host_t.set_io_override) so that a
// child task's write(STDOUT_FILENO,...) / read(STDIN_FILENO,...) — i.e. from
// TUI ELF apps — go through the SSH channel instead of the local console.

static ssize_t ssh_console_write(int fd, const void *data, size_t size)
{
    if (!s_conn.channel || ssh_channel_is_eof(s_conn.channel)) {
        return (ssize_t)size;  // discard gracefully
    }
    // \n → \r\n translation (same as sshvfs_write)
    const char *p   = (const char *)data;
    const char *end = p + size;
    while (p < end) {
        const char *nl    = memchr(p, '\n', (size_t)(end - p));
        size_t      chunk = nl ? (size_t)(nl - p) : (size_t)(end - p);
        if (chunk > 0) {
            ssh_channel_write(s_conn.channel, p, (uint32_t)chunk);
        }
        if (nl) {
            ssh_channel_write(s_conn.channel, "\r\n", 2);
            p = nl + 1;
        } else {
            p = end;
        }
    }
    return (ssize_t)size;
}

static ssize_t ssh_console_read(int fd, void *data, size_t size)
{
    if (!s_conn.channel || ssh_channel_is_eof(s_conn.channel)) {
        return 0;
    }
    int nonblock = s_host.is_fd_nonblock ? s_host.is_fd_nonblock(fd) : 0;
    if (nonblock) {
        int n = ssh_channel_read_nonblocking(s_conn.channel, data, (uint32_t)size, 0);
        if (n == 0) {
            errno = EAGAIN;
            return -1;
        }
        return n;
    }
    // Blocking: poll with short timeout, retry while session is alive
    while (s_running && !ssh_channel_is_eof(s_conn.channel)) {
        int n = ssh_channel_read_timeout(s_conn.channel, data, (uint32_t)size, 0, 50);
        if (n > 0) return n;
        if (n < 0) return -1;
        // n == 0: timeout, retry
    }
    return 0;
}

// ---- Shell REPL ---- //

static void run_shell(ssh_conn_t *c)
{
    // Open the SSH VFS as a writable FILE so printf() from commands reaches
    // the SSH client.  We redirect only _stdout/_stderr for this task;
    // other tasks keep writing to the main breezy console.
    FILE *ssh_out = fopen(SSH_VFS_PATH, "w");
    if (!ssh_out) {
        ESP_LOGE(TAG, "fopen %s failed", SSH_VFS_PATH);
        return;
    }
    setvbuf(ssh_out, NULL, _IONBF, 0);

    FILE *saved_out = _REENT->_stdout;
    FILE *saved_err = _REENT->_stderr;
    _REENT->_stdout = ssh_out;
    _REENT->_stderr = ssh_out;

    // Route this task's write(1,...)/read(0,...) (e.g. from TUI ELF apps) to
    // the SSH channel, and report the negotiated terminal size. Both hooks are
    // optional; without them the line shell still works for printf output.
    if (s_host.set_io_override) {
        s_host.set_io_override(ssh_console_write, ssh_console_read);
    }
    if (s_host.set_term_size) {
        s_host.set_term_size(s_ssh_rows, s_ssh_cols);
    }

    const char *banner =
        "\r\n"
        "Welcome to BreezyBox SSH\r\n"
        "Type 'help' for commands. Type 'exit' to disconnect.\r\n"
        "\r\n";
    ssh_channel_write(c->channel, banner, strlen(banner));

    ESP_LOGI(TAG, "shell entry: internal SRAM free = %u bytes",
             (unsigned)heap_caps_get_free_size(MALLOC_CAP_INTERNAL | MALLOC_CAP_8BIT));

    char line[256];
    while (s_running && !ssh_channel_is_eof(c->channel)) {
        ssh_channel_write(c->channel, "breezy$ ", 8);

        int len = ssh_readline(c, line, sizeof(line));
        if (len < 0) break;          // disconnected
        if (!line[0]) continue;      // empty line

        if (strcmp(line, "exit") == 0 || strcmp(line, "quit") == 0) break;

        if (s_host.exec_line) {
            s_host.exec_line(line);
        } else {
            const char *msg = "breezy_ssh: no command handler installed\r\n";
            ssh_channel_write(c->channel, msg, strlen(msg));
        }
        fflush(ssh_out);
    }

    ssh_channel_write(c->channel, "\r\nGoodbye.\r\n", 12);

    ESP_LOGI(TAG, "shell exit: internal SRAM free = %u bytes; ssh task stack unused = %u of %u bytes",
             (unsigned)heap_caps_get_free_size(MALLOC_CAP_INTERNAL | MALLOC_CAP_8BIT),
             (unsigned)(uxTaskGetStackHighWaterMark(NULL) * sizeof(StackType_t)),
             (unsigned)SSH_TASK_STACK);

    if (s_host.clear_term_size)   s_host.clear_term_size();
    if (s_host.clear_io_override) s_host.clear_io_override();

    _REENT->_stdout = saved_out;
    _REENT->_stderr = saved_err;
    fclose(ssh_out);
}

// ---- Session handler ---- //

static void handle_session(ssh_conn_t *c)
{
    struct ssh_server_callbacks_struct srv_cb;
    memset(&srv_cb, 0, sizeof(srv_cb));
    srv_cb.userdata                                = c;
    srv_cb.auth_none_function                      = auth_none_cb;
    srv_cb.auth_password_function                  = auth_password_cb;
    srv_cb.channel_open_request_session_function   = channel_open_cb;
    ssh_callbacks_init(&srv_cb);
    ssh_set_server_callbacks(c->session, &srv_cb);
    ssh_set_auth_methods(c->session, SSH_AUTH_METHOD_PASSWORD);

    ssh_event ev = ssh_event_new();
    if (!ev || ssh_event_add_session(ev, c->session) != SSH_OK) {
        ESP_LOGE(TAG, "Failed to create SSH event");
        if (ev) ssh_event_free(ev);
        return;
    }

    // Poll until auth succeeds, shell is requested, auth fails, or server stops.
    // Each dopoll call waits up to 1 s; 30 iterations = ~30 s timeout.
    for (int i = 0; i < 30 && !c->shell_requested && !c->failed && s_running; i++) {
        if (ssh_event_dopoll(ev, 1000) == SSH_ERROR) {
            ESP_LOGW(TAG, "Poll error during auth");
            break;
        }
    }
    ssh_event_free(ev);

    if (!c->shell_requested) {
        ESP_LOGI(TAG, "Session ended before shell (auth failed or timeout)");
        return;
    }

    ESP_LOGI(TAG, "Shell session started");
    run_shell(c);
    ESP_LOGI(TAG, "Shell session ended");
}

// ---- Server task ---- //

static void server_task(void *arg)
{
    int port = (int)(intptr_t)arg;

    // Tell libssh NOT to use pthreads, bypassing mutex initialization failures
    ssh_threads_set_callbacks(ssh_threads_get_noop());

    if (ssh_init() != SSH_OK) {
        ESP_LOGE(TAG, "ssh_init() failed — entropy/DRBG init error. "
                      "Increase SSH_TASK_STACK or check mbedTLS config.");
        s_running = false;
        vTaskDelete(NULL);
        return;
    }
    register_sshvfs();

    s_sshbind = ssh_bind_new();
    char port_str[8];
    snprintf(port_str, sizeof(port_str), "%d", port);
    ssh_bind_options_set(s_sshbind, SSH_BIND_OPTIONS_BINDADDR,          "0.0.0.0");
    ssh_bind_options_set(s_sshbind, SSH_BIND_OPTIONS_BINDPORT_STR,      port_str);
    ssh_bind_options_set(s_sshbind, SSH_BIND_OPTIONS_LOG_VERBOSITY_STR, "1");
    ssh_bind_options_set(s_sshbind, SSH_BIND_OPTIONS_IMPORT_KEY_STR,
                         ssh_host_ed25519_key_start);

    if (ssh_bind_listen(s_sshbind) != SSH_OK) {
        ESP_LOGE(TAG, "ssh_bind_listen: %s", ssh_get_error(s_sshbind));
        ssh_bind_free(s_sshbind);
        s_sshbind = NULL;
        s_running = false;
        vTaskDelete(NULL);
        return;
    }

    ESP_LOGI(TAG, "Listening on port %d (user: %s)", port, SSH_USERNAME);
    printf("SSH server ready on port %d  (user: %s / pass: %s)\n",
           port, SSH_USERNAME, SSH_PASSWORD);

    while (s_running) {
        ssh_session session = ssh_new();
        if (!session) {
            vTaskDelay(pdMS_TO_TICKS(1000));
            continue;
        }

        // ssh_bind_accept blocks until a client connects or the bind is freed.
        if (ssh_bind_accept(s_sshbind, session) != SSH_OK) {
            ssh_free(session);
            if (!s_running) break;
            ESP_LOGW(TAG, "Accept error: %s", ssh_get_error(s_sshbind));
            vTaskDelay(pdMS_TO_TICKS(100));
            continue;
        }

        ESP_LOGI(TAG, "New connection");

        if (ssh_handle_key_exchange(session) != SSH_OK) {
            ESP_LOGW(TAG, "Key exchange failed: %s", ssh_get_error(session));
            ssh_disconnect(session);
            ssh_free(session);
            continue;
        }

        memset(&s_conn, 0, sizeof(s_conn));
        s_conn.session = session;

        handle_session(&s_conn);

        // Clean up channel and session
        if (s_conn.channel) {
            if (!ssh_channel_is_eof(s_conn.channel))
                ssh_channel_send_eof(s_conn.channel);
            ssh_channel_close(s_conn.channel);
            ssh_channel_free(s_conn.channel);
            s_conn.channel = NULL;
        }
        ssh_disconnect(s_conn.session);
        ssh_free(s_conn.session);
        s_conn.session = NULL;

        ESP_LOGI(TAG, "Connection closed");
    }

    ssh_bind_free(s_sshbind);
    s_sshbind = NULL;
    ssh_finalize();
    s_running      = false;
    s_server_task  = NULL;
    vTaskDelete(NULL);
}

// ---- Public API ---- //

esp_err_t ssh_server_start(int port)
{
    if (s_running) return ESP_ERR_INVALID_STATE;
    s_running = true;
    if (xTaskCreate(server_task, "ssh_srv", SSH_TASK_STACK,
                    (void *)(intptr_t)port,
                    SSH_TASK_PRIO, &s_server_task) != pdPASS) {
        s_running = false;
        return ESP_ERR_NO_MEM;
    }
    return ESP_OK;
}

void ssh_server_stop(void)
{
    if (!s_running) return;
    s_running = false;

    // Forcefully delete the server task (PoC limitation — no graceful drain).
    // This also interrupts any blocked ssh_bind_accept or ssh_channel_read.
    if (s_server_task) {
        vTaskDelete(s_server_task);
        s_server_task = NULL;
    }

    // Free libssh resources that the task no longer owns.
    if (s_conn.channel) {
        ssh_channel_free(s_conn.channel);
        s_conn.channel = NULL;
    }
    if (s_conn.session) {
        ssh_disconnect(s_conn.session);
        ssh_free(s_conn.session);
        s_conn.session = NULL;
    }
    if (s_sshbind) {
        ssh_bind_free(s_sshbind);
        s_sshbind = NULL;
    }
    ssh_finalize();
}

bool ssh_server_running(void)
{
    return s_running;
}
