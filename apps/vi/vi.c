/*
 * vi - Minimal vi clone for ESP32-DOS and POSIX
 *
 * Supports: arrow keys, i (insert), ESC (normal), :w, :q, :q!, :wq
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>

/* ========== Configuration ========== */
#define MAX_LINES       4096
#define MAX_LINE_LEN    1024
#define CMD_BUF_SIZE    64
#define ESC_BUF_SIZE    8

/* ========== ANSI Escape Codes ========== */
#define ESC_CLEAR       "\033[2J"
#define ESC_HOME        "\033[H"
#define ESC_CURSOR_HIDE "\033[?25l"
#define ESC_CURSOR_SHOW "\033[?25h"
#define ESC_RESET       "\033[0m"
#define ESC_REVERSE     "\033[7m"
#define ESC_BOLD        "\033[1m"

/* ========== Platform Abstraction ========== */
#if defined(__XTENSA__) || defined(__riscv)
    /* ESP32-S3 / ESP32-P4 */
    void vterm_get_size(int *rows, int *cols);

    static int s_orig_fcntl;

    static void plat_init(void) {
        s_orig_fcntl = fcntl(STDIN_FILENO, F_GETFL, 0);
        fcntl(STDIN_FILENO, F_SETFL, s_orig_fcntl | O_NONBLOCK);
    }

    static void plat_cleanup(void) {
        fcntl(STDIN_FILENO, F_SETFL, s_orig_fcntl);
    }

    static void plat_get_size(int *rows, int *cols) {
        vterm_get_size(rows, cols);
    }

    static void plat_delay_ms(int ms) {
        extern void vTaskDelay(unsigned int);
        vTaskDelay(ms / 10);  /* portTICK_PERIOD_MS = 10 */
    }

#else
    /* POSIX / Mac */
    #include <sys/ioctl.h>
    #include <termios.h>

    static struct termios s_orig_termios;

    static void plat_init(void) {
        tcgetattr(STDIN_FILENO, &s_orig_termios);
        struct termios raw = s_orig_termios;
        raw.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
        raw.c_iflag &= ~(IXON | ICRNL | BRKINT | INPCK | ISTRIP);
        raw.c_cc[VMIN] = 0;
        raw.c_cc[VTIME] = 1;  /* 100ms timeout */
        tcsetattr(STDIN_FILENO, TCSANOW, &raw);
    }

    static void plat_cleanup(void) {
        tcsetattr(STDIN_FILENO, TCSANOW, &s_orig_termios);
    }

    static void plat_get_size(int *rows, int *cols) {
        struct winsize w;
        if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) == 0) {
            *rows = w.ws_row;
            *cols = w.ws_col;
        } else {
            *rows = 24;
            *cols = 80;
        }
    }

    static void plat_delay_ms(int ms) {
        usleep(ms * 1000);
    }
#endif

/* ========== Editor Modes ========== */
enum { MODE_NORMAL, MODE_INSERT, MODE_COMMAND };

/* ========== Special Keys ========== */
enum {
    KEY_NONE = 0,
    KEY_UP = 1000,
    KEY_DOWN,
    KEY_LEFT,
    KEY_RIGHT,
    KEY_HOME,
    KEY_END,
    KEY_DELETE,
    KEY_BACKSPACE,
    KEY_ENTER,
    KEY_ESC
};

/* ========== Editor State ========== */
static struct {
    char **lines;           /* Array of line strings */
    int line_count;         /* Number of lines */
    int lines_alloc;        /* Allocated slots */

    int cur_row;            /* Cursor row (0-based) */
    int cur_col;            /* Cursor col (0-based) */
    int top_line;           /* First visible line */
    int left_col;           /* First visible column (horizontal scroll) */

    int mode;               /* Current mode */
    int modified;           /* Dirty flag */
    int running;            /* Main loop flag */

    char filepath[256];     /* Current file path */
    char status[128];       /* Status line message */
    char cmd_buf[CMD_BUF_SIZE];  /* Command buffer for : mode */
    int cmd_len;            /* Command buffer length */

