s32 Util_WildcardPatternMatch(const char *arg0, const char *arg1) {
    s32 var_r29_26;
    s32 var_r5_27;
    s8 *temp_r30_23;
    s8 *temp_r4_32;
    s8 *var_r23_45;
    s8 *var_r28_15;
    s8 *var_r3_46;
    u32 temp_r31_22;
    u8 temp_r3_33;
    u8 temp_r4_52;
    u8 var_r24_83;
    u8 var_r25_66;
    u8 var_r26_69;
    u8 var_r26_86;

    var_r28_15 = (signed char *) (arg1);
    if ((var_r28_15 != NULL) && ((s8) (u8) *var_r28_15 != 0)) {
        temp_r31_22 = strlen(arg0);
        temp_r30_23 = (signed char *) (&arg0[temp_r31_22]);
loop_33:
        if ((s8) (u8) *var_r28_15 == 0) {
            goto block_34;
        }
        var_r29_26 = 0;
        var_r5_27 = 0;
loop_5:
        temp_r4_32 = &var_r28_15[var_r5_27];
        temp_r3_33 = (u8) *temp_r4_32;
        if (((s8) temp_r3_33 != 0) && ((s8) temp_r3_33 != 0x3B) && ((s8) temp_r3_33 != 0x2A)) {
            var_r5_27 += 1;
            goto loop_5;
        }
        if ((s8) temp_r3_33 == 0x2A) {
            var_r23_45 = temp_r4_32 + 1;
            var_r3_46 = var_r23_45;
loop_11:
            temp_r4_52 = (u8) *var_r3_46;
            if ((s8) temp_r4_52 != 0) {
                if ((s8) temp_r4_52 == 0x3B) {

                } else {
                    var_r29_26 += 1;
                    var_r3_46 += 1;
                    goto loop_11;
                }
            }
        } else {
            var_r23_45 = temp_r4_32;
            var_r29_26 = 0;
        }
        var_r25_66 = 1;
        if (var_r5_27 != 0) {
            var_r26_69 = 0;
            if (((s32) temp_r31_22 >= var_r5_27) && (strnicmp((const char *) var_r28_15, arg0, var_r5_27) == 0)) {
                var_r26_69 = 1;
            }
            if (var_r26_69 == 0) {
                var_r25_66 = 0;
            }
        }
        var_r24_83 = 1;
        if (var_r29_26 != 0) {
            var_r26_86 = 0;
            if (((s32) temp_r31_22 >= var_r29_26) && (strnicmp((const char *) var_r23_45, (const char *) (temp_r30_23 - var_r29_26), var_r29_26) == 0)) {
                var_r26_86 = 1;
            }
            if (var_r26_86 == 0) {
                var_r24_83 = 0;
            }
        }
        if ((var_r25_66 != 0) && (var_r24_83 != 0)) {
            return 1;
        }
        var_r28_15 = &var_r28_15[&var_r23_45[var_r29_26] - var_r28_15];
loop_32:
        if ((s32) (u8) *var_r28_15 == 0x3B) {
            var_r28_15 += 1;
            goto loop_32;
        }
        goto loop_33;
    }
block_34:
    return 0;
}
