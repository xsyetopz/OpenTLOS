#include "spyro/source/NPCGuardian.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
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
#include "spyro/source/Crate.h"
#include "spyro/source/Enemy.h"
#include "spyro/source/EnemyAttackPattern.h"
#include "spyro/source/EnemyDataTypes.h"
#include "spyro/source/EnemyDescriptor.h"
#include "spyro/source/EnemyRegion.h"
#include "spyro/source/EnemySettings.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/GlowingPropManager.h"
#include "spyro/source/Goal.h"
#include "spyro/source/IceBitsPS.h"
#include "spyro/source/KDMatrixRefProperty.h"
#include "spyro/source/KDPath.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDProperty.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/KDStateMachine.h"
#include "spyro/source/MeleeTrails.h"
#include "spyro/source/NPCGuardianGoal_Think.h"
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
#include <m2c_macros.h>

void NPCGuardian::Message(MKMessage *arg0) {
    if ((s32) arg0->unk0 != 0xB5) {

    } else {
        this->unkB10 = 1;
    }
    Enemy::Message(arg0);
}

#if 0 // DRAFT: ')' expected
f32 NPCGuardian::Resolve() {
    MKSceneManager *temp_r3_74;
    s32 temp_r31_86;
    u32 temp_r3_78;

    Enemy::Resolve();
    temp_r3_74 = this->unkB18;
    if (temp_r3_74 != NULL) {
        temp_r3_78 = (unsigned long) (checked_cast<CharacterGraphNodeProp *, MKProp>(temp_r3_74->PropResolver_Resolve(M2C_ERROR(/* Read from unset register $r4 */))));
        if (temp_r3_78 != 0U) {
            this->unkA80 = temp_r3_78 + 0x50;
            this->unkA90 = 0;
        }
    }
    temp_r31_86 = this->unkB1C;
    M2C_FIELD(checked_cast<NPCGuardianGoal_Think *, Goal<Enemy>>((Goal<Enemy> *) this->unkA3C), s32 *, 0x20) = temp_r31_86;
    if (!(this->unk680 & 0x160000)) {
        Disable();
    }
    this->unkB14.Send(NULL);
}
#endif

s32 NPCGuardian::LoadDone() {
    Enemy::LoadDone();
}

s32 NPCGuardian::LoadLine(MKIniLine *arg0) {
    if (Enemy::LoadLine(arg0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("FollowGraphID", (int *) &this->unkB18, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("Behaviour", (int *) &this->unkB1C, 0) != 0) {
        return 1U;
    }
    return (u8) (this->unkB14.LoadLine(arg0, "OnLoad") != 0);
}

#if 0 // DRAFT: undefined identifier '__vptr'
void NPCGuardian::Init() {
    NPCGuardianGoal_Think *temp_r31_191;

    Enemy::Init();
    operator new(0x34U, NULL, 0);
    temp_r31_191 = M2C_ERROR(/* Read from unset register $r3 */);
    if (temp_r31_191 != NULL) {
        temp_r31_191->__vptr = &__vt__12Goal<5Enemy>;
        temp_r31_191->unk4 = 0;
        temp_r31_191->unk8 = 1;
        temp_r31_191->unk9 = 0;
        temp_r31_191->unkC = 0;
        temp_r31_191->__vptr = &__vt__21CompositeGoal<5Enemy>;
        temp_r31_191->unk1C = 0;
        temp_r31_191->unk18 = 0;
        temp_r31_191->unk10 = 0;
        temp_r31_191->unk14 = 0;
        temp_r31_191->__vptr = &__vt;
    }
    temp_r31_191->Init((Enemy *) this);
    this->unkA3C = &temp_r31_191->__vptr;
    this->unk598 = 0.0f;
    this->unk59C = 0.0f;
    this->unk5A0 = 0.0f;
    this->unkB18 = NULL;
    this->unkB10 = 0;
}
#endif
