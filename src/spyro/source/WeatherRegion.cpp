#include "spyro/source/WeatherRegion.h"
#include "common/Source/Frustum.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "spyro/source/WeatherAshPS.h"
#include "spyro/source/WeatherConvexityPS.h"
#include "spyro/source/WeatherEmbersPS.h"
#include "spyro/source/WeatherRainPS.h"
#include "spyro/source/WeatherSnowPS.h"
#include "spyro/source/WeatherSpores.h"
#include "unplaced_templates.h"
#include "common/Source/StdMath.h"
#include <m2c_macros.h>

extern MKSceneManager *gMK;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern M2C_UNK gb;

#if 0 // DRAFT: illegal type
static s8 lit_stringBase0[0x98] = {
    0x54,
    0x79,
    0x70,
    0x65,
    0,
    0x4D,
    0x69,
    0x6E,
    0x53,
    0x63,
    0x61,
    0x6C,
    0x65,
    0,
    0x4D,
    0x61,
    0x78,
    0x53,
    0x63,
    0x61,
    0x6C,
    0x65,
    0,
    0x4D,
    0x69,
    0x6E,
    0x52,
    0x61,
    0x74,
    0x65,
    0,
    0x4D,
    0x61,
    0x78,
    0x52,
    0x61,
    0x74,
    0x65,
    0,
    0x4E,
    0x75,
    0x6D,
    0x50,
    0x65,
    0x72,
    0x45,
    0x6D,
    0x69,
    0x74,
    0,
    0x77,
    0x61,
    0x79,
    0x70,
    0x6F,
    0x69,
    0x6E,
    0x74,
    0x73,
    0,
    0x57,
    0x65,
    0x61,
    0x74,
    0x68,
    0x65,
    0x72,
    0x53,
    0x6E,
    0x6F,
    0x77,
    0x50,
    0x53,
    0,
    0x57,
    0x65,
    0x61,
    0x74,
    0x68,
    0x65,
    0x72,
    0x41,
    0x73,
    0x68,
    0x50,
    0x53,
    0,
    0x57,
    0x65,
    0x61,
    0x74,
    0x68,
    0x65,
    0x72,
    0x45,
    0x6D,
    0x62,
    0x65,
    0x72,
    0x73,
    0x50,
    0x53,
    0,
    0x57,
    0x65,
    0x61,
    0x74,
    0x68,
    0x65,
    0x72,
    0x53,
    0x70,
    0x6F,
    0x72,
    0x65,
    0x73,
    0x50,
    0x53,
    0,
    0x57,
    0x65,
    0x61,
    0x74,
    0x68,
    0x65,
    0x72,
    0x43,
    0x6F,
    0x6E,
    0x76,
    0x65,
    0x78,
    0x69,
    0x74,
    0x79,
    0x50,
    0x53,
    0,
    0x57,
    0x65,
    0x61,
    0x74,
    0x68,
    0x65,
    0x72,
    0x52,
    0x61,
    0x69,
    0x6E,
    0x50,
    0x53,
    0,
}; /* const */

