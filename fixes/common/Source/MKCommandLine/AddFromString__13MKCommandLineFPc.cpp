void MKCommandLine::AddFromString(char *arg0) {
    s32 var_r5_187;
    s8 *temp_r3_193;
    s8 *temp_r4_223;
    s8 *var_r3_225;
    u32 temp_r29_219;
    u32 temp_r3_186;
    u32 var_ctr_189;
    u32 var_r26_224;
    u32 var_r28_217;
    u8 temp_r0_194;
    u8 temp_r0_241;
    u8 var_r27_220;

    temp_r3_186 = strlen(arg0);
    var_r5_187 = 0;
    var_ctr_189 = temp_r3_186;
    if (temp_r3_186 > 0U) {
loop_1:
        temp_r3_193 = (signed char *) (&arg0[var_r5_187]);
        temp_r0_194 = (u8) M2C_FIELD(temp_r3_193, s8 *, 0);
        switch ((s8) temp_r0_194) {                 /* irregular */
        case 10:
        case 13:
            M2C_FIELD(temp_r3_193, s8 *, 0) = 0x20;
        default:
block_7:
            var_r5_187 += 1;
            var_ctr_189 -= 1;
            if (var_ctr_189 != 0) {
                goto loop_1;
            }
            break;
        case 47:
            if ((s32) M2C_FIELD(temp_r3_193, u8 *, 1) == 0x2F) {
                M2C_FIELD(temp_r3_193, s8 *, 0) = 0;
            } else {
                goto block_7;
            }
            break;
        }
    }
    var_r28_217 = 0U;
    temp_r29_219 = strlen(arg0);
    var_r27_220 = 0;
loop_21:
    if (var_r28_217 < temp_r29_219) {
        temp_r4_223 = (signed char *) (&arg0[var_r28_217]);
        var_r26_224 = 0U;
        var_r3_225 = temp_r4_223;
loop_13:
        if (var_r27_220 != 0) {
block_10:
            if ((s32) (u8) *var_r3_225 == 0x22) {
                var_r27_220 = var_r27_220 == 0;
            }
            var_r26_224 += 1;
            var_r3_225 += 1;
            goto loop_13;
        }
        temp_r0_241 = (u8) *var_r3_225;
        if (((s8) temp_r0_241 != 0x20) && ((s8) temp_r0_241 != 0xD) && ((s8) temp_r0_241 != 0xA) && ((u32) (var_r28_217 + var_r26_224) < temp_r29_219)) {
            goto block_10;
        }
        temp_r4_223[var_r26_224] = 0;
        if (var_r26_224 != 0U) {
            ParseArgument((char *) temp_r4_223);
        }
        var_r28_217 = var_r26_224 + var_r28_217 + 1;
        goto loop_21;
    }
}
