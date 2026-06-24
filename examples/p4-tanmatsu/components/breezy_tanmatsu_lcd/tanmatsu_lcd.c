/*
 * tanmatsu_lcd.c - Text renderer for the Tanmatsu (ESP32-P4) MIPI panel.
 *
 * Draws a vterm character-cell grid into a PSRAM framebuffer and pushes it to
 * the panel via badge-bsp (bsp_display_blit). A background task redraws only
 * when the buffer is marked dirty or the cursor needs to blink.
 */

#include "tanmatsu_lcd.h"

#include <string.h>
#include <stdbool.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_heap_caps.h"
#include "esp_log.h"

#include "bsp/display.h"

static const char *TAG = "tanmatsu_lcd";

#define BLINK_MS       500
#define REFRESH_MS     33      /* ~30 fps cap; only blits when dirty */

/* --- Font (Terminus 8x16), chars 0x20..0xFF in terminus16.c --- */
extern const uint8_t terminus16_glyph_bitmap[];
static uint8_t s_font[256][TANMATSU_FONT_H];

/* --- Panel geometry / format ---
 *
 * The Tanmatsu ST7701 is a 480x800 *portrait* panel, but the device is held in
 * landscape; badge-bsp reports this as BSP_DISPLAY_ROTATION_270. So we keep two
 * coordinate systems:
 *   - physical (s_pw x s_ph): the panel's native 480x800 framebuffer we blit.
 *   - logical  (s_lw x s_lh): the upright landscape canvas we draw text into
 *                             (800x480 -> 100x30 cells), rotated into physical.
 */
static int     s_pw = 0, s_ph = 0;     /* physical panel pixels (native) */
static int     s_lw = 0, s_lh = 0;     /* logical (rotated) canvas pixels */
static int     s_rot = 270;            /* default rotation from the BSP */
static int     s_bpp = 3;              /* bytes per pixel */
static bool    s_is_565 = false;
static uint8_t *s_fb = NULL;

/* Map a logical landscape pixel to its byte offset in the physical framebuffer.
 * Handles the four BSP rotations; 270 (PAX_O_ROT_CW) is the Tanmatsu default. */
static inline uint8_t *phys_px(int lx, int ly)
{
    int px, py;
    switch (s_rot) {
        case 90:   px = ly;            py = s_ph - 1 - lx;  break;
        case 180:  px = s_pw - 1 - lx; py = s_ph - 1 - ly;  break;
        case 270:  px = s_pw - 1 - ly; py = lx;             break;
        default:   px = lx;            py = ly;             break;  /* 0 */
    }
    return s_fb + ((size_t)py * s_pw + px) * s_bpp;
}

/* --- Source cell buffer --- */
static const lcd_cell_t *s_cells = NULL;
static int     s_cols = 0, s_rows = 0;

/* --- Cursor --- */
static volatile int s_cur_col = -1, s_cur_row = -1;

/* --- Dirty / blink state --- */
static volatile bool s_dirty = true;
static bool          s_last_blink = false;

/* --- Palette: 16 CGA colors (RGB565), expanded to output bytes --- */
static const uint16_t s_cga565[16] = {
    0x0000, 0x0015, 0x0540, 0x0555, 0xA800, 0xA815, 0xA520, 0xAD55,
    0x52AA, 0x52BF, 0x57EA, 0x57FF, 0xFAAA, 0xFABF, 0xFFE0, 0xFFFF,
};
static uint16_t s_pal565[16];
static uint8_t  s_out888[16][3];  /* pre-ordered output bytes per palette index */
static uint16_t s_out565[16];     /* pre-ordered 16-bit value per palette index */
static bool     s_endian_big = false;

static inline uint8_t exp5(uint8_t v5) { return (uint8_t)((v5 * 255 + 15) / 31); }
static inline uint8_t exp6(uint8_t v6) { return (uint8_t)((v6 * 255 + 31) / 63); }

