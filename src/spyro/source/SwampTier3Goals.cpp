#include "spyro/source/SwampTier3Goals.h"
#include "common/Source/Animation.h"
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
#include "common/Source/MKResource.h"
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
#include "spyro/source/EarthShockwave.h"
#include "spyro/source/Enemies_Swamp.h"
#include "spyro/source/Enemy.h"
#include "spyro/source/EnemyAttackPattern.h"
#include "spyro/source/EnemyDataTypes.h"
#include "spyro/source/EnemyDescriptor.h"
#include "spyro/source/EnemyGoal_AlertMode.h"
#include "spyro/source/EnemyGoal_FollowGraph.h"
#include "spyro/source/EnemyGoals_Death.h"
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
#include "spyro/source/KDMath.h"
#include <m2c_macros.h>

M2C_UNK free(void *);                               /* extern */
void *malloc(M2C_UNK);                              /* extern */
extern s32 gViewSeed;
extern M2C_UNK gb;

void SwampTier3Goal_Patrol::Terminate() {
    this->unk8 = 1;
    RemoveAllSubgoals();
}

u8 SwampTier3Goal_Patrol::Update() {
    ActivateIfInactive();
    this->unk8 = UpdateSubgoals();
    if ((u8) this->unk8 == 2) {
        Activate();
    }
    return this->unk8;
}

void SwampTier3Goal_Patrol::Activate() {
    Enemy *temp_r3_123;
    Enemy *temp_r3_63;
    Enemy *temp_r4_68;
    Goal<SwampTier3> *temp_r4_96;
    Goal<SwampTier3> *temp_r5_112;
    Goal<SwampTier3> *temp_r5_174;
    Goal<SwampTier3> *temp_r7_142;
    f32 temp_f1_139;
    s32 temp_r30_110;
    s32 temp_r3_111;
    s32 temp_r3_94;
    u8 temp_r5_69;
    u8 var_r30_64;
    void *temp_r4_124;

    this->unk8 = 0;
    RemoveAllSubgoals();
    temp_r3_63 = this->unkC;
    var_r30_64 = 0;
    temp_r3_63->unkB08 &= ~0x40;
    temp_r4_68 = this->unkC;
    temp_r5_69 = M2C_FIELD(temp_r4_68, u8 *, 0xB10);
    if ((temp_r5_69 == 0) && (M2C_FIELD(&gb, f32 *, 0x30C) >= M2C_FIELD(temp_r4_68, f32 *, 0xB14))) {
        var_r30_64 = 1;
    }
    if ((var_r30_64 != 0) || (temp_r5_69 != 0)) {
        M2C_FIELD(temp_r4_68, u8 *, 0xB10) = 1U;
        AddSubgoal((Goal<SwampTier3> *) this->unk24);
        temp_r3_94 = MKRand_Int((int *) &gViewSeed, 1, 3);
        temp_r4_96 = this->unk24;
        M2C_FIELD(temp_r4_96, s8 *, 0x14) = (s8) (var_r30_64 == 0);
        M2C_FIELD(temp_r4_96, s32 *, 0x10) = temp_r3_94;
    } else {
        AddSubgoal((Goal<SwampTier3> *) this->unk20);
        temp_r30_110 = this->unkC->unk688;
        temp_r3_111 = MKRand_Int((int *) &gViewSeed, 1, 3);
        temp_r5_112 = this->unk20;
        M2C_FIELD(temp_r5_112, s32 *, 0x10) = 0;
        M2C_FIELD(temp_r5_112, s32 *, 0x14) = temp_r3_111;
        M2C_FIELD(temp_r5_112, s32 *, 0x18) = 1;
        M2C_FIELD(temp_r5_112, s32 *, 0x1C) = temp_r30_110;
        M2C_FIELD(temp_r5_112, u8 *, 0x20) = (u8) (M2C_FIELD(temp_r5_112, u8 *, 0x20) & ~0x40);
    }
    temp_r3_123 = this->unkC;
    temp_r4_124 = temp_r3_123->unkA44;
    if ((temp_r4_124 != NULL) && (M2C_FIELD(temp_r4_124, s32 *, 4) & 2)) {
        if (temp_r3_123->HasWaypoints() != 0) {
            AddSubgoal((Goal<SwampTier3> *) this->unk28);
            temp_f1_139 = MKRand_Float((int *) &gViewSeed, 5.0f, 10.0f);
            temp_r7_142 = this->unk28;
            M2C_FIELD(temp_r7_142, s32 *, 0x10) = (s32) M2C_FIELD(this->unkC->unkA44, s32 *, 0x18);
            M2C_FIELD(temp_r7_142, f32 *, 0x14) = temp_f1_139;
            M2C_FIELD(temp_r7_142, s32 *, 0x18) = 0xC;
            M2C_FIELD(temp_r7_142, s32 *, 0x20) = 5;
            M2C_FIELD(temp_r7_142, s32 *, 0x1C) = 0x12;
            M2C_FIELD(temp_r7_142, u8 *, 0x24) = (u8) (M2C_FIELD(temp_r7_142, u8 *, 0x24) & ~0x20);
            M2C_FIELD(temp_r7_142, u8 *, 0x24) = (u8) (M2C_FIELD(temp_r7_142, u8 *, 0x24) & ~0x10);
            M2C_FIELD(temp_r7_142, u8 *, 0x24) = (u8) (M2C_FIELD(temp_r7_142, u8 *, 0x24) & ~8);
            M2C_FIELD(temp_r7_142, u8 *, 0x24) = (u8) (M2C_FIELD(temp_r7_142, u8 *, 0x24) & ~4);
            return;
        }
        AddSubgoal((Goal<SwampTier3> *) this->unk2C);
        temp_r5_174 = this->unk2C;
        M2C_FIELD(temp_r5_174, f32 *, 0x10) = MKRand_Float((int *) &gViewSeed, 5.0f, 10.0f);
        M2C_FIELD(temp_r5_174, s32 *, 0x14) = 0xC;
        M2C_FIELD(temp_r5_174, s32 *, 0x1C) = 5;
        M2C_FIELD(temp_r5_174, s32 *, 0x18) = 0x12;
    }
}

