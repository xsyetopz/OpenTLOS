#include "spyro/source/UISystem.h"
#include "spyro/source/LoadLevel.h"
#include "spyro/source/MCLoadCheckScreen.h"
#include "spyro/source/UIContainer.h"
#include "spyro/source/UIMessage.h"
#include "spyro/source/UIObject.h"
#include "spyro/source/UIScreen.h"
#include "unplaced_templates.h"
#include "spyro/source/UIControls.h"
#include <m2c_macros.h>

void UISystem::ClearStack(UIScreen *arg0) {
    this->unk60 = (UIObject *)4;
    this->unk94 = arg0;
    ProvokeTransition();
}

void UISystem::PopScreen_Internal() {
    if ((UIObject *) this->unk60 != (UIObject *)3) {
        this->unk60 = (UIObject *)3;
        this->unk94 = M2C_FIELD((this + (this->unk64 * 4)), UIScreen **, 0x6C);
        ProvokeTransition();
    }
}

void UISystem::PushScreen_Internal(UIScreen *arg0) {
    if (((UIObject *) this->unk60 != (UIObject *)2) || ((UIScreen *) this->unk94 != arg0)) {
        this->unk60 = (UIObject *)2;
        this->unk94 = arg0;
        ProvokeTransition();
    }
}

#if 0 // DRAFT: illegal implicit conversion from 'long *' to
void UISystem::PushScreen(const char *arg0) {
    UIObject *spC;
    s32 sp8;

    spC = FindChild(arg0);
    sp8 = 0xE;
    Message(&sp8);
}
#endif

void UISystem::ChangeScreen_Internal(UIScreen *arg0) {
    if (((UIObject *) this->unk60 != (UIObject *)1) || ((UIScreen *) this->unk94 != arg0)) {
        this->unk60 = (UIObject *)1;
        this->unk94 = arg0;
        ProvokeTransition();
    }
}

#if 0 // DRAFT: illegal implicit conversion from 'long *' to
void UISystem::ChangeScreen(const char *arg0) {
    UIObject *spC;
    s32 sp8;

    spC = FindChild(arg0);
    sp8 = 0xD;
    Message(&sp8);
}
#endif

#if 0 // DRAFT: illegal operand 'UIObject *'
void UISystem::DoTransition() {
    UIObject *temp_r0_149;
    s32 temp_r0_200;

    temp_r0_149 = this->unk60;
    switch (temp_r0_149) {                          /* irregular */
    case 0:
        break;
    case 1:
        M2C_FIELD((this + (this->unk64 * 4)), UIScreen **, 0x70) = (UIScreen *) this->unk94;
        break;
    case 2:
        this->unk64 += 1;
        M2C_FIELD((this + (this->unk64 * 4)), UIScreen **, 0x70) = (UIScreen *) this->unk94;
        break;
    case 3:
        M2C_FIELD((this + (this->unk64 * 4)), s32 *, 0x70) = 0;
        this->unk64 -= 1;
        break;
    case 4:
loop_13:
        temp_r0_200 = this->unk64;
        if (temp_r0_200 > 0) {
            *(this + ((temp_r0_200 * 4) + 0x70)) = 0;
            this->unk64 -= 1;
            goto loop_13;
        }
        M2C_FIELD((this + (temp_r0_200 * 4)), UIScreen **, 0x70) = (UIScreen *) this->unk94;
        break;
    }
    this->unk94 = NULL;
    if ((u32) M2C_FIELD((this + (this->unk64 * 4)), u32 *, 0x70) != 0U) {
        M2C_FIELD(this, s8 *, 0x9D) = 1;
        return;
    }
    M2C_FIELD(this, s8 *, 0x9D) = 0;
    this->unk60 = NULL;
}
#endif

void UISystem::ProvokeTransition() {
    s32 temp_r0_237;

    if ((u8) M2C_FIELD(this, u8 *, 0x9D) != 0) {
        DoTransition();
        return;
    }
    temp_r0_237 = this->unk64;
    if ((temp_r0_237 < 0) || ((u32) M2C_FIELD((this + (temp_r0_237 * 4)), u32 *, 0x70) == 0U)) {
        this->unk98 = 0;
        DoTransition();
        return;
    }
    M2C_FIELD(this, s8 *, 0x9C) = 1;
}

#if 0 // DRAFT: undefined identifier 'P8UIScreen'
void UISystem::Message(UIMessage *arg0) {
    s32 temp_r5_269;

    temp_r5_269 = arg0->unk0;
    switch (temp_r5_269) {                          /* irregular */
    case 0xD:
        ChangeScreen_Internal(ui_cast<P8UIScreen, P8UIObject>__FP8UIObject((UIObject *) arg0->unk4));
    default:
block_14:
        UIContainer::Message(arg0);
        return;
    case 0xE:
        PushScreen_Internal(ui_cast<P8UIScreen, P8UIObject>__FP8UIObject((UIObject *) arg0->unk4));
        goto block_14;
    case 0xF:
        PopScreen_Internal();
        goto block_14;
    case 0x8001:
        M2C_FIELD(this, s8 *, 0x9E) = 1;
        return;
    }
}
#endif

