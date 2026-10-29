#include "common.h"
#include "structs.h"

/*
 * movie/strfile.cpp in the original source; text 0x23CE18-0x23CEC8.
 * Name and boundary from the NTSC split of this game, mapped to PAL by matching function
 * sizes -- see docs/DECOMP_PROGRESS.md. Compiled as C for now.
 */

/* StrFile: only the fields these functions touch are known. */
typedef struct StrFile {
    int second;
    int first;
} StrFile;

/* No recovered name. Stores its two arguments in the object (first argument at offset 4)
 * and returns 1. */
int set_state_fields(StrFile *f, int first, int second) {
    f->first = first;
    f->second = second;
    return 1;
}
/* No recovered name. Nothing to free, returns 1. */
int get_state_callback_result(StrFile *f) {
    return 1;
}
extern void sce_cd_read(int, int, int, void *);
extern void sce_cd_sync_s(int);

/* Start a movie-sector read. Wait and advance the cursor
   for synchronous reads. */
int read_cd_stream_sectors(void *stream_file, int destination_address, int byte_count, int asynchronous) {
    struct { unsigned char retries, speed, pattern, padding; } mode;
    int bytes_read = 0;
    int sector_count = byte_count >> 11;

    mode.retries = 0x64;
    mode.speed = 0;
    mode.pattern = 0;
    sce_cd_read(*(int *)((char *)stream_file + 4), sector_count, destination_address, &mode);
    if (asynchronous == 0) {
        *(int *)((char *)stream_file + 4) = *(int *)((char *)stream_file + 4) + sector_count;
        sce_cd_sync_s(0);
        bytes_read = byte_count;
    }
    return bytes_read;
}
