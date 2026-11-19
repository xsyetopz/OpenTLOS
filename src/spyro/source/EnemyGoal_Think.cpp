#include "spyro/source/EnemyGoal_Think.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "spyro/source/AITargetData.h"
#include "spyro/source/Enemy.h"
#include "spyro/source/EnemyAttackPattern.h"
#include "spyro/source/EnemyDataTypes.h"
#include "spyro/source/EnemyDescriptor.h"
#include "spyro/source/EnemyGoal_AlertMode.h"
#include "spyro/source/EnemyGoal_FollowGraph.h"
#include "spyro/source/EnemyGoal_GroundAttackMode.h"
#include "spyro/source/EnemyGoals.h"
#include "spyro/source/EnemyGoals_Death.h"
#include "spyro/source/EnemyGoals_Hit.h"
#include "spyro/source/EnemyGoals_Movement.h"
#include "spyro/source/EnemyRegion.h"
#include "spyro/source/ExplosiveBarrelPath.h"
#include "spyro/source/KDPath.h"
#include "spyro/source/Lever.h"
#include "spyro/source/SpyroHud.h"
#include "spyro/source/TargetManager.h"
#include "unplaced_enums.h"
#include "common/Source/MKCollision.h"
#include <m2c_macros.h>

M2C_UNK free(s32);                                  /* extern */
void *malloc(s32);                                  /* extern */
extern void **gMK;
extern void **gb;

#if 0 // DRAFT: illegal implicit conversion from 'long' to
void EnemyGoal_Think::RemoveAllInactiveSubgoals(int arg0) {
    s32 temp_r0_154;
    s32 temp_r3_114;
    s32 temp_r3_135;
    s32 temp_r3_155;
    s32 temp_r3_87;
    s32 temp_r4_113;
    s32 temp_r4_123;
    s32 temp_r4_141;
    s32 temp_r4_167;
    s32 temp_r4_96;
    s32 var_r0_124;
    s32 var_r0_168;
    s32 var_r0_97;
    u32 *var_r3_119;
    u32 var_r31_84;
    void ***var_r3_92;
    void **temp_r3_106;

    var_r31_84 = 0U;
loop_17:
    temp_r4_141 = this->unk14;
    if (temp_r4_141 > 1) {
        temp_r3_87 = temp_r4_141 - 1;
        if ((temp_r3_87 < 0) || (temp_r3_87 >= temp_r4_141)) {
            var_r3_92 = NULL;
        } else {
            temp_r4_96 = this->unk10;
            var_r0_97 = this->unk18 + temp_r3_87;
            if (var_r0_97 >= temp_r4_96) {
                var_r0_97 -= temp_r4_96;
            }
            var_r3_92 = this->unk1C + (var_r0_97 * 4);
        }
        temp_r3_106 = *var_r3_92;
        if (arg0 == M2C_FIELD(*temp_r3_106, s32 (**)(void **), 0x34)(temp_r3_106)) {
            temp_r4_113 = this->unk14;
            temp_r3_114 = temp_r4_113 - 1;
            if ((temp_r3_114 < 0) || (temp_r3_114 >= temp_r4_113)) {
                var_r3_119 = NULL;
            } else {
                temp_r4_123 = this->unk10;
                var_r0_124 = this->unk18 + temp_r3_114;
                if (var_r0_124 >= temp_r4_123) {
                    var_r0_124 -= temp_r4_123;
                }
                var_r3_119 = this->unk1C + (var_r0_124 * 4);
            }
            var_r31_84 = *var_r3_119;
        }
        temp_r3_135 = this->unk14;
        if (temp_r3_135 > 0) {
            this->unk14 = temp_r3_135 - 1;
        }
        goto loop_17;
    }
    if (var_r31_84 != 0U) {
        if ((temp_r4_141 == (s32) this->unk10) && (temp_r4_141 > 0)) {
            this->unk18 += 1;
            temp_r0_154 = this->unk18;
            temp_r3_155 = this->unk10;
            if (temp_r0_154 >= temp_r3_155) {
                this->unk18 = temp_r0_154 - temp_r3_155;
            }
            this->unk14 -= 1;
        }
        temp_r4_167 = this->unk10;
        var_r0_168 = this->unk18 + this->unk14;
        if (var_r0_168 >= temp_r4_167) {
            var_r0_168 -= temp_r4_167;
        }
        this->unk14 += 1;
        *(this->unk1C + (var_r0_168 * 4)) = var_r31_84;
    }
}
#endif

void EnemyGoal_Think::SetFollowSpawnPathParams(AnimSequenceType arg0, int arg1) {
    this->unk68 = (AITargetData *) arg0;
    this->unk6C = arg1;
}

void EnemyGoal_Think::SetSpawnGoal(Goal<Enemy> *arg0) {
    this->unk48 = (Goal<Enemy> *) arg0;
}

#if 0 // DRAFT: illegal operands 'void' == 'int'
void EnemyGoal_Think::AddGoal_Frozen() {
    s32 temp_r3_226;

    if (((Goal<Enemy> *) this->unk4C != NULL) && (IsPresent(6) == 0)) {
        RemoveAllSubgoals();
        AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk4C);
    }
    temp_r3_226 = this->unkC;
    M2C_FIELD(temp_r3_226, u8 *, 0xB01) = (u8) (M2C_FIELD(temp_r3_226, u8 *, 0xB01) & ~1);
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void EnemyGoal_Think::AddGoal_Spawn() {
    Goal<Enemy> *temp_r3_246;

    temp_r3_246 = this->unk48;
    if ((temp_r3_246 != NULL) && (IsPresent(M2C_FIELD(temp_r3_246->__vptr, s32 (**)(), 0x34)()) == 0)) {
        this->unk70 |= 0x80;
        RemoveAllSubgoals();
        AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk48);
    }
}
#endif

#if 0 // DRAFT: illegal operands 'void' != 'int'
u8 EnemyGoal_Think::Try_AddGoal_Kong() {
    MKProp *sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    void *temp_r4_290;

    if ((Goal<Enemy> *) this->unk40 != NULL) {
        temp_r4_290 = M2C_FIELD(this->unkC, void **, 0xA44);
        if ((temp_r4_290 != NULL) && (M2C_FIELD(temp_r4_290, s32 *, 4) & 0x10)) {
            if (IsPresent(0x48) != 0) {
                return 1U;
            }
            spC = 0;
            sp8 = 0x79;
            sp14 = NULL;
            sp10 = 1;
            M2C_FIELD(*gMK, M2C_UNK (**)(void **, s32 *, M2C_UNK, M2C_UNK, s32, M2C_UNK, f32), 0x94)(gMK, &sp8, 0x800, 0, M2C_FIELD(this->unkC, s32 *, 8) + 0x30, 0, 1000.0f);
            if (sp14 != NULL) {
                AddGoal_Kong(sp14);
                return 1U;
            }
            goto block_7;
        }
    }
block_7:
    return 0U;
}
#endif

#if 0 // DRAFT: illegal operands 'void' != 'int'
u8 EnemyGoal_Think::Try_AddGoal_OperateLever() {
    MKProp *sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    s32 temp_r3_377;
    void *temp_r4_355;

    if ((Goal<Enemy> *) this->unk3C != NULL) {
        temp_r4_355 = M2C_FIELD(this->unkC, void **, 0xA44);
        if ((temp_r4_355 != NULL) && (M2C_FIELD(temp_r4_355, s32 *, 4) & 8)) {
            if (IsPresent(0x47) != 0) {
                return 1U;
            }
            spC = 0;
            sp8 = 0x79;
            sp14 = NULL;
            sp10 = 0;
            temp_r3_377 = this->unkC;
            M2C_FIELD(*gMK, M2C_UNK (**)(void **, s32 *, M2C_UNK, M2C_UNK, s32, M2C_UNK, f32), 0x94)(gMK, &sp8, 0x800, 1, M2C_FIELD(M2C_FIELD(M2C_FIELD(temp_r3_377, void **, 0x44), void *(**)(s32), 0xD0)(temp_r3_377), s32 *, 8) + 0x30, 1, 1500.0f);
            if (sp14 != NULL) {
                AddGoal_OperateLever(sp14);
                return 1U;
            }
            goto block_7;
        }
    }
block_7:
    return 0U;
}
#endif

void EnemyGoal_Think::StartFollowingSpawnGraph() {
    s32 temp_r4_418;

    if (!(((u8) this->unk70 >> 5U) & 1)) {
        temp_r4_418 = this->unkC;
        M2C_FIELD(temp_r4_418, u8 *, 0xB09) = (u8) (M2C_FIELD(temp_r4_418, u8 *, 0xB09) | 8);
        this->unk70 |= 0x20;
    }
}

