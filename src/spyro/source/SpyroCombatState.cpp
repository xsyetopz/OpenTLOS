#include "spyro/source/SpyroCombatState.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "spyro/source/Enemy.h"
#include "spyro/source/GameData.h"
#include "spyro/source/HitFX.h"
#include "spyro/source/InputModifier.h"
#include "spyro/source/KDCamera.h"
#include "spyro/source/KDInput.h"
#include "spyro/source/MeleeAttackHitMsg.h"
#include "spyro/source/Spyro.h"
#include "spyro/source/SpyroTools.h"
#include "spyro/source/TargetManager.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKInput.h"
#include "common/Source/StdMath.h"
#include <m2c_macros.h>

extern f32 SPYRO_BOUNCE_Y_SPEED;
extern f32 SPYRO_MIN_JUMP_Y_VELOCITY;
extern f32 fCometDashTargetArc;
extern f32 gUpdateTimeDelta;
extern M2C_UNK gb;
static f32 animSpeedMultiplier[0x11] = {
    1.0f,
    1.0f,
    1.0f,
    1.0f,
    1.0f,
    1.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
};
SpyroCombatState states__16SpyroCombatState;        /* unable to generate initializer: confusing struct layout */

void SpyroCombatState::CometDashTransition() {
    u32 var_r5_37;

    if (((KDInput *) (this->unk10->GetInput()))->GetLeftMag() != 0.0f) {
        var_r5_37 = 0;
    } else {
        var_r5_37 = 4;
    }
    this->unk10->TryChangeState(((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1DU) & 1, var_r5_37, NULL, 0U);
}

void SpyroCombatState::CometDashUpdate() {
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f64 sp8;
    Spyro *temp_r3_71;
    f64 temp_f0_97;
    void *temp_r4_72;

    temp_r3_71 = this->unk10;
    temp_r4_72 = temp_r3_71->unk8;
    sp18 = -M2C_FIELD(temp_r4_72, f32 *, 0x20);
    sp1C = -M2C_FIELD(temp_r4_72, f32 *, 0x24);
    sp20 = -M2C_FIELD(temp_r4_72, f32 *, 0x28);
    sp38 = (f64) sp18;
    sp40 = (f64) sp20;
    if (((CombatStateData *) &temp_r3_71->unk430.unk28)->GetHitTarget() == 0) {
        ((CombatStateData *) &this->unk10->unk430.unk28)->GetTargetDir((MKVector3 *) &sp38);
    }
    temp_f0_97 = sp38 * 5.7204941e-315;
    sp8 = temp_f0_97;
    sp28 = temp_f0_97;
    sp10 = (f32) sp40 * 2100.0f;
    sp30 = (f64) sp10;
    this->unk10->SetDesiredVelocityHoriz(*((MKVector3 *) &sp28), 3800.0f);
    CometDashTransition();
}

#if 0 // DRAFT: undefined identifier '__vptr'
void SpyroCombatState::CometDashExit() {
    s32 spC;
    s32 sp8;
    KDCamera *temp_r3_128;

    temp_r3_128 = this->unk10->GetCamera();
    spC = 0;
    sp8 = 0x43A;
    M2C_FIELD(temp_r3_128->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp8);
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void SpyroCombatState::CometDashEnter() {
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    s32 sp10;
    s32 spC;
    f32 sp8;
    KDCamera *temp_r3_178;
    TargetManager **temp_r3_216;
    f32 var_f4_230;
    f32 var_f5_255;
    f64 temp_f1_223;
    f64 temp_f1_260;
    f64 temp_f1_266;
    f64 temp_f1_270;
    s32 temp_r3_289;
    s32 var_r0_299;
    void *temp_r3_229;
    void *temp_r4_221;
    void *temp_r8_192;

    this->unk38 = M2C_FIELD(&gb, f32 *, 0x30C) + 1.0f;
    this->unk2F = 0;
    this->unk28 = 6;
    ((CombatStateData *) &this->unk10->unk430.unk28)->SetCombatArc(5);
    ((CombatStateData *) &this->unk10->unk430.unk28)->SetHitType(8);
    this->unk10->SetAnim(9U, 0.1f, (Spyro::AnimScriptNode) 0, 0U, 1.0f);
    temp_r3_178 = this->unk10->GetCamera();
    sp10 = 0;
    spC = 0x439;
    M2C_FIELD(temp_r3_178->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&spC);
    temp_r8_192 = this->unk10->unk8;
    sp18 = -M2C_FIELD(temp_r8_192, f32 *, 0x20);
    sp1C = -M2C_FIELD(temp_r8_192, f32 *, 0x24);
    sp20 = -M2C_FIELD(temp_r8_192, f32 *, 0x28);
    sp78 = (f64) sp18;
    sp80 = (f64) sp20;
    sp88 = M2C_FIELD(temp_r8_192, f64 *, 0x30);
    sp90 = M2C_FIELD(temp_r8_192, f64 *, 0x38);
    temp_r3_216 = ((TargetManager *) (M2C_FIELD(&gb, TargetManager **, 0x20)))->GetNearestFacingEnemy(*((MKVector3 *) &sp88), 1000.0f, *((MKVector3 *) &sp78), fCometDashTargetArc, 1U, 0U);
    if (temp_r3_216 != NULL) {
        temp_r4_221 = this->unk10->unk8;
        temp_f1_223 = M2C_FIELD(temp_r4_221, f64 *, 0x30);
        sp48 = temp_f1_223;
        sp50 = M2C_FIELD(temp_r4_221, f64 *, 0x38);
        temp_r3_229 = M2C_FIELD((*temp_r3_216)->unk8.unk0(temp_r4_221, temp_f1_223), void **, 8);
        var_f4_230 = 0.0f;
        sp58 = M2C_FIELD(temp_r3_229, f64 *, 0x30);
        sp60 = M2C_FIELD(temp_r3_229, f64 *, 0x38);
        sp3C = 0.0f;
        sp38 = (f32) sp58 - (f32) sp48;
        sp40 = (f32) sp60 - (f32) sp50;
        sp68 = (f64) sp38;
        sp70 = (f64) sp40;
        var_f5_255 = ((f32) sp70 * (f32) sp70) + (((f32) sp68 * (f32) sp68) + ((*(f32 *) ((u8 *) &sp68 + 0x4)) * (*(f32 *) ((u8 *) &sp68 + 0x4))));
        if (var_f5_255 > 1e-12f) {
            if (var_f5_255 > 0.0f) {
                temp_f1_260 = __frsqrte(var_f5_255);
                temp_f1_266 = 0.5 * temp_f1_260 * -(((f64) var_f5_255 * (temp_f1_260 * temp_f1_260)) - 3.0);
                temp_f1_270 = 0.5 * temp_f1_266 * -(((f64) var_f5_255 * (temp_f1_266 * temp_f1_266)) - 3.0);
                var_f5_255 = (f32) ((f64) var_f5_255 * (0.5 * temp_f1_270 * -(((f64) var_f5_255 * (temp_f1_270 * temp_f1_270)) - 3.0)));
            } else if (var_f5_255 < M2C_BITWISE(f32, 0.0)) {
                var_f5_255 = __float_nan;
            } else {
                sp8 = var_f5_255;
                temp_r3_289 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                switch (temp_r3_289) {              /* irregular */
                case 0x7F800000:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_299 = 1;
                    } else {
                        var_r0_299 = 2;
                    }
                    break;
                case 0x0:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_299 = 5;
                    } else {
                        var_r0_299 = 3;
                    }
                    break;
                default:
                    var_r0_299 = 4;
                    break;
                }
                if (var_r0_299 == 1) {
                    var_f5_255 = __float_nan;
                }
            }
            var_f4_230 = 1.0f / var_f5_255;
        }
        sp2C = (*(f32 *) ((u8 *) &sp68 + 0x4)) * var_f4_230;
        sp28 = (f32) sp68 * var_f4_230;
        sp30 = (f32) sp70 * var_f4_230;
        sp98 = (f64) sp28;
        spA0 = (f64) sp30;
        ((CombatStateData *) &this->unk10->unk430.unk28)->SetTargetDir(1U, *((MKVector3 *) &sp98));
    } else {
        ((CombatStateData *) &this->unk10->unk430.unk28)->SetTargetDir(0U, MKVector3::zero);
    }
    this->unk10->StartCombatArc(((CombatStateData *) &this->unk10->unk430.unk28)->GetCombatArc());
    this->unk32 = 1;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
u8 SpyroCombatState::ChargeKnockdownTransition() {
    s8 sp2D;
    s8 sp2C;
    f32 sp28;
    f32 sp24;
    s32 sp20;
    s32 sp1C;
    s32 sp18;
    f64 sp10;
    f64 sp8;
    Spyro *temp_r3_388;
    Spyro *temp_r3_417;
    u8 var_r31_416;
    u8 var_r4_389;
    u8 var_r4_418;
    void *temp_r5_393;

    sp1C = 0;
    sp20 = -1;
    sp18 = 0x187;
    sp24 = 0.0f;
    sp28 = 0.2f;
    sp2C = 1;
    sp2D = 1;
    if (this->unk10->OnFloor() == 0) {
        temp_r3_388 = this->unk10;
        var_r4_389 = 1;
        if ((u8) M2C_FIELD(temp_r3_388, u8 *, 0x2F0) != 0) {
            temp_r5_393 = temp_r3_388->unk8;
            sp8 = M2C_FIELD(temp_r5_393, f64 *, 0x30);
            sp10 = M2C_FIELD(temp_r5_393, f64 *, 0x38);
            if (!(((*(f32 *) ((u8 *) &sp8 + 0x4)) - temp_r3_388->unk2A4) > 33.0f)) {
                var_r4_389 = 0;
            }
        }
        if (temp_r3_388->TryChangeState(var_r4_389, 6U, NULL, 0U) != 0) {
            return 1U;
        }
        goto block_6;
    }
block_6:
    var_r31_416 = 1;
    temp_r3_417 = this->unk10;
    var_r4_418 = 0;
    if (((u8) this->unk2E != 0) && ((s32) M2C_FIELD(temp_r3_417->unk26C.unk8, s32 *, 0x16C) > 0)) {
        var_r4_418 = 1;
    }
    if ((temp_r3_417->TryChangeState(var_r4_418, 4U, (MKMessage *) &sp18, 0U) == 0) && (this->unk10->TryChangeState(this->unk10->GetAnimScript((Spyro::AnimScriptNode) 0)->unk2C & 1, 4U, NULL, 0U) == 0)) {
        var_r31_416 = 0;
    }
    return var_r31_416;
}
#endif

void SpyroCombatState::ChargeKnockdownUpdate() {
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    Spyro *temp_r3_470;
    f64 temp_f0_489;
    f64 temp_f0_499;
    void *temp_r4_472;

    ChargeKnockdownTransition();
    temp_r3_470 = this->unk10;
    temp_r4_472 = temp_r3_470->unk8;
    sp8 = -M2C_FIELD(temp_r4_472, f32 *, 0x20);
    spC = -M2C_FIELD(temp_r4_472, f32 *, 0x24);
    sp10 = -M2C_FIELD(temp_r4_472, f32 *, 0x28);
    sp38 = (f64) sp8;
    sp40 = (f64) sp10;
    temp_f0_489 = sp38 * 1.624458753e-314;
    sp28 = temp_f0_489;
    sp48 = temp_f0_489;
    sp30 = (f32) sp40 * -500.0f;
    sp50 = (f64) sp30;
    temp_f0_499 = temp_f0_489 * (f64) gUpdateTimeDelta;
    sp18 = temp_f0_499;
    sp58 = temp_f0_499;
    sp20 = (f32) sp50 * gUpdateTimeDelta;
    sp60 = (f64) sp20;
    temp_r3_470->SetDeltaPos(*((MKVector3 *) &sp58));
}

void SpyroCombatState::ChargeKnockdownExit() {

}

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void SpyroCombatState::ChargeKnockdownEnter() {
    MeleeAttackHitMsg sp188;
    u8 sp180;
    f32 sp178;
    f32 sp174;
    MKProp sp128;
    MKProp spD8;
    f64 spD0;
    f64 spC8;
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
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f64 sp8;
    MKProp *temp_r3_595;
    Spyro *temp_r3_564;
    Spyro *temp_r3_604;
    Spyro *temp_r4_575;
    Spyro *temp_r4_682;
    f32 temp_f2_636;
    f32 temp_f30_609;
    f64 temp_f0_699;
    f64 temp_f0_711;
    f64 temp_f0_721;
    f64 temp_f1_660;
    f64 temp_f2_658;
    s32 temp_r29_745;
    void *temp_r28_755;
    void *temp_r3_684;
    void *temp_r4_654;

    this->unk2E = 0;
    this->unk28 = 5;
    if (((CombatStateData *) &this->unk10->unk430.unk28)->GetChargeTime() > 0.5f) {
        ((CombatStateData *) &this->unk10->unk430.unk28)->SetHitType(8);
    } else {
        ((CombatStateData *) &this->unk10->unk430.unk28)->SetHitType(1);
    }
    ((CombatStateData *) &this->unk10->unk430.unk28)->SetCombatArc(1);
    temp_r3_564 = this->unk10;
    temp_r3_564->unk428 |= 1;
    this->unk10->SetAnim(0x21U, 0.1f, (Spyro::AnimScriptNode) 0, 0U, 1.0f);
    temp_r4_575 = this->unk10;
loop_5:
    if ((u32) *temp_r4_575->unk6F0 != 0U) {
        temp_r4_575->unk6F0 += 4;
        goto loop_5;
    }
    SetTargetDirection();
    if (((CombatStateData *) &this->unk10->unk430.unk28)->GetChargeHitProp() != NULL) {
        temp_r3_595 = ((CombatStateData *) &this->unk10->unk430.unk28)->GetChargeHitProp();
        if (temp_r3_595 != NULL) {
            sp188.unk4 = 0;
            this->unk10->SetupMeleeAttackHitMsg(this->unk28, &sp188);
            temp_r3_604 = this->unk10;
            temp_f30_609 = temp_r3_604->GetCollisionRadius();
            spD8.GetPos();
            ((MKProp *) &spD8.unk10)->GetPos();
            KDMath_Sub2D(*((MKVector3 *) &spD8.unk20), *((MKVector3 *) &spD8.unk10));
            Normalise(*((MKVector3 *) &spD8.unk30));
            ((MKVector3 *) &spD8.unk40)->operator*(temp_f30_609);
            sp128.GetPos();
            sp8 = sp128 + M2C_BITWISE(f64, spD8.unk40);
            temp_f2_636 = M2C_BITWISE(f32, sp128.unk8);
            sp188.unk10 = sp8;
            sp10 = temp_f2_636 + spD8.unk48;
            sp128.unk10 = sp8;
            sp188.unk18 = (f64) sp10;
            sp128.unk18 = (f64) sp10;
            temp_r3_595->Message(&sp188, sp8, temp_f2_636);
            if ((u8) sp188.unk3E != 0) {
                temp_r4_654 = temp_r3_595->unk8;
                temp_f2_658 = M2C_FIELD(temp_r4_654, f64 *, 0x30);
                temp_f1_660 = M2C_FIELD(temp_r4_654, f64 *, 0x38);
                sp128.unk30 = temp_f2_658;
                sp128.__vptr = NULL;
                sp128.unk40 = 0x77;
                sp180 = 0;
                sp128.unk48 = 0.0f;
                sp174 = 0.0f;
                sp178 = 0.0f;
                sp128.unk38 = temp_f1_660;
                temp_r3_595->Message((MeleeAttackHitMsg *) &sp128.unk40, 0.0, (f32) temp_f1_660, temp_f2_658);
                if (sp180 != 0) {
                    sp128.unk30 = (f64) sp128.unk48;
                    sp128.unk38 = (f64) sp178;
                }
                temp_r4_682 = this->unk10;
                temp_r3_684 = temp_r4_682->unk8;
                sp40 = 0.0f;
                sp38 = 0.0f;
                sp3C = 125.0f;
                sp98 = M2C_FIELD(temp_r3_684, f64 *, 0x30);
                sp88 = (f64) sp38;
                sp90 = (f64) sp40;
                spA0 = M2C_FIELD(temp_r3_684, f64 *, 0x38);
                temp_f0_699 = sp98 - sp128.unk30;
                sp68 = temp_f0_699;
                spA8 = temp_f0_699;
                sp70 = (f32) spA0 - (f32) sp128.unk38;
                spB0 = (f64) sp70;
                temp_f0_711 = temp_f0_699 * 5.222099017e-315;
                sp58 = temp_f0_711;
                spB8 = temp_f0_711;
                sp60 = (f32) spB0 * 0.5f;
                spC0 = (f64) sp60;
                temp_f0_721 = sp128.unk30 + temp_f0_711;
                sp48 = temp_f0_721;
                spC8 = temp_f0_721;
                sp50 = (f32) sp128.unk38 + (f32) spC0;
                spD0 = (f64) sp50;
                sp28 = spC8 + sp88;
                sp20 = 0.0f;
                sp18 = 0.0f;
                temp_r29_745 = M2C_FIELD(GameData::gameData, s32 *, 0x158);
                sp1C = 1.0f;
                sp30 = (f32) spD0 + (f32) sp90;
                sp128.unk20 = sp28;
                sp128.unk28 = (f64) sp30;
                sp78 = (f64) sp18;
                sp80 = (f64) sp20;
                temp_r28_755 = M2C_FIELD(temp_r4_682->unk258, void **, 4);
                ((HitFX *) (M2C_FIELD(temp_r28_755, HitFX **, 0x10)))->Trigger(*((MKVector3 *) &sp128.unk20), *((MKVector3 *) &sp78), *((GameStats *) &GameData::gameData[0x70])->GetCurrentBreathColor(), temp_r29_745);
                ((CombatStateData *) &this->unk10->unk430.unk28)->SetTargetDir(0U, MKVector3::zero);
                ((CombatStateData *) &this->unk10->unk430.unk28)->SetLastCombatEnemy(temp_r3_595);
                ((CombatStateData *) &this->unk10->unk430.unk28)->SetHitTarget(1U);
                this->unk10->unk3CD = 1;
            }
        }
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
s32 SpyroCombatState::KnockupTransition() {
    s8 sp1D;
    s8 sp1C;
    f32 sp18;
    f32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    Spyro *temp_r3_836;
    s32 var_r31_814;
    u8 var_r28_800;
    u8 var_r29_816;
    u8 var_r4_835;

    var_r28_800 = 0;
    if (((u8) this->unk2D != 0) && ((u8) this->unk31 != 0) && (this->unk10->SelectBestKnockedUpEnemy() != 0)) {
        var_r28_800 = 1;
    }
    var_r31_814 = 1;
    var_r29_816 = 0;
    spC = 0;
    sp10 = -1;
    sp8 = 0x187;
    sp14 = 0.0f;
    sp18 = 0.2f;
    sp1C = 1;
    sp1D = 1;
    if (this->unk10->TryChangeState(var_r28_800, 0xCU, NULL, 0U) == 0) {
        var_r4_835 = 0;
        temp_r3_836 = this->unk10;
        if (((u8) this->unk2E != 0) && ((s32) M2C_FIELD(temp_r3_836->unk26C.unk8, s32 *, 0x16C) > 0)) {
            var_r4_835 = 1;
        }
        if (temp_r3_836->TryChangeState(var_r4_835, 4U, (MKMessage *) &sp8, 0U) != 0) {
            goto block_9;
        }
    } else {
block_9:
        var_r29_816 = 1;
    }
    if ((var_r29_816 == 0) && (this->unk10->TryChangeState(this->unk10->GetAnimScript((Spyro::AnimScriptNode) 0)->unk2C & 1, 4U, NULL, 0U) == 0)) {
        var_r31_814 = 0;
    }
    return var_r31_814;
}
#endif

void SpyroCombatState::KnockupUpdate() {
    InputModifier *temp_r3_892;
    s32 var_r3_905;
    u8 var_r31_887;
    u8 var_r4_894;

    var_r31_887 = 1;
    if ((u8) this->unk31 == 0) {
        temp_r3_892 = this->unk10->GetInput();
        var_r4_894 = 0;
        if (((u8) temp_r3_892->unk5 != 0) || ((u8) temp_r3_892->unk4 != 0)) {
            var_r4_894 = 1;
        }
        if (var_r4_894 != 0) {
            var_r3_905 = 0;
        } else {
            var_r3_905 = MKInput_Pressed(0xE, (MKInputDevices) temp_r3_892->unk0);
        }
        if ((u8) var_r3_905 == 0) {
            var_r31_887 = 0;
        }
    }
    this->unk31 = var_r31_887;
    KnockupTransition();
}

#if 0 // DRAFT: pointer/array required
void SpyroCombatState::KnockupExit() {
    Enemy *var_r3_945;

    ((CombatStateData *) &this->unk10->unk430.unk28)->GetLastCombatEnemy();
    if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
        ((CombatStateData *) &this->unk10->unk430.unk28)->GetLastCombatEnemy();
        var_r3_945 = M2C_FIELD(*M2C_ERROR(/* Read from unset register $r3 */), Enemy *(**)(), 0xC)();
    } else {
        var_r3_945 = NULL;
    }
    if ((var_r3_945 != NULL) && (var_r3_945->IsKnockedUp() != 0)) {
        ((CombatStateData *) &this->unk10->unk430.unk28)->SetKnockupTime(M2C_FIELD(&gb, f32 *, 0x30C));
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void SpyroCombatState::KnockupEnter() {
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    Spyro *temp_r3_989;
    Spyro *temp_r3_993;

    this->unk10->ClearMeleeButtonState();
    this->unk32 = 1;
    this->unk2E = 0;
    this->unk2D = 0;
    this->unk31 = 0;
    this->unk2F = 0;
    this->unk28 = 3;
    temp_r3_989 = this->unk10;
    temp_r3_989->unk428 |= 1;
    temp_r3_993 = this->unk10;
    temp_r3_993->unk428 |= 0x30;
    ((CombatStateData *) &this->unk10->unk430.unk28)->SetHitType(2);
    ((CombatStateData *) &this->unk10->unk430.unk28)->SetCombatArc(0);
    this->unk10->SetAnim(0x20U, 0.2f, (Spyro::AnimScriptNode) 0, 4U, 1.0f);
    sp10 = 2.0f;
    sp8 = 2.0f;
    spC = 2.0f;
    sp20 = (f64) sp10;
    sp18 = (f64) sp8;
    this->unk10->SetLVEScale(*((MKVector3 *) &sp18));
    this->unk31 = 0;
}
#endif

#if 0 // DRAFT: pointer/array required
u8 SpyroCombatState::CombatTransition() {
    s8 sp2D;
    s8 sp2C;
    f32 sp28;
    f32 sp24;
    s32 sp20;
    s32 sp1C;
    s32 sp18;
    f64 sp10;
    f64 sp8;
    Spyro *temp_r3_1056;
    u32 temp_r0_1093;
    u32 temp_r3_1090;
    u32 temp_r3_1092;
    u8 var_r0_1171;
    u8 var_r3_1136;
    u8 var_r3_1164;
    u8 var_r4_1057;
    u8 var_r4_1190;
    void *temp_r5_1061;

    sp1C = 0;
    sp20 = -1;
    sp18 = 0x187;
    sp24 = 0.0f;
    sp28 = 0.2f;
    sp2C = 1;
    sp2D = 1;
    if (this->unk10->OnFloor() == 0) {
        temp_r3_1056 = this->unk10;
        var_r4_1057 = 1;
        if ((u8) M2C_FIELD(temp_r3_1056, u8 *, 0x2F0) != 0) {
            temp_r5_1061 = temp_r3_1056->unk8;
            sp8 = M2C_FIELD(temp_r5_1061, f64 *, 0x30);
            sp10 = M2C_FIELD(temp_r5_1061, f64 *, 0x38);
            if (!(((*(f32 *) ((u8 *) &sp8 + 0x4)) - temp_r3_1056->unk2A4) > 33.0f)) {
                var_r4_1057 = 0;
            }
        }
        if (temp_r3_1056->TryChangeState(var_r4_1057, 6U, NULL, 0U) != 0) {
            return 1U;
        }
        goto block_6;
    }
block_6:
    if (((u8) this->unk2D != 0) && ((u8) this->unk2F != 0)) {
        temp_r3_1090 = this->unk28 + 1;
        temp_r3_1092 = temp_r3_1090 >> 0x1FU;
        temp_r0_1093 = (temp_r3_1090 << 0x1E) - temp_r3_1092;
        this->unk28 = ((temp_r0_1093 << 2) | (temp_r0_1093 >> 0x1EU)) + temp_r3_1092;
        if ((s32) this->unk28 == 3) {
            if (((s32) (GameData::gameData[0x168] & 0x20) == 0x20) && (((CombatStateData *) &this->unk10->unk430.unk28)->GetLastCombatEnemy(), (((u32) M2C_ERROR(/* Read from unset register $r3 */) == 0U) == 0)) && (((CombatStateData *) &this->unk10->unk430.unk28)->GetLastCombatEnemy(), ((M2C_FIELD(*M2C_ERROR(/* Read from unset register $r3 */), u32 (**)(), 0xC)() == 0U) == 0)) && (((CombatStateData *) &this->unk10->unk430.unk28)->GetLastCombatEnemy(), ((M2C_FIELD(*M2C_ERROR(/* Read from unset register $r3 */), u8 (**)(), 0x20)() == 0) != 0))) {
                this->unk30 = 1;
            } else {
                this->unk28 = 0;
            }
        }
    }
    var_r3_1136 = this->unk2D;
    if (var_r3_1136 != 0) {
        var_r3_1136 = this->unk30;
    }
    if (var_r3_1136 != 0) {
        var_r3_1136 = ((u8) GameData::gameData[0x168] >> 5U) & 1;
    }
    if (var_r3_1136 != 0) {
        ((CombatStateData *) &this->unk10->unk430.unk28)->GetLastCombatEnemy();
        var_r3_1136 = M2C_ERROR(/* Read from unset register $r3 */) != 0;
    }
    if (var_r3_1136 != 0) {
        this->unk14.SetState(this, 1, 1U);
        var_r3_1164 = 1;
    } else {
        var_r3_1164 = 0;
    }
    if (var_r3_1164 == 0) {
        var_r0_1171 = this->unk2D;
        if (var_r0_1171 != 0) {
            var_r0_1171 = this->unk2F;
        }
        if (var_r0_1171 != 0) {
            this->unk14.SetState(this, 0, 1U);
            var_r3_1164 = 1;
        } else {
            var_r3_1164 = 0;
        }
    }
    if (var_r3_1164 == 0) {
        var_r4_1190 = this->unk2E;
        if (var_r4_1190 != 0) {
            var_r4_1190 = M2C_FIELD(this->unk10->unk26C.unk8, s32 *, 0x16C) > 0;
        }
        var_r3_1164 = this->unk10->TryChangeState(var_r4_1190, 4U, (MKMessage *) &sp18, 0U);
    }
    if (var_r3_1164 == 0) {
        var_r3_1164 = this->unk10->TryChangeState(this->unk10->GetAnimScript((Spyro::AnimScriptNode) 0)->unk2C & 1, 4U, NULL, 0U);
    }
    return var_r3_1164;
}
#endif

void SpyroCombatState::CombatUpdate() {
    if (((CombatStateData *) &this->unk10->unk430.unk28)->GetTargetDir(NULL) == 0) {
        this->unk10->SetLVEScale(MKVector3::one);
    }
    CombatTransition();
}

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void SpyroCombatState::CombatExit() {
    Spyro *temp_r4_1269;

    this->unk10->GetAnimScript((Spyro::AnimScriptNode) 0)->unk38 = 1.0f;
    temp_r4_1269 = this->unk10;
    temp_r4_1269->unk428 &= 0xFFFFFFCF;
    this->unk2C = 0;
    this->unk2E = 0;
}
#endif

#if 0 // DRAFT: undefined identifier 'MKVector'
void SpyroCombatState::CombatEnter() {
    MKCollisionResult spD8;
    MKProp sp88;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    MKVector3 sp58;
    M2C_UNK sp48;
    f64 sp40;
    f64 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    Spyro *temp_r3_1301;
    Spyro *temp_r3_1429;
    f32 temp_f31_1459;
    s32 temp_r0_1396;
    s32 temp_r30_1302;
    u32 temp_r3_1397;
    u32 temp_r4_1436;
    void *temp_r3_1362;
    void *temp_r3_1371;
    void *temp_r3_1380;

    this->unk10->ClearMeleeButtonState();
    this->unk32 = 1;
    this->unk2F = 0;
    this->unk30 = 0;
    this->unk2D = 0;
    this->unk2E = 0;
    temp_r3_1301 = this->unk10;
    temp_r30_1302 = this->unk28;
    MKVector(0.0f, temp_r3_1301->GetCollisionHeight(), 0.0f);
    sp88.GetPos();
    sp18 = sp88 + sp78;
    sp88.unk40 = sp18;
    sp20 = M2C_BITWISE(f32, sp88.unk8) + sp80;
    sp88.unk10 = sp18;
    sp88.unk48 = (f64) sp20;
    sp88.unk18 = (f64) sp20;
    ((MKProp *) &sp48)->GetDir();
    sp58.operator*(500.0f);
    sp8 = M2C_BITWISE(f64, sp88.unk40) + M2C_BITWISE(f64, sp58);
    sp68 = sp8;
    sp10 = sp88.unk48 + sp58.unk8;
    sp88.unk30 = sp8;
    sp70 = (f64) sp10;
    sp88.unk38 = (f64) sp10;
    if ((MKCollision_RayCollide(*((MKVector3 *) &sp88.unk40), *((MKVector3 *) &sp88.unk30), &spD8, (MKCollisionMode) 7, 0x04000000) != 0) && (spD8.unk48 != NULL)) {
        temp_r3_1362 = M2C_FIELD(spD8.unk48, void **, 8);
        if ((temp_r3_1362 != NULL) && (M2C_FIELD(M2C_FIELD(temp_r3_1362, void **, 0), s32 *, 0xC) & 0x8000)) {
            temp_r3_1371 = checked_cast<SpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk10->unk0);
            sp88.unk24 = 0.0f;
            sp88.unk20 = 1.95e-43f;
            sp88.unk28 = NULL;
            sp88.unk2C = M2C_FIELD(temp_r3_1371, MKProp **, 0x12C);
            temp_r3_1380 = M2C_FIELD(spD8.unk48, void **, 8);
            M2C_FIELD(M2C_FIELD(temp_r3_1380, void **, 0x44), M2C_UNK (**)(void *, f32 *, M2C_UNK), 0x2C)(temp_r3_1380, &sp88.unk20, 0);
            if (sp88.unk28 <= 1) {
                this->unk28 = 2;
                if (temp_r30_1302 != 1) {
                    this->unk2C = 1;
                }
            } else {
                temp_r0_1396 = this->unk28;
                temp_r3_1397 = (u32) temp_r0_1396 >> 0x1FU;
                this->unk28 = ((temp_r0_1396 & 1) ^ temp_r3_1397) - temp_r3_1397;
            }
        }
    }
    sp30 = 2.0f;
    sp28 = 2.0f;
    sp2C = 2.0f;
    sp40 = (f64) sp30;
    sp38 = (f64) sp28;
    this->unk10->SetLVEScale(*((MKVector3 *) &sp38));
    M2C_FIELD(GameData::gameData, s32 *, 0x150) = (s32) this->unk28;
    ((CombatStateData *) &this->unk10->unk430.unk28)->SetHitType(GetCombatHitType());
    ((CombatStateData *) &this->unk10->unk430.unk28)->SetCombatArc(this->unk28 + 2);
    temp_r3_1429 = this->unk10;
    temp_r3_1429->unk428 |= 0x30;
    temp_r4_1436 = this->unk28 + 0x1D;
    if ((u8) this->unk2C != 0) {
        this->unk10->SetAnim(temp_r4_1436, 0.2f, (Spyro::AnimScriptNode) 0, 0U, 1.0f);
    } else {
        this->unk10->SetAnim(temp_r4_1436, 0.0f, (Spyro::AnimScriptNode) 0, 4U, 1.0f);
    }
    temp_f31_1459 = animSpeedMultiplier[this->unk28];
    this->unk10->GetAnimScript((Spyro::AnimScriptNode) 0)->unk38 = temp_f31_1459;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk14'
s32 SpyroCombatState::GetCombatHitType() {
    if (this->unk14.GetState() == 0) {
        if ((s32) this->unk28 != 2) {
            return 0;
        }
        return 1;
    }
    return 2;
}
#endif

void SpyroCombatState::SetTargetDirection() {
    MKVector3 sp18;
    MKVector3 sp8;

    if (this->unk10->ChooseCombatTarget(&sp18, &sp8) != 0) {
        ((CombatStateData *) &this->unk10->unk430.unk28)->SetTargetDir(1U, sp8);
        return;
    }
    ((CombatStateData *) &this->unk10->unk430.unk28)->SetTargetDir(0U, MKVector3::zero);
}

void SpyroCombatState::ProcessAnimEvent(unsigned int arg0) {
    if ((s32) arg0 != 0x15) {
        return;
    }
    this->unk10->StartCombatArc(((CombatStateData *) &this->unk10->unk430.unk28)->GetCombatArc());
    this->unk32 = 0;
}

void SpyroCombatState::Message(MKMessage *arg0) {

}

s32 SpyroCombatState::Transition() {
    s32 var_r31_1578;

    var_r31_1578 = 0;
    if ((this->unk10->LavaTransition() != 0) || (this->unk10->SpikyTransition() != 0)) {
        var_r31_1578 = 1;
    }
    return var_r31_1578;
}

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void SpyroCombatState::Update() {
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 sp8;
    Spyro *temp_r3_1715;
    f32 var_f1_1692;
    f32 var_f4_1751;
    f32 var_f4_1818;
    f64 temp_f1_1728;
    f64 temp_f1_1757;
    f64 temp_f1_1763;
    f64 temp_f1_1767;
    s32 temp_r3_1612;
    s32 temp_r3_1786;
    s32 var_r0_1796;
    u8 var_r30_1607;
    u8 var_r30_1639;
    u8 var_r30_1653;
    void *temp_r3_1727;
    void *temp_r4_1716;

    var_r30_1607 = 0;
    M2C_FIELD(this->unk10->unk26C.unk8, f32 *, 0x47C) = 50.0f;
    temp_r3_1612 = this->unk10->GetMeleeButtonState();
    if (((u8) this->unk2F == 0) && ((u8) this->unk30 == 0) && (temp_r3_1612 != 0)) {
        var_r30_1607 = 1;
        this->unk2F = temp_r3_1612 == 1;
        this->unk30 = temp_r3_1612 == 2;
    }
    if (var_r30_1607 != 0) {
        this->unk2F = 1;
        SetTargetDirection();
    }
    var_r30_1639 = 0;
    if (((u8) this->unk2D != 0) || (((MKAnimScript *) (this->unk10->GetAnimScript((Spyro::AnimScriptNode) 0)))->CheckEvent(3) != 0)) {
        var_r30_1639 = 1;
    }
    this->unk2D = var_r30_1639;
    var_r30_1653 = 0;
    if (((u8) this->unk2E != 0) || (((MKAnimScript *) (this->unk10->GetAnimScript((Spyro::AnimScriptNode) 0)))->CheckEvent(5) != 0)) {
        var_r30_1653 = 1;
    }
    this->unk2E = var_r30_1653;
    sp70 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    sp78 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
    if (((CombatStateData *) &this->unk10->unk430.unk28)->GetTargetDir((MKVector3 *) &sp70) != 0) {
        if ((u8) this->unk32 == 0) {
            var_f1_1692 = *(this->unk10 + (((this->unk28 + 2) << 5) + 0x4E8)) - M2C_FIELD(&gb, f32 *, 0x30C);
            if (var_f1_1692 > 0.0f) {

            } else {
                var_f1_1692 = 0.0f;
            }
            if (var_f1_1692 != 0.0f) {
                goto block_18;
            }
            goto block_19;
        }
block_18:
        ((SpyroRotation *) &this->unk10->unk3A0)->YawTowards(*((MKVector3 *) &sp70), 12.0f);
    } else {
block_19:
        ((CombatStateData *) &this->unk10->unk430.unk28)->GetLastCombatEnemy();
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            temp_r3_1715 = this->unk10;
            temp_r4_1716 = temp_r3_1715->unk8;
            sp30 = M2C_FIELD(temp_r4_1716, f64 *, 0x30);
            sp38 = M2C_FIELD(temp_r4_1716, f64 *, 0x38);
            ((CombatStateData *) &temp_r3_1715->unk430.unk28)->GetLastCombatEnemy();
            temp_r3_1727 = M2C_FIELD(M2C_FIELD(*M2C_ERROR(/* Read from unset register $r3 */), void *(**)(), 8)(), void **, 8);
            temp_f1_1728 = M2C_FIELD(temp_r3_1727, f64 *, 0x30);
            sp40 = temp_f1_1728;
            sp48 = M2C_FIELD(temp_r3_1727, f64 *, 0x38);
            sp20 = temp_f1_1728 - sp30;
            sp50 = sp20;
            sp28 = (f32) sp48 - (f32) sp38;
            sp58 = (f64) sp28;
            var_f4_1751 = ((f32) sp58 * (f32) sp58) + (((f32) sp50 * (f32) sp50) + ((*(f32 *) ((u8 *) &sp50 + 0x4)) * (*(f32 *) ((u8 *) &sp50 + 0x4))));
            if (var_f4_1751 > 1e-12f) {
                if (var_f4_1751 > 0.0f) {
                    temp_f1_1757 = __frsqrte(var_f4_1751);
                    temp_f1_1763 = 0.5 * temp_f1_1757 * -(((f64) var_f4_1751 * (temp_f1_1757 * temp_f1_1757)) - 3.0);
                    temp_f1_1767 = 0.5 * temp_f1_1763 * -(((f64) var_f4_1751 * (temp_f1_1763 * temp_f1_1763)) - 3.0);
                    var_f4_1751 = (f32) ((f64) var_f4_1751 * (0.5 * temp_f1_1767 * -(((f64) var_f4_1751 * (temp_f1_1767 * temp_f1_1767)) - 3.0)));
                } else if (var_f4_1751 < M2C_BITWISE(f32, 0.0)) {
                    var_f4_1751 = __float_nan;
                } else {
                    sp8 = var_f4_1751;
                    temp_r3_1786 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                    switch (temp_r3_1786) {         /* irregular */
                    case 0x7F800000:
                        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                            var_r0_1796 = 1;
                        } else {
                            var_r0_1796 = 2;
                        }
                        break;
                    case 0x0:
                        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                            var_r0_1796 = 5;
                        } else {
                            var_r0_1796 = 3;
                        }
                        break;
                    default:
                        var_r0_1796 = 4;
                        break;
                    }
                    if (var_r0_1796 == 1) {
                        var_f4_1751 = __float_nan;
                    }
                }
                var_f4_1818 = 1.0f / var_f4_1751;
            } else {
                var_f4_1818 = 0.0f;
            }
            sp14 = (*(f32 *) ((u8 *) &sp50 + 0x4)) * var_f4_1818;
            sp10 = (f32) sp50 * var_f4_1818;
            sp18 = (f32) sp58 * var_f4_1818;
            sp60 = (f64) sp10;
            sp68 = (f64) sp18;
            ((SpyroRotation *) &this->unk10->unk3A0)->YawTowards(*((MKVector3 *) &sp60), 12.0f);
        }
    }
    this->unk14.Update(this, 0);
}
#endif

#if 0 // DRAFT: undefined identifier 'unk14'
void SpyroCombatState::Exit() {
    Spyro *temp_r3_1863;
    Spyro *temp_r3_1867;

    this->unk10->SetLVEScale(MKVector3::one);
    temp_r3_1863 = this->unk10;
    temp_r3_1863->unk428 &= 0xFFFF7FFF;
    temp_r3_1867 = this->unk10;
    temp_r3_1867->unk428 |= 1;
    ((CombatStateData *) &this->unk10->unk430.unk28)->SetDefaults();
    this->unk34 = M2C_FIELD(&gb, f32 *, 0x30C);
    M2C_FIELD(GameData::gameData, s32 *, 0x150) = 0;
    this->unk14.Exit(this);
}
#endif

#if 0 // DRAFT: ambiguous access to overloaded function
void SpyroCombatState::Enter(SpyroStateMessages &arg0) {
    s32 sp10;
    s32 spC;
    s32 sp8;
    Spyro *temp_r3_1915;
    Spyro *temp_r4_1923;
    Spyro *temp_r5_1908;
    f32 temp_f2_2022;
    s32 temp_r27_1956;
    s32 var_r26_1947;
    s32 var_r29_1952;
    s32 var_r29_2018;
    s32 var_r5_1994;
    u32 temp_r0_2042;
    u32 temp_r3_2039;
    u32 temp_r3_2041;
    u8 temp_r30_1906;
    void *temp_r3_2100;

    temp_r30_1906 = this->unk10->GetMeleeButtonState() == 2;
    this->unk10->ClearMeleeButtonState();
    temp_r5_1908 = this->unk10;
    temp_r5_1908->unk428 |= 0x8000;
    temp_r3_1915 = this->unk10;
    temp_r3_1915->unk428 &= 0xFFFFFFFE;
    this->unk10->SetDesiredVelocity(MKVector3::zero, 540000.0f);
    temp_r4_1923 = this->unk10;
    M2C_FIELD(temp_r4_1923, f64 *, 0x338) = (f64) M2C_FIELD(&MKVector3::zero, f64 *, 0);
    M2C_FIELD(temp_r4_1923, f64 *, 0x340) = (f64) M2C_FIELD(&MKVector3::zero, f64 *, 8);
    ((CombatStateData *) &this->unk10->unk430.unk28)->SetDefaults();
    M2C_FIELD(GameData::gameData, s32 *, 0x150) = 0;
    ((CombatStateData *) &this->unk10->unk430.unk28)->SetLastCombatEnemy(NULL);
    M2C_FIELD(this->unk10->unk26C.unk8, f32 *, 0x47C) = 50.0f;
    var_r26_1947 = arg0.IsMessageOnList(0x17F);
    var_r29_1952 = arg0.IsMessageOnList(0x17E);
    temp_r27_1956 = arg0.IsMessageOnList(0x181);
    if (((u8) var_r29_1952 != 0) && ((s32) (GameData::gameData[0x168] & 0x20) != 0x20)) {
        var_r26_1947 = 1;
        var_r29_1952 = 0;
    }
    SetTargetDirection();
    this->unk2C = 0;
    if (((u8) var_r26_1947 != 0) || ((u8) var_r29_1952 != 0)) {
        if (((u8) var_r29_1952 != 0) && (temp_r30_1906 == 0) && ((((CombatStateData *) &this->unk10->unk430.unk28)->GetChargeHitProp() == NULL) || !(M2C_FIELD(((CombatStateData *) &this->unk10->unk430.unk28)->GetChargeHitProp()->unk0, s32 *, 0xC) & 8))) {
            var_r29_1952 = 0;
        }
        var_r5_1994 = 2;
        if ((u8) var_r29_1952 != 0) {
            var_r5_1994 = 1;
        }
        this->unk2C = 1;
        this->unk14.SetState(this, var_r5_1994, 1U);
    } else if ((u8) temp_r27_1956 != 0) {
        this->unk2C = 1;
        this->unk14.SetState(this, 3, 1U);
    } else {
        var_r29_2018 = 0;
        ((CombatStateData *) &this->unk10->unk430.unk28)->SetChargeHitProp(NULL);
        temp_f2_2022 = this->unk34;
        if ((temp_f2_2022 != 0.0f) && ((M2C_FIELD(&gb, f32 *, 0x30C) - temp_f2_2022) < 0.5f) && ((s32) this->unk28 < 4)) {
            this->unk2C = 1;
            temp_r3_2039 = this->unk28 + 1;
            temp_r3_2041 = temp_r3_2039 >> 0x1FU;
            temp_r0_2042 = (temp_r3_2039 << 0x1E) - temp_r3_2041;
            this->unk28 = ((temp_r0_2042 << 2) | (temp_r0_2042 >> 0x1EU)) + temp_r3_2041;
            if ((s32) this->unk28 == 3) {
                if (((s32) (GameData::gameData[0x168] & 0x20) == 0x20) && (((CombatStateData *) &this->unk10->unk430.unk28)->GetLastCombatEnemy(), (((u32) M2C_ERROR(/* Read from unset register $r3 */) == 0U) == 0)) && (((CombatStateData *) &this->unk10->unk430.unk28)->GetLastCombatEnemy(), ((M2C_FIELD(*M2C_ERROR(/* Read from unset register $r3 */), u32 (**)(), 0xC)() == 0U) == 0)) && (((CombatStateData *) &this->unk10->unk430.unk28)->GetLastCombatEnemy(), ((M2C_FIELD(*M2C_ERROR(/* Read from unset register $r3 */), u8 (**)(), 0x20)() == 0) != 0))) {
                    var_r29_2018 = 1;
                } else {
                    this->unk28 = 0;
                }
            }
        } else {
            this->unk28 = 0;
        }
        this->unk14.SetState(this, var_r29_2018, 1U);
    }
    spC = 0;
    sp8 = 0x17;
    sp10 = 5;
    temp_r3_2100 = this->unk10->unkB70;
    M2C_FIELD(M2C_FIELD(temp_r3_2100, void **, 0x44), M2C_UNK (**)(void *, s32 *), 0x2C)(temp_r3_2100, &sp8);
}
#endif

#if 0 // DRAFT: undefined identifier 'unk14'
void SpyroCombatState::Deinit() {
    this->unk14.Deinit();
}
#endif

#if 0 // DRAFT: undefined identifier 'Init__34KDStateMachine'
void SpyroCombatState::Init(Spyro *arg0) {
    this->unk10 = arg0;
    Init__34KDStateMachine<16SpyroCombatState>FPQ234KDStateMachine<16SpyroCombatState>5StateP34KDStateMachine<16SpyroCombatState>(&this->unk14, (KDStateMachine<SpyroCombatState>::State *) &SpyroCombatState::states, NULL);
    this->unk28 = 0;
    this->unk2C = 0;
    this->unk2D = 0;
    this->unk2E = 0;
    this->unk2F = 0;
    this->unk30 = 0;
    this->unk31 = 0;
    this->unk32 = 0;
    this->unk34 = 0.0f;
    ((CombatStateData *) &this->unk10->unk430.unk28)->SetChargeHitProp(NULL);
}
#endif

void CombatStateData::GetLastTailSweepTarget() {
    ((TargetContext *) &this->unk20.unk8)->Get();
}

void CombatStateData::SetLastTailSweepTarget(Targetable *arg0) {
    ((TargetContext *) &this->unk20.unk8)->Set(arg0);
}

void CombatStateData::IncTailSweepComboCount() {
    this->unk48 += 1;
}

void CombatStateData::SetTailSweepComboCount(int arg0) {
    this->unk48 = arg0;
}

s32 CombatStateData::GetTailSweepComboCount() {
    return this->unk48;
}

s32 CombatStateData::GetCombatArcHitFlags() {
    return this->unk3C;
}

void CombatStateData::SetCombatArcHit(int arg0) {
    this->unk3C |= 1 << arg0;
}

void CombatStateData::ClearCombatArcHitFlags() {
    this->unk3C = 0;
}

void CombatStateData::SetKnockupTime(float arg0) {
    this->unk34 = arg0;
}

u8 CombatStateData::GetHornDiveEnabled() {
    return this->unk53;
}

void CombatStateData::SetHornDiveEnabled(bool arg0) {
    this->unk53 = arg0;
}

u8 CombatStateData::GetTailStrikeEnabled() {
    return this->unk52;
}

void CombatStateData::SetTailStrikeEnabled(bool arg0) {
    this->unk52 = arg0;
}

u8 CombatStateData::GetTailSweepEnabled() {
    return this->unk51;
}

void CombatStateData::SetTailSweepEnabled(bool arg0) {
    this->unk51 = arg0;
}

f32 CombatStateData::GetChargeTime() {
    return this->unk38;
}

void CombatStateData::SetChargeTime(float arg0) {
    this->unk38 = arg0;
}

MKProp *CombatStateData::GetChargeHitProp() {
    return this->unk30;
}

void CombatStateData::SetChargeHitProp(MKProp *arg0) {
    this->unk30 = arg0;
}

u8 CombatStateData::GetHitTarget() {
    return this->unk50;
}

void CombatStateData::SetHitTarget(bool arg0) {
    this->unk50 = arg0;
    if (arg0 != 0) {
        SetCombatArcHit(this->unk44);
    }
}

s32 CombatStateData::GetCombatArc() {
    return this->unk44;
}

void CombatStateData::SetCombatArc(int arg0) {
    this->unk44 = arg0;
}

s32 CombatStateData::GetHitType() {
    return this->unk40;
}

void CombatStateData::SetHitType(int arg0) {
    this->unk40 = arg0;
}

u8 CombatStateData::GetChargeAttackActive() {
    return this->unk4C;
}

u8 CombatStateData::GetTargetDir(MKVector3 *arg0) {
    if (((u8) this->unk4E != 0) && (arg0 != NULL)) {
        M2C_FIELD(arg0, f64 *, 0) = (f64) M2C_FIELD(this, f64 *, 0);
        M2C_FIELD(arg0, f64 *, 8) = (f64) this->unk8;
    }
    return this->unk4E;
}

void CombatStateData::SetTargetDir(bool arg0, const MKVector3 &arg1) {
    this->unk4E = arg0;
    M2C_FIELD(this, f64 *, 0) = (f64) M2C_FIELD(&arg1, f64 *, 0);
    this->unk8 = M2C_FIELD(&arg1, f64 *, 8);
}

void CombatStateData::GetLastCombatEnemy() {
    this->unk20.Get();
}

void CombatStateData::SetLastCombatEnemy(Targetable *arg0) {
    this->unk20.Set(arg0);
}

#if 0 // DRAFT: ambiguous access to overloaded function
void CombatStateData::SetLastCombatEnemy(MKProp *arg0) {
    if ((arg0 == NULL) || !(M2C_FIELD(arg0->unk0, s32 *, 0xC) & 0x208)) {
        this->unk20.Set(NULL);
        return;
    }
    this->unk20.Set(arg0);
}
#endif

void CombatStateData::SetDefaults() {
    this->unk4C = 0;
    this->unk4D = 0;
    this->unk4E = 0;
    this->unk4F = 0;
    this->unk50 = 0;
    this->unk0 = 0.0f;
    this->unk4 = 0.0f;
    M2C_FIELD(this, f32 *, 8) = 0.0f;
    this->unk10 = 0.0f;
    this->unk14 = 0.0f;
    this->unk18 = 0.0f;
    this->unk40 = 0;
    this->unk44 = 2;
}

#if 0 // DRAFT: ambiguous access to overloaded function
void CombatStateData::Init() {
    SetDefaults();
    this->unk51 = 1;
    this->unk52 = 1;
    this->unk53 = 1;
    this->unk34 = 0.0f;
    this->unk3C = 0;
    this->unk20.Set(NULL);
    this->unk38 = 0.0f;
    this->unk48 = 0;
    ((TargetContext *) &this->unk20.unk8)->Set(NULL);
}
#endif

void SpyroCombatState_cpp::__sinit() {
    f32 *temp_r3_2738;
    f64 temp_f0_2777;
    f64 temp_f1_2747;
    f64 temp_f1_2771;
    f64 temp_f3_2733;
    f64 temp_f3_2774;
    f64 temp_f4_2746;
    f64 temp_f4_2768;
    f64 temp_f8_2735;

    temp_f3_2733 = __frsqrte(2014000.0);
    temp_f8_2735 = __frsqrte(380000.0);
    temp_r3_2738 = animSpeedMultiplier + 0xD4;
    temp_f4_2746 = 0.5 * temp_f3_2733 * -((2014000.0 * (temp_f3_2733 * temp_f3_2733)) - 3.0);
    temp_f1_2747 = 0.5 * temp_f8_2735 * -((380000.0 * (temp_f8_2735 * temp_f8_2735)) - 3.0);
    temp_f4_2768 = 0.5 * temp_f4_2746 * -((2014000.0 * (temp_f4_2746 * temp_f4_2746)) - 3.0);
    temp_f1_2771 = 0.5 * temp_f1_2747 * -((380000.0 * (temp_f1_2747 * temp_f1_2747)) - 3.0);
    temp_f3_2774 = temp_f4_2768 * temp_f4_2768;
    temp_f0_2777 = temp_f1_2771 * temp_f1_2771;
    M2C_FIELD(animSpeedMultiplier, s32 *, 0xD4) = (s32) M2C_FIELD(animSpeedMultiplier, s32 *, 0x44);
    M2C_FIELD(animSpeedMultiplier, s32 *, 0xD8) = (s32) M2C_FIELD(animSpeedMultiplier, s32 *, 0x48);
    M2C_FIELD(animSpeedMultiplier, s32 *, 0xDC) = (s32) M2C_FIELD(animSpeedMultiplier, s32 *, 0x4C);
    temp_r3_2738[3] = M2C_FIELD(animSpeedMultiplier, f32 *, 0x50);
    temp_r3_2738[4] = M2C_FIELD(animSpeedMultiplier, f32 *, 0x54);
    temp_r3_2738[5] = M2C_FIELD(animSpeedMultiplier, f32 *, 0x58);
    temp_r3_2738[6] = M2C_FIELD(animSpeedMultiplier, f32 *, 0x5C);
    temp_r3_2738[7] = M2C_FIELD(animSpeedMultiplier, f32 *, 0x60);
    temp_r3_2738[8] = M2C_FIELD(animSpeedMultiplier, f32 *, 0x64);
    temp_r3_2738[9] = M2C_FIELD(animSpeedMultiplier, f32 *, 0x68);
    temp_r3_2738[0xA] = M2C_FIELD(animSpeedMultiplier, f32 *, 0x6C);
    temp_r3_2738[0xB] = M2C_FIELD(animSpeedMultiplier, f32 *, 0x70);
    temp_r3_2738[0xC] = M2C_FIELD(animSpeedMultiplier, f32 *, 0x74);
    temp_r3_2738[0xD] = M2C_FIELD(animSpeedMultiplier, f32 *, 0x78);
    temp_r3_2738[0xE] = M2C_FIELD(animSpeedMultiplier, f32 *, 0x7C);
    temp_r3_2738[0xF] = M2C_FIELD(animSpeedMultiplier, f32 *, 0x80);
    temp_r3_2738[0x10] = M2C_FIELD(animSpeedMultiplier, f32 *, 0x84);
    M2C_FIELD(temp_r3_2738, s32 *, 0x44) = (s32) M2C_FIELD(animSpeedMultiplier, s32 *, 0x88);
    SPYRO_BOUNCE_Y_SPEED = (f32) (2014000.0 * (0.5 * temp_f4_2768 * -((2014000.0 * temp_f3_2774) - 3.0)));
    SPYRO_MIN_JUMP_Y_VELOCITY = (f32) (380000.0 * (0.5 * temp_f1_2771 * -((380000.0 * temp_f0_2777) - 3.0)));
    M2C_FIELD(temp_r3_2738, s32 *, 0x48) = (s32) M2C_FIELD(animSpeedMultiplier, s32 *, 0x8C);
    M2C_FIELD(temp_r3_2738, s32 *, 0x4C) = (s32) M2C_FIELD(animSpeedMultiplier, s32 *, 0x90);
    M2C_FIELD(temp_r3_2738, s32 *, 0x50) = (s32) M2C_FIELD(animSpeedMultiplier, s32 *, 0x94);
    M2C_FIELD(temp_r3_2738, s32 *, 0x54) = (s32) M2C_FIELD(animSpeedMultiplier, s32 *, 0x98);
    M2C_FIELD(temp_r3_2738, s32 *, 0x58) = (s32) M2C_FIELD(animSpeedMultiplier, s32 *, 0x9C);
    M2C_FIELD(temp_r3_2738, s32 *, 0x5C) = (s32) M2C_FIELD(animSpeedMultiplier, s32 *, 0xA0);
    M2C_FIELD(temp_r3_2738, s32 *, 0x60) = (s32) M2C_FIELD(animSpeedMultiplier, s32 *, 0xA4);
    M2C_FIELD(temp_r3_2738, s32 *, 0x64) = (s32) M2C_FIELD(animSpeedMultiplier, s32 *, 0xA8);
    M2C_FIELD(temp_r3_2738, s32 *, 0x68) = (s32) M2C_FIELD(animSpeedMultiplier, s32 *, 0xAC);
    M2C_FIELD(temp_r3_2738, s32 *, 0x6C) = (s32) M2C_FIELD(animSpeedMultiplier, s32 *, 0xB0);
    M2C_FIELD(temp_r3_2738, s32 *, 0x70) = (s32) M2C_FIELD(animSpeedMultiplier, s32 *, 0xB4);
    M2C_FIELD(temp_r3_2738, s32 *, 0x74) = (s32) M2C_FIELD(animSpeedMultiplier, s32 *, 0xB8);
    M2C_FIELD(temp_r3_2738, s32 *, 0x78) = (s32) M2C_FIELD(animSpeedMultiplier, s32 *, 0xBC);
    M2C_FIELD(temp_r3_2738, s32 *, 0x7C) = (s32) M2C_FIELD(animSpeedMultiplier, s32 *, 0xC0);
    M2C_FIELD(temp_r3_2738, s32 *, 0x80) = (s32) M2C_FIELD(animSpeedMultiplier, s32 *, 0xC4);
    M2C_FIELD(temp_r3_2738, s32 *, 0x84) = (s32) M2C_FIELD(animSpeedMultiplier, s32 *, 0xC8);
    M2C_FIELD(temp_r3_2738, s32 *, 0x88) = (s32) M2C_FIELD(animSpeedMultiplier, s32 *, 0xCC);
    M2C_FIELD(temp_r3_2738, s32 *, 0x8C) = (s32) M2C_FIELD(animSpeedMultiplier, s32 *, 0xD0);
    fCometDashTargetArc = _table_sinf(1.8325958f);
}
