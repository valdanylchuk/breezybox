#include "breezy_cmd.h"
#include "breezy_vfs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmd_head(int argc, char **argv)
{
    int num_lines = 10;
    const char *filename = NULL;
    
    // Parse arguments
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-n") == 0 && i + 1 < argc) {
            num_lines = atoi(argv[++i]);
            if (num_lines <= 0) num_lines = 10;
        } else if (argv[i][0] == '-' && argv[i][1] >= '0' && argv[i][1] <= '9') {
            // Support -N syntax
            num_lines = atoi(&argv[i][1]);
            if (num_lines <= 0) num_lines = 10;
        } else if (argv[i][0] != '-') {
            filename = argv[i];
        }
    }
    
    if (!filename) {
        printf("Usage: head [-n lines] <file>\n");
        return 1;
    }
    
    char resolved[BREEZYBOX_MAX_PATH * 2 + 2];
    const char *path = filename;
    if (path[0] != '/') {
        if (!breezybox_resolve_path(path, resolved, sizeof(resolved))) {
            printf("head: path too long\n");
            return 1;
        }
        path = resolved;
    }
    
    FILE *f = fopen(path, "r");
    if (!f) {
        printf("head: %s: No such file\n", filename);
        return 1;
    }
    
    char line[256];
    int count = 0;
    while (count < num_lines && fgets(line, sizeof(line), f)) {
        printf("%s", line);
        // Only count as a line if we got a newline or EOF
        if (strchr(line, '\n') || feof(f)) {
            count++;
        }
    }
    
    fclose(f);
    return 0;
}