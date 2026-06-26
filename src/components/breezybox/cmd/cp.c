/*
 * cp.c - Copy files
 * 
 * Usage: cp <source> <dest>
 */

#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include "breezy_vfs.h"

#define COPY_BUF_SIZE 512

int cmd_cp(int argc, char **argv)
{
    if (argc < 3) {
        printf("Usage: cp <source> <dest>\n");
        return 1;
    }
    
    char src_path[256], dst_path[256];
    breezybox_resolve_path(argv[1], src_path, sizeof(src_path));
    breezybox_resolve_path(argv[2], dst_path, sizeof(dst_path));
    
    // Check if source exists and is a file
    struct stat st;
    if (stat(src_path, &st) != 0) {
        printf("cp: cannot stat '%s': No such file\n", argv[1]);
        return 1;
    }
    if (S_ISDIR(st.st_mode)) {
        printf("cp: '%s' is a directory (not supported)\n", argv[1]);
        return 1;
    }
    
    // Check if dest is a directory - if so, append source filename
    if (stat(dst_path, &st) == 0 && S_ISDIR(st.st_mode)) {
        // Extract filename from source
        const char *filename = strrchr(argv[1], '/');
        filename = filename ? filename + 1 : argv[1];
        
        size_t len = strlen(dst_path);
        if (len > 0 && dst_path[len-1] != '/') {
            strncat(dst_path, "/", sizeof(dst_path) - len - 1);
        }
        strncat(dst_path, filename, sizeof(dst_path) - strlen(dst_path) - 1);
    }
    
    // Open source for reading
    FILE *src = fopen(src_path, "rb");
    if (!src) {
        printf("cp: cannot open '%s'\n", argv[1]);
        return 1;
    }
    
    // Open dest for writing
    FILE *dst = fopen(dst_path, "wb");
    if (!dst) {
        printf("cp: cannot create '%s'\n", argv[2]);
        fclose(src);
        return 1;
    }
    
    // Copy contents
    char buf[COPY_BUF_SIZE];
    size_t bytes_read;
    
    while ((bytes_read = fread(buf, 1, sizeof(buf), src)) > 0) {
        size_t written = fwrite(buf, 1, bytes_read, dst);
        if (written != bytes_read) {
            printf("cp: write error\n");
            fclose(src);
            fclose(dst);
            return 1;
        }
    }
    
    fclose(src);
    fclose(dst);
    
    return 0;
}