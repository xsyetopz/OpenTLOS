#include "spyro/source/IceBossGoals.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKParticleSystem.h"
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
#include "spyro/source/Crate.h"
#include "spyro/source/EarthShockwave.h"
#include "spyro/source/ElementalShield.h"
#include "spyro/source/EmbersPS.h"
#include "spyro/source/Enemies_IceBoss.h"
#include "spyro/source/Enemy.h"
#include "spyro/source/EnemyAttackPattern.h"
#include "spyro/source/EnemyDataTypes.h"
#include "spyro/source/EnemyDescriptor.h"
#include "spyro/source/EnemyGoals_Death.h"
#include "spyro/source/EnemyGoals_Hit.h"
#include "spyro/source/EnemyRegion.h"
#include "spyro/source/EnemySettings.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/GlowingPropManager.h"
#include "spyro/source/Goal.h"
#include "spyro/source/IceBitsPS.h"
#include "spyro/source/IceBossStalactite.h"
#include "spyro/source/KDMatrixRefProperty.h"
#include "spyro/source/KDPath.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDProperty.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/KDSpline.h"
#include "spyro/source/Level.h"
#include "spyro/source/LightManager.h"
#include "spyro/source/ManagedLight.h"
#include "spyro/source/MeleeTrails.h"
#include "spyro/source/Names.h"
#include "spyro/source/NodeLookAt.h"
#include "spyro/source/SB2.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/SpawnPointObject.h"
#include "spyro/source/SpawnerObject.h"
#include "spyro/source/TargetManager.h"
#include "spyro/source/ZapArcFX.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "common/Source/StdMath.h"
#include "spyro/source/EventCamera.h"
#include "spyro/source/KDMath.h"
#include "spyro/source/KDRandom.h"
#include <m2c_macros.h>

M2C_UNK free(void *);                               /* extern */
void *malloc(M2C_UNK);                              /* extern */
extern s32 GS_ElecBossFlinch1;
extern s32 GS_IceBossFlinch1;
extern s32 GS_PLACEHOLDER;
extern s32 GS_SpyroMeleeHit;
extern s32 GS_SpyroZapBurn;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern void **gb;

static u8 lit_1598 = 1;

void IceBossGoal_MoveToTarget::Terminate() {
    SB2 *temp_r3_28;

    temp_r3_28 = this->unkC->unk640;
    temp_r3_28->unk464 &= ~0x80;
    this->unkC->unk640->SeekOff();
    this->unkC->unk640->ObstacleAvoidanceOff();
    this->unkC->unk640->ContainmentOff();
    this->unk8 = 1;
}

u8 IceBossGoal_MoveToTarget::Update() {
    Enemy *temp_r3_59;
    Enemy *temp_r3_73;
    u8 var_r31_60;

    ActivateIfInactive();
    temp_r3_59 = this->unkC;
    var_r31_60 = 0;
    if (((u8) M2C_FIELD(temp_r3_59, u8 *, 0x8B8) == 2) || (temp_r3_59->unk870.unk40.Get() != NULL)) {
        var_r31_60 = 1;
    }
    if ((var_r31_60 == 0) || (temp_r3_73 = this->unkC, (((((u8) M2C_FIELD(temp_r3_73, u8 *, 0x8B9) >> 6U) & 1) == 0) != 0)) || (temp_r3_73->unk870.GetDist() < 500.0f) || (M2C_FIELD(&gb, f32 *, 0x30C) >= this->unk10)) {
        this->unk8 = 2;
    }
    return this->unk8;
}

void IceBossGoal_MoveToTarget::Activate() {
    Enemy *temp_r3_140;
    Enemy *temp_r4_160;
    SB2 *temp_r3_156;
    u8 var_r31_141;

    this->unk8 = 0;
    this->unkC->SetWalkMovementSpeed(1U);
    ((Character *) this->unkC)->SetMovementType((CharacterMoveType) 0);
    if (((IceBoss *) this->unkC)->GetPhase() == 2) {
        this->unkC->SetAnim((AnimSequenceType) 5, 0x12, 0, 0.15f, 0U, 0U);
    } else {
        this->unkC->SetAnim((AnimSequenceType) 5, 0, 0, 0.15f, 0U, 0U);
    }
    temp_r3_140 = this->unkC;
    var_r31_141 = 0;
    if (((u8) M2C_FIELD(temp_r3_140, u8 *, 0x8B8) == 2) || (temp_r3_140->unk870.unk40.Get() != NULL)) {
        var_r31_141 = 1;
    }
    if (var_r31_141 != 0) {
        temp_r3_156 = this->unkC->unk640;
        temp_r3_156->unk464 |= 0x80;
        temp_r4_160 = this->unkC;
        temp_r4_160->unk640->SeekOn(&temp_r4_160->unk870);
        this->unkC->unk640->ObstacleAvoidanceOn(NULL);
        this->unkC->unk640->ContainmentOn();
    }
    this->unk10 = M2C_FIELD(&gb, f32 *, 0x30C) + 10.0f;
}

#if 0 // DRAFT: undefined identifier 'sp30'
void IceBossGoal_MoveToPoint::SelectMoveAnimSequence() {
    f64 sp40;
    f64 sp38;
    f32 sp28;
    f32 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    Enemy *temp_r5_198;
    Enemy *temp_r5_220;
    f32 temp_f1_243;
    f32 temp_f2_205;
    f32 temp_f31_231;
    f32 temp_f3_202;
    f32 temp_f4_206;
    f32 temp_f5_201;
    f32 temp_f6_200;
    f32 temp_f7_203;

    temp_r5_198 = this->unkC;
    temp_f6_200 = temp_r5_198->unkD4;
    temp_f5_201 = temp_r5_198->unkC0;
    temp_f3_202 = temp_r5_198->unkC8;
    temp_f7_203 = temp_r5_198->unkD0;
    temp_f2_205 = temp_r5_198->unkC4;
    temp_f4_206 = temp_r5_198->unkD8;
    sp10 = (temp_f7_203 * temp_f2_205) - (temp_f6_200 * temp_f5_201);
    spC = (temp_f4_206 * temp_f5_201) - (temp_f7_203 * temp_f3_202);
    sp8 = (temp_f6_200 * temp_f3_202) - (temp_f4_206 * temp_f2_205);
    sp40 = (f64) sp10;
    sp38 = (f64) sp8;
    ((AITargetData *) &sp28)->GetDir();
    temp_r5_220 = this->unkC;
    temp_f31_231 = (temp_r5_220->unkC8 * sp30) + ((temp_r5_220->unkC0 * sp28) + (temp_r5_220->unkC4 * sp2C));
    ((AITargetData *) &sp18)->GetDir();
    temp_f1_243 = _table_sinf(2.0943952f);
    if (temp_f31_231 > temp_f1_243) {
        this->unkC->unkA38->GetAnimSequence(5, 0, 0, NULL);
        return;
    }
    if (temp_f31_231 < -temp_f1_243) {
        this->unkC->unkA38->GetAnimSequence(5, 0xF, 0, NULL);
        return;
    }
    if ((((f32) sp40 * sp20) + (((f32) sp38 * sp18) + ((*(f32 *) ((u8 *) &sp38 + 0x4)) * sp1C))) > 0.0f) {
        this->unkC->unkA38->GetAnimSequence(7, 0x1A, 0, NULL);
        return;
    }
    this->unkC->unkA38->GetAnimSequence(7, 0x19, 0, NULL);
}
#endif

void IceBossGoal_MoveToPoint::Reset() {
    this->unk8 = 1;
    this->unk10.Set(NULL, 0U);
    this->unk60 = 0.0f;
}

void IceBossGoal_MoveToPoint::Terminate() {
    this->unk8 = 1;
}

#if 0 // DRAFT: undefined identifier 'sp10'
u8 IceBossGoal_MoveToPoint::Update() {
    f64 sp8;
    AnimSequence *temp_r4_396;
    Enemy *temp_r3_342;
    Enemy *temp_r4_360;
    Enemy *temp_r5_395;
    u8 var_r30_343;
    u8 var_r3_377;
    u8 var_r4_371;
    void *temp_r5_372;

    ActivateIfInactive();
    this->unk10.Update(this->unkC->unk588);
    temp_r3_342 = this->unkC;
    var_r30_343 = 0;
    if (((u8) M2C_FIELD(temp_r3_342, u8 *, 0x8B8) == 2) || (temp_r3_342->unk870.unk40.Get() != NULL)) {
        var_r30_343 = 1;
    }
    if (var_r30_343 != 0) {
        ((AITargetData *) &sp8)->GetDir();
        temp_r4_360 = this->unkC;
        M2C_FIELD(temp_r4_360, f64 *, 0xE0) = sp8;
        M2C_FIELD(temp_r4_360, f64 *, 0xE8) = sp10;
        temp_r4_360->unk6B5 |= 0x40;
    }
    var_r4_371 = 0;
    temp_r5_372 = this->unkC->unk630;
    if (((u32) M2C_FIELD(temp_r5_372, u32 *, 0x2C) >> 1U) & 1) {
        var_r3_377 = 0;
        if ((M2C_FIELD(temp_r5_372, f32 *, 0x38) > 0.0f) || ((s32) M2C_FIELD(temp_r5_372, s32 *, 0x44) > 1)) {
            var_r3_377 = 1;
        }
        if (var_r3_377 != 0) {
            var_r4_371 = 1;
        }
    }
    if (var_r4_371 != 0) {
        SelectMoveAnimSequence();
        temp_r5_395 = this->unkC;
        temp_r4_396 = M2C_ERROR(/* Read from unset register $r3 */);
        if (temp_r4_396 != (AnimSequence *) temp_r5_395->unkA50) {
            temp_r5_395->SetAnim(temp_r4_396, (AnimTransition *) temp_r4_396, 0.15f, 0U);
        }
    }
    if ((this->unk10.GetDist() < 300.0f) || (M2C_FIELD(&gb, f32 *, 0x30C) >= this->unk60)) {
        this->unk8 = 2;
    }
    return this->unk8;
}
#endif

void IceBossGoal_MoveToPoint::Activate() {
    AnimSequence *temp_r0_452;

    this->unk8 = 0;
    this->unkC->SetWalkMovementSpeed(1U);
    ((Character *) this->unkC)->SetMovementType((CharacterMoveType) 0);
    this->unk10.Update(this->unkC->unk588);
    SelectMoveAnimSequence();
    temp_r0_452 = M2C_ERROR(/* Read from unset register $r3 */);
    this->unkC->SetAnim(temp_r0_452, (AnimTransition *) temp_r0_452, 0.15f, 0U);
    this->unk60 = M2C_FIELD(&gb, f32 *, 0x30C) + 5.0f;
}

#if 0 // DRAFT: ')' expected
void IceBossGoal_IceBreath::Terminate() {
    Enemy *temp_r4_482;
    ManagedLight *temp_r4_510;

    temp_r4_482 = this->unkC;
    temp_r4_482->unkB08 &= ~0x10;
    M2C_FIELD(this->unkC, s8 *, 0xB20) = 1;
    M2C_FIELD(this->unkC, f32 *, 0xFD0) = (f32) (M2C_FIELD(&gb, f32 *, 0x30C) + M2C_FIELD(checked_cast<IceBossDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unkC->unk0), f32 *, 0x2C4));
    this->unkC->unkA20 = NULL;
    this->unkC->SetInvulnerableToMeleeAttacks(0U, 1U);
    this->unkC->SetInvulnerableToBreathAttacks(0U, 1U);
    temp_r4_510 = M2C_FIELD(this->unkC, ManagedLight **, 0xFFC);
    if (temp_r4_510 != NULL) {
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->EnableLight(temp_r4_510, 0U);
    }
    this->unk8 = 1;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void' to 'double'
u8 IceBossGoal_IceBreath::Update() {
    MKCollisionResult sp300;
    Matrix sp2C0;
    f32 sp2A0;
    M2C_UNK sp27C;
    f64 sp270;
    f64 sp268;
    f64 sp260;
    f64 sp258;
    f64 sp250;
    f64 sp248;
    f64 sp240;
    f64 sp238;
    f64 sp230;
    f64 sp228;
    f64 sp220;
    f64 sp218;
    f64 sp210;
    f64 sp208;
    f64 sp200;
    f64 sp1F8;
    f64 sp1F0;
    f64 sp1E8;
    f64 sp1E0;
    f64 sp1D8;
    f64 sp1D0;
    f64 sp1C8;
    MKVector3 sp1B8;
    f64 sp1B0;
    f64 sp1A8;
    f64 sp1A0;
    f64 sp198;
    f64 sp190;
    f64 sp188;
    f64 sp180;
    f64 sp178;
    f64 sp170;
    f64 sp168;
    MKVector3 sp158;
    f64 sp150;
    f64 sp148;
    f64 sp138;
    f64 sp130;
    f64 sp128;
    f64 sp120;
    f64 sp118;
    f32 sp110;
    f32 sp10C;
    f32 sp108;
    f32 sp100;
    f64 spF8;
    f32 spF0;
    f32 spEC;
    f32 spE8;
    f32 spE0;
    f64 spD8;
    f32 spD0;
    f64 spC8;
    f32 spC4;
    f32 spC0;
    f32 spBC;
    f32 spB8;
    f32 spB0;
    f32 spAC;
    f32 spA8;
    f32 spA0;
    f32 sp9C;
    f32 sp98;
    f32 sp90;
    f64 sp88;
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    f32 sp70;
    f64 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp14;
    f32 sp10;
    Enemy *temp_r3_1005;
    Enemy *temp_r3_1041;
    Enemy *temp_r3_1062;
    Enemy *temp_r3_717;
    Enemy *temp_r3_848;
    Enemy *temp_r5_589;
    MKProp *var_r29_991;
    Matrix *temp_r29_592;
    f32 temp_f0_832;
    f32 temp_f1_691;
    f32 temp_f26_637;
    f32 temp_f27_642;
    f32 temp_f31_620;
    f64 temp_f0_656;
    f64 temp_f0_667;
    f64 temp_f0_679;
    f64 temp_f0_761;
    s32 temp_r0_565;
    s32 temp_r0_906;
    s32 temp_r3_556;
    s32 temp_r3_566;
    s32 temp_r3_907;
    s32 temp_r4_578;
    s32 var_r0_579;
    s32 var_r28_613;
    u32 *var_r4_1006;
    u32 temp_r0_1015;
    u8 var_r30_849;
    void *temp_r3_811;
    void *temp_r3_818;
    void *temp_r3_833;
    void *temp_r3_835;
    void *var_r3_885;

    ActivateIfInactive();
    if (((u8) this->unkC->unkB08 >> 4U) & 1) {
        temp_r3_556 = this->unk14;
        if ((temp_r3_556 == (s32) this->unk10) && (temp_r3_556 > 0)) {
            this->unk18 += 1;
            temp_r0_565 = this->unk18;
            temp_r3_566 = this->unk10;
            if (temp_r0_565 >= temp_r3_566) {
                this->unk18 = temp_r0_565 - temp_r3_566;
            }
            this->unk14 -= 1;
        }
        temp_r4_578 = this->unk10;
        var_r0_579 = this->unk18 + this->unk14;
        if (var_r0_579 >= temp_r4_578) {
            var_r0_579 -= temp_r4_578;
        }
        this->unk14 += 1;
        temp_r5_589 = this->unkC;
        temp_r29_592 = (Matrix *) (((u8 *) this->unk1C) + (var_r0_579 << 6));
        MKModel_GetRefPointMatrix(temp_r5_589->unk4, (s32) temp_r5_589->unkA38->unk284, temp_r29_592, 1U);
        if (((IceBoss *) this->unkC)->IsIceKing() != 0) {
            this->unkC->unkA0C->EmitConeBreathFx(3, 4000.0f, 0.5f, 1.5f, 0.0f, 0.5235987f);
            var_r28_613 = 0;
            do {
                temp_f31_620 = MKRand_Float((int *) &gViewSeed, 0.1f, 1.0f);
                spE8 = -temp_r29_592->unk20;
                spEC = -temp_r29_592->unk24;
                spF0 = -temp_r29_592->unk28;
                sp1E8 = (f64) spE8;
                sp1F0 = (f64) spF0;
                temp_f26_637 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
                temp_f27_642 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
                sp108 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
                sp10C = temp_f27_642;
                sp110 = temp_f26_637;
                sp1F8 = (f64) sp108;
                sp200 = (f64) sp110;
                temp_f0_656 = sp1F8 * 5.222099017e-315;
                spF8 = temp_f0_656;
                sp208 = temp_f0_656;
                sp100 = (f32) sp200 * 0.5f;
                sp210 = (f64) sp100;
                temp_f0_667 = sp208 + sp1E8;
                spD8 = temp_f0_667;
                sp218 = temp_f0_667;
                spE0 = (f32) sp210 + (f32) sp1F0;
                sp220 = (f64) spE0;
                temp_f0_679 = temp_f0_667 * 5.717903774e-315;
                spC8 = temp_f0_679;
                sp228 = temp_f0_679;
                spD0 = (f32) sp220 * 2010.0f;
                sp230 = (f64) spD0;
                temp_f1_691 = MKRand_Float((int *) &gViewSeed, 7.1f, 15.0f);
                spB8 = temp_f31_620;
                spBC = temp_f31_620;
                sp14 = temp_f1_691;
                spC0 = 1.0f;
                spC4 = 1.0f;
                sp1D8 = (f64) spB8;
                sp1E0 = (f64) spC0;
                ((EmbersPS *) (M2C_FIELD(&gb, EmbersPS **, 0x74)))->Emit(*((MKVector3 *) &temp_r29_592->unk30), *((MKVector3 *) &sp228), sp14, *((MKVector4 *) &sp1D8), 0.0f);
                var_r28_613 += 1;
            } while (var_r28_613 < 3);
        } else if (((IceBoss *) this->unkC)->IsIceKing() == 0) {
            temp_r3_717 = this->unkC;
            MKModel_GetRefPointMatrix(temp_r3_717->unk4, *temp_r3_717->unkA0C->unk0, &sp2C0, 1U);
            spB0 = -1.0f;
            sp80 = -sp2C0.unk28;
            spA0 = 1.0f;
            sp78 = -sp2C0.unk20;
            sp7C = -sp2C0.unk24;
            spA8 = -1.0f;
            spAC = -1.0f;
            sp98 = 1.0f;
            sp9C = 1.0f;
            sp188 = (f64) sp78;
            sp190 = (f64) sp80;
            sp1A8 = (f64) spA8;
            sp1B0 = (f64) spB0;
            sp198 = (f64) sp98;
            sp1A0 = (f64) spA0;
            KDRand_Vector(sp1B8, *((MKVector3 *) &sp1A8));
            temp_f0_761 = sp1B8 * 5.222099017e-315;
            sp88 = temp_f0_761;
            sp1C8 = temp_f0_761;
            sp90 = sp1B8.unk8 * 0.5f;
            sp1D0 = (f64) sp90;
            sp68 = sp1C8 + sp188;
            sp58 = 1.0f;
            sp5C = 0.0f;
            sp70 = (f32) sp1D0 + (f32) sp190;
            sp60 = 0.5f;
            sp64 = 1.0f;
            sp268 = sp68;
            sp270 = (f64) sp70;
            sp178 = (f64) sp58;
            sp180 = (f64) sp60;
            sp10 = MKRand_Float((int *) &gViewSeed, 2.0f, 3.0f);
            ((ZapArcFX *) (M2C_FIELD(&gb, ZapArcFX **, 0x94)))->Trigger(*((MKVector3 *) &sp2C0.unk30), *((MKVector3 *) &sp268), sp10, lit_1598, (MKVector4) &sp178);
            M2C_FIELD(this->unkC, s8 *, 0x1064) = 1;
        }
        temp_r3_811 = M2C_FIELD(this->unkC, void **, 0xFFC);
        if (temp_r3_811 != NULL) {
            M2C_FIELD(temp_r3_811, f64 *, 0x10) = (f64) M2C_FIELD(temp_r29_592, f64 *, 0x30);
            M2C_FIELD(temp_r3_811, f64 *, 0x18) = (f64) M2C_FIELD(temp_r29_592, f64 *, 0x38);
            temp_r3_818 = M2C_FIELD(temp_r3_811, void **, 0x3C);
            if (temp_r3_818 != NULL) {
                M2C_FIELD(temp_r3_818, f64 *, 0x10) = (f64) M2C_FIELD(temp_r29_592, f64 *, 0x30);
                M2C_FIELD(temp_r3_818, f64 *, 0x18) = (f64) M2C_FIELD(temp_r29_592, f64 *, 0x38);
            }
            temp_f0_832 = 100.0f * MKRand_Float((int *) &gViewSeed, 10.0f, 15.0f);
            temp_r3_833 = M2C_FIELD(this->unkC, void **, 0xFFC);
            M2C_FIELD(temp_r3_833, f32 *, 0x38) = temp_f0_832;
            temp_r3_835 = M2C_FIELD(temp_r3_833, void **, 0x3C);
            if (temp_r3_835 != NULL) {
                M2C_FIELD(temp_r3_835, f32 *, 0x20) = temp_f0_832;
                M2C_FIELD(temp_r3_835, f32 *, 0x24) = (f32) (temp_f0_832 * temp_f0_832);
                M2C_FIELD(temp_r3_835, f32 *, 0x28) = (f32) (1.0f / temp_f0_832);
                M2C_FIELD(temp_r3_835, f32 *, 0x2C) = (f32) (1.0f / M2C_FIELD(temp_r3_835, f32 *, 0x24));
            }
        }
    }
    temp_r3_848 = this->unkC;
    var_r30_849 = 0;
    if (((u8) M2C_FIELD(temp_r3_848, u8 *, 0x8B8) == 2) || (temp_r3_848->unk870.unk40.Get() != NULL)) {
        var_r30_849 = 1;
    }
    if (((var_r30_849 != 0) && (((u8) this->unkC->unkB08 >> 4U) & 1) && ((s32) this->unk14 >= (s32) this->unk10)) || (!(((u8) this->unkC->unkB08 >> 4U) & 1) && ((s32) this->unk14 != 0))) {
        if ((s32) this->unk14 > 0) {
            var_r3_885 = ((u8 *) this->unk1C) + (this->unk18 << 6);
        } else {
            var_r3_885 = NULL;
        }
        M2C_STRUCT_COPY((s32) &sp27C + 4, (s32) (((u8 *) var_r3_885) - 4) + 4, 0x40);
        if ((s32) this->unk14 > 0) {
            this->unk18 += 1;
            temp_r0_906 = this->unk18;
            temp_r3_907 = this->unk10;
            if (temp_r0_906 >= temp_r3_907) {
                this->unk18 = temp_r0_906 - temp_r3_907;
            }
            this->unk14 -= 1;
        }
        sp258 = sp2B0;
        sp260 = sp2B8;
        sp158.operator*(-1000.0f);
        sp28 = sp258 + M2C_BITWISE(f64, sp158);
        sp168 = sp28;
        sp30 = (f32) sp260 + sp158.unk8;
        sp248 = sp28;
        sp170 = (f64) sp30;
        sp250 = (f64) sp30;
        MKVector(0.0f, 200.0f, 0.0f);
        sp18 = sp248 - sp138;
        sp238 = sp18;
        sp20 = (f32) sp250 - sp140;
        sp148 = sp18;
        sp240 = (f64) sp20;
        sp150 = (f64) sp20;
        if ((MKCollision_SweepSphereCollide(*((MKVector3 *) &sp258), *((MKVector3 *) &sp248), 150.0f, &sp300, (MKCollisionMode) 2, M2C_FIELD(this->unkC->unk110.unk460, s32 *, 0x18) | 0x08000000 | 8) != 0) || (MKCollision_SweepSphereCollide(*((MKVector3 *) &sp258), *((MKVector3 *) &sp238), 150.0f, &sp300, (MKCollisionMode) 2, M2C_FIELD(this->unkC->unk110.unk460, s32 *, 0x18) | 0x08000000 | 8) != 0)) {
            if ((sp300.unk50 != 0) && (sp300.unk48 != NULL) && (var_r29_991 = M2C_FIELD(sp300.unk48, MKProp **, 8), ((var_r29_991 == NULL) == 0))) {

            } else {
                var_r29_991 = NULL;
            }
            if ((var_r29_991 != NULL) && (var_r29_991 == this->unkC->unk870.GetProp())) {
                temp_r3_1005 = this->unkC;
                var_r4_1006 = temp_r3_1005->unkA1C;
loop_47:
                temp_r0_1015 = *var_r4_1006;
                if (temp_r0_1015 == 0) {
                    var_r4_1006 = NULL;
                } else if (temp_r0_1015 == var_r29_991) {

                } else {
                    var_r4_1006 += 4;
                    goto loop_47;
                }
                if (var_r4_1006 == NULL) {
                    if (((IceBoss *) temp_r3_1005)->IsIceKing() == 0) {
                        sp48 = -sp2A0;
                        sp4C = -sp2A4;
                        sp50 = -sp2A8;
                        sp128 = (f64) sp48;
                        sp130 = (f64) sp50;
                        temp_r3_1041 = this->unkC;
                        temp_r3_1041->MeleeDamageTarget(var_r29_991, temp_r3_1041->unkA20, *((MKVector3 *) &sp128), GS_SpyroZapBurn);
                    } else {
                        sp38 = -sp2A0;
                        sp3C = -sp2A4;
                        sp40 = -sp2A8;
                        sp118 = (f64) sp38;
                        sp120 = (f64) sp40;
                        temp_r3_1062 = this->unkC;
                        temp_r3_1062->MeleeDamageTarget(var_r29_991, temp_r3_1062->unkA20, *((MKVector3 *) &sp118), GS_PLACEHOLDER);
                    }
                    this->unkC->SetHitTarget(1U);
                }
            }
        }
    }
    if (((Character *) this->unkC)->HasAnimFinished() != 0) {
        if (((u8) this->unkC->unkB08 >> 1U) & 1) {
            this->unk8 = 2;
        } else {
            this->unk8 = 3;
        }
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: undefined identifier 'MKVector'
void IceBossGoal_IceBreath::Activate() {
    f64 sp40;
    f64 sp38;
    f64 sp28;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    AnimSequence *temp_r4_1129;
    Enemy *temp_r3_1125;
    Enemy *temp_r4_1133;
    ManagedLight *temp_r3_1172;
    ManagedLight *temp_r3_1205;
    ManagedLight *temp_r4_1162;
    void *temp_r3_1174;
    void *temp_r3_1211;

    this->unk8 = 0;
    ((Character *) this->unkC)->StopMovement(1U);
    if (this->unkC->SelectAttack(0x10, 0x98) != 0) {
        temp_r3_1125 = this->unkC;
        temp_r4_1129 = temp_r3_1125->unkA20->unk0;
        temp_r3_1125->SetAnim(temp_r4_1129, (AnimTransition *) temp_r4_1129, 0.15f, 0U);
    }
    temp_r4_1133 = this->unkC;
loop_4:
    if ((u32) *temp_r4_1133->unkA1C != 0) {
        temp_r4_1133->unkA1C += 4;
        goto loop_4;
    }
    M2C_FIELD(this->unkC, f32 *, 0xFD0) = 0.0f;
    M2C_FIELD(this->unkC, s8 *, 0xB20) = 0;
    this->unkC->SetInvulnerableToMeleeAttacks(1U, 1U);
    this->unkC->SetInvulnerableToBreathAttacks(1U, 1U);
    this->unk18 = 0;
    this->unk14 = 0;
    temp_r4_1162 = M2C_FIELD(this->unkC, ManagedLight **, 0xFFC);
    if (temp_r4_1162 != NULL) {
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->EnableLight(temp_r4_1162, 1U);
        temp_r3_1172 = M2C_FIELD(this->unkC, ManagedLight **, 0xFFC);
        temp_r3_1172->unk38 = 1000.0f;
        temp_r3_1174 = temp_r3_1172->unk3C;
        if (temp_r3_1174 != NULL) {
            M2C_FIELD(temp_r3_1174, f32 *, 0x20) = 1000.0f;
            M2C_FIELD(temp_r3_1174, f32 *, 0x24) = 1000000.0f;
            M2C_FIELD(temp_r3_1174, f32 *, 0x28) = 0.001f;
            M2C_FIELD(temp_r3_1174, f32 *, 0x2C) = (f32) (1.0f / M2C_FIELD(temp_r3_1174, f32 *, 0x24));
        }
        MKVector(0.0f, 1000.0f, 0.0f);
        ((MKProp *) &sp28)->GetPos();
        sp8 = sp28 + sp18;
        temp_r3_1205 = M2C_FIELD(this->unkC, ManagedLight **, 0xFFC);
        sp38 = sp8;
        sp10 = sp30 + sp20;
        temp_r3_1205->unk10 = sp8;
        temp_r3_1205->unk18 = (f64) sp10;
        temp_r3_1211 = temp_r3_1205->unk3C;
        sp40 = (f64) sp10;
        if (temp_r3_1211 != NULL) {
            M2C_FIELD(temp_r3_1211, f64 *, 0x10) = sp8;
            M2C_FIELD(temp_r3_1211, f64 *, 0x18) = (f64) sp10;
        }
    }
}
#endif

void IceBossGoal_IceBreath::Deinit() {
    void *temp_r31_1238;

    this->unk8 = 1;
    this->unkC = NULL;
    this->unk9 = 0;
    temp_r31_1238 = this->unk1C;
    if (temp_r31_1238 != NULL) {
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_1238, NULL, 0);
        } else {
            free(temp_r31_1238);
        }
        this->unk1C = NULL;
    }
    this->unk10 = 0;
    this->unk18 = 0;
    this->unk14 = 0;
}