    int screen_rows;        /* Terminal rows */
    int screen_cols;        /* Terminal cols */
} E;

/* ========== Output Buffering ========== */
static char s_out_buf[8192];
static int s_out_pos = 0;

static void out_flush(void) {
    if (s_out_pos > 0) {
        write(STDOUT_FILENO, s_out_buf, s_out_pos);
        s_out_pos = 0;
    }
}

static void out_str(const char *s) {
    int len = strlen(s);
    if (s_out_pos + len >= (int)sizeof(s_out_buf)) out_flush();
    if (len < (int)sizeof(s_out_buf)) {
        memcpy(&s_out_buf[s_out_pos], s, len);
        s_out_pos += len;
    } else {
        out_flush();
        write(STDOUT_FILENO, s, len);
    }
}

static void out_char(char c) {
    if (s_out_pos >= (int)sizeof(s_out_buf) - 1) out_flush();
    s_out_buf[s_out_pos++] = c;
}

static void out_int(int n) {
    char buf[16];
    snprintf(buf, sizeof(buf), "%d", n);
    out_str(buf);
}

static void out_goto(int row, int col) {
    out_str("\033[");
    out_int(row + 1);
    out_char(';');
    out_int(col + 1);
    out_char('H');
}

/* ========== Line Management ========== */
static char *line_dup(const char *s) {
    if (!s) s = "";
    size_t len = strlen(s);
    char *p = malloc(len + 1);
    if (p) memcpy(p, s, len + 1);
    return p;
}

static void ensure_lines_capacity(int needed) {
    if (needed <= E.lines_alloc) return;
    int new_alloc = E.lines_alloc ? E.lines_alloc * 2 : 64;
    while (new_alloc < needed) new_alloc *= 2;
    E.lines = realloc(E.lines, new_alloc * sizeof(char *));
    E.lines_alloc = new_alloc;
}

static void insert_line_at(int idx, const char *text) {
    ensure_lines_capacity(E.line_count + 1);
    for (int i = E.line_count; i > idx; i--) {
        E.lines[i] = E.lines[i - 1];
    }
    E.lines[idx] = line_dup(text);
    E.line_count++;
}

static void delete_line_at(int idx) {
    if (idx < 0 || idx >= E.line_count) return;
    free(E.lines[idx]);
    for (int i = idx; i < E.line_count - 1; i++) {
        E.lines[i] = E.lines[i + 1];
    }
    E.line_count--;
    if (E.line_count == 0) {
        insert_line_at(0, "");
    }
}

static void free_all_lines(void) {
    for (int i = 0; i < E.line_count; i++) {
        free(E.lines[i]);
    }
    free(E.lines);
    E.lines = NULL;
    E.line_count = 0;
    E.lines_alloc = 0;
}

/* ========== File I/O ========== */
static int load_file(const char *path) {
    FILE *f = fopen(path, "r");
    if (!f) {
        /* New file - start with empty line */
        insert_line_at(0, "");
        snprintf(E.status, sizeof(E.status), "[New File]");
        return 1;
    }

    char line[MAX_LINE_LEN];
    while (fgets(line, sizeof(line), f)) {
        /* Strip trailing newline/CR */
        size_t len = strlen(line);
        while (len > 0 && (line[len - 1] == '\n' || line[len - 1] == '\r')) {
            line[--len] = '\0';
        }
        insert_line_at(E.line_count, line);
    }
    fclose(f);

    if (E.line_count == 0) {
        insert_line_at(0, "");
    }

    snprintf(E.status, sizeof(E.status), "\"%s\" %d lines", path, E.line_count);
    return 1;
}

static int save_file(const char *path) {
    if (!path || !path[0]) path = E.filepath;
    if (!path || !path[0]) {
        snprintf(E.status, sizeof(E.status), "No filename");
        return 0;
    }

    FILE *f = fopen(path, "w");
    if (!f) {
        snprintf(E.status, sizeof(E.status), "Cannot write: %s", path);
        return 0;
    }

    for (int i = 0; i < E.line_count; i++) {
        fprintf(f, "%s\n", E.lines[i]);
    }
    fclose(f);

    E.modified = 0;
    if (path != E.filepath) {
        strncpy(E.filepath, path, sizeof(E.filepath) - 1);
    }
    snprintf(E.status, sizeof(E.status), "\"%s\" %d lines written", E.filepath, E.line_count);
    return 1;
}

