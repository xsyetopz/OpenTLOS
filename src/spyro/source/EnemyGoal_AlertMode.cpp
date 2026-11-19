#include "spyro/source/EnemyGoal_AlertMode.h"
#include "common/Source/Animation.h"
#include "common/Source/Frustum.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "common/Source/Texture.h"
#include "spyro/source/AITargetData.h"
#include "spyro/source/BoneBlurFX.h"
#include "spyro/source/Character.h"
#include "spyro/source/CharacterBodyFX.h"
#include "spyro/source/CharacterBreathFX.h"
#include "spyro/source/CharacterFireFX.h"
#include "spyro/source/CharacterGraph.h"
#include "spyro/source/CharacterZapFX.h"
#include "spyro/source/CollisionObject.h"
#include "spyro/source/Enemy.h"
#include "spyro/source/EnemyAttackPattern.h"
#include "spyro/source/EnemyDataTypes.h"
#include "spyro/source/EnemyDescriptor.h"
#include "spyro/source/EnemyGoal_DefensiveMode.h"
#include "spyro/source/EnemyGoal_FlyingAttackMode.h"
#include "spyro/source/EnemyGoal_MeleeAttackMode.h"
#include "spyro/source/EnemyGoal_RangeAttackMode.h"
#include "spyro/source/EnemyGoals_Movement.h"
#include "spyro/source/EnemyRegion.h"
#include "spyro/source/EnemySettings.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/GameMessages.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/Goal.h"
#include "spyro/source/IceBitsPS.h"
#include "spyro/source/KDPath.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/KDSpline.h"
#include "spyro/source/Level.h"
#include "spyro/source/MeleeTrails.h"
#include "spyro/source/Names.h"
#include "spyro/source/NodeLookAt.h"
#include "spyro/source/SB2.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/SpawnPointObject.h"
#include "spyro/source/SpawnerObject.h"
#include "spyro/source/TargetManager.h"
#include "unplaced_enums.h"
#include <m2c_macros.h>

M2C_UNK free(void *);                               /* extern */
void *malloc(M2C_UNK);                              /* extern */
extern void **gMK;
extern M2C_UNK gb;

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to
void EnemyGoal_AlertMode::CalculateRegionEdgeMoveTarget(bool arg0) {
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
    f64 spB8;
    f32 spB0;
    f64 spA8;
    M2C_UNK sp98;
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
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f64 sp10;
    f64 sp8;
    Enemy *temp_r4_302;
    f64 temp_f0_105;
    f64 temp_f0_125;
    f64 temp_f0_137;
    f64 temp_f0_221;
    f64 temp_f0_231;
    f64 temp_f0_251;
    f64 temp_f0_263;
    f64 temp_f0_95;
    u8 var_r30_158;

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
        ((AITargetData *) &sp198)->GetPos();
        this->unkC->unk800.GetNearestPointOnBoundingRegion(*((MKVector3 *) &sp198), (MKVector3 *) &sp1D8, (MKVector3 *) &sp1B8);
        sp178.operator*(100.0f);
        sp68 = sp1D8 + M2C_BITWISE(f64, sp178);
        sp188 = sp68;
        sp70 = (f32) sp1E0 + sp178.unk8;
        sp1C8 = sp68;
        sp190 = (f64) sp70;
        sp1D0 = (f64) sp70;
        temp_f0_95 = sp1B8 * 5.263544247e-315;
        spB8 = temp_f0_95;
        sp158 = temp_f0_95;
        spC0 = (f32) sp1C0 * 1.0f;
        sp160 = (f64) spC0;
        temp_f0_105 = sp1D8 + temp_f0_95;
        spA8 = temp_f0_105;
        sp168 = temp_f0_105;
        spB0 = (f32) sp1E0 + (f32) sp160;
        sp170 = (f64) spB0;
        if (this->unkC->unk800.GetFirstIntersectionPlane(*((MKVector3 *) &sp168), *((MKVector3 *) &sp1C8), (MKVector3 *) &sp1C8, (MKVector3 *) &sp1A8) != 0) {
            temp_f0_125 = sp1C8 - sp1D8;
            sp28 = temp_f0_125;
            sp138 = temp_f0_125;
            sp30 = (f32) sp1D0 - (f32) sp1E0;
            sp140 = (f64) sp30;
            temp_f0_137 = temp_f0_125 * 5.222099017e-315;
            sp58 = temp_f0_137;
            sp148 = temp_f0_137;
            sp60 = (f32) sp140 * 0.5f;
            sp150 = (f64) sp60;
            sp1D8 += temp_f0_137;
            sp1E0 = (f32) sp1E0 + (f32) sp150;
        } else {
            var_r30_158 = 0;
            if (this->unkC->unk800.IsPointWithin(*((MKVector3 *) &sp1C8)) != 0) {
                ((EnemyRegion *) &sp98)->GetRegionPos();
                if ((f32) fabs(sp9C - (*(f32 *) ((u8 *) &sp1C8 + 0x4))) <= 500.0f) {
                    var_r30_158 = 1;
                }
            }
            if (var_r30_158 != 0) {
                sp1D8 = sp1C8;
                sp1E0 = sp1D0;
            }
        }
    } else {
        ((AITargetData *) &sp128)->GetPos();
        this->unkC->unk838.GetNearestPointOnBoundingRegion(*((MKVector3 *) &sp128), (MKVector3 *) &sp1D8, (MKVector3 *) &sp1B8);
        sp1B8 *= 1.58735232e-314;
        sp1C0 = (f32) sp1C0 * -1.0f;
        sp108.operator*(100.0f);
        sp48 = sp1D8 + M2C_BITWISE(f64, sp108);
        sp118 = sp48;
        sp50 = (f32) sp1E0 + sp108.unk8;
        sp1C8 = sp48;
        sp120 = (f64) sp50;
        sp1D0 = (f64) sp50;
        temp_f0_221 = sp1B8 * 5.263544247e-315;
        sp88 = temp_f0_221;
        spE8 = temp_f0_221;
        sp90 = sp1C0 * 1.0f;
        spF0 = (f64) sp90;
        temp_f0_231 = sp1D8 + temp_f0_221;
        sp78 = temp_f0_231;
        spF8 = temp_f0_231;
        sp80 = (f32) sp1E0 + (f32) spF0;
        sp100 = (f64) sp80;
        if (this->unkC->unk838.GetFirstIntersectionPlane(*((MKVector3 *) &spF8), *((MKVector3 *) &sp1C8), (MKVector3 *) &sp1C8, (MKVector3 *) &sp1A8) != 0) {
            temp_f0_251 = sp1C8 - sp1D8;
            sp18 = temp_f0_251;
            spC8 = temp_f0_251;
            sp20 = (f32) sp1D0 - (f32) sp1E0;
            spD0 = (f64) sp20;
            temp_f0_263 = temp_f0_251 * 5.222099017e-315;
            sp38 = temp_f0_263;
            spD8 = temp_f0_263;
            sp40 = (f32) spD0 * 0.5f;
            spE0 = (f64) sp40;
            sp1D8 += temp_f0_263;
            sp1E0 = (f32) sp1E0 + (f32) spE0;
        } else if (this->unkC->unk838.IsPointWithin(*((MKVector3 *) &sp1C8)) == 0) {
            sp1D8 = sp1C8;
            sp1E0 = sp1D0;
        }
    }
    this->unkC->unk8C0.Set(*((MKVector3 *) &sp1D8), 0U);
    this->unkC->unk8C0.SetInsideRegion(1U);
    temp_r4_302 = this->unkC;
    temp_r4_302->unk8C0.Update(temp_r4_302->unk588);
}
#endif

