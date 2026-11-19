#include "spyro/source/DataMap.h"
#include "common/Source/MKIni.h"
#include <m2c_macros.h>

#if 0 // DRAFT: function call 'DataMap_GetValue(const DataMap *, long)' does not match 'DataMap_GetValue(const DataMap *, const char *)'
s32 stricmp(s8 *);                                  /* extern */

s32 DataMap_LoadLineBitfield(MKIniLine *arg0, const char *arg1, const DataMap *arg2, unsigned int *arg3) {
    s16 temp_r31_21;
    s32 temp_r3_32;
    s32 var_r30_23;

    if (arg0->IsField(arg1) != 0) {
        temp_r31_21 = arg0->unk0;
        var_r30_23 = 0;
        *arg3 = 0;
loop_3:
        if (var_r30_23 < temp_r31_21) {
            temp_r3_32 = DataMap_GetValue(arg2, arg0->GetString(var_r30_23));
            var_r30_23 += 1;
            *arg3 |= temp_r3_32;
            goto loop_3;
        }
        return 1;
    }
    return 0;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'signed char **' to 'const char **'
s32 DataMap_LoadLine(MKIniLine *arg0, const char *arg1, const DataMap *arg2, unsigned int *arg3) {
    s8 *sp8;
    s32 var_r31_68;
    void *temp_r30_82;

    sp8 = NULL;
    if (arg0->LoadString(arg1, &sp8, 0) != 0) {
        var_r31_68 = 0;
loop_5:
        temp_r30_82 = arg2 + var_r31_68;
        if ((u32) M2C_FIELD(temp_r30_82, u32 *, 4) == 0U) {
            *arg3 = 0;
            return 1;
        }
        if (stricmp(sp8) == 0) {
            *arg3 = M2C_FIELD(temp_r30_82, u32 *, 0);
            return 1;
        }
        var_r31_68 += 8;
        goto loop_5;
    }
    return 0;
}
#endif

#if 0 // DRAFT: illegal type
s32 DataMap_GetName(const DataMap *arg0, unsigned int arg1) {
    s32 var_r5_103;
    void *temp_r6_115;

    var_r5_103 = 0;
loop_4:
    temp_r6_115 = arg0 + var_r5_103;
    if ((u32) M2C_FIELD(temp_r6_115, u32 *, 4) == 0U) {
        return 0;
    }
    if (arg1 == (u32) M2C_FIELD(temp_r6_115, u32 *, 0)) {
        return M2C_FIELD((arg0 + var_r5_103), s32 *, 4);
    }
    var_r5_103 += 8;
    goto loop_4;
}
#endif

#if 0 // DRAFT: illegal type
s32 DataMap_GetValue(const DataMap *arg0, const char *arg1) {
    s32 var_r31_132;
    void *temp_r30_144;

    var_r31_132 = 0;
loop_4:
    temp_r30_144 = arg0 + var_r31_132;
    if ((u32) M2C_FIELD(temp_r30_144, u32 *, 4) == 0U) {
        return 0;
    }
    if (stricmp(arg1) == 0) {
        return M2C_FIELD(temp_r30_144, s32 *, 0);
    }
    var_r31_132 += 8;
    goto loop_4;
}
#endif
