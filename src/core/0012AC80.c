#include "common.h"
#include "callees.h"
#include "structs.h"

/*
 * core_text object 0x12AC80-0x12CC70. Boundaries are retail's linker fill
 * (0xCDCDCDCD) between objects; see docs/DECOMP_PROGRESS.md.
 *
 * Sony's MPEG library (libmpeg): sceMpegInit/Create/Delete-style setup,
 * the callback table (sceMpegAddCallback, func_0012BC50) and its
 * dispatcher, the work-area allocator, the picture/field steps and the
 * error reporter ("[MPEG ERROR]%s"). Built with Sony's 2.9-ee like the
 * rest of libmpeg (0012A2F0.c): see func_0012BC50, whose match needs
 * 2.9-ee's type-based alias analysis.
 */

/* Declarations in scope here before the split. */
extern long strtol(int arg0, int arg1, int arg2);
extern int SbrkErrno;
extern void *_impure_ptr NOT_SDA;
extern int __sread(void *arg0, void *arg1, void *arg2);
extern int __swrite(void *arg0, void *arg1, void *arg2);
extern long __sseek(void *arg0, void *arg1, void *arg2);
extern void __sclose(void *arg0);
extern void libc_fflush(void);
extern void _fwalk(void *, void *);
extern char locale_lconv[];
extern int libc_glue_read();
extern long func_00116108_wide(int *errOut, void *a, void *b, void *c)
    __asm__("func_00116108");
extern long func_001188C8_wide(int *errOut, void *a, void *b, void *c)
    __asm__("func_001188C8");
extern long func_00114518_wide(int *errOut, void *a, void *b, void *c)
    __asm__("func_00114518");
extern int _close_r(int *errOut, int arg1);
extern int __sfvwrite(int, void *);
extern void __sinit(void *);
extern void _vfprintf_r(void *, void *, int, int);
extern int libc_glue_write();
extern int CoreGlobalWord NOT_SDA;
extern void Deci2Call(int arg0, void *arg1);
extern void *InitBlockData NOT_SDA;
extern int sif_sregs[];
extern void disable_dmac_atomic(int);
extern void remove_dmac_handler(int, int);
extern int sif_cmd_dmac_handler_id;
extern int sif_cmd_init_done;
extern int sif_cmd_data_sys_handlers NOT_SDA;
extern int sif_cmd_data_usr_handlers NOT_SDA;
extern void sif_send_cmd_common(int, int, int, int, int, int, int);
extern void sceSifExitCmd(void);
extern int RpcCommandState NOT_SDA;
extern int disable_interrupts(void);
extern void enable_interrupts(void);
extern int create_semaphore(void *);
extern int fs_iob_sema;
extern int fs_iob_sema_2;
extern char fs_iob_table[];
extern int fs_call_sema;
extern void fs_call_sema_init(void);
extern int fs_call_sema NOT_SDA;
extern char sif_lib_version_string[];
extern char FsResetBuffer[];
extern int fs_expected_version;
extern void libc_memset(void *, int, int);
extern int FsResetState;
extern int iop_heap_bind_state;
extern char iop_heap_rpc_client[];
extern int iop_heap_rpc_reply;
extern int iop_heap_rpc_arg;
extern char lf_iop_version[];
extern int lf_expected_version;
extern int _sceSifLoadModuleBuffer(int arg0, int arg1, int arg2, void *arg3);
extern void tty_reset_init_flag(void);
extern void init_tlb_32mb(void);
extern void kernel_init_tlb(void);
extern int FirstSemaphore;
extern int SecondSemaphore;
extern int osd_syscall_patch_table[];
extern char osd_kernel_patch_code[];
extern int PatchIsNeeded(void);
extern void flush_cache(int);
extern int sce_cd_sync_s(int);
extern void *cd_user_callback;
extern int cd_callback_sema;
extern int cd_ncmd_sema;
extern int cd_scmd_sema;
extern int cd_ncmd_busy;
extern int cd_poweroff_installing;
extern int cd_poweroff_installed;
extern int sif_call_rpc();
extern int cd_ncmd_prechk(int);
extern void signal_semaphore(int);
extern char cd_ncmd_rpc_client[];
extern int cd_ncmd_recv_buffer;
extern int sce_sif_check_stat_rpc(void *);
extern char cd_scmd_wait_msg[];
extern char cd_scmd_rpc_client[];
extern int cd_debug_level;
extern int cd_scmd_prechk(int);
extern int cd_scmd_recv_buffer;
extern char CoreDataTable[];
extern void sceDmaPause(void *);
extern char dma_sync_timeout_msg[];
extern int DmaChannels[];
extern int sce_mc_open(int, int, int, int);
extern int mc_current_command;
extern int *mc_get_info_type_out;
extern int *mc_get_info_free_out;
extern int *mc_get_info_format_out;
extern char RpcQueueData[];
extern int RpcReceiveData;
extern void debug_print_stub(void *);
extern char str_dbc_set_work_addr_error[];
extern int sceDbcGetDepNumber(int);
typedef struct {
    char unk_00[4];
    int  unk_04;
    int  unk_08;
    char *unk_0C;
    char unk_10[0x320];
} Ent330;
extern Ent330 pad2_sockets[];
extern void sync_dcache_range(void *a, void *b);
extern void ipu_vdec(int, int);
extern int IpuCommandTable[];
extern void dispatch_mpeg_cb_nodata(int);
extern void wait_ipu_idle(void *);
extern void _flushBuf(void *, int);
extern int _peepBit(void *, int);
extern void extra_bit_information(void *);
extern char str_mpeg_buffer_too_small_fmt[];
extern void sprintf_4(void *, char *, int, int) __asm__("func_00116248");
extern void _Error_a(void *, void *) __asm__("func_0012C468");
extern void sysbit_flush(void *, int);
extern void ipu_set_mpeg1(int arg0);
extern int sysbit_get(void *arg0, int arg1);

/* {base id, field mask} per type; the mask selects the shift of value. */
struct TypeEntry_12AC80 {
    u64 id;
    u64 type;
};

extern struct TypeEntry_12AC80 mpeg_stream_type_keys_r[] __asm__("D_00132FD8");

/* _type2id (libmpeg): for a type below 10, the 64-bit stream key
   D_00132FD8[type].id with value shifted into the field its mask selects
   (0, 24 or 32 bits up); 0 for any other type.
   Adapted from Lombyte's project (GPL-3.0): src/sdk/library/type2id.c, _type2id. */
long mpeg_type2id(int id, int value) {
    u64 result = 0;
    s32 shift = 0;

    if ((u32)id < 10) {
        switch (mpeg_stream_type_keys_r[id].type) {
        case 0xFFFFFFFFFF:
            shift = 0;
            break;
        case 0xFFFF000000:
            shift = 24;
            break;
        case 0xFF00000000:
            shift = 32;
            break;
        }
        result = mpeg_stream_type_keys_r[id].id | ((u64)value << shift);
    }
    return result;
}

LINKER_REMNANT("asm/remnants/core_text", func_0012AD08);

