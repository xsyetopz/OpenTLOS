s32 MKFont_GetNumRenderableChars(const char *arg0, int arg1) {
    s32 var_r7;
    const char *var_r6;
    s8 temp_r5;
    u8 var_r0;

    var_r7 = 0;
    var_r6 = arg0;
    while (((s8) (u8) *var_r6 != 0) && ((u32) (var_r6 - arg0) < (u32) arg1)) {
        temp_r5 = (s8) (u8) *var_r6;
        if (temp_r5 == 0x3C) {
            var_r7 += 1;
        } else {
            var_r0 = 0;
            if ((temp_r5 == 0x20) || (temp_r5 == 9) || (temp_r5 == 0xA)) {
                var_r0 = 1;
            }
            if (var_r0 == 0) {
                var_r7 += 1;
            }
        }
        var_r6 += 1;
    }
    return var_r7;
}
