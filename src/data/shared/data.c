/* Data with no one owner: several files use it, or no C file does yet. Its values come from your own baserom (tools/data_in_c.py). */
#include "common.h"

#include "structs/menu.h"

extern u32 D_0012F580[];
extern char __malloc_av_last_remainder[];
extern void *D_0012F898[];
extern void *D_0012F8A0[];
extern void *D_0012F8A8[];
extern void *D_0012F8B0[];
extern void *D_0012F8B8[];
extern void *D_0012F8C0[];
extern void *D_0012F8C8[];
extern void *D_0012F8D0[];
extern void *D_0012F8D8[];
extern void *D_0012F8E0[];
extern void *D_0012F8E8[];
extern void *D_0012F8F0[];
extern void *D_0012F8F8[];
extern void *D_0012F900[];
extern void *D_0012F908[];
extern void *D_0012F910[];
extern void *D_0012F918[];
extern void *D_0012F920[];
extern void *D_0012F928[];
extern void *D_0012F930[];
extern void *D_0012F938[];
extern void *D_0012F940[];
extern void *D_0012F948[];
extern void *D_0012F950[];
extern void *D_0012F958[];
extern void *D_0012F960[];
extern void *D_0012F968[];
extern void *D_0012F970[];
extern void *D_0012F978[];
extern void *D_0012F980[];
extern void *D_0012F988[];
extern void *D_0012F990[];
extern void *D_0012F998[];
extern void *D_0012F9A0[];
extern void *D_0012F9A8[];
extern void *D_0012F9B0[];
extern void *D_0012F9B8[];
extern void *D_0012F9C0[];
extern void *D_0012F9C8[];
extern void *D_0012F9D0[];
extern void *D_0012F9D8[];
extern void *D_0012F9E0[];
extern void *D_0012F9E8[];
extern void *D_0012F9F0[];
extern void *D_0012F9F8[];
extern void *D_0012FA00[];
extern void *D_0012FA08[];
extern void *D_0012FA10[];
extern void *D_0012FA18[];
extern void *D_0012FA20[];
extern void *D_0012FA28[];
extern void *D_0012FA30[];
extern void *D_0012FA38[];
extern void *D_0012FA40[];
extern void *D_0012FA48[];
extern void *D_0012FA50[];
extern void *D_0012FA58[];
extern void *D_0012FA60[];
extern void *D_0012FA68[];
extern void *D_0012FA70[];
extern void *D_0012FA78[];
extern void *D_0012FA80[];
extern void *D_0012FA88[];
extern void *D_0012FA90[];
extern void *D_0012FA98[];
extern void *D_0012FAA0[];
extern void *D_0012FAA8[];
extern void *D_0012FAB0[];
extern void *D_0012FAB8[];
extern void *D_0012FAC0[];
extern void *D_0012FAC8[];
extern void *D_0012FAD0[];
extern void *D_0012FAD8[];
extern void *D_0012FAE0[];
extern void *D_0012FAE8[];
extern void *D_0012FAF0[];
extern void *D_0012FAF8[];
extern void *D_0012FB00[];
extern void *D_0012FB08[];
extern void *D_0012FB10[];
extern void *D_0012FB18[];
extern void *D_0012FB20[];
extern void *D_0012FB28[];
extern void *D_0012FB30[];
extern void *D_0012FB38[];
extern void *D_0012FB40[];
extern void *D_0012FB48[];
extern void *D_0012FB50[];
extern void *D_0012FB58[];
extern void *D_0012FB60[];
extern void *D_0012FB68[];
extern void *D_0012FB70[];
extern void *D_0012FB78[];
extern void *D_0012FB80[];
extern void *D_0012FB88[];
extern void *D_0012FB90[];
extern void *D_0012FB98[];
extern void *D_0012FBA0[];
extern void *D_0012FBA8[];
extern void *D_0012FBB0[];
extern void *D_0012FBB8[];
extern void *D_0012FBC0[];
extern void *D_0012FBC8[];
extern void *D_0012FBD0[];
extern void *D_0012FBD8[];
extern void *D_0012FBE0[];
extern void *D_0012FBE8[];
extern void *D_0012FBF0[];
extern void *D_0012FBF8[];
extern void *D_0012FC00[];
extern void *D_0012FC08[];
extern void *D_0012FC10[];
extern void *D_0012FC18[];
extern void *D_0012FC20[];
extern void *D_0012FC28[];
extern void *D_0012FC30[];
extern void *D_0012FC38[];
extern void *D_0012FC40[];
extern void *D_0012FC48[];
extern void *D_0012FC50[];
extern void *D_0012FC58[];
extern void *D_0012FC60[];
extern void *D_0012FC68[];
extern void *D_0012FC70[];
extern void *D_0012FC78[];
extern void *D_0012FC80[];
extern char D_1FF8000[];
extern void map_filter_l04_0();
extern void map_filter_l04_1();
extern void map_filter_l04_2();
extern void map_filter_l04_3();
extern u32 D_001A0C90[];
extern u32 D_001A0DA8[];
extern u32 D_001A0F60[];
extern u32 D_001A11E0[];
extern u32 D_001A1460[];
extern u32 D_001A15F0[];
extern u32 D_001A1848[];
extern u32 D_001A1A00[];
extern u32 D_001A1BE0[];
extern u32 D_001A1D98[];
extern u32 D_001A1FA0[];
extern u32 D_001A2248[];
extern u32 D_001A24C8[];
extern u32 D_001A2630[];
extern u32 D_001A2810[];
extern u32 D_001A2A40[];
extern u32 D_001A2C48[];
extern u32 D_001A2D88[];
extern u32 D_001A2E78[];
extern u32 D_001CE6F8[];
extern char D_4000[];
extern void render_localized_ui_entry_list();
extern u32 D_001CE770[];
extern void menu_update_noop();
extern void draw_selected_item_ammo();
extern u32 D_001CF428[];
extern void leave_map_screen();
extern void DrawMapScreen();
extern void draw_map_screen_overlay();
extern void reset_pause_memory_card_state();
extern void draw_map_screen_layers();
extern void Pause_PageInput();
extern void DrawMissionsMenu();
extern void enter_menu_mission_list();
extern void update_menu_mission_list();
extern void MissionMenu_DrawObjectives();
extern u32 D_001CFD60[];
extern char D_1000[];
extern void update_menu_entry_actions();
extern u32 D_001CFE68[];
extern void enter_menu_stream_image();
extern void leave_menu_stream_image();
extern void advance_audio_stream_state();
extern void draw_two_texture_panels();
extern u32 D_001D09A8[];
extern u32 D_001D0D18[];
extern u32 D_001D0F20[];
extern void update_menu_option_list();
extern void DrawCheatsMenu();
extern u32 D_001D17B0[];
extern void set_pause_sound_volume();
extern void sound_options_menu();
extern void DrawSoundMenu();
extern void draw_menu_selection_text();
extern void enter_save_slot_screen();
extern void leave_save_slot_screen();
extern void saving_data_menu();
extern void draw_save_slot_list();
extern void loading_data_menu();
extern char D_001D1C00[];
extern u32 D_001D1DC0[];
extern void enter_menu_choice_list();
extern void leave_menu_choice_list();
extern void update_menu_choice_list();
extern void draw_menu_choice_list();
extern void Menu_BackInput();
extern void DrawQuitGameMenu();
extern void update_level_selection_map_screen();
extern void draw_level_selection_map_screen();
extern void enter_menu_prompt();
extern void leave_menu_prompt();
extern void Menu_ConfirmPromptInput();
extern void draw_prompt_box();
extern char D_001D2A28[];
extern void draw_selected_menu_item_text();
extern void process_global_state_flags();
extern void DrawEndScreenMenuMaybe();
extern void draw_menu_side_indicator();
extern u32 D_001D3A20[];
extern void handle_cyclic_menu_selection_input();
extern u32 D_001D3D38[];
extern u32 D_001D3FD8[];
extern u32 D_001D4130[];
extern void set_pause_action_list();
extern char D_001D4F18[];
extern void saving_data_menu2();
extern char D_001D5138[];

#include "data_inc/D_0012F580.refs"
u32 D_0012F580[] DATA_SECTION(D_0012F580) = {
#include "data_inc/D_0012F580.inc"
};

void *_impure_ptr DATA_SECTION(D_0012F86C) = D_0012F580;

u32 vfprintf_mb_cur_max[] DATA_SECTION(D_0012F870) = {
#include "data_inc/D_0012F870.inc"
};

u32 __malloc_av_[2] DATA_SECTION(D_0012F888) = {0};

void *D_0012F898[] DATA_SECTION(D_0012F898) = {
    __malloc_av_last_remainder,
    __malloc_av_last_remainder,
};

void *D_0012F8A0[] DATA_SECTION(D_0012F8A0) = {
    D_0012F898,
    D_0012F898,
};

void *D_0012F8A8[] DATA_SECTION(D_0012F8A8) = {
    D_0012F8A0,
    D_0012F8A0,
};

void *D_0012F8B0[] DATA_SECTION(D_0012F8B0) = {
    D_0012F8A8,
    D_0012F8A8,
};

void *D_0012F8B8[] DATA_SECTION(D_0012F8B8) = {
    D_0012F8B0,
    D_0012F8B0,
};

void *D_0012F8C0[] DATA_SECTION(D_0012F8C0) = {
    D_0012F8B8,
    D_0012F8B8,
};

void *D_0012F8C8[] DATA_SECTION(D_0012F8C8) = {
    D_0012F8C0,
    D_0012F8C0,
};

void *D_0012F8D0[] DATA_SECTION(D_0012F8D0) = {
    D_0012F8C8,
    D_0012F8C8,
};

void *D_0012F8D8[] DATA_SECTION(D_0012F8D8) = {
    D_0012F8D0,
    D_0012F8D0,
};

void *D_0012F8E0[] DATA_SECTION(D_0012F8E0) = {
    D_0012F8D8,
    D_0012F8D8,
};

void *D_0012F8E8[] DATA_SECTION(D_0012F8E8) = {
    D_0012F8E0,
    D_0012F8E0,
};

void *D_0012F8F0[] DATA_SECTION(D_0012F8F0) = {
    D_0012F8E8,
    D_0012F8E8,
};

void *D_0012F8F8[] DATA_SECTION(D_0012F8F8) = {
    D_0012F8F0,
    D_0012F8F0,
};

void *D_0012F900[] DATA_SECTION(D_0012F900) = {
    D_0012F8F8,
    D_0012F8F8,
};

void *D_0012F908[] DATA_SECTION(D_0012F908) = {
    D_0012F900,
    D_0012F900,
};

void *D_0012F910[] DATA_SECTION(D_0012F910) = {
    D_0012F908,
    D_0012F908,
};

void *D_0012F918[] DATA_SECTION(D_0012F918) = {
    D_0012F910,
    D_0012F910,
};

void *D_0012F920[] DATA_SECTION(D_0012F920) = {
    D_0012F918,
    D_0012F918,
};

void *D_0012F928[] DATA_SECTION(D_0012F928) = {
    D_0012F920,
    D_0012F920,
};

void *D_0012F930[] DATA_SECTION(D_0012F930) = {
    D_0012F928,
    D_0012F928,
};

void *D_0012F938[] DATA_SECTION(D_0012F938) = {
    D_0012F930,
    D_0012F930,
};

void *D_0012F940[] DATA_SECTION(D_0012F940) = {
    D_0012F938,
    D_0012F938,
};

