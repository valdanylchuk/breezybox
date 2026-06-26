#include "breezy_cmd.h"
#include "breezy_vfs.h"
#include <stdio.h>
#include <sys/stat.h>

int cmd_mkdir(int argc, char **argv)
{
    if (argc < 2) {
        printf("Usage: mkdir <dir>\n");
        return 1;
    }

    char resolved[BREEZYBOX_MAX_PATH * 2 + 2];
    const char *path = argv[1];

    if (path[0] != '/') {
        if (!breezybox_resolve_path(path, resolved, sizeof(resolved))) {
            printf("mkdir: path too long\n");
            return 1;
        }
        path = resolved;
    }

    if (mkdir(path, 0755) != 0) {
        printf("mkdir: cannot create '%s'\n", argv[1]);
        return 1;
    }

    return 0;
}