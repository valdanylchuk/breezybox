# breezy_term

This is the vterm used in [BreezyBox](https://github.com/valdanylchuk/breezybox), a mini shell for esp32-s3. It seemed nice and reusable, so I release it as a standalone component with no dependencies, for people who need a vterm but do not need full BreezyBox shell.

[![Component Registry](https://components.espressif.com/components/valdanylchuk/breezy_term/badge.svg)](https://components.espressif.com/components/valdanylchuk/breezy_term)

## Features

- Enough ANSI codes for simplified VI
- Fixed size for now
- Good performance proven in BreezyBox
- 4 VTs by default, F1-F4 hotkey switching
- 16 colors (SGR), configurable palette
- Save/restore on switching to graphics mode
- Cell-based screen buffer with character + attribute per cell
- ANSI escape sequence parsing (cursor movement, colors, clear)
- Optional stdio bridge (`vterm_vfs_init`) for printf/getchar routing

## Installation

### ESP Component Registry (Recommended)

```bash
idf.py add-dependency "valdanylchuk/breezy_term"
```

### Manual Installation

Clone into your project's `components` folder:

```bash
cd your_project/components
git clone https://github.com/valdanylchuk/breezy_term.git
```

## Quick Start

### A. Using with LCD or any custom display (main use case)

```c
#include "vterm.h"

void app_main(void)
{
    vterm_init();

    // Get the zero-copy cell buffer (IRAM-backed, active VT)
    vterm_cell_t *cells = vterm_get_direct_buffer();
    int rows, cols;
    vterm_get_size(&rows, &cols);

    // Write to the active VT
    int vt = vterm_get_active();
    vterm_write(vt, "Hello, world!\n", 14);
    vterm_write(vt, "\033[32mGreen text\033[0m\n", 20);

    // Your display render loop reads cells directly:
    // cells[row * cols + col].ch   holds the  character
    // cells[row * cols + col].attr holds (bg << 4) | fg
    // Use VTERM_ATTR_FG() / VTERM_ATTR_BG() macros to unpack.
}
```

The cell buffer is updated in-place by `vterm_write`. Your display
driver can read it at any time (DMA bounce buffer, timer, etc.)
without any copy step.

### B. Stdio bridge (printf/getchar through vterm)

```c
#include <stdio.h>
#include "driver/usb_serial_jtag.h"
#include "freertos/FreeRTOS.h"
#include "vterm.h"

void app_main(void)
{
    // Initialize USB-JTAG driver for passthrough
    usb_serial_jtag_driver_config_t usb_config = {
        .tx_buffer_size = 256,
        .rx_buffer_size = 256,
    };
    usb_serial_jtag_driver_install(&usb_config);

    // Initialize vterm and redirect stdio
    vterm_init();
    vterm_vfs_init(true);

    // Now printf/getchar go through vterm
    printf("Hello from vterm!\n");
    printf("\033[31mRed text\033[0m\n");

    while (1) {
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}
```

After `vterm_vfs_init()`, all printf output goes through the vterm
ANSI parser into the cell buffer. Input from `vterm_input_feed()`
(your keyboard driver) becomes available via getchar.

### C. Direct API (no display, no stdio)

At its core, vterm is a terminal state machine: you feed it text
(including ANSI escape sequences), and it maintains a cell buffer
with parsed characters, colors, and cursor position. On the input
side, it provides a per-VT queue and intercepts F1-F4 for VT
switching; all other input passes through to your app unchanged.

```c
#include "vterm.h"

void app_main(void)
{
    vterm_init();
    int vt = vterm_get_active();

    // Write text; ANSI codes are parsed into cell attributes
    vterm_write(vt, "Hello!\n", 7);
    vterm_write(vt, "\033[32mGreen\033[0m\n", 16);

    // Read back the parsed cell buffer
    vterm_cell_t *cells = vterm_get_direct_buffer();
    // cells[row * VTERM_COLS + col].ch   holds the character
    // cells[row * VTERM_COLS + col].attr holds the color attribute

    // Feed and read keyboard input
    vterm_send_input(vt, 'y');
    int ch = vterm_getchar(vt, 1000);  // returns 'y'
}
```

BreezyBox uses vterm to switch transparently between writing to LCD screen, USB console, or both.

## Extended fully working example/demo

[My BreezyBox-based hobby cyberdeck project](https://github.com/valdanylchuk/breezydemo).

Includes integration with a custom LCD driver, stdio routing, and a demo video.

See also some [BreezyBox compatible ELF apps here](https://github.com/valdanylchuk/breezyapps).

## Virtual Terminals

Switch between terminals using:
- **F1-F4**: Switch to VT0-VT3
- **Ctrl+F1-F4**: Switch to VT0-VT3 (alternative)

## Dependencies

- ESP-IDF >= 5.0
- uses PSRAM for inactive buffers to save IRAM

## License

This is free software under MIT License - see [LICENSE](LICENSE) file.
