/*
 * my_console_io.c - Minimal USB-Serial-JTAG console for the breezy_ssh demo.
 *
 * A thin VFS over USB-Serial-JTAG that adds one capability the stock console
 * lacks: per-task raw-stdio override, used by breezy_ssh to route an SSH
 * session's write(1)/read(0) (and that of ELF apps like vi) to the SSH
 * channel. No display, no Bluetooth, no vterm.
 */

#include "my_console_io.h"

#include "esp_vfs.h"
#include "esp_log.h"
#include "driver/usb_serial_jtag.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

#define CONSOLE_DEV_PATH   "/dev/console"
#define MAX_CONSOLE_FDS    4

static int s_fd_flags[MAX_CONSOLE_FDS] = {0};
static int s_next_local_fd = 0;

// Per-task override (installed by breezy_ssh during a session).
static TaskHandle_t          s_override_task = NULL;
static console_io_override_t s_io_override   = {0};

// ---- VFS ops ---- //

static ssize_t my_console_write(int fd, const void *data, size_t size)
{
    if (s_override_task == xTaskGetCurrentTaskHandle() && s_io_override.write) {
        return s_io_override.write(fd, data, size);
    }
    usb_serial_jtag_write_bytes(data, size, pdMS_TO_TICKS(20));
    return (ssize_t)size;
}

static ssize_t my_console_read(int fd, void *data, size_t size)
{
    if (s_override_task == xTaskGetCurrentTaskHandle() && s_io_override.read) {
        return s_io_override.read(fd, data, size);
    }

    char  *buf   = (char *)data;
    size_t count = 0;
    int    idx   = (fd >= 0 && fd < MAX_CONSOLE_FDS) ? fd : 0;
    int    nonblock = (s_fd_flags[idx] & O_NONBLOCK);

    while (count < size) {
        char c;
        // First byte: block briefly (or not, if non-blocking). Once we have a
        // byte, drain whatever else is buffered without waiting.
        TickType_t to = (count == 0) ? (nonblock ? 0 : pdMS_TO_TICKS(50)) : 0;
        int n = usb_serial_jtag_read_bytes(&c, 1, to);
        if (n > 0) {
            if (c == '\r') c = '\n';   // terminals send CR; linenoise wants LF
            buf[count++] = c;
            if (c == '\n') break;
        } else {
            if (count > 0) break;
            if (nonblock) { errno = EAGAIN; return -1; }
            // blocking: usb_serial_jtag_read_bytes already waited; loop again
        }
    }
    return (ssize_t)count;
}

static int my_console_open(const char *path, int flags, int mode)
{
    int fd = s_next_local_fd;
    s_next_local_fd = (s_next_local_fd + 1) % MAX_CONSOLE_FDS;
    s_fd_flags[fd] = flags & O_NONBLOCK;
    return fd;
}

static int my_console_close(int fd) { return 0; }

static int my_console_fstat(int fd, struct stat *st)
{
    memset(st, 0, sizeof(*st));
    st->st_mode = S_IFCHR;   // character device -> isatty() true
    return 0;
}

static int my_console_fsync(int fd) { return 0; }

#if CONFIG_VFS_SUPPORT_TERMIOS
static int my_console_tcsetattr(int fd, int act, const struct termios *p) { return 0; }
static int my_console_tcgetattr(int fd, struct termios *p)
{
    memset(p, 0, sizeof(*p));
    p->c_cflag   = CS8;
    p->c_cc[VMIN]  = 1;
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
    default:      return 0;
    }
}

// ESP_LOG always goes straight to USB, bypassing stdout redirection and any
// per-task override, so logs stay visible locally even during an SSH session.
static int usb_log_vprintf(const char *fmt, va_list args)
{
    char buf[256];
    int len = vsnprintf(buf, sizeof(buf), fmt, args);
    if (len > 0) {
        if (len > (int)sizeof(buf)) len = sizeof(buf);
        usb_serial_jtag_write_bytes(buf, len, pdMS_TO_TICKS(20));
    }
    return len;
}

// ---- Public API ---- //

esp_err_t my_console_init(void)
{
    usb_serial_jtag_driver_config_t usb_config = {
        .tx_buffer_size = 1024,
        .rx_buffer_size = 1024,
    };
    esp_err_t ret = usb_serial_jtag_driver_install(&usb_config);
    if (ret != ESP_OK) return ret;

    esp_vfs_t vfs = {
        .flags = ESP_VFS_FLAG_DEFAULT,
        .write = my_console_write,
        .read  = my_console_read,
        .open  = my_console_open,
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

    // Free fds 0/1 so our opens land on them, then point the FILE* streams at
    // our VFS.
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    int fd_in  = open(CONSOLE_DEV_PATH, O_RDONLY);
    int fd_out = open(CONSOLE_DEV_PATH, O_WRONLY);
    if (fd_in != STDIN_FILENO || fd_out != STDOUT_FILENO) {
        if (fd_in  >= 0) close(fd_in);
        if (fd_out >= 0) close(fd_out);
    }
    if (!freopen(CONSOLE_DEV_PATH, "r", stdin))  return ESP_FAIL;
    if (!freopen(CONSOLE_DEV_PATH, "w", stdout)) return ESP_FAIL;
    setvbuf(stdin,  NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);

    esp_log_set_vprintf(usb_log_vprintf);
    return ESP_OK;
}

void my_console_set_io_override(const console_io_override_t *ovr)
{
    s_io_override   = *ovr;
    s_override_task = xTaskGetCurrentTaskHandle();
}

void my_console_clear_io_override(void)
{
    s_override_task = NULL;
    memset(&s_io_override, 0, sizeof(s_io_override));
}

int my_console_fd_is_nonblock(int fd)
{
    int idx = (fd >= 0 && fd < MAX_CONSOLE_FDS) ? fd : 0;
    return (s_fd_flags[idx] & O_NONBLOCK) ? 1 : 0;
}
