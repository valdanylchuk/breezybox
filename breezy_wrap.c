#include "breezy_vfs.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <dirent.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

// Declare the 'real' functions
FILE* __real_fopen(const char *path, const char *mode);
int __real_open(const char *path, int flags, int mode);
int __real_mkdir(const char *path, mode_t mode);
int __real_stat(const char *path, struct stat *st);
int __real_rename(const char *oldpath, const char *newpath);
int __real_remove(const char *path);
int __real_rmdir(const char *path);
DIR* __real_opendir(const char *name);
struct dirent* __real_readdir(DIR* dirp);
int __real_closedir(DIR* dirp);
void __real_rewinddir(DIR* dirp);

// Virtual root directory handle
#define VIRTUAL_ROOT_MAGIC 0x42525459  // "BRTY"

typedef struct {
    uint32_t magic;
    int index;
    struct dirent entry;
} virtual_root_dir_t;

// Mount points to show at "/"
static const char *s_mount_names[] = { "root" };
#define NUM_MOUNTS (sizeof(s_mount_names) / sizeof(s_mount_names[0]))

// ============ Wrapped Functions ============

FILE* __wrap_fopen(const char *path, const char *mode)
{
    char resolved[BREEZYBOX_MAX_PATH * 2 + 2];
    const char *p = breezybox_resolve_path(path, resolved, sizeof(resolved));
    return __real_fopen(p ? p : path, mode);
}

int __wrap_open(const char *path, int flags, int mode)
{
    char resolved[BREEZYBOX_MAX_PATH * 2 + 2];
    const char *p = breezybox_resolve_path(path, resolved, sizeof(resolved));
    return __real_open(p ? p : path, flags, mode);
}

int __wrap_mkdir(const char *path, mode_t mode)
{
    char resolved[BREEZYBOX_MAX_PATH * 2 + 2];
    const char *p = breezybox_resolve_path(path, resolved, sizeof(resolved));
    return __real_mkdir(p ? p : path, mode);
}

int __wrap_rename(const char *oldpath, const char *newpath)
{
    char resolved_old[BREEZYBOX_MAX_PATH * 2 + 2];
    char resolved_new[BREEZYBOX_MAX_PATH * 2 + 2];
    const char *p_old = breezybox_resolve_path(oldpath, resolved_old, sizeof(resolved_old));
    const char *p_new = breezybox_resolve_path(newpath, resolved_new, sizeof(resolved_new));
    return __real_rename(p_old ? p_old : oldpath, p_new ? p_new : newpath);
}

int __wrap_remove(const char *path)
{
    char resolved[BREEZYBOX_MAX_PATH * 2 + 2];
    const char *p = breezybox_resolve_path(path, resolved, sizeof(resolved));
    return __real_remove(p ? p : path);
}

int __wrap_rmdir(const char *path)
{
    char resolved[BREEZYBOX_MAX_PATH * 2 + 2];
    const char *p = breezybox_resolve_path(path, resolved, sizeof(resolved));
    return __real_rmdir(p ? p : path);
}

int __wrap_chdir(const char *path)
{
    return breezybox_set_cwd(path);
}

char* __wrap_getcwd(char *buf, size_t size)
{
    breezybox_get_cwd(buf, size);
    return buf;
}

int __wrap_stat(const char *path, struct stat *st)
{
    char resolved[BREEZYBOX_MAX_PATH * 2 + 2];
    const char *p = breezybox_resolve_path(path, resolved, sizeof(resolved));
    if (!p) p = path;

    // Virtual directories
    if (strcmp(p, "/") == 0 || strcmp(p, "/root") == 0) {
        memset(st, 0, sizeof(struct stat));
        st->st_mode = S_IFDIR | 0755;
        st->st_nlink = 1;
        return 0;
    }

    return __real_stat(p, st);
}

DIR* __wrap_opendir(const char *name)
{
    char resolved[BREEZYBOX_MAX_PATH * 2 + 2];
    const char *p = breezybox_resolve_path(name, resolved, sizeof(resolved));
    if (!p) p = name;

    // Virtual root "/"
    if (strcmp(p, "/") == 0) {
        virtual_root_dir_t *vdir = malloc(sizeof(virtual_root_dir_t));
        if (!vdir) {
            errno = ENOMEM;
            return NULL;
        }
        vdir->magic = VIRTUAL_ROOT_MAGIC;
        vdir->index = 0;
        return (DIR*)vdir;
    }

    return __real_opendir(p);
}

struct dirent* __wrap_readdir(DIR* dirp)
{
    if (!dirp) return __real_readdir(dirp);

    virtual_root_dir_t *vdir = (virtual_root_dir_t*)dirp;
    if (vdir->magic == VIRTUAL_ROOT_MAGIC) {
        if (vdir->index >= (int)NUM_MOUNTS) return NULL;
        
        vdir->entry.d_ino = vdir->index + 1;
        vdir->entry.d_type = DT_DIR;
        strcpy(vdir->entry.d_name, s_mount_names[vdir->index]);
        vdir->index++;
        return &vdir->entry;
    }

    return __real_readdir(dirp);
}

int __wrap_closedir(DIR* dirp)
{
    if (!dirp) return __real_closedir(dirp);

    virtual_root_dir_t *vdir = (virtual_root_dir_t*)dirp;
    if (vdir->magic == VIRTUAL_ROOT_MAGIC) {
        free(vdir);
        return 0;
    }

    return __real_closedir(dirp);
}

void __wrap_rewinddir(DIR* dirp)
{
    if (!dirp) {
        __real_rewinddir(dirp);
        return;
    }

    virtual_root_dir_t *vdir = (virtual_root_dir_t*)dirp;
    if (vdir->magic == VIRTUAL_ROOT_MAGIC) {
        vdir->index = 0;
    } else {
        __real_rewinddir(dirp);
    }
}