#include "spyro/source/DataMap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKVector3.h"
#include <m2c_macros.h>

s32 stricmp(s8 *);                                  /* extern */

s32 DataMap_LoadLineBitfield(MKIniLine *arg0, const char *arg1, const DataMap *arg2, unsigned int *arg3) {
    s16 temp_r31_21;
    s32 temp_r3_32;
    s32 var_r30_23;

    if ((u8) arg0->IsField(arg1) != 0) {
        temp_r31_21 = arg0->unk0;
        *arg3 = 0;
        for (var_r30_23 = 0; var_r30_23 < temp_r31_21;) {
            temp_r3_32 = DataMap_GetValue(arg2, (const char *) arg0->GetString(var_r30_23));
            var_r30_23 += 1;
            *arg3 |= temp_r3_32;
        }
        return 1;
    }
    return 0;
}

extern "C" s32 stricmp(s8 *, s8 *);

s32 DataMap_LoadLine(MKIniLine *arg0, const char *arg1, const DataMap *arg2, unsigned int *arg3) {
    s32 var_r31_68;
    void *temp_r30_82;
    s8 *temp_r3_82;
    const char *sp8;

    sp8 = 0;
    if ((u8) arg0->LoadString(arg1, &sp8, 0) != 0) {
        for (var_r31_68 = 0; temp_r30_82 = (s8 *) arg2 + var_r31_68, temp_r3_82 = M2C_FIELD(temp_r30_82, s8 **, 4), temp_r3_82 != 0; var_r31_68 += 8) {
            if (stricmp(temp_r3_82, (s8 *) sp8) == 0) {
                *arg3 = M2C_FIELD(temp_r30_82, u32 *, 0);
                return 1;
            }
        }
        *arg3 = 0;
        return 1;
    }
    return 0;
}

s32 DataMap_GetName(const DataMap *arg0, unsigned int arg1) {
    s32 var_r5_103;
    s8 *temp_r6_115;

    for (var_r5_103 = 0; temp_r6_115 = (s8 *) arg0 + var_r5_103, (u32) M2C_FIELD(temp_r6_115, u32 *, 4) != 0U; var_r5_103 += 8) {
        if (arg1 == (u32) M2C_FIELD(temp_r6_115, u32 *, 0)) {
            return M2C_FIELD(arg0, s32 *, var_r5_103 + 4);
        }
    }
    return 0;
}

extern "C" s32 stricmp(s8 *, s8 *);

s32 DataMap_GetValue(const DataMap *arg0, const char *arg1) {
    s32 var_r31_132;
    void *temp_r30_144;
    s8 *temp_r3_144;

    for (var_r31_132 = 0; temp_r30_144 = (s8 *) arg0 + var_r31_132, temp_r3_144 = M2C_FIELD(temp_r30_144, s8 **, 4), temp_r3_144 != 0; var_r31_132 += 8) {
        if (stricmp(temp_r3_144, (s8 *) arg1) == 0) {
            return M2C_FIELD(temp_r30_144, s32 *, 0);
        }
    }
    return 0;
}
