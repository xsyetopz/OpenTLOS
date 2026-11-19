#include "spyro/source/ExplosiveBarrelSpawner.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
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
#include "spyro/source/BurningWick.h"
#include "spyro/source/Crate.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/ExplosiveBarrel.h"
#include "spyro/source/ExplosiveBarrelPath.h"
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
#include "spyro/source/Shadow.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/TargetManager.h"
#include "unplaced_templates.h"
#include <m2c_macros.h>

extern MKSceneManager *gMK;

void *ExplosiveBarrelSpawner::Update() {
    void *temp_r3_44;
    void *temp_r3_53;
    void *temp_r3_58;

    temp_r3_44 = this->unkC8;
    if ((temp_r3_44 != NULL) && (M2C_FIELD(M2C_FIELD(temp_r3_44, void **, 0x44), u8 (**)(), 0xB8)() != 0)) {
        temp_r3_53 = this->unkC8;
        M2C_FIELD(M2C_FIELD(temp_r3_53, void **, 0x44), M2C_UNK (**)(void *), 0x20)(temp_r3_53);
        temp_r3_58 = this->unkC8;
        M2C_FIELD(M2C_FIELD(temp_r3_58, void **, 0x44), M2C_UNK (**)(void *), 0x30)(temp_r3_58);
    }
}

#if 0 // DRAFT: identifier 'ExplosiveBarrelSpawner::LoadDone()' redeclared was declared as: 'long ()' now declared as: 'void ()'
void ExplosiveBarrelSpawner::LoadDone() {
    MKProp *temp_r3_87;
    s32 var_r30_81;

    GameProp::LoadDone();
    var_r30_81 = 0;
    while (var_r30_81 < *(s32 *) ((s8 *) checked_cast<ExplosiveBarrelSpawnerDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + 0xE4)) {
        temp_r3_87 = gMK->CreateProp("ExplosiveBarrel");
        this->unkC8 = checked_cast<ExplosiveBarrel *, MKProp>(temp_r3_87);
        temp_r3_87->Enable();
        var_r30_81 += 1;
    }
}
#endif

s32 ExplosiveBarrelSpawnerDescriptor::LoadLine(MKIniLine *arg0) {
    GamePropDescriptor::LoadLine(arg0);
}

void ExplosiveBarrelSpawnerDescriptor::Init() {
    GamePropDescriptor::Init();
    M2C_FIELD(this, s32 *, 0xE4) = 1;
}
