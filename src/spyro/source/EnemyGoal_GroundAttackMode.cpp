#include "spyro/source/EnemyGoal_GroundAttackMode.h"
#include "common/Source/Frustum.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKVector3.h"
#include "spyro/source/AITargetData.h"
#include "spyro/source/CharacterBreathFX.h"
#include "spyro/source/CharacterFireFX.h"
#include "spyro/source/Enemy.h"
#include "spyro/source/EnemyAttackPattern.h"
#include "spyro/source/EnemyDataTypes.h"
#include "spyro/source/SpawnerObject.h"
#include "spyro/source/TargetManager.h"
#include "unplaced_enums.h"
#include "common/Source/MKCollision.h"
#include "common/Source/StdMath.h"
#include <m2c_macros.h>

M2C_UNK free(void *);                               /* extern */
void *malloc(M2C_UNK);                              /* extern */
extern s32 gViewSeed;
extern M2C_UNK gb;

#if 0 // DRAFT: undefined identifier 'AddSubgoalToFront__21CompositeGoal'
void EnemyGoal_GroundAttackMode::AddGoal_MoveToAttackRange(EnemyAttack *arg0) {
    Enemy *temp_r3_35;
    Goal<Enemy> *temp_r3_56;
    Goal<Enemy> *temp_r7_89;
    f32 temp_f0_42;
    f32 temp_f31_54;
    f32 temp_f31_64;
    f32 var_f2_41;
    s32 temp_r4_18;
    s32 var_r6_82;
    u8 temp_r3_71;

    temp_r4_18 = arg0->unk38;
    if (!(temp_r4_18 & 0x30000)) {
        if (temp_r4_18 & 2) {
            AddSubgoalToFront__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk3C);
            M2C_FIELD(this->unk3C, AITargetData **, 0x10) = (AITargetData *) this->unk20;
        }
        if (this->unk20->GetDist() < arg0->unk14) {
            temp_r3_35 = this->unkC;
            var_f2_41 = arg0->unk14;
            temp_f0_42 = 1.5f * temp_r3_35->GetCollisionRadius();
            if (var_f2_41 > temp_f0_42) {

            } else {
                var_f2_41 = temp_f0_42;
            }
            temp_f31_54 = (0.25f * (arg0->unk18 - var_f2_41)) + var_f2_41;
            AddSubgoalToFront__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk38);
            temp_r3_56 = this->unk38;
            M2C_FIELD(temp_r3_56, AITargetData **, 0x10) = (AITargetData *) this->unk20;
            M2C_FIELD(temp_r3_56, f32 *, 0x14) = temp_f31_54;
            return;
        }
        temp_f31_64 = arg0->unk18;
        if (this->unk20->GetDist() > temp_f31_64) {
            if (arg0->unk38 & 2) {
                temp_r3_71 = M2C_FIELD(this->unk20, u8 *, 0x49);
                if ((temp_r3_71 >> 6U) & 1) {
                    if ((temp_r3_71 >> 5U) & 1) {
                        return;
                    }
                    goto block_13;
                }
            } else {
block_13:
                AddSubgoalToFront__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk34);
                var_r6_82 = 3;
                if ((u8) M2C_FIELD(this->unkC->unkA20, u8 *, 0x17D) != 0) {
                    var_r6_82 = 0;
                }
                temp_r7_89 = this->unk34;
                M2C_FIELD(temp_r7_89, AITargetData **, 0x10) = (AITargetData *) this->unk20;
                M2C_FIELD(temp_r7_89, f32 *, 0x18) = temp_f31_64;
                M2C_FIELD(temp_r7_89, u8 *, 0x30) = (u8) (M2C_FIELD(temp_r7_89, u8 *, 0x30) | 0x80);
                M2C_FIELD(temp_r7_89, s32 *, 0x20) = var_r6_82;
                M2C_FIELD(temp_r7_89, s32 *, 0x24) = 0;
                M2C_FIELD(temp_r7_89, s32 *, 0x28) = -1;
                M2C_FIELD(temp_r7_89, u8 *, 0x30) = (u8) (M2C_FIELD(temp_r7_89, u8 *, 0x30) | 0x40);
                M2C_FIELD(temp_r7_89, u8 *, 0x30) = (u8) (M2C_FIELD(temp_r7_89, u8 *, 0x30) | 0x20);
                M2C_FIELD(temp_r7_89, u8 *, 0x30) = (u8) (M2C_FIELD(temp_r7_89, u8 *, 0x30) & ~0x10);
            }
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'GetEnemyAttackSetting'
u8 EnemyGoal_GroundAttackMode::AddGoal_Attack(EnemyAttack *arg0) {
    Goal<Enemy> *temp_r3_191;
    Goal<Enemy> *temp_r3_258;
    Goal<Enemy> *temp_r4_244;
    Goal<Enemy> *temp_r5_160;
    Goal<Enemy> *temp_r5_210;
    f32 temp_f0_144;
    f32 temp_f0_147;
    f32 temp_f0_182;
    f32 temp_f1_139;
    f32 temp_f1_177;
    f32 var_f1_148;
    f32 var_f31_136;
    f32 var_f31_174;
    s32 temp_r5_130;

    temp_r5_130 = arg0->unk38;
    if (temp_r5_130 & 0x20000) {
        var_f31_136 = 1.0f;
        temp_f1_139 = this->unkC->unkA20->GetEnemyAttackSetting((EnemySettingType) 7, arg0);
        if (temp_f1_139 > 0.0f) {
            temp_f0_144 = this->unkC->unkAA0;
            if (temp_f0_144 > temp_f1_139) {
                temp_f0_147 = temp_f0_144 / temp_f1_139;
                var_f1_148 = 3.0f;
                if (var_f1_148 < temp_f0_147) {

                } else {
                    var_f1_148 = temp_f0_147;
                }
                var_f31_136 = 1.0f + var_f1_148;
            }
        }
        AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk58);
        temp_r5_160 = this->unk58;
        M2C_FIELD(temp_r5_160, AITargetData **, 0x10) = (AITargetData *) this->unk20;
        M2C_FIELD(temp_r5_160, s8 *, 0x1C) = 0;
        M2C_FIELD(temp_r5_160, s8 *, 0x1D) = 1;
        M2C_FIELD(temp_r5_160, f32 *, 0x18) = var_f31_136;
        goto block_26;
    }
    if (temp_r5_130 & 0x10000) {
        var_f31_174 = 1.0f;
        temp_f1_177 = this->unkC->unkA20->GetEnemyAttackSetting((EnemySettingType) 7, arg0);
        if (temp_f1_177 > 0.0f) {
            temp_f0_182 = this->unkC->unkAA0;
            if (temp_f0_182 > temp_f1_177) {
                var_f31_174 = 1.0f + (temp_f0_182 / temp_f1_177);
            }
        }
        AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk54);
        temp_r3_191 = this->unk54;
        M2C_FIELD(temp_r3_191, AITargetData **, 0x10) = (AITargetData *) this->unk20;
        M2C_FIELD(temp_r3_191, f32 *, 0x18) = var_f31_174;
        goto block_26;
    }
    if (temp_r5_130 & 0x40000) {
        AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk5C);
        AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk24);
        M2C_FIELD(this->unk5C, AITargetData **, 0x10) = (AITargetData *) this->unk20;
        temp_r5_210 = this->unk24;
        M2C_FIELD(temp_r5_210, s32 *, 0x10) = 0;
        M2C_FIELD(temp_r5_210, s32 *, 0x14) = 5;
        M2C_FIELD(temp_r5_210, s32 *, 0x18) = 0xE;
        M2C_FIELD(temp_r5_210, s32 *, 0x1C) = 0;
        M2C_FIELD(temp_r5_210, u8 *, 0x20) = (u8) (M2C_FIELD(temp_r5_210, u8 *, 0x20) & ~0x40);
        goto block_26;
    }
    if (temp_r5_130 & 0x2000) {
        AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk50);
        goto block_26;
    }
    if (temp_r5_130 & 2) {
        AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk60);
        goto block_26;
    }
    if (temp_r5_130 & 0x800) {
        AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk48);
        goto block_26;
    }
    if (temp_r5_130 & 0x40) {
        AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk44);
        temp_r4_244 = this->unk44;
        M2C_FIELD(temp_r4_244, s8 *, 0x14) = 1;
        M2C_FIELD(temp_r4_244, AITargetData **, 0x10) = (AITargetData *) this->unk20;
        AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk4C);
        goto block_26;
    }
    if (temp_r5_130 & 1) {
        AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk44);
        temp_r3_258 = this->unk44;
        M2C_FIELD(temp_r3_258, s8 *, 0x14) = 0;
        M2C_FIELD(temp_r3_258, AITargetData **, 0x10) = (AITargetData *) this->unk20;
