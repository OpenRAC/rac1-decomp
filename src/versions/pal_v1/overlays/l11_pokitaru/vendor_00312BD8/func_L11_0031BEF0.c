void Moby1350Update(char *moby) {
    int *data = *(int **)(moby + 0x78);
    if (data[0] == -1) {
        DeleteMoby(moby);
    } else if (data[1] != -1 && MobyGroup_CountNotInState(data[1], -1) == 0) {
        unsigned char *g = D_0013D50F + 1;
        if (g[0x13] == 0) {
            g[0x13] = 1;
            PlayBankSound(1, 0, 0);
            ShowBanner(0x53D6, -1);
        }
    }
}
