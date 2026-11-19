#include "spyro/source/ExplosiveBarrelPath.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/ExplosiveBarrel.h"
#include "spyro/source/KDParticleSystem.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSpline.h"
#include "unplaced_templates.h"
#include "common/Source/MKCollision.h"
#include "common/Source/StdMath.h"
#include "spyro/source/KDRandom.h"
#include "spyro/source/Tools.h"
#include <m2c_macros.h>

M2C_UNK __destroy_arr(f32 *, ExplosiveBarrelPath::BarrelData *(*)(ExplosiveBarrelPath::BarrelData *, s16), M2C_UNK, M2C_UNK); /* extern */
f64 fmod(f32, f64);                                 /* extern */
extern f32 *KDSpline_PositionMixer;
extern MKSceneManager *gMK;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern M2C_UNK gb;
#if 0 // DRAFT: ')' expected
static s8 lit_stringBase0[0x108] = {
    0x50,
    0x35,
    0x30,
    0x32,
    0x33,
    0x5F,
    0x42,
    0x6F,
    0x6F,
    0x6D,
    0x42,
    0x61,
    0x72,
    0x72,
    0x65,
    0x6C,
    0,
    0x50,
    0x33,
    0x30,
    0x34,
    0x30,
    0x5F,
    0x42,
    0x6F,
    0x6F,
    0x6D,
    0x42,
    0x61,
    0x72,
    0x72,
    0x65,
    0x6C,
    0,
    0x50,
    0x34,
    0x30,
    0x33,
    0x36,
    0x5F,
    0x42,
    0x6F,
    0x6F,
    0x6D,
    0x42,
    0x61,
    0x72,
    0x72,
    0x65,
    0x6C,
    0,
    0x50,
    0x31,
    0x30,
    0x34,
    0x30,
    0x5F,
    0x42,
    0x6F,
    0x6F,
    0x6D,
    0x42,
    0x61,
    0x72,
    0x72,
    0x65,
    0x6C,
    0,
    0x50,
    0x30,
    0x30,
    0x39,
    0x31,
    0x5F,
    0x42,
    0x6F,
    0x6F,
    0x6D,
    0x42,
    0x61,
    0x72,
    0x72,
    0x65,
    0x6C,
    0,
    0x4C,
    0x65,
    0x66,
    0x74,
    0x54,
    0x72,
    0x61,
    0x63,
    0x6B,
    0,
    0x52,
    0x69,
    0x67,
    0x68,
    0x74,
    0x54,
    0x72,
    0x61,
    0x63,
    0x6B,
    0,
    0x53,
    0x70,
    0x65,
    0x65,
    0x64,
    0,
    0x41,
    0x63,
    0x63,
    0x65,
    0x6C,
    0x65,
    0x72,
    0x61,
    0x74,
    0x69,
    0x6F,
    0x6E,
    0,
    0x42,
    0x6F,
    0x75,
    0x6E,
    0x63,
    0x65,
    0x43,
    0x68,
    0x61,
    0x6E,
    0x63,
    0x65,
    0,
    0x42,
    0x6F,
    0x75,
    0x6E,
    0x63,
    0x65,
    0x53,
    0x70,
    0x65,
    0x65,
    0x64,
    0,
    0x62,
    0x41,
    0x75,
    0x74,
    0x6F,
    0x53,
    0x68,
    0x6F,
    0x6F,
    0x74,
    0x42,
    0x61,
    0x72,
    0x72,
    0x65,
    0x6C,
    0x73,
    0,
    0x62,
    0x4F,
    0x6E,
    0x65,
    0x53,
    0x68,
    0x6F,
    0x74,
    0,
    0x66,
    0x41,
    0x75,
    0x74,
    0x6F,
    0x53,
    0x68,
    0x6F,
    0x6F,
    0x74,
    0x44,
    0x65,
    0x6C,
    0x61,
    0x79,
    0,
    0x66,
    0x45,
    0x78,
    0x70,
    0x6C,
    0x6F,
    0x73,
    0x69,
    0x6F,
    0x6E,
    0x52,
    0x61,
    0x64,
    0x69,
    0x75,
    0x73,
    0x53,
    0x63,
    0x61,
    0x6C,
    0x65,
    0,
    0x42,
    0x61,
    0x72,
    0x72,
    0x65,
    0x6C,
    0x44,
    0x75,
    0x73,
    0x74,
    0x44,
    0x69,
    0x72,
    0x74,
    0x50,
    0x53,
    0,
    0x42,
    0x61,
    0x72,
    0x72,
    0x65,
    0x6C,
    0x44,
    0x75,
    0x73,
    0x74,
    0x49,
    0x63,
    0x65,
    0x50,
    0x53,
    0,
    0x62,
    0x61,
    0x72,
    0x72,
    0x65,
    0x6C,
    0x52,
    0x6F,
    0x6C,
    0x6C,
    0x53,
    0x6F,
    0x75,
    0x6E,
    0x64,
    0,
}; /* const */

