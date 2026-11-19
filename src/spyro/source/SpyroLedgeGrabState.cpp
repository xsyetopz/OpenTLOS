#include "spyro/source/SpyroLedgeGrabState.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "spyro/source/InputModifier.h"
#include "spyro/source/MobilePlatform.h"
#include "spyro/source/Spyro.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "common/Source/MKInput.h"
#include "spyro/source/KDMath.h"
#include <m2c_macros.h>

extern f32 PULL_UP_Y_VELOCITY;
extern f32 SPYRO_BOUNCE_Y_SPEED;
extern f32 SPYRO_MIN_JUMP_Y_VELOCITY;
extern f32 gUpdateTimeDelta;
static M2C_UNK lit_737;                                /* unable to generate initializer: unknown type */
SpyroLedgeGrabState states__19SpyroLedgeGrabState;  /* unable to generate initializer: confusing struct layout */

void SpyroLedgeGrabState::PullUpDescendTransition() {
    s8 sp1D;
    s8 sp1C;
    f32 sp18;
    f32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    Spyro *temp_r3_59;

    spC = 0;
    sp10 = 0x5B;
    sp8 = 0x187;
    sp14 = 0.0f;
    sp18 = 0.2f;
    sp1C = 1;
    sp1D = 1;
    temp_r3_59 = this->unk10;
    temp_r3_59->TryChangeState(M2C_FIELD(temp_r3_59->unk27C, s32 *, 0x16C) > 0, 4U, (MKMessage *) &sp8, 0U);
}

