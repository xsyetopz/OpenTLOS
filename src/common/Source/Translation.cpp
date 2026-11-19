#include "common/Source/Translation.h"
#include "common/Source/MKHeap.h"
#include "unplaced_enums.h"
#include "dolphin/os.h"
#include "common/Source/FileSys.h"
#include "common/Source/Str.h"
#include <m2c_macros.h>

s32 atoi(u8 *);                                     /* extern */
M2C_UNK free(u8 *);                                 /* extern */
u8 *malloc(s32);                                    /* extern */
s32 strcmpi(void *, void *, u8 *);                  /* extern */
extern s32 gDisplay;
extern s32 gLanguageDebugOption;
extern M2C_UNK gMKDefaults;
extern s32 gNmbrOfStrings;
#if 0 // DRAFT: identifier 'gNullStr' redeclared
extern M2C_UNK gNullStr;
#endif
extern u8 *gpEnumTagArray;
extern u8 *gpTranslationBuffer;
#if 0 // DRAFT: identifier 'gpTranslation_StringArray' redeclared
extern u8 *gpTranslation_StringArray;
#endif
#if 0 // DRAFT: illegal use of incomplete struct/union/class '_struct_gLanguageInfo_0x14'
static struct _struct_gLanguageInfo_0x14 gLanguageInfo[0xD] = {
    { "English (UK)", &.L_8036DFA5, &.L_8036DFAD, .L_8036DFB0, 0 },
    { &.L_8036DFC9, &.L_8036DFD6, &.L_8036DFAD, .L_8036DFDF, 0 },
    { &.L_8036DFF9, &.L_8036E002, &.L_8036E009, .L_8036E00C, 0 },
    { &.L_8036E024, &.L_8036E02C, &.L_8036E034, .L_8036E037, 0 },
    { &.L_8036E050, &.L_8036E058, &.L_8036E05F, .L_8036E062, 0 },
    { &.L_8036E07A, &.L_8036E083, &.L_8036E08B, .L_8036E08E, 0 },
    { &.L_8036E0A7, &.L_8036E0B2, &.L_8036E0B8, .L_8036E0BB, 0 },
    { &.L_8036E0D2, &.L_8036E0D2, &.L_8036E0DB, .L_8036E0DE, 0 },
    { &.L_8036E0F8, &.L_8036E0FE, &.L_8036E105, .L_8036E108, 0 },
    { &.L_8036E120, &.L_8036E128, &.L_8036E130, .L_8036E133, 0 },
    { &.L_8036E14C, &.L_8036E152, &.L_8036E15C, .L_8036E15F, 0 },
    { &.L_8036E17A, &.L_8036E180, &.L_8036E188, .L_8036E18B, 0 },
    { &.L_8036E1A4, &.L_8036E1A4, &.L_8036E1AC, .L_8036E1AF, 0 },
};
#endif
static s32 gpLanguageOptionStrings[0xE];
static M2C_UNK gLanguageOptionLanguages;
static s32 gCurrentLanguage = -1;
#if 0 // DRAFT: declaration syntax error
static M2C_UNK .L_8036DFA5;                         /* unable to generate initializer: unknown type; const */
static M2C_UNK .L_8036DFAD;                         /* unable to generate initializer: unknown type; const */
static s8 .L_8036DFB0[0x19] = {
    0x54,
    0x72,
    0x61,
    0x6E,
    0x73,
    0x6C,
    0x61,
    0x74,
    0x69,
    0x6F,
    0x6E,
    0x73,
    0x2E,
    0x45,
    0x6E,
    0x67,
    0x6C,
    0x69,
    0x73,
    0x68,
    0x2E,
    0x74,
    0x78,
    0x74,
    0,
}; /* const */
static M2C_UNK .L_8036DFC9;                         /* unable to generate initializer: unknown type; const */
static M2C_UNK .L_8036DFD6;                         /* unable to generate initializer: unknown type; const */
static s8 .L_8036DFDF[0x1A] = {
    0x54,
    0x72,
    0x61,
    0x6E,
    0x73,
    0x6C,
    0x61,
    0x74,
    0x69,
    0x6F,
    0x6E,
    0x73,
    0x2E,
    0x41,
    0x6D,
    0x65,
    0x72,
    0x69,
    0x63,
    0x61,
    0x6E,
    0x2E,
    0x74,
    0x78,
    0x74,
    0,
}; /* const */
static M2C_UNK .L_8036DFF9;                         /* unable to generate initializer: unknown type; const */
static M2C_UNK .L_8036E002;                         /* unable to generate initializer: unknown type; const */
static M2C_UNK .L_8036E009;                         /* unable to generate initializer: unknown type; const */
static s8 .L_8036E00C[0x18] = {
    0x54,
    0x72,
    0x61,
    0x6E,
    0x73,
    0x6C,
    0x61,
    0x74,
    0x69,
    0x6F,
    0x6E,
    0x73,
    0x2E,
    0x46,
    0x72,
    0x65,
    0x6E,
    0x63,
    0x68,
    0x2E,
    0x74,
    0x78,
    0x74,
    0,
}; /* const */
static M2C_UNK .L_8036E024;                         /* unable to generate initializer: unknown type; const */
static M2C_UNK .L_8036E02C;                         /* unable to generate initializer: unknown type; const */
static M2C_UNK .L_8036E034;                         /* unable to generate initializer: unknown type; const */
static s8 .L_8036E037[0x19] = {
    0x54,
    0x72,
    0x61,
    0x6E,
    0x73,
    0x6C,
    0x61,
    0x74,
    0x69,
    0x6F,
    0x6E,
    0x73,
    0x2E,
    0x53,
    0x70,
    0x61,
    0x6E,
    0x69,
    0x73,
    0x68,
    0x2E,
    0x74,
    0x78,
    0x74,
    0,
}; /* const */
static M2C_UNK .L_8036E050;                         /* unable to generate initializer: unknown type; const */
static M2C_UNK .L_8036E058;                         /* unable to generate initializer: unknown type; const */
static M2C_UNK .L_8036E05F;                         /* unable to generate initializer: unknown type; const */
static s8 .L_8036E062[0x18] = {
    0x54,
    0x72,
    0x61,
    0x6E,
    0x73,
    0x6C,
    0x61,
    0x74,
    0x69,
    0x6F,
    0x6E,
    0x73,
    0x2E,
    0x47,
    0x65,
    0x72,
    0x6D,
    0x61,
    0x6E,
    0x2E,
    0x74,
    0x78,
    0x74,
    0,
}; /* const */
static M2C_UNK .L_8036E07A;                         /* unable to generate initializer: unknown type; const */
static M2C_UNK .L_8036E083;                         /* unable to generate initializer: unknown type; const */
static M2C_UNK .L_8036E08B;                         /* unable to generate initializer: unknown type; const */
static s8 .L_8036E08E[0x19] = {
    0x54,
    0x72,
    0x61,
    0x6E,
    0x73,
    0x6C,
    0x61,
    0x74,
    0x69,
    0x6F,
    0x6E,
    0x73,
    0x2E,
    0x49,
    0x74,
    0x61,
    0x6C,
    0x69,
    0x61,
    0x6E,
    0x2E,
    0x74,
    0x78,
    0x74,
    0,
}; /* const */
static M2C_UNK .L_8036E0A7;                         /* unable to generate initializer: unknown type; const */
static M2C_UNK .L_8036E0B2;                         /* unable to generate initializer: unknown type; const */
static M2C_UNK .L_8036E0B8;                         /* unable to generate initializer: unknown type; const */
static s8 .L_8036E0BB[0x17] = {
    0x54,
    0x72,
    0x61,
    0x6E,
    0x73,
    0x6C,
    0x61,
    0x74,
    0x69,
    0x6F,
    0x6E,
    0x73,
    0x2E,
    0x44,
    0x75,
    0x74,
    0x63,
    0x68,
    0x2E,
    0x74,
    0x78,
    0x74,
    0,
}; /* const */
static M2C_UNK .L_8036E0D2;                         /* unable to generate initializer: unknown type; const */
static M2C_UNK .L_8036E0DB;                         /* unable to generate initializer: unknown type; const */
static s8 .L_8036E0DE[0x1A] = {
    0x54,
    0x72,
    0x61,
    0x6E,
    0x73,
    0x6C,
    0x61,
    0x74,
    0x69,
    0x6F,
    0x6E,
    0x73,
    0x2E,
    0x4A,
    0x61,
    0x70,
    0x61,
    0x6E,
    0x65,
    0x73,
    0x65,
    0x2E,
    0x74,
    0x78,
    0x74,
    0,
}; /* const */
static M2C_UNK .L_8036E0F8;                         /* unable to generate initializer: unknown type; const */
static M2C_UNK .L_8036E0FE;                         /* unable to generate initializer: unknown type; const */
static M2C_UNK .L_8036E105;                         /* unable to generate initializer: unknown type; const */
static s8 .L_8036E108[0x18] = {
    0x54,
    0x72,
    0x61,
    0x6E,
    0x73,
    0x6C,
    0x61,
    0x74,
    0x69,
    0x6F,
    0x6E,
    0x73,
    0x2E,
    0x44,
    0x61,
    0x6E,
    0x69,
    0x73,
    0x68,
    0x2E,
    0x74,
    0x78,
    0x74,
    0,
}; /* const */
static M2C_UNK .L_8036E120;                         /* unable to generate initializer: unknown type; const */
static M2C_UNK .L_8036E128;                         /* unable to generate initializer: unknown type; const */
static M2C_UNK .L_8036E130;                         /* unable to generate initializer: unknown type; const */
static s8 .L_8036E133[0x19] = {
    0x54,
    0x72,
    0x61,
    0x6E,
    0x73,
    0x6C,
    0x61,
    0x74,
    0x69,
    0x6F,
    0x6E,
    0x73,
    0x2E,
    0x53,
    0x77,
    0x65,
    0x64,
    0x69,
    0x73,
    0x68,
    0x2E,
    0x74,
    0x78,
    0x74,
    0,
}; /* const */
static M2C_UNK .L_8036E14C;                         /* unable to generate initializer: unknown type; const */
static M2C_UNK .L_8036E152;                         /* unable to generate initializer: unknown type; const */
static M2C_UNK .L_8036E15C;                         /* unable to generate initializer: unknown type; const */
static s8 .L_8036E15F[0x1B] = {
    0x54,
    0x72,
    0x61,
    0x6E,
    0x73,
    0x6C,
    0x61,
    0x74,
    0x69,
    0x6F,
    0x6E,
    0x73,
    0x2E,
    0x4E,
    0x6F,
    0x72,
    0x77,
    0x65,
    0x67,
    0x69,
    0x61,
    0x6E,
    0x2E,
    0x74,
    0x78,
    0x74,
    0,
}; /* const */
static M2C_UNK .L_8036E17A;                         /* unable to generate initializer: unknown type; const */
static M2C_UNK .L_8036E180;                         /* unable to generate initializer: unknown type; const */
static M2C_UNK .L_8036E188;                         /* unable to generate initializer: unknown type; const */
static s8 .L_8036E18B[0x19] = {
    0x54,
    0x72,
    0x61,
    0x6E,
    0x73,
    0x6C,
    0x61,
    0x74,
    0x69,
    0x6F,
    0x6E,
    0x73,
    0x2E,
    0x46,
    0x69,
    0x6E,
    0x6E,
    0x69,
    0x73,
    0x68,
    0x2E,
    0x74,
    0x78,
    0x74,
    0,
}; /* const */
static M2C_UNK .L_8036E1A4;                         /* unable to generate initializer: unknown type; const */
static M2C_UNK .L_8036E1AC;                         /* unable to generate initializer: unknown type; const */
static s8 .L_8036E1AF[0x3A] = {
    0x54,
    0x72,
    0x61,
    0x6E,
    0x73,
    0x6C,
    0x61,
    0x74,
    0x69,
    0x6F,
    0x6E,
    0x73,
    0x2E,
    0x52,
    0x75,
    0x73,
    0x73,
    0x69,
    0x61,
    0x6E,
    0x2E,
    0x74,
    0x78,
    0x74,
    0,
    0x5B,
    0x5D,
    0,
    0x5B,
    0x50,
    0x53,
    0x32,
    0x5D,
    0,
    0x5B,
    0x47,
    0x43,
    0x4E,
    0x5D,
    0,
    0x5B,
    0x58,
    0x42,
    0x4F,
    0x58,
    0x5D,
    0,
    0x5B,
    0x50,
    0x43,
    0x5D,
    0,
    0x5B,
    0x50,
    0x53,
    0x50,
    0x5D,
    0,
}; /* const */

