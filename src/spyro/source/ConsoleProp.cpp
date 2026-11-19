#include "spyro/source/ConsoleProp.h"
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
#include "spyro/source/GameConsole.h"
#include <m2c_macros.h>

#if 0 // DRAFT: illegal implicit conversion from 'unsigned char *' to
M2C_UNK free(void *);                               /* extern */
void *malloc(s32);                                  /* extern */

void ConsoleProp::LoadDone() {
    s32 temp_r0_57;
    s32 var_r29_48;
    s32 var_r31_47;
    s8 *temp_r3_53;

    MKProp::LoadDone();
    var_r31_47 = 0;
    var_r29_48 = 0;
loop_2:
    if (var_r29_48 < (s32) this->unk50) {
        temp_r3_53 = ((u8 *) this->unk4C) + var_r31_47;
        Console_AddMacro(temp_r3_53, M2C_FIELD(temp_r3_53, s8 **, 0x20));
        temp_r0_57 = var_r31_47 + 0x20;
        var_r29_48 += 1;
        var_r31_47 += 0x24;
        *(this->unk4C + temp_r0_57) = 0;
        goto loop_2;
    }
}
#endif

#if 0 // DRAFT: function call 'strcpy(unsigned char *, long)' does not match
s32 ConsoleProp::LoadLine(MKIniLine *arg0) {
    MKHeap *temp_r3_100;
    MKIniLine *temp_r27_137;
    MKIniLine *var_r26_123;
    s32 temp_r0_96;
    s32 temp_r28_99;
    s32 temp_r3_94;
    s32 var_r30_125;
    void *var_r3_107;

    if (MKProp::LoadLine(arg0) != 0) {
        return 1;
    }
    if (arg0->IsField("Macros") != 0) {
        temp_r3_94 = arg0->GetNmbrOfSubLines();
        this->unk50 = temp_r3_94;
        temp_r0_96 = this->unk50;
        if (temp_r0_96 != 0) {
            temp_r28_99 = temp_r0_96 * 0x24;
            temp_r3_100 = ((MKHeap *) temp_r3_94)->Current();
            if (temp_r3_100 != NULL) {
                var_r3_107 = ((MKHeap *) (temp_r3_100->Current()))->Alloc(temp_r28_99, NULL, 0);
            } else {
                var_r3_107 = malloc(temp_r28_99);
            }
            this->unk4C = var_r3_107;
            memset(this->unk4C, 0, this->unk50 * 0x24);
            var_r26_123 = arg0->unkC->GetSubLine(arg0);
            var_r30_125 = 0;
loop_16:
            if (var_r26_123 != NULL) {
                if (var_r26_123->IsField("Macro") != 0) {
                    temp_r27_137 = var_r26_123->unkC->GetSubLine(var_r26_123);
loop_14:
                    if (temp_r27_137 != NULL) {
                        if (temp_r27_137->IsField("MacroName") != 0) {
                            strcpy(((u8 *) this->unk4C) + var_r30_125, temp_r27_137->GetString(0));
                        } else if (temp_r27_137->IsField("ScriptCommand") != 0) {
                            *(var_r30_125 + (((u8 *) this->unk4C) + 0x20)) = temp_r27_137->GetString(0);
                        }
                        goto loop_14;
                    }
                }
                var_r30_125 += 0x24;
                var_r26_123 = var_r26_123->unkC->GetNextLine(var_r26_123);
                goto loop_16;
            }
        }
        return 1;
    }
    return 0;
}
#endif

#if 0 // DRAFT: function call 'Console_RemoveMacro(unsigned char *)' does not match
void ConsoleProp::Deinit() {
    MKHeap *temp_r3_218;
    s32 var_r30_204;
    s32 var_r31_205;
    void *temp_r31_217;

    if ((void *) this->unk4C != NULL) {
        var_r30_204 = 0;
        var_r31_205 = 0;
loop_3:
        if (var_r30_204 < (s32) this->unk50) {
            Console_RemoveMacro(((u8 *) this->unk4C) + var_r31_205);
            var_r30_204 += 1;
            var_r31_205 += 0x24;
            goto loop_3;
        }
        temp_r31_217 = this->unk4C;
        temp_r3_218 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_218 != NULL) {
            ((MKHeap *) (temp_r3_218->Current()))->Free(temp_r31_217, NULL, 0);
        } else {
            free(temp_r31_217);
        }
    }
    this->unk4C = NULL;
    this->unk50 = 0;
    MKProp::Deinit();
}
#endif

void ConsoleProp::Init() {
    MKProp::Init();
    this->unk4C = NULL;
    this->unk50 = 0;
}