block_26:
        this->unk6C |= 0x20;
        return 1U;
    }
    return 0U;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long *' to
u8 EnemyGoal_GroundAttackMode::AddGoal_StrafeIfObscuringCamera() {
    s32 sp8;
    Enemy *temp_r3_292;
    Goal<Enemy> *temp_r5_306;

    sp8 = 1;
    temp_r3_292 = this->unkC;
    if (temp_r3_292->IsObscuringCamera(&sp8) != 0) {
        AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk2C);
        temp_r5_306 = this->unk2C;
        M2C_FIELD(temp_r5_306, s8 *, 0x14) = (s8) (sp8 == -1);
        M2C_FIELD(temp_r5_306, f32 **, 0x10) = &this->unkC->unk838.unk28;
        return 1U;
    }
    return 0U;
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void EnemyGoal_GroundAttackMode::AddGoal_AttackIdleOrStrafe() {
    Enemy *temp_r3_352;
    Enemy *temp_r3_366;
    Enemy *temp_r3_380;
    Goal<Enemy> *temp_r3_430;
    u32 temp_r27_338;
    u8 var_r27_363;
    u8 var_r28_364;
    u8 var_r28_378;
    u8 var_r30_350;
    u8 var_r31_337;

    var_r31_337 = 0;
    temp_r27_338 = ((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1EU) & 1;
    if ((temp_r27_338 != 0) && (M2C_FIELD(this->unkC->__vptr, u8 (**)(AITargetData *), 0x13C)(this->unk20) != 0)) {
        var_r31_337 = 1;
    }
    var_r30_350 = 0;
    if (temp_r27_338 != 0) {
        temp_r3_352 = this->unkC;
        if (temp_r3_352->CanStrafeRight(this->unk20) != 0) {
            var_r30_350 = 1;
        }
    }
    var_r27_363 = 1;
    var_r28_364 = 0;
    if (var_r31_337 != 0) {
        temp_r3_366 = this->unkC;
        if (temp_r3_366->CanMoveAwayLeft() != 0) {
            var_r28_364 = 1;
        }
    }
    if (var_r28_364 == 0) {
        var_r28_378 = 0;
        if (var_r30_350 != 0) {
            temp_r3_380 = this->unkC;
            if (temp_r3_380->CanMoveAwayRight() != 0) {
                var_r28_378 = 1;
            }
        }
        if (var_r28_378 == 0) {
            var_r27_363 = 0;
        }
    }
    if ((((u8) M2C_FIELD(this->unkC, u8 *, 0xB08) >> 1U) & 1) || (var_r27_363 == 0) || (MKRand_Float(&gViewSeed, 0.0f, 1.0f) > M2C_FIELD(this->unkC->unkA20, f32 *, 0x150))) {
        AddGoal_AttackIdle();
    } else {
        if ((var_r31_337 != 0) && (var_r30_350 != 0)) {
            MKRand_Float(&gViewSeed, 0.0f, 1.0f);
            var_r31_337 = ((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1EU) & 1;
        }
        AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk2C);
        temp_r3_430 = this->unk2C;
        M2C_FIELD(temp_r3_430, u8 *, 0x14) = var_r31_337;
        M2C_FIELD(temp_r3_430, AITargetData **, 0x10) = (AITargetData *) this->unk20;
    }
    this->unkC->unkA08 = NULL;
}
#endif

#if 0 // DRAFT: undefined identifier 'AddSubgoal__21CompositeGoal'
void EnemyGoal_GroundAttackMode::AddGoal_AttackIdle() {
    Goal<Enemy> *temp_r5_454;

    AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk28);
    temp_r5_454 = this->unk28;
    M2C_FIELD(temp_r5_454, s32 *, 0x10) = 1;
    M2C_FIELD(temp_r5_454, s32 *, 0x14) = 0xA;
    this->unkC->unkA08 = NULL;
}
#endif

