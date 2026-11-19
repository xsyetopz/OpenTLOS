u8 *MKCommandLine::GetParameter(const char *arg0, bool arg1) {
    s32 var_r31_126;
    s32 var_r30_125;
    void *temp_r30_136;

    if ((s8) init_221 == 0) {
        init_221 = 1;
        pPositive_220 = lit_stringBase0;
    }
    var_r30_125 = 0;
    var_r31_126 = 0;
    do {
        if ((*(u32 *) ((s8 *) this + (var_r31_126 + 4)) != 0U) && (stricmp((s8 *) arg0, M2C_FIELD(this, u8 **, var_r31_126 + 4)) == 0)) {
            temp_r30_136 = (u8 *) this + var_r31_126;
            if (stricmp(M2C_FIELD(temp_r30_136, s8 **, 8), &lit_stringBase0[2]) == 0) {
                return NULL;
            }
            if (stricmp(M2C_FIELD(temp_r30_136, s8 **, 8), M2C_FIELD(temp_r30_136, u8 **, 4)) == 0) {
                return pPositive_220;
            }
            return (u8 *) M2C_FIELD(temp_r30_136, s8 **, 8);
        }
        var_r30_125 += 1;
        var_r31_126 += 8;
    } while (var_r30_125 < 0x10);
    if (arg1 != 0) {
        return pPositive_220;
    }
    return NULL;
}