void *D_0012F948[] DATA_SECTION(D_0012F948) = {
    D_0012F940,
    D_0012F940,
};

void *D_0012F950[] DATA_SECTION(D_0012F950) = {
    D_0012F948,
    D_0012F948,
};

void *D_0012F958[] DATA_SECTION(D_0012F958) = {
    D_0012F950,
    D_0012F950,
};

void *D_0012F960[] DATA_SECTION(D_0012F960) = {
    D_0012F958,
    D_0012F958,
};

void *D_0012F968[] DATA_SECTION(D_0012F968) = {
    D_0012F960,
    D_0012F960,
};

void *D_0012F970[] DATA_SECTION(D_0012F970) = {
    D_0012F968,
    D_0012F968,
};

void *D_0012F978[] DATA_SECTION(D_0012F978) = {
    D_0012F970,
    D_0012F970,
};

void *D_0012F980[] DATA_SECTION(D_0012F980) = {
    D_0012F978,
    D_0012F978,
};

void *D_0012F988[] DATA_SECTION(D_0012F988) = {
    D_0012F980,
    D_0012F980,
};

void *D_0012F990[] DATA_SECTION(D_0012F990) = {
    D_0012F988,
    D_0012F988,
};

void *D_0012F998[] DATA_SECTION(D_0012F998) = {
    D_0012F990,
    D_0012F990,
};

void *D_0012F9A0[] DATA_SECTION(D_0012F9A0) = {
    D_0012F998,
    D_0012F998,
};

void *D_0012F9A8[] DATA_SECTION(D_0012F9A8) = {
    D_0012F9A0,
    D_0012F9A0,
};

void *D_0012F9B0[] DATA_SECTION(D_0012F9B0) = {
    D_0012F9A8,
    D_0012F9A8,
};

void *D_0012F9B8[] DATA_SECTION(D_0012F9B8) = {
    D_0012F9B0,
    D_0012F9B0,
};

void *D_0012F9C0[] DATA_SECTION(D_0012F9C0) = {
    D_0012F9B8,
    D_0012F9B8,
};

void *D_0012F9C8[] DATA_SECTION(D_0012F9C8) = {
    D_0012F9C0,
    D_0012F9C0,
};

void *D_0012F9D0[] DATA_SECTION(D_0012F9D0) = {
    D_0012F9C8,
    D_0012F9C8,
};

void *D_0012F9D8[] DATA_SECTION(D_0012F9D8) = {
    D_0012F9D0,
    D_0012F9D0,
};

void *D_0012F9E0[] DATA_SECTION(D_0012F9E0) = {
    D_0012F9D8,
    D_0012F9D8,
};

void *D_0012F9E8[] DATA_SECTION(D_0012F9E8) = {
    D_0012F9E0,
    D_0012F9E0,
};

void *D_0012F9F0[] DATA_SECTION(D_0012F9F0) = {
    D_0012F9E8,
    D_0012F9E8,
};

void *D_0012F9F8[] DATA_SECTION(D_0012F9F8) = {
    D_0012F9F0,
    D_0012F9F0,
};

void *D_0012FA00[] DATA_SECTION(D_0012FA00) = {
    D_0012F9F8,
    D_0012F9F8,
};

void *D_0012FA08[] DATA_SECTION(D_0012FA08) = {
    D_0012FA00,
    D_0012FA00,
};

void *D_0012FA10[] DATA_SECTION(D_0012FA10) = {
    D_0012FA08,
    D_0012FA08,
};

void *D_0012FA18[] DATA_SECTION(D_0012FA18) = {
    D_0012FA10,
    D_0012FA10,
};

void *D_0012FA20[] DATA_SECTION(D_0012FA20) = {
    D_0012FA18,
    D_0012FA18,
};

void *D_0012FA28[] DATA_SECTION(D_0012FA28) = {
    D_0012FA20,
    D_0012FA20,
};

void *D_0012FA30[] DATA_SECTION(D_0012FA30) = {
    D_0012FA28,
    D_0012FA28,
};

void *D_0012FA38[] DATA_SECTION(D_0012FA38) = {
    D_0012FA30,
    D_0012FA30,
};

void *D_0012FA40[] DATA_SECTION(D_0012FA40) = {
    D_0012FA38,
    D_0012FA38,
};

void *D_0012FA48[] DATA_SECTION(D_0012FA48) = {
    D_0012FA40,
    D_0012FA40,
};

void *D_0012FA50[] DATA_SECTION(D_0012FA50) = {
    D_0012FA48,
    D_0012FA48,
};

void *D_0012FA58[] DATA_SECTION(D_0012FA58) = {
    D_0012FA50,
    D_0012FA50,
};

void *D_0012FA60[] DATA_SECTION(D_0012FA60) = {
    D_0012FA58,
    D_0012FA58,
};

void *D_0012FA68[] DATA_SECTION(D_0012FA68) = {
    D_0012FA60,
    D_0012FA60,
};

void *D_0012FA70[] DATA_SECTION(D_0012FA70) = {
    D_0012FA68,
    D_0012FA68,
};

void *D_0012FA78[] DATA_SECTION(D_0012FA78) = {
    D_0012FA70,
    D_0012FA70,
};

void *D_0012FA80[] DATA_SECTION(D_0012FA80) = {
    D_0012FA78,
    D_0012FA78,
};

void *D_0012FA88[] DATA_SECTION(D_0012FA88) = {
    D_0012FA80,
    D_0012FA80,
};

void *D_0012FA90[] DATA_SECTION(D_0012FA90) = {
    D_0012FA88,
    D_0012FA88,
};

void *D_0012FA98[] DATA_SECTION(D_0012FA98) = {
    D_0012FA90,
    D_0012FA90,
};

void *D_0012FAA0[] DATA_SECTION(D_0012FAA0) = {
    D_0012FA98,
    D_0012FA98,
};

void *D_0012FAA8[] DATA_SECTION(D_0012FAA8) = {
    D_0012FAA0,
    D_0012FAA0,
};

void *D_0012FAB0[] DATA_SECTION(D_0012FAB0) = {
    D_0012FAA8,
    D_0012FAA8,
};

void *D_0012FAB8[] DATA_SECTION(D_0012FAB8) = {
    D_0012FAB0,
    D_0012FAB0,
};

void *D_0012FAC0[] DATA_SECTION(D_0012FAC0) = {
    D_0012FAB8,
    D_0012FAB8,
};

void *D_0012FAC8[] DATA_SECTION(D_0012FAC8) = {
    D_0012FAC0,
    D_0012FAC0,
};

void *D_0012FAD0[] DATA_SECTION(D_0012FAD0) = {
    D_0012FAC8,
    D_0012FAC8,
};

void *D_0012FAD8[] DATA_SECTION(D_0012FAD8) = {
    D_0012FAD0,
    D_0012FAD0,
};

void *D_0012FAE0[] DATA_SECTION(D_0012FAE0) = {
    D_0012FAD8,
    D_0012FAD8,
};

void *D_0012FAE8[] DATA_SECTION(D_0012FAE8) = {
    D_0012FAE0,
    D_0012FAE0,
};

void *D_0012FAF0[] DATA_SECTION(D_0012FAF0) = {
    D_0012FAE8,
    D_0012FAE8,
};

void *D_0012FAF8[] DATA_SECTION(D_0012FAF8) = {
    D_0012FAF0,
    D_0012FAF0,
};

void *D_0012FB00[] DATA_SECTION(D_0012FB00) = {
    D_0012FAF8,
    D_0012FAF8,
};

void *D_0012FB08[] DATA_SECTION(D_0012FB08) = {
    D_0012FB00,
    D_0012FB00,
};

void *D_0012FB10[] DATA_SECTION(D_0012FB10) = {
    D_0012FB08,
    D_0012FB08,
};

void *D_0012FB18[] DATA_SECTION(D_0012FB18) = {
    D_0012FB10,
    D_0012FB10,
};

void *D_0012FB20[] DATA_SECTION(D_0012FB20) = {
    D_0012FB18,
    D_0012FB18,
};

void *D_0012FB28[] DATA_SECTION(D_0012FB28) = {
    D_0012FB20,
    D_0012FB20,
};

void *D_0012FB30[] DATA_SECTION(D_0012FB30) = {
    D_0012FB28,
    D_0012FB28,
};

void *D_0012FB38[] DATA_SECTION(D_0012FB38) = {
    D_0012FB30,
    D_0012FB30,
};

void *D_0012FB40[] DATA_SECTION(D_0012FB40) = {
    D_0012FB38,
    D_0012FB38,
};

void *D_0012FB48[] DATA_SECTION(D_0012FB48) = {
    D_0012FB40,
    D_0012FB40,
};

void *D_0012FB50[] DATA_SECTION(D_0012FB50) = {
    D_0012FB48,
    D_0012FB48,
};

void *D_0012FB58[] DATA_SECTION(D_0012FB58) = {
    D_0012FB50,
    D_0012FB50,
};

void *D_0012FB60[] DATA_SECTION(D_0012FB60) = {
    D_0012FB58,
    D_0012FB58,
};

void *D_0012FB68[] DATA_SECTION(D_0012FB68) = {
    D_0012FB60,
    D_0012FB60,
};

void *D_0012FB70[] DATA_SECTION(D_0012FB70) = {
    D_0012FB68,
    D_0012FB68,
};

void *D_0012FB78[] DATA_SECTION(D_0012FB78) = {
    D_0012FB70,
    D_0012FB70,
};

void *D_0012FB80[] DATA_SECTION(D_0012FB80) = {
    D_0012FB78,
    D_0012FB78,
};

void *D_0012FB88[] DATA_SECTION(D_0012FB88) = {
    D_0012FB80,
    D_0012FB80,
};

void *D_0012FB90[] DATA_SECTION(D_0012FB90) = {
    D_0012FB88,
    D_0012FB88,
};

void *D_0012FB98[] DATA_SECTION(D_0012FB98) = {
    D_0012FB90,
    D_0012FB90,
};

void *D_0012FBA0[] DATA_SECTION(D_0012FBA0) = {
    D_0012FB98,
    D_0012FB98,
};

void *D_0012FBA8[] DATA_SECTION(D_0012FBA8) = {
    D_0012FBA0,
    D_0012FBA0,
};

void *D_0012FBB0[] DATA_SECTION(D_0012FBB0) = {
    D_0012FBA8,
    D_0012FBA8,
};

void *D_0012FBB8[] DATA_SECTION(D_0012FBB8) = {
    D_0012FBB0,
    D_0012FBB0,
};

void *D_0012FBC0[] DATA_SECTION(D_0012FBC0) = {
    D_0012FBB8,
    D_0012FBB8,
};

void *D_0012FBC8[] DATA_SECTION(D_0012FBC8) = {
    D_0012FBC0,
    D_0012FBC0,
};

void *D_0012FBD0[] DATA_SECTION(D_0012FBD0) = {
    D_0012FBC8,
    D_0012FBC8,
};

void *D_0012FBD8[] DATA_SECTION(D_0012FBD8) = {
    D_0012FBD0,
    D_0012FBD0,
};

void *D_0012FBE0[] DATA_SECTION(D_0012FBE0) = {
    D_0012FBD8,
    D_0012FBD8,
};

void *D_0012FBE8[] DATA_SECTION(D_0012FBE8) = {
    D_0012FBE0,
    D_0012FBE0,
};