void SwampTier3Goal_Patrol::Deinit() {
    Goal<SwampTier3> *temp_r3_198;
    Goal<SwampTier3> *temp_r3_203;
    Goal<SwampTier3> *temp_r3_208;
    void *temp_r31_221;

    temp_r3_198 = this->unk20;
    temp_r3_198->Deinit();
    temp_r3_203 = this->unk24;
    temp_r3_203->Deinit();
    temp_r3_208 = this->unk28;
    temp_r3_208->Deinit();
    operator delete(this->unk20);
    operator delete(this->unk24);
    operator delete(this->unk28);
    operator delete(this->unk2C);
    temp_r31_221 = this->unk1C;
    if (temp_r31_221 != NULL) {
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_221, NULL, 0);
        } else {
            free(temp_r31_221);
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
void SwampTier3Goal_Patrol::Init(SwampTier3 *arg0) {
    Goal<SwampTier3> *temp_r4_378;
    Goal<SwampTier3> *temp_r4_389;
    Goal<SwampTier3> *temp_r4_400;
    Goal<SwampTier3> *temp_r4_411;
    void *var_r3_358;

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
        operator new(0x18U, NULL, 0);
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
    }
    if ((u8) this->unk9 == 0) {
        if (MKHeap::Current() != NULL) {
            var_r3_358 = ((MKHeap *) (MKHeap::Current()))->Alloc(8, NULL, 0);
        } else {
            var_r3_358 = malloc(8);
        }
        this->unk1C = var_r3_358;
        this->unk10 = 2;
    }
    this->unk8 = 1;
    this->unkC = (Enemy *) arg0;
    this->unk4 = 0x53;
    if ((Enemy *) this->unkC != NULL) {
        this->unk9 = 1;
    }
    temp_r4_378 = this->unk20;
    M2C_FIELD(temp_r4_378, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_378, SwampTier3 **, 0xC) = arg0;
    M2C_FIELD(temp_r4_378, s32 *, 4) = 0;
    if ((SwampTier3 *) M2C_FIELD(temp_r4_378, SwampTier3 **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_378, s8 *, 9) = 1;
    }
    temp_r4_389 = this->unk24;
    M2C_FIELD(temp_r4_389, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_389, SwampTier3 **, 0xC) = arg0;
    M2C_FIELD(temp_r4_389, s32 *, 4) = 5;
    if ((SwampTier3 *) M2C_FIELD(temp_r4_389, SwampTier3 **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_389, s8 *, 9) = 1;
    }
    temp_r4_400 = this->unk28;
    M2C_FIELD(temp_r4_400, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_400, SwampTier3 **, 0xC) = arg0;
    M2C_FIELD(temp_r4_400, s32 *, 4) = 0x22;
    if ((SwampTier3 *) M2C_FIELD(temp_r4_400, SwampTier3 **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_400, s8 *, 9) = 1;
    }
    temp_r4_411 = this->unk2C;
    M2C_FIELD(temp_r4_411, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_411, SwampTier3 **, 0xC) = arg0;
    M2C_FIELD(temp_r4_411, s32 *, 4) = 0x23;
    if ((SwampTier3 *) M2C_FIELD(temp_r4_411, SwampTier3 **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_411, s8 *, 9) = 1;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk6F8'
void SwampTier3Goal_Cower::Terminate() {
    this->unkC->unk6F8 = 0;
    this->unk8 = 1;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk8B0'
u8 SwampTier3Goal_Cower::Update() {
    AnimSequence *temp_r4_471;
    AnimSequence *temp_r4_486;
    AnimSequence *temp_r4_514;
    AnimSequence *temp_r4_524;
    Character *temp_r29_465;
    Character *temp_r29_518;
    Character *temp_r3_483;
    Character *temp_r3_511;
    Character *temp_r5_458;
    Character *temp_r5_490;
    SpawnerObject *temp_r3_496;
    u8 var_r30_466;
    u8 var_r30_519;

    ActivateIfInactive();
    if (this->unkC->unk8B0.Get() != NULL) {
        temp_r5_458 = this->unkC;
        M2C_FIELD(this->unkC->unk8B0.Get()->__vptr, M2C_UNK (**)(MKVector3 *, M2C_UNK *), 0x28)(&temp_r5_458->unk588, &temp_r5_458->unk700);
    }
    temp_r29_465 = this->unkC;
    var_r30_466 = 0;
    if (temp_r29_465->HasAnimFinished() != 0) {
        temp_r4_471 = temp_r29_465->unkA50;
        if ((temp_r4_471 != NULL) && ((u32) temp_r4_471->unk0 == (u32) M2C_FIELD(temp_r29_465->unk630, u32 *, 0x20))) {
            var_r30_466 = 1;
        }
    }
    if (var_r30_466 != 0) {
        temp_r3_483 = this->unkC;
        temp_r4_486 = temp_r3_483->unkA50;
        ((Enemy *) temp_r3_483)->SetAnim(temp_r4_486, (AnimTransition *) &temp_r4_486->unk20, 0.15f, 0U);
    }
    temp_r5_490 = this->unkC;
    if (((u32) temp_r5_490->unkA54 == &temp_r5_490->unkA50->unk20) && ((temp_r3_496 = temp_r5_490->unkA4C, ((temp_r3_496 == NULL) != 0)) || (temp_r3_496->GetNumberActive(), (((s32) M2C_ERROR(/* Read from unset register $r3 */) > 0) == 0)) || (M2C_FIELD(&gb, f32 *, 0x30C) >= M2C_FIELD(this->unkC, f32 *, 0xB18)))) {
        temp_r3_511 = this->unkC;
        temp_r4_514 = temp_r3_511->unkA50;
        ((Enemy *) temp_r3_511)->SetAnim(temp_r4_514, (AnimTransition *) &temp_r4_514->unk40, 0.15f, 0U);
    }
    temp_r29_518 = this->unkC;
    var_r30_519 = 0;
    if (temp_r29_518->HasAnimFinished() != 0) {
        temp_r4_524 = temp_r29_518->unkA50;
        if ((temp_r4_524 != NULL) && ((u32) temp_r4_524->unk40 == (u32) M2C_FIELD(temp_r29_518->unk630, u32 *, 0x20))) {
            var_r30_519 = 1;
        }
    }
    if (var_r30_519 != 0) {
        this->unk8 = 2;
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: expression syntax error
void SwampTier3Goal_Cower::Activate() {
    Character *temp_r3_568;
    Character *temp_r5_586;
    u8 var_r31_569;

    this->unk8 = 0;
    ((Enemy *) this->unkC)->SetAnim((AnimSequenceType) 1, 0xD, 0, 0.15f, 0U, 0U);
    this->unkC->StopMovement(1U);
    temp_r3_568 = this->unkC;
    var_r31_569 = 0;
    if (((u8) M2C_FIELD(temp_r3_568, u8 *, 0x8B8) == 2) || (temp_r3_568->unk8B0.Get() != NULL)) {
        var_r31_569 = 1;
    }
    if (var_r31_569 != 0) {
        temp_r5_586 = this->unkC;
        if (M2C_FIELD(this->unkC->unk8B0.Get()->__vptr, u8 (**)(MKVector3 *, M2C_UNK *), 0x28)(&temp_r5_586->unk588, &temp_r5_586->unk700) != 0) {
            this->unkC->unk6F8 = 1;
        }
    }
}
#endif

#if 0 // DRAFT: ';' expected
void SwampTier3Goal_Summon::PositionSpawnPoints() {
    s8 sp408;
    s32 sp404;
    s32 sp400;
    s32 sp3FC;
    f32 sp3F8;
    s32 sp3F4;
    s8 sp3F3;
    s8 sp3F2;
    s16 sp3F0;
    f32 sp3EC;
    f32 sp3E8;
    f32 sp3E4;
    f32 sp3E0;
    f32 sp3DC;
    f32 sp3D8;
    f32 sp3D0;
    f32 sp3CC;
    f32 sp3C8;
    f32 sp3C0;
    f32 sp3BC;
    f32 sp3B8;
    s8 sp3B0;
    s32 sp3AC;
    s32 sp3A8;
    s32 sp3A4;
    f32 sp3A0;
    s32 sp39C;
    s8 sp39B;
    s8 sp39A;
    s16 sp398;
    f32 sp394;
    f32 sp390;
    f32 sp38C;
    f32 sp388;
    f32 sp384;
    f32 sp380;
    f32 sp378;
    f32 sp374;
    f32 sp370;
    f32 sp368;
    f32 sp364;
    f32 sp360;
    f64 sp358;
    f64 sp350;
    f64 sp348;
    f64 sp340;
    f64 sp338;                                      /* compiler-managed */
    f64 sp330;
    f64 sp328;
    f64 sp320;
    f64 sp318;
    f64 sp310;
    f64 sp308;                                      /* compiler-managed */
    f64 sp300;                                      /* compiler-managed */
    f64 sp2F8;
    f64 sp2F0;
    AITargetData sp2A0;
    f64 sp298;
    f64 sp290;
    f64 sp280;
    MKVector3 sp270;
    f64 sp268;
    f64 sp260;
    f64 sp258;
    f64 sp250;
    f64 sp248;
    f64 sp240;
    f64 sp230;
    MKVector3 sp220;
    f64 sp218;
    f64 sp210;
    f64 sp208;
    f64 sp200;
    f64 sp1F0;
    f64 sp1E8;
    f64 sp1E0;
    f64 sp1D8;
    f64 sp1D0;
    f64 sp1C0;
    MKVector3 sp1B0;
    f64 sp1A8;
    f64 sp1A0;
    f64 sp198;
    f64 sp190;
    f64 sp188;
    f64 sp180;
    f64 sp178;
    f64 sp170;
    f64 sp168;
    f64 sp160;
    f32 sp158;
    f32 sp154;
    f32 sp150;
    f32 sp148;
    f64 sp140;
    M2C_UNK sp130;
    f32 sp128;
    f64 sp120;
    f32 sp118;
    f64 sp110;
    f32 sp108;
    f32 sp104;
    f32 sp100;
    f32 spF8;
    f64 spF0;
    f32 spE8;
    f64 spE0;
    f32 spD8;
    f64 spD0;
    f32 spC8;
    f32 spC4;
    f32 spC0;
    f32 spB8;
    f64 spB0;
    f32 spA8;
    f64 spA0;
    f32 sp98;
    f64 sp90;
    f32 sp88;
    f64 sp80;
    f32 sp78;
    f64 sp70;
    f32 sp68;
    f64 sp60;
    f32 sp58;
    f64 sp50;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 sp8;
    SpawnPointObject *temp_r3_1100;
    SpawnPointObject *temp_r3_1267;
    SpawnerObject *temp_r3_648;
    f32 temp_f0_707;
    f32 temp_f0_888;
    f32 temp_f18_771;
    f32 temp_f1_781;
    f32 temp_f1_916;
    f32 temp_f22_720;
    f32 temp_f22_907;
    f32 temp_f23_700;
    f32 temp_f23_906;
    f32 temp_f24_905;
    f32 temp_f25_904;
    f32 temp_f26_892;
    f32 temp_f27_1162;
    f32 temp_f28_1172;
    f32 temp_f29_1173;
    f32 temp_f2_1276;
    f32 temp_f30_1175;
    f32 temp_f31_1174;
    f32 temp_f4_1274;
    f32 temp_f6_1272;
    f32 var_f16_1153;
    f32 var_f24_715;
    f32 var_f2_1026;
    f32 var_f2_706;
    f32 var_f4_960;
    f64 temp_f0_1049;
    f64 temp_f0_1187;
    f64 temp_f0_1216;
    f64 temp_f0_794;
    f64 temp_f0_929;
    f64 temp_f0_944;
    f64 temp_f1_965;
    f64 temp_f1_971;
    f64 temp_f1_975;
    s32 temp_r29_664;
    s32 temp_r3_994;
    s32 var_r0_1004;
    s32 var_r20_1154;
    s32 var_r20_769;
    s32 var_r21_767;
    s32 var_r22_725;
    s32 var_r27_885;
    u32 *temp_r4_651;
    u32 *var_r3_652;
    u8 var_r24_722;
    u8 var_r25_798;

    temp_r3_648 = this->unkC->unkA4C;
    if (temp_r3_648 != NULL) {
        temp_r4_651 = temp_r3_648->unk44;
        var_r3_652 = temp_r4_651;
loop_3:
        if ((u32) *var_r3_652 != 0) {
            var_r3_652 += 4;
            goto loop_3;
        }
        temp_r29_664 = (s32) (var_r3_652 - temp_r4_651) / 4;
        sp2A0.GetDir();
        sp350 = M2C_BITWISE(f64, sp2A0);
        sp358 = (f64) sp2A0.unk8;
        sp158 = (MKVector3::up.unk0 * (*(f32 *) ((u8 *) &sp350 + 0x4))) - (MKVector3::up.unk4 * (f32) sp350);
        sp150 = (MKVector3::up.unk4 * (f32) sp358) - (MKVector3::up.unk8 * (*(f32 *) ((u8 *) &sp350 + 0x4)));
        sp154 = (MKVector3::up.unk8 * (f32) sp350) - (MKVector3::up.unk0 * (f32) sp358);
        temp_f23_700 = 0.5f * (175.0f * (f32) temp_r29_664);
        sp348 = (f64) sp158;
        sp340 = (f64) sp150;
        var_f2_706 = 300.0f;
        temp_f0_707 = this->unkC->unk870.GetDist() - 350.0f;
        if (temp_f0_707 < 300.0f) {

        } else {
            var_f2_706 = temp_f0_707;
        }
        var_f24_715 = var_f2_706;
        temp_f22_720 = (f32) sp348 * temp_f23_700;
        var_r24_722 = 0;
        var_r22_725 = 0;
loop_19:
        if (var_r22_725 < (s32) ((s32) ((var_f2_706 - 300.0f) / 100.0f) + 1)) {
            sp270.operator*(var_f24_715);
            ((MKProp *) &sp280)->GetPos();
            spA0 = sp280 + M2C_BITWISE(f64, sp270);
            sp290 = spA0;
            spA8 = sp288 + sp270.unk8;
            sp330 = spA0;
            sp298 = (f64) spA8;
            sp338 = (f64) spA8;
            sp90 = sp340 * (f64) temp_f23_700;
            sp98 = temp_f22_720;
            sp260 = sp90;
            sp268 = (f64) sp98;
            sp330 = spA0 - sp260;
            var_r21_767 = 0;
            var_r20_769 = 0;
            temp_f18_771 = (f32) sp338 - (f32) sp268;
            sp338 = temp_f18_771;
loop_15:
            if (var_r20_769 < temp_r29_664) {
                temp_f1_781 = 2.0f * ((f32) var_r20_769 * 175.0f);
                sp80 = sp340 * (f64) temp_f1_781;
                sp88 = (f32) sp348 * temp_f1_781;
                sp250 = sp80;
                sp258 = (f64) sp88;
                temp_f0_794 = sp330 + sp250;
                sp140 = temp_f0_794;
                var_r25_798 = 0;
                sp320 = temp_f0_794;
                sp148 = temp_f18_771 + (f32) sp258;
                sp328 = (f64) sp148;
                if (this->unkC->unk800.IsPointWithin(*((MKVector3 *) &sp320)) != 0) {
                    ((EnemyRegion *) &sp130)->GetRegionPos();
                    if ((f32) fabs(sp134 - (*(f32 *) ((u8 *) &sp320 + 0x4))) <= 500.0f) {
                        var_r25_798 = 1;
                    }
                }
                if ((var_r25_798 != 0) && (this->unkC->unk838.IsPointWithin(*((MKVector3 *) &sp320)) == 0)) {
                    var_r21_767 += 1;
                    var_r20_769 += 1;
                    goto loop_15;
                }
            }
            if (var_r21_767 == temp_r29_664) {
                var_r24_722 = 1;
            } else {
                var_f24_715 -= 100.0f;
                var_r22_725 += 1;
                goto loop_19;
            }
        }
        if (var_r24_722 != 0) {
            sp220.operator*(var_f24_715);
            ((MKProp *) &sp230)->GetPos();
            sp70 = sp230 + M2C_BITWISE(f64, sp220);
            sp240 = sp70;
            sp78 = sp238 + sp220.unk8;
            sp330 = sp70;
            sp248 = (f64) sp78;
            sp338 = (f64) sp78;
            sp60 = sp340 * (f64) temp_f23_700;
            sp68 = temp_f22_720;
            sp210 = sp60;
            sp218 = (f64) sp68;
            sp330 = sp70 - sp210;
            var_r27_885 = 0;
            temp_f0_888 = (f32) sp338 - (f32) sp218;
            sp338 = temp_f0_888;
            temp_f26_892 = MKVector3::up.unk0;
            temp_f25_904 = MKVector3::up.unk4;
            temp_f24_905 = MKVector3::up.unk8;
            temp_f23_906 = MKVector3::up.unk4;
            temp_f22_907 = MKVector3::up.unk8;
loop_45:
            if (var_r27_885 < temp_r29_664) {
                temp_f1_916 = 2.0f * ((f32) var_r27_885 * 175.0f);
                sp50 = sp340 * (f64) temp_f1_916;
                sp58 = (f32) sp348 * temp_f1_916;
                sp200 = sp50;
                sp208 = (f64) sp58;
                temp_f0_929 = sp330 + sp200;
                sp120 = temp_f0_929;
                sp310 = temp_f0_929;
                sp128 = (f32) temp_f0_888 + (f32) sp208;
                sp318 = (f64) sp128;
                ((AITargetData *) &sp1F0)->GetPos();
                temp_f0_944 = sp1F0 - sp310;
                sp110 = temp_f0_944;
                sp300 = temp_f0_944;
                sp118 = sp1F8 - (f32) sp318;
                (*(f32 *) ((u8 *) &sp2F8 + 0xc)) = 0.0f;
                sp308 = (f64) sp118;
                var_f4_960 = ((f32) sp308 * (f32) sp308) + (((f32) sp300 * (f32) sp300) + (0.0f * 0.0f));
                if (var_f4_960 > 0.000001f) {
                    if (var_f4_960 > 0.0f) {
                        temp_f1_965 = __frsqrte(var_f4_960);
                        temp_f1_971 = 0.5 * temp_f1_965 * -(((f64) var_f4_960 * (temp_f1_965 * temp_f1_965)) - 3.0);
                        temp_f1_975 = 0.5 * temp_f1_971 * -(((f64) var_f4_960 * (temp_f1_971 * temp_f1_971)) - 3.0);
                        var_f4_960 = (f32) ((f64) var_f4_960 * (0.5 * temp_f1_975 * -(((f64) var_f4_960 * (temp_f1_975 * temp_f1_975)) - 3.0)));
                    } else if (var_f4_960 < M2C_BITWISE(f32, 0.0)) {
                        var_f4_960 = __float_nan;
                    } else {
                        sp8 = var_f4_960;
                        temp_r3_994 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                        switch (temp_r3_994) {      /* irregular */
                        case 0x7F800000:
                            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                var_r0_1004 = 1;
                            } else {
                                var_r0_1004 = 2;
                            }
                            break;
                        case 0x0:
                            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                var_r0_1004 = 5;
                            } else {
                                var_r0_1004 = 3;
                            }
                            break;
                        default:
                            var_r0_1004 = 4;
                            break;
                        }
                        if (var_r0_1004 == 1) {
                            var_f4_960 = __float_nan;
                        }
                    }
                    var_f2_1026 = 1.0f / var_f4_960;
                } else {
                    var_f2_1026 = 0.0f;
                }
                sp100 = 0.0f;
                sp104 = 100.0f;
                sp108 = 0.0f;
                sp1E0 = (f64) sp100;
                sp300 = (f32) sp300 * var_f2_1026;
                (*(f32 *) ((u8 *) &sp2F8 + 0xc)) *= var_f2_1026;
                sp308 = (f32) sp308 * var_f2_1026;
                sp1E8 = (f64) sp108;
                temp_f0_1049 = sp310 + sp1E0;
                spF0 = temp_f0_1049;
                sp3B8 = 0.0f;
                sp2F0 = temp_f0_1049;
                spF8 = (f32) sp318 + (f32) sp1E8;
                sp3BC = 0.0f;
                sp2F8 = (f64) spF8;
                sp3C0 = 0.0f;
                sp3C8 = 0.0f;
                sp3CC = 0.0f;
                sp3D0 = 0.0f;
                sp3D8 = 0.0f;
                sp3DC = 0.0f;
                sp3E0 = 0.0f;
                sp3E4 = 1.0f;
                sp3E8 = 0.0f;
                sp3EC = 0.0f;
                sp3F0 = 0;
                sp3F2 = 0;
                sp3F3 = 0;
                sp3F4 = 0;
                sp3F8 = 3.4028235e38f;
                sp3FC = 0;
                sp400 = 0;
                sp404 = -1;
                sp408 = 0;
                if (MKCollision_GetGroundPoint(*((MKVector3 *) &sp2F0), 200.0f, (MKCollisionResult *) &sp3B8, M2C_FIELD(this->unkC->unk110.unk460, s32 *, 0x18), 2, NULL, (MKCollisionMode) 6) != 0) {
                    (*(f32 *) ((u8 *) &sp310 + 0x4)) = sp3BC;
                }
                temp_r3_1100 = this->unkC->unkA4C->GetSpawnPoint(var_r27_885);
                var_r27_885 += 1;
                temp_r3_1100->unk40 = (f32) sp310;
                temp_r3_1100->unk44 = (*(f32 *) ((u8 *) &sp310 + 0x4));
                temp_r3_1100->unk48 = (f32) sp318;
                temp_r3_1100->unk4C = 1.0f;
                temp_r3_1100->unk30 = sp300;
                temp_r3_1100->unk34 = (*(f32 *) ((u8 *) &sp2F8 + 0xc));
                temp_r3_1100->unk38 = sp308;
                temp_r3_1100->unk3C = 0.0f;
                temp_r3_1100->unk20 = temp_f26_892;
                temp_r3_1100->unk24 = temp_f25_904;
                temp_r3_1100->unk28 = temp_f24_905;
                sp48 = (temp_f26_892 * (*(f32 *) ((u8 *) &sp2F8 + 0xc))) - (temp_f23_906 * sp300);
                sp40 = (temp_f23_906 * sp308) - (temp_f22_907 * (*(f32 *) ((u8 *) &sp2F8 + 0xc)));
                sp44 = (temp_f22_907 * sp300) - (temp_f26_892 * sp308);
                sp1D8 = (f64) sp48;
                sp1D0 = (f64) sp40;
                temp_r3_1100->unk2C = 0.0f;
                temp_r3_1100->unk10 = (f32) sp1D0;
                temp_r3_1100->unk14 = (*(f32 *) ((u8 *) &sp1D0 + 0x4));
                temp_r3_1100->unk18 = (f32) sp1D8;
                temp_r3_1100->unk1C = 0.0f;
                goto loop_45;
            }
            return;
        }
        ((AITargetData *) &sp1C0)->GetPos();
        var_f16_1153 = 0.0f;
        var_r20_1154 = 0;
        temp_f27_1162 = MKVector3::up.unk0;
        sp2A0.unk40.unk8 = sp1C8;
        sp2A0.unk40 = sp1C0;
        temp_f28_1172 = MKVector3::up.unk4;
        temp_f29_1173 = MKVector3::up.unk8;
        temp_f31_1174 = MKVector3::up.unk4;
        temp_f30_1175 = MKVector3::up.unk8;
loop_51:
        if (var_r20_1154 < temp_r29_664) {
            sp1B0 = KDMath_GetDirection(var_f16_1153);
            *(MKVector3 *) &sp2A0.unk30 = sp1B0;
            temp_f0_1187 = (f64) sp2A0.unk30 * 5.61841903e-315;
            spE0 = temp_f0_1187;
            sp1A0 = temp_f0_1187;
            spE8 = sp2A0.unk38 * 400.0f;
            sp1A8 = (f64) spE8;
            spD0 = M2C_BITWISE(f64, sp2A0.unk40) + temp_f0_1187;
            spC8 = 0.0f;
            spC0 = 0.0f;
            spC4 = 100.0f;
            spD8 = M2C_BITWISE(f32, sp2A0.unk40.unk8) + (f32) sp1A8;
            sp2A0.unk20 = spD0;
            sp190 = (f64) spC0;
            sp2A0.unk28 = (f64) spD8;
            sp198 = (f64) spC8;
            temp_f0_1216 = sp2A0.unk20 + sp190;
            spB0 = temp_f0_1216;
            sp360 = 0.0f;
            sp2A0.unk10 = temp_f0_1216;
            spB8 = (f32) sp2A0.unk28 + (f32) sp198;
            sp364 = 0.0f;
            sp2A0.unk18 = (f64) spB8;
            sp368 = 0.0f;
            sp370 = 0.0f;
            sp374 = 0.0f;
            sp378 = 0.0f;
            sp380 = 0.0f;
            sp384 = 0.0f;
            sp388 = 0.0f;
            sp38C = 1.0f;
            sp390 = 0.0f;
            sp394 = 0.0f;
            sp398 = 0;
            sp39A = 0;
            sp39B = 0;
            sp39C = 0;
            sp3A0 = 3.4028235e38f;
            sp3A4 = 0;
            sp3A8 = 0;
            sp3AC = -1;
            sp3B0 = 0;
            if (MKCollision_GetGroundPoint(*((MKVector3 *) &sp2A0.unk10), 200.0f, (MKCollisionResult *) &sp360, M2C_FIELD(this->unkC->unk110.unk460, s32 *, 0x18), 2, NULL, (MKCollisionMode) 6) != 0) {
                (*(f32 *) ((u8 *) &sp2A0 + 0x24)) = sp364;
            }
            temp_r3_1267 = this->unkC->unkA4C->GetSpawnPoint(var_r20_1154);
            var_f16_1153 += 6.2831855f / (f32) temp_r29_664;
            var_r20_1154 += 1;
            temp_f6_1272 = -sp2A0.unk30;
            temp_f4_1274 = -sp2A0.unk34;
            temp_f2_1276 = -sp2A0.unk38;
            sp30 = temp_f6_1272;
            temp_r3_1267->unk40 = (f32) sp2A0.unk20;
            temp_r3_1267->unk44 = (*(f32 *) ((u8 *) &sp2A0 + 0x24));
            sp34 = temp_f4_1274;
            temp_r3_1267->unk48 = (f32) sp2A0.unk28;
            sp180 = (f64) sp30;
            sp38 = temp_f2_1276;
            sp18 = temp_f2_1276;
            temp_r3_1267->unk4C = 1.0f;
            temp_r3_1267->unk30 = (f32) sp180;
            sp188 = (f64) sp38;
            sp168 = (f64) sp18;
            temp_r3_1267->unk34 = (*(f32 *) ((u8 *) &sp180 + 0x4));
            temp_r3_1267->unk38 = (f32) sp188;
            temp_r3_1267->unk3C = 0.0f;
            temp_r3_1267->unk20 = temp_f27_1162;
            temp_r3_1267->unk24 = temp_f28_1172;
            temp_r3_1267->unk28 = temp_f29_1173;
            sp10 = temp_f6_1272;
            sp14 = temp_f4_1274;
            temp_r3_1267->unk2C = 0.0f;
            sp160 = (f64) sp10;
            sp24 = (temp_f30_1175 * (f32) sp160) - (temp_f27_1162 * (f32) sp168);
            sp20 = (temp_f31_1174 * (f32) sp168) - (temp_f30_1175 * (*(f32 *) ((u8 *) &sp160 + 0x4)));
            sp28 = (temp_f27_1162 * (*(f32 *) ((u8 *) &sp160 + 0x4))) - (temp_f31_1174 * (f32) sp160);
            sp170 = (f64) sp20;
            sp178 = (f64) sp28;
            temp_r3_1267->unk10 = (f32) sp170;
            temp_r3_1267->unk14 = (*(f32 *) ((u8 *) &sp170 + 0x4));
            temp_r3_1267->unk18 = (f32) sp178;
            temp_r3_1267->unk1C = 0.0f;
            goto loop_51;
        }
    }
}
#endif

void SwampTier3Goal_Summon::Terminate() {
    this->unk8 = 1;
    RemoveAllSubgoals();
    this->unkC->SetInvulnerableToMeleeAttacks(0U, 1U);
    this->unkC->SetInvulnerableToBreathAttacks(0U, 1U);
}

u8 SwampTier3Goal_Summon::Update() {
    ActivateIfInactive();
    this->unk8 = UpdateSubgoals();
    this->unkC->unkA4C->TrySpawnItems(0x17, 0U);
    return this->unk8;
}

void SwampTier3Goal_Summon::Activate() {
    f64 sp10;
    f64 sp8;
    Enemy *temp_r3_1438;
    Enemy *temp_r3_1447;
    Goal<SwampTier3> *temp_r6_1483;
    u8 var_r30_1448;
    void *temp_r5_1440;

    this->unk8 = 0;
    RemoveAllSubgoals();
    temp_r3_1438 = this->unkC;
    temp_r5_1440 = temp_r3_1438->unk8;
    sp8 = M2C_FIELD(temp_r5_1440, f64 *, 0x30);
    sp10 = M2C_FIELD(temp_r5_1440, f64 *, 0x38);
    temp_r3_1438->unk870.Update(*((MKVector3 *) &sp8));
    temp_r3_1447 = this->unkC;
    var_r30_1448 = 0;
    if (((u8) M2C_FIELD(temp_r3_1447, u8 *, 0x8B8) == 2) || (temp_r3_1447->unk870.unk40.Get() != NULL)) {
        var_r30_1448 = 1;
    }
    if (var_r30_1448 == 0) {
        this->unk8 = 3;
        this->unkC->unkA4C->FunctionOff();
    } else {
        this->unkC->unkA4C->GetNumberActive();
        if ((s32) M2C_ERROR(/* Read from unset register $r3 */) <= 0) {
            this->unkC->unkA4C->FunctionOn();
            PositionSpawnPoints();
            AddSubgoal((Goal<SwampTier3> *) this->unk20);
            temp_r6_1483 = this->unk20;
            M2C_FIELD(temp_r6_1483, AITargetData **, 0x10) = &this->unkC->unk870;
            M2C_FIELD(temp_r6_1483, s32 *, 0x14) = 1;
            M2C_FIELD(temp_r6_1483, s32 *, 0x18) = 0xB;
            M2C_FIELD(temp_r6_1483, s32 *, 0x1C) = 0;
            M2C_FIELD(temp_r6_1483, u8 *, 0x20) = (u8) (M2C_FIELD(temp_r6_1483, u8 *, 0x20) & ~0x40);
            M2C_FIELD(this->unkC, f32 *, 0xB18) = (f32) (M2C_FIELD(&gb, f32 *, 0x30C) + 20.0f);
        }
        AddSubgoal((Goal<SwampTier3> *) this->unk24);
    }
    this->unkC->SetInvulnerableToMeleeAttacks(1U, 1U);
    this->unkC->SetInvulnerableToBreathAttacks(1U, 1U);
}

void SwampTier3Goal_Summon::Deinit() {
    Goal<SwampTier3> *temp_r3_1529;
    Goal<SwampTier3> *temp_r3_1534;
    void *temp_r31_1543;

    temp_r3_1529 = this->unk20;
    temp_r3_1529->Deinit();
    temp_r3_1534 = this->unk24;
    temp_r3_1534->Deinit();
    operator delete(this->unk20);
    operator delete(this->unk24);
    temp_r31_1543 = this->unk1C;
    if (temp_r31_1543 != NULL) {
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_1543, NULL, 0);
        } else {
            free(temp_r31_1543);
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
void SwampTier3Goal_Summon::Init(SwampTier3 *arg0) {
    Goal<SwampTier3> *temp_r4_1660;
    Goal<SwampTier3> *temp_r4_1671;
    void *var_r3_1640;

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
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__18Goal<10SwampTier3>;
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
            var_r3_1640 = ((MKHeap *) (MKHeap::Current()))->Alloc(8, NULL, 0);
        } else {
            var_r3_1640 = malloc(8);
        }
        this->unk1C = var_r3_1640;
        this->unk10 = 2;
    }
    this->unk8 = 1;
    this->unkC = (Enemy *) arg0;
    this->unk4 = 0x7B;
    if ((Enemy *) this->unkC != NULL) {
        this->unk9 = 1;
    }
    temp_r4_1660 = this->unk20;
    M2C_FIELD(temp_r4_1660, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_1660, SwampTier3 **, 0xC) = arg0;
    M2C_FIELD(temp_r4_1660, s32 *, 4) = 0;
    if ((SwampTier3 *) M2C_FIELD(temp_r4_1660, SwampTier3 **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_1660, s8 *, 9) = 1;
    }
    temp_r4_1671 = this->unk24;
    M2C_FIELD(temp_r4_1671, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_1671, SwampTier3 **, 0xC) = arg0;
    M2C_FIELD(temp_r4_1671, s32 *, 4) = 0x7C;
    if ((SwampTier3 *) M2C_FIELD(temp_r4_1671, SwampTier3 **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_1671, s8 *, 9) = 1;
    }
    this->unk28 = 3;
}
#endif

void SwampTier3Goal_Hit::Terminate() {
    this->unk8 = 1;
    RemoveAllSubgoals();
}

u8 SwampTier3Goal_Hit::Update() {
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    s32 sp8;
    Enemy *temp_r3_1722;
    Enemy *temp_r3_1732;
    f64 temp_f0_1752;
    f64 temp_f1_1742;
    s32 var_r6_1758;
    void *temp_r4_1739;

    ActivateIfInactive();
    this->unk8 = UpdateSubgoals();
    sp8 = 0;
    temp_r3_1722 = this->unkC;
    if (((u8) temp_r3_1722->unkA38->unk121 != 0) && (temp_r3_1722->InWaterVolume(temp_r3_1722->unk588, (int *) &sp8) != 0)) {
        temp_r3_1732 = this->unkC;
        sp20 = M2C_FIELD(temp_r3_1732, f64 *, 0xC0) * 5.398241246e-315;
        temp_r4_1739 = temp_r3_1732->unk8;
        temp_f1_1742 = M2C_FIELD(temp_r4_1739, f64 *, 0x30);
        sp28 = temp_r3_1732->unkC8 * 10.0f;
        sp30 = sp20;
        sp40 = temp_f1_1742;
        sp38 = (f64) sp28;
        sp48 = M2C_FIELD(temp_r4_1739, f64 *, 0x38);
        temp_f0_1752 = temp_f1_1742 + sp30;
        sp10 = temp_f0_1752;
        var_r6_1758 = 0x4000;
        sp50 = temp_f0_1752;
        sp18 = (f32) sp48 + (f32) sp38;
        sp58 = (f64) sp18;
        if (sp8 & 1) {
            var_r6_1758 = 0x800;
        }
        temp_r3_1732->AddDamage(0.0f, 1U, *((MKVector3 *) &sp50), var_r6_1758, 0, 0U, 0U, NULL, 0.0f, 1.0f);
        this->unk8 = 2;
    }
    return this->unk8;
}

void SwampTier3Goal_Hit::Activate() {
    Enemy *temp_r3_1859;
    Enemy *temp_r4_1802;
    Enemy *temp_r5_1807;
    s32 temp_r0_1808;

    this->unk8 = 0;
    temp_r4_1802 = this->unkC;
    temp_r4_1802->unkB08 |= 0x40;
    RemoveAllSubgoals();
    temp_r5_1807 = this->unkC;
    temp_r0_1808 = temp_r5_1807->unk938;
    switch (temp_r0_1808) {                         /* irregular */
    case 4:
        AddSubgoal((Goal<SwampTier3> *) this->unk28);
        return;
    case 5:
        if (temp_r5_1807->unkA38->GetAnimSequence(2, 0x31, temp_r5_1807->unkAE4, NULL) != NULL) {
            AddSubgoal((Goal<SwampTier3> *) this->unk2C);
            return;
        }
        AddSubgoal((Goal<SwampTier3> *) this->unk28);
        return;
    case 11:
        AddSubgoal((Goal<SwampTier3> *) this->unk30);
        return;
    case 1:
        AddSubgoal((Goal<SwampTier3> *) this->unk24);
        return;
    default:
        AddSubgoal((Goal<SwampTier3> *) this->unk20);
        temp_r3_1859 = this->unkC;
        temp_r3_1859->unk6B4 |= 1;
        return;
    }
}

void SwampTier3Goal_Hit::Deinit() {
    Goal<SwampTier3> *temp_r3_1879;
    Goal<SwampTier3> *temp_r3_1884;
    Goal<SwampTier3> *temp_r3_1889;
    Goal<SwampTier3> *temp_r3_1894;
    Goal<SwampTier3> *temp_r3_1899;
    void *temp_r31_1914;

    temp_r3_1879 = this->unk20;
    temp_r3_1879->Deinit();
    temp_r3_1884 = this->unk28;
    temp_r3_1884->Deinit();
    temp_r3_1889 = this->unk2C;
    temp_r3_1889->Deinit();
    temp_r3_1894 = this->unk30;
    temp_r3_1894->Deinit();
    temp_r3_1899 = this->unk24;
    temp_r3_1899->Deinit();
    operator delete(this->unk20);
    operator delete(this->unk28);
    operator delete(this->unk2C);
    operator delete(this->unk30);
    operator delete(this->unk24);
    temp_r31_1914 = this->unk1C;
    if (temp_r31_1914 != NULL) {
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_1914, NULL, 0);
        } else {
            free(temp_r31_1914);
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
void SwampTier3Goal_Hit::Init(SwampTier3 *arg0) {
    Goal<SwampTier3> *temp_r4_2091;
    Goal<SwampTier3> *temp_r4_2102;
    Goal<SwampTier3> *temp_r4_2113;
    Goal<SwampTier3> *temp_r4_2124;
    Goal<SwampTier3> *temp_r4_2135;
    void *var_r3_2071;

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
        this->unk20 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x10U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk28 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x10U, NULL, 0);
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
        this->unk30 = M2C_ERROR(/* Read from unset register $r3 */);
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
            var_r3_2071 = ((MKHeap *) (MKHeap::Current()))->Alloc(4, NULL, 0);
        } else {
            var_r3_2071 = malloc(4);
        }
        this->unk1C = var_r3_2071;
        this->unk10 = 1;
    }
    this->unk8 = 1;
    this->unkC = (Enemy *) arg0;
    this->unk4 = 0x59;
    if ((Enemy *) this->unkC != NULL) {
        this->unk9 = 1;
    }
    temp_r4_2091 = this->unk20;
    M2C_FIELD(temp_r4_2091, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_2091, SwampTier3 **, 0xC) = arg0;
    M2C_FIELD(temp_r4_2091, s32 *, 4) = 8;
    if ((SwampTier3 *) M2C_FIELD(temp_r4_2091, SwampTier3 **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_2091, s8 *, 9) = 1;
    }
    temp_r4_2102 = this->unk28;
    M2C_FIELD(temp_r4_2102, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_2102, SwampTier3 **, 0xC) = arg0;
    M2C_FIELD(temp_r4_2102, s32 *, 4) = 0xF;
    if ((SwampTier3 *) M2C_FIELD(temp_r4_2102, SwampTier3 **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_2102, s8 *, 9) = 1;
    }
    temp_r4_2113 = this->unk2C;
    M2C_FIELD(temp_r4_2113, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_2113, SwampTier3 **, 0xC) = arg0;
    M2C_FIELD(temp_r4_2113, s32 *, 4) = 0x10;
    if ((SwampTier3 *) M2C_FIELD(temp_r4_2113, SwampTier3 **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_2113, s8 *, 9) = 1;
    }
    temp_r4_2124 = this->unk30;
    M2C_FIELD(temp_r4_2124, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_2124, SwampTier3 **, 0xC) = arg0;
    M2C_FIELD(temp_r4_2124, s32 *, 4) = 0x14;
    if ((SwampTier3 *) M2C_FIELD(temp_r4_2124, SwampTier3 **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_2124, s8 *, 9) = 1;
    }
    temp_r4_2135 = this->unk24;
    M2C_FIELD(temp_r4_2135, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_2135, SwampTier3 **, 0xC) = arg0;
    M2C_FIELD(temp_r4_2135, s32 *, 4) = 0xA;
    if ((SwampTier3 *) M2C_FIELD(temp_r4_2135, SwampTier3 **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_2135, s8 *, 9) = 1;
    }
}
#endif

