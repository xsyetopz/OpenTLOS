#include "spyro/source/ElementalSpline.h"
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
extern f32 *KDSpline_PositionMixer;
extern void **gMK;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern GameGlobals gb;
#if 0 // DRAFT: illegal use of incomplete struct/union/class
static M2C_UNK lit_685;                                /* unable to generate initializer: unknown type */
static KDStateMachine<ElementalSpline>::State ElementalSplineStates; /* unable to generate initializer: confusing struct layout */
static s32 lit_812 = 1;
#endif

static s32 lit_878 = 1;

static s32 lit_922 = 1;

static s32 lit_967 = 1;

static s32 lit_1021 = 1;
static s32 lit_1047 = 1;

static u8 lit_1057 = 1;
static s32 lit_1078 = 1;
static s32 lit_1095 = 1;
static s32 lit_1104 = 1;

void ElementalSpline::StateESOffExit() {

}

void ElementalSpline::StateESOffUpdate() {

}

void ElementalSpline::StateESOffEnter() {

}

void ElementalSpline::StateESTurningOffExit() {

}

#if 0 // DRAFT: undefined identifier '__vptr'
void ElementalSpline::StateESTurningOffUpdate() {
    s8 spC1;
    s8 spC0;
    s32 spBC;
    f32 spB8;
    s32 spB4;
    s8 spB2;
    s8 spB1;
    s8 spB0;
    f64 spA8;                                       /* compiler-managed */
    f64 spA0;                                       /* compiler-managed */
    ElementalSpline *sp9C;
    s32 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    s32 sp74;
    s32 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    KDUniformSpline sp30;
    f32 sp28;
    f64 sp20;
    f64 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f2_175;
    f32 var_f31_180;
    f64 temp_f1_183;
    f64 temp_f1_189;
    f64 temp_f1_193;
    s32 temp_r3_212;
    s32 var_r0_222;
    void *temp_r3_134;

    if (this->unk10C >= this->unk108) {
        ((KDStateMachine<ElementalSpline> *) &this->unkC0)->SetState(this, 3, 0U);
        this->unkD8.Send(NULL);
        return;
    }
    if (((Frustum *) (M2C_FIELD(&gb, s32 *, 0x3B8) + 0xB0))->IsVisible((Matrix *) this->unk8, this->unkC) != 0) {
        EmitParticles(this->unk10C / this->unk108, 1.0f);
    }
    if (((u8) this->unk118 != 0) && ((HeroInterface *) gb.unk0 != NULL)) {
        temp_r3_134 = M2C_FIELD(M2C_FIELD(gb.unk0->__vptr, void *(**)(), 0xC)(), void **, 8);
        sp60 = M2C_FIELD(temp_r3_134, f64 *, 0x30);
        sp68 = M2C_FIELD(temp_r3_134, f64 *, 0x38);
        Tools_GetClosestSplineTime(((u8 *) this->unkB0) + 0x30, *((MKVector3 *) &sp60), this->unk114);
        if (M2C_ERROR(/* Read from unset register $f1 */) > (this->unk10C / this->unk100)) {
            spC = 0.0f;
            sp30.GetMeasure(M2C_ERROR(/* Read from unset register $f1 */), ((u8 *) this->unkB0) + 0x30, KDSpline_PositionMixer);
            sp50 = M2C_BITWISE(f64, sp30);
            sp58 = (f64) sp30.unk8;
            sp20 = sp60 - sp50;
            sp30.unk10 = sp20;
            sp28 = (f32) sp68 - (f32) sp58;
            temp_f2_175 = M2C_BITWISE(f32, sp30.unk10);
            sp48 = (f64) sp28;
            var_f31_180 = ((f32) sp48 * (f32) sp48) + ((temp_f2_175 * temp_f2_175) + (sp44 * sp44));
            if (var_f31_180 > 0.0f) {
                temp_f1_183 = __frsqrte(var_f31_180);
                temp_f1_189 = 0.5 * temp_f1_183 * -(((f64) var_f31_180 * (temp_f1_183 * temp_f1_183)) - 3.0);
                temp_f1_193 = 0.5 * temp_f1_189 * -(((f64) var_f31_180 * (temp_f1_189 * temp_f1_189)) - 3.0);
                var_f31_180 = (f32) ((f64) var_f31_180 * (0.5 * temp_f1_193 * -(((f64) var_f31_180 * (temp_f1_193 * temp_f1_193)) - 3.0)));
            } else if (var_f31_180 < M2C_BITWISE(f32, 0.0)) {
                var_f31_180 = __float_nan;
            } else {
                sp8 = var_f31_180;
                temp_r3_212 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                switch (temp_r3_212) {              /* irregular */
                case 0x7F800000:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_222 = 1;
                    } else {
                        var_r0_222 = 2;
                    }
                    break;
                case 0x0:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_222 = 5;
                    } else {
                        var_r0_222 = 3;
                    }
                    break;
                default:
                    var_r0_222 = 4;
                    break;
                }
                if (var_r0_222 == 1) {
                    var_f31_180 = __float_nan;
                }
            }
            if (var_f31_180 <= gb.unk0->GetCollideRadius()) {
                sp74 = 0;
                sp70 = 7;
                sp98 = 5;
                sp9C = this;
                sp78 = M2C_BITWISE(f64, sp30.unk10);
                sp80 = sp48;
                spB0 = 1;
                spBC = 2;
                spB8 = 10.0f;
                spB1 = 0;
                spB2 = 1;
                spB4 = -1;
                sp88 = M2C_FIELD(&MKVector3::one, f64 *, 0);
                sp90 = M2C_FIELD(&MKVector3::one, f64 *, 8);
                spC0 = 0;
                if (this != NULL) {
                    ((MKProp *) &sp10)->GetPos();
                    spA0 = sp10;
                    spA8 = sp18;
                } else {
                    spA0 = 0.0f;
                    (*(f32 *) ((u8 *) &sp9C + 0x8)) = 0.0f;
                    spA8 = 0.0f;
                }
                spC1 = 0;
                gb.unk0->Message(&sp70);
            }
        }
    }
    this->unk10C += gUpdateTimeDelta;
}
#endif

void ElementalSpline::StateESTurningOffEnter() {
    this->unk10C = 0.0f;
}

void ElementalSpline::StateESOnExit() {

}

#if 0 // DRAFT: undefined identifier '__vptr'
void ElementalSpline::StateESOnUpdate() {
    s8 spC1;
    s8 spC0;
    s32 spBC;
    f32 spB8;
    s32 spB4;
    s8 spB2;
    s8 spB1;
    s8 spB0;
    f64 spA8;                                       /* compiler-managed */
    f64 spA0;                                       /* compiler-managed */
    ElementalSpline *sp9C;
    s32 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    s32 sp74;
    s32 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    KDUniformSpline sp30;
    f32 sp28;
    f64 sp20;
    f64 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f2_419;
    f32 var_f31_424;
    f64 temp_f1_427;
    f64 temp_f1_433;
    f64 temp_f1_437;
    s32 temp_r3_456;
    s32 var_r0_466;
    void *temp_r3_383;

    if (this->unk10C >= this->unk104) {
        ((KDStateMachine<ElementalSpline> *) &this->unkC0)->SetState(this, 2, 0U);
        return;
    }
    if (((Frustum *) (M2C_FIELD(&gb, s32 *, 0x3B8) + 0xB0))->IsVisible((Matrix *) this->unk8, this->unkC) != 0) {
        EmitParticles(0.0f, 1.0f);
    }
    if (((u8) this->unk118 != 0) && ((HeroInterface *) gb.unk0 != NULL)) {
        temp_r3_383 = M2C_FIELD(M2C_FIELD(gb.unk0->__vptr, void *(**)(), 0xC)(), void **, 8);
        sp60 = M2C_FIELD(temp_r3_383, f64 *, 0x30);
        sp68 = M2C_FIELD(temp_r3_383, f64 *, 0x38);
        Tools_GetClosestSplineTime(((u8 *) this->unkB0) + 0x30, *((MKVector3 *) &sp60), this->unk114);
        spC = 0.0f;
        sp30.GetMeasure(M2C_ERROR(/* Read from unset register $f1 */), ((u8 *) this->unkB0) + 0x30, KDSpline_PositionMixer);
        sp50 = M2C_BITWISE(f64, sp30);
        sp58 = (f64) sp30.unk8;
        sp20 = sp60 - sp50;
        sp30.unk10 = sp20;
        sp28 = (f32) sp68 - (f32) sp58;
        temp_f2_419 = M2C_BITWISE(f32, sp30.unk10);
        sp48 = (f64) sp28;
        var_f31_424 = ((f32) sp48 * (f32) sp48) + ((temp_f2_419 * temp_f2_419) + (sp44 * sp44));
        if (var_f31_424 > 0.0f) {
            temp_f1_427 = __frsqrte(var_f31_424);
            temp_f1_433 = 0.5 * temp_f1_427 * -(((f64) var_f31_424 * (temp_f1_427 * temp_f1_427)) - 3.0);
            temp_f1_437 = 0.5 * temp_f1_433 * -(((f64) var_f31_424 * (temp_f1_433 * temp_f1_433)) - 3.0);
            var_f31_424 = (f32) ((f64) var_f31_424 * (0.5 * temp_f1_437 * -(((f64) var_f31_424 * (temp_f1_437 * temp_f1_437)) - 3.0)));
        } else if (var_f31_424 < M2C_BITWISE(f32, 0.0)) {
            var_f31_424 = __float_nan;
        } else {
            sp8 = var_f31_424;
            temp_r3_456 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r3_456) {                  /* irregular */
            case 0x7F800000:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_466 = 1;
                } else {
                    var_r0_466 = 2;
                }
                break;
            case 0x0:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_466 = 5;
                } else {
                    var_r0_466 = 3;
                }
                break;
            default:
                var_r0_466 = 4;
                break;
            }
            if (var_r0_466 == 1) {
                var_f31_424 = __float_nan;
            }
        }
        if (var_f31_424 <= gb.unk0->GetCollideRadius()) {
            sp74 = 0;
            sp70 = 7;
            sp98 = 5;
            sp9C = this;
            sp78 = M2C_BITWISE(f64, sp30.unk10);
            sp80 = sp48;
            spB0 = 1;
            spBC = 2;
            spB8 = 10.0f;
            spB1 = 0;
            spB2 = 1;
            spB4 = -1;
            sp88 = M2C_FIELD(&MKVector3::one, f64 *, 0);
            sp90 = M2C_FIELD(&MKVector3::one, f64 *, 8);
            spC0 = 0;
            if (this != NULL) {
                ((MKProp *) &sp10)->GetPos();
                spA0 = sp10;
                spA8 = sp18;
            } else {
                spA0 = 0.0f;
                (*(f32 *) ((u8 *) &sp9C + 0x8)) = 0.0f;
                spA8 = 0.0f;
            }
            spC1 = 0;
            gb.unk0->Message(&sp70);
        }
    }
    this->unk10C += gUpdateTimeDelta;
}
#endif

void ElementalSpline::StateESOnEnter() {
    this->unk10C = 0.0f;
}

void ElementalSpline::StateESTurningOnExit() {

}

#if 0 // DRAFT: undefined identifier '__vptr'
void ElementalSpline::StateESTurningOnUpdate() {
    s8 spC1;
    s8 spC0;
    s32 spBC;
    f32 spB8;
    s32 spB4;
    s8 spB2;
    s8 spB1;
    s8 spB0;
    f64 spA8;                                       /* compiler-managed */
    f64 spA0;                                       /* compiler-managed */
    ElementalSpline *sp9C;
    s32 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    s32 sp74;
    s32 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    KDUniformSpline sp30;
    f32 sp28;
    f64 sp20;
    f64 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f2_673;
    f32 var_f31_678;
    f64 temp_f1_681;
    f64 temp_f1_687;
    f64 temp_f1_691;
    s32 temp_r3_710;
    s32 var_r0_720;
    void *temp_r3_632;

    if (this->unk10C >= this->unk100) {
        ((KDStateMachine<ElementalSpline> *) &this->unkC0)->SetState(this, 1, 0U);
        this->unkD4.Send(NULL);
        return;
    }
    if (((Frustum *) (M2C_FIELD(&gb, s32 *, 0x3B8) + 0xB0))->IsVisible((Matrix *) this->unk8, this->unkC) != 0) {
        EmitParticles(0.0f, this->unk10C / this->unk100);
    }
    if (((u8) this->unk118 != 0) && ((HeroInterface *) gb.unk0 != NULL)) {
        temp_r3_632 = M2C_FIELD(M2C_FIELD(gb.unk0->__vptr, void *(**)(), 0xC)(), void **, 8);
        sp60 = M2C_FIELD(temp_r3_632, f64 *, 0x30);
        sp68 = M2C_FIELD(temp_r3_632, f64 *, 0x38);
        Tools_GetClosestSplineTime(((u8 *) this->unkB0) + 0x30, *((MKVector3 *) &sp60), this->unk114);
        if (M2C_ERROR(/* Read from unset register $f1 */) < (this->unk10C / this->unk100)) {
            spC = 0.0f;
            sp30.GetMeasure(M2C_ERROR(/* Read from unset register $f1 */), ((u8 *) this->unkB0) + 0x30, KDSpline_PositionMixer);
            sp50 = M2C_BITWISE(f64, sp30);
            sp58 = (f64) sp30.unk8;
            sp20 = sp60 - sp50;
            sp30.unk10 = sp20;
            sp28 = (f32) sp68 - (f32) sp58;
            temp_f2_673 = M2C_BITWISE(f32, sp30.unk10);
            sp48 = (f64) sp28;
            var_f31_678 = ((f32) sp48 * (f32) sp48) + ((temp_f2_673 * temp_f2_673) + (sp44 * sp44));
            if (var_f31_678 > 0.0f) {
                temp_f1_681 = __frsqrte(var_f31_678);
                temp_f1_687 = 0.5 * temp_f1_681 * -(((f64) var_f31_678 * (temp_f1_681 * temp_f1_681)) - 3.0);
                temp_f1_691 = 0.5 * temp_f1_687 * -(((f64) var_f31_678 * (temp_f1_687 * temp_f1_687)) - 3.0);
                var_f31_678 = (f32) ((f64) var_f31_678 * (0.5 * temp_f1_691 * -(((f64) var_f31_678 * (temp_f1_691 * temp_f1_691)) - 3.0)));
            } else if (var_f31_678 < M2C_BITWISE(f32, 0.0)) {
                var_f31_678 = __float_nan;
            } else {
                sp8 = var_f31_678;
                temp_r3_710 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                switch (temp_r3_710) {              /* irregular */
                case 0x7F800000:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_720 = 1;
                    } else {
                        var_r0_720 = 2;
                    }
                    break;
                case 0x0:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_720 = 5;
                    } else {
                        var_r0_720 = 3;
                    }
                    break;
                default:
                    var_r0_720 = 4;
                    break;
                }
                if (var_r0_720 == 1) {
                    var_f31_678 = __float_nan;
                }
            }
            if (var_f31_678 <= gb.unk0->GetCollideRadius()) {
                sp74 = 0;
                sp70 = 7;
                sp98 = 5;
                sp9C = this;
                sp78 = M2C_BITWISE(f64, sp30.unk10);
                sp80 = sp48;
                spB0 = 1;
                spBC = 2;
                spB8 = 10.0f;
                spB1 = 0;
                spB2 = 1;
                spB4 = -1;
                sp88 = M2C_FIELD(&MKVector3::one, f64 *, 0);
                sp90 = M2C_FIELD(&MKVector3::one, f64 *, 8);
                spC0 = 0;
                if (this != NULL) {
                    ((MKProp *) &sp10)->GetPos();
                    spA0 = sp10;
                    spA8 = sp18;
                } else {
                    spA0 = 0.0f;
                    (*(f32 *) ((u8 *) &sp9C + 0x8)) = 0.0f;
                    spA8 = 0.0f;
                }
                spC1 = 0;
                gb.unk0->Message(&sp70);
            }
        }
    }
    this->unk10C += gUpdateTimeDelta;
}
#endif

