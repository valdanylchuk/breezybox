idf_component_register(
    SRCS
        "tanmatsu_lcd.c"
        "rgb_gfx.c"
        "terminus16.c"
    INCLUDE_DIRS
        "include"
    REQUIRES
        badge-bsp        # bsp/display.h, bsp_display_blit / get_parameters
)
