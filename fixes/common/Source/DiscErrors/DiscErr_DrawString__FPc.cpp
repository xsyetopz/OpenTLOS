void DiscErr_DrawString(char *arg0) {
    char sp8[32];
    s16 var_r29_27;
    s32 temp_r3_30;
    char *temp_r3_59;
    char *var_r30_35;
    char *var_r31_20;
    u32 temp_r26_66;
    s32 temp_ret_76;
    u8 temp_r4_43;
    u8 temp_r5_41;
    extern u8 __ctype_map[];

    MKInput_Update();
    VIWaitForRetrace();
    XFONTClearScreen(7U);
    var_r31_20 = arg0;
    var_r29_27 = 0xB - (((u32) strlen(arg0) / 24) / 2);
loop_1:
    temp_r3_30 = (s32) strlen(var_r31_20);
    if (temp_r3_30 > 0x18) {
        var_r30_35 = var_r31_20 + 0x18;
loop_4:
        temp_r5_41 = (u8) *var_r30_35;
        temp_r4_43 = __ctype_map[temp_r5_41];
        if ((temp_r4_43 & 0xD0) || (temp_r4_43 & 8) || (temp_r5_41 > 0xC0U)) {
            if (var_r30_35 <= var_r31_20) {

            } else {
                var_r30_35 -= 1;
                goto loop_4;
            }
        }
    } else {
        var_r30_35 = &var_r31_20[temp_r3_30];
    }
    temp_r3_59 = strchr(var_r31_20, 0xA);
    if ((temp_r3_59 != NULL) && (temp_r3_59 < var_r30_35)) {
        var_r30_35 = temp_r3_59;
    }
    temp_r26_66 = (u32) (var_r30_35 - var_r31_20);
    strncpy(sp8, var_r31_20, temp_r26_66);
    sp8[temp_r26_66] = 0;
    strupr((s8 *) sp8);
    temp_ret_76 = (s32) strlen(sp8);
    XFONTPrintf((s16) (0x14 - (temp_ret_76 / 2)), var_r29_27, sp8);
    if (&var_r31_20[temp_r3_30] > var_r30_35) {
        var_r31_20 = var_r30_35 + 1;
        var_r29_27 += 2;
        if ((var_r31_20 != NULL) && ((s8) *var_r31_20 != 0)) {
            goto loop_1;
        }
    }
    DCFlushRange(((void *(*)(void)) GPGetCurrentBuffer)(), 0xA5000U);
}
