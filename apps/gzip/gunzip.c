/*
 * gunzip.c - Minimal gzip decompressor for ESP32-BreezyBox
 *
 * Usage: gunzip <file.gz> [outfile]
 *
 * Decompresses a .gz file using zlib's gzFile API.
 */

#include <stdio.h>
#include <string.h>

/* Forward declarations for zlib gzFile API */
typedef void *gzFile;
gzFile gzopen(const char *path, const char *mode);
int gzread(gzFile file, void *buf, unsigned len);
int gzclose(gzFile file);

/* Generate output filename by stripping .gz extension */
static void strip_gz(const char *src, char *dst, size_t dst_size)
{
    size_t len = strlen(src);
    if (len > 3 && strcmp(src + len - 3, ".gz") == 0) {
        size_t copy_len = len - 3;
        if (copy_len >= dst_size) copy_len = dst_size - 1;
        memcpy(dst, src, copy_len);
        dst[copy_len] = '\0';
    } else {
        snprintf(dst, dst_size, "%s.out", src);
    }
}

int main(int argc, char **argv)
{
    if (argc < 2) {
        printf("Usage: gunzip <file.gz> [outfile]\n");
        return 1;
    }

    const char *src = argv[1];
    char outbuf[256];
    const char *dst;

    if (argc > 2) {
        dst = argv[2];
    } else {
        strip_gz(src, outbuf, sizeof(outbuf));
        dst = outbuf;
    }

    printf("Decompressing %s -> %s\n", src, dst);

    gzFile gz = gzopen(src, "rb");
    if (!gz) {
        printf("gunzip: cannot open %s\n", src);
        return 1;
    }

    FILE *out = fopen(dst, "wb");
    if (!out) {
        printf("gunzip: cannot create %s\n", dst);
        gzclose(gz);
        return 1;
    }

    char buf[4096];
    int n;
    size_t total = 0;

    while ((n = gzread(gz, buf, sizeof(buf))) > 0) {
        if (fwrite(buf, 1, n, out) != (size_t)n) {
            printf("gunzip: write error\n");
            fclose(out);
            gzclose(gz);
            return 1;
        }
        total += n;
    }

    fclose(out);
    gzclose(gz);

    if (n < 0) {
        printf("gunzip: decompression error\n");
        return 1;
    }

    printf("Done (%zu bytes).\n", total);
    return 0;
}
