/*
 * df.c - Show disk free space
 * 
 * Usage: df
 */

#include <stdio.h>
#include "esp_littlefs.h"
#include "breezy_vfs.h"

int cmd_df(int argc, char **argv)
{
    (void)argc; (void)argv;
    
    size_t total_bytes = 0, used_bytes = 0;
    
    // Get LittleFS partition info
    // The partition label is "storage" as configured in breezy_vfs.c
    esp_err_t ret = esp_littlefs_info("storage", &total_bytes, &used_bytes);
    if (ret != ESP_OK) {
        printf("df: cannot get filesystem info\n");
        return 1;
    }
    
    unsigned long total_kb = total_bytes / 1024;
    unsigned long used_kb = used_bytes / 1024;
    unsigned long free_kb = total_kb - used_kb;
    int percent = (total_kb > 0) ? ((int)(used_kb * 100 / total_kb)) : 0;
    
    printf("Filesystem      Size    Used   Avail  Use%%\n");
    printf("%-12s  %5luK  %5luK  %5luK  %3d%%\n",
           BREEZYBOX_MOUNT_POINT, total_kb, used_kb, free_kb, percent);
    
    return 0;
}