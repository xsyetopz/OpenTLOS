#include "spyro/source/SpyroChargeState.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "spyro/source/InputModifier.h"
#include "spyro/source/KDCamera.h"
#include "spyro/source/KDInput.h"
#include "spyro/source/Spyro.h"
#include "spyro/source/SpyroCombatState.h"
#include "spyro/source/SpyroTools.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKInput.h"
#include <m2c_macros.h>

extern f32 SPYRO_BOUNCE_Y_SPEED;
extern f32 SPYRO_MIN_JUMP_Y_VELOCITY;
extern f32 gUpdateTimeDelta;
static M2C_UNK lit_764;                                /* unable to generate initializer: unknown type */
SpyroChargeState states__16SpyroChargeState;        /* unable to generate initializer: confusing struct layout */

void SpyroChargeState::ChargeTransition() {
    InputModifier *temp_r3_32;
    u8 var_r4_34;

    temp_r3_32 = this->unk10->GetInput();
    var_r4_34 = 0;
    if (((u8) temp_r3_32->unk5 != 0) || ((u8) temp_r3_32->unk4 != 0)) {
        var_r4_34 = 1;
    }
    if (var_r4_34 != 0) {

    } else {
        MKInput_GetState(0xB, (MKInputDevices) temp_r3_32->unk0, NULL, NULL);
    }
    this->unk10->TryChangeState((u8) ((((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1DU) & 1) ^ 1) == 0, 4U, NULL, 0U);
}

void SpyroChargeState::ChargeUpdate() {
    ChargeTransition();
}

void SpyroChargeState::ChargeExit() {

}

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void SpyroChargeState::ChargeEnter() {
    this->unk10->SetAnim(9U, 0.15f, (Spyro::AnimScriptNode) 0, 0U, 1.0f);
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
s32 SpyroChargeState::PostHornDiveTransition() {
    if ((this->unk10->GetAnimScript((Spyro::AnimScriptNode) 0)->unk2C & 1) && ((s32) this->unk14.unk0 != 2)) {
        this->unk14.SetState(this, 2, 0U);
        return 1;
    }
    return 0;
}
#endif

void SpyroChargeState::PostHornDiveUpdate() {
    PostHornDiveTransition();
}

void SpyroChargeState::PostHornDiveExit() {

}

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void SpyroChargeState::PostHornDiveEnter() {
    this->unk10->SetAnim(0x2FU, 0.1f, (Spyro::AnimScriptNode) 0, 0U, 1.0f);
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
u8 SpyroChargeState::InitialChargeTransition() {
    InputModifier *temp_r3_199;
    InputModifier *temp_r3_240;
    f32 var_f1_212;
    u8 var_r3_232;
    u8 var_r4_201;
    u8 var_r4_242;

    if ((s32) this->unk10->GetAnimScript((Spyro::AnimScriptNode) 0)->unk44 > 0) {
        temp_r3_199 = this->unk10->GetInput();
        var_r4_201 = 0;
        if (((u8) temp_r3_199->unk5 != 0) || ((u8) temp_r3_199->unk4 != 0)) {
            var_r4_201 = 1;
        }
        if (var_r4_201 != 0) {
            var_f1_212 = 0.0f;
        } else {
            var_f1_212 = MKInput_GetState(0xB, (MKInputDevices) temp_r3_199->unk0, NULL, NULL);
        }
        if ((var_f1_212 != 0.0f) && ((s32) this->unk14.unk0 != 2)) {
            this->unk14.SetState(this, 2, 0U);
            var_r3_232 = 1;
        } else {
            var_r3_232 = 0;
        }
        if (var_r3_232 == 0) {
            temp_r3_240 = this->unk10->GetInput();
            var_r4_242 = 0;
            if (((u8) temp_r3_240->unk5 != 0) || ((u8) temp_r3_240->unk4 != 0)) {
                var_r4_242 = 1;
            }
            if (var_r4_242 != 0) {

            } else {
                MKInput_GetState(0xB, (MKInputDevices) temp_r3_240->unk0, NULL, NULL);
            }
            return this->unk10->TryChangeState((u8) ((((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1DU) & 1) ^ 1) == 0, 4U, NULL, 0U);
        }
        /* Duplicate return node #20. Try simplifying control flow for better match */
        return var_r3_232;
    }
    var_r3_232 = 0;
    return var_r3_232;
}
#endif

void SpyroChargeState::InitialChargeUpdate() {
    InitialChargeTransition();
}

void SpyroChargeState::InitialChargeExit() {

}

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void SpyroChargeState::InitialChargeEnter() {
    this->unk10->SetAnim(9U, 0.15f, (Spyro::AnimScriptNode) 0, 0U, 1.0f);
}
#endif

void SpyroChargeState::ProcessAnimEvent(unsigned int arg0) {

}

void SpyroChargeState::Message(MKMessage *arg0) {

}

#if 0 // DRAFT: undefined identifier 'unkspA4'
s32 SpyroChargeState::Transition() {
    MKCollisionResult spC8;
    s8 spC5;
    s8 spC4;
    f32 spC0;
    f32 spBC;
    s32 spB8;
    s32 spB4;
    s32 spB0;
    f64 spA8;
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;                                       /* compiler-managed */
    f64 sp80;                                       /* compiler-managed */
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp38;
    f64 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 sp8;
    MKProp *temp_r3_345;
    Spyro *temp_r3_509;
    Spyro *temp_r5_344;
    f32 temp_f1_538;
    f32 temp_f4_523;
    f32 temp_f5_512;
    f32 temp_f6_516;
    f32 var_f4_431;
    f32 var_f5_441;
    f64 temp_f0_399;
    f64 temp_f0_410;
    f64 temp_f1_446;
    f64 temp_f1_452;
    f64 temp_f1_456;
    s32 temp_r25_576;
    s32 temp_r3_347;
    s32 temp_r3_475;
    s32 var_r0_485;
    u32 var_r0_364;
    u32 var_r26_598;
    u8 var_r27_578;
    u8 var_r28_577;
    u8 var_r29_574;
    u8 var_r30_579;
    u8 var_r30_604;
    void *temp_r3_361;
    void *temp_r3_373;
    void *temp_r3_384;
    void *temp_r4_511;
    void *var_r3_353;

    temp_r5_344 = this->unk10;
    temp_r3_345 = temp_r5_344->unk26C.unk8;
    temp_r3_347 = M2C_FIELD(temp_r3_345, s32 *, 0x2D4);
    if (temp_r3_347 > 0) {
        if (temp_r3_347 != 0) {
            var_r3_353 = temp_r3_345 + 0x170 + ((temp_r3_347 - 1) * 0x58);
        } else {
            var_r3_353 = NULL;
        }
        if (((u8) M2C_FIELD(var_r3_353, u8 *, 0x50) != 0) && (temp_r3_361 = M2C_FIELD(var_r3_353, void **, 0x48), ((temp_r3_361 == NULL) == 0)) && (var_r0_364 = M2C_FIELD(temp_r3_361, u32 *, 8), ((var_r0_364 == 0U) == 0))) {

        } else {
            var_r0_364 = 0U;
        }
        if (var_r0_364 == 0U) {
            temp_r3_373 = temp_r5_344->unk8;
            spA0 = M2C_FIELD(temp_r3_373, f64 *, 0x30);
            spA8 = M2C_FIELD(temp_r3_373, f64 *, 0x38);
            unkspA4 += 100.0f;
            temp_r3_384 = this->unk10->unk8;
            sp40 = -M2C_FIELD(temp_r3_384, f32 *, 0x20);
            sp44 = -M2C_FIELD(temp_r3_384, f32 *, 0x24);
            sp48 = -M2C_FIELD(temp_r3_384, f32 *, 0x28);
            sp60 = (f64) sp40;
            sp68 = (f64) sp48;
            temp_f0_399 = sp60 * 5.634608575e-315;
            sp30 = temp_f0_399;
            sp70 = temp_f0_399;
            sp38 = (f32) sp68 * 500.0f;
            sp78 = (f64) sp38;
            temp_f0_410 = sp70 + spA0;
            sp20 = temp_f0_410;
            sp90 = temp_f0_410;
            sp28 = (f32) sp78 + (f32) spA8;
            sp98 = (f64) sp28;
            if (MKCollision_RayCollide(*((MKVector3 *) &spA0), *((MKVector3 *) &sp90), &spC8, (MKCollisionMode) 7, 0x04000000) != 0) {
                sp80 = (f64) spC8.unk10;
                var_f4_431 = 0.0f;
                sp88 = (f64) spC8.unk18;
                unksp84 = 0.0f;
                var_f5_441 = ((f32) sp88 * (f32) sp88) + (((f32) sp80 * (f32) sp80) + (0.0f * 0.0f));
                if (var_f5_441 > 0.000001f) {
                    if (var_f5_441 > 0.0f) {
                        temp_f1_446 = __frsqrte(var_f5_441);
                        temp_f1_452 = 0.5 * temp_f1_446 * -(((f64) var_f5_441 * (temp_f1_446 * temp_f1_446)) - 3.0);
                        temp_f1_456 = 0.5 * temp_f1_452 * -(((f64) var_f5_441 * (temp_f1_452 * temp_f1_452)) - 3.0);
                        var_f5_441 = (f32) ((f64) var_f5_441 * (0.5 * temp_f1_456 * -(((f64) var_f5_441 * (temp_f1_456 * temp_f1_456)) - 3.0)));
                    } else if (var_f5_441 < M2C_BITWISE(f32, 0.0)) {
                        var_f5_441 = __float_nan;
                    } else {
                        sp8 = var_f5_441;
                        temp_r3_475 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                        switch (temp_r3_475) {      /* irregular */
                        case 0x7F800000:
                            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                var_r0_485 = 1;
                            } else {
                                var_r0_485 = 2;
                            }
                            break;
                        case 0x0:
                            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                var_r0_485 = 5;
                            } else {
                                var_r0_485 = 3;
                            }
                            break;
                        default:
                            var_r0_485 = 4;
                            break;
                        }
                        if (var_r0_485 == 1) {
                            var_f5_441 = __float_nan;
                        }
                    }
                    var_f4_431 = 1.0f / var_f5_441;
                }
                temp_r3_509 = this->unk10;
                temp_r4_511 = temp_r3_509->unk8;
                temp_f5_512 = unksp84 * var_f4_431;
                temp_f6_516 = (f32) sp80 * var_f4_431;
                sp10 = -M2C_FIELD(temp_r4_511, f32 *, 0x20);
                temp_f4_523 = (f32) sp88 * var_f4_431;
                sp14 = -M2C_FIELD(temp_r4_511, f32 *, 0x24);
                sp18 = -M2C_FIELD(temp_r4_511, f32 *, 0x28);
                sp50 = (f64) sp10;
                sp58 = (f64) sp18;
                sp80 = temp_f6_516;
                unksp84 = temp_f5_512;
                temp_f1_538 = (temp_f4_523 * (f32) sp58) + ((temp_f6_516 * (f32) sp50) + (temp_f5_512 * unksp54));
                sp88 = temp_f4_523;
                if ((temp_f1_538 > 0.8f) || (temp_f1_538 < -0.8f)) {
                    temp_r3_509->EmitWallHeadbuttEffects(*((MKVector3 *) &spC8));
                    spB4 = 0;
                    spB8 = 4;
                    spB0 = 0x187;
                    spBC = 1.0f;
                    spC0 = 0.2f;
                    spC4 = 1;
                    spC5 = 1;
                    this->unk10->unk3CD = 1;
                    return this->unk10->TryChangeState(1U, 4U, (MKMessage *) &spB0, 0U);
                }
                goto block_33;
            }
        }
        goto block_33;
    }
block_33:
    var_r29_574 = 1;
    temp_r25_576 = this->unk10->ChargeCombatArcTest();
    var_r28_577 = 1;
    var_r27_578 = 1;
    var_r30_579 = 0;
    if ((this->unk10->LavaTransition() != 0) || (this->unk10->SpikyTransition() != 0)) {
        var_r30_579 = 1;
    }
    if (var_r30_579 == 0) {
        if (((KDInput *) (this->unk10->GetInput()))->GetLeftMag() != 0.0f) {
            var_r26_598 = 0;
        } else {
            var_r26_598 = 4;
        }
        var_r30_604 = 0;
        if ((this->unk28 >= 5.0f) || (this->unk10->IsAgainstMatID(2), (((u32) M2C_ERROR(/* Read from unset register $r3 */) == 0U) == 0))) {
            var_r30_604 = 1;
        }
        if (this->unk10->TryChangeState(var_r30_604, var_r26_598, NULL, 0U) == 0) {
            var_r27_578 = 0;
        }
    }
    if ((var_r27_578 == 0) && (this->unk10->TryChangeState((u8) temp_r25_576, 0xBU, (SpyroStateMsg) 0x17F, 0U) == 0)) {
        var_r28_577 = 0;
    }
    if (var_r28_577 == 0) {
        this->unk10->LandToAirTransition(1U, 0U, 1U);
        if ((u8) M2C_ERROR(/* Read from unset register $r3 */) == 0) {
            var_r29_574 = 0;
        }
    }
    return var_r29_574;
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void SpyroChargeState::Update() {
    f64 sp58;
    f64 sp50;
    M2C_UNK sp40;
    f64 sp38;
    f64 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f64 sp10;
    s32 spC;
    s32 sp8;
    KDCamera *temp_r3_687;
    MKProp *temp_r3_706;
    Spyro *temp_r3_747;
    Spyro *temp_r5_700;
    f32 temp_f2_676;
    f32 temp_f3_750;
    f32 var_f30_702;
    f64 temp_f0_766;
    s32 temp_r3_708;
    s32 var_r0_722;
    u8 var_r4_701;
    void *temp_r4_749;
    void *var_r3_717;

    this->unk28 += gUpdateTimeDelta;
    temp_f2_676 = this->unk2C;
    if (temp_f2_676 > 0.0f) {
        this->unk2C = temp_f2_676 - gUpdateTimeDelta;
        if (this->unk2C <= 0.0f) {
            temp_r3_687 = this->unk10->GetCamera();
            spC = 0;
            sp8 = 0x445;
            M2C_FIELD(temp_r3_687->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp8);
            this->unk2C = -1.0f;
        }
    }
    temp_r5_700 = this->unk10;
    var_r4_701 = 0;
    var_f30_702 = 1.0f;
    if (((u32) temp_r5_700->unk428 >> 5U) & 1) {
        temp_r3_706 = temp_r5_700->unk26C.unk8;
        temp_r3_708 = M2C_FIELD(temp_r3_706, s32 *, 0x16C);
        if (((u32) (-temp_r3_708 & ~temp_r3_708) >> 0x1FU) != 0) {
            if (temp_r3_708 != 0) {
                var_r3_717 = &temp_r3_706->unk8 + ((temp_r3_708 - 1) * 0x58);
            } else {
                var_r3_717 = NULL;
            }
            var_r0_722 = M2C_FIELD(var_r3_717, s32 *, 0x44);
        } else {
            var_r0_722 = 0;
        }
        if (var_r0_722 & 0x40) {
            var_r4_701 = 1;
        }
    }
    if (var_r4_701 != 0) {
        var_f30_702 = 1.0f * M2C_FIELD(checked_cast<SpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) temp_r5_700->unk0), f32 *, 0xD8);
    }
    ((Spyro *) &sp40)->CalcYawTurnDir(3.5f);
    ((SpyroRotation *) &this->unk10->unk3A0)->YawTowards(*((MKVector3 *) &sp40), 3.5f);
    temp_r3_747 = this->unk10;
    temp_r4_749 = temp_r3_747->unk8;
    temp_f3_750 = 1400.0f * var_f30_702;
    sp20 = -M2C_FIELD(temp_r4_749, f32 *, 0x20);
    sp24 = -M2C_FIELD(temp_r4_749, f32 *, 0x24);
    sp28 = -M2C_FIELD(temp_r4_749, f32 *, 0x28);
    sp30 = (f64) sp20;
    sp38 = (f64) sp28;
    temp_f0_766 = sp30 * (f64) temp_f3_750;
    sp10 = temp_f0_766;
    sp50 = temp_f0_766;
    sp18 = (f32) sp38 * temp_f3_750;
    sp58 = (f64) sp18;
    temp_r3_747->SetDesiredVelocityHoriz(*((MKVector3 *) &sp50), 100000.0f);
    this->unk14.Update(this, 0);
    Transition();
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void SpyroChargeState::Exit() {
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    KDCamera *temp_r3_825;
    KDCamera *temp_r3_840;
    f32 temp_f0_811;
    f32 var_f1_810;

    var_f1_810 = 3.0f;
    temp_f0_811 = 3.0f * (this->unk28 / 5.0f);
    if (temp_f0_811 > 3.0f) {

    } else {
        var_f1_810 = temp_f0_811;
    }
    this->unk10->unk3C4 = var_f1_810;
    ((CombatStateData *) &this->unk10->unk430.unk28)->SetChargeTime(this->unk28);
    temp_r3_825 = this->unk10->GetCamera();
    sp14 = 0;
    sp10 = 0x43A;
    M2C_FIELD(temp_r3_825->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp10);
    if (this->unk2C == -1.0f) {
        temp_r3_840 = this->unk10->GetCamera();
        spC = 0;
        sp8 = 0x446;
        M2C_FIELD(temp_r3_840->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp8);
    }
    this->unk14.Exit(this);
}
#endif

#if 0 // DRAFT: undefined identifier 'unk14'
void SpyroChargeState::Enter(SpyroStateMessages &arg0) {
    s32 sp20;
    s32 sp1C;
    s32 sp18;
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    KDCamera *temp_r3_888;
    KDCamera *temp_r3_899;
    Spyro *temp_r3_912;
    Spyro *temp_r3_916;
    void *temp_r3_932;

    if (arg0.IsMessageOnList(0x17C) != 0) {
        this->unk14.SetState(this, 1, 1U);
    } else {
        this->unk14.SetState(this, 0, 1U);
    }
    temp_r3_888 = this->unk10->GetCamera();
    sp14 = 0;
    sp10 = 0x439;
    M2C_FIELD(temp_r3_888->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp10);
    temp_r3_899 = this->unk10->GetCamera();
    spC = 0;
    sp8 = 0x42B;
    M2C_FIELD(temp_r3_899->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp8);
    this->unk2C = 0.4f;
    temp_r3_912 = this->unk10;
    temp_r3_912->unk428 |= 0x8000;
    temp_r3_916 = this->unk10;
    temp_r3_916->unk428 &= 0xFFFFFFFE;
    this->unk28 = 0.0f;
    ((CombatStateData *) &this->unk10->unk430.unk28)->SetChargeTime(0.0f);
    sp1C = 0;
    sp18 = 0x17;
    sp20 = 4;
    temp_r3_932 = this->unk10->unkB70;
    M2C_FIELD(M2C_FIELD(temp_r3_932, void **, 0x44), M2C_UNK (**)(void *, s32 *), 0x2C)(temp_r3_932, &sp18);
    this->unk10->StartCombatArc(1);
}
#endif

#if 0 // DRAFT: undefined identifier 'unk14'
void SpyroChargeState::Deinit() {
    this->unk14.Deinit();
}
#endif

#if 0 // DRAFT: undefined identifier 'Init__34KDStateMachine'
void SpyroChargeState::Init(Spyro *arg0) {
    this->unk10 = arg0;
    Init__34KDStateMachine<16SpyroChargeState>FPQ234KDStateMachine<16SpyroChargeState>5StateP34KDStateMachine<16SpyroChargeState>(&this->unk14, (KDStateMachine<SpyroChargeState>::State *) &SpyroChargeState::states, NULL);
    this->unk28 = 0.0f;
    this->unk2C = 0.0f;
}
#endif

void SpyroChargeState_cpp::__sinit() {
    f64 temp_f0_1248;
    f64 temp_f1_1208;
    f64 temp_f1_1228;
    f64 temp_f1_1244;
    f64 temp_f3_1194;
    f64 temp_f3_1241;
    f64 temp_f4_1207;
    f64 temp_f4_1225;
    f64 temp_f4_1238;
    f64 temp_f8_1196;
    void *temp_r17_1199;

    temp_f3_1194 = __frsqrte(2014000.0);
    temp_f8_1196 = __frsqrte(380000.0);
    temp_r17_1199 = &lit_764 + 0x6C;
    temp_f4_1207 = 0.5 * temp_f3_1194 * -((2014000.0 * (temp_f3_1194 * temp_f3_1194)) - 3.0);
    temp_f1_1208 = 0.5 * temp_f8_1196 * -((380000.0 * (temp_f8_1196 * temp_f8_1196)) - 3.0);
    temp_f4_1225 = 0.5 * temp_f4_1207 * -((2014000.0 * (temp_f4_1207 * temp_f4_1207)) - 3.0);
    temp_f1_1228 = 0.5 * temp_f1_1208 * -((380000.0 * (temp_f1_1208 * temp_f1_1208)) - 3.0);
    temp_f4_1238 = 0.5 * temp_f4_1225;
    temp_f3_1241 = -((2014000.0 * (temp_f4_1225 * temp_f4_1225)) - 3.0);
    temp_f1_1244 = 0.5 * temp_f1_1228;
    temp_f0_1248 = -((380000.0 * (temp_f1_1228 * temp_f1_1228)) - 3.0);
    M2C_FIELD(&lit_764, s32 *, 0x6C) = (s32) M2C_FIELD(&lit_764, s32 *, 0);
    M2C_FIELD(&lit_764, s32 *, 0x70) = (s32) M2C_FIELD(&lit_764, s32 *, 4);
    M2C_FIELD(&lit_764, s32 *, 0x74) = (s32) M2C_FIELD(&lit_764, s32 *, 8);
    M2C_FIELD(temp_r17_1199, s32 *, 0xC) = (s32) M2C_FIELD(&lit_764, s32 *, 0xC);
    M2C_FIELD(temp_r17_1199, s32 *, 0x10) = (s32) M2C_FIELD(&lit_764, s32 *, 0x10);
    M2C_FIELD(temp_r17_1199, s32 *, 0x14) = (s32) M2C_FIELD(&lit_764, s32 *, 0x14);
    M2C_FIELD(temp_r17_1199, s32 *, 0x18) = (s32) M2C_FIELD(&lit_764, s32 *, 0x18);
    M2C_FIELD(temp_r17_1199, s32 *, 0x1C) = (s32) M2C_FIELD(&lit_764, s32 *, 0x1C);
    M2C_FIELD(temp_r17_1199, s32 *, 0x20) = (s32) M2C_FIELD(&lit_764, s32 *, 0x20);
    M2C_FIELD(temp_r17_1199, s32 *, 0x24) = (s32) M2C_FIELD(&lit_764, s32 *, 0x24);
    M2C_FIELD(temp_r17_1199, s32 *, 0x28) = (s32) M2C_FIELD(&lit_764, s32 *, 0x28);
    M2C_FIELD(temp_r17_1199, s32 *, 0x2C) = (s32) M2C_FIELD(&lit_764, s32 *, 0x2C);
    M2C_FIELD(temp_r17_1199, s32 *, 0x30) = (s32) M2C_FIELD(&lit_764, s32 *, 0x30);
    M2C_FIELD(temp_r17_1199, s32 *, 0x34) = (s32) M2C_FIELD(&lit_764, s32 *, 0x34);
    M2C_FIELD(temp_r17_1199, s32 *, 0x38) = (s32) M2C_FIELD(&lit_764, s32 *, 0x38);
    M2C_FIELD(temp_r17_1199, s32 *, 0x3C) = (s32) M2C_FIELD(&lit_764, s32 *, 0x3C);
    M2C_FIELD(temp_r17_1199, s32 *, 0x40) = (s32) M2C_FIELD(&lit_764, s32 *, 0x40);
    M2C_FIELD(temp_r17_1199, s32 *, 0x44) = (s32) M2C_FIELD(&lit_764, s32 *, 0x44);
    M2C_FIELD(temp_r17_1199, s32 *, 0x48) = (s32) M2C_FIELD(&lit_764, s32 *, 0x48);
    M2C_FIELD(temp_r17_1199, s32 *, 0x4C) = (s32) M2C_FIELD(&lit_764, s32 *, 0x4C);
    M2C_FIELD(temp_r17_1199, s32 *, 0x50) = (s32) M2C_FIELD(&lit_764, s32 *, 0x50);
    M2C_FIELD(temp_r17_1199, s32 *, 0x54) = (s32) M2C_FIELD(&lit_764, s32 *, 0x54);
    M2C_FIELD(temp_r17_1199, s32 *, 0x58) = (s32) M2C_FIELD(&lit_764, s32 *, 0x58);
    M2C_FIELD(temp_r17_1199, s32 *, 0x5C) = (s32) M2C_FIELD(&lit_764, s32 *, 0x5C);
    M2C_FIELD(temp_r17_1199, s32 *, 0x60) = (s32) M2C_FIELD(&lit_764, s32 *, 0x60);
    M2C_FIELD(temp_r17_1199, s32 *, 0x64) = (s32) M2C_FIELD(&lit_764, s32 *, 0x64);
    M2C_FIELD(temp_r17_1199, s32 *, 0x68) = (s32) M2C_FIELD(&lit_764, s32 *, 0x68);
    SPYRO_BOUNCE_Y_SPEED = (f32) (2014000.0 * (temp_f4_1238 * temp_f3_1241));
    SPYRO_MIN_JUMP_Y_VELOCITY = (f32) (380000.0 * (temp_f1_1244 * temp_f0_1248));
}
