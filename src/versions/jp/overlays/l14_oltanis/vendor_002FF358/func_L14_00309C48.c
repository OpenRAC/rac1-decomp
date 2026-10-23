void func_L14_00309C48(unsigned char *moby) {
    int *d = *(int **)(moby + 0x78);
    unsigned v;
    int i;
    if (d[0] != -1) {
        if (func_L01_0026EFB8(d[0], -1) == 0) {
            if (gSkillPoints[0x17] == 0) {
                gSkillPoints[0x17] = 1;
                func_0022EE28(1, 0, 0);
                func_L00_00264DB8(0x542D, -1);
            }
        }
    }
    switch (moby[0x20]) {
    case 0:
        moby[0x30] = 0xFF;
        moby[0x20] = 1;
        break;
    case 1:
        if (D_L14_0015F6A8 == 2) {
            v = D_L14_0016D060.state - 3;
            if (v < 3) {
                i = 0;
                if (v <= D_L14_0015F6A8) i = moby[0x20];
                func_L00_00264870(D_L14_0016D060.v178[i]);
            }
        }
        break;
    }
}
