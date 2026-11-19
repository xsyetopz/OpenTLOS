void MKCommandLine::ParseArgument(char *arg0) {
    s32 var_ctr_40;
    s32 var_r28_39;
    s8 *temp_r31_22;
    u32 var_r27_17;
    u8 temp_r0_23;

    var_r27_17 = 0U;
    temp_r31_22 = (signed char *) (&arg0[var_r27_17]);
    temp_r0_23 = (u8) *temp_r31_22;
    while (((s8) temp_r0_23 != 0x2D) && ((s8) temp_r0_23 != 0x2B) && ((s8) temp_r0_23 != 0x3D) && ((s8) temp_r0_23 != 0x20) && (var_r27_17 < strlen(arg0))) {
        var_r27_17 += 1;
        temp_r31_22 = (signed char *) (&arg0[var_r27_17]);
        temp_r0_23 = (u8) *temp_r31_22;
    }
    var_r28_39 = 0;
    var_ctr_40 = 0x10;
    do {
        if (M2C_FIELD(this, u32 *, var_r28_39 + 4) == 0U) {
            if (var_r27_17 == strlen(arg0)) {
                M2C_FIELD(this, s8 **, var_r28_39 + 8) = (signed char *) (arg0);
            } else if (stricmp(temp_r31_22, lit_stringBase0) == 0) {
                M2C_FIELD(this, u8 **, var_r28_39 + 8) = lit_stringBase0;
            } else if (stricmp(temp_r31_22, &lit_stringBase0[2]) == 0) {
                M2C_FIELD(this, u8 **, var_r28_39 + 8) = &lit_stringBase0[2];
            } else if ((s32) (u8) *temp_r31_22 != 0x20) {
                M2C_FIELD(this, s8 **, var_r28_39 + 8) = (s8 *) (temp_r31_22 + 1);
            }
            *temp_r31_22 = 0;
            M2C_FIELD(this, s8 **, var_r28_39 + 4) = (signed char *) (arg0);
            this->unk0 += 1;
            return;
        }
        var_r28_39 += 8;
        var_ctr_40 -= 1;
    } while (var_ctr_40 != 0);
}
