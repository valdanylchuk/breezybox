#include "breezy_cmd.h"
#include "breezy_vfs.h"
#include "esp_http_server.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>

#define MAX_URI_LEN 128
#define MAX_FILEPATH (BREEZYBOX_MAX_PATH + MAX_URI_LEN + 2)

static char s_base_path[BREEZYBOX_MAX_PATH + 1];
static httpd_handle_t s_server = NULL;

static esp_err_t get_handler(httpd_req_t *req)
{
    char filepath[MAX_FILEPATH];
    const char *uri = req->uri;
    
    // Skip leading slash for path joining
    if (uri[0] == '/') uri++;
    
    // Build full path
    if (uri[0] == '\0') {
        strncpy(filepath, s_base_path, sizeof(filepath) - 1);
        filepath[sizeof(filepath) - 1] = '\0';
    } else {
        snprintf(filepath, sizeof(filepath), "%.128s/%.127s", s_base_path, uri);
    }

    printf("GET %s -> %s\n", req->uri, filepath);

    struct stat st;
    if (stat(filepath, &st) != 0) {
        printf("  404 Not Found\n");
        httpd_resp_send_err(req, HTTPD_404_NOT_FOUND, "File not found");
        return ESP_FAIL;
    }

    // If directory, list contents
    if (S_ISDIR(st.st_mode)) {
        httpd_resp_set_type(req, "text/html");
        httpd_resp_sendstr_chunk(req, "<html><body><pre>\n");
        
        DIR *dir = opendir(filepath);
        if (dir) {
            struct dirent *entry;
            while ((entry = readdir(dir)) != NULL) {
                if (entry->d_name[0] == '.') continue;
                
                char line[256];
                char entry_path[MAX_FILEPATH];
                snprintf(entry_path, sizeof(entry_path), "%.128s/%.64s", filepath, entry->d_name);
                
                struct stat est;
                const char *suffix = "";
                long size = 0;
                if (stat(entry_path, &est) == 0) {
                    if (S_ISDIR(est.st_mode)) suffix = "/";
                    else size = est.st_size;
                }
                
                snprintf(line, sizeof(line), 
                    "<a href=\"%.64s%s%.32s\">%.32s%s</a>  %ld\n",
                    req->uri, 
                    (req->uri[strlen(req->uri)-1] == '/') ? "" : "/",
                    entry->d_name,
                    entry->d_name, suffix, size);
                httpd_resp_sendstr_chunk(req, line);
            }
            closedir(dir);
        }
        
        httpd_resp_sendstr_chunk(req, "</pre></body></html>");
        httpd_resp_sendstr_chunk(req, NULL);
        printf("  200 OK (dir listing)\n");
        return ESP_OK;
    }

    // Serve file
    FILE *f = fopen(filepath, "r");
    if (!f) {
        printf("  403 Forbidden\n");
        httpd_resp_send_err(req, HTTPD_403_FORBIDDEN, "Cannot open file");
        return ESP_FAIL;
    }

    // Set content type based on extension
    const char *ext = strrchr(filepath, '.');
    if (ext) {
        if (strcasecmp(ext, ".html") == 0 || strcasecmp(ext, ".htm") == 0)
            httpd_resp_set_type(req, "text/html");
        else if (strcasecmp(ext, ".txt") == 0 || strcasecmp(ext, ".sh") == 0 ||
                 strcasecmp(ext, ".c") == 0 || strcasecmp(ext, ".h") == 0)
            httpd_resp_set_type(req, "text/plain");
        else if (strcasecmp(ext, ".json") == 0)
            httpd_resp_set_type(req, "application/json");
        else
            httpd_resp_set_type(req, "application/octet-stream");
    } else {
        httpd_resp_set_type(req, "application/octet-stream");
    }

    char buf[256];
    size_t read_bytes;
    while ((read_bytes = fread(buf, 1, sizeof(buf), f)) > 0) {
        httpd_resp_send_chunk(req, buf, read_bytes);
    }
    httpd_resp_send_chunk(req, NULL, 0);
    fclose(f);

    printf("  200 OK (%ld bytes)\n", st.st_size);
    return ESP_OK;
}

