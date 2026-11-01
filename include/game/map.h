#ifndef GAME_MAP_H
#define GAME_MAP_H

/* Functions defined in src/game/map.c. */

#include "common.h"

extern void decode_map_rle_row(unsigned char *dst, int row, unsigned char *src, short *offs);

#endif /* GAME_MAP_H */
