# BreezyBox demo for Tanmatsu Cyberdeck (ESP32-P4)

BreezyBox demo that runs on [Tanmatsu](https://nicolaielectronics.nl/tanmatsu/),
the coolest commercially available cyberdeck handheld, as of June 2026!

*Sponsorship disclosure:* Test device was generously supplied by the developer,
Nicolai Electronics. Thank you!

## Technical details

- ESP32-P4 MCU
- 800x480 display
- Built-in keyboard
- WiFi radio on a separate ESP32-C6 (reached over esp-hosted)

This is a port of the ESP32-S3 [breezydemo](https://github.com/valdanylchuk/breezydemo).
The BreezyBox shell and the `breezy_term` virtual terminal are reused unchanged;
only the **display** and **keyboard** are board-specific, and the **WiFi** radio
lives on the C6 instead of the main chip.

## What works (MVP)

- BreezyBox shell on the built-in display + keyboard
- Core commands: `ls`, `cat`, `mkdir`, `cp`, `mv`, `rm`, `head`, `tail`, `more`,
  `wc`, `df`, `du`, `date`, plus running ELF apps from the LittleFS `storage`
  partition
- A parallel **USB-Serial-JTAG console** (logs + a second shell) for debugging
- Multiple virtual terminals (switch with the `vt` command)
- Custom commands: `vt`, `keytest`, `colortest`, `setcon`, `netup`

Text-only for now: the S3 demo's VGA/graphics mode and the BT keyboard are not
ported. WiFi networking is wired but **off by default** (see Phase 2 below).

## Architecture / what changed vs. the S3 demo

| Concern        | S3 demo                         | This P4 port                                   |
|----------------|---------------------------------|------------------------------------------------|
| Display        | `breezy_rgb_lcd` (RGB parallel) | new `breezy_tanmatsu_lcd` → `bsp_display_blit` |
| Keyboard       | Bluetooth HID (`breezy_bt`)     | built-in keyboard via `badge-bsp` input queue  |
| Terminal       | `breezy_term` (vterm)           | `breezy_term` (vterm), unchanged               |
| Grid size      | 128×37                          | 100×30 (800×480 / 8×16 Terminus font)          |
| WiFi           | native `esp_wifi` on-chip       | C6 radio via esp-hosted + `esp_wifi_remote`    |
| Shell / ELF    | `breezybox` + `elf_loader`      | same, recompiled for P4 (RISC-V)               |

Local components live in `components/`. The display backend
(`breezy_tanmatsu_lcd`) renders vterm cells into a PSRAM RGB888 framebuffer and
blits it via badge-bsp ~30 fps (only when the screen changes).

### One change to a shared component

`breezy_term`'s grid was hard-coded to 128×37. It is now configurable via
`CONFIG_VTERM_COLS` / `CONFIG_VTERM_ROWS` (defaults preserve 128×37, so the S3
demo is unaffected). This project sets 100×30 in `sdkconfig.defaults`, and pulls
the in-tree `breezy_term` via `override_path` in `main/idf_component.yml`.

## Building

Requires ESP-IDF **5.5.x** with the ESP32-P4 toolchain.

```bash
idf.py set-target esp32p4
idf.py build
idf.py -p <PORT> flash monitor
```

The top-level `CMakeLists.txt` pulls the in-tree `breezybox` component via
`EXTRA_COMPONENT_DIRS "../.."`. Other dependencies (`badge-bsp`, `breezy_term`,
the Tanmatsu WiFi stack) come from the component registry via
`main/idf_component.yml`.

Flashing this firmware replaces the native launcher while you test; re-flash the
launcher to switch back. The C6 radio firmware is **not** touched.

## Phase 2: WiFi networking (over the C6)

Networking is compiled in (so `wifi` / `httpd` / `eget` link) but the radio is
brought up on demand:

```
> netup                  # powers the C6 radio into application mode + esp_wifi_remote
> wifi <ssid> <password> # connect (breezybox's built-in command)
> eget http://...        # download a file
> httpd                  # serve the filesystem
```

`netup` mirrors the launcher's bring-up (`bsp_power_set_radio_state(APPLICATION)`
+ `wifi_remote_initialize()`), see `main/net_bringup.c`. The esp-hosted SDIO pins
and C6 slave config are set in `sdkconfig.defaults`, copied from the native
launcher.

## ELF apps on P4

The `elf_loader`'s built-in libc + ESP-IDF symbol tables are correct for the P4,
so downloaded ELF apps resolve standard symbols out of the box. To export
project-specific functions (e.g. the display API) to ELF apps, generate a P4
customer symbol table — see `main/all_my_symbols.c.p4-template`. Do **not** reuse
the S3 demo's generated table; it contains Xtensa-only symbols.

## Status / validation notes

This MVP was ported by careful reference to the S3 demo, the `breezy_term` /
`breezybox` sources, and the Tanmatsu native launcher (for the exact badge-bsp
and esp-hosted APIs). It has **not** yet been built or run on hardware here, so
expect to validate/tune on-device. Most likely spots:

- **Color byte order** in `breezy_tanmatsu_lcd` (RGB vs BGR / endianness) — if
  red and blue look swapped, flip the order in `rebuild_palette_out()`.
- **Dependency versions** in `main/idf_component.yml` are loose (`"*"`) — pin them
  to match your installed IDF / registry if resolution complains.
- **WiFi bring-up** (`net_bringup.c`) — the `wifi_remote` API/version may need a
  small tweak to match your IDF.
- **Function-key / VT-switch hotkeys** from the physical keyboard are not mapped;
  use the `vt` command for now.
