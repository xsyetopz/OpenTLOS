#include "spyro/source/MineCartDoor.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKProp.h"
#include "spyro/source/GameProp.h"
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

void MineCartDoor::Update() {
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

#if 0 // DRAFT: undefined identifier 'unkE4'
void MineCartDoorDescriptor::LoadDone() {
    GamePropDescriptor::LoadDone();
    this->unkE4 = ((MKAnimScript *) this->unk34)->GetAnim("Opening");
    this->unkE8 = ((MKAnimScript *) this->unk34)->GetAnim("Open");
    this->unkEC = ((MKAnimScript *) this->unk34)->GetAnim("Closing");
    this->unkF0 = ((MKAnimScript *) this->unk34)->GetAnim("Closed");
}
#endif