u8 WeatherRegion::CalculateEmissionPointRain(MKVector3 &arg0) {
    f64 sp108;
    f64 sp100;
    f64 spF8;                                       /* compiler-managed */
    f64 spF0;                                       /* compiler-managed */
    f64 spE8;
    f64 spE0;
    f64 spD8;
    f64 spD0;
    MKVector3 spC0;
    MKVector3 spB0;
    MKVector3 spA0;
    MKVector3 sp90;
    MKVector3 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f32 sp58;
    f32 sp48;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f32 sp18;
    f32 sp8;
    f32 temp_f1_258;
    f32 temp_f2_63;
    f32 var_f4_90;
    f32 var_f5_79;
    f64 temp_f1_101;
    f64 temp_f1_105;
    f64 temp_f1_95;
    s32 temp_r3_124;
    s32 var_r0_134;
    u8 var_r31_253;
    void *temp_r30_55;
    void *temp_r31_53;
    void *temp_r3_52;

    temp_r3_52 = checked_cast<WeatherRegionDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    temp_r31_53 = temp_r3_52;
    temp_r30_55 = temp_r31_53 + 0x90;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r30, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r3, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    temp_f2_63 = M2C_FIELD(temp_r31_53, f32 *, 0x98) - M2C_FIELD(temp_r31_53, f32 *, 0xD8);
    sp100 = sp50;
    sp58 = temp_f2_63;
    sp108 = (f64) sp58;
    var_f5_79 = 0.0f;
    spF0 = M2C_FIELD(temp_r31_53, f64 *, 0x80);
    spF8 = M2C_FIELD(temp_r31_53, f64 *, 0x88);
    unkspF4 = 0.0f;
    var_f4_90 = ((f32) spF8 * (f32) spF8) + (((f32) spF0 * (f32) spF0) + (0.0f * 0.0f));
    if (var_f4_90 > 0.000001f) {
        if (var_f4_90 > 0.0f) {
            temp_f1_95 = __frsqrte(var_f4_90);
            temp_f1_101 = 0.5 * temp_f1_95 * -(((f64) var_f4_90 * (temp_f1_95 * temp_f1_95)) - 3.0);
            temp_f1_105 = 0.5 * temp_f1_101 * -(((f64) var_f4_90 * (temp_f1_101 * temp_f1_101)) - 3.0);
            var_f4_90 = (f32) ((f64) var_f4_90 * (0.5 * temp_f1_105 * -(((f64) var_f4_90 * (temp_f1_105 * temp_f1_105)) - 3.0)));
        } else if (var_f4_90 < M2C_BITWISE(f32, 0.0)) {
            var_f4_90 = __float_nan;
        } else {
            sp8 = var_f4_90;
            temp_r3_124 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r3_124) {                  /* irregular */
            case 0x7F800000:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_134 = 1;
                } else {
                    var_r0_134 = 2;
                }
                break;
            case 0x0:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_134 = 5;
                } else {
                    var_r0_134 = 3;
                }
                break;
            default:
                var_r0_134 = 4;
                break;
            }
            if (var_r0_134 == 1) {
                var_f4_90 = __float_nan;
            }
        }
        var_f5_79 = 1.0f / var_f4_90;
    }
    spF0 = (f32) spF0 * var_f5_79;
    unkspF4 *= var_f5_79;
    spF8 = (f32) spF8 * var_f5_79;
    sp80.operator*(MKRand_Float(&gViewSeed, -0.1f, 1.0f));
    sp90.operator*(2000.0f);
    spA0.operator*(2.0f);
    spB0.operator*(MKRand_Float(&gViewSeed, -1.0f, 1.0f));
    spC0.operator*(1000.0f);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r30, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    spD0 = sp10;
    sp18 = M2C_FIELD(temp_r30_55, f32 *, 8) + spC0.unk8;
    spD8 = (f64) sp18;
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    M2C_FIELD(&arg0, f64 *, 0) = sp40;
    sp48 = (f32) spD8 + spA0.unk8;
    spE0 = sp40;
    spE8 = (f64) sp48;
    M2C_FIELD(&arg0, f64 *, 8) = (f64) sp48;
    sp34 = MKRand_Float(&gViewSeed, 1500.0f, 2500.0f);
    sp30 = 0.0f;
    sp38 = 0.0f;
    sp70 = (f64) sp30;
    sp78 = (f64) sp38;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r29, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    M2C_ERROR(/* unknown instruction: psq_stx $f0, $zero, $r29, 0x0, qr0 */);
    arg0.unk8 += (f32) sp78;
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
    sp28 = (f32) sp108 * 20.0f;
    sp60 = sp20;
    sp68 = (f64) sp28;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r29, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    M2C_ERROR(/* unknown instruction: psq_stx $f0, $zero, $r29, 0x0, qr0 */);
    var_r31_253 = 0;
    arg0.unk8 += (f32) sp68;
    temp_f1_258 = arg0.unk4;
    M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
    if (temp_f1_258 == this->unk80.unk4.unk18) {
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if ((temp_f1_258 == this->unk80.unk4.unk1C) && (this->unk80.unk4.IsPointWithin(arg0) != 0)) {
            var_r31_253 = 1;
        }
    }
    if (var_r31_253 != 0) {
        return 1U;
    }
    return 0U;
}
#endif

