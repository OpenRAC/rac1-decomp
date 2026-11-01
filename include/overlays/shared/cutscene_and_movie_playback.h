#ifndef OVERLAYS_SHARED_CUTSCENE_AND_MOVIE_PLAYBACK_H
#define OVERLAYS_SHARED_CUTSCENE_AND_MOVIE_PLAYBACK_H

/* Functions defined in src/overlays/shared/cutscene_and_movie_playback.c. */

#include "common.h"

extern void PlayMovieEntryIfIdle(int);
extern void StartCutscene(int);
extern void start_slideshow(void);

#endif /* OVERLAYS_SHARED_CUTSCENE_AND_MOVIE_PLAYBACK_H */
