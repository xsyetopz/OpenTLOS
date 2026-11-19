#include "spyro/source/CynderPortcullis.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "spyro/source/AssaultCannon.h"
#include "spyro/source/Crate.h"
#include "spyro/source/EnemyGenerator.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/GlowingPropManager.h"
#include "spyro/source/KDMatrixProperty.h"
#include "spyro/source/KDMatrixRefProperty.h"
#include "spyro/source/KDPositionProperty.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDProperty.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/KDStateMachine.h"
#include "spyro/source/PlatformObject.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/ShatterablePlatform.h"
#include "spyro/source/SpawnPointObject.h"
#include "spyro/source/SpawnerObject.h"
#include "spyro/source/TargetManager.h"
#include "unplaced_templates.h"
#include <m2c_macros.h>

void CynderPortcullis::Message(MKMessage *arg0) {
    s32 temp_r0_72;

    temp_r0_72 = arg0->unk0;
    if (temp_r0_72 < 0xB6) {
        if (temp_r0_72 < 0xB4) {

        } else {
            this->unkC8.Message(arg0);
        }
    }
    GameProp::Message(arg0);
}

void *CynderPortcullis::Update() {
    GameProp::Update();
    this->unkC8.Update();
}

f32 CynderPortcullis::Resolve() {
    KDPropEx::Resolve();
    this->unkC8.Resolve();
}

s32 CynderPortcullis::LoadDone() {
    GameProp::LoadDone();
    this->unkC8.LoadDone();
}

s32 CynderPortcullis::LoadLine(MKIniLine *arg0) {
    s32 var_r31_155;

    var_r31_155 = 0;
    if ((GameProp::LoadLine(arg0) != 0) || (this->unkC8.LoadLine(arg0) != 0)) {
        var_r31_155 = 1;
    }
    return var_r31_155;
}

void CynderPortcullis::Deinit() {
    this->unkC8.Deinit();
    GameProp::Deinit();
}

void CynderPortcullis::Init() {
    CynderPortcullisDescriptor *desc;
    EnemyGeneratorDescriptor *gen;

    GameProp::Init();
    desc = checked_cast<CynderPortcullisDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    gen = (EnemyGeneratorDescriptor *) ((s8 *) desc + 0xE4);
    this->unkC8.Init(gen, (MKProp *) this);
}

void CynderPortcullisDescriptor::LoadDone() {
    GamePropDescriptor::LoadDone();
    M2C_FIELD(this, EnemyGeneratorDescriptor *, 0xE4).LoadDone();
}

s32 CynderPortcullisDescriptor::LoadLine(MKIniLine *arg0) {
    s32 var_r31_247;

    var_r31_247 = 0;
    if ((GamePropDescriptor::LoadLine(arg0) != 0) || (M2C_FIELD(this, EnemyGeneratorDescriptor *, 0xE4).LoadLine(arg0) != 0)) {
        var_r31_247 = 1;
    }
    return var_r31_247;
}

void CynderPortcullisDescriptor::Deinit() {
    M2C_FIELD(this, EnemyGeneratorDescriptor *, 0xE4).Deinit();
    KDPropExDescriptor::Deinit();
}

void CynderPortcullisDescriptor::Init() {
    GamePropDescriptor::Init();
    this->unk64 |= 0x2000;
    M2C_FIELD(this, EnemyGeneratorDescriptor *, 0xE4).Init();
}
