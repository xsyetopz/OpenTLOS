#include "spyro/source/FireTier2Goal_Think.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKVector3.h"
#include "spyro/source/AITargetData.h"
#include "spyro/source/Enemies_Fire.h"
#include "spyro/source/Enemy.h"
#include "spyro/source/EnemyDataTypes.h"
#include "spyro/source/EnemyGoal_Think.h"
#include "spyro/source/KDPath.h"
#include "spyro/source/TargetManager.h"
#include "unplaced_templates.h"
#include "common/Source/MKCollision.h"
#include "spyro/source/KDMath.h"
#include "spyro/source/KDSound.h"
#include <m2c_macros.h>

M2C_UNK free(void *);                               /* extern */
void *malloc(M2C_UNK);                              /* extern */
extern s32 GS_MWHit1;

#if 0 // DRAFT: pointer/array required
u8 FireTier2Goal_Think::Update() {
    f64 sp18;
    f64 sp10;
    s32 sp8;
    s32 temp_r3_38;
    u8 temp_r30_39;
    u8 var_r31_35;
    void *temp_r6_40;

    var_r31_35 = 0;
    sp8 = 0;
    temp_r3_38 = this->unkC;
    temp_r30_39 = this->unk7C;
    temp_r6_40 = M2C_FIELD(temp_r3_38, void **, 8);
    sp10 = M2C_FIELD(temp_r6_40, f64 *, 0x30);
    sp18 = M2C_FIELD(temp_r6_40, f64 *, 0x38);
    if ((temp_r3_38->InWaterVolume(*((MKVector3 *) &sp10), &sp8) != 0) && (sp8 & 1)) {
        var_r31_35 = 1;
    }
    this->unk7C = var_r31_35;
    if (((u8) this->unk7C != 0) && (temp_r30_39 == 0)) {
        KDSound_Play3d(GS_MWHit1, M2C_FIELD(this->unkC, s32 *, 8) + 0x30, 0U, -1, 0.0f, 0U);
    }
    EnemyGoal_Think::Update();
}
#endif

#if 0 // DRAFT: undefined identifier 'AddSubgoal__21CompositeGoal'
void FireTier2Goal_Think::Arbitrate() {
    EnemyDamageFeedback sp8;
    f32 var_f31_317;
    s32 temp_r3_103;
    s32 temp_r3_115;
    s32 temp_r3_147;
    s32 temp_r3_172;
    s32 temp_r3_200;
    s32 temp_r3_281;
    s32 temp_r3_336;
    s32 temp_r3_344;
    s32 temp_r3_357;
    s32 temp_r4_217;
    s32 temp_r4_224;
    s32 temp_r4_312;
    s32 temp_r5_87;
    u8 temp_r30_134;
    u8 temp_r3_111;
    u8 var_r30_173;
    u8 var_r30_205;
    u8 var_r30_324;

    temp_r5_87 = this->unkC;
    if (!(((u8) M2C_FIELD(temp_r5_87, u8 *, 0xB09) >> 7U) & 1)) {
        AddGoal_Respawn();
        return;
    }
    if (((u8) M2C_FIELD(this->unk74, u8 *, 0xB10) >> 7U) & 1) {
        RemoveAllSubgoals();
        AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk78);
        temp_r3_103 = this->unkC;
        M2C_FIELD(M2C_FIELD(temp_r3_103, void **, 0x44), M2C_UNK (**)(s32), 0x58)(temp_r3_103);
        return;
    }
    temp_r3_111 = temp_r5_87->IsInvulnerable();
    if (temp_r3_111 != 0) {
        temp_r3_115 = this->unkC;
        M2C_FIELD(temp_r3_115, s32 *, 0x9D8) = 0;
        M2C_FIELD(temp_r3_115, s32 *, 0x9D4) = 0;
    }
    if ((this->unkC->WasHit() != 0) && (temp_r3_111 == 0)) {
        temp_r30_134 = IsActive(0x29);
        sp8.Init();
        this->unkC->TakeDamage(&sp8, temp_r30_134);
        if (IsFollowingSpawnPath() != 0) {
            StopFollowingSpawnPath();
        }
        temp_r3_147 = this->unkC;
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if (M2C_FIELD(temp_r3_147, f32 *, 0xAC8) == 0.0f) {
            AddGoal_Death(&sp8);
            return;
        }
        if ((sp8.unk28 != 0xE) && (temp_r30_134 == 0)) {
            if (!(((u8) M2C_FIELD(temp_r3_147, u8 *, 0xB08) >> 6U) & 1) && (M2C_FIELD(M2C_FIELD(temp_r3_147, void **, 0x44), u8 (**)(), 0x190)() != 0)) {
                temp_r3_172 = this->unkC;
                var_r30_173 = 0;
                if (((u8) M2C_FIELD(temp_r3_172, u8 *, 0x8B8) == 2) || (((TargetContext *) (temp_r3_172 + 0x8B0))->Get() != NULL)) {
                    var_r30_173 = 1;
                }
                if ((var_r30_173 != 0) && (((AITargetData *) (this->unkC + 0x870))->GetDistSq() > 1000000.0f)) {
                    AddGoal_Panic();
                }
            }
            AddGoal_Hit(&sp8);
            return;
        }
        goto block_23;
    }
