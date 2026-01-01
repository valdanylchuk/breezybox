#include "breezybox.h"
#include "breezy_vfs.h"
#include "breezy_cmd.h"
#include "breezy_exec.h"
#include "esp_console.h"
#include "esp_heap_caps.h"
#include "linenoise/linenoise.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define INIT_SCRIPT BREEZYBOX_MOUNT_POINT "/init.sh"
#define DEFAULT_INIT "echo Welcome to BreezyBox!\n"

static esp_console_repl_t *s_repl = NULL;

// ============ Short Commands (inline) ============

int cmd_echo(int argc, char **argv)
{
    for (int i = 1; i < argc; i++) {
        printf("%s%s", argv[i], (i < argc - 1) ? " " : "");
    }
    printf("\n");
    return 0;
}

int cmd_pwd(int argc, char **argv)
{
    (void)argc; (void)argv;
    printf("%s\n", breezybox_cwd());
    return 0;
}

int cmd_cd(int argc, char **argv)
{
    if (argc < 2) {
        printf("%s\n", breezybox_cwd());
        return 0;
    }
    if (breezybox_set_cwd(argv[1]) != 0) {
        printf("cd: %s: No such directory\n", argv[1]);
        return 1;
    }
    return 0;
}

int cmd_clear(int argc, char **argv)
{
    (void)argc; (void)argv;
    printf("\033[2J\033[H");  // Clear screen + cursor home
    return 0;
}

int cmd_free(int argc, char **argv)
{
    (void)argc; (void)argv;
    
    // Internal SRAM (DMA-capable, needed for WiFi/BT)
    size_t free_internal = heap_caps_get_free_size(MALLOC_CAP_INTERNAL | MALLOC_CAP_8BIT);
    size_t total_internal = heap_caps_get_total_size(MALLOC_CAP_INTERNAL | MALLOC_CAP_8BIT);
    size_t min_internal = heap_caps_get_minimum_free_size(MALLOC_CAP_INTERNAL | MALLOC_CAP_8BIT);
    
    printf("SRAM:  %6uK free, %6uK min, %6uK total\n", 
           (unsigned)(free_internal / 1024),
           (unsigned)(min_internal / 1024),
           (unsigned)(total_internal / 1024));
    
#ifdef CONFIG_SPIRAM
    size_t free_psram = heap_caps_get_free_size(MALLOC_CAP_SPIRAM);
    size_t total_psram = heap_caps_get_total_size(MALLOC_CAP_SPIRAM);
    size_t min_psram = heap_caps_get_minimum_free_size(MALLOC_CAP_SPIRAM);
    
    printf("PSRAM: %6uK free, %6uK min, %6uK total\n",
           (unsigned)(free_psram / 1024),
           (unsigned)(min_psram / 1024),
           (unsigned)(total_psram / 1024));
#endif
    
    return 0;
}

// Run a script file with redirect support
int cmd_sh(int argc, char **argv)
{
    if (argc < 2) {
        printf("Usage: sh <script>\n");
        return 1;
    }
    
    char resolved[BREEZYBOX_MAX_PATH * 2 + 2];
    const char *path = argv[1];
    if (path[0] != '/') {
        if (!breezybox_resolve_path(path, resolved, sizeof(resolved))) {
            printf("sh: path too long\n");
            return 1;
        }
        path = resolved;
    }
    
    FILE *f = fopen(path, "r");
    if (!f) {
        printf("sh: %s: No such file\n", argv[1]);
        return 1;
    }
    
    char line[256];
    int ret = 0;
    while (fgets(line, sizeof(line), f)) {
        size_t len = strlen(line);
        while (len > 0 && (line[len-1] == '\n' || line[len-1] == '\r' || line[len-1] == ' ')) {
            line[--len] = '\0';
        }
        
        char *p = line;
        while (*p && isspace((unsigned char)*p)) p++;
        if (*p == '\0' || *p == '#') continue;
        
        ret = breezybox_exec(p);
    }
    fclose(f);
    return ret;
}

// ============ Init Script ============

static void create_default_init(void)
{
    FILE *f = fopen(INIT_SCRIPT, "w");
    if (f) {
        fputs(DEFAULT_INIT, f);
        fclose(f);
    }
}

static void run_init_script(void)
{
    FILE *f = fopen(INIT_SCRIPT, "r");
    if (!f) {
        create_default_init();
        f = fopen(INIT_SCRIPT, "r");
        if (!f) return;
    }

    char line[256];
    while (fgets(line, sizeof(line), f)) {
        size_t len = strlen(line);
        while (len > 0 && (line[len-1] == '\n' || line[len-1] == '\r' || line[len-1] == ' ')) {
            line[--len] = '\0';
        }
        
        char *p = line;
        while (*p && isspace((unsigned char)*p)) p++;
        if (*p == '\0' || *p == '#') continue;

        // Execute with redirect support
        breezybox_exec(p);
    }
    fclose(f);
}

// ============ Command Registration ============