void ElementalSpline::StateESTurningOnEnter() {
    this->unk10C = 0.0f;
}

#if 0 // DRAFT: undefined identifier 'fabs'
void ElementalSpline::EmitEarthParticles(float arg0, float arg1) {
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
    MKVector3 spA8;
    KDUniformSpline sp88;
    f64 sp80;
    f64 sp78;
    MKVector3 sp68;
    M2C_UNK sp58;
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
    f32 temp_f1_1000;
    f32 temp_f1_871;
    f32 temp_f1_956;
    f32 temp_f24_865;
    f32 temp_f27_860;
    f32 temp_f27_947;
    f32 temp_f30_884;
    f64 temp_f0_887;
    s32 var_r0_1055;
    s32 var_r0_934;
    s32 var_r26_949;
    s32 var_r27_862;

    temp_f27_860 = arg0 - arg1;
    var_r27_862 = 0;
    temp_f24_865 = (f32) fabs(temp_f27_860);
loop_2:
    var_r0_934 = (s32) (0.2f * (f32) this->unk114 * temp_f24_865);
    if ((s32) lit_1095 > var_r0_934) {
        var_r0_934 = lit_1095;
    }
    if (var_r27_862 < var_r0_934) {
        temp_f1_871 = MKRand_Float(&gViewSeed, arg0, arg1);
        sp10 = 0.0f;
        spF8.GetMeasure(temp_f1_871, ((u8 *) this->unkB0) + 0x30, KDSpline_PositionMixer);
        sp118 = M2C_BITWISE(f64, spF8);
        sp120 = (f64) spF8.unk8;
        temp_f30_884 = this->unkB4;
        KDRand_UnitVectorXZ();
        temp_f0_887 = spD8 * (f64) temp_f30_884;
        sp48 = temp_f0_887;
        spF8.unk10 = temp_f0_887;
        sp50 = spE0 * temp_f30_884;
        spE8 = temp_f0_887;
        sp110 = (f64) sp50;
        spF0 = (f64) sp50;
        sp10C += this->unkB4;
        sp1C = MKRand_Int(&gViewSeed, 0, 3);
        sp20 = MKRand_Float(&gViewSeed, 1.0f, 1.5f);
        ((FallingLeaves *) (M2C_FIELD(checked_cast<ElementalSplineDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), FallingLeaves **, 0x60)))->Emit(*((MKVector3 *) &sp118), *((MKVector3 *) &spF8.unk10), sp20, sp1C, 1U);
        var_r27_862 += 1;
        goto loop_2;
    }
    temp_f27_947 = (f32) fabs(temp_f27_860);
    var_r26_949 = 0;
