#include "spyro/source/SwampTier2Goal_Think.h"
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
#include "spyro/source/Enemies_Swamp.h"
#include "spyro/source/Enemy.h"
#include "spyro/source/EnemyAttackPattern.h"
#include "spyro/source/EnemyDataTypes.h"
#include "spyro/source/EnemyDescriptor.h"
#include "spyro/source/EnemyGoal_FollowGraph.h"
#include "spyro/source/EnemyGoals_Death.h"
#include "spyro/source/EnemyGoals_Hit.h"
#include "spyro/source/EnemyRegion.h"
#include "spyro/source/EnemySettings.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/GameMessages.h"
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
#include "spyro/source/KDSpline.h"
#include "spyro/source/Level.h"
#include "spyro/source/MeleeTrails.h"
#include "spyro/source/Names.h"
#include "spyro/source/NodeLookAt.h"
#include "spyro/source/SB2.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/SpawnPointObject.h"
#include "spyro/source/SpawnerObject.h"
#include "spyro/source/SwampTier3Goals.h"
#include "spyro/source/TargetManager.h"
#include "unplaced_enums.h"
#include "common/Source/StdMath.h"
#include <m2c_macros.h>

M2C_UNK free(void *);                               /* extern */
void *malloc(M2C_UNK);                              /* extern */
extern void **gMK;
extern s32 gViewSeed;
extern M2C_UNK gb;

void SwampTier2Goal_MoveToTarget::Terminate() {
    Character *temp_r3_28;
    SB2 *temp_r3_33;

    temp_r3_28 = this->unkC;
    temp_r3_28->unk598 = 0.0f;
    temp_r3_28->unk59C = 0.0f;
    temp_r3_28->unk5A0 = 0.0f;
    temp_r3_33 = this->unkC->unk640;
    temp_r3_33->unk464 &= ~0x80;
    this->unkC->unk640->SeekOff();
    this->unkC->unk640->ContainmentOff();
    this->unkC->unk640->ObstacleAvoidanceOff();
    this->unkC->unk640->WallAvoidanceOff();
    this->unk8 = 1;
}

