/*
 * breezy_exports.c - Force-export symbols for ELF runtime linking
 * 
 * The ELF loader resolves symbols at load time. This file forces the
 * linker to include functions that ELF binaries might need but are NOT
 * already used (directly or indirectly) by the main firmware.
 * 
 * DO NOT add functions already used in BreezyBox - they're already linked.
 * DO NOT add macros - only real functions.
 * 
 * Add functions here when ELF binaries fail to load with "symbol not found".
 */

#include "breezybox.h"

#include <dirent.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <math.h>

#include "esp_cpu.h"
#include "esp_heap_caps.h"
#include "vterm.h"
#include "zlib.h"

/*
 * Wrapper for inline function esp_cpu_get_cycle_count.
 * Inline functions can't be exported directly, so we wrap them.
 */
uint32_t elf_get_cycle_count(void)
{
    return (uint32_t)esp_cpu_get_cycle_count();
}

/*
 * Call this once during init to ensure the linker includes these symbols.
 * The function itself does nothing at runtime.
 */
void breezybox_export_symbols(void)
{
    volatile const void *exports[] = {
        // Functions possibly needed by ELF programs but not used in BreezyBox

        // seen missing at some point
        (void*)stpcpy,
        (void*)srand,
        (void*)rand,
        (void*)sin,
        (void*)cos,
        (void*)sqrt,
        (void*)sinf,
        (void*)cosf,
        (void*)sqrtf,
        (void*)atexit,
        (void*)perror,
        (void*)rewinddir,
        (void*)chdir,
        (void*)mkdir,
        (void*)getcwd,
        (void*)heap_caps_get_free_size,
        (void*)heap_caps_check_integrity_all,
        (void*)elf_get_cycle_count,
        (void*)lseek,
        (void*)clock,

        // Other commonly useful functions that might be missing:
        (void*)sscanf,
        (void*)strtok,
        (void*)qsort,
        (void*)fseek,
        (void*)ftell,
        (void*)rewind,
        (void*)fgets,
        (void*)getchar,
        (void*)qsort,
        (void*)bsearch,
        (void*)strtod,
        (void*)heap_caps_check_integrity_all,

        // VTerm functions for ELF binaries
        (void*)vterm_get_size,
        (void*)vterm_set_palette,
        (void*)vterm_get_palette,

        // HTTP helper for ELF apps
        (void*)breezy_http_download,

        // Zlib
        (void*)gzopen,
        (void*)gzread,
        (void*)gzwrite,
        (void*)gzclose,
        (void*)gzerror,
        (void*)deflateInit2_,
        (void*)deflate,
        (void*)deflateEnd,
        (void*)crc32,
        (void*)ferror,
        (void*)feof,
    };
    
    (void)exports;  // Suppress unused variable warning
}