void IceBossGoal_IceBreath::Init(IceBoss *arg0) {
    void *var_r3_1293;

    this->unk8 = 1;
    this->unkC = (Enemy *) arg0;
    this->unk4 = 0x86;
    if ((Enemy *) this->unkC != NULL) {
        this->unk9 = 1;
    }
    if (MKHeap::Current() != NULL) {
        var_r3_1293 = ((MKHeap *) (MKHeap::Current()))->Alloc(0x140, NULL, 0);
    } else {
        var_r3_1293 = malloc(0x140);
    }
    this->unk1C = var_r3_1293;
    this->unk10 = 5;
}

#if 0 // DRAFT: ')' expected
void IceBossGoal_IceWave::Terminate() {
    Enemy *temp_r3_1318;
    Enemy *temp_r3_1332;
    f32 var_f1_1336;

    temp_r3_1318 = this->unkC;
    temp_r3_1318->unkB08 &= ~0x10;
    M2C_FIELD(this->unkC, f32 *, 0xFD8) = (f32) (M2C_FIELD(&gb, f32 *, 0x30C) + M2C_FIELD(checked_cast<IceBossDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unkC->unk0), f32 *, 0x2C0));
    temp_r3_1332 = this->unkC;
    var_f1_1336 = M2C_FIELD(temp_r3_1332, f32 *, 0xFD4) - M2C_FIELD(&gb, f32 *, 0x30C);
    if (var_f1_1336 > 0.0f) {

    } else {
        var_f1_1336 = 0.0f;
    }
    if (var_f1_1336 < M2C_BITWISE(f32, 5.0)) {
        M2C_FIELD(temp_r3_1332, f32 *, 0xFD4) = (f32) (M2C_FIELD(&gb, f32 *, 0x30C) + 5.0f);
    }
    this->unkC->unkA20 = NULL;
    this->unkC->SetInvulnerableToMeleeAttacks(0U, 1U);
    this->unkC->SetInvulnerableToBreathAttacks(0U, 1U);
    this->unk8 = 1;
}
#endif

#if 0 // DRAFT: undefined identifier 'sp80'
u8 IceBossGoal_IceWave::Update() {
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    Enemy *temp_r3_1386;
    Enemy *temp_r3_1420;
    Enemy *temp_r4_1404;
    Enemy *temp_r4_1445;
    Enemy *temp_r6_1479;
    f32 temp_f1_1491;
    f32 temp_f2_1480;
    f64 temp_f0_1465;
    f64 temp_f0_1484;
    f64 temp_f1_1455;
    u8 var_r30_1387;
    u8 var_r30_1418;
    void *temp_r3_1434;
    void *temp_r3_1440;
    void *temp_r3_1452;
    void *temp_r3_1497;

    ActivateIfInactive();
    if ((u8) this->unk10 != 0) {
        temp_r3_1386 = this->unkC;
        var_r30_1387 = 0;
        if (((u8) M2C_FIELD(temp_r3_1386, u8 *, 0x8B8) == 2) || (temp_r3_1386->unk870.unk40.Get() != NULL)) {
            var_r30_1387 = 1;
        }
        if (var_r30_1387 != 0) {
            ((AITargetData *) &sp78)->GetDir();
            temp_r4_1404 = this->unkC;
            M2C_FIELD(temp_r4_1404, f64 *, 0xE0) = sp78;
            M2C_FIELD(temp_r4_1404, f64 *, 0xE8) = sp80;
            temp_r4_1404->unk6B5 |= 0x40;
        }
        if (((u8) this->unkC->unkB08 >> 4U) & 1) {
            var_r30_1418 = 0;
            this->unk10 = 0;
            temp_r3_1420 = this->unkC;
            if (((u8) M2C_FIELD(temp_r3_1420, u8 *, 0x8B8) == 2) || (temp_r3_1420->unk870.unk40.Get() != NULL)) {
                var_r30_1418 = 1;
            }
            if (var_r30_1418 != 0) {
                temp_r3_1434 = M2C_FIELD(this->unkC, void **, 0xFDC);
                M2C_FIELD(M2C_FIELD(temp_r3_1434, void **, 0x44), M2C_UNK (**)(void *), 0x30)(temp_r3_1434);
                temp_r3_1440 = M2C_FIELD(this->unkC, void **, 0xFDC);
                M2C_FIELD(M2C_FIELD(temp_r3_1440, void **, 0x44), M2C_UNK (**)(void *), 0x40)(temp_r3_1440);
                temp_r4_1445 = this->unkC;
                sp28 = M2C_FIELD(temp_r4_1445, f64 *, 0xC0) * 5.5769738e-315;
                temp_r3_1452 = temp_r4_1445->unk8;
                temp_f1_1455 = M2C_FIELD(temp_r3_1452, f64 *, 0x30);
                sp30 = temp_r4_1445->unkC8 * 200.0f;
                sp48 = sp28;
                sp58 = temp_f1_1455;
                sp50 = (f64) sp30;
                sp60 = M2C_FIELD(temp_r3_1452, f64 *, 0x38);
                temp_f0_1465 = temp_f1_1455 + sp48;
                sp18 = temp_f0_1465;
                sp68 = temp_f0_1465;
                sp20 = (f32) sp60 + (f32) sp50;
                sp70 = (f64) sp20;
                temp_r6_1479 = this->unkC;
                temp_f2_1480 = 100.0f * M2C_FIELD(checked_cast<IceBossDescriptor *, MKPropDescriptor>((MKPropDescriptor *) temp_r4_1445->unk0), f32 *, 0x2CC);
                temp_f0_1484 = M2C_FIELD(temp_r6_1479, f64 *, 0xC0) * (f64) temp_f2_1480;
                sp8 = temp_f0_1484;
                temp_f1_1491 = temp_r6_1479->unkC8 * temp_f2_1480;
                sp38 = temp_f0_1484;
                sp10 = temp_f1_1491;
                sp40 = (f64) sp10;
                temp_r3_1497 = M2C_FIELD(temp_r6_1479, void **, 0xFDC);
                M2C_FIELD(M2C_FIELD(temp_r3_1497, void **, 0x44), M2C_UNK (**)(void *, f64 *, f64 *, Enemy *, M2C_UNK, M2C_UNK, f32, f32), 0x48)(temp_r3_1497, &sp68, &sp38, temp_r6_1479, 0, 0, temp_f1_1491, temp_f2_1480);
            }
        }
    }
    if (((Character *) this->unkC)->HasAnimFinished() != 0) {
        this->unk8 = 2;
    }
    return this->unk8;
}
#endif

void IceBossGoal_IceWave::Activate() {
    AnimSequence *temp_r4_1551;
    Enemy *temp_r3_1547;
    Enemy *temp_r6_1537;
    void *temp_r3_1567;

    this->unk8 = 0;
    this->unk10 = 1;
    ((Character *) this->unkC)->StopMovement(1U);
    temp_r6_1537 = this->unkC;
    temp_r6_1537->unk68C = temp_r6_1537->unkA38->unk15C;
    if (this->unkC->SelectAttack(0x10, 0x97) != 0) {
        temp_r3_1547 = this->unkC;
        temp_r4_1551 = temp_r3_1547->unkA20->unk0;
        temp_r3_1547->SetAnim(temp_r4_1551, (AnimTransition *) temp_r4_1551, 0.15f, 0U);
    }
    M2C_FIELD(this->unkC, f32 *, 0xFD8) = 0.0f;
    this->unkC->SetInvulnerableToMeleeAttacks(1U, 1U);
    this->unkC->SetInvulnerableToBreathAttacks(1U, 1U);
    temp_r3_1567 = M2C_FIELD(this->unkC, void **, 0xFDC);
    M2C_FIELD(M2C_FIELD(temp_r3_1567, void **, 0x44), M2C_UNK (**)(void *), 0x20)(temp_r3_1567);
}

#if 0 // DRAFT: ')' expected
void IceBossGoal_Stalactite::Terminate() {
    Enemy *temp_r3_1588;
    Enemy *temp_r3_1602;
    f32 var_f1_1606;

    temp_r3_1588 = this->unkC;
    temp_r3_1588->unkB08 &= ~0x10;
    M2C_FIELD(this->unkC, f32 *, 0xFD4) = (f32) (M2C_FIELD(&gb, f32 *, 0x30C) + M2C_FIELD(checked_cast<IceBossDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unkC->unk0), f32 *, 0x2BC));
    temp_r3_1602 = this->unkC;
    var_f1_1606 = M2C_FIELD(temp_r3_1602, f32 *, 0xFD8) - M2C_FIELD(&gb, f32 *, 0x30C);
    if (var_f1_1606 > 0.0f) {

    } else {
        var_f1_1606 = 0.0f;
    }
    if (var_f1_1606 < M2C_BITWISE(f32, 5.0)) {
        M2C_FIELD(temp_r3_1602, f32 *, 0xFD8) = (f32) (M2C_FIELD(&gb, f32 *, 0x30C) + 5.0f);
    }
    this->unkC->unkA20 = NULL;
    this->unkC->SetInvulnerableToMeleeAttacks(0U, 1U);
    this->unkC->SetInvulnerableToBreathAttacks(0U, 1U);
    this->unk8 = 1;
}
#endif

