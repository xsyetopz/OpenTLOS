#include "spyro/source/TrainGate.h"
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
#include "spyro/source/TargetManager.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include <m2c_macros.h>

void TrainGate::SetState(TrainGateState arg0) {
    this->unkCC = (s32) arg0;
    this->unk80->SetAnim(M2C_FIELD((checked_cast<TrainGateDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + (this->unkCC * 4)), MKAnim **, 0xE4), 1.0f, 0.0f, 0, -1);
}

void TrainGate::Message(MKMessage *arg0) {
    s32 temp_r0_80;

    temp_r0_80 = arg0->unk0;
    switch (temp_r0_80) {                           /* irregular */
    case 0xB5:
        this->unkD4 += 1;
        if ((s32) this->unkD4 >= (s32) this->unkD0) {
            this->unkC8.Send(NULL);
            SetState((TrainGateState) 1);
        }
        break;
    case 0xB4:
        Reset();
        break;
    }
    GameProp::Message(arg0);
}

void TrainGate::Update() {
    GameProp::Update();
    if ((s32) this->unkCC != 1) {
        return;
    }
    if (this->unk80->unk2C & 1) {
        SetState((TrainGateState) 2);
    }
}

void TrainGate::Reset() {
    GameProp::Reset();
    SetState((TrainGateState) 0);
    this->unkD4 = 0;
}

void TrainGate::Resolve() {
    KDPropEx::Resolve();
}

void TrainGate::LoadDone() {
    GameProp::LoadDone();
}

s32 TrainGate::LoadLine(MKIniLine *arg0) {
    s32 var_r31_203;

    var_r31_203 = 0;
    if ((GameProp::LoadLine(arg0) != 0) || (this->unkC8.LoadLine(arg0, "onOpened") != 0) || (arg0->LoadInt("NumSwitches", (int *) &this->unkD0, 0) != 0)) {
        var_r31_203 = 1;
    }
    return var_r31_203;
}

void TrainGate::Deinit() {
    GameProp::Deinit();
}

void TrainGate::Init() {
    GameProp::Init();
    this->unkD0 = 3;
    this->unkD4 = 0;
}

#if 0 // DRAFT: undefined identifier 'unkE4'
void TrainGateDescriptor::Resolve() {
    MKPropDescriptor::Resolve();
    this->unkE4 = ((MKAnimScript *) this->unk34)->GetAnim("closed");
    this->unkE8 = ((MKAnimScript *) this->unk34)->GetAnim("opening");
    this->unkEC = ((MKAnimScript *) this->unk34)->GetAnim("open");
}
#endif
