#include "spyro/source/Enemies_Fire.h"
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
#include "spyro/source/AssaultCannon.h"
#include "spyro/source/BoneBlurFX.h"
#include "spyro/source/Character.h"
#include "spyro/source/CharacterBodyFX.h"
#include "spyro/source/CharacterBreathFX.h"
#include "spyro/source/CharacterFireFX.h"
#include "spyro/source/CharacterGraph.h"
#include "spyro/source/CharacterZapFX.h"
#include "spyro/source/CollisionObject.h"
#include "spyro/source/CrashFirePS.h"
#include "spyro/source/Crate.h"
#include "spyro/source/Enemy.h"
#include "spyro/source/EnemyAttackPattern.h"
#include "spyro/source/EnemyDataTypes.h"
#include "spyro/source/EnemyDescriptor.h"
#include "spyro/source/EnemyGoal_Think.h"
#include "spyro/source/EnemyRegion.h"
#include "spyro/source/EnemySettings.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/FireTier1Goal_Think.h"
#include "spyro/source/FireTier2Goal_Think.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/GlowingPropManager.h"
#include "spyro/source/Goal.h"
#include "spyro/source/GoopFX.h"
#include "spyro/source/IceBitsPS.h"
#include "spyro/source/KDMatrixRefProperty.h"
#include "spyro/source/KDPath.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDProperty.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/KDStateMachine.h"
#include "spyro/source/KDVolume.h"
#include "spyro/source/KDWaterVolume.h"
#include "spyro/source/Level.h"
#include "spyro/source/MeleeTrails.h"
#include "spyro/source/Names.h"
#include "spyro/source/NodeLookAt.h"
#include "spyro/source/PlatformObject.h"
#include "spyro/source/SB2.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/ShatterablePlatform.h"
#include "spyro/source/SpawnPointObject.h"
#include "spyro/source/SpawnerObject.h"
#include "spyro/source/TargetManager.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "common/Source/StdMath.h"
#include "spyro/source/KDRandom.h"
#include "spyro/source/PropFlags.h"
#include "spyro/source/Tools.h"
#include "unplaced_inlines.h"
#include <m2c_macros.h>

extern s32 GS_OBHit;
extern MKSceneManager *gMK;
extern s32 gViewSeed;
extern M2C_UNK gb;
extern void *gpTranslation_StringArray;
#if 0 // DRAFT: illegal use of incomplete struct/union/class 'CharacterBodyFxInit'
static CharacterBodyFxInit fireTier1BodyFXInit;     /* unable to generate initializer: confusing struct layout */
#endif
#if 0 // DRAFT: illegal use of incomplete struct/union/class 'CharacterBodyFxInit'
static CharacterBodyFxInit fireTier2BodyFXInit;     /* unable to generate initializer: confusing struct layout */
#endif
#if 0 // DRAFT: illegal use of incomplete struct/union/class 'CharacterBodyFxInit'
static CharacterBodyFxInit fireTier3BodyFXInit;     /* unable to generate initializer: confusing struct layout */
#endif

#if 0 // DRAFT: ')' expected
void FireTier3::Message(MKMessage *arg0) {
    s32 temp_r31_50;

    if ((s32) arg0->unk0 == 0x8D) {
        temp_r31_50 = M2C_FIELD(gpTranslation_StringArray, s32 *, 0x354);
        M2C_FIELD(checked_cast<GetNameMsg *, MKMessage>(arg0), s32 *, 8) = temp_r31_50;
        return;
    }
    Enemy::Message(arg0);
}
#endif

