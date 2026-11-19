#include "spyro/source/ElecTier3Goals.h"
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
#include "spyro/source/Enemies_Elec.h"
#include "spyro/source/Enemy.h"
#include "spyro/source/EnemyAttackPattern.h"
#include "spyro/source/EnemyDataTypes.h"
#include "spyro/source/EnemyDescriptor.h"
#include "spyro/source/EnemyGoal_AlertMode.h"
#include "spyro/source/EnemyGoal_FollowGraph.h"
#include "spyro/source/EnemyGoals_Death.h"
#include "spyro/source/EnemyGoals_Hit.h"
#include "spyro/source/EnemyRegion.h"
#include "spyro/source/EnemySettings.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/Goal.h"
#include "spyro/source/IceBitsPS.h"
#include "spyro/source/KDMatrixRefProperty.h"
#include "spyro/source/KDPath.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDProperty.h"
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
#include "common/Source/StdMath.h"
#include "spyro/source/PropFlags.h"
#include <m2c_macros.h>

M2C_UNK free(void *);                               /* extern */
void *malloc(M2C_UNK);                              /* extern */
extern f32 gUpdateTimeDelta;

void EnemyGoal_TestSB::Terminate() {
    this->unk8 = 1;
}

u8 EnemyGoal_TestSB::Update() {
    ActivateIfInactive();
    return this->unk8;
}

void EnemyGoal_TestSB::Activate() {
    this->unk8 = 0;
    this->unkC->StopMovement(1U);
    ((Enemy *) this->unkC)->SetAnim((AnimSequenceType) 5, 0, 0, 0.15f, 0U, 0U);
    this->unkC->SetMovementType((CharacterMoveType) 2);
}

void ElecTier3Goal_Scan::Terminate() {
    this->unk10->EnableScan(0U);
    this->unk8 = 1;
}

#if 0 // DRAFT: undefined identifier 'unkA50'
u8 ElecTier3Goal_Scan::Update() {
    Character *temp_r29_174;
    Character *temp_r29_93;
    Character *temp_r6_127;
    ElecTier3 *temp_r3_150;
    u32 *temp_r4_180;
    u32 *temp_r4_99;
    u8 var_r30_175;
    u8 var_r30_94;
    u8 var_r3_134;
    u8 var_r4_128;
    void *temp_r5_129;

    ActivateIfInactive();
    temp_r29_93 = this->unkC;
    var_r30_94 = 0;
    if (temp_r29_93->HasAnimFinished() != 0) {
        temp_r4_99 = temp_r29_93->unkA50;
        if ((temp_r4_99 != NULL) && ((u32) *temp_r4_99 == (u32) M2C_FIELD(temp_r29_93->unk630, u32 *, 0x20))) {
            var_r30_94 = 1;
        }
    }
    if (var_r30_94 != 0) {
        ((Enemy *) this->unkC)->SetAnim((AnimSequenceType) 1, 0xA5, 1, 0.0f, 0U, 0U);
        M2C_FIELD(this->unkC->unk630, f32 *, 0x38) = 2.0f;
        this->unk10->EnableScan(1U);
    }
    temp_r6_127 = this->unkC;
    var_r4_128 = 0;
    temp_r5_129 = temp_r6_127->unk630;
    if (((u32) M2C_FIELD(temp_r5_129, u32 *, 0x2C) >> 1U) & 1) {
        var_r3_134 = 0;
        if ((M2C_FIELD(temp_r5_129, f32 *, 0x38) > 0.0f) || ((s32) M2C_FIELD(temp_r5_129, s32 *, 0x44) > 1)) {
            var_r3_134 = 1;
        }
        if (var_r3_134 != 0) {
            var_r4_128 = 1;
        }
    }
    if ((var_r4_128 != 0) && ((temp_r3_150 = this->unk10, (((u8) temp_r3_150->unkB55 == 0) == 0)) || ((s32) M2C_FIELD(temp_r6_127->unk630, s32 *, 0x44) >= 2))) {
        temp_r3_150->EnableScan(0U);
        ((Enemy *) this->unkC)->SetAnim((AnimSequenceType) 1, 0xA5, 2, 0.0f, 0U, 0U);
        M2C_FIELD(this->unkC->unk630, f32 *, 0x38) = 2.0f;
    }
    temp_r29_174 = this->unkC;
    var_r30_175 = 0;
    if (temp_r29_174->HasAnimFinished() != 0) {
        temp_r4_180 = temp_r29_174->unkA50;
        if ((temp_r4_180 != NULL) && ((u32) M2C_FIELD(temp_r4_180, u32 *, 0x40) == (u32) M2C_FIELD(temp_r29_174->unk630, u32 *, 0x20))) {
            var_r30_175 = 1;
        }
    }
    if (var_r30_175 != 0) {
        this->unk8 = 2;
    }
    return this->unk8;
}
#endif

void ElecTier3Goal_Scan::Activate() {
    this->unk8 = 0;
    this->unkC->StopMovement(1U);
    ((Enemy *) this->unkC)->SetAnim((AnimSequenceType) 1, 0xA5, 0, 0.15f, 0U, 0U);
    this->unkC->SetMovementType((CharacterMoveType) 0);
    M2C_FIELD(this->unkC->unk630, f32 *, 0x38) = 2.0f;
}

void ElecTier3Goal_Spawn::Reset() {
    this->unk8 = 1;
    this->unk14 = 0.0f;
}

u8 ElecTier3Goal_Spawn::Update() {
    f32 temp_f1_257;
    f32 var_f0_263;

    ActivateIfInactive();
    temp_f1_257 = this->unk14;
    if (temp_f1_257 < 1.0f) {
        var_f0_263 = temp_f1_257 + gUpdateTimeDelta;
        if (var_f0_263 < 1.0f) {

        } else {
            var_f0_263 = 1.0f;
        }
        this->unk14 = var_f0_263;
        M2C_FIELD(this->unk10, f32 *, 0xB50) = (f32) (0.6f * (1.0f - _table_sinf((3.9826f * this->unk14) + 1.5707964f)));
        if (this->unk14 >= 1.0f) {
            M2C_FIELD(this->unk10, f32 *, 0xB50) = 1.0f;
            M2C_FIELD(this->unkC->unk630, f32 *, 0x38) = 1.0f;
        }
    }
    if (this->unkC->HasAnimFinished() != 0) {
        this->unk8 = 2;
    }
    return this->unk8;
}