void Translation_GetLanguageCode(TranslationLanguage arg0) {

}
#endif

void Translation_GetLanguageLocalName(TranslationLanguage arg0) {

}

void Translation_GetLanguageName(TranslationLanguage arg0) {

}

#if 0 // DRAFT: undefined identifier 'gLanguageInfo'
u8 Translation_IsLanguageAvailable(TranslationLanguage arg0) {
    return gLanguageInfo[(s32) arg0].unk10 != 0;
}
#endif

#if 0 // DRAFT: undefined identifier 'gLanguageInfo'
void Translation_SetLanguage(TranslationLanguage arg0) {
    s32 temp_r0_285;
    s32 temp_r0_293;
    s32 temp_r3_242;
    s32 var_r30_65;
    s32 var_r3_340;
    s32 var_r5_337;
    s32 var_r6_79;
    s8 *temp_r3_144;
    struct _struct_gLanguageInfo_0x14 *temp_r3_78;
    u8 *temp_r3_238;
    u8 *var_r28_98;
    u8 *var_r6_308;
    u8 temp_r0_103;
    u8 temp_r0_269;
    u8 temp_r0_313;
    u8 temp_r3_118;
    u8 temp_r3_224;
    u8 temp_r3_300;
    void *temp_r4_249;

    var_r30_65 = 0;
    gCurrentLanguage = (s32) arg0;
    gNmbrOfStrings = 0;
    MKArchive_Load(gLanguageInfo[(s32) arg0].unkC, NULL, gpTranslationBuffer, -1);
    temp_r3_78 = &gLanguageInfo[(s32) arg0];
    var_r6_79 = 0;
    gpTranslationBuffer[temp_r3_78->unk10] = 0;
loop_4:
    if (var_r6_79 < (s32) temp_r3_78->unk10) {
        if ((s8) gpTranslationBuffer[var_r6_79] == 0xD) {
            gpTranslationBuffer[var_r6_79] = 0xA;
        }
        var_r6_79 += 1;
        goto loop_4;
    }
    var_r28_98 = gpTranslationBuffer;
    do {
loop_7:
        temp_r0_103 = *var_r28_98;
        if ((s8) temp_r0_103 == 0x20) {
            var_r28_98 += 1;
            goto loop_7;
        }
        if ((s8) temp_r0_103 == 0xA) {
            var_r28_98 += 1;
        } else if ((s8) temp_r0_103 == 0x23) {
loop_13:
            temp_r3_118 = *var_r28_98;
            if ((s8) temp_r3_118 != 0) {
                if ((s8) temp_r3_118 == 0xA) {

                } else {
                    var_r28_98 += 1;
                    goto loop_13;
                }
            }
        } else {
            *(gpEnumTagArray + (gNmbrOfStrings * 4)) = var_r28_98;
loop_18:
            if ((s8) *var_r28_98 > 0x20) {
                var_r28_98 += 1;
                goto loop_18;
            }
            *var_r28_98 = 0;
            var_r28_98 += 1;
            temp_r3_144 = *(gpEnumTagArray + (gNmbrOfStrings * 4));
            if ((s32) *temp_r3_144 == 0x5B) {
                if (strcmpi"[]" == 0) {
                    var_r30_65 = 0;
                } else if (strcmpi(*(gpEnumTagArray + (gNmbrOfStrings * 4)), "[PS2]", gpEnumTagArray) == 0) {
                    var_r30_65 = 1;
                } else if (strcmpi(*(gpEnumTagArray + (gNmbrOfStrings * 4)), "[GCN]", gpEnumTagArray) == 0) {
                    var_r30_65 = 2;
                } else if (strcmpi(*(gpEnumTagArray + (gNmbrOfStrings * 4)), "[XBOX]", gpEnumTagArray) == 0) {
                    var_r30_65 = 3;
                } else if (strcmpi(*(gpEnumTagArray + (gNmbrOfStrings * 4)), "[PC]", gpEnumTagArray) == 0) {
                    var_r30_65 = 4;
                } else if (strcmpi(*(gpEnumTagArray + (gNmbrOfStrings * 4)), "[PSP]", gpEnumTagArray) == 0) {
                    var_r30_65 = 5;
                }
loop_33:
                temp_r3_224 = *var_r28_98;
                if ((s8) temp_r3_224 != 0) {
                    if ((s8) temp_r3_224 == 0xA) {

                    } else {
                        var_r28_98 += 1;
                        goto loop_33;
                    }
                }
            } else if ((var_r30_65 == 0) || (var_r30_65 == 2)) {
                temp_r3_238 = Str_FindChar(temp_r3_144, 0x3D);
                if (temp_r3_238 != NULL) {
                    temp_r3_242 = atoi(temp_r3_238 + 1);
loop_41:
                    if (temp_r3_242 > (s32) gNmbrOfStrings) {
                        temp_r4_249 = gpEnumTagArray + (gNmbrOfStrings * 4);
                        M2C_FIELD(temp_r4_249, s32 *, 4) = (s32) M2C_FIELD(temp_r4_249, s32 *, 0);
                        *(gpEnumTagArray + (gNmbrOfStrings * 4)) = &gNullStr;
                        gNmbrOfStrings += 1;
                        goto loop_41;
                    }
                    *temp_r3_238 = 0;
                }
loop_44:
                temp_r0_269 = *var_r28_98;
                if ((s8) temp_r0_269 == 0x20) {
block_43:
                    var_r28_98 += 1;
                    goto loop_44;
                }
                if ((s8) temp_r0_269 == 9) {
                    goto block_43;
                }
                if (((s8) temp_r0_269 == 0) || ((s8) temp_r0_269 == 0xA)) {
                    temp_r0_285 = gNmbrOfStrings * 4;
                    gNmbrOfStrings += 1;
                    gpTranslation_StringArray[temp_r0_285] = &gNullStr;
                } else {
                    temp_r0_293 = gNmbrOfStrings * 4;
                    gNmbrOfStrings += 1;
                    gpTranslation_StringArray[temp_r0_293] = var_r28_98;
loop_51:
                    temp_r3_300 = *var_r28_98;
                    if (((s8) temp_r3_300 != 0) && ((s8) temp_r3_300 != 0xA)) {
                        var_r28_98 += 1;
                        goto loop_51;
                    }
                    var_r6_308 = var_r28_98 - 1;
                    *var_r28_98 = 0;
                    var_r28_98 += 1;
loop_57:
                    if (var_r6_308 >= (u32) (*(gpTranslation_StringArray + ((gNmbrOfStrings * 4) - 4)) - 1)) {
                        temp_r0_313 = *var_r6_308;
                        if (((s8) temp_r0_313 == 0x20) || ((s8) temp_r0_313 == 9)) {
                            *var_r6_308 = 0;
                            var_r6_308 -= 1;
                            goto loop_57;
                        }
                    }
                }
            }
        }
    } while (var_r28_98 < &gpTranslationBuffer[temp_r3_78->unk10]);
    var_r5_337 = 0;
    gLanguageDebugOption = 0;
    var_r3_340 = 0;
loop_61:
    if ((s32) gCurrentLanguage != (s32) *(&gLanguageOptionLanguages + var_r3_340)) {
        var_r5_337 += 1;
        var_r3_340 += 4;
        goto loop_61;
    }
    gLanguageDebugOption = var_r5_337;
}
#endif