typedef struct {
    u8 pad0[0x18];
    u64 pos;
    u8 pad20[0x10];
} SysBit;
typedef struct {
    s32 v[6];
} PackHdr;
typedef struct {
    u64 id;
    s32 len;
    s32 scrambling;
    s64 pts;
    s64 dts;
    s32 data;
    s32 datalen;
    s32 header;
    s32 pad2C;
} PesHdr;
typedef struct {
    PackHdr pack;
    PesHdr pes;
} PssHdr;
typedef struct {
    s32 type;
    u8 *header;
    u8 *data;
    u32 len;
    s64 pts;
    s64 dts;
} sceMpegCbDataStr;
typedef s32 (*sceMpegCallback)(void *mp, sceMpegCbDataStr *cbstr, void *data);
typedef struct {
    u64 id;
    u64 mask;
    sceMpegCallback func;
    void *data;
} StreamCb;
typedef struct {
    u8 pad0[0x44];
    StreamCb *tbl;
    s32 n;
} MpegSys;
typedef struct {
    u8 pad0[0x40];
    MpegSys *sys;
} sceMpeg;
extern void sysbit_init(SysBit *bs, u8 *start, u8 *bufstart, s32 bufsize);
extern s32 sysbit_show_r(SysBit *bs, s32 n) __asm__("func_0012AAA8");
extern u8 *sysbit_ptr(SysBit *bs, s32 pos);
extern s32 mpeg_pack_header_r(SysBit *bs, PackHdr *pack) __asm__("func_0012B100");
extern s32 mpeg_pes_packet_r(MpegSys *sys, SysBit *bs, PesHdr *pes) __asm__("func_0012B2C0");

/* Adapted from Lombyte's project (GPL-3.0) for PAL by OpenRAC's tools/port.py: src/sdk/dma/sce_mpeg_demux_pss_ring.c, sceMpegDemuxPssRing. */
int sce_mpeg_demux_pss_ring_buffer(sceMpeg *mp, u8 *start, int size, u8 *bufstart, int bufsize) {
    SysBit bs;
    PssHdr hdr;
    SysBit *b;
    PssHdr *h;
    sceMpegCbDataStr cb;
    sceMpegCallback cbfunc = 0;
    void *cbdata = 0;
    StreamCb *tbl;
    int ret;
    int i;
    int cont;
    MpegSys *sys;
    int headerpos;

    cont = 1;
    h = &hdr;
    sys = mp->sys;
    tbl = sys->tbl;
    sysbit_init(&bs, start, bufstart, bufsize);
    ret = 0;
    i = 0;
    b = &bs;
    if (i < sys->n) {
        do {
            if (tbl[i].id == 0xBDFF000000) {
                cbfunc = tbl[i].func;
                cbdata = tbl[i].data;
            }
            if (cbfunc != 0) {
                break;
            }
            i++;
        } while (i < sys->n);
    }
    for (;;) {
        if (sysbit_show_r(b, 32) == 0x1BA) {
            mpeg_pack_header_r(b, &h->pack);
        }
        while (sysbit_show_r(b, 24) == 1 && sysbit_show_r(b, 32) != 0x1BA &&
               sysbit_show_r(b, 32) != 0x1B9 && b->pos < size * 8 && cont) {
            mpeg_pes_packet_r(sys, b, &h->pes);
            if (b->pos > size * 8) {
                continue;
            }
            for (i = 0; i < sys->n; i++) {
                if (tbl[i].id == (h->pes.id & tbl[i].mask)) {
                    headerpos = h->pes.header;
                    cb.type = 6;
                    cb.header = sysbit_ptr(b, headerpos);
                    cb.data = sysbit_ptr(b, h->pes.data);
                    cb.len = h->pes.datalen;
                    cb.pts = h->pes.pts;
                    cb.dts = h->pes.dts;
                    cont = tbl[i].func(mp, &cb, tbl[i].data);
                    break;
                }
            }
            if (i == sys->n && cbfunc != 0) {
                headerpos = h->pes.header;
                cb.type = 6;
                cb.header = sysbit_ptr(b, headerpos);
                cb.data = sysbit_ptr(b, h->pes.data);
                cb.len = h->pes.datalen;
                cb.pts = h->pes.pts;
                cb.dts = h->pes.dts;
                cont = cbfunc(mp, &cb, cbdata);
            }
            if (cont) {
                ret = b->pos >> 3;
            }
        }
        if (b->pos > size * 8 || sysbit_show_r(b, 32) != 0x1BA) {
            break;
        }
    }
    return ret;
}

extern long mpeg_type2id(int arg0, int arg1);

typedef struct {
    long key;
    long extra;
    int  cb;
    int  data;
} StrCbEnt; /* 0x18 */

typedef struct { char pad[8]; long extra; } Tbl16;
extern Tbl16 mpeg_stream_type_keys[];

/* Registers a stream callback and returns the old callback.
   The stored count increases even when an existing entry is replaced. */
int sce_mpeg_add_str_callback(void *mpeg_handle, int stream_type, int stream_channel, int callback_address, int callback_context) {
    int old = 0;
    char *mpeg_state = *(char **)((char *)mpeg_handle + 0x40);
    StrCbEnt *tbl = *(StrCbEnt **)(mpeg_state + 0x44);
    long key = mpeg_type2id(stream_type, stream_channel);
    int count = *(int *)(mpeg_state + 0x48);
    int i;

    for (i = 0; i < count; i++) {
        if (key == tbl[i].key) {
            old = tbl[i].cb;
            break;
        }
    }
    if (i < 0x40) {
        *(int *)(mpeg_state + 0x48) = count + 1;
        tbl[i].key = key;
        tbl[i].data = callback_context;
        tbl[i].cb = callback_address;
        tbl[i].extra = mpeg_stream_type_keys[stream_type].extra;
    }
    return old;
}

extern void sysbit_marker(void *arg0);
extern int mpeg_system_header();

/* Reads pack timing and stuffing, then reads an optional system header. */
int mpeg_pack_header(void *bitstream, void *pack_header) {
    char *header_bytes = (char *)pack_header;
    unsigned int first, second, third, stuffing;
    unsigned int i;

    sysbit_get(bitstream, 0x22);
    first = sysbit_get(bitstream, 3);
    sysbit_marker(bitstream);
    second = sysbit_get(bitstream, 0xF);
    sysbit_marker(bitstream);
    third = sysbit_get(bitstream, 0xF);
    sysbit_marker(bitstream);
    *(int *)(header_bytes + 0x0) = sysbit_get(bitstream, 9);
    sysbit_get(bitstream, 0x1E);
    stuffing = sysbit_get(bitstream, 3);

    *(unsigned int *)(header_bytes + 0x8) = (first >> 2) & 1;
    *(unsigned int *)(header_bytes + 0x4) = (first << 30) | (second << 15) | third;

    for (i = 0; i < stuffing; i++) {
        sysbit_get(bitstream, 8);
    }

    if (sysbit_show(bitstream, 0x20) == 0x1BB) {
        *(int *)(header_bytes + 0xC) = 1;
        mpeg_system_header(bitstream, header_bytes);
    } else {
        *(int *)(header_bytes + 0xC) = 0;
    }
    return 1;
}

int mpeg_system_header(void *bitstream) {
    sysbit_get(bitstream, 0x38);
    sysbit_get(bitstream, 0x28);
    while (sysbit_show(bitstream, 1) == 1) {
        sysbit_get(bitstream, 0x18);
    }
    return 1;
}

extern void sysbit_jump(void *arg0, int n);
extern char pes_optional_field_bits[];
extern char pes_pack_header_field_flag_msg[];

struct PES_BS {
    unsigned char pad_0[0x18];
    long stamp;
};

struct PES_HDR {
    long unk0;
    int unk8;
    int unkC;
    long unk10;
    long unk18;
    int unk20;
    int unk24;
    int unk28;
};

struct PES_TBL {
    unsigned char v[16];
} __attribute__((packed));

/* Parse one MPEG-2 PES packet header from the bit stream into hdr (libmpeg _PES_packet).
   Adapted from Lombyte's project (GPL-3.0) for PAL: src/sdk/library/_PES_packet.c, _PES_packet. */
