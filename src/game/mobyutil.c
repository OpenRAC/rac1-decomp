#include "common.h"
#include "moby.h"
#include "callees.h"
#include "records.h"
#include "structs.h"

/*
 * mobyutil.cpp in the original source; text 0x213A78-0x2161E0.
 * Name and boundary from the NTSC split of this game, mapped to PAL by matching function
 * sizes -- see docs/DECOMP_PROGRESS.md. Compiled as C for now.
 */

/* Declarations in scope here before the split. */
extern char voice_pool[];
extern int bank_sound_count;
extern void FastMemCopy(void *, void *, int);
extern char backup_cam[];
extern char gCamBackupState[];
extern void *cur_cam NOT_SDA;
extern DispatchRec camera_types[];
extern int draw_config[];
extern void FastMemSet();
extern void BuildOcclVisibility(void);
extern int occl_update NOT_SDA;
extern char occl_visibility[];
extern long gs_display_settings[3];
extern int space_load_in_progress;
extern short draw_enable_mask;
extern void append_gif_transfer_packet(void);
extern void DrawDebugProfiler(void);
extern int draw_callback_count;
extern int draw_callback_args[];
extern int draw_callback_funcs[];
extern short GlobalStateFlag;
extern int measure_text_width(unsigned char *arg0, int arg1, void *arg2);
extern unsigned char normal_font_metrics[];
extern unsigned char small_font_metrics[];
extern unsigned char large_font_metrics[];
extern void FontPrint(void *, void *, void *, void *, void *, int,
                          unsigned char *);
extern int measure_text_width_regular(unsigned char *, int);
extern int measure_text_width_small(unsigned char *, int);
extern int GetEffectTex(int);
extern void PutDrawBufferLarge(void);
extern void InitViewContext(void);
extern void UpdateViewContext(void);
extern int bit_swap_lut[];
extern long background_rgbaq NOT_SDA;
extern int Help_FindIndex(void);
extern char s_paradox_this_message_does_not[];
extern short help_msgs;
extern int hud_heap_base NOT_SDA;
extern int hud_state NOT_SDA;
extern int Hud_GetIconIndex(int);
typedef struct {
    char b[0x13];
} Cfg13;
extern Cfg13 message_text_buffer NOT_SDA;
extern Cfg13 message_too_long_label NOT_SDA;
extern int libc_strlen(void);
extern void libc_strcpy(Cfg13 *, void *);
extern short ResourceCounter;
extern void draw_stretchable_ui_frame(int, int, int, int, int);
extern void CreatePointLight(int);
extern void DetachPointLight(int);
extern void update_world_object_animation(void *);
extern int render_sequence NOT_SDA;
extern int vu1_chain_buffer_2 NOT_SDA;
extern int current_vu_chain;
extern int map_slot_use[];
extern void move_map_entry_slot(int a, int b);
extern PadSlots level_map_selection_slots __asm__("D_001A01F0");
extern int level_map_selection[];
extern int *menu_level_indices;
extern unsigned char menu_item_enabled_0 NOT_SDA;
extern unsigned char g_menu_item_enabled_1 NOT_SDA;
extern unsigned char menu_item_enabled_9 NOT_SDA;
extern short menu_selection_count;
extern unsigned char menu_item_enabled_16 NOT_SDA;
extern unsigned char menu_item_enabled_17 NOT_SDA;
extern unsigned char menu_item_enabled_18 NOT_SDA;
extern unsigned char menu_item_enabled_19 NOT_SDA;
extern unsigned char menu_item_enabled_25 NOT_SDA;
extern int map_region_enabled_3 NOT_SDA;
extern unsigned char menu_item_enabled_41 NOT_SDA;
extern int hero_control_mode NOT_SDA;
extern unsigned char menu_item_enabled_36 NOT_SDA;
extern unsigned char menu_item_enabled_37 NOT_SDA;
extern unsigned char menu_item_enabled_38 NOT_SDA;
extern unsigned char menu_item_enabled_55 NOT_SDA;
extern unsigned char menu_item_enabled_56 NOT_SDA;
extern unsigned char menu_item_enabled_57 NOT_SDA;
extern unsigned char menu_item_enabled_68;
extern unsigned char menu_item_enabled_64 NOT_SDA;
extern unsigned char menu_item_enabled_65 NOT_SDA;
extern unsigned char menu_item_enabled_66 NOT_SDA;
extern unsigned char menu_item_enabled_67 NOT_SDA;
extern unsigned char menu_item_enabled_69 NOT_SDA;
extern unsigned char menu_item_enabled_77 NOT_SDA;
extern unsigned char menu_item_enabled_102 NOT_SDA;
extern unsigned char menu_item_enabled_103 NOT_SDA;
extern unsigned char menu_item_enabled_104 NOT_SDA;
extern unsigned char menu_item_enabled_105 NOT_SDA;
extern unsigned char menu_item_enabled_115 NOT_SDA;
extern int max_map_coverage_size[];
extern void DebugEnter_Nop(void);
extern int compress_map_coverage(void *dst, int size, int a, int b);
extern void downsample_map_coverage(void *dst);
extern short g_current_level_index;
extern int g_current_level_index_far __asm__("D_0015EE84") NOT_SDA;
extern int map_coverage_active[] NOT_SDA;
extern void decode_compressed_occlusion_map(void *, unsigned char *, int);
extern void expand_map_coverage(void *, unsigned char *);
extern char memory_card_state[];
extern short mode_freeze_state;
extern int mode_freeze_flags;
extern int mc_gamedata[];
extern int mc_leveldata[];
extern int memcard_GetDataSize(int *p);
extern int memcard_PrepData(void *dst, int i, int *table);
extern int sce_mc_init(void);
extern int STUB_printf();
extern char memcard_error_message[];
extern int race_gates_24_status NOT_SDA;
extern unsigned char menu_item_enabled_12 NOT_SDA;
extern int race_gates_47_flag NOT_SDA;
extern unsigned char gSpecialItems[];
extern unsigned char gHaveHeliPack NOT_SDA;
extern int race_gates NOT_SDA;
extern int race_gates_66_status NOT_SDA;
extern unsigned char menu_item_enabled_73 NOT_SDA;
extern int race_gates_70_status NOT_SDA;
extern unsigned char menu_item_enabled_85 NOT_SDA;
extern int race_gates_87_status NOT_SDA;
extern unsigned char race_gates_base NOT_SDA;
extern int item_available NOT_SDA;
extern unsigned char menu_item_enabled_20 NOT_SDA;
extern unsigned char gemlik_available NOT_SDA;
extern unsigned char gHaveMorphORay NOT_SDA;
extern unsigned char gHaveHologuise NOT_SDA;
extern int moby_render_slots[];
extern void copy_matrix_rotation_2(void *, void *) __asm__("func_001FA460");
extern void FastVecScale(void *, void *, float);
extern void FastVecAdd(void *, void *, void *);
extern void matrix_mul_vec3(void *, void *, void *);
extern int g_hero_moby NOT_SDA;
extern float shadow_light_dir[] NOT_SDA;
extern float FastCos(float);
extern float FastSin(float);
extern void flush_cache(int);
extern char normal_lut[];
extern int render_packet_end;
extern short vu1_chain_safe_end;
extern char moby_backup_buffer[];
extern float FastAbsF(float arg0);
extern int find_or_allocate_id_slot(int v);
extern void prune_moby_references(void);

