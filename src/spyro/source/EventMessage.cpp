#include "spyro/source/EventMessage.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKProp.h"
#include "spyro/source/ChunkData.h"
#include "spyro/source/UIStringTable.h"
#include "spyro/source/GameConsole.h"
#include <m2c_macros.h>

extern MKProp *ConsoleCmds_pSenderProp;

#if 0 // DRAFT: function call 'Console_Execute(signed char *)' does not match
f32 EventMessage::Send(MKProp *arg0) {
    f32 var_f1_13;

    var_f1_13 = 1.0f;
    if ((u32) this->unk0 != 0U) {
        ConsoleCmds_pSenderProp = arg0;
        var_f1_13 = Console_Execute((s8 *) this->unk0);
        ConsoleCmds_pSenderProp = NULL;
    }
    return var_f1_13;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long' to
s32 EventMessage::LoadLine(MKIniLine *arg0, const char *arg1) {
    MKIniLine *var_r30_48;
    s8 *temp_r3_59;

    if (arg0->IsField(arg1) != 0) {
        var_r30_48 = arg0->unkC->GetSubLine(arg0);
loop_7:
        if (var_r30_48 == NULL) {
            goto block_8;
        }
        if (var_r30_48->IsField("ScriptCommand") != 0) {
            temp_r3_59 = var_r30_48->GetString(0);
            if ((s8) *temp_r3_59 != 0) {
                this->unk0 = ((UIStringTable *) (*ChunkData::pCurrentEventStrings))->Add(temp_r3_59);
            }
            return 1;
        }
        var_r30_48 = var_r30_48->unkC->GetNextLine(var_r30_48);
        goto loop_7;
    }
block_8:
    return 0;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'signed char *' to
void EventMessage::Deinit() {
    s32 temp_r4_96;

    temp_r4_96 = this->unk0;
    if ((u32) temp_r4_96 != 0U) {
        ((UIStringTable *) (*ChunkData::pCurrentEventStrings))->Remove((s8 *) temp_r4_96);
    }
    this->unk0 = 0;
}
#endif

void EventMessage::Init() {
    this->unk0 = 0;
}

#if 0 // DRAFT: illegal implicit conversion from 'signed char *' to
EventMessage *EventMessage::operator=(const EventMessage &arg0) {
    this->unk0 = ((UIStringTable *) (*ChunkData::pCurrentEventStrings))->Add((s8 *) arg0.unk0);
    return this;
}
#endif