/* ========== Input Handling ========== */
static int read_key(void) {
    static char esc_buf[ESC_BUF_SIZE];
    static int esc_len = 0;

    char c;
    int n = read(STDIN_FILENO, &c, 1);
    if (n <= 0) return KEY_NONE;

    /* Handle escape sequences */
    if (esc_len > 0 || c == 27) {
        esc_buf[esc_len++] = c;

        /* Try to match complete sequences */
        if (esc_len >= 3) {
            if (memcmp(esc_buf, "\033[A", 3) == 0) { esc_len = 0; return KEY_UP; }
            if (memcmp(esc_buf, "\033[B", 3) == 0) { esc_len = 0; return KEY_DOWN; }
            if (memcmp(esc_buf, "\033[C", 3) == 0) { esc_len = 0; return KEY_RIGHT; }
            if (memcmp(esc_buf, "\033[D", 3) == 0) { esc_len = 0; return KEY_LEFT; }
            if (memcmp(esc_buf, "\033[H", 3) == 0) { esc_len = 0; return KEY_HOME; }
            if (memcmp(esc_buf, "\033[F", 3) == 0) { esc_len = 0; return KEY_END; }
            if (memcmp(esc_buf, "\033OH", 3) == 0) { esc_len = 0; return KEY_HOME; }
            if (memcmp(esc_buf, "\033OF", 3) == 0) { esc_len = 0; return KEY_END; }
        }
        if (esc_len >= 4) {
            if (memcmp(esc_buf, "\033[3~", 4) == 0) { esc_len = 0; return KEY_DELETE; }
            if (memcmp(esc_buf, "\033[1~", 4) == 0) { esc_len = 0; return KEY_HOME; }
            if (memcmp(esc_buf, "\033[4~", 4) == 0) { esc_len = 0; return KEY_END; }
        }

        /* Plain ESC (no more bytes coming) */
        if (esc_len == 1) {
            /* Check for more input */
            char c2;
            int n2 = read(STDIN_FILENO, &c2, 1);
            if (n2 <= 0) {
                esc_len = 0;
                return KEY_ESC;
            }
            esc_buf[esc_len++] = c2;
        }

        /* Partial sequence or unknown - keep waiting or reset */
        if (esc_len >= ESC_BUF_SIZE - 1) {
            esc_len = 0;  /* Buffer overflow, reset */
        }
        return KEY_NONE;
    }

    /* Regular keys */
    if (c == 127 || c == 8) return KEY_BACKSPACE;
    if (c == '\r' || c == '\n') return KEY_ENTER;
    if (c >= 32 && c < 127) return c;

    return KEY_NONE;
}

/* ========== Cursor Movement ========== */
static int line_len(int row) {
    if (row < 0 || row >= E.line_count) return 0;
    return strlen(E.lines[row]);
}

static void clamp_cursor(void) {
    if (E.cur_row < 0) E.cur_row = 0;
    if (E.cur_row >= E.line_count) E.cur_row = E.line_count - 1;
    if (E.cur_row < 0) E.cur_row = 0;

    int len = line_len(E.cur_row);
    if (E.mode == MODE_INSERT) {
        /* In insert mode, can be at end of line */
        if (E.cur_col > len) E.cur_col = len;
    } else {
        /* In normal mode, can't be past last char */
        if (len == 0) {
            E.cur_col = 0;
        } else if (E.cur_col >= len) {
            E.cur_col = len - 1;
        }
    }
    if (E.cur_col < 0) E.cur_col = 0;
}

static void move_up(void) {
    if (E.cur_row > 0) E.cur_row--;
    clamp_cursor();
}

static void move_down(void) {
    if (E.cur_row < E.line_count - 1) E.cur_row++;
    clamp_cursor();
}

