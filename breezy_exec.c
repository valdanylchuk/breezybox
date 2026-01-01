#include "breezy_exec.h"
#include "breezy_vfs.h"
#include "esp_console.h"
#include "esp_log.h"
#include "esp_elf.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

#define TEMP_PIPE_FILE BREEZYBOX_MOUNT_POINT "/.pipe_tmp"
#define TEMP_OUT_FILE  BREEZYBOX_MOUNT_POINT "/.out_tmp"

// PATH for executable search (colon-separated like Unix)
#define EXEC_PATH "/root/bin"

// ELF magic bytes
static const uint8_t ELF_MAGIC[4] = {0x7f, 'E', 'L', 'F'};

static const char *TAG = "exec";
static vprintf_like_t s_orig_vprintf = NULL;

// Custom log handler that suppresses logs during redirects
static int null_vprintf(const char *fmt, va_list args)
{
    return 0;
}

void breezybox_exec_init(void)
{
    s_orig_vprintf = esp_log_set_vprintf(vprintf);
    esp_log_set_vprintf(s_orig_vprintf);
}

// Check if file exists
static int file_exists(const char *path)
{
    struct stat st;
    return stat(path, &st) == 0 && S_ISREG(st.st_mode);
}

// Check if file has ELF magic
static int is_elf_file(const char *path)
{
    FILE *f = fopen(path, "rb");
    if (!f) return 0;
    
    uint8_t magic[4];
    size_t n = fread(magic, 1, 4, f);
    fclose(f);
    
    return (n == 4 && memcmp(magic, ELF_MAGIC, 4) == 0);
}

// Search for executable in PATH and CWD
// Returns allocated string with full path, or NULL if not found
static char *find_executable(const char *name)
{
    char path[BREEZYBOX_MAX_PATH * 2];
    
    // If name contains '/', treat as path (absolute or relative)
    if (strchr(name, '/')) {
        if (name[0] == '/') {
            // Absolute path
            if (file_exists(name)) {
                return strdup(name);
            }
        } else {
            // Relative path - resolve from CWD
            breezybox_resolve_path(name, path, sizeof(path));
            if (file_exists(path)) {
                return strdup(path);
            }
        }
        return NULL;
    }
    
    // Search in CWD first
    breezybox_resolve_path(name, path, sizeof(path));
    if (file_exists(path)) {
        return strdup(path);
    }
    
    // Search in PATH
    snprintf(path, sizeof(path), "%s/%s", EXEC_PATH, name);
    if (file_exists(path)) {
        return strdup(path);
    }
    
    return NULL;
}

// Argument parsing context
typedef struct {
    char *buffer;   // Original strdup'd buffer
    char **argv;    // Argument pointers
    int argc;       // Argument count
} parsed_args_t;

// Parse command line into argc/argv with basic quote support
// Returns 0 on success, -1 on error
static int parse_args(const char *cmdline, parsed_args_t *args)
{
    args->buffer = NULL;
    args->argv = NULL;
    args->argc = 0;
    
    if (!cmdline || !*cmdline) return 0;
    
    // Make a working copy
    char *buf = strdup(cmdline);
    if (!buf) return -1;
    
    // First pass: count arguments
    int argc = 0;
    char *p = buf;
    
    while (*p) {
        while (*p == ' ') p++;
        if (!*p) break;
        
        argc++;
        
        // Handle quoted strings
        if (*p == '"' || *p == '\'') {
            char quote = *p++;
            while (*p && *p != quote) p++;
            if (*p) p++;
        } else {
            while (*p && *p != ' ') p++;
        }
    }
    
    if (argc == 0) {
        free(buf);
        return 0;
    }
    
    // Allocate argv array
    char **argv = malloc((argc + 1) * sizeof(char *));
    if (!argv) {
        free(buf);
        return -1;
    }
    
    // Second pass: extract arguments
    p = buf;
    int i = 0;
    
    while (*p && i < argc) {
        while (*p == ' ') p++;
        if (!*p) break;
        
        // Handle quoted strings
        if (*p == '"' || *p == '\'') {
            char quote = *p++;
            argv[i++] = p;
            while (*p && *p != quote) p++;
            if (*p) *p++ = '\0';
        } else {
            argv[i++] = p;
            while (*p && *p != ' ') p++;
            if (*p) *p++ = '\0';
        }
    }
    argv[argc] = NULL;
    
    args->buffer = buf;
    args->argv = argv;
    args->argc = argc;
    
    return 0;
}