loop_7:
    var_r0_1055 = (s32) ((f32) this->unk114 * temp_f27_947);
    if ((s32) lit_1104 > var_r0_1055) {
        var_r0_1055 = lit_1104;
    }
    if (var_r26_949 < var_r0_1055) {
        temp_f1_956 = MKRand_Float(&gViewSeed, arg0, arg1);
        spC = 0.0f;
        ((KDUniformSpline *) &spC8)->GetMeasure(temp_f1_956, ((u8 *) this->unkB0) + 0x30, KDSpline_PositionMixer);
        sp118 = spC8;
        sp120 = spD0;
        KDRand_UnitVectorXZ();
        spA8.operator*(this->unkB4);
        sp38 = spA8 * 5.439686476e-315;
        spB8 = sp38;
        sp40 = spA8.unk8 * 20.0f;
        spF8.unk10 = sp38;
        spC0 = (f64) sp40;
        sp110 = (f64) sp40;
        sp18 = MKRand_Float(&gViewSeed, 0.1f, 0.5f);
        gb.EmitSmallRocks(*((MKVector3 *) &sp118), *((MKVector3 *) &spF8.unk10), sp18);
        temp_f1_1000 = MKRand_Float(&gViewSeed, arg0, arg1);
        sp8 = 0.0f;
        sp88.GetMeasure(temp_f1_1000, ((u8 *) this->unkB0) + 0x30, KDSpline_PositionMixer);
        sp118 = M2C_BITWISE(f64, sp88);
        sp120 = (f64) sp88.unk8;
        KDRand_UnitVectorXZ();
        sp68.operator*(this->unkB4);
        sp28 = sp68 * 5.398241246e-315;
        sp78 = sp28;
        sp30 = sp68.unk8 * 10.0f;
        spF8.unk10 = sp28;
        sp80 = (f64) sp30;
        sp110 = (f64) sp30;
        sp14 = MKRand_Float(&gViewSeed, 2.0f, 5.0f);
        ((EmbersPS *) gb.unk74)->Emit(*((MKVector3 *) &sp118), *((MKVector3 *) &spF8.unk10), sp14, this->unkE0, 0.0f);
        var_r26_949 += 1;
        goto loop_7;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk30C'
void ElementalSpline::EmitIceParticles(float arg0, float arg1) {
    f64 sp78;
    f64 sp70;
    f64 sp68;
    KDUniformSpline sp50;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    f32 spC;
    f32 sp8;
    MKPropDescriptor *temp_r28_1127;
    f32 temp_f1_1130;
    f32 temp_f1_1195;
    f32 temp_f27_1189;
    f32 temp_f30_1208;
    s32 var_r0_1267;
    s32 var_r27_1187;
    void *temp_r26_1229;
    void *temp_r3_1145;
    void *temp_r3_1226;

    if (gb.unk30C >= this->unkF0) {
        temp_r28_1127 = checked_cast<ShatterableDescriptor *, MKPropDescriptor>(M2C_FIELD(*gMK, MKPropDescriptor *(**)(void **, M2C_UNK *), 0x5C)(gMK, "IceCube"));
        temp_f1_1130 = MKRand_Float(&gViewSeed, arg0, arg1);
        spC = 0.0f;
        sp50.GetMeasure(temp_f1_1130, ((u8 *) this->unkB0) + 0x30, KDSpline_PositionMixer);
        sp70 = M2C_BITWISE(f64, sp50);
        sp78 = (f64) sp50.unk8;
        temp_r3_1145 = checked_cast<PooledShatterProp *, MKProp>(temp_r28_1127->CreateInstance());
        if (temp_r3_1145 != NULL) {
            M2C_FIELD(M2C_FIELD(temp_r3_1145, void **, 0x44), M2C_UNK (**)(f64 *), 0x38)(&sp70);
            M2C_FIELD(M2C_FIELD(temp_r3_1145, void **, 0x44), M2C_UNK (**)(void *), 0x20)(temp_r3_1145);
            M2C_FIELD(M2C_FIELD(temp_r3_1145, void **, 0x44), M2C_UNK (**)(void *), 0x30)(temp_r3_1145);
            M2C_FIELD(M2C_FIELD(temp_r3_1145, void **, 0x44), M2C_UNK (**)(void *, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK), 0x94)(temp_r3_1145, 0, 0, -1, 0, 0, 0);
        }
        this->unkF0 = gb.unk30C + 0.33f;
    }
    var_r27_1187 = 0;
    temp_f27_1189 = (f32) fabs(arg0 - arg1);
loop_8:
    var_r0_1267 = (s32) ((f32) this->unk114 * temp_f27_1189);
    if ((s32) lit_1078 > var_r0_1267) {
        var_r0_1267 = lit_1078;
    }
    if (var_r27_1187 < var_r0_1267) {
        temp_f1_1195 = MKRand_Float(&gViewSeed, arg0, arg1);
        sp8 = 0.0f;
        ((KDUniformSpline *) &sp40)->GetMeasure(temp_f1_1195, ((u8 *) this->unkB0) + 0x30, KDSpline_PositionMixer);
        sp70 = sp40;
        sp78 = sp48;
        temp_f30_1208 = this->unkB4;
        KDRand_UnitVector();
        sp10 = sp20 * (f64) temp_f30_1208;
        sp30 = sp10;
        sp18 = sp28 * temp_f30_1208;
        sp50.unk10 = sp10;
        sp38 = (f64) sp18;
        sp68 = (f64) sp18;
        temp_r3_1226 = M2C_FIELD(M2C_FIELD(gb.unk2A0, void **, 0x44), void *(**)(void *, f64), 0x3C)(gb.unk2A0, sp10);
        if (temp_r3_1226 != NULL) {
            temp_r26_1229 = M2C_FIELD(temp_r3_1226, void **, 0x2C);
            M2C_FIELD(temp_r3_1226, f64 *, 0) = sp70;
            M2C_FIELD(temp_r3_1226, f64 *, 8) = sp78;
            M2C_FIELD(temp_r3_1226, f32 *, 0x20) = 0.0f;
            M2C_FIELD(temp_r3_1226, f32 *, 0x28) = 0.0f;
            M2C_FIELD(temp_r26_1229, f64 *, 0) = M2C_BITWISE(f64, sp50.unk10);
            M2C_FIELD(temp_r26_1229, f64 *, 8) = sp68;
            M2C_FIELD(temp_r26_1229, f32 *, 0x18) = MKRand_Float(&gViewSeed, 0.25f, 1.0f);
            M2C_FIELD(temp_r26_1229, f32 *, 0x10) = MKRand_Float(&gViewSeed, -3.1415927f, 3.1415927f);
            M2C_FIELD(temp_r26_1229, f32 *, 0x14) = (f32) M2C_FIELD(gb.unk2A0, f32 *, 0xF4);
        }
        var_r27_1187 += 1;
        goto loop_8;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk30C'
void ElementalSpline::EmitElectricityParticles(float arg0, float arg1) {
    f64 spF0;
    f64 spE8;
    f64 spE0;                                       /* compiler-managed */
    f32 spDC;
    KDUniformSpline spC8;
    f64 spC0;
    f64 spB8;
    f64 spA8;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f32 sp40;
    f64 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f0_1553;
    f32 temp_f1_1339;
    f32 temp_f1_1400;
    f32 temp_f25_1333;
    f32 temp_f29_1435;
    f32 temp_f30_1416;
    f32 temp_f4_1455;
    f32 var_f4_1463;
    f32 var_f4_1530;
    f32 var_f4_1543;
    f64 temp_f0_1439;
    f64 temp_f1_1469;
    f64 temp_f1_1475;
    f64 temp_f1_1479;
    s32 temp_r3_1498;
    s32 var_r0_1390;
    s32 var_r0_1508;
    s32 var_r27_1330;

    if (gb.unk30C >= this->unkF0) {
        var_r27_1330 = 0;
        temp_f25_1333 = (f32) fabs(arg0 - arg1);
loop_3:
        var_r0_1390 = (s32) ((f32) this->unk114 * temp_f25_1333);
        if ((s32) lit_1047 > var_r0_1390) {
            var_r0_1390 = lit_1047;
        }
        if (var_r27_1330 < var_r0_1390) {
            temp_f1_1339 = MKRand_Float(&gViewSeed, arg0, arg1);
            sp10 = 0.0f;
            spC8.GetMeasure(temp_f1_1339, ((u8 *) this->unkB0) + 0x30, KDSpline_PositionMixer);
            spE8 = M2C_BITWISE(f64, spC8);
            spF0 = (f64) spC8.unk8;
            KDRand_UnitVector();
            sp38 = spA8 * 5.60222949e-315;
            spC8.unk10 = sp38;
            sp40 = spB0 * 300.0f;
            spB8 = sp38;
            spC0 = (f64) sp40;
            spE0 = (f64) sp40;
            spDC += 300.0f;
            ((ElectricSparks *) gb.unk230)->Emit(*((MKVector3 *) &spE8), *((MKVector3 *) &spC8.unk10), MKRand_Float(&gViewSeed, 1.0f, 2.0f), 1U);
            var_r27_1330 += 1;
            goto loop_3;
        }
        temp_f1_1400 = MKRand_Float(&gViewSeed, arg0, arg1);
        spC = 0.0f;
        ((KDUniformSpline *) &sp98)->GetMeasure(temp_f1_1400, ((u8 *) this->unkB0) + 0x30, KDSpline_PositionMixer);
        spE8 = sp98;
        spF0 = spA0;
        temp_f30_1416 = this->unkB4;
        ((KDSplinePathSegment *) &sp78)->GetVelocity(MKRand_Float(&gViewSeed, arg0, arg1));
        sp28 = sp78 * (f64) temp_f30_1416;
        spC8.unk10 = sp28;
        sp30 = sp80 * temp_f30_1416;
        sp88 = sp28;
        spE0 = (f64) sp30;
        sp90 = (f64) sp30;
        temp_f29_1435 = this->unkB4;
        KDRand_UnitVector();
        temp_f0_1439 = sp58 * (f64) temp_f29_1435;
        sp18 = temp_f0_1439;
        sp68 = temp_f0_1439;
        sp20 = sp60 * temp_f29_1435;
        sp70 = (f64) sp20;
        spC8.unk10 = sp28 + temp_f0_1439;
        temp_f4_1455 = (f32) spE0 + (f32) sp70;
        spE0 = temp_f4_1455;
        var_f4_1463 = (temp_f4_1455 * temp_f4_1455) + (((f32) spC8.unk10 * (f32) spC8.unk10) + (spDC * spDC));
        if (var_f4_1463 > 0.000001f) {
            if (var_f4_1463 > 0.0f) {
                temp_f1_1469 = __frsqrte(var_f4_1463);
                temp_f1_1475 = 0.5 * temp_f1_1469 * -(((f64) var_f4_1463 * (temp_f1_1469 * temp_f1_1469)) - 3.0);
                temp_f1_1479 = 0.5 * temp_f1_1475 * -(((f64) var_f4_1463 * (temp_f1_1475 * temp_f1_1475)) - 3.0);
                var_f4_1463 = (f32) ((f64) var_f4_1463 * (0.5 * temp_f1_1479 * -(((f64) var_f4_1463 * (temp_f1_1479 * temp_f1_1479)) - 3.0)));
            } else if (var_f4_1463 < M2C_BITWISE(f32, 0.0)) {
                var_f4_1463 = __float_nan;
            } else {
                sp8 = var_f4_1463;
                temp_r3_1498 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                switch (temp_r3_1498) {             /* irregular */
                case 0x7F800000:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_1508 = 1;
                    } else {
                        var_r0_1508 = 2;
                    }
                    break;
                case 0x0:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_1508 = 5;
                    } else {
                        var_r0_1508 = 3;
                    }
                    break;
                default:
                    var_r0_1508 = 4;
                    break;
                }
                if (var_r0_1508 == 1) {
                    var_f4_1463 = __float_nan;
                }
            }
            var_f4_1530 = 1.0f / var_f4_1463;
        } else {
            var_f4_1530 = 0.0f;
        }
        var_f4_1543 = 1.0f;
        spC8.unk10 = (f32) spC8.unk10 * var_f4_1530;
        spDC *= var_f4_1530;
        spE0 *= var_f4_1530;
        sp48 = M2C_FIELD(this, f64 *, 0xE0);
        sp50 = M2C_FIELD(this, f64 *, 0xE8);
        temp_f0_1553 = M2C_FIELD(this->unkB0, f32 *, 0x38) / 1000.0f;
        if (var_f4_1543 > temp_f0_1553) {

        } else {
            var_f4_1543 = temp_f0_1553;
        }
        sp14 = 0.01f * this->unkB4 * var_f4_1543;
        ((ZapArcFX *) gb.unk94)->Trigger(*((MKVector3 *) &spE8), *((MKVector3 *) &spC8.unk10), sp14, lit_1057, (MKVector4) &sp48);
        this->unkF0 = gb.unk30C + 0.05f;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk30C'
void ElementalSpline::EmitFireParticles(float arg0, float arg1) {
    f64 spF8;
    f64 spF0;
    f64 spE8;
    f32 spE4;
    KDUniformSpline spD0;
    f64 spC8;
    f64 spC0;
    f64 spB0;
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp80;
    f64 sp70;
    f64 sp68;
    f64 sp60;
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
    f32 temp_f1_1635;
    f32 temp_f1_1696;
    f32 temp_f1_1743;
    f32 temp_f24_1649;
    f32 temp_f24_1710;
    f32 temp_f26_1690;
    f32 temp_f29_1756;
    s32 var_r0_1798;
    s32 var_r25_1688;

    if (gb.unk30C >= this->unkF0) {
        temp_f1_1635 = MKRand_Float(&gViewSeed, arg0, arg1);
        sp10 = 0.0f;
        spD0.GetMeasure(temp_f1_1635, ((u8 *) this->unkB0) + 0x30, KDSpline_PositionMixer);
        spF0 = M2C_BITWISE(f64, spD0);
        spF8 = (f64) spD0.unk8;
        temp_f24_1649 = this->unkB4;
        KDRand_UnitVectorXZ();
        sp40 = spB0 * (f64) temp_f24_1649;
        spD0.unk10 = sp40;
        sp48 = spB8 * temp_f24_1649;
        spC0 = sp40;
        spE8 = (f64) sp48;
        spC8 = (f64) sp48;
        spE4 += 5.0f * this->unkB4;
        gb.unk240.Emit(*((MKVector3 *) &spF0), *((MKVector3 *) &spD0.unk10), MKRand_Float(&gViewSeed, 2.0f, 5.0f), 1.0f);
        var_r25_1688 = 0;
        temp_f26_1690 = (f32) fabs(arg0 - arg1);
loop_3:
        var_r0_1798 = (s32) ((f32) this->unk114 * temp_f26_1690);
        if ((s32) lit_1021 > var_r0_1798) {
            var_r0_1798 = lit_1021;
        }
        if (var_r25_1688 < var_r0_1798) {
            temp_f1_1696 = MKRand_Float(&gViewSeed, arg0, arg1);
            spC = 0.0f;
            ((KDUniformSpline *) &spA0)->GetMeasure(temp_f1_1696, ((u8 *) this->unkB0) + 0x30, KDSpline_PositionMixer);
            spF0 = spA0;
            spF8 = spA8;
            temp_f24_1710 = this->unkB4;
            (*(f32 *) ((u8 *) &spF0 + 0x4)) -= temp_f24_1710;
            KDRand_UnitVectorXZ();
            sp30 = sp80 * (f64) temp_f24_1710;
            spD0.unk10 = sp30;
            sp38 = sp88 * temp_f24_1710;
            sp90 = sp30;
            spE8 = (f64) sp38;
            sp98 = (f64) sp38;
            spE4 += 5.0f * this->unkB4;
            sp18 = MKRand_Float(&gViewSeed, 2.0f, 5.0f);
            ((CrashFirePS *) gb.unk68)->Emit(*((MKVector3 *) &spF0), *((MKVector3 *) &spD0.unk10), sp18);
            temp_f1_1743 = MKRand_Float(&gViewSeed, arg0, arg1);
            sp8 = 0.0f;
            ((KDUniformSpline *) &sp70)->GetMeasure(temp_f1_1743, ((u8 *) this->unkB0) + 0x30, KDSpline_PositionMixer);
            spF0 = sp70;
            spF8 = sp78;
            temp_f29_1756 = this->unkB4;
            KDRand_UnitVectorXZ();
            sp20 = sp50 * (f64) temp_f29_1756;
            spD0.unk10 = sp20;
            sp28 = sp58 * temp_f29_1756;
            sp60 = sp20;
            spE8 = (f64) sp28;
            sp68 = (f64) sp28;
            spE4 += 5.0f * this->unkB4;
            sp14 = MKRand_Float(&gViewSeed, 2.0f, 5.0f);
            ((EmbersPS *) gb.unk74)->Emit(*((MKVector3 *) &spF0), *((MKVector3 *) &spD0.unk10), sp14, this->unkE0, 0.0f);
            var_r25_1688 += 1;
            goto loop_3;
        }
        this->unkF0 = gb.unk30C + 0.05f;
    }
}
#endif

void ElementalSpline::EmitParticles(float arg0, float arg1) {
    s32 temp_r0_1839;

    temp_r0_1839 = this->unk110;
    switch (temp_r0_1839) {                         /* irregular */
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
        return;
    }
}

#if 0 // DRAFT: undefined identifier 'fabs'
void ElementalSpline::DrawEarthSpline(float arg0, float arg1) {
    Matrix sp200;
    M2C_UNK sp1FC;
    f32 sp1F0;
    f32 sp1EC;
    f32 sp1E8;
    f64 sp1E0;                                      /* compiler-managed */
    f64 sp1D8;
    f64 sp1D0;
    f64 sp1C8;
    f64 sp1C0;                                      /* compiler-managed */
    f64 sp1B8;                                      /* compiler-managed */
    f64 sp1B0;                                      /* compiler-managed */
    f64 sp1A8;                                      /* compiler-managed */
    f64 sp1A0;
    KDUniformSpline sp188;
    f64 sp178;
    f64 sp168;
    f64 sp158;
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
    f64 spF0;
    f64 spE8;
    f64 spE0;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    f64 spC0;
    f64 spB8;
    f64 spB0;
    f64 spA8;
    f32 spA0;
    f64 sp98;
    f32 sp90;
    f64 sp88;
    f32 sp80;
    f64 sp78;
    f32 sp70;
    f64 sp68;
    f32 sp60;
    f64 sp58;
    f32 sp50;
    f64 sp48;
    f32 sp40;
    f64 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 temp_f20_2327;
    f32 temp_f26_2338;
    f32 temp_f27_2388;
    f32 temp_f2_2319;
    f32 temp_f30_2387;
    f32 temp_f31_2337;
    f32 temp_f7_2280;
    f32 temp_f8_2278;
    f32 temp_f9_2277;
    f32 var_f1_1978;
    f32 var_f1_1991;
    f32 var_f1_2011;
    f32 var_f1_2024;
    f32 var_f1_2051;
    f32 var_f1_2078;
    f32 var_f3_2269;
    f32 var_f4_2114;
    f32 var_f5_2181;
    f32 var_f6_2198;
    f64 temp_f0_2340;
    f64 temp_f0_2350;
    f64 temp_f0_2361;
    f64 temp_f0_2390;
    f64 temp_f0_2400;
    f64 temp_f0_2411;
    f64 temp_f1_2120;
    f64 temp_f1_2126;
    f64 temp_f1_2130;
    f64 temp_f1_2208;
    f64 temp_f1_2214;
    f64 temp_f1_2218;
    s32 temp_r0_1947;
    s32 temp_r3_2149;
    s32 temp_r3_2237;
    s32 var_r0_2159;
    s32 var_r0_2247;
    s32 var_r30_1969;
    s32 var_r31_1932;
    s32 var_r4_1940;
    void *temp_r3_2285;
    void *temp_r6_1923;

    M2C_STRUCT_COPY((s32) &sp1FC + 4, (s32) &this->unk4C + 4, 0x40);
    temp_r6_1923 = M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 8);
    sp1C8 = M2C_FIELD(temp_r6_1923, f64 *, 0x30);
    sp1D0 = M2C_FIELD(temp_r6_1923, f64 *, 0x38);
    sp1E8 = 1.0f;
    sp1EC = 1.0f;
    sp1F0 = 1.0f;
    sp200.Scale3x3(&sp200, *((MKVector3 *) &sp1E8));
    var_r31_1932 = this->unk114;
    var_r4_1940 = lit_967;
    temp_r0_1947 = (s32) ((f32) var_r31_1932 * (f32) fabs(arg1 - arg0));
    if (temp_r0_1947 > var_r4_1940) {
        var_r4_1940 = temp_r0_1947;
    }
    if (var_r4_1940 < var_r31_1932) {
        var_r31_1932 = var_r4_1940;
    }
    MKMaterial_SetMaterial(this->unkF4);
    MKPrimitive(0xC, 0x10);
    MKSetMatrix(sp200);
    MKBegin((var_r31_1932 + 1) * 2);
    var_r30_1969 = 0;
loop_65:
    if (var_r30_1969 < (s32) (var_r31_1932 + 1)) {
        if (var_r30_1969 == var_r31_1932) {
            var_f1_1978 = 1.0f;
            if (arg1 < var_f1_1978) {
                var_f1_1978 = arg1;
            }
            sp20 = 0.0f;
            sp188.GetMeasure(var_f1_1978, ((u8 *) this->unkB0) + 0x30, KDSpline_PositionMixer);
            var_f1_1991 = 1.0f;
            sp1D8 = M2C_BITWISE(f64, sp188);
            sp1E0 = (f64) sp188.unk8;
            if (arg1 < var_f1_1991) {
                var_f1_1991 = arg1;
            }
            ((KDSplinePathSegment *) &sp178)->GetVelocity(var_f1_1991);
            sp1A8 = sp178;
            sp1B0 = sp180;
        } else if (var_r30_1969 == 0) {
            var_f1_2011 = 1.0f;
            if (arg0 < var_f1_2011) {
                var_f1_2011 = arg0;
            }
            sp1C = 0.0f;
            ((KDUniformSpline *) &sp168)->GetMeasure(var_f1_2011, ((u8 *) this->unkB0) + 0x30, KDSpline_PositionMixer);
            var_f1_2024 = 1.0f;
            sp1D8 = sp168;
            sp1E0 = sp170;
            if (arg0 < var_f1_2024) {
                var_f1_2024 = arg0;
            }
            ((KDSplinePathSegment *) &sp158)->GetVelocity(var_f1_2024);
            sp1A8 = sp158;
            sp1B0 = sp160;
        } else {
            var_f1_2051 = ((f32) var_r30_1969 * this->unkFC) + arg0;
            if (var_f1_2051 < 1.0f) {

            } else {
                var_f1_2051 = 1.0f;
            }
            sp18 = 0.0f;
            ((KDUniformSpline *) &sp148)->GetMeasure(var_f1_2051, ((u8 *) this->unkB0) + 0x30, KDSpline_PositionMixer);
            sp1D8 = sp148;
            var_f1_2078 = ((f32) var_r30_1969 * this->unkFC) + arg0;
            sp1E0 = sp150;
            if (var_f1_2078 < 1.0f) {

            } else {
                var_f1_2078 = 1.0f;
            }
            ((KDSplinePathSegment *) &sp138)->GetVelocity(var_f1_2078);
            sp1A8 = sp138;
            sp1B0 = sp140;
        }
        sp38 = sp1D8 - sp1C8;
        sp1B8 = sp38;
        sp40 = (f32) sp1E0 - (f32) sp1D0;
        sp1C0 = (f64) sp40;
        sp128 = sp38;
        sp130 = (f64) sp40;
        var_f4_2114 = ((f32) sp1C0 * (f32) sp1C0) + (((f32) sp1B8 * (f32) sp1B8) + ((*(f32 *) ((u8 *) &sp1A0 + 0x1c)) * (*(f32 *) ((u8 *) &sp1A0 + 0x1c))));
        if (var_f4_2114 > 0.000001f) {
            if (var_f4_2114 > 0.0f) {
                temp_f1_2120 = __frsqrte(var_f4_2114);
                temp_f1_2126 = 0.5 * temp_f1_2120 * -(((f64) var_f4_2114 * (temp_f1_2120 * temp_f1_2120)) - 3.0);
                temp_f1_2130 = 0.5 * temp_f1_2126 * -(((f64) var_f4_2114 * (temp_f1_2126 * temp_f1_2126)) - 3.0);
                var_f4_2114 = (f32) ((f64) var_f4_2114 * (0.5 * temp_f1_2130 * -(((f64) var_f4_2114 * (temp_f1_2130 * temp_f1_2130)) - 3.0)));
            } else if (var_f4_2114 < M2C_BITWISE(f32, 0.0)) {
                var_f4_2114 = __float_nan;
            } else {
                sp14 = var_f4_2114;
                temp_r3_2149 = M2C_BITWISE(s32, sp14) & 0x7F800000;
                switch (temp_r3_2149) {             /* switch 1; irregular */
                case 0x7F800000:                    /* switch 1 */
                    if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                        var_r0_2159 = 1;
                    } else {
                        var_r0_2159 = 2;
                    }
                    break;
                case 0x0:                           /* switch 1 */
                    if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                        var_r0_2159 = 5;
                    } else {
                        var_r0_2159 = 3;
                    }
                    break;
                default:                            /* switch 1 */
                    var_r0_2159 = 4;
                    break;
                }
                if (var_r0_2159 == 1) {
                    var_f4_2114 = __float_nan;
                }
            }
            var_f5_2181 = 1.0f / var_f4_2114;
        } else {
            var_f5_2181 = 0.0f;
        }
        var_f6_2198 = ((f32) sp1B0 * (f32) sp1B0) + (((f32) sp1A8 * (f32) sp1A8) + ((*(f32 *) ((u8 *) &sp1A0 + 0xc)) * (*(f32 *) ((u8 *) &sp1A0 + 0xc))));
        sp1B8 = (f32) sp1B8 * var_f5_2181;
        (*(f32 *) ((u8 *) &sp1A0 + 0x1c)) *= var_f5_2181;
        sp1C0 = (f32) sp1C0 * var_f5_2181;
        if (var_f6_2198 > 0.000001f) {
            if (var_f6_2198 > 0.0f) {
                temp_f1_2208 = __frsqrte(var_f6_2198);
                temp_f1_2214 = 0.5 * temp_f1_2208 * -(((f64) var_f6_2198 * (temp_f1_2208 * temp_f1_2208)) - 3.0);
                temp_f1_2218 = 0.5 * temp_f1_2214 * -(((f64) var_f6_2198 * (temp_f1_2214 * temp_f1_2214)) - 3.0);
                var_f6_2198 = (f32) ((f64) var_f6_2198 * (0.5 * temp_f1_2218 * -(((f64) var_f6_2198 * (temp_f1_2218 * temp_f1_2218)) - 3.0)));
            } else if (var_f6_2198 < M2C_BITWISE(f32, 0.0)) {
                var_f6_2198 = __float_nan;
            } else {
                sp10 = var_f6_2198;
                temp_r3_2237 = M2C_BITWISE(s32, sp10) & 0x7F800000;
                switch (temp_r3_2237) {             /* switch 2; irregular */
                case 0x7F800000:                    /* switch 2 */
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_2247 = 1;
                    } else {
                        var_r0_2247 = 2;
                    }
                    break;
                case 0x0:                           /* switch 2 */
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_2247 = 5;
                    } else {
                        var_r0_2247 = 3;
                    }
                    break;
                default:                            /* switch 2 */
                    var_r0_2247 = 4;
                    break;
                }
                if (var_r0_2247 == 1) {
                    var_f6_2198 = __float_nan;
                }
            }
            var_f3_2269 = 1.0f / var_f6_2198;
        } else {
            var_f3_2269 = 0.0f;
        }
        temp_f9_2277 = (f32) sp1A8 * var_f3_2269;
        temp_f8_2278 = (*(f32 *) ((u8 *) &sp1A0 + 0xc)) * var_f3_2269;
        temp_f7_2280 = (f32) sp1B0 * var_f3_2269;
        temp_r3_2285 = this->unk8;
        sp1A8 = temp_f9_2277;
        sp2C = (temp_f7_2280 * sp1B8) - (temp_f9_2277 * sp1C0);
        sp28 = (temp_f8_2278 * sp1C0) - (temp_f7_2280 * (*(f32 *) ((u8 *) &sp1A0 + 0x1c)));
        sp30 = (temp_f9_2277 * (*(f32 *) ((u8 *) &sp1A0 + 0x1c))) - (temp_f8_2278 * sp1B8);
        sp108 = M2C_FIELD(temp_r3_2285, f64 *, 0x30);
        (*(f32 *) ((u8 *) &sp1A0 + 0xc)) = temp_f8_2278;
        sp1B0 = temp_f7_2280;
        sp118 = (f64) sp28;
        sp120 = (f64) sp30;
        sp188.unk10 = (f64) sp28;
        sp1A0 = (f64) sp30;
        sp110 = M2C_FIELD(temp_r3_2285, f64 *, 0x38);
        sp1D8 -= sp108;
        temp_f2_2319 = (f32) sp1E0 - (f32) sp110;
        sp1E0 = temp_f2_2319;
        temp_f20_2327 = 4.0f * ((f32) var_r30_1969 / (f32) this->unk114);
        MKSetColorV(this->unkE0);
        MKSetTexCoord1F(temp_f20_2327, 0.95f);
        temp_f31_2337 = MKRand_Float(&gViewSeed, 1.0f, 4.0f);
        temp_f26_2338 = this->unkB4 * 0.5f;
        temp_f0_2340 = M2C_BITWISE(f64, sp188.unk10) * (f64) temp_f26_2338;
        sp98 = temp_f0_2340;
        spD8 = temp_f0_2340;
        spA0 = (f32) sp1A0 * temp_f26_2338;
        spE0 = (f64) spA0;
        temp_f0_2350 = temp_f0_2340 * (f64) temp_f31_2337;
        sp88 = temp_f0_2350;
        spE8 = temp_f0_2350;
        sp90 = (f32) spE0 * temp_f31_2337;
        spF0 = (f64) sp90;
        temp_f0_2361 = sp1D8 - temp_f0_2350;
        sp78 = temp_f0_2361;
        spF8 = temp_f0_2361;
        sp80 = temp_f2_2319 - (f32) spF0;
        sp100 = (f64) sp80;
        MKSetPositionV(*((MKVector3 *) &spF8));
        MKRand_Float(&gViewSeed, 0.0f, 30.000002f);
        MKSetColorV(this->unkE0);
        MKSetTexCoord1F(temp_f20_2327, 0.05f);
        temp_f30_2387 = MKRand_Float(&gViewSeed, 1.0f, 4.0f);
        temp_f27_2388 = this->unkB4 * 0.5f;
        temp_f0_2390 = M2C_BITWISE(f64, sp188.unk10) * (f64) temp_f27_2388;
        sp68 = temp_f0_2390;
        spA8 = temp_f0_2390;
        sp70 = (f32) sp1A0 * temp_f27_2388;
        spB0 = (f64) sp70;
        temp_f0_2400 = temp_f0_2390 * (f64) temp_f30_2387;
        sp58 = temp_f0_2400;
        spB8 = temp_f0_2400;
        sp60 = (f32) spB0 * temp_f30_2387;
        spC0 = (f64) sp60;
        temp_f0_2411 = sp1D8 + temp_f0_2400;
        sp48 = temp_f0_2411;
        spC8 = temp_f0_2411;
        sp50 = sp1E0 + (f32) spC0;
        spD0 = (f64) sp50;
        MKSetPositionV(*((MKVector3 *) &spC8));
        var_r30_1969 += 1;
        goto loop_65;
    }
    MKEnd();
    MKEndPrimitive();
}
#endif