#if 0 // DRAFT: undefined identifier 'AddSubgoal__21CompositeGoal'
void EnemyGoal_GroundAttackMode::AddGoal_Taunt() {
    Goal<Enemy> *temp_r5_481;

    AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk24);
    temp_r5_481 = this->unk24;
    M2C_FIELD(temp_r5_481, AITargetData **, 0x10) = (AITargetData *) this->unk20;
    M2C_FIELD(temp_r5_481, s32 *, 0x14) = 1;
    M2C_FIELD(temp_r5_481, s32 *, 0x18) = 3;
    M2C_FIELD(temp_r5_481, u32 *, 0x1C) = (u32) this->unkC->unk680;
    M2C_FIELD(temp_r5_481, u8 *, 0x20) = (u8) (M2C_FIELD(temp_r5_481, u8 *, 0x20) | 0x40);
    this->unkC->TryChangeEnemyRegion();
}
#endif

#if 0 // DRAFT: undefined identifier 'AddSubgoal__21CompositeGoal'
u8 EnemyGoal_GroundAttackMode::AddGoal_OnlyRangeAttack(bool arg0) {
    if (M2C_FIELD(this->unkC, u8 *, 0xB00) & 1) {
        if (arg0 != 0) {
            this->unkC->SelectAttack(this->unk20->GetDist(), 2U, 0U, 1U);
            if ((CharacterFireFX *) this->unkC->unkA08 != NULL) {
                AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk3C);
                AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk60);
                M2C_FIELD(this->unk60, s8 *, 0x48) = 0;
                M2C_FIELD(this->unk3C, AITargetData **, 0x10) = (AITargetData *) this->unk20;
                return 1U;
            }
        }
        AddGoal_Taunt();
        return 1U;
    }
    return 0U;
}
#endif

#if 0 // DRAFT: function call 'GetCollisionRadius(Enemy *, double)' does not match
u8 EnemyGoal_GroundAttackMode::AddGoal_MoveToRegion() {
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
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp30;
    f32 sp20;
    f64 sp10;
    f64 sp8;
    Enemy *temp_r3_567;
    Enemy *temp_r3_581;
    Enemy *temp_r3_712;
    Enemy *temp_r4_588;
    Enemy *temp_r4_740;
    Goal<Enemy> *temp_r6_719;
    f32 temp_f0_597;
    f32 temp_f1_716;
    f32 temp_f31_589;
    f32 temp_f3_625;
    f32 var_f30_600;

    temp_r3_567 = this->unkC;
    if (((void *) temp_r3_567->unk638 != NULL) && (temp_r3_567->IsInsideEnemyRegion() == 0)) {
        spC8 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
        spD0 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
        spB8 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
        spC0 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
        temp_r3_581 = this->unkC;
        sp8 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
        sp10 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
        temp_r4_588 = this->unkC;
        temp_f31_589 = temp_r3_581->GetCollisionRadius(M2C_FIELD(&MKVector3::zero, f64 *, 0));
        temp_r4_588->unk750.unkA0.GetNearestPointOnBoundingRegion(*((MKVector3 *) &temp_r4_588->unk700), (MKVector3 *) &spC8, (MKVector3 *) &spB8);
        temp_f0_597 = 2.0f * temp_f31_589;
        if (150.0f > temp_f0_597) {
            var_f30_600 = 150.0f;
        } else {
            var_f30_600 = temp_f0_597;
        }
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
        spA8 = sp18;
        sp20 = (f32) spC0 * var_f30_600;
        spB0 = (f64) sp20;
        M2C_ERROR(/* unknown instruction: ps_add $f5, $f1, $f0 */);
        sp60 = 0.0f;
        temp_f3_625 = (f32) spD0 + (f32) spB0;
        sp58 = 0.0f;
        sp5C = 200.0f;
        spD0 = temp_f3_625;
        sp88 = (f64) sp58;
        sp90 = (f64) sp60;
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f5, $f0 */);
        sp98 = sp48;
        sp50 = temp_f3_625 + (f32) sp90;
        spA0 = (f64) sp50;
        if (MKCollision_GetGroundPoint(*((MKVector3 *) &sp98), 300.0f, &spD8, 0x04000000, 2, NULL, (MKCollisionMode) 7) != 0) {
            unkspCC = spD8.unk4;
            if ((f32) fabs(spD8.unk4 - this->unkC->unk588.unk0) > 200.0f) {
                return 0U;
            }
            sp3C = temp_f31_589;
            sp38 = 0.0f;
            sp40 = 0.0f;
            sp68 = (f64) sp38;
            sp70 = (f64) sp40;
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            sp78 = sp28;
            sp30 = spD0 + (f32) sp70;
            sp80 = (f64) sp30;
            if (MKCollision_SphereCollide(*((MKVector3 *) &sp78), temp_f31_589, NULL, 0, (MKCollisionMode) 7, 0x04000000) != 0) {
                return 0U;
            }
            this->unkC->unk870.unk40.Set(*((MKVector3 *) &spC8), 0U);
            this->unkC->unk870.unk40.SetInsideRegion(1U);
            AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk34);
            temp_r3_712 = this->unkC;
            temp_f1_716 = temp_r3_712->GetCollisionRadius();
            temp_r6_719 = this->unk34;
            M2C_FIELD(temp_r6_719, TargetContext **, 0x10) = &this->unkC->unk870.unk40;
            M2C_FIELD(temp_r6_719, f32 *, 0x18) = temp_f1_716;
            M2C_FIELD(temp_r6_719, u8 *, 0x30) = (u8) (M2C_FIELD(temp_r6_719, u8 *, 0x30) | 0x80);
            M2C_FIELD(temp_r6_719, s32 *, 0x20) = 0;
            M2C_FIELD(temp_r6_719, s32 *, 0x24) = 0;
            M2C_FIELD(temp_r6_719, s32 *, 0x28) = -1;
            M2C_FIELD(temp_r6_719, u8 *, 0x30) = (u8) (M2C_FIELD(temp_r6_719, u8 *, 0x30) & ~0x40);
            M2C_FIELD(temp_r6_719, u8 *, 0x30) = (u8) (M2C_FIELD(temp_r6_719, u8 *, 0x30) | 0x20);
            M2C_FIELD(temp_r6_719, u8 *, 0x30) = (u8) (M2C_FIELD(temp_r6_719, u8 *, 0x30) & ~0x10);
            temp_r4_740 = this->unkC;
            temp_r4_740->unk870.unk40.Update(*((MKVector3 *) &temp_r4_740->unk588));
            return 1U;
        }
        return 0U;
    }
    return 0U;
}
#endif

