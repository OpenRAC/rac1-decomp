#ifndef GAME_VUCHAIN_H
#define GAME_VUCHAIN_H

/* Functions defined in src/game/vuchain.c. */

#include "common.h"

extern void DMAC_VIF1_Disable(void);
extern void DMAC_VIF1_Enable(void);
extern void VU1_addDataRef(void *, int);
extern void VU1_initChain(void);
extern void VU1_sendChain(void);
extern void VU1_swapChain(void);
extern void VU1_texFlush(void);

#endif /* GAME_VUCHAIN_H */
