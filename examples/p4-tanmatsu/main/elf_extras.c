/*
 * elf_extras.c - Project-level symbols exported to loadable ELF apps.
 *
 * The breezybox component already force-exports the libc/zlib/vterm surface
 * (breezy_exports.c). This file adds the few P4-demo-specific symbols that the
 * reference apps need but the firmware wouldn't otherwise link:
 *
 *   - vTaskDelayUntil   IDF's FreeRTOS only provides this as a *macro*, so there
 *                       is no real symbol for an app to resolve. We provide one.
 *   - my_display_refresh_palette  defined in my_console_io.c; anchored here so
 *                       --gc-sections keeps it (nothing in firmware calls it).
 *   - __floatundidf     libgcc soft-float helper (termbench); usually already
 *                       linked, anchored for safety.
 *
 * After changing exports here, rebuild and regenerate the ELF customer symbol
 * table (see Readme "ELF apps on P4").
 */

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "my_console_io.h"

#ifdef vTaskDelayUntil
#undef vTaskDelayUntil
#endif

/*
 * Real vTaskDelayUntil symbol for ELF apps (e.g. plasma's frame pacing).
 * Reimplemented on xTaskGetTickCount/vTaskDelay so it does not depend on
 * INCLUDE_xTaskDelayUntil. Signed tick delta tolerates counter wraparound.
 */
void vTaskDelayUntil(TickType_t *pxPreviousWakeTime, TickType_t xTimeIncrement)
{
    TickType_t now  = xTaskGetTickCount();
    TickType_t wake = *pxPreviousWakeTime + xTimeIncrement;
    TickType_t delay = wake - now;
    if ((int32_t)delay > 0) {
        vTaskDelay(delay);
    }
    *pxPreviousWakeTime = wake;
}

/* libgcc: unsigned 64-bit -> double (some apps' integer/double math). */
extern double __floatundidf(unsigned long long);

/* Volatile sink: volatile stores can't be optimized away, so the address-of
 * references below are emitted and the symbols are retained under -O2. */
static volatile const void *s_export_sink;

/*
 * Force the linker to keep the symbols above (and the my_ glue) so they land in
 * the firmware ELF and, in turn, the generated customer symbol table. Call once
 * at boot. Does nothing useful at runtime.
 */
void breezy_p4_export_symbols(void)
{
    s_export_sink = (const void *)vTaskDelayUntil;
    s_export_sink = (const void *)my_display_refresh_palette;
    s_export_sink = (const void *)__floatundidf;
}
