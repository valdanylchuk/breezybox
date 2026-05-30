/*
 * bt_keyboard.h - BLE HID Keyboard Driver
 *
 * Self-contained BLE keyboard component using NimBLE + esp_hidh.
 * Provides two input paths:
 *
 * 1. Character callback: Translates HID keycodes to ASCII and delivers
 *    them via a registered callback. Ideal for shell/console/stdio use.
 *    Set with bt_keyboard_set_char_callback().
 *
 * 2. Polling API: bt_keyboard_is_pressed() / bt_keyboard_get_modifiers()
 *    return raw key state instantly. Ideal for games and realtime input
 *    where you need multi-key state without stdio's line buffering.
 */

#ifndef BT_KEYBOARD_H
#define BT_KEYBOARD_H

#include <stdint.h>
#include "esp_err.h"

/**
 * Callback type for receiving translated ASCII characters.
 * Called from the HID event context when a key is pressed.
 */
typedef void (*bt_keyboard_char_cb_t)(char c);

/**
 * Register a callback for translated key characters.
 * Call this before bt_keyboard_init() or at any time to change routing.
 * Pass NULL to disable character delivery.
 */
void bt_keyboard_set_char_callback(bt_keyboard_char_cb_t cb);

/**
 * Initialize the BLE keyboard subsystem.
 * Sets up NimBLE, esp_hidh, NVS bond storage, and auto-reconnect.
 */
esp_err_t bt_keyboard_init(void);

/**
 * Start scanning for BLE HID keyboards.
 */
esp_err_t bt_keyboard_scan(void);

/**
 * Start scanning with optional verbose output.
 */
esp_err_t bt_keyboard_scan_ex(int verbose);

/**
 * Check if a keyboard is connected.
 * @return 1 if connected, 0 otherwise
 */
int bt_keyboard_connected(void);

/**
 * Reconnect to the last known keyboard (scan-first, safe).
 */
esp_err_t bt_keyboard_connect_native(void);

/**
 * Clear all BLE bonds and saved keyboard address.
 */
esp_err_t bt_keyboard_clear_bonds(void);

/**
 * Dump internal BT keyboard state for debugging.
 */
void bt_keyboard_debug_dump(void);

/**
 * Check if encryption is established.
 * @return 1 if encrypted, 0 otherwise
 */
int bt_keyboard_encrypted(void);

/* ============ Polling / Game Input API ============
 *
 * These bypass stdio entirely. Poll raw HID key state directly.
 * Thread-safe (uses portENTER_CRITICAL internally).
 *
 * Usage pattern (e.g. celesp):
 *   void input_update(void) {
 *       if (bt_keyboard_is_pressed(BT_KEY_LEFT))  keys |= KEY_LEFT;
 *       if (bt_keyboard_is_pressed(BT_KEY_Z))     keys |= KEY_JUMP;
 *       ...
 *   }
 */

/**
 * Check if a specific HID keycode is currently pressed.
 * @param keycode HID usage code (use BT_KEY_* constants)
 * @return 1 if pressed, 0 if not
 */
int bt_keyboard_is_pressed(uint8_t keycode);

/**
 * Get current modifier key state.
 * @return Bitmask of BT_MOD_* flags
 */
uint8_t bt_keyboard_get_modifiers(void);

/* HID Keycodes (USB HID Usage Tables) */
#define BT_KEY_A        0x04
#define BT_KEY_B        0x05
#define BT_KEY_C        0x06
#define BT_KEY_D        0x07
#define BT_KEY_E        0x08
#define BT_KEY_F        0x09
#define BT_KEY_G        0x0A
#define BT_KEY_H        0x0B
#define BT_KEY_I        0x0C
#define BT_KEY_J        0x0D
#define BT_KEY_K        0x0E
#define BT_KEY_L        0x0F
#define BT_KEY_M        0x10
#define BT_KEY_N        0x11
#define BT_KEY_O        0x12
#define BT_KEY_P        0x13
#define BT_KEY_Q        0x14
#define BT_KEY_R        0x15
#define BT_KEY_S        0x16
#define BT_KEY_T        0x17
#define BT_KEY_U        0x18
#define BT_KEY_V        0x19
#define BT_KEY_W        0x1A
#define BT_KEY_X        0x1B
#define BT_KEY_Y        0x1C
#define BT_KEY_Z        0x1D

#define BT_KEY_1        0x1E
#define BT_KEY_2        0x1F
#define BT_KEY_3        0x20
#define BT_KEY_4        0x21
#define BT_KEY_5        0x22
#define BT_KEY_6        0x23
#define BT_KEY_7        0x24
#define BT_KEY_8        0x25
#define BT_KEY_9        0x26
#define BT_KEY_0        0x27

#define BT_KEY_ENTER    0x28
#define BT_KEY_ESC      0x29
#define BT_KEY_BACKSPACE 0x2A
#define BT_KEY_TAB      0x2B
#define BT_KEY_SPACE    0x2C

#define BT_KEY_RIGHT    0x4F
#define BT_KEY_LEFT     0x50
#define BT_KEY_DOWN     0x51
#define BT_KEY_UP       0x52

/* Modifier bitmask constants */
#define BT_MOD_LCTRL    0x01
#define BT_MOD_LSHIFT   0x02
#define BT_MOD_LALT     0x04
#define BT_MOD_LGUI     0x08
#define BT_MOD_RCTRL    0x10
#define BT_MOD_RSHIFT   0x20
#define BT_MOD_RALT     0x40
#define BT_MOD_RGUI     0x80

#define BT_MOD_CTRL     (BT_MOD_LCTRL | BT_MOD_RCTRL)
#define BT_MOD_SHIFT    (BT_MOD_LSHIFT | BT_MOD_RSHIFT)
#define BT_MOD_ALT      (BT_MOD_LALT | BT_MOD_RALT)

#endif // BT_KEYBOARD_H
