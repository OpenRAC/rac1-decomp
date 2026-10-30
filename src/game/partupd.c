#include "common.h"
#include "callees.h"
#include "records.h"
#include "structs.h"

/*
 * partupd.cpp in the original source; text 0x219780-0x219C08.
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
extern int measure_text_width(unsigned char *str, int count, void *table);
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
extern int func_001160D8(void);
extern float random_angle_radians(void);
extern float random_float_between(float, float);
extern void BuildSphericalOffset(void *, float, float, float);
extern void fast_vec_normalize(void *, void *, float);
extern void copy_matrix_rotation(void *);
extern void MatrixToQuaternion(void *, void *);
extern void matrix_copy_rows(void *, void *);
extern float MobyGetFrameValue(void);
extern float round_float_to_decimal_places(int, float);
extern unsigned char gold_bolts_collected[];
extern unsigned char gold_weapon_purchased[];
extern unsigned char gSkillPoints[];
extern void snd_StreamSafeCdCallback(void *);
extern void finish_audio_stream_read(int);
extern short cd_read_state[];
extern void snd_ContinueVAGStream(void *);
extern void snd_StreamSafeCdBreak(void);
extern char load_file_start_failed_string[];
extern int snd_StreamSafeCdRead(int, int, int, void *);
extern int start_audio_stream_read_v(void) __asm__("func_00217628");
extern void sce_gs_sync_v(int);
extern void music_Update(void);
extern void snd_reset_state_and_flush_commands(void);
extern void snd_FlushSoundCommands(void);
extern void snd_reenable_command_flush(void);
extern int snd_StreamSafeCdGetError(void);
extern void music_start_track_by_id(short, short, short);
extern void music_PreseekTrack(short, short, short);
extern short music_flagged_track_started NOT_SDA;
extern char g_controller_state[];
extern int pad_socket_param NOT_SDA;
extern void sce_dbc_init(void);
extern void sce_pad2_init(int);
extern int sce_pad2_create_socket(void *, void *);
extern void poll_pad_device_state(void *);

typedef u32 u128 __attribute__((mode(TI), aligned(16)));
struct Sub {
    s32 a;
    s32 b;
    s32 c;
    s32 d;
    s16 h10;
    s16 h12;
    s16 h14;
    s16 h16;
    s16 h18;
};
struct Obj {
    u8 pad_0;
    u8 b1;
    u8 b2;
    u8 b3;
    s32 w4;
    u8 b8;
    u8 b9;
    s16 hA;
    f32 fC;
    u128 q10;
    struct Sub sub;
};
extern u8 * particle_texture_ptrs[];
extern u8 * particle_texture_ptrs_23[];
extern struct Obj *create_part(s32);
extern s32 truncate_float_to_s32(f32);
extern f32 random_float_between(f32, f32);
extern void pack_vector_xyz_with_shared_scale(void *, void *);
extern void load_display_text_resource_entry(void *, void *);

/* Adapted from Lombyte's project (GPL-3.0) for PAL by OpenRAC's tools/port.py: src/rendering/fun_00218888.c, FUN_00218888. */
struct Obj *PartType02Spawn(u128 *source_quadword, f32 *first_vector, f32 *second_vector, s32 initial_spark_word, s32 second_spark_word, s32 frame_count, s32 second_frame_count, s32 third_frame_count, s32 lookup_index_and_flags) {
    struct Obj *spark_part;
    struct Sub *spark_substructure;
    f32 first_vector_scratch[4];
    f32 second_vector_scratch[4];

    spark_part = create_part(2);
    if (spark_part != 0) {
        qcopy(&spark_part->q10, source_quadword);
        spark_part->w4 = initial_spark_word;
        spark_part->b9 = truncate_float_to_s32(4.0f) + 0x40;
        spark_part->fC = 0.0f;
        spark_part->b1 = 0;
        spark_part->b3 = 0x44;
        spark_part->b8 = truncate_float_to_s32(random_float_between(spark_part->fC, 255.0f));
        if (lookup_index_and_flags == -1) {
            spark_part->b2 = *particle_texture_ptrs_23[0];
        } else {
            spark_part->b2 = *particle_texture_ptrs[(u16)lookup_index_and_flags];
            if (lookup_index_and_flags & 0x10000) {
                spark_part->b3 = 0x48;
            }
        }
        spark_part->hA = frame_count;
        spark_substructure = &spark_part->sub;
        spark_substructure->h16 = truncate_float_to_s32(first_vector[3] * 210000.0f / 1000.0f);
        spark_substructure->h18 = truncate_float_to_s32(second_vector[3] * 210000.0f / 1000.0f);
        pack_vector_xyz_with_shared_scale(first_vector, &spark_substructure->a);
        pack_vector_xyz_with_shared_scale(second_vector, &spark_substructure->b);
        load_display_text_resource_entry(first_vector_scratch, &spark_substructure->a);
        load_display_text_resource_entry(second_vector_scratch, &spark_substructure->b);
        spark_substructure->c = initial_spark_word;
        spark_substructure->d = second_spark_word;
        spark_substructure->h10 = frame_count;
        spark_substructure->h12 = second_frame_count;
        spark_substructure->h14 = third_frame_count;
    }
    return spark_part;
}

LINKER_REMNANT("asm/remnants/text", func_00219958);