void SwampTier3Goal_Think::StartFollowingSpawnGraph() {
    s32 temp_r4_2159;

    if (!(((u8) this->unk44 >> 6U) & 1)) {
        temp_r4_2159 = this->unkC;
        M2C_FIELD(temp_r4_2159, u8 *, 0xB09) = (u8) (M2C_FIELD(temp_r4_2159, u8 *, 0xB09) | 8);
        this->unk44 |= 0x40;
    }
}

#if 0 // DRAFT: undefined identifier '__vptr'
void SwampTier3Goal_Think::StopFollowingSpawnGraph() {
    s32 temp_r3_2193;
    s32 temp_r5_2180;

    temp_r5_2180 = this->unkC;
    M2C_FIELD(temp_r5_2180, u8 *, 0xB09) = (u8) (M2C_FIELD(temp_r5_2180, u8 *, 0xB09) & ~8);
    if (M2C_FIELD(this->__vptr, u8 (**)(M2C_UNK, s32, M2C_UNK), 0x38)(0x2A, temp_r5_2180, 0) != 0) {
        RemoveAllSubgoals();
    }
    temp_r3_2193 = this->unkC;
    ((Enemy *) temp_r3_2193)->SetupEnemyRegion(*(temp_r3_2193 + 0x588), 1000.0f);
}
#endif

