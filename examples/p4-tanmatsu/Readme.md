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

## What works

- BreezyBox shell on the built-in display + keyboard
- Core commands: `ls`, `cat`, `mkdir`, `cp`, `mv`, `rm`, `head`, `tail`, `more`,
  `wc`, `df`, `du`, `date`, plus running ELF apps from the LittleFS `storage`
  partition
- A parallel **USB-Serial-JTAG console** (logs + a second shell) for debugging
- Multiple virtual terminals (switch with the `vt` command)
- Custom commands: `vt`, `keytest`, `colortest`, `setcon`, `netup`, `testgfx`
- **Graphics + extended display modes** (ported from the S3 demo): an 8bpp
  indexed framebuffer with mode switching (`SM_VGA13H` 320×200, `SM_150P`
  256×150), a 256-color VGA palette, `rgb_gfx_*` drawing primitives and emulated
  vsync — all exported to ELF apps. See **Graphics** below.

The BT keyboard is still not ported (the built-in keyboard is used instead), so
games that poll raw HID key state (e.g. ccleste) need an input shim that is not
done yet. WiFi networking is wired but **off by default** (see Phase 2 below).

## Graphics

The display backend `breezy_tanmatsu_lcd` renders both text (vterm cells) and an
8bpp indexed graphics framebuffer. In graphics mode the render task upscales the
small framebuffer by an integer factor, palettizes it through the 256-color VGA
palette, centers it (black border) and rotates it into the native panel buffer —
the same blit path the text renderer uses. On the 800×480 panel: VGA13h scales
2× (640×400), 150P scales 3× (768×450).

ELF apps link the same `rgb_display_*` / `rgb_gfx_*` ABI as on the S3 demo, so
the reference graphics apps run unchanged. The reference apps in
[`reference/p4apps`](reference/p4apps) map as follows:

| App        | Needs                                                            |
|------------|-----------------------------------------------------------------|
| `gfx150`   | `rgb_display_set_mode(SM_150P)` + `rgb_display_get_framebuffer`  |
| `testgfx`  | built in as the `testgfx` command (`rgb_display_*` + `rgb_gfx_*`)|
| `plasma`   | text-mode effect: `vterm_set_palette` + `my_display_refresh_palette` |
| termbench/vi/wget/gzip | exec + stdio + the libc/zlib/vterm symbols (no graphics) |

`my_display_refresh_palette()` pushes the live vterm palette to the LCD and
redraws — apps call it after `vterm_set_palette()` to make a palette change
visible without rewriting cells.

Try it on device without flashing an app:

```
> testgfx            # bouncing rainbow rectangles in VGA 320x200, ~6s
> testgfx -t 15      # run for 15 seconds
> testgfx -v         # pace to emulated vsync
```

## Architecture / what changed vs. the S3 demo

| Concern        | S3 demo                         | This P4 port                                   |
|----------------|---------------------------------|------------------------------------------------|
| Display        | `breezy_rgb_lcd` (RGB parallel) | new `breezy_tanmatsu_lcd` → `bsp_display_blit` (text **and** graphics) |
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
so downloaded ELF apps resolve standard symbols out of the box. Project-specific
functions (the `rgb_display_*` / `rgb_gfx_*` graphics ABI, `my_display_refresh_palette`,
`vterm_*`, zlib, `breezy_http_download`, …) are exported via a **customer symbol
table** generated from the firmware ELF.

How the export works:

1. Functions are force-linked into the firmware so `--gc-sections` keeps them:
   - the graphics ABI by an anchor in `tanmatsu_lcd_init()`
     (`components/breezy_tanmatsu_lcd/tanmatsu_lcd.c`),
   - the demo glue (`vTaskDelayUntil`, `my_display_refresh_palette`, `__floatundidf`)
     by `breezy_p4_export_symbols()` in `main/elf_extras.c`.
   Both use a *volatile sink* — `(void)array` does **not** survive `-O2`.
2. After building, regenerate the table from the firmware ELF. It lands in
   `managed_components/espressif__elf_loader/src/esp_all_symbol.c` (gitignored, so
   the committed reference copy is `main/all_my_symbols.c`).

```bash
idf.py build

# symbols.py shells out to bare `nm`/`readelf`; point them at the RISC-V tools.
TC=$HOME/.espressif/tools/riscv32-esp-elf/*/riscv32-esp-elf/bin
SHIM=$(mktemp -d); ln -s $TC/riscv32-esp-elf-nm $SHIM/nm
ln -s $TC/riscv32-esp-elf-readelf $SHIM/readelf; export PATH="$SHIM:$PATH"

python managed_components/espressif__elf_loader/tool/symbols.py \
    -t e -i build/breezy_tanmatsu.elf \
    --exclude elf_find_sym elf_find_sym_default esp_elf_find_symbol

idf.py build          # relink with the updated table
cp managed_components/espressif__elf_loader/src/esp_all_symbol.c main/all_my_symbols.c
```

Notes:
- `--type e` names the array `g_customer_elfsyms` (what the loader expects). Do
  **not** pass `--output-file`; it would rename the array after the basename.
- The `--exclude` list drops the loader's own functions, which are declared as
  functions in the loader headers and would clash with the generated
  `extern int …;` declarations.
- Do **not** reuse the S3 demo's generated table; it contains Xtensa-only symbols.

To build the reference apps as P4 (RISC-V) ELFs, see
[`reference/p4apps/buildelf.sh`](reference/p4apps) (`-fPIC -shared`, entry
`app_main`, riscv32 ABI).

## Status / validation notes

This was ported by careful reference to the S3 demo, the `breezy_term` /
`breezybox` sources, and the Tanmatsu native launcher (for the exact badge-bsp
and esp-hosted APIs). The firmware **builds clean** for esp32p4 here, but has not
been run on hardware, so expect to validate/tune on-device. Most likely spots:

- **Color byte order** in `breezy_tanmatsu_lcd` (RGB vs BGR / endianness) — if
  red and blue look swapped, flip the order in `rebuild_palette_out()` (text) and
  `vga_out_entry()` (graphics, same convention).
- **Graphics performance / tearing** — the graphics render task redraws the whole
  upscaled frame every ~33 ms via per-pixel rotated writes (`render_gfx_frame()`),
  the same cost model as the text path. If animation is slow on the 800×480 panel,
  that loop is the place to optimize; apps draw straight into the framebuffer
  asynchronously, so some tearing is expected.
- **Dependency versions** in `main/idf_component.yml` are loose (`"*"`) — pin them
  to match your installed IDF / registry if resolution complains.
- **WiFi bring-up** (`net_bringup.c`) — the `wifi_remote` API/version may need a
  small tweak to match your IDF.
- **Function-key / VT-switch hotkeys** from the physical keyboard are not mapped;
  use the `vt` command for now.
