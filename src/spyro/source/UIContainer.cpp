#include "spyro/source/UIContainer.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "spyro/source/MCLoadCheckScreen.h"
#include "spyro/source/UIMessage.h"
#include "spyro/source/UIObject.h"
#include <m2c_macros.h>

M2C_UNK free(UIObject *);                           /* extern */
UIObject *malloc(s32);                              /* extern */
s32 strcmpi(s8 *);                                  /* extern */

void UIContainer::Remove(UIObject *arg0) {
    UIObject **var_r6_12;
    UIObject *var_r5_11;

    var_r5_11 = this->unk60;
    var_r6_12 = &this->unk60;
loop_4:
    if (var_r5_11 == NULL) {
        return;
    }
    if (var_r5_11 == arg0) {
        *var_r6_12 = var_r5_11->unk10;
        arg0->unk10 = NULL;
        arg0->unkC = NULL;
        this->unk64 -= 1;
        return;
    }
    var_r6_12 = &var_r5_11->unk10;
    var_r5_11 = var_r5_11->unk10;
    goto loop_4;
}

void UIContainer::AddBefore(UIObject *arg0, UIObject *arg1) {
    UIObject **var_r7_38;
    UIObject *temp_r6_43;

    var_r7_38 = &this->unk60;
loop_2:
    temp_r6_43 = *var_r7_38;
    if (temp_r6_43 != arg0) {
        var_r7_38 = &temp_r6_43->unk10;
        goto loop_2;
    }
    arg1->unkC = this;
    *var_r7_38 = arg1;
    arg1->unk10 = arg0;
    this->unk64 += 1;
}

void UIContainer::Add(UIObject *arg0) {
    arg0->unkC = this;
    arg0->unk10 = this->unk60;
    this->unk60 = arg0;
    this->unk64 += 1;
}

void UIContainer::FreeResources() {
    UIObject *var_r31_75;

    var_r31_75 = this->unk60;
loop_2:
    if (var_r31_75 != NULL) {
        var_r31_75->FreeResources();
        var_r31_75 = var_r31_75->unk10;
        goto loop_2;
    }
}

void UIContainer::LoadResources() {
    UIObject *var_r31_101;

    var_r31_101 = this->unk60;
loop_2:
    if (var_r31_101 != NULL) {
        var_r31_101->LoadResources();
        var_r31_101 = var_r31_101->unk10;
        goto loop_2;
    }
}

void UIContainer::Message(UIMessage *arg0) {
    UIObject *var_r31_134;

    if ((s32) arg0->unk0 != 1) {

    } else {
        var_r31_134 = this->unk60;
loop_4:
        if (var_r31_134 != NULL) {
            var_r31_134->Message(arg0);
            var_r31_134 = var_r31_134->unk10;
            goto loop_4;
        }
    }
    UIObject::Message(arg0);
}

#if 0 // DRAFT: undefined identifier 'arg_sp10'
void UIContainer::Draw(const RenderContext &arg0) {
    UIObject *var_r31_172;
    arg_sp10.RenderContext(arg0, this->unk18);
    var_r31_172 = this->unk60;
loop_4:
    if (var_r31_172 != NULL) {
        if ((u8) var_r31_172->unk14 != 0) {
            var_r31_172->Draw(arg_sp10);
        }
        var_r31_172 = var_r31_172->unk10;
        goto loop_4;
    }
}
#endif

void UIContainer::Update() {
    UIObject *var_r31_204;

    var_r31_204 = this->unk60;
loop_2:
    if (var_r31_204 != NULL) {
        var_r31_204->Update();
        var_r31_204 = var_r31_204->unk10;
        goto loop_2;
    }
}

