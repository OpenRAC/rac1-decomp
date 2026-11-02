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
extern u32 D_0018A400[];
extern u32 D_0018CB40[];
extern void map_filter_l04_0();
extern void map_filter_l04_1();
extern void map_filter_l04_2();
extern void map_filter_l04_3();
extern void map_filter_l06_0();
extern void map_filter_l07_0();
extern void map_filter_l07_1();
extern void map_filter_l07_2();
extern void map_filter_l07_3();
extern void map_filter_l07_4();
extern void map_filter_l07_5();
extern void map_filter_l07_6();
extern void map_filter_l07_7();
extern void map_filter_l08_0();
extern void map_filter_l08_1();
extern void map_filter_l08_2();
extern void map_filter_l08_3();
extern void map_filter_l08_4();
extern void map_filter_l08_5();
extern void map_filter_l08_6();
extern void map_filter_l08_7();
extern void map_filter_l09_0();
extern void map_filter_l09_1();
extern void map_filter_l09_2();
extern void map_filter_l10_0();
extern void map_filter_l10_1();
extern void map_filter_l10_2();
extern void map_filter_l10_3();
extern void map_filter_l10_4();
extern void map_filter_l10_5();
extern void map_filter_l11_0();
extern void map_filter_l11_1();
extern void map_filter_l11_2();
extern void map_filter_l11_3();
extern void map_filter_l11_4();
extern void map_filter_l11_5();
extern void map_filter_l12_0();
extern void MenuL12_IsAlwaysActive1();
extern void map_filter_l12_2();
extern void map_filter_l15_0();
extern void map_filter_l16_0();
extern void map_filter_l16_1();
extern void map_filter_l16_2();
extern void map_filter_l16_3();
extern void map_filter_l18_0();
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
extern u32 D_001D1C00[];
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
extern u32 D_001D2A28[];
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
extern u32 D_001D4F18[];
extern void saving_data_menu2();
extern u32 D_001D5138[];

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

u32 snd_sync_buffer[16] DATA_SECTION(D_00133200) = {0};

u8 snd_sync_send_buffer[320] DATA_SECTION(D_00133240) = {0};

u8 disc_table[10440] DATA_SECTION(D_00137C80) = {0};

u32 pad_globals_base[] DATA_SECTION(D_0013A5E0) = {
#include "data_inc/D_0013A5E0.inc"
};

u32 D_00152300[] DATA_SECTION(D_00152300) = {
#include "data_inc/D_00152300.inc"
};

u8 dtoa_infinity_string[] DATA_SECTION(D_00152410) = {
#include "data_inc/D_00152410.inc"
};

u8 dtoa_nan_string[] DATA_SECTION(D_00152420) = {
#include "data_inc/D_00152420.inc"
};

u32 dtoa_zero_string[] DATA_SECTION(D_00152428) = {
#include "data_inc/D_00152428.inc"
};

u32 D_00152468[] DATA_SECTION(D_00152468) = {
#include "data_inc/D_00152468.inc"
};

#include "data_inc/D_00152470.refs"
u32 locale_lconv[] DATA_SECTION(D_00152470) = {
#include "data_inc/D_00152470.inc"
};

u32 D_001524A0[2] DATA_SECTION(D_001524A0) = {0};

u32 D_001524A8[] DATA_SECTION(D_001524A8) = {
#include "data_inc/D_001524A8.inc"
};

u32 pow5mult_p05[] DATA_SECTION(D_001524B8) = {
#include "data_inc/D_001524B8.inc"
};

u32 __mprec_tens[] DATA_SECTION(D_001524C8) = {
#include "data_inc/D_001524C8.inc"
};

u32 __mprec_bigtens[] DATA_SECTION(D_00152590) = {
#include "data_inc/D_00152590.inc"
};

u32 __mprec_bigtens_4[] DATA_SECTION(D_001525B0) = {
#include "data_inc/D_001525B0.inc"
};

u32 vfprintf_blanks_pad[] DATA_SECTION(D_001525E0) = {
#include "data_inc/D_001525E0.inc"
};

u32 vfprintf_zeroes_pad[] DATA_SECTION(D_001525F0) = {
#include "data_inc/D_001525F0.inc"
};

u32 vfprintf_inf_str[] DATA_SECTION(D_00152600) = {
#include "data_inc/D_00152600.inc"
};

u32 vfprintf_nan_str[] DATA_SECTION(D_00152608) = {
#include "data_inc/D_00152608.inc"
};

u32 vfprintf_hex_digits_lower[] DATA_SECTION(D_00152610) = {
#include "data_inc/D_00152610.inc"
};

char vfprintf_null_str[] DATA_SECTION(D_00152628) =
#include "data_inc/D_00152628.inc"
    ;

u32 vfprintf_hex_digits_upper[] DATA_SECTION(D_00152630) = {
#include "data_inc/D_00152630.inc"
};

u32 vfprintf_bad_base_msg[] DATA_SECTION(D_00152648) = {
#include "data_inc/D_00152648.inc"
};

u32 vfprintf_zero_char[] DATA_SECTION(D_00152668) = {
#include "data_inc/D_00152668.inc"
};

u32 vfprintf_dot_char[] DATA_SECTION(D_00152670) = {
#include "data_inc/D_00152670.inc"
};

u32 D_001527E4 DATA_SECTION(D_001527E4) =
#include "data_inc/D_001527E4.inc"
    ;

u32 top_thread_bad_request_message[] DATA_SECTION(D_001527E8) = {
#include "data_inc/D_001527E8.inc"
};

char tty_packet_too_large_msg[] DATA_SECTION(D_00152810) =
#include "data_inc/D_00152810.inc"
    ;

u32 tty_receive_error_msg[] DATA_SECTION(D_00152838) = {
#include "data_inc/D_00152838.inc"
};

u32 tty_send_error_msg[] DATA_SECTION(D_00152850) = {
#include "data_inc/D_00152850.inc"
};

char tty_wlen_error_msg[] DATA_SECTION(D_00152868) =
#include "data_inc/D_00152868.inc"
    ;

u32 D_00152A48[] DATA_SECTION(D_00152A48) = {
#include "data_inc/D_00152A48.inc"
};

u32 D_00152A50[] DATA_SECTION(D_00152A50) = {
#include "data_inc/D_00152A50.inc"
};

u32 iop_reboot_udnl_prefix[] DATA_SECTION(D_00152A60) = {
#include "data_inc/D_00152A60.inc"
};

u32 iop_reboot_param_too_long_msg[] DATA_SECTION(D_00152A70) = {
#include "data_inc/D_00152A70.inc"
};

char D_00152A90[] DATA_SECTION(D_00152A90) =
#include "data_inc/D_00152A90.inc"
    ;

u32 D_00152AC8[] DATA_SECTION(D_00152AC8) = {
#include "data_inc/D_00152AC8.inc"
};

u32 D_00152AE0[] DATA_SECTION(D_00152AE0) = {
#include "data_inc/D_00152AE0.inc"
};

u32 D_00152AF8[] DATA_SECTION(D_00152AF8) = {
#include "data_inc/D_00152AF8.inc"
};

u32 D_00152F18[] DATA_SECTION(D_00152F18) = {
#include "data_inc/D_00152F18.inc"
};

char cd_ncmd_sema_fail_msg[] DATA_SECTION(D_00152FB0) =
#include "data_inc/D_00152FB0.inc"
    ;

char cd_ncmd_bind_error_msg[] DATA_SECTION(D_00152FD8) =
#include "data_inc/D_00152FD8.inc"
    ;

u32 cd_ncmd_wait_msg[] DATA_SECTION(D_00152FF0) = {
#include "data_inc/D_00152FF0.inc"
};

u32 cd_scmd_wait_msg[] DATA_SECTION(D_00153000) = {
#include "data_inc/D_00153000.inc"
};

char cd_scmd_sema_fail_msg[] DATA_SECTION(D_00153010) =
#include "data_inc/D_00153010.inc"
    ;

char cd_scmd_bind_error_msg[] DATA_SECTION(D_00153038) =
#include "data_inc/D_00153038.inc"
    ;

char cd_bind_error_fmt[] DATA_SECTION(D_00153050) =
#include "data_inc/D_00153050.inc"
    ;

char cd_exit_message[] DATA_SECTION(D_00153070) =
#include "data_inc/D_00153070.inc"
    ;

char cd_disk_ready_start_msg[] DATA_SECTION(D_00153080) =
#include "data_inc/D_00153080.inc"
    ;

char cd_disk_ready_bind_error_msg[] DATA_SECTION(D_00153090) =
#include "data_inc/D_00153090.inc"
    ;

u32 cd_disk_ready_end_msg[] DATA_SECTION(D_001530B0) = {
#include "data_inc/D_001530B0.inc"
};

u32 cd_read_call_msg[] DATA_SECTION(D_001530C8) = {
#include "data_inc/D_001530C8.inc"
};

u32 cd_read_end_msg[] DATA_SECTION(D_001530E0) = {
#include "data_inc/D_001530E0.inc"
};

u32 cd_read_clock_msg_1[] DATA_SECTION(D_001530F0) = {
#include "data_inc/D_001530F0.inc"
};

u32 cd_read_clock_msg_2[] DATA_SECTION(D_00153110) = {
#include "data_inc/D_00153110.inc"
};

u32 romver_path[] DATA_SECTION(D_00153130) = {
#include "data_inc/D_00153130.inc"
};

u32 gs_def_disp_env_mode_error_msg[] DATA_SECTION(D_00153140) = {
#include "data_inc/D_00153140.inc"
};

