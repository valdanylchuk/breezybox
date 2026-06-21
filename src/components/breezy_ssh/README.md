# breezy_ssh

[![Component Registry](https://components.espressif.com/components/valdanylchuk/breezy_ssh/badge.svg)](https://components.espressif.com/components/valdanylchuk/breezy_ssh)

This is the SSH inbound connections component used in [BreezyBox](https://github.com/valdanylchuk/breezybox), a mini shell for esp32-s3.

Integrates [david-cermak/libssh](https://components.espressif.com/components/david-cermak/libssh/) into BreezyBox.

## Features

- Basic ssh inbound connection over wifi works
- Simple CLI commands like "ls" and tiny "Hello World" scale ELF binaries work
- The biggest app tested to work is vi

## Known issues

- Severely limited by main SRAM available
- No meaningful security (default keys, password for use in prototypes)

## Installation

### ESP Component Registry (Recommended)

```bash
idf.py add-dependency "valdanylchuk/breezy_ssh"
```

### Manual Installation

Clone into your project's `components` folder:

```bash
git clone https://github.com/valdanylchuk/breezybox.git
cp -r breezybox/src/components/ your_project/components
```

## Quick Start

`breezy_ssh` is a leaf component: it owns the SSH transport and a tiny line
shell, but knows nothing about your firmware. You inject the host-specific
behaviour through `breezy_ssh_host_t` before starting the server.

Only `exec_line` is required. The other hooks are optional and degrade cleanly
if left `NULL` (see [include/ssh_server.h](include/ssh_server.h)).

```c
#include "ssh_server.h"

// 1. Required: run one command line and return its exit code.
static int host_exec_line(const char *line) {
    return my_shell_exec(line);          // your shell's command runner
}

// 2. Optional: route a child task's raw stdio to the SSH channel so that
//    TUI apps (e.g. vi) render. The component hands you its own write/read.
static int  ssh_write(int fd, const void *d, size_t n) { /* installed below */ }
static void host_set_io(ssh_io_write_fn w, ssh_io_read_fn r) {
    my_console_set_io_override(w, r);    // your console multiplexer
}
static void host_clear_io(void)         { my_console_clear_io_override(); }
static int  host_is_nonblock(int fd)    { return my_console_fd_is_nonblock(fd); }

// 3. Optional: report the SSH-negotiated terminal size to apps.
static void host_set_size(int rows, int cols) { vterm_set_size_override(rows, cols); }
static void host_clear_size(void)             { vterm_clear_size_override(); }

void start_ssh(void) {
    const breezy_ssh_host_t host = {
        .exec_line         = host_exec_line,
        .set_io_override   = host_set_io,
        .clear_io_override = host_clear_io,
        .is_fd_nonblock    = host_is_nonblock,
        .set_term_size     = host_set_size,
        .clear_term_size   = host_clear_size,
    };
    ssh_server_set_host(&host);
    ssh_server_start(22);                 // default creds: breezy / breezy
}
```

A minimal integration that only provides `exec_line` still gives a working
line shell (printf-level command output); raw-fd TUI apps just won't render.

The bundled `cmd_sshd` command (`sshd [start [port] | stop | status]`) can be
registered with your console for interactive control.

## Extended fully working example/demo

[See examples in the BreezyBox project](https://github.com/valdanylchuk/breezybox).

## Dependencies

- ESP-IDF >= 5.0
- david-cermak/libssh 0.11.0

## License

This is free software under MIT License - see [LICENSE](LICENSE) file.