u8 SwampTier3Goal_Think::IsFollowingSpawnGraph() {
    return ((u8) M2C_FIELD(this->unkC, u8 *, 0xB09) >> 3U) & 1;
}

void SwampTier3Goal_Think::StartFollowingSpawnPath() {
    s32 temp_r4_2219;

    if (!(((u8) this->unk44 >> 7U) & 1)) {
        temp_r4_2219 = this->unkC;
        M2C_FIELD(temp_r4_2219, u8 *, 0xB09) = (u8) (M2C_FIELD(temp_r4_2219, u8 *, 0xB09) | 0x10);
        this->unk44 |= 0x80;
    }
}

#if 0 // DRAFT: undefined identifier '__vptr'
void SwampTier3Goal_Think::StopFollowingSpawnPath() {
    s32 temp_r3_2253;
    s32 temp_r5_2240;

    temp_r5_2240 = this->unkC;
    M2C_FIELD(temp_r5_2240, u8 *, 0xB09) = (u8) (M2C_FIELD(temp_r5_2240, u8 *, 0xB09) & ~0x10);
    if (M2C_FIELD(this->__vptr, u8 (**)(M2C_UNK, s32, M2C_UNK), 0x38)(0x22, temp_r5_2240, 0) != 0) {
        RemoveAllSubgoals();
    }
    temp_r3_2253 = this->unkC;
    ((Enemy *) temp_r3_2253)->SetupEnemyRegion(*(temp_r3_2253 + 0x588), 1000.0f);
}
#endif

