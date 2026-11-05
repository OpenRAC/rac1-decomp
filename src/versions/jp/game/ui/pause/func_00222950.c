int update_level_selection_map_screen(void) {
    if (pad0_pressed_unmasked & (PAD_CIRCLE | PAD_CROSS)) {
        pause_current_action_list = D_001D2678;
    }
    return 0;
}