#if 0 // DRAFT: illegal type
u8 WeatherRegion::CalculateEmissionParametersConvexity(MKVector3 &arg0, MKVector3 &arg1) {
    f64 sp198;
    f64 sp190;
    f64 sp188;                                      /* compiler-managed */
    f64 sp180;                                      /* compiler-managed */
    f64 sp178;
    f64 sp170;
    f64 sp168;                                      /* compiler-managed */
    f64 sp160;                                      /* compiler-managed */
    f64 sp158;
    f64 sp150;
    f64 sp148;
    f64 sp140;
    MKVector3 sp130;
    MKVector3 sp120;
    MKVector3 sp110;
    MKVector3 sp100;
    MKVector3 spF0;
    f64 spE8;
    f64 spE0;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    f64 spC0;
    f64 spB8;
    f64 spB0;
    f64 spA8;
    f64 spA0;
    f32 sp98;
    f32 sp88;
    f32 sp78;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp58;
    f32 sp48;
    f32 sp38;
    f32 sp28;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f1_521;
    f32 temp_f28_638;
    f32 temp_f29_666;
    f32 temp_f2_322;
    f32 var_f3_627;
    f32 var_f4_349;
    f32 var_f4_560;
    f32 var_f5_338;
    f64 temp_f1_354;
    f64 temp_f1_360;
    f64 temp_f1_364;
    f64 temp_f1_566;
    f64 temp_f1_572;
    f64 temp_f1_576;
    s32 temp_r3_383;
    s32 temp_r3_595;
    s32 var_r0_393;
    s32 var_r0_605;
    u8 var_r28_516;
    void *temp_r28_312;
    void *temp_r3_311;
    void *temp_r5_314;

    temp_r3_311 = checked_cast<WeatherRegionDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    temp_r28_312 = temp_r3_311;
    temp_r5_314 = temp_r28_312 + 0x90;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r5, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r3, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    temp_f2_322 = M2C_FIELD(temp_r28_312, f32 *, 0x98) - M2C_FIELD(temp_r28_312, f32 *, 0xD8);
    sp190 = sp90;
    sp98 = temp_f2_322;
    sp198 = (f64) sp98;
    var_f5_338 = 0.0f;
    sp180 = M2C_FIELD(temp_r28_312, f64 *, 0x80);
    sp188 = M2C_FIELD(temp_r28_312, f64 *, 0x88);
    unksp184 = 0.0f;
    var_f4_349 = ((f32) sp188 * (f32) sp188) + (((f32) sp180 * (f32) sp180) + (0.0f * 0.0f));
    if (var_f4_349 > 0.000001f) {
        if (var_f4_349 > 0.0f) {
            temp_f1_354 = __frsqrte(var_f4_349);
            temp_f1_360 = 0.5 * temp_f1_354 * -(((f64) var_f4_349 * (temp_f1_354 * temp_f1_354)) - 3.0);
            temp_f1_364 = 0.5 * temp_f1_360 * -(((f64) var_f4_349 * (temp_f1_360 * temp_f1_360)) - 3.0);
            var_f4_349 = (f32) ((f64) var_f4_349 * (0.5 * temp_f1_364 * -(((f64) var_f4_349 * (temp_f1_364 * temp_f1_364)) - 3.0)));
        } else if (var_f4_349 < M2C_BITWISE(f32, 0.0)) {
            var_f4_349 = __float_nan;
        } else {
            spC = var_f4_349;
            temp_r3_383 = M2C_BITWISE(s32, spC) & 0x7F800000;
            switch (temp_r3_383) {                  /* switch 1; irregular */
            case 0x7F800000:                        /* switch 1 */
                if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                    var_r0_393 = 1;
                } else {
                    var_r0_393 = 2;
                }
                break;
            case 0x0:                               /* switch 1 */
                if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                    var_r0_393 = 5;
                } else {
                    var_r0_393 = 3;
                }
                break;
            default:                                /* switch 1 */
                var_r0_393 = 4;
                break;
            }
            if (var_r0_393 == 1) {
                var_f4_349 = __float_nan;
            }
        }
        var_f5_338 = 1.0f / var_f4_349;
    }
    sp180 = (f32) sp180 * var_f5_338;
    unksp184 *= var_f5_338;
    sp188 = (f32) sp188 * var_f5_338;
    sp170 = M2C_FIELD(temp_r5_314, f64 *, 0);
    sp178 = M2C_FIELD(temp_r5_314, f64 *, 8);
    spF0.operator*(MKRand_Float(&gViewSeed, -0.1f, 1.0f));
    sp100.operator*(2000.0f);
    sp110.operator*(2.0f);
    sp120.operator*(MKRand_Float(&gViewSeed, -1.0f, 1.0f));
    sp130.operator*(1000.0f);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    sp140 = sp20;
    sp28 = (f32) sp178 + sp130.unk8;
    sp148 = (f64) sp28;
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    M2C_FIELD(&arg0, f64 *, 0) = sp70;
    sp78 = (f32) sp148 + sp110.unk8;
    sp150 = sp70;
    sp158 = (f64) sp78;
    M2C_FIELD(&arg0, f64 *, 8) = (f64) sp78;
    sp64 = MKRand_Float(&gViewSeed, -500.0f, 1500.0f);
    sp60 = 0.0f;
    sp68 = 0.0f;
    spE0 = (f64) sp60;
    spE8 = (f64) sp68;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r30, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    M2C_ERROR(/* unknown instruction: psq_stx $f0, $zero, $r30, 0x0, qr0 */);
    arg0.unk8 += (f32) spE8;
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
    sp58 = (f32) sp198 * 20.0f;
    spD0 = sp50;
    spD8 = (f64) sp58;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r30, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    M2C_ERROR(/* unknown instruction: psq_stx $f0, $zero, $r30, 0x0, qr0 */);
    var_r28_516 = 0;
    arg0.unk8 += (f32) spD8;
    temp_f1_521 = arg0.unk4;
    M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
    if (temp_f1_521 == this->unk80.unk4.unk18) {
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if ((temp_f1_521 == this->unk80.unk4.unk1C) && (this->unk80.unk4.IsPointWithin(arg0) != 0)) {
            var_r28_516 = 1;
        }
    }
    if (var_r28_516 != 0) {
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r30, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $r29, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
        sp160 = sp80;
        sp88 = arg0.unk8 - this->unk58;
        sp168 = (f64) sp88;
        var_f4_560 = ((f32) sp168 * (f32) sp168) + (((f32) sp160 * (f32) sp160) + (unksp164 * unksp164));
        if (var_f4_560 > 0.000001f) {
            if (var_f4_560 > 0.0f) {
                temp_f1_566 = __frsqrte(var_f4_560);
                temp_f1_572 = 0.5 * temp_f1_566 * -(((f64) var_f4_560 * (temp_f1_566 * temp_f1_566)) - 3.0);
                temp_f1_576 = 0.5 * temp_f1_572 * -(((f64) var_f4_560 * (temp_f1_572 * temp_f1_572)) - 3.0);
                var_f4_560 = (f32) ((f64) var_f4_560 * (0.5 * temp_f1_576 * -(((f64) var_f4_560 * (temp_f1_576 * temp_f1_576)) - 3.0)));
            } else if (var_f4_560 < M2C_BITWISE(f32, 0.0)) {
                var_f4_560 = __float_nan;
            } else {
                sp8 = var_f4_560;
                temp_r3_595 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                switch (temp_r3_595) {              /* switch 2; irregular */
                case 0x7F800000:                    /* switch 2 */
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_605 = 1;
                    } else {
                        var_r0_605 = 2;
                    }
                    break;
                case 0x0:                           /* switch 2 */
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_605 = 5;
                    } else {
                        var_r0_605 = 3;
                    }
                    break;
                default:                            /* switch 2 */
                    var_r0_605 = 4;
                    break;
                }
                if (var_r0_605 == 1) {
                    var_f4_560 = __float_nan;
                }
            }
            var_f3_627 = 1.0f / var_f4_560;
        } else {
            var_f3_627 = 0.0f;
        }
        temp_f28_638 = (f32) sp168 * var_f3_627;
        sp160 = (f32) sp160 * var_f3_627;
        unksp164 *= var_f3_627;
        sp168 = temp_f28_638;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
        sp48 = temp_f28_638 * 1000.0f;
        spC0 = sp40;
        spC8 = (f64) sp48;
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r30, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        M2C_ERROR(/* unknown instruction: psq_stx $f0, $zero, $r30, 0x0, qr0 */);
        arg0.unk8 += (f32) spC8;
        temp_f29_666 = MKRand_Float(&gViewSeed, M2C_ERROR(/* unknown instruction: ps_mr $f1, $f30 */), 2000.0f);
        sp18 = -temp_f28_638;
        sp10 = -sp160;
        sp14 = -unksp164;
        spA8 = (f64) sp18;
        spA0 = (f64) sp10;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
        M2C_FIELD(&arg1, f64 *, 0) = sp30;
        sp38 = (f32) spA8 * temp_f29_666;
        spB0 = sp30;
        spB8 = (f64) sp38;
        M2C_FIELD(&arg1, f64 *, 8) = (f64) sp38;
        return 1U;
    }
    return 0U;
}
#endif