ASM_FUNC("asm/handwritten/text", func_00213A78);

LINKER_REMNANT("asm/remnants/text", func_00213BAC);

typedef struct {
    int key;
    int a;
    int b;
} Rec0C;
extern Rec0C moby_class_data_table[];
extern int resident_moby_class_data[];
extern char *moby_class_resources[];
extern int resident_moby_class_count MACRO_ADDR;

/* Looks arg0 up in the {key, a, b} table D_001E8F00 (ended by key -1).
   D_00160000 is read at every use, not cached in a local: CSE then
   reproduces retail's load order and its surviving register copy. */
struct Obj {
    u8 pad_00[0x2C];
    s32 extra;                       /* 0x2C */
};

/* Looks id up in the {key, a, b} table D_001E8F00 (ended by key -1).
   D_00160000 is read at every use, not cached in a local: CSE then
   reproduces retail's load order and its surviving register copy. */

/* The -1 key is also the fallback entry: a missing id uses its values rather
   than leaving the current resident class slot unchanged. */
void assign_moby_class_data(int id) {
    struct Obj *class_resource;
    int i = 0;

    class_resource = moby_class_resources[resident_moby_class_count];
    while (moby_class_data_table[i].key != -1 && moby_class_data_table[i].key != id) {
        i++;
    }
    resident_moby_class_data[resident_moby_class_count] = moby_class_data_table[i].a;
    if (class_resource != 0) {
        ((struct Obj *)moby_class_resources[resident_moby_class_count])->extra = moby_class_data_table[i].b;
    }
}

LINKER_REMNANT("asm/remnants/text", func_00213C70);

extern void *build_resident_visibility_list(void);
extern void advance_moby_animation(void *);
extern void refresh_moby_spatial_bounds(void *);
extern void *visible_moby_list MACRO_ADDR;

/* Rebuild the visible list each call. Negative-state entries are skipped;
   flag 0x40 suppresses animation and flag 0x4 suppresses the bounds refresh.
   The optional per-object hook runs between those two operations. */
void update_visible_resident_objects(void) {
    char *m;

    visible_moby_list = build_resident_visibility_list();
    m = visible_moby_list;
    if (m != 0) {
        while (1) {
            if ((signed char)*(char *)&((Moby *)m)->state < 0) {
                m = *(char **)&((Moby *)m)->next;
            } else {
                if (!(((Moby *)m)->flags & 0x40)) {
                    advance_moby_animation(m);
                }
                /* inline asm: hook call (beq/move/jal with empty slots). The original used inline asm here too: GCC 2.95 reorg leaves both slots empty only next to asm (see reorg.c stop_search_p). */
                { int r; __asm__ volatile("beq %1,$0,1f\n\tmove $4,%2\n\tjal $31,%1\n1:" : "=r"(r) : "r"(*(void (**)(void *))(m + 0x74)), "r"(m) : "$4", "$31", "memory"); }
                if (((Moby *)m)->flags & 0x4) {
                    m = *(char **)&((Moby *)m)->next;
                } else {
                    refresh_moby_spatial_bounds(m);
                    m = *(char **)&((Moby *)m)->next;
                }
            }
            if (m == 0) break;
        }
    }
}

LINKER_REMNANT("asm/remnants/text", func_00213D10);

typedef struct {
    char _pad00[0x48];
    AnimSeq *seqs[1]; /* 0x48 */
} AnimClass;
typedef struct {
    char _pad00[0x24];
    AnimClass *pClass;       /* 0x24 */
    char _pad28[0x50 - 0x28];
    unsigned char frame;     /* 0x50 */
    unsigned char nextFrame; /* 0x51 */
    unsigned char seq;       /* 0x52 */
    unsigned char prevSeq;   /* 0x53 */
    char _pad54[0x5C - 0x54];
    float unk5C;             /* 0x5C */
    char _pad60[0x68 - 0x60];
    float *frameData;        /* 0x68 */
    char _pad6C[4];
    unsigned char unk70;     /* 0x70 */
} MobyAnim;
extern void update_moby_animation_state_a(void *) __asm__("func_0020D6D0");

/* Sets moby m's animation to sequence seq at frame (clamped to the
   sequence's last frame), the next frame to frame + 1 (clamped the same
   way, 0 if still out of range), refreshes the frame pointers
   (func_0020D6D0) and copies the first float of the new frame to +0x5C.
   The frame count is re-read through the class at each test, as retail
   reloads it after the byte stores. */
void MobySetAnimation(MobyAnim *m, int seq, int frame) {
    int frame_count = m->pClass->seqs[seq]->nframes;

    m->seq = seq;
    if (frame >= frame_count) {
        frame = frame_count - 1;
    }
    m->frame = frame;
    m->nextFrame = frame + 1;
    if (m->nextFrame > m->pClass->seqs[seq]->nframes - 1) {
        m->nextFrame = m->pClass->seqs[seq]->nframes - 1;
    }
    m->prevSeq = seq;
    if (m->nextFrame >= m->pClass->seqs[seq]->nframes) {
        m->nextFrame = 0;
    }
    update_moby_animation_state_a(m);
    m->unk5C = *m->frameData;
    m->unk70 &= ~2;
}

extern float IntToFloat(int arg0);
extern void capture_moby_blend_pose(void *, int);
extern char moby_blend_slot_poses[];

/* Blend to a sequence and frame, saving the current pose when needed. */
void MobyBlendAnimation(MobyAnim *moby, int sequence, int target_frame, int blend_duration) {
    int frame_count = moby->pClass->seqs[sequence]->nframes;
    int slot;
    unsigned char oldSeq;
    float scale;

    if (target_frame >= frame_count) {
        target_frame = frame_count - 1;
    }
    if (*(float *)((char *)moby + 0x54) > 0.025f ||
        *(int *)((char *)moby + 0x60) != 0 ||
        *(int *)((char *)moby + 0x64) != 0) {
        slot = find_or_allocate_id_slot((int)moby);
        if (slot >= 0) {
            capture_moby_blend_pose(moby, slot | 0x300);
            qcopy(moby_blend_slot_poses + slot * 0x10, (char *)moby + 0xF0);
            oldSeq = moby->seq;
            if (oldSeq != 0xFF) {
                *(unsigned char *)((char *)moby + 0xA5) = oldSeq;
            }
            moby->seq = 0xFF;
            moby->frame = slot;
        }
    }
    moby->nextFrame = target_frame;
    moby->prevSeq = sequence;
    update_moby_animation_state_a(moby);
    *(float *)((char *)moby + 0x58) = 1.0f;
    scale = 1.0f / IntToFloat(blend_duration);
    *(float *)((char *)moby + 0x54) = 0.0f;
    moby->unk70 = (unsigned char)(moby->unk70 & 0xFD);
    moby->unk5C = scale;
    *(unsigned char *)((char *)moby + 0x7C) =
        *((unsigned char *)moby->pClass->seqs[sequence] + 0x11);
}