u32 gs_put_draw_env_dma_timeout_msg[] DATA_SECTION(D_00153178) = {
#include "data_inc/D_00153178.inc"
};

u32 gs_load_image_too_big_msg[] DATA_SECTION(D_001531B0) = {
#include "data_inc/D_001531B0.inc"
};

u32 D_001532CC DATA_SECTION(D_001532CC) =
#include "data_inc/D_001532CC.inc"
    ;

u32 gs_exec_load_image_dma_timeout_msg[] DATA_SECTION(D_001532D0) = {
#include "data_inc/D_001532D0.inc"
};

u32 gs_store_image_dma1_timeout_msg[] DATA_SECTION(D_00153310) = {
#include "data_inc/D_00153310.inc"
};

char gs_store_image_gs_timeout_msg[] DATA_SECTION(D_00153348) =
#include "data_inc/D_00153348.inc"
    ;

char gs_store_image_readback_timeout_msg[] DATA_SECTION(D_00153378) =
#include "data_inc/D_00153378.inc"
    ;

char gs_store_image_vif1_short_msg[] DATA_SECTION(D_001533B8) =
#include "data_inc/D_001533B8.inc"
    ;

u32 D_001534DC DATA_SECTION(D_001534DC) =
#include "data_inc/D_001534DC.inc"
    ;

char dma_sync_timeout_msg[] DATA_SECTION(D_001534E0) =
#include "data_inc/D_001534E0.inc"
    ;

u32 DmaChannelsUsed[] DATA_SECTION(D_001534F8) = {
#include "data_inc/D_001534F8.inc"
};

u8 dma_sts_channel_codes[] DATA_SECTION(D_00153520) = {
#include "data_inc/D_00153520.inc"
};

u8 dma_std_channel_codes[] DATA_SECTION(D_00153530) = {
#include "data_inc/D_00153530.inc"
};

u8 dma_mfd_channel_codes[] DATA_SECTION(D_00153540) = {
#include "data_inc/D_00153540.inc"
};

u32 str_mc_bind_error[] DATA_SECTION(D_00153550) = {
#include "data_inc/D_00153550.inc"
};

char str_mc_old_mcserv[] DATA_SECTION(D_00153568) =
#include "data_inc/D_00153568.inc"
    ;

u32 str_mc_old_mcman[] DATA_SECTION(D_00153590) = {
#include "data_inc/D_00153590.inc"
};

u32 str_dbc_bind_failed[] DATA_SECTION(D_001535D8) = {
#include "data_inc/D_001535D8.inc"
};

u32 str_dbc_version_mismatch[] DATA_SECTION(D_001535F0) = {
#include "data_inc/D_001535F0.inc"
};

char str_dbc_version_pair_fmt[] DATA_SECTION(D_00153618) =
#include "data_inc/D_00153618.inc"
    ;

u32 str_dbc_sif_dma_addr_fmt[] DATA_SECTION(D_00153640) = {
#include "data_inc/D_00153640.inc"
};

char str_dbc_set_work_addr_error[] DATA_SECTION(D_00153658) =
#include "data_inc/D_00153658.inc"
    ;

u32 str_dbc_create_socket_error[] DATA_SECTION(D_00153678) = {
#include "data_inc/D_00153678.inc"
};

u32 str_dbc_get_dep_number_error[] DATA_SECTION(D_001536B8) = {
#include "data_inc/D_001536B8.inc"
};

u32 str_dbc_receive_data_error[] DATA_SECTION(D_001537A0) = {
#include "data_inc/D_001537A0.inc"
};

char D_001537C0[] DATA_SECTION(D_001537C0) =
#include "data_inc/D_001537C0.inc"
    ;

char D_001537C8[] DATA_SECTION(D_001537C8) =
#include "data_inc/D_001537C8.inc"
    ;

char D_001537D0[] DATA_SECTION(D_001537D0) =
#include "data_inc/D_001537D0.inc"
    ;

u32 D_001537D8[] DATA_SECTION(D_001537D8) = {
#include "data_inc/D_001537D8.inc"
};

u32 str_mpeg_invalid_motion_type[] DATA_SECTION(D_001537E8) = {
#include "data_inc/D_001537E8.inc"
};

char str_mpeg_invalid_motion_type_a[] DATA_SECTION(D_00153810) =
#include "data_inc/D_00153810.inc"
    ;

char str_mpeg_invalid_motion_type_b[] DATA_SECTION(D_00153830) =
#include "data_inc/D_00153830.inc"
    ;

char str_mpeg_invalid_motion_type_c[] DATA_SECTION(D_00153850) =
#include "data_inc/D_00153850.inc"
    ;

u32 str_mpeg_intra_skip_mb[] DATA_SECTION(D_00153870) = {
#include "data_inc/D_00153870.inc"
};

u32 str_mpeg_bdec_error[] DATA_SECTION(D_00153888) = {
#include "data_inc/D_00153888.inc"
};

u32 str_mpeg_invalid_mb_addr_inc[] DATA_SECTION(D_001538A8) = {
#include "data_inc/D_001538A8.inc"
};

char str_mpeg_skip_to_next_picture[] DATA_SECTION(D_001538E0) =
#include "data_inc/D_001538E0.inc"
    ;

char str_mpeg_slice_start_code_range[] DATA_SECTION(D_00153900) =
#include "data_inc/D_00153900.inc"
    ;

u32 str_mpeg_slice_a0_error[] DATA_SECTION(D_00153928) = {
#include "data_inc/D_00153928.inc"
};

char str_mpeg_too_many_macroblocks[] DATA_SECTION(D_00153948) =
#include "data_inc/D_00153948.inc"
    ;

char str_mpeg_skipped_mb_in_i_picture[] DATA_SECTION(D_00153968) =
#include "data_inc/D_00153968.inc"
    ;

char str_mpeg_invalid_mb_type[] DATA_SECTION(D_00153998) =
#include "data_inc/D_00153998.inc"
    ;

char str_mpeg_load_chroma_intra_qm[] DATA_SECTION(D_001539E8) =
#include "data_inc/D_001539E8.inc"
    ;

u32 str_mpeg_load_chroma_non_intra_qm[] DATA_SECTION(D_00153A10) = {
#include "data_inc/D_00153A10.inc"
};

char str_mpeg_odd_field_pictures[] DATA_SECTION(D_00153A40) =
#include "data_inc/D_00153A40.inc"
    ;

u32 str_mpeg_unknown_picture_structure[] DATA_SECTION(D_00153A60) = {
#include "data_inc/D_00153A60.inc"
};

u32 str_mpeg_buffer_too_small_fmt[] DATA_SECTION(D_00153A80) = {
#include "data_inc/D_00153A80.inc"
};

u32 csc_handler_error_msg[] DATA_SECTION(D_00153AB0) = {
#include "data_inc/D_00153AB0.inc"
};

u32 pes_optional_field_bits[] DATA_SECTION(D_00153AC8) = {
#include "data_inc/D_00153AC8.inc"
};

u32 pes_pack_header_field_flag_msg[] DATA_SECTION(D_00153AD8) = {
#include "data_inc/D_00153AD8.inc"
};

u32 mpeg_create_work_area_too_small_msg[] DATA_SECTION(D_00153B10) = {
#include "data_inc/D_00153B10.inc"
};

u32 mpeg_work_area_size_too_small_msg[] DATA_SECTION(D_00153B38) = {
#include "data_inc/D_00153B38.inc"
};

u32 mpeg_image_buffer_unaligned_msg[] DATA_SECTION(D_00153B58) = {
#include "data_inc/D_00153B58.inc"
};

u32 D_00153BB4 DATA_SECTION(D_00153BB4) =
#include "data_inc/D_00153BB4.inc"
    ;

u32 mpeg_second_field_missing_msg[] DATA_SECTION(D_00153BB8) = {
#include "data_inc/D_00153BB8.inc"
};

char mpeg_error_format[] DATA_SECTION(D_00153BD8) =
#include "data_inc/D_00153BD8.inc"
    ;

char mpeg_vertical_size_too_large_msg[] DATA_SECTION(D_00153BE8) =
#include "data_inc/D_00153BE8.inc"
    ;

u32 mpeg_chroma_format_not_420_msg[] DATA_SECTION(D_00153C00) = {
#include "data_inc/D_00153C00.inc"
};

u32 mpeg_unsupported_profile_level_msg[] DATA_SECTION(D_00153C28) = {
#include "data_inc/D_00153C28.inc"
};

char mpeg_sequence_scalable_ext_msg[] DATA_SECTION(D_00153C48) =
#include "data_inc/D_00153C48.inc"
    ;

u32 mpeg_unknown_extension_msg[] DATA_SECTION(D_00153C78) = {
#include "data_inc/D_00153C78.inc"
};

u32 mpeg_picture_spatial_scalable_ext_msg[] DATA_SECTION(D_00153C90) = {
#include "data_inc/D_00153C90.inc"
};

u32 mpeg_picture_temporal_scalable_ext_msg[] DATA_SECTION(D_00153CC8) = {
#include "data_inc/D_00153CC8.inc"
};

u32 scf_romver_path[] DATA_SECTION(D_00153D00) = {
#include "data_inc/D_00153D00.inc"
};

char scf_romver_open_failed_msg[] DATA_SECTION(D_00153D10) =
#include "data_inc/D_00153D10.inc"
    ;

char scf_romver_read_failed_msg[] DATA_SECTION(D_00153D28) =
#include "data_inc/D_00153D28.inc"
    ;

