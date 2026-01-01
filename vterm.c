/*
 * vterm.c - Virtual Terminal Manager
 */

#include "vterm.h"
#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"
#include "freertos/semphr.h"
#include "esp_heap_caps.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define INPUT_QUEUE_SIZE    64
#define MAX_TASKS           8

typedef struct {
    vterm_cell_t cells[VTERM_ROWS][VTERM_COLS];
    int cursor_x;
    int cursor_y;
    uint8_t current_attr;   // Current drawing attribute
    QueueHandle_t input_queue;
    SemaphoreHandle_t mutex;
    int dirty;  // Needs refresh
} vterm_t;

static vterm_t *s_vterms = NULL;
static volatile int s_active_vt = 0;
static void (*s_on_switch_cb)(int new_vt) = NULL;
static void (*s_on_render_cb)(int vt_id) = NULL;

// Task-to-VT mapping
typedef struct {
    TaskHandle_t task;
    int vt_id;
} task_map_entry_t;

static task_map_entry_t s_task_map[MAX_TASKS];
static SemaphoreHandle_t s_task_map_mutex;

// ============ Internal Functions ============

static void vterm_scroll(vterm_t *vt)
{
    // Move all lines up by one
    memmove(&vt->cells[0][0], &vt->cells[1][0], 
            (VTERM_ROWS - 1) * VTERM_COLS * sizeof(vterm_cell_t));
    // Clear last line
    for (int x = 0; x < VTERM_COLS; x++) {
        vt->cells[VTERM_ROWS - 1][x].ch = ' ';
        vt->cells[VTERM_ROWS - 1][x].attr = VTERM_DEFAULT_ATTR;
    }
    vt->cursor_y = VTERM_ROWS - 1;
}

static void vterm_putchar_internal(vterm_t *vt, char c)
{
    switch (c) {
    case '\n':
        vt->cursor_x = 0;
        vt->cursor_y++;
        if (vt->cursor_y >= VTERM_ROWS) {
            vterm_scroll(vt);
        }
        break;
        
    case '\r':
        vt->cursor_x = 0;
        break;
        
    case '\b':
        if (vt->cursor_x > 0) {
            vt->cursor_x--;
            vt->cells[vt->cursor_y][vt->cursor_x].ch = ' ';
            vt->cells[vt->cursor_y][vt->cursor_x].attr = vt->current_attr;
        }
        break;
        
    case '\t':
        // Tab to next 8-column boundary
        do {
            vt->cells[vt->cursor_y][vt->cursor_x].ch = ' ';
            vt->cells[vt->cursor_y][vt->cursor_x].attr = vt->current_attr;
            vt->cursor_x++;
        } while (vt->cursor_x < VTERM_COLS && (vt->cursor_x % 8) != 0);
        if (vt->cursor_x >= VTERM_COLS) {
            vt->cursor_x = 0;
            vt->cursor_y++;
            if (vt->cursor_y >= VTERM_ROWS) {
                vterm_scroll(vt);
            }
        }
        break;
        
    default:
        if (c >= 32 && c < 127) {
            vt->cells[vt->cursor_y][vt->cursor_x].ch = c;
            vt->cells[vt->cursor_y][vt->cursor_x].attr = vt->current_attr;
            vt->cursor_x++;
            if (vt->cursor_x >= VTERM_COLS) {
                vt->cursor_x = 0;
                vt->cursor_y++;
                if (vt->cursor_y >= VTERM_ROWS) {
                    vterm_scroll(vt);
                }
            }
        }
        break;
    }
    
    vt->dirty = 1;
}

static void vterm_clear_internal(vterm_t *vt)
{
    for (int y = 0; y < VTERM_ROWS; y++) {
        for (int x = 0; x < VTERM_COLS; x++) {
            vt->cells[y][x].ch = ' ';
            vt->cells[y][x].attr = VTERM_DEFAULT_ATTR;
        }
    }
    vt->cursor_x = 0;
    vt->cursor_y = 0;
    vt->current_attr = VTERM_DEFAULT_ATTR;
    vt->dirty = 1;
}

