void start_level(int level) {
    int a;
    int b;
    int t;

    if (level < 0) {
        return;
    }
    if (pal_mode != 0) {
        b = D_00137C80_g.alt[level].b;
        a = D_00137C80_g.alt[level].a;
    } else {
        b = D_00137C80_g.normal[level].b;
        a = D_00137C80_g.normal[level].a;
    }
    decode_mode = 2;
    voice_pool[0x6B] |= 8;
    func_00118D80(0);
    sound_StopAllSounds();
    music_Stop();
    FadeToBlack(scale_game_frame_count(12));
    g_game_mode = 1;
    func_00118D80(0);
    sound_StopAllSounds();
    music_Stop();
    func_0012EF48(0);
    for (;;) {
        char *ld = memory_card_state;
        if (*(int *)(ld + 0xD4) < 3 && *(int *)(ld + 0xDC) < 0) {
            break;
        }
        memcard_update_state();
    }
    {
        char *g = level_resource_buffers;
        t = *(int *)(g + 0x1C);
    }
    Movie_Play(b, a, t + 0x100000, t + 0x400000, 0);
    func_00120F30(0);
    func_00122598(0);
    func_00120858(0, 0);
    func_00123168(func_0012F308);
    Hud_sendTexture(0x1000000, depth_buffer_address, 0x1B, 6, 6, 1);
    decode_mode = 0;
    FadeToBlack(4);
    g_game_mode = 0;
    voice_pool[0x6B] |= 0x10;
}