s32 Translation_GetDefaultLanguage() {
    s32 var_r31_366;
    u8 temp_r3_367;

    var_r31_366 = 0;
    temp_r3_367 = OSGetLanguage();
    switch ((s32) temp_r3_367) {                    /* irregular */
    case 0:
        var_r31_366 = 0;
        break;
    case 1:
        var_r31_366 = 4;
        break;
    case 2:
        var_r31_366 = 2;
        break;
    case 3:
        var_r31_366 = 3;
        break;
    case 4:
        var_r31_366 = 5;
        break;
    case 5:
        var_r31_366 = 6;
        break;
    }
    if ((var_r31_366 == 0) || (Translation_IsLanguageAvailable((TranslationLanguage) var_r31_366) == 0)) {
        if (((s32) gDisplay == 1) && (Translation_IsLanguageAvailable((TranslationLanguage) 1) != 0)) {
            var_r31_366 = 1;
        } else {
            var_r31_366 = 0;
        }
    }
    return var_r31_366;
}

s32 Translation_GetLanguage() {
    return gCurrentLanguage;
}

#if 0 // DRAFT: pointer/array required
void Translation_DeinitModule() {
    MKHeap *temp_r3_444;
    MKHeap *temp_r3_462;
    MKHeap *temp_r3_478;
    u8 *temp_r31_443;
    u8 *temp_r31_460;
    u8 *temp_r31_476;

    temp_r31_443 = gpTranslationBuffer;
    temp_r3_444 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_444 != NULL) {
        ((MKHeap *) (temp_r3_444->Current()))->Free(temp_r31_443, NULL, 0);
    } else {
        free(temp_r31_443);
    }
    gpTranslationBuffer = NULL;
    temp_r31_460 = gpEnumTagArray;
    gCurrentLanguage = -1;
    temp_r3_462 = NULL->Current();
    if (temp_r3_462 != NULL) {
        ((MKHeap *) (temp_r3_462->Current()))->Free(temp_r31_460, NULL, 0);
    } else {
        free(temp_r31_460);
    }
    temp_r31_476 = gpTranslation_StringArray;
    gpEnumTagArray = NULL;
    temp_r3_478 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_478 != NULL) {
        ((MKHeap *) (temp_r3_478->Current()))->Free(temp_r31_476, NULL, 0);
    } else {
        free(temp_r31_476);
    }
    gpTranslation_StringArray = NULL;
}
#endif