// Handle ANSI escape sequences
// Supports: cursor movement, clear screen, and SGR (colors)
static int s_escape_state = 0;  // 0=normal, 1=got ESC, 2=got ESC[
static char s_escape_buf[32];
static int s_escape_len = 0;

// Parse SGR (Select Graphic Rendition) parameters and update current_attr
static void vterm_apply_sgr(vterm_t *vt, const char *params)
{
    // Parse semicolon-separated numbers
    // Empty or "0" = reset, 1 = bold, 30-37 = fg, 40-47 = bg, 90-97 = bright fg, 100-107 = bright bg
    
    const char *p = params;
    int bright = 0;
    
    // Handle empty params (ESC[m) as reset
    if (*p == '\0' || (*p == '0' && (p[1] == '\0' || p[1] == ';'))) {
        vt->current_attr = VTERM_DEFAULT_ATTR;
        if (*p == '0') p++;
        if (*p == ';') p++;
    }
    
    while (*p) {
        // Parse number
        int num = 0;
        while (*p >= '0' && *p <= '9') {
            num = num * 10 + (*p - '0');
            p++;
        }
        
        // Skip semicolon
        if (*p == ';') p++;
        
        // Apply the SGR code
        if (num == 0) {
            // Reset
            vt->current_attr = VTERM_DEFAULT_ATTR;
            bright = 0;
        } else if (num == 1) {
            // Bold/bright - apply to foreground
            bright = VTERM_BRIGHT;
            uint8_t fg = VTERM_ATTR_FG(vt->current_attr);
            uint8_t bg = VTERM_ATTR_BG(vt->current_attr);
            vt->current_attr = VTERM_ATTR(fg | VTERM_BRIGHT, bg);
        } else if (num == 22) {
            // Normal intensity (not bold)
            bright = 0;
            uint8_t fg = VTERM_ATTR_FG(vt->current_attr) & 0x07;
            uint8_t bg = VTERM_ATTR_BG(vt->current_attr);
            vt->current_attr = VTERM_ATTR(fg, bg);
        } else if (num >= 30 && num <= 37) {
            // Foreground color
            uint8_t fg = (num - 30) | bright;
            uint8_t bg = VTERM_ATTR_BG(vt->current_attr);
            vt->current_attr = VTERM_ATTR(fg, bg);
        } else if (num == 39) {
            // Default foreground
            uint8_t bg = VTERM_ATTR_BG(vt->current_attr);
            vt->current_attr = VTERM_ATTR(VTERM_WHITE, bg);
        } else if (num >= 40 && num <= 47) {
            // Background color
            uint8_t fg = VTERM_ATTR_FG(vt->current_attr);
            uint8_t bg = num - 40;
            vt->current_attr = VTERM_ATTR(fg, bg);
        } else if (num == 49) {
            // Default background
            uint8_t fg = VTERM_ATTR_FG(vt->current_attr);
            vt->current_attr = VTERM_ATTR(fg, VTERM_BLACK);
        } else if (num >= 90 && num <= 97) {
            // Bright foreground
            uint8_t fg = (num - 90) | VTERM_BRIGHT;
            uint8_t bg = VTERM_ATTR_BG(vt->current_attr);
            vt->current_attr = VTERM_ATTR(fg, bg);
        } else if (num >= 100 && num <= 107) {
            // Bright background
            uint8_t fg = VTERM_ATTR_FG(vt->current_attr);
            uint8_t bg = (num - 100) | VTERM_BRIGHT;
            vt->current_attr = VTERM_ATTR(fg, bg);
        }
        // Ignore other SGR codes (italic, underline, etc.)
    }
}