static void move_left(void) {
    if (E.cur_col > 0) E.cur_col--;
    clamp_cursor();
}

static void move_right(void) {
    E.cur_col++;
    clamp_cursor();
}

/* ========== Text Editing ========== */
static void insert_char(char c) {
    char *line = E.lines[E.cur_row];
    int len = strlen(line);

    char *new_line = malloc(len + 2);
    memcpy(new_line, line, E.cur_col);
    new_line[E.cur_col] = c;
    memcpy(new_line + E.cur_col + 1, line + E.cur_col, len - E.cur_col + 1);

    free(E.lines[E.cur_row]);
    E.lines[E.cur_row] = new_line;
    E.cur_col++;
    E.modified = 1;
}

static void delete_char_at(int col) {
    char *line = E.lines[E.cur_row];
    int len = strlen(line);
    if (col < 0 || col >= len) return;

    memmove(line + col, line + col + 1, len - col);
    E.modified = 1;
}

static void backspace_char(void) {
    if (E.cur_col > 0) {
        E.cur_col--;
        delete_char_at(E.cur_col);
    } else if (E.cur_row > 0) {
        /* Join with previous line */
        int prev_len = line_len(E.cur_row - 1);
        char *prev = E.lines[E.cur_row - 1];
        char *curr = E.lines[E.cur_row];

        char *new_line = malloc(prev_len + strlen(curr) + 1);
        strcpy(new_line, prev);
        strcat(new_line, curr);

        free(E.lines[E.cur_row - 1]);
        E.lines[E.cur_row - 1] = new_line;

        delete_line_at(E.cur_row);
        E.cur_row--;
        E.cur_col = prev_len;
        E.modified = 1;
    }
}

static void insert_newline(void) {
    char *line = E.lines[E.cur_row];
    char *rest = line_dup(line + E.cur_col);

    line[E.cur_col] = '\0';
    insert_line_at(E.cur_row + 1, rest);
    free(rest);

    E.cur_row++;
    E.cur_col = 0;
    E.modified = 1;
}

/* ========== Screen Rendering ========== */
static void adjust_viewport(void) {
    int text_rows = E.screen_rows - 1;  /* Reserve 1 for status */
    int text_cols = E.screen_cols;

    /* Vertical scroll */
    if (E.cur_row < E.top_line) {
        E.top_line = E.cur_row;
    }
    if (E.cur_row >= E.top_line + text_rows) {
        E.top_line = E.cur_row - text_rows + 1;
    }

    /* Horizontal scroll */
    if (E.cur_col < E.left_col) {
        E.left_col = E.cur_col;
    }
    if (E.cur_col >= E.left_col + text_cols) {
        E.left_col = E.cur_col - text_cols + 1;
    }
}

