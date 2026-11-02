/* Data owned by src/game/ui/pause.c. Its values come from your own baserom (tools/data_in_c.py). */
#include "common.h"

#include "structs/data/game_ui_pause.h"

extern u16 pause_weapon_menu_items[];
extern void update_menu_icon_list();
extern void draw_menu_icon_list();
extern u16 gadget_menu_items[];

u32 item_info_table_slot[2] DATA_SECTION(D_001864D8) = {0};

u32 D_001864E0[] DATA_SECTION(D_001864E0) = {
#include "data_inc/D_001864E0.inc"
};

s32 active_camera_basis_column1_x[4] DATA_SECTION(D_001873A0) = {0};

s32 active_camera_basis_column2_x[20] DATA_SECTION(D_001873B0) = {0};

int selected_level_index DATA_SECTION(D_001A0414) = {0};

int pause_memory_card_state[12] DATA_SECTION(D_001A0418) = {0};

u32 transition_overlay_tex0[8] DATA_SECTION(D_001A0448) = {0};

s32 panel_slot_enabled[] DATA_SECTION(D_001CE640) = {
#include "data_inc/D_001CE640.inc"
};

#include "data_inc/D_001CE938.refs"
u32 pause_menu_screen_a[] DATA_SECTION(D_001CE938) = {
#include "data_inc/D_001CE938.inc"
};

#include "data_inc/D_001CEAC8.refs"
u32 pause_menu_screen_b[] DATA_SECTION(D_001CEAC8) = {
#include "data_inc/D_001CEAC8.inc"
};

#include "data_inc/D_001CEB18.refs"
u32 pause_menu_screen_optional[] DATA_SECTION(D_001CEB18) = {
#include "data_inc/D_001CEB18.inc"
};

#include "data_inc/D_001CEFA0.refs"
u32 gadget_menu_slots_row0[] DATA_SECTION(D_001CEFA0) = {
#include "data_inc/D_001CEFA0.inc"
};

Item0A gadget_menu_slots_row1[] DATA_SECTION(D_001CEFE0) = {
#include "data_inc/D_001CEFE0.inc"
};

Item0A gadget_menu_slots_row2[] DATA_SECTION(D_001CF000) = {
#include "data_inc/D_001CF000.inc"
};

#include "data_inc/D_001CF020.refs"
u32 gadget_menu_slots_row3[] DATA_SECTION(D_001CF020) = {
#include "data_inc/D_001CF020.inc"
};

#include "data_inc/D_001CF4A0.refs"
u32 pause_weapon_menu_slots[] DATA_SECTION(D_001CF4A0) = {
#include "data_inc/D_001CF4A0.inc"
};

int selected_mission_index[4] DATA_SECTION(D_001CFAD8) = {0};

u16 active_message_menu_items[] DATA_SECTION(D_001CFFC0) = {
#include "data_inc/D_001CFFC0.inc"
};

int pause_entry_cleared_word[4] DATA_SECTION(D_001D0718) = {0};

void *pause_weapon_menu_grid[] DATA_SECTION(D_001D1080) = {
    update_menu_icon_list,
    draw_menu_icon_list,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    pause_weapon_menu_items,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
};

void *gadget_menu_grid[] DATA_SECTION(D_001D1408) = {
    update_menu_icon_list,
    draw_menu_icon_list,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    gadget_menu_items,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
};

#include "data_inc/D_001D28F8.refs"
u32 save_overwrite_confirm_page[] DATA_SECTION(D_001D28F8) = {
#include "data_inc/D_001D28F8.inc"
};

int save_confirm_slot[4] DATA_SECTION(D_001D29C0) = {0};

u16 reward_menu_items[] DATA_SECTION(D_001D2B80) = {
#include "data_inc/D_001D2B80.inc"
};

u32 reward_menu_page[] DATA_SECTION(D_001D2BF8) = {
#include "data_inc/D_001D2BF8.inc"
};

Entry14 cheat_toggle_menu_items[13] DATA_SECTION(D_001D3E90) = {0};

#include "data_inc/D_001D48A8.refs"
int pause_level_sprite_lists[] DATA_SECTION(D_001D48A8) = {
#include "data_inc/D_001D48A8.inc"
};

#include "data_inc/D_001D4B90.refs"
u32 pause_action_list_pal[] DATA_SECTION(D_001D4B90) = {
#include "data_inc/D_001D4B90.inc"
};

#include "data_inc/D_001D4BC0.refs"
u32 pause_action_list_short[] DATA_SECTION(D_001D4BC0) = {
#include "data_inc/D_001D4BC0.inc"
};