int mpeg_pes_packet(int parser_context, struct PES_BS *bs, struct PES_HDR *hdr) {
    struct PES_TBL tbl;
    int ctx;
    int flag1;
    int len;         /* PES_header_data_length */
    int base;        /* (int)bs->stamp, captured before the header fields */
    long now;         /* the same stamp, re-read at the sync point */
    int pts_dts_flags;
    int optional_field_length;
    int extension_flag;

    ctx = parser_context;
    hdr->unk28 = (int)bs->stamp;
    tbl = *(struct PES_TBL *)pes_optional_field_bits;
    sysbit_get(bs, 0x18);
    hdr->unk0 = (long)sysbit_get(bs, 8) << 0x20;
    hdr->unk8 = sysbit_get(bs, 0x10);
    hdr->unk18 = -1;
    hdr->unk10 = -1;
    if (hdr->unk0 != ((unsigned long)0xBC00 << 0x18) &&
        hdr->unk0 != ((unsigned long)0xBE00 << 0x18) &&
        hdr->unk0 != ((unsigned long)0xBF00 << 0x18) &&
        hdr->unk0 != ((unsigned long)0xF000 << 0x18) &&
        hdr->unk0 != ((unsigned long)0xF100 << 0x18) &&
        hdr->unk0 != ((unsigned long)0xFF00 << 0x18) &&
        hdr->unk0 != ((unsigned long)0xF200 << 0x18) &&
        hdr->unk0 != ((unsigned long)0xF800 << 0x18)) {
        sysbit_get(bs, 2);
        hdr->unkC = sysbit_get(bs, 2);
        sysbit_get(bs, 4);
        pts_dts_flags = sysbit_get(bs, 2);
        flag1 = sysbit_get(bs, 1);
        optional_field_length = sysbit_get(bs, 4);
        extension_flag = sysbit_get(bs, 1);
        len = sysbit_get(bs, 8);
        base = bs->stamp;
        if (pts_dts_flags & 2) {
            unsigned int a, b, c;
            sysbit_get(bs, 4);
            a = sysbit_get(bs, 3);
            sysbit_marker(bs);
            b = sysbit_get(bs, 0xF);
            sysbit_marker(bs);
            c = sysbit_get(bs, 0xF);
            sysbit_marker(bs);
            hdr->unk10 = ((long)((a >> 2) & 1) << 0x20) | (long)(unsigned int)(a << 30 | b << 15 | c);
        }
        if (pts_dts_flags == 3) {
            unsigned int a, b, c;
            sysbit_get(bs, 4);
            a = sysbit_get(bs, 3);
            sysbit_marker(bs);
            b = sysbit_get(bs, 0xF);
            sysbit_marker(bs);
            c = sysbit_get(bs, 0xF);
            sysbit_marker(bs);
            hdr->unk18 = ((long)((a >> 2) & 1) << 0x20) | (long)(unsigned int)(a << 30 | b << 15 | c);
        }
        if (flag1 == 1) {
            sysbit_get(bs, 0x30);
        }
        if (optional_field_length != 0) {
            sysbit_get(bs, tbl.v[optional_field_length]);
        }
        if (extension_flag == 1) {
            int a1;
            int a2;
            int a3;
            int a4;
            int a5;
            a1 = sysbit_get(bs, 1);
            a2 = sysbit_get(bs, 1);
            a3 = sysbit_get(bs, 1);
            a4 = sysbit_get(bs, 1);
            sysbit_get(bs, 3);
            a5 = sysbit_get(bs, 1);
            if (a1 == extension_flag) {
                sysbit_get(bs, 0x30);
                sysbit_get(bs, 0x30);
                sysbit_get(bs, 0x20);
            }
            if (a2 == extension_flag) {
                _Error_a(ctx, pes_pack_header_field_flag_msg);
                return 0;
            }
            if (a3 == extension_flag) {
                sysbit_get(bs, 0x10);
            }
            if (a4 == extension_flag) {
                sysbit_get(bs, 0x10);
            }
            if (a5 == extension_flag) {
                unsigned int i;
                unsigned int n;
                sysbit_marker(bs);
                n = sysbit_get(bs, 7);
                for (i = 0; i < n; i++) {
                    sysbit_get(bs, 8);
                }
            }
        }
        now = bs->stamp;
        {
        int delta = len - (int)((now - base) >> 3);
        if (delta != 0) {
            sysbit_jump(bs, delta);
        }
        }
        {
        int n = hdr->unk8 - len;
        int m;
        hdr->unk24 = n - 3;
        hdr->unk20 = (int)bs->stamp;
        if (hdr->unk0 == ((unsigned long)0xBD00 << 0x18)) {
            hdr->unk0 |= (unsigned long)(unsigned int)sysbit_get(bs, 0x20);
            m = n - 7;
        } else {
            m = n - 3;
        }
        if (m != 0) {
            sysbit_jump(bs, m);
        }
        }
    } else if (hdr->unk0 == ((unsigned long)0xBC00 << 0x18) ||
               hdr->unk0 == ((unsigned long)0xBF00 << 0x18) ||
               hdr->unk0 == ((unsigned long)0xF000 << 0x18) ||
               hdr->unk0 == ((unsigned long)0xF100 << 0x18) ||
               hdr->unk0 == ((unsigned long)0xFF00 << 0x18) ||
               hdr->unk0 == ((unsigned long)0xF200 << 0x18) ||
               hdr->unk0 == ((unsigned long)0xF800 << 0x18)) {
        int n = hdr->unk8;
        if (hdr->unk0 == ((unsigned long)0xBF00 << 0x18)) {
            n -= 4;
            hdr->unk0 |= (unsigned long)(unsigned int)sysbit_get(bs, 0x20);
        }
        if (n != 0) {
            sysbit_jump(bs, n);
        }
    } else if (hdr->unk0 == ((unsigned long)0xBE00 << 0x18)) {
        if (hdr->unk8 != 0) {
            sysbit_jump(bs, hdr->unk8);
        }
    }
    return 1;
}

extern void sce_ipu_init(void);

/*
 * sceMpegInit (libmpeg.a:mpeg.o): one-time IOP/EE SIF hardware bring-up.
 * func_0011D960 presumably queries the DMA/SIF state, gating whether
 * func_0011D9A8 (a kick) runs; the SIF flag register at 0x1000F590 is set
 * then cleared (bit 0x10000, re-reading 0x1000F520 fresh each time), two
 * DMA channel control registers (0x1000B000/0x1000B400) have bit 0x100
 * masked off, and two more (0x1000B020/0x1000B420) are zeroed before the
 * tail call into func_0012D068.
 */
void sce_mpeg_init(void) {
    int r = disable_interrupts();

    *(volatile unsigned int *)0x1000F590 =
        *(volatile unsigned int *)0x1000F520 | 0x10000;
    *(volatile unsigned int *)0x1000B000 &= ~0x100;
    *(volatile unsigned int *)0x1000B400 &= ~0x100;
    *(volatile unsigned int *)0x1000F590 =
        *(volatile unsigned int *)0x1000F520 & ~0x10000;

    if (r != 0) {
        enable_interrupts();
    }

    *(volatile unsigned int *)0x1000B020 = 0;
    *(volatile unsigned int *)0x1000B420 = 0;
    sce_ipu_init();
}

extern void _Error(void *, void *);
/* memset returns its pointer: the unused return moves the first temporary
   after the call from $v0 to $v1. */
extern void *libc_memset_p(void *, int, unsigned int) __asm__("func_001153FC");
extern char mpeg_create_work_area_too_small_msg[];
extern void mpeg_work_area_init(void *, int, int);
extern unsigned int reserve_aligned_buffer_space(void *, char *, unsigned int, unsigned int);
extern void mpeg_clear_once(void *);
extern void sce_mpeg_reset(void *);
extern int sce_mpeg_clear_ref_buff(void *);
extern void mpeg_work_area_set_mark(void *);
extern void mpeg_stop_ipu_dma(void);
extern void mpeg_restart_ipu_dma(void);

/* Creates decoder state in the caller's work area. Returns 0 if it is too small.
   Success has no explicit return, matching the original code. */