#if 0 // DRAFT: undefined identifier '__vptr'
void EnemyGoal_Think::StopFollowingSpawnGraph() {
    s32 temp_r3_451;
    s32 temp_r5_439;

    temp_r5_439 = this->unkC;
    M2C_FIELD(temp_r5_439, u8 *, 0xB09) = (u8) (M2C_FIELD(temp_r5_439, u8 *, 0xB09) & ~8);
    if (M2C_FIELD(this->__vptr, u8 (**)(M2C_UNK, s32, M2C_UNK), 0x38)(0x2A, temp_r5_439, 0) != 0) {
        RemoveAllSubgoals();
        temp_r3_451 = this->unkC;
        ((Enemy *) temp_r3_451)->SetupEnemyRegion(*(temp_r3_451 + 0x588), 1000.0f);
    }
}
#endif

u8 EnemyGoal_Think::IsFollowingSpawnGraph() {
    return ((u8) M2C_FIELD(this->unkC, u8 *, 0xB09) >> 3U) & 1;
}

void EnemyGoal_Think::StartFollowingSpawnPath() {
    s32 temp_r4_478;

    if (!(((u8) this->unk70 >> 6U) & 1)) {
        temp_r4_478 = this->unkC;
        M2C_FIELD(temp_r4_478, u8 *, 0xB09) = (u8) (M2C_FIELD(temp_r4_478, u8 *, 0xB09) | 0x10);
        this->unk70 |= 0x40;
    }
}

#if 0 // DRAFT: undefined identifier '__vptr'
void EnemyGoal_Think::StopFollowingSpawnPath() {
    s32 temp_r3_511;
    s32 temp_r5_499;

    temp_r5_499 = this->unkC;
    M2C_FIELD(temp_r5_499, u8 *, 0xB09) = (u8) (M2C_FIELD(temp_r5_499, u8 *, 0xB09) & ~0x10);
    if (M2C_FIELD(this->__vptr, u8 (**)(M2C_UNK, s32, M2C_UNK), 0x38)(0x22, temp_r5_499, 0) != 0) {
        RemoveAllSubgoals();
        temp_r3_511 = this->unkC;
        ((Enemy *) temp_r3_511)->SetupEnemyRegion(*(temp_r3_511 + 0x588), 1000.0f);
    }
}
#endif

u8 EnemyGoal_Think::IsFollowingSpawnPath() {
    return ((u8) M2C_FIELD(this->unkC, u8 *, 0xB09) >> 4U) & 1;
}

#if 0 // DRAFT: illegal operands 'void' == 'int'
void EnemyGoal_Think::AddGoal_Kong(MKProp *arg0) {
    if (IsPresent(0x48) == 0) {
        RemoveAllSubgoals();
        AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk40);
        ((EnemyGoal_Kong *) this->unk40)->SetParams((ExplosiveBarrelPath *) arg0);
    }
}
#endif

#if 0 // DRAFT: illegal operands 'void' == 'int'
void EnemyGoal_Think::AddGoal_OperateLever(MKProp *arg0) {
    if (IsPresent(0x47) == 0) {
        RemoveAllSubgoals();
        AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk3C);
        ((EnemyGoal_OperateLever *) this->unk3C)->SetParams((Lever *) arg0);
    }
}
#endif

#if 0 // DRAFT: illegal operands 'void' == 'int'
void EnemyGoal_Think::AddGoal_FollowSpawnGraph() {
    s32 temp_r3_616;
    s32 temp_r3_621;

    if (IsPresent(0x2A) == 0) {
        RemoveAllSubgoals();
        AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk50);
        temp_r3_616 = this->unkC;
        M2C_FIELD(temp_r3_616, u8 *, 0xB09) = (u8) (M2C_FIELD(temp_r3_616, u8 *, 0xB09) | 8);
        temp_r3_621 = this->unkC;
        M2C_FIELD(temp_r3_621, u8 *, 0xB08) = (u8) (M2C_FIELD(temp_r3_621, u8 *, 0xB08) | 0x40);
    }
}
#endif

#if 0 // DRAFT: illegal operands 'void' == 'int'
void EnemyGoal_Think::AddGoal_FollowSpawnPath() {
    Goal<Enemy> *temp_r6_658;
    s32 temp_r3_678;
    s32 temp_r3_682;

    if (IsPresent(0x22) == 0) {
        RemoveAllSubgoals();
        AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk38);
        temp_r6_658 = this->unk38;
        M2C_FIELD(temp_r6_658, s32 *, 0x10) = (s32) M2C_FIELD(this->unkC, s32 *, 0xA94);
        M2C_FIELD(temp_r6_658, f32 *, 0x14) = 0.0f;
        M2C_FIELD(temp_r6_658, s32 *, 0x18) = 1;
        M2C_FIELD(temp_r6_658, AITargetData **, 0x20) = (AITargetData *) this->unk68;
        M2C_FIELD(temp_r6_658, s32 *, 0x1C) = (s32) this->unk6C;
        M2C_FIELD(temp_r6_658, u8 *, 0x24) = (u8) (M2C_FIELD(temp_r6_658, u8 *, 0x24) & ~0x20);
        M2C_FIELD(temp_r6_658, u8 *, 0x24) = (u8) (M2C_FIELD(temp_r6_658, u8 *, 0x24) & ~0x10);
        M2C_FIELD(temp_r6_658, u8 *, 0x24) = (u8) (M2C_FIELD(temp_r6_658, u8 *, 0x24) & ~8);
        M2C_FIELD(temp_r6_658, u8 *, 0x24) = (u8) (M2C_FIELD(temp_r6_658, u8 *, 0x24) & ~4);
        temp_r3_678 = this->unkC;
        M2C_FIELD(temp_r3_678, u8 *, 0xB09) = (u8) (M2C_FIELD(temp_r3_678, u8 *, 0xB09) | 0x10);
        temp_r3_682 = this->unkC;
        M2C_FIELD(temp_r3_682, u8 *, 0xB08) = (u8) (M2C_FIELD(temp_r3_682, u8 *, 0xB08) | 0x40);
        ((KDPathIterator *) (this->unkC + 0xA94))->Init();
    }
}
#endif

#if 0 // DRAFT: illegal operands 'void' == 'int'
void EnemyGoal_Think::AddGoal_Panic() {
    if (IsPresent(0x26) == 0) {
        RemoveAllSubgoals();
        AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk34);
    }
}
#endif

#if 0 // DRAFT: illegal operands 'void' == 'int'
void EnemyGoal_Think::AddGoal_ReceiveOrders() {
    if (IsPresent(0x4D) == 0) {
        RemoveAllSubgoals();
        AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk54);
    }
}
#endif

