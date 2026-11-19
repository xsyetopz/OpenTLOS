s32 strnicmp(const char *arg0, const char *arg1, int arg2) {
    extern u8 __lower_map[];
    s8 *var_r3;
    s8 *var_r4;
    s32 var_ctr;
    s8 var_r6;
    s8 var_r0;
    u8 temp_r0_15;
    u8 temp_r0_28;

    var_r3 = (s8 *) arg0;
    var_r4 = (s8 *) arg1;
    var_ctr = arg2;
    if (arg2 > 0) {
        do {
            temp_r0_15 = (u8) *var_r3;
            var_r3 += 1;
            if ((s8) temp_r0_15 == -1) {
                var_r6 = -1;
            } else {
                var_r6 = (s8) __lower_map[temp_r0_15];
            }
            temp_r0_28 = (u8) *var_r4;
            var_r4 += 1;
            if ((s8) temp_r0_28 == -1) {
                var_r0 = -1;
            } else {
                var_r0 = (s8) __lower_map[temp_r0_28];
            }
            if (var_r6 < var_r0) {
                return -1;
            }
            if (var_r6 > var_r0) {
                return 1;
            }
            if (var_r6 == 0) {
                return 0;
            }
        } while (--var_ctr != 0);
    }
    return 0;
}
