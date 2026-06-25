/*
 * my_console_io.h - VFS console bridging stdio <-> vterm + Tanmatsu LCD,
 * with an optional parallel USB-Serial-JTAG console.
 *
 * Adapted from the S3 breezydemo: graphics-mode and BT-keyboard paths removed
 * (the P4 MVP is text-only and uses the built-in keyboard via badge-bsp).
 */
#pragma once

#include "esp_err.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    CONSOLE_OUT_LCD,   /* LCD (vterm) only */
    CONSOLE_OUT_USB,   /* USB-Serial-JTAG only */
    CONSOLE_OUT_BOTH,  /* both (default) */
    CONSOLE_OUT_GFX,   /* graphics mode: skip vterm/LCD, mirror text to USB */
} console_output_mode_t;

/*
 * Initialize vterm + the Tanmatsu LCD backend, register the console VFS and
 * redirect stdin/stdout through it. Call after bsp_device_initialize().
 */
esp_err_t my_console_init(void);

void                  my_console_set_output_mode(console_output_mode_t mode);
console_output_mode_t my_console_get_output_mode(void);
int                   my_console_usb_connected(void);
void                  my_console_usb_reconnect(void);

/*
 * Push the live vterm text palette to the LCD and redraw. ELF apps call this
 * (by symbol name) after vterm_set_palette() to make a palette change visible
 * without rewriting cells -- e.g. the `plasma` demo. Exported to the loader.
 */
void                  my_display_refresh_palette(void);

#ifdef __cplusplus
}
#endif