esp_err_t breezybox_register_commands(void)
{
    const esp_console_cmd_t cmds[] = {
        { .command = "echo",  .help = "Print arguments",         .hint = "[text...]", .func = &cmd_echo  },
        { .command = "pwd",   .help = "Print working directory", .hint = NULL,        .func = &cmd_pwd   },
        { .command = "cd",    .help = "Change directory",        .hint = "[path]",    .func = &cmd_cd    },
        { .command = "ls",    .help = "List directory",          .hint = "[path]",    .func = &cmd_ls    },
        { .command = "cat",   .help = "Print file contents",     .hint = "<file>",    .func = &cmd_cat   },
        { .command = "head",  .help = "Show first lines",        .hint = "[-n N] <file>", .func = &cmd_head },
        { .command = "tail",  .help = "Show last lines",         .hint = "[-n N] <file>", .func = &cmd_tail },
        { .command = "more",  .help = "Paginate file",           .hint = "<file>",    .func = &cmd_more  },
        { .command = "wc",    .help = "Count lines/words/chars", .hint = "[-lwc] <file>", .func = &cmd_wc },
        { .command = "mkdir", .help = "Create directory",        .hint = "<dir>",     .func = &cmd_mkdir },
        { .command = "cp",    .help = "Copy file",               .hint = "<src> <dst>", .func = &cmd_cp  },
        { .command = "mv",    .help = "Move/rename file",        .hint = "<src> <dst>", .func = &cmd_mv  },
        { .command = "rm",    .help = "Remove file/directory",   .hint = "[-r] <file...>", .func = &cmd_rm },
        { .command = "df",    .help = "Show disk free space",    .hint = NULL,        .func = &cmd_df    },
        { .command = "du",    .help = "Show disk usage",         .hint = "[-s] [path]", .func = &cmd_du  },
        { .command = "free",  .help = "Show memory usage",       .hint = NULL,        .func = &cmd_free  },
        { .command = "date",  .help = "Show/set date and time",  .hint = "[\"YYYY-MM-DD HH:MM:SS\"]", .func = &cmd_date },
        { .command = "clear", .help = "Clear screen",            .hint = NULL,        .func = &cmd_clear },
        { .command = "sh",    .help = "Run script file",         .hint = "<script>",  .func = &cmd_sh    },
        { .command = "eget",  .help = "Download ELF from GitHub", .hint = "<user/repo>", .func = &cmd_eget },
        { .command = "wifi",  .help = "WiFi commands",           .hint = "<scan|connect|disconnect|status|forget>", .func = &cmd_wifi },
        { .command = "httpd", .help = "HTTP file server",        .hint = "[dir] [-p port]", .func = &cmd_httpd },
    };

    for (size_t i = 0; i < sizeof(cmds) / sizeof(cmds[0]); i++) {
        esp_err_t err = esp_console_cmd_register(&cmds[i]);
        if (err != ESP_OK) return err;
    }
    return ESP_OK;
}

// ============ Common Init ============

static esp_err_t breezybox_init_common(void)
{
    // Force-export symbols for ELF runtime linking
    breezybox_export_symbols();
    
    // Initialize filesystem
    esp_err_t ret = breezybox_vfs_init();
    if (ret != ESP_OK) {
        printf("BreezyBox: filesystem init failed\n");
        return ret;
    }

    // Initialize exec subsystem (for redirects)
    breezybox_exec_init();

    // Initialize console (for command parsing)
    esp_console_config_t console_config = ESP_CONSOLE_CONFIG_DEFAULT();
    ESP_ERROR_CHECK(esp_console_init(&console_config));

    // Register commands
    breezybox_register_commands();
    esp_console_register_help_command();

    // Run init script
    run_init_script();

    return ESP_OK;
}

// ============ REPL Implementations ============

// Linenoise-based REPL task for stdio mode
static void stdio_repl_task(void *arg)
{
    // Skip probe for now - our VFS console handles terminal queries internally
    // The probe can cause issues when responses get mixed up
    // linenoiseSetDumbMode(1);  // Uncomment to force dumb mode for debugging
    
    // Setup linenoise with esp_console's completion/hints
    linenoiseSetMultiLine(1);
    linenoiseSetCompletionCallback(&esp_console_get_completion);
    linenoiseSetHintsCallback((linenoiseHintsCallback *)&esp_console_get_hint);
    linenoiseHistorySetMaxLen(100);
    
    printf("\nType 'help' to get the list of commands.\n");
    
    while (true) {
        char *line = linenoise("$ ");
        
        if (line == NULL) {
            // Ctrl+D or read error, just continue
            continue;
        }
        
        // Skip empty lines
        if (strlen(line) > 0) {
            linenoiseHistoryAdd(line);
            breezybox_exec(line);
        }
        
        linenoiseFree(line);
    }
}

esp_err_t breezybox_start_stdio(size_t stack_size, uint32_t priority)
{
    esp_err_t ret = breezybox_init_common();
    if (ret != ESP_OK) return ret;

    xTaskCreate(stdio_repl_task, "breezy_repl", stack_size, NULL, priority, NULL);
    return ESP_OK;
}

esp_err_t breezybox_start_usb(size_t stack_size, uint32_t priority)
{
    // Initialize filesystem and exec
    esp_err_t ret = breezybox_vfs_init();
    if (ret != ESP_OK) {
        printf("BreezyBox: filesystem init failed\n");
        return ret;
    }
    breezybox_exec_init();

    // Setup USB Serial JTAG REPL (this also initializes console)
    esp_console_repl_config_t repl_config = ESP_CONSOLE_REPL_CONFIG_DEFAULT();
    repl_config.prompt = "$ ";
    repl_config.task_stack_size = stack_size;
    repl_config.task_priority = priority;

    esp_console_dev_usb_serial_jtag_config_t hw_config =
        ESP_CONSOLE_DEV_USB_SERIAL_JTAG_CONFIG_DEFAULT();

    ESP_ERROR_CHECK(esp_console_new_repl_usb_serial_jtag(&hw_config, &repl_config, &s_repl));
    
    breezybox_register_commands();
    run_init_script();

    return esp_console_start_repl(s_repl);
}