#include "spyro/source/ElementalWall.h"
#include "common/Source/Frustum.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/CrashFirePS.h"
#include "spyro/source/ElectricSparks.h"
#include "spyro/source/EmbersPS.h"
#include "spyro/source/FallingLeaves.h"
#include "spyro/source/Game.h"
#include "spyro/source/GameMessages.h"
#include "spyro/source/HeroInterface.h"
#include "spyro/source/KDPath.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/KDSpline.h"
#include "spyro/source/PooledShatterProp.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/SplineProp.h"
#include "spyro/source/ZapArcFX.h"
#include "unplaced_templates.h"
#include "common/Source/StdMath.h"
#include "common/gc/MKMaterial_GC.h"
#include "common/gc/MKPrimitive_GC.h"
#include "spyro/source/KDRandom.h"
#include "spyro/source/Tools.h"
#include <m2c_macros.h>

extern s32 GS_EarthBarricadeLP;
extern s32 GS_EarthBarricadeStart;
extern s32 GS_EarthBarricadeStop;
extern s32 GS_ElecBarricadeLP;
extern s32 GS_ElecBarricadeStart;
extern s32 GS_ElecBarricadeStop;
extern s32 GS_FireBarricadeLP;
extern s32 GS_FireBarricadeStart;
extern s32 GS_FireBarricadeStop;
extern s32 GS_IceBarricadeLP;
extern s32 GS_IceBarricadeStart;
extern s32 GS_IceBarricadeStop;
extern s32 GS_SpyroEarthBurn;
extern s32 GS_SpyroIceBurn;
extern s32 GS_SpyroLavaBurn;
extern s32 GS_SpyroZapBurn;
extern f32 *KDSpline_PositionMixer;
extern void **gMK;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern GameGlobals gb;
#if 0 // DRAFT: undefined identifier 'KDStateMachine'
static M2C_UNK lit_684;                                /* unable to generate initializer: unknown type */
static KDStateMachine<ElementalWall>::State ElementalWallStates; /* unable to generate initializer: confusing struct layout */
static s32 lit_775 = 1;
#endif

static s32 lit_879 = 1;

static s32 lit_917 = 1;

static u8 lit_996 = 1;

void ElementalWall::CalcBounds() {
    SplineProp::CalcBounds();
    M2C_FIELD(this, f32 *, 0xA4) = (f32) (M2C_FIELD(this, f32 *, 0xA4) + this->unk110);
}

void ElementalWall::StateEWOffExit() {

}

#if 0 // DRAFT: '(' expected
void ElementalWall::StateEWOffUpdate() {
    if (this->unk124 >= this->unk120) {
        ((KDStateMachine<ElementalWall> *) &this->unkE0)->SetState(this, 3, 0U);
        return;
    }
    if (((Frustum *) (M2C_FIELD(&gb, s32 *, 0x3B8) + 0xB0))->IsVisible((Matrix *) this->unk8, this->unkC) != 0) {
        EmitParticles(this->unk124 / this->unk120, 1.0f);
    }
    ((KDSound_SoundWall *) &this->unk130)->SetBeginEndTimes(this->unk124 / this->unk120, 1.0f);
    this->unk124 += gUpdateTimeDelta;
}
#endif

void ElementalWall::StateEWOffEnter() {
    this->unk124 = 0.0f;
}

void ElementalWall::StateEWTurningOffExit() {

}

#if 0 // DRAFT: '(' expected
void ElementalWall::StateEWTurningOffUpdate() {
    if (this->unk124 >= this->unk120) {
        this->unk10C = 0.0f;
        ((KDStateMachine<ElementalWall> *) &this->unkE0)->SetState(this, 3, 0U);
        return;
    }
    if (((Frustum *) (M2C_FIELD(&gb, s32 *, 0x3B8) + 0xB0))->IsVisible((Matrix *) this->unk8, this->unkC) != 0) {
        EmitParticles(this->unk124 / this->unk120, 1.0f);
    }
    ((KDSound_SoundWall *) &this->unk130)->SetBeginEndTimes(this->unk124 / this->unk120, 1.0f);
    this->unk10C = this->unk110 * (1.0f - (this->unk124 / this->unk120));
    this->unk124 += gUpdateTimeDelta;
}
#endif

void ElementalWall::StateEWTurningOffEnter() {
    this->unk124 = 0.0f;
}

void ElementalWall::StateEWOnExit() {

}

#if 0 // DRAFT: undefined identifier '__vptr'
void ElementalWall::StateEWOnUpdate() {
    s8 sp161;
    s8 sp160;
    s32 sp15C;
    f32 sp158;
    s32 sp154;
    s8 sp152;
    s8 sp151;
    s8 sp150;
    f64 sp148;                                      /* compiler-managed */
    f64 sp140;                                      /* compiler-managed */
    ElementalWall *sp13C;
    s32 sp138;
    f64 sp130;
    f64 sp128;
    f64 sp120;
    f64 sp118;
    s32 sp114;
    s32 sp110;
    s8 sp109;
    s8 sp108;
    s32 sp104;
    f32 sp100;
    s32 spFC;
    s8 spFA;
    s8 spF9;
    s8 spF8;
    f64 spF0;                                       /* compiler-managed */
    f64 spE8;                                       /* compiler-managed */
    ElementalWall *spE4;
    s32 spE0;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    f64 spC0;
    s32 spBC;
    s32 spB8;
    s8 spB2;
    s8 spB1;
    s8 spB0;
    s8 spAC;
    f32 spA8;
    f64 spA0;
    f64 sp98;
    s32 sp94;
    s32 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;                                       /* compiler-managed */
    f64 sp70;                                       /* compiler-managed */
    f64 sp68;                                       /* compiler-managed */
    f32 sp64;
    KDUniformSpline sp50;
    Matrix sp40;
    f32 sp38;
    f64 sp30;
    f64 sp20;
    f64 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f1_363;
    f32 var_f1_555;
    f32 var_f30_371;
    f64 temp_f0_353;
    f64 temp_f1_374;
    f64 temp_f1_380;
    f64 temp_f1_384;
    f64 temp_f1_646;
    s32 temp_r3_403;
    s32 var_r0_413;
    u8 var_r0_437;
    u8 var_r30_259;
    void *temp_r3_329;

    if (((Frustum *) (M2C_FIELD(&gb, s32 *, 0x3B8) + 0xB0))->IsVisible((Matrix *) this->unk8, this->unkC) != 0) {
        EmitParticles(0.0f, 1.0f);
    }
    ((KDSound_SoundWall *) &this->unk130)->SetBeginEndTimes(0.0f, 1.0f);
    this->unk124 += gUpdateTimeDelta;
    if ((u8) this->unk128 == 0) {
        var_r30_259 = 0;
        if ((gb.unk0->IsDying() == 0) && (gb.unk0->IsRespawning() == 0)) {
            var_r30_259 = 1;
        }
        this->unk128 = var_r30_259;
    } else if (gb.unk0->IsRespawning() != 0) {
        this->unkC0 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
        this->unkC8 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
        this->unk128 = 1;
    }
    if (((HeroInterface *) gb.unk0 != NULL) && ((u8) this->unk128 != 0) && (M2C_FIELD(gb.unk0->__vptr, u8 (**)(), 0x54)() == 0) && (gb.unk0->IsRespawning() == 0)) {
        temp_r3_329 = M2C_FIELD(gb.unk0->GetProp(), void **, 8);
        sp80 = M2C_FIELD(temp_r3_329, f64 *, 0x30);
        sp88 = M2C_FIELD(temp_r3_329, f64 *, 0x38);
        Tools_GetClosestSplineTime(&this->unkB0->unk30, *((MKVector3 *) &sp80), this->unk104);
        spC = 0.0f;
        sp50.GetMeasure(M2C_ERROR(/* Read from unset register $f1 */), (Matrix *) &this->unkB0->unk30, KDSpline_PositionMixer);
        sp70 = M2C_BITWISE(f64, sp50);
        sp78 = (f64) sp50.unk8;
        temp_f0_353 = sp80 - sp70;
        sp30 = temp_f0_353;
        sp50.unk10 = temp_f0_353;
        sp38 = (f32) sp88 - (f32) sp78;
        temp_f1_363 = M2C_BITWISE(f32, sp50.unk10);
        sp64 = 0.0f;
        sp68 = (f64) sp38;
        var_f30_371 = ((f32) sp68 * (f32) sp68) + ((temp_f1_363 * temp_f1_363) + (0.0f * 0.0f));
        if (var_f30_371 > 0.0f) {
            temp_f1_374 = __frsqrte(var_f30_371);
            temp_f1_380 = 0.5 * temp_f1_374 * -(((f64) var_f30_371 * (temp_f1_374 * temp_f1_374)) - 3.0);
            temp_f1_384 = 0.5 * temp_f1_380 * -(((f64) var_f30_371 * (temp_f1_380 * temp_f1_380)) - 3.0);
            var_f30_371 = (f32) ((f64) var_f30_371 * (0.5 * temp_f1_384 * -(((f64) var_f30_371 * (temp_f1_384 * temp_f1_384)) - 3.0)));
        } else if (var_f30_371 < M2C_BITWISE(f32, 0.0)) {
            var_f30_371 = __float_nan;
        } else {
            sp8 = var_f30_371;
            temp_r3_403 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r3_403) {                  /* irregular */
            case 0x7F800000:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_413 = 1;
                } else {
                    var_r0_413 = 2;
                }
                break;
            case 0x0:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_413 = 5;
                } else {
                    var_r0_413 = 3;
                }
                break;
            default:
                var_r0_413 = 4;
                break;
            }
            if (var_r0_413 == 1) {
                var_f30_371 = __float_nan;
            }
        }
        var_r0_437 = 0;
        if (((f32) M2C_FIELD(this, f64 *, 0xC0) == MKVector3::zero.unk0) && (M2C_FIELD(this, f32 *, 0xC4) == MKVector3::zero.unk4) && ((f32) M2C_FIELD(this, f64 *, 0xC8) == MKVector3::zero.unk8)) {
            var_r0_437 = 1;
        }
        if (var_r0_437 != 0) {
            this->unkC0 = M2C_BITWISE(f64, sp50.unk10);
            this->unkC8 = sp68;
            this->unkD0 = sp80;
            this->unkD8 = sp88;
        }
        if (((u8) this->unk11C != 0) && (var_f30_371 <= (1.5f * gb.unk0->GetCollideRadius()))) {
            sp110 = 7;
            sp114 = 0;
            sp138 = 2;
            sp13C = this;
            sp118 = this->unkC0;
            sp120 = this->unkC8;
            sp150 = 1;
            sp15C = 2;
            sp158 = 10.0f;
            sp151 = 0;
            sp152 = 0;
            sp154 = -1;
            sp128 = M2C_FIELD(&MKVector3::one, f64 *, 0);
            sp130 = M2C_FIELD(&MKVector3::one, f64 *, 8);
            sp160 = 0;
            if (this != NULL) {
                ((MKProp *) &sp20)->GetPos();
                sp140 = sp20;
                sp148 = sp28;
            } else {
                sp140 = 0.0f;
                (*(f32 *) ((u8 *) &sp13C + 0x8)) = 0.0f;
                sp148 = 0.0f;
            }
            sp161 = 0;
            gb.unk0->Message(&sp110);
            return;
        }
        if ((var_f30_371 <= (1.5f * gb.unk0->GetCollideRadius())) && ((*(f32 *) ((u8 *) &sp80 + 0x4)) > -((2.0f * gb.unk0->GetCollideRadius()) - (*(f32 *) ((u8 *) &sp64 + 0x10))))) {
            var_f1_555 = (*(f32 *) ((u8 *) &sp80 + 0x4)) - (*(f32 *) ((u8 *) &sp64 + 0x10));
            if (var_f1_555 < 0.0f) {
                var_f1_555 = -var_f1_555;
            }
            if (var_f1_555 < this->unk10C) {
                spB8 = 7;
                spBC = 0;
                spE0 = 2;
                spE4 = this;
                spC0 = this->unkC0;
                spC8 = this->unkC8;
                spF8 = 1;
                sp104 = 2;
                sp100 = 10.0f;
                spF9 = 0;
                spFA = 0;
                spFC = -1;
                spD0 = M2C_FIELD(&MKVector3::one, f64 *, 0);
                spD8 = M2C_FIELD(&MKVector3::one, f64 *, 8);
                sp108 = 0;
                if (this != NULL) {
                    ((MKProp *) &sp10)->GetPos();
                    spE8 = sp10;
                    spF0 = sp18;
                } else {
                    spE8 = 0.0f;
                    (*(f32 *) ((u8 *) &spE4 + 0x8)) = 0.0f;
                    spF0 = 0.0f;
                }
                sp109 = 0;
                gb.unk0->Message(&spB8);
                return;
            }
            goto block_51;
        }
block_51:
        if ((((f32) M2C_FIELD(this, f64 *, 0xC8) * (f32) sp68) + (((f32) M2C_FIELD(this, f64 *, 0xC0) * M2C_BITWISE(f32, sp50.unk10)) + (M2C_FIELD(this, f32 *, 0xC4) * 0.0f))) < 0.5f) {
            sp94 = 0;
            gb.unk0->GetProp();
            sp40.GetRotationPRY();
            sp90 = 0xE;
            temp_f1_646 = this->unkD0;
            spB1 = 1;
            sp98 = temp_f1_646;
            spA0 = this->unkD8;
            spA8 = sp40.unk4;
            spAC = 0;
            spB0 = 0;
            spB2 = 1;
            spB1 = 1;
            gb.unk0->Message(&sp90, 0, temp_f1_646, sp40.unk4);
            return;
        }
        this->unkC0 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
        this->unkC8 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
    }
}
#endif