u8 SwampTier3Goal_Think::IsFollowingSpawnPath() {
    return ((u8) M2C_FIELD(this->unkC, u8 *, 0xB09) >> 4U) & 1;
}

void SwampTier3Goal_Think::AddGoal_FollowSpawnGraph() {
    s32 temp_r3_2293;
    s32 temp_r3_2298;

    if (IsPresent(0x2A) == 0) {
        RemoveAllSubgoals();
        AddSubgoal((Goal<SwampTier3> *) this->unk40);
        temp_r3_2293 = this->unkC;
        M2C_FIELD(temp_r3_2293, u8 *, 0xB09) = (u8) (M2C_FIELD(temp_r3_2293, u8 *, 0xB09) | 8);
        temp_r3_2298 = this->unkC;
        M2C_FIELD(temp_r3_2298, u8 *, 0xB08) = (u8) (M2C_FIELD(temp_r3_2298, u8 *, 0xB08) | 0x40);
    }
}

void SwampTier3Goal_Think::AddGoal_FollowSpawnPath() {
    Goal<SwampTier3> *temp_r6_2332;
    s32 temp_r3_2354;
    s32 temp_r3_2358;

    if (IsPresent(0x22) == 0) {
        RemoveAllSubgoals();
        AddSubgoal((Goal<SwampTier3> *) this->unk3C);
        temp_r6_2332 = this->unk3C;
        M2C_FIELD(temp_r6_2332, s32 *, 0x10) = (s32) M2C_FIELD(this->unkC, s32 *, 0xA94);
        M2C_FIELD(temp_r6_2332, f32 *, 0x14) = 0.0f;
        M2C_FIELD(temp_r6_2332, s32 *, 0x18) = 1;
        M2C_FIELD(temp_r6_2332, s32 *, 0x20) = 6;
        M2C_FIELD(temp_r6_2332, s32 *, 0x1C) = 0;
        M2C_FIELD(temp_r6_2332, u8 *, 0x24) = (u8) (M2C_FIELD(temp_r6_2332, u8 *, 0x24) & ~0x20);
        M2C_FIELD(temp_r6_2332, u8 *, 0x24) = (u8) (M2C_FIELD(temp_r6_2332, u8 *, 0x24) & ~0x10);
        M2C_FIELD(temp_r6_2332, u8 *, 0x24) = (u8) (M2C_FIELD(temp_r6_2332, u8 *, 0x24) & ~8);
        M2C_FIELD(temp_r6_2332, u8 *, 0x24) = (u8) (M2C_FIELD(temp_r6_2332, u8 *, 0x24) & ~4);
        temp_r3_2354 = this->unkC;
        M2C_FIELD(temp_r3_2354, u8 *, 0xB09) = (u8) (M2C_FIELD(temp_r3_2354, u8 *, 0xB09) | 0x10);
        temp_r3_2358 = this->unkC;
        M2C_FIELD(temp_r3_2358, u8 *, 0xB08) = (u8) (M2C_FIELD(temp_r3_2358, u8 *, 0xB08) | 0x40);
    }
}

