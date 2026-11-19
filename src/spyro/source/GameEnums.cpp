#include "spyro/source/GameEnums.h"
#include "common/Source/MKIni.h"
#include "spyro/source/DataMap.h"
#include <m2c_macros.h>

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'DataMap'
static DataMap propTypeDataMap[0x13] = {
    { 2, "Prop" },
    { 4, "Friend" },
    { 8, "Enemy" },
    { 0x10, "Trap" },
    { 0x20, "CutScene" },
    { 0x40, "Hero" },
    { 0x80, "Ignorable" },
    { 0x100, "WaterVolume" },
    { 0x200, "Shatterable" },
    { 0x400, "DontGetColour" },
    { 0x800, "Interactive" },
    { 0x1000, "Butterfly" },
    { 0x2000, "Pushable" },
    { 0x4000, "Platform" },
    { 0x8000, "BreakableDoor" },
    { 0x10000, "EventCamera" },
    { 0x20000, "RopeBridge" },
    { 0x40000, "Trigger" },
    { 0, NULL },
};
#endif

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

#if 0 // DRAFT: function call 'DataMap_LoadLineBitfield(MKIniLine *, char *, DataMap, unsigned int *)' does not match 'DataMap_LoadLineBitfield(MKIniLine *, const char *, const
s32 PropTypes_LoadLine(MKIniLine *arg0, char *arg1, int *arg2) {
    u32 sp8;

    sp8 = 0;
    if (DataMap_LoadLineBitfield(arg0, arg1, propTypeDataMap, (unsigned int *) &sp8) != 0) {
        *arg2 |= sp8;
        return 1;
    }
    return 0;
}
#endif
