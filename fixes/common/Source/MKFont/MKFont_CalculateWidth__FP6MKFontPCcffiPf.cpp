f32 MKFont_CalculateWidth(MKFont *arg0, const char *arg1, float arg2, float arg3, int arg4, float *arg5) {
    MKVector3 pos;
    f32 sp8;
    f32 temp_f31_1051;
    f32 temp_f29_1058;
    f32 temp_f28_1059;
    f32 var_f30_1040;
    f32 var_f3_1144;
    f32 var_f1_1095;
    s32 var_r29_1053;
    s32 var_ctr_1147;
    s32 glyph;
    const char *var_r30_1046;
    const char *var_r31_1045;
    const char *var_r4_1065;
    const char *var_r6_1145;
    s8 temp_r5_1206;
    u8 temp_r0_1070;
    u8 var_r3_1071;
    u8 temp_r4_1153;
    u8 var_r0_1152;
    void *temp_r3_1054;

    var_f30_1040 = 0.0f;
    M2C_FIELD(&pos, f64 *, 0) = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    M2C_FIELD(&pos, f64 *, 8) = M2C_FIELD(&MKVector3::zero, f64 *, 8);
    var_r31_1045 = arg1;
    var_r30_1046 = arg1;
    temp_f31_1051 = MKFontInternal_CalcHeightAndScale(arg0, arg2, &sp8);
    var_r29_1053 = 0;
    temp_r3_1054 = M2C_FIELD(arg0, void **, 0);
    temp_r3_1054 = M2C_FIELD(temp_r3_1054, void **, 0);
    temp_f29_1058 = M2C_FIELD(temp_r3_1054, f32 *, 8) * sp8;
    temp_f28_1059 = M2C_FIELD(temp_r3_1054, f32 *, 0xC) * sp8;
    temp_r5_1206 = (s8) (u8) *var_r31_1045;
    while ((temp_r5_1206 != 0) && (var_r29_1053 < arg4)) {
        glyph = 0;
        if (temp_r5_1206 == 0x3C) {
            var_r4_1065 = var_r31_1045 + 1;
            temp_r0_1070 = (u8) *var_r4_1065;
            var_r3_1071 = 0;
            if (((s8) temp_r0_1070 == 0x20) || ((s8) temp_r0_1070 == 9) || ((s8) temp_r0_1070 == 0xA)) {
                var_r3_1071 = 1;
            }
            while (var_r3_1071 != 0) {
                var_r4_1065 += 1;
                temp_r0_1070 = (u8) *var_r4_1065;
                var_r3_1071 = 0;
                if (((s8) temp_r0_1070 == 0x20) || ((s8) temp_r0_1070 == 9) || ((s8) temp_r0_1070 == 0xA)) {
                    var_r3_1071 = 1;
                }
            }
            glyph = 1;
        } else if (temp_r5_1206 == 0x20) {
            pos.unk0 = pos.unk0 + temp_f28_1059;
        } else if (temp_r5_1206 == 0xA) {
            var_f1_1095 = pos.unk0;
            if (var_f1_1095 > var_f30_1040) {

            } else {
                var_f1_1095 = var_f30_1040;
            }
            var_f30_1040 = var_f1_1095;
            var_r30_1046 = var_r31_1045 + 1;
            pos.unk0 = 0.0f;
            pos.unk4 = pos.unk4 + temp_f31_1051;
        } else if (temp_r5_1206 == 0x9) {
            pos.unk0 = (pos.unk0 + gFontTabWidth) - (f32) fmod((f64) pos.unk0, (f64) gFontTabWidth);
        } else {
            glyph = 1;
        }
        if (glyph != 0) {
            pos.unk0 = pos.unk0 + ((sp8 * *(f32 *) ((u8 *) M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 0), void **, 0), void **, 0x28) + (((s8) temp_r5_1206 << 5) + 0x18))) + temp_f29_1058);
        }
        if ((arg3 > 0.0f) && (pos.unk0 > arg3)) {
            var_f3_1144 = pos.unk0;
            var_r6_1145 = var_r31_1045;
            var_ctr_1147 = var_r31_1045 - var_r30_1046;
            if (var_r31_1045 > var_r30_1046) {
                do {
                    var_r0_1152 = 0;
                    temp_r4_1153 = (u8) *var_r6_1145;
                    var_f3_1144 -= (sp8 * *(f32 *) ((u8 *) M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 0), void **, 0), void **, 0x28) + (((s8) temp_r4_1153 << 5) + 0x18))) + temp_f29_1058;
                    if (((s8) temp_r4_1153 == 0x20) || ((s8) temp_r4_1153 == 9)) {
                        var_r0_1152 = 1;
                    }
                    if (var_r0_1152 != 0) {
                        var_r31_1045 = var_r6_1145 + 1;
                        break;
                    }
                    var_r6_1145 -= 1;
                    var_ctr_1147 -= 1;
                } while (var_ctr_1147 != 0);
            }
            if (var_r6_1145 == var_r30_1046) {
                var_f3_1144 = pos.unk0 - ((sp8 * *(f32 *) ((u8 *) M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 0), void **, 0), void **, 0x28) + (((s8) (u8) *var_r31_1045 << 5) + 0x18))) + temp_f29_1058);
            }
            if (var_f3_1144 > var_f30_1040) {
                var_f30_1040 = var_f3_1144;
            }
            var_r30_1046 = var_r31_1045;
            pos.unk0 = 0.0f;
            pos.unk4 = pos.unk4 + temp_f31_1051;
        }
        var_r31_1045 += 1;
        var_r29_1053 += 1;
        temp_r5_1206 = (s8) (u8) *var_r31_1045;
    }
    if (arg5 != NULL) {
        *arg5 = pos.unk4 + temp_f31_1051;
    }
    if (pos.unk0 > var_f30_1040) {
        return pos.unk0;
    }
    return var_f30_1040;
}
