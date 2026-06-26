/*
 * wget.c - Minimal HTTP file downloader for ESP32-BusyBox
 *
 * Usage: wget <url> [filename]
 *
 * Downloads a file from HTTP(S) URL and saves to current directory.
 * If filename not specified, extracts from URL path.
 */

#include <stdio.h>
#include <string.h>

/* Wrapper function provided by firmware - avoids struct layout issues */
int breezy_http_download(const char *url, const char *dest_path);

/* Extract filename from URL path */
static const char *url_filename(const char *url)
{
    const char *p = strrchr(url, '/');
    if (p && p[1] != '\0') {
        return p + 1;
    }
    return "download";
}

int main(int argc, char **argv)
{
    if (argc < 2) {
        printf("Usage: wget <url> [filename]\n");
        return 1;
    }

    const char *url = argv[1];
    const char *filename = (argc > 2) ? argv[2] : url_filename(url);

    /* Validate URL */
    if (strncmp(url, "http://", 7) != 0 && strncmp(url, "https://", 8) != 0) {
        printf("wget: URL must start with http:// or https://\n");
        return 1;
    }

    printf("Downloading %s\n", url);
    printf("  -> %s\n", filename);

    int ret = breezy_http_download(url, filename);
    if (ret == -2) {
        printf("wget: no network (use 'wifi' to connect)\n");
        return 1;
    }
    if (ret != 0) {
        printf("wget: download failed\n");
        return 1;
    }

    printf("Done.\n");
    return 0;
}
