/*
 * tanmatsu_keyboard.h - Feed the Tanmatsu built-in keyboard into vterm.
 */
#pragma once

#include "esp_err.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Start the task that drains the badge-bsp input queue into vterm input.
 * Call after bsp_device_initialize() and vterm_init(). */
esp_err_t tanmatsu_keyboard_start(void);

#ifdef __cplusplus
}
#endif
