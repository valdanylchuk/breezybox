/*
 * Headless breezy_ssh demo.
 *
 * A USB-console BreezyBox shell that also accepts SSH logins over WiFi.
 * No display, no Bluetooth. At the local USB prompt:
 *     wifi connect <ssid> <password>
 *     sshd start
 * then `ssh breezy@<ip>` (password: breezy).
 */

#include <stdio.h>
#include "esp_log.h"
#include "nvs_flash.h"
#include "esp_console.h"

#include "breezybox.h"
#include "breezy_exec.h"   // breezybox_exec()
#include "ssh_server.h"    // breezy_ssh
#include "my_console_io.h"

static const char *TAG = "ssh_demo";

// Provided by breezy_ssh (cmd_sshd.c); no public header declares it.
extern int cmd_sshd(int argc, char **argv);

// ELF apps (vi) query terminal size via vterm_get_size(); breezy_ssh reports
// the SSH-negotiated size through these. vterm is linked transitively via
// breezybox. Forward-declared so this demo needs no direct vterm include --
// swap these two for your own size store if you ever drop vterm.
extern void vterm_set_size_override(int rows, int cols);
extern void vterm_clear_size_override(void);

// ---- breezy_ssh host adapters: bridge the component to this firmware ---- //

static int  host_exec(const char *line)            { return breezybox_exec(line); }
static void host_clear_io(void)                    { my_console_clear_io_override(); }
static int  host_is_nonblock(int fd)               { return my_console_fd_is_nonblock(fd); }
static void host_set_size(int rows, int cols)      { vterm_set_size_override(rows, cols); }
static void host_clear_size(void)                  { vterm_clear_size_override(); }

static void host_set_io(ssh_io_write_fn w, ssh_io_read_fn r)
{
    const console_io_override_t ovr = { .write = w, .read = r };
    my_console_set_io_override(&ovr);
}

void app_main(void)
{
    esp_err_t err = nvs_flash_init();
    if (err == ESP_ERR_NVS_NO_FREE_PAGES || err == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ESP_ERROR_CHECK(nvs_flash_init());
    }

    // USB console with per-task I/O override (lets vi & co. render over SSH).
    ESP_ERROR_CHECK(my_console_init());

    // Tell breezy_ssh how to talk to this host.
    const breezy_ssh_host_t host = {
        .exec_line         = host_exec,
        .set_io_override   = host_set_io,
        .clear_io_override = host_clear_io,
        .is_fd_nonblock    = host_is_nonblock,
        .set_term_size     = host_set_size,
        .clear_term_size   = host_clear_size,
    };
    ssh_server_set_host(&host);

    // Local shell on USB. This also inits the filesystem, esp_console, and
    // registers the built-in commands (including `wifi`).
    breezybox_start_stdio(12288, 5);

    // Add the sshd command (esp_console is up after breezybox_start_stdio).
    const esp_console_cmd_t sshd_cmd = {
        .command = "sshd",
        .help    = "SSH server",
        .hint    = "[start [port] | stop | status]",
        .func    = &cmd_sshd,
    };
    esp_console_cmd_register(&sshd_cmd);

    ESP_LOGI(TAG, "Ready. Try: wifi connect <ssid> <pass>  then  sshd start");
}