#if 0 // DRAFT: undefined identifier 'AddSubgoal__21CompositeGoal'
u8 EnemyGoal_GroundAttackMode::AddGoal_Summon() {
    Enemy *temp_r3_787;
    Enemy *temp_r4_768;
    Goal<Enemy> *temp_r4_795;
    Goal<Enemy> *temp_r6_805;
    SpawnerObject *temp_r3_775;
    void *temp_r3_769;

    temp_r4_768 = this->unkC;
    temp_r3_769 = temp_r4_768->unkA2C;
    if ((temp_r3_769 != NULL) && (M2C_FIELD(temp_r3_769, s32 *, 4) & 0x40)) {
        temp_r3_775 = temp_r4_768->unkA4C;
        if (temp_r3_775 != NULL) {
            temp_r3_775->GetNumberActive();
            if ((s32) M2C_ERROR(/* Read from unset register $r3 */) <= 0) {
                AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk3C);
                M2C_FIELD(this->unk3C, AITargetData **, 0x10) = (AITargetData *) this->unk20;
                temp_r3_787 = this->unkC;
                temp_r3_787->OnSummon();
                this->unkC->unkA4C->SetDefaults();
                temp_r4_795 = this->unk40;
                if (temp_r4_795 != NULL) {
                    AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) temp_r4_795);
                } else {
                    AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk24);
                    temp_r6_805 = this->unk24;
                    M2C_FIELD(temp_r6_805, AITargetData **, 0x10) = (AITargetData *) this->unk20;
                    M2C_FIELD(temp_r6_805, s32 *, 0x14) = 1;
                    M2C_FIELD(temp_r6_805, s32 *, 0x18) = 0xB;
                    M2C_FIELD(temp_r6_805, s32 *, 0x1C) = 0;
                    M2C_FIELD(temp_r6_805, u8 *, 0x20) = (u8) (M2C_FIELD(temp_r6_805, u8 *, 0x20) & ~0x40);
                }
                return 1U;
            }
        }
    }
    return 0U;
}
#endif

void EnemyGoal_GroundAttackMode::SetSummonGoal(Goal<Enemy> *arg0) {
    this->unk40 = (Goal<Enemy> *) arg0;
}

void EnemyGoal_GroundAttackMode::SetParams(AITargetData *arg0, bool arg1, EAPItem *arg2) {
    this->unk20 = arg0;
    this->unk6C = (this->unk6C & ~0x80) | ((arg1 << 7) & 0x80);
    this->unk64 = arg2;
}

void EnemyGoal_GroundAttackMode::Reset() {
    this->unk8 = 1;
    RemoveAllSubgoals();
    this->unk20 = NULL;
    this->unk6C &= ~0x80;
    this->unk6C &= ~0x40;
    this->unk6C &= ~0x20;
    this->unk68 = 0.0f;
    this->unk64 = NULL;
}

void EnemyGoal_GroundAttackMode::Terminate() {
    this->unk8 = 1;
    RemoveAllSubgoals();
}