#if 0 // DRAFT: illegal type
u8 WeatherRegion::CalculateEmissionPointSpores(MKVector3 &arg0) {
    f64 sp108;
    f64 sp100;
    f64 spF8;                                       /* compiler-managed */
    f64 spF0;                                       /* compiler-managed */
    f64 spE8;
    f64 spE0;
    f64 spD8;
    f64 spD0;
    MKVector3 spC0;
    MKVector3 spB0;
    MKVector3 spA0;
    MKVector3 sp90;
    MKVector3 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f32 sp58;
    f32 sp48;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f32 sp18;
    f32 sp8;
    f32 temp_f1_928;
    f32 temp_f2_733;
    f32 var_f4_760;
    f32 var_f5_749;
    f64 temp_f1_765;
    f64 temp_f1_771;
    f64 temp_f1_775;
    s32 temp_r3_794;
    s32 var_r0_804;
    u8 var_r31_923;
    void *temp_r30_725;
    void *temp_r31_723;
    void *temp_r3_722;

    temp_r3_722 = checked_cast<WeatherRegionDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    temp_r31_723 = temp_r3_722;
    temp_r30_725 = temp_r31_723 + 0x90;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r30, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r3, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    temp_f2_733 = M2C_FIELD(temp_r31_723, f32 *, 0x98) - M2C_FIELD(temp_r31_723, f32 *, 0xD8);
    sp100 = sp50;
    sp58 = temp_f2_733;
    sp108 = (f64) sp58;
    var_f5_749 = 0.0f;
    spF0 = M2C_FIELD(temp_r31_723, f64 *, 0x80);
    spF8 = M2C_FIELD(temp_r31_723, f64 *, 0x88);
    unkspF4 = 0.0f;
    var_f4_760 = ((f32) spF8 * (f32) spF8) + (((f32) spF0 * (f32) spF0) + (0.0f * 0.0f));
    if (var_f4_760 > 0.000001f) {
        if (var_f4_760 > 0.0f) {
            temp_f1_765 = __frsqrte(var_f4_760);
            temp_f1_771 = 0.5 * temp_f1_765 * -(((f64) var_f4_760 * (temp_f1_765 * temp_f1_765)) - 3.0);
            temp_f1_775 = 0.5 * temp_f1_771 * -(((f64) var_f4_760 * (temp_f1_771 * temp_f1_771)) - 3.0);
            var_f4_760 = (f32) ((f64) var_f4_760 * (0.5 * temp_f1_775 * -(((f64) var_f4_760 * (temp_f1_775 * temp_f1_775)) - 3.0)));
        } else if (var_f4_760 < M2C_BITWISE(f32, 0.0)) {
            var_f4_760 = __float_nan;
        } else {
            sp8 = var_f4_760;
            temp_r3_794 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r3_794) {                  /* irregular */
            case 0x7F800000:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_804 = 1;
                } else {
                    var_r0_804 = 2;
                }
                break;
            case 0x0:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_804 = 5;
                } else {
                    var_r0_804 = 3;
                }
                break;
            default:
                var_r0_804 = 4;
                break;
            }
            if (var_r0_804 == 1) {
                var_f4_760 = __float_nan;
            }
        }
        var_f5_749 = 1.0f / var_f4_760;
    }
    spF0 = (f32) spF0 * var_f5_749;
    unkspF4 *= var_f5_749;
    spF8 = (f32) spF8 * var_f5_749;
    sp80.operator*(MKRand_Float(&gViewSeed, -0.1f, 1.0f));
    sp90.operator*(2000.0f);
    spA0.operator*(2.0f);
    spB0.operator*(MKRand_Float(&gViewSeed, -1.0f, 1.0f));
    spC0.operator*(1000.0f);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r30, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    spD0 = sp10;
    sp18 = M2C_FIELD(temp_r30_725, f32 *, 8) + spC0.unk8;
    spD8 = (f64) sp18;
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    M2C_FIELD(&arg0, f64 *, 0) = sp40;
    sp48 = (f32) spD8 + spA0.unk8;
    spE0 = sp40;
    spE8 = (f64) sp48;
    M2C_FIELD(&arg0, f64 *, 8) = (f64) sp48;
    sp34 = MKRand_Float(&gViewSeed, -500.0f, 1500.0f);
    sp30 = 0.0f;
    sp38 = 0.0f;
    sp70 = (f64) sp30;
    sp78 = (f64) sp38;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r29, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    M2C_ERROR(/* unknown instruction: psq_stx $f0, $zero, $r29, 0x0, qr0 */);
    arg0.unk8 += (f32) sp78;
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
    sp28 = (f32) sp108 * 20.0f;
    sp60 = sp20;
    sp68 = (f64) sp28;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r29, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    M2C_ERROR(/* unknown instruction: psq_stx $f0, $zero, $r29, 0x0, qr0 */);
    var_r31_923 = 0;
    arg0.unk8 += (f32) sp68;
    temp_f1_928 = arg0.unk4;
    M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
    if (temp_f1_928 == this->unk80.unk4.unk18) {
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if ((temp_f1_928 == this->unk80.unk4.unk1C) && (this->unk80.unk4.IsPointWithin(arg0) != 0)) {
            var_r31_923 = 1;
        }
    }
    if (var_r31_923 != 0) {
        return 1U;
    }
    return 0U;
}
#endif

