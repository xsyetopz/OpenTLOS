#include "spyro/source/CollideBox.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKResource.h"
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
#include <m2c_macros.h>

void CollideBox::Message(MKMessage *arg0) {
    s32 temp_r0_48;

    temp_r0_48 = arg0->unk0;
    switch (temp_r0_48) {                           /* irregular */
    case 0xBE:
    case 0xB5:
        this->unk70.unk4 = 1;
        break;
    case 0xBF:
        this->unk70.unk4 = 0;
        break;
    }
    KDProp::Message(arg0);
}

void CollideBox::LoadDone() {
    KDProp::LoadDone();
    if ((u8) this->unk90 != 0) {
        this->unk70.unk4 = 1;
        return;
    }
    this->unk70.unk4 = 0;
}

#if 0 // DRAFT: illegal implicit conversion from 'unsigned char *' to
s32 CollideBox::LoadLine(MKIniLine *arg0) {
    s32 var_r31_112;

    var_r31_112 = 0;
    if ((KDProp::LoadLine(arg0) != 0) || (arg0->LoadBool("bEnabled", &this->unk90, 0) != 0)) {
        var_r31_112 = 1;
    }
    return var_r31_112;
}
#endif

void CollideBox::Init() {
    KDProp::Init();
    this->unk90 = 1;
}
