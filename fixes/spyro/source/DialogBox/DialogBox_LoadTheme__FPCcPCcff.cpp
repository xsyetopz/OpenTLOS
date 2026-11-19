s8 *DialogBox_LoadTheme(const char *arg0, const char *arg1, float arg2, float arg3) {
    MKResource *temp_ret_667;
    MKResource *temp_ret_679;
    MKResource *temp_ret_687;
    f32 temp_f30_632;
    f32 var_f1_0;
    s32 var_r29_658;
    s32 var_r31_660;
    s32 var_r3_638;
    s32 var_r6_627;
    s8 *temp_r5_641;
    s8 *var_r28_637;
    s8 *var_r4_636;

    var_f1_0 = arg2;
    var_r6_627 = 0;
    temp_f30_632 = var_f1_0;
    var_r4_636 = themes;
    var_r28_637 = NULL;
    var_r3_638 = 0;
loop_4:
    if ((var_r6_627 < 2) && (var_r28_637 == NULL)) {
        temp_r5_641 = &themes[var_r3_638];
        if ((u32) M2C_FIELD(temp_r5_641, u32 *, 0x1C) == 0U) {
            var_r28_637 = temp_r5_641;
        }
        var_r6_627 += 1;
        var_r3_638 += 0x20;
        goto loop_4;
    }
    if (arg0 != NULL) {
        var_r29_658 = 0;
        var_r31_660 = 0;
        do {
            temp_ret_667 = MKMaterial_Create((const char *) Str_Printf((const char *) (lit_stringBase0 + 0x12), var_r29_658 + 1, arg0, var_f1_0));
            var_r29_658 += 1;
            M2C_FIELD(var_r28_637, MKResource **, var_r31_660) = temp_ret_667;
            var_r31_660 += 4;
        } while (var_r29_658 < 3);
        temp_ret_679 = MKMaterial_Create((const char *) Str_Printf((const char *) (lit_stringBase0 + 0x25), arg0, var_f1_0));
        M2C_FIELD(var_r28_637, MKResource **, 0xC) = temp_ret_679;
        temp_ret_687 = MKMaterial_Create((const char *) Str_Printf((const char *) (lit_stringBase0 + 0x37), arg0, var_f1_0));
        var_r4_636 = (s8 *) temp_ret_687;
        M2C_FIELD(var_r28_637, MKResource **, 0x10) = temp_ret_687;
    }
    M2C_FIELD(var_r28_637, f32 *, 0x14) = temp_f30_632;
    M2C_FIELD(var_r28_637, f32 *, 0x18) = arg3;
    M2C_FIELD(var_r28_637, MKFont **, 0x1C) = ((MKFont *) arg1)->Create((const char *) var_r4_636);
    return var_r28_637;
}