void SwampTier3Goal_Think::AddGoal_Patrol() {
    if (IsPresent(0x53) == 0) {
        RemoveAllSubgoals();
        AddSubgoal((Goal<SwampTier3> *) this->unk38);
    }
}

#if 0 // DRAFT: declaration syntax error
void SwampTier3Goal_Think::AddGoal_AlertMode(AITargetData *arg0) {
    Goal<SwampTier3> *temp_r4_2419;
    s32 temp_r3_2433;

    if (IsPresent(0x54) == 0) {
        RemoveAllSubgoals();
        AddSubgoal((Goal<SwampTier3> *) this->unk30);
        temp_r4_2419 = this->unk30;
        M2C_FIELD(temp_r4_2419, AITargetData **, 0x20) = arg0;
        M2C_FIELD(temp_r4_2419, s32 *, 0x4C) = 3;
        M2C_FIELD(temp_r4_2419, u8 *, 0x50) = (u8) (M2C_FIELD(temp_r4_2419, u8 *, 0x50) | 0x80);
        ((EnemyGoal_AlertMode *) this->unk30)->SetSummonGoal((Goal<Enemy> *) this->unk34);
        M2C_FIELD(this->unkC, s8 *, 0xB10) = 0;
        temp_r3_2433 = this->unkC;
        M2C_FIELD(temp_r3_2433, u8 *, 0xB01) = (u8) (M2C_FIELD(temp_r3_2433, u8 *, 0xB01) & ~0x20);
    }
}
#endif