#include "data_inc/D_001D51B8.refs"
u32 save_menu_overwrite_confirm_page[] DATA_SECTION(D_001D51B8) = {
#include "data_inc/D_001D51B8.inc"
};

#include "data_inc/D_001D5240.refs"
u32 restart_confirm_page[] DATA_SECTION(D_001D5240) = {
#include "data_inc/D_001D5240.inc"
};

#include "data_inc/D_001D5318.refs"
u32 save_menu_load_confirm_page[] DATA_SECTION(D_001D5318) = {
#include "data_inc/D_001D5318.inc"
};

int menu_preview_slot_enabled[] DATA_SECTION(D_001D53A0) = {
#include "data_inc/D_001D53A0.inc"
};

u32 timed_sequence_page1[] DATA_SECTION(D_001D5418) = {
#include "data_inc/D_001D5418.inc"
};

u32 timed_sequence_page2[] DATA_SECTION(D_001D54C8) = {
#include "data_inc/D_001D54C8.inc"
};

HandGadgetAnimation gadget_animations[] DATA_SECTION(D_001D5668) = {
#include "data_inc/D_001D5668.inc"
};

u32 menu_system DATA_SECTION(D_001D5F70) = 0;

u32 current_menu_page DATA_SECTION(D_001D5F74) = 0;

int menu_system_help_text_buffer[18] DATA_SECTION(D_001D6078) = {0};

int panel_slots[16] DATA_SECTION(D_001D6120) = {0};

u8 class_pose_manipulator[64] DATA_SECTION(D_001D6160) = {0};

u8 first_attachment_manipulator[32] DATA_SECTION(D_001D61A0) = {0};

u8 D_001D61C0[8] DATA_SECTION(D_001D61C0) = {0};

u8 D_001D61C8[24] DATA_SECTION(D_001D61C8) = {0};

u8 second_attachment_manipulator[32] DATA_SECTION(D_001D61E0) = {0};

u8 D_001D6200[8] DATA_SECTION(D_001D6200) = {0};

u8 D_001D6208[16] DATA_SECTION(D_001D6208) = {0};

float ammo_preview_offsets[6] DATA_SECTION(D_001D6220) = {0};

f32 ammo_preview_velocities[6] DATA_SECTION(D_001D6238) = {0};

Rec38 preview_animation_requests[8] DATA_SECTION(D_001D6250) = {0};

int menu_stream_buffers[10] DATA_SECTION(D_001D6448) = {0};

u16 pause_weapon_menu_items[76] DATA_SECTION(D_001D6470) = {0};

int pause_weapon_menu_item_field40[16] DATA_SECTION(D_001D6508) = {0};

u16 gadget_menu_items[72] DATA_SECTION(D_001D6548) = {0};

int gadget_menu_item_field40[14] DATA_SECTION(D_001D65D8) = {0};

int gadget_menu_item_field44[14] DATA_SECTION(D_001D6610) = {0};

Out0C galaxy_menu_items[23] DATA_SECTION(D_001D6648) = {0};

int scene_state_buffer_2[64] DATA_SECTION(D_001D6760) = {0};

int scene_state_buffer_0[792] DATA_SECTION(D_001D6860) = {0};

int scene_state_buffer_1[792] DATA_SECTION(D_001D74C0) = {0};

u32 graphics_setup_dma_packets[] DATA_SECTION(D_001D8120) = {
#include "data_inc/D_001D8120.inc"
};

#include "data_inc/D_001D81E0.refs"
u32 ntsc_graphics_setup_packet[] DATA_SECTION(D_001D81E0) = {
#include "data_inc/D_001D81E0.inc"
};

#include "data_inc/D_001D8250.refs"
u32 pal_graphics_setup_packet[] DATA_SECTION(D_001D8250) = {
#include "data_inc/D_001D8250.inc"
};

u32 planet_icon_rows[] DATA_SECTION(D_001DE0C0) = {
#include "data_inc/D_001DE0C0.inc"
};

int map_screen_layer_insets[] DATA_SECTION(D_001DE2E8) = {
#include "data_inc/D_001DE2E8.inc"
};

float preview_placements[] DATA_SECTION(D_001E0708) = {
#include "data_inc/D_001E0708.inc"
};

int map_gold_bolt_totals[] DATA_SECTION(D_001E0B88) = {
#include "data_inc/D_001E0B88.inc"
};

Blk32 cheat_menu_ids_init DATA_SECTION(D_001E8A58) = {
#include "data_inc/D_001E8A58.inc"
};
