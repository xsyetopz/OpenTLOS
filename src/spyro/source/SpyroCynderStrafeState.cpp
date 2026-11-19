#include "spyro/source/SpyroCynderStrafeState.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "spyro/source/InputModifier.h"
#include "spyro/source/KDCamera.h"
#include "spyro/source/LineSegmentTrail.h"
#include "spyro/source/Spyro.h"
#include "spyro/source/checkpoint.h"
#include "common/Source/MKInput.h"
#include "spyro/source/KDMath.h"
#include "spyro/source/KDSound.h"
#include <m2c_macros.h>

extern s32 GS_SpyroLand;
extern f32 SPYRO_BOUNCE_Y_SPEED;
extern f32 SPYRO_MIN_JUMP_Y_VELOCITY;
#if 0 // DRAFT: undefined identifier '__vptr'
static M2C_UNK lit_733;                                /* unable to generate initializer: unknown type */
static SpyroCynderStrafeState states__22SpyroCynderStrafeState; /* type too large by 0x18; unable to generate initializer: confusing struct layout */
static SpyroCynderStrafeState jumpStates__22SpyroCynderStrafeState; /* type too large by 0x3C; unable to generate initializer: confusing struct layout */

void SpyroCynderStrafeState::Landed(bool arg0) {
    s8 sp32;
    s8 sp31;
    s8 sp30;
    f64 sp28;
    f64 sp20;
    s32 sp1C;
    s32 sp18;
    f64 sp10;
    f64 sp8;
    Spyro *temp_r3_54;
    Spyro *temp_r3_73;
    f64 temp_f0_57;
    f64 temp_f1_56;
    void *temp_r5_55;

    if (arg0 != 0) {
        this->unk10->AddFootEffect(2);
        this->unk10->AddFootEffect(3);
        this->unk10->AddFootEffect(4);
        this->unk10->AddFootEffect(5);
    }
    if (this->unk10->OnProp() != NULL) {
        sp1C = 0;
        temp_r3_54 = this->unk10;
        temp_r5_55 = temp_r3_54->unk8;
        temp_f1_56 = M2C_FIELD(temp_r5_55, f64 *, 0x30);
        temp_f0_57 = M2C_FIELD(temp_r5_55, f64 *, 0x38);
        sp8 = temp_f1_56;
        sp10 = temp_f0_57;
        sp18 = 0xF;
        sp20 = temp_f1_56;
        sp28 = temp_f0_57;
        sp30 = 0;
        sp31 = 0;
        sp32 = 1;
        M2C_FIELD(temp_r3_54->OnProp()->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp18);
    }
    temp_r3_73 = this->unk10;
    if (((s32) M2C_FIELD(temp_r3_73->unk26C.unk8, s32 *, 0x16C) > 0) && ((u32) temp_r3_73->unk40C != 0U)) {
        temp_r3_73->BridgeHit(0.0f, 1000.0f);
    }
}
#endif

s32 SpyroCynderStrafeState::JumpLoftTransition() {
    return 0;
}

void SpyroCynderStrafeState::JumpLoftUpdate() {
    JumpLoftTransition();
}

void SpyroCynderStrafeState::JumpLoftExit() {

}

#if 0 // DRAFT: illegal type
void SpyroCynderStrafeState::JumpLoftEnter() {
    s16 spA;
    s16 sp8;
    MKAnim *temp_r31_135;
    MKAnim *temp_r31_164;
    Spyro *temp_r3_129;
    Spyro *temp_r3_156;
    f32 temp_f31_165;

    temp_r3_129 = this->unk10;
    temp_r31_135 = M2C_FIELD((temp_r3_129->unkB4 + (M2C_FIELD(this->unk74, s32 *, 4) * 8)), MKAnim **, 4);
    ((MKAnimScript *) (temp_r3_129->GetAnimScript((Spyro::AnimScriptNode) 0)))->GetStartAndEnd(temp_r31_135, &spA, &sp8);
    temp_r3_156 = this->unk10;
    temp_r31_164 = M2C_FIELD((temp_r3_156->unkB4 + (M2C_FIELD(this->unk74, s32 *, 4) * 8)), MKAnim **, 4);
    temp_f31_165 = ((f32) (sp8 - ((MKAnimScript *) (this->unk10->GetAnimScript((Spyro::AnimScriptNode) 0)))->GetCurrentFrame()) / 30.0f) / 0.3f;
    ((MKAnimScript *) (temp_r3_156->GetAnimScript((Spyro::AnimScriptNode) 0)))->SetAnim(temp_r31_164, temp_f31_165, 0.0f, 0, -1);
}
#endif

#if 0 // DRAFT: expression syntax error
s32 SpyroCynderStrafeState::JumpCycleTransition() {
    u8 var_r0_188;

    var_r0_188 = this->unk65;
    if (var_r0_188 == 0) {
        var_r0_188 = this->unk64;
    }
    if ((var_r0_188 != 0) && ((s32) this->unk50 != 2)) {
        this->unk50.SetState(this, 2, 0U);
        return 1;
    }
    return 0;
}
#endif

void SpyroCynderStrafeState::JumpCycleUpdate() {
    JumpCycleTransition();
}

void SpyroCynderStrafeState::JumpCycleExit() {

}

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void SpyroCynderStrafeState::JumpCycleEnter() {
    this->unk10->SetAnim(M2C_FIELD(this->unk74, u32 *, 4), 0.0f, (Spyro::AnimScriptNode) 0, 0U, 1.0f);
}
#endif

#if 0 // DRAFT: expression syntax error
u8 SpyroCynderStrafeState::JumpStartTransition() {
    u8 var_r0_261;
    u8 var_r3_276;

    var_r0_261 = this->unk65;
    if (var_r0_261 == 0) {
        var_r0_261 = this->unk64;
    }
    if ((var_r0_261 != 0) && ((s32) this->unk50 != 2)) {
        this->unk50.SetState(this, 2, 0U);
        var_r3_276 = 1;
    } else {
        var_r3_276 = 0;
    }
    if (var_r3_276 == 0) {
        if ((this->unk10->GetAnimScript((Spyro::AnimScriptNode) 0)->unk2C & 1) && ((s32) this->unk50 != 1)) {
            this->unk50.SetState(this, 1, 0U);
            return 1U;
        }
        var_r3_276 = 0;
        /* Duplicate return node #11. Try simplifying control flow for better match */
        return var_r3_276;
    }
    return var_r3_276;
}
#endif

void SpyroCynderStrafeState::JumpStartUpdate() {
    JumpStartTransition();
}