void ElementalWall::StateEWOnEnter() {

}

void ElementalWall::StateEWTurningOnExit() {

}

#if 0 // DRAFT: '(' expected
void ElementalWall::StateEWTurningOnUpdate() {
    if (this->unk124 >= this->unk120) {
        this->unk10C = this->unk110;
        ((KDStateMachine<ElementalWall> *) &this->unkE0)->SetState(this, 1, 0U);
        return;
    }
    if (((Frustum *) (M2C_FIELD(&gb, s32 *, 0x3B8) + 0xB0))->IsVisible((Matrix *) this->unk8, this->unkC) != 0) {
        EmitParticles(0.0f, this->unk124 / this->unk120);
    }
    ((KDSound_SoundWall *) &this->unk130)->SetBeginEndTimes(0.0f, this->unk124 / this->unk120);
    this->unk10C = this->unk110 * (this->unk124 / this->unk120);
    this->unk124 += gUpdateTimeDelta;
}
#endif

void ElementalWall::StateEWTurningOnEnter() {
    this->unk124 = 0.0f;
}

#if 0 // DRAFT: undefined identifier 'unk30C'
void ElementalWall::EmitEarthParticles(float arg0, float arg1) {
    f64 sp120;
    f64 sp118;
    f64 sp110;
    f32 sp10C;
    KDUniformSpline spF8;
    f64 spF0;
    f64 spE8;
    f64 spD8;
    f64 spC8;
    f64 spC0;
    f64 spB8;
    f64 spA8;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp50;
    f64 sp48;
    f32 sp40;
    f64 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    s32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f1_802;
    f32 temp_f1_874;
    f32 temp_f1_920;
    f32 temp_f1_951;
    f32 temp_f2_901;
    f32 temp_f2_947;
    f32 temp_f3_833;
    s32 var_r26_867;

    if (gb.unk30C >= this->unkFC) {
        temp_f1_802 = MKRand_Float(&gViewSeed, arg0, arg1);
        sp10 = 0.0f;
        spF8.GetMeasure(temp_f1_802, (Matrix *) &this->unkB0->unk30, KDSpline_PositionMixer);
        sp118 = M2C_BITWISE(f64, spF8);
        sp120 = (f64) spF8.unk8;
        KDRand_UnitVectorXZ();
        sp48 = spD8 * 5.49408334e-315;
        spF8.unk10 = sp48;
        sp50 = spE0 * 50.0f;
        spE8 = sp48;
        sp110 = (f64) sp50;
        temp_f3_833 = this->unk110;
        spF0 = (f64) sp50;
        sp10C = MKRand_Float(&gViewSeed, temp_f3_833 / 3.0f, temp_f3_833 / 1.5f);
        sp1C = MKRand_Int(&gViewSeed, 0, 3);
        sp20 = MKRand_Float(&gViewSeed, 1.0f, 1.5f);
        ((FallingLeaves *) (M2C_FIELD(checked_cast<ElementalWallDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), FallingLeaves **, 0x60)))->Emit(*((MKVector3 *) &sp118), *((MKVector3 *) &spF8.unk10), sp20, sp1C, 1U);
        var_r26_867 = 0;
loop_3:
        if ((f32) var_r26_867 < (1.5f * (f32) this->unk104)) {
            temp_f1_874 = MKRand_Float(&gViewSeed, arg0, arg1);
            spC = 0.0f;
            ((KDUniformSpline *) &spC8)->GetMeasure(temp_f1_874, (Matrix *) &this->unkB0->unk30, KDSpline_PositionMixer);
            sp118 = spC8;
            sp120 = spD0;
            KDRand_UnitVectorXZ();
            sp38 = spA8 * 5.53552857e-315;
            spF8.unk10 = sp38;
            sp40 = spB0 * 100.0f;
            spB8 = sp38;
            sp110 = (f64) sp40;
            temp_f2_901 = this->unk110;
            spC0 = (f64) sp40;
            sp10C = MKRand_Float(&gViewSeed, 0.75f * temp_f2_901, 1.5f * temp_f2_901);
            sp18 = MKRand_Float(&gViewSeed, 0.1f, 0.5f);
            gb.EmitSmallRocks(*((MKVector3 *) &sp118), *((MKVector3 *) &spF8.unk10), sp18);
            temp_f1_920 = MKRand_Float(&gViewSeed, arg0, arg1);
            sp8 = 0.0f;
            ((KDUniformSpline *) &sp98)->GetMeasure(temp_f1_920, (Matrix *) &this->unkB0->unk30, KDSpline_PositionMixer);
            sp118 = sp98;
            sp120 = spA0;
            KDRand_UnitVectorXZ();
            sp28 = sp78 * 5.53552857e-315;
            spF8.unk10 = sp28;
            sp30 = sp80 * 100.0f;
            sp88 = sp28;
            sp110 = (f64) sp30;
            temp_f2_947 = this->unk110;
            sp90 = (f64) sp30;
            temp_f1_951 = MKRand_Float(&gViewSeed, 0.75f * temp_f2_947, 1.5f * temp_f2_947);
            sp58 = 0.0f;
            sp5C = 1.0f;
            sp10C = temp_f1_951;
            sp60 = 0.0f;
            sp64 = 1.0f;
            sp68 = (f64) sp58;
            sp70 = (f64) sp60;
            sp14 = MKRand_Float(&gViewSeed, 2.0f, 5.0f);
            ((EmbersPS *) gb.unk74)->Emit(*((MKVector3 *) &sp118), *((MKVector3 *) &spF8.unk10), sp14, *((MKVector4 *) &sp68), 0.0f);
            var_r26_867 += 1;
            goto loop_3;
        }
        this->unkFC = gb.unk30C + 0.25f;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk30C'
void ElementalWall::EmitIceParticles(float arg0, float arg1) {
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f32 sp64;
    KDUniformSpline sp50;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    f32 spC;
    f32 sp8;
    MKPropDescriptor *temp_r29_1053;
    f32 temp_f1_1056;
    f32 temp_f1_1116;
    s32 var_r28_1110;
    void *temp_r27_1157;
    void *temp_r3_1071;
    void *temp_r3_1154;

    if (gb.unk30C >= this->unkFC) {
        temp_r29_1053 = checked_cast<ShatterableDescriptor *, MKPropDescriptor>(M2C_FIELD(*gMK, MKPropDescriptor *(**)(void **, M2C_UNK *), 0x5C)(gMK, "IceCube"));
        temp_f1_1056 = MKRand_Float(&gViewSeed, arg0, arg1);
        spC = 0.0f;
        sp50.GetMeasure(temp_f1_1056, (Matrix *) &this->unkB0->unk30, KDSpline_PositionMixer);
        sp70 = M2C_BITWISE(f64, sp50);
        sp78 = (f64) sp50.unk8;
        temp_r3_1071 = checked_cast<PooledShatterProp *, MKProp>(temp_r29_1053->CreateInstance());
        if (temp_r3_1071 != NULL) {
            M2C_FIELD(M2C_FIELD(temp_r3_1071, void **, 0x44), M2C_UNK (**)(f64 *), 0x38)(&sp70);
            M2C_FIELD(M2C_FIELD(temp_r3_1071, void **, 0x44), M2C_UNK (**)(void *), 0x20)(temp_r3_1071);
            M2C_FIELD(M2C_FIELD(temp_r3_1071, void **, 0x44), M2C_UNK (**)(void *), 0x30)(temp_r3_1071);
            M2C_FIELD(M2C_FIELD(temp_r3_1071, void **, 0x44), M2C_UNK (**)(void *, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK), 0x94)(temp_r3_1071, 0, 0, -1, 0, 0, 0);
        }
        this->unkFC = gb.unk30C + 0.5f;
    }
    var_r28_1110 = 0;
loop_8:
    if (var_r28_1110 < (s32) ((s32) this->unk104 / 2)) {
        temp_f1_1116 = MKRand_Float(&gViewSeed, arg0, arg1);
        sp8 = 0.0f;
        ((KDUniformSpline *) &sp40)->GetMeasure(temp_f1_1116, (Matrix *) &this->unkB0->unk30, KDSpline_PositionMixer);
        sp70 = sp40;
        sp78 = sp48;
        KDRand_UnitVector();
        sp10 = sp20 * 5.56078426e-315;
        sp30 = sp10;
        sp18 = sp28 * 150.0f;
        sp50.unk10 = sp10;
        sp38 = (f64) sp18;
        sp68 = (f64) sp18;
        sp64 = this->unk110 * MKRand_Float(&gViewSeed, 2.0f, 3.0f);
        temp_r3_1154 = M2C_FIELD(M2C_FIELD(gb.unk2A0, void **, 0x44), void *(**)(void *), 0x3C)(gb.unk2A0);
        if (temp_r3_1154 != NULL) {
            temp_r27_1157 = M2C_FIELD(temp_r3_1154, void **, 0x2C);
            M2C_FIELD(temp_r3_1154, f64 *, 0) = sp70;
            M2C_FIELD(temp_r3_1154, f64 *, 8) = sp78;
            M2C_FIELD(temp_r3_1154, f32 *, 0x20) = 0.0f;
            M2C_FIELD(temp_r3_1154, f32 *, 0x28) = 0.0f;
            M2C_FIELD(temp_r27_1157, f64 *, 0) = M2C_BITWISE(f64, sp50.unk10);
            M2C_FIELD(temp_r27_1157, f64 *, 8) = sp68;
            M2C_FIELD(temp_r27_1157, f32 *, 0x18) = MKRand_Float(&gViewSeed, 0.25f, 1.0f);
            M2C_FIELD(temp_r27_1157, f32 *, 0x10) = MKRand_Float(&gViewSeed, -3.1415927f, 3.1415927f);
            M2C_FIELD(temp_r27_1157, f32 *, 0x14) = (f32) M2C_FIELD(gb.unk2A0, f32 *, 0xF4);
        }
        var_r28_1110 += 1;
        goto loop_8;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk30C'
void ElementalWall::EmitElectricityParticles(float arg0, float arg1) {
    f64 spB0;
    f64 spA8;
    f64 spA0;
    KDUniformSpline sp88;
    f64 sp80;
    f64 sp78;
    f64 sp68;
    f64 sp58;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f1_1238;
    f32 temp_f1_1292;
    s32 var_r29_1232;

    if (gb.unk30C >= this->unkFC) {
        var_r29_1232 = 0;
loop_3:
        if (var_r29_1232 < (s32) ((s32) this->unk104 / 2)) {
            temp_f1_1238 = MKRand_Float(&gViewSeed, arg0, arg1);
            spC = 0.0f;
            sp88.GetMeasure(temp_f1_1238, (Matrix *) &this->unkB0->unk30, KDSpline_PositionMixer);
            spA8 = M2C_BITWISE(f64, sp88);
            spB0 = (f64) sp88.unk8;
            (*(f32 *) ((u8 *) &spA8 + 0x4)) += this->unk110 * MKRand_Float(&gViewSeed, 0.0f, 1.0f);
            KDRand_UnitVector();
            sp18 = sp68 * 5.60222949e-315;
            sp78 = sp18;
            sp20 = sp70 * 300.0f;
            sp88.unk10 = sp18;
            sp80 = (f64) sp20;
            spA0 = (f64) sp20;
            ((ElectricSparks *) gb.unk230)->Emit(*((MKVector3 *) &spA8), *((MKVector3 *) &sp88.unk10), MKRand_Float(&gViewSeed, 1.0f, 2.0f), 1U);
            var_r29_1232 += 1;
            goto loop_3;
        }
        temp_f1_1292 = MKRand_Float(&gViewSeed, arg0, arg1);
        sp8 = 0.0f;
        ((KDUniformSpline *) &sp58)->GetMeasure(temp_f1_1292, (Matrix *) &this->unkB0->unk30, KDSpline_PositionMixer);
        spA8 = sp58;
        spB0 = sp60;
        (*(f32 *) ((u8 *) &spA8 + 0x4)) += this->unk10C * (this->unk118 * (f32) (s32) ((f32) this->unk108 * MKRand_Float(&gViewSeed, 0.0f, 1.0f)));
        KDRand_UnitVector();
        sp28 = 1.0f;
        sp2C = 0.0f;
        sp30 = 0.2f;
        sp34 = 1.0f;
        sp88.unk10 = sp48;
        spA0 = sp50;
        sp38 = (f64) sp28;
        sp40 = (f64) sp30;
        sp10 = 0.1f * (0.01f * this->unk10C);
        ((ZapArcFX *) gb.unk94)->Trigger(*((MKVector3 *) &spA8), *((MKVector3 *) &sp88.unk10), sp10, lit_996, (MKVector4) &sp38);
        this->unkFC = gb.unk30C + 0.05f;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk30C'
void ElementalWall::EmitFireParticles(float arg0, float arg1) {
    f64 sp118;
    f64 sp110;
    f64 sp108;
    f32 sp104;
    KDUniformSpline spF0;
    f64 spE8;
    f64 spE0;
    f64 spD0;
    f64 spC0;
    f64 spB8;
    f64 spB0;
    f64 spA0;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp54;
    f32 sp50;
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
    f32 temp_f1_1420;
    f32 temp_f1_1450;
    f32 temp_f1_1481;
    f32 temp_f1_1526;
    f32 temp_f1_1553;
    f32 temp_f1_1556;
    f32 temp_f2_1508;
    s32 var_r27_1475;

    if (gb.unk30C >= this->unkFC) {
        temp_f1_1420 = MKRand_Float(&gViewSeed, arg0, arg1);
        sp10 = 0.0f;
        spF0.GetMeasure(temp_f1_1420, (Matrix *) &this->unkB0->unk30, KDSpline_PositionMixer);
        sp110 = M2C_BITWISE(f64, spF0);
        sp118 = (f64) spF0.unk8;
        KDRand_UnitVectorXZ();
        sp40 = spD0 * 5.5769738e-315;
        spF0.unk10 = sp40;
        sp48 = spD8 * 200.0f;
        spE0 = sp40;
        sp108 = (f64) sp48;
        temp_f1_1450 = this->unk110;
        spE8 = (f64) sp48;
        sp104 = MKRand_Float(&gViewSeed, temp_f1_1450, 2.0f * temp_f1_1450);
        gb.unk240.Emit(*((MKVector3 *) &sp110), *((MKVector3 *) &spF0.unk10), MKRand_Float(&gViewSeed, 2.0f, 5.0f), 1.0f);
        var_r27_1475 = 0;
loop_3:
        if (var_r27_1475 < (s32) this->unk104) {
            temp_f1_1481 = MKRand_Float(&gViewSeed, arg0, arg1);
            spC = 0.0f;
            ((KDUniformSpline *) &spC0)->GetMeasure(temp_f1_1481, (Matrix *) &this->unkB0->unk30, KDSpline_PositionMixer);
            sp110 = spC0;
            sp118 = spC8;
            KDRand_UnitVectorXZ();
            sp30 = spA0 * 5.45263811e-315;
            spF0.unk10 = sp30;
            sp38 = spA8 * 25.0f;
            spB0 = sp30;
            sp108 = (f64) sp38;
            temp_f2_1508 = this->unk110;
            spB8 = (f64) sp38;
            sp104 = MKRand_Float(&gViewSeed, 0.5f * temp_f2_1508, temp_f2_1508);
            sp18 = MKRand_Float(&gViewSeed, 2.0f, 5.0f);
            ((CrashFirePS *) gb.unk68)->Emit(*((MKVector3 *) &sp110), *((MKVector3 *) &spF0.unk10), sp18);
            temp_f1_1526 = MKRand_Float(&gViewSeed, arg0, arg1);
            sp8 = 0.0f;
            ((KDUniformSpline *) &sp90)->GetMeasure(temp_f1_1526, (Matrix *) &this->unkB0->unk30, KDSpline_PositionMixer);
            sp110 = sp90;
            sp118 = sp98;
            KDRand_UnitVectorXZ();
            sp20 = sp70 * 5.49408334e-315;
            spF0.unk10 = sp20;
            sp28 = sp78 * 50.0f;
            sp80 = sp20;
            sp108 = (f64) sp28;
            temp_f1_1553 = this->unk110;
            sp88 = (f64) sp28;
            temp_f1_1556 = MKRand_Float(&gViewSeed, temp_f1_1553, 2.0f * temp_f1_1553);
            sp50 = 1.0f;
            sp54 = 0.1f;
            sp104 = temp_f1_1556;
            sp58 = 0.1f;
            sp5C = 1.0f;
            sp60 = (f64) sp50;
            sp68 = (f64) sp58;
            sp14 = MKRand_Float(&gViewSeed, 2.0f, 5.0f);
            ((EmbersPS *) gb.unk74)->Emit(*((MKVector3 *) &sp110), *((MKVector3 *) &spF0.unk10), sp14, *((MKVector4 *) &sp60), 0.0f);
            var_r27_1475 += 1;
            goto loop_3;
        }
        this->unkFC = gb.unk30C + 0.5f;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'KDStateMachine'
void ElementalWall::EmitParticles(float arg0, float arg1) {
    s32 temp_r0_1629;

    if (((KDStateMachine<ElementalWall> *) &this->unkE0)->GetState() != 3) {
        temp_r0_1629 = this->unk100;
        switch (temp_r0_1629) {                     /* irregular */
        case 0:
            EmitFireParticles(arg0, arg1);
            return;
        case 1:
            EmitElectricityParticles(arg0, arg1);
            return;
        case 2:
            EmitIceParticles(arg0, arg1);
            return;
        case 3:
            EmitEarthParticles(arg0, arg1);
            break;
        }
    }
}
#endif

#if 0 // DRAFT: function call 'memcpy(long, long, int)' does not match
void ElementalWall::DrawEarthWall(float arg0, float arg1) {
    Matrix sp230;
    M2C_UNK sp22C;
    f32 sp220;
    f32 sp21C;
    f32 sp218;
    f64 sp210;                                      /* compiler-managed */
    f64 sp208;
    f64 sp200;                                      /* compiler-managed */
    f64 sp1E0;
    f64 sp1D8;                                      /* compiler-managed */
    KDSplinePathSegment sp1B8;
    f64 sp1A8;
    KDSplinePathSegment sp188;
    f64 sp178;
    f64 sp168;
    f64 sp160;
    f64 sp158;
    f64 sp150;
    f64 sp148;
    f64 sp138;
    f64 sp130;
    f64 sp128;
    f64 sp120;
    f64 sp118;
    f64 sp110;
    f64 sp108;
    f64 sp100;
    f64 spF8;
    f64 spE8;
    f64 spE0;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    f32 spC4;
    f32 spC0;
    f32 spBC;
    f32 spB8;
    f32 spB4;
    f32 spB0;
    f32 spAC;
    f32 spA8;
    f32 spA0;
    f64 sp98;
    f32 sp90;
    f64 sp88;
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    f32 sp70;
    f64 sp68;
    f32 sp60;
    f64 sp58;
    f32 sp50;
    f64 sp48;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp14;
    f32 sp10;
    f32 temp_f0_1979;
    f32 temp_f18_2105;
    f32 temp_f1_1877;
    f32 temp_f1_1978;
    f32 temp_f1_2106;
    f32 temp_f1_2181;
    f32 temp_f1_2200;
    f32 temp_f22_1783;
    f32 temp_f23_1785;
    f32 temp_f24_1787;
    f32 temp_f2_1878;
    f32 temp_f3_1961;
    f32 temp_f4_1959;
    f32 temp_f5_1962;
    f32 var_f18_2185;
    f32 var_f1_1801;
    f32 var_f1_1838;
    f32 var_f2_1742;
    f32 var_f2_1952;
    f32 var_f3_2055;
    f32 var_f4_1885;
    f32 var_f4_1988;
    f64 temp_f0_2073;
    f64 temp_f0_2122;
    f64 temp_f0_2133;
    f64 temp_f0_2149;
    f64 temp_f0_2212;
    f64 temp_f1_1891;
    f64 temp_f1_1897;
    f64 temp_f1_1901;
    f64 temp_f1_1994;
    f64 temp_f1_2000;
    f64 temp_f1_2004;
    s32 temp_r0_1760;
    s32 temp_r3_1920;
    s32 temp_r3_2023;
    s32 var_r0_1930;
    s32 var_r0_2033;
    s32 var_r27_1790;
    s32 var_r28_1748;
    s32 var_r4_1754;

    M2C_STRUCT_COPY((s32) &sp22C + 4, (s32) &this->unk4C + 4, 0x40);
    spB8 = 0.0f;
    spBC = 0.0f;
    spC0 = 0.0f;
    spC4 = 0.0f;
    sp1D8 = (f64) spB8;
    sp1E0 = (f64) spC0;
    sp218 = 1.0f;
    sp21C = 1.0f;
    sp220 = 1.0f;
    sp230.Scale3x3(&sp230, *((MKVector3 *) &sp218));
    var_f2_1742 = arg1 - arg0;
    if (var_f2_1742 < 0.0f) {
        var_f2_1742 = -var_f2_1742;
    }
    var_r28_1748 = this->unk104;
    var_r4_1754 = lit_917;
    temp_r0_1760 = (s32) ((f32) var_r28_1748 * var_f2_1742);
    if (temp_r0_1760 > var_r4_1754) {
        var_r4_1754 = temp_r0_1760;
    }
    if (var_r4_1754 < var_r28_1748) {
        var_r28_1748 = var_r4_1754;
    }
    MKMaterial_SetMaterial(this->unkF4);
    MKPrimitive(0xC, 0x10);
    MKSetMatrix(sp230);
    MKBegin((var_r28_1748 + 1) * 2);
    temp_f22_1783 = MKVector3::up.unk4;
    temp_f23_1785 = MKVector3::up.unk8;
    temp_f24_1787 = MKVector3::up.unk0;
    var_r27_1790 = 0;
loop_61:
    if (var_r27_1790 < (s32) (var_r28_1748 + 1)) {
        if (var_r27_1790 == var_r28_1748) {
            ((MKProp *) &sp1A8)->GetPos();
            var_f1_1801 = 1.0f;
            if (arg1 < var_f1_1801) {
                var_f1_1801 = arg1;
            }
            sp1B8.GetPosition(var_f1_1801);
            sp58 = sp1B8.unk0 - sp1A8;
            sp1B8.unk10 = sp58;
            sp60 = sp1B8.unk8 - sp1B0;
            sp208 = sp58;
            sp1B8.unk18 = (f64) sp60;
            sp210 = (f64) sp60;
        } else {
            ((MKProp *) &sp178)->GetPos();
            var_f1_1838 = ((f32) var_r27_1790 * this->unk114) + arg0;
            if (var_f1_1838 < 1.0f) {

            } else {
                var_f1_1838 = 1.0f;
            }
            sp188.GetPosition(var_f1_1838);
            sp48 = sp188.unk0 - sp178;
            sp188.unk10 = sp48;
            sp50 = sp188.unk8 - sp180;
            sp208 = sp48;
            sp188.unk18 = (f64) sp50;
            sp210 = (f64) sp50;
        }
        ((KDSplinePathSegment *) &sp168)->GetVelocity((f32) var_r27_1790 * this->unk114);
        sp1B8.unk30.unk10 = sp168;
        temp_f1_1877 = M2C_BITWISE(f32, sp1B8.unk30.unk10);
        temp_f2_1878 = M2C_BITWISE(f32, sp1B8.unk44);
        sp200 = sp170;
        var_f4_1885 = ((f32) sp200 * (f32) sp200) + ((temp_f1_1877 * temp_f1_1877) + (temp_f2_1878 * temp_f2_1878));
        if (var_f4_1885 > 0.000001f) {
            if (var_f4_1885 > 0.0f) {
                temp_f1_1891 = __frsqrte(var_f4_1885);
                temp_f1_1897 = 0.5 * temp_f1_1891 * -(((f64) var_f4_1885 * (temp_f1_1891 * temp_f1_1891)) - 3.0);
                temp_f1_1901 = 0.5 * temp_f1_1897 * -(((f64) var_f4_1885 * (temp_f1_1897 * temp_f1_1897)) - 3.0);
                var_f4_1885 = (f32) ((f64) var_f4_1885 * (0.5 * temp_f1_1901 * -(((f64) var_f4_1885 * (temp_f1_1901 * temp_f1_1901)) - 3.0)));
            } else if (var_f4_1885 < M2C_BITWISE(f32, 0.0)) {
                var_f4_1885 = __float_nan;
            } else {
                sp14 = var_f4_1885;
                temp_r3_1920 = M2C_BITWISE(s32, sp14) & 0x7F800000;
                switch (temp_r3_1920) {             /* switch 1; irregular */
                case 0x7F800000:                    /* switch 1 */
                    if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                        var_r0_1930 = 1;
                    } else {
                        var_r0_1930 = 2;
                    }
                    break;
                case 0x0:                           /* switch 1 */
                    if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                        var_r0_1930 = 5;
                    } else {
                        var_r0_1930 = 3;
                    }
                    break;
                default:                            /* switch 1 */
                    var_r0_1930 = 4;
                    break;
                }
                if (var_r0_1930 == 1) {
                    var_f4_1885 = __float_nan;
                }
            }
            var_f2_1952 = 1.0f / var_f4_1885;
        } else {
            var_f2_1952 = 0.0f;
        }
        temp_f4_1959 = M2C_BITWISE(f32, sp1B8.unk44) * var_f2_1952;
        temp_f3_1961 = (f32) sp200 * var_f2_1952;
        temp_f5_1962 = M2C_BITWISE(f32, sp1B8.unk30.unk10) * var_f2_1952;
        sp1B8.unk44 = temp_f4_1959;
        sp1B8.unk30.unk10 = temp_f5_1962;
        sp200 = temp_f3_1961;
        sp38 = (temp_f22_1783 * temp_f3_1961) - (temp_f23_1785 * temp_f4_1959);
        sp3C = (temp_f23_1785 * temp_f5_1962) - (temp_f24_1787 * temp_f3_1961);
        sp40 = (temp_f24_1787 * temp_f4_1959) - (temp_f22_1783 * temp_f5_1962);
        sp1B8.unk30 = (f64) sp38;
        temp_f1_1978 = M2C_BITWISE(f32, sp1B8.unk30);
        temp_f0_1979 = M2C_BITWISE(f32, sp1B8.unk30.unk4);
        sp1B8.unk30.unk8 = (f64) sp40;
        sp158 = (f64) sp38;
        sp160 = (f64) sp40;
        var_f4_1988 = (sp1B8.unk30.unk8 * sp1B8.unk30.unk8) + ((temp_f1_1978 * temp_f1_1978) + (temp_f0_1979 * temp_f0_1979));
        if (var_f4_1988 > 0.000001f) {
            if (var_f4_1988 > 0.0f) {
                temp_f1_1994 = __frsqrte(var_f4_1988);
                temp_f1_2000 = 0.5 * temp_f1_1994 * -(((f64) var_f4_1988 * (temp_f1_1994 * temp_f1_1994)) - 3.0);
                temp_f1_2004 = 0.5 * temp_f1_2000 * -(((f64) var_f4_1988 * (temp_f1_2000 * temp_f1_2000)) - 3.0);
                var_f4_1988 = (f32) ((f64) var_f4_1988 * (0.5 * temp_f1_2004 * -(((f64) var_f4_1988 * (temp_f1_2004 * temp_f1_2004)) - 3.0)));
            } else if (var_f4_1988 < M2C_BITWISE(f32, 0.0)) {
                var_f4_1988 = __float_nan;
            } else {
                sp10 = var_f4_1988;
                temp_r3_2023 = M2C_BITWISE(s32, sp10) & 0x7F800000;
                switch (temp_r3_2023) {             /* switch 2; irregular */
                case 0x7F800000:                    /* switch 2 */
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_2033 = 1;
                    } else {
                        var_r0_2033 = 2;
                    }
                    break;
                case 0x0:                           /* switch 2 */
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_2033 = 5;
                    } else {
                        var_r0_2033 = 3;
                    }
                    break;
                default:                            /* switch 2 */
                    var_r0_2033 = 4;
                    break;
                }
                if (var_r0_2033 == 1) {
                    var_f4_1988 = __float_nan;
                }
            }
            var_f3_2055 = 1.0f / var_f4_1988;
        } else {
            var_f3_2055 = 0.0f;
        }
        sp1B8.unk30 = M2C_BITWISE(f32, sp1B8.unk30) * var_f3_2055;
        sp1B8.unk30.unk4 = M2C_BITWISE(f32, sp1B8.unk30.unk4) * var_f3_2055;
        sp1B8.unk30.unk8 *= var_f3_2055;
        KDRand_UnitVector();
        temp_f0_2073 = sp138 * 5.398241246e-315;
        sp28 = temp_f0_2073;
        sp148 = temp_f0_2073;
        sp30 = sp140 * 10.0f;
        sp150 = (f64) sp30;
        sp208 += temp_f0_2073;
        sp210 = (f32) sp210 + (f32) sp150;
        temp_f18_2105 = 4.0f * ((f32) var_r27_1790 / (f32) this->unk104);
        temp_f1_2106 = MKRand_Float(&gViewSeed, 0.8f, 1.0f);
        spA8 = 0.0f;
        spAC = temp_f1_2106;
        spB0 = 0.0f;
        spB4 = temp_f1_2106;
        sp128 = (f64) spA8;
        sp130 = (f64) spB0;
        MKSetColorV(*((MKVector4 *) &sp128));
        MKSetTexCoord1F(temp_f18_2105, 0.95f);
        temp_f0_2122 = (f64) sp1B8.unk30 * 5.45263811e-315;
        sp98 = temp_f0_2122;
        sp108 = temp_f0_2122;
        spA0 = sp1B8.unk30.unk8 * 25.0f;
        sp110 = (f64) spA0;
        temp_f0_2133 = sp208 + temp_f0_2122;
        sp88 = temp_f0_2133;
        sp118 = temp_f0_2133;
        sp90 = sp210 + (f32) sp110;
        sp120 = (f64) sp90;
        MKSetPositionV(*((MKVector3 *) &sp118));
        KDRand_UnitVector();
        temp_f0_2149 = spE8 * 5.439686476e-315;
        sp18 = temp_f0_2149;
        spF8 = temp_f0_2149;
        sp20 = spF0 * 20.0f;
        sp100 = (f64) sp20;
        sp208 += temp_f0_2149;
        sp210 += (f32) sp100;
        MKRand_Float(&gViewSeed, 0.0f, 30.000002f);
        MKSetColorV(*((MKVector4 *) &sp1B8.unk20));
        MKSetTexCoord1F(temp_f18_2105, 0.05f);
        temp_f1_2181 = (f32) var_r27_1790 * this->unk114;
        if (temp_f1_2181 > 0.6f) {
            var_f18_2185 = 1.5f - temp_f1_2181;
        } else if (temp_f1_2181 < 0.4f) {
            var_f18_2185 = 0.5f + temp_f1_2181;
        } else {
            var_f18_2185 = 0.9f;
        }
        temp_f1_2200 = MKRand_Float(&gViewSeed, -33.0f, 33.0f);
        sp80 = 0.0f;
        sp78 = 0.0f;
        sp7C = (this->unk10C * var_f18_2185) + temp_f1_2200;
        spD0 = (f64) sp80;
        spC8 = (f64) sp78;
        temp_f0_2212 = sp208 + spC8;
        sp68 = temp_f0_2212;
        spD8 = temp_f0_2212;
        sp70 = sp210 + (f32) spD0;
        spE0 = (f64) sp70;
        MKSetPositionV(*((MKVector3 *) &spD8));
        var_r27_1790 += 1;
        goto loop_61;
    }
    MKEnd();
    MKEndPrimitive();
}
#endif

#if 0 // DRAFT: function call 'memcpy(long, long, int)' does not match
void ElementalWall::DrawIceWall(float arg0, float arg1) {
    Matrix sp230;
    M2C_UNK sp22C;
    f32 sp220;
    f32 sp21C;
    f32 sp218;
    f64 sp210;                                      /* compiler-managed */
    f64 sp208;
    f64 sp200;                                      /* compiler-managed */
    f64 sp1E0;
    f64 sp1D8;                                      /* compiler-managed */
    KDSplinePathSegment sp1B8;
    f64 sp1A8;
    KDSplinePathSegment sp188;
    f64 sp178;
    f64 sp168;
    f64 sp160;
    f64 sp158;
    f64 sp150;
    f64 sp148;
    f64 sp138;
    f64 sp130;
    f64 sp128;
    f64 sp120;
    f64 sp118;
    f64 sp110;
    f64 sp108;
    f64 sp100;
    f64 spF8;
    f64 spE8;
    f64 spE0;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    f32 spC4;
    f32 spC0;
    f32 spBC;
    f32 spB8;
    f32 spB4;
    f32 spB0;
    f32 spAC;
    f32 spA8;
    f32 spA0;
    f64 sp98;
    f32 sp90;
    f64 sp88;
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    f32 sp70;
    f64 sp68;
    f32 sp60;
    f64 sp58;
    f32 sp50;
    f64 sp48;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp14;
    f32 sp10;
    f32 temp_f0_2571;
    f32 temp_f18_2697;
    f32 temp_f1_2469;
    f32 temp_f1_2570;
    f32 temp_f1_2698;
    f32 temp_f1_2773;
    f32 temp_f1_2792;
    f32 temp_f22_2375;
    f32 temp_f23_2377;
    f32 temp_f24_2379;
    f32 temp_f2_2470;
    f32 temp_f3_2553;
    f32 temp_f4_2551;
    f32 temp_f5_2554;
    f32 var_f18_2777;
    f32 var_f1_2393;
    f32 var_f1_2430;
    f32 var_f2_2334;
    f32 var_f2_2544;
    f32 var_f3_2647;
    f32 var_f4_2477;
    f32 var_f4_2580;
    f64 temp_f0_2665;
    f64 temp_f0_2714;
    f64 temp_f0_2725;
    f64 temp_f0_2741;
    f64 temp_f0_2804;
    f64 temp_f1_2483;
    f64 temp_f1_2489;
    f64 temp_f1_2493;
    f64 temp_f1_2586;
    f64 temp_f1_2592;
    f64 temp_f1_2596;
    s32 temp_r0_2352;
    s32 temp_r3_2512;
    s32 temp_r3_2615;
    s32 var_r0_2522;
    s32 var_r0_2625;
    s32 var_r27_2382;
    s32 var_r28_2340;
    s32 var_r4_2346;

    M2C_STRUCT_COPY((s32) &sp22C + 4, (s32) &this->unk4C + 4, 0x40);
    spB8 = 0.0f;
    spBC = 0.0f;
    spC0 = 0.0f;
    spC4 = 0.0f;
    sp1D8 = (f64) spB8;
    sp1E0 = (f64) spC0;
    sp218 = 1.0f;
    sp21C = 1.0f;
    sp220 = 1.0f;
    sp230.Scale3x3(&sp230, *((MKVector3 *) &sp218));
    var_f2_2334 = arg1 - arg0;
    if (var_f2_2334 < 0.0f) {
        var_f2_2334 = -var_f2_2334;
    }
    var_r28_2340 = this->unk104;
    var_r4_2346 = lit_879;
    temp_r0_2352 = (s32) ((f32) var_r28_2340 * var_f2_2334);
    if (temp_r0_2352 > var_r4_2346) {
        var_r4_2346 = temp_r0_2352;
    }
    if (var_r4_2346 < var_r28_2340) {
        var_r28_2340 = var_r4_2346;
    }
    MKMaterial_SetMaterial(this->unkF4);
    MKPrimitive(0xC, 0x10);
    MKSetMatrix(sp230);
    MKBegin((var_r28_2340 + 1) * 2);
    temp_f22_2375 = MKVector3::up.unk4;
    temp_f23_2377 = MKVector3::up.unk8;
    temp_f24_2379 = MKVector3::up.unk0;
    var_r27_2382 = 0;
loop_61:
    if (var_r27_2382 < (s32) (var_r28_2340 + 1)) {
        if (var_r27_2382 == var_r28_2340) {
            ((MKProp *) &sp1A8)->GetPos();
            var_f1_2393 = 1.0f;
            if (arg1 < var_f1_2393) {
                var_f1_2393 = arg1;
            }
            sp1B8.GetPosition(var_f1_2393);
            sp58 = sp1B8.unk0 - sp1A8;
            sp1B8.unk10 = sp58;
            sp60 = sp1B8.unk8 - sp1B0;
            sp208 = sp58;
            sp1B8.unk18 = (f64) sp60;
            sp210 = (f64) sp60;
        } else {
            ((MKProp *) &sp178)->GetPos();
            var_f1_2430 = ((f32) var_r27_2382 * this->unk114) + arg0;
            if (var_f1_2430 < 1.0f) {

            } else {
                var_f1_2430 = 1.0f;
            }
            sp188.GetPosition(var_f1_2430);
            sp48 = sp188.unk0 - sp178;
            sp188.unk10 = sp48;
            sp50 = sp188.unk8 - sp180;
            sp208 = sp48;
            sp188.unk18 = (f64) sp50;
            sp210 = (f64) sp50;
        }
        ((KDSplinePathSegment *) &sp168)->GetVelocity((f32) var_r27_2382 * this->unk114);
        sp1B8.unk30.unk10 = sp168;
        temp_f1_2469 = M2C_BITWISE(f32, sp1B8.unk30.unk10);
        temp_f2_2470 = M2C_BITWISE(f32, sp1B8.unk44);
        sp200 = sp170;
        var_f4_2477 = ((f32) sp200 * (f32) sp200) + ((temp_f1_2469 * temp_f1_2469) + (temp_f2_2470 * temp_f2_2470));
        if (var_f4_2477 > 0.000001f) {
            if (var_f4_2477 > 0.0f) {
                temp_f1_2483 = __frsqrte(var_f4_2477);
                temp_f1_2489 = 0.5 * temp_f1_2483 * -(((f64) var_f4_2477 * (temp_f1_2483 * temp_f1_2483)) - 3.0);
                temp_f1_2493 = 0.5 * temp_f1_2489 * -(((f64) var_f4_2477 * (temp_f1_2489 * temp_f1_2489)) - 3.0);
                var_f4_2477 = (f32) ((f64) var_f4_2477 * (0.5 * temp_f1_2493 * -(((f64) var_f4_2477 * (temp_f1_2493 * temp_f1_2493)) - 3.0)));
            } else if (var_f4_2477 < M2C_BITWISE(f32, 0.0)) {
                var_f4_2477 = __float_nan;
            } else {
                sp14 = var_f4_2477;
                temp_r3_2512 = M2C_BITWISE(s32, sp14) & 0x7F800000;
                switch (temp_r3_2512) {             /* switch 1; irregular */
                case 0x7F800000:                    /* switch 1 */
                    if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                        var_r0_2522 = 1;
                    } else {
                        var_r0_2522 = 2;
                    }
                    break;
                case 0x0:                           /* switch 1 */
                    if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                        var_r0_2522 = 5;
                    } else {
                        var_r0_2522 = 3;
                    }
                    break;
                default:                            /* switch 1 */
                    var_r0_2522 = 4;
                    break;
                }
                if (var_r0_2522 == 1) {
                    var_f4_2477 = __float_nan;
                }
            }
            var_f2_2544 = 1.0f / var_f4_2477;
        } else {
            var_f2_2544 = 0.0f;
        }
        temp_f4_2551 = M2C_BITWISE(f32, sp1B8.unk44) * var_f2_2544;
        temp_f3_2553 = (f32) sp200 * var_f2_2544;
        temp_f5_2554 = M2C_BITWISE(f32, sp1B8.unk30.unk10) * var_f2_2544;
        sp1B8.unk44 = temp_f4_2551;
        sp1B8.unk30.unk10 = temp_f5_2554;
        sp200 = temp_f3_2553;
        sp38 = (temp_f22_2375 * temp_f3_2553) - (temp_f23_2377 * temp_f4_2551);
        sp3C = (temp_f23_2377 * temp_f5_2554) - (temp_f24_2379 * temp_f3_2553);
        sp40 = (temp_f24_2379 * temp_f4_2551) - (temp_f22_2375 * temp_f5_2554);
        sp1B8.unk30 = (f64) sp38;
        temp_f1_2570 = M2C_BITWISE(f32, sp1B8.unk30);
        temp_f0_2571 = M2C_BITWISE(f32, sp1B8.unk30.unk4);
        sp1B8.unk30.unk8 = (f64) sp40;
        sp158 = (f64) sp38;
        sp160 = (f64) sp40;
        var_f4_2580 = (sp1B8.unk30.unk8 * sp1B8.unk30.unk8) + ((temp_f1_2570 * temp_f1_2570) + (temp_f0_2571 * temp_f0_2571));
        if (var_f4_2580 > 0.000001f) {
            if (var_f4_2580 > 0.0f) {
                temp_f1_2586 = __frsqrte(var_f4_2580);
                temp_f1_2592 = 0.5 * temp_f1_2586 * -(((f64) var_f4_2580 * (temp_f1_2586 * temp_f1_2586)) - 3.0);
                temp_f1_2596 = 0.5 * temp_f1_2592 * -(((f64) var_f4_2580 * (temp_f1_2592 * temp_f1_2592)) - 3.0);
                var_f4_2580 = (f32) ((f64) var_f4_2580 * (0.5 * temp_f1_2596 * -(((f64) var_f4_2580 * (temp_f1_2596 * temp_f1_2596)) - 3.0)));
            } else if (var_f4_2580 < M2C_BITWISE(f32, 0.0)) {
                var_f4_2580 = __float_nan;
            } else {
                sp10 = var_f4_2580;
                temp_r3_2615 = M2C_BITWISE(s32, sp10) & 0x7F800000;
                switch (temp_r3_2615) {             /* switch 2; irregular */
                case 0x7F800000:                    /* switch 2 */
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_2625 = 1;
                    } else {
                        var_r0_2625 = 2;
                    }
                    break;
                case 0x0:                           /* switch 2 */
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_2625 = 5;
                    } else {
                        var_r0_2625 = 3;
                    }
                    break;
                default:                            /* switch 2 */
                    var_r0_2625 = 4;
                    break;
                }
                if (var_r0_2625 == 1) {
                    var_f4_2580 = __float_nan;
                }
            }
            var_f3_2647 = 1.0f / var_f4_2580;
        } else {
            var_f3_2647 = 0.0f;
        }
        sp1B8.unk30 = M2C_BITWISE(f32, sp1B8.unk30) * var_f3_2647;
        sp1B8.unk30.unk4 = M2C_BITWISE(f32, sp1B8.unk30.unk4) * var_f3_2647;
        sp1B8.unk30.unk8 *= var_f3_2647;
        KDRand_UnitVector();
        temp_f0_2665 = sp138 * 5.398241246e-315;
        sp28 = temp_f0_2665;
        sp148 = temp_f0_2665;
        sp30 = sp140 * 10.0f;
        sp150 = (f64) sp30;
        sp208 += temp_f0_2665;
        sp210 = (f32) sp210 + (f32) sp150;
        temp_f18_2697 = 4.0f * ((f32) var_r27_2382 / (f32) this->unk104);
        temp_f1_2698 = MKRand_Float(&gViewSeed, 0.8f, 1.0f);
        spA8 = 0.0f;
        spAC = 0.0f;
        spB0 = temp_f1_2698;
        spB4 = temp_f1_2698;
        sp128 = (f64) spA8;
        sp130 = (f64) spB0;
        MKSetColorV(*((MKVector4 *) &sp128));
        MKSetTexCoord1F(temp_f18_2697, 0.95f);
        temp_f0_2714 = (f64) sp1B8.unk30 * 5.45263811e-315;
        sp98 = temp_f0_2714;
        sp108 = temp_f0_2714;
        spA0 = sp1B8.unk30.unk8 * 25.0f;
        sp110 = (f64) spA0;
        temp_f0_2725 = sp208 + temp_f0_2714;
        sp88 = temp_f0_2725;
        sp118 = temp_f0_2725;
        sp90 = sp210 + (f32) sp110;
        sp120 = (f64) sp90;
        MKSetPositionV(*((MKVector3 *) &sp118));
        KDRand_UnitVector();
        temp_f0_2741 = spE8 * 5.439686476e-315;
        sp18 = temp_f0_2741;
        spF8 = temp_f0_2741;
        sp20 = spF0 * 20.0f;
        sp100 = (f64) sp20;
        sp208 += temp_f0_2741;
        sp210 += (f32) sp100;
        MKRand_Float(&gViewSeed, 0.0f, 30.000002f);
        MKSetColorV(*((MKVector4 *) &sp1B8.unk20));
        MKSetTexCoord1F(temp_f18_2697, 0.05f);
        temp_f1_2773 = (f32) var_r27_2382 * this->unk114;
        if (temp_f1_2773 > 0.6f) {
            var_f18_2777 = 1.5f - temp_f1_2773;
        } else if (temp_f1_2773 < 0.4f) {
            var_f18_2777 = 0.5f + temp_f1_2773;
        } else {
            var_f18_2777 = 0.9f;
        }
        temp_f1_2792 = MKRand_Float(&gViewSeed, -33.0f, 33.0f);
        sp80 = 0.0f;
        sp78 = 0.0f;
        sp7C = (this->unk10C * var_f18_2777) + temp_f1_2792;
        spD0 = (f64) sp80;
        spC8 = (f64) sp78;
        temp_f0_2804 = sp208 + spC8;
        sp68 = temp_f0_2804;
        spD8 = temp_f0_2804;
        sp70 = sp210 + (f32) spD0;
        spE0 = (f64) sp70;
        MKSetPositionV(*((MKVector3 *) &spD8));
        var_r27_2382 += 1;
        goto loop_61;
    }
    MKEnd();
    MKEndPrimitive();
}
#endif