int sce_mpeg_create(void *mpeg_handle, void *workarea, int size) {
    char *handle_bytes = (char *)mpeg_handle;
    unsigned int workarea_address = (unsigned int)workarea;
    char *aligned;
    char *work_area_descriptor;
    unsigned int avail;
    int neg1;

    libc_memset_p(workarea, 0, size);

    aligned = (char *)(((workarea_address + 3) >> 2) << 2);
    avail = (unsigned int)size - ((unsigned int)aligned - workarea_address);

    if (avail < 0x10C0) {
        _Error(aligned, mpeg_create_work_area_too_small_msg);
        return 0;
    }

    work_area_descriptor = aligned + 0x108;
    *(int *)(handle_bytes + 0x40) = (int)aligned;
    avail -= 0x10C0;
    mpeg_work_area_init(work_area_descriptor, (int)(aligned + 0x10C0), (int)avail);
    neg1 = -1;

    *(int *)(handle_bytes + 0x0) = 0;
    *(int *)(handle_bytes + 0x4) = 0;
    *(int *)(handle_bytes + 0x8) = 0;
    *(long *)(handle_bytes + 0x10) = -1;
    *(long *)(handle_bytes + 0x18) = -1;
    *(long *)(handle_bytes + 0x20) = 0;
    *(long *)(handle_bytes + 0x28) = -1;
    *(long *)(handle_bytes + 0x30) = -1;
    *(long *)(handle_bytes + 0x38) = 0;

    *(int *)(aligned + 0xB4) = 0;
    *(int *)(aligned + 0xB8) = 0;
    *(int *)(aligned + 0xBC) = 0;
    *(int *)(aligned + 0xC0) = 0;
    *(int *)(aligned + 0xC4) = 0;
    *(int *)(aligned + 0xC8) = 0;
    *(int *)(aligned + 0xCC) = 0;
    *(int *)(aligned + 0xD0) = 0;
    *(int *)(aligned + 0xD4) = 0;
    *(int *)(aligned + 0xD8) = 0;
    *(int *)(aligned + 0xDC) = 0;
    *(int *)(aligned + 0xE0) = 0;
    *(int *)(aligned + 0xE4) = 0;
    *(int *)(aligned + 0xE8) = 0;
    *(int *)(aligned + 0xF8) = 0;
    *(int *)(aligned + 0xC) = 0;
    *(int *)(aligned + 0x14) = 0;
    *(int *)(aligned + 0x2C) = 0;
    *(int *)(aligned + 0x34) = 0;
    *(int *)(aligned + 0x3C) = 0;
    *(long *)(aligned + 0xF0) = -1;
    *(int *)(aligned + 0x1C) = (int)mpeg_stop_ipu_dma;
    *(int *)(aligned + 0x24) = (int)mpeg_restart_ipu_dma;

    *(int *)(aligned + 0x44) = (int)reserve_aligned_buffer_space(aligned, work_area_descriptor, 0x600, 8);

    *(int *)(aligned + 0x48) = 0;
    *(int *)(aligned + 0xFC) = 0;
    *(int *)(aligned + 0x100) = 0;
    *(int *)(aligned + 0x104) = 0;
    *(int *)(aligned + 0x70) = 0;
    *(long *)(aligned + 0x78) = 0;
    *(int *)(aligned + 0x80) = neg1;
    *(long *)(aligned + 0x88) = 0;
    *(int *)(aligned + 0x90) = 0;
    *(int *)(aligned + 0xAC) = 0;
    *(int *)(aligned + 0x94) = neg1;
    *(int *)(aligned + 0x98) = neg1;
    *(int *)(aligned + 0x9C) = neg1;
    *(int *)(aligned + 0x858) = (int)handle_bytes;
    *(int *)(aligned + 0xB0) = 1;

    mpeg_clear_once(aligned);
    sce_mpeg_reset(handle_bytes);
    sce_mpeg_clear_ref_buff(handle_bytes);

    *(int *)(aligned + 0x1B8) = (int)(aligned + 0x1E8);
    *(int *)(aligned + 0x1BC) = (int)(aligned + 0x250);
    *(int *)(aligned + 0x1C4) = (int)(aligned + 0x2B8);
    *(int *)(aligned + 0x1C8) = (int)(aligned + 0x320);
    *(int *)(aligned + 0x1CC) = (int)(aligned + 0x388);
    *(int *)(aligned + 0x1D4) = (int)(aligned + 0x3F0);
    *(int *)(aligned + 0x1D8) = (int)(aligned + 0x458);
    *(int *)(aligned + 0x1DC) = (int)(aligned + 0x4C0);
    *(int *)(aligned + 0x1E4) = (int)(aligned + 0x528);

    mpeg_work_area_set_mark(work_area_descriptor);

    *(int *)(aligned + 0x850) = neg1;
    *(int *)(aligned + 0x84C) = 0;
    *(int *)(aligned + 0x81C) = 0x70003600;
    *(int *)(aligned + 0x854) = 0;
}

int sce_mpeg_delete(void) {
    return 1;
}

LINKER_REMNANT("asm/remnants/core_text", func_0012BB28);

extern int mpeg_getpic(void *);

int sce_mpeg_get_picture(char *p, unsigned int addr, int size) {
    char *t = *(char **)(p + 0x40);

    *(int *)(t + 0xB0) = 1;
    *(int *)(t + 0xD8) = (addr & 0x0FFFFFFF) | 0x20000000;
    *(int *)(t + 0xE4) = size;
    *(int *)(t + 0xE0) = 0;
    *(int *)(t + 0xDC) = 0;
    return mpeg_getpic(p);
}

LINKER_REMNANT("asm/remnants/core_text", func_0012BB78);

int sce_mpeg_is_end(char *p) {
    return **(int **)(p + 0x40);
}

int sce_mpeg_is_ref_buff_empty(void *mpeg_handle) {
    return ((Wrapper *)mpeg_handle)->obj->unk004 == 0;
}

extern void mpeg_clear_each(void *arg0);
extern void mpeg_set_mpeg1_mode(void *arg0);

/* Resets the decoder state and starts its MPEG-1 hardware setup. */
void sce_mpeg_reset(void *mpeg_handle) {
    char *handle_bytes = (char *)mpeg_handle;
    char *inner = *(char **)(handle_bytes + 0x40);

    *(int *)(inner + 0x0) = 0;
    *(int *)(inner + 0x4) = 0;
    *(int *)(inner + 0x8) = 0;
    *(int *)(handle_bytes + 0x8) = 0;
    *(int *)(inner + 0xAC) = 0;
    *(int *)(inner + 0x80) = -1;
    mpeg_clear_each(inner);
    *(int *)(inner + 0x118) = 0;
    mpeg_set_mpeg1_mode(inner);
}

int sce_mpeg_clear_ref_buff(void *mpeg_handle) {
    char *mpeg_state = *(char **)((char *)mpeg_handle + 0x40);
    char *reference_picture;
    reference_picture = *(char **)(mpeg_state + 0x1B8); if (reference_picture != 0) *(int *)(reference_picture + 0x28) = 0;
    reference_picture = *(char **)(mpeg_state + 0x1C8); if (reference_picture != 0) *(int *)(reference_picture + 0x28) = 0;
    reference_picture = *(char **)(mpeg_state + 0x1D8); if (reference_picture != 0) *(int *)(reference_picture + 0x28) = 0;
    reference_picture = *(char **)(mpeg_state + 0x1BC); if (reference_picture != 0) *(int *)(reference_picture + 0x28) = 0;
    reference_picture = *(char **)(mpeg_state + 0x1CC); if (reference_picture != 0) *(int *)(reference_picture + 0x28) = 0;
    reference_picture = *(char **)(mpeg_state + 0x1DC); if (reference_picture != 0) *(int *)(reference_picture + 0x28) = 0;
    return 1;
}

/* The callback table at +0x40: {callback, data} pairs from +0xC, one
   per callback type. */