void UISystem::Draw(const RenderContext &arg0) {
    void **temp_r5_331;

    temp_r5_331 = M2C_FIELD((this + (this->unk64 * 4)), void ***, 0x70);
    if ((temp_r5_331 != NULL) && ((u8) M2C_FIELD(this, u8 *, 0x9D) == 0)) {
        M2C_FIELD(*temp_r5_331, M2C_UNK (**)(void **), 0x1C)(temp_r5_331);
    }
}

#if 0 // DRAFT: illegal implicit conversion from 'long' to
void UISystem::Update() {
    void **temp_r3_366;
    void **temp_r3_393;
    void **temp_r3_407;

    UIControls_Update();
    if ((u8) M2C_FIELD(this, u8 *, 0x9C) != 0) {
        M2C_FIELD(this, u8 *, 0x9C) = 0U;
        temp_r3_366 = M2C_FIELD((this + (this->unk64 * 4)), void ***, 0x70);
        M2C_FIELD(*temp_r3_366, M2C_UNK (**)(void **), 0x3C)(temp_r3_366);
    }
    if ((u8) M2C_FIELD(this, u8 *, 0x9E) != 0) {
        M2C_FIELD(this, u8 *, 0x9E) = 0U;
        this->unk98 = M2C_FIELD((this + (this->unk64 * 4)), s32 *, 0x70);
        DoTransition();
    }
    if ((u8) M2C_FIELD(this, u8 *, 0x9D) != 0) {
        M2C_FIELD(this, u8 *, 0x9D) = 0U;
        temp_r3_393 = M2C_FIELD((this + (this->unk64 * 4)), void ***, 0x70);
        M2C_FIELD(*temp_r3_393, M2C_UNK (**)(void **), 0x38)(temp_r3_393);
        if ((u8) M2C_FIELD(this, u8 *, 0x9E) == 0) {
            this->unk60 = NULL;
        }
    }
    temp_r3_407 = M2C_FIELD((this + (this->unk64 * 4)), void ***, 0x70);
    if (temp_r3_407 != NULL) {
        M2C_FIELD(*temp_r3_407, M2C_UNK (**)(), 0x18)();
    }
}
#endif

void UISystem::Deinit() {
    UIContainer::Deinit();
}

