#pragma once
#include <stdint.h>

#define DISPLAY_COLS 128
#define DISPLAY_ROWS 37

// Text-mode cell: identical layout to vterm_cell_t, owned by the display component.
// Callers with their own cell type (e.g. vterm) just cast the pointer.
typedef struct {
    char ch;
    uint8_t attr;  // (bg << 4) | fg
} __attribute__((packed)) lcd_cell_t;

#define LCD_ATTR_FG(attr)  ((attr) & 0x0F)
#define LCD_ATTR_BG(attr)  (((attr) >> 4) & 0x0F)

// Screen modes (DOS-compatible constants)
typedef enum {
    SM_TEXT   = 3,      // Text mode (128x37 chars)
    SM_VGA13H = 0x13,   // VGA mode 13h: 320x200 @ 8bpp (256 colors)
    SM_150P   = 0x80,   // Custom mode: 256x150 @ 8bpp (256 colors)
} screen_mode_t;

// Callbacks for integrating with an external terminal / console system.
// All pointers may be NULL -- the display works standalone without them
// (you just won't get text-mode palette sync or graphics mode switching).
typedef struct {
    // Return the 16-color RGB565 palette for text-mode attribute LUT.
    // If NULL, CGA defaults are used.
    const uint16_t *(*get_text_palette)(void);

    // Enter graphics mode: save text buffer, redirect console, etc.
    // Return 0 on success, non-zero to abort mode switch.
    int (*enter_graphics)(void);

    // Exit graphics mode: restore text buffer and console routing.
    // Return 0 on success.
    int (*exit_graphics)(void);

    // After exiting graphics, return the text cell buffer pointer to re-link.
    // If NULL, display buffer stays NULL (no text rendering until set_buffer).
    lcd_cell_t *(*get_text_buffer)(void);

    // After exiting graphics, flush stale input (optional).
    void (*flush_input)(void);
} rgb_display_callbacks_t;

void rgb_display_init(void);
void rgb_display_set_buffer(lcd_cell_t *cells);
void rgb_display_set_callbacks(const rgb_display_callbacks_t *cb);

// Palette support - call after changing the text palette to update display LUT
void rgb_display_refresh_palette(void);

// Cursor support - set position for blinking underscore cursor
// Pass col=-1 or row=-1 to hide cursor
void rgb_display_set_cursor(int col, int row);

// Screen mode API
screen_mode_t rgb_display_get_mode(void);
int rgb_display_set_mode(screen_mode_t mode);  // Returns 0 on success

// Graphics framebuffer (only valid in graphics modes)
uint8_t *rgb_display_get_framebuffer(void);    // Returns NULL in text mode
int rgb_display_get_fb_width(void);            // Returns current framebuffer width (0 in text mode)
int rgb_display_get_fb_height(void);           // Returns current framebuffer height (0 in text mode)

// VGA 256-color palette (only used in graphics modes)
void rgb_display_set_vga_palette(const uint16_t palette[256]);
void rgb_display_set_vga_palette_entry(int index, uint16_t rgb565);
uint16_t rgb_display_get_vga_palette_entry(int index);

// VSYNC synchronization (only used in graphics modes)
// Block until next vertical blank
void rgb_display_wait_vsync(void);
