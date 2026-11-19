#include "spyro/source/WindFX.h"
#include "common/Source/MKVector3.h"
#include <m2c_macros.h>

#if 0 // DRAFT: undefined identifier 'unksp134'
void WindFX::GetSwirlVelocity(const MKVector3 &arg0) {
    f64 sp148;                                      /* compiler-managed */
    f64 sp140;
    f64 sp138;                                      /* compiler-managed */
    f64 sp130;                                      /* compiler-managed */
    f64 sp128;
    f64 sp120;
    f64 sp118;
    f64 sp110;
    f64 sp108;
    f64 sp100;
    MKVector3 spF0;
    MKVector3 spE0;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    f64 spC0;
    f64 spB8;
    f64 spB0;
    f64 spA8;
    f64 spA0;
    f32 sp98;
    f64 sp90;
    f32 sp88;
    f32 sp84;
    f32 sp80;
    f32 sp78;
    f64 sp70;
    f32 sp68;
    f64 sp60;
    f32 sp58;
    f64 sp50;
    f32 sp48;
    f64 sp40;
    f32 sp38;
    f64 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f0_138;
    f32 temp_f0_332;
    f32 temp_f2_184;
    f32 temp_f2_21;
    f32 temp_f2_336;
    f32 var_f0_188;
    f32 var_f4_259;
    f32 var_f4_45;
    f32 var_f5_58;
    f64 temp_f0_162;
    f64 temp_f0_349;
    f64 temp_f0_39;
    f64 temp_f1_179;
    f64 temp_f1_25;
    f64 temp_f1_264;
    f64 temp_f1_270;
    f64 temp_f1_274;
    f64 temp_f1_339;
    f64 temp_f1_63;
    f64 temp_f1_69;
    f64 temp_f1_73;
    s32 temp_r3_293;
    s32 temp_r3_92;
    s32 var_r0_102;
    s32 var_r0_303;
    void *temp_r29_22;

    temp_f2_21 = M2C_FIELD(&arg0, f32 *, 0x10);
    temp_r29_22 = M2C_ERROR(/* Read from unset register $r5 */);
    temp_f1_25 = M2C_FIELD(&arg0, f64 *, 0) * (f64) temp_f2_21;
    sp60 = temp_f1_25;
    sp110 = temp_f1_25;
    sp68 = arg0.unk8 * temp_f2_21;
    sp140 = temp_f1_25;
    sp118 = (f64) sp68;
    sp148 = (f64) sp68;
    temp_f0_39 = M2C_FIELD(&arg0, f64 *, 0x20) - M2C_FIELD(temp_r29_22, f64 *, 0);
    sp90 = temp_f0_39;
    var_f4_45 = 0.0f;
    sp130 = temp_f0_39;
    sp98 = M2C_FIELD(&arg0, f32 *, 0x28) - M2C_FIELD(temp_r29_22, f32 *, 8);
    unksp134 = 0.0f;
    sp138 = (f64) sp98;
    var_f5_58 = ((f32) sp138 * (f32) sp138) + (((f32) sp130 * (f32) sp130) + (0.0f * 0.0f));
    if (var_f5_58 > 0.000001f) {
        if (var_f5_58 > 0.0f) {
            temp_f1_63 = __frsqrte(var_f5_58);
            temp_f1_69 = 0.5 * temp_f1_63 * -(((f64) var_f5_58 * (temp_f1_63 * temp_f1_63)) - 3.0);
            temp_f1_73 = 0.5 * temp_f1_69 * -(((f64) var_f5_58 * (temp_f1_69 * temp_f1_69)) - 3.0);
            var_f5_58 = (f32) ((f64) var_f5_58 * (0.5 * temp_f1_73 * -(((f64) var_f5_58 * (temp_f1_73 * temp_f1_73)) - 3.0)));
        } else if (var_f5_58 < M2C_BITWISE(f32, 0.0)) {
            var_f5_58 = __float_nan;
        } else {
            spC = var_f5_58;
            temp_r3_92 = M2C_BITWISE(s32, spC) & 0x7F800000;
            switch (temp_r3_92) {                   /* switch 1; irregular */
            case 0x7F800000:                        /* switch 1 */
                if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                    var_r0_102 = 1;
                } else {
                    var_r0_102 = 2;
                }
                break;
            case 0x0:                               /* switch 1 */
                if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                    var_r0_102 = 5;
                } else {
                    var_r0_102 = 3;
                }
                break;
            default:                                /* switch 1 */
                var_r0_102 = 4;
                break;
            }
            if (var_r0_102 == 1) {
                var_f5_58 = __float_nan;
            }
        }
        var_f4_45 = 1.0f / var_f5_58;
    } else {
        var_f5_58 = 0.0f;
    }
    sp130 = (f32) sp130 * var_f4_45;
    unksp134 *= var_f4_45;
    sp138 = (f32) sp138 * var_f4_45;
    temp_f0_138 = M2C_FIELD(&arg0, f32 *, 0x18);
    if (var_f5_58 > temp_f0_138) {
        sp80 = 0.0f;
        sp84 = 0.0f;
        sp88 = 0.0f;
        this->unk0 = (f64) sp80;
        this->unk8 = (f64) sp88;
        return;
    }
    spE0.operator*(var_f5_58 / temp_f0_138);
    spF0.operator*(M2C_FIELD(&arg0, f32 *, 0x10));
    temp_f0_162 = spF0 * 5.325712093e-315;
    sp50 = temp_f0_162;
    sp100 = temp_f0_162;
    sp58 = spF0.unk8 * 3.0f;
    sp108 = (f64) sp58;
    sp140 += temp_f0_162;
    sp148 = (f32) sp148 + (f32) sp108;
    temp_f1_179 = M2C_FIELD(temp_r29_22, f64 *, 0);
    sp70 = temp_f1_179 - M2C_FIELD(&arg0, f64 *, 0x20);
    temp_f2_184 = M2C_FIELD(temp_r29_22, f32 *, 8);
    var_f0_188 = 0.0f;
    sp120 = sp70;
    sp78 = temp_f2_184 - M2C_FIELD(&arg0, f32 *, 0x28);
    sp128 = (f64) sp78;
    unksp124 = 0.0f;
    sp10 = M2C_FIELD(&arg0, f32 *, 0x60) + (((f32) sp128 * M2C_FIELD(&arg0, f32 *, 0x50)) + (((f32) sp120 * M2C_FIELD(&arg0, f32 *, 0x30)) + (0.0f * M2C_FIELD(&arg0, f32 *, 0x40))));
    sp14 = M2C_FIELD(&arg0, f32 *, 0x64) + (((f32) sp128 * M2C_FIELD(&arg0, f32 *, 0x54)) + (((f32) sp120 * M2C_FIELD(&arg0, f32 *, 0x34)) + (0.0f * M2C_FIELD(&arg0, f32 *, 0x44))));
    sp18 = M2C_FIELD(&arg0, f32 *, 0x68) + (((f32) sp128 * M2C_FIELD(&arg0, f32 *, 0x58)) + (((f32) sp120 * M2C_FIELD(&arg0, f32 *, 0x38)) + (0.0f * M2C_FIELD(&arg0, f32 *, 0x48))));
    spC0 = (f64) sp10;
    spC8 = (f64) sp18;
    sp40 = spC0 + temp_f1_179;
    sp120 = sp40;
    sp48 = (f32) spC8 + temp_f2_184;
    spD0 = sp40;
    spD8 = (f64) sp48;
    sp128 = (f64) sp48;
    sp30 = sp120 - temp_f1_179;
    spB0 = sp30;
    sp38 = (f32) sp128 - temp_f2_184;
    sp130 = sp30;
    spB8 = (f64) sp38;
    sp138 = (f64) sp38;
    var_f4_259 = ((f32) sp138 * (f32) sp138) + (((f32) sp130 * (f32) sp130) + (unksp134 * unksp134));
    if (var_f4_259 > 0.000001f) {
        if (var_f4_259 > 0.0f) {
            temp_f1_264 = __frsqrte(var_f4_259);
            temp_f1_270 = 0.5 * temp_f1_264 * -(((f64) var_f4_259 * (temp_f1_264 * temp_f1_264)) - 3.0);
            temp_f1_274 = 0.5 * temp_f1_270 * -(((f64) var_f4_259 * (temp_f1_270 * temp_f1_270)) - 3.0);
            var_f4_259 = (f32) ((f64) var_f4_259 * (0.5 * temp_f1_274 * -(((f64) var_f4_259 * (temp_f1_274 * temp_f1_274)) - 3.0)));
        } else if (var_f4_259 < M2C_BITWISE(f32, 0.0)) {
            var_f4_259 = __float_nan;
        } else {
            sp8 = var_f4_259;
            temp_r3_293 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r3_293) {                  /* switch 2; irregular */
            case 0x7F800000:                        /* switch 2 */
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_303 = 1;
                } else {
                    var_r0_303 = 2;
                }
                break;
            case 0x0:                               /* switch 2 */
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_303 = 5;
                } else {
                    var_r0_303 = 3;
                }
                break;
            default:                                /* switch 2 */
                var_r0_303 = 4;
                break;
            }
            if (var_r0_303 == 1) {
                var_f4_259 = __float_nan;
            }
        }
        var_f0_188 = 1.0f / var_f4_259;
    }
    temp_f0_332 = (f32) sp138 * var_f0_188;
    sp130 = (f32) sp130 * var_f0_188;
    unksp134 *= var_f0_188;
    sp138 = temp_f0_332;
    temp_f2_336 = M2C_FIELD(&arg0, f32 *, 0x10);
    temp_f1_339 = (f64) sp130 * (f64) temp_f2_336;
    sp20 = temp_f1_339;
    sp28 = temp_f0_332 * temp_f2_336;
    spA0 = temp_f1_339;
    spA8 = (f64) sp28;
    temp_f0_349 = sp140 + spA0;
    sp140 = temp_f0_349;
    this->unk0 = temp_f0_349;
    sp148 += (f32) spA8;
    this->unk8 = (f64) sp148;
}
#endif