typedef int (*MpegCbFn)(void *, void *, void *);
typedef struct { MpegCbFn func; void *data; } MpegCbEnt;
typedef struct { char pad[0xC]; MpegCbEnt cb[1]; } MpegCbTbl;

/* Registers a callback and its context for the type. Returns the previous callback. */
int sce_mpeg_add_callback(void *mpeg_handle, int callback_type, int callback_address, int callback_context) {
    MpegCbTbl *callback_table = *(MpegCbTbl **)((char *)mpeg_handle + 0x40);
    MpegCbFn old;
    callback_table->cb[callback_type].data = (void *)callback_context;
    old = callback_table->cb[callback_type].func;
    callback_table->cb[callback_type].func = (MpegCbFn)callback_address;
    return (int)old;
}

/* Calls the handler for the callback data's type. Returns 0 if no handler exists. */
void *dispatch_mpeg_callback(void *mpeg_handle, int *callback_data) {
    int ret = 0;
    if (mpeg_handle != 0) {
        MpegCbTbl *callback_table = *(MpegCbTbl **)((char *)mpeg_handle + 0x40);
        if (callback_table != 0) {
            if (callback_table->cb[*callback_data].func != 0) {
                ret = callback_table->cb[*callback_data].func(mpeg_handle, callback_data, callback_table->cb[*callback_data].data);
            }
        }
    }
    return (void *)ret;
}

/* Dispatches the no-data callback with type 1. */
void dispatch_mpeg_cb_nodata(int mpeg_handle) {
    int callback_data[8];
    callback_data[0] = 1;
    dispatch_mpeg_callback(mpeg_handle, callback_data);
}

LINKER_REMNANT("asm/remnants/core_text", func_0012BCF0);

void mpeg_work_area_init(void *allocator_data, int buffer_address, int buffer_size) {
    int *allocator_fields = (int *)allocator_data;
    allocator_fields[1] = buffer_size;
    allocator_fields[0] = buffer_address;
    allocator_fields[2] = buffer_address;
    allocator_fields[3] = buffer_address;
}

void mpeg_work_area_set_mark(void *allocator_data) {
    char *allocator_bytes = (char *)allocator_data;
    *(int *)(allocator_bytes + 0xC) = *(int *)(allocator_bytes + 0x8);
}

void mpeg_work_area_reset_to_mark(void *allocator_data) {
    char *allocator_bytes = (char *)allocator_data;
    *(int *)(allocator_bytes + 0x8) = *(int *)(allocator_bytes + 0xC);
}

extern void _Error(void *, void *);
extern char mpeg_work_area_size_too_small_msg[];

/* Bump allocator out of a region {base, size, used}: round `used` up to
   `align`, reserve `size` bytes, and hand back the aligned offset. On
   overflow it reports through func_0012C468 and returns 0 WITHOUT
   touching `used`.

   The fitting case is written first (`>=`): 2.9-ee then branches to the
   report on the true side (bnel) and puts the `used` store in the slot
   of the fall-through `b`, as retail. Written overflow-first, as 2.95.3
   needed, 2.9-ee inverts the test and puts the store in a beql slot,
   one instruction short (SIZE 104/108). */
unsigned int reserve_aligned_buffer_space(void *arg0, char *r, unsigned int size,
                           unsigned int align) {
    unsigned int aligned;
    unsigned int end;

    aligned = ((*(unsigned int *)(r + 0x8) + align - 1) / align) * align;
    end = aligned + size;
    if (*(unsigned int *)(r + 0x0) + *(unsigned int *)(r + 0x4) >= end) {
        *(unsigned int *)(r + 0x8) = end;
        return aligned;
    }
    _Error(arg0, mpeg_work_area_size_too_small_msg);
    return 0;
}

extern int mpeg_next_header(void *);
extern int mpeg_flush_last_frame(void *);
extern int mpeg_decode_or_skip(void *, int, int);
/* _errMessage (func_0012C430) sprintf's its format and passes the
   format's arguments on untouched in $a1-$a3, so it is called here
   without a prototype, with the value the "%08x" reports. */
extern void _errMessage();
extern char mpeg_image_buffer_unaligned_msg[];

/* Reads picture headers and decodes or skips a picture. Rejects an unaligned image buffer. */
int mpeg_getpic(void *mpeg_handle) {
    int pictureType = 1;
    int lastResult = 0;
    char *handle_bytes = (char *)mpeg_handle;
    char *inner = *(char **)(handle_bytes + 0x40);

    *(int *)inner = 0;
    if ((*(int *)(inner + 0xD8) & 0x3F) != 0) {
        _errMessage(inner, mpeg_image_buffer_unaligned_msg, *(int *)(inner + 0xD8));
        return -1;
    }
    *(int *)(inner + 0x820) = 0;

    do {
        if (lastResult != -1) {
            for (;;) {
                pictureType = mpeg_next_header(inner);
                if (pictureType == 0) break;
                if (*(int *)(inner + 0x174) == *(int *)(inner + 0xD4)) break;
                if (*(int *)(inner + 0x848) == 0) break;
            }
        }

        switch (pictureType) {
        case 0:
            mpeg_flush_last_frame(handle_bytes);
            *(int *)inner = 1;
            break;
        case 1:
            *(int *)(inner + 0xA8) = 0;
            *(int *)(inner + 0xA4) = 0;
            *(int *)(inner + 0xA0) = 0;
            lastResult = mpeg_decode_or_skip(handle_bytes, 0, *(int *)(inner + 0x94));
            *(int *)(inner + 0xA0) = *(int *)(inner + 0xA0) + 1;
            break;
        case 2:
            lastResult = mpeg_decode_or_skip(handle_bytes, *(int *)(inner + 0xA4), *(int *)(inner + 0x98));
            *(int *)(inner + 0xA4) = *(int *)(inner + 0xA4) + 1;
            break;
        case 3:
        case 4:
            lastResult = mpeg_decode_or_skip(handle_bytes, *(int *)(inner + 0xA8), *(int *)(inner + 0x9C));
            *(int *)(inner + 0xA8) = *(int *)(inner + 0xA8) + 1;
            break;
        }

        if (*(int *)(inner + 0x820) != 0) {
            return 1;
        }
    } while (*(int *)inner == 0);

    return 1;
}

extern int mpeg_update_ref_image(void *, int);
extern int mpeg_dec_picture(void *);
extern void mpeg_output_frame(void *, int, int);

/* _decodeOrSkipFrame (libmpeg): sibling of func_0012C0A0
   (_decodeOrSkipField), for the frame-picture path. Adapted from
   Lombyte's project (GPL-3.0) for PAL. */
int mpeg_decode_or_skip_frame(void *mpeg_handle, int picture_count, int decode_limit) {
    Wrapper *w = (Wrapper *)mpeg_handle;
    Obj40 *p = w->obj;
    int flag = 0;
    int t;
    int ret;

    if (decode_limit == -1 || picture_count < decode_limit) {
        if (p->unk008 == 0) {
            w->unk08 = 0;
            p->unk008 = 1;
        }
        if (mpeg_update_ref_image(p, 0) == 0) {
            t = 0;
        } else {
            t = 0;
            t = mpeg_dec_picture(p) != t;
        }
        ret = t;
    } else {
        flag = 1;
        ret = mpeg_update_ref_image(p, 0);
        dispatch_mpeg_cb_nodata((int)w);
    }
    mpeg_output_frame(p, p->unk118, p->unk004);
    if (p->unk174 != 3 && flag == 0) {
        p->unk120 = (p->unk120 == 0);
    }
    w->unk08 = p->unk118 - p->unk0AC;
    if (p->unk120 == 0) {
        p->unk118 = p->unk118 + 1;
        p->unk004 = p->unk004 + 1;
    }
    return ret;
}