void SwampTier3Goal_Think::AddGoal_Respawn() {
    if (IsPresent(0x1E) == 0) {
        RemoveAllSubgoals();
        AddSubgoal((Goal<SwampTier3> *) this->unk2C);
    }
}

void SwampTier3Goal_Think::AddGoal_Death(EnemyDamageFeedback *arg0) {
    s32 temp_r4_2489;

    if (IsPresent(0x5B) == 0) {
        temp_r4_2489 = this->unkC;
        M2C_FIELD(temp_r4_2489, f64 *, 0x910) = (f64) arg0->unk0;
        M2C_FIELD(temp_r4_2489, f64 *, 0x918) = (f64) arg0->unk8;
        M2C_FIELD(temp_r4_2489, s32 *, 0x920) = (s32) arg0->unk10;
        M2C_FIELD(temp_r4_2489, s32 *, 0x924) = (s32) arg0->unk14;
        M2C_FIELD(temp_r4_2489, f32 *, 0x928) = (f32) arg0->unk18;
        M2C_FIELD(temp_r4_2489, f32 *, 0x92C) = (f32) arg0->unk1C;
        M2C_FIELD(temp_r4_2489, s32 *, 0x930) = (s32) arg0->unk20;
        M2C_FIELD(temp_r4_2489, f32 *, 0x934) = (f32) arg0->unk24;
        M2C_FIELD(temp_r4_2489, s32 *, 0x938) = (s32) arg0->unk28;
        M2C_FIELD(temp_r4_2489, s32 *, 0x93C) = (s32) arg0->unk2C;
        M2C_FIELD(temp_r4_2489, s32 *, 0x940) = (s32) arg0->unk30;
        M2C_FIELD(temp_r4_2489, u8 *, 0x944) = (u8) arg0->unk34;
        RemoveAllSubgoals();
        AddSubgoal((Goal<SwampTier3> *) this->unk28);
    }
}

void SwampTier3Goal_Think::AddGoal_Hit(EnemyDamageFeedback *arg0) {
    s32 temp_r0_2543;
    s32 temp_r0_2564;
    s32 temp_r3_2565;
    s32 temp_r4_2575;

    if (IsActive(0x59) != 0) {
        temp_r0_2543 = arg0->unk28;
        if (temp_r0_2543 != 0) {
            if ((temp_r0_2543 == 1) && (IsActive(0xA) != 0)) {
                return;
            }
            if ((s32) this->unk14 > 0) {
                this->unk18 += 1;
                temp_r0_2564 = this->unk18;
                temp_r3_2565 = this->unk10;
                if (temp_r0_2564 >= temp_r3_2565) {
                    this->unk18 = temp_r0_2564 - temp_r3_2565;
                }
                this->unk14 -= 1;
            }
            goto block_9;
        }
    } else {
block_9:
        temp_r4_2575 = this->unkC;
        M2C_FIELD(temp_r4_2575, f64 *, 0x910) = (f64) arg0->unk0;
        M2C_FIELD(temp_r4_2575, f64 *, 0x918) = (f64) arg0->unk8;
        M2C_FIELD(temp_r4_2575, s32 *, 0x920) = (s32) arg0->unk10;
        M2C_FIELD(temp_r4_2575, s32 *, 0x924) = (s32) arg0->unk14;
        M2C_FIELD(temp_r4_2575, f32 *, 0x928) = (f32) arg0->unk18;
        M2C_FIELD(temp_r4_2575, f32 *, 0x92C) = (f32) arg0->unk1C;
        M2C_FIELD(temp_r4_2575, s32 *, 0x930) = (s32) arg0->unk20;
        M2C_FIELD(temp_r4_2575, f32 *, 0x934) = (f32) arg0->unk24;
        M2C_FIELD(temp_r4_2575, s32 *, 0x938) = (s32) arg0->unk28;
        M2C_FIELD(temp_r4_2575, s32 *, 0x93C) = (s32) arg0->unk2C;
        M2C_FIELD(temp_r4_2575, s32 *, 0x940) = (s32) arg0->unk30;
        M2C_FIELD(temp_r4_2575, u8 *, 0x944) = (u8) arg0->unk34;
        AddSubgoalToFront((Goal<SwampTier3> *) this->unk24);
    }
}

#if 0 // DRAFT: expression syntax error
void SwampTier3Goal_Think::Arbitrate() {
    EnemyDamageFeedback sp8;
    s32 temp_r3_2735;
    s32 temp_r3_2750;
    s32 temp_r3_2777;
    s32 temp_r4_2619;
    s32 temp_r4_2643;
    s32 temp_r4_2654;
    s32 temp_r4_2797;
    u8 var_r30_2751;

    temp_r4_2619 = this->unkC;
    if (!(((u8) M2C_FIELD(temp_r4_2619, u8 *, 0xB09) >> 7U) & 1)) {
        AddGoal_Respawn();
        return;
    }
    if (((Enemy *) temp_r4_2619)->WasHit() != 0) {
        if (((u8) M2C_FIELD(this->unkC, u8 *, 0xB10) != 0) || (IsPresent(2) != 0)) {
            temp_r4_2643 = this->unkC;
            M2C_FIELD(temp_r4_2643, s32 *, 0x9D8) = 0;
            M2C_FIELD(temp_r4_2643, s32 *, 0x9D4) = 0;
            M2C_FIELD(this->unkC, f32 *, 0xB14) = (f32) (M2C_FIELD(&gb, f32 *, 0x30C) + 10.0f);
            temp_r4_2654 = this->unkC;
            if (!(((u8) M2C_FIELD(temp_r4_2654, u8 *, 0xB08) >> 6U) & 1)) {
                AddGoal_AlertMode(temp_r4_2654 + 0x870);
            }
            goto block_17;
        }
        sp8.Init();
        ((Enemy *) this->unkC)->TakeDamage(&sp8, 0U);
        if (IsFollowingSpawnPath() != 0) {
            StopFollowingSpawnPath();
        }
        if ((IsFollowingSpawnGraph() != 0) && (IsActive(0x30) == 0)) {
            StopFollowingSpawnGraph();
        }
        if (M2C_FIELD(this->unkC, f32 *, 0xAC8) <= 0.0f) {
            AddGoal_Death(&sp8);
            if (sp8.unk28 == 6) {
                AddGoal_Hit(&sp8);
            }
        } else {
            if (sp8.unk28 != 0xE) {
                AddGoal_Hit(&sp8);
                return;
            }
            goto block_17;
        }
    } else {
block_17:
        if (IsFollowingSpawnPath() != 0) {
            AddGoal_FollowSpawnPath();
        }
        if (IsFollowingSpawnGraph() != 0) {
            AddGoal_FollowSpawnGraph();
            return;
        }
        if ((IsFollowingSpawnPath() == 0) && (temp_r3_2735 = this->unkC, ((M2C_FIELD(temp_r3_2735, f32 *, 0xAC8) > 0.0f) != 0)) && (M2C_FIELD(M2C_FIELD(temp_r3_2735, void **, 0x44), u8 (**)(), 0x134)() == 0) && (((Enemy *) this->unkC)->IsFlinching(), (((u8) M2C_ERROR(/* Read from unset register $r3 */) == 0) != 0))) {
            temp_r3_2750 = this->unkC;
            var_r30_2751 = 0;
            if (((u8) M2C_FIELD(temp_r3_2750, u8 *, 0x8B8) == 2) || (((TargetContext *) (temp_r3_2750 + 0x8B0))->Get() != NULL)) {
                var_r30_2751 = 1;
            }
            if ((var_r30_2751 != 0) && (((u8) M2C_FIELD(this->unkC, u8 *, 0x8B9) >> 6U) & 1) && (IsFollowingSpawnPath() == 0) && (((AITargetData *) (this->unkC + 0x870))->IsAttackable() != 0)) {
                temp_r3_2777 = this->unkC;
                if (M2C_FIELD(M2C_FIELD(temp_r3_2777, void **, 0x44), u8 (**)(s32), 0x114)(temp_r3_2777) == 0) {
                    M2C_FIELD(this->unkC, f32 *, 0xB14) = (f32) (M2C_FIELD(&gb, f32 *, 0x30C) + 10.0f);
                    AddGoal_AlertMode(this->unkC + 0x870);
                    return;
                }
            }
            temp_r4_2797 = this->unkC;
            if (M2C_FIELD(&gb, f32 *, 0x30C) >= M2C_FIELD(temp_r4_2797, f32 *, 0xB14)) {
                AddGoal_Patrol();
                return;
            }
            AddGoal_AlertMode(temp_r4_2797 + 0x870);
        }
    }
}
#endif

