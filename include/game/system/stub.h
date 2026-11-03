#ifndef GAME_SYSTEM_STUB_H
#define GAME_SYSTEM_STUB_H

/* Functions defined in src/game/system/stub.c. */

#include "common.h"

extern void Profile_Mark(void *);
extern void STUB_printf(void *, ...);
extern void noop_callback_e(void *);
extern void noop_callback_h(void);
extern void noop_callback_i(void);
extern void noop_callback_k(void *, void *, int, int);
extern int noop_callback_l(void *);
extern void noop_callback_n(int);
extern void noop_callback_o(int);
extern void noop_callback_q(int, int);
extern void noop_callback_r(void *, int);
extern void noop_callback_s(void *, void *, int, int, int);

#endif /* GAME_SYSTEM_STUB_H */
