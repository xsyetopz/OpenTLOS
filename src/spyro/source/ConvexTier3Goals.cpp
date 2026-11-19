#include "spyro/source/ConvexTier3Goals.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKCollision.h"
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
#include "spyro/source/EnemyGoal_FollowGraph.h"
#include "spyro/source/EnemyRegion.h"
#include "spyro/source/EnemySettings.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/Goal.h"
#include "spyro/source/IceBitsPS.h"
#include "spyro/source/KDPath.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSoundTools.h"
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

u8 ConvexTier3Goal_FlyIdle::Update() {
    u8 var_r3_28;
    u8 var_r4_22;
    void *temp_r5_23;

    ActivateIfInactive();
    if (this->unkC->HasAnimFinished() == 0) {
        var_r4_22 = 0;
        temp_r5_23 = this->unkC->unk630;
        if (((u32) M2C_FIELD(temp_r5_23, u32 *, 0x2C) >> 1U) & 1) {
            var_r3_28 = 0;
            if ((M2C_FIELD(temp_r5_23, f32 *, 0x38) > 0.0f) || ((s32) M2C_FIELD(temp_r5_23, s32 *, 0x44) > 1)) {
                var_r3_28 = 1;
            }
            if (var_r3_28 != 0) {
                var_r4_22 = 1;
            }
        }
        if (var_r4_22 != 0) {
            goto block_8;
        }
    } else {
block_8:
        this->unk8 = 2;
    }
    return this->unk8;
}

#if 0 // DRAFT: undefined identifier 'unkAEC'
void ConvexTier3Goal_FlyIdle::Activate() {
    this->unk8 = 0;
    this->unkC->unkAEC = 0;
    this->unkC->StopMovement(1U);
    ((Enemy *) this->unkC)->SetAnim((AnimSequenceType) 0xA, 0, 1, 0.15f, 0U, 0U);
    this->unkC->SetMovementType((CharacterMoveType) 2);
}
#endif

void ConvexTier3Goal_PatrolMode::Terminate() {
    this->unk8 = 1;
    RemoveAllSubgoals();
}

u8 ConvexTier3Goal_PatrolMode::Update() {
    ActivateIfInactive();
    this->unk8 = UpdateSubgoals();
    return this->unk8;
}

void ConvexTier3Goal_PatrolMode::Activate() {
    Enemy *temp_r4_135;

    this->unk8 = 0;
    RemoveAllSubgoals();
    temp_r4_135 = this->unkC;
    temp_r4_135->unkB08 &= ~0x40;
    AddSubgoal((Goal<Enemy> *) this->unk24);
}

void ConvexTier3Goal_PatrolMode::Deinit() {
    Goal<Enemy> *temp_r3_158;
    void *temp_r31_165;

    temp_r3_158 = this->unk24;
    temp_r3_158->Deinit();
    operator delete(this->unk24);
    temp_r31_165 = this->unk1C;
    if (temp_r31_165 != NULL) {
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_165, NULL, 0);
        } else {
            free(temp_r31_165);
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
void ConvexTier3Goal_PatrolMode::Init(Enemy *arg0) {
    Goal<Enemy> *temp_r4_263;
    void *var_r3_243;

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
        if (MKHeap::Current() != NULL) {
            var_r3_243 = ((MKHeap *) (MKHeap::Current()))->Alloc(8, NULL, 0);
        } else {
            var_r3_243 = malloc(8);
        }
        this->unk1C = var_r3_243;
        this->unk10 = 2;
    }
    this->unk8 = 1;
    this->unkC = arg0;
    this->unk4 = 0x53;
    if ((Enemy *) this->unkC != NULL) {
        this->unk9 = 1;
    }
    temp_r4_263 = this->unk24;
    M2C_FIELD(temp_r4_263, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_263, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_263, s32 *, 4) = 0x43;
    if ((Enemy *) M2C_FIELD(temp_r4_263, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_263, s8 *, 9) = 1;
    }
    M2C_FIELD(temp_r4_263, Enemy **, 0x10) = arg0;
}
#endif

void ConvexTier3Goal_Think::StartFollowingSpawnGraph() {
    Enemy *temp_r4_288;

    if (!(((u8) this->unk38 >> 6U) & 1)) {
        temp_r4_288 = this->unkC;
        temp_r4_288->unkB09 |= 8;
        this->unk38 |= 0x40;
    }
}