#if 0 // DRAFT: undefined identifier 'fabs'
void ElementalSpline::DrawIceSpline(float arg0, float arg1) {
    Matrix sp200;
    M2C_UNK sp1FC;
    f32 sp1F0;
    f32 sp1EC;
    f32 sp1E8;
    f64 sp1E0;                                      /* compiler-managed */
    f64 sp1D8;
    f64 sp1D0;
    f64 sp1C8;
    f64 sp1C0;                                      /* compiler-managed */
    f64 sp1B8;                                      /* compiler-managed */
    f64 sp1B0;                                      /* compiler-managed */
    f64 sp1A8;                                      /* compiler-managed */
    f64 sp1A0;
    KDUniformSpline sp188;
    f64 sp178;
    f64 sp168;
    f64 sp158;
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
    f64 spF0;
    f64 spE8;
    f64 spE0;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    f64 spC0;
    f64 spB8;
    f64 spB0;
    f64 spA8;
    f32 spA0;
    f64 sp98;
    f32 sp90;
    f64 sp88;
    f32 sp80;
    f64 sp78;
    f32 sp70;
    f64 sp68;
    f32 sp60;
    f64 sp58;
    f32 sp50;
    f64 sp48;
    f32 sp40;
    f64 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 temp_f20_2919;
    f32 temp_f26_2930;
    f32 temp_f27_2980;
    f32 temp_f2_2911;
    f32 temp_f30_2979;
    f32 temp_f31_2929;
    f32 temp_f7_2872;
    f32 temp_f8_2870;
    f32 temp_f9_2869;
    f32 var_f1_2570;
    f32 var_f1_2583;
    f32 var_f1_2603;
    f32 var_f1_2616;
    f32 var_f1_2643;
    f32 var_f1_2670;
    f32 var_f3_2861;
    f32 var_f4_2706;
    f32 var_f5_2773;
    f32 var_f6_2790;
    f64 temp_f0_2932;
    f64 temp_f0_2942;
    f64 temp_f0_2953;
    f64 temp_f0_2982;
    f64 temp_f0_2992;
    f64 temp_f0_3003;
    f64 temp_f1_2712;
    f64 temp_f1_2718;
    f64 temp_f1_2722;
    f64 temp_f1_2800;
    f64 temp_f1_2806;
    f64 temp_f1_2810;
    s32 temp_r0_2539;
    s32 temp_r3_2741;
    s32 temp_r3_2829;
    s32 var_r0_2751;
    s32 var_r0_2839;
    s32 var_r30_2561;
    s32 var_r31_2524;
    s32 var_r4_2532;
    void *temp_r3_2877;
    void *temp_r6_2515;

    M2C_STRUCT_COPY((s32) &sp1FC + 4, (s32) &this->unk4C + 4, 0x40);
    temp_r6_2515 = M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 8);
    sp1C8 = M2C_FIELD(temp_r6_2515, f64 *, 0x30);
    sp1D0 = M2C_FIELD(temp_r6_2515, f64 *, 0x38);
    sp1E8 = 1.0f;
    sp1EC = 1.0f;
    sp1F0 = 1.0f;
    sp200.Scale3x3(&sp200, *((MKVector3 *) &sp1E8));
    var_r31_2524 = this->unk114;
    var_r4_2532 = lit_922;
    temp_r0_2539 = (s32) ((f32) var_r31_2524 * (f32) fabs(arg1 - arg0));
    if (temp_r0_2539 > var_r4_2532) {
        var_r4_2532 = temp_r0_2539;
    }
    if (var_r4_2532 < var_r31_2524) {
        var_r31_2524 = var_r4_2532;
    }
    MKMaterial_SetMaterial(this->unkF4);
    MKPrimitive(0xC, 0x10);
    MKSetMatrix(sp200);
    MKBegin((var_r31_2524 + 1) * 2);
    var_r30_2561 = 0;
