#include "spyro/source/UIButton.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKVector3.h"
#include "spyro/source/UIAttributes.h"
#include "spyro/source/UIContainer.h"
#include "spyro/source/UIMessage.h"
#include "spyro/source/UIObject.h"
#include <m2c_macros.h>

void UIButtonGroup::OnSelectionChanged() {
    this->unk6C.Send();
}

s32 UIButtonGroup::SetSelection(int arg0) {
    UIMessage sp10;
    UIMessage sp8;
    UIObject *temp_r3_42;
    UIObject *temp_r3_56;
    s32 temp_r4_35;

    if ((u8) GetChild(arg0)->unk15 != 0) {
        temp_r4_35 = this->unk68;
        if ((temp_r4_35 >= 0) && (temp_r4_35 < (s32) this->unk64)) {
            temp_r3_42 = GetChild(temp_r4_35);
            sp10.unk0 = 9;
            sp10.unk4 = 0;
            M2C_FIELD(*(s8 **) temp_r3_42, s32 (**)(UIObject *, UIMessage *), 0x2C)(temp_r3_42, &sp10);
        }
        this->unk68 = arg0;
        temp_r3_56 = GetChild(this->unk68);
        sp8.unk0 = 8;
        sp8.unk4 = 0;
        M2C_FIELD(*(s8 **) temp_r3_56, s32 (**)(UIObject *, UIMessage *), 0x2C)(temp_r3_56, &sp8);
        return 1;
    }
    return 0;
}

s32 UIButtonGroup::Message(UIMessage *arg0) {
    s32 initial;
    s32 cur;
    UIObject *child;

    switch (arg0->unk0) {
    case 0:
    case 2:
    case 3:
    case 4:
    case 5:
    case 7:
    case 8:
    case 9:
        break;
    case 1:
        M2C_FIELD(*(s8 **) this, s32 (**)(UIButtonGroup *, s32), 0x38)(this, arg0->unk4);
        break;
    case 6:
        child = GetChild(this->unk68);
        M2C_FIELD(*(s8 **) child, s32 (**)(UIObject *, UIMessage *), 0x2C)(child, arg0);
        return 1;
    case 10:
        if ((u8) this->unk15 != 0) {
            initial = this->unk68;
            cur = initial;
            do {
                cur = (cur < this->unk64 - 1) ? cur + 1 : 0;
            } while (cur != initial && (u8) M2C_FIELD(*(s8 **) this, s32 (**)(UIButtonGroup *, s32), 0x38)(this, cur) == 0);
            if (initial != this->unk68) {
                M2C_FIELD(*(s8 **) this, void (**)(UIButtonGroup *), 0x3C)(this);
            }
            return this->unk68 != initial;
        }
        return 0;
    case 11:
        if ((u8) this->unk15 != 0) {
            initial = this->unk68;
            cur = initial;
            do {
                cur = (cur > 0) ? cur - 1 : this->unk64 - 1;
            } while (cur != initial && (u8) M2C_FIELD(*(s8 **) this, s32 (**)(UIButtonGroup *, s32), 0x38)(this, cur) == 0);
            if (initial != this->unk68) {
                M2C_FIELD(*(s8 **) this, void (**)(UIButtonGroup *), 0x3C)(this);
            }
            return this->unk68 != initial;
        }
        return 0;
    case 12:
        if ((u8) M2C_FIELD(*(s8 **) this, s32 (**)(UIButtonGroup *, s32), 0x38)(this, arg0->unk4) != 0) {
            M2C_FIELD(*(s8 **) this, void (**)(UIButtonGroup *), 0x3C)(this);
            return 1;
        }
        return 0;
    default:
        break;
    }
    return UIContainer::Message(arg0);
}

void UIButtonGroup::Resolve() {
    UIContainer::Resolve();
    this->unk6C.Resolve((UIObject *) this);
}

s32 UIButtonGroup::LoadLine(UIDataLine *arg0) {
    s32 var_r31_261;

    var_r31_261 = 0;
    if ((this->unk6C.LoadLine("OnSelectionChanged", arg0) != 0) || (UIContainer::LoadLine(arg0) != 0)) {
        var_r31_261 = 1;
    }
    return var_r31_261;
}

void UIButtonGroup::Init() {
    UIContainer::Init();
    this->unk68 = -1;
}

void UIButton::SetColor() {
    this->unk18.unk40 |= 1;
    if ((u8) this->unk15 == 0) {
        this->unk18.unk0 = 0.5f;
        this->unk18.unk4 = 0.5f;
        M2C_FIELD(this, f32 *, 0x20) = 0.5f;
        return;
    }
    if ((u8) this->unk16 != 0) {
        this->unk18.unk0 = 1.0f;
        this->unk18.unk4 = 0.5f;
        M2C_FIELD(this, f32 *, 0x20) = 0.25f;
        return;
    }
    this->unk18.unk0 = 1.0f;
    this->unk18.unk4 = 1.0f;
    M2C_FIELD(this, f32 *, 0x20) = 1.0f;
}

void UIButton::OnDeselection() {
    this->unk80.Send();
}

void UIButton::OnSelection() {
    this->unk74.Send();
}

void UIButton::OnActivate() {
    this->unk68.Send();
}

void UIButton::Update() {
    SetColor();
    UIContainer::Update();
}

s32 UIButton::Message(UIMessage *arg0) {
    s32 temp_r0_407;

    temp_r0_407 = arg0->unk0;
    switch (temp_r0_407) {                          /* irregular */
    case 6:
        OnActivate();
        break;
    case 8:
        this->unk16 = 1;
        OnSelection();
        break;
    case 9:
        this->unk16 = 0;
        OnDeselection();
        break;
    }
    UIContainer::Message(arg0);
}

void UIButton::Resolve() {
    UIContainer::Resolve();
    this->unk68.Resolve((UIObject *) this);
    this->unk74.Resolve((UIObject *) this);
    this->unk80.Resolve((UIObject *) this);
}

s32 UIButton::LoadLine(UIDataLine *arg0) {
    s32 var_r31_486;

    var_r31_486 = 0;
    if ((this->unk68.LoadLine("OnActivate", arg0) != 0) || (this->unk74.LoadLine("OnSelection", arg0) != 0) || (this->unk80.LoadLine("OnDeselection", arg0) != 0) || (UIContainer::LoadLine(arg0) != 0)) {
        var_r31_486 = 1;
    }
    return var_r31_486;
}