// Free parsed args
static void free_args(parsed_args_t *args)
{
    if (args) {
        free(args->argv);
        free(args->buffer);
        args->argv = NULL;
        args->buffer = NULL;
        args->argc = 0;
    }
}

// Run an ELF file
static int run_elf(const char *path, int argc, char **argv)
{
    ESP_LOGI(TAG, "Loading ELF: %s", path);
    
    // Read entire file into memory
    FILE *f = fopen(path, "rb");
    if (!f) {
        printf("Cannot open: %s\n", path);
        return -1;
    }
    
    fseek(f, 0, SEEK_END);
    long file_size = ftell(f);
    fseek(f, 0, SEEK_SET);
    
    if (file_size <= 0) {
        printf("Invalid file: %s\n", path);
        fclose(f);
        return -1;
    }
    
    uint8_t *elf_data = malloc(file_size);
    if (!elf_data) {
        printf("Out of memory (%ld bytes needed)\n", file_size);
        fclose(f);
        return -1;
    }
    
    size_t bytes_read = fread(elf_data, 1, file_size, f);
    fclose(f);
    
    if (bytes_read != (size_t)file_size) {
        printf("Read error\n");
        free(elf_data);
        return -1;
    }
    
    ESP_LOGI(TAG, "Loaded %ld bytes, initializing ELF loader", file_size);
    
    // Initialize and relocate ELF
    esp_elf_t elf;
    int ret;
    
    ret = esp_elf_init(&elf);
    if (ret < 0) {
        printf("ELF init failed: %d\n", ret);
        free(elf_data);
        return ret;
    }
    
    ret = esp_elf_relocate(&elf, elf_data);
    if (ret < 0) {
        printf("ELF relocate failed: %d\n", ret);
        esp_elf_deinit(&elf);
        free(elf_data);
        return ret;
    }
    
    ESP_LOGI(TAG, "Executing with %d args", argc);
    
    // Execute - pass argc/argv like a normal main()
    ret = esp_elf_request(&elf, 0, argc, argv);
    
    ESP_LOGI(TAG, "ELF returned: %d", ret);
    
    esp_elf_deinit(&elf);
    free(elf_data);
    
    return ret;
}

// Sentinel value meaning "command not found as external"
#define EXEC_NOT_FOUND INT_MIN

// Try to run as external command (ELF binary)
// Returns EXEC_NOT_FOUND if not found, otherwise returns ELF's return code
static int try_run_external(const char *cmdline)
{
    parsed_args_t args;
    
    if (parse_args(cmdline, &args) != 0 || args.argc == 0) {
        return EXEC_NOT_FOUND;
    }
    
    // Find executable
    char *exe_path = find_executable(args.argv[0]);
    if (!exe_path) {
        free_args(&args);
        return EXEC_NOT_FOUND;  // Not found
    }
    
    // Check if it's an ELF
    if (!is_elf_file(exe_path)) {
        free(exe_path);
        free_args(&args);
        return EXEC_NOT_FOUND;  // Not an ELF
    }
    
    int ret = run_elf(exe_path, args.argc, args.argv);
    
    free(exe_path);
    free_args(&args);
    
    return ret;
}

// Execute with output redirect using temp file
static int exec_with_output_redirect(const char *cmd, const char *outfile, int append)
{
    int ret = 0;
    
    esp_log_set_vprintf(null_vprintf);
    
    FILE *old_stdout = stdout;
    FILE *tmp = fopen(TEMP_OUT_FILE, "w");
    if (!tmp) {
        esp_log_set_vprintf(s_orig_vprintf);
        printf("Cannot create temp file\n");
        return -1;
    }
    
    // Swap stdout
    stdout = tmp;
    
    // Try external first, then builtin
    ret = try_run_external(cmd);
    if (ret == EXEC_NOT_FOUND) {
        esp_console_run(cmd, &ret);
    }
    fflush(stdout);
    
    // Restore stdout
    fclose(tmp);
    stdout = old_stdout;
    esp_log_set_vprintf(s_orig_vprintf);
    
    // Copy temp to destination
    FILE *src = fopen(TEMP_OUT_FILE, "r");
    if (!src) return ret;
    
    FILE *dst = fopen(outfile, append ? "a" : "w");
    if (!dst) {
        fclose(src);
        unlink(TEMP_OUT_FILE);
        return -1;
    }
    
    char buf[128];
    size_t n;
    while ((n = fread(buf, 1, sizeof(buf), src)) > 0) {
        fwrite(buf, 1, n, dst);
    }
    
    fclose(src);
    fclose(dst);
    unlink(TEMP_OUT_FILE);
    
    return ret;
}

