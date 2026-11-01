#ifndef CORE_00119D88_H
#define CORE_00119D88_H

/* Functions defined in src/core/00119D88.c. */

#include "common.h"

extern int sceLseek(int, int, int);
extern int sceRead(int fd, void *buf, int len);
extern int sceWrite(int, void *, int);
extern int sce_sif_check_stat_rpc(void *);

#endif /* CORE_00119D88_H */
