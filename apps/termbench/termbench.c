/*
* VTerm Benchmark Suite v3.1
* Portable: POSIX & ESP32-S3
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdint.h>
#include <fcntl.h>
#include <errno.h>

/* ========================================================================= */
/* PLATFORM SHIM                                                             */
/* ========================================================================= */

#ifdef __XTENSA__
    #include <unistd.h>
    #include "esp_timer.h"
    #define portTICK_PERIOD_MS 1
    void vTaskDelay(int ticks);
    void vterm_get_size(int *rows, int *cols);

    static uint64_t get_time_us(void) { return (uint64_t)esp_timer_get_time(); }
    static void plat_write(const char *d, int l) { write(STDOUT_FILENO, d, l); }
    static void plat_sleep_us(uint32_t us) {
        int ticks = (us) / 1000 / portTICK_PERIOD_MS;
        if (ticks == 0 && us > 1000) ticks = 1;
        vTaskDelay(ticks);
    }
    static void plat_get_size(int *c, int *r) { vterm_get_size(r, c); }
#else
    #include <time.h>
    #include <unistd.h>
    #include <sys/ioctl.h> // Standard POSIX window size

    static uint64_t get_time_us(void) {
        struct timespec ts;
        clock_gettime(CLOCK_MONOTONIC, &ts);
        return (uint64_t)ts.tv_sec * 1000000ULL + ts.tv_nsec / 1000;
    }
    static void plat_write(const char *d, int l) { fwrite(d, 1, l, stdout); }
    static void plat_sleep_us(uint32_t us) { usleep(us); }
    static void plat_get_size(int *c, int *r) {
        struct winsize w;
        if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) == 0) { *c = w.ws_col; *r = w.ws_row; }
    }
#endif

/* ========================================================================= */
/* CONFIG & MACROS                                                           */
/* ========================================================================= */

#define OUT_BUF_SIZE      4096
#define MAX_TESTS         10
#define FRAME_PACE_US     16667 // ~60fps target for paced tests

#define CSI               "\033["
#define RESET             CSI "0m"
#define CLS               CSI "2J" CSI "H"
#define HOME              CSI "H"
#define EL                CSI "K"  // Erase Line

/* ========================================================================= */
/* ENGINE & HELPERS                                                          */
/* ========================================================================= */

static char g_outbuf[OUT_BUF_SIZE];
static int  g_outpos = 0;
static int  g_log_fd = -1;
static int  g_rows = 24, g_cols = 80;
static int  g_duration = 1;
static int  g_verbose = 1;

static void flush_out(void) {
    if (g_outpos > 0) { plat_write(g_outbuf, g_outpos); g_outpos = 0; }
}

static void emit(const char *data, int len) {
    while (len > 0) {
        int space = OUT_BUF_SIZE - g_outpos;
        int chunk = (len < space) ? len : space;
        memcpy(g_outbuf + g_outpos, data, chunk);
        g_outpos += chunk;
        len -= chunk; data += chunk;
        if (g_outpos >= OUT_BUF_SIZE) flush_out();
    }
}

static void emit_str(const char *s) { emit(s, strlen(s)); }

static void emit_fmt(const char *fmt, ...) {
    static char buf[256];
    va_list ap;
    va_start(ap, fmt);
    int n = vsnprintf(buf, sizeof(buf), fmt, ap);
    va_end(ap);
    if (n > 0) emit(buf, (n < sizeof(buf)) ? n : sizeof(buf) - 1);
}

static void log_fmt(const char *fmt, ...) {
    if (g_log_fd < 0) return;
    static char buf[512];
    va_list ap;
    va_start(ap, fmt);
    int n = vsnprintf(buf, sizeof(buf), fmt, ap);
    va_end(ap);
    if (n > 0) write(g_log_fd, buf, n);
}

/* PRNG */
static uint32_t g_rand = 12345;
static int rand_range(int min, int max) {
    g_rand = g_rand * 1103515245 + 12345;
    return min + ((g_rand >> 16) & 0x7FFF) % (max - min + 1);
}

/* Benchmark State */
typedef struct { const char *name; double bps; uint64_t ops; } result_t;
static result_t g_results[MAX_TESTS];
static int g_res_count = 0;

typedef struct { uint64_t start_us; uint64_t bytes; uint64_t ops; } bench_ctx_t;

static void bench_start(bench_ctx_t *ctx) {
    flush_out();
    ctx->start_us = get_time_us();
    ctx->bytes = 0; ctx->ops = 0;
}

