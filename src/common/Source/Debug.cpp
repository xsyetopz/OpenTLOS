#include "common/Source/Debug.h"
#include "common/Source/Font.h"
#include "common/Source/MKFont.h"
#include <m2c_macros.h>

extern MKFont *gpDebugFont;

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'MKVector3'
s32 ValidateVector(const MKVector3 &arg0) {
    s32 var_r5_12;

    var_r5_12 = 0;
    if (((u32) ((M2C_BITWISE(s32, arg0.unk0) & 0x7F800000) + 0x80800000) != 0U) && ((u32) ((M2C_BITWISE(s32, arg0.unk4) & 0x7F800000) + 0x80800000) != 0U) && ((u32) ((M2C_BITWISE(s32, arg0.unk8) & 0x7F800000) + 0x80800000) != 0U)) {
        var_r5_12 = 1;
    }
    return var_r5_12;
}
#endif

void Debug_SetFont(MKFont *arg0) {
    gpDebugFont = arg0;
}

void Debug_DeinitModule() {

}

void Debug_InitModule() {
    gpDebugFont = NULL;
}