#if 0 // DRAFT: undefined identifier 'list'
void UISystem::Init() {
    MCLoadCheckScreen *temp_r3_452;
    MCLoadCheckScreen *temp_r3_470;
    MCLoadCheckScreen *temp_r3_488;
    MCLoadCheckScreen *temp_r3_506;
    MCLoadCheckScreen *temp_r3_524;
    MCLoadCheckScreen *temp_r3_542;
    MCLoadCheckScreen *temp_r3_560;
    MCLoadCheckScreen *temp_r3_578;
    MCLoadCheckScreen *temp_r3_596;
    MCLoadCheckScreen *temp_r3_614;
    UIObjectDescriptor *var_r4_443;
    UIObjectDescriptor *var_r4_462;
    UIObjectDescriptor *var_r4_480;
    UIObjectDescriptor *var_r4_498;
    UIObjectDescriptor *var_r4_516;
    UIObjectDescriptor *var_r4_534;
    UIObjectDescriptor *var_r4_552;
    UIObjectDescriptor *var_r4_570;
    UIObjectDescriptor *var_r4_588;
    UIObjectDescriptor *var_r4_606;
    s32 temp_r0_632;
    s32 var_ctr_630;
    s32 var_r3_628;

    var_r4_443 = &list;
loop_3:
    temp_r3_452 = var_r4_443->unk0;
    if (temp_r3_452 == NULL) {
        var_r4_443->unk0 = (MCLoadCheckScreen *) &descriptor;
        descriptor.unk10 = NULL;
    } else if (temp_r3_452 != &descriptor) {
        var_r4_443 = (UIObjectDescriptor *) &temp_r3_452->unk10;
        goto loop_3;
    }
    var_r4_462 = &list;
loop_8:
    temp_r3_470 = var_r4_462->unk0;
    if (temp_r3_470 == NULL) {
        var_r4_462->unk0 = (MCLoadCheckScreen *) &descriptor;
        descriptor.unk10 = NULL;
    } else if (temp_r3_470 != &descriptor) {
        var_r4_462 = (UIObjectDescriptor *) &temp_r3_470->unk10;
        goto loop_8;
    }
    var_r4_480 = &list;
loop_13:
    temp_r3_488 = var_r4_480->unk0;
    if (temp_r3_488 == NULL) {
        var_r4_480->unk0 = (MCLoadCheckScreen *) &descriptor;
        descriptor.unk10 = NULL;
    } else if (temp_r3_488 != &descriptor) {
        var_r4_480 = (UIObjectDescriptor *) &temp_r3_488->unk10;
        goto loop_13;
    }
    var_r4_498 = &list;
loop_18:
    temp_r3_506 = var_r4_498->unk0;
    if (temp_r3_506 == NULL) {
        var_r4_498->unk0 = (MCLoadCheckScreen *) &descriptor;
        descriptor.unk10 = NULL;
    } else if (temp_r3_506 != &descriptor) {
        var_r4_498 = (UIObjectDescriptor *) &temp_r3_506->unk10;
        goto loop_18;
    }
    var_r4_516 = &list;
loop_23:
    temp_r3_524 = var_r4_516->unk0;
    if (temp_r3_524 == NULL) {
        var_r4_516->unk0 = (MCLoadCheckScreen *) &descriptor;
        descriptor.unk10 = NULL;
    } else if (temp_r3_524 != &descriptor) {
        var_r4_516 = (UIObjectDescriptor *) &temp_r3_524->unk10;
        goto loop_23;
    }
    var_r4_534 = &list;
loop_28:
    temp_r3_542 = var_r4_534->unk0;
    if (temp_r3_542 == NULL) {
        var_r4_534->unk0 = (MCLoadCheckScreen *) &descriptor;
        descriptor.unk10 = NULL;
    } else if (temp_r3_542 != &descriptor) {
        var_r4_534 = (UIObjectDescriptor *) &temp_r3_542->unk10;
        goto loop_28;
    }
    var_r4_552 = &list;
loop_33:
    temp_r3_560 = var_r4_552->unk0;
    if (temp_r3_560 == NULL) {
        var_r4_552->unk0 = (MCLoadCheckScreen *) &descriptor;
        descriptor.unk10 = NULL;
    } else if (temp_r3_560 != &descriptor) {
        var_r4_552 = (UIObjectDescriptor *) &temp_r3_560->unk10;
        goto loop_33;
    }
    var_r4_570 = &list;
loop_38:
    temp_r3_578 = var_r4_570->unk0;
    if (temp_r3_578 == NULL) {
        var_r4_570->unk0 = (MCLoadCheckScreen *) &descriptor;
        descriptor.unk10 = NULL;
    } else if (temp_r3_578 != &descriptor) {
        var_r4_570 = (UIObjectDescriptor *) &temp_r3_578->unk10;
        goto loop_38;
    }
    var_r4_588 = &list;
loop_43:
    temp_r3_596 = var_r4_588->unk0;
    if (temp_r3_596 == NULL) {
        var_r4_588->unk0 = (MCLoadCheckScreen *) &descriptor;
        descriptor.unk10 = NULL;
    } else if (temp_r3_596 != &descriptor) {
        var_r4_588 = (UIObjectDescriptor *) &temp_r3_596->unk10;
        goto loop_43;
    }
    var_r4_606 = &list;
loop_48:
    temp_r3_614 = var_r4_606->unk0;
    if (temp_r3_614 == NULL) {
        var_r4_606->unk0 = (MCLoadCheckScreen *) &descriptor;
        descriptor.unk10 = NULL;
    } else if (temp_r3_614 != &descriptor) {
        var_r4_606 = (UIObjectDescriptor *) &temp_r3_614->unk10;
        goto loop_48;
    }
    UIContainer::Init();
    this->unk60 = NULL;
    var_r3_628 = 0;
    this->unk64 = 0;
    var_ctr_630 = 9;
    do {
        temp_r0_632 = var_r3_628 + 0x70;
        var_r3_628 += 4;
        *(this + temp_r0_632) = 0;
        var_ctr_630 -= 1;
    } while (var_ctr_630 != 0);
    this->unk94 = NULL;
    this->unk98 = 0;
    M2C_FIELD(this, s8 *, 0x9C) = 0;
    M2C_FIELD(this, s8 *, 0x9D) = 0;
    M2C_FIELD(this, s8 *, 0x9E) = 0;
}
#endif

#if 0 // DRAFT: identifier 'ui_cast<...>(T1)' redeclared
UIScreen *ui_cast<UIScreen *, UIObject *>(UIObject *arg0) {
    UIScreen *sp8;

    sp8 = NULL;
    ui_cast_ptr<UIScreen, UIObject>(sp8, arg0);
    return sp8;
}
#endif

#if 0 // DRAFT: identifier 'ui_cast_ptr<...>(T0 *&, T1 *)' redeclared
void ui_cast_ptr<UIScreen, UIObject>(UIScreen *&arg0, UIObject *arg1) {
    u8 var_r0_683;
    void *var_r5_678;

    if (arg1 != NULL) {
        var_r5_678 = arg1->unk8;
loop_2:
        if (var_r5_678 == &descriptor) {
            var_r0_683 = 1;
        } else {
            var_r5_678 = M2C_FIELD(var_r5_678, void **, 4);
            if (var_r5_678 == NULL) {
                var_r0_683 = 0;
            } else {
                goto loop_2;
            }
        }
        if (var_r0_683 != 0) {
            &arg0 = checked_cast<UIScreen *, UIObject>(arg1);
        }
    }
}
#endif

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<UIScreen *, UIObject>(UIObject *arg0) {

}
#endif