u8 ConvexTier3Goal_Think::IsFollowingSpawnGraph() {
    return ((u8) this->unkC->unkB09 >> 3U) & 1;
}

void ConvexTier3Goal_Think::StartFollowingSpawnPath() {
    Enemy *temp_r4_314;

    if (!(((u8) this->unk38 >> 7U) & 1)) {
        temp_r4_314 = this->unkC;
        temp_r4_314->unkB09 |= 0x10;
        this->unk38 |= 0x80;
    }
}

u8 ConvexTier3Goal_Think::IsFollowingSpawnPath() {
    return ((u8) this->unkC->unkB09 >> 4U) & 1;
}

void ConvexTier3Goal_Think::AddGoal_FollowSpawnGraph() {
    Enemy *temp_r3_363;
    Enemy *temp_r3_367;
    Goal<Enemy> *temp_r5_354;

    if (IsPresent(0x2A) == 0) {
        RemoveAllSubgoals();
        AddSubgoal((Goal<Enemy> *) this->unk2C);
        temp_r5_354 = this->unk2C;
        M2C_FIELD(temp_r5_354, u8 *, 0x95) = (u8) (M2C_FIELD(temp_r5_354, u8 *, 0x95) | 8);
        M2C_FIELD(temp_r5_354, u8 *, 0x95) = (u8) (M2C_FIELD(temp_r5_354, u8 *, 0x95) & ~1);
        temp_r3_363 = this->unkC;
        temp_r3_363->unkB09 |= 8;
        temp_r3_367 = this->unkC;
        temp_r3_367->unkB08 |= 0x40;
    }
}

void ConvexTier3Goal_Think::AddGoal_FollowSpawnPath() {
    Enemy *temp_r3_424;
    Enemy *temp_r3_428;
    Goal<Enemy> *temp_r6_404;

    if (IsPresent(0x22) == 0) {
        RemoveAllSubgoals();
        AddSubgoal((Goal<Enemy> *) this->unk28);
        temp_r6_404 = this->unk28;
        M2C_FIELD(temp_r6_404, Enemy **, 0x10) = (Enemy *) this->unkC->unkA94;
        M2C_FIELD(temp_r6_404, f32 *, 0x14) = 0.0f;
        M2C_FIELD(temp_r6_404, s32 *, 0x18) = 1;
        M2C_FIELD(temp_r6_404, s32 *, 0x20) = (s32) this->unk30;
        M2C_FIELD(temp_r6_404, s32 *, 0x1C) = (s32) this->unk34;
        M2C_FIELD(temp_r6_404, u8 *, 0x24) = (u8) (M2C_FIELD(temp_r6_404, u8 *, 0x24) & ~0x20);
        M2C_FIELD(temp_r6_404, u8 *, 0x24) = (u8) (M2C_FIELD(temp_r6_404, u8 *, 0x24) & ~0x10);
        M2C_FIELD(temp_r6_404, u8 *, 0x24) = (u8) (M2C_FIELD(temp_r6_404, u8 *, 0x24) & ~8);
        M2C_FIELD(temp_r6_404, u8 *, 0x24) = (u8) (M2C_FIELD(temp_r6_404, u8 *, 0x24) & ~4);
        temp_r3_424 = this->unkC;
        temp_r3_424->unkB09 |= 0x10;
        temp_r3_428 = this->unkC;
        temp_r3_428->unkB08 |= 0x40;
        ((KDPathIterator *) &this->unkC->unkA94)->Init();
    }
}

void ConvexTier3Goal_Think::AddGoal_PatrolMode() {
    if (IsPresent(0x53) == 0) {
        RemoveAllSubgoals();
        AddSubgoal((Goal<Enemy> *) this->unk24);
    }
}

void ConvexTier3Goal_Think::Reset() {
    this->unk8 = 1;
    RemoveAllSubgoals();
}