#if 0 // DRAFT: illegal type
u8 WeatherRegion::CalculateEmissionPoint(MKVector3 &arg0) {
    f64 sp130;
    f64 sp128;
    f64 sp120;                                      /* compiler-managed */
    f64 sp118;                                      /* compiler-managed */
    f64 sp110;
    f64 sp108;
    f64 sp100;
    f64 spF8;
    MKVector3 spE8;
    MKVector3 spD8;
    MKVector3 spC8;
    MKVector3 spB8;
    MKVector3 spA8;
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f32 sp70;
    f32 sp60;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp30;
    f32 sp20;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f1_1242;
    f32 temp_f1_1278;
    f32 temp_f29_1237;
    f32 temp_f2_989;
    f32 var_f4_1001;
    f32 var_f4_1081;
    f32 var_f5_1065;
    f64 temp_f1_1004;
    f64 temp_f1_1010;
    f64 temp_f1_1014;
    f64 temp_f1_1086;
    f64 temp_f1_1092;
    f64 temp_f1_1096;
    s32 temp_r3_1033;
    s32 temp_r3_1115;
    s32 var_r0_1043;
    s32 var_r0_1125;
    u8 var_r30_1273;
    void *temp_r30_981;
    void *temp_r31_979;
    void *temp_r3_978;

    temp_r3_978 = checked_cast<WeatherRegionDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    temp_r31_979 = temp_r3_978;
    temp_r30_981 = temp_r31_979 + 0x90;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r30, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r3, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    temp_f2_989 = M2C_FIELD(temp_r31_979, f32 *, 0x98) - M2C_FIELD(temp_r31_979, f32 *, 0xD8);
    sp128 = sp68;
    sp70 = temp_f2_989;
    sp130 = (f64) sp70;
    var_f4_1001 = ((f32) sp130 * (f32) sp130) + (((f32) sp128 * (f32) sp128) + (unksp12C * unksp12C));
    if (var_f4_1001 > 0.0f) {
        temp_f1_1004 = __frsqrte(var_f4_1001);
        temp_f1_1010 = 0.5 * temp_f1_1004 * -(((f64) var_f4_1001 * (temp_f1_1004 * temp_f1_1004)) - 3.0);
        temp_f1_1014 = 0.5 * temp_f1_1010 * -(((f64) var_f4_1001 * (temp_f1_1010 * temp_f1_1010)) - 3.0);
        var_f4_1001 = (f32) ((f64) var_f4_1001 * (0.5 * temp_f1_1014 * -(((f64) var_f4_1001 * (temp_f1_1014 * temp_f1_1014)) - 3.0)));
    } else if (var_f4_1001 < M2C_BITWISE(f32, 0.0)) {
        var_f4_1001 = __float_nan;
    } else {
        spC = var_f4_1001;
        temp_r3_1033 = M2C_BITWISE(s32, spC) & 0x7F800000;
        switch (temp_r3_1033) {                     /* switch 1; irregular */
        case 0x7F800000:                            /* switch 1 */
            if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                var_r0_1043 = 1;
            } else {
                var_r0_1043 = 2;
            }
            break;
        case 0x0:                                   /* switch 1 */
            if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                var_r0_1043 = 5;
            } else {
                var_r0_1043 = 3;
            }
            break;
        default:                                    /* switch 1 */
            var_r0_1043 = 4;
            break;
        }
        if (var_r0_1043 == 1) {
            var_f4_1001 = __float_nan;
        }
    }
    var_f5_1065 = 0.0f;
    sp118 = M2C_FIELD(temp_r31_979, f64 *, 0x80);
    sp120 = M2C_FIELD(temp_r31_979, f64 *, 0x88);
    unksp11C = 0.0f;
    var_f4_1081 = ((f32) sp120 * (f32) sp120) + (((f32) sp118 * (f32) sp118) + (0.0f * 0.0f));
    if (var_f4_1081 > 0.000001f) {
        if (var_f4_1081 > 0.0f) {
            temp_f1_1086 = __frsqrte(var_f4_1081);
            temp_f1_1092 = 0.5 * temp_f1_1086 * -(((f64) var_f4_1081 * (temp_f1_1086 * temp_f1_1086)) - 3.0);
            temp_f1_1096 = 0.5 * temp_f1_1092 * -(((f64) var_f4_1081 * (temp_f1_1092 * temp_f1_1092)) - 3.0);
            var_f4_1081 = (f32) ((f64) var_f4_1081 * (0.5 * temp_f1_1096 * -(((f64) var_f4_1081 * (temp_f1_1096 * temp_f1_1096)) - 3.0)));
        } else if (var_f4_1081 < M2C_BITWISE(f32, 0.0)) {
            var_f4_1081 = __float_nan;
        } else {
            sp8 = var_f4_1081;
            temp_r3_1115 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r3_1115) {                 /* switch 2; irregular */
            case 0x7F800000:                        /* switch 2 */
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_1125 = 1;
                } else {
                    var_r0_1125 = 2;
                }
                break;
            case 0x0:                               /* switch 2 */
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_1125 = 5;
                } else {
                    var_r0_1125 = 3;
                }
                break;
            default:                                /* switch 2 */
                var_r0_1125 = 4;
                break;
            }
            if (var_r0_1125 == 1) {
                var_f4_1081 = __float_nan;
            }
        }
        var_f5_1065 = 1.0f / var_f4_1081;
    }
    sp118 = (f32) sp118 * var_f5_1065;
    unksp11C *= var_f5_1065;
    sp120 = (f32) sp120 * var_f5_1065;
    spA8.operator*(MKRand_Float(&gViewSeed, -0.1f, 1.0f));
    spB8.operator*(2000.0f);
    spC8.operator*(2.0f);
    spD8.operator*(MKRand_Float(&gViewSeed, -1.0f, 1.0f));
    spE8.operator*(1000.0f);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r30, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    spF8 = sp18;
    sp20 = M2C_FIELD(temp_r30_981, f32 *, 8) + spE8.unk8;
    sp100 = (f64) sp20;
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    M2C_FIELD(&arg0, f64 *, 0) = sp58;
    sp60 = (f32) sp100 + spC8.unk8;
    sp108 = sp58;
    sp110 = (f64) sp60;
    M2C_FIELD(&arg0, f64 *, 8) = (f64) sp60;
    sp4C = MKRand_Float(&gViewSeed, 500.0f, 1500.0f);
    sp48 = 0.0f;
    sp50 = 0.0f;
    sp98 = (f64) sp48;
    spA0 = (f64) sp50;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r29, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    M2C_ERROR(/* unknown instruction: psq_stx $f0, $zero, $r29, 0x0, qr0 */);
    arg0.unk8 += (f32) spA0;
    sp10 = 1.0f - ((var_f4_1001 / 100.0f) + 1.0f);
    temp_f29_1237 = MKRand_Float(&gViewSeed, 500.0f, 1500.0f);
    temp_f1_1242 = temp_f29_1237 * Clamp<float>(-1.0f, sp10, 100.0f);
    sp40 = 0.0f;
    sp38 = 0.0f;
    sp3C = temp_f1_1242;
    sp90 = (f64) sp40;
    sp88 = (f64) sp38;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r29, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    M2C_ERROR(/* unknown instruction: psq_stx $f0, $zero, $r29, 0x0, qr0 */);
    arg0.unk8 += (f32) sp90;
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
    sp30 = (f32) sp130 * 20.0f;
    sp78 = sp28;
    sp80 = (f64) sp30;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r29, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    M2C_ERROR(/* unknown instruction: psq_stx $f0, $zero, $r29, 0x0, qr0 */);
    var_r30_1273 = 0;
    arg0.unk8 += (f32) sp80;
    temp_f1_1278 = arg0.unk4;
    M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
    if (temp_f1_1278 == this->unk80.unk4.unk18) {
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if ((temp_f1_1278 == this->unk80.unk4.unk1C) && (this->unk80.unk4.IsPointWithin(arg0) != 0)) {
            var_r30_1273 = 1;
        }
    }
    if (var_r30_1273 != 0) {
        return 1U;
    }
    return 0U;
}
#endif