void WindFX::GetGlobalVelocity(const MKVector3 &arg0) {
    f32 sp10;
    f64 sp8;
    f32 temp_f2_375;

    temp_f2_375 = M2C_FIELD(&arg0, f32 *, 0x10);
    sp8 = M2C_FIELD(&arg0, f64 *, 0) * (f64) temp_f2_375;
    this->unk0 = sp8;
    sp10 = arg0.unk8 * temp_f2_375;
    this->unk8 = (f64) sp10;
}

#if 0 // DRAFT: expression syntax error
void WindFX::GetVelocity(const MKVector3 &arg0) {
    f64 sp40;
    f64 sp38;
    f64 sp28;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    s32 temp_r0_401;

    sp10 = 0.0f;
    temp_r0_401 = M2C_FIELD(&arg0, s32 *, 0x14);
    sp8 = 0.0f;
    spC = 0.0f;
    sp40 = (f64) sp10;
    sp38 = (f64) sp8;
    switch (temp_r0_401) {                          /* irregular */
    case 0:
        sp28.GetGlobalVelocity(arg0);
        sp38 = sp28;
        sp40 = sp30;
        break;
    case 1:
        sp18.GetSwirlVelocity(arg0);
        sp38 = sp18;
        sp40 = sp20;
        break;
    }
    this->unk0 = sp38;
    this->unk8 = sp40;
}
#endif

void WindFX::Init(int arg0, float arg1, const MKVector3 &arg2, const MKVector3 &arg3) {
    this->unk14 = arg0;
    this->unk10 = arg1;
    this->unk20 = M2C_FIELD(&arg2, f64 *, 0);
    this->unk28 = M2C_FIELD(&arg2, f64 *, 8);
    this->unk0 = M2C_FIELD(&arg3, f64 *, 0);
    this->unk8 = M2C_FIELD(&arg3, f64 *, 8);
}
