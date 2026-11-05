/* NTSC-J measure_text_width: dakuten marks 0xBD and 0xBE take their width from the character before them. */
int func_J_001F6B60(unsigned char *str, int count, signed char *table) {
    int width = 0;
    int i = 0;
    unsigned char *p;

    if (count != 0 && *str != 0) {
        p = str;
        do {
            int c = *p;
            int w = table[c * 4 + 3];

            if (w != 0) {
                if (c == 0xBD || c == 0xBE) {
                    signed char *prev = table + p[-1] * 4;
                    int d = prev[0x203] - prev[3] + 4;

                    width = (c == 0xBE) ? width + 1 + d : width + d;
                } else {
                    width += w;
                }
            }
            i++;
            if (i == count) {
                break;
            }
            p++;
        } while (*p != 0);
    }
    return width;
}
