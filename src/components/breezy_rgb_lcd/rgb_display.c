/*
* rgb_display.c - Tuned Text Renderer (Zero-Copy)
*
* Reads directly from interleaved lcd_cell_t buffer (IRAM).
* Optimized for 32-bit reads with 2-byte aligned cells.
* Uses configurable 16-color palette via callbacks.
*/

#include "rgb_display.h"
#include "rgb_gfx.h"
#include "esp_log.h"
#include "esp_lcd_panel_ops.h"
#include "esp_lcd_panel_rgb.h"
#include "esp_heap_caps.h"
#include "esp_memory_utils.h"
#include "freertos/FreeRTOS.h"
#include "freertos/semphr.h"
#include <string.h>

static const char *TAG = "display";

#define SCREEN_WIDTH    1024
#define SCREEN_HEIGHT   600
#define BOUNCE_HEIGHT_PX 12  // 12 lines = 24KB bounce buffer (used by both text and graphics modes)
#define FONT_WIDTH      8
#define FONT_HEIGHT     16
#define TEXT_COLS       128
#define TEXT_ROWS       37

// Graphics mode constants - VGA 13h (320x200)
#define GFX_VGA_WIDTH   320
#define GFX_VGA_HEIGHT  200
#define GFX_VGA_SIZE    (GFX_VGA_WIDTH * GFX_VGA_HEIGHT)  // 64000 bytes
#define GFX_VGA_SCALE   3      // 3x upscale: 320*3=960, 200*3=600
#define GFX_VGA_MARGIN_X 32    // (1024 - 960) / 2 = 32 pixels black margin each side

// Graphics mode constants - 150P (256x150)
#define GFX_150P_WIDTH  256
#define GFX_150P_HEIGHT 150
#define GFX_150P_SIZE   (GFX_150P_WIDTH * GFX_150P_HEIGHT)  // 38400 bytes
#define GFX_150P_SCALE  4      // 4x upscale: 256*4=1024, 150*4=600 (perfect fit!)

// Current mode dimensions (set during mode switch)
static int s_gfx_width = 0;
static int s_gfx_height = 0;
static int s_gfx_scale = 0;
static int s_gfx_margin_x = 0;

// Pointer to external buffer (managed by caller, e.g. vterm)
static lcd_cell_t *s_display_buffer = NULL;

static esp_lcd_panel_handle_t panel_handle = NULL;

// Screen mode state
static screen_mode_t s_screen_mode = SM_TEXT;
static uint8_t *s_graphics_framebuffer = NULL;

// VSYNC synchronization
static SemaphoreHandle_t s_vsync_sem = NULL;
static volatile bool s_waiting_for_vsync = false;

// Cursor state (volatile for IRAM callback access)
static volatile int s_cursor_col = -1;  // -1 = hidden
static volatile int s_cursor_row = -1;
static uint32_t s_frame_count = 0;

// LUTs
static uint8_t font_ram[256][16];
static uint32_t BYTE_MASKS[256][4];
static const uint32_t MASK_LUT[4] = { 0x00000000, 0xFFFF0000, 0x0000FFFF, 0xFFFFFFFF };

// ATTR_LUT: precomputed bg32 and xor32 for each attribute byte
// ATTR_LUT[attr][0] = bg32, ATTR_LUT[attr][1] = xor32
static uint32_t ATTR_LUT[256][2];

// VGA 256-color palette (RGB565)
static uint16_t s_vga_palette[256];

// External font data
extern const uint8_t terminus16_glyph_bitmap[];

// Callbacks for terminal/console integration (optional)
static const rgb_display_callbacks_t *s_callbacks = NULL;

