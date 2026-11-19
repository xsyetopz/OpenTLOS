#include "common/Source/MKWind.h"
#include "common/Source/MKVector4.h"
#include "common/Source/StdMath.h"
#include <m2c_macros.h>

#if 0 // DRAFT: identifier '_sinTable' redeclared
f64 pow(f32, f64);                                  /* extern */
extern M2C_UNK _sinTable;
#endif
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern MKWind wind;

#if 0 // DRAFT: pointer/array required
void MKWind_GetVelocity(const MKVector3 &arg0) {
    f64 sp18;                                       /* compiler-managed */
    f64 sp10;                                       /* compiler-managed */
    f32 sp8;                                        /* compiler-managed */
    MKWind *temp_r4_31;
    f32 temp_f0_33;
    f32 temp_f6_60;
    s32 temp_r0_51;
    s32 var_ctr_29;
    s32 var_r5_22;

    sp10 = M2C_FIELD(&wind, f64 *, 0x140);
    var_r5_22 = 0;
    sp18 = M2C_FIELD(&wind, f64 *, 0x148);
    var_ctr_29 = 8;
    do {
        temp_r4_31 = &(&wind)[var_r5_22];
        temp_f0_33 = M2C_FIELD(temp_r4_31, f32 *, 4);
        var_r5_22 += 0x28;
        temp_r0_51 = (s32) (325.9493f * ((M2C_FIELD(&wind, f32 *, 0x190) * M2C_FIELD(temp_r4_31, f32 *, 0x20)) + ((M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), f32 *, 8) * M2C_FIELD(temp_r4_31, f32 *, 8)) + ((*M2C_ERROR(/* Read from unset register $r4 */) * M2C_FIELD(temp_r4_31, f32 *, 0)) + (M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), f32 *, 4) * temp_f0_33)))));
        sp8 = *(&_sinTable + ((temp_r0_51 * 4) & 0xFFC));
        sp8 = M2C_BITWISE(s32, sp8) | ((temp_r0_51 << 0x15) & 0x80000000);
        temp_f6_60 = M2C_FIELD(temp_r4_31, f32 *, 0x24) * M2C_BITWISE(f32, sp8);
        sp10 = (temp_f6_60 * M2C_FIELD(temp_r4_31, f32 *, 0x10)) + (f32) sp10;
        unksp14 += temp_f6_60 * M2C_FIELD(temp_r4_31, f32 *, 0x14);
        sp18 = (temp_f6_60 * M2C_FIELD(temp_r4_31, f32 *, 0x18)) + (f32) sp18;
        var_ctr_29 -= 1;
    } while (var_ctr_29 != 0);
    M2C_FIELD(&arg0, f64 *, 0) = (f64) sp10;
    M2C_FIELD(&arg0, f64 *, 8) = (f64) sp18;
}
#endif

