/*
 * tanmatsu_keyboard.c - Bridge the Tanmatsu built-in keyboard to vterm.
 *
 * badge-bsp delivers input as a queue of bsp_input_event_t. We translate:
 *   - KEYBOARD events  -> printable ASCII (and Tab / Ctrl-C / Ctrl-D) fed raw
 *   - NAVIGATION events-> Enter, Backspace, Esc, and arrow escape sequences
 * and push the bytes into vterm_input_feed(), which the console VFS then
 * delivers to the BreezyBox shell. vterm_input_feed() also recognizes its own
 * VT-switch hotkey escape sequences, so those keep working too.
 *
 * MVP scope: basic typing + line editing. Modifier layers, function keys and
 * special Tanmatsu keys are intentionally not mapped yet.
 */

#include "tanmatsu_keyboard.h"
#include "vterm.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "esp_log.h"

#include "bsp/input.h"

static const char *TAG = "kbd";

static void feed_seq(const char *s)
{
    while (*s) vterm_input_feed(*s++);
}

static void handle_keyboard(const bsp_input_event_args_keyboard_t *k)
{
    char a = (char)k->ascii;
    if (a == 0) return;
    /* Printable, plus a few control codes that the shell relies on.
     * Enter/Backspace come via NAVIGATION, so we skip CR/LF/BS here to
     * avoid double input. */
    if ((a >= 0x20 && a < 0x7f) ||  /* printable */
        a == '\t' ||                /* Tab */
        a == 0x03 ||                /* Ctrl-C */
        a == 0x04) {                /* Ctrl-D */
        vterm_input_feed(a);
    }
}

static void handle_navigation(const bsp_input_event_args_navigation_t *n)
{
    if (!n->state) return;  /* key-down only */
    switch (n->key) {
        case BSP_INPUT_NAVIGATION_KEY_RETURN:    vterm_input_feed('\r');   break;
        case BSP_INPUT_NAVIGATION_KEY_BACKSPACE: vterm_input_feed(0x7f);   break;
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
