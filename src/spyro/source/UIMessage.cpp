#include "spyro/source/UIMessage.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKVector3.h"
#include "spyro/source/UIAttributes.h"
#include "spyro/source/UIContainer.h"
#include "spyro/source/UIObject.h"
#include "spyro/source/UIStringTable.h"
#include <m2c_macros.h>

s32 stricmp(s8 *);                                  /* extern */
#if 0 // DRAFT: identifier 'UIMessageStrings' redeclared was declared as: 'unsigned char[64]' now declared as: 'long'
static M2C_UNK UIMessageStrings;                    /* unable to generate initializer: unknown type */
#endif
#if 0 // DRAFT: identifier 'UIMessageArgType' redeclared was declared as: 'unsigned char[64]' now declared as: 'long[16]'
static s32 UIMessageArgType[0x10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1, 1, 0 };
#endif

s32 UIEvent::Send() {
    s8 *spC;
    s32 sp8;
    s32 temp_r6_17;
    s8 *temp_r5_24;
    void **temp_r0_14;

    temp_r0_14 = this->unk0;
    if ((temp_r0_14 == NULL) || (temp_r6_17 = this->unk4, ((temp_r6_17 == 0) != 0))) {
        return -1;
    }
    temp_r5_24 = this->unk8;
    sp8 = temp_r6_17;
    spC = temp_r5_24;
    return M2C_FIELD(*temp_r0_14, s32 (**)(void **, s32 *, s8 *), 0x2C)(temp_r0_14, &sp8, temp_r5_24);
}

void UIEvent::Resolve(UIObject *arg0) {
    const char *name;
    s8 *argName;

    /* unk0 starts as a name string; the lookup replaces it with the object it names. */
    name = (const char *) this->unk0;
    if (name != NULL) {
        this->unk0 = (void **) arg0->Find(name);
        UIStringTable_Remove(name);
    }
    if (((void **) this->unk0 != NULL) && (GetScriptArgType(this->unk4) == 1)) {
        argName = this->unk8;
        if (argName != NULL) {
            this->unk8 = (s8 *) ((UIObject *) this->unk0)->Find((const char *) argName);
            UIStringTable_Remove((const char *) argName);
        }
    }
}

#if 0 // DRAFT: illegal implicit conversion from 'signed char **' to 'const char **'
s32 UIEvent::LoadLine(const char *arg0, UIDataLine *arg1) {
    s8 *sp8;
    MKIniLine *var_r29_106;
    s32 temp_r3_146;

    if (((MKIniLine *) arg1)->IsField(arg0) != 0) {
        var_r29_106 = arg1->unkC->GetSubLine((MKIniLine *) arg1);
loop_18:
        if (var_r29_106 != NULL) {
            sp8 = NULL;
            if (var_r29_106->LoadString("target", &sp8, 0) != 0) {
                UIStringTable_Add(sp8);
                this->unk0 = M2C_ERROR(/* Read from unset register $r3 */);
            } else if (var_r29_106->LoadString("message", &sp8, 0) != 0) {
                this->unk4 = GetMessageFromString(sp8);
            } else if (var_r29_106->IsField("argument") != 0) {
                temp_r3_146 = GetScriptArgType(this->unk4);
                switch (temp_r3_146) {              /* irregular */
                case 0:
                    break;
                case 1:
                    UIStringTable_Add(var_r29_106->GetString(0));
                    this->unk8 = M2C_ERROR(/* Read from unset register $r3 */);
                    break;
                case 2:
                    this->unk8 = (signed char *) (var_r29_106->GetInt(0));
                    break;
                case 3:
                    this->unk8 = var_r29_106->GetFloat(0);
                    break;
                }
            }
            var_r29_106 = var_r29_106->unkC->GetNextLine(var_r29_106);
            goto loop_18;
        }
        return 1;
    }
    return 0;
}
#endif

s32 GetScriptArgType(int arg0) {
    return UIMessageArgType[arg0];
}

extern "C" s32 stricmp(const char *, const char *);
s32 GetMessageFromString(const char *arg0) {
    const char *entry;
    s32 index;

    /* Scan the 16-entry string table: pointer equality first, then a case-insensitive compare. */
    for (index = 0; index < 0x10; index += 1) {
        entry = ((const char **) UIMessageStrings)[index];
        if ((entry == arg0) || (stricmp(entry, arg0) == 0)) {
            return index;
        }
    }
    return 0;
}
