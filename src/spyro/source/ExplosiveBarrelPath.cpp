#include "spyro/source/ExplosiveBarrelPath.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKParticleSystem.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/AssaultCannon.h"
#include "spyro/source/BurningWick.h"
#include "spyro/source/Crate.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/ExplosiveBarrel.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/GlowingPropManager.h"
#include "spyro/source/KDFaderObject.h"
#include "spyro/source/KDParticleSystem.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/KDSpline.h"
#include "spyro/source/KDStateMachine.h"
#include "spyro/source/PlatformObject.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/ShatterablePlatform.h"
#include "spyro/source/TargetManager.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
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
        M2C_FIELD(temp_r31_83, f32 *, 0x10) = MKRand_Float((int *) &gViewSeed, -3.1415927f, 3.1415927f);
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
    f64 sp20;
    f32 sp18;
    f64 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f30_142;
    f64 temp_f0_169;
    f64 temp_f0_181;

    temp_f30_142 = (f32) fmod(M2C_FIELD(M2C_ERROR(/* Read from unset register $r5 */), f32 *, 4), 1.0);
    spC = 0.0f;
    sp50.GetMeasure(temp_f30_142, arg1 + 0x50, KDSpline_PositionMixer);
    sp70 = M2C_BITWISE(f64, sp50);
    sp78 = (f64) sp50.unk8;
    sp8 = 0.0f;
    ((KDUniformSpline *) &sp40)->GetMeasure(temp_f30_142, arg1 + 0x64, KDSpline_PositionMixer);
    sp50.unk10 = sp40;
    sp68 = sp48;
    temp_f0_169 = sp70 + M2C_BITWISE(f64, sp50.unk10);
    sp10 = temp_f0_169;
    sp30 = temp_f0_169;
    sp18 = (f32) sp78 + (f32) sp68;
    sp38 = (f64) sp18;
    temp_f0_181 = temp_f0_169 * 5.222099017e-315;
    sp20 = temp_f0_181;
    M2C_FIELD(this, f64 *, 0) = temp_f0_181;
    sp28 = (f32) sp38 * 0.5f;
    M2C_FIELD(this, f64 *, 8) = (f64) sp28;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'KDUniformSpline' to
