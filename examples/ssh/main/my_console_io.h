#pragma once

#include "esp_err.h"
#include <stddef.h>
#include <sys/types.h>

// ---------------------------------------------------------------------------
// Minimal USB-Serial-JTAG console for the headless breezy_ssh demo.
//
// It exists for one reason beyond plain stdio: per-task I/O override. An SSH
// session (and the ELF apps it runs, e.g. vi) needs its raw write(1)/read(0)
// routed to the SSH channel instead of the USB console. breezy_ssh installs
// that routing through the override hooks below.
//
// No display, no Bluetooth, no vterm — just USB in/out plus the override.
// ---------------------------------------------------------------------------

// Per-task raw stdio override. While installed for a task, that task's
// read(0)/write(1) go through these instead of the USB console.
typedef struct {
    ssize_t (*write)(int fd, const void *data, size_t size);
    ssize_t (*read)(int fd, void *data, size_t size);
} console_io_override_t;

// Register the console VFS and redirect stdin/stdout/stderr to USB-Serial-JTAG.
// Call once, before starting the breezybox stdio REPL.
esp_err_t my_console_init(void);

// Install / remove the raw-stdio override for the calling task.
void my_console_set_io_override(const console_io_override_t *ovr);
void my_console_clear_io_override(void);

// Whether the given console fd is in non-blocking (O_NONBLOCK) mode.
int  my_console_fd_is_nonblock(int fd);
