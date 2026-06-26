# BreezyBox

A BusyBox-inspired shell and virtual terminal system for ESP32.

Also components, ELF apps, and full firmware project examples for it.

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
- **Extensible**: Easy to extend with custom commands, components, and apps

## Firmware project examples

- [Waveshare ESP32-S3-Touch-LCD-7B 1024x600](examples/s3-waveshare/) - most detailed, with demo video
- [Tanmatsu Handheld ESP32-P4 800x480](examples/p4-tanmatsu/)
- [headless sshd demo S3](examples/ssh/)
- [vterm and BT init on C3](examples/parts_c3/)
- [basic syntax headless](examples/basic/)
- [Community project: Cardputer](https://github.com/chrisdiana/breezybox-cardputer)

## Components

I try to keep BreezyBox modular, so some components can be reused separately.

- [breezybox](src/components/breezybox/) - command shell, VFS integration
- [breezy_term](src/components/breezy_term/) - vterm
- [breezy_bt](src/components/breezy_bt/) - Bluetooth keyboard
- [breezy_ssh](src/components/breezy_ssh/) - basic sshd
- [breezy_rgb_lcd](src/components/breezy_rgb_lcd/)

## ELF Apps

1. See some [ELF apps under apps/](apps/): vi, wget, gzip/gunzip, termbench, plasma

You can install all of them on your BreezyBox device with this command:

    eget valdanylchuk/breezybox

2. Some apps in separate repositories:

- [valdanylchuk/ccleste](https://github.com/valdanylchuk/ccleste) - Celeste Classic port with Scrolleste merged scrollable map
- [valdanylchuk/xcc700](https://github.com/valdanylchuk/xcc700) - Mini C compiler for ESP32 / Xtensa (S3)
- [valdanylchuk/rcc700](https://github.com/valdanylchuk/rcc700) - Mini C compiler for ESP32 / RISC-V (P4)

## License

This is free software under MIT License - see [LICENSE](LICENSE) file.

## Contributing - help wanted!

The best help is currently more testing on different devices, more shared examples and fun use cases:

1. More ELF apps – see the [ELF app examples in apps/](apps/), they are super easy to follow. Even a carefully written stdlib C program with no platform-specific bits may work sometimes, also with some ANSI codes. But be sure to verify on the actual ESP32: the memory is tight, the larger PSRAM requires alignment, and there are other limits and quirks. You can publish and install the apps using your own repo.

2. More full firmware repositories: for different boards, with different styles. Maybe you provide the basic LVGL text label example on some popular board. Maybe you prefer C++ to plain C. Maybe you embrace the GUI. Maybe you port some retro games. Maybe you attach some cool gadgets to it. Maybe you build an extra cool cyberdeck case. Or maybe you reproduce the exact same thing, and just share your setup experience and hands-on impressions.

It would be so cool to see more people using BreezyBox, and to have more ready-to-clone examples for everyone!

Have fun!