# breezy_bt

[![Component Registry](https://components.espressif.com/components/valdanylchuk/breezy_bt/badge.svg)](https://components.espressif.com/components/valdanylchuk/breezy_bt)

This is the bluetooth keyboard driver used in [BreezyBox demo](https://github.com/valdanylchuk/breezydemo), a mini shell for esp32-s3. It seemed nice and reusable, so I release it as a standalone component with minimal dependencies, for people who need a similar BT keyboard driver, but do not need full BreezyBox shell.

## Features

- Character push mode via bt_keyboard_set_char_callback()
- Game-friendly polling mode via bt_keyboard_is_pressed()
- Good performance proven in BreezyBox demo and Celeste port

## Known issues

- Requires reboot after pairing

## Installation

See [sdkconfig.defaults](sdkconfig.defaults) for features to enable in your firmware.

### ESP Component Registry (Recommended)

```bash
idf.py add-dependency "valdanylchuk/breezy_bt"
```

### Manual Installation

Clone into your project's `components` folder:

```bash
cd your_project/components
git clone https://github.com/valdanylchuk/breezy_bt.git
```

## Quick Start

### A. Using character-based callback

This is the simple, convenient mode suitable for most terminal apps.

```c
#include "nvs_flash.h"
#include "bt_keyboard.h"

// Character callback - inject into your input system
static void bt_char_callback(char c)
{
    // Feed to stdin, vterm, or your console system
    putchar(c);
    fflush(stdout);
}

void app_main(void)
{
    // 1. Initialize NVS (required for BT bond storage)
    esp_err_t err = nvs_flash_init();
    if (err == ESP_ERR_NVS_NO_FREE_PAGES || err == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        nvs_flash_erase();
        nvs_flash_init();
    }

    // 2. Set up BT keyboard
    bt_keyboard_set_char_callback(bt_char_callback);
    bt_keyboard_init();
    bt_keyboard_scan();  // Start scanning for keyboards

    // Your app continues here...
}
```

My BreezyBox demo uses this mode to read keyboard input transparently from a BT keyboard, USB console, or both.

### B. Using polling mode

This is the mode suitable for games, where you are interested in press/release detection and multi-key combos.

```c
#include "nvs_flash.h"
#include "bt_keyboard.h"

void app_main(void)
{
    // 1. Initialize NVS (required for BT bond storage)
    esp_err_t err = nvs_flash_init();
    if (err == ESP_ERR_NVS_NO_FREE_PAGES || err == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        nvs_flash_erase();
        nvs_flash_init();
    }

    // 2. Initialize BT keyboard (no callback needed for polling)
    bt_keyboard_init();
    bt_keyboard_scan();

    // 3. Poll keys in your game loop
    while (1) {
        // Check individual keys (returns 1 if pressed, 0 if not)
        if (bt_keyboard_is_pressed(BT_KEY_LEFT))   { /* move left */ }
        if (bt_keyboard_is_pressed(BT_KEY_RIGHT))  { /* move right */ }
        if (bt_keyboard_is_pressed(BT_KEY_UP))     { /* jump */ }
        if (bt_keyboard_is_pressed(BT_KEY_Z))      { /* action */ }

        // Check modifiers (returns bitmask)
        uint8_t mods = bt_keyboard_get_modifiers();
        if (mods & BT_MOD_SHIFT) { /* shift pressed */ }

        vTaskDelay(pdMS_TO_TICKS(10));  // Your frame timing
    }
}
```

## Extended fully working example/demo

[My BreezyBox-based hobby cyberdeck project](https://github.com/valdanylchuk/breezydemo).

Includes integration with a vterm, stdio routing, and a demo video.

See also some [BreezyBox compatible ELF apps here](https://github.com/valdanylchuk/breezyapps).

## Dependencies

- ESP-IDF >= 5.0
- Standard modules: bt, esp_hid, nvs_flash

## License

This is free software under MIT License - see [LICENSE](LICENSE) file.