#if 0 // DRAFT: function call 'memcpy(long, long, int)' does not match
void ElementalWall::DrawElectricityWall(float arg0, float arg1) {
    Matrix sp130;
    M2C_UNK sp12C;
    f32 sp128;
    f32 sp124;
    f32 sp120;
    f64 sp118;
    f64 sp110;
    f64 sp108;
    f64 sp100;
    f64 spF0;
    MKProp spA0;
    MKVector3 sp90;
    M2C_UNK sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp38;
    f64 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    f32 temp_f24_3063;
    f64 temp_f0_3002;
    s32 temp_r3_3095;
    s32 var_r30_2904;
    s32 var_r31_2925;

    M2C_STRUCT_COPY((s32) &sp12C + 4, (s32) &this->unk4C + 4, 0x40);
    sp120 = 1.0f;
    sp124 = 1.0f;
    sp128 = 1.0f;
    sp130.Scale3x3(&sp130, *((MKVector3 *) &sp120));
    var_r30_2904 = 0;
loop_9:
    if (var_r30_2904 < (s32) (this->unk108 + 1)) {
        MKMaterial_SetMaterial(this->unkF4);
        MKPrimitive(0xC, 0x10);
        MKSetMatrix(sp130);
        MKBegin((this->unk104 + 1) * 2);
        var_r31_2925 = 0;
loop_7:
        temp_r3_3095 = this->unk104;
        if (var_r31_2925 < (s32) (temp_r3_3095 + 1)) {
            if ((var_r31_2925 == 0) || (var_r31_2925 == temp_r3_3095)) {
                ((MKProp *) &spA0.unk40)->GetPos();
                ((KDSplinePathSegment *) &spF0)->GetPosition((f32) var_r31_2925 * this->unk114);
                sp30 = spF0 - M2C_BITWISE(f64, spA0.unk40);
                sp38 = spF8 - spA0.unk48;
                sp110 = sp30;
                sp118 = (f64) sp38;
                sp100 = sp30;
                sp108 = (f64) sp38;
                (*(f32 *) ((u8 *) &sp110 + 0x4)) += this->unk10C * ((f32) var_r30_2904 * this->unk118);
            } else {
                KDRand_UnitVector();
                sp90.operator*(20.0f);
                spA0.GetPos();
                ((KDSplinePathSegment *) &spA0.unk10)->GetPosition((f32) var_r31_2925 * this->unk114);
                temp_f0_3002 = spA0.unk10 - M2C_BITWISE(f64, spA0);
                sp10 = temp_f0_3002;
                spA0.unk20 = temp_f0_3002;
                sp18 = M2C_BITWISE(f32, spA0.unk18) - M2C_BITWISE(f32, spA0.unk8);
                spA0.unk28 = (f64) sp18;
                sp20 = (f64) spA0.unk20 + M2C_BITWISE(f64, sp90);
                sp110 = sp20;
                sp28 = M2C_BITWISE(f32, spA0.unk28) + sp90.unk8;
                sp118 = (f64) sp28;
                spA0.unk30 = sp20;
                spA0.unk38 = (f64) sp28;
                (*(f32 *) ((u8 *) &sp110 + 0x4)) += this->unk10C * ((f32) var_r30_2904 * this->unk118);
            }
            (*(f32 *) ((u8 *) &sp110 + 0x4)) += 20.0f;
            sp50 = 1.0f;
            sp54 = 0.0f;
            sp58 = 0.2f;
            sp5C = 1.0f;
            sp70 = (f64) sp50;
            temp_f24_3063 = 4.0f * ((f32) var_r31_2925 / (f32) this->unk104);
            sp78 = (f64) sp58;
            MKSetColorV(*((MKVector4 *) &sp70));
            MKSetTexCoord1F(temp_f24_3063, 0.95f);
            MKSetPositionV(*((MKVector3 *) &sp110));
            (*(f32 *) ((u8 *) &sp110 + 0x4)) += 10.0f;
            MKRand_Float(&gViewSeed, 0.0f, 30.000002f);
            sp40 = 1.0f;
            sp44 = 0.0f;
            sp48 = 0.2f;
            sp4C = 1.0f;
            sp60 = (f64) sp40;
            sp68 = (f64) sp48;
            MKSetColorV(*((MKVector4 *) &sp60));
            MKSetTexCoord1F(temp_f24_3063, 0.05f);
            MKSetPositionV(*((MKVector3 *) &sp110));
            var_r31_2925 += 1;
            goto loop_7;
        }
        MKEnd();
        MKEndPrimitive();
        var_r30_2904 += 1;
        goto loop_9;
    }
}
#endif

