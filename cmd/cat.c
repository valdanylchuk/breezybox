#include "breezy_cmd.h"
#include "breezy_vfs.h"
#include <stdio.h>
#include <string.h>

int cmd_cat(int argc, char **argv)
{
    if (argc < 2) {
        printf("Usage: cat <file>\n");
        return 1;
    }

    char resolved[BREEZYBOX_MAX_PATH * 2 + 2];
    const char *path = argv[1];

    if (path[0] != '/') {
        if (!breezybox_resolve_path(path, resolved, sizeof(resolved))) {
            printf("cat: path too long\n");
            return 1;
        }
        path = resolved;
    }

    FILE *f = fopen(path, "r");
    if (!f) {
        printf("cat: %s: No such file\n", argv[1]);
        return 1;
    }

    char buf[128];
    while (fgets(buf, sizeof(buf), f)) {
        printf("%s", buf);
    }
    fclose(f);

    return 0;
}