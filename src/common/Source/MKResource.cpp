#include "common/Source/MKResource.h"
#include "common/Source/MKHeap.h"
#include <m2c_macros.h>

extern void **gMK;
#if 0 // DRAFT: undefined identifier 'sWorkingChunkID'
static MKResource sWorkingChunkID__10MKResource;    /* type too large by 0x28; unable to generate initializer: not enough data */

void MKResource::InitialiseResource() {
    this->unk20 = sWorkingChunkID.unk0;
}
#endif

#if 0 // DRAFT: undefined identifier 'sWorkingChunkID'
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
    if ((temp_r4_38 == -1) || (temp_r4_38 == (s32) sWorkingChunkID.unk0) || ((MKHeap *) tempMemOverride.unk0 > 0) || (var_r31_24 != 0)) {
        var_r3_39 = 1;
    }
    return var_r3_39;
}
#endif
