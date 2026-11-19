#include "spyro/source/SpyroTailStrikeState.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "spyro/source/GameData.h"
#include "spyro/source/KDCamera.h"
#include "spyro/source/KDInput.h"
#include "spyro/source/Spyro.h"
#include "spyro/source/SpyroCombatState.h"
#include "spyro/source/SpyroTools.h"
#include "unplaced_enums.h"
#include "spyro/source/KDSound.h"
#include <m2c_macros.h>

extern s32 GS_SpyroStompHit;
extern s32 GS_SpyroStompLand;
extern f32 SPYRO_BOUNCE_Y_SPEED;
extern f32 SPYRO_MIN_JUMP_Y_VELOCITY;
extern f32 gUpdateTimeDelta;
extern M2C_UNK iMeleeAttackTypeMap;
#if 0 // DRAFT: illegal implicit conversion from 'unsigned long **' to
static M2C_UNK lit_762;                                /* unable to generate initializer: unknown type */
SpyroTailStrikeState states__20SpyroTailStrikeState; /* unable to generate initializer: confusing struct layout */

void SpyroTailStrikeState::HitProp(MKProp *arg0, MKCollisionInfo *arg1) {
    u8 sp56;
    s8 sp55;
    s8 sp54;
    MKCollisionInfo *sp50;
    M2C_UNK *sp4C;
    s32 sp48;
    s32 sp44;
    s32 sp40;
    f32 sp3C;
    f32 sp38;
    f64 sp30;
    f64 sp28;
    Spyro *sp20;
    s32 sp1C;
    s32 sp18;
    f64 sp10;
    f64 sp8;
    Spyro *temp_r10_46;
    f32 temp_f1_45;
    f64 temp_f2_56;
    f64 temp_f3_54;
    s32 temp_r28_44;
    void *temp_r3_50;

    if (arg0 != NULL) {
        sp1C = 0;
        temp_r28_44 = *(&iMeleeAttackTypeMap + (M2C_FIELD(GameData::gameData, s32 *, 0x158) * 4)) | 0x400;
        temp_f1_45 = ((GameStats *) &GameData::gameData[0x70])->TailStrikeDamage();
        temp_r10_46 = this->unk10;
        temp_r3_50 = temp_r10_46->unk8;
        temp_f3_54 = M2C_FIELD(temp_r3_50, f64 *, 0x30);
        temp_f2_56 = M2C_FIELD(temp_r3_50, f64 *, 0x38);
        sp8 = temp_f3_54;
        sp44 = -1;
        sp4C = NULL;
        sp50 = NULL;
        sp18 = 4;
        sp20 = temp_r10_46;
        sp28 = temp_f3_54;
        sp30 = temp_f2_56;
        sp38 = temp_f1_45;
        sp54 = 0;
        sp40 = 1;
        sp48 = temp_r28_44;
        sp55 = 0;
        sp56 = 0;
        sp3C = 1.0f;
        sp44 = GS_SpyroStompHit;
        sp50 = arg1;
        sp4C = &temp_r10_46->unk6F0;
        sp10 = temp_f2_56;
        arg0->Message(&sp18, GS_SpyroStompHit, -1, 1, 0, 4, temp_r10_46, temp_f2_56, temp_f3_54);
        if (sp56 != 0) {
            M2C_FIELD(this, s8 *, 0x50) = 0;
        }
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
u8 SpyroTailStrikeState::LandTransition() {
    u8 var_r29_105;
    u8 var_r29_123;
    u8 var_r29_148;
    u8 var_r30_106;
    u8 var_r31_104;

    var_r31_104 = 1;
    var_r29_105 = 0;
    var_r30_106 = 1;
    if ((this->unk10->GetAnimScript((Spyro::AnimScriptNode) 0)->unk2C & 1) && (this->unk10->LandToMoveTransition(1U, 1U) != 0)) {
        var_r29_105 = 1;
    }
    if (var_r29_105 == 0) {
        var_r29_123 = 0;
        if ((this->unk10->GetAnimScript((Spyro::AnimScriptNode) 0)->unk2C & 1) && (this->unk10->OnFloor() == 0)) {
            var_r29_123 = 1;
        }
        if (this->unk10->TryChangeState(var_r29_123, 6U, NULL, 0U) == 0) {
            var_r30_106 = 0;
        }
    }
    if (var_r30_106 == 0) {
        var_r29_148 = 0;
        if ((this->unk10->GetAnimScript((Spyro::AnimScriptNode) 0)->unk2C & 1) && (this->unk10->TryChangeState(1U, 4U, NULL, 0U) != 0)) {
            var_r29_148 = 1;
        }
        if (var_r29_148 == 0) {
            var_r31_104 = 0;
        }
    }
    return var_r31_104;
}
#endif

#if 0 // DRAFT: undefined identifier 'MKVector'
void SpyroTailStrikeState::LandUpdate() {
    MKCollisionResult sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;                                       /* compiler-managed */
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f64 sp8;
    MKCollisionInfo *temp_r5_274;
    MKProp *var_r4_279;
    f32 temp_f29_221;
    f64 temp_f3_202;
    f64 temp_f4_201;
    s32 temp_r28_266;
    s32 var_r25_267;
    s32 var_r29_268;
    s32 var_r31_218;
    void *temp_r3_197;
    void *temp_r3_272;

    if (M2C_BITWISE(s32, this->unk48) <= 3) {
        temp_r3_197 = this->unk10->unk8;
        temp_f4_201 = M2C_FIELD(temp_r3_197, f64 *, 0x30);
        temp_f3_202 = M2C_FIELD(temp_r3_197, f64 *, 0x38);
        sp18 = 0.5f * -300.0f;
        sp1C = 0.0f;
        sp20 = 150.0f;
        sp58 = temp_f4_201;
        sp48 = (f64) sp18;
        sp68 = temp_f4_201;
        sp70 = temp_f3_202;
        sp60 = temp_f3_202;
        sp50 = (f64) sp20;
        sp58 += sp48;
        var_r31_218 = 0;
        temp_f29_221 = (f32) sp60 + (f32) sp50;
        sp60 = temp_f29_221;
        do {
            MKVector((f32) (var_r31_218 & 1) * 300.0f, 0.0f, (f32) -(var_r31_218 / 2) * 300.0f);
            sp8 = sp58 + sp28;
            sp38 = sp8;
            sp10 = temp_f29_221 + sp30;
            sp68 = sp8;
            sp40 = (f64) sp10;
            sp70 = (f64) sp10;
            temp_r28_266 = MKCollision_SphereCollide(*((MKVector3 *) &sp68), 300.0f, &sp78, 0x14, (MKCollisionMode) 2, 0x04200200);
            var_r25_267 = 0;
            var_r29_268 = 0;
loop_9:
            if (var_r25_267 < temp_r28_266) {
                temp_r3_272 = &sp78 + var_r29_268;
                temp_r5_274 = M2C_FIELD(temp_r3_272, MKCollisionInfo **, 0x48);
                if (((u8) M2C_FIELD(temp_r3_272, u8 *, 0x50) != 0) && (temp_r5_274 != NULL) && (var_r4_279 = temp_r5_274->unk8, ((var_r4_279 == NULL) == 0))) {

                } else {
                    var_r4_279 = NULL;
                }
                HitProp(var_r4_279, temp_r5_274);
                var_r25_267 += 1;
                var_r29_268 += 0x58;
                goto loop_9;
            }
            var_r31_218 += 1;
        } while (var_r31_218 < 4);
    }
    this->unk48 = M2C_BITWISE(f32, (M2C_BITWISE(s32, this->unk48) + 1));
    LandTransition();
}
#endif

void SpyroTailStrikeState::LandExit() {

}

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void SpyroTailStrikeState::LandEnter() {
    M2C_FIELD(this->unk10, f32 *, 0x38C) = 1900.0f;
    this->unk10->SetAnim(0x43U, 0.0f, (Spyro::AnimScriptNode) 0, 0U, 1.0f);
    this->unk48 = 0.0f;
}
#endif

#if 0 // DRAFT: illegal type
s32 SpyroTailStrikeState::DescentTransition() {
    MKCollisionResult sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f64 sp8;
    f64 temp_f0_374;
    f64 temp_f1_364;
    u8 var_r31_358;
    void *temp_r3_362;

    var_r31_358 = 0;
    sp20 = 0.0f;
    temp_r3_362 = this->unk10->unk8;
    sp18 = 0.0f;
    temp_f1_364 = M2C_FIELD(temp_r3_362, f64 *, 0x30);
    sp1C = 220.0f;
    sp30 = (f64) sp20;
    sp28 = (f64) sp18;
    sp38 = temp_f1_364;
    sp40 = M2C_FIELD(temp_r3_362, f64 *, 0x38);
    temp_f0_374 = temp_f1_364 - sp28;
    sp8 = temp_f0_374;
    sp48 = temp_f0_374;
    sp10 = (f32) sp40 - (f32) sp30;
    sp50 = (f64) sp10;
    if (MKCollision_SphereCollide(*((MKVector3 *) &sp48), 100.0f, &sp58, 0xA, (MKCollisionMode) 7, 0x04000220) != 0) {
        var_r31_358 = 1;
    }
    if ((var_r31_358 != 0) && ((u8) M2C_FIELD(this, u8 *, 0x50) != 0)) {
        KDSound_Play3d(GS_SpyroStompLand, this->unk10->unk8 + 0x30, 0U, -1, 0.0f, 0U);
        ((KDInput *) (this->unk10->GetInput()))->RumblePlay(0.5f, 0.7f, 0.1f, 0, 4.0f, 0U);
    }
    if ((var_r31_358 != 0) && ((s32) this->unk14.unk0 != 2)) {
        this->unk14.SetState(this, 2, 0U);
        return 1;
    }
    return 0;
}
#endif

void SpyroTailStrikeState::DescentUpdate() {
    f32 temp_f1_462;
    f32 temp_f1_466;
    f32 var_f3_455;

    var_f3_455 = 0.5f * (5.0f * gUpdateTimeDelta);
    if (var_f3_455 < 1.0f) {

    } else {
        var_f3_455 = 1.0f;
    }
    temp_f1_462 = this->unk48;
    temp_f1_466 = (var_f3_455 * (-4000.0f - temp_f1_462)) + temp_f1_462;
    this->unk48 = (var_f3_455 * (-4000.0f - temp_f1_466)) + temp_f1_466;
    this->unk10->SetDesiredVelocityVectical(this->unk48, 540000.0f);
    this->unk28.Update();
    DescentTransition();
}

void SpyroTailStrikeState::DescentExit() {
    Spyro *temp_r3_487;

    temp_r3_487 = this->unk10;
    temp_r3_487->unk428 |= 0x20000;
}

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void SpyroTailStrikeState::DescentEnter() {
    s32 spC;
    s32 sp8;
    KDCamera *temp_r3_538;
    Spyro *temp_r3_503;
    Spyro *temp_r3_529;
    f32 temp_f0_507;
    f32 temp_f1_505;
    f32 var_f2_506;

    temp_r3_503 = this->unk10;
    temp_r3_503->unk388 = 3800.0f;
    temp_f1_505 = temp_r3_503->unk388;
    var_f2_506 = temp_r3_503->unk33C;
    temp_f0_507 = -temp_f1_505;
    if (var_f2_506 < temp_f1_505) {

    } else {
        var_f2_506 = temp_f1_505;
    }
    if (var_f2_506 > temp_f0_507) {

    } else {
        var_f2_506 = temp_f0_507;
    }
    temp_r3_503->unk33C = var_f2_506;
    M2C_FIELD(this->unk10, f32 *, 0x38C) = 0.0f;
    temp_r3_529 = this->unk10;
    temp_r3_529->unk428 &= 0xFFFDFFFF;
    this->unk48 = -3400.0f;
    this->unk10->SetAnim(0x42U, 0.1f, (Spyro::AnimScriptNode) 0, 0U, 1.0f);
    temp_r3_538 = this->unk10->GetCamera();
    spC = 0;
    sp8 = 0x416;
    M2C_FIELD(temp_r3_538->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp8);
    M2C_FIELD(this, s8 *, 0x50) = 1;
    this->unk28.Reset();
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
s32 SpyroTailStrikeState::StartTransition() {
    if (((s32) this->unk10->GetAnimScript((Spyro::AnimScriptNode) 0)->unk44 >= 2) && ((s32) this->unk14.unk0 != 1)) {
        this->unk14.SetState(this, 1, 0U);
        return 1;
    }
    return 0;
}
#endif

void SpyroTailStrikeState::StartUpdate() {
    StartTransition();
}

void SpyroTailStrikeState::StartExit() {
    Spyro *temp_r3_609;

    temp_r3_609 = this->unk10;
    temp_r3_609->unk428 |= 0x20000;
}

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void SpyroTailStrikeState::StartEnter() {
    s32 spC;
    s32 sp8;
    KDCamera *temp_r3_650;
    Spyro *temp_r3_638;

    this->unk10->GetYaw();
    ((SpyroRotation *) &this->unk10->unk3A0)->YawTowards(M2C_ERROR(/* Read from unset register $f1 */), 900.0f);
    M2C_FIELD(this->unk10, f32 *, 0x38C) = 0.0f;
    this->unk10->SetDesiredVelocity(MKVector3::zero, 540000.0f);
    temp_r3_638 = this->unk10;
    temp_r3_638->unk428 &= 0xFFFDFFFF;
    this->unk10->SetAnim(0x41U, 0.1f, (Spyro::AnimScriptNode) 0, 0U, 1.0f);
    temp_r3_650 = this->unk10->GetCamera();
    spC = 0;
    sp8 = 0x415;
    M2C_FIELD(temp_r3_650->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp8);
}
#endif

void SpyroTailStrikeState::ProcessAnimEvent(unsigned int arg0) {

}

void SpyroTailStrikeState::Message(MKMessage *arg0) {

}

s32 SpyroTailStrikeState::Transition() {
    s32 var_r31_687;

    var_r31_687 = 0;
    if ((this->unk10->LavaTransition() != 0) || (this->unk10->SpikyTransition() != 0)) {
        var_r31_687 = 1;
    }
    return var_r31_687;
}

#if 0 // DRAFT: undefined identifier 'unk14'
void SpyroTailStrikeState::Update() {
    this->unk14.Update(this, 0);
}
#endif

#if 0 // DRAFT: undefined identifier 'unk14'
void SpyroTailStrikeState::Exit() {
    Spyro *temp_r3_732;

    temp_r3_732 = this->unk10;
    temp_r3_732->unk428 |= 1;
    this->unk10->SetMeleeButtonStateTimeout(0U);
    this->unk14.Exit(this);
}
#endif

#if 0 // DRAFT: undefined identifier 'unk14'
void SpyroTailStrikeState::Enter(SpyroStateMessages &arg0) {
    Spyro *temp_r3_761;
    Spyro *temp_r4_777;

    this->unk14.SetState(this, 0, 0U);
    temp_r3_761 = this->unk10;
    temp_r3_761->unk428 &= 0xFFFFFFFE;
    ((CombatStateData *) &this->unk10->unk430.unk28)->SetTailStrikeEnabled(0U);
    ((CombatStateData *) &this->unk10->unk430.unk28)->SetTailSweepEnabled(0U);
    ((CombatStateData *) &this->unk10->unk430.unk28)->SetHornDiveEnabled(0U);
    temp_r4_777 = this->unk10;
loop_2:
    if ((u32) *M2C_FIELD(temp_r4_777, u32 **, 0x6F0) != 0U) {
        M2C_FIELD(temp_r4_777, u32 **, 0x6F0) = (u32 *) (M2C_FIELD(temp_r4_777, u32 **, 0x6F0) + 4);
        goto loop_2;
    }
    this->unk10->ClearMeleeButtonState();
    this->unk10->SetMeleeButtonStateTimeout(1U);
}
#endif

#if 0 // DRAFT: undefined identifier 'unk14'
void SpyroTailStrikeState::Deinit() {
    this->unk14.Deinit();
}
#endif

#if 0 // DRAFT: undefined identifier 'Init__38KDStateMachine'
void SpyroTailStrikeState::Init(Spyro *arg0) {
    this->unk10 = arg0;
    Init__38KDStateMachine<20SpyroTailStrikeState>FPQ238KDStateMachine<20SpyroTailStrikeState>5StateP38KDStateMachine<20SpyroTailStrikeState>(&this->unk14, (KDStateMachine<SpyroTailStrikeState>::State *) &SpyroTailStrikeState::states, NULL);
    this->unk48 = 0.0f;
    M2C_FIELD(this, s8 *, 0x50) = 1;
    this->unk48 = 0.0f;
    this->unk28.Init((MKProp *) this->unk10);
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_762'
void SpyroTailStrikeState_cpp::__sinit() {
    f64 temp_f0_1107;
    f64 temp_f1_1067;
    f64 temp_f1_1087;
    f64 temp_f1_1103;
    f64 temp_f3_1053;
    f64 temp_f3_1100;
    f64 temp_f4_1066;
    f64 temp_f4_1084;
    f64 temp_f4_1097;
    f64 temp_f8_1055;
    void *temp_r17_1058;

    temp_f3_1053 = __frsqrte(2014000.0);
    temp_f8_1055 = __frsqrte(380000.0);
    temp_r17_1058 = &lit_762 + 0x6C;
    temp_f4_1066 = 0.5 * temp_f3_1053 * -((2014000.0 * (temp_f3_1053 * temp_f3_1053)) - 3.0);
    temp_f1_1067 = 0.5 * temp_f8_1055 * -((380000.0 * (temp_f8_1055 * temp_f8_1055)) - 3.0);
    temp_f4_1084 = 0.5 * temp_f4_1066 * -((2014000.0 * (temp_f4_1066 * temp_f4_1066)) - 3.0);
    temp_f1_1087 = 0.5 * temp_f1_1067 * -((380000.0 * (temp_f1_1067 * temp_f1_1067)) - 3.0);
    temp_f4_1097 = 0.5 * temp_f4_1084;
    temp_f3_1100 = -((2014000.0 * (temp_f4_1084 * temp_f4_1084)) - 3.0);
    temp_f1_1103 = 0.5 * temp_f1_1087;
    temp_f0_1107 = -((380000.0 * (temp_f1_1087 * temp_f1_1087)) - 3.0);
    M2C_FIELD(&lit_762, s32 *, 0x6C) = (s32) M2C_FIELD(&lit_762, s32 *, 0);
    M2C_FIELD(&lit_762, s32 *, 0x70) = (s32) M2C_FIELD(&lit_762, s32 *, 4);
    M2C_FIELD(&lit_762, s32 *, 0x74) = (s32) M2C_FIELD(&lit_762, s32 *, 8);
    M2C_FIELD(temp_r17_1058, s32 *, 0xC) = (s32) M2C_FIELD(&lit_762, s32 *, 0xC);
    M2C_FIELD(temp_r17_1058, s32 *, 0x10) = (s32) M2C_FIELD(&lit_762, s32 *, 0x10);
    M2C_FIELD(temp_r17_1058, s32 *, 0x14) = (s32) M2C_FIELD(&lit_762, s32 *, 0x14);
    M2C_FIELD(temp_r17_1058, s32 *, 0x18) = (s32) M2C_FIELD(&lit_762, s32 *, 0x18);
    M2C_FIELD(temp_r17_1058, s32 *, 0x1C) = (s32) M2C_FIELD(&lit_762, s32 *, 0x1C);
    M2C_FIELD(temp_r17_1058, s32 *, 0x20) = (s32) M2C_FIELD(&lit_762, s32 *, 0x20);
    M2C_FIELD(temp_r17_1058, s32 *, 0x24) = (s32) M2C_FIELD(&lit_762, s32 *, 0x24);
    M2C_FIELD(temp_r17_1058, s32 *, 0x28) = (s32) M2C_FIELD(&lit_762, s32 *, 0x28);
    M2C_FIELD(temp_r17_1058, s32 *, 0x2C) = (s32) M2C_FIELD(&lit_762, s32 *, 0x2C);
    M2C_FIELD(temp_r17_1058, s32 *, 0x30) = (s32) M2C_FIELD(&lit_762, s32 *, 0x30);
    M2C_FIELD(temp_r17_1058, s32 *, 0x34) = (s32) M2C_FIELD(&lit_762, s32 *, 0x34);
    M2C_FIELD(temp_r17_1058, s32 *, 0x38) = (s32) M2C_FIELD(&lit_762, s32 *, 0x38);
    M2C_FIELD(temp_r17_1058, s32 *, 0x3C) = (s32) M2C_FIELD(&lit_762, s32 *, 0x3C);
    M2C_FIELD(temp_r17_1058, s32 *, 0x40) = (s32) M2C_FIELD(&lit_762, s32 *, 0x40);
    M2C_FIELD(temp_r17_1058, s32 *, 0x44) = (s32) M2C_FIELD(&lit_762, s32 *, 0x44);
    M2C_FIELD(temp_r17_1058, s32 *, 0x48) = (s32) M2C_FIELD(&lit_762, s32 *, 0x48);
    M2C_FIELD(temp_r17_1058, s32 *, 0x4C) = (s32) M2C_FIELD(&lit_762, s32 *, 0x4C);
    M2C_FIELD(temp_r17_1058, s32 *, 0x50) = (s32) M2C_FIELD(&lit_762, s32 *, 0x50);
    M2C_FIELD(temp_r17_1058, s32 *, 0x54) = (s32) M2C_FIELD(&lit_762, s32 *, 0x54);
    M2C_FIELD(temp_r17_1058, s32 *, 0x58) = (s32) M2C_FIELD(&lit_762, s32 *, 0x58);
    M2C_FIELD(temp_r17_1058, s32 *, 0x5C) = (s32) M2C_FIELD(&lit_762, s32 *, 0x5C);
    M2C_FIELD(temp_r17_1058, s32 *, 0x60) = (s32) M2C_FIELD(&lit_762, s32 *, 0x60);
    M2C_FIELD(temp_r17_1058, s32 *, 0x64) = (s32) M2C_FIELD(&lit_762, s32 *, 0x64);
    M2C_FIELD(temp_r17_1058, s32 *, 0x68) = (s32) M2C_FIELD(&lit_762, s32 *, 0x68);
    SPYRO_BOUNCE_Y_SPEED = (f32) (2014000.0 * (temp_f4_1097 * temp_f3_1100));
    SPYRO_MIN_JUMP_Y_VELOCITY = (f32) (380000.0 * (temp_f1_1103 * temp_f0_1107));
}
#endif
