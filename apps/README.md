# BreezyBox apps
These are some ELF apps compatible with [BreezyBox](https://github.com/valdanylchuk/breezybox) shell running on ESP32-S3.

Some can also be compiled with gcc to run on POSIX-compatible systems, e.g. Mac OS:

- [plasma](plasma/) - ANSI console full-screen "plasma" effect
- [termbench](termbench/) - small vterm benchmark
- [vi](vi/) - minimal vi clone

Some depend on specific exports being available from your ESP-IDF firmware, usually via BreezyBox:

- [gzip](gzip/gzip.c) - gzip compressor
- [gunzip](gzip/gunzip.c) - gzip decompressor
- [wget](wget/) - minimal wget downloader clone

## Installation in BreezyBox
(for the whole bundle):
```
eget valdanylchuk/breezyapps
```

## Building from source

POSIX versions for your Mac can be built literally like this:

```
gcc vi.c
```

For ESP32 builds, there is usually buildelf.sh included, with the build commands I used. You will need xtensa-esp32s3-elf-gcc from the xtensa-esp-elf toolkit. [Espressif IDF Tools documentation](https://docs.espressif.com/projects/esp-idf/en/stable/esp32/api-guides/tools/idf-tools.html) provides a good starting point on where to get and how to install that.

You do not need a full ESP-IDF CMakeLists.txt and idf.py based setup for this.

## More BreezyBox apps elsewhere:

- [xcc700](https://github.com/valdanylchuk/xcc700) - mini C compiler

## Contributing: help wanted!

The best help right now is to try out the system, and publish more examples. Even if you just blink a LED, or print some ASCII art, or vibe-code a text mode game, those are all valuable additions to the ecosystem right now. It would be great to demonstrate that it is an open platform with multiple repositories, by multiple developers, easy to get into and publish your own stuff, without asking or waiting for anyone's approval.

I will link some featured apps/repos here. Or if some app makes sense to include in this specific repo, we can discuss that.

Also if you can share your full firmware project like I did with [my BreezyBox demo](https://github.com/valdanylchuk/breezydemo/), please do so. More full examples working on different dev boards, with different displays (or headless), can help others to get started.

## License
This is free software under [MIT License](LICENSE).