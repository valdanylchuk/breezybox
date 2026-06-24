/*
 * my_console_io.c - Custom VFS console with vterm + Tanmatsu LCD integration.
 *
 * Redirects stdin/stdout to a virtual terminal rendered on the Tanmatsu MIPI
 * panel, while also mirroring I/O over USB-Serial-JTAG for debugging. Adapted
 * from the S3 breezydemo; the graphics-mode and BT paths have been dropped.
 */

#include "my_console_io.h"
#include "tanmatsu_lcd.h"
#include "vterm.h"
#include "esp_vfs.h"
#include "esp_log.h"
#include "driver/usb_serial_jtag.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <errno.h>
#include <sys/fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

static const char *TAG = "console";

#define CONSOLE_DEV_PATH "/dev/breezy"

/* O_NONBLOCK tracking per local fd (stdin, stdout + stdio dups). */
#define MAX_CONSOLE_FDS 4
static int s_fd_flags[MAX_CONSOLE_FDS] = {0};
static int s_next_local_fd = 0;

static console_output_mode_t s_output_mode = CONSOLE_OUT_BOTH;

/* USB connectivity state (auto-disables USB writes if cable absent). */
static int s_usb_connected = 1;
static int s_usb_fail_count = 0;
#define USB_FAIL_THRESHOLD 3

/* Push the active VT's cursor to the LCD and request a redraw. */
static void sync_cursor_and_redraw(void)
{
    int col, row, visible;
    vterm_get_cursor(vterm_get_active(), &col, &row, &visible);
    tanmatsu_lcd_set_cursor(visible ? col : -1, row);
    tanmatsu_lcd_mark_dirty();
}

/* Detect terminal probe/query sequences that should not echo to USB. */
static int is_terminal_probe(const char *data, size_t size)
{
    if (size < 4) return 0;
    for (size_t i = 0; i + 3 < size; i++) {
        if (data[i] == '\x1b' && data[i + 1] == '[') {
            if ((data[i + 2] == '5' || data[i + 2] == '6') && data[i + 3] == 'n') return 1;
            if (i + 5 <= size &&
                data[i + 2] == '9' && data[i + 3] == '9' && data[i + 4] == '9' && data[i + 5] == 'C')
                return 1;
        }
    }
    if (size == 4 && data[0] == '\x1b' && data[1] == '[' &&
        (data[2] == '5' || data[2] == '6') && data[3] == 'n')
        return 1;
    return 0;
}

static ssize_t my_console_write(int fd, const void *data, size_t size)
{
    const char *str = (const char *)data;

    if (s_output_mode == CONSOLE_OUT_BOTH || s_output_mode == CONSOLE_OUT_LCD) {
        int active = vterm_get_active();
        vterm_write(active, str, size);
        sync_cursor_and_redraw();
    }

    if ((s_output_mode == CONSOLE_OUT_BOTH || s_output_mode == CONSOLE_OUT_USB) && s_usb_connected) {
        if (!is_terminal_probe(str, size)) {
            int written = usb_serial_jtag_write_bytes(data, size, pdMS_TO_TICKS(1));
            if (written < (int)size) {
                if (++s_usb_fail_count >= USB_FAIL_THRESHOLD && s_output_mode == CONSOLE_OUT_BOTH) {
                    s_usb_connected = 0;  /* auto fall back to LCD-only */
                }
            } else {
                s_usb_fail_count = 0;
                s_usb_connected = 1;
            }
        }
    }
    return size;
}

static ssize_t my_console_read(int fd, void *data, size_t size)
{
    char *buf = (char *)data;
    size_t count = 0;
    int idx = (fd >= 0 && fd < MAX_CONSOLE_FDS) ? fd : 0;
    int nonblock = (s_fd_flags[idx] & O_NONBLOCK);

    while (count < size) {
        /* Drain any USB bytes into the vterm input queue. */
        char c;
        while (usb_serial_jtag_read_bytes(&c, 1, 0) > 0) {
            if (c == '\r') c = '\n';
            vterm_input_feed(c);
        }

        int active = vterm_get_active();
        int timeout = (count == 0) ? (nonblock ? 0 : 50) : 0;
        int ch = vterm_getchar(active, timeout);

        if (ch >= 0) {
            if (ch == '\r') ch = '\n';
            buf[count++] = (char)ch;
            if (ch == '\n') break;
        } else {
            if (count > 0) break;
            if (nonblock) { errno = EAGAIN; return -1; }
            vTaskDelay(pdMS_TO_TICKS(5));
        }
    }
    return count;
}

static int my_console_open(const char *path, int flags, int mode)
{
    int fd = s_next_local_fd;
    s_next_local_fd = (s_next_local_fd + 1) % MAX_CONSOLE_FDS;
    if (fd < MAX_CONSOLE_FDS) s_fd_flags[fd] = flags & O_NONBLOCK;
    return fd;
}

