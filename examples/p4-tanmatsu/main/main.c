/*
 * BreezyBox demo for the Tanmatsu cyberdeck (ESP32-P4).
 *
 * Text-mode MVP: BreezyBox shell on the built-in 800x480 display + keyboard,
 * with a parallel USB-Serial-JTAG console. WiFi (via the C6 radio) is wired but
 * brought up on demand with `netup` (see net_bringup.c).
 *
 * Hardware brought up through badge-bsp; ported from the S3 breezydemo.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/usb_serial_jtag.h"
#include "driver/usb_serial_jtag_vfs.h"
#include "esp_log.h"
#include "esp_console.h"
#include "nvs_flash.h"

#include "bsp/device.h"
#include "bsp/display.h"

#include "breezybox.h"
#include "vterm.h"
#include "my_console_io.h"
#include "tanmatsu_keyboard.h"
#include "net_bringup.h"

static const char *TAG = "main";

/* ---- Custom commands ---- */

/* Switch / query virtual terminals. */
static int cmd_vt(int argc, char **argv)
{
    if (argc < 2) {
        printf("Active: VT%d (of %d)\n", vterm_get_active(), VTERM_COUNT);
        return 0;
    }
    int n = atoi(argv[1]);
    if (n >= 0 && n < VTERM_COUNT) {
        vterm_switch(n);
        printf("Switched to VT%d\n", n);
    } else {
        printf("VT must be 0..%d\n", VTERM_COUNT - 1);
    }
    return 0;
}

/* Echo raw key codes (Ctrl-C to exit) -- handy for checking the keymap. */
static int cmd_keytest(int argc, char **argv)
{
    printf("Press keys (Ctrl+C to exit):\n");
    while (1) {
        int c = getchar();
        if (c == 3) break;            /* Ctrl-C */
        if (c == EOF) { vTaskDelay(pdMS_TO_TICKS(10)); continue; }
        if (c >= 32 && c < 127) printf("0x%02X '%c'\n", c, c);
        else                    printf("0x%02X\n", c);
    }
    return 0;
}

/* ANSI color sanity check. */
static int cmd_colortest(int argc, char **argv)
{
    printf("\033[31mRed\033[0m \033[32mGreen\033[0m \033[33mYellow\033[0m "
           "\033[34mBlue\033[0m \033[1;35mBright Magenta\033[0m\n");
    printf("\033[41;37mWhite on Red\033[0m\n");
    return 0;
}

/* Route console output: lcd | usb | both | usbreset. */
static int cmd_setcon(int argc, char **argv)
{
    if (argc < 2) {
        console_output_mode_t m = my_console_get_output_mode();
        const char *s = (m == CONSOLE_OUT_LCD) ? "lcd" : (m == CONSOLE_OUT_USB) ? "usb" : "both";
        printf("Console output: %s\n", s);
        printf("USB: %s\n", my_console_usb_connected() ? "connected" : "disconnected (auto-skipped)");
        printf("Usage: setcon <lcd|usb|both|usbreset>\n");
        return 0;
    }
    const char *a = argv[1];
    if (strcmp(a, "usbreset") == 0) { my_console_usb_reconnect(); printf("USB detection reset\n"); return 0; }
    if (strcmp(a, "lcd") == 0)       my_console_set_output_mode(CONSOLE_OUT_LCD);
    else if (strcmp(a, "usb") == 0)  my_console_set_output_mode(CONSOLE_OUT_USB);
    else if (strcmp(a, "both") == 0) my_console_set_output_mode(CONSOLE_OUT_BOTH);
    else { printf("Invalid mode: %s\n", a); return 1; }
    printf("Console output: %s\n", a);
    return 0;
}

/* Phase 2: bring up the C6 WiFi radio (then use breezy's `wifi` command). */
static int cmd_netup(int argc, char **argv)
{
    printf("Bringing up WiFi radio (C6 over esp-hosted)...\n");
    esp_err_t err = breezy_net_up();
    if (err == ESP_OK) printf("Radio up. Now: wifi <ssid> <password>\n");
    else               printf("Radio bring-up failed: %s\n", esp_err_to_name(err));
    return err == ESP_OK ? 0 : 1;
}

extern int cmd_testgfx(int argc, char **argv);  /* cmd_testgfx.c */

static void register_commands(void)
{
    static const esp_console_cmd_t cmds[] = {
        { .command = "vt",        .help = "Switch/show virtual terminal", .hint = "[n]",                     .func = &cmd_vt },
        { .command = "keytest",   .help = "Echo raw key codes",           .hint = NULL,                      .func = &cmd_keytest },
        { .command = "colortest", .help = "ANSI color test",              .hint = NULL,                      .func = &cmd_colortest },
        { .command = "setcon",    .help = "Set console output",           .hint = "<lcd|usb|both|usbreset>", .func = &cmd_setcon },
        { .command = "netup",     .help = "Bring up the C6 WiFi radio",   .hint = NULL,                      .func = &cmd_netup },
        { .command = "testgfx",   .help = "VGA 320x200 graphics demo",    .hint = "[-t seconds] [-v]",       .func = &cmd_testgfx },
    };
    for (size_t i = 0; i < sizeof(cmds) / sizeof(cmds[0]); i++) {
        esp_console_cmd_register(&cmds[i]);
    }
}

void app_main(void)
{
    /* USB-Serial-JTAG: parallel console + log output. */
    usb_serial_jtag_driver_config_t usb_config = {
        .tx_buffer_size = 256,
        .rx_buffer_size = 256,
    };
    ESP_ERROR_CHECK(usb_serial_jtag_driver_install(&usb_config));
    usb_serial_jtag_vfs_use_driver();

    printf("\n--- BreezyBox / Tanmatsu (ESP32-P4) ---\n");

    /* Bring up Tanmatsu hardware: display, keyboard, power, C6 link. */
    const bsp_configuration_t bsp_configuration = {
        .display = {
            /* RGB565 + double buffering: the P4 backend renders graphics frames
             * straight into the DPI scanout buffers (PPA scale/rotate) and flips,
             * so we want two 16bpp framebuffers rather than one 24bpp copy target. */
            .requested_color_format = BSP_DISPLAY_COLOR_FORMAT_16_565RGB,
            .num_fbs                = 2,
        },
    };
    ESP_ERROR_CHECK(bsp_device_initialize(&bsp_configuration));
    bsp_display_set_backlight_brightness(100);

    esp_err_t err = nvs_flash_init();
    if (err == ESP_ERR_NVS_NO_FREE_PAGES || err == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ESP_ERROR_CHECK(nvs_flash_init());
    }

    /* vterm + LCD renderer + stdio redirection. */
    if (my_console_init() != ESP_OK) {
        ESP_LOGE(TAG, "Console init failed!");
        return;
    }

    /* Built-in keyboard -> vterm. */
    if (tanmatsu_keyboard_start() != ESP_OK) {
        ESP_LOGW(TAG, "Keyboard task failed to start (USB console still works)");
    }

    /* Start the BreezyBox shell on our stdio (LCD + USB). */
    ESP_ERROR_CHECK(breezybox_start_stdio(8192, 5));
    register_commands();

    /* Keep P4-demo-specific symbols in the firmware for the ELF loader. */
    extern void breezy_p4_export_symbols(void);
    breezy_p4_export_symbols();

    /* Display renders via the LCD task; keep app_main alive. */
    while (1) {
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}
