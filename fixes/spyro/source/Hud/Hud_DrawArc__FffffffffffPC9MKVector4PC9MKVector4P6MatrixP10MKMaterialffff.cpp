void Hud_DrawArc(float arg0, float arg1, float arg2, float arg3, float arg4, float arg5, float arg6, float arg7, float arg8, float arg9, const MKVector4 *arg10, const MKVector4 *arg11, Matrix *arg12, MKMaterial *arg13, float arg14, float arg15, float arg16, float arg17) {
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f16_118;
    f32 temp_f16_126;
    f32 temp_f29_70;
    f32 var_f1_53;
    s32 var_r28_103;
    s32 var_r29_77;

    var_f1_53 = -arg3;
    if (arg2 > var_f1_53) {
        var_f1_53 = arg2;
    }
    temp_f29_70 = arg8 - arg6;
    var_r29_77 = (s32) ((temp_f29_70 / 6.2831855f) * var_f1_53);
    if (lit_679 > var_r29_77) {
        var_r29_77 = lit_679;
    }
    MKMaterial_SetMaterial(arg13);
    MKPrimitive(0xC, arg13 == NULL ? 3 : 1);
    if (arg12 != NULL) {
        MKSetMatrix(*arg12);
    }
    MKBegin((var_r29_77 + 1) * 2);
    var_r28_103 = 0;
    while (var_r28_103 <= var_r29_77) {
        temp_f16_118 = (f32) var_r28_103 / (f32) var_r29_77;
        _table_sincosf((temp_f16_118 * temp_f29_70) + arg6, sp14, spC);
        _table_sincosf((temp_f16_118 * (arg9 - arg7)) + arg7, sp10, sp8);
        temp_f16_126 = ((arg16 - arg14) * temp_f16_118) + arg14;
        if (arg11 != NULL) {
            MKSetColorV(*arg11);
        }
        if (arg13 != NULL) {
            MKSetTexCoord1F(temp_f16_126, arg17);
        }
        MKSetPositionF((sp10 * arg4) + arg0, (sp8 * arg5) + arg1, 0.0f);
        if (arg10 != NULL) {
            MKSetColorV(*arg10);
        }
        if (arg13 != NULL) {
            MKSetTexCoord1F(temp_f16_126, arg15);
        }
        MKSetPositionF((sp14 * arg2) + arg0, (spC * arg3) + arg1, 0.0f);
        var_r28_103 += 1;
    }
    MKEnd();
    MKEndPrimitive();
}