// Standard 16 CGA colors (RGB565)
static const uint16_t s_cga_colors[16] = {
    0x0000, // 0: Black
    0x0015, // 1: Blue
    0x0540, // 2: Green
    0x0555, // 3: Cyan
    0xA800, // 4: Red
    0xA815, // 5: Magenta
    0xA520, // 6: Brown (dark yellow)
    0xAD55, // 7: Light Gray
    0x52AA, // 8: Dark Gray
    0x52BF, // 9: Light Blue
    0x57EA, // 10: Light Green
    0x57FF, // 11: Light Cyan
    0xFAAA, // 12: Light Red
    0xFABF, // 13: Light Magenta
    0xFFE0, // 14: Yellow
    0xFFFF, // 15: White
};

static void init_vga_palette(void)
{
    // Copy CGA colors to first 16 entries
    memcpy(s_vga_palette, s_cga_colors, sizeof(s_cga_colors));

    // Generate 6x6x6 color cube for indices 16-231
    int idx = 16;
    for (int r = 0; r < 6; r++) {
        for (int g = 0; g < 6; g++) {
            for (int b = 0; b < 6; b++) {
                // Convert 0-5 levels to RGB565
                uint16_t r5 = (r * 51 * 31) / 255;  // 0-5 -> 0-31
                uint16_t g6 = (g * 51 * 63) / 255;  // 0-5 -> 0-63
                uint16_t b5 = (b * 51 * 31) / 255;  // 0-5 -> 0-31
                s_vga_palette[idx++] = (r5 << 11) | (g6 << 5) | b5;
            }
        }
    }

    // Generate 24-step grayscale for indices 232-255
    for (int i = 0; i < 24; i++) {
        int gray = 8 + i * 10;  // 8, 18, 28, ... 238
        uint16_t g5 = (gray * 31) / 255;
        uint16_t g6 = (gray * 63) / 255;
        s_vga_palette[232 + i] = (g5 << 11) | (g6 << 5) | g5;
    }
}

static int allocate_graphics_framebuffer(screen_mode_t mode)
{
    if (s_graphics_framebuffer != NULL) {
        return 0;  // Already allocated
    }

    // Determine size based on mode
    int fb_size;
    if (mode == SM_VGA13H) {
        fb_size = GFX_VGA_SIZE;
        s_gfx_width = GFX_VGA_WIDTH;
        s_gfx_height = GFX_VGA_HEIGHT;
        s_gfx_scale = GFX_VGA_SCALE;
        s_gfx_margin_x = GFX_VGA_MARGIN_X;
    } else if (mode == SM_150P) {
        fb_size = GFX_150P_SIZE;
        s_gfx_width = GFX_150P_WIDTH;
        s_gfx_height = GFX_150P_HEIGHT;
        s_gfx_scale = GFX_150P_SCALE;
        s_gfx_margin_x = 0;  // Perfect 4x fit, no margin needed
    } else {
        ESP_LOGE(TAG, "Unknown graphics mode for allocation: %d", mode);
        return -1;
    }

    // Try internal RAM first (faster for DMA)
    s_graphics_framebuffer = heap_caps_malloc(fb_size,
        MALLOC_CAP_INTERNAL | MALLOC_CAP_8BIT);

#ifdef CONFIG_SPIRAM
    if (!s_graphics_framebuffer) {
        // Fallback to PSRAM if internal RAM is tight
        ESP_LOGW(TAG, "Internal RAM tight, using PSRAM for framebuffer");
        s_graphics_framebuffer = heap_caps_malloc(fb_size, MALLOC_CAP_SPIRAM);
    }
#endif

    if (!s_graphics_framebuffer) {
        ESP_LOGE(TAG, "Failed to allocate graphics framebuffer (%d bytes)", fb_size);
        return -1;
    }

    // Diagnostic: confirm memory region
    if (esp_ptr_internal(s_graphics_framebuffer)) {
        ESP_LOGI(TAG, "Framebuffer in INTERNAL RAM at %p (%d bytes)", s_graphics_framebuffer, fb_size);
    } else if (esp_ptr_external_ram(s_graphics_framebuffer)) {
        ESP_LOGW(TAG, "Framebuffer in PSRAM at %p (%d bytes) - vsync timing may be tight", s_graphics_framebuffer, fb_size);
    }

    // Clear to black (palette index 0)
    memset(s_graphics_framebuffer, 0, fb_size);
    return 0;
}