static int vterm_handle_escape(vterm_t *vt, char c)
{
    if (s_escape_state == 0) {
        if (c == '\033') {
            s_escape_state = 1;
            s_escape_len = 0;
            return 1;  // Consumed
        }
        return 0;  // Not an escape
    }
    
    if (s_escape_state == 1) {
        if (c == '[') {
            s_escape_state = 2;
            return 1;
        }
        // Unknown escape, reset
        s_escape_state = 0;
        return 0;
    }
    
    // s_escape_state == 2: collecting CSI parameters
    if (s_escape_len < (int)sizeof(s_escape_buf) - 1) {
        s_escape_buf[s_escape_len++] = c;
        s_escape_buf[s_escape_len] = '\0';
    }
    
    // Check for final character (letter)
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
        // Remove the final character from params for parsing
        s_escape_buf[s_escape_len - 1] = '\0';
        
        switch (c) {
        case 'm':
            // SGR - Select Graphic Rendition (colors)
            vterm_apply_sgr(vt, s_escape_buf);
            break;
            
        case 'J':
            // Erase in Display
            if (strcmp(s_escape_buf, "2") == 0 || strcmp(s_escape_buf, "") == 0) {
                vterm_clear_internal(vt);
            }
            break;
            
        case 'H':
        case 'f':
            // Cursor Position
            if (s_escape_buf[0] == '\0' || strcmp(s_escape_buf, "1;1") == 0) {
                vt->cursor_x = 0;
                vt->cursor_y = 0;
            } else {
                // Parse row;col
                int row = 1, col = 1;
                sscanf(s_escape_buf, "%d;%d", &row, &col);
                vt->cursor_y = (row > 0 ? row - 1 : 0);
                vt->cursor_x = (col > 0 ? col - 1 : 0);
                if (vt->cursor_y >= VTERM_ROWS) vt->cursor_y = VTERM_ROWS - 1;
                if (vt->cursor_x >= VTERM_COLS) vt->cursor_x = VTERM_COLS - 1;
            }
            break;
            
        case 'A':
            // Cursor Up
            {
                int n = 1;
                if (s_escape_buf[0]) n = atoi(s_escape_buf);
                if (n < 1) n = 1;
                vt->cursor_y -= n;
                if (vt->cursor_y < 0) vt->cursor_y = 0;
            }
            break;
            
        case 'B':
            // Cursor Down
            {
                int n = 1;
                if (s_escape_buf[0]) n = atoi(s_escape_buf);
                if (n < 1) n = 1;
                vt->cursor_y += n;
                if (vt->cursor_y >= VTERM_ROWS) vt->cursor_y = VTERM_ROWS - 1;
            }
            break;
            
        case 'C':
            // Cursor Forward
            {
                int n = 1;
                if (s_escape_buf[0]) n = atoi(s_escape_buf);
                if (n < 1) n = 1;
                vt->cursor_x += n;
                if (vt->cursor_x >= VTERM_COLS) vt->cursor_x = VTERM_COLS - 1;
            }
            break;
            
        case 'D':
            // Cursor Back
            {
                int n = 1;
                if (s_escape_buf[0]) n = atoi(s_escape_buf);
                if (n < 1) n = 1;
                vt->cursor_x -= n;
                if (vt->cursor_x < 0) vt->cursor_x = 0;
            }
            break;
            
        case 'K':
            // Erase in Line
            {
                int mode = 0;
                if (s_escape_buf[0]) mode = atoi(s_escape_buf);
                int start = 0, end = VTERM_COLS;
                if (mode == 0) {
                    // Cursor to end
                    start = vt->cursor_x;
                } else if (mode == 1) {
                    // Start to cursor
                    end = vt->cursor_x + 1;
                }
                // mode == 2: entire line (start=0, end=COLS)
                for (int x = start; x < end; x++) {
                    vt->cells[vt->cursor_y][x].ch = ' ';
                    vt->cells[vt->cursor_y][x].attr = vt->current_attr;
                }
            }
            break;

        case 'n':
            // Device Status Report / Cursor Position Report
            // Request: ESC [ 6 n
            // Response: ESC [ <r> ; <c> R
            if (s_escape_buf[0] == '6' && s_escape_buf[1] == '\0') {
                char resp[32];
                // VT coordinates are 1-based
                snprintf(resp, sizeof(resp), "\x1b[%d;%dR", vt->cursor_y + 1, vt->cursor_x + 1);
                
                // Inject response directly into input queue
                for (int i = 0; resp[i] != '\0'; i++) {
                    vterm_send_input(s_active_vt, resp[i]); // Or pass specific vt ID if context allows
                }
            }
            // Linenoise Probe sends ESC [ 5 n, expects ESC [ 0 n
            else if (s_escape_buf[0] == '5' && s_escape_buf[1] == '\0') {
                const char *resp = "\x1b[0n";
                for (int i = 0; resp[i] != '\0'; i++) {
                    vterm_send_input(s_active_vt, resp[i]);
                }
            }
            break;
            
        default:
            // Unknown CSI sequence, ignore
            break;
        }
        
        s_escape_state = 0;
        s_escape_len = 0;
        return 1;
    }
    
    return 1;  // Still in escape sequence
}