/* Blend to a sequence and frame. blend_flags controls pose capture;
   bit 2 forces it. */
void blend_moby_animation_ex(MobyAnim *moby, int sequence, int target_frame, int blend_duration, int blend_flags) {
    int slot;
    int flags;
    unsigned char oldSeq;
    float scale;

    if (*(float *)((char *)moby + 0x54) > 0.025f ||
        *(int *)((char *)moby + 0x60) != 0 ||
        *(int *)((char *)moby + 0x64) != 0 || (blend_flags & 4)) {
        slot = find_or_allocate_id_slot((int)moby);
        if (slot >= 0) {
            flags = (blend_flags & 1) ? (slot | 0x100) : slot;
            capture_moby_blend_pose(moby, (blend_flags & 2) ? (flags | 0x200) : flags);
            qcopy(moby_blend_slot_poses + slot * 0x10, (char *)moby + 0xF0);
            oldSeq = moby->seq;
            if (oldSeq != 0xFF) {
                *(unsigned char *)((char *)moby + 0xA5) = oldSeq;
            }
            moby->seq = 0xFF;
            moby->frame = slot;
        }
    }
    moby->nextFrame = target_frame;
    moby->prevSeq = sequence;
    update_moby_animation_state_a(moby);
    *(float *)((char *)moby + 0x58) = 1.0f;
    scale = 1.0f / IntToFloat(blend_duration);
    *(float *)((char *)moby + 0x54) = 0.0f;
    moby->unk70 = (unsigned char)(moby->unk70 & 0xFD);
    moby->unk5C = scale;
    *(unsigned char *)((char *)moby + 0x7C) =
        *((unsigned char *)moby->pClass->seqs[sequence] + 0x11);
}

LINKER_REMNANT("asm/remnants/text", func_00214080);

extern int func_001160D8(void);

/* Returns a random integer from 0 to upper_bound - 1. */
int random_integer_below(int upper_bound) {
    return ((func_001160D8() >> 16) & 0x7FFF) % upper_bound;
}

LINKER_REMNANT("asm/remnants/text", func_002140F0);

/* As func_00214158: the old note's C, with the mtc1 nop added by the
   pipeline. */
float random_float_between(float minimum, float maximum) {
    int random_bits = func_001160D8();
    float delta = maximum - minimum;
    random_bits = (random_bits >> 16) & 0x7FFF;
    return minimum + (float)random_bits * delta * 3.0517578125e-05f;
}

/* The C of the old revert note: the nop it lacked is ps2eeas's (after
   an mtc1), which tools/ps2eeas_nops.py now adds. */
float random_angle_radians(void) {
    int random_steps = ((func_001160D8() >> 16) & 0xFFF) - 0x800;
    return (float)random_steps * 3.14159274f * 0.00048828125f;
}

extern float random_angle_radians(void);
extern float random_float_between(float, float);
extern void BuildSphericalOffset(void *, float, float, float);

/* Writes a random offset with length between minimum_radius and maximum_radius in a random direction. */
void random_spherical_offset(void *output_vector, float minimum_radius, float maximum_radius) {
    float azimuth = random_angle_radians();
    float elevation = random_angle_radians();

    BuildSphericalOffset(output_vector, random_float_between(minimum_radius, maximum_radius), azimuth, elevation);
}

/* Cosine interpolation: a + (b - a) * ((1 - cos(t * pi)) * 0.5). */
float CosineInterpolate(float a, float b, float t) {
    if (t == 0.0f) {
        return a;
    }
    if (t == 1.0f) {
        return b;
    }
    return a + (b - a) * ((1.0f - FastCos(t * 3.14159274f)) * 0.5f);
}

LINKER_REMNANT("asm/remnants/text", func_002142B8);

extern int coll_line_fix_a(void *, void *, int, int, int) __asm__("func_001EFE10");
extern char coll_hit_pos[];

/* Cast from position + probe_height down to z = 0.01.
   Return the hit height, or zero if no surface is found. */
f32 ProbeGroundHeight(void *position, s32 collision_flags, f32 probe_height) {
    char base_endpoint[16];
    char probe_endpoint[16];

    qcopy(base_endpoint, position);
    *(f32 *)(base_endpoint + 8) = 0.01f;
    qcopy(probe_endpoint, position);
    *(f32 *)(probe_endpoint + 8) = *(f32 *)(probe_endpoint + 8) + probe_height;
    if (coll_line_fix_a(probe_endpoint, base_endpoint, collision_flags | 2, 0, 0) != 0) {
        return *(f32 *)(coll_hit_pos + 8);
    }
    return 0.0f;
}

LINKER_REMNANT("asm/remnants/text", func_002143D0);

extern int occl_cell_count MACRO_ADDR;
extern int local_surface_region_enabled MACRO_ADDR;
extern float local_surface_region_center_x[4] MACRO_ADDR;
extern int sample_surface_height_map(float *, void *, float, float, float);
extern float vec_distance_xy(void *, void *);
extern void set_vector_unit_z(void *);

/* Ground height under pos: func_0023B210's answer when D_00161298 is on
   and it finds one (it writes the height through its first argument and
   gets `out` as well); else, when D_0016129C is on and pos lies within
   0.5 of the height of the disc D_001612A0 (x, y, height, radius) and
   inside its radius (func_001F9D48 is an XY distance), the disc's
   height; else pos's own z. Whenever the answer is not func_0023B210's,
   a non-null `out` is reset by func_001F9BC8. The disc is one MACRO_ADDR
   array: its fields are symbol+offset accesses, which the compiler
   counts as two instructions and so keeps out of delay slots, as retail
   has them. */
float resolve_camera_surface_height(float *pos, void *out) {
    float h;

    if (occl_cell_count != 0) {
        h = pos[2];
        if (sample_surface_height_map(&h, out, pos[0], pos[1], h) != 0) {
            return h;
        }
    }
    if (local_surface_region_enabled != 0 && FastAbsF(pos[2] - local_surface_region_center_x[2]) < 0.5f
        && vec_distance_xy(pos, local_surface_region_center_x) < local_surface_region_center_x[3]) {
        if (out != 0) {
            set_vector_unit_z(out);
        }
        return local_surface_region_center_x[2];
    }
    if (out != 0) {
        set_vector_unit_z(out);
    }
    return pos[2];
}

