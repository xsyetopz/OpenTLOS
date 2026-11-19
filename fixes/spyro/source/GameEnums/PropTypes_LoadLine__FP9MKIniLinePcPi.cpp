s32 PropTypes_LoadLine(MKIniLine *arg0, char *arg1, int *arg2) {
    u32 sp8;

    sp8 = 0;
    if ((u8) DataMap_LoadLineBitfield(arg0, arg1, &propTypeDataMap, (unsigned int *) &sp8) != 0) {
        *arg2 |= sp8;
        return 1;
    }
    return 0;
}