static void bench_finish(bench_ctx_t *ctx, const char *name) {
    flush_out();
    uint64_t now = get_time_us();
    uint64_t elapsed_us = now - ctx->start_us;
    
    // Calculate duration in seconds for BPS (which expects double)
    double dur = (double)elapsed_us / 1000000.0;

    if (g_res_count < MAX_TESTS) {
        result_t *r = &g_results[g_res_count++];
        r->name = name;
        
        // BPS: result_t.bps is double, so double math is fine here.
        r->bps = (dur > 0.000001) ? ctx->bytes / dur : 0;
        
        // OPS: result_t.ops is uint64_t.
        // FIX: Use integer math to calculate ops/sec to avoid __fixunsdfdi intrinsic.
        // (ops * 1000000) / elapsed_microseconds
        if (elapsed_us > 0) {
            r->ops = (ctx->ops * 1000000ULL) / elapsed_us;
        } else {
            r->ops = 0;
        }
    }
}

static int check_time(bench_ctx_t *ctx) {
    return (get_time_us() - ctx->start_us) < (g_duration * 1000000ULL);
}

/* ========================================================================= */
/* TESTS                                                                     */
/* ========================================================================= */

/* 1. Raw throughput: The Baseline. Determines max speed of pipeline. */
static void test_raw_flood(void) {
    bench_ctx_t ctx;
    uint64_t last_frame = get_time_us();
    static char line[512];
    int len = (g_cols < 510) ? g_cols : 510;
    for (int i=0; i<len; i++) line[i] = 'A' + (i % 26);
    
    emit_str(CLS);
    bench_start(&ctx);
    while (check_time(&ctx)) {
        for (int r = 0; r < g_rows; r++) {
            emit(line, len); emit("\n", 1);
            ctx.bytes += len + 1;
        }
        emit_str(HOME); ctx.bytes += 3;
        ctx.ops++; // 1 op = 1 full screen
        
        // Pace to avoid completely choking watchdog on ESP
        uint64_t now = get_time_us();
        if (now - last_frame < FRAME_PACE_US) plat_sleep_us(FRAME_PACE_US - (now - last_frame));
        last_frame = get_time_us();
    }
    bench_finish(&ctx, "Raw Flood");
}

/* 2. SGR: Parsers often choke on colors. Now with EL to fix artifacts. */
static void test_sgr_color(void) {
    bench_ctx_t ctx;
    const char *colors[] = { "31", "32", "33", "34", "36", "35", "37" };
    
    emit_str(CLS HOME);
    bench_start(&ctx);
    int ci = 0;
    while (check_time(&ctx)) {
        emit_str(EL); // Clear line to avoid garbage
        emit_fmt(CSI "%smColorTest" RESET, colors[ci]);
        ctx.bytes += 18; ctx.ops++;
        ci = (ci + 1) % 7;
        if ((ctx.ops % (g_cols/10)) == 0) emit("\r", 1);
    }
    bench_finish(&ctx, "SGR Parser");
}

/* 3. Scrolling: The heavyweight. Now visibly prints line numbers. */
static void test_scroll(void) {
    bench_ctx_t ctx;
    uint64_t last_frame = get_time_us();
    static char line[512];
    
    emit_str(CLS);
    bench_start(&ctx);
    int ln = 0;
    while (check_time(&ctx)) {
        // Burst 1 screen worth of lines then yield
        for (int i=0; i<g_rows; i++) {
            int n = snprintf(line, sizeof(line), "Line %d scrolling test...", ln++);
            emit(line, n); emit("\n", 1);
            ctx.bytes += n + 1; ctx.ops++;
        }
        flush_out(); // Force display update
        
        uint64_t now = get_time_us();
        if (now - last_frame < FRAME_PACE_US) plat_sleep_us(FRAME_PACE_US - (now - last_frame));
        last_frame = get_time_us();
    }
    bench_finish(&ctx, "Scroll (Text)");
}

/* 4. Fill Chars: Random access cursor addressing + chars. */
static void test_fill_chars(void) {
    bench_ctx_t ctx;
    g_rand = 42;
    emit_str(CLS);
    bench_start(&ctx);
    while (check_time(&ctx)) {
        int x = rand_range(1, g_cols - 10);
        int y = rand_range(1, g_rows - 5);
        int w = rand_range(5, 10);
        int h = rand_range(2, 5);
        
        char c = 'A' + rand_range(0, 25);
        for (int r = 0; r < h; r++) {
            emit_fmt(CSI "%d;%dH", y + r, x);
            for(int k=0; k<w; k++) emit(&c, 1);
            ctx.bytes += 7 + w;
        }
        ctx.ops++; // 1 op = 1 rect
    }
    bench_finish(&ctx, "Fill (Char)");
}