#if 0 // DRAFT: illegal implicit conversion from 'void' to
u8 EnemyGoal_GroundAttackMode::Update() {
    AITargetData *temp_r3_907;
    Enemy *temp_r4_923;
    u8 var_r31_911;
    void *temp_r3_924;

    ActivateIfInactive();
    this->unk8 = UpdateSubgoals();
    temp_r3_907 = this->unk20;
    if (temp_r3_907 != NULL) {
        var_r31_911 = 0;
        if (((u8) M2C_FIELD(temp_r3_907, u8 *, 0x48) == 2) || (temp_r3_907->unk40.Get() != NULL)) {
            var_r31_911 = 1;
        }
        if (var_r31_911 != 0) {
            temp_r4_923 = this->unkC;
            temp_r3_924 = temp_r4_923->unkA44;
            if (((u32) M2C_FIELD(temp_r3_924, u32 *, 8) != 0U) && (temp_r3_924->ReEvaluate(temp_r4_923, this->unk20) == 0)) {
                this->unk8 = 2;
                M2C_FIELD(this->unkC->unkA44, s32 *, 8) = 0;
            }
            if ((u8) this->unk8 == 2) {
                this->unk8 = 1;
            }
            ReactivateIfFailed();
            ActivateIfInactive();
        }
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long' to
void EnemyGoal_GroundAttackMode::Activate() {
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp10;
    AITargetData *temp_r3_977;
    EAPItem *temp_r0_1076;
    Enemy *temp_r3_1007;
    Enemy *temp_r3_998;
    Enemy *temp_r4_1061;
    Enemy *temp_r4_1149;
    Enemy *temp_r5_1049;
    Frustum *temp_r31_1004;
    f32 temp_f1_1032;
    s32 temp_r31_1045;
    s32 temp_r3_1152;
    u8 var_r31_981;
    void *temp_r3_1062;
    void *temp_r3_1072;
    void *temp_r4_1014;
    void *temp_r4_1085;
    void *temp_r4_1090;
    void *temp_r4_1140;
    void *temp_r4_1163;

    this->unk8 = 0;
    this->unk6C &= ~0x40;
    this->unk6C &= ~0x20;
    RemoveAllSubgoals();
    temp_r3_977 = this->unk20;
    if (temp_r3_977 != NULL) {
        var_r31_981 = 0;
        if (((u8) M2C_FIELD(temp_r3_977, u8 *, 0x48) == 2) || (temp_r3_977->unk40.Get() != NULL)) {
            var_r31_981 = 1;
        }
        if (var_r31_981 == 0) {
            goto block_5;
        }
        temp_r3_998 = this->unkC;
        temp_r31_1004 = M2C_FIELD(&gb, s32 *, 0x3B8) + 0xB0;
        temp_r3_1007 = this->unkC;
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r4, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
        temp_r4_1014 = temp_r3_1007->unk8;
        sp20 = temp_r3_1007->unkD8 * temp_r3_998->GetCollisionRadius(M2C_FIELD(&gb, s32 *, 0x3B8));
        sp28 = sp18;
        sp38 = M2C_FIELD(temp_r4_1014, f64 *, 0x30);
        sp30 = (f64) sp20;
        sp40 = M2C_FIELD(temp_r4_1014, f64 *, 0x38);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        temp_f1_1032 = (f32) sp40 + (f32) sp30;
        sp48 = sp8;
        sp10 = temp_f1_1032;
        sp50 = (f64) sp10;
        temp_r31_1045 = temp_r31_1004->IsVisible(*((MKVector3 *) &sp48), temp_r3_1007->GetCollisionRadius(temp_r4_1014, temp_f1_1032, (f32) sp40, sp18));
        temp_r5_1049 = this->unkC;
        if (M2C_FIELD(this->unk20->unk40.Get()->__vptr, u8 (**)(M2C_UNK *, u8 *), 0x28)(&temp_r5_1049->unk588, &temp_r5_1049->unk6C0.unk38) != 0) {
            M2C_FIELD(this->unkC, s8 *, 0x6F8) = 1;
        }
        temp_r4_1061 = this->unkC;
        temp_r3_1062 = temp_r4_1061->unkA44;
        if (temp_r3_1062 != NULL) {
            if (((u8) M2C_FIELD(temp_r3_1062, u8 *, 0x10) >> 6U) & 1) {
                temp_r4_1061->unkA7C = 0.0f;
            }
            temp_r3_1072 = this->unkC->unkA44;
            M2C_FIELD(temp_r3_1072, u8 *, 0x10) = (u8) ((M2C_FIELD(temp_r3_1072, u8 *, 0x10) & ~0x20) | ((temp_r31_1045 << 5) & 0x20));
            temp_r0_1076 = this->unk64;
            if (temp_r0_1076 != NULL) {
                M2C_FIELD(this->unkC->unkA44, EAPItem **, 8) = temp_r0_1076;
                temp_r4_1085 = this->unkC->unkA44;
                M2C_FIELD(temp_r4_1085, u8 *, 0x10) = (u8) (M2C_FIELD(temp_r4_1085, u8 *, 0x10) & ~0x80);
                temp_r4_1090 = this->unkC->unkA44;
                M2C_FIELD(temp_r4_1090, u8 *, 0x10) = (u8) (M2C_FIELD(temp_r4_1090, u8 *, 0x10) & ~0x40);
                this->unkC->unkA08 = (CharacterFireFX *) this->unk64->unk0;
                this->unkC->unkA0C = (CharacterBreathFX *) this->unk64->unk0;
                AddGoal_Attack(this->unk64->unk0);
                this->unk64 = NULL;
                return;
            }
            goto block_13;
        }
block_13:
        if ((AddGoal_Summon() == 0) && (AddGoal_MoveToRegion() == 0) && (AddGoal_OnlyRangeAttack((u8) temp_r31_1045) == 0) && (AddGoal_StrafeIfObscuringCamera() == 0)) {
            M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
            if ((M2C_FIELD(&gb, f32 *, 0x30C) != this->unkC->unkA7C) && ((u8) temp_r31_1045 != 0)) {
                AddGoal_AttackIdleOrStrafe();
            }
            temp_r4_1140 = this->unkC->unkA44;
            if (temp_r4_1140 != NULL) {
                M2C_FIELD(temp_r4_1140, u8 *, 0x10) = (u8) (M2C_FIELD(temp_r4_1140, u8 *, 0x10) & ~0x40);
                temp_r4_1149 = this->unkC;
                temp_r3_1152 = temp_r4_1149->unkA44->Evaluate(temp_r4_1149, this->unk20, NULL, 0);
                if ((temp_r3_1152 != 0) && (AddGoal_Attack(*temp_r3_1152) != 0)) {
                    temp_r4_1163 = this->unkC->unkA44;
                    M2C_FIELD(temp_r4_1163, u8 *, 0x10) = (u8) (M2C_FIELD(temp_r4_1163, u8 *, 0x10) & ~0x80);
                    M2C_FIELD(this->unkC->unkA44, s32 *, 8) = temp_r3_1152;
                    this->unkC->unkA08 = (CharacterFireFX *) *temp_r3_1152;
                    this->unkC->unkA0C = (CharacterBreathFX *) *temp_r3_1152;
                    AddGoal_MoveToAttackRange(*temp_r3_1152);
                    return;
                }
            }
            AddGoal_Taunt();
        }
    } else {
block_5:
        this->unk8 = 2;
    }
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void EnemyGoal_GroundAttackMode::Deinit() {
    Goal<Enemy> *temp_r3_1200;
    Goal<Enemy> *temp_r3_1210;
    Goal<Enemy> *temp_r3_1220;
    Goal<Enemy> *temp_r3_1240;
    Goal<Enemy> *temp_r3_1250;
    Goal<Enemy> *temp_r3_1260;
    Goal<Enemy> *temp_r3_1270;
    Goal<Enemy> *temp_r3_1280;
    Goal<Enemy> *temp_r3_1290;
    Goal<Enemy> *temp_r3_1300;
    Goal<Enemy> *temp_r3_1310;
    Goal<Enemy> *temp_r3_1320;
    Goal<Enemy> *temp_r3_1330;
    Goal<Enemy> *temp_r3_1340;
    MKHeap *temp_r3_1353;
    void **temp_r3_1230;
    void *temp_r30_1350;

    temp_r3_1200 = this->unk24;
    if (temp_r3_1200 != NULL) {
        M2C_FIELD(temp_r3_1200->__vptr, M2C_UNK (**)(), 0xC)();
        operator delete(this->unk24);
    }
    temp_r3_1210 = this->unk28;
    if (temp_r3_1210 != NULL) {
        M2C_FIELD(temp_r3_1210->__vptr, M2C_UNK (**)(), 0xC)();
        operator delete(this->unk28);
    }
    temp_r3_1220 = this->unk2C;
    if (temp_r3_1220 != NULL) {
        M2C_FIELD(temp_r3_1220->__vptr, M2C_UNK (**)(), 0xC)();
        operator delete(this->unk2C);
    }
    temp_r3_1230 = this->unk30;
    if (temp_r3_1230 != NULL) {
        M2C_FIELD(*temp_r3_1230, M2C_UNK (**)(), 0xC)();
        operator delete(this->unk30);
    }
    temp_r3_1240 = this->unk34;
    if (temp_r3_1240 != NULL) {
        M2C_FIELD(temp_r3_1240->__vptr, M2C_UNK (**)(), 0xC)();
        operator delete(this->unk34);
    }
    temp_r3_1250 = this->unk38;
    if (temp_r3_1250 != NULL) {
        M2C_FIELD(temp_r3_1250->__vptr, M2C_UNK (**)(), 0xC)();
        operator delete(this->unk38);
    }
    temp_r3_1260 = this->unk3C;
    if (temp_r3_1260 != NULL) {
        M2C_FIELD(temp_r3_1260->__vptr, M2C_UNK (**)(), 0xC)();
        operator delete(this->unk3C);
    }
    temp_r3_1270 = this->unk44;
    if (temp_r3_1270 != NULL) {
        M2C_FIELD(temp_r3_1270->__vptr, M2C_UNK (**)(), 0xC)();
        operator delete(this->unk44);
    }
    temp_r3_1280 = this->unk48;
    if (temp_r3_1280 != NULL) {
        M2C_FIELD(temp_r3_1280->__vptr, M2C_UNK (**)(), 0xC)();
        operator delete(this->unk48);
    }
    temp_r3_1290 = this->unk4C;
    if (temp_r3_1290 != NULL) {
        M2C_FIELD(temp_r3_1290->__vptr, M2C_UNK (**)(), 0xC)();
        operator delete(this->unk4C);
    }
    temp_r3_1300 = this->unk50;
    if (temp_r3_1300 != NULL) {
        M2C_FIELD(temp_r3_1300->__vptr, M2C_UNK (**)(), 0xC)();
        operator delete(this->unk50);
    }
    temp_r3_1310 = this->unk54;
    if (temp_r3_1310 != NULL) {
        M2C_FIELD(temp_r3_1310->__vptr, M2C_UNK (**)(), 0xC)();
        operator delete(this->unk54);
    }
    temp_r3_1320 = this->unk58;
    if (temp_r3_1320 != NULL) {
        M2C_FIELD(temp_r3_1320->__vptr, M2C_UNK (**)(), 0xC)();
        operator delete(this->unk58);
    }
    temp_r3_1330 = this->unk5C;
    if (temp_r3_1330 != NULL) {
        M2C_FIELD(temp_r3_1330->__vptr, M2C_UNK (**)(), 0xC)();
        operator delete(this->unk5C);
    }
    temp_r3_1340 = this->unk60;
    if (temp_r3_1340 != NULL) {
        M2C_FIELD(temp_r3_1340->__vptr, M2C_UNK (**)(), 0xC)();
        operator delete(this->unk60);
    }
    temp_r30_1350 = this->unk1C;
    if (temp_r30_1350 != NULL) {
        temp_r3_1353 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_1353 != NULL) {
            ((MKHeap *) (temp_r3_1353->Current()))->Free(temp_r30_1350, NULL, 0);
        } else {
            free(temp_r30_1350);
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
void EnemyGoal_GroundAttackMode::Init(Enemy *arg0) {
    Goal<Enemy> *temp_r3_1927;
    Goal<Enemy> *temp_r4_1813;
    Goal<Enemy> *temp_r4_1826;
    Goal<Enemy> *temp_r4_1838;
    Goal<Enemy> *temp_r4_1857;
    Goal<Enemy> *temp_r4_1875;
    Goal<Enemy> *temp_r4_1888;
    Goal<Enemy> *temp_r4_1901;
    Goal<Enemy> *temp_r4_1914;
    Goal<Enemy> *temp_r4_1933;
    Goal<Enemy> *temp_r4_1946;
    Goal<Enemy> *temp_r4_1959;
    Goal<Enemy> *temp_r4_1972;
    Goal<Enemy> *temp_r4_1985;
    MKHeap *temp_r3_1783;
    void **temp_r3_1851;
    void *var_r3_1790;

    if ((arg0 != NULL) && ((u8) this->unk9 == 0)) {
        this->unk24 = NULL;
        this->unk28 = NULL;
        this->unk2C = NULL;
        this->unk30 = NULL;
        this->unk34 = NULL;
        this->unk40 = NULL;
        this->unk44 = NULL;
        this->unk48 = NULL;
        this->unk4C = NULL;
        this->unk50 = NULL;
        this->unk54 = NULL;
        this->unk58 = NULL;
        this->unk5C = NULL;
        this->unk60 = NULL;
        this->unk38 = NULL;
        this->unk3C = NULL;
        operator new(0x24U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk24 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x1CU, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk28 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x18U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk2C = M2C_ERROR(/* Read from unset register $r3 */);
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
        this->unk30 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x34U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk34 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x1CU, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk38 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x14U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk3C = M2C_ERROR(/* Read from unset register $r3 */);
        if ((s32) M2C_FIELD(arg0->unkA20, s32 *, 0x214) > 0) {
            operator new(0x18U, NULL, 0);
            if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
                *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
                *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
            }
            this->unk44 = M2C_ERROR(/* Read from unset register $r3 */);
        }
        if ((s32) M2C_FIELD(arg0->unkA20, s32 *, 0x21C) > 0) {
            operator new(0x50U, NULL, 0);
            if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
                *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
                *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
            }
            this->unk60 = M2C_ERROR(/* Read from unset register $r3 */);
        }
        if (arg0->unkA20->HasAttack(0x801U, 0) != 0) {
            operator new(0x14U, NULL, 0);
            if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
                *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
                *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
            }
            this->unk48 = M2C_ERROR(/* Read from unset register $r3 */);
        }
        if (arg0->unkA20->HasAttack(0x40U, 0) != 0) {
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
            this->unk4C = M2C_ERROR(/* Read from unset register $r3 */);
        }
        if (arg0->unkA20->HasAttack(0x2000U, 0) != 0) {
            operator new(0x18U, NULL, 0);
            if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
                *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
                *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
            }
            this->unk50 = M2C_ERROR(/* Read from unset register $r3 */);
        }
        if (arg0->unkA20->HasAttack(0x10000U, 0) != 0) {
            operator new(0x1CU, NULL, 0);
            if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
                *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
                *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
            }
            this->unk54 = M2C_ERROR(/* Read from unset register $r3 */);
        }
        if (arg0->unkA20->HasAttack(0x20000U, 0) != 0) {
            operator new(0x20U, NULL, 0);
            if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
                *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
                *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
            }
            this->unk58 = M2C_ERROR(/* Read from unset register $r3 */);
        }
        if (arg0->unkA20->HasAttack(0x40000U, 0) != 0) {
            operator new(0x18U, NULL, 0);
            if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
                *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
                *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
            }
            this->unk5C = M2C_ERROR(/* Read from unset register $r3 */);
        }
    }
    if ((u8) this->unk9 == 0) {
        temp_r3_1783 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_1783 != NULL) {
            var_r3_1790 = ((MKHeap *) (temp_r3_1783->Current()))->Alloc(0x10, NULL, 0);
        } else {
            var_r3_1790 = malloc(0x10);
        }
        this->unk1C = var_r3_1790;
        this->unk10 = 4;
    }
    this->unk8 = 1;
    this->unkC = arg0;
    this->unk4 = 0x58;
    if ((Enemy *) this->unkC != NULL) {
        this->unk9 = 1;
    }
    if ((u8) this->unk9 != 0) {
        temp_r4_1813 = this->unk24;
        if (temp_r4_1813 != NULL) {
            M2C_FIELD(temp_r4_1813, s8 *, 8) = 1;
            M2C_FIELD(temp_r4_1813, Enemy **, 0xC) = arg0;
            M2C_FIELD(temp_r4_1813, s32 *, 4) = 0;
            if ((Enemy *) M2C_FIELD(temp_r4_1813, Enemy **, 0xC) != NULL) {
                M2C_FIELD(temp_r4_1813, s8 *, 9) = 1;
            }
        }
        temp_r4_1826 = this->unk28;
        if (temp_r4_1826 != NULL) {
            M2C_FIELD(temp_r4_1826, s8 *, 8) = 1;
            M2C_FIELD(temp_r4_1826, Enemy **, 0xC) = arg0;
            M2C_FIELD(temp_r4_1826, s32 *, 4) = 1;
            if ((Enemy *) M2C_FIELD(temp_r4_1826, Enemy **, 0xC) != NULL) {
                M2C_FIELD(temp_r4_1826, s8 *, 9) = 1;
            }
        }
        temp_r4_1838 = this->unk2C;
        if (temp_r4_1838 != NULL) {
            M2C_FIELD(temp_r4_1838, s8 *, 8) = 1;
            M2C_FIELD(temp_r4_1838, Enemy **, 0xC) = arg0;
            M2C_FIELD(temp_r4_1838, s32 *, 4) = 0x20;
            if ((Enemy *) M2C_FIELD(temp_r4_1838, Enemy **, 0xC) != NULL) {
                M2C_FIELD(temp_r4_1838, s8 *, 9) = 1;
            }
        }
        temp_r3_1851 = this->unk30;
        if (temp_r3_1851 != NULL) {
            temp_r3_1851->Init(arg0);
        }
        temp_r4_1857 = this->unk34;
        if (temp_r4_1857 != NULL) {
            M2C_FIELD(temp_r4_1857, s8 *, 8) = 1;
            M2C_FIELD(temp_r4_1857, Enemy **, 0xC) = arg0;
            M2C_FIELD(temp_r4_1857, s32 *, 4) = 0x21;
            if ((Enemy *) M2C_FIELD(temp_r4_1857, Enemy **, 0xC) != NULL) {
                M2C_FIELD(temp_r4_1857, s8 *, 9) = 1;
            }
            M2C_FIELD(temp_r4_1857, u8 *, 0x30) = (u8) (M2C_FIELD(temp_r4_1857, u8 *, 0x30) & ~0x10);
        }
        temp_r4_1875 = this->unk38;
        if (temp_r4_1875 != NULL) {
            M2C_FIELD(temp_r4_1875, s8 *, 8) = 1;
            M2C_FIELD(temp_r4_1875, Enemy **, 0xC) = arg0;
            M2C_FIELD(temp_r4_1875, s32 *, 4) = 0x1F;
            if ((Enemy *) M2C_FIELD(temp_r4_1875, Enemy **, 0xC) != NULL) {
                M2C_FIELD(temp_r4_1875, s8 *, 9) = 1;
            }
        }
        temp_r4_1888 = this->unk3C;
        if (temp_r4_1888 != NULL) {
            M2C_FIELD(temp_r4_1888, s8 *, 8) = 1;
            M2C_FIELD(temp_r4_1888, Enemy **, 0xC) = arg0;
            M2C_FIELD(temp_r4_1888, s32 *, 4) = 0x27;
            if ((Enemy *) M2C_FIELD(temp_r4_1888, Enemy **, 0xC) != NULL) {
                M2C_FIELD(temp_r4_1888, s8 *, 9) = 1;
            }
        }
        temp_r4_1901 = this->unk44;
        if (temp_r4_1901 != NULL) {
            M2C_FIELD(temp_r4_1901, s8 *, 8) = 1;
            M2C_FIELD(temp_r4_1901, Enemy **, 0xC) = arg0;
            M2C_FIELD(temp_r4_1901, s32 *, 4) = 0x3A;
            if ((Enemy *) M2C_FIELD(temp_r4_1901, Enemy **, 0xC) != NULL) {
                M2C_FIELD(temp_r4_1901, s8 *, 9) = 1;
            }
        }
        temp_r4_1914 = this->unk48;
        if (temp_r4_1914 != NULL) {
            M2C_FIELD(temp_r4_1914, s8 *, 8) = 1;
            M2C_FIELD(temp_r4_1914, Enemy **, 0xC) = arg0;
            M2C_FIELD(temp_r4_1914, s32 *, 4) = 0x3A;
            if ((Enemy *) M2C_FIELD(temp_r4_1914, Enemy **, 0xC) != NULL) {
                M2C_FIELD(temp_r4_1914, s8 *, 9) = 1;
            }
        }
        temp_r3_1927 = this->unk4C;
        if (temp_r3_1927 != NULL) {
            temp_r3_1927->Init(arg0);
        }
        temp_r4_1933 = this->unk50;
        if (temp_r4_1933 != NULL) {
            M2C_FIELD(temp_r4_1933, s8 *, 8) = 1;
            M2C_FIELD(temp_r4_1933, Enemy **, 0xC) = arg0;
            M2C_FIELD(temp_r4_1933, s32 *, 4) = 0x40;
            if ((Enemy *) M2C_FIELD(temp_r4_1933, Enemy **, 0xC) != NULL) {
                M2C_FIELD(temp_r4_1933, s8 *, 9) = 1;
            }
        }
        temp_r4_1946 = this->unk54;
        if (temp_r4_1946 != NULL) {
            M2C_FIELD(temp_r4_1946, s8 *, 8) = 1;
            M2C_FIELD(temp_r4_1946, Enemy **, 0xC) = arg0;
            M2C_FIELD(temp_r4_1946, s32 *, 4) = 0x50;
            if ((Enemy *) M2C_FIELD(temp_r4_1946, Enemy **, 0xC) != NULL) {
                M2C_FIELD(temp_r4_1946, s8 *, 9) = 1;
            }
        }
        temp_r4_1959 = this->unk58;
        if (temp_r4_1959 != NULL) {
            M2C_FIELD(temp_r4_1959, s8 *, 8) = 1;
            M2C_FIELD(temp_r4_1959, Enemy **, 0xC) = arg0;
            M2C_FIELD(temp_r4_1959, s32 *, 4) = 0x51;
            if ((Enemy *) M2C_FIELD(temp_r4_1959, Enemy **, 0xC) != NULL) {
                M2C_FIELD(temp_r4_1959, s8 *, 9) = 1;
            }
        }
        temp_r4_1972 = this->unk5C;
        if (temp_r4_1972 != NULL) {
            M2C_FIELD(temp_r4_1972, s8 *, 8) = 1;
            M2C_FIELD(temp_r4_1972, Enemy **, 0xC) = arg0;
            M2C_FIELD(temp_r4_1972, s32 *, 4) = 0x52;
            if ((Enemy *) M2C_FIELD(temp_r4_1972, Enemy **, 0xC) != NULL) {
                M2C_FIELD(temp_r4_1972, s8 *, 9) = 1;
            }
        }
        temp_r4_1985 = this->unk60;
        if (temp_r4_1985 != NULL) {
            M2C_FIELD(temp_r4_1985, s8 *, 8) = 1;
            M2C_FIELD(temp_r4_1985, Enemy **, 0xC) = arg0;
            M2C_FIELD(temp_r4_1985, s32 *, 4) = 0x3B;
            if ((Enemy *) M2C_FIELD(temp_r4_1985, Enemy **, 0xC) != NULL) {
                M2C_FIELD(temp_r4_1985, s8 *, 9) = 1;
            }
            M2C_FIELD(temp_r4_1985, f32 *, 0x28) = 0.0f;
            M2C_FIELD(temp_r4_1985, f32 *, 0x2C) = 0.0f;
            M2C_FIELD(temp_r4_1985, f32 *, 0x30) = 0.0f;
            M2C_FIELD(temp_r4_1985, f32 *, 0x18) = 0.0f;
            M2C_FIELD(temp_r4_1985, f32 *, 0x1C) = 0.0f;
            M2C_FIELD(temp_r4_1985, f32 *, 0x20) = 0.0f;
        }
    }
}
#endif
