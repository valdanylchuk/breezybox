/*
 * rm.c - Remove files
 * 
 * Usage: rm [-r] <file...>
 */

#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include "breezy_vfs.h"

// Forward declaration for recursion
static int remove_recursive(const char *path);

static int remove_dir_contents(const char *path)
{
    DIR *dir = opendir(path);
    if (!dir) return -1;
    
    struct dirent *entry;
    char child_path[512];
    int ret = 0;
    
    while ((entry = readdir(dir)) != NULL) {
        // Skip . and ..
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        
        snprintf(child_path, sizeof(child_path), "%.240s/%.240s", path, entry->d_name);
        
        if (remove_recursive(child_path) != 0) {
            ret = -1;
        }
    }
    
    closedir(dir);
    return ret;
}

static int remove_recursive(const char *path)
{
    struct stat st;
    if (stat(path, &st) != 0) {
        return -1;
    }
    
    if (S_ISDIR(st.st_mode)) {
        // Remove directory contents first
        if (remove_dir_contents(path) != 0) {
            return -1;
        }
        // Then remove the directory itself
        return rmdir(path);
    } else {
        return remove(path);
    }
}

int cmd_rm(int argc, char **argv)
{
    if (argc < 2) {
        printf("Usage: rm [-r] <file...>\n");
        return 1;
    }
    
    int recursive = 0;
    int start_arg = 1;
    
    // Check for -r flag
    if (argc >= 2 && strcmp(argv[1], "-r") == 0) {
        recursive = 1;
        start_arg = 2;
    }
    
    if (start_arg >= argc) {
        printf("Usage: rm [-r] <file...>\n");
        return 1;
    }
    
    int errors = 0;
    
    for (int i = start_arg; i < argc; i++) {
        char path[256];
        breezybox_resolve_path(argv[i], path, sizeof(path));
        
        struct stat st;
        if (stat(path, &st) != 0) {
            printf("rm: cannot remove '%s': No such file or directory\n", argv[i]);
            errors++;
            continue;
        }
        
        if (S_ISDIR(st.st_mode)) {
            if (!recursive) {
                printf("rm: cannot remove '%s': Is a directory (use -r)\n", argv[i]);
                errors++;
                continue;
            }
            
            if (remove_recursive(path) != 0) {
                printf("rm: cannot remove '%s'\n", argv[i]);
                errors++;
            }
        } else {
            if (remove(path) != 0) {
                printf("rm: cannot remove '%s'\n", argv[i]);
                errors++;
            }
        }
    }
    
    return errors > 0 ? 1 : 0;
}