/*
 * breezy_http.c - HTTP helper functions for ELF apps
 *
 * Provides simple wrappers that hide ESP-IDF struct complexity.
 */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "esp_http_client.h"
#include "esp_crt_bundle.h"
#include "esp_netif.h"
#include "breezybox.h"

/* Check if we have network connectivity */
static int check_network(void)
{
    esp_netif_t *netif = esp_netif_get_default_netif();
    if (!netif) {
        return 0;
    }
    esp_netif_ip_info_t ip_info;
    if (esp_netif_get_ip_info(netif, &ip_info) != ESP_OK) {
        return 0;
    }
    return ip_info.ip.addr != 0;
}

/* Download context */
typedef struct {
    FILE *file;
    size_t total;
} dl_ctx_t;

static esp_err_t download_handler(esp_http_client_event_t *evt)
{
    dl_ctx_t *ctx = (dl_ctx_t *)evt->user_data;

    if (evt->event_id == HTTP_EVENT_ON_DATA) {
        if (ctx->file && evt->data_len > 0) {
            size_t written = fwrite(evt->data, 1, evt->data_len, ctx->file);
            ctx->total += written;
        }
    }
    return ESP_OK;
}

int breezy_http_download(const char *url, const char *dest_path)
{
    if (!url || !dest_path) {
        return -1;
    }

    if (!check_network()) {
        return -2;  /* No network */
    }

    FILE *f = fopen(dest_path, "wb");
    if (!f) {
        return -1;
    }

    dl_ctx_t ctx = { .file = f, .total = 0 };

    esp_http_client_config_t config = {
        .url = url,
        .event_handler = download_handler,
        .user_data = &ctx,
        .crt_bundle_attach = esp_crt_bundle_attach,
        .timeout_ms = 30000,
        .max_redirection_count = 5,
        .buffer_size = 4096,
        .buffer_size_tx = 2048,
    };

    esp_http_client_handle_t client = esp_http_client_init(&config);
    if (!client) {
        fclose(f);
        unlink(dest_path);
        return -1;
    }

    esp_http_client_set_header(client, "User-Agent", "ESP32-BreezyBox");

    esp_err_t err = esp_http_client_perform(client);
    int status = esp_http_client_get_status_code(client);

    esp_http_client_cleanup(client);
    fclose(f);

    if (err != ESP_OK || (status != 200 && status != 0)) {
        unlink(dest_path);
        return -1;
    }

    return 0;
}
