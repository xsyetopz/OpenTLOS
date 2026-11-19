#include "spyro/source/KDInput.h"
#include "common/Source/MKVector3.h"
#include "unplaced_enums.h"
#include "common/Source/MKRumble.h"
#include "spyro/source/KDSound.h"
#include <m2c_macros.h>

extern M2C_UNK gb;

#if 0 // DRAFT: undefined identifier 'sp10'
f32 KDInput::RumblePlay3D(float arg0, float arg1, float arg2, MKVector3 *arg3, float arg4, char arg5, float arg6, bool arg7) {
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f64 sp20;
    f32 sp18;
    f32 sp8;
    f32 temp_f26_164;
    f32 temp_f27_166;
    f32 temp_f28_167;
    f32 var_f26_154;
    f32 var_f4_89;
    f64 temp_f1_102;
    f64 temp_f1_92;
    f64 temp_f1_98;
    s32 temp_r3_121;
    s32 var_r0_131;
    void *temp_r3_65;

    if ((arg7 == 0) && (KDSound_IsChronoSoundWarpEnabled() != 0) && (M2C_FIELD(&gb, f32 *, 0x2D0) != 1.0f)) {
        return 0.0f;
    }
    if ((arg3 == NULL) || (arg2 == 0.0f) || ((arg0 == 0.0f) && (arg1 == 0.0f))) {
        return -1.0f;
    }
    temp_r3_65 = M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 8);
    sp20 = M2C_FIELD(temp_r3_65, f64 *, 0x30);
    sp28 = M2C_FIELD(temp_r3_65, f64 *, 0x38);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r29, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    sp30 = sp10;
    sp18 = (f32) sp28 - arg3->unk8;
    sp38 = (f64) sp18;
    var_f4_89 = ((f32) sp38 * (f32) sp38) + (((f32) sp30 * (f32) sp30) + (unksp34 * unksp34));
    if (var_f4_89 > 0.0f) {
        temp_f1_92 = __frsqrte(var_f4_89);
        temp_f1_98 = 0.5 * temp_f1_92 * -(((f64) var_f4_89 * (temp_f1_92 * temp_f1_92)) - 3.0);
        temp_f1_102 = 0.5 * temp_f1_98 * -(((f64) var_f4_89 * (temp_f1_98 * temp_f1_98)) - 3.0);
        var_f4_89 = (f32) ((f64) var_f4_89 * (0.5 * temp_f1_102 * -(((f64) var_f4_89 * (temp_f1_102 * temp_f1_102)) - 3.0)));
    } else if (var_f4_89 < M2C_BITWISE(f32, 0.0)) {
        var_f4_89 = __float_nan;
    } else {
        sp8 = var_f4_89;
        temp_r3_121 = M2C_BITWISE(s32, sp8) & 0x7F800000;
        switch (temp_r3_121) {                      /* irregular */
        case 0x7F800000:
            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                var_r0_131 = 1;
            } else {
                var_r0_131 = 2;
            }
            break;
        case 0x0:
            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                var_r0_131 = 5;
            } else {
                var_r0_131 = 3;
            }
            break;
        default:
            var_r0_131 = 4;
            break;
        }
        if (var_r0_131 == 1) {
            var_f4_89 = __float_nan;
        }
    }
    var_f26_154 = -((0.01f * var_f4_89) - arg4);
    if (var_f26_154 < 0.0f) {
        var_f26_154 = 0.0f;
    } else if (var_f26_154 > arg4) {
        var_f26_154 = arg4;
    }
    temp_f26_164 = var_f26_154 / arg4;
    temp_f27_166 = arg0 * temp_f26_164;
    temp_f28_167 = arg1 * temp_f26_164;
    if ((temp_f27_166 != 0.0f) || (temp_f28_167 != 0.0f)) {
        ((KDInput *) (M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), KDInput *(**)(void **), 0x40)(M2C_FIELD(&gb, void ***, 0))))->RumblePlay(temp_f27_166, temp_f28_167, arg2, arg5, arg6, arg7);
    }
    return temp_f26_164;
}
#endif

void KDInput::RumbleStop() {
    MKRumble_Stop((MKInputDevices) this->unk0);
}

void KDInput::RumblePlay(float arg0, float arg1, float arg2, char arg3, float arg4, bool arg5) {
    if ((arg5 != 0) || (KDSound_IsChronoSoundWarpEnabled() == 0) || (M2C_FIELD(&gb, f32 *, 0x2D0) == 1.0f)) {
        MKRumble_Play((MKInputDevices) this->unk0, arg0, arg1, arg2, arg3, arg4);
    }
}
