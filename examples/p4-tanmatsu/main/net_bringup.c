/*
 * net_bringup.c - Phase 2 WiFi radio bring-up for the Tanmatsu (ESP32-P4).
 *
 * The WiFi MAC/PHY lives on the ESP32-C6 co-processor. The P4 reaches it over
 * esp-hosted (SDIO) using esp_wifi_remote, exactly like the native launcher:
 *   1. Put the radio into APPLICATION mode via badge-bsp power control.
 *   2. Initialize the remote WiFi stack (tanmatsu-wifi / wifi-manager).
 * We do NOT touch the C6 firmware; we just speak to the radio it already runs.
 *
 * The launcher also calls radio_system_protocol_init() to register a control
 * channel for querying radio info; that is optional for plain connectivity and
 * is omitted here to keep the MVP free of launcher-internal headers.
 *
 * This file is compiled in so the networking commands link, but breezy_net_up()
 * is only called on demand (the `netup` command). NOTE: validate on-device --
 * the exact wifi_remote API/version may need a tweak to match your IDF.
 */

#include "net_bringup.h"
#include "esp_log.h"

static const char *TAG = "net";

#if defined(CONFIG_IDF_TARGET_ESP32P4)

#include "bsp/power.h"
#include "wifi_remote.h"   /* wifi_remote_initialize() -- nicolaielectronics/tanmatsu-wifi */

esp_err_t breezy_net_up(void)
{
    bsp_radio_state_t state = BSP_POWER_RADIO_STATE_OFF;
    bsp_power_get_radio_state(&state);
    if (state != BSP_POWER_RADIO_STATE_OFF) {
        bsp_power_set_radio_state(BSP_POWER_RADIO_STATE_OFF);
    }

    esp_err_t err = bsp_power_set_radio_state(BSP_POWER_RADIO_STATE_APPLICATION);
    if (err != ESP_OK) {
        ESP_LOGE(TAG, "Failed to set radio to APPLICATION: %s", esp_err_to_name(err));
        return err;
    }

    err = wifi_remote_initialize();
    if (err != ESP_OK) {
        ESP_LOGE(TAG, "wifi_remote_initialize failed: %s", esp_err_to_name(err));
        return err;
    }

    ESP_LOGI(TAG, "Radio up. Use 'wifi <ssid> <password>' to connect.");
    return ESP_OK;
}

#else  /* non-P4 target */

esp_err_t breezy_net_up(void)
{
    ESP_LOGE(TAG, "Radio bring-up only supported on ESP32-P4");
    return ESP_ERR_NOT_SUPPORTED;
}

#endif
