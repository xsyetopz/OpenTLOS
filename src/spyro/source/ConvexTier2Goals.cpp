#include "spyro/source/ConvexTier2Goals.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKVector3.h"
#include "spyro/source/Character.h"
#include "spyro/source/Enemy.h"
#include "spyro/source/EnemyDataTypes.h"
#include <m2c_macros.h>

#if 0 // DRAFT: expression syntax error
M2C_UNK free(void *);                               /* extern */
void *malloc(M2C_UNK);                              /* extern */

void ConvexTier2Goal_FlyIdle::Terminate() {
    Character *temp_r3_25;
    void *temp_r3_21;

    this->unk8 = 1;
    temp_r3_21 = this->unkC->unk638;
    M2C_FIELD(temp_r3_21, u8 *, 0x464) = (u8) (M2C_FIELD(temp_r3_21, u8 *, 0x464) & ~0x80);
    temp_r3_25 = this->unkC;
    temp_r3_25->unk588.unkC = 0.0f;
    temp_r3_25->unk598 = 0.0f;
    temp_r3_25->unk59C = 0.0f;
    this->unkC->unk638->WanderOff();
    this->unkC->unk638->ObstacleAvoidanceOff();
    this->unkC->unk638->WallAvoidanceOff();
}
#endif

u8 ConvexTier2Goal_FlyIdle::Update() {
    ActivateIfInactive();
    return this->unk8;
}

#if 0 // DRAFT: undefined identifier 'unkAEC'
void ConvexTier2Goal_FlyIdle::Activate() {
    Character *temp_r3_77;
    Character *temp_r9_88;
    void *temp_r3_99;

    this->unk8 = 0;
    this->unkC->unkAEC = 0;
    this->unkC->StopMovement(1U);
    temp_r3_77 = this->unkC;
    temp_r3_77->unk6B5 |= 0x10;
    temp_r9_88 = this->unkC;
    temp_r9_88->unk684 = M2C_FIELD(temp_r9_88->unkA38, f32 *, 0x158);
    this->unkC->SetAnim((AnimSequenceType) 0xA, 0, 1, 0.15f, 0U, 0U);
    this->unkC->SetMovementType((CharacterMoveType) 2);
    temp_r3_99 = this->unkC->unk638;
    M2C_FIELD(temp_r3_99, u8 *, 0x464) = (u8) (M2C_FIELD(temp_r3_99, u8 *, 0x464) | 0x80);
    this->unkC->unk638->WanderOn();
    this->unkC->unk638->ObstacleAvoidanceOn(NULL);
    this->unkC->unk638->WallAvoidanceOn();
}
#endif

void ConvexTier2Goal_PatrolMode::Terminate() {
    this->unk8 = 1;
    RemoveAllSubgoals();
}

#if 0 // DRAFT: illegal implicit conversion from 'void' to
u8 ConvexTier2Goal_PatrolMode::Update() {
    ActivateIfInactive();
    this->unk8 = UpdateSubgoals();
    return this->unk8;
}
#endif

#if 0 // DRAFT: undefined identifier 'AddSubgoal__21CompositeGoal'
void ConvexTier2Goal_PatrolMode::Activate() {
    Enemy *temp_r4_166;

    this->unk8 = 0;
    RemoveAllSubgoals();
    temp_r4_166 = this->unkC;
    M2C_FIELD(temp_r4_166, u8 *, 0xB08) = (u8) (M2C_FIELD(temp_r4_166, u8 *, 0xB08) & ~0x40);
    AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk24);
}
#endif

