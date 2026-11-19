#include "spyro/source/KaneGoal_Think.h"
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
#include <m2c_macros.h>

M2C_UNK free(s32);                                  /* extern */
s32 malloc(M2C_UNK);                                /* extern */

void KaneGoal_Think::AddGoal_Idle() {
    Goal<Enemy> *temp_r3_16;
    Goal<Enemy> *temp_r4_26;

    temp_r3_16 = this->unk24;
    if (temp_r3_16->IsActive() == 0) {
        AddSubgoal((Goal<Enemy> *) this->unk24);
        temp_r4_26 = this->unk24;
        M2C_FIELD(temp_r4_26, s32 *, 0x10) = 0;
        M2C_FIELD(temp_r4_26, s32 *, 0x14) = 0;
        M2C_FIELD(temp_r4_26, s32 *, 0x18) = 1;
        M2C_FIELD(temp_r4_26, s32 *, 0x1C) = 0;
        M2C_FIELD(temp_r4_26, u8 *, 0x20) = (u8) (M2C_FIELD(temp_r4_26, u8 *, 0x20) & ~0x40);
    }
}

void KaneGoal_Think::AddGoal_FollowSpawnGraph() {
    s32 temp_r3_64;
    s32 temp_r3_69;

    if (IsPresent(0x2A) == 0) {
        RemoveAllSubgoals();
        AddSubgoal((Goal<Enemy> *) this->unk20);
        temp_r3_64 = this->unkC;
        M2C_FIELD(temp_r3_64, u8 *, 0xB09) = (u8) (M2C_FIELD(temp_r3_64, u8 *, 0xB09) | 8);
        temp_r3_69 = this->unkC;
        M2C_FIELD(temp_r3_69, u8 *, 0xB08) = (u8) (M2C_FIELD(temp_r3_69, u8 *, 0xB08) | 0x40);
    }
}

void KaneGoal_Think::StartFollowingSpawnGraph() {
    s32 temp_r4_87;

    if (!(((u8) this->unk28 >> 7U) & 1)) {
        temp_r4_87 = this->unkC;
        M2C_FIELD(temp_r4_87, u8 *, 0xB09) = (u8) (M2C_FIELD(temp_r4_87, u8 *, 0xB09) | 8);
        this->unk28 |= 0x80;
    }
}

u8 KaneGoal_Think::IsFollowingSpawnGraph() {
    return ((u8) M2C_FIELD(M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), void **, 0xC), u8 *, 0xB09) >> 3U) & 1;
}

void KaneGoal_Think::Arbitrate() {
    if (KaneGoal_Think::IsFollowingSpawnGraph() != 0) {
        AddGoal_FollowSpawnGraph();
        return;
    }
    AddGoal_Idle();
}

void KaneGoal_Think::Terminate() {
    this->unk8 = 1;
    RemoveAllSubgoals();
}

u8 KaneGoal_Think::Update() {
    s32 temp_r3_156;

    ActivateIfInactive();
    temp_r3_156 = this->unkC;
    if (M2C_FIELD(M2C_FIELD(temp_r3_156, void **, 0x44), u8 (**)(s32), 0xE8)(temp_r3_156) == 0) {
        ((Enemy *) this->unkC)->SelectTarget();
    }
    this->unk8 = UpdateSubgoals();
    if ((u8) this->unk8 != 0) {
        Activate();
    }
    return (u8) this->unk8;
}

void KaneGoal_Think::Activate() {
    this->unk8 = 0;
    if ((u32) M2C_FIELD(this->unkC, u32 *, 0xA80) != 0U) {
        StartFollowingSpawnGraph();
    }
    Arbitrate();
}

void KaneGoal_Think::Deinit() {
    Goal<Enemy> *temp_r3_222;
    Goal<Enemy> *temp_r3_227;
    s32 temp_r31_236;

    temp_r3_222 = this->unk20;
    temp_r3_222->Deinit();
    temp_r3_227 = this->unk24;
    temp_r3_227->Deinit();
    operator delete(this->unk20);
    operator delete(this->unk24);
    temp_r31_236 = this->unk1C;
    if ((u32) temp_r31_236 != 0U) {
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free((void *) temp_r31_236, NULL, 0);
        } else {
            free(temp_r31_236);
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

#if 0 // DRAFT: pointer/array required
void KaneGoal_Think::Init(Enemy *arg0) {
    Goal<Enemy> *temp_r4_363;
    void *var_r3_340;

    if ((u8) this->unk9 == 0) {
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
        this->unk20 = M2C_ERROR(/* Read from unset register $r3 */);
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
    }
    if ((u8) this->unk9 == 0) {
        if (MKHeap::Current() != NULL) {
            var_r3_340 = ((MKHeap *) (MKHeap::Current()))->Alloc(8, NULL, 0);
        } else {
            var_r3_340 = malloc(8);
        }
        this->unk1C = (s32) var_r3_340;
        this->unk10 = 2;
    }
    this->unk8 = 1;
    this->unkC = (s32) arg0;
    this->unk4 = 0x5E;
    if ((u32) this->unkC != 0U) {
        this->unk9 = 1;
    }
    ((EnemyGoal_FollowGraph *) this->unk20)->Init(arg0);
    temp_r4_363 = this->unk24;
    M2C_FIELD(temp_r4_363, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_363, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_363, s32 *, 4) = 0;
    if ((Enemy *) M2C_FIELD(temp_r4_363, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_363, s8 *, 9) = 1;
    }
    this->unk28 &= ~0x80;
}
#endif
