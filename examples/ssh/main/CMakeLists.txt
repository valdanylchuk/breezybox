# Register the 'main' component with the build system.
idf_component_register(
    # --- Source Files ---
    SRCS
        "main.c"
        "my_console_io.c"

    # --- Dependencies ---
    # Headless: just the shell, the SSH component, and the console plumbing.
    # (breezybox transitively provides breezy_term/vterm, esp_wifi, esp_netif.)
    PRIV_REQUIRES
        breezybox
        breezy_ssh
        console
        driver
        vfs
        nvs_flash

    # --- Include Directories ---
    INCLUDE_DIRS
        "."
)