void SpyroLedgeGrabState::PullUpDescendUpdate() {
    PullUpDescendTransition();
}

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void SpyroLedgeGrabState::PullUpDescendEnter() {
    Spyro *temp_r3_100;
    f32 temp_f0_105;
    f32 temp_f1_103;
    f32 var_f2_104;

    this->unk10->SetAnim(0x5AU, 0.1f, (Spyro::AnimScriptNode) 0, 0U, 1.0f);
    temp_r3_100 = this->unk10;
    temp_r3_100->unk390 = 3800.0f;
    temp_f1_103 = temp_r3_100->unk390;
    var_f2_104 = temp_r3_100->unk33C;
    temp_f0_105 = -temp_f1_103;
    if (var_f2_104 < temp_f1_103) {

    } else {
        var_f2_104 = temp_f1_103;
    }
    if (var_f2_104 > temp_f0_105) {

    } else {
        var_f2_104 = temp_f0_105;
    }
    temp_r3_100->unk33C = var_f2_104;
    this->unk10->unk38C = 1900.0f;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk0'
s32 SpyroLedgeGrabState::PullUpAscendTransition() {
    if ((this->unk10->unk33C <= 0.0f) && ((s32) this->unk14.unk0 != 2)) {
        this->unk14.SetState(this, 2, 0U);
        return 1;
    }
    return 0;
}
#endif

void SpyroLedgeGrabState::PullUpAscendUpdate() {
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    Spyro *temp_r3_169;
    f64 temp_f0_185;
    void *temp_r4_170;

    temp_r3_169 = this->unk10;
    temp_r4_170 = temp_r3_169->unk8;
    sp8 = -M2C_FIELD(temp_r4_170, f32 *, 0x20);
    spC = -M2C_FIELD(temp_r4_170, f32 *, 0x24);
    sp10 = -M2C_FIELD(temp_r4_170, f32 *, 0x28);
    sp28 = (f64) sp8;
    sp30 = (f64) sp10;
    temp_f0_185 = sp28 * 5.60222949e-315;
    sp18 = temp_f0_185;
    sp38 = temp_f0_185;
    sp20 = (f32) sp30 * 300.0f;
    sp40 = (f64) sp20;
    temp_r3_169->SetDesiredVelocityHoriz(*((MKVector3 *) &sp38), 3800.0f);
    PullUpAscendTransition();
}

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void SpyroLedgeGrabState::PullUpAscendEnter() {
    this->unk10->SetAnim(0x59U, 0.1f, (Spyro::AnimScriptNode) 0, 0U, 1.0f);
    M2C_FIELD(this, f64 *, 0x48) = (f64) M2C_FIELD(&MKVector3::zero, f64 *, 0);
    M2C_FIELD(this, f64 *, 0x50) = (f64) M2C_FIELD(&MKVector3::zero, f64 *, 8);
    this->unk10->SetModelVisualOffset(this->unk48, 0U);
    this->unk10->unk38C = 1900.0f;
    this->unk10->SetDesiredVelocityVectical(PULL_UP_Y_VELOCITY, 540000.0f);
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
s32 SpyroLedgeGrabState::AttachTransition() {
    InputModifier *temp_r3_253;
    s32 var_r3_266;
    u8 var_r4_255;

    temp_r3_253 = this->unk10->GetInput();
    var_r4_255 = 0;
    if (((u8) temp_r3_253->unk5 != 0) || ((u8) temp_r3_253->unk4 != 0)) {
        var_r4_255 = 1;
    }
    if (var_r4_255 != 0) {
        var_r3_266 = 0;
    } else {
        var_r3_266 = MKInput_Pressed(0xE, (MKInputDevices) temp_r3_253->unk0);
    }
    if ((u8) var_r3_266 == 0) {
        var_r3_266 = this->unk10->GetAnimScript((Spyro::AnimScriptNode) 0)->unk2C & 1;
    }
    if (((u8) var_r3_266 != 0) && ((s32) this->unk14.unk0 != 1)) {
        this->unk14.SetState(this, 1, 0U);
        return 1;
    }
    return 0;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'Spyro *' to
void SpyroLedgeGrabState::AttachUpdate() {
    f64 sp50;
    f64 sp48;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    Spyro *temp_r3_322;
    f32 temp_f2_387;
    f64 temp_f0_320;
    f64 temp_f0_390;
    u8 var_r0_338;
    u8 var_r0_370;

    ((Spyro *) &sp38)->GetRefPos((Spyro::RefPoints) this->unk10);
    temp_f0_320 = M2C_FIELD(this, f64 *, 0x28) - sp38;
    sp18 = temp_f0_320;
    temp_r3_322 = this->unk10;
    sp48 = temp_f0_320;
    sp20 = this->unk30 - sp40;
    sp50 = (f64) sp20;
    if ((s32) M2C_FIELD(temp_r3_322->unk27C, s32 *, 0x2D4) > 0) {
        var_r0_338 = 0;
        if ((this->unk48.unk0 == MKVector3::zero.unk0) && (this->unk48.unk4 == MKVector3::zero.unk4) && (this->unk48.unk8 == MKVector3::zero.unk8)) {
            var_r0_338 = 1;
        }
        if (var_r0_338 != 0) {
            temp_r3_322->SetDesiredVelocity(MKVector3::zero, 540000.0f);
            M2C_FIELD(this, f32 *, 0x48) = sp48;
            M2C_FIELD(this, f32 *, 0x50) = sp50;
            this->unk10->SetModelVisualOffset(this->unk48, 0U);
        }
    } else {
        var_r0_370 = 0;
        if ((this->unk48.unk0 == MKVector3::zero.unk0) && (this->unk48.unk4 == MKVector3::zero.unk4) && (this->unk48.unk8 == MKVector3::zero.unk8)) {
            var_r0_370 = 1;
        }
        if (var_r0_370 != 0) {
            temp_f2_387 = 1.0f / gUpdateTimeDelta;
            temp_f0_390 = sp48 * (f64) temp_f2_387;
            sp8 = temp_f0_390;
            sp28 = temp_f0_390;
            sp10 = (f32) sp50 * temp_f2_387;
            sp30 = (f64) sp10;
            this->unk10->SetDesiredVelocity(*((MKVector3 *) &sp28), 540000.0f);
        }
    }
    AttachTransition();
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void SpyroLedgeGrabState::AttachEnter() {
    this->unk10->SetDesiredVelocity(MKVector3::zero, 540000.0f);
    M2C_FIELD(this, f64 *, 0x48) = (f64) M2C_FIELD(&MKVector3::zero, f64 *, 0);
    M2C_FIELD(this, f64 *, 0x50) = (f64) M2C_FIELD(&MKVector3::zero, f64 *, 8);
    this->unk10->SetAnim(0x58U, 0.13f, (Spyro::AnimScriptNode) 0, 0U, 1.0f);
}
#endif

void SpyroLedgeGrabState::ProcessAnimEvent(unsigned int arg0) {

}

#if 0 // DRAFT: undefined identifier 'PlatformMoveMsg'
void SpyroLedgeGrabState::Message(MKMessage *arg0) {
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    MKVector3 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f2_476;
    f32 temp_f6_486;
    f32 temp_f7_491;
    s32 temp_r0_461;
    void *temp_r3_474;
    void *temp_r6_479;
    void *temp_r7_477;

    temp_r0_461 = arg0->unk0;
    switch (temp_r0_461) {                          /* irregular */
    case 34:
        temp_r3_474 = checked_cast<PlatformMoveMsg *, MKMessage>(arg0);
        temp_f2_476 = this->unk2C;
        temp_r7_477 = M2C_FIELD(temp_r3_474, void **, 0x10);
        temp_r6_479 = M2C_FIELD(temp_r3_474, void **, 0x14);
        temp_f6_486 = this->unk28;
        temp_f7_491 = this->unk30;
        sp8 = M2C_FIELD(temp_r7_477, f32 *, 0x30) + ((temp_f7_491 * M2C_FIELD(temp_r7_477, f32 *, 0x20)) + ((temp_f6_486 * M2C_FIELD(temp_r7_477, f32 *, 0)) + (temp_f2_476 * M2C_FIELD(temp_r7_477, f32 *, 0x10))));
        spC = M2C_FIELD(temp_r7_477, f32 *, 0x34) + ((temp_f7_491 * M2C_FIELD(temp_r7_477, f32 *, 0x24)) + ((temp_f6_486 * M2C_FIELD(temp_r7_477, f32 *, 4)) + (temp_f2_476 * M2C_FIELD(temp_r7_477, f32 *, 0x14))));
        sp38 = (f64) sp8;
        sp10 = M2C_FIELD(temp_r7_477, f32 *, 0x38) + ((temp_f7_491 * M2C_FIELD(temp_r7_477, f32 *, 0x28)) + ((temp_f6_486 * M2C_FIELD(temp_r7_477, f32 *, 8)) + (temp_f2_476 * M2C_FIELD(temp_r7_477, f32 *, 0x18))));
        sp40 = (f64) sp10;
        sp18 = M2C_FIELD(temp_r6_479, f32 *, 0x30) + (((f32) sp40 * M2C_FIELD(temp_r6_479, f32 *, 0x20)) + (((f32) sp38 * M2C_FIELD(temp_r6_479, f32 *, 0)) + ((*(f32 *) ((u8 *) &sp38 + 0x4)) * M2C_FIELD(temp_r6_479, f32 *, 0x10))));
        sp1C = M2C_FIELD(temp_r6_479, f32 *, 0x34) + (((f32) sp40 * M2C_FIELD(temp_r6_479, f32 *, 0x24)) + (((f32) sp38 * M2C_FIELD(temp_r6_479, f32 *, 4)) + ((*(f32 *) ((u8 *) &sp38 + 0x4)) * M2C_FIELD(temp_r6_479, f32 *, 0x14))));
        sp20 = M2C_FIELD(temp_r6_479, f32 *, 0x38) + (((f32) sp40 * M2C_FIELD(temp_r6_479, f32 *, 0x28)) + (((f32) sp38 * M2C_FIELD(temp_r6_479, f32 *, 8)) + ((*(f32 *) ((u8 *) &sp38 + 0x4)) * M2C_FIELD(temp_r6_479, f32 *, 0x18))));
        M2C_FIELD(this, f32 *, 0x28) = (f64) sp18;
        M2C_FIELD(this, f32 *, 0x30) = (f64) sp20;
        sp48 = (f64) sp18;
        sp50 = (f64) sp20;
        KDMath_RotateVectorByYaw(sp28, M2C_FIELD(M2C_FIELD(temp_r3_474, void **, 0xC), f32 *, 4));
        M2C_FIELD(this, f64 *, 0x38) = M2C_BITWISE(f64, sp28);
        M2C_FIELD(this, f64 *, 0x40) = (f64) sp28.unk8;
        return;
    case 36:
        this->unk10->TryChangeState(1U, 6U, NULL, 0U);
        /* fallthrough */
    case 41:
        return;
    }
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
s32 SpyroLedgeGrabState::Transition() {
    void *sp10;
    s32 spC;
    s32 sp8;
    MKProp *temp_r3_590;
    u8 var_r4_600;

    this->unk10->unk3D2 = 1;
    spC = 0;
    sp10 = NULL;
    sp8 = 0x27;
    temp_r3_590 = this->unk10->unk3EC;
    if (temp_r3_590 != NULL) {
        M2C_FIELD(temp_r3_590->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp8);
    }
    var_r4_600 = 0;
    if (((sp10 != NULL) && ((u8) M2C_FIELD(sp10, u8 *, 4) == 0)) || (((u8) this->unk58 != 0) && ((MKProp *) this->unk10->unk3EC == NULL))) {
        var_r4_600 = 1;
    }
    this->unk10->TryChangeState(var_r4_600, 6U, NULL, 0U);
}
#endif

void SpyroLedgeGrabState::Update() {
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;

    sp8 = -this->unk38.unk0;
    spC = -this->unk38.unk4;
    sp10 = -this->unk38.unk8;
    sp18 = (f64) sp8;
    sp20 = (f64) sp10;
    this->unk10->unk3A8.YawTowards(*((MKVector3 *) &sp18), 10.0f);
    this->unk14.Update(this, 0);
}

void SpyroLedgeGrabState::Exit() {
    Spyro *temp_r3_679;

    this->unk10->SetModelVisualOffset(MKVector3::zero, 0U);
    temp_r3_679 = this->unk10;
    temp_r3_679->unk428 |= 0x20000;
    this->unk10->PlatformDetach();
    this->unk10->SetMeleeButtonStateTimeout(0U);
    this->unk14.Exit(this);
}

#if 0 // DRAFT: undefined identifier 'SpyroLedgeGrabMessage'
void SpyroLedgeGrabState::Enter(SpyroStateMessages &arg0) {
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    MKProp *temp_r3_736;
    MKProp *temp_r4_729;
    Spyro *temp_r3_760;
    Spyro *temp_r4_723;
    f64 temp_f0_764;
    u8 var_r30_737;
    void *temp_r29_717;

    temp_r29_717 = checked_cast<SpyroLedgeGrabMessage *, MKMessage>(arg0.GetMessage(0x184));
    M2C_FIELD(this, f64 *, 0x48) = (f64) M2C_FIELD(&MKVector3::zero, f64 *, 0);
    M2C_FIELD(this, f64 *, 0x50) = (f64) M2C_FIELD(&MKVector3::zero, f64 *, 8);
    this->unk10->unk38C = 0.0f;
    temp_r4_723 = this->unk10;
    temp_r4_723->unk428 &= 0xFFF9FEDE;
    this->unk10->PlatformDetach();
    temp_r4_729 = M2C_FIELD(temp_r29_717, MKProp **, 0x28);
    if (temp_r4_729 != NULL) {
        this->unk10->PlatformAttach(temp_r4_729, NULL);
    }
    temp_r3_736 = M2C_FIELD(temp_r29_717, MKProp **, 0x28);
    var_r30_737 = 0;
    if ((temp_r3_736 != NULL) && (((MobilePlatformDescriptor *) temp_r3_736->unk0)->IsDescriptor(M2C_ERROR(/* Read from unset register $r4 */)) != 0)) {
        var_r30_737 = 1;
    }
    this->unk58 = var_r30_737;
    M2C_FIELD(this, f64 *, 0x28) = (f64) M2C_FIELD(temp_r29_717, f64 *, 8);
    M2C_FIELD(this, f64 *, 0x30) = (f64) M2C_FIELD(temp_r29_717, f64 *, 0x10);
    M2C_FIELD(this, f64 *, 0x38) = (f64) M2C_FIELD(temp_r29_717, f64 *, 0x18);
    M2C_FIELD(this, f64 *, 0x40) = (f64) M2C_FIELD(temp_r29_717, f64 *, 0x20);
    this->unk14.SetState(this, 0, 0U);
    temp_r3_760 = this->unk10;
    temp_f0_764 = M2C_FIELD(temp_r3_760, f64 *, 0x338) * 5.222099017e-315;
    sp8 = temp_f0_764;
    sp18 = temp_f0_764;
    sp10 = temp_r3_760->unk340 * 0.5f;
    sp20 = (f64) sp10;
    temp_r3_760->SetDesiredVelocity(*((MKVector3 *) &sp18), 540000.0f);
    this->unk10->CheckForLedge(MKVector3::zero, (MKVector3 *) &this->unk28, NULL, &this->unk38, NULL);
    this->unk10->SetMeleeButtonStateTimeout(1U);
}
#endif

void SpyroLedgeGrabState::Deinit() {
    this->unk14.Deinit(this);
}

#if 0 // DRAFT: undefined identifier 'Init__37KDStateMachine'
void SpyroLedgeGrabState::Init(Spyro *arg0) {
    this->unk10 = arg0;
    M2C_FIELD(this, f64 *, 0x28) = (f64) M2C_FIELD(&MKVector3::zero, f64 *, 0);
    M2C_FIELD(this, f64 *, 0x30) = (f64) M2C_FIELD(&MKVector3::zero, f64 *, 8);
    M2C_FIELD(this, f64 *, 0x38) = (f64) M2C_FIELD(this, f64 *, 0x28);
    M2C_FIELD(this, f64 *, 0x40) = (f64) M2C_FIELD(this, f64 *, 0x30);
    M2C_FIELD(this, f64 *, 0x48) = (f64) M2C_FIELD(&MKVector3::zero, f64 *, 0);
    M2C_FIELD(this, f64 *, 0x50) = (f64) M2C_FIELD(&MKVector3::zero, f64 *, 8);
    this->unk58 = 0;
    Init__37KDStateMachine<19SpyroLedgeGrabState>FPQ237KDStateMachine<19SpyroLedgeGrabState>5StateP37KDStateMachine<19SpyroLedgeGrabState>(&this->unk14, (KDStateMachine<SpyroLedgeGrabState>::State *) &SpyroLedgeGrabState::states, NULL);
}
#endif

#if 0 // DRAFT: undefined identifier '__ptmf_null'
void SpyroLedgeGrabState_cpp::__sinit() {
    s32 sp10;
    s32 spC;
    s32 sp8;
    f64 temp_f0_1117;
    f64 temp_f11_1115;
    f64 temp_f11_1136;
    f64 temp_f11_1152;
    f64 temp_f1_1123;
    f64 temp_f3_1116;
    f64 temp_f4_1101;
    f64 temp_f4_1148;
    f64 temp_f6_1120;
    f64 temp_f7_1103;
    f64 temp_f7_1127;
    f64 temp_f7_1145;
    void *temp_r27_1113;

    temp_f4_1101 = __frsqrte(2014000.0);
    temp_f7_1103 = __frsqrte(380000.0);
    temp_r27_1113 = &lit_737 + 0x48;
    temp_f11_1115 = __frsqrte(456000.03125);
    temp_f3_1116 = 0.5 * temp_f7_1103;
    temp_f0_1117 = temp_f11_1115 * temp_f11_1115;
    temp_f6_1120 = 0.5 * temp_f4_1101 * -((2014000.0 * (temp_f4_1101 * temp_f4_1101)) - 3.0);
    temp_f1_1123 = -((380000.0 * (temp_f7_1103 * temp_f7_1103)) - 3.0);
    M2C_FIELD(&lit_737, s32 *, 0x48) = (s32) M2C_FIELD(&lit_737, s32 *, 0);
    M2C_FIELD(&lit_737, s32 *, 0x4C) = (s32) M2C_FIELD(&lit_737, s32 *, 4);
    temp_f7_1127 = temp_f3_1116 * temp_f1_1123;
    M2C_FIELD(&lit_737, s32 *, 0x50) = (s32) M2C_FIELD(&lit_737, s32 *, 8);
    sp8 = M2C_FIELD(&__ptmf_null, s32 *, 0);
    spC = M2C_FIELD(&__ptmf_null, s32 *, 4);
    temp_f11_1136 = 0.5 * temp_f11_1115 * -((456000.03125 * temp_f0_1117) - 3.0);
    sp10 = M2C_FIELD(&__ptmf_null, s32 *, 8);
    M2C_FIELD(temp_r27_1113, s32 *, 0xC) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 0);
    M2C_FIELD(temp_r27_1113, s32 *, 0x10) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 4);
    M2C_FIELD(temp_r27_1113, s32 *, 0x14) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 8);
    temp_f7_1145 = 0.5 * temp_f6_1120 * -((2014000.0 * (temp_f6_1120 * temp_f6_1120)) - 3.0);
    temp_f4_1148 = 0.5 * temp_f7_1127 * -((380000.0 * (temp_f7_1127 * temp_f7_1127)) - 3.0);
    temp_f11_1152 = 0.5 * temp_f11_1136 * -((456000.03125 * (temp_f11_1136 * temp_f11_1136)) - 3.0);
    SPYRO_BOUNCE_Y_SPEED = (f32) (2014000.0 * (0.5 * temp_f7_1145 * -((2014000.0 * (temp_f7_1145 * temp_f7_1145)) - 3.0)));
    SPYRO_MIN_JUMP_Y_VELOCITY = (f32) (380000.0 * (0.5 * temp_f4_1148 * -((380000.0 * (temp_f4_1148 * temp_f4_1148)) - 3.0)));
    PULL_UP_Y_VELOCITY = (f32) (456000.03125 * (0.5 * temp_f11_1152 * -((456000.03125 * (temp_f11_1152 * temp_f11_1152)) - 3.0)));
    M2C_FIELD(temp_r27_1113, s32 *, 0x18) = (s32) M2C_FIELD(&lit_737, s32 *, 0xC);
    M2C_FIELD(temp_r27_1113, s32 *, 0x1C) = (s32) M2C_FIELD(&lit_737, s32 *, 0x10);
    M2C_FIELD(temp_r27_1113, s32 *, 0x20) = (s32) M2C_FIELD(&lit_737, s32 *, 0x14);
    M2C_FIELD(temp_r27_1113, s32 *, 0x24) = (s32) M2C_FIELD(&lit_737, s32 *, 0x18);
    M2C_FIELD(temp_r27_1113, s32 *, 0x28) = (s32) M2C_FIELD(&lit_737, s32 *, 0x1C);
    M2C_FIELD(temp_r27_1113, s32 *, 0x2C) = (s32) M2C_FIELD(&lit_737, s32 *, 0x20);
    M2C_FIELD(temp_r27_1113, s32 *, 0x30) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 0);
    M2C_FIELD(temp_r27_1113, s32 *, 0x34) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 4);
    M2C_FIELD(temp_r27_1113, s32 *, 0x38) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 8);
    M2C_FIELD(temp_r27_1113, s32 *, 0x3C) = (s32) M2C_FIELD(&lit_737, s32 *, 0x24);
    M2C_FIELD(temp_r27_1113, s32 *, 0x40) = (s32) M2C_FIELD(&lit_737, s32 *, 0x28);
    M2C_FIELD(temp_r27_1113, s32 *, 0x44) = (s32) M2C_FIELD(&lit_737, s32 *, 0x2C);
    M2C_FIELD(temp_r27_1113, s32 *, 0x48) = (s32) M2C_FIELD(&lit_737, s32 *, 0x30);
    M2C_FIELD(temp_r27_1113, s32 *, 0x4C) = (s32) M2C_FIELD(&lit_737, s32 *, 0x34);
    M2C_FIELD(temp_r27_1113, s32 *, 0x50) = (s32) M2C_FIELD(&lit_737, s32 *, 0x38);
    M2C_FIELD(temp_r27_1113, s32 *, 0x54) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 0);
    M2C_FIELD(temp_r27_1113, s32 *, 0x58) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 4);
    M2C_FIELD(temp_r27_1113, s32 *, 0x5C) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 8);
    M2C_FIELD(temp_r27_1113, s32 *, 0x60) = (s32) M2C_FIELD(&lit_737, s32 *, 0x3C);
    M2C_FIELD(temp_r27_1113, s32 *, 0x64) = (s32) M2C_FIELD(&lit_737, s32 *, 0x40);
    M2C_FIELD(temp_r27_1113, s32 *, 0x68) = (s32) M2C_FIELD(&lit_737, s32 *, 0x44);
}
#endif
