/*
 * gzip.c - Minimal gzip compressor for ESP32-BreezyBox
 *
 * Usage: gzip <file> [outfile]
 */

#include <stdio.h>
#include <string.h>

/* zlib constants */
#define Z_OK            0
#define Z_STREAM_END    1
#define Z_NO_FLUSH      0
#define Z_FINISH        4
#define Z_DEFLATED      8
#define MAX_WBITS       15

/* z_stream structure - must match zlib's layout */
typedef struct {
    const unsigned char *next_in;
    unsigned int avail_in;
    unsigned long total_in;
    unsigned char *next_out;
    unsigned int avail_out;
    unsigned long total_out;
    const char *msg;
    void *state;
    void *zalloc;
    void *zfree;
    void *opaque;
    int data_type;
    unsigned long adler;
    unsigned long reserved;
} z_stream;

/* Forward declarations */
int deflateInit2_(z_stream *strm, int level, int method, int windowBits,
                  int memLevel, int strategy, const char *version, int stream_size);
int deflate(z_stream *strm, int flush);
int deflateEnd(z_stream *strm);
unsigned long crc32(unsigned long crc, const unsigned char *buf, unsigned int len);

#define deflateInit2(strm, level, method, windowBits, memLevel, strategy) \
    deflateInit2_(strm, level, method, windowBits, memLevel, strategy, "1.2.13", (int)sizeof(z_stream))

/* Write gzip header */
static void write_gzip_header(FILE *f)
{
    unsigned char hdr[10] = {
        0x1f, 0x8b,  /* magic */
        0x08,        /* deflate */
        0x00,        /* flags */
        0,0,0,0,     /* mtime */
        0x00,        /* xfl */
        0xff         /* OS unknown */
    };
    fwrite(hdr, 1, 10, f);
}

/* Write gzip trailer */
static void write_gzip_trailer(FILE *f, unsigned long crc, unsigned long size)
{
    unsigned char trl[8];
    trl[0] = crc & 0xff;
    trl[1] = (crc >> 8) & 0xff;
    trl[2] = (crc >> 16) & 0xff;
    trl[3] = (crc >> 24) & 0xff;
    trl[4] = size & 0xff;
    trl[5] = (size >> 8) & 0xff;
    trl[6] = (size >> 16) & 0xff;
    trl[7] = (size >> 24) & 0xff;
    fwrite(trl, 1, 8, f);
}

int main(int argc, char **argv)
{
    if (argc < 2) {
        printf("Usage: gzip <file> [outfile]\n");
        return 1;
    }

    const char *src = argv[1];
    char outbuf[256];
    const char *dst;

    if (argc > 2) {
        dst = argv[2];
    } else {
        snprintf(outbuf, sizeof(outbuf), "%s.gz", src);
        dst = outbuf;
    }

    printf("Compressing %s -> %s\n", src, dst);

    FILE *in = fopen(src, "rb");
    if (!in) {
        printf("gzip: cannot open %s\n", src);
        return 1;
    }

    FILE *out = fopen(dst, "wb");
    if (!out) {
        printf("gzip: cannot create %s\n", dst);
        fclose(in);
        return 1;
    }

    /* Initialize deflate with small memory footprint:
     * windowBits=-12 (4KB window, raw deflate - negative means no zlib header)
     * memLevel=4 (uses ~2KB for hash)
     * Total: ~10KB */
    z_stream strm = {0};
    int ret = deflateInit2(&strm, 6, Z_DEFLATED, -12, 4, 0);
    if (ret != Z_OK) {
        printf("gzip: deflateInit failed: %d\n", ret);
        fclose(in);
        fclose(out);
        return 1;
    }

    write_gzip_header(out);

    unsigned char inbuf[1024];
    unsigned char outbuf2[1024];
    unsigned long crc = crc32(0, NULL, 0);
    unsigned long total_in = 0;
    int flush;

    do {
        strm.avail_in = fread(inbuf, 1, sizeof(inbuf), in);
        if (ferror(in)) {
            printf("gzip: read error\n");
            deflateEnd(&strm);
            fclose(in);
            fclose(out);
            return 1;
        }
        flush = feof(in) ? Z_FINISH : Z_NO_FLUSH;
        strm.next_in = inbuf;
        crc = crc32(crc, inbuf, strm.avail_in);
        total_in += strm.avail_in;

        do {
            strm.avail_out = sizeof(outbuf2);
            strm.next_out = outbuf2;
            ret = deflate(&strm, flush);
            if (ret < 0) {
                printf("gzip: deflate error: %d\n", ret);
                deflateEnd(&strm);
                fclose(in);
                fclose(out);
                return 1;
            }
            fwrite(outbuf2, 1, sizeof(outbuf2) - strm.avail_out, out);
        } while (strm.avail_out == 0);

    } while (flush != Z_FINISH);

    deflateEnd(&strm);
    write_gzip_trailer(out, crc, total_in);

    fclose(in);
    fclose(out);

    printf("Done (%lu bytes -> %lu bytes).\n", total_in, strm.total_out + 18);
    return 0;
}