loop_65:
    if (var_r30_2561 < (s32) (var_r31_2524 + 1)) {
        if (var_r30_2561 == var_r31_2524) {
            var_f1_2570 = 1.0f;
            if (arg1 < var_f1_2570) {
                var_f1_2570 = arg1;
            }
            sp20 = 0.0f;
            sp188.GetMeasure(var_f1_2570, ((u8 *) this->unkB0) + 0x30, KDSpline_PositionMixer);
            var_f1_2583 = 1.0f;
            sp1D8 = M2C_BITWISE(f64, sp188);
            sp1E0 = (f64) sp188.unk8;
            if (arg1 < var_f1_2583) {
                var_f1_2583 = arg1;
            }
            ((KDSplinePathSegment *) &sp178)->GetVelocity(var_f1_2583);
            sp1A8 = sp178;
            sp1B0 = sp180;
        } else if (var_r30_2561 == 0) {
            var_f1_2603 = 1.0f;
            if (arg0 < var_f1_2603) {
                var_f1_2603 = arg0;
            }
            sp1C = 0.0f;
            ((KDUniformSpline *) &sp168)->GetMeasure(var_f1_2603, ((u8 *) this->unkB0) + 0x30, KDSpline_PositionMixer);
            var_f1_2616 = 1.0f;
            sp1D8 = sp168;
            sp1E0 = sp170;
            if (arg0 < var_f1_2616) {
                var_f1_2616 = arg0;
            }
            ((KDSplinePathSegment *) &sp158)->GetVelocity(var_f1_2616);
            sp1A8 = sp158;
            sp1B0 = sp160;
        } else {
            var_f1_2643 = ((f32) var_r30_2561 * this->unkFC) + arg0;
            if (var_f1_2643 < 1.0f) {

            } else {
                var_f1_2643 = 1.0f;
            }
            sp18 = 0.0f;
            ((KDUniformSpline *) &sp148)->GetMeasure(var_f1_2643, ((u8 *) this->unkB0) + 0x30, KDSpline_PositionMixer);
            sp1D8 = sp148;
            var_f1_2670 = ((f32) var_r30_2561 * this->unkFC) + arg0;
            sp1E0 = sp150;
            if (var_f1_2670 < 1.0f) {

            } else {
                var_f1_2670 = 1.0f;
            }
            ((KDSplinePathSegment *) &sp138)->GetVelocity(var_f1_2670);
            sp1A8 = sp138;
            sp1B0 = sp140;
        }
        sp38 = sp1D8 - sp1C8;
        sp1B8 = sp38;
        sp40 = (f32) sp1E0 - (f32) sp1D0;
        sp1C0 = (f64) sp40;
        sp128 = sp38;
        sp130 = (f64) sp40;
        var_f4_2706 = ((f32) sp1C0 * (f32) sp1C0) + (((f32) sp1B8 * (f32) sp1B8) + ((*(f32 *) ((u8 *) &sp1A0 + 0x1c)) * (*(f32 *) ((u8 *) &sp1A0 + 0x1c))));
        if (var_f4_2706 > 0.000001f) {
            if (var_f4_2706 > 0.0f) {
                temp_f1_2712 = __frsqrte(var_f4_2706);
                temp_f1_2718 = 0.5 * temp_f1_2712 * -(((f64) var_f4_2706 * (temp_f1_2712 * temp_f1_2712)) - 3.0);
                temp_f1_2722 = 0.5 * temp_f1_2718 * -(((f64) var_f4_2706 * (temp_f1_2718 * temp_f1_2718)) - 3.0);
                var_f4_2706 = (f32) ((f64) var_f4_2706 * (0.5 * temp_f1_2722 * -(((f64) var_f4_2706 * (temp_f1_2722 * temp_f1_2722)) - 3.0)));
            } else if (var_f4_2706 < M2C_BITWISE(f32, 0.0)) {
                var_f4_2706 = __float_nan;
            } else {
                sp14 = var_f4_2706;
                temp_r3_2741 = M2C_BITWISE(s32, sp14) & 0x7F800000;
                switch (temp_r3_2741) {             /* switch 1; irregular */
                case 0x7F800000:                    /* switch 1 */
                    if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                        var_r0_2751 = 1;
                    } else {
                        var_r0_2751 = 2;
                    }
                    break;
                case 0x0:                           /* switch 1 */
                    if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                        var_r0_2751 = 5;
                    } else {
                        var_r0_2751 = 3;
                    }
                    break;
                default:                            /* switch 1 */
                    var_r0_2751 = 4;
                    break;
                }
                if (var_r0_2751 == 1) {
                    var_f4_2706 = __float_nan;
                }
            }
            var_f5_2773 = 1.0f / var_f4_2706;
        } else {
            var_f5_2773 = 0.0f;
        }
        var_f6_2790 = ((f32) sp1B0 * (f32) sp1B0) + (((f32) sp1A8 * (f32) sp1A8) + ((*(f32 *) ((u8 *) &sp1A0 + 0xc)) * (*(f32 *) ((u8 *) &sp1A0 + 0xc))));
        sp1B8 = (f32) sp1B8 * var_f5_2773;
        (*(f32 *) ((u8 *) &sp1A0 + 0x1c)) *= var_f5_2773;
        sp1C0 = (f32) sp1C0 * var_f5_2773;
        if (var_f6_2790 > 0.000001f) {
            if (var_f6_2790 > 0.0f) {
                temp_f1_2800 = __frsqrte(var_f6_2790);
                temp_f1_2806 = 0.5 * temp_f1_2800 * -(((f64) var_f6_2790 * (temp_f1_2800 * temp_f1_2800)) - 3.0);
                temp_f1_2810 = 0.5 * temp_f1_2806 * -(((f64) var_f6_2790 * (temp_f1_2806 * temp_f1_2806)) - 3.0);
                var_f6_2790 = (f32) ((f64) var_f6_2790 * (0.5 * temp_f1_2810 * -(((f64) var_f6_2790 * (temp_f1_2810 * temp_f1_2810)) - 3.0)));
            } else if (var_f6_2790 < M2C_BITWISE(f32, 0.0)) {
                var_f6_2790 = __float_nan;
            } else {
                sp10 = var_f6_2790;
                temp_r3_2829 = M2C_BITWISE(s32, sp10) & 0x7F800000;
                switch (temp_r3_2829) {             /* switch 2; irregular */
                case 0x7F800000:                    /* switch 2 */
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_2839 = 1;
                    } else {
                        var_r0_2839 = 2;
                    }
                    break;
                case 0x0:                           /* switch 2 */
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_2839 = 5;
                    } else {
                        var_r0_2839 = 3;
                    }
                    break;
                default:                            /* switch 2 */
                    var_r0_2839 = 4;
                    break;
                }
                if (var_r0_2839 == 1) {
                    var_f6_2790 = __float_nan;
                }
            }
            var_f3_2861 = 1.0f / var_f6_2790;
        } else {
            var_f3_2861 = 0.0f;
        }
        temp_f9_2869 = (f32) sp1A8 * var_f3_2861;
        temp_f8_2870 = (*(f32 *) ((u8 *) &sp1A0 + 0xc)) * var_f3_2861;
        temp_f7_2872 = (f32) sp1B0 * var_f3_2861;
        temp_r3_2877 = this->unk8;
        sp1A8 = temp_f9_2869;
        sp2C = (temp_f7_2872 * sp1B8) - (temp_f9_2869 * sp1C0);
        sp28 = (temp_f8_2870 * sp1C0) - (temp_f7_2872 * (*(f32 *) ((u8 *) &sp1A0 + 0x1c)));
        sp30 = (temp_f9_2869 * (*(f32 *) ((u8 *) &sp1A0 + 0x1c))) - (temp_f8_2870 * sp1B8);
        sp108 = M2C_FIELD(temp_r3_2877, f64 *, 0x30);
        (*(f32 *) ((u8 *) &sp1A0 + 0xc)) = temp_f8_2870;
        sp1B0 = temp_f7_2872;
        sp118 = (f64) sp28;
        sp120 = (f64) sp30;
        sp188.unk10 = (f64) sp28;
        sp1A0 = (f64) sp30;
        sp110 = M2C_FIELD(temp_r3_2877, f64 *, 0x38);
        sp1D8 -= sp108;
        temp_f2_2911 = (f32) sp1E0 - (f32) sp110;
        sp1E0 = temp_f2_2911;
        temp_f20_2919 = 4.0f * ((f32) var_r30_2561 / (f32) this->unk114);
        MKSetColorV(this->unkE0);
        MKSetTexCoord1F(temp_f20_2919, 0.95f);
        temp_f31_2929 = MKRand_Float(&gViewSeed, 1.0f, 2.0f);
        temp_f26_2930 = this->unkB4 * 0.5f;
        temp_f0_2932 = M2C_BITWISE(f64, sp188.unk10) * (f64) temp_f26_2930;
        sp98 = temp_f0_2932;
        spD8 = temp_f0_2932;
        spA0 = (f32) sp1A0 * temp_f26_2930;
        spE0 = (f64) spA0;
        temp_f0_2942 = temp_f0_2932 * (f64) temp_f31_2929;
        sp88 = temp_f0_2942;
        spE8 = temp_f0_2942;
        sp90 = (f32) spE0 * temp_f31_2929;
        spF0 = (f64) sp90;
        temp_f0_2953 = sp1D8 - temp_f0_2942;
        sp78 = temp_f0_2953;
        spF8 = temp_f0_2953;
        sp80 = temp_f2_2911 - (f32) spF0;
        sp100 = (f64) sp80;
        MKSetPositionV(*((MKVector3 *) &spF8));
        MKRand_Float(&gViewSeed, 0.0f, 30.000002f);
        MKSetColorV(this->unkE0);
        MKSetTexCoord1F(temp_f20_2919, 0.05f);
        temp_f30_2979 = MKRand_Float(&gViewSeed, 1.0f, 2.0f);
        temp_f27_2980 = this->unkB4 * 0.5f;
        temp_f0_2982 = M2C_BITWISE(f64, sp188.unk10) * (f64) temp_f27_2980;
        sp68 = temp_f0_2982;
        spA8 = temp_f0_2982;
        sp70 = (f32) sp1A0 * temp_f27_2980;
        spB0 = (f64) sp70;
        temp_f0_2992 = temp_f0_2982 * (f64) temp_f30_2979;
        sp58 = temp_f0_2992;
        spB8 = temp_f0_2992;
        sp60 = (f32) spB0 * temp_f30_2979;
        spC0 = (f64) sp60;
        temp_f0_3003 = sp1D8 + temp_f0_2992;
        sp48 = temp_f0_3003;
        spC8 = temp_f0_3003;
        sp50 = sp1E0 + (f32) spC0;
        spD0 = (f64) sp50;
        MKSetPositionV(*((MKVector3 *) &spC8));
        var_r30_2561 += 1;
        goto loop_65;
    }
    MKEnd();
    MKEndPrimitive();
}
#endif

#if 0 // DRAFT: undefined identifier 'fabs'
void ElementalSpline::DrawElectricitySpline(float arg0, float arg1) {
    Matrix sp1B0;
    M2C_UNK sp1AC;
    f32 sp1A8;
    f32 sp1A4;
    f32 sp1A0;
    f64 sp198;                                      /* compiler-managed */
    f64 sp190;
    f64 sp188;
    f64 sp180;
    f64 sp178;                                      /* compiler-managed */
    f64 sp170;                                      /* compiler-managed */
    f64 sp168;                                      /* compiler-managed */
    f64 sp160;                                      /* compiler-managed */
    f64 sp158;
    KDUniformSpline sp140;
    f64 sp130;
    f64 sp120;
    f64 sp110;
    f64 sp108;
    f64 sp100;
    f64 spF0;
    MKVector3 spE0;
    f64 spD0;
    f64 spC0;
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
    f64 sp60;
    f32 sp58;
    f64 sp50;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp38;
    f64 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 temp_f22_3537;
    f32 temp_f2_3504;
    f32 temp_f30_3544;
    f32 temp_f31_3507;
    f32 temp_f7_3472;
    f32 temp_f8_3470;
    f32 temp_f9_3469;
    f32 var_f1_3158;
    f32 var_f1_3171;
    f32 var_f1_3191;
    f32 var_f1_3204;
    f32 var_f1_3237;
    f32 var_f1_3270;
    f32 var_f3_3461;
    f32 var_f4_3306;
    f32 var_f5_3373;
    f32 var_f6_3390;
    f64 temp_f0_3509;
    f64 temp_f0_3546;
    f64 temp_f1_3312;
    f64 temp_f1_3318;
    f64 temp_f1_3322;
    f64 temp_f1_3400;
    f64 temp_f1_3406;
    f64 temp_f1_3410;
    f64 temp_f3_3500;
    s32 temp_r0_3127;
    s32 temp_r3_3341;
    s32 temp_r3_3429;
    s32 var_r0_3351;
    s32 var_r0_3439;
    s32 var_r30_3149;
    s32 var_r31_3112;
    s32 var_r4_3120;
    void *temp_r3_3477;
    void *temp_r6_3103;

    M2C_STRUCT_COPY((s32) &sp1AC + 4, (s32) &this->unk4C + 4, 0x40);
    temp_r6_3103 = M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 8);
    sp180 = M2C_FIELD(temp_r6_3103, f64 *, 0x30);
    sp188 = M2C_FIELD(temp_r6_3103, f64 *, 0x38);
    sp1A0 = 1.0f;
    sp1A4 = 1.0f;
    sp1A8 = 1.0f;
    sp1B0.Scale3x3(&sp1B0, *((MKVector3 *) &sp1A0));
    var_r31_3112 = this->unk114;
    var_r4_3120 = lit_878;
    temp_r0_3127 = (s32) ((f32) var_r31_3112 * (f32) fabs(arg1 - arg0));
    if (temp_r0_3127 > var_r4_3120) {
        var_r4_3120 = temp_r0_3127;
    }
    if (var_r4_3120 < var_r31_3112) {
        var_r31_3112 = var_r4_3120;
    }
    MKMaterial_SetMaterial(this->unkF4);
    MKPrimitive(0xC, 0x10);
    MKSetMatrix(sp1B0);
    MKBegin((var_r31_3112 + 1) * 2);
    var_r30_3149 = 0;