void WeatherRegion::Deinit() {
    this->unk80.Deinit();
    MKProp::Deinit();
}

void WeatherRegion::Draw() {

}

#if 0 // DRAFT: function call 'memcpy(long, long, int)' does not match
void WeatherRegion::Update() {
    Frustum spE0;
    MKVector3 spD0;
    MKVector3 spC0;
    f64 spB8;
    f64 spB0;
    f64 spA8;
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f1_1596;
    s32 temp_r0_1396;
    s32 var_r30_1412;
    s32 var_r30_1448;
    s32 var_r30_1484;
    s32 var_r30_1520;
    s32 var_r30_1556;
    s32 var_r30_1585;

    this->unk78 -= gUpdateTimeDelta;
    M2C_STRUCT_COPY((s32) &spD0.unkC + 4, M2C_FIELD(&gb, s32 *, 0x3B8) + 0xAC + 4, 0x70);
    if ((spE0.IsVisible((BoundingVolume *) &this->unk80.unk30) != 0) && !(this->unk78 > 0.0f)) {
        this->unk78 = MKRand_Float(&gViewSeed, this->unk6C, this->unk70);
        temp_r0_1396 = this->unk60;
        switch (temp_r0_1396) {                     /* irregular */
        case 1:
            var_r30_1412 = 0;
loop_15:
            if (var_r30_1412 < (s32) this->unk74) {
                if (CalculateEmissionPoint(spD0) != 0) {
                    sp1C = MKRand_Float(&gViewSeed, this->unk64, this->unk68);
                    sp68 = 0.0f;
                    sp60 = 0.0f;
                    sp64 = 0.0f;
                    spB8 = (f64) sp68;
                    spB0 = (f64) sp60;
                    ((WeatherSnowPS *) (M2C_FIELD(checked_cast<WeatherRegionDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), WeatherSnowPS **, 0xE0)))->Emit(spD0, *((MKVector3 *) &spB0), sp1C);
                }
                var_r30_1412 += 1;
                goto loop_15;
            }
            return;
        case 2:
            var_r30_1448 = 0;
loop_21:
            if (var_r30_1448 < (s32) this->unk74) {
                if (CalculateEmissionPoint(spD0) != 0) {
                    sp18 = MKRand_Float(&gViewSeed, this->unk64, this->unk68);
                    sp58 = 0.0f;
                    sp50 = 0.0f;
                    sp54 = 0.0f;
                    spA8 = (f64) sp58;
                    spA0 = (f64) sp50;
                    ((WeatherAshPS *) (M2C_FIELD(checked_cast<WeatherRegionDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), WeatherAshPS **, 0xE4)))->Emit(spD0, *((MKVector3 *) &spA0), sp18);
                }
                var_r30_1448 += 1;
                goto loop_21;
            }
            return;
        case 3:
            var_r30_1484 = 0;
loop_27:
            if (var_r30_1484 < (s32) this->unk74) {
                if (CalculateEmissionPoint(spD0) != 0) {
                    sp14 = MKRand_Float(&gViewSeed, this->unk64, this->unk68);
                    sp48 = 0.0f;
                    sp40 = 0.0f;
                    sp44 = 0.0f;
                    sp98 = (f64) sp48;
                    sp90 = (f64) sp40;
                    ((WeatherEmbersPS *) (M2C_FIELD(checked_cast<WeatherRegionDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), WeatherEmbersPS **, 0xE8)))->Emit(spD0, *((MKVector3 *) &sp90), sp14);
                }
                var_r30_1484 += 1;
                goto loop_27;
            }
            return;
        case 4:
            var_r30_1520 = 0;
