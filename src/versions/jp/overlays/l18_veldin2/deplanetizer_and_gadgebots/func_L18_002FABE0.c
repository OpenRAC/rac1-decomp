extern float D_J_L18_001625DC MACRO_ADDR;
void draw_three_scaled_camera_facing_quads(void) {
    extern ML_9780 D_L18_0016D2E0;
    extern int func_001F9850(int);
    extern unsigned long func_001F4868(int);
    extern void func_00234C98(int, long);
    extern void func_001F9EC0(void *, void *, void *);
    extern void func_001F9BD8(void *, void *, void *);
    extern void func_001F9BF0(void *, void *, void *);
    extern void func_L00_001FF4B0(void *, void *, float);
    extern void func_001F9CA0(void *, void *, void *);
    extern void func_001F9C30(void *, void *, float);
    extern void func_001F9EE8(void *, void *, void *);
    extern void func_L00_001FD1D8(void *, void *, int);
    extern short D_L18_00162528;
    extern char D_L18_00167A50[];
    extern short D_L18_00162588;
    extern short D_L18_0016258C;
    extern float D_L18_001DFE50[4][4];
    Pk_9780 pk;
    float mat[4][4];
    float up[4];
    int i;
    int color;
    float tilt;
    char *target;

    if (veldin2_cutscene_state.n == scale_ticks((*(int *)&deplanetizer_quads_start_tick) + 1)) {
        D_L18_001625E0 = 1.0f;
        D_L18_001625E4 = 0.0f;
        if (veldin2_cutscene_state.state == 7) {
            tilt = -0.15f;
        } else {
            tilt = 0.15f;
        }
        D_L18_001625E8 = tilt;
        D_J_L18_001625DC = 1.0f;
    }
    pk.b = GetEffectTex(0xB);
    pk.c = 0x0000FF9000000260ULL;
    pk.d = 0x8000000048ULL;
    pk.a = 0;
    VU1_addGSregister(0x4A, 0);
    VU1_addGSregister(0x47, 0x51001);
    matrix_mul_vec3(mat[3], &D_L18_001625E0, D_L18_00167A50);
    target = D_L18_00167A50;
    target -= 0x210;
    FastVecAdd(mat[3], mat[3], target);
    FastVecSub(mat[0], mat[3], target);
    vec_scale_to_length(mat[0], mat[0], 1.0f);
    *(u128_9780 *)up = 0;
    up[2] = 1.0f;
    up[3] = 1.0f;
    FastVecCross(mat[1], mat[0], up);
    vec_scale_to_length(mat[1], mat[1], 1.0f);
    FastVecCross(mat[2], mat[1], mat[0]);
    pk.uv[0] = 1.0f;
    pk.uv[1] = 1.0f;
    pk.uv[2] = 0.0f;
    pk.uv[3] = 1.0f;
    pk.uv[4] = 1.0f;
    pk.uv[5] = 0.0f;
    pk.uv[6] = 0.0f;
    pk.uv[7] = 0.0f;
    color = (*(int *)&D_L18_00162588);
    pk.col[3] = color;
    pk.col[2] = color;
    pk.col[1] = color;
    pk.col[0] = color;
    for (i = 0; i < 4; i++) {
        FastVecScale(pk.m[i], D_L18_001DFE50[i], deplanetizer_camera_quad_base_scale);
        transform_vector(pk.m[i], pk.m[i], mat);
    }
    draw_world_quad(&pk, 0, 0);
    color = (*(int *)&D_L18_0016258C);
    pk.col[3] = color;
    pk.col[2] = color;
    pk.col[1] = color;
    pk.col[0] = color;
    for (i = 0; i < 4; i++) {
        FastVecScale(pk.m[i], D_L18_001DFE50[i], deplanetizer_camera_quad_base_scale * 0.75f);
        transform_vector(pk.m[i], pk.m[i], mat);
    }
    draw_world_quad(&pk, 0, 0);
    for (i = 0; i < 4; i++) {
        FastVecScale(pk.m[i], D_L18_001DFE50[i], deplanetizer_camera_quad_base_scale * 0.5f);
        transform_vector(pk.m[i], pk.m[i], mat);
    }
    draw_world_quad(&pk, 0, 0);
}