loop_65:
    if (var_r30_3149 < (s32) (var_r31_3112 + 1)) {
        if (var_r30_3149 == var_r31_3112) {
            var_f1_3158 = 1.0f;
            if (arg1 < var_f1_3158) {
                var_f1_3158 = arg1;
            }
            sp1C = 0.0f;
            sp140.GetMeasure(var_f1_3158, ((u8 *) this->unkB0) + 0x30, KDSpline_PositionMixer);
            var_f1_3171 = 1.0f;
            sp190 = M2C_BITWISE(f64, sp140);
            sp198 = (f64) sp140.unk8;
            if (arg1 < var_f1_3171) {
                var_f1_3171 = arg1;
            }
            ((KDSplinePathSegment *) &sp130)->GetVelocity(var_f1_3171);
            sp160 = sp130;
            sp168 = sp138;
        } else if (var_r30_3149 == 0) {
            var_f1_3191 = 1.0f;
            if (arg0 < var_f1_3191) {
                var_f1_3191 = arg0;
            }
            sp18 = 0.0f;
            ((KDUniformSpline *) &sp120)->GetMeasure(var_f1_3191, ((u8 *) this->unkB0) + 0x30, KDSpline_PositionMixer);
            var_f1_3204 = 1.0f;
            sp190 = sp120;
            sp198 = sp128;
            if (arg0 < var_f1_3204) {
                var_f1_3204 = arg0;
            }
            ((KDSplinePathSegment *) &sp110)->GetVelocity(var_f1_3204);
            sp160 = sp110;
            sp168 = sp118;
        } else {
            KDRand_UnitVector();
            spE0.operator*(this->unkB4);
            var_f1_3237 = ((f32) var_r30_3149 * this->unkFC) + arg0;
            if (var_f1_3237 < 1.0f) {

            } else {
                var_f1_3237 = 1.0f;
            }
            ((KDSplinePathSegment *) &spF0)->GetPosition(var_f1_3237);
            sp60 = spF0 + M2C_BITWISE(f64, spE0);
            sp68 = spF8 + spE0.unk8;
            sp190 = sp60;
            sp198 = (f64) sp68;
            sp100 = sp60;
            var_f1_3270 = ((f32) var_r30_3149 * this->unkFC) + arg0;
            sp108 = (f64) sp68;
            if (var_f1_3270 < 1.0f) {

            } else {
                var_f1_3270 = 1.0f;
            }
            ((KDSplinePathSegment *) &spC0)->GetVelocity(var_f1_3270);
            sp160 = spC0;
            sp168 = spC8;
        }
        sp50 = sp190 - sp180;
        sp170 = sp50;
        sp58 = (f32) sp198 - (f32) sp188;
        sp178 = (f64) sp58;
        spB0 = sp50;
        spB8 = (f64) sp58;
        var_f4_3306 = ((f32) sp178 * (f32) sp178) + (((f32) sp170 * (f32) sp170) + ((*(f32 *) ((u8 *) &sp158 + 0x1c)) * (*(f32 *) ((u8 *) &sp158 + 0x1c))));
        if (var_f4_3306 > 0.000001f) {
            if (var_f4_3306 > 0.0f) {
                temp_f1_3312 = __frsqrte(var_f4_3306);
                temp_f1_3318 = 0.5 * temp_f1_3312 * -(((f64) var_f4_3306 * (temp_f1_3312 * temp_f1_3312)) - 3.0);
                temp_f1_3322 = 0.5 * temp_f1_3318 * -(((f64) var_f4_3306 * (temp_f1_3318 * temp_f1_3318)) - 3.0);
                var_f4_3306 = (f32) ((f64) var_f4_3306 * (0.5 * temp_f1_3322 * -(((f64) var_f4_3306 * (temp_f1_3322 * temp_f1_3322)) - 3.0)));
            } else if (var_f4_3306 < M2C_BITWISE(f32, 0.0)) {
                var_f4_3306 = __float_nan;
            } else {
                sp14 = var_f4_3306;
                temp_r3_3341 = M2C_BITWISE(s32, sp14) & 0x7F800000;
                switch (temp_r3_3341) {             /* switch 1; irregular */
                case 0x7F800000:                    /* switch 1 */
                    if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                        var_r0_3351 = 1;
                    } else {
                        var_r0_3351 = 2;
                    }
                    break;
                case 0x0:                           /* switch 1 */
                    if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                        var_r0_3351 = 5;
                    } else {
                        var_r0_3351 = 3;
                    }
                    break;
                default:                            /* switch 1 */
                    var_r0_3351 = 4;
                    break;
                }
                if (var_r0_3351 == 1) {
                    var_f4_3306 = __float_nan;
                }
            }
            var_f5_3373 = 1.0f / var_f4_3306;
        } else {
            var_f5_3373 = 0.0f;
        }
        var_f6_3390 = ((f32) sp168 * (f32) sp168) + (((f32) sp160 * (f32) sp160) + ((*(f32 *) ((u8 *) &sp158 + 0xc)) * (*(f32 *) ((u8 *) &sp158 + 0xc))));
        sp170 = (f32) sp170 * var_f5_3373;
        (*(f32 *) ((u8 *) &sp158 + 0x1c)) *= var_f5_3373;
        sp178 = (f32) sp178 * var_f5_3373;
        if (var_f6_3390 > 0.000001f) {
            if (var_f6_3390 > 0.0f) {
                temp_f1_3400 = __frsqrte(var_f6_3390);
                temp_f1_3406 = 0.5 * temp_f1_3400 * -(((f64) var_f6_3390 * (temp_f1_3400 * temp_f1_3400)) - 3.0);
                temp_f1_3410 = 0.5 * temp_f1_3406 * -(((f64) var_f6_3390 * (temp_f1_3406 * temp_f1_3406)) - 3.0);
                var_f6_3390 = (f32) ((f64) var_f6_3390 * (0.5 * temp_f1_3410 * -(((f64) var_f6_3390 * (temp_f1_3410 * temp_f1_3410)) - 3.0)));
            } else if (var_f6_3390 < M2C_BITWISE(f32, 0.0)) {
                var_f6_3390 = __float_nan;
            } else {
                sp10 = var_f6_3390;
                temp_r3_3429 = M2C_BITWISE(s32, sp10) & 0x7F800000;
                switch (temp_r3_3429) {             /* switch 2; irregular */
                case 0x7F800000:                    /* switch 2 */
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_3439 = 1;
                    } else {
                        var_r0_3439 = 2;
                    }
                    break;
                case 0x0:                           /* switch 2 */
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_3439 = 5;
                    } else {
                        var_r0_3439 = 3;
                    }
                    break;
                default:                            /* switch 2 */
                    var_r0_3439 = 4;
                    break;
                }
                if (var_r0_3439 == 1) {
                    var_f6_3390 = __float_nan;
                }
            }
            var_f3_3461 = 1.0f / var_f6_3390;
        } else {
            var_f3_3461 = 0.0f;
        }
        temp_f9_3469 = (f32) sp160 * var_f3_3461;
        temp_f8_3470 = (*(f32 *) ((u8 *) &sp158 + 0xc)) * var_f3_3461;
        temp_f7_3472 = (f32) sp168 * var_f3_3461;
        temp_r3_3477 = this->unk8;
        sp160 = temp_f9_3469;
        sp44 = (temp_f7_3472 * sp170) - (temp_f9_3469 * sp178);
        sp40 = (temp_f8_3470 * sp178) - (temp_f7_3472 * (*(f32 *) ((u8 *) &sp158 + 0x1c)));
        sp48 = (temp_f9_3469 * (*(f32 *) ((u8 *) &sp158 + 0x1c))) - (temp_f8_3470 * sp170);
        sp90 = M2C_FIELD(temp_r3_3477, f64 *, 0x30);
        (*(f32 *) ((u8 *) &sp158 + 0xc)) = temp_f8_3470;
        sp168 = temp_f7_3472;
        spA0 = (f64) sp40;
        spA8 = (f64) sp48;
        sp140.unk10 = (f64) sp40;
        sp158 = (f64) sp48;
        sp98 = M2C_FIELD(temp_r3_3477, f64 *, 0x38);
        temp_f3_3500 = sp190 - sp90;
        sp190 = temp_f3_3500;
        temp_f2_3504 = (f32) sp198 - (f32) sp98;
        sp198 = temp_f2_3504;
        temp_f31_3507 = this->unkB4 * 0.5f;
        temp_f0_3509 = M2C_BITWISE(f64, sp140.unk10) * (f64) temp_f31_3507;
        sp30 = temp_f0_3509;
        sp80 = temp_f0_3509;
        sp38 = (f32) sp158 * temp_f31_3507;
        sp88 = (f64) sp38;
        sp190 = temp_f3_3500 - temp_f0_3509;
        sp198 = temp_f2_3504 - (f32) sp88;
        temp_f22_3537 = 4.0f * ((f32) var_r30_3149 / (f32) this->unk114);
        MKSetColorV(this->unkE0);
        MKSetTexCoord1F(temp_f22_3537, 0.95f);
        MKSetPositionV(*((MKVector3 *) &sp190));
        temp_f30_3544 = this->unkB4;
        temp_f0_3546 = M2C_BITWISE(f64, sp140.unk10) * (f64) temp_f30_3544;
        sp20 = temp_f0_3546;
        sp70 = temp_f0_3546;
        sp28 = (f32) sp158 * temp_f30_3544;
        sp78 = (f64) sp28;
        sp190 += temp_f0_3546;
        sp198 += (f32) sp78;
        MKRand_Float(&gViewSeed, 0.0f, 30.000002f);
        MKSetColorV(this->unkE0);
        MKSetTexCoord1F(temp_f22_3537, 0.05f);
        MKSetPositionV(*((MKVector3 *) &sp190));
        var_r30_3149 += 1;
        goto loop_65;
    }
    MKEnd();
    MKEndPrimitive();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_812'
void ElementalSpline::DrawFireSpline(float arg0, float arg1) {
    s32 sp304;
    s32 sp300;
    Matrix sp2C0;
    M2C_UNK sp2BC;
    f32 sp2B0;
    f32 sp2AC;
    f32 sp2A8;
    f64 sp2A0;                                      /* compiler-managed */
    f64 sp298;
    f64 sp290;
    f64 sp288;
    f64 sp280;                                      /* compiler-managed */
    f64 sp278;                                      /* compiler-managed */
    f64 sp270;                                      /* compiler-managed */
    f64 sp268;                                      /* compiler-managed */
    f64 sp260;
    KDUniformSpline sp248;
    f64 sp238;
    f64 sp228;
    f64 sp218;
    f64 sp208;
    f64 sp1F8;
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
    f64 sp148;
    f64 sp140;
    f64 sp138;
    f64 sp130;
    f64 sp128;
    f64 sp120;
    f64 sp118;
    f64 sp110;
    f64 sp108;
    f32 sp104;
    f32 sp100;
    f32 spFC;
    f32 spF8;
    f32 spF0;
    f64 spE8;
    f32 spE0;
    f64 spD8;
    f32 spD0;
    f64 spC8;
    f32 spC0;
    f64 spB8;
    f32 spB4;
    f32 spB0;
    f32 spAC;
    f32 spA8;
    f32 spA0;
    f64 sp98;
    f32 sp90;
    f64 sp88;
    f32 sp80;
    f64 sp78;
    f32 sp70;
    f64 sp68;
    f32 sp60;
    f64 sp58;
    f32 sp50;
    f64 sp48;
    f32 sp40;
    f64 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 temp_f17_4085;
    f32 temp_f23_4097;
    f32 temp_f24_4126;
    f32 temp_f25_4182;
    f32 temp_f26_4226;
    f32 temp_f27_4180;
    f32 temp_f31_4224;
    f32 temp_f7_4029;
    f32 temp_f8_4027;
    f32 temp_f9_4026;
    f32 var_f0_3947;
    f32 var_f1_3727;
    f32 var_f1_3740;
    f32 var_f1_3760;
    f32 var_f1_3773;
    f32 var_f1_3800;
    f32 var_f1_3827;
    f32 var_f2_3677;
    f32 var_f3_4018;
    f32 var_f4_3863;
    f32 var_f5_3930;
    f64 temp_f0_4099;
    f64 temp_f0_4110;
    f64 temp_f0_4128;
    f64 temp_f0_4139;
    f64 temp_f0_4184;
    f64 temp_f0_4194;
    f64 temp_f0_4205;
    f64 temp_f0_4228;
    f64 temp_f0_4238;
    f64 temp_f0_4249;
    f64 temp_f1_3869;
    f64 temp_f1_3875;
    f64 temp_f1_3879;
    f64 temp_f2_3957;
    f64 temp_f2_3963;
    f64 temp_f2_3967;
    s32 temp_r0_3695;
    s32 temp_r0_4060;
    s32 temp_r3_3898;
    s32 temp_r3_3986;
    s32 var_r0_3908;
    s32 var_r0_3996;
    s32 var_r30_3717;
    s32 var_r31_3683;
    s32 var_r4_3689;
    void *temp_r3_4034;
    void *temp_r6_3668;

    M2C_STRUCT_COPY((s32) &sp2BC + 4, (s32) &this->unk4C + 4, 0x40);
    temp_r6_3668 = M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 8);
    sp288 = M2C_FIELD(temp_r6_3668, f64 *, 0x30);
    sp290 = M2C_FIELD(temp_r6_3668, f64 *, 0x38);
    sp2A8 = 1.0f;
    sp2AC = 1.0f;
    sp2B0 = 1.0f;
    sp2C0.Scale3x3(&sp2C0, *((MKVector3 *) &sp2A8));
    var_f2_3677 = arg1 - arg0;
    if (var_f2_3677 < 0.0f) {
        var_f2_3677 = -var_f2_3677;
    }
    var_r31_3683 = this->unk114;
    var_r4_3689 = lit_812;
    temp_r0_3695 = (s32) ((f32) var_r31_3683 * var_f2_3677);
    if (temp_r0_3695 > var_r4_3689) {
        var_r4_3689 = temp_r0_3695;
    }
    if (var_r4_3689 < var_r31_3683) {
        var_r31_3683 = var_r4_3689;
    }
    MKMaterial_SetMaterial(this->unkF4);
    MKPrimitive(0xC, 0x10);
    MKSetMatrix(sp2C0);
    MKBegin((var_r31_3683 + 1) * 2);
    var_r30_3717 = 0;
