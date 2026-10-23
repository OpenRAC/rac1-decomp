void menu_post_preparePageOpen(void) {
    char *s = D_0013D390;
    *(int *)(s + 0x1C) = 0;
    if (*(int *)(s + 0xDC) < 0) {
        *(int *)(s + 0xE0) = 0;
        *(int *)(s + 0xDC) = 3;
    }
    D_0015EFB0 = 8;
}
