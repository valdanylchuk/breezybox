#include "breezy_cmd.h"
#include "esp_wifi.h"
#include "esp_netif.h"
#include "esp_event.h"
#include "nvs_flash.h"
#include "nvs.h"
#include <string.h>
#include <stdio.h>

#define NVS_NAMESPACE "breezy_wifi"
#define NVS_KEY_SSID "ssid"
#define NVS_KEY_PASS "pass"
#define CONNECT_TIMEOUT_MS 15000

static esp_netif_t *s_netif = NULL;
static bool s_wifi_initialized = false;
static volatile bool s_connected = false;
static volatile bool s_got_ip = false;

static const char *auth_mode_str(wifi_auth_mode_t auth)
{
    switch (auth) {
        case WIFI_AUTH_OPEN:            return "OPEN";
        case WIFI_AUTH_WEP:             return "WEP";
        case WIFI_AUTH_WPA_PSK:         return "WPA";
        case WIFI_AUTH_WPA2_PSK:        return "WPA2";
        case WIFI_AUTH_WPA_WPA2_PSK:    return "WPA/2";
        case WIFI_AUTH_WPA3_PSK:        return "WPA3";
        case WIFI_AUTH_WPA2_WPA3_PSK:   return "WPA2/3";
        default:                        return "?";
    }
}

static void event_handler(void *arg, esp_event_base_t base, int32_t id, void *data)
{
    if (base == WIFI_EVENT) {
        switch (id) {
            case WIFI_EVENT_STA_CONNECTED:
                s_connected = true;
                break;
            case WIFI_EVENT_STA_DISCONNECTED:
                s_connected = false;
                s_got_ip = false;
                break;
        }
    } else if (base == IP_EVENT && id == IP_EVENT_STA_GOT_IP) {
        s_got_ip = true;
    }
}

static esp_err_t wifi_init_once(void)
{
    if (s_wifi_initialized) return ESP_OK;

    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        nvs_flash_erase();
        ret = nvs_flash_init();
    }
    if (ret != ESP_OK) return ret;

    ret = esp_netif_init();
    if (ret != ESP_OK) return ret;

    ret = esp_event_loop_create_default();
    if (ret != ESP_OK && ret != ESP_ERR_INVALID_STATE) return ret;

    s_netif = esp_netif_create_default_wifi_sta();
    if (!s_netif) return ESP_FAIL;

    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    ret = esp_wifi_init(&cfg);
    if (ret != ESP_OK) return ret;

    esp_event_handler_register(WIFI_EVENT, ESP_EVENT_ANY_ID, &event_handler, NULL);
    esp_event_handler_register(IP_EVENT, IP_EVENT_STA_GOT_IP, &event_handler, NULL);

    ret = esp_wifi_set_mode(WIFI_MODE_STA);
    if (ret != ESP_OK) return ret;

    ret = esp_wifi_start();
    if (ret != ESP_OK) return ret;

    s_wifi_initialized = true;
    return ESP_OK;
}

// ============ NVS Storage ============

static esp_err_t save_credentials(const char *ssid, const char *password)
{
    nvs_handle_t handle;
    esp_err_t ret = nvs_open(NVS_NAMESPACE, NVS_READWRITE, &handle);
    if (ret != ESP_OK) return ret;

    nvs_set_str(handle, NVS_KEY_SSID, ssid);
    nvs_set_str(handle, NVS_KEY_PASS, password ? password : "");
    nvs_commit(handle);
    nvs_close(handle);
    return ESP_OK;
}

static esp_err_t load_credentials(char *ssid, size_t ssid_len, char *password, size_t pass_len)
{
    nvs_handle_t handle;
    esp_err_t ret = nvs_open(NVS_NAMESPACE, NVS_READONLY, &handle);
    if (ret != ESP_OK) return ret;

    ret = nvs_get_str(handle, NVS_KEY_SSID, ssid, &ssid_len);
    if (ret != ESP_OK) {
        nvs_close(handle);
        return ret;
    }

    nvs_get_str(handle, NVS_KEY_PASS, password, &pass_len);  // OK if missing
    nvs_close(handle);
    return ESP_OK;
}

// ============ Commands ============

static int wifi_scan(void)
{
    if (wifi_init_once() != ESP_OK) {
        printf("WiFi init failed\n");
        return 1;
    }

    wifi_scan_config_t scan_cfg = { .show_hidden = true };
    if (esp_wifi_scan_start(&scan_cfg, true) != ESP_OK) {
        printf("Scan failed\n");
        return 1;
    }

    uint16_t count = 0;
    esp_wifi_scan_get_ap_num(&count);
    if (count == 0) {
        printf("No networks found\n");
        return 0;
    }

    wifi_ap_record_t *records = malloc(count * sizeof(wifi_ap_record_t));
    if (!records) {
        printf("Out of memory\n");
        return 1;
    }

    esp_wifi_scan_get_ap_records(&count, records);

    printf("%-32s  %4s  %s\n", "SSID", "RSSI", "AUTH");
    printf("--------------------------------  ----  ------\n");
    for (int i = 0; i < count; i++) {
        printf("%-32s  %4d  %s\n", 
               records[i].ssid, 
               records[i].rssi, 
               auth_mode_str(records[i].authmode));
    }

    free(records);
    return 0;
}