block_23:
    temp_r3_200 = this->unkC;
    if (((u8) M2C_FIELD(temp_r3_200, u8 *, 0xB0A) >> 7U) & 1) {
        var_r30_205 = 0;
        if (((u8) M2C_FIELD(temp_r3_200, u8 *, 0x8B8) == 2) || (((TargetContext *) (temp_r3_200 + 0x8B0))->Get() != NULL)) {
            var_r30_205 = 1;
        }
        if (var_r30_205 != 0) {
            temp_r4_217 = this->unkC;
            M2C_FIELD(temp_r4_217, u8 *, 0xB0A) = (u8) (M2C_FIELD(temp_r4_217, u8 *, 0xB0A) & ~0x80);
            temp_r4_224 = this->unkC;
            M2C_FIELD(temp_r4_224, u8 *, 0xB08) = (u8) (M2C_FIELD(temp_r4_224, u8 *, 0xB08) | 0x40);
            AddGoal_AlertMode(this->unkC + 0x870);
            return;
        }
        goto block_29;
    }
block_29:
    if (IsFollowingSpawnPath() != 0) {
        AddGoal_FollowSpawnPath();
    }
    if (IsFollowingSpawnGraph() != 0) {
        AddGoal_FollowSpawnGraph();
        return;
    }
    if (IsActive(0x66) == 0) {
        if ((u32) M2C_FIELD(this->unkC, u32 *, 0xA94) != 0U) {
            AddGoal_FollowSpawnPath();
            ((KDPathIterator *) (this->unkC + 0xA94))->Init();
            return;
        }
        if ((u8) this->unk7C != 0) {
            RemoveAllSubgoals();
            AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk78);
            return;
        }
        if ((IsFollowingSpawnPath() == 0) && (temp_r3_281 = this->unkC, ((M2C_FIELD(temp_r3_281, f32 *, 0xAC8) > 0.0f) != 0)) && (M2C_FIELD(M2C_FIELD(temp_r3_281, void **, 0x44), u8 (**)(), 0x134)() == 0) && (this->unkC->IsFlinching(), (((u8) M2C_ERROR(/* Read from unset register $r3 */) == 0) != 0)) && (IsPresent(0x26) == 0) && (IsPresent(0x28) == 0)) {
            temp_r4_312 = this->unkC;
            if (((u8) M2C_FIELD(temp_r4_312, u8 *, 0xB08) >> 6U) & 1) {
                var_f31_317 = M2C_FIELD(M2C_FIELD(temp_r4_312, void **, 0xA38), f32 *, 0x134);
            } else {
                var_f31_317 = M2C_FIELD(M2C_FIELD(temp_r4_312, void **, 0xA38), f32 *, 0x12C);
            }
            var_r30_324 = 0;
            if (((u8) M2C_FIELD(temp_r4_312, u8 *, 0x8B8) == 2) || (((TargetContext *) (temp_r4_312 + 0x8B0))->Get() != NULL)) {
                var_r30_324 = 1;
            }
            if ((var_r30_324 != 0) && ((temp_r3_336 = this->unkC, (((((u8) M2C_FIELD(temp_r3_336, u8 *, 0xB08) >> 5U) & 1) == 0) == 0)) || ((((AITargetData *) (temp_r3_336 + 0x870))->GetDist() < var_f31_317) && ((temp_r3_344 = this->unkC, (((((u8) M2C_FIELD(temp_r3_344, u8 *, 0xB08) >> 6U) & 1) == 0) == 0)) || (((u8) M2C_FIELD(temp_r3_344, u8 *, 0x8B9) >> 4U) & 1)))) && (((AITargetData *) (this->unkC + 0x870))->IsAttackable() != 0) && (temp_r3_357 = this->unkC, ((M2C_FIELD(M2C_FIELD(temp_r3_357, void **, 0x44), u8 (**)(s32), 0x114)(temp_r3_357) == 0) != 0))) {
                AddGoal_AlertMode(this->unkC + 0x870);
                if (IsFollowingSpawnPath() != 0) {
                    StopFollowingSpawnPath();
                }
            } else if ((AddGoal_MoveToLastPlayerPos() == 0) && ((IsPresent(2) == 0) || (((u8) M2C_FIELD(this->unkC, u8 *, 0xB08) >> 6U) & 1)) && (IsFollowingSpawnPath() == 0)) {
                AddGoal_PatrolMode();
            }
        }
    }
}
#endif