static void free_graphics_framebuffer(void)
{
    if (s_graphics_framebuffer) {
        heap_caps_free(s_graphics_framebuffer);
        s_graphics_framebuffer = NULL;
        ESP_LOGI(TAG, "Freed graphics framebuffer");
    }
}

static void rebuild_attr_lut(void)
{
    const uint16_t *palette = (s_callbacks && s_callbacks->get_text_palette)
        ? s_callbacks->get_text_palette()
        : s_cga_colors;

    for (int attr = 0; attr < 256; attr++) {
        uint8_t fg_idx = LCD_ATTR_FG(attr);
        uint8_t bg_idx = LCD_ATTR_BG(attr);

        uint16_t fg_color = palette[fg_idx];
        uint16_t bg_color = palette[bg_idx];

        uint32_t bg32 = (bg_color << 16) | bg_color;
        uint32_t fg32 = (fg_color << 16) | fg_color;

        ATTR_LUT[attr][0] = bg32;
        ATTR_LUT[attr][1] = fg32 ^ bg32;  // xor32
    }
}

static void precompute_tables(void)
{
    // Build ATTR_LUT from palette
    rebuild_attr_lut();

    // Pre-compute glyph byte to pixel masks
    for (int i = 0; i < 256; i++) {
        BYTE_MASKS[i][0] = MASK_LUT[(i >> 6) & 0x03];
        BYTE_MASKS[i][1] = MASK_LUT[(i >> 4) & 0x03];
        BYTE_MASKS[i][2] = MASK_LUT[(i >> 2) & 0x03];
        BYTE_MASKS[i][3] = MASK_LUT[i & 0x03];
    }
}

