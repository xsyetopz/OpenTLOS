#include "spyro/source/UIMessage.h"
#include "common/Source/MKIni.h"
#include "spyro/source/UIObject.h"
#include "spyro/source/UIStringTable.h"
#include <m2c_macros.h>

#if 0 // DRAFT: identifier 'UIMessageStrings' redeclared
s32 stricmp(s8 *);                                  /* extern */
static M2C_UNK UIMessageStrings;                    /* unable to generate initializer: unknown type */
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

#if 0 // DRAFT: illegal implicit conversion from 'void **' to
void UIEvent::Resolve(UIObject *arg0) {
    s8 *temp_r31_69;
    void **temp_r0_48;
    void **temp_r3_72;

    temp_r0_48 = this->unk0;
    if (temp_r0_48 != NULL) {
        this->unk0 = arg0->Find(temp_r0_48);
        UIStringTable_Remove((s8 *) temp_r0_48);
    }
    if (((void **) this->unk0 != NULL) && (GetScriptArgType(this->unk4) == 1)) {
        temp_r31_69 = this->unk8;
        if (temp_r31_69 != NULL) {
            temp_r3_72 = this->unk0;
            this->unk8 = M2C_FIELD(*temp_r3_72, s8 *(**)(void **, s8 *), 0x30)(temp_r3_72, temp_r31_69);
            UIStringTable_Remove(temp_r31_69);
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'IsField'
s32 UIEvent::LoadLine(const char *arg0, UIDataLine *arg1) {
    s8 *sp8;
    MKIniLine *var_r29_106;
    s32 temp_r3_146;

    if (arg1->IsField(arg0) != 0) {
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
                    this->unk8 = var_r29_106->GetInt(0);
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

#if 0 // DRAFT: illegal operand
s32 GetMessageFromString(const char *arg0) {
    s32 var_r29_216;
    s32 var_r31_217;

    var_r29_216 = 0;
    var_r31_217 = 0;
loop_1:
    if (((u32) *(&UIMessageStrings + var_r31_217) == arg0) || (stricmp(arg0) == 0)) {
        return var_r29_216;
    }
    var_r29_216 += 1;
    var_r31_217 += 4;
    if (var_r29_216 >= 0x10) {
        return 0;
    }
    goto loop_1;
}
#endif
