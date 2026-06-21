// ============ Stdio VFS Bridge ============

#include "vterm.h"
#include "esp_vfs.h"
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

// Optional USB-JTAG passthrough support
#ifdef CONFIG_USJ_ENABLE_USB_SERIAL_JTAG
#include "driver/usb_serial_jtag.h"
#endif

#define VTERM_VFS_PATH "/dev/vterm"

extern int s_active_vt;

static bool s_usb_jtag_enabled = false;

static ssize_t vfs_vterm_write(int fd, const void *data, size_t size)
{
    (void)fd;

    // Write to vterm buffer
    vterm_write(s_active_vt, (const char *)data, size);

    // Optionally write through to USB-JTAG (if enabled by user)
#ifdef CONFIG_USJ_ENABLE_USB_SERIAL_JTAG
    if (s_usb_jtag_enabled) {
        usb_serial_jtag_write_bytes(data, size, pdMS_TO_TICKS(1));
    }
#endif

    return size;
}

static ssize_t vfs_vterm_read(int fd, void *data, size_t size)
{
    (void)fd;
    char *buf = (char *)data;
    size_t count = 0;

    while (count < size) {
        // Optionally drain USB-JTAG input into vterm queue (if enabled)
#ifdef CONFIG_USJ_ENABLE_USB_SERIAL_JTAG
        if (s_usb_jtag_enabled) {
            char c;
            while (usb_serial_jtag_read_bytes(&c, 1, 0) > 0) {
                if (c == '\r') c = '\n';
                vterm_input_feed(c);
            }
        }
#endif

        // First char: wait with timeout. Subsequent chars: no wait
        int ch = vterm_getchar(s_active_vt, count == 0 ? 50 : 0);
        if (ch < 0) {
            if (count > 0) break;
            vTaskDelay(pdMS_TO_TICKS(5));
            continue;
        }
        buf[count++] = (char)ch;
        if (ch == '\n') break;
    }
    return count;
}

static int vfs_vterm_open(const char *path, int flags, int mode)
{
    (void)path; (void)flags; (void)mode;
    return 0;
}

static int vfs_vterm_close(int fd) { (void)fd; return 0; }

static int vfs_vterm_fstat(int fd, struct stat *st)
{
    (void)fd;
    memset(st, 0, sizeof(*st));
    st->st_mode = S_IFCHR;
    return 0;
}

esp_err_t vterm_vfs_init(bool enable_usb_jtag_passthrough)
{
#ifdef CONFIG_USJ_ENABLE_USB_SERIAL_JTAG
    s_usb_jtag_enabled = enable_usb_jtag_passthrough;
#else
    (void)enable_usb_jtag_passthrough;  // Suppress warning if USB-JTAG not available
#endif

    esp_vfs_t vfs = {
        .flags = ESP_VFS_FLAG_DEFAULT,
        .write = vfs_vterm_write,
        .read  = vfs_vterm_read,
        .open  = vfs_vterm_open,
        .close = vfs_vterm_close,
        .fstat = vfs_vterm_fstat,
    };

    esp_err_t ret = esp_vfs_register(VTERM_VFS_PATH, &vfs, NULL);
    if (ret != ESP_OK) return ret;

    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    open(VTERM_VFS_PATH, O_RDONLY);   // gets fd 0
    open(VTERM_VFS_PATH, O_WRONLY);   // gets fd 1

    if (!freopen(VTERM_VFS_PATH, "r", stdin)) return ESP_FAIL;
    if (!freopen(VTERM_VFS_PATH, "w", stdout)) return ESP_FAIL;
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);

    return ESP_OK;
}