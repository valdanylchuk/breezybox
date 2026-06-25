idf_component_register(
    SRCS
        "tanmatsu_lcd.c"
        "rgb_gfx.c"
        "terminus16.c"
    INCLUDE_DIRS
        "include"
    REQUIRES
        badge-bsp        # bsp/display.h, bsp_display_blit / get_parameters
        esp_lcd          # esp_lcd_dpi_panel_get_frame_buffer (direct scanout FB)
        esp_driver_ppa   # ppa_do_scale_rotate_mirror (HW scale + rotate)
        esp_mm           # esp_cache_msync (write back FB borders)
)
