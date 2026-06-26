/*
 * rgb_gfx.h - Graphics primitives for 8bpp indexed color modes
 *
 * Provides basic drawing functions for use in graphics mode (SM_VGA13H, SM_150P).
 * All functions operate on the current framebuffer obtained via rgb_display_get_framebuffer().
 */

#pragma once

#include <stdint.h>
#include <stdbool.h>

// Clear entire framebuffer to a single color
void rgb_gfx_clear(uint8_t color);

// Single pixel (with bounds checking)
void rgb_gfx_pixel(int x, int y, uint8_t color);

// Fast horizontal line
void rgb_gfx_hline(int x, int y, int w, uint8_t color);

// Fast vertical line
void rgb_gfx_vline(int x, int y, int h, uint8_t color);

// Rectangle outline
void rgb_gfx_rect(int x, int y, int w, int h, uint8_t color);

// Filled rectangle
void rgb_gfx_rectfill(int x, int y, int w, int h, uint8_t color);

// Blit 8bpp sprite data with transparency
// data: source pixel data (row-major, 8bpp indexed)
// x, y: destination position
// w, h: sprite dimensions
// src_stride: bytes per row in source (usually == w)
// transparent_color: color index to skip (-1 for no transparency)
void rgb_gfx_blit(const uint8_t *data, int x, int y, int w, int h,
                 int src_stride, int transparent_color);

// Blit with horizontal/vertical flip
void rgb_gfx_blit_flip(const uint8_t *data, int x, int y, int w, int h,
                      int src_stride, int transparent_color,
                      bool flip_x, bool flip_y);
