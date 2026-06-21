#pragma once
#include "esp_err.h"
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

// VT count based on memory availability
#ifdef CONFIG_SPIRAM
#define VTERM_COUNT     4   // Multiple VTs with PSRAM backing
#else
#define VTERM_COUNT     1   // Single VT for systems without PSRAM
#endif

#define VTERM_COLS      128
#define VTERM_ROWS      37

#define VTERM_BLACK     0
#define VTERM_RED       1
#define VTERM_GREEN     2
#define VTERM_YELLOW    3
#define VTERM_BLUE      4
#define VTERM_MAGENTA   5
#define VTERM_CYAN      6
#define VTERM_WHITE     7
#define VTERM_BRIGHT    8

// Attribute byte packing: (bg << 4) | fg
#define VTERM_ATTR(fg, bg)    (((bg) << 4) | ((fg) & 0x0F))
#define VTERM_ATTR_FG(attr)   ((attr) & 0x0F)
#define VTERM_ATTR_BG(attr)   (((attr) >> 4) & 0x0F)
#define VTERM_DEFAULT_ATTR    VTERM_ATTR(VTERM_WHITE, VTERM_BLACK)

// 2-byte cell structure (optimized for 32-bit aligned access)
typedef struct {
    char ch;
    uint8_t attr;  // 4-bit fg + 4-bit bg
} __attribute__((packed)) vterm_cell_t;

esp_err_t vterm_init(void);
void vterm_switch(int vt_id);
int vterm_get_active(void);
int vterm_input_feed(char c);
void vterm_write(int vt_id, const char *data, size_t len);
int vterm_getchar(int vt_id, int timeout_ms);
void vterm_send_input(int vt_id, char c);
void vterm_get_size(int *rows, int *cols);
void vterm_get_cursor(int vt_id, int *col, int *row, int *visible);
void vterm_set_switch_callback(void (*cb)(int new_vt));

// Zero-copy cell buffer (active VT, IRAM-backed)
vterm_cell_t *vterm_get_direct_buffer(void);

// Palette API - configurable 16-color palette (RGB565)
void vterm_set_palette(const uint16_t palette[16]);
const uint16_t *vterm_get_palette(void);

// Flush all pending characters from a VT's input queue.
// Call after exiting apps that used polling input (games, etc.)
void vterm_input_flush(int vt_id);

// Stdio bridge: registers a VFS so printf/getchar go through vterm.
// Call after vterm_init(). Not needed if you use vterm_write/vterm_getchar directly.
// enable_usb_jtag_passthrough: if true, writes are also sent to USB-JTAG (requires driver init in main)
esp_err_t vterm_vfs_init(bool enable_usb_jtag_passthrough);

// Graphics mode integration
// Save current VT text buffer to PSRAM before entering graphics mode
int vterm_enter_graphics_mode(void);
// Restore VT text buffer from PSRAM after exiting graphics mode
int vterm_exit_graphics_mode(void);
