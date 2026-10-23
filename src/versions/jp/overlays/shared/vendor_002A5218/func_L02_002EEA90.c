extern short D_J_L02_001620AC;
void func_L02_002EEA90(char *moby, void *arg) {
    float v0[4];
    float v1[4];
    float mat[4];
    float v2[4];
    float m[4];
    int i;
    func_001F9BF0(mat, moby + 0x10, arg);
    for (i = 0; i < 2; i++) {
        int a, b, c, d, e;
        char *p;
        func_L00_00250800(moby, i, m);
        func_001F9C30(v0, mat, *(float *)&D_L02_001620A4);
        func_001F9C30(v1, mat, *(float *)&D_L02_001620A8);
        func_L00_00258DB0(v2, 0.0f, *(float *)&D_L02_001620AC * D_0015EE6C);
        func_001F9BD8(v1, v1, v2);
        v0[3] = func_002140F8(*(float *)&D_L02_00162084, *(float *)&D_L02_00162088) / 1.5f;
        v1[3] = func_002140F8(*(float *)&D_L02_0016208C, *(float *)&D_L02_00162090) / 1.5f;
        a = func_001FA8A8(*(int *)&D_L02_001620B0, *(int *)&D_L02_001620B4, func_002140F8(0.0f, 1.0f));
        b = func_001FA8A8(*(int *)&D_L02_001620B8, *(int *)&D_J_L02_001620AC, func_002140F8(0.0f, 1.0f));
        c = func_001FA898_r(func_001F9878((float)*(int *)&D_L02_00162074 * func_002140F8(0.0f, 1.0f) + 1.0f));
        d = func_001FA898_r(func_001F9878((float)*(int *)&D_L02_00162078 * (func_002140F8(-*(float *)&D_L02_00162080, *(float *)&D_L02_00162080) + 1.0f)));
        e = func_001FA898_r(func_001F9878((float)*(int *)&D_L02_0016207C * (func_002140F8(-*(float *)&D_L02_00162080, *(float *)&D_L02_00162080) + 1.0f)));
        p = func_00219780(m, v0, v1, a, b, c, d, e, -1);
        if (p != 0) {
            p[9] = func_001FA898_r(8.0f) + 0x60;
        }
    }
}