void SpyroCynderStrafeState::JumpStartExit() {

}

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void SpyroCynderStrafeState::JumpStartEnter() {
    this->unk64 = 0;
    this->unk65 = 0;
    this->unk10->SetAnim(*this->unk74, 0.2f, (Spyro::AnimScriptNode) 0, 0U, 1.0f);
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void SpyroCynderStrafeState::AnyStateEnter() {
    s32 spC;
    s32 sp8;
    KDCamera *temp_r3_362;

    this->unk10->OnStateChange();
    temp_r3_362 = this->unk10->GetCamera();
    spC = 0;
    sp8 = 0x42B;
    M2C_FIELD(temp_r3_362->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp8);
    M2C_FIELD(this->unk10, s8 *, 0x25C) = 1;
}
#endif

#if 0 // DRAFT: expression syntax error
u8 SpyroCynderStrafeState::FallTransition() {
    f64 sp10;
    f64 sp8;
    MKProp *temp_r3_415;
    Spyro *temp_r4_393;
    s32 temp_r3_395;
    s32 temp_r3_417;
    u32 temp_r30_398;
    u32 var_r29_411;
    u8 var_r3_449;
    void *temp_r6_400;
    void *var_r3_426;

    M2C_FIELD(this->unk10, s8 *, 0x3D2) = 0;
    temp_r4_393 = this->unk10;
    temp_r3_395 = M2C_FIELD(temp_r4_393->unk26C.unk8, s32 *, 0x16C);
    temp_r30_398 = (u32) (-temp_r3_395 & ~temp_r3_395) >> 0x1FU;
    if (temp_r30_398 != 0) {
        temp_r6_400 = temp_r4_393->unk8;
        sp8 = M2C_FIELD(temp_r6_400, f64 *, 0x30);
        sp10 = M2C_FIELD(temp_r6_400, f64 *, 0x38);
        if (sp8.IsWithin(*NULL, NULL, (s32 *) temp_r6_400) != 0) {
            var_r29_411 = 0x01000000;
        } else {
            temp_r3_415 = this->unk10->unk26C.unk8;
            temp_r3_417 = M2C_FIELD(temp_r3_415, s32 *, 0x16C);
            if (((u32) (-temp_r3_417 & ~temp_r3_417) >> 0x1FU) != 0) {
                if (temp_r3_417 != 0) {
                    var_r3_426 = &temp_r3_415->unk8 + ((temp_r3_417 - 1) * 0x58);
                } else {
                    var_r3_426 = NULL;
                }
                var_r29_411 = M2C_FIELD(var_r3_426, u32 *, 0x44);
            } else {
                var_r29_411 = 0;
            }
        }
        Landed(1U);
        this->unk10->SetDesiredVelocityVectical(0.0f, 540000.0f);
        KDSound_Play(GS_SpyroLand, var_r29_411, 0xFF);
    }
    var_r3_449 = AnyToDodgeTranstion();
    if (var_r3_449 == 0) {
        if ((temp_r30_398 != 0) && ((s32) this->unk18.unk0 != 0)) {
            this->unk18.SetState(this, 0, 0U);
            return 1U;
        }
        var_r3_449 = 0;
        /* Duplicate return node #15. Try simplifying control flow for better match */
        return var_r3_449;
    }
    return var_r3_449;
}
#endif

#if 0 // DRAFT: expression syntax error
void SpyroCynderStrafeState::FallUpdate() {
    f64 sp20;
    f64 sp18;
    f64 sp8;

    this->unk7C.Update(this->unk10);
    sp8.GetMoveVelocityHorz();
    sp18 = sp8;
    sp20 = sp10;
    this->unk10->SetDesiredVelocityHoriz(*((MKVector3 *) &sp18), 3800.0f);
    this->unk88.Update();
    FallTransition();
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void SpyroCynderStrafeState::FallExit() {
    s32 spC;
    s32 sp8;
    KDCamera *temp_r3_516;
    Spyro *temp_r3_526;
    Spyro *temp_r3_530;

    temp_r3_516 = this->unk10->GetCamera();
    spC = 0;
    sp8 = 0x450;
    M2C_FIELD(temp_r3_516->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp8);
    temp_r3_526 = this->unk10;
    temp_r3_526->unk428 |= 0x80;
    temp_r3_530 = this->unk10;
    temp_r3_530->unk428 &= 0xFFFF7FFF;
    ((LineSegmentTrail *) (M2C_FIELD(M2C_FIELD(this->unk10->unk258, void **, 4), LineSegmentTrail **, 0xC8)))->EndTrail();
    ((LineSegmentTrail *) (M2C_FIELD(M2C_FIELD(this->unk10->unk258, void **, 4), LineSegmentTrail **, 0xCC)))->EndTrail();
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void SpyroCynderStrafeState::FallEnter() {
    s32 sp40;
    s32 sp3C;
    s32 sp38;
    f64 sp30;
    f64 sp28;
    f64 sp20;
    f64 sp18;
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    KDCamera *temp_r3_613;
    KDCamera *temp_r3_624;
    Spyro *temp_r3_570;
    Spyro *temp_r3_643;
    Spyro *temp_r4_563;
    Spyro *temp_r4_592;
    Spyro *temp_r4_666;
    f32 temp_f0_574;
    f32 temp_f0_647;
    f32 temp_f1_572;
    f32 temp_f1_645;
    f32 var_f2_573;
    f32 var_f2_646;
    s32 temp_r3_593;
    u8 var_r0_588;
    void *temp_r3_605;
    void *temp_r3_636;
    void *temp_r3_682;

    AnyStateEnter();
    this->unk10->SetMedium((Spyro::Medium) 2);
    temp_r4_563 = this->unk10;
    temp_r4_563->unk428 &= 0xFFFDF7DF;
    temp_r3_570 = this->unk10;
    temp_r3_570->unk388 = 3800.0f;
    temp_f1_572 = temp_r3_570->unk388;
    var_f2_573 = temp_r3_570->unk33C;
    temp_f0_574 = -temp_f1_572;
    if (var_f2_573 < temp_f1_572) {

    } else {
        var_f2_573 = temp_f1_572;
    }
    if (var_f2_573 > temp_f0_574) {

    } else {
        var_f2_573 = temp_f0_574;
    }
    temp_r3_570->unk33C = var_f2_573;
    var_r0_588 = 1;
    M2C_FIELD(this->unk10, f32 *, 0x38C) = 1900.0f;
    temp_r4_592 = this->unk10;
    temp_r3_593 = temp_r4_592->unk54.unkC;
    if ((temp_r3_593 != 9) && (temp_r3_593 != 4)) {
        var_r0_588 = 0;
    }
    temp_r4_592->unk3CC = var_r0_588 != 0;
    temp_r3_605 = this->unk10->unk8;
    sp28 = M2C_FIELD(temp_r3_605, f64 *, 0x30);
    sp30 = M2C_FIELD(temp_r3_605, f64 *, 0x38);
    this->unk78 = unksp2C;
    temp_r3_613 = this->unk10->GetCamera();
    sp14 = 0;
    sp10 = 0x44F;
    M2C_FIELD(temp_r3_613->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp10);
    temp_r3_624 = this->unk10->GetCamera();
    spC = 0;
    sp8 = 0x414;
    M2C_FIELD(temp_r3_624->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp8);
    temp_r3_636 = this->unk10->unk8;
    sp18 = M2C_FIELD(temp_r3_636, f64 *, 0x30);
    sp20 = M2C_FIELD(temp_r3_636, f64 *, 0x38);
    this->unk78 = unksp1C;
    temp_r3_643 = this->unk10;
    temp_r3_643->unk388 = 3800.0f;
    temp_f1_645 = temp_r3_643->unk388;
    var_f2_646 = temp_r3_643->unk33C;
    temp_f0_647 = -temp_f1_645;
    if (var_f2_646 < temp_f1_645) {

    } else {
        var_f2_646 = temp_f1_645;
    }
    if (var_f2_646 > temp_f0_647) {

    } else {
        var_f2_646 = temp_f0_647;
    }
    temp_r3_643->unk33C = var_f2_646;
    M2C_FIELD(this->unk10, f32 *, 0x38C) = 1900.0f;
    temp_r4_666 = this->unk10;
    temp_r4_666->unk428 |= 0x8000;
    this->unk7C.Start(this->unk10, 0.0f);
    this->unk88.Reset();
    sp3C = 0;
    sp38 = 0x17;
    sp40 = 0xA;
    temp_r3_682 = this->unk10->unkB70;
    M2C_FIELD(M2C_FIELD(temp_r3_682, void **, 0x44), M2C_UNK (**)(void *, s32 *), 0x2C)(temp_r3_682, &sp38);
    this->unk10->SetMeleeButtonStateTimeout(1U);
}
#endif

#if 0 // DRAFT: undefined identifier 'unk18'
u8 SpyroCynderStrafeState::JumpTransition() {
    u8 var_r3_705;

    var_r3_705 = AnyToDodgeTranstion();
    if (var_r3_705 == 0) {
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if ((this->unk10->unk33C == 0.0f) && ((s32) this->unk18.unk0 != 3)) {
            this->unk18.SetState(this, 3, 0U);
            return 1U;
        }
        var_r3_705 = 0;
        /* Duplicate return node #5. Try simplifying control flow for better match */
        return var_r3_705;
    }
    return var_r3_705;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'long' to
void SpyroCynderStrafeState::JumpUpdate() {
    f64 sp58;
    f64 sp50;
    f64 sp48;                                       /* compiler-managed */
    f64 sp40;                                       /* compiler-managed */
    SpyroCynderStrafeState sp30;
    f64 sp20;
    M2C_UNK sp10;
    f32 sp8;
    InputModifier *temp_r3_746;
    Spyro *temp_r4_774;
    f32 temp_f31_785;
    f32 var_f1_759;
    f32 var_f5_805;
    f64 temp_f1_810;
    f64 temp_f1_816;
    f64 temp_f1_820;
    s32 temp_r3_839;
    s32 var_r0_849;
    u8 var_r30_744;
    u8 var_r4_748;
    void *temp_r3_776;

    var_r30_744 = 0;
    temp_r3_746 = this->unk10->GetInput();
    var_r4_748 = 0;
    if (((u8) temp_r3_746->unk5 != 0) || ((u8) temp_r3_746->unk4 != 0)) {
        var_r4_748 = 1;
    }
    if (var_r4_748 != 0) {
        var_f1_759 = 0.0f;
    } else {
        var_f1_759 = MKInput_GetState(0xE, (MKInputDevices) temp_r3_746->unk0, NULL, NULL);
    }
    if (var_f1_759 != 0.0f) {
        if ((u8) this->unk64 == 0) {
            temp_r4_774 = this->unk10;
            temp_r3_776 = temp_r4_774->unk8;
            sp40 = M2C_FIELD(temp_r3_776, f64 *, 0x30);
            sp48 = M2C_FIELD(temp_r3_776, f64 *, 0x38);
            temp_f31_785 = 300.0f - (unksp44 - this->unk68);
            if ((temp_f31_785 < 100.0f) || ((s32) M2C_FIELD(temp_r4_774->unk26C.unk8, s32 *, 0x43C) > 0)) {
                if ((u8) this->unk65 == 0) {
                    sp30.GetMoveVelocityHorz();
                    var_f5_805 = 1900.0f * (2.0f * temp_f31_785);
                    sp30.unk30 = M2C_BITWISE(f64, sp30);
                    sp30.unk38 = sp30.unk8;
                    if (var_f5_805 > 0.0f) {
                        temp_f1_810 = __frsqrte(var_f5_805);
                        temp_f1_816 = 0.5 * temp_f1_810 * -(((f64) var_f5_805 * (temp_f1_810 * temp_f1_810)) - 3.0);
                        temp_f1_820 = 0.5 * temp_f1_816 * -(((f64) var_f5_805 * (temp_f1_816 * temp_f1_816)) - 3.0);
                        var_f5_805 = (f32) ((f64) var_f5_805 * (0.5 * temp_f1_820 * -(((f64) var_f5_805 * (temp_f1_820 * temp_f1_820)) - 3.0)));
                    } else if (var_f5_805 < M2C_BITWISE(f32, 0.0)) {
                        var_f5_805 = __float_nan;
                    } else {
                        sp8 = var_f5_805;
                        temp_r3_839 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                        switch (temp_r3_839) {      /* irregular */
                        case 0x7F800000:
                            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                var_r0_849 = 1;
                            } else {
                                var_r0_849 = 2;
                            }
                            break;
                        case 0x0:
                            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                var_r0_849 = 5;
                            } else {
                                var_r0_849 = 3;
                            }
                            break;
                        default:
                            var_r0_849 = 4;
                            break;
                        }
                        if (var_r0_849 == 1) {
                            var_f5_805 = __float_nan;
                        }
                    }
                    sp30.unk34 = var_f5_805;
                    this->unk10->SetDesiredVelocity(*((MKVector3 *) &sp30.unk30), 540000.0f);
                    var_r30_744 = 1;
                    this->unk65 = 1;
                }
            } else {
                sp20.GetMoveVelocityHorz();
                sp50 = sp20;
                sp58 = sp28;
                unksp54 = SPYRO_MIN_JUMP_Y_VELOCITY;
                this->unk10->SetDesiredVelocity(*((MKVector3 *) &sp50), 540000.0f);
                var_r30_744 = 1;
            }
        }
    } else {
        this->unk64 = 1;
    }
    if (var_r30_744 == 0) {
        sp10.GetMoveVelocityHorz();
        this->unk10->SetDesiredVelocityHoriz(*((MKVector3 *) &sp10), 3800.0f);
    }
    this->unk50.Update(this, 0);
    JumpTransition();
}
#endif

#if 0 // DRAFT: expression syntax error
void SpyroCynderStrafeState::JumpExit() {
    Spyro *temp_r3_938;
    Spyro *temp_r3_942;

    this->unk50.Exit(this);
    M2C_FIELD(this->unk10, s8 *, 0x3D2) = 0;
    temp_r3_938 = this->unk10;
    temp_r3_938->unk428 |= 0x20000;
    temp_r3_942 = this->unk10;
    temp_r3_942->unk428 &= 0xFFFF7FFF;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void SpyroCynderStrafeState::JumpEnter() {
    f64 sp48;
    f64 sp40;
    s32 sp38;
    s32 sp34;
    s32 sp30;
    f64 sp20;
    f64 sp18;
    f64 sp10;
    s32 spC;
    s32 sp8;
    KDCamera *temp_r3_1004;
    Spyro *temp_r5_965;
    Spyro *temp_r5_972;
    f64 temp_f1_1021;
    void *temp_r3_1030;
    void *temp_r6_1018;

    AnyStateEnter();
    this->unk10->SetMedium((Spyro::Medium) 2);
    temp_r5_965 = this->unk10;
    temp_r5_965->unk428 |= 0x8007;
    temp_r5_972 = this->unk10;
    temp_r5_972->unk428 &= 0xFFFDF7D7;
    this->unk10->unk430.unk28.SetTailSweepEnabled(0U);
    this->unk10->unk430.unk28.SetHornDiveEnabled(0U);
    this->unk74 = &this->unk6C;
    sp20.GetMoveVelocityHorz();
    sp40 = sp20;
    sp48 = sp28;
    unksp44 = SPYRO_MIN_JUMP_Y_VELOCITY;
    this->unk10->SetDesiredVelocity(*((MKVector3 *) &sp40), 540000.0f);
    this->unk50.SetState(this, 0, 0U);
    temp_r3_1004 = this->unk10->GetCamera();
    spC = 0;
    sp8 = 0x414;
    M2C_FIELD(temp_r3_1004->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp8);
    temp_r6_1018 = this->unk10->unk8;
    temp_f1_1021 = M2C_FIELD(temp_r6_1018, f64 *, 0x38);
    sp10 = M2C_FIELD(temp_r6_1018, f64 *, 0x30);
    sp18 = temp_f1_1021;
    this->unk68 = unksp14;
    sp34 = 0;
    sp30 = 0x17;
    sp38 = 9;
    temp_r3_1030 = this->unk10->unkB70;
    M2C_FIELD(M2C_FIELD(temp_r3_1030, void **, 0x44), M2C_UNK (**)(void *, s32 *, M2C_UNK, void *, f64), 0x2C)(temp_r3_1030, &sp30, 0, temp_r6_1018, temp_f1_1021);
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'long' to
u8 SpyroCynderStrafeState::AnyToDodgeTranstion() {
    InputModifier *temp_r3_1051;
    s32 var_r3_1059;
    u8 var_r0_1052;

    temp_r3_1051 = this->unk10->GetInput();
    var_r0_1052 = temp_r3_1051->unk5;
    if (var_r0_1052 == 0) {
        var_r0_1052 = temp_r3_1051->unk4;
    }
    if (var_r0_1052 != 0) {
        var_r3_1059 = 0;
    } else {
        var_r3_1059 = MKInput_Pressed(0xE, (MKInputDevices) temp_r3_1051->unk0);
    }
    if ((u8) var_r3_1059 != 0) {
        if (((InputModifier *) (this->unk10->GetInput()))->GetLeftX() < 0.0f) {

        }
        var_r3_1059 = ((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1EU) & 1;
    }
    if ((u8) var_r3_1059 != 0) {
        this->unk18.SetState(this, 1, 1U);
        return 1U;
    }
    return 0U;
}
#endif

void SpyroCynderStrafeState::DodgeLeftRightSetLVEScale() {
    s32 temp_r0_1108;

    temp_r0_1108 = this->unk14;
    switch (temp_r0_1108) {                         /* irregular */
    case 0:
        this->unk10->SetLVEScale(MKVector3::one);
        return;
    case 1:
        if (((InputModifier *) (this->unk10->GetInput()))->GetLeftX() > 0.0f) {
            this->unk10->SetLVEScale(MKVector3::one);
            return;
        }
        this->unk10->SetLVEScale(MKVector3::zero);
        return;
    case 2:
        if (((InputModifier *) (this->unk10->GetInput()))->GetLeftX() < 0.0f) {
            this->unk10->SetLVEScale(MKVector3::one);
            return;
        }
        this->unk10->SetLVEScale(MKVector3::zero);
        return;
    }
}

#if 0 // DRAFT: illegal explicit conversion from 'int' to
u8 SpyroCynderStrafeState::DodgeLeftRightTransition() {
    InputModifier *temp_r3_1186;
    s32 var_r3_1194;
    u8 var_r0_1187;
    u8 var_r3_1178;

    this->unk10->GetAnimScript((Spyro::AnimScriptNode) 0);
    var_r3_1178 = ((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1EU) & 1;
    if (var_r3_1178 != 0) {
        var_r3_1178 = AnyToDodgeTranstion();
    }
    if (var_r3_1178 == 0) {
        temp_r3_1186 = this->unk10->GetInput();
        var_r0_1187 = temp_r3_1186->unk5;
        if (var_r0_1187 == 0) {
            var_r0_1187 = temp_r3_1186->unk4;
        }
        if (var_r0_1187 != 0) {
            var_r3_1194 = 0;
        } else {
            var_r3_1194 = MKInput_Pressed(0xE, (MKInputDevices) temp_r3_1186->unk0);
        }
        if ((u8) var_r3_1194 != 0) {
            this->unk10->GetAnimScript((Spyro::AnimScriptNode) 0);
            var_r3_1194 = ((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1EU) & 1;
        }
        if (((u8) var_r3_1194 != 0) && ((s32) this->unk18.unk0 != 2)) {
            this->unk18.SetState(this, 2, 0U);
            var_r3_1178 = 1;
        } else {
            var_r3_1178 = 0;
        }
    }
    if (var_r3_1178 == 0) {
        if ((this->unk10->GetAnimScript((Spyro::AnimScriptNode) 0)->unk2C & 1) && ((s32) this->unk18.unk0 != 0)) {
            this->unk18.SetState(this, 0, 0U);
            return 1U;
        }
        var_r3_1178 = 0;
        /* Duplicate return node #19. Try simplifying control flow for better match */
        return var_r3_1178;
    }
    return var_r3_1178;
}
#endif

void SpyroCynderStrafeState::DodgeLeftRightUpdate() {
    DodgeLeftRightSetLVEScale();
    SetDesiredVelocityHorz();
    DodgeLeftRightTransition();
}

void SpyroCynderStrafeState::DodgeLeftRightExit() {
    M2C_FIELD(this->unk10, s8 *, 0x25C) = 0;
    this->unk10->SetLVEScale(MKVector3::one);
}

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void SpyroCynderStrafeState::DodgeLeftRightEnter() {
    Spyro *temp_r4_1303;
    u32 var_r4_1315;

    AnyStateEnter();
    temp_r4_1303 = this->unk10;
    temp_r4_1303->unk428 &= 0xFFFDF7FF;
    if (((InputModifier *) (this->unk10->GetInput()))->GetLeftX() < 0.0f) {
        var_r4_1315 = 0x14;
    } else {
        var_r4_1315 = 0x15;
    }
    this->unk10->SetAnim(var_r4_1315, 0.1f, (Spyro::AnimScriptNode) 0, 4U, 1.0f);
    this->unk10->SetLVEScale(MKVector3::one);
    DodgeLeftRightSetLVEScale();
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'long' to
u8 SpyroCynderStrafeState::NoTargetTransition() {
    InputModifier *temp_r3_1351;
    s32 var_r3_1359;
    u8 var_r0_1352;
    u8 var_r3_1347;

    var_r3_1347 = AnyToDodgeTranstion();
    if (var_r3_1347 == 0) {
        temp_r3_1351 = this->unk10->GetInput();
        var_r0_1352 = temp_r3_1351->unk5;
        if (var_r0_1352 == 0) {
            var_r0_1352 = temp_r3_1351->unk4;
        }
        if (var_r0_1352 != 0) {
            var_r3_1359 = 0;
        } else {
            var_r3_1359 = MKInput_Pressed(0xE, (MKInputDevices) temp_r3_1351->unk0);
        }
        if (((u8) var_r3_1359 != 0) && ((s32) this->unk18.unk0 != 2)) {
            this->unk18.SetState(this, 2, 0U);
            return 1U;
        }
        var_r3_1347 = 0;
        /* Duplicate return node #10. Try simplifying control flow for better match */
        return var_r3_1347;
    }
    return var_r3_1347;
}
#endif

void SpyroCynderStrafeState::NoTargetUpdate() {
    Spyro *temp_r3_1403;
    s32 temp_r0_1404;

    SetDesiredVelocityHorz();
    SelectAnim();
    if (NoTargetTransition() != 0) {
        temp_r3_1403 = this->unk10;
        temp_r0_1404 = temp_r3_1403->unk54.unk8;
        if ((temp_r0_1404 != 0xB) && (temp_r0_1404 != 2)) {
            temp_r3_1403->unkB90.ClearCurrentTarget();
        }
    }
}

void SpyroCynderStrafeState::NoTargetExit() {

}

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void SpyroCynderStrafeState::NoTargetEnter() {
    s32 sp10;
    s32 spC;
    s32 sp8;
    Spyro *temp_r8_1437;
    s32 temp_r6_1445;
    s32 temp_r7_1441;
    void *temp_r3_1451;

    AnyStateEnter();
    this->unk10->SetMedium((Spyro::Medium) 1);
    temp_r8_1437 = this->unk10;
    temp_r7_1441 = temp_r8_1437->unk428;
    temp_r6_1445 = temp_r7_1441 & 0xFFFDF7FF;
    temp_r8_1437->unk428 = temp_r6_1445;
    spC = 0;
    sp8 = 0x17;
    sp10 = 3;
    temp_r3_1451 = this->unk10->unkB70;
    M2C_FIELD(M2C_FIELD(temp_r3_1451, void **, 0x44), M2C_UNK (**)(void *, s32 *, M2C_UNK, s32, s32, Spyro *), 0x2C)(temp_r3_1451, &sp8, 0, temp_r6_1445, temp_r7_1441, temp_r8_1437);
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void SpyroCynderStrafeState::SelectAnim() {
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f32 sp48;
    M2C_UNK sp38;
    MKVector3 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    Spyro *temp_r4_1476;
    Spyro *temp_r4_1489;
    Spyro *temp_r4_1496;
    f32 temp_f1_1550;
    f32 var_f1_1564;
    s32 var_r0_1579;
    s32 var_r31_1491;

    temp_r4_1476 = this->unk10;
    if (((u32) this->unk10->GetAnimScript((Spyro::AnimScriptNode) 0)->unk20 != (u32) M2C_FIELD(temp_r4_1476->unkB4, u32 *, 0x8C)) || (temp_r4_1476->GetAnimScript((Spyro::AnimScriptNode) 0)->unk2C & 1)) {
        temp_r4_1489 = this->unk10;
        var_r31_1491 = -1;
        M2C_FIELD(temp_r4_1489->__vptr, M2C_UNK (**)(M2C_UNK *, Spyro *), 0xB0)(&sp38, temp_r4_1489);
        temp_r4_1496 = this->unk10;
        M2C_FIELD(temp_r4_1496->__vptr, M2C_UNK (**)(f32 *, Spyro *), 0xB0)(&sp48, temp_r4_1496);
        sp18 = sp48;
        sp1C = 0.0f;
        sp20 = sp40;
        sp68 = (f64) sp18;
        sp70 = (f64) sp20;
        if ((((f32) sp70 * (f32) sp70) + (((f32) sp68 * (f32) sp68) + (unksp6C * unksp6C))) > 10000.0f) {
            Normalise(sp28);
            sp70 = (f64) sp28.unk8;
            sp68 = M2C_BITWISE(f64, sp28);
            sp8 = (f32) sp70;
            spC = 0.0f;
            sp10 = -(f32) sp68;
            sp58 = (f64) sp8;
            sp60 = (f64) sp10;
            temp_f1_1550 = ((f32) sp60 * this->unk38) + (((f32) sp58 * this->unk30) + (unksp5C * this->unk34));
            if (temp_f1_1550 > 0.5f) {
                var_r31_1491 = 0xE;
            } else if (temp_f1_1550 < -0.5f) {
                var_r31_1491 = 0xF;
            }
        } else {
            var_f1_1564 = ((InputModifier *) (this->unk10->GetInput()))->GetLeftX();
            if (var_f1_1564 < 0.0f) {
                var_f1_1564 = -var_f1_1564;
            }
            if (var_f1_1564 > 0.5f) {
                if (((InputModifier *) (this->unk10->GetInput()))->GetLeftX() > 0.0f) {
                    var_r0_1579 = 0xF;
                } else {
                    var_r0_1579 = 0xE;
                }
                var_r31_1491 = var_r0_1579;
            } else {
                var_r31_1491 = 0xB;
            }
        }
        if (var_r31_1491 > -1) {
            this->unk10->SetAnim((u32) var_r31_1491, 0.15f, (Spyro::AnimScriptNode) 0, 0U, 1.0f);
        }
    }
}
#endif

u8 SpyroCynderStrafeState::ClampVelocity() {
    return this->unk14 != 0;
}

#if 0 // DRAFT: undefined identifier 'sp40'
void SpyroCynderStrafeState::GetMoveVelocityHorz() {
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
    f64 sp68;
    f64 sp60;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp48;
    f32 sp38;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 sp8;
    SpyroCynderStrafeState *temp_r30_1630;
    f32 temp_f31_1653;
    f32 var_f1_1640;
    f32 var_f1_1762;
    f32 var_f4_1695;
    f64 temp_f1_1701;
    f64 temp_f1_1707;
    f64 temp_f1_1711;
    s32 temp_r3_1730;
    s32 var_r0_1740;
    void *temp_r3_1771;

    temp_r30_1630 = M2C_ERROR(/* Read from unset register $r4 */);
    if (((InputModifier *) (((Spyro *) (M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), Spyro **, 0x10)))->GetInput()))->GetLeftX() != 0.0f) {
        var_f1_1640 = ((InputModifier *) (temp_r30_1630->unk10->GetInput()))->GetLeftX();
        if (var_f1_1640 < 0.0f) {
            var_f1_1640 = -var_f1_1640;
        }
        temp_f31_1653 = ((InputModifier *) (temp_r30_1630->unk10->GetInput()))->GetLeftX();
        sp50 = temp_r30_1630->unk38;
        sp54 = 0.0f;
        sp58 = -temp_r30_1630->unk30;
        sp70 = (f64) sp50;
        sp78 = (f64) sp58;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
        sp80 = sp40;
        sp48 = (f32) sp78 * temp_f31_1653;
        sp88 = (f64) sp48;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
        spB0 = sp30;
        sp38 = (f32) sp88 * (750.0f * var_f1_1640);
        spB8 = (f64) sp38;
        if (temp_r30_1630->ClampVelocity() != 0) {
            var_f4_1695 = ((f32) spB8 * (f32) spB8) + (((f32) spB0 * (f32) spB0) + (unkspB4 * unkspB4));
            if (var_f4_1695 > 1e-12f) {
                if (var_f4_1695 > 0.0f) {
                    temp_f1_1701 = __frsqrte(var_f4_1695);
                    temp_f1_1707 = 0.5 * temp_f1_1701 * -(((f64) var_f4_1695 * (temp_f1_1701 * temp_f1_1701)) - 3.0);
                    temp_f1_1711 = 0.5 * temp_f1_1707 * -(((f64) var_f4_1695 * (temp_f1_1707 * temp_f1_1707)) - 3.0);
                    var_f4_1695 = (f32) ((f64) var_f4_1695 * (0.5 * temp_f1_1711 * -(((f64) var_f4_1695 * (temp_f1_1711 * temp_f1_1711)) - 3.0)));
                } else if (var_f4_1695 < M2C_BITWISE(f32, 0.0)) {
                    var_f4_1695 = __float_nan;
                } else {
                    sp8 = var_f4_1695;
                    temp_r3_1730 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                    switch (temp_r3_1730) {         /* irregular */
                    case 0x7F800000:
                        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                            var_r0_1740 = 1;
                        } else {
                            var_r0_1740 = 2;
                        }
                        break;
                    case 0x0:
                        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                            var_r0_1740 = 5;
                        } else {
                            var_r0_1740 = 3;
                        }
                        break;
                    default:
                        var_r0_1740 = 4;
                        break;
                    }
                    if (var_r0_1740 == 1) {
                        var_f4_1695 = __float_nan;
                    }
                }
                var_f1_1762 = 1.0f / var_f4_1695;
            } else {
                var_f1_1762 = 0.0f;
            }
            temp_r3_1771 = temp_r30_1630->unk10->unk8;
            sp60 = M2C_FIELD(temp_r3_1771, f64 *, 0x30);
            sp68 = M2C_FIELD(temp_r3_1771, f64 *, 0x38);
            sp28 = (f32) spB8 * var_f1_1762;
            sp20 = (f32) spB0 * var_f1_1762;
            sp24 = unkspB4 * var_f1_1762;
            sp18 = temp_r30_1630->unk48 - (f32) sp68;
            spA0 = (f64) sp20;
            spA8 = (f64) sp28;
            sp98 = (f64) sp18;
            sp10 = temp_r30_1630->unk40 - (f32) sp60;
            sp14 = 0.0f;
            sp90 = (f64) sp10;
            if ((((f32) spA8 * (f32) sp98) + (((f32) spA0 * (f32) sp90) + (unkspA4 * unksp94))) < 0.0f) {
                spB0 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
                spB8 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
            }
        }
        M2C_FIELD(this, f64 *, 0) = spB0;
        this->unk8 = spB8;
        return;
    }
    M2C_FIELD(this, f64 *, 0) = (f64) M2C_FIELD(&MKVector3::zero, f64 *, 0);
    this->unk8 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
}
#endif

#if 0 // DRAFT: expression syntax error
void SpyroCynderStrafeState::SetDesiredVelocityHorz() {
    M2C_UNK sp8;

    sp8.GetMoveVelocityHorz();
    this->unk10->SetDesiredVelocityHoriz(*((MKVector3 *) &sp8), 100000.0f);
}
#endif

#if 0 // DRAFT: undefined identifier 'unksp54'
void SpyroCynderStrafeState::ClampMovementUpdate() {
    f64 sp78;
    f64 sp70;
    f64 sp68;                                       /* compiler-managed */
    f64 sp60;                                       /* compiler-managed */
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f2_2078;
    f32 temp_f5_2072;
    f32 temp_f6_2066;
    f32 temp_f7_2068;
    f32 var_f0_1956;
    f32 var_f1_1991;
    f32 var_f4_1867;
    f32 var_f5_1886;
    f64 temp_f1_1891;
    f64 temp_f1_1897;
    f64 temp_f1_1901;
    f64 temp_f2_1998;
    f64 temp_f2_2004;
    f64 temp_f2_2008;
    s32 temp_r4_1920;
    s32 temp_r4_2027;
    s32 var_r0_1930;
    s32 var_r0_2037;
    void *temp_r4_1958;

    var_f4_1867 = 0.0f;
    this->unk14 = 0;
    sp30 = this->unk38;
    sp34 = 0.0f;
    sp38 = -this->unk30;
    sp50 = (f64) sp30;
    sp58 = (f64) sp38;
    var_f5_1886 = ((f32) sp58 * (f32) sp58) + (((f32) sp50 * (f32) sp50) + (unksp54 * unksp54));
    if (var_f5_1886 > 1e-12f) {
        if (var_f5_1886 > 0.0f) {
            temp_f1_1891 = __frsqrte(var_f5_1886);
            temp_f1_1897 = 0.5 * temp_f1_1891 * -(((f64) var_f5_1886 * (temp_f1_1891 * temp_f1_1891)) - 3.0);
            temp_f1_1901 = 0.5 * temp_f1_1897 * -(((f64) var_f5_1886 * (temp_f1_1897 * temp_f1_1897)) - 3.0);
            var_f5_1886 = (f32) ((f64) var_f5_1886 * (0.5 * temp_f1_1901 * -(((f64) var_f5_1886 * (temp_f1_1901 * temp_f1_1901)) - 3.0)));
        } else if (var_f5_1886 < M2C_BITWISE(f32, 0.0)) {
            var_f5_1886 = __float_nan;
        } else {
            spC = var_f5_1886;
            temp_r4_1920 = M2C_BITWISE(s32, spC) & 0x7F800000;
            switch (temp_r4_1920) {                 /* switch 1; irregular */
            case 0x7F800000:                        /* switch 1 */
                if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                    var_r0_1930 = 1;
                } else {
                    var_r0_1930 = 2;
                }
                break;
            case 0x0:                               /* switch 1 */
                if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                    var_r0_1930 = 5;
                } else {
                    var_r0_1930 = 3;
                }
                break;
            default:                                /* switch 1 */
                var_r0_1930 = 4;
                break;
            }
            if (var_r0_1930 == 1) {
                var_f5_1886 = __float_nan;
            }
        }
        var_f4_1867 = 1.0f / var_f5_1886;
    }
    var_f0_1956 = 0.0f;
    temp_r4_1958 = this->unk10->unk8;
    sp40 = M2C_FIELD(temp_r4_1958, f64 *, 0x30);
    sp48 = M2C_FIELD(temp_r4_1958, f64 *, 0x38);
    sp28 = (f32) sp58 * var_f4_1867;
    sp10 = this->unk40 - (f32) sp40;
    sp14 = 0.0f;
    sp18 = this->unk48 - (f32) sp48;
    sp60 = (f64) sp10;
    sp68 = (f64) sp18;
    sp20 = (f32) sp50 * var_f4_1867;
    sp24 = unksp54 * var_f4_1867;
    var_f1_1991 = ((f32) sp68 * (f32) sp68) + (((f32) sp60 * (f32) sp60) + (unksp64 * unksp64));
    sp78 = (f64) sp28;
    sp70 = (f64) sp20;
    if (var_f1_1991 > 0.000001f) {
        if (var_f1_1991 > 0.0f) {
            temp_f2_1998 = __frsqrte(var_f1_1991);
            temp_f2_2004 = 0.5 * temp_f2_1998 * -(((f64) var_f1_1991 * (temp_f2_1998 * temp_f2_1998)) - 3.0);
            temp_f2_2008 = 0.5 * temp_f2_2004 * -(((f64) var_f1_1991 * (temp_f2_2004 * temp_f2_2004)) - 3.0);
            var_f1_1991 = (f32) ((f64) var_f1_1991 * (0.5 * temp_f2_2008 * -(((f64) var_f1_1991 * (temp_f2_2008 * temp_f2_2008)) - 3.0)));
        } else if (var_f1_1991 < M2C_BITWISE(f32, 0.0)) {
            var_f1_1991 = __float_nan;
        } else {
            sp8 = var_f1_1991;
            temp_r4_2027 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r4_2027) {                 /* switch 2; irregular */
            case 0x7F800000:                        /* switch 2 */
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_2037 = 1;
                } else {
                    var_r0_2037 = 2;
                }
                break;
            case 0x0:                               /* switch 2 */
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_2037 = 5;
                } else {
                    var_r0_2037 = 3;
                }
                break;
            default:                                /* switch 2 */
                var_r0_2037 = 4;
                break;
            }
            if (var_r0_2037 == 1) {
                var_f1_1991 = __float_nan;
            }
        }
        var_f0_1956 = 1.0f / var_f1_1991;
    } else {
        var_f1_1991 = 0.0f;
    }
    temp_f6_2066 = unksp64 * var_f0_1956;
    temp_f7_2068 = (f32) sp60 * var_f0_1956;
    temp_f5_2072 = (f32) sp68 * var_f0_1956;
    sp60 = temp_f7_2068;
    unksp64 = temp_f6_2066;
    temp_f2_2078 = (temp_f5_2072 * (f32) sp78) + ((temp_f7_2068 * (f32) sp70) + (temp_f6_2066 * unksp74));
    sp68 = temp_f5_2072;
    if ((temp_f2_2078 > 0.0f) && (var_f1_1991 > 900.0f)) {
        this->unk14 = 1;
        return;
    }
    if ((temp_f2_2078 < 0.0f) && (var_f1_1991 > 800.0f)) {
        this->unk14 = 2;
    }
}
#endif

