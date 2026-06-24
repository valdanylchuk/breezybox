# Parts of BreezyBox running on ESP32-C3

The main problem with C3 is, it is not supported by the Espressif elf_loader:
https://components.espressif.com/components/espressif/elf_loader/
And it is kind of central to the most interesting things that BreezyBox does.

Some Breezy submodules do work on C3. This example imports breezy_term and breezy_bt.
You can make many other things work on it as well, but it is not plug-and-play currently.