LINKER_REMNANT("asm/remnants/text", func_00214538);

extern char coll_output[];
extern void vec_scale_xy_to_length(float *, float *, float);
extern void fast_vec_normalize(void *, void *, float);
extern float min_float(float, float);
extern float max_float(float, float);

/* Shadow range probe: cast a ray down (8 units) from the moby position
   shifted against the light direction D_001CAE00 by its size, then a
   second one along the light from just above; +0x84/+0x88 get the lower
   and upper hit height (at most 4 apart), or 0 when nothing is below. */
void update_moby_shadow_range(char *m) {
    float dir[4];
    float p[4];
    float a[4];
    float b[4];
    float h2;
    float h1;
    float t;
    char *hit;

    qcopy(dir, shadow_light_dir);
    vec_scale_xy_to_length(dir, dir, 1.0f);
    FastVecScale(p, m, 0.0009765625f);
    qcopy(a, p);
    a[0] -= dir[0] * *(float *)(m + 0xC) * 0.000732421875f;
    a[1] -= dir[1] * *(float *)(m + 0xC) * 0.000732421875f;
    qcopy(b, a);
    b[2] -= 8.0f;
    if (coll_line_fix_a(a, b, 0x22, 0, 0) != 0) {
        qcopy(a, p);
        hit = coll_output;
        h1 = *(float *)(hit + 0x28);
        a[2] = a[2] + *(float *)(m + 0xC) * 0.00048828125f;
        a[0] = a[0] + dir[0] * *(float *)(m + 0xC) * 0.000732421875f;
        a[1] = a[1] + dir[1] * *(float *)(m + 0xC) * 0.000732421875f;
        fast_vec_normalize(dir, dir, (a[2] - h1) / -dir[2]);
        FastVecAdd(b, a, dir);
        h2 = h1;
        if (coll_line_fix_a(a, b, 0x22, 0, 0) != 0) {
            h2 = *(float *)(hit + 0x28);
        }
        *(float *)(m + 0x84) = min_float(h1, h2) - 0.25f;
        t = max_float(h1, h2) + 0.25f;
        *(float *)(m + 0x88) = t;
        if (*(float *)(m + 0x84) + 4.0f < t) {
            *(float *)(m + 0x88) = *(float *)(m + 0x84) + 4.0f;
        }
    } else {
        *(float *)(m + 0x84) = 0.0f;
        *(float *)(m + 0x88) = 0.0f;
    }
}

LINKER_REMNANT("asm/remnants/text", func_00214770);

extern short damage_class_131_a8_float_table;
extern unsigned char damage_reaction_code_table[];
extern char damage_reaction_scale_table[];
extern unsigned char hero_globals_base[];
extern char g_hero[];
extern int suck_get_aim_height(char *);
extern int read_state_field(char *);
extern int FastDecTimer(void *);
extern int scale_game_frame_count(int);
extern float FastVecLength(void *);

typedef struct { float v[4]; } __attribute__((aligned(16))) Q_214778;

/* Picks a moby's hit reaction from the damage record, scales the knockback; returns the reaction. */
int select_damage_reaction(char *a, char *B, char *an, unsigned int btn, int *outA, float *outF, int *outI, int k) {
    float v[4] __attribute__((aligned(16)));
    float w[4] __attribute__((aligned(16)));
    int s21;
    int a22;
    int u17;
    unsigned int c;

    *outA = 0;
    if (outI != 0)
        *outI = -1;

    if (B != 0 && *(char **)(B + 0x20) != 0) {
        int cls = *(short *)(*(char **)(B + 0x20) + 0xA6);
        if ((cls == 0x131 || cls == 0xA8) && an != 0)
            *(float *)(B + 0x2C) = ((float *)&damage_class_131_a8_float_table)[(unsigned char)an[8]];
    }

    if (a == 0) {
        if (an != 0) {
            *(short *)(an + 0x1C) = 0;
            *(short *)(an + 0x14) = -1;
        }
        *(short *)(an + 0x16) = -1;
        *outA = 0;
        return 0;
    }
    if (an == 0) {
        an = (char *)suck_get_aim_height(a);
        if (an == 0) {
            *outA = 0;
            return 0;
        }
    }
    if (k == 4)
        k = (unsigned char)an[8];

    if (B == 0) {
        if (an != 0) {
            FastDecTimer(an + 0x1C);
            *(short *)(an + 0x16) = -1;
        }
        *outA = 1;
        if (outF != 0)
            *outF = 0;
        return 0xB;
    }

    if (*(float *)(B + 0x1C) == 5627.9248f) {
        FastVecScale(B + 0x10, B + 0x10, *(float *)(damage_reaction_scale_table + (unsigned char)B[0x28] * 4 + k * 32));
        a22 = *(unsigned short *)(B + 0x2A);
        *(float *)(B + 0x1C) = 5627.9248f;
        if (a22 == 0x47) {
            char *h = g_hero;

            v[0] = FastCos(fast_arc_tan(*(float *)(a + 0x10) - *(float *)(h + 0x80),
                                               *(float *)(a + 0x14) - *(float *)(h + 0x84)));
            v[1] = FastSin(fast_arc_tan(*(float *)(a + 0x10) - *(float *)(h + 0x80),
                                               *(float *)(a + 0x14) - *(float *)(h + 0x84)));
            v[2] = 1.0f;
            fast_vec_normalize(v, v, FastVecLength(B + 0x10) * 0.7f);
            FastVecScale(B + 0x10, B + 0x10, 0.3f);
            FastVecAdd(w, B + 0x10, v);
            *(Q_214778 *)(B + 0x10) = *(Q_214778 *)w;
            vec_scale_xy_to_length((float *)(B + 0x10), (float *)(B + 0x10), 1.0f);
        }
    } else {
        if (*(char **)(B + 0x20) == 0) {
            a22 = 0x47;
            B[0x28] = 8;
        } else {
            a22 = *(short *)(*(char **)(B + 0x20) + 0xA6);
            B[0x28] = 8;
        }
    }

    switch ((unsigned char)B[0x28]) {
    case 0:
        if ((unsigned int)(*(unsigned short *)(B + 0x2A) - 1) < 2) {
            *outA = 2;
            s21 = 0;
        } else {
            *outA = 2;
            s21 = 1;
        }
        break;
    case 1:
        if ((unsigned char)B[0x29] < 2) {
            *outA = 2;
            s21 = 0xB;
        } else if ((unsigned char)B[0x29] == 2) {
            *outA = 2;
            s21 = 5;
        } else {
            *outA = 2;
            s21 = 9;
        }
        break;
    case 2:
        if ((unsigned char)B[0x29] < 2) {
            *outA = 2;
            s21 = 8;
        } else {
            *outA = 2;
            s21 = 0xD;
        }
        break;
    case 3:
        c = (unsigned char)B[0x29];
        if (c < 2) {
            *outA = 2;
            s21 = 0xA;
        } else if (c < 3) {
            *outA = 2;
            s21 = 0xF;
        } else {
            *outA = 2;
            s21 = 0x10;
            *(short *)(an + 0x14) = -1;
            *(short *)(an + 0x1C) = 0;
        }
        break;
    case 4:
        *outA = 2;
        s21 = 0xE;
        break;
    case 5:
        if ((unsigned char)B[0x29] < 2) {
            *outA = 3;
            s21 = 4;
        } else {
            *outA = 4;
            s21 = 7;
        }
        break;
    case 7:
        if ((unsigned char)B[0x29] < 2) {
            *outA = 2;
            s21 = 0xC;
        } else {
            *outA = 2;
            s21 = 0x11;
        }
        break;
    default:
        *outA = 2;
        s21 = 1;
        break;
    }

    if (outI != 0)
        *outI = a22;

    u17 = damage_reaction_code_table[(unsigned char)an[8] + s21 * 4];
    if (*(short *)(an + 0x14) != a22)
        *(short *)(an + 0x1C) = 0;

    if (FastDecTimer(an + 0x1C) != 0) {
        switch (s21) {
        case 0:
            *(short *)(an + 0x1C) = scale_game_frame_count(0x25);
            break;
        case 1:
            *(short *)(an + 0x1C) = scale_game_frame_count(0xF);
            break;
        case 4:
            *(short *)(an + 0x1C) = scale_game_frame_count(0x3C);
            break;
        case 7:
            if (hero_globals_base[0] != 0)
                *(short *)(an + 0x1C) = scale_game_frame_count(0x2D);
            else
                *(short *)(an + 0x1C) = scale_game_frame_count(0x3C);
            break;
        case 11:
            *(short *)(an + 0x1C) = scale_game_frame_count(0x3C);
            break;
        default:
            *(short *)(an + 0x1C) = scale_game_frame_count(0x1E);
            break;
        }
    } else {
        switch (s21) {
        case 0:
        case 1:
            if ((btn & 0x10) == 0)
                u17 = 0xB;
            if ((btn & 0x20) == 0)
                *outA = 1;
            *(float *)(B + 0x2C) = 0.0f;
            break;
        case 4:
            if ((btn & 1) == 0)
                u17 = 0xB;
            if ((btn & 2) == 0)
                *outA = 1;
            *(float *)(B + 0x2C) = 0.0f;
            break;
        case 7:
            if ((btn & 4) == 0)
                u17 = 0xB;
            if ((btn & 8) == 0)
                *outA = 1;
            *(float *)(B + 0x2C) = 0.0f;
            break;
        case 11:
            u17 = 0xC;
            break;
        default:
            *(float *)(B + 0x2C) = 0.0f;
            u17 = 0xD;
            break;
        }
    }

    *(short *)(an + 0x14) = a22;
    *(short *)(an + 0x16) = a22;
    if (outF != 0)
        *outF = *(float *)(B + 0x2C);

    if (s21 == 4) {
        char *p = (char *)read_state_field(a);
        if (p != 0)
            p[0x2E] = 1;
    } else {
        char *p = (char *)read_state_field(a);
        if (p != 0)
            p[0x2E] = 0;
    }
    return u17;
}

