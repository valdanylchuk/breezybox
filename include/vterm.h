/*
 * vterm.h - Virtual Terminal Manager
 * 
 * Provides multiple virtual terminals with independent screen buffers
 * and input queues. Only the active VT is displayed and receives input.
 * 
 * Hotkeys (multiple encodings supported):
 *   Ctrl+F1, Ctrl+1, F1  -> Switch to VT0
 *   Ctrl+F2, Ctrl+2, F2  -> Switch to VT1
 *   Ctrl+F3, Ctrl+3, F3  -> Switch to VT2
 *   Ctrl+F4, Ctrl+4, F4  -> Switch to VT3
 */

#pragma once

#include "esp_err.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <stddef.h>
#include <stdint.h>

#define VTERM_COUNT     4       // Number of virtual terminals
#define VTERM_COLS      53      // Screen columns
#define VTERM_ROWS      20

// ANSI 16-color palette indices
#define VTERM_BLACK     0
#define VTERM_RED       1
#define VTERM_GREEN     2
#define VTERM_YELLOW    3
#define VTERM_BLUE      4
#define VTERM_MAGENTA   5
#define VTERM_CYAN      6
#define VTERM_WHITE     7
// 8-15 = bright variants (add 8)
#define VTERM_BRIGHT    8

// Attribute macros
#define VTERM_ATTR(fg, bg)    (((bg) << 4) | ((fg) & 0x0F))
#define VTERM_ATTR_FG(attr)   ((attr) & 0x0F)
#define VTERM_ATTR_BG(attr)   (((attr) >> 4) & 0x0F)
#define VTERM_DEFAULT_ATTR    VTERM_ATTR(VTERM_WHITE, VTERM_BLACK)

// Cell structure: one character with its color attribute
typedef struct {
    char ch;        // Character
    uint8_t attr;   // Color: bits 0-3 = fg, bits 4-7 = bg
} vterm_cell_t;

// Initialize virtual terminal system
esp_err_t vterm_init(void);

// Switch to a different VT (0-3), refreshes display
void vterm_switch(int vt_id);

// Get currently active VT
int vterm_get_active(void);

// Feed input character from keyboard (USB/BT)
// This handles hotkey detection and routes to active VT
// Returns: 0 = normal char (routed to vterm), 1 = hotkey handled
int vterm_input_feed(char c);

// Write a character to a specific VT's screen buffer
void vterm_putchar(int vt_id, char c);

// Write string to a specific VT's screen buffer
void vterm_write(int vt_id, const char *data, size_t len);

// Read a character from VT's input queue (blocks if empty)
// timeout_ms: max wait time, or -1 for infinite
// Returns character, or -1 on timeout
int vterm_getchar(int vt_id, int timeout_ms);

// Send a character directly to a VT's input queue (bypasses hotkey handling)
void vterm_send_input(int vt_id, char c);

// Assign a task to a VT (for multi-task support)
void vterm_set_task(TaskHandle_t task, int vt_id);

// Get which VT a task is assigned to (-1 if none)
int vterm_get_task_vt(TaskHandle_t task);

// Get VT for current task (convenience)
int vterm_get_current_vt(void);

// Clear a VT's screen
void vterm_clear(int vt_id);

// Refresh display (triggers render callback)
void vterm_refresh(void);

// Check if there's pending input for a VT (non-blocking)
int vterm_input_available(int vt_id);

// Register callback for VT switch events
void vterm_set_switch_callback(void (*cb)(int new_vt));

// Register callback for screen content changes (for custom rendering)
// Called whenever visible content changes on the active VT
void vterm_set_render_callback(void (*cb)(int vt_id));

// Get direct access to cell buffer (for custom rendering)
const vterm_cell_t *vterm_get_cells(int vt_id);

// Get terminal dimensions
void vterm_get_size(int *rows, int *cols);