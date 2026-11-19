#include "spyro/source/CynderBossGoals.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "spyro/source/AITargetData.h"
#include "spyro/source/Character.h"
#include "spyro/source/CharacterBreathFX.h"
#include "spyro/source/CharacterFireFX.h"
#include "spyro/source/CharacterZapFX.h"
#include "spyro/source/Cynder.h"
#include "spyro/source/CynderBreathFX.h"
#include "spyro/source/EarthShockwave.h"
#include "spyro/source/Enemy.h"
#include "spyro/source/EnemyAttackPattern.h"
#include "spyro/source/EnemyDataTypes.h"
#include "spyro/source/EnemyDescriptor.h"
#include "spyro/source/EventCamera.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/Game.h"
#include "spyro/source/GameData.h"
#include "spyro/source/KDSpline.h"
#include "spyro/source/Spyro.h"
#include "spyro/source/SpyroHud.h"
#include "spyro/source/TargetManager.h"
#include "unplaced_enums.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKInput.h"
#include "common/Source/MKModel.h"
#include "common/Source/StdMath.h"
#include "spyro/source/KDRandom.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/Music.h"
#include "spyro/source/PhrasePlayer.h"
#include <m2c_macros.h>

M2C_UNK free(void *);                               /* extern */
void *malloc(M2C_UNK);                              /* extern */
extern f32 *KDSpline_PositionMixer;
extern f32 *KDSpline_VelocityMixer;
extern f32 SPYRO_BOUNCE_Y_SPEED;
extern f32 SPYRO_MIN_JUMP_Y_VELOCITY;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern GameGlobals gb;

u8 CynderBossGoal_Death::Update() {
    MKProp *temp_r4_17;

    ActivateIfInactive();
    temp_r4_17 = this->unkC;
    ((EventMessage *) (M2C_FIELD(temp_r4_17, s32 *, 0xA44) + 8))->Send(temp_r4_17);
    return this->unk8;
}

#if 0 // DRAFT: undefined identifier 'StopMovement'
void CynderBossGoal_Death::Activate() {
    MKProp *temp_r3_42;
    MKProp *temp_r4_59;
    MKProp *temp_r4_62;

    this->unk8 = 0;
    M2C_FIELD(this->unkC, s8 *, 0xCB0) = 0;
    temp_r3_42 = this->unkC;
    M2C_FIELD(temp_r3_42, u8 *, 0x6B5) = (u8) (M2C_FIELD(temp_r3_42, u8 *, 0x6B5) & ~0x10);
    this->unkC->StopMovement(1U);
    this->unkC->SetMovementType((CharacterMoveType) 2);
    this->unkC->SetAnim((AnimSequenceType) 3, 0x143, 2, 0.15f, 0U, 0U);
    temp_r4_59 = this->unkC;
    ((EventMessage *) (temp_r4_59 + 0xED4))->Send(temp_r4_59);
    temp_r4_62 = this->unkC;
    ((EventMessage *) (M2C_FIELD(temp_r4_62, s32 *, 0xA44) + 8))->Send(temp_r4_62);
    gb.GetSpyro();
    ((Spyro *) (M2C_ERROR(/* Read from unset register $r3 */)))->SetForceLookAtTarget(NULL);
}
#endif

#if 0 // DRAFT: expression syntax error
u8 CynderBossGoal_HoverAttack::Update() {
    CharacterFireFX *temp_r4_117;
    Cynder *temp_r3_116;
    Cynder *temp_r3_302;
    Cynder *temp_r3_96;
    MKAnimScript *temp_r5_313;
    f32 temp_f0_268;
    f32 temp_f5_222;
    f64 temp_f30_271;
    u8 var_r30_97;
    u8 var_r3_318;
    u8 var_r4_312;
    ActivateIfInactive();
    temp_r3_96 = this->unkC;
    var_r30_97 = 0;
    if (((u8) M2C_FIELD(temp_r3_96, u8 *, 0x8B8) == 2) || (temp_r3_96->unk870.unk30.Get() != NULL)) {
        var_r30_97 = 1;
    }
    if ((var_r30_97 != 0) && (((MKAnimScript *) (M2C_FIELD(this->unkC, MKAnimScript **, 0x630)))->CheckEvent(0) != 0)) {
        temp_r3_116 = this->unkC;
        temp_r4_117 = temp_r3_116->unkA08;
        if (temp_r4_117 != NULL) {
            MKModel_GetRefPointMatrix(temp_r3_116->unk4, M2C_FIELD(temp_r4_117, s32 *, 0x84), (Matrix *) &arg_sp1A0, 1U);
            arg_sp90 = -arg_sp1C0;
            arg_sp94 = -arg_sp1C4;
            arg_sp98 = -arg_sp1C8;
            arg_sp190 = (f64) arg_sp90;
            arg_sp198 = (f64) arg_sp98;
            arg_sp180 = arg_sp1D0;
            arg_sp188 = arg_sp1D8;
            arg_sp160.GetPos();
            arg_sp170 = arg_sp160;
            arg_sp178 = arg_sp168;
            arg_sp150.GetVel();
            if (((arg_sp158 * arg_sp158) + ((arg_sp150 * arg_sp150) + (arg_sp154 * arg_sp154))) > 10000.0f) {
                arg_sp120.GetVel();
                arg_sp10 = arg_sp120;
                arg_sp18 = arg_sp128;
                arg_sp14 = 0.0f;
                arg_sp138 = arg_sp128;
                arg_sp130 = arg_sp10;
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
                arg_sp140 = arg_sp40;
                arg_sp48 = (f32) arg_sp138 * 0.75f;
                arg_sp148 = (f64) arg_sp48;
                M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
                arg_sp178 = (f32) arg_sp178 - (f32) arg_sp148;
            }
            KDRand_UnitVectorXZ();
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
            arg_sp110 = arg_sp30;
            arg_sp38 = arg_sp108 * 300.0f;
            arg_sp118 = (f64) arg_sp38;
            M2C_ERROR(/* unknown instruction: ps_add $f6, $f1, $f0 */);
            arg_sp68 = 0.0f;
            temp_f5_222 = (f32) arg_sp178 + (f32) arg_sp118;
            arg_sp60 = 0.0f;
            arg_sp64 = 600.0f;
            arg_sp178 = temp_f5_222;
            arg_spC0 = (f64) arg_sp60;
            arg_spC8 = (f64) arg_sp68;
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f6, $f0 */);
            arg_sp88 = 0.0f;
            arg_sp58 = temp_f5_222 - (f32) arg_spC8;
            arg_sp80 = 0.0f;
            arg_sp84 = 100.0f;
            arg_spD0 = arg_sp50;
            arg_spE0 = (f64) arg_sp80;
            arg_spD8 = (f64) arg_sp58;
            arg_spE8 = (f64) arg_sp88;
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f6, $f0 */);
            arg_spF0 = arg_sp70;
            arg_sp78 = temp_f5_222 + (f32) arg_spE8;
            arg_spF8 = (f64) arg_sp78;
            if (MKCollision_RayCollide(*((MKVector3 *) &arg_spF0), *((MKVector3 *) &arg_spD0), (MKCollisionResult *) &arg_sp1E0, (MKCollisionMode) 7, 0x0C000000) != 0) {
                temp_f0_268 = arg_sp174 - arg_sp1E4;
                arg_sp174 = arg_sp1E4;
                temp_f30_271 = fabs(temp_f0_268);
                arg_spA0.GetDir();
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
                arg_spB0 = arg_sp20;
                arg_sp28 = arg_spA8 * (f32) temp_f30_271;
                arg_spB8 = (f64) arg_sp28;
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                arg_sp178 = (f32) arg_sp178 + (f32) arg_spB8;
            }
            this->unkC->ShootFireBomb(*((MKVector3 *) &arg_sp180), *((MKVector3 *) &arg_sp190), *((MKVector3 *) &arg_sp170));
        }
    }
    temp_r3_302 = this->unkC;
    M2C_FIELD(temp_r3_302, f64 *, 0x598) = (f64) M2C_FIELD(temp_r3_302, f64 *, 0x90);
    M2C_FIELD(temp_r3_302, f64 *, 0x5A0) = (f64) M2C_FIELD(temp_r3_302, f64 *, 0x98);
    if (this->unkC->HasAnimFinished() == 0) {
        var_r4_312 = 0;
        temp_r5_313 = M2C_FIELD(this->unkC, MKAnimScript **, 0x630);
        if (((u32) temp_r5_313->unk2C >> 1U) & 1) {
            var_r3_318 = 0;
            if ((temp_r5_313->unk38 > 0.0f) || ((s32) temp_r5_313->unk44 > 1)) {
                var_r3_318 = 1;
            }
            if (var_r3_318 != 0) {
                var_r4_312 = 1;
            }
        }
        if (var_r4_312 != 0) {
            goto block_19;
        }
    } else {
block_19:
        this->unk8 = 2;
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: undefined identifier 'unkCB0'
void CynderBossGoal_HoverAttack::Activate() {
    Cynder *temp_r3_367;
    Cynder *temp_r3_382;
    void *temp_r4_386;

    this->unk8 = 0;
    this->unkC->unkCB0 = 1;
    temp_r3_367 = this->unkC;
    temp_r3_367->unk6B5 |= 0x10;
    this->unkC->StopMovement(1U);
    this->unkC->SetMovementType((CharacterMoveType) 2);
    if (this->unkC->SelectAttack(0x10, 0x49) != 0) {
        temp_r3_382 = this->unkC;
        temp_r4_386 = temp_r3_382->unkA08->__vptr;
        temp_r3_382->SetAnim((AnimSequence *) temp_r4_386, (AnimTransition *) temp_r4_386, 0.15f, 0U);
    }
}
#endif

u8 CynderBossGoal_HoverRight::Update() {
    Character *temp_r3_406;
    u8 var_r3_418;
    u8 var_r4_407;
    void *temp_r5_413;

    ActivateIfInactive();
    temp_r3_406 = this->unkC;
    var_r4_407 = 0;
    M2C_FIELD(temp_r3_406, f64 *, 0x598) = (f64) M2C_FIELD(temp_r3_406, f64 *, 0x90);
    M2C_FIELD(temp_r3_406, f64 *, 0x5A0) = (f64) M2C_FIELD(temp_r3_406, f64 *, 0x98);
    temp_r5_413 = M2C_FIELD(this->unkC, void **, 0x630);
    if (((u32) M2C_FIELD(temp_r5_413, u32 *, 0x2C) >> 1U) & 1) {
        var_r3_418 = 0;
        if ((M2C_FIELD(temp_r5_413, f32 *, 0x38) > 0.0f) || ((s32) M2C_FIELD(temp_r5_413, s32 *, 0x44) > 1)) {
            var_r3_418 = 1;
        }
        if (var_r3_418 != 0) {
            var_r4_407 = 1;
        }
    }
    if (var_r4_407 != 0) {
        this->unk8 = 2;
    }
    return this->unk8;
}

#if 0 // DRAFT: illegal implicit conversion from 'AnimSequenceType' to
void CynderBossGoal_HoverRight::Activate() {
    Character *temp_r3_457;

    this->unk8 = 0;
    temp_r3_457 = this->unkC;
    temp_r3_457->unk6B5 |= 0x10;
    this->unkC->StopMovement(1U);
    this->unkC->SetMovementType((CharacterMoveType) 2);
    this->unkC->SetAnim((AnimSequenceType) 0xA, 0xE6, 0, 0.15f, 0U, 0U);
}
#endif

u8 CynderBossGoal_HoverLeft::Update() {
    Character *temp_r3_490;
    u8 var_r3_502;
    u8 var_r4_491;
    void *temp_r5_497;

    ActivateIfInactive();
    temp_r3_490 = this->unkC;
    var_r4_491 = 0;
    M2C_FIELD(temp_r3_490, f64 *, 0x598) = (f64) M2C_FIELD(temp_r3_490, f64 *, 0x90);
    M2C_FIELD(temp_r3_490, f64 *, 0x5A0) = (f64) M2C_FIELD(temp_r3_490, f64 *, 0x98);
    temp_r5_497 = M2C_FIELD(this->unkC, void **, 0x630);
    if (((u32) M2C_FIELD(temp_r5_497, u32 *, 0x2C) >> 1U) & 1) {
        var_r3_502 = 0;
        if ((M2C_FIELD(temp_r5_497, f32 *, 0x38) > 0.0f) || ((s32) M2C_FIELD(temp_r5_497, s32 *, 0x44) > 1)) {
            var_r3_502 = 1;
        }
        if (var_r3_502 != 0) {
            var_r4_491 = 1;
        }
    }
    if (var_r4_491 != 0) {
        this->unk8 = 2;
    }
    return this->unk8;
}

#if 0 // DRAFT: illegal implicit conversion from 'AnimSequenceType' to
void CynderBossGoal_HoverLeft::Activate() {
    Character *temp_r3_541;

    this->unk8 = 0;
    temp_r3_541 = this->unkC;
    temp_r3_541->unk6B5 |= 0x10;
    this->unkC->StopMovement(1U);
    this->unkC->SetMovementType((CharacterMoveType) 2);
    this->unkC->SetAnim((AnimSequenceType) 0xA, 0xE5, 0, 0.15f, 0U, 0U);
}
#endif

u8 CynderBossGoal_Hover::Update() {
    Character *temp_r3_574;
    u8 var_r3_586;
    u8 var_r4_575;
    void *temp_r5_581;

    ActivateIfInactive();
    temp_r3_574 = this->unkC;
    var_r4_575 = 0;
    M2C_FIELD(temp_r3_574, f64 *, 0x598) = (f64) M2C_FIELD(temp_r3_574, f64 *, 0x90);
    M2C_FIELD(temp_r3_574, f64 *, 0x5A0) = (f64) M2C_FIELD(temp_r3_574, f64 *, 0x98);
    temp_r5_581 = M2C_FIELD(this->unkC, void **, 0x630);
    if (((u32) M2C_FIELD(temp_r5_581, u32 *, 0x2C) >> 1U) & 1) {
        var_r3_586 = 0;
        if ((M2C_FIELD(temp_r5_581, f32 *, 0x38) > 0.0f) || ((s32) M2C_FIELD(temp_r5_581, s32 *, 0x44) > 1)) {
            var_r3_586 = 1;
        }
        if (var_r3_586 != 0) {
            var_r4_575 = 1;
        }
    }
    if (var_r4_575 != 0) {
        this->unk8 = 2;
    }
    return this->unk8;
}

#if 0 // DRAFT: illegal implicit conversion from 'AnimSequenceType' to
void CynderBossGoal_Hover::Activate() {
    Character *temp_r3_625;

    this->unk8 = 0;
    temp_r3_625 = this->unkC;
    temp_r3_625->unk6B5 |= 0x10;
    this->unkC->StopMovement(1U);
    this->unkC->SetMovementType((CharacterMoveType) 2);
    this->unkC->SetAnim((AnimSequenceType) 0xA, 0xE3, 0, 0.15f, 0U, 0U);
}
#endif

void CynderBossGoal_HoverAttackMode::Reset() {
    this->unk8 = 1;
    RemoveAllSubgoals();
    this->unk20 = 0;
    this->unk38 = 0;
    this->unk34 = 1;
    this->unk3C = 0;
}

void CynderBossGoal_HoverAttackMode::Terminate() {
    this->unk8 = 1;
    RemoveAllSubgoals();
}

#if 0 // DRAFT: illegal implicit conversion from 'void' to
u8 CynderBossGoal_HoverAttackMode::Update() {
    Cynder *temp_r3_712;
    Cynder *temp_r3_729;
    Cynder *temp_r3_738;

    ActivateIfInactive();
    this->unk8 = UpdateSubgoals();
    if ((u8) this->unk8 == 2) {
        Activate();
    }
    if ((u8) this->unk3C == 0) {
        temp_r3_712 = this->unkC;
        if ((u8) M2C_FIELD(temp_r3_712, u8 *, 0xF1E) == 0) {
            M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
            if (temp_r3_712->unkAB0 == 0.0f) {
                temp_r3_712->TriggerFuryPowerUp(15.0f, (HeroHurtReactionType) 9);
                this->unk3C = 1;
                M2C_FIELD(this->unkC, u8 *, 0xF1E) = 1U;
            }
        }
    }
    temp_r3_729 = this->unkC;
    if (((u8) M2C_FIELD(temp_r3_729, u8 *, 0xF20) != 0) && ((u8) M2C_FIELD(temp_r3_729, u8 *, 0xF1F) != 0)) {
        temp_r3_729->ResetFury();
    }
    temp_r3_738 = this->unkC;
    if ((((u8) M2C_FIELD(temp_r3_738, u8 *, 0xF1E) != 0) && ((u8) this->unk3C != 0) && (M2C_ERROR(/* unknown instruction: cror eq, lt, eq */), ((temp_r3_738->unkF70 == 0.0f) != 0))) || ((u8) M2C_FIELD(temp_r3_738, u8 *, 0xF1D) != 0)) {
        this->unk8 = 2;
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: expression syntax error
void CynderBossGoal_HoverAttackMode::Activate() {
    Cynder *temp_r3_779;
    s32 temp_r0_855;
    s32 temp_r3_815;
    s32 temp_r3_827;
    s32 temp_r3_845;
    u8 temp_r0_812;
    u8 var_r30_787;

    this->unk8 = 0;
    this->unkC->unkCFC = 0;
    RemoveAllSubgoals();
    temp_r3_779 = this->unkC;
    if (((u8) M2C_FIELD(temp_r3_779, u8 *, 0xF1E) == 0) && ((u8) this->unk3C == 0)) {
        var_r30_787 = 0;
        if (((u8) M2C_FIELD(temp_r3_779, u8 *, 0x8B8) == 2) || (temp_r3_779->unk870.unk30.Get() != NULL)) {
            var_r30_787 = 1;
        }
        if ((var_r30_787 == 0) || ((gb.GetSpyro(), (((u32) M2C_ERROR(/* Read from unset register $r3 */) == 0U) == 0)) && (gb.GetSpyro(), (((s32) M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x5C) == 9) != 0)))) {
            goto block_8;
        }
        temp_r3_845 = this->unk34;
        if (temp_r3_845 > 0) {
            this->unk34 = temp_r3_845 - 1;
            AddSubgoal__22CompositeGoal<6Cynder>FP13Goal<6Cynder>((CompositeGoal<Cynder> *) this, (Goal<Cynder> *) this->unk24);
            return;
        }
        temp_r0_855 = this->unk38;
        if ((temp_r0_855 >= -1) && (temp_r0_855 <= 1)) {
            if (MKRand_Float(&gViewSeed, 0.0f, 1.0f) > 0.5f) {
                this->unk38 -= 1;
                AddSubgoal__22CompositeGoal<6Cynder>FP13Goal<6Cynder>((CompositeGoal<Cynder> *) this, (Goal<Cynder> *) this->unk28);
                AddSubgoal__22CompositeGoal<6Cynder>FP13Goal<6Cynder>((CompositeGoal<Cynder> *) this, (Goal<Cynder> *) this->unk30);
            } else {
                this->unk38 += 1;
                AddSubgoal__22CompositeGoal<6Cynder>FP13Goal<6Cynder>((CompositeGoal<Cynder> *) this, (Goal<Cynder> *) this->unk2C);
                AddSubgoal__22CompositeGoal<6Cynder>FP13Goal<6Cynder>((CompositeGoal<Cynder> *) this, (Goal<Cynder> *) this->unk30);
            }
        } else if (temp_r0_855 >= -1) {
            this->unk38 -= 1;
            AddSubgoal__22CompositeGoal<6Cynder>FP13Goal<6Cynder>((CompositeGoal<Cynder> *) this, (Goal<Cynder> *) this->unk28);
            AddSubgoal__22CompositeGoal<6Cynder>FP13Goal<6Cynder>((CompositeGoal<Cynder> *) this, (Goal<Cynder> *) this->unk30);
        } else {
            this->unk38 += 1;
            AddSubgoal__22CompositeGoal<6Cynder>FP13Goal<6Cynder>((CompositeGoal<Cynder> *) this, (Goal<Cynder> *) this->unk2C);
            AddSubgoal__22CompositeGoal<6Cynder>FP13Goal<6Cynder>((CompositeGoal<Cynder> *) this, (Goal<Cynder> *) this->unk30);
        }
        AddSubgoal__22CompositeGoal<6Cynder>FP13Goal<6Cynder>((CompositeGoal<Cynder> *) this, (Goal<Cynder> *) this->unk24);
        AddSubgoal__22CompositeGoal<6Cynder>FP13Goal<6Cynder>((CompositeGoal<Cynder> *) this, (Goal<Cynder> *) this->unk30);
        return;
    }
block_8:
    temp_r0_812 = M2C_FIELD(this->unkC, u8 *, 0xF1E);
    if ((temp_r0_812 != 0) && (temp_r3_815 = this->unk38, ((temp_r3_815 > 0) != 0))) {
        this->unk38 = temp_r3_815 - 1;
        AddSubgoal__22CompositeGoal<6Cynder>FP13Goal<6Cynder>((CompositeGoal<Cynder> *) this, (Goal<Cynder> *) this->unk28);
    } else if ((temp_r0_812 != 0) && (temp_r3_827 = this->unk38, ((temp_r3_827 < 0) != 0))) {
        this->unk38 = temp_r3_827 + 1;
        AddSubgoal__22CompositeGoal<6Cynder>FP13Goal<6Cynder>((CompositeGoal<Cynder> *) this, (Goal<Cynder> *) this->unk2C);
    } else {
        AddSubgoal__22CompositeGoal<6Cynder>FP13Goal<6Cynder>((CompositeGoal<Cynder> *) this, (Goal<Cynder> *) this->unk24);
    }
    this->unk34 = 0;
}
#endif

void CynderBossGoal_HoverAttackMode::Deinit() {
    Goal<Cynder> *temp_r3_934;
    Goal<Cynder> *temp_r3_939;
    Goal<Cynder> *temp_r3_944;
    Goal<Cynder> *temp_r3_949;
    MKHeap *temp_r3_965;
    void *temp_r31_962;

    temp_r3_934 = this->unk24;
    temp_r3_934->Deinit();
    temp_r3_939 = this->unk28;
    temp_r3_939->Deinit();
    temp_r3_944 = this->unk2C;
    temp_r3_944->Deinit();
    temp_r3_949 = this->unk30;
    temp_r3_949->Deinit();
    operator delete(this->unk24);
    operator delete(this->unk28);
    operator delete(this->unk2C);
    operator delete(this->unk30);
    temp_r31_962 = this->unk1C;
    if (temp_r31_962 != NULL) {
        temp_r3_965 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_965 != NULL) {
            ((MKHeap *) (temp_r3_965->Current()))->Free(temp_r31_962, NULL, 0);
        } else {
            free(temp_r31_962);
        }
        this->unk1C = NULL;
    }
    this->unk10 = 0;
    this->unk18 = 0;
    this->unk14 = 0;
    this->unk8 = 1;
    this->unkC = NULL;
    this->unk9 = 0;
}

#if 0 // DRAFT: pointer/array required
void CynderBossGoal_HoverAttackMode::Init(Cynder *arg0) {
    Goal<Cynder> *temp_r4_1119;
    Goal<Cynder> *temp_r4_1130;
    Goal<Cynder> *temp_r4_1141;
    Goal<Cynder> *temp_r4_1152;
    MKHeap *temp_r3_1092;
    void *var_r3_1099;

    if ((u8) this->unk9 == 0) {
        operator new(0x10U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__13Goal<6Cynder>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk24 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x10U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__13Goal<6Cynder>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk28 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x10U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__13Goal<6Cynder>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk2C = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x10U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__13Goal<6Cynder>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk30 = M2C_ERROR(/* Read from unset register $r3 */);
    }
    if ((u8) this->unk9 == 0) {
        temp_r3_1092 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_1092 != NULL) {
            var_r3_1099 = ((MKHeap *) (temp_r3_1092->Current()))->Alloc(0x18, NULL, 0);
        } else {
            var_r3_1099 = malloc(0x18);
        }
        this->unk1C = var_r3_1099;
        this->unk10 = 6;
    }
    this->unk8 = 1;
    this->unkC = arg0;
    this->unk4 = 0xBA;
    if ((Cynder *) this->unkC != NULL) {
        this->unk9 = 1;
    }
    temp_r4_1119 = this->unk24;
    M2C_FIELD(temp_r4_1119, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_1119, Cynder **, 0xC) = arg0;
    M2C_FIELD(temp_r4_1119, s32 *, 4) = 0xB5;
    if ((Cynder *) M2C_FIELD(temp_r4_1119, Cynder **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_1119, s8 *, 9) = 1;
    }
    temp_r4_1130 = this->unk28;
    M2C_FIELD(temp_r4_1130, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_1130, Cynder **, 0xC) = arg0;
    M2C_FIELD(temp_r4_1130, s32 *, 4) = 0xB7;
    if ((Cynder *) M2C_FIELD(temp_r4_1130, Cynder **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_1130, s8 *, 9) = 1;
    }
    temp_r4_1141 = this->unk2C;
    M2C_FIELD(temp_r4_1141, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_1141, Cynder **, 0xC) = arg0;
    M2C_FIELD(temp_r4_1141, s32 *, 4) = 0xB7;
    if ((Cynder *) M2C_FIELD(temp_r4_1141, Cynder **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_1141, s8 *, 9) = 1;
    }
    temp_r4_1152 = this->unk30;
    M2C_FIELD(temp_r4_1152, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_1152, Cynder **, 0xC) = arg0;
    M2C_FIELD(temp_r4_1152, s32 *, 4) = 0xB6;
    if ((Cynder *) M2C_FIELD(temp_r4_1152, Cynder **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_1152, s8 *, 9) = 1;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unkA50'
u8 CynderBossGoal_HitByFury::Update() {
    MKCollisionResult sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp10;
    Character *temp_r29_1247;
    Character *temp_r29_1275;
    Character *temp_r3_1182;
    Character *temp_r4_1228;
    Character *temp_r7_1191;
    u32 *temp_r4_1193;
    u32 *temp_r4_1253;
    u32 *temp_r4_1277;
    u32 *temp_r4_1313;
    u8 var_r30_1248;
    u8 var_r30_1309;
    u8 var_r5_1192;
    u8 var_r5_1276;

    ActivateIfInactive();
    if ((u8) this->unk10 == 0) {
        temp_r3_1182 = this->unkC;
        M2C_FIELD(temp_r3_1182, f64 *, 0x598) = (f64) M2C_FIELD(temp_r3_1182, f64 *, 0x90);
        M2C_FIELD(temp_r3_1182, f64 *, 0x5A0) = (f64) M2C_FIELD(temp_r3_1182, f64 *, 0x98);
    }
    if ((u8) this->unk10 == 0) {
        temp_r7_1191 = this->unkC;
        var_r5_1192 = 0;
        temp_r4_1193 = temp_r7_1191->unkA50;
        if ((temp_r4_1193 != NULL) && ((u32) M2C_FIELD(temp_r4_1193, u32 *, 0x40) == (u32) M2C_FIELD(M2C_FIELD(temp_r7_1191, void **, 0x630), u32 *, 0x20))) {
            var_r5_1192 = 1;
        }
        if (var_r5_1192 != 0) {
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r3, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r6, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            sp38 = sp18;
            sp20 = temp_r7_1191->unk588.unk4 + temp_r7_1191->unk59C;
            sp40 = (f64) sp20;
            if (MKCollision_RayCollide(*((MKVector3 *) &this->unkC->unk588), *((MKVector3 *) &sp38), &sp48, (MKCollisionMode) 4, 0) != 0) {
                temp_r4_1228 = this->unkC;
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r3, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
                M2C_FIELD(temp_r4_1228, f64 *, 0x598) = sp8;
                sp10 = sp48.unk8 - temp_r4_1228->unk588.unk4;
                sp28 = sp8;
                M2C_FIELD(temp_r4_1228, f64 *, 0x5A0) = (f64) sp10;
                sp30 = (f64) sp10;
                this->unk10 = 1;
            }
        }
    }
    temp_r29_1247 = this->unkC;
    var_r30_1248 = 0;
    if (temp_r29_1247->HasAnimFinished() != 0) {
        temp_r4_1253 = temp_r29_1247->unkA50;
        if ((temp_r4_1253 != NULL) && ((u32) *temp_r4_1253 == (u32) M2C_FIELD(M2C_FIELD(temp_r29_1247, void **, 0x630), u32 *, 0x20))) {
            var_r30_1248 = 1;
        }
    }
    if (var_r30_1248 != 0) {
        this->unkC->SetAnim((AnimSequenceType) 3, 0x143, 1, 0.15f, 0U, 0U);
    } else {
        temp_r29_1275 = this->unkC;
        var_r5_1276 = 0;
        temp_r4_1277 = temp_r29_1275->unkA50;
        if ((temp_r4_1277 != NULL) && ((u32) M2C_FIELD(temp_r4_1277, u32 *, 0x20) == (u32) M2C_FIELD(M2C_FIELD(temp_r29_1275, void **, 0x630), u32 *, 0x20))) {
            var_r5_1276 = 1;
        }
        if ((var_r5_1276 != 0) && ((u8) gb.unk381 == 0)) {
            temp_r29_1275->SetAnim((AnimSequenceType) 3, 0x143, 2, 0.15f, 0U, 0U);
            ((EventMessage *) (this->unkC + 0xF08))->Send(NULL);
        } else {
            var_r30_1309 = 0;
            if (temp_r29_1275->HasAnimFinished() != 0) {
                temp_r4_1313 = temp_r29_1275->unkA50;
                if ((temp_r4_1313 != NULL) && ((u32) M2C_FIELD(temp_r4_1313, u32 *, 0x40) == (u32) M2C_FIELD(M2C_FIELD(temp_r29_1275, void **, 0x630), u32 *, 0x20))) {
                    var_r30_1309 = 1;
                }
            }
            if (var_r30_1309 != 0) {
                ((EventMessage *) (this->unkC + 0xF0C))->Send(NULL);
                this->unk8 = 2;
            }
        }
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'AnimSequenceType' to
void CynderBossGoal_HitByFury::Activate() {
    Character *temp_r3_1352;

    this->unk8 = 0;
    temp_r3_1352 = this->unkC;
    temp_r3_1352->unk6B5 |= 0x10;
    this->unkC->StopMovement(1U);
    this->unkC->SetMovementType((CharacterMoveType) 2);
    this->unkC->SetAnim((AnimSequenceType) 3, 0x143, 0, 0.15f, 0U, 0U);
    ((EventMessage *) (this->unkC + 0xF04))->Send(NULL);
    this->unk10 = 0;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'AnimSequenceType' to
u8 CynderBossGoal_Stage3Fury::Update() {
    Character *temp_r3_1391;

    ActivateIfInactive();
    temp_r3_1391 = this->unkC;
    M2C_FIELD(temp_r3_1391, f64 *, 0x598) = (f64) M2C_FIELD(temp_r3_1391, f64 *, 0x90);
    M2C_FIELD(temp_r3_1391, f64 *, 0x5A0) = (f64) M2C_FIELD(temp_r3_1391, f64 *, 0x98);
    if (this->unkC->HasAnimFinished() != 0) {
        if ((u8) this->unk10 != 0) {
            this->unkC->SetAnim((AnimSequenceType) 0xA, 0x142, 0, 0.15f, 0U, 0U);
            this->unk10 = 0;
            this->unkC->TriggerFury();
            ((EventMessage *) (this->unkC + 0xEF0))->Send(NULL);
        } else {
            ((EventMessage *) (this->unkC + 0xEF4))->Send(NULL);
            this->unk8 = 2;
        }
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'AnimSequenceType' to
void CynderBossGoal_Stage3Fury::Activate() {
    Character *temp_r3_1449;

    this->unk8 = 0;
    this->unk10 = 1;
    temp_r3_1449 = this->unkC;
    temp_r3_1449->unk6B5 |= 0x10;
    this->unkC->StopMovement(1U);
    this->unkC->SetMovementType((CharacterMoveType) 2);
    this->unkC->SetAnim((AnimSequenceType) 0xA, 0x141, 0, 0.15f, 0U, 0U);
    ((Stat *) ((Stat *) &GameData::gameData[0xB8]))->SetValue(0.0f, 1U);
    ((EventMessage *) (this->unkC + 0xEEC))->Send(NULL);
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void CynderBossGoal_Stage2Fury::Terminate() {
    s32 spC;
    s32 sp8;
    EventCamera *temp_r3_1494;

    this->unk8 = 1;
    if (EventCamera_GetCurrent() != NULL) {
        temp_r3_1494 = EventCamera_GetCurrent();
        spC = 0;
        sp8 = 0xB4;
        M2C_FIELD(temp_r3_1494->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp8);
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'AnimSequenceType' to
u8 CynderBossGoal_Stage2Fury::Update() {
    EnemyHudData sp10;
    s32 spC;
    s32 sp8;
    Character *temp_r3_1520;
    EventCamera *temp_r3_1612;
    s32 temp_r0_1532;

    ActivateIfInactive();
    temp_r3_1520 = this->unkC;
    M2C_FIELD(temp_r3_1520, f64 *, 0x598) = (f64) M2C_FIELD(temp_r3_1520, f64 *, 0x90);
    M2C_FIELD(temp_r3_1520, f64 *, 0x5A0) = (f64) M2C_FIELD(temp_r3_1520, f64 *, 0x98);
    if (this->unkC->HasAnimFinished() != 0) {
        this->unk10 += 1;
        temp_r0_1532 = this->unk10;
        switch (temp_r0_1532) {                     /* irregular */
        case 1:
            this->unkC->SetAnim((AnimSequenceType) 1, 4, 0, 0.15f, 0U, 0U);
            this->unkC->TriggerFuryPowerUp(5.0f, (HeroHurtReactionType) 8);
            this->unkC->GetMaxHealth();
            this->unkC->SetHealth(M2C_ERROR(/* Read from unset register $f1 */));
            sp10.EnemyHudData();
            this->unkC->GetMaxHealth();
            sp10.Init((Enemy *) this->unkC, 0.0f, M2C_ERROR(/* Read from unset register $f1 */));
            EnemyHud_Modified(sp10);
            ((EventMessage *) (this->unkC + 0xEDC))->Send(NULL);
            break;
        case 2:
            this->unkC->SetAnim((AnimSequenceType) 0xA, 0x140, 0, 0.15f, 0U, 0U);
            ((EventMessage *) (this->unkC + 0xEE0))->Send(NULL);
            break;
        case 3:
            this->unkC->SetAnim((AnimSequenceType) 0xA, 0x142, 0, 0.15f, 0U, 0U);
            this->unkC->TriggerFury();
            ((EventMessage *) (this->unkC + 0xEE4))->Send(NULL);
            break;
        default:
            this->unk8 = 2;
            if (EventCamera_GetCurrent() != NULL) {
                temp_r3_1612 = EventCamera_GetCurrent();
                spC = 0;
                sp8 = 0xB4;
                M2C_FIELD(temp_r3_1612->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp8);
            }
            ((EventMessage *) (this->unkC + 0xEE8))->Send(NULL);
            break;
        }
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: undefined identifier 'SetHealth'
void CynderBossGoal_Stage2Fury::Activate() {
    Character *temp_r3_1648;

    this->unk8 = 0;
    temp_r3_1648 = this->unkC;
    temp_r3_1648->unk6B5 |= 0x10;
    this->unkC->StopMovement(1U);
    this->unkC->SetMovementType((CharacterMoveType) 2);
    this->unkC->SetHealth(0.0f);
    gb.GetSpyro();
    ((Spyro *) (M2C_ERROR(/* Read from unset register $r3 */)))->SetForceLookAtTarget((MKProp *) this->unkC);
    this->unk10 = 0;
    this->unkC->SetAnim((AnimSequenceType) 1, 0xA0, 0, 0.15f, 0U, 0U);
    ((EventMessage *) (this->unkC + 0xED8))->Send(NULL);
}
#endif

void CynderGoal_FlyingAttackMode::Reset() {
    this->unk8 = 1;
    RemoveAllSubgoals();
    this->unk40 = 0;
    this->unk20 = 0;
    this->unk3C = 0;
}

#if 0 // DRAFT: expression syntax error
void CynderGoal_FlyingAttackMode::Terminate() {
    Cynder *temp_r3_1719;
    u8 var_r31_1720;

    this->unk8 = 1;
    RemoveAllSubgoals();
    temp_r3_1719 = this->unkC;
    var_r31_1720 = 0;
    if (((u8) M2C_FIELD(temp_r3_1719, u8 *, 0x8B8) == 2) || (temp_r3_1719->unk870.unk30.Get() != NULL)) {
        var_r31_1720 = 1;
    }
    if (var_r31_1720 != 0) {
        this->unkC->unkEFC.unk0 = gb.unk30C + 30.0f;
        return;
    }
    this->unkC->unkEFC.unk0 = 0.0f;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void' to
u8 CynderGoal_FlyingAttackMode::Update() {
    Cynder *temp_r3_1770;
    Cynder *temp_r4_1804;
    CynderBossGoal_FlyAlongSpline *temp_r5_1779;
    CynderBossGoal_FlyAlongSpline *temp_r5_1819;
    s32 temp_r0_1789;

    ActivateIfInactive();
    this->unk8 = UpdateSubgoals();
    if ((s32) this->unk3C != 3) {

    } else {
        temp_r3_1770 = this->unkC;
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if (temp_r3_1770->unkAB0 == 0.0f) {
            temp_r3_1770->CalcLandingFlightPathData();
            temp_r5_1779 = this->unk30;
            temp_r5_1779->unk18 = this->unkC->unkFF8;
            temp_r5_1779->unk24 |= 0x80;
            this->unk3C = 4;
        } else {
            temp_r0_1789 = temp_r3_1770->unkCFC;
            if ((temp_r0_1789 < 2) && (M2C_ERROR(/* unknown instruction: cror eq, gt, eq */), ((gb.unk30C == temp_r3_1770->unkA7C) != 0))) {
                temp_r3_1770->unkA7C = gb.unk30C + 10.0f;
                this->unk30->PerformBreathAttack();
                temp_r4_1804 = this->unkC;
                temp_r4_1804->unkCFC += 1;
            } else if ((temp_r0_1789 >= 2) && !(((u8) this->unk30->unk24 >> 5U) & 1)) {
                temp_r3_1770->CalcLandingFlightPathData();
                temp_r5_1819 = this->unk30;
                temp_r5_1819->unk18 = this->unkC->unkFF8;
                temp_r5_1819->unk24 |= 0x80;
                this->unk3C = 4;
            }
        }
    }
    if ((u8) this->unk8 != 0) {
        if ((s32) this->unk3C == 6) {
            M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
            if (this->unkC->unkAB0 == 0.0f) {
                this->unk8 = 3;
            }
        } else {
            Activate();
        }
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: undefined identifier 'AddSubgoal__22CompositeGoal'
void CynderGoal_FlyingAttackMode::Activate() {
    Cynder *temp_r5_1910;
    Cynder *temp_r6_1920;
    CynderBossGoal_FlyAlongSpline *temp_r5_1922;
    EnemyDescriptor *temp_r3_1892;
    Goal<Cynder> *temp_r3_1911;
    Goal<Cynder> *temp_r5_1943;
    s32 temp_r0_1873;

    this->unk8 = 0;
    this->unkC->unkCFC = 0;
    this->unk3C += 1;
    temp_r0_1873 = this->unk3C;
    switch (temp_r0_1873) {                         /* irregular */
    case 1:
        this->unkC->CalcFlightPathData2();
        temp_r3_1892 = this->unkC->unkA38;
        if ((temp_r3_1892 != NULL) && ((s32) temp_r3_1892->unk6C == 6)) {
            AddSubgoal__22CompositeGoal<6Cynder>FP13Goal<6Cynder>((CompositeGoal<Cynder> *) this, (Goal<Cynder> *) this->unk24);
            return;
        }
        AddSubgoal__22CompositeGoal<6Cynder>FP13Goal<6Cynder>((CompositeGoal<Cynder> *) this, (Goal<Cynder> *) this->unk28);
        return;
    case 2:
        AddSubgoal__22CompositeGoal<6Cynder>FP13Goal<6Cynder>((CompositeGoal<Cynder> *) this, (Goal<Cynder> *) this->unk2C);
        temp_r5_1910 = this->unkC;
        temp_r3_1911 = this->unk2C;
        M2C_FIELD(temp_r3_1911, f32 **, 0x10) = &temp_r5_1910->unkF88;
        M2C_FIELD(temp_r3_1911, s32 *, 0x14) = (s32) temp_r5_1910->unkFFC;
        return;
    case 3:
        AddSubgoal__22CompositeGoal<6Cynder>FP13Goal<6Cynder>((CompositeGoal<Cynder> *) this, (Goal<Cynder> *) this->unk30);
        temp_r6_1920 = this->unkC;
        temp_r5_1922 = this->unk30;
        temp_r5_1922->unk10 = temp_r6_1920->unkFF0;
        temp_r5_1922->unk14 = temp_r6_1920->unkFF4;
        temp_r5_1922->unk24 &= ~0x40;
        this->unkC->unkA7C = gb.unk30C + 1.0f;
        return;
    case 5:
        AddSubgoal__22CompositeGoal<6Cynder>FP13Goal<6Cynder>((CompositeGoal<Cynder> *) this, (Goal<Cynder> *) this->unk34);
        temp_r5_1943 = this->unk34;
        M2C_FIELD(temp_r5_1943, f32 **, 0x10) = &this->unkC->unkCD4;
        M2C_FIELD(temp_r5_1943, f32 *, 0x14) = 0.0f;
        M2C_FIELD(temp_r5_1943, u8 *, 0x24) = (u8) (M2C_FIELD(temp_r5_1943, u8 *, 0x24) | 0x40);
        return;
    case 6:
        AddSubgoal__22CompositeGoal<6Cynder>FP13Goal<6Cynder>((CompositeGoal<Cynder> *) this, (Goal<Cynder> *) this->unk38);
        /* fallthrough */
        return;
    }
}
#endif

void CynderGoal_FlyingAttackMode::Deinit() {
    CynderBossGoal_FlyAlongSpline *temp_r3_1986;
    Goal<Cynder> *temp_r3_1971;
    Goal<Cynder> *temp_r3_1976;
    Goal<Cynder> *temp_r3_1981;
    Goal<Cynder> *temp_r3_1991;
    Goal<Cynder> *temp_r3_1996;
    MKHeap *temp_r3_2016;
    void *temp_r31_2013;

    temp_r3_1971 = this->unk24;
    temp_r3_1971->Deinit();
    temp_r3_1976 = this->unk28;
    temp_r3_1976->Deinit();
    temp_r3_1981 = this->unk2C;
    temp_r3_1981->Deinit();
    temp_r3_1986 = this->unk30;
    temp_r3_1986->Deinit();
    temp_r3_1991 = this->unk34;
    temp_r3_1991->Deinit();
    temp_r3_1996 = this->unk38;
    temp_r3_1996->Deinit();
    operator delete(this->unk24);
    operator delete(this->unk28);
    operator delete(this->unk2C);
    operator delete(this->unk30);
    operator delete(this->unk34);
    operator delete(this->unk38);
    temp_r31_2013 = this->unk1C;
    if (temp_r31_2013 != NULL) {
        temp_r3_2016 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_2016 != NULL) {
            ((MKHeap *) (temp_r3_2016->Current()))->Free(temp_r31_2013, NULL, 0);
        } else {
            free(temp_r31_2013);
        }
        this->unk1C = NULL;
    }
    this->unk10 = 0;
    this->unk18 = 0;
    this->unk14 = 0;
    this->unk8 = 1;
    this->unkC = NULL;
    this->unk9 = 0;
}

#if 0 // DRAFT: pointer/array required
void CynderGoal_FlyingAttackMode::Init(Cynder *arg0) {
    CynderBossGoal_FlyAlongSpline *temp_r4_2243;
    Goal<Cynder> *temp_r4_2210;
    Goal<Cynder> *temp_r4_2221;
    Goal<Cynder> *temp_r4_2232;
    Goal<Cynder> *temp_r4_2254;
    Goal<Cynder> *temp_r4_2265;
    MKHeap *temp_r3_2183;
    void *var_r3_2190;

    if ((u8) this->unk9 == 0) {
        operator new(0x10U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__13Goal<6Cynder>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk24 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x10U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__13Goal<6Cynder>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk28 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x1CU, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__13Goal<6Cynder>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk2C = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x28U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__13Goal<6Cynder>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk30 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x28U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__13Goal<6Cynder>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk34 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x10U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__13Goal<6Cynder>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk38 = M2C_ERROR(/* Read from unset register $r3 */);
    }
    if ((u8) this->unk9 == 0) {
        temp_r3_2183 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_2183 != NULL) {
            var_r3_2190 = ((MKHeap *) (temp_r3_2183->Current()))->Alloc(0x18, NULL, 0);
        } else {
            var_r3_2190 = malloc(0x18);
        }
        this->unk1C = var_r3_2190;
        this->unk10 = 6;
    }
    this->unk8 = 1;
    this->unkC = arg0;
    this->unk4 = 0xBA;
    if ((Cynder *) this->unkC != NULL) {
        this->unk9 = 1;
    }
    temp_r4_2210 = this->unk24;
    M2C_FIELD(temp_r4_2210, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_2210, Cynder **, 0xC) = arg0;
    M2C_FIELD(temp_r4_2210, s32 *, 4) = 0x9C;
    if ((Cynder *) M2C_FIELD(temp_r4_2210, Cynder **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_2210, s8 *, 9) = 1;
    }
    temp_r4_2221 = this->unk28;
    M2C_FIELD(temp_r4_2221, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_2221, Cynder **, 0xC) = arg0;
    M2C_FIELD(temp_r4_2221, s32 *, 4) = 0x9C;
    if ((Cynder *) M2C_FIELD(temp_r4_2221, Cynder **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_2221, s8 *, 9) = 1;
    }
    temp_r4_2232 = this->unk2C;
    M2C_FIELD(temp_r4_2232, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_2232, Cynder **, 0xC) = arg0;
    M2C_FIELD(temp_r4_2232, s32 *, 4) = 0xAE;
    if ((Cynder *) M2C_FIELD(temp_r4_2232, Cynder **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_2232, s8 *, 9) = 1;
    }
    temp_r4_2243 = this->unk30;
    temp_r4_2243->unk8 = 1;
    temp_r4_2243->unkC = arg0;
    temp_r4_2243->unk4 = 0xAD;
    if ((Cynder *) temp_r4_2243->unkC != NULL) {
        temp_r4_2243->unk9 = 1;
    }
    temp_r4_2254 = this->unk34;
    M2C_FIELD(temp_r4_2254, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_2254, Cynder **, 0xC) = arg0;
    M2C_FIELD(temp_r4_2254, s32 *, 4) = 0xAD;
    if ((Cynder *) M2C_FIELD(temp_r4_2254, Cynder **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_2254, s8 *, 9) = 1;
    }
    temp_r4_2265 = this->unk38;
    M2C_FIELD(temp_r4_2265, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_2265, Cynder **, 0xC) = arg0;
    M2C_FIELD(temp_r4_2265, s32 *, 4) = 0x9D;
    if ((Cynder *) M2C_FIELD(temp_r4_2265, Cynder **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_2265, s8 *, 9) = 1;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'SetInvulnerableToBreathAttacks'
void CynderGoal_TurnToAttack::Terminate() {
    this->unkC->StopMovement(1U);
    this->unkC->SetInvulnerableToBreathAttacks(1U, 1U);
    this->unkC->SetInvulnerableToMeleeAttacks(1U, 1U);
    this->unk8 = 1;
}
#endif

u8 CynderGoal_TurnToAttack::Update() {
    Character *temp_r3_2320;

    ActivateIfInactive();
    temp_r3_2320 = this->unkC;
    M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
    if (((temp_r3_2320->unkC8 * temp_r3_2320->unkE8) + ((temp_r3_2320->unkC0 * temp_r3_2320->unkE0) + (temp_r3_2320->unkC4 * temp_r3_2320->unkE4))) == 0.999f) {
        temp_r3_2320->unk684 = 0.0f;
        this->unk8 = 2;
    }
    return this->unk8;
}

#if 0 // DRAFT: undefined identifier 'unk8B8'
void CynderGoal_TurnToAttack::Activate() {
    f64 sp30;
    f64 sp28;
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    Character *temp_r3_2360;
    Character *temp_r3_2374;
    Character *temp_r3_2427;
    Character *temp_r4_2397;
    EnemyAttack **temp_r4_2376;
    f32 temp_f2_2411;
    f32 temp_f2_2431;
    f32 temp_f4_2434;
    f32 temp_f6_2429;
    f32 temp_f7_2436;
    f32 temp_f8_2432;
    f32 temp_f9_2430;
    s32 var_r5_2463;
    u8 var_r30_2361;

    this->unk8 = 0;
    this->unkC->StopMovement(1U);
    temp_r3_2360 = this->unkC;
    var_r30_2361 = 0;
    if (((u8) temp_r3_2360->unk8B8 == 2) || (temp_r3_2360->unk8B0.Get() != NULL)) {
        var_r30_2361 = 1;
    }
    if ((var_r30_2361 == 0) || (temp_r3_2374 = this->unkC, temp_r4_2376 = M2C_FIELD(temp_r3_2374->unkA5C, EnemyAttack ***, 8), ((temp_r4_2376 == NULL) != 0))) {
        this->unk8 = 3;
        return;
    }
    sp28 = M2C_FIELD(temp_r3_2374, f64 *, 0xC0);
    sp30 = M2C_FIELD(temp_r3_2374, f64 *, 0xC8);
    if (temp_r3_2374->GetAttackHeading(*temp_r4_2376, (MKVector3 *) &sp28) == 0) {
        this->unk8 = 2;
        return;
    }
    temp_r4_2397 = this->unkC;
    M2C_FIELD(temp_r4_2397, f64 *, 0xE0) = sp28;
    temp_f2_2411 = (temp_r4_2397->unkC8 * (f32) sp30) + ((temp_r4_2397->unkC0 * (f32) sp28) + (temp_r4_2397->unkC4 * unksp2C));
    M2C_FIELD(temp_r4_2397, f64 *, 0xE8) = sp30;
    temp_r4_2397->unk6B5 |= 0x40;
    M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
    if (temp_f2_2411 == 0.999f) {
        this->unk8 = 2;
    } else {
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if (temp_f2_2411 == 0.7f) {
            temp_r3_2427 = this->unkC;
            temp_f6_2429 = temp_r3_2427->unkC8;
            temp_f9_2430 = temp_r3_2427->unkD0;
            temp_f2_2431 = temp_r3_2427->unkD8;
            temp_f8_2432 = temp_r3_2427->unkC4;
            temp_f4_2434 = temp_r3_2427->unkC0;
            temp_f7_2436 = temp_r3_2427->unkD4;
            spC = (temp_f2_2431 * temp_f4_2434) - (temp_f9_2430 * temp_f6_2429);
            sp8 = (temp_f7_2436 * temp_f6_2429) - (temp_f2_2431 * temp_f8_2432);
            sp10 = (temp_f9_2430 * temp_f8_2432) - (temp_f7_2436 * temp_f4_2434);
            sp18 = (f64) sp8;
            sp20 = (f64) sp10;
            temp_r3_2427->unk684 = 3.1415927f;
            var_r5_2463 = 0x15;
            if (((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1FU) != 0) {
                var_r5_2463 = 0x14;
            }
            this->unkC->SetAnim((AnimSequenceType) 4, var_r5_2463, 0, 0.15f, 0U, 0U);
        } else {
            this->unkC->SetAnim((AnimSequenceType) 1, 0xA, 0, 0.15f, 0U, 0U);
            this->unkC->unk684 = 3.1415927f;
        }
    }
    this->unkC->SetInvulnerableToBreathAttacks(1U, 1U);
    this->unkC->SetInvulnerableToMeleeAttacks(1U, 1U);
}
#endif

#if 0 // DRAFT: undefined identifier 'AddSubgoalToFront__22CompositeGoal'
void CynderGoal_GroundAttackMode::AddGoal_MoveToAttackRange(EnemyAttack *arg0) {
    Goal<Cynder> *temp_r4_2523;
    f32 temp_f31_2516;

    temp_f31_2516 = arg0->unk18;
    if (this->unk20->GetDist() > temp_f31_2516) {
        AddSubgoalToFront__22CompositeGoal<6Cynder>FP13Goal<6Cynder>((CompositeGoal<Cynder> *) this, (Goal<Cynder> *) this->unk2C);
        temp_r4_2523 = this->unk2C;
        M2C_FIELD(temp_r4_2523, AITargetData **, 0x20) = (AITargetData *) this->unk20;
        M2C_FIELD(temp_r4_2523, f32 *, 0x38) = temp_f31_2516;
        M2C_FIELD(temp_r4_2523, s8 *, 0x3D) = (s8) (M2C_FIELD(this->unkC, u8 *, 0xD01) == 0);
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'AddSubgoal__22CompositeGoal'
u8 CynderGoal_GroundAttackMode::AddGoal_Attack(EnemyAttack *arg0) {
    s32 temp_r4_2549;

    temp_r4_2549 = arg0->unk38;
    if (temp_r4_2549 & 2) {
        AddSubgoal__22CompositeGoal<6Cynder>FP13Goal<6Cynder>((CompositeGoal<Cynder> *) this, (Goal<Cynder> *) this->unk30);
        AddSubgoal__22CompositeGoal<6Cynder>FP13Goal<6Cynder>((CompositeGoal<Cynder> *) this, (Goal<Cynder> *) this->unk38);
        goto block_5;
    }
    if (temp_r4_2549 & 1) {
        AddSubgoal__22CompositeGoal<6Cynder>FP13Goal<6Cynder>((CompositeGoal<Cynder> *) this, (Goal<Cynder> *) this->unk30);
        AddSubgoal__22CompositeGoal<6Cynder>FP13Goal<6Cynder>((CompositeGoal<Cynder> *) this, (Goal<Cynder> *) this->unk34);
block_5:
        this->unk44 |= 0x40;
        return 1U;
    }
    return 0U;
}
#endif

#if 0 // DRAFT: undefined identifier 'AddSubgoal__22CompositeGoal'
void CynderGoal_GroundAttackMode::AddGoal_AttackIdle() {
    Goal<Cynder> *temp_r4_2594;

    AddSubgoal__22CompositeGoal<6Cynder>FP13Goal<6Cynder>((CompositeGoal<Cynder> *) this, (Goal<Cynder> *) this->unk24);
    temp_r4_2594 = this->unk24;
    M2C_FIELD(temp_r4_2594, s32 *, 0x10) = 0;
    M2C_FIELD(temp_r4_2594, s32 *, 0x14) = 0xA;
}
#endif

#if 0 // DRAFT: undefined identifier 'AddSubgoal__22CompositeGoal'
void CynderGoal_GroundAttackMode::AddGoal_Taunt() {
    Goal<Cynder> *temp_r4_2616;

    AddSubgoal__22CompositeGoal<6Cynder>FP13Goal<6Cynder>((CompositeGoal<Cynder> *) this, (Goal<Cynder> *) this->unk24);
    temp_r4_2616 = this->unk24;
    M2C_FIELD(temp_r4_2616, s32 *, 0x10) = 1;
    M2C_FIELD(temp_r4_2616, s32 *, 0x14) = 3;
}
#endif

#if 0 // DRAFT: undefined identifier 'AddSubgoal__22CompositeGoal'
void CynderGoal_GroundAttackMode::AddGoal_Cheer() {
    Goal<Cynder> *temp_r4_2638;

    AddSubgoal__22CompositeGoal<6Cynder>FP13Goal<6Cynder>((CompositeGoal<Cynder> *) this, (Goal<Cynder> *) this->unk24);
    temp_r4_2638 = this->unk24;
    M2C_FIELD(temp_r4_2638, s32 *, 0x10) = 1;
    M2C_FIELD(temp_r4_2638, s32 *, 0x14) = 4;
}
#endif

void CynderGoal_GroundAttackMode::SetParams(AITargetData *arg0, EAPItem *arg1, bool arg2) {
    this->unk20 = arg0;
    this->unk3C = arg1;
    this->unk44 = (this->unk44 & ~0x20) | ((arg2 << 5) & 0x20);
}

void CynderGoal_GroundAttackMode::Reset() {
    this->unk8 = 1;
    RemoveAllSubgoals();
    this->unk44 &= ~0x40;
    this->unk44 &= ~0x20;
    this->unk40 = M2C_BITWISE(s32, this->unkC->unkAD0);
}

void CynderGoal_GroundAttackMode::Terminate() {
    this->unk8 = 1;
    RemoveAllSubgoals();
}

#if 0 // DRAFT: illegal implicit conversion from 'void' to
u8 CynderGoal_GroundAttackMode::Update() {
    Enemy *temp_r4_2719;

    ActivateIfInactive();
    this->unk8 = UpdateSubgoals();
    if ((u8) this->unk8 == 2) {
        temp_r4_2719 = this->unkC;
        if ((temp_r4_2719->unkAB0 > 0.0f) && ((M2C_BITWISE(s32, temp_r4_2719->unkAD0) != 2) || (M2C_ERROR(/* unknown instruction: cror eq, gt, eq */), ((gb.unk30C == M2C_FIELD(temp_r4_2719, f32 *, 0xF14)) == 0)))) {
            Activate();
        }
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: expression syntax error
void CynderGoal_GroundAttackMode::Activate() {
    EAPItem *temp_r0_2807;
    Enemy *temp_r3_2760;
    Enemy *temp_r4_2793;
    Enemy *temp_r4_2840;
    Enemy *temp_r4_2859;
    s32 temp_r3_2862;
    u8 var_r30_2761;
    void *temp_r3_2803;
    void *temp_r3_2852;
    void *temp_r4_2816;
    void *temp_r4_2821;
    void *temp_r4_2873;

    this->unk8 = 0;
    RemoveAllSubgoals();
    temp_r3_2760 = this->unkC;
    var_r30_2761 = 0;
    if (((u8) M2C_FIELD(temp_r3_2760, u8 *, 0x8B8) == 2) || (temp_r3_2760->unk870.unk30.Get() != NULL)) {
        var_r30_2761 = 1;
    }
    if ((var_r30_2761 == 0) && (this->unkC->SelectTarget() == 0)) {
        if (((u8) M2C_FIELD(this->unkC, u8 *, 0xB08) >> 1U) & 1) {
            AddGoal_Cheer();
            this->unkC->SetHitTarget(0U);
            return;
        }
        AddGoal_AttackIdle();
        return;
    }
    temp_r4_2793 = this->unkC;
    if (((u8) M2C_FIELD(temp_r4_2793->unkA44, u8 *, 0x10) >> 6U) & 1) {
        temp_r4_2793->unkA7C = 0.0f;
    }
    temp_r3_2803 = this->unkC->unkA44;
    M2C_FIELD(temp_r3_2803, u8 *, 0x10) = (u8) (M2C_FIELD(temp_r3_2803, u8 *, 0x10) | 0x20);
    temp_r0_2807 = this->unk3C;
    if (temp_r0_2807 != NULL) {
        M2C_FIELD(this->unkC->unkA44, EAPItem **, 8) = temp_r0_2807;
        temp_r4_2816 = this->unkC->unkA44;
        M2C_FIELD(temp_r4_2816, u8 *, 0x10) = (u8) (M2C_FIELD(temp_r4_2816, u8 *, 0x10) & ~0x80);
        temp_r4_2821 = this->unkC->unkA44;
        M2C_FIELD(temp_r4_2821, u8 *, 0x10) = (u8) (M2C_FIELD(temp_r4_2821, u8 *, 0x10) & ~0x40);
        this->unkC->unkA08 = (CharacterFireFX *) this->unk3C->unk0;
        this->unkC->unkA0C = (CharacterBreathFX *) this->unk3C->unk0;
        AddGoal_Attack(this->unk3C->unk0);
        this->unk3C = NULL;
        return;
    }
    temp_r4_2840 = this->unkC;
    M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
    if (gb.unk30C != temp_r4_2840->unkA7C) {
        AddGoal_AttackIdle();
        return;
    }
    temp_r3_2852 = temp_r4_2840->unkA44;
    M2C_FIELD(temp_r3_2852, u8 *, 0x10) = (u8) (M2C_FIELD(temp_r3_2852, u8 *, 0x10) & ~0x40);
    temp_r4_2859 = this->unkC;
    temp_r3_2862 = temp_r4_2859->unkA44->Evaluate(temp_r4_2859, this->unk20, NULL, 0);
    if ((temp_r3_2862 != 0) && (AddGoal_Attack(*temp_r3_2862) != 0)) {
        temp_r4_2873 = this->unkC->unkA44;
        M2C_FIELD(temp_r4_2873, u8 *, 0x10) = (u8) (M2C_FIELD(temp_r4_2873, u8 *, 0x10) & ~0x80);
        M2C_FIELD(this->unkC->unkA44, s32 *, 8) = temp_r3_2862;
        this->unkC->unkA08 = (CharacterFireFX *) *temp_r3_2862;
        this->unkC->unkA0C = (CharacterBreathFX *) *temp_r3_2862;
        AddGoal_MoveToAttackRange(*temp_r3_2862);
        return;
    }
    AddGoal_Taunt();
}
#endif

void CynderGoal_GroundAttackMode::Deinit() {
    Goal<Cynder> *temp_r3_2908;
    Goal<Cynder> *temp_r3_2918;
    Goal<Cynder> *temp_r3_2923;
    Goal<Cynder> *temp_r3_2928;
    Goal<Cynder> *temp_r3_2933;
    MKHeap *temp_r3_2953;
    void **temp_r3_2913;
    void *temp_r31_2950;

    temp_r3_2908 = this->unk24;
    temp_r3_2908->Deinit();
    temp_r3_2913 = this->unk28;
    M2C_FIELD(*temp_r3_2913, M2C_UNK (**)(void **), 0xC)(temp_r3_2913);
    temp_r3_2918 = this->unk2C;
    temp_r3_2918->Deinit();
    temp_r3_2923 = this->unk30;
    temp_r3_2923->Deinit();
    temp_r3_2928 = this->unk38;
    temp_r3_2928->Deinit();
    temp_r3_2933 = this->unk34;
    temp_r3_2933->Deinit();
    operator delete(this->unk24);
    operator delete(this->unk28);
    operator delete(this->unk2C);
    operator delete(this->unk30);
    operator delete(this->unk38);
    operator delete(this->unk34);
    temp_r31_2950 = this->unk1C;
    if (temp_r31_2950 != NULL) {
        temp_r3_2953 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_2953 != NULL) {
            ((MKHeap *) (temp_r3_2953->Current()))->Free(temp_r31_2950, NULL, 0);
        } else {
            free(temp_r31_2950);
        }
        this->unk1C = NULL;
    }
    this->unk10 = 0;
    this->unk18 = 0;
    this->unk14 = 0;
    this->unk8 = 1;
    this->unkC = NULL;
    this->unk9 = 0;
}

#if 0 // DRAFT: pointer/array required
void CynderGoal_GroundAttackMode::Init(Cynder *arg0) {
    Goal<Cynder> *temp_r4_3154;
    Goal<Cynder> *temp_r4_3179;
    Goal<Cynder> *temp_r4_3190;
    Goal<Cynder> *temp_r4_3201;
    MKHeap *temp_r3_3127;
    void **temp_r4_3165;
    void *var_r3_3134;

    if ((u8) this->unk9 == 0) {
        operator new(0x1CU, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__13Goal<6Cynder>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk24 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x28U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__13Goal<6Cynder>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk28 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x40U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__13Goal<6Cynder>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__22CompositeGoal<6Cynder>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x1C) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x18) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x10) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x14) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk2C = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x10U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__13Goal<6Cynder>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk30 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x1CU, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__13Goal<6Cynder>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk38 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x10U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__13Goal<6Cynder>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk34 = M2C_ERROR(/* Read from unset register $r3 */);
    }
    if ((u8) this->unk9 == 0) {
        temp_r3_3127 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_3127 != NULL) {
            var_r3_3134 = ((MKHeap *) (temp_r3_3127->Current()))->Alloc(0x14, NULL, 0);
        } else {
            var_r3_3134 = malloc(0x14);
        }
        this->unk1C = var_r3_3134;
        this->unk10 = 5;
    }
    this->unk8 = 1;
    this->unkC = (Enemy *) arg0;
    this->unk4 = 0xB9;
    if ((Enemy *) this->unkC != NULL) {
        this->unk9 = 1;
    }
    temp_r4_3154 = this->unk24;
    M2C_FIELD(temp_r4_3154, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_3154, Cynder **, 0xC) = arg0;
    M2C_FIELD(temp_r4_3154, s32 *, 4) = 0xAA;
    if ((Cynder *) M2C_FIELD(temp_r4_3154, Cynder **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_3154, s8 *, 9) = 1;
    }
    temp_r4_3165 = this->unk28;
    M2C_FIELD(temp_r4_3165, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_3165, Cynder **, 0xC) = arg0;
    M2C_FIELD(temp_r4_3165, s32 *, 4) = 0xA9;
    if ((Cynder *) M2C_FIELD(temp_r4_3165, Cynder **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_3165, s8 *, 9) = 1;
    }
    this->unk2C->Init(arg0);
    temp_r4_3179 = this->unk30;
    M2C_FIELD(temp_r4_3179, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_3179, Cynder **, 0xC) = arg0;
    M2C_FIELD(temp_r4_3179, s32 *, 4) = 0xBC;
    if ((Cynder *) M2C_FIELD(temp_r4_3179, Cynder **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_3179, s8 *, 9) = 1;
    }
    temp_r4_3190 = this->unk38;
    M2C_FIELD(temp_r4_3190, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_3190, Cynder **, 0xC) = arg0;
    M2C_FIELD(temp_r4_3190, s32 *, 4) = 0xAC;
    if ((Cynder *) M2C_FIELD(temp_r4_3190, Cynder **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_3190, s8 *, 9) = 1;
    }
    temp_r4_3201 = this->unk34;
    M2C_FIELD(temp_r4_3201, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_3201, Cynder **, 0xC) = arg0;
    M2C_FIELD(temp_r4_3201, s32 *, 4) = 0xAB;
    if ((Cynder *) M2C_FIELD(temp_r4_3201, Cynder **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_3201, s8 *, 9) = 1;
    }
    this->unk3C = NULL;
    this->unk20 = NULL;
    this->unk40 = 0;
    this->unk44 &= ~0x40;
    this->unk44 &= ~0x20;
}
#endif

#if 0 // DRAFT: undefined identifier 'SetInvulnerableToMeleeAttacks'
void CynderBossGoal_FlyingInWait::Terminate() {
    Character *temp_r3_3243;
    Character *temp_r3_3250;
    Character *temp_r3_3286;
    Character *temp_r6_3273;
    f32 temp_f1_3296;
    f32 temp_f1_3326;
    f32 temp_f5_3302;
    f32 temp_f6_3290;
    this->unk8 = 1;
    RemoveAllSubgoals();
    temp_r3_3243 = this->unkC;
    temp_r3_3243->unk6B5 |= 0x20;
    temp_r3_3250 = this->unkC;
    temp_r3_3250->unk6B5 &= ~0x10;
    this->unkC->StopMovement(1U);
    this->unkC->SetMovementType((CharacterMoveType) 0);
    this->unkC->SetInvulnerableToMeleeAttacks(0U, 1U);
    this->unkC->SetInvulnerableToBreathAttacks(0U, 1U);
    temp_r6_3273 = this->unkC;
    temp_r6_3273->unkA7C = gb.unk30C + 3.0f;
    M2C_STRUCT_COPY((s32) &arg_sp2C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
    temp_r3_3286 = this->unkC;
    temp_f6_3290 = temp_r3_3286->unk5C8;
    arg_sp50 = temp_f6_3290;
    temp_f1_3296 = temp_r3_3286->unk5C8;
    arg_sp54 = temp_f1_3296;
    temp_f5_3302 = temp_r3_3286->unk5CC;
    arg_sp18 = (MKVector3::up.unk0 * temp_f1_3296) - (MKVector3::up.unk4 * temp_f6_3290);
    arg_sp58 = temp_f5_3302;
    arg_sp28 = (f64) arg_sp18;
    arg_sp10 = (MKVector3::up.unk4 * temp_f5_3302) - (MKVector3::up.unk8 * temp_f1_3296);
    arg_sp14 = (MKVector3::up.unk8 * temp_f6_3290) - (MKVector3::up.unk0 * temp_f5_3302);
    arg_sp5C = 0.0f;
    arg_sp20 = (f64) arg_sp10;
    arg_sp30 = (f32) arg_sp20;
    arg_sp34 = arg_sp24;
    arg_sp38 = (f32) arg_sp28;
    arg_sp3C = 0.0f;
    arg_sp60 = temp_r3_3286->unk5B8;
    arg_sp64 = temp_r3_3286->unk5B8;
    temp_f1_3326 = temp_r3_3286->unk5BC;
    arg_sp68 = temp_f1_3326;
    arg_sp6C = 1.0f;
    temp_r3_3286->Teleport(&arg_sp30, &MKVector3::up, temp_r6_3273, temp_f1_3326, arg_sp24, (f32) arg_sp20, 0.0f, temp_f5_3302, temp_f6_3290, MKVector3::up.unk8, MKVector3::up.unk4);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void' to
u8 CynderBossGoal_FlyingInWait::Update() {
    Character *temp_r3_3353;

    ActivateIfInactive();
    this->unk8 = UpdateSubgoals();
    temp_r3_3353 = this->unkC;
    if ((u8) M2C_FIELD(temp_r3_3353, u8 *, 0xF1A) != 0) {
        M2C_FIELD(temp_r3_3353, u8 *, 0xF1A) = 0U;
        M2C_FIELD(this->unkC, s8 *, 0xF19) = 0;
        this->unkC->SetAnim((AnimSequenceType) 1, 0xA, 0, 0.0f, 0U, 0U);
        this->unk8 = 2;
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: undefined identifier 'SetInvulnerableToMeleeAttacks'
void CynderBossGoal_FlyingInWait::Activate() {
    Character *temp_r5_3420;
    Character *temp_r6_3413;
    Goal<Cynder> *temp_r4_3415;
    Goal<Cynder> *temp_r4_3421;

    this->unk8 = 0;
    RemoveAllSubgoals();
    M2C_FIELD(this->unkC, s8 *, 0xF1A) = 0;
    this->unkC->SetInvulnerableToMeleeAttacks(1U, 0U);
    this->unkC->SetInvulnerableToBreathAttacks(1U, 0U);
    this->unkC->CalcFlightPathData2();
    AddSubgoal__22CompositeGoal<6Cynder>FP13Goal<6Cynder>((CompositeGoal<Cynder> *) this, (Goal<Cynder> *) this->unk20);
    AddSubgoal__22CompositeGoal<6Cynder>FP13Goal<6Cynder>((CompositeGoal<Cynder> *) this, (Goal<Cynder> *) this->unk24);
    AddSubgoal__22CompositeGoal<6Cynder>FP13Goal<6Cynder>((CompositeGoal<Cynder> *) this, (Goal<Cynder> *) this->unk28);
    temp_r6_3413 = this->unkC;
    temp_r4_3415 = this->unk24;
    M2C_FIELD(temp_r4_3415, void **, 0x10) = (void *) (temp_r6_3413 + 0xFA0);
    M2C_FIELD(temp_r4_3415, s32 *, 0x14) = (s32) M2C_FIELD(temp_r6_3413, s32 *, 0xFFC);
    temp_r5_3420 = this->unkC;
    temp_r4_3421 = this->unk28;
    M2C_FIELD(temp_r4_3421, s32 *, 0x10) = (s32) M2C_FIELD(temp_r5_3420, s32 *, 0xFF0);
    M2C_FIELD(temp_r4_3421, f32 *, 0x14) = (f32) M2C_FIELD(temp_r5_3420, f32 *, 0xFF4);
    M2C_FIELD(temp_r4_3421, u8 *, 0x24) = (u8) (M2C_FIELD(temp_r4_3421, u8 *, 0x24) & ~0x40);
}
#endif

void CynderBossGoal_FlyingInWait::Deinit() {
    Goal<Cynder> *temp_r3_3444;
    Goal<Cynder> *temp_r3_3449;
    Goal<Cynder> *temp_r3_3454;
    MKHeap *temp_r3_3482;
    void **temp_r3_3459;
    void **temp_r3_3464;
    void *temp_r31_3479;

    temp_r3_3444 = this->unk20;
    temp_r3_3444->Deinit();
    temp_r3_3449 = this->unk24;
    temp_r3_3449->Deinit();
    temp_r3_3454 = this->unk28;
    temp_r3_3454->Deinit();
    temp_r3_3459 = this->unk2C;
    M2C_FIELD(*temp_r3_3459, M2C_UNK (**)(void **), 0xC)(temp_r3_3459);
    temp_r3_3464 = this->unk30;
    M2C_FIELD(*temp_r3_3464, M2C_UNK (**)(void **), 0xC)(temp_r3_3464);
    operator delete(this->unk20);
    operator delete(this->unk24);
    operator delete(this->unk28);
    operator delete(this->unk2C);
    operator delete(this->unk30);
    temp_r31_3479 = this->unk1C;
    if (temp_r31_3479 != NULL) {
        temp_r3_3482 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_3482 != NULL) {
            ((MKHeap *) (temp_r3_3482->Current()))->Free(temp_r31_3479, NULL, 0);
        } else {
            free(temp_r31_3479);
        }
        this->unk1C = NULL;
    }
    this->unk10 = 0;
    this->unk18 = 0;
    this->unk14 = 0;
    this->unk8 = 1;
    this->unkC = NULL;
    this->unk9 = 0;
}

#if 0 // DRAFT: pointer/array required
void CynderBossGoal_FlyingInWait::Init(Cynder *arg0) {
    Goal<Cynder> *temp_r4_3656;
    Goal<Cynder> *temp_r4_3667;
    Goal<Cynder> *temp_r4_3678;
    MKHeap *temp_r3_3629;
    void **temp_r4_3689;
    void **temp_r4_3700;
    void *var_r3_3636;

    if ((u8) this->unk9 == 0) {
        operator new(0x10U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__13Goal<6Cynder>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk20 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x1CU, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__13Goal<6Cynder>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk24 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x28U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__13Goal<6Cynder>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk28 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x28U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__13Goal<6Cynder>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk2C = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x10U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__13Goal<6Cynder>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk30 = M2C_ERROR(/* Read from unset register $r3 */);
    }
    if ((u8) this->unk9 == 0) {
        temp_r3_3629 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_3629 != NULL) {
            var_r3_3636 = ((MKHeap *) (temp_r3_3629->Current()))->Alloc(0x14, NULL, 0);
        } else {
            var_r3_3636 = malloc(0x14);
        }
        this->unk1C = var_r3_3636;
        this->unk10 = 5;
    }
    this->unk8 = 1;
    this->unkC = (Character *) arg0;
    this->unk4 = 0xB0;
    if ((Character *) this->unkC != NULL) {
        this->unk9 = 1;
    }
    temp_r4_3656 = this->unk20;
    M2C_FIELD(temp_r4_3656, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_3656, Cynder **, 0xC) = arg0;
    M2C_FIELD(temp_r4_3656, s32 *, 4) = 0x9C;
    if ((Cynder *) M2C_FIELD(temp_r4_3656, Cynder **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_3656, s8 *, 9) = 1;
    }
    temp_r4_3667 = this->unk24;
    M2C_FIELD(temp_r4_3667, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_3667, Cynder **, 0xC) = arg0;
    M2C_FIELD(temp_r4_3667, s32 *, 4) = 0xAE;
    if ((Cynder *) M2C_FIELD(temp_r4_3667, Cynder **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_3667, s8 *, 9) = 1;
    }
    temp_r4_3678 = this->unk28;
    M2C_FIELD(temp_r4_3678, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_3678, Cynder **, 0xC) = arg0;
    M2C_FIELD(temp_r4_3678, s32 *, 4) = 0xAD;
    if ((Cynder *) M2C_FIELD(temp_r4_3678, Cynder **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_3678, s8 *, 9) = 1;
    }
    temp_r4_3689 = this->unk2C;
    M2C_FIELD(temp_r4_3689, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_3689, Cynder **, 0xC) = arg0;
    M2C_FIELD(temp_r4_3689, s32 *, 4) = 0xAD;
    if ((Cynder *) M2C_FIELD(temp_r4_3689, Cynder **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_3689, s8 *, 9) = 1;
    }
    temp_r4_3700 = this->unk30;
    M2C_FIELD(temp_r4_3700, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_3700, Cynder **, 0xC) = arg0;
    M2C_FIELD(temp_r4_3700, s32 *, 4) = 0x9D;
    if ((Cynder *) M2C_FIELD(temp_r4_3700, Cynder **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_3700, s8 *, 9) = 1;
    }
}
#endif

u8 CynderBossGoal_RunningTakeOff::Update() {
    Enemy *temp_r3_3736;
    Enemy *temp_r3_3742;

    ActivateIfInactive();
    if (((MKAnimScript *) (M2C_FIELD(this->unkC, MKAnimScript **, 0x630)))->CheckEvent(5) != 0) {
        this->unkC->SetIdleMovementSpeed(1U);
        temp_r3_3736 = this->unkC;
        temp_r3_3736->unk6B5 |= 0x10;
    }
    temp_r3_3742 = this->unkC;
    M2C_FIELD(temp_r3_3742, f64 *, 0x598) = (f64) M2C_FIELD(temp_r3_3742, f64 *, 0x90);
    M2C_FIELD(temp_r3_3742, f64 *, 0x5A0) = (f64) M2C_FIELD(temp_r3_3742, f64 *, 0x98);
    if (this->unkC->HasAnimFinished() != 0) {
        this->unk8 = 2;
    }
    return this->unk8;
}

void CynderBossGoal_RunningTakeOff::Activate() {
    Enemy *temp_r3_3773;
    Enemy *temp_r6_3782;
    Enemy *temp_r6_3793;

    this->unk8 = 0;
    temp_r3_3773 = this->unkC;
    temp_r3_3773->unk6B5 &= ~0x20;
    this->unkC->StopMovement(0U);
    this->unkC->SetMovementType((CharacterMoveType) 1);
    temp_r6_3782 = this->unkC;
    M2C_FIELD(temp_r6_3782, f64 *, 0xE0) = (f64) M2C_FIELD(temp_r6_3782, f64 *, 0xC0);
    M2C_FIELD(temp_r6_3782, f64 *, 0xE8) = (f64) M2C_FIELD(temp_r6_3782, f64 *, 0xC8);
    temp_r6_3782->unk6B5 |= 0x40;
    temp_r6_3793 = this->unkC;
    M2C_FIELD(temp_r6_3793, f64 *, 0xF0) = (f64) M2C_FIELD(temp_r6_3793, f64 *, 0xD0);
    M2C_FIELD(temp_r6_3793, f64 *, 0xF8) = (f64) M2C_FIELD(temp_r6_3793, f64 *, 0xD8);
    temp_r6_3793->unk6B5 |= 0x40;
    this->unkC->SetInvulnerableToMeleeAttacks(1U, 1U);
    this->unkC->SetInvulnerableToBreathAttacks(1U, 1U);
    this->unkC->SetAnim((AnimSequenceType) 0xA, 0xDC, 0, 0.15f, 0U, 0U);
    M2C_FIELD(this->unkC, s32 *, 0xCFC) = 0;
}

#if 0 // DRAFT: expression syntax error
void CynderBossGoal_MoveToTarget::CalculateRegionEdgeMoveTarget(bool arg0) {
    f64 sp1E0;                                      /* compiler-managed */
    f64 sp1D8;
    f64 sp1D0;
    f64 sp1C8;
    f64 sp1C0;                                      /* compiler-managed */
    f64 sp1B8;
    f64 sp1B0;
    f64 sp1A8;
    M2C_UNK sp198;
    f64 sp190;
    f64 sp188;
    MKVector3 sp178;
    f64 sp170;
    f64 sp168;
    f64 sp160;
    f64 sp158;
    f64 sp150;
    f64 sp148;
    f64 sp140;
    f64 sp138;
    M2C_UNK sp128;
    f64 sp120;
    f64 sp118;
    MKVector3 sp108;
    f64 sp100;
    f64 spF8;
    f64 spF0;
    f64 spE8;
    f64 spE0;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    f32 spC0;
    f32 spB0;
    M2C_UNK sp98;
    f32 sp90;
    f32 sp80;
    f32 sp70;
    f32 sp60;
    f32 sp50;
    f32 sp40;
    f32 sp30;
    f32 sp20;
    f64 sp10;
    f64 sp8;
    Cynder *temp_r4_4091;
    u8 var_r30_3947;

    sp8 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    sp10 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
    sp1D8 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    sp1E0 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
    sp1C8 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    sp1D0 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
    sp1B8 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    sp1C0 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
    sp1A8 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    sp1B0 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
    if (arg0 != 0) {
        sp198.GetPos();
        this->unkC->unk750.unkA0.GetNearestPointOnBoundingRegion(*((MKVector3 *) &sp198), (MKVector3 *) &sp1D8, (MKVector3 *) &sp1B8);
        sp178.operator*(100.0f);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f2, $f0 */);
        sp188 = sp68;
        sp70 = (f32) sp1E0 + sp178.unk8;
        sp1C8 = sp68;
        sp190 = (f64) sp70;
        sp1D0 = (f64) sp70;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
        sp158 = spB8;
        spC0 = (f32) sp1C0 * 1.0f;
        sp160 = (f64) spC0;
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f2, $f0 */);
        sp168 = spA8;
        spB0 = (f32) sp1E0 + (f32) sp160;
        sp170 = (f64) spB0;
        if (this->unkC->unk750.unkA0.GetFirstIntersectionPlane(*((MKVector3 *) &sp168), *((MKVector3 *) &sp1C8), (MKVector3 *) &sp1C8, (MKVector3 *) &sp1A8) != 0) {
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
            sp138 = sp28;
            sp30 = (f32) sp1D0 - (f32) sp1E0;
            sp140 = (f64) sp30;
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
            sp148 = sp58;
            sp60 = (f32) sp140 * 0.5f;
            sp150 = (f64) sp60;
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            sp1E0 = (f32) sp1E0 + (f32) sp150;
        } else {
            var_r30_3947 = 0;
            if (this->unkC->unk750.unkA0.IsPointWithin(*((MKVector3 *) &sp1C8)) != 0) {
                sp98.GetRegionPos();
                M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
                if ((f32) fabs(sp9C - unksp1CC) == 500.0f) {
                    var_r30_3947 = 1;
                }
            }
            if (var_r30_3947 != 0) {
                sp1D8 = sp1C8;
                sp1E0 = sp1D0;
            }
        }
    } else {
        sp128.GetPos();
        this->unkC->unk800.unk28.GetNearestPointOnBoundingRegion(*((MKVector3 *) &sp128), (MKVector3 *) &sp1D8, (MKVector3 *) &sp1B8);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
        sp1C0 = (f32) sp1C0 * -1.0f;
        sp108.operator*(100.0f);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f2, $f0 */);
        sp118 = sp48;
        sp50 = (f32) sp1E0 + sp108.unk8;
        sp1C8 = sp48;
        sp120 = (f64) sp50;
        sp1D0 = (f64) sp50;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
        spE8 = sp88;
        sp90 = sp1C0 * 1.0f;
        spF0 = (f64) sp90;
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f2, $f0 */);
        spF8 = sp78;
        sp80 = (f32) sp1E0 + (f32) spF0;
        sp100 = (f64) sp80;
        if (this->unkC->unk800.unk28.GetFirstIntersectionPlane(*((MKVector3 *) &spF8), *((MKVector3 *) &sp1C8), (MKVector3 *) &sp1C8, (MKVector3 *) &sp1A8) != 0) {
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
            spC8 = sp18;
            sp20 = (f32) sp1D0 - (f32) sp1E0;
            spD0 = (f64) sp20;
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
            spD8 = sp38;
            sp40 = (f32) spD0 * 0.5f;
            spE0 = (f64) sp40;
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            sp1E0 = (f32) sp1E0 + (f32) spE0;
        } else if (this->unkC->unk800.unk28.IsPointWithin(*((MKVector3 *) &sp1C8)) == 0) {
            sp1D8 = sp1C8;
            sp1E0 = sp1D0;
        }
    }
    this->unkC->unk870.unk40.Set(*((MKVector3 *) &sp1D8), 0U);
    this->unkC->unk870.unk40.SetInsideRegion(1U);
    temp_r4_4091 = this->unkC;
    temp_r4_4091->unk870.unk40.Update(*((MKVector3 *) &temp_r4_4091->unk588));
}
#endif

void CynderBossGoal_MoveToTarget::Terminate() {
    this->unk8 = 1;
    RemoveAllSubgoals();
}

#if 0 // DRAFT: undefined identifier 'Update'
u8 CynderBossGoal_MoveToTarget::Update() {
    f64 sp140;
    f64 sp138;
    AITargetData sp128;
    M2C_UNK sp118;
    M2C_UNK sp108;
    f64 sp100;
    f64 spF8;
    f64 spF0;
    f64 spE8;
    AITargetData spD8;
    M2C_UNK spC8;
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
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f32 sp40;
    f32 sp30;
    f32 sp20;
    f32 sp10;
    AITargetData *temp_r3_4135;
    AITargetData *temp_r3_4498;
    Cynder *temp_r3_4296;
    Cynder *temp_r3_4412;
    Cynder *temp_r4_4177;
    Cynder *temp_r4_4196;
    Cynder *temp_r4_4344;
    Goal<Cynder> *temp_r3_4184;
    Goal<Cynder> *temp_r3_4241;
    Goal<Cynder> *temp_r6_4315;
    Goal<Cynder> *temp_r6_4469;
    Goal<Cynder> *temp_r8_4383;
    u8 temp_r3_4172;
    u8 temp_r3_4252;
    u8 temp_r3_4459;
    u8 var_r30_4139;
    u8 var_r30_4413;
    u8 var_r30_4502;
    void **temp_r3_4162;
    void *temp_r3_4197;
    void *temp_r3_4345;
    void *temp_r5_4298;

    ActivateIfInactive();
    if ((u8) this->unk8 != 3) {
        temp_r3_4135 = this->unk20;
        if (temp_r3_4135 != NULL) {
            var_r30_4139 = 0;
            if (((u8) M2C_FIELD(temp_r3_4135, u8 *, 0x48) == 2) || (temp_r3_4135->unk40.Get() != NULL)) {
                var_r30_4139 = 1;
            }
            if (var_r30_4139 == 0) {
                goto block_6;
            }
            if (this->unk20->GetDist() < this->unk38) {
                temp_r3_4162 = this->unk28;
                if (M2C_FIELD(*temp_r3_4162, u8 (**)(void **), 0x28)(temp_r3_4162) == 0) {
                    this->unk8 = 2;
                }
            }
            temp_r3_4172 = this->unk8;
            if (temp_r3_4172 == 2) {
                return temp_r3_4172;
            }
            temp_r4_4177 = this->unkC;
            temp_r4_4177->unk870.unk40.Update(*((MKVector3 *) &temp_r4_4177->unk588));
            this->unk8 = UpdateSubgoals();
            temp_r3_4184 = this->unk34;
            if (temp_r3_4184->IsActive() != 0) {
                if (this->unkC->FollowPathToTarget(this->unk20) != 0) {
                    temp_r4_4196 = this->unkC;
                    temp_r3_4197 = temp_r4_4196->unk8;
                    sp138 = M2C_FIELD(temp_r3_4197, f64 *, 0x30);
                    sp140 = M2C_FIELD(temp_r3_4197, f64 *, 0x38);
                    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r4, 0x0, qr0 */);
                    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
                    spA8 = sp38;
                    sp40 = (f32) sp140 - temp_r4_4196->unkF70;
                    spB8 = sp38;
                    spB0 = (f64) sp40;
                    spC0 = (f64) sp40;
                    if ((((f32) spB0 * (f32) spB0) + (((f32) spA8 * (f32) spA8) + (unkspAC * unkspAC))) < 40000.0f) {
                        this->unk8 = ActivateNextSubgoal();
                        ActivateIfInactive();
                    }
                } else {
                    this->unk8 = ActivateNextSubgoal();
                    ActivateIfInactive();
                }
            } else {
                temp_r3_4241 = this->unk30;
                if (temp_r3_4241->IsActive() != 0) {
                    if ((u8) this->unk3E != 0) {
                        temp_r3_4252 = M2C_FIELD(this->unk20, u8 *, 0x49);
                        if (((temp_r3_4252 >> 6U) & 1) && !((temp_r3_4252 >> 5U) & 1)) {
                            sp118.GetPos();
                            sp128.GetPos();
                            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
                            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
                            sp88 = sp28;
                            sp30 = sp128.unk8 - sp120;
                            sp90 = (f64) sp30;
                            sp98 = sp28;
                            spA0 = (f64) sp30;
                            if (!((((f32) sp90 * (f32) sp90) + (((f32) sp88 * (f32) sp88) + (unksp8C * unksp8C))) < 40000.0f)) {
                                sp108.GetPos();
                                this->unkC->unk870.unk40.Set(*((MKVector3 *) &sp108), 0U);
                                temp_r3_4296 = this->unkC;
                                temp_r5_4298 = temp_r3_4296->unk8;
                                spF8 = M2C_FIELD(temp_r5_4298, f64 *, 0x30);
                                sp100 = M2C_FIELD(temp_r5_4298, f64 *, 0x38);
                                temp_r3_4296->unk870.unk40.Update(*((MKVector3 *) &spF8));
                                this->unkC->unk870.unk40.SetInsideRegion(1U);
                                this->unkC->unk870.unk40.SetInsideExclusionRegion(0U);
                                temp_r6_4315 = this->unk30;
                                M2C_FIELD(temp_r6_4315, TargetContext **, 0x10) = &this->unkC->unk870.unk40;
                                M2C_FIELD(temp_r6_4315, f32 *, 0x18) = 200.0f;
                                M2C_FIELD(temp_r6_4315, u8 *, 0x30) = (u8) (M2C_FIELD(temp_r6_4315, u8 *, 0x30) | 0x80);
                                M2C_FIELD(temp_r6_4315, s32 *, 0x20) = 0;
                                M2C_FIELD(temp_r6_4315, s32 *, 0x24) = 0;
                                M2C_FIELD(temp_r6_4315, s32 *, 0x28) = -1;
                                M2C_FIELD(temp_r6_4315, u8 *, 0x30) = (u8) (M2C_FIELD(temp_r6_4315, u8 *, 0x30) | 0x40);
                                M2C_FIELD(temp_r6_4315, u8 *, 0x30) = (u8) (M2C_FIELD(temp_r6_4315, u8 *, 0x30) | 0x20);
                                M2C_FIELD(temp_r6_4315, u8 *, 0x30) = (u8) (M2C_FIELD(temp_r6_4315, u8 *, 0x30) & ~0x10);
                            }
                        }
                    } else if (this->unkC->FollowPathToTarget(this->unk20) != 0) {
                        temp_r4_4344 = this->unkC;
                        temp_r3_4345 = temp_r4_4344->unk8;
                        spE8 = M2C_FIELD(temp_r3_4345, f64 *, 0x30);
                        spF0 = M2C_FIELD(temp_r3_4345, f64 *, 0x38);
                        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r4, 0x0, qr0 */);
                        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
                        sp68 = sp18;
                        sp20 = (f32) spF0 - temp_r4_4344->unkF70;
                        sp78 = sp18;
                        sp70 = (f64) sp20;
                        sp80 = (f64) sp20;
                        if (!((((f32) sp70 * (f32) sp70) + (((f32) sp68 * (f32) sp68) + (unksp6C * unksp6C))) < 40000.0f)) {
                            AddSubgoal__22CompositeGoal<6Cynder>FP13Goal<6Cynder>((CompositeGoal<Cynder> *) this, (Goal<Cynder> *) this->unk34);
                            temp_r8_4383 = this->unk34;
                            M2C_FIELD(temp_r8_4383, f32 *, 0x10) = (f32) this->unkC->unkF64;
                            M2C_FIELD(temp_r8_4383, f32 *, 0x14) = 10000.0f;
                            M2C_FIELD(temp_r8_4383, s32 *, 0x18) = 0xA;
                            M2C_FIELD(temp_r8_4383, s32 *, 0x20) = 6;
                            M2C_FIELD(temp_r8_4383, s32 *, 0x1C) = 0;
                            M2C_FIELD(temp_r8_4383, u8 *, 0x24) = (u8) (M2C_FIELD(temp_r8_4383, u8 *, 0x24) & ~0x20);
                            M2C_FIELD(temp_r8_4383, u8 *, 0x24) = (u8) (M2C_FIELD(temp_r8_4383, u8 *, 0x24) | 0x10);
                            M2C_FIELD(temp_r8_4383, u8 *, 0x24) = (u8) ((M2C_FIELD(temp_r8_4383, u8 *, 0x24) & ~8) | (((u32) M2C_ERROR(/* unknown instruction: mfcr $r7 */) >> 0x1CU) & 8));
                            M2C_FIELD(temp_r8_4383, u8 *, 0x24) = (u8) (M2C_FIELD(temp_r8_4383, u8 *, 0x24) & ~4);
                            this->unk8 = ActivateNextSubgoal();
                        }
                    } else {
                        temp_r3_4412 = this->unkC;
                        var_r30_4413 = 0;
                        if (((u8) M2C_FIELD(temp_r3_4412, u8 *, 0x908) == 2) || (temp_r3_4412->unk8C0.unk30.Get() != NULL)) {
                            var_r30_4413 = 1;
                        }
                        if (var_r30_4413 != 0) {
                            spC8.GetPos();
                            spD8.GetPos();
                            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
                            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
                            sp48 = sp8;
                            sp10 = spD8.unk8 - spD0;
                            sp50 = (f64) sp10;
                            sp58 = sp8;
                            sp60 = (f64) sp10;
                            if (!((((f32) sp50 * (f32) sp50) + (((f32) sp48 * (f32) sp48) + (unksp4C * unksp4C))) < 40000.0f)) {
                                temp_r3_4459 = M2C_FIELD(this->unk20, u8 *, 0x49);
                                if (((temp_r3_4459 >> 6U) & 1) && !((temp_r3_4459 >> 5U) & 1)) {
                                    this->unkC->unk870.unk40.SetDefaults();
                                    temp_r6_4469 = this->unk30;
                                    M2C_FIELD(temp_r6_4469, TargetContext **, 0x10) = (TargetContext *) this->unk20;
                                    M2C_FIELD(temp_r6_4469, f32 *, 0x18) = (f32) this->unk38;
                                    M2C_FIELD(temp_r6_4469, u8 *, 0x30) = (u8) (M2C_FIELD(temp_r6_4469, u8 *, 0x30) | 0x80);
                                    M2C_FIELD(temp_r6_4469, s32 *, 0x20) = 0;
                                    M2C_FIELD(temp_r6_4469, s32 *, 0x24) = 0;
                                    M2C_FIELD(temp_r6_4469, s32 *, 0x28) = -1;
                                    M2C_FIELD(temp_r6_4469, u8 *, 0x30) = (u8) (M2C_FIELD(temp_r6_4469, u8 *, 0x30) | 0x40);
                                    M2C_FIELD(temp_r6_4469, u8 *, 0x30) = (u8) (M2C_FIELD(temp_r6_4469, u8 *, 0x30) | 0x20);
                                    M2C_FIELD(temp_r6_4469, u8 *, 0x30) = (u8) (M2C_FIELD(temp_r6_4469, u8 *, 0x30) & ~0x10);
                                    this->unkC->unk638->SeekOn(this->unk20);
                                }
                            }
                        }
                    }
                }
            }
            if ((u8) this->unk8 == 2) {
                temp_r3_4498 = this->unk20;
                if (temp_r3_4498 != NULL) {
                    var_r30_4502 = 0;
                    if (((u8) M2C_FIELD(temp_r3_4498, u8 *, 0x48) == 2) || (temp_r3_4498->unk40.Get() != NULL)) {
                        var_r30_4502 = 1;
                    }
                    if ((var_r30_4502 != 0) && (this->unk20->GetDist() > this->unk38)) {
                        this->unk8 = 3;
                    }
                }
            }
            return this->unk8;
        }
    }
block_6:
    this->unk8 = 3;
    return this->unk8;
}
#endif

#if 0 // DRAFT: undefined identifier 'Update'
void CynderBossGoal_MoveToTarget::Activate() {
    f64 spD0;
    f64 spC8;
    f64 spC0;
    f64 spB8;
    f64 spB0;
    f64 spA8;
    M2C_UNK sp98;
    f32 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f32 sp10;
    AITargetData *temp_r3_4542;
    AITargetData *temp_r3_4779;
    Cynder *temp_r3_4566;
    Cynder *temp_r3_4574;
    Cynder *temp_r5_4583;
    Cynder *temp_r6_4789;
    Goal<Cynder> *temp_r4_4685;
    Goal<Cynder> *temp_r6_4701;
    Goal<Cynder> *temp_r6_4754;
    Goal<Cynder> *temp_r6_4869;
    Goal<Cynder> *temp_r7_4622;
    f32 temp_f2_4799;
    f32 temp_f3_4796;
    f32 temp_f5_4795;
    u32 temp_r0_4734;
    u8 temp_r0_4732;
    u8 temp_r30_4828;
    u8 temp_r4_4780;
    u8 var_r30_4546;
    void **temp_r3_4858;
    void *temp_r3_4584;
    void *temp_r3_4653;
    void *temp_r5_4576;

    this->unk8 = 0;
    RemoveAllSubgoals();
    temp_r3_4542 = this->unk20;
    if (temp_r3_4542 != NULL) {
        var_r30_4546 = 0;
        if (((u8) M2C_FIELD(temp_r3_4542, u8 *, 0x48) == 2) || (temp_r3_4542->unk40.Get() != NULL)) {
            var_r30_4546 = 1;
        }
        if (var_r30_4546 == 0) {
            goto block_5;
        }
        this->unk3C = 0;
        this->unk3E = 0;
        temp_r3_4566 = this->unkC;
        if (M2C_BITWISE(u32, temp_r3_4566->unkF64) != 0U) {
            if (temp_r3_4566->FollowPathToTarget(this->unk20) != 0) {
                temp_r3_4574 = this->unkC;
                temp_r5_4576 = temp_r3_4574->unk8;
                spC8 = M2C_FIELD(temp_r5_4576, f64 *, 0x30);
                spD0 = M2C_FIELD(temp_r5_4576, f64 *, 0x38);
                temp_r3_4574->unk870.unk40.Update(*((MKVector3 *) &spC8));
                temp_r5_4583 = this->unkC;
                temp_r3_4584 = temp_r5_4583->unk8;
                spB8 = M2C_FIELD(temp_r3_4584, f64 *, 0x30);
                spC0 = M2C_FIELD(temp_r3_4584, f64 *, 0x38);
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r4, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
                sp58 = sp18;
                sp20 = (f32) spC0 - temp_r5_4583->unkF70;
                sp68 = sp18;
                sp60 = (f64) sp20;
                sp70 = (f64) sp20;
                if (!((((f32) sp60 * (f32) sp60) + (((f32) sp58 * (f32) sp58) + (unksp5C * unksp5C))) < 40000.0f)) {
                    AddSubgoal__22CompositeGoal<6Cynder>FP13Goal<6Cynder>((CompositeGoal<Cynder> *) this, (Goal<Cynder> *) this->unk34);
                    temp_r7_4622 = this->unk34;
                    M2C_FIELD(temp_r7_4622, f32 *, 0x10) = (f32) this->unkC->unkF64;
                    M2C_FIELD(temp_r7_4622, f32 *, 0x14) = 10000.0f;
                    M2C_FIELD(temp_r7_4622, s32 *, 0x18) = 0xA;
                    M2C_FIELD(temp_r7_4622, s32 *, 0x20) = 6;
                    M2C_FIELD(temp_r7_4622, s32 *, 0x1C) = 0;
                    M2C_FIELD(temp_r7_4622, u8 *, 0x24) = (u8) (M2C_FIELD(temp_r7_4622, u8 *, 0x24) & ~0x20);
                    M2C_FIELD(temp_r7_4622, u8 *, 0x24) = (u8) (M2C_FIELD(temp_r7_4622, u8 *, 0x24) | 0x10);
                    M2C_FIELD(temp_r7_4622, u8 *, 0x24) = (u8) ((M2C_FIELD(temp_r7_4622, u8 *, 0x24) & ~8) | (((u32) M2C_ERROR(/* unknown instruction: mfcr $r6 */) >> 0x1CU) & 8));
                    M2C_FIELD(temp_r7_4622, u8 *, 0x24) = (u8) (M2C_FIELD(temp_r7_4622, u8 *, 0x24) & ~4);
                    this->unk3C = 1;
                    goto block_12;
                }
                sp98.GetPos();
                temp_r3_4653 = this->unkC->unk8;
                spA8 = M2C_FIELD(temp_r3_4653, f64 *, 0x30);
                spB0 = M2C_FIELD(temp_r3_4653, f64 *, 0x38);
                M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
                sp38 = sp8;
                sp10 = (f32) spB0 - spA0;
                sp48 = sp8;
                sp40 = (f64) sp10;
                sp50 = (f64) sp10;
                if ((((f32) sp40 * (f32) sp40) + (((f32) sp38 * (f32) sp38) + (unksp3C * unksp3C))) < 40000.0f) {
                    AddSubgoal__22CompositeGoal<6Cynder>FP13Goal<6Cynder>((CompositeGoal<Cynder> *) this, (Goal<Cynder> *) this->unk24);
                    temp_r4_4685 = this->unk24;
                    M2C_FIELD(temp_r4_4685, s32 *, 0x10) = 1;
                    M2C_FIELD(temp_r4_4685, s32 *, 0x14) = 0xA;
                    return;
                }
block_12:
                AddSubgoal__22CompositeGoal<6Cynder>FP13Goal<6Cynder>((CompositeGoal<Cynder> *) this, (Goal<Cynder> *) this->unk30);
                this->unkC->unk870.unk40.SetInsideRegion(1U);
                temp_r6_4701 = this->unk30;
                M2C_FIELD(temp_r6_4701, TargetContext **, 0x10) = &this->unkC->unk870.unk40;
                M2C_FIELD(temp_r6_4701, f32 *, 0x18) = 200.0f;
                M2C_FIELD(temp_r6_4701, u8 *, 0x30) = (u8) (M2C_FIELD(temp_r6_4701, u8 *, 0x30) | 0x80);
                M2C_FIELD(temp_r6_4701, s32 *, 0x20) = 0;
                M2C_FIELD(temp_r6_4701, s32 *, 0x24) = 0;
                M2C_FIELD(temp_r6_4701, s32 *, 0x28) = -1;
                M2C_FIELD(temp_r6_4701, u8 *, 0x30) = (u8) (M2C_FIELD(temp_r6_4701, u8 *, 0x30) | 0x40);
                M2C_FIELD(temp_r6_4701, u8 *, 0x30) = (u8) (M2C_FIELD(temp_r6_4701, u8 *, 0x30) | 0x20);
                M2C_FIELD(temp_r6_4701, u8 *, 0x30) = (u8) (M2C_FIELD(temp_r6_4701, u8 *, 0x30) & ~0x10);
                M2C_FIELD(this->unk30, AITargetData **, 0x14) = (AITargetData *) this->unk20;
                return;
            }
            goto block_18;
        }
        if (((u8) M2C_FIELD(temp_r3_4566, u8 *, 0xD01) != 0) && ((temp_r0_4732 = M2C_FIELD(this->unk20, u8 *, 0x49), temp_r0_4734 = (temp_r0_4732 >> 5U) & 1, ((((temp_r0_4732 >> 6U) & 1) == 0) != 0)) || (temp_r0_4734 != 0))) {
            CalculateRegionEdgeMoveTarget(temp_r0_4734 == 0);
            if (this->unkC->unk870.unk40.GetDist() > 200.0f) {
                AddSubgoal__22CompositeGoal<6Cynder>FP13Goal<6Cynder>((CompositeGoal<Cynder> *) this, (Goal<Cynder> *) this->unk30);
                temp_r6_4754 = this->unk30;
                M2C_FIELD(temp_r6_4754, TargetContext **, 0x10) = &this->unkC->unk870.unk40;
                M2C_FIELD(temp_r6_4754, f32 *, 0x18) = 200.0f;
                M2C_FIELD(temp_r6_4754, u8 *, 0x30) = (u8) (M2C_FIELD(temp_r6_4754, u8 *, 0x30) | 0x80);
                M2C_FIELD(temp_r6_4754, s32 *, 0x20) = 0;
                M2C_FIELD(temp_r6_4754, s32 *, 0x24) = 0;
                M2C_FIELD(temp_r6_4754, s32 *, 0x28) = -1;
                M2C_FIELD(temp_r6_4754, u8 *, 0x30) = (u8) (M2C_FIELD(temp_r6_4754, u8 *, 0x30) | 0x40);
                M2C_FIELD(temp_r6_4754, u8 *, 0x30) = (u8) (M2C_FIELD(temp_r6_4754, u8 *, 0x30) | 0x20);
                M2C_FIELD(temp_r6_4754, u8 *, 0x30) = (u8) (M2C_FIELD(temp_r6_4754, u8 *, 0x30) & ~0x10);
                this->unk3E = 1;
                return;
            }
        }
block_18:
        temp_r3_4779 = this->unk20;
        temp_r4_4780 = M2C_FIELD(temp_r3_4779, u8 *, 0x49);
        if (((temp_r4_4780 >> 6U) & 1) && !((temp_r4_4780 >> 5U) & 1) && (temp_r3_4779->GetDist() > this->unk38)) {
            temp_r6_4789 = this->unkC;
            temp_f5_4795 = temp_r6_4789->unkC0;
            temp_f3_4796 = temp_r6_4789->unkC8;
            temp_f2_4799 = temp_r6_4789->unkC4;
            sp30 = (MKVector3::up.unk0 * temp_f2_4799) - (MKVector3::up.unk4 * temp_f5_4795);
            sp2C = (MKVector3::up.unk8 * temp_f5_4795) - (MKVector3::up.unk0 * temp_f3_4796);
            sp28 = (MKVector3::up.unk4 * temp_f3_4796) - (MKVector3::up.unk8 * temp_f2_4799);
            sp80 = (f64) sp30;
            sp78 = (f64) sp28;
            sp88.GetDir();
            M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
            temp_r30_4828 = ((u32) M2C_ERROR(/* unknown instruction: mfcr $r3 */) >> 0x1DU) & 1;
            if (((u8) this->unk3D != 0) && (this->unkC->unk838.unk28.GetDist() > 1500.0f) && (this->unkC->unk838.unk28.GetDist() < 2200.0f) && (this->unkC->CanLeap(temp_r30_4828) != 0)) {
                AddSubgoal__22CompositeGoal<6Cynder>FP13Goal<6Cynder>((CompositeGoal<Cynder> *) this, (Goal<Cynder> *) this->unk2C);
                AddSubgoal__22CompositeGoal<6Cynder>FP13Goal<6Cynder>((CompositeGoal<Cynder> *) this, (Goal<Cynder> *) this->unk28);
                M2C_FIELD(this->unk2C, f32 **, 0x10) = &this->unkC->unk838.unk28;
                temp_r3_4858 = this->unk28;
                M2C_FIELD(temp_r3_4858, u8 *, 0x20) = (u8) ((M2C_FIELD(temp_r3_4858, u8 *, 0x20) & ~0x40) | ((temp_r30_4828 << 6) & 0x40));
                return;
            }
            AddSubgoal__22CompositeGoal<6Cynder>FP13Goal<6Cynder>((CompositeGoal<Cynder> *) this, (Goal<Cynder> *) this->unk30);
            temp_r6_4869 = this->unk30;
            M2C_FIELD(temp_r6_4869, TargetContext **, 0x10) = (TargetContext *) this->unk20;
            M2C_FIELD(temp_r6_4869, f32 *, 0x18) = (f32) this->unk38;
            M2C_FIELD(temp_r6_4869, u8 *, 0x30) = (u8) (M2C_FIELD(temp_r6_4869, u8 *, 0x30) | 0x80);
            M2C_FIELD(temp_r6_4869, s32 *, 0x20) = 0;
            M2C_FIELD(temp_r6_4869, s32 *, 0x24) = 0;
            M2C_FIELD(temp_r6_4869, s32 *, 0x28) = -1;
            M2C_FIELD(temp_r6_4869, u8 *, 0x30) = (u8) (M2C_FIELD(temp_r6_4869, u8 *, 0x30) | 0x40);
            M2C_FIELD(temp_r6_4869, u8 *, 0x30) = (u8) (M2C_FIELD(temp_r6_4869, u8 *, 0x30) | 0x20);
            M2C_FIELD(temp_r6_4869, u8 *, 0x30) = (u8) (M2C_FIELD(temp_r6_4869, u8 *, 0x30) & ~0x10);
            return;
        }
        this->unk8 = 2;
        return;
    }
block_5:
    this->unk8 = 3;
}
#endif

void CynderBossGoal_MoveToTarget::Deinit() {
    Goal<Cynder> *temp_r3_4910;
    Goal<Cynder> *temp_r3_4920;
    Goal<Cynder> *temp_r3_4925;
    Goal<Cynder> *temp_r3_4930;
    MKHeap *temp_r3_4948;
    void **temp_r3_4915;
    void *temp_r31_4945;

    temp_r3_4910 = this->unk24;
    temp_r3_4910->Deinit();
    temp_r3_4915 = this->unk28;
    M2C_FIELD(*temp_r3_4915, M2C_UNK (**)(void **), 0xC)(temp_r3_4915);
    temp_r3_4920 = this->unk2C;
    temp_r3_4920->Deinit();
    temp_r3_4925 = this->unk30;
    temp_r3_4925->Deinit();
    temp_r3_4930 = this->unk34;
    temp_r3_4930->Deinit();
    operator delete(this->unk24);
    operator delete(this->unk28);
    operator delete(this->unk2C);
    operator delete(this->unk30);
    operator delete(this->unk34);
    temp_r31_4945 = this->unk1C;
    if (temp_r31_4945 != NULL) {
        temp_r3_4948 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_4948 != NULL) {
            ((MKHeap *) (temp_r3_4948->Current()))->Free(temp_r31_4945, NULL, 0);
        } else {
            free(temp_r31_4945);
        }
        this->unk1C = NULL;
    }
    this->unk10 = 0;
    this->unk18 = 0;
    this->unk14 = 0;
    this->unk8 = 1;
    this->unkC = NULL;
    this->unk9 = 0;
}

#if 0 // DRAFT: pointer/array required
void CynderBossGoal_MoveToTarget::Init(Cynder *arg0) {
    Goal<Cynder> *temp_r4_5122;
    Goal<Cynder> *temp_r4_5144;
    Goal<Cynder> *temp_r4_5155;
    Goal<Cynder> *temp_r4_5172;
    MKHeap *temp_r3_5095;
    void **temp_r4_5133;
    void *var_r3_5102;

    if ((u8) this->unk9 == 0) {
        operator new(0x1CU, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__13Goal<6Cynder>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk24 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x28U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__13Goal<6Cynder>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk28 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x14U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk2C = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x34U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk30 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x28U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk34 = M2C_ERROR(/* Read from unset register $r3 */);
    }
    if ((u8) this->unk9 == 0) {
        temp_r3_5095 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_5095 != NULL) {
            var_r3_5102 = ((MKHeap *) (temp_r3_5095->Current()))->Alloc(0xC, NULL, 0);
        } else {
            var_r3_5102 = malloc(0xC);
        }
        this->unk1C = var_r3_5102;
        this->unk10 = 3;
    }
    this->unk8 = 1;
    this->unkC = arg0;
    this->unk4 = 0xBD;
    if ((Cynder *) this->unkC != NULL) {
        this->unk9 = 1;
    }
    temp_r4_5122 = this->unk24;
    M2C_FIELD(temp_r4_5122, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_5122, Cynder **, 0xC) = arg0;
    M2C_FIELD(temp_r4_5122, s32 *, 4) = 0xAA;
    if ((Cynder *) M2C_FIELD(temp_r4_5122, Cynder **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_5122, s8 *, 9) = 1;
    }
    temp_r4_5133 = this->unk28;
    M2C_FIELD(temp_r4_5133, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_5133, Cynder **, 0xC) = arg0;
    M2C_FIELD(temp_r4_5133, s32 *, 4) = 0xA9;
    if ((Cynder *) M2C_FIELD(temp_r4_5133, Cynder **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_5133, s8 *, 9) = 1;
    }
    temp_r4_5144 = this->unk2C;
    M2C_FIELD(temp_r4_5144, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_5144, Cynder **, 0xC) = arg0;
    M2C_FIELD(temp_r4_5144, s32 *, 4) = 0x27;
    if ((Cynder *) M2C_FIELD(temp_r4_5144, Cynder **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_5144, s8 *, 9) = 1;
    }
    temp_r4_5155 = this->unk30;
    M2C_FIELD(temp_r4_5155, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_5155, Cynder **, 0xC) = arg0;
    M2C_FIELD(temp_r4_5155, s32 *, 4) = 0x21;
    if ((Cynder *) M2C_FIELD(temp_r4_5155, Cynder **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_5155, s8 *, 9) = 1;
    }
    M2C_FIELD(temp_r4_5155, u8 *, 0x30) = (u8) (M2C_FIELD(temp_r4_5155, u8 *, 0x30) & ~0x10);
    temp_r4_5172 = this->unk34;
    M2C_FIELD(temp_r4_5172, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_5172, Cynder **, 0xC) = arg0;
    M2C_FIELD(temp_r4_5172, s32 *, 4) = 0x22;
    if ((Cynder *) M2C_FIELD(temp_r4_5172, Cynder **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_5172, s8 *, 9) = 1;
    }
}
#endif

void CynderBossGoal_TestTaunt::Terminate() {
    this->unk8 = 1;
}

u8 CynderBossGoal_TestTaunt::Update() {
    ActivateIfInactive();
    if (this->unkC->HasAnimFinished() != 0) {
        this->unk8 = 2;
    }
    return this->unk8;
}

#if 0 // DRAFT: illegal implicit conversion from 'AnimSequenceType' to
void CynderBossGoal_TestTaunt::Activate() {
    Character *temp_r3_5233;

    this->unk8 = 0;
    this->unkC->StopMovement(1U);
    temp_r3_5233 = this->unkC;
    temp_r3_5233->unkA0 = 0.0f;
    temp_r3_5233->unkA4 = 0.0f;
    temp_r3_5233->unkA8 = 0.0f;
    this->unkC->SetAnim((AnimSequenceType) 1, 3, 0, 0.15f, 0U, 0U);
}
#endif

void CynderBossGoal_TestMode::Terminate() {
    this->unk8 = 1;
    RemoveAllSubgoals();
}

#if 0 // DRAFT: undefined identifier 'unk30C'
u8 CynderBossGoal_TestMode::Update() {
    Cynder *temp_r3_5291;
    Cynder *temp_r5_5317;
    Cynder *temp_r6_5310;
    EnemyDescriptor *temp_r4_5292;
    Goal<Cynder> *temp_r4_5312;
    Goal<Cynder> *temp_r4_5318;
    Goal<Cynder> *temp_r5_5361;
    Goal<Cynder> *temp_r5_5369;
    s32 var_r3_5342;
    u8 var_r3_5328;
    void **temp_r3_5277;

    ActivateIfInactive();
    temp_r3_5277 = this->unk30;
    if (M2C_FIELD(*temp_r3_5277, u8 (**)(void **), 0x28)(temp_r3_5277) != 0) {
        M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
        if (gb.unk30C == this->unk50) {
            temp_r3_5291 = this->unkC;
            temp_r4_5292 = temp_r3_5291->unkA38;
            if ((temp_r4_5292 != NULL) && ((s32) temp_r4_5292->unk6C == 6)) {
                temp_r3_5291->CalcFlightPathData2();
                RemoveAllSubgoals();
                AddSubgoal__22CompositeGoal<6Cynder>FP13Goal<6Cynder>((CompositeGoal<Cynder> *) this, (Goal<Cynder> *) this->unk34);
                AddSubgoal__22CompositeGoal<6Cynder>FP13Goal<6Cynder>((CompositeGoal<Cynder> *) this, (Goal<Cynder> *) this->unk40);
                AddSubgoal__22CompositeGoal<6Cynder>FP13Goal<6Cynder>((CompositeGoal<Cynder> *) this, (Goal<Cynder> *) this->unk44);
                temp_r6_5310 = this->unkC;
                temp_r4_5312 = this->unk40;
                M2C_FIELD(temp_r4_5312, f32 **, 0x10) = &temp_r6_5310->unkF88;
                M2C_FIELD(temp_r4_5312, s32 *, 0x14) = (s32) temp_r6_5310->unkFFC;
                temp_r5_5317 = this->unkC;
                temp_r4_5318 = this->unk44;
                M2C_FIELD(temp_r4_5318, AITargetData **, 0x10) = (AITargetData *) temp_r5_5317->unkFF0;
                M2C_FIELD(temp_r4_5318, f32 *, 0x14) = (f32) temp_r5_5317->unkFF4;
                M2C_FIELD(temp_r4_5318, u8 *, 0x24) = (u8) (M2C_FIELD(temp_r4_5318, u8 *, 0x24) & ~0x40);
            }
        }
    }
    var_r3_5328 = 0;
    if (((u8) M2C_FIELD(gb.unk354, u8 *, 5) != 0) || ((u8) M2C_FIELD(gb.unk354, u8 *, 4) != 0)) {
        var_r3_5328 = 1;
    }
    if (var_r3_5328 != 0) {
        var_r3_5342 = 0;
    } else {
        var_r3_5342 = MKInput_Pressed(0, (MKInputDevices) M2C_FIELD(gb.unk354, s32 *, 0));
    }
    if ((u8) var_r3_5342 != 0) {
        this->unkC->CalcLandingFlightPathData();
        AddSubgoal__22CompositeGoal<6Cynder>FP13Goal<6Cynder>((CompositeGoal<Cynder> *) this, (Goal<Cynder> *) this->unk48);
        AddSubgoal__22CompositeGoal<6Cynder>FP13Goal<6Cynder>((CompositeGoal<Cynder> *) this, (Goal<Cynder> *) this->unk4C);
        temp_r5_5361 = this->unk44;
        M2C_FIELD(temp_r5_5361, f32 *, 0x18) = (f32) this->unkC->unkFF8;
        M2C_FIELD(temp_r5_5361, u8 *, 0x24) = (u8) (M2C_FIELD(temp_r5_5361, u8 *, 0x24) | 0x80);
        temp_r5_5369 = this->unk48;
        M2C_FIELD(temp_r5_5369, f32 **, 0x10) = &this->unkC->unkCD4;
        M2C_FIELD(temp_r5_5369, f32 *, 0x14) = 0.0f;
        M2C_FIELD(temp_r5_5369, u8 *, 0x24) = (u8) (M2C_FIELD(temp_r5_5369, u8 *, 0x24) | 0x40);
    }
    this->unk8 = UpdateSubgoals();
    return this->unk8;
}
#endif

#if 0 // DRAFT: illegal token
void CynderBossGoal_TestMode::Activate() {
    Goal<Cynder> *temp_r5_5413;
    void **temp_r5_5404;

    this->unk8 = 0;
    RemoveAllSubgoals();
    AddSubgoal__22CompositeGoal<6Cynder>FP13Goal<6Cynder>((CompositeGoal<Cynder> *) this, (Goal<Cynder> *) this->unk30);
    temp_r5_5404 = this->unk30;
    M2C_FIELD(temp_r5_5404, f32 **, 0x20) = &this->unkC->unk838.unk28;
    M2C_FIELD(temp_r5_5404, f32 *, 0x38) = 1000.0f;
    M2C_FIELD(temp_r5_5404, s8 *, 0x3D) = 1;
    AddSubgoal__22CompositeGoal<6Cynder>FP13Goal<6Cynder>((CompositeGoal<Cynder> *) this, (Goal<Cynder> *) this->unk20);
    temp_r5_5413 = this->unk20;
    M2C_FIELD(temp_r5_5413, s32 *, 0x10) = 1;
    M2C_FIELD(temp_r5_5413, s32 *, 0x14) = 0xA;
    this->unk50 = gb.unk30C + 5.0f;
}
#endif

void CynderBossGoal_TestMode::Deinit() {
    Goal<Cynder> *temp_r3_5439;
    Goal<Cynder> *temp_r3_5464;
    Goal<Cynder> *temp_r3_5479;
    Goal<Cynder> *temp_r3_5484;
    Goal<Cynder> *temp_r3_5489;
    Goal<Cynder> *temp_r3_5494;
    MKHeap *temp_r3_5526;
    void **temp_r3_5444;
    void **temp_r3_5449;
    void **temp_r3_5454;
    void **temp_r3_5459;
    void **temp_r3_5469;
    void **temp_r3_5474;
    void *temp_r31_5523;

    temp_r3_5439 = this->unk20;
    temp_r3_5439->Deinit();
    temp_r3_5444 = this->unk24;
    M2C_FIELD(*temp_r3_5444, M2C_UNK (**)(void **), 0xC)(temp_r3_5444);
    temp_r3_5449 = this->unk28;
    M2C_FIELD(*temp_r3_5449, M2C_UNK (**)(void **), 0xC)(temp_r3_5449);
    temp_r3_5454 = this->unk2C;
    M2C_FIELD(*temp_r3_5454, M2C_UNK (**)(void **), 0xC)(temp_r3_5454);
    temp_r3_5459 = this->unk30;
    M2C_FIELD(*temp_r3_5459, M2C_UNK (**)(void **), 0xC)(temp_r3_5459);
    temp_r3_5464 = this->unk34;
    temp_r3_5464->Deinit();
    temp_r3_5469 = this->unk38;
    M2C_FIELD(*temp_r3_5469, M2C_UNK (**)(void **), 0xC)(temp_r3_5469);
    temp_r3_5474 = this->unk3C;
    M2C_FIELD(*temp_r3_5474, M2C_UNK (**)(void **), 0xC)(temp_r3_5474);
    temp_r3_5479 = this->unk40;
    temp_r3_5479->Deinit();
    temp_r3_5484 = this->unk44;
    temp_r3_5484->Deinit();
    temp_r3_5489 = this->unk4C;
    temp_r3_5489->Deinit();
    temp_r3_5494 = this->unk48;
    temp_r3_5494->Deinit();
    operator delete(this->unk20);
    operator delete(this->unk24);
    operator delete(this->unk28);
    operator delete(this->unk2C);
    operator delete(this->unk30);
    operator delete(this->unk34);
    operator delete(this->unk38);
    operator delete(this->unk3C);
    operator delete(this->unk40);
    operator delete(this->unk44);
    operator delete(this->unk48);
    operator delete(this->unk4C);
    temp_r31_5523 = this->unk1C;
    if (temp_r31_5523 != NULL) {
        temp_r3_5526 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_5526 != NULL) {
            ((MKHeap *) (temp_r3_5526->Current()))->Free(temp_r31_5523, NULL, 0);
        } else {
            free(temp_r31_5523);
        }
        this->unk1C = NULL;
    }
    this->unk10 = 0;
    this->unk18 = 0;
    this->unk14 = 0;
    this->unk8 = 1;
    this->unkC = NULL;
    this->unk9 = 0;
}

#if 0 // DRAFT: pointer/array required
void CynderBossGoal_TestMode::Init(Cynder *arg0) {
    Goal<Cynder> *temp_r4_5861;
    Goal<Cynder> *temp_r4_5912;
    Goal<Cynder> *temp_r4_5929;
    Goal<Cynder> *temp_r4_5940;
    Goal<Cynder> *temp_r4_5951;
    Goal<Cynder> *temp_r4_5962;
    MKHeap *temp_r3_5834;
    void **temp_r4_5872;
    void **temp_r4_5883;
    void **temp_r4_5900;
    void *var_r3_5841;

    if ((u8) this->unk9 == 0) {
        operator new(0x1CU, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__13Goal<6Cynder>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk20 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x10U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__13Goal<6Cynder>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk24 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x34U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk28 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x1CU, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__13Goal<6Cynder>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk2C = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x40U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__13Goal<6Cynder>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__22CompositeGoal<6Cynder>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x1C) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x18) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x10) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x14) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk30 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x10U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__13Goal<6Cynder>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk34 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x3CU, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__13Goal<6Cynder>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__22CompositeGoal<6Cynder>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x1C) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x18) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x10) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x14) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk38 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x40U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__13Goal<6Cynder>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__22CompositeGoal<6Cynder>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x1C) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x18) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x10) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x14) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk3C = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x1CU, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__13Goal<6Cynder>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk40 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x28U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__13Goal<6Cynder>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk44 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x28U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__13Goal<6Cynder>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk48 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x10U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__13Goal<6Cynder>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk4C = M2C_ERROR(/* Read from unset register $r3 */);
    }
    if ((u8) this->unk9 == 0) {
        temp_r3_5834 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_5834 != NULL) {
            var_r3_5841 = ((MKHeap *) (temp_r3_5834->Current()))->Alloc(0x14, NULL, 0);
        } else {
            var_r3_5841 = malloc(0x14);
        }
        this->unk1C = var_r3_5841;
        this->unk10 = 5;
    }
    this->unk8 = 1;
    this->unkC = arg0;
    this->unk4 = 0x99;
    if ((Cynder *) this->unkC != NULL) {
        this->unk9 = 1;
    }
    temp_r4_5861 = this->unk20;
    M2C_FIELD(temp_r4_5861, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_5861, Cynder **, 0xC) = arg0;
    M2C_FIELD(temp_r4_5861, s32 *, 4) = 0xAA;
    if ((Cynder *) M2C_FIELD(temp_r4_5861, Cynder **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_5861, s8 *, 9) = 1;
    }
    temp_r4_5872 = this->unk24;
    M2C_FIELD(temp_r4_5872, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_5872, Cynder **, 0xC) = arg0;
    M2C_FIELD(temp_r4_5872, s32 *, 4) = 0x99;
    if ((Cynder *) M2C_FIELD(temp_r4_5872, Cynder **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_5872, s8 *, 9) = 1;
    }
    temp_r4_5883 = this->unk28;
    M2C_FIELD(temp_r4_5883, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_5883, Cynder **, 0xC) = arg0;
    M2C_FIELD(temp_r4_5883, s32 *, 4) = 0x21;
    if ((Cynder *) M2C_FIELD(temp_r4_5883, Cynder **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_5883, s8 *, 9) = 1;
    }
    M2C_FIELD(temp_r4_5883, u8 *, 0x30) = (u8) (M2C_FIELD(temp_r4_5883, u8 *, 0x30) & ~0x10);
    temp_r4_5900 = this->unk2C;
    M2C_FIELD(temp_r4_5900, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_5900, Cynder **, 0xC) = arg0;
    M2C_FIELD(temp_r4_5900, s32 *, 4) = 0xAC;
    if ((Cynder *) M2C_FIELD(temp_r4_5900, Cynder **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_5900, s8 *, 9) = 1;
    }
    this->unk30->Init(arg0);
    temp_r4_5912 = this->unk34;
    M2C_FIELD(temp_r4_5912, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_5912, Cynder **, 0xC) = arg0;
    M2C_FIELD(temp_r4_5912, s32 *, 4) = 0x9C;
    if ((Cynder *) M2C_FIELD(temp_r4_5912, Cynder **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_5912, s8 *, 9) = 1;
    }
    this->unk38->Init(arg0);
    this->unk3C->Init(arg0);
    temp_r4_5929 = this->unk40;
    M2C_FIELD(temp_r4_5929, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_5929, Cynder **, 0xC) = arg0;
    M2C_FIELD(temp_r4_5929, s32 *, 4) = 0xAE;
    if ((Cynder *) M2C_FIELD(temp_r4_5929, Cynder **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_5929, s8 *, 9) = 1;
    }
    temp_r4_5940 = this->unk44;
    M2C_FIELD(temp_r4_5940, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_5940, Cynder **, 0xC) = arg0;
    M2C_FIELD(temp_r4_5940, s32 *, 4) = 0xAD;
    if ((Cynder *) M2C_FIELD(temp_r4_5940, Cynder **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_5940, s8 *, 9) = 1;
    }
    temp_r4_5951 = this->unk48;
    M2C_FIELD(temp_r4_5951, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_5951, Cynder **, 0xC) = arg0;
    M2C_FIELD(temp_r4_5951, s32 *, 4) = 0xAD;
    if ((Cynder *) M2C_FIELD(temp_r4_5951, Cynder **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_5951, s8 *, 9) = 1;
    }
    temp_r4_5962 = this->unk4C;
    M2C_FIELD(temp_r4_5962, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_5962, Cynder **, 0xC) = arg0;
    M2C_FIELD(temp_r4_5962, s32 *, 4) = 0x9D;
    if ((Cynder *) M2C_FIELD(temp_r4_5962, Cynder **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_5962, s8 *, 9) = 1;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk30C'
void CynderBossGoal_BreathAttack::Terminate() {
    AttackerManager *var_r3_6041;
    CharacterFireFX *temp_r5_5996;
    Enemy *temp_r3_5991;
    Enemy *temp_r3_5995;
    Enemy *temp_r3_6012;
    Enemy *temp_r3_6021;
    Enemy *var_r4_6048;
    u8 var_r30_6022;
    void *temp_r4_6013;

    M2C_FIELD(this->unkC, s8 *, 0xD00) = 0;
    temp_r3_5991 = this->unkC;
    M2C_FIELD(temp_r3_5991, u8 *, 0xB08) = (u8) (M2C_FIELD(temp_r3_5991, u8 *, 0xB08) & ~0x10);
    temp_r3_5995 = this->unkC;
    temp_r5_5996 = temp_r3_5995->unkA08;
    if (temp_r5_5996 != NULL) {
        this->unkC->unkA7C = gb.unk30C + temp_r3_5995->unkA20->GetEnemyAttackSetting((EnemySettingType) 6, (EnemyAttack *) temp_r5_5996);
    }
    this->unkC->unkA08 = NULL;
    temp_r3_6012 = this->unkC;
    temp_r4_6013 = temp_r3_6012->unkA44;
    if (temp_r4_6013 != NULL) {
        M2C_FIELD(temp_r4_6013, u8 *, 0x10) = (u8) ((M2C_FIELD(temp_r4_6013, u8 *, 0x10) & ~0x80) | ((M2C_FIELD(temp_r3_6012, u8 *, 0xB08) << 6) & 0x80));
    }
    temp_r3_6021 = this->unkC;
    var_r30_6022 = 0;
    if (((u8) M2C_FIELD(temp_r3_6021, u8 *, 0x8B8) == 2) || (temp_r3_6021->unk870.unk30.Get() != NULL)) {
        var_r30_6022 = 1;
    }
    if (var_r30_6022 != 0) {
        var_r3_6041 = M2C_FIELD(this->unkC->unk870.unk30.Get()->__vptr, AttackerManager *(**)(), 0x48)();
    } else {
        var_r3_6041 = NULL;
    }
    if (var_r3_6041 != NULL) {
        var_r4_6048 = this->unkC;
        if (var_r4_6048 != NULL) {
            var_r4_6048 += 0x6B8;
        }
        var_r3_6041->Remove((Targetable *) var_r4_6048, 2);
    }
    this->unkC->SetInvulnerableToMeleeAttacks(0U, 1U);
    this->unkC->SetInvulnerableToBreathAttacks(0U, 1U);
    ((CynderBreathFX *) (M2C_FIELD(this->unkC, CynderBreathFX **, 0xCEC)))->End();
}
#endif

#if 0 // DRAFT: expression syntax error
u8 CynderBossGoal_BreathAttack::Update() {
    f64 sp248;
    f64 sp240;
    AITargetData sp1F0;
    MKVector3 sp1E0;
    f64 sp1D8;
    f64 sp1D0;
    f64 sp1C8;
    f64 sp1C0;
    f64 sp1B8;
    f64 sp1B0;
    f64 sp1A8;
    f64 sp1A0;
    MKVector3 sp190;
    f64 sp188;
    f64 sp180;
    f64 sp178;
    f64 sp170;
    M2C_UNK sp160;
    MKVector3 sp150;
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
    MKVector3 spE0;
    f32 spD8;
    f32 spD4;
    f32 spD0;
    f32 spC8;
    f32 spC4;
    f32 spC0;
    f32 spB8;
    f32 spA8;
    f32 sp98;
    f32 sp88;
    f32 sp78;
    f32 sp74;
    f32 sp70;
    f32 sp68;
    f32 sp58;
    f32 sp48;
    f32 sp38;
    f32 sp28;
    f32 sp18;
    f32 sp8;
    CharacterFireFX *temp_r29_6172;
    Enemy *temp_r29_6537;
    Enemy *temp_r29_6563;
    Enemy *temp_r30_6169;
    Enemy *temp_r3_6101;
    Enemy *temp_r3_6229;
    Enemy *temp_r3_6349;
    Enemy *temp_r3_6355;
    Enemy *temp_r3_6519;
    Enemy *temp_r3_6555;
    Enemy *temp_r3_6584;
    Enemy *temp_r4_6119;
    Enemy *temp_r4_6132;
    EnemyDescriptor *temp_r4_6231;
    EnemyDescriptor *temp_r4_6543;
    EnemyDescriptor *temp_r4_6558;
    EnemyDescriptor *temp_r4_6569;
    f32 temp_f2_6211;
    f32 var_f4_6387;
    f32 var_f4_6454;
    f64 temp_f1_6393;
    f64 temp_f1_6399;
    f64 temp_f1_6403;
    s32 temp_r3_6422;
    s32 var_r0_6432;
    u8 temp_r3_6093;
    u8 var_r30_6102;
    u8 var_r30_6538;
    u8 var_r30_6564;

    ActivateIfInactive();
    temp_r3_6093 = this->unk8;
    if (temp_r3_6093 == 2) {
        return temp_r3_6093;
    }
    if ((u8) this->unk18 != 0) {
        temp_r3_6101 = this->unkC;
        var_r30_6102 = 0;
        if (((u8) M2C_FIELD(temp_r3_6101, u8 *, 0x8B8) == 2) || (temp_r3_6101->unk870.unk30.Get() != NULL)) {
            var_r30_6102 = 1;
        }
        if (var_r30_6102 != 0) {
            sp1F0.GetDir();
            temp_r4_6119 = this->unkC;
            M2C_FIELD(temp_r4_6119, f64 *, 0xE0) = M2C_BITWISE(f64, sp1F0);
            M2C_FIELD(temp_r4_6119, f64 *, 0xE8) = (f64) sp1F0.unk8;
            temp_r4_6119->unk6B5 |= 0x40;
            this->unkC->unk684 = 3.1415927f;
        }
    }
    temp_r4_6132 = this->unkC;
    sp240 = M2C_FIELD(temp_r4_6132, f64 *, 0xC0);
    sp248 = M2C_FIELD(temp_r4_6132, f64 *, 0xC8);
    spD0 = (MKVector3::up.unk4 * (f32) sp248) - (MKVector3::up.unk8 * unksp244);
    spD4 = (MKVector3::up.unk8 * (f32) sp240) - (MKVector3::up.unk0 * (f32) sp248);
    spD8 = (MKVector3::up.unk0 * unksp244) - (MKVector3::up.unk4 * (f32) sp240);
    sp1F0.unk40 = (f64) spD0;
    sp1F0.unk40.unk8 = (f64) spD8;
    MKModel_CalculateRefPointWorldPosition(temp_r4_6132->unk4, M2C_FIELD(temp_r4_6132->unkA08, s32 *, 0x84), (MKVector3 *) &sp1F0.unk30);
    if (((MKAnimScript *) (M2C_FIELD(this->unkC, MKAnimScript **, 0x630)))->CheckEvent(0) != 0) {
        temp_r30_6169 = this->unkC;
        temp_r29_6172 = temp_r30_6169->unkA08;
        M2C_FIELD(temp_r30_6169->__vptr, M2C_UNK (**)(MKVector3 *, Enemy *), 0xF8)(&sp1E0, temp_r30_6169);
        ((CynderBreathFX *) (M2C_FIELD(temp_r30_6169, CynderBreathFX **, 0xCEC)))->Trigger((MKProp *) temp_r30_6169, *((MKVector3 *) &sp1F0.unk30), *((MKVector3 *) &sp240), sp1E0, 1.0f, M2C_FIELD(temp_r29_6172, s32 *, 0x84), 100.0f);
        M2C_FIELD(this->unkC, s8 *, 0xD00) = 1;
        M2C_FIELD(this->unkC, s8 *, 0xCB0) = 1;
        this->unk18 = 0;
        this->unkC->unk684 = 0.0f;
    }
    if (((u8) M2C_FIELD(this->unkC, u8 *, 0xB08) >> 4U) & 1) {
        this->unk10 += 0.75f * (this->unk14 * (6.2831855f * gUpdateTimeDelta));
        temp_f2_6211 = this->unk14;
        if ((temp_f2_6211 > 0.0f) && (M2C_ERROR(/* unknown instruction: cror eq, gt, eq */), ((this->unk10 == 6.2831855f) != 0))) {
            this->unk14 = -1.0f;
        } else if (temp_f2_6211 < 0.0f) {
            M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
            if (this->unk10 == 0.0f) {
                temp_r3_6229 = this->unkC;
                temp_r4_6231 = temp_r3_6229->unkA38;
                temp_r3_6229->SetAnim((AnimSequence *) temp_r4_6231, (AnimTransition *) &temp_r4_6231->__vptr, 0.0f, 0U);
            }
        }
        spC0 = -M2C_BITWISE(f32, sp1F0.unk40);
        spC4 = -M2C_BITWISE(f32, sp1F0.unk40.unk4);
        spC8 = -M2C_BITWISE(f32, sp1F0.unk40.unk8);
        sp1B0 = (f64) spC0;
        sp1B8 = (f64) spC8;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
        sp1C0 = spB0;
        spB8 = (f32) sp1B8 * 6.2831855f;
        sp1C8 = (f64) spB8;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f27 */);
        sp1D0 = spA0;
        spA8 = (f32) sp1C8 * 500.0f;
        sp1D8 = (f64) spA8;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
        sp1F0.unk20 = sp90;
        sp98 = (f32) sp1D8 * 0.5f;
        sp1F0.unk28 = (f64) sp98;
        sp190.operator*(this->unk10);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f27 */);
        sp1A0 = sp40;
        sp48 = sp190.unk8 * 500.0f;
        sp1A8 = (f64) sp48;
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        sp1F0.unk28 = (f32) sp1F0.unk28 + (f32) sp1A8;
        unksp214 = (200.0f * (this->unk14 * _table_sinf(this->unk10))) + 100.0f;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f28 */);
        sp180 = sp30;
        sp38 = (f32) sp248 * 1000.0f;
        sp188 = (f64) sp38;
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        sp1F0.unk28 += (f32) sp188;
        sp150.operator*(M2C_ERROR(/* unknown instruction: ps_mr $f1, $f28 */));
        sp160.GetPos();
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        temp_r3_6349 = this->unkC;
        sp170 = sp20;
        sp28 = sp168 + sp150.unk8;
        M2C_FIELD(temp_r3_6349, f64 *, 0x700) = sp20;
        temp_r3_6349->unk708 = (f64) sp28;
        temp_r3_6355 = this->unkC;
        sp178 = (f64) sp28;
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r3, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        M2C_ERROR(/* unknown instruction: psq_stx $f0, $zero, $r3, 0x0, qr0 */);
        M2C_FIELD(temp_r3_6355, f64 *, 0x708) = (f32) ((f32) M2C_FIELD(temp_r3_6355, f64 *, 0x708) + sp1F0.unk28);
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r3, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
        sp140 = sp80;
        sp88 = (f32) M2C_FIELD(this->unkC, f64 *, 0x708) - sp1F0.unk38;
        sp148 = (f64) sp88;
        var_f4_6387 = ((f32) sp148 * (f32) sp148) + (((f32) sp140 * (f32) sp140) + (unksp144 * unksp144));
        if (var_f4_6387 > 1e-12f) {
            if (var_f4_6387 > 0.0f) {
                temp_f1_6393 = __frsqrte(var_f4_6387);
                temp_f1_6399 = 0.5 * temp_f1_6393 * -(((f64) var_f4_6387 * (temp_f1_6393 * temp_f1_6393)) - 3.0);
                temp_f1_6403 = 0.5 * temp_f1_6399 * -(((f64) var_f4_6387 * (temp_f1_6399 * temp_f1_6399)) - 3.0);
                var_f4_6387 = (f32) ((f64) var_f4_6387 * (0.5 * temp_f1_6403 * -(((f64) var_f4_6387 * (temp_f1_6403 * temp_f1_6403)) - 3.0)));
            } else if (var_f4_6387 < M2C_BITWISE(f32, 0.0)) {
                var_f4_6387 = __float_nan;
            } else {
                sp8 = var_f4_6387;
                temp_r3_6422 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                switch (temp_r3_6422) {             /* irregular */
                case 0x7F800000:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_6432 = 1;
                    } else {
                        var_r0_6432 = 2;
                    }
                    break;
                case 0x0:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_6432 = 5;
                    } else {
                        var_r0_6432 = 3;
                    }
                    break;
                default:
                    var_r0_6432 = 4;
                    break;
                }
                if (var_r0_6432 == 1) {
                    var_f4_6387 = __float_nan;
                }
            }
            var_f4_6454 = 1.0f / var_f4_6387;
        } else {
            var_f4_6454 = 0.0f;
        }
        sp74 = unksp144 * var_f4_6454;
        sp70 = (f32) sp140 * var_f4_6454;
        sp78 = (f32) sp148 * var_f4_6454;
        sp1F0.unk10 = (f64) sp70;
        sp1F0.unk18 = (f64) sp78;
        sp130 = (f64) sp1F0.unk30;
        sp138 = (f64) sp1F0.unk38;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
        sp110 = sp60;
        sp68 = (f32) sp1F0.unk18 * 1500.0f;
        sp118 = (f64) sp68;
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        sp100 = (f64) sp70;
        sp120 = sp50;
        sp58 = sp1F0.unk38 + (f32) sp118;
        sp108 = (f64) sp78;
        sp128 = (f64) sp58;
        ((CynderBreathFX *) (M2C_FIELD(this->unkC, CynderBreathFX **, 0xCEC)))->UpdateBeam((MKVector3) &sp130, (MKVector3) &sp120, (MKVector3) &sp100);
    } else {
        spE0.operator*(800.0f);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        temp_r3_6519 = this->unkC;
        spF0 = sp10;
        sp18 = sp1F0.unk38 + spE0.unk8;
        M2C_FIELD(temp_r3_6519, f64 *, 0x700) = sp10;
        spF8 = (f64) sp18;
        temp_r3_6519->unk708 = (f64) sp18;
    }
    if (((MKAnimScript *) (M2C_FIELD(this->unkC, MKAnimScript **, 0x630)))->CheckEvent(1) != 0) {
        ((CynderBreathFX *) (M2C_FIELD(this->unkC, CynderBreathFX **, 0xCEC)))->End();
    }
    temp_r29_6537 = this->unkC;
    var_r30_6538 = 0;
    if (temp_r29_6537->HasAnimFinished() != 0) {
        temp_r4_6543 = temp_r29_6537->unkA38;
        if ((temp_r4_6543 != NULL) && ((s8 *) temp_r4_6543->unk0 == (u32) M2C_FIELD(temp_r29_6537, MKAnimScript **, 0x630)->unk20)) {
            var_r30_6538 = 1;
        }
    }
    if (var_r30_6538 != 0) {
        temp_r3_6555 = this->unkC;
        temp_r4_6558 = temp_r3_6555->unkA38;
        temp_r3_6555->SetAnim((AnimSequence *) temp_r4_6558, (AnimTransition *) &temp_r4_6558->unk20, 0.0f, 0U);
    } else {
        temp_r29_6563 = this->unkC;
        var_r30_6564 = 0;
        if (temp_r29_6563->HasAnimFinished() != 0) {
            temp_r4_6569 = temp_r29_6563->unkA38;
            if ((temp_r4_6569 != NULL) && ((void *) temp_r4_6569->__vptr == (u32) M2C_FIELD(temp_r29_6563, MKAnimScript **, 0x630)->unk20)) {
                var_r30_6564 = 1;
            }
        }
        if (var_r30_6564 != 0) {
            this->unk8 = 2;
        }
    }
    temp_r3_6584 = this->unkC;
    if ((((u8) M2C_FIELD(temp_r3_6584, u8 *, 0xB08) >> 4U) & 1) && (temp_r3_6584->CheckMeleeHit((EnemyAttack *) temp_r3_6584->unkA08, -1) != 0)) {
        this->unkC->SetHitTarget(1U);
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void CynderBossGoal_BreathAttack::Activate() {
    AttackerManager *var_r3_6694;
    Enemy *temp_r3_6638;
    Enemy *temp_r3_6651;
    Enemy *temp_r3_6674;
    Enemy *temp_r4_6657;
    Enemy *temp_r5_6720;
    Enemy *var_r4_6701;
    MKMaterial *temp_r3_6669;
    u8 var_r30_6675;
    void *temp_r5_6653;

    this->unk8 = 0;
    if (PhrasePlayer_IsEventPlaying(M2C_FIELD(this->unkC, s32 *, 0xD58)) != 0) {
        this->unk8 = 2;
        return;
    }
    this->unkC->StopMovement(1U);
    temp_r3_6638 = this->unkC;
    temp_r3_6638->unkA0 = 0.0f;
    temp_r3_6638->unkA4 = 0.0f;
    temp_r3_6638->unkA8 = 0.0f;
    M2C_FIELD(M2C_FIELD(this->unkC, void **, 0xCEC), f32 *, 0x1C8) = 100.0f;
    temp_r3_6651 = this->unkC;
    temp_r5_6653 = temp_r3_6651->unkA08->__vptr;
    temp_r3_6651->SetAnim((AnimSequenceType) M2C_FIELD(temp_r5_6653, s32 *, 0x6C), M2C_FIELD(temp_r5_6653, s32 *, 0x68), 0, 0.15f, 0U, 0U);
    temp_r4_6657 = this->unkC;
loop_4:
    if ((void *) temp_r4_6657->unkA04->__vptr != NULL) {
        temp_r4_6657->unkA04 = (CharacterZapFX *) &temp_r4_6657->unkA04->unk4;
        goto loop_4;
    }
    temp_r3_6669 = this->unkC->unkA18;
    if (temp_r3_6669 != NULL) {
        temp_r3_6669->SetDefaults();
    }
    temp_r3_6674 = this->unkC;
    var_r30_6675 = 0;
    if (((u8) M2C_FIELD(temp_r3_6674, u8 *, 0x8B8) == 2) || (temp_r3_6674->unk870.unk30.Get() != NULL)) {
        var_r30_6675 = 1;
    }
    if (var_r30_6675 != 0) {
        var_r3_6694 = M2C_FIELD(this->unkC->unk870.unk30.Get()->__vptr, AttackerManager *(**)(), 0x48)();
    } else {
        var_r3_6694 = NULL;
    }
    if (var_r3_6694 != NULL) {
        var_r4_6701 = this->unkC;
        if (var_r4_6701 != NULL) {
            var_r4_6701 += 0x6B8;
        }
        var_r3_6694->Add((Targetable *) var_r4_6701, 2);
    }
    this->unkC->SetInvulnerableToMeleeAttacks(1U, 1U);
    this->unkC->SetInvulnerableToBreathAttacks(1U, 1U);
    this->unkC->SetHitTarget(0U);
    temp_r5_6720 = this->unkC;
    M2C_FIELD(temp_r5_6720, s32 *, 0xCFC) = (s32) (M2C_FIELD(temp_r5_6720, s32 *, 0xCFC) + 1);
    this->unk10 = 0.0f;
    this->unk14 = 1.0f;
    this->unk18 = 1;
    M2C_FIELD(this->unkC, s8 *, 0xCB0) = 0;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk30C'
void CynderBossGoal_MeleeAttack::Terminate() {
    AttackerManager *var_r3_6800;
    CharacterFireFX *temp_r5_6755;
    Enemy *temp_r3_6750;
    Enemy *temp_r3_6754;
    Enemy *temp_r3_6771;
    Enemy *temp_r3_6780;
    Enemy *var_r4_6807;
    u8 var_r30_6781;
    void *temp_r4_6772;

    temp_r3_6750 = this->unkC;
    M2C_FIELD(temp_r3_6750, u8 *, 0xB08) = (u8) (M2C_FIELD(temp_r3_6750, u8 *, 0xB08) & ~0x10);
    temp_r3_6754 = this->unkC;
    temp_r5_6755 = temp_r3_6754->unkA08;
    if (temp_r5_6755 != NULL) {
        this->unkC->unkA7C = gb.unk30C + temp_r3_6754->unkA20->GetEnemyAttackSetting((EnemySettingType) 6, (EnemyAttack *) temp_r5_6755);
    }
    this->unkC->unkA08 = NULL;
    temp_r3_6771 = this->unkC;
    temp_r4_6772 = temp_r3_6771->unkA44;
    if (temp_r4_6772 != NULL) {
        M2C_FIELD(temp_r4_6772, u8 *, 0x10) = (u8) ((M2C_FIELD(temp_r4_6772, u8 *, 0x10) & ~0x80) | ((M2C_FIELD(temp_r3_6771, u8 *, 0xB08) << 6) & 0x80));
    }
    temp_r3_6780 = this->unkC;
    var_r30_6781 = 0;
    if (((u8) M2C_FIELD(temp_r3_6780, u8 *, 0x8B8) == 2) || (temp_r3_6780->unk870.unk30.Get() != NULL)) {
        var_r30_6781 = 1;
    }
    if (var_r30_6781 != 0) {
        var_r3_6800 = M2C_FIELD(this->unkC->unk870.unk30.Get()->__vptr, AttackerManager *(**)(), 0x48)();
    } else {
        var_r3_6800 = NULL;
    }
    if (var_r3_6800 != NULL) {
        var_r4_6807 = this->unkC;
        if (var_r4_6807 != NULL) {
            var_r4_6807 += 0x6B8;
        }
        var_r3_6800->Remove((Targetable *) var_r4_6807, 2);
    }
    this->unkC->SetInvulnerableToMeleeAttacks(0U, 1U);
    this->unkC->SetInvulnerableToBreathAttacks(0U, 1U);
}
#endif

#if 0 // DRAFT: undefined identifier 'unksp40'
u8 CynderBossGoal_MeleeAttack::Update() {
    CharacterFireFX *temp_r3_6859;
    Enemy *temp_r3_6888;
    Enemy *temp_r3_7087;
    Enemy *temp_r3_7115;
    Enemy *temp_r4_6858;
    Enemy *temp_r4_6883;
    MKProp *var_r3_6975;
    MKProp *var_r4_7093;
    f32 temp_f0_6949;
    f32 temp_f1_6893;
    f32 temp_f1_6994;
    f32 temp_f28_6914;
    f32 var_f3_7071;
    f32 var_f4_7005;
    f64 temp_f1_7010;
    f64 temp_f1_7016;
    f64 temp_f1_7020;
    f64 temp_f2_6895;
    f64 temp_f3_6894;
    s32 temp_r31_6960;
    s32 temp_r3_7039;
    s32 var_r0_7049;
    s32 var_r26_6962;
    s32 var_r28_6961;
    s32 var_r29_6911;
    void *temp_r3_6972;
    void *temp_r3_6982;
    void *temp_r4_7090;
    void *temp_r6_6967;

    ActivateIfInactive();
    if (this->unkC->HasAnimFinished() != 0) {
        this->unk8 = 2;
    }
    temp_r4_6858 = this->unkC;
    temp_r3_6859 = temp_r4_6858->unkA08;
    if ((temp_r3_6859 != NULL) && (M2C_FIELD(temp_r3_6859, s32 *, 0x38) & 0x80) && (((MKAnimScript *) (M2C_FIELD(temp_r4_6858, MKAnimScript **, 0x630)))->CheckEvent(1) != 0)) {
        unksp40 = 1.0f;
        unksp44 = 0.0f;
        unksp48 = 0.1f;
        unksp4C = 1.0f;
        unksp90 = unksp40;
        unksp98 = 5.122630465e-315;
        temp_r4_6883 = this->unkC;
        ((EarthShockwave *) (M2C_FIELD(temp_r4_6883, EarthShockwave **, 0xCE8)))->Trigger(*((MKVector3 *) &temp_r4_6883->unk588), 1.0f, 0U, (MKVector4) &unksp90);
        temp_r3_6888 = this->unkC;
        temp_f1_6893 = 0.5f * -500.0f;
        temp_f3_6894 = M2C_FIELD(temp_r3_6888, f64 *, 0x588);
        temp_f2_6895 = M2C_FIELD(temp_r3_6888, f64 *, 0x590);
        unksp28 = 250.0f;
        unksp20 = temp_f1_6893;
        unksp24 = 0.0f;
        unkspB0 = temp_f3_6894;
        unksp80 = (f64) temp_f1_6893;
        unkspC0 = temp_f3_6894;
        unkspC8 = temp_f2_6895;
        unkspB8 = temp_f2_6895;
        unksp88 = 5.593163344e-315;
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        var_r29_6911 = 0;
        temp_f28_6914 = unkspB8 + M2C_BITWISE(f32, 5.593163344e-315);
        unkspB8 = temp_f28_6914;
        do {
            MKVector((f32) (var_r29_6911 & 1) * 500.0f, 0.0f, (f32) -(var_r29_6911 / 2) * 500.0f);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            temp_f0_6949 = temp_f28_6914 + unksp68;
            unksp70 = unksp10;
            unksp18 = temp_f0_6949;
            unkspC0 = unksp10;
            unksp78 = (f64) temp_f0_6949;
            unkspC8 = (f64) temp_f0_6949;
            temp_r31_6960 = MKCollision_SphereCollide(*((MKVector3 *) &unkspC0), 500.0f, (MKCollisionResult *) &unkspD0, 0x14, (MKCollisionMode) 2, 0x08000000);
            var_r28_6961 = 0;
            var_r26_6962 = 0;
loop_38:
            if (var_r28_6961 < temp_r31_6960) {
                temp_r6_6967 = &unkspD0 + var_r26_6962;
                if (((u8) M2C_FIELD(temp_r6_6967, u8 *, 0x50) != 0) && (temp_r3_6972 = M2C_FIELD(temp_r6_6967, void **, 0x48), ((temp_r3_6972 == NULL) == 0)) && (var_r3_6975 = M2C_FIELD(temp_r3_6972, MKProp **, 8), ((var_r3_6975 == NULL) == 0))) {

                } else {
                    var_r3_6975 = NULL;
                }
                temp_r3_6982 = var_r3_6975->unk8;
                unksp50 = M2C_FIELD(temp_r3_6982, f64 *, 0x30);
                unksp58 = M2C_FIELD(temp_r3_6982, f64 *, 0x38);
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r4, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
                temp_f1_6994 = unksp58 - this->unkC->unk588.unk4;
                unkspA0 = unksp30;
                unksp38 = temp_f1_6994;
                unkspA4 = 0.0f;
                unkspA8 = (f64) temp_f1_6994;
                var_f4_7005 = (temp_f1_6994 * temp_f1_6994) + (((f32) unksp30 * (f32) unksp30) + (0.0f * 0.0f));
                if (var_f4_7005 > 0.000001f) {
                    if (var_f4_7005 > 0.0f) {
                        temp_f1_7010 = __frsqrte(var_f4_7005);
                        temp_f1_7016 = 0.5 * temp_f1_7010 * -(((f64) var_f4_7005 * (temp_f1_7010 * temp_f1_7010)) - 3.0);
                        temp_f1_7020 = 0.5 * temp_f1_7016 * -(((f64) var_f4_7005 * (temp_f1_7016 * temp_f1_7016)) - 3.0);
                        var_f4_7005 = (f32) ((f64) var_f4_7005 * (0.5 * temp_f1_7020 * -(((f64) var_f4_7005 * (temp_f1_7020 * temp_f1_7020)) - 3.0)));
                    } else if (var_f4_7005 < M2C_BITWISE(f32, 0.0)) {
                        var_f4_7005 = __float_nan;
                    } else {
                        unksp8 = var_f4_7005;
                        temp_r3_7039 = unksp8 & 0x7F800000;
                        switch (temp_r3_7039) {     /* irregular */
                        case 0x7F800000:
                            if (unksp8 & 0x7FFFFF) {
                                var_r0_7049 = 1;
                            } else {
                                var_r0_7049 = 2;
                            }
                            break;
                        case 0x0:
                            if (unksp8 & 0x7FFFFF) {
                                var_r0_7049 = 5;
                            } else {
                                var_r0_7049 = 3;
                            }
                            break;
                        default:
                            var_r0_7049 = 4;
                            break;
                        }
                        if (var_r0_7049 == 1) {
                            var_f4_7005 = __float_nan;
                        }
                    }
                    var_f3_7071 = 1.0f / var_f4_7005;
                } else {
                    var_f3_7071 = 0.0f;
                }
                unkspA0 *= var_f3_7071;
                unkspA4 *= var_f3_7071;
                unkspA8 *= var_f3_7071;
                temp_r3_7087 = this->unkC;
                if (((u8) M2C_FIELD(temp_r6_6967, u8 *, 0x50) != 0) && (temp_r4_7090 = M2C_FIELD(temp_r6_6967, void **, 0x48), ((temp_r4_7090 == NULL) == 0)) && (var_r4_7093 = M2C_FIELD(temp_r4_7090, MKProp **, 8), ((var_r4_7093 == NULL) == 0))) {

                } else {
                    var_r4_7093 = NULL;
                }
                temp_r3_7087->MeleeDamageTarget(var_r4_7093, (EnemyAttack *) temp_r3_7087->unkA08, *((MKVector3 *) &unkspA0), -1);
                this->unkC->SetHitTarget(1U);
                var_r28_6961 += 1;
                var_r26_6962 += 0x58;
                goto loop_38;
            }
            var_r29_6911 += 1;
        } while (var_r29_6911 < 4);
    }
    temp_r3_7115 = this->unkC;
    if ((((u8) M2C_FIELD(temp_r3_7115, u8 *, 0xB08) >> 4U) & 1) && (temp_r3_7115->CheckMeleeHit((EnemyAttack *) temp_r3_7115->unkA08, -1) != 0)) {
        this->unkC->SetHitTarget(1U);
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void CynderBossGoal_MeleeAttack::Activate() {
    AttackerManager *var_r3_7213;
    Enemy *temp_r3_7161;
    Enemy *temp_r3_7170;
    Enemy *temp_r3_7193;
    Enemy *temp_r4_7176;
    Enemy *temp_r4_7239;
    Enemy *var_r4_7220;
    MKMaterial *temp_r3_7188;
    u8 var_r30_7194;
    void *temp_r5_7172;

    this->unk8 = 0;
    this->unkC->StopMovement(1U);
    temp_r3_7161 = this->unkC;
    temp_r3_7161->unkA0 = 0.0f;
    temp_r3_7161->unkA4 = 0.0f;
    temp_r3_7161->unkA8 = 0.0f;
    temp_r3_7170 = this->unkC;
    temp_r5_7172 = temp_r3_7170->unkA08->__vptr;
    temp_r3_7170->SetAnim((AnimSequenceType) M2C_FIELD(temp_r5_7172, s32 *, 0x6C), M2C_FIELD(temp_r5_7172, s32 *, 0x68), 0, 0.15f, 0U, 0U);
    temp_r4_7176 = this->unkC;
loop_2:
    if ((void *) temp_r4_7176->unkA04->__vptr != NULL) {
        temp_r4_7176->unkA04 = (CharacterZapFX *) &temp_r4_7176->unkA04->unk4;
        goto loop_2;
    }
    temp_r3_7188 = this->unkC->unkA18;
    if (temp_r3_7188 != NULL) {
        temp_r3_7188->SetDefaults();
    }
    temp_r3_7193 = this->unkC;
    var_r30_7194 = 0;
    if (((u8) M2C_FIELD(temp_r3_7193, u8 *, 0x8B8) == 2) || (temp_r3_7193->unk870.unk30.Get() != NULL)) {
        var_r30_7194 = 1;
    }
    if (var_r30_7194 != 0) {
        var_r3_7213 = M2C_FIELD(this->unkC->unk870.unk30.Get()->__vptr, AttackerManager *(**)(), 0x48)();
    } else {
        var_r3_7213 = NULL;
    }
    if (var_r3_7213 != NULL) {
        var_r4_7220 = this->unkC;
        if (var_r4_7220 != NULL) {
            var_r4_7220 += 0x6B8;
        }
        var_r3_7213->Add((Targetable *) var_r4_7220, 2);
    }
    this->unkC->SetInvulnerableToMeleeAttacks(1U, 1U);
    this->unkC->SetInvulnerableToBreathAttacks(1U, 1U);
    this->unkC->SetHitTarget(0U);
    temp_r4_7239 = this->unkC;
    M2C_FIELD(temp_r4_7239, s32 *, 0xCFC) = (s32) (M2C_FIELD(temp_r4_7239, s32 *, 0xCFC) + 1);
}
#endif

void CynderBossGoal_Idle::Reset() {
    this->unk8 = 1;
    this->unk10 = 0;
    this->unk14 = 1;
}

#if 0 // DRAFT: undefined identifier 'unk8B8'
u8 CynderBossGoal_Idle::Update() {
    Character *temp_r3_7270;
    Character *temp_r4_7295;
    Character *temp_r4_7338;
    s32 temp_r4_7342;
    u8 var_r30_7271;
    u8 var_r3_7321;
    u8 var_r4_7315;
    void *temp_r5_7316;

    ActivateIfInactive();
    temp_r3_7270 = this->unkC;
    var_r30_7271 = 0;
    if (((u8) temp_r3_7270->unk8B8 == 2) || (temp_r3_7270->unk8B0.Get() != NULL)) {
        var_r30_7271 = 1;
    }
    if ((var_r30_7271 == 0) || ((s32) this->unk14 == 4)) {
        this->unkC->unk684 = 0.0f;
    }
    if ((s32) this->unk14 != 4) {
        temp_r4_7295 = this->unkC;
        if (M2C_BITWISE(f32, temp_r4_7295->unk684) == 0.0f) {
            M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
            if (gb.unk30C == temp_r4_7295->unkA7C) {
                this->unk8 = 2;
            }
        }
    }
    if (this->unkC->HasAnimFinished() == 0) {
        var_r4_7315 = 0;
        temp_r5_7316 = M2C_FIELD(this->unkC, void **, 0x630);
        if (((u32) M2C_FIELD(temp_r5_7316, u32 *, 0x2C) >> 1U) & 1) {
            var_r3_7321 = 0;
            if ((M2C_FIELD(temp_r5_7316, f32 *, 0x38) > 0.0f) || ((s32) M2C_FIELD(temp_r5_7316, s32 *, 0x44) > 1)) {
                var_r3_7321 = 1;
            }
            if (var_r3_7321 != 0) {
                var_r4_7315 = 1;
            }
        }
        if (var_r4_7315 != 0) {
            goto block_18;
        }
    } else {
block_18:
        temp_r4_7338 = this->unkC;
        temp_r4_7338->unkAEC += 1;
        temp_r4_7342 = this->unk10;
        if ((temp_r4_7342 != 0) && ((s32) this->unkC->unkAEC >= temp_r4_7342)) {
            this->unk8 = 2;
        } else if ((temp_r4_7342 == 0) && (M2C_ERROR(/* unknown instruction: cror eq, gt, eq */), ((gb.unk30C == this->unkC->unkA7C) != 0))) {
            this->unk8 = 2;
        } else {
            this->unkC->SetAnim((AnimSequenceType) 1, this->unk14, 0, 0.15f, 0U, 0U);
        }
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: undefined identifier 'unkAEC'
void CynderBossGoal_Idle::Activate() {
    Character *temp_r3_7399;
    s32 temp_r0_7412;

    this->unk8 = 0;
    this->unkC->unkAEC = 0;
    this->unkC->StopMovement(1U);
    temp_r3_7399 = this->unkC;
    temp_r3_7399->unkA0 = 0.0f;
    temp_r3_7399->unkA4 = 0.0f;
    temp_r3_7399->unkA8 = 0.0f;
    this->unkC->SetAnim((AnimSequenceType) 1, this->unk14, 0, 0.15f, 0U, 0U);
    temp_r0_7412 = this->unk14;
    if ((temp_r0_7412 == 4) || (temp_r0_7412 == 3)) {
        this->unkC->SetInvulnerableToBreathAttacks(1U, 1U);
        this->unkC->SetInvulnerableToMeleeAttacks(1U, 1U);
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk8B8'
u8 CynderBossGoal_Leap::Update() {
    Character *temp_r3_7448;
    Character *temp_r3_7493;
    Character *temp_r3_7595;
    Character *temp_r4_7466;
    Character *temp_r4_7511;
    f32 temp_f10_7597;
    f32 temp_f11_7599;
    f32 temp_f6_7596;
    f32 temp_f7_7544;
    f32 temp_f8_7542;
    f32 temp_f9_7540;
    u8 temp_r3_7482;
    u8 var_r30_7449;
    u8 var_r30_7494;
    ActivateIfInactive();
    temp_r3_7448 = this->unkC;
    var_r30_7449 = 0;
    if (((u8) temp_r3_7448->unk8B8 == 2) || (temp_r3_7448->unk8B0.Get() != NULL)) {
        var_r30_7449 = 1;
    }
    if (var_r30_7449 != 0) {
        arg_spA0.GetDir();
        temp_r4_7466 = this->unkC;
        M2C_FIELD(temp_r4_7466, f64 *, 0xE0) = arg_spA0;
        M2C_FIELD(temp_r4_7466, f64 *, 0xE8) = arg_spA8;
        temp_r4_7466->unk6B5 |= 0x40;
    }
    if (((MKAnimScript *) (M2C_FIELD(this->unkC, MKAnimScript **, 0x630)))->CheckEvent(6) != 0) {
        temp_r3_7482 = this->unk20;
        this->unk20 = (temp_r3_7482 & ~0x80) | ((CLZ((temp_r3_7482 >> 7U) & 1) << 2) & 0x80);
        this->unkC->unk684 = 3.1415927f;
        if (!(((u8) this->unk20 >> 7U) & 1)) {
            temp_r3_7493 = this->unkC;
            var_r30_7494 = 0;
            if (((u8) temp_r3_7493->unk8B8 == 2) || (temp_r3_7493->unk8B0.Get() != NULL)) {
                var_r30_7494 = 1;
            }
            if (var_r30_7494 != 0) {
                arg_sp90.GetDir();
                temp_r4_7511 = this->unkC;
                M2C_FIELD(temp_r4_7511, f64 *, 0xE0) = arg_sp90;
                M2C_FIELD(temp_r4_7511, f64 *, 0xE8) = arg_sp98;
                temp_r4_7511->unk6B5 |= 0x40;
            }
        }
    }
    if (((u8) this->unk20 >> 7U) & 1) {
        M2C_STRUCT_COPY((s32) &arg_spAC + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
        temp_f9_7540 = -this->unk10;
        temp_f8_7542 = -this->unk14;
        temp_f7_7544 = -this->unk18;
        arg_sp10 = temp_f9_7540;
        arg_sp14 = temp_f8_7542;
        arg_sp18 = temp_f7_7544;
        arg_sp60 = (f64) arg_sp10;
        arg_sp68 = (f64) arg_sp18;
        arg_sp48 = temp_f7_7544;
        arg_sp40 = temp_f9_7540;
        arg_sp44 = temp_f8_7542;
        arg_sp38 = (MKVector3::up.unk0 * arg_sp64) - (MKVector3::up.unk4 * (f32) arg_sp60);
        arg_sp80 = (f64) arg_sp40;
        arg_sp88 = (f64) arg_sp48;
        arg_sp78 = (f64) arg_sp38;
        arg_sp30 = (MKVector3::up.unk4 * (f32) arg_sp68) - (MKVector3::up.unk8 * arg_sp64);
        arg_sp34 = (MKVector3::up.unk8 * (f32) arg_sp60) - (MKVector3::up.unk0 * (f32) arg_sp68);
        arg_spD0 = (f32) arg_sp80;
        arg_sp70 = (f64) arg_sp30;
        arg_spD4 = arg_sp84;
        arg_spD8 = (f32) arg_sp88;
        arg_spDC = 0.0f;
        arg_spB0 = (f32) arg_sp70;
        arg_spB4 = arg_sp74;
        arg_spB8 = (f32) arg_sp78;
        arg_spBC = 0.0f;
        temp_r3_7595 = this->unkC;
        temp_f6_7596 = temp_r3_7595->unk84;
        temp_f10_7597 = temp_r3_7595->unk80;
        temp_f11_7599 = temp_r3_7595->unk88;
        arg_sp20 = (temp_f11_7599 * (f32) arg_sp80) + ((temp_f10_7597 * (f32) arg_sp70) + (temp_f6_7596 * arg_spC0));
        arg_sp24 = (temp_f11_7599 * arg_sp84) + ((temp_f10_7597 * arg_sp74) + (temp_f6_7596 * arg_spC4));
        arg_sp28 = (temp_f11_7599 * (f32) arg_sp88) + ((temp_f10_7597 * (f32) arg_sp78) + (temp_f6_7596 * arg_spC8));
        M2C_FIELD(temp_r3_7595, f64 *, 0x90) = (f64) arg_sp20;
        arg_sp50 = (f64) arg_sp20;
        arg_sp58 = (f64) arg_sp28;
        M2C_FIELD(temp_r3_7595, f64 *, 0x98) = (f64) arg_sp28;
    }
    if (this->unkC->HasAnimFinished() != 0) {
        this->unk8 = 2;
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: undefined identifier 'SetInvulnerableToMeleeAttacks'
void CynderBossGoal_Leap::Activate() {
    f64 sp8;
    Character *temp_r3_7677;
    Character *temp_r3_7701;
    s32 var_r5_7665;
    u8 var_r31_7678;

    this->unk8 = 0;
    this->unkC->StopMovement(1U);
    this->unkC->SetMovementType((CharacterMoveType) 0);
    this->unkC->SetInvulnerableToMeleeAttacks(1U, 1U);
    this->unkC->SetInvulnerableToBreathAttacks(1U, 1U);
    this->unk20 &= ~0x80;
    var_r5_7665 = 0x1B;
    if (((u8) this->unk20 >> 6U) & 1) {
        var_r5_7665 = 0x1C;
    }
    this->unkC->SetAnim((AnimSequenceType) 9, var_r5_7665, 0, 0.15f, 4U, 0U);
    temp_r3_7677 = this->unkC;
    var_r31_7678 = 0;
    if (((u8) temp_r3_7677->unk8B8 == 2) || (temp_r3_7677->unk8B0.Get() != NULL)) {
        var_r31_7678 = 1;
    }
    if (var_r31_7678 != 0) {
        sp8.GetDir();
        M2C_FIELD(this, f64 *, 0x10) = sp8;
        M2C_FIELD(this, f64 *, 0x18) = sp10;
        return;
    }
    temp_r3_7701 = this->unkC;
    M2C_FIELD(this, f64 *, 0x10) = (f64) M2C_FIELD(temp_r3_7701, f64 *, 0xC0);
    M2C_FIELD(this, f64 *, 0x18) = (f64) M2C_FIELD(temp_r3_7701, f64 *, 0xC8);
}
#endif

void CynderBossGoal_AttackPhase3::Terminate() {
    gb.unk35D = 0;
    this->unk8 = 1;
    RemoveAllSubgoals();
}

#if 0 // DRAFT: illegal implicit conversion from 'void' to
u8 CynderBossGoal_AttackPhase3::Update() {
    ActivateIfInactive();
    this->unk8 = UpdateSubgoals();
    if ((u8) this->unk8 != 0) {
        Activate();
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_sp2C'
void CynderBossGoal_AttackPhase3::Activate() {
    Enemy *temp_r3_7776;
    Enemy *temp_r3_7813;
    Enemy *temp_r3_7885;
    Enemy *temp_r4_7788;
    Enemy *temp_r5_7860;
    f32 temp_f1_7823;
    f32 temp_f1_7853;
    f32 temp_f5_7829;
    f32 temp_f6_7817;
    this->unk8 = 0;
    RemoveAllSubgoals();
    temp_r3_7776 = this->unkC;
    if ((u8) M2C_FIELD(temp_r3_7776, u8 *, 0xF1E) == 0) {
        temp_r3_7776->SetInvulnerableToBreathAttacks(0U, 1U);
        this->unkC->SetInvulnerableToMeleeAttacks(0U, 1U);
    }
    temp_r4_7788 = this->unkC;
    if ((u8) M2C_FIELD(temp_r4_7788, u8 *, 0xF1B) != 0) {
        gb.unk35D = 1;
        if ((u8) M2C_FIELD(temp_r4_7788, u8 *, 0xF1C) != 0) {
            ((EventMessage *) (temp_r4_7788 + 0xED0))->Send((MKProp *) temp_r4_7788);
            M2C_STRUCT_COPY((s32) &arg_sp2C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
            temp_r3_7813 = this->unkC;
            temp_f6_7817 = M2C_FIELD(temp_r3_7813, f32 *, 0xEA8);
            arg_sp50 = temp_f6_7817;
            temp_f1_7823 = M2C_FIELD(temp_r3_7813, f32 *, 0xEAC);
            arg_sp54 = temp_f1_7823;
            temp_f5_7829 = M2C_FIELD(temp_r3_7813, f32 *, 0xEB0);
            arg_sp18 = (MKVector3::up.unk0 * temp_f1_7823) - (MKVector3::up.unk4 * temp_f6_7817);
            arg_sp58 = temp_f5_7829;
            arg_sp28 = (f64) arg_sp18;
            arg_sp10 = (MKVector3::up.unk4 * temp_f5_7829) - (MKVector3::up.unk8 * temp_f1_7823);
            arg_sp14 = (MKVector3::up.unk8 * temp_f6_7817) - (MKVector3::up.unk0 * temp_f5_7829);
            arg_sp5C = 0.0f;
            arg_sp20 = (f64) arg_sp10;
            arg_sp30 = (f32) arg_sp20;
            arg_sp34 = arg_sp24;
            arg_sp38 = (f32) arg_sp28;
            arg_sp3C = 0.0f;
            arg_sp60 = M2C_FIELD(temp_r3_7813, f32 *, 0xE98);
            arg_sp64 = M2C_FIELD(temp_r3_7813, f32 *, 0xE9C);
            temp_f1_7853 = M2C_FIELD(temp_r3_7813, f32 *, 0xEA0);
            arg_sp68 = temp_f1_7853;
            arg_sp6C = 1.0f;
            temp_r3_7813->Teleport(&arg_sp30, &MKVector3::up, temp_f1_7853, arg_sp24, (f32) arg_sp20, 0.0f, temp_f5_7829, temp_f6_7817, MKVector3::up.unk8, MKVector3::up.unk4);
            temp_r5_7860 = this->unkC;
            M2C_FIELD(temp_r5_7860, f64 *, 0xE0) = (f64) M2C_FIELD(temp_r5_7860, f64 *, 0xC0);
            M2C_FIELD(temp_r5_7860, f64 *, 0xE8) = (f64) M2C_FIELD(temp_r5_7860, f64 *, 0xC8);
            temp_r5_7860->unk6B5 |= 0x40;
            this->unkC->StopMovement(1U);
            this->unkC->EnableFlyingRotation(0U);
        }
        ((Stat *) ((Stat *) &GameData::gameData[0xB8]))->SetValue(0.0f, 1U);
        M2C_FIELD(this->unkC, u8 *, 0xF1B) = 0U;
        temp_r3_7885 = this->unkC;
        if ((u8) M2C_FIELD(temp_r3_7885, u8 *, 0xF1C) != 0) {
            M2C_FIELD(temp_r3_7885, u8 *, 0xF1C) = 0U;
            AddSubgoal__22CompositeGoal<6Cynder>FP13Goal<6Cynder>((CompositeGoal<Cynder> *) this, (Goal<Cynder> *) this->unk24);
        }
        AddSubgoal__22CompositeGoal<6Cynder>FP13Goal<6Cynder>((CompositeGoal<Cynder> *) this, (Goal<Cynder> *) this->unk34);
        return;
    }
    if ((u8) M2C_FIELD(temp_r4_7788, u8 *, 0xF1D) != 0) {
        AddSubgoal__22CompositeGoal<6Cynder>FP13Goal<6Cynder>((CompositeGoal<Cynder> *) this, (Goal<Cynder> *) this->unk2C);
        AddSubgoal__22CompositeGoal<6Cynder>FP13Goal<6Cynder>((CompositeGoal<Cynder> *) this, (Goal<Cynder> *) this->unk30);
        return;
    }
    AddSubgoal__22CompositeGoal<6Cynder>FP13Goal<6Cynder>((CompositeGoal<Cynder> *) this, (Goal<Cynder> *) this->unk28);
    AddSubgoal__22CompositeGoal<6Cynder>FP13Goal<6Cynder>((CompositeGoal<Cynder> *) this, (Goal<Cynder> *) this->unk34);
}
#endif

void CynderBossGoal_AttackPhase3::Deinit() {
    Goal<Cynder> *temp_r3_7940;
    Goal<Cynder> *temp_r3_7945;
    Goal<Cynder> *temp_r3_7950;
    Goal<Cynder> *temp_r3_7955;
    Goal<Cynder> *temp_r3_7960;
    MKHeap *temp_r3_7978;
    void **temp_r3_7933;
    void *temp_r31_7975;

    temp_r3_7933 = this->unk20;
    M2C_FIELD(*temp_r3_7933, M2C_UNK (**)(void **), 0xC)(temp_r3_7933);
    operator delete(this->unk20);
    temp_r3_7940 = this->unk24;
    temp_r3_7940->Deinit();
    temp_r3_7945 = this->unk28;
    temp_r3_7945->Deinit();
    temp_r3_7950 = this->unk2C;
    temp_r3_7950->Deinit();
    temp_r3_7955 = this->unk30;
    temp_r3_7955->Deinit();
    temp_r3_7960 = this->unk34;
    temp_r3_7960->Deinit();
    operator delete(this->unk24);
    operator delete(this->unk28);
    operator delete(this->unk2C);
    operator delete(this->unk30);
    operator delete(this->unk34);
    temp_r31_7975 = this->unk1C;
    if (temp_r31_7975 != NULL) {
        temp_r3_7978 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_7978 != NULL) {
            ((MKHeap *) (temp_r3_7978->Current()))->Free(temp_r31_7975, NULL, 0);
        } else {
            free(temp_r31_7975);
        }
        this->unk1C = NULL;
    }
    this->unk10 = 0;
    this->unk18 = 0;
    this->unk14 = 0;
    this->unk8 = 1;
    this->unkC = NULL;
    this->unk9 = 0;
}

#if 0 // DRAFT: pointer/array required
void CynderBossGoal_AttackPhase3::Init(Cynder *arg0) {
    Goal<Cynder> *temp_r4_8190;
    Goal<Cynder> *temp_r4_8201;
    Goal<Cynder> *temp_r4_8212;
    Goal<Cynder> *temp_r4_8223;
    MKHeap *temp_r3_8152;
    void **temp_r4_8179;
    void *var_r3_8159;

    if ((u8) this->unk9 == 0) {
        operator new(0x1CU, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__13Goal<6Cynder>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk20 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x14U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__13Goal<6Cynder>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk24 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x14U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__13Goal<6Cynder>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk28 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x14U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__13Goal<6Cynder>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk2C = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x10U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__13Goal<6Cynder>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk30 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x40U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__13Goal<6Cynder>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__22CompositeGoal<6Cynder>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x1C) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x18) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x10) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x14) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk34 = M2C_ERROR(/* Read from unset register $r3 */);
    }
    if ((u8) this->unk9 == 0) {
        temp_r3_8152 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_8152 != NULL) {
            var_r3_8159 = ((MKHeap *) (temp_r3_8152->Current()))->Alloc(0x14, NULL, 0);
        } else {
            var_r3_8159 = malloc(0x14);
        }
        this->unk1C = var_r3_8159;
        this->unk10 = 5;
    }
    this->unk8 = 1;
    this->unkC = (Enemy *) arg0;
    this->unk4 = 0xA8;
    if ((Enemy *) this->unkC != NULL) {
        this->unk9 = 1;
    }
    temp_r4_8179 = this->unk20;
    M2C_FIELD(temp_r4_8179, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_8179, Cynder **, 0xC) = arg0;
    M2C_FIELD(temp_r4_8179, s32 *, 4) = 0xAA;
    if ((Cynder *) M2C_FIELD(temp_r4_8179, Cynder **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_8179, s8 *, 9) = 1;
    }
    temp_r4_8190 = this->unk24;
    M2C_FIELD(temp_r4_8190, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_8190, Cynder **, 0xC) = arg0;
    M2C_FIELD(temp_r4_8190, s32 *, 4) = 0xB1;
    if ((Cynder *) M2C_FIELD(temp_r4_8190, Cynder **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_8190, s8 *, 9) = 1;
    }
    temp_r4_8201 = this->unk28;
    M2C_FIELD(temp_r4_8201, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_8201, Cynder **, 0xC) = arg0;
    M2C_FIELD(temp_r4_8201, s32 *, 4) = 0xB2;
    if ((Cynder *) M2C_FIELD(temp_r4_8201, Cynder **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_8201, s8 *, 9) = 1;
    }
    temp_r4_8212 = this->unk2C;
    M2C_FIELD(temp_r4_8212, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_8212, Cynder **, 0xC) = arg0;
    M2C_FIELD(temp_r4_8212, s32 *, 4) = 0xB3;
    if ((Cynder *) M2C_FIELD(temp_r4_8212, Cynder **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_8212, s8 *, 9) = 1;
    }
    temp_r4_8223 = this->unk30;
    M2C_FIELD(temp_r4_8223, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_8223, Cynder **, 0xC) = arg0;
    M2C_FIELD(temp_r4_8223, s32 *, 4) = 0x5B;
    if ((Cynder *) M2C_FIELD(temp_r4_8223, Cynder **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_8223, s8 *, 9) = 1;
    }
    this->unk34->Init(arg0);
}
#endif

void CynderBossGoal_AttackPhase2::Reset() {
    this->unk8 = 1;
    RemoveAllSubgoals();
    this->unk20 = NULL;
}

void CynderBossGoal_AttackPhase2::Terminate() {
    Cynder *temp_r3_8275;
    Cynder *temp_r3_8279;
    Cynder *temp_r3_8283;

    temp_r3_8275 = this->unkC;
    M2C_FIELD(temp_r3_8275, u8 *, 0xB01) = (u8) (M2C_FIELD(temp_r3_8275, u8 *, 0xB01) & ~0x80);
    temp_r3_8279 = this->unkC;
    temp_r3_8279->unk6B5 |= 0x20;
    temp_r3_8283 = this->unkC;
    temp_r3_8283->unk6B5 &= ~0x10;
    this->unkC->EnableFlyingRotation(0U);
    this->unk8 = 1;
    RemoveAllSubgoals();
}

#if 0 // DRAFT: illegal implicit conversion from 'void' to
u8 CynderBossGoal_AttackPhase2::Update() {
    Cynder *temp_r3_8326;
    Cynder *temp_r3_8349;
    Cynder *temp_r4_8313;
    u8 var_r31_8333;

    ActivateIfInactive();
    this->unk8 = UpdateSubgoals();
    temp_r4_8313 = this->unkC;
    M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
    if (temp_r4_8313->unkAB0 == 0.0f) {
        M2C_FIELD(temp_r4_8313, u8 *, 0xB01) = (u8) (M2C_FIELD(temp_r4_8313, u8 *, 0xB01) | 0x80);
    }
    if ((u8) this->unk8 != 0) {
        temp_r3_8326 = this->unkC;
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if (temp_r3_8326->unkAB0 == 0.0f) {
            var_r31_8333 = 0;
            if (((u8) M2C_FIELD(temp_r3_8326, u8 *, 0x8B8) == 2) || (temp_r3_8326->unk870.unk30.Get() != NULL)) {
                var_r31_8333 = 1;
            }
            if (var_r31_8333 != 0) {
                this->unkC->unkAD0 = 4e-45f;
                temp_r3_8349 = this->unkC;
                M2C_FIELD(temp_r3_8349, u8 *, 0xB01) = (u8) (M2C_FIELD(temp_r3_8349, u8 *, 0xB01) | 0x80);
            } else {
                goto block_9;
            }
        } else {
block_9:
            Activate();
        }
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk30C'
void CynderBossGoal_AttackPhase2::Activate() {
    this->unk8 = 0;
    RemoveAllSubgoals();
    M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
    if (gb.unk30C != M2C_BITWISE(f32, this->unkC->unkEFC.unk0)) {
        AddSubgoal__22CompositeGoal<6Cynder>FP13Goal<6Cynder>((CompositeGoal<Cynder> *) this, (Goal<Cynder> *) this->unk24);
        this->unk24->SetParams((AITargetData *) &this->unkC->unk838.unk28, this->unk20, 0U);
        return;
    }
    AddSubgoal__22CompositeGoal<6Cynder>FP13Goal<6Cynder>((CompositeGoal<Cynder> *) this, (Goal<Cynder> *) this->unk28);
}
#endif

void CynderBossGoal_AttackPhase2::Deinit() {
    Goal<Cynder> *temp_r3_8418;
    Goal<Cynder> *temp_r3_8423;
    MKHeap *temp_r3_8435;
    void *temp_r31_8432;

    temp_r3_8418 = this->unk24;
    temp_r3_8418->Deinit();
    temp_r3_8423 = this->unk28;
    temp_r3_8423->Deinit();
    operator delete(this->unk24);
    operator delete(this->unk28);
    temp_r31_8432 = this->unk1C;
    if (temp_r31_8432 != NULL) {
        temp_r3_8435 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_8435 != NULL) {
            ((MKHeap *) (temp_r3_8435->Current()))->Free(temp_r31_8432, NULL, 0);
        } else {
            free(temp_r31_8432);
        }
        this->unk1C = NULL;
    }
    this->unk10 = 0;
    this->unk18 = 0;
    this->unk14 = 0;
    this->unk8 = 1;
    this->unkC = NULL;
    this->unk9 = 0;
}

#if 0 // DRAFT: pointer/array required
void CynderBossGoal_AttackPhase2::Init(Cynder *arg0) {
    MKHeap *temp_r3_8536;
    void *var_r3_8543;

    if ((u8) this->unk9 == 0) {
        operator new(0x48U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__13Goal<6Cynder>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__22CompositeGoal<6Cynder>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x1C) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x18) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x10) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x14) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk24 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x44U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__13Goal<6Cynder>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__22CompositeGoal<6Cynder>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x1C) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x18) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x10) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x14) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk28 = M2C_ERROR(/* Read from unset register $r3 */);
    }
    if ((u8) this->unk9 == 0) {
        temp_r3_8536 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_8536 != NULL) {
            var_r3_8543 = ((MKHeap *) (temp_r3_8536->Current()))->Alloc(8, NULL, 0);
        } else {
            var_r3_8543 = malloc(8);
        }
        this->unk1C = var_r3_8543;
        this->unk10 = 2;
    }
    this->unk8 = 1;
    this->unkC = arg0;
    this->unk4 = 0xA7;
    if ((Cynder *) this->unkC != NULL) {
        this->unk9 = 1;
    }
    this->unk24->Init(arg0);
    this->unk28->Init(arg0);
}
#endif

void CynderBossGoal_AttackPhase1::Reset() {
    this->unk20 = NULL;
}

void CynderBossGoal_AttackPhase1::Terminate() {
    MKProp *temp_r3_8593;
    MKProp *temp_r4_8597;

    temp_r3_8593 = this->unkC;
    M2C_FIELD(temp_r3_8593, u8 *, 0xB01) = (u8) (M2C_FIELD(temp_r3_8593, u8 *, 0xB01) & ~0x80);
    temp_r4_8597 = this->unkC;
    ((EventMessage *) (temp_r4_8597 + 0xECC))->Send(temp_r4_8597);
    this->unk8 = 1;
    RemoveAllSubgoals();
}

#if 0 // DRAFT: illegal implicit conversion from 'void' to
u8 CynderBossGoal_AttackPhase1::Update() {
    EnemyHudData sp8;
    MKProp *temp_r4_8626;

    ActivateIfInactive();
    this->unk8 = UpdateSubgoals();
    if ((u8) this->unk8 != 0) {
        temp_r4_8626 = this->unkC;
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if (M2C_FIELD(temp_r4_8626, f32 *, 0xAC8) == 0.0f) {
            M2C_FIELD(temp_r4_8626, s32 *, 0xAE8) = (s32) (M2C_FIELD(temp_r4_8626, s32 *, 0xAE8) + 1);
            this->unkC->GetMaxHealth();
            this->unkC->SetHealth(M2C_ERROR(/* Read from unset register $f1 */));
            sp8.EnemyHudData();
            this->unkC->GetMaxHealth();
            sp8.Init((Enemy *) this->unkC, 0.0f, M2C_ERROR(/* Read from unset register $f1 */));
            EnemyHud_Modified(sp8);
        } else {
            Activate();
        }
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: illegal token
void CynderBossGoal_AttackPhase1::Activate() {
    this->unk8 = 0;
    RemoveAllSubgoals();
    if ((u8) M2C_FIELD(this->unkC, u8 *, 0xF19) != 0) {
        AddSubgoal__22CompositeGoal<6Cynder>FP13Goal<6Cynder>((CompositeGoal<Cynder> *) this, (Goal<Cynder> *) this->unk24);
    }
    AddSubgoal__22CompositeGoal<6Cynder>FP13Goal<6Cynder>((CompositeGoal<Cynder> *) this, (Goal<Cynder> *) this->unk28);
    this->unk28->SetParams(this->unkC + 0x870, this->unk20, 0U);
}
#endif

void CynderBossGoal_AttackPhase1::Deinit() {
    Goal<Cynder> *temp_r3_8709;
    Goal<Cynder> *temp_r3_8716;
    MKHeap *temp_r3_8726;
    void *temp_r31_8723;

    temp_r3_8709 = this->unk24;
    temp_r3_8709->Deinit();
    operator delete(this->unk24);
    temp_r3_8716 = this->unk28;
    temp_r3_8716->Deinit();
    operator delete(this->unk28);
    temp_r31_8723 = this->unk1C;
    if (temp_r31_8723 != NULL) {
        temp_r3_8726 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_8726 != NULL) {
            ((MKHeap *) (temp_r3_8726->Current()))->Free(temp_r31_8723, NULL, 0);
        } else {
            free(temp_r31_8723);
        }
        this->unk1C = NULL;
    }
    this->unk10 = 0;
    this->unk18 = 0;
    this->unk14 = 0;
    this->unk8 = 1;
    this->unkC = NULL;
    this->unk9 = 0;
}

#if 0 // DRAFT: pointer/array required
void CynderBossGoal_AttackPhase1::Init(Cynder *arg0) {
    MKHeap *temp_r3_8827;
    void *var_r3_8834;

    if ((u8) this->unk9 == 0) {
        operator new(0x34U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__13Goal<6Cynder>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__22CompositeGoal<6Cynder>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x1C) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x18) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x10) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x14) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk24 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x48U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__13Goal<6Cynder>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__22CompositeGoal<6Cynder>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x1C) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x18) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x10) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x14) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk28 = M2C_ERROR(/* Read from unset register $r3 */);
    }
    if ((u8) this->unk9 == 0) {
        temp_r3_8827 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_8827 != NULL) {
            var_r3_8834 = ((MKHeap *) (temp_r3_8827->Current()))->Alloc(8, NULL, 0);
        } else {
            var_r3_8834 = malloc(8);
        }
        this->unk1C = var_r3_8834;
        this->unk10 = 2;
    }
    this->unk8 = 1;
    this->unkC = (MKProp *) arg0;
    this->unk4 = 0xA6;
    if ((MKProp *) this->unkC != NULL) {
        this->unk9 = 1;
    }
    this->unk24->Init(arg0);
    this->unk28->Init(arg0);
}
#endif

#if 0 // DRAFT: undefined identifier 'sp8'
u8 CynderBossGoal_FlyAttack3::Update() {
    f64 sp20;
    f64 sp18;
    f32 sp10;
    Character *temp_r29_8896;
    Character *temp_r29_8922;
    Character *temp_r3_8914;
    Character *temp_r4_8880;
    u32 *temp_r4_8902;
    u32 *temp_r4_8917;
    u32 *temp_r4_8927;
    u32 *temp_r4_8940;
    u8 var_r30_8887;
    u8 var_r30_8936;

    ActivateIfInactive();
    temp_r4_8880 = this->unkC;
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r3, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
    var_r30_8887 = 0;
    M2C_FIELD(temp_r4_8880, f64 *, 0x598) = sp8;
    sp10 = temp_r4_8880->unkC8 * (2000.0f * gUpdateTimeDelta);
    sp18 = sp8;
    M2C_FIELD(temp_r4_8880, f64 *, 0x5A0) = (f64) sp10;
    temp_r29_8896 = this->unkC;
    sp20 = (f64) sp10;
    if (temp_r29_8896->HasAnimFinished() != 0) {
        temp_r4_8902 = temp_r29_8896->unkA50;
        if ((temp_r4_8902 != NULL) && ((u32) *temp_r4_8902 == (u32) M2C_FIELD(M2C_FIELD(temp_r29_8896, void **, 0x630), u32 *, 0x20))) {
            var_r30_8887 = 1;
        }
    }
    if (var_r30_8887 != 0) {
        temp_r3_8914 = this->unkC;
        temp_r4_8917 = temp_r3_8914->unkA50;
        temp_r3_8914->SetAnim((AnimSequence *) temp_r4_8917, (AnimTransition *) (temp_r4_8917 + 0x20), 0.0f, 0U);
    } else {
        temp_r29_8922 = this->unkC;
        if ((s32) M2C_FIELD(M2C_FIELD(temp_r29_8922, void **, 0x630), s32 *, 0x44) >= 1) {
            temp_r4_8927 = temp_r29_8922->unkA50;
            temp_r29_8922->SetAnim((AnimSequence *) temp_r4_8927, (AnimTransition *) (temp_r4_8927 + 0x40), 0.0f, 0U);
        } else {
            var_r30_8936 = 0;
            if (temp_r29_8922->HasAnimFinished() != 0) {
                temp_r4_8940 = temp_r29_8922->unkA50;
                if ((temp_r4_8940 != NULL) && ((u32) M2C_FIELD(temp_r4_8940, u32 *, 0x40) == (u32) M2C_FIELD(M2C_FIELD(temp_r29_8922, void **, 0x630), u32 *, 0x20))) {
                    var_r30_8936 = 1;
                }
            }
            if (var_r30_8936 != 0) {
                this->unk8 = 2;
            }
        }
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: undefined identifier 'SetRunMovementSpeed'
void CynderBossGoal_FlyAttack3::Activate() {
    AttackSweepData *temp_r3_9038;
    Character *temp_r3_8977;
    Character *temp_r3_8981;
    Character *temp_r3_9008;
    Character *temp_r3_9016;
    Character *temp_r4_9026;
    Character *temp_r5_8985;
    Character *temp_r7_8994;
    void *temp_r5_9022;

    this->unk8 = 0;
    temp_r3_8977 = this->unkC;
    temp_r3_8977->unk6B5 &= ~0x20;
    temp_r3_8981 = this->unkC;
    temp_r3_8981->unk6B5 |= 0x10;
    temp_r5_8985 = this->unkC;
    M2C_FIELD(temp_r5_8985, s32 *, 0xCFC) = (s32) (M2C_FIELD(temp_r5_8985, s32 *, 0xCFC) + 1);
    this->unkC->SetRunMovementSpeed(1U);
    this->unkC->SetMovementType((CharacterMoveType) 2);
    temp_r7_8994 = this->unkC;
    M2C_FIELD(temp_r7_8994, f64 *, 0xE0) = (f64) M2C_FIELD(temp_r7_8994, f64 *, 0xC0);
    M2C_FIELD(temp_r7_8994, f64 *, 0xE8) = (f64) M2C_FIELD(temp_r7_8994, f64 *, 0xC8);
    temp_r7_8994->unk6B5 |= 0x40;
    temp_r3_9008 = this->unkC;
    M2C_FIELD(temp_r3_9008, f64 *, 0xF0) = (f64) M2C_FIELD(&MKVector3::up, f64 *, 0);
    M2C_FIELD(temp_r3_9008, f64 *, 0xF8) = (f64) M2C_FIELD(&MKVector3::up, f64 *, 8);
    temp_r3_9008->unk6B5 |= 0x40;
    this->unkC->SelectAttack(0x10, 0x48);
    temp_r3_9016 = this->unkC;
    temp_r5_9022 = *temp_r3_9016->unkA20;
    temp_r3_9016->SetAnim((AnimSequenceType) M2C_FIELD(temp_r5_9022, s32 *, 0x6C), M2C_FIELD(temp_r5_9022, s32 *, 0x68), 0, 0.15f, 0U, 0U);
    temp_r4_9026 = this->unkC;
loop_2:
    if ((u32) *temp_r4_9026->unkA1C != 0U) {
        temp_r4_9026->unkA1C += 4;
        goto loop_2;
    }
    temp_r3_9038 = this->unkC->unkA30;
    if (temp_r3_9038 != NULL) {
        temp_r3_9038->SetDefaults();
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_sp10'
u8 CynderBossGoal_FlyAttack2::Update() {
    AnimSequence *temp_r4_9200;
    AnimSequence *temp_r4_9215;
    AnimSequence *temp_r4_9225;
    AnimSequence *temp_r4_9238;
    MKProp *temp_r29_9194;
    MKProp *temp_r29_9220;
    MKProp *temp_r30_9119;
    MKProp *temp_r3_9090;
    MKProp *temp_r3_9140;
    MKProp *temp_r3_9212;
    MKProp *temp_r4_9073;
    u8 temp_r3_9066;
    u8 var_r30_9195;
    u8 var_r30_9234;
    void *temp_r29_9122;
    ActivateIfInactive();
    temp_r3_9066 = this->unk8;
    if (temp_r3_9066 == 2) {
        return temp_r3_9066;
    }
    temp_r4_9073 = this->unkC;
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r3, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
    M2C_FIELD(temp_r4_9073, f64 *, 0x598) = arg_sp10;
    arg_sp18 = M2C_FIELD(temp_r4_9073, f32 *, 0xC8) * (2000.0f * gUpdateTimeDelta);
    arg_spA0 = arg_sp10;
    M2C_FIELD(temp_r4_9073, f64 *, 0x5A0) = (f64) arg_sp18;
    temp_r3_9090 = this->unkC;
    arg_spA8 = (f64) arg_sp18;
    MKModel_GetRefPointMatrix(temp_r3_9090->unk4, M2C_FIELD(M2C_FIELD(temp_r3_9090, void **, 0xA20), s32 *, 0x84), (Matrix *) &arg_spD0, 1U);
    arg_sp40 = -arg_spF0;
    arg_sp44 = -arg_spF4;
    arg_sp48 = -arg_spF8;
    arg_spC0 = (f64) arg_sp40;
    arg_spC8 = (f64) arg_sp48;
    arg_spB0 = arg_sp100;
    arg_spB8 = arg_sp108;
    if (((MKAnimScript *) (M2C_FIELD(this->unkC, MKAnimScript **, 0x630)))->CheckEvent(0) != 0) {
        temp_r30_9119 = this->unkC;
        temp_r29_9122 = M2C_FIELD(temp_r30_9119, void **, 0xA20);
        M2C_FIELD(temp_r30_9119->__vptr, M2C_UNK (**)(M2C_UNK *, MKProp *), 0xF8)(&arg_sp90, temp_r30_9119);
        ((CynderBreathFX *) (M2C_FIELD(temp_r30_9119, CynderBreathFX **, 0xCEC)))->Trigger(temp_r30_9119, *((MKVector3 *) &arg_spB0), *((MKVector3 *) &arg_spC0), *((MKVector3 *) &arg_sp90), 1.0f, M2C_FIELD(temp_r29_9122, s32 *, 0x84), 100.0f);
        M2C_FIELD(this->unkC, s8 *, 0xCB0) = 0;
    }
    temp_r3_9140 = this->unkC;
    if (((u8) M2C_FIELD(temp_r3_9140, u8 *, 0xB08) >> 4U) & 1) {
        arg_sp80 = arg_spB0;
        arg_sp88 = arg_spB8;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
        arg_sp60 = arg_sp30;
        arg_sp38 = (f32) arg_spC8 * 1500.0f;
        arg_sp68 = (f64) arg_sp38;
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        arg_sp70 = arg_sp20;
        arg_sp50 = arg_spC0;
        arg_sp28 = (f32) arg_spB8 + (f32) arg_sp68;
        arg_sp58 = arg_spC8;
        arg_sp78 = (f64) arg_sp28;
        ((CynderBreathFX *) (M2C_FIELD(temp_r3_9140, CynderBreathFX **, 0xCEC)))->UpdateBeam((MKVector3) &arg_sp80, (MKVector3) &arg_sp70, (MKVector3) &arg_sp50);
    }
    if (((MKAnimScript *) (M2C_FIELD(this->unkC, MKAnimScript **, 0x630)))->CheckEvent(1) != 0) {
        ((CynderBreathFX *) (M2C_FIELD(this->unkC, CynderBreathFX **, 0xCEC)))->End();
        M2C_FIELD(this->unkC, s8 *, 0xCB0) = 1;
    }
    temp_r29_9194 = this->unkC;
    var_r30_9195 = 0;
    if (temp_r29_9194->HasAnimFinished() != 0) {
        temp_r4_9200 = M2C_FIELD(temp_r29_9194, AnimSequence **, 0xA50);
        if ((temp_r4_9200 != NULL) && ((u32) temp_r4_9200->unk0 == (u32) M2C_FIELD(temp_r29_9194, MKAnimScript **, 0x630)->unk20)) {
            var_r30_9195 = 1;
        }
    }
    if (var_r30_9195 != 0) {
        temp_r3_9212 = this->unkC;
        temp_r4_9215 = M2C_FIELD(temp_r3_9212, AnimSequence **, 0xA50);
        temp_r3_9212->SetAnim(temp_r4_9215, temp_r4_9215 + 0x20, 0.0f, 0U);
    } else {
        temp_r29_9220 = this->unkC;
        if ((s32) M2C_FIELD(temp_r29_9220, MKAnimScript **, 0x630)->unk44 >= 1) {
            temp_r4_9225 = M2C_FIELD(temp_r29_9220, AnimSequence **, 0xA50);
            temp_r29_9220->SetAnim(temp_r4_9225, (AnimTransition *) &temp_r4_9225->unk40, 0.0f, 0U);
        } else {
            var_r30_9234 = 0;
            if (temp_r29_9220->HasAnimFinished() != 0) {
                temp_r4_9238 = M2C_FIELD(temp_r29_9220, AnimSequence **, 0xA50);
                if ((temp_r4_9238 != NULL) && ((u32) temp_r4_9238->unk40 == (u32) M2C_FIELD(temp_r29_9220, MKAnimScript **, 0x630)->unk20)) {
                    var_r30_9234 = 1;
                }
            }
            if (var_r30_9234 != 0) {
                this->unk8 = 2;
            }
        }
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: undefined identifier 'SetRunMovementSpeed'
void CynderBossGoal_FlyAttack2::Activate() {
    AttackSweepData *temp_r3_9350;
    MKProp *temp_r3_9286;
    MKProp *temp_r3_9293;
    MKProp *temp_r3_9320;
    MKProp *temp_r3_9328;
    MKProp *temp_r4_9338;
    MKProp *temp_r5_9297;
    MKProp *temp_r7_9306;
    void *temp_r5_9334;

    this->unk8 = 0;
    if (PhrasePlayer_IsEventPlaying(M2C_FIELD(this->unkC, s32 *, 0xD58)) != 0) {
        this->unk8 = 2;
        return;
    }
    temp_r3_9286 = this->unkC;
    M2C_FIELD(temp_r3_9286, u8 *, 0x6B5) = (u8) (M2C_FIELD(temp_r3_9286, u8 *, 0x6B5) & ~0x20);
    temp_r3_9293 = this->unkC;
    M2C_FIELD(temp_r3_9293, u8 *, 0x6B5) = (u8) (M2C_FIELD(temp_r3_9293, u8 *, 0x6B5) | 0x10);
    temp_r5_9297 = this->unkC;
    M2C_FIELD(temp_r5_9297, s32 *, 0xCFC) = (s32) (M2C_FIELD(temp_r5_9297, s32 *, 0xCFC) + 1);
    this->unkC->SetRunMovementSpeed(1U);
    this->unkC->SetMovementType((CharacterMoveType) 2);
    temp_r7_9306 = this->unkC;
    M2C_FIELD(temp_r7_9306, f64 *, 0xE0) = (f64) M2C_FIELD(temp_r7_9306, f64 *, 0xC0);
    M2C_FIELD(temp_r7_9306, f64 *, 0xE8) = (f64) M2C_FIELD(temp_r7_9306, f64 *, 0xC8);
    M2C_FIELD(temp_r7_9306, u8 *, 0x6B5) = (u8) (M2C_FIELD(temp_r7_9306, u8 *, 0x6B5) | 0x40);
    temp_r3_9320 = this->unkC;
    M2C_FIELD(temp_r3_9320, f64 *, 0xF0) = (f64) M2C_FIELD(&MKVector3::up, f64 *, 0);
    M2C_FIELD(temp_r3_9320, f64 *, 0xF8) = (f64) M2C_FIELD(&MKVector3::up, f64 *, 8);
    M2C_FIELD(temp_r3_9320, u8 *, 0x6B5) = (u8) (M2C_FIELD(temp_r3_9320, u8 *, 0x6B5) | 0x40);
    this->unkC->SelectAttack(0x10, 0x47);
    temp_r3_9328 = this->unkC;
    temp_r5_9334 = *M2C_FIELD(temp_r3_9328, void ***, 0xA20);
    temp_r3_9328->SetAnim((AnimSequenceType) M2C_FIELD(temp_r5_9334, s32 *, 0x6C), M2C_FIELD(temp_r5_9334, s32 *, 0x68), 0, 0.15f, 0U, 0U);
    temp_r4_9338 = this->unkC;
loop_4:
    if ((u32) *M2C_FIELD(temp_r4_9338, u32 **, 0xA1C) != 0U) {
        M2C_FIELD(temp_r4_9338, u32 **, 0xA1C) = (u32 *) (M2C_FIELD(temp_r4_9338, u32 **, 0xA1C) + 4);
        goto loop_4;
    }
    temp_r3_9350 = M2C_FIELD(this->unkC, AttackSweepData **, 0xA30);
    if (temp_r3_9350 != NULL) {
        temp_r3_9350->SetDefaults();
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'sp8'
u8 CynderBossGoal_FlyAttack1::Update() {
    f64 sp20;
    f64 sp18;
    f32 sp10;
    Character *temp_r29_9391;
    Character *temp_r29_9417;
    Character *temp_r3_9409;
    Character *temp_r4_9375;
    u32 *temp_r4_9397;
    u32 *temp_r4_9412;
    u32 *temp_r4_9422;
    u32 *temp_r4_9435;
    u8 var_r30_9382;
    u8 var_r30_9431;

    ActivateIfInactive();
    temp_r4_9375 = this->unkC;
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r3, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
    var_r30_9382 = 0;
    M2C_FIELD(temp_r4_9375, f64 *, 0x598) = sp8;
    sp10 = temp_r4_9375->unkC8 * (2000.0f * gUpdateTimeDelta);
    sp18 = sp8;
    M2C_FIELD(temp_r4_9375, f64 *, 0x5A0) = (f64) sp10;
    temp_r29_9391 = this->unkC;
    sp20 = (f64) sp10;
    if (temp_r29_9391->HasAnimFinished() != 0) {
        temp_r4_9397 = temp_r29_9391->unkA50;
        if ((temp_r4_9397 != NULL) && ((u32) *temp_r4_9397 == (u32) M2C_FIELD(M2C_FIELD(temp_r29_9391, void **, 0x630), u32 *, 0x20))) {
            var_r30_9382 = 1;
        }
    }
    if (var_r30_9382 != 0) {
        temp_r3_9409 = this->unkC;
        temp_r4_9412 = temp_r3_9409->unkA50;
        temp_r3_9409->SetAnim((AnimSequence *) temp_r4_9412, (AnimTransition *) (temp_r4_9412 + 0x20), 0.0f, 0U);
    } else {
        temp_r29_9417 = this->unkC;
        if ((s32) M2C_FIELD(M2C_FIELD(temp_r29_9417, void **, 0x630), s32 *, 0x44) >= 1) {
            temp_r4_9422 = temp_r29_9417->unkA50;
            temp_r29_9417->SetAnim((AnimSequence *) temp_r4_9422, (AnimTransition *) (temp_r4_9422 + 0x40), 0.0f, 0U);
        } else {
            var_r30_9431 = 0;
            if (temp_r29_9417->HasAnimFinished() != 0) {
                temp_r4_9435 = temp_r29_9417->unkA50;
                if ((temp_r4_9435 != NULL) && ((u32) M2C_FIELD(temp_r4_9435, u32 *, 0x40) == (u32) M2C_FIELD(M2C_FIELD(temp_r29_9417, void **, 0x630), u32 *, 0x20))) {
                    var_r30_9431 = 1;
                }
            }
            if (var_r30_9431 != 0) {
                this->unk8 = 2;
            }
        }
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: undefined identifier 'SetRunMovementSpeed'
void CynderBossGoal_FlyAttack1::Activate() {
    AttackSweepData *temp_r3_9533;
    Character *temp_r3_9472;
    Character *temp_r3_9476;
    Character *temp_r3_9503;
    Character *temp_r3_9511;
    Character *temp_r4_9521;
    Character *temp_r5_9480;
    Character *temp_r7_9489;
    void *temp_r5_9517;

    this->unk8 = 0;
    temp_r3_9472 = this->unkC;
    temp_r3_9472->unk6B5 &= ~0x20;
    temp_r3_9476 = this->unkC;
    temp_r3_9476->unk6B5 |= 0x10;
    temp_r5_9480 = this->unkC;
    M2C_FIELD(temp_r5_9480, s32 *, 0xCFC) = (s32) (M2C_FIELD(temp_r5_9480, s32 *, 0xCFC) + 1);
    this->unkC->SetRunMovementSpeed(1U);
    this->unkC->SetMovementType((CharacterMoveType) 2);
    temp_r7_9489 = this->unkC;
    M2C_FIELD(temp_r7_9489, f64 *, 0xE0) = (f64) M2C_FIELD(temp_r7_9489, f64 *, 0xC0);
    M2C_FIELD(temp_r7_9489, f64 *, 0xE8) = (f64) M2C_FIELD(temp_r7_9489, f64 *, 0xC8);
    temp_r7_9489->unk6B5 |= 0x40;
    temp_r3_9503 = this->unkC;
    M2C_FIELD(temp_r3_9503, f64 *, 0xF0) = (f64) M2C_FIELD(&MKVector3::up, f64 *, 0);
    M2C_FIELD(temp_r3_9503, f64 *, 0xF8) = (f64) M2C_FIELD(&MKVector3::up, f64 *, 8);
    temp_r3_9503->unk6B5 |= 0x40;
    this->unkC->SelectAttack(0x10, 0x46);
    temp_r3_9511 = this->unkC;
    temp_r5_9517 = *temp_r3_9511->unkA20;
    temp_r3_9511->SetAnim((AnimSequenceType) M2C_FIELD(temp_r5_9517, s32 *, 0x6C), M2C_FIELD(temp_r5_9517, s32 *, 0x68), 0, 0.15f, 0U, 0U);
    temp_r4_9521 = this->unkC;
loop_2:
    if ((u32) *temp_r4_9521->unkA1C != 0U) {
        temp_r4_9521->unkA1C += 4;
        goto loop_2;
    }
    temp_r3_9533 = this->unkC->unkA30;
    if (temp_r3_9533 != NULL) {
        temp_r3_9533->SetDefaults();
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk8C0'
u8 CynderBossGoal_GlideToAttack::Update() {
    f64 sp48;
    f32 sp38;
    f64 sp28;
    f64 sp20;
    f64 sp18;
    f32 sp10;
    Character *temp_r30_9585;
    Character *temp_r4_9558;
    Character *temp_r4_9566;
    Character *temp_r4_9614;
    Character *temp_r4_9619;
    Character *temp_r4_9627;
    Character *temp_r4_9640;
    f32 temp_f1_9580;
    f32 var_f30_9578;
    f32 var_f31_9586;
    u8 var_r0_9591;

    ActivateIfInactive();
    temp_r4_9558 = this->unkC;
    temp_r4_9558->unk8C0.Update(*((MKVector3 *) &temp_r4_9558->unk588));
    sp48.GetDir();
    temp_r4_9566 = this->unkC;
    M2C_FIELD(temp_r4_9566, f64 *, 0xE0) = sp48;
    M2C_FIELD(temp_r4_9566, f64 *, 0xE8) = sp50;
    temp_r4_9566->unk6B5 &= ~0x40;
    var_f30_9578 = 2000.0f * gUpdateTimeDelta;
    temp_f1_9580 = this->unkC->unk8C0.GetDist();
    if (temp_f1_9580 < var_f30_9578) {
        var_f30_9578 = temp_f1_9580;
    }
    temp_r30_9585 = this->unkC;
    var_f31_9586 = var_f30_9578;
    sp38.GetPos();
    var_r0_9591 = 0;
    if ((sp38 == M2C_FIELD(temp_r30_9585, f32 *, 0xD38)) && (sp3C == M2C_FIELD(temp_r30_9585, f32 *, 0xD3C)) && (sp40 == M2C_FIELD(temp_r30_9585, f32 *, 0xD40))) {
        var_r0_9591 = 1;
    }
    if ((var_r0_9591 != 0) && ((this->unkC->unk8C0.GetDist() - var_f30_9578) < 5.0f)) {
        temp_r4_9614 = this->unkC;
        temp_r4_9614->unk8C0.Set(*(temp_r4_9614 + 0xD48), 1U);
        temp_r4_9619 = this->unkC;
        temp_r4_9619->unk8C0.Update(*((MKVector3 *) &temp_r4_9619->unk588));
        sp28.GetDir();
        temp_r4_9627 = this->unkC;
        M2C_FIELD(temp_r4_9627, f64 *, 0xE0) = sp28;
        M2C_FIELD(temp_r4_9627, f64 *, 0xE8) = sp30;
        temp_r4_9627->unk6B5 &= ~0x40;
        var_f31_9586 = 2000.0f * gUpdateTimeDelta;
    }
    temp_r4_9640 = this->unkC;
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r3, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
    M2C_FIELD(temp_r4_9640, f64 *, 0x598) = sp8;
    sp10 = temp_r4_9640->unkC8 * var_f31_9586;
    sp18 = sp8;
    M2C_FIELD(temp_r4_9640, f64 *, 0x5A0) = (f64) sp10;
    sp20 = (f64) sp10;
    if (M2C_FIELD(M2C_FIELD(this->unkC, void **, 0x630), s32 *, 0x2C) & 2) {
        this->unk8 = 2;
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'AnimSequenceType' to
void CynderBossGoal_GlideToAttack::Activate() {
    Character *temp_r3_9686;
    Character *temp_r3_9690;

    this->unk8 = 0;
    temp_r3_9686 = this->unkC;
    temp_r3_9686->unk6B5 &= ~0x20;
    temp_r3_9690 = this->unkC;
    temp_r3_9690->unk6B5 |= 0x10;
    this->unkC->SetMovementType((CharacterMoveType) 2);
    this->unkC->unk684 = 0.3926991f;
    this->unkC->SetAnim((AnimSequenceType) 0xA, 0xE1, 1, 0.15f, 0U, 0U);
}
#endif

#if 0 // DRAFT: undefined identifier 'unk8C0'
u8 CynderBossGoal_GlideToLand::Update() {
    Character *temp_r3_9780;
    Character *temp_r4_9730;
    Character *temp_r4_9738;
    Character *temp_r4_9760;
    f32 temp_f1_9752;
    f32 temp_f2_9798;
    f32 temp_f31_9750;
    f32 temp_f3_9804;
    f32 temp_f4_9801;
    f32 temp_f6_9795;
    f32 temp_f7_9793;
    f32 temp_f8_9791;
    f32 var_f30_9755;
    ActivateIfInactive();
    temp_r4_9730 = this->unkC;
    temp_r4_9730->unk8C0.Update(*((MKVector3 *) &temp_r4_9730->unk588));
    arg_sp50.GetDir();
    temp_r4_9738 = this->unkC;
    M2C_FIELD(temp_r4_9738, f64 *, 0xE0) = arg_sp50;
    M2C_FIELD(temp_r4_9738, f64 *, 0xE8) = arg_sp58;
    temp_r4_9738->unk6B5 &= ~0x40;
    temp_f31_9750 = 3500.0f * gUpdateTimeDelta;
    temp_f1_9752 = this->unkC->unk8C0.GetDist();
    if (temp_f1_9752 < temp_f31_9750) {
        var_f30_9755 = temp_f1_9752;
    } else {
        var_f30_9755 = temp_f31_9750;
    }
    temp_r4_9760 = this->unkC;
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r3, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
    M2C_FIELD(temp_r4_9760, f64 *, 0x598) = arg_sp20;
    arg_sp28 = temp_r4_9760->unkC8 * var_f30_9755;
    arg_sp40 = arg_sp20;
    M2C_FIELD(temp_r4_9760, f64 *, 0x5A0) = (f64) arg_sp28;
    arg_sp48 = (f64) arg_sp28;
    if ((this->unkC->unk8C0.GetDist() - var_f30_9755) < var_f30_9755) {
        temp_r3_9780 = this->unkC;
        arg_sp90 = M2C_FIELD(temp_r3_9780, f32 *, 0x588);
        arg_sp94 = temp_r3_9780->unk588.unk0;
        arg_sp98 = temp_r3_9780->unk588.unk4;
        arg_sp9C = 1.0f;
        temp_f8_9791 = temp_r3_9780->unkC0;
        arg_sp80 = temp_f8_9791;
        temp_f7_9793 = temp_r3_9780->unkC4;
        arg_sp84 = temp_f7_9793;
        temp_f6_9795 = temp_r3_9780->unkC8;
        arg_sp88 = temp_f6_9795;
        arg_sp8C = 0.0f;
        temp_f2_9798 = temp_r3_9780->unkD0;
        arg_sp70 = temp_f2_9798;
        temp_f4_9801 = temp_r3_9780->unkD4;
        arg_sp74 = temp_f4_9801;
        temp_f3_9804 = temp_r3_9780->unkD8;
        arg_sp78 = temp_f3_9804;
        arg_sp18 = (temp_f2_9798 * temp_f7_9793) - (temp_f4_9801 * temp_f8_9791);
        arg_sp14 = (temp_f3_9804 * temp_f8_9791) - (temp_f2_9798 * temp_f6_9795);
        arg_sp10 = (temp_f4_9801 * temp_f6_9795) - (temp_f3_9804 * temp_f7_9793);
        arg_sp38 = (f64) arg_sp18;
        arg_sp30 = (f64) arg_sp10;
        arg_sp7C = 0.0f;
        arg_sp60 = (f32) arg_sp30;
        arg_sp64 = arg_sp34;
        arg_sp68 = (f32) arg_sp38;
        arg_sp6C = 0.0f;
        temp_r3_9780->Teleport(&arg_sp60, arg_sp34, (f32) arg_sp30, temp_f3_9804, temp_f4_9801, 0.0f, temp_f6_9795, temp_f7_9793, temp_f8_9791);
        this->unk8 = 2;
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: undefined identifier 'EnableFlyingRotation'
void CynderBossGoal_GlideToLand::Activate() {
    Character *temp_r3_9857;
    Character *temp_r3_9861;

    this->unk8 = 0;
    temp_r3_9857 = this->unkC;
    temp_r3_9857->unk6B5 &= ~0x20;
    temp_r3_9861 = this->unkC;
    temp_r3_9861->unk6B5 |= 0x10;
    this->unkC->SetMovementType((CharacterMoveType) 2);
    this->unkC->EnableFlyingRotation(0U);
    this->unkC->unk684 = 0.785398f;
    this->unkC->SetAnim((AnimSequenceType) 0xA, 0xE1, 1, 0.15f, 0U, 0U);
}
#endif

#if 0 // DRAFT: undefined identifier 'unk8C0'
u8 CynderBossGoal_Dive::Update() {
    AITargetData sp58;
    f64 sp50;
    f64 sp48;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp10;
    Character *temp_r29_10082;
    Character *temp_r29_9920;
    Character *temp_r3_9911;
    Character *temp_r3_9937;
    Character *temp_r4_10043;
    Character *temp_r4_10048;
    Character *temp_r4_10056;
    Character *temp_r4_10068;
    Character *temp_r4_9903;
    Character *temp_r4_9971;
    Character *temp_r4_9992;
    Character *temp_r6_9945;
    f32 temp_f1_10030;
    f32 temp_f1_9963;
    f32 temp_f29_10028;
    f32 temp_f31_9962;
    f32 var_f30_10029;
    f32 var_f30_9966;
    f32 var_f31_10036;
    u32 *temp_r4_10007;
    u32 *temp_r4_10088;
    u32 *temp_r4_9925;
    u32 *temp_r4_9940;
    u32 *temp_r4_9947;
    u8 var_r30_10073;
    u8 var_r30_9912;
    u8 var_r5_10008;
    u8 var_r5_9946;

    ActivateIfInactive();
    temp_r4_9903 = this->unkC;
    temp_r4_9903->unk8C0.Update(*((MKVector3 *) &temp_r4_9903->unk588));
    sp58.GetDir();
    temp_r3_9911 = this->unkC;
    var_r30_9912 = 0;
    M2C_FIELD(temp_r3_9911, f64 *, 0xE0) = M2C_BITWISE(f64, sp58);
    M2C_FIELD(temp_r3_9911, f64 *, 0xE8) = (f64) sp58.unk8;
    temp_r3_9911->unk6B5 &= ~0x40;
    temp_r29_9920 = this->unkC;
    if (temp_r29_9920->HasAnimFinished() != 0) {
        temp_r4_9925 = temp_r29_9920->unkA50;
        if ((temp_r4_9925 != NULL) && ((u32) *temp_r4_9925 == (u32) M2C_FIELD(M2C_FIELD(temp_r29_9920, void **, 0x630), u32 *, 0x20))) {
            var_r30_9912 = 1;
        }
    }
    if (var_r30_9912 != 0) {
        temp_r3_9937 = this->unkC;
        temp_r4_9940 = temp_r3_9937->unkA50;
        temp_r3_9937->SetAnim((AnimSequence *) temp_r4_9940, (AnimTransition *) (temp_r4_9940 + 0x20), 0.0f, 0U);
    } else {
        temp_r6_9945 = this->unkC;
        var_r5_9946 = 0;
        temp_r4_9947 = temp_r6_9945->unkA50;
        if ((temp_r4_9947 != NULL) && ((u32) M2C_FIELD(temp_r4_9947, u32 *, 0x20) == (u32) M2C_FIELD(M2C_FIELD(temp_r6_9945, void **, 0x630), u32 *, 0x20))) {
            var_r5_9946 = 1;
        }
        if (var_r5_9946 != 0) {
            temp_f31_9962 = 4000.0f * gUpdateTimeDelta;
            temp_f1_9963 = temp_r6_9945->unk8C0.GetDist();
            if (temp_f1_9963 < temp_f31_9962) {
                var_f30_9966 = temp_f1_9963;
            } else {
                var_f30_9966 = temp_f31_9962;
            }
            temp_r4_9971 = this->unkC;
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r3, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
            M2C_FIELD(temp_r4_9971, f64 *, 0x598) = sp18;
            sp20 = temp_r4_9971->unkC8 * var_f30_9966;
            sp48 = sp18;
            M2C_FIELD(temp_r4_9971, f64 *, 0x5A0) = (f64) sp20;
            sp50 = (f64) sp20;
            if ((this->unkC->unk8C0.GetDist() - var_f30_9966) < 5.0f) {
                temp_r4_9992 = this->unkC;
                temp_r4_9992->unk8C0.Set(*(temp_r4_9992 + 0xD38), 1U);
                this->unkC->SetAnim((AnimSequenceType) 0xA, 0xE2, 2, 0.15f, 0U, 0U);
            }
        } else {
            temp_r4_10007 = temp_r6_9945->unkA50;
            var_r5_10008 = 0;
            if ((temp_r4_10007 != NULL) && ((u32) M2C_FIELD(temp_r4_10007, u32 *, 0x40) == (u32) M2C_FIELD(M2C_FIELD(temp_r6_9945, void **, 0x630), u32 *, 0x20))) {
                var_r5_10008 = 1;
            }
            if (var_r5_10008 != 0) {
                temp_f29_10028 = (500.0f * (1.0f - M2C_FIELD(M2C_FIELD(temp_r6_9945, void **, 0x630), f32 *, 0x24))) + 3500.0f;
                var_f30_10029 = temp_f29_10028 * gUpdateTimeDelta;
                temp_f1_10030 = temp_r6_9945->unk8C0.GetDist();
                if (temp_f1_10030 < var_f30_10029) {
                    var_f30_10029 = temp_f1_10030;
                }
                var_f31_10036 = var_f30_10029;
                if ((this->unkC->unk8C0.GetDist() - var_f30_10029) < 5.0f) {
                    temp_r4_10043 = this->unkC;
                    temp_r4_10043->unk8C0.Set(*(temp_r4_10043 + 0xD48), 1U);
                    temp_r4_10048 = this->unkC;
                    temp_r4_10048->unk8C0.Update(*((MKVector3 *) &temp_r4_10048->unk588));
                    sp38.GetDir();
                    temp_r4_10056 = this->unkC;
                    M2C_FIELD(temp_r4_10056, f64 *, 0xE0) = sp38;
                    M2C_FIELD(temp_r4_10056, f64 *, 0xE8) = sp40;
                    temp_r4_10056->unk6B5 &= ~0x40;
                    var_f31_10036 = temp_f29_10028 * gUpdateTimeDelta;
                }
                temp_r4_10068 = this->unkC;
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r3, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
                var_r30_10073 = 0;
                M2C_FIELD(temp_r4_10068, f64 *, 0x598) = sp8;
                sp10 = temp_r4_10068->unkC8 * var_f31_10036;
                sp28 = sp8;
                M2C_FIELD(temp_r4_10068, f64 *, 0x5A0) = (f64) sp10;
                temp_r29_10082 = this->unkC;
                sp30 = (f64) sp10;
                if (temp_r29_10082->HasAnimFinished() != 0) {
                    temp_r4_10088 = temp_r29_10082->unkA50;
                    if ((temp_r4_10088 != NULL) && ((u32) M2C_FIELD(temp_r4_10088, u32 *, 0x40) == (u32) M2C_FIELD(M2C_FIELD(temp_r29_10082, void **, 0x630), u32 *, 0x20))) {
                        var_r30_10073 = 1;
                    }
                }
                if (var_r30_10073 != 0) {
                    this->unk8 = 2;
                }
            }
        }
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: undefined identifier 'EnableFlyingRotation'
void CynderBossGoal_Dive::Activate() {
    Character *temp_r3_10130;
    Character *temp_r3_10134;

    this->unk8 = 0;
    temp_r3_10130 = this->unkC;
    temp_r3_10130->unk6B5 &= ~0x20;
    temp_r3_10134 = this->unkC;
    temp_r3_10134->unk6B5 |= 0x10;
    this->unkC->unk684 = 0.3926991f;
    this->unkC->SetMovementType((CharacterMoveType) 2);
    this->unkC->EnableFlyingRotation(0U);
    this->unkC->SetAnim((AnimSequenceType) 0xA, 0xE0, 0, 0.15f, 0U, 0U);
}
#endif

#if 0 // DRAFT: undefined identifier 'Update'
u8 CynderBossGoal_FlyToDive::Update() {
    AITargetData sp60;
    M2C_UNK sp50;
    f64 sp48;
    f64 sp40;
    MKVector3 sp30;
    f32 sp20;
    f32 sp18;
    f32 sp8;
    Cynder *temp_r29_10314;
    Cynder *temp_r3_10196;
    Cynder *temp_r3_10206;
    Cynder *temp_r3_10222;
    Cynder *temp_r3_10231;
    Cynder *temp_r3_10277;
    Cynder *temp_r3_10309;
    Cynder *temp_r3_10345;
    Cynder *temp_r4_10175;
    Cynder *temp_r4_10245;
    Cynder *temp_r4_10259;
    Cynder *temp_r4_10295;
    Cynder *temp_r4_10300;
    Cynder *temp_r4_10361;
    Cynder *temp_r5_10183;
    EnemyDescriptor *temp_r4_10310;
    EnemyDescriptor *temp_r4_10316;
    EnemyDescriptor *temp_r4_10333;
    EnemyDescriptor *temp_r4_10348;
    f32 temp_f1_10202;
    f32 temp_f29_10211;
    f32 temp_f2_10232;
    f32 temp_f31_10266;
    f32 var_f30_10213;
    u8 var_r30_10329;
    u8 var_r5_10315;

    ActivateIfInactive();
    temp_r4_10175 = this->unkC;
    temp_r4_10175->unk870.unk40.Update(*((MKVector3 *) &temp_r4_10175->unk588));
    sp60.GetDir();
    temp_r5_10183 = this->unkC;
    M2C_FIELD(temp_r5_10183, f64 *, 0xE0) = M2C_BITWISE(f64, sp60);
    M2C_FIELD(temp_r5_10183, f64 *, 0xE8) = (f64) sp60.unk8;
    temp_r5_10183->unk6B5 |= 0x40;
    temp_r3_10196 = this->unkC;
    M2C_FIELD(temp_r3_10196, f64 *, 0xF0) = (f64) M2C_FIELD(&MKVector3::up, f64 *, 0);
    M2C_FIELD(temp_r3_10196, f64 *, 0xF8) = (f64) M2C_FIELD(&MKVector3::up, f64 *, 8);
    temp_r3_10196->unk6B5 |= 0x40;
    temp_f1_10202 = this->unk10;
    if (temp_f1_10202 > 0.0f) {
        temp_r3_10206 = this->unkC;
        temp_f29_10211 = 3000.0f * (temp_f1_10202 / 3.0f);
        if (((u8) M2C_FIELD(temp_r3_10206, u8 *, 0xB08) >> 7U) & 1) {
            var_f30_10213 = -1.0f;
        } else {
            var_f30_10213 = 1.0f;
        }
        if (temp_r3_10206->unk870.unk40.GetDist() < temp_f29_10211) {
            temp_r3_10222 = this->unkC;
            M2C_FIELD(temp_r3_10222, f32 *, 0xF98) = (f32) ((gUpdateTimeDelta * (temp_f29_10211 * (var_f30_10213 * M2C_BITWISE(f32, temp_r3_10222->unkF7C)))) + M2C_FIELD(temp_r3_10222, f32 *, 0xF98));
            temp_r3_10231 = this->unkC;
            temp_f2_10232 = M2C_FIELD(temp_r3_10231, f32 *, 0xF98);
            if (temp_f2_10232 > 1.0f) {
                M2C_FIELD(temp_r3_10231, f32 *, 0xF98) = (f32) (temp_f2_10232 - 1.0f);
            } else if (temp_f2_10232 < 0.0f) {
                M2C_FIELD(temp_r3_10231, f32 *, 0xF98) = (f32) (temp_f2_10232 + 1.0f);
            }
            temp_r4_10245 = this->unkC;
            sp8 = 0.0f;
            sp50.GetMeasure(M2C_FIELD(temp_r4_10245, f32 *, 0xF98), (Matrix *) &temp_r4_10245->unkCC0, KDSpline_PositionMixer);
            this->unkC->unk870.unk40.Set(*((MKVector3 *) &sp50), 1U);
            temp_r4_10259 = this->unkC;
            temp_r4_10259->unk870.unk40.Update(*((MKVector3 *) &temp_r4_10259->unk588));
        }
        temp_f31_10266 = gUpdateTimeDelta;
        sp30.operator*(temp_f29_10211);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
        temp_r3_10277 = this->unkC;
        M2C_FIELD(temp_r3_10277, f64 *, 0x598) = sp10;
        sp18 = sp30.unk8 * temp_f31_10266;
        sp40 = sp10;
        M2C_FIELD(temp_r3_10277, f64 *, 0x5A0) = (f64) sp18;
        sp48 = (f64) sp18;
        this->unk10 -= gUpdateTimeDelta;
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if (this->unk10 == 0.0f) {
            this->unkC->CalculateDiveTrajectory();
            temp_r4_10295 = this->unkC;
            temp_r4_10295->unk870.unk40.Set(*((MKVector3 *) &temp_r4_10295->unkD10), 0U);
            temp_r4_10300 = this->unkC;
            temp_r4_10300->unk870.unk40.Update(*((MKVector3 *) &temp_r4_10300->unk588));
            this->unkC->unk684 = 0.785398f;
            temp_r3_10309 = this->unkC;
            temp_r4_10310 = temp_r3_10309->unkA38;
            temp_r3_10309->SetAnim((AnimSequence *) temp_r4_10310, (AnimTransition *) &temp_r4_10310->unk20, 0.0f, 0U);
        }
    }
    temp_r29_10314 = this->unkC;
    var_r5_10315 = 0;
    temp_r4_10316 = temp_r29_10314->unkA38;
    if ((temp_r4_10316 != NULL) && ((s8 *) temp_r4_10316->unk0 == (u32) M2C_FIELD(M2C_FIELD(temp_r29_10314, void **, 0x630), u32 *, 0x20))) {
        var_r5_10315 = 1;
    }
    if (var_r5_10315 != 0) {
        var_r30_10329 = 0;
        if (temp_r29_10314->HasAnimFinished() != 0) {
            temp_r4_10333 = temp_r29_10314->unkA38;
            if ((temp_r4_10333 != NULL) && ((s8 *) temp_r4_10333->unk0 == (u32) M2C_FIELD(M2C_FIELD(temp_r29_10314, void **, 0x630), u32 *, 0x20))) {
                var_r30_10329 = 1;
            }
        }
        if (var_r30_10329 != 0) {
            temp_r3_10345 = this->unkC;
            temp_r4_10348 = temp_r3_10345->unkA38;
            temp_r3_10345->SetAnim((AnimSequence *) temp_r4_10348, (AnimTransition *) &temp_r4_10348->unk20, 0.0f, 0U);
        }
    } else {
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if (this->unk10 == 0.0f) {
            sp20.GetDir();
            temp_r4_10361 = this->unkC;
            M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
            if (((temp_r4_10361->unkC8 * sp28) + ((temp_r4_10361->unkC0 * sp20) + (temp_r4_10361->unkC4 * sp24))) == 0.999f) {
                temp_r4_10361->unk870.unk40.Set(*((MKVector3 *) &temp_r4_10361->unkD10), 1U);
                this->unk8 = 2;
            }
        }
    }
    return this->unk8;
}
#endif

void CynderBossGoal_FlyToDive::Activate() {
    Cynder *temp_r3_10408;
    Cynder *temp_r3_10412;

    this->unk8 = 0;
    temp_r3_10408 = this->unkC;
    temp_r3_10408->unk6B5 &= ~0x20;
    temp_r3_10412 = this->unkC;
    temp_r3_10412->unk6B5 |= 0x10;
    this->unkC->SetMovementType((CharacterMoveType) 2);
    this->unkC->SetAnim((AnimSequenceType) 0xA, 0xDF, 0, 0.15f, 0U, 0U);
    this->unkC->EnableFlyingRotation(0U);
    this->unk10 = 3.0f;
}

#if 0 // DRAFT: undefined identifier 'unk8C0'
u8 CynderBossGoal_FlyAlongWaypoints::Update() {
    f64 sp30;
    f64 sp28;
    MKVector3 sp18;
    f32 sp10;
    Character *temp_r3_10495;
    Character *temp_r4_10449;
    Character *temp_r4_10477;
    f32 temp_f31_10484;
    s32 temp_r3_10460;

    ActivateIfInactive();
    temp_r4_10449 = this->unkC;
    temp_r4_10449->unk8C0.Update(*((MKVector3 *) &temp_r4_10449->unk588));
    if (this->unkC->unk8C0.GetDist() < 1000.0f) {
        temp_r3_10460 = this->unk18 + 1;
        this->unk18 = temp_r3_10460;
        if (temp_r3_10460 >= (s32) this->unk14) {
            this->unk8 = 2;
        } else {
            this->unkC->unk8C0.Set(*(this->unk10 + (this->unk18 * 0x10)), 1U);
            temp_r4_10477 = this->unkC;
            temp_r4_10477->unk8C0.Update(*((MKVector3 *) &temp_r4_10477->unk588));
        }
    }
    temp_f31_10484 = gUpdateTimeDelta;
    sp18.operator*(3000.0f);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
    temp_r3_10495 = this->unkC;
    sp28 = sp8;
    sp10 = sp18.unk8 * temp_f31_10484;
    M2C_FIELD(temp_r3_10495, f64 *, 0x598) = sp8;
    M2C_FIELD(temp_r3_10495, f64 *, 0x5A0) = (f64) sp10;
    sp30 = (f64) sp10;
    return this->unk8;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk8C0'
void CynderBossGoal_FlyAlongWaypoints::Activate() {
    Character *temp_r3_10524;
    Character *temp_r3_10528;
    Character *temp_r4_10544;

    this->unk8 = 0;
    temp_r3_10524 = this->unkC;
    temp_r3_10524->unk6B5 &= ~0x20;
    temp_r3_10528 = this->unkC;
    temp_r3_10528->unk6B5 |= 0x10;
    this->unkC->SetMovementType((CharacterMoveType) 2);
    this->unk18 = 0;
    this->unkC->unk8C0.Set(*(this->unk10 + (this->unk18 * 0x10)), 1U);
    temp_r4_10544 = this->unkC;
    temp_r4_10544->unk8C0.Update(*((MKVector3 *) &temp_r4_10544->unk588));
    this->unkC->EnableFlyingRotation(1U);
    this->unkC->SetAnim((AnimSequenceType) 0xA, 0xDE, 0, 0.15f, 0U, 0U);
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void CynderBossGoal_FlyAlongSpline::PerformBreathAttack() {
    Cynder *temp_r3_10586;
    void *temp_r5_10592;

    this->unk24 |= 0x20;
    M2C_FIELD(this->unkC->unkCD4, f32 *, 0x1C8) = 200.0f;
    this->unkC->SelectAttack(0x10, 0x47);
    temp_r3_10586 = this->unkC;
    temp_r5_10592 = temp_r3_10586->unkA08->__vptr;
    temp_r3_10586->SetAnim((AnimSequenceType) M2C_FIELD(temp_r5_10592, s32 *, 0x6C), M2C_FIELD(temp_r5_10592, s32 *, 0x68), 0, 0.15f, 0U, 0U);
}
#endif

#if 0 // DRAFT: pointer/array required
void CynderBossGoal_FlyAlongSpline::Terminate() {
    if (((u8) this->unk24 >> 5U) & 1) {
        this->unkC->unkCD4->End();
    }
    this->unk24 &= ~0x20;
    this->unkC->unkCB0 = 1;
    this->unk8 = 1;
}
#endif

#if 0 // DRAFT: undefined identifier 'Update'
u8 CynderBossGoal_FlyAlongSpline::Update() {
    CharacterFireFX *temp_r29_10999;
    Cynder *temp_r29_11065;
    Cynder *temp_r29_11091;
    Cynder *temp_r30_10996;
    Cynder *temp_r3_10956;
    Cynder *temp_r3_10966;
    Cynder *temp_r3_11014;
    Cynder *temp_r3_11083;
    Cynder *temp_r4_10655;
    Cynder *temp_r4_10831;
    Cynder *temp_r4_10922;
    EnemyDescriptor *temp_r4_11071;
    EnemyDescriptor *temp_r4_11086;
    EnemyDescriptor *temp_r4_11096;
    EnemyDescriptor *temp_r4_11109;
    f32 temp_f1_10690;
    f32 temp_f27_10665;
    f32 temp_f29_10945;
    f32 temp_f2_10884;
    f32 temp_f31_10714;
    f32 temp_f3_10691;
    f32 var_f3_10811;
    f32 var_f4_10744;
    f64 temp_f1_10750;
    f64 temp_f1_10756;
    f64 temp_f1_10760;
    s32 temp_r3_10779;
    s32 var_r0_10789;
    u8 var_r30_11066;
    u8 var_r30_11105;
    void *temp_r3_10678;
    void *temp_r3_10834;
    ActivateIfInactive();
    temp_r4_10655 = this->unkC;
    temp_r4_10655->unk870.unk40.Update(*((MKVector3 *) &temp_r4_10655->unk588));
    temp_f27_10665 = 10.0f * (3000.0f * gUpdateTimeDelta);
    if (((u8) this->unk24 >> 7U) & 1) {
        arg_sp20 = 0.0f;
        arg_sp1A8.GetMeasure(this->unk18, (Matrix *) this->unk10, KDSpline_PositionMixer);
        temp_r3_10678 = this->unkC->unk8;
        arg_sp1F8 = arg_sp1A8;
        arg_sp200 = arg_sp1B0;
        arg_sp198 = M2C_FIELD(temp_r3_10678, f64 *, 0x30);
        arg_sp1A0 = M2C_FIELD(temp_r3_10678, f64 *, 0x38);
        temp_f1_10690 = (f32) arg_sp1F8 - (f32) arg_sp198;
        temp_f3_10691 = (f32) arg_sp200 - (f32) arg_sp1A0;
        if (((temp_f1_10690 * temp_f1_10690) + (temp_f3_10691 * temp_f3_10691)) < (temp_f27_10665 * temp_f27_10665)) {
            this->unk8 = 2;
        }
    }
    arg_sp1C = 0.0f;
    arg_sp188.GetMeasure(this->unk1C, (Matrix *) this->unk10, KDSpline_PositionMixer);
    temp_f31_10714 = this->unk20;
    arg_sp1E8 = arg_sp188;
    arg_sp1F0 = arg_sp190;
    arg_sp18 = 0.0f;
    arg_spC8.GetMeasure(this->unk1C, (Matrix *) this->unk10, KDSpline_VelocityMixer);
    arg_spB8 = arg_spC8;
    arg_spC0 = arg_spD0;
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
    arg_sp168 = arg_sp98;
    arg_spA0 = (f32) arg_spC0 * arg_sp18;
    arg_sp170 = (f64) arg_spA0;
    var_f4_10744 = ((f32) arg_sp170 * (f32) arg_sp170) + (((f32) arg_sp168 * (f32) arg_sp168) + (arg_sp16C * arg_sp16C));
    if (var_f4_10744 > 1e-12f) {
        if (var_f4_10744 > 0.0f) {
            temp_f1_10750 = __frsqrte(var_f4_10744);
            temp_f1_10756 = 0.5 * temp_f1_10750 * -(((f64) var_f4_10744 * (temp_f1_10750 * temp_f1_10750)) - 3.0);
            temp_f1_10760 = 0.5 * temp_f1_10756 * -(((f64) var_f4_10744 * (temp_f1_10756 * temp_f1_10756)) - 3.0);
            var_f4_10744 = (f32) ((f64) var_f4_10744 * (0.5 * temp_f1_10760 * -(((f64) var_f4_10744 * (temp_f1_10760 * temp_f1_10760)) - 3.0)));
        } else if (var_f4_10744 < M2C_BITWISE(f32, 0.0)) {
            var_f4_10744 = __float_nan;
        } else {
            arg_sp10 = var_f4_10744;
            temp_r3_10779 = M2C_BITWISE(s32, arg_sp10) & 0x7F800000;
            switch (temp_r3_10779) {                /* irregular */
            case 0x7F800000:
                if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                    var_r0_10789 = 1;
                } else {
                    var_r0_10789 = 2;
                }
                break;
            case 0x0:
                if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                    var_r0_10789 = 5;
                } else {
                    var_r0_10789 = 3;
                }
                break;
            default:
                var_r0_10789 = 4;
                break;
            }
            if (var_r0_10789 == 1) {
                var_f4_10744 = __float_nan;
            }
        }
        var_f3_10811 = 1.0f / var_f4_10744;
    } else {
        var_f3_10811 = 0.0f;
    }
    arg_sp8C = arg_sp16C * var_f3_10811;
    arg_sp88 = (f32) arg_sp168 * var_f3_10811;
    arg_sp90 = (f32) arg_sp170 * var_f3_10811;
    arg_sp178 = (f64) arg_sp88;
    arg_sp180 = (f64) arg_sp90;
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
    temp_r4_10831 = this->unkC;
    temp_r3_10834 = temp_r4_10831->unk8;
    arg_sp1D8 = arg_spA8;
    arg_spB0 = (f32) arg_sp180 * temp_f31_10714;
    arg_sp158 = M2C_FIELD(temp_r3_10834, f64 *, 0x30);
    arg_sp1E0 = (f64) arg_spB0;
    arg_sp160 = M2C_FIELD(temp_r3_10834, f64 *, 0x38);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    arg_sp78 = arg_sp38;
    arg_sp40 = (f32) arg_sp160 - (f32) arg_sp1F0;
    arg_sp80 = (f64) arg_sp40;
    if ((((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1EU) & 1) || (temp_r4_10831->unk870.unk40.GetDist() < temp_f27_10665)) {
        this->unk1C += 2.0f * (temp_f27_10665 * (this->unk20 * M2C_BITWISE(f32, this->unkC->unkF7C)));
        temp_f2_10884 = this->unk1C;
        if (temp_f2_10884 > 1.0f) {
            if (((u8) this->unk24 >> 6U) & 1) {
                this->unk1C = 1.0f;
            } else {
                this->unk1C = temp_f2_10884 - 1.0f;
            }
        } else if (temp_f2_10884 < 0.0f) {
            if (((u8) this->unk24 >> 6U) & 1) {
                this->unk1C = 0.0f;
            } else {
                this->unk1C = temp_f2_10884 + 1.0f;
            }
        }
        arg_sp14 = 0.0f;
        arg_sp148.GetMeasure(this->unk1C, (Matrix *) this->unk10, KDSpline_PositionMixer);
        this->unkC->unk870.unk40.Set(*((MKVector3 *) &arg_sp148), 1U);
        temp_r4_10922 = this->unkC;
        temp_r4_10922->unk870.unk40.Update(*((MKVector3 *) &temp_r4_10922->unk588));
        if (((u8) this->unk24 >> 6U) & 1) {
            M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
            if ((this->unk1C == 1.0f) && (this->unkC->unk870.unk40.GetDist() < 500.0f)) {
                this->unk8 = 2;
            }
        }
    }
    temp_f29_10945 = gUpdateTimeDelta;
    arg_sp128.operator*(3000.0f);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
    temp_r3_10956 = this->unkC;
    arg_sp138 = arg_sp28;
    arg_sp30 = arg_sp130 * temp_f29_10945;
    M2C_FIELD(temp_r3_10956, f64 *, 0x598) = arg_sp28;
    M2C_FIELD(temp_r3_10956, f64 *, 0x5A0) = (f64) arg_sp30;
    arg_sp140 = (f64) arg_sp30;
    if (((u8) this->unk24 >> 5U) & 1) {
        temp_r3_10966 = this->unkC;
        MKModel_GetRefPointMatrix(temp_r3_10966->unk4, M2C_FIELD(temp_r3_10966->unkA08, s32 *, 0x84), (Matrix *) &arg_sp210, 1U);
        arg_sp68 = -arg_sp230;
        arg_sp6C = -arg_sp234;
        arg_sp70 = -arg_sp238;
        arg_sp1C8 = (f64) arg_sp68;
        arg_sp1D0 = (f64) arg_sp70;
        arg_sp1B8 = arg_sp240;
        arg_sp1C0 = arg_sp248;
        if (((MKAnimScript *) (M2C_FIELD(this->unkC, MKAnimScript **, 0x630)))->CheckEvent(0) != 0) {
            temp_r30_10996 = this->unkC;
            temp_r29_10999 = temp_r30_10996->unkA08;
            M2C_FIELD(temp_r30_10996->__vptr, M2C_UNK (**)(M2C_UNK *, Cynder *), 0xF8)(&arg_sp118, temp_r30_10996);
            temp_r30_10996->unkCD4->Trigger((MKProp *) temp_r30_10996, *((MKVector3 *) &arg_sp1B8), *((MKVector3 *) &arg_sp1C8), *((MKVector3 *) &arg_sp118), 1.0f, M2C_FIELD(temp_r29_10999, s32 *, 0x84), 100.0f);
        }
        temp_r3_11014 = this->unkC;
        if (((u8) M2C_FIELD(temp_r3_11014, u8 *, 0xB08) >> 4U) & 1) {
            arg_sp108 = arg_sp1B8;
            arg_sp110 = arg_sp1C0;
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f28 */);
            arg_spE8 = arg_sp58;
            arg_sp60 = (f32) arg_sp1D0 * 1500.0f;
            arg_spF0 = (f64) arg_sp60;
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            arg_spF8 = arg_sp48;
            arg_spD8 = arg_sp1C8;
            arg_sp50 = (f32) arg_sp1C0 + (f32) arg_spF0;
            arg_spE0 = arg_sp1D0;
            arg_sp100 = (f64) arg_sp50;
            temp_r3_11014->unkCD4->UpdateBeam((MKVector3) &arg_sp108, (MKVector3) &arg_spF8, (MKVector3) &arg_spD8);
        }
        if (((MKAnimScript *) (M2C_FIELD(this->unkC, MKAnimScript **, 0x630)))->CheckEvent(1) != 0) {
            this->unkC->unkCD4->End();
        }
        temp_r29_11065 = this->unkC;
        var_r30_11066 = 0;
        if (temp_r29_11065->HasAnimFinished() != 0) {
            temp_r4_11071 = temp_r29_11065->unkA38;
            if ((temp_r4_11071 != NULL) && ((s8 *) temp_r4_11071->unk0 == (u32) M2C_FIELD(temp_r29_11065, MKAnimScript **, 0x630)->unk20)) {
                var_r30_11066 = 1;
            }
        }
        if (var_r30_11066 != 0) {
            temp_r3_11083 = this->unkC;
            temp_r4_11086 = temp_r3_11083->unkA38;
            temp_r3_11083->SetAnim((AnimSequence *) temp_r4_11086, (AnimTransition *) &temp_r4_11086->unk20, 0.0f, 0U);
        } else {
            temp_r29_11091 = this->unkC;
            if ((s32) M2C_FIELD(temp_r29_11091, MKAnimScript **, 0x630)->unk44 >= 3) {
                temp_r4_11096 = temp_r29_11091->unkA38;
                temp_r29_11091->SetAnim((AnimSequence *) temp_r4_11096, (AnimTransition *) &temp_r4_11096->__vptr, 0.0f, 0U);
            } else {
                var_r30_11105 = 0;
                if (temp_r29_11091->HasAnimFinished() != 0) {
                    temp_r4_11109 = temp_r29_11091->unkA38;
                    if ((temp_r4_11109 != NULL) && ((void *) temp_r4_11109->__vptr == (u32) M2C_FIELD(temp_r29_11091, MKAnimScript **, 0x630)->unk20)) {
                        var_r30_11105 = 1;
                    }
                }
                if (var_r30_11105 != 0) {
                    this->unk24 &= ~0x20;
                    this->unkC->SetAnim((AnimSequenceType) 0xA, 0xDE, 0, 0.15f, 0U, 0U);
                }
            }
        }
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'float' to
void CynderBossGoal_FlyAlongSpline::Activate() {
    f64 spC0;
    f64 spB8;
    f64 spB0;
    f64 spA8;
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    KDUniformSpline sp68;
    f64 sp60;
    f64 sp58;
    f32 sp50;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    Cynder *temp_r3_11167;
    Cynder *temp_r3_11171;
    Cynder *temp_r3_11294;
    Cynder *temp_r4_11420;
    Cynder *temp_r4_11437;
    f32 var_f2_11289;
    f32 var_f4_11222;
    f32 var_f6_11320;
    f32 var_f9_11302;
    f64 temp_f1_11228;
    f64 temp_f1_11234;
    f64 temp_f1_11238;
    f64 temp_f2_11327;
    f64 temp_f2_11333;
    f64 temp_f2_11337;
    f64 temp_f5_11299;
    s32 temp_r3_11257;
    s32 temp_r3_11356;
    s32 var_r0_11267;
    s32 var_r0_11366;

    this->unk8 = 0;
    temp_r3_11167 = this->unkC;
    temp_r3_11167->unk6B5 &= ~0x20;
    temp_r3_11171 = this->unkC;
    temp_r3_11171->unk6B5 |= 0x10;
    this->unkC->SetMovementType((CharacterMoveType) 2);
    this->unkC->unkF7C = 1.0f / this->unk10->unk8;
    this->unk1C = this->unk14;
    this->unk20 = 1.0f;
    this->unk24 &= ~0x80;
    this->unk18 = 0.0f;
    sp14 = 0.0f;
    sp68.GetMeasure(this->unk1C, (Matrix *) this->unk10, KDSpline_VelocityMixer);
    sp58 = M2C_BITWISE(f64, sp68);
    sp60 = (f64) sp68.unk8;
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
    sp98 = sp48;
    sp50 = (f32) sp60 * sp14;
    spA0 = (f64) sp50;
    var_f4_11222 = ((f32) spA0 * (f32) spA0) + (((f32) sp98 * (f32) sp98) + (unksp9C * unksp9C));
    if (var_f4_11222 > 1e-12f) {
        if (var_f4_11222 > 0.0f) {
            temp_f1_11228 = __frsqrte(var_f4_11222);
            temp_f1_11234 = 0.5 * temp_f1_11228 * -(((f64) var_f4_11222 * (temp_f1_11228 * temp_f1_11228)) - 3.0);
            temp_f1_11238 = 0.5 * temp_f1_11234 * -(((f64) var_f4_11222 * (temp_f1_11234 * temp_f1_11234)) - 3.0);
            var_f4_11222 = (f32) ((f64) var_f4_11222 * (0.5 * temp_f1_11238 * -(((f64) var_f4_11222 * (temp_f1_11238 * temp_f1_11238)) - 3.0)));
        } else if (var_f4_11222 < M2C_BITWISE(f32, 0.0)) {
            var_f4_11222 = __float_nan;
        } else {
            spC = var_f4_11222;
            temp_r3_11257 = M2C_BITWISE(s32, spC) & 0x7F800000;
            switch (temp_r3_11257) {                /* switch 1; irregular */
            case 0x7F800000:                        /* switch 1 */
                if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                    var_r0_11267 = 1;
                } else {
                    var_r0_11267 = 2;
                }
                break;
            case 0x0:                               /* switch 1 */
                if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                    var_r0_11267 = 5;
                } else {
                    var_r0_11267 = 3;
                }
                break;
            default:                                /* switch 1 */
                var_r0_11267 = 4;
                break;
            }
            if (var_r0_11267 == 1) {
                var_f4_11222 = __float_nan;
            }
        }
        var_f2_11289 = 1.0f / var_f4_11222;
    } else {
        var_f2_11289 = 0.0f;
    }
    temp_r3_11294 = this->unkC;
    temp_f5_11299 = M2C_FIELD(temp_r3_11294, f64 *, 0xC8);
    sp28 = M2C_FIELD(temp_r3_11294, f64 *, 0xC0);
    var_f9_11302 = 0.0f;
    sp90 = temp_f5_11299;
    unksp2C = 0.0f;
    sp40 = (f32) spA0 * var_f2_11289;
    sp88 = sp28;
    sp38 = (f32) sp98 * var_f2_11289;
    sp3C = unksp9C * var_f2_11289;
    spC0 = (f64) sp40;
    var_f6_11320 = ((f32) sp90 * (f32) sp90) + (((f32) sp88 * (f32) sp88) + (unksp8C * unksp8C));
    spB8 = (f64) sp38;
    sp30 = temp_f5_11299;
    if (var_f6_11320 > 1e-12f) {
        if (var_f6_11320 > 0.0f) {
            temp_f2_11327 = __frsqrte(var_f6_11320);
            temp_f2_11333 = 0.5 * temp_f2_11327 * -(((f64) var_f6_11320 * (temp_f2_11327 * temp_f2_11327)) - 3.0);
            temp_f2_11337 = 0.5 * temp_f2_11333 * -(((f64) var_f6_11320 * (temp_f2_11333 * temp_f2_11333)) - 3.0);
            var_f6_11320 = (f32) ((f64) var_f6_11320 * (0.5 * temp_f2_11337 * -(((f64) var_f6_11320 * (temp_f2_11337 * temp_f2_11337)) - 3.0)));
        } else if (var_f6_11320 < M2C_BITWISE(f32, 0.0)) {
            var_f6_11320 = __float_nan;
        } else {
            sp8 = var_f6_11320;
            temp_r3_11356 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r3_11356) {                /* switch 2; irregular */
            case 0x7F800000:                        /* switch 2 */
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_11366 = 1;
                } else {
                    var_r0_11366 = 2;
                }
                break;
            case 0x0:                               /* switch 2 */
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_11366 = 5;
                } else {
                    var_r0_11366 = 3;
                }
                break;
            default:                                /* switch 2 */
                var_r0_11366 = 4;
                break;
            }
            if (var_r0_11366 == 1) {
                var_f6_11320 = __float_nan;
            }
        }
        var_f9_11302 = 1.0f / var_f6_11320;
    }
    sp1C = unksp8C * var_f9_11302;
    sp18 = (f32) sp88 * var_f9_11302;
    sp20 = (f32) sp90 * var_f9_11302;
    spA8 = (f64) sp18;
    spB0 = (f64) sp20;
    if ((((f32) spB0 * (f32) spC0) + (((f32) spA8 * (f32) spB8) + (unkspAC * unkspBC))) < 0.0f) {
        this->unk20 = -1.0f;
    }
    temp_r4_11420 = this->unkC;
    M2C_FIELD(temp_r4_11420, u8 *, 0xB08) = (u8) ((M2C_FIELD(temp_r4_11420, u8 *, 0xB08) & ~0x80) | ((((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1FU) << 7) & 0x80));
    sp10 = 0.0f;
    sp68.unk10.GetMeasure(this->unk1C, (Matrix *) this->unk10, KDSpline_PositionMixer);
    this->unkC->unk870.unk40.Set(*((MKVector3 *) &sp68.unk10), 1U);
    temp_r4_11437 = this->unkC;
    temp_r4_11437->unk870.unk40.Update(*((MKVector3 *) &temp_r4_11437->unk588));
    this->unkC->EnableFlyingRotation(1U);
    this->unkC->SetAnim((AnimSequenceType) 0xA, 0xDE, 0, 0.15f, 0U, 0U);
    this->unkC->unkCB0 = 0;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk8C0'
u8 CynderBossGoal_Fly::Update() {
    KDUniformSpline sp60;
    f64 sp58;
    f64 sp50;
    MKVector3 sp40;
    f64 sp38;
    f64 sp30;
    f32 sp20;
    f32 sp18;
    f32 sp8;
    Character *temp_r3_11483;
    Character *temp_r3_11503;
    Character *temp_r3_11512;
    Character *temp_r3_11558;
    Character *temp_r4_11479;
    Character *temp_r4_11526;
    Character *temp_r4_11540;
    Character *temp_r4_11569;
    f32 temp_f1_11607;
    f32 temp_f2_11513;
    f32 temp_f2_11606;
    f32 temp_f31_11547;
    f32 var_f29_11484;
    f32 var_f30_11488;
    u8 var_r30_11579;
    void *temp_r3_11597;

    ActivateIfInactive();
    temp_r4_11479 = this->unkC;
    temp_r4_11479->unk8C0.Update(*((MKVector3 *) &temp_r4_11479->unk588));
    temp_r3_11483 = this->unkC;
    var_f29_11484 = 3000.0f;
    if (((u8) temp_r3_11483->unkB08 >> 7U) & 1) {
        var_f30_11488 = -1.0f;
    } else {
        var_f30_11488 = 1.0f;
    }
    if (M2C_FIELD(temp_r3_11483, f32 *, 0xF98) != 0.0f) {
        var_f29_11484 = 4500.0f;
    }
    if (temp_r3_11483->unk8C0.GetDist() < var_f29_11484) {
        temp_r3_11503 = this->unkC;
        M2C_FIELD(temp_r3_11503, f32 *, 0xF98) = (f32) ((gUpdateTimeDelta * (var_f29_11484 * (var_f30_11488 * M2C_FIELD(temp_r3_11503, f32 *, 0xF94)))) + M2C_FIELD(temp_r3_11503, f32 *, 0xF98));
        temp_r3_11512 = this->unkC;
        temp_f2_11513 = M2C_FIELD(temp_r3_11512, f32 *, 0xF98);
        if (temp_f2_11513 > 1.0f) {
            M2C_FIELD(temp_r3_11512, f32 *, 0xF98) = (f32) (temp_f2_11513 - 1.0f);
        } else if (temp_f2_11513 < 0.0f) {
            M2C_FIELD(temp_r3_11512, f32 *, 0xF98) = (f32) (temp_f2_11513 + 1.0f);
        }
        temp_r4_11526 = this->unkC;
        sp8 = 0.0f;
        sp60.GetMeasure(M2C_FIELD(temp_r4_11526, f32 *, 0xF98), temp_r4_11526 + 0xCC0, KDSpline_PositionMixer);
        this->unkC->unk8C0.Set(*((MKVector3 *) &sp60), 1U);
        temp_r4_11540 = this->unkC;
        temp_r4_11540->unk8C0.Update(*((MKVector3 *) &temp_r4_11540->unk588));
    }
    temp_f31_11547 = gUpdateTimeDelta;
    sp40.operator*(3000.0f);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
    temp_r3_11558 = this->unkC;
    sp50 = sp10;
    sp18 = sp40.unk8 * temp_f31_11547;
    M2C_FIELD(temp_r3_11558, f64 *, 0x598) = sp10;
    M2C_FIELD(temp_r3_11558, f64 *, 0x5A0) = (f64) sp18;
    sp58 = (f64) sp18;
    this->unk10 += gUpdateTimeDelta;
    temp_r4_11569 = this->unkC;
    if ((((u32) M2C_FIELD(M2C_FIELD(temp_r4_11569, void **, 0x630), u32 *, 0x2C) >> 1U) & 1) && (this->unk10 > 7.5f)) {
        var_r30_11579 = 0;
        if (((u8) temp_r4_11569->unk8B8 == 2) || (temp_r4_11569->unk8B0.Get() != NULL)) {
            var_r30_11579 = 1;
        }
        if (var_r30_11579 != 0) {
            sp20.GetPos();
            temp_r3_11597 = this->unkC->unk8;
            sp30 = M2C_FIELD(temp_r3_11597, f64 *, 0x30);
            sp38 = M2C_FIELD(temp_r3_11597, f64 *, 0x38);
            temp_f2_11606 = (f32) sp30 - sp20;
            temp_f1_11607 = (f32) sp38 - sp28;
            if (((temp_f2_11606 * temp_f2_11606) + (temp_f1_11607 * temp_f1_11607)) > 2.5e7f) {
                this->unk8 = 2;
            }
        }
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'Character *' to
void CynderBossGoal_Fly::Activate() {
    f64 sp128;
    f64 sp120;
    f64 sp118;
    f64 sp110;
    f64 sp108;                                      /* compiler-managed */
    f64 sp100;                                      /* compiler-managed */
    f64 spF8;                                       /* compiler-managed */
    f64 spF0;                                       /* compiler-managed */
    f64 spE8;
    f64 spE0;
    f64 spD8;
    KDUniformSpline spC0;
    f64 spB0;
    f64 spA8;
    f64 spA0;
    M2C_UNK sp90;
    f64 sp88;
    f64 sp80;
    M2C_UNK sp70;
    M2C_UNK sp60;
    f64 sp50;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp38;
    f32 sp28;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    Character *temp_r3_11644;
    Character *temp_r3_11648;
    Character *temp_r3_11891;
    Character *temp_r3_11993;
    Character *temp_r4_11661;
    Character *temp_r4_11783;
    Character *temp_r4_11961;
    Character *temp_r4_11972;
    Character *temp_r5_11923;
    Character *temp_r6_11980;
    f32 temp_f2_11927;
    f32 temp_f31_11796;
    f32 temp_f3_11791;
    f32 temp_f3_11899;
    f32 temp_f4_11784;
    f32 temp_f4_11892;
    f32 temp_f4_11930;
    f32 temp_f5_11787;
    f32 temp_f5_11895;
    f32 temp_f6_11925;
    f32 temp_f7_11932;
    f32 temp_f8_11928;
    f32 temp_f9_11926;
    f32 var_f4_11713;
    f32 var_f4_11822;
    f32 var_f6_11698;
    f32 var_f6_11807;
    f64 temp_f1_11718;
    f64 temp_f1_11724;
    f64 temp_f1_11728;
    f64 temp_f1_11827;
    f64 temp_f1_11833;
    f64 temp_f1_11837;
    s32 temp_r3_11747;
    s32 temp_r3_11856;
    s32 var_r0_11757;
    s32 var_r0_11866;

    this->unk8 = 0;
    temp_r3_11644 = this->unkC;
    temp_r3_11644->unk6B5 &= ~0x20;
    temp_r3_11648 = this->unkC;
    temp_r3_11648->unk6B5 |= 0x10;
    this->unkC->SetMovementType((CharacterMoveType) 2);
    this->unkC->unk684 = 1.570796f;
    temp_r4_11661 = this->unkC;
    M2C_FIELD(temp_r4_11661, f32 *, 0xF94) = (f32) (1.0f / M2C_FIELD(temp_r4_11661, f32 *, 0xCC8));
    sp14 = 0.0f;
    spC0.GetMeasure(0.0f, this->unkC + 0xCC0, KDSpline_PositionMixer);
    sp120 = M2C_BITWISE(f64, spC0);
    sp128 = (f64) spC0.unk8;
    sp10 = 0.0f;
    spB0.GetMeasure(0.5f, this->unkC + 0xCC0, KDSpline_PositionMixer);
    sp110 = spB0;
    sp118 = spB8;
    sp90.GetPos();
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    var_f6_11698 = 0.0f;
    sp100 = sp30;
    sp38 = (f32) sp128 - sp98;
    spA0 = sp30;
    sp108 = (f64) sp38;
    spA8 = (f64) sp38;
    unksp104 = 0.0f;
    var_f4_11713 = ((f32) sp108 * (f32) sp108) + (((f32) sp100 * (f32) sp100) + (0.0f * 0.0f));
    if (var_f4_11713 > 0.000001f) {
        if (var_f4_11713 > 0.0f) {
            temp_f1_11718 = __frsqrte(var_f4_11713);
            temp_f1_11724 = 0.5 * temp_f1_11718 * -(((f64) var_f4_11713 * (temp_f1_11718 * temp_f1_11718)) - 3.0);
            temp_f1_11728 = 0.5 * temp_f1_11724 * -(((f64) var_f4_11713 * (temp_f1_11724 * temp_f1_11724)) - 3.0);
            var_f4_11713 = (f32) ((f64) var_f4_11713 * (0.5 * temp_f1_11728 * -(((f64) var_f4_11713 * (temp_f1_11728 * temp_f1_11728)) - 3.0)));
        } else if (var_f4_11713 < M2C_BITWISE(f32, 0.0)) {
            var_f4_11713 = __float_nan;
        } else {
            spC = var_f4_11713;
            temp_r3_11747 = M2C_BITWISE(s32, spC) & 0x7F800000;
            switch (temp_r3_11747) {                /* switch 1; irregular */
            case 0x7F800000:                        /* switch 1 */
                if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                    var_r0_11757 = 1;
                } else {
                    var_r0_11757 = 2;
                }
                break;
            case 0x0:                               /* switch 1 */
                if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                    var_r0_11757 = 5;
                } else {
                    var_r0_11757 = 3;
                }
                break;
            default:                                /* switch 1 */
                var_r0_11757 = 4;
                break;
            }
            if (var_r0_11757 == 1) {
                var_f4_11713 = __float_nan;
            }
        }
        var_f6_11698 = 1.0f / var_f4_11713;
    }
    temp_r4_11783 = this->unkC;
    temp_f4_11784 = unksp104 * var_f6_11698;
    temp_f5_11787 = (f32) sp100 * var_f6_11698;
    temp_f3_11791 = (f32) sp108 * var_f6_11698;
    sp100 = temp_f5_11787;
    unksp104 = temp_f4_11784;
    temp_f31_11796 = (temp_r4_11783->unkC8 * temp_f3_11791) + ((temp_r4_11783->unkC0 * temp_f5_11787) + (temp_r4_11783->unkC4 * temp_f4_11784));
    sp108 = temp_f3_11791;
    sp70.GetPos();
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    var_f6_11807 = 0.0f;
    spF0 = sp20;
    sp28 = (f32) sp118 - sp78;
    sp80 = sp20;
    spF8 = (f64) sp28;
    sp88 = (f64) sp28;
    unkspF4 = 0.0f;
    var_f4_11822 = ((f32) spF8 * (f32) spF8) + (((f32) spF0 * (f32) spF0) + (0.0f * 0.0f));
    if (var_f4_11822 > 0.000001f) {
        if (var_f4_11822 > 0.0f) {
            temp_f1_11827 = __frsqrte(var_f4_11822);
            temp_f1_11833 = 0.5 * temp_f1_11827 * -(((f64) var_f4_11822 * (temp_f1_11827 * temp_f1_11827)) - 3.0);
            temp_f1_11837 = 0.5 * temp_f1_11833 * -(((f64) var_f4_11822 * (temp_f1_11833 * temp_f1_11833)) - 3.0);
            var_f4_11822 = (f32) ((f64) var_f4_11822 * (0.5 * temp_f1_11837 * -(((f64) var_f4_11822 * (temp_f1_11837 * temp_f1_11837)) - 3.0)));
        } else if (var_f4_11822 < M2C_BITWISE(f32, 0.0)) {
            var_f4_11822 = __float_nan;
        } else {
            sp8 = var_f4_11822;
            temp_r3_11856 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r3_11856) {                /* switch 2; irregular */
            case 0x7F800000:                        /* switch 2 */
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_11866 = 1;
                } else {
                    var_r0_11866 = 2;
                }
                break;
            case 0x0:                               /* switch 2 */
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_11866 = 5;
                } else {
                    var_r0_11866 = 3;
                }
                break;
            default:                                /* switch 2 */
                var_r0_11866 = 4;
                break;
            }
            if (var_r0_11866 == 1) {
                var_f4_11822 = __float_nan;
            }
        }
        var_f6_11807 = 1.0f / var_f4_11822;
    }
    temp_r3_11891 = this->unkC;
    temp_f4_11892 = unkspF4 * var_f6_11807;
    temp_f5_11895 = (f32) spF0 * var_f6_11807;
    temp_f3_11899 = (f32) spF8 * var_f6_11807;
    spF0 = temp_f5_11895;
    unkspF4 = temp_f4_11892;
    spF8 = temp_f3_11899;
    if (temp_f31_11796 > ((temp_r3_11891->unkC8 * temp_f3_11899) + ((temp_r3_11891->unkC0 * temp_f5_11895) + (temp_r3_11891->unkC4 * temp_f4_11892)))) {
        M2C_FIELD(temp_r3_11891, f32 *, 0xF98) = 0.0f;
        spE0 = (f64) sp100;
        spE8 = (f64) sp108;
    } else {
        M2C_FIELD(temp_r3_11891, f32 *, 0xF98) = 0.5f;
        spE0 = (f64) spF0;
        spE8 = (f64) spF8;
    }
    temp_r5_11923 = this->unkC;
    temp_f6_11925 = temp_r5_11923->unkC8;
    temp_f9_11926 = temp_r5_11923->unkD0;
    temp_f2_11927 = temp_r5_11923->unkD8;
    temp_f8_11928 = temp_r5_11923->unkC4;
    temp_f4_11930 = temp_r5_11923->unkC0;
    temp_f7_11932 = temp_r5_11923->unkD4;
    sp44 = (temp_f2_11927 * temp_f4_11930) - (temp_f9_11926 * temp_f6_11925);
    sp40 = (temp_f7_11932 * temp_f6_11925) - (temp_f2_11927 * temp_f8_11928);
    sp48 = (temp_f9_11926 * temp_f8_11928) - (temp_f7_11932 * temp_f4_11930);
    spC0.unk10 = (f64) sp40;
    spD8 = (f64) sp48;
    temp_r5_11923->unkB08 = (temp_r5_11923->unkB08 & ~0x80) | ((((u32) M2C_ERROR(/* unknown instruction: mfcr $r3 */) >> 0x1FU) << 7) & 0x80);
    temp_r4_11961 = this->unkC;
    sp18 = 0.0f;
    sp60.GetMeasure(M2C_FIELD(temp_r4_11961, f32 *, 0xF98), temp_r4_11961 + 0xCC0, KDSpline_PositionMixer);
    this->unkC->unk8C0.Set(*((MKVector3 *) &sp60), 1U);
    temp_r4_11972 = this->unkC;
    temp_r4_11972->unk8C0.Update(*((MKVector3 *) &temp_r4_11972->unk588));
    sp50.GetDir();
    temp_r6_11980 = this->unkC;
    M2C_FIELD(temp_r6_11980, f64 *, 0xE0) = sp50;
    M2C_FIELD(temp_r6_11980, f64 *, 0xE8) = sp58;
    temp_r6_11980->unk6B5 &= ~0x40;
    temp_r3_11993 = this->unkC;
    M2C_FIELD(temp_r3_11993, f64 *, 0xF0) = (f64) M2C_FIELD(&MKVector3::up, f64 *, 0);
    M2C_FIELD(temp_r3_11993, f64 *, 0xF8) = (f64) M2C_FIELD(&MKVector3::up, f64 *, 8);
    temp_r3_11993->unk6B5 &= ~0x40;
    this->unkC->EnableFlyingRotation(1U);
    this->unkC->SetAnim((AnimSequenceType) 0xA, 0xDE, 0, 0.15f, 0U, 0U);
    this->unk10 = 0.0f;
}
#endif

void CynderBossGoal_Land::Terminate() {
    this->unkC->SetInvulnerableToMeleeAttacks(0U, 1U);
    this->unkC->SetInvulnerableToBreathAttacks(0U, 1U);
    this->unk8 = 1;
}

#if 0 // DRAFT: undefined identifier 'arg_sp30'
u8 CynderBossGoal_Land::Update() {
    Enemy *temp_r3_12062;
    Enemy *temp_r3_12101;
    f32 temp_f3_12064;
    f32 temp_f6_12069;
    f32 temp_f7_12075;
    ActivateIfInactive();
    arg_sp30.SetIdentity();
    this->unkC->GetDesiredHeadingMatrix((Matrix *) &arg_sp30);
    temp_r3_12062 = this->unkC;
    temp_f3_12064 = temp_r3_12062->unk84;
    temp_f6_12069 = temp_r3_12062->unk80;
    temp_f7_12075 = temp_r3_12062->unk88;
    arg_sp10 = (temp_f7_12075 * arg_sp50) + ((temp_f6_12069 * arg_sp30) + (temp_f3_12064 * arg_sp40));
    arg_sp14 = (temp_f7_12075 * arg_sp54) + ((temp_f6_12069 * arg_sp34) + (temp_f3_12064 * arg_sp44));
    arg_sp18 = (temp_f7_12075 * arg_sp58) + ((temp_f6_12069 * arg_sp38) + (temp_f3_12064 * arg_sp48));
    M2C_FIELD(temp_r3_12062, f64 *, 0x598) = (f64) arg_sp10;
    M2C_FIELD(temp_r3_12062, f64 *, 0x5A0) = (f64) arg_sp18;
    arg_sp20 = (f64) arg_sp10;
    arg_sp28 = (f64) arg_sp18;
    if (this->unkC->HasAnimFinished() != 0) {
        this->unk8 = 2;
        temp_r3_12101 = this->unkC;
        temp_r3_12101->unk6B5 |= 0x20;
        this->unkC->SetMovementType((CharacterMoveType) 0);
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: expression syntax error
void CynderBossGoal_Land::Activate() {
    f64 sp8;
    Enemy *temp_r3_12128;
    Enemy *temp_r3_12132;
    Enemy *temp_r3_12138;
    Enemy *temp_r4_12156;
    Enemy *temp_r4_12167;
    Enemy *temp_r6_12178;
    u8 var_r30_12139;

    this->unk8 = 0;
    temp_r3_12128 = this->unkC;
    temp_r3_12128->unk6B5 &= ~0x20;
    temp_r3_12132 = this->unkC;
    temp_r3_12132->unk6B5 &= ~0x10;
    this->unkC->SetMovementType((CharacterMoveType) 1);
    temp_r3_12138 = this->unkC;
    var_r30_12139 = 0;
    if (((u8) M2C_FIELD(temp_r3_12138, u8 *, 0x8B8) == 2) || (temp_r3_12138->unk870.unk30.Get() != NULL)) {
        var_r30_12139 = 1;
    }
    if (var_r30_12139 != 0) {
        sp8.GetDir();
        temp_r4_12156 = this->unkC;
        M2C_FIELD(temp_r4_12156, f64 *, 0xE0) = sp8;
        M2C_FIELD(temp_r4_12156, f64 *, 0xE8) = sp10;
        temp_r4_12156->unk6B5 |= 0x40;
    } else {
        temp_r4_12167 = this->unkC;
        M2C_FIELD(temp_r4_12167, f64 *, 0xE0) = (f64) M2C_FIELD(temp_r4_12167, f64 *, 0xC0);
        M2C_FIELD(temp_r4_12167, f64 *, 0xE8) = (f64) M2C_FIELD(temp_r4_12167, f64 *, 0xC8);
        temp_r4_12167->unk6B5 |= 0x40;
    }
    temp_r6_12178 = this->unkC;
    M2C_FIELD(temp_r6_12178, f64 *, 0xF0) = (f64) M2C_FIELD(&MKVector3::up, f64 *, 0);
    M2C_FIELD(temp_r6_12178, f64 *, 0xF8) = (f64) M2C_FIELD(&MKVector3::up, f64 *, 8);
    temp_r6_12178->unk6B5 |= 0x40;
    this->unkC->unk684 = 0.392699f;
    this->unkC->EnableFlyingRotation(0U);
    this->unkC->SetAnim((AnimSequenceType) 0xA, 0xDD, 0, 0.15f, 0U, 0U);
    this->unkC->UpdateAnimation();
    M2C_FIELD(this->unkC, s32 *, 0xCFC) = 0;
}
#endif

u8 CynderBossGoal_TakeOff::Update() {
    Enemy *temp_r3_12232;
    Enemy *temp_r3_12238;

    ActivateIfInactive();
    if (((MKAnimScript *) (M2C_FIELD(this->unkC, MKAnimScript **, 0x630)))->CheckEvent(5) != 0) {
        this->unkC->SetIdleMovementSpeed(1U);
        temp_r3_12232 = this->unkC;
        temp_r3_12232->unk6B5 |= 0x10;
    }
    temp_r3_12238 = this->unkC;
    M2C_FIELD(temp_r3_12238, f64 *, 0x598) = (f64) M2C_FIELD(temp_r3_12238, f64 *, 0x90);
    M2C_FIELD(temp_r3_12238, f64 *, 0x5A0) = (f64) M2C_FIELD(temp_r3_12238, f64 *, 0x98);
    if (this->unkC->HasAnimFinished() != 0) {
        this->unk8 = 2;
    }
    return this->unk8;
}

void CynderBossGoal_TakeOff::Activate() {
    Enemy *temp_r3_12269;
    Enemy *temp_r3_12295;
    Enemy *temp_r4_12278;
    Enemy *temp_r4_12287;

    this->unk8 = 0;
    temp_r3_12269 = this->unkC;
    temp_r3_12269->unk6B5 &= ~0x20;
    this->unkC->StopMovement(1U);
    this->unkC->SetMovementType((CharacterMoveType) 1);
    temp_r4_12278 = this->unkC;
    M2C_FIELD(temp_r4_12278, f64 *, 0xE0) = (f64) M2C_FIELD(temp_r4_12278, f64 *, 0xC0);
    M2C_FIELD(temp_r4_12278, f64 *, 0xE8) = (f64) M2C_FIELD(temp_r4_12278, f64 *, 0xC8);
    temp_r4_12278->unk6B5 |= 0x40;
    temp_r4_12287 = this->unkC;
    M2C_FIELD(temp_r4_12287, f64 *, 0xF0) = (f64) M2C_FIELD(temp_r4_12287, f64 *, 0xD0);
    M2C_FIELD(temp_r4_12287, f64 *, 0xF8) = (f64) M2C_FIELD(temp_r4_12287, f64 *, 0xD8);
    temp_r4_12287->unk6B5 |= 0x40;
    temp_r3_12295 = this->unkC;
    if ((u8) M2C_FIELD(temp_r3_12295, u8 *, 0xF19) == 0) {
        temp_r3_12295->SetInvulnerableToMeleeAttacks(1U, 1U);
        this->unkC->SetInvulnerableToBreathAttacks(1U, 1U);
    }
    this->unkC->SetAnim((AnimSequenceType) 0xA, 0xDC, 0, 0.15f, 0U, 0U);
    M2C_FIELD(this->unkC, s32 *, 0xCFC) = 0;
}

#if 0 // DRAFT: illegal implicit conversion from 'void' to
u8 CynderBossGoal_AttackFlight::Update() {
    ActivateIfInactive();
    this->unk8 = UpdateSubgoals();
    return this->unk8;
}
#endif

#if 0 // DRAFT: undefined identifier 'AddSubgoal__22CompositeGoal'
void CynderBossGoal_AttackFlight::Activate() {
    s32 temp_r3_12377;

    this->unk8 = 0;
    if (!(((u8) this->unkC->unk6B5 >> 4U) & 1)) {
        AddSubgoal__22CompositeGoal<6Cynder>FP13Goal<6Cynder>((CompositeGoal<Cynder> *) this, (Goal<Cynder> *) this->unk20);
    }
    AddSubgoal__22CompositeGoal<6Cynder>FP13Goal<6Cynder>((CompositeGoal<Cynder> *) this, (Goal<Cynder> *) this->unk24);
    AddSubgoal__22CompositeGoal<6Cynder>FP13Goal<6Cynder>((CompositeGoal<Cynder> *) this, (Goal<Cynder> *) this->unk28);
    AddSubgoal__22CompositeGoal<6Cynder>FP13Goal<6Cynder>((CompositeGoal<Cynder> *) this, (Goal<Cynder> *) this->unk2C);
    AddSubgoal__22CompositeGoal<6Cynder>FP13Goal<6Cynder>((CompositeGoal<Cynder> *) this, (Goal<Cynder> *) this->unk30);
    temp_r3_12377 = MKRand_Int(&gViewSeed, 0, 0xA);
    if (temp_r3_12377 < 3) {
        if (temp_r3_12377 < 0) {
            goto block_6;
        }
        AddSubgoal__22CompositeGoal<6Cynder>FP13Goal<6Cynder>((CompositeGoal<Cynder> *) this, (Goal<Cynder> *) this->unk34);
    } else {
block_6:
        AddSubgoal__22CompositeGoal<6Cynder>FP13Goal<6Cynder>((CompositeGoal<Cynder> *) this, (Goal<Cynder> *) this->unk38);
    }
    this->unkC->unkCDC = 0.0f;
}
#endif

void CynderBossGoal_AttackFlight::Deinit() {
    Goal<Cynder> *temp_r3_12411;
    Goal<Cynder> *temp_r3_12416;
    Goal<Cynder> *temp_r3_12421;
    Goal<Cynder> *temp_r3_12426;
    Goal<Cynder> *temp_r3_12431;
    Goal<Cynder> *temp_r3_12436;
    Goal<Cynder> *temp_r3_12441;
    MKHeap *temp_r3_12470;
    void **temp_r3_12446;
    void *temp_r31_12467;

    temp_r3_12411 = this->unk20;
    temp_r3_12411->Deinit();
    temp_r3_12416 = this->unk24;
    temp_r3_12416->Deinit();
    temp_r3_12421 = this->unk28;
    temp_r3_12421->Deinit();
    temp_r3_12426 = this->unk2C;
    temp_r3_12426->Deinit();
    temp_r3_12431 = this->unk30;
    temp_r3_12431->Deinit();
    temp_r3_12436 = this->unk34;
    temp_r3_12436->Deinit();
    temp_r3_12441 = this->unk38;
    temp_r3_12441->Deinit();
    temp_r3_12446 = this->unk3C;
    M2C_FIELD(*temp_r3_12446, M2C_UNK (**)(void **), 0xC)(temp_r3_12446);
    operator delete(this->unk20);
    operator delete(this->unk24);
    operator delete(this->unk28);
    operator delete(this->unk2C);
    operator delete(this->unk30);
    operator delete(this->unk34);
    operator delete(this->unk38);
    operator delete(this->unk3C);
    temp_r31_12467 = this->unk1C;
    if (temp_r31_12467 != NULL) {
        temp_r3_12470 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_12470 != NULL) {
            ((MKHeap *) (temp_r3_12470->Current()))->Free(temp_r31_12467, NULL, 0);
        } else {
            free(temp_r31_12467);
        }
        this->unk1C = NULL;
    }
    this->unk10 = 0;
    this->unk18 = 0;
    this->unk14 = 0;
    this->unk8 = 1;
    this->unkC = NULL;
    this->unk9 = 0;
}

#if 0 // DRAFT: pointer/array required
void CynderBossGoal_AttackFlight::Init(Cynder *arg0) {
    Goal<Cynder> *temp_r4_12704;
    Goal<Cynder> *temp_r4_12715;
    Goal<Cynder> *temp_r4_12726;
    Goal<Cynder> *temp_r4_12737;
    Goal<Cynder> *temp_r4_12748;
    Goal<Cynder> *temp_r4_12759;
    Goal<Cynder> *temp_r4_12770;
    MKHeap *temp_r3_12677;
    void **temp_r4_12781;
    void *var_r3_12684;

    if ((u8) this->unk9 == 0) {
        operator new(0x10U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__13Goal<6Cynder>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk20 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x14U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__13Goal<6Cynder>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk24 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x14U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__13Goal<6Cynder>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk28 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x10U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__13Goal<6Cynder>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk2C = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x10U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__13Goal<6Cynder>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk30 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x10U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__13Goal<6Cynder>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk34 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x10U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__13Goal<6Cynder>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk38 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x10U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__13Goal<6Cynder>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk3C = M2C_ERROR(/* Read from unset register $r3 */);
    }
    if ((u8) this->unk9 == 0) {
        temp_r3_12677 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_12677 != NULL) {
            var_r3_12684 = ((MKHeap *) (temp_r3_12677->Current()))->Alloc(0x28, NULL, 0);
        } else {
            var_r3_12684 = malloc(0x28);
        }
        this->unk1C = var_r3_12684;
        this->unk10 = 0xA;
    }
    this->unk8 = 1;
    this->unkC = arg0;
    this->unk4 = 0x9A;
    if ((Cynder *) this->unkC != NULL) {
        this->unk9 = 1;
    }
    temp_r4_12704 = this->unk20;
    M2C_FIELD(temp_r4_12704, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_12704, Cynder **, 0xC) = arg0;
    M2C_FIELD(temp_r4_12704, s32 *, 4) = 0x9C;
    if ((Cynder *) M2C_FIELD(temp_r4_12704, Cynder **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_12704, s8 *, 9) = 1;
    }
    temp_r4_12715 = this->unk24;
    M2C_FIELD(temp_r4_12715, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_12715, Cynder **, 0xC) = arg0;
    M2C_FIELD(temp_r4_12715, s32 *, 4) = 0x9E;
    if ((Cynder *) M2C_FIELD(temp_r4_12715, Cynder **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_12715, s8 *, 9) = 1;
    }
    temp_r4_12726 = this->unk28;
    M2C_FIELD(temp_r4_12726, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_12726, Cynder **, 0xC) = arg0;
    M2C_FIELD(temp_r4_12726, s32 *, 4) = 0x9F;
    if ((Cynder *) M2C_FIELD(temp_r4_12726, Cynder **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_12726, s8 *, 9) = 1;
    }
    temp_r4_12737 = this->unk2C;
    M2C_FIELD(temp_r4_12737, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_12737, Cynder **, 0xC) = arg0;
    M2C_FIELD(temp_r4_12737, s32 *, 4) = 0xA0;
    if ((Cynder *) M2C_FIELD(temp_r4_12737, Cynder **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_12737, s8 *, 9) = 1;
    }
    temp_r4_12748 = this->unk30;
    M2C_FIELD(temp_r4_12748, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_12748, Cynder **, 0xC) = arg0;
    M2C_FIELD(temp_r4_12748, s32 *, 4) = 0xA2;
    if ((Cynder *) M2C_FIELD(temp_r4_12748, Cynder **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_12748, s8 *, 9) = 1;
    }
    temp_r4_12759 = this->unk34;
    M2C_FIELD(temp_r4_12759, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_12759, Cynder **, 0xC) = arg0;
    M2C_FIELD(temp_r4_12759, s32 *, 4) = 0xA3;
    if ((Cynder *) M2C_FIELD(temp_r4_12759, Cynder **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_12759, s8 *, 9) = 1;
    }
    temp_r4_12770 = this->unk38;
    M2C_FIELD(temp_r4_12770, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_12770, Cynder **, 0xC) = arg0;
    M2C_FIELD(temp_r4_12770, s32 *, 4) = 0xA4;
    if ((Cynder *) M2C_FIELD(temp_r4_12770, Cynder **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_12770, s8 *, 9) = 1;
    }
    temp_r4_12781 = this->unk3C;
    M2C_FIELD(temp_r4_12781, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_12781, Cynder **, 0xC) = arg0;
    M2C_FIELD(temp_r4_12781, s32 *, 4) = 0xA5;
    if ((Cynder *) M2C_FIELD(temp_r4_12781, Cynder **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_12781, s8 *, 9) = 1;
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void' to
u8 CynderBossGoal_LandingFlight::Update() {
    ActivateIfInactive();
    this->unk8 = UpdateSubgoals();
    return this->unk8;
}
#endif

#if 0 // DRAFT: undefined identifier 'AddSubgoal__22CompositeGoal'
void CynderBossGoal_LandingFlight::Activate() {
    Goal<Cynder> *temp_r6_12835;

    this->unk8 = 0;
    if (!(((u8) this->unkC->unk6B5 >> 4U) & 1)) {
        AddSubgoal__22CompositeGoal<6Cynder>FP13Goal<6Cynder>((CompositeGoal<Cynder> *) this, (Goal<Cynder> *) this->unk20);
        temp_r6_12835 = this->unk20;
        M2C_FIELD(temp_r6_12835, s32 *, 0x10) = 0;
        M2C_FIELD(temp_r6_12835, s32 *, 0x14) = 1;
        M2C_FIELD(temp_r6_12835, s32 *, 0x18) = 0xA;
        M2C_FIELD(temp_r6_12835, s32 *, 0x1C) = 0;
        M2C_FIELD(temp_r6_12835, u8 *, 0x20) = (u8) (M2C_FIELD(temp_r6_12835, u8 *, 0x20) & ~0x40);
        AddSubgoal__22CompositeGoal<6Cynder>FP13Goal<6Cynder>((CompositeGoal<Cynder> *) this, (Goal<Cynder> *) this->unk24);
    }
    AddSubgoal__22CompositeGoal<6Cynder>FP13Goal<6Cynder>((CompositeGoal<Cynder> *) this, (Goal<Cynder> *) this->unk2C);
    AddSubgoal__22CompositeGoal<6Cynder>FP13Goal<6Cynder>((CompositeGoal<Cynder> *) this, (Goal<Cynder> *) this->unk30);
    AddSubgoal__22CompositeGoal<6Cynder>FP13Goal<6Cynder>((CompositeGoal<Cynder> *) this, (Goal<Cynder> *) this->unk34);
    AddSubgoal__22CompositeGoal<6Cynder>FP13Goal<6Cynder>((CompositeGoal<Cynder> *) this, (Goal<Cynder> *) this->unk38);
    AddSubgoal__22CompositeGoal<6Cynder>FP13Goal<6Cynder>((CompositeGoal<Cynder> *) this, (Goal<Cynder> *) this->unk28);
    this->unkC->unkCDC = 1e-45f;
}
#endif

void CynderBossGoal_LandingFlight::Deinit() {
    Goal<Cynder> *temp_r3_12883;
    Goal<Cynder> *temp_r3_12888;
    Goal<Cynder> *temp_r3_12893;
    Goal<Cynder> *temp_r3_12898;
    Goal<Cynder> *temp_r3_12903;
    Goal<Cynder> *temp_r3_12908;
    Goal<Cynder> *temp_r3_12913;
    MKHeap *temp_r3_12935;
    void *temp_r31_12932;

    temp_r3_12883 = this->unk20;
    temp_r3_12883->Deinit();
    temp_r3_12888 = this->unk24;
    temp_r3_12888->Deinit();
    temp_r3_12893 = this->unk28;
    temp_r3_12893->Deinit();
    temp_r3_12898 = this->unk2C;
    temp_r3_12898->Deinit();
    temp_r3_12903 = this->unk30;
    temp_r3_12903->Deinit();
    temp_r3_12908 = this->unk34;
    temp_r3_12908->Deinit();
    temp_r3_12913 = this->unk38;
    temp_r3_12913->Deinit();
    operator delete(this->unk20);
    operator delete(this->unk24);
    operator delete(this->unk28);
    operator delete(this->unk2C);
    operator delete(this->unk30);
    operator delete(this->unk34);
    operator delete(this->unk38);
    temp_r31_12932 = this->unk1C;
    if (temp_r31_12932 != NULL) {
        temp_r3_12935 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_12935 != NULL) {
            ((MKHeap *) (temp_r3_12935->Current()))->Free(temp_r31_12932, NULL, 0);
        } else {
            free(temp_r31_12932);
        }
        this->unk1C = NULL;
    }
    this->unk10 = 0;
    this->unk18 = 0;
    this->unk14 = 0;
    this->unk8 = 1;
    this->unkC = NULL;
    this->unk9 = 0;
}

#if 0 // DRAFT: pointer/array required
void CynderBossGoal_LandingFlight::Init(Cynder *arg0) {
    Goal<Cynder> *temp_r4_13149;
    Goal<Cynder> *temp_r4_13160;
    Goal<Cynder> *temp_r4_13171;
    Goal<Cynder> *temp_r4_13182;
    Goal<Cynder> *temp_r4_13193;
    Goal<Cynder> *temp_r4_13204;
    Goal<Cynder> *temp_r4_13215;
    MKHeap *temp_r3_13122;
    void *var_r3_13129;

    if ((u8) this->unk9 == 0) {
        operator new(0x24U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk20 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x10U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__13Goal<6Cynder>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk24 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x10U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__13Goal<6Cynder>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk28 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x14U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__13Goal<6Cynder>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk2C = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x14U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__13Goal<6Cynder>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk30 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x10U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__13Goal<6Cynder>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk34 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x10U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__13Goal<6Cynder>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk38 = M2C_ERROR(/* Read from unset register $r3 */);
    }
    if ((u8) this->unk9 == 0) {
        temp_r3_13122 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_13122 != NULL) {
            var_r3_13129 = ((MKHeap *) (temp_r3_13122->Current()))->Alloc(0x28, NULL, 0);
        } else {
            var_r3_13129 = malloc(0x28);
        }
        this->unk1C = var_r3_13129;
        this->unk10 = 0xA;
    }
    this->unk8 = 1;
    this->unkC = arg0;
    this->unk4 = 0x9B;
    if ((Cynder *) this->unkC != NULL) {
        this->unk9 = 1;
    }
    temp_r4_13149 = this->unk20;
    M2C_FIELD(temp_r4_13149, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_13149, Cynder **, 0xC) = arg0;
    M2C_FIELD(temp_r4_13149, s32 *, 4) = 0;
    if ((Cynder *) M2C_FIELD(temp_r4_13149, Cynder **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_13149, s8 *, 9) = 1;
    }
    temp_r4_13160 = this->unk24;
    M2C_FIELD(temp_r4_13160, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_13160, Cynder **, 0xC) = arg0;
    M2C_FIELD(temp_r4_13160, s32 *, 4) = 0x9C;
    if ((Cynder *) M2C_FIELD(temp_r4_13160, Cynder **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_13160, s8 *, 9) = 1;
    }
    temp_r4_13171 = this->unk28;
    M2C_FIELD(temp_r4_13171, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_13171, Cynder **, 0xC) = arg0;
    M2C_FIELD(temp_r4_13171, s32 *, 4) = 0x9D;
    if ((Cynder *) M2C_FIELD(temp_r4_13171, Cynder **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_13171, s8 *, 9) = 1;
    }
    temp_r4_13182 = this->unk2C;
    M2C_FIELD(temp_r4_13182, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_13182, Cynder **, 0xC) = arg0;
    M2C_FIELD(temp_r4_13182, s32 *, 4) = 0x9E;
    if ((Cynder *) M2C_FIELD(temp_r4_13182, Cynder **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_13182, s8 *, 9) = 1;
    }
    temp_r4_13193 = this->unk30;
    M2C_FIELD(temp_r4_13193, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_13193, Cynder **, 0xC) = arg0;
    M2C_FIELD(temp_r4_13193, s32 *, 4) = 0x9F;
    if ((Cynder *) M2C_FIELD(temp_r4_13193, Cynder **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_13193, s8 *, 9) = 1;
    }
    temp_r4_13204 = this->unk34;
    M2C_FIELD(temp_r4_13204, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_13204, Cynder **, 0xC) = arg0;
    M2C_FIELD(temp_r4_13204, s32 *, 4) = 0xA0;
    if ((Cynder *) M2C_FIELD(temp_r4_13204, Cynder **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_13204, s8 *, 9) = 1;
    }
    temp_r4_13215 = this->unk38;
    M2C_FIELD(temp_r4_13215, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_13215, Cynder **, 0xC) = arg0;
    M2C_FIELD(temp_r4_13215, s32 *, 4) = 0xA1;
    if ((Cynder *) M2C_FIELD(temp_r4_13215, Cynder **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_13215, s8 *, 9) = 1;
    }
}
#endif

#if 0 // DRAFT: illegal operands 'void' == 'int'
void CynderBossGoal_Think::AddGoal_AttackPhase3() {
    if (IsPresent(0xA8) == 0) {
        RemoveAllSubgoals();
        AddSubgoal__22CompositeGoal<6Cynder>FP13Goal<6Cynder>((CompositeGoal<Cynder> *) this, (Goal<Cynder> *) this->unk44);
    }
}
#endif

#if 0 // DRAFT: illegal operands 'void' == 'int'
void CynderBossGoal_Think::AddGoal_AttackPhase2(EAPItem *arg0) {
    if (IsPresent(0xA7) == 0) {
        RemoveAllSubgoals();
        AddSubgoal__22CompositeGoal<6Cynder>FP13Goal<6Cynder>((CompositeGoal<Cynder> *) this, (Goal<Cynder> *) this->unk40);
        M2C_FIELD(this->unk40, EAPItem **, 0x20) = arg0;
    }
}
#endif

#if 0 // DRAFT: illegal operands 'void' == 'int'
void CynderBossGoal_Think::AddGoal_AttackPhase1(EAPItem *arg0) {
    if (IsPresent(0xA6) == 0) {
        RemoveAllSubgoals();
        AddSubgoal__22CompositeGoal<6Cynder>FP13Goal<6Cynder>((CompositeGoal<Cynder> *) this, (Goal<Cynder> *) this->unk3C);
        M2C_FIELD(this->unk3C, EAPItem **, 0x20) = arg0;
    }
}
#endif

#if 0 // DRAFT: illegal operands 'void' == 'int'
void CynderBossGoal_Think::AddGoal_Idle() {
    Goal<Cynder> *temp_r6_13345;

    if (IsActive(0) == 0) {
        RemoveAllSubgoals();
        AddSubgoal__22CompositeGoal<6Cynder>FP13Goal<6Cynder>((CompositeGoal<Cynder> *) this, (Goal<Cynder> *) this->unk28);
        temp_r6_13345 = this->unk28;
        M2C_FIELD(temp_r6_13345, f32 **, 0x10) = &this->unkC->unk838.unk28;
        M2C_FIELD(temp_r6_13345, s32 *, 0x14) = 1;
        M2C_FIELD(temp_r6_13345, s32 *, 0x18) = 0xA;
        M2C_FIELD(temp_r6_13345, s32 *, 0x1C) = 0;
        M2C_FIELD(temp_r6_13345, u8 *, 0x20) = (u8) (M2C_FIELD(temp_r6_13345, u8 *, 0x20) & ~0x40);
    }
}
#endif

#if 0 // DRAFT: illegal operands 'void' != 'int'
void CynderBossGoal_Think::AddGoal_Hit(EnemyDamageFeedback *arg0) {
    Enemy *temp_r4_13428;
    s32 temp_r0_13373;
    s32 temp_r0_13404;

    temp_r0_13373 = arg0->unk28;
    if (temp_r0_13373 < 8) {
        if (temp_r0_13373 != 3) {
            if (temp_r0_13373 < 3) {
                if (temp_r0_13373 < 1) {

                } else {
                    goto block_8;
                }
            }
        } else {
            goto block_9;
        }
    } else if (temp_r0_13373 < 0xD) {
        if (temp_r0_13373 < 0xB) {
block_9:
            arg0->unk28 = 0;
        } else {
block_8:
            arg0->unk28 = 0;
        }
    }
    if (IsActive(0x59) != 0) {
        temp_r0_13404 = arg0->unk28;
        if ((temp_r0_13404 != 0) && ((temp_r0_13404 != 1) || (IsActive(0xA) == 0))) {
            if (IsActive(0x12) != 0) {
                return;
            }
            goto block_16;
        }
    } else {
block_16:
        temp_r4_13428 = this->unkC;
        M2C_FIELD(temp_r4_13428, f64 *, 0x910) = (f64) arg0->unk0;
        M2C_FIELD(temp_r4_13428, f64 *, 0x918) = (f64) arg0->unk8;
        M2C_FIELD(temp_r4_13428, s32 *, 0x920) = (s32) arg0->unk10;
        M2C_FIELD(temp_r4_13428, s32 *, 0x924) = (s32) arg0->unk14;
        temp_r4_13428->unk918 = arg0->unk18;
        temp_r4_13428->unk92C = arg0->unk1C;
        temp_r4_13428->unk920 = arg0->unk20;
        temp_r4_13428->unk924 = arg0->unk24;
        temp_r4_13428->unk928 = M2C_BITWISE(f32, arg0->unk28);
        temp_r4_13428->unk92C = M2C_BITWISE(f32, arg0->unk2C);
        temp_r4_13428->unk930 = arg0->unk30;
        M2C_FIELD(temp_r4_13428, u8 *, 0x944) = (u8) arg0->unk34;
        this->unkC->unk918 = 0.0f;
        RemoveAllSubgoals();
        AddSubgoal__22CompositeGoal<6Cynder>FP13Goal<6Cynder>((CompositeGoal<Cynder> *) this, (Goal<Cynder> *) this->unk2C);
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void' to
u8 CynderBossGoal_Think::Update() {
    s32 sp8;
    Enemy *temp_r3_13546;
    Enemy *temp_r3_13566;
    Enemy *temp_r3_13573;
    Enemy *temp_r3_13613;
    Enemy *temp_r4_13532;
    Enemy *temp_r4_13539;
    Enemy *temp_r4_13589;
    s32 temp_r0_13485;
    s32 temp_r3_13592;
    u32 temp_r31_13488;
    u8 temp_r4_13610;
    void *temp_r4_13580;

    if (this->unkC->WasHit() != 0) {
        this->unk8 = 1;
    }
    temp_r0_13485 = this->unk24;
    temp_r31_13488 = ((u8) M2C_FIELD(this->unkC, u8 *, 0xB09) >> 7U) & 1;
    switch (temp_r0_13485) {                        /* irregular */
    case 1:
        Music_Pause(1U);
        KDSound_SoundDucking_Init(0.2f, 1.0f, 1.2f, 1U);
        KDSound_SoundDucking_Duck();
        this->unk24 = 2;
        break;
    case 2:
        if ((KDSound_SoundDucking_GetState() == 2) && (PhrasePlayer_IsAnyEventPlaying() == 0)) {
            PhrasePlayer_PlayEvent("ConvexFuryPhrase");
            this->unk24 = 3;
        }
        break;
    case 3:
        if (PhrasePlayer_IsAnyEventPlaying() == 0) {
            KDSound_SoundDucking_UnDuck();
            Music_Resume();
            this->unk24 = 0;
        }
        break;
    }
    temp_r4_13532 = this->unkC;
    if ((u8) M2C_FIELD(temp_r4_13532, u8 *, 0xF18) != 0) {
        M2C_FIELD(temp_r4_13532, u8 *, 0xF18) = 0U;
        temp_r4_13539 = this->unkC;
        temp_r4_13539->unk9D8 = 0;
        temp_r4_13539->unk9D4 = 0;
        RemoveAllSubgoals();
        this->unk8 = 1;
    }
    temp_r3_13546 = this->unkC;
    if (temp_r3_13546->IsDead() == 0) {
        this->unkC->SelectTarget();
    }
    ActivateIfInactive();
    if (temp_r31_13488 == (u32) (((u8) M2C_FIELD(this->unkC, u8 *, 0xB09) >> 7U) & 1)) {
        this->unk8 = UpdateSubgoals();
        temp_r3_13566 = this->unkC;
        if ((void *) temp_r3_13566->unkA44 != NULL) {
            temp_r3_13566->IsFlinching();
            if ((u8) M2C_ERROR(/* Read from unset register $r3 */) != 0) {
                temp_r3_13573 = this->unkC;
                if (!(((u8) temp_r3_13573->unk6B5 >> 4U) & 1) && (M2C_BITWISE(s32, temp_r3_13573->unkAD0) <= 2)) {
                    temp_r4_13580 = temp_r3_13573->unkA44;
                    M2C_FIELD(temp_r4_13580, u8 *, 0x10) = (u8) (M2C_FIELD(temp_r4_13580, u8 *, 0x10) | 0x40);
                    sp8 = 7;
                    temp_r4_13589 = this->unkC;
                    temp_r3_13592 = temp_r4_13589->unkA44->Evaluate(temp_r4_13589, (AITargetData *) &temp_r4_13589->unk838.unk28, &sp8, 1);
                    if (temp_r3_13592 != 0) {
                        RemoveAllSubgoals();
                        if (M2C_BITWISE(s32, this->unkC->unkAD0) == 1) {
                            AddGoal_AttackPhase1((EAPItem *) temp_r3_13592);
                        } else {
                            AddGoal_AttackPhase2((EAPItem *) temp_r3_13592);
                        }
                    }
                }
            }
        }
        temp_r4_13610 = this->unk8;
        if (temp_r4_13610 == 2) {
            temp_r3_13613 = this->unkC;
            if (!(((u8) M2C_FIELD(temp_r3_13613, u8 *, 0xB09) >> 7U) & 1)) {
                M2C_FIELD(temp_r3_13613->__vptr, M2C_UNK (**)(), 0x34)();
                return this->unk8;
            }
        }
        if (temp_r4_13610 != 0) {
            Activate();
        }
        goto block_32;
    }
block_32:
    return this->unk8;
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_sp6C'
void CynderBossGoal_Think::Arbitrate() {
    Enemy *temp_r3_13674;
    Enemy *temp_r3_13743;
    Enemy *temp_r4_13770;
    f32 temp_f1_13685;
    f32 temp_f1_13715;
    f32 temp_f29_13757;
    f32 temp_f30_13751;
    f32 temp_f31_13749;
    f32 temp_f5_13691;
    f32 temp_f6_13678;
    f32 temp_r0_13853;
    if ((((u8) M2C_FIELD(this->unkC, u8 *, 0xB09) >> 7U) & 1) || (M2C_STRUCT_COPY((s32) &arg_sp6C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40), temp_r3_13674 = this->unkC, temp_f6_13678 = temp_r3_13674->unk5C8, arg_sp90 = temp_f6_13678, temp_f1_13685 = temp_r3_13674->unk5C8, arg_sp94 = temp_f1_13685, temp_f5_13691 = temp_r3_13674->unk5CC, arg_sp18 = (MKVector3::up.unk0 * temp_f1_13685) - (MKVector3::up.unk4 * temp_f6_13678), arg_sp98 = temp_f5_13691, arg_sp28 = (f64) arg_sp18, arg_sp10 = (MKVector3::up.unk4 * temp_f5_13691) - (MKVector3::up.unk8 * temp_f1_13685), arg_sp14 = (MKVector3::up.unk8 * temp_f6_13678) - (MKVector3::up.unk0 * temp_f5_13691), arg_sp9C = 0.0f, arg_sp20 = (f64) arg_sp10, arg_sp70 = (f32) arg_sp20, arg_sp74 = arg_sp24, arg_sp78 = (f32) arg_sp28, arg_sp7C = 0.0f, arg_spA0 = temp_r3_13674->unk5B8, arg_spA4 = temp_r3_13674->unk5B8, temp_f1_13715 = temp_r3_13674->unk5BC, arg_spA8 = temp_f1_13715, arg_spAC = 1.0f, ((temp_r3_13674->Spawn(&arg_sp70, 0, &MKVector3::up, temp_f1_13715, arg_sp24, (f32) arg_sp20, 0.0f, temp_f5_13691, temp_f6_13678, MKVector3::up.unk8, MKVector3::up.unk4) == 0) == 0))) {
        if (this->unkC->WasHit() != 0) {
            arg_sp30.Init();
            this->unkC->TakeDamage((EnemyDamageFeedback *) &arg_sp30, 0U);
            this->unkC->UpdateEnemyHud();
            if ((arg_sp58 == 0xD) && !((arg_sp64 >> 6U) & 1)) {
                temp_r3_13743 = this->unkC;
                if ((u8) M2C_FIELD(temp_r3_13743, u8 *, 0xF1E) == 0) {
                    temp_f31_13749 = M2C_FIELD(GameData::gameData, f32 *, 0xBC);
                    temp_f30_13751 = M2C_FIELD(GameData::gameData, f32 *, 0xB8);
                    temp_f29_13757 = temp_f31_13749 * (1.0f - temp_r3_13743->GetHealthPercentage());
                    ((Stat *) ((Stat *) &GameData::gameData[0xB8]))->SetValue(temp_f29_13757, 0U);
                    arg_sp58 = 0xE;
                    if (temp_f30_13751 < temp_f31_13749) {
                        M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
                        if (temp_f29_13757 == temp_f31_13749) {
                            this->unk24 = 1;
                        }
                    }
                }
            }
            temp_r4_13770 = this->unkC;
            M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
            if ((temp_r4_13770->unkAB0 == 0.0f) && (arg_sp58 == 0xD) && ((arg_sp64 >> 6U) & 1)) {
                M2C_FIELD(temp_r4_13770, s8 *, 0xF1D) = 1;
                arg_sp58 = 0xE;
            }
            if ((arg_sp58 == 4) || (arg_sp58 == 5) || (((u8) this->unkC->unk6B5 >> 4U) & 1)) {
                arg_sp58 = 0xE;
            }
            if (arg_sp58 != 0xE) {
                AddGoal_Hit((EnemyDamageFeedback *) &arg_sp30);
                return;
            }
            goto block_19;
        }
block_19:
        this->unkC->IsFlinching();
        if (((u8) M2C_ERROR(/* Read from unset register $r3 */) == 0) && (IsActive(0xA6) == 0) && (IsActive(0xA7) == 0) && (IsActive(0xA8) == 0) && (IsActive(0x9B) == 0) && (IsActive(0x9A) == 0)) {
            temp_r0_13853 = this->unkC->unkAD0;
            switch (M2C_BITWISE(s32, temp_r0_13853)) { /* irregular */
            case 1:
                AddGoal_AttackPhase1(NULL);
                return;
            case 2:
                AddGoal_AttackPhase2(NULL);
                return;
            case 3:
                AddGoal_AttackPhase3();
                return;
            default:
                AddGoal_Idle();
                break;
            }
        }
    }
}
#endif

void CynderBossGoal_Think::Activate() {
    this->unk8 = 0;
    Arbitrate();
}

void CynderBossGoal_Think::Reset() {
    this->unk8 = 1;
    RemoveAllSubgoals();
    this->unk20 = 1;
    this->unk24 = 0;
    M2C_FIELD(this->unkC, f32 *, 0xF14) = 0.0f;
}

#if 0 // DRAFT: undefined identifier 'unk360'
void CynderBossGoal_Think::Deinit() {
    Goal<Cynder> *temp_r3_13954;
    Goal<Cynder> *temp_r3_13959;
    Goal<Cynder> *temp_r3_13979;
    Goal<Cynder> *temp_r3_13984;
    Goal<Cynder> *temp_r3_13989;
    MKHeap *temp_r3_14013;
    void **temp_r3_13947;
    void **temp_r3_13964;
    void **temp_r3_13969;
    void **temp_r3_13974;
    void *temp_r31_14010;

    temp_r3_13947 = this->unk48;
    M2C_FIELD(*temp_r3_13947, M2C_UNK (**)(void **), 0xC)(temp_r3_13947);
    operator delete(this->unk48);
    temp_r3_13954 = this->unk28;
    temp_r3_13954->Deinit();
    temp_r3_13959 = this->unk2C;
    temp_r3_13959->Deinit();
    temp_r3_13964 = this->unk30;
    M2C_FIELD(*temp_r3_13964, M2C_UNK (**)(void **), 0xC)(temp_r3_13964);
    temp_r3_13969 = this->unk34;
    M2C_FIELD(*temp_r3_13969, M2C_UNK (**)(void **), 0xC)(temp_r3_13969);
    temp_r3_13974 = this->unk38;
    M2C_FIELD(*temp_r3_13974, M2C_UNK (**)(void **), 0xC)(temp_r3_13974);
    temp_r3_13979 = this->unk3C;
    temp_r3_13979->Deinit();
    temp_r3_13984 = this->unk40;
    temp_r3_13984->Deinit();
    temp_r3_13989 = this->unk44;
    temp_r3_13989->Deinit();
    operator delete(this->unk28);
    operator delete(this->unk2C);
    operator delete(this->unk30);
    operator delete(this->unk34);
    operator delete(this->unk38);
    operator delete(this->unk3C);
    operator delete(this->unk40);
    operator delete(this->unk44);
    temp_r31_14010 = this->unk1C;
    if (temp_r31_14010 != NULL) {
        temp_r3_14013 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_14013 != NULL) {
            ((MKHeap *) (temp_r3_14013->Current()))->Free(temp_r31_14010, NULL, 0);
        } else {
            free(temp_r31_14010);
        }
        this->unk1C = NULL;
    }
    this->unk10 = 0;
    this->unk18 = 0;
    this->unk14 = 0;
    this->unk8 = 1;
    this->unkC = NULL;
    this->unk9 = 0;
    gb.unk360 = 0;
}
#endif

#if 0 // DRAFT: pointer/array required
void CynderBossGoal_Think::Init(Cynder *arg0) {
    Goal<Cynder> *temp_r4_14328;
    MKHeap *temp_r3_14301;
    void *var_r3_14308;

    if ((u8) this->unk9 == 0) {
        operator new(0x24U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk28 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x54U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__21CompositeGoal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x1C) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x18) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x10) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x14) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk2C = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x24U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__21CompositeGoal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x1C) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x18) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x10) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x14) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk30 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x3CU, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__13Goal<6Cynder>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__22CompositeGoal<6Cynder>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x1C) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x18) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x10) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x14) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk34 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x40U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__13Goal<6Cynder>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__22CompositeGoal<6Cynder>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x1C) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x18) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x10) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x14) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk38 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x2CU, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__13Goal<6Cynder>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__22CompositeGoal<6Cynder>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x1C) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x18) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x10) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x14) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk3C = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x2CU, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__13Goal<6Cynder>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__22CompositeGoal<6Cynder>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x1C) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x18) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x10) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x14) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk40 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x38U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__13Goal<6Cynder>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__22CompositeGoal<6Cynder>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x1C) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x18) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x10) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x14) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk44 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x54U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__13Goal<6Cynder>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__22CompositeGoal<6Cynder>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x1C) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x18) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x10) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x14) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk48 = M2C_ERROR(/* Read from unset register $r3 */);
    }
    this->unk24 = 0;
    if ((u8) this->unk9 == 0) {
        temp_r3_14301 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_14301 != NULL) {
            var_r3_14308 = ((MKHeap *) (temp_r3_14301->Current()))->Alloc(0x14, NULL, 0);
        } else {
            var_r3_14308 = malloc(0x14);
        }
        this->unk1C = var_r3_14308;
        this->unk10 = 5;
    }
    this->unk8 = 1;
    this->unkC = (Enemy *) arg0;
    this->unk4 = 0x98;
    if ((Enemy *) this->unkC != NULL) {
        this->unk9 = 1;
    }
    temp_r4_14328 = this->unk28;
    M2C_FIELD(temp_r4_14328, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_14328, Cynder **, 0xC) = arg0;
    M2C_FIELD(temp_r4_14328, s32 *, 4) = 0;
    if ((Cynder *) M2C_FIELD(temp_r4_14328, Cynder **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_14328, s8 *, 9) = 1;
    }
    this->unk2C->Init((Enemy *) arg0);
    this->unk30->Init((Enemy *) arg0);
    this->unk34->Init(arg0);
    this->unk38->Init(arg0);
    this->unk3C->Init(arg0);
    this->unk40->Init(arg0);
    this->unk44->Init(arg0);
    this->unk48->Init(arg0);
}
#endif

void CynderBossGoals_cpp::__sinit() {
    f32 temp_f0_14752;
    f64 temp_f1_14733;
    f64 temp_f1_14741;
    f64 temp_f3_14721;
    f64 temp_f4_14730;
    f64 temp_f4_14738;
    f64 temp_f8_14723;

    temp_f3_14721 = __frsqrte(2014000.0);
    temp_f8_14723 = __frsqrte(380000.0);
    temp_f4_14730 = 0.5 * temp_f3_14721 * -((2014000.0 * (temp_f3_14721 * temp_f3_14721)) - 3.0);
    temp_f1_14733 = 0.5 * temp_f8_14723 * -((380000.0 * (temp_f8_14723 * temp_f8_14723)) - 3.0);
    temp_f4_14738 = 0.5 * temp_f4_14730 * -((2014000.0 * (temp_f4_14730 * temp_f4_14730)) - 3.0);
    temp_f1_14741 = 0.5 * temp_f1_14733 * -((380000.0 * (temp_f1_14733 * temp_f1_14733)) - 3.0);
    temp_f0_14752 = (f32) (380000.0 * (0.5 * temp_f1_14741 * -((380000.0 * (temp_f1_14741 * temp_f1_14741)) - 3.0)));
    SPYRO_BOUNCE_Y_SPEED = (f32) (2014000.0 * (0.5 * temp_f4_14738 * -((2014000.0 * (temp_f4_14738 * temp_f4_14738)) - 3.0)));
    SPYRO_MIN_JUMP_Y_VELOCITY = temp_f0_14752;
}
