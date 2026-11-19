extern "C" s32 stricmp(s8 *, s8 *);

s32 DataMap_GetValue(const DataMap *arg0, const char *arg1) {
    s32 var_r31_132;
    void *temp_r30_144;
    s8 *temp_r3_144;

    for (var_r31_132 = 0; temp_r30_144 = (s8 *) arg0 + var_r31_132, temp_r3_144 = M2C_FIELD(temp_r30_144, s8 **, 4), temp_r3_144 != 0; var_r31_132 += 8) {
        if (stricmp(temp_r3_144, (s8 *) arg1) == 0) {
            return M2C_FIELD(temp_r30_144, s32 *, 0);
        }
    }
    return 0;
}
