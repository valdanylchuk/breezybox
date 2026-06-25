/*
 * rgb_gfx.c - Graphics primitives for 8bpp indexed-color modes.
 *
 * Panel-agnostic: every primitive resolves the current framebuffer through
 * rgb_display_get_framebuffer() / _fb_width() / _fb_height(), so it works
 * identically on the S3 and the Tanmatsu (P4) display backends.
 */

#include "rgb_gfx.h"
#include "rgb_display.h"
#include <string.h>

/* Resolve the active framebuffer and its dimensions. */
static inline uint8_t *get_fb(int *w, int *h)
{
    *w = rgb_display_get_fb_width();
    *h = rgb_display_get_fb_height();
    return rgb_display_get_framebuffer();
}

void rgb_gfx_clear(uint8_t color)
{
    int w, h;
    uint8_t *fb = get_fb(&w, &h);
    if (fb && w > 0 && h > 0) {
        memset(fb, color, (size_t)w * h);
    }
}

void rgb_gfx_pixel(int x, int y, uint8_t color)
{
    int w, h;
    uint8_t *fb = get_fb(&w, &h);
    if (fb && x >= 0 && x < w && y >= 0 && y < h) {
        fb[y * w + x] = color;
    }
}

void rgb_gfx_hline(int x, int y, int len, uint8_t color)
{
    int w, h;
    uint8_t *fb = get_fb(&w, &h);
    if (!fb || y < 0 || y >= h || len <= 0) return;

    if (x < 0) { len += x; x = 0; }
    if (x + len > w) { len = w - x; }
    if (len <= 0) return;

    memset(&fb[y * w + x], color, len);
}

void rgb_gfx_vline(int x, int y, int len, uint8_t color)
{
    int w, h;
    uint8_t *fb = get_fb(&w, &h);
    if (!fb || x < 0 || x >= w || len <= 0) return;

    if (y < 0) { len += y; y = 0; }
    if (y + len > h) { len = h - y; }
    if (len <= 0) return;

    uint8_t *p = &fb[y * w + x];
    for (int i = 0; i < len; i++) {
        *p = color;
        p += w;
    }
}

void rgb_gfx_rect(int x, int y, int rw, int rh, uint8_t color)
{
    if (rw <= 0 || rh <= 0) return;

    rgb_gfx_hline(x, y, rw, color);
    rgb_gfx_hline(x, y + rh - 1, rw, color);
    if (rh > 2) {
        rgb_gfx_vline(x, y + 1, rh - 2, color);
        rgb_gfx_vline(x + rw - 1, y + 1, rh - 2, color);
    }
}

void rgb_gfx_rectfill(int x, int y, int rw, int rh, uint8_t color)
{
    int w, h;
    uint8_t *fb = get_fb(&w, &h);
    if (!fb || rw <= 0 || rh <= 0) return;

    int x0 = x, y0 = y;
    int x1 = x + rw, y1 = y + rh;
    if (x0 < 0) x0 = 0;
    if (y0 < 0) y0 = 0;
    if (x1 > w) x1 = w;
    if (y1 > h) y1 = h;

    int cw = x1 - x0;
    if (cw <= 0 || y1 - y0 <= 0) return;

    for (int row = y0; row < y1; row++) {
        memset(&fb[row * w + x0], color, cw);
    }
}

void rgb_gfx_blit(const uint8_t *data, int x, int y, int sw, int sh,
                  int src_stride, int transparent_color)
{
    int w, h;
    uint8_t *fb = get_fb(&w, &h);
    if (!fb || !data || sw <= 0 || sh <= 0) return;

    for (int sy = 0; sy < sh; sy++) {
        int dy = y + sy;
        if (dy < 0 || dy >= h) continue;

        const uint8_t *src_row = &data[sy * src_stride];
        uint8_t *dst_row = &fb[dy * w];

        for (int sx = 0; sx < sw; sx++) {
            int dx = x + sx;
            if (dx < 0 || dx >= w) continue;

            uint8_t pixel = src_row[sx];
            if (transparent_color < 0 || pixel != (uint8_t)transparent_color) {
                dst_row[dx] = pixel;
            }
        }
    }
}

void rgb_gfx_blit_flip(const uint8_t *data, int x, int y, int sw, int sh,
                       int src_stride, int transparent_color,
                       bool flip_x, bool flip_y)
{
    int w, h;
    uint8_t *fb = get_fb(&w, &h);
    if (!fb || !data || sw <= 0 || sh <= 0) return;

    for (int sy = 0; sy < sh; sy++) {
        int src_y = flip_y ? (sh - 1 - sy) : sy;
        int dy = y + sy;
        if (dy < 0 || dy >= h) continue;

        const uint8_t *src_row = &data[src_y * src_stride];
        uint8_t *dst_row = &fb[dy * w];

        for (int sx = 0; sx < sw; sx++) {
            int src_x = flip_x ? (sw - 1 - sx) : sx;
            int dx = x + sx;
            if (dx < 0 || dx >= w) continue;

            uint8_t pixel = src_row[src_x];
            if (transparent_color < 0 || pixel != (uint8_t)transparent_color) {
                dst_row[dx] = pixel;
            }
        }
    }
}
