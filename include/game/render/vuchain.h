#ifndef GAME_RENDER_VUCHAIN_H
#define GAME_RENDER_VUCHAIN_H

/* Functions defined in src/game/render/vuchain.c. */

#include "common.h"

extern void DMAC_VIF1_Disable(void);
extern void DMAC_VIF1_Enable(void);
extern void VU1_addDataRef(void *, int);
extern void VU1_initChain(void);
extern void VU1_sendChain(void);
extern void VU1_swapChain(void);
extern void VU1_texFlush(void);

#endif /* GAME_RENDER_VUCHAIN_H */
