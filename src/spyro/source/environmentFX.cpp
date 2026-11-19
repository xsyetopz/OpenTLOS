#include "spyro/source/environmentFX.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "spyro/source/AssaultCannon.h"
#include "spyro/source/Crate.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/GlowingPropManager.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/KDStateMachine.h"
#include "spyro/source/PlatformObject.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/ShatterablePlatform.h"
#include "spyro/source/TargetManager.h"
#include "unplaced_enums.h"
#include <m2c_macros.h>

extern M2C_UNK gb;

void *EnvironmentFX::Update() {
    MKProp::Update();
    if ((M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), u8 (**)(void *), 0x58)(M2C_FIELD(&gb, void **, 0x3B8)) != 0) && ((u8) this->unk4C == 0)) {
        this->unk4C = 1;
        KDSound_GetAcousticProperty();
        this->unk50 = M2C_ERROR(/* Read from unset register $r3 */);
        KDSound_SetAcousticProperty((Sound_AcousticProperty) 1);
        return;
    }
    if ((M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), u8 (**)(void *), 0x58)(M2C_FIELD(&gb, void **, 0x3B8)) == 0) && ((u8) this->unk4C != 0)) {
        this->unk4C = 0;
        KDSound_SetAcousticProperty((Sound_AcousticProperty) this->unk50);
    }
}

void EnvironmentFX::Message(MKMessage *arg0) {
    s32 temp_r3_98;

    temp_r3_98 = arg0->unk0;
    switch (temp_r3_98) {
    case 0xE7:
        KDSound_SetAcousticProperty((Sound_AcousticProperty) 0);
        break;
    case 0xE8:
        KDSound_SetAcousticProperty((Sound_AcousticProperty) 1);
        break;
    case 0xEA:
        KDSound_SetAcousticProperty((Sound_AcousticProperty) 2);
        break;
    case 0xEB:
        KDSound_SetAcousticProperty((Sound_AcousticProperty) 3);
        break;
    case 0xEC:
        KDSound_SetAcousticProperty((Sound_AcousticProperty) 4);
        break;
    case 0xED:
        KDSound_SetAcousticProperty((Sound_AcousticProperty) 5);
        break;
    case 0xE9:
        KDSound_SetAcousticProperty((Sound_AcousticProperty) 6);
        break;
    }
    MKProp::Message(arg0);
}

void EnvironmentFX::Reset() {
    MKProp::Reset();
    KDSound_SetAcousticProperty((Sound_AcousticProperty) 0);
}

void EnvironmentFX::Deinit() {
    MKProp::Deinit();
    KDSound_SetAcousticProperty((Sound_AcousticProperty) 0);
}

void EnvironmentFX::Init() {
    MKProp::Init();
    this->unk4C = 0;
    this->unk50 = 0;
}
