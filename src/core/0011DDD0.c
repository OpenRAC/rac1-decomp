#include "common.h"
#include "callees.h"
#include "structs.h"

/*
 * core_text object 0x11DDD0-0x11DF10. Boundaries are retail's linker fill
 * (0xCDCDCDCD) between objects; see docs/reference/DECOMP_PROGRESS.md.
 */


extern void flush_cache(int);

ASM_FUNC("asm/handwritten/core_text", func_0011DDD0);

ASM_FUNC("asm/handwritten/core_text", func_0011DDE0);

/* kCopy: alarm.o's own copy of the word-at-a-time copy helper (nbytes
 * rounded down to words); returns 0. Same body as func_0011DA08
 * (initsys.o), func_0011D370 and func_0011DC08 (libosd.o's copy) -- each
 * kernel module linked its own instance of this helper. */
int alarm_kCopy(int *dst, int *src, unsigned int nbytes) {
    unsigned int i;
    for (i = 0; i < nbytes >> 2; i++) {
        *dst++ = *src++;
    }
    return 0;
}

ASM_FUNC("asm/handwritten/core_text", func_0011DE28);

extern void alarm_set_syscall(int, int);
extern void alarm_kernel_copy(void *, void *, int);
extern int alarm_get_syscall_entry(int);
extern int alarm_syscall_patch_table[];
extern char alarm_kernel_patch_code[];
extern char alarm_scratchpad_patch_code[];

typedef struct {
    int a;
    int b;
} D_00131358_pair;

/*
 * Same-size near-miss (8/0xD4 bytes). Same shape as func_0011D3C8:
 * guarded by a hardware status bit at 0x10001810 (skip everything if
 * already done), two (addr,value) pokes through func_0011DDD0, two
 * func_0011DDE0 block copies (to a fixed load address and to
 * scratchpad at 0x82000), an interrupt disable/enable bracket, a
 * third func_0011DDD0 poke, then a 6-entry table loop where
 * func_0011DE28 reads the entry's current value back before
 * func_0011DDD0 rewrites it. All three callees are handwritten
 * syscall wrappers.
 */
void InitAlarm(void) {
    int *t;
    D_00131358_pair *p;
    unsigned int i;
    int old;

    if (*(volatile unsigned int *)0x10001810 & 0x100) {
        return;
    }

    t = alarm_syscall_patch_table;
    alarm_set_syscall(t[0], t[1]);
    alarm_kernel_copy((void *)0x80076000, alarm_kernel_patch_code, 0x740);
    alarm_kernel_copy((void *)0x82000, alarm_scratchpad_patch_code, 0x28);
    flush_cache(0);
    flush_cache(2);
    alarm_set_syscall(t[2], t[3]);

    p = (D_00131358_pair *)(t + 4);
    for (i = 2; i < 8; i++) {
        old = alarm_get_syscall_entry(p->a);
        alarm_set_syscall(p->a, old);
        p++;
    }
}

INCLUDE_ASM("asm/nonmatchings/core_text", func_0011DF0C);