static void draw_screen(void) {
    int text_rows = E.screen_rows - 1;
    int text_cols = E.screen_cols;

    adjust_viewport();

    out_str(ESC_HOME);
    out_str(ESC_CURSOR_HIDE);

    /* Draw text lines */
    for (int y = 0; y < text_rows; y++) {
        int file_row = E.top_line + y;

        out_goto(y, 0);

        if (file_row < E.line_count) {
            const char *line = E.lines[file_row];
            int len = strlen(line);

            /* Draw visible portion of line */
            int start = E.left_col;
            if (start < len) {
                int chars = len - start;
                if (chars > text_cols) chars = text_cols;
                for (int i = 0; i < chars; i++) {
                    out_char(line[start + i]);
                }
                /* Clear rest of line */
                for (int i = chars; i < text_cols; i++) {
                    out_char(' ');
                }
            } else {
                /* Line shorter than scroll offset */
                for (int i = 0; i < text_cols; i++) {
                    out_char(' ');
                }
            }
        } else {
            /* Empty row - show tilde like vi */
            out_char('~');
            for (int i = 1; i < text_cols; i++) {
                out_char(' ');
            }
        }
    }

    /* Draw status line */
    out_goto(E.screen_rows - 1, 0);
    out_str(ESC_REVERSE);

    char status_left[128];
    char status_right[64];

    /* Left side: mode + filename + modified */
    const char *mode_str;
    switch (E.mode) {
        case MODE_INSERT:  mode_str = "-- INSERT --"; break;
        case MODE_COMMAND: mode_str = ":"; break;
        default:           mode_str = ""; break;
    }

    if (E.mode == MODE_COMMAND) {
        snprintf(status_left, sizeof(status_left), ":%s", E.cmd_buf);
    } else if (E.status[0]) {
        snprintf(status_left, sizeof(status_left), "%s", E.status);
    } else {
        snprintf(status_left, sizeof(status_left), "%s %s%s",
                 mode_str,
                 E.filepath[0] ? E.filepath : "[No Name]",
                 E.modified ? " [+]" : "");
    }

    /* Right side: line/col */
    snprintf(status_right, sizeof(status_right), "%d,%d",
             E.cur_row + 1, E.cur_col + 1);

    int left_len = strlen(status_left);
    int right_len = strlen(status_right);
    /* Use screen_cols - 1 to avoid writing the very last character,
     * which would trigger vterm auto-scroll on ESP32 */
    int status_width = E.screen_cols - 1;
    int padding = status_width - left_len - right_len;
    if (padding < 0) padding = 0;

    /* Output exactly status_width characters */
    int pos = 0;
    for (int i = 0; i < left_len && pos < status_width; i++, pos++) {
        out_char(status_left[i]);
    }
    for (int i = 0; i < padding && pos < status_width; i++, pos++) {
        out_char(' ');
    }
    for (int i = 0; i < right_len && pos < status_width; i++, pos++) {
        out_char(status_right[i]);
    }

    out_str(ESC_RESET);

    /* Position cursor */
    int screen_row = E.cur_row - E.top_line;
    int screen_col = E.cur_col - E.left_col;
    out_goto(screen_row, screen_col);
    out_str(ESC_CURSOR_SHOW);

    out_flush();
}

/* ========== Mode Handlers ========== */
static void handle_normal(int key) {
    E.status[0] = '\0';  /* Clear status on keypress */

    switch (key) {
        case 'h':
        case KEY_LEFT:
            move_left();
            break;
        case 'j':
        case KEY_DOWN:
            move_down();
            break;
        case 'k':
        case KEY_UP:
            move_up();
            break;
        case 'l':
        case KEY_RIGHT:
            move_right();
            break;
        case '0':
        case KEY_HOME:
            E.cur_col = 0;
            break;
        case '$':
        case KEY_END:
            E.cur_col = line_len(E.cur_row);
            clamp_cursor();
            break;
        case 'i':
            E.mode = MODE_INSERT;
            break;
        case 'a':
            /* Append after cursor */
            E.cur_col++;
            clamp_cursor();
            E.mode = MODE_INSERT;
            break;
        case 'A':
            /* Append at end of line */
            E.cur_col = line_len(E.cur_row);
            E.mode = MODE_INSERT;
            break;
        case 'o':
            /* Open line below */
            insert_line_at(E.cur_row + 1, "");
            E.cur_row++;
            E.cur_col = 0;
            E.mode = MODE_INSERT;
            E.modified = 1;
            break;
        case 'O':
            /* Open line above */
            insert_line_at(E.cur_row, "");
            E.cur_col = 0;
            E.mode = MODE_INSERT;
            E.modified = 1;
            break;
        case 'x':
            /* Delete char at cursor */
            if (line_len(E.cur_row) > 0) {
                delete_char_at(E.cur_col);
                clamp_cursor();
            }
            break;
        case 'd':
            /* dd - delete line (simple: just 'd' deletes line) */
            delete_line_at(E.cur_row);
            clamp_cursor();
            break;
        case ':':
            E.mode = MODE_COMMAND;
            E.cmd_buf[0] = '\0';
            E.cmd_len = 0;
            break;
        case 'G':
            /* Go to last line */
            E.cur_row = E.line_count - 1;
            clamp_cursor();
            break;
        case 'g':
            /* gg - go to first line (simple: just 'g') */
            E.cur_row = 0;
            E.cur_col = 0;
            break;
    }
}