#if 0 // DRAFT: illegal operands 'void' == 'int'
void EnemyGoal_Think::AddGoal_Respawn() {
    if (IsPresent(0x1E) == 0) {
        RemoveAllSubgoals();
        AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk30);
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void' to
void EnemyGoal_Think::AddGoal_Death(EnemyDamageFeedback *arg0) {
    s32 temp_r0_796;
    s32 temp_r0_875;
    s32 temp_r0_975;
    s32 temp_r3_816;
    s32 temp_r4_983;
    u8 temp_r28_797;
    u8 var_r28_920;
    u8 var_r29_790;
    u8 var_r29_823;
    u8 var_r31_890;

    var_r29_790 = 0;
    temp_r0_796 = arg0->unk28;
    temp_r28_797 = IsActive(0x29);
    if (temp_r0_796 == 6) {
        if (IsActive(0x11) == 0) {
            AddGoal_Hit(arg0);
            var_r29_790 = 1;
        }
    } else {
        if (temp_r0_796 == 0xC) {
            temp_r3_816 = this->unkC;
            M2C_FIELD(temp_r3_816, u8 *, 0xB0A) = (u8) (M2C_FIELD(temp_r3_816, u8 *, 0xB0A) | 8);
        }
        var_r29_823 = 0;
        if ((IsActive(0x11) == 0) && ((IsActive(0xB) != 0) || (IsActive(0x13) != 0) || (IsActive(0xC) != 0) || (temp_r28_797 != 0))) {
            var_r29_823 = 1;
        }
        if (var_r29_823 != 0) {
            if (temp_r28_797 != 0) {
                arg0->unk28 = 3;
                RemoveAllSubgoals();
            }
            AddGoal_Hit(arg0);
            var_r29_790 = 1;
        } else {
            temp_r0_875 = arg0->unk28;
            if ((temp_r0_875 == 2) || (temp_r0_875 == 8) || (temp_r0_875 == 0xA)) {
                AddGoal_Hit(arg0);
                var_r29_790 = 1;
            } else {
                var_r31_890 = 0;
                if ((IsActive(0xC) != 0) || (IsActive(0xD) != 0)) {
                    var_r31_890 = 1;
                }
                var_r29_790 = var_r31_890;
            }
        }
    }
    if (IsPresent(0x5B) == 0) {
        var_r28_920 = 0;
        if ((IsActive(0x2E) != 0) || (IsActive(0x2F) != 0) || (IsActive(0x31) != 0) || (IsActive(0x92) != 0) || (IsActive(0x8F) != 0)) {
            var_r28_920 = 1;
        }
        if ((var_r29_790 != 0) && (var_r28_920 == 0)) {
loop_35:
            temp_r0_975 = this->unk14;
            if (temp_r0_975 > 1) {
                if (temp_r0_975 > 0) {
                    this->unk14 -= 1;
                }
                goto loop_35;
            }
        } else {
            RemoveAllSubgoals();
        }
        temp_r4_983 = this->unkC;
        M2C_FIELD(temp_r4_983, u8 *, 0x6B5) = (u8) ((M2C_FIELD(temp_r4_983, u8 *, 0x6B5) & ~0x10) | ((var_r28_920 << 4) & 0x10));
        AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk2C);
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void' to
void EnemyGoal_Think::AddGoal_Hit(EnemyDamageFeedback *arg0) {
    f32 var_f31_1013;
    s32 temp_r0_1141;
    s32 temp_r0_1191;
    s32 temp_r0_1280;
    s32 temp_r3_1185;
    s32 temp_r3_1231;
    s32 temp_r3_1249;
    s32 temp_r3_1281;
    s32 temp_r4_1086;
    s32 temp_r4_1302;
    s32 temp_r5_1205;
    s32 var_r25_1010;
    u8 temp_r19_1023;
    u8 temp_r20_1030;
    u8 temp_r21_1037;
    u8 temp_r22_1044;
    u8 temp_r26_1016;
    u8 temp_r27_1051;
    u8 temp_r28_1058;
    u8 temp_r29_1065;
    u8 temp_r30_1072;
    u8 temp_r31_1079;
    u8 temp_r3_1085;
    void *temp_r3_1163;

    var_r25_1010 = arg0->unk28;
    var_f31_1013 = 0.0f;
    temp_r26_1016 = IsActive(8);
    temp_r19_1023 = IsActive(0xB);
    temp_r20_1030 = IsActive(0xE);
    temp_r21_1037 = IsActive(0xC);
    temp_r22_1044 = IsActive(0x13);
    temp_r27_1051 = IsActive(0x12);
    temp_r28_1058 = IsActive(0xD);
    temp_r29_1065 = IsActive(0x26);
    temp_r30_1072 = IsActive(0x3B);
    temp_r31_1079 = IsActive(6);
    temp_r3_1085 = IsActive(0x29);
    temp_r4_1086 = this->unkC;
    if ((((u8) M2C_FIELD(temp_r4_1086, u8 *, 0x6B5) >> 4U) & 1) && ((var_r25_1010 == 1) || (var_r25_1010 == 0))) {
        var_r25_1010 = 0xE;
    } else if ((temp_r19_1023 != 0) || (temp_r22_1044 != 0) || (temp_r3_1085 != 0)) {
        switch (var_r25_1010) {
        case 4:
        case 5:
        case 7:
        case 9:
        case 11:
            if (var_r25_1010 != 0xB) {
                ((Enemy *) temp_r4_1086)->ThawIfFrozen();
            }
            var_r25_1010 = 9;
            break;
        case 10:
            var_f31_1013 = 3000.0f;
            break;
        default:
            var_f31_1013 = 500.0f;
            var_r25_1010 = 3;
            break;
        }
    } else if (((temp_r21_1037 != 0) || (temp_r20_1030 != 0)) && (((u32) (var_r25_1010 - 4) <= 1U) || (var_r25_1010 == 2)) && (temp_r0_1141 = arg0->unk20, (((u32) temp_r0_1141 == 8U) == 0)) && (var_r25_1010 != 2) && ((u32) temp_r0_1141 != 0x20U) && (var_r25_1010 != 8)) {
        var_r25_1010 = 0xE;
    } else if (var_r25_1010 == 9) {
        var_r25_1010 = 1;
    } else if (var_r25_1010 == 0xA) {
        var_r25_1010 = 8;
    }
    temp_r3_1163 = M2C_FIELD(this->unkC, void **, 0xA00);
    if ((((temp_r3_1163 != NULL) && ((u8) M2C_FIELD(temp_r3_1163, u8 *, 0x20) != 0)) || (temp_r31_1079 != 0)) && ((temp_r31_1079 != 0) || (arg0->unk20 & 0x47F1))) {
        RemoveAllSubgoals();
    }
    if (var_r25_1010 == 9) {
        temp_r3_1185 = M2C_FIELD(this->unkC, s32 *, 0xAF4);
        if ((temp_r3_1185 >= 3) && !(arg0->unk20 & 8) && (((temp_r0_1191 = arg0->unk28, ((temp_r0_1191 == 4) == 0)) && (temp_r0_1191 != 5)) || (temp_r3_1185 >= 6))) {
            var_r25_1010 = 0xE;
        }
    }
    if ((((u8) arg0->unk34 >> 4U) & 1) && (temp_r5_1205 = this->unkC, ((M2C_FIELD(temp_r5_1205, f32 *, 0xACC) <= 0.0f) != 0)) && ((var_r25_1010 == 0) || ((u32) (var_r25_1010 - 4) <= 1U) || (((EnemyDescriptor *) (M2C_FIELD(temp_r5_1205, EnemyDescriptor **, 0xA38)))->GetAnimSequence(2, 0x2A, M2C_FIELD(temp_r5_1205, s32 *, 0xAE4), NULL) == NULL))) {
        var_r25_1010 = 7;
    } else if (((u8) arg0->unk34 >> 4U) & 1) {
        temp_r3_1231 = this->unkC;
        if (M2C_FIELD(temp_r3_1231, f32 *, 0xACC) <= 0.0f) {
            ((Enemy *) temp_r3_1231)->Armour_Destroy();
        }
    }
    if (var_r25_1010 != 0xE) {
        if (IsActive(0x59) != 0) {
            temp_r3_1249 = arg0->unk20;
            if ((!(temp_r3_1249 & 4) || ((s32) arg0->unk2C != 1)) && (!(temp_r3_1249 & 8) || (var_r25_1010 != 2))) {
                if ((var_r25_1010 != 0) && ((var_r25_1010 != 1) || (temp_r26_1016 != 0)) && (temp_r27_1051 == 0)) {
                    if (temp_r28_1058 != 0) {
                        return;
                    }
                    goto block_61;
                }
            } else {
block_61:
                if ((s32) this->unk14 > 0) {
                    this->unk18 += 1;
                    temp_r0_1280 = this->unk18;
                    temp_r3_1281 = this->unk10;
                    if (temp_r0_1280 >= temp_r3_1281) {
                        this->unk18 = temp_r0_1280 - temp_r3_1281;
                    }
                    this->unk14 -= 1;
                }
                goto block_65;
            }
        } else {
block_65:
            if ((temp_r29_1065 != 0) || (temp_r30_1072 != 0)) {
                RemoveAllSubgoals();
            }
            arg0->unk28 = var_r25_1010;
            arg0->unk18 = var_f31_1013;
            temp_r4_1302 = this->unkC;
            M2C_FIELD(temp_r4_1302, f64 *, 0x910) = (f64) arg0->unk0;
            M2C_FIELD(temp_r4_1302, f64 *, 0x918) = (f64) arg0->unk8;
            M2C_FIELD(temp_r4_1302, s32 *, 0x920) = (s32) arg0->unk10;
            M2C_FIELD(temp_r4_1302, s32 *, 0x924) = (s32) arg0->unk14;
            M2C_FIELD(temp_r4_1302, f32 *, 0x928) = (f32) arg0->unk18;
            M2C_FIELD(temp_r4_1302, f32 *, 0x92C) = (f32) arg0->unk1C;
            M2C_FIELD(temp_r4_1302, s32 *, 0x930) = (s32) arg0->unk20;
            M2C_FIELD(temp_r4_1302, f32 *, 0x934) = (f32) arg0->unk24;
            M2C_FIELD(temp_r4_1302, s32 *, 0x938) = (s32) arg0->unk28;
            M2C_FIELD(temp_r4_1302, s32 *, 0x93C) = (s32) arg0->unk2C;
            M2C_FIELD(temp_r4_1302, s32 *, 0x940) = (s32) arg0->unk30;
            M2C_FIELD(temp_r4_1302, u8 *, 0x944) = (u8) arg0->unk34;
            AddSubgoalToFront__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk28);
        }
    }
}
#endif

#if 0 // DRAFT: illegal operands 'void' == 'int'
void EnemyGoal_Think::AddGoal_Strafe() {
    Goal<Enemy> *temp_r4_1361;

    if (IsPresent(0x20) == 0) {
        RemoveAllSubgoals();
        AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk5C);
        temp_r4_1361 = this->unk5C;
        M2C_FIELD(temp_r4_1361, s8 *, 0x14) = (s8) (M2C_FIELD(this->unkC, s32 *, 0xAFC) == 0x19);
        M2C_FIELD(temp_r4_1361, s32 *, 0x10) = 0;
    }
}
#endif