static IRAM_ATTR bool on_bounce_empty(esp_lcd_panel_handle_t panel, void *buf,
                                    int pos_px, int len_bytes, void *user_ctx)
{
    // Clear to black - also serves as fallback if nothing is ready
    memset(buf, 0, len_bytes);

    int y_start = pos_px / SCREEN_WIDTH;
    int num_lines = (len_bytes / 2) / SCREEN_WIDTH;

    // Frame counter for cursor blink (increment at start of each frame)
    if (y_start == 0) s_frame_count++;

    // === GRAPHICS MODE (SM_VGA13H or SM_150P) ===
    if ((s_screen_mode == SM_VGA13H || s_screen_mode == SM_150P) && s_graphics_framebuffer) {
        uint16_t *dest_base = (uint16_t *)buf;
        int gfx_width = s_gfx_width;
        int gfx_height = s_gfx_height;
        int gfx_scale = s_gfx_scale;
        int gfx_margin = s_gfx_margin_x;

        for (int line = 0; line < num_lines; line++) {
            int lcd_y = y_start + line;

            // Map LCD Y to source framebuffer Y (divide by scale factor)
            int src_y = lcd_y / gfx_scale;
            if (src_y >= gfx_height) continue;  // Past end of framebuffer

            uint16_t *dest = dest_base + (line * SCREEN_WIDTH);
            const uint8_t *src_row = &s_graphics_framebuffer[src_y * gfx_width];

            // Skip left margin (black from memset) - 0 for 150P, 32 for VGA13H
            dest += gfx_margin;

            // Render with appropriate horizontal scaling
            if (gfx_scale == 4) {
                // 4x scaling for 150P mode (256*4=1024, perfect fit)
                for (int x = 0; x < gfx_width; x++) {
                    uint16_t color = s_vga_palette[src_row[x]];
                    *dest++ = color;
                    *dest++ = color;
                    *dest++ = color;
                    *dest++ = color;
                }
            } else {
                // 3x scaling for VGA13H mode (320*3=960)
                for (int x = 0; x < gfx_width; x++) {
                    uint16_t color = s_vga_palette[src_row[x]];
                    *dest++ = color;
                    *dest++ = color;
                    *dest++ = color;
                }
            }
            // Right margin already black from memset
        }
        return false;
    }

    // === TEXT MODE (SM_TEXT) ===
    if (!s_display_buffer) return false;

    const lcd_cell_t *src_buf = s_display_buffer;

    // Cursor state: check once per callback
    int cursor_col = s_cursor_col;
    int cursor_row = s_cursor_row;
    // Blink at ~2Hz: frame_count >> 4 toggles every 16 frames (~0.5s at 30fps)
    int cursor_blink_on = (s_frame_count >> 4) & 1;

    for (int line = 0; line < num_lines; line++) {
        int y = y_start + line;
        int text_row = y / FONT_HEIGHT;
        if (text_row >= TEXT_ROWS) continue;

        int glyph_y = y % FONT_HEIGHT;
        uint32_t *dest = (uint32_t *)((uint8_t *)buf + (line * SCREEN_WIDTH * 2));

        // Check if cursor should be drawn on this scanline (last 2 rows of glyph)
        int draw_cursor = (cursor_row >= 0 && text_row == cursor_row &&
                          glyph_y >= FONT_HEIGHT - 2 && cursor_blink_on);

        // Get pointer to the start of the row in the cell buffer
        const lcd_cell_t *cell_row_ptr = &src_buf[text_row * TEXT_COLS];

        // Process 2 cells at a time using 32-bit aligned reads
        // With 2-byte cells, reading 4 bytes gives us 2 cells
        const uint32_t *cell_pairs = (const uint32_t *)cell_row_ptr;

        for (int pair = 0; pair < TEXT_COLS / 2; pair++) {
            uint32_t cell_data = cell_pairs[pair];

            // Extract cell 0 (low 16 bits): ch in bits 0-7, attr in bits 8-15
            uint8_t ch0 = cell_data & 0xFF;
            uint8_t attr0 = (cell_data >> 8) & 0xFF;

            // Extract cell 1 (high 16 bits): ch in bits 16-23, attr in bits 24-31
            uint8_t ch1 = (cell_data >> 16) & 0xFF;
            uint8_t attr1 = (cell_data >> 24) & 0xFF;

            // --- Render cell 0 ---
            uint32_t bg32_0 = ATTR_LUT[attr0][0];
            uint32_t xor32_0 = ATTR_LUT[attr0][1];
            uint8_t glyph0 = font_ram[ch0][glyph_y];

            if (glyph0 == 0) {
                *dest++ = bg32_0; *dest++ = bg32_0; *dest++ = bg32_0; *dest++ = bg32_0;
            } else {
                const uint32_t *m = BYTE_MASKS[glyph0];
                *dest++ = (xor32_0 & m[0]) ^ bg32_0;
                *dest++ = (xor32_0 & m[1]) ^ bg32_0;
                *dest++ = (xor32_0 & m[2]) ^ bg32_0;
                *dest++ = (xor32_0 & m[3]) ^ bg32_0;
            }

            // Cursor underscore for cell 0
            if (draw_cursor && pair * 2 == cursor_col) {
                uint32_t fg32 = bg32_0 ^ xor32_0;
                dest[-4] = fg32; dest[-3] = fg32; dest[-2] = fg32; dest[-1] = fg32;
            }

            // --- Render cell 1 ---
            uint32_t bg32_1 = ATTR_LUT[attr1][0];
            uint32_t xor32_1 = ATTR_LUT[attr1][1];
            uint8_t glyph1 = font_ram[ch1][glyph_y];

            if (glyph1 == 0) {
                *dest++ = bg32_1; *dest++ = bg32_1; *dest++ = bg32_1; *dest++ = bg32_1;
            } else {
                const uint32_t *m = BYTE_MASKS[glyph1];
                *dest++ = (xor32_1 & m[0]) ^ bg32_1;
                *dest++ = (xor32_1 & m[1]) ^ bg32_1;
                *dest++ = (xor32_1 & m[2]) ^ bg32_1;
                *dest++ = (xor32_1 & m[3]) ^ bg32_1;
            }

            // Cursor underscore for cell 1
            if (draw_cursor && pair * 2 + 1 == cursor_col) {
                uint32_t fg32 = bg32_1 ^ xor32_1;
                dest[-4] = fg32; dest[-3] = fg32; dest[-2] = fg32; dest[-1] = fg32;
            }
        }
    }
    return false;
}

