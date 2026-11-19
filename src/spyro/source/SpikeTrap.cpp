#include "spyro/source/SpikeTrap.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKProp.h"
#include "spyro/source/GameProp.h"
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

void SpikeTrap::Update() {
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

void SpikeTrap::LoadDone() {
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

#if 0 // DRAFT: function call 'PropFlagsSet(unsigned long *, unsigned int)' does not match
void SpikeTrap::Init() {
    Trap::Init();
    PropFlagsSet((u32 *) &this->unk10, 0x80000U);
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void SpikeTrapDescriptor::LoadDone() {
    GamePropDescriptor::LoadDone();
    this->unkE4 = this->unk34->GetAnim("inactive");
    this->unkE8 = this->unk34->GetAnim("activating");
    this->unkEC = this->unk34->GetAnim("activated");
    this->unkF0 = this->unk34->GetAnim("deactivating");
}
#endif

#if 0 // DRAFT: illegal use of non-static member
s32 SpikeTrapDescriptor::LoadLine(MKIniLine *arg0) {
    GamePropDescriptor::LoadLine(arg0);
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void SpikeTrapDescriptor::Init() {
    TrapDescriptor::Init();
}
#endif
