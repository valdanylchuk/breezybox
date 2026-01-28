# BreezyBox

A BusyBox-inspired shell and virtual terminal system for ESP32.

[![Component Registry](https://components.espressif.com/components/valdanylchuk/breezybox/badge.svg)](https://components.espressif.com/components/valdanylchuk/breezybox)

## Features

- **Unix-like Shell**: Familiar commands like `ls`, `cat`, `echo`, `cd`, `pwd`, `cp`, `mv`, `rm`, `mkdir`
- **Virtual Terminals**: Multiple independent terminals with hotkey switching (F1-F4)
- **ANSI Colors**: Full 16-color support with SGR escape sequences
- **I/O Redirection**: Support for `>`, `>>`, `<`, and pipes `|`
- **Script Execution**: Run shell scripts from files with `sh`
- **Tab Completion**: Command completion via linenoise
- **History**: Arrow key navigation through command history
- **WiFi Commands**: `wifi scan`, `wifi connect`, `wifi status`
- **HTTP Server**: Built-in file server with `httpd`
- **ELF Loader**: Download and run programs with `eget`
- **Extensible**: Easy to add custom commands and apps

## Installation

### ESP Component Registry (Recommended)

```bash
idf.py add-dependency "valdanylchuk/breezybox"
```

### Manual Installation

Clone into your project's `components` folder:

```bash
cd your_project/components
git clone https://github.com/valdanylchuk/breezybox.git
```

## Quick Start

```c
#include "breezybox.h"

void app_main(void)
{
    // Initialize your display, filesystem, etc.
    
    // Start BreezyBox shell on stdio
    // (if "hello world" works, this should work)
    breezybox_start_stdio(8192, 5);
    
    // Your app continues running...
}
```

## Extended fully working example/demo

[My BreezyBox-based hobby cyberdeck project](https://github.com/valdanylchuk/breezydemo).

Includes intergration with a custom LCD driver, some custom commands, and a demo video.

See also some [BreezyBox compatible ELF apps here](https://github.com/valdanylchuk/breezyapps).

## Commands

### File Operations
```
ls [path]           - List directory contents
cat <file>          - Display file contents
head [-n N] <file>  - Show first N lines (default 10)
tail [-n N] <file>  - Show last N lines (default 10)
more <file>         - Paginate file contents
wc [-lwc] <file>    - Count lines/words/chars
cp <src> <dst>      - Copy file
mv <src> <dst>      - Move/rename file
rm [-r] <file...>   - Remove file or directory
mkdir <dir>         - Create directory
```

### Navigation
```
cd [path]           - Change directory
pwd                 - Print working directory
```

### System
```
free                - Show memory usage (SRAM/PSRAM)
df                  - Show filesystem space
du [-s] [path]      - Show disk usage
date [datetime]     - Show/set date and time
clear               - Clear screen
sh <script>         - Run shell script
help                - List all commands
```

### Networking
```
wifi scan                    - Scan for WiFi networks
wifi connect <ssid> [pass]   - Connect to WiFi
wifi disconnect              - Disconnect from WiFi
wifi status                  - Show connection status
wifi forget                  - Forget saved network
httpd [dir] [-p port]        - Start HTTP file server
```

### Programs
```
eget <user/repo>    - Download ELF from GitHub releases
app_name            - run app_name ELF file from /root/bin/ or CWD
```

### Built-in
```
echo [text...]      - Print text to stdout
```

## I/O Redirection

```bash
$ echo "Hello" > /root/test.txt    # Write to file
$ echo "World" >> /root/test.txt   # Append to file
$ cat < /root/test.txt             # Read from file
$ ls | head                        # Pipe output
```

## Virtual Terminals

Switch between terminals using:
- **F1-F4**: Switch to VT0-VT3
- **Ctrl+F1-F4**: Switch to VT0-VT3 (alternative)

## Virtual Terminal Integration

BreezyBox includes a virtual terminal (vterm) system with:

- Cell-based screen buffer with character + attribute per cell
- ANSI escape sequence parsing (cursor movement, colors, clear)
- Multiple independent terminals
- Render callback for custom display output

## Adding Custom Commands

```c
#include "esp_console.h"

static int cmd_hello(int argc, char **argv)
{
    printf("Hello, %s!\n", argc > 1 ? argv[1] : "World");
    return 0;
}

// Register in your app
esp_console_cmd_t cmd = {
    .command = "hello",
    .help = "Say hello",
    .hint = "[name]",
    .func = &cmd_hello,
};
esp_console_cmd_register(&cmd);
```

## Dependencies

- ESP-IDF >= 5.0
- [joltwallet/littlefs](https://components.espressif.com/components/joltwallet/littlefs) - Filesystem
- [espressif/elf_loader](https://components.espressif.com/components/espressif/elf_loader) - ELF execution
- PSRAM required for full functionality

## License

This is free software under MIT License - see [LICENSE](LICENSE) file.

## Contributing - help wanted!

This is in early stage with many rough edges. Pull requests are better than bug reports. I know there would be hundreds of bugs if we were to catalog them, an I would never be able to address them all. Top priority for help:

- Make breezybox easy and smooth to install
- Improve the documentation in the repo/Readme; create a Wiki
- Make existing core features more stable without major code bloat

## Acknowledgments

- Inspired by [BusyBox](https://busybox.net/)
- Uses [linenoise](https://github.com/antirez/linenoise) for line editing
- Built for the ESP-IDF framework