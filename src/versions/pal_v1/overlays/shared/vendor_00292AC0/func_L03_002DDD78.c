extern char D_E1_L03_001DC0A0[];
void func_L03_002DDD78(unsigned char *moby) {
    switch (moby[0x20]) {
    case 0:
        func_L02_002A5238(D_E1_L03_001DC0A0, 0.6666667f, 0x20);
        moby[0x20] = 1;
        moby[0x30] = 0xFF;
        break;
    case 1:
        func_001F49B0(func_00216270, moby);
        break;
    }
}
