/*
 * du.c - Show disk usage
 * 
 * Usage: du [-s] [path]
 *   -s  Summary only (don't show subdirectories)
 */

#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include "breezy_vfs.h"

static int s_summary_only = 0;

// Calculate size of a directory recursively
static unsigned long get_dir_size(const char *path, int depth)
{
    DIR *dir = opendir(path);
    if (!dir) return 0;
    
    struct dirent *entry;
    struct stat st;
    char child_path[512];
    unsigned long total = 0;
    
    while ((entry = readdir(dir)) != NULL) {
        // Skip . and ..
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        
        snprintf(child_path, sizeof(child_path), "%.240s/%.240s", path, entry->d_name);
        
        if (stat(child_path, &st) == 0) {
            if (S_ISDIR(st.st_mode)) {
                unsigned long subdir_size = get_dir_size(child_path, depth + 1);
                total += subdir_size;
                
                // Print subdirectory if not summary mode
                if (!s_summary_only) {
                    printf("%7lu  %s\n", (subdir_size + 1023) / 1024, child_path);
                }
            } else {
                total += st.st_size;
            }
        }
    }
    
    closedir(dir);
    return total;
}

int cmd_du(int argc, char **argv)
{
    s_summary_only = 0;
    const char *target = ".";
    
    // Parse arguments
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-s") == 0) {
            s_summary_only = 1;
        } else if (argv[i][0] != '-') {
            target = argv[i];
        }
    }
    
    char path[256];
    breezybox_resolve_path(target, path, sizeof(path));
    
    struct stat st;
    if (stat(path, &st) != 0) {
        printf("du: cannot access '%s'\n", target);
        return 1;
    }
    
    unsigned long size;
    
    if (S_ISDIR(st.st_mode)) {
        size = get_dir_size(path, 0);
    } else {
        size = st.st_size;
    }
    
    // Print total (always shown)
    printf("%7lu  %s\n", (size + 1023) / 1024, path);
    
    return 0;
}