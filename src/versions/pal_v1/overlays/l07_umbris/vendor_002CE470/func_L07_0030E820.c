extern char D_E1_L07_00208460[];
void func_L07_0030E820(unsigned char *moby) {
    switch (moby[0x20]) {
    case 0:
        func_L02_002A52B0(D_E1_L07_00208460, 0.66666669f);
        moby[0x20] = 1;
        moby[0x30] = 0xFF;
        break;
    case 1:
        if (!func_00215570(D_L07_00166EC0, **(int **)(moby + 0x78))) {
            func_001F49B0((void *)func_00216270, moby);
        }
        break;
    }
}
