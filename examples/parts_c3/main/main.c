#include <stdio.h>
#include "driver/usb_serial_jtag.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "nvs_flash.h"
#include "esp_log.h"
#include "vterm.h"
#include "bt_keyboard.h"

static const char *TAG = "main";

// Callback to inject BT keyboard input into vterm
static void bt_char_callback(char c)
{
    vterm_input_feed(c);
}

void app_main(void)
{
    // Initialize USB-JTAG driver for passthrough (optional - remove if LCD-only)
    usb_serial_jtag_driver_config_t usb_config = {
        .tx_buffer_size = 256,
        .rx_buffer_size = 256,
    };
    usb_serial_jtag_driver_install(&usb_config);

    // Initialize NVS (required for BT bond storage)
    esp_err_t err = nvs_flash_init();
    if (err == ESP_ERR_NVS_NO_FREE_PAGES || err == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        nvs_flash_erase();
        nvs_flash_init();
    }

    // Initialize vterm and redirect stdio
    vterm_init();
    vterm_vfs_init(true);  // true for USB-JTAG passthrough

    // Initialize BT keyboard
    bt_keyboard_set_char_callback(bt_char_callback);
    if (bt_keyboard_init() == ESP_OK) {
        ESP_LOGI(TAG, "BT keyboard initialized");
        bt_keyboard_scan();  // Start scanning for keyboards
        ESP_LOGI(TAG, "Scanning for BT keyboards...");
    } else {
        ESP_LOGW(TAG, "BT init failed, USB-only mode");
    }

    // Now printf/getchar go through vterm
    printf("Hello from vterm!\n");
    printf("\033[31mRed text\033[0m\n");
    printf("Type something (characters will be echoed):\n");

    // Simple echo loop
    while (1) {
        int c = getchar();
        if (c != EOF) {
            putchar(c);
            fflush(stdout);
        }
    }
}
