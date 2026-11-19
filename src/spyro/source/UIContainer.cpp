#include "spyro/source/UIContainer.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/Level.h"
#include "spyro/source/LoadLevel.h"
#include "spyro/source/MCLoadCheckScreen.h"
#include "spyro/source/UIAttributes.h"
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

s32 UIContainer::Message(UIMessage *arg0) {
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

void UIContainer::Draw(const RenderContext &arg0) {
    RenderContext sp10;
    UIObject *var_r31_172;

    sp10.RenderContext(arg0, this->unk18);
    var_r31_172 = this->unk60;
loop_4:
    if (var_r31_172 != NULL) {
        if ((u8) var_r31_172->unk14 != 0) {
            var_r31_172->Draw(sp10);
        }
        var_r31_172 = var_r31_172->unk10;
        goto loop_4;
    }
}

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

extern "C" s32 strcmpi(s8 *, s8 *);
UIObject *UIContainer::FindChild(const char *arg0) {
    UIObject *var_r31_259;

    for (var_r31_259 = this->unk60; var_r31_259 != NULL; var_r31_259 = var_r31_259->unk10) {
        if (((u32) var_r31_259->unk4 != 0) && (strcmpi((s8 *) arg0, (s8 *) var_r31_259->unk4) == 0)) {
            return var_r31_259;
        }
    }
    return NULL;
}

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

extern "C" UIObject *malloc(u32);
s32 UIContainer::LoadLine(UIDataLine *arg0) {
    s8 *desc;
    UIObject *obj;
    MKIniLine *sub;
    s32 size;

    if (((MKIniLine *) arg0)->IsField("include") != 0) {
        UIObject::Load((const char *) ((MKIniLine *) arg0)->GetString(0), NULL);
        return 1;
    }
    for (desc = (s8 *) UIObjectDescriptor::list.unk0; desc != NULL; desc = M2C_FIELD(desc, s8 **, 0x10)) {
        if (((MKIniLine *) arg0)->IsField(M2C_FIELD(desc, const char **, 0x0)) != 0) {
            size = M2C_FIELD(desc, s32 *, 0x8);
            if (MKHeap::Current() != NULL) {
                obj = (UIObject *) MKHeap::Current()->Alloc(size, NULL, 0);
            } else {
                obj = malloc((u32) size);
            }
            M2C_FIELD(desc, void (**)(UIObject *), 0xC)(obj);
            obj->unk8 = desc;
            M2C_FIELD(*(s8 **) obj, void (**)(UIObject *), 0x8)(obj);
            sub = arg0->unkC->GetSubLine((MKIniLine *) arg0);
            for (; sub != NULL; sub = sub->unkC->GetNextLine(sub)) {
                M2C_FIELD(*(s8 **) obj, s32 (**)(UIObject *, UIDataLine *), 0x10)(obj, (UIDataLine *) sub);
            }
            AddBefore(NULL, obj);
            M2C_FIELD(*(s8 **) obj, void (**)(UIObject *), 0x14)(obj);
            return 1;
        }
    }
    return UIObject::LoadLine(arg0);
}

void UIContainer::Deinit() {
    UIObject *temp_r31_430;

loop_4:
    if ((s32) this->unk64 != 0) {
        temp_r31_430 = this->unk60;
        Remove(temp_r31_430);
        temp_r31_430->Deinit();
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_430, NULL, 0);
        } else {
            free(temp_r31_430);
        }
        goto loop_4;
    }
    UIObject::Deinit();
}

void UIContainer::Init() {
    UIObject::Init();
    this->unk60 = NULL;
    this->unk64 = 0;
}