#if 0 // DRAFT: ')' expected
u8 IceBossGoal_Stalactite::Update() {
    f64 sp20;
    f64 sp18;
    M2C_UNK sp8;
    Enemy *temp_r3_1649;
    Enemy *temp_r4_1663;
    u8 var_r31_1650;
    void *temp_r3_1664;

    ActivateIfInactive();
    temp_r3_1649 = this->unkC;
    var_r31_1650 = 0;
    if (((u8) M2C_FIELD(temp_r3_1649, u8 *, 0x8B8) == 2) || (temp_r3_1649->unk870.unk40.Get() != NULL)) {
        var_r31_1650 = 1;
    }
    if (var_r31_1650 != 0) {
        temp_r4_1663 = this->unkC;
        temp_r3_1664 = temp_r4_1663->unk8;
        sp18 = M2C_FIELD(temp_r3_1664, f64 *, 0x30);
        sp20 = M2C_FIELD(temp_r3_1664, f64 *, 0x38);
        (*(f32 *) ((u8 *) &sp18 + 0x4)) += 100.0f * M2C_FIELD(checked_cast<IceBossDescriptor *, MKPropDescriptor>((MKPropDescriptor *) temp_r4_1663->unk0), f32 *, 0x2C8);
        if (((MKAnimScript *) this->unkC->unk630)->CheckEvent(0) != 0) {
            ((IceBossStalactiteSpawner *) (M2C_FIELD(this->unkC, IceBossStalactiteSpawner **, 0xFE0)))->Spawn(*((MKVector3 *) &sp18));
        }
        if (((MKAnimScript *) this->unkC->unk630)->CheckEvent(1) != 0) {
            ((AITargetData *) &sp8)->GetPos();
            ((IceBossStalactiteSpawner *) (M2C_FIELD(this->unkC, IceBossStalactiteSpawner **, 0xFE0)))->Fire(*((MKVector3 *) &sp8));
        }
    }
    if (((Character *) this->unkC)->HasAnimFinished() != 0) {
        this->unk8 = 2;
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'Enemy *' to 'MKVector3 *'
void IceBossGoal_Stalactite::Activate() {
    AnimSequence *temp_r4_1740;
    Enemy *temp_r3_1736;
    Enemy *temp_r4_1755;

    this->unk8 = 0;
    ((Character *) this->unkC)->StopMovement(1U);
    if (this->unkC->SelectAttack(0x10, 0x96) != 0) {
        temp_r3_1736 = this->unkC;
        temp_r4_1740 = temp_r3_1736->unkA20->unk0;
        temp_r3_1736->SetAnim(temp_r4_1740, (AnimTransition *) temp_r4_1740, 0.15f, 0U);
    }
    M2C_FIELD(this->unkC, f32 *, 0xFD4) = 0.0f;
    this->unkC->SetInvulnerableToMeleeAttacks(1U, 1U);
    this->unkC->SetInvulnerableToBreathAttacks(1U, 1U);
    temp_r4_1755 = this->unkC;
    ((ElementalShield *) (M2C_FIELD(temp_r4_1755, ElementalShield **, 0xFF8)))->Trigger(temp_r4_1755 + 0xF80, 10.0f, 0U);
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void IceBossGoal_MeleeAttack3::Terminate() {
    AttackerManager *var_r3_1817;
    Enemy *temp_r3_1777;
    Enemy *temp_r3_1781;
    Enemy *temp_r3_1798;
    Enemy *var_r4_1824;
    EnemyAttack *temp_r5_1782;
    u8 var_r30_1796;

    temp_r3_1777 = this->unkC;
    temp_r3_1777->unkB08 &= ~0x10;
    temp_r3_1781 = this->unkC;
    temp_r5_1782 = temp_r3_1781->unkA20;
    if (temp_r5_1782 != NULL) {
        this->unkC->unkA7C = M2C_FIELD(&gb, f32 *, 0x30C) + temp_r3_1781->unkA38->GetEnemyAttackSetting((EnemySettingType) 6, temp_r5_1782);
    }
    var_r30_1796 = 0;
    this->unkC->unkA20 = NULL;
    temp_r3_1798 = this->unkC;
    if (((u8) M2C_FIELD(temp_r3_1798, u8 *, 0x8B8) == 2) || (temp_r3_1798->unk870.unk40.Get() != NULL)) {
        var_r30_1796 = 1;
    }
    if (var_r30_1796 != 0) {
        var_r3_1817 = M2C_FIELD(this->unkC->unk870.unk40.Get()->__vptr, AttackerManager *(**)(), 0x48)();
    } else {
        var_r3_1817 = NULL;
    }
    if (var_r3_1817 != NULL) {
        var_r4_1824 = this->unkC;
        if (var_r4_1824 != NULL) {
            var_r4_1824 += 0x6B8;
        }
        var_r3_1817->Remove((Targetable *) var_r4_1824, 2);
    }
    this->unkC->SetInvulnerableToMeleeAttacks(0U, 1U);
    this->unkC->SetInvulnerableToBreathAttacks(0U, 1U);
}
#endif

#if 0 // DRAFT: illegal operand
u8 IceBossGoal_MeleeAttack3::Update() {
    MKCollisionResult sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 sp8;
    Enemy *temp_r3_1856;
    Enemy *temp_r3_2058;
    Enemy *temp_r3_2100;
    Enemy *temp_r4_1864;
    Enemy *temp_r6_1879;
    EnemyAttack *temp_r30_1857;
    MKProp *var_r0_1911;
    MKProp *var_r25_2078;
    MKProp *var_r4_2044;
    f32 var_f4_1937;
    f32 var_f5_1957;
    f64 temp_f1_1962;
    f64 temp_f1_1968;
    f64 temp_f1_1972;
    s32 temp_r3_1896;
    s32 temp_r3_1991;
    s32 var_r0_2001;
    s32 var_r26_1900;
    s32 var_r28_1899;
    u32 *var_r3_1919;
    u32 temp_r4_1928;
    u8 var_r25_2059;
    void *temp_r29_1904;
    void *temp_r3_1881;
    void *temp_r3_1908;
    void *temp_r3_2041;
    void *temp_r3_2075;

    ActivateIfInactive();
    temp_r3_1856 = this->unkC;
    temp_r30_1857 = temp_r3_1856->unkA20;
    if (((Character *) temp_r3_1856)->HasAnimFinished() != 0) {
        this->unk8 = 2;
    }
    temp_r4_1864 = this->unkC;
    if (!(((u8) temp_r4_1864->unkB08 >> 1U) & 1) && (temp_r30_1857 != NULL) && ((s32) temp_r30_1857->unk0->unk68 == 0x3F) && (((MKAnimScript *) temp_r4_1864->unk630)->CheckEvent(0xB) != 0)) {
        temp_r6_1879 = this->unkC;
        temp_r3_1881 = temp_r6_1879->unk8;
        sp50 = M2C_FIELD(temp_r3_1881, f64 *, 0x30);
        sp58 = M2C_FIELD(temp_r3_1881, f64 *, 0x38);
        MKModel_CalculateRefPointWorldPosition(temp_r6_1879->unk4, (s32) *temp_r30_1857->unk7C, (MKVector3 *) &sp50);
        temp_r3_1896 = MKCollision_SphereCollide(*((MKVector3 *) &sp50), 250.0f, &sp60, 0xA, (MKCollisionMode) 2, 0x08000000);
        if (temp_r3_1896 != 0) {
            var_r28_1899 = 0;
            var_r26_1900 = 0;
loop_57:
            if (var_r28_1899 < temp_r3_1896) {
                temp_r29_1904 = &sp60 + var_r26_1900;
                if (((u8) M2C_FIELD(temp_r29_1904, u8 *, 0x50) != 0) && (temp_r3_1908 = M2C_FIELD(temp_r29_1904, void **, 0x48), ((temp_r3_1908 == NULL) == 0)) && (var_r0_1911 = M2C_FIELD(temp_r3_1908, MKProp **, 8), ((var_r0_1911 == NULL) == 0))) {

                } else {
                    var_r0_1911 = NULL;
                }
                var_r3_1919 = this->unkC->unkA1C;
loop_17:
                temp_r4_1928 = *var_r3_1919;
                if (temp_r4_1928 == 0) {
                    var_r3_1919 = NULL;
                } else if (temp_r4_1928 == var_r0_1911) {

                } else {
                    var_r3_1919 += 4;
                    goto loop_17;
                }
                if (var_r3_1919 == NULL) {
                    var_f4_1937 = 0.0f;
                    sp24 = 0.0f;
                    sp20 = M2C_FIELD(temp_r29_1904, f32 *, 0) - (f32) sp50;
                    sp28 = M2C_FIELD(temp_r29_1904, f32 *, 8) - (f32) sp58;
                    sp30 = (f64) sp20;
                    sp38 = (f64) sp28;
                    var_f5_1957 = ((f32) sp38 * (f32) sp38) + (((f32) sp30 * (f32) sp30) + ((*(f32 *) ((u8 *) &sp30 + 0x4)) * (*(f32 *) ((u8 *) &sp30 + 0x4))));
                    if (var_f5_1957 > 1e-12f) {
                        if (var_f5_1957 > 0.0f) {
                            temp_f1_1962 = __frsqrte(var_f5_1957);
                            temp_f1_1968 = 0.5 * temp_f1_1962 * -(((f64) var_f5_1957 * (temp_f1_1962 * temp_f1_1962)) - 3.0);
                            temp_f1_1972 = 0.5 * temp_f1_1968 * -(((f64) var_f5_1957 * (temp_f1_1968 * temp_f1_1968)) - 3.0);
                            var_f5_1957 = (f32) ((f64) var_f5_1957 * (0.5 * temp_f1_1972 * -(((f64) var_f5_1957 * (temp_f1_1972 * temp_f1_1972)) - 3.0)));
                        } else if (var_f5_1957 < M2C_BITWISE(f32, 0.0)) {
                            var_f5_1957 = __float_nan;
                        } else {
                            sp8 = var_f5_1957;
                            temp_r3_1991 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                            switch (temp_r3_1991) { /* irregular */
                            case 0x7F800000:
                                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                    var_r0_2001 = 1;
                                } else {
                                    var_r0_2001 = 2;
                                }
                                break;
                            case 0x0:
                                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                    var_r0_2001 = 5;
                                } else {
                                    var_r0_2001 = 3;
                                }
                                break;
                            default:
                                var_r0_2001 = 4;
                                break;
                            }
                            if (var_r0_2001 == 1) {
                                var_f5_1957 = __float_nan;
                            }
                        }
                        var_f4_1937 = 1.0f / var_f5_1957;
                    }
                    sp10 = (f32) sp30 * var_f4_1937;
                    sp14 = (*(f32 *) ((u8 *) &sp30 + 0x4)) * var_f4_1937;
                    sp18 = (f32) sp38 * var_f4_1937;
                    sp40 = (f64) sp10;
                    sp48 = (f64) sp18;
                    if (((u8) M2C_FIELD(temp_r29_1904, u8 *, 0x50) != 0) && (temp_r3_2041 = M2C_FIELD(temp_r29_1904, void **, 0x48), ((temp_r3_2041 == NULL) == 0)) && (var_r4_2044 = M2C_FIELD(temp_r3_2041, MKProp **, 8), ((var_r4_2044 == NULL) == 0))) {

                    } else {
                        var_r4_2044 = NULL;
                    }
                    if (this->unkC->MeleeDamageTarget(var_r4_2044, temp_r30_1857, *((MKVector3 *) &sp40), -1) != 0) {
                        temp_r3_2058 = this->unkC;
                        var_r25_2059 = 0;
                        if (((u8) M2C_FIELD(temp_r3_2058, u8 *, 0x8B8) == 2) || (temp_r3_2058->unk870.unk40.Get() != NULL)) {
                            var_r25_2059 = 1;
                        }
                        if (var_r25_2059 != 0) {
                            if (((u8) M2C_FIELD(temp_r29_1904, u8 *, 0x50) != 0) && (temp_r3_2075 = M2C_FIELD(temp_r29_1904, void **, 0x48), ((temp_r3_2075 == NULL) == 0)) && (var_r25_2078 = M2C_FIELD(temp_r3_2075, MKProp **, 8), ((var_r25_2078 == NULL) == 0))) {

                            } else {
                                var_r25_2078 = NULL;
                            }
                            if (var_r25_2078 == this->unkC->unk870.GetProp()) {
                                this->unkC->SetHitTarget(1U);
                            }
                        }
                    }
                }
                var_r28_1899 += 1;
                var_r26_1900 += 0x58;
                goto loop_57;
            }
        }
    }
    temp_r3_2100 = this->unkC;
    if ((((u8) temp_r3_2100->unkB08 >> 4U) & 1) && (temp_r3_2100->CheckMeleeHit(temp_r30_1857, GS_SpyroMeleeHit) != 0)) {
        this->unkC->SetHitTarget(1U);
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: undefined identifier 'sp10'
void IceBossGoal_MeleeAttack3::Activate() {
    f64 sp8;
    AnimSequence *temp_r5_2154;
    AttackSweepData *temp_r3_2202;
    AttackerManager *var_r3_2227;
    Enemy *temp_r3_2148;
    Enemy *temp_r3_2163;
    Enemy *temp_r3_2207;
    Enemy *temp_r4_2158;
    Enemy *temp_r4_2180;
    Enemy *temp_r4_2190;
    Enemy *var_r4_2234;
    u8 var_r30_2159;
    u8 var_r30_2208;

    this->unk8 = 0;
    if (MKRand_Int((int *) &gViewSeed, 0, 0x64) >= 0x32) {
        this->unkC->SelectAttack(0x10, 0x3E);
    } else {
        this->unkC->SelectAttack(0x10, 0x3F);
    }
    temp_r3_2148 = this->unkC;
    temp_r5_2154 = temp_r3_2148->unkA20->unk0;
    temp_r3_2148->SetAnim((AnimSequenceType) temp_r5_2154->unk6C, temp_r5_2154->unk68, 0, 0.15f, 0U, 0U);
    temp_r4_2158 = this->unkC;
    var_r30_2159 = 0;
    temp_r4_2158->unk68C = temp_r4_2158->unkA38->unk15C;
    temp_r3_2163 = this->unkC;
    if (((u8) M2C_FIELD(temp_r3_2163, u8 *, 0x8B8) == 2) || (temp_r3_2163->unk870.unk40.Get() != NULL)) {
        var_r30_2159 = 1;
    }
    if (var_r30_2159 != 0) {
        ((AITargetData *) &sp8)->GetDir();
        temp_r4_2180 = this->unkC;
        M2C_FIELD(temp_r4_2180, f64 *, 0xE0) = sp8;
        M2C_FIELD(temp_r4_2180, f64 *, 0xE8) = sp10;
        temp_r4_2180->unk6B5 |= 0x40;
    }
    temp_r4_2190 = this->unkC;
loop_10:
    if ((u32) *temp_r4_2190->unkA1C != 0) {
        temp_r4_2190->unkA1C += 4;
        goto loop_10;
    }
    temp_r3_2202 = this->unkC->unkA30;
    if (temp_r3_2202 != NULL) {
        temp_r3_2202->SetDefaults();
    }
    temp_r3_2207 = this->unkC;
    var_r30_2208 = 0;
    if (((u8) M2C_FIELD(temp_r3_2207, u8 *, 0x8B8) == 2) || (temp_r3_2207->unk870.unk40.Get() != NULL)) {
        var_r30_2208 = 1;
    }
    if (var_r30_2208 != 0) {
        var_r3_2227 = M2C_FIELD(this->unkC->unk870.unk40.Get()->__vptr, AttackerManager *(**)(), 0x48)();
    } else {
        var_r3_2227 = NULL;
    }
    if (var_r3_2227 != NULL) {
        var_r4_2234 = this->unkC;
        if (var_r4_2234 != NULL) {
            var_r4_2234 += 0x6B8;
        }
        var_r3_2227->Add((Targetable *) var_r4_2234, 2);
    }
    this->unkC->SetInvulnerableToMeleeAttacks(1U, 1U);
    this->unkC->SetInvulnerableToBreathAttacks(1U, 1U);
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void IceBossGoal_MeleeAttack2::Terminate() {
    AttackerManager *var_r3_2306;
    Enemy *temp_r3_2266;
    Enemy *temp_r3_2270;
    Enemy *temp_r3_2287;
    Enemy *var_r4_2313;
    EnemyAttack *temp_r5_2271;
    u8 var_r30_2285;

    temp_r3_2266 = this->unkC;
    temp_r3_2266->unkB08 &= ~0x10;
    temp_r3_2270 = this->unkC;
    temp_r5_2271 = temp_r3_2270->unkA20;
    if (temp_r5_2271 != NULL) {
        this->unkC->unkA7C = M2C_FIELD(&gb, f32 *, 0x30C) + temp_r3_2270->unkA38->GetEnemyAttackSetting((EnemySettingType) 6, temp_r5_2271);
    }
    var_r30_2285 = 0;
    this->unkC->unkA20 = NULL;
    temp_r3_2287 = this->unkC;
    if (((u8) M2C_FIELD(temp_r3_2287, u8 *, 0x8B8) == 2) || (temp_r3_2287->unk870.unk40.Get() != NULL)) {
        var_r30_2285 = 1;
    }
    if (var_r30_2285 != 0) {
        var_r3_2306 = M2C_FIELD(this->unkC->unk870.unk40.Get()->__vptr, AttackerManager *(**)(), 0x48)();
    } else {
        var_r3_2306 = NULL;
    }
    if (var_r3_2306 != NULL) {
        var_r4_2313 = this->unkC;
        if (var_r4_2313 != NULL) {
            var_r4_2313 += 0x6B8;
        }
        var_r3_2306->Remove((Targetable *) var_r4_2313, 2);
    }
    this->unkC->SetInvulnerableToMeleeAttacks(0U, 1U);
    this->unkC->SetInvulnerableToBreathAttacks(0U, 1U);
}
#endif

u8 IceBossGoal_MeleeAttack2::Update() {
    Enemy *temp_r3_2352;

    ActivateIfInactive();
    if (((Character *) this->unkC)->HasAnimFinished() != 0) {
        this->unk8 = 2;
    }
    temp_r3_2352 = this->unkC;
    if ((((u8) temp_r3_2352->unkB08 >> 4U) & 1) && (temp_r3_2352->CheckMeleeHit(temp_r3_2352->unkA20, -1) != 0)) {
        this->unkC->SetHitTarget(1U);
    }
    return this->unk8;
}

#if 0 // DRAFT: undefined identifier 'sp10'
void IceBossGoal_MeleeAttack2::Activate() {
    f64 sp8;
    AnimSequence *temp_r5_2393;
    AttackSweepData *temp_r3_2441;
    AttackerManager *var_r3_2466;
    Enemy *temp_r3_2387;
    Enemy *temp_r3_2402;
    Enemy *temp_r3_2446;
    Enemy *temp_r4_2397;
    Enemy *temp_r4_2419;
    Enemy *temp_r4_2429;
    Enemy *var_r4_2473;
    u8 var_r30_2398;
    u8 var_r30_2447;

    this->unk8 = 0;
    this->unkC->SelectAttack(0x10, 0x3D);
    temp_r3_2387 = this->unkC;
    temp_r5_2393 = temp_r3_2387->unkA20->unk0;
    temp_r3_2387->SetAnim((AnimSequenceType) temp_r5_2393->unk6C, temp_r5_2393->unk68, 0, 0.15f, 0U, 0U);
    temp_r4_2397 = this->unkC;
    var_r30_2398 = 0;
    temp_r4_2397->unk68C = temp_r4_2397->unkA38->unk15C;
    temp_r3_2402 = this->unkC;
    if (((u8) M2C_FIELD(temp_r3_2402, u8 *, 0x8B8) == 2) || (temp_r3_2402->unk870.unk40.Get() != NULL)) {
        var_r30_2398 = 1;
    }
    if (var_r30_2398 != 0) {
        ((AITargetData *) &sp8)->GetDir();
        temp_r4_2419 = this->unkC;
        M2C_FIELD(temp_r4_2419, f64 *, 0xE0) = sp8;
        M2C_FIELD(temp_r4_2419, f64 *, 0xE8) = sp10;
        temp_r4_2419->unk6B5 |= 0x40;
    }
    temp_r4_2429 = this->unkC;
loop_7:
    if ((u32) *temp_r4_2429->unkA1C != 0) {
        temp_r4_2429->unkA1C += 4;
        goto loop_7;
    }
    temp_r3_2441 = this->unkC->unkA30;
    if (temp_r3_2441 != NULL) {
        temp_r3_2441->SetDefaults();
    }
    temp_r3_2446 = this->unkC;
    var_r30_2447 = 0;
    if (((u8) M2C_FIELD(temp_r3_2446, u8 *, 0x8B8) == 2) || (temp_r3_2446->unk870.unk40.Get() != NULL)) {
        var_r30_2447 = 1;
    }
    if (var_r30_2447 != 0) {
        var_r3_2466 = M2C_FIELD(this->unkC->unk870.unk40.Get()->__vptr, AttackerManager *(**)(), 0x48)();
    } else {
        var_r3_2466 = NULL;
    }
    if (var_r3_2466 != NULL) {
        var_r4_2473 = this->unkC;
        if (var_r4_2473 != NULL) {
            var_r4_2473 += 0x6B8;
        }
        var_r3_2466->Add((Targetable *) var_r4_2473, 2);
    }
    this->unkC->SetInvulnerableToMeleeAttacks(1U, 1U);
    this->unkC->SetInvulnerableToBreathAttacks(1U, 1U);
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void IceBossGoal_MeleeAttack1::Terminate() {
    AttackerManager *var_r3_2545;
    EnemyAttack *temp_r5_2510;
    IceBoss *temp_r3_2505;
    IceBoss *temp_r3_2509;
    IceBoss *temp_r3_2526;
    IceBoss *var_r4_2552;
    u8 var_r30_2524;

    temp_r3_2505 = this->unkC;
    temp_r3_2505->unkB08 &= ~0x10;
    temp_r3_2509 = this->unkC;
    temp_r5_2510 = temp_r3_2509->unkA20;
    if (temp_r5_2510 != NULL) {
        this->unkC->unkA7C = M2C_FIELD(&gb, f32 *, 0x30C) + temp_r3_2509->unkA38->GetEnemyAttackSetting((EnemySettingType) 6, temp_r5_2510);
    }
    var_r30_2524 = 0;
    this->unkC->unkA20 = NULL;
    temp_r3_2526 = this->unkC;
    if (((u8) M2C_FIELD(temp_r3_2526, u8 *, 0x8B8) == 2) || (temp_r3_2526->unk870.unk40.Get() != NULL)) {
        var_r30_2524 = 1;
    }
    if (var_r30_2524 != 0) {
        var_r3_2545 = M2C_FIELD(this->unkC->unk870.unk40.Get()->__vptr, AttackerManager *(**)(), 0x48)();
    } else {
        var_r3_2545 = NULL;
    }
    if (var_r3_2545 != NULL) {
        var_r4_2552 = this->unkC;
        if (var_r4_2552 != NULL) {
            var_r4_2552 += 0x6B8;
        }
        var_r3_2545->Remove((Targetable *) var_r4_2552, 2);
    }
    this->unkC->EnableWeaponCollision(0U);
    ((Enemy *) this->unkC)->SetInvulnerableToMeleeAttacks(0U, 1U);
    ((Enemy *) this->unkC)->SetInvulnerableToBreathAttacks(0U, 1U);
}
#endif

#if 0 // DRAFT: undefined identifier 'sp10'
u8 IceBossGoal_MeleeAttack1::Update() {
    f64 sp8;
    AnimSequence *temp_r4_2603;
    AnimSequence *temp_r4_2643;
    AnimSequence *temp_r4_2673;
    AnimSequence *temp_r4_2684;
    AnimSequence *temp_r4_2752;
    AnimSequence *temp_r5_2702;
    IceBoss *temp_r29_2637;
    IceBoss *temp_r29_2678;
    IceBoss *temp_r3_2587;
    IceBoss *temp_r3_2670;
    IceBoss *temp_r3_2700;
    IceBoss *temp_r3_2749;
    IceBoss *temp_r3_2756;
    IceBoss *temp_r5_2618;
    IceBoss *temp_r6_2601;
    u8 var_r30_2588;
    u8 var_r30_2638;
    u8 var_r30_2679;
    u8 var_r4_2723;
    u8 var_r5_2602;
    u8 var_r5_2718;
    u8 var_r6_2701;
    void *temp_r6_2717;

    ActivateIfInactive();
    temp_r3_2587 = this->unkC;
    var_r30_2588 = 0;
    if (((u8) M2C_FIELD(temp_r3_2587, u8 *, 0x8B8) == 2) || (temp_r3_2587->unk870.unk40.Get() != NULL)) {
        var_r30_2588 = 1;
    }
    if (var_r30_2588 != 0) {
        temp_r6_2601 = this->unkC;
        var_r5_2602 = 0;
        temp_r4_2603 = temp_r6_2601->unkA50;
        if ((temp_r4_2603 != NULL) && ((u32) temp_r4_2603->unk0 == (u32) M2C_FIELD(temp_r6_2601->unk630, u32 *, 0x20))) {
            var_r5_2602 = 1;
        }
        if (var_r5_2602 != 0) {
            ((AITargetData *) &sp8)->GetDir();
            temp_r5_2618 = this->unkC;
            M2C_FIELD(temp_r5_2618, f64 *, 0xE0) = sp8;
            M2C_FIELD(temp_r5_2618, f64 *, 0xE8) = sp10;
            temp_r5_2618->unk6B5 |= 0x40;
            if (((MKAnimScript *) this->unkC->unk630)->CheckEvent(1) != 0) {
                this->unkC->unk68C = 0.0f;
            }
        }
    }
    temp_r29_2637 = this->unkC;
    var_r30_2638 = 0;
    if (((Character *) temp_r29_2637)->HasAnimFinished() != 0) {
        temp_r4_2643 = temp_r29_2637->unkA50;
        if ((temp_r4_2643 != NULL) && ((u32) temp_r4_2643->unk0 == (u32) M2C_FIELD(temp_r29_2637->unk630, u32 *, 0x20))) {
            var_r30_2638 = 1;
        }
    }
    if (var_r30_2638 != 0) {
        this->unkC->unk68C = 0.0f;
        this->unk10 = M2C_FIELD(&gb, f32 *, 0x30C) + M2C_FIELD(checked_cast<IceBossDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unkC->unk0), f32 *, 0x2B8);
        this->unkC->EnableWeaponCollision(1U);
        temp_r3_2670 = this->unkC;
        temp_r4_2673 = temp_r3_2670->unkA50;
        ((Enemy *) temp_r3_2670)->SetAnim(temp_r4_2673, (AnimTransition *) &temp_r4_2673->unk20, 0.0f, 0U);
    } else {
        temp_r29_2678 = this->unkC;
        var_r30_2679 = 0;
        if (((Character *) temp_r29_2678)->HasAnimFinished() != 0) {
            temp_r4_2684 = temp_r29_2678->unkA50;
            if ((temp_r4_2684 != NULL) && ((u32) temp_r4_2684->unk40 == (u32) M2C_FIELD(temp_r29_2678->unk630, u32 *, 0x20))) {
                var_r30_2679 = 1;
            }
        }
        if (var_r30_2679 != 0) {
            this->unk8 = 2;
        } else {
            temp_r3_2700 = this->unkC;
            var_r6_2701 = 0;
            temp_r5_2702 = temp_r3_2700->unkA50;
            if ((temp_r5_2702 != NULL) && ((u32) temp_r5_2702->unk20 == (u32) M2C_FIELD(temp_r3_2700->unk630, u32 *, 0x20))) {
                var_r6_2701 = 1;
            }
            if (var_r6_2701 != 0) {
                if (!(((u8) temp_r3_2700->unkB08 >> 1U) & 1)) {
                    temp_r6_2717 = temp_r3_2700->unk630;
                    var_r5_2718 = 0;
                    if (((u32) M2C_FIELD(temp_r6_2717, u32 *, 0x2C) >> 1U) & 1) {
                        var_r4_2723 = 0;
                        if ((M2C_FIELD(temp_r6_2717, f32 *, 0x38) > 0.0f) || ((s32) M2C_FIELD(temp_r6_2717, s32 *, 0x44) > 1)) {
                            var_r4_2723 = 1;
                        }
                        if (var_r4_2723 != 0) {
                            var_r5_2718 = 1;
                        }
                    }
                    if ((var_r5_2718 != 0) && (M2C_FIELD(&gb, f32 *, 0x30C) >= this->unk10)) {
                        goto block_35;
                    }
                } else {
block_35:
                    temp_r3_2700->EnableWeaponCollision(0U);
                    temp_r3_2749 = this->unkC;
                    temp_r4_2752 = temp_r3_2749->unkA50;
                    ((Enemy *) temp_r3_2749)->SetAnim(temp_r4_2752, (AnimTransition *) &temp_r4_2752->unk40, 0.0f, 0U);
                }
            }
        }
    }
    temp_r3_2756 = this->unkC;
    if ((((u8) temp_r3_2756->unkB08 >> 4U) & 1) && (((Enemy *) temp_r3_2756)->CheckMeleeHit(temp_r3_2756->unkA20, -1) != 0)) {
        ((Enemy *) this->unkC)->SetHitTarget(1U);
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: undefined identifier 'sp10'
void IceBossGoal_MeleeAttack1::Activate() {
    f64 sp8;
    AnimSequence *temp_r4_2795;
    AttackSweepData *temp_r3_2842;
    AttackerManager *var_r3_2867;
    IceBoss *temp_r3_2791;
    IceBoss *temp_r3_2803;
    IceBoss *temp_r3_2847;
    IceBoss *temp_r4_2798;
    IceBoss *temp_r4_2820;
    IceBoss *temp_r4_2830;
    IceBoss *var_r4_2874;
    u8 var_r30_2799;
    u8 var_r30_2848;

    this->unk8 = 0;
    ((Enemy *) this->unkC)->SelectAttack(0x10, 0x3C);
    temp_r3_2791 = this->unkC;
    temp_r4_2795 = temp_r3_2791->unkA20->unk0;
    ((Enemy *) temp_r3_2791)->SetAnim(temp_r4_2795, (AnimTransition *) temp_r4_2795, 0.15f, 0U);
    temp_r4_2798 = this->unkC;
    var_r30_2799 = 0;
    temp_r4_2798->unk68C = temp_r4_2798->unkA38->unk15C;
    temp_r3_2803 = this->unkC;
    if (((u8) M2C_FIELD(temp_r3_2803, u8 *, 0x8B8) == 2) || (temp_r3_2803->unk870.unk40.Get() != NULL)) {
        var_r30_2799 = 1;
    }
    if (var_r30_2799 != 0) {
        ((AITargetData *) &sp8)->GetDir();
        temp_r4_2820 = this->unkC;
        M2C_FIELD(temp_r4_2820, f64 *, 0xE0) = sp8;
        M2C_FIELD(temp_r4_2820, f64 *, 0xE8) = sp10;
        temp_r4_2820->unk6B5 |= 0x40;
    }
    temp_r4_2830 = this->unkC;
loop_7:
    if ((u32) *temp_r4_2830->unkA1C != 0) {
        temp_r4_2830->unkA1C += 4;
        goto loop_7;
    }
    temp_r3_2842 = this->unkC->unkA30;
    if (temp_r3_2842 != NULL) {
        temp_r3_2842->SetDefaults();
    }
    temp_r3_2847 = this->unkC;
    var_r30_2848 = 0;
    if (((u8) M2C_FIELD(temp_r3_2847, u8 *, 0x8B8) == 2) || (temp_r3_2847->unk870.unk40.Get() != NULL)) {
        var_r30_2848 = 1;
    }
    if (var_r30_2848 != 0) {
        var_r3_2867 = M2C_FIELD(this->unkC->unk870.unk40.Get()->__vptr, AttackerManager *(**)(), 0x48)();
    } else {
        var_r3_2867 = NULL;
    }
    if (var_r3_2867 != NULL) {
        var_r4_2874 = this->unkC;
        if (var_r4_2874 != NULL) {
            var_r4_2874 += 0x6B8;
        }
        var_r3_2867->Add((Targetable *) var_r4_2874, 2);
    }
    ((Enemy *) this->unkC)->SetInvulnerableToMeleeAttacks(1U, 1U);
    ((Enemy *) this->unkC)->SetInvulnerableToBreathAttacks(1U, 1U);
    this->unk10 = 0.0f;
}
#endif

void IceBossGoal_AttackPhase3::AddGoal_AttackIdle() {
    Goal<IceBoss> *temp_r6_2911;

    AddSubgoal((Goal<IceBoss> *) this->unk20);
    temp_r6_2911 = this->unk20;
    M2C_FIELD(temp_r6_2911, AITargetData **, 0x10) = &this->unkC->unk870;
    M2C_FIELD(temp_r6_2911, s32 *, 0x14) = 1;
    M2C_FIELD(temp_r6_2911, s32 *, 0x18) = 0xA0;
    M2C_FIELD(temp_r6_2911, s32 *, 0x1C) = 0;
    M2C_FIELD(temp_r6_2911, u8 *, 0x20) = (u8) (M2C_FIELD(temp_r6_2911, u8 *, 0x20) & ~0x40);
}

void IceBossGoal_AttackPhase3::AddGoal_Taunt() {
    Goal<IceBoss> *temp_r6_2941;

    AddSubgoal((Goal<IceBoss> *) this->unk20);
    temp_r6_2941 = this->unk20;
    M2C_FIELD(temp_r6_2941, AITargetData **, 0x10) = &this->unkC->unk870;
    M2C_FIELD(temp_r6_2941, s32 *, 0x14) = 1;
    M2C_FIELD(temp_r6_2941, s32 *, 0x18) = 3;
    M2C_FIELD(temp_r6_2941, s32 *, 0x1C) = 0;
    M2C_FIELD(temp_r6_2941, u8 *, 0x20) = (u8) (M2C_FIELD(temp_r6_2941, u8 *, 0x20) & ~0x40);
}

void IceBossGoal_AttackPhase3::Terminate() {
    this->unk8 = 1;
    RemoveAllSubgoals();
}

#if 0 // DRAFT: undefined identifier 'sp10'
u8 IceBossGoal_AttackPhase3::Update() {
    f32 sp8;
    IceBoss *temp_r3_2983;
    IceBoss *temp_r3_3070;
    u8 var_r30_2984;
    void **temp_r3_3014;
    void **temp_r3_3037;
    void **temp_r3_3057;

    ActivateIfInactive();
    temp_r3_2983 = this->unkC;
    var_r30_2984 = 0;
    if (((u8) M2C_FIELD(temp_r3_2983, u8 *, 0x8B8) == 2) || (temp_r3_2983->unk870.unk40.Get() != NULL)) {
        var_r30_2984 = 1;
    }
    if ((var_r30_2984 != 0) && (this->unkC->unk870.IsAttackable() == 0)) {
        AddGoal_AttackIdle();
    } else if ((M2C_FIELD(&gb, f32 *, 0x30C) >= this->unkC->unkFD0) && (temp_r3_3014 = this->unk28, ((M2C_FIELD(*temp_r3_3014, u8 (**)(void **), 0x28)(temp_r3_3014) == 0) == 0))) {
        RemoveAllSubgoals();
        AddSubgoal((Goal<IceBoss> *) this->unk38);
        AddSubgoal((Goal<IceBoss> *) this->unk30);
    } else if ((M2C_FIELD(&gb, f32 *, 0x30C) >= this->unkC->unkFD4) && (temp_r3_3037 = this->unk28, ((M2C_FIELD(*temp_r3_3037, u8 (**)(void **), 0x28)(temp_r3_3037) == 0) == 0))) {
        RemoveAllSubgoals();
        AddSubgoal((Goal<IceBoss> *) this->unk2C);
    } else if (M2C_FIELD(&gb, f32 *, 0x30C) >= this->unkC->unkFD8) {
        temp_r3_3057 = this->unk28;
        if (M2C_FIELD(*temp_r3_3057, u8 (**)(void **), 0x28)(temp_r3_3057) != 0) {
            RemoveAllSubgoals();
            ((AITargetData *) &sp8)->GetDir();
            temp_r3_3070 = this->unkC;
            if (((temp_r3_3070->unkC8 * sp10) + ((temp_r3_3070->unkC0 * sp8) + (temp_r3_3070->unkC4 * spC))) < 0.95f) {
                AddGoal_Taunt();
            }
            AddSubgoal((Goal<IceBoss> *) this->unk30);
        }
    }
    this->unk8 = UpdateSubgoals();
    if ((u8) this->unk8 == 2) {
        Activate();
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'IceBoss' to 'unsigned char'
void IceBossGoal_AttackPhase3::Activate() {
    f32 sp8;
    IceBoss *temp_r3_3121;
    IceBoss *temp_r3_3153;
    IceBoss *temp_r3_3210;
    IceBoss *temp_r3_3225;
    IceBoss *temp_r3_3246;
    IceBoss *temp_r4_3168;
    IceBoss *temp_r4_3192;
    u8 var_r30_3122;
    u8 var_r30_3247;

    this->unk8 = 0;
    RemoveAllSubgoals();
    temp_r3_3121 = this->unkC;
    var_r30_3122 = 0;
    if (((u8) M2C_FIELD(temp_r3_3121, u8 *, 0x8B8) == 2) || (temp_r3_3121->unk870.unk40.Get() != NULL)) {
        var_r30_3122 = 1;
    }
    if ((var_r30_3122 == 0) || (this->unkC->GetPhase() != 2)) {
        this->unk8 = 2;
        return;
    }
    if (this->unkC->unk870.IsAttackable() == 0) {
        AddGoal_AttackIdle();
        return;
    }
    temp_r3_3153 = this->unkC;
    if (((u8) temp_r3_3153->unkB08 >> 1U) & 1) {
        ((Enemy *) temp_r3_3153)->SetHitTarget(0U);
        AddGoal_Taunt();
        return;
    }
    if (temp_r3_3153->unk870.GetDist() < 500.0f) {
        temp_r4_3168 = this->unkC;
        if (!(M2C_FIELD(&gb, f32 *, 0x30C) >= temp_r4_3168->unkA7C) || ((u8) *(temp_r4_3168 + ((temp_r4_3168->unkB18 * 0x28) + 0xE54)) != 0)) {
            AddGoal_AttackIdle();
            return;
        }
        AddSubgoal((Goal<IceBoss> *) this->unk34);
        return;
    }
    temp_r4_3192 = this->unkC;
    if ((M2C_FIELD(&gb, f32 *, 0x30C) >= temp_r4_3192->unkFD4) && (temp_r4_3192->unk870.GetDist() > 1000.0f)) {
        AddSubgoal((Goal<IceBoss> *) this->unk2C);
        return;
    }
    temp_r3_3210 = this->unkC;
    if ((M2C_FIELD(&gb, f32 *, 0x30C) >= temp_r3_3210->unkFD8) && (temp_r3_3210->unk870.GetDist() > 1000.0f)) {
        ((AITargetData *) &sp8)->GetDir();
        temp_r3_3225 = this->unkC;
        if (((temp_r3_3225->unkC8 * sp10) + ((temp_r3_3225->unkC0 * sp8) + (temp_r3_3225->unkC4 * spC))) < 0.95f) {
            AddGoal_Taunt();
        }
        AddSubgoal((Goal<IceBoss> *) this->unk30);
        return;
    }
    temp_r3_3246 = this->unkC;
    var_r30_3247 = 0;
    if (((u8) M2C_FIELD(temp_r3_3246, u8 *, 0x8B8) == 2) || (temp_r3_3246->unk870.unk40.Get() != NULL)) {
        var_r30_3247 = 1;
    }
    if ((var_r30_3247 != 0) && (((u8) M2C_FIELD(this->unkC, u8 *, 0x8B9) >> 6U) & 1)) {
        AddSubgoal((Goal<IceBoss> *) this->unk28);
        return;
    }
    AddGoal_Taunt();
}
#endif

void IceBossGoal_AttackPhase3::Deinit() {
    Goal<IceBoss> *temp_r3_3287;
    Goal<IceBoss> *temp_r3_3292;
    void *temp_r31_3301;

    temp_r3_3287 = this->unk34;
    temp_r3_3287->Deinit();
    temp_r3_3292 = this->unk38;
    temp_r3_3292->Deinit();
    operator delete(this->unk34);
    operator delete(this->unk38);
    temp_r31_3301 = this->unk1C;
    if (temp_r31_3301 != NULL) {
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_3301, NULL, 0);
        } else {
            free(temp_r31_3301);
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
void IceBossGoal_AttackPhase3::Init(IceBoss *arg0) {
    Goal<IceBoss> *temp_r4_3422;
    void *var_r3_3402;

    if ((u8) this->unk9 == 0) {
        operator new(0x10U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__14Goal<7IceBoss>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk34 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x20U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__14Goal<7IceBoss>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x1C) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x18) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x10) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x14) = 0;
        }
        this->unk38 = M2C_ERROR(/* Read from unset register $r3 */);
    }
    if ((u8) this->unk9 == 0) {
        if (MKHeap::Current() != NULL) {
            var_r3_3402 = ((MKHeap *) (MKHeap::Current()))->Alloc(8, NULL, 0);
        } else {
            var_r3_3402 = malloc(8);
        }
        this->unk1C = var_r3_3402;
        this->unk10 = 2;
    }
    this->unk8 = 1;
    this->unkC = arg0;
    this->unk4 = 0x83;
    if ((IceBoss *) this->unkC != NULL) {
        this->unk9 = 1;
    }
    temp_r4_3422 = this->unk34;
    M2C_FIELD(temp_r4_3422, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_3422, IceBoss **, 0xC) = arg0;
    M2C_FIELD(temp_r4_3422, s32 *, 4) = 0x3A;
    if ((IceBoss *) M2C_FIELD(temp_r4_3422, IceBoss **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_3422, s8 *, 9) = 1;
    }
    ((IceBossGoal_IceBreath *) this->unk38)->Init(arg0);
}
#endif

void IceBossGoal_AttackPhase2::AddGoal_AttackIdle() {
    Goal<IceBoss> *temp_r6_3455;

    AddSubgoal((Goal<IceBoss> *) this->unk20);
    temp_r6_3455 = this->unk20;
    M2C_FIELD(temp_r6_3455, AITargetData **, 0x10) = &this->unkC->unk870;
    M2C_FIELD(temp_r6_3455, s32 *, 0x14) = 1;
    M2C_FIELD(temp_r6_3455, s32 *, 0x18) = 0xA;
    M2C_FIELD(temp_r6_3455, s32 *, 0x1C) = 0;
    M2C_FIELD(temp_r6_3455, u8 *, 0x20) = (u8) (M2C_FIELD(temp_r6_3455, u8 *, 0x20) & ~0x40);
}

void IceBossGoal_AttackPhase2::AddGoal_Taunt() {
    Goal<IceBoss> *temp_r6_3485;

    AddSubgoal((Goal<IceBoss> *) this->unk20);
    temp_r6_3485 = this->unk20;
    M2C_FIELD(temp_r6_3485, AITargetData **, 0x10) = &this->unkC->unk870;
    M2C_FIELD(temp_r6_3485, s32 *, 0x14) = 1;
    M2C_FIELD(temp_r6_3485, s32 *, 0x18) = 3;
    M2C_FIELD(temp_r6_3485, s32 *, 0x1C) = 0;
    M2C_FIELD(temp_r6_3485, u8 *, 0x20) = (u8) (M2C_FIELD(temp_r6_3485, u8 *, 0x20) & ~0x40);
}

void IceBossGoal_AttackPhase2::Terminate() {
    this->unk8 = 1;
    RemoveAllSubgoals();
}

#if 0 // DRAFT: undefined identifier 'sp10'
u8 IceBossGoal_AttackPhase2::Update() {
    f32 sp8;
    IceBoss *temp_r3_3527;
    IceBoss *temp_r3_3572;
    IceBoss *temp_r3_3605;
    u8 var_r29_3528;
    u8 var_r30_3573;
    void **temp_r3_3558;
    void **temp_r3_3592;

    ActivateIfInactive();
    temp_r3_3527 = this->unkC;
    var_r29_3528 = 0;
    if (((u8) M2C_FIELD(temp_r3_3527, u8 *, 0x8B8) == 2) || (temp_r3_3527->unk870.unk40.Get() != NULL)) {
        var_r29_3528 = 1;
    }
    if ((var_r29_3528 != 0) && (this->unkC->unk870.IsAttackable() == 0)) {
        AddGoal_AttackIdle();
    } else if ((M2C_FIELD(&gb, f32 *, 0x30C) >= this->unkC->unkFD4) && (temp_r3_3558 = this->unk28, ((M2C_FIELD(*temp_r3_3558, u8 (**)(void **), 0x28)(temp_r3_3558) == 0) == 0))) {
        RemoveAllSubgoals();
        AddSubgoal((Goal<IceBoss> *) this->unk2C);
    } else {
        temp_r3_3572 = this->unkC;
        var_r30_3573 = 0;
        if (((u8) M2C_FIELD(temp_r3_3572, u8 *, 0x8B8) == 2) || (temp_r3_3572->unk870.unk40.Get() != NULL)) {
            var_r30_3573 = 1;
        }
        if ((var_r30_3573 != 0) && (M2C_FIELD(&gb, f32 *, 0x30C) >= this->unkC->unkFD8)) {
            temp_r3_3592 = this->unk28;
            if (M2C_FIELD(*temp_r3_3592, u8 (**)(void **), 0x28)(temp_r3_3592) != 0) {
                RemoveAllSubgoals();
                ((AITargetData *) &sp8)->GetDir();
                temp_r3_3605 = this->unkC;
                if (((temp_r3_3605->unkC8 * sp10) + ((temp_r3_3605->unkC0 * sp8) + (temp_r3_3605->unkC4 * spC))) < 0.95f) {
                    AddGoal_Taunt();
                }
                AddSubgoal((Goal<IceBoss> *) this->unk30);
            }
        }
    }
    this->unk8 = UpdateSubgoals();
    if ((u8) this->unk8 == 2) {
        Activate();
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'IceBoss' to 'unsigned char'
void IceBossGoal_AttackPhase2::Activate() {
    IceBoss *temp_r3_3656;
    IceBoss *temp_r3_3688;
    IceBoss *temp_r3_3745;
    IceBoss *temp_r3_3763;
    IceBoss *temp_r4_3703;
    IceBoss *temp_r4_3727;
    u8 var_r30_3657;
    u8 var_r30_3764;

    this->unk8 = 0;
    RemoveAllSubgoals();
    temp_r3_3656 = this->unkC;
    var_r30_3657 = 0;
    if (((u8) M2C_FIELD(temp_r3_3656, u8 *, 0x8B8) == 2) || (temp_r3_3656->unk870.unk40.Get() != NULL)) {
        var_r30_3657 = 1;
    }
    if ((var_r30_3657 == 0) || (this->unkC->GetPhase() != 1)) {
        this->unk8 = 2;
        return;
    }
    if (this->unkC->unk870.IsAttackable() == 0) {
        AddGoal_AttackIdle();
        return;
    }
    temp_r3_3688 = this->unkC;
    if (((u8) temp_r3_3688->unkB08 >> 1U) & 1) {
        ((Enemy *) temp_r3_3688)->SetHitTarget(0U);
        AddGoal_Taunt();
        return;
    }
    if (temp_r3_3688->unk870.GetDist() < 500.0f) {
        temp_r4_3703 = this->unkC;
        if (!(M2C_FIELD(&gb, f32 *, 0x30C) >= temp_r4_3703->unkA7C) || ((u8) *(temp_r4_3703 + ((temp_r4_3703->unkB18 * 0x28) + 0xE54)) != 0)) {
            AddGoal_AttackIdle();
            return;
        }
        AddSubgoal((Goal<IceBoss> *) this->unk34);
        return;
    }
    temp_r4_3727 = this->unkC;
    if ((M2C_FIELD(&gb, f32 *, 0x30C) >= temp_r4_3727->unkFD4) && (temp_r4_3727->unk870.GetDist() > 1000.0f)) {
        AddSubgoal((Goal<IceBoss> *) this->unk2C);
        return;
    }
    temp_r3_3745 = this->unkC;
    if ((M2C_FIELD(&gb, f32 *, 0x30C) >= temp_r3_3745->unkFD8) && (temp_r3_3745->unk870.GetDist() > 1000.0f)) {
        AddGoal_Taunt();
        AddSubgoal((Goal<IceBoss> *) this->unk30);
        return;
    }
    temp_r3_3763 = this->unkC;
    var_r30_3764 = 0;
    if (((u8) M2C_FIELD(temp_r3_3763, u8 *, 0x8B8) == 2) || (temp_r3_3763->unk870.unk40.Get() != NULL)) {
        var_r30_3764 = 1;
    }
    if ((var_r30_3764 != 0) && (((u8) M2C_FIELD(this->unkC, u8 *, 0x8B9) >> 6U) & 1)) {
        AddSubgoal((Goal<IceBoss> *) this->unk28);
        return;
    }
    AddGoal_Taunt();
}
#endif

void IceBossGoal_AttackPhase2::Deinit() {
    Goal<IceBoss> *temp_r3_3804;
    void *temp_r31_3811;

    temp_r3_3804 = this->unk34;
    temp_r3_3804->Deinit();
    operator delete(this->unk34);
    temp_r31_3811 = this->unk1C;
    if (temp_r31_3811 != NULL) {
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_3811, NULL, 0);
        } else {
            free(temp_r31_3811);
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
void IceBossGoal_AttackPhase2::Init(IceBoss *arg0) {
    Goal<IceBoss> *temp_r4_3908;
    void *var_r3_3888;

    if ((u8) this->unk9 == 0) {
        operator new(0x10U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__14Goal<7IceBoss>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk34 = M2C_ERROR(/* Read from unset register $r3 */);
    }
    if ((u8) this->unk9 == 0) {
        if (MKHeap::Current() != NULL) {
            var_r3_3888 = ((MKHeap *) (MKHeap::Current()))->Alloc(8, NULL, 0);
        } else {
            var_r3_3888 = malloc(8);
        }
        this->unk1C = var_r3_3888;
        this->unk10 = 2;
    }
    this->unk8 = 1;
    this->unkC = arg0;
    this->unk4 = 0x82;
    if ((IceBoss *) this->unkC != NULL) {
        this->unk9 = 1;
    }
    temp_r4_3908 = this->unk34;
    M2C_FIELD(temp_r4_3908, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_3908, IceBoss **, 0xC) = arg0;
    M2C_FIELD(temp_r4_3908, s32 *, 4) = 0x3A;
    if ((IceBoss *) M2C_FIELD(temp_r4_3908, IceBoss **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_3908, s8 *, 9) = 1;
    }
}
#endif

void IceBossGoal_AttackPhase1::AddGoal_AttackIdle() {
    Goal<IceBoss> *temp_r6_3938;

    AddSubgoal((Goal<IceBoss> *) this->unk20);
    temp_r6_3938 = this->unk20;
    M2C_FIELD(temp_r6_3938, AITargetData **, 0x10) = &this->unkC->unk870;
    M2C_FIELD(temp_r6_3938, s32 *, 0x14) = 1;
    M2C_FIELD(temp_r6_3938, s32 *, 0x18) = 0xA;
    M2C_FIELD(temp_r6_3938, s32 *, 0x1C) = 0;
    M2C_FIELD(temp_r6_3938, u8 *, 0x20) = (u8) (M2C_FIELD(temp_r6_3938, u8 *, 0x20) & ~0x40);
}

void IceBossGoal_AttackPhase1::AddGoal_Taunt() {
    Goal<IceBoss> *temp_r6_3968;

    AddSubgoal((Goal<IceBoss> *) this->unk20);
    temp_r6_3968 = this->unk20;
    M2C_FIELD(temp_r6_3968, AITargetData **, 0x10) = &this->unkC->unk870;
    M2C_FIELD(temp_r6_3968, s32 *, 0x14) = 1;
    M2C_FIELD(temp_r6_3968, s32 *, 0x18) = 3;
    M2C_FIELD(temp_r6_3968, s32 *, 0x1C) = 0;
    M2C_FIELD(temp_r6_3968, u8 *, 0x20) = (u8) (M2C_FIELD(temp_r6_3968, u8 *, 0x20) & ~0x40);
}

void IceBossGoal_AttackPhase1::Terminate() {
    this->unk8 = 1;
    RemoveAllSubgoals();
}

#if 0 // DRAFT: undefined identifier '__vptr' Too many errors printed, aborting program
u8 IceBossGoal_AttackPhase1::Update() {
    f32 sp8;
    Enemy *temp_r3_4038;
    Enemy *temp_r3_4094;
    Enemy *temp_r3_4139;
    Enemy *temp_r3_4172;
    Goal<IceBoss> *temp_r3_4017;
    Goal<IceBoss> *temp_r3_4024;
    Goal<IceBoss> *temp_r3_4031;
    Goal<IceBoss> *temp_r5_4085;
    u8 var_r29_4043;
    u8 var_r29_4095;
    u8 var_r30_4140;
    void **temp_r3_4010;
    void **temp_r3_4125;
    void **temp_r3_4159;

    ActivateIfInactive();
    temp_r3_4010 = this->unk34;
    if (M2C_FIELD(*temp_r3_4010, u8 (**)(void **), 0x28)(temp_r3_4010) == 0) {
        temp_r3_4017 = this->unk2C;
        if (temp_r3_4017->IsActive() == 0) {
            temp_r3_4024 = this->unk30;
            if (temp_r3_4024->IsActive() == 0) {
                temp_r3_4031 = this->unk38;
                if (temp_r3_4031->IsActive() == 0) {
                    temp_r3_4038 = this->unkC;
                    if ((u8) M2C_FIELD(temp_r3_4038, u8 *, 0xEC8) == 0) {
                        var_r29_4043 = 0;
                        if (((u8) M2C_FIELD(temp_r3_4038, u8 *, 0x8B8) == 2) || (temp_r3_4038->unk870.unk40.Get() != NULL)) {
                            var_r29_4043 = 1;
                        }
                        if ((var_r29_4043 != 0) && (M2C_FIELD(this->unkC->unk870.unk40.Get()->__vptr, u8 (**)(), 0x44)() != 0) && (this->unkC->unk870.GetDist() < 1000.0f) && (this->unkC->SelectDefensiveAttack(this->unkC->unk870.GetDist(), 0x20000U) != 0)) {
                            RemoveAllSubgoals();
                            AddSubgoal((Goal<IceBoss> *) this->unk38);
                            temp_r5_4085 = this->unk38;
                            M2C_FIELD(temp_r5_4085, AITargetData **, 0x10) = &this->unkC->unk870;
                            M2C_FIELD(temp_r5_4085, s8 *, 0x1C) = 1;
                            M2C_FIELD(temp_r5_4085, s8 *, 0x1D) = 0;
                            M2C_FIELD(temp_r5_4085, f32 *, 0x18) = 1.0f;
                        }
                    }
                }
            }
        }
    }
    temp_r3_4094 = this->unkC;
    var_r29_4095 = 0;
    if (((u8) M2C_FIELD(temp_r3_4094, u8 *, 0x8B8) == 2) || (temp_r3_4094->unk870.unk40.Get() != NULL)) {
        var_r29_4095 = 1;
    }
    if ((var_r29_4095 != 0) && (this->unkC->unk870.IsAttackable() == 0)) {
        AddGoal_AttackIdle();
    } else if ((M2C_FIELD(&gb, f32 *, 0x30C) >= M2C_FIELD(this->unkC, f32 *, 0xFD4)) && (temp_r3_4125 = this->unk28, ((M2C_FIELD(*temp_r3_4125, u8 (**)(void **), 0x28)(temp_r3_4125) == 0) == 0))) {
        RemoveAllSubgoals();
        AddSubgoal((Goal<IceBoss> *) this->unk2C);
    } else {
        temp_r3_4139 = this->unkC;
        var_r30_4140 = 0;
        if (((u8) M2C_FIELD(temp_r3_4139, u8 *, 0x8B8) == 2) || (temp_r3_4139->unk870.unk40.Get() != NULL)) {
            var_r30_4140 = 1;
        }
        if ((var_r30_4140 != 0) && (M2C_FIELD(&gb, f32 *, 0x30C) >= M2C_FIELD(this->unkC, f32 *, 0xFD8))) {
            temp_r3_4159 = this->unk28;
            if (M2C_FIELD(*temp_r3_4159, u8 (**)(void **), 0x28)(temp_r3_4159) != 0) {
                RemoveAllSubgoals();
                ((AITargetData *) &sp8)->GetDir();
                temp_r3_4172 = this->unkC;
                if (((temp_r3_4172->unkC8 * sp10) + ((temp_r3_4172->unkC0 * sp8) + (temp_r3_4172->unkC4 * spC))) < 0.95f) {
                    AddGoal_Taunt();
                }
                AddSubgoal((Goal<IceBoss> *) this->unk30);
            }
        }
    }
    this->unk8 = UpdateSubgoals();
    if ((u8) this->unk8 == 2) {
        Activate();
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'Enemy' to 'unsigned char'
void IceBossGoal_AttackPhase1::Activate() {
    Enemy *temp_r3_4223;
    Enemy *temp_r3_4255;
    Enemy *temp_r3_4312;
    Enemy *temp_r3_4330;
    Enemy *temp_r4_4270;
    Enemy *temp_r4_4294;
    u8 var_r30_4224;
    u8 var_r30_4331;

    this->unk8 = 0;
    RemoveAllSubgoals();
    temp_r3_4223 = this->unkC;
    var_r30_4224 = 0;
    if (((u8) M2C_FIELD(temp_r3_4223, u8 *, 0x8B8) == 2) || (temp_r3_4223->unk870.unk40.Get() != NULL)) {
        var_r30_4224 = 1;
    }
    if ((var_r30_4224 == 0) || (((IceBoss *) this->unkC)->GetPhase() != 0)) {
        this->unk8 = 2;
        return;
    }
    if (this->unkC->unk870.IsAttackable() == 0) {
        AddGoal_AttackIdle();
        return;
    }
    temp_r3_4255 = this->unkC;
    if (((u8) temp_r3_4255->unkB08 >> 1U) & 1) {
        temp_r3_4255->SetHitTarget(0U);
        AddGoal_Taunt();
        return;
    }
    if (temp_r3_4255->unk870.GetDist() < 500.0f) {
        temp_r4_4270 = this->unkC;
        if (!(M2C_FIELD(&gb, f32 *, 0x30C) >= temp_r4_4270->unkA7C) || ((u8) *(temp_r4_4270 + ((M2C_FIELD(temp_r4_4270, s32 *, 0xB18) * 0x28) + 0xE54)) != 0)) {
            AddGoal_AttackIdle();
            return;
        }
        AddSubgoal((Goal<IceBoss> *) this->unk34);
        return;
    }
    temp_r4_4294 = this->unkC;
    if ((M2C_FIELD(&gb, f32 *, 0x30C) >= M2C_FIELD(temp_r4_4294, f32 *, 0xFD4)) && (temp_r4_4294->unk870.GetDist() > 1000.0f)) {
        AddSubgoal((Goal<IceBoss> *) this->unk2C);
        return;
    }
    temp_r3_4312 = this->unkC;
    if ((M2C_FIELD(&gb, f32 *, 0x30C) >= M2C_FIELD(temp_r3_4312, f32 *, 0xFD8)) && (temp_r3_4312->unk870.GetDist() > 1000.0f)) {
        AddGoal_Taunt();
        AddSubgoal((Goal<IceBoss> *) this->unk30);
        return;
    }
    temp_r3_4330 = this->unkC;
    var_r30_4331 = 0;
    if (((u8) M2C_FIELD(temp_r3_4330, u8 *, 0x8B8) == 2) || (temp_r3_4330->unk870.unk40.Get() != NULL)) {
        var_r30_4331 = 1;
    }
    if ((var_r30_4331 != 0) && (((u8) M2C_FIELD(this->unkC, u8 *, 0x8B9) >> 6U) & 1)) {
        AddSubgoal((Goal<IceBoss> *) this->unk28);
        return;
    }
    AddGoal_Taunt();
}
#endif

void IceBossGoal_AttackPhase1::Deinit() {
    Goal<IceBoss> *temp_r3_4376;
    void **temp_r3_4371;
    void *temp_r31_4385;

    temp_r3_4371 = this->unk34;
    M2C_FIELD(*temp_r3_4371, M2C_UNK (**)(void **), 0xC)(temp_r3_4371);
    temp_r3_4376 = this->unk38;
    temp_r3_4376->Deinit();
    operator delete(this->unk34);
    operator delete(this->unk38);
    temp_r31_4385 = this->unk1C;
    if (temp_r31_4385 != NULL) {
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_4385, NULL, 0);
        } else {
            free(temp_r31_4385);
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
void IceBossGoal_AttackPhase1::Init(IceBoss *arg0) {
    Goal<IceBoss> *temp_r4_4513;
    void **temp_r4_4502;
    void *var_r3_4482;

    if ((u8) this->unk9 == 0) {
        operator new(0x14U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__14Goal<7IceBoss>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk34 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x20U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk38 = M2C_ERROR(/* Read from unset register $r3 */);
    }
    if ((u8) this->unk9 == 0) {
        if (MKHeap::Current() != NULL) {
            var_r3_4482 = ((MKHeap *) (MKHeap::Current()))->Alloc(8, NULL, 0);
        } else {
            var_r3_4482 = malloc(8);
        }
        this->unk1C = var_r3_4482;
        this->unk10 = 2;
    }
    this->unk8 = 1;
    this->unkC = (Enemy *) arg0;
    this->unk4 = 0x81;
    if ((Enemy *) this->unkC != NULL) {
        this->unk9 = 1;
    }
    temp_r4_4502 = this->unk34;
    M2C_FIELD(temp_r4_4502, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_4502, IceBoss **, 0xC) = arg0;
    M2C_FIELD(temp_r4_4502, s32 *, 4) = 0x3A;
    if ((IceBoss *) M2C_FIELD(temp_r4_4502, IceBoss **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_4502, s8 *, 9) = 1;
    }
    temp_r4_4513 = this->unk38;
    M2C_FIELD(temp_r4_4513, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_4513, IceBoss **, 0xC) = arg0;
    M2C_FIELD(temp_r4_4513, s32 *, 4) = 0x51;
    if ((IceBoss *) M2C_FIELD(temp_r4_4513, IceBoss **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_4513, s8 *, 9) = 1;
    }
}
#endif

#if 0 // DRAFT: illegal operand
void IceBossGoal_SummonWeapon::Terminate() {
    Enemy *temp_r7_4542;

    temp_r7_4542 = this->unkC;
    *(temp_r7_4542 + ((M2C_FIELD(temp_r7_4542, s32 *, 0xB18) * 0x28) + 0xE55)) = 0;
    this->unkC->SetInvulnerableToMeleeAttacks(0U, 1U);
    this->unkC->SetInvulnerableToBreathAttacks(0U, 1U);
    this->unk8 = 1;
}
#endif

u8 IceBossGoal_SummonWeapon::Update() {
    ActivateIfInactive();
    ((IceBoss *) this->unkC)->UpdateSummonWeapon();
    if (((Character *) this->unkC)->HasAnimFinished() != 0) {
        this->unk8 = 2;
    }
    return this->unk8;
}

void IceBossGoal_SummonWeapon::Activate() {
    this->unk8 = 0;
    ((IceBoss *) this->unkC)->SummonWeapon();
    this->unkC->SetAnim((AnimSequenceType) 0x12, 0xCD, 0, 0.15f, 0U, 0U);
    this->unkC->SetInvulnerableToMeleeAttacks(1U, 1U);
    this->unkC->SetInvulnerableToBreathAttacks(1U, 1U);
}

void IceBossGoal_FormShield::Terminate() {
    M2C_FIELD(this->unkC, s8 *, 0xEC9) = 0;
    M2C_FIELD(this->unkC, s8 *, 0xB20) = 0;
    M2C_FIELD(this->unkC, s8 *, 0xFBA) = 0;
    M2C_FIELD(this->unkC, s8 *, 0xEC8) = 0;
    this->unkC->SetInvulnerableToMeleeAttacks(0U, 1U);
    this->unkC->SetInvulnerableToBreathAttacks(0U, 1U);
    this->unk8 = 1;
}

u8 IceBossGoal_FormShield::Update() {
    ActivateIfInactive();
    ((IceBoss *) this->unkC)->UpdateFormShield();
    if (((Character *) this->unkC)->HasAnimFinished() != 0) {
        this->unk8 = 2;
    }
    return this->unk8;
}

void IceBossGoal_FormShield::Activate() {
    this->unk8 = 0;
    ((IceBoss *) this->unkC)->FormShield();
    this->unkC->SetAnim((AnimSequenceType) 0x12, 0xCC, 0, 0.15f, 0U, 0U);
    this->unkC->SetInvulnerableToMeleeAttacks(1U, 1U);
    this->unkC->SetInvulnerableToBreathAttacks(1U, 1U);
}

#if 0 // DRAFT: illegal operand
void IceBossGoal_FormWeapon::Terminate() {
    Enemy *temp_r7_4729;
    Enemy *temp_r7_4738;

    temp_r7_4729 = this->unkC;
    *(temp_r7_4729 + ((M2C_FIELD(temp_r7_4729, s32 *, 0xB18) * 0x28) + 0xE55)) = 0;
    M2C_FIELD(this->unkC, s8 *, 0xB20) = 0;
    M2C_FIELD(this->unkC, s8 *, 0xFB9) = 0;
    temp_r7_4738 = this->unkC;
    *(temp_r7_4738 + ((M2C_FIELD(temp_r7_4738, s32 *, 0xB18) * 0x28) + 0xE54)) = 0;
    this->unkC->SetInvulnerableToMeleeAttacks(0U, 1U);
    this->unkC->SetInvulnerableToBreathAttacks(0U, 1U);
    this->unk8 = 1;
}
#endif

u8 IceBossGoal_FormWeapon::Update() {
    ActivateIfInactive();
    ((IceBoss *) this->unkC)->UpdateFormWeapon();
    if (((Character *) this->unkC)->HasAnimFinished() != 0) {
        this->unk8 = 2;
    }
    return this->unk8;
}

void IceBossGoal_FormWeapon::Activate() {
    this->unk8 = 0;
    ((IceBoss *) this->unkC)->FormWeapon();
    this->unkC->SetAnim((AnimSequenceType) 0x12, 0xCA, 0, 0.15f, 4U, 0U);
    this->unkC->SetInvulnerableToMeleeAttacks(1U, 1U);
    this->unkC->SetInvulnerableToBreathAttacks(1U, 1U);
}

void IceBossGoal_Cutscene3::Terminate() {
    this->unk8 = 1;
    this->unkC->SetInvulnerableToMeleeAttacks(0U, 1U);
    this->unkC->SetInvulnerableToBreathAttacks(0U, 1U);
    M2C_FIELD(this->unkC, s8 *, 0xFBE) = 0;
}

u8 IceBossGoal_Cutscene3::Update() {
    f64 sp28;
    f64 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    s32 spC;
    s32 sp8;
    AnimSequence *temp_r4_4865;
    AnimSequence *temp_r4_4935;
    Enemy *temp_r29_4859;
    Enemy *temp_r29_4929;
    Enemy *temp_r3_4914;
    u8 var_r30_4860;
    u8 var_r30_4930;
    void *temp_r3_4883;

    ActivateIfInactive();
    if (EventCamera_GetCurrent() != NULL) {
        temp_r29_4859 = this->unkC;
        var_r30_4860 = 0;
        if (((Character *) temp_r29_4859)->HasAnimFinished() != 0) {
            temp_r4_4865 = temp_r29_4859->unkA50;
            if ((temp_r4_4865 != NULL) && ((u32) temp_r4_4865->unk0 == (u32) M2C_FIELD(temp_r29_4859->unk630, u32 *, 0x20))) {
                var_r30_4860 = 1;
            }
        }
        if ((var_r30_4860 != 0) && (this->unk10 == 0.0f)) {
            goto block_7;
        }
    } else {
block_7:
        temp_r3_4883 = M2C_FIELD(this->unkC, void **, 0xB10);
        if (temp_r3_4883 != NULL) {
            spC = 0;
            sp8 = 0xB4;
            M2C_FIELD(M2C_FIELD(temp_r3_4883, void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp8);
        }
        sp10 = 0.0f;
        sp14 = 0.0f;
        sp18 = 0.0f;
        sp1C = 1.0f;
        M2C_FIELD(&gb, f64 *, 0x40) = (f64) sp10;
        M2C_FIELD(&gb, f64 *, 0x48) = (f64) sp18;
        sp20 = (f64) sp10;
        sp28 = (f64) sp18;
        ((EventMessage *) (this->unkC + 0xFEC))->Send(NULL);
        temp_r3_4914 = this->unkC;
        temp_r3_4914->Despawn(1);
    }
    if (this->unk10 >= 3.0f) {
        this->unk8 = 2;
    }
    temp_r29_4929 = this->unkC;
    var_r30_4930 = 0;
    if (((Character *) temp_r29_4929)->HasAnimFinished() != 0) {
        temp_r4_4935 = temp_r29_4929->unkA50;
        if ((temp_r4_4935 != NULL) && ((u32) temp_r4_4935->unk0 == (u32) M2C_FIELD(temp_r29_4929->unk630, u32 *, 0x20))) {
            var_r30_4930 = 1;
        }
    }
    if (var_r30_4930 != 0) {
        this->unk10 += gUpdateTimeDelta;
    }
    return this->unk8;
}

#if 0 // DRAFT: undefined identifier '__float_nan'
void IceBossGoal_Cutscene3::Activate() {
    f64 spA8;                                       /* compiler-managed */
    f64 spA0;                                       /* compiler-managed */
    f64 sp98;                                       /* compiler-managed */
    f64 sp90;                                       /* compiler-managed */
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f32 sp48;
    f64 sp40;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f64 sp20;
    s32 sp1C;
    s32 sp18;
    s32 sp14;
    s32 sp10;
    f32 spC;
    f32 sp8;
    Enemy *temp_r3_5230;
    Enemy *temp_r3_5306;
    Enemy *temp_r3_5315;
    Enemy *temp_r4_5226;
    Enemy *temp_r5_5210;
    f32 temp_f5_5102;
    f32 temp_f6_5100;
    f32 temp_f7_5105;
    f32 var_f2_5091;
    f32 var_f3_5198;
    f32 var_f4_5024;
    f32 var_f4_5131;
    f64 temp_f0_5240;
    f64 temp_f1_4997;
    f64 temp_f1_5030;
    f64 temp_f1_5036;
    f64 temp_f1_5040;
    f64 temp_f1_5137;
    f64 temp_f1_5143;
    f64 temp_f1_5147;
    s32 temp_r3_5059;
    s32 temp_r3_5166;
    s32 var_r0_5069;
    s32 var_r0_5176;
    s32 var_r27_5283;
    s32 var_r30_5282;
    void *temp_r3_4981;
    void *temp_r3_4995;
    void *temp_r3_5262;
    void *temp_r3_5289;
    void *temp_r5_4994;

    this->unk8 = 0;
    this->unkC->SetInvulnerableToMeleeAttacks(1U, 1U);
    this->unkC->SetInvulnerableToBreathAttacks(1U, 1U);
    temp_r3_4981 = M2C_FIELD(this->unkC, void **, 0xFF8);
    M2C_FIELD(M2C_FIELD(temp_r3_4981, void **, 0x44), M2C_UNK (**)(void *), 0x34)(temp_r3_4981);
    temp_r5_4994 = M2C_FIELD(M2C_FIELD(*gb, void *(**)(void **), 0xC)(gb), void **, 8);
    temp_r3_4995 = this->unkC->unk8;
    temp_f1_4997 = M2C_FIELD(temp_r3_4995, f64 *, 0x30);
    sp70 = M2C_FIELD(temp_r5_4994, f64 *, 0x30);
    sp80 = temp_f1_4997;
    sp78 = M2C_FIELD(temp_r5_4994, f64 *, 0x38);
    sp88 = M2C_FIELD(temp_r3_4995, f64 *, 0x38);
    sp40 = temp_f1_4997 - sp70;
    spA0 = sp40;
    sp48 = (f32) sp88 - (f32) sp78;
    spA8 = (f64) sp48;
    var_f4_5024 = ((f32) spA8 * (f32) spA8) + (((f32) spA0 * (f32) spA0) + ((*(f32 *) ((u8 *) &sp88 + 0x1c)) * (*(f32 *) ((u8 *) &sp88 + 0x1c))));
    if (var_f4_5024 > 0.000001f) {
        if (var_f4_5024 > 0.0f) {
            temp_f1_5030 = __frsqrte(var_f4_5024);
            temp_f1_5036 = 0.5 * temp_f1_5030 * -(((f64) var_f4_5024 * (temp_f1_5030 * temp_f1_5030)) - 3.0);
            temp_f1_5040 = 0.5 * temp_f1_5036 * -(((f64) var_f4_5024 * (temp_f1_5036 * temp_f1_5036)) - 3.0);
            var_f4_5024 = (f32) ((f64) var_f4_5024 * (0.5 * temp_f1_5040 * -(((f64) var_f4_5024 * (temp_f1_5040 * temp_f1_5040)) - 3.0)));
        } else if (var_f4_5024 < M2C_BITWISE(f32, 0.0)) {
            var_f4_5024 = __float_nan;
        } else {
            spC = var_f4_5024;
            temp_r3_5059 = M2C_BITWISE(s32, spC) & 0x7F800000;
            switch (temp_r3_5059) {                 /* switch 1; irregular */
            case 0x7F800000:                        /* switch 1 */
                if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                    var_r0_5069 = 1;
                } else {
                    var_r0_5069 = 2;
                }
                break;
            case 0x0:                               /* switch 1 */
                if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                    var_r0_5069 = 5;
                } else {
                    var_r0_5069 = 3;
                }
                break;
            default:                                /* switch 1 */
                var_r0_5069 = 4;
                break;
            }
            if (var_r0_5069 == 1) {
                var_f4_5024 = __float_nan;
            }
        }
        var_f2_5091 = 1.0f / var_f4_5024;
    } else {
        var_f2_5091 = 0.0f;
    }
    temp_f6_5100 = (*(f32 *) ((u8 *) &sp88 + 0x1c)) * var_f2_5091;
    temp_f5_5102 = (f32) spA8 * var_f2_5091;
    temp_f7_5105 = (f32) spA0 * var_f2_5091;
    spA0 = temp_f7_5105;
    (*(f32 *) ((u8 *) &sp88 + 0x1c)) = temp_f6_5100;
    spA8 = temp_f5_5102;
    sp30 = (MKVector3::up.unk4 * temp_f5_5102) - (MKVector3::up.unk8 * temp_f6_5100);
    sp34 = (MKVector3::up.unk8 * temp_f7_5105) - (MKVector3::up.unk0 * temp_f5_5102);
    sp38 = (MKVector3::up.unk0 * temp_f6_5100) - (MKVector3::up.unk4 * temp_f7_5105);
    sp90 = (f64) sp30;
    sp98 = (f64) sp38;
    var_f4_5131 = ((f32) sp98 * (f32) sp98) + (((f32) sp90 * (f32) sp90) + ((*(f32 *) ((u8 *) &sp88 + 0xc)) * (*(f32 *) ((u8 *) &sp88 + 0xc))));
    if (var_f4_5131 > 0.000001f) {
        if (var_f4_5131 > 0.0f) {
            temp_f1_5137 = __frsqrte(var_f4_5131);
            temp_f1_5143 = 0.5 * temp_f1_5137 * -(((f64) var_f4_5131 * (temp_f1_5137 * temp_f1_5137)) - 3.0);
            temp_f1_5147 = 0.5 * temp_f1_5143 * -(((f64) var_f4_5131 * (temp_f1_5143 * temp_f1_5143)) - 3.0);
            var_f4_5131 = (f32) ((f64) var_f4_5131 * (0.5 * temp_f1_5147 * -(((f64) var_f4_5131 * (temp_f1_5147 * temp_f1_5147)) - 3.0)));
        } else if (var_f4_5131 < M2C_BITWISE(f32, 0.0)) {
            var_f4_5131 = __float_nan;
        } else {
            sp8 = var_f4_5131;
            temp_r3_5166 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r3_5166) {                 /* switch 2; irregular */
            case 0x7F800000:                        /* switch 2 */
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_5176 = 1;
                } else {
                    var_r0_5176 = 2;
                }
                break;
            case 0x0:                               /* switch 2 */
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_5176 = 5;
                } else {
                    var_r0_5176 = 3;
                }
                break;
            default:                                /* switch 2 */
                var_r0_5176 = 4;
                break;
            }
            if (var_r0_5176 == 1) {
                var_f4_5131 = __float_nan;
            }
        }
        var_f3_5198 = 1.0f / var_f4_5131;
    } else {
        var_f3_5198 = 0.0f;
    }
    temp_r5_5210 = this->unkC;
    sp90 = (f32) sp90 * var_f3_5198;
    (*(f32 *) ((u8 *) &sp88 + 0xc)) *= var_f3_5198;
    sp98 = (f32) sp98 * var_f3_5198;
    M2C_FIELD(temp_r5_5210, f64 *, 0xE0) = (f64) sp90;
    M2C_FIELD(temp_r5_5210, f64 *, 0xE8) = (f64) sp98;
    temp_r5_5210->unk6B5 |= 0x40;
    this->unkC->SetIdleMovementSpeed(1U);
    temp_r4_5226 = this->unkC;
    M2C_FIELD(temp_r4_5226, f64 *, 0x598) = (f64) M2C_FIELD(&MKVector3::zero, f64 *, 0);
    M2C_FIELD(temp_r4_5226, f64 *, 0x5A0) = (f64) M2C_FIELD(&MKVector3::zero, f64 *, 8);
    temp_r3_5230 = this->unkC;
    if ((void *) M2C_FIELD(temp_r3_5230, void **, 0xB10) != NULL) {
        sp60 = M2C_FIELD(temp_r3_5230, f64 *, 0xC0);
        sp68 = M2C_FIELD(temp_r3_5230, f64 *, 0xC8);
        temp_f0_5240 = (f64) sp90 * 5.60222949e-315;
        sp20 = temp_f0_5240;
        sp50 = temp_f0_5240;
        sp28 = sp98 * 300.0f;
        sp58 = (f64) sp28;
        ((IceBoss *) temp_r3_5230)->SetupCameraSpline(1000.0f, 300.0f, (MKVector3) &sp60, (MKVector3) &sp50);
        M2C_FIELD(M2C_FIELD(this->unkC, void **, 0xB10), f32 *, 0xBC) = 10.0f;
        temp_r3_5262 = M2C_FIELD(this->unkC, void **, 0xB10);
        sp1C = 0;
        sp18 = 0xB5;
        M2C_FIELD(M2C_FIELD(temp_r3_5262, void **, 0x44), M2C_UNK (**)(void *, s32 *, M2C_UNK), 0x2C)(temp_r3_5262, &sp18, 0);
        M2C_FIELD(M2C_FIELD(this->unkC, void **, 0xB10), s8 *, 0xF9) = 0;
    }
    this->unkC->SetAnim((AnimSequenceType) 3, 0x20, 0, 0.15f, 4U, 0U);
    var_r30_5282 = 0;
    var_r27_5283 = 0;
    do {
        temp_r3_5289 = *(this->unkC + (var_r30_5282 + 0xF98));
        if (temp_r3_5289 != NULL) {
            sp14 = 0;
            sp10 = 0xBA;
            M2C_FIELD(M2C_FIELD(temp_r3_5289, void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp10);
        }
        var_r27_5283 += 1;
        var_r30_5282 += 4;
    } while (var_r27_5283 < 4);
    this->unk10 = 0.0f;
    temp_r3_5306 = this->unkC;
    if ((u8) M2C_FIELD((temp_r3_5306 + (M2C_FIELD(temp_r3_5306, s32 *, 0xB18) * 0x28)), u8 *, 0xE54) == 0) {
        ((IceBoss *) temp_r3_5306)->DestroyWeapon();
    }
    temp_r3_5315 = this->unkC;
    if ((u8) M2C_FIELD(temp_r3_5315, u8 *, 0xEC8) == 0) {
        ((IceBoss *) temp_r3_5315)->DestroyShield();
    }
}
#endif

void IceBossGoal_Cutscene2::Terminate() {
    Enemy *temp_r3_5351;

    this->unk8 = 1;
    this->unkC->SetInvulnerableToMeleeAttacks(0U, 1U);
    this->unkC->SetInvulnerableToBreathAttacks(0U, 1U);
    M2C_FIELD(this->unkC, s8 *, 0xFBE) = 0;
    temp_r3_5351 = this->unkC;
    if ((u8) M2C_FIELD((temp_r3_5351 + (M2C_FIELD(temp_r3_5351, s32 *, 0xB18) * 0x28)), u8 *, 0xE54) == 0) {
        ((IceBoss *) temp_r3_5351)->DestroyWeapon();
    }
    ((IceBoss *) this->unkC)->StartPhase3();
}

u8 IceBossGoal_Cutscene2::Update() {
    AnimSequence *temp_r4_5411;
    Enemy *temp_r30_5405;
    Enemy *temp_r3_5391;
    u8 var_r31_5406;

    ActivateIfInactive();
    if ((u32) M2C_FIELD(this->unkC, u32 *, 0xB10) == 0U) {
        this->unk8 = 2;
        return this->unk8;
    }
    this->unk10 += gUpdateTimeDelta;
    temp_r3_5391 = this->unkC;
    if (((u8) M2C_FIELD((temp_r3_5391 + (M2C_FIELD(temp_r3_5391, s32 *, 0xB18) * 0x28)), u8 *, 0xE54) == 0) && (this->unk10 >= 9.4333f)) {
        ((IceBoss *) temp_r3_5391)->DestroyWeapon();
    }
    temp_r30_5405 = this->unkC;
    var_r31_5406 = 0;
    if (((Character *) temp_r30_5405)->HasAnimFinished() != 0) {
        temp_r4_5411 = temp_r30_5405->unkA50;
        if ((temp_r4_5411 != NULL) && ((u32) temp_r4_5411->unk0 == (u32) M2C_FIELD(temp_r30_5405->unk630, u32 *, 0x20))) {
            var_r31_5406 = 1;
        }
    }
    if (var_r31_5406 != 0) {
        this->unk8 = 2;
    }
    return this->unk8;
}

#if 0 // DRAFT: undefined identifier '__float_nan'
void IceBossGoal_Cutscene2::Activate() {
    f64 spB0;                                       /* compiler-managed */
    f64 spA8;                                       /* compiler-managed */
    f64 spA0;                                       /* compiler-managed */
    f64 sp98;                                       /* compiler-managed */
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    MKVector3 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f32 sp40;
    f64 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    s32 sp14;
    s32 sp10;
    f32 spC;
    f32 sp8;
    Enemy *temp_r3_5720;
    Enemy *temp_r3_5762;
    Enemy *temp_r5_5698;
    Enemy *temp_r9_5708;
    f32 temp_f5_5577;
    f32 temp_f6_5580;
    f32 temp_f7_5575;
    f32 var_f2_5566;
    f32 var_f4_5499;
    f32 var_f4_5606;
    f32 var_f4_5673;
    f64 temp_f1_5467;
    f64 temp_f1_5475;
    f64 temp_f1_5505;
    f64 temp_f1_5511;
    f64 temp_f1_5515;
    f64 temp_f1_5612;
    f64 temp_f1_5618;
    f64 temp_f1_5622;
    f64 temp_f1_5692;
    s32 temp_r3_5534;
    s32 temp_r3_5641;
    s32 var_r0_5544;
    s32 var_r0_5651;
    void *temp_r3_5446;
    void *temp_r3_5474;
    void *temp_r3_5750;
    void *temp_r4_5465;

    this->unk8 = 0;
    temp_r3_5446 = M2C_FIELD(this->unkC, void **, 0xFF8);
    M2C_FIELD(M2C_FIELD(temp_r3_5446, void **, 0x44), M2C_UNK (**)(void *), 0x34)(temp_r3_5446);
    this->unkC->SetInvulnerableToMeleeAttacks(1U, 1U);
    this->unkC->SetInvulnerableToBreathAttacks(1U, 1U);
    this->unk10 = 0.0f;
    temp_r4_5465 = this->unkC->unk8;
    temp_f1_5467 = M2C_FIELD(temp_r4_5465, f64 *, 0x30);
    sp78 = temp_f1_5467;
    sp80 = M2C_FIELD(temp_r4_5465, f64 *, 0x38);
    temp_r3_5474 = M2C_FIELD(M2C_FIELD(*gb, void *(**)(void **, void *, f64), 0xC)(gb, temp_r4_5465, temp_f1_5467), void **, 8);
    temp_f1_5475 = M2C_FIELD(temp_r3_5474, f64 *, 0x30);
    sp88 = temp_f1_5475;
    sp90 = M2C_FIELD(temp_r3_5474, f64 *, 0x38);
    sp38 = temp_f1_5475 - sp78;
    spA8 = sp38;
    sp40 = (f32) sp90 - (f32) sp80;
    spB0 = (f64) sp40;
    var_f4_5499 = ((f32) spB0 * (f32) spB0) + (((f32) spA8 * (f32) spA8) + ((*(f32 *) ((u8 *) &sp90 + 0x1c)) * (*(f32 *) ((u8 *) &sp90 + 0x1c))));
    if (var_f4_5499 > 0.000001f) {
        if (var_f4_5499 > 0.0f) {
            temp_f1_5505 = __frsqrte(var_f4_5499);
            temp_f1_5511 = 0.5 * temp_f1_5505 * -(((f64) var_f4_5499 * (temp_f1_5505 * temp_f1_5505)) - 3.0);
            temp_f1_5515 = 0.5 * temp_f1_5511 * -(((f64) var_f4_5499 * (temp_f1_5511 * temp_f1_5511)) - 3.0);
            var_f4_5499 = (f32) ((f64) var_f4_5499 * (0.5 * temp_f1_5515 * -(((f64) var_f4_5499 * (temp_f1_5515 * temp_f1_5515)) - 3.0)));
        } else if (var_f4_5499 < M2C_BITWISE(f32, 0.0)) {
            var_f4_5499 = __float_nan;
        } else {
            spC = var_f4_5499;
            temp_r3_5534 = M2C_BITWISE(s32, spC) & 0x7F800000;
            switch (temp_r3_5534) {                 /* switch 1; irregular */
            case 0x7F800000:                        /* switch 1 */
                if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                    var_r0_5544 = 1;
                } else {
                    var_r0_5544 = 2;
                }
                break;
            case 0x0:                               /* switch 1 */
                if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                    var_r0_5544 = 5;
                } else {
                    var_r0_5544 = 3;
                }
                break;
            default:                                /* switch 1 */
                var_r0_5544 = 4;
                break;
            }
            if (var_r0_5544 == 1) {
                var_f4_5499 = __float_nan;
            }
        }
        var_f2_5566 = 1.0f / var_f4_5499;
    } else {
        var_f2_5566 = 0.0f;
    }
    temp_f7_5575 = (f32) spA8 * var_f2_5566;
    temp_f5_5577 = (f32) spB0 * var_f2_5566;
    temp_f6_5580 = (*(f32 *) ((u8 *) &sp90 + 0x1c)) * var_f2_5566;
    spA8 = temp_f7_5575;
    (*(f32 *) ((u8 *) &sp90 + 0x1c)) = temp_f6_5580;
    spB0 = temp_f5_5577;
    sp28 = (temp_f6_5580 * MKVector3::up.unk8) - (temp_f5_5577 * MKVector3::up.unk4);
    sp2C = (temp_f5_5577 * MKVector3::up.unk0) - (temp_f7_5575 * MKVector3::up.unk8);
    sp30 = (temp_f7_5575 * MKVector3::up.unk4) - (temp_f6_5580 * MKVector3::up.unk0);
    sp98 = (f64) sp28;
    spA0 = (f64) sp30;
    var_f4_5606 = ((f32) spA0 * (f32) spA0) + (((f32) sp98 * (f32) sp98) + ((*(f32 *) ((u8 *) &sp90 + 0xc)) * (*(f32 *) ((u8 *) &sp90 + 0xc))));
    if (var_f4_5606 > 0.000001f) {
        if (var_f4_5606 > 0.0f) {
            temp_f1_5612 = __frsqrte(var_f4_5606);
            temp_f1_5618 = 0.5 * temp_f1_5612 * -(((f64) var_f4_5606 * (temp_f1_5612 * temp_f1_5612)) - 3.0);
            temp_f1_5622 = 0.5 * temp_f1_5618 * -(((f64) var_f4_5606 * (temp_f1_5618 * temp_f1_5618)) - 3.0);
            var_f4_5606 = (f32) ((f64) var_f4_5606 * (0.5 * temp_f1_5622 * -(((f64) var_f4_5606 * (temp_f1_5622 * temp_f1_5622)) - 3.0)));
        } else if (var_f4_5606 < M2C_BITWISE(f32, 0.0)) {
            var_f4_5606 = __float_nan;
        } else {
            sp8 = var_f4_5606;
            temp_r3_5641 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r3_5641) {                 /* switch 2; irregular */
            case 0x7F800000:                        /* switch 2 */
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_5651 = 1;
                } else {
                    var_r0_5651 = 2;
                }
                break;
            case 0x0:                               /* switch 2 */
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_5651 = 5;
                } else {
                    var_r0_5651 = 3;
                }
                break;
            default:                                /* switch 2 */
                var_r0_5651 = 4;
                break;
            }
            if (var_r0_5651 == 1) {
                var_f4_5606 = __float_nan;
            }
        }
        var_f4_5673 = 1.0f / var_f4_5606;
    } else {
        var_f4_5673 = 0.0f;
    }
    sp98 = (f32) sp98 * var_f4_5673;
    (*(f32 *) ((u8 *) &sp90 + 0xc)) *= var_f4_5673;
    spA0 = (f32) spA0 * var_f4_5673;
    KDMath_Slerp(sp68, *((MKVector3 *) &spA8), 0.785398f);
    temp_f1_5692 = M2C_BITWISE(f64, sp68);
    spA8 = temp_f1_5692;
    spB0 = (f64) sp68.unk8;
    temp_r5_5698 = this->unkC;
    M2C_FIELD(temp_r5_5698, f64 *, 0xE0) = temp_f1_5692;
    M2C_FIELD(temp_r5_5698, f64 *, 0xE8) = (f64) sp68.unk8;
    temp_r5_5698->unk6B5 |= 0x40;
    this->unkC->SetIdleMovementSpeed(1U);
    temp_r9_5708 = this->unkC;
    M2C_FIELD(temp_r9_5708, f64 *, 0x598) = (f64) M2C_FIELD(&MKVector3::zero, f64 *, 0);
    M2C_FIELD(temp_r9_5708, f64 *, 0x5A0) = (f64) M2C_FIELD(&MKVector3::zero, f64 *, 8);
    this->unkC->SetAnim((AnimSequenceType) 1, 0xAB, 0, 0.15f, 4U, 0U);
    temp_r3_5720 = this->unkC;
    if ((void *) M2C_FIELD(temp_r3_5720, void **, 0xB10) != NULL) {
        sp20 = 0.0f;
        sp18 = 0.0f;
        sp1C = 200.0f;
        sp50 = (f64) sp20;
        sp48 = (f64) sp18;
        sp58 = M2C_FIELD(temp_r3_5720, f64 *, 0xC0);
        sp60 = M2C_FIELD(temp_r3_5720, f64 *, 0xC8);
        ((IceBoss *) temp_r3_5720)->SetupCameraSpline(1000.0f, 400.0f, (MKVector3) &sp58, (MKVector3) &sp48);
        M2C_FIELD(M2C_FIELD(this->unkC, void **, 0xB10), f32 *, 0xBC) = 12.0f;
        temp_r3_5750 = M2C_FIELD(this->unkC, void **, 0xB10);
        sp14 = 0;
        sp10 = 0xB5;
        M2C_FIELD(M2C_FIELD(temp_r3_5750, void **, 0x44), M2C_UNK (**)(void *, s32 *, M2C_UNK), 0x2C)(temp_r3_5750, &sp10, 0);
        M2C_FIELD(M2C_FIELD(this->unkC, void **, 0xB10), s8 *, 0xF9) = 1;
    }
    temp_r3_5762 = this->unkC;
    if ((u8) M2C_FIELD(temp_r3_5762, u8 *, 0xEC8) == 0) {
        ((IceBoss *) temp_r3_5762)->DestroyShield();
    }
}
#endif

void IceBossGoal_Cutscene1::Terminate() {
    Enemy *temp_r3_5793;

    this->unk8 = 1;
    this->unkC->SetInvulnerableToMeleeAttacks(0U, 1U);
    this->unkC->SetInvulnerableToBreathAttacks(0U, 1U);
    temp_r3_5793 = this->unkC;
    M2C_FIELD((temp_r3_5793 + (M2C_FIELD(temp_r3_5793, s32 *, 0xB18) * 0x28)), s8 *, 0xE55) = 0;
    M2C_FIELD(this->unkC, s8 *, 0xFBE) = 0;
}

u8 IceBossGoal_Cutscene1::Update() {
    AnimSequence *temp_r3_5826;
    AnimSequence *temp_r3_5879;
    AnimSequence *temp_r3_5908;
    AnimSequence *temp_r4_5838;
    AnimSequence *temp_r4_5891;
    AnimSequence *temp_r4_5920;
    Enemy *temp_r29_5817;
    Enemy *temp_r29_5878;
    Enemy *temp_r29_5907;
    u8 var_r30_5834;
    u8 var_r30_5887;
    u8 var_r30_5916;

    ActivateIfInactive();
    temp_r29_5817 = this->unkC;
    if ((u32) M2C_FIELD(temp_r29_5817, u32 *, 0xB10) == 0U) {
        this->unk8 = 2;
        return this->unk8;
    }
    temp_r3_5826 = temp_r29_5817->unkA50;
    if (((s32) temp_r3_5826->unk6C == 1) && ((s32) temp_r3_5826->unk68 == 0xAA)) {
        var_r30_5834 = 0;
        if (((Character *) temp_r29_5817)->HasAnimFinished() != 0) {
            temp_r4_5838 = temp_r29_5817->unkA50;
            if ((temp_r4_5838 != NULL) && ((u32) temp_r4_5838->unk0 == (u32) M2C_FIELD(temp_r29_5817->unk630, u32 *, 0x20))) {
                var_r30_5834 = 1;
            }
        }
        if (var_r30_5834 != 0) {
            M2C_FIELD(this->unkC, s8 *, 0xFBE) = 0;
            ((IceBoss *) this->unkC)->UpdateBodyParts();
            M2C_FIELD(this->unkC, s8 *, 0xFBE) = 1;
            this->unkC->SetAnim((AnimSequenceType) 0x12, 0xCA, 0, 0.15f, 4U, 0U);
            ((IceBoss *) this->unkC)->FormWeapon();
            this->unkC->SetAnim((AnimSequenceType) 0x12, 0xCA, 0, 0.15f, 4U, 0U);
        } else {
            goto block_10;
        }
    } else {
block_10:
        temp_r29_5878 = this->unkC;
        temp_r3_5879 = temp_r29_5878->unkA50;
        if (((s32) temp_r3_5879->unk6C == 0x12) && ((s32) temp_r3_5879->unk68 == 0xCA)) {
            var_r30_5887 = 0;
            if (((Character *) temp_r29_5878)->HasAnimFinished() != 0) {
                temp_r4_5891 = temp_r29_5878->unkA50;
                if ((temp_r4_5891 != NULL) && ((u32) temp_r4_5891->unk0 == (u32) M2C_FIELD(temp_r29_5878->unk630, u32 *, 0x20))) {
                    var_r30_5887 = 1;
                }
            }
            if (var_r30_5887 == 0) {
                ((IceBoss *) this->unkC)->UpdateFormWeapon();
            } else {
                goto block_18;
            }
        } else {
block_18:
            temp_r29_5907 = this->unkC;
            temp_r3_5908 = temp_r29_5907->unkA50;
            if (((s32) temp_r3_5908->unk6C == 0x12) && ((s32) temp_r3_5908->unk68 == 0xCA)) {
                var_r30_5916 = 0;
                if (((Character *) temp_r29_5907)->HasAnimFinished() != 0) {
                    temp_r4_5920 = temp_r29_5907->unkA50;
                    if ((temp_r4_5920 != NULL) && ((u32) temp_r4_5920->unk0 == (u32) M2C_FIELD(temp_r29_5907->unk630, u32 *, 0x20))) {
                        var_r30_5916 = 1;
                    }
                }
                if (var_r30_5916 != 0) {
                    this->unkC->SetAnim((AnimSequenceType) 1, 1, 0, 0.15f, 4U, 0U);
                    this->unk8 = 2;
                }
            }
        }
    }
    return this->unk8;
}

#if 0 // DRAFT: illegal explicit conversion from 'double *' to 'MKVector3'
void IceBossGoal_Cutscene1::Activate() {
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f64 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    s32 spC;
    s32 sp8;
    Enemy *temp_r3_5984;
    Enemy *temp_r3_6025;
    Enemy *temp_r3_6034;
    void *temp_r3_5963;
    void *temp_r3_6013;

    this->unk8 = 0;
    temp_r3_5963 = M2C_FIELD(this->unkC, void **, 0xFF8);
    M2C_FIELD(M2C_FIELD(temp_r3_5963, void **, 0x44), M2C_UNK (**)(void *), 0x34)(temp_r3_5963);
    this->unkC->SetInvulnerableToMeleeAttacks(1U, 1U);
    this->unkC->SetInvulnerableToBreathAttacks(1U, 1U);
    this->unkC->SetAnim((AnimSequenceType) 1, 0xAA, 0, 0.15f, 4U, 0U);
    temp_r3_5984 = this->unkC;
    if ((void *) M2C_FIELD(temp_r3_5984, void **, 0xB10) != NULL) {
        sp18 = 0.0f;
        sp10 = 0.0f;
        sp14 = 500.0f;
        sp28 = (f64) sp18;
        sp20 = (f64) sp10;
        sp30 = M2C_FIELD(temp_r3_5984, f64 *, 0xC0);
        sp38 = M2C_FIELD(temp_r3_5984, f64 *, 0xC8);
        ((IceBoss *) temp_r3_5984)->SetupCameraSpline(1500.0f, 500.0f, (MKVector3) &sp30, (MKVector3) &sp20);
        M2C_FIELD(M2C_FIELD(this->unkC, void **, 0xB10), f32 *, 0xBC) = 6.0f;
        temp_r3_6013 = M2C_FIELD(this->unkC, void **, 0xB10);
        spC = 0;
        sp8 = 0xB5;
        M2C_FIELD(M2C_FIELD(temp_r3_6013, void **, 0x44), M2C_UNK (**)(void *, s32 *, M2C_UNK), 0x2C)(temp_r3_6013, &sp8, 0);
        M2C_FIELD(M2C_FIELD(this->unkC, void **, 0xB10), s8 *, 0xF9) = 1;
    }
    temp_r3_6025 = this->unkC;
    if ((u8) M2C_FIELD((temp_r3_6025 + (M2C_FIELD(temp_r3_6025, s32 *, 0xB18) * 0x28)), u8 *, 0xE54) == 0) {
        ((IceBoss *) temp_r3_6025)->DestroyWeapon();
    }
    temp_r3_6034 = this->unkC;
    if ((u8) M2C_FIELD(temp_r3_6034, u8 *, 0xEC8) == 0) {
        ((IceBoss *) temp_r3_6034)->DestroyShield();
    }
}
#endif

void IceBossGoal_Think::AddGoal_CutScene() {
    s32 temp_r0_6068;
    s32 temp_r4_6056;
    s32 var_r3_6060;

    temp_r4_6056 = this->unkC;
    if (M2C_FIELD(temp_r4_6056, f32 *, 0xAC8) > 0.0f) {
        var_r3_6060 = 1;
    } else {
        var_r3_6060 = 0;
    }
    this->unk24 = M2C_FIELD(temp_r4_6056, s32 *, 0xAE8) - var_r3_6060;
    temp_r0_6068 = this->unk24;
    switch (temp_r0_6068) {                         /* irregular */
    case 0:
        if (IsPresent(0x89) == 0) {
            RemoveAllSubgoals();
            AddSubgoal((Goal<IceBoss> *) this->unk60);
            this->unk24 += 1;
            return;
        }
        return;
    case 1:
        if (IsPresent(0x8A) == 0) {
            RemoveAllSubgoals();
            AddSubgoal((Goal<IceBoss> *) this->unk64);
            this->unk24 += 1;
            return;
        }
        break;
    case 2:
        if (IsPresent(0x8B) == 0) {
            RemoveAllSubgoals();
            AddSubgoal((Goal<IceBoss> *) this->unk68);
            this->unk24 += 1;
        }
        break;
    }
}

u8 IceBossGoal_Think::AddGoal_FollowSpawnPath() {
    Goal<IceBoss> *temp_r7_6161;
    s32 temp_r3_6184;
    s32 temp_r3_6191;
    s32 temp_r4_6148;

    temp_r4_6148 = this->unkC;
    if (((u32) M2C_FIELD(temp_r4_6148, u32 *, 0xA94) != 0U) && !(((u8) M2C_FIELD(temp_r4_6148, u8 *, 0xB09) >> 4U) & 1)) {
        RemoveAllSubgoals();
        AddSubgoal((Goal<IceBoss> *) this->unk5C);
        temp_r7_6161 = this->unk5C;
        M2C_FIELD(temp_r7_6161, s32 *, 0x10) = (s32) M2C_FIELD(this->unkC, s32 *, 0xA94);
        M2C_FIELD(temp_r7_6161, f32 *, 0x14) = 0.0f;
        M2C_FIELD(temp_r7_6161, s32 *, 0x18) = 3;
        M2C_FIELD(temp_r7_6161, s32 *, 0x20) = 5;
        M2C_FIELD(temp_r7_6161, s32 *, 0x1C) = 0;
        M2C_FIELD(temp_r7_6161, u8 *, 0x24) = (u8) (M2C_FIELD(temp_r7_6161, u8 *, 0x24) & ~0x20);
        M2C_FIELD(temp_r7_6161, u8 *, 0x24) = (u8) (M2C_FIELD(temp_r7_6161, u8 *, 0x24) & ~0x10);
        M2C_FIELD(temp_r7_6161, u8 *, 0x24) = (u8) (M2C_FIELD(temp_r7_6161, u8 *, 0x24) & ~8);
        M2C_FIELD(temp_r7_6161, u8 *, 0x24) = (u8) (M2C_FIELD(temp_r7_6161, u8 *, 0x24) & ~4);
        temp_r3_6184 = this->unkC;
        M2C_FIELD(temp_r3_6184, u8 *, 0xB08) = (u8) (M2C_FIELD(temp_r3_6184, u8 *, 0xB08) | 0x40);
        ((KDPathIterator *) (this->unkC + 0xA94))->Init();
        temp_r3_6191 = this->unkC;
        M2C_FIELD(temp_r3_6191, u8 *, 0xB09) = (u8) (M2C_FIELD(temp_r3_6191, u8 *, 0xB09) | 0x10);
    }
    return ((u8) M2C_FIELD(this->unkC, u8 *, 0xB09) >> 4U) & 1;
}

void IceBossGoal_Think::AddGoal_AttackPhase3() {
    if (IsPresent(0x83) == 0) {
        RemoveAllSubgoals();
        AddSubgoal((Goal<IceBoss> *) this->unk48);
    }
}

void IceBossGoal_Think::AddGoal_AttackPhase2() {
    if (IsPresent(0x82) == 0) {
        RemoveAllSubgoals();
        AddSubgoal((Goal<IceBoss> *) this->unk44);
    }
}

void IceBossGoal_Think::AddGoal_AttackPhase1() {
    Goal<IceBoss> *temp_r6_6290;

    if (IsPresent(0x81) == 0) {
        RemoveAllSubgoals();
        if ((u8) this->unk21 != 0) {
            this->unk21 = 0;
            AddSubgoal((Goal<IceBoss> *) this->unk28);
            temp_r6_6290 = this->unk28;
            M2C_FIELD(temp_r6_6290, s32 *, 0x10) = (s32) (this->unkC + 0x870);
            M2C_FIELD(temp_r6_6290, s32 *, 0x14) = 1;
            M2C_FIELD(temp_r6_6290, s32 *, 0x18) = 3;
            M2C_FIELD(temp_r6_6290, s32 *, 0x1C) = 0;
            M2C_FIELD(temp_r6_6290, u8 *, 0x20) = (u8) (M2C_FIELD(temp_r6_6290, u8 *, 0x20) & ~0x40);
        }
        AddSubgoal((Goal<IceBoss> *) this->unk40);
    }
}

void IceBossGoal_Think::AddGoal_SummonWeapon() {
    if (IsPresent(0x80) == 0) {
        RemoveAllSubgoals();
        AddSubgoal((Goal<IceBoss> *) this->unk3C);
    }
}

void IceBossGoal_Think::AddGoal_FormShield() {
    if (IsPresent(0x7F) == 0) {
        RemoveAllSubgoals();
        AddSubgoal((Goal<IceBoss> *) this->unk38);
    }
}

void IceBossGoal_Think::AddGoal_FormWeapon() {
    if (IsPresent(0x7E) == 0) {
        RemoveAllSubgoals();
        AddSubgoal((Goal<IceBoss> *) this->unk34);
    }
}

void IceBossGoal_Think::AddGoal_Death(EnemyDamageFeedback *arg0) {
    if (IsPresent(0x5B) == 0) {
        RemoveAllSubgoals();
        AddSubgoal((Goal<IceBoss> *) this->unk30);
    }
}

#if 0 // DRAFT: pointer/array required
void IceBossGoal_Think::AddGoal_Hit(EnemyDamageFeedback *arg0) {
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    M2C_UNK sp8;
    f64 temp_f0_6463;
    f64 temp_f0_6475;
    s32 temp_r0_6434;
    s32 temp_r0_6525;
    s32 temp_r28_6459;
    s32 temp_r4_6549;
    u8 var_r29_6481;

    temp_r0_6434 = arg0->unk28;
    switch (temp_r0_6434) {                         /* irregular */
    case 11:
    case 2:
        arg0->unk28 = 0;
        break;
    default:
    case 3:
        arg0->unk28 = 1;
        break;
    }
    if ((s32) arg0->unk28 == 1) {
        temp_r28_6459 = this->unkC;
        temp_f0_6463 = *(temp_r28_6459 + 0xC0) * 5.64367472e-315;
        sp28 = temp_f0_6463;
        sp38 = temp_f0_6463;
        sp30 = M2C_FIELD(temp_r28_6459, f32 *, 0xC8) * 600.0f;
        sp40 = (f64) sp30;
        temp_f0_6475 = *(temp_r28_6459 + 0x588) - temp_f0_6463;
        sp18 = temp_f0_6475;
        var_r29_6481 = 0;
        sp48 = temp_f0_6475;
        sp20 = M2C_FIELD(temp_r28_6459, f32 *, 0x590) - (f32) sp40;
        sp50 = (f64) sp20;
        if (((EnemyRegion *) (temp_r28_6459 + 0x800))->IsPointWithin(*((MKVector3 *) &sp48)) != 0) {
            ((EnemyRegion *) &sp8)->GetRegionPos();
            if ((f32) fabs(spC - (*(f32 *) ((u8 *) &sp48 + 0x4))) <= 500.0f) {
                var_r29_6481 = 1;
            }
        }
        if ((var_r29_6481 == 0) || (((EnemyRegion *) (this->unkC + 0x838))->IsPointWithin(*((MKVector3 *) &sp48)) != 0)) {
            arg0->unk28 = 0;
        }
    }
    if (IsActive(0x59) != 0) {
        temp_r0_6525 = arg0->unk28;
        if ((temp_r0_6525 != 0) && ((temp_r0_6525 != 1) || (IsActive(0xA) == 0))) {
            if (IsActive(0x12) != 0) {
                return;
            }
            goto block_23;
        }
    } else {
block_23:
        temp_r4_6549 = this->unkC;
        M2C_FIELD(temp_r4_6549, f64 *, 0x910) = (f64) arg0->unk0;
        M2C_FIELD(temp_r4_6549, f64 *, 0x918) = (f64) arg0->unk8;
        M2C_FIELD(temp_r4_6549, s32 *, 0x920) = (s32) arg0->unk10;
        M2C_FIELD(temp_r4_6549, s32 *, 0x924) = (s32) arg0->unk14;
        M2C_FIELD(temp_r4_6549, f32 *, 0x928) = (f32) arg0->unk18;
        M2C_FIELD(temp_r4_6549, f32 *, 0x92C) = (f32) arg0->unk1C;
        M2C_FIELD(temp_r4_6549, s32 *, 0x930) = (s32) arg0->unk20;
        M2C_FIELD(temp_r4_6549, f32 *, 0x934) = (f32) arg0->unk24;
        M2C_FIELD(temp_r4_6549, s32 *, 0x938) = (s32) arg0->unk28;
        M2C_FIELD(temp_r4_6549, s32 *, 0x93C) = (s32) arg0->unk2C;
        M2C_FIELD(temp_r4_6549, s32 *, 0x940) = (s32) arg0->unk30;
        M2C_FIELD(temp_r4_6549, u8 *, 0x944) = (u8) arg0->unk34;
        M2C_FIELD(this->unkC, f32 *, 0x928) = 0.0f;
        RemoveAllSubgoals();
        AddSubgoal((Goal<IceBoss> *) this->unk2C);
    }
}
#endif

#if 0 // DRAFT: pointer/array required
u8 IceBossGoal_Think::HasToSummonWeapon() {
    s32 temp_r3_6604;
    s32 temp_r4_6602;

    if (((IceBoss *) this->unkC)->GetPhase() == 2) {
        temp_r4_6602 = this->unkC;
        temp_r3_6604 = M2C_FIELD(temp_r4_6602, s32 *, 0xB18) * 0x28;
        if (((u8) *(temp_r4_6602 + (temp_r3_6604 + 0xE54)) != 0) && ((u8) *(temp_r4_6602 + (temp_r3_6604 + 0xE55)) == 0)) {
            return 1U;
        }
    }
    return 0U;
}
#endif

u8 IceBossGoal_Think::HasToFormShield() {
    s32 temp_r4_6637;

    if (((IceBoss *) this->unkC)->GetPhase() == 0) {
        temp_r4_6637 = this->unkC;
        if (((u8) M2C_FIELD(temp_r4_6637, u8 *, 0xEC8) != 0) && ((u8) M2C_FIELD(temp_r4_6637, u8 *, 0xEC9) == 0) && (M2C_FIELD(&gb, f32 *, 0x30C) >= M2C_FIELD(temp_r4_6637, f32 *, 0xFCC))) {
            return 1U;
        }
    }
    return 0U;
}

#if 0 // DRAFT: pointer/array required
u8 IceBossGoal_Think::HasToFormWeapon() {
    s32 temp_r3_6677;
    s32 temp_r4_6675;

    if (((IceBoss *) this->unkC)->GetPhase() < 2) {
        temp_r4_6675 = this->unkC;
        temp_r3_6677 = M2C_FIELD(temp_r4_6675, s32 *, 0xB18) * 0x28;
        if (((u8) *(temp_r4_6675 + (temp_r3_6677 + 0xE54)) != 0) && ((u8) *(temp_r4_6675 + (temp_r3_6677 + 0xE55)) == 0) && (M2C_FIELD(&gb, f32 *, 0x30C) >= M2C_FIELD(temp_r4_6675, f32 *, 0xFC8))) {
            return 1U;
        }
    }
    return 0U;
}
#endif

#if 0 // DRAFT: pointer/array required
u8 IceBossGoal_Think::Update() {
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    M2C_UNK sp8;
    f64 temp_f0_6759;
    f64 temp_f0_6771;
    s32 temp_r29_6755;
    s32 temp_r3_6722;
    s32 temp_r3_6810;
    s32 temp_r3_6815;
    s32 temp_r3_6823;
    s32 temp_r3_6828;
    u8 var_r30_6777;

    if (((Enemy *) this->unkC)->WasHit() != 0) {
        this->unk8 = 1;
    }
    temp_r3_6722 = this->unkC;
    if (M2C_FIELD(M2C_FIELD(temp_r3_6722, void **, 0x44), u8 (**)(s32), 0xE8)(temp_r3_6722) == 0) {
        ((Enemy *) this->unkC)->SelectTarget();
    }
    ActivateIfInactive();
    if ((u8) M2C_FIELD(this->unkC, u8 *, 0xFBD) != 0) {
        AddGoal_FormWeapon();
        M2C_FIELD(this->unkC, u8 *, 0xFBD) = 0U;
    }
    this->unk8 = UpdateSubgoals();
    if (IsActive(0x12) != 0) {
        temp_r29_6755 = this->unkC;
        temp_f0_6759 = *(temp_r29_6755 + 0xC0) * 5.64367472e-315;
        sp28 = temp_f0_6759;
        sp38 = temp_f0_6759;
        sp30 = M2C_FIELD(temp_r29_6755, f32 *, 0xC8) * 600.0f;
        sp40 = (f64) sp30;
        temp_f0_6771 = *(temp_r29_6755 + 0x588) - temp_f0_6759;
        sp18 = temp_f0_6771;
        var_r30_6777 = 0;
        sp48 = temp_f0_6771;
        sp20 = M2C_FIELD(temp_r29_6755, f32 *, 0x590) - (f32) sp40;
        sp50 = (f64) sp20;
        if (((EnemyRegion *) (temp_r29_6755 + 0x800))->IsPointWithin(*((MKVector3 *) &sp48)) != 0) {
            ((EnemyRegion *) &sp8)->GetRegionPos();
            if ((f32) fabs(spC - (*(f32 *) ((u8 *) &sp48 + 0x4))) <= 500.0f) {
                var_r30_6777 = 1;
            }
        }
        if ((var_r30_6777 == 0) || (((EnemyRegion *) (this->unkC + 0x838))->IsPointWithin(*((MKVector3 *) &sp48)) != 0)) {
            temp_r3_6810 = this->unkC;
            M2C_FIELD(temp_r3_6810, f32 *, 0x80) = 0.0f;
            M2C_FIELD(temp_r3_6810, f32 *, 0x84) = 0.0f;
            M2C_FIELD(temp_r3_6810, f32 *, 0x88) = 0.0f;
            temp_r3_6815 = this->unkC;
            M2C_FIELD(temp_r3_6815, f32 *, 0x90) = 0.0f;
            M2C_FIELD(temp_r3_6815, f32 *, 0x94) = 0.0f;
            M2C_FIELD(temp_r3_6815, f32 *, 0x98) = 0.0f;
        }
    }
    if ((u8) this->unk8 == 2) {
        temp_r3_6823 = this->unkC;
        M2C_FIELD(temp_r3_6823, u8 *, 0xB09) = (u8) (M2C_FIELD(temp_r3_6823, u8 *, 0xB09) & ~0x10);
        temp_r3_6828 = this->unkC;
        if (!(((u8) M2C_FIELD(temp_r3_6828, u8 *, 0xB09) >> 7U) & 1)) {
            M2C_FIELD(M2C_FIELD(temp_r3_6828, void **, 0x44), M2C_UNK (**)(), 0x34)();
            return (u8) this->unk8;
        }
    }
    if ((u8) this->unk8 != 0) {
        Activate();
    }
    return (u8) this->unk8;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'unsigned char *' to 'bool *'
void IceBossGoal_Think::Arbitrate() {
    f32 spAC;
    f32 spA8;
    f32 spA4;
    f32 spA0;
    f32 sp9C;
    f32 sp98;
    f32 sp94;
    f32 sp90;
    f32 sp7C;
    f32 sp78;
    f32 sp74;
    f32 sp70;
    EnemyDamageFeedback sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    u8 sp10;
    f32 temp_f1_6897;
    f32 temp_f1_6927;
    f32 temp_f5_6903;
    f32 temp_f6_6890;
    s32 temp_r3_6886;
    s32 temp_r3_7002;
    s32 temp_r3_7020;
    s32 temp_r3_7118;
    s32 temp_r3_7226;
    u8 var_r29_7136;
    u8 var_r30_7073;
    u8 var_r30_7137;
    u8 var_r30_7185;
    u8 var_r4_7167;
    u8 var_r5_7168;
    void **temp_r3_7076;
    void **temp_r3_7083;
    void **temp_r3_7135;
    void **temp_r3_7144;
    void *temp_r3_7169;

    if (((((u8) M2C_FIELD(this->unkC, u8 *, 0xB09) >> 7U) & 1) || (M2C_STRUCT_COPY((s32) &sp38.unk34 + 4, (s32) (&Matrix::identity - 4) + 4, 0x40), temp_r3_6886 = this->unkC, temp_f6_6890 = M2C_FIELD(temp_r3_6886, f32 *, 0x5C8), sp90 = temp_f6_6890, temp_f1_6897 = M2C_FIELD(temp_r3_6886, f32 *, 0x5CC), sp94 = temp_f1_6897, temp_f5_6903 = M2C_FIELD(temp_r3_6886, f32 *, 0x5D0), sp20 = (MKVector3::up.unk0 * temp_f1_6897) - (MKVector3::up.unk4 * temp_f6_6890), sp98 = temp_f5_6903, sp30 = (f64) sp20, sp18 = (MKVector3::up.unk4 * temp_f5_6903) - (MKVector3::up.unk8 * temp_f1_6897), sp1C = (MKVector3::up.unk8 * temp_f6_6890) - (MKVector3::up.unk0 * temp_f5_6903), sp9C = 0.0f, sp28 = (f64) sp18, sp70 = (f32) sp28, sp74 = (*(f32 *) ((u8 *) &sp28 + 0x4)), sp78 = (f32) sp30, sp7C = 0.0f, spA0 = M2C_FIELD(temp_r3_6886, f32 *, 0x5B8), spA4 = M2C_FIELD(temp_r3_6886, f32 *, 0x5BC), temp_f1_6927 = M2C_FIELD(temp_r3_6886, f32 *, 0x5C0), spA8 = temp_f1_6927, spAC = 1.0f, ((M2C_FIELD(M2C_FIELD(temp_r3_6886, void **, 0x44), u8 (**)(s32, f32 *, M2C_UNK, MKVector3 *, f32, f32, f32, f32, f32, f32, f32, f32), 0x120)(temp_r3_6886, &sp70, 0, &MKVector3::up, temp_f1_6927, (*(f32 *) ((u8 *) &sp28 + 0x4)), (f32) sp28, 0.0f, temp_f5_6903, temp_f6_6890, MKVector3::up.unk8, MKVector3::up.unk4) == 0) == 0))) && (AddGoal_FollowSpawnPath() == 0)) {
        if (((Enemy *) this->unkC)->WasHit() != 0) {
            sp10 = 0;
            ((IceBoss *) this->unkC)->InterceptDamage(&sp10);
            sp38.Init();
            ((Enemy *) this->unkC)->TakeDamage(&sp38, 0U);
            if ((sp38.unk24 != 0.0f) && (KDSound_IsVoicePlaying(M2C_FIELD(this->unkC, s32 *, 0x1010)) == 0) && (((MKAnimScript *) (M2C_FIELD(this->unkC, MKAnimScript **, 0x630)))->CheckEvent(0xC) == 0)) {
                if (((IceBoss *) this->unkC)->IsIceKing() != 0) {
                    M2C_FIELD(this->unkC, s32 *, 0x1010) = KDSound_Play3d(GS_IceBossFlinch1, M2C_FIELD(this->unkC, s32 *, 8) + 0x30, 0U, -1, 0.0f, 0U);
                } else {
                    M2C_FIELD(this->unkC, s32 *, 0x1010) = KDSound_Play3d(GS_ElecBossFlinch1, M2C_FIELD(this->unkC, s32 *, 8) + 0x30, 0U, -1, 0.0f, 0U);
                }
            }
            ((IceBoss *) this->unkC)->TryChangeStage();
            temp_r3_7002 = this->unkC;
            if ((u8) M2C_FIELD(temp_r3_7002, u8 *, 0xFBE) != 0) {
                AddGoal_CutScene();
                return;
            }
            if ((((IceBoss *) temp_r3_7002)->IsIceKing() == 0) || !(M2C_FIELD(this->unkC, f32 *, 0xAC8) <= 0.0f)) {
                temp_r3_7020 = this->unkC;
                if (M2C_FIELD(temp_r3_7020, f32 *, 0xAC8) <= 0.0f) {
                    ((Enemy *) temp_r3_7020)->ClearHitAndDeathFX();
                    AddGoal_Death(&sp38);
                    ((EventMessage *) (this->unkC + 0xFEC))->Send(NULL);
                    return;
                }
                if (((sp38.unk34 >> 5U) & 1) && (M2C_FIELD(temp_r3_7020, f32 *, 0xAD0) <= 0.0f) && ((u8) M2C_FIELD(temp_r3_7020, u8 *, 0xEC8) == 0)) {
                    ((IceBoss *) temp_r3_7020)->DestroyShield();
                }
                if (sp10 != 0) {
                    sp38.unk28 = 7;
                    ((IceBoss *) this->unkC)->EnableWeaponCollision(0U);
                    ((IceBoss *) this->unkC)->DestroyWeapon();
                }
                if ((sp38.unk28 == 4) || (sp38.unk28 == 5)) {
                    sp38.unk28 = 0xE;
                }
                if (((IceBoss *) this->unkC)->IsIceKing() == 0) {
                    var_r30_7073 = 0;
                    M2C_FIELD(this->unkC, f32 *, 0xFC8) = 0.0f;
                    temp_r3_7076 = this->unk4C;
                    if ((M2C_FIELD(*temp_r3_7076, u8 (**)(void **), 0x28)(temp_r3_7076) != 0) || (temp_r3_7083 = this->unk50, ((M2C_FIELD(*temp_r3_7083, u8 (**)(void **), 0x28)(temp_r3_7083) == 0) == 0)) || (IsActive(0x3A) != 0)) {
                        var_r30_7073 = 1;
                    }
                    if ((var_r30_7073 == 0) && (HasToFormWeapon() != 0)) {
                        sp38.unk28 = 0xE;
                    }
                }
                if (sp38.unk28 != 0xE) {
                    AddGoal_Hit(&sp38);
                    return;
                }
                goto block_35;
            }
        } else {
block_35:
            temp_r3_7118 = this->unkC;
            if (((u8) *(temp_r3_7118 + ((M2C_FIELD(temp_r3_7118, s32 *, 0xB18) * 0x28) + 0xE55)) == 0) && ((u8) M2C_FIELD(temp_r3_7118, u8 *, 0xEC9) == 0) && (((Enemy *) temp_r3_7118)->IsFlinching(), (((u8) M2C_ERROR(/* Read from unset register $r3 */) == 0) != 0)) && ((u8) M2C_FIELD(this->unkC, u8 *, 0xFBE) == 0)) {
                temp_r3_7135 = this->unk4C;
                var_r29_7136 = 1;
                var_r30_7137 = 0;
                if ((M2C_FIELD(*temp_r3_7135, u8 (**)(void **), 0x28)(temp_r3_7135) != 0) || (temp_r3_7144 = this->unk50, ((M2C_FIELD(*temp_r3_7144, u8 (**)(void **), 0x28)(temp_r3_7144) == 0) == 0))) {
                    var_r30_7137 = 1;
                }
                if ((var_r30_7137 == 0) && (IsActive(0x3A) == 0)) {
                    var_r29_7136 = 0;
                }
                var_r4_7167 = 0;
                var_r5_7168 = 0;
                temp_r3_7169 = M2C_FIELD(this->unkC, void **, 0xA50);
                if ((temp_r3_7169 != NULL) && ((s32) M2C_FIELD(temp_r3_7169, s32 *, 0x6C) == 1)) {
                    var_r5_7168 = 1;
                }
                if ((var_r5_7168 != 0) && ((s32) M2C_FIELD(temp_r3_7169, s32 *, 0x68) == 3)) {
                    var_r4_7167 = 1;
                }
                var_r30_7185 = 0;
                if ((var_r29_7136 != 0) || (var_r4_7167 != 0) || ((u8) this->unk21 != 0)) {
                    var_r30_7185 = 1;
                }
                if ((var_r30_7185 == 0) && (HasToFormWeapon() != 0)) {
                    AddGoal_FormWeapon();
                    return;
                }
                if ((var_r30_7185 == 0) && (HasToFormShield() != 0)) {
                    AddGoal_FormShield();
                    return;
                }
                if ((var_r30_7185 == 0) && (HasToSummonWeapon() != 0)) {
                    AddGoal_SummonWeapon();
                    return;
                }
                temp_r3_7226 = ((IceBoss *) this->unkC)->GetPhase();
                switch (temp_r3_7226) {             /* irregular */
                case 0:
                    AddGoal_AttackPhase1();
                    return;
                case 1:
                    AddGoal_AttackPhase2();
                    return;
                case 2:
                    AddGoal_AttackPhase3();
                    break;
                }
            }
        }
    }
}
#endif

void IceBossGoal_Think::Activate() {
    this->unk8 = 0;
    Arbitrate();
}

void IceBossGoal_Think::Reset() {
    this->unk8 = 1;
    RemoveAllSubgoals();
    this->unk20 = 1;
    this->unk21 = ((IceBoss *) this->unkC)->IsIceKing() == 0;
    M2C_FIELD(this->unkC, s8 *, 0xFBE) = 0;
    this->unk24 = 0;
}

void IceBossGoal_Think::Deinit() {
    Goal<IceBoss> *temp_r3_7313;
    Goal<IceBoss> *temp_r3_7318;
    Goal<IceBoss> *temp_r3_7323;
    Goal<IceBoss> *temp_r3_7328;
    Goal<IceBoss> *temp_r3_7333;
    Goal<IceBoss> *temp_r3_7338;
    Goal<IceBoss> *temp_r3_7343;
    Goal<IceBoss> *temp_r3_7348;
    Goal<IceBoss> *temp_r3_7353;
    Goal<IceBoss> *temp_r3_7378;
    Goal<IceBoss> *temp_r3_7383;
    Goal<IceBoss> *temp_r3_7388;
    Goal<IceBoss> *temp_r3_7393;
    s32 temp_r31_7432;
    void **temp_r3_7358;
    void **temp_r3_7363;
    void **temp_r3_7368;
    void **temp_r3_7373;

    temp_r3_7313 = this->unk28;
    temp_r3_7313->Deinit();
    temp_r3_7318 = this->unk2C;
    temp_r3_7318->Deinit();
    temp_r3_7323 = this->unk30;
    temp_r3_7323->Deinit();
    temp_r3_7328 = this->unk34;
    temp_r3_7328->Deinit();
    temp_r3_7333 = this->unk38;
    temp_r3_7333->Deinit();
    temp_r3_7338 = this->unk3C;
    temp_r3_7338->Deinit();
    temp_r3_7343 = this->unk40;
    temp_r3_7343->Deinit();
    temp_r3_7348 = this->unk44;
    temp_r3_7348->Deinit();
    temp_r3_7353 = this->unk48;
    temp_r3_7353->Deinit();
    temp_r3_7358 = this->unk4C;
    M2C_FIELD(*temp_r3_7358, M2C_UNK (**)(void **), 0xC)(temp_r3_7358);
    temp_r3_7363 = this->unk50;
    M2C_FIELD(*temp_r3_7363, M2C_UNK (**)(void **), 0xC)(temp_r3_7363);
    temp_r3_7368 = this->unk54;
    M2C_FIELD(*temp_r3_7368, M2C_UNK (**)(void **), 0xC)(temp_r3_7368);
    temp_r3_7373 = this->unk58;
    M2C_FIELD(*temp_r3_7373, M2C_UNK (**)(void **), 0xC)(temp_r3_7373);
    temp_r3_7378 = this->unk5C;
    temp_r3_7378->Deinit();
    temp_r3_7383 = this->unk60;
    temp_r3_7383->Deinit();
    temp_r3_7388 = this->unk64;
    temp_r3_7388->Deinit();
    temp_r3_7393 = this->unk68;
    temp_r3_7393->Deinit();
    operator delete(this->unk28);
    operator delete(this->unk2C);
    operator delete(this->unk30);
    operator delete(this->unk34);
    operator delete(this->unk38);
    operator delete(this->unk3C);
    operator delete(this->unk40);
    operator delete(this->unk44);
    operator delete(this->unk48);
    operator delete(this->unk4C);
    operator delete(this->unk50);
    operator delete(this->unk54);
    operator delete(this->unk58);
    operator delete(this->unk5C);
    operator delete(this->unk60);
    operator delete(this->unk64);
    operator delete(this->unk68);
    temp_r31_7432 = this->unk1C;
    if ((u32) temp_r31_7432 != 0U) {
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free((void *) temp_r31_7432, NULL, 0);
        } else {
            free((void *) temp_r31_7432);
        }
        this->unk1C = 0;
    }
    this->unk10 = 0;
    this->unk18 = 0;
    this->unk14 = 0;
    this->unk8 = 1;
    this->unkC = 0;
    this->unk9 = 0;
    M2C_FIELD(&gb, s32 *, 0x360) = 0;
}

#if 0 // DRAFT: pointer/array required
void IceBossGoal_Think::Init(IceBoss *arg0) {
    Goal<IceBoss> *temp_r4_7887;
    Goal<IceBoss> *temp_r4_7904;
    Goal<IceBoss> *temp_r4_7915;
    Goal<IceBoss> *temp_r4_7926;
    Goal<IceBoss> *temp_r4_7990;
    Goal<IceBoss> *temp_r4_8001;
    Goal<IceBoss> *temp_r4_8012;
    Goal<IceBoss> *temp_r4_8023;
    void **temp_r4_7946;
    void **temp_r4_7957;
    void **temp_r4_7968;
    void **temp_r4_7979;
    void *var_r3_7867;

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
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__14Goal<7IceBoss>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk34 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x10U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__14Goal<7IceBoss>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk38 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x10U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__14Goal<7IceBoss>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk3C = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x3CU, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__14Goal<7IceBoss>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__23CompositeGoal<7IceBoss>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x1C) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x18) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x10) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x14) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk40 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x38U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__14Goal<7IceBoss>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__23CompositeGoal<7IceBoss>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x1C) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x18) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x10) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x14) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk44 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x3CU, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__14Goal<7IceBoss>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__23CompositeGoal<7IceBoss>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x1C) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x18) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x10) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x14) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk48 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x10U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__14Goal<7IceBoss>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk4C = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x14U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__14Goal<7IceBoss>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk50 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x68U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__14Goal<7IceBoss>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk54 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x14U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__14Goal<7IceBoss>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk58 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x28U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk5C = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x10U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__14Goal<7IceBoss>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk60 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x14U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__14Goal<7IceBoss>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk64 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x14U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__14Goal<7IceBoss>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk68 = M2C_ERROR(/* Read from unset register $r3 */);
    }
    if ((u8) this->unk9 == 0) {
        if (MKHeap::Current() != NULL) {
            var_r3_7867 = ((MKHeap *) (MKHeap::Current()))->Alloc(0x14, NULL, 0);
        } else {
            var_r3_7867 = malloc(0x14);
        }
        this->unk1C = (s32) var_r3_7867;
        this->unk10 = 5;
    }
    this->unk8 = 1;
    this->unkC = (s32) arg0;
    this->unk4 = 0x7D;
    if ((u32) this->unkC != 0U) {
        this->unk9 = 1;
    }
    temp_r4_7887 = this->unk28;
    M2C_FIELD(temp_r4_7887, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_7887, IceBoss **, 0xC) = arg0;
    M2C_FIELD(temp_r4_7887, s32 *, 4) = 0;
    if ((IceBoss *) M2C_FIELD(temp_r4_7887, IceBoss **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_7887, s8 *, 9) = 1;
    }
    ((EnemyGoal_Hit *) this->unk2C)->Init((Enemy *) arg0);
    ((EnemyGoal_Death *) this->unk30)->Init((Enemy *) arg0);
    temp_r4_7904 = this->unk34;
    M2C_FIELD(temp_r4_7904, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_7904, IceBoss **, 0xC) = arg0;
    M2C_FIELD(temp_r4_7904, s32 *, 4) = 0x7E;
    if ((IceBoss *) M2C_FIELD(temp_r4_7904, IceBoss **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_7904, s8 *, 9) = 1;
    }
    temp_r4_7915 = this->unk38;
    M2C_FIELD(temp_r4_7915, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_7915, IceBoss **, 0xC) = arg0;
    M2C_FIELD(temp_r4_7915, s32 *, 4) = 0x7F;
    if ((IceBoss *) M2C_FIELD(temp_r4_7915, IceBoss **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_7915, s8 *, 9) = 1;
    }
    temp_r4_7926 = this->unk3C;
    M2C_FIELD(temp_r4_7926, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_7926, IceBoss **, 0xC) = arg0;
    M2C_FIELD(temp_r4_7926, s32 *, 4) = 0x80;
    if ((IceBoss *) M2C_FIELD(temp_r4_7926, IceBoss **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_7926, s8 *, 9) = 1;
    }
    ((IceBossGoal_AttackPhase1 *) this->unk40)->Init(arg0);
    ((IceBossGoal_AttackPhase2 *) this->unk44)->Init(arg0);
    ((IceBossGoal_AttackPhase3 *) this->unk48)->Init(arg0);
    temp_r4_7946 = this->unk4C;
    M2C_FIELD(temp_r4_7946, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_7946, IceBoss **, 0xC) = arg0;
    M2C_FIELD(temp_r4_7946, s32 *, 4) = 0x88;
    if ((IceBoss *) M2C_FIELD(temp_r4_7946, IceBoss **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_7946, s8 *, 9) = 1;
    }
    temp_r4_7957 = this->unk50;
    M2C_FIELD(temp_r4_7957, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_7957, IceBoss **, 0xC) = arg0;
    M2C_FIELD(temp_r4_7957, s32 *, 4) = 0x87;
    if ((IceBoss *) M2C_FIELD(temp_r4_7957, IceBoss **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_7957, s8 *, 9) = 1;
    }
    temp_r4_7968 = this->unk54;
    M2C_FIELD(temp_r4_7968, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_7968, IceBoss **, 0xC) = arg0;
    M2C_FIELD(temp_r4_7968, s32 *, 4) = 0x84;
    if ((IceBoss *) M2C_FIELD(temp_r4_7968, IceBoss **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_7968, s8 *, 9) = 1;
    }
    temp_r4_7979 = this->unk58;
    M2C_FIELD(temp_r4_7979, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_7979, IceBoss **, 0xC) = arg0;
    M2C_FIELD(temp_r4_7979, s32 *, 4) = 0x85;
    if ((IceBoss *) M2C_FIELD(temp_r4_7979, IceBoss **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_7979, s8 *, 9) = 1;
    }
    temp_r4_7990 = this->unk5C;
    M2C_FIELD(temp_r4_7990, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_7990, IceBoss **, 0xC) = arg0;
    M2C_FIELD(temp_r4_7990, s32 *, 4) = 0x22;
    if ((IceBoss *) M2C_FIELD(temp_r4_7990, IceBoss **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_7990, s8 *, 9) = 1;
    }
    temp_r4_8001 = this->unk60;
    M2C_FIELD(temp_r4_8001, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_8001, IceBoss **, 0xC) = arg0;
    M2C_FIELD(temp_r4_8001, s32 *, 4) = 0x89;
    if ((IceBoss *) M2C_FIELD(temp_r4_8001, IceBoss **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_8001, s8 *, 9) = 1;
    }
    temp_r4_8012 = this->unk64;
    M2C_FIELD(temp_r4_8012, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_8012, IceBoss **, 0xC) = arg0;
    M2C_FIELD(temp_r4_8012, s32 *, 4) = 0x8A;
    if ((IceBoss *) M2C_FIELD(temp_r4_8012, IceBoss **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_8012, s8 *, 9) = 1;
    }
    temp_r4_8023 = this->unk68;
    M2C_FIELD(temp_r4_8023, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_8023, IceBoss **, 0xC) = arg0;
    M2C_FIELD(temp_r4_8023, s32 *, 4) = 0x8B;
    if ((IceBoss *) M2C_FIELD(temp_r4_8023, IceBoss **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_8023, s8 *, 9) = 1;
    }
    M2C_FIELD(this->unk40, Goal<IceBoss> **, 0x20) = (Goal<IceBoss> *) this->unk28;
    M2C_FIELD(this->unk44, Goal<IceBoss> **, 0x20) = (Goal<IceBoss> *) this->unk28;
    M2C_FIELD(this->unk48, Goal<IceBoss> **, 0x20) = (Goal<IceBoss> *) this->unk28;
    M2C_FIELD(this->unk40, void ***, 0x24) = (void **) this->unk54;
    M2C_FIELD(this->unk44, void ***, 0x24) = (void **) this->unk54;
    M2C_FIELD(this->unk48, void ***, 0x24) = (void **) this->unk54;
    M2C_FIELD(this->unk40, void ***, 0x28) = (void **) this->unk58;
    M2C_FIELD(this->unk44, void ***, 0x28) = (void **) this->unk58;
    M2C_FIELD(this->unk48, void ***, 0x28) = (void **) this->unk58;
    M2C_FIELD(this->unk40, void ***, 0x2C) = (void **) this->unk4C;
    M2C_FIELD(this->unk44, void ***, 0x2C) = (void **) this->unk4C;
    M2C_FIELD(this->unk48, void ***, 0x2C) = (void **) this->unk4C;
    M2C_FIELD(this->unk40, void ***, 0x30) = (void **) this->unk50;
    M2C_FIELD(this->unk44, void ***, 0x30) = (void **) this->unk50;
    M2C_FIELD(this->unk48, void ***, 0x30) = (void **) this->unk50;
}
#endif
