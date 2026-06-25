# 'main' component for the BreezyBox Tanmatsu (ESP32-P4) demo.
idf_component_register(
    SRCS
        "main.c"
        "my_console_io.c"
        "tanmatsu_keyboard.c"
        "net_bringup.c"
        "cmd_testgfx.c"     # built-in graphics smoke test
        "elf_extras.c"      # extra symbols exported to ELF apps

    PRIV_REQUIRES
        # Core
        driver
        console
        vfs
        nvs_flash
        esp_timer
        # BreezyBox stack
        breezybox
        breezy_term
        breezy_tanmatsu_lcd
        # Tanmatsu hardware
        badge-bsp
        # Networking: net_bringup.c includes wifi_remote.h (tanmatsu-wifi).
        # The rest of the remote-radio stack (esp-hosted-tanmatsu, wifi-manager)
        # is pulled in transitively and linked project-wide.
        tanmatsu-wifi

    INCLUDE_DIRS
        "."
)
