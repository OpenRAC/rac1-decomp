extern char D_E1_L14_001E9BE0[];
void func_L14_003047F8(unsigned char *moby) {
    switch (moby[0x20]) {
    case 0:
        func_L02_002A5238(D_E1_L14_001E9BE0, 0.6666667f, 0x40);
        moby[0x20] = 1;
        moby[0x30] = 0xFF;
        break;
    case 1:
        func_001F49B0(func_00216270, moby);
        break;
    }
}