static void handle_insert(int key) {
    switch (key) {
        case KEY_ESC:
            E.mode = MODE_NORMAL;
            if (E.cur_col > 0) E.cur_col--;  /* vi behavior */
            clamp_cursor();
            break;
        case KEY_UP:
            move_up();
            break;
        case KEY_DOWN:
            move_down();
            break;
        case KEY_LEFT:
            move_left();
            break;
        case KEY_RIGHT:
            move_right();
            break;
        case KEY_BACKSPACE:
            backspace_char();
            break;
        case KEY_DELETE:
            delete_char_at(E.cur_col);
            break;
        case KEY_ENTER:
            insert_newline();
            break;
        case KEY_HOME:
            E.cur_col = 0;
            break;
        case KEY_END:
            E.cur_col = line_len(E.cur_row);
            break;
        default:
            if (key >= 32 && key < 127) {
                insert_char((char)key);
            }
            break;
    }
}

static void exec_command(void) {
    char *cmd = E.cmd_buf;

    /* Skip leading spaces */
    while (*cmd == ' ') cmd++;

    if (strcmp(cmd, "q") == 0) {
        if (E.modified) {
            snprintf(E.status, sizeof(E.status),
                     "No write since last change (add ! to override)");
        } else {
            E.running = 0;
        }
    } else if (strcmp(cmd, "q!") == 0) {
        E.running = 0;
    } else if (strcmp(cmd, "w") == 0) {
        save_file(NULL);
    } else if (strncmp(cmd, "w ", 2) == 0) {
        save_file(cmd + 2);
    } else if (strcmp(cmd, "wq") == 0 || strcmp(cmd, "x") == 0) {
        if (save_file(NULL)) {
            E.running = 0;
        }
    } else if (cmd[0] != '\0') {
        snprintf(E.status, sizeof(E.status), "Unknown command: %s", cmd);
    }
}

static void handle_command(int key) {
    switch (key) {
        case KEY_ESC:
            E.mode = MODE_NORMAL;
            E.status[0] = '\0';
            break;
        case KEY_ENTER:
            exec_command();
            E.mode = MODE_NORMAL;
            break;
        case KEY_BACKSPACE:
            if (E.cmd_len > 0) {
                E.cmd_buf[--E.cmd_len] = '\0';
            } else {
                E.mode = MODE_NORMAL;
            }
            break;
        default:
            if (key >= 32 && key < 127 && E.cmd_len < CMD_BUF_SIZE - 1) {
                E.cmd_buf[E.cmd_len++] = (char)key;
                E.cmd_buf[E.cmd_len] = '\0';
            }
            break;
    }
}

/* ========== Main ========== */
int main(int argc, char **argv) {
    /* Initialize editor state */
    memset(&E, 0, sizeof(E));
    E.running = 1;
    E.mode = MODE_NORMAL;

    /* Platform init */
    plat_init();
    plat_get_size(&E.screen_rows, &E.screen_cols);

    /* Load file or create empty buffer */
    if (argc >= 2) {
        strncpy(E.filepath, argv[1], sizeof(E.filepath) - 1);
        load_file(argv[1]);
    } else {
        insert_line_at(0, "");
        snprintf(E.status, sizeof(E.status), "[No Name]");
    }

    /* Clear screen */
    out_str(ESC_CLEAR);
    out_str(ESC_HOME);
    out_flush();

    /* Main loop */
    draw_screen();
    while (E.running) {
        int key = read_key();
        if (key == KEY_NONE) {
            plat_delay_ms(10);
            continue;
        }

        switch (E.mode) {
            case MODE_NORMAL:
                handle_normal(key);
                break;
            case MODE_INSERT:
                handle_insert(key);
                break;
            case MODE_COMMAND:
                handle_command(key);
                break;
        }

        draw_screen();
    }

    /* Cleanup */
    out_str(ESC_CLEAR);
    out_str(ESC_HOME);
    out_str(ESC_CURSOR_SHOW);
    out_str(ESC_RESET);
    out_flush();

    free_all_lines();
    plat_cleanup();

    return 0;
}
