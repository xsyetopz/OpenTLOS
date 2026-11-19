#include "spyro/source/SpyroIdleState.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "spyro/source/EventCamera.h"
#include "spyro/source/GameData.h"
#include "spyro/source/KDCamera.h"
#include "spyro/source/Spyro.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include <m2c_macros.h>

extern f32 SPYRO_BOUNCE_Y_SPEED;
extern f32 SPYRO_MIN_JUMP_Y_VELOCITY;
extern M2C_UNK gb;
#if 0 // DRAFT: illegal explicit conversion from 'float' to
static M2C_UNK lit_728;                                /* unable to generate initializer: unknown type */
SpyroIdleState states__14SpyroIdleState;            /* unable to generate initializer: confusing struct layout */

u8 SpyroIdleState::AnyToBreathingTranistion() {
    EventCamera *temp_r3_31;
    EventCamera *temp_r3_71;
    u8 var_r0_74;
    u8 var_r3_34;
    u8 var_r3_64;

    temp_r3_31 = EventCamera_GetCurrent();
    var_r3_34 = temp_r3_31 == NULL;
    if ((u8) (temp_r3_31 == NULL) != 0) {
        var_r3_34 = M2C_FIELD(this->unk10, u8 *, 0x3D3);
    }
    if (var_r3_34 != 0) {
        var_r3_34 = M2C_FIELD(this->unk10->unk258, u8 *, 0x14);
    }
    if (var_r3_34 != 0) {
        var_r3_34 = M2C_FIELD(GameData::gameData, s32 *, 0x158) != 2;
    }
    if ((var_r3_34 != 0) && ((s32) this->unk14.unk0 != 4)) {
        this->unk14.SetState(this, 4, 0U);
        var_r3_64 = 1;
    } else {
        var_r3_64 = 0;
    }
    if (var_r3_64 == 0) {
        temp_r3_71 = EventCamera_GetCurrent();
        var_r0_74 = temp_r3_71 == NULL;
        if ((u8) (temp_r3_71 == NULL) != 0) {
            var_r0_74 = M2C_FIELD(this->unk10, u8 *, 0x3D3);
        }
        if ((var_r0_74 != 0) && ((s32) this->unk14.unk0 != 3)) {
            this->unk14.SetState(this, 3, 0U);
            return 1U;
        }
        var_r3_64 = 0;
        /* Duplicate return node #17. Try simplifying control flow for better match */
        return var_r3_64;
    }
    return var_r3_64;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk14'
u8 SpyroIdleState::Breathing2Transition() {
    Spyro *temp_r3_126;
    u8 var_r0_127;
    u8 var_r3_119;

    if ((u8) (EventCamera_GetCurrent() != NULL) != 0) {
        this->unk14.SetState(this, 0, 1U);
        var_r3_119 = 1;
    } else {
        var_r3_119 = 0;
    }
    if (var_r3_119 == 0) {
        temp_r3_126 = this->unk10;
        var_r0_127 = M2C_FIELD(temp_r3_126, u8 *, 0x3D3);
        if (var_r0_127 != 0) {
            var_r0_127 = M2C_FIELD(temp_r3_126->unk258, u8 *, 0x14) == 0;
        }
        if (var_r0_127 != 0) {
            this->unk14.SetState(this, 3, 1U);
            var_r3_119 = 1;
        } else {
            var_r3_119 = 0;
        }
    }
    if (var_r3_119 == 0) {
        if (this->unk10->GetAnimScript((Spyro::AnimScriptNode) 0)->unk2C & 1) {
            this->unk14.SetState(this, 0, 1U);
            return 1U;
        }
        var_r3_119 = 0;
        /* Duplicate return node #13. Try simplifying control flow for better match */
        return var_r3_119;
    }
    return var_r3_119;
}
#endif

void SpyroIdleState::Breathing2Update() {
    Breathing2Transition();
}

void SpyroIdleState::Breathing2Exit() {

}

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void SpyroIdleState::Breathing2Enter() {
    this->unk10->SetAnim(3U, 0.1f, (Spyro::AnimScriptNode) 0, 0U, 1.0f);
}
#endif

#if 0 // DRAFT: undefined identifier 'unk14'
s32 SpyroIdleState::BreathingTransition() {
    u8 temp_r0_219;
    u8 var_r0_222;

    temp_r0_219 = M2C_FIELD(this->unk10, u8 *, 0x3D3);
    var_r0_222 = temp_r0_219 == 0;
    if ((u8) (temp_r0_219 == 0) == 0) {
        var_r0_222 = EventCamera_GetCurrent() != NULL;
    }
    if (var_r0_222 != 0) {
        this->unk14.SetState(this, 0, 1U);
        return 1;
    }
    return 0;
}
#endif

void SpyroIdleState::BreathingUpdate() {
    BreathingTransition();
}

void SpyroIdleState::BreathingExit() {

}

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void SpyroIdleState::BreathingEnter() {
    this->unk10->SetAnim(2U, 0.1f, (Spyro::AnimScriptNode) 0, 0U, 1.0f);
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
s32 SpyroIdleState::OneOffIdleTransition() {
    if ((this->unk10->GetAnimScript((Spyro::AnimScriptNode) 0)->unk2C & 1) && ((s32) this->unk14.unk0 != 0)) {
        this->unk14.SetState(this, 0, 0U);
        return 1;
    }
    return 0;
}
#endif

void SpyroIdleState::OneOffIdleUpdate() {
    OneOffIdleTransition();
}

void SpyroIdleState::OneOffIdleExit() {
    Spyro *temp_r4_342;
    Spyro *temp_r4_350;

    if ((u8) this->unk5D == 0) {
        temp_r4_342 = this->unk10;
        temp_r4_342->unk428 |= 1;
    }
    if ((u8) this->unk5C == 0) {
        temp_r4_350 = this->unk10;
        temp_r4_350->unk428 |= 0x40000;
    }
    this->unk48 = -1;
    this->unk10->SetMeleeButtonStateTimeout(0U);
}

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void SpyroIdleState::OneOffIdleEnter() {
    Spyro *temp_r3_387;
    Spyro *temp_r3_395;
    s32 temp_r4_374;

    temp_r4_374 = this->unk50;
    if (temp_r4_374 > -1) {
        this->unk10->SetAnim((u32) temp_r4_374, this->unk58, (Spyro::AnimScriptNode) 0, 0U, 1.0f);
    }
    if ((u8) this->unk5D == 0) {
        temp_r3_387 = this->unk10;
        temp_r3_387->unk428 &= 0xFFFFFFFE;
    }
    if ((u8) this->unk5C == 0) {
        temp_r3_395 = this->unk10;
        temp_r3_395->unk428 &= 0xFFFBFFFF;
    }
    this->unk10->SetMeleeButtonStateTimeout(1U);
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void SpyroIdleState::SelectAnimation() {
    MKProp *temp_r3_477;
    Spyro *temp_r4_476;
    s32 temp_r3_479;
    s32 temp_r5_418;
    u32 var_r6_493;
    void *var_r3_488;

    temp_r5_418 = this->unk3C;
    if ((temp_r5_418 == 0) && (M2C_FIELD(&gb, f32 *, 0x30C) >= this->unk28) && ((u8) M2C_FIELD(&gb, u8 *, 0x35D) == 0)) {
        if ((s32) this->unk2C == 5) {
            this->unk3C = 2;
            this->unk2C = 0;
        } else {
            this->unk3C = 1;
            this->unk2C += 1;
        }
        this->unk28 = M2C_FIELD(&gb, f32 *, 0x30C) + 10.0f;
    } else if ((temp_r5_418 != 0) && ((this->unk10->GetAnimScript((Spyro::AnimScriptNode) 0)->unk2C & 1) || ((s32) this->unk10->GetAnimScript((Spyro::AnimScriptNode) 0)->unk44 > 1))) {
        this->unk3C = 0;
        this->unk28 = M2C_FIELD(&gb, f32 *, 0x30C) + 10.0f;
    }
    temp_r4_476 = this->unk10;
    temp_r3_477 = temp_r4_476->unk26C.unk8;
    temp_r3_479 = M2C_FIELD(temp_r3_477, s32 *, 0x16C);
    if (((u32) (-temp_r3_479 & ~temp_r3_479) >> 0x1FU) != 0) {
        if (temp_r3_479 != 0) {
            var_r3_488 = &temp_r3_477->unk8 + ((temp_r3_479 - 1) * 0x58);
        } else {
            var_r3_488 = NULL;
        }
        var_r6_493 = M2C_FIELD(var_r3_488, u32 *, 0x44);
    } else {
        var_r6_493 = 0;
    }
    this->unk30.Update(temp_r4_476, 1U, var_r6_493, (IdleAnimNumber) this->unk3C, 0.0f);
}
#endif

#if 0 // DRAFT: undefined identifier 'unk14'
u8 SpyroIdleState::SlideTransition() {
    MKProp *temp_r3_522;
    s32 temp_r3_524;
    u32 var_r0_538;
    u8 var_r3_518;
    u8 var_r3_544;
    void *var_r3_533;

    var_r3_518 = AnyToBreathingTranistion();
    if (var_r3_518 == 0) {
        temp_r3_522 = this->unk10->unk26C.unk8;
        temp_r3_524 = M2C_FIELD(temp_r3_522, s32 *, 0x16C);
        if (((u32) (-temp_r3_524 & ~temp_r3_524) >> 0x1FU) != 0) {
            if (temp_r3_524 != 0) {
                var_r3_533 = &temp_r3_522->unk8 + ((temp_r3_524 - 1) * 0x58);
            } else {
                var_r3_533 = NULL;
            }
            var_r0_538 = M2C_FIELD(var_r3_533, u32 *, 0x44);
        } else {
            var_r0_538 = 0;
        }
        var_r3_544 = ((var_r0_538 >> 3U) & 1) ^ 1;
        if (var_r3_544 == 0) {
            var_r3_544 = (u8) ((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1FU);
        }
        if ((var_r3_544 != 0) && ((s32) this->unk14.unk0 != 0)) {
            this->unk14.SetState(this, 0, 0U);
            return 1U;
        }
        var_r3_518 = 0;
        /* Duplicate return node #13. Try simplifying control flow for better match */
        return var_r3_518;
    }
    return var_r3_518;
}
#endif

void SpyroIdleState::SlideUpdate() {
    SlideTransition();
}

void SpyroIdleState::SlideExit() {

}

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void SpyroIdleState::SlideEnter() {
    this->unk10->SetAnim(0xAU, 0.1f, (Spyro::AnimScriptNode) 0, 0U, 1.0f);
}
#endif

void SpyroIdleState::NormalTransition() {
    AnyToBreathingTranistion();
}

void SpyroIdleState::NormalUpdate() {
    SelectAnimation();
    NormalTransition();
}

void SpyroIdleState::NormalExit() {

}

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void SpyroIdleState::NormalEnter() {
    this->unk10->SetAnim(0U, 0.2f, (Spyro::AnimScriptNode) 0, 0U, 1.0f);
    this->unk28 = M2C_FIELD(&gb, f32 *, 0x30C) + 10.0f;
    this->unk3C = 0;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk14'
s32 SpyroIdleState::Transition() {
    M2C_UNK var_r28_760;
    s32 var_r29_726;
    u8 var_r30_727;
    u8 var_r30_765;

    if ((this->unk10->LavaTransition() != 0) || (this->unk10->SpikyTransition() != 0)) {
        return 1;
    }
    if ((this->unk14.GetState() == 2) && (this->unk54 > 0.0f) && (this->unk10->GetAnimScript((Spyro::AnimScriptNode) 0)->unk24 < this->unk54)) {
        return 0;
    }
    var_r29_726 = 1;
    var_r30_727 = 0;
    if ((this->unk10->TryChangeState(this->unk10->SlipTest(), 8U, NULL, 0U) != 0) || (this->unk10->LandToAirTransition(this->unk44 == 0, 0U, 0U), (((u8) M2C_ERROR(/* Read from unset register $r3 */) == 0) == 0)) || (this->unk10->LandToMoveTransition(1U, 1U) != 0)) {
        var_r30_727 = 1;
    }
    if (var_r30_727 == 0) {
        var_r28_760 = 0x16C;
        if (this->unk10->GetMeleeButtonState() == 2) {
            var_r28_760 = 0x17E;
        }
        var_r30_765 = 0;
        if (((u8) M2C_FIELD(&gb, u8 *, 5) != 0) && (this->unk10->GetMeleeButtonState() != 0)) {
            var_r30_765 = 1;
        }
        if (this->unk10->TryChangeState(var_r30_765, 0xBU, (SpyroStateMsg) var_r28_760, 0U) == 0) {
            var_r29_726 = 0;
        }
    }
    return var_r29_726;
}
#endif

void SpyroIdleState::Message(MKMessage *arg0) {
    s32 temp_r0_801;

    temp_r0_801 = arg0->unk0;
    switch (temp_r0_801) {                          /* irregular */
    case 181:
    case 190:
        this->unk28 = M2C_FIELD(&gb, f32 *, 0x30C) + 10.0f;
        return;
    case -4:
        this->unk10->unk6F8.Message(arg0);
        return;
    }
}

#if 0 // DRAFT: expression syntax error
void SpyroIdleState::Update() {
    Spyro *temp_r3_839;

    temp_r3_839 = this->unk10;
    if ((s32) M2C_FIELD(temp_r3_839->unk26C.unk8, s32 *, 0x16C) > 0) {
        temp_r3_839->SetDesiredVelocity(MKVector3::zero, 540000.0f);
        if (this->unk10->unk26C.unk8->unk8.HitID(2U) != 0) {
            this->unk44 = 1;
        } else {
            this->unk44 = 0;
        }
    }
    this->unk14.Update(this, 0);
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void SpyroIdleState::Exit() {
    s32 spC;
    s32 sp8;
    KDCamera *temp_r3_882;

    temp_r3_882 = this->unk10->GetCamera();
    spC = 0;
    sp8 = 0x454;
    M2C_FIELD(temp_r3_882->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp8);
    this->unk14.Exit(this);
}
#endif

#if 0 // DRAFT: expression syntax error
void SpyroIdleState::Enter(SpyroStateMessages &arg0) {
    s32 sp20;
    s32 sp1C;
    s32 sp18;
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    KDCamera *temp_r3_1072;
    KDCamera *temp_r3_937;
    MKProp *temp_r3_1009;
    Spyro *temp_r3_913;
    Spyro *temp_r3_918;
    Spyro *temp_r5_1008;
    f32 temp_f0_1033;
    f32 temp_f1_1032;
    f32 temp_f3_1035;
    s32 temp_r3_1011;
    s32 var_r0_1025;
    void *temp_r3_1090;
    void *temp_r3_986;
    void *var_r3_1020;

    temp_r3_913 = this->unk10;
    temp_r3_913->unk428 = temp_r3_913->unk428 | 0xE0000 | 0x3FA7;
    temp_r3_918 = this->unk10;
    temp_r3_918->unk428 = temp_r3_918->unk428 | 0x300000 | 0x8000;
    M2C_FIELD(this->unk10, f32 *, 0x38C) = 1900.0f;
    this->unk10->unk430.unk28.SetTailSweepEnabled(1U);
    this->unk10->unk430.unk28.SetHornDiveEnabled(1U);
    this->unk2C = 0;
    this->unk48 = -1;
    temp_r3_937 = this->unk10->GetCamera();
    sp14 = 0;
    sp10 = 0x453;
    M2C_FIELD(temp_r3_937->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp10);
    this->unk44 = arg0.IsMessageOnList(0x176);
    M2C_FIELD(this->unk10, s8 *, 0x3D2) = 0;
    this->unk10->SetDesiredVelocity(MKVector3::zero, 540000.0f);
    if (arg0.IsMessageOnList(0x186) != 0) {
        this->unk14.SetState(this, 0, 0U);
        this->unk10->SetAnim(0U, 0.0f, (Spyro::AnimScriptNode) 0, 4U, 1.0f);
    } else if (arg0.IsMessageOnList(0x187) != 0) {
        temp_r3_986 = checked_cast<SpyroOneOffIdleMessage *, MKMessage>(arg0.GetMessage(0x187));
        this->unk48 = M2C_FIELD(temp_r3_986, s32 *, 0);
        this->unk4C = M2C_FIELD(temp_r3_986, s32 *, 4);
        this->unk50 = M2C_FIELD(temp_r3_986, s32 *, 8);
        this->unk54 = M2C_FIELD(temp_r3_986, f32 *, 0xC);
        this->unk58 = M2C_FIELD(temp_r3_986, f32 *, 0x10);
        this->unk5C = M2C_FIELD(temp_r3_986, u8 *, 0x14);
        this->unk5D = M2C_FIELD(temp_r3_986, u8 *, 0x15);
        this->unk14.SetState(this, 2, 0U);
    } else {
        temp_r5_1008 = this->unk10;
        temp_r3_1009 = temp_r5_1008->unk26C.unk8;
        temp_r3_1011 = M2C_FIELD(temp_r3_1009, s32 *, 0x16C);
        if (((u32) (-temp_r3_1011 & ~temp_r3_1011) >> 0x1FU) != 0) {
            if (temp_r3_1011 != 0) {
                var_r3_1020 = &temp_r3_1009->unk8 + ((temp_r3_1011 - 1) * 0x58);
            } else {
                var_r3_1020 = NULL;
            }
            var_r0_1025 = M2C_FIELD(var_r3_1020, s32 *, 0x44);
        } else {
            var_r0_1025 = 0;
        }
        if ((var_r0_1025 & 8) && (temp_f1_1032 = temp_r5_1008->unk330, temp_f0_1033 = temp_r5_1008->unk33C, temp_f3_1035 = temp_r5_1008->unk338, ((((temp_f3_1035 * temp_f3_1035) + ((temp_f1_1032 * temp_f1_1032) + (temp_f0_1033 * temp_f0_1033))) > 10000.0f) != 0))) {
            this->unk14.SetState(this, 1, 0U);
        } else if ((u8) M2C_FIELD(temp_r5_1008, u8 *, 0x3D3) != 0) {
            this->unk14.SetState(this, 3, 0U);
        } else {
            this->unk14.SetState(this, 0, 0U);
        }
    }
    if ((u8) M2C_FIELD(&gb, u8 *, 0x35D) != 0) {
        temp_r3_1072 = this->unk10->GetCamera();
        spC = 0;
        sp8 = 0x42B;
        M2C_FIELD(temp_r3_1072->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp8);
    }
    sp1C = 0;
    sp18 = 0x17;
    sp20 = 0;
    temp_r3_1090 = this->unk10->unkB70;
    M2C_FIELD(M2C_FIELD(temp_r3_1090, void **, 0x44), M2C_UNK (**)(void *, s32 *), 0x2C)(temp_r3_1090, &sp18);
}
#endif

#if 0 // DRAFT: undefined identifier 'unk14'
void SpyroIdleState::Deinit() {
    this->unk30.Deinit();
    this->unk14.Deinit(this);
}
#endif

#if 0 // DRAFT: undefined identifier 'Init__32KDStateMachine'
void SpyroIdleState::Init(Spyro *arg0) {
    this->unk10 = arg0;
    Init__32KDStateMachine<14SpyroIdleState>FPQ232KDStateMachine<14SpyroIdleState>5StateP32KDStateMachine<14SpyroIdleState>(&this->unk14, (KDStateMachine<SpyroIdleState>::State *) &SpyroIdleState::states, NULL);
    this->unk28 = 0.0f;
    this->unk2C = 0;
    this->unk30.Init(M2C_FIELD(checked_cast<SpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk10->unk0), MKAnimScript **, 0x34));
    this->unk3C = 0;
    this->unk44 = 0;
    this->unk40 = 0;
    this->unk48 = -1;
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_728'
void SpyroIdleState_cpp::__sinit() {
    f64 temp_f0_1466;
    f64 temp_f1_1433;
    f64 temp_f1_1450;
    f64 temp_f1_1464;
    f64 temp_f3_1419;
    f64 temp_f3_1469;
    f64 temp_f4_1432;
    f64 temp_f4_1448;
    f64 temp_f8_1421;
    void *temp_r3_1424;

    temp_f3_1419 = __frsqrte(2014000.0);
    temp_f8_1421 = __frsqrte(380000.0);
    temp_r3_1424 = &lit_728 + 0xB4;
    temp_f4_1432 = 0.5 * temp_f3_1419 * -((2014000.0 * (temp_f3_1419 * temp_f3_1419)) - 3.0);
    temp_f1_1433 = 0.5 * temp_f8_1421 * -((380000.0 * (temp_f8_1421 * temp_f8_1421)) - 3.0);
    temp_f4_1448 = 0.5 * temp_f4_1432 * -((2014000.0 * (temp_f4_1432 * temp_f4_1432)) - 3.0);
    temp_f1_1450 = 0.5 * temp_f1_1433 * -((380000.0 * (temp_f1_1433 * temp_f1_1433)) - 3.0);
    temp_f1_1464 = 0.5 * temp_f1_1450;
    temp_f0_1466 = -((380000.0 * (temp_f1_1450 * temp_f1_1450)) - 3.0);
    temp_f3_1469 = 0.5 * temp_f4_1448 * -((2014000.0 * (temp_f4_1448 * temp_f4_1448)) - 3.0);
    M2C_FIELD(&lit_728, s32 *, 0xB4) = (s32) M2C_FIELD(&lit_728, s32 *, 0);
    M2C_FIELD(&lit_728, s32 *, 0xB8) = (s32) M2C_FIELD(&lit_728, s32 *, 4);
    M2C_FIELD(&lit_728, s32 *, 0xBC) = (s32) M2C_FIELD(&lit_728, s32 *, 8);
    M2C_FIELD(temp_r3_1424, s32 *, 0xC) = (s32) M2C_FIELD(&lit_728, s32 *, 0xC);
    M2C_FIELD(temp_r3_1424, s32 *, 0x10) = (s32) M2C_FIELD(&lit_728, s32 *, 0x10);
    M2C_FIELD(temp_r3_1424, s32 *, 0x14) = (s32) M2C_FIELD(&lit_728, s32 *, 0x14);
    M2C_FIELD(temp_r3_1424, s32 *, 0x18) = (s32) M2C_FIELD(&lit_728, s32 *, 0x18);
    M2C_FIELD(temp_r3_1424, s32 *, 0x1C) = (s32) M2C_FIELD(&lit_728, s32 *, 0x1C);
    M2C_FIELD(temp_r3_1424, s32 *, 0x20) = (s32) M2C_FIELD(&lit_728, s32 *, 0x20);
    M2C_FIELD(temp_r3_1424, s32 *, 0x24) = (s32) M2C_FIELD(&lit_728, s32 *, 0x24);
    M2C_FIELD(temp_r3_1424, s32 *, 0x28) = (s32) M2C_FIELD(&lit_728, s32 *, 0x28);
    M2C_FIELD(temp_r3_1424, s32 *, 0x2C) = (s32) M2C_FIELD(&lit_728, s32 *, 0x2C);
    M2C_FIELD(temp_r3_1424, s32 *, 0x30) = (s32) M2C_FIELD(&lit_728, s32 *, 0x30);
    M2C_FIELD(temp_r3_1424, s32 *, 0x34) = (s32) M2C_FIELD(&lit_728, s32 *, 0x34);
    M2C_FIELD(temp_r3_1424, s32 *, 0x38) = (s32) M2C_FIELD(&lit_728, s32 *, 0x38);
    M2C_FIELD(temp_r3_1424, s32 *, 0x3C) = (s32) M2C_FIELD(&lit_728, s32 *, 0x3C);
    M2C_FIELD(temp_r3_1424, s32 *, 0x40) = (s32) M2C_FIELD(&lit_728, s32 *, 0x40);
    M2C_FIELD(temp_r3_1424, s32 *, 0x44) = (s32) M2C_FIELD(&lit_728, s32 *, 0x44);
    SPYRO_BOUNCE_Y_SPEED = (f32) (2014000.0 * temp_f3_1469);
    SPYRO_MIN_JUMP_Y_VELOCITY = (f32) (380000.0 * (temp_f1_1464 * temp_f0_1466));
    M2C_FIELD(temp_r3_1424, s32 *, 0x48) = (s32) M2C_FIELD(&lit_728, s32 *, 0x48);
    M2C_FIELD(temp_r3_1424, s32 *, 0x4C) = (s32) M2C_FIELD(&lit_728, s32 *, 0x4C);
    M2C_FIELD(temp_r3_1424, s32 *, 0x50) = (s32) M2C_FIELD(&lit_728, s32 *, 0x50);
    M2C_FIELD(temp_r3_1424, s32 *, 0x54) = (s32) M2C_FIELD(&lit_728, s32 *, 0x54);
    M2C_FIELD(temp_r3_1424, s32 *, 0x58) = (s32) M2C_FIELD(&lit_728, s32 *, 0x58);
    M2C_FIELD(temp_r3_1424, s32 *, 0x5C) = (s32) M2C_FIELD(&lit_728, s32 *, 0x5C);
    M2C_FIELD(temp_r3_1424, s32 *, 0x60) = (s32) M2C_FIELD(&lit_728, s32 *, 0x60);
    M2C_FIELD(temp_r3_1424, s32 *, 0x64) = (s32) M2C_FIELD(&lit_728, s32 *, 0x64);
    M2C_FIELD(temp_r3_1424, s32 *, 0x68) = (s32) M2C_FIELD(&lit_728, s32 *, 0x68);
    M2C_FIELD(temp_r3_1424, s32 *, 0x6C) = (s32) M2C_FIELD(&lit_728, s32 *, 0x6C);
    M2C_FIELD(temp_r3_1424, s32 *, 0x70) = (s32) M2C_FIELD(&lit_728, s32 *, 0x70);
    M2C_FIELD(temp_r3_1424, s32 *, 0x74) = (s32) M2C_FIELD(&lit_728, s32 *, 0x74);
    M2C_FIELD(temp_r3_1424, s32 *, 0x78) = (s32) M2C_FIELD(&lit_728, s32 *, 0x78);
    M2C_FIELD(temp_r3_1424, s32 *, 0x7C) = (s32) M2C_FIELD(&lit_728, s32 *, 0x7C);
    M2C_FIELD(temp_r3_1424, s32 *, 0x80) = (s32) M2C_FIELD(&lit_728, s32 *, 0x80);
    M2C_FIELD(temp_r3_1424, s32 *, 0x84) = (s32) M2C_FIELD(&lit_728, s32 *, 0x84);
    M2C_FIELD(temp_r3_1424, s32 *, 0x88) = (s32) M2C_FIELD(&lit_728, s32 *, 0x88);
    M2C_FIELD(temp_r3_1424, s32 *, 0x8C) = (s32) M2C_FIELD(&lit_728, s32 *, 0x8C);
    M2C_FIELD(temp_r3_1424, s32 *, 0x90) = (s32) M2C_FIELD(&lit_728, s32 *, 0x90);
    M2C_FIELD(temp_r3_1424, s32 *, 0x94) = (s32) M2C_FIELD(&lit_728, s32 *, 0x94);
    M2C_FIELD(temp_r3_1424, s32 *, 0x98) = (s32) M2C_FIELD(&lit_728, s32 *, 0x98);
    M2C_FIELD(temp_r3_1424, s32 *, 0x9C) = (s32) M2C_FIELD(&lit_728, s32 *, 0x9C);
    M2C_FIELD(temp_r3_1424, s32 *, 0xA0) = (s32) M2C_FIELD(&lit_728, s32 *, 0xA0);
    M2C_FIELD(temp_r3_1424, s32 *, 0xA4) = (s32) M2C_FIELD(&lit_728, s32 *, 0xA4);
    M2C_FIELD(temp_r3_1424, s32 *, 0xA8) = (s32) M2C_FIELD(&lit_728, s32 *, 0xA8);
    M2C_FIELD(temp_r3_1424, s32 *, 0xAC) = (s32) M2C_FIELD(&lit_728, s32 *, 0xAC);
    M2C_FIELD(temp_r3_1424, s32 *, 0xB0) = (s32) M2C_FIELD(&lit_728, s32 *, 0xB0);
}
#endif