LINKER_REMNANT("asm/remnants/text", func_00214CF8);

/* Steps *p toward target by at most maxstep; returns the distance still left. */
float ApproachValue(float *value, float target, float maxstep) {
    float step = target - *value;
    if (maxstep < step) {
        step = maxstep;
    } else if (step < -maxstep) {
        step = -maxstep;
    }
    *value = *value + step;
    return FastAbsF(target - *value);
}

LINKER_REMNANT("asm/remnants/text", func_00214D80);


/* Move value toward target with acceleration and braking.
   Snap to target when the next step would reach or pass it. */
float ApproachWithVelocity(float *value, float *velocity, float target, float acceleration, float deceleration, float maximum_speed) {
    float diff = target - *value;

    if (*velocity * diff >= 0.0f && diff != 0.0f) {
        float braking_distance = *velocity * *velocity / deceleration * 0.5f;

        if (FastAbsF(diff) < braking_distance) {
            float distance_with_step = FastAbsF(diff);
            distance_with_step += FastAbsF(*velocity);
            if (braking_distance < distance_with_step) {
                ApproachValue(velocity, 0.0f, deceleration);
            } else {
                ApproachValue(velocity, 0.0f, deceleration * 1.1f);
            }
        } else {
            float speed = vec_length((deceleration + deceleration) * diff);

            if (maximum_speed < speed) {
                speed = maximum_speed;
            }
            if (diff < 0.0f) {
                ApproachValue(velocity, -speed, acceleration);
            } else {
                ApproachValue(velocity, speed, acceleration);
            }
        }
        {
            float remaining_distance = FastAbsF(diff);
            float current_speed = FastAbsF(*velocity);

            if (current_speed < remaining_distance) {
                *value = *value + *velocity;
                return *velocity;
            }
            *value = target;
            return diff;
        }
    }
    ApproachValue(velocity, 0.0f, deceleration);
    *value += *velocity;
    return *velocity;
}

LINKER_REMNANT("asm/remnants/text", func_00214F50);

extern void fast_vec_normalize(void *, void *, float);

struct M2c_temp3 {
    f32 values[3];
    s32 pad;
};
extern void fast_vec_normalize_r(f32 *, f32 *, f32) __asm__("func_001F9DC0");
void normalize_vector_triplet(f32 *matrix_data);

/* Adapted from Lombyte's project (GPL-3.0) for PAL by OpenRAC's tools/port.py: src/math/vectors/normalize_vector_triplet.c, normalize_vector_triplet. */
void normalize_vector_triplet(f32 *matrix_data) {
    struct M2c_temp3 scratch;
    f32 *base;
    f32 *src;
    f32 *dst;
    f32 value;
    s32 offset;
    s32 i;
    s32 next;
    s32 count;

    base = matrix_data;
    i = 0;
    do {
        next = i + 1;
        offset = i * 4;
        scratch.pad = 0;
        dst = scratch.values;
        src = (f32 *)((u8 *)base + offset);
        count = 2;
        do {
            value = *src;
            count--;
            src += 4;
            *dst = value;
            dst++;
        } while (count >= 0);
        fast_vec_normalize_r(scratch.values, scratch.values, 1.0f);
        dst = (f32 *)((u8 *)base + offset);
        src = scratch.values;
        count = 2;
        do {
            value = *src;
            count--;
            src++;
            *dst = value;
            dst += 4;
        } while (count >= 0);
        i = next;
    } while (i < 3);
}

LINKER_REMNANT("asm/remnants/text", func_00215038);

/* A goto into the first `return 0` gives retail's backward beqz; the two
   nops before it are short-loop padding (tools/ps2eeas_nops.py). */