void *D_0012FBF0[] DATA_SECTION(D_0012FBF0) = {
    D_0012FBE8,
    D_0012FBE8,
};

void *D_0012FBF8[] DATA_SECTION(D_0012FBF8) = {
    D_0012FBF0,
    D_0012FBF0,
};

void *D_0012FC00[] DATA_SECTION(D_0012FC00) = {
    D_0012FBF8,
    D_0012FBF8,
};

void *D_0012FC08[] DATA_SECTION(D_0012FC08) = {
    D_0012FC00,
    D_0012FC00,
};

void *D_0012FC10[] DATA_SECTION(D_0012FC10) = {
    D_0012FC08,
    D_0012FC08,
};

void *D_0012FC18[] DATA_SECTION(D_0012FC18) = {
    D_0012FC10,
    D_0012FC10,
};

void *D_0012FC20[] DATA_SECTION(D_0012FC20) = {
    D_0012FC18,
    D_0012FC18,
};

void *D_0012FC28[] DATA_SECTION(D_0012FC28) = {
    D_0012FC20,
    D_0012FC20,
};

void *D_0012FC30[] DATA_SECTION(D_0012FC30) = {
    D_0012FC28,
    D_0012FC28,
};

void *D_0012FC38[] DATA_SECTION(D_0012FC38) = {
    D_0012FC30,
    D_0012FC30,
};

void *D_0012FC40[] DATA_SECTION(D_0012FC40) = {
    D_0012FC38,
    D_0012FC38,
};

void *D_0012FC48[] DATA_SECTION(D_0012FC48) = {
    D_0012FC40,
    D_0012FC40,
};

void *D_0012FC50[] DATA_SECTION(D_0012FC50) = {
    D_0012FC48,
    D_0012FC48,
};

void *D_0012FC58[] DATA_SECTION(D_0012FC58) = {
    D_0012FC50,
    D_0012FC50,
};

void *D_0012FC60[] DATA_SECTION(D_0012FC60) = {
    D_0012FC58,
    D_0012FC58,
};

void *D_0012FC68[] DATA_SECTION(D_0012FC68) = {
    D_0012FC60,
    D_0012FC60,
};

void *D_0012FC70[] DATA_SECTION(D_0012FC70) = {
    D_0012FC68,
    D_0012FC68,
};

void *D_0012FC78[] DATA_SECTION(D_0012FC78) = {
    D_0012FC70,
    D_0012FC70,
};

void *D_0012FC80[] DATA_SECTION(D_0012FC80) = {
    D_0012FC78,
    D_0012FC78,
    D_0012FC80,
    D_0012FC80,
};

u32 __malloc_top_pad[2] DATA_SECTION(D_0012FC98) = {0};

u32 __malloc_sbrk_base[] DATA_SECTION(D_0012FCA0) = {
#include "data_inc/D_0012FCA0.inc"
};

u32 __malloc_current_mallinfo[] DATA_SECTION(D_0012FCB8) = {
#include "data_inc/D_0012FCB8.inc"
};

u32 sif_lib_version_string DATA_SECTION(D_0012FCEC) =
#include "data_inc/D_0012FCEC.inc"
    ;

void *heap_break DATA_SECTION(D_0012FCF4) = D_1FF8000;

u32 D_001300E8[18] DATA_SECTION(D_001300E8) = {0};

u32 D_00130178[] DATA_SECTION(D_00130178) = {
#include "data_inc/D_00130178.inc"
};

#include "data_inc/D_00130248.refs"
u32 D_00130248[] DATA_SECTION(D_00130248) = {
#include "data_inc/D_00130248.inc"
};

u32 D_00130368[] DATA_SECTION(D_00130368) = {
#include "data_inc/D_00130368.inc"
};

#include "data_inc/D_001303E8.refs"
u32 D_001303E8[] DATA_SECTION(D_001303E8) = {
#include "data_inc/D_001303E8.inc"
};

u32 cd_debug_level DATA_SECTION(D_001313D0) = 0;

u32 cd_ncmd_sema DATA_SECTION(D_001313E8) =
#include "data_inc/D_001313E8.inc"
    ;

u32 cd_scmd_sema DATA_SECTION(D_001313EC) =
#include "data_inc/D_001313EC.inc"
    ;

u32 cd_ncmd_busy DATA_SECTION(D_001313F0) = 0;

u32 cd_read_mode_flags DATA_SECTION(D_001313F4) = 0;

u32 cd_callback_num DATA_SECTION(D_00131414) = 0;

u32 cd_last_callback_num[10] DATA_SECTION(D_00131418) = {0};

u32 cd_ncmd_rpc_client[12] DATA_SECTION(D_00132590) = {0};

u32 cd_scmd_recv_buffer[272] DATA_SECTION(D_001325C0) = {0};

u32 cd_scmd_rpc_client[] DATA_SECTION(D_00132E08) = {
#include "data_inc/D_00132E08.inc"
};

u32 D_00132F00[] DATA_SECTION(D_00132F00) = {
#include "data_inc/D_00132F00.inc"
};

u32 snd_sync_buffer DATA_SECTION(D_00133200) = 0;

u8 snd_sync_send_buffer[320] DATA_SECTION(D_00133240) = {0};

u8 disc_table[10440] DATA_SECTION(D_00137C80) = {0};

u32 D_00165E00[] DATA_SECTION(D_00165E00) = {
#include "data_inc/D_00165E00.inc"
};

u32 gp_base[9408] DATA_SECTION(D_00166D00) = {0};

u32 D_00170000[16384] DATA_SECTION(D_00170000) = {0};

u32 D_00180000[2] DATA_SECTION(D_00180000) = {0};

u32 D_00180008[4] DATA_SECTION(D_00180008) = {0};

u32 D_00180018[6266] DATA_SECTION(D_00180018) = {0};

u32 startlevel_sound_defs[] DATA_SECTION(D_00186200) = {
#include "data_inc/D_00186200.inc"
};

u32 moby_class_472_sound_defs[] DATA_SECTION(D_001862E0) = {
#include "data_inc/D_001862E0.inc"
};

u32 transition_sound_cues[] DATA_SECTION(D_001863B0) = {
#include "data_inc/D_001863B0.inc"
};

u32 level_init_cleared_block[16] DATA_SECTION(D_00186410) = {0};

u32 item_info_table[2] DATA_SECTION(D_001864D0) = {0};

float gCamera[80] DATA_SECTION(D_00187040) = {0};

u32 camera_position[6] DATA_SECTION(D_00187180) = {0};

u32 D_001871A0[8] DATA_SECTION(D_001871A0) = {0};

u32 cur_cam[4] DATA_SECTION(D_001871C0) = {0};

u32 cam_coll_state[56] DATA_SECTION(D_001871D0) = {0};

u32 camera_rows[4] DATA_SECTION(D_00187390) = {0};

u32 effect_ribbon[68] DATA_SECTION(D_00187400) = {0};

u32 draw_config DATA_SECTION(D_0018A3B0) = 0;

u32 D_0018A400[512] DATA_SECTION(D_0018A400) = {0};

u32 occl_cam_state[5] DATA_SECTION(D_0018C418) = {0};

u32 D_0018CB40[] DATA_SECTION(D_0018CB40) = {
#include "data_inc/D_0018CB40.inc"
};

u32 render_sequence[13] DATA_SECTION(D_0018CC20) = {0};

u32 view_context[44] DATA_SECTION(D_0018CE00) = {0};

float view_tan_half_fov[4] DATA_SECTION(D_0018CEB0) = {0};

u32 clip_transform[36] DATA_SECTION(D_0018CF80) = {0};

u32 D_0018E450[252] DATA_SECTION(D_0018E450) = {0};

u32 D_00190000[5] DATA_SECTION(D_00190000) = {0};

u32 occl_visibility[32] DATA_SECTION(D_001940C0) = {0};

u32 level_resource_buffers[2] DATA_SECTION(D_001941C0) = {0};

u32 coll_output[8] DATA_SECTION(D_00194200) = {0};

u32 coll_hit_pos[24] DATA_SECTION(D_00194220) = {0};

u32 coll_output_aux_buffer[16] DATA_SECTION(D_00194280) = {0};

u32 image_clear_buffer[4224] DATA_SECTION(D_001942C0) = {0};

u32 D_001984C0[1024] DATA_SECTION(D_001984C0) = {0};

u32 g_help_state[] DATA_SECTION(D_001997D0) = {
#include "data_inc/D_001997D0.inc"
};

u32 D_00199AD0[] DATA_SECTION(D_00199AD0) = {
#include "data_inc/D_00199AD0.inc"
};

u32 hud_state[6] DATA_SECTION(D_0019A4E8) = {0};

u32 D_0019ACC0[128] DATA_SECTION(D_0019ACC0) = {0};

u32 dir_lights[228] DATA_SECTION(D_0019BEC0) = {0};

u32 menu_light_direction[4] DATA_SECTION(D_0019C250) = {0};

u32 D_0019C260[24] DATA_SECTION(D_0019C260) = {0};

u32 point_lights[128] DATA_SECTION(D_0019C2C0) = {0};

u32 point_light_data[2144] DATA_SECTION(D_0019C4C0) = {0};

u32 special_material_template[6] DATA_SECTION(D_0019E7C0) = {0};

void *D_001A0000[] DATA_SECTION(D_001A0000) = {
    0, 0, 0, 0, map_filter_l04_0, map_filter_l04_1, map_filter_l04_2, map_filter_l04_3, 0,
};

u32 level_map_selection[3] DATA_SECTION(D_001A01F0) = {0};

u32 memcard_dir_entries[8] DATA_SECTION(D_001A0980) = {0};

u32 memcard_save_file_name_buffer[168] DATA_SECTION(D_001A09A0) = {0};

u32 D_001A0C40[] DATA_SECTION(D_001A0C40) = {
#include "data_inc/D_001A0C40.inc"
};

#include "data_inc/D_001A0C90.refs"
u32 D_001A0C90[] DATA_SECTION(D_001A0C90) = {
#include "data_inc/D_001A0C90.inc"
};

u32 D_001A0DA8[] DATA_SECTION(D_001A0DA8) = {
#include "data_inc/D_001A0DA8.inc"
};

u32 D_001A0F60[] DATA_SECTION(D_001A0F60) = {
#include "data_inc/D_001A0F60.inc"
};

u32 D_001A11E0[] DATA_SECTION(D_001A11E0) = {
#include "data_inc/D_001A11E0.inc"
};

u32 D_001A1460[] DATA_SECTION(D_001A1460) = {
#include "data_inc/D_001A1460.inc"
};

u32 D_001A15F0[] DATA_SECTION(D_001A15F0) = {
#include "data_inc/D_001A15F0.inc"
};

u32 D_001A1848[] DATA_SECTION(D_001A1848) = {
#include "data_inc/D_001A1848.inc"
};

u32 D_001A1A00[] DATA_SECTION(D_001A1A00) = {
#include "data_inc/D_001A1A00.inc"
};

u32 D_001A1BE0[] DATA_SECTION(D_001A1BE0) = {
#include "data_inc/D_001A1BE0.inc"
};

u32 D_001A1D98[] DATA_SECTION(D_001A1D98) = {
#include "data_inc/D_001A1D98.inc"
};

u32 D_001A1FA0[] DATA_SECTION(D_001A1FA0) = {
#include "data_inc/D_001A1FA0.inc"
};

