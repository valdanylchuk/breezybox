/*
 * mv.c - Move/rename files
 * 
 * Usage: mv <source> <dest>
 */

#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include "breezy_vfs.h"

int cmd_mv(int argc, char **argv)
{
    if (argc < 3) {
        printf("Usage: mv <source> <dest>\n");
        return 1;
    }
    
    char src_path[256], dst_path[256];
    breezybox_resolve_path(argv[1], src_path, sizeof(src_path));
    breezybox_resolve_path(argv[2], dst_path, sizeof(dst_path));
    
    // Check if source exists
    struct stat st;
    if (stat(src_path, &st) != 0) {
        printf("mv: cannot stat '%s': No such file or directory\n", argv[1]);
        return 1;
    }
    
    // Check if dest is a directory - if so, append source filename
    struct stat dst_st;
    if (stat(dst_path, &dst_st) == 0 && S_ISDIR(dst_st.st_mode)) {
        // Extract filename from source
        const char *filename = strrchr(argv[1], '/');
        filename = filename ? filename + 1 : argv[1];
        
        size_t len = strlen(dst_path);
        if (len > 0 && dst_path[len-1] != '/') {
            strncat(dst_path, "/", sizeof(dst_path) - len - 1);
        }
        strncat(dst_path, filename, sizeof(dst_path) - strlen(dst_path) - 1);
    }
    
    // Try rename (works if same filesystem)
    if (rename(src_path, dst_path) == 0) {
        return 0;
    }
    
    // If rename failed and source is a directory, we can't easily move it
    if (S_ISDIR(st.st_mode)) {
        printf("mv: cannot move directory '%s'\n", argv[1]);
        return 1;
    }
    
    // For files, fall back to copy + delete
    FILE *src = fopen(src_path, "rb");
    if (!src) {
        printf("mv: cannot open '%s'\n", argv[1]);
        return 1;
    }
    
    FILE *dst = fopen(dst_path, "wb");
    if (!dst) {
        printf("mv: cannot create '%s'\n", argv[2]);
        fclose(src);
        return 1;
    }
    
    char buf[512];
    size_t bytes_read;
    int error = 0;
    
    while ((bytes_read = fread(buf, 1, sizeof(buf), src)) > 0) {
        if (fwrite(buf, 1, bytes_read, dst) != bytes_read) {
            error = 1;
            break;
        }
    }
    
    fclose(src);
    fclose(dst);
    
    if (error) {
        printf("mv: write error\n");
        remove(dst_path);  // Clean up partial file
        return 1;
    }
    
    // Delete source
    if (remove(src_path) != 0) {
        printf("mv: warning: copied but could not remove source\n");
    }
    
    return 0;
}