#if 0 // DRAFT: pointer/array required
u8 EnemyGoal_Think::AddGoal_MoveToLastPlayerPos() {
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
    Goal<Enemy> *temp_r8_1624;
    MKVector3 *temp_r30_1567;
    f32 temp_f1_1512;
    f32 temp_f1_1621;
    f32 temp_f2_1515;
    f32 temp_f31_1415;
    f64 temp_f0_1430;
    f64 temp_f0_1527;
    s32 temp_r28_1565;
    s32 temp_r3_1386;
    s32 temp_r3_1420;
    s32 temp_r3_1449;
    s32 temp_r3_1508;
    s32 temp_r3_1516;
    s32 temp_r3_1617;
    s32 temp_r4_1589;
    s32 temp_r4_1595;
    s32 temp_r4_1602;
    u8 var_r0_1390;
    u8 var_r29_1566;
    u8 var_r30_1450;
    u8 var_r30_1496;
    void *temp_r4_1440;
    void *temp_r4_1537;

    temp_r3_1386 = this->unkC;
    var_r0_1390 = 0;
    if ((M2C_FIELD(temp_r3_1386, f32 *, 0x720) == MKVector3::zero.unk0) && (M2C_FIELD(temp_r3_1386, f32 *, 0x724) == MKVector3::zero.unk4) && (M2C_FIELD(temp_r3_1386, f32 *, 0x728) == MKVector3::zero.unk8)) {
        var_r0_1390 = 1;
    }
    if (var_r0_1390 != 0) {
        return 0U;
    }
    if (((u8) this->unk70 >> 4U) & 1) {
        temp_f31_1415 = M2C_FIELD(M2C_FIELD(temp_r3_1386, void **, 0x44), f32 (**)(), 0x100)();
        sp60 = 0.0f;
        temp_r3_1420 = this->unkC;
        sp58 = 0.0f;
        sp5C = 50.0f + temp_f31_1415;
        sp80 = (f64) sp60;
        sp78 = (f64) sp58;
        temp_f0_1430 = *(temp_r3_1420 + 0x720) + (f64) sp58;
        sp48 = temp_f0_1430;
        spB8 = temp_f0_1430;
        sp50 = M2C_FIELD(temp_r3_1420, f32 *, 0x728) + (f32) sp80;
        spC0 = (f64) sp50;
        temp_r4_1440 = M2C_FIELD(temp_r3_1420, void **, 0x634);
        sp10 = temp_r4_1440;
        if (temp_r4_1440 != NULL) {
            sp14 = M2C_FIELD(temp_r4_1440, u8 *, 4);
            M2C_FIELD(temp_r4_1440, u8 *, 4) = 0U;
        }
        temp_r3_1449 = this->unkC;
        var_r30_1450 = 0;
        if (((u8) M2C_FIELD(temp_r3_1449, u8 *, 0x8B8) == 2) || (((TargetContext *) (temp_r3_1449 + 0x8B0))->Get() != NULL)) {
            var_r30_1450 = 1;
        }
        if ((var_r30_1450 == 0) || (MKCollision_SphereCollide(*((MKVector3 *) &spB8), temp_f31_1415, NULL, 0, (MKCollisionMode) 7, 0x04000000) != 0)) {
            RemoveAllSubgoals();
            this->unk70 &= ~0x10;
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
    var_r30_1496 = 0;
    if (((u8) M2C_FIELD(temp_r3_1386, u8 *, 0x8B8) == 2) || (((TargetContext *) (temp_r3_1386 + 0x8B0))->Get() != NULL)) {
        var_r30_1496 = 1;
    }
    if (var_r30_1496 != 0) {
        temp_r3_1508 = this->unkC;
        temp_f1_1512 = M2C_FIELD(M2C_FIELD(temp_r3_1508, void **, 0x44), f32 (**)(s32), 0x100)(temp_r3_1508);
        temp_f2_1515 = 50.0f + temp_f1_1512;
        temp_r3_1516 = this->unkC;
        sp40 = 0.0f;
        sp38 = 0.0f;
        sp3C = temp_f2_1515;
        sp70 = (f64) sp40;
        sp68 = (f64) sp38;
        temp_f0_1527 = *(temp_r3_1516 + 0x720) + (f64) sp38;
        sp28 = temp_f0_1527;
        spA8 = temp_f0_1527;
        sp30 = M2C_FIELD(temp_r3_1516, f32 *, 0x728) + (f32) sp70;
        spB0 = (f64) sp30;
        temp_r4_1537 = M2C_FIELD(temp_r3_1516, void **, 0x634);
        sp8 = temp_r4_1537;
        if (temp_r4_1537 != NULL) {
            spC = M2C_FIELD(temp_r4_1537, u8 *, 4);
            M2C_FIELD(temp_r4_1537, u8 *, 4) = 0U;
        }
        if (MKCollision_SphereCollide(*((MKVector3 *) &spA8), temp_f1_1512, NULL, 0, (MKCollisionMode) 7, 0x04000000) != 0) {
            if (sp8 != NULL) {
                M2C_FIELD(sp8, u8 *, 4) = spC;
            }
            return 0U;
        }
        RemoveAllSubgoals();
        temp_r28_1565 = this->unkC;
        var_r29_1566 = 0;
        temp_r30_1567 = temp_r28_1565 + 0x720;
        if (((EnemyRegion *) (temp_r28_1565 + 0x800))->IsPointWithin(*temp_r30_1567) != 0) {
            ((EnemyRegion *) &sp18)->GetRegionPos();
            if ((f32) fabs(sp1C - temp_r30_1567->unk4) <= 500.0f) {
                var_r29_1566 = 1;
            }
        }
        if ((var_r29_1566 != 0) && (temp_r4_1589 = this->unkC, ((((EnemyRegion *) (temp_r4_1589 + 0x838))->IsPointWithin(*(temp_r4_1589 + 0x720)) == 0) != 0))) {
            temp_r4_1595 = this->unkC;
            ((AITargetData *) (temp_r4_1595 + 0x8C0))->Set(*(temp_r4_1595 + 0x720), 0U);
        } else {
            temp_r4_1602 = this->unkC;
            ((EnemyRegion *) (temp_r4_1602 + 0x800))->GetNearestPointOnBoundingRegion(*(temp_r4_1602 + 0x720), &sp98, &sp88);
            ((AITargetData *) (this->unkC + 0x8C0))->Set(sp98, 0U);
        }
        AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk58);
        temp_r3_1617 = this->unkC;
        temp_f1_1621 = M2C_FIELD(M2C_FIELD(temp_r3_1617, void **, 0x44), f32 (**)(s32), 0x100)(temp_r3_1617);
        temp_r8_1624 = this->unk58;
        M2C_FIELD(temp_r8_1624, s32 *, 0x10) = (s32) (this->unkC + 0x8C0);
        M2C_FIELD(temp_r8_1624, f32 *, 0x18) = temp_f1_1621;
        M2C_FIELD(temp_r8_1624, u8 *, 0x30) = (u8) (M2C_FIELD(temp_r8_1624, u8 *, 0x30) | 0x80);
        M2C_FIELD(temp_r8_1624, s32 *, 0x20) = 2;
        M2C_FIELD(temp_r8_1624, s32 *, 0x24) = 0;
        M2C_FIELD(temp_r8_1624, s32 *, 0x28) = -1;
        M2C_FIELD(temp_r8_1624, u8 *, 0x30) = (u8) (M2C_FIELD(temp_r8_1624, u8 *, 0x30) | 0x40);
        M2C_FIELD(temp_r8_1624, u8 *, 0x30) = (u8) (M2C_FIELD(temp_r8_1624, u8 *, 0x30) | 0x20);
        M2C_FIELD(temp_r8_1624, u8 *, 0x30) = (u8) (M2C_FIELD(temp_r8_1624, u8 *, 0x30) | 0x10);
        ((AITargetData *) (this->unkC + 0x8C0))->SetInsideRegion(1U);
        this->unk70 |= 0x10;
        if (sp8 != NULL) {
            M2C_FIELD(sp8, u8 *, 4) = spC;
        }
block_39:
        return 1U;
    }
    return 0U;
}
#endif

#if 0 // DRAFT: illegal operands 'void' == 'int'
void EnemyGoal_Think::AddGoal_GroundAttackMode() {
    Goal<Enemy> *temp_r4_1701;

    if (IsActive(0x58) == 0) {
        RemoveAllSubgoals();
        if (!(((u8) M2C_FIELD(this->unkC, u8 *, 0xB08) >> 6U) & 1)) {
            AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk60);
            temp_r4_1701 = this->unk60;
            M2C_FIELD(temp_r4_1701, s32 *, 0x10) = (s32) (this->unkC + 0x870);
            M2C_FIELD(temp_r4_1701, s32 *, 0x14) = 0;
            M2C_FIELD(temp_r4_1701, f32 *, 0x18) = 0.0f;
        }
        AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk64);
        ((EnemyGoal_GroundAttackMode *) this->unk64)->SetParams(this->unkC + 0x870, 1U, NULL);
    }
}
#endif

