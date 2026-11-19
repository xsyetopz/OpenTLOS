#include "spyro/source/CounterProp.h"
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

void CounterProp::Deinit() {
    MKProp::Deinit();
}

void CounterProp::Message(MKMessage *arg0) {
    s32 temp_r0_67;

    temp_r0_67 = arg0->unk0;
    switch (temp_r0_67) {                           /* irregular */
    case 0x14E:
        this->unk54 += 1;
        if (((s32) this->unk54 >= (s32) this->unk50) && ((u8) this->unk59 == 0)) {
            this->unk4C.Send(NULL);
            if ((u8) this->unk58 != 0) {
                this->unk54 = 0;
            } else {
                this->unk59 = 1;
            }
        }
        break;
    case 0x14F:
        this->unk54 -= 1;
        break;
    case 0xD5:
        this->unk54 = 0;
        this->unk59 = 0;
        break;
    }
    MKProp::Message(arg0);
}

s32 CounterProp::LoadLine(MKIniLine *arg0) {
    s32 var_r31_131;

    var_r31_131 = 0;
    if ((MKProp::LoadLine(arg0) != 0) || (arg0->LoadInt("iCountSize", (int *) &this->unk50, 0) != 0) || (arg0->LoadBool("bResetOnCount", (bool *) &this->unk58, 0) != 0) || (this->unk4C.LoadLine(arg0, "OnCount") != 0)) {
        var_r31_131 = 1;
    }
    return var_r31_131;
}

void CounterProp::Init() {
    MKProp::Init();
    this->unk50 = 0;
    this->unk54 = 0;
    this->unk59 = 0;
    this->unk58 = 0;
}