void ElecTier3Goal_Spawn::Activate() {
    this->unk8 = 0;
    this->unkC->StopMovement(1U);
    ((Enemy *) this->unkC)->SetAnim((AnimSequenceType) 0xF, 0, 0, 0.15f, 0U, 0U);
    M2C_FIELD(this->unkC->unk630, f32 *, 0x38) = 0.0f;
    this->unkC->SetMovementType((CharacterMoveType) 2);
    PropFlagsSet((unsigned int *) &this->unkC->unk10, 0x40000U);
    M2C_FIELD(this->unk10, f32 *, 0xB50) = 0.0f;
    this->unk14 = 0.0f;
}

void ElecTier3Goal_PatrolMode::Terminate() {
    this->unk8 = 1;
    RemoveAllSubgoals();
}

u8 ElecTier3Goal_PatrolMode::Update() {
    ActivateIfInactive();
    this->unk8 = UpdateSubgoals();
    if (((u8) this->unk8 == 2) && ((u8) M2C_FIELD(this->unk20, u8 *, 0xB55) == 0)) {
        Activate();
    }
    return this->unk8;
}

void ElecTier3Goal_PatrolMode::Activate() {
    Enemy *temp_r3_409;
    Enemy *temp_r3_414;
    Goal<Enemy> *temp_r4_463;
    Goal<Enemy> *temp_r6_432;
    void *temp_r4_415;

    this->unk8 = 0;
    RemoveAllSubgoals();
    temp_r3_409 = this->unkC;
    temp_r3_409->unkB08 &= ~0x40;
    temp_r3_414 = this->unkC;
    temp_r4_415 = temp_r3_414->unkA44;
    if ((temp_r4_415 != NULL) && (M2C_FIELD(temp_r4_415, s32 *, 4) & 2) && (temp_r3_414->HasWaypoints() != 0)) {
        AddSubgoal((Goal<Enemy> *) this->unk2C);
        AddSubgoal((Goal<Enemy> *) this->unk28);
        temp_r6_432 = this->unk2C;
        M2C_FIELD(temp_r6_432, s32 *, 0x10) = (s32) M2C_FIELD(this->unkC->unkA44, s32 *, 0x18);
        M2C_FIELD(temp_r6_432, f32 *, 0x14) = 0.0f;
        M2C_FIELD(temp_r6_432, s32 *, 0x18) = 1;
        M2C_FIELD(temp_r6_432, s32 *, 0x20) = 5;
        M2C_FIELD(temp_r6_432, s32 *, 0x1C) = 0;
        M2C_FIELD(temp_r6_432, u8 *, 0x24) = (u8) (M2C_FIELD(temp_r6_432, u8 *, 0x24) | 0x20);
        M2C_FIELD(temp_r6_432, u8 *, 0x24) = (u8) (M2C_FIELD(temp_r6_432, u8 *, 0x24) & ~0x10);
        M2C_FIELD(temp_r6_432, u8 *, 0x24) = (u8) (M2C_FIELD(temp_r6_432, u8 *, 0x24) & ~8);
        M2C_FIELD(temp_r6_432, u8 *, 0x24) = (u8) (M2C_FIELD(temp_r6_432, u8 *, 0x24) & ~4);
        return;
    }
    AddSubgoal((Goal<Enemy> *) this->unk24);
    AddSubgoal((Goal<Enemy> *) this->unk28);
    temp_r4_463 = this->unk24;
    M2C_FIELD(temp_r4_463, s32 *, 0x10) = 0;
    M2C_FIELD(temp_r4_463, s32 *, 0x14) = 1;
    M2C_FIELD(temp_r4_463, s32 *, 0x18) = 1;
    M2C_FIELD(temp_r4_463, s32 *, 0x1C) = 0;
    M2C_FIELD(temp_r4_463, u8 *, 0x20) = (u8) (M2C_FIELD(temp_r4_463, u8 *, 0x20) & ~0x40);
}

