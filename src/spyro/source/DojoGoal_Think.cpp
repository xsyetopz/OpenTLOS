#include "spyro/source/DojoGoal_Think.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKVector3.h"
#include "spyro/source/AITargetData.h"
#include "spyro/source/Enemies_Dojo.h"
#include "spyro/source/Enemy.h"
#include "spyro/source/EnemyDataTypes.h"
#include "spyro/source/EnemyGoal_AlertMode.h"
#include "spyro/source/EnemyGoal_FollowGraph.h"
#include "spyro/source/EnemyGoals_Death.h"
#include "spyro/source/EnemyGoals_Hit.h"
#include "spyro/source/EnemyGoals_Movement.h"
#include "spyro/source/EnemyRegion.h"
#include "spyro/source/SpawnerObject.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "common/Source/MKCollision.h"
#include <m2c_macros.h>

#if 0 // DRAFT: undefined identifier 'AddSubgoalToFront__21CompositeGoal'
M2C_UNK free(void *);                               /* extern */
void *malloc(M2C_UNK);                              /* extern */

void DojoGoal_Think::AddGoal_SpawnIdle() {
    void **temp_r3_16;

    temp_r3_16 = this->unk40;
    if ((temp_r3_16 != NULL) && (IsPresent(M2C_FIELD(*temp_r3_16, s32 (**)(), 0x34)()) == 0) && (IsActive(0x39) == 0)) {
        RemoveAllSubgoals();
        AddSubgoalToFront__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk44);
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'AddSubgoal__21CompositeGoal'
void DojoGoal_Think::AddGoal_Spawn() {
    void **temp_r3_60;

    temp_r3_60 = this->unk40;
    if ((temp_r3_60 != NULL) && (IsPresent(M2C_FIELD(*temp_r3_60, s32 (**)(), 0x34)()) == 0)) {
        this->unk54 |= 0x80;
        RemoveAllSubgoals();
        AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk40);
    }
}
#endif

void DojoGoal_Think::StartFollowingSpawnGraph() {
    Enemy *temp_r4_98;

    if (!(((u8) this->unk54 >> 6U) & 1)) {
        temp_r4_98 = this->unk20;
        temp_r4_98->unkB09 |= 8;
        this->unk54 |= 0x40;
    }
}

#if 0 // DRAFT: undefined identifier '__vptr'
void DojoGoal_Think::StopFollowingSpawnGraph() {
    Enemy *temp_r3_132;
    Enemy *temp_r5_119;

    temp_r5_119 = this->unk20;
    temp_r5_119->unkB09 &= ~8;
    if (M2C_FIELD(this->__vptr, u8 (**)(M2C_UNK, Enemy *, M2C_UNK), 0x38)(0x2A, temp_r5_119, 0) != 0) {
        RemoveAllSubgoals();
    }
    temp_r3_132 = this->unk20;
    temp_r3_132->SetupEnemyRegion(temp_r3_132->unk588, 1000.0f);
}
#endif

u8 DojoGoal_Think::IsFollowingSpawnGraph() {
    return ((u8) this->unk20->unkB09 >> 3U) & 1;
}

