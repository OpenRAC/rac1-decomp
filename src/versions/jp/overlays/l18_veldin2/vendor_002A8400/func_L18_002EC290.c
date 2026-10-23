extern short D_J_L18_001620AC;
void func_L18_002EC290(void *moby) {
    V_ec290 s[10];
    V_ec290 d[5];
    unsigned char flag = *(unsigned char *)D_0013E633;
    char *data = *(char **)((char *)moby + 0x78);
    float scale;
    int i;
    int k;
    float f20;
    int r;

    *(float *)&D_L18_00162098 = func_001FA748(*(float *)&D_L18_00162098, *(float *)&D_L18_0016209C);
    *(float *)&D_L18_001620A0 = func_001FA790(*(float *)&D_L18_001620A0, *(float *)&D_L18_001620A4);
    *(float *)&D_L18_001620B4 = func_001FA748(*(float *)&D_L18_001620B4, *(float *)&D_L18_001620B8);
    scale = func_001F9D10((char *)moby + 0x10, data + 0x10) * 0.05f;
    if (flag) {
        *(int *)&D_L18_001620E4 = 0x7F2040;
    } else {
        *(int *)&D_L18_001620E4 = 0x7F2020;
    }
    func_001F9BF0(&s[0], data + 0x10, (char *)moby + 0x10);
    func_L00_001FF4B0(&s[0], &s[0], 1.0f);
    func_001F9CA0(&s[1], &s[0], D_0013F6E0);
    func_002156E0(&s[0], &s[0], &s[1], 0.17453292f);
    func_001F9C30(&s[3], &s[0], scale);
    qcopy(D_L18_001D9FD0[0], (char *)moby + 0x10);
    qcopy(D_L18_001D9FD0[1], (char *)moby + 0x10);
    for (i = 1; i < 20; i++) {
        float f21;
        float len;
        float len0;
        float a;
        float b;
        f21 = *(float *)&D_L18_00162090
              + (*(float *)&D_L18_00162094 - *(float *)&D_L18_00162090) * (func_001FA888(i) * 0.05f);
        f21 = f21 * func_001F9FA8(func_L00_0025F368(*(float *)&D_L18_00162098 + (float)i * *(float *)&D_L18_0016208C));
        f21 = f21 + func_L00_00258C80(*(float *)&D_L18_001620D0, *(float *)&D_L18_001620D4);
        D_L18_001D9FD0[0][i].f[2] = D_L18_001D9FD0[0][i].f[2] - D_L18_001DA250[i];
        D_L18_001DA250[i] = f21;
        a = func_00214158();
        b = func_00214158();
        func_00215C00(&s[1], scale, a, b);
        s[1].f[2] = s[1].f[2] * 0.5f;
        func_001F9C08(&s[2], &s[3], &s[1], *(float *)&D_L18_0016211C);
        len0 = func_001F9CB8(&s[2]);
        if (len0 == 0.0f) {
            qcopy(&D_L18_001D9FD0[0][i], &D_L18_001D9FD0[0][i - 1]);
        } else {
            func_001F9C30(&s[2], &s[2], scale / len0);
            func_001F9BD8(&D_L18_001D9FD0[0][i], &D_L18_001D9FC0[i], &s[2]);
            qcopy(&s[3], &s[2]);
        }
        D_L18_001D9FD0[0][i].f[2] = D_L18_001D9FD0[0][i].f[2] + f21;
        func_001F9BF0(&s[1], &D_L18_001D9FD0[0][i], &D_L18_001D9FC0[i]);
        func_001F9BF0(&s[5], data + 0x10, &D_L18_001D9FD0[0][i]);
        len = func_001F9CB8(&s[5]);
        if (len != 0.0f) {
            float w;
            if (i == 19) {
                w = 0.5f;
                scale = len;
            } else if (i >= 16) {
                w = 0.5f;
                scale = len / func_001FA888(19 - i);
            } else {
                w = 0.1f;
            }
            func_001F9C30(&s[5], &s[5], scale / len);
            func_001F9C08(&s[3], &s[3], &s[5], w);
        }
        if (i < 10) {
            float g;
            float h;
            float ang;
            float m;
            g = func_L00_0025F368(*(float *)&D_L18_001620A0 + (float)i * *(float *)&D_L18_001620A8);
            h = *(float *)&D_L18_001620AC
                * func_001F9FA8(func_L00_0025F368(*(float *)&D_L18_001620B4 + (float)i * *(float *)&D_J_L18_001620AC));
            qcopy(&D_L18_001D9FD0[1][i], &D_L18_001D9FD0[0][i]);
            h = h * func_001F9FA8(g) + func_L00_00258C80(0.0f, 0.1f);
            D_L18_001D9FD0[1][i].f[2] = D_L18_001D9FD0[1][i].f[2] + h;
            D_L18_001DA3E0[i] = h;
            ang = func_001FA748(func_L00_001FF860(s[1].f[0], s[1].f[1]), 1.5707964f);
            m = *(float *)&D_L18_001620B0 * func_001F9F90(g);
            s[4].f[0] = func_001F9F90(ang) * m;
            s[4].f[1] = func_001F9FA8(ang) * m;
            s[4].f[2] = 0.0f;
            qcopy(&D_L18_001DA2A0[i], &s[4]);
            func_001F9BD8(&D_L18_001D9FD0[1][i], &D_L18_001D9FD0[1][i], &s[4]);
        } else {
            int r = 21 - i;
            qcopy(&D_L18_001D9FD0[1][i], &D_L18_001D9FD0[0][i]);
            D_L18_001D9FD0[1][i].f[2] = D_L18_001D9FD0[1][i].f[2] + D_L18_001DA3E0[r];
            func_001F9BD8(&D_L18_001D9FD0[1][i], &D_L18_001D9FD0[1][i], &D_L18_001DA2A0[r]);
            qcopy(&s[4], &D_L18_001DA2A0[i]);
        }
    }
    func_001F9CA0(&s[6], &s[0], D_0013F6E0);
    func_L00_001FF4B0(&s[6], &s[6], 1.0f);
    func_L00_001FF4B0(&s[7], D_0013F6E0, 1.0f);
    for (k = 0; k < 4; k++) {
        float t;
        if (k < 2) {
            qcopy(&s[8], (char *)moby + 0x10);
            t = 0.4f;
        } else {
            qcopy(&s[8], data + 0x10);
            t = 0.5f;
        }
        if (func_001F9938(D_L18_00162148 + k)) {
            int j;
            D_L18_00162148[k] = func_001F9850(D_L18_00162158[k]);
            D_L18_00162150[k] = 0;
            scale = func_L00_00258C80(0.52359879f, 1.04719758f);
            f20 = func_002140F8(-1.04719758f, 0.17453292f);
            func_001F9C30(&s[5], &s[0], t);
            func_002156E0(&s[5], &s[5], &s[6], f20);
            func_002156E0(&s[5], &s[5], &s[7], scale);
            qcopy(&D_L18_001DA430[k].p[0], &s[8]);
            func_001F9BD8(&D_L18_001DA430[k].p[1], &s[8], &s[5]);
            t = 1.0f;
            for (j = 2; j < 5; j++) {
                func_001F9BF0(&s[9], &D_L18_001DA420[k].p[j - 1], D_L18_00167840);
                f20 = func_002140F8(0.17453292f, 0.959931076f) * t;
                t = -t;
                func_002156E0(&s[5], &s[5], &s[9], f20);
                func_001F9BD8((D_L18_001DA430[k].p + j), &D_L18_001DA420[k].p[j - 1], &s[5]);
            }
        } else {
            int j;
            for (j = 1; j < 5; j++) {
                func_001F9BF0(&d[j], (D_L18_001DA430[k].p + j), &D_L18_001DA420[k].p[j - 1]);
                d[j].f[0] += func_L00_00258C80(0.0f, 0.1f);
                d[j].f[1] += func_L00_00258C80(0.0f, 0.1f);
                d[j].f[2] += func_L00_00258C80(0.0f, 0.1f);
            }
            qcopy(&D_L18_001DA430[k].p[0], &s[8]);
            for (j = 1; j < 5; j++) {
                func_001F9BD8((D_L18_001DA430[k].p + j), &D_L18_001DA420[k].p[j - 1], &d[j]);
            }
            {
                int x = D_L18_00162160[k];
                int y = D_L18_00162148[k];
                float fr;
                if (x < y) {
                    x = y - x;
                } else {
                    x = x - y;
                }
                fr = func_001FA888(x);
                fr = fr / func_001FA888(func_001F9850(15));
                D_L18_00162150[k] = func_001FA898_r((1.0f - fr) * 32.0f);
            }
        }
    }
    scale = func_L00_00258C80(0.52359879f, 1.04719758f);
    f20 = func_002140F8(-0.52359879f, 1.04719758f);
    func_001F9C30(&s[5], &s[0], *(float *)&D_L18_00162114 * D_0015EE60);
    func_002156E0(&s[5], &s[5], &s[6], f20);
    func_002156E0(&s[5], &s[5], &s[7], scale);
    r = func_L00_00258BC8(1, 8);
    if (func_002140B0(2)) r = -r;
    f20 = func_002140F8(0.2f, 0.6f);
    spawn_ec290((char *)moby + 0x10, func_001F9850(15), f20 * 0.3f, f20, *(int *)&D_L18_001620E4 | 0x7F000000, 0, r, &s[5], 0.0f);
    r = -r;
    spawn_ec290((char *)moby + 0x10, func_001F9850(15), f20 * 0.15f, f20 * 0.5f, 0x307F7F7F, 0, r, &s[5], 0.0f);
    r = func_L00_00258BC8(1, 8);
    if (func_002140B0(2)) r = -r;
    f20 = func_002140F8(0.15f, 3.0f);
    spawn_ec290(data + 0x10, func_001F9850(12), f20 * 0.1f, f20, *(int *)&D_L18_001620E4 | 0x7F000000, 0, r, D_L18_0015F660_2D7310, 0.0f);
}
