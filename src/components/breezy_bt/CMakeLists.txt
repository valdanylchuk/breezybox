idf_component_register(
    SRCS "bt_keyboard.c"
    INCLUDE_DIRS "include"
    REQUIRES bt esp_hid nvs_flash
)