static IRAM_ATTR bool on_vsync(esp_lcd_panel_handle_t panel,
                                const esp_lcd_rgb_panel_event_data_t *edata,
                                void *user_ctx)
{
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;
    if (s_waiting_for_vsync && s_vsync_sem) {
        xSemaphoreGiveFromISR(s_vsync_sem, &xHigherPriorityTaskWoken);
        s_waiting_for_vsync = false;
    }
    return xHigherPriorityTaskWoken;
}

void rgb_display_init(void)
{
    ESP_LOGI(TAG, "Initializing RGB LCD (Bounce Buffer Text Mode - Zero Copy)");

    volatile const void *exports[] = { // for ELF binaries
        // Display API
        (void *)rgb_display_refresh_palette,
        (void *)rgb_display_set_mode,
        (void *)rgb_display_get_mode,
        (void *)rgb_display_get_framebuffer,
        (void *)rgb_display_get_fb_width,
        (void *)rgb_display_get_fb_height,
        (void *)rgb_display_set_vga_palette,
        (void *)rgb_display_set_vga_palette_entry,
        (void *)rgb_display_get_vga_palette_entry,
        (void *)rgb_display_wait_vsync,
        // Graphics primitives
        (void *)rgb_gfx_clear,
        (void *)rgb_gfx_pixel,
        (void *)rgb_gfx_hline,
        (void *)rgb_gfx_vline,
        (void *)rgb_gfx_rect,
        (void *)rgb_gfx_rectfill,
        (void *)rgb_gfx_blit,
        (void *)rgb_gfx_blit_flip,
    };
    (void)exports; // suppress unused warning

    // Initialize VGA palette before precomputing tables
    init_vga_palette();
    precompute_tables();

    // Load font to RAM
    memset(font_ram, 0, sizeof(font_ram));
    for (int i = 0x20; i < 0x100; i++)
        memcpy(font_ram[i], &terminus16_glyph_bitmap[(i - 0x20) * 16], 16);

    esp_lcd_rgb_panel_config_t panel_config = {
        .clk_src = LCD_CLK_SRC_DEFAULT,
        .timings = {
            .pclk_hz = 20 * 1000 * 1000,
            .h_res = SCREEN_WIDTH,
            .v_res = SCREEN_HEIGHT,
            .hsync_pulse_width = 162,
            .hsync_back_porch = 152,
            .hsync_front_porch = 48,
            .vsync_pulse_width = 45,
            .vsync_back_porch = 13,
            .vsync_front_porch = 3,
            .flags.pclk_active_neg = 1,
        },
        .data_width = 16,
        .bits_per_pixel = 16,
        .num_fbs = 0,
        .flags.no_fb = 1,
        .bounce_buffer_size_px = SCREEN_WIDTH * BOUNCE_HEIGHT_PX,
        .hsync_gpio_num = 46,
        .vsync_gpio_num = 3,
        .de_gpio_num = 5,
        .pclk_gpio_num = 7,
        .disp_gpio_num = -1,
        .data_gpio_nums = {14, 38, 18, 17, 10, 39, 0, 45, 48, 47, 21, 1, 2, 42, 41, 40},
    };

    ESP_ERROR_CHECK(esp_lcd_new_rgb_panel(&panel_config, &panel_handle));

    // Create vsync semaphore for graphics mode synchronization
    s_vsync_sem = xSemaphoreCreateBinary();

    esp_lcd_rgb_panel_event_callbacks_t cbs = {
        .on_bounce_empty = on_bounce_empty,
        .on_vsync = on_vsync,
    };
    ESP_ERROR_CHECK(esp_lcd_rgb_panel_register_event_callbacks(panel_handle, &cbs, NULL));
    ESP_ERROR_CHECK(esp_lcd_panel_init(panel_handle));

    ESP_LOGI(TAG, "Display ready: %dx%d pixels, %dx%d chars",
            SCREEN_WIDTH, SCREEN_HEIGHT, TEXT_COLS, TEXT_ROWS);
}