#if 0 // DRAFT: function call 'KDSound_Play3d(long, unsigned char *, unsigned int, int, float, unsigned int)' does not match 'KDSound_Play3d(MKAnimScript *, const MKVector3 *, 
void FireTier3::DoDeadFx() {
    f64 sp140;
    f64 sp138;
    f64 sp130;
    f64 sp128;
    f64 sp120;
    f64 sp118;
    f64 sp110;
    f64 sp108;
    f64 sp100;
    f64 spF8;
    f64 spF0;
    f64 spE8;
    f64 spE0;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    f64 spC0;
    f64 spB8;
    f64 spB0;
    f64 spA8;
    f32 spA0;
    f32 sp9C;
    f32 sp98;
    f32 sp90;
    f32 sp8C;
    f32 sp88;
    f32 sp80;
    f64 sp78;
    f32 sp70;
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
    f32 sp20;
    f64 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f19_130;
    f32 temp_f1_135;
    f32 temp_f20_133;
    f64 temp_f0_154;
    f64 temp_f0_166;
    f64 temp_f0_210;
    f64 temp_f0_222;
    s32 var_r28_115;
    void *temp_r29_102;
    void *temp_r3_139;
    void *temp_r3_183;
    void *temp_r3_246;

    Enemy::DoDeadFx();
    temp_r29_102 = checked_cast<FireTier3Descriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    KDSound_Play3d(GS_OBHit, ((u8 *) this->unk8) + 0x30, 0U, -1, 0.0f, 0U);
    var_r28_115 = 0;
    do {
        temp_f19_130 = 6.2831855f * ((f32) var_r28_115 / 39.0f);
        temp_f20_133 = -_table_sinf(1.5707964f + temp_f19_130);
        temp_f1_135 = _table_sinf(temp_f19_130);
        sp88 = 0.0f;
        sp8C = 25.0f;
        temp_r3_139 = ((u8 *) this->unk8) + 0x30;
        spA0 = temp_f20_133;
        sp90 = 0.0f;
        sp98 = temp_f1_135;
        sp9C = 0.0f;
        sp118 = (f64) sp88;
        sp138 = (f64) sp98;
        sp140 = (f64) spA0;
        sp120 = (f64) sp90;
        temp_f0_154 = M2C_FIELD(temp_r3_139, f64 *, 0) + sp118;
        sp78 = temp_f0_154;
        sp128 = temp_f0_154;
        sp80 = M2C_FIELD(temp_r3_139, f32 *, 8) + (f32) sp120;
        sp130 = (f64) sp80;
        temp_f0_166 = sp138 * 5.63800838e-315;
        sp68 = temp_f0_166;
        sp108 = temp_f0_166;
        sp70 = (f32) sp140 * 530.0f;
        sp110 = (f64) sp70;
        ((CrashFirePS *) (M2C_FIELD(&gb, CrashFirePS **, 0x68)))->Emit(*((MKVector3 *) &sp128), *((MKVector3 *) &sp108), 10.0f);
        sp58 = 0.0f;
        sp5C = 20.0f;
        temp_r3_183 = ((u8 *) this->unk8) + 0x30;
        sp60 = 0.0f;
        spE8 = (f64) sp58;
        spF0 = (f64) sp60;
        sp48 = M2C_FIELD(temp_r3_183, f64 *, 0) + spE8;
        sp40 = 0.0f;
        sp38 = 0.0f;
        sp3C = 2.0f;
        sp50 = M2C_FIELD(temp_r3_183, f32 *, 8) + (f32) spF0;
        spB8 = (f64) sp38;
        spF8 = sp48;
        sp100 = (f64) sp50;
        spC0 = (f64) sp40;
        temp_f0_210 = sp138 + spB8;
        sp28 = temp_f0_210;
        spC8 = temp_f0_210;
        sp30 = (f32) sp140 + (f32) spC0;
        spD0 = (f64) sp30;
        temp_f0_222 = temp_f0_210 * 5.72858887e-315;
        sp18 = temp_f0_222;
        spD8 = temp_f0_222;
        sp20 = (f32) spD0 * 2500.0f;
        spE0 = (f64) sp20;
        MKRand_Float((int *) &gViewSeed, 0.75f, 1.2f);
        sp8 = 1.0f;
        spC = 1.0f;
        sp10 = 1.0f;
        sp14 = 1.0f;
        spA8 = (f64) sp8;
        spB0 = (f64) sp10;
        temp_r3_246 = M2C_FIELD(temp_r29_102, void **, 0x2B4);
        M2C_FIELD(M2C_FIELD(temp_r3_246, void **, 0x44), M2C_UNK (**)(void *, f64 *, f64 *, f64 *, f64), 0x3C)(temp_r3_246, &spF8, &spD8, &spA8, (f64) sp8);
        var_r28_115 += 1;
    } while (var_r28_115 < 0x28);
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void FireTier3::Init() {
    EnemyGoal_Think *temp_r31_300;

    Enemy::Init();
    operator new(0x74U, NULL, 0);
    temp_r31_300 = M2C_ERROR(/* Read from unset register $r3 */);
    if (temp_r31_300 != NULL) {
        temp_r31_300->__vptr = &__vt__12Goal<5Enemy>;
        temp_r31_300->unk4 = 0;
        temp_r31_300->unk8 = 1;
        temp_r31_300->unk9 = 0;
        temp_r31_300->unkC = 0;
        temp_r31_300->__vptr = &__vt__21CompositeGoal<5Enemy>;
        temp_r31_300->unk1C = 0;
        temp_r31_300->unk18 = 0;
        temp_r31_300->unk10 = 0;
        temp_r31_300->unk14 = 0;
        temp_r31_300->__vptr = &__vt;
    }
    temp_r31_300->Init((Enemy *) this);
    this->unkA3C = &temp_r31_300->__vptr;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk244'
void FireTier3Descriptor::LoadDone() {
    EnemyDescriptor::LoadDone();
    this->unk244.Init(&fireTier3BodyFXInit, 0xD, (MKAnimScript *) this->unk34);
    this->unk2B4 = (long) (checked_cast<GoopFX *, MKProp>(gMK->CreateProp("GoopFX")));
}
#endif

#if 0 // DRAFT: function call 'KDSound_Play3d(long, unsigned char *, unsigned int, int, float, unsigned int)' does not match 'KDSound_Play3d(MKAnimScript *, const MKVector3 *, 
void FireTier2::DoDeadFx() {
    f64 sp140;
    f64 sp138;
    f64 sp130;
    f64 sp128;
    f64 sp120;
    f64 sp118;
    f64 sp110;
    f64 sp108;
    f64 sp100;
    f64 spF8;
    f64 spF0;
    f64 spE8;
    f64 spE0;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    f64 spC0;
    f64 spB8;
    f64 spB0;
    f64 spA8;
    f32 spA0;
    f32 sp9C;
    f32 sp98;
    f32 sp90;
    f32 sp8C;
    f32 sp88;
    f32 sp80;
    f64 sp78;
    f32 sp70;
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
    f32 sp20;
    f64 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f19_428;
    f32 temp_f1_433;
    f32 temp_f20_431;
    f64 temp_f0_452;
    f64 temp_f0_464;
    f64 temp_f0_508;
    f64 temp_f0_520;
    s32 var_r28_413;
    void *temp_r29_400;
    void *temp_r3_437;
    void *temp_r3_481;
    void *temp_r3_544;

    Enemy::DoDeadFx();
    temp_r29_400 = checked_cast<FireTier2Descriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    KDSound_Play3d(GS_OBHit, ((u8 *) this->unk8) + 0x30, 0U, -1, 0.0f, 0U);
    var_r28_413 = 0;
    do {
        temp_f19_428 = 6.2831855f * ((f32) var_r28_413 / 19.0f);
        temp_f20_431 = -_table_sinf(1.5707964f + temp_f19_428);
        temp_f1_433 = _table_sinf(temp_f19_428);
        sp88 = 0.0f;
        sp8C = 25.0f;
        temp_r3_437 = ((u8 *) this->unk8) + 0x30;
        spA0 = temp_f20_431;
        sp90 = 0.0f;
        sp98 = temp_f1_433;
        sp9C = 0.0f;
        sp118 = (f64) sp88;
        sp138 = (f64) sp98;
        sp140 = (f64) spA0;
        sp120 = (f64) sp90;
        temp_f0_452 = M2C_FIELD(temp_r3_437, f64 *, 0) + sp118;
        sp78 = temp_f0_452;
        sp128 = temp_f0_452;
        sp80 = M2C_FIELD(temp_r3_437, f32 *, 8) + (f32) sp120;
        sp130 = (f64) sp80;
        temp_f0_464 = sp138 * 5.63800838e-315;
        sp68 = temp_f0_464;
        sp108 = temp_f0_464;
        sp70 = (f32) sp140 * 530.0f;
        sp110 = (f64) sp70;
        ((CrashFirePS *) (M2C_FIELD(&gb, CrashFirePS **, 0x68)))->Emit(*((MKVector3 *) &sp128), *((MKVector3 *) &sp108), 10.0f);
        sp58 = 0.0f;
        sp5C = 20.0f;
        temp_r3_481 = ((u8 *) this->unk8) + 0x30;
        sp60 = 0.0f;
        spE8 = (f64) sp58;
        spF0 = (f64) sp60;
        sp48 = M2C_FIELD(temp_r3_481, f64 *, 0) + spE8;
        sp40 = 0.0f;
        sp38 = 0.0f;
        sp3C = 2.0f;
        sp50 = M2C_FIELD(temp_r3_481, f32 *, 8) + (f32) spF0;
        spB8 = (f64) sp38;
        spF8 = sp48;
        sp100 = (f64) sp50;
        spC0 = (f64) sp40;
        temp_f0_508 = sp138 + spB8;
        sp28 = temp_f0_508;
        spC8 = temp_f0_508;
        sp30 = (f32) sp140 + (f32) spC0;
        spD0 = (f64) sp30;
        temp_f0_520 = temp_f0_508 * 5.72858887e-315;
        sp18 = temp_f0_520;
        spD8 = temp_f0_520;
        sp20 = (f32) spD0 * 2500.0f;
        spE0 = (f64) sp20;
        MKRand_Float((int *) &gViewSeed, 0.75f, 1.2f);
        sp8 = 1.0f;
        spC = 1.0f;
        sp10 = 1.0f;
        sp14 = 1.0f;
        spA8 = (f64) sp8;
        spB0 = (f64) sp10;
        temp_r3_544 = M2C_FIELD(temp_r29_400, void **, 0x2B4);
        M2C_FIELD(M2C_FIELD(temp_r3_544, void **, 0x44), M2C_UNK (**)(void *, f64 *, f64 *, f64 *, f64), 0x3C)(temp_r3_544, &spF8, &spD8, &spA8, (f64) sp8);
        var_r28_413 += 1;
    } while (var_r28_413 < 0x14);
}
#endif

void FireTier2::UpdateMovementCustom() {
    M2C_FIELD(this, f64 *, 0x598) = (f64) (M2C_FIELD(this, f64 *, 0x598) + M2C_FIELD(this, f64 *, 0x90));
    this->unk5A0 += this->unk98;
    UpdateRotation();
    UpdateModel();
}

void FireTier2::CheckAnimEvents() {
    f64 sp140;
    f64 sp138;
    f64 sp130;
    f64 sp128;
    f64 sp120;
    f64 sp118;
    f64 sp110;
    f64 sp108;
    f64 sp100;
    f64 spF8;
    f64 spF0;
    f64 spE8;
    f64 spE0;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    f64 spC0;
    f64 spB8;
    f64 spB0;
    f64 spA8;
    f32 spA0;
    f32 sp9C;
    f32 sp98;
    f32 sp90;
    f32 sp8C;
    f32 sp88;
    f32 sp80;
    f64 sp78;
    f32 sp70;
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
    f32 sp20;
    f64 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f18_681;
    f32 temp_f19_684;
    f32 temp_f1_686;
    f64 temp_f0_705;
    f64 temp_f0_717;
    f64 temp_f0_761;
    f64 temp_f0_773;
    s32 var_r28_666;
    void *temp_r29_662;
    void *temp_r3_690;
    void *temp_r3_734;
    void *temp_r3_797;

    if (((MKAnimScript *) this->unk630)->CheckEvent(0xD) != 0) {
        temp_r29_662 = checked_cast<FireTier2Descriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        var_r28_666 = 0;
        do {
            temp_f18_681 = 6.2831855f * ((f32) var_r28_666 / 19.0f);
            temp_f19_684 = -_table_sinf(1.5707964f + temp_f18_681);
            temp_f1_686 = _table_sinf(temp_f18_681);
            sp88 = 0.0f;
            sp8C = 25.0f;
            temp_r3_690 = ((u8 *) this->unk8) + 0x30;
            spA0 = temp_f19_684;
            sp90 = 0.0f;
            sp98 = temp_f1_686;
            sp9C = 0.0f;
            sp118 = (f64) sp88;
            sp138 = (f64) sp98;
            sp140 = (f64) spA0;
            sp120 = (f64) sp90;
            temp_f0_705 = M2C_FIELD(temp_r3_690, f64 *, 0) + sp118;
            sp78 = temp_f0_705;
            sp128 = temp_f0_705;
            sp80 = M2C_FIELD(temp_r3_690, f32 *, 8) + (f32) sp120;
            sp130 = (f64) sp80;
            temp_f0_717 = sp138 * 5.63800838e-315;
            sp68 = temp_f0_717;
            sp108 = temp_f0_717;
            sp70 = (f32) sp140 * 530.0f;
            sp110 = (f64) sp70;
            ((CrashFirePS *) (M2C_FIELD(&gb, CrashFirePS **, 0x68)))->Emit(*((MKVector3 *) &sp128), *((MKVector3 *) &sp108), 10.0f);
            sp58 = 0.0f;
            sp5C = 20.0f;
            temp_r3_734 = ((u8 *) this->unk8) + 0x30;
            sp60 = 0.0f;
            spE8 = (f64) sp58;
            spF0 = (f64) sp60;
            sp48 = M2C_FIELD(temp_r3_734, f64 *, 0) + spE8;
            sp40 = 0.0f;
            sp38 = 0.0f;
            sp3C = 3.0f;
            sp50 = M2C_FIELD(temp_r3_734, f32 *, 8) + (f32) spF0;
            spB8 = (f64) sp38;
            spF8 = sp48;
            sp100 = (f64) sp50;
            spC0 = (f64) sp40;
            temp_f0_761 = sp138 + spB8;
            sp28 = temp_f0_761;
            spC8 = temp_f0_761;
            sp30 = (f32) sp140 + (f32) spC0;
            spD0 = (f64) sp30;
            temp_f0_773 = temp_f0_761 * 5.697262106e-315;
            sp18 = temp_f0_773;
            spD8 = temp_f0_773;
            sp20 = (f32) spD0 * 1500.0f;
            spE0 = (f64) sp20;
            MKRand_Float((int *) &gViewSeed, 0.75f, 1.2f);
            sp8 = 1.0f;
            spC = 0.1f;
            sp10 = 0.0f;
            sp14 = 1.0f;
            spA8 = (f64) sp8;
            spB0 = (f64) sp10;
            temp_r3_797 = M2C_FIELD(temp_r29_662, void **, 0x2B4);
            M2C_FIELD(M2C_FIELD(temp_r3_797, void **, 0x44), M2C_UNK (**)(void *, f64 *, f64 *, f64 *, f64), 0x3C)(temp_r3_797, &spF8, &spD8, &spA8, (f64) sp8);
            var_r28_666 += 1;
        } while (var_r28_666 < 0x14);
        return;
    }
    Enemy::CheckAnimEvents();
}

s32 FireTier2::Spawn(const Matrix *arg0, SpawnPointRef *arg1) {
    Matrix spA0;
    M2C_UNK sp9C;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp30;
    f64 sp28;
    f64 sp20;
    f64 sp18;
    s32 sp10;
    f64 temp_f0_871;
    f64 temp_f0_936;
    f64 temp_f1_869;
    f64 temp_f1_947;
    s32 var_r28_874;
    u8 temp_ret_922;
    u8 var_r29_894;
    u8 var_r4_872;

    M2C_STRUCT_COPY((s32) &sp9C + 4, (s32) (arg0 - 4) + 4, 0x40);
    temp_f1_869 = M2C_FIELD(arg0, f64 *, 0x30);
    temp_f0_871 = M2C_FIELD(arg0, f64 *, 0x38);
    var_r4_872 = 0;
    sp78 = temp_f1_869;
    var_r28_874 = 0;
    sp80 = temp_f0_871;
    sp68 = temp_f1_869;
    sp70 = temp_f0_871;
    sp18 = temp_f1_869;
    this->unkB10 &= ~0x80;
    sp20 = temp_f0_871;
    sp88 = temp_f1_869;
    sp90 = temp_f0_871;
    this->unkB10 &= ~0x40;
loop_5:
    if ((var_r4_872 == 0) && (var_r28_874 < 0xA)) {
        var_r29_894 = 0;
        if ((InWaterVolume(*((MKVector3 *) &sp68), (int *) &sp10) != 0) && (sp10 & 1)) {
            var_r29_894 = 1;
        }
        var_r4_872 = var_r29_894;
        var_r28_874 += 1;
        (*(f32 *) ((u8 *) &sp68 + 0x4)) -= 10.0f;
        goto loop_5;
    }
    if (var_r4_872 != 0) {
        temp_ret_922 = MKCollision_RayCollide(*((MKVector3 *) &sp78), *((MKVector3 *) &sp68), NULL, (MKCollisionMode) 4, M2C_FIELD(this->unk110.unk460, s32 *, 0x18));
        if (temp_ret_922 == 0) {
            sp38 = 0.0f;
            sp3C = 300.0f;
            sp40 = 0.0f;
            sp48 = (f64) sp38;
            sp50 = (f64) sp40;
            temp_f0_936 = sp78 + sp48;
            sp28 = temp_f0_936;
            sp58 = temp_f0_936;
            sp30 = (f32) sp80 + (f32) sp50;
            sp60 = (f64) sp30;
            temp_f1_947 = ((KDWaterVolume *) &sp58)->GetWaterSurface(*((MKVector3 *) (u32) (u64) temp_ret_922));
            (*(f32 *) ((u8 *) &sp78 + 0x4)) = (f32) temp_f1_947;
            spA0.unk30 = (f32) sp78;
            spA0.unk34 = (f32) temp_f1_947;
            spA0.unk38 = (f32) sp80;
            spA0.unk3C = 1.0f;
            this->unkB10 |= 0x80;
            this->unkB10 |= 0x40;
        }
    }
    if (Enemy::Spawn(&spA0, arg1) != 0) {
        if (((u8) this->unkB10 >> 7U) & 1) {
            PropFlagsClear((unsigned int *) &this->unk10, 0x40000U);
        }
        M2C_FIELD(this, f64 *, 0x5B8) = sp88;
        M2C_FIELD(this, f64 *, 0x5C0) = sp90;
        return 1;
    }
    return 0;
}

#if 0 // DRAFT: ')' expected
void FireTier2::Message(MKMessage *arg0) {
    s32 temp_r31_1011;

    if ((s32) arg0->unk0 != 0x8D) {
        Enemy::Message(arg0);
        return;
    }
    temp_r31_1011 = M2C_FIELD(gpTranslation_StringArray, s32 *, 0x350);
    M2C_FIELD(checked_cast<GetNameMsg *, MKMessage>(arg0), s32 *, 8) = temp_r31_1011;
}
#endif

void FireTier2::Deinit() {
    Enemy::Deinit();
}

#if 0 // DRAFT: illegal implicit conversion from 'FireTier2Goal_Think' to 'FireTier2Goal_Think *'
void FireTier2::Init() {
    FireTier2Goal_Think *var_r31_1051;

    Enemy::Init();
    operator new(0x80U, NULL, 0);
    var_r31_1051 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r31_1051 != NULL) {
        var_r31_1051 = ((FireTier2Goal_Think *) (M2C_ERROR(/* Read from unset register $r3 */)))->FireTier2Goal_Think();
    }
    var_r31_1051->Init((Enemy *) this);
    this->unkA3C = &var_r31_1051->__vptr;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk244'
void FireTier2Descriptor::LoadDone() {
    EnemyDescriptor::LoadDone();
    this->unk244.Init(&fireTier2BodyFXInit, 0xE, (MKAnimScript *) this->unk34);
    this->unk2B4 = (long) (checked_cast<GoopFX *, MKProp>(gMK->CreateProp("GoopFX")));
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'MKCollisionResult' to 'double'
s32 FireTier1::SelectMoveToWallPos(const MKVector3 &arg0, const MKVector3 &arg1, MKVector3 *arg2) {
    MKCollisionResult sp138;
    f64 sp130;
    f64 sp128;
    f64 sp120;
    f64 sp118;
    f64 sp110;
    f64 sp108;
    f64 sp100;
    f64 spF8;
    MKVector3 spE8;
    MKVector3 spD8;
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
    f32 sp80;
    f64 sp78;
    f32 sp70;
    f64 sp68;
    f32 sp60;
    f64 sp58;
    f32 sp50;
    f64 sp48;
    f32 sp40;
    f64 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    f32 temp_f29_1167;
    f32 temp_f3_1222;
    f32 temp_f5_1144;
    f32 temp_f6_1143;
    f32 temp_f7_1146;
    f64 temp_f0_1179;
    f64 temp_f0_1197;
    f64 temp_f0_1208;
    f64 temp_f0_1220;
    f64 temp_f0_1231;
    f64 temp_f0_1251;

    spE8 = KDRand_UnitVector();
    temp_f6_1143 = arg1.unk0;
    temp_f5_1144 = arg1.unk4;
    temp_f7_1146 = arg1.unk8;
    *(MKVector3 *) &sp128 = spE8;
    if (((temp_f7_1146 * temp_f7_1146) + ((temp_f6_1143 * temp_f6_1143) + (temp_f5_1144 * temp_f5_1144))) <= 0.000001f) {
        return 0;
    }
    temp_f29_1167 = ((f32) sp130 * temp_f7_1146) + (((f32) sp128 * temp_f6_1143) + ((*(f32 *) ((u8 *) &sp128 + 0x4)) * temp_f5_1144));
    sp18 = (f64) M2C_FIELD(&arg1, f32 *, 0) * (f64) temp_f29_1167;
    sp20 = temp_f7_1146 * temp_f29_1167;
    spB8 = sp18;
    spC0 = (f64) sp20;
    temp_f0_1179 = sp128 - spB8;
    sp8 = temp_f0_1179;
    spC8 = temp_f0_1179;
    sp10 = (f32) sp130 - (f32) spC0;
    spD0 = (f64) sp10;
    spD8 = Normalise(*((MKVector3 *) &spC8));
    *(MKVector3 *) &sp128 = spD8;
    temp_f0_1197 = sp128 * 5.5769738e-315;
    sp78 = temp_f0_1197;
    spA8 = temp_f0_1197;
    sp80 = (f32) sp130 * 200.0f;
    spB0 = (f64) sp80;
    temp_f0_1208 = M2C_FIELD(&arg0, f64 *, 0) + temp_f0_1197;
    sp68 = temp_f0_1208;
    sp118 = temp_f0_1208;
    sp70 = arg0.unk8 + (f32) spB0;
    sp120 = (f64) sp70;
    temp_f0_1220 = (f64) M2C_FIELD(&arg1, f32 *, 0) * 5.634608575e-315;
    sp58 = temp_f0_1220;
    temp_f3_1222 = arg1.unk8;
    sp98 = temp_f0_1220;
    sp60 = temp_f3_1222 * 500.0f;
    spA0 = (f64) sp60;
    temp_f0_1231 = sp118 + temp_f0_1220;
    sp48 = temp_f0_1231;
    sp108 = temp_f0_1231;
    sp50 = (f32) sp120 + (f32) spA0;
    sp110 = (f64) sp50;
    sp38 = (f64) M2C_FIELD(&arg1, f32 *, 0) * 5.5769738e-315;
    sp40 = temp_f3_1222 * 200.0f;
    sp88 = sp38;
    sp90 = (f64) sp40;
    temp_f0_1251 = sp118 - sp88;
    sp28 = temp_f0_1251;
    spF8 = temp_f0_1251;
    sp30 = (f32) sp120 - (f32) sp90;
    sp100 = (f64) sp30;
    if (MKCollision_RayCollide(*((MKVector3 *) &sp108), *((MKVector3 *) &spF8), &sp138, (MKCollisionMode) 5, M2C_FIELD(this->unk110.unk460, s32 *, 0x18)) != 0) {
        M2C_FIELD(arg2, f64 *, 0) = M2C_BITWISE(f64, sp138);
        M2C_FIELD(arg2, f64 *, 8) = (f64) sp138.unk8;
        return 1;
    }
    return 0;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'MKCollisionResult' to 'double'
s32 FireTier1::SelectFlyToWallPos(const MKVector3 &arg0, MKVector3 *arg1, MKVector3 *arg2, MKVector3 *arg3) {
    MKCollisionResult sp200;
    Matrix sp1C0;
    f64 sp1B8;
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
    f64 sp160;
    f64 sp158;
    f64 sp150;
    f64 sp148;
    f64 sp140;
    f64 sp138;
    f64 sp130;
    f64 sp128;
    f64 sp120;
    f64 sp118;
    f64 sp110;
    f64 sp108;
    f64 sp100;
    f64 spF8;
    f64 spF0;
    f64 spE8;
    f64 spE0;
    f64 spD8;
    f64 spD0;
    f32 spC8;
    f64 spC0;
    f32 spB8;
    f64 spB0;
    f32 spA8;
    f32 spA4;
    f32 spA0;
    f32 sp98;
    f32 sp94;
    f32 sp90;
    f32 sp88;
    f32 sp84;
    f32 sp80;
    f32 sp78;
    f32 sp74;
    f32 sp70;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp58;
    f64 sp50;
    f32 sp48;
    f64 sp40;
    f32 sp38;
    f64 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    s32 sp18;
    f32 sp14;
    f32 sp10;
    f32 *temp_r7_1391;
    f32 temp_f0_1610;
    f32 temp_f13_1619;
    f32 temp_f30_1625;
    f32 var_f4_1471;
    f32 var_f4_1538;
    f64 temp_f0_1403;
    f64 temp_f0_1662;
    f64 temp_f1_1330;
    f64 temp_f1_1477;
    f64 temp_f1_1483;
    f64 temp_f1_1487;
    f64 temp_f31_1431;
    s32 temp_r3_1506;
    s32 var_r0_1516;
    s32 var_r26_1316;
    void *temp_r3_1329;
    void *temp_r4_1325;

    sp1B0 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    sp1B8 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
    var_r26_1316 = 0;
loop_1:
    temp_r4_1325 = M2C_FIELD(this->unkA44, void **, 0x1C);
    temp_r3_1329 = (void *) (M2C_FIELD(temp_r4_1325, s32 *, 0x24) + (MKRand_Int((int *) &gViewSeed, 0, M2C_FIELD(M2C_FIELD(this->unkA44, void **, 0x1C), s32 *, 0x20)) * M2C_FIELD(temp_r4_1325, s32 *, 0x1C)));
    temp_f1_1330 = M2C_FIELD(temp_r3_1329, f64 *, 0);
    sp1B0 = temp_f1_1330;
    sp1B8 = M2C_FIELD(temp_r3_1329, f64 *, 8);
    sp40 = temp_f1_1330 - M2C_FIELD(this, f64 *, 0x588);
    spF0 = sp40;
    sp48 = (f32) sp1B8 - this->unk588.unk8;
    sp100 = sp40;
    spF8 = (f64) sp48;
    sp108 = (f64) sp48;
    if ((((f32) spF8 * (f32) spF8) + (((f32) spF0 * (f32) spF0) + ((*(f32 *) ((u8 *) &spF0 + 0x4)) * (*(f32 *) ((u8 *) &spF0 + 0x4))))) < 10000.0f) {
        var_r26_1316 += 1;
        if (var_r26_1316 < 3) {
            goto loop_1;
        }
    }
    sp30 = sp1B0 - M2C_FIELD(this, f64 *, 0x588);
    spD0 = sp30;
    sp38 = (f32) sp1B8 - this->unk588.unk8;
    spD8 = (f64) sp38;
    spE0 = sp30;
    spE8 = (f64) sp38;
    if ((((f32) spD8 * (f32) spD8) + (((f32) spD0 * (f32) spD0) + ((*(f32 *) ((u8 *) &spD0 + 0x4)) * (*(f32 *) ((u8 *) &spD0 + 0x4))))) < 10000.0f) {
        return 0;
    }
    temp_r7_1391 = this->unk110.unk460;
    if (MKCollision_SphereCollide(*((MKVector3 *) &sp1B0), M2C_FIELD(temp_r7_1391, f32 *, 0), &sp200, 1, (MKCollisionMode) 5, M2C_FIELD(temp_r7_1391, s32 *, 0x18)) != 0) {
        temp_f0_1403 = M2C_BITWISE(f64, sp200) - sp1B0;
        spC0 = temp_f0_1403;
        sp160 = temp_f0_1403;
        spC8 = sp200.unk8 - (f32) sp1B8;
        sp168 = (f64) spC8;
        sp14 = (MKVector3::up.unk8 * (f32) sp168) + ((MKVector3::up.unk0 * (f32) sp160) + (MKVector3::up.unk4 * (*(f32 *) ((u8 *) &sp160 + 0x4))));
        sp18 = (M2C_BITWISE(s32, sp14) & 0x80000000) | 0x3F800000;
        temp_f31_1431 = -M2C_BITWISE(f32, sp18);
        sp200.unk10 = (f64) (sp200.unk10 * temp_f31_1431);
        sp200.unk18 *= (f32) temp_f31_1431;
        M2C_FIELD(arg1, f64 *, 0) = M2C_BITWISE(f64, sp200);
        M2C_FIELD(arg1, f64 *, 8) = (f64) sp200.unk8;
        M2C_FIELD(arg2, f64 *, 0) = (f64) sp200.unk10;
        M2C_FIELD(arg2, f64 *, 8) = (f64) sp200.unk18;
        spB0 = M2C_FIELD(arg1, f64 *, 0) - M2C_FIELD(this, f64 *, 0x588);
        sp150 = spB0;
        spB8 = arg1->unk8 - this->unk588.unk8;
        sp158 = (f64) spB8;
        var_f4_1471 = ((f32) sp158 * (f32) sp158) + (((f32) sp150 * (f32) sp150) + ((*(f32 *) ((u8 *) &sp150 + 0x4)) * (*(f32 *) ((u8 *) &sp150 + 0x4))));
        if (var_f4_1471 > 1e-12f) {
            if (var_f4_1471 > 0.0f) {
                temp_f1_1477 = __frsqrte(var_f4_1471);
                temp_f1_1483 = 0.5 * temp_f1_1477 * -(((f64) var_f4_1471 * (temp_f1_1477 * temp_f1_1477)) - 3.0);
                temp_f1_1487 = 0.5 * temp_f1_1483 * -(((f64) var_f4_1471 * (temp_f1_1483 * temp_f1_1483)) - 3.0);
                var_f4_1471 = (f32) ((f64) var_f4_1471 * (0.5 * temp_f1_1487 * -(((f64) var_f4_1471 * (temp_f1_1487 * temp_f1_1487)) - 3.0)));
            } else if (var_f4_1471 < M2C_BITWISE(f32, 0.0)) {
                var_f4_1471 = __float_nan;
            } else {
                sp10 = var_f4_1471;
                temp_r3_1506 = M2C_BITWISE(s32, sp10) & 0x7F800000;
                switch (temp_r3_1506) {             /* irregular */
                case 0x7F800000:
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_1516 = 1;
                    } else {
                        var_r0_1516 = 2;
                    }
                    break;
                case 0x0:
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_1516 = 5;
                    } else {
                        var_r0_1516 = 3;
                    }
                    break;
                default:
                    var_r0_1516 = 4;
                    break;
                }
                if (var_r0_1516 == 1) {
                    var_f4_1471 = __float_nan;
                }
            }
            var_f4_1538 = 1.0f / var_f4_1471;
        } else {
            var_f4_1538 = 0.0f;
        }
        sp190 = M2C_FIELD(arg2, f64 *, 0);
        spA8 = (f32) sp158 * var_f4_1538;
        spA0 = (f32) sp150 * var_f4_1538;
        spA4 = (*(f32 *) ((u8 *) &sp150 + 0x4)) * var_f4_1538;
        sp1A8 = (f64) spA8;
        sp1A0 = (f64) spA0;
        sp198 = M2C_FIELD(arg2, f64 *, 8);
        sp94 = ((f32) sp198 * (f32) sp1A0) - ((f32) sp190 * (f32) sp1A8);
        sp98 = ((f32) sp190 * (*(f32 *) ((u8 *) &sp1A0 + 0x4))) - ((*(f32 *) ((u8 *) &sp190 + 0x4)) * (f32) sp1A0);
        sp90 = ((*(f32 *) ((u8 *) &sp190 + 0x4)) * (f32) sp1A8) - ((f32) sp198 * (*(f32 *) ((u8 *) &sp1A0 + 0x4)));
        sp188 = (f64) sp98;
        sp180 = (f64) sp90;
        sp80 = ((*(f32 *) ((u8 *) &sp180 + 0x4)) * (f32) sp198) - ((f32) sp188 * (*(f32 *) ((u8 *) &sp190 + 0x4)));
        sp84 = ((f32) sp188 * (f32) sp190) - ((f32) sp180 * (f32) sp198);
        sp88 = ((f32) sp180 * (*(f32 *) ((u8 *) &sp190 + 0x4))) - ((*(f32 *) ((u8 *) &sp180 + 0x4)) * (f32) sp190);
        sp170 = (f64) sp80;
        sp178 = (f64) sp88;
        sp1C0.SetIdentity();
        sp70 = -(f32) sp180;
        sp74 = -(*(f32 *) ((u8 *) &sp180 + 0x4));
        temp_f0_1610 = arg0.unk4;
        sp78 = -(f32) sp188;
        sp140 = (f64) sp70;
        temp_f13_1619 = arg0.unk0;
        sp68 = -(f32) sp178;
        temp_f30_1625 = arg0.unk8;
        sp148 = (f64) sp78;
        sp138 = (f64) sp68;
        sp60 = -(f32) sp170;
        sp64 = -(*(f32 *) ((u8 *) &sp170 + 0x4));
        sp28 = (temp_f30_1625 * (f32) sp138) + ((temp_f13_1619 * (f32) sp148) + (temp_f0_1610 * (f32) sp198));
        sp130 = (f64) sp60;
        sp1C0 = (f32) sp140;
        sp1C0.unk4 = (*(f32 *) ((u8 *) &sp140 + 0x4));
        sp20 = (temp_f30_1625 * (f32) sp130) + ((temp_f13_1619 * (f32) sp140) + (temp_f0_1610 * (f32) sp190));
        sp24 = (temp_f30_1625 * (*(f32 *) ((u8 *) &sp130 + 0x4))) + ((temp_f13_1619 * (*(f32 *) ((u8 *) &sp140 + 0x4))) + (temp_f0_1610 * (*(f32 *) ((u8 *) &sp190 + 0x4))));
        sp1C0.unk8 = (f32) sp148;
        sp1C0.unkC = 0.0f;
        sp1C0.unk10 = (f32) sp190;
        sp1C0.unk14 = (*(f32 *) ((u8 *) &sp190 + 0x4));
        sp1C0.unk18 = (f32) sp198;
        sp1C0.unk1C = 0.0f;
        sp1C0.unk20 = (f32) sp130;
        sp1C0.unk24 = (*(f32 *) ((u8 *) &sp130 + 0x4));
        sp1C0.unk28 = (f32) sp138;
        sp1C0.unk2C = 0.0f;
        sp110 = (f64) sp20;
        sp118 = (f64) sp28;
        temp_f0_1662 = M2C_FIELD(arg1, f64 *, 0) - sp110;
        sp50 = temp_f0_1662;
        M2C_FIELD(arg3, f64 *, 0) = temp_f0_1662;
        sp120 = temp_f0_1662;
        sp58 = arg1->unk8 - (f32) sp118;
        sp128 = (f64) sp58;
        M2C_FIELD(arg3, f64 *, 8) = (f64) sp58;
        return 1;
    }
    return 0;
}
#endif

#if 0 // DRAFT: function call 'KDSound_Play3d(long, unsigned char *, unsigned int, int, float, unsigned int)' does not match 'KDSound_Play3d(MKAnimScript *, const MKVector3 *, 
void FireTier1::DoDeadFx() {
    f64 sp140;
    f64 sp138;
    f64 sp130;
    f64 sp128;
    f64 sp120;
    f64 sp118;
    f64 sp110;
    f64 sp108;
    f64 sp100;
    f64 spF8;
    f64 spF0;
    f64 spE8;
    f64 spE0;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    f64 spC0;
    f64 spB8;
    f64 spB0;
    f64 spA8;
    f32 spA0;
    f32 sp9C;
    f32 sp98;
    f32 sp90;
    f32 sp8C;
    f32 sp88;
    f32 sp80;
    f64 sp78;
    f32 sp70;
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
    f32 sp20;
    f64 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f19_1754;
    f32 temp_f1_1759;
    f32 temp_f20_1757;
    f64 temp_f0_1778;
    f64 temp_f0_1790;
    f64 temp_f0_1834;
    f64 temp_f0_1846;
    s32 var_r28_1739;
    void *temp_r29_1726;
    void *temp_r3_1763;
    void *temp_r3_1807;
    void *temp_r3_1870;

    Enemy::DoDeadFx();
    temp_r29_1726 = checked_cast<FireTier1Descriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    KDSound_Play3d(GS_OBHit, ((u8 *) this->unk8) + 0x30, 0U, -1, 0.0f, 0U);
    var_r28_1739 = 0;
    do {
        temp_f19_1754 = 6.2831855f * ((f32) var_r28_1739 / 9.0f);
        temp_f20_1757 = -_table_sinf(1.5707964f + temp_f19_1754);
        temp_f1_1759 = _table_sinf(temp_f19_1754);
        sp88 = 0.0f;
        sp8C = 25.0f;
        temp_r3_1763 = ((u8 *) this->unk8) + 0x30;
        spA0 = temp_f20_1757;
        sp90 = 0.0f;
        sp98 = temp_f1_1759;
        sp9C = 0.0f;
        sp118 = (f64) sp88;
        sp138 = (f64) sp98;
        sp140 = (f64) spA0;
        sp120 = (f64) sp90;
        temp_f0_1778 = M2C_FIELD(temp_r3_1763, f64 *, 0) + sp118;
        sp78 = temp_f0_1778;
        sp128 = temp_f0_1778;
        sp80 = M2C_FIELD(temp_r3_1763, f32 *, 8) + (f32) sp120;
        sp130 = (f64) sp80;
        temp_f0_1790 = sp138 * 5.63800838e-315;
        sp68 = temp_f0_1790;
        sp108 = temp_f0_1790;
        sp70 = (f32) sp140 * 530.0f;
        sp110 = (f64) sp70;
        ((CrashFirePS *) (M2C_FIELD(&gb, CrashFirePS **, 0x68)))->Emit(*((MKVector3 *) &sp128), *((MKVector3 *) &sp108), 10.0f);
        sp58 = 0.0f;
        sp5C = 20.0f;
        temp_r3_1807 = ((u8 *) this->unk8) + 0x30;
        sp60 = 0.0f;
        spE8 = (f64) sp58;
        spF0 = (f64) sp60;
        sp48 = M2C_FIELD(temp_r3_1807, f64 *, 0) + spE8;
        sp40 = 0.0f;
        sp38 = 0.0f;
        sp3C = 2.0f;
        sp50 = M2C_FIELD(temp_r3_1807, f32 *, 8) + (f32) spF0;
        spB8 = (f64) sp38;
        spF8 = sp48;
        sp100 = (f64) sp50;
        spC0 = (f64) sp40;
        temp_f0_1834 = sp138 + spB8;
        sp28 = temp_f0_1834;
        spC8 = temp_f0_1834;
        sp30 = (f32) sp140 + (f32) spC0;
        spD0 = (f64) sp30;
        temp_f0_1846 = temp_f0_1834 * 5.72858887e-315;
        sp18 = temp_f0_1846;
        spD8 = temp_f0_1846;
        sp20 = (f32) spD0 * 2500.0f;
        spE0 = (f64) sp20;
        MKRand_Float((int *) &gViewSeed, 0.75f, 1.2f);
        sp8 = 1.0f;
        spC = 1.0f;
        sp10 = 1.0f;
        sp14 = 1.0f;
        spA8 = (f64) sp8;
        spB0 = (f64) sp10;
        temp_r3_1870 = M2C_FIELD(temp_r29_1726, void **, 0x2B4);
        M2C_FIELD(M2C_FIELD(temp_r3_1870, void **, 0x44), M2C_UNK (**)(void *, f64 *, f64 *, f64 *, f64), 0x3C)(temp_r3_1870, &spF8, &spD8, &spA8, (f64) sp8);
        var_r28_1739 += 1;
    } while (var_r28_1739 < 0xA);
}
#endif

void FireTier1::UpdateMovementCustom() {
    M2C_FIELD(this, f64 *, 0x598) = (f64) (M2C_FIELD(this, f64 *, 0x598) + M2C_FIELD(this, f64 *, 0x90));
    this->unk5A0 += this->unk98;
    M2C_FIELD(this, f64 *, 0x588) = (f64) (M2C_FIELD(this, f64 *, 0x588) + M2C_FIELD(this, f64 *, 0x598));
    this->unk588.unk8 += this->unk5A0;
    UpdateRotation();
    UpdateModel();
}

#if 0 // DRAFT: illegal operand
s32 FireTier1::Spawn(const Matrix *arg0, SpawnPointRef *arg1) {
    u8 spE0;
    s32 spDC;
    void *spD8;
    s32 spD4;
    f32 spD0;
    s32 spCC;
    s8 spCB;
    s8 spCA;
    s16 spC8;
    f32 spC4;
    f32 spC0;
    f32 spBC;
    f32 spB8;
    f32 spB4;
    f32 spB0;
    f32 spA8;
    f32 spA4;
    f32 spA0;
    f32 sp98;
    f32 sp94;
    f32 sp90;
    MKVector3 sp80;
    M2C_UNK sp50;
    M2C_UNK sp4C;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    f64 temp_f0_2010;
    f64 temp_f0_2022;
    s32 temp_cr0_eq_2039;
    u16 temp_r3_2058;
    void *var_r29_2045;

    M2C_STRUCT_COPY((s32) &sp4C + 4, (s32) (arg0 - 4) + 4, 0x40);
    this->unkB40 &= ~0x80;
    if (M2C_FIELD(this->unkA44, s32 *, 4) & 0x20) {
        sp90 = 0.0f;
        sp94 = 0.0f;
        sp98 = 0.0f;
        spA0 = 0.0f;
        spA4 = 0.0f;
        spA8 = 0.0f;
        spB0 = 0.0f;
        spB4 = 0.0f;
        spB8 = 0.0f;
        spBC = 1.0f;
        spC0 = 0.0f;
        spC4 = 0.0f;
        spC8 = 0;
        spCA = 0;
        spCB = 0;
        spCC = 0;
        spD0 = 3.4028235e38f;
        spD4 = 0;
        spD8 = NULL;
        spDC = -1;
        spE0 = 0;
        temp_f0_2010 = M2C_FIELD(&MKVector3::up, f64 *, 0) * 5.5769738e-315;
        sp20 = temp_f0_2010;
        sp30 = temp_f0_2010;
        sp28 = MKVector3::up.unk8 * 200.0f;
        sp38 = (f64) sp28;
        temp_f0_2022 = sp80 + temp_f0_2010;
        sp10 = temp_f0_2022;
        sp40 = temp_f0_2022;
        sp18 = sp80.unk8 + (f32) sp38;
        sp48 = (f64) sp18;
        MKCollision_RayCollide(*((MKVector3 *) &sp40), sp80, (MKCollisionResult *) &sp90, (MKCollisionMode) 2, M2C_FIELD(this->unk110.unk460, s32 *, 0x18));
        temp_cr0_eq_2039 = spE0 == 0;
        if (temp_cr0_eq_2039 == 0) {
            if ((temp_cr0_eq_2039 == 0) && (spD8 != NULL) && (var_r29_2045 = M2C_FIELD(spD8, void **, 8), ((var_r29_2045 == NULL) == 0))) {

            } else {
                var_r29_2045 = NULL;
            }
            if (var_r29_2045 != NULL) {
                temp_r3_2058 = Tools_GetMatchingRefPointIndex(M2C_FIELD(var_r29_2045, MKModel **, 4), "spawn");
                if ((temp_r3_2058 != -1U) && (MKModel_GetRefPointMatrix(M2C_FIELD(var_r29_2045, MKModel **, 4), (s32) temp_r3_2058, (Matrix *) &sp50, 1U) != 0)) {
                    this->unkB40 |= 0x80;
                }
            }
        }
    }
    Enemy::Spawn((Matrix *) &sp50, arg1);
}
#endif

void FireTier1::SetDefaults() {
    Enemy::SetDefaults();
    this->unkB30 = 0.0f;
    this->unkB34 = 0.0f;
    this->unkB38 = 0.0f;
    this->unkB20 = 0.0f;
    this->unkB24 = 0.0f;
    this->unkB28 = 0.0f;
    this->unkB10 = 0.0f;
    this->unkB14 = 0.0f;
    this->unkB18 = 0.0f;
}

s32 FireTier1::GetCharacterName() {
    return M2C_FIELD(gpTranslation_StringArray, s32 *, 0x36C);
}

#if 0 // DRAFT: undefined identifier '__vptr'
void FireTier1::Init() {
    FireTier1Goal_Think *temp_r31_2133;

    Enemy::Init();
    operator new(0x38U, NULL, 0);
    temp_r31_2133 = M2C_ERROR(/* Read from unset register $r3 */);
    if (temp_r31_2133 != NULL) {
        temp_r31_2133->__vptr = &__vt__12Goal<5Enemy>;
        temp_r31_2133->unk4 = 0;
        temp_r31_2133->unk8 = 1;
        temp_r31_2133->unk9 = 0;
        temp_r31_2133->unkC = NULL;
        temp_r31_2133->__vptr = &__vt__21CompositeGoal<5Enemy>;
        temp_r31_2133->unk1C = NULL;
        temp_r31_2133->unk18 = 0;
        temp_r31_2133->unk10 = 0;
        temp_r31_2133->unk14 = 0;
        temp_r31_2133->__vptr = &__vt;
    }
    temp_r31_2133->Init((Enemy *) this);
    this->unkA3C = &temp_r31_2133->__vptr;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk244'
void FireTier1Descriptor::LoadDone() {
    EnemyDescriptor::LoadDone();
    this->unk244.Init(&fireTier1BodyFXInit, 2, (MKAnimScript *) this->unk34);
    this->unk2B4 = (long) (checked_cast<GoopFX *, MKProp>(gMK->CreateProp("GoopFX")));
}
#endif

#if 0 // DRAFT: undefined identifier 'fireTier1BodyFXInit'
void Enemies_Fire_cpp::__sinit() {
    f32 sp3A0;
    f32 sp39C;
    f32 sp398;
    f32 sp390;
    f32 sp38C;
    f32 sp388;
    f32 sp380;
    f32 sp37C;
    f32 sp378;
    f32 sp370;
    f32 sp36C;
    f32 sp368;
    f32 sp360;
    f32 sp35C;
    f32 sp358;
    f32 sp350;
    f32 sp34C;
    f32 sp348;
    f32 sp340;
    f32 sp33C;
    f32 sp338;
    f32 sp330;
    f32 sp32C;
    f32 sp328;
    f32 sp320;
    f32 sp31C;
    f32 sp318;
    f32 sp310;
    f32 sp30C;
    f32 sp308;
    f32 sp300;
    f32 sp2FC;
    f32 sp2F8;
    f32 sp2F0;
    f32 sp2EC;
    f32 sp2E8;
    f32 sp2E0;
    f32 sp2DC;
    f32 sp2D8;
    f32 sp2D0;
    f32 sp2CC;
    f32 sp2C8;
    f32 sp2C0;
    f32 sp2BC;
    f32 sp2B8;
    f32 sp2B0;
    f32 sp2AC;
    f32 sp2A8;
    f32 sp2A0;
    f32 sp29C;
    f32 sp298;
    f32 sp290;
    f32 sp28C;
    f32 sp288;
    f32 sp280;
    f32 sp27C;
    f32 sp278;
    f32 sp270;
    f32 sp26C;
    f32 sp268;
    f32 sp260;
    f32 sp25C;
    f32 sp258;
    f32 sp250;
    f32 sp24C;
    f32 sp248;
    f32 sp240;
    f32 sp23C;
    f32 sp238;
    f32 sp230;
    f32 sp22C;
    f32 sp228;
    f32 sp220;
    f32 sp21C;
    f32 sp218;
    f32 sp210;
    f32 sp20C;
    f32 sp208;
    f32 sp200;
    f32 sp1FC;
    f32 sp1F8;
    f32 sp1F0;
    f32 sp1EC;
    f32 sp1E8;
    f32 sp1E0;
    f32 sp1DC;
    f32 sp1D8;
    f32 sp1D0;
    f32 sp1CC;
    f32 sp1C8;
    f32 sp1C0;
    f32 sp1BC;
    f32 sp1B8;
    f32 sp1B0;
    f32 sp1AC;
    f32 sp1A8;
    f32 sp1A0;
    f32 sp19C;
    f32 sp198;
    f32 sp190;
    f32 sp18C;
    f32 sp188;
    f32 sp180;
    f32 sp17C;
    f32 sp178;
    f32 sp170;
    f32 sp16C;
    f32 sp168;
    f32 sp160;
    f32 sp15C;
    f32 sp158;
    f32 sp150;
    f32 sp14C;
    f32 sp148;
    f32 sp140;
    f32 sp13C;
    f32 sp138;
    f32 sp130;
    f32 sp12C;
    f32 sp128;
    f32 sp120;
    f32 sp11C;
    f32 sp118;
    f32 sp110;
    f32 sp10C;
    f32 sp108;
    f32 sp100;
    f32 spFC;
    f32 spF8;
    f32 spF0;
    f32 spEC;
    f32 spE8;
    f32 spE0;
    f32 spDC;
    f32 spD8;
    f32 spD0;
    f32 spCC;
    f32 spC8;
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
    f32 sp8C;
    f32 sp88;
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
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
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    void *temp_r3_2503;
    void *temp_r4_2311;

    sp390 = 0.0f;
    temp_r4_2311 = &fireTier1BodyFXInit + 0x60;
    sp3A0 = 1.0f;
    sp380 = 1.0f;
    sp370 = 0.0f;
    sp360 = 2.0f;
    sp350 = 0.0f;
    sp340 = 2.0f;
    sp330 = 0.0f;
    sp320 = 2.0f;
    sp398 = 1.0f;
    sp39C = 1.0f;
    sp388 = 0.0f;
    sp38C = 0.0f;
    sp378 = 1.0f;
    sp37C = 1.0f;
    sp368 = 0.0f;
    sp36C = 0.0f;
    sp358 = 2.0f;
    sp35C = 2.0f;
    sp348 = 0.0f;
    sp34C = 0.0f;
    sp338 = 2.0f;
    sp33C = 2.0f;
    sp328 = 0.0f;
    sp32C = 0.0f;
    sp318 = 2.0f;
    sp31C = 2.0f;
    M2C_FIELD(&fireTier1BodyFXInit, f64 *, 0x10) = (f64) sp398;
    M2C_FIELD(&fireTier1BodyFXInit, f64 *, 0x18) = (f64) sp3A0;
    M2C_FIELD(&fireTier1BodyFXInit, f64 *, 0x20) = (f64) sp388;
    M2C_FIELD(&fireTier1BodyFXInit, f64 *, 0x28) = (f64) sp390;
    M2C_FIELD(&fireTier1BodyFXInit, f64 *, 0x40) = (f64) sp378;
    M2C_FIELD(&fireTier1BodyFXInit, f64 *, 0x48) = (f64) sp380;
    M2C_FIELD(&fireTier1BodyFXInit, f64 *, 0x50) = (f64) sp368;
    M2C_FIELD(&fireTier1BodyFXInit, f64 *, 0x58) = (f64) sp370;
    M2C_FIELD(temp_r4_2311, f64 *, 0x10) = (f64) sp358;
    M2C_FIELD(temp_r4_2311, f64 *, 0x18) = (f64) sp360;
    M2C_FIELD(temp_r4_2311, f64 *, 0x20) = (f64) sp348;
    M2C_FIELD(temp_r4_2311, f64 *, 0x28) = (f64) sp350;
    M2C_FIELD(temp_r4_2311, f64 *, 0x40) = (f64) sp338;
    M2C_FIELD(temp_r4_2311, f64 *, 0x48) = (f64) sp340;
    M2C_FIELD(temp_r4_2311, f64 *, 0x50) = (f64) sp328;
    M2C_FIELD(temp_r4_2311, f64 *, 0x58) = (f64) sp330;
    M2C_FIELD(temp_r4_2311, f64 *, 0x70) = (f64) sp318;
    M2C_FIELD(temp_r4_2311, f64 *, 0x78) = (f64) sp320;
    sp310 = 0.0f;
    sp300 = 2.0f;
    sp2F0 = 0.0f;
    sp2E0 = 2.0f;
    sp2D0 = 0.0f;
    sp2C0 = 2.0f;
    sp2B0 = 0.0f;
    sp2A0 = 2.0f;
    sp290 = 0.0f;
    sp308 = 0.0f;
    sp30C = 0.0f;
    sp2F8 = 2.0f;
    sp2FC = 2.0f;
    sp2E8 = 0.0f;
    sp2EC = 0.0f;
    sp2D8 = 2.0f;
    sp2DC = 2.0f;
    sp2C8 = 0.0f;
    sp2CC = 0.0f;
    sp2B8 = 2.0f;
    sp2BC = 2.0f;
    sp2A8 = 0.0f;
    sp2AC = 0.0f;
    sp298 = 2.0f;
    sp29C = 2.0f;
    sp288 = 0.0f;
    sp28C = 0.0f;
    M2C_FIELD(temp_r4_2311, f64 *, 0x80) = (f64) sp308;
    M2C_FIELD(temp_r4_2311, f64 *, 0x88) = (f64) sp310;
    M2C_FIELD(temp_r4_2311, f64 *, 0xA0) = (f64) sp2F8;
    M2C_FIELD(temp_r4_2311, f64 *, 0xA8) = (f64) sp300;
    M2C_FIELD(temp_r4_2311, f64 *, 0xB0) = (f64) sp2E8;
    M2C_FIELD(temp_r4_2311, f64 *, 0xB8) = (f64) sp2F0;
    M2C_FIELD(temp_r4_2311, f64 *, 0xD0) = (f64) sp2D8;
    M2C_FIELD(temp_r4_2311, f64 *, 0xD8) = (f64) sp2E0;
    M2C_FIELD(temp_r4_2311, f64 *, 0xE0) = (f64) sp2C8;
    M2C_FIELD(temp_r4_2311, f64 *, 0xE8) = (f64) sp2D0;
    M2C_FIELD(temp_r4_2311, f64 *, 0x100) = (f64) sp2B8;
    M2C_FIELD(temp_r4_2311, f64 *, 0x108) = (f64) sp2C0;
    M2C_FIELD(temp_r4_2311, f64 *, 0x110) = (f64) sp2A8;
    M2C_FIELD(temp_r4_2311, f64 *, 0x118) = (f64) sp2B0;
    M2C_FIELD(temp_r4_2311, f64 *, 0x130) = (f64) sp298;
    M2C_FIELD(temp_r4_2311, f64 *, 0x138) = (f64) sp2A0;
    M2C_FIELD(temp_r4_2311, f64 *, 0x140) = (f64) sp288;
    M2C_FIELD(temp_r4_2311, f64 *, 0x148) = (f64) sp290;
    sp278 = 2.0f;
    sp27C = 2.0f;
    sp280 = 2.0f;
    sp270 = 0.0f;
    sp260 = 2.0f;
    sp250 = 0.0f;
    sp240 = 2.0f;
    sp230 = 0.0f;
    sp220 = 2.0f;
    sp210 = 0.0f;
    sp200 = 2.0f;
    sp268 = 0.0f;
    sp26C = 0.0f;
    sp258 = 2.0f;
    sp25C = 2.0f;
    sp248 = 0.0f;
    sp24C = 0.0f;
    sp238 = 2.0f;
    sp23C = 2.0f;
    sp228 = 0.0f;
    sp22C = 0.0f;
    sp218 = 2.0f;
    sp21C = 2.0f;
    sp208 = 0.0f;
    sp20C = 0.0f;
    sp1F8 = 2.0f;
    sp1FC = 2.0f;
    M2C_FIELD(temp_r4_2311, f64 *, 0x160) = (f64) sp278;
    M2C_FIELD(temp_r4_2311, f64 *, 0x168) = (f64) sp280;
    M2C_FIELD(temp_r4_2311, f64 *, 0x170) = (f64) sp268;
    M2C_FIELD(temp_r4_2311, f64 *, 0x178) = (f64) sp270;
    M2C_FIELD(temp_r4_2311, f64 *, 0x190) = (f64) sp258;
    M2C_FIELD(temp_r4_2311, f64 *, 0x198) = (f64) sp260;
    M2C_FIELD(temp_r4_2311, f64 *, 0x1A0) = (f64) sp248;
    M2C_FIELD(temp_r4_2311, f64 *, 0x1A8) = (f64) sp250;
    M2C_FIELD(temp_r4_2311, f64 *, 0x1C0) = (f64) sp238;
    M2C_FIELD(temp_r4_2311, f64 *, 0x1C8) = (f64) sp240;
    M2C_FIELD(temp_r4_2311, f64 *, 0x1D0) = (f64) sp228;
    M2C_FIELD(temp_r4_2311, f64 *, 0x1D8) = (f64) sp230;
    M2C_FIELD(temp_r4_2311, f64 *, 0x1F0) = (f64) sp218;
    M2C_FIELD(temp_r4_2311, f64 *, 0x1F8) = (f64) sp220;
    M2C_FIELD(temp_r4_2311, f64 *, 0x200) = (f64) sp208;
    M2C_FIELD(temp_r4_2311, f64 *, 0x208) = (f64) sp210;
    M2C_FIELD(temp_r4_2311, f64 *, 0x220) = (f64) sp1F8;
    M2C_FIELD(temp_r4_2311, f64 *, 0x228) = (f64) sp200;
    sp1E8 = 0.0f;
    sp1EC = 0.0f;
    temp_r3_2503 = &fireTier1BodyFXInit + 0x300;
    sp1F0 = 0.0f;
    sp1E0 = 2.0f;
    sp1D0 = 0.0f;
    sp1C0 = 2.0f;
    sp1B0 = 0.0f;
    sp1A0 = 3.0f;
    sp190 = 0.0f;
    sp180 = 2.0f;
    sp170 = 0.0f;
    sp1D8 = 2.0f;
    sp1DC = 2.0f;
    sp1C8 = 0.0f;
    sp1CC = 0.0f;
    sp1B8 = 2.0f;
    sp1BC = 2.0f;
    sp1A8 = 0.0f;
    sp1AC = 0.0f;
    sp198 = 3.0f;
    sp19C = 3.0f;
    sp188 = 0.0f;
    sp18C = 0.0f;
    sp178 = 2.0f;
    sp17C = 2.0f;
    sp168 = 0.0f;
    sp16C = 0.0f;
    M2C_FIELD(temp_r4_2311, f64 *, 0x230) = (f64) sp1E8;
    M2C_FIELD(temp_r4_2311, f64 *, 0x238) = (f64) sp1F0;
    M2C_FIELD(temp_r4_2311, f64 *, 0x250) = (f64) sp1D8;
    M2C_FIELD(temp_r4_2311, f64 *, 0x258) = (f64) sp1E0;
    M2C_FIELD(temp_r4_2311, f64 *, 0x260) = (f64) sp1C8;
    M2C_FIELD(temp_r4_2311, f64 *, 0x268) = (f64) sp1D0;
    M2C_FIELD(temp_r4_2311, f64 *, 0x280) = (f64) sp1B8;
    M2C_FIELD(temp_r4_2311, f64 *, 0x288) = (f64) sp1C0;
    M2C_FIELD(temp_r4_2311, f64 *, 0x290) = (f64) sp1A8;
    M2C_FIELD(temp_r4_2311, f64 *, 0x298) = (f64) sp1B0;
    M2C_FIELD(temp_r3_2503, f64 *, 0x10) = (f64) sp198;
    M2C_FIELD(temp_r3_2503, f64 *, 0x18) = (f64) sp1A0;
    M2C_FIELD(temp_r3_2503, f64 *, 0x20) = (f64) sp188;
    M2C_FIELD(temp_r3_2503, f64 *, 0x28) = (f64) sp190;
    M2C_FIELD(temp_r3_2503, f64 *, 0x40) = (f64) sp178;
    M2C_FIELD(temp_r3_2503, f64 *, 0x48) = (f64) sp180;
    M2C_FIELD(temp_r3_2503, f64 *, 0x50) = (f64) sp168;
    M2C_FIELD(temp_r3_2503, f64 *, 0x58) = (f64) sp170;
    sp158 = 2.0f;
    sp15C = 2.0f;
    sp160 = 2.0f;
    sp150 = 0.0f;
    sp140 = 4.0f;
    sp130 = 0.0f;
    sp120 = 2.0f;
    sp110 = 0.0f;
    sp100 = 2.0f;
    spF0 = 0.0f;
    spE0 = 4.0f;
    spD0 = 0.0f;
    sp148 = 0.0f;
    sp14C = 0.0f;
    sp138 = 4.0f;
    sp13C = 4.0f;
    sp128 = 0.0f;
    sp12C = 0.0f;
    sp118 = 2.0f;
    sp11C = 2.0f;
    sp108 = 0.0f;
    sp10C = 0.0f;
    spF8 = 2.0f;
    spFC = 2.0f;
    spE8 = 0.0f;
    spEC = 0.0f;
    spD8 = 4.0f;
    spDC = 4.0f;
    spC8 = 0.0f;
    spCC = 0.0f;
    M2C_FIELD(temp_r3_2503, f64 *, 0x70) = (f64) sp158;
    M2C_FIELD(temp_r3_2503, f64 *, 0x78) = (f64) sp160;
    M2C_FIELD(temp_r3_2503, f64 *, 0x80) = (f64) sp148;
    M2C_FIELD(temp_r3_2503, f64 *, 0x88) = (f64) sp150;
    M2C_FIELD(temp_r3_2503, f64 *, 0xA0) = (f64) sp138;
    M2C_FIELD(temp_r3_2503, f64 *, 0xA8) = (f64) sp140;
    M2C_FIELD(temp_r3_2503, f64 *, 0xB0) = (f64) sp128;
    M2C_FIELD(temp_r3_2503, f64 *, 0xB8) = (f64) sp130;
    M2C_FIELD(temp_r3_2503, f64 *, 0xD0) = (f64) sp118;
    M2C_FIELD(temp_r3_2503, f64 *, 0xD8) = (f64) sp120;
    M2C_FIELD(temp_r3_2503, f64 *, 0xE0) = (f64) sp108;
    M2C_FIELD(temp_r3_2503, f64 *, 0xE8) = (f64) sp110;
    M2C_FIELD(temp_r3_2503, f64 *, 0x100) = (f64) spF8;
    M2C_FIELD(temp_r3_2503, f64 *, 0x108) = (f64) sp100;
    M2C_FIELD(temp_r3_2503, f64 *, 0x110) = (f64) spE8;
    M2C_FIELD(temp_r3_2503, f64 *, 0x118) = (f64) spF0;
    M2C_FIELD(temp_r3_2503, f64 *, 0x130) = (f64) spD8;
    M2C_FIELD(temp_r3_2503, f64 *, 0x138) = (f64) spE0;
    M2C_FIELD(temp_r3_2503, f64 *, 0x140) = (f64) spC8;
    M2C_FIELD(temp_r3_2503, f64 *, 0x148) = (f64) spD0;
    spC0 = 3.0f;
    spB0 = 0.0f;
    spA0 = 3.0f;
    sp90 = 0.0f;
    sp80 = 3.0f;
    sp70 = 0.0f;
    sp60 = 3.0f;
    sp50 = 0.0f;
    sp40 = 3.0f;
    sp30 = 0.0f;
    sp20 = 3.0f;
    sp10 = 0.0f;
    spB8 = 3.0f;
    spBC = 3.0f;
    spA8 = 0.0f;
    spAC = 0.0f;
    sp98 = 3.0f;
    sp9C = 3.0f;
    sp88 = 0.0f;
    sp8C = 0.0f;
    sp78 = 3.0f;
    sp7C = 3.0f;
    sp68 = 0.0f;
    sp6C = 0.0f;
    sp58 = 3.0f;
    sp5C = 3.0f;
    sp48 = 0.0f;
    sp4C = 0.0f;
    sp38 = 3.0f;
    sp3C = 3.0f;
    sp28 = 0.0f;
    sp2C = 0.0f;
    sp18 = 3.0f;
    sp1C = 3.0f;
    sp8 = 0.0f;
    spC = 0.0f;
    M2C_FIELD(temp_r3_2503, f64 *, 0x160) = (f64) spB8;
    M2C_FIELD(temp_r3_2503, f64 *, 0x168) = (f64) spC0;
    M2C_FIELD(temp_r3_2503, f64 *, 0x170) = (f64) spA8;
    M2C_FIELD(temp_r3_2503, f64 *, 0x178) = (f64) spB0;
    M2C_FIELD(temp_r3_2503, f64 *, 0x190) = (f64) sp98;
    M2C_FIELD(temp_r3_2503, f64 *, 0x198) = (f64) spA0;
    M2C_FIELD(temp_r3_2503, f64 *, 0x1A0) = (f64) sp88;
    M2C_FIELD(temp_r3_2503, f64 *, 0x1A8) = (f64) sp90;
    M2C_FIELD(temp_r3_2503, f64 *, 0x1C0) = (f64) sp78;
    M2C_FIELD(temp_r3_2503, f64 *, 0x1C8) = (f64) sp80;
    M2C_FIELD(temp_r3_2503, f64 *, 0x1D0) = (f64) sp68;
    M2C_FIELD(temp_r3_2503, f64 *, 0x1D8) = (f64) sp70;
    M2C_FIELD(temp_r3_2503, f64 *, 0x1F0) = (f64) sp58;
    M2C_FIELD(temp_r3_2503, f64 *, 0x1F8) = (f64) sp60;
    M2C_FIELD(temp_r3_2503, f64 *, 0x200) = (f64) sp48;
    M2C_FIELD(temp_r3_2503, f64 *, 0x208) = (f64) sp50;
    M2C_FIELD(temp_r3_2503, f64 *, 0x220) = (f64) sp38;
    M2C_FIELD(temp_r3_2503, f64 *, 0x228) = (f64) sp40;
    M2C_FIELD(temp_r3_2503, f64 *, 0x230) = (f64) sp28;
    M2C_FIELD(temp_r3_2503, f64 *, 0x238) = (f64) sp30;
    M2C_FIELD(temp_r3_2503, f64 *, 0x250) = (f64) sp18;
    M2C_FIELD(temp_r3_2503, f64 *, 0x258) = (f64) sp20;
    M2C_FIELD(temp_r3_2503, f64 *, 0x260) = (f64) sp8;
    M2C_FIELD(temp_r3_2503, f64 *, 0x268) = (f64) sp10;
}
#endif