void ExplosiveBarrelPath::EmitDust(const MKVector3 &arg0, const MKVector3 &arg1, float arg2) {
    f32 var_f0_107;
    void *temp_r31_83;
    void *temp_r3_64;
    void *temp_r3_74;
    void *var_r4_69;

    if ((u8) this->unk232 != 0) {
        temp_r3_64 = M2C_FIELD(checked_cast<ExplosiveBarrelPathDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), void **, 0x94);
        var_r4_69 = M2C_FIELD(M2C_FIELD(temp_r3_64, void **, 0x44), void *(**)(void *), 0x3C)(temp_r3_64);
    } else {
        temp_r3_74 = M2C_FIELD(checked_cast<ExplosiveBarrelPathDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), void **, 0x90);
        var_r4_69 = M2C_FIELD(M2C_FIELD(temp_r3_74, void **, 0x44), void *(**)(void *), 0x3C)(temp_r3_74);
    }
    if (var_r4_69 != NULL) {
        temp_r31_83 = M2C_FIELD(var_r4_69, void **, 0x2C);
        M2C_FIELD(var_r4_69, f64 *, 0) = (f64) M2C_FIELD(&arg0, f64 *, 0);
        M2C_FIELD(var_r4_69, f64 *, 8) = (f64) M2C_FIELD(&arg0, f64 *, 8);
        M2C_FIELD(var_r4_69, f32 *, 0x20) = 0.0f;
        M2C_FIELD(var_r4_69, f32 *, 0x28) = 0.0f;
        M2C_FIELD(temp_r31_83, f64 *, 0) = (f64) M2C_FIELD(&arg1, f64 *, 0);
        M2C_FIELD(temp_r31_83, f64 *, 8) = (f64) M2C_FIELD(&arg1, f64 *, 8);
        M2C_FIELD(temp_r31_83, f32 *, 0x18) = arg2;
        M2C_FIELD(temp_r31_83, f32 *, 0x10) = MKRand_Float(&gViewSeed, -3.1415927f, 3.1415927f);
        if ((u8) this->unk232 != 0) {
            var_f0_107 = M2C_FIELD(M2C_FIELD(checked_cast<ExplosiveBarrelPathDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), void **, 0x94), f32 *, 0xF4);
        } else {
            var_f0_107 = M2C_FIELD(M2C_FIELD(checked_cast<ExplosiveBarrelPathDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), void **, 0x90), f32 *, 0xF4);
        }
        M2C_FIELD(temp_r31_83, f32 *, 0x14) = var_f0_107;
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'ExplosiveBarrelPath::BarrelData *' to
void ExplosiveBarrelPath::GetBarrelMiddle(ExplosiveBarrelPath::BarrelData *arg1) {
    f64 sp78;
    f64 sp70;
    f64 sp68;
    KDUniformSpline sp50;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f32 sp28;
    f32 sp18;
    f32 spC;
    f32 sp8;
    f32 temp_f30_142;

    temp_f30_142 = (f32) fmod(M2C_FIELD(M2C_ERROR(/* Read from unset register $r5 */), f32 *, 4), 1.0);
    spC = 0.0f;
    sp50.GetMeasure(temp_f30_142, arg1 + 0x50, KDSpline_PositionMixer);
    sp70 = M2C_BITWISE(f64, sp50);
    sp78 = (f64) sp50.unk8;
    sp8 = 0.0f;
    sp40.GetMeasure(temp_f30_142, arg1 + 0x64, KDSpline_PositionMixer);
    sp50.unk10 = sp40;
    sp68 = sp48;
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    sp30 = sp10;
    sp18 = (f32) sp78 + (f32) sp68;
    sp38 = (f64) sp18;
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
    M2C_FIELD(this, f64 *, 0) = sp20;
    sp28 = (f32) sp38 * 0.5f;
    M2C_FIELD(this, f64 *, 8) = (f64) sp28;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk0'
void ExplosiveBarrelPath::UpdateBarrelModel(ExplosiveBarrelPath::BarrelData *arg1) {
    f32 temp_f29_225;
    f32 var_f28_228;
    f32 var_f3_512;
    f32 var_f3_621;
    f32 var_f4_412;
    f32 var_f4_445;
    f32 var_f4_554;
    f32 var_f5_345;
    f64 temp_f1_451;
    f64 temp_f1_457;
    f64 temp_f1_461;
    f64 temp_f1_560;
    f64 temp_f1_566;
    f64 temp_f1_570;
    f64 temp_f2_351;
    f64 temp_f2_357;
    f64 temp_f2_361;
    s32 temp_r3_380;
    s32 temp_r3_480;
    s32 temp_r3_589;
    s32 var_r0_390;
    s32 var_r0_490;
    s32 var_r0_599;
    void *temp_r31_221;
    temp_r31_221 = arg1->unk0;
    temp_f29_225 = (f32) fmod(arg1->unk4, 1.0);
    var_f28_228 = 0.01f + temp_f29_225;
    if (var_f28_228 > 1.0f) {
        var_f28_228 = 1.0f;
    }
    arg_sp28 = 0.0f;
    arg_sp1F0.GetMeasure(temp_f29_225, &this->unk50, KDSpline_PositionMixer);
    arg_sp290 = arg_sp1F0;
    arg_sp298 = arg_sp1F8;
    arg_sp24 = 0.0f;
    arg_sp1E0.GetMeasure(temp_f29_225, (Matrix *) &this->unk50.unk14, KDSpline_PositionMixer);
    arg_sp280 = arg_sp1E0;
    arg_sp288 = arg_sp1E8;
    arg_sp20 = 0.0f;
    arg_sp1D0.GetMeasure(var_f28_228, &this->unk50, KDSpline_PositionMixer);
    arg_sp270 = arg_sp1D0;
    arg_sp278 = arg_sp1D8;
    arg_sp1C = 0.0f;
    arg_sp1C0.GetMeasure(var_f28_228, (Matrix *) &this->unk50.unk14, KDSpline_PositionMixer);
    arg_sp260 = arg_sp1C0;
    arg_sp268 = arg_sp1C8;
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    arg_sp1B0 = arg_sp100;
    arg_sp108 = (f32) arg_sp298 + (f32) arg_sp288;
    arg_sp1B8 = (f64) arg_sp108;
    M2C_ERROR(/* unknown instruction: ps_muls0 $f1, $f1, $f31 */);
    arg_sp250 = arg_spF0;
    arg_spF8 = (f32) arg_sp1B8 * 0.5f;
    arg_sp258 = (f64) arg_spF8;
    M2C_ERROR(/* unknown instruction: ps_add $f1, $f2, $f1 */);
    arg_sp1A0 = arg_spE0;
    arg_spE8 = (f32) arg_sp278 + (f32) arg_sp268;
    arg_sp1A8 = (f64) arg_spE8;
    M2C_ERROR(/* unknown instruction: ps_muls0 $f1, $f1, $f31 */);
    arg_sp240 = arg_spD0;
    arg_spD8 = (f32) arg_sp1A8 * 0.5f;
    arg_sp248 = (f64) arg_spD8;
    M2C_ERROR(/* unknown instruction: ps_sub $f1, $f2, $f1 */);
    arg_sp190 = arg_spC0;
    arg_spC8 = (f32) arg_sp258 - (f32) arg_sp248;
    arg_sp198 = (f64) arg_spC8;
    var_f5_345 = ((f32) arg_sp198 * (f32) arg_sp198) + (((f32) arg_sp190 * (f32) arg_sp190) + (arg_sp194 * arg_sp194));
    if (var_f5_345 > 1e-12f) {
        if (var_f5_345 > 0.0f) {
            temp_f2_351 = __frsqrte(var_f5_345);
            temp_f2_357 = 0.5 * temp_f2_351 * -(((f64) var_f5_345 * (temp_f2_351 * temp_f2_351)) - 3.0);
            temp_f2_361 = 0.5 * temp_f2_357 * -(((f64) var_f5_345 * (temp_f2_357 * temp_f2_357)) - 3.0);
            var_f5_345 = (f32) ((f64) var_f5_345 * (0.5 * temp_f2_361 * -(((f64) var_f5_345 * (temp_f2_361 * temp_f2_361)) - 3.0)));
        } else if (var_f5_345 < M2C_BITWISE(f32, 0.0)) {
            var_f5_345 = __float_nan;
        } else {
            arg_sp18 = var_f5_345;
            temp_r3_380 = M2C_BITWISE(s32, arg_sp18) & 0x7F800000;
            switch (temp_r3_380) {                  /* switch 1; irregular */
            case 0x7F800000:                        /* switch 1 */
                if (M2C_BITWISE(s32, arg_sp18) & 0x7FFFFF) {
                    var_r0_390 = 1;
                } else {
                    var_r0_390 = 2;
                }
                break;
            case 0x0:                               /* switch 1 */
                if (M2C_BITWISE(s32, arg_sp18) & 0x7FFFFF) {
                    var_r0_390 = 5;
                } else {
                    var_r0_390 = 3;
                }
                break;
            default:                                /* switch 1 */
                var_r0_390 = 4;
                break;
            }
            if (var_r0_390 == 1) {
                var_f5_345 = __float_nan;
            }
        }
        var_f4_412 = 1.0f / var_f5_345;
    } else {
        var_f4_412 = 0.0f;
    }
    arg_spB4 = arg_sp194 * var_f4_412;
    arg_spB0 = (f32) arg_sp190 * var_f4_412;
    arg_spB8 = (f32) arg_sp198 * var_f4_412;
    arg_sp230 = (f64) arg_spB0;
    arg_sp238 = (f64) arg_spB8;
    M2C_ERROR(/* unknown instruction: ps_sub $f1, $f2, $f1 */);
    arg_spA8 = (f32) arg_sp298 - (f32) arg_sp288;
    arg_sp180 = arg_spA0;
    arg_sp188 = (f64) arg_spA8;
    var_f4_445 = ((f32) arg_sp188 * (f32) arg_sp188) + (((f32) arg_sp180 * (f32) arg_sp180) + (arg_sp184 * arg_sp184));
    if (var_f4_445 > 1e-12f) {
        if (var_f4_445 > 0.0f) {
            temp_f1_451 = __frsqrte(var_f4_445);
            temp_f1_457 = 0.5 * temp_f1_451 * -(((f64) var_f4_445 * (temp_f1_451 * temp_f1_451)) - 3.0);
            temp_f1_461 = 0.5 * temp_f1_457 * -(((f64) var_f4_445 * (temp_f1_457 * temp_f1_457)) - 3.0);
            var_f4_445 = (f32) ((f64) var_f4_445 * (0.5 * temp_f1_461 * -(((f64) var_f4_445 * (temp_f1_461 * temp_f1_461)) - 3.0)));
        } else if (var_f4_445 < M2C_BITWISE(f32, 0.0)) {
            var_f4_445 = __float_nan;
        } else {
            arg_sp14 = var_f4_445;
            temp_r3_480 = M2C_BITWISE(s32, arg_sp14) & 0x7F800000;
            switch (temp_r3_480) {                  /* switch 2; irregular */
            case 0x7F800000:                        /* switch 2 */
                if (M2C_BITWISE(s32, arg_sp14) & 0x7FFFFF) {
                    var_r0_490 = 1;
                } else {
                    var_r0_490 = 2;
                }
                break;
            case 0x0:                               /* switch 2 */
                if (M2C_BITWISE(s32, arg_sp14) & 0x7FFFFF) {
                    var_r0_490 = 5;
                } else {
                    var_r0_490 = 3;
                }
                break;
            default:                                /* switch 2 */
                var_r0_490 = 4;
                break;
            }
            if (var_r0_490 == 1) {
                var_f4_445 = __float_nan;
            }
        }
        var_f3_512 = 1.0f / var_f4_445;
    } else {
        var_f3_512 = 0.0f;
    }
    arg_sp94 = arg_sp184 * var_f3_512;
    arg_sp90 = (f32) arg_sp180 * var_f3_512;
    arg_sp98 = (f32) arg_sp188 * var_f3_512;
    arg_sp220 = (f64) arg_sp90;
    arg_sp228 = (f64) arg_sp98;
    arg_sp80 = (arg_sp234 * (f32) arg_sp228) - ((f32) arg_sp238 * arg_sp224);
    arg_sp84 = ((f32) arg_sp238 * (f32) arg_sp220) - ((f32) arg_sp230 * (f32) arg_sp228);
    arg_sp88 = ((f32) arg_sp230 * arg_sp224) - (arg_sp234 * (f32) arg_sp220);
    arg_sp170 = (f64) arg_sp80;
    arg_sp178 = (f64) arg_sp88;
    var_f4_554 = ((f32) arg_sp178 * (f32) arg_sp178) + (((f32) arg_sp170 * (f32) arg_sp170) + (arg_sp174 * arg_sp174));
    if (var_f4_554 > 1e-12f) {
        if (var_f4_554 > 0.0f) {
            temp_f1_560 = __frsqrte(var_f4_554);
            temp_f1_566 = 0.5 * temp_f1_560 * -(((f64) var_f4_554 * (temp_f1_560 * temp_f1_560)) - 3.0);
            temp_f1_570 = 0.5 * temp_f1_566 * -(((f64) var_f4_554 * (temp_f1_566 * temp_f1_566)) - 3.0);
            var_f4_554 = (f32) ((f64) var_f4_554 * (0.5 * temp_f1_570 * -(((f64) var_f4_554 * (temp_f1_570 * temp_f1_570)) - 3.0)));
        } else if (var_f4_554 < M2C_BITWISE(f32, 0.0)) {
            var_f4_554 = __float_nan;
        } else {
            arg_sp10 = var_f4_554;
            temp_r3_589 = M2C_BITWISE(s32, arg_sp10) & 0x7F800000;
            switch (temp_r3_589) {                  /* switch 3; irregular */
            case 0x7F800000:                        /* switch 3 */
                if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                    var_r0_599 = 1;
                } else {
                    var_r0_599 = 2;
                }
                break;
            case 0x0:                               /* switch 3 */
                if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                    var_r0_599 = 5;
                } else {
                    var_r0_599 = 3;
                }
                break;
            default:                                /* switch 3 */
                var_r0_599 = 4;
                break;
            }
            if (var_r0_599 == 1) {
                var_f4_554 = __float_nan;
            }
        }
        var_f3_621 = 1.0f / var_f4_554;
    } else {
        var_f3_621 = 0.0f;
    }
    arg_sp74 = arg_sp174 * var_f3_621;
    arg_sp70 = (f32) arg_sp170 * var_f3_621;
    arg_sp78 = (f32) arg_sp178 * var_f3_621;
    arg_sp210 = (f64) arg_sp70;
    arg_sp218 = (f64) arg_sp78;
    arg_sp48 = ((f32) arg_sp210 * arg_sp234) - (arg_sp214 * (f32) arg_sp230);
    arg_sp40 = (arg_sp214 * (f32) arg_sp238) - ((f32) arg_sp218 * arg_sp234);
    arg_sp44 = ((f32) arg_sp218 * (f32) arg_sp230) - ((f32) arg_sp210 * (f32) arg_sp238);
    arg_sp168 = (f64) arg_sp48;
    arg_sp160 = (f64) arg_sp40;
    arg_sp220 = (f64) arg_sp40;
    arg_sp228 = (f64) arg_sp48;
    M2C_STRUCT_COPY((s32) &arg_sp2DC + 4, MKModel_GetWorldMatrix(M2C_FIELD(temp_r31_221, MKModel **, 4)) - 4 + 4, 0x40);
    MKVector(0.0f, arg1->unk10, 0.0f);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    arg_sp150 = arg_sp30;
    arg_sp38 = (f32) arg_sp298 + arg_sp148;
    arg_sp158 = (f64) arg_sp38;
    arg_sp310 = (f32) arg_sp150;
    arg_sp314 = arg_sp154;
    arg_sp318 = (f32) arg_sp158;
    arg_sp31C = 1.0f;
    arg_sp2E0 = (f32) arg_sp220;
    arg_sp2E4 = arg_sp224;
    arg_sp2E8 = (f32) arg_sp228;
    arg_sp2EC = 0.0f;
    arg_sp2F0 = (f32) arg_sp210;
    arg_sp2F4 = arg_sp214;
    arg_sp2F8 = (f32) arg_sp218;
    arg_sp2FC = 0.0f;
    arg_sp300 = (f32) arg_sp230;
    arg_sp304 = arg_sp234;
    arg_sp308 = (f32) arg_sp238;
    arg_sp30C = 0.0f;
    arg_sp2A0.SetRotateAroundAxis(*((MKVector3 *) &arg_sp300), 1.5707964f);
    arg_sp2E0.Multiply3x3((Matrix *) &arg_sp2E0, (Matrix *) &arg_sp2A0);
    arg_sp2A0.SetRotateAroundAxis(*((MKVector3 *) &arg_sp2F0), arg1->unk8);
    arg_sp2E0.Multiply3x3((Matrix *) &arg_sp2E0, (Matrix *) &arg_sp2A0);
    MKModel_SetWorldMatrix(M2C_FIELD(temp_r31_221, MKModel **, 4), *((Matrix *) &arg_sp2E0));
    arg_sp200 = (f64) arg_sp310;
    arg_sp208 = (f64) arg_sp318;
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r3, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
    arg_sp120 = arg_sp60;
    arg_sp68 = up.unk8 * 500.0f;
    arg_sp128 = (f64) arg_sp68;
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    arg_sp130 = arg_sp50;
    arg_sp58 = (f32) arg_sp208 - (f32) arg_sp128;
    arg_sp138 = (f64) arg_sp58;
    if (MKCollision_RayCollide(*((MKVector3 *) &arg_sp200), *((MKVector3 *) &arg_sp130), (MKCollisionResult *) &arg_sp320, (MKCollisionMode) 4, 0) != 0) {
        Tools_GroundColor((MKCollisionResult *) &arg_sp110);
        MKModel_SetColor(M2C_FIELD(temp_r31_221, MKModel **, 4), *((MKVector4 *) &arg_sp110));
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'ExplosiveBarrelPath' to
s32 ExplosiveBarrelPath::GetNextInactiveBarrelID() {
    s32 var_r30_804;
    s32 var_r31_805;

    var_r30_804 = 0;
    var_r31_805 = 0;
loop_1:
    if (((ExplosiveBarrel *) (*(this + (var_r31_805 + 0x78))))->IsActive() == 0) {
        return var_r30_804;
    }
    var_r30_804 += 1;
    var_r31_805 += 0x44;
    if (var_r30_804 >= 4) {
        return -1;
    }
    goto loop_1;
}
#endif

void ExplosiveBarrelPath::PushBarrel(int arg0) {
    void *temp_r3_835;

    temp_r3_835 = this + (arg0 * 0x44);
    if ((u8) M2C_FIELD(temp_r3_835, u8 *, 0x90) == 0) {
        M2C_FIELD(temp_r3_835, u8 *, 0x90) = 1U;
        ((ExplosiveBarrel *) (M2C_FIELD(temp_r3_835, ExplosiveBarrel **, 0x78)))->Ignite(200.0f);
    }
}

void ExplosiveBarrelPath::ExplodeBarrel(int arg0) {
    s32 spC;
    s32 sp8;
    void *temp_r3_865;
    void *temp_r3_873;

    if ((arg0 > -1) && (arg0 < 4)) {
        temp_r3_865 = this + (arg0 * 0x44);
        M2C_FIELD(temp_r3_865, f32 *, 0x7C) = 0.0f;
        M2C_FIELD(temp_r3_865, f32 *, 0x80) = 0.0f;
        M2C_FIELD(temp_r3_865, f32 *, 0x84) = 0.0f;
        M2C_FIELD(temp_r3_865, f32 *, 0x88) = 0.0f;
        M2C_FIELD(temp_r3_865, f32 *, 0x8C) = 0.0f;
        M2C_FIELD(temp_r3_865, s8 *, 0x90) = 0;
        temp_r3_873 = M2C_FIELD(temp_r3_865, void **, 0x78);
        spC = 0;
        sp8 = 0xBA;
        M2C_FIELD(M2C_FIELD(temp_r3_873, void **, 0x44), M2C_UNK (**)(void *, s32 *, M2C_UNK), 0x2C)(temp_r3_873, &sp8, 0);
    }
}

#if 0 // DRAFT: illegal implicit conversion from 'ExplosiveBarrelPath *' to
s32 ExplosiveBarrelPath::SpawnBarrel(MKProp *arg0) {
    s32 temp_r31_900;
    s32 temp_r3_896;
    void *temp_r31_914;
    void *temp_r5_904;

    temp_r3_896 = GetNextInactiveBarrelID();
    if (temp_r3_896 > -1) {
        temp_r31_900 = temp_r3_896 * 0x44;
        temp_r5_904 = this + temp_r31_900;
        M2C_FIELD(temp_r5_904, f32 *, 0x7C) = 0.0f;
        M2C_FIELD(temp_r5_904, f32 *, 0x80) = 0.0f;
        M2C_FIELD(temp_r5_904, f32 *, 0x84) = 0.0f;
        M2C_FIELD(temp_r5_904, f32 *, 0x88) = 0.0f;
        M2C_FIELD(temp_r5_904, f32 *, 0x8C) = 0.0f;
        M2C_FIELD(temp_r5_904, s8 *, 0x90) = 0;
        UpdateBarrelModel(this + (temp_r31_900 + 0x78));
        temp_r31_914 = this + temp_r31_900;
        ((ExplosiveBarrel *) (M2C_FIELD(temp_r31_914, ExplosiveBarrel **, 0x78)))->SetDefaults();
        ((ExplosiveBarrel *) (M2C_FIELD(temp_r31_914, ExplosiveBarrel **, 0x78)))->SetActive(1U);
    }
    this->unk4C = arg0;
    return temp_r3_896;
}
#endif

#if 0 // DRAFT: expression syntax error
void ExplosiveBarrelPath::CalcStandPosAndDir() {
    MKCollisionResult sp190;
    f64 sp188;
    f64 sp180;
    f64 sp178;
    f64 sp170;
    KDUniformSpline sp150;
    f64 sp148;
    f64 sp140;
    f64 sp138;
    f64 sp130;
    f64 sp128;
    f64 sp120;
    f64 sp118;
    f64 sp110;
    f64 sp108;
    f64 sp100;
    MKVector3 spF0;
    f64 spE8;
    f64 spE0;
    KDUniformSpline spC0;
    f64 spB8;
    f64 spB0;
    f32 spA8;
    f32 sp98;
    f32 sp88;
    f32 sp78;
    f32 sp68;
    f32 sp58;
    f32 sp48;
    f32 sp38;
    f32 sp28;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f1_1094;
    f32 temp_f2_1004;
    f32 temp_f2_1093;
    f32 temp_f5_1095;
    f32 var_f4_1085;
    f32 var_f5_1101;
    f64 temp_f1_1106;
    f64 temp_f1_1112;
    f64 temp_f1_1116;
    s32 temp_r3_1135;
    s32 var_r0_1145;

    sp14 = 0.0f;
    sp150.GetMeasure(0.0f, (Matrix *) &this->unk50.unk14, KDSpline_PositionMixer);
    sp18 = 0.0f;
    sp150.unk10.GetMeasure(0.0f, &this->unk50, KDSpline_PositionMixer);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    sp170 = sp30;
    sp38 = sp168 + sp150.unk8;
    sp178 = (f64) sp38;
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f28 */);
    this->unk200 = sp60;
    sp68 = (f32) sp178 * 0.5f;
    sp180 = sp60;
    sp188 = (f64) sp68;
    this->unk208 = (f64) sp68;
    M2C_ERROR(/* unknown instruction: psq_lx $f4, $zero, $r3, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f4, $f31 */);
    sp130 = spA0;
    spA8 = up.unk8 * 100.0f;
    sp138 = (f64) spA8;
    M2C_ERROR(/* unknown instruction: psq_lx $f3, $r31, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f3, $f0 */);
    temp_f2_1004 = (f32) M2C_FIELD(this, f64 *, 0x208);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f4, $f4, $f30 */);
    sp140 = sp90;
    sp98 = temp_f2_1004 + (f32) sp138;
    sp148 = (f64) sp98;
    sp88 = up.unk8 * 500.0f;
    sp110 = sp80;
    sp118 = (f64) sp88;
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f3, $f0 */);
    sp120 = sp70;
    sp78 = temp_f2_1004 - (f32) sp118;
    sp128 = (f64) sp78;
    if (MKCollision_RayCollide(*((MKVector3 *) &sp140), *((MKVector3 *) &sp120), &sp190, (MKCollisionMode) 4, 0) != 0) {
        this->unk200 = M2C_BITWISE(f64, sp190);
        this->unk208 = (f64) sp190.unk8;
    }
    spC = 0.0f;
    spC0.GetMeasure(0.01f, (Matrix *) &this->unk50.unk14, KDSpline_PositionMixer);
    sp10 = 0.0f;
    spC0.unk10.GetMeasure(0.01f, &this->unk50, KDSpline_PositionMixer);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    spE0 = sp20;
    sp28 = spD8 + spC0.unk8;
    spE8 = (f64) sp28;
    spF0.operator*(0.5f);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $r31, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    var_f4_1085 = 0.0f;
    this->unk210 = sp50;
    sp58 = spF0.unk8 - (f32) M2C_FIELD(this, f64 *, 0x208);
    sp100 = sp50;
    this->unk218 = (f64) sp58;
    M2C_FIELD(this, f32 *, 0x214) = 0.0f;
    temp_f2_1093 = (f32) M2C_FIELD(this, f64 *, 0x210);
    temp_f1_1094 = M2C_FIELD(this, f32 *, 0x214);
    temp_f5_1095 = (f32) M2C_FIELD(this, f64 *, 0x218);
    sp108 = (f64) sp58;
    var_f5_1101 = (temp_f5_1095 * temp_f5_1095) + ((temp_f2_1093 * temp_f2_1093) + (temp_f1_1094 * temp_f1_1094));
    if (var_f5_1101 > 0.000001f) {
        if (var_f5_1101 > 0.0f) {
            temp_f1_1106 = __frsqrte(var_f5_1101);
            temp_f1_1112 = 0.5 * temp_f1_1106 * -(((f64) var_f5_1101 * (temp_f1_1106 * temp_f1_1106)) - 3.0);
            temp_f1_1116 = 0.5 * temp_f1_1112 * -(((f64) var_f5_1101 * (temp_f1_1112 * temp_f1_1112)) - 3.0);
            var_f5_1101 = (f32) ((f64) var_f5_1101 * (0.5 * temp_f1_1116 * -(((f64) var_f5_1101 * (temp_f1_1116 * temp_f1_1116)) - 3.0)));
        } else if (var_f5_1101 < M2C_BITWISE(f32, 0.0)) {
            var_f5_1101 = __float_nan;
        } else {
            sp8 = var_f5_1101;
            temp_r3_1135 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r3_1135) {                 /* irregular */
            case 0x7F800000:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_1145 = 1;
                } else {
                    var_r0_1145 = 2;
                }
                break;
            case 0x0:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_1145 = 5;
                } else {
                    var_r0_1145 = 3;
                }
                break;
            default:
                var_r0_1145 = 4;
                break;
            }
            if (var_r0_1145 == 1) {
                var_f5_1101 = __float_nan;
            }
        }
        var_f4_1085 = 1.0f / var_f5_1101;
    }
    M2C_FIELD(this, f64 *, 0x210) = (f32) ((f32) M2C_FIELD(this, f64 *, 0x210) * var_f4_1085);
    M2C_FIELD(this, f32 *, 0x214) = (f32) (M2C_FIELD(this, f32 *, 0x214) * var_f4_1085);
    M2C_FIELD(this, f64 *, 0x218) = (f32) ((f32) M2C_FIELD(this, f64 *, 0x218) * var_f4_1085);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $r31, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
    spB0 = sp40;
    sp48 = (f32) M2C_FIELD(this, f64 *, 0x218) * 200.0f;
    spB8 = (f64) sp48;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    M2C_ERROR(/* unknown instruction: psq_stx $f0, $r31, $r0, 0x0, qr0 */);
    M2C_FIELD(this, f64 *, 0x208) = (f32) ((f32) M2C_FIELD(this, f64 *, 0x208) - (f32) spB8);
    this->unk1B1 = 1;
}
#endif

