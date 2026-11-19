#include "common/Source/system_extras.h"
#include <m2c_macros.h>

#if 0 // DRAFT: undefined identifier '__lower_map'
s32 strnicmp(const char *arg0, const char *arg1, int arg2) {
    s32 var_ctr_11;
    s8 *var_r3_0;
    s8 *var_r4_0;
    u8 temp_r0_15;
    u8 temp_r0_28;
    u8 var_r0_34;
    u8 var_r5_20;

    var_r3_0 = (signed char *) (arg0);
    var_r4_0 = (signed char *) (arg1);
    var_ctr_11 = arg2;
    if (arg2 > 0) {
loop_1:
        temp_r0_15 = (u8) *var_r3_0;
        var_r3_0 += 1;
        if ((s8) temp_r0_15 == -1) {
            var_r5_20 = -1U;
        } else {
            var_r5_20 = *(&__lower_map + (u8) (s8) temp_r0_15);
        }
        temp_r0_28 = (u8) *var_r4_0;
        var_r4_0 += 1;
        if ((s8) temp_r0_28 == -1) {
            var_r0_34 = -1U;
        } else {
            var_r0_34 = *(&__lower_map + (u8) (s8) temp_r0_28);
        }
        if ((s8) var_r5_20 < (s8) var_r0_34) {
            return -1;
        }
        if ((s8) var_r5_20 > (s8) var_r0_34) {
            return 1;
        }
        if ((s8) var_r5_20 == 0) {
            return 0;
        }
        var_ctr_11 -= 1;
        if (var_ctr_11 == 0) {
            /* Duplicate return node #14. Try simplifying control flow for better match */
            return 0;
        }
        goto loop_1;
    }
    return 0;
}
#endif