static esp_err_t put_handler(httpd_req_t *req)
{
    char filepath[MAX_FILEPATH];
    const char *uri = req->uri;
    
    if (uri[0] == '/') uri++;
    
    if (uri[0] == '\0') {
        httpd_resp_send_err(req, HTTPD_400_BAD_REQUEST, "Filename required");
        return ESP_FAIL;
    }
    
    snprintf(filepath, sizeof(filepath), "%.128s/%.127s", s_base_path, uri);
    
    printf("PUT %s -> %s (%d bytes)\n", req->uri, filepath, req->content_len);

    FILE *f = fopen(filepath, "w");
    if (!f) {
        printf("  500 Cannot create file\n");
        httpd_resp_send_err(req, HTTPD_500_INTERNAL_SERVER_ERROR, "Cannot create file");
        return ESP_FAIL;
    }

    char buf[256];
    int remaining = req->content_len;
    int received;
    
    while (remaining > 0) {
        int to_read = (remaining < (int)sizeof(buf)) ? remaining : (int)sizeof(buf);
        received = httpd_req_recv(req, buf, to_read);
        
        if (received <= 0) {
            if (received == HTTPD_SOCK_ERR_TIMEOUT) continue;
            fclose(f);
            printf("  500 Receive error\n");
            httpd_resp_send_err(req, HTTPD_500_INTERNAL_SERVER_ERROR, "Receive error");
            return ESP_FAIL;
        }
        
        fwrite(buf, 1, received, f);
        remaining -= received;
    }
    
    fclose(f);
    httpd_resp_sendstr(req, "OK\n");
    printf("  201 Created\n");
    return ESP_OK;
}

static esp_err_t delete_handler(httpd_req_t *req)
{
    char filepath[MAX_FILEPATH];
    const char *uri = req->uri;
    
    if (uri[0] == '/') uri++;
    
    if (uri[0] == '\0') {
        httpd_resp_send_err(req, HTTPD_400_BAD_REQUEST, "Filename required");
        return ESP_FAIL;
    }
    
    snprintf(filepath, sizeof(filepath), "%.128s/%.127s", s_base_path, uri);
    
    printf("DELETE %s -> %s\n", req->uri, filepath);

    if (remove(filepath) != 0) {
        printf("  404 Not Found\n");
        httpd_resp_send_err(req, HTTPD_404_NOT_FOUND, "File not found");
        return ESP_FAIL;
    }

    httpd_resp_sendstr(req, "Deleted\n");
    printf("  200 OK\n");
    return ESP_OK;
}

int cmd_httpd(int argc, char **argv)
{
    const char *dir = (argc > 1) ? argv[1] : ".";
    int port = 80;
    
    // Parse -p port
    for (int i = 1; i < argc - 1; i++) {
        if (strcmp(argv[i], "-p") == 0) {
            port = atoi(argv[i + 1]);
            if (port <= 0 || port > 65535) {
                printf("Invalid port\n");
                return 1;
            }
        }
    }
    
    // Resolve directory path
    if (dir[0] != '/') {
        breezybox_resolve_path(dir, s_base_path, sizeof(s_base_path));
    } else {
        strncpy(s_base_path, dir, sizeof(s_base_path) - 1);
    }
    
    // Verify directory exists
    struct stat st;
    if (stat(s_base_path, &st) != 0 || !S_ISDIR(st.st_mode)) {
        printf("Not a directory: %s\n", s_base_path);
        return 1;
    }

    httpd_config_t config = HTTPD_DEFAULT_CONFIG();
    config.server_port = port;
    config.uri_match_fn = httpd_uri_match_wildcard;
    config.max_uri_handlers = 8;
    config.stack_size = 8192;  // Increase from default 4096

    if (httpd_start(&s_server, &config) != ESP_OK) {
        printf("Failed to start server\n");
        return 1;
    }

    // Register wildcard handlers
    httpd_uri_t get_uri = {
        .uri = "/*",
        .method = HTTP_GET,
        .handler = get_handler,
    };
    httpd_uri_t put_uri = {
        .uri = "/*",
        .method = HTTP_PUT,
        .handler = put_handler,
    };
    httpd_uri_t delete_uri = {
        .uri = "/*",
        .method = HTTP_DELETE,
        .handler = delete_handler,
    };
    
    httpd_register_uri_handler(s_server, &get_uri);
    httpd_register_uri_handler(s_server, &put_uri);
    httpd_register_uri_handler(s_server, &delete_uri);

    printf("Serving %s on port %d\n", s_base_path, port);
    printf("Press Enter to stop...\n\n");

    // Wait for Enter key
    int c;
    while ((c = getchar()) != '\n' && c != '\r') {
        if (c == EOF) {
            vTaskDelay(pdMS_TO_TICKS(100));
        }
    }

    httpd_stop(s_server);
    s_server = NULL;
    printf("\nServer stopped\n");
    
    return 0;
}