static void rebuild_palette_out(void)
{
    for (int i = 0; i < 16; i++) {
        uint16_t c = s_pal565[i];
        uint8_t r = exp5((c >> 11) & 0x1F);
        uint8_t g = exp6((c >> 5) & 0x3F);
        uint8_t b = exp5(c & 0x1F);
        if (s_endian_big) {            /* BGR byte order */
            s_out888[i][0] = b; s_out888[i][1] = g; s_out888[i][2] = r;
            s_out565[i] = (uint16_t)((c << 8) | (c >> 8));
        } else {                       /* RGB byte order */
            s_out888[i][0] = r; s_out888[i][1] = g; s_out888[i][2] = b;
            s_out565[i] = c;
        }
    }
}

void tanmatsu_lcd_set_palette(const uint16_t *palette16)
{
    memcpy(s_pal565, palette16 ? palette16 : s_cga565, sizeof(s_pal565));
    rebuild_palette_out();
    s_dirty = true;
}

void tanmatsu_lcd_set_buffer(const lcd_cell_t *cells, int cols, int rows)
{
    s_cells = cells;
    s_cols = cols;
    s_rows = rows;
    s_dirty = true;
}

void tanmatsu_lcd_set_cursor(int col, int row)
{
    s_cur_col = col;
    s_cur_row = row;
    s_dirty = true;
}

void tanmatsu_lcd_mark_dirty(void) { s_dirty = true; }

void tanmatsu_lcd_get_text_size(int *cols, int *rows)
{
    if (cols) *cols = s_lw / TANMATSU_FONT_W;
    if (rows) *rows = s_lh / TANMATSU_FONT_H;
}

/* Render one full frame into s_fb. */
static void render_frame(bool blink_on)
{
    const lcd_cell_t *cells = s_cells;
    if (!cells || !s_fb) return;

    const int cols = s_cols, rows = s_rows;
    const int cur_col = s_cur_col, cur_row = s_cur_row;

    /* Iterate in logical (landscape) coordinates; phys_px() rotates each pixel
     * into the native portrait framebuffer. */
    for (int ty = 0; ty < rows; ty++) {
        int ly0 = ty * TANMATSU_FONT_H;
        if (ly0 >= s_lh) break;

        for (int gy = 0; gy < TANMATSU_FONT_H; gy++) {
            int ly = ly0 + gy;
            if (ly >= s_lh) break;

            for (int tx = 0; tx < cols; tx++) {
                int lx0 = tx * TANMATSU_FONT_W;
                if (lx0 >= s_lw) break;

                lcd_cell_t cell = cells[ty * cols + tx];
                uint8_t ch   = (uint8_t)cell.ch;
                uint8_t fg   = LCD_ATTR_FG(cell.attr);
                uint8_t bg   = LCD_ATTR_BG(cell.attr);
                uint8_t glyph = s_font[ch][gy];

                /* Blinking underscore cursor: bottom two glyph rows. */
                bool cursor_line = (cur_col == tx && cur_row == ty &&
                                    gy >= TANMATSU_FONT_H - 2 && blink_on);

                for (int bit = 0; bit < TANMATSU_FONT_W; bit++) {
                    int lx = lx0 + bit;
                    if (lx >= s_lw) break;
                    bool on = cursor_line || (glyph & (0x80 >> bit));
                    uint8_t idx = on ? fg : bg;
                    uint8_t *p = phys_px(lx, ly);
                    if (s_is_565) {
                        uint16_t v = s_out565[idx];
                        p[0] = (uint8_t)v;
                        p[1] = (uint8_t)(v >> 8);
                    } else {
                        p[0] = s_out888[idx][0];
                        p[1] = s_out888[idx][1];
                        p[2] = s_out888[idx][2];
                    }
                }
            }
        }
    }
}