void SpyroCynderStrafeState::ProcessAnimEvent(unsigned int arg0) {

}

void SpyroCynderStrafeState::Message(MKMessage *arg0) {

}

s32 SpyroCynderStrafeState::Transition() {
    return 0;
}

#if 0 // DRAFT: undefined identifier 'unk18'
void SpyroCynderStrafeState::Update() {
    ClampMovementUpdate();
    this->unk18.Update(this, 0);
}
#endif

#if 0 // DRAFT: undefined identifier 'unk18'
void SpyroCynderStrafeState::Exit() {
    this->unk18.Exit(this);
}
#endif

#if 0 // DRAFT: expression syntax error
void SpyroCynderStrafeState::Enter(SpyroStateMessages &arg0) {
    f64 sp28;
    f64 sp20;
    f64 sp10;
    s32 spC;
    s32 sp8;
    KDCamera *temp_r3_2197;
    Spyro *temp_r4_2165;
    Spyro *temp_r4_2170;
    f64 temp_f0_2176;
    f64 temp_f1_2175;

    temp_r4_2165 = this->unk10;
    temp_r4_2165->unk428 |= 0x8000;
    temp_r4_2170 = this->unk10;
    temp_r4_2170->unk428 &= 0xFFFDF7FF;
    temp_f1_2175 = M2C_FIELD(CheckPoint::pCurrentCheckPoint.unk0, f64 *, 0xF0);
    temp_f0_2176 = M2C_FIELD(CheckPoint::pCurrentCheckPoint.unk0, f64 *, 0xF8);
    sp20 = temp_f1_2175;
    M2C_FIELD(this, f64 *, 0x40) = temp_f1_2175;
    M2C_FIELD(this, f64 *, 0x48) = temp_f0_2176;
    sp28 = temp_f0_2176;
    this->unk10->GetYaw();
    KDMath_GetDirection(M2C_ERROR(/* Read from unset register $f1 */));
    M2C_FIELD(this, f64 *, 0x30) = sp10;
    M2C_FIELD(this, f64 *, 0x38) = sp18;
    this->unk10->SetAnim(0x11U, 0.15f, (Spyro::AnimScriptNode) 0, 0U, 1.0f);
    temp_r3_2197 = this->unk10->GetCamera();
    spC = 0;
    sp8 = 0x42B;
    M2C_FIELD(temp_r3_2197->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp8);
    this->unk18.SetState(this, 0, 0U);
}
#endif

