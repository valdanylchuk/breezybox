idf_component_register(
    SRCS "rgb_display.c" "rgb_gfx.c" "terminus16.c"
    INCLUDE_DIRS "include"
    REQUIRES esp_lcd heap
)