#if 0 // DRAFT: undefined identifier '__vptr'
void ConvexTier3Goal_Think::Arbitrate() {
    Enemy *temp_r3_508;
    Enemy *temp_r3_523;
    u8 var_r31_524;

    if (IsFollowingSpawnPath() != 0) {
        AddGoal_FollowSpawnPath();
    }
    if (IsFollowingSpawnGraph() != 0) {
        AddGoal_FollowSpawnGraph();
        return;
    }
    temp_r3_508 = this->unkC;
    if ((temp_r3_508->unkAC8 > 0.0f) && (M2C_FIELD(temp_r3_508->__vptr, u8 (**)(), 0x134)() == 0)) {
        this->unkC->IsFlinching();
        if ((u8) M2C_ERROR(/* Read from unset register $r3 */) == 0) {
            temp_r3_523 = this->unkC;
            var_r31_524 = 0;
            if (((u8) M2C_FIELD(temp_r3_523, u8 *, 0x8B8) == 2) || (temp_r3_523->unk870.unk40.Get() != NULL)) {
                var_r31_524 = 1;
            }
            if (var_r31_524 != 0) {
                AddGoal_PatrolMode();
            }
        }
    }
}
#endif

void ConvexTier3Goal_Think::Terminate() {
    this->unk8 = 1;
    RemoveAllSubgoals();
}

u8 ConvexTier3Goal_Think::Update() {
    Enemy *temp_r3_577;

    if (this->unkC->WasHit() != 0) {
        this->unk8 = 1;
    }
    temp_r3_577 = this->unkC;
    if (temp_r3_577->IsDead() == 0) {
        this->unkC->SelectTarget();
    }
    ActivateIfInactive();
    this->unk8 = UpdateSubgoals();
    if ((u8) this->unk8 != 0) {
        Activate();
    }
    return this->unk8;
}

void ConvexTier3Goal_Think::Activate() {
    this->unk8 = 0;
    if ((Enemy *) this->unkC->unkA94 != NULL) {
        StartFollowingSpawnPath();
    }
    if ((u32) this->unkC->unkA80 != 0) {
        StartFollowingSpawnGraph();
    }
    Arbitrate();
}

void ConvexTier3Goal_Think::Deinit() {
    Goal<Enemy> *temp_r3_652;
    Goal<Enemy> *temp_r3_657;
    Goal<Enemy> *temp_r3_662;
    void *temp_r31_673;

    temp_r3_652 = this->unk24;
    temp_r3_652->Deinit();
    temp_r3_657 = this->unk28;
    temp_r3_657->Deinit();
    temp_r3_662 = this->unk2C;
    temp_r3_662->Deinit();
    operator delete(this->unk24);
    operator delete(this->unk28);
    operator delete(this->unk2C);
    temp_r31_673 = this->unk1C;
    if (temp_r31_673 != NULL) {
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_673, NULL, 0);
        } else {
            free(temp_r31_673);
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
void ConvexTier3Goal_Think::Init(Enemy *arg0) {
    Goal<Enemy> *temp_r4_828;
    void *var_r3_805;

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
        operator new(0x28U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk28 = M2C_ERROR(/* Read from unset register $r3 */);
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
        this->unk2C = M2C_ERROR(/* Read from unset register $r3 */);
    }
    if ((u8) this->unk9 == 0) {
        if (MKHeap::Current() != NULL) {
            var_r3_805 = ((MKHeap *) (MKHeap::Current()))->Alloc(8, NULL, 0);
        } else {
            var_r3_805 = malloc(8);
        }
        this->unk1C = var_r3_805;
        this->unk10 = 2;
    }
    this->unk8 = 1;
    this->unkC = arg0;
    this->unk4 = 0x5C;
    if ((Enemy *) this->unkC != NULL) {
        this->unk9 = 1;
    }
    ((ConvexTier3Goal_PatrolMode *) this->unk24)->Init(arg0);
    temp_r4_828 = this->unk28;
    M2C_FIELD(temp_r4_828, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_828, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_828, s32 *, 4) = 0x22;
    if ((Enemy *) M2C_FIELD(temp_r4_828, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_828, s8 *, 9) = 1;
    }
    ((EnemyGoal_FollowGraph *) this->unk2C)->Init(arg0);
    this->unk38 &= ~0x80;
    this->unk38 &= ~0x40;
    this->unk30 = 0xA;
    this->unk34 = 0;
}
#endif