static int my_console_close(int fd) { return 0; }

static int my_console_fstat(int fd, struct stat *st)
{
    memset(st, 0, sizeof(*st));
    st->st_mode = S_IFCHR;  /* character device -> isatty() true */
    return 0;
}

static int my_console_fsync(int fd) { return 0; }

#if CONFIG_VFS_SUPPORT_TERMIOS
static int my_console_tcsetattr(int fd, int optional_actions, const struct termios *p) { return 0; }
static int my_console_tcgetattr(int fd, struct termios *p)
{
    memset(p, 0, sizeof(*p));
    p->c_cflag = CS8;
    p->c_cc[VMIN] = 1;
    p->c_cc[VTIME] = 0;
    return 0;
}
#endif

static int my_console_fcntl(int fd, int cmd, int arg)
{
    int idx = (fd >= 0 && fd < MAX_CONSOLE_FDS) ? fd : 0;
    switch (cmd) {
    case F_GETFL: return s_fd_flags[idx];
    case F_SETFL: s_fd_flags[idx] = arg & O_NONBLOCK; return 0;
    default: return 0;
    }
}

static void on_vt_switch(int new_vt)
{
    char msg[32];
    int n = snprintf(msg, sizeof(msg), "\r\n[Switched to VT%d]\r\n", new_vt);
    if (s_usb_connected) usb_serial_jtag_write_bytes(msg, n, pdMS_TO_TICKS(10));
    sync_cursor_and_redraw();
}

/* ESP_LOG goes straight to USB so logs never disturb the on-screen terminal. */
static int usb_log_vprintf(const char *fmt, va_list args)
{
    char buf[256];
    int len = vsnprintf(buf, sizeof(buf), fmt, args);
    if (len > 0) usb_serial_jtag_write_bytes(buf, len, pdMS_TO_TICKS(10));
    return len;
}

static void probe_usb_connection(void)
{
    char probe = '\0';
    int written = usb_serial_jtag_write_bytes(&probe, 1, pdMS_TO_TICKS(5));
    if (written <= 0) { s_usb_connected = 0; s_usb_fail_count = USB_FAIL_THRESHOLD; }
    else { s_usb_connected = 1; s_usb_fail_count = 0; }
}

esp_err_t my_console_init(void)
{
    /* vterm first (allocates the cell buffers). */
    esp_err_t ret = vterm_init();
    if (ret != ESP_OK) { ESP_LOGE(TAG, "vterm_init failed"); return ret; }

    /* Bring up the LCD renderer and point it at vterm's live buffer. */
    ret = tanmatsu_lcd_init();
    if (ret != ESP_OK) { ESP_LOGE(TAG, "tanmatsu_lcd_init failed"); return ret; }
    tanmatsu_lcd_set_buffer((const lcd_cell_t *)vterm_get_direct_buffer(),
                            VTERM_COLS, VTERM_ROWS);
    sync_cursor_and_redraw();

    vterm_set_switch_callback(on_vt_switch);

    esp_vfs_t vfs = {
        .flags = ESP_VFS_FLAG_DEFAULT,
        .write = my_console_write,
        .read = my_console_read,
        .open = my_console_open,
        .close = my_console_close,
        .fstat = my_console_fstat,
        .fcntl = my_console_fcntl,
        .fsync = my_console_fsync,
#if CONFIG_VFS_SUPPORT_TERMIOS
        .tcsetattr = my_console_tcsetattr,
        .tcgetattr = my_console_tcgetattr,
#endif
    };

    ret = esp_vfs_register(CONSOLE_DEV_PATH, &vfs, NULL);
    if (ret != ESP_OK) return ret;

    /* Free fds 0/1 so our VFS opens claim stdin/stdout. */
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    int fd_in = open(CONSOLE_DEV_PATH, O_RDONLY);
    int fd_out = open(CONSOLE_DEV_PATH, O_WRONLY);
    if (fd_in != STDIN_FILENO || fd_out != STDOUT_FILENO) {
        if (fd_in >= 0) close(fd_in);
        if (fd_out >= 0) close(fd_out);
    }

    if (!freopen(CONSOLE_DEV_PATH, "r", stdin)) return ESP_FAIL;
    if (!freopen(CONSOLE_DEV_PATH, "w", stdout)) return ESP_FAIL;
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);

    esp_log_set_vprintf(usb_log_vprintf);
    probe_usb_connection();
    return ESP_OK;
}

void my_console_set_output_mode(console_output_mode_t mode) { s_output_mode = mode; }
console_output_mode_t my_console_get_output_mode(void) { return s_output_mode; }
int my_console_usb_connected(void) { return s_usb_connected; }
void my_console_usb_reconnect(void) { s_usb_connected = 1; s_usb_fail_count = 0; }
