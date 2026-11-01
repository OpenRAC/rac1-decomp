#ifndef CORE_SOUND_989SND_H
#define CORE_SOUND_989SND_H

/* Functions defined in src/core/sound/989snd.c. */

#include "common.h"

extern void snd_ContinueAllSoundsInGroup(int);
extern void snd_PauseAllSoundsInGroup(int);
extern void snd_StreamSafeCdCallback(void *);
extern void snd_reenable_command_flush(void);
extern void snd_reset_state_and_flush_commands(void);

#endif /* CORE_SOUND_989SND_H */