UIObject *UIContainer::GetChild(int arg0) {
    UIObject *var_r3_237;
    s32 var_ctr_238;

    if (arg0 < 0) {
        return NULL;
    }
    var_r3_237 = this->unk60;
    var_ctr_238 = arg0;
    if (arg0 > 0) {
loop_3:
        if (var_r3_237 == NULL) {
            return NULL;
        }
        var_r3_237 = var_r3_237->unk10;
        var_ctr_238 -= 1;
        if (var_ctr_238 == 0) {
            return var_r3_237;
        }
        goto loop_3;
    }
    return var_r3_237;
}

#if 0 // DRAFT: function call 'strcmpi(const char *)' does not match
UIObject *UIContainer::FindChild(const char *arg0) {
    UIObject *var_r31_259;

    var_r31_259 = this->unk60;
loop_5:
    if (var_r31_259 == NULL) {
        return NULL;
    }
    if (((u32) var_r31_259->unk4 != 0) && (strcmpi(arg0) == 0)) {
        return var_r31_259;
    }
    var_r31_259 = var_r31_259->unk10;
    goto loop_5;
}
#endif

void UIContainer::Resolve() {
    UIObject *var_r31_294;

    UIObject::Resolve();
    var_r31_294 = this->unk60;
loop_2:
    if (var_r31_294 != NULL) {
        var_r31_294->Resolve();
        var_r31_294 = var_r31_294->unk10;
        goto loop_2;
    }
}

#if 0 // DRAFT: undefined identifier 'IsField'
s32 UIContainer::LoadLine(UIDataLine *arg0) {
    MCLoadCheckScreen *var_r29_339;
    MKHeap *temp_r3_348;
    MKIniLine *var_r29_377;
    UIObject *var_r31_356;
    u8 temp_r3_344;
    void *temp_r30_347;

    if (arg0->IsField("include") != 0) {
        Load(arg0->GetString(0), NULL);
        return 1;
    }
    var_r29_339 = list.unk0;
loop_12:
    if (var_r29_339 == NULL) {
        return UIObject::LoadLine(arg0);
    }
    temp_r3_344 = arg0->IsField((s8 *) var_r29_339->__vptr);
    if (temp_r3_344 != 0) {
        temp_r30_347 = var_r29_339->unk8;
        temp_r3_348 = temp_r3_344->Current();
        if (temp_r3_348 != NULL) {
            var_r31_356 = ((MKHeap *) (temp_r3_348->Current()))->Alloc((s32) temp_r30_347, NULL, 0);
        } else {
            var_r31_356 = malloc((s32) temp_r30_347);
        }
        ((M2C_UNK (*)(UIObject *)) var_r29_339->unkC)(var_r31_356);
        var_r31_356->unk8 = var_r29_339;
        var_r31_356->Init();
        var_r29_377 = arg0->unkC->GetSubLine((MKIniLine *) arg0);
loop_9:
        if (var_r29_377 != NULL) {
            var_r31_356->LoadLine(var_r29_377);
            var_r29_377 = var_r29_377->unkC->GetNextLine(var_r29_377);
            goto loop_9;
        }
        AddBefore(NULL, var_r31_356);
        var_r31_356->LoadDone();
        return 1;
    }
    var_r29_339 = (MCLoadCheckScreen *) var_r29_339->unk10;
    goto loop_12;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'void' to
void UIContainer::Deinit() {
    MKHeap *temp_r3_439;
    UIObject *temp_r31_430;

loop_4:
    if ((s32) this->unk64 != 0) {
        temp_r31_430 = this->unk60;
        Remove(temp_r31_430);
        temp_r3_439 = ((MKHeap *) (temp_r31_430->Deinit()))->Current();
        if (temp_r3_439 != NULL) {
            ((MKHeap *) (temp_r3_439->Current()))->Free(temp_r31_430, NULL, 0);
        } else {
            free(temp_r31_430);
        }
        goto loop_4;
    }
    UIObject::Deinit();
}
#endif

void UIContainer::Init() {
    UIObject::Init();
    this->unk60 = NULL;
    this->unk64 = 0;
}
