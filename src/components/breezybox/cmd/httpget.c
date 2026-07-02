/*
 * httpget.c - Download ELF binaries from http://url/file
 *
 * Usage: httpget http://url/file path_file
 *
 * Downloads all .elf files from the latest release to /root/bin/
 * The .elf extension is removed from the installed binary name.
 */

#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "esp_http_client.h"
#include "esp_crt_bundle.h"
#include "esp_heap_caps.h"
#include "cJSON.h"
#include "breezy_vfs.h"

#define MAX_RESPONSE_SIZE (64 * 1024) // 64KB for API response
#define MAX_URL_LEN 512
#define MAX_DOWNLOAD_SIZE (512 * 1024) // 512KB max binary size
#define BIN_DIR "/root/bin"

#if defined(__riscv)
#define BREEZY_ARCH "rv32"
#elif defined(__XTENSA__)
#define BREEZY_ARCH "xtensa"
#else
#error "eget: unknown breezy target arch"
#endif
#define ARCH_SUFFIX "." BREEZY_ARCH ".elf"

// Buffer for HTTP response
static char *s_response_buf = NULL;
static int s_response_len = 0;
static int s_response_max = 0;
struct stat fileStat;

// HTTP event handler
static esp_err_t http_event_handler(esp_http_client_event_t *evt)
{
    switch (evt->event_id)
    {
    case HTTP_EVENT_ON_DATA:
        if (s_response_buf && (s_response_len + evt->data_len < s_response_max))
        {
            memcpy(s_response_buf + s_response_len, evt->data, evt->data_len);
            s_response_len += evt->data_len;
        }
        break;
    default:
        break;
    }
    return ESP_OK;
}

// Context struct to pass to the event handler
typedef struct
{
    FILE *file;
    size_t total_written;
} download_ctx_t;

static esp_err_t download_event_handler(esp_http_client_event_t *evt)
{
    download_ctx_t *ctx = (download_ctx_t *)evt->user_data;

    switch (evt->event_id)
    {
    case HTTP_EVENT_ON_DATA:
        if (ctx->file && evt->data_len > 0)
        {
            size_t written = fwrite(evt->data, 1, evt->data_len, ctx->file);
            ctx->total_written += written;
            // Optional: Print progress dots
            // if (ctx->total_written % 10240 == 0) printf(".");
        }
        break;
    default:
        break;
    }
    return ESP_OK;
}

static int download_file(const char *url, const char *dest_path)
{
    printf("  Downloading to %s...\n", dest_path);

    FILE *f = fopen(dest_path, "wb");
    if (!f)
    {
        printf("httpget: cannot create file\n");
        return -1;
    }

    download_ctx_t ctx = {.file = f, .total_written = 0};

    esp_http_client_config_t config = {
        .url = url,
        .event_handler = download_event_handler,
        .user_data = &ctx,
        .crt_bundle_attach = esp_crt_bundle_attach,
        .timeout_ms = 60000,
        .max_redirection_count = 5,

        .buffer_size = 4096,    // Rx Buffer: Standard size is usually fine
        .buffer_size_tx = 2048, // Tx Buffer: Increased to hold long AWS URLs
    };

    esp_http_client_handle_t client = esp_http_client_init(&config);
    if (!client)
    {
        fclose(f);
        return -1;
    }

    // Headers required by GitHub for assets
    esp_http_client_set_header(client, "Accept", "application/octet-stream");
    esp_http_client_set_header(client, "User-Agent", "ESP32-BreezyBox");

    esp_err_t err = esp_http_client_perform(client);
    int status = esp_http_client_get_status_code(client);

    esp_http_client_cleanup(client);
    fclose(f);

    if (err != ESP_OK || status != 200)
    {
        printf("\neget: download failed (err=%d, status=%d)\n", err, status);
        unlink(dest_path); // Delete partial file
        return -1;
    }

    printf("  Success (%u bytes)\n", (unsigned)ctx.total_written);
    return 0;
}

int cmd_httpget(int argc, char **argv)
{

    if (argc < 3)
    {
        printf("Usage: httpget http://url/file </path/file>\n");
        printf("  Downloads file and save to destination\n");
        return 1;
    }
    const char *url = argv[1];
    const char *path_file = argv[2];

    // make sure the destination path exists
    if (argc == 3)
    {
        const char *last_slash = strrchr(argv[2], '/');
        char dst_dir[256] = {0};
        char dst_file[256] = {0};

        if (last_slash != NULL)
        {
            size_t dst_dir_len = last_slash - argv[2];

            if (dst_dir_len < sizeof(dst_dir))
            {
                strncpy(dst_dir, argv[2], dst_dir_len);
                dst_dir[dst_dir_len] = '\0'; // Explicitly null-terminate
            }
            strncpy(dst_file, last_slash + 1, sizeof(dst_file) - 1);
        }
        else
        {
            // No slash found
            dst_dir[0] = '\0';
            strncpy(dst_file, argv[2], sizeof(dst_file) - 1);
        }

        if (stat(dst_dir, &fileStat) == 0)
        {
            if (S_ISDIR(fileStat.st_mode))
            {
                //  printf("Directory exists: %s\n", dst_dir);
            }
            else
            {
                // printf("it's a file: %s\n", dst_dir);
                return 1;
            }
        }
        else
        {
            printf("No such file or directory: %s\n", dst_dir);
            return 1;
        }
        // printf("Directory: %s\n", dst_dir);
        // printf("File Name: %s\n", dst_file);
    }

    printf("Fetching %s...\n", url);

    // Download the file
    download_file(url, path_file);

    printf("Download complete. File saved to  %s/\n", path_file);
    return 0;
}
