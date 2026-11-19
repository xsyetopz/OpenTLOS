#include "spyro/source/Kane.h"
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
#include "spyro/source/KaneGoal_Think.h"
#include "spyro/source/MeleeTrails.h"
#include "spyro/source/Names.h"
#include "spyro/source/NodeLookAt.h"
#include "spyro/source/SB2.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/SpawnPointObject.h"
#include "spyro/source/SpawnerObject.h"
#include "spyro/source/TargetManager.h"
#include "unplaced_templates.h"
#include <m2c_macros.h>

#if 0 // DRAFT: illegal implicit conversion from 'unsigned char *' to
s32 Kane::LoadLine(MKIniLine *arg0) {
    if ((Enemy::LoadLine(arg0) != 0) || (arg0->LoadBool("StartEnabled", (u8 *) &this->unkB14, 0) != 0) || (arg0->LoadInt("StartNode", (int *) &this->unkB10, 0) != 0)) {
        return 1;
    }
    return 0;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'CharacterGraphNodeProp *' to
f32 Kane::Resolve() {
    s32 spC;
    s32 sp8;
    u32 temp_r3_91;

    Enemy::Resolve();
    temp_r3_91 = checked_cast<CharacterGraphNodeProp *, MKProp>(((MKSceneManager *) this->unkB10)->PropResolver_Resolve(M2C_ERROR(/* Read from unset register $r4 */)));
    if (temp_r3_91 != 0U) {
        this->unkA80 = temp_r3_91 + 0x50;
    }
    M2C_FIELD(this->unkA3C, s8 *, 8) = 1;
    if ((u8) M2C_FIELD(this, u8 *, 0xB14) == 0) {
        spC = 0;
        sp8 = 0xBF;
        Message(&sp8);
        Disable();
    }
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void Kane::Init() {
    KaneGoal_Think *temp_r31_139;

    Enemy::Init();
    operator new(0x2CU, NULL, 0);
    temp_r31_139 = M2C_ERROR(/* Read from unset register $r3 */);
    if (temp_r31_139 != NULL) {
        temp_r31_139->__vptr = &__vt__12Goal<5Enemy>;
        temp_r31_139->unk4 = 0;
        temp_r31_139->unk8 = 1;
        temp_r31_139->unk9 = 0;
        temp_r31_139->unkC = 0;
        temp_r31_139->__vptr = &__vt__21CompositeGoal<5Enemy>;
        temp_r31_139->unk1C = 0;
        temp_r31_139->unk18 = 0;
        temp_r31_139->unk10 = 0;
        temp_r31_139->unk14 = 0;
        temp_r31_139->__vptr = &__vt;
    }
    temp_r31_139->Init((Enemy *) this);
    this->unkA3C = &temp_r31_139->__vptr;
    M2C_FIELD(this, s8 *, 0xB14) = 0;
    this->unkB10 = 0;
}
#endif
