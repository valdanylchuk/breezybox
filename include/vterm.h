#pragma once
#include "esp_err.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <stddef.h>
#include <stdint.h>

#define VTERM_COUNT     4
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
void vterm_putchar(int vt_id, char c);
void vterm_write(int vt_id, const char *data, size_t len);
int vterm_getchar(int vt_id, int timeout_ms);
void vterm_send_input(int vt_id, char c);
void vterm_set_task(TaskHandle_t task, int vt_id);
int vterm_get_task_vt(TaskHandle_t task);
int vterm_get_current_vt(void);
void vterm_clear(int vt_id);
void vterm_refresh(void);
void vterm_get_size(int *rows, int *cols);
void vterm_get_cursor(int vt_id, int *col, int *row, int *visible);
void vterm_set_switch_callback(void (*cb)(int new_vt));
void vterm_set_render_callback(void (*cb)(int vt_id));
const vterm_cell_t *vterm_get_cells(int vt_id);
const vterm_cell_t *vterm_get_cells_for_render(int vt_id);
const vterm_cell_t *vterm_get_render_cells(int vt_id);
int vterm_snapshot_for_render(int vt_id);

// New API for zero-copy
vterm_cell_t *vterm_get_direct_buffer(void);

// Palette API - configurable 16-color palette (RGB565)
void vterm_set_palette_color(int index, uint16_t rgb565);
uint16_t vterm_get_palette_color(int index);
void vterm_set_palette(const uint16_t palette[16]);
const uint16_t *vterm_get_palette(void);