void FireTier2Goal_Think::Deinit() {
    Goal<Enemy> *temp_r3_417;

    temp_r3_417 = this->unk78;
    temp_r3_417->Deinit();
    operator delete(this->unk78);
    EnemyGoal_Think::Deinit();
}

#if 0 // DRAFT: illegal implicit conversion from 'FireTier2 *' to
void FireTier2Goal_Think::Init(Enemy *arg0) {
    this->unk74 = checked_cast<FireTier2 *, Enemy>(arg0);
    if ((u8) this->unk9 == 0) {
        operator new(0x60U, NULL, 0);
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
        this->unk78 = M2C_ERROR(/* Read from unset register $r3 */);
    }
    this->unk78->Init(arg0);
    Init(arg0);
}
#endif

void FireTier2Goal_JumpOutOfLava::Reset() {
    this->unk8 = 1;
    RemoveAllSubgoals();
}

void FireTier2Goal_JumpOutOfLava::Terminate() {
    this->unk8 = 1;
    RemoveAllSubgoals();
}

#if 0 // DRAFT: illegal implicit conversion from 'void' to
u8 FireTier2Goal_JumpOutOfLava::Update() {
    ActivateIfInactive();
    this->unk8 = UpdateSubgoals();
    if (((u8) this->unk8 != 0) && ((u8) this->unk58 != 0)) {
        Activate();
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: undefined identifier 'sp28'
u8 FireTier2Goal_JumpOutOfLava::FindLavaEdge(const MKVector3 &arg0, MKVector3 *arg1, MKVector3 *arg2) {
    MKCollisionResult spF8;
    f64 spF0;
    f64 spE8;
    f64 spE0;                                       /* compiler-managed */
    f64 spD8;
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
    f64 sp60;
    f64 sp58;
    MKVector3 sp48;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp30;
    f32 sp20;
    f32 sp10;
    f32 temp_f2_610;
    f32 temp_f31_597;
    f64 temp_f3_608;
    f64 temp_f4_609;
    s32 var_r31_602;
    void *temp_r3_572;
    void *temp_r3_605;

    sp40 = 0.0f;
    temp_r3_572 = this->unkC->unk8;
    sp38 = 0.0f;
    sp3C = 300.0f;
    sp70 = (f64) sp40;
    sp68 = (f64) sp38;
    sp78 = M2C_FIELD(temp_r3_572, f64 *, 0x30);
    sp80 = M2C_FIELD(temp_r3_572, f64 *, 0x38);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    sp88 = sp28;
    sp30 = (f32) sp80 + (f32) sp70;
    sp90 = (f64) sp30;
    temp_f31_597 = sp88.GetWaterSurface(arg0);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r28, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
    var_r31_602 = 0;
    temp_r3_605 = this->unkC->unk8;
    temp_f3_608 = M2C_FIELD(temp_r3_605, f64 *, 0x38);
    temp_f4_609 = M2C_FIELD(temp_r3_605, f64 *, 0x30);
    temp_f2_610 = 300.0f + temp_f31_597;
    sp20 = arg0.unk8 * 200.0f;
    spD8 = temp_f4_609;
    unkspDC = temp_f2_610;
    spF0 = (f64) sp20;
    spC8 = temp_f4_609;
    spE8 = sp18;
    spE0 = temp_f3_608;
    spD0 = temp_f3_608;
    unkspCC = 10.0f + temp_f31_597;
    spB8 = spD8;
    spC0 = temp_f3_608;
loop_1:
    if (MKCollision_RayCollide(*((MKVector3 *) &spD8), *((MKVector3 *) &spC8), &spF8, (MKCollisionMode) 4, M2C_FIELD(this->unkC->unk110.unk460, s32 *, 0x18)) != 0) {
        if (var_r31_602 == 0) {
            M2C_FIELD(arg1, f64 *, 0) = M2C_BITWISE(f64, spF8);
            M2C_FIELD(arg1, f64 *, 8) = (f64) spF8.unk8;
            M2C_FIELD(arg2, f64 *, 0) = (f64) M2C_FIELD(arg1, f64 *, 0);
            M2C_FIELD(arg2, f64 *, 8) = (f64) M2C_FIELD(arg1, f64 *, 8);
            this->unkC->SetupEnemyRegion(*arg2, 1000.0f);
            return 1U;
        }
        spA8 = spB8;
        spB0 = spC0;
        unkspAC = temp_f31_597;
        sp98 = M2C_BITWISE(f64, spF8);
        spA0 = (f64) spF8.unk8;
        if (MKCollision_RayCollide(*((MKVector3 *) &spA8), *((MKVector3 *) &sp98), &spF8, (MKCollisionMode) 4, M2C_FIELD(this->unkC->unk110.unk460, s32 *, 0x18)) != 0) {
            M2C_FIELD(arg1, f64 *, 0) = M2C_BITWISE(f64, spF8);
            M2C_FIELD(arg1, f64 *, 8) = (f64) spF8.unk8;
            sp48.operator*(150.0f);
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r29, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            M2C_FIELD(arg2, f64 *, 0) = sp8;
            sp10 = arg1->unk8 + sp48.unk8;
            sp58 = sp8;
            M2C_FIELD(arg2, f64 *, 8) = (f64) sp10;
            sp60 = (f64) sp10;
            this->unkC->SetupEnemyRegion(*arg2, 1000.0f);
            return 1U;
        }
        goto block_6;
    }
block_6:
    spB8 = spD8;
    spC0 = spE0;
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f0, $f1 */);
    spE0 = (f32) spE0 + (f32) spF0;
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f0, $f1 */);
    var_r31_602 += 1;
    spD0 = (f32) spD0 + (f32) spF0;
    if (var_r31_602 >= 0xA) {
        return 0U;
    }
    goto loop_1;
}
#endif

