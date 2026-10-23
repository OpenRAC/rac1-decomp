void func_L16_002E8680(char *moby) {
    char *data = *(char **)(moby + 0x78);
    switch (*(int *)(data + 8)) {
    case 0: {
        char *g = D_0013E633 + 0xE9D;
        if (func_00215570(g, *(int *)data) != 0) {
            if (*(int *)(g + 0x200C) == 0xF) {
                *(int *)(data + 8) = 1;
            }
        }
        break;
    }
    case 1: {
        char *h = D_0013E633 + 0xE1D;
        if (*(int *)(h + 0x2084) == 0x42) {
            *(int *)(data + 8) = 0;
        } else if (func_00215570(h + 0x80, *(int *)(data + 4)) != 0) {
            unsigned char *f = (unsigned char *)D_0013D50F + 0x1;
            if (f[0x19] == 0) {
                f[0x19] = 1;
                func_0022EE28(1, 0, 0);
                func_L00_00264DB8(0x542D, -1);
            }
        }
        break;
    }
    }
}
