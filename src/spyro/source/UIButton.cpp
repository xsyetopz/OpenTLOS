#include "spyro/source/UIButton.h"
#include "spyro/source/UIContainer.h"
#include "spyro/source/UIMessage.h"
#include "spyro/source/UIObject.h"
#include <m2c_macros.h>

#if 0 // DRAFT: expression syntax error
void UIButtonGroup::OnSelectionChanged() {
    this->unk64.Send();
}
#endif

#if 0 // DRAFT: type mismatch
s32 UIButtonGroup::SetSelection(int arg0) {
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    UIObject *temp_r3_42;
    UIObject *temp_r3_56;
    UIObject *temp_r4_35;

    if ((u8) GetChild(arg0)->unk15 != 0) {
        temp_r4_35 = this->unk60;
        if ((temp_r4_35 >= 0) && (temp_r4_35 < (s32) this->unk64)) {
            temp_r3_42 = GetChild((s32) temp_r4_35);
            sp10 = 9;
            sp14 = 0;
            M2C_FIELD(temp_r3_42->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp10);
        }
        this->unk60 = (UIObject *) arg0;
        temp_r3_56 = GetChild((s32) this->unk60);
        sp8 = 8;
        spC = 0;
        M2C_FIELD(temp_r3_56->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp8);
        return 1;
    }
    return 0;
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void UIButtonGroup::Message(UIMessage *arg0) {
    UIObject *temp_r30_117;
    UIObject *temp_r30_161;
    UIObject *var_r29_118;
    UIObject *var_r29_162;
    UIObject *var_r4_167;
    s32 temp_cr0_eq_128;
    s32 temp_r0_87;
    s32 temp_r3_122;
    s32 temp_r3_125;
    s32 temp_r4_127;

    temp_r0_87 = arg0->unk0;
    if ((u32) temp_r0_87 <= 0xCU) {
        switch (temp_r0_87) {
        case 1:
            M2C_FIELD(this->__vptr, u8 (**)(s32), 0x38)(arg0->unk4);
            goto block_26;
        case 6:
            M2C_FIELD(GetChild((s32) this->unk60)->__vptr, M2C_UNK (**)(UIMessage *), 0x2C)(arg0);
            return;
        case 10:
            if ((u8) this->unk15 != 0) {
                temp_r30_117 = this->unk60;
                var_r29_118 = temp_r30_117;
loop_6:
                temp_r3_122 = this->unk64 - 1;
                temp_r3_125 = (var_r29_118 - temp_r3_122) + (temp_r3_122 ^ 0x80000000);
                temp_r4_127 = (s32) (var_r29_118 + 1) & ~((temp_r3_125 - temp_r3_125) - !M2C_CARRY);
                temp_cr0_eq_128 = temp_r4_127 == temp_r30_117;
                var_r29_118 = (UIObject *) temp_r4_127;
                if (temp_cr0_eq_128 == 0) {
                    if (SetSelection() == 0) {
                        goto loop_6;
                    }
                }
                if (temp_r30_117 != (UIObject *) this->unk60) {
                    OnSelectionChanged();
                }
                return;
            }
            return;
        case 11:
            if ((u8) this->unk15 != 0) {
                temp_r30_161 = this->unk60;
                var_r29_162 = temp_r30_161;
loop_14:
                if (var_r29_162 <= 0) {
                    var_r4_167 = this->unk64 - 1;
                } else {
                    var_r4_167 = var_r29_162 - 1;
                }
                var_r29_162 = var_r4_167;
                if ((var_r4_167 != temp_r30_161) && (SetSelection() == 0)) {
                    goto loop_14;
                }
                if (temp_r30_161 != (UIObject *) this->unk60) {
                    OnSelectionChanged();
                }
                return;
            }
            return;
        case 12:
            if (M2C_FIELD(this->__vptr, u8 (**)(s32), 0x38)(arg0->unk4) != 0) {
                OnSelectionChanged();
                return;
            }
            return;
        }
    } else {
    case 0:
    case 2:
    case 3:
    case 4:
    case 5:
    case 7:
    case 8:
    case 9:
block_26:
        UIContainer::Message(arg0);
    }
}
#endif

#if 0 // DRAFT: expression syntax error
void UIButtonGroup::Resolve() {
    UIContainer::Resolve();
    this->unk64.Resolve((UIObject *) this);
}
#endif

#if 0 // DRAFT: expression syntax error
s32 UIButtonGroup::LoadLine(UIDataLine *arg0) {
    s32 var_r31_261;

    var_r31_261 = 0;
    if ((this->unk64.LoadLine("OnSelectionChanged", arg0) != 0) || (UIContainer::LoadLine(arg0) != 0)) {
        var_r31_261 = 1;
    }
    return var_r31_261;
}
#endif

void UIButtonGroup::Init() {
    UIContainer::Init();
    this->unk60 = (UIObject *)-1;
}

#if 0 // DRAFT: expression syntax error
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
#endif

#if 0 // DRAFT: expression syntax error
void UIButton::OnDeselection() {
    this->unk74.unk4.Send();
}
#endif

#if 0 // DRAFT: expression syntax error
void UIButton::OnSelection() {
    this->unk68.unk4.Send();
}
#endif

#if 0 // DRAFT: expression syntax error
void UIButton::OnActivate() {
    this->unk60.Send();
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void UIButton::Update() {
    M2C_FIELD(this->__vptr, M2C_UNK (**)(), 0x44)();
    UIContainer::Update();
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void UIButton::Message(UIMessage *arg0) {
    s32 temp_r0_407;

    temp_r0_407 = arg0->unk0;
    switch (temp_r0_407) {                          /* irregular */
    case 6:
        M2C_FIELD(this->__vptr, M2C_UNK (**)(), 0x38)();
        break;
    case 8:
        this->unk16 = 1;
        M2C_FIELD(this->__vptr, M2C_UNK (**)(), 0x3C)();
        break;
    case 9:
        this->unk16 = 0;
        M2C_FIELD(this->__vptr, M2C_UNK (**)(), 0x40)();
        break;
    }
    UIContainer::Message(arg0);
}
#endif

#if 0 // DRAFT: expression syntax error
void UIButton::Resolve() {
    UIContainer::Resolve();
    this->unk60.Resolve((UIObject *) this);
    this->unk68.unk4.Resolve((UIObject *) this);
    this->unk74.unk4.Resolve((UIObject *) this);
}
#endif

#if 0 // DRAFT: expression syntax error
s32 UIButton::LoadLine(UIDataLine *arg0) {
    s32 var_r31_486;

    var_r31_486 = 0;
    if ((this->unk60.LoadLine("OnActivate", arg0) != 0) || (this->unk68.unk4.LoadLine("OnSelection", arg0) != 0) || (this->unk74.unk4.LoadLine("OnDeselection", arg0) != 0) || (UIContainer::LoadLine(arg0) != 0)) {
        var_r31_486 = 1;
    }
    return var_r31_486;
}
#endif