#if 0 // DRAFT: function call 'memcpy(long, long, int)' does not match
void ElementalWall::DrawFireWall(float arg0, float arg1) {
    Matrix sp3E0;
    M2C_UNK sp3DC;
    f32 sp3D8;
    f32 sp3D4;
    f32 sp3D0;
    f64 sp3C8;                                      /* compiler-managed */
    f64 sp3C0;
    f64 sp3B8;                                      /* compiler-managed */
    f64 sp398;
    f64 sp390;                                      /* compiler-managed */
    KDSplinePathSegment sp370;
    f64 sp360;
    KDSplinePathSegment sp340;
    f64 sp330;
    f64 sp320;
    f64 sp318;
    f64 sp310;
    f64 sp308;
    f64 sp300;
    f64 sp2F0;
    f64 sp2E8;
    f64 sp2E0;
    f64 sp2D8;
    f64 sp2D0;
    f64 sp2C8;
    f64 sp2C0;
    f64 sp2B8;
    f64 sp2B0;
    f64 sp2A0;
    f64 sp298;                                      /* compiler-managed */
    f64 sp290;                                      /* compiler-managed */
    f64 sp288;
    f64 sp280;                                      /* compiler-managed */
    KDSplinePathSegment sp260;
    f64 sp250;
    KDSplinePathSegment sp230;
    f64 sp220;
    f64 sp218;
    f64 sp210;
    f64 sp200;
    f64 sp1F0;
    f64 sp1E8;
    f64 sp1E0;
    f64 sp1D8;
    f64 sp1D0;
    f64 sp1C8;
    f64 sp1C0;
    f64 sp1B8;
    f64 sp1B0;
    f64 sp1A8;
    f64 sp1A0;
    f64 sp190;
    f64 sp188;
    f64 sp180;
    f64 sp178;
    f64 sp170;
    f32 sp16C;
    f32 sp168;
    f32 sp164;
    f32 sp160;
    f32 sp15C;
    f32 sp158;
    f32 sp154;
    f32 sp150;
    f32 sp148;
    f64 sp140;
    f32 sp138;
    f64 sp130;
    f32 sp128;
    f32 sp124;
    f32 sp120;
    f32 sp118;
    f64 sp110;
    f32 sp10C;
    f32 sp108;
    f32 sp104;
    f32 sp100;
    f32 spF8;
    f64 spF0;
    f32 spE8;
    f64 spE0;
    f32 spD8;
    f32 spD4;
    f32 spD0;
    f32 spC8;
    f64 spC0;
    f32 spB8;
    f64 spB0;
    f32 spA8;
    f64 spA0;
    f32 sp98;
    f32 sp94;
    f32 sp90;
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
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 temp_f0_3443;
    f32 temp_f0_3923;
    f32 temp_f15_3569;
    f32 temp_f16_4028;
    f32 temp_f19_3251;
    f32 temp_f1_3341;
    f32 temp_f1_3442;
    f32 temp_f1_3570;
    f32 temp_f1_3645;
    f32 temp_f1_3664;
    f32 temp_f1_4029;
    f32 temp_f1_4100;
    f32 temp_f1_4119;
    f32 temp_f20_3711;
    f32 temp_f21_3709;
    f32 temp_f22_3247;
    f32 temp_f22_3707;
    f32 temp_f23_3249;
    f32 temp_f2_3342;
    f32 temp_f2_3822;
    f32 temp_f3_3425;
    f32 temp_f3_3905;
    f32 temp_f4_3423;
    f32 temp_f4_3903;
    f32 temp_f5_3426;
    f32 temp_f5_3906;
    f32 var_f15_3649;
    f32 var_f15_4104;
    f32 var_f1_3265;
    f32 var_f1_3302;
    f32 var_f1_3724;
    f32 var_f1_3761;
    f32 var_f2_3205;
    f32 var_f2_3416;
    f32 var_f2_3896;
    f32 var_f2_3999;
    f32 var_f3_3519;
    f32 var_f4_3349;
    f32 var_f4_3452;
    f32 var_f4_3829;
    f32 var_f4_3932;
    f64 temp_f0_3537;
    f64 temp_f0_3586;
    f64 temp_f0_3597;
    f64 temp_f0_3613;
    f64 temp_f0_3676;
    f64 temp_f0_3791;
    f64 temp_f0_4045;
    f64 temp_f0_4056;
    f64 temp_f0_4072;
    f64 temp_f0_4131;
    f64 temp_f1_3355;
    f64 temp_f1_3361;
    f64 temp_f1_3365;
    f64 temp_f1_3458;
    f64 temp_f1_3464;
    f64 temp_f1_3468;
    f64 temp_f1_3835;
    f64 temp_f1_3841;
    f64 temp_f1_3845;
    f64 temp_f1_3938;
    f64 temp_f1_3944;
    f64 temp_f1_3948;
    s32 temp_r0_3223;
    s32 temp_r26_3240;
    s32 temp_r3_3384;
    s32 temp_r3_3487;
    s32 temp_r3_3864;
    s32 temp_r3_3967;
    s32 var_r0_3394;
    s32 var_r0_3497;
    s32 var_r0_3874;
    s32 var_r0_3977;
    s32 var_r25_3254;
    s32 var_r26_3712;
    s32 var_r27_3211;
    s32 var_r4_3217;

    M2C_STRUCT_COPY((s32) &sp3DC + 4, (s32) &this->unk4C + 4, 0x40);
    sp160 = 0.0f;
    sp164 = 0.0f;
    sp168 = 0.0f;
    sp16C = 0.0f;
    sp390 = (f64) sp160;
    sp398 = (f64) sp168;
    sp3D0 = 1.0f;
    sp3D4 = 1.0f;
    sp3D8 = 1.0f;
    sp3E0.Scale3x3(&sp3E0, *((MKVector3 *) &sp3D0));
    var_f2_3205 = arg1 - arg0;
    if (var_f2_3205 < 0.0f) {
        var_f2_3205 = -var_f2_3205;
    }
    var_r27_3211 = this->unk104;
    var_r4_3217 = lit_775;
    temp_r0_3223 = (s32) ((f32) var_r27_3211 * var_f2_3205);
    if (temp_r0_3223 > var_r4_3217) {
        var_r4_3217 = temp_r0_3223;
    }
    if (var_r4_3217 < var_r27_3211) {
        var_r27_3211 = var_r4_3217;
    }
    MKMaterial_SetMaterial(this->unkF4);
    MKPrimitive(0xC, 0x10);
    MKSetMatrix(sp3E0);
    temp_r26_3240 = (var_r27_3211 + 1) * 2;
    MKBegin(temp_r26_3240);
    temp_f22_3247 = MKVector3::up.unk4;
    temp_f23_3249 = MKVector3::up.unk8;
    temp_f19_3251 = MKVector3::up.unk0;
    var_r25_3254 = 0;
loop_61:
    if (var_r25_3254 < (s32) (var_r27_3211 + 1)) {
        if (var_r25_3254 == var_r27_3211) {
            ((MKProp *) &sp360)->GetPos();
            var_f1_3265 = 1.0f;
            if (arg1 < var_f1_3265) {
                var_f1_3265 = arg1;
            }
            sp370.GetPosition(var_f1_3265);
            spB0 = sp370.unk0 - sp360;
            sp370.unk10 = spB0;
            spB8 = sp370.unk8 - sp368;
            sp3C0 = spB0;
            sp370.unk18 = (f64) spB8;
            sp3C8 = (f64) spB8;
        } else {
            ((MKProp *) &sp330)->GetPos();
            var_f1_3302 = ((f32) var_r25_3254 * this->unk114) + arg0;
            if (var_f1_3302 < 1.0f) {

            } else {
                var_f1_3302 = 1.0f;
            }
            sp340.GetPosition(var_f1_3302);
            spA0 = sp340.unk0 - sp330;
            sp340.unk10 = spA0;
            spA8 = sp340.unk8 - sp338;
            sp3C0 = spA0;
            sp340.unk18 = (f64) spA8;
            sp3C8 = (f64) spA8;
        }
        ((KDSplinePathSegment *) &sp320)->GetVelocity((f32) var_r25_3254 * this->unk114);
        sp370.unk30.unk10 = sp320;
        temp_f1_3341 = M2C_BITWISE(f32, sp370.unk30.unk10);
        temp_f2_3342 = M2C_BITWISE(f32, sp370.unk44);
        sp3B8 = sp328;
        var_f4_3349 = ((f32) sp3B8 * (f32) sp3B8) + ((temp_f1_3341 * temp_f1_3341) + (temp_f2_3342 * temp_f2_3342));
        if (var_f4_3349 > 0.000001f) {
            if (var_f4_3349 > 0.0f) {
                temp_f1_3355 = __frsqrte(var_f4_3349);
                temp_f1_3361 = 0.5 * temp_f1_3355 * -(((f64) var_f4_3349 * (temp_f1_3355 * temp_f1_3355)) - 3.0);
                temp_f1_3365 = 0.5 * temp_f1_3361 * -(((f64) var_f4_3349 * (temp_f1_3361 * temp_f1_3361)) - 3.0);
                var_f4_3349 = (f32) ((f64) var_f4_3349 * (0.5 * temp_f1_3365 * -(((f64) var_f4_3349 * (temp_f1_3365 * temp_f1_3365)) - 3.0)));
            } else if (var_f4_3349 < M2C_BITWISE(f32, 0.0)) {
                var_f4_3349 = __float_nan;
            } else {
                sp1C = var_f4_3349;
                temp_r3_3384 = M2C_BITWISE(s32, sp1C) & 0x7F800000;
                switch (temp_r3_3384) {             /* switch 1; irregular */
                case 0x7F800000:                    /* switch 1 */
                    if (M2C_BITWISE(s32, sp1C) & 0x7FFFFF) {
                        var_r0_3394 = 1;
                    } else {
                        var_r0_3394 = 2;
                    }
                    break;
                case 0x0:                           /* switch 1 */
                    if (M2C_BITWISE(s32, sp1C) & 0x7FFFFF) {
                        var_r0_3394 = 5;
                    } else {
                        var_r0_3394 = 3;
                    }
                    break;
                default:                            /* switch 1 */
                    var_r0_3394 = 4;
                    break;
                }
                if (var_r0_3394 == 1) {
                    var_f4_3349 = __float_nan;
                }
            }
            var_f2_3416 = 1.0f / var_f4_3349;
        } else {
            var_f2_3416 = 0.0f;
        }
        temp_f4_3423 = M2C_BITWISE(f32, sp370.unk44) * var_f2_3416;
        temp_f3_3425 = (f32) sp3B8 * var_f2_3416;
        temp_f5_3426 = M2C_BITWISE(f32, sp370.unk30.unk10) * var_f2_3416;
        sp370.unk44 = temp_f4_3423;
        sp370.unk30.unk10 = temp_f5_3426;
        sp3B8 = temp_f3_3425;
        sp90 = (temp_f22_3247 * temp_f3_3425) - (temp_f23_3249 * temp_f4_3423);
        sp94 = (temp_f23_3249 * temp_f5_3426) - (temp_f19_3251 * temp_f3_3425);
        sp98 = (temp_f19_3251 * temp_f4_3423) - (temp_f22_3247 * temp_f5_3426);
        sp370.unk30 = (f64) sp90;
        temp_f1_3442 = M2C_BITWISE(f32, sp370.unk30);
        temp_f0_3443 = M2C_BITWISE(f32, sp370.unk30.unk4);
        sp370.unk30.unk8 = (f64) sp98;
        sp310 = (f64) sp90;
        sp318 = (f64) sp98;
        var_f4_3452 = (sp370.unk30.unk8 * sp370.unk30.unk8) + ((temp_f1_3442 * temp_f1_3442) + (temp_f0_3443 * temp_f0_3443));
        if (var_f4_3452 > 0.000001f) {
            if (var_f4_3452 > 0.0f) {
                temp_f1_3458 = __frsqrte(var_f4_3452);
                temp_f1_3464 = 0.5 * temp_f1_3458 * -(((f64) var_f4_3452 * (temp_f1_3458 * temp_f1_3458)) - 3.0);
                temp_f1_3468 = 0.5 * temp_f1_3464 * -(((f64) var_f4_3452 * (temp_f1_3464 * temp_f1_3464)) - 3.0);
                var_f4_3452 = (f32) ((f64) var_f4_3452 * (0.5 * temp_f1_3468 * -(((f64) var_f4_3452 * (temp_f1_3468 * temp_f1_3468)) - 3.0)));
            } else if (var_f4_3452 < M2C_BITWISE(f32, 0.0)) {
                var_f4_3452 = __float_nan;
            } else {
                sp18 = var_f4_3452;
                temp_r3_3487 = M2C_BITWISE(s32, sp18) & 0x7F800000;
                switch (temp_r3_3487) {             /* switch 2; irregular */
                case 0x7F800000:                    /* switch 2 */
                    if (M2C_BITWISE(s32, sp18) & 0x7FFFFF) {
                        var_r0_3497 = 1;
                    } else {
                        var_r0_3497 = 2;
                    }
                    break;
                case 0x0:                           /* switch 2 */
                    if (M2C_BITWISE(s32, sp18) & 0x7FFFFF) {
                        var_r0_3497 = 5;
                    } else {
                        var_r0_3497 = 3;
                    }
                    break;
                default:                            /* switch 2 */
                    var_r0_3497 = 4;
                    break;
                }
                if (var_r0_3497 == 1) {
                    var_f4_3452 = __float_nan;
                }
            }
            var_f3_3519 = 1.0f / var_f4_3452;
        } else {
            var_f3_3519 = 0.0f;
        }
        sp370.unk30 = M2C_BITWISE(f32, sp370.unk30) * var_f3_3519;
        sp370.unk30.unk4 = M2C_BITWISE(f32, sp370.unk30.unk4) * var_f3_3519;
        sp370.unk30.unk8 *= var_f3_3519;
        KDRand_UnitVector();
        temp_f0_3537 = sp2F0 * 5.398241246e-315;
        sp80 = temp_f0_3537;
        sp300 = temp_f0_3537;
        sp88 = sp2F8 * 10.0f;
        sp308 = (f64) sp88;
        sp3C0 += temp_f0_3537;
        sp3C8 = (f32) sp3C8 + (f32) sp308;
        temp_f15_3569 = 4.0f * ((f32) var_r25_3254 / (f32) this->unk104);
        temp_f1_3570 = MKRand_Float(&gViewSeed, 0.8f, 1.0f);
        sp150 = temp_f1_3570;
        sp154 = temp_f1_3570;
        sp158 = temp_f1_3570;
        sp15C = temp_f1_3570;
        sp2E0 = (f64) sp150;
        sp2E8 = (f64) sp158;
        MKSetColorV(*((MKVector4 *) &sp2E0));
        MKSetTexCoord1F(temp_f15_3569, 0.95f);
        temp_f0_3586 = (f64) sp370.unk30 * 5.45263811e-315;
        sp140 = temp_f0_3586;
        sp2C0 = temp_f0_3586;
        sp148 = sp370.unk30.unk8 * 25.0f;
        sp2C8 = (f64) sp148;
        temp_f0_3597 = sp3C0 + temp_f0_3586;
        sp130 = temp_f0_3597;
        sp2D0 = temp_f0_3597;
        sp138 = sp3C8 + (f32) sp2C8;
        sp2D8 = (f64) sp138;
        MKSetPositionV(*((MKVector3 *) &sp2D0));
        KDRand_UnitVector();
        temp_f0_3613 = sp2A0 * 5.439686476e-315;
        sp70 = temp_f0_3613;
        sp2B0 = temp_f0_3613;
        sp78 = sp2A8 * 20.0f;
        sp2B8 = (f64) sp78;
        sp3C0 += temp_f0_3613;
        sp3C8 += (f32) sp2B8;
        MKRand_Float(&gViewSeed, 0.0f, 30.000002f);
        MKSetColorV(*((MKVector4 *) &sp370.unk20));
        MKSetTexCoord1F(temp_f15_3569, 0.05f);
        temp_f1_3645 = (f32) var_r25_3254 * this->unk114;
        if (temp_f1_3645 > 0.6f) {
            var_f15_3649 = 1.5f - temp_f1_3645;
        } else if (temp_f1_3645 < 0.4f) {
            var_f15_3649 = 0.5f + temp_f1_3645;
        } else {
            var_f15_3649 = 0.9f;
        }
        temp_f1_3664 = MKRand_Float(&gViewSeed, -33.0f, 33.0f);
        sp128 = 0.0f;
        sp120 = 0.0f;
        sp124 = (this->unk10C * var_f15_3649) + temp_f1_3664;
        sp288 = (f64) sp128;
        sp280 = (f64) sp120;
        temp_f0_3676 = sp3C0 + sp280;
        sp110 = temp_f0_3676;
        sp290 = temp_f0_3676;
        sp118 = sp3C8 + (f32) sp288;
        sp298 = (f64) sp118;
        MKSetPositionV(*((MKVector3 *) &sp290));
        var_r25_3254 += 1;
        goto loop_61;
    }
    MKEnd();
    MKEndPrimitive();
    MKMaterial_SetMaterial(this->unkF8);
    MKPrimitive(0xC, 0x10);
    MKSetMatrix(sp3E0);
    MKBegin(temp_r26_3240);
    temp_f22_3707 = MKVector3::up.unk4;
    temp_f21_3709 = MKVector3::up.unk8;
    temp_f20_3711 = MKVector3::up.unk0;
    var_r26_3712 = 0;
loop_117:
    if (var_r26_3712 < (s32) (var_r27_3211 + 1)) {
        if (var_r26_3712 == var_r27_3211) {
            ((MKProp *) &sp250)->GetPos();
            var_f1_3724 = 1.0f;
            if (arg1 < var_f1_3724) {
                var_f1_3724 = arg1;
            }
            sp260.GetPosition(var_f1_3724);
            sp60 = sp260.unk0 - sp250;
            sp260.unk10 = sp60;
            sp68 = sp260.unk8 - sp258;
            sp3C0 = sp60;
            sp260.unk18 = (f64) sp68;
            sp3C8 = (f64) sp68;
        } else {
            ((MKProp *) &sp220)->GetPos();
            var_f1_3761 = ((f32) var_r26_3712 * this->unk114) + arg0;
            if (var_f1_3761 < 1.0f) {

            } else {
                var_f1_3761 = 1.0f;
            }
            sp230.GetPosition(var_f1_3761);
            sp50 = sp230.unk0 - sp220;
            sp230.unk10 = sp50;
            sp58 = sp230.unk8 - sp228;
            sp3C0 = sp50;
            sp230.unk18 = (f64) sp58;
            sp3C8 = (f64) sp58;
        }
        KDRand_UnitVector();
        temp_f0_3791 = sp200 * 5.398241246e-315;
        sp40 = temp_f0_3791;
        sp210 = temp_f0_3791;
        sp48 = sp208 * 10.0f;
        sp218 = (f64) sp48;
        sp3C0 += temp_f0_3791;
        sp3C8 = (f32) sp3C8 + (f32) sp218;
        ((KDSplinePathSegment *) &sp1F0)->GetVelocity((f32) var_r26_3712 * this->unk114);
        sp370.unk30.unk10 = sp1F0;
        temp_f2_3822 = M2C_BITWISE(f32, sp370.unk44);
        sp3B8 = sp1F8;
        var_f4_3829 = ((f32) sp3B8 * (f32) sp3B8) + (((f32) sp370.unk30.unk10 * (f32) sp370.unk30.unk10) + (temp_f2_3822 * temp_f2_3822));
        if (var_f4_3829 > 0.000001f) {
            if (var_f4_3829 > 0.0f) {
                temp_f1_3835 = __frsqrte(var_f4_3829);
                temp_f1_3841 = 0.5 * temp_f1_3835 * -(((f64) var_f4_3829 * (temp_f1_3835 * temp_f1_3835)) - 3.0);
                temp_f1_3845 = 0.5 * temp_f1_3841 * -(((f64) var_f4_3829 * (temp_f1_3841 * temp_f1_3841)) - 3.0);
                var_f4_3829 = (f32) ((f64) var_f4_3829 * (0.5 * temp_f1_3845 * -(((f64) var_f4_3829 * (temp_f1_3845 * temp_f1_3845)) - 3.0)));
            } else if (var_f4_3829 < M2C_BITWISE(f32, 0.0)) {
                var_f4_3829 = __float_nan;
            } else {
                sp14 = var_f4_3829;
                temp_r3_3864 = M2C_BITWISE(s32, sp14) & 0x7F800000;
                switch (temp_r3_3864) {             /* switch 3; irregular */
                case 0x7F800000:                    /* switch 3 */
                    if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                        var_r0_3874 = 1;
                    } else {
                        var_r0_3874 = 2;
                    }
                    break;
                case 0x0:                           /* switch 3 */
                    if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                        var_r0_3874 = 5;
                    } else {
                        var_r0_3874 = 3;
                    }
                    break;
                default:                            /* switch 3 */
                    var_r0_3874 = 4;
                    break;
                }
                if (var_r0_3874 == 1) {
                    var_f4_3829 = __float_nan;
                }
            }
            var_f2_3896 = 1.0f / var_f4_3829;
        } else {
            var_f2_3896 = 0.0f;
        }
        temp_f4_3903 = M2C_BITWISE(f32, sp370.unk44) * var_f2_3896;
        temp_f3_3905 = (f32) sp3B8 * var_f2_3896;
        temp_f5_3906 = (f32) sp370.unk30.unk10 * var_f2_3896;
        sp370.unk44 = temp_f4_3903;
        sp370.unk30.unk10 = temp_f5_3906;
        sp3B8 = temp_f3_3905;
        sp30 = (temp_f22_3707 * temp_f3_3905) - (temp_f21_3709 * temp_f4_3903);
        sp34 = (temp_f21_3709 * temp_f5_3906) - (temp_f20_3711 * temp_f3_3905);
        sp38 = (temp_f20_3711 * temp_f4_3903) - (temp_f22_3707 * temp_f5_3906);
        sp370.unk30 = (f64) sp30;
        temp_f0_3923 = M2C_BITWISE(f32, sp370.unk30.unk4);
        sp370.unk30.unk8 = (f64) sp38;
        sp1E0 = (f64) sp30;
        sp1E8 = (f64) sp38;
        var_f4_3932 = ((f32) sp370.unk30.unk8 * (f32) sp370.unk30.unk8) + (((f32) sp370.unk30 * (f32) sp370.unk30) + (temp_f0_3923 * temp_f0_3923));
        if (var_f4_3932 > 0.000001f) {
            if (var_f4_3932 > 0.0f) {
                temp_f1_3938 = __frsqrte(var_f4_3932);
                temp_f1_3944 = 0.5 * temp_f1_3938 * -(((f64) var_f4_3932 * (temp_f1_3938 * temp_f1_3938)) - 3.0);
                temp_f1_3948 = 0.5 * temp_f1_3944 * -(((f64) var_f4_3932 * (temp_f1_3944 * temp_f1_3944)) - 3.0);
                var_f4_3932 = (f32) ((f64) var_f4_3932 * (0.5 * temp_f1_3948 * -(((f64) var_f4_3932 * (temp_f1_3948 * temp_f1_3948)) - 3.0)));
            } else if (var_f4_3932 < M2C_BITWISE(f32, 0.0)) {
                var_f4_3932 = __float_nan;
            } else {
                sp10 = var_f4_3932;
                temp_r3_3967 = M2C_BITWISE(s32, sp10) & 0x7F800000;
                switch (temp_r3_3967) {             /* switch 4; irregular */
                case 0x7F800000:                    /* switch 4 */
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_3977 = 1;
                    } else {
                        var_r0_3977 = 2;
                    }
                    break;
                case 0x0:                           /* switch 4 */
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_3977 = 5;
                    } else {
                        var_r0_3977 = 3;
                    }
                    break;
                default:                            /* switch 4 */
                    var_r0_3977 = 4;
                    break;
                }
                if (var_r0_3977 == 1) {
                    var_f4_3932 = __float_nan;
                }
            }
            var_f2_3999 = 1.0f / var_f4_3932;
        } else {
            var_f2_3999 = 0.0f;
        }
        sp370.unk30 = (f32) sp370.unk30 * var_f2_3999;
        sp370.unk30.unk4 = M2C_BITWISE(f32, sp370.unk30.unk4) * var_f2_3999;
        sp370.unk30.unk8 = (f32) sp370.unk30.unk8 * var_f2_3999;
        temp_f16_4028 = 4.0f * ((f32) var_r26_3712 / (f32) this->unk104);
        temp_f1_4029 = MKRand_Float(&gViewSeed, 0.8f, 1.0f);
        sp100 = temp_f1_4029;
        sp104 = temp_f1_4029;
        sp108 = temp_f1_4029;
        sp10C = temp_f1_4029;
        sp1D0 = (f64) sp100;
        sp1D8 = (f64) sp108;
        MKSetColorV(*((MKVector4 *) &sp1D0));
        MKSetTexCoord1F(temp_f16_4028, 0.95f);
        temp_f0_4045 = (f64) sp370.unk30 * 5.45263811e-315;
        spF0 = temp_f0_4045;
        sp1B0 = temp_f0_4045;
        spF8 = sp370.unk30.unk8 * 25.0f;
        sp1B8 = (f64) spF8;
        temp_f0_4056 = sp3C0 - temp_f0_4045;
        spE0 = temp_f0_4056;
        sp1C0 = temp_f0_4056;
        spE8 = sp3C8 - (f32) sp1B8;
        sp1C8 = (f64) spE8;
        MKSetPositionV(*((MKVector3 *) &sp1C0));
        KDRand_UnitVector();
        temp_f0_4072 = sp190 * 5.439686476e-315;
        sp20 = temp_f0_4072;
        sp1A0 = temp_f0_4072;
        sp28 = sp198 * 20.0f;
        sp1A8 = (f64) sp28;
        sp3C0 += temp_f0_4072;
        sp3C8 += (f32) sp1A8;
        MKSetColorV(*((MKVector4 *) &sp370.unk20));
        MKSetTexCoord1F(temp_f16_4028, 0.05f);
        temp_f1_4100 = (f32) var_r26_3712 * this->unk114;
        if (temp_f1_4100 > 0.6f) {
            var_f15_4104 = 1.5f - temp_f1_4100;
        } else if (temp_f1_4100 < 0.4f) {
            var_f15_4104 = 0.5f + temp_f1_4100;
        } else {
            var_f15_4104 = 0.9f;
        }
        temp_f1_4119 = MKRand_Float(&gViewSeed, -33.0f, 33.0f);
        spD8 = 0.0f;
        spD0 = 0.0f;
        spD4 = (this->unk10C * var_f15_4104) + temp_f1_4119;
        sp178 = (f64) spD8;
        sp170 = (f64) spD0;
        temp_f0_4131 = sp3C0 + sp170;
        spC0 = temp_f0_4131;
        sp180 = temp_f0_4131;
        spC8 = sp3C8 + (f32) sp178;
        sp188 = (f64) spC8;
        MKSetPositionV(*((MKVector3 *) &sp180));
        var_r26_3712 += 1;
        goto loop_117;
    }
    MKEnd();
    MKEndPrimitive();
}
#endif