#if 0 // DRAFT: illegal operand
void Translation_InitModule() {
    MKHeap *temp_r3_512;
    MKHeap *temp_r3_534;
    MKHeap *temp_r3_594;
    s32 temp_r29_511;
    s32 temp_r29_533;
    s32 temp_r5_571;
    s32 var_r25_556;
    s32 var_r26_558;
    s32 var_r29_559;
    s32 var_r30_557;
    s32 var_r31_554;
    u8 *var_r3_519;
    u8 *var_r3_541;
    u8 *var_r3_601;
    void *temp_r27_561;

    temp_r29_511 = (M2C_FIELD(&gMKDefaults, MKHeap **, 0x20) + 1) * 4;
    temp_r3_512 = ((MKHeap *) (M2C_FIELD(&gMKDefaults, MKHeap **, 0x20)))->Current();
    if (temp_r3_512 != NULL) {
        var_r3_519 = ((MKHeap *) (temp_r3_512->Current()))->Alloc(temp_r29_511, NULL, 0);
    } else {
        var_r3_519 = malloc(temp_r29_511);
    }
    gpTranslation_StringArray = var_r3_519;
    memset(var_r3_519, 0, (s32) (M2C_FIELD(&gMKDefaults, MKHeap **, 0x20) + 1) * 4);
    temp_r29_533 = (s32) (M2C_FIELD(&gMKDefaults, MKHeap **, 0x20) + 1) * 4;
    temp_r3_534 = ((MKHeap *) (M2C_FIELD(&gMKDefaults, MKHeap **, 0x20)))->Current();
    if (temp_r3_534 != NULL) {
        var_r3_541 = ((MKHeap *) (temp_r3_534->Current()))->Alloc(temp_r29_533, NULL, 0);
    } else {
        var_r3_541 = malloc(temp_r29_533);
    }
    gpEnumTagArray = var_r3_541;
    memset(var_r3_541, 0, (s32) (M2C_FIELD(&gMKDefaults, MKHeap **, 0x20) + 1) * 4);
    var_r31_554 = 0;
    var_r25_556 = 0;
    var_r30_557 = 0;
    var_r26_558 = 0;
    var_r29_559 = 0;
    do {
        temp_r27_561 = gLanguageInfo + var_r29_559;
        if (MKArchive_Exists(M2C_FIELD(temp_r27_561, s8 **, 0xC), temp_r27_561 + 0x10) == 0) {
            M2C_FIELD(temp_r27_561, s32 *, 0x10) = 0;
        } else {
            temp_r5_571 = M2C_FIELD(temp_r27_561, s32 *, 0x10);
            *(gpLanguageOptionStrings + var_r30_557) = M2C_FIELD(temp_r27_561, s32 *, 4);
            var_r25_556 += 1;
            *(&gLanguageOptionLanguages + var_r30_557) = var_r26_558;
            var_r30_557 += 4;
            if (temp_r5_571 > var_r31_554) {
                var_r31_554 = temp_r5_571;
            }
        }
        var_r26_558 += 1;
        var_r29_559 += 0x14;
    } while (var_r26_558 < 0xD);
    gpLanguageOptionStrings[var_r25_556] = 0;
    temp_r3_594 = gpLanguageOptionStrings->Current();
    if (temp_r3_594 != NULL) {
        var_r3_601 = ((MKHeap *) (temp_r3_594->Current()))->Alloc(var_r31_554 + 1, NULL, 0);
    } else {
        var_r3_601 = malloc(var_r31_554 + 1);
    }
    gpTranslationBuffer = var_r3_601;
    gNmbrOfStrings = 0;
    gCurrentLanguage = -1;
}
#endif