loop_33:
            if (var_r30_1520 < (s32) this->unk74) {
                if (CalculateEmissionPointSpores(spD0) != 0) {
                    sp10 = MKRand_Float(&gViewSeed, this->unk64, this->unk68);
                    sp38 = 0.0f;
                    sp30 = 0.0f;
                    sp34 = 0.0f;
                    sp88 = (f64) sp38;
                    sp80 = (f64) sp30;
                    ((WeatherSporesPS *) (M2C_FIELD(checked_cast<WeatherRegionDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), WeatherSporesPS **, 0xEC)))->Emit(spD0, *((MKVector3 *) &sp80), sp10);
                }
                var_r30_1520 += 1;
                goto loop_33;
            }
            return;
        case 5:
            var_r30_1556 = 0;
loop_39:
            if (var_r30_1556 < (s32) this->unk74) {
                if (CalculateEmissionParametersConvexity(spD0, spC0) != 0) {
                    spC = MKRand_Float(&gViewSeed, this->unk64, this->unk68);
                    ((WeatherConvexityPS *) (M2C_FIELD(checked_cast<WeatherRegionDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), WeatherConvexityPS **, 0xF0)))->Emit(spD0, spC0, spC);
                }
                var_r30_1556 += 1;
                goto loop_39;
            }
            return;
        case 6:
            var_r30_1585 = 0;