#if 0 // DRAFT: undefined identifier '__vptr'
u8 DojoGoal_Think::AddGoal_MoveToLastPlayerPos() {
    f64 spC0;
    f64 spB8;
    f64 spB0;
    f64 spA8;
    MKVector3 sp98;
    MKVector3 sp88;
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
    M2C_UNK sp18;
    u8 sp14;
    void *sp10;
    u8 spC;
    void *sp8;
    Enemy *temp_r28_341;
    Enemy *temp_r3_162;
    Enemy *temp_r3_196;
    Enemy *temp_r3_225;
    Enemy *temp_r3_284;
    Enemy *temp_r3_292;
    Enemy *temp_r3_393;
    Enemy *temp_r4_365;
    Enemy *temp_r4_371;
    Enemy *temp_r4_378;
    Goal<Enemy> *temp_r8_400;
    f32 temp_f1_288;
    f32 temp_f1_397;
    f32 temp_f2_291;
    f32 temp_f31_191;
    f64 temp_f0_206;
    f64 temp_f0_303;
    u8 var_r0_166;
    u8 var_r29_342;
    u8 var_r30_226;
    u8 var_r30_272;
    void *temp_r4_216;
    void *temp_r4_313;

    temp_r3_162 = this->unk20;
    var_r0_166 = 0;
    if ((temp_r3_162->unk720 == MKVector3::zero.unk0) && (temp_r3_162->unk724 == MKVector3::zero.unk4) && (temp_r3_162->unk728 == MKVector3::zero.unk8)) {
        var_r0_166 = 1;
    }
    if (var_r0_166 != 0) {
        return 0U;
    }
    if (((u8) this->unk54 >> 4U) & 1) {
        temp_f31_191 = M2C_FIELD(temp_r3_162->__vptr, f32 (**)(), 0x100)();
        sp60 = 0.0f;
        temp_r3_196 = this->unk20;
        sp58 = 0.0f;
        sp5C = 50.0f + temp_f31_191;
        sp80 = (f64) sp60;
        sp78 = (f64) sp58;
        temp_f0_206 = M2C_FIELD(temp_r3_196, f64 *, 0x720) + (f64) sp58;
        sp48 = temp_f0_206;
        spB8 = temp_f0_206;
        sp50 = temp_r3_196->unk728 + (f32) sp80;
        spC0 = (f64) sp50;
        temp_r4_216 = temp_r3_196->unk634;
        sp10 = temp_r4_216;
        if (temp_r4_216 != NULL) {
            sp14 = M2C_FIELD(temp_r4_216, u8 *, 4);
            M2C_FIELD(temp_r4_216, u8 *, 4) = 0U;
        }
        temp_r3_225 = this->unk20;
        var_r30_226 = 0;
        if (((u8) M2C_FIELD(temp_r3_225, u8 *, 0x8B8) == 2) || (temp_r3_225->unk870.unk40.Get() != NULL)) {
            var_r30_226 = 1;
        }
        if ((var_r30_226 == 0) || (MKCollision_SphereCollide(*((MKVector3 *) &spB8), temp_f31_191, NULL, 0, (MKCollisionMode) 7, 0x04000000) != 0)) {
            RemoveAllSubgoals();
            this->unk54 &= ~0x10;
            if (sp10 != NULL) {
                M2C_FIELD(sp10, u8 *, 4) = sp14;
            }
            return 0U;
        }
        if (sp10 != NULL) {
            M2C_FIELD(sp10, u8 *, 4) = sp14;
        }
        goto block_39;
    }
    var_r30_272 = 0;
    if (((u8) M2C_FIELD(temp_r3_162, u8 *, 0x8B8) == 2) || (temp_r3_162->unk870.unk40.Get() != NULL)) {
        var_r30_272 = 1;
    }
    if (var_r30_272 != 0) {
        temp_r3_284 = this->unk20;
        temp_f1_288 = temp_r3_284->GetCollisionRadius();
        temp_f2_291 = 50.0f + temp_f1_288;
        temp_r3_292 = this->unk20;
        sp40 = 0.0f;
        sp38 = 0.0f;
        sp3C = temp_f2_291;
        sp70 = (f64) sp40;
        sp68 = (f64) sp38;
        temp_f0_303 = M2C_FIELD(temp_r3_292, f64 *, 0x720) + (f64) sp38;
        sp28 = temp_f0_303;
        spA8 = temp_f0_303;
        sp30 = temp_r3_292->unk728 + (f32) sp70;
        spB0 = (f64) sp30;
        temp_r4_313 = temp_r3_292->unk634;
        sp8 = temp_r4_313;
        if (temp_r4_313 != NULL) {
            spC = M2C_FIELD(temp_r4_313, u8 *, 4);
            M2C_FIELD(temp_r4_313, u8 *, 4) = 0U;
        }
        if (MKCollision_SphereCollide(*((MKVector3 *) &spA8), temp_f1_288, NULL, 0, (MKCollisionMode) 7, 0x04000000) != 0) {
            if (sp8 != NULL) {
                M2C_FIELD(sp8, u8 *, 4) = spC;
            }
            return 0U;
        }
        RemoveAllSubgoals();
        temp_r28_341 = this->unk20;
        var_r29_342 = 0;
        if (temp_r28_341->unk800.IsPointWithin(*((MKVector3 *) &temp_r28_341->unk720)) != 0) {
            ((EnemyRegion *) &sp18)->GetRegionPos();
            if ((f32) fabs(sp1C - temp_r28_341->unk724) <= 500.0f) {
                var_r29_342 = 1;
            }
        }
        if ((var_r29_342 != 0) && (temp_r4_365 = this->unk20, ((temp_r4_365->unk838.IsPointWithin(*((MKVector3 *) &temp_r4_365->unk720)) == 0) != 0))) {
            temp_r4_371 = this->unk20;
            temp_r4_371->unk8C0.Set(*((MKVector3 *) &temp_r4_371->unk720), 0U);
        } else {
            temp_r4_378 = this->unk20;
            temp_r4_378->unk800.GetNearestPointOnBoundingRegion(*((MKVector3 *) &temp_r4_378->unk720), &sp98, &sp88);
            this->unk20->unk8C0.Set(sp98, 0U);
        }
        AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk50);
        temp_r3_393 = this->unk20;
        temp_f1_397 = temp_r3_393->GetCollisionRadius();
        temp_r8_400 = this->unk50;
        M2C_FIELD(temp_r8_400, AITargetData **, 0x10) = &this->unk20->unk8C0;
        M2C_FIELD(temp_r8_400, f32 *, 0x18) = temp_f1_397;
        M2C_FIELD(temp_r8_400, u8 *, 0x30) = (u8) (M2C_FIELD(temp_r8_400, u8 *, 0x30) | 0x80);
        M2C_FIELD(temp_r8_400, s32 *, 0x20) = 2;
        M2C_FIELD(temp_r8_400, s32 *, 0x24) = 0;
        M2C_FIELD(temp_r8_400, s32 *, 0x28) = -1;
        M2C_FIELD(temp_r8_400, u8 *, 0x30) = (u8) (M2C_FIELD(temp_r8_400, u8 *, 0x30) | 0x40);
        M2C_FIELD(temp_r8_400, u8 *, 0x30) = (u8) (M2C_FIELD(temp_r8_400, u8 *, 0x30) | 0x20);
        M2C_FIELD(temp_r8_400, u8 *, 0x30) = (u8) (M2C_FIELD(temp_r8_400, u8 *, 0x30) | 0x10);
        this->unk20->unk8C0.SetInsideRegion(1U);
        this->unk54 |= 0x10;
        if (sp8 != NULL) {
            M2C_FIELD(sp8, u8 *, 4) = spC;
        }
block_39:
        return 1U;
    }
    return 0U;
}
#endif

