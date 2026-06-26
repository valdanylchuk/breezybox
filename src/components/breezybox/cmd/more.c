#include "breezy_cmd.h"
#include "breezy_vfs.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFAULT_PAGE_LINES 20

int cmd_more(int argc, char **argv)
{
    int page_lines = DEFAULT_PAGE_LINES;
    const char *filename = NULL;
    
    // Parse arguments
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-n") == 0 && i + 1 < argc) {
            page_lines = atoi(argv[++i]);
            if (page_lines <= 0) page_lines = DEFAULT_PAGE_LINES;
        } else if (argv[i][0] != '-') {
            filename = argv[i];
        }
    }
    
    if (!filename) {
        printf("Usage: more [-n lines] <file>\n");
        return 1;
    }
    
    char resolved[BREEZYBOX_MAX_PATH * 2 + 2];
    const char *path = filename;
    if (path[0] != '/') {
        if (!breezybox_resolve_path(path, resolved, sizeof(resolved))) {
            printf("more: path too long\n");
            return 1;
        }
        path = resolved;
    }
    
    FILE *f = fopen(path, "r");
    if (!f) {
        printf("more: %s: No such file\n", filename);
        return 1;
    }
    
    char line[256];
    int line_count = 0;
    
    while (fgets(line, sizeof(line), f)) {
        printf("%s", line);
        
        // Count line if it had a newline
        if (strchr(line, '\n')) {
            line_count++;
        }
        
        if (line_count >= page_lines) {
            printf("--More-- (Enter=next line, Space=next page, q=quit)");
            fflush(stdout);
            
            // Wait for input
            int c;
            while (1) {
                c = getchar();
                if (c == EOF) {
                    vTaskDelay(pdMS_TO_TICKS(50));
                    continue;
                }
                break;
            }
            
            // Clear the --More-- prompt
            printf("\r                                                  \r");
            
            if (c == 'q' || c == 'Q') {
                break;
            } else if (c == '\n' || c == '\r') {
                // Show one more line
                line_count = page_lines - 1;
            } else {
                // Space or anything else: next page
                line_count = 0;
            }
        }
    }
    
    fclose(f);
    return 0;
}