#include "data_inc/D_001A20E0.refs"
u32 D_001A20E0[] DATA_SECTION(D_001A20E0) = {
#include "data_inc/D_001A20E0.inc"
};

u32 D_001A2248[] DATA_SECTION(D_001A2248) = {
#include "data_inc/D_001A2248.inc"
};

#include "data_inc/D_001A23D8.refs"
u32 D_001A23D8[] DATA_SECTION(D_001A23D8) = {
#include "data_inc/D_001A23D8.inc"
};

u32 D_001A24C8[] DATA_SECTION(D_001A24C8) = {
#include "data_inc/D_001A24C8.inc"
};

u32 D_001A25B8[] DATA_SECTION(D_001A25B8) = {
#include "data_inc/D_001A25B8.inc"
};

u32 D_001A2630[] DATA_SECTION(D_001A2630) = {
#include "data_inc/D_001A2630.inc"
};

#include "data_inc/D_001A26D0.refs"
u32 D_001A26D0[] DATA_SECTION(D_001A26D0) = {
#include "data_inc/D_001A26D0.inc"
};

u32 D_001A2810[] DATA_SECTION(D_001A2810) = {
#include "data_inc/D_001A2810.inc"
};

#include "data_inc/D_001A2928.refs"
u32 D_001A2928[] DATA_SECTION(D_001A2928) = {
#include "data_inc/D_001A2928.inc"
};

u32 D_001A2A40[] DATA_SECTION(D_001A2A40) = {
#include "data_inc/D_001A2A40.inc"
};

#include "data_inc/D_001A2B30.refs"
u32 D_001A2B30[] DATA_SECTION(D_001A2B30) = {
#include "data_inc/D_001A2B30.inc"
};

u32 D_001A2C48[] DATA_SECTION(D_001A2C48) = {
#include "data_inc/D_001A2C48.inc"
};

u32 D_001A2D10[] DATA_SECTION(D_001A2D10) = {
#include "data_inc/D_001A2D10.inc"
};

u32 D_001A2D88[] DATA_SECTION(D_001A2D88) = {
#include "data_inc/D_001A2D88.inc"
};

u32 D_001A2E28[] DATA_SECTION(D_001A2E28) = {
#include "data_inc/D_001A2E28.inc"
};

u32 D_001A2E78[] DATA_SECTION(D_001A2E78) = {
#include "data_inc/D_001A2E78.inc"
};

void *map_icon_lists[] DATA_SECTION(D_001A2F40) = {
    D_001A0C90, D_001A0DA8, D_001A0F60, D_001A11E0, D_001A1460, D_001A15F0, D_001A1848,
    D_001A1A00, D_001A1BE0, D_001A1D98, D_001A1FA0, D_001A2248, D_001A24C8, D_001A2630,
    D_001A2810, D_001A2A40, D_001A2C48, D_001A2D88, D_001A2E78, 0,
};

u32 debug_font_buffer[5168] DATA_SECTION(D_001AAF40) = {0};

u32 D_001B0000[8] DATA_SECTION(D_001B0000) = {0};

u32 D_001B0020[3016] DATA_SECTION(D_001B0020) = {0};

u32 D_001B3080[64] DATA_SECTION(D_001B3080) = {0};

u32 D_001B3180[32] DATA_SECTION(D_001B3180) = {0};

u32 moby_class_resources[224] DATA_SECTION(D_001B3580) = {0};

u32 resident_moby_class_data[224] DATA_SECTION(D_001B3900) = {0};

u32 resident_class_original_field_2c[224] DATA_SECTION(D_001B6500) = {0};

u32 D_001B7A00[24] DATA_SECTION(D_001B7A00) = {0};

u32 D_001C0000[7] DATA_SECTION(D_001C0000) = {0};

u32 D_001C7AC0[112] DATA_SECTION(D_001C7AC0) = {0};

u32 D_001C7C80[512] DATA_SECTION(D_001C7C80) = {0};

u32 D_001C8480[256] DATA_SECTION(D_001C8480) = {0};

u32 D_001C8880[96] DATA_SECTION(D_001C8880) = {0};

float shadow_light_dir[16] DATA_SECTION(D_001CAE00) = {0};

u32 resident_indexed_textures[1024] DATA_SECTION(D_001CAE40) = {0};

u32 space_flight_paths[240] DATA_SECTION(D_001CC730) = {0};

u32 D_001CCAF0[] DATA_SECTION(D_001CCAF0) = {
#include "data_inc/D_001CCAF0.inc"
};

u32 D_001CCB80[] DATA_SECTION(D_001CCB80) = {
#include "data_inc/D_001CCB80.inc"
};

u32 D_001CCC10[] DATA_SECTION(D_001CCC10) = {
#include "data_inc/D_001CCC10.inc"
};

u32 D_001CCC68[] DATA_SECTION(D_001CCC68) = {
#include "data_inc/D_001CCC68.inc"
};

u32 D_001CCCC0[] DATA_SECTION(D_001CCCC0) = {
#include "data_inc/D_001CCCC0.inc"
};

u32 D_001CCD18[] DATA_SECTION(D_001CCD18) = {
#include "data_inc/D_001CCD18.inc"
};

u32 D_001CCD70[] DATA_SECTION(D_001CCD70) = {
#include "data_inc/D_001CCD70.inc"
};

u32 D_001CCDE0[] DATA_SECTION(D_001CCDE0) = {
#include "data_inc/D_001CCDE0.inc"
};

#include "data_inc/D_001CCE50.refs"
u32 D_001CCE50[] DATA_SECTION(D_001CCE50) = {
#include "data_inc/D_001CCE50.inc"
};

u32 D_001CCEE0[] DATA_SECTION(D_001CCEE0) = {
#include "data_inc/D_001CCEE0.inc"
};

#include "data_inc/D_001CCF88.refs"
u32 D_001CCF88[] DATA_SECTION(D_001CCF88) = {
#include "data_inc/D_001CCF88.inc"
};

#include "data_inc/D_001CD018.refs"
u32 D_001CD018[] DATA_SECTION(D_001CD018) = {
#include "data_inc/D_001CD018.inc"
};

u32 D_001CD070[] DATA_SECTION(D_001CD070) = {
#include "data_inc/D_001CD070.inc"
};

u32 D_001CD0E0[] DATA_SECTION(D_001CD0E0) = {
#include "data_inc/D_001CD0E0.inc"
};

u32 D_001CD170[] DATA_SECTION(D_001CD170) = {
#include "data_inc/D_001CD170.inc"
};

u32 D_001CD200[] DATA_SECTION(D_001CD200) = {
#include "data_inc/D_001CD200.inc"
};

u32 D_001CD258[] DATA_SECTION(D_001CD258) = {
#include "data_inc/D_001CD258.inc"
};

u32 D_001CD2B0[] DATA_SECTION(D_001CD2B0) = {
#include "data_inc/D_001CD2B0.inc"
};

u32 D_001CD308[] DATA_SECTION(D_001CD308) = {
#include "data_inc/D_001CD308.inc"
};

u32 D_001CD360[] DATA_SECTION(D_001CD360) = {
#include "data_inc/D_001CD360.inc"
};

u32 D_001CD380[] DATA_SECTION(D_001CD380) = {
#include "data_inc/D_001CD380.inc"
};

u32 D_001CD410[] DATA_SECTION(D_001CD410) = {
#include "data_inc/D_001CD410.inc"
};

u32 D_001CD4A0[] DATA_SECTION(D_001CD4A0) = {
#include "data_inc/D_001CD4A0.inc"
};

u32 D_001CD4D8[] DATA_SECTION(D_001CD4D8) = {
#include "data_inc/D_001CD4D8.inc"
};

#include "data_inc/D_001CD4F8.refs"
u32 D_001CD4F8[] DATA_SECTION(D_001CD4F8) = {
#include "data_inc/D_001CD4F8.inc"
};

#include "data_inc/D_001CD588.refs"
u32 D_001CD588[] DATA_SECTION(D_001CD588) = {
#include "data_inc/D_001CD588.inc"
};

#include "data_inc/D_001CD5E0.refs"
u32 D_001CD5E0[] DATA_SECTION(D_001CD5E0) = {
#include "data_inc/D_001CD5E0.inc"
};

#include "data_inc/D_001CD638.refs"
u32 D_001CD638[] DATA_SECTION(D_001CD638) = {
#include "data_inc/D_001CD638.inc"
};

#include "data_inc/D_001CD690.refs"
u32 D_001CD690[] DATA_SECTION(D_001CD690) = {
#include "data_inc/D_001CD690.inc"
};

#include "data_inc/D_001CD6E8.refs"
u32 D_001CD6E8[] DATA_SECTION(D_001CD6E8) = {
#include "data_inc/D_001CD6E8.inc"
};

#include "data_inc/D_001CD740.refs"
u32 D_001CD740[] DATA_SECTION(D_001CD740) = {
#include "data_inc/D_001CD740.inc"
};

#include "data_inc/D_001CD798.refs"
u32 D_001CD798[] DATA_SECTION(D_001CD798) = {
#include "data_inc/D_001CD798.inc"
};

#include "data_inc/D_001CD7F0.refs"
u32 D_001CD7F0[] DATA_SECTION(D_001CD7F0) = {
#include "data_inc/D_001CD7F0.inc"
};

#include "data_inc/D_001CD848.refs"
u32 D_001CD848[] DATA_SECTION(D_001CD848) = {
#include "data_inc/D_001CD848.inc"
};

#include "data_inc/D_001CD8A0.refs"
u32 D_001CD8A0[] DATA_SECTION(D_001CD8A0) = {
#include "data_inc/D_001CD8A0.inc"
};

u32 part_slot_bitmap[128] DATA_SECTION(D_001CDB00) = {0};

u32 D_001CE100[128] DATA_SECTION(D_001CE100) = {0};

u32 particle_texture_ptrs[23] DATA_SECTION(D_001CE300) = {0};

u32 D_001CE678[] DATA_SECTION(D_001CE678) = {
#include "data_inc/D_001CE678.inc"
};

u32 D_001CE6F8[] DATA_SECTION(D_001CE6F8) = {
#include "data_inc/D_001CE6F8.inc"
};

void *D_001CE720[] DATA_SECTION(D_001CE720) = {
    0, render_localized_ui_entry_list, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, (char *)D_4000 + 0x2, D_001CE6F8, 0, 0, 0, 0, 0, 0,
};

u32 D_001CE770[] DATA_SECTION(D_001CE770) = {
#include "data_inc/D_001CE770.inc"
};

u32 D_001CE788[] DATA_SECTION(D_001CE788) = {
#include "data_inc/D_001CE788.inc"
};

void *D_001CE7B8[] DATA_SECTION(D_001CE7B8) = {
    0, render_localized_ui_entry_list, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, (char *)D_4000 + 0x2, D_001CE770, 0, 0, 0, 0, 0, 0,
};

#include "data_inc/D_001CE808.refs"
u32 D_001CE808[] DATA_SECTION(D_001CE808) = {
#include "data_inc/D_001CE808.inc"
};

#include "data_inc/D_001CE890.refs"
u32 D_001CE890[] DATA_SECTION(D_001CE890) = {
#include "data_inc/D_001CE890.inc"
};

#include "data_inc/D_001CE8A8.refs"
u32 D_001CE8A8[] DATA_SECTION(D_001CE8A8) = {
#include "data_inc/D_001CE8A8.inc"
};