/* 5. Fill Color: Random access + SGR Parsing. */
static void test_fill_color(void) {
    bench_ctx_t ctx;
    g_rand = 42;
    const char *bgs[] = { "41", "42", "44", "40" };
    
    emit_str(CLS);
    bench_start(&ctx);
    while (check_time(&ctx)) {
        int x = rand_range(1, g_cols - 10);
        int y = rand_range(1, g_rows - 5);
        int w = rand_range(5, 10);
        int h = rand_range(2, 5);
        
        emit_fmt(CSI "%sm", bgs[rand_range(0, 3)]);
        for (int r = 0; r < h; r++) {
            emit_fmt(CSI "%d;%dH", y + r, x);
            for(int k=0; k<w; k++) emit(" ", 1);
            ctx.bytes += 7 + w;
        }
        emit_str(RESET);
        ctx.bytes += 9; ctx.ops++;
    }
    bench_finish(&ctx, "Fill (Color)");
}

/* 6. Sparse Random: The "Matrix" effect. High cursor cost, low byte count. */
static void test_sparse(void) {
    bench_ctx_t ctx;
    g_rand = 99;
    emit_str(CLS);
    bench_start(&ctx);
    while (check_time(&ctx)) {
        int x = rand_range(1, g_cols);
        int y = rand_range(1, g_rows);
        char c = 33 + rand_range(0, 90);
        emit_fmt(CSI "%d;%dH%c", y, x, c);
        ctx.bytes += 9; ctx.ops++;
    }
    bench_finish(&ctx, "Sparse Rand");
}

/* 7. Mixed Log: The most realistic use-case (UART logging). */
static void test_mixed_log(void) {
    bench_ctx_t ctx;
    const char *levels[] = { CSI "32mINF" RESET, CSI "33mWRN" RESET, CSI "31mERR" RESET };
    
    emit_str(CLS);
    bench_start(&ctx);
    while (check_time(&ctx)) {
        emit_fmt("[%04llu] %s System status check: 0x%08X\n", 
                ctx.ops % 1000, levels[rand_range(0,2)], rand_range(0, 0xFFFF));
        ctx.bytes += 45; ctx.ops++;
    }
    bench_finish(&ctx, "Mixed Log");
}

/* ========================================================================= */
/* MAIN                                                                      */
/* ========================================================================= */

typedef void (*test_fn)(void);
static struct { test_fn fn; const char *name; } g_tests[] = {
    { test_raw_flood,  "Raw Flood" },
    { test_sgr_color,  "SGR Parser" },
    { test_scroll,     "Scroll" },
    { test_fill_chars, "Fill Char" },
    { test_fill_color, "Fill Color" },
    { test_sparse,     "Sparse" },
    { test_mixed_log,  "Mixed Log" },
    { NULL, NULL }
};

int main(int argc, char **argv) {
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-q") == 0) g_verbose = 0;
        else if (strcmp(argv[i], "-d") == 0) g_duration = atoi(argv[++i]);
        else if (strcmp(argv[i], "-s") == 0) { g_cols = atoi(argv[++i]); g_rows = atoi(argv[++i]); }
    }

    g_log_fd = open("termbench.log", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    plat_get_size(&g_cols, &g_rows);
    if (g_cols <= 0) { g_cols=80; g_rows=24; }

    if (g_verbose) fprintf(stderr, "TermBench v3.0 (%dx%d, %ds)\n", g_cols, g_rows, g_duration);

    emit_str(CSI "?25l"); // Hide cursor

    for (int i = 0; g_tests[i].fn; i++) {
        if (g_verbose) { fprintf(stderr, "\rTesting: %-15s", g_tests[i].name); fflush(stderr); }
        emit_str(RESET CLS);
        flush_out(); plat_sleep_us(100000); // Sync
        g_tests[i].fn();
    }

    emit_str(RESET CLS CSI "?25h"); // Show cursor
    flush_out();
    if (g_verbose) fprintf(stderr, "\rDone!                  \n");

    /* Report */
    log_fmt("==================================================\n");
    log_fmt("TERMBENCH v3.0 | %dx%d | %ds\n", g_cols, g_rows, g_duration);
    log_fmt("==================================================\n");
    for(int i=0; i<g_res_count; i++) {
        log_fmt("%-15s %8.1f KB/s %8llu ops/s\n", 
            g_results[i].name, g_results[i].bps/1024.0, g_results[i].ops);
    }
    if (g_log_fd >= 0) close(g_log_fd);

    return 0;
}