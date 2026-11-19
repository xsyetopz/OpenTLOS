#include "spyro/source/GameEnums.h"
#include "common/Source/MKIni.h"
#include "spyro/source/DataMap.h"
#include <m2c_macros.h>

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'DataMap'
static DataMap propTypeDataMap;                     /* unable to generate initializer: confusing struct layout */

s32 ProjectileType_IsDynamite(int arg0) {
    if (arg0 < 5) {
        if (arg0 < 0) {
            /* Duplicate return node #4. Try simplifying control flow for better match */
            return 0;
        }
        return 1;
    }
    return 0;
}
#endif

#if 0 // DRAFT: function call 'DataMap_LoadLineBitfield(MKIniLine *, char *, DataMap *,
s32 PropTypes_LoadLine(MKIniLine *arg0, char *arg1, int *arg2) {
    u32 sp8;

    sp8 = 0;
    if (DataMap_LoadLineBitfield(arg0, arg1, &propTypeDataMap, &sp8) != 0) {
        *arg2 |= sp8;
        return 1;
    }
    return 0;
}
#endif