s32 EnemyGoal_AlertMode::AddGoal_MoveAwayFromHero() {
    Enemy *temp_r3_352;
    Enemy *temp_r4_330;

    if ((u8) this->unk8 == 0) {
        temp_r4_330 = this->unkC;
        if ((((u8) temp_r4_330->unkB08 >> 6U) & 1) && (((u8) temp_r4_330->unkB09 >> 6U) & 1) && (IsActive(0x4F) == 0) && (IsPresent(0x28) == 0)) {
            temp_r3_352 = this->unkC;
            if (temp_r3_352->CanMoveAwayFromHero() != 0) {
                AddSubgoal((Goal<Enemy> *) this->unk38);
                return 1;
            }
        }
    }
    return 0;
}

#if 0 // DRAFT: undefined identifier '__vptr'
u8 EnemyGoal_AlertMode::AddGoal_DefensiveMode() {
    AITargetData *temp_r3_418;
    AITargetData *temp_r3_445;
    Enemy *temp_r3_382;
    u8 var_r30_390;
    u8 var_r30_419;

    temp_r3_382 = this->unkC;
    var_r30_390 = temp_r3_382->IsAttacking();
    if (IsActive(0x3B) != 0) {
        var_r30_390 = ((u8) this->unkC->unkB08 >> 4U) & 1;
    }
    if (((u8) this->unk8 == 0) && (((u8) this->unkC->unkB08 >> 6U) & 1) && (var_r30_390 == 0) && (IsActive(0x4F) == 0)) {
        temp_r3_418 = this->unk20;
        var_r30_419 = 0;
        if (((u8) M2C_FIELD(temp_r3_418, u8 *, 0x48) == 2) || (temp_r3_418->unk40.Get() != NULL)) {
            var_r30_419 = 1;
        }
        if ((var_r30_419 != 0) && (M2C_FIELD(this->unk20->unk40.Get()->__vptr, u8 (**)(), 0x44)() != 0) && (((((u8) this->unkC->unkB00 >> 1U) & 1) && (temp_r3_445 = this->unk20, (((((u8) M2C_FIELD(temp_r3_445, u8 *, 0x49) >> 6U) & 1) == 0) == 0)) && (this->unkC->SelectDefensiveAttack(temp_r3_445->GetDist(), 0x40000U) != 0)) || ((((u8) this->unkC->unkB00 >> 2U) & 1) && (this->unkC->SelectDefensiveAttack(this->unk20->GetDist(), 0x20000U) != 0)) || ((((u8) this->unkC->unkB00 >> 3U) & 1) && (this->unkC->SelectDefensiveAttack(this->unk20->GetDist(), 0x10000U) != 0)))) {
            RemoveAllSubgoals();
            AddSubgoal((Goal<Enemy> *) this->unk3C);
            M2C_FIELD(this->unk3C, AITargetData **, 0x20) = (AITargetData *) this->unk20;
            return 1U;
        }
        goto block_19;
    }
block_19:
    return 0U;
}
#endif