#if 0 // DRAFT: illegal operands 'void' == 'int'
void EnemyGoal_Think::AddGoal_AlertMode(AITargetData *arg0) {
    Goal<Enemy> *temp_r4_1746;

    if (IsPresent(0x54) == 0) {
        RemoveAllSubgoals();
        AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk24);
        temp_r4_1746 = this->unk24;
        M2C_FIELD(temp_r4_1746, AITargetData **, 0x20) = arg0;
        M2C_FIELD(temp_r4_1746, s32 *, 0x4C) = 3;
        M2C_FIELD(temp_r4_1746, u8 *, 0x50) = (u8) (M2C_FIELD(temp_r4_1746, u8 *, 0x50) | 0x80);
    }
}
#endif

#if 0 // DRAFT: illegal operands 'void' == 'int'
void EnemyGoal_Think::AddGoal_PatrolMode() {
    if (IsPresent(0x53) == 0) {
        RemoveAllSubgoals();
        AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk20);
    }
}
#endif

void EnemyGoal_Think::Reset() {
    this->unk8 = 1;
    RemoveAllSubgoals();
    this->unk70 &= ~0x80;
    this->unk70 &= ~0x40;
    this->unk70 &= ~0x20;
}

#if 0 // DRAFT: illegal operands 'void' == 'int'
void EnemyGoal_Think::ArbitrateOld() {
    f32 var_f31_1867;
    s32 temp_r3_1829;
    s32 temp_r3_1891;
    s32 temp_r3_1899;
    s32 temp_r3_1919;
    s32 temp_r3_1939;
    s32 temp_r3_1977;
    s32 temp_r4_1862;
    s32 temp_r4_1949;
    s32 temp_r4_1990;
    u8 var_r30_1874;
    void *temp_r3_1932;

    temp_r3_1829 = this->unkC;
    if (!(M2C_FIELD(temp_r3_1829, f32 *, 0xAC8) <= 0.0f) && (M2C_FIELD(M2C_FIELD(temp_r3_1829, void **, 0x44), u8 (**)(), 0x134)() == 0) && (((Enemy *) this->unkC)->IsFlinching(), (((u8) M2C_ERROR(/* Read from unset register $r3 */) == 0) != 0)) && (IsPresent(0x26) == 0)) {
        if (IsPresent(0x28) != 0) {
            return;
        }
        temp_r4_1862 = this->unkC;
        if (((u8) M2C_FIELD(temp_r4_1862, u8 *, 0xB08) >> 6U) & 1) {
            var_f31_1867 = M2C_FIELD(M2C_FIELD(temp_r4_1862, void **, 0xA38), f32 *, 0x134);
        } else {
            var_f31_1867 = M2C_FIELD(M2C_FIELD(temp_r4_1862, void **, 0xA38), f32 *, 0x12C);
        }
        var_r30_1874 = 0;
        if (((u8) M2C_FIELD(temp_r4_1862, u8 *, 0x8B8) == 2) || (((TargetContext *) (temp_r4_1862 + 0x8B0))->Get() != NULL)) {
            var_r30_1874 = 1;
        }
        if ((var_r30_1874 != 0) && (((AITargetData *) (this->unkC + 0x870))->IsAttackable() != 0) && ((temp_r3_1891 = this->unkC, (((((u8) M2C_FIELD(temp_r3_1891, u8 *, 0xB08) >> 5U) & 1) == 0) == 0)) || ((((AITargetData *) (temp_r3_1891 + 0x870))->GetDist() < var_f31_1867) && ((temp_r3_1899 = this->unkC, (((((u8) M2C_FIELD(temp_r3_1899, u8 *, 0xB08) >> 6U) & 1) == 0) == 0)) || (((u8) M2C_FIELD(temp_r3_1899, u8 *, 0x8B9) >> 4U) & 1)) && (IsFollowingSpawnPath() == 0)) || ((((AITargetData *) (this->unkC + 0x870))->GetDist() < (var_f31_1867 * 0.5f)) && ((temp_r3_1919 = this->unkC, (((((u8) M2C_FIELD(temp_r3_1919, u8 *, 0xB08) >> 6U) & 1) == 0) == 0)) || (((u8) M2C_FIELD(temp_r3_1919, u8 *, 0x8B9) >> 4U) & 1)) && (IsFollowingSpawnPath() != 0) && ((temp_r3_1932 = M2C_FIELD(this->unkC, void **, 0xA44), ((temp_r3_1932 == NULL) != 0)) || !(M2C_FIELD(temp_r3_1932, s32 *, 4) & 0x10000))))) {
            temp_r3_1939 = this->unkC;
            if (M2C_FIELD(M2C_FIELD(temp_r3_1939, void **, 0x44), u8 (**)(s32), 0x114)(temp_r3_1939) == 0) {
                temp_r4_1949 = this->unkC;
                if ((((AITargetData *) (this->unkC + 0x870))->GetDist() < M2C_FIELD(M2C_FIELD(temp_r4_1949, void **, 0xA38), f32 *, 0x130)) || (((AITargetData *) (temp_r4_1949 + 0x870))->GetDist() < (0.5f * var_f31_1867)) || (IsFollowingSpawnPath() != 0) || ((IsActive(0x21) != 0) && (((u8) M2C_FIELD(this->unk58, u8 *, 0x30) >> 4U) & 1))) {
                    temp_r3_1977 = this->unkC;
                    M2C_FIELD(temp_r3_1977, u8 *, 0xB08) = (u8) (M2C_FIELD(temp_r3_1977, u8 *, 0xB08) | 0x40);
                }
                if (IsFollowingSpawnPath() != 0) {
                    StopFollowingSpawnPath();
                }
                temp_r4_1990 = this->unkC;
                if ((u32) M2C_FIELD(temp_r4_1990, u32 *, 0xA5C) != 0U) {
                    AddGoal_GroundAttackMode();
                    return;
                }
                AddGoal_AlertMode(temp_r4_1990 + 0x870);
                return;
            }
        }
        if ((AddGoal_MoveToLastPlayerPos() == 0) && (Try_AddGoal_OperateLever() == 0)) {
            if (Try_AddGoal_Kong() != 0) {
                return;
            }
            if (((IsPresent(2) == 0) || (((u8) M2C_FIELD(this->unkC, u8 *, 0xB08) >> 6U) & 1)) && (IsFollowingSpawnPath() == 0)) {
                AddGoal_PatrolMode();
            }
        }
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void' to
void EnemyGoal_Think::Arbitrate() {
    EnemyDamageFeedback sp28;
    EnemyHudData sp8;
    Goal<Enemy> *temp_r3_2270;
    s32 temp_r3_2100;
    s32 temp_r3_2156;
    s32 temp_r3_2191;
    s32 temp_r3_2223;
    s32 temp_r3_2233;
    s32 temp_r3_2288;
    s32 temp_r3_2323;
    s32 temp_r3_2349;
    s32 temp_r3_2355;
    s32 temp_r4_2054;
    s32 temp_r4_2136;
    s32 temp_r4_2168;
    s32 temp_r5_2162;
    u8 temp_r30_2119;
    u8 temp_r3_2096;
    u8 var_r30_2234;
    u8 var_r30_2328;
    void *temp_r3_2085;
    void *temp_r3_2143;

    temp_r4_2054 = this->unkC;
    if (!(((u8) M2C_FIELD(temp_r4_2054, u8 *, 0xB09) >> 7U) & 1)) {
        AddGoal_Respawn();
        return;
    }
    if (((s32) M2C_FIELD(temp_r4_2054, s32 *, 0xAFC) != 0) && (((Enemy *) temp_r4_2054)->CanStrafe() != 0)) {
        AddGoal_Strafe();
        M2C_FIELD(this->unkC, s32 *, 0xAFC) = 0;
        return;
    }
    M2C_FIELD(this->unkC, s32 *, 0xAFC) = 0;
    if (!(((u8) this->unk70 >> 7U) & 1) && ((Goal<Enemy> *) this->unk48 != NULL)) {
        temp_r3_2085 = M2C_FIELD(this->unkC, void **, 0xA44);
        if ((temp_r3_2085 != NULL) && (M2C_FIELD(temp_r3_2085, s32 *, 4) & 0x200)) {
            AddGoal_Spawn();
            return;
        }
    }
    temp_r3_2096 = ((Enemy *) this->unkC)->IsInvulnerable();
    if (temp_r3_2096 != 0) {
        temp_r3_2100 = this->unkC;
        M2C_FIELD(temp_r3_2100, s32 *, 0x9D8) = 0;
        M2C_FIELD(temp_r3_2100, s32 *, 0x9D4) = 0;
    }
    if ((((Enemy *) this->unkC)->WasHit() != 0) && (temp_r3_2096 == 0)) {
        temp_r30_2119 = IsActive(0x29);
        sp28.Init();
        ((Enemy *) this->unkC)->TakeDamage(&sp28, temp_r30_2119);
        if (IsFollowingSpawnPath() != 0) {
            StopFollowingSpawnPath();
        }
        if (IsFollowingSpawnGraph() != 0) {
            temp_r4_2136 = this->unkC;
            if (!(sp28.unk20 & M2C_FIELD(temp_r4_2136, s32 *, 0xAD4)) && (temp_r30_2119 == 0) && ((temp_r3_2143 = M2C_FIELD(temp_r4_2136, void **, 0xA44), ((temp_r3_2143 == NULL) != 0)) || !(M2C_FIELD(temp_r3_2143, s32 *, 4) & 0x10000)) && !(((u8) M2C_FIELD(temp_r4_2136, u8 *, 0x6B5) >> 4U) & 1)) {
                StopFollowingSpawnGraph();
            }
        }
        temp_r3_2156 = this->unkC;
        M2C_FIELD(temp_r3_2156, u8 *, 0xB0A) = (u8) (M2C_FIELD(temp_r3_2156, u8 *, 0xB0A) & ~1);
        temp_r5_2162 = this->unkC;
        if (M2C_FIELD(temp_r5_2162, f32 *, 0xAC8) <= 0.0f) {
            temp_r4_2168 = M2C_FIELD(temp_r5_2162, s32 *, 0xAE8);
            if (temp_r4_2168 < (s32) (M2C_FIELD(M2C_FIELD(temp_r5_2162, void **, 0xA38), s32 *, 0x11C) - 1)) {
                M2C_FIELD(temp_r5_2162, s32 *, 0xAE8) = (s32) (temp_r4_2168 + 1);
                ((Enemy *) this->unkC)->GetMaxHealth();
                ((Enemy *) this->unkC)->SetHealth(M2C_ERROR(/* Read from unset register $f1 */));
                sp8.EnemyHudData();
                ((Enemy *) this->unkC)->GetMaxHealth();
                sp8.Init((Enemy *) this->unkC, 0.0f, M2C_ERROR(/* Read from unset register $f1 */));
                EnemyHud_Modified(sp8);
            }
        }
        temp_r3_2191 = this->unkC;
        if (M2C_FIELD(temp_r3_2191, f32 *, 0xAC8) <= 0.0f) {
            AddGoal_Death(&sp28);
            return;
        }
        if (sp28.unk28 != 0xE) {
            if ((sp28.unk20 & 1) && (sp28.unk30 >= 2) && (sp28.unk30 < 3) && (M2C_FIELD(M2C_FIELD(temp_r3_2191, void **, 0x44), u8 (**)(), 0x190)() != 0)) {
                AddGoal_Panic();
                return;
            }
            temp_r3_2223 = this->unkC;
            if (!(((u8) M2C_FIELD(temp_r3_2223, u8 *, 0xB08) >> 6U) & 1) && (M2C_FIELD(M2C_FIELD(temp_r3_2223, void **, 0x44), u8 (**)(), 0x190)() != 0)) {
                temp_r3_2233 = this->unkC;
                var_r30_2234 = 0;
                if (((u8) M2C_FIELD(temp_r3_2233, u8 *, 0x8B8) == 2) || (((TargetContext *) (temp_r3_2233 + 0x8B0))->Get() != NULL)) {
                    var_r30_2234 = 1;
                }
                if ((var_r30_2234 != 0) && (((AITargetData *) (this->unkC + 0x870))->GetDist() > 1000.0f)) {
                    AddGoal_Panic();
                }
            }
            AddGoal_Hit(&sp28);
            return;
        }
        if (((sp28.unk34 >> 4U) & 1) && (M2C_FIELD(temp_r3_2191, f32 *, 0xACC) <= 0.0f)) {
            ((Enemy *) temp_r3_2191)->Armour_Destroy();
        }
        goto block_46;
    }
block_46:
    temp_r3_2270 = this->unk48;
    if (((temp_r3_2270 == NULL) || (M2C_FIELD(temp_r3_2270->__vptr, u8 (**)(), 0x28)() == 0)) && (IsPresent(6) == 0)) {
        temp_r3_2288 = this->unkC;
        if (M2C_FIELD(temp_r3_2288, u8 *, 0xB0A) & 1) {
            AddGoal_ReceiveOrders();
            return;
        }
        if ((((u8) M2C_FIELD(temp_r3_2288, u8 *, 0xB09) >> 1U) & 1) && (M2C_FIELD(M2C_FIELD(temp_r3_2288, void **, 0x44), u8 (**)(), 0x190)() != 0)) {
            AddGoal_Panic();
        }
        if (IsFollowingSpawnPath() != 0) {
            AddGoal_FollowSpawnPath();
        }
        if (IsFollowingSpawnGraph() != 0) {
            AddGoal_FollowSpawnGraph();
            return;
        }
        temp_r3_2323 = this->unkC;
        if (((u8) M2C_FIELD(temp_r3_2323, u8 *, 0xB0A) >> 7U) & 1) {
            var_r30_2328 = 0;
            if (((u8) M2C_FIELD(temp_r3_2323, u8 *, 0x8B8) == 2) || (((TargetContext *) (temp_r3_2323 + 0x8B0))->Get() != NULL)) {
                var_r30_2328 = 1;
            }
            if ((var_r30_2328 != 0) && (M2C_FIELD(*gb, u8 (**)(void **), 0x4C)(gb) != 0)) {
                temp_r3_2349 = this->unkC;
                M2C_FIELD(temp_r3_2349, u8 *, 0xB0A) = (u8) (M2C_FIELD(temp_r3_2349, u8 *, 0xB0A) & ~0x80);
                temp_r3_2355 = this->unkC;
                M2C_FIELD(temp_r3_2355, u8 *, 0xB08) = (u8) (M2C_FIELD(temp_r3_2355, u8 *, 0xB08) | 0x40);
                if ((Goal<Enemy> *) this->unk24 != NULL) {
                    AddGoal_AlertMode(this->unkC + 0x870);
                    return;
                }
                AddGoal_GroundAttackMode();
                return;
            }
            goto block_67;
        }
block_67:
        ArbitrateOld();
    }
}
#endif

void EnemyGoal_Think::Terminate() {
    this->unk8 = 1;
    RemoveAllSubgoals();
}

#if 0 // DRAFT: illegal implicit conversion from 'void' to
u8 EnemyGoal_Think::Update() {
    s32 temp_r3_2405;
    s32 temp_r3_2427;
    s32 temp_r3_2475;
    s32 temp_r4_2470;

    temp_r3_2405 = this->unkC;
    if (M2C_FIELD(M2C_FIELD(temp_r3_2405, void **, 0x44), u8 (**)(s32), 0xE8)(temp_r3_2405) == 0) {
        ((Enemy *) this->unkC)->SelectTarget();
    }
    if (((Enemy *) this->unkC)->WasHit() != 0) {
        this->unk8 = 1;
    }
    ActivateIfInactive();
    this->unk8 = UpdateSubgoals();
    temp_r3_2427 = this->unkC;
    if (((EAPManager *) M2C_FIELD(temp_r3_2427, EAPManager **, 0xA5C) != NULL) && ((Goal<Enemy> *) this->unk64 != NULL)) {
        ((Enemy *) temp_r3_2427)->IsFlinching();
        if (((u8) M2C_ERROR(/* Read from unset register $r3 */) != 0) && ((IsActive(8) != 0) || (IsActive(0xA) != 0) || (IsActive(0xF) != 0) || (IsActive(0x10) != 0))) {
            temp_r4_2470 = this->unkC;
            temp_r3_2475 = ((EAPManager *) (M2C_FIELD(temp_r4_2470, EAPManager **, 0xA5C)))->Evaluate((Enemy *) temp_r4_2470, temp_r4_2470 + 0x870, NULL, 0);
            if ((temp_r3_2475 != 0) && (M2C_FIELD(*temp_r3_2475, s32 *, 0x38) & 0x30000)) {
                RemoveAllSubgoals();
                AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk64);
                ((EnemyGoal_GroundAttackMode *) this->unk64)->SetParams(this->unkC + 0x870, 1U, (EAPItem *) temp_r3_2475);
            }
        }
    }
    if ((u8) this->unk8 != 0) {
        this->unk70 &= ~0x10;
        Activate();
    }
    return (u8) this->unk8;
}
#endif

void EnemyGoal_Think::Activate() {
    this->unk8 = 0;
    if ((u32) M2C_FIELD(this->unkC, u32 *, 0xA94) != 0U) {
        StartFollowingSpawnPath();
    }
    if ((u32) M2C_FIELD(this->unkC, u32 *, 0xA80) != 0U) {
        StartFollowingSpawnGraph();
    }
    if (M2C_FIELD(this->unkC, u8 *, 0xB01) & 1) {
        AddGoal_Frozen();
    }
    Arbitrate();
}

#if 0 // DRAFT: undefined identifier '__vptr'
void EnemyGoal_Think::Deinit() {
    Goal<Enemy> *temp_r3_2565;
    Goal<Enemy> *temp_r3_2570;
    Goal<Enemy> *temp_r3_2575;
    Goal<Enemy> *temp_r3_2580;
    Goal<Enemy> *temp_r3_2585;
    Goal<Enemy> *temp_r3_2590;
    Goal<Enemy> *temp_r3_2595;
    Goal<Enemy> *temp_r3_2600;
    Goal<Enemy> *temp_r3_2605;
    Goal<Enemy> *temp_r3_2610;
    Goal<Enemy> *temp_r3_2618;
    Goal<Enemy> *temp_r3_2634;
    Goal<Enemy> *temp_r3_2642;
    Goal<Enemy> *temp_r3_2650;
    Goal<Enemy> *temp_r3_2660;
    Goal<Enemy> *temp_r3_2670;
    Goal<Enemy> *temp_r3_2698;
    Goal<Enemy> *temp_r3_2703;
    Goal<Enemy> *temp_r3_2713;
    Goal<Enemy> *temp_r3_2718;
    MKHeap *temp_r3_2726;
    s32 temp_r30_2723;
    void **temp_r3_2626;
    void **temp_r3_2708;

    temp_r3_2565 = this->unk20;
    temp_r3_2565->Deinit();
    temp_r3_2570 = this->unk28;
    temp_r3_2570->Deinit();
    temp_r3_2575 = this->unk2C;
    temp_r3_2575->Deinit();
    temp_r3_2580 = this->unk30;
    temp_r3_2580->Deinit();
    temp_r3_2585 = this->unk34;
    temp_r3_2585->Deinit();
    temp_r3_2590 = this->unk38;
    temp_r3_2590->Deinit();
    temp_r3_2595 = this->unk50;
    temp_r3_2595->Deinit();
    temp_r3_2600 = this->unk54;
    temp_r3_2600->Deinit();
    temp_r3_2605 = this->unk58;
    temp_r3_2605->Deinit();
    temp_r3_2610 = this->unk3C;
    if (temp_r3_2610 != NULL) {
        M2C_FIELD(temp_r3_2610->__vptr, M2C_UNK (**)(), 0xC)();
    }
    temp_r3_2618 = this->unk40;
    if (temp_r3_2618 != NULL) {
        M2C_FIELD(temp_r3_2618->__vptr, M2C_UNK (**)(), 0xC)();
    }
    temp_r3_2626 = this->unk44;
    if (temp_r3_2626 != NULL) {
        M2C_FIELD(*temp_r3_2626, M2C_UNK (**)(), 0xC)();
    }
    temp_r3_2634 = this->unk5C;
    if (temp_r3_2634 != NULL) {
        M2C_FIELD(temp_r3_2634->__vptr, M2C_UNK (**)(), 0xC)();
    }
    temp_r3_2642 = this->unk4C;
    if (temp_r3_2642 != NULL) {
        M2C_FIELD(temp_r3_2642->__vptr, M2C_UNK (**)(), 0xC)();
    }
    temp_r3_2650 = this->unk64;
    if (temp_r3_2650 != NULL) {
        M2C_FIELD(temp_r3_2650->__vptr, M2C_UNK (**)(), 0xC)();
        operator delete(this->unk64);
    }
    temp_r3_2660 = this->unk60;
    if (temp_r3_2660 != NULL) {
        M2C_FIELD(temp_r3_2660->__vptr, M2C_UNK (**)(), 0xC)();
        operator delete(this->unk60);
    }
    temp_r3_2670 = this->unk24;
    if (temp_r3_2670 != NULL) {
        M2C_FIELD(temp_r3_2670->__vptr, M2C_UNK (**)(), 0xC)();
        operator delete(this->unk24);
    }
    operator delete(this->unk20);
    operator delete(this->unk28);
    operator delete(this->unk2C);
    operator delete(this->unk30);
    operator delete(this->unk34);
    operator delete(this->unk38);
    operator delete(this->unk50);
    operator delete(this->unk54);
    operator delete(this->unk58);
    temp_r3_2698 = this->unk3C;
    if (temp_r3_2698 != NULL) {
        operator delete(temp_r3_2698);
    }
    temp_r3_2703 = this->unk40;
    if (temp_r3_2703 != NULL) {
        operator delete(temp_r3_2703);
    }
    temp_r3_2708 = this->unk44;
    if (temp_r3_2708 != NULL) {
        operator delete(temp_r3_2708);
    }
    temp_r3_2713 = this->unk5C;
    if (temp_r3_2713 != NULL) {
        operator delete(temp_r3_2713);
    }
    temp_r3_2718 = this->unk4C;
    if (temp_r3_2718 != NULL) {
        operator delete(temp_r3_2718);
    }
    temp_r30_2723 = this->unk1C;
    if ((u32) temp_r30_2723 != 0U) {
        temp_r3_2726 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_2726 != NULL) {
            ((MKHeap *) (temp_r3_2726->Current()))->Free((void *) temp_r30_2723, NULL, 0);
        } else {
            free(temp_r30_2723);
        }
        this->unk1C = 0;
    }
    this->unk10 = 0;
    this->unk18 = 0;
    this->unk14 = 0;
    this->unk8 = 1;
    this->unkC = 0;
    this->unk9 = 0;
}
#endif

