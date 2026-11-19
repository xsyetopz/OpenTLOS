#include "common/Source/Str.h"
#include <m2c_macros.h>

M2C_UNK strlwr();                                   /* extern */
M2C_UNK strupr();                                   /* extern */
extern s32 bufferIndex;
static M2C_UNK buffer;

/*
Decompilation failure in function Str_CompareIgnoreCase__FPCcPCc:

Cannot find branch target Str_CompareIgnoreCase__FPCcPCc
*/

u8 *Str_FindChar(const char *arg0, int arg1) {
    s8 *var_r3_0;
    u8 temp_r5_49;

    var_r3_0 = (signed char *) (arg0);
loop_3:
    temp_r5_49 = (u8) *var_r3_0;
    if ((s8) temp_r5_49 == 0) {
        return NULL;
    }
    if ((s8) temp_r5_49 != arg1) {
        var_r3_0 += 1;
        goto loop_3;
    }
    return (u8 *) var_r3_0;
}

#if 0 // DRAFT: type mismatch 'signed char *' and 'const char *'
s8 *Str_GetFilenameFromPath(const char *arg0) {
    s32 temp_r3_103;
    s8 *temp_r31_95;
    s8 *var_r4_65;
    u8 temp_r0_72;
    u8 temp_r0_81;

    var_r4_65 = (signed char *) (&arg0[strlen(arg0)]);
loop_2:
    if (var_r4_65 != arg0) {
        temp_r0_72 = (u8) *var_r4_65;
        if (((s8) temp_r0_72 != 0x2F) && ((s8) temp_r0_72 != 0x3A) && ((s8) temp_r0_72 != 0x5C)) {
            var_r4_65 -= 1;
            goto loop_2;
        }
    }
    temp_r0_81 = (u8) *var_r4_65;
    if (((s8) temp_r0_81 == 0x3A) || ((s8) temp_r0_81 == 0x2F) || ((s8) temp_r0_81 == 0x5C)) {
        var_r4_65 += 1;
    }
    temp_r31_95 = (signed char *) (&buffer + bufferIndex);
    strcpy(temp_r31_95, var_r4_65);
    temp_r3_103 = bufferIndex + ((strlen(temp_r31_95) + 0x10) & 0xFFFFFFF0);
    bufferIndex = temp_r3_103;
    if ((s32) (temp_r3_103 + 0x400) > 0x4000) {
        bufferIndex = 0;
    }
    return temp_r31_95;
}
#endif

void Str_Lower(const char *arg0) {
    Str_Dup(arg0);
    strlwr();
}

void Str_Upper(const char *arg0) {
    Str_Dup(arg0);
    strupr();
}

#if 0 // DRAFT: function call 'strcpy(signed char *, const char *)' does not match 'strcpy(char *, const char *)'
s8 *Str_Dup(const char *arg0) {
    s32 temp_r3_167;
    s8 *temp_r30_160;
    u32 temp_r31_159;

    temp_r31_159 = strlen(arg0);
    temp_r30_160 = (signed char *) (&buffer + bufferIndex);
    strcpy(temp_r30_160, arg0);
    temp_r3_167 = bufferIndex + ((temp_r31_159 + 0x10) & 0xFFFFFFF0);
    bufferIndex = temp_r3_167;
    if ((s32) (temp_r3_167 + 0x400) > 0x4000) {
        bufferIndex = 0;
    }
    return temp_r30_160;
}
#endif

u8 *Str_CopyString(const char *arg0, int arg1) {
    s32 temp_r3_209;
    s32 var_r8_189;
    s8 *var_r3_0;
    u8 *temp_r7_190;
    u8 *var_r5_191;
    u8 temp_r6_201;

    var_r3_0 = (signed char *) (arg0);
    var_r8_189 = 0;
    temp_r7_190 = (unsigned char *) (&buffer + bufferIndex);
    var_r5_191 = temp_r7_190;
loop_2:
    if (var_r8_189 < arg1) {
        temp_r6_201 = (u8) *var_r3_0;
        if ((s8) temp_r6_201 != 0) {
            *var_r5_191 = temp_r6_201;
            var_r8_189 += 1;
            var_r3_0 += 1;
            var_r5_191 += 1;
            goto loop_2;
        }
    }
    temp_r3_209 = bufferIndex + ((var_r8_189 + 0x10) & 0xFFFFFFF0);
    *(temp_r7_190 + var_r8_189) = 0;
    bufferIndex = temp_r3_209;
    if ((s32) (temp_r3_209 + 0x400) > 0x4000) {
        bufferIndex = 0;
    }
    return temp_r7_190;
}