static void render_task(void *arg)
{
    (void)arg;
    for (;;) {
        uint32_t now = xTaskGetTickCount();
        bool blink = ((now / pdMS_TO_TICKS(BLINK_MS)) & 1) != 0;

        if (s_dirty || blink != s_last_blink) {
            s_dirty = false;
            s_last_blink = blink;
            render_frame(blink);
            esp_err_t err = bsp_display_blit(0, 0, s_pw, s_ph, s_fb);
            if (err != ESP_OK) {
                ESP_LOGW(TAG, "blit failed: %s", esp_err_to_name(err));
            }
        }
        vTaskDelay(pdMS_TO_TICKS(REFRESH_MS));
    }
}

esp_err_t tanmatsu_lcd_init(void)
{
    size_t h_res = 0, v_res = 0;
    bsp_display_color_format_t fmt = 0;
    bsp_display_endianness_t endian = 0;

    esp_err_t err = bsp_display_get_parameters(&h_res, &v_res, &fmt, &endian);
    if (err != ESP_OK) {
        ESP_LOGE(TAG, "bsp_display_get_parameters failed: %s", esp_err_to_name(err));
        return err;
    }
    s_pw = (int)h_res;
    s_ph = (int)v_res;
    s_endian_big = (endian == BSP_DISPLAY_ENDIAN_BIG);

    /* Honor the panel's mounting rotation (Tanmatsu reports 270). For 90/270
     * the logical landscape canvas is the physical dims swapped. */
    switch (bsp_display_get_default_rotation()) {
        case BSP_DISPLAY_ROTATION_90:  s_rot = 90;  break;
        case BSP_DISPLAY_ROTATION_180: s_rot = 180; break;
        case BSP_DISPLAY_ROTATION_270: s_rot = 270; break;
        default:                       s_rot = 0;   break;
    }
    if (s_rot == 90 || s_rot == 270) {
        s_lw = s_ph; s_lh = s_pw;
    } else {
        s_lw = s_pw; s_lh = s_ph;
    }

    /* We requested 24_888RGB in app_main; handle 16-bit panels too just in case. */
    if (fmt == BSP_DISPLAY_COLOR_FORMAT_24_888RGB) {
        s_bpp = 3; s_is_565 = false;
    } else {
        /* Assume a 16-bit RGB565 panel. */
        s_bpp = 2; s_is_565 = true;
        ESP_LOGW(TAG, "Unexpected color format %d, assuming RGB565", (int)fmt);
    }

    /* Load font: control chars (<0x20) render blank. */
    memset(s_font, 0, sizeof(s_font));
    for (int i = 0x20; i < 0x100; i++) {
        memcpy(s_font[i], &terminus16_glyph_bitmap[(i - 0x20) * TANMATSU_FONT_H],
               TANMATSU_FONT_H);
    }

    /* Default palette. */
    memcpy(s_pal565, s_cga565, sizeof(s_pal565));
    rebuild_palette_out();

    /* Framebuffer in PSRAM (sized to the native panel, not the logical canvas). */
    size_t fb_size = (size_t)s_pw * s_ph * s_bpp;
    s_fb = heap_caps_malloc(fb_size, MALLOC_CAP_SPIRAM | MALLOC_CAP_8BIT);
    if (!s_fb) {
        s_fb = heap_caps_malloc(fb_size, MALLOC_CAP_8BIT);  /* fallback */
    }
    if (!s_fb) {
        ESP_LOGE(TAG, "Failed to allocate %u-byte framebuffer", (unsigned)fb_size);
        return ESP_ERR_NO_MEM;
    }
    memset(s_fb, 0, fb_size);

    ESP_LOGI(TAG, "Panel %dx%d (rot %d) -> logical %dx%d, %d bpp -> text grid %dx%d",
             s_pw, s_ph, s_rot, s_lw, s_lh, s_bpp * 8,
             s_lw / TANMATSU_FONT_W, s_lh / TANMATSU_FONT_H);

    BaseType_t ok = xTaskCreate(render_task, "lcd_render", 4096, NULL, 4, NULL);
    if (ok != pdPASS) {
        ESP_LOGE(TAG, "Failed to start render task");
        return ESP_FAIL;
    }
    return ESP_OK;
}
