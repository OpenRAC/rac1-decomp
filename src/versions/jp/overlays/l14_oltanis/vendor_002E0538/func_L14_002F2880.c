void func_L14_002F2880(char *moby) {
    char *data = *(char **)(moby + 0x78);
    int v = *(short *)(data + 0xB4);
    if (*(unsigned char *)(moby + 0x20) == 5) {
        v = *(short *)(data + 0xB6);
    }
    switch (v) {
    case 0:
        func_00215F80(4, 0x5444);
        break;
    case 1:
        func_00215F80(4, 0x5445);
        break;
    case 2:
        func_00215F80(4, 0x5445);
        break;
    case 3:
        func_00215F80(4, 0x5445);
        break;
    case 4:
        func_00215F80(4, 0x1399);
        break;
    default:
        func_00215F80(4, 0x139B);
        break;
    }
}
