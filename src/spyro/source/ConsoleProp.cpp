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

M2C_UNK free(void *);                               /* extern */
void *malloc(s32);                                  /* extern */

s32 ConsoleProp::LoadDone() {
    s32 off;
    s32 i;

    MKProp::LoadDone();
    off = 0;
    for (i = 0; i < this->unk50; i++) {
        Console_AddMacro((const char *) ((u8 *) this->unk4C + off), *(const char **) ((u8 *) this->unk4C + off + 0x20));
        *(const char **) ((u8 *) this->unk4C + off + 0x20) = NULL;
        off += 0x24;
    }
}

s32 ConsoleProp::LoadLine(MKIniLine *arg0) {
    MKIniLine *macro;
    MKIniLine *sub;
    void *mem;
    s32 off;

    if (MKProp::LoadLine(arg0) != 0) {
        return 1;
    }
    if (arg0->IsField("Macros") != 0) {
        this->unk50 = arg0->GetNmbrOfSubLines();
        if (this->unk50 != 0) {
            if (MKHeap::Current() != NULL) {
                mem = ((MKHeap *) (MKHeap::Current()))->Alloc(this->unk50 * 0x24, NULL, 0);
            } else {
                mem = malloc(this->unk50 * 0x24);
            }
            this->unk4C = mem;
            memset(this->unk4C, 0, this->unk50 * 0x24);
            sub = arg0->unkC->GetSubLine(arg0);
            off = 0;
            while (sub != NULL) {
                if (sub->IsField("Macro") != 0) {
                    macro = sub->unkC->GetSubLine(sub);
                    // The shipped loop never advances `macro` (asm 0x8022E938-0x8022E9A4
                    // branches back without GetNextLine): a Macro with sub-lines hangs.
                    while (macro != NULL) {
                        if (macro->IsField("MacroName") != 0) {
                            strcpy((char *) ((u8 *) this->unk4C + off), (const char *) macro->GetString(0));
                        } else if (macro->IsField("ScriptCommand") != 0) {
                            *(const char **) ((u8 *) this->unk4C + off + 0x20) = (const char *) macro->GetString(0);
                        }
                    }
                }
                off += 0x24;
                sub = sub->unkC->GetNextLine(sub);
            }
        }
        return 1;
    }
    return 0;
}

void ConsoleProp::Deinit() {
    s32 i;
    s32 off;
    void *mem;

    if (this->unk4C != NULL) {
        off = 0;
        for (i = 0; i < this->unk50; i++) {
            Console_RemoveMacro((const char *) ((u8 *) this->unk4C + off));
            off += 0x24;
        }
        mem = this->unk4C;
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(mem, NULL, 0);
        } else {
            free(mem);
        }
    }
    this->unk4C = NULL;
    this->unk50 = 0;
    MKProp::Deinit();
}

void ConsoleProp::Init() {
    MKProp::Init();
    this->unk4C = NULL;
    this->unk50 = 0;
}