u32 MonthLengths[] DATA_SECTION(D_00153D40) = {
#include "data_inc/D_00153D40.inc"
};

u32 snd_sif_bind_rpc_error_string[] DATA_SECTION(D_00153D50) = {
#include "data_inc/D_00153D50.inc"
};

u32 snd_989_snd_source_file[] DATA_SECTION(D_00153D78) = {
#include "data_inc/D_00153D78.inc"
};

u32 snd_no_return_error_string[] DATA_SECTION(D_00153D98) = {
#include "data_inc/D_00153D98.inc"
};

u32 snd_non_idle_error_string[] DATA_SECTION(D_00153E20) = {
#include "data_inc/D_00153E20.inc"
};

char snd_bank_load_by_loc_progress_string[] DATA_SECTION(D_00153EA8) =
#include "data_inc/D_00153EA8.inc"
    ;

char snd_bank_load_by_loc_cd_busy_string[] DATA_SECTION(D_00153ED8) =
#include "data_inc/D_00153ED8.inc"
    ;

u32 snd_bank_load_by_loc_rpc_error_string[] DATA_SECTION(D_00153EF8) = {
#include "data_inc/D_00153EF8.inc"
};

u32 snd_bank_load_from_ee_progress_string[] DATA_SECTION(D_00153FC0) = {
#include "data_inc/D_00153FC0.inc"
};

u32 snd_bank_load_from_ee_cd_busy_string[] DATA_SECTION(D_00153FF8) = {
#include "data_inc/D_00153FF8.inc"
};

char snd_send_iop_command_buffer_full_string[] DATA_SECTION(D_00154110) =
#include "data_inc/D_00154110.inc"
    ;

u32 snd_no_wait_continuing_string[] DATA_SECTION(D_00154170) = {
#include "data_inc/D_00154170.inc"
};

#include "data_inc/D_0015ED80.refs"
u32 snd_current_buffer[] DATA_SECTION(D_0015ED80) = {
#include "data_inc/D_0015ED80.inc"
};

u32 snd_cd_callback_data[10] DATA_SECTION(D_0015EDD8) = {0};

u32 snd_cd_callback_arg[16] DATA_SECTION(D_0015EE00) = {0};

u32 frm_clock_time[2] DATA_SECTION(D_0015EE40) = {0};

u32 frm_vsync_cnt[4] DATA_SECTION(D_0015EE48) = {0};

u8 cd_read_spindle_speed[] DATA_SECTION(D_0015EE58) = {
#include "data_inc/D_0015EE58.inc"
};

u32 sound_bank_handle DATA_SECTION(D_0015EE5C) = 0;

float frame_scale DATA_SECTION(D_0015EE60) =
#include "data_inc/D_0015EE60.inc"
    ;

float g_frame_scale_sq DATA_SECTION(D_0015EE64) =
#include "data_inc/D_0015EE64.inc"
    ;

float inv_frame_scale DATA_SECTION(D_0015EE68) =
#include "data_inc/D_0015EE68.inc"
    ;

float g_frame_time DATA_SECTION(D_0015EE6C) =
#include "data_inc/D_0015EE6C.inc"
    ;

float g_frame_time_sq DATA_SECTION(D_0015EE70) =
#include "data_inc/D_0015EE70.inc"
    ;

float g_frame_time_cube DATA_SECTION(D_0015EE74) =
#include "data_inc/D_0015EE74.inc"
    ;

u32 frame_scale_fifths DATA_SECTION(D_0015EE78) =
#include "data_inc/D_0015EE78.inc"
    ;

float frame_delta_time DATA_SECTION(D_0015EE7C) =
#include "data_inc/D_0015EE7C.inc"
    ;

u32 pal_mode DATA_SECTION(D_0015EE80) = 0;

u32 g_current_level_index DATA_SECTION(D_0015EE84) = 0;

u32 g_game_language[] DATA_SECTION(D_0015EE88) = {
#include "data_inc/D_0015EE88.inc"
};

u32 gBolts[2] DATA_SECTION(D_0015EE98) = {0};

u32 hero_max_health[] DATA_SECTION(D_0015EEA0) = {
#include "data_inc/D_0015EEA0.inc"
};

u32 gCheats[4] DATA_SECTION(D_0015EEB0) = {0};

u8 selector_available[16] DATA_SECTION(D_0015EEC0) = {0};

u32 vendor_stock[] DATA_SECTION(D_0015EED0) = {
#include "data_inc/D_0015EED0.inc"
};

u32 playback_mode DATA_SECTION(D_0015EEE8) =
#include "data_inc/D_0015EEE8.inc"
    ;

u32 music_volume DATA_SECTION(D_0015EEEC) =
#include "data_inc/D_0015EEEC.inc"
    ;

u32 sound_volume[] DATA_SECTION(D_0015EEF0) = {
#include "data_inc/D_0015EEF0.inc"
};

u32 D_0015EF20[4] DATA_SECTION(D_0015EF20) = {0};

u32 active_message_record_count DATA_SECTION(D_0015EF30) =
#include "data_inc/D_0015EF30.inc"
    ;

u32 memcard_selected_slot DATA_SECTION(D_0015EF34) = 0;

u32 rilgar_hoverboard_races_finished DATA_SECTION(D_0015EF38) = 0;

u32 kalebo3_hoverboard_races_finished DATA_SECTION(D_0015EF3C) = 0;

u8 subtitles_enabled[8] DATA_SECTION(D_0015EF40) = {0};

u16 level_archive_load_state DATA_SECTION(D_0015EF48) = 0;

u16 level_archive_load_busy DATA_SECTION(D_0015EF4A) = 0;

u32 level_root DATA_SECTION(D_0015EF4C) = 0;

u32 sound_archive_base DATA_SECTION(D_0015EF50) = 0;

u32 level_archive_base DATA_SECTION(D_0015EF54) = 0;

u32 race_best_times[4] DATA_SECTION(D_0015EF58) = {0};

u32 race_best_records[3] DATA_SECTION(D_0015EF68) = {0};

u32 g_gs_texture_allocation_cursor DATA_SECTION(D_0015EF74) = 0;

u32 g_gs_texture_allocation_start[2] DATA_SECTION(D_0015EF78) = {0};

u32 display_buffer_address DATA_SECTION(D_0015EF80) = 0;

u32 draw_buffer_address DATA_SECTION(D_0015EF84) = 0;

u32 depth_buffer_address DATA_SECTION(D_0015EF88) = 0;

u32 g_gs_texture_allocation_base DATA_SECTION(D_0015EF8C) = 0;

u32 pause_action_list_mode[2] DATA_SECTION(D_0015EF90) = {0};

u32 save_clock_time[2] DATA_SECTION(D_0015EF98) = {0};

u32 challenge_mode[4] DATA_SECTION(D_0015EFA0) = {0};

u32 mode_freeze_state DATA_SECTION(D_0015EFB0) = 0;

u32 mode_freeze_flags DATA_SECTION(D_0015EFB4) = 0;

u32 active_fs_aa_buffer DATA_SECTION(D_0015EFB8) = 0;

u32 cd_read_wait_frames DATA_SECTION(D_0015EFBC) = 0;

u32 cd_read_slowdown_applied[2] DATA_SECTION(D_0015EFC0) = {0};

u32 debug_font_pif_header[2] DATA_SECTION(D_0015EFC8) = {0};

u32 capture_texture_tex0[2] DATA_SECTION(D_0015EFD0) = {0};

u32 decode_mode[10] DATA_SECTION(D_0015EFD8) = {0};

u32 D_0015F000[] DATA_SECTION(D_0015F000) = {
#include "data_inc/D_0015F000.inc"
};

u32 texture_alloc_counter[] DATA_SECTION(D_0015F020) = {
#include "data_inc/D_0015F020.inc"
};

u32 intro_overlay_alpha DATA_SECTION(D_0015F050) = 0;

u32 language_intro_overlay_alpha DATA_SECTION(D_0015F054) = 0;

u32 intro_overlay_timer[2] DATA_SECTION(D_0015F058) = {0};

u32 help_msg_data[] DATA_SECTION(D_0015F060) = {
#include "data_inc/D_0015F060.inc"
};

u32 cam_post_upd_routine_cnt DATA_SECTION(D_0015F08C) = 0;

u32 gCameraDefs[3] DATA_SECTION(D_0015F090) = {0};

u32 cam_coll_flag DATA_SECTION(D_0015F09C) = 0;

void *cam_coll_flag_prev[] DATA_SECTION(D_0015F0A0) = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, D_0018A400, 0,
};

u32 font_text_format[] DATA_SECTION(D_0015F108) = {
#include "data_inc/D_0015F108.inc"
};

u32 camera_sample_path_format[] DATA_SECTION(D_0015F120) = {
#include "data_inc/D_0015F120.inc"
};

u32 camera_sample_path_suffix[] DATA_SECTION(D_0015F130) = {
#include "data_inc/D_0015F130.inc"
};

u32 camera_sample_bin_name[] DATA_SECTION(D_0015F138) = {
#include "data_inc/D_0015F138.inc"
};

