s32 DataMap_GetName(const DataMap *arg0, unsigned int arg1) {
    s32 var_r5_103;
    s8 *temp_r6_115;

    for (var_r5_103 = 0; temp_r6_115 = (s8 *) arg0 + var_r5_103, (u32) M2C_FIELD(temp_r6_115, u32 *, 4) != 0U; var_r5_103 += 8) {
        if (arg1 == (u32) M2C_FIELD(temp_r6_115, u32 *, 0)) {
            return M2C_FIELD(arg0, s32 *, var_r5_103 + 4);
        }
    }
    return 0;
}