void rgb_display_set_buffer(lcd_cell_t *cells)
{
    s_display_buffer = cells;
}

void rgb_display_set_callbacks(const rgb_display_callbacks_t *cb)
{
    s_callbacks = cb;
}

// Rebuild ATTR_LUT when palette changes
void rgb_display_refresh_palette(void)
{
    rebuild_attr_lut();
}

// Set cursor position for blinking underscore (-1 to hide)
void rgb_display_set_cursor(int col, int row)
{
    s_cursor_col = col;
    s_cursor_row = row;
}

// --- Screen Mode API ---

screen_mode_t rgb_display_get_mode(void)
{
    return s_screen_mode;
}

int rgb_display_set_mode(screen_mode_t mode)
{
    if (mode == s_screen_mode) {
        return 0;  // Already in this mode
    }

    if (mode == SM_VGA13H || mode == SM_150P) {
        // Notify external system to save text state and redirect console
        if (s_callbacks && s_callbacks->enter_graphics) {
            if (s_callbacks->enter_graphics() != 0) return -1;
        }

        // Switch to graphics mode
        if (allocate_graphics_framebuffer(mode) != 0) {
            // Rollback
            if (s_callbacks && s_callbacks->exit_graphics)
                s_callbacks->exit_graphics();
            return -1;
        }
        s_screen_mode = mode;
        s_display_buffer = NULL;  // Disable text buffer pointer
        ESP_LOGI(TAG, "Switched to %s mode",
                mode == SM_VGA13H ? "VGA13H (320x200)" : "150P (256x150)");
    }
    else if (mode == SM_TEXT) {
        // Switch back to text mode
        s_screen_mode = SM_TEXT;
        free_graphics_framebuffer();

        // Notify external system to restore text state and console routing
        if (s_callbacks && s_callbacks->exit_graphics)
            s_callbacks->exit_graphics();

        // Re-link display buffer from external system
        if (s_callbacks && s_callbacks->get_text_buffer)
            s_display_buffer = s_callbacks->get_text_buffer();

        // Flush stale input accumulated during graphics mode
        if (s_callbacks && s_callbacks->flush_input)
            s_callbacks->flush_input();

        ESP_LOGI(TAG, "Switched to text mode");
    }
    else {
        ESP_LOGE(TAG, "Unknown screen mode: %d", mode);
        return -1;  // Unknown mode
    }

    return 0;
}

uint8_t *rgb_display_get_framebuffer(void)
{
    return s_graphics_framebuffer;
}

// --- VGA Palette API ---

void rgb_display_set_vga_palette(const uint16_t palette[256])
{
    memcpy(s_vga_palette, palette, sizeof(s_vga_palette));
}

void rgb_display_set_vga_palette_entry(int index, uint16_t rgb565)
{
    if (index >= 0 && index < 256) {
        s_vga_palette[index] = rgb565;
    }
}

uint16_t rgb_display_get_vga_palette_entry(int index)
{
    if (index >= 0 && index < 256) {
        return s_vga_palette[index];
    }
    return 0;
}

// --- VSYNC Synchronization ---

void rgb_display_wait_vsync(void)
{
    if ((s_screen_mode != SM_VGA13H && s_screen_mode != SM_150P) || !s_vsync_sem) return;
    s_waiting_for_vsync = true;
    xSemaphoreTake(s_vsync_sem, pdMS_TO_TICKS(100));  // Timeout ~2 frames
}

// --- Framebuffer Dimension Getters ---

int rgb_display_get_fb_width(void)
{
    return s_gfx_width;
}

int rgb_display_get_fb_height(void)
{
    return s_gfx_height;
}