// ============ Public API ============

esp_err_t vterm_init(void)
{
    // --- CHANGE 2: Allocate memory in PSRAM ---
    if (s_vterms == NULL) {
        // Allocate the array of structures in PSRAM
        // We use calloc to zero-initialize it automatically
        s_vterms = (vterm_t *)heap_caps_calloc(VTERM_COUNT, sizeof(vterm_t), MALLOC_CAP_SPIRAM);
        
        if (s_vterms == NULL) {
            printf("Error: Failed to allocate vterm buffers in PSRAM\n");
            return ESP_ERR_NO_MEM;
        }
    }

    s_task_map_mutex = xSemaphoreCreateMutex();
    if (!s_task_map_mutex) {
        return ESP_ERR_NO_MEM;
    }
    
    // Clear task map
    memset(s_task_map, 0, sizeof(s_task_map));
    for (int i = 0; i < MAX_TASKS; i++) {
        s_task_map[i].vt_id = -1;
    }
    
    // Initialize each VT
    for (int i = 0; i < VTERM_COUNT; i++) {
        vterm_t *vt = &s_vterms[i];
        
        vt->input_queue = xQueueCreate(INPUT_QUEUE_SIZE, sizeof(char));
        if (!vt->input_queue) {
            return ESP_ERR_NO_MEM;
        }
        
        vt->mutex = xSemaphoreCreateMutex();
        if (!vt->mutex) {
            return ESP_ERR_NO_MEM;
        }
        
        vt->current_attr = VTERM_DEFAULT_ATTR;
        
        // Note: vterm_clear_internal needs s_vterms to be valid, which it now is.
        // We need to temporarily declare the prototype or move the function up, 
        // or just rely on the static declaration earlier in your file.
        // Assuming vterm_clear_internal is static defined above:
        vterm_clear_internal(vt); 
        
        vt->dirty = 0;
    }
    
    s_active_vt = 0;
    return ESP_OK;
}

void vterm_switch(int vt_id)
{
    if (vt_id < 0 || vt_id >= VTERM_COUNT) return;
    if (vt_id == s_active_vt) return;
    
    s_active_vt = vt_id;
    vterm_refresh();
    
    // Call user callback if registered
    if (s_on_switch_cb) {
        s_on_switch_cb(vt_id);
    }
}

void vterm_set_switch_callback(void (*cb)(int new_vt))
{
    s_on_switch_cb = cb;
}

void vterm_set_render_callback(void (*cb)(int vt_id))
{
    s_on_render_cb = cb;
}

// Notify that screen content changed (call render callback if active VT)
static void notify_render(int vt_id)
{
    if (s_on_render_cb && vt_id == s_active_vt) {
        s_on_render_cb(vt_id);
    }
}

int vterm_get_active(void)
{
    return s_active_vt;
}

