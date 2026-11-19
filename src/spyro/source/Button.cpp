#include "spyro/source/Button.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKProp.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/Trap.h"
#include "unplaced_templates.h"
#include <m2c_macros.h>

void Button::SetState(int arg0) {
    this->unkE0 = arg0;
    this->unk80->SetAnim(M2C_FIELD((checked_cast<ButtonDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + (this->unkE0 * 4)), MKAnim **, 0xE4), 1.0f, 0.0f, 0, -1);
}

void Button::Message(MKMessage *arg0) {
    u8 sp10;
    s32 spC;
    s32 sp8;
    u8 temp_r3_100;
    u8 temp_r3_104;
    void **temp_r3_111;

    if ((s32) arg0->unk0 != 0x12) {

    } else if ((((u8) this->unkEC >> 6U) & 1) && ((s32) this->unkE0 == 0) && ((temp_r3_100 = sp10 & ~0x80, sp10 = temp_r3_100, temp_r3_104 = temp_r3_100 & ~0x40, sp10 = temp_r3_104, spC = 0, sp10 = temp_r3_104 & ~0x20, sp8 = 0x6D, temp_r3_111 = arg0->unkC, M2C_FIELD(M2C_FIELD(M2C_FIELD(*temp_r3_111, void *(**)(void **, M2C_UNK), 0x2C)(temp_r3_111, 0), void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp8), ((((sp10 >> 7U) & 1) == 0) == 0)) || ((sp10 >> 6U) & 1))) {
        this->unkEC |= 0x80;
    }
    Trap::Message(arg0);
}

void Button::Reset() {
    Trap::Reset();
    this->unkEC &= ~0x80;
    SetState(0);
}

void Button::Update() {
    s32 temp_r0_174;

    GameProp::Update();
    temp_r0_174 = this->unkE0;
    switch (temp_r0_174) {                          /* irregular */
    default:
    case 0:
        if (((u8) this->unkEC >> 7U) & 1) {
            SetState(1);
        }
        break;
    case 1:
        if (this->unk80->unk2C & 1) {
            this->unkE4.Send((MKProp *) this);
            SetState(2);
        }
        break;
    case 2:
        if (!(((u8) this->unkEC >> 7U) & 1)) {
            this->unkE8.Send((MKProp *) this);
            SetState(3);
        }
        break;
    case 3:
        if (this->unk80->unk2C & 1) {
            SetState(0);
        }
        break;
    }
    this->unkEC &= ~0x80;
}

#if 0 // DRAFT: illegal implicit conversion from 'unsigned char *' to
s32 Button::LoadLine(MKIniLine *arg0) {
    u8 sp8;
    s32 var_r31_261;

    if (arg0->LoadBool("Charge", &sp8, 0) != 0) {
        this->unkEC = (this->unkEC & ~0x40) | ((sp8 << 6) & 0x40);
    }
    var_r31_261 = 0;
    if ((Trap::LoadLine(arg0) != 0) || (this->unkE4.LoadLine(arg0, "OnPressed") != 0) || (this->unkE8.LoadLine(arg0, "OnReleased") != 0)) {
        var_r31_261 = 1;
    }
    return var_r31_261;
}
#endif

void Button::Init() {
    Trap::Init();
    memset(&this->unkEC, 0, 1U);
}

#if 0 // DRAFT: illegal use of non-static member
void ButtonDescriptor::LoadDone() {
    GamePropDescriptor::LoadDone();
    this->unkE4 = this->unk34->GetAnim("inactive");
    this->unkE8 = this->unk34->GetAnim("activating");
    this->unkEC = this->unk34->GetAnim("active");
    this->unkF0 = this->unk34->GetAnim("deactivating");
}
#endif
