#include "spyro/source/GunPowderFuse.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/BaseBreathFX.h"
#include "spyro/source/BurnPoint.h"
#include "spyro/source/Coronas.h"
#include "spyro/source/FireBombFX.h"
#include "spyro/source/Game.h"
#include "spyro/source/GameData.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSpline.h"
#include "spyro/source/LiquidFX.h"
#include "spyro/source/SplineProp.h"
#include "unplaced_templates.h"
#include "common/Source/StdMath.h"
#include "common/gc/MKMaterial_GC.h"
#include "common/gc/MKPrimitive_GC.h"
#include "spyro/source/KDRandom.h"
#include "spyro/source/Tools.h"
#include <m2c_macros.h>

M2C_UNK __destroy_arr(M2C_UNK *, BurnPoint *(*)(BurnPoint *, s16), M2C_UNK, M2C_UNK); /* extern */
s32 stricmp(s32, M2C_UNK *);                        /* extern */
extern s32 GS_GunpowderBurnLP;
extern f32 *KDSpline_PositionMixer;
extern f32 SPYRO_BOUNCE_Y_SPEED;
extern f32 SPYRO_MIN_JUMP_Y_VELOCITY;
extern void **gMK;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern GameGlobals gb;
static s32 lit_743 = 2;
static u8 lit_744 = 0;

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'KDSplinePathSegment'
void GunPowderFuse::EmitBurn(float arg0) {
    f64 sp100;
    f64 spF8;
    f64 spF0;
    f32 spEC;
    KDUniformSpline spD8;
    f64 spD0;
    f64 spC8;
    M2C_UNK spB8;
    f64 spB0;
    f64 spA8;
    MKVector3 sp98;
    M2C_UNK sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    M2C_UNK sp58;
    f32 sp50;
    f32 sp40;
    f32 sp30;
    f32 sp20;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f28_141;
    f32 temp_f29_135;
    f32 temp_f29_88;
    f32 temp_f2_128;
    f32 temp_f2_140;
    f32 temp_f2_198;
    f32 temp_f31_170;
    f32 temp_f3_105;
    f32 temp_f3_116;

    sp8 = 0.0f;
    spD8.GetMeasure(arg0, (Matrix *) &this->unkB0->unk30, KDSpline_PositionMixer);
    spF8 = M2C_BITWISE(f64, spD8);
    sp100 = (f64) spD8.unk8;
    temp_f29_88 = 100.0f * (this->unkB4 / 20.0f);
    KDRand_UnitVectorXZ();
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
    spD8.unk10 = sp28;
    sp30 = spC0 * temp_f29_88;
    spC8 = sp28;
    spF0 = (f64) sp30;
    temp_f3_105 = this->unkB4;
    spD0 = (f64) sp30;
    spEC = 100.0f * MKRand_Float(&gViewSeed, temp_f3_105 / 10.0f, temp_f3_105 / 3.3333f);
    temp_f3_116 = this->unkB4;
    sp10 = MKRand_Float(&gViewSeed, temp_f3_116 / 40.0f, temp_f3_116 / 20.0f);
    gb.EmitDust(*((MKVector3 *) &spF8), *((MKVector3 *) &spD8.unk10), sp10, 0.0f);
    temp_f2_128 = this->unkB4;
    temp_f29_135 = MKRand_Float(&gViewSeed, -temp_f2_128 / 10.0f, temp_f2_128 / 10.0f);
    temp_f2_140 = this->unkB4;
    temp_f28_141 = MKRand_Float(&gViewSeed, 0.0f, this->unkB4);
    MKVector(MKRand_Float(&gViewSeed, -temp_f2_140 / 10.0f, temp_f2_140 / 10.0f), temp_f28_141, temp_f29_135);
    Normalise(sp98);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
    spD8.unk10 = sp18;
    sp20 = sp98.unk8 * 500.0f;
    spA8 = sp18;
    spF0 = (f64) sp20;
    spB0 = (f64) sp20;
    temp_f31_170 = this->unkB4;
    KDRand_UnitVectorXZ();
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
    sp68 = sp48;
    sp50 = sp60 * temp_f31_170;
    sp70 = (f64) sp50;
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    sp78 = sp38;
    sp40 = (f32) sp100 + (f32) sp70;
    sp80 = (f64) sp40;
    temp_f2_198 = this->unkB4;
    spC = MKRand_Float(&gViewSeed, temp_f2_198 / 6.6666f, temp_f2_198 / 3.3333f);
    gb.unk84->Emit(*((MKVector3 *) &sp78), *((MKVector3 *) &spD8.unk10), spC);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'GunPowderFuse' to
BurnPoint *GunPowderFuse::GetFirst() {
    f32 temp_f3_239;
    f32 var_f0_248;
    f32 var_f4_228;
    s32 var_ctr_236;
    s32 var_r3_235;
    s32 var_r4_233;
    s32 var_r5_234;

    var_f4_228 = 1.0f;
    var_r4_233 = -1;
    var_r5_234 = 0;
    var_r3_235 = 0;
    var_ctr_236 = 8;
    do {
        temp_f3_239 = *(this + (var_r3_235 + 0xCC));
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if (temp_f3_239 == 1.0f) {
            M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
            if (temp_f3_239 == 0.0f) {
                if (temp_f3_239 < 0.0f) {
                    var_f0_248 = -temp_f3_239;
                } else {
                    var_f0_248 = temp_f3_239;
                }
                if (var_f0_248 < var_f4_228) {
                    var_f4_228 = temp_f3_239;
                    var_r4_233 = var_r5_234;
                }
            }
        }
        var_r5_234 += 1;
        var_r3_235 += 0x3C;
        var_ctr_236 -= 1;
    } while (var_ctr_236 != 0);
    if (var_r4_233 != -1) {
        return this + ((var_r4_233 * 0x3C) + 0xC4);
    }
    return NULL;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk8'
BurnPoint *GunPowderFuse::GetNextPositive(BurnPoint *arg0) {
    f32 temp_f4_292;
    f32 temp_f4_306;
    f32 var_f0_309;
    f32 var_f3_278;
    f32 var_f5_283;
    s32 var_ctr_289;
    s32 var_r3_288;
    s32 var_r6_285;
    s32 var_r7_286;
    void *temp_r5_291;

    if (arg0 != NULL) {
        var_f3_278 = arg0->unk8;
    } else {
        var_f3_278 = 0.0f;
    }
    var_f5_283 = 1.0f;
    var_r6_285 = -1;
    var_r7_286 = 0;
    var_r3_288 = 0;
    var_ctr_289 = 8;
    do {
        temp_r5_291 = this + var_r3_288;
        temp_f4_292 = M2C_FIELD(temp_r5_291, f32 *, 0xCC);
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if (temp_f4_292 == 1.0f) {
            M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
            if ((temp_f4_292 == 0.0f) && (M2C_FIELD(temp_r5_291, f32 *, 0xD0) == 1.0f) && (temp_f4_292 > var_f3_278)) {
                temp_f4_306 = temp_f4_292 - arg0->unk8;
                if (temp_f4_306 < 0.0f) {
                    var_f0_309 = -temp_f4_306;
                } else {
                    var_f0_309 = temp_f4_306;
                }
                if ((var_f0_309 < var_f5_283) && ((void *) (temp_r5_291 + 0xC4) != arg0)) {
                    if (temp_f4_306 < 0.0f) {
                        var_f5_283 = -temp_f4_306;
                    } else {
                        var_f5_283 = temp_f4_306;
                    }
                    var_r6_285 = var_r7_286;
                }
            }
        }
        var_r7_286 += 1;
        var_r3_288 += 0x3C;
        var_ctr_289 -= 1;
    } while (var_ctr_289 != 0);
    if (var_r6_285 != -1) {
        return this + ((var_r6_285 * 0x3C) + 0xC4);
    }
    return NULL;
}
#endif

#if 0 // DRAFT: illegal type
void GunPowderFuse::UpdatePartners() {
    f32 temp_f0_361;
    s32 var_r29_357;
    s32 var_r31_358;
    void *temp_r30_360;

    var_r29_357 = 0;
    var_r31_358 = 0;
    do {
        temp_r30_360 = this + var_r31_358;
        temp_f0_361 = M2C_FIELD(temp_r30_360, f32 *, 0xCC);
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if (temp_f0_361 == 1.0f) {
            M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
            if (temp_f0_361 == 0.0f) {
                M2C_FIELD(temp_r30_360, s32 *, 0xD4) = GetPartner(temp_r30_360 + 0xC4);
            }
        }
        var_r29_357 += 1;
        var_r31_358 += 0x3C;
    } while (var_r29_357 < 8);
}
#endif

#if 0 // DRAFT: undefined identifier 'unkC'
s32 GunPowderFuse::GetPartner(BurnPoint *arg0) {
    f32 temp_f0_415;
    f32 temp_f0_465;
    f32 temp_f1_418;
    f32 temp_f3_454;
    f32 temp_f3_468;
    f32 temp_f4_403;
    f32 var_f0_421;
    f32 var_f0_471;
    f32 var_f5_391;
    s32 var_ctr_400;
    s32 var_ctr_451;
    s32 var_r5_399;
    s32 var_r5_450;
    s32 var_r7_397;
    s32 var_r8_398;
    s32 var_r8_449;
    void *temp_r6_402;
    void *temp_r6_453;

    var_f5_391 = 1.0f;
    if (arg0->unkC == 1.0f) {
        var_r7_397 = 0x64;
        var_r8_398 = 0;
        var_r5_399 = 0;
        var_ctr_400 = 8;
        do {
            temp_r6_402 = this + var_r5_399;
            temp_f4_403 = M2C_FIELD(temp_r6_402, f32 *, 0xCC);
            M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
            if (temp_f4_403 == 1.0f) {
                M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
                if ((temp_f4_403 == 0.0f) && (M2C_FIELD(temp_r6_402, f32 *, 0xD0) == -1.0f)) {
                    temp_f0_415 = arg0->unk8;
                    if (temp_f4_403 > temp_f0_415) {
                        temp_f1_418 = temp_f4_403 - temp_f0_415;
                        if (temp_f1_418 < 0.0f) {
                            var_f0_421 = -temp_f1_418;
                        } else {
                            var_f0_421 = temp_f1_418;
                        }
                        if ((var_f0_421 < var_f5_391) && ((void *) (temp_r6_402 + 0xC4) != arg0)) {
                            if (temp_f1_418 < 0.0f) {
                                var_f5_391 = -temp_f1_418;
                            } else {
                                var_f5_391 = temp_f1_418;
                            }
                            var_r7_397 = var_r8_398;
                        }
                    }
                }
            }
            var_r8_398 += 1;
            var_r5_399 += 0x3C;
            var_ctr_400 -= 1;
        } while (var_ctr_400 != 0);
    } else {
        var_r7_397 = -0x64;
        var_r8_449 = 0;
        var_r5_450 = 0;
        var_ctr_451 = 8;
        do {
            temp_r6_453 = this + var_r5_450;
            temp_f3_454 = M2C_FIELD(temp_r6_453, f32 *, 0xCC);
            M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
            if (temp_f3_454 == 1.0f) {
                M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
                if ((temp_f3_454 == 0.0f) && (M2C_FIELD(temp_r6_453, f32 *, 0xD0) == 1.0f)) {
                    temp_f0_465 = arg0->unk8;
                    if (temp_f3_454 < temp_f0_465) {
                        temp_f3_468 = temp_f3_454 - temp_f0_465;
                        if (temp_f3_468 < 0.0f) {
                            var_f0_471 = -temp_f3_468;
                        } else {
                            var_f0_471 = temp_f3_468;
                        }
                        if ((var_f0_471 < var_f5_391) && ((void *) (temp_r6_453 + 0xC4) != arg0)) {
                            if (temp_f3_468 < 0.0f) {
                                var_f5_391 = -temp_f3_468;
                            } else {
                                var_f5_391 = temp_f3_468;
                            }
                            var_r7_397 = var_r8_449;
                        }
                    }
                }
            }
            var_r8_449 += 1;
            var_r5_450 += 0x3C;
            var_ctr_451 -= 1;
        } while (var_ctr_451 != 0);
    }
    return var_r7_397;
}
#endif

#if 0 // DRAFT: undefined identifier 'unkC'
u8 GunPowderFuse::IsBurnable(float arg0) {
    BurnPoint *var_r4_520;
    s32 temp_r0_534;

    if (IsBurntOut() != 0) {
        return 0U;
    }
    var_r4_520 = GetFirst();
    if (var_r4_520 == NULL) {
        return 1U;
    }
loop_18:
    if (var_r4_520 == NULL) {
        return 0U;
    }
    if (var_r4_520->unkC == 1.0f) {
        if (arg0 > var_r4_520->unk8) {
            temp_r0_534 = var_r4_520->unk10;
            if (temp_r0_534 == 0x64) {
                if (arg0 < 1.0f) {
                    return 1U;
                }
                goto block_13;
            }
            if (arg0 < *(this + ((temp_r0_534 * 0x3C) + 0xCC))) {
                return 1U;
            }
block_13:
            var_r4_520 = GetNextPositive(var_r4_520);
            goto loop_18;
        }
        return 0U;
    }
    if ((arg0 > M2C_BITWISE(f32, 0.0)) && (arg0 < var_r4_520->unk8)) {
        return 1U;
    }
    var_r4_520 = GetNextPositive(var_r4_520);
    goto loop_18;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'GunPowderFuse' to
u8 GunPowderFuse::TooClose(float arg0) {
    f32 temp_f0_597;
    f32 var_f5_604;
    s32 var_ctr_594;
    s32 var_r4_592;

    var_r4_592 = 0;
    var_ctr_594 = 8;
loop_1:
    temp_f0_597 = *(this + (var_r4_592 + 0xCC));
    M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
    if (temp_f0_597 == 1.0f) {
        M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
        if (temp_f0_597 == 0.0f) {
            var_f5_604 = temp_f0_597 - arg0;
            if (var_f5_604 < 0.0f) {
                var_f5_604 = -var_f5_604;
            }
            if (var_f5_604 < (2.0f * this->unk2A8)) {
                return 1U;
            }
            goto block_7;
        }
    }
block_7:
    var_r4_592 += 0x3C;
    var_ctr_594 -= 1;
    if (var_ctr_594 == 0) {
        return 0U;
    }
    goto loop_1;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'GunPowderFuse' to
u8 GunPowderFuse::HasAvailableBurnPoints() {
    f32 temp_f2_633;
    s32 var_ctr_630;
    s32 var_r4_629;
    s32 var_r5_628;

    var_r5_628 = 0;
    var_r4_629 = 0;
    var_ctr_630 = 8;
loop_1:
    temp_f2_633 = *(this + (var_r4_629 + 0xCC));
    M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
    if ((temp_f2_633 != 1.0f) || (M2C_ERROR(/* unknown instruction: cror eq, gt, eq */), ((temp_f2_633 == 0.0f) == 0))) {
        var_r5_628 += 1;
    }
    if (var_r5_628 == 2) {
        return 1U;
    }
    var_r4_629 += 0x3C;
    var_ctr_630 -= 1;
    if (var_ctr_630 == 0) {
        return 0U;
    }
    goto loop_1;
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_sp34C'
void GunPowderFuse::Draw() {
    BurnPoint *var_r28_1093;
    f32 temp_f18_1504;
    f32 temp_f18_762;
    f32 temp_f18_998;
    f32 temp_f20_748;
    f32 temp_f21_746;
    f32 temp_f22_744;
    f32 temp_f24_1094;
    f32 temp_f25_1096;
    f32 temp_f26_1097;
    f32 temp_f29_720;
    f32 temp_f3_1379;
    f32 temp_f3_873;
    f32 temp_f4_1377;
    f32 temp_f4_871;
    f32 temp_f5_1380;
    f32 temp_f5_874;
    f32 var_f1_1132;
    f32 var_f1_1275;
    f32 var_f27_1111;
    f32 var_f28_1106;
    f32 var_f2_1129;
    f32 var_f2_1370;
    f32 var_f2_1473;
    f32 var_f2_864;
    f32 var_f2_967;
    f32 var_f4_1303;
    f32 var_f4_1406;
    f32 var_f4_797;
    f32 var_f4_900;
    f64 temp_f1_1309;
    f64 temp_f1_1315;
    f64 temp_f1_1319;
    f64 temp_f1_1412;
    f64 temp_f1_1418;
    f64 temp_f1_1422;
    f64 temp_f1_803;
    f64 temp_f1_809;
    f64 temp_f1_813;
    f64 temp_f1_906;
    f64 temp_f1_912;
    f64 temp_f1_916;
    s32 temp_r0_1105;
    s32 temp_r0_1137;
    s32 temp_r3_1338;
    s32 temp_r3_1441;
    s32 temp_r3_832;
    s32 temp_r3_935;
    s32 var_r0_1348;
    s32 var_r0_1451;
    s32 var_r0_842;
    s32 var_r0_945;
    s32 var_r29_1176;
    s32 var_r29_745;
    s32 var_r30_1162;
    if (IsBurntOut() == 0) {
        M2C_STRUCT_COPY((s32) &arg_sp34C + 4, (s32) &this->unk4C + 4, 0x40);
        arg_sp338 = 1.0f;
        arg_sp33C = 1.0f;
        temp_f29_720 = 1.0f / (f32) this->unk2B4;
        arg_sp340 = 1.0f;
        arg_sp350.Scale3x3((Matrix *) &arg_sp350, *((MKVector3 *) &arg_sp338));
        if (IsBurning() == 0) {
            MKMaterial_SetMaterial(this->unk2A4);
            MKPrimitive(0xC, 0x10);
            MKSetMatrix(*((Matrix *) &arg_sp350));
            MKBegin((this->unk2B4 + 1) * 2);
            temp_f22_744 = MKVector3::up.unk4;
            var_r29_745 = 0;
            temp_f21_746 = MKVector3::up.unk8;
            temp_f20_748 = MKVector3::up.unk0;
loop_44:
            if (var_r29_745 < (s32) (this->unk2B4 + 1)) {
                arg_sp2D8.GetPos();
                temp_f18_762 = (f32) var_r29_745 * temp_f29_720;
                arg_sp2E8.GetPosition(temp_f18_762);
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r30, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
                arg_sp328 = arg_sp78;
                arg_sp2F8 = arg_sp78;
                arg_sp80 = arg_sp2F0 - arg_sp2E0;
                arg_sp32C += 1.0f;
                arg_sp300 = (f64) arg_sp80;
                arg_sp330 = (f64) arg_sp80;
                arg_sp2C8.GetVelocity(temp_f18_762);
                arg_sp318 = arg_sp2C8;
                arg_sp320 = arg_sp2D0;
                var_f4_797 = ((f32) arg_sp320 * (f32) arg_sp320) + (((f32) arg_sp318 * (f32) arg_sp318) + (arg_sp31C * arg_sp31C));
                if (var_f4_797 > 0.000001f) {
                    if (var_f4_797 > 0.0f) {
                        temp_f1_803 = __frsqrte(var_f4_797);
                        temp_f1_809 = 0.5 * temp_f1_803 * -(((f64) var_f4_797 * (temp_f1_803 * temp_f1_803)) - 3.0);
                        temp_f1_813 = 0.5 * temp_f1_809 * -(((f64) var_f4_797 * (temp_f1_809 * temp_f1_809)) - 3.0);
                        var_f4_797 = (f32) ((f64) var_f4_797 * (0.5 * temp_f1_813 * -(((f64) var_f4_797 * (temp_f1_813 * temp_f1_813)) - 3.0)));
                    } else if (var_f4_797 < M2C_BITWISE(f32, 0.0)) {
                        var_f4_797 = __float_nan;
                    } else {
                        arg_sp1C = var_f4_797;
                        temp_r3_832 = M2C_BITWISE(s32, arg_sp1C) & 0x7F800000;
                        switch (temp_r3_832) {      /* switch 1; irregular */
                        case 0x7F800000:            /* switch 1 */
                            if (M2C_BITWISE(s32, arg_sp1C) & 0x7FFFFF) {
                                var_r0_842 = 1;
                            } else {
                                var_r0_842 = 2;
                            }
                            break;
                        case 0x0:                   /* switch 1 */
                            if (M2C_BITWISE(s32, arg_sp1C) & 0x7FFFFF) {
                                var_r0_842 = 5;
                            } else {
                                var_r0_842 = 3;
                            }
                            break;
                        default:                    /* switch 1 */
                            var_r0_842 = 4;
                            break;
                        }
                        if (var_r0_842 == 1) {
                            var_f4_797 = __float_nan;
                        }
                    }
                    var_f2_864 = 1.0f / var_f4_797;
                } else {
                    var_f2_864 = 0.0f;
                }
                temp_f4_871 = arg_sp31C * var_f2_864;
                temp_f3_873 = (f32) arg_sp320 * var_f2_864;
                temp_f5_874 = (f32) arg_sp318 * var_f2_864;
                arg_sp31C = temp_f4_871;
                arg_sp318 = temp_f5_874;
                arg_sp320 = temp_f3_873;
                arg_sp68 = (temp_f22_744 * temp_f3_873) - (temp_f21_746 * temp_f4_871);
                arg_sp6C = (temp_f21_746 * temp_f5_874) - (temp_f20_748 * temp_f3_873);
                arg_sp70 = (temp_f20_748 * temp_f4_871) - (temp_f22_744 * temp_f5_874);
                arg_sp308 = (f64) arg_sp68;
                arg_sp310 = (f64) arg_sp70;
                arg_sp2B8 = (f64) arg_sp68;
                arg_sp2C0 = (f64) arg_sp70;
                var_f4_900 = ((f32) arg_sp310 * (f32) arg_sp310) + (((f32) arg_sp308 * (f32) arg_sp308) + (arg_sp30C * arg_sp30C));
                if (var_f4_900 > 0.000001f) {
                    if (var_f4_900 > 0.0f) {
                        temp_f1_906 = __frsqrte(var_f4_900);
                        temp_f1_912 = 0.5 * temp_f1_906 * -(((f64) var_f4_900 * (temp_f1_906 * temp_f1_906)) - 3.0);
                        temp_f1_916 = 0.5 * temp_f1_912 * -(((f64) var_f4_900 * (temp_f1_912 * temp_f1_912)) - 3.0);
                        var_f4_900 = (f32) ((f64) var_f4_900 * (0.5 * temp_f1_916 * -(((f64) var_f4_900 * (temp_f1_916 * temp_f1_916)) - 3.0)));
                    } else if (var_f4_900 < M2C_BITWISE(f32, 0.0)) {
                        var_f4_900 = __float_nan;
                    } else {
                        arg_sp18 = var_f4_900;
                        temp_r3_935 = M2C_BITWISE(s32, arg_sp18) & 0x7F800000;
                        switch (temp_r3_935) {      /* switch 2; irregular */
                        case 0x7F800000:            /* switch 2 */
                            if (M2C_BITWISE(s32, arg_sp18) & 0x7FFFFF) {
                                var_r0_945 = 1;
                            } else {
                                var_r0_945 = 2;
                            }
                            break;
                        case 0x0:                   /* switch 2 */
                            if (M2C_BITWISE(s32, arg_sp18) & 0x7FFFFF) {
                                var_r0_945 = 5;
                            } else {
                                var_r0_945 = 3;
                            }
                            break;
                        default:                    /* switch 2 */
                            var_r0_945 = 4;
                            break;
                        }
                        if (var_r0_945 == 1) {
                            var_f4_900 = __float_nan;
                        }
                    }
                    var_f2_967 = 1.0f / var_f4_900;
                } else {
                    var_f2_967 = 0.0f;
                }
                arg_sp138 = 1.0f;
                arg_sp13C = 1.0f;
                arg_sp140 = 1.0f;
                arg_sp144 = 1.0f;
                arg_sp308 = (f32) arg_sp308 * var_f2_967;
                temp_f18_998 = 4.0f * ((f32) var_r29_745 / (f32) this->unk2B4);
                arg_sp30C *= var_f2_967;
                arg_sp310 = (f32) arg_sp310 * var_f2_967;
                arg_sp2A8 = (f64) arg_sp138;
                arg_sp2B0 = (f64) arg_sp140;
                MKSetColorV(*((MKVector4 *) &arg_sp2A8));
                MKSetTexCoord1F(temp_f18_998, 0.95f);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f26 */);
                arg_sp288 = arg_sp128;
                arg_sp130 = (f32) arg_sp310 * this->unkB4;
                arg_sp290 = (f64) arg_sp130;
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                arg_sp298 = arg_sp118;
                arg_sp120 = (f32) arg_sp330 + (f32) arg_sp290;
                arg_sp2A0 = (f64) arg_sp120;
                MKSetPositionV(*((MKVector3 *) &arg_sp298));
                MKRand_Float(&gViewSeed, 0.0f, 30.000002f);
                arg_sp108 = 1.0f;
                arg_sp10C = 1.0f;
                arg_sp110 = 1.0f;
                arg_sp114 = 1.0f;
                arg_sp278 = (f64) arg_sp108;
                arg_sp280 = (f64) arg_sp110;
                MKSetColorV(*((MKVector4 *) &arg_sp278));
                MKSetTexCoord1F(temp_f18_998, 0.05f);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f27 */);
                arg_sp258 = arg_spF8;
                arg_sp100 = (f32) arg_sp310 * this->unkB4;
                arg_sp260 = (f64) arg_sp100;
                M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
                arg_sp268 = arg_spE8;
                arg_spF0 = (f32) arg_sp330 - (f32) arg_sp260;
                arg_sp270 = (f64) arg_spF0;
                MKSetPositionV(*((MKVector3 *) &arg_sp268));
                var_r29_745 += 1;
                goto loop_44;
            }
            MKEnd();
            MKEndPrimitive();
            return;
        }
        MKMaterial_SetMaterial(this->unk2A4);
        var_r28_1093 = GetFirst();
        temp_f24_1094 = MKVector3::up.unk4;
        temp_f25_1096 = MKVector3::up.unk8;
        temp_f26_1097 = MKVector3::up.unk0;
loop_116:
        if (var_r28_1093 != NULL) {
            if (var_r28_1093->unkC == 1.0f) {
                temp_r0_1105 = var_r28_1093->unk10;
                var_f28_1106 = var_r28_1093->unk8;
                if (temp_r0_1105 != 0x64) {
                    var_f27_1111 = *(this + ((temp_r0_1105 * 0x3C) + 0xCC));
                } else {
                    var_f27_1111 = 1.0f;
                }
                var_r28_1093 = GetNextPositive(var_r28_1093);
            } else {
                var_f28_1106 = 0.0f;
                var_f27_1111 = var_r28_1093->unk8;
                var_r28_1093 = GetNextPositive(var_r28_1093);
            }
            var_f2_1129 = var_f27_1111 - var_f28_1106;
            if (var_f2_1129 < 0.0f) {
                var_f1_1132 = -var_f2_1129;
            } else {
                var_f1_1132 = var_f2_1129;
            }
            temp_r0_1137 = this->unk2B4;
            if ((s32) ((f32) temp_r0_1137 * var_f1_1132) != 0) {
                if (var_f2_1129 < 0.0f) {
                    var_f2_1129 = -var_f2_1129;
                }
                var_r30_1162 = (s32) ((f32) temp_r0_1137 * var_f2_1129);
            } else {
                var_r30_1162 = 1;
            }
            MKPrimitive(0xC, 0x10);
            MKSetMatrix(*((Matrix *) &arg_sp350));
            MKBegin((var_r30_1162 + 1) * 2);
            var_r29_1176 = 0;
loop_114:
            if (var_r29_1176 < (s32) (var_r30_1162 + 1)) {
                if (var_r29_1176 == 0) {
                    arg_sp228.GetPos();
                    arg_sp238.GetPosition(var_f28_1106);
                    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
                    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
                    arg_sp248 = arg_sp58;
                    arg_sp60 = arg_sp240 - arg_sp230;
                    arg_sp328 = arg_sp58;
                    arg_sp250 = (f64) arg_sp60;
                    arg_sp330 = (f64) arg_sp60;
                } else if (var_r29_1176 == var_r30_1162) {
                    arg_sp1F8.GetPos();
                    arg_sp208.GetPosition(var_f27_1111);
                    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
                    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
                    arg_sp218 = arg_sp48;
                    arg_sp50 = arg_sp210 - arg_sp200;
                    arg_sp328 = arg_sp48;
                    arg_sp220 = (f64) arg_sp50;
                    arg_sp330 = (f64) arg_sp50;
                } else {
                    arg_sp1C8.GetPos();
                    arg_sp20 = ((f32) var_r29_1176 * temp_f29_720) + var_f28_1106;
                    arg_sp1D8.GetPosition(Clamp<float>(0.0f, arg_sp20, 1.0f));
                    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
                    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
                    arg_sp1E8 = arg_sp38;
                    arg_sp40 = arg_sp1E0 - arg_sp1D0;
                    arg_sp328 = arg_sp38;
                    arg_sp1F0 = (f64) arg_sp40;
                    arg_sp330 = (f64) arg_sp40;
                }
                arg_sp32C += 1.0f;
                var_f1_1275 = ((f32) var_r29_1176 * temp_f29_720) + var_f28_1106;
                if (var_f1_1275 < 1.0f) {

                } else {
                    var_f1_1275 = 1.0f;
                }
                if (var_f1_1275 > 0.0f) {

                } else {
                    var_f1_1275 = 0.0f;
                }
                arg_sp1B8.GetVelocity(var_f1_1275);
                arg_sp318 = arg_sp1B8;
                arg_sp320 = arg_sp1C0;
                var_f4_1303 = ((f32) arg_sp320 * (f32) arg_sp320) + (((f32) arg_sp318 * (f32) arg_sp318) + (arg_sp31C * arg_sp31C));
                if (var_f4_1303 > 0.000001f) {
                    if (var_f4_1303 > 0.0f) {
                        temp_f1_1309 = __frsqrte(var_f4_1303);
                        temp_f1_1315 = 0.5 * temp_f1_1309 * -(((f64) var_f4_1303 * (temp_f1_1309 * temp_f1_1309)) - 3.0);
                        temp_f1_1319 = 0.5 * temp_f1_1315 * -(((f64) var_f4_1303 * (temp_f1_1315 * temp_f1_1315)) - 3.0);
                        var_f4_1303 = (f32) ((f64) var_f4_1303 * (0.5 * temp_f1_1319 * -(((f64) var_f4_1303 * (temp_f1_1319 * temp_f1_1319)) - 3.0)));
                    } else if (var_f4_1303 < M2C_BITWISE(f32, 0.0)) {
                        var_f4_1303 = __float_nan;
                    } else {
                        arg_sp14 = var_f4_1303;
                        temp_r3_1338 = M2C_BITWISE(s32, arg_sp14) & 0x7F800000;
                        switch (temp_r3_1338) {     /* switch 3; irregular */
                        case 0x7F800000:            /* switch 3 */
                            if (M2C_BITWISE(s32, arg_sp14) & 0x7FFFFF) {
                                var_r0_1348 = 1;
                            } else {
                                var_r0_1348 = 2;
                            }
                            break;
                        case 0x0:                   /* switch 3 */
                            if (M2C_BITWISE(s32, arg_sp14) & 0x7FFFFF) {
                                var_r0_1348 = 5;
                            } else {
                                var_r0_1348 = 3;
                            }
                            break;
                        default:                    /* switch 3 */
                            var_r0_1348 = 4;
                            break;
                        }
                        if (var_r0_1348 == 1) {
                            var_f4_1303 = __float_nan;
                        }
                    }
                    var_f2_1370 = 1.0f / var_f4_1303;
                } else {
                    var_f2_1370 = 0.0f;
                }
                temp_f4_1377 = arg_sp31C * var_f2_1370;
                temp_f3_1379 = (f32) arg_sp320 * var_f2_1370;
                temp_f5_1380 = (f32) arg_sp318 * var_f2_1370;
                arg_sp31C = temp_f4_1377;
                arg_sp318 = temp_f5_1380;
                arg_sp320 = temp_f3_1379;
                arg_sp28 = (temp_f24_1094 * temp_f3_1379) - (temp_f25_1096 * temp_f4_1377);
                arg_sp2C = (temp_f25_1096 * temp_f5_1380) - (temp_f26_1097 * temp_f3_1379);
                arg_sp30 = (temp_f26_1097 * temp_f4_1377) - (temp_f24_1094 * temp_f5_1380);
                arg_sp308 = (f64) arg_sp28;
                arg_sp310 = (f64) arg_sp30;
                arg_sp1A8 = (f64) arg_sp28;
                arg_sp1B0 = (f64) arg_sp30;
                var_f4_1406 = ((f32) arg_sp310 * (f32) arg_sp310) + (((f32) arg_sp308 * (f32) arg_sp308) + (arg_sp30C * arg_sp30C));
                if (var_f4_1406 > 0.000001f) {
                    if (var_f4_1406 > 0.0f) {
                        temp_f1_1412 = __frsqrte(var_f4_1406);
                        temp_f1_1418 = 0.5 * temp_f1_1412 * -(((f64) var_f4_1406 * (temp_f1_1412 * temp_f1_1412)) - 3.0);
                        temp_f1_1422 = 0.5 * temp_f1_1418 * -(((f64) var_f4_1406 * (temp_f1_1418 * temp_f1_1418)) - 3.0);
                        var_f4_1406 = (f32) ((f64) var_f4_1406 * (0.5 * temp_f1_1422 * -(((f64) var_f4_1406 * (temp_f1_1422 * temp_f1_1422)) - 3.0)));
                    } else if (var_f4_1406 < M2C_BITWISE(f32, 0.0)) {
                        var_f4_1406 = __float_nan;
                    } else {
                        arg_sp10 = var_f4_1406;
                        temp_r3_1441 = M2C_BITWISE(s32, arg_sp10) & 0x7F800000;
                        switch (temp_r3_1441) {     /* switch 4; irregular */
                        case 0x7F800000:            /* switch 4 */
                            if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                                var_r0_1451 = 1;
                            } else {
                                var_r0_1451 = 2;
                            }
                            break;
                        case 0x0:                   /* switch 4 */
                            if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                                var_r0_1451 = 5;
                            } else {
                                var_r0_1451 = 3;
                            }
                            break;
                        default:                    /* switch 4 */
                            var_r0_1451 = 4;
                            break;
                        }
                        if (var_r0_1451 == 1) {
                            var_f4_1406 = __float_nan;
                        }
                    }
                    var_f2_1473 = 1.0f / var_f4_1406;
                } else {
                    var_f2_1473 = 0.0f;
                }
                arg_spD8 = 1.0f;
                arg_spDC = 1.0f;
                arg_spE0 = 1.0f;
                arg_spE4 = 1.0f;
                arg_sp308 = (f32) arg_sp308 * var_f2_1473;
                temp_f18_1504 = 4.0f * ((f32) var_r29_1176 / (f32) this->unk2B4);
                arg_sp30C *= var_f2_1473;
                arg_sp310 = (f32) arg_sp310 * var_f2_1473;
                arg_sp198 = (f64) arg_spD8;
                arg_sp1A0 = (f64) arg_spE0;
                MKSetColorV(*((MKVector4 *) &arg_sp198));
                MKSetTexCoord1F(temp_f18_1504, 0.95f);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
                arg_sp178 = arg_spC8;
                arg_spD0 = (f32) arg_sp310 * this->unkB4;
                arg_sp180 = (f64) arg_spD0;
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                arg_sp188 = arg_spB8;
                arg_spC0 = (f32) arg_sp330 + (f32) arg_sp180;
                arg_sp190 = (f64) arg_spC0;
                MKSetPositionV(*((MKVector3 *) &arg_sp188));
                MKRand_Float(&gViewSeed, 0.0f, 30.000002f);
                arg_spA8 = 1.0f;
                arg_spAC = 1.0f;
                arg_spB0 = 1.0f;
                arg_spB4 = 1.0f;
                arg_sp168 = (f64) arg_spA8;
                arg_sp170 = (f64) arg_spB0;
                MKSetColorV(*((MKVector4 *) &arg_sp168));
                MKSetTexCoord1F(temp_f18_1504, 0.05f);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
                arg_sp148 = arg_sp98;
                arg_spA0 = (f32) arg_sp310 * this->unkB4;
                arg_sp150 = (f64) arg_spA0;
                M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
                arg_sp158 = arg_sp88;
                arg_sp90 = (f32) arg_sp330 - (f32) arg_sp150;
                arg_sp160 = (f64) arg_sp90;
                MKSetPositionV(*((MKVector3 *) &arg_sp158));
                var_r29_1176 += 1;
                goto loop_114;
            }
            MKEnd();
            MKEndPrimitive();
            goto loop_116;
        }
    }
}
#endif

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'HeroInterface'
void GunPowderFuse::Update() {
    f64 sp178;
    f64 sp170;
    f64 sp168;
    f64 sp160;
    f64 sp158;
    f64 sp150;
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
    f64 spF8;
    f64 spF0;
    f64 spE8;
    KDUniformSpline spD0;
    f64 spC0;
    f64 spB0;
    f64 spA0;
    f64 sp90;
    f64 sp80;
    f64 sp70;
    f64 sp60;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    s32 sp4C;
    s32 sp48;
    s32 sp44;
    s32 sp40;
    s32 sp3C;
    s32 sp38;
    s32 sp34;
    s32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    s32 sp8;
    MKVector3 *temp_r8_2249;
    f32 temp_f1_1735;
    f32 temp_f1_1966;
    f32 temp_f1_2031;
    f32 temp_f1_2095;
    f32 temp_f1_2158;
    f32 temp_f2_1786;
    f32 temp_f2_1811;
    f32 temp_f3_1724;
    f32 temp_f3_1792;
    f32 temp_f3_1813;
    f32 temp_f3_1904;
    f32 temp_f3_1915;
    f32 temp_f4_1720;
    f32 temp_f4_1788;
    f32 temp_f4_1809;
    f32 temp_f4_1912;
    f32 temp_f5_1716;
    f32 temp_f5_1796;
    f32 temp_f5_1908;
    f32 temp_f9_1793;
    s32 temp_r0_2021;
    s32 var_r25_1871;
    s32 var_r25_2245;
    s32 var_r28_1872;
    s32 var_r28_1962;
    s32 var_r30_1960;
    s32 var_r30_2246;
    void *temp_r28_2248;
    void *temp_r31_1874;
    void *temp_r31_1965;
    void *temp_r3_1665;
    void *temp_r3_1692;
    void *temp_r3_1753;
    void *temp_r3_1795;
    void *temp_r3_2009;
    void *temp_r4_2000;
    void *temp_r4_2065;
    void *temp_r4_2076;
    void *temp_r4_2129;
    void *temp_r4_2140;
    void *temp_r4_2227;
    void *var_r26_1868;
    void *var_r27_1857;
    void *var_r28_1747;
    void *var_r4_1844;
    void *var_r4_1941;

    MKProp::Update();
    if (IsBurntOut() == 0) {
        temp_r3_1665 = gb.unk0->GetEffects();
        if (temp_r3_1665 != NULL) {
            gb.GetSpyro();
            if (((u8) M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), u8 *, 0x3D3) != 0) && ((s32) M2C_FIELD(GameData::gameData, s32 *, 0x158) == 0) && ((s32) *(&GameData::gameData[0x70] + ((M2C_FIELD(GameData::gameData, s32 *, 0x158) << 5) + 0x7C)) == 0)) {
                temp_r3_1692 = M2C_FIELD(gb.unk0->GetProp(), void **, 8);
                sp170 = M2C_FIELD(temp_r3_1692, f64 *, 0x30);
                sp178 = M2C_FIELD(temp_r3_1692, f64 *, 0x38);
                Tools_GetClosestSplineTime(&this->unkB0->unk30, *((MKVector3 *) &sp170), this->unk2B4);
                sp2C = 0.0f;
                spD0.GetMeasure(M2C_ERROR(/* Read from unset register $f1 */), (Matrix *) &this->unkB0->unk30, KDSpline_PositionMixer);
                sp160 = M2C_BITWISE(f64, spD0);
                sp168 = (f64) spD0.unk8;
                temp_f5_1716 = unksp174 - unksp164;
                temp_f4_1720 = (f32) sp170 - (f32) sp160;
                temp_f3_1724 = (f32) sp178 - (f32) sp168;
                if (((temp_f3_1724 * temp_f3_1724) + ((temp_f4_1720 * temp_f4_1720) + (temp_f5_1716 * temp_f5_1716))) < 1000000.0f) {
                    temp_f1_1735 = ((BaseBreathFX *) (M2C_FIELD(M2C_FIELD(temp_r3_1665, void **, 4), BaseBreathFX **, 0x14)))->SplineCollide(this->unkB0, this->unkB4);
                    if (temp_f1_1735 != -1.0f) {
                        Burn(temp_f1_1735);
                    }
                }
            }
            var_r28_1747 = checked_cast<FireBombFX *, MKProp>(M2C_FIELD(M2C_FIELD(M2C_FIELD(M2C_FIELD(temp_r3_1665, void **, 4), BaseBreathFX **, 0x14), void **, 0x26C), MKProp **, 0x28));
loop_15:
            if (var_r28_1747 != NULL) {
                if ((u8) M2C_FIELD(var_r28_1747, u8 *, 0xE0) != 0) {
                    temp_r3_1753 = M2C_FIELD(var_r28_1747, void **, 8);
                    sp150 = M2C_FIELD(temp_r3_1753, f64 *, 0x30);
                    sp158 = M2C_FIELD(temp_r3_1753, f64 *, 0x38);
                    Tools_GetClosestSplineTime(&this->unkB0->unk30, *((MKVector3 *) &sp150), this->unk2B4);
                    sp28 = 0.0f;
                    spC0.GetMeasure(M2C_ERROR(/* Read from unset register $f1 */), (Matrix *) &this->unkB0->unk30, KDSpline_PositionMixer);
                    sp140 = spC0;
                    sp148 = spC8;
                    temp_f2_1786 = unksp154 - unksp144;
                    temp_f4_1788 = (f32) sp150 - (f32) sp140;
                    temp_f3_1792 = (f32) sp158 - (f32) sp148;
                    temp_f9_1793 = M2C_FIELD(var_r28_1747, f32 *, 0x128);
                    temp_r3_1795 = M2C_FIELD(gb.unk0->GetProp(spC0), void **, 8);
                    temp_f5_1796 = 500.0f * temp_f9_1793;
                    sp130 = M2C_FIELD(temp_r3_1795, f64 *, 0x30);
                    sp138 = M2C_FIELD(temp_r3_1795, f64 *, 0x38);
                    if (((temp_f3_1792 * temp_f3_1792) + ((temp_f4_1788 * temp_f4_1788) + (temp_f2_1786 * temp_f2_1786))) < (temp_f5_1796 * temp_f5_1796)) {
                        temp_f4_1809 = unksp154 - unksp134;
                        temp_f2_1811 = (f32) sp150 - (f32) sp130;
                        temp_f3_1813 = (f32) sp158 - (f32) sp138;
                        if (((temp_f3_1813 * temp_f3_1813) + ((temp_f2_1811 * temp_f2_1811) + (temp_f4_1809 * temp_f4_1809))) > 10000.0f) {
                            Tools_TestFloor(*((MKVector3 *) &sp150), NULL, 200.0f * temp_f9_1793, (MKCollisionMode) 4);
                            if ((u8) M2C_ERROR(/* Read from unset register $r3 */) != 0) {
                                Tools_GetClosestSplineTime(&this->unkB0->unk30, *((MKVector3 *) &sp150), this->unk2B4);
                                Burn(M2C_ERROR(/* Read from unset register $f1 */));
                            }
                        }
                    }
                }
                var_r28_1747 = checked_cast<FireBombFX *, MKProp>(M2C_FIELD(var_r28_1747, MKProp **, 0x38));
                goto loop_15;
            }
        }
        var_r4_1844 = *LiquidFXDescriptor::pFirstDesc;
loop_18:
        if ((var_r4_1844 != NULL) && !(M2C_FIELD(M2C_FIELD(var_r4_1844, void **, 0xE8), s32 *, 0x138) & 2)) {
            var_r4_1844 = M2C_FIELD(var_r4_1844, void **, 0xF0);
            goto loop_18;
        }
        var_r27_1857 = var_r4_1844;
loop_36:
        if (var_r27_1857 != NULL) {
            if (stricmp(M2C_FIELD(var_r27_1857, s32 *, 0), "MoltenMetalFX") == 0) {
                var_r26_1868 = checked_cast<LiquidFX *, MKProp>(M2C_FIELD(var_r27_1857, MKProp **, 0x28));
loop_30:
                if (var_r26_1868 != NULL) {
                    var_r25_1871 = 0;
                    var_r28_1872 = 0;
                    do {
                        temp_r31_1874 = var_r26_1868 + var_r28_1872;
                        if (((u8) M2C_FIELD(temp_r31_1874, u8 *, 0x159) != 0) && ((u8) M2C_FIELD(temp_r31_1874, u8 *, 0x158) != 0)) {
                            sp120 = M2C_FIELD(temp_r31_1874, f64 *, 0xC8);
                            sp128 = M2C_FIELD(temp_r31_1874, f64 *, 0xD0);
                            Tools_GetClosestSplineTime(&this->unkB0->unk30, *((MKVector3 *) &sp120), this->unk2B4);
                            sp24 = 0.0f;
                            spB0.GetMeasure(M2C_ERROR(/* Read from unset register $f1 */), (Matrix *) &this->unkB0->unk30, KDSpline_PositionMixer);
                            sp110 = spB0;
                            sp118 = spB8;
                            temp_f3_1904 = unksp124 - unksp114;
                            temp_f5_1908 = (f32) sp120 - (f32) sp110;
                            temp_f4_1912 = (f32) sp128 - (f32) sp118;
                            temp_f3_1915 = 150.0f * M2C_FIELD(temp_r31_1874, f32 *, 0xF8);
                            if (((temp_f4_1912 * temp_f4_1912) + ((temp_f5_1908 * temp_f5_1908) + (temp_f3_1904 * temp_f3_1904))) < (temp_f3_1915 * temp_f3_1915)) {
                                Tools_GetClosestSplineTime(&this->unkB0->unk30, *((MKVector3 *) &sp120), this->unk2B4);
                                Burn(M2C_ERROR(/* Read from unset register $f1 */));
                            }
                        }
                        var_r25_1871 += 1;
                        var_r28_1872 += 0xA0;
                    } while (var_r25_1871 < 0x64);
                    var_r26_1868 = checked_cast<LiquidFX *, MKProp>(M2C_FIELD(var_r26_1868, MKProp **, 0x38));
                    goto loop_30;
                }
            }
            var_r4_1941 = M2C_FIELD(var_r27_1857, void **, 0xF0);
loop_33:
            if ((var_r4_1941 != NULL) && !(M2C_FIELD(M2C_FIELD(var_r4_1941, void **, 0xE8), s32 *, 0x138) & 2)) {
                var_r4_1941 = M2C_FIELD(var_r4_1941, void **, 0xF0);
                goto loop_33;
            }
            var_r27_1857 = var_r4_1941;
            goto loop_36;
        }
        sp4C = 0;
        var_r30_1960 = 0;
        var_r28_1962 = 0;
        sp48 = 0x162;
        do {
            temp_r31_1965 = this + var_r28_1962;
            temp_f1_1966 = M2C_FIELD(temp_r31_1965, f32 *, 0xCC);
            M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
            if (temp_f1_1966 == 1.0f) {
                M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
                if (temp_f1_1966 == 0.0f) {
                    M2C_FIELD(*gMK, M2C_UNK (**)(void **, s32 *, M2C_UNK, M2C_UNK, void *, M2C_UNK, f32), 0x94)(gMK, &sp48, 0, 0, M2C_FIELD(temp_r31_1965, void **, 0xC4), 1, 100.0f);
                    EmitBurn(M2C_FIELD(temp_r31_1965, f32 *, 0xCC));
                    if ((void *) M2C_FIELD(temp_r31_1965, void **, 0xC4) != NULL) {
                        sp18 = 0.0f;
                        spA0.GetMeasure(M2C_FIELD(temp_r31_1965, f32 *, 0xCC), (Matrix *) &this->unkB0->unk30, KDSpline_PositionMixer);
                        temp_r4_2000 = M2C_FIELD(temp_r31_1965, void **, 0xC4);
                        M2C_FIELD(temp_r4_2000, f64 *, 0) = spA0;
                        M2C_FIELD(temp_r4_2000, f64 *, 8) = spA8;
                        temp_r3_2009 = M2C_FIELD(temp_r31_1965, void **, 0xC4);
                        M2C_FIELD(temp_r3_2009, f32 *, 0x2C) = (f32) (M2C_FIELD(temp_r3_2009, f32 *, 0x2C) + MKRand_Float(&gViewSeed, -1.0f, 1.0f));
                    }
                    M2C_FIELD(temp_r31_1965, f32 *, 0xCC) = (f32) ((M2C_FIELD(temp_r31_1965, f32 *, 0xD0) * (this->unk2A8 * gUpdateTimeDelta)) + M2C_FIELD(temp_r31_1965, f32 *, 0xCC));
                    temp_r0_2021 = M2C_FIELD(temp_r31_1965, s32 *, 0xD4);
                    if ((temp_r0_2021 != 0x64) && (temp_r0_2021 != -0x64)) {
                        if (M2C_FIELD(temp_r31_1965, f32 *, 0xD0) == 1.0f) {
                            temp_f1_2031 = M2C_FIELD(temp_r31_1965, f32 *, 0xCC);
                            if (temp_f1_2031 > *(this + ((temp_r0_2021 * 0x3C) + 0xCC))) {
                                sp20 = 0.0f;
                                sp90.GetMeasure(temp_f1_2031, (Matrix *) &this->unkB0->unk30, KDSpline_PositionMixer);
                                sp100 = sp90;
                                sp108 = sp98;
                                sp44 = 0;
                                sp40 = 0x162;
                                M2C_FIELD(*gMK, M2C_UNK (**)(void **, s32 *, M2C_UNK, M2C_UNK, f64 *, M2C_UNK, f32), 0x94)(gMK, &sp40, 2, 1, &sp100, 1, 4.0f * this->unkB4);
                                temp_r4_2065 = M2C_FIELD(temp_r31_1965, void **, 0xC4);
                                if (temp_r4_2065 != NULL) {
                                    M2C_FIELD(temp_r4_2065, u8 *, 0x31) = (u8) (M2C_FIELD(temp_r4_2065, u8 *, 0x31) & ~0x40);
                                }
                                temp_r4_2076 = *(this + ((M2C_FIELD(temp_r31_1965, s32 *, 0xD4) * 0x3C) + 0xC4));
                                if (temp_r4_2076 != NULL) {
                                    M2C_FIELD(temp_r4_2076, u8 *, 0x31) = (u8) (M2C_FIELD(temp_r4_2076, u8 *, 0x31) & ~0x40);
                                }
                                M2C_FIELD(temp_r31_1965, f32 *, 0xCC) = 100.0f;
                                *(this + ((M2C_FIELD(temp_r31_1965, s32 *, 0xD4) * 0x3C) + 0xCC)) = 100.0f;
                                UpdatePartners();
                            }
                        } else {
                            temp_f1_2095 = M2C_FIELD(temp_r31_1965, f32 *, 0xCC);
                            if (temp_f1_2095 < *(this + ((temp_r0_2021 * 0x3C) + 0xCC))) {
                                sp1C = 0.0f;
                                sp80.GetMeasure(temp_f1_2095, (Matrix *) &this->unkB0->unk30, KDSpline_PositionMixer);
                                spF0 = sp80;
                                spF8 = sp88;
                                sp3C = 0;
                                sp38 = 0x162;
                                M2C_FIELD(*gMK, M2C_UNK (**)(void **, s32 *, M2C_UNK, M2C_UNK, f64 *, M2C_UNK, f32), 0x94)(gMK, &sp38, 2, 1, &spF0, 1, 4.0f * this->unkB4);
                                temp_r4_2129 = M2C_FIELD(temp_r31_1965, void **, 0xC4);
                                if (temp_r4_2129 != NULL) {
                                    M2C_FIELD(temp_r4_2129, u8 *, 0x31) = (u8) (M2C_FIELD(temp_r4_2129, u8 *, 0x31) & ~0x40);
                                }
                                temp_r4_2140 = *(this + ((M2C_FIELD(temp_r31_1965, s32 *, 0xD4) * 0x3C) + 0xC4));
                                if (temp_r4_2140 != NULL) {
                                    M2C_FIELD(temp_r4_2140, u8 *, 0x31) = (u8) (M2C_FIELD(temp_r4_2140, u8 *, 0x31) & ~0x40);
                                }
                                M2C_FIELD(temp_r31_1965, f32 *, 0xCC) = 100.0f;
                                *(this + ((M2C_FIELD(temp_r31_1965, s32 *, 0xD4) * 0x3C) + 0xCC)) = 100.0f;
                                UpdatePartners();
                            }
                        }
                    } else {
                        temp_f1_2158 = M2C_FIELD(temp_r31_1965, f32 *, 0xCC);
                        if ((temp_f1_2158 > 1.0f) || (temp_f1_2158 < 0.0f)) {
                            sp58 = 0.0f;
                            sp50 = 0.0f;
                            sp54 = 0.0f;
                            spE8 = (f64) sp58;
                            spD0.unk10 = (f64) sp50;
                            if (M2C_FIELD(temp_r31_1965, f32 *, 0xCC) > 1.0f) {
                                this->unk2B9 = 1;
                                sp14 = 0.0f;
                                sp70.GetMeasure(1.0f, (Matrix *) &this->unkB0->unk30, KDSpline_PositionMixer);
                                spD0.unk10 = sp70;
                                spE8 = sp78;
                            }
                            if (M2C_FIELD(temp_r31_1965, f32 *, 0xCC) < 0.0f) {
                                this->unk2B8 = 1;
                                sp10 = 0.0f;
                                sp60.GetMeasure(0.0f, (Matrix *) &this->unkB0->unk30, KDSpline_PositionMixer);
                                spD0.unk10 = sp60;
                                spE8 = sp68;
                            }
                            sp34 = 0;
                            sp30 = 0x162;
                            M2C_FIELD(*gMK, M2C_UNK (**)(void **, s32 *, M2C_UNK, M2C_UNK, f64 *, M2C_UNK, f32), 0x94)(gMK, &sp30, 2, 1, &spD0.unk10, 1, 4.0f * this->unkB4);
                            temp_r4_2227 = M2C_FIELD(temp_r31_1965, void **, 0xC4);
                            if (temp_r4_2227 != NULL) {
                                M2C_FIELD(temp_r4_2227, u8 *, 0x31) = (u8) (M2C_FIELD(temp_r4_2227, u8 *, 0x31) & ~0x40);
                            }
                            M2C_FIELD(temp_r31_1965, f32 *, 0xCC) = 100.0f;
                            UpdatePartners();
                        }
                    }
                }
            }
            var_r30_1960 += 1;
            var_r28_1962 += 0x3C;
        } while (var_r30_1960 < 8);
    }
    var_r25_2245 = 0;
    var_r30_2246 = 0;
    do {
        temp_r28_2248 = this + var_r30_2246;
        temp_r8_2249 = M2C_FIELD(temp_r28_2248, MKVector3 **, 0xC4);
        if (temp_r8_2249 != NULL) {
            sp8 = 1;
            ((KDSoundFader *) (temp_r28_2248 + 0xD8))->Update(GS_GunpowderBurnLP, 1U, ((u8) M2C_FIELD(temp_r8_2249, u8 *, 0x31) >> 6U) & 1, NULL, temp_r8_2249, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
        } else if (KDSound_IsVoicePlaying(M2C_FIELD(temp_r28_2248, s32 *, 0xD8)) != 0) {
            KDSound_Stop(temp_r28_2248 + 0xD8);
        }
        var_r25_2245 += 1;
        var_r30_2246 += 0x3C;
    } while (var_r25_2245 < 8);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'GunPowderFuse' to
u8 GunPowderFuse::IsBurntOut() {
    f32 temp_f2_2295;
    s32 var_ctr_2292;
    s32 var_r4_2291;
    u8 var_r4_2308;

    var_r4_2291 = 0;
    var_ctr_2292 = 8;
loop_1:
    temp_f2_2295 = *(this + (var_r4_2291 + 0xCC));
    M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
    if (temp_f2_2295 == 1.0f) {
        M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
        if (temp_f2_2295 == 0.0f) {
            return 0U;
        }
    }
    var_r4_2291 += 0x3C;
    var_ctr_2292 -= 1;
    if (var_ctr_2292 == 0) {
        var_r4_2308 = 0;
        if (((u8) this->unk2B8 != 0) || ((u8) this->unk2B9 != 0)) {
            var_r4_2308 = 1;
        }
        return var_r4_2308;
    }
    goto loop_1;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'GunPowderFuse' to
u8 GunPowderFuse::IsBurning() {
    f32 temp_f2_2331;
    s32 var_ctr_2328;
    s32 var_r4_2327;

    var_r4_2327 = 0;
    var_ctr_2328 = 8;
loop_1:
    temp_f2_2331 = *(this + (var_r4_2327 + 0xCC));
    M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
    if (temp_f2_2331 == 1.0f) {
        M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
        if (temp_f2_2331 == 0.0f) {
            return 1U;
        }
    }
    var_r4_2327 += 0x3C;
    var_ctr_2328 -= 1;
    if (var_ctr_2328 == 0) {
        return 0U;
    }
    goto loop_1;
}
#endif

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'KDSplinePathSegment'
void GunPowderFuse::Burn(float arg0) {
    f64 sp30;
    KDUniformSpline sp18;
    s32 sp10;
    s32 spC;
    f32 sp8;
    f32 temp_f1_2395;
    s32 var_r28_2390;
    s32 var_r29_2388;
    s32 var_r30_2392;
    void *temp_r3_2394;
    void *temp_r3_2407;
    void *temp_r4_2414;
    void *temp_r4_2431;

    if ((HasAvailableBurnPoints() != 0) && (TooClose(arg0) == 0) && (IsBurnable(arg0) != 0)) {
        if ((arg0 > this->unk2B0) && ((u8) this->unk2BA == 0)) {
            this->unkC0.Send(NULL);
            this->unk2BA = 1;
        }
        var_r29_2388 = 0;
        var_r28_2390 = 0;
        var_r30_2392 = 0;
loop_7:
        temp_r3_2394 = this + var_r30_2392;
        temp_f1_2395 = M2C_FIELD(temp_r3_2394, f32 *, 0xCC);
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if ((temp_f1_2395 != 1.0f) || (M2C_ERROR(/* unknown instruction: cror eq, gt, eq */), ((temp_f1_2395 == 0.0f) == 0))) {
            if (var_r29_2388 != 0) {
                temp_r3_2407 = this + var_r30_2392;
                M2C_FIELD(temp_r3_2407, f32 *, 0xD0) = -1.0f;
                M2C_FIELD(temp_r3_2407, f32 *, 0xCC) = (f32) (-0.00001f + arg0);
                M2C_FIELD(temp_r3_2407, f32 *, 0xC8) = (f32) M2C_FIELD(temp_r3_2407, f32 *, 0xCC);
                temp_r4_2414 = M2C_FIELD(temp_r3_2407, void **, 0xC4);
                if (temp_r4_2414 != NULL) {
                    M2C_FIELD(temp_r4_2414, u8 *, 0x31) = (u8) (M2C_FIELD(temp_r4_2414, u8 *, 0x31) | 0x40);
                }
                UpdatePartners();
                return;
            }
            M2C_FIELD(temp_r3_2394, f32 *, 0xD0) = 1.0f;
            M2C_FIELD(temp_r3_2394, f32 *, 0xCC) = (f32) (0.00001f + arg0);
            M2C_FIELD(temp_r3_2394, f32 *, 0xC8) = (f32) M2C_FIELD(temp_r3_2394, f32 *, 0xCC);
            temp_r4_2431 = M2C_FIELD(temp_r3_2394, void **, 0xC4);
            if (temp_r4_2431 != NULL) {
                M2C_FIELD(temp_r4_2431, u8 *, 0x31) = (u8) (M2C_FIELD(temp_r4_2431, u8 *, 0x31) | 0x40);
            }
            sp8 = 0.0f;
            sp18.GetMeasure(arg0, (Matrix *) &this->unkB0->unk30, KDSpline_PositionMixer);
            sp18.unk10 = M2C_BITWISE(f64, sp18);
            sp30 = (f64) sp18.unk8;
            sp10 = 0;
            spC = 0x162;
            M2C_FIELD(*gMK, M2C_UNK (**)(void **, s32 *, M2C_UNK, M2C_UNK, u8 *, M2C_UNK, f32), 0x94)(gMK, &spC, 2, 1, &sp18.unk10, 1, 4.0f * this->unkB4);
            var_r29_2388 += 1;
            goto block_16;
        }
block_16:
        var_r28_2390 += 1;
        var_r30_2392 += 0x3C;
        if (var_r28_2390 >= 8) {

        } else {
            goto loop_7;
        }
    }
}
#endif

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'KDSplinePathSegment'
void GunPowderFuse::Message(MKMessage *arg0) {
    MKVector3 *sp10;
    s32 spC;
    s32 sp8;
    s32 var_r30_2498;
    s32 var_r31_2499;
    u32 temp_r3_2514;

    var_r30_2498 = 0;
    var_r31_2499 = 0;
    do {
        ((KDSoundPlayer *) (this + (var_r31_2499 + 0xD8)))->Message(arg0);
        var_r30_2498 += 1;
        var_r31_2499 += 0x3C;
    } while (var_r30_2498 < 8);
    if ((s32) arg0->unk0 != 0x162) {

    } else {
        temp_r3_2514 = arg0->unk4;
        if (temp_r3_2514 != 0) {
            spC = 0;
            sp8 = 0x5B;
            sp10 = NULL;
            M2C_FIELD(M2C_FIELD(temp_r3_2514, void **, 0x44), M2C_UNK (**)(s32 *, M2C_UNK), 0x2C)(&sp8, 0);
            Tools_GetClosestSplineTime(&this->unkB0->unk30, *sp10, this->unk2B4);
            Burn(M2C_ERROR(/* Read from unset register $f1 */));
        }
    }
    MKProp::Message(arg0);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'MKResource * (const char *)' to
void GunPowderFuse::Resolve() {
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 sp8;
    s32 temp_r0_2610;
    s32 var_r29_2569;
    s32 var_r31_2571;
    void *temp_r4_2612;

    MKProp::Resolve();
    this->unk2A4 = MKMaterial_Create"FX_GunPowderFuse";
    var_r29_2569 = 0;
    var_r31_2571 = 0;
    this->unk2A8 /= this->unkB0->unk30.unk8;
    this->unk2AC = 2.0f * (this->unkB4 / this->unkB0->unk30.unk8);
    do {
        sp28 = 0.0f;
        sp10 = 1.0f;
        sp14 = 1.0f;
        sp18 = 1.0f;
        sp1C = 1.0f;
        sp20 = 0.0f;
        sp24 = 0.0f;
        sp8 = this->unkB4 / 20.0f;
        sp30 = (f64) sp10;
        sp38 = (f64) sp18;
        sp40 = (f64) sp20;
        sp48 = (f64) sp28;
        temp_r0_2610 = var_r31_2571 + 0xC4;
        *(this + temp_r0_2610) = gb.unk64->Alloc(*((MKVector3 *) &sp40), *((MKVector4 *) &sp30), sp8, lit_743, lit_744);
        temp_r4_2612 = *(this + temp_r0_2610);
        if (temp_r4_2612 != NULL) {
            M2C_FIELD(temp_r4_2612, u8 *, 0x31) = (u8) (M2C_FIELD(temp_r4_2612, u8 *, 0x31) & ~0x40);
        }
        var_r29_2569 += 1;
        var_r31_2571 += 0x3C;
    } while (var_r29_2569 < 8);
    this->unk2B0 = -((this->unk2A8 * this->unk2B0) - 1.0f);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long *' to
s32 GunPowderFuse::LoadLine(MKIniLine *arg0) {
    if (SplineProp::LoadLine(arg0) != 0) {
        return 1U;
    }
    if (arg0->LoadFloat("Width", &this->unkB4, 0) != 0) {
        this->unkB4 *= 100.0f;
        return 1U;
    }
    if (arg0->LoadFloat("BurnSpeed", &this->unk2A8, 0) != 0) {
        this->unk2A8 *= 100.0f;
        return 1U;
    }
    if (arg0->LoadFloat("NumSecondsBeforeBurnEnd", &this->unk2B0, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("Subdivisions", &this->unk2B4, 0) != 0) {
        return 1U;
    }
    return (u8) (this->unkC0.LoadLine(arg0, "OnNumSecondsBeforeBurnEnd") != 0);
}
#endif

#if 0 // DRAFT: illegal type
void GunPowderFuse::Deinit() {
    Corona *temp_r4_2752;
    MKMaterial *temp_r3_2739;
    s32 var_r28_2745;
    s32 var_r31_2747;
    void *temp_r29_2749;

    temp_r3_2739 = this->unk2A4;
    if (temp_r3_2739 != NULL) {
        MKMaterial_Destroy(temp_r3_2739);
    }
    var_r28_2745 = 0;
    var_r31_2747 = 0;
    do {
        temp_r29_2749 = this + var_r31_2747;
        KDSound_Stop(temp_r29_2749 + 0xD8);
        temp_r4_2752 = M2C_FIELD(temp_r29_2749, Corona **, 0xC4);
        if (temp_r4_2752 != NULL) {
            gb.unk64->Free(temp_r4_2752);
        }
        var_r28_2745 += 1;
        var_r31_2747 += 0x3C;
    } while (var_r28_2745 < 8);
    SplineProp::Deinit();
}
#endif

#if 0 // DRAFT: illegal type
void GunPowderFuse::Init() {
    s32 var_r29_2789;
    s32 var_r31_2787;
    void *temp_r4_2798;

    SplineProp::Init();
    var_r31_2787 = 0;
    this->unkB4 = 5.0f;
    var_r29_2789 = 0;
    this->unk2A8 = 20.0f;
    this->unk2B8 = 0;
    this->unk2B9 = 0;
    this->unk2BA = 0;
    this->unk2AC = 0.0f;
    do {
        temp_r4_2798 = this + var_r31_2787;
        M2C_FIELD(temp_r4_2798, f32 *, 0xCC) = 100.0f;
        M2C_FIELD(temp_r4_2798, f32 *, 0xC8) = 0.0f;
        M2C_FIELD(temp_r4_2798, s32 *, 0xC4) = 0;
        ((KDSoundFader *) (temp_r4_2798 + 0xD8))->Init(0.25f, 0.25f);
        var_r29_2789 += 1;
        var_r31_2787 += 0x3C;
    } while (var_r29_2789 < 8);
    this->unk2A4 = NULL;
}
#endif

void GunPowderFuse_cpp::__sinit() {
    f32 temp_f0_2858;
    f64 temp_f1_2839;
    f64 temp_f1_2847;
    f64 temp_f3_2827;
    f64 temp_f4_2836;
    f64 temp_f4_2844;
    f64 temp_f8_2829;

    temp_f3_2827 = __frsqrte(2014000.0);
    temp_f8_2829 = __frsqrte(380000.0);
    temp_f4_2836 = 0.5 * temp_f3_2827 * -((2014000.0 * (temp_f3_2827 * temp_f3_2827)) - 3.0);
    temp_f1_2839 = 0.5 * temp_f8_2829 * -((380000.0 * (temp_f8_2829 * temp_f8_2829)) - 3.0);
    temp_f4_2844 = 0.5 * temp_f4_2836 * -((2014000.0 * (temp_f4_2836 * temp_f4_2836)) - 3.0);
    temp_f1_2847 = 0.5 * temp_f1_2839 * -((380000.0 * (temp_f1_2839 * temp_f1_2839)) - 3.0);
    temp_f0_2858 = (f32) (380000.0 * (0.5 * temp_f1_2847 * -((380000.0 * (temp_f1_2847 * temp_f1_2847)) - 3.0)));
    SPYRO_BOUNCE_Y_SPEED = (f32) (2014000.0 * (0.5 * temp_f4_2844 * -((2014000.0 * (temp_f4_2844 * temp_f4_2844)) - 3.0)));
    SPYRO_MIN_JUMP_Y_VELOCITY = temp_f0_2858;
}
