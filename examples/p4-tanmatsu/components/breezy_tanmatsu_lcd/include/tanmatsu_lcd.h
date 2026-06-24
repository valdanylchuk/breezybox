/*
 * tanmatsu_lcd.h - Text-mode display backend for the Tanmatsu (ESP32-P4).
 *
 * Renders a vterm-style character-cell grid to the Tanmatsu MIPI panel using
 * badge-bsp (bsp_display_blit). This is the P4 counterpart of the S3 demo's
 * breezy_rgb_lcd, minus the graphics modes (text-only for the MVP).
 *
 * The cell layout is byte-compatible with vterm_cell_t / lcd_cell_t:
 *   { char ch; uint8_t attr; }  where attr = (bg << 4) | fg  (16-color CGA).
 * Callers (e.g. the console layer) pass vterm's direct buffer straight in.
 */
#pragma once

#include <stdint.h>
#include "esp_err.h"

#ifdef __cplusplus
extern "C" {
#endif

#define TANMATSU_FONT_W 8
#define TANMATSU_FONT_H 16

typedef struct {
    char    ch;
    uint8_t attr;   /* (bg << 4) | fg */
} __attribute__((packed)) lcd_cell_t;

#define LCD_ATTR_FG(attr) ((attr) & 0x0F)
#define LCD_ATTR_BG(attr) (((attr) >> 4) & 0x0F)

/*
 * Initialize the renderer. Requires bsp_device_initialize() to have already
 * brought up the display (done in app_main). Queries the panel geometry,
 * allocates a framebuffer in PSRAM, loads the font/palette and starts the
 * background render task. Safe to call once.
 */
esp_err_t tanmatsu_lcd_init(void);

/*
 * Point the renderer at a character-cell buffer. `cols`/`rows` are the logical
 * grid dimensions AND the row stride of the buffer (cells[row*cols + col]).
 * Pass vterm_get_direct_buffer() with VTERM_COLS / VTERM_ROWS.
 */
void tanmatsu_lcd_set_buffer(const lcd_cell_t *cells, int cols, int rows);

/* Cursor position for the blinking underscore. col<0 or row<0 hides it. */
void tanmatsu_lcd_set_cursor(int col, int row);

/* Override the 16-color palette (RGB565). NULL restores the CGA defaults. */
void tanmatsu_lcd_set_palette(const uint16_t *palette16);

/* Request a redraw on the next render-task tick (call after writing cells). */
void tanmatsu_lcd_mark_dirty(void);

/* Panel-derived text grid that fits the display (h/8 x v/16). */
void tanmatsu_lcd_get_text_size(int *cols, int *rows);

#ifdef __cplusplus
}
#endif