#include "data_inc/D_001CE8C0.refs"
u32 D_001CE8C0[] DATA_SECTION(D_001CE8C0) = {
#include "data_inc/D_001CE8C0.inc"
};

#include "data_inc/D_001CE8D8.refs"
u32 D_001CE8D8[] DATA_SECTION(D_001CE8D8) = {
#include "data_inc/D_001CE8D8.inc"
};

#include "data_inc/D_001CE8F0.refs"
u32 D_001CE8F0[] DATA_SECTION(D_001CE8F0) = {
#include "data_inc/D_001CE8F0.inc"
};

#include "data_inc/D_001CE908.refs"
u32 D_001CE908[] DATA_SECTION(D_001CE908) = {
#include "data_inc/D_001CE908.inc"
};

#include "data_inc/D_001CE920.refs"
u32 D_001CE920[] DATA_SECTION(D_001CE920) = {
#include "data_inc/D_001CE920.inc"
};

#include "data_inc/D_001CE988.refs"
u32 D_001CE988[] DATA_SECTION(D_001CE988) = {
#include "data_inc/D_001CE988.inc"
};

#include "data_inc/D_001CE9D8.refs"
u32 D_001CE9D8[] DATA_SECTION(D_001CE9D8) = {
#include "data_inc/D_001CE9D8.inc"
};

#include "data_inc/D_001CEA28.refs"
u32 D_001CEA28[] DATA_SECTION(D_001CEA28) = {
#include "data_inc/D_001CEA28.inc"
};

#include "data_inc/D_001CEA78.refs"
u32 D_001CEA78[] DATA_SECTION(D_001CEA78) = {
#include "data_inc/D_001CEA78.inc"
};

#include "data_inc/D_001CEBF0.refs"
u32 D_001CEBF0[] DATA_SECTION(D_001CEBF0) = {
#include "data_inc/D_001CEBF0.inc"
};

#include "data_inc/D_001CEC48.refs"
u32 D_001CEC48[] DATA_SECTION(D_001CEC48) = {
#include "data_inc/D_001CEC48.inc"
};

#include "data_inc/D_001CECA0.refs"
u32 D_001CECA0[] DATA_SECTION(D_001CECA0) = {
#include "data_inc/D_001CECA0.inc"
};

#include "data_inc/D_001CECF8.refs"
u32 D_001CECF8[] DATA_SECTION(D_001CECF8) = {
#include "data_inc/D_001CECF8.inc"
};

#include "data_inc/D_001CED50.refs"
u32 D_001CED50[] DATA_SECTION(D_001CED50) = {
#include "data_inc/D_001CED50.inc"
};

#include "data_inc/D_001CEDA8.refs"
u32 D_001CEDA8[] DATA_SECTION(D_001CEDA8) = {
#include "data_inc/D_001CEDA8.inc"
};

#include "data_inc/D_001CEE00.refs"
u32 D_001CEE00[] DATA_SECTION(D_001CEE00) = {
#include "data_inc/D_001CEE00.inc"
};

#include "data_inc/D_001CEE68.refs"
u32 D_001CEE68[] DATA_SECTION(D_001CEE68) = {
#include "data_inc/D_001CEE68.inc"
};

#include "data_inc/D_001CEED0.refs"
u32 D_001CEED0[] DATA_SECTION(D_001CEED0) = {
#include "data_inc/D_001CEED0.inc"
};

#include "data_inc/D_001CEF38.refs"
u32 D_001CEF38[] DATA_SECTION(D_001CEF38) = {
#include "data_inc/D_001CEF38.inc"
};

#include "data_inc/D_001CF0C0.refs"
u32 D_001CF0C0[] DATA_SECTION(D_001CF0C0) = {
#include "data_inc/D_001CF0C0.inc"
};

#include "data_inc/D_001CF118.refs"
u32 D_001CF118[] DATA_SECTION(D_001CF118) = {
#include "data_inc/D_001CF118.inc"
};

#include "data_inc/D_001CF1D8.refs"
u32 D_001CF1D8[] DATA_SECTION(D_001CF1D8) = {
#include "data_inc/D_001CF1D8.inc"
};

#include "data_inc/D_001CF300.refs"
u32 D_001CF300[] DATA_SECTION(D_001CF300) = {
#include "data_inc/D_001CF300.inc"
};

