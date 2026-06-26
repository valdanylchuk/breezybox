// Plasma Effect - Portable: POSIX & ESP32-S3 BreezyBox
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>

#define TARGET_FPS   50
#define BUF_SIZE     256
#define CACHE_W      256

#ifdef __XTENSA__

    typedef uint32_t TickType_t;
    TickType_t xTaskGetTickCount(void);
    void vTaskDelayUntil(TickType_t *pxPreviousWakeTime, TickType_t xTimeIncrement);
    void vterm_get_size(int *rows, int *cols);
    void vterm_set_palette(const uint16_t *palette);
    void my_display_refresh_palette(void);
    const uint16_t *vterm_get_palette(void);

    #define portTICK_PERIOD_MS  10
    #define pdMS_TO_TICKS(ms)   ((ms) / portTICK_PERIOD_MS)

    static const uint16_t PLASMA_PALETTE[16] = {
        0x0000, 0xF800, 0xD000, 0xFC20, 0xFFE0, 0xFEA0, 0x07E0, 0x0560,
        0x057F, 0x02FF, 0x801F, 0x581F, 0xF81F, 0xD015, 0xFD75, 0xFEB5
    };

    static const char *s_color_map[16] = {
        "\033[31m", "\033[32m", "\033[33m", "\033[33m", "\033[34m", "\033[35m", "\033[36m", "\033[37m",
        "\033[90m", "\033[91m", "\033[92m", "\033[93m", "\033[94m", "\033[95m", "\033[96m", "\033[97m"
    };

    static uint16_t s_old_palette[16];
    static int s_orig_fcntl;
    static TickType_t s_last_wake;
    static TickType_t s_freq;

    static void plat_init(void) {
        memcpy(s_old_palette, vterm_get_palette(), sizeof(s_old_palette));
        vterm_set_palette(PLASMA_PALETTE);
        my_display_refresh_palette();

        s_orig_fcntl = fcntl(STDIN_FILENO, F_GETFL, 0);
        fcntl(STDIN_FILENO, F_SETFL, s_orig_fcntl | O_NONBLOCK);

        s_last_wake = xTaskGetTickCount();
        s_freq = pdMS_TO_TICKS(1000 / TARGET_FPS);
    }

    static void plat_cleanup(void) {
        vterm_set_palette(s_old_palette);
        my_display_refresh_palette();
        fcntl(STDIN_FILENO, F_SETFL, s_orig_fcntl);
    }

    static void plat_get_size(int *rows, int *cols) { vterm_get_size(rows, cols); }

    static void plat_sync_frame(void) { vTaskDelayUntil(&s_last_wake, s_freq); }

#else /* POSIX / Mac */
    #include <sys/ioctl.h>
    #include <termios.h>

    static struct termios s_orig_termios;

    static const char *s_color_map[16] = {
        "\033[38;5;196m", "\033[38;5;160m", "\033[38;5;208m", "\033[38;5;208m",
        "\033[38;5;226m", "\033[38;5;220m", "\033[38;5;46m",  "\033[38;5;34m",
        "\033[38;5;39m",  "\033[38;5;27m",  "\033[38;5;93m",  "\033[38;5;57m",
        "\033[38;5;201m", "\033[38;5;163m", "\033[38;5;217m", "\033[38;5;223m"
    };

    static void plat_get_size(int *rows, int *cols) {
        struct winsize w;
        if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) == 0) {
            *rows = w.ws_row; *cols = w.ws_col;
        } else {
            *rows = 24; *cols = 80;
        }
    }

    static void plat_init(void) {
        /* Enable Raw Mode (disable echo, line buffering, etc.) */
        tcgetattr(STDIN_FILENO, &s_orig_termios);
        struct termios raw = s_orig_termios;
        raw.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
        raw.c_cc[VMIN] = 0; raw.c_cc[VTIME] = 0;
        tcsetattr(STDIN_FILENO, TCSANOW, &raw);
    }

    static void plat_cleanup(void) {
        tcsetattr(STDIN_FILENO, TCSANOW, &s_orig_termios);
        printf("\033[?25h"); // show cursor
    }

    static void plat_sync_frame(void) { usleep(1000000 / TARGET_FPS); }