#if 0 // DRAFT: undefined identifier 'AddSubgoal__21CompositeGoal'
void DojoGoal_Think::AddGoal_FollowSpawnGraph() {
    Enemy *temp_r3_471;
    Enemy *temp_r3_476;

    if (IsPresent(0x2A) == 0) {
        RemoveAllSubgoals();
        AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk48);
        temp_r3_471 = this->unk20;
        temp_r3_471->unkB09 |= 8;
        temp_r3_476 = this->unk20;
        temp_r3_476->unkB08 |= 0x40;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'AddSubgoal__21CompositeGoal'
void DojoGoal_Think::AddGoal_ReceiveOrders() {
    if (IsPresent(0x4D) == 0) {
        RemoveAllSubgoals();
        AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk4C);
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'AddSubgoal__21CompositeGoal'
void DojoGoal_Think::AddGoal_Respawn() {
    if (IsPresent(0x1E) == 0) {
        RemoveAllSubgoals();
        AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk38);
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'AddSubgoal__21CompositeGoal'
void DojoGoal_Think::AddGoal_Death(EnemyDamageFeedback *arg0) {
    Enemy *temp_r4_572;
    s32 temp_r0_576;
    s32 temp_r0_643;
    s32 temp_r0_697;
    u8 temp_r3_573;
    u8 var_r29_553;
    u8 var_r29_600;
    u8 var_r31_658;

    var_r29_553 = 0;
    if ((((u8) this->unk20->unkB0A >> 5U) & 1) && (IsPresent(0x5B) == 0)) {
        RemoveAllSubgoals();
        AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk34);
        return;
    }
    temp_r4_572 = this->unk20;
    temp_r3_573 = temp_r4_572->unkB0A;
    if (!((temp_r3_573 >> 5U) & 1)) {
        temp_r0_576 = arg0->unk28;
        if (temp_r0_576 == 6) {
            if (IsActive(0x11) == 0) {
                AddGoal_Hit(arg0);
                var_r29_553 = 1;
            }
        } else {
            if (temp_r0_576 == 0xC) {
                temp_r4_572->unkB0A = temp_r3_573 | 8;
            }
            var_r29_600 = 0;
            if ((IsActive(0x11) == 0) && ((IsActive(0xB) != 0) || (IsActive(0x13) != 0) || (IsActive(0xC) != 0))) {
                var_r29_600 = 1;
            }
            if (var_r29_600 != 0) {
                AddGoal_Hit(arg0);
                var_r29_553 = 1;
            } else {
                temp_r0_643 = arg0->unk28;
                if ((temp_r0_643 == 2) || (temp_r0_643 == 8) || (temp_r0_643 == 0xA)) {
                    AddGoal_Hit(arg0);
                    var_r29_553 = 1;
                } else {
                    var_r31_658 = 0;
                    if ((IsActive(0xC) != 0) || (IsActive(0xD) != 0)) {
                        var_r31_658 = 1;
                    }
                    var_r29_553 = var_r31_658;
                }
            }
        }
        if (IsPresent(0x5B) == 0) {
            if (var_r29_553 != 0) {
loop_29:
                temp_r0_697 = this->unk14;
                if (temp_r0_697 > 1) {
                    if (temp_r0_697 > 0) {
                        this->unk14 -= 1;
                    }
                    goto loop_29;
                }
            } else {
                RemoveAllSubgoals();
            }
            AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk34);
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'AddSubgoalToFront__21CompositeGoal'
void DojoGoal_Think::AddGoal_Hit(EnemyDamageFeedback *arg0) {
    Enemy *temp_r3_893;
    Enemy *temp_r4_956;
    f32 var_f31_731;
    s32 temp_r0_818;
    s32 temp_r0_861;
    s32 temp_r0_942;
    s32 temp_r3_855;
    s32 temp_r3_911;
    s32 temp_r3_943;
    s32 var_r28_728;
    u32 temp_r0_873;
    u8 temp_r23_748;
    u8 temp_r24_755;
    u8 temp_r25_762;
    u8 temp_r29_734;
    u8 temp_r30_769;
    u8 temp_r31_741;
    u8 temp_r31_777;
    void *temp_r3_840;

    var_r28_728 = arg0->unk28;
    var_f31_731 = 0.0f;
    temp_r29_734 = IsActive(8);
    temp_r31_741 = IsActive(0xB);
    temp_r23_748 = IsActive(0xE);
    temp_r24_755 = IsActive(0xC);
    temp_r25_762 = IsActive(0x13);
    temp_r30_769 = IsActive(0x12);
    temp_r31_777 = IsActive(0xD);
    if ((temp_r31_741 != 0) || (temp_r25_762 != 0)) {
        switch (var_r28_728) {
        case 4:
        case 5:
        case 7:
        case 9:
        case 11:
            if (var_r28_728 != 0xB) {
                this->unk20->ThawIfFrozen();
            }
            var_r28_728 = 9;
            break;
        case 10:
            var_f31_731 = 3000.0f;
            break;
        default:
            var_f31_731 = 500.0f;
            var_r28_728 = 3;
            break;
        }
    } else if (((temp_r24_755 != 0) || (temp_r23_748 != 0)) && (((u32) (var_r28_728 - 4) <= 1U) || (var_r28_728 == 2)) && (temp_r0_818 = arg0->unk20, (((u32) temp_r0_818 == 8U) == 0)) && (var_r28_728 != 2) && ((u32) temp_r0_818 != 0x20U) && (var_r28_728 != 8)) {
        var_r28_728 = 0xE;
    } else if (var_r28_728 == 9) {
        var_r28_728 = 1;
    } else if (var_r28_728 == 0xA) {
        var_r28_728 = 8;
    }
    temp_r3_840 = this->unk20->unkA00;
    if ((temp_r3_840 != NULL) && ((u8) M2C_FIELD(temp_r3_840, u8 *, 0x20) != 0) && (arg0->unk20 & 0x47F1)) {
        RemoveAllSubgoals();
    }
    if (var_r28_728 == 9) {
        temp_r3_855 = this->unk20->unkAF4;
        if ((temp_r3_855 >= 3) && !(arg0->unk20 & 8) && (((temp_r0_861 = arg0->unk28, ((temp_r0_861 == 4) == 0)) && (temp_r0_861 != 5)) || (temp_r3_855 >= 6))) {
            var_r28_728 = 0xE;
        }
    }
    temp_r0_873 = ((u8) arg0->unk34 >> 4U) & 1;
    if ((temp_r0_873 != 0) && (this->unk20->unkACC <= 0.0f) && ((var_r28_728 == 0) || (var_r28_728 == 4) || (var_r28_728 == 5))) {
        var_r28_728 = 7;
    } else if (temp_r0_873 != 0) {
        temp_r3_893 = this->unk20;
        if (temp_r3_893->unkACC <= 0.0f) {
            temp_r3_893->Armour_Destroy();
        }
    }
    if (var_r28_728 != 0xE) {
        if (IsActive(0x59) != 0) {
            temp_r3_911 = arg0->unk20;
            if ((!(temp_r3_911 & 4) || ((s32) arg0->unk2C != 1)) && (!(temp_r3_911 & 8) || (var_r28_728 != 2))) {
                if ((var_r28_728 != 0) && ((var_r28_728 != 1) || (temp_r29_734 != 0)) && (temp_r30_769 == 0)) {
                    if (temp_r31_777 != 0) {
                        return;
                    }
                    goto block_54;
                }
            } else {
block_54:
                if ((s32) this->unk14 > 0) {
                    this->unk18 += 1;
                    temp_r0_942 = this->unk18;
                    temp_r3_943 = this->unk10;
                    if (temp_r0_942 >= temp_r3_943) {
                        this->unk18 = temp_r0_942 - temp_r3_943;
                    }
                    this->unk14 -= 1;
                }
                goto block_58;
            }
        } else {
block_58:
            arg0->unk28 = var_r28_728;
            arg0->unk18 = var_f31_731;
            temp_r4_956 = this->unk20;
            temp_r4_956->unk910 = arg0->unk0;
            M2C_FIELD(temp_r4_956, f64 *, 0x918) = (f64) arg0->unk8;
            temp_r4_956->unk920 = arg0->unk10;
            temp_r4_956->unk924 = arg0->unk14;
            temp_r4_956->unk928 = arg0->unk18;
            temp_r4_956->unk92C = arg0->unk1C;
            temp_r4_956->unk930 = arg0->unk20;
            temp_r4_956->unk934 = arg0->unk24;
            temp_r4_956->unk938 = arg0->unk28;
            temp_r4_956->unk93C = arg0->unk2C;
            temp_r4_956->unk940 = arg0->unk30;
            temp_r4_956->unk944 = arg0->unk34;
            AddSubgoalToFront__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk30);
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'AddSubgoal__21CompositeGoal'
void DojoGoal_Think::AddGoal_AlertMode(AITargetData *arg0) {
    Goal<Enemy> *temp_r4_1014;

    if (IsPresent(0x54) == 0) {
        RemoveAllSubgoals();
        AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk2C);
        temp_r4_1014 = this->unk2C;
        M2C_FIELD(temp_r4_1014, AITargetData **, 0x20) = arg0;
        M2C_FIELD(temp_r4_1014, s32 *, 0x4C) = 3;
        M2C_FIELD(temp_r4_1014, u8 *, 0x50) = (u8) (M2C_FIELD(temp_r4_1014, u8 *, 0x50) & ~0x80);
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'AddSubgoal__21CompositeGoal'
void DojoGoal_Think::AddGoal_Idle() {
    Goal<Enemy> *temp_r4_1050;

    if (IsPresent(0) == 0) {
        RemoveAllSubgoals();
        AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk24);
        temp_r4_1050 = this->unk24;
        M2C_FIELD(temp_r4_1050, s32 *, 0x10) = 0;
        M2C_FIELD(temp_r4_1050, s32 *, 0x14) = 0;
        M2C_FIELD(temp_r4_1050, s32 *, 0x18) = 1;
        M2C_FIELD(temp_r4_1050, s32 *, 0x1C) = 0;
        M2C_FIELD(temp_r4_1050, u8 *, 0x20) = (u8) (M2C_FIELD(temp_r4_1050, u8 *, 0x20) & ~0x40);
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'AddSubgoal__21CompositeGoal'
void DojoGoal_Think::AddGoal_PatrolMode() {
    if (IsPresent(0x53) == 0) {
        RemoveAllSubgoals();
        AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk28);
    }
}
#endif

void DojoGoal_Think::Reset() {
    this->unk8 = 1;
    RemoveAllSubgoals();
    this->unk54 &= ~0x80;
    this->unk54 &= ~0x40;
    this->unk54 &= ~0x20;
}

#if 0 // DRAFT: undefined identifier '__vptr'
void DojoGoal_Think::Arbitrate() {
    EnemyDamageFeedback sp40;
    EnemyDamageFeedback sp8;
    Enemy *temp_r3_1217;
    Enemy *temp_r3_1252;
    Enemy *temp_r3_1270;
    Enemy *temp_r3_1278;
    Enemy *temp_r3_1318;
    Enemy *temp_r3_1342;
    Enemy *temp_r3_1375;
    Enemy *temp_r3_1389;
    Enemy *temp_r3_1415;
    Enemy *temp_r3_1468;
    Enemy *temp_r3_1476;
    Enemy *temp_r3_1484;
    Enemy *temp_r4_1133;
    Enemy *temp_r4_1302;
    Enemy *temp_r4_1309;
    Enemy *temp_r4_1438;
    Goal<Enemy> *temp_r5_1361;
    f32 var_f0_1443;
    u32 var_r0_1168;
    u8 var_r30_1290;
    u8 var_r30_1330;
    u8 var_r30_1376;
    u8 var_r30_1451;
    void **temp_r3_1260;
    void *temp_r3_1165;
    void *temp_r5_1147;

    temp_r4_1133 = this->unk20;
    if (!(((u8) temp_r4_1133->unkB09 >> 7U) & 1)) {
        AddGoal_Respawn();
        return;
    }
    if (!(((u8) this->unk54 >> 7U) & 1) && ((void **) this->unk40 != NULL)) {
        temp_r5_1147 = temp_r4_1133->unkA44;
        if ((temp_r5_1147 != NULL) && (M2C_FIELD(temp_r5_1147, s32 *, 4) & 0x200)) {
            AddGoal_Spawn();
            return;
        }
    }
    if ((((u8) temp_r4_1133->unkB0A >> 5U) & 1) && ((s32) temp_r4_1133->unk110.unk16C > 0)) {
        if (((u8) temp_r4_1133->unk110.unk58 != 0) && (temp_r3_1165 = temp_r4_1133->unk110.unk50, ((temp_r3_1165 == NULL) == 0)) && (var_r0_1168 = M2C_FIELD(temp_r3_1165, u32 *, 8), ((var_r0_1168 == 0U) == 0))) {

        } else {
            var_r0_1168 = 0U;
        }
        if (var_r0_1168 == 0U) {
            sp40.Init();
            AddGoal_Death(&sp40);
            return;
        }
        goto block_16;
    }
block_16:
    if (temp_r4_1133->WasHit() != 0) {
        sp8.Init();
        if ((IsFollowingSpawnGraph() != 0) && (IsActive(0x30) == 0) && (IsActive(0x29) == 0)) {
            StopFollowingSpawnGraph();
        }
        this->unk20->TakeDamage(&sp8, 0U);
        temp_r3_1217 = this->unk20;
        temp_r3_1217->unkB0A &= ~1;
        if ((this->unk20->unkAC8 <= 0.0f) && (IsPresent(0x29) == 0)) {
            AddGoal_Death(&sp8);
            return;
        }
        if (sp8.unk28 != 0xE) {
            AddGoal_Hit(&sp8);
            return;
        }
        if ((sp8.unk34 >> 4U) & 1) {
            temp_r3_1252 = this->unk20;
            if (temp_r3_1252->unkACC <= 0.0f) {
                temp_r3_1252->Armour_Destroy();
            }
        }
        goto block_29;
    }
block_29:
    temp_r3_1260 = this->unk40;
    if ((temp_r3_1260 == NULL) || (M2C_FIELD(*temp_r3_1260, u8 (**)(), 0x28)() == 0)) {
        temp_r3_1270 = this->unk20;
        if (temp_r3_1270->unkAC8 > 0.0f) {
            temp_r3_1270->IsFlinching();
            if ((u8) M2C_ERROR(/* Read from unset register $r3 */) == 0) {
                temp_r3_1278 = this->unk20;
                if (((u8) temp_r3_1278->unkB01 >> 4U) & 1) {
                    AddGoal_SpawnIdle();
                    return;
                }
                if (((u8) temp_r3_1278->unkB0A >> 7U) & 1) {
                    var_r30_1290 = 0;
                    if (((u8) M2C_FIELD(temp_r3_1278, u8 *, 0x8B8) == 2) || (temp_r3_1278->unk870.unk40.Get() != NULL)) {
                        var_r30_1290 = 1;
                    }
                    if (var_r30_1290 != 0) {
                        temp_r4_1302 = this->unk20;
                        temp_r4_1302->unkB0A &= ~0x80;
                        temp_r4_1309 = this->unk20;
                        temp_r4_1309->unkB08 |= 0x40;
                        AddGoal_AlertMode(&this->unk20->unk870);
                        return;
                    }
                    goto block_41;
                }
block_41:
                temp_r3_1318 = this->unk20;
                if (temp_r3_1318->unkB0A & 1) {
                    AddGoal_ReceiveOrders();
                    return;
                }
                if (((u8) this->unk54 >> 5U) & 1) {
                    var_r30_1330 = 0;
                    if (((u8) M2C_FIELD(temp_r3_1318, u8 *, 0x8B8) == 2) || (temp_r3_1318->unk870.unk40.Get() != NULL)) {
                        var_r30_1330 = 1;
                    }
                    if ((var_r30_1330 != 0) && (((temp_r3_1342 = this->unk20, (((s32) temp_r3_1342->unkA90 == 1) != 0)) && (temp_r3_1342->unk870.GetDist() < this->unk20->unkA38->unk140)) || ((s32) this->unk20->unkA90 != 1))) {
                        AddGoal_FollowSpawnGraph();
                        temp_r5_1361 = this->unk48;
                        M2C_FIELD(temp_r5_1361, u8 *, 0x95) = (u8) (M2C_FIELD(temp_r5_1361, u8 *, 0x95) | 8);
                        M2C_FIELD(temp_r5_1361, u8 *, 0x95) = (u8) (M2C_FIELD(temp_r5_1361, u8 *, 0x95) & ~1);
                        return;
                    }
                    goto block_52;
                }
block_52:
                if (((u8) this->unk54 >> 5U) & 1) {
                    temp_r3_1375 = this->unk20;
                    var_r30_1376 = 0;
                    if (((u8) M2C_FIELD(temp_r3_1375, u8 *, 0x8B8) == 2) || (temp_r3_1375->unk870.unk40.Get() != NULL)) {
                        var_r30_1376 = 1;
                    }
                    if (var_r30_1376 != 0) {
                        temp_r3_1389 = this->unk20;
                        if (((s32) temp_r3_1389->unkA90 == 1) && (temp_r3_1389->unk870.GetDist() > this->unk20->unkA38->unk140)) {
                            AddGoal_Idle();
                            return;
                        }
                    }
                    goto block_60;
                }
block_60:
                if (!(((u8) this->unk54 >> 5U) & 1) && (IsFollowingSpawnGraph() != 0)) {
                    AddGoal_FollowSpawnGraph();
                    return;
                }
                goto block_63;
            }
        }
block_63:
        temp_r3_1415 = this->unk20;
        if ((temp_r3_1415->unkAC8 > 0.0f) && (M2C_FIELD(temp_r3_1415->__vptr, u8 (**)(), 0x134)() == 0) && (this->unk20->IsFlinching(), (((u8) M2C_ERROR(/* Read from unset register $r3 */) == 0) != 0)) && (IsPresent(0x28) == 0)) {
            temp_r4_1438 = this->unk20;
            if (((u8) temp_r4_1438->unkB08 >> 6U) & 1) {
                var_f0_1443 = temp_r4_1438->unkA38->unk134;
            } else {
                var_f0_1443 = temp_r4_1438->unkA38->unk12C;
            }
            var_r30_1451 = 0;
            if (((u8) M2C_FIELD(temp_r4_1438, u8 *, 0x8B8) == 2) || (temp_r4_1438->unk870.unk40.Get() != NULL)) {
                var_r30_1451 = 1;
            }
            if ((var_r30_1451 != 0) && (this->unk20->unk870.IsAttackable() != 0) && ((temp_r3_1468 = this->unk20, (((((u8) temp_r3_1468->unkB08 >> 5U) & 1) == 0) == 0)) || ((temp_r3_1468->unk870.GetDistSq() < (var_f0_1443 * var_f0_1443)) && ((temp_r3_1476 = this->unk20, (((((u8) temp_r3_1476->unkB08 >> 6U) & 1) == 0) == 0)) || (((u8) M2C_FIELD(temp_r3_1476, u8 *, 0x8B9) >> 4U) & 1))))) {
                temp_r3_1484 = this->unk20;
                if (temp_r3_1484->IsTargetBehindWall() == 0) {
                    AddGoal_AlertMode(&this->unk20->unk870);
                    return;
                }
            }
            if ((AddGoal_MoveToLastPlayerPos() == 0) && ((IsPresent(2) == 0) || (((u8) this->unk20->unkB08 >> 6U) & 1))) {
                AddGoal_PatrolMode();
            }
        }
    }
}
#endif

void DojoGoal_Think::Terminate() {
    this->unk54 &= ~0x20;
    this->unk8 = 1;
    RemoveAllSubgoals();
}

u8 DojoGoal_Think::Update() {
    Enemy *temp_r3_1560;

    if (this->unk20->WasHit() != 0) {
        this->unk8 = 1;
    }
    temp_r3_1560 = this->unk20;
    if (temp_r3_1560->IsDead() == 0) {
        this->unk20->SelectTarget();
    }
    ActivateIfInactive();
    this->unk8 = UpdateSubgoals();
    if ((u8) this->unk8 != 0) {
        Activate();
        this->unk54 &= ~0x10;
    }
    return this->unk8;
}

void DojoGoal_Think::Activate() {
    this->unk8 = 0;
    if ((u32) this->unk20->unkA80 != 0) {
        StartFollowingSpawnGraph();
        this->unk54 |= 0x20;
    }
    Arbitrate();
}

#if 0 // DRAFT: undefined identifier '__vptr'
void DojoGoal_Think::Deinit() {
    Goal<Enemy> *temp_r3_1636;
    Goal<Enemy> *temp_r3_1641;
    Goal<Enemy> *temp_r3_1646;
    Goal<Enemy> *temp_r3_1651;
    Goal<Enemy> *temp_r3_1656;
    Goal<Enemy> *temp_r3_1661;
    Goal<Enemy> *temp_r3_1666;
    Goal<Enemy> *temp_r3_1671;
    Goal<Enemy> *temp_r3_1676;
    Goal<Enemy> *temp_r3_1697;
    Goal<Enemy> *temp_r3_1733;
    MKHeap *temp_r3_1741;
    void **temp_r3_1681;
    void **temp_r3_1689;
    void **temp_r3_1723;
    void **temp_r3_1728;
    void *temp_r31_1738;

    temp_r3_1636 = this->unk24;
    temp_r3_1636->Deinit();
    temp_r3_1641 = this->unk28;
    temp_r3_1641->Deinit();
    temp_r3_1646 = this->unk2C;
    temp_r3_1646->Deinit();
    temp_r3_1651 = this->unk30;
    temp_r3_1651->Deinit();
    temp_r3_1656 = this->unk34;
    temp_r3_1656->Deinit();
    temp_r3_1661 = this->unk38;
    temp_r3_1661->Deinit();
    temp_r3_1666 = this->unk48;
    temp_r3_1666->Deinit();
    temp_r3_1671 = this->unk4C;
    temp_r3_1671->Deinit();
    temp_r3_1676 = this->unk50;
    temp_r3_1676->Deinit();
    temp_r3_1681 = this->unk3C;
    if (temp_r3_1681 != NULL) {
        M2C_FIELD(*temp_r3_1681, M2C_UNK (**)(), 0xC)();
    }
    temp_r3_1689 = this->unk40;
    if (temp_r3_1689 != NULL) {
        M2C_FIELD(*temp_r3_1689, M2C_UNK (**)(), 0xC)();
    }
    temp_r3_1697 = this->unk44;
    if (temp_r3_1697 != NULL) {
        M2C_FIELD(temp_r3_1697->__vptr, M2C_UNK (**)(), 0xC)();
    }
    operator delete(this->unk24);
    operator delete(this->unk28);
    operator delete(this->unk2C);
    operator delete(this->unk30);
    operator delete(this->unk34);
    operator delete(this->unk38);
    operator delete(this->unk48);
    operator delete(this->unk4C);
    operator delete(this->unk50);
    temp_r3_1723 = this->unk3C;
    if (temp_r3_1723 != NULL) {
        operator delete(temp_r3_1723);
    }
    temp_r3_1728 = this->unk40;
    if (temp_r3_1728 != NULL) {
        operator delete(temp_r3_1728);
    }
    temp_r3_1733 = this->unk44;
    if (temp_r3_1733 != NULL) {
        operator delete(temp_r3_1733);
    }
    temp_r31_1738 = this->unk1C;
    if (temp_r31_1738 != NULL) {
        temp_r3_1741 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_1741 != NULL) {
            ((MKHeap *) (temp_r3_1741->Current()))->Free(temp_r31_1738, NULL, 0);
        } else {
            free(temp_r31_1738);
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
void DojoGoal_Think::Init(Enemy *arg0) {
    Goal<Enemy> *temp_r4_2108;
    Goal<Enemy> *temp_r4_2131;
    Goal<Enemy> *temp_r4_2145;
    Goal<Enemy> *temp_r4_2156;
    Goal<Enemy> *temp_r4_2204;
    MKHeap *temp_r3_2081;
    void **temp_r3_2192;
    void **temp_r4_2171;
    void *var_r3_2088;

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
        this->unk24 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x30U, NULL, 0);
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
        this->unk30 = M2C_ERROR(/* Read from unset register $r3 */);
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
        this->unk34 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x10U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk38 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x98U, NULL, 0);
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
        this->unk48 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x10U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk4C = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x34U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk50 = M2C_ERROR(/* Read from unset register $r3 */);
        this->unk3C = NULL;
        if ((SpawnerObject *) arg0->unkA4C != NULL) {
            operator new(0x1CU, NULL, 0);
            if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
                *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
                *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
            }
            this->unk3C = M2C_ERROR(/* Read from unset register $r3 */);
        }
        if (arg0->CanCustomSpawn() != 0) {
            operator new(0x14U, NULL, 0);
            if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
                *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
                *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
            }
            this->unk40 = M2C_ERROR(/* Read from unset register $r3 */);
            operator new(0x10U, NULL, 0);
            if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
                *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
                *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
            }
            this->unk44 = M2C_ERROR(/* Read from unset register $r3 */);
        } else {
            this->unk40 = NULL;
            this->unk44 = NULL;
        }
    }
    if ((u8) this->unk9 == 0) {
        temp_r3_2081 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_2081 != NULL) {
            var_r3_2088 = ((MKHeap *) (temp_r3_2081->Current()))->Alloc(0xC, NULL, 0);
        } else {
            var_r3_2088 = malloc(0xC);
        }
        this->unk1C = var_r3_2088;
        this->unk10 = 3;
    }
    this->unk8 = 1;
    this->unkC = arg0;
    this->unk4 = 0x60;
    if ((Enemy *) this->unkC != NULL) {
        this->unk9 = 1;
    }
    temp_r4_2108 = this->unk24;
    M2C_FIELD(temp_r4_2108, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_2108, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_2108, s32 *, 4) = 0;
    if ((Enemy *) M2C_FIELD(temp_r4_2108, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_2108, s8 *, 9) = 1;
    }
    ((EnemyGoal_PatrolMode *) this->unk28)->Init(arg0);
    ((EnemyGoal_AlertMode *) this->unk2C)->Init(arg0);
    ((EnemyGoal_Hit *) this->unk30)->Init(arg0);
    ((EnemyGoal_Death *) this->unk34)->Init(arg0);
    temp_r4_2131 = this->unk38;
    M2C_FIELD(temp_r4_2131, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_2131, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_2131, s32 *, 4) = 0x1E;
    if ((Enemy *) M2C_FIELD(temp_r4_2131, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_2131, s8 *, 9) = 1;
    }
    ((EnemyGoal_FollowGraph *) this->unk48)->Init(arg0);
    temp_r4_2145 = this->unk4C;
    M2C_FIELD(temp_r4_2145, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_2145, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_2145, s32 *, 4) = 0x4D;
    if ((Enemy *) M2C_FIELD(temp_r4_2145, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_2145, s8 *, 9) = 1;
    }
    temp_r4_2156 = this->unk50;
    M2C_FIELD(temp_r4_2156, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_2156, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_2156, s32 *, 4) = 0x21;
    if ((Enemy *) M2C_FIELD(temp_r4_2156, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_2156, s8 *, 9) = 1;
    }
    M2C_FIELD(temp_r4_2156, u8 *, 0x30) = (u8) (M2C_FIELD(temp_r4_2156, u8 *, 0x30) & ~0x10);
    temp_r4_2171 = this->unk3C;
    if (temp_r4_2171 != NULL) {
        M2C_FIELD(temp_r4_2171, s8 *, 8) = 1;
        M2C_FIELD(temp_r4_2171, Enemy **, 0xC) = arg0;
        M2C_FIELD(temp_r4_2171, s32 *, 4) = 0x4A;
        if ((Enemy *) M2C_FIELD(temp_r4_2171, Enemy **, 0xC) != NULL) {
            M2C_FIELD(temp_r4_2171, s8 *, 9) = 1;
        }
        M2C_FIELD(temp_r4_2171, s32 *, 0x14) = 3;
        M2C_FIELD(temp_r4_2171, s32 *, 0x10) = 0;
        SetSummonGoal__19EnemyGoal_AlertModeFP12Goal<5Enemy>((EnemyGoal_AlertMode *) this->unk2C, (Goal<Enemy> *) this->unk3C);
    }
    temp_r3_2192 = this->unk40;
    if (temp_r3_2192 != NULL) {
        M2C_FIELD(*temp_r3_2192, M2C_UNK (**)(Enemy *, M2C_UNK, M2C_UNK *), 8)(arg0, 0x38, "DojoDummy_Spawn");
    }
    temp_r4_2204 = this->unk44;
    if (temp_r4_2204 != NULL) {
        M2C_FIELD(temp_r4_2204, s8 *, 8) = 1;
        M2C_FIELD(temp_r4_2204, Enemy **, 0xC) = arg0;
        M2C_FIELD(temp_r4_2204, s32 *, 4) = 0x39;
        if ((Enemy *) M2C_FIELD(temp_r4_2204, Enemy **, 0xC) != NULL) {
            M2C_FIELD(temp_r4_2204, s8 *, 9) = 1;
        }
    }
    this->unk54 &= ~0x20;
    this->unk54 &= ~0x40;
    this->unk54 &= ~0x80;
    this->unk54 &= ~0x10;
    this->unk20 = checked_cast<DojoEnemy *, Enemy>(arg0);
}
#endif