#if 0 // DRAFT: ')' expected
s32 Str_snPrintf(char *arg0, int arg1, const char *arg2, ... arg3) {
    s8 **sp70;
    M2C_UNK *sp6C;
    s32 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    s32 sp24;
    s32 sp20;
    s32 sp1C;
    s32 sp18;
    s32 sp14;
    s8 *sp10;
    s32 spC;
    s8 *sp8;
    s32 temp_r4_276;
    s8 *temp_r29_262;
    u32 temp_r3_272;

    if (M2C_ERROR(/* Read from unset register $cr0_eq */)) {
        sp28 = farg0;
        sp30 = farg1;
        sp38 = farg2;
        sp40 = farg3;
        sp48 = farg4;
        sp50 = farg5;
        sp58 = farg6;
        sp60 = farg7;
    }
    sp8 = arg0;
    spC = arg1;
    sp10 = arg2;
    sp14 = arg3;
    sp18 = arg4;
    sp1C = arg5;
    sp20 = arg6;
    sp24 = arg7;
    if ((arg0 == NULL) || (arg1 == 0)) {
        return 0;
    }
    temp_r29_262 = &buffer + bufferIndex;
    sp68 = 0x03000000;
    sp6C = &arg_sp8;
    sp70 = &sp8;
    vsprintf(temp_r29_262, arg2, (struct _anonymous *) &sp68);
    temp_r3_272 = strlen(temp_r29_262);
    temp_r4_276 = bufferIndex + ((temp_r3_272 + 0x10) & 0xFFFFFFF0);
    bufferIndex = temp_r4_276;
    if ((s32) (temp_r4_276 + 0x400) > 0x4000) {
        bufferIndex = 0;
    }
    if ((s32) temp_r3_272 >= arg1) {
        strncpy(arg0, temp_r29_262, (u32) arg1);
        return -1;
    }
    strcpy(arg0, temp_r29_262);
    return 4;
}
#endif

#if 0 // DRAFT: ')' expected
s8 *Str_Printf(const char *arg0, ... arg1) {
    s8 **sp70;
    M2C_UNK *sp6C;
    s32 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    s32 sp24;
    s32 sp20;
    s32 sp1C;
    s32 sp18;
    s32 sp14;
    s32 sp10;
    s32 spC;
    s8 *sp8;
    s32 temp_r3_350;
    s8 *temp_r30_329;

    if (M2C_ERROR(/* Read from unset register $cr0_eq */)) {
        sp28 = farg0;
        sp30 = farg1;
        sp38 = farg2;
        sp40 = farg3;
        sp48 = farg4;
        sp50 = farg5;
        sp58 = farg6;
        sp60 = farg7;
    }
    spC = arg1;
    temp_r30_329 = &buffer + bufferIndex;
    sp8 = arg0;
    sp10 = arg2;
    sp14 = arg3;
    sp18 = arg4;
    sp1C = arg5;
    sp20 = arg6;
    sp24 = arg7;
    sp68 = 0x01000000;
    sp6C = &arg_sp8;
    sp70 = &sp8;
    vsprintf(temp_r30_329, arg0, (struct _anonymous *) &sp68);
    temp_r3_350 = bufferIndex + ((strlen(temp_r30_329) + 0x10) & 0xFFFFFFF0);
    bufferIndex = temp_r3_350;
    if ((s32) (temp_r3_350 + 0x400) > 0x4000) {
        bufferIndex = 0;
    }
    return temp_r30_329;
}
#endif