static int wifi_connect(const char *ssid, const char *password)
{
    if (wifi_init_once() != ESP_OK) {
        printf("WiFi init failed\n");
        return 1;
    }

    char stored_ssid[33] = {0};
    char stored_pass[65] = {0};

    // If no SSID provided, try to load from NVS
    if (!ssid) {
        if (load_credentials(stored_ssid, sizeof(stored_ssid), 
                            stored_pass, sizeof(stored_pass)) != ESP_OK || 
            stored_ssid[0] == '\0') {
            printf("No saved network. Usage: wifi connect <ssid> [password]\n");
            return 1;
        }
        ssid = stored_ssid;
        password = stored_pass[0] ? stored_pass : NULL;
        printf("Using saved network: %s\n", ssid);
    }

    wifi_config_t cfg = {
        .sta = {
            //.threshold.authmode = password ? WIFI_AUTH_WPA_PSK : WIFI_AUTH_OPEN,
            .threshold.authmode = password ? WIFI_AUTH_WPA2_PSK : WIFI_AUTH_OPEN,
            .pmf_cfg = {
                .capable = false,
                .required = false,  // Don't require PMF - improves compatibility
            },
            .listen_interval = 0, // DEBUG
        },
    };
    strncpy((char*)cfg.sta.ssid, ssid, sizeof(cfg.sta.ssid) - 1);
    if (password) {
        strncpy((char*)cfg.sta.password, password, sizeof(cfg.sta.password) - 1);
    }

    s_connected = false;
    s_got_ip = false;

    esp_wifi_disconnect();
    if (esp_wifi_set_config(WIFI_IF_STA, &cfg) != ESP_OK) {
        printf("Invalid config\n");
        return 1;
    }

    printf("Connecting to %s...\n", ssid);
    if (esp_wifi_connect() != ESP_OK) {
        printf("Connect failed\n");
        return 1;
    }

    // Wait for connection + IP
    int elapsed = 0;
    while (elapsed < CONNECT_TIMEOUT_MS) {
        if (s_got_ip) break;
        vTaskDelay(pdMS_TO_TICKS(100));
        elapsed += 100;

        // Show progress
        if (elapsed % 3000 == 0 && elapsed > 0) {
            if (s_connected && !s_got_ip) {
                printf("  Associated, waiting for IP...\n");
            }
        }
    }

    if (s_got_ip) {
        printf("Connected!\n");
        // Save credentials on success (only if user provided them)
        if (ssid != stored_ssid) {
            save_credentials(ssid, password);
        }
        return 0;
    } else if (s_connected) {
        printf("Associated but no IP (DHCP timeout)\n");
        return 1;
    } else {
        printf("Connection failed\n");
        return 1;
    }
}

static int wifi_disconnect_cmd(void)
{
    if (!s_wifi_initialized) {
        printf("WiFi not initialized\n");
        return 1;
    }

    esp_wifi_disconnect();
    s_connected = false;
    s_got_ip = false;
    printf("Disconnected\n");
    return 0;
}

static int wifi_status(void)
{
    if (!s_wifi_initialized) {
        printf("WiFi not initialized\n");
        return 0;
    }

    wifi_ap_record_t ap;
    if (!s_got_ip || esp_wifi_sta_get_ap_info(&ap) != ESP_OK) {
        printf("Not connected\n");
        
        // Show saved network if any
        char saved_ssid[33] = {0};
        char saved_pass[65] = {0};
        if (load_credentials(saved_ssid, sizeof(saved_ssid), 
                            saved_pass, sizeof(saved_pass)) == ESP_OK && 
            saved_ssid[0] != '\0') {
            printf("Saved: %s\n", saved_ssid);
        }
        return 0;
    }

    esp_netif_ip_info_t ip;
    esp_netif_get_ip_info(s_netif, &ip);

    printf("SSID:    %s\n", ap.ssid);
    printf("RSSI:    %d dBm\n", ap.rssi);
    printf("IP:      " IPSTR "\n", IP2STR(&ip.ip));
    printf("Gateway: " IPSTR "\n", IP2STR(&ip.gw));
    printf("Netmask: " IPSTR "\n", IP2STR(&ip.netmask));

    return 0;
}

static int wifi_forget(void)
{
    nvs_handle_t handle;
    esp_err_t ret = nvs_open(NVS_NAMESPACE, NVS_READWRITE, &handle);
    if (ret != ESP_OK) {
        printf("No saved network\n");
        return 0;
    }
    
    nvs_erase_key(handle, NVS_KEY_SSID);
    nvs_erase_key(handle, NVS_KEY_PASS);
    nvs_commit(handle);
    nvs_close(handle);
    printf("Saved network forgotten\n");
    return 0;
}

int cmd_wifi(int argc, char **argv)
{
    if (argc < 2) {
        printf("Usage: wifi <scan|connect|disconnect|status|forget>\n");
        return 1;
    }

    const char *subcmd = argv[1];

    if (strcmp(subcmd, "scan") == 0) {
        return wifi_scan();
    } 
    else if (strcmp(subcmd, "connect") == 0) {
        const char *ssid = (argc > 2) ? argv[2] : NULL;
        const char *pass = (argc > 3) ? argv[3] : NULL;
        return wifi_connect(ssid, pass);
    } 
    else if (strcmp(subcmd, "disconnect") == 0) {
        return wifi_disconnect_cmd();
    } 
    else if (strcmp(subcmd, "status") == 0) {
        return wifi_status();
    }
    else if (strcmp(subcmd, "forget") == 0) {
        return wifi_forget();
    }
    else {
        printf("Unknown: %s\n", subcmd);
        return 1;
    }
}