#if 0 // DRAFT: expression syntax error
u8 FireTier2Goal_JumpOutOfLava::FindLavaEdgePath(const MKVector3 &arg0, MKVector3 *arg1, MKVector3 *arg2) {
    s32 sp2C;
    s32 sp28;
    void *sp24;
    void *sp18;
    f64 sp10;
    f64 sp8;
    f32 temp_f3_780;
    f32 temp_f4_775;
    f32 temp_f5_774;
    void *temp_r3_765;
    void *temp_r4_764;
    void *temp_r4_797;

    sp18.NearestPoint(2, arg0);
    sp24 = sp18;
    sp28 = sp1C;
    sp2C = sp20;
    if (sp18 != NULL) {
        temp_r4_764 = M2C_FIELD(sp18, void **, 0x24);
        temp_r3_765 = this->unkC->unk8;
        sp8 = M2C_FIELD(temp_r3_765, f64 *, 0x30);
        sp10 = M2C_FIELD(temp_r3_765, f64 *, 0x38);
        temp_f5_774 = unkspC - M2C_FIELD(temp_r4_764, f32 *, 4);
        temp_f4_775 = (f32) sp8 - M2C_FIELD(temp_r4_764, f32 *, 0);
        temp_f3_780 = (f32) sp10 - M2C_FIELD(temp_r4_764, f32 *, 8);
        if (((temp_f3_780 * temp_f3_780) + ((temp_f4_775 * temp_f4_775) + (temp_f5_774 * temp_f5_774))) < 2250000.0f) {
            M2C_FIELD(arg1, f64 *, 0) = (f64) M2C_FIELD(temp_r4_764, f32 *, 0);
            M2C_FIELD(arg1, f64 *, 8) = (f64) M2C_FIELD(temp_r4_764, f32 *, 8);
            temp_r4_797 = M2C_FIELD(sp18, void **, 0x24) + ((M2C_FIELD(sp18, s32 *, 0x20) - 1) * M2C_FIELD(sp18, s32 *, 0x1C));
            M2C_FIELD(arg2, f64 *, 0) = (f64) M2C_FIELD(temp_r4_797, f64 *, 0);
            M2C_FIELD(arg2, f64 *, 8) = (f64) M2C_FIELD(temp_r4_797, f64 *, 8);
            return 1U;
        }
    }
    return 0U;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk28'
void FireTier2Goal_JumpOutOfLava::Activate() {
    AITargetData sp60;
    M2C_UNK sp50;
    M2C_UNK sp40;
    f64 sp38;
    f64 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f32 sp8;
    AITargetData *var_r3_874;
    Enemy *temp_r3_831;
    Enemy *temp_r3_845;
    Enemy *temp_r3_856;
    Enemy *temp_r3_885;
    Enemy *temp_r3_946;
    Enemy *temp_r3_985;
    Enemy *temp_r4_823;
    Goal<Enemy> *temp_r3_1115;
    Goal<Enemy> *temp_r4_1108;
    Goal<Enemy> *temp_r6_1127;
    M2C_UNK *var_r3_902;
    MKHeap *temp_r5_915;
    f32 var_f2_1097;
    f32 var_f31_934;
    f32 var_f4_1033;
    f64 temp_f1_1036;
    f64 temp_f1_1042;
    f64 temp_f1_1046;
    s32 temp_r3_1065;
    s32 var_r0_1075;
    u8 temp_r4_916;
    u8 var_r29_938;
    u8 var_r31_832;
    u8 var_r31_881;
    u8 var_r31_936;

    temp_r4_823 = this->unkC;
    temp_r4_823->unk838.unk28.Update(*((MKVector3 *) &temp_r4_823->unk588));
    if (((u8) M2C_FIELD(this->unk20, u8 *, 0xB10) >> 7U) & 1) {
        temp_r3_831 = this->unkC;
        var_r31_832 = 0;
        if (((u8) M2C_FIELD(temp_r3_831, u8 *, 0x8B8) == 2) || (temp_r3_831->unk870.unk30.Get() != NULL)) {
            var_r31_832 = 1;
        }
        if (var_r31_832 != 0) {
            temp_r3_845 = this->unkC;
            if (((u8) M2C_FIELD(temp_r3_845, u8 *, 0x8B9) >> 6U) & 1) {
                if (temp_r3_845->unk838.unk28.GetDist() > 1500.0f) {
                    return;
                }
                goto block_8;
            }
        }
    } else {
block_8:
        temp_r3_856 = this->unkC;
        temp_r3_856->Activate();
        this->unk8 = 0;
        this->unk58 = 0;
        RemoveAllSubgoals();
        if (((u8) M2C_FIELD(this->unk20, u8 *, 0xB10) >> 7U) & 1) {
            sp60.GetPos();
            var_r3_874 = &sp60;
        } else {
            var_r3_874 = (AITargetData *) &this->unkC->unk588;
        }
        var_r31_881 = 0;
        sp60.unk30 = var_r3_874->unk0;
        sp60.unk38 = M2C_FIELD(var_r3_874, f64 *, 8);
        temp_r3_885 = this->unkC;
        if (((u8) M2C_FIELD(temp_r3_885, u8 *, 0x8B8) == 2) || (temp_r3_885->unk870.unk30.Get() != NULL)) {
            var_r31_881 = 1;
        }
        if (var_r31_881 != 0) {
            sp50.GetDir();
            var_r3_902 = &sp50;
        } else {
            KDMath_GetDirection(this->unkC->unk5C8);
            var_r3_902 = &sp40;
        }
        sp60.unk20 = M2C_FIELD(var_r3_902, f64 *, 0);
        sp60.unk28 = M2C_FIELD(var_r3_902, f64 *, 8);
        temp_r5_915 = this->unk20;
        temp_r4_916 = M2C_FIELD(temp_r5_915, u8 *, 0xB10);
        if ((temp_r4_916 >> 7U) & 1) {
            M2C_FIELD(temp_r5_915, u8 *, 0xB10) = (u8) (temp_r4_916 & ~0x80);
            AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk24);
            M2C_FIELD(this->unk24, s32 *, 0x10) = 0x73;
        }
        this->unk38.unk0 = 0.0f;
        var_f31_934 = 0.0f;
        var_r31_936 = 0;
        this->unk38.unk4 = 0.0f;
        var_r29_938 = 0;
        this->unk38.unk8 = 0.0f;
        this->unk48.unk0 = 0.0f;
        this->unk48.unk4 = 0.0f;
        this->unk48.unk8 = 0.0f;
        if (FindLavaEdgePath(*((MKVector3 *) &sp60.unk30), &this->unk38, &this->unk48) != 0) {
            temp_r3_946 = this->unkC;
            var_r29_938 = 1;
            var_r31_936 = 1;
            var_f31_934 = 50.0f + temp_r3_946->GetCollisionRadius();
        } else if ((FindLavaEdge(*((MKVector3 *) &sp60.unk20), &this->unk38, &this->unk48) != 0) || (sp20 = -(f32) sp60.unk20, sp24 = -unksp84, sp28 = -(f32) sp60.unk28, sp30 = (f64) sp20, sp38 = (f64) sp28, ((FindLavaEdge(*((MKVector3 *) &sp30), &this->unk38, &this->unk48) == 0) == 0))) {
            temp_r3_985 = this->unkC;
            var_r29_938 = 1;
            var_f31_934 = 200.0f + temp_r3_985->GetCollisionRadius();
        }
        if (var_r29_938 != 0) {
            AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk28);
            AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk2C);
            this->unkC->unk870.unk40.Set(this->unk38, 0U);
            this->unkC->unk870.unk40.SetInsideRegion(1U);
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $r30, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $r30, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
            sp60.unk10 = sp10;
            sp18 = this->unk48.unk8 - this->unk38.unk8;
            unksp74 = 0.0f;
            sp60.unk18 = (f64) sp18;
            var_f4_1033 = ((f32) sp60.unk18 * (f32) sp60.unk18) + (((f32) sp60.unk10 * (f32) sp60.unk10) + (0.0f * 0.0f));
            if (var_f4_1033 > 0.0f) {
                temp_f1_1036 = __frsqrte(var_f4_1033);
                temp_f1_1042 = 0.5 * temp_f1_1036 * -(((f64) var_f4_1033 * (temp_f1_1036 * temp_f1_1036)) - 3.0);
                temp_f1_1046 = 0.5 * temp_f1_1042 * -(((f64) var_f4_1033 * (temp_f1_1042 * temp_f1_1042)) - 3.0);
                var_f4_1033 = (f32) ((f64) var_f4_1033 * (0.5 * temp_f1_1046 * -(((f64) var_f4_1033 * (temp_f1_1046 * temp_f1_1046)) - 3.0)));
            } else if (var_f4_1033 < M2C_BITWISE(f32, 0.0)) {
                var_f4_1033 = __float_nan;
            } else {
                sp8 = var_f4_1033;
                temp_r3_1065 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                switch (temp_r3_1065) {             /* irregular */
                case 0x7F800000:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_1075 = 1;
                    } else {
                        var_r0_1075 = 2;
                    }
                    break;
                case 0x0:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_1075 = 5;
                    } else {
                        var_r0_1075 = 3;
                    }
                    break;
                default:
                    var_r0_1075 = 4;
                    break;
                }
                if (var_r0_1075 == 1) {
                    var_f4_1033 = __float_nan;
                }
            }
            var_f2_1097 = var_f4_1033;
            if (var_r31_936 == 0) {
                if (var_f4_1033 > 400.0f) {

                } else {
                    var_f4_1033 = 400.0f;
                }
                var_f2_1097 = var_f4_1033;
            }
            temp_r4_1108 = this->unk28;
            M2C_FIELD(temp_r4_1108, MKVector3 **, 0x10) = &this->unk38;
            M2C_FIELD(temp_r4_1108, f32 *, 0x14) = var_f31_934;
            temp_r3_1115 = this->unk2C;
            M2C_FIELD(temp_r3_1115, MKVector3 **, 0x10) = &this->unk48;
            M2C_FIELD(temp_r3_1115, f32 *, 0x14) = var_f2_1097;
            M2C_FIELD(temp_r3_1115, f32 *, 0x18) = 1000.0f;
            M2C_FIELD(temp_r3_1115, f32 *, 0x1C) = 15.0f;
            return;
        }
        AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk30);
        temp_r6_1127 = this->unk30;
        M2C_FIELD(temp_r6_1127, M2C_UNK **, 0x10) = &this->unkC->unk838.unk28;
        M2C_FIELD(temp_r6_1127, s32 *, 0x14) = 1;
        M2C_FIELD(temp_r6_1127, s32 *, 0x18) = 0xA;
        M2C_FIELD(temp_r6_1127, s32 *, 0x1C) = 0;
        M2C_FIELD(temp_r6_1127, u8 *, 0x20) = (u8) (M2C_FIELD(temp_r6_1127, u8 *, 0x20) & ~0x40);
        this->unk58 = 1;
    }
}
#endif

