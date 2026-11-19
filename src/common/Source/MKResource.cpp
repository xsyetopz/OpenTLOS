#include "common/Source/MKResource.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/Level.h"
#include <m2c_macros.h>

extern void **gMK;
u8 sWorkingChunkID__10MKResource[4] = { 0xFF, 0xFF, 0xFF, 0xFF };

void MKResource::InitialiseResource() {
    this->unk20 = *MKResource::sWorkingChunkID;
}

s32 MKResource::IsResourceAvailable() {
    s32 temp_r4_38;
    s32 var_r3_39;
    u8 var_r31_24;
    void *temp_r3_32;

    var_r31_24 = 0;
    if ((void **) gMK != NULL) {
        temp_r3_32 = M2C_FIELD(*gMK, void *(**)(void **), 0x7C)(gMK);
        if (temp_r3_32 != NULL) {
            var_r31_24 = ((u32) M2C_FIELD(temp_r3_32, u32 *, 0x13C) >> 0xBU) & 1;
        }
    }
    temp_r4_38 = this->unk20;
    var_r3_39 = 0;
    if ((temp_r4_38 == -1) || (temp_r4_38 == (s32) *MKResource::sWorkingChunkID) || ((s32) *MKHeap::tempMemOverride > 0) || (var_r31_24 != 0)) {
        var_r3_39 = 1;
    }
    return var_r3_39;
}
