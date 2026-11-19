#include "spyro/source/EventMessage.h"
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
#include "common/Source/Matrix.h"
#include "spyro/source/ChunkData.h"
#include "spyro/source/UIStringTable.h"
#include "spyro/source/GameConsole.h"
#include <m2c_macros.h>

extern MKProp *ConsoleCmds_pSenderProp;

f32 EventMessage::Send(MKProp *arg0) {
    f32 var_f1_13;

    var_f1_13 = 1.0f;
    if ((u32) this->unk0 != 0U) {
        ConsoleCmds_pSenderProp = arg0;
        var_f1_13 = Console_Execute((const char *) this->unk0);
        ConsoleCmds_pSenderProp = NULL;
    }
    return var_f1_13;
}

s32 EventMessage::LoadLine(MKIniLine *arg0, const char *arg1) {
    MKIniLine *var_r30_48;
    const char *temp_r3_59;

    if (arg0->IsField(arg1) != 0) {
        var_r30_48 = arg0->unkC->GetSubLine(arg0);
        while (var_r30_48 != NULL) {
            if (var_r30_48->IsField("ScriptCommand") != 0) {
                temp_r3_59 = (const char *) var_r30_48->GetString(0);
                if (*temp_r3_59 != 0) {
                    this->unk0 = (*(UIStringTable **) ChunkData::pCurrentEventStrings)->Add(temp_r3_59);
                }
                return 1;
            }
            var_r30_48 = var_r30_48->unkC->GetNextLine(var_r30_48);
        }
    }
    return 0;
}

void EventMessage::Deinit() {
    s32 temp_r4_96;

    temp_r4_96 = this->unk0;
    if ((u32) temp_r4_96 != 0U) {
        (*(UIStringTable **) ChunkData::pCurrentEventStrings)->Remove((const char *) temp_r4_96);
    }
    this->unk0 = 0;
}

void EventMessage::Init() {
    this->unk0 = 0;
}

EventMessage *EventMessage::operator=(const EventMessage &arg0) {
    this->unk0 = (*(UIStringTable **) ChunkData::pCurrentEventStrings)->Add((const char *) arg0.unk0);
    return this;
}