void *screen_tint_quad_enabled[] DATA_SECTION(D_0015F430) = {
    0, 0, 0, 0, 0, 0, 0, 0, D_0018CB40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

char profile_mark_frame_start[] DATA_SECTION(D_0015F480) =
#include "data_inc/D_0015F480.inc"
    ;

u32 profile_mark_after_sky[] DATA_SECTION(D_0015F490) = {
#include "data_inc/D_0015F490.inc"
};

u32 profile_mark_after_ties[] DATA_SECTION(D_0015F4A0) = {
#include "data_inc/D_0015F4A0.inc"
};

u32 profile_mark_after_mobys[] DATA_SECTION(D_0015F4B0) = {
#include "data_inc/D_0015F4B0.inc"
};

char profile_mark_after_lights[] DATA_SECTION(D_0015F4C0) =
#include "data_inc/D_0015F4C0.inc"
    ;

u32 profile_mark_after_particles[] DATA_SECTION(D_0015F4D0) = {
#include "data_inc/D_0015F4D0.inc"
};

char profile_mark_after_sprites[] DATA_SECTION(D_0015F4E0) =
#include "data_inc/D_0015F4E0.inc"
    ;

char profile_mark_after_blur[] DATA_SECTION(D_0015F4F0) =
#include "data_inc/D_0015F4F0.inc"
    ;

u32 profile_mark_after_hud[] DATA_SECTION(D_0015F4F8) = {
#include "data_inc/D_0015F4F8.inc"
};

char profile_mark_after_fades[] DATA_SECTION(D_0015F500) =
#include "data_inc/D_0015F500.inc"
    ;

u32 profile_mark_vu1_sync[2] DATA_SECTION(D_0015F510) = {0};

char profile_mark_tie_lighting[] DATA_SECTION(D_0015F518) =
#include "data_inc/D_0015F518.inc"
    ;

char profile_mark_moby_patch[] DATA_SECTION(D_0015F528) =
#include "data_inc/D_0015F528.inc"
    ;

u32 draw_enable_mask DATA_SECTION(D_0015F534) = 0;

u32 game_frame_counter DATA_SECTION(D_0015F538) = 0;

float gFade DATA_SECTION(D_0015F53C) = 0;

float white_fade_level DATA_SECTION(D_0015F540) = 0;

u32 letterbox_enabled DATA_SECTION(D_0015F544) = 0;

u32 letterbox_bar_height[2] DATA_SECTION(D_0015F548) = {0};

u32 gif_paging_head_tag DATA_SECTION(D_0015F550) = 0;

u32 gif_paging_tail_tag DATA_SECTION(D_0015F554) = 0;

u32 pending_texture_upload_count DATA_SECTION(D_0015F558) = 0;

u32 effect_tex_cnt DATA_SECTION(D_0015F55C) = 0;

u32 level_texture_payload_address DATA_SECTION(D_0015F560) = 0;

u32 draw_callback_count DATA_SECTION(D_0015F564) = 0;

u32 draw_callback2_count DATA_SECTION(D_0015F568) = 0;

u32 draw_callback3_count DATA_SECTION(D_0015F56C) = 0;

u32 draw_callback4_count DATA_SECTION(D_0015F570) = 0;

u32 effect_quad_count DATA_SECTION(D_0015F574) = 0;

u32 font_quad_count DATA_SECTION(D_0015F578) = 0;

u32 D_0015F57C DATA_SECTION(D_0015F57C) = 0;

u32 D_0015F580[2] DATA_SECTION(D_0015F580) = {0};

float fog_near_distance DATA_SECTION(D_0015F588) = 0;

float fog_far_distance DATA_SECTION(D_0015F58C) = 0;

float fog_near_intensity DATA_SECTION(D_0015F590) = 0;

float fog_far_intensity DATA_SECTION(D_0015F594) = 0;

u32 level_fog_mode DATA_SECTION(D_0015F598) = 0;

u32 GlobalStateFlag DATA_SECTION(D_0015F59C) = 0;

u32 font_window_active[] DATA_SECTION(D_0015F5A0) = {
#include "data_inc/D_0015F5A0.inc"
};

u32 freeze_prompt_default_text[2] DATA_SECTION(D_0015F648) = {0};

u32 freeze_prompt_number_format[] DATA_SECTION(D_0015F650) = {
#include "data_inc/D_0015F650.inc"
};

char freeze_rank_line_format[] DATA_SECTION(D_0015F660) =
#include "data_inc/D_0015F660.inc"
    ;

u32 freeze_text_line_format[] DATA_SECTION(D_0015F668) = {
#include "data_inc/D_0015F668.inc"
};

char freeze_race_time_format[] DATA_SECTION(D_0015F670) =
#include "data_inc/D_0015F670.inc"
    ;

u32 freeze_record_value_format[] DATA_SECTION(D_0015F680) = {
#include "data_inc/D_0015F680.inc"
};

u32 space_load_pending DATA_SECTION(D_0015F690) = 0;

u32 bank_sound_count DATA_SECTION(D_0015F694) =
#include "data_inc/D_0015F694.inc"
    ;

u32 vu1_chain_reserved_bytes[] DATA_SECTION(D_0015F698) = {
#include "data_inc/D_0015F698.inc"
};

u32 help_message_keepalive[] DATA_SECTION(D_0015F6B0) = {
#include "data_inc/D_0015F6B0.inc"
};

u32 boot_level_active DATA_SECTION(D_0015F6C8) = 0;

u32 pause_restart_reset_flag DATA_SECTION(D_0015F6CC) = 0;

u32 counter_advance_disabled[5] DATA_SECTION(D_0015F6D0) = {0};

u32 space_load_level DATA_SECTION(D_0015F6E4) = 0;

u32 g_game_mode[2] DATA_SECTION(D_0015F6E8) = {0};

u32 world_update_time[8] DATA_SECTION(D_0015F6F0) = {0};

u32 level_sound_def_count DATA_SECTION(D_0015F710) = 0;

u32 level_sound_defs DATA_SECTION(D_0015F714) = 0;

u32 render_packet_end DATA_SECTION(D_0015F718) = 0;

u32 vu1_chain_safe_end DATA_SECTION(D_0015F71C) = 0;

u32 occl_grid_data DATA_SECTION(D_0015F720) = 0;

u32 occl_oct DATA_SECTION(D_0015F724) = 0;

u32 occl_fallback_mode DATA_SECTION(D_0015F728) = 0;

u32 occl_invalid_grid DATA_SECTION(D_0015F72C) = 0;

u32 occl_previous_grid[12] DATA_SECTION(D_0015F730) = {0};

u32 hud_msg_count DATA_SECTION(D_0015F760) = 0;

u32 hud_msg_alpha DATA_SECTION(D_0015F764) = 0;

u32 hud_msg_y[] DATA_SECTION(D_0015F768) = {
#include "data_inc/D_0015F768.inc"
};

#include "data_inc/D_0015F780.refs"
u32 help_msgs[] DATA_SECTION(D_0015F780) = {
#include "data_inc/D_0015F780.inc"
};

u32 hud_file_str[] DATA_SECTION(D_0015F7B8) = {
#include "data_inc/D_0015F7B8.inc"
};

u32 hud_bank_main[2] DATA_SECTION(D_0015FAB8) = {0};

u32 hud_bank_end[32] DATA_SECTION(D_0015FAC0) = {0};

u32 rebooted_iop_message[] DATA_SECTION(D_0015FB40) = {
#include "data_inc/D_0015FB40.inc"
};

u32 D_0015FB80[] DATA_SECTION(D_0015FB80) = {
#include "data_inc/D_0015FB80.inc"
};

u32 hud_bank_alloc_file[] DATA_SECTION(D_0015FC70) = {
#include "data_inc/D_0015FC70.inc"
};

u32 hud_bank1_stash_comment[] DATA_SECTION(D_0015FC80) = {
#include "data_inc/D_0015FC80.inc"
};

u32 hud_bank3_stash_comment[] DATA_SECTION(D_0015FC90) = {
#include "data_inc/D_0015FC90.inc"
};

u32 hud_bank4_stash_comment[] DATA_SECTION(D_0015FCA0) = {
#include "data_inc/D_0015FCA0.inc"
};

u32 hud_bank5_stash_comment[] DATA_SECTION(D_0015FCB0) = {
#include "data_inc/D_0015FCB0.inc"
};

u8 debug_mission_state_mirror[] DATA_SECTION(D_0015FCC8) = {
#include "data_inc/D_0015FCC8.inc"
};

u32 menu_item_price_fmt[] DATA_SECTION(D_0015FE60) = {
#include "data_inc/D_0015FE60.inc"
};

u32 menu_token_error_text[] DATA_SECTION(D_0015FE68) = {
#include "data_inc/D_0015FE68.inc"
};

char memcard_slot_file_prefix[] DATA_SECTION(D_0015FF58) =
#include "data_inc/D_0015FF58.inc"
    ;

char memcard_slot_file_suffix[] DATA_SECTION(D_0015FF60) =
#include "data_inc/D_0015FF60.inc"
    ;

char fmt_memcard_path[] DATA_SECTION(D_0015FF68) =
#include "data_inc/D_0015FF68.inc"
    ;

u32 str_memcard_deleting_file[] DATA_SECTION(D_0015FF70) = {
#include "data_inc/D_0015FF70.inc"
};

u32 graphics_setup_profile_label[] DATA_SECTION(D_0015FFC0) = {
#include "data_inc/D_0015FFC0.inc"
};

u32 draw_mobys_profile_label[] DATA_SECTION(D_0015FFD0) = {
#include "data_inc/D_0015FFD0.inc"
};

u32 moby_texture_dma_profile_label[] DATA_SECTION(D_0015FFE0) = {
#include "data_inc/D_0015FFE0.inc"
};

char draw_mobys_cleanup_profile_label[] DATA_SECTION(D_0015FFF0) =
#include "data_inc/D_0015FFF0.inc"
    ;

u32 num_spawnable_mobys DATA_SECTION(D_0015FFFC) = 0;

u32 resident_moby_class_count[2] DATA_SECTION(D_00160000) = {0};

u32 resident_indexed_texture_count[3] DATA_SECTION(D_00160008) = {0};

u32 moby_anim_head DATA_SECTION(D_00160014) = 0;

u32 resident_object_pool DATA_SECTION(D_00160018) = 0;

u32 moby_instance_end DATA_SECTION(D_0016001C) = 0;

u32 moby_instance_perm_end[2] DATA_SECTION(D_00160020) = {0};

u32 g_moby_vars[2] DATA_SECTION(D_00160028) = {0};

u32 occl_fog_count[2] DATA_SECTION(D_00160030) = {0};

u32 moby_word_fill_table_bytes DATA_SECTION(D_00160038) = 0;

u32 graphics_setup_dma_chain_enabled DATA_SECTION(D_0016003C) = 0;

u32 graphics_setup_tag_slot DATA_SECTION(D_00160040) = 0;

u32 runtime_resource_tag DATA_SECTION(D_00160044) = 0;

u32 class_resource_count DATA_SECTION(D_00160048) = 0;

u32 active_class_resource_index DATA_SECTION(D_0016004C) = 0;

u32 active_decode_buffer[] DATA_SECTION(D_00160050) = {
#include "data_inc/D_00160050.inc"
};

u32 quat_next_axis_table[] DATA_SECTION(D_001600D8) = {
#include "data_inc/D_001600D8.inc"
};

u32 sound_handle_in_use_message[] DATA_SECTION(D_00160168) = {
#include "data_inc/D_00160168.inc"
};

u32 menu_entry_find_token[] DATA_SECTION(D_00160188) = {
#include "data_inc/D_00160188.inc"
};

u32 menu_time_value_format[] DATA_SECTION(D_00160190) = {
#include "data_inc/D_00160190.inc"
};

u32 part_instance_pool DATA_SECTION(D_001601AC) = 0;

u32 part_slot_search_start[3] DATA_SECTION(D_001601B0) = {0};

u32 part_clip_dist DATA_SECTION(D_001601BC) = 0;

u32 particle_texture_range_count[] DATA_SECTION(D_001601C0) = {
#include "data_inc/D_001601C0.inc"
};

#include "data_inc/D_001602E0.refs"
u32 menu_level_indices[] DATA_SECTION(D_001602E0) = {
#include "data_inc/D_001602E0.inc"
};

char str_default[] DATA_SECTION(D_00160370) =
#include "data_inc/D_00160370.inc"
    ;

u32 str_empty_menu_label[2] DATA_SECTION(D_00160378) = {0};

char fmt_two_strings[] DATA_SECTION(D_00160380) =
#include "data_inc/D_00160380.inc"
    ;

u32 str_null_text[] DATA_SECTION(D_00160388) = {
#include "data_inc/D_00160388.inc"
};

u32 fmt_decimal[] DATA_SECTION(D_001603A0) = {
#include "data_inc/D_001603A0.inc"
};

u32 fmt_gold_bolt_count_line[] DATA_SECTION(D_001603A8) = {
#include "data_inc/D_001603A8.inc"
};

u32 fmt_ammo_have[] DATA_SECTION(D_001603B8) = {
#include "data_inc/D_001603B8.inc"
};

u32 fmt_ammo_have_thousands[] DATA_SECTION(D_001603C0) = {
#include "data_inc/D_001603C0.inc"
};

u32 fmt_number_thousands[] DATA_SECTION(D_001603D0) = {
#include "data_inc/D_001603D0.inc"
};

u32 pause_ring_left_glyph[] DATA_SECTION(D_001603D8) = {
#include "data_inc/D_001603D8.inc"
};

u32 pause_ring_right_glyph[] DATA_SECTION(D_001603E0) = {
#include "data_inc/D_001603E0.inc"
};

char str_error_text[] DATA_SECTION(D_001603E8) =
#include "data_inc/D_001603E8.inc"
    ;

u8 menu_side_indicator_left_glyph[] DATA_SECTION(D_001603F0) = {
#include "data_inc/D_001603F0.inc"
};

u8 menu_side_indicator_right_glyph[] DATA_SECTION(D_001603F8) = {
#include "data_inc/D_001603F8.inc"
};

u32 fmt_save_play_time[] DATA_SECTION(D_00160400) = {
#include "data_inc/D_00160400.inc"
};

char fmt_save_bolt_count[] DATA_SECTION(D_00160410) =
#include "data_inc/D_00160410.inc"
    ;

u32 fmt_save_date[] DATA_SECTION(D_00160420) = {
#include "data_inc/D_00160420.inc"
};

u32 preview_animation_request_count[] DATA_SECTION(D_00160450) = {
#include "data_inc/D_00160450.inc"
};

float direction_unit DATA_SECTION(D_00160470) = 0;

float direction_unit_y DATA_SECTION(D_00160474) = 0;

float direction_unit_z[2] DATA_SECTION(D_00160478) = {0};

float direction_perpendicular DATA_SECTION(D_00160480) = 0;

float direction_perpendicular_y DATA_SECTION(D_00160484) = 0;

float direction_perpendicular_z[2] DATA_SECTION(D_00160488) = {0};

float direction_scaled DATA_SECTION(D_00160490) = 0;

float direction_scaled_y DATA_SECTION(D_00160494) = 0;

float direction_scaled_z[2] DATA_SECTION(D_00160498) = {0};

u32 graphics_setup_word[2] DATA_SECTION(D_001604A0) = {0};

u32 D_001604A8[2] DATA_SECTION(D_001604A8) = {0};

u32 str_shrub_texs[] DATA_SECTION(D_001604B0) = {
#include "data_inc/D_001604B0.inc"
};

char str_shrub_draw[] DATA_SECTION(D_001604C0) =
#include "data_inc/D_001604C0.inc"
    ;

u32 registered_shrub_render_class_count DATA_SECTION(D_001604CC) = 0;

u32 shrub_count DATA_SECTION(D_001604D0) = 0;

u32 shrubs DATA_SECTION(D_001604D4) = 0;

u32 shrubs_end DATA_SECTION(D_001604D8) = 0;

u32 shrub_data_table DATA_SECTION(D_001604DC) = 0;

u32 shrub_colors[3] DATA_SECTION(D_001604E0) = {0};

u32 shrub_render_texture_definition_count DATA_SECTION(D_001604EC) = 0;

u32 shrub_tex_dma_tag[2] DATA_SECTION(D_001604F0) = {0};

u32 max_shrub_texture_dma_size[] DATA_SECTION(D_001604F8) = {
#include "data_inc/D_001604F8.inc"
};

char str_sky_texs[] DATA_SECTION(D_00160550) =
#include "data_inc/D_00160550.inc"
    ;

u32 level_sky_effect_data DATA_SECTION(D_0016055C) = 0;

u32 sky_shell_translation[4] DATA_SECTION(D_00160560) = {0};

u32 sky_gif_paging_tag[6] DATA_SECTION(D_00160570) = {0};

#include "data_inc/D_00160588.refs"
u32 D_00160588[] DATA_SECTION(D_00160588) = {
#include "data_inc/D_00160588.inc"
};

u32 resident_quad_texture[2] DATA_SECTION(D_00160680) = {0};

#include "data_inc/D_00160688.refs"
u32 resident_banner_texture[] DATA_SECTION(D_00160688) = {
#include "data_inc/D_00160688.inc"
};

u32 view_depth_constants[] DATA_SECTION(D_00160820) = {
#include "data_inc/D_00160820.inc"
};

u32 rect_overlay_gif_regs_a[] DATA_SECTION(D_00160920) = {
#include "data_inc/D_00160920.inc"
};

u32 rect_overlay_gif_regs_b[] DATA_SECTION(D_00160930) = {
#include "data_inc/D_00160930.inc"
};

u32 textured_quad_header[] DATA_SECTION(D_00160940) = {
#include "data_inc/D_00160940.inc"
};

u32 textured_quad_giftag[] DATA_SECTION(D_00160950) = {
#include "data_inc/D_00160950.inc"
};

u32 textured_rect_gif_regs[] DATA_SECTION(D_00160960) = {
#include "data_inc/D_00160960.inc"
};

#include "data_inc/D_001609E0.refs"
u32 billboard_quad_header[] DATA_SECTION(D_001609E0) = {
#include "data_inc/D_001609E0.inc"
};

u32 shrub_color_dma_ref_tag[] DATA_SECTION(D_00160BB0) = {
#include "data_inc/D_00160BB0.inc"
};

u32 view_fog_multiplier[] DATA_SECTION(D_00160C30) = {
#include "data_inc/D_00160C30.inc"
};

u32 D_00160F00[] DATA_SECTION(D_00160F00) = {
#include "data_inc/D_00160F00.inc"
};

u32 D_00160F20[] DATA_SECTION(D_00160F20) = {
#include "data_inc/D_00160F20.inc"
};

u32 D_00160F40[] DATA_SECTION(D_00160F40) = {
#include "data_inc/D_00160F40.inc"
};

u32 str_tfrag_texs[] DATA_SECTION(D_00160F70) = {
#include "data_inc/D_00160F70.inc"
};

char str_tfrag_draw[] DATA_SECTION(D_00160F80) =
#include "data_inc/D_00160F80.inc"
    ;

u32 tfrag_render_records DATA_SECTION(D_00160F8C) = 0;

u32 tfrag_render_record_count[4] DATA_SECTION(D_00160F90) = {0};

float tfrag_render_ranges[4] DATA_SECTION(D_00160FA0) = {0};

u32 tfrag_lod_dists_raw[3] DATA_SECTION(D_00160FB0) = {0};

u32 tfrag_tex_dma_tag_slot DATA_SECTION(D_00160FBC) = 0;

u32 tfrag_draw_distance[4] DATA_SECTION(D_00160FC0) = {0};

u32 attachment_vertex_indices[] DATA_SECTION(D_00160FD0) = {
#include "data_inc/D_00160FD0.inc"
};

u32 vif_chain_flags[] DATA_SECTION(D_00160FE0) = {
#include "data_inc/D_00160FE0.inc"
};

u32 vu1_chain_buffers[2] DATA_SECTION(D_00160FF8) = {0};

u32 g_render_packet_cursor DATA_SECTION(D_00161000) = 0;

u32 previous_render_packet_cursor DATA_SECTION(D_00161004) = 0;

u32 vu1_chain_limit DATA_SECTION(D_00161008) = 0;

u32 current_vu_chain DATA_SECTION(D_0016100C) = 0;

u32 vu1_chain_buffer_index DATA_SECTION(D_00161010) = 0;

u32 vu1_chain_peak_bytes DATA_SECTION(D_00161014) = 0;

u32 vif1_dma_handler_id[] DATA_SECTION(D_00161018) = {
#include "data_inc/D_00161018.inc"
};

u32 str_tie_texs[] DATA_SECTION(D_00161030) = {
#include "data_inc/D_00161030.inc"
};

u32 str_tie_draw[] DATA_SECTION(D_00161040) = {
#include "data_inc/D_00161040.inc"
};

u32 registered_object_render_class_count DATA_SECTION(D_0016104C) = 0;

u32 ties DATA_SECTION(D_00161050) = 0;

u32 ties_end DATA_SECTION(D_00161054) = 0;

u32 tie_data_table[3] DATA_SECTION(D_00161058) = {0};

u32 object_render_texture_definition_count DATA_SECTION(D_00161064) = 0;

u32 tie_tex_dma_tag_slot[2] DATA_SECTION(D_00161068) = {0};

u32 tie_draw_distance[] DATA_SECTION(D_00161070) = {
#include "data_inc/D_00161070.inc"
};

char fmt_thousands_grouped_int[] DATA_SECTION(D_00161178) =
#include "data_inc/D_00161178.inc"
    ;

u32 fmt_plain_int[] DATA_SECTION(D_00161180) = {
#include "data_inc/D_00161180.inc"
};

u32 capture_moby_pass_enabled[2] DATA_SECTION(D_001611A8) = {0};

u32 resident_dialogue_started[] DATA_SECTION(D_001611B0) = {
#include "data_inc/D_001611B0.inc"
};

float water_fog_near_dist DATA_SECTION(D_001611C8) = 0;

float water_fog_far_dist DATA_SECTION(D_001611CC) =
#include "data_inc/D_001611CC.inc"
    ;

u32 water_fog_near_intensity[] DATA_SECTION(D_001611D0) = {
#include "data_inc/D_001611D0.inc"
};

u32 surface_height_tiles DATA_SECTION(D_00161290) = 0;

u32 occl_cell_table DATA_SECTION(D_00161294) = 0;

u32 occl_cell_count DATA_SECTION(D_00161298) = 0;

u32 local_surface_region_enabled DATA_SECTION(D_0016129C) = 0;

u32 local_surface_region_center_x[2] DATA_SECTION(D_001612A0) = {0};

float D_001612A8[14] DATA_SECTION(D_001612A8) = {0};

u32 movie_display_active DATA_SECTION(D_001612E0) = 0;

u32 movie_vblank_count DATA_SECTION(D_001612E4) = 0;

u32 image_buffer_count_decrement_pending DATA_SECTION(D_001612E8) = 0;

u32 D_001612EC DATA_SECTION(D_001612EC) = 0;

u32 D_001612F0[2] DATA_SECTION(D_001612F0) = {0};

char movie_error_message[] DATA_SECTION(D_001612F8) =
#include "data_inc/D_001612F8.inc"
    ;

u32 decoder_buffer_address DATA_SECTION(D_00161308) = 0;

u32 decoder_state DATA_SECTION(D_0016130C) = 0;

u32 movie_decoder_thread_id DATA_SECTION(D_00161310) = 0;

u32 movie_play_step DATA_SECTION(D_00161314) = 0;

u32 movie_frame_count[2] DATA_SECTION(D_00161318) = {0};

u32 mpeg_sequence_end_code[] DATA_SECTION(D_00161320) = {
#include "data_inc/D_00161320.inc"
};

u32 video_error_message[] DATA_SECTION(D_00161328) = {
#include "data_inc/D_00161328.inc"
};

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

u32 cam_trans_state[56] DATA_SECTION(D_001872B0) = {0};

u32 camera_rows[4] DATA_SECTION(D_00187390) = {0};

u32 effect_ribbon[68] DATA_SECTION(D_00187400) = {0};

u32 draw_config[6] DATA_SECTION(D_0018A3B0) = {0};

u32 D_0018A400[512] DATA_SECTION(D_0018A400) = {0};

u32 occl_cam_state[] DATA_SECTION(D_0018C418) = {
#include "data_inc/D_0018C418.inc"
};

u32 D_0018CB40[] DATA_SECTION(D_0018CB40) = {
#include "data_inc/D_0018CB40.inc"
};

u32 render_sequence[94] DATA_SECTION(D_0018CC20) = {0};

u32 view_context[44] DATA_SECTION(D_0018CE00) = {0};

float view_tan_half_fov[4] DATA_SECTION(D_0018CEB0) = {0};

u32 clip_transform[36] DATA_SECTION(D_0018CF80) = {0};

u32 D_0018E450[252] DATA_SECTION(D_0018E450) = {0};

u32 D_00190000[3328] DATA_SECTION(D_00190000) = {0};

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

u32 message_id_code_table[] DATA_SECTION(D_00199810) = {
#include "data_inc/D_00199810.inc"
};

u32 s_paradox_this_message_does_not[] DATA_SECTION(D_00199A68) = {
#include "data_inc/D_00199A68.inc"
};

u32 D_00199AD0[] DATA_SECTION(D_00199AD0) = {
#include "data_inc/D_00199AD0.inc"
};

u32 D_00199BB0[] DATA_SECTION(D_00199BB0) = {
#include "data_inc/D_00199BB0.inc"
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
    0,
    0,
    0,
    0,
    map_filter_l04_0,
    map_filter_l04_1,
    map_filter_l04_2,
    map_filter_l04_3,
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
    map_filter_l06_0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    map_filter_l07_0,
    map_filter_l07_1,
    map_filter_l07_2,
    map_filter_l07_3,
    map_filter_l07_4,
    map_filter_l07_5,
    map_filter_l07_6,
    map_filter_l07_7,
    map_filter_l08_0,
    map_filter_l08_1,
    map_filter_l08_2,
    map_filter_l08_3,
    map_filter_l08_4,
    map_filter_l08_5,
    map_filter_l08_6,
    map_filter_l08_7,
    map_filter_l09_0,
    map_filter_l09_1,
    map_filter_l09_2,
    0,
    0,
    0,
    0,
    0,
    map_filter_l10_0,
    map_filter_l10_1,
    map_filter_l10_2,
    map_filter_l10_3,
    map_filter_l10_4,
    map_filter_l10_5,
    0,
    0,
    map_filter_l11_0,
    map_filter_l11_1,
    map_filter_l11_2,
    map_filter_l11_3,
    map_filter_l11_4,
    map_filter_l11_5,
    0,
    0,
    map_filter_l12_0,
    MenuL12_IsAlwaysActive1,
    map_filter_l12_2,
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
    map_filter_l15_0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    map_filter_l16_0,
    map_filter_l16_1,
    map_filter_l16_2,
    map_filter_l16_3,
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
    map_filter_l18_0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
};

u32 level_map_selection[10] DATA_SECTION(D_001A01F0) = {0};

u32 memcard_dir_entries[8] DATA_SECTION(D_001A0980) = {0};

u32 memcard_save_file_name_buffer[168] DATA_SECTION(D_001A09A0) = {0};

u32 D_001A0C40[] DATA_SECTION(D_001A0C40) = {
#include "data_inc/D_001A0C40.inc"
};

#include "data_inc/D_001A0C90.refs"
u32 D_001A0C90[] DATA_SECTION(D_001A0C90) = {
#include "data_inc/D_001A0C90.inc"
};

u32 D_001A0CE0[] DATA_SECTION(D_001A0CE0) = {
#include "data_inc/D_001A0CE0.inc"
};

u32 D_001A0DA8[] DATA_SECTION(D_001A0DA8) = {
#include "data_inc/D_001A0DA8.inc"
};

#include "data_inc/D_001A0E70.refs"
u32 D_001A0E70[] DATA_SECTION(D_001A0E70) = {
#include "data_inc/D_001A0E70.inc"
};

u32 D_001A0F60[] DATA_SECTION(D_001A0F60) = {
#include "data_inc/D_001A0F60.inc"
};

#include "data_inc/D_001A1078.refs"
u32 D_001A1078[] DATA_SECTION(D_001A1078) = {
#include "data_inc/D_001A1078.inc"
};

u32 D_001A11E0[] DATA_SECTION(D_001A11E0) = {
#include "data_inc/D_001A11E0.inc"
};

u32 D_001A13E8[] DATA_SECTION(D_001A13E8) = {
#include "data_inc/D_001A13E8.inc"
};

u32 D_001A1460[] DATA_SECTION(D_001A1460) = {
#include "data_inc/D_001A1460.inc"
};

u32 D_001A1500[] DATA_SECTION(D_001A1500) = {
#include "data_inc/D_001A1500.inc"
};

u32 D_001A15F0[] DATA_SECTION(D_001A15F0) = {
#include "data_inc/D_001A15F0.inc"
};

#include "data_inc/D_001A1708.refs"
u32 D_001A1708[] DATA_SECTION(D_001A1708) = {
#include "data_inc/D_001A1708.inc"
};

u32 D_001A1848[] DATA_SECTION(D_001A1848) = {
#include "data_inc/D_001A1848.inc"
};

#include "data_inc/D_001A1960.refs"
u32 D_001A1960[] DATA_SECTION(D_001A1960) = {
#include "data_inc/D_001A1960.inc"
};

u32 D_001A1A00[] DATA_SECTION(D_001A1A00) = {
#include "data_inc/D_001A1A00.inc"
};

u32 D_001A1AA0[] DATA_SECTION(D_001A1AA0) = {
#include "data_inc/D_001A1AA0.inc"
};

u32 D_001A1BE0[] DATA_SECTION(D_001A1BE0) = {
#include "data_inc/D_001A1BE0.inc"
};

u32 D_001A1D48[] DATA_SECTION(D_001A1D48) = {
#include "data_inc/D_001A1D48.inc"
};

u32 D_001A1D98[] DATA_SECTION(D_001A1D98) = {
#include "data_inc/D_001A1D98.inc"
};

#include "data_inc/D_001A1E10.refs"
u32 D_001A1E10[] DATA_SECTION(D_001A1E10) = {
#include "data_inc/D_001A1E10.inc"
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

u32 resident_class_slot_by_id[1968] DATA_SECTION(D_001B3E40) = {0};

u32 resident_class_original_field_2c[224] DATA_SECTION(D_001B6500) = {0};

u32 D_001B7A00[24] DATA_SECTION(D_001B7A00) = {0};

u32 D_001C0000[7832] DATA_SECTION(D_001C0000) = {0};

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

u32 particle_texture_ptrs[128] DATA_SECTION(D_001CE300) = {0};

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

#include "data_inc/D_001CEB68.refs"
u32 D_001CEB68[] DATA_SECTION(D_001CEB68) = {
#include "data_inc/D_001CEB68.inc"
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

#include "data_inc/D_001CF038.refs"
u32 D_001CF038[] DATA_SECTION(D_001CF038) = {
#include "data_inc/D_001CF038.inc"
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

#include "data_inc/D_001CF538.refs"
u32 D_001CF538[] DATA_SECTION(D_001CF538) = {
#include "data_inc/D_001CF538.inc"
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

#include "data_inc/D_001CF9F8.refs"
u32 mission_menu_page[] DATA_SECTION(D_001CF9F8) = {
#include "data_inc/D_001CF9F8.inc"
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

#include "data_inc/D_001CFC18.refs"
u32 D_001CFC18[] DATA_SECTION(D_001CFC18) = {
#include "data_inc/D_001CFC18.inc"
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

u32 D_001D0000[438] DATA_SECTION(D_001D0000) = {0};

#include "data_inc/D_001D06D8.refs"
u32 D_001D06D8[] DATA_SECTION(D_001D06D8) = {
#include "data_inc/D_001D06D8.inc"
};

#include "data_inc/D_001D0728.refs"
u32 D_001D0728[] DATA_SECTION(D_001D0728) = {
#include "data_inc/D_001D0728.inc"
};

#include "data_inc/D_001D0780.refs"
u32 D_001D0780[] DATA_SECTION(D_001D0780) = {
#include "data_inc/D_001D0780.inc"
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

#include "data_inc/D_001D08C8.refs"
u32 D_001D08C8[] DATA_SECTION(D_001D08C8) = {
#include "data_inc/D_001D08C8.inc"
};

#include "data_inc/D_001D0950.refs"
u32 D_001D0950[] DATA_SECTION(D_001D0950) = {
#include "data_inc/D_001D0950.inc"
};

u32 D_001D09A8[] DATA_SECTION(D_001D09A8) = {
#include "data_inc/D_001D09A8.inc"
};

u32 heli_pack_menu_table[] DATA_SECTION(D_001D0A50) = {
#include "data_inc/D_001D0A50.inc"
};

u32 no_helipack_menu_table[] DATA_SECTION(D_001D0A88) = {
#include "data_inc/D_001D0A88.inc"
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

#include "data_inc/D_001D0BD0.refs"
u32 D_001D0BD0[] DATA_SECTION(D_001D0BD0) = {
#include "data_inc/D_001D0BD0.inc"
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

u32 D_001D0DC8[] DATA_SECTION(D_001D0DC8) = {
#include "data_inc/D_001D0DC8.inc"
};

#include "data_inc/D_001D0DE8.refs"
u32 D_001D0DE8[] DATA_SECTION(D_001D0DE8) = {
#include "data_inc/D_001D0DE8.inc"
};

#include "data_inc/D_001D0E40.refs"
u32 D_001D0E40[] DATA_SECTION(D_001D0E40) = {
#include "data_inc/D_001D0E40.inc"
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

#include "data_inc/D_001D0FA0.refs"
u32 D_001D0FA0[] DATA_SECTION(D_001D0FA0) = {
#include "data_inc/D_001D0FA0.inc"
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

#include "data_inc/D_001D1328.refs"
u32 D_001D1328[] DATA_SECTION(D_001D1328) = {
#include "data_inc/D_001D1328.inc"
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

#include "data_inc/D_001D1588.refs"
u32 D_001D1588[] DATA_SECTION(D_001D1588) = {
#include "data_inc/D_001D1588.inc"
};

#include "data_inc/D_001D1610.refs"
u32 D_001D1610[] DATA_SECTION(D_001D1610) = {
#include "data_inc/D_001D1610.inc"
};

#include "data_inc/D_001D1668.refs"
u32 D_001D1668[] DATA_SECTION(D_001D1668) = {
#include "data_inc/D_001D1668.inc"
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

#include "data_inc/D_001D1818.refs"
u32 D_001D1818[] DATA_SECTION(D_001D1818) = {
#include "data_inc/D_001D1818.inc"
};

#include "data_inc/D_001D18A0.refs"
u32 D_001D18A0[] DATA_SECTION(D_001D18A0) = {
#include "data_inc/D_001D18A0.inc"
};

void *D_001D18F8[] DATA_SECTION(D_001D18F8) = {
    sound_options_menu, DrawSoundMenu, 0, set_pause_sound_volume, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

#include "data_inc/D_001D1948.refs"
u32 D_001D1948[] DATA_SECTION(D_001D1948) = {
#include "data_inc/D_001D1948.inc"
};

#include "data_inc/D_001D19D0.refs"
u32 D_001D19D0[] DATA_SECTION(D_001D19D0) = {
#include "data_inc/D_001D19D0.inc"
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

u32 D_001D1C00[] DATA_SECTION(D_001D1C00) = {
#include "data_inc/D_001D1C00.inc"
};

void *D_001D1C28[] DATA_SECTION(D_001D1C28) = {
    0, render_localized_ui_entry_list, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, (char *)D_4000 + 0x2, D_001D1C00, 0, 0, 0, 0, 0, 0,
};

#include "data_inc/D_001D1C78.refs"
u32 D_001D1C78[] DATA_SECTION(D_001D1C78) = {
#include "data_inc/D_001D1C78.inc"
};

#include "data_inc/D_001D1CE0.refs"
u32 D_001D1CE0[] DATA_SECTION(D_001D1CE0) = {
#include "data_inc/D_001D1CE0.inc"
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

#include "data_inc/D_001D1E60.refs"
u32 D_001D1E60[] DATA_SECTION(D_001D1E60) = {
#include "data_inc/D_001D1E60.inc"
};

void *D_001D1EE8[] DATA_SECTION(D_001D1EE8) = {
    Menu_BackInput, DrawQuitGameMenu, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

#include "data_inc/D_001D1F38.refs"
u32 D_001D1F38[] DATA_SECTION(D_001D1F38) = {
#include "data_inc/D_001D1F38.inc"
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

u32 D_001D2208[] DATA_SECTION(D_001D2208) = {
#include "data_inc/D_001D2208.inc"
};

#include "data_inc/D_001D2230.refs"
u32 D_001D2230[] DATA_SECTION(D_001D2230) = {
#include "data_inc/D_001D2230.inc"
};

u32 D_001D2288[] DATA_SECTION(D_001D2288) = {
#include "data_inc/D_001D2288.inc"
};

#include "data_inc/D_001D22B0.refs"
u32 D_001D22B0[] DATA_SECTION(D_001D22B0) = {
#include "data_inc/D_001D22B0.inc"
};

#include "data_inc/D_001D2308.refs"
u32 D_001D2308[] DATA_SECTION(D_001D2308) = {
#include "data_inc/D_001D2308.inc"
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

#include "data_inc/D_001D2678.refs"
u32 pause_default_action_list[] DATA_SECTION(D_001D2678) = {
#include "data_inc/D_001D2678.inc"
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

u32 D_001D2A28[] DATA_SECTION(D_001D2A28) = {
#include "data_inc/D_001D2A28.inc"
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

u32 D_001D3AA0[] DATA_SECTION(D_001D3AA0) = {
#include "data_inc/D_001D3AA0.inc"
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

u32 D_001D3C50[] DATA_SECTION(D_001D3C50) = {
#include "data_inc/D_001D3C50.inc"
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

u32 D_001D4DA0[] DATA_SECTION(D_001D4DA0) = {
#include "data_inc/D_001D4DA0.inc"
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

#include "data_inc/D_001D4F18.refs"
u32 D_001D4F18[] DATA_SECTION(D_001D4F18) = {
#include "data_inc/D_001D4F18.inc"
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

u32 D_001D5138[] DATA_SECTION(D_001D5138) = {
#include "data_inc/D_001D5138.inc"
};

void *D_001D5168[] DATA_SECTION(D_001D5168) = {
    0, render_localized_ui_entry_list, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, (char *)D_4000 + 0x2, D_001D5138, 0, 0, 0, 0, 0, 0,
};

#include "data_inc/D_001D52C8.refs"
u32 D_001D52C8[] DATA_SECTION(D_001D52C8) = {
#include "data_inc/D_001D52C8.inc"
};

u32 timed_sequence_page3[] DATA_SECTION(D_001D5588) = {
#include "data_inc/D_001D5588.inc"
};

u32 timed_sequence_page4[] DATA_SECTION(D_001D5618) = {
#include "data_inc/D_001D5618.inc"
};

u32 timed_sequence_page5[] DATA_SECTION(D_001D5630) = {
#include "data_inc/D_001D5630.inc"
};

#include "data_inc/D_001D5D58.refs"
u32 preview_resource_bindings[] DATA_SECTION(D_001D5D58) = {
#include "data_inc/D_001D5D58.inc"
};

u32 preserved_item_available_indices[] DATA_SECTION(D_001D5F20) = {
#include "data_inc/D_001D5F20.inc"
};

u32 pause_current_action_list[42] DATA_SECTION(D_001D5F78) = {0};

u32 D_001D6020[22] DATA_SECTION(D_001D6020) = {0};

u32 preview_resource_ids[22] DATA_SECTION(D_001D60C8) = {0};

u32 preview_request_address_base[2] DATA_SECTION(D_001D6218) = {0};

u32 current_preview_animation_request[14] DATA_SECTION(D_001D6410) = {0};

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

#include "data_inc/D_001DC3F0.refs"
u32 D_001DC3F0[] DATA_SECTION(D_001DC3F0) = {
#include "data_inc/D_001DC3F0.inc"
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

u32 vendor_state[15] DATA_SECTION(D_001E66C0) = {0};

u32 D_001E7958[] DATA_SECTION(D_001E7958) = {
#include "data_inc/D_001E7958.inc"
};

char str_loading_sound_bank[] DATA_SECTION(D_001E79C0) =
#include "data_inc/D_001E79C0.inc"
    ;

u32 str_too_many_dir_lights[] DATA_SECTION(D_001E79D8) = {
#include "data_inc/D_001E79D8.inc"
};

u32 D_001E7A50[] DATA_SECTION(D_001E7A50) = {
#include "data_inc/D_001E7A50.inc"
};

u32 camera_sample_dir[] DATA_SECTION(D_001E7AD8) = {
#include "data_inc/D_001E7AD8.inc"
};

u32 camera_sample_line_format[] DATA_SECTION(D_001E7B10) = {
#include "data_inc/D_001E7B10.inc"
};

u32 camera_sample_alt_line_format[] DATA_SECTION(D_001E7B30) = {
#include "data_inc/D_001E7B30.inc"
};

u32 D_001E7B68[2] DATA_SECTION(D_001E7B68) = {0};

u32 profile_mark_tfrag_lighting[] DATA_SECTION(D_001E7BA0) = {
#include "data_inc/D_001E7BA0.inc"
};

u32 profile_mark_shrub_lighting[] DATA_SECTION(D_001E7BB8) = {
#include "data_inc/D_001E7BB8.inc"
};

u32 message_too_long_label[] DATA_SECTION(D_001E7DD8) = {
#include "data_inc/D_001E7DD8.inc"
};

u32 loaded_irx_modules_message[] DATA_SECTION(D_001E7E28) = {
#include "data_inc/D_001E7E28.inc"
};

u32 unsupported_lang_message[] DATA_SECTION(D_001E7E40) = {
#include "data_inc/D_001E7E40.inc"
};

u32 str_bad_point_light_tfrag[] DATA_SECTION(D_001E7EA0) = {
#include "data_inc/D_001E7EA0.inc"
};

u32 str_bad_point_light_shrub[] DATA_SECTION(D_001E7EC8) = {
#include "data_inc/D_001E7EC8.inc"
};

u32 D_001E8030[] DATA_SECTION(D_001E8030) = {
#include "data_inc/D_001E8030.inc"
};

u32 str_no_map_available[] DATA_SECTION(D_001E8398) = {
#include "data_inc/D_001E8398.inc"
};

u32 D_001E83F0[] DATA_SECTION(D_001E83F0) = {
#include "data_inc/D_001E83F0.inc"
};

u32 D_001E8408[] DATA_SECTION(D_001E8408) = {
#include "data_inc/D_001E8408.inc"
};

u32 D_001E8420[] DATA_SECTION(D_001E8420) = {
#include "data_inc/D_001E8420.inc"
};

u32 D_001E8438[] DATA_SECTION(D_001E8438) = {
#include "data_inc/D_001E8438.inc"
};

char D_001E8450[] DATA_SECTION(D_001E8450) =
#include "data_inc/D_001E8450.inc"
    ;

char D_001E8468[] DATA_SECTION(D_001E8468) =
#include "data_inc/D_001E8468.inc"
    ;

u32 D_001E8480[] DATA_SECTION(D_001E8480) = {
#include "data_inc/D_001E8480.inc"
};

u32 D_001E8498[] DATA_SECTION(D_001E8498) = {
#include "data_inc/D_001E8498.inc"
};

u32 D_001E84B0[] DATA_SECTION(D_001E84B0) = {
#include "data_inc/D_001E84B0.inc"
};

u32 D_001E84C8[] DATA_SECTION(D_001E84C8) = {
#include "data_inc/D_001E84C8.inc"
};

char D_001E84E8[] DATA_SECTION(D_001E84E8) =
#include "data_inc/D_001E84E8.inc"
    ;

u32 memcard_restore_size_mismatch_msg[] DATA_SECTION(D_001E8500) = {
#include "data_inc/D_001E8500.inc"
};

u32 str_memcard_deleting_folder[] DATA_SECTION(D_001E8518) = {
#include "data_inc/D_001E8518.inc"
};

u32 D_001E85A8[2] DATA_SECTION(D_001E85A8) = {0};

u32 D_001E8608[2] DATA_SECTION(D_001E8608) = {0};

u32 memcard_error_message[] DATA_SECTION(D_001E8690) = {
#include "data_inc/D_001E8690.inc"
};

u32 D_001E86E8[2] DATA_SECTION(D_001E86E8) = {0};

u32 s_tried_to_create_moby[] DATA_SECTION(D_001E86F0) = {
#include "data_inc/D_001E86F0.inc"
};

u32 vu_chain_overflow_message[] DATA_SECTION(D_001E8730) = {
#include "data_inc/D_001E8730.inc"
};

u32 D_001E8890[] DATA_SECTION(D_001E8890) = {
#include "data_inc/D_001E8890.inc"
};

u32 load_file_start_failed_string[] DATA_SECTION(D_001E8980) = {
#include "data_inc/D_001E8980.inc"
};

u32 D_001E89E8[] DATA_SECTION(D_001E89E8) = {
#include "data_inc/D_001E89E8.inc"
};

u32 cheat_menu_text_ids_init[] DATA_SECTION(D_001E8A78) = {
#include "data_inc/D_001E8A78.inc"
};

u32 language_resource_offsets[] DATA_SECTION(D_001E8B00) = {
#include "data_inc/D_001E8B00.inc"
};

u32 str_shrub_texture_overflow[] DATA_SECTION(D_001E8C00) = {
#include "data_inc/D_001E8C00.inc"
};

u32 D_001E8C58[2] DATA_SECTION(D_001E8C58) = {0};

u32 unloaded_sound_bank_format[] DATA_SECTION(D_001E8CB8) = {
#include "data_inc/D_001E8CB8.inc"
};

u32 vu1_chain_overflow_msg[] DATA_SECTION(D_001E8CF8) = {
#include "data_inc/D_001E8CF8.inc"
};

u32 str_tie_texture_overflow[] DATA_SECTION(D_001E8D80) = {
#include "data_inc/D_001E8D80.inc"
};

u32 str_scrolling_status_fmt[] DATA_SECTION(D_001E8DA0) = {
#include "data_inc/D_001E8DA0.inc"
};

u32 D_001E8E18[2] DATA_SECTION(D_001E8E18) = {0};

u32 movie_open_error_text[] DATA_SECTION(D_001E8E20) = {
#include "data_inc/D_001E8E20.inc"
};

u32 vibuf_dma_not_active_msg[] DATA_SECTION(D_001E8E50) = {
#include "data_inc/D_001E8E50.inc"
};

u32 str_mpeg_get_picture_error[] DATA_SECTION(D_001E8E80) = {
#include "data_inc/D_001E8E80.inc"
};

u32 moby_class_data_table[] DATA_SECTION(D_001E8F00) = {
#include "data_inc/D_001E8F00.inc"
};

u32 camera_types[] DATA_SECTION(D_001E8F80) = {
#include "data_inc/D_001E8F80.inc"
};

u32 D_001E9000[] DATA_SECTION(D_001E9000) = {
#include "data_inc/D_001E9000.inc"
};
