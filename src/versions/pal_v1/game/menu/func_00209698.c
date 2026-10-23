void CardMenu_State14BeginSlot9(void) {
    char *s = D_0013D390;
    if (*(int *)(s + 0xD4) == 2 && *(int *)(s + 0xDC) < 0) {
        *(int *)(s + 0xDC) = 9;
        *(int *)(s + 0xE0) = 0;
        D_0015EFB0 = 0xF;
    }
}
