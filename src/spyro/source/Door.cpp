#include "spyro/source/Door.h"
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
#include "unplaced_enums.h"
#include "spyro/source/PropFlags.h"
#include <m2c_macros.h>

void Door::SetState(DoorStates arg0) {
    this->unkE0 = (s32) arg0;
    this->unk80->SetAnim(M2C_FIELD((checked_cast<DoorDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + (this->unkE0 * 4)), MKAnim **, 0xE4), 1.0f, 0.0f, 0, -1);
}

void Door::Message(MKMessage *arg0) {
    s32 temp_r0_46;

    temp_r0_46 = arg0->unk0;
    switch (temp_r0_46) {                           /* irregular */
    case 0xB5:
        this->unkE4 = 1;
        break;
    case 0xBB:
        this->unkE4 = 2;
        SetState((DoorStates) this->unkE4);
        break;
    case 0xBC:
        this->unkE4 = 0;
        SetState((DoorStates) this->unkE4);
        break;
    case 0xB4:
        this->unkE4 = 3;
        break;
    }
    Trap::Message(arg0);
}

void Door::Reset() {
    Trap::Reset();
    SetState((DoorStates) 0);
    this->unkE4 = this->unkE0;
}

#if 0 // DRAFT: ')' expected
void *Door::Update() {
    s32 temp_r0_123;
    s32 temp_r4_136;
    s32 temp_r4_160;

    GameProp::Update();
    if (this->unk10 & 0x20000) {
        temp_r0_123 = this->unkE0;
        switch (temp_r0_123) {                      /* irregular */
        case 0:
            temp_r4_136 = this->unkE4;
            if (temp_r4_136 == 1) {
                SetState((DoorStates) temp_r4_136);
                return;
            }
            break;
        case 1:
            if (this->unk80->unk2C & 1) {
                if ((u8) M2C_FIELD(checked_cast<DoorDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), u8 *, 0xF4) != 0) {
                    this->unk70.unk4 = 0;
                }
                SetState((DoorStates) 2);
                return;
            }
            break;
        case 2:
            temp_r4_160 = this->unkE4;
            if (temp_r4_160 == 3) {
                SetState((DoorStates) temp_r4_160);
                return;
            }
            break;
        case 3:
            if (this->unk80->unk2C & 1) {
                if ((u8) M2C_FIELD(checked_cast<DoorDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), u8 *, 0xF4) != 0) {
                    this->unk70.unk4 = 1;
                }
                SetState((DoorStates) 0);
            }
            break;
        }
    }
}
#endif

void Door::Init() {
    Trap::Init();
    PropFlagsSet((unsigned int *) &this->unk10, 0x80000U);
}

#if 0 // DRAFT: undefined identifier 'unkE4'
void DoorDescriptor::LoadDone() {
    GamePropDescriptor::LoadDone();
    this->unkE4 = ((MKAnimScript *) this->unk34)->GetAnim("Closed");
    this->unkE8 = ((MKAnimScript *) this->unk34)->GetAnim("Opening");
    this->unkEC = ((MKAnimScript *) this->unk34)->GetAnim("Open");
    this->unkF0 = ((MKAnimScript *) this->unk34)->GetAnim("Closing");
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'unsigned char *' to
s32 DoorDescriptor::LoadLine(MKIniLine *arg0) {
    u8 sp8;

    if (GamePropDescriptor::LoadLine(arg0) != 0) {
        return 1;
    }
    if (arg0->LoadBool("disableCollideOnOpen", &sp8, 0) != 0) {
        this->unkF4 = sp8;
        return 1;
    }
    return 0;
}
#endif

void DoorDescriptor::Init() {
    TrapDescriptor::Init();
    this->unkF4 = 0;
}
