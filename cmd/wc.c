#include "breezy_cmd.h"
#include "breezy_vfs.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int cmd_wc(int argc, char **argv)
{
    int show_lines = 0, show_words = 0, show_chars = 0;
    const char *filename = NULL;
    
    // Parse arguments
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-') {
            for (int j = 1; argv[i][j]; j++) {
                switch (argv[i][j]) {
                    case 'l': show_lines = 1; break;
                    case 'w': show_words = 1; break;
                    case 'c': show_chars = 1; break;
                }
            }
        } else {
            filename = argv[i];
        }
    }
    
    // Default: show all
    if (!show_lines && !show_words && !show_chars) {
        show_lines = show_words = show_chars = 1;
    }
    
    if (!filename) {
        printf("Usage: wc [-lwc] <file>\n");
        return 1;
    }
    
    char resolved[BREEZYBOX_MAX_PATH * 2 + 2];
    const char *path = filename;
    if (path[0] != '/') {
        if (!breezybox_resolve_path(path, resolved, sizeof(resolved))) {
            printf("wc: path too long\n");
            return 1;
        }
        path = resolved;
    }
    
    FILE *f = fopen(path, "r");
    if (!f) {
        printf("wc: %s: No such file\n", filename);
        return 1;
    }
    
    long lines = 0, words = 0, chars = 0;
    int in_word = 0;
    int c;
    
    while ((c = fgetc(f)) != EOF) {
        chars++;
        
        if (c == '\n') {
            lines++;
        }
        
        if (isspace(c)) {
            in_word = 0;
        } else if (!in_word) {
            in_word = 1;
            words++;
        }
    }
    
    fclose(f);
    
    // Print results
    if (show_lines) printf("%7ld ", lines);
    if (show_words) printf("%7ld ", words);
    if (show_chars) printf("%7ld ", chars);
    printf("%s\n", filename);
    
    return 0;
}