u8 EnemyGoal_AlertMode::AddGoal_FlyingAttackMode() {
    if (((this->unk4C & 4) > 0) && (((u8) this->unkC->unkB00 >> 5U) & 1)) {
        AddSubgoal((Goal<Enemy> *) this->unk34);
        M2C_FIELD(this->unk34, AITargetData **, 0x20) = (AITargetData *) this->unk20;
        return 1U;
    }
    return 0U;
}

#if 0 // DRAFT: illegal implicit conversion from 'long' to
u8 EnemyGoal_AlertMode::AddGoal_RangedAttackMode() {
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    AttackerManager *temp_r30_597;
    Enemy *temp_r3_543;
    Enemy *temp_r3_551;
    Frustum *temp_r28_547;
    f32 temp_f1_576;
    f64 temp_f0_571;
    f64 temp_f1_550;
    f64 temp_f1_561;
    s32 temp_r28_589;
    s32 var_r29_610;
    s32 var_r30_628;
    u8 var_r3_598;
    u8 var_r3_616;
    void *temp_r4_558;

    temp_r3_543 = this->unkC;
    temp_r28_547 = M2C_FIELD(&gb, s32 *, 0x3B8) + 0xB0;
    temp_f1_550 = temp_r3_543->GetCollisionRadius(M2C_FIELD(&gb, s32 *, 0x3B8));
    temp_r3_551 = this->unkC;
    sp18 = M2C_FIELD(temp_r3_551, f64 *, 0xD0) * temp_f1_550;
    temp_r4_558 = temp_r3_551->unk8;
    temp_f1_561 = M2C_FIELD(temp_r4_558, f64 *, 0x30);
    sp20 = temp_r3_551->unkD8 * (f32) temp_f1_550;
    sp28 = sp18;
    sp38 = temp_f1_561;
    sp30 = (f64) sp20;
    sp40 = M2C_FIELD(temp_r4_558, f64 *, 0x38);
    temp_f0_571 = temp_f1_561 + sp28;
    sp8 = temp_f0_571;
    temp_f1_576 = (f32) sp40 + (f32) sp30;
    sp48 = temp_f0_571;
    sp10 = temp_f1_576;
    sp50 = (f64) sp10;
    temp_r28_589 = temp_r28_547->IsVisible(*((MKVector3 *) &sp48), temp_r3_551->GetCollisionRadius(temp_r4_558, temp_f1_576, (f32) sp40, sp18));
    temp_r30_597 = M2C_FIELD(this->unk20->unk40.Get()->__vptr, AttackerManager *(**)(), 0x48)();
    var_r3_598 = 0;
    if ((((u8) this->unk50 >> 7U) & 1) && (temp_r30_597 != NULL)) {
        var_r3_598 = 1;
    }
    if (var_r3_598 != 0) {
        var_r29_610 = temp_r30_597->GetAttackerCount(4);
    } else {
        var_r29_610 = 0;
    }
    var_r3_616 = 0;
    if ((((u8) this->unk50 >> 7U) & 1) && (temp_r30_597 != NULL)) {
        var_r3_616 = 1;
    }
    if (var_r3_616 != 0) {
        var_r30_628 = temp_r30_597->GetAttackerCount(1);
    } else {
        var_r30_628 = 0;
    }
    if (((this->unk4C & 2) > 0) && ((u8) temp_r28_589 != 0) && (((u8) this->unkC->unkB00 >> 6U) & 1) && (this->unk20->GetDist() > this->unkC->unkA38->unk13C) && (var_r30_628 <= 0) && (var_r29_610 <= 3)) {
        AddSubgoal((Goal<Enemy> *) this->unk30);
        M2C_FIELD(this->unk30, AITargetData **, 0x20) = (AITargetData *) this->unk20;
        return 1U;
    }
    return 0U;
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
u8 EnemyGoal_AlertMode::AddGoal_MeleeAttackMode() {
    AITargetData *temp_r3_715;
    AttackerManager *temp_r3_687;
    s32 var_r31_700;
    u8 temp_r0_717;
    u8 var_r28_725;
    u8 var_r29_706;
    u8 var_r4_689;
    u8 var_r4_716;
    void *temp_r3_707;

    temp_r3_687 = M2C_FIELD(this->unk20->unk40.Get()->__vptr, AttackerManager *(**)(), 0x48)();
    var_r4_689 = 0;
    if ((((u8) this->unk50 >> 7U) & 1) && (temp_r3_687 != NULL)) {
        var_r4_689 = 1;
    }
    if (var_r4_689 != 0) {
        var_r31_700 = temp_r3_687->GetAttackerCount(1);
    } else {
        var_r31_700 = 0;
    }
    var_r29_706 = 0;
    temp_r3_707 = this->unkC->unkA44;
    if ((temp_r3_707 != NULL) && (M2C_FIELD(temp_r3_707, s32 *, 4) & 0x4000)) {
        var_r29_706 = 1;
    }
    temp_r3_715 = this->unk20;
    var_r4_716 = 0;
    temp_r0_717 = M2C_FIELD(temp_r3_715, u8 *, 0x49);
    if (((temp_r0_717 >> 6U) & 1) && !((temp_r0_717 >> 5U) & 1)) {
        var_r4_716 = 1;
    }
    var_r28_725 = var_r4_716;
    if ((var_r4_716 == 0) && (this->unkC->SelectAttack(temp_r3_715->GetDist(), 1U, 0U, 1U) != 0)) {
        var_r28_725 = 1;
    }
    if ((this->unk4C & 1) && (((u8) this->unkC->unkB00 >> 7U) & 1) && (var_r28_725 != 0) && ((var_r29_706 != 0) || (this->unk20->GetDist() < this->unkC->unkA38->unk138)) && (var_r31_700 <= 5)) {
        AddSubgoal((Goal<Enemy> *) this->unk2C);
        M2C_FIELD(this->unk2C, AITargetData **, 0x20) = (AITargetData *) this->unk20;
        return 1U;
    }
    return 0U;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long' to
u8 EnemyGoal_AlertMode::AddGoal_OnlyRangeAttack() {
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    Enemy *temp_r3_786;
    Enemy *temp_r3_800;
    Frustum *temp_r31_797;
    f32 temp_f1_825;
    f64 temp_f0_820;
    f64 temp_f1_799;
    f64 temp_f1_810;
    s32 temp_r3_836;
    u8 temp_r4_787;
    void *temp_r4_807;

    temp_r3_786 = this->unkC;
    temp_r4_787 = temp_r3_786->unkB00;
    if ((temp_r4_787 & 1) && ((temp_r4_787 >> 6U) & 1)) {
        temp_r31_797 = M2C_FIELD(&gb, s32 *, 0x3B8) + 0xB0;
        temp_f1_799 = M2C_FIELD(temp_r3_786->__vptr, f64 (**)(s32), 0x100)(M2C_FIELD(&gb, s32 *, 0x3B8));
        temp_r3_800 = this->unkC;
        sp18 = M2C_FIELD(temp_r3_800, f64 *, 0xD0) * temp_f1_799;
        temp_r4_807 = temp_r3_800->unk8;
        temp_f1_810 = M2C_FIELD(temp_r4_807, f64 *, 0x30);
        sp20 = temp_r3_800->unkD8 * (f32) temp_f1_799;
        sp28 = sp18;
        sp38 = temp_f1_810;
        sp30 = (f64) sp20;
        sp40 = M2C_FIELD(temp_r4_807, f64 *, 0x38);
        temp_f0_820 = temp_f1_810 + sp28;
        sp8 = temp_f0_820;
        temp_f1_825 = (f32) sp40 + (f32) sp30;
        sp48 = temp_f0_820;
        sp10 = temp_f1_825;
        sp50 = (f64) sp10;
        temp_r3_836 = temp_r31_797->IsVisible(*((MKVector3 *) &sp48), temp_r3_800->GetCollisionRadius(temp_r4_807, temp_f1_825, (f32) sp40, sp18));
        if ((this->unk4C & 2) && ((u8) temp_r3_836 != 0)) {
            AddSubgoal((Goal<Enemy> *) this->unk30);
            M2C_FIELD(this->unk30, AITargetData **, 0x20) = (AITargetData *) this->unk20;
        } else {
            AddGoal_Taunt();
        }
        return 1U;
    }
    return 0U;
}
#endif

#if 0 // DRAFT: function call 'GetCollisionRadius(Enemy *, double)' does not match
u8 EnemyGoal_AlertMode::AddGoal_MoveToRegion() {
    MKCollisionResult spD8;
    f64 spD0;                                       /* compiler-managed */
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
    f64 sp70;
    f64 sp68;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp50;
    f64 sp48;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f64 sp10;
    f64 sp8;
    Enemy *temp_r3_1024;
    Enemy *temp_r3_879;
    Enemy *temp_r3_893;
    Enemy *temp_r4_1052;
    Enemy *temp_r4_900;
    Goal<Enemy> *temp_r6_1031;
    f32 temp_f0_909;
    f32 temp_f1_1028;
    f32 temp_f31_901;
    f32 temp_f3_937;
    f32 var_f30_912;
    f64 temp_f0_918;
    f64 temp_f0_945;
    f64 temp_f0_987;
    f64 temp_f5_929;

    temp_r3_879 = this->unkC;
    if (((SB2 *) temp_r3_879->unk640 != NULL) && (temp_r3_879->IsInsideEnemyRegion() == 0)) {
        spC8 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
        spD0 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
        spB8 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
        spC0 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
        temp_r3_893 = this->unkC;
        sp8 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
        sp10 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
        temp_r4_900 = this->unkC;
        temp_f31_901 = temp_r3_893->GetCollisionRadius(M2C_FIELD(&MKVector3::zero, f64 *, 0));
        temp_r4_900->unk800.GetNearestPointOnBoundingRegion(temp_r4_900->unk710, (MKVector3 *) &spC8, (MKVector3 *) &spB8);
        temp_f0_909 = 2.0f * temp_f31_901;
        if (150.0f > temp_f0_909) {
            var_f30_912 = 150.0f;
        } else {
            var_f30_912 = temp_f0_909;
        }
        temp_f0_918 = spB8 * (f64) var_f30_912;
        sp18 = temp_f0_918;
        spA8 = temp_f0_918;
        sp20 = (f32) spC0 * var_f30_912;
        spB0 = (f64) sp20;
        temp_f5_929 = spC8 + temp_f0_918;
        spC8 = temp_f5_929;
        sp60 = 0.0f;
        temp_f3_937 = (f32) spD0 + (f32) spB0;
        sp58 = 0.0f;
        sp5C = 200.0f;
        spD0 = temp_f3_937;
        sp88 = (f64) sp58;
        sp90 = (f64) sp60;
        temp_f0_945 = temp_f5_929 + sp88;
        sp48 = temp_f0_945;
        sp98 = temp_f0_945;
        sp50 = temp_f3_937 + (f32) sp90;
        spA0 = (f64) sp50;
        if (MKCollision_GetGroundPoint(*((MKVector3 *) &sp98), 300.0f, &spD8, 0x04000000, 2, NULL, (MKCollisionMode) 7) != 0) {
            (*(f32 *) ((u8 *) &spC8 + 0x4)) = spD8.unk4;
            if ((f32) fabs(spD8.unk4 - this->unkC->unk588.unk4) > 200.0f) {
                return 0U;
            }
            sp3C = temp_f31_901;
            sp38 = 0.0f;
            sp40 = 0.0f;
            sp68 = (f64) sp38;
            sp70 = (f64) sp40;
            temp_f0_987 = spC8 + sp68;
            sp28 = temp_f0_987;
            sp78 = temp_f0_987;
            sp30 = spD0 + (f32) sp70;
            sp80 = (f64) sp30;
            if (MKCollision_SphereCollide(*((MKVector3 *) &sp78), temp_f31_901, NULL, 0, (MKCollisionMode) 7, 0x04000000) != 0) {
                return 0U;
            }
            this->unkC->unk8C0.Set(*((MKVector3 *) &spC8), 0U);
            this->unkC->unk8C0.SetInsideRegion(1U);
            AddSubgoal((Goal<Enemy> *) this->unk40);
            temp_r3_1024 = this->unkC;
            temp_f1_1028 = temp_r3_1024->GetCollisionRadius();
            temp_r6_1031 = this->unk40;
            M2C_FIELD(temp_r6_1031, AITargetData **, 0x10) = &this->unkC->unk8C0;
            M2C_FIELD(temp_r6_1031, f32 *, 0x18) = temp_f1_1028;
            M2C_FIELD(temp_r6_1031, u8 *, 0x30) = (u8) (M2C_FIELD(temp_r6_1031, u8 *, 0x30) | 0x80);
            M2C_FIELD(temp_r6_1031, s32 *, 0x20) = 0;
            M2C_FIELD(temp_r6_1031, s32 *, 0x24) = 0;
            M2C_FIELD(temp_r6_1031, s32 *, 0x28) = -1;
            M2C_FIELD(temp_r6_1031, u8 *, 0x30) = (u8) (M2C_FIELD(temp_r6_1031, u8 *, 0x30) & ~0x40);
            M2C_FIELD(temp_r6_1031, u8 *, 0x30) = (u8) (M2C_FIELD(temp_r6_1031, u8 *, 0x30) | 0x20);
            M2C_FIELD(temp_r6_1031, u8 *, 0x30) = (u8) (M2C_FIELD(temp_r6_1031, u8 *, 0x30) & ~0x10);
            temp_r4_1052 = this->unkC;
            temp_r4_1052->unk8C0.Update(temp_r4_1052->unk588);
            return 1U;
        }
        return 0U;
    }
    return 0U;
}
#endif

void EnemyGoal_AlertMode::AddGoal_Taunt() {
    Goal<Enemy> *temp_r5_1084;

    AddSubgoal((Goal<Enemy> *) this->unk28);
    temp_r5_1084 = this->unk28;
    M2C_FIELD(temp_r5_1084, AITargetData **, 0x10) = (AITargetData *) this->unk20;
    M2C_FIELD(temp_r5_1084, s32 *, 0x14) = 1;
    M2C_FIELD(temp_r5_1084, s32 *, 0x18) = 3;
    M2C_FIELD(temp_r5_1084, s32 *, 0x1C) = (s32) this->unkC->unk688;
    M2C_FIELD(temp_r5_1084, u8 *, 0x20) = (u8) (M2C_FIELD(temp_r5_1084, u8 *, 0x20) | 0x40);
    this->unkC->TryChangeEnemyRegion();
}

u8 EnemyGoal_AlertMode::AddGoal_Summon() {
    Enemy *temp_r3_1125;
    Enemy *temp_r4_1112;
    Goal<Enemy> *temp_r4_1133;
    Goal<Enemy> *temp_r6_1143;
    SpawnerObject *temp_r3_1119;
    void *temp_r3_1113;

    temp_r4_1112 = this->unkC;
    temp_r3_1113 = temp_r4_1112->unkA44;
    if ((temp_r3_1113 != NULL) && (M2C_FIELD(temp_r3_1113, s32 *, 4) & 0x40)) {
        temp_r3_1119 = temp_r4_1112->unkA4C;
        if (temp_r3_1119 != NULL) {
            temp_r3_1119->GetNumberActive();
            if ((s32) M2C_ERROR(/* Read from unset register $r3 */) <= 0) {
                temp_r3_1125 = this->unkC;
                temp_r3_1125->OnSummon();
                this->unkC->unkA4C->SetDefaults();
                temp_r4_1133 = this->unk44;
                if (temp_r4_1133 != NULL) {
                    AddSubgoal((Goal<Enemy> *) temp_r4_1133);
                } else {
                    AddSubgoal((Goal<Enemy> *) this->unk28);
                    temp_r6_1143 = this->unk28;
                    M2C_FIELD(temp_r6_1143, AITargetData **, 0x10) = (AITargetData *) this->unk20;
                    M2C_FIELD(temp_r6_1143, s32 *, 0x14) = 1;
                    M2C_FIELD(temp_r6_1143, s32 *, 0x18) = 0xB;
                    M2C_FIELD(temp_r6_1143, s32 *, 0x1C) = 0;
                    M2C_FIELD(temp_r6_1143, u8 *, 0x20) = (u8) (M2C_FIELD(temp_r6_1143, u8 *, 0x20) & ~0x40);
                }
                return 1U;
            }
        }
    }
    return 0U;
}

#if 0 // DRAFT: illegal implicit conversion from 'Enemy *' to
s32 EnemyGoal_AlertMode::AddGoal_Alert() {
    IsInAlertRangeMsg sp18;
    f64 sp10;
    f64 sp8;
    Enemy *temp_r5_1176;
    Enemy *temp_r7_1200;
    Goal<Enemy> *temp_r5_1221;
    void *temp_r5_1194;

    temp_r5_1176 = this->unkC;
    if (!(((u8) temp_r5_1176->unkB08 >> 6U) & 1) && (temp_r5_1176->unkA38->GetAnimSequence(1, 2, temp_r5_1176->unkAE4, NULL) != NULL)) {
        sp18.unk4 = 0;
        temp_r5_1194 = this->unkC->unk8;
        sp8 = M2C_FIELD(temp_r5_1194, f64 *, 0x30);
        sp10 = M2C_FIELD(temp_r5_1194, f64 *, 0x38);
        sp18.Init(*((MKVector3 *) &sp8), 2000.0f);
        temp_r7_1200 = this->unkC;
        sp18.unk4 = temp_r7_1200;
        M2C_FIELD(*gMK, M2C_UNK (**)(void **, IsInAlertRangeMsg *, M2C_UNK, M2C_UNK, void *, M2C_UNK, f32), 0x94)(gMK, &sp18, 8, 0, temp_r7_1200->unk8 + 0x30, 1, 2000.0f);
        AddSubgoal((Goal<Enemy> *) this->unk24);
        temp_r5_1221 = this->unk24;
        M2C_FIELD(temp_r5_1221, AITargetData **, 0x10) = (AITargetData *) this->unk20;
        M2C_FIELD(temp_r5_1221, Enemy **, 0x14) = sp18.unk1C;
        M2C_FIELD(temp_r5_1221, f32 *, 0x18) = (f32) this->unkC->unkA38->unk160;
        return 1;
    }
    return 0;
}
#endif

void EnemyGoal_AlertMode::SetSummonGoal(Goal<Enemy> *arg0) {
    this->unk44 = (Goal<Enemy> *) arg0;
}

void EnemyGoal_AlertMode::Terminate() {
    Enemy *temp_r5_1253;
    Enemy *temp_r5_1257;

    temp_r5_1253 = this->unkC;
    temp_r5_1253->unkB08 &= ~0x40;
    temp_r5_1257 = this->unkC;
    temp_r5_1257->unkB08 &= ~0x20;
    this->unk8 = 1;
    RemoveAllSubgoals();
}

#if 0 // DRAFT: illegal explicit conversion from 'AITargetData' to
u8 EnemyGoal_AlertMode::Update() {
    AITargetData sp48;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f64 sp8;
    AITargetData *temp_r3_1284;
    AITargetData *temp_r3_1411;
    Enemy *temp_r3_1334;
    Enemy *temp_r3_1447;
    f32 temp_f30_1339;
    f32 temp_f3_1327;
    f32 temp_f3_1364;
    f32 temp_f4_1321;
    f32 temp_f5_1323;
    f32 var_f31_1365;
    s32 temp_r3_1300;
    u8 temp_r0_1299;
    u8 var_r30_1285;
    u8 var_r30_1415;

    if (((u8) this->unk50 >> 6U) & 1) {
        temp_r3_1284 = this->unk20;
        var_r30_1285 = 0;
        if (((u8) M2C_FIELD(temp_r3_1284, u8 *, 0x48) == 2) || (temp_r3_1284->unk40.Get() != NULL)) {
            var_r30_1285 = 1;
        }
        if (var_r30_1285 != 0) {
            temp_r0_1299 = M2C_FIELD(this->unk20, u8 *, 0x49);
            temp_r3_1300 = (temp_r0_1299 >> 6U) & 1;
            if ((temp_r3_1300 == 0) || ((u32) ((temp_r0_1299 >> 5U) & 1) != 0)) {
                CalculateRegionEdgeMoveTarget(temp_r3_1300 == 0);
                sp48.GetPos();
                ((AITargetData *) &sp48.unk10)->GetPos();
                temp_f4_1321 = (*(f32 *) ((u8 *) &sp48 + 0x14)) - (*(f32 *) ((u8 *) &sp48 + 0x4));
                temp_f5_1323 = (f32) sp48.unk10 - M2C_BITWISE(f32, sp48);
                temp_f3_1327 = (f32) sp48.unk18 - sp48.unk8;
                if (((temp_f3_1327 * temp_f3_1327) + ((temp_f5_1323 * temp_f5_1323) + (temp_f4_1321 * temp_f4_1321))) < 1000000.0f) {
                    temp_r3_1334 = this->unkC;
                    temp_f30_1339 = temp_r3_1334->GetCollisionRadius();
                    sp20 = 0.0f;
                    sp18 = 0.0f;
                    sp1C = 50.0f + temp_f30_1339;
                    sp30 = (f64) sp20;
                    sp28 = (f64) sp18;
                    ((AITargetData *) &sp38)->GetPos();
                    sp8 = sp38 + sp28;
                    temp_f3_1364 = 2.0f * temp_f30_1339;
                    var_f31_1365 = 200.0f;
                    sp48.unk20 = sp8;
                    sp10 = sp40 + (f32) sp30;
                    sp48.unk28 = (f64) sp10;
                    if (var_f31_1365 > temp_f3_1364) {

                    } else {
                        var_f31_1365 = temp_f3_1364;
                    }
                    if (!(this->unkC->unk8C0.GetDist() > var_f31_1365) || (MKCollision_SphereCollide(*((MKVector3 *) &sp48.unk20), temp_f30_1339, NULL, 0, (MKCollisionMode) 7, 0x04000000) != 0)) {
                        this->unk8 = 1;
                    }
                } else {
                    this->unk8 = 1;
                }
            } else {
                this->unk8 = 1;
            }
        }
    }
    AddGoal_MoveAwayFromHero();
    ActivateIfInactive();
    this->unk8 = UpdateSubgoals();
    AddGoal_DefensiveMode();
    temp_r3_1411 = this->unk20;
    if (temp_r3_1411 != NULL) {
        var_r30_1415 = 0;
        if (((u8) M2C_FIELD(temp_r3_1411, u8 *, 0x48) == 2) || (temp_r3_1411->unk40.Get() != NULL)) {
            var_r30_1415 = 1;
        }
        if (var_r30_1415 != 0) {
            if ((M2C_FIELD(&gb, f32 *, 0x30C) >= this->unk48) && (IsActive(0x21) != 0) && !(((u8) M2C_FIELD(M2C_FIELD(this->unk2C, void **, 0x28), u8 *, 0x30) >> 4U) & 1)) {
                temp_r3_1447 = this->unkC;
                if (temp_r3_1447->IsTargetBehindWall() != 0) {
                    this->unk8 = 3;
                    return this->unk8;
                }
                this->unk48 = M2C_FIELD(&gb, f32 *, 0x30C) + 0.25f;
                goto block_27;
            }
block_27:
            if ((u8) this->unk8 == 2) {
                this->unk8 = 1;
            }
            ReactivateIfFailed();
            ActivateIfInactive();
            goto block_30;
        }
        goto block_30;
    }
block_30:
    return this->unk8;
}
#endif

void EnemyGoal_AlertMode::Activate() {
    AITargetData *temp_r3_1502;
    u8 var_r31_1506;

    this->unk8 = 0;
    this->unk50 &= ~0x40;
    RemoveAllSubgoals();
    temp_r3_1502 = this->unk20;
    if (temp_r3_1502 != NULL) {
        var_r31_1506 = 0;
        if (((u8) M2C_FIELD(temp_r3_1502, u8 *, 0x48) == 2) || (temp_r3_1502->unk40.Get() != NULL)) {
            var_r31_1506 = 1;
        }
        if (var_r31_1506 == 0) {
            goto block_5;
        }
        this->unk48 = M2C_FIELD(&gb, f32 *, 0x30C) + 1.0f;
        AddGoal_Alert();
        if ((AddGoal_DefensiveMode() == 0) && (AddGoal_Summon() == 0) && (AddGoal_MoveToRegion() == 0) && (AddGoal_OnlyRangeAttack() == 0) && (AddGoal_MeleeAttackMode() == 0) && (AddGoal_RangedAttackMode() == 0) && (AddGoal_FlyingAttackMode() == 0)) {
            AddGoal_Taunt();
        }
        return;
    }
block_5:
    this->unk8 = 2;
}

#if 0 // DRAFT: undefined identifier '__vptr'
void EnemyGoal_AlertMode::Deinit() {
    Goal<Enemy> *temp_r3_1577;
    Goal<Enemy> *temp_r3_1582;
    Goal<Enemy> *temp_r3_1587;
    Goal<Enemy> *temp_r3_1592;
    Goal<Enemy> *temp_r3_1605;
    Goal<Enemy> *temp_r3_1615;
    Goal<Enemy> *temp_r3_1625;
    Goal<Enemy> *temp_r3_1635;
    void *temp_r31_1645;

    temp_r3_1577 = this->unk28;
    temp_r3_1577->Deinit();
    temp_r3_1582 = this->unk38;
    temp_r3_1582->Deinit();
    temp_r3_1587 = this->unk3C;
    temp_r3_1587->Deinit();
    temp_r3_1592 = this->unk40;
    temp_r3_1592->Deinit();
    operator delete(this->unk28);
    operator delete(this->unk38);
    operator delete(this->unk3C);
    operator delete(this->unk40);
    temp_r3_1605 = this->unk24;
    if (temp_r3_1605 != NULL) {
        M2C_FIELD(temp_r3_1605->__vptr, M2C_UNK (**)(), 0xC)();
        operator delete(this->unk24);
    }
    temp_r3_1615 = this->unk2C;
    if (temp_r3_1615 != NULL) {
        M2C_FIELD(temp_r3_1615->__vptr, M2C_UNK (**)(), 0xC)();
        operator delete(this->unk2C);
    }
    temp_r3_1625 = this->unk30;
    if (temp_r3_1625 != NULL) {
        M2C_FIELD(temp_r3_1625->__vptr, M2C_UNK (**)(), 0xC)();
        operator delete(this->unk30);
    }
    temp_r3_1635 = this->unk34;
    if (temp_r3_1635 != NULL) {
        M2C_FIELD(temp_r3_1635->__vptr, M2C_UNK (**)(), 0xC)();
        operator delete(this->unk34);
    }
    temp_r31_1645 = this->unk1C;
    if (temp_r31_1645 != NULL) {
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_1645, NULL, 0);
        } else {
            free(temp_r31_1645);
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
#endif

#if 0 // DRAFT: pointer/array required
void EnemyGoal_AlertMode::Init(Enemy *arg0) {
    Goal<Enemy> *temp_r3_1976;
    Goal<Enemy> *temp_r3_1982;
    Goal<Enemy> *temp_r3_1988;
    Goal<Enemy> *temp_r4_1952;
    Goal<Enemy> *temp_r4_1963;
    Goal<Enemy> *temp_r4_2000;
    void *var_r3_1929;

    if ((arg0 != NULL) && ((u8) this->unk9 == 0)) {
        this->unk24 = NULL;
        this->unk28 = NULL;
        this->unk2C = NULL;
        this->unk30 = NULL;
        this->unk34 = NULL;
        this->unk44 = NULL;
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
        if (arg0->unkA38->GetAnimSequence(1, 2, 0, NULL) != NULL) {
            operator new(0x1CU, NULL, 0);
            if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
                *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
                *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
            }
            this->unk24 = M2C_ERROR(/* Read from unset register $r3 */);
        }
        if ((s32) arg0->unkA38->unk214 > 0) {
            operator new(0x44U, NULL, 0);
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
        }
        if ((s32) arg0->unkA38->unk21C > 0) {
            operator new(0x2CU, NULL, 0);
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
        }
        if ((s32) arg0->unkA38->unk218 > 0) {
            operator new(0x34U, NULL, 0);
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
            this->unk34 = M2C_ERROR(/* Read from unset register $r3 */);
        }
        operator new(0x28U, NULL, 0);
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
        this->unk38 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x38U, NULL, 0);
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
        this->unk3C = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x34U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk40 = M2C_ERROR(/* Read from unset register $r3 */);
    }
    if ((u8) this->unk9 == 0) {
        if (MKHeap::Current() != NULL) {
            var_r3_1929 = ((MKHeap *) (MKHeap::Current()))->Alloc(0x10, NULL, 0);
        } else {
            var_r3_1929 = malloc(0x10);
        }
        this->unk1C = var_r3_1929;
        this->unk10 = 4;
    }
    this->unk8 = 1;
    this->unkC = arg0;
    this->unk4 = 0x54;
    if ((Enemy *) this->unkC != NULL) {
        this->unk9 = 1;
    }
    if ((u8) this->unk9 != 0) {
        temp_r4_1952 = this->unk28;
        M2C_FIELD(temp_r4_1952, s8 *, 8) = 1;
        M2C_FIELD(temp_r4_1952, Enemy **, 0xC) = arg0;
        M2C_FIELD(temp_r4_1952, s32 *, 4) = 0;
        if ((Enemy *) M2C_FIELD(temp_r4_1952, Enemy **, 0xC) != NULL) {
            M2C_FIELD(temp_r4_1952, s8 *, 9) = 1;
        }
        temp_r4_1963 = this->unk24;
        if (temp_r4_1963 != NULL) {
            M2C_FIELD(temp_r4_1963, s8 *, 8) = 1;
            M2C_FIELD(temp_r4_1963, Enemy **, 0xC) = arg0;
            M2C_FIELD(temp_r4_1963, s32 *, 4) = 2;
            if ((Enemy *) M2C_FIELD(temp_r4_1963, Enemy **, 0xC) != NULL) {
                M2C_FIELD(temp_r4_1963, s8 *, 9) = 1;
            }
        }
        temp_r3_1976 = this->unk2C;
        if (temp_r3_1976 != NULL) {
            ((EnemyGoal_MeleeAttackMode *) temp_r3_1976)->Init(arg0);
        }
        temp_r3_1982 = this->unk30;
        if (temp_r3_1982 != NULL) {
            ((EnemyGoal_RangeAttackMode *) temp_r3_1982)->Init(arg0);
        }
        temp_r3_1988 = this->unk34;
        if (temp_r3_1988 != NULL) {
            ((EnemyGoal_FlyingAttackMode *) temp_r3_1988)->Init(arg0);
        }
        ((EnemyGoal_MoveAwayFromHero *) this->unk38)->Init(arg0);
        ((EnemyGoal_DefensiveMode *) this->unk3C)->Init(arg0);
        temp_r4_2000 = this->unk40;
        M2C_FIELD(temp_r4_2000, s8 *, 8) = 1;
        M2C_FIELD(temp_r4_2000, Enemy **, 0xC) = arg0;
        M2C_FIELD(temp_r4_2000, s32 *, 4) = 0x21;
        if ((Enemy *) M2C_FIELD(temp_r4_2000, Enemy **, 0xC) != NULL) {
            M2C_FIELD(temp_r4_2000, s8 *, 9) = 1;
        }
        M2C_FIELD(temp_r4_2000, u8 *, 0x30) = (u8) (M2C_FIELD(temp_r4_2000, u8 *, 0x30) & ~0x10);
    }
}
#endif