void vterm_putchar(int vt_id, char c)
{
    if (vt_id < 0 || vt_id >= VTERM_COUNT) return;
    
    vterm_t *vt = &s_vterms[vt_id];
    
    xSemaphoreTake(vt->mutex, portMAX_DELAY);
    
    // Handle escape sequences
    if (!vterm_handle_escape(vt, c)) {
        vterm_putchar_internal(vt, c);
    }
    
    xSemaphoreGive(vt->mutex);
    
    // Notify render callback (outside mutex to avoid deadlock)
    notify_render(vt_id);
}

void vterm_write(int vt_id, const char *data, size_t len)
{
    if (vt_id < 0 || vt_id >= VTERM_COUNT) return;
    
    vterm_t *vt = &s_vterms[vt_id];
    
    xSemaphoreTake(vt->mutex, portMAX_DELAY);
    
    for (size_t i = 0; i < len; i++) {
        if (!vterm_handle_escape(vt, data[i])) {
            vterm_putchar_internal(vt, data[i]);
        }
    }
    
    xSemaphoreGive(vt->mutex);
    
    // Notify render callback once for the whole write
    notify_render(vt_id);
}

int vterm_getchar(int vt_id, int timeout_ms)
{
    if (vt_id < 0 || vt_id >= VTERM_COUNT) return -1;
    
    vterm_t *vt = &s_vterms[vt_id];
    char c;
    
    TickType_t wait = (timeout_ms < 0) ? portMAX_DELAY : pdMS_TO_TICKS(timeout_ms);
    
    if (xQueueReceive(vt->input_queue, &c, wait) == pdTRUE) {
        return (unsigned char)c;
    }
    return -1;
}

void vterm_send_input(int vt_id, char c)
{
    if (vt_id < 0 || vt_id >= VTERM_COUNT) return;
    
    vterm_t *vt = &s_vterms[vt_id];
    xQueueSend(vt->input_queue, &c, 0);
}

void vterm_set_task(TaskHandle_t task, int vt_id)
{
    xSemaphoreTake(s_task_map_mutex, portMAX_DELAY);
    
    // Find existing or empty slot
    int empty_slot = -1;
    for (int i = 0; i < MAX_TASKS; i++) {
        if (s_task_map[i].task == task) {
            s_task_map[i].vt_id = vt_id;
            xSemaphoreGive(s_task_map_mutex);
            return;
        }
        if (empty_slot < 0 && s_task_map[i].task == NULL) {
            empty_slot = i;
        }
    }
    
    // Add new mapping
    if (empty_slot >= 0) {
        s_task_map[empty_slot].task = task;
        s_task_map[empty_slot].vt_id = vt_id;
    }
    
    xSemaphoreGive(s_task_map_mutex);
}

int vterm_get_task_vt(TaskHandle_t task)
{
    int vt_id = -1;
    
    xSemaphoreTake(s_task_map_mutex, portMAX_DELAY);
    
    for (int i = 0; i < MAX_TASKS; i++) {
        if (s_task_map[i].task == task) {
            vt_id = s_task_map[i].vt_id;
            break;
        }
    }
    
    xSemaphoreGive(s_task_map_mutex);
    return vt_id;
}

int vterm_get_current_vt(void)
{
    int vt = vterm_get_task_vt(xTaskGetCurrentTaskHandle());
    // Default to active VT if not mapped
    return (vt >= 0) ? vt : s_active_vt;
}

void vterm_clear(int vt_id)
{
    if (vt_id < 0 || vt_id >= VTERM_COUNT) return;
    
    vterm_t *vt = &s_vterms[vt_id];
    
    xSemaphoreTake(vt->mutex, portMAX_DELAY);
    vterm_clear_internal(vt);
    xSemaphoreGive(vt->mutex);
    
    if (vt_id == s_active_vt) {
        vterm_refresh();
    }
    
    notify_render(vt_id);
}

