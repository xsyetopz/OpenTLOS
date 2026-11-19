#include "spyro/source/MineCartDoor.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
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
#include <m2c_macros.h>

void MineCartDoor::SetState(int arg0) {
    this->unkC8 = arg0;
    this->unk80->SetAnim(M2C_FIELD((checked_cast<MineCartDoorDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + (this->unkC8 * 4)), MKAnim **, 0xE4), 1.0f, 0.0f, 0, -1);
}

void MineCartDoor::Message(MKMessage *arg0) {
    s32 temp_r0_74;

    temp_r0_74 = arg0->unk0;
    switch (temp_r0_74) {                           /* irregular */
    case 0xBB:
        if ((s32) this->unkC8 == 3) {
            SetState(0);
        }
        break;
    case 0xBC:
        if ((s32) this->unkC8 == 1) {
            SetState(2);
        }
        break;
    }
    GameProp::Message(arg0);
}

void *MineCartDoor::Update() {
    s32 temp_r0_114;

    GameProp::Update();
    temp_r0_114 = this->unkC8;
    switch (temp_r0_114) {                          /* irregular */
    case 0:
        if (this->unk80->unk2C & 1) {
            SetState(1);
            return;
        }
    case 1:
        return;
    case 2:
        if (this->unk80->unk2C & 1) {
            SetState(3);
        }
        break;
    }
}

void MineCartDoor::Reset() {
    GameProp::Reset();
    SetState(3);
}

void MineCartDoorDescriptor::LoadDone() {
    GamePropDescriptor::LoadDone();
    M2C_FIELD(this, void **, 0xE4) = ((MKAnimScript *) this->unk34)->GetAnim("Opening");
    this->unkE8 = (long) (((MKAnimScript *) this->unk34)->GetAnim("Open"));
    this->unkEC = (long) (((MKAnimScript *) this->unk34)->GetAnim("Closing"));
    this->unkF0 = (long) (((MKAnimScript *) this->unk34)->GetAnim("Closed"));
}