#if 0 // DRAFT: undefined identifier 'KDStateMachine'
void ElementalWall::Draw() {
    f32 var_f30_4209;
    f32 var_f31_4207;
    s32 temp_r0_4236;

    if (((KDStateMachine<ElementalWall> *) &this->unkE0)->GetState() != 3) {
        var_f31_4207 = 0.0f;
        var_f30_4209 = 0.0f;
        if (((KDStateMachine<ElementalWall> *) &this->unkE0)->GetState() == 1) {
            var_f31_4207 = 0.0f;
            var_f30_4209 = 1.0f;
        } else if (((KDStateMachine<ElementalWall> *) &this->unkE0)->GetState() == 0) {
            var_f31_4207 = 0.0f;
            var_f30_4209 = this->unk124 / this->unk120;
        } else if (((KDStateMachine<ElementalWall> *) &this->unkE0)->GetState() == 2) {
            var_f30_4209 = 1.0f;
            var_f31_4207 = this->unk124 / this->unk120;
        }
        temp_r0_4236 = this->unk100;
        switch (temp_r0_4236) {                     /* irregular */
        case 0:
            DrawFireWall(var_f31_4207, var_f30_4209);
            return;
        case 1:
            DrawElectricityWall(var_f31_4207, var_f30_4209);
            return;
        case 2:
            DrawIceWall(var_f31_4207, var_f30_4209);
            return;
        case 3:
            DrawEarthWall(var_f31_4207, var_f30_4209);
            break;
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'KDStateMachine'
void ElementalWall::Update() {
    u8 var_r30_4297;
    u8 var_r31_4295;

    ((KDStateMachine<ElementalWall> *) &this->unkE0)->Update(this, 0);
    var_r31_4295 = 1;
    var_r30_4297 = 1;
    if ((((KDStateMachine<ElementalWall> *) &this->unkE0)->GetState() != 1) && (((KDStateMachine<ElementalWall> *) &this->unkE0)->GetState() != 0)) {
        var_r30_4297 = 0;
    }
    if ((var_r30_4297 == 0) && (((KDStateMachine<ElementalWall> *) &this->unkE0)->GetState() != 2)) {
        var_r31_4295 = 0;
    }
    ((KDSound_SoundWall *) &this->unk130)->Update(var_r31_4295);
}
#endif

#if 0 // DRAFT: undefined identifier 'KDStateMachine'
void ElementalWall::Message(MKMessage *arg0) {
    s32 temp_r0_4336;
    s32 temp_r0_4372;
    void *temp_r3_4369;

    ((KDSound_SoundWall *) &this->unk130)->Message(arg0);
    temp_r0_4336 = arg0->unk0;
    switch (temp_r0_4336) {                         /* switch 1; irregular */
    case 0xB5:                                      /* switch 1 */
        if (((KDStateMachine<ElementalWall> *) &this->unkE0)->GetState() == 3) {
            ((KDStateMachine<ElementalWall> *) &this->unkE0)->SetState(this, 0, 0U);
        }
        break;
    case 0xB4:                                      /* switch 1 */
        if (((KDStateMachine<ElementalWall> *) &this->unkE0)->GetState() == 1) {
            ((KDStateMachine<ElementalWall> *) &this->unkE0)->SetState(this, 2, 0U);
        }
        break;
    case 0x16:                                      /* switch 1 */
        temp_r3_4369 = checked_cast<HitHeroSndMsg *, MKMessage>(arg0);
        M2C_FIELD(temp_r3_4369, s32 *, 8) = 0;
        temp_r0_4372 = this->unk100;
        switch (temp_r0_4372) {                     /* switch 2; irregular */
        case 0:                                     /* switch 2 */
            M2C_FIELD(temp_r3_4369, s32 *, 8) = (s32) GS_SpyroLavaBurn;
            break;
        case 1:                                     /* switch 2 */
            M2C_FIELD(temp_r3_4369, s32 *, 8) = (s32) GS_SpyroZapBurn;
            break;
        case 2:                                     /* switch 2 */
            M2C_FIELD(temp_r3_4369, s32 *, 8) = (s32) GS_SpyroIceBurn;
            break;
        case 3:                                     /* switch 2 */
            M2C_FIELD(temp_r3_4369, s32 *, 8) = (s32) GS_SpyroEarthBurn;
            break;
        }
        break;
    }
    MKProp::Message(arg0);
}
#endif

#if 0 // DRAFT: undefined identifier 'KDStateMachine'
void ElementalWall::Resolve() {
    s32 temp_r0_4423;

    ((KDStateMachine<ElementalWall> *) &this->unkE0)->SetState(this, 3, 0U);
    temp_r0_4423 = this->unk100;
    switch (temp_r0_4423) {                         /* irregular */
    case 0:
        this->unkF4 = MKMaterial_Create"FX_ElementalFlameWall";
        this->unkF8 = MKMaterial_Create"FX_ElementalFlameWall1";
        ((KDSound_SoundWall *) &this->unk130)->Init(&this->unkB0->unk30, this->unk110, GS_FireBarricadeLP, GS_FireBarricadeStart, GS_FireBarricadeStop, 0.25f, 0.25f, 0.0f, 0.0f);
        break;
    case 1:
        this->unkF4 = MKMaterial_Create"FX_ElementalElectricityWall";
        ((KDSound_SoundWall *) &this->unk130)->Init(&this->unkB0->unk30, this->unk110, GS_ElecBarricadeLP, GS_ElecBarricadeStart, GS_ElecBarricadeStop, 0.25f, 0.25f, 0.0f, 0.0f);
        break;
    case 2:
        this->unkF4 = MKMaterial_Create"FX_ElementalIceWall";
        ((KDSound_SoundWall *) &this->unk130)->Init(&this->unkB0->unk30, this->unk110, GS_IceBarricadeLP, GS_IceBarricadeStart, GS_IceBarricadeStop, 0.25f, 0.25f, 0.0f, 0.0f);
        break;
    case 3:
        this->unkF4 = MKMaterial_Create"FX_ElementalEarthWall";
        ((KDSound_SoundWall *) &this->unk130)->Init(&this->unkB0->unk30, this->unk110, GS_EarthBarricadeLP, GS_EarthBarricadeStart, GS_EarthBarricadeStop, 0.25f, 0.25f, 0.0f, 0.0f);
        break;
    }
    this->unk114 = 1.0f / (f32) this->unk104;
    this->unk118 = 1.0f / (f32) this->unk108;
    MKProp::Resolve();
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long *' to
s32 ElementalWall::LoadLine(MKIniLine *arg0) {
    if (SplineProp::LoadLine(arg0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("Element", &this->unk100, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadBool("InfiniteCollision", &this->unk11C, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadFloat("Height", &this->unk10C, 0) != 0) {
        this->unk110 = 100.0f * this->unk10C;
        this->unk10C = 0.0f;
        return 1U;
    }
    if (arg0->LoadInt("HSubDivisions", &this->unk104, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("VSubDivisions", &this->unk108, 0) != 0) {
        return 1U;
    }
    return (u8) (arg0->LoadFloat("IgniteTime", &this->unk120, 0) != 0);
}
#endif

#if 0 // DRAFT: undefined identifier 'KDStateMachine'
void ElementalWall::Deinit() {
    MKMaterial *temp_r3_4657;
    MKMaterial *temp_r3_4662;

    ((KDStateMachine<ElementalWall> *) &this->unkE0)->Deinit(this);
    ((KDSound_SoundWall *) &this->unk130)->Deinit();
    temp_r3_4657 = this->unkF4;
    if (temp_r3_4657 != NULL) {
        MKMaterial_Destroy(temp_r3_4657);
    }
    temp_r3_4662 = this->unkF8;
    if (temp_r3_4662 != NULL) {
        MKMaterial_Destroy(temp_r3_4662);
    }
    SplineProp::Deinit();
}
#endif

#if 0 // DRAFT: undefined identifier 'Init__31KDStateMachine'
void ElementalWall::Init() {
    Init__31KDStateMachine<13ElementalWall>FPQ231KDStateMachine<13ElementalWall>5StateP31KDStateMachine<13ElementalWall>((KDStateMachine<ElementalWall> *) &this->unkE0, &ElementalWallStates, NULL);
    this->unkF4 = NULL;
    this->unkF8 = NULL;
    this->unk104 = 1;
    this->unk108 = 1;
    this->unk120 = 1.0f;
    this->unk124 = 0.0f;
    this->unk11C = 0;
    this->unk128 = 0;
    this->unk10C = 0.0f;
    this->unk110 = 200.0f;
    SplineProp::Init();
    this->unkFC = gb.unk30C + 0.0f;
    this->unkC0 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    this->unkC8 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
    this->unkD0 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    this->unkD8 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'FallingLeaves *' to
void ElementalWallDescriptor::LoadDone() {
    MKPropDescriptor::LoadDone();
    this->unk60 = checked_cast<FallingLeaves *, MKProp>(((MKSceneManager *) gMK)->CreateProp("FallingGlowLeaves"));
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_684'
void ElementalWall_cpp::__sinit() {
    s32 sp2C;
    s32 sp28;
    s32 sp24;
    s32 sp20;
    s32 sp1C;
    s32 sp18;
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    void *temp_r20_4983;

    temp_r20_4983 = &lit_684 + 0x90;
    sp2C = M2C_FIELD(&lit_684, s32 *, 0x68);
    M2C_FIELD(temp_r20_4983, s32 *, 0x60) = (s32) M2C_FIELD(&lit_684, s32 *, 0x60);
    sp8 = M2C_FIELD(&lit_684, s32 *, 0x6C);
    M2C_FIELD(temp_r20_4983, s32 *, 0x68) = sp2C;
    spC = M2C_FIELD(&lit_684, s32 *, 0x70);
    M2C_FIELD(temp_r20_4983, s32 *, 0x6C) = sp8;
    sp10 = M2C_FIELD(&lit_684, s32 *, 0x74);
    M2C_FIELD(temp_r20_4983, s32 *, 0x70) = spC;
    sp14 = M2C_FIELD(&lit_684, s32 *, 0x78);
    M2C_FIELD(temp_r20_4983, s32 *, 0x74) = sp10;
    sp18 = M2C_FIELD(&lit_684, s32 *, 0x7C);
    M2C_FIELD(temp_r20_4983, s32 *, 0x78) = sp14;
    sp1C = M2C_FIELD(&lit_684, s32 *, 0x80);
    M2C_FIELD(temp_r20_4983, s32 *, 0x7C) = sp18;
    sp20 = M2C_FIELD(&lit_684, s32 *, 0x84);
    M2C_FIELD(temp_r20_4983, s32 *, 0x80) = sp1C;
    sp24 = M2C_FIELD(&lit_684, s32 *, 0x88);
    M2C_FIELD(temp_r20_4983, s32 *, 0x84) = sp20;
    M2C_FIELD(temp_r20_4983, s32 *, 0x88) = sp24;
    M2C_FIELD(&lit_684, s32 *, 0x90) = (s32) M2C_FIELD(&lit_684, s32 *, 0);
    M2C_FIELD(&lit_684, s32 *, 0x94) = (s32) M2C_FIELD(&lit_684, s32 *, 4);
    M2C_FIELD(&lit_684, s32 *, 0x98) = (s32) M2C_FIELD(&lit_684, s32 *, 8);
    M2C_FIELD(temp_r20_4983, s32 *, 0xC) = (s32) M2C_FIELD(&lit_684, s32 *, 0xC);
    M2C_FIELD(temp_r20_4983, s32 *, 0x10) = (s32) M2C_FIELD(&lit_684, s32 *, 0x10);
    M2C_FIELD(temp_r20_4983, s32 *, 0x14) = (s32) M2C_FIELD(&lit_684, s32 *, 0x14);
    M2C_FIELD(temp_r20_4983, s32 *, 0x18) = (s32) M2C_FIELD(&lit_684, s32 *, 0x18);
    M2C_FIELD(temp_r20_4983, s32 *, 0x1C) = (s32) M2C_FIELD(&lit_684, s32 *, 0x1C);
    M2C_FIELD(temp_r20_4983, s32 *, 0x20) = (s32) M2C_FIELD(&lit_684, s32 *, 0x20);
    M2C_FIELD(temp_r20_4983, s32 *, 0x24) = (s32) M2C_FIELD(&lit_684, s32 *, 0x24);
    M2C_FIELD(temp_r20_4983, s32 *, 0x28) = (s32) M2C_FIELD(&lit_684, s32 *, 0x28);
    M2C_FIELD(temp_r20_4983, s32 *, 0x2C) = (s32) M2C_FIELD(&lit_684, s32 *, 0x2C);
    M2C_FIELD(temp_r20_4983, s32 *, 0x30) = (s32) M2C_FIELD(&lit_684, s32 *, 0x30);
    M2C_FIELD(temp_r20_4983, s32 *, 0x34) = (s32) M2C_FIELD(&lit_684, s32 *, 0x34);
    M2C_FIELD(temp_r20_4983, s32 *, 0x38) = (s32) M2C_FIELD(&lit_684, s32 *, 0x38);
    M2C_FIELD(temp_r20_4983, s32 *, 0x3C) = (s32) M2C_FIELD(&lit_684, s32 *, 0x3C);
    M2C_FIELD(temp_r20_4983, s32 *, 0x40) = (s32) M2C_FIELD(&lit_684, s32 *, 0x40);
    M2C_FIELD(temp_r20_4983, s32 *, 0x44) = (s32) M2C_FIELD(&lit_684, s32 *, 0x44);
    M2C_FIELD(temp_r20_4983, s32 *, 0x48) = (s32) M2C_FIELD(&lit_684, s32 *, 0x48);
    M2C_FIELD(temp_r20_4983, s32 *, 0x4C) = (s32) M2C_FIELD(&lit_684, s32 *, 0x4C);
    M2C_FIELD(temp_r20_4983, s32 *, 0x50) = (s32) M2C_FIELD(&lit_684, s32 *, 0x50);
    M2C_FIELD(temp_r20_4983, s32 *, 0x54) = (s32) M2C_FIELD(&lit_684, s32 *, 0x54);
    M2C_FIELD(temp_r20_4983, s32 *, 0x58) = (s32) M2C_FIELD(&lit_684, s32 *, 0x58);
    M2C_FIELD(temp_r20_4983, s32 *, 0x5C) = (s32) M2C_FIELD(&lit_684, s32 *, 0x5C);
    M2C_FIELD(temp_r20_4983, s32 *, 0x64) = (s32) M2C_FIELD(&lit_684, s32 *, 0x64);
    M2C_FIELD(temp_r20_4983, s32 *, 0x8C) = (s32) M2C_FIELD(&lit_684, s32 *, 0x8C);
    sp28 = M2C_FIELD(&lit_684, s32 *, 0x8C);
}
#endif
