/*
 * tanmatsu_keyboard.c - Bridge the Tanmatsu built-in keyboard to its two
 * consumers in this firmware.
 *
 * badge-bsp delivers input as a queue of bsp_input_event_t and also exposes a
 * live, pollable snapshot of the key matrix. We use both:
 *
 *  1. Shell / console (a FreeRTOS task draining the queue into vterm):
 *       - KEYBOARD (ascii) events -> printable text, plus Ctrl-<letter> folded
 *         into the matching control code (Ctrl-C = 0x03, Ctrl-D = 0x04, ...).
 *         The BSP reports the plain letter in `ascii` and Ctrl only in
 *         `modifiers`, so we fold it here.
 *       - NAVIGATION events -> Enter, Backspace, Tab, Esc, and the arrow
 *         escape sequences.
 *     vterm_input_feed() also recognizes its own VT-switch hotkey sequences, so
 *     those keep working too.
 *
 *  2. Games (e.g. ccleste): a polling shim that re-implements the BreezyBox
 *     bt_keyboard_*() game-input API on top of the BSP's bsp_input_read_scancode().
 *     Games poll "is this key held right now"; the BSP tracks both press and
 *     release across the whole matrix, so this gives real held-key state with
 *     no Bluetooth involved. We keep the bt_keyboard_*() symbol names so that
 *     unmodified games (which link against them) load unchanged.
 *
 * MVP scope for the shell path: basic typing + line editing + Ctrl combos.
 * Modifier layers beyond Ctrl, function keys and special Tanmatsu keys are
 * intentionally not mapped yet.
 */

#include "tanmatsu_keyboard.h"
#include "vterm.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "esp_log.h"

#include "bsp/input.h"

static const char *TAG = "kbd";

/* ===================== Shell / console path ===================== */

static void feed_seq(const char *s)
{
    while (*s) vterm_input_feed(*s++);
}

static void handle_keyboard(const bsp_input_event_args_keyboard_t *k)
{
    char a = k->ascii;
    if (a == 0) return;
    if (k->modifiers & BSP_INPUT_MODIFIER_CTRL) {
        /* Ctrl+<letter> -> control code. Other Ctrl combos are ignored. */
        char upper = a & ~0x20;
        if (upper >= 'A' && upper <= 'Z') vterm_input_feed(a & 0x1f);
        return;
    }
    /* Enter/Backspace/Tab/Esc arrive via NAVIGATION, not here, so the ascii
     * stream is just printable text. */
    if (a >= 0x20 && a < 0x7f) vterm_input_feed(a);
}

static void handle_navigation(const bsp_input_event_args_navigation_t *n)
{
    if (!n->state) return;  /* key-down only */
    switch (n->key) {
        case BSP_INPUT_NAVIGATION_KEY_RETURN:    vterm_input_feed('\r');   break;
        case BSP_INPUT_NAVIGATION_KEY_BACKSPACE: vterm_input_feed(0x7f);   break;
        case BSP_INPUT_NAVIGATION_KEY_TAB:       vterm_input_feed('\t');   break;
        case BSP_INPUT_NAVIGATION_KEY_ESC:       vterm_input_feed(0x1b);   break;
        case BSP_INPUT_NAVIGATION_KEY_UP:        feed_seq("\x1b[A");       break;
        case BSP_INPUT_NAVIGATION_KEY_DOWN:      feed_seq("\x1b[B");       break;
        case BSP_INPUT_NAVIGATION_KEY_RIGHT:     feed_seq("\x1b[C");       break;
        case BSP_INPUT_NAVIGATION_KEY_LEFT:      feed_seq("\x1b[D");       break;
        default: break;
    }
}

static void kbd_task(void *arg)
{
    (void)arg;
    QueueHandle_t q = NULL;
    if (bsp_input_get_queue(&q) != ESP_OK || q == NULL) {
        ESP_LOGE(TAG, "bsp_input_get_queue failed; keyboard disabled");
        vTaskDelete(NULL);
        return;
    }

    bsp_input_event_t ev;
    for (;;) {
        if (xQueueReceive(q, &ev, portMAX_DELAY) != pdTRUE) continue;
        switch (ev.type) {
            case INPUT_EVENT_TYPE_KEYBOARD:   handle_keyboard(&ev.args_keyboard);     break;
            case INPUT_EVENT_TYPE_NAVIGATION: handle_navigation(&ev.args_navigation); break;
            default: break;
        }
    }
}

esp_err_t tanmatsu_keyboard_start(void)
{
    BaseType_t ok = xTaskCreate(kbd_task, "kbd", 4096, NULL, 5, NULL);
    return ok == pdPASS ? ESP_OK : ESP_FAIL;
}

/* ===================== Game polling shim (bt_keyboard_* API) ===================== */
/*
 * Games poll bt_keyboard_is_pressed(hid_usage_code). USB-HID usage codes are
 * alphabetical for letters and a different numbering from the BSP's set-1
 * scancodes, so we translate explicitly. Unmapped keys read as "not pressed".
 *
 * These symbols are exported to loadable ELF apps via breezy_p4_export_symbols()
 * in elf_extras.c -- after changing them, rebuild and regenerate the customer
 * symbol table (see Readme "ELF apps on P4").
 */

/* USB-HID modifier bitmask (matches BreezyBox bt_keyboard.h BT_MOD_*). */
#define BT_MOD_LCTRL  0x01
#define BT_MOD_LSHIFT 0x02
#define BT_MOD_LALT   0x04
#define BT_MOD_RSHIFT 0x20
#define BT_MOD_RALT   0x40

