/*
 * net_bringup.h - Phase 2: bring up the C6 radio link (esp-hosted).
 */
#pragma once

#include "esp_err.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Bring the WiFi radio (on the C6) into application mode and initialize the
 * esp_wifi_remote stack over esp-hosted, mirroring the native launcher. The C6
 * firmware is not modified. After this returns ESP_OK, BreezyBox's standard
 * networking commands (wifi / httpd / eget) operate over the remote radio.
 *
 * Not called automatically in the MVP -- invoke via the `netup` shell command.
 */
esp_err_t breezy_net_up(void);

#ifdef __cplusplus
}
#endif