loop_73:
    if (var_r30_3717 < (s32) (var_r31_3683 + 1)) {
        if (var_r30_3717 == var_r31_3683) {
            var_f1_3727 = 1.0f;
            if (arg1 < var_f1_3727) {
                var_f1_3727 = arg1;
            }
            sp20 = 0.0f;
            sp248.GetMeasure(var_f1_3727, ((u8 *) this->unkB0) + 0x30, KDSpline_PositionMixer);
            var_f1_3740 = 1.0f;
            sp298 = M2C_BITWISE(f64, sp248);
            sp2A0 = (f64) sp248.unk8;
            if (arg1 < var_f1_3740) {
                var_f1_3740 = arg1;
            }
            ((KDSplinePathSegment *) &sp238)->GetVelocity(var_f1_3740);
            sp268 = sp238;
            sp270 = sp240;
        } else if (var_r30_3717 == 0) {
            var_f1_3760 = 1.0f;
            if (arg0 < var_f1_3760) {
                var_f1_3760 = arg0;
            }
            sp1C = 0.0f;
            ((KDUniformSpline *) &sp228)->GetMeasure(var_f1_3760, ((u8 *) this->unkB0) + 0x30, KDSpline_PositionMixer);
            var_f1_3773 = 1.0f;
            sp298 = sp228;
            sp2A0 = sp230;
            if (arg0 < var_f1_3773) {
                var_f1_3773 = arg0;
            }
            ((KDSplinePathSegment *) &sp218)->GetVelocity(var_f1_3773);
            sp268 = sp218;
            sp270 = sp220;
        } else {
            var_f1_3800 = ((f32) var_r30_3717 * this->unkFC) + arg0;
            if (var_f1_3800 < 1.0f) {

            } else {
                var_f1_3800 = 1.0f;
            }
            sp18 = 0.0f;
            ((KDUniformSpline *) &sp208)->GetMeasure(var_f1_3800, ((u8 *) this->unkB0) + 0x30, KDSpline_PositionMixer);
            sp298 = sp208;
            var_f1_3827 = ((f32) var_r30_3717 * this->unkFC) + arg0;
            sp2A0 = sp210;
            if (var_f1_3827 < 1.0f) {

            } else {
                var_f1_3827 = 1.0f;
            }
            ((KDSplinePathSegment *) &sp1F8)->GetVelocity(var_f1_3827);
            sp268 = sp1F8;
            sp270 = sp200;
        }
        sp38 = sp298 - sp288;
        sp278 = sp38;
        sp40 = (f32) sp2A0 - (f32) sp290;
        sp280 = (f64) sp40;
        sp1E8 = sp38;
        sp1F0 = (f64) sp40;
        var_f4_3863 = ((f32) sp280 * (f32) sp280) + (((f32) sp278 * (f32) sp278) + ((*(f32 *) ((u8 *) &sp260 + 0x1c)) * (*(f32 *) ((u8 *) &sp260 + 0x1c))));
        if (var_f4_3863 > 0.000001f) {
            if (var_f4_3863 > 0.0f) {
                temp_f1_3869 = __frsqrte(var_f4_3863);
                temp_f1_3875 = 0.5 * temp_f1_3869 * -(((f64) var_f4_3863 * (temp_f1_3869 * temp_f1_3869)) - 3.0);
                temp_f1_3879 = 0.5 * temp_f1_3875 * -(((f64) var_f4_3863 * (temp_f1_3875 * temp_f1_3875)) - 3.0);
                var_f4_3863 = (f32) ((f64) var_f4_3863 * (0.5 * temp_f1_3879 * -(((f64) var_f4_3863 * (temp_f1_3879 * temp_f1_3879)) - 3.0)));
            } else if (var_f4_3863 < M2C_BITWISE(f32, 0.0)) {
                var_f4_3863 = __float_nan;
            } else {
                sp14 = var_f4_3863;
                temp_r3_3898 = M2C_BITWISE(s32, sp14) & 0x7F800000;
                switch (temp_r3_3898) {             /* switch 1; irregular */
                case 0x7F800000:                    /* switch 1 */
                    if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                        var_r0_3908 = 1;
                    } else {
                        var_r0_3908 = 2;
                    }
                    break;
                case 0x0:                           /* switch 1 */
                    if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                        var_r0_3908 = 5;
                    } else {
                        var_r0_3908 = 3;
                    }
                    break;
                default:                            /* switch 1 */
                    var_r0_3908 = 4;
                    break;
                }
                if (var_r0_3908 == 1) {
                    var_f4_3863 = __float_nan;
                }
            }
            var_f5_3930 = 1.0f / var_f4_3863;
        } else {
            var_f5_3930 = 0.0f;
        }
        var_f0_3947 = ((f32) sp270 * (f32) sp270) + (((f32) sp268 * (f32) sp268) + ((*(f32 *) ((u8 *) &sp260 + 0xc)) * (*(f32 *) ((u8 *) &sp260 + 0xc))));
        sp278 = (f32) sp278 * var_f5_3930;
        (*(f32 *) ((u8 *) &sp260 + 0x1c)) *= var_f5_3930;
        sp280 = (f32) sp280 * var_f5_3930;
        if (var_f0_3947 > 0.000001f) {
            if (var_f0_3947 > 0.0f) {
                temp_f2_3957 = __frsqrte(var_f0_3947);
                temp_f2_3963 = 0.5 * temp_f2_3957 * -(((f64) var_f0_3947 * (temp_f2_3957 * temp_f2_3957)) - 3.0);
                temp_f2_3967 = 0.5 * temp_f2_3963 * -(((f64) var_f0_3947 * (temp_f2_3963 * temp_f2_3963)) - 3.0);
                var_f0_3947 = (f32) ((f64) var_f0_3947 * (0.5 * temp_f2_3967 * -(((f64) var_f0_3947 * (temp_f2_3967 * temp_f2_3967)) - 3.0)));
            } else if (var_f0_3947 < M2C_BITWISE(f32, 0.0)) {
                var_f0_3947 = __float_nan;
            } else {
                sp10 = var_f0_3947;
                temp_r3_3986 = M2C_BITWISE(s32, sp10) & 0x7F800000;
                switch (temp_r3_3986) {             /* switch 2; irregular */
                case 0x7F800000:                    /* switch 2 */
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_3996 = 1;
                    } else {
                        var_r0_3996 = 2;
                    }
                    break;
                case 0x0:                           /* switch 2 */
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_3996 = 5;
                    } else {
                        var_r0_3996 = 3;
                    }
                    break;
                default:                            /* switch 2 */
                    var_r0_3996 = 4;
                    break;
                }
                if (var_r0_3996 == 1) {
                    var_f0_3947 = __float_nan;
                }
            }
            var_f3_4018 = 1.0f / var_f0_3947;
        } else {
            var_f3_4018 = 0.0f;
        }
        temp_f9_4026 = (f32) sp268 * var_f3_4018;
        temp_f8_4027 = (*(f32 *) ((u8 *) &sp260 + 0xc)) * var_f3_4018;
        temp_f7_4029 = (f32) sp270 * var_f3_4018;
        temp_r3_4034 = this->unk8;
        sp268 = temp_f9_4026;
        sp2C = (temp_f7_4029 * sp278) - (temp_f9_4026 * sp280);
        sp28 = (temp_f8_4027 * sp280) - (temp_f7_4029 * (*(f32 *) ((u8 *) &sp260 + 0x1c)));
        sp30 = (temp_f9_4026 * (*(f32 *) ((u8 *) &sp260 + 0x1c))) - (temp_f8_4027 * sp278);
        sp1C8 = M2C_FIELD(temp_r3_4034, f64 *, 0x30);
        (*(f32 *) ((u8 *) &sp260 + 0xc)) = temp_f8_4027;
        sp270 = temp_f7_4029;
        sp1D8 = (f64) sp28;
        sp1E0 = (f64) sp30;
        sp248.unk10 = (f64) sp28;
        sp260 = (f64) sp30;
        sp1D0 = M2C_FIELD(temp_r3_4034, f64 *, 0x38);
        sp298 -= sp1C8;
        temp_r0_4060 = this->unk114;
        sp304 = temp_r0_4060 ^ 0x80000000;
        sp300 = 0x43300000;
        spF8 = this->unkE0.unk0;
        spFC = this->unkE0.unk4;
        sp100 = this->unkE0.unk8;
        sp104 = 0.5f;
        sp2A0 = (f32) sp2A0 - (f32) sp1D0;
        temp_f17_4085 = 4.0f * ((f32) var_r30_3717 / (f32) temp_r0_4060);
        sp1B8 = (f64) spF8;
        sp1C0 = (f64) sp100;
        MKSetColorV(*((MKVector4 *) &sp1B8));
        MKSetTexCoord1F(temp_f17_4085, 0.95f);
        if (sp25C > 0.0f) {
            temp_f23_4097 = this->unkB4 * 0.5f;
            temp_f0_4099 = M2C_BITWISE(f64, sp248.unk10) * (f64) temp_f23_4097;
            spE8 = temp_f0_4099;
            sp198 = temp_f0_4099;
            spF0 = (f32) sp260 * temp_f23_4097;
            sp1A0 = (f64) spF0;
            temp_f0_4110 = sp298 - temp_f0_4099;
            spD8 = temp_f0_4110;
            sp1A8 = temp_f0_4110;
            spE0 = sp2A0 - (f32) sp1A0;
            sp1B0 = (f64) spE0;
            MKSetPositionV(*((MKVector3 *) &sp1A8));
        } else {
            temp_f24_4126 = this->unkB4 * 0.5f;
            temp_f0_4128 = M2C_BITWISE(f64, sp248.unk10) * (f64) temp_f24_4126;
            spC8 = temp_f0_4128;
            sp178 = temp_f0_4128;
            spD0 = (f32) sp260 * temp_f24_4126;
            sp180 = (f64) spD0;
            temp_f0_4139 = sp298 + temp_f0_4128;
            spB8 = temp_f0_4139;
            sp188 = temp_f0_4139;
            spC0 = sp2A0 + (f32) sp180;
            sp190 = (f64) spC0;
            MKSetPositionV(*((MKVector3 *) &sp188));
        }
        MKRand_Float(&gViewSeed, 0.0f, 30.000002f);
        spA8 = this->unkE0.unk0;
        spAC = this->unkE0.unk4;
        spB0 = this->unkE0.unk8;
        spB4 = 0.0f;
        sp168 = (f64) spA8;
        sp170 = (f64) spB0;
        MKSetColorV(*((MKVector4 *) &sp168));
        MKSetTexCoord1F(temp_f17_4085, 0.05f);
        if (sp25C > 0.0f) {
            temp_f27_4180 = MKRand_Float(&gViewSeed, 2.0f, 4.0f);
            temp_f25_4182 = this->unkB4 * 0.5f;
            temp_f0_4184 = M2C_BITWISE(f64, sp248.unk10) * (f64) temp_f25_4182;
            sp98 = temp_f0_4184;
            sp138 = temp_f0_4184;
            spA0 = (f32) sp260 * temp_f25_4182;
            sp140 = (f64) spA0;
            temp_f0_4194 = temp_f0_4184 * (f64) temp_f27_4180;
            sp88 = temp_f0_4194;
            sp148 = temp_f0_4194;
            sp90 = (f32) sp140 * temp_f27_4180;
            sp150 = (f64) sp90;
            temp_f0_4205 = sp298 + temp_f0_4194;
            sp78 = temp_f0_4205;
            sp158 = temp_f0_4205;
            sp80 = sp2A0 + (f32) sp150;
            sp160 = (f64) sp80;
            MKSetPositionV(*((MKVector3 *) &sp158));
        } else {
            temp_f31_4224 = MKRand_Float(&gViewSeed, 2.0f, 4.0f);
            temp_f26_4226 = this->unkB4 * 0.5f;
            temp_f0_4228 = M2C_BITWISE(f64, sp248.unk10) * (f64) temp_f26_4226;
            sp68 = temp_f0_4228;
            sp108 = temp_f0_4228;
            sp70 = (f32) sp260 * temp_f26_4226;
            sp110 = (f64) sp70;
            temp_f0_4238 = temp_f0_4228 * (f64) temp_f31_4224;
            sp58 = temp_f0_4238;
            sp118 = temp_f0_4238;
            sp60 = (f32) sp110 * temp_f31_4224;
            sp120 = (f64) sp60;
            temp_f0_4249 = sp298 - temp_f0_4238;
            sp48 = temp_f0_4249;
            sp128 = temp_f0_4249;
            sp50 = sp2A0 - (f32) sp120;
            sp130 = (f64) sp50;
            MKSetPositionV(*((MKVector3 *) &sp128));
        }
        var_r30_3717 += 1;
        goto loop_73;
    }
    MKEnd();
    MKEndPrimitive();
}
#endif

void ElementalSpline::Draw() {
    f32 var_f30_4321;
    f32 var_f31_4319;
    s32 temp_r0_4352;

    MKProp::Draw();
    var_f31_4319 = 0.0f;
    var_f30_4321 = 0.0f;
    if (((KDStateMachine<ElementalSpline> *) &this->unkC0)->GetState() != 3) {
        if (((KDStateMachine<ElementalSpline> *) &this->unkC0)->GetState() == 1) {
            var_f31_4319 = 0.0f;
            var_f30_4321 = 1.0f;
        } else if (((KDStateMachine<ElementalSpline> *) &this->unkC0)->GetState() == 0) {
            var_f31_4319 = 0.0f;
            var_f30_4321 = this->unk10C / this->unk100;
        } else if (((KDStateMachine<ElementalSpline> *) &this->unkC0)->GetState() == 2) {
            var_f30_4321 = 1.0f;
            var_f31_4319 = this->unk10C / this->unk108;
        }
        temp_r0_4352 = this->unk110;
        switch (temp_r0_4352) {                     /* irregular */
        case 0:
            DrawFireSpline(var_f31_4319, var_f30_4321);
            return;
        case 1:
            DrawElectricitySpline(var_f31_4319, var_f30_4321);
            return;
        case 2:
            DrawIceSpline(var_f31_4319, var_f30_4321);
            return;
        case 3:
            DrawEarthSpline(var_f31_4319, var_f30_4321);
            break;
        }
    }
}

void ElementalSpline::Update() {
    u8 var_r31_4413;

    MKProp::Update();
    ((KDStateMachine<ElementalSpline> *) &this->unkC0)->Update(this, 0);
    var_r31_4413 = 1;
    if ((((KDStateMachine<ElementalSpline> *) &this->unkC0)->GetState() != 1) && (((KDStateMachine<ElementalSpline> *) &this->unkC0)->GetState() != 0)) {
        var_r31_4413 = 0;
    }
    ((KDSound_SoundWall *) &this->unk120)->Update(var_r31_4413);
}