static bsp_input_scancode_t hid_to_scancode(uint8_t hid)
{
    switch (hid) {
        /* Letters: HID 0x04..0x1D (alphabetical) -> set-1 (positional). */
        case 0x04: return BSP_INPUT_SCANCODE_A;
        case 0x05: return BSP_INPUT_SCANCODE_B;
        case 0x06: return BSP_INPUT_SCANCODE_C;
        case 0x07: return BSP_INPUT_SCANCODE_D;
        case 0x08: return BSP_INPUT_SCANCODE_E;
        case 0x09: return BSP_INPUT_SCANCODE_F;
        case 0x0A: return BSP_INPUT_SCANCODE_G;
        case 0x0B: return BSP_INPUT_SCANCODE_H;
        case 0x0C: return BSP_INPUT_SCANCODE_I;
        case 0x0D: return BSP_INPUT_SCANCODE_J;
        case 0x0E: return BSP_INPUT_SCANCODE_K;
        case 0x0F: return BSP_INPUT_SCANCODE_L;
        case 0x10: return BSP_INPUT_SCANCODE_M;
        case 0x11: return BSP_INPUT_SCANCODE_N;
        case 0x12: return BSP_INPUT_SCANCODE_O;
        case 0x13: return BSP_INPUT_SCANCODE_P;
        case 0x14: return BSP_INPUT_SCANCODE_Q;
        case 0x15: return BSP_INPUT_SCANCODE_R;
        case 0x16: return BSP_INPUT_SCANCODE_S;
        case 0x17: return BSP_INPUT_SCANCODE_T;
        case 0x18: return BSP_INPUT_SCANCODE_U;
        case 0x19: return BSP_INPUT_SCANCODE_V;
        case 0x1A: return BSP_INPUT_SCANCODE_W;
        case 0x1B: return BSP_INPUT_SCANCODE_X;
        case 0x1C: return BSP_INPUT_SCANCODE_Y;
        case 0x1D: return BSP_INPUT_SCANCODE_Z;
        /* Digits: HID 0x1E..0x26 = 1..9, 0x27 = 0. */
        case 0x1E: return BSP_INPUT_SCANCODE_1;
        case 0x1F: return BSP_INPUT_SCANCODE_2;
        case 0x20: return BSP_INPUT_SCANCODE_3;
        case 0x21: return BSP_INPUT_SCANCODE_4;
        case 0x22: return BSP_INPUT_SCANCODE_5;
        case 0x23: return BSP_INPUT_SCANCODE_6;
        case 0x24: return BSP_INPUT_SCANCODE_7;
        case 0x25: return BSP_INPUT_SCANCODE_8;
        case 0x26: return BSP_INPUT_SCANCODE_9;
        case 0x27: return BSP_INPUT_SCANCODE_0;
        /* Editing / whitespace. */
        case 0x28: return BSP_INPUT_SCANCODE_ENTER;
        case 0x29: return BSP_INPUT_SCANCODE_ESC;
        case 0x2A: return BSP_INPUT_SCANCODE_BACKSPACE;
        case 0x2B: return BSP_INPUT_SCANCODE_TAB;
        case 0x2C: return BSP_INPUT_SCANCODE_SPACE;
        /* Arrows (the "grey" escaped scancodes). */
        case 0x4F: return BSP_INPUT_SCANCODE_ESCAPED_GREY_RIGHT;
        case 0x50: return BSP_INPUT_SCANCODE_ESCAPED_GREY_LEFT;
        case 0x51: return BSP_INPUT_SCANCODE_ESCAPED_GREY_DOWN;
        case 0x52: return BSP_INPUT_SCANCODE_ESCAPED_GREY_UP;
        default:   return BSP_INPUT_SCANCODE_NONE;
    }
}

int bt_keyboard_is_pressed(uint8_t keycode)
{
    bsp_input_scancode_t sc = hid_to_scancode(keycode);
    if (sc == BSP_INPUT_SCANCODE_NONE) return 0;
    bool state = false;
    return (bsp_input_read_scancode(sc, &state) == ESP_OK && state) ? 1 : 0;
}

uint8_t bt_keyboard_get_modifiers(void)
{
    uint8_t m = 0;
    bool s;
    if (bsp_input_read_scancode(BSP_INPUT_SCANCODE_LEFTSHIFT,  &s) == ESP_OK && s) m |= BT_MOD_LSHIFT;
    if (bsp_input_read_scancode(BSP_INPUT_SCANCODE_RIGHTSHIFT, &s) == ESP_OK && s) m |= BT_MOD_RSHIFT;
    if (bsp_input_read_scancode(BSP_INPUT_SCANCODE_LEFTCTRL,   &s) == ESP_OK && s) m |= BT_MOD_LCTRL;
    if (bsp_input_read_scancode(BSP_INPUT_SCANCODE_LEFTALT,    &s) == ESP_OK && s) m |= BT_MOD_LALT;
    if (bsp_input_read_scancode(BSP_INPUT_SCANCODE_ESCAPED_RALT, &s) == ESP_OK && s) m |= BT_MOD_RALT;
    return m;
}

/* The Tanmatsu keyboard is always physically present, so games that gate on a
 * connection (originally a BT pairing check) always see it as connected. */
int bt_keyboard_connected(void)
{
    return 1;
}
