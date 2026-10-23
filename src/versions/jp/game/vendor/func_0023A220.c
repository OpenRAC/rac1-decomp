void func_0023A220(char *unused, int x, int y) {
    char sp[0x18];
    VendorA *v;
    int idx;
    int m;
    int price;
    int sz = 0x18;

    func_001FBAB8(0, 0, 0x200, 0x80, 0x200, 0x80, 0);
    ((void *(*)(void *, int, int))func_001153FC)(sp, 0, 0x18);
    *(short *)(sp + 0x2) = y;
    *(short *)(sp + 0x6) = x;
    *(short *)(sp + 0x8) = x >> 1;
    *(short *)(sp + 0xA) = (y >> 1) - 7;
    *(short *)(sp + 0x10) = 0x10;
    *(short *)(sp + 0x12) = 1;
    if (((VendorA *)D_001E66C0)->sel != 0) {
        if (((VendorA *)D_001E66C0)->slots[((VendorA *)D_001E66C0)->idx].kind == 1 &&
            D_0013D530[((VendorA *)D_001E66C0)->slots[((VendorA *)D_001E66C0)->idx].type] >=
                ((WeaponInfoA *)(D_001E02B0 + ((VendorA *)D_001E66C0)->slots[((VendorA *)D_001E66C0)->idx].type * sz))->max) {
            m = 0x528A;
        } else {
            v = (VendorA *)D_001E66C0;
            if (v->slots[v->idx].kind == 1) {
                if (v->alt) {
                    price = ((WeaponInfoA *)(D_001E02B0 + v->slots[v->idx].type * 0x18))->priceAlt;
                } else {
                    price = ((WeaponInfoA *)(D_001E02B0 + v->slots[v->idx].type * 0x18))->price;
                }
                m = 0x528A;
                if (D_0015EE98 >= price)
                    m = 0x528B;
            } else {
                int cost;
                if (D_0013D5EB[0] != 0) {
                    cost = ((struct { WeaponInfoA a[1]; } *)D_001E02B0)->a[v->slots[v->idx].type].second;
                } else {
                    cost = ((WeaponInfoA *)(D_001E02B0 + v->slots[v->idx].type * 0x18))->first;
                }
                m = D_0015EE98 < cost ? 0x528A : 0;
            }
        }
    } else {
        m = 0x528B;
    }
    if (m != 0) {
        *(unsigned short *)(sp + 0x12) |= 4;
        func_001F75D0(sp, 0x80F0F0F0L, func_001FE540_id(m), -1);
        *(unsigned short *)(sp + 0x12) ^= 4;
        *(short *)(sp + 0xA) = (y - *(short *)(sp + 0xE)) >> 1;
        func_001F75D0(sp, 0x80F0F0F0L, func_001FE540_id(m), -1);
    }
}