void ElecTier3Goal_PatrolMode::Deinit() {
    Goal<Enemy> *temp_r3_489;
    Goal<Enemy> *temp_r3_494;
    Goal<Enemy> *temp_r3_499;
    void *temp_r31_510;

    temp_r3_489 = this->unk24;
    temp_r3_489->Deinit();
    temp_r3_494 = this->unk2C;
    temp_r3_494->Deinit();
    temp_r3_499 = this->unk28;
    temp_r3_499->Deinit();
    operator delete(this->unk24);
    operator delete(this->unk2C);
    operator delete(this->unk28);
    temp_r31_510 = this->unk1C;
    if (temp_r31_510 != NULL) {
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_510, NULL, 0);
        } else {
            free(temp_r31_510);
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
void ElecTier3Goal_PatrolMode::Init(Enemy *arg0) {
    Goal<Enemy> *temp_r4_648;
    Goal<Enemy> *temp_r4_659;
    Goal<Enemy> *temp_r4_670;
    void *var_r3_628;

    this->unk20 = arg0;
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
        operator new(0x14U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk28 = M2C_ERROR(/* Read from unset register $r3 */);
    }
    if ((u8) this->unk9 == 0) {
        if (MKHeap::Current() != NULL) {
            var_r3_628 = ((MKHeap *) (MKHeap::Current()))->Alloc(8, NULL, 0);
        } else {
            var_r3_628 = malloc(8);
        }
        this->unk1C = var_r3_628;
        this->unk10 = 2;
    }
    this->unk8 = 1;
    this->unkC = arg0;
    this->unk4 = 0x53;
    if ((Enemy *) this->unkC != NULL) {
        this->unk9 = 1;
    }
    temp_r4_648 = this->unk24;
    M2C_FIELD(temp_r4_648, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_648, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_648, s32 *, 4) = 0;
    if ((Enemy *) M2C_FIELD(temp_r4_648, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_648, s8 *, 9) = 1;
    }
    temp_r4_659 = this->unk2C;
    M2C_FIELD(temp_r4_659, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_659, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_659, s32 *, 4) = 0x22;
    if ((Enemy *) M2C_FIELD(temp_r4_659, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_659, s8 *, 9) = 1;
    }
    temp_r4_670 = this->unk28;
    M2C_FIELD(temp_r4_670, Enemy **, 0x10) = arg0;
    M2C_FIELD(temp_r4_670, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_670, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_670, s32 *, 4) = 0xCD;
    if ((Enemy *) M2C_FIELD(temp_r4_670, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_670, s8 *, 9) = 1;
    }
}
#endif

void ElecTier3Goal_Think::StartFollowingSpawnGraph() {
    Enemy *temp_r4_695;

    if (!(((u8) this->unk54 >> 5U) & 1)) {
        temp_r4_695 = this->unkC;
        temp_r4_695->unkB09 |= 8;
        this->unk54 |= 0x20;
    }
}

#if 0 // DRAFT: undefined identifier '__vptr'
void ElecTier3Goal_Think::StopFollowingSpawnGraph() {
    Enemy *temp_r3_729;
    Enemy *temp_r5_716;

    temp_r5_716 = this->unkC;
    temp_r5_716->unkB09 &= ~8;
    if (M2C_FIELD(this->__vptr, u8 (**)(M2C_UNK, Enemy *, M2C_UNK), 0x38)(0x2A, temp_r5_716, 0) != 0) {
        RemoveAllSubgoals();
    }
    temp_r3_729 = this->unkC;
    temp_r3_729->SetupEnemyRegion(temp_r3_729->unk588, 1000.0f);
}
#endif

u8 ElecTier3Goal_Think::IsFollowingSpawnGraph() {
    return ((u8) this->unkC->unkB09 >> 3U) & 1;
}

void ElecTier3Goal_Think::StartFollowingSpawnPath() {
    Enemy *temp_r4_755;

    if (!(((u8) this->unk54 >> 6U) & 1)) {
        temp_r4_755 = this->unkC;
        temp_r4_755->unkB09 |= 0x10;
        this->unk54 |= 0x40;
    }
}

#if 0 // DRAFT: undefined identifier '__vptr'
void ElecTier3Goal_Think::StopFollowingSpawnPath() {
    Enemy *temp_r3_789;
    Enemy *temp_r5_776;

    temp_r5_776 = this->unkC;
    temp_r5_776->unkB09 &= ~0x10;
    if (M2C_FIELD(this->__vptr, u8 (**)(M2C_UNK, Enemy *, M2C_UNK), 0x38)(0x22, temp_r5_776, 0) != 0) {
        RemoveAllSubgoals();
    }
    temp_r3_789 = this->unkC;
    temp_r3_789->SetupEnemyRegion(temp_r3_789->unk588, 1000.0f);
}
#endif

u8 ElecTier3Goal_Think::IsFollowingSpawnPath() {
    return ((u8) this->unkC->unkB09 >> 4U) & 1;
}

#if 0 // DRAFT: undefined identifier '__vptr'
u8 ElecTier3Goal_Think::AddGoal_MoveToLastPlayerPos() {
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
    MKVector3 sp18;
    u8 sp14;
    void *sp10;
    u8 spC;
    void *sp8;
    Enemy *temp_r28_998;
    Enemy *temp_r3_1050;
    Enemy *temp_r3_819;
    Enemy *temp_r3_853;
    Enemy *temp_r3_882;
    Enemy *temp_r3_941;
    Enemy *temp_r3_949;
    Enemy *temp_r4_1022;
    Enemy *temp_r4_1028;
    Enemy *temp_r4_1035;
    Goal<Enemy> *temp_r8_1057;
    f32 temp_f1_1054;
    f32 temp_f1_945;
    f32 temp_f2_948;
    f32 temp_f31_848;
    f64 temp_f0_863;
    f64 temp_f0_960;
    u8 var_r0_823;
    u8 var_r29_999;
    u8 var_r30_883;
    u8 var_r30_929;
    void *temp_r4_873;
    void *temp_r4_970;

    temp_r3_819 = this->unkC;
    var_r0_823 = 0;
    if ((temp_r3_819->unk720 == MKVector3::zero.unk0) && (temp_r3_819->unk724 == MKVector3::zero.unk4) && (temp_r3_819->unk728 == MKVector3::zero.unk8)) {
        var_r0_823 = 1;
    }
    if (var_r0_823 != 0) {
        return 0U;
    }
    if (((u8) this->unk54 >> 4U) & 1) {
        temp_f31_848 = M2C_FIELD(temp_r3_819->__vptr, f32 (**)(), 0x100)();
        sp60 = 0.0f;
        temp_r3_853 = this->unkC;
        sp58 = 0.0f;
        sp5C = 50.0f + temp_f31_848;
        sp80 = (f64) sp60;
        sp78 = (f64) sp58;
        temp_f0_863 = M2C_FIELD(temp_r3_853, f64 *, 0x720) + (f64) sp58;
        sp48 = temp_f0_863;
        spB8 = temp_f0_863;
        sp50 = temp_r3_853->unk728 + (f32) sp80;
        spC0 = (f64) sp50;
        temp_r4_873 = temp_r3_853->unk634;
        sp10 = temp_r4_873;
        if (temp_r4_873 != NULL) {
            sp14 = M2C_FIELD(temp_r4_873, u8 *, 4);
            M2C_FIELD(temp_r4_873, u8 *, 4) = 0U;
        }
        temp_r3_882 = this->unkC;
        var_r30_883 = 0;
        if (((u8) M2C_FIELD(temp_r3_882, u8 *, 0x8B8) == 2) || (temp_r3_882->unk870.unk40.Get() != NULL)) {
            var_r30_883 = 1;
        }
        if ((var_r30_883 == 0) || (MKCollision_SphereCollide(*((MKVector3 *) &spB8), temp_f31_848, NULL, 0, (MKCollisionMode) 7, 0x04000000) != 0)) {
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
    var_r30_929 = 0;
    if (((u8) M2C_FIELD(temp_r3_819, u8 *, 0x8B8) == 2) || (temp_r3_819->unk870.unk40.Get() != NULL)) {
        var_r30_929 = 1;
    }
    if (var_r30_929 != 0) {
        temp_r3_941 = this->unkC;
        temp_f1_945 = temp_r3_941->GetCollisionRadius();
        temp_f2_948 = 50.0f + temp_f1_945;
        temp_r3_949 = this->unkC;
        sp40 = 0.0f;
        sp38 = 0.0f;
        sp3C = temp_f2_948;
        sp70 = (f64) sp40;
        sp68 = (f64) sp38;
        temp_f0_960 = M2C_FIELD(temp_r3_949, f64 *, 0x720) + (f64) sp38;
        sp28 = temp_f0_960;
        spA8 = temp_f0_960;
        sp30 = temp_r3_949->unk728 + (f32) sp70;
        spB0 = (f64) sp30;
        temp_r4_970 = temp_r3_949->unk634;
        sp8 = temp_r4_970;
        if (temp_r4_970 != NULL) {
            spC = M2C_FIELD(temp_r4_970, u8 *, 4);
            M2C_FIELD(temp_r4_970, u8 *, 4) = 0U;
        }
        if (MKCollision_SphereCollide(*((MKVector3 *) &spA8), temp_f1_945, NULL, 0, (MKCollisionMode) 7, 0x04000000) != 0) {
            if (sp8 != NULL) {
                M2C_FIELD(sp8, u8 *, 4) = spC;
            }
            return 0U;
        }
        RemoveAllSubgoals();
        temp_r28_998 = this->unkC;
        var_r29_999 = 0;
        if (temp_r28_998->unk800.IsPointWithin(*((MKVector3 *) &temp_r28_998->unk720)) != 0) {
            sp18 = temp_r28_998->unk800.GetRegionPos();
            if ((f32) fabs(sp18.unk4 - temp_r28_998->unk724) <= 500.0f) {
                var_r29_999 = 1;
            }
        }
        if ((var_r29_999 != 0) && (temp_r4_1022 = this->unkC, ((temp_r4_1022->unk838.IsPointWithin(*((MKVector3 *) &temp_r4_1022->unk720)) == 0) != 0))) {
            temp_r4_1028 = this->unkC;
            temp_r4_1028->unk8C0.Set(*((MKVector3 *) &temp_r4_1028->unk720), 0U);
        } else {
            temp_r4_1035 = this->unkC;
            temp_r4_1035->unk800.GetNearestPointOnBoundingRegion(*((MKVector3 *) &temp_r4_1035->unk720), &sp98, &sp88);
            this->unkC->unk8C0.Set(sp98, 0U);
        }
        AddSubgoal((Goal<Enemy> *) this->unk44);
        temp_r3_1050 = this->unkC;
        temp_f1_1054 = temp_r3_1050->GetCollisionRadius();
        temp_r8_1057 = this->unk44;
        M2C_FIELD(temp_r8_1057, AITargetData **, 0x10) = &this->unkC->unk8C0;
        M2C_FIELD(temp_r8_1057, f32 *, 0x18) = temp_f1_1054;
        M2C_FIELD(temp_r8_1057, u8 *, 0x30) = (u8) (M2C_FIELD(temp_r8_1057, u8 *, 0x30) | 0x80);
        M2C_FIELD(temp_r8_1057, s32 *, 0x20) = 2;
        M2C_FIELD(temp_r8_1057, s32 *, 0x24) = 0;
        M2C_FIELD(temp_r8_1057, s32 *, 0x28) = -1;
        M2C_FIELD(temp_r8_1057, u8 *, 0x30) = (u8) (M2C_FIELD(temp_r8_1057, u8 *, 0x30) | 0x40);
        M2C_FIELD(temp_r8_1057, u8 *, 0x30) = (u8) (M2C_FIELD(temp_r8_1057, u8 *, 0x30) | 0x20);
        M2C_FIELD(temp_r8_1057, u8 *, 0x30) = (u8) (M2C_FIELD(temp_r8_1057, u8 *, 0x30) | 0x10);
        this->unkC->unk8C0.SetInsideRegion(1U);
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

void ElecTier3Goal_Think::AddGoal_FollowSpawnGraph() {
    Enemy *temp_r3_1128;
    Enemy *temp_r3_1133;

    if (IsPresent(0x2A) == 0) {
        RemoveAllSubgoals();
        AddSubgoal((Goal<Enemy> *) this->unk40);
        temp_r3_1128 = this->unkC;
        temp_r3_1128->unkB09 |= 8;
        temp_r3_1133 = this->unkC;
        temp_r3_1133->unkB08 |= 0x40;
    }
}

void ElecTier3Goal_Think::AddGoal_FollowSpawnPath() {
    Enemy *temp_r3_1190;
    Enemy *temp_r3_1194;
    Goal<Enemy> *temp_r6_1170;

    if (IsPresent(0x22) == 0) {
        RemoveAllSubgoals();
        AddSubgoal((Goal<Enemy> *) this->unk3C);
        temp_r6_1170 = this->unk3C;
        M2C_FIELD(temp_r6_1170, Enemy **, 0x10) = (Enemy *) this->unkC->unkA94;
        M2C_FIELD(temp_r6_1170, f32 *, 0x14) = 0.0f;
        M2C_FIELD(temp_r6_1170, s32 *, 0x18) = 1;
        M2C_FIELD(temp_r6_1170, AITargetData **, 0x20) = (AITargetData *) this->unk4C;
        M2C_FIELD(temp_r6_1170, s32 *, 0x1C) = (s32) this->unk50;
        M2C_FIELD(temp_r6_1170, u8 *, 0x24) = (u8) (M2C_FIELD(temp_r6_1170, u8 *, 0x24) & ~0x20);
        M2C_FIELD(temp_r6_1170, u8 *, 0x24) = (u8) (M2C_FIELD(temp_r6_1170, u8 *, 0x24) & ~0x10);
        M2C_FIELD(temp_r6_1170, u8 *, 0x24) = (u8) (M2C_FIELD(temp_r6_1170, u8 *, 0x24) & ~8);
        M2C_FIELD(temp_r6_1170, u8 *, 0x24) = (u8) (M2C_FIELD(temp_r6_1170, u8 *, 0x24) & ~4);
        temp_r3_1190 = this->unkC;
        temp_r3_1190->unkB09 |= 0x10;
        temp_r3_1194 = this->unkC;
        temp_r3_1194->unkB08 |= 0x40;
        ((KDPathIterator *) &this->unkC->unkA94)->Init();
    }
}

#if 0 // DRAFT: undefined identifier '__vptr'
void ElecTier3Goal_Think::AddGoal_Spawn() {
    Goal<Enemy> *temp_r3_1217;

    temp_r3_1217 = this->unk38;
    if ((temp_r3_1217 != NULL) && (IsPresent(M2C_FIELD(temp_r3_1217->__vptr, s32 (**)(), 0x34)()) == 0)) {
        this->unk54 |= 0x80;
        RemoveAllSubgoals();
        AddSubgoal((Goal<Enemy> *) this->unk38);
    }
}
#endif

void ElecTier3Goal_Think::AddGoal_Respawn() {
    if (IsPresent(0x1E) == 0) {
        RemoveAllSubgoals();
        AddSubgoal((Goal<Enemy> *) this->unk34);
    }
}

void ElecTier3Goal_Think::AddGoal_Death(EnemyDamageFeedback *arg0) {
    s32 temp_r0_1346;
    s32 temp_r0_1398;
    u8 var_r30_1286;
    u8 var_r30_1304;

    var_r30_1286 = 0;
    if ((s32) arg0->unk28 == 6) {
        if (IsActive(0x11) == 0) {
            AddGoal_Hit(arg0);
            var_r30_1286 = 1;
        }
    } else {
        var_r30_1304 = 0;
        if ((IsActive(0x11) == 0) && ((IsActive(0xB) != 0) || (IsActive(0x13) != 0) || (IsActive(0xC) != 0))) {
            var_r30_1304 = 1;
        }
        if (var_r30_1304 != 0) {
            AddGoal_Hit(arg0);
            var_r30_1286 = 1;
        } else {
            temp_r0_1346 = arg0->unk28;
            if ((temp_r0_1346 == 2) || (temp_r0_1346 == 8) || (temp_r0_1346 == 0xA)) {
                AddGoal_Hit(arg0);
                var_r30_1286 = 1;
            } else {
                var_r30_1286 = 0;
                if ((IsActive(0xC) != 0) || (IsActive(0xD) != 0)) {
                    var_r30_1286 = 1;
                }
            }
        }
    }
    if (IsPresent(0x5B) == 0) {
        if (var_r30_1286 != 0) {
loop_22:
            temp_r0_1398 = this->unk14;
            if (temp_r0_1398 > 1) {
                if (temp_r0_1398 > 0) {
                    this->unk14 -= 1;
                }
                goto loop_22;
            }
        } else {
            RemoveAllSubgoals();
        }
        AddSubgoal((Goal<Enemy> *) this->unk30);
    }
}

void ElecTier3Goal_Think::AddGoal_Hit(EnemyDamageFeedback *arg0) {
    Enemy *temp_r3_1599;
    Enemy *temp_r4_1658;
    f32 var_f31_1432;
    s32 temp_r0_1567;
    s32 temp_r0_1636;
    s32 temp_r3_1564;
    s32 temp_r3_1637;
    s32 var_r26_1429;
    u32 temp_r0_1579;
    u8 temp_r21_1449;
    u8 temp_r22_1456;
    u8 temp_r23_1463;
    u8 temp_r27_1435;
    u8 temp_r28_1470;
    u8 temp_r29_1477;
    u8 temp_r30_1484;
    u8 temp_r31_1442;
    u8 temp_r31_1492;
    void *temp_r3_1549;

    var_r26_1429 = arg0->unk28;
    var_f31_1432 = 0.0f;
    temp_r27_1435 = IsActive(8);
    temp_r31_1442 = IsActive(0xB);
    temp_r21_1449 = IsActive(0xE);
    temp_r22_1456 = IsActive(0xC);
    temp_r23_1463 = IsActive(0x13);
    temp_r28_1470 = IsActive(0x12);
    temp_r29_1477 = IsActive(0xD);
    temp_r30_1484 = IsActive(0x26);
    temp_r31_1492 = IsActive(0x3B);
    if ((temp_r31_1442 != 0) || (temp_r23_1463 != 0)) {
        switch (var_r26_1429) {                     /* switch 1 */
        case 4:                                     /* switch 1 */
        case 5:                                     /* switch 1 */
        case 7:                                     /* switch 1 */
        case 9:                                     /* switch 1 */
        case 11:                                    /* switch 1 */
            if (var_r26_1429 != 0xB) {
                this->unkC->ThawIfFrozen();
            }
            var_r26_1429 = 9;
            break;
        case 10:                                    /* switch 1 */
            var_f31_1432 = 3000.0f;
            break;
        default:                                    /* switch 1 */
            var_f31_1432 = 500.0f;
            var_r26_1429 = 3;
            break;
        }
    } else if (((temp_r22_1456 != 0) || (temp_r21_1449 != 0)) && (((u32) (var_r26_1429 - 4) <= 1U) || (var_r26_1429 == 2))) {
        var_r26_1429 = 0xE;
    } else {
        switch (var_r26_1429) {                     /* switch 2; irregular */
        case 3:                                     /* switch 2 */
        case 9:                                     /* switch 2 */
            var_r26_1429 = 1;
            break;
        case 10:                                    /* switch 2 */
            var_r26_1429 = 8;
            break;
        }
    }
    temp_r3_1549 = this->unkC->unkA00;
    if ((temp_r3_1549 != NULL) && ((u8) M2C_FIELD(temp_r3_1549, u8 *, 0x20) != 0) && (arg0->unk20 & 0x47F1)) {
        RemoveAllSubgoals();
    }
    if (var_r26_1429 == 9) {
        temp_r3_1564 = this->unkC->unkAF4;
        if ((temp_r3_1564 >= 3) && (((temp_r0_1567 = arg0->unk28, ((temp_r0_1567 == 4) == 0)) && (temp_r0_1567 != 5)) || (temp_r3_1564 >= 6))) {
            var_r26_1429 = 0xE;
        }
    }
    temp_r0_1579 = ((u8) arg0->unk34 >> 4U) & 1;
    if ((temp_r0_1579 != 0) && (this->unkC->unkACC <= 0.0f) && ((var_r26_1429 == 0) || (var_r26_1429 == 4) || (var_r26_1429 == 5))) {
        var_r26_1429 = 7;
    } else if (temp_r0_1579 != 0) {
        temp_r3_1599 = this->unkC;
        if (temp_r3_1599->unkACC <= 0.0f) {
            temp_r3_1599->Armour_Destroy();
        }
    }
    if (var_r26_1429 != 0xE) {
        if (IsActive(0x59) != 0) {
            if ((var_r26_1429 != 0) && ((var_r26_1429 != 1) || (temp_r27_1435 != 0)) && (temp_r28_1470 == 0)) {
                if (temp_r29_1477 != 0) {
                    return;
                }
                if ((s32) this->unk14 > 0) {
                    this->unk18 += 1;
                    temp_r0_1636 = this->unk18;
                    temp_r3_1637 = this->unk10;
                    if (temp_r0_1636 >= temp_r3_1637) {
                        this->unk18 = temp_r0_1636 - temp_r3_1637;
                    }
                    this->unk14 -= 1;
                }
                goto block_50;
            }
        } else {
block_50:
            if ((temp_r30_1484 != 0) || (temp_r31_1492 != 0)) {
                RemoveAllSubgoals();
            }
            arg0->unk28 = var_r26_1429;
            arg0->unk18 = var_f31_1432;
            temp_r4_1658 = this->unkC;
            temp_r4_1658->unk910 = arg0->unk0;
            M2C_FIELD(temp_r4_1658, f64 *, 0x918) = (f64) arg0->unk8;
            temp_r4_1658->unk920 = arg0->unk10;
            temp_r4_1658->unk924 = arg0->unk14;
            temp_r4_1658->unk928 = arg0->unk18;
            temp_r4_1658->unk92C = arg0->unk1C;
            temp_r4_1658->unk930 = arg0->unk20;
            temp_r4_1658->unk934 = arg0->unk24;
            temp_r4_1658->unk938 = arg0->unk28;
            temp_r4_1658->unk93C = arg0->unk2C;
            temp_r4_1658->unk940 = arg0->unk30;
            temp_r4_1658->unk944 = arg0->unk34;
            AddSubgoalToFront((Goal<Enemy> *) this->unk2C);
        }
    }
}

void ElecTier3Goal_Think::AddGoal_AlertMode() {
    Goal<Enemy> *temp_r5_1717;

    if (IsPresent(0x54) == 0) {
        RemoveAllSubgoals();
        AddSubgoal((Goal<Enemy> *) this->unk28);
        temp_r5_1717 = this->unk28;
        M2C_FIELD(temp_r5_1717, AITargetData **, 0x20) = &this->unkC->unk870;
        M2C_FIELD(temp_r5_1717, s32 *, 0x4C) = 3;
        M2C_FIELD(temp_r5_1717, u8 *, 0x50) = (u8) (M2C_FIELD(temp_r5_1717, u8 *, 0x50) | 0x80);
    }
}

void ElecTier3Goal_Think::AddGoal_PatrolMode() {
    if (IsPresent(0x53) == 0) {
        RemoveAllSubgoals();
        AddSubgoal((Goal<Enemy> *) this->unk24);
    }
}

void ElecTier3Goal_Think::Reset() {
    this->unk8 = 1;
    RemoveAllSubgoals();
    this->unk54 &= ~0x80;
}

#if 0 // DRAFT: undefined identifier '__vptr'
void ElecTier3Goal_Think::Arbitrate() {
    EnemyDamageFeedback sp8;
    ElecTier3 *temp_r3_1863;
    Enemy *temp_r3_1812;
    Enemy *temp_r3_1853;
    Enemy *temp_r3_1876;
    Enemy *temp_r3_1933;
    Enemy *temp_r3_1979;
    Enemy *temp_r3_2006;
    Enemy *temp_r3_2020;
    Enemy *temp_r3_2033;
    Enemy *temp_r3_2064;
    Enemy *temp_r4_1792;
    Enemy *temp_r4_1950;
    Enemy *temp_r4_1957;
    Goal<Enemy> *temp_r3_1844;
    Goal<Enemy> *temp_r3_1923;
    f32 temp_f31_2023;
    u8 var_r30_1813;
    u8 var_r30_1938;
    u8 var_r30_2007;
    u8 var_r30_2034;

    temp_r4_1792 = this->unkC;
    if (!(((u8) temp_r4_1792->unkB09 >> 7U) & 1)) {
        AddGoal_Respawn();
        return;
    }
    if (!(((u8) this->unk54 >> 7U) & 1)) {
        AddGoal_Spawn();
        return;
    }
    if (temp_r4_1792->WasHit() != 0) {
        sp8.Init();
        temp_r3_1812 = this->unkC;
        var_r30_1813 = 0;
        if (((u8) M2C_FIELD(temp_r3_1812, u8 *, 0x8B8) == 2) || (temp_r3_1812->unk870.unk40.Get() != NULL)) {
            var_r30_1813 = 1;
        }
        if (var_r30_1813 != 0) {
            this->unk20->unkB55 = 1;
        }
        if (IsFollowingSpawnPath() != 0) {
            StopFollowingSpawnPath();
        }
        if (IsFollowingSpawnGraph() != 0) {
            StopFollowingSpawnGraph();
        }
        temp_r3_1844 = this->unk38;
        if ((temp_r3_1844 != NULL) && (M2C_FIELD(temp_r3_1844->__vptr, u8 (**)(), 0x28)() != 0)) {
            temp_r3_1853 = this->unkC;
            temp_r3_1853->unk9D8 = 0;
            temp_r3_1853->unk9D4 = 0;
        } else {
            this->unkC->TakeDamage(&sp8, 0U);
            temp_r3_1863 = this->unk20;
            if ((u8) temp_r3_1863->unkB54 != 0) {
                temp_r3_1863->EnableScan(0U);
            }
        }
        if ((sp8.unk20 & 4) && (sp8.unk2C == 0)) {
            temp_r3_1876 = this->unkC;
            if ((temp_r3_1876->unkAC8 <= 0.0f) || (M2C_FIELD(temp_r3_1876->__vptr, u8 (**)(s32, M2C_UNK, f32, f32), 0x1D0)(((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1DU) & 1, 1, sp8.unk24, 1.0f) != 0)) {
                sp8.unk28 = 0xB;
            } else {
                sp8.unk28 = 0xE;
            }
        }
        if (this->unkC->unkAC8 <= 0.0f) {
            AddGoal_Death(&sp8);
            return;
        }
        if (sp8.unk28 != 0xE) {
            AddGoal_Hit(&sp8);
            return;
        }
        goto block_29;
    }
block_29:
    temp_r3_1923 = this->unk38;
    if ((temp_r3_1923 == NULL) || (M2C_FIELD(temp_r3_1923->__vptr, u8 (**)(), 0x28)() == 0)) {
        temp_r3_1933 = this->unkC;
        if (((u8) temp_r3_1933->unkB0A >> 7U) & 1) {
            var_r30_1938 = 0;
            if (((u8) M2C_FIELD(temp_r3_1933, u8 *, 0x8B8) == 2) || (temp_r3_1933->unk870.unk40.Get() != NULL)) {
                var_r30_1938 = 1;
            }
            if (var_r30_1938 != 0) {
                temp_r4_1950 = this->unkC;
                temp_r4_1950->unkB0A &= ~0x80;
                temp_r4_1957 = this->unkC;
                temp_r4_1957->unkB08 |= 0x40;
                AddGoal_AlertMode();
                return;
            }
            goto block_37;
        }
block_37:
        if (IsFollowingSpawnPath() != 0) {
            AddGoal_FollowSpawnPath();
        }
        if (IsFollowingSpawnGraph() != 0) {
            AddGoal_FollowSpawnGraph();
            return;
        }
        temp_r3_1979 = this->unkC;
        if ((temp_r3_1979->unkAC8 > 0.0f) && (M2C_FIELD(temp_r3_1979->__vptr, u8 (**)(), 0x134)() == 0) && (this->unkC->IsFlinching(), (((u8) M2C_ERROR(/* Read from unset register $r3 */) == 0) != 0)) && (IsPresent(0x28) == 0)) {
            if ((u8) this->unk20->unkB55 != 0) {
                temp_r3_2006 = this->unkC;
                var_r30_2007 = 0;
                if (((u8) M2C_FIELD(temp_r3_2006, u8 *, 0x8B8) == 2) || (temp_r3_2006->unk870.unk40.Get() != NULL)) {
                    var_r30_2007 = 1;
                }
                if ((var_r30_2007 == 0) || (temp_r3_2020 = this->unkC, temp_f31_2023 = temp_r3_2020->unkA38->unk134, ((temp_r3_2020->unk870.GetDistSq() > (temp_f31_2023 * temp_f31_2023)) != 0))) {
                    this->unk20->unkB55 = 0;
                }
            }
            temp_r3_2033 = this->unkC;
            var_r30_2034 = 0;
            if (((u8) M2C_FIELD(temp_r3_2033, u8 *, 0x8B8) == 2) || (temp_r3_2033->unk870.unk40.Get() != NULL)) {
                var_r30_2034 = 1;
            }
            if ((var_r30_2034 != 0) && (this->unkC->unk870.IsAttackable() != 0) && ((u8) this->unk20->unkB55 != 0) && (IsActive(0xCD) == 0)) {
                temp_r3_2064 = this->unkC;
                if (temp_r3_2064->IsTargetBehindWall() == 0) {
                    AddGoal_AlertMode();
                    StopFollowingSpawnPath();
                    return;
                }
            }
            if ((AddGoal_MoveToLastPlayerPos() == 0) && ((IsPresent(2) == 0) || (((u8) this->unkC->unkB08 >> 6U) & 1)) && (IsFollowingSpawnPath() == 0)) {
                AddGoal_PatrolMode();
            }
        }
    }
}
#endif

void ElecTier3Goal_Think::Terminate() {
    this->unk8 = 1;
    RemoveAllSubgoals();
}

u8 ElecTier3Goal_Think::Update() {
    Enemy *temp_r3_2140;

    if (this->unkC->WasHit() != 0) {
        this->unk8 = 1;
    }
    temp_r3_2140 = this->unkC;
    if (temp_r3_2140->IsDead() == 0) {
        this->unkC->SelectTarget();
    }
    ActivateIfInactive();
    this->unk8 = UpdateSubgoals();
    if ((u8) this->unk8 != 0) {
        Activate();
        this->unk54 &= ~0x10;
    }
    return this->unk8;
}

void ElecTier3Goal_Think::Activate() {
    this->unk8 = 0;
    if ((Enemy *) this->unkC->unkA94 != NULL) {
        StartFollowingSpawnPath();
    }
    if ((u32) this->unkC->unkA80 != 0) {
        StartFollowingSpawnGraph();
    }
    Arbitrate();
}

void ElecTier3Goal_Think::Deinit() {
    Goal<Enemy> *temp_r3_2219;
    Goal<Enemy> *temp_r3_2224;
    Goal<Enemy> *temp_r3_2229;
    Goal<Enemy> *temp_r3_2234;
    Goal<Enemy> *temp_r3_2239;
    Goal<Enemy> *temp_r3_2244;
    Goal<Enemy> *temp_r3_2249;
    Goal<Enemy> *temp_r3_2254;
    Goal<Enemy> *temp_r3_2264;
    void **temp_r3_2259;
    void *temp_r31_2289;

    temp_r3_2219 = this->unk24;
    temp_r3_2219->Deinit();
    temp_r3_2224 = this->unk28;
    temp_r3_2224->Deinit();
    temp_r3_2229 = this->unk2C;
    temp_r3_2229->Deinit();
    temp_r3_2234 = this->unk30;
    temp_r3_2234->Deinit();
    temp_r3_2239 = this->unk34;
    temp_r3_2239->Deinit();
    temp_r3_2244 = this->unk38;
    temp_r3_2244->Deinit();
    temp_r3_2249 = this->unk3C;
    temp_r3_2249->Deinit();
    temp_r3_2254 = this->unk40;
    temp_r3_2254->Deinit();
    temp_r3_2259 = this->unk48;
    M2C_FIELD(*temp_r3_2259, M2C_UNK (**)(void **), 0xC)(temp_r3_2259);
    temp_r3_2264 = this->unk44;
    temp_r3_2264->Deinit();
    operator delete(this->unk24);
    operator delete(this->unk28);
    operator delete(this->unk2C);
    operator delete(this->unk30);
    operator delete(this->unk34);
    operator delete(this->unk38);
    operator delete(this->unk3C);
    operator delete(this->unk40);
    operator delete(this->unk48);
    operator delete(this->unk44);
    temp_r31_2289 = this->unk1C;
    if (temp_r31_2289 != NULL) {
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_2289, NULL, 0);
        } else {
            free(temp_r31_2289);
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
void ElecTier3Goal_Think::Init(Enemy *arg0) {
    Goal<Enemy> *temp_r4_2614;
    Goal<Enemy> *temp_r4_2625;
    Goal<Enemy> *temp_r4_2637;
    Goal<Enemy> *temp_r5_2663;
    void **temp_r4_2651;
    void *var_r3_2582;

    this->unk20 = (ElecTier3 *) arg0;
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
        operator new(0x10U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk34 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x18U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk38 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x28U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk3C = M2C_ERROR(/* Read from unset register $r3 */);
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
        this->unk40 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x34U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk44 = M2C_ERROR(/* Read from unset register $r3 */);
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
    if ((u8) this->unk9 == 0) {
        if (MKHeap::Current() != NULL) {
            var_r3_2582 = ((MKHeap *) (MKHeap::Current()))->Alloc(8, NULL, 0);
        } else {
            var_r3_2582 = malloc(8);
        }
        this->unk1C = var_r3_2582;
        this->unk10 = 2;
    }
    this->unk8 = 1;
    this->unkC = arg0;
    this->unk4 = 0x5C;
    if ((Enemy *) this->unkC != NULL) {
        this->unk9 = 1;
    }
    ((ElecTier3Goal_PatrolMode *) this->unk24)->Init(arg0);
    ((EnemyGoal_AlertMode *) this->unk28)->Init(arg0);
    ((EnemyGoal_Hit *) this->unk2C)->Init(arg0);
    ((EnemyGoal_Death *) this->unk30)->Init(arg0);
    temp_r4_2614 = this->unk34;
    M2C_FIELD(temp_r4_2614, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_2614, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_2614, s32 *, 4) = 0x1E;
    if ((Enemy *) M2C_FIELD(temp_r4_2614, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_2614, s8 *, 9) = 1;
    }
    temp_r4_2625 = this->unk38;
    M2C_FIELD(temp_r4_2625, Enemy **, 0x10) = arg0;
    M2C_FIELD(temp_r4_2625, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_2625, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_2625, s32 *, 4) = 0x38;
    if ((Enemy *) M2C_FIELD(temp_r4_2625, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_2625, s8 *, 9) = 1;
    }
    temp_r4_2637 = this->unk3C;
    M2C_FIELD(temp_r4_2637, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_2637, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_2637, s32 *, 4) = 0x22;
    if ((Enemy *) M2C_FIELD(temp_r4_2637, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_2637, s8 *, 9) = 1;
    }
    ((EnemyGoal_FollowGraph *) this->unk40)->Init(arg0);
    temp_r4_2651 = this->unk48;
    M2C_FIELD(temp_r4_2651, Enemy **, 0x10) = arg0;
    M2C_FIELD(temp_r4_2651, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_2651, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_2651, s32 *, 4) = 0xCE;
    if ((Enemy *) M2C_FIELD(temp_r4_2651, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_2651, s8 *, 9) = 1;
    }
    temp_r5_2663 = this->unk44;
    M2C_FIELD(temp_r5_2663, s8 *, 8) = 1;
    M2C_FIELD(temp_r5_2663, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r5_2663, s32 *, 4) = 0x21;
    if ((Enemy *) M2C_FIELD(temp_r5_2663, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r5_2663, s8 *, 9) = 1;
    }
    M2C_FIELD(temp_r5_2663, u8 *, 0x30) = (u8) (M2C_FIELD(temp_r5_2663, u8 *, 0x30) & ~0x10);
    this->unk54 &= ~0x40;
    this->unk54 &= ~0x20;
    this->unk54 &= ~0x80;
    this->unk54 &= ~0x10;
    this->unk4C = (AITargetData *)6;
    this->unk50 = 0;
}
#endif
