extern int func_J_001F6B60(unsigned char *arg0, int arg1, void *arg2);

int measure_text_width_small(unsigned char *arg0, int arg1) {
    return func_J_001F6B60(arg0, arg1, small_font_metrics);
}