#if 0 // DRAFT: undefined identifier 'free'
void ConvexTier2Goal_PatrolMode::Deinit() {
    Goal<Enemy> *temp_r3_189;
    MKHeap *temp_r3_199;
    void *temp_r31_196;

    temp_r3_189 = this->unk24;
    temp_r3_189->Deinit();
    operator delete(this->unk24);
    temp_r31_196 = this->unk1C;
    if (temp_r31_196 != NULL) {
        temp_r3_199 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_199 != NULL) {
            ((MKHeap *) (temp_r3_199->Current()))->Free(temp_r31_196, NULL, 0);
        } else {
            free(temp_r31_196);
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
void ConvexTier2Goal_PatrolMode::Init(Enemy *arg0) {
    Goal<Enemy> *temp_r4_294;
    MKHeap *temp_r3_267;
    void *var_r3_274;

    this->unk20 = arg0;
    if ((u8) this->unk9 == 0) {
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
    }
    if ((u8) this->unk9 == 0) {
        temp_r3_267 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_267 != NULL) {
            var_r3_274 = ((MKHeap *) (temp_r3_267->Current()))->Alloc(8, NULL, 0);
        } else {
            var_r3_274 = malloc(8);
        }
        this->unk1C = var_r3_274;
        this->unk10 = 2;
    }
    this->unk8 = 1;
    this->unkC = arg0;
    this->unk4 = 0x53;
    if ((Enemy *) this->unkC != NULL) {
        this->unk9 = 1;
    }
    temp_r4_294 = this->unk24;
    M2C_FIELD(temp_r4_294, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_294, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_294, s32 *, 4) = 0x43;
    if ((Enemy *) M2C_FIELD(temp_r4_294, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_294, s8 *, 9) = 1;
    }
    M2C_FIELD(temp_r4_294, Enemy **, 0x10) = arg0;
}
#endif

void ConvexTier2Goal_Think::StartFollowingSpawnGraph() {
    Enemy *temp_r4_319;

    if (!(((u8) this->unk3C >> 6U) & 1)) {
        temp_r4_319 = this->unkC;
        M2C_FIELD(temp_r4_319, u8 *, 0xB09) = (u8) (M2C_FIELD(temp_r4_319, u8 *, 0xB09) | 8);
        this->unk3C |= 0x40;
    }
}

#if 0 // DRAFT: undefined identifier '__vptr'
void ConvexTier2Goal_Think::StopFollowingSpawnGraph() {
    Enemy *temp_r3_355;
    Enemy *temp_r6_338;
    u8 temp_r5_339;
    u8 temp_r5_344;

    temp_r6_338 = this->unkC;
    temp_r5_339 = M2C_FIELD(temp_r6_338, u8 *, 0xB09);
    if ((temp_r5_339 >> 3U) & 1) {
        temp_r5_344 = temp_r5_339 & ~8;
        M2C_FIELD(temp_r6_338, u8 *, 0xB09) = temp_r5_344;
        if (M2C_FIELD(this->__vptr, u8 (**)(M2C_UNK, u8), 0x38)(0x2A, temp_r5_344) != 0) {
            RemoveAllSubgoals();
        }
        temp_r3_355 = this->unkC;
        temp_r3_355->SetupEnemyRegion(*((MKVector3 *) &temp_r3_355->unk588), 1000.0f);
    }
}
#endif

u8 ConvexTier2Goal_Think::IsFollowingSpawnGraph() {
    return ((u8) M2C_FIELD(this->unkC, u8 *, 0xB09) >> 3U) & 1;
}

void ConvexTier2Goal_Think::StartFollowingSpawnPath() {
    Enemy *temp_r4_382;

    if (!(((u8) this->unk3C >> 7U) & 1)) {
        temp_r4_382 = this->unkC;
        M2C_FIELD(temp_r4_382, u8 *, 0xB09) = (u8) (M2C_FIELD(temp_r4_382, u8 *, 0xB09) | 0x10);
        this->unk3C |= 0x80;
    }
}

#if 0 // DRAFT: undefined identifier '__vptr'
void ConvexTier2Goal_Think::StopFollowingSpawnPath() {
    Enemy *temp_r3_418;
    Enemy *temp_r6_401;
    u8 temp_r5_402;
    u8 temp_r5_407;

    temp_r6_401 = this->unkC;
    temp_r5_402 = M2C_FIELD(temp_r6_401, u8 *, 0xB09);
    if ((temp_r5_402 >> 4U) & 1) {
        temp_r5_407 = temp_r5_402 & ~0x10;
        M2C_FIELD(temp_r6_401, u8 *, 0xB09) = temp_r5_407;
        if (M2C_FIELD(this->__vptr, u8 (**)(M2C_UNK, u8), 0x38)(0x22, temp_r5_407) != 0) {
            RemoveAllSubgoals();
        }
        temp_r3_418 = this->unkC;
        temp_r3_418->SetupEnemyRegion(*((MKVector3 *) &temp_r3_418->unk588), 1000.0f);
    }
}
#endif

u8 ConvexTier2Goal_Think::IsFollowingSpawnPath() {
    return ((u8) M2C_FIELD(this->unkC, u8 *, 0xB09) >> 4U) & 1;
}

#if 0 // DRAFT: illegal operands 'void' == 'int'
void ConvexTier2Goal_Think::AddGoal_FollowSpawnGraph() {
    Enemy *temp_r3_468;
    Enemy *temp_r3_472;
    Goal<Enemy> *temp_r5_459;

    if (IsPresent(0x2A) == 0) {
        RemoveAllSubgoals();
        AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk30);
        temp_r5_459 = this->unk30;
        M2C_FIELD(temp_r5_459, u8 *, 0x95) = (u8) (M2C_FIELD(temp_r5_459, u8 *, 0x95) | 8);
        M2C_FIELD(temp_r5_459, u8 *, 0x95) = (u8) (M2C_FIELD(temp_r5_459, u8 *, 0x95) & ~1);
        temp_r3_468 = this->unkC;
        M2C_FIELD(temp_r3_468, u8 *, 0xB09) = (u8) (M2C_FIELD(temp_r3_468, u8 *, 0xB09) | 8);
        temp_r3_472 = this->unkC;
        M2C_FIELD(temp_r3_472, u8 *, 0xB08) = (u8) (M2C_FIELD(temp_r3_472, u8 *, 0xB08) | 0x40);
    }
}
#endif

