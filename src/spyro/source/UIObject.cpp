#include "spyro/source/UIObject.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKStringCache.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/Level.h"
#include "spyro/source/UIAttributes.h"
#include "spyro/source/UIContainer.h"
#include "spyro/source/UIMessage.h"
#include "spyro/source/UIStringTable.h"
#include <m2c_macros.h>

s32 stricmp(s8 *, M2C_UNK *, M2C_UNK *);            /* extern */
extern UIStringTable menuStrings;

s32 UIObject::Message(UIMessage *arg0) {
    s32 temp_r0_11;

    temp_r0_11 = arg0->unk0;
    switch (temp_r0_11) {                           /* irregular */
    case 2:
        this->unk14 = 1;
        break;
    case 3:
        this->unk14 = 0;
        break;
    case 4:
        this->unk15 = 1;
        break;
    case 5:
        this->unk15 = 0;
        break;
    }
    return 0;
}

#if 0 // DRAFT: function call 'stricmp(const char *, const char[7], const char[5])' does not match 'stricmp(signed char *, long *, long *)'
UIContainer *UIObject::Find(const char *arg0) {
    UIContainer *temp_r3_83;
    UIObject *var_r31_55;

    var_r31_55 = NULL;
    if (stricmp(arg0, "system", "this") == 0) {
        return GetRoot();
    }
    if (stricmp(arg0, "this") == 0) {
        return (UIContainer *) this;
    }
    if (stricmp(arg0, "parent") == 0) {
        return this->unkC;
    }
    temp_r3_83 = this->unkC;
    if (temp_r3_83 != NULL) {
        var_r31_55 = temp_r3_83->FindChild(arg0);
    }
    if ((var_r31_55 == NULL) && (IsContainer() != 0)) {
        var_r31_55 = ((UIContainer *) this)->FindChild(arg0);
    }
    if ((var_r31_55 == NULL) && (GetRoot() != NULL)) {
        var_r31_55 = ((UIContainer *) (GetRoot()))->FindChild(arg0);
    }
    return (UIContainer *) var_r31_55;
}
#endif

void UIObject::Resolve() {

}

UIContainer *UIObject::GetRoot() const {
    UIContainer *temp_r0_156;
    UIContainer *var_r3_151;

    if (((UIContainer *) this->unkC == NULL) && (IsContainer() != 0)) {
        return (UIContainer *) this;
    }
    var_r3_151 = this->unkC;
loop_5:
    temp_r0_156 = var_r3_151->unkC;
    if (temp_r0_156 != NULL) {
        var_r3_151 = temp_r0_156;
        goto loop_5;
    }
    return var_r3_151;
}

#if 0 // DRAFT: illegal implicit conversion from 'signed char **' to 'const char **'
s32 UIObject::LoadLine(UIDataLine *arg0) {
    s8 *sp8;
    s32 var_r31_204;
    u32 temp_r3_187;

    sp8 = NULL;
    if (((MKIniLine *) arg0)->LoadString("id", &sp8, 0) != 0) {
        temp_r3_187 = this->unk4;
        if (temp_r3_187 != 0) {
            UIStringTable_Remove((s8 *) temp_r3_187);
        }
        UIStringTable_Add(sp8);
        this->unk4 = M2C_ERROR(/* Read from unset register $r3 */);
        return 1;
    }
    var_r31_204 = 0;
    if ((((MKIniLine *) arg0)->LoadBool("bVisible", &this->unk14, 0) != 0) || (((MKIniLine *) arg0)->LoadBool("bEnabled", (u8 *) &this->unk15, 0) != 0) || (this->unk18.LoadLine(arg0) != 0)) {
        var_r31_204 = 1;
    }
    return var_r31_204;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'MKIniLine *' to 'UIDataLine *'
s32 UIObject::Load(const char *arg0, const char *arg1) {
    MKIni sp8;
    MKIniLine *temp_r3_260;
    MKIniLine *var_r31_264;
    s32 temp_r31_255;

    if (arg0 == NULL) {
        return 0;
    }
    MKHeap::ActivateTempMemOverride();
    temp_r31_255 = sp8.Init(arg0, 1, arg1);
    MKHeap::DeactivateTempMemOverride();
    if ((u8) temp_r31_255 != 0) {
        temp_r3_260 = sp8.GetFirstLine();
        var_r31_264 = temp_r3_260->unkC->GetSubLine(temp_r3_260);
loop_5:
        if (var_r31_264 != NULL) {
            LoadLine(var_r31_264);
            var_r31_264 = var_r31_264->unkC->GetNextLine(var_r31_264);
            goto loop_5;
        }
        sp8.Deinit();
        return 1;
    }
    return 0;
}
#endif

#if 0 // DRAFT: function call 'UIStringTable_Remove(signed char *)' does not match 'UIStringTable_Remove(const char *)'
void UIObject::Deinit() {
    u32 temp_r3_308;

    FreeResources();
    temp_r3_308 = this->unk4;
    if (temp_r3_308 != 0) {
        UIStringTable_Remove((s8 *) temp_r3_308);
    }
    UIStringTable_Add(NULL);
    this->unk4 = M2C_ERROR(/* Read from unset register $r3 */);
}
#endif

void UIObject::Init() {
    this->unk4 = 0;
    this->unkC = NULL;
    this->unk10 = NULL;
    this->unk14 = 1;
    this->unk15 = 1;
    this->unk16 = 0;
    this->unk18.SetIdentity();
}

void UIObject_MenuStringsDeinit() {
    UIStringTable_SetCurrent(NULL);
    menuStrings.Deinit();
}

void UIObject_MenuStringsInit(int arg0) {
    menuStrings.Init(arg0);
    UIStringTable_SetCurrent(&menuStrings);
}

void UIObject_cpp::__sinit() {
    menuStrings.UIStringTable();
}
