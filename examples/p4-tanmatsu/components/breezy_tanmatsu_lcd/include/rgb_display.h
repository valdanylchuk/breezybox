/*
 * rgb_display.h - Graphics-mode display API for the Tanmatsu (ESP32-P4).
 *
 * This is the P4 counterpart of the S3 breezy_rgb_lcd "rgb_display" API. ELF
 * apps (gfx150, plasma, testgfx, ccleste, ...) link against these symbol names,
 * so the names and the DOS-style mode constants are kept ABI-compatible with
 * the S3 component. The implementation lives in tanmatsu_lcd.c and shares the
 * panel framebuffer / rotation / blit path with the text renderer.
 *
 * Text-mode rendering still uses the tanmatsu_lcd_* API (see tanmatsu_lcd.h);
 * this header only adds the graphics-mode surface that loadable apps expect.
 */
#pragma once

#include <stdint.h>
#include "tanmatsu_lcd.h"   /* lcd_cell_t, LCD_ATTR_* */

#ifdef __cplusplus
extern "C" {
#endif

/* Screen modes (DOS-compatible constants, matching the S3 component). */
typedef enum {
    SM_TEXT   = 3,      /* Text mode (vterm cell grid) */
    SM_VGA13H = 0x13,   /* VGA mode 13h: 320x200 @ 8bpp (256 colors) */
    SM_150P   = 0x80,   /* Custom mode:  256x150 @ 8bpp (256 colors) */
} screen_mode_t;

/*
 * Callbacks bridging the display to an external terminal/console system.
 * All pointers may be NULL; the display still works standalone (you just lose
 * text-mode palette sync and the text<->graphics console hand-off).
 */
typedef struct {
    /* 16-color RGB565 text palette; NULL -> CGA defaults. */
    const uint16_t *(*get_text_palette)(void);
    /* Enter graphics mode: save text state, redirect console. 0 = ok. */
    int (*enter_graphics)(void);
    /* Exit graphics mode: restore text state and console routing. 0 = ok. */
    int (*exit_graphics)(void);
    /* After exiting graphics, the text cell buffer to re-link (may be NULL). */
    lcd_cell_t *(*get_text_buffer)(void);
    /* After exiting graphics, flush stale input (optional). */
    void (*flush_input)(void);
} rgb_display_callbacks_t;

/* Register the console bridge callbacks (see my_console_io.c). */
void rgb_display_set_callbacks(const rgb_display_callbacks_t *cb);

/* --- Screen mode --- */
screen_mode_t rgb_display_get_mode(void);
int           rgb_display_set_mode(screen_mode_t mode);  /* 0 on success */

/* --- Graphics framebuffer (8bpp indexed; NULL/0 in text mode) --- */
uint8_t *rgb_display_get_framebuffer(void);
int      rgb_display_get_fb_width(void);
int      rgb_display_get_fb_height(void);

/* --- VGA 256-color palette (RGB565); only used in graphics modes --- */
void     rgb_display_set_vga_palette(const uint16_t palette[256]);
void     rgb_display_set_vga_palette_entry(int index, uint16_t rgb565);
uint16_t rgb_display_get_vga_palette_entry(int index);

/* Re-sync the text-mode palette LUT from get_text_palette() and redraw. */
void rgb_display_refresh_palette(void);

/* Block until the next frame is pushed to the panel (graphics modes only). */
void rgb_display_wait_vsync(void);

#ifdef __cplusplus
}
#endif