int suck_get_aim_height(char *moby) {
    if (moby == 0) {
    ret0:
        return 0;
    }
    if ((((Moby *)moby)->flags & 0x20) == 0) {
        goto ret0;
    }
    return *((int *)((Moby *)moby)->pvars);
}

/* func_00215048 for the +0x10 field. */
int read_state_field(char *moby) {
    if (moby == 0) {
    ret0:
        return 0;
    }
    if ((((Moby *)moby)->flags & 0x20) == 0) {
        goto ret0;
    }
    return *(int *)(((char *)((Moby *)moby)->pvars) + 0x10);
}

LINKER_REMNANT("asm/remnants/text", func_002150A8);

/* The {1, 2, 0} successor table of the quaternion extraction. */
typedef struct {
    int next[3];
} QuatNext;

extern QuatNext quat_next_axis_table;

/* Rotation matrix (rows of four floats) to quaternion (x, y, z, w), by
   Shoemake's method: from the trace when it is positive, else from the
   largest diagonal element, working on a packed 3x3 copy. */
void MatrixToQuaternion(void *output_quaternion, void *matrix_data) {
    float *q = output_quaternion;
    float (*m)[4] = matrix_data;
    QuatNext n = quat_next_axis_table;
    float mat[3][3];
    float trace;
    float s;
    int i, j, k;

    trace = m[0][0] + m[1][1] + m[2][2];
    if (trace > 0.0f) {
        s = vec_length(trace + 1.0f);
        q[3] = s * 0.5f;
        s = 0.5f / s;
        q[0] = (m[2][1] - m[1][2]) * s;
        q[1] = (m[0][2] - m[2][0]) * s;
        q[2] = (m[1][0] - m[0][1]) * s;
    } else {
        mat[0][0] = m[0][0];
        mat[0][1] = m[0][1];
        mat[0][2] = m[0][2];
        mat[1][0] = m[1][0];
        mat[1][1] = m[1][1];
        mat[1][2] = m[1][2];
        mat[2][0] = m[2][0];
        mat[2][1] = m[2][1];
        mat[2][2] = m[2][2];
        i = 0;
        if (mat[1][1] > mat[0][0]) {
            i = 1;
        }
        if (mat[2][2] > mat[i][i]) {
            i = 2;
        }
        j = n.next[i];
        k = n.next[j];
        s = vec_length(mat[i][i] - (mat[j][j] + mat[k][k]) + 1.0f);
        q[i] = s * 0.5f;
        if (s != 0.0f) {
            s = 0.5f / s;
        }
        q[3] = (mat[k][j] - mat[j][k]) * s;
        q[j] = (mat[j][i] + mat[i][j]) * s;
        q[k] = (mat[k][i] + mat[i][k]) * s;
    }
}

extern void copy_matrix_rotation(void *);
extern void MatrixToQuaternion(void *, void *);
extern void matrix_copy_rows(void *, void *);

/* func_001FA460 takes two arguments: matrix_data is passed on to it untouched,
   which gives matrix_data three references and retail's $s0. */
void extract_matrix_rotation_quaternion(void *output_quaternion, void *matrix_data) {
    char rotation_matrix[0x40];
    copy_matrix_rotation_2(rotation_matrix, matrix_data);
    MatrixToQuaternion(output_quaternion, rotation_matrix);
    matrix_copy_rows(matrix_data, rotation_matrix);
}

LINKER_REMNANT("asm/remnants/text", func_00215378);

extern float FastSin(float);  /* sin of a half-angle */
extern float FastCos(float);  /* cos of a half-angle */

/* Axis-angle -> quaternion: the xyz part is axis scaled by sin(angle/2)
   (done by func_001F9C30, which writes through output_quaternion), and w at +0xC is
   cos(angle/2). Both trig calls take the same half-angle, which is why
   it lives in $f20 across all three calls. */
void build_quaternion_from_axis_angle(void *output_quaternion, void *axis, float angle) {
    float half = angle * 0.5f;

    FastVecScale(output_quaternion, axis, FastSin(half));
    *(float *)((char *)output_quaternion + 0xC) = FastCos(half);
}

typedef struct {
    float m[4][4];
} __attribute__((aligned(16))) Mtx44;
extern void clear_u64_value(float *);
extern void euler_to_matrix(float *, float *);
extern void euler_to_matrix_ee(float *, float *);

/* Matrix to Euler angles: on a copy of src with the translation cleared,
   read the Z angle from row 0, undo it (func_001FA218 builds the Z
   rotation, func_001FA540 multiplies), read and undo Y the same way,
   then read X from row 1; out = (x, y, z). The last undo vector is
   filled but never used. The 16-byte aligned struct copy is retail's
   four interleaved lq/sq. */
void matrix_to_euler(Mtx44 *src, float *out) {
    float rot[16];
    Mtx44 m;
    float v[4];
    float x;
    float y;
    float z;

    m = *src;
    clear_u64_value(m.m[3]);
    m.m[3][3] = 1.0f;
    z = fast_arc_tan(m.m[0][0], m.m[0][1]);
    v[0] = 0.0f;
    v[1] = 0.0f;
    v[2] = -z;
    euler_to_matrix(rot, v);
    sce_vu0_mul_matrix(&m, rot, &m);
    y = fast_arc_tan(m.m[0][0], -m.m[0][2]);
    v[0] = 0.0f;
    v[2] = 0.0f;
    v[1] = -y;
    euler_to_matrix_ee(rot, v);
    sce_vu0_mul_matrix(&m, rot, &m);
    x = fast_arc_tan(m.m[1][1], m.m[1][2]);
    v[1] = 0.0f;
    v[0] = -x;
    v[2] = 0.0f;
    out[2] = z;
    out[1] = y;
    out[0] = x;
}

/* 12 bytes of post-endlabel nop padding in retail -- see func_001F6668. */
__asm__(".section .text\n\tnop\n\tnop\n\tnop\n");

LINKER_REMNANT("asm/remnants/text", func_00215518);

typedef struct {
    char pad[0x30];
    float pos[4];     /* 0x30 */
    float mtx[4][4];  /* 0x40 */
} ViewBox;
extern ViewBox *clip_volume_table MACRO_ADDR;
extern void FastVecSub(void *, void *, void *);

/* Is point point inside box volume_index of the table at D_00160134? The offset
   from the box's position, taken through its matrix, must lie in
   [-1, 1] on every axis. 0 for volume_index == -1. */
int is_point_inside_clip_volume(void *point, int volume_index) {
    float offset[4];
    float clip_point[4];
    ViewBox *volume;

    if (volume_index == -1) {
        return 0;
    }
    volume = &clip_volume_table[volume_index];
    FastVecSub(offset, point, volume->pos);
    offset[3] = 0.0f;
    matrix_mul_vec3(clip_point, offset, volume->mtx);
    if (clip_point[0] >= -1.0f && clip_point[0] <= 1.0f && clip_point[1] >= -1.0f && clip_point[1] <= 1.0f
        && clip_point[2] >= -1.0f && clip_point[2] <= 1.0f) {
        return 1;
    }
    return 0;
}

