#include "spyro/source/SpikeTrap.h"
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
#include "spyro/source/Trap.h"
#include "unplaced_templates.h"
#include "spyro/source/PropFlags.h"
#include <m2c_macros.h>

void SpikeTrap::SetState(int arg0) {
    this->unkE0 = arg0;
    this->unk80->SetAnim(M2C_FIELD((checked_cast<SpikeTrapDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + (this->unkE0 * 4)), MKAnim **, 0xE4), 1.0f, 0.0f, 0, -1);
}

void SpikeTrap::Message(MKMessage *arg0) {
    if ((s32) arg0->unk0 != 0x12) {

    } else {
        this->unkE4 = 1;
    }
    Trap::Message(arg0);
}

void SpikeTrap::Reset() {
    Trap::Reset();
    this->unkE4 = 0;
    SetState(0);
}

void *SpikeTrap::Update() {
    s32 temp_r0_132;

    GameProp::Update();
    if (this->unk10 & 0x20000) {
        temp_r0_132 = this->unkE0;
        switch (temp_r0_132) {                      /* irregular */
        default:
        case 0:
            if ((u8) this->unkE4 != 0) {
                SetState(1);
            }
            break;
        case 1:
            if (this->unk80->unk2C & 1) {
                this->unkE8.Send((MKProp *) this);
                SetState(2);
            }
            break;
        case 2:
            if ((u8) this->unkE4 == 0) {
                this->unkEC.Send((MKProp *) this);
                SetState(3);
            }
            break;
        case 3:
            if (this->unk80->unk2C & 1) {
                SetState(0);
            }
            break;
        }
        this->unkE4 = 0;
    }
}

s32 SpikeTrap::LoadDone() {
    Trap::LoadDone();
}

s32 SpikeTrap::LoadLine(MKIniLine *arg0) {
    s32 var_r31_216;

    var_r31_216 = 0;
    if ((Trap::LoadLine(arg0) != 0) || (this->unkE8.LoadLine(arg0, "OnPressed") != 0) || (this->unkEC.LoadLine(arg0, "OnReleased") != 0)) {
        var_r31_216 = 1;
    }
    return var_r31_216;
}

void SpikeTrap::Deinit() {
    GameProp::Deinit();
}

void SpikeTrap::Init() {
    Trap::Init();
    PropFlagsSet((unsigned int *) &this->unk10, 0x80000U);
}

#if 0 // DRAFT: undefined identifier 'unkE4'
void SpikeTrapDescriptor::LoadDone() {
    GamePropDescriptor::LoadDone();
    this->unkE4 = ((MKAnimScript *) this->unk34)->GetAnim("inactive");
    this->unkE8 = (long) (((MKAnimScript *) this->unk34)->GetAnim("activating"));
    this->unkEC = (long) (((MKAnimScript *) this->unk34)->GetAnim("activated"));
    this->unkF0 = (long) (((MKAnimScript *) this->unk34)->GetAnim("deactivating"));
}
#endif

s32 SpikeTrapDescriptor::LoadLine(MKIniLine *arg0) {
    GamePropDescriptor::LoadLine(arg0);
}

void SpikeTrapDescriptor::Init() {
    TrapDescriptor::Init();
}
