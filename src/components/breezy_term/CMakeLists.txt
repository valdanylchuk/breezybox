idf_component_register(
    SRCS "vterm.c" "vterm_vfs.c"
    INCLUDE_DIRS "include"
    REQUIRES vfs driver
)