loop_45:
            if (var_r30_1585 < (s32) this->unk74) {
                if (CalculateEmissionPointRain(spD0) != 0) {
                    temp_f1_1596 = MKRand_Float(&gViewSeed, this->unk64, this->unk68);
                    sp28 = 0.0f;
                    sp20 = 0.0f;
                    sp24 = -1000.0f;
                    sp8 = temp_f1_1596;
                    sp70 = (f64) sp20;
                    sp78 = (f64) sp28;
                    ((WeatherRainPS *) (M2C_FIELD(checked_cast<WeatherRegionDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), WeatherRainPS **, 0xF4)))->Emit(spD0, *((MKVector3 *) &sp70), sp8);
                }
                var_r30_1585 += 1;
                goto loop_45;
            }
            break;
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'loadInfo'
void WeatherRegion::LoadDone() {
    MKProp::LoadDone();
    this->unk50 = M2C_FIELD(&loadInfo, f64 *, 0x40);
    M2C_FIELD(this, f64 *, 0x58) = (f64) M2C_FIELD(&loadInfo, f64 *, 0x48);
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_stringBase0'
s32 WeatherRegion::LoadLine(MKIniLine *arg0) {
    s32 var_r31_1659;

    var_r31_1659 = 0;
    if ((MKProp::LoadLine(arg0) != 0) || (arg0->LoadInt(lit_stringBase0, &this->unk60, 0) != 0) || (arg0->LoadFloat(&lit_stringBase0[5], &this->unk64, 0) != 0) || (arg0->LoadFloat(&lit_stringBase0[0xE], &this->unk68, 0) != 0) || (arg0->LoadFloat(&lit_stringBase0[0x17], &this->unk6C, 0) != 0) || (arg0->LoadFloat(&lit_stringBase0[0x1F], &this->unk70, 0) != 0) || (arg0->LoadInt(&lit_stringBase0[0x27], &this->unk74, 0) != 0) || (this->unk80.LoadLine(&lit_stringBase0[0x32], arg0) != 0)) {
        var_r31_1659 = 1;
    }
    return var_r31_1659;
}
#endif

void WeatherRegion::Init() {
    MKProp::Init();
    this->unk80.Init();
    this->unk60 = 0;
    this->unk64 = 0.125f;
    this->unk68 = 1.0f;
    this->unk6C = 0.0f;
    this->unk70 = 0.0f;
    this->unk74 = 5;
    this->unk78 = 0.0f;
}

#if 0 // DRAFT: undefined identifier 'unk9C'
void WeatherRegionDescriptor::Update() {
    MKPropDescriptor::Update();
    M2C_STRUCT_COPY((s32) &this->unk9C + 4, (s32) &this->unk5C + 4, 0x40);
    M2C_STRUCT_COPY((s32) &this->unk5C + 4, M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), s32 *, 8) - 4 + 4, 0x40);
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_stringBase0'
void WeatherRegionDescriptor::Resolve() {
    MKPropDescriptor::Resolve();
    this->unkE0 = checked_cast<WeatherSnowPS *, MKProp>(gMK->CreateProp(&lit_stringBase0[0x3C]));
    this->unkE4 = checked_cast<WeatherAshPS *, MKProp>(gMK->CreateProp(&lit_stringBase0[0x4A]));
    this->unkE8 = checked_cast<WeatherEmbersPS *, MKProp>(gMK->CreateProp(&lit_stringBase0[0x57]));
    this->unkEC = checked_cast<WeatherSporesPS *, MKProp>(gMK->CreateProp(&lit_stringBase0[0x67]));
    this->unkF0 = checked_cast<WeatherConvexityPS *, MKProp>(gMK->CreateProp(&lit_stringBase0[0x77]));
    this->unkF4 = checked_cast<WeatherRainPS *, MKProp>(gMK->CreateProp(&lit_stringBase0[0x8A]));
}
#endif

#if 0 // DRAFT: undefined identifier 'unk9C'
void WeatherRegionDescriptor::Init() {
    MKPropDescriptor::Init();
    M2C_STRUCT_COPY((s32) &this->unk9C + 4, (s32) (&identity - 4) + 4, 0x40);
    M2C_STRUCT_COPY((s32) &this->unk5C + 4, (s32) &this->unk9C + 4, 0x40);
}
#endif

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<WeatherRainPS *, MKProp>(MKProp *arg0) {

}
#endif

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<WeatherConvexityPS *, MKProp>(MKProp *arg0) {

}
#endif

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<WeatherSporesPS *, MKProp>(MKProp *arg0) {

}
#endif

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<WeatherEmbersPS *, MKProp>(MKProp *arg0) {

}
#endif

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<WeatherAshPS *, MKProp>(MKProp *arg0) {

}
#endif

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<WeatherSnowPS *, MKProp>(MKProp *arg0) {

}
#endif

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<WeatherRegionDescriptor *, MKPropDescriptor>(MKPropDescriptor *arg0) {

}
#endif