extern int mpeg_decode_or_skip_field(void *, int, int);
extern int mpeg_decode_or_skip_frame(void *, int, int);

/* Routes to the frame or field decoder using the current picture structure. */
int mpeg_decode_or_skip(void *mpeg_handle, int picture_count, int decode_limit) {
    Obj40 *inner = ((Wrapper *)mpeg_handle)->obj;
    if (inner->unk174 != 3) {
        return mpeg_decode_or_skip_field(mpeg_handle, picture_count, decode_limit);
    } else {
        return mpeg_decode_or_skip_frame(mpeg_handle, picture_count, decode_limit);
    }
}

struct MpegFieldDec
{
  int unk0;
  int unk4;
  int unk8;
  unsigned char pad_C[0xA0];
  int unkAC;
  unsigned char pad_B0[0x24];
  int unkD4;
  unsigned char pad_D8[0x40];
  int unk118;
  int unk11C;
  int unk120;
  unsigned char pad_124[0x50];
  int unk174;
};
struct MpegHandle
{
  unsigned char pad_0[0x8];
  int unk8;
  unsigned char pad_C[0x34];
  struct MpegFieldDec *unk40;
};
extern int mpeg_dec_picture();
extern int mpeg_update_ref_image();
extern void mpeg_output_frame();
/* _decodeOrSkipField (libmpeg). Adapted from Lombyte's project (GPL-3.0) for PAL. */
int mpeg_decode_or_skip_field(void *handle, int picture_count, int decode_limit)
{
  struct MpegHandle *typed_handle = handle;
  struct MpegFieldDec *field_decoder;
  int decode;
  unsigned int ref;
  int want;
  long r;
  int ret;
  int gate;
  decode = 0;
  field_decoder = typed_handle->unk40;
  field_decoder->unk120 = 0;
  if ((decode_limit == (-1)) || (picture_count < decode_limit))
  {
    decode = 1;
  }
  if (field_decoder->unk8 == 0)
  {
    typed_handle->unk8 = 0;
    field_decoder->unk8 = 1;
  }
  r = mpeg_update_ref_image(field_decoder, 0);
  if ((r != 0) && (decode != 0))
  {
    mpeg_dec_picture(field_decoder);
  }
  field_decoder->unk120 = 1;
  r = mpeg_next_header(field_decoder);
  if (r == 0)
  {
    mpeg_flush_last_frame(typed_handle);
    field_decoder->unk0 = 1;
    return 0;
  }
  want = 2;
  if (field_decoder->unkD4 != 1)
  {
    want = 1;
  }
  if (field_decoder->unk174 != want)
  {
    return -1;
  }
  ref = mpeg_update_ref_image(field_decoder, 1);
  gate = 0;
  if (ref != 0)
  {
    gate = 1;
  }
  ret = 0;
  if (gate != 0)
  {
    if (decode == 0)
    {
      goto out;
    }
    r = mpeg_dec_picture(field_decoder);
    if (r != 0)
    {
      ret = 1;
    }
  }
  out:
  mpeg_output_frame(field_decoder, field_decoder->unk118, field_decoder->unk4);

  field_decoder->unk120 = 0;
  typed_handle->unk8 = field_decoder->unk118 - field_decoder->unkAC;
  field_decoder->unk118 = field_decoder->unk118 + 1;
  field_decoder->unk4 = (unsigned long long) (field_decoder->unk4 + 1);
  if (decode == 0)
  {
    dispatch_mpeg_cb_nodata((int)typed_handle);
  }
  return ret;
}

extern void mpeg_last_frame(void *);

int mpeg_flush_last_frame(void *mpeg_handle) {
    Wrapper *handle_bytes = (Wrapper *)mpeg_handle;
    Obj40 *inner = handle_bytes->obj;
    int ret = 0;

    if (inner->unk004 != 0 && inner->unk008 != 0) {
        mpeg_last_frame((void *)inner);
        handle_bytes->unk08 = inner->unk118 - inner->unk0AC;
        inner->unk004 = 0;
        ret = 1;
    }
    return ret;
}

/* Selects MPEG-1 mode in the decoder and IPU. */
void mpeg_set_mpeg1_mode(void *mpeg_state) {
    *(int *)((char *)mpeg_state + 0x848) = 0;
    ipu_set_mpeg1(1);
}

extern void _dispRefImage(void *, int, int, int);
extern char mpeg_second_field_missing_msg[];

/* _lastFrame (libmpeg): at the end of the stream, report an error if a
   second field is still pending, else display the last reference picture
   (whole frame when the picture structure is 3, else its two fields) as
   frame count - 1; then clear the pending-field flag.
   Adapted from Lombyte's project (GPL-3.0): src/sdk/library/_lastFrame.c, _lastFrame. */
typedef struct {
    u8 pad0[0x118];
    s32 frame_count;         /* 0x118 */
    u8 pad11C[4];
    s32 second_field;        /* 0x120 */
    u8 pad124[0x50];
    s32 picture_structure;   /* 0x174 */
    u8 pad178[0x40];
    void *ref_images[10];    /* 0x1B8 */
} MpegDecoder_12C278;

extern s32 _Error_lf(MpegDecoder_12C278 *, u8 *, s32) __asm__("func_0012C468");
extern s32 _dispRefImage_lf(MpegDecoder_12C278 *, void *, s32) __asm__("func_00129E30");
extern s32 _dispRefImageField_lf(MpegDecoder_12C278 *, void *, void *, s32) __asm__("func_00129F40");
extern u8 mpeg_second_field_missing_msg_lf[] __asm__("D_00153BB8");

void mpeg_last_frame(void *mpeg_state) {
    MpegDecoder_12C278 *decoder = (MpegDecoder_12C278 *)mpeg_state;
    s32 count;
    count = decoder->frame_count;
    if (decoder->second_field != 0) {
        _Error_lf(decoder, mpeg_second_field_missing_msg_lf, count);
    } else {
        if (decoder->picture_structure == 3) {
            _dispRefImage_lf(decoder, decoder->ref_images[1], count - 1);
        } else {
            _dispRefImageField_lf(decoder, decoder->ref_images[5], decoder->ref_images[9], count - 1);
        }
    }
    decoder->second_field = 0;
}

/* Sets the decoder scratchpad pointers and clears its state flag.
   Keep scratchpad_base initialized before the call to preserve register allocation. */
void mpeg_clear_once(void *mpeg_state) {
    char *state_bytes = (char *)mpeg_state;
    int scratchpad_base = 0x70000000;

    ipu_set_mpeg1(1);
    *(int *)(state_bytes + 0x590) = scratchpad_base;
    *(int *)(state_bytes + 0x594) = 0x70001800;
    *(int *)(state_bytes + 0x6D0) = 0x70001B00;
    *(int *)(state_bytes + 0x6D4) = 0x70003300;
    *(int *)(state_bytes + 0x810) = 0;
}

extern void sce_ipu_sync(int, int);

/* Resets stream flags and DMA channels, then resets and waits for the IPU. */
void mpeg_clear_each(void *mpeg_state) {
    char *state_bytes = (char *)mpeg_state;
    int interrupt_state;

    *(int *)(state_bytes + 0x818) = 1;
    *(int *)(state_bytes + 0x1B0) = 0;
    interrupt_state = disable_interrupts();

    *(volatile unsigned int *)0x1000F590 =
        *(volatile unsigned int *)0x1000F520 | 0x10000;
    *(volatile unsigned int *)0x1000B000 = 0;
    *(volatile unsigned int *)0x1000B400 = 0;
    *(volatile unsigned int *)0x1000D400 = 0;
    *(volatile unsigned int *)0x1000F590 =
        *(volatile unsigned int *)0x1000F520 & ~0x10000;

    if (interrupt_state != 0) {
        enable_interrupts();
    }

    *(volatile unsigned int *)0x1000B020 = 0;
    *(volatile unsigned int *)0x1000B420 = 0;
    *(volatile unsigned int *)0x1000D420 = 0;
    *(volatile unsigned int *)0x10002010 = 0x40000000;
    sce_ipu_sync(0, 0);
}

