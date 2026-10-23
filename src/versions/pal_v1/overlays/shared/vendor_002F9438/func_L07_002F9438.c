extern char D_L07_00208820[];
void func_L07_002F9438(unsigned char *moby)
{
    switch (moby[0x20]) {
    case 0:
        moby[0x20] = 1;
        moby[0x30] = 0xFF;
        func_L02_002A5238(D_L07_00208820, 0x80, 1.0f);
        break;
    case 1:
        func_001F49B0(func_00216270, moby);
        break;
    }
}