void vterm_refresh(void)
{
    vterm_t *vt = &s_vterms[s_active_vt];
    
    xSemaphoreTake(vt->mutex, portMAX_DELAY);
    vt->dirty = 0;
    xSemaphoreGive(vt->mutex);
    
    // Notify render callback
    notify_render(s_active_vt);
}

// Display status indicator showing active VT
void vterm_show_status(void)
{
    // Status format: "[VT0]" or "[VT1]" in top-right corner
    char status[8];
    snprintf(status, sizeof(status), "[VT%d]", s_active_vt);
    
    // TODO: Could overlay on screen via render callback
    (void)status;
}

int vterm_input_available(int vt_id)
{
    if (vt_id < 0 || vt_id >= VTERM_COUNT) return 0;
    return uxQueueMessagesWaiting(s_vterms[vt_id].input_queue) > 0;
}

const vterm_cell_t *vterm_get_cells(int vt_id)
{
    if (vt_id < 0 || vt_id >= VTERM_COUNT) return NULL;
    // Note: caller should hold mutex or accept slight race conditions
    return &s_vterms[vt_id].cells[0][0];
}

void vterm_get_size(int *rows, int *cols)
{
    if (rows) *rows = VTERM_ROWS;
    if (cols) *cols = VTERM_COLS;
}

// ============ Input Routing with Hotkey Detection ============

/*
 * Hotkey sequences supported (all switch to VT 0-3):
 * 
 * Ctrl+F1-F4:
 *   ESC [ 1 ; 5 P/Q/R/S       (xterm style)
 *   ESC [ 11;5~ to [14;5~    (vt style with modifier)
 *   ESC O 5 P/Q/R/S          (alternate)
 * 
 * Plain F1-F4 (fallback):
 *   ESC O P/Q/R/S
 *   ESC [ 11~ to [14~
 *
 * Ctrl+1-4:
 *   ESC [ 49;5u to [52;5u    (CSI u / fixterms mode)
 */

static char s_esc_buf[16];
static int s_esc_len = 0;
static TickType_t s_esc_start = 0;

// Flush buffered escape chars to active vterm as regular input
static void flush_input_buffer(void)
{
    for (int i = 0; i < s_esc_len; i++) {
        vterm_send_input(s_active_vt, s_esc_buf[i]);
    }
    s_esc_len = 0;
}

// Check if buffer matches a VT switch sequence, return VT number or -1
static int match_vt_hotkey(void)
{
    if (s_esc_len < 2) return -1;
    
    // Must start with ESC
    if (s_esc_buf[0] != '\033') return -1;
    
    // ESC O <x> - F1-F4 or Ctrl+F1-F4
    if (s_esc_len >= 3 && s_esc_buf[1] == 'O') {
        char c = s_esc_buf[2];
        // ESC O P/Q/R/S = F1-F4
        if (c == 'P') return 0;
        if (c == 'Q') return 1;
        if (c == 'R') return 2;
        if (c == 'S') return 3;
        
        // ESC O 5 P/Q/R/S = Ctrl+F1-F4 (some terminals)
        if (s_esc_len >= 4 && c == '5') {
            char d = s_esc_buf[3];
            if (d == 'P') return 0;
            if (d == 'Q') return 1;
            if (d == 'R') return 2;
            if (d == 'S') return 3;
        }
    }
    
    // ESC [ ... sequences
    if (s_esc_len >= 3 && s_esc_buf[1] == '[') {
        // Null-terminate for easier parsing
        s_esc_buf[s_esc_len] = '\0';
        
        // ESC [ 1 ; 5 P/Q/R/S = Ctrl+F1-F4 (xterm)
        if (s_esc_len == 6 && s_esc_buf[2] == '1' && s_esc_buf[3] == ';' && s_esc_buf[4] == '5') {
            char c = s_esc_buf[5];
            if (c == 'P') return 0;
            if (c == 'Q') return 1;
            if (c == 'R') return 2;
            if (c == 'S') return 3;
        }
        
        // ESC [ 11~ to [14~ = F1-F4 (vt style)
        // ESC [ 11;5~ to [14;5~ = Ctrl+F1-F4 (vt style with modifier)
        if (s_esc_buf[s_esc_len - 1] == '~') {
            int num = 0;
            
            // Parse: ESC [ <num> ~ or ESC [ <num> ; <mod> ~
            char *p = &s_esc_buf[2];
            while (*p >= '0' && *p <= '9') {
                num = num * 10 + (*p - '0');
                p++;
            }
            // Skip optional modifier (;5 etc) - we accept with or without
            if (*p == ';') {
                p++;
                while (*p >= '0' && *p <= '9') p++;
            }
            
            // F1=11, F2=12, F3=13, F4=14
            if (num >= 11 && num <= 14) {
                return num - 11;
            }
        }
        
        // ESC [ 49;5u to [52;5u = Ctrl+1-4 (CSI u / fixterms)
        // 49='1', 50='2', 51='3', 52='4'
        if (s_esc_buf[s_esc_len - 1] == 'u') {
            int codepoint = 0;
            int modifier = 0;
            
            char *p = &s_esc_buf[2];
            while (*p >= '0' && *p <= '9') {
                codepoint = codepoint * 10 + (*p - '0');
                p++;
            }
            if (*p == ';') {
                p++;
                while (*p >= '0' && *p <= '9') {
                    modifier = modifier * 10 + (*p - '0');
                    p++;
                }
            }
            
            // Modifier 5 = Ctrl
            if (modifier == 5 && codepoint >= 49 && codepoint <= 52) {
                return codepoint - 49;  // '1'->0, '2'->1, etc.
            }
        }
    }
    
    return -1;
}