static int exec_with_input_redirect(const char *cmd, const char *infile)
{
    int ret = 0;
    
    FILE *old_stdin = stdin;
    FILE *in = fopen(infile, "r");
    if (!in) {
        printf("Cannot open: %s\n", infile);
        return -1;
    }
    
    stdin = in;
    
    // Try external first, then builtin
    ret = try_run_external(cmd);
    if (ret == EXEC_NOT_FOUND) {
        esp_console_run(cmd, &ret);
    }
    
    fclose(in);
    stdin = old_stdin;
    
    return ret;
}

// Parse and execute a command with redirect support
int breezybox_exec(const char *cmdline)
{
    if (!cmdline || !*cmdline) return 0;
    
    // Make a working copy
    char *line = strdup(cmdline);
    if (!line) return -1;
    
    char *cmd1 = NULL, *cmd2 = NULL;
    char *infile = NULL, *outfile = NULL;
    int append = 0;
    int ret = 0;
    
    // Check for pipe first
    char *pipe_pos = strchr(line, '|');
    if (pipe_pos) {
        *pipe_pos = '\0';
        cmd1 = line;
        cmd2 = pipe_pos + 1;
        
        // Trim whitespace
        while (*cmd1 == ' ') cmd1++;
        while (*cmd2 == ' ') cmd2++;
        char *end1 = cmd1 + strlen(cmd1) - 1;
        char *end2 = cmd2 + strlen(cmd2) - 1;
        while (end1 > cmd1 && *end1 == ' ') *end1-- = '\0';
        while (end2 > cmd2 && *end2 == ' ') *end2-- = '\0';
        
        // Execute: cmd1 > tmpfile; cmd2 < tmpfile
        exec_with_output_redirect(cmd1, TEMP_PIPE_FILE, 0);
        ret = exec_with_input_redirect(cmd2, TEMP_PIPE_FILE);
        unlink(TEMP_PIPE_FILE);
        
        free(line);
        return ret;
    }
    
    // Check for output redirect (>> or >)
    char *redir_out = strstr(line, ">>");
    if (redir_out) {
        append = 1;
        *redir_out = '\0';
        outfile = redir_out + 2;
    } else {
        redir_out = strchr(line, '>');
        if (redir_out) {
            *redir_out = '\0';
            outfile = redir_out + 1;
        }
    }
    
    // Check for input redirect
    char *redir_in = strchr(line, '<');
    if (redir_in) {
        *redir_in = '\0';
        infile = redir_in + 1;
    }
    
    // Trim whitespace from all parts
    cmd1 = line;
    while (*cmd1 == ' ') cmd1++;
    char *end = cmd1 + strlen(cmd1) - 1;
    while (end > cmd1 && *end == ' ') *end-- = '\0';
    
    if (outfile) {
        while (*outfile == ' ') outfile++;
        end = outfile + strlen(outfile) - 1;
        while (end > outfile && *end == ' ') *end-- = '\0';
    }
    
    if (infile) {
        while (*infile == ' ') infile++;
        end = infile + strlen(infile) - 1;
        while (end > infile && *end == ' ') *end-- = '\0';
    }
    
    // Resolve relative paths for redirects
    char resolved_in[BREEZYBOX_MAX_PATH * 2];
    char resolved_out[BREEZYBOX_MAX_PATH * 2];
    
    if (infile && infile[0] != '/') {
        breezybox_resolve_path(infile, resolved_in, sizeof(resolved_in));
        infile = resolved_in;
    }
    if (outfile && outfile[0] != '/') {
        breezybox_resolve_path(outfile, resolved_out, sizeof(resolved_out));
        outfile = resolved_out;
    }
    
    // Execute with appropriate redirects
    if (outfile && infile) {
        // Both redirects - output takes precedence for now
        ret = exec_with_output_redirect(cmd1, outfile, append);
    } else if (outfile) {
        ret = exec_with_output_redirect(cmd1, outfile, append);
    } else if (infile) {
        ret = exec_with_input_redirect(cmd1, infile);
    } else {
        // No redirects - try external first, then builtin
        ret = try_run_external(cmd1);
        if (ret == EXEC_NOT_FOUND) {
            // Not found as external, try builtin
            esp_console_run(cmd1, &ret);
        }
    }
    
    free(line);
    return ret;
}