extern char mpeg_error_format[];
/* Unprototyped: func_0011A6C8 is a varargs definition (blocked as such),
   but calling one is fine -- only defining one needs stdarg.h. */
extern void scePrintf();

void mpeg_print_error(void *message) {
    scePrintf(mpeg_error_format, message);
}

extern int sprintf_f(char *, char *, int) __asm__("func_00116248");

void _errMessage(void *mpeg_state, char *fmt, int code) {
    char formatted_message[0x100];
    sprintf_f(formatted_message, fmt, code);
    _Error(mpeg_state, formatted_message);
}

extern void mpeg_print_error(void *);

void _Error(void *mpeg_state, void *message) {
    char *state_bytes = (char *)mpeg_state;
    void *mpeg_handle = *(void **)(state_bytes + 0x858);
    /* The null guard intentionally follows the state access. */
    if (mpeg_handle != 0 && mpeg_state != 0 && *(int *)(state_bytes + 0xC) != 0) {
        int callback_data[4];
        callback_data[0] = 0;
        callback_data[1] = (int)message;
        dispatch_mpeg_callback(mpeg_handle, callback_data);
    } else {
        mpeg_print_error(message);
    }
}

/* Stores frame dimensions and their 16-pixel macroblock counts. */
int mpeg_set_frame_size(void *frame_layout, int width, int height) {
    char *layout_bytes = (char *)frame_layout;
    *(int *)(layout_bytes + 0x4) = width;
    *(int *)(layout_bytes + 0x8) = height;
    *(int *)(layout_bytes + 0xC) = width >> 4;
    *(int *)(layout_bytes + 0x10) = height >> 4;
    return 1;
}

extern int _nextBit(void *, int);
extern void _Error(void *, void *);
extern char mpeg_vertical_size_too_large_msg[];
extern void send_ipu_command(void *, unsigned int);
extern void mpeg_set_default_qm(void *, int, int);
extern char mpeg_default_intra_qm[];
extern char mpeg_default_non_intra_qm[];
extern void _extensionAndUserData(void *);
extern void mpeg_init_seq(void *);

/* Reads sequence fields and quantization tables, then initializes the sequence. */
void _sequenceHeader(void *mpeg_state) {
    char *state_bytes = (char *)mpeg_state;
    unsigned int header_bits;
    int vertical_size;
    unsigned int flag;

    *(unsigned int *)(state_bytes + 0xD4) = 0;

    header_bits = _nextBit(state_bytes, 0x20);
    *(unsigned int *)(state_bytes + 0x124) = header_bits >> 20;
    vertical_size = (header_bits >> 8) & 0xFFF;
    *(unsigned int *)(state_bytes + 0x128) = vertical_size;
    if (vertical_size >= 0xAF1) {
        _Error(state_bytes, mpeg_vertical_size_too_large_msg);
    }

    header_bits = _nextBit(state_bytes, 0x1E);
    *(unsigned int *)(state_bytes + 0x134) = header_bits >> 12;
    *(unsigned int *)(state_bytes + 0x138) = (header_bits >> 1) & 0x3FF;

    flag = _nextBit(state_bytes, 1);
    *(unsigned int *)(state_bytes + 0x840) = flag;
    if (flag != 0) {
        wait_ipu_idle(state_bytes);
        send_ipu_command(state_bytes, 0x50000000);
        wait_ipu_idle(state_bytes);
    } else {
        mpeg_set_default_qm(state_bytes, 0x50000000, (int)mpeg_default_intra_qm);
    }

    flag = _nextBit(state_bytes, 1);
    *(unsigned int *)(state_bytes + 0x844) = flag;
    if (flag != 0) {
        wait_ipu_idle(state_bytes);
        send_ipu_command(state_bytes, 0x58000000);
        wait_ipu_idle(state_bytes);
    } else {
        mpeg_set_default_qm(state_bytes, 0x58000000, (int)mpeg_default_non_intra_qm);
    }

    _extensionAndUserData(state_bytes);
    mpeg_init_seq(*(void **)(state_bytes + 0x858));
}

void mpeg_init_seq(void *mpeg_handle) {
    extern void mpeg_init_ref_image_addrs(unsigned int *, unsigned int *, unsigned int *, unsigned int *,
                              unsigned int *, unsigned int *, unsigned int *, unsigned int *,
                              unsigned int *, int, int, int, int, int);
    int *handle_words = (int *)mpeg_handle;
    char *state_bytes = *(char **)((char *)mpeg_handle + 0x40);
    int mpeg2_mode = *(int *)(state_bytes + 0x848);
    int h, mbw, mbh;
    unsigned int n, t;
    unsigned int *q0, *q1, *q2, *q3, *q4, *q5, *q6, *q7, *q8;

    if (mpeg2_mode == 0) {
        *(int *)(state_bytes + 0x174) = 3;
        *(int *)(state_bytes + 0x13C) = 1;
        *(int *)(state_bytes + 0x140) = 1;
        *(int *)(state_bytes + 0x188) = 1;
        *(int *)(state_bytes + 0x17C) = 1;
        *(int *)(state_bytes + 0x144) = 5;
    }
    *(int *)(state_bytes + 0x12C) = (*(int *)(state_bytes + 0x124) + 0xF) >> 4;
    if (mpeg2_mode != 0 && *(int *)(state_bytes + 0x13C) == 0)
        h = ((*(int *)(state_bytes + 0x128) + 0x1F) >> 5) << 1;
    else
        h = (*(int *)(state_bytes + 0x128) + 0xF) >> 4;
    *(int *)(state_bytes + 0x130) = h;
    mbh = h << 4;
    mbw = *(int *)(state_bytes + 0x12C) << 4;
    {
    unsigned int *p;
    if (mbw != handle_words[0]) {
        p = (unsigned int *)(state_bytes + 0x528);
    } else {
        if (mbh == handle_words[1])
            return;
        p = (unsigned int *)(state_bytes + 0x528);
    }
    handle_words[0] = mbw;
    handle_words[1] = mbh;
    if ((mbw & 0xF) && (mbw & 0xE))
        p = q8;
    q8 = p;
    t = mbh * 0x180;
    q0 = (unsigned int *)(state_bytes + 0x1E8);
    q1 = (unsigned int *)(state_bytes + 0x250);
    q2 = (unsigned int *)(state_bytes + 0x2B8);
    q3 = (unsigned int *)(state_bytes + 0x320);
    q4 = (unsigned int *)(state_bytes + 0x388);
    q5 = (unsigned int *)(state_bytes + 0x3F0);
    q6 = (unsigned int *)(state_bytes + 0x458);
    q7 = (unsigned int *)(state_bytes + 0x4C0);
    n = (mbw * t) >> 8;
    mpeg_work_area_reset_to_mark(state_bytes + 0x108);
    *(unsigned int *)(state_bytes + 0xFC) = reserve_aligned_buffer_space(state_bytes, state_bytes + 0x108, n, 0x40);
    *(unsigned int *)(state_bytes + 0x100) = reserve_aligned_buffer_space(state_bytes, state_bytes + 0x108, n, 0x40);
    *(unsigned int *)(state_bytes + 0x104) = reserve_aligned_buffer_space(state_bytes, state_bytes + 0x108, n, 0x40);
    mpeg_init_ref_image_addrs(q0, q1, q2,
                  q3, q4, q5,
                  q6, q7, q8,
                  *(int *)(state_bytes + 0xFC), *(int *)(state_bytes + 0x100), *(int *)(state_bytes + 0x104), mbw, mbh);
    mpeg_set_frame_size(q0, mbw, mbh);
    mpeg_set_frame_size(q1, mbw, mbh);
    mpeg_set_frame_size(q2, mbw, mbh);
    mpeg_set_frame_size(q3, mbw, mbh >> 1);
    mpeg_set_frame_size(q4, mbw, mbh >> 1);
    mpeg_set_frame_size(q5, mbw, mbh >> 1);
    mpeg_set_frame_size(q6, mbw, mbh >> 1);
    mpeg_set_frame_size(q7, mbw, mbh >> 1);
    mpeg_set_frame_size(q8, mbw, mbh >> 1);
    }
}