void ExplosiveBarrelPath::GetStandDir() {
    ExplosiveBarrelPath *temp_r31_1223;

    temp_r31_1223 = M2C_ERROR(/* Read from unset register $r4 */);
    if ((u8) M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), u8 *, 0x1B1) == 0) {
        temp_r31_1223->CalcStandPosAndDir();
    }
    M2C_FIELD(this, f64 *, 0) = (f64) temp_r31_1223->unk210;
    M2C_FIELD(this, f64 *, 8) = (f64) temp_r31_1223->unk218;
}

void ExplosiveBarrelPath::GetStandPos() {
    ExplosiveBarrelPath *temp_r31_1249;

    temp_r31_1249 = M2C_ERROR(/* Read from unset register $r4 */);
    if ((u8) M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), u8 *, 0x1B1) == 0) {
        temp_r31_1249->CalcStandPosAndDir();
    }
    M2C_FIELD(this, f64 *, 0) = (f64) temp_r31_1249->unk200;
    M2C_FIELD(this, f64 *, 8) = (f64) temp_r31_1249->unk208;
}

#if 0 // DRAFT: ')' expected
void ExplosiveBarrelPath::Message(MKMessage *arg0) {
    s32 temp_r0_1294;
    s32 var_r30_1282;
    s32 var_r31_1283;
    void *temp_r3_1307;

    if ((s32) M2C_FIELD(checked_cast<ExplosiveBarrelPathDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x60) != 0) {
        var_r30_1282 = 0;
        var_r31_1283 = 0;
        do {
            ((KDSoundPlayer *) (this + (var_r31_1283 + 0x94)))->Message(arg0);
            var_r30_1282 += 1;
            var_r31_1283 += 0x44;
        } while (var_r30_1282 < 4);
    }
    temp_r0_1294 = arg0->unk0;
    switch (temp_r0_1294) {                         /* irregular */
    case 0x79:
        temp_r3_1307 = checked_cast<FindInteractivePropMsg *, MKMessage>(arg0);
        if ((s32) M2C_FIELD(temp_r3_1307, s32 *, 8) == 1) {
            M2C_FIELD(temp_r3_1307, ExplosiveBarrelPath **, 0xC) = this;
            return;
        }
        return;
    case 0xB5:
        this->unk231 = 1;
        this->unk238 = 0.0f;
    default:
block_13:
        MKProp::Message(arg0);
        break;
    case 0xB4:
        this->unk231 = 0;
        goto block_13;
    }
}
#endif