#if 0 // DRAFT: illegal operands 'void' == 'int'
void ConvexTier2Goal_Think::AddGoal_FollowSpawnPath() {
    Enemy *temp_r3_529;
    Enemy *temp_r3_533;
    Goal<Enemy> *temp_r6_509;

    if (IsPresent(0x22) == 0) {
        RemoveAllSubgoals();
        AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk2C);
        temp_r6_509 = this->unk2C;
        M2C_FIELD(temp_r6_509, f32 *, 0x10) = (f32) this->unkC->unkA7C;
        M2C_FIELD(temp_r6_509, f32 *, 0x14) = 0.0f;
        M2C_FIELD(temp_r6_509, s32 *, 0x18) = 1;
        M2C_FIELD(temp_r6_509, s32 *, 0x20) = (s32) this->unk34;
        M2C_FIELD(temp_r6_509, s32 *, 0x1C) = (s32) this->unk38;
        M2C_FIELD(temp_r6_509, u8 *, 0x24) = (u8) (M2C_FIELD(temp_r6_509, u8 *, 0x24) & ~0x20);
        M2C_FIELD(temp_r6_509, u8 *, 0x24) = (u8) (M2C_FIELD(temp_r6_509, u8 *, 0x24) & ~0x10);
        M2C_FIELD(temp_r6_509, u8 *, 0x24) = (u8) (M2C_FIELD(temp_r6_509, u8 *, 0x24) & ~8);
        M2C_FIELD(temp_r6_509, u8 *, 0x24) = (u8) (M2C_FIELD(temp_r6_509, u8 *, 0x24) & ~4);
        temp_r3_529 = this->unkC;
        M2C_FIELD(temp_r3_529, u8 *, 0xB09) = (u8) (M2C_FIELD(temp_r3_529, u8 *, 0xB09) | 0x10);
        temp_r3_533 = this->unkC;
        M2C_FIELD(temp_r3_533, u8 *, 0xB08) = (u8) (M2C_FIELD(temp_r3_533, u8 *, 0xB08) | 0x40);
        this->unkC->unkA7C.Init();
    }
}
#endif

#if 0 // DRAFT: illegal operands 'void' == 'int'
void ConvexTier2Goal_Think::AddGoal_Hit(EnemyDamageFeedback *arg0) {
    if (((s32) arg0->unk28 != 0xE) && (IsActive(0x59) == 0)) {
        AddSubgoalToFront__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk28);
    }
}
#endif

#if 0 // DRAFT: illegal operands 'void' == 'int'
void ConvexTier2Goal_Think::AddGoal_PatrolMode() {
    if (IsPresent(0x53) == 0) {
        RemoveAllSubgoals();
        AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk24);
    }
}
#endif

void ConvexTier2Goal_Think::Reset() {
    this->unk8 = 1;
    RemoveAllSubgoals();
}

#if 0 // DRAFT: undefined identifier '__vptr'
void ConvexTier2Goal_Think::Arbitrate() {
    EnemyDamageFeedback sp8;
    Enemy *temp_r3_679;
    Enemy *temp_r3_694;
    Enemy *temp_r4_634;
    u8 var_r31_695;

    if (this->unkC->WasHit() != 0) {
        sp8.Init();
        temp_r4_634 = this->unkC;
        temp_r4_634->unk9D8 = 0;
        temp_r4_634->unk9D4 = 0;
        if (IsFollowingSpawnPath() != 0) {
            StopFollowingSpawnPath();
        }
        if (IsFollowingSpawnGraph() != 0) {
            StopFollowingSpawnGraph();
        }
        this->unkC->TakeDamage(&sp8, 0U);
        if (sp8.unk28 != 0xE) {
            AddGoal_Hit(&sp8);
            return;
        }
        goto block_7;
    }
block_7:
    if (IsFollowingSpawnPath() != 0) {
        AddGoal_FollowSpawnPath();
    }
    if (IsFollowingSpawnGraph() != 0) {
        AddGoal_FollowSpawnGraph();
        return;
    }
    temp_r3_679 = this->unkC;
    if ((temp_r3_679->unkAB0 > 0.0f) && (M2C_FIELD(temp_r3_679->__vptr, u8 (**)(), 0x134)() == 0)) {
        this->unkC->IsFlinching();
        if ((u8) M2C_ERROR(/* Read from unset register $r3 */) == 0) {
            temp_r3_694 = this->unkC;
            var_r31_695 = 0;
            if (((u8) M2C_FIELD(temp_r3_694, u8 *, 0x8B8) == 2) || (temp_r3_694->unk870.unk30.Get() != NULL)) {
                var_r31_695 = 1;
            }
            if (var_r31_695 != 0) {
                AddGoal_PatrolMode();
            }
        }
    }
}
#endif