void FireTier2Goal_JumpOutOfLava::Deinit() {
    Goal<Enemy> *temp_r3_1157;
    Goal<Enemy> *temp_r3_1162;
    Goal<Enemy> *temp_r3_1167;
    Goal<Enemy> *temp_r3_1172;
    MKHeap *temp_r3_1188;
    void *temp_r31_1185;

    temp_r3_1157 = this->unk24;
    temp_r3_1157->Deinit();
    temp_r3_1162 = this->unk28;
    temp_r3_1162->Deinit();
    temp_r3_1167 = this->unk2C;
    temp_r3_1167->Deinit();
    temp_r3_1172 = this->unk30;
    temp_r3_1172->Deinit();
    operator delete(this->unk24);
    operator delete(this->unk28);
    operator delete(this->unk2C);
    operator delete(this->unk30);
    temp_r31_1185 = this->unk1C;
    if (temp_r31_1185 != NULL) {
        temp_r3_1188 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_1188 != NULL) {
            ((MKHeap *) (temp_r3_1188->Current()))->Free(temp_r31_1185, NULL, 0);
        } else {
            free(temp_r31_1185);
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

#if 0 // DRAFT: illegal implicit conversion from 'FireTier2 *' to
void FireTier2Goal_JumpOutOfLava::Init(Enemy *arg0) {
    Goal<Enemy> *temp_r4_1350;
    Goal<Enemy> *temp_r4_1361;
    Goal<Enemy> *temp_r4_1372;
    Goal<Enemy> *temp_r4_1383;
    MKHeap *temp_r3_1320;
    void *var_r3_1327;

    this->unk20 = checked_cast<FireTier2 *, Enemy>(arg0);
    if ((arg0 != NULL) && ((u8) this->unk9 == 0)) {
        operator new(0x14U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk24 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x18U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk28 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x20U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
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
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk30 = M2C_ERROR(/* Read from unset register $r3 */);
    }
    if ((u8) this->unk9 == 0) {
        temp_r3_1320 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_1320 != NULL) {
            var_r3_1327 = ((MKHeap *) (temp_r3_1320->Current()))->Alloc(0xC, NULL, 0);
        } else {
            var_r3_1327 = malloc(0xC);
        }
        this->unk1C = var_r3_1327;
        this->unk10 = 3;
    }
    this->unk8 = 1;
    this->unkC = arg0;
    this->unk4 = 0x66;
    if ((Enemy *) this->unkC != NULL) {
        this->unk9 = 1;
    }
    if ((u8) this->unk9 != 0) {
        temp_r4_1350 = this->unk24;
        M2C_FIELD(temp_r4_1350, s8 *, 8) = 1;
        M2C_FIELD(temp_r4_1350, Enemy **, 0xC) = arg0;
        M2C_FIELD(temp_r4_1350, s32 *, 4) = 0x38;
        if ((Enemy *) M2C_FIELD(temp_r4_1350, Enemy **, 0xC) != NULL) {
            M2C_FIELD(temp_r4_1350, s8 *, 9) = 1;
        }
        temp_r4_1361 = this->unk28;
        M2C_FIELD(temp_r4_1361, s8 *, 8) = 1;
        M2C_FIELD(temp_r4_1361, Enemy **, 0xC) = arg0;
        M2C_FIELD(temp_r4_1361, s32 *, 4) = 0x67;
        if ((Enemy *) M2C_FIELD(temp_r4_1361, Enemy **, 0xC) != NULL) {
            M2C_FIELD(temp_r4_1361, s8 *, 9) = 1;
        }
        temp_r4_1372 = this->unk2C;
        M2C_FIELD(temp_r4_1372, s8 *, 8) = 1;
        M2C_FIELD(temp_r4_1372, Enemy **, 0xC) = arg0;
        M2C_FIELD(temp_r4_1372, s32 *, 4) = 0x29;
        if ((Enemy *) M2C_FIELD(temp_r4_1372, Enemy **, 0xC) != NULL) {
            M2C_FIELD(temp_r4_1372, s8 *, 9) = 1;
        }
        temp_r4_1383 = this->unk30;
        M2C_FIELD(temp_r4_1383, s8 *, 8) = 1;
        M2C_FIELD(temp_r4_1383, Enemy **, 0xC) = arg0;
        M2C_FIELD(temp_r4_1383, s32 *, 4) = 0;
        if ((Enemy *) M2C_FIELD(temp_r4_1383, Enemy **, 0xC) != NULL) {
            M2C_FIELD(temp_r4_1383, s8 *, 9) = 1;
        }
    }
    this->unk58 = 0;
}
#endif

#if 0 // DRAFT: expression syntax error
void FireTier2Goal_MoveToLavaEdge::Terminate() {
    Enemy *temp_r3_1415;
    Enemy *temp_r3_1423;
    Enemy *temp_r4_1419;
    void *temp_r3_1428;

    this->unk10 = NULL;
    temp_r3_1415 = this->unkC;
    temp_r3_1415->unk6B5 |= 0x20;
    temp_r4_1419 = this->unkC;
    temp_r4_1419->unk5E4 = M2C_FIELD(temp_r4_1419->unk5D8, f32 *, 8);
    temp_r3_1423 = this->unkC;
    temp_r3_1423->unk588.unkC = 0.0f;
    temp_r3_1423->unk598 = 0.0f;
    temp_r3_1423->unk59C = 0.0f;
    temp_r3_1428 = this->unkC->unk638;
    M2C_FIELD(temp_r3_1428, u8 *, 0x464) = (u8) (M2C_FIELD(temp_r3_1428, u8 *, 0x464) & ~0x80);
    this->unkC->unk638->ArriveOff();
    this->unkC->unk638->ObstacleAvoidanceOff();
    this->unkC->unk638->WallAvoidanceOff();
    this->unk8 = 1;
}
#endif

#if 0 // DRAFT: expression syntax error
u8 FireTier2Goal_MoveToLavaEdge::Update() {
    u8 sp138;
    s32 sp134;
    s32 sp130;
    s32 sp12C;
    f32 sp128;
    s32 sp124;
    s8 sp123;
    s8 sp122;
    s16 sp120;
    f32 sp11C;
    f32 sp118;
    f32 sp114;
    f32 sp110;
    f32 sp10C;
    f32 sp108;
    f32 sp100;
    f32 spFC;
    f32 spF8;
    f32 spF0;
    f32 spEC;
    f32 spE8;
    f64 spE0;
    f64 spD8;
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
    M2C_UNK sp68;
    f32 sp58;
    f32 sp50;
    f32 sp40;
    f32 sp30;
    f32 sp20;
    f32 sp10;
    Enemy *temp_r3_1465;
    Enemy *temp_r3_1483;
    Enemy *temp_r3_1492;
    Enemy *temp_r3_1515;
    Enemy *temp_r3_1613;
    Enemy *temp_r3_1639;
    f32 temp_f1_1505;
    f32 temp_f1_1534;
    f32 temp_f31_1546;
    f32 var_f0_1643;
    u8 var_r30_1466;
    void *temp_r4_1518;
    void *temp_r5_1485;

    ActivateIfInactive();
    temp_r3_1465 = this->unkC;
    var_r30_1466 = 0;
    if (((u8) M2C_FIELD(temp_r3_1465, u8 *, 0x908) == 2) || (temp_r3_1465->unk8C0.unk30.Get() != NULL)) {
        var_r30_1466 = 1;
    }
    if (var_r30_1466 == 0) {
        this->unk8 = 3;
    } else {
        temp_r3_1483 = this->unkC;
        temp_r5_1485 = temp_r3_1483->unk8;
        spB8 = M2C_FIELD(temp_r5_1485, f64 *, 0x30);
        spC0 = M2C_FIELD(temp_r5_1485, f64 *, 0x38);
        temp_r3_1483->unk870.unk40.Update(*((MKVector3 *) &spB8));
        temp_r3_1492 = this->unkC;
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r3, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
        temp_f1_1505 = up.unk8 * temp_r3_1492->GetCollisionHeight();
        sp88 = sp48;
        sp50 = temp_f1_1505;
        sp90 = (f64) sp50;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
        temp_r3_1515 = this->unkC;
        temp_r4_1518 = temp_r3_1515->unk8;
        sp98 = sp38;
        sp40 = (f32) sp90 * 0.5f;
        spA8 = M2C_FIELD(temp_r4_1518, f64 *, 0x30);
        spA0 = (f64) sp40;
        spB0 = M2C_FIELD(temp_r4_1518, f64 *, 0x38);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        temp_f1_1534 = (f32) spB0 + (f32) spA0;
        spD8 = sp28;
        sp30 = temp_f1_1534;
        spE0 = (f64) sp30;
        temp_f31_1546 = 150.0f + temp_r3_1515->GetCollisionRadius(temp_r4_1518, temp_f1_1534, (f32) spB0);
        sp68.GetDir();
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
        sp78 = sp18;
        sp20 = sp70 * temp_f31_1546;
        sp80 = (f64) sp20;
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        sp10 = (f32) spE0 + (f32) sp80;
        spC8 = sp8;
        spD0 = (f64) sp10;
        spE8 = 0.0f;
        spEC = 0.0f;
        spF0 = 0.0f;
        spF8 = 0.0f;
        spFC = 0.0f;
        sp100 = 0.0f;
        sp108 = 0.0f;
        sp10C = 0.0f;
        sp110 = 0.0f;
        sp114 = 1.0f;
        sp118 = 0.0f;
        sp11C = 0.0f;
        sp120 = 0;
        sp122 = 0;
        sp123 = 0;
        sp124 = 0;
        sp128 = 3.4028235e38f;
        sp12C = 0;
        sp130 = 0;
        sp134 = -1;
        sp138 = 0;
        MKCollision_RayCollide(*((MKVector3 *) &spD8), *((MKVector3 *) &spC8), (MKCollisionResult *) &spE8, (MKCollisionMode) 4, M2C_FIELD(this->unkC->unk110.unk460, s32 *, 0x18));
        if (((sp138 != 0) && (sp58.GetDir(), temp_r3_1613 = this->unkC, ((((temp_r3_1613->unkC8 * sp60) + ((temp_r3_1613->unkC0 * sp58) + (temp_r3_1613->unkC4 * sp5C))) > 0.95f) != 0))) || (M2C_ERROR(/* unknown instruction: cror eq, lt, eq */), ((this->unkC->unk870.unk40.GetDist() == this->unk14) != 0))) {
            this->unk8 = 2;
        } else {
            temp_r3_1639 = this->unkC;
            var_f0_1643 = M2C_BITWISE(f32, temp_r3_1639->unk688) / temp_r3_1639->unk68C;
            if (var_f0_1643 < 1.0f) {

            } else {
                var_f0_1643 = 1.0f;
            }
            if (var_f0_1643 > 0.5f) {

            } else {
                var_f0_1643 = 0.5f;
            }
            M2C_FIELD(M2C_FIELD(temp_r3_1639, void **, 0x630), f32 *, 0x38) = var_f0_1643;
        }
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: function call 'Set(MKVector3, unsigned int)' does not match
void FireTier2Goal_MoveToLavaEdge::Activate() {
    Enemy *temp_r3_1720;
    Enemy *temp_r4_1695;
    Enemy *temp_r6_1699;
    void *temp_r3_1691;

    this->unk8 = 0;
    this->unkC->unk870.unk40.Set(*this->unk10, 0U);
    temp_r3_1691 = this->unkC->unk638;
    M2C_FIELD(temp_r3_1691, u8 *, 0x464) = (u8) (M2C_FIELD(temp_r3_1691, u8 *, 0x464) | 0x80);
    temp_r4_1695 = this->unkC;
    temp_r4_1695->unk638->ArriveOn((AITargetData *) &temp_r4_1695->unk870.unk40);
    temp_r6_1699 = this->unkC;
    temp_r6_1699->unkA20->GetAnimSequence(5, 0, M2C_BITWISE(s32, temp_r6_1699->unkACC), NULL);
    this->unkC->SetWalkMovementSpeed(1U);
    this->unkC->SetAnim((AnimSequenceType) 5, 0, 0, 0.15f, 0U, 0U);
    this->unkC->SetMovementType((CharacterMoveType) 0);
    temp_r3_1720 = this->unkC;
    temp_r3_1720->unk6B5 &= ~0x20;
    this->unkC->unk5E4 = 0.0f;
}
#endif
