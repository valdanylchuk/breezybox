/*
 * rgb_gfx.h - Graphics primitives for 8bpp indexed-color modes.
 *
 * Operate on the current framebuffer obtained via rgb_display_get_framebuffer()
 * (valid only in SM_VGA13H / SM_150P). Panel-agnostic; ABI-compatible with the
 * S3 breezy_rgb_lcd rgb_gfx API so loadable apps link unchanged.
 */
#pragma once

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Clear the entire framebuffer to a single color index. */
void rgb_gfx_clear(uint8_t color);

/* Single pixel (bounds-checked). */
void rgb_gfx_pixel(int x, int y, uint8_t color);

/* Fast horizontal / vertical lines. */
void rgb_gfx_hline(int x, int y, int w, uint8_t color);
void rgb_gfx_vline(int x, int y, int h, uint8_t color);

/* Rectangle outline / filled rectangle. */
void rgb_gfx_rect(int x, int y, int w, int h, uint8_t color);
void rgb_gfx_rectfill(int x, int y, int w, int h, uint8_t color);

/*
 * Blit 8bpp indexed sprite data.
 *   data              source pixels (row-major, 8bpp indexed)
 *   x, y              destination position
 *   w, h              sprite dimensions
 *   src_stride        bytes per source row (usually == w)
 *   transparent_color color index to skip (-1 for no transparency)
 */
void rgb_gfx_blit(const uint8_t *data, int x, int y, int w, int h,
                  int src_stride, int transparent_color);

/* Blit with optional horizontal/vertical flip. */
void rgb_gfx_blit_flip(const uint8_t *data, int x, int y, int w, int h,
                       int src_stride, int transparent_color,
                       bool flip_x, bool flip_y);

#ifdef __cplusplus
}
#endif