#if 0 // DRAFT: expression syntax error
void SpyroCynderStrafeState::Deinit() {
    this->unk50.Deinit();
    this->unk18.Deinit();
}
#endif

#if 0 // DRAFT: undefined identifier 'Init__40KDStateMachine'
void SpyroCynderStrafeState::Init(Spyro *arg0) {
    this->unk10 = arg0;
    Init__40KDStateMachine<22SpyroCynderStrafeState>FPQ240KDStateMachine<22SpyroCynderStrafeState>5StateP40KDStateMachine<22SpyroCynderStrafeState>(&this->unk18, (KDStateMachine<SpyroCynderStrafeState>::State *) &SpyroCynderStrafeState::states, NULL);
    Init__40KDStateMachine<22SpyroCynderStrafeState>FPQ240KDStateMachine<22SpyroCynderStrafeState>5StateP40KDStateMachine<22SpyroCynderStrafeState>((KDStateMachine<SpyroCynderStrafeState> *) &this->unk50, (KDStateMachine<SpyroCynderStrafeState>::State *) &SpyroCynderStrafeState::jumpStates, NULL);
    this->unk14 = 0;
    M2C_FIELD(this, f64 *, 0x40) = (f64) M2C_FIELD(&MKVector3::zero, f64 *, 0);
    M2C_FIELD(this, f64 *, 0x48) = (f64) M2C_FIELD(&MKVector3::zero, f64 *, 8);
    M2C_FIELD(this, f64 *, 0x30) = (f64) M2C_FIELD(&MKVector3::zero, f64 *, 0);
    M2C_FIELD(this, f64 *, 0x38) = (f64) M2C_FIELD(&MKVector3::zero, f64 *, 8);
    this->unk68 = 0.0f;
    this->unk64 = 0;
    this->unk65 = 0;
    this->unk6C = 0x19;
    this->unk70 = 0x19;
    this->unk74 = &this->unk6C;
    this->unk78 = 0.0f;
    this->unk7C.unk0 = 0x1A;
    this->unk7C.unk4 = 0x1B;
    this->unk88.Init((MKProp *) this->unk10);
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_733'
void SpyroCynderStrafeState_cpp::__sinit() {
    s32 sp48;
    s32 sp44;
    s32 sp40;
    s32 sp3C;
    s32 sp38;
    s32 sp34;
    s32 sp30;
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
    f64 temp_f0_2548;
    f64 temp_f1_2513;
    f64 temp_f1_2528;
    f64 temp_f1_2551;
    f64 temp_f3_2498;
    f64 temp_f4_2512;
    f64 temp_f4_2525;
    f64 temp_f8_2500;
    void *temp_r17_2507;
    void *temp_r8_2579;

    temp_f3_2498 = __frsqrte(2014000.0);
    temp_f8_2500 = __frsqrte(380000.0);
    temp_r17_2507 = &lit_733 + 0x90;
    temp_f4_2512 = 0.5 * temp_f3_2498 * -((2014000.0 * (temp_f3_2498 * temp_f3_2498)) - 3.0);
    temp_f1_2513 = 0.5 * temp_f8_2500 * -((380000.0 * (temp_f8_2500 * temp_f8_2500)) - 3.0);
    temp_f4_2525 = 0.5 * temp_f4_2512 * -((2014000.0 * (temp_f4_2512 * temp_f4_2512)) - 3.0);
    temp_f1_2528 = 0.5 * temp_f1_2513 * -((380000.0 * (temp_f1_2513 * temp_f1_2513)) - 3.0);
    temp_f0_2548 = 0.5 * temp_f1_2528 * -((380000.0 * (temp_f1_2528 * temp_f1_2528)) - 3.0);
    temp_f1_2551 = 2014000.0 * (0.5 * temp_f4_2525 * -((2014000.0 * (temp_f4_2525 * temp_f4_2525)) - 3.0));
    M2C_FIELD(&lit_733, s32 *, 0x90) = (s32) M2C_FIELD(&lit_733, s32 *, 0);
    M2C_FIELD(&lit_733, s32 *, 0x94) = (s32) M2C_FIELD(&lit_733, s32 *, 4);
    M2C_FIELD(&lit_733, s32 *, 0x98) = (s32) M2C_FIELD(&lit_733, s32 *, 8);
    M2C_FIELD(temp_r17_2507, s32 *, 0xC) = (s32) M2C_FIELD(&lit_733, s32 *, 0xC);
    M2C_FIELD(temp_r17_2507, s32 *, 0x10) = (s32) M2C_FIELD(&lit_733, s32 *, 0x10);
    M2C_FIELD(temp_r17_2507, s32 *, 0x14) = (s32) M2C_FIELD(&lit_733, s32 *, 0x14);
    M2C_FIELD(temp_r17_2507, s32 *, 0x18) = (s32) M2C_FIELD(&lit_733, s32 *, 0x18);
    M2C_FIELD(temp_r17_2507, s32 *, 0x1C) = (s32) M2C_FIELD(&lit_733, s32 *, 0x1C);
    M2C_FIELD(temp_r17_2507, s32 *, 0x20) = (s32) M2C_FIELD(&lit_733, s32 *, 0x20);
    M2C_FIELD(temp_r17_2507, s32 *, 0x24) = (s32) M2C_FIELD(&lit_733, s32 *, 0x24);
    M2C_FIELD(temp_r17_2507, s32 *, 0x28) = (s32) M2C_FIELD(&lit_733, s32 *, 0x28);
    M2C_FIELD(temp_r17_2507, s32 *, 0x2C) = (s32) M2C_FIELD(&lit_733, s32 *, 0x2C);
    M2C_FIELD(temp_r17_2507, s32 *, 0x30) = (s32) M2C_FIELD(&lit_733, s32 *, 0x30);
    M2C_FIELD(temp_r17_2507, s32 *, 0x34) = (s32) M2C_FIELD(&lit_733, s32 *, 0x34);
    M2C_FIELD(temp_r17_2507, s32 *, 0x38) = (s32) M2C_FIELD(&lit_733, s32 *, 0x38);
    M2C_FIELD(temp_r17_2507, s32 *, 0x3C) = (s32) M2C_FIELD(&lit_733, s32 *, 0x3C);
    M2C_FIELD(temp_r17_2507, s32 *, 0x40) = (s32) M2C_FIELD(&lit_733, s32 *, 0x40);
    M2C_FIELD(temp_r17_2507, s32 *, 0x44) = (s32) M2C_FIELD(&lit_733, s32 *, 0x44);
    SPYRO_BOUNCE_Y_SPEED = (f32) temp_f1_2551;
    SPYRO_MIN_JUMP_Y_VELOCITY = (f32) (380000.0 * temp_f0_2548);
    M2C_FIELD(temp_r17_2507, s32 *, 0x48) = (s32) M2C_FIELD(&lit_733, s32 *, 0x48);
    M2C_FIELD(temp_r17_2507, s32 *, 0x4C) = (s32) M2C_FIELD(&lit_733, s32 *, 0x4C);
    M2C_FIELD(temp_r17_2507, s32 *, 0x50) = (s32) M2C_FIELD(&lit_733, s32 *, 0x50);
    temp_r8_2579 = &lit_733 + 0x18C;
    sp48 = M2C_FIELD(&lit_733, s32 *, 0x148);
    M2C_FIELD(temp_r8_2579, s32 *, 0x20) = (s32) M2C_FIELD(&lit_733, s32 *, 0x140);
    sp8 = M2C_FIELD(&lit_733, s32 *, 0x14C);
    M2C_FIELD(temp_r8_2579, s32 *, 0x28) = sp48;
    spC = M2C_FIELD(&lit_733, s32 *, 0x150);
    M2C_FIELD(temp_r8_2579, s32 *, 0x2C) = sp8;
    sp10 = M2C_FIELD(&lit_733, s32 *, 0x154);
    M2C_FIELD(temp_r8_2579, s32 *, 0x30) = spC;
    sp14 = M2C_FIELD(&lit_733, s32 *, 0x158);
    M2C_FIELD(temp_r8_2579, s32 *, 0x34) = sp10;
    sp18 = M2C_FIELD(&lit_733, s32 *, 0x15C);
    M2C_FIELD(temp_r8_2579, s32 *, 0x38) = sp14;
    sp1C = M2C_FIELD(&lit_733, s32 *, 0x160);
    M2C_FIELD(temp_r8_2579, s32 *, 0x3C) = sp18;
    sp20 = M2C_FIELD(&lit_733, s32 *, 0x164);
    M2C_FIELD(temp_r8_2579, s32 *, 0x40) = sp1C;
    sp24 = M2C_FIELD(&lit_733, s32 *, 0x168);
    M2C_FIELD(temp_r8_2579, s32 *, 0x44) = sp20;
    sp28 = M2C_FIELD(&lit_733, s32 *, 0x16C);
    M2C_FIELD(temp_r8_2579, s32 *, 0x48) = sp24;
    sp2C = M2C_FIELD(&lit_733, s32 *, 0x170);
    M2C_FIELD(temp_r8_2579, s32 *, 0x4C) = sp28;
    sp30 = M2C_FIELD(&lit_733, s32 *, 0x174);
    M2C_FIELD(temp_r8_2579, s32 *, 0x50) = sp2C;
    sp34 = M2C_FIELD(&lit_733, s32 *, 0x178);
    M2C_FIELD(temp_r8_2579, s32 *, 0x54) = sp30;
    sp38 = M2C_FIELD(&lit_733, s32 *, 0x17C);
    M2C_FIELD(temp_r8_2579, s32 *, 0x58) = sp34;
    sp3C = M2C_FIELD(&lit_733, s32 *, 0x180);
    M2C_FIELD(temp_r8_2579, s32 *, 0x5C) = sp38;
    sp40 = M2C_FIELD(&lit_733, s32 *, 0x184);
    M2C_FIELD(temp_r8_2579, s32 *, 0x60) = sp3C;
    M2C_FIELD(temp_r8_2579, s32 *, 0x64) = sp40;
    sp44 = M2C_FIELD(&lit_733, s32 *, 0x188);
    M2C_FIELD(temp_r17_2507, s32 *, 0x54) = (s32) M2C_FIELD(&lit_733, s32 *, 0x54);
    M2C_FIELD(temp_r17_2507, s32 *, 0x58) = (s32) M2C_FIELD(&lit_733, s32 *, 0x58);
    M2C_FIELD(temp_r17_2507, s32 *, 0x5C) = (s32) M2C_FIELD(&lit_733, s32 *, 0x5C);
    M2C_FIELD(temp_r17_2507, s32 *, 0x60) = (s32) M2C_FIELD(&lit_733, s32 *, 0x60);
    M2C_FIELD(temp_r17_2507, s32 *, 0x64) = (s32) M2C_FIELD(&lit_733, s32 *, 0x64);
    M2C_FIELD(temp_r17_2507, s32 *, 0x68) = (s32) M2C_FIELD(&lit_733, s32 *, 0x68);
    M2C_FIELD(temp_r17_2507, s32 *, 0x6C) = (s32) M2C_FIELD(&lit_733, s32 *, 0x6C);
    M2C_FIELD(temp_r17_2507, s32 *, 0x70) = (s32) M2C_FIELD(&lit_733, s32 *, 0x70);
    M2C_FIELD(temp_r17_2507, s32 *, 0x74) = (s32) M2C_FIELD(&lit_733, s32 *, 0x74);
    M2C_FIELD(temp_r17_2507, s32 *, 0x78) = (s32) M2C_FIELD(&lit_733, s32 *, 0x78);
    M2C_FIELD(temp_r17_2507, s32 *, 0x7C) = (s32) M2C_FIELD(&lit_733, s32 *, 0x7C);
    M2C_FIELD(temp_r17_2507, s32 *, 0x80) = (s32) M2C_FIELD(&lit_733, s32 *, 0x80);
    M2C_FIELD(temp_r17_2507, s32 *, 0x84) = (s32) M2C_FIELD(&lit_733, s32 *, 0x84);
    M2C_FIELD(temp_r17_2507, s32 *, 0x88) = (s32) M2C_FIELD(&lit_733, s32 *, 0x88);
    M2C_FIELD(temp_r17_2507, s32 *, 0x8C) = (s32) M2C_FIELD(&lit_733, s32 *, 0x8C);
    M2C_FIELD(&lit_733, s32 *, 0x18C) = (s32) M2C_FIELD(&lit_733, s32 *, 0x120);
    M2C_FIELD(&lit_733, s32 *, 0x190) = (s32) M2C_FIELD(&lit_733, s32 *, 0x124);
    M2C_FIELD(&lit_733, s32 *, 0x194) = (s32) M2C_FIELD(&lit_733, s32 *, 0x128);
    M2C_FIELD(temp_r8_2579, s32 *, 0xC) = (s32) M2C_FIELD(&lit_733, s32 *, 0x12C);
    M2C_FIELD(temp_r8_2579, s32 *, 0x10) = (s32) M2C_FIELD(&lit_733, s32 *, 0x130);
    M2C_FIELD(temp_r8_2579, s32 *, 0x14) = (s32) M2C_FIELD(&lit_733, s32 *, 0x134);
    M2C_FIELD(temp_r8_2579, s32 *, 0x18) = (s32) M2C_FIELD(&lit_733, s32 *, 0x138);
    M2C_FIELD(temp_r8_2579, s32 *, 0x1C) = (s32) M2C_FIELD(&lit_733, s32 *, 0x13C);
    M2C_FIELD(temp_r8_2579, s32 *, 0x24) = (s32) M2C_FIELD(&lit_733, s32 *, 0x144);
    M2C_FIELD(temp_r8_2579, s32 *, 0x68) = (s32) M2C_FIELD(&lit_733, s32 *, 0x188);
}
#endif