void mpeg_init_ref_image_addrs(unsigned int *o0, unsigned int *o1, unsigned int *o2, unsigned int *o3,
                   unsigned int *o4, unsigned int *o5, unsigned int *o6, unsigned int *o7,
                   unsigned int *o8, int a, int b, int c, int w, int h) {
    unsigned int x = (a & 0xFFFFFFF) | 0x20000000;
    unsigned int y = (b & 0xFFFFFFF) | 0x20000000;
    unsigned int z = (c & 0xFFFFFFF) | 0x20000000;
    int q = (w * h) / 512;
    int s6, s7, s8;
    s6 = q * 384; s6 += a;
    s7 = q * 384; s7 += b;
    s8 = q * 384; s8 += c;
    *o0 = x; *o1 = y; *o2 = z; *o3 = x; *o4 = y; *o5 = z;
    *o6 = (s6 & 0xFFFFFFF) | 0x20000000;
    *o7 = (s7 & 0xFFFFFFF) | 0x20000000;
    *o8 = (s8 & 0xFFFFFFF) | 0x20000000;
}

/* _setDefaultQM: tell the callback (type 2) that the default quantiser
   matrix load starts, then with the IPU idle and reset, DMA the matrix
   at addr to IPU_TO (tag 4 qwords, chcr 0x101) with interrupts held
   off, send command cmd and wait, and report type 3. Adapted from
   Lombyte's project (GPL-3.0) for PAL. */
void mpeg_set_default_qm(void *arg, int cmd, int addr) {
    char *mp = arg;
    int cb[8];
    int intr;

    cb[0] = 2;
    dispatch_mpeg_callback(*(void **)(mp + 0x858), cb);
    wait_ipu_idle(mp);
    *(volatile int *)0x10002000 = 0;
    wait_ipu_idle(mp);
    intr = disable_interrupts();
    *(volatile int *)0x1000B410 = addr & 0x0FFFFFFF;
    *(volatile int *)0x1000B420 = 4;
    *(volatile int *)0x1000B400 = 0x101;
    if (intr != 0) {
        enable_interrupts();
    }
    send_ipu_command(mp, cmd);
    wait_ipu_idle(mp);
    cb[0] = 3;
    dispatch_mpeg_callback(*(void **)(mp + 0x858), cb);
}

extern void _Error(void *, void *);
extern char mpeg_chroma_format_not_420_msg[];
extern char mpeg_unsupported_profile_level_msg[];

/*
 * _sequenceExtension (libmpeg.a:init.o): ISO/IEC 13818-2 6.2.2.3
 * sequence_extension(), matching mpeg2decode's gethdr.c almost line for
 * line but reading two combined bitfields with func_00128A58: a 28-bit
 * fetch covers profile_and_level_indication(8) + progressive_sequence(1)
 * + chroma_format(2) + horizontal_size_extension(2) +
 * vertical_size_extension(2) + bit_rate_extension(12) + marker_bit(1); a
 * 16-bit fetch covers vbv_buffer_size_extension(8) + low_delay(1) +
 * frame_rate_extension_n(2) + frame_rate_extension_d(5) (the last three
 * read and dropped). chroma_format must be 1 (4:2:0) and
 * profile_and_level_indication one of three literal bytes (0x48/0x58/
 * 0x44); either failing reports through func_0012C468. Ends by folding
 * the extension bits into sequenceHeader's fields exactly as the
 * reference decoder's
 * `horizontal_size = (horizontal_size_extension<<12) | (horizontal_size&0xfff)`
 * et al.
 */
void _sequenceExtension(void *arg0) {
    char *s = (char *)arg0;
    unsigned int v1, v2;
    unsigned int chroma_format, h_ext, v_ext, bitrate_ext;
    unsigned int progressive, profile, vbv_ext;

    *(int *)(s + 0x848) = 1;
    ipu_set_mpeg1(0);

    v1 = _nextBit(s, 0x1C);
    bitrate_ext = (v1 >> 1) & 0xFFF;
    chroma_format = (v1 >> 17) & 3;
    v_ext = (v1 >> 13) & 3;
    h_ext = (v1 >> 15) & 3;

    *(unsigned int *)(s + 0x140) = chroma_format;
    if (chroma_format != 1) {
        _Error(s, mpeg_chroma_format_not_420_msg);
    }

    progressive = (v1 >> 19) & 1;
    *(unsigned int *)(s + 0x13C) = progressive;
    profile = v1 >> 20;

    v2 = _nextBit(s, 0x10);
    vbv_ext = v2 >> 8;

    if (profile != 0x48 && profile != 0x58 && profile != 0x44) {
        _Error(s, mpeg_unsupported_profile_level_msg);
    }

    *(int *)(s + 0x124) = (h_ext << 12) | (*(int *)(s + 0x124) & 0xFFF);
    *(int *)(s + 0x128) = (v_ext << 12) | (*(int *)(s + 0x128) & 0xFFF);
    *(int *)(s + 0x134) += bitrate_ext << 18;
    *(int *)(s + 0x138) += vbv_ext << 10;
}


/*
 * MPEG-2 sequence_display_extension(): video_format (3 bits), then
 * colour_description (1) and, when set, colour_primaries,
 * transfer_characteristics and matrix_coefficients (8 each; the last is
 * kept at +0x144); display_horizontal_size (14) to +0x148, a marker
 * bit, display_vertical_size (14) to +0x14C.
 *
 * Plain C, exact under 2.9-ee. (Under 2.95.3 it needed the marker bit's
 * read to go through a void view of the reader, `func_00128A58_v`: as a
 * value call it reset $v0's readers and the +0x148 store lost the
 * scheduler tie to the next call's argument setup, 8/140.)
 */
void _sequenceDisplayExtension(void *arg0) {
    char *s = (char *)arg0;

    _nextBit(s, 3);
    if (_nextBit(s, 1) != 0) {
        _nextBit(s, 8);
        _nextBit(s, 8);
        *(int *)(s + 0x144) = _nextBit(s, 8);
    }
    *(int *)(s + 0x148) = _nextBit(s, 0xE);
    _nextBit(s, 1);
    *(int *)(s + 0x14C) = _nextBit(s, 0xE);
}

extern char mpeg_sequence_scalable_ext_msg[];
extern char mpeg_unknown_extension_msg[];
extern char mpeg_picture_spatial_scalable_ext_msg[];

/* Three more of the func_0012C468 family, same shape as func_0012CC60. */
void _sequenceScalableExtension(void *arg0) {
    _Error(arg0, mpeg_sequence_scalable_ext_msg);
}

void report_unknown_mpeg_extension(void *arg0) {
    _Error(arg0, mpeg_unknown_extension_msg);
}

void _pictureSpatialScalableExtension(void *arg0) {
    _Error(arg0, mpeg_picture_spatial_scalable_ext_msg);
}

extern char mpeg_picture_temporal_scalable_ext_msg[];

/* Tail call: arg0 passes straight through, arg1 is &D_00153CC8 whose
   %lo half retail schedules into the jump's delay slot. */
void _pictureTemporalScalableExtension(void *arg0) {
    _Error(arg0, mpeg_picture_temporal_scalable_ext_msg);
}

INCLUDE_ASM("asm/nonmatchings/core_text", func_0012CC6C);