#endif // XTENSA / POSIX

static char s_out_buf[BUF_SIZE];
static int  s_buf_pos = 0;

static void flush_buf(void) {
    if (s_buf_pos > 0) {
        write(STDOUT_FILENO, s_out_buf, s_buf_pos);
        s_buf_pos = 0;
    }
}

static void push_str(const char *s) {
    int len = strlen(s);
    if (s_buf_pos + len >= BUF_SIZE) flush_buf();
    memcpy(&s_out_buf[s_buf_pos], s, len);
    s_buf_pos += len;
}

static void push_char(char c) {
    if (s_buf_pos >= BUF_SIZE - 1) flush_buf();
    s_out_buf[s_buf_pos++] = c;
}

static void push_color(int i) { push_str(s_color_map[i & 0x0F]); }

static int has_input_should_exit(void) {
    char c;
    return read(STDIN_FILENO, &c, 1) > 0;
}

#define SIN_SIZE   1024
#define SIN_MASK   (SIN_SIZE - 1)
#define RAD_TO_IDX 162.97466f

static const char CHARS[] = "ABCDEFGHIJKLMNOP";
static float s_sin_lut[SIN_SIZE];
static float s_cache_x_val[CACHE_W];
static float s_cache_x_sq[CACHE_W];

static inline float fast_sin(float rads) {
    return s_sin_lut[(int)(rads * RAD_TO_IDX) & SIN_MASK];
}

static void init_sin_lut(void) {
    for (int i = 0; i < SIN_SIZE; i++) {
        s_sin_lut[i] = sinf((float)i * (2.0f * 3.14159265f) / (float)SIN_SIZE);
    }
}

int main(int argc, char **argv) {
    int rows, cols;

    plat_init();
    init_sin_lut();
    plat_get_size(&rows, &cols);
    if (cols > CACHE_W) cols = CACHE_W;

    push_str("\033[?25l\033[2J"); flush_buf();

    srand(time(NULL));
    float r1 = (float)rand() / RAND_MAX * 10.0f;
    float r2 = (float)rand() / RAND_MAX * 10.0f;
    float r3 = (float)rand() / RAND_MAX * 10.0f;
    float t = 0.0f;

    while (!has_input_should_exit()) {
        push_str("\033[H");
        int last_color = -1;

        float cx_shift = fast_sin(t / 3.0f) * 20.0f;
        float phase_x = t + r1;
        float phase_z = t + r3;

        for (int x = 0; x < cols; x++) {
            s_cache_x_val[x] = fast_sin(x * 0.06f + phase_x);
            float cx = (x - cols / 2.0f) + cx_shift;
            s_cache_x_sq[x] = cx * cx;
        }

        float phase_y = t + r2;
        float cy_shift = cosf(t / 2.0f) * 10.0f;

        for (int y = 0; y < rows; y++) {
            float cy = (y - rows / 2.0f) * 2.0f + cy_shift;
            float cy_sq = cy * cy;
            float val_y = fast_sin(y * 0.12f + phase_y);

            for (int x = 0; x < cols; x++) {
                if (y == rows - 1 && x == cols - 1) break;

                float dist_sq = s_cache_x_sq[x] + cy_sq;
                float v = s_cache_x_val[x] + val_y + fast_sin(sqrtf(dist_sq) * 0.08f + phase_z);

                int i = ((int)((v + 10.0f) * 4.0f)) % 32;
                if (i < 0) i = 0;
                if (i > 15) i = 31 - i;

                if (i != last_color) {
                    push_color(i);
                    last_color = i;
                }
                push_char(CHARS[i]);
            }
        }

        flush_buf();
        t += 0.08f;
        plat_sync_frame();
    }

    plat_cleanup();

    /* Reset colors and clear */
    push_str("\033[0m\033[2J\033[H"); flush_buf();

    return 0;
}