#if 0 // DRAFT: undefined identifier 'unk8B8'
u8 SwampTier2Goal_MoveToTarget::Update() {
    f64 sp10;
    f64 sp8;
    AnimSequence *temp_r4_130;
    AnimSequence *temp_r4_145;
    Character *temp_r29_124;
    Character *temp_r3_105;
    Character *temp_r3_142;
    Character *temp_r3_67;
    Character *temp_r3_81;
    Character *temp_r3_91;
    Character *temp_r5_149;
    f32 var_f0_158;
    u8 var_r30_125;
    u8 var_r30_68;
    u8 var_r30_92;
    void *temp_r5_83;

    ActivateIfInactive();
    temp_r3_67 = this->unkC;
    var_r30_68 = 0;
    if (((u8) temp_r3_67->unk8B8 == 2) || (((TargetContext *) &temp_r3_67->unk8B0)->Get() != NULL)) {
        var_r30_68 = 1;
    }
    if (var_r30_68 != 0) {
        temp_r3_81 = this->unkC;
        temp_r5_83 = temp_r3_81->unk8;
        sp8 = M2C_FIELD(temp_r5_83, f64 *, 0x30);
        sp10 = M2C_FIELD(temp_r5_83, f64 *, 0x38);
        ((AITargetData *) &temp_r3_81->unk870)->Update(*((MKVector3 *) &sp8));
    }
    temp_r3_91 = this->unkC;
    var_r30_92 = 0;
    if (((u8) temp_r3_91->unk8B8 == 2) || (((TargetContext *) &temp_r3_91->unk8B0)->Get() != NULL)) {
        var_r30_92 = 1;
    }
    if ((var_r30_92 == 0) || (temp_r3_105 = this->unkC, (((((u8) temp_r3_105->unk8B9 >> 6U) & 1) == 0) != 0))) {
        this->unk8 = 3;
    } else if (((AITargetData *) &temp_r3_105->unk870)->GetDist() <= this->unk10) {
        this->unk8 = 2;
    } else {
        temp_r29_124 = this->unkC;
        var_r30_125 = 0;
        if (temp_r29_124->HasAnimFinished() != 0) {
            temp_r4_130 = temp_r29_124->unkA50;
            if ((temp_r4_130 != NULL) && ((u32) temp_r4_130->unk0 == (u32) M2C_FIELD(temp_r29_124->unk630, u32 *, 0x20))) {
                var_r30_125 = 1;
            }
        }
        if (var_r30_125 != 0) {
            temp_r3_142 = this->unkC;
            temp_r4_145 = temp_r3_142->unkA50;
            ((Enemy *) temp_r3_142)->SetAnim(temp_r4_145, (AnimTransition *) &temp_r4_145->unk20, 0.0f, 0U);
        }
        temp_r5_149 = this->unkC;
        if ((u32) temp_r5_149->unkA54 == &temp_r5_149->unkA50->unk20) {
            var_f0_158 = temp_r5_149->unk690 / temp_r5_149->unk694;
            if (var_f0_158 < 1.0f) {

            } else {
                var_f0_158 = 1.0f;
            }
            if (var_f0_158 > 0.5f) {

            } else {
                var_f0_158 = 0.5f;
            }
            M2C_FIELD(temp_r5_149->unk630, f32 *, 0x38) = var_f0_158;
        }
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: expression syntax error
void SwampTier2Goal_MoveToTarget::Activate() {
    Character *temp_r3_196;
    Character *temp_r4_229;
    SB2 *temp_r3_225;
    s32 var_r6_188;

    var_r6_188 = 1;
    this->unk8 = 0;
    temp_r3_196 = this->unkC;
    if (M2C_FIELD(&gb, f32 *, 0x30C) >= M2C_FIELD(temp_r3_196, f32 *, 0xB20)) {
        var_r6_188 = 0;
        M2C_FIELD(temp_r3_196, f32 *, 0xB20) = (f32) (M2C_FIELD(&gb, f32 *, 0x30C) + 5.0f);
    }
    ((Enemy *) this->unkC)->SetAnim((AnimSequenceType) 6, 0, var_r6_188, 0.15f, 0U, 0U);
    this->unkC->StopMovement(1U);
    ((Enemy *) this->unkC)->SetRunMovementSpeed(1U);
    this->unkC->SetMovementType((CharacterMoveType) 0);
    temp_r3_225 = this->unkC->unk640;
    temp_r3_225->unk464 |= 0x80;
    temp_r4_229 = this->unkC;
    temp_r4_229->unk640->SeekOn((AITargetData *) &temp_r4_229->unk870);
    this->unkC->unk640->ObstacleAvoidanceOn(NULL);
    this->unkC->unk640->ContainmentOn();
    this->unkC->unk640->WallAvoidanceOn();
}
#endif

void SwampTier2Goal_MoveToTarget::Init(SwampTier2 *arg0) {
    this->unk8 = 1;
    this->unkC = (Character *) arg0;
    this->unk4 = 0x21;
    if ((Character *) this->unkC != NULL) {
        this->unk9 = 1;
    }
}

#if 0 // DRAFT: undefined identifier '__vptr'
void SwampTier2Goal_Attack2::Terminate() {
    AttackerManager *var_r3_299;
    Enemy *temp_r3_274;
    Enemy *temp_r3_280;
    Enemy *var_r4_306;
    u8 var_r31_273;

    var_r31_273 = 0;
    temp_r3_274 = this->unkC;
    temp_r3_274->unkB08 &= ~0x10;
    this->unkC->unkA20 = NULL;
    temp_r3_280 = this->unkC;
    if (((u8) M2C_FIELD(temp_r3_280, u8 *, 0x8B8) == 2) || (temp_r3_280->unk870.unk40.Get() != NULL)) {
        var_r31_273 = 1;
    }
    if (var_r31_273 != 0) {
        var_r3_299 = M2C_FIELD(this->unkC->unk870.unk40.Get()->__vptr, AttackerManager *(**)(), 0x48)();
    } else {
        var_r3_299 = NULL;
    }
    if (var_r3_299 != NULL) {
        var_r4_306 = this->unkC;
        if (var_r4_306 != NULL) {
            var_r4_306 += 0x6B8;
        }
        var_r3_299->Remove((Targetable *) var_r4_306, 2);
    }
    this->unkC->SetInvulnerableToMeleeAttacks(0U, 1U);
    this->unkC->SetInvulnerableToBreathAttacks(0U, 1U);
    this->unk8 = 1;
}
#endif

#if 0 // DRAFT: type mismatch 'AnimTransition *' and 'unsigned long *'
u8 SwampTier2Goal_Attack2::Update() {
    AnimSequence *temp_r4_366;
    AnimSequence *temp_r4_381;
    AnimSequence *temp_r4_397;
    AnimSequence *temp_r4_423;
    Enemy *temp_r29_360;
    Enemy *temp_r29_417;
    Enemy *temp_r3_340;
    Enemy *temp_r3_378;
    Enemy *temp_r3_385;
    Enemy *temp_r3_394;
    Enemy *temp_r3_401;
    Enemy *temp_r4_353;
    EnemyAttack *temp_r4_402;
    u8 var_r30_339;
    u8 var_r30_361;
    u8 var_r30_418;

    var_r30_339 = 0;
    temp_r3_340 = this->unkC;
    if (((u8) M2C_FIELD(temp_r3_340, u8 *, 0x8B8) == 2) || (temp_r3_340->unk870.unk40.Get() != NULL)) {
        var_r30_339 = 1;
    }
    if (var_r30_339 != 0) {
        temp_r4_353 = this->unkC;
        temp_r4_353->unk870.Update(temp_r4_353->unk588);
    }
    ActivateIfInactive();
    temp_r29_360 = this->unkC;
    var_r30_361 = 0;
    if (((Character *) temp_r29_360)->HasAnimFinished() != 0) {
        temp_r4_366 = temp_r29_360->unkA50;
        if ((temp_r4_366 != NULL) && ((u32) temp_r4_366->unk0 == (u32) M2C_FIELD(temp_r29_360->unk630, u32 *, 0x20))) {
            var_r30_361 = 1;
        }
    }
    if (var_r30_361 != 0) {
        temp_r3_378 = this->unkC;
        temp_r4_381 = temp_r3_378->unkA50;
        temp_r3_378->SetAnim(temp_r4_381, (AnimTransition *) &temp_r4_381->unk20, 0.0f, 0U);
    }
    temp_r3_385 = this->unkC;
    if ((AnimTransition *) temp_r3_385->unkA54 == &temp_r3_385->unkA50->unk20) {
        if (((Character *) temp_r3_385)->HasAnimFinished() != 0) {
            temp_r3_394 = this->unkC;
            temp_r4_397 = temp_r3_394->unkA50;
            temp_r3_394->SetAnim(temp_r4_397, (AnimTransition *) &temp_r4_397->unk40, 0.0f, 0U);
        }
        temp_r3_401 = this->unkC;
        temp_r4_402 = temp_r3_401->unkA20;
        if (((s32) temp_r4_402->unk78 > 0) && (((u8) temp_r3_401->unkB08 >> 4U) & 1) && (temp_r3_401->CheckMeleeHit(temp_r4_402, -1) != 0)) {
            this->unkC->SetHitTarget(1U);
        }
    }
    temp_r29_417 = this->unkC;
    var_r30_418 = 0;
    if (((Character *) temp_r29_417)->HasAnimFinished() != 0) {
        temp_r4_423 = temp_r29_417->unkA50;
        if ((temp_r4_423 != NULL) && ((u32) temp_r4_423->unk40 == (u32) M2C_FIELD(temp_r29_417->unk630, u32 *, 0x20))) {
            var_r30_418 = 1;
        }
    }
    if (var_r30_418 != 0) {
        this->unk8 = 2;
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void SwampTier2Goal_Attack2::Activate() {
    AttackSweepData *temp_r3_472;
    AttackerManager *var_r3_497;
    Enemy *temp_r3_477;
    Enemy *temp_r3_512;
    Enemy *temp_r4_460;
    Enemy *var_r4_504;
    u8 var_r30_478;

    this->unk8 = 0;
    this->unkC->SelectAttack(0x10, 0x3D);
    temp_r4_460 = this->unkC;
loop_2:
    if ((u32) *temp_r4_460->unkA1C != 0) {
        temp_r4_460->unkA1C += 4;
        goto loop_2;
    }
    temp_r3_472 = this->unkC->unkA30;
    if (temp_r3_472 != NULL) {
        temp_r3_472->SetDefaults();
    }
    temp_r3_477 = this->unkC;
    var_r30_478 = 0;
    if (((u8) M2C_FIELD(temp_r3_477, u8 *, 0x8B8) == 2) || (temp_r3_477->unk870.unk40.Get() != NULL)) {
        var_r30_478 = 1;
    }
    if (var_r30_478 != 0) {
        var_r3_497 = M2C_FIELD(this->unkC->unk870.unk40.Get()->__vptr, AttackerManager *(**)(), 0x48)();
    } else {
        var_r3_497 = NULL;
    }
    if (var_r3_497 != NULL) {
        var_r4_504 = this->unkC;
        if (var_r4_504 != NULL) {
            var_r4_504 += 0x6B8;
        }
        var_r3_497->Add((Targetable *) var_r4_504, 2);
    }
    temp_r3_512 = this->unkC;
    if (temp_r3_512->unkA20->unk38 & 0x40000000) {
        temp_r3_512->SetInvulnerableToMeleeAttacks(1U, 1U);
        this->unkC->SetInvulnerableToBreathAttacks(1U, 1U);
    }
    this->unkC->SetAnim((AnimSequenceType) 0x10, 0x3D, 0, 0.15f, 0U, 0U);
    ((Character *) this->unkC)->StopMovement(1U);
    ((Character *) this->unkC)->SetMovementType((CharacterMoveType) 0);
}
#endif

void SwampTier2Goal_Attack2::Init(SwampTier2 *arg0) {
    this->unk8 = 1;
    this->unkC = (Enemy *) arg0;
    this->unk4 = 0x3A;
    if ((Enemy *) this->unkC != NULL) {
        this->unk9 = 1;
    }
}

#if 0 // DRAFT: undefined identifier '__vptr'
void SwampTier2Goal_Attack1::Terminate() {
    AttackerManager *var_r3_595;
    Enemy *temp_r3_570;
    Enemy *temp_r3_576;
    Enemy *var_r4_602;
    u8 var_r31_569;

    var_r31_569 = 0;
    temp_r3_570 = this->unkC;
    temp_r3_570->unkB08 &= ~0x10;
    this->unkC->unkA20 = NULL;
    temp_r3_576 = this->unkC;
    if (((u8) M2C_FIELD(temp_r3_576, u8 *, 0x8B8) == 2) || (temp_r3_576->unk870.unk40.Get() != NULL)) {
        var_r31_569 = 1;
    }
    if (var_r31_569 != 0) {
        var_r3_595 = M2C_FIELD(this->unkC->unk870.unk40.Get()->__vptr, AttackerManager *(**)(), 0x48)();
    } else {
        var_r3_595 = NULL;
    }
    if (var_r3_595 != NULL) {
        var_r4_602 = this->unkC;
        if (var_r4_602 != NULL) {
            var_r4_602 += 0x6B8;
        }
        var_r3_595->Remove((Targetable *) var_r4_602, 2);
    }
    this->unkC->SetInvulnerableToMeleeAttacks(0U, 1U);
    this->unkC->SetInvulnerableToBreathAttacks(0U, 1U);
    this->unk8 = 1;
}
#endif

#if 0 // DRAFT: type mismatch 'AnimTransition *' and 'unsigned long *'
u8 SwampTier2Goal_Attack1::Update() {
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    M2C_UNK sp8;
    AnimSequence *temp_r4_664;
    AnimSequence *temp_r4_679;
    AnimSequence *temp_r4_756;
    AnimSequence *temp_r4_782;
    Enemy *temp_r29_658;
    Enemy *temp_r29_776;
    Enemy *temp_r30_693;
    Enemy *temp_r3_638;
    Enemy *temp_r3_676;
    Enemy *temp_r3_683;
    Enemy *temp_r3_753;
    Enemy *temp_r3_760;
    Enemy *temp_r4_651;
    EnemyAttack *temp_r4_761;
    f64 temp_f0_697;
    f64 temp_f0_709;
    f64 temp_f1_692;
    u8 var_r29_715;
    u8 var_r30_637;
    u8 var_r30_659;
    u8 var_r30_777;

    var_r30_637 = 0;
    temp_r3_638 = this->unkC;
    if (((u8) M2C_FIELD(temp_r3_638, u8 *, 0x8B8) == 2) || (temp_r3_638->unk870.unk40.Get() != NULL)) {
        var_r30_637 = 1;
    }
    if (var_r30_637 != 0) {
        temp_r4_651 = this->unkC;
        temp_r4_651->unk870.Update(temp_r4_651->unk588);
    }
    ActivateIfInactive();
    temp_r29_658 = this->unkC;
    var_r30_659 = 0;
    if (((Character *) temp_r29_658)->HasAnimFinished() != 0) {
        temp_r4_664 = temp_r29_658->unkA50;
        if ((temp_r4_664 != NULL) && ((u32) temp_r4_664->unk0 == (u32) M2C_FIELD(temp_r29_658->unk630, u32 *, 0x20))) {
            var_r30_659 = 1;
        }
    }
    if (var_r30_659 != 0) {
        temp_r3_676 = this->unkC;
        temp_r4_679 = temp_r3_676->unkA50;
        temp_r3_676->SetAnim(temp_r4_679, (AnimTransition *) &temp_r4_679->unk20, 0.15f, 0U);
    }
    temp_r3_683 = this->unkC;
    if ((AnimTransition *) temp_r3_683->unkA54 == &temp_r3_683->unkA50->unk20) {
        temp_f1_692 = M2C_FIELD(temp_r3_683->__vptr, f64 (**)(), 0x100)();
        temp_r30_693 = this->unkC;
        temp_f0_697 = M2C_FIELD(temp_r30_693, f64 *, 0xC0) * temp_f1_692;
        sp28 = temp_f0_697;
        sp38 = temp_f0_697;
        sp30 = temp_r30_693->unkC8 * (f32) temp_f1_692;
        sp40 = (f64) sp30;
        temp_f0_709 = M2C_FIELD(temp_r30_693, f64 *, 0x588) + temp_f0_697;
        sp18 = temp_f0_709;
        var_r29_715 = 0;
        sp48 = temp_f0_709;
        sp20 = temp_r30_693->unk588.unk8 + (f32) sp40;
        sp50 = (f64) sp20;
        if (temp_r30_693->unk800.IsPointWithin(*((MKVector3 *) &sp48)) != 0) {
            ((EnemyRegion *) &sp8)->GetRegionPos();
            if ((f32) fabs(spC - (*(f32 *) ((u8 *) &sp48 + 0x4))) <= 500.0f) {
                var_r29_715 = 1;
            }
        }
        if ((var_r29_715 == 0) || (this->unkC->unk838.IsPointWithin(*((MKVector3 *) &sp48)) != 0) || ((s32) M2C_FIELD(this->unkC->unk630, s32 *, 0x44) >= 2)) {
            temp_r3_753 = this->unkC;
            temp_r4_756 = temp_r3_753->unkA50;
            temp_r3_753->SetAnim(temp_r4_756, (AnimTransition *) &temp_r4_756->unk40, 0.15f, 0U);
        }
        temp_r3_760 = this->unkC;
        temp_r4_761 = temp_r3_760->unkA20;
        if (((s32) temp_r4_761->unk78 > 0) && (((u8) temp_r3_760->unkB08 >> 4U) & 1) && (temp_r3_760->CheckMeleeHit(temp_r4_761, -1) != 0)) {
            this->unkC->SetHitTarget(1U);
        }
    }
    temp_r29_776 = this->unkC;
    var_r30_777 = 0;
    if (((Character *) temp_r29_776)->HasAnimFinished() != 0) {
        temp_r4_782 = temp_r29_776->unkA50;
        if ((temp_r4_782 != NULL) && ((u32) temp_r4_782->unk40 == (u32) M2C_FIELD(temp_r29_776->unk630, u32 *, 0x20))) {
            var_r30_777 = 1;
        }
    }
    if (var_r30_777 != 0) {
        this->unk8 = 2;
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void SwampTier2Goal_Attack1::Activate() {
    AttackSweepData *temp_r3_833;
    AttackerManager *var_r3_858;
    Enemy *temp_r3_838;
    Enemy *temp_r3_873;
    Enemy *temp_r4_821;
    Enemy *var_r4_865;
    u8 var_r30_839;

    this->unk8 = 0;
    this->unkC->SelectAttack(0x10, 0x3C);
    temp_r4_821 = this->unkC;
loop_2:
    if ((u32) *temp_r4_821->unkA1C != 0) {
        temp_r4_821->unkA1C += 4;
        goto loop_2;
    }
    temp_r3_833 = this->unkC->unkA30;
    if (temp_r3_833 != NULL) {
        temp_r3_833->SetDefaults();
    }
    temp_r3_838 = this->unkC;
    var_r30_839 = 0;
    if (((u8) M2C_FIELD(temp_r3_838, u8 *, 0x8B8) == 2) || (temp_r3_838->unk870.unk40.Get() != NULL)) {
        var_r30_839 = 1;
    }
    if (var_r30_839 != 0) {
        var_r3_858 = M2C_FIELD(this->unkC->unk870.unk40.Get()->__vptr, AttackerManager *(**)(), 0x48)();
    } else {
        var_r3_858 = NULL;
    }
    if (var_r3_858 != NULL) {
        var_r4_865 = this->unkC;
        if (var_r4_865 != NULL) {
            var_r4_865 += 0x6B8;
        }
        var_r3_858->Add((Targetable *) var_r4_865, 2);
    }
    temp_r3_873 = this->unkC;
    if (temp_r3_873->unkA20->unk38 & 0x40000000) {
        temp_r3_873->SetInvulnerableToMeleeAttacks(1U, 1U);
        this->unkC->SetInvulnerableToBreathAttacks(1U, 1U);
    }
    this->unkC->SetAnim((AnimSequenceType) 0x10, 0x3C, 0, 0.15f, 0U, 0U);
    ((Character *) this->unkC)->StopMovement(1U);
    ((Character *) this->unkC)->SetMovementType((CharacterMoveType) 0);
}
#endif

void SwampTier2Goal_Attack1::Init(SwampTier2 *arg0) {
    this->unk8 = 1;
    this->unkC = (Enemy *) arg0;
    this->unk4 = 0x3A;
    if ((Enemy *) this->unkC != NULL) {
        this->unk9 = 1;
    }
}

void SwampTier2Goal_AlertMode::Terminate() {
    Enemy *temp_r5_930;
    Enemy *temp_r5_934;

    temp_r5_930 = this->unkC;
    temp_r5_930->unkB08 &= ~0x40;
    temp_r5_934 = this->unkC;
    temp_r5_934->unkB08 &= ~0x20;
    this->unk8 = 1;
    RemoveAllSubgoals();
}

u8 SwampTier2Goal_AlertMode::Update() {
    AITargetData *temp_r3_958;
    u8 var_r31_962;

    ActivateIfInactive();
    this->unk8 = UpdateSubgoals();
    temp_r3_958 = this->unk20;
    if (temp_r3_958 != NULL) {
        var_r31_962 = 0;
        if (((u8) M2C_FIELD(temp_r3_958, u8 *, 0x48) == 2) || (temp_r3_958->unk40.Get() != NULL)) {
            var_r31_962 = 1;
        }
        if (var_r31_962 != 0) {
            if (((u8) this->unk40 != 0) && ((u8) this->unk8 == 3)) {
                this->unk8 = 0;
                this->unk40 = 0;
            }
            if ((u8) this->unk8 == 2) {
                this->unk8 = 1;
                this->unk40 = 0;
            }
            ReactivateIfFailed();
            ActivateIfInactive();
        }
    }
    return this->unk8;
}

#if 0 // DRAFT: illegal type
void SwampTier2Goal_AlertMode::Activate() {
    IsInAlertRangeMsg sp18;
    f64 sp10;
    f64 sp8;
    AITargetData *temp_r3_1018;
    AITargetData *temp_r3_1098;
    AITargetData *temp_r3_1192;
    AttackerManager *temp_r3_1088;
    Enemy *temp_r3_1107;
    Enemy *temp_r3_1201;
    Enemy *temp_r5_1038;
    Enemy *temp_r5_1146;
    Enemy *temp_r5_1240;
    Enemy *temp_r7_1056;
    Goal<SwampTier2> *temp_r3_1074;
    Goal<SwampTier2> *temp_r3_1147;
    Goal<SwampTier2> *temp_r3_1241;
    Goal<SwampTier2> *temp_r6_1291;
    Goal<SwampTier2> *temp_r7_1176;
    Goal<SwampTier2> *temp_r7_1270;
    s32 var_r30_1093;
    u8 var_r30_1016;
    void *temp_r5_1050;

    this->unk8 = 0;
    RemoveAllSubgoals();
    var_r30_1016 = 0;
    this->unk40 = 0;
    temp_r3_1018 = this->unk20;
    if (temp_r3_1018 != NULL) {
        if (((u8) M2C_FIELD(temp_r3_1018, u8 *, 0x48) == 2) || (temp_r3_1018->unk40.Get() != NULL)) {
            var_r30_1016 = 1;
        }
        if (var_r30_1016 == 0) {
            goto block_5;
        }
        temp_r5_1038 = this->unkC;
        if (!(((u8) temp_r5_1038->unkB08 >> 6U) & 1) && ((Goal<SwampTier2> *) this->unk24 != NULL)) {
            sp18.unk4 = 0;
            temp_r5_1050 = temp_r5_1038->unk8;
            sp8 = M2C_FIELD(temp_r5_1050, f64 *, 0x30);
            sp10 = M2C_FIELD(temp_r5_1050, f64 *, 0x38);
            sp18.Init(*((MKVector3 *) &sp8), 1000.0f);
            temp_r7_1056 = this->unkC;
            sp18.unk4 = (unsigned long) (temp_r7_1056);
            M2C_FIELD(*gMK, M2C_UNK (**)(void **, IsInAlertRangeMsg *, M2C_UNK, M2C_UNK, void *, M2C_UNK, f32), 0x94)(gMK, &sp18, 8, 0, temp_r7_1056->unk8 + 0x30, 1, 1000.0f);
            AddSubgoal((Goal<SwampTier2> *) this->unk24);
            temp_r3_1074 = this->unk24;
            M2C_FIELD(temp_r3_1074, AITargetData **, 0x10) = (AITargetData *) this->unk20;
            M2C_FIELD(temp_r3_1074, Enemy **, 0x14) = sp18.unk1C;
            M2C_FIELD(temp_r3_1074, f32 *, 0x18) = 0.0f;
            return;
        }
        temp_r3_1088 = M2C_FIELD(this->unk20->unk40.Get()->__vptr, AttackerManager *(**)(), 0x48)();
        if (temp_r3_1088 != NULL) {
            var_r30_1093 = temp_r3_1088->GetAttackerCount(1);
        } else {
            var_r30_1093 = 0;
        }
        temp_r3_1098 = this->unk20;
        if ((((u8) M2C_FIELD(temp_r3_1098, u8 *, 0x49) >> 6U) & 1) && ((s32) M2C_FIELD(this->unkC, s32 *, 0xB14) == 0)) {
            temp_r3_1107 = this->unkC;
            if ((temp_r3_1098->GetDist() < temp_r3_1107->unkA38->unk138) && (var_r30_1093 <= 0)) {
                temp_r3_1107->SelectAttack(0x10, 0x3C);
                if (this->unk20->GetDist() > this->unkC->unkA20->unk18) {
                    AddSubgoal((Goal<SwampTier2> *) this->unk34);
                    M2C_FIELD(this->unk34, f32 *, 0x10) = (f32) this->unkC->unkA20->unk18;
                } else if (this->unk20->GetDist() < this->unkC->unkA20->unk14) {
                    this->unk40 = 1;
                    AddSubgoal((Goal<SwampTier2> *) this->unk38);
                    temp_r5_1146 = this->unkC;
                    temp_r3_1147 = this->unk38;
                    M2C_FIELD(temp_r3_1147, AITargetData **, 0x10) = &temp_r5_1146->unk870;
                    M2C_FIELD(temp_r3_1147, f32 *, 0x14) = (f32) temp_r5_1146->unkA20->unk14;
                }
                AddSubgoal((Goal<SwampTier2> *) this->unk3C);
                AddSubgoal((Goal<SwampTier2> *) this->unk2C);
                AddSubgoal((Goal<SwampTier2> *) this->unk3C);
                AddSubgoal((Goal<SwampTier2> *) this->unk28);
                M2C_FIELD(this->unk3C, AITargetData **, 0x10) = (AITargetData *) this->unk20;
                temp_r7_1176 = this->unk28;
                M2C_FIELD(temp_r7_1176, AITargetData **, 0x10) = (AITargetData *) this->unk20;
                M2C_FIELD(temp_r7_1176, s32 *, 0x14) = 1;
                M2C_FIELD(temp_r7_1176, s32 *, 0x18) = 0xA;
                M2C_FIELD(temp_r7_1176, s32 *, 0x1C) = (s32) this->unkC->unk688;
                M2C_FIELD(temp_r7_1176, u8 *, 0x20) = (u8) (M2C_FIELD(temp_r7_1176, u8 *, 0x20) & ~0x40);
                M2C_FIELD(this->unkC, f32 *, 0xB1C) = (f32) (M2C_FIELD(&gb, f32 *, 0x30C) + 2.0f);
                return;
            }
        }
        temp_r3_1192 = this->unk20;
        if ((((u8) M2C_FIELD(temp_r3_1192, u8 *, 0x49) >> 6U) & 1) && ((s32) M2C_FIELD(this->unkC, s32 *, 0xB14) == 1)) {
            temp_r3_1201 = this->unkC;
            if ((temp_r3_1192->GetDist() < temp_r3_1201->unkA38->unk138) && (var_r30_1093 <= 0)) {
                temp_r3_1201->SelectAttack(0x10, 0x3D);
                if (this->unk20->GetDist() > this->unkC->unkA20->unk18) {
                    AddSubgoal((Goal<SwampTier2> *) this->unk34);
                    M2C_FIELD(this->unk34, f32 *, 0x10) = (f32) this->unkC->unkA20->unk18;
                } else if (this->unk20->GetDist() < this->unkC->unkA20->unk14) {
                    this->unk40 = 1;
                    AddSubgoal((Goal<SwampTier2> *) this->unk38);
                    temp_r5_1240 = this->unkC;
                    temp_r3_1241 = this->unk38;
                    M2C_FIELD(temp_r3_1241, AITargetData **, 0x10) = &temp_r5_1240->unk870;
                    M2C_FIELD(temp_r3_1241, f32 *, 0x14) = (f32) temp_r5_1240->unkA20->unk14;
                }
                AddSubgoal((Goal<SwampTier2> *) this->unk3C);
                AddSubgoal((Goal<SwampTier2> *) this->unk30);
                AddSubgoal((Goal<SwampTier2> *) this->unk3C);
                AddSubgoal((Goal<SwampTier2> *) this->unk28);
                M2C_FIELD(this->unk3C, AITargetData **, 0x10) = (AITargetData *) this->unk20;
                temp_r7_1270 = this->unk28;
                M2C_FIELD(temp_r7_1270, AITargetData **, 0x10) = (AITargetData *) this->unk20;
                M2C_FIELD(temp_r7_1270, s32 *, 0x14) = 1;
                M2C_FIELD(temp_r7_1270, s32 *, 0x18) = 0xA;
                M2C_FIELD(temp_r7_1270, s32 *, 0x1C) = (s32) this->unkC->unk688;
                M2C_FIELD(temp_r7_1270, u8 *, 0x20) = (u8) (M2C_FIELD(temp_r7_1270, u8 *, 0x20) & ~0x40);
                M2C_FIELD(this->unkC, f32 *, 0xB1C) = (f32) (M2C_FIELD(&gb, f32 *, 0x30C) + 2.0f);
                return;
            }
        }
        AddSubgoal((Goal<SwampTier2> *) this->unk28);
        temp_r6_1291 = this->unk28;
        M2C_FIELD(temp_r6_1291, AITargetData **, 0x10) = (AITargetData *) this->unk20;
        M2C_FIELD(temp_r6_1291, s32 *, 0x14) = 1;
        M2C_FIELD(temp_r6_1291, s32 *, 0x18) = 3;
        M2C_FIELD(temp_r6_1291, s32 *, 0x1C) = (s32) this->unkC->unk688;
        M2C_FIELD(temp_r6_1291, u8 *, 0x20) = (u8) (M2C_FIELD(temp_r6_1291, u8 *, 0x20) & ~0x40);
        return;
    }
block_5:
    this->unk8 = 2;
}
#endif

void SwampTier2Goal_AlertMode::Deinit() {
    Goal<SwampTier2> *temp_r3_1319;
    Goal<SwampTier2> *temp_r3_1324;
    Goal<SwampTier2> *temp_r3_1329;
    Goal<SwampTier2> *temp_r3_1334;
    Goal<SwampTier2> *temp_r3_1339;
    Goal<SwampTier2> *temp_r3_1344;
    Goal<SwampTier2> *temp_r3_1349;
    void *temp_r31_1368;

    temp_r3_1319 = this->unk24;
    temp_r3_1319->Deinit();
    temp_r3_1324 = this->unk28;
    temp_r3_1324->Deinit();
    temp_r3_1329 = this->unk2C;
    temp_r3_1329->Deinit();
    temp_r3_1334 = this->unk30;
    temp_r3_1334->Deinit();
    temp_r3_1339 = this->unk34;
    temp_r3_1339->Deinit();
    temp_r3_1344 = this->unk38;
    temp_r3_1344->Deinit();
    temp_r3_1349 = this->unk3C;
    temp_r3_1349->Deinit();
    operator delete(this->unk24);
    operator delete(this->unk28);
    operator delete(this->unk2C);
    operator delete(this->unk30);
    operator delete(this->unk34);
    operator delete(this->unk38);
    operator delete(this->unk3C);
    temp_r31_1368 = this->unk1C;
    if (temp_r31_1368 != NULL) {
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_1368, NULL, 0);
        } else {
            free(temp_r31_1368);
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
void SwampTier2Goal_AlertMode::Init(SwampTier2 *arg0) {
    Goal<SwampTier2> *temp_r4_1589;
    Goal<SwampTier2> *temp_r4_1600;
    Goal<SwampTier2> *temp_r4_1620;
    Goal<SwampTier2> *temp_r4_1631;
    void *var_r3_1566;

    if ((arg0 != NULL) && ((u8) this->unk9 == 0)) {
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
        operator new(0x10U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__18Goal<10SwampTier2>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk2C = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x10U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__18Goal<10SwampTier2>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk30 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x14U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__18Goal<10SwampTier2>;
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
    }
    if ((u8) this->unk9 == 0) {
        if (MKHeap::Current() != NULL) {
            var_r3_1566 = ((MKHeap *) (MKHeap::Current()))->Alloc(0x14, NULL, 0);
        } else {
            var_r3_1566 = malloc(0x14);
        }
        this->unk1C = var_r3_1566;
        this->unk10 = 5;
    }
    this->unk8 = 1;
    this->unkC = (Enemy *) arg0;
    this->unk4 = 0x54;
    if ((Enemy *) this->unkC != NULL) {
        this->unk9 = 1;
    }
    if ((u8) this->unk9 != 0) {
        temp_r4_1589 = this->unk24;
        M2C_FIELD(temp_r4_1589, s8 *, 8) = 1;
        M2C_FIELD(temp_r4_1589, SwampTier2 **, 0xC) = arg0;
        M2C_FIELD(temp_r4_1589, s32 *, 4) = 2;
        if ((SwampTier2 *) M2C_FIELD(temp_r4_1589, SwampTier2 **, 0xC) != NULL) {
            M2C_FIELD(temp_r4_1589, s8 *, 9) = 1;
        }
        temp_r4_1600 = this->unk28;
        M2C_FIELD(temp_r4_1600, s8 *, 8) = 1;
        M2C_FIELD(temp_r4_1600, SwampTier2 **, 0xC) = arg0;
        M2C_FIELD(temp_r4_1600, s32 *, 4) = 0;
        if ((SwampTier2 *) M2C_FIELD(temp_r4_1600, SwampTier2 **, 0xC) != NULL) {
            M2C_FIELD(temp_r4_1600, s8 *, 9) = 1;
        }
        ((SwampTier2Goal_Attack1 *) this->unk2C)->Init(arg0);
        ((SwampTier2Goal_Attack2 *) this->unk30)->Init(arg0);
        ((SwampTier2Goal_MoveToTarget *) this->unk34)->Init(arg0);
        temp_r4_1620 = this->unk38;
        M2C_FIELD(temp_r4_1620, s8 *, 8) = 1;
        M2C_FIELD(temp_r4_1620, SwampTier2 **, 0xC) = arg0;
        M2C_FIELD(temp_r4_1620, s32 *, 4) = 0x1F;
        if ((SwampTier2 *) M2C_FIELD(temp_r4_1620, SwampTier2 **, 0xC) != NULL) {
            M2C_FIELD(temp_r4_1620, s8 *, 9) = 1;
        }
        temp_r4_1631 = this->unk3C;
        M2C_FIELD(temp_r4_1631, s8 *, 8) = 1;
        M2C_FIELD(temp_r4_1631, SwampTier2 **, 0xC) = arg0;
        M2C_FIELD(temp_r4_1631, s32 *, 4) = 0x27;
        if ((SwampTier2 *) M2C_FIELD(temp_r4_1631, SwampTier2 **, 0xC) != NULL) {
            M2C_FIELD(temp_r4_1631, s8 *, 9) = 1;
        }
    }
    this->unk40 = 0;
}
#endif

void SwampTier2Goal_Hide::Terminate() {
    M2C_FIELD(this->unkC, f32 *, 0xB1C) = (f32) (M2C_FIELD(&gb, f32 *, 0x30C) + 2.0f);
    this->unk8 = 1;
}

#if 0 // DRAFT: undefined identifier 'unkA50'
u8 SwampTier2Goal_Hide::Update() {
    AnimSequence *temp_r4_1681;
    AnimSequence *temp_r4_1696;
    AnimSequence *temp_r4_1717;
    AnimSequence *temp_r4_1727;
    Character *temp_r29_1675;
    Character *temp_r29_1721;
    Character *temp_r3_1693;
    Character *temp_r3_1716;
    Character *temp_r4_1711;
    u8 temp_r3_1703;
    u8 var_r30_1676;
    u8 var_r30_1722;

    ActivateIfInactive();
    temp_r29_1675 = this->unkC;
    var_r30_1676 = 0;
    if (temp_r29_1675->HasAnimFinished() != 0) {
        temp_r4_1681 = temp_r29_1675->unkA50;
        if ((temp_r4_1681 != NULL) && ((u32) temp_r4_1681->unk0 == (u32) M2C_FIELD(temp_r29_1675->unk630, u32 *, 0x20))) {
            var_r30_1676 = 1;
        }
    }
    if (var_r30_1676 != 0) {
        temp_r3_1693 = this->unkC;
        temp_r4_1696 = temp_r3_1693->unkA50;
        ((Enemy *) temp_r3_1693)->SetAnim(temp_r4_1696, (AnimTransition *) &temp_r4_1696->unk20, 0.15f, 0U);
        M2C_FIELD(this->unkC, s32 *, 0xB10) = 2;
    }
    temp_r3_1703 = this->unk10;
    if ((temp_r3_1703 >> 7U) & 1) {
        this->unk10 = temp_r3_1703 & ~0x80;
        temp_r4_1711 = this->unkC;
        M2C_FIELD(temp_r4_1711, s32 *, 0xB10) = (s32) (M2C_FIELD(temp_r4_1711, s32 *, 0xB14) != 0);
        temp_r3_1716 = this->unkC;
        temp_r4_1717 = temp_r3_1716->unkA50;
        ((Enemy *) temp_r3_1716)->SetAnim(temp_r4_1717, (AnimTransition *) &temp_r4_1717->unk40, 0.15f, 0U);
    }
    temp_r29_1721 = this->unkC;
    var_r30_1722 = 0;
    if (temp_r29_1721->HasAnimFinished() != 0) {
        temp_r4_1727 = temp_r29_1721->unkA50;
        if ((temp_r4_1727 != NULL) && ((u32) temp_r4_1727->unk40 == (u32) M2C_FIELD(temp_r29_1721->unk630, u32 *, 0x20))) {
            var_r30_1722 = 1;
        }
    }
    if (var_r30_1722 != 0) {
        this->unk8 = 2;
    }
    return this->unk8;
}
#endif

void SwampTier2Goal_Hide::Activate() {
    this->unk8 = 0;
    this->unk10 &= ~0x80;
    M2C_FIELD(this->unkC, f32 *, 0xB1C) = (f32) (M2C_FIELD(&gb, f32 *, 0x30C) + 2.0f);
    ((Enemy *) this->unkC)->SetAnim((AnimSequenceType) 1, 0xC, 0, 0.15f, 0U, 0U);
    this->unkC->StopMovement(1U);
    this->unkC->SetMovementType((CharacterMoveType) 0);
}

void SwampTier2Goal_Hide::Init(SwampTier2 *arg0) {
    this->unk8 = 1;
    this->unkC = (Character *) arg0;
    this->unk4 = 0x79;
    if ((Character *) this->unkC != NULL) {
        this->unk9 = 1;
    }
}

void SwampTier2Goal_Think::StartFollowingSpawnGraph() {
    Enemy *temp_r4_1812;

    if (!(((u8) this->unk3C >> 7U) & 1)) {
        temp_r4_1812 = this->unkC;
        temp_r4_1812->unkB09 |= 8;
        this->unk3C |= 0x80;
    }
}

#if 0 // DRAFT: undefined identifier '__vptr'
void SwampTier2Goal_Think::StopFollowingSpawnGraph() {
    Enemy *temp_r3_1846;
    Enemy *temp_r5_1833;

    temp_r5_1833 = this->unkC;
    temp_r5_1833->unkB09 &= ~8;
    if (M2C_FIELD(this->__vptr, u8 (**)(M2C_UNK, Enemy *, M2C_UNK), 0x38)(0x2A, temp_r5_1833, 0) != 0) {
        RemoveAllSubgoals();
    }
    temp_r3_1846 = this->unkC;
    temp_r3_1846->SetupEnemyRegion(temp_r3_1846->unk588, 1000.0f);
}
#endif

u8 SwampTier2Goal_Think::IsFollowingSpawnGraph() {
    return ((u8) this->unkC->unkB09 >> 3U) & 1;
}

void SwampTier2Goal_Think::AddGoal_FollowSpawnGraph() {
    Enemy *temp_r3_1886;
    Enemy *temp_r3_1891;

    if (IsPresent(0x2A) == 0) {
        RemoveAllSubgoals();
        AddSubgoal((Goal<SwampTier2> *) this->unk38);
        temp_r3_1886 = this->unkC;
        temp_r3_1886->unkB09 |= 8;
        temp_r3_1891 = this->unkC;
        temp_r3_1891->unkB08 |= 0x40;
    }
}

void SwampTier2Goal_Think::AddGoal_AlertMode(bool arg0) {
    if (IsPresent(0x54) == 0) {
        if (arg0 == 0) {
            RemoveAllSubgoals();
        }
        AddSubgoal((Goal<SwampTier2> *) this->unk34);
        M2C_FIELD(this->unk34, AITargetData **, 0x20) = &this->unkC->unk870;
    }
}

void SwampTier2Goal_Think::AddGoal_Hide() {
    if (IsPresent(0x79) == 0) {
        RemoveAllSubgoals();
        AddSubgoal((Goal<SwampTier2> *) this->unk30);
    }
}

void SwampTier2Goal_Think::AddGoal_Respawn() {
    if (IsPresent(0x1E) == 0) {
        RemoveAllSubgoals();
        AddSubgoal((Goal<SwampTier2> *) this->unk2C);
    }
}

void SwampTier2Goal_Think::AddGoal_Death(EnemyDamageFeedback *arg0) {
    s32 temp_r0_2064;
    s32 temp_r0_2116;
    u8 var_r30_2004;
    u8 var_r30_2022;

    var_r30_2004 = 0;
    if ((s32) arg0->unk28 == 6) {
        if (IsActive(0x11) == 0) {
            AddGoal_Hit(arg0);
            var_r30_2004 = 1;
        }
    } else {
        var_r30_2022 = 0;
        if ((IsActive(0x11) == 0) && ((IsActive(0xB) != 0) || (IsActive(0x13) != 0) || (IsActive(0xC) != 0))) {
            var_r30_2022 = 1;
        }
        if (var_r30_2022 != 0) {
            AddGoal_Hit(arg0);
            var_r30_2004 = 1;
        } else {
            temp_r0_2064 = arg0->unk28;
            if ((temp_r0_2064 == 2) || (temp_r0_2064 == 8) || (temp_r0_2064 == 0xA)) {
                AddGoal_Hit(arg0);
                var_r30_2004 = 1;
            } else {
                var_r30_2004 = 0;
                if ((IsActive(0xC) != 0) || (IsActive(0xD) != 0)) {
                    var_r30_2004 = 1;
                }
            }
        }
    }
    if (IsPresent(0x5B) == 0) {
        if (var_r30_2004 != 0) {
loop_22:
            temp_r0_2116 = this->unk14;
            if (temp_r0_2116 > 1) {
                if (temp_r0_2116 > 0) {
                    this->unk14 -= 1;
                }
                goto loop_22;
            }
        } else {
            RemoveAllSubgoals();
        }
        AddSubgoal((Goal<SwampTier2> *) this->unk28);
    }
}

void SwampTier2Goal_Think::AddGoal_Hit(EnemyDamageFeedback *arg0) {
    Enemy *temp_r3_2331;
    Enemy *temp_r4_2390;
    f32 var_f31_2150;
    s32 temp_r0_2299;
    s32 temp_r0_2368;
    s32 temp_r3_2296;
    s32 temp_r3_2369;
    s32 var_r25_2147;
    u32 temp_r0_2311;
    u8 temp_r20_2167;
    u8 temp_r21_2174;
    u8 temp_r22_2181;
    u8 temp_r26_2153;
    u8 temp_r27_2188;
    u8 temp_r28_2195;
    u8 temp_r29_2202;
    u8 temp_r30_2209;
    u8 temp_r31_2160;
    u8 temp_r31_2217;
    void *temp_r3_2274;

    var_r25_2147 = arg0->unk28;
    var_f31_2150 = 0.0f;
    temp_r26_2153 = IsActive(8);
    temp_r31_2160 = IsActive(0xB);
    temp_r20_2167 = IsActive(0xE);
    temp_r21_2174 = IsActive(0xC);
    temp_r22_2181 = IsActive(0x13);
    temp_r27_2188 = IsActive(0x12);
    temp_r28_2195 = IsActive(0xD);
    temp_r29_2202 = IsActive(0x26);
    temp_r30_2209 = IsActive(0x3B);
    temp_r31_2217 = IsActive(6);
    if ((temp_r31_2160 != 0) || (temp_r22_2181 != 0)) {
        switch (var_r25_2147) {                     /* switch 1 */
        case 4:                                     /* switch 1 */
        case 5:                                     /* switch 1 */
        case 7:                                     /* switch 1 */
        case 9:                                     /* switch 1 */
        case 11:                                    /* switch 1 */
            if (var_r25_2147 != 0xB) {
                this->unkC->ThawIfFrozen();
            }
            var_r25_2147 = 9;
            break;
        case 10:                                    /* switch 1 */
            var_f31_2150 = 3000.0f;
            break;
        default:                                    /* switch 1 */
            var_f31_2150 = 500.0f;
            var_r25_2147 = 3;
            break;
        }
    } else if (((temp_r21_2174 != 0) || (temp_r20_2167 != 0)) && (((u32) (var_r25_2147 - 4) <= 1U) || (var_r25_2147 == 2))) {
        var_r25_2147 = 0xE;
    } else {
        switch (var_r25_2147) {                     /* switch 2; irregular */
        case 3:                                     /* switch 2 */
        case 9:                                     /* switch 2 */
            var_r25_2147 = 1;
            break;
        case 10:                                    /* switch 2 */
            var_r25_2147 = 8;
            break;
        }
    }
    temp_r3_2274 = this->unkC->unkA00;
    if ((((temp_r3_2274 != NULL) && ((u8) M2C_FIELD(temp_r3_2274, u8 *, 0x20) != 0)) || (temp_r31_2217 != 0)) && ((temp_r31_2217 != 0) || (arg0->unk20 & 0x47F1))) {
        RemoveAllSubgoals();
    }
    if (var_r25_2147 == 9) {
        temp_r3_2296 = this->unkC->unkAF4;
        if ((temp_r3_2296 >= 3) && (((temp_r0_2299 = arg0->unk28, ((temp_r0_2299 == 4) == 0)) && (temp_r0_2299 != 5)) || (temp_r3_2296 >= 6))) {
            var_r25_2147 = 0xE;
        }
    }
    temp_r0_2311 = ((u8) arg0->unk34 >> 4U) & 1;
    if ((temp_r0_2311 != 0) && (this->unkC->unkACC <= 0.0f) && ((var_r25_2147 == 0) || (var_r25_2147 == 4) || (var_r25_2147 == 5))) {
        var_r25_2147 = 7;
    } else if (temp_r0_2311 != 0) {
        temp_r3_2331 = this->unkC;
        if (temp_r3_2331->unkACC <= 0.0f) {
            temp_r3_2331->Armour_Destroy();
        }
    }
    if (var_r25_2147 != 0xE) {
        if (IsActive(0x59) != 0) {
            if ((var_r25_2147 != 0) && ((var_r25_2147 != 1) || (temp_r26_2153 != 0)) && (temp_r27_2188 == 0)) {
                if (temp_r28_2195 != 0) {
                    return;
                }
                if ((s32) this->unk14 > 0) {
                    this->unk18 += 1;
                    temp_r0_2368 = this->unk18;
                    temp_r3_2369 = this->unk10;
                    if (temp_r0_2368 >= temp_r3_2369) {
                        this->unk18 = temp_r0_2368 - temp_r3_2369;
                    }
                    this->unk14 -= 1;
                }
                goto block_52;
            }
        } else {
block_52:
            if ((temp_r29_2202 != 0) || (temp_r30_2209 != 0)) {
                RemoveAllSubgoals();
            }
            arg0->unk28 = var_r25_2147;
            arg0->unk18 = var_f31_2150;
            temp_r4_2390 = this->unkC;
            temp_r4_2390->unk910 = arg0->unk0;
            M2C_FIELD(temp_r4_2390, f64 *, 0x918) = (f64) arg0->unk8;
            temp_r4_2390->unk920 = arg0->unk10;
            temp_r4_2390->unk924 = arg0->unk14;
            temp_r4_2390->unk928 = arg0->unk18;
            temp_r4_2390->unk92C = arg0->unk1C;
            temp_r4_2390->unk930 = arg0->unk20;
            temp_r4_2390->unk934 = arg0->unk24;
            temp_r4_2390->unk938 = arg0->unk28;
            temp_r4_2390->unk93C = arg0->unk2C;
            temp_r4_2390->unk940 = arg0->unk30;
            temp_r4_2390->unk944 = arg0->unk34;
            AddSubgoalToFront((Goal<SwampTier2> *) this->unk24);
        }
    }
}

#if 0 // DRAFT: undefined identifier '__vptr'
void SwampTier2Goal_Think::Arbitrate() {
    EnemyDamageFeedback sp8;
    Enemy *temp_r3_2449;
    Enemy *temp_r3_2536;
    Enemy *temp_r3_2580;
    Enemy *temp_r3_2588;
    Enemy *temp_r3_2603;
    Enemy *temp_r3_2625;
    Enemy *temp_r4_2436;
    Enemy *temp_r4_2551;
    Enemy *temp_r4_2613;
    Enemy *temp_r5_2483;
    Enemy *temp_r5_2639;
    Goal<SwampTier2> *temp_r5_2653;
    Goal<SwampTier2> *temp_r6_2479;
    f32 var_f31_2556;
    u8 temp_r3_2445;
    u8 var_r30_2563;

    temp_r4_2436 = this->unkC;
    if (!(((u8) temp_r4_2436->unkB09 >> 7U) & 1)) {
        AddGoal_Respawn();
        return;
    }
    temp_r3_2445 = temp_r4_2436->IsInvulnerable();
    if (temp_r3_2445 != 0) {
        temp_r3_2449 = this->unkC;
        temp_r3_2449->unk9D8 = 0;
        temp_r3_2449->unk9D4 = 0;
    }
    if ((this->unkC->WasHit() != 0) && (temp_r3_2445 == 0)) {
        if (IsActive(0x79) != 0) {
            M2C_FIELD(this->unkC, f32 *, 0xB1C) = (f32) (M2C_FIELD(&gb, f32 *, 0x30C) + 2.0f);
            temp_r6_2479 = this->unk30;
            M2C_FIELD(temp_r6_2479, u8 *, 0x10) = (u8) (M2C_FIELD(temp_r6_2479, u8 *, 0x10) | 0x80);
            temp_r5_2483 = this->unkC;
            temp_r5_2483->unk9D8 = 0;
            temp_r5_2483->unk9D4 = 0;
            AddGoal_AlertMode(1U);
            goto block_16;
        }
        sp8.Init();
        this->unkC->TakeDamage(&sp8, 0U);
        if (this->unkC->unkAC8 <= 0.0f) {
            if (IsFollowingSpawnGraph() != 0) {
                StopFollowingSpawnGraph();
            }
            AddGoal_Death(&sp8);
            return;
        }
        if (sp8.unk28 != 0xE) {
            if (IsFollowingSpawnGraph() != 0) {
                StopFollowingSpawnGraph();
            }
            AddGoal_Hit(&sp8);
            return;
        }
        goto block_16;
    }
block_16:
    if (IsFollowingSpawnGraph() != 0) {
        AddGoal_FollowSpawnGraph();
        return;
    }
    temp_r3_2536 = this->unkC;
    if ((temp_r3_2536->unkAC8 > 0.0f) && (M2C_FIELD(temp_r3_2536->__vptr, u8 (**)(), 0x134)() == 0) && (this->unkC->IsFlinching(), (((u8) M2C_ERROR(/* Read from unset register $r3 */) == 0) != 0))) {
        temp_r4_2551 = this->unkC;
        if (((u8) temp_r4_2551->unkB08 >> 6U) & 1) {
            var_f31_2556 = temp_r4_2551->unkA38->unk134;
        } else {
            var_f31_2556 = temp_r4_2551->unkA38->unk12C;
        }
        var_r30_2563 = 0;
        if (((u8) M2C_FIELD(temp_r4_2551, u8 *, 0x8B8) == 2) || (temp_r4_2551->unk870.unk40.Get() != NULL)) {
            var_r30_2563 = 1;
        }
        if ((var_r30_2563 != 0) && (this->unkC->unk870.IsAttackable() != 0) && ((temp_r3_2580 = this->unkC, (((((u8) temp_r3_2580->unkB08 >> 5U) & 1) == 0) == 0)) || ((temp_r3_2580->unk870.GetDist() < var_f31_2556) && ((temp_r3_2588 = this->unkC, (((((u8) temp_r3_2588->unkB08 >> 6U) & 1) == 0) == 0)) || (((u8) M2C_FIELD(temp_r3_2588, u8 *, 0x8B9) >> 4U) & 1) || (temp_r3_2588->unk870.GetDist() < this->unkC->unkA38->unk130)))) && (temp_r3_2603 = this->unkC, ((temp_r3_2603->IsTargetBehindWall() == 0) != 0))) {
            temp_r4_2613 = this->unkC;
            if ((this->unkC->unk870.GetDist() < temp_r4_2613->unkA38->unk130) || (temp_r4_2613->unk870.GetDist() < (0.5f * var_f31_2556))) {
                temp_r3_2625 = this->unkC;
                temp_r3_2625->unkB08 |= 0x40;
            }
            if (IsActive(0x79) != 0) {
                temp_r5_2639 = this->unkC;
                if (M2C_FIELD(&gb, f32 *, 0x30C) >= M2C_FIELD(temp_r5_2639, f32 *, 0xB1C)) {
                    M2C_FIELD(temp_r5_2639, f32 *, 0xB1C) = (f32) (M2C_FIELD(&gb, f32 *, 0x30C) + 2.0f);
                    temp_r5_2653 = this->unk30;
                    M2C_FIELD(temp_r5_2653, u8 *, 0x10) = (u8) (M2C_FIELD(temp_r5_2653, u8 *, 0x10) | 0x80);
                    AddGoal_AlertMode(1U);
                }
            } else {
                AddGoal_AlertMode(0U);
            }
        } else if (M2C_FIELD(&gb, f32 *, 0x30C) >= M2C_FIELD(this->unkC, f32 *, 0xB1C)) {
            AddGoal_Hide();
        }
    }
}
#endif

void SwampTier2Goal_Think::Terminate() {
    this->unk8 = 1;
    RemoveAllSubgoals();
}

u8 SwampTier2Goal_Think::Update() {
    Enemy *temp_r3_2715;

    if (this->unkC->WasHit() != 0) {
        this->unk8 = 1;
    }
    temp_r3_2715 = this->unkC;
    if (temp_r3_2715->IsDead() == 0) {
        this->unkC->SelectTarget();
    }
    ActivateIfInactive();
    this->unk8 = UpdateSubgoals();
    if ((u8) this->unk8 != 0) {
        Activate();
    }
    return this->unk8;
}

void SwampTier2Goal_Think::Reset() {
    Enemy *temp_r5_2774;
    s32 var_r0_2765;

    this->unk8 = 1;
    RemoveAllSubgoals();
    if (MKRand_Float((int *) &gViewSeed, 0.0f, 1.0f) > 0.5f) {
        var_r0_2765 = 1;
    } else {
        var_r0_2765 = 0;
    }
    M2C_FIELD(this->unkC, s32 *, 0xB14) = var_r0_2765;
    temp_r5_2774 = this->unkC;
    M2C_FIELD(temp_r5_2774, s32 *, 0xB10) = (s32) (M2C_FIELD(temp_r5_2774, s32 *, 0xB14) != 0);
    M2C_FIELD(this->unkC, f32 *, 0xB1C) = 0.0f;
    M2C_FIELD(this->unkC, f32 *, 0xB20) = 0.0f;
    this->unk3C &= ~0x80;
}

void SwampTier2Goal_Think::Activate() {
    this->unk8 = 0;
    if ((u32) this->unkC->unkA80 != 0) {
        StartFollowingSpawnGraph();
    }
    Arbitrate();
}

void SwampTier2Goal_Think::Deinit() {
    Goal<SwampTier2> *temp_r3_2834;
    Goal<SwampTier2> *temp_r3_2839;
    Goal<SwampTier2> *temp_r3_2844;
    Goal<SwampTier2> *temp_r3_2849;
    Goal<SwampTier2> *temp_r3_2854;
    Goal<SwampTier2> *temp_r3_2859;
    void **temp_r3_2829;
    void *temp_r31_2878;

    temp_r3_2829 = this->unk20;
    M2C_FIELD(*temp_r3_2829, M2C_UNK (**)(void **), 0xC)(temp_r3_2829);
    temp_r3_2834 = this->unk28;
    temp_r3_2834->Deinit();
    temp_r3_2839 = this->unk2C;
    temp_r3_2839->Deinit();
    temp_r3_2844 = this->unk30;
    temp_r3_2844->Deinit();
    temp_r3_2849 = this->unk24;
    temp_r3_2849->Deinit();
    temp_r3_2854 = this->unk34;
    temp_r3_2854->Deinit();
    temp_r3_2859 = this->unk38;
    temp_r3_2859->Deinit();
    operator delete(this->unk20);
    operator delete(this->unk28);
    operator delete(this->unk2C);
    operator delete(this->unk30);
    operator delete(this->unk24);
    operator delete(this->unk34);
    operator delete(this->unk38);
    temp_r31_2878 = this->unk1C;
    if (temp_r31_2878 != NULL) {
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_2878, NULL, 0);
        } else {
            free(temp_r31_2878);
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
void SwampTier2Goal_Think::Init(SwampTier2 *arg0) {
    Goal<SwampTier2> *temp_r4_3137;
    void **temp_r4_3123;
    void *var_r3_3103;

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
        operator new(0x14U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__18Goal<10SwampTier2>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk30 = M2C_ERROR(/* Read from unset register $r3 */);
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
        operator new(0x44U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__18Goal<10SwampTier2>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__27CompositeGoal<10SwampTier2>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x1C) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x18) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x10) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x14) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk34 = M2C_ERROR(/* Read from unset register $r3 */);
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
        this->unk38 = M2C_ERROR(/* Read from unset register $r3 */);
    }
    if ((u8) this->unk9 == 0) {
        if (MKHeap::Current() != NULL) {
            var_r3_3103 = ((MKHeap *) (MKHeap::Current()))->Alloc(8, NULL, 0);
        } else {
            var_r3_3103 = malloc(8);
        }
        this->unk1C = var_r3_3103;
        this->unk10 = 2;
    }
    this->unk8 = 1;
    this->unkC = (Enemy *) arg0;
    this->unk4 = 0x78;
    if ((Enemy *) this->unkC != NULL) {
        this->unk9 = 1;
    }
    temp_r4_3123 = this->unk20;
    M2C_FIELD(temp_r4_3123, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_3123, SwampTier2 **, 0xC) = arg0;
    M2C_FIELD(temp_r4_3123, s32 *, 4) = 0;
    if ((SwampTier2 *) M2C_FIELD(temp_r4_3123, SwampTier2 **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_3123, s8 *, 9) = 1;
    }
    ((EnemyGoal_Death *) this->unk28)->Init((Enemy *) arg0);
    temp_r4_3137 = this->unk2C;
    M2C_FIELD(temp_r4_3137, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_3137, SwampTier2 **, 0xC) = arg0;
    M2C_FIELD(temp_r4_3137, s32 *, 4) = 0x1E;
    if ((SwampTier2 *) M2C_FIELD(temp_r4_3137, SwampTier2 **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_3137, s8 *, 9) = 1;
    }
    ((SwampTier2Goal_Hide *) this->unk30)->Init(arg0);
    ((EnemyGoal_Hit *) this->unk24)->Init((Enemy *) arg0);
    ((SwampTier2Goal_AlertMode *) this->unk34)->Init(arg0);
    ((EnemyGoal_FollowGraph *) this->unk38)->Init((Enemy *) arg0);
    this->unk3C &= ~0x80;
}
#endif
