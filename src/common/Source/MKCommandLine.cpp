#include "common/Source/MKCommandLine.h"
#include <m2c_macros.h>

s32 stricmp(s8 *, u8 *);                            /* extern */
extern u8 init_221;
extern u8 *pPositive_220;
static u8 lit_stringBase0[4] = { 0x2B, 0, 0x2D, 0 };   /* const */

#if 0 // DRAFT: illegal explicit conversion from 'MKCommandLine' to 'unsigned long'
void MKCommandLine::ParseArgument(char *arg0) {
    s32 var_ctr_40;
    s32 var_r28_39;
    s8 *temp_r31_22;
    u32 var_r27_17;
    u8 temp_r0_23;

    var_r27_17 = 0U;
loop_2:
    temp_r31_22 = (signed char *) (&arg0[var_r27_17]);
    temp_r0_23 = (u8) *temp_r31_22;
    if (((s8) temp_r0_23 != 0x2D) && ((s8) temp_r0_23 != 0x2B) && ((s8) temp_r0_23 != 0x3D) && ((s8) temp_r0_23 != 0x20) && (var_r27_17 < strlen(arg0))) {
        var_r27_17 += 1;
        goto loop_2;
    }
    var_r28_39 = 0;
    var_ctr_40 = 0x10;
loop_8:
    if ((u32) *(this + (var_r28_39 + 4)) == 0U) {
        if (var_r27_17 == strlen(arg0)) {
            M2C_FIELD((this + var_r28_39), s8 **, 8) = (signed char *) (arg0);
        } else if (stricmp(temp_r31_22, lit_stringBase0) == 0) {
            M2C_FIELD((this + var_r28_39), u8 **, 8) = lit_stringBase0;
        } else if (stricmp(temp_r31_22, &lit_stringBase0[2]) == 0) {
            M2C_FIELD((this + var_r28_39), u8 **, 8) = &lit_stringBase0[2];
        } else if ((s32) (u8) *temp_r31_22 != 0x20) {
            M2C_FIELD((this + var_r28_39), s8 **, 8) = (s8 *) (temp_r31_22 + 1);
        }
        *temp_r31_22 = 0;
        M2C_FIELD((this + var_r28_39), s8 **, 4) = (signed char *) (arg0);
        this->unk0 += 1;
        return;
    }
    var_r28_39 += 8;
    var_ctr_40 -= 1;
    if (var_ctr_40 == 0) {
        return;
    }
    goto loop_8;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'MKCommandLine' to 'unsigned long'
u8 *MKCommandLine::GetParameter(const char *arg0, bool arg1) {
    s32 var_r30_125;
    s32 var_r31_126;
    void *temp_r30_136;

    if ((s8) init_221 == 0) {
        init_221 = 1;
        pPositive_220 = lit_stringBase0;
    }
    var_r30_125 = 0;
    var_r31_126 = 0;
loop_3:
    if (((u32) *(this + (var_r31_126 + 4)) != 0U) && (stricmp(arg0) == 0)) {
        temp_r30_136 = this + var_r31_126;
        if (stricmp(M2C_FIELD(temp_r30_136, s8 **, 8), &lit_stringBase0[2]) == 0) {
            return NULL;
        }
        if (stricmp(M2C_FIELD(temp_r30_136, s8 **, 8), M2C_FIELD(temp_r30_136, u8 **, 4)) == 0) {
            return pPositive_220;
        }
        return (u8 *) M2C_FIELD(temp_r30_136, s8 **, 8);
    }
    var_r30_125 += 1;
    var_r31_126 += 8;
    if (var_r30_125 >= 0x10) {
        if (arg1 != 0) {
            return pPositive_220;
        }
        return NULL;
    }
    goto loop_3;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'signed char *' to 'char *'
void MKCommandLine::AddFromString(char *arg0) {
    s32 var_r5_187;
    s8 *temp_r3_193;
    s8 *temp_r4_223;
    s8 *var_r3_225;
    u32 temp_r29_219;
    u32 temp_r3_186;
    u32 var_ctr_189;
    u32 var_r26_224;
    u32 var_r28_217;
    u8 temp_r0_194;
    u8 temp_r0_241;
    u8 var_r27_220;

    temp_r3_186 = strlen(arg0);
    var_r5_187 = 0;
    var_ctr_189 = temp_r3_186;
    if (temp_r3_186 > 0U) {
loop_1:
        temp_r3_193 = (signed char *) (&arg0[var_r5_187]);
        temp_r0_194 = (u8) M2C_FIELD(temp_r3_193, s8 *, 0);
        switch ((s8) temp_r0_194) {                 /* irregular */
        case 10:
        case 13:
            M2C_FIELD(temp_r3_193, s8 *, 0) = 0x20;
        default:
block_7:
            var_r5_187 += 1;
            var_ctr_189 -= 1;
            if (var_ctr_189 != 0) {
                goto loop_1;
            }
            break;
        case 47:
            if ((s32) M2C_FIELD(temp_r3_193, u8 *, 1) == 0x2F) {
                M2C_FIELD(temp_r3_193, s8 *, 0) = 0;
            } else {
                goto block_7;
            }
            break;
        }
    }
    var_r28_217 = 0U;
    temp_r29_219 = strlen(arg0);
    var_r27_220 = 0;
loop_21:
    if (var_r28_217 < temp_r29_219) {
        temp_r4_223 = (signed char *) (&arg0[var_r28_217]);
        var_r26_224 = 0U;
        var_r3_225 = temp_r4_223;
loop_13:
        if (var_r27_220 != 0) {
block_10:
            if ((s32) (u8) *var_r3_225 == 0x22) {
                var_r27_220 = var_r27_220 == 0;
            }
            var_r26_224 += 1;
            var_r3_225 += 1;
            goto loop_13;
        }
        temp_r0_241 = (u8) *var_r3_225;
        if (((s8) temp_r0_241 != 0x20) && ((s8) temp_r0_241 != 0xD) && ((s8) temp_r0_241 != 0xA) && ((u32) (var_r28_217 + var_r26_224) < temp_r29_219)) {
            goto block_10;
        }
        temp_r4_223[var_r26_224] = 0;
        if (var_r26_224 != 0U) {
            ParseArgument(temp_r4_223);
        }
        var_r28_217 = var_r26_224 + var_r28_217 + 1;
        goto loop_21;
    }
}
#endif

void MKCommandLine::InitFromString(char *arg0) {
    s32 var_ctr_282;
    s32 var_r5_280;
    void *temp_r7_284;

    var_r5_280 = 0;
    this->unk0 = 0;
    var_ctr_282 = 0x10;
    do {
        temp_r7_284 = this + var_r5_280;
        var_r5_280 += 8;
        M2C_FIELD(temp_r7_284, s32 *, 4) = 0;
        M2C_FIELD(temp_r7_284, s32 *, 8) = 0;
        var_ctr_282 -= 1;
    } while (var_ctr_282 != 0);
    AddFromString(arg0);
}
