/*
 * BreezyBox Example - Basic Shell
 * 
 * This example shows how to start a BreezyBox shell on an ESP32.
 * It uses USB Serial JTAG for I/O (common on ESP32-S3 dev boards).
 */

#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "breezybox.h"

static const char *TAG = "example";

void app_main(void)
{
    ESP_LOGI(TAG, "Starting BreezyBox example");
    
    // Option 1: Use ESP-IDF's built-in USB Serial JTAG REPL
    // This is the simplest option - no custom console setup needed
    ESP_ERROR_CHECK(breezybox_start_usb(8192, 5));
    
    // Option 2: Use stdio with custom console (e.g., for LCD display)
    // Requires: my_console_init() to redirect stdin/stdout
    // ESP_ERROR_CHECK(breezybox_start_stdio(8192, 5));
    
    ESP_LOGI(TAG, "Shell started");
    
    // Main task can do other work or just idle
    while (1) {
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}