#if 0 // DRAFT: undefined identifier '__float_nan'
void MKWind::Init(float arg0, float arg1, float arg2, float arg3, const MKVector3 &arg4, float arg5) {
    f64 sp38;
    f64 sp30;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    f32 spC;
    f32 sp8;
    MKWind *temp_r27_273;
    MKWind *temp_r5_371;
    MKWind *temp_r7_372;
    f32 temp_f0_347;
    f32 temp_f21_297;
    f32 temp_f22_299;
    f32 temp_f22_302;
    f32 temp_f23_295;
    f32 temp_f23_305;
    f32 temp_f24_308;
    f32 temp_f24_331;
    f32 temp_f24_343;
    f32 temp_f26_269;
    f32 temp_f29_270;
    f32 temp_f30_117;
    f32 temp_f4_125;
    f32 temp_f4_375;
    f32 temp_f5_373;
    f32 var_f1_128;
    f32 var_f24_281;
    f32 var_f28_111;
    f32 var_f2_120;
    f32 var_f3_116;
    f32 var_f5_209;
    f64 temp_f6_131;
    f64 temp_f6_137;
    f64 temp_f6_141;
    f64 temp_f6_193;
    f64 temp_f6_199;
    f64 temp_f6_203;
    s32 temp_r0_257;
    s32 temp_r4_160;
    s32 temp_r4_222;
    s32 var_ctr_126;
    s32 var_ctr_369;
    s32 var_r0_170;
    s32 var_r0_232;
    s32 var_r26_267;
    s32 var_r29_268;
    s32 var_r3_121;
    s32 var_r3_365;
    s32 var_r4_367;

    var_f28_111 = 6.2831855f / arg1;
    var_f3_116 = 1.0f;
    temp_f30_117 = (f32) pow(arg1 / arg0, 0.125);
    var_f2_120 = 0.0f;
    var_r3_121 = 0;
    temp_f4_125 = arg1 / (64.0f - 1.0f);
    var_ctr_126 = 8;
    do {
        var_f1_128 = (arg1 * var_f3_116) + temp_f4_125;
        if (var_f1_128 > 0.0f) {
            temp_f6_131 = __frsqrte(var_f1_128);
            temp_f6_137 = 0.5 * temp_f6_131 * -(((f64) var_f1_128 * (temp_f6_131 * temp_f6_131)) - 3.0);
            temp_f6_141 = 0.5 * temp_f6_137 * -(((f64) var_f1_128 * (temp_f6_137 * temp_f6_137)) - 3.0);
            var_f1_128 = (f32) ((f64) var_f1_128 * (0.5 * temp_f6_141 * -(((f64) var_f1_128 * (temp_f6_141 * temp_f6_141)) - 3.0)));
        } else if (var_f1_128 < M2C_BITWISE(f32, 0.0)) {
            var_f1_128 = __float_nan;
        } else {
            spC = var_f1_128;
            temp_r4_160 = M2C_BITWISE(s32, spC) & 0x7F800000;
            switch (temp_r4_160) {                  /* switch 1; irregular */
            case 0x7F800000:                        /* switch 1 */
                if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                    var_r0_170 = 1;
                } else {
                    var_r0_170 = 2;
                }
                break;
            case 0x0:                               /* switch 1 */
                if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                    var_r0_170 = 5;
                } else {
                    var_r0_170 = 3;
                }
                break;
            default:                                /* switch 1 */
                var_r0_170 = 4;
                break;
            }
            if (var_r0_170 == 1) {
                var_f1_128 = __float_nan;
            }
        }
        if (temp_f4_125 > 0.0f) {
            temp_f6_193 = __frsqrte(temp_f4_125);
            temp_f6_199 = 0.5 * temp_f6_193 * -(((f64) temp_f4_125 * (temp_f6_193 * temp_f6_193)) - 3.0);
            temp_f6_203 = 0.5 * temp_f6_199 * -(((f64) temp_f4_125 * (temp_f6_199 * temp_f6_199)) - 3.0);
            var_f5_209 = (f32) ((f64) temp_f4_125 * (0.5 * temp_f6_203 * -(((f64) temp_f4_125 * (temp_f6_203 * temp_f6_203)) - 3.0)));
        } else if (temp_f4_125 < M2C_BITWISE(f32, 0.0)) {
            var_f5_209 = __float_nan;
        } else {
            sp8 = temp_f4_125;
            temp_r4_222 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r4_222) {                  /* switch 2; irregular */
            case 0x7F800000:                        /* switch 2 */
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_232 = 1;
                } else {
                    var_r0_232 = 2;
                }
                break;
            case 0x0:                               /* switch 2 */
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_232 = 5;
                } else {
                    var_r0_232 = 3;
                }
                break;
            default:                                /* switch 2 */
                var_r0_232 = 4;
                break;
            }
            if (var_r0_232 == 1) {
                var_f5_209 = __float_nan;
            } else {
                var_f5_209 = temp_f4_125;
            }
        }
        var_f3_116 /= temp_f30_117;
        temp_r0_257 = var_r3_121 + 0x24;
        var_r3_121 += 0x28;
        this[temp_r0_257] = (f32) (var_f1_128 - var_f5_209);
        var_f2_120 += this[temp_r0_257];
        var_ctr_126 -= 1;
    } while (var_ctr_126 != 0);
    var_r26_267 = 0;
    var_r29_268 = 0;
    temp_f26_269 = arg5 * 1.5707964f;
    temp_f29_270 = 1.5707964f + temp_f26_269;
    do {
        temp_r27_273 = &this[var_r29_268];
        M2C_FIELD(temp_r27_273, f32 *, 0x24) = (f32) (M2C_FIELD(temp_r27_273, f32 *, 0x24) * ((arg2 / var_f2_120) / var_f28_111));
        var_f24_281 = MKRand_Float(&gViewSeed, 0.0f, 3.1415927f);
        if (MKRand_Int(&gViewSeed, 0, 2) != 0) {
            var_f24_281 += 3.1415927f;
        }
        temp_f23_295 = MKRand_Float(&gViewSeed, -0.7853982f, 0.7853982f);
        temp_f21_297 = 1.5707964f + temp_f23_295;
        temp_f22_299 = _table_sinf(1.5707964f + var_f24_281);
        temp_f22_302 = _table_sinf(temp_f21_297) * temp_f22_299;
        temp_f23_305 = _table_sinf(temp_f23_295);
        temp_f24_308 = _table_sinf(var_f24_281);
        MKVector(_table_sinf(temp_f21_297) * temp_f24_308, temp_f23_305, temp_f22_302);
        sp10 = sp20 * (f64) var_f28_111;
        M2C_FIELD(temp_r27_273, f64 *, 0) = sp10;
        sp18 = sp28 * var_f28_111;
        sp30 = sp10;
        sp38 = (f64) sp18;
        M2C_FIELD(temp_r27_273, f64 *, 8) = (f64) sp18;
        temp_f24_331 = (f32) M2C_FIELD(temp_r27_273, f64 *, 0) * _table_sinf(temp_f29_270);
        M2C_FIELD(temp_r27_273, f32 *, 0x10) = (f32) (((f32) M2C_FIELD(temp_r27_273, f64 *, 8) * -_table_sinf(temp_f26_269)) + temp_f24_331);
        M2C_FIELD(temp_r27_273, f32 *, 0x14) = (f32) M2C_FIELD(temp_r27_273, f32 *, 4);
        temp_f24_343 = (f32) M2C_FIELD(temp_r27_273, f64 *, 0) * _table_sinf(temp_f26_269);
        temp_f0_347 = var_f28_111 * arg3;
        var_r26_267 += 1;
        var_f28_111 *= temp_f30_117;
        var_r29_268 += 0x28;
        M2C_FIELD(temp_r27_273, f32 *, 0x18) = (f32) (((f32) M2C_FIELD(temp_r27_273, f64 *, 8) * _table_sinf(temp_f29_270)) + temp_f24_343);
        M2C_FIELD(temp_r27_273, f32 *, 0x20) = temp_f0_347;
    } while (var_r26_267 < 8);
    M2C_FIELD(this, f64 *, 0x140) = (f64) M2C_FIELD(&arg4, f64 *, 0);
    var_r3_365 = 0;
    M2C_FIELD(this, f64 *, 0x148) = (f64) M2C_FIELD(&arg4, f64 *, 8);
    var_r4_367 = 0;
    var_ctr_369 = 2;
    do {
        temp_r5_371 = &(&wind)[var_r4_367];
        temp_r7_372 = &this[var_r3_365];
        temp_f5_373 = M2C_FIELD(temp_r5_371, f32 *, 0x9C);
        var_r3_365 += 0x10;
        temp_f4_375 = M2C_FIELD(temp_r5_371, f32 *, 0x74);
        var_r4_367 += 0xA0;
        M2C_FIELD(temp_r7_372, f32 *, 0x150) = (f32) M2C_FIELD(temp_r5_371, f32 *, 0x24);
        M2C_FIELD(temp_r7_372, f32 *, 0x154) = (f32) M2C_FIELD(temp_r5_371, f32 *, 0x4C);
        M2C_FIELD(temp_r7_372, f32 *, 0x158) = temp_f4_375;
        M2C_FIELD(temp_r7_372, f32 *, 0x15C) = temp_f5_373;
        M2C_FIELD(temp_r7_372, f64 *, 0x170) = (f64) M2C_FIELD(&MKVector4::zero, f64 *, 0);
        M2C_FIELD(temp_r7_372, f64 *, 0x178) = (f64) M2C_FIELD(&MKVector4::zero, f64 *, 8);
        var_ctr_369 -= 1;
    } while (var_ctr_369 != 0);
    M2C_FIELD(this, f32 *, 0x190) = 0.0f;
}
#endif