void ElementalSpline::Message(MKMessage *arg0) {
    s32 temp_r0_4444;

    ((KDSound_SoundWall *) &this->unk120)->Message(arg0);
    temp_r0_4444 = arg0->unk0;
    switch (temp_r0_4444) {                         /* irregular */
    case 0xB5:
        if (((KDStateMachine<ElementalSpline> *) &this->unkC0)->GetState() == 3) {
            ((KDStateMachine<ElementalSpline> *) &this->unkC0)->SetState(this, 0, 0U);
        }
        break;
    case 0xB4:
        if (((KDStateMachine<ElementalSpline> *) &this->unkC0)->GetState() == 1) {
            ((KDStateMachine<ElementalSpline> *) &this->unkC0)->SetState(this, 2, 0U);
        }
        break;
    }
    MKProp::Message(arg0);
}

#if 0 // DRAFT: illegal implicit conversion from 'MKResource * (const char *)' to
void ElementalSpline::Resolve() {
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    s32 temp_r0_4497;

    MKProp::Resolve();
    ((KDStateMachine<ElementalSpline> *) &this->unkC0)->SetState(this, 3, 0U);
    temp_r0_4497 = this->unk110;
    switch (temp_r0_4497) {                         /* irregular */
    case 0:
        this->unkF4 = MKMaterial_Create"FX_ElementalFlameWall";
        this->unkF8 = MKMaterial_Create"FX_ElementalFlameWall1";
        ((KDSound_SoundWall *) &this->unk120)->Init(((u8 *) this->unkB0) + 0x30, this->unkB4, GS_FireBarricadeLP, GS_FireBarricadeStart, GS_FireBarricadeStop, 0.25f, 0.25f, 0.0f, 1.0f);
        if (this->unkB4 == 0.0f) {
            this->unkB4 = 100.0f;
        }
        if ((this->unkE0.unk0 == 0.0f) || (this->unkE0.unk4 == 0.0f) || (this->unkE0.unk8 == 0.0f) || (this->unkE0.unkC == 0.0f)) {
            sp38 = 1.0f;
            sp3C = 0.5f;
            sp40 = 0.0f;
            sp44 = 1.0f;
            M2C_FIELD(this, f32 *, 0xE0) = (f64) sp38;
            sp78 = (f64) sp38;
            sp80 = (f64) sp40;
            M2C_FIELD(this, f32 *, 0xE8) = (f64) sp40;
        }
        break;
    case 1:
        this->unkF4 = MKMaterial_Create"FX_ElementalElectricityWall";
        ((KDSound_SoundWall *) &this->unk120)->Init(((u8 *) this->unkB0) + 0x30, this->unkB4, GS_ElecBarricadeLP, GS_ElecBarricadeStart, GS_ElecBarricadeStop, 0.25f, 0.25f, 0.0f, 1.0f);
        if (this->unkB4 == 0.0f) {
            this->unkB4 = 25.0f;
        }
        if ((this->unkE0.unk0 == 0.0f) || (this->unkE0.unk4 == 0.0f) || (this->unkE0.unk8 == 0.0f) || (this->unkE0.unkC == 0.0f)) {
            sp28 = 1.0f;
            sp2C = 0.0f;
            sp30 = 0.2f;
            sp34 = 1.0f;
            M2C_FIELD(this, f32 *, 0xE0) = (f64) sp28;
            sp68 = (f64) sp28;
            sp70 = (f64) sp30;
            M2C_FIELD(this, f32 *, 0xE8) = (f64) sp30;
        }
        break;
    case 2:
        this->unkF4 = MKMaterial_Create"FX_ElementalEarthSpline";
        ((KDSound_SoundWall *) &this->unk120)->Init(((u8 *) this->unkB0) + 0x30, this->unkB4, GS_IceBarricadeLP, GS_IceBarricadeStart, GS_IceBarricadeStop, 0.25f, 0.25f, 0.0f, 1.0f);
        if (this->unkB4 == 0.0f) {
            this->unkB4 = 300.0f;
        }
        if ((this->unkE0.unk0 == 0.0f) || (this->unkE0.unk4 == 0.0f) || (this->unkE0.unk8 == 0.0f) || (this->unkE0.unkC == 0.0f)) {
            sp18 = 0.25f;
            sp1C = 0.25f;
            sp20 = 0.75f;
            sp24 = 0.5f;
            M2C_FIELD(this, f32 *, 0xE0) = (f64) sp18;
            sp58 = (f64) sp18;
            sp60 = (f64) sp20;
            M2C_FIELD(this, f32 *, 0xE8) = (f64) sp20;
        }
        break;
    case 3:
        this->unkF4 = MKMaterial_Create"FX_ElementalEarthSpline";
        ((KDSound_SoundWall *) &this->unk120)->Init(((u8 *) this->unkB0) + 0x30, this->unkB4, GS_EarthBarricadeLP, GS_EarthBarricadeStart, GS_EarthBarricadeStop, 0.25f, 0.25f, 0.0f, 1.0f);
        if (this->unkB4 == 0.0f) {
            this->unkB4 = 100.0f;
        }
        if ((this->unkE0.unk0 == 0.0f) || (this->unkE0.unk4 == 0.0f) || (this->unkE0.unk8 == 0.0f) || (this->unkE0.unkC == 0.0f)) {
            sp8 = 0.0f;
            spC = 1.0f;
            sp10 = 0.2f;
            sp14 = 0.33f;
            M2C_FIELD(this, f32 *, 0xE0) = (f64) sp8;
            sp48 = (f64) sp8;
            sp50 = (f64) sp10;
            M2C_FIELD(this, f32 *, 0xE8) = (f64) sp10;
        }
        break;
    }
    this->unkFC = 1.0f / (f32) this->unk114;
}
#endif

#if 0 // DRAFT: illegal use of non-static member
s32 ElementalSpline::LoadLine(MKIniLine *arg0) {
    if (SplineProp::LoadLine(arg0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("Element", &this->unk110, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadFloat("Width", &this->unkB4, 0) != 0) {
        this->unkB4 *= 100.0f;
        return 1U;
    }
    if (arg0->LoadFloat("StartTime", &this->unk100, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadFloat("HoldTime", &this->unk104, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadFloat("EndTime", &this->unk108, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("SubDivisions", &this->unk114, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadBool("HurtHero", &this->unk118, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadVector4("EffectColour", &this->unkE0, 0) != 0) {
        return 1U;
    }
    if (this->unkD4.LoadLine(arg0, "OnConnect") != 0) {
        return 1U;
    }
    return (u8) (this->unkD8.LoadLine(arg0, "OnComplete") != 0);
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void ElementalSpline::Deinit() {
    MKMaterial *temp_r3_4902;
    MKMaterial *temp_r3_4907;

    ((KDStateMachine<ElementalSpline> *) &this->unkC0)->Deinit(this);
    ((KDSound_SoundWall *) &this->unk120)->Deinit();
    temp_r3_4902 = this->unkF4;
    if (temp_r3_4902 != NULL) {
        MKMaterial_Destroy(temp_r3_4902);
    }
    temp_r3_4907 = this->unkF8;
    if (temp_r3_4907 != NULL) {
        MKMaterial_Destroy(temp_r3_4907);
    }
    SplineProp::Deinit();
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void ElementalSpline::Init() {
    f64 sp20;
    f64 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;

    SplineProp::Init();
    Init__33KDStateMachine<15ElementalSpline>FPQ233KDStateMachine<15ElementalSpline>5StateP33KDStateMachine<15ElementalSpline>((KDStateMachine<ElementalSpline> *) &this->unkC0, &ElementalSplineStates, NULL);
    this->unkF4 = NULL;
    this->unkF8 = NULL;
    this->unk114 = 1;
    this->unkB4 = 20.0f;
    sp8 = 0.0f;
    spC = 0.0f;
    this->unkF0 = gb.unk30C + 0.0f;
    sp10 = 0.0f;
    sp14 = 0.0f;
    M2C_FIELD(this, f64 *, 0xE0) = (f64) sp8;
    M2C_FIELD(this, f64 *, 0xE8) = (f64) sp10;
    sp18 = (f64) sp8;
    sp20 = (f64) sp10;
    this->unk118 = 0;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'FallingLeaves *' to
void ElementalSplineDescriptor::LoadDone() {
    MKPropDescriptor::LoadDone();
    this->unk60 = checked_cast<FallingLeaves *, MKProp>(((MKSceneManager *) gMK)->CreateProp("FallingGlowLeaves"));
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_685'
void ElementalSpline_cpp::__sinit() {
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
    void *temp_r20_5216;

    temp_r20_5216 = &lit_685 + 0x90;
    sp2C = M2C_FIELD(&lit_685, s32 *, 0x68);
    M2C_FIELD(temp_r20_5216, s32 *, 0x60) = (s32) M2C_FIELD(&lit_685, s32 *, 0x60);
    sp8 = M2C_FIELD(&lit_685, s32 *, 0x6C);
    M2C_FIELD(temp_r20_5216, s32 *, 0x68) = sp2C;
    spC = M2C_FIELD(&lit_685, s32 *, 0x70);
    M2C_FIELD(temp_r20_5216, s32 *, 0x6C) = sp8;
    sp10 = M2C_FIELD(&lit_685, s32 *, 0x74);
    M2C_FIELD(temp_r20_5216, s32 *, 0x70) = spC;
    sp14 = M2C_FIELD(&lit_685, s32 *, 0x78);
    M2C_FIELD(temp_r20_5216, s32 *, 0x74) = sp10;
    sp18 = M2C_FIELD(&lit_685, s32 *, 0x7C);
    M2C_FIELD(temp_r20_5216, s32 *, 0x78) = sp14;
    sp1C = M2C_FIELD(&lit_685, s32 *, 0x80);
    M2C_FIELD(temp_r20_5216, s32 *, 0x7C) = sp18;
    sp20 = M2C_FIELD(&lit_685, s32 *, 0x84);
    M2C_FIELD(temp_r20_5216, s32 *, 0x80) = sp1C;
    sp24 = M2C_FIELD(&lit_685, s32 *, 0x88);
    M2C_FIELD(temp_r20_5216, s32 *, 0x84) = sp20;
    M2C_FIELD(temp_r20_5216, s32 *, 0x88) = sp24;
    M2C_FIELD(&lit_685, s32 *, 0x90) = (s32) M2C_FIELD(&lit_685, s32 *, 0);
    M2C_FIELD(&lit_685, s32 *, 0x94) = (s32) M2C_FIELD(&lit_685, s32 *, 4);
    M2C_FIELD(&lit_685, s32 *, 0x98) = (s32) M2C_FIELD(&lit_685, s32 *, 8);
    M2C_FIELD(temp_r20_5216, s32 *, 0xC) = (s32) M2C_FIELD(&lit_685, s32 *, 0xC);
    M2C_FIELD(temp_r20_5216, s32 *, 0x10) = (s32) M2C_FIELD(&lit_685, s32 *, 0x10);
    M2C_FIELD(temp_r20_5216, s32 *, 0x14) = (s32) M2C_FIELD(&lit_685, s32 *, 0x14);
    M2C_FIELD(temp_r20_5216, s32 *, 0x18) = (s32) M2C_FIELD(&lit_685, s32 *, 0x18);
    M2C_FIELD(temp_r20_5216, s32 *, 0x1C) = (s32) M2C_FIELD(&lit_685, s32 *, 0x1C);
    M2C_FIELD(temp_r20_5216, s32 *, 0x20) = (s32) M2C_FIELD(&lit_685, s32 *, 0x20);
    M2C_FIELD(temp_r20_5216, s32 *, 0x24) = (s32) M2C_FIELD(&lit_685, s32 *, 0x24);
    M2C_FIELD(temp_r20_5216, s32 *, 0x28) = (s32) M2C_FIELD(&lit_685, s32 *, 0x28);
    M2C_FIELD(temp_r20_5216, s32 *, 0x2C) = (s32) M2C_FIELD(&lit_685, s32 *, 0x2C);
    M2C_FIELD(temp_r20_5216, s32 *, 0x30) = (s32) M2C_FIELD(&lit_685, s32 *, 0x30);
    M2C_FIELD(temp_r20_5216, s32 *, 0x34) = (s32) M2C_FIELD(&lit_685, s32 *, 0x34);
    M2C_FIELD(temp_r20_5216, s32 *, 0x38) = (s32) M2C_FIELD(&lit_685, s32 *, 0x38);
    M2C_FIELD(temp_r20_5216, s32 *, 0x3C) = (s32) M2C_FIELD(&lit_685, s32 *, 0x3C);
    M2C_FIELD(temp_r20_5216, s32 *, 0x40) = (s32) M2C_FIELD(&lit_685, s32 *, 0x40);
    M2C_FIELD(temp_r20_5216, s32 *, 0x44) = (s32) M2C_FIELD(&lit_685, s32 *, 0x44);
    M2C_FIELD(temp_r20_5216, s32 *, 0x48) = (s32) M2C_FIELD(&lit_685, s32 *, 0x48);
    M2C_FIELD(temp_r20_5216, s32 *, 0x4C) = (s32) M2C_FIELD(&lit_685, s32 *, 0x4C);
    M2C_FIELD(temp_r20_5216, s32 *, 0x50) = (s32) M2C_FIELD(&lit_685, s32 *, 0x50);
    M2C_FIELD(temp_r20_5216, s32 *, 0x54) = (s32) M2C_FIELD(&lit_685, s32 *, 0x54);
    M2C_FIELD(temp_r20_5216, s32 *, 0x58) = (s32) M2C_FIELD(&lit_685, s32 *, 0x58);
    M2C_FIELD(temp_r20_5216, s32 *, 0x5C) = (s32) M2C_FIELD(&lit_685, s32 *, 0x5C);
    M2C_FIELD(temp_r20_5216, s32 *, 0x64) = (s32) M2C_FIELD(&lit_685, s32 *, 0x64);
    M2C_FIELD(temp_r20_5216, s32 *, 0x8C) = (s32) M2C_FIELD(&lit_685, s32 *, 0x8C);
    sp28 = M2C_FIELD(&lit_685, s32 *, 0x8C);
}
#endif