void SwampTier3Goal_Think::Terminate() {
    this->unk8 = 1;
    RemoveAllSubgoals();
}

#if 0 // DRAFT: expression syntax error
u8 SwampTier3Goal_Think::Update() {
    Goal<SwampTier3> *temp_r3_2872;
    s32 temp_r3_2850;
    s32 temp_r3_2879;

    if (((Enemy *) this->unkC)->WasHit() != 0) {
        this->unk8 = 1;
    }
    temp_r3_2850 = this->unkC;
    if (M2C_FIELD(M2C_FIELD(temp_r3_2850, void **, 0x44), u8 (**)(s32), 0xE8)(temp_r3_2850) == 0) {
        ((Enemy *) this->unkC)->SelectTarget();
    }
    ActivateIfInactive();
    this->unk8 = UpdateSubgoals();
    if ((u8) this->unk8 != 0) {
        if (((u8) M2C_FIELD(this->unkC, u8 *, 0xB09) >> 4U) & 1) {
            temp_r3_2872 = this->unk3C;
            if (temp_r3_2872->IsComplete() != 0) {
                temp_r3_2879 = this->unkC;
                M2C_FIELD(temp_r3_2879, u8 *, 0xB09) = (u8) (M2C_FIELD(temp_r3_2879, u8 *, 0xB09) & ~0x10);
            }
        }
        Activate();
    }
    return (u8) this->unk8;
}
#endif

void SwampTier3Goal_Think::Reset() {
    this->unk8 = 1;
    RemoveAllSubgoals();
}

void SwampTier3Goal_Think::Activate() {
    this->unk8 = 0;
    if ((u32) M2C_FIELD(this->unkC, u32 *, 0xA94) != 0U) {
        StartFollowingSpawnPath();
    }
    if ((u32) M2C_FIELD(this->unkC, u32 *, 0xA80) != 0U) {
        StartFollowingSpawnGraph();
    }
    Arbitrate();
}

void SwampTier3Goal_Think::Deinit() {
    Goal<Enemy> *temp_r3_2982;
    Goal<SwampTier3> *temp_r3_2962;
    Goal<SwampTier3> *temp_r3_2967;
    Goal<SwampTier3> *temp_r3_2972;
    Goal<SwampTier3> *temp_r3_2977;
    Goal<SwampTier3> *temp_r3_2987;
    Goal<SwampTier3> *temp_r3_2992;
    Goal<SwampTier3> *temp_r3_2997;
    s32 temp_r31_3020;
    void **temp_r3_2957;

    temp_r3_2957 = this->unk20;
    M2C_FIELD(*temp_r3_2957, M2C_UNK (**)(void **), 0xC)(temp_r3_2957);
    temp_r3_2962 = this->unk28;
    temp_r3_2962->Deinit();
    temp_r3_2967 = this->unk2C;
    temp_r3_2967->Deinit();
    temp_r3_2972 = this->unk24;
    temp_r3_2972->Deinit();
    temp_r3_2977 = this->unk30;
    temp_r3_2977->Deinit();
    temp_r3_2982 = this->unk34;
    temp_r3_2982->Deinit();
    temp_r3_2987 = this->unk38;
    temp_r3_2987->Deinit();
    temp_r3_2992 = this->unk3C;
    temp_r3_2992->Deinit();
    temp_r3_2997 = this->unk40;
    temp_r3_2997->Deinit();
    operator delete(this->unk20);
    operator delete(this->unk28);
    operator delete(this->unk2C);
    operator delete(this->unk24);
    operator delete(this->unk30);
    operator delete(this->unk34);
    operator delete(this->unk38);
    operator delete(this->unk3C);
    operator delete(this->unk40);
    temp_r31_3020 = this->unk1C;
    if ((u32) temp_r31_3020 != 0U) {
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free((void *) temp_r31_3020, NULL, 0);
        } else {
            free((void *) temp_r31_3020);
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
void SwampTier3Goal_Think::Init(SwampTier3 *arg0) {
    Goal<SwampTier3> *temp_r4_3333;
    Goal<SwampTier3> *temp_r4_3356;
    void **temp_r4_3319;
    void *var_r3_3299;

    if ((u8) this->unk9 == 0) {
        operator new(0x18U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
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
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__21CompositeGoal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x1C) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x18) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x10) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x14) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk28 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x10U, NULL, 0);
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
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__18Goal<10SwampTier3>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__27CompositeGoal<10SwampTier3>;
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
        this->unk30 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x2CU, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__18Goal<10SwampTier3>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__27CompositeGoal<10SwampTier3>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x1C) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x18) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x10) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x14) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk34 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x30U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__18Goal<10SwampTier3>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__27CompositeGoal<10SwampTier3>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x1C) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x18) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x10) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x14) = 0;
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
    }
    if ((u8) this->unk9 == 0) {
        if (MKHeap::Current() != NULL) {
            var_r3_3299 = ((MKHeap *) (MKHeap::Current()))->Alloc(0xC, NULL, 0);
        } else {
            var_r3_3299 = malloc(0xC);
        }
        this->unk1C = (s32) var_r3_3299;
        this->unk10 = 3;
    }
    this->unk8 = 1;
    this->unkC = (s32) arg0;
    this->unk4 = 0x7A;
    if ((u32) this->unkC != 0U) {
        this->unk9 = 1;
    }
    temp_r4_3319 = this->unk20;
    M2C_FIELD(temp_r4_3319, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_3319, SwampTier3 **, 0xC) = arg0;
    M2C_FIELD(temp_r4_3319, s32 *, 4) = 5;
    if ((SwampTier3 *) M2C_FIELD(temp_r4_3319, SwampTier3 **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_3319, s8 *, 9) = 1;
    }
    ((EnemyGoal_Death *) this->unk28)->Init((Enemy *) arg0);
    temp_r4_3333 = this->unk2C;
    M2C_FIELD(temp_r4_3333, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_3333, SwampTier3 **, 0xC) = arg0;
    M2C_FIELD(temp_r4_3333, s32 *, 4) = 0x1E;
    if ((SwampTier3 *) M2C_FIELD(temp_r4_3333, SwampTier3 **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_3333, s8 *, 9) = 1;
    }
    ((SwampTier3Goal_Hit *) this->unk24)->Init(arg0);
    ((EnemyGoal_AlertMode *) this->unk30)->Init((Enemy *) arg0);
    ((SwampTier3Goal_Summon *) this->unk34)->Init(arg0);
    ((SwampTier3Goal_Patrol *) this->unk38)->Init(arg0);
    temp_r4_3356 = this->unk3C;
    M2C_FIELD(temp_r4_3356, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_3356, SwampTier3 **, 0xC) = arg0;
    M2C_FIELD(temp_r4_3356, s32 *, 4) = 0x22;
    if ((SwampTier3 *) M2C_FIELD(temp_r4_3356, SwampTier3 **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_3356, s8 *, 9) = 1;
    }
    ((EnemyGoal_FollowGraph *) this->unk40)->Init((Enemy *) arg0);
    this->unk44 &= ~0x80;
    this->unk44 &= ~0x40;
}
#endif
