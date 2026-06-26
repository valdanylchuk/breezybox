#include "breezy_cmd.h"
#include "breezy_vfs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAIL_LINE_SIZE 256
#define TAIL_MAX_LINES 100

int cmd_tail(int argc, char **argv)
{
    int num_lines = 10;
    const char *filename = NULL;
    
    // Parse arguments
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-n") == 0 && i + 1 < argc) {
            num_lines = atoi(argv[++i]);
            if (num_lines <= 0) num_lines = 10;
        } else if (argv[i][0] == '-' && argv[i][1] >= '0' && argv[i][1] <= '9') {
            num_lines = atoi(&argv[i][1]);
            if (num_lines <= 0) num_lines = 10;
        } else if (argv[i][0] != '-') {
            filename = argv[i];
        }
    }
    
    if (!filename) {
        printf("Usage: tail [-n lines] <file>\n");
        return 1;
    }
    
    // Clamp to reasonable limit
    if (num_lines > TAIL_MAX_LINES) {
        num_lines = TAIL_MAX_LINES;
    }
    
    char resolved[BREEZYBOX_MAX_PATH * 2 + 2];
    const char *path = filename;
    if (path[0] != '/') {
        if (!breezybox_resolve_path(path, resolved, sizeof(resolved))) {
            printf("tail: path too long\n");
            return 1;
        }
        path = resolved;
    }
    
    FILE *f = fopen(path, "r");
    if (!f) {
        printf("tail: %s: No such file\n", filename);
        return 1;
    }
    
    // Circular buffer for last N lines
    char (*lines)[TAIL_LINE_SIZE] = malloc(num_lines * TAIL_LINE_SIZE);
    if (!lines) {
        printf("tail: out of memory\n");
        fclose(f);
        return 1;
    }
    
    int head = 0;       // Next position to write
    int count = 0;      // Total lines stored
    char buf[TAIL_LINE_SIZE];
    
    while (fgets(buf, sizeof(buf), f)) {
        strncpy(lines[head], buf, TAIL_LINE_SIZE - 1);
        lines[head][TAIL_LINE_SIZE - 1] = '\0';
        head = (head + 1) % num_lines;
        if (count < num_lines) count++;
    }
    fclose(f);
    
    // Print lines in order
    int start = (count < num_lines) ? 0 : head;
    for (int i = 0; i < count; i++) {
        int idx = (start + i) % num_lines;
        printf("%s", lines[idx]);
    }
    
    free(lines);
    return 0;
}