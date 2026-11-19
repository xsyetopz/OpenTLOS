#include "spyro/source/KDRandom.h"
#include "common/Source/MKVector3.h"
#include "common/Source/StdMath.h"
#include <m2c_macros.h>

extern s32 gViewSeed;

void KDRand_Box(float arg0) {
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f29_20;
    f32 temp_f30_24;
    f32 temp_f31_29;
    void *temp_r31_18;

    temp_r31_18 = M2C_ERROR(/* Read from unset register $r3 */);
    temp_f29_20 = -arg0;
    temp_f30_24 = MKRand_Float((int *) &gViewSeed, temp_f29_20, arg0);
    temp_f31_29 = MKRand_Float((int *) &gViewSeed, temp_f29_20, arg0);
    sp8 = MKRand_Float((int *) &gViewSeed, temp_f29_20, arg0);
    spC = temp_f31_29;
    sp10 = temp_f30_24;
    M2C_FIELD(temp_r31_18, f64 *, 0) = (f64) sp8;
    M2C_FIELD(temp_r31_18, f64 *, 8) = (f64) sp10;
}

#if 0 // DRAFT: illegal function overloading
void KDRand_Vector(const MKVector3 &arg1, const MKVector3 &arg2) {
    MKVector3 result;
    MKVector3 *sret = &result;
    f32 sp10;
    f32 spC;
    f32 sp8;

    sp8 = MKRand_Float((int *) &gViewSeed, arg1.unk0, arg2.unk0);
    spC = MKRand_Float((int *) &gViewSeed, arg1.unk4, arg2.unk4);
    sp10 = MKRand_Float((int *) &gViewSeed, arg1.unk8, arg2.unk8);
    M2C_FIELD(sret, f64 *, 0) = (f64) sp8;
    M2C_FIELD(sret, f64 *, 8) = (f64) sp10;
    return result;
}
#endif

#if 0 // DRAFT: illegal function overloading
void KDRand_UnitVectorXZ() {
    MKVector3 result;
    MKVector3 *sret = &result;
    f32 sp10;
    f32 spC;
    f32 sp8;

    _table_sincosf(MKRand_Float((int *) &gViewSeed, 0.0f, 6.2831855f), sp8, sp10);
    spC = 0.0f;
    sp10 = -sp10;
    M2C_FIELD(sret, f64 *, 0) = (f64) sp8;
    M2C_FIELD(sret, f64 *, 8) = (f64) sp10;
    return result;
}
#endif

#if 0 // DRAFT: illegal function overloading
void KDRand_UnitVector() {
    MKVector3 result;
    MKVector3 *sret = &result;
    f64 sp28;                                       /* compiler-managed */
    f64 sp20;
    MKVector3 sp10;
    f32 sp8;
    f32 temp_f1_136;
    f32 temp_f5_139;
    f32 var_f31_158;
    f64 temp_f0_206;
    f64 temp_f2_142;
    f64 temp_f2_148;
    f64 temp_f2_152;
    s32 temp_r3_171;
    s32 var_r0_181;

    sp10 = KDRand_UnitVectorXZ();
    *(MKVector3 *) &sp20 = sp10;
    temp_f1_136 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
    temp_f5_139 = -((temp_f1_136 * temp_f1_136) - 1.0f);
    if (temp_f5_139 > 0.0f) {
        temp_f2_142 = __frsqrte(temp_f5_139);
        temp_f2_148 = 0.5 * temp_f2_142 * -(((f64) temp_f5_139 * (temp_f2_142 * temp_f2_142)) - 3.0);
        temp_f2_152 = 0.5 * temp_f2_148 * -(((f64) temp_f5_139 * (temp_f2_148 * temp_f2_148)) - 3.0);
        var_f31_158 = (f32) ((f64) temp_f5_139 * (0.5 * temp_f2_152 * -(((f64) temp_f5_139 * (temp_f2_152 * temp_f2_152)) - 3.0)));
    } else if (temp_f5_139 < M2C_BITWISE(f32, 0.0)) {
        var_f31_158 = __float_nan;
    } else {
        sp8 = temp_f5_139;
        temp_r3_171 = M2C_BITWISE(s32, sp8) & 0x7F800000;
        switch (temp_r3_171) {                      /* irregular */
        case 0x7F800000:
            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                var_r0_181 = 1;
            } else {
                var_r0_181 = 2;
            }
            break;
        case 0x0:
            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                var_r0_181 = 5;
            } else {
                var_r0_181 = 3;
            }
            break;
        default:
            var_r0_181 = 4;
            break;
        }
        if (var_r0_181 == 1) {
            var_f31_158 = __float_nan;
        } else {
            var_f31_158 = temp_f5_139;
        }
    }
    temp_f0_206 = sp20 * (f64) var_f31_158;
    sp20 = temp_f0_206;
    (*(f32 *) ((u8 *) &sp20 + 0x4)) = temp_f1_136;
    sp28 = (f32) sp28 * var_f31_158;
    M2C_FIELD(sret, f64 *, 0) = temp_f0_206;
    M2C_FIELD(sret, f64 *, 8) = (f64) sp28;
    return result;
}
#endif

f32 KDRand_Gaussian() {
    f32 temp_f31_255;
    f32 var_f30_257;
    f64 temp_f3_238;
    f64 temp_f3_245;
    f64 temp_f3_249;

    temp_f3_238 = __frsqrte(7.5);
    temp_f3_245 = 0.5 * temp_f3_238 * -((7.5 * (temp_f3_238 * temp_f3_238)) - 3.0);
    temp_f3_249 = 0.5 * temp_f3_245 * -((7.5 * (temp_f3_245 * temp_f3_245)) - 3.0);
    temp_f31_255 = (f32) (7.5 * (0.5 * temp_f3_249 * -((7.5 * (temp_f3_249 * temp_f3_249)) - 3.0)));
    var_f30_257 = MKRand_Float((int *) &gViewSeed, 0.0f, 1.0f);
    if (MKRand_Float((int *) &gViewSeed, 0.0f, 1.0f) > (1.0f + ((var_f30_257 * (2.0f * var_f30_257 * var_f30_257)) - (3.0f * var_f30_257 * var_f30_257)))) {
        var_f30_257 -= 1.0f;
    }
    return var_f30_257 * temp_f31_255;
}

void KDRand_SetSeed(int arg0) {
    gViewSeed = arg0;
}
