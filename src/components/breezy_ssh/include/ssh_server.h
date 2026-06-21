#pragma once
#include "esp_err.h"
#include <stdbool.h>
#include <stddef.h>
#include <sys/types.h>

// ---------------------------------------------------------------------------
// breezy_ssh - leaf-level SSH server component.
//
// The component owns the SSH transport and a tiny line shell. Everything that
// is specific to the host firmware (how to run a command, how to route a child
// program's stdio to the SSH channel, how to report the terminal size) is
// injected through breezy_ssh_host_t. The component has no compile-time
// dependency on the rest of BreezyBox.
// ---------------------------------------------------------------------------

// Raw stdio routing callbacks. The component supplies these implementations;
// the host installs them for the current (SSH server) task so that a child
// program's write(STDOUT_FILENO,...) / read(STDIN_FILENO,...) reach the SSH
// channel instead of the local console.
typedef ssize_t (*ssh_io_write_fn)(int fd, const void *data, size_t size);
typedef ssize_t (*ssh_io_read_fn)(int fd, void *data, size_t size);

// Host integration hooks. Only exec_line is required; the rest are optional
// and may be NULL, in which case the corresponding feature degrades cleanly:
//   - no set_io_override  => printf-level command output still works, but raw
//                            fd apps (TUIs like vi) won't render.
//   - no is_fd_nonblock   => reads are treated as blocking-with-timeout.
//   - no set_term_size    => apps fall back to their own default size.
typedef struct {
    // Required: execute one shell command line; return its exit code.
    int  (*exec_line)(const char *line);

    // Optional: install/remove the raw-stdio routing for the current task.
    void (*set_io_override)(ssh_io_write_fn write_fn, ssh_io_read_fn read_fn);
    void (*clear_io_override)(void);

    // Optional: query whether fd is in non-blocking (O_NONBLOCK) mode.
    int  (*is_fd_nonblock)(int fd);

    // Optional: report / clear the SSH-negotiated terminal size for child apps.
    void (*set_term_size)(int rows, int cols);
    void (*clear_term_size)(void);
} breezy_ssh_host_t;

// Install host integration hooks. The struct is copied. Pass NULL to clear.
// Call before ssh_server_start() (or before the first connection).
void ssh_server_set_host(const breezy_ssh_host_t *host);

// Start SSH server in a background task.
// Default credentials: breezy / breezy
esp_err_t ssh_server_start(int port);

// Stop the server. Forcefully terminates the server task (PoC limitation).
void ssh_server_stop(void);

bool ssh_server_running(void);