void ConvexTier2Goal_Think::Terminate() {
    this->unk8 = 1;
    RemoveAllSubgoals();
}

#if 0 // DRAFT: illegal implicit conversion from 'void' to
u8 ConvexTier2Goal_Think::Update() {
    Enemy *temp_r3_748;

    if (this->unkC->WasHit() != 0) {
        this->unk8 = 1;
    }
    temp_r3_748 = this->unkC;
    if (temp_r3_748->IsDead() == 0) {
        this->unkC->SelectTarget();
    }
    ActivateIfInactive();
    this->unk8 = UpdateSubgoals();
    if ((u8) this->unk8 != 0) {
        Activate();
    }
    return this->unk8;
}
#endif

void ConvexTier2Goal_Think::Activate() {
    this->unk8 = 0;
    if (M2C_BITWISE(u32, this->unkC->unkA7C) != 0U) {
        StartFollowingSpawnPath();
    }
    if (M2C_BITWISE(u32, this->unkC->unkA68) != 0U) {
        StartFollowingSpawnGraph();
    }
    Arbitrate();
}

#if 0 // DRAFT: undefined identifier 'free'
void ConvexTier2Goal_Think::Deinit() {
    Goal<Enemy> *temp_r3_823;
    Goal<Enemy> *temp_r3_828;
    Goal<Enemy> *temp_r3_833;
    Goal<Enemy> *temp_r3_838;
    MKHeap *temp_r3_854;
    void *temp_r31_851;

    temp_r3_823 = this->unk24;
    temp_r3_823->Deinit();
    temp_r3_828 = this->unk28;
    temp_r3_828->Deinit();
    temp_r3_833 = this->unk2C;
    temp_r3_833->Deinit();
    temp_r3_838 = this->unk30;
    temp_r3_838->Deinit();
    operator delete(this->unk24);
    operator delete(this->unk28);
    operator delete(this->unk2C);
    operator delete(this->unk30);
    temp_r31_851 = this->unk1C;
    if (temp_r31_851 != NULL) {
        temp_r3_854 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_854 != NULL) {
            ((MKHeap *) (temp_r3_854->Current()))->Free(temp_r31_851, NULL, 0);
        } else {
            free(temp_r31_851);
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
void ConvexTier2Goal_Think::Init(Enemy *arg0) {
    Goal<Enemy> *temp_r4_1036;
    MKHeap *temp_r3_1003;
    void *var_r3_1010;

    this->unk20 = arg0;
    if ((u8) this->unk9 == 0) {
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
        this->unk24 = M2C_ERROR(/* Read from unset register $r3 */);
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
        operator new(0x28U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk2C = M2C_ERROR(/* Read from unset register $r3 */);
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
        this->unk30 = M2C_ERROR(/* Read from unset register $r3 */);
    }
    if ((u8) this->unk9 == 0) {
        temp_r3_1003 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_1003 != NULL) {
            var_r3_1010 = ((MKHeap *) (temp_r3_1003->Current()))->Alloc(8, NULL, 0);
        } else {
            var_r3_1010 = malloc(8);
        }
        this->unk1C = var_r3_1010;
        this->unk10 = 2;
    }
    this->unk8 = 1;
    this->unkC = arg0;
    this->unk4 = 0x5C;
    if ((Enemy *) this->unkC != NULL) {
        this->unk9 = 1;
    }
    this->unk24->Init(arg0);
    this->unk28->Init(arg0);
    temp_r4_1036 = this->unk2C;
    M2C_FIELD(temp_r4_1036, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_1036, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_1036, s32 *, 4) = 0x22;
    if ((Enemy *) M2C_FIELD(temp_r4_1036, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_1036, s8 *, 9) = 1;
    }
    this->unk30->Init(arg0);
    this->unk3C &= ~0x80;
    this->unk3C &= ~0x40;
    this->unk34 = 0xA;
    this->unk38 = 0;
}
#endif
