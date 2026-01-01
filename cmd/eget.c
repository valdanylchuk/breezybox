/*
 * eget.c - Download ELF binaries from GitHub releases
 * 
 * Usage: eget <user/repo>
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

#define MAX_RESPONSE_SIZE   (64 * 1024)  // 64KB for API response
#define MAX_URL_LEN         512
#define MAX_DOWNLOAD_SIZE   (512 * 1024) // 512KB max binary size
#define BIN_DIR             "/root/bin"

// Buffer for HTTP response
static char *s_response_buf = NULL;
static int s_response_len = 0;
static int s_response_max = 0;

// HTTP event handler
static esp_err_t http_event_handler(esp_http_client_event_t *evt)
{
    switch (evt->event_id) {
    case HTTP_EVENT_ON_DATA:
        if (s_response_buf && (s_response_len + evt->data_len < s_response_max)) {
            memcpy(s_response_buf + s_response_len, evt->data, evt->data_len);
            s_response_len += evt->data_len;
        }
        break;
    default:
        break;
    }
    return ESP_OK;
}

// Fetch URL and return response in buffer (caller must free)
static char *fetch_json(const char *url, int *out_len)
{
    s_response_buf = heap_caps_malloc(MAX_RESPONSE_SIZE, MALLOC_CAP_SPIRAM);
    if (!s_response_buf) {
        printf("eget: out of memory\n");
        return NULL;
    }
    s_response_len = 0;
    s_response_max = MAX_RESPONSE_SIZE;
    
    esp_http_client_config_t config = {
        .url = url,
        .event_handler = http_event_handler,
        .crt_bundle_attach = esp_crt_bundle_attach,
        .timeout_ms = 30000,
        .buffer_size = 4096,
    };
    
    esp_http_client_handle_t client = esp_http_client_init(&config);
    if (!client) {
        free(s_response_buf);
        s_response_buf = NULL;
        return NULL;
    }
    
    // Set headers for GitHub API
    esp_http_client_set_header(client, "Accept", "application/vnd.github.v3+json");
    esp_http_client_set_header(client, "User-Agent", "ESP32-BreezyBox");
    
    esp_err_t err = esp_http_client_perform(client);
    int status = esp_http_client_get_status_code(client);
    esp_http_client_cleanup(client);
    
    if (err != ESP_OK || status != 200) {
        printf("eget: HTTP error %d (status %d)\n", err, status);
        free(s_response_buf);
        s_response_buf = NULL;
        return NULL;
    }
    
    // Null-terminate for JSON parsing
    s_response_buf[s_response_len] = '\0';
    
    char *result = s_response_buf;
    s_response_buf = NULL;
    *out_len = s_response_len;
    return result;
}

// Context struct to pass to the event handler
typedef struct {
    FILE *file;
    size_t total_written;
} download_ctx_t;

static esp_err_t download_event_handler(esp_http_client_event_t *evt)
{
    download_ctx_t *ctx = (download_ctx_t *)evt->user_data;

    switch (evt->event_id) {
    case HTTP_EVENT_ON_DATA:
        if (ctx->file && evt->data_len > 0) {
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
    if (!f) {
        printf("eget: cannot create file\n");
        return -1;
    }

    download_ctx_t ctx = { .file = f, .total_written = 0 };

    esp_http_client_config_t config = {
        .url = url,
        .event_handler = download_event_handler,
        .user_data = &ctx,
        .crt_bundle_attach = esp_crt_bundle_attach,
        .timeout_ms = 60000,
        .max_redirection_count = 5,

        .buffer_size = 4096,     // Rx Buffer: Standard size is usually fine
        .buffer_size_tx = 2048,  // Tx Buffer: Increased to hold long AWS URLs
    };

    esp_http_client_handle_t client = esp_http_client_init(&config);
    if (!client) {
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

    if (err != ESP_OK || status != 200) {
        printf("\neget: download failed (err=%d, status=%d)\n", err, status);
        unlink(dest_path); // Delete partial file
        return -1;
    }

    printf("  Success (%u bytes)\n", (unsigned)ctx.total_written);
    return 0;
}

// Remove .elf extension from filename
static void strip_elf_ext(const char *name, char *out, size_t out_size)
{
    strncpy(out, name, out_size - 1);
    out[out_size - 1] = '\0';
    
    size_t len = strlen(out);
    if (len > 4 && strcasecmp(out + len - 4, ".elf") == 0) {
        out[len - 4] = '\0';
    }
}

int cmd_eget(int argc, char **argv)
{
    if (argc < 2) {
        printf("Usage: eget <user/repo>\n");
        printf("  Downloads .elf files from latest GitHub release to %s/\n", BIN_DIR);
        return 1;
    }
    
    const char *repo = argv[1];
    
    // Validate repo format
    if (strchr(repo, '/') == NULL || repo[0] == '/' || repo[strlen(repo)-1] == '/') {
        printf("eget: invalid repo format, use 'user/repo'\n");
        return 1;
    }
    
    // Create bin directory if it doesn't exist
    mkdir(BIN_DIR, 0755);
    
    // Build API URL
    char url[MAX_URL_LEN];
    snprintf(url, sizeof(url), "https://api.github.com/repos/%s/releases/latest", repo);
    
    printf("Fetching %s...\n", repo);
    
    // Fetch release info
    int len;
    char *json = fetch_json(url, &len);
    if (!json) {
        printf("eget: failed to fetch release info\n");
        return 1;
    }
    
    // Parse JSON
    cJSON *root = cJSON_Parse(json);
    free(json);
    
    if (!root) {
        printf("eget: failed to parse response\n");
        return 1;
    }
    
    // Check for error message (e.g., rate limit, not found)
    cJSON *message = cJSON_GetObjectItem(root, "message");
    if (message && cJSON_IsString(message)) {
        printf("eget: %s\n", message->valuestring);
        cJSON_Delete(root);
        return 1;
    }
    
    // Get tag name
    cJSON *tag = cJSON_GetObjectItem(root, "tag_name");
    if (tag && cJSON_IsString(tag)) {
        printf("Latest release: %s\n", tag->valuestring);
    }
    
    // Get assets array
    cJSON *assets = cJSON_GetObjectItem(root, "assets");
    if (!assets || !cJSON_IsArray(assets)) {
        printf("eget: no assets in release\n");
        cJSON_Delete(root);
        return 1;
    }
    
    // Find and download .elf files
    int downloaded = 0;
    int count = cJSON_GetArraySize(assets);
    
    for (int i = 0; i < count; i++) {
        cJSON *asset = cJSON_GetArrayItem(assets, i);
        cJSON *name = cJSON_GetObjectItem(asset, "name");
        cJSON *download_url = cJSON_GetObjectItem(asset, "browser_download_url");
        
        if (!name || !cJSON_IsString(name) || !download_url || !cJSON_IsString(download_url)) {
            continue;
        }
        
        const char *asset_name = name->valuestring;
        size_t name_len = strlen(asset_name);
        
        // Check if it's an .elf file
        if (name_len < 5 || strcasecmp(asset_name + name_len - 4, ".elf") != 0) {
            continue;
        }
        
        printf("Found: %s\n", asset_name);
        
        // Build destination path
        char bin_name[64];
        strip_elf_ext(asset_name, bin_name, sizeof(bin_name));
        
        char dest_path[128];
        snprintf(dest_path, sizeof(dest_path), "%s/%s", BIN_DIR, bin_name);
        
        // Download the file
        if (download_file(download_url->valuestring, dest_path) == 0) {
            downloaded++;
        }
    }
    
    cJSON_Delete(root);
    
    if (downloaded == 0) {
        printf("eget: no .elf files found in release\n");
        return 1;
    }
    
    printf("Done. Installed %d binary(s) to %s/\n", downloaded, BIN_DIR);
    return 0;
}