#if 0 // DRAFT: ')' expected
void ExplosiveBarrelPath::Update() {
    ExplosiveBarrelPath spC0;
    f64 spB8;
    f64 spB0;
    f64 spA8;
    f64 spA0;
    MKVector3 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp48;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    s32 sp8;
    ExplosiveBarrel *temp_r28_1381;
    MKProp *temp_r4_1524;
    f32 temp_f1_1572;
    f32 temp_f29_1562;
    f32 temp_f3_1543;
    s32 temp_r3_1361;
    s32 temp_r5_1654;
    s32 var_ctr_1433;
    s32 var_ctr_1503;
    s32 var_r25_1606;
    s32 var_r26_1378;
    s32 var_r29_1377;
    s32 var_r3_1431;
    s32 var_r3_1502;
    u32 var_r0_1513;
    u8 var_r25_1465;
    void *temp_r30_1380;
    void *temp_r4_1406;
    void *temp_r4_1506;
    void *temp_r4_1510;
    void *temp_r4_1710;
    void *temp_r5_1437;

    this->unk238 -= gUpdateTimeDelta;
    if ((u8) this->unk231 != 0) {
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if (this->unk238 == 0.0f) {
            temp_r3_1361 = SpawnBarrel(NULL);
            if (temp_r3_1361 > -1) {
                PushBarrel(temp_r3_1361);
            }
            this->unk238 = this->unk234;
            if ((u8) this->unk230 != 0) {
                this->unk231 = 0;
            }
        }
    }
    var_r29_1377 = 0;
    var_r26_1378 = 0;
    do {
        temp_r30_1380 = this + var_r26_1378;
        temp_r28_1381 = M2C_FIELD(temp_r30_1380, ExplosiveBarrel **, 0x78);
        if ((temp_r28_1381 == NULL) || (temp_r28_1381->GetState() == 3) || (((ExplosiveBarrel *) (M2C_FIELD(temp_r30_1380, ExplosiveBarrel **, 0x78)))->IsActive() == 0) || ((u8) M2C_FIELD(temp_r30_1380, u8 *, 0x90) == 0)) {
            if ((temp_r28_1381 != NULL) && ((s32) M2C_FIELD(checked_cast<ExplosiveBarrelPathDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x60) != 0)) {
                temp_r4_1406 = checked_cast<ExplosiveBarrelPathDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
                sp8 = 1;
                ((KDSoundFader *) (temp_r30_1380 + 0x94))->Update(M2C_FIELD(temp_r4_1406, s32 *, 0x60), 1U, 0U, (MKProp *) temp_r28_1381, NULL, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
            }
        } else {
            temp_r28_1381->Enable();
            UpdateBarrelModel(temp_r30_1380 + 0x78);
            var_r3_1431 = 0;
            var_ctr_1433 = 0xF;
            do {
                temp_r5_1437 = &spC0.unk30 + var_r3_1431;
                M2C_FIELD(temp_r5_1437, f32 *, 0) = 0.0f;
                var_r3_1431 += 0x58;
                M2C_FIELD(temp_r5_1437, f32 *, 4) = 0.0f;
                M2C_FIELD(temp_r5_1437, f32 *, 8) = 0.0f;
                M2C_FIELD(temp_r5_1437, f32 *, 0x10) = 0.0f;
                M2C_FIELD(temp_r5_1437, f32 *, 0x14) = 0.0f;
                M2C_FIELD(temp_r5_1437, f32 *, 0x18) = 0.0f;
                M2C_FIELD(temp_r5_1437, f32 *, 0x20) = 0.0f;
                M2C_FIELD(temp_r5_1437, f32 *, 0x24) = 0.0f;
                M2C_FIELD(temp_r5_1437, f32 *, 0x28) = 0.0f;
                M2C_FIELD(temp_r5_1437, f32 *, 0x2C) = 1.0f;
                M2C_FIELD(temp_r5_1437, f32 *, 0x30) = 0.0f;
                M2C_FIELD(temp_r5_1437, f32 *, 0x34) = 0.0f;
                M2C_FIELD(temp_r5_1437, s16 *, 0x38) = 0;
                M2C_FIELD(temp_r5_1437, s8 *, 0x3A) = 0;
                M2C_FIELD(temp_r5_1437, s8 *, 0x3B) = 0;
                M2C_FIELD(temp_r5_1437, s32 *, 0x3C) = 0;
                M2C_FIELD(temp_r5_1437, f32 *, 0x40) = 3.4028235e38f;
                M2C_FIELD(temp_r5_1437, s32 *, 0x44) = 0;
                M2C_FIELD(temp_r5_1437, s32 *, 0x48) = 0;
                M2C_FIELD(temp_r5_1437, s32 *, 0x4C) = -1;
                M2C_FIELD(temp_r5_1437, s8 *, 0x50) = 0;
                var_ctr_1433 -= 1;
            } while (var_ctr_1433 != 0);
            var_r25_1465 = 0;
            spC0.GetBarrelMiddle((ExplosiveBarrelPath::BarrelData *) this);
            spC0.unk20 = M2C_BITWISE(f64, spC0);
            spC0.unk28 = M2C_BITWISE(f64, spC0.unk8);
            sp50 = 0.0f;
            sp54 = M2C_FIELD(temp_r30_1380, f32 *, 0x88);
            sp58 = 0.0f;
            spA0 = (f64) sp50;
            spA8 = (f64) sp58;
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            spB0 = sp40;
            sp48 = M2C_BITWISE(f32, spC0.unk28) + (f32) spA8;
            spB8 = (f64) sp48;
            if (MKCollision_SphereCollide(*((MKVector3 *) &spB0), 100.0f, (MKCollisionResult *) &spC0.unk30, 0xF, (MKCollisionMode) 7, 0) != 0) {
                var_r3_1502 = 0;
                var_ctr_1503 = 0xF;
loop_18:
                temp_r4_1506 = &spC0.unk30 + var_r3_1502;
                if (((u8) M2C_FIELD(temp_r4_1506, u8 *, 0x50) != 0) && (temp_r4_1510 = M2C_FIELD(temp_r4_1506, void **, 0x48), ((temp_r4_1510 == NULL) == 0)) && (var_r0_1513 = M2C_FIELD(temp_r4_1510, u32 *, 8), ((var_r0_1513 == 0U) == 0))) {

                } else {
                    var_r0_1513 = 0U;
                }
                if ((var_r0_1513 != 0U) && (var_r0_1513 != temp_r28_1381) && ((temp_r4_1524 = this->unk4C, ((temp_r4_1524 == NULL) != 0)) || (var_r0_1513 != temp_r4_1524))) {
                    var_r25_1465 = 1;
                } else {
                    var_r3_1502 += 0x58;
                    var_ctr_1503 -= 1;
                    if (var_ctr_1503 != 0) {
                        goto loop_18;
                    }
                }
            }
            if (var_r25_1465 != 0) {
                ExplodeBarrel(var_r29_1377);
            } else {
                temp_f3_1543 = M2C_FIELD(temp_r30_1380, f32 *, 0x84);
                if (temp_f3_1543 < 1000.0f) {
                    M2C_FIELD(temp_r30_1380, f32 *, 0x84) = (f32) ((gUpdateTimeDelta * (1000.0f * this->unk224)) + temp_f3_1543);
                    if (M2C_FIELD(temp_r30_1380, f32 *, 0x84) > 1000.0f) {
                        M2C_FIELD(temp_r30_1380, f32 *, 0x84) = 1000.0f;
                    }
                }
                temp_f29_1562 = (M2C_FIELD(temp_r30_1380, f32 *, 0x84) * this->unk220) / this->unk50.unk8;
                M2C_FIELD(temp_r30_1380, f32 *, 0x80) = (f32) ((gUpdateTimeDelta * (temp_f29_1562 * (0.2f * temp_r28_1381->GetRadius()))) + M2C_FIELD(temp_r30_1380, f32 *, 0x80));
                temp_f1_1572 = M2C_FIELD(temp_r30_1380, f32 *, 0x80);
                if (temp_f1_1572 > 6.2831855f) {
                    M2C_FIELD(temp_r30_1380, f32 *, 0x80) = (f32) (temp_f1_1572 - 6.2831855f);
                }
                M2C_FIELD(temp_r30_1380, f32 *, 0x7C) = (f32) ((temp_f29_1562 * gUpdateTimeDelta) + M2C_FIELD(temp_r30_1380, f32 *, 0x7C));
                if (M2C_FIELD(temp_r30_1380, f32 *, 0x7C) > 1.0f) {
                    ExplodeBarrel(var_r29_1377);
                    M2C_FIELD(temp_r30_1380, f32 *, 0x7C) = 1.0f;
                }
                if ((M2C_FIELD(temp_r30_1380, f32 *, 0x88) < 20.0f) && ((u8) M2C_FIELD(temp_r30_1380, u8 *, 0x91) != 0)) {
                    M2C_FIELD(temp_r30_1380, u8 *, 0x91) = 0U;
                    Tools_GetFloor(*((MKVector3 *) &spC0.unk20), 300.0f, &spC0.unk24);
                    var_r25_1606 = 0;
                    do {
                        sp28 = 1.0f;
                        sp38 = -1.0f;
                        sp20 = 1.0f;
                        sp24 = 1.0f;
                        sp30 = -1.0f;
                        sp34 = 1.0f;
                        sp70 = (f64) sp20;
                        sp78 = (f64) sp28;
                        sp80 = (f64) sp30;
                        sp88 = (f64) sp38;
                        KDRand_Vector(sp90, *((MKVector3 *) &sp80));
                        spC0.unk10 = M2C_BITWISE(f64, sp90);
                        spC0.unk18 = (f64) sp90.unk8;
                        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
                        sp60 = sp10;
                        sp18 = M2C_BITWISE(f32, spC0.unk18) * 200.0f;
                        sp68 = (f64) sp18;
                        EmitDust(*((MKVector3 *) &spC0.unk20), *((MKVector3 *) &sp60), MKRand_Float(&gViewSeed, 0.5f, 1.0f));
                        var_r25_1606 += 1;
                    } while (var_r25_1606 < 0xF);
                }
                temp_r5_1654 = this->unk228;
                if (temp_r5_1654 > 0) {
                    M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
                    if ((M2C_FIELD(temp_r30_1380, f32 *, 0x88) == 10.0f) && (M2C_FIELD(temp_r30_1380, f32 *, 0x8C) < 0.0f) && (MKRand_Int(&gViewSeed, 0, temp_r5_1654) == 0)) {
                        M2C_FIELD(temp_r30_1380, f32 *, 0x8C) = MKRand_Float(&gViewSeed, 0.0f, M2C_FIELD(temp_r30_1380, f32 *, 0x84) * this->unk22C);
                        M2C_FIELD(temp_r30_1380, u8 *, 0x91) = 1U;
                    }
                }
                M2C_FIELD(temp_r30_1380, f32 *, 0x88) = (f32) ((M2C_FIELD(temp_r30_1380, f32 *, 0x8C) * gUpdateTimeDelta) + M2C_FIELD(temp_r30_1380, f32 *, 0x88));
                if (M2C_FIELD(temp_r30_1380, f32 *, 0x88) < 0.0f) {
                    M2C_FIELD(temp_r30_1380, f32 *, 0x88) = 0.0f;
                    M2C_FIELD(temp_r30_1380, f32 *, 0x8C) = (f32) (0.5f * -M2C_FIELD(temp_r30_1380, f32 *, 0x8C));
                }
                M2C_FIELD(temp_r30_1380, f32 *, 0x8C) = (f32) -((1960.0f * gUpdateTimeDelta) - M2C_FIELD(temp_r30_1380, f32 *, 0x8C));
                if ((s32) M2C_FIELD(checked_cast<ExplosiveBarrelPathDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x60) != 0) {
                    temp_r4_1710 = checked_cast<ExplosiveBarrelPathDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
                    sp8 = 1;
                    ((KDSoundFader *) (temp_r30_1380 + 0x94))->Update(M2C_FIELD(temp_r4_1710, s32 *, 0x60), 1U, 1U, (MKProp *) temp_r28_1381, NULL, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
                }
            }
        }
        var_r29_1377 += 1;
        var_r26_1378 += 0x44;
    } while (var_r29_1377 < 4);
}
#endif

void ExplosiveBarrelPath::Resolve() {
    MKProp::Resolve();
}

#if 0 // DRAFT: undefined identifier 'unk1BC'
void ExplosiveBarrelPath::LoadDone() {
    f64 sp20;
    f64 sp18;
    f32 sp10;
    s32 temp_r26_1877;
    s32 var_r27_1807;
    s32 var_r29_1806;
    s8 *var_r4_1814;
    u8 temp_r0_1837;
    void *temp_r3_1815;
    void *temp_r3_1827;
    void *temp_r3_1879;
    void *var_r3_1818;
    void *var_r3_1830;

    MKProp::LoadDone();
    this->unk1B1 = 0;
    M2C_STRUCT_COPY((s32) &this->unk1BC + 4, (s32) (&loadInfo - 4) + 4, 0x40);
    this->unk200 = this->unk1F0;
    this->unk208 = this->unk1F8;
    this->unk210 = this->unk1E0;
    this->unk218 = this->unk1E8;
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $r28, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
    sp18 = sp8;
    sp10 = (f32) M2C_FIELD(this, f64 *, 0x218) * 200.0f;
    sp20 = (f64) sp10;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r28, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    M2C_ERROR(/* unknown instruction: psq_stx $f0, $r28, $r0, 0x0, qr0 */);
    var_r29_1806 = 0;
    var_r27_1807 = 0;
    M2C_FIELD(this, f64 *, 0x208) = (f32) ((f32) M2C_FIELD(this, f64 *, 0x208) - (f32) sp20);
    do {
        var_r4_1814 = lit_stringBase0;
        temp_r3_1815 = M2C_FIELD(M2C_FIELD(&gb, void **, 0x32C), void **, 0x18);
        if (temp_r3_1815 != NULL) {
            var_r3_1818 = M2C_FIELD(temp_r3_1815, void **, 4);
        } else {
            var_r3_1818 = M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x32C), void **, 0x24), void **, 4);
        }
        if ((u32) M2C_FIELD(var_r3_1818, u32 *, 0xC) != 0U) {
            temp_r3_1827 = M2C_FIELD(M2C_FIELD(&gb, void **, 0x32C), void **, 0x18);
            if (temp_r3_1827 != NULL) {
                var_r3_1830 = M2C_FIELD(temp_r3_1827, void **, 4);
            } else {
                var_r3_1830 = M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x32C), void **, 0x24), void **, 4);
            }
            temp_r0_1837 = *M2C_FIELD(var_r3_1830, u8 **, 0xC);
            switch ((s8) temp_r0_1837) {            /* irregular */
            case 0x61:
                this->unk232 = 1;
                var_r4_1814 = &lit_stringBase0[0x11];
                break;
            case 0x62:
                var_r4_1814 = &lit_stringBase0[0x22];
                break;
            case 0x64:
            case 0x7A:
                var_r4_1814 = &lit_stringBase0[0x33];
                break;
            case 0x63:
                var_r4_1814 = &lit_stringBase0[0x44];
                break;
            }
        }
        temp_r26_1877 = var_r27_1807 + 0x78;
        *(this + temp_r26_1877) = checked_cast<ExplosiveBarrel *, MKProp>(gMK->CreateProp(var_r4_1814));
        temp_r3_1879 = *(this + temp_r26_1877);
        if (temp_r3_1879 != NULL) {
            M2C_FIELD(M2C_FIELD(temp_r3_1879, void **, 0x44), M2C_UNK (**)(), 0x34)();
            ((ExplosiveBarrel *) (*(this + temp_r26_1877)))->SetOwner(this);
            ((ExplosiveBarrel *) (*(this + temp_r26_1877)))->SetActive(0U);
            M2C_FIELD(*(this + temp_r26_1877), f32 *, 0x1B0) = (f32) this->unk23C;
        }
        var_r29_1806 += 1;
        var_r27_1807 += 0x44;
    } while (var_r29_1806 < 4);
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_stringBase0'
s32 ExplosiveBarrelPath::LoadLine(MKIniLine *arg0) {
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    MKIniLine sp58;
    MKVector3 sp48;
    MKVector3 sp38;
    MKIniLine sp28;
    MKVector3 sp18;
    MKVector3 sp8;
    MKIniLine *var_r30_1936;
    MKIniLine *var_r30_2010;
    f64 temp_f0_1951;
    f64 temp_f0_2025;
    f64 temp_f1_1950;
    f64 temp_f1_2024;
    s32 temp_r3_1937;
    s32 temp_r3_2011;
    s32 var_r31_2077;

    if (MKProp::LoadLine(arg0) != 0) {
        return 1;
    }
    if (arg0->IsField(&lit_stringBase0[0x55]) != 0) {
        var_r30_1936 = arg0->unkC->GetSubLine(arg0);
        temp_r3_1937 = arg0->GetNmbrOfSubLines();
        if (temp_r3_1937 != 0) {
            this->unk50.Init(temp_r3_1937, 0U);
loop_9:
            if (var_r30_1936 != NULL) {
                sp58.GetVector3((s32) var_r30_1936);
                temp_f1_1950 = M2C_BITWISE(f64, sp58);
                temp_f0_1951 = M2C_BITWISE(f64, sp58.unk8);
                sp78 = temp_f1_1950;
                sp80 = temp_f0_1951;
                if ((u8) this->unk1B0 != 0) {
                    this->unk190 = temp_f1_1950;
                    this->unk198 = temp_f0_1951;
                    this->unk1A0 = sp78;
                    this->unk1A8 = sp80;
                    this->unk1B0 = 0;
                } else {
                    Min(sp48, *((MKVector3 *) &this->unk190));
                    this->unk190 = M2C_BITWISE(f64, sp48);
                    this->unk198 = (f64) sp48.unk8;
                    Max(sp38, *((MKVector3 *) &this->unk1A0));
                    this->unk1A0 = M2C_BITWISE(f64, sp38);
                    this->unk1A8 = (f64) sp38.unk8;
                }
                this->unk50.AddNode(*((MKVector3 *) &sp78));
                var_r30_1936 = var_r30_1936->unkC->GetNextLine(var_r30_1936);
                goto loop_9;
            }
        }
        return 1;
    }
    if (arg0->IsField(&lit_stringBase0[0x5F]) != 0) {
        var_r30_2010 = arg0->unkC->GetSubLine(arg0);
        temp_r3_2011 = arg0->GetNmbrOfSubLines();
        if (temp_r3_2011 != 0) {
            this->unk50.unk14.Init(temp_r3_2011, 0U);
loop_18:
            if (var_r30_2010 != NULL) {
                sp28.GetVector3((s32) var_r30_2010);
                temp_f1_2024 = M2C_BITWISE(f64, sp28);
                temp_f0_2025 = M2C_BITWISE(f64, sp28.unk8);
                sp68 = temp_f1_2024;
                sp70 = temp_f0_2025;
                if ((u8) this->unk1B0 != 0) {
                    this->unk190 = temp_f1_2024;
                    this->unk198 = temp_f0_2025;
                    this->unk1A0 = sp68;
                    this->unk1A8 = sp70;
                    this->unk1B0 = 0;
                } else {
                    Min(sp18, *((MKVector3 *) &this->unk190));
                    this->unk190 = M2C_BITWISE(f64, sp18);
                    this->unk198 = (f64) sp18.unk8;
                    Max(sp8, *((MKVector3 *) &this->unk1A0));
                    this->unk1A0 = M2C_BITWISE(f64, sp8);
                    this->unk1A8 = (f64) sp8.unk8;
                }
                this->unk50.unk14.AddNode(*((MKVector3 *) &sp68));
                var_r30_2010 = var_r30_2010->unkC->GetNextLine(var_r30_2010);
                goto loop_18;
            }
        }
        return 1;
    }
    var_r31_2077 = 0;
    if ((arg0->LoadFloat(&lit_stringBase0[0x6A], &this->unk220, 0) != 0) || (arg0->LoadFloat(&lit_stringBase0[0x70], &this->unk224, 0) != 0) || (arg0->LoadInt(&lit_stringBase0[0x7D], &this->unk228, 0) != 0) || (arg0->LoadFloat(&lit_stringBase0[0x8A], &this->unk22C, 0) != 0) || (arg0->LoadBool(&lit_stringBase0[0x96], &this->unk231, 0) != 0) || (arg0->LoadBool(&lit_stringBase0[0xA8], &this->unk230, 0) != 0) || (arg0->LoadFloat(&lit_stringBase0[0xB1], &this->unk234, 0) != 0) || (arg0->LoadFloat(&lit_stringBase0[0xC1], &this->unk23C, 0) != 0)) {
        var_r31_2077 = 1;
    }
    return var_r31_2077;
}
#endif

#if 0 // DRAFT: undefined identifier 'Deinit'
void ExplosiveBarrelPath::Deinit() {
    s32 var_r29_2170;
    s32 var_r31_2171;
    void *temp_r30_2173;
    void *temp_r3_2174;

    MKProp::Deinit();
    this->unk50.Deinit();
    this->unk50.unk14.Deinit();
    var_r29_2170 = 0;
    var_r31_2171 = 0;
    do {
        temp_r30_2173 = this + var_r31_2171;
        temp_r3_2174 = M2C_FIELD(temp_r30_2173, void **, 0x78);
        M2C_FIELD(M2C_FIELD(temp_r3_2174, void **, 0x44), M2C_UNK (**)(void *), 0x34)(temp_r3_2174);
        KDSound_Stop(temp_r30_2173 + 0x94);
        var_r29_2170 += 1;
        var_r31_2171 += 0x44;
    } while (var_r29_2170 < 4);
}
#endif

#if 0 // DRAFT: illegal type
void ExplosiveBarrelPath::Init() {
    s32 var_r26_2206;
    s32 var_r30_2203;
    void *temp_r4_2210;

    MKProp::Init();
    var_r30_2203 = 0;
    var_r26_2206 = 0;
    do {
        temp_r4_2210 = this + var_r30_2203;
        M2C_FIELD(temp_r4_2210, s32 *, 0x78) = 0;
        M2C_FIELD(temp_r4_2210, f32 *, 0x7C) = 0.0f;
        M2C_FIELD(temp_r4_2210, f32 *, 0x80) = 0.0f;
        M2C_FIELD(temp_r4_2210, f32 *, 0x84) = 0.0f;
        M2C_FIELD(temp_r4_2210, f32 *, 0x88) = 0.0f;
        M2C_FIELD(temp_r4_2210, f32 *, 0x8C) = 0.0f;
        M2C_FIELD(temp_r4_2210, s8 *, 0x90) = 0;
        M2C_FIELD(temp_r4_2210, s8 *, 0x91) = 0;
        ((KDSoundFader *) (temp_r4_2210 + 0x94))->Init(0.25f, 0.25f);
        var_r26_2206 += 1;
        var_r30_2203 += 0x44;
    } while (var_r26_2206 < 4);
    this->unk4C = NULL;
    this->unk190 = M2C_FIELD(&zero, f64 *, 0);
    this->unk198 = M2C_FIELD(&zero, f64 *, 8);
    this->unk1A0 = M2C_FIELD(&zero, f64 *, 0);
    this->unk1A8 = M2C_FIELD(&zero, f64 *, 8);
    this->unkC = (BoundingVolume *) &this->unk190;
    this->unk1B0 = 1;
    M2C_STRUCT_COPY((s32) &this->unk1BC + 4, (s32) (&identity - 4) + 4, 0x40);
    this->unk8 = &this->unk1C0;
    this->unk200 = M2C_FIELD(&zero, f64 *, 0);
    this->unk208 = M2C_FIELD(&zero, f64 *, 8);
    this->unk210 = M2C_FIELD(&zero, f64 *, 0);
    this->unk218 = M2C_FIELD(&zero, f64 *, 8);
    this->unk228 = 0x14;
    this->unk22C = 1.0f;
    this->unk231 = 0;
    this->unk230 = 0;
    this->unk232 = 0;
    this->unk234 = 1.0f;
    this->unk238 = 0.0f;
    this->unk23C = 1.0f;
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_stringBase0'
void ExplosiveBarrelPathDescriptor::LoadDone() {
    this->unk90 = checked_cast<KDEnvParticleSystem *, MKProp>(gMK->CreateProp(&lit_stringBase0[0xD7]));
    this->unk94 = checked_cast<KDEnvParticleSystem *, MKProp>(gMK->CreateProp(&lit_stringBase0[0xE8]));
    MKPropDescriptor::LoadDone();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_stringBase0'
s32 ExplosiveBarrelPathDescriptor::LoadLine(MKIniLine *arg0) {
    s32 var_r31_2324;

    var_r31_2324 = 0;
    if ((MKPropDescriptor::LoadLine(arg0) != 0) || (KDSound_LoadLine(arg0, &lit_stringBase0[0xF8], &this->unk60) != 0)) {
        var_r31_2324 = 1;
    }
    return var_r31_2324;
}
#endif

#if 0 // DRAFT: undefined identifier 'zero'
void ExplosiveBarrelPathDescriptor::Init() {
    MKPropDescriptor::Init();
    M2C_FIELD(this, f64 *, 0x70) = (f64) M2C_FIELD(&zero, f64 *, 0);
    this->unk78 = M2C_FIELD(&zero, f64 *, 8);
    this->unk80 = M2C_FIELD(&zero, f64 *, 0);
    this->unk88 = M2C_FIELD(&zero, f64 *, 8);
    this->unk60 = 0;
    this->unk1C = (BoundingVolume *) &this->unk70;
    this->unkC |= 0x802;
}
#endif

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<ExplosiveBarrel *, MKProp>(MKProp *arg0) {

}
#endif

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<ExplosiveBarrelPathDescriptor *, MKPropDescriptor>(MKPropDescriptor *arg0) {

}
#endif
