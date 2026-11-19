extern "C" s32 stricmp(const char *, const char *);
s32 MKMaterial_GetMaterialIDMask(const char *arg0) {
    s32 var_r30_27;
    s32 var_r31_28;

    if (stricmp(arg0, "NONE") == 0) {
        return 0;
    }
    var_r30_27 = 0;
    var_r31_28 = 0;
    while (var_r30_27 < (s32) materialIdCount) {
        if (stricmp(arg0, (const char *) &pMatIDTable[var_r31_28]) == 0) {
            return 1 << M2C_FIELD(&pMatIDTable[var_r31_28], u8 *, 0x40);
        }
        var_r30_27 += 1;
        var_r31_28 += 0x41;
    }
    return 0;
}
