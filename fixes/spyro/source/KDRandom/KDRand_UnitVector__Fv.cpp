MKVector3 KDRand_UnitVector() {
    MKVector3 result;
    MKVector3 sp10;
    f32 sp8;
    f32 temp_f1_136;
    f32 temp_f5_139;
    f32 var_f31_158;
    f64 temp_f2_142;
    f64 temp_f2_148;
    f64 temp_f2_152;
    s32 temp_r3_171;
    s32 var_r0_181;

    sp10 = KDRand_UnitVectorXZ();
    temp_f1_136 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
    temp_f5_139 = -((temp_f1_136 * temp_f1_136) - 1.0f);
    if (temp_f5_139 > 0.0f) {
        temp_f2_142 = __frsqrte(temp_f5_139);
        temp_f2_148 = 0.5 * temp_f2_142 * -(((f64) temp_f5_139 * (temp_f2_142 * temp_f2_142)) - 3.0);
        temp_f2_152 = 0.5 * temp_f2_148 * -(((f64) temp_f5_139 * (temp_f2_148 * temp_f2_148)) - 3.0);
        var_f31_158 = (f32) ((f64) temp_f5_139 * (0.5 * temp_f2_152 * -(((f64) temp_f5_139 * (temp_f2_152 * temp_f2_152)) - 3.0)));
    } else if (temp_f5_139 < M2C_BITWISE(f32, 0.0)) {
        var_f31_158 = __float_nan;
    } else {
        sp8 = temp_f5_139;
        temp_r3_171 = M2C_BITWISE(s32, sp8) & 0x7F800000;
        switch (temp_r3_171) {                      /* irregular */
        case 0x7F800000:
            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                var_r0_181 = 1;
            } else {
                var_r0_181 = 2;
            }
            break;
        case 0x0:
            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                var_r0_181 = 5;
            } else {
                var_r0_181 = 3;
            }
            break;
        default:
            var_r0_181 = 4;
            break;
        }
        if (var_r0_181 == 1) {
            var_f31_158 = __float_nan;
        } else {
            var_f31_158 = temp_f5_139;
        }
    }
    result.unk0 = sp10.unk0 * var_f31_158;
    result.unk4 = temp_f1_136;
    result.unk8 = sp10.unk8 * var_f31_158;
    return result;
}
