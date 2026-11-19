extern "C" s32 stricmp(s8 *, s8 *);

s32 DataMap_LoadLine(MKIniLine *arg0, const char *arg1, const DataMap *arg2, unsigned int *arg3) {
    s32 var_r31_68;
    void *temp_r30_82;
    s8 *temp_r3_82;
    const char *sp8;

    sp8 = 0;
    if ((u8) arg0->LoadString(arg1, &sp8, 0) != 0) {
        for (var_r31_68 = 0; temp_r30_82 = (s8 *) arg2 + var_r31_68, temp_r3_82 = M2C_FIELD(temp_r30_82, s8 **, 4), temp_r3_82 != 0; var_r31_68 += 8) {
            if (stricmp(temp_r3_82, (s8 *) sp8) == 0) {
                *arg3 = M2C_FIELD(temp_r30_82, u32 *, 0);
                return 1;
            }
        }
        *arg3 = 0;
        return 1;
    }
    return 0;
}