// Check if we're in the middle of a potential hotkey sequence
static int could_be_hotkey(void)
{
    if (s_esc_len == 0) return 0;
    if (s_esc_buf[0] != '\033') return 0;
    if (s_esc_len == 1) return 1;  // Just ESC, wait for more
    
    char c1 = s_esc_buf[1];
    
    // ESC O ... or ESC [ ... could be hotkeys
    if (c1 == 'O' || c1 == '[') {
        // Limit max length to avoid hanging on garbage
        if (s_esc_len > 10) return 0;
        
        // Check for terminal characters
        if (s_esc_len >= 3) {
            char last = s_esc_buf[s_esc_len - 1];
            // These end a sequence
            if (last == '~' || last == 'u' || 
                (last >= 'A' && last <= 'Z') ||
                (c1 == 'O' && s_esc_len >= 3 && last >= 'P' && last <= 'S')) {
                return 0;  // Sequence complete, should be matched by now
            }
        }
        return 1;  // Still building sequence
    }
    
    return 0;
}

int vterm_input_feed(char c)
{
    // Timeout: if we're in escape state too long, flush and reset
    if (s_esc_len > 0) {
        if ((xTaskGetTickCount() - s_esc_start) > pdMS_TO_TICKS(20)) {
            flush_input_buffer();
        }
    }
    
    // Start of new escape sequence?
    if (s_esc_len == 0 && c == '\033') {
        s_esc_buf[s_esc_len++] = c;
        s_esc_start = xTaskGetTickCount();
        return 0;  // Buffering
    }
    
    // If we're in an escape sequence, add to buffer
    if (s_esc_len > 0) {
        if (s_esc_len < (int)sizeof(s_esc_buf) - 1) {
            s_esc_buf[s_esc_len++] = c;
        }
        
        // Check for complete hotkey match
        int vt = match_vt_hotkey();
        if (vt >= 0) {
            s_esc_len = 0;
            vterm_switch(vt);
            return 1;  // Hotkey handled
        }
        
        // Could this still become a hotkey?
        if (could_be_hotkey()) {
            return 0;  // Keep buffering
        }
        
        // Not a hotkey, flush as regular input
        flush_input_buffer();
        return 0;
    }
    
    // Normal character, pass through
    vterm_send_input(s_active_vt, c);
    return 0;
}