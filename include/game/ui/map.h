#ifndef GAME_UI_MAP_H
#define GAME_UI_MAP_H

/* Functions defined in src/game/ui/map.c. */

#include "common.h"

extern void decode_map_rle_row(unsigned char *dst, int row, unsigned char *src, short *offs);

#endif /* GAME_UI_MAP_H */