LINKER_REMNANT("asm/remnants/text", func_00215648);


/* Conjugate-style sandwich: output_vector = quaternion * (vector with w = 0) * conjugate, where
   conjugate is quaternion negated with its w kept (func_001FA588 is the quaternion
   multiply). The 16-byte copy of vector is qcopy's lq/sq. */
void rotate_vector_by_quaternion(void *output_vector, void *vector, void *quaternion) {
    float conjugate[4];
    float vector_quaternion[4];
    float product[4];

    FastVecScale(conjugate, quaternion, -1.0f);
    conjugate[3] = ((float *)quaternion)[3];
    qcopy(vector_quaternion, vector);
    vector_quaternion[3] = 0.0f;
    multiply_quaternions(product, quaternion, vector_quaternion);
    multiply_quaternions(output_vector, product, conjugate);
}

extern void build_quaternion_from_axis_angle(void *output_quaternion, void *axis, float angle);
extern void rotate_vector_by_quaternion(void *output_vector, void *vector, void *quaternion);

/* dst = vec rotated `angle` around axis. A tiny angle skips the rotation
   (dst = vec); otherwise the axis is normalised to unit length and turned
   into an axis-angle quaternion in a scratch buffer, which then rotates
   vec into dst. */
void build_look_at_matrix(void *dst, void *vec, void *axis, float angle) {
    float q[4];

    if (FastAbsF(angle) < 0.00001f) {
        qcopy(dst, vec);
        return;
    }
    fast_vec_normalize(q, axis, 1.0f);
    build_quaternion_from_axis_angle(q, q, angle);
    rotate_vector_by_quaternion(dst, vec, q);
}

LINKER_REMNANT("asm/remnants/text", func_00215788);

extern float frame_scale MACRO_ADDR;
extern float g_frame_scale_sq MACRO_ADDR;
extern float inv_frame_scale MACRO_ADDR;
extern float g_frame_time MACRO_ADDR;
extern float g_frame_time_sq MACRO_ADDR;
extern float g_frame_time_cube MACRO_ADDR;
extern int frame_scale_fifths MACRO_ADDR;
extern float frame_delta_time MACRO_ADDR;
extern int pal_mode MACRO_ADDR;

/* The EE80 flag is written first in each arm. Its float store lands in
   a delay slot, where check_macro_slots.py makes it $gp-relative. */
void set_video_timing(int pal) {
    if (pal == 0) {
        pal_mode = 0;
        frame_scale = 1.0f;
        g_frame_scale_sq = 1.0f;
        inv_frame_scale = 1.0f;
        g_frame_time = 0.01666666753590106964111328125f;
        g_frame_time_sq = 0.000277777784503996372222900390625f;
        g_frame_time_cube = 0.00000462962952951784245669841766357421875f;
        frame_scale_fifths = 5;
        frame_delta_time = 0.01666666753590106964111328125f;
    } else {
        pal_mode = 1;
        frame_scale = 1.2000000476837158203125f;
        g_frame_scale_sq = 1.440000057220458984375f;
        inv_frame_scale = 0.833333313465118408203125f;
        g_frame_time = 0.02000000141561031341552734375f;
        g_frame_time_sq = 0.00040000001899898052215576171875f;
        g_frame_time_cube = 0.0000079999999798019416630268096923828125f;
        frame_scale_fifths = 6;
        frame_delta_time = 0.0199999995529651641845703125f;
    }
}

LINKER_REMNANT("asm/remnants/text", func_002158E0);

extern int FastVectorToPackedChars(float *);
extern int truncate_float_to_s32_r(float) __asm__("func_001FA898");

/* Pack xyz into bytes around 127; w holds their shared scale. */
void pack_vector_xyz_with_shared_scale(float *vector, int *packed_value) {
    float components[4];
    float abs_x = FastAbsF(vector[0]);
    float max_xy = FastAbsF(vector[1]);
    float abs_z = FastAbsF(vector[2]);
    float max_component;
    int packed_scale;
    float inverse_scale;

    if (max_xy < abs_x) {
        max_xy = abs_x;
    }
    max_component = (abs_z < max_xy) ? max_xy : abs_z;
    packed_scale = truncate_float_to_s32_r(max_component * 10000.0f / 63.0f);
    packed_scale = (packed_scale < 0x100) ? packed_scale : 0xFF;
    if (packed_scale <= 0) {
        packed_scale = 1;
    }
    components[3] = (float)packed_scale;
    inverse_scale = 1.0f / (components[3] * 0.0001f);
    components[0] = vector[0] * inverse_scale + 127.0f;
    components[1] = vector[1] * inverse_scale + 127.0f;
    components[2] = vector[2] * inverse_scale + 127.0f;
    *packed_value = FastVectorToPackedChars(components);
}

typedef float FVec4[4] __attribute__((aligned(16)));
extern void FastVectorFromPackedChars(float *, int);

/* Unpack the packed colour *packed_value into a float vector, centre its
   channels on 127 and scale by alpha/10000 into output_vector. The 127 vector is
   a 16-byte aligned (sceVu0FVECTOR-style) local cleared by its
   initializer (one por/sq), then filled. */
void load_display_text_resource_entry(float *output_vector, int *packed_value) {
    float v[4];
    FVec4 mid = { 0 };
    float scale;

    mid[0] = 127.0f;
    mid[1] = 127.0f;
    mid[2] = 127.0f;
    FastVectorFromPackedChars(v, *packed_value);
    scale = v[3] * 0.0001f;
    FastVecSub(v, v, mid);
    FastVecScale(output_vector, v, scale);
}


/* Rounds value to decimal_places decimal places: round(value * 10^decimal_places) / 10^decimal_places.
   value is updated in place throughout, so it stays in $f12 as retail
   has it. The nops after the two mtc1s are ps2eeas's
   (tools/ps2eeas_nops.py). */
float round_float_to_decimal_places(int decimal_places, float value) {
    int p = 1;
    float scale;

    if (decimal_places > 0) {
        do {
            decimal_places--;
            p *= 10;
        } while (decimal_places != 0);
    }
    scale = (float)p;
    value += 1.0f / (scale + scale);
    value *= scale;
    value = (float)truncate_float_to_s32_r(value);
    return value / scale;
}

extern float MobyGetFrameValue(char *);
extern float round_float_to_decimal_places(int, float);

/* Returns 1 if the moby's current anim frame lies inside the one-frame window starting at window_start. */
int IsFrameWithinWindow(char *moby, float window_start) {
    float now = MobyGetFrameValue(moby);
    float frame_offset = round_float_to_decimal_places(4, now - window_start);
    float window_size = round_float_to_decimal_places(4, *(float *)(moby + 0x58) * *(float *)(moby + 0x5C));

    if (window_start <= now && frame_offset < window_size) {
        return 1;
    }
    return 0;
}