#if 0 // DRAFT: pointer/array required
void EnemyGoal_Think::InitKongGoal() {
    operator new(0x3CU, NULL, 0);
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
    this->unk40 = M2C_ERROR(/* Read from unset register $r3 */);
    ((EnemyGoal_Kong *) this->unk40)->Init((Enemy *) this->unkC);
}
#endif

#if 0 // DRAFT: pointer/array required
void EnemyGoal_Think::InitFrozenGoal() {
    Goal<Enemy> *temp_r4_2833;

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
    temp_r4_2833 = this->unk4C;
    M2C_FIELD(temp_r4_2833, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_2833, s32 *, 0xC) = (s32) this->unkC;
    M2C_FIELD(temp_r4_2833, s32 *, 4) = 6;
    if ((u32) M2C_FIELD(temp_r4_2833, s32 *, 0xC) != 0U) {
        M2C_FIELD(temp_r4_2833, s8 *, 9) = 1;
    }
}
#endif

#if 0 // DRAFT: pointer/array required
void EnemyGoal_Think::InitOperateLeverGoal() {
    operator new(0x40U, NULL, 0);
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
    ((EnemyGoal_OperateLever *) this->unk3C)->Init((Enemy *) this->unkC);
}
#endif

#if 0 // DRAFT: pointer/array required
void EnemyGoal_Think::Init(Enemy *arg0) {
    Goal<Enemy> *temp_r3_3354;
    Goal<Enemy> *temp_r3_3360;
    Goal<Enemy> *temp_r3_3410;
    Goal<Enemy> *temp_r3_3432;
    Goal<Enemy> *temp_r4_3292;
    Goal<Enemy> *temp_r4_3303;
    Goal<Enemy> *temp_r4_3314;
    Goal<Enemy> *temp_r4_3328;
    Goal<Enemy> *temp_r4_3339;
    Goal<Enemy> *temp_r4_3384;
    Goal<Enemy> *temp_r4_3397;
    Goal<Enemy> *temp_r4_3419;
    MKHeap *temp_r3_3256;
    void **temp_r4_3366;
    void *var_r3_3263;

    if ((u8) this->unk9 == 0) {
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
        this->unk20 = M2C_ERROR(/* Read from unset register $r3 */);
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
        this->unk28 = M2C_ERROR(/* Read from unset register $r3 */);
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
        this->unk2C = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x10U, NULL, 0);
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
        operator new(0x28U, NULL, 0);
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
        this->unk50 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x10U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk54 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x34U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk58 = M2C_ERROR(/* Read from unset register $r3 */);
        this->unk3C = NULL;
        this->unk40 = NULL;
        this->unk5C = NULL;
        this->unk44 = NULL;
        this->unk48 = NULL;
        this->unk4C = NULL;
        this->unk24 = NULL;
        this->unk60 = NULL;
        this->unk64 = NULL;
        if ((void *) arg0->unkA44 != NULL) {
            operator new(0x1CU, NULL, 0);
            if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
                *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
                *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
            }
            this->unk60 = M2C_ERROR(/* Read from unset register $r3 */);
            operator new(0x70U, NULL, 0);
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
            this->unk64 = M2C_ERROR(/* Read from unset register $r3 */);
        } else {
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
            this->unk24 = M2C_ERROR(/* Read from unset register $r3 */);
        }
        if (arg0->CanStrafe() != 0) {
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
        if ((u32) arg0->unkA4C != 0U) {
            operator new(0x1CU, NULL, 0);
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
    }
    if ((u8) this->unk9 == 0) {
        temp_r3_3256 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_3256 != NULL) {
            var_r3_3263 = ((MKHeap *) (temp_r3_3256->Current()))->Alloc(0xC, NULL, 0);
        } else {
            var_r3_3263 = malloc(0xC);
        }
        this->unk1C = (s32) var_r3_3263;
        this->unk10 = 3;
    }
    this->unk8 = 1;
    this->unkC = (s32) arg0;
    this->unk4 = 0x5C;
    if ((u32) this->unkC != 0U) {
        this->unk9 = 1;
    }
    ((EnemyGoal_PatrolMode *) this->unk20)->Init(arg0);
    ((EnemyGoal_Hit *) this->unk28)->Init(arg0);
    ((EnemyGoal_Death *) this->unk2C)->Init(arg0);
    temp_r4_3292 = this->unk30;
    M2C_FIELD(temp_r4_3292, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_3292, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_3292, s32 *, 4) = 0x1E;
    if ((Enemy *) M2C_FIELD(temp_r4_3292, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_3292, s8 *, 9) = 1;
    }
    temp_r4_3303 = this->unk34;
    M2C_FIELD(temp_r4_3303, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_3303, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_3303, s32 *, 4) = 0x26;
    if ((Enemy *) M2C_FIELD(temp_r4_3303, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_3303, s8 *, 9) = 1;
    }
    temp_r4_3314 = this->unk38;
    M2C_FIELD(temp_r4_3314, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_3314, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_3314, s32 *, 4) = 0x22;
    if ((Enemy *) M2C_FIELD(temp_r4_3314, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_3314, s8 *, 9) = 1;
    }
    ((EnemyGoal_FollowGraph *) this->unk50)->Init(arg0);
    temp_r4_3328 = this->unk54;
    M2C_FIELD(temp_r4_3328, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_3328, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_3328, s32 *, 4) = 0x4D;
    if ((Enemy *) M2C_FIELD(temp_r4_3328, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_3328, s8 *, 9) = 1;
    }
    temp_r4_3339 = this->unk58;
    M2C_FIELD(temp_r4_3339, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_3339, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_3339, s32 *, 4) = 0x21;
    if ((Enemy *) M2C_FIELD(temp_r4_3339, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_3339, s8 *, 9) = 1;
    }
    M2C_FIELD(temp_r4_3339, u8 *, 0x30) = (u8) (M2C_FIELD(temp_r4_3339, u8 *, 0x30) & ~0x10);
    temp_r3_3354 = this->unk3C;
    if (temp_r3_3354 != NULL) {
        ((EnemyGoal_OperateLever *) temp_r3_3354)->Init(arg0);
    }
    temp_r3_3360 = this->unk40;
    if (temp_r3_3360 != NULL) {
        ((EnemyGoal_Kong *) temp_r3_3360)->Init(arg0);
    }
    temp_r4_3366 = this->unk44;
    if (temp_r4_3366 != NULL) {
        M2C_FIELD(temp_r4_3366, s8 *, 8) = 1;
        M2C_FIELD(temp_r4_3366, Enemy **, 0xC) = arg0;
        M2C_FIELD(temp_r4_3366, s32 *, 4) = 0x4A;
        if ((Enemy *) M2C_FIELD(temp_r4_3366, Enemy **, 0xC) != NULL) {
            M2C_FIELD(temp_r4_3366, s8 *, 9) = 1;
        }
        M2C_FIELD(temp_r4_3366, s32 *, 0x14) = 3;
        M2C_FIELD(temp_r4_3366, s32 *, 0x10) = 0;
    }
    temp_r4_3384 = this->unk5C;
    if (temp_r4_3384 != NULL) {
        M2C_FIELD(temp_r4_3384, s8 *, 8) = 1;
        M2C_FIELD(temp_r4_3384, Enemy **, 0xC) = arg0;
        M2C_FIELD(temp_r4_3384, s32 *, 4) = 0x20;
        if ((Enemy *) M2C_FIELD(temp_r4_3384, Enemy **, 0xC) != NULL) {
            M2C_FIELD(temp_r4_3384, s8 *, 9) = 1;
        }
    }
    temp_r4_3397 = this->unk4C;
    if (temp_r4_3397 != NULL) {
        M2C_FIELD(temp_r4_3397, s8 *, 8) = 1;
        M2C_FIELD(temp_r4_3397, Enemy **, 0xC) = arg0;
        M2C_FIELD(temp_r4_3397, s32 *, 4) = 6;
        if ((Enemy *) M2C_FIELD(temp_r4_3397, Enemy **, 0xC) != NULL) {
            M2C_FIELD(temp_r4_3397, s8 *, 9) = 1;
        }
    }
    temp_r3_3410 = this->unk24;
    if (temp_r3_3410 != NULL) {
        ((EnemyGoal_AlertMode *) temp_r3_3410)->Init(arg0);
        SetSummonGoal__19EnemyGoal_AlertModeFP12Goal<5Enemy>((EnemyGoal_AlertMode *) this->unk24, (Goal<Enemy> *) this->unk44);
    }
    temp_r4_3419 = this->unk60;
    if (temp_r4_3419 != NULL) {
        M2C_FIELD(temp_r4_3419, s8 *, 8) = 1;
        M2C_FIELD(temp_r4_3419, Enemy **, 0xC) = arg0;
        M2C_FIELD(temp_r4_3419, s32 *, 4) = 2;
        if ((Enemy *) M2C_FIELD(temp_r4_3419, Enemy **, 0xC) != NULL) {
            M2C_FIELD(temp_r4_3419, s8 *, 9) = 1;
        }
    }
    temp_r3_3432 = this->unk64;
    if (temp_r3_3432 != NULL) {
        ((EnemyGoal_GroundAttackMode *) temp_r3_3432)->Init(arg0);
        SetSummonGoal__26EnemyGoal_GroundAttackModeFP12Goal<5Enemy>((EnemyGoal_GroundAttackMode *) this->unk64, (Goal<Enemy> *) this->unk44);
    }
    this->unk70 &= ~0x40;
    this->unk70 &= ~0x20;
    this->unk70 &= ~0x80;
    this->unk70 &= ~0x10;
    this->unk68 = (AITargetData *)6;
    this->unk6C = 0;
}
#endif