void *D_001CF3C0[] DATA_SECTION(D_001CF3C0) = {
    menu_update_noop, draw_selected_item_ammo, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

u32 D_001CF428[] DATA_SECTION(D_001CF428) = {
#include "data_inc/D_001CF428.inc"
};

void *D_001CF450[] DATA_SECTION(D_001CF450) = {
    0, render_localized_ui_entry_list, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, (char *)D_4000 + 0x2, D_001CF428, 0, 0, 0, 0, 0, 0,
};

#include "data_inc/D_001CF5C0.refs"
u32 D_001CF5C0[] DATA_SECTION(D_001CF5C0) = {
#include "data_inc/D_001CF5C0.inc"
};

#include "data_inc/D_001CF618.refs"
u32 D_001CF618[] DATA_SECTION(D_001CF618) = {
#include "data_inc/D_001CF618.inc"
};

#include "data_inc/D_001CF680.refs"
u32 D_001CF680[] DATA_SECTION(D_001CF680) = {
#include "data_inc/D_001CF680.inc"
};

#include "data_inc/D_001CF6E8.refs"
u32 D_001CF6E8[] DATA_SECTION(D_001CF6E8) = {
#include "data_inc/D_001CF6E8.inc"
};

#include "data_inc/D_001CF798.refs"
u32 map_menu_page[] DATA_SECTION(D_001CF798) = {
#include "data_inc/D_001CF798.inc"
};

#include "data_inc/D_001CF820.refs"
u32 D_001CF820[] DATA_SECTION(D_001CF820) = {
#include "data_inc/D_001CF820.inc"
};

#include "data_inc/D_001CF878.refs"
u32 D_001CF878[] DATA_SECTION(D_001CF878) = {
#include "data_inc/D_001CF878.inc"
};

void *D_001CF8D0[] DATA_SECTION(D_001CF8D0) = {
    DrawMapScreen,
    draw_map_screen_overlay,
    0,
    leave_map_screen,
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
    0,
    0,
    0,
    0,
    0,
    0,
};

void *D_001CF938[] DATA_SECTION(D_001CF938) = {
    0,
    draw_map_screen_layers,
    reset_pause_memory_card_state,
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
    0,
    0,
    0,
    0,
    0,
    0,
    0,
};

void *D_001CF9A0[] DATA_SECTION(D_001CF9A0) = {
    Pause_PageInput, DrawMissionsMenu, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

#include "data_inc/D_001CFA80.refs"
u32 D_001CFA80[] DATA_SECTION(D_001CFA80) = {
#include "data_inc/D_001CFA80.inc"
};

#include "data_inc/D_001CFAE8.refs"
u32 D_001CFAE8[] DATA_SECTION(D_001CFAE8) = {
#include "data_inc/D_001CFAE8.inc"
};

void *D_001CFB40[] DATA_SECTION(D_001CFB40) = {
    update_menu_mission_list,
    MissionMenu_DrawObjectives,
    enter_menu_mission_list,
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
};

#include "data_inc/D_001CFBC0.refs"
u32 D_001CFBC0[] DATA_SECTION(D_001CFBC0) = {
#include "data_inc/D_001CFBC0.inc"
};

#include "data_inc/D_001CFCA0.refs"
u32 D_001CFCA0[] DATA_SECTION(D_001CFCA0) = {
#include "data_inc/D_001CFCA0.inc"
};

#include "data_inc/D_001CFD08.refs"
u32 D_001CFD08[] DATA_SECTION(D_001CFD08) = {
#include "data_inc/D_001CFD08.inc"
};

#include "data_inc/D_001CFD60.refs"
u32 D_001CFD60[] DATA_SECTION(D_001CFD60) = {
#include "data_inc/D_001CFD60.inc"
};

u32 D_001CFDA8[] DATA_SECTION(D_001CFDA8) = {
#include "data_inc/D_001CFDA8.inc"
};

#include "data_inc/D_001CFDC0.refs"
u32 D_001CFDC0[] DATA_SECTION(D_001CFDC0) = {
#include "data_inc/D_001CFDC0.inc"
};

void *D_001CFE18[] DATA_SECTION(D_001CFE18) = {
    update_menu_entry_actions,
    render_localized_ui_entry_list,
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
    D_1000,
    D_001CFD60,
    0,
    0,
    0,
    0,
    0,
    0,
};

u32 D_001CFE68[] DATA_SECTION(D_001CFE68) = {
#include "data_inc/D_001CFE68.inc"
};

void *D_001CFE90[] DATA_SECTION(D_001CFE90) = {
    0, render_localized_ui_entry_list, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, (char *)D_4000 + 0x2, D_001CFE68, 0, 0, 0, 0, 0, 0,
};

#include "data_inc/D_001CFEE0.refs"
u32 D_001CFEE0[] DATA_SECTION(D_001CFEE0) = {
#include "data_inc/D_001CFEE0.inc"
};

#include "data_inc/D_001CFF68.refs"
u32 D_001CFF68[] DATA_SECTION(D_001CFF68) = {
#include "data_inc/D_001CFF68.inc"
};

u32 D_001D0000[9] DATA_SECTION(D_001D0000) = {0};

#include "data_inc/D_001D06D8.refs"
u32 D_001D06D8[] DATA_SECTION(D_001D06D8) = {
#include "data_inc/D_001D06D8.inc"
};

#include "data_inc/D_001D0728.refs"
u32 D_001D0728[] DATA_SECTION(D_001D0728) = {
#include "data_inc/D_001D0728.inc"
};

#include "data_inc/D_001D0808.refs"
u32 D_001D0808[] DATA_SECTION(D_001D0808) = {
#include "data_inc/D_001D0808.inc"
};

void *D_001D0860[] DATA_SECTION(D_001D0860) = {
    advance_audio_stream_state,
    draw_two_texture_panels,
    enter_menu_stream_image,
    leave_menu_stream_image,
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
    0,
    0,
    0,
    0,
    0,
    0,
};

#include "data_inc/D_001D0950.refs"
u32 D_001D0950[] DATA_SECTION(D_001D0950) = {
#include "data_inc/D_001D0950.inc"
};

u32 D_001D09A8[] DATA_SECTION(D_001D09A8) = {
#include "data_inc/D_001D09A8.inc"
};

void *D_001D0AC0[] DATA_SECTION(D_001D0AC0) = {
    update_menu_entry_actions,
    render_localized_ui_entry_list,
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
    D_1000,
    D_001D09A8,
    0,
    0,
    0,
    0,
    0,
    0,
};

#include "data_inc/D_001D0B10.refs"
u32 D_001D0B10[] DATA_SECTION(D_001D0B10) = {
#include "data_inc/D_001D0B10.inc"
};

#include "data_inc/D_001D0B78.refs"
u32 D_001D0B78[] DATA_SECTION(D_001D0B78) = {
#include "data_inc/D_001D0B78.inc"
};

#include "data_inc/D_001D0C58.refs"
u32 D_001D0C58[] DATA_SECTION(D_001D0C58) = {
#include "data_inc/D_001D0C58.inc"
};

#include "data_inc/D_001D0CB0.refs"
u32 D_001D0CB0[] DATA_SECTION(D_001D0CB0) = {
#include "data_inc/D_001D0CB0.inc"
};

#include "data_inc/D_001D0D18.refs"
u32 D_001D0D18[] DATA_SECTION(D_001D0D18) = {
#include "data_inc/D_001D0D18.inc"
};

void *D_001D0D78[] DATA_SECTION(D_001D0D78) = {
    update_menu_entry_actions,
    render_localized_ui_entry_list,
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
    D_1000,
    D_001D0D18,
    0,
    0,
    0,
    0,
    0,
    0,
};

#include "data_inc/D_001D0DE8.refs"
u32 D_001D0DE8[] DATA_SECTION(D_001D0DE8) = {
#include "data_inc/D_001D0DE8.inc"
};

#include "data_inc/D_001D0EC8.refs"
u32 D_001D0EC8[] DATA_SECTION(D_001D0EC8) = {
#include "data_inc/D_001D0EC8.inc"
};

#include "data_inc/D_001D0F20.refs"
u32 D_001D0F20[] DATA_SECTION(D_001D0F20) = {
#include "data_inc/D_001D0F20.inc"
};

void *D_001D0F60[] DATA_SECTION(D_001D0F60) = {
    update_menu_option_list, DrawCheatsMenu, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, D_001D0F20, 0, 0,
};

#include "data_inc/D_001D1028.refs"
u32 D_001D1028[] DATA_SECTION(D_001D1028) = {
#include "data_inc/D_001D1028.inc"
};

#include "data_inc/D_001D10E8.refs"
u32 D_001D10E8[] DATA_SECTION(D_001D10E8) = {
#include "data_inc/D_001D10E8.inc"
};

#include "data_inc/D_001D1150.refs"
u32 D_001D1150[] DATA_SECTION(D_001D1150) = {
#include "data_inc/D_001D1150.inc"
};

#include "data_inc/D_001D11A8.refs"
u32 D_001D11A8[] DATA_SECTION(D_001D11A8) = {
#include "data_inc/D_001D11A8.inc"
};

#include "data_inc/D_001D1268.refs"
u32 D_001D1268[] DATA_SECTION(D_001D1268) = {
#include "data_inc/D_001D1268.inc"
};

#include "data_inc/D_001D13B0.refs"
u32 D_001D13B0[] DATA_SECTION(D_001D13B0) = {
#include "data_inc/D_001D13B0.inc"
};

#include "data_inc/D_001D1470.refs"
u32 D_001D1470[] DATA_SECTION(D_001D1470) = {
#include "data_inc/D_001D1470.inc"
};

#include "data_inc/D_001D14D8.refs"
u32 D_001D14D8[] DATA_SECTION(D_001D14D8) = {
#include "data_inc/D_001D14D8.inc"
};

#include "data_inc/D_001D1530.refs"
u32 D_001D1530[] DATA_SECTION(D_001D1530) = {
#include "data_inc/D_001D1530.inc"
};

#include "data_inc/D_001D1610.refs"
u32 D_001D1610[] DATA_SECTION(D_001D1610) = {
#include "data_inc/D_001D1610.inc"
};

#include "data_inc/D_001D1690.refs"
u32 D_001D1690[] DATA_SECTION(D_001D1690) = {
#include "data_inc/D_001D1690.inc"
};

#include "data_inc/D_001D1758.refs"
u32 D_001D1758[] DATA_SECTION(D_001D1758) = {
#include "data_inc/D_001D1758.inc"
};

u32 D_001D17B0[] DATA_SECTION(D_001D17B0) = {
#include "data_inc/D_001D17B0.inc"
};

void *D_001D17D8[] DATA_SECTION(D_001D17D8) = {
    update_menu_option_list, DrawCheatsMenu, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, D_001D17B0, 0, 0,
};

#include "data_inc/D_001D18A0.refs"
u32 D_001D18A0[] DATA_SECTION(D_001D18A0) = {
#include "data_inc/D_001D18A0.inc"
};

void *D_001D18F8[] DATA_SECTION(D_001D18F8) = {
    sound_options_menu, DrawSoundMenu, 0, set_pause_sound_volume, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

#include "data_inc/D_001D1A58.refs"
u32 D_001D1A58[] DATA_SECTION(D_001D1A58) = {
#include "data_inc/D_001D1A58.inc"
};

#include "data_inc/D_001D1AB0.refs"
u32 D_001D1AB0[] DATA_SECTION(D_001D1AB0) = {
#include "data_inc/D_001D1AB0.inc"
};

void *D_001D1B08[] DATA_SECTION(D_001D1B08) = {
    0, draw_menu_selection_text, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

void *D_001D1B60[] DATA_SECTION(D_001D1B60) = {
    saving_data_menu,
    draw_save_slot_list,
    enter_save_slot_screen,
    leave_save_slot_screen,
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
};

void *D_001D1BB0[] DATA_SECTION(D_001D1BB0) = {
    loading_data_menu,
    draw_save_slot_list,
    enter_save_slot_screen,
    leave_save_slot_screen,
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
};

void *D_001D1C28[] DATA_SECTION(D_001D1C28) = {
    0, render_localized_ui_entry_list, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, (char *)D_4000 + 0x2, D_001D1C00, 0, 0, 0, 0, 0, 0,
};

#include "data_inc/D_001D1C78.refs"
u32 D_001D1C78[] DATA_SECTION(D_001D1C78) = {
#include "data_inc/D_001D1C78.inc"
};

#include "data_inc/D_001D1D68.refs"
u32 D_001D1D68[] DATA_SECTION(D_001D1D68) = {
#include "data_inc/D_001D1D68.inc"
};

u32 D_001D1DC0[] DATA_SECTION(D_001D1DC0) = {
#include "data_inc/D_001D1DC0.inc"
};

void *D_001D1E20[] DATA_SECTION(D_001D1E20) = {
    update_menu_choice_list,
    draw_menu_choice_list,
    enter_menu_choice_list,
    leave_menu_choice_list,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    D_001D1DC0,
    0,
    0,
};

void *D_001D1EE8[] DATA_SECTION(D_001D1EE8) = {
    Menu_BackInput, DrawQuitGameMenu, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

#include "data_inc/D_001D1FC0.refs"
u32 D_001D1FC0[] DATA_SECTION(D_001D1FC0) = {
#include "data_inc/D_001D1FC0.inc"
};

#include "data_inc/D_001D2018.refs"
u32 D_001D2018[] DATA_SECTION(D_001D2018) = {
#include "data_inc/D_001D2018.inc"
};

#include "data_inc/D_001D2080.refs"
u32 D_001D2080[] DATA_SECTION(D_001D2080) = {
#include "data_inc/D_001D2080.inc"
};

#include "data_inc/D_001D20E0.refs"
u32 D_001D20E0[] DATA_SECTION(D_001D20E0) = {
#include "data_inc/D_001D20E0.inc"
};

#include "data_inc/D_001D2148.refs"
u32 D_001D2148[] DATA_SECTION(D_001D2148) = {
#include "data_inc/D_001D2148.inc"
};

#include "data_inc/D_001D2230.refs"
u32 D_001D2230[] DATA_SECTION(D_001D2230) = {
#include "data_inc/D_001D2230.inc"
};

#include "data_inc/D_001D22B0.refs"
u32 D_001D22B0[] DATA_SECTION(D_001D22B0) = {
#include "data_inc/D_001D22B0.inc"
};

#include "data_inc/D_001D2390.refs"
u32 D_001D2390[] DATA_SECTION(D_001D2390) = {
#include "data_inc/D_001D2390.inc"
};

#include "data_inc/D_001D23F8.refs"
u32 D_001D23F8[] DATA_SECTION(D_001D23F8) = {
#include "data_inc/D_001D23F8.inc"
};

#include "data_inc/D_001D2538.refs"
u32 D_001D2538[] DATA_SECTION(D_001D2538) = {
#include "data_inc/D_001D2538.inc"
};

void *D_001D25E0[] DATA_SECTION(D_001D25E0) = {
    update_level_selection_map_screen, draw_level_selection_map_screen, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

#include "data_inc/D_001D2610.refs"
u32 D_001D2610[] DATA_SECTION(D_001D2610) = {
#include "data_inc/D_001D2610.inc"
};

#include "data_inc/D_001D2700.refs"
u32 D_001D2700[] DATA_SECTION(D_001D2700) = {
#include "data_inc/D_001D2700.inc"
};

void *D_001D2750[] DATA_SECTION(D_001D2750) = {
    update_menu_mission_list,
    MissionMenu_DrawObjectives,
    enter_menu_mission_list,
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
};

#include "data_inc/D_001D27D0.refs"
u32 D_001D27D0[] DATA_SECTION(D_001D27D0) = {
#include "data_inc/D_001D27D0.inc"
};

#include "data_inc/D_001D2838.refs"
u32 D_001D2838[] DATA_SECTION(D_001D2838) = {
#include "data_inc/D_001D2838.inc"
};

void *D_001D2980[] DATA_SECTION(D_001D2980) = {
    0, draw_save_slot_list, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

void *D_001D29D0[] DATA_SECTION(D_001D29D0) = {
    Menu_ConfirmPromptInput,
    draw_prompt_box,
    enter_menu_prompt,
    leave_menu_prompt,
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
    0,
    0,
};

void *D_001D2A50[] DATA_SECTION(D_001D2A50) = {
    0, render_localized_ui_entry_list, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, (char *)D_4000 + 0x2, D_001D2A28, 0, 0, 0, 0, 0, 0,
};

#include "data_inc/D_001D2AA0.refs"
u32 D_001D2AA0[] DATA_SECTION(D_001D2AA0) = {
#include "data_inc/D_001D2AA0.inc"
};

#include "data_inc/D_001D2B28.refs"
u32 D_001D2B28[] DATA_SECTION(D_001D2B28) = {
#include "data_inc/D_001D2B28.inc"
};

#include "data_inc/D_001D2C20.refs"
u32 D_001D2C20[] DATA_SECTION(D_001D2C20) = {
#include "data_inc/D_001D2C20.inc"
};

#include "data_inc/D_001D2C78.refs"
u32 D_001D2C78[] DATA_SECTION(D_001D2C78) = {
#include "data_inc/D_001D2C78.inc"
};

#include "data_inc/D_001D2CC8.refs"
u32 D_001D2CC8[] DATA_SECTION(D_001D2CC8) = {
#include "data_inc/D_001D2CC8.inc"
};

#include "data_inc/D_001D2E40.refs"
u32 D_001D2E40[] DATA_SECTION(D_001D2E40) = {
#include "data_inc/D_001D2E40.inc"
};

#include "data_inc/D_001D2E98.refs"
u32 D_001D2E98[] DATA_SECTION(D_001D2E98) = {
#include "data_inc/D_001D2E98.inc"
};

#include "data_inc/D_001D2EF0.refs"
u32 D_001D2EF0[] DATA_SECTION(D_001D2EF0) = {
#include "data_inc/D_001D2EF0.inc"
};

#include "data_inc/D_001D2F58.refs"
u32 D_001D2F58[] DATA_SECTION(D_001D2F58) = {
#include "data_inc/D_001D2F58.inc"
};

#include "data_inc/D_001D2FC0.refs"
u32 D_001D2FC0[] DATA_SECTION(D_001D2FC0) = {
#include "data_inc/D_001D2FC0.inc"
};

#include "data_inc/D_001D3048.refs"
u32 D_001D3048[] DATA_SECTION(D_001D3048) = {
#include "data_inc/D_001D3048.inc"
};

void *D_001D30A0[] DATA_SECTION(D_001D30A0) = {
    0, draw_selected_menu_item_text, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

#include "data_inc/D_001D30F8.refs"
u32 D_001D30F8[] DATA_SECTION(D_001D30F8) = {
#include "data_inc/D_001D30F8.inc"
};

u32 D_001D3160[] DATA_SECTION(D_001D3160) = {
#include "data_inc/D_001D3160.inc"
};

u32 D_001D32D8[] DATA_SECTION(D_001D32D8) = {
#include "data_inc/D_001D32D8.inc"
};

#include "data_inc/D_001D33C8.refs"
u32 D_001D33C8[] DATA_SECTION(D_001D33C8) = {
#include "data_inc/D_001D33C8.inc"
};

#include "data_inc/D_001D3420.refs"
u32 D_001D3420[] DATA_SECTION(D_001D3420) = {
#include "data_inc/D_001D3420.inc"
};

#include "data_inc/D_001D3470.refs"
u32 D_001D3470[] DATA_SECTION(D_001D3470) = {
#include "data_inc/D_001D3470.inc"
};

#include "data_inc/D_001D34F8.refs"
u32 D_001D34F8[] DATA_SECTION(D_001D34F8) = {
#include "data_inc/D_001D34F8.inc"
};

u32 D_001D35B8[] DATA_SECTION(D_001D35B8) = {
#include "data_inc/D_001D35B8.inc"
};

#include "data_inc/D_001D35E0.refs"
u32 D_001D35E0[] DATA_SECTION(D_001D35E0) = {
#include "data_inc/D_001D35E0.inc"
};

void *D_001D36E0[] DATA_SECTION(D_001D36E0) = {
    process_global_state_flags, DrawEndScreenMenuMaybe, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

#include "data_inc/D_001D3738.refs"
u32 D_001D3738[] DATA_SECTION(D_001D3738) = {
#include "data_inc/D_001D3738.inc"
};

void *D_001D37C0[] DATA_SECTION(D_001D37C0) = {
    0, draw_menu_side_indicator, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

#include "data_inc/D_001D3818.refs"
u32 D_001D3818[] DATA_SECTION(D_001D3818) = {
#include "data_inc/D_001D3818.inc"
};

u32 D_001D386C DATA_SECTION(D_001D386C) = 0;

#include "data_inc/D_001D3870.refs"
u32 D_001D3870[] DATA_SECTION(D_001D3870) = {
#include "data_inc/D_001D3870.inc"
};

#include "data_inc/D_001D38D8.refs"
u32 D_001D38D8[] DATA_SECTION(D_001D38D8) = {
#include "data_inc/D_001D38D8.inc"
};

#include "data_inc/D_001D3960.refs"
u32 D_001D3960[] DATA_SECTION(D_001D3960) = {
#include "data_inc/D_001D3960.inc"
};

#include "data_inc/D_001D39C8.refs"
u32 D_001D39C8[] DATA_SECTION(D_001D39C8) = {
#include "data_inc/D_001D39C8.inc"
};

u32 D_001D3A20[] DATA_SECTION(D_001D3A20) = {
#include "data_inc/D_001D3A20.inc"
};

void *D_001D3A50[] DATA_SECTION(D_001D3A50) = {
    handle_cyclic_menu_selection_input,
    render_localized_ui_entry_list,
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
    (char *)D_4000 + 0x2,
    D_001D3A20,
    0,
    0,
    0,
    0,
    0,
    0,
};

#include "data_inc/D_001D3B18.refs"
u32 D_001D3B18[] DATA_SECTION(D_001D3B18) = {
#include "data_inc/D_001D3B18.inc"
};

#include "data_inc/D_001D3B70.refs"
u32 D_001D3B70[] DATA_SECTION(D_001D3B70) = {
#include "data_inc/D_001D3B70.inc"
};

#include "data_inc/D_001D3BF8.refs"
u32 D_001D3BF8[] DATA_SECTION(D_001D3BF8) = {
#include "data_inc/D_001D3BF8.inc"
};

#include "data_inc/D_001D3C80.refs"
u32 D_001D3C80[] DATA_SECTION(D_001D3C80) = {
#include "data_inc/D_001D3C80.inc"
};

#include "data_inc/D_001D3CD0.refs"
u32 D_001D3CD0[] DATA_SECTION(D_001D3CD0) = {
#include "data_inc/D_001D3CD0.inc"
};

u32 D_001D3D38[] DATA_SECTION(D_001D3D38) = {
#include "data_inc/D_001D3D38.inc"
};

void *D_001D3D60[] DATA_SECTION(D_001D3D60) = {
    Pause_PageInput,
    render_localized_ui_entry_list,
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
    (char *)D_4000 + 0x2,
    D_001D3D38,
    0,
    0,
    0,
    0,
    0,
    0,
};

#include "data_inc/D_001D3DB0.refs"
u32 D_001D3DB0[] DATA_SECTION(D_001D3DB0) = {
#include "data_inc/D_001D3DB0.inc"
};

#include "data_inc/D_001D3E38.refs"
u32 D_001D3E38[] DATA_SECTION(D_001D3E38) = {
#include "data_inc/D_001D3E38.inc"
};

#include "data_inc/D_001D3F98.refs"
u32 D_001D3F98[] DATA_SECTION(D_001D3F98) = {
#include "data_inc/D_001D3F98.inc"
};

u32 D_001D3FD8[] DATA_SECTION(D_001D3FD8) = {
#include "data_inc/D_001D3FD8.inc"
};

void *D_001D4000[] DATA_SECTION(D_001D4000) = {
    Pause_PageInput,
    render_localized_ui_entry_list,
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
    (char *)D_4000 + 0x2,
    D_001D3FD8,
    0,
    0,
    0,
    0,
    0,
    0,
};

#include "data_inc/D_001D4050.refs"
u32 D_001D4050[] DATA_SECTION(D_001D4050) = {
#include "data_inc/D_001D4050.inc"
};

#include "data_inc/D_001D40D8.refs"
u32 D_001D40D8[] DATA_SECTION(D_001D40D8) = {
#include "data_inc/D_001D40D8.inc"
};

u32 D_001D4130[] DATA_SECTION(D_001D4130) = {
#include "data_inc/D_001D4130.inc"
};

void *D_001D4158[] DATA_SECTION(D_001D4158) = {
    Pause_PageInput,
    render_localized_ui_entry_list,
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
    (char *)D_4000 + 0x2,
    D_001D4130,
    0,
    0,
    0,
    0,
    0,
    0,
};

u32 D_001D41A8[] DATA_SECTION(D_001D41A8) = {
#include "data_inc/D_001D41A8.inc"
};

#include "data_inc/D_001D4310.refs"
u32 D_001D4310[] DATA_SECTION(D_001D4310) = {
#include "data_inc/D_001D4310.inc"
};

#include "data_inc/D_001D4360.refs"
u32 D_001D4360[] DATA_SECTION(D_001D4360) = {
#include "data_inc/D_001D4360.inc"
};

#include "data_inc/D_001D43E8.refs"
u32 D_001D43E8[] DATA_SECTION(D_001D43E8) = {
#include "data_inc/D_001D43E8.inc"
};

u32 D_001D4440[] DATA_SECTION(D_001D4440) = {
#include "data_inc/D_001D4440.inc"
};

u32 D_001D4470[] DATA_SECTION(D_001D4470) = {
#include "data_inc/D_001D4470.inc"
};

u32 D_001D44C8[] DATA_SECTION(D_001D44C8) = {
#include "data_inc/D_001D44C8.inc"
};

#include "data_inc/D_001D4508.refs"
u32 D_001D4508[] DATA_SECTION(D_001D4508) = {
#include "data_inc/D_001D4508.inc"
};

u32 D_001D4568[] DATA_SECTION(D_001D4568) = {
#include "data_inc/D_001D4568.inc"
};

u32 D_001D4590[] DATA_SECTION(D_001D4590) = {
#include "data_inc/D_001D4590.inc"
};

u32 D_001D45D8[] DATA_SECTION(D_001D45D8) = {
#include "data_inc/D_001D45D8.inc"
};

u32 D_001D4600[] DATA_SECTION(D_001D4600) = {
#include "data_inc/D_001D4600.inc"
};

u32 D_001D4640[] DATA_SECTION(D_001D4640) = {
#include "data_inc/D_001D4640.inc"
};

u32 D_001D46A0[] DATA_SECTION(D_001D46A0) = {
#include "data_inc/D_001D46A0.inc"
};

u32 D_001D46C8[] DATA_SECTION(D_001D46C8) = {
#include "data_inc/D_001D46C8.inc"
};

u32 D_001D4720[] DATA_SECTION(D_001D4720) = {
#include "data_inc/D_001D4720.inc"
};

u32 D_001D4760[] DATA_SECTION(D_001D4760) = {
#include "data_inc/D_001D4760.inc"
};

u32 D_001D47A0[] DATA_SECTION(D_001D47A0) = {
#include "data_inc/D_001D47A0.inc"
};

u32 D_001D47E8[] DATA_SECTION(D_001D47E8) = {
#include "data_inc/D_001D47E8.inc"
};

u32 D_001D4830[] DATA_SECTION(D_001D4830) = {
#include "data_inc/D_001D4830.inc"
};

u32 D_001D4860[] DATA_SECTION(D_001D4860) = {
#include "data_inc/D_001D4860.inc"
};

#include "data_inc/D_001D48F8.refs"
u32 D_001D48F8[] DATA_SECTION(D_001D48F8) = {
#include "data_inc/D_001D48F8.inc"
};

#include "data_inc/D_001D4948.refs"
struct MenuPage pause_menu_start_page DATA_SECTION(D_001D4948) = {
#include "data_inc/D_001D4948.inc"
};

#include "data_inc/D_001D49D0.refs"
u32 D_001D49D0[] DATA_SECTION(D_001D49D0) = {
#include "data_inc/D_001D49D0.inc"
};

#include "data_inc/D_001D49E8.refs"
u32 D_001D49E8[] DATA_SECTION(D_001D49E8) = {
#include "data_inc/D_001D49E8.inc"
};

#include "data_inc/D_001D4A00.refs"
u32 D_001D4A00[] DATA_SECTION(D_001D4A00) = {
#include "data_inc/D_001D4A00.inc"
};

#include "data_inc/D_001D4A18.refs"
u32 D_001D4A18[] DATA_SECTION(D_001D4A18) = {
#include "data_inc/D_001D4A18.inc"
};

#include "data_inc/D_001D4A68.refs"
u32 D_001D4A68[] DATA_SECTION(D_001D4A68) = {
#include "data_inc/D_001D4A68.inc"
};

#include "data_inc/D_001D4AB8.refs"
u32 D_001D4AB8[] DATA_SECTION(D_001D4AB8) = {
#include "data_inc/D_001D4AB8.inc"
};

#include "data_inc/D_001D4B08.refs"
u32 D_001D4B08[] DATA_SECTION(D_001D4B08) = {
#include "data_inc/D_001D4B08.inc"
};

void *D_001D4BE8[] DATA_SECTION(D_001D4BE8) = {
    update_menu_entry_actions,
    render_localized_ui_entry_list,
    set_pause_action_list,
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
    0,
};

#include "data_inc/D_001D4C38.refs"
u32 D_001D4C38[] DATA_SECTION(D_001D4C38) = {
#include "data_inc/D_001D4C38.inc"
};

#include "data_inc/D_001D4CC0.refs"
u32 D_001D4CC0[] DATA_SECTION(D_001D4CC0) = {
#include "data_inc/D_001D4CC0.inc"
};

#include "data_inc/D_001D4D48.refs"
u32 D_001D4D48[] DATA_SECTION(D_001D4D48) = {
#include "data_inc/D_001D4D48.inc"
};

#include "data_inc/D_001D4DE8.refs"
u32 D_001D4DE8[] DATA_SECTION(D_001D4DE8) = {
#include "data_inc/D_001D4DE8.inc"
};

#include "data_inc/D_001D4E38.refs"
u32 D_001D4E38[] DATA_SECTION(D_001D4E38) = {
#include "data_inc/D_001D4E38.inc"
};

#include "data_inc/D_001D4EC0.refs"
u32 D_001D4EC0[] DATA_SECTION(D_001D4EC0) = {
#include "data_inc/D_001D4EC0.inc"
};

void *D_001D4F40[] DATA_SECTION(D_001D4F40) = {
    update_menu_option_list, DrawCheatsMenu, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, D_001D4F18, 0, 0,
};

#include "data_inc/D_001D4F80.refs"
u32 D_001D4F80[] DATA_SECTION(D_001D4F80) = {
#include "data_inc/D_001D4F80.inc"
};

#include "data_inc/D_001D5008.refs"
u32 D_001D5008[] DATA_SECTION(D_001D5008) = {
#include "data_inc/D_001D5008.inc"
};

#include "data_inc/D_001D5090.refs"
u32 D_001D5090[] DATA_SECTION(D_001D5090) = {
#include "data_inc/D_001D5090.inc"
};

void *D_001D50E8[] DATA_SECTION(D_001D50E8) = {
    saving_data_menu2,
    draw_save_slot_list,
    enter_save_slot_screen,
    leave_save_slot_screen,
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
};

void *D_001D5168[] DATA_SECTION(D_001D5168) = {
    0, render_localized_ui_entry_list, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, (char *)D_4000 + 0x2, D_001D5138, 0, 0, 0, 0, 0, 0,
};

#include "data_inc/D_001D52C8.refs"
u32 D_001D52C8[] DATA_SECTION(D_001D52C8) = {
#include "data_inc/D_001D52C8.inc"
};

#include "data_inc/D_001D5D58.refs"
u32 preview_resource_bindings[] DATA_SECTION(D_001D5D58) = {
#include "data_inc/D_001D5D58.inc"
};

u32 preserved_item_available_indices[] DATA_SECTION(D_001D5F20) = {
#include "data_inc/D_001D5F20.inc"
};

u32 pause_current_action_list[42] DATA_SECTION(D_001D5F78) = {0};

u32 preview_resource_ids[22] DATA_SECTION(D_001D60C8) = {0};

u32 preview_request_address_base[2] DATA_SECTION(D_001D6218) = {0};

u32 current_preview_animation_request[3] DATA_SECTION(D_001D6410) = {0};

u32 shrub_render_classes[64] DATA_SECTION(D_001D82C0) = {0};

u8 shrub_render_class_slot_by_id[1024] DATA_SECTION(D_001D8440) = {0};

u32 shrub_render_texture_addrs[256] DATA_SECTION(D_001D8840) = {0};

u32 shrub_scratchpad_copy[256] DATA_SECTION(D_001D9240) = {0};

float resident_effect_quad_uvs[] DATA_SECTION(D_001D9C20) = {
#include "data_inc/D_001D9C20.inc"
};

float resident_effect_quad_offsets[] DATA_SECTION(D_001D9C40) = {
#include "data_inc/D_001D9C40.inc"
};

float resident_effect_quad_offsets_variant1[] DATA_SECTION(D_001D9CC0) = {
#include "data_inc/D_001D9CC0.inc"
};

float resident_effect_quad_offsets_variant2[] DATA_SECTION(D_001D9CE0) = {
#include "data_inc/D_001D9CE0.inc"
};

u32 resident_effect_quad_corners[] DATA_SECTION(D_001D9D00) = {
#include "data_inc/D_001D9D00.inc"
};

u32 space_ship_trail_emitter_offsets[] DATA_SECTION(D_001D9D40) = {
#include "data_inc/D_001D9D40.inc"
};

float warp_texture_coordinates[] DATA_SECTION(D_001D9DA0) = {
#include "data_inc/D_001D9DA0.inc"
};

u32 space_ship_companion_a_offset[] DATA_SECTION(D_001DA010) = {
#include "data_inc/D_001DA010.inc"
};

u32 space_ship_companion_b_offset[] DATA_SECTION(D_001DA040) = {
#include "data_inc/D_001DA040.inc"
};

u32 D_001DA070[] DATA_SECTION(D_001DA070) = {
#include "data_inc/D_001DA070.inc"
};

#include "data_inc/D_001DA6D0.refs"
u32 D_001DA6D0[] DATA_SECTION(D_001DA6D0) = {
#include "data_inc/D_001DA6D0.inc"
};

u32 D_001DAB70[] DATA_SECTION(D_001DAB70) = {
#include "data_inc/D_001DAB70.inc"
};

u32 D_001DB1D0[] DATA_SECTION(D_001DB1D0) = {
#include "data_inc/D_001DB1D0.inc"
};

#include "data_inc/D_001DB440.refs"
u32 D_001DB440[] DATA_SECTION(D_001DB440) = {
#include "data_inc/D_001DB440.inc"
};

u32 D_001DB5C0[] DATA_SECTION(D_001DB5C0) = {
#include "data_inc/D_001DB5C0.inc"
};

u32 D_001DB830[] DATA_SECTION(D_001DB830) = {
#include "data_inc/D_001DB830.inc"
};

#include "data_inc/D_001DBB40.refs"
u32 D_001DBB40[] DATA_SECTION(D_001DBB40) = {
#include "data_inc/D_001DBB40.inc"
};

u32 D_001DBE40[] DATA_SECTION(D_001DBE40) = {
#include "data_inc/D_001DBE40.inc"
};

u32 D_001DC150[] DATA_SECTION(D_001DC150) = {
#include "data_inc/D_001DC150.inc"
};

u32 D_001DC5D0[] DATA_SECTION(D_001DC5D0) = {
#include "data_inc/D_001DC5D0.inc"
};

u32 D_001DE0CC DATA_SECTION(D_001DE0CC) =
#include "data_inc/D_001DE0CC.inc"
    ;

u32 D_001DE0D0[] DATA_SECTION(D_001DE0D0) = {
#include "data_inc/D_001DE0D0.inc"
};

u32 D_001DE6A0[] DATA_SECTION(D_001DE6A0) = {
#include "data_inc/D_001DE6A0.inc"
};

u32 D_001DE6C0[] DATA_SECTION(D_001DE6C0) = {
#include "data_inc/D_001DE6C0.inc"
};

#include "data_inc/D_001DE700.refs"
u32 D_001DE700[] DATA_SECTION(D_001DE700) = {
#include "data_inc/D_001DE700.inc"
};

u32 D_001DE990[] DATA_SECTION(D_001DE990) = {
#include "data_inc/D_001DE990.inc"
};

u32 D_001DEA20[] DATA_SECTION(D_001DEA20) = {
#include "data_inc/D_001DEA20.inc"
};

u32 D_001DEB20[] DATA_SECTION(D_001DEB20) = {
#include "data_inc/D_001DEB20.inc"
};

u32 D_001DEC00[] DATA_SECTION(D_001DEC00) = {
#include "data_inc/D_001DEC00.inc"
};

#include "data_inc/D_001DEC40.refs"
u32 D_001DEC40[] DATA_SECTION(D_001DEC40) = {
#include "data_inc/D_001DEC40.inc"
};

#include "data_inc/D_001DECA0.refs"
u32 D_001DECA0[] DATA_SECTION(D_001DECA0) = {
#include "data_inc/D_001DECA0.inc"
};

u32 D_001DEE00[] DATA_SECTION(D_001DEE00) = {
#include "data_inc/D_001DEE00.inc"
};

u32 D_001DEE30[] DATA_SECTION(D_001DEE30) = {
#include "data_inc/D_001DEE30.inc"
};

u32 D_001DEE60[] DATA_SECTION(D_001DEE60) = {
#include "data_inc/D_001DEE60.inc"
};

#include "data_inc/D_001DEE90.refs"
u32 D_001DEE90[] DATA_SECTION(D_001DEE90) = {
#include "data_inc/D_001DEE90.inc"
};

u32 D_001DEF30[] DATA_SECTION(D_001DEF30) = {
#include "data_inc/D_001DEF30.inc"
};

u32 D_001DEFB0[] DATA_SECTION(D_001DEFB0) = {
#include "data_inc/D_001DEFB0.inc"
};

u32 D_001DF140[] DATA_SECTION(D_001DF140) = {
#include "data_inc/D_001DF140.inc"
};

u32 D_001DF1B0[128] DATA_SECTION(D_001DF1B0) = {0};

u32 normal_font_metrics[] DATA_SECTION(D_001DF3D0) = {
#include "data_inc/D_001DF3D0.inc"
};

u32 small_font_metrics[] DATA_SECTION(D_001DF770) = {
#include "data_inc/D_001DF770.inc"
};

u32 large_font_metrics[] DATA_SECTION(D_001DFB10) = {
#include "data_inc/D_001DFB10.inc"
};

u32 D_001E0000[] DATA_SECTION(D_001E0000) = {
#include "data_inc/D_001E0000.inc"
};

u32 D_001E00F0[] DATA_SECTION(D_001E00F0) = {
#include "data_inc/D_001E00F0.inc"
};

u32 D_001E01F0[] DATA_SECTION(D_001E01F0) = {
#include "data_inc/D_001E01F0.inc"
};

u32 D_001E0220[] DATA_SECTION(D_001E0220) = {
#include "data_inc/D_001E0220.inc"
};

u32 D_001E0280[] DATA_SECTION(D_001E0280) = {
#include "data_inc/D_001E0280.inc"
};

u16 vendor_item_prices[] DATA_SECTION(D_001E02B0) = {
#include "data_inc/D_001E02B0.inc"
};

u32 tfrag_texture_size_table[192] DATA_SECTION(D_001E0C00) = {0};

u32 tfrag_dma_block[256] DATA_SECTION(D_001E1600) = {0};

u32 object_render_classes[128] DATA_SECTION(D_001E1A00) = {0};

u8 object_render_class_slot_by_id[3072] DATA_SECTION(D_001E1D00) = {0};

u32 object_render_texture_addrs[256] DATA_SECTION(D_001E2900) = {0};

u32 tie_light_data[256] DATA_SECTION(D_001E3500) = {0};

u32 vendor_state[9] DATA_SECTION(D_001E66C0) = {0};

char str_loading_sound_bank[] DATA_SECTION(D_001E79C0) =
#include "data_inc/D_001E79C0.inc"
    ;

char D_001E8450[] DATA_SECTION(D_001E8450) =
#include "data_inc/D_001E8450.inc"
    ;

char D_001E8468[] DATA_SECTION(D_001E8468) =
#include "data_inc/D_001E8468.inc"
    ;

char D_001E84E8[] DATA_SECTION(D_001E84E8) =
#include "data_inc/D_001E84E8.inc"
    ;

u32 language_resource_offsets[] DATA_SECTION(D_001E8B00) = {
#include "data_inc/D_001E8B00.inc"
};