void ExplosiveBarrelPath::UpdateBarrelModel(ExplosiveBarrelPath::BarrelData *arg1) {
    MKCollisionResult sp320;
    f32 sp31C;
    f32 sp318;
    f32 sp314;
    f32 sp310;
    f32 sp30C;
    f32 sp308;
    f32 sp304;
    f32 sp300;
    f32 sp2FC;
    f32 sp2F8;
    f32 sp2F4;
    f32 sp2F0;
    f32 sp2EC;
    f32 sp2E8;
    f32 sp2E4;
    f32 sp2E0;
    Matrix sp2A0;
    f64 sp298;
    f64 sp290;
    f64 sp288;
    f64 sp280;
    f64 sp278;
    f64 sp270;
    f64 sp268;
    f64 sp260;
    f64 sp258;
    f64 sp250;
    f64 sp248;
    f64 sp240;
    f64 sp238;
    f64 sp230;
    f64 sp228;
    f64 sp220;
    f64 sp218;
    f64 sp210;
    f64 sp208;
    KDUniformSpline sp1F0;
    f64 sp1E0;
    f64 sp1D0;
    f64 sp1C0;
    f64 sp1B8;
    f64 sp1B0;
    f64 sp1A8;
    f64 sp1A0;
    f64 sp198;
    f64 sp190;
    f64 sp188;
    f64 sp180;
    f64 sp178;
    f64 sp170;
    f64 sp168;
    f64 sp160;
    f64 sp158;
    f64 sp150;
    f64 sp140;
    f64 sp138;
    f64 sp130;
    f64 sp128;
    f64 sp120;
    M2C_UNK sp110;
    f32 sp108;
    f64 sp100;
    f32 spF8;
    f64 spF0;
    f32 spE8;
    f64 spE0;
    f32 spD8;
    f64 spD0;
    f32 spC8;
    f64 spC0;
    f32 spB8;
    f32 spB4;
    f32 spB0;
    f32 spA8;
    f64 spA0;
    f32 sp98;
    f32 sp94;
    f32 sp90;
    f32 sp88;
    f32 sp84;
    f32 sp80;
    f32 sp78;
    f32 sp74;
    f32 sp70;
    f32 sp68;
    f64 sp60;
    f32 sp58;
    f64 sp50;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp38;
    f64 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 temp_f29_225;
    f32 var_f28_228;
    f32 var_f3_512;
    f32 var_f3_621;
    f32 var_f4_412;
    f32 var_f4_445;
    f32 var_f4_554;
    f32 var_f5_345;
    f64 temp_f0_677;
    f64 temp_f0_744;
    f64 temp_f0_755;
    f64 temp_f1_295;
    f64 temp_f1_306;
    f64 temp_f1_317;
    f64 temp_f1_430;
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
    sp28 = 0.0f;
    sp1F0.GetMeasure(temp_f29_225, &this->unk50, KDSpline_PositionMixer);
    sp290 = M2C_BITWISE(f64, sp1F0);
    sp298 = (f64) sp1F0.unk8;
    sp24 = 0.0f;
    ((KDUniformSpline *) &sp1E0)->GetMeasure(temp_f29_225, (Matrix *) &this->unk50.unk14, KDSpline_PositionMixer);
    sp280 = sp1E0;
    sp288 = sp1E8;
    sp20 = 0.0f;
    ((KDUniformSpline *) &sp1D0)->GetMeasure(var_f28_228, &this->unk50, KDSpline_PositionMixer);
    sp270 = sp1D0;
    sp278 = sp1D8;
    sp1C = 0.0f;
    ((KDUniformSpline *) &sp1C0)->GetMeasure(var_f28_228, (Matrix *) &this->unk50.unk14, KDSpline_PositionMixer);
    sp260 = sp1C0;
    sp268 = sp1C8;
    sp100 = sp290 + sp280;
    sp1B0 = sp100;
    sp108 = (f32) sp298 + (f32) sp288;
    sp1B8 = (f64) sp108;
    temp_f1_295 = sp100 * 5.222099017e-315;
    spF0 = temp_f1_295;
    sp250 = temp_f1_295;
    spF8 = (f32) sp1B8 * 0.5f;
    sp258 = (f64) spF8;
    temp_f1_306 = sp270 + sp1C0;
    spE0 = temp_f1_306;
    sp1A0 = temp_f1_306;
    spE8 = (f32) sp278 + (f32) sp268;
    sp1A8 = (f64) spE8;
    temp_f1_317 = temp_f1_306 * 5.222099017e-315;
    spD0 = temp_f1_317;
    sp240 = temp_f1_317;
    spD8 = (f32) sp1A8 * 0.5f;
    sp248 = (f64) spD8;
    spC0 = sp250 - temp_f1_317;
    sp190 = spC0;
    spC8 = (f32) sp258 - (f32) sp248;
    sp198 = (f64) spC8;
    var_f5_345 = ((f32) sp198 * (f32) sp198) + (((f32) sp190 * (f32) sp190) + ((*(f32 *) ((u8 *) &sp190 + 0x4)) * (*(f32 *) ((u8 *) &sp190 + 0x4))));
    if (var_f5_345 > 1e-12f) {
        if (var_f5_345 > 0.0f) {
            temp_f2_351 = __frsqrte(var_f5_345);
            temp_f2_357 = 0.5 * temp_f2_351 * -(((f64) var_f5_345 * (temp_f2_351 * temp_f2_351)) - 3.0);
            temp_f2_361 = 0.5 * temp_f2_357 * -(((f64) var_f5_345 * (temp_f2_357 * temp_f2_357)) - 3.0);
            var_f5_345 = (f32) ((f64) var_f5_345 * (0.5 * temp_f2_361 * -(((f64) var_f5_345 * (temp_f2_361 * temp_f2_361)) - 3.0)));
        } else if (var_f5_345 < M2C_BITWISE(f32, 0.0)) {
            var_f5_345 = __float_nan;
        } else {
            sp18 = var_f5_345;
            temp_r3_380 = M2C_BITWISE(s32, sp18) & 0x7F800000;
            switch (temp_r3_380) {                  /* switch 1; irregular */
            case 0x7F800000:                        /* switch 1 */
                if (M2C_BITWISE(s32, sp18) & 0x7FFFFF) {
                    var_r0_390 = 1;
                } else {
                    var_r0_390 = 2;
                }
                break;
            case 0x0:                               /* switch 1 */
                if (M2C_BITWISE(s32, sp18) & 0x7FFFFF) {
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
    spB4 = (*(f32 *) ((u8 *) &sp190 + 0x4)) * var_f4_412;
    spB0 = (f32) sp190 * var_f4_412;
    spB8 = (f32) sp198 * var_f4_412;
    sp230 = (f64) spB0;
    sp238 = (f64) spB8;
    temp_f1_430 = sp290 - sp280;
    spA0 = temp_f1_430;
    spA8 = (f32) sp298 - (f32) sp288;
    sp180 = temp_f1_430;
    sp188 = (f64) spA8;
    var_f4_445 = ((f32) sp188 * (f32) sp188) + (((f32) sp180 * (f32) sp180) + ((*(f32 *) ((u8 *) &sp180 + 0x4)) * (*(f32 *) ((u8 *) &sp180 + 0x4))));
    if (var_f4_445 > 1e-12f) {
        if (var_f4_445 > 0.0f) {
            temp_f1_451 = __frsqrte(var_f4_445);
            temp_f1_457 = 0.5 * temp_f1_451 * -(((f64) var_f4_445 * (temp_f1_451 * temp_f1_451)) - 3.0);
            temp_f1_461 = 0.5 * temp_f1_457 * -(((f64) var_f4_445 * (temp_f1_457 * temp_f1_457)) - 3.0);
            var_f4_445 = (f32) ((f64) var_f4_445 * (0.5 * temp_f1_461 * -(((f64) var_f4_445 * (temp_f1_461 * temp_f1_461)) - 3.0)));
        } else if (var_f4_445 < M2C_BITWISE(f32, 0.0)) {
            var_f4_445 = __float_nan;
        } else {
            sp14 = var_f4_445;
            temp_r3_480 = M2C_BITWISE(s32, sp14) & 0x7F800000;
            switch (temp_r3_480) {                  /* switch 2; irregular */
            case 0x7F800000:                        /* switch 2 */
                if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                    var_r0_490 = 1;
                } else {
                    var_r0_490 = 2;
                }
                break;
            case 0x0:                               /* switch 2 */
                if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
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
    sp94 = (*(f32 *) ((u8 *) &sp180 + 0x4)) * var_f3_512;
    sp90 = (f32) sp180 * var_f3_512;
    sp98 = (f32) sp188 * var_f3_512;
    sp220 = (f64) sp90;
    sp228 = (f64) sp98;
    sp80 = ((*(f32 *) ((u8 *) &sp230 + 0x4)) * (f32) sp228) - ((f32) sp238 * (*(f32 *) ((u8 *) &sp220 + 0x4)));
    sp84 = ((f32) sp238 * (f32) sp220) - ((f32) sp230 * (f32) sp228);
    sp88 = ((f32) sp230 * (*(f32 *) ((u8 *) &sp220 + 0x4))) - ((*(f32 *) ((u8 *) &sp230 + 0x4)) * (f32) sp220);
    sp170 = (f64) sp80;
    sp178 = (f64) sp88;
    var_f4_554 = ((f32) sp178 * (f32) sp178) + (((f32) sp170 * (f32) sp170) + ((*(f32 *) ((u8 *) &sp170 + 0x4)) * (*(f32 *) ((u8 *) &sp170 + 0x4))));
    if (var_f4_554 > 1e-12f) {
        if (var_f4_554 > 0.0f) {
            temp_f1_560 = __frsqrte(var_f4_554);
            temp_f1_566 = 0.5 * temp_f1_560 * -(((f64) var_f4_554 * (temp_f1_560 * temp_f1_560)) - 3.0);
            temp_f1_570 = 0.5 * temp_f1_566 * -(((f64) var_f4_554 * (temp_f1_566 * temp_f1_566)) - 3.0);
            var_f4_554 = (f32) ((f64) var_f4_554 * (0.5 * temp_f1_570 * -(((f64) var_f4_554 * (temp_f1_570 * temp_f1_570)) - 3.0)));
        } else if (var_f4_554 < M2C_BITWISE(f32, 0.0)) {
            var_f4_554 = __float_nan;
        } else {
            sp10 = var_f4_554;
            temp_r3_589 = M2C_BITWISE(s32, sp10) & 0x7F800000;
            switch (temp_r3_589) {                  /* switch 3; irregular */
            case 0x7F800000:                        /* switch 3 */
                if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                    var_r0_599 = 1;
                } else {
                    var_r0_599 = 2;
                }
                break;
            case 0x0:                               /* switch 3 */
                if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
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
    sp74 = (*(f32 *) ((u8 *) &sp170 + 0x4)) * var_f3_621;
    sp70 = (f32) sp170 * var_f3_621;
    sp78 = (f32) sp178 * var_f3_621;
    sp210 = (f64) sp70;
    sp218 = (f64) sp78;
    sp48 = ((f32) sp210 * (*(f32 *) ((u8 *) &sp230 + 0x4))) - ((*(f32 *) ((u8 *) &sp210 + 0x4)) * (f32) sp230);
    sp40 = ((*(f32 *) ((u8 *) &sp210 + 0x4)) * (f32) sp238) - ((f32) sp218 * (*(f32 *) ((u8 *) &sp230 + 0x4)));
    sp44 = ((f32) sp218 * (f32) sp230) - ((f32) sp210 * (f32) sp238);
    sp168 = (f64) sp48;
    sp160 = (f64) sp40;
    sp220 = (f64) sp40;
    sp228 = (f64) sp48;
    M2C_STRUCT_COPY((s32) &sp2A0.unk3C + 4, MKModel_GetWorldMatrix(M2C_FIELD(temp_r31_221, MKModel **, 4)) - 4 + 4, 0x40);
    MKVector(0.0f, arg1->unk10, 0.0f);
    temp_f0_677 = sp290 + sp140;
    sp30 = temp_f0_677;
    sp150 = temp_f0_677;
    sp38 = (f32) sp298 + sp148;
    sp158 = (f64) sp38;
    sp310 = (f32) sp150;
    sp314 = (*(f32 *) ((u8 *) &sp150 + 0x4));
    sp318 = (f32) sp158;
    sp31C = 1.0f;
    sp2E0 = (f32) sp220;
    sp2E4 = (*(f32 *) ((u8 *) &sp220 + 0x4));
    sp2E8 = (f32) sp228;
    sp2EC = 0.0f;
    sp2F0 = (f32) sp210;
    sp2F4 = (*(f32 *) ((u8 *) &sp210 + 0x4));
    sp2F8 = (f32) sp218;
    sp2FC = 0.0f;
    sp300 = (f32) sp230;
    sp304 = (*(f32 *) ((u8 *) &sp230 + 0x4));
    sp308 = (f32) sp238;
    sp30C = 0.0f;
    sp2A0.SetRotateAroundAxis(*((MKVector3 *) &sp300), 1.5707964f);
    ((Matrix *) &sp2E0)->Multiply3x3((Matrix *) &sp2E0, &sp2A0);
    sp2A0.SetRotateAroundAxis(*((MKVector3 *) &sp2F0), arg1->unk8);
    ((Matrix *) &sp2E0)->Multiply3x3((Matrix *) &sp2E0, &sp2A0);
    MKModel_SetWorldMatrix(M2C_FIELD(temp_r31_221, MKModel **, 4), *((Matrix *) &sp2E0));
    sp1F0.unk10 = (f64) sp310;
    sp208 = (f64) sp318;
    temp_f0_744 = M2C_FIELD(&MKVector3::up, f64 *, 0) * 5.634608575e-315;
    sp60 = temp_f0_744;
    sp120 = temp_f0_744;
    sp68 = MKVector3::up.unk8 * 500.0f;
    sp128 = (f64) sp68;
    temp_f0_755 = M2C_BITWISE(f64, sp1F0.unk10) - temp_f0_744;
    sp50 = temp_f0_755;
    sp130 = temp_f0_755;
    sp58 = (f32) sp208 - (f32) sp128;
    sp138 = (f64) sp58;
    if (MKCollision_RayCollide(*((MKVector3 *) &sp1F0.unk10), *((MKVector3 *) &sp130), &sp320, (MKCollisionMode) 4, 0) != 0) {
        Tools_GroundColor((MKCollisionResult *) &sp110);
        MKModel_SetColor(M2C_FIELD(temp_r31_221, MKModel **, 4), *((MKVector4 *) &sp110));
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

#if 0 // DRAFT: illegal explicit conversion from 'KDUniformSpline' to
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
    f64 spA0;
    f32 sp98;
    f64 sp90;
    f32 sp88;
    f64 sp80;
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
    f32 temp_f1_1094;
    f32 temp_f2_1004;
    f32 temp_f2_1093;
    f32 temp_f5_1095;
    f32 var_f4_1085;
    f32 var_f5_1101;
    f64 temp_f0_1001;
    f64 temp_f0_1021;
    f64 temp_f0_1061;
    f64 temp_f0_1181;
    f64 temp_f0_962;
    f64 temp_f0_989;
    f64 temp_f1_1106;
    f64 temp_f1_1112;
    f64 temp_f1_1116;
    f64 temp_f3_999;
    s32 temp_r3_1135;
    s32 var_r0_1145;

    sp14 = 0.0f;
    sp150.GetMeasure(0.0f, (Matrix *) &this->unk50.unk14, KDSpline_PositionMixer);
    sp18 = 0.0f;
    ((KDUniformSpline *) &sp150.unk10)->GetMeasure(0.0f, &this->unk50, KDSpline_PositionMixer);
    temp_f0_962 = M2C_BITWISE(f64, sp150.unk10) + M2C_BITWISE(f64, sp150);
    sp30 = temp_f0_962;
    sp170 = temp_f0_962;
    sp38 = sp168 + sp150.unk8;
    sp178 = (f64) sp38;
    sp60 = temp_f0_962 * 5.222099017e-315;
    this->unk200 = sp60;
    sp68 = (f32) sp178 * 0.5f;
    sp180 = sp60;
    sp188 = (f64) sp68;
    this->unk208 = (f64) sp68;
    temp_f0_989 = M2C_FIELD(&MKVector3::up, f64 *, 0) * 5.53552857e-315;
    spA0 = temp_f0_989;
    sp130 = temp_f0_989;
    spA8 = MKVector3::up.unk8 * 100.0f;
    sp138 = (f64) spA8;
    temp_f3_999 = this->unk200;
    temp_f0_1001 = temp_f3_999 + temp_f0_989;
    sp90 = temp_f0_1001;
    temp_f2_1004 = (f32) M2C_FIELD(this, f64 *, 0x208);
    sp140 = temp_f0_1001;
    sp98 = temp_f2_1004 + (f32) sp138;
    sp148 = (f64) sp98;
    sp80 = M2C_FIELD(&MKVector3::up, f64 *, 0) * 5.634608575e-315;
    sp88 = MKVector3::up.unk8 * 500.0f;
    sp110 = sp80;
    sp118 = (f64) sp88;
    temp_f0_1021 = temp_f3_999 - sp110;
    sp70 = temp_f0_1021;
    sp120 = temp_f0_1021;
    sp78 = temp_f2_1004 - (f32) sp118;
    sp128 = (f64) sp78;
    if (MKCollision_RayCollide(*((MKVector3 *) &sp140), *((MKVector3 *) &sp120), &sp190, (MKCollisionMode) 4, 0) != 0) {
        this->unk200 = M2C_BITWISE(f64, sp190);
        this->unk208 = (f64) sp190.unk8;
    }
    spC = 0.0f;
    spC0.GetMeasure(0.01f, (Matrix *) &this->unk50.unk14, KDSpline_PositionMixer);
    sp10 = 0.0f;
    ((KDUniformSpline *) &spC0.unk10)->GetMeasure(0.01f, &this->unk50, KDSpline_PositionMixer);
    temp_f0_1061 = M2C_BITWISE(f64, spC0.unk10) + M2C_BITWISE(f64, spC0);
    sp20 = temp_f0_1061;
    spE0 = temp_f0_1061;
    sp28 = spD8 + spC0.unk8;
    spE8 = (f64) sp28;
    spF0.operator*(0.5f);
    sp50 = spF0 - this->unk200;
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
    temp_f0_1181 = this->unk210 * 5.5769738e-315;
    sp40 = temp_f0_1181;
    spB0 = temp_f0_1181;
    sp48 = (f32) M2C_FIELD(this, f64 *, 0x218) * 200.0f;
    spB8 = (f64) sp48;
    this->unk200 -= temp_f0_1181;
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
    f64 sp40;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f64 sp10;
    s32 sp8;
    ExplosiveBarrel *temp_r28_1381;
    MKProp *temp_r4_1524;
    f32 temp_f1_1572;
    f32 temp_f29_1562;
    f32 temp_f3_1543;
    f64 temp_f0_1482;
    f64 temp_f0_1633;
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
    if (((u8) this->unk231 != 0) && (this->unk238 <= 0.0f)) {
        temp_r3_1361 = SpawnBarrel(NULL);
        if (temp_r3_1361 > -1) {
            PushBarrel(temp_r3_1361);
        }
        this->unk238 = this->unk234;
        if ((u8) this->unk230 != 0) {
            this->unk231 = 0;
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
                ((KDSoundFader *) (((u8 *) temp_r30_1380) + 0x94))->Update(M2C_FIELD(temp_r4_1406, s32 *, 0x60), 1U, 0U, (MKProp *) temp_r28_1381, NULL, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
            }
        } else {
            temp_r28_1381->Enable();
            UpdateBarrelModel(((u8 *) temp_r30_1380) + 0x78);
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
            temp_f0_1482 = (f64) spC0.unk20 + spA0;
            sp40 = temp_f0_1482;
            spB0 = temp_f0_1482;
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
                        temp_f0_1633 = M2C_BITWISE(f64, spC0.unk10) * 5.5769738e-315;
                        sp10 = temp_f0_1633;
                        sp60 = temp_f0_1633;
                        sp18 = M2C_BITWISE(f32, spC0.unk18) * 200.0f;
                        sp68 = (f64) sp18;
                        EmitDust(*((MKVector3 *) &spC0.unk20), *((MKVector3 *) &sp60), MKRand_Float((int *) &gViewSeed, 0.5f, 1.0f));
                        var_r25_1606 += 1;
                    } while (var_r25_1606 < 0xF);
                }
                temp_r5_1654 = this->unk228;
                if ((temp_r5_1654 > 0) && (M2C_FIELD(temp_r30_1380, f32 *, 0x88) <= 10.0f) && (M2C_FIELD(temp_r30_1380, f32 *, 0x8C) < 0.0f) && (MKRand_Int((int *) &gViewSeed, 0, temp_r5_1654) == 0)) {
                    M2C_FIELD(temp_r30_1380, f32 *, 0x8C) = MKRand_Float((int *) &gViewSeed, 0.0f, M2C_FIELD(temp_r30_1380, f32 *, 0x84) * this->unk22C);
                    M2C_FIELD(temp_r30_1380, u8 *, 0x91) = 1U;
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
                    ((KDSoundFader *) (((u8 *) temp_r30_1380) + 0x94))->Update(M2C_FIELD(temp_r4_1710, s32 *, 0x60), 1U, 1U, (MKProp *) temp_r28_1381, NULL, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
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

#if 0 // DRAFT: illegal implicit conversion from 'const char[17]' to
void ExplosiveBarrelPath::LoadDone() {
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    f64 temp_f0_1788;
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
    M2C_STRUCT_COPY((s32) &this->unk1BC + 4, (s32) (&MKProp::loadInfo - 4) + 4, 0x40);
    this->unk200 = this->unk1F0;
    this->unk208 = this->unk1F8;
    this->unk210 = this->unk1E0;
    this->unk218 = this->unk1E8;
    temp_f0_1788 = this->unk210 * 5.5769738e-315;
    sp8 = temp_f0_1788;
    sp18 = temp_f0_1788;
    sp10 = (f32) M2C_FIELD(this, f64 *, 0x218) * 200.0f;
    sp20 = (f64) sp10;
    this->unk200 -= temp_f0_1788;
    var_r29_1806 = 0;
    var_r27_1807 = 0;
    M2C_FIELD(this, f64 *, 0x208) = (f32) ((f32) M2C_FIELD(this, f64 *, 0x208) - (f32) sp20);
    do {
        var_r4_1814 = "P5023_BoomBarrel";
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
                var_r4_1814 = "P3040_BoomBarrel";
                break;
            case 0x62:
                var_r4_1814 = "P4036_BoomBarrel";
                break;
            case 0x64:
            case 0x7A:
                var_r4_1814 = "P1040_BoomBarrel";
                break;
            case 0x63:
                var_r4_1814 = "P0091_BoomBarrel";
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

#if 0 // DRAFT: illegal explicit conversion from 'MKIniLine' to
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
    if (arg0->IsField("LeftTrack") != 0) {
        var_r30_1936 = arg0->unkC->GetSubLine(arg0);
        temp_r3_1937 = arg0->GetNmbrOfSubLines();
        if (temp_r3_1937 != 0) {
            ((KDUniformSpline *) &this->unk50)->Init(temp_r3_1937, 0U);
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
                ((KDUniformSpline *) &this->unk50)->AddNode(*((MKVector3 *) &sp78));
                var_r30_1936 = var_r30_1936->unkC->GetNextLine(var_r30_1936);
                goto loop_9;
            }
        }
        return 1;
    }
    if (arg0->IsField("RightTrack") != 0) {
        var_r30_2010 = arg0->unkC->GetSubLine(arg0);
        temp_r3_2011 = arg0->GetNmbrOfSubLines();
        if (temp_r3_2011 != 0) {
            ((KDUniformSpline *) &this->unk50.unk14)->Init(temp_r3_2011, 0U);
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
                ((KDUniformSpline *) &this->unk50.unk14)->AddNode(*((MKVector3 *) &sp68));
                var_r30_2010 = var_r30_2010->unkC->GetNextLine(var_r30_2010);
                goto loop_18;
            }
        }
        return 1;
    }
    var_r31_2077 = 0;
    if ((arg0->LoadFloat("Speed", &this->unk220, 0) != 0) || (arg0->LoadFloat("Acceleration", &this->unk224, 0) != 0) || (arg0->LoadInt("BounceChance", (int *) &this->unk228, 0) != 0) || (arg0->LoadFloat("BounceSpeed", &this->unk22C, 0) != 0) || (arg0->LoadBool("bAutoShootBarrels", &this->unk231, 0) != 0) || (arg0->LoadBool("bOneShot", &this->unk230, 0) != 0) || (arg0->LoadFloat("fAutoShootDelay", &this->unk234, 0) != 0) || (arg0->LoadFloat("fExplosionRadiusScale", &this->unk23C, 0) != 0)) {
        var_r31_2077 = 1;
    }
    return var_r31_2077;
}
#endif

#if 0 // DRAFT: function call 'KDSound_Stop(unsigned char *)' does not match
void ExplosiveBarrelPath::Deinit() {
    s32 var_r29_2170;
    s32 var_r31_2171;
    void *temp_r30_2173;
    void *temp_r3_2174;

    MKProp::Deinit();
    ((KDUniformSpline *) &this->unk50)->Deinit();
    ((KDUniformSpline *) &this->unk50.unk14)->Deinit();
    var_r29_2170 = 0;
    var_r31_2171 = 0;
    do {
        temp_r30_2173 = this + var_r31_2171;
        temp_r3_2174 = M2C_FIELD(temp_r30_2173, void **, 0x78);
        M2C_FIELD(M2C_FIELD(temp_r3_2174, void **, 0x44), M2C_UNK (**)(void *), 0x34)(temp_r3_2174);
        KDSound_Stop(((u8 *) temp_r30_2173) + 0x94);
        var_r29_2170 += 1;
        var_r31_2171 += 0x44;
    } while (var_r29_2170 < 4);
}
#endif

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
        ((KDSoundFader *) (((u8 *) temp_r4_2210) + 0x94))->Init(0.25f, 0.25f);
        var_r26_2206 += 1;
        var_r30_2203 += 0x44;
    } while (var_r26_2206 < 4);
    this->unk4C = NULL;
    this->unk190 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    this->unk198 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
    this->unk1A0 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    this->unk1A8 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
    this->unkC = (BoundingVolume *) &this->unk190;
    this->unk1B0 = 1;
    M2C_STRUCT_COPY((s32) &this->unk1BC + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
    this->unk8 = &this->unk1C0;
    this->unk200 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    this->unk208 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
    this->unk210 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    this->unk218 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
    this->unk228 = 0x14;
    this->unk22C = 1.0f;
    this->unk231 = 0;
    this->unk230 = 0;
    this->unk232 = 0;
    this->unk234 = 1.0f;
    this->unk238 = 0.0f;
    this->unk23C = 1.0f;
}

#if 0 // DRAFT: illegal implicit conversion from 'KDEnvParticleSystem *' to
void ExplosiveBarrelPathDescriptor::LoadDone() {
    this->unk90 = checked_cast<KDEnvParticleSystem *, MKProp>(gMK->CreateProp("BarrelDustDirtPS"));
    this->unk94 = checked_cast<KDEnvParticleSystem *, MKProp>(gMK->CreateProp("BarrelDustIcePS"));
    MKPropDescriptor::LoadDone();
}
#endif

s32 ExplosiveBarrelPathDescriptor::LoadLine(MKIniLine *arg0) {
    s32 var_r31_2324;

    var_r31_2324 = 0;
    if ((MKPropDescriptor::LoadLine(arg0) != 0) || (KDSound_LoadLine(arg0, "barrelRollSound", (int *) &this->unk60) != 0)) {
        var_r31_2324 = 1;
    }
    return var_r31_2324;
}

void ExplosiveBarrelPathDescriptor::Init() {
    MKPropDescriptor::Init();
    M2C_FIELD(this, f64 *, 0x70) = (f64) M2C_FIELD(&MKVector3::zero, f64 *, 0);
    this->unk78 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
    this->unk80 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    this->unk88 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
    this->unk60 = 0;
    this->unk1C = (BoundingVolume *) &this->unk70;
    this->unkC |= 0x802;
}
