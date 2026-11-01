#ifndef CORE_989SND_H
#define CORE_989SND_H

/* Functions defined in src/core/989snd.c. */

#include "common.h"

extern void snd_ContinueAllSoundsInGroup(int);
extern void snd_StreamSafeCdCallback(void *);
extern void snd_reenable_command_flush(void);
extern void snd_reset_state_and_flush_commands(void);

#endif /* CORE_989SND_H */
