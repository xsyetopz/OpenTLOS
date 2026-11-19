#include "spyro/source/MessageMap.h"
#include "common/Source/MKIni.h"
#include <m2c_macros.h>

#if 0 // DRAFT: illegal implicit conversion from 'signed char **' to
s32 stricmp(s8 *, s32);                             /* extern */
static MessageMap globalMessageMap = { 0xA8, 0xC4 }; /* extra bytes: 4 */

s32 MessageMap_LoadLine(MKIniLine *arg0, char *arg1, int *arg2) {
    s8 *sp8;

    sp8 = NULL;
    if (arg0->LoadString(arg1, &sp8, 0) != 0) {
        *arg2 = globalMessageMap.GetIdFromString(sp8);
        return 1;
    }
    return 0;
}
#endif

#if 0 // DRAFT: pointer/array required
s32 MessageMap::GetIdFromString(const char *arg0) const {
    s32 temp_r29_48;
    s32 temp_r30_50;
    s32 var_r28_51;
    s32 var_r31_52;

    temp_r29_48 = M2C_FIELD(this, s32 *, 8);
    temp_r30_50 = this->unk4;
    var_r28_51 = 0;
    var_r31_52 = 0;
loop_4:
    if (var_r28_51 >= temp_r30_50) {
        return 0;
    }
    if (stricmp(arg0, *(temp_r29_48 + var_r31_52)) == 0) {
        return var_r28_51 + this->unk0;
    }
    var_r28_51 += 1;
    var_r31_52 += 4;
    goto loop_4;
}
#endif
