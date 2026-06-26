# breezy_rgb_lcd

[![Component Registry](https://components.espressif.com/components/valdanylchuk/breezy_rgb_lcd/badge.svg)](https://components.espressif.com/components/valdanylchuk/breezy_rgb_lcd)

This is the rgb_lcd display driver used in [BreezyBox demo](https://github.com/valdanylchuk/breezydemo), a mini shell for esp32-s3. It seemed nice and reusable, so I release it as a standalone component with minimal dependencies, for people who need a similar display driver, but do not need full BreezyBox shell.

I wrote this to make a big 7" 1024x600 display work fast with esp32-s3. The key is to keep a small buffer for text or low-res graphics in IRAM, and render/scale to a small DMA bounce buffer on the fly, e.g. 10 scan lines at a time.

## Features

- Text mode
- Scaled graphics mode
- Tested on one board: [Waveshare ESP32-S3-Touch-LCD-7B](https://www.waveshare.com/product/esp32-s3-lcd-7b.htm) (no affiliation)
- Good performance proven in BreezyBox demo and Celeste port

## Installation

### ESP Component Registry (Recommended)

```bash
idf.py add-dependency "valdanylchuk/breezy_rgb_lcd"
```

### Manual Installation

Clone into your project's `components` folder:

```bash
cd your_project/components
git clone https://github.com/valdanylchuk/breezy_rgb_lcd.git
```

## Quick Start

### A. Text mode

The text mode only renders from a text screen buffer, which is usually managed by vterm, but you can also use it directly.

```c
#include "freertos/FreeRTOS.h"
#include "rgb_display.h"

static lcd_cell_t s_cells[DISPLAY_COLS * DISPLAY_ROWS];

static void put_str(int col, int row, uint8_t attr, const char *str) {
    lcd_cell_t *p = &s_cells[row * DISPLAY_COLS + col];
    while (*str && col++ < DISPLAY_COLS)
        *p++ = (lcd_cell_t){ .ch = *str++, .attr = attr };
}

void app_main(void) {
    rgb_display_init();
    rgb_display_set_buffer(s_cells);

    put_str(0, 0, 0x07, "breezy_rgb_lcd text mode demo");  // light gray
    put_str(0, 1, 0x0A, "Hello, World!");                   // bright green

    while (1) {
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}
```

### B. Text mode with vterm

Here is the minimal setup to link this driver to the [breezy_term virtual terminal](https://components.espressif.com/components/valdanylchuk/breezy_term):

```c
#include "freertos/FreeRTOS.h"
#include "rgb_display.h"
#include "vterm.h"

void app_main(void)
{
    vterm_init();
    rgb_display_init();
    rgb_display_set_buffer((lcd_cell_t *)vterm_get_direct_buffer());

    vterm_write(0, "breezy_rgb_lcd text mode demo\n", 30);
    vterm_write(0, "\033[32mHello, World!\033[0m\n",  23);

    while (1) {
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}
```

You can also do vterm_vfs_init() for a more complete setup, and then just use printf() and other stdio functions as usual in C console programs.

### C. Scaled graphics mode

```c
#include "freertos/FreeRTOS.h"
#include "rgb_display.h"
#include "rgb_gfx.h"

#define W  256
#define H  150

void app_main(void)
{
    rgb_display_init();
    rgb_display_set_mode(SM_150P);

    int x = 10, y = 10, vx = 3, vy = 2;
    int bw = 40, bh = 30;
    uint8_t color = 1;
    while (1) {
        rgb_gfx_rect(x, y, bw, bh, color++);
        x += vx; y += vy;
        if (x <= 0 || x + bw >= W) vx = -vx;
        if (y <= 0 || y + bh >= H) vy = -vy;
        vTaskDelay(pdMS_TO_TICKS(30));
    }
}
```

## Extended fully working example/demo

[My BreezyBox-based hobby cyberdeck project](https://github.com/valdanylchuk/breezydemo).

Includes integration with a vterm, stdio routing, and a demo video.

See also some [BreezyBox compatible ELF apps here](https://github.com/valdanylchuk/breezyapps).

## Dependencies

- ESP-IDF >= 5.0
- Standard modules: esp_lcd, heap

## License

This is free software under MIT License - see [LICENSE](LICENSE) file.

The included Terminus font by Dimitar Toshkov Zhekov is lisenced under [SIL Open Font License](terminus-font-license.txt).
