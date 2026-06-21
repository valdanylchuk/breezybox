#include "ssh_server.h"
#include "esp_err.h"
#include "esp_netif.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Returns true if at least one network interface has a non-zero IP address.
static bool network_has_ip(void)
{
    esp_netif_t *netif = NULL;
    while ((netif = esp_netif_next_unsafe(netif)) != NULL) {
        esp_netif_ip_info_t ip;
        if (esp_netif_get_ip_info(netif, &ip) == ESP_OK && ip.ip.addr != 0) {
            return true;
        }
    }
    return false;
}

// Usage: sshd [start [port] | stop | status]
int cmd_sshd(int argc, char **argv)
{
    const char *subcmd = (argc > 1) ? argv[1] : "start";

    if (strcmp(subcmd, "stop") == 0) {
        if (!ssh_server_running()) {
            printf("SSH server is not running\n");
            return 1;
        }
        ssh_server_stop();
        printf("SSH server stopped\n");
        return 0;
    }

    if (strcmp(subcmd, "status") == 0) {
        printf("SSH server: %s\n", ssh_server_running() ? "running" : "stopped");
        return 0;
    }

    if (strcmp(subcmd, "start") == 0 || argc == 1) {
        if (ssh_server_running()) {
            printf("SSH server already running\n");
            return 1;
        }
        if (!network_has_ip()) {
            printf("No network connection. Connect to WiFi first (use 'wifi').\n");
            return 1;
        }
        int port = 22;
        if (argc > 2) {
            port = atoi(argv[2]);
            if (port <= 0 || port > 65535) {
                printf("Invalid port: %s\n", argv[2]);
                return 1;
            }
        }
        esp_err_t err = ssh_server_start(port);
        if (err != ESP_OK) {
            printf("Failed to start SSH server: %s\n", esp_err_to_name(err));
            return 1;
        }
        return 0;
    }

    printf("Usage: sshd [start [port] | stop | status]\n");
    return 1;
}