LINKER_REMNANT("asm/remnants/text", func_00215BA8);

/* Spherical-to-cartesian: r is the radius; azimuth and elevation are angles.
   func_001F9F90 is cos, func_001F9FA8 sin (named in the comments at
   func_00212xxx). Each product is spelled trig * r * trig so the two
   calls are issued before the multiplies, the way retail does. */
void BuildSphericalOffset(void *output_vector, float r, float azimuth, float elevation) {
    float *out = (float *)output_vector;

    out[0] = FastCos(azimuth) * r * FastCos(elevation);
    out[1] = FastSin(azimuth) * r * FastCos(elevation);
    out[2] = FastSin(elevation) * r;
}

LINKER_REMNANT("asm/remnants/text", func_00215CA0);

typedef struct {
    float v[4];
} __attribute__((aligned(16))) PathPt;
typedef struct {
    int count;
    char pad[0xC];
    PathPt pts[1];        /* 0x10 */
} Path;
extern void lerp_vector(void *, void *, void *, float);
extern float vec_length_xy(void *);
extern float FastSubRots(float, float);
extern float FastAddRots(float, float);

/* Samples a path of points at arg t: lerps the position between point
   floor(t) and the next into pos and, unless flags bit 0 is set, writes
   the rotation interpolated between the two segments' directions (and
   the points' w as roll) into rot. Without wrap the last segment clamps. */
void SamplePathAt(Path *path, int wrap, void *pos, float *rot, int flags, float t) {
    PathPt a;
    PathPt b;
    PathPt c;
    PathPt d;
    int i;
    int j;
    int k;
    int clamp = 0;
    float f;
    float yaw;
    float pitch;
    float yaw2;
    float pitch2;
    float roll;
    float roll2;

    /* The whole part selects a path segment; the fraction blends its ends. */
    i = truncate_float_to_s32_r(t);
    if (!wrap && i >= path->count - 2) {
        i = path->count - 2;
        clamp = 1;
    }
    f = t - (float)i;
    if (clamp && f > 1.0f) {
        f = 1.0f;
    }
    j = i + 1;
    k = i + 2;
    if (k >= path->count) {
        j = j % path->count;
        k = k % path->count;
    }
    roll2 = 0.0f;
    qcopy(&a, &path->pts[i]);
    qcopy(&b, &path->pts[j]);
    lerp_vector(pos, &a, &b, f);
    /* Position-only requests leave the rotation output untouched. */
    if (flags & 1) {
        return;
    }
    FastVecSub(&d, &b, &a);
    yaw = fast_arc_tan(d.v[0], d.v[1]);
    pitch = fast_arc_tan(vec_length_xy(&d), d.v[2]);
    roll = a.v[3];
    if (clamp) {
        yaw2 = yaw;
        pitch2 = pitch;
        roll = 0.0f;
    } else {
        qcopy(&c, &path->pts[k]);
        FastVecSub(&d, &c, &b);
        yaw2 = fast_arc_tan(d.v[0], d.v[1]);
        pitch2 = fast_arc_tan(vec_length_xy(&d), d.v[2]);
        roll2 = b.v[3];
    }
    rot[0] = 0.0f;
    rot[1] = -FastAddRots(FastSubRots(pitch2, pitch) * f, pitch);
    rot[2] = FastAddRots(FastSubRots(yaw2, yaw) * f, yaw);
    rot[3] = -FastAddRots(FastSubRots(roll2, roll) * f, roll);
}

LINKER_REMNANT("asm/remnants/text", func_00215F20);

extern int msg_string(int);
extern void copy_text_to_shared_buffer(int);
extern int help_message_keepalive MACRO_ADDR;
extern int help_message_owner MACRO_ADDR;
extern int help_message_id MACRO_ADDR;

/* Shows help message message_id (func_001FFE88 of its string) for requester
   requester: 2 if requester already holds the slot, 1 if the slot was free and
   requester takes it, 0 if someone else holds it. The failure return goes
   last, which lets the scheduler put `li $2,1` before the last store. */
int try_set_help_message(int requester, int message_id) {
    int current_owner = help_message_owner;

    if (current_owner == requester) {
        if (message_id != 0) {
            copy_text_to_shared_buffer(msg_string(message_id));
        }
        help_message_id = message_id;
        help_message_keepalive = 2;
        return 2;
    }
    if (current_owner == 0) {
        if (message_id != 0) {
            copy_text_to_shared_buffer(msg_string(message_id));
        }
        help_message_owner = requester;
        help_message_keepalive = 2;
        help_message_id = message_id;
        return 1;
    }
    return 0;
}

/* Return 1 or 2 for a normal request, or 3 when replacing another owner. */
int force_help_message(int requester, int message_id) {
    int busy = try_set_help_message(requester, message_id);
    if (busy != 0) {
        return busy;
    }
    if (message_id != 0) {
        copy_text_to_shared_buffer(msg_string(message_id));
    }
    help_message_owner = requester;
    help_message_keepalive = 2;
    help_message_id = message_id;
    return 3;
}

/* Returns gold bolts collected minus four per gold weapon bought, clamped to 0..40. */
int compute_clamped_count_difference(void) {
    int a = count_nonzero_entries_up_to_40();
    int b = count_nonzero_entries_up_to_10();
    int v = a - b * 4;
    if (v < 0) v = 0;
    return (v < 0x29) ? v : 0x28;
}

extern unsigned char gold_bolts_collected[];

/* Counts the gold bolts collected, capped at 40. */
int count_nonzero_entries_up_to_40(void) {
    int count = 0;
    int row;
    for (row = 0; row < 0x14; row++) {
        unsigned char *p = &gold_bolts_collected[row * 4];
        int k;
        for (k = 3; k >= 0; k--) {
            if (*p != 0) count = count + 1;
            p++;
        }
    }
    if (count < 0) count = 0;
    return (count < 0x29) ? count : 0x28;
}

extern unsigned char gold_weapon_purchased[];

/* Counts the gold weapons bought, capped at 10. */
int count_nonzero_entries_up_to_10(void) {
    int count = 0;
    int i;
    for (i = 0; i < 0x25; i++) {
        if (gold_weapon_purchased[i] != 0) count = count + 1;
    }
    if (count < 0) count = 0;
    return (count < 0xB) ? count : 0xA;
}

extern unsigned char gSkillPoints[];

/* Counts the skill points earned, capped at 30. */
int count_nonzero_entries_up_to_30(void) {
    int count = 0;
    int i;
    for (i = 0; i < 0x20; i++) {
        if (gSkillPoints[i] != 0) count = count + 1;
    }
    if (count < 0) count = 0;
    return (count < 0x1F) ? count : 0x1E;
}