#if 0 // DRAFT: illegal operand
void MKWind_Update() {
    MKWind *temp_r26_437;
    MKWind *temp_r27_439;
    MKWind *temp_r28_436;
    s32 var_r23_426;
    s32 var_r30_430;
    s32 var_r31_427;

    var_r23_426 = 0;
    var_r31_427 = 0;
    var_r30_430 = 0;
    M2C_FIELD(&wind, f32 *, 0x190) = (f32) (M2C_FIELD(&wind, f32 *, 0x190) + gUpdateTimeDelta);
    do {
        temp_r28_436 = &(&wind)[var_r31_427];
        temp_r26_437 = &(&wind + 0x170)[var_r30_430];
        temp_r27_439 = &(&wind + 0x150)[var_r30_430];
        _table_sincosf(M2C_FIELD(&wind, f32 *, 0x190) * M2C_FIELD(temp_r28_436, f32 *, 0x20), *((f32 *) temp_r26_437), *((f32 *) temp_r27_439));
        var_r23_426 += 1;
        var_r31_427 += 0x28;
        var_r30_430 += 4;
        *temp_r27_439 = (f32) (*temp_r27_439 * M2C_FIELD(temp_r28_436, f32 *, 0x24));
        *temp_r26_437 = (f32) (*temp_r26_437 * M2C_FIELD(temp_r28_436, f32 *, 0x24));
    } while (var_r23_426 < 8);
}
#endif

void MKWind_SetConstantWind(const MKVector3 &arg0) {
    M2C_FIELD(&wind, f64 *, 0x140) = (f64) M2C_FIELD(&arg0, f64 *, 0);
    M2C_FIELD(&wind, f64 *, 0x148) = (f64) M2C_FIELD(&arg0, f64 *, 8);
}

void MKWind_Set(float arg0, float arg1, float arg2, float arg3, const MKVector3 &arg4, float arg5) {
    wind.Init(arg0, arg1, arg2, arg3, arg4, arg5);
}
