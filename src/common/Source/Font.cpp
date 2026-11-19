#include "common/Source/Font.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKFont.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "common/Source/Texture.h"
#include "spyro/source/Level.h"
#include "unplaced_enums.h"
#include "common/Source/FileSys.h"
#include "common/Source/MKMat_MK2_Standard.h"
#include "common/Source/MKView.h"
#include "common/Source/Str.h"
#include "common/Source/system_extras.h"
#include "common/gc/MKMaterial_GC.h"
#include <m2c_macros.h>

f64 atof(s8 *, s32, s32, M2C_UNK, s32);             /* extern */
s32 atoi(s8 *, s8 *, s8 *);                         /* extern */
M2C_UNK free(M2C_UNK *);                            /* extern */
TextCharStrip **malloc(s32);                        /* extern */
s32 stricmp(s32, MKFont *);                         /* extern */
s32 strnicmp(s8 *, s32, s32);                       /* extern */
#if 0 // DRAFT: identifier 'drawStringChars' redeclared was declared as: 'MKHeap *' now declared as: 'TextCharStrip **'
extern TextCharStrip **drawStringChars;
#endif
extern M2C_UNK gEmptyPtrListDL;
extern M2C_UNK gMKDefaults;
extern M2C_UNK gRenderState;
extern TextCharStrip **pDrawStringList;
extern s8 *pWorkingText;
u8 pEndToken__6MKFont[4];                           /* unable to generate initializer: cannot parse "/FONT" as integer */
u8 pStartToken__6MKFont[4];                         /* unable to generate initializer: cannot parse .L_8036DA2E as integer */
u8 pColourToken__6MKFont[4];                        /* unable to generate initializer: cannot parse .L_8036DA34 as integer */
u8 pEndColourToken__6MKFont[4];                     /* unable to generate initializer: cannot parse .L_8036DA3B as integer */
u8 pPageToken__6MKFont[4];                          /* unable to generate initializer: cannot parse .L_8036DA43 as integer */
static GeometryTransformationInfo transformInfo_723 = { 1, 0 };

f32 *MKFont::GetFontColour(int arg0) {
    s32 temp_r0_22;
    s32 var_r3_12;
    u32 var_ctr_14;
    void *temp_r5_18;

    var_r3_12 = 0;
    var_ctr_14 = *MKFont::currentColour;
    if ((u32) *MKFont::currentColour > 0U) {
loop_1:
        temp_r5_18 = (void *) (*MKFont::fontColours + var_r3_12);
        if (((s32) M2C_FIELD(temp_r5_18, s32 *, 0x10) <= arg0) && ((temp_r0_22 = M2C_FIELD(temp_r5_18, s32 *, 0x14), ((temp_r0_22 > arg0) != 0)) || (temp_r0_22 == -1))) {
            return (float *) (*MKFont::fontColours + var_r3_12);
        }
        var_r3_12 += 0x18;
        var_ctr_14 -= 1;
        if (var_ctr_14 == 0U) {
            /* Duplicate return node #6. Try simplifying control flow for better match */
            return NULL;
        }
        goto loop_1;
    }
    return NULL;
}

extern "C" s32 strnicmp(s8 *, const char *, s32);
extern "C" f64 atof(s8 *);
void MKFont::ParseFontColours(char *arg0) {
    s8 *base = (s8 *) arg0;
    s8 *var_r31_48;
    s8 *var_r31_59;
    s8 *var_r31_80;
    s32 temp_r7_89;
    s32 temp_r4_98;
    s32 temp_r6_153;
    s32 var_r3_155;
    s32 var_ctr_156;
    s32 temp_r4_159;
    s32 temp_r6_196;
    s32 temp_r3_199;
    u8 temp_r0;

    var_r31_48 = base;
    *(s32 *) MKFont::currentColour = 0;
loop_30:
    if ((s8) (u8) *var_r31_48 != 0) {
        if (IsToken(arg0, (u32) (var_r31_48 - base)) != 0) {
            var_r31_59 = var_r31_48 + 1;
            if (strnicmp(var_r31_59, *(char **) MKFont::pColourToken, *(s32 *) MKFont::colourTokenLen) == 0) {
loop_5:
                if ((s32) (u8) *var_r31_59 == 0x20) {
                    var_r31_59 += 1;
                    goto loop_5;
                }
loop_8:
                if ((s32) (u8) *var_r31_59 != 0x3D) {
                    var_r31_59 += 1;
                    goto loop_8;
                }
                var_r31_80 = var_r31_59 + 1;
loop_11:
                if ((s32) (u8) *var_r31_80 == 0x20) {
                    var_r31_80 += 1;
                    goto loop_11;
                }
                temp_r7_89 = (s32) (var_r31_48 - base);
                *(s32 *) (*(s8 **) MKFont::fontColours + (*(s32 *) MKFont::currentColour * 0x18 + 0x10)) = temp_r7_89;
                temp_r4_98 = *(s32 *) MKFont::currentColour * 0x18;
                *(s32 *) (*(s8 **) MKFont::fontColours + (temp_r4_98 + 0x14)) = -1;
                *(f32 *) (*(s8 **) MKFont::fontColours + (*(s32 *) MKFont::currentColour * 0x18)) = (f32) atof(var_r31_80);
                do {
                    temp_r0 = (u8) *var_r31_80;
                    var_r31_80 += 1;
                } while ((s32) temp_r0 != 0x2C);
                *(f32 *) (*(s8 **) MKFont::fontColours + (*(s32 *) MKFont::currentColour * 0x18 + 4)) = (f32) atof(var_r31_80);
                do {
                    temp_r0 = (u8) *var_r31_80;
                    var_r31_80 += 1;
                } while ((s32) temp_r0 != 0x2C);
                *(f32 *) (*(s8 **) MKFont::fontColours + (*(s32 *) MKFont::currentColour * 0x18 + 8)) = (f32) atof(var_r31_80);
                do {
                    temp_r0 = (u8) *var_r31_80;
                    var_r31_80 += 1;
                } while ((s32) temp_r0 != 0x2C);
                *(f32 *) (*(s8 **) MKFont::fontColours + (*(s32 *) MKFont::currentColour * 0x18 + 0xC)) = (f32) atof(var_r31_80);
                do {
                    temp_r0 = (u8) *var_r31_80;
                    var_r31_80 += 1;
                } while ((s32) temp_r0 != 0x3E);
                temp_r6_153 = *(s32 *) MKFont::currentFont - 1;
                var_r3_155 = temp_r6_153 * 0x18;
                var_ctr_156 = temp_r6_153 + 1;
                if (temp_r6_153 >= 0) {
loop_21:
                    temp_r4_159 = var_r3_155 + 0x14;
                    if (*(s32 *) (*(s8 **) MKFont::fontColours + temp_r4_159) == -1) {
                        *(s32 *) (*(s8 **) MKFont::fontColours + temp_r4_159) = *(s32 *) (*(s8 **) MKFont::fontColours + (*(s32 *) MKFont::currentColour * 0x18 + 0x10)) - 1;
                    } else {
                        var_r3_155 -= 0x18;
                        var_ctr_156 -= 1;
                        if (var_ctr_156 != 0) {
                            goto loop_21;
                        }
                    }
                }
                strcpy((char *) var_r31_48, (const char *) var_r31_80);
            } else if (strnicmp(var_r31_59, *(char **) MKFont::pEndColourToken, *(s32 *) MKFont::endColourTokenLen) == 0) {
                do {
                    temp_r0 = (u8) *var_r31_59;
                    var_r31_59 += 1;
                } while ((s32) temp_r0 != 0x3E);
                strcpy((char *) var_r31_48, (const char *) var_r31_59);
                temp_r6_196 = (s32) (var_r31_48 - base);
                temp_r3_199 = *(s32 *) MKFont::currentColour * 0x18;
                *(s32 *) MKFont::currentColour += 1;
                *(s32 *) (*(s8 **) MKFont::fontColours + (temp_r3_199 + 0x14)) = temp_r6_196;
            } else {
                var_r31_48 = var_r31_59 + 1;
            }
        } else {
            var_r31_48 += 1;
        }
        goto loop_30;
    }
}

extern "C" s32 atoi(s8 *);
s32 MKFont::ScanForToken(const char *arg0, unsigned int arg1) {
    s8 spB[0x20];
    s8 spA[2];
    s8 *temp_r5_230;
    s8 *temp_r30_284;
    s8 *temp_r4_267;
    s8 *var_r3_296;
    s8 *var_r3_306;
    s8 *temp_r5_445;
    s8 *temp_r4_448;
    s8 *temp_r7_364;
    s8 *temp_r8_368;
    s8 *temp_r3_395;
    s8 *temp_r3_504;
    s8 *temp_r7_473;
    s8 *temp_r8_477;
    u8 temp_r3_234;
    s32 temp_r0_255;
    s32 temp_r7_257;
    s32 temp_r3_258;
    s32 temp_r31_293;
    s32 var_r31_295;
    s32 var_r30_305;
    s32 temp_r28_333;
    s32 var_r4_349;
    s32 var_r0_369;
    s32 temp_r5_360;
    s32 temp_r9_361;
    s32 var_r3_363;
    s32 var_ctr_365;
    s32 temp_r5_432;
    s32 temp_r4_439;
    s32 var_r4_458;
    s32 temp_r5_469;
    s32 temp_r9_470;
    s32 var_r3_472;
    s32 var_ctr_474;
    s32 var_r0_478;
    s32 temp_r3_515;

    temp_r5_230 = (s8 *) arg0 + arg1;
    if ((s32) (u8) *temp_r5_230 == 0x3C) {
        temp_r3_234 = (u8) temp_r5_230[1];
        if (((s8) temp_r3_234 != 0) && ((s8) temp_r3_234 != 0x3C) && ((arg1 == 0) || ((s32) (u8) temp_r5_230[-1] != 0x3C))) {
            if (strnicmp(temp_r5_230 + 1, *(char **) MKFont::pEndToken, *(s32 *) MKFont::endTokenLen) == 0) {
                temp_r0_255 = *(s32 *) MKFont::currentFont + 1;
                temp_r7_257 = temp_r0_255 * 0x14;
                temp_r3_258 = *(s32 *) MKFont::endTokenLen + 2;
                *(s32 *) MKFont::currentFont = temp_r0_255;
                *(s32 *) (*(s8 **) MKFont::currentFontStack + temp_r7_257) = *(s32 *) (*(s8 **) MKFont::currentFontStack + temp_r7_257 - 0x28);
                temp_r4_267 = *(s8 **) MKFont::currentFontStack + *(s32 *) MKFont::currentFont * 0x14;
                *(s32 *) (temp_r4_267 + 4) = *(s32 *) (temp_r4_267 - 0x24);
                *(s32 *) (*(s8 **) MKFont::currentFontStack + *(s32 *) MKFont::currentFont * 0x14 - 8) = (s32) (arg1 - 1);
                *(s32 *) (*(s8 **) MKFont::currentFontStack + *(s32 *) MKFont::currentFont * 0x14 + 8) = (s32) (arg1 + temp_r3_258);
                return temp_r3_258;
            }
            temp_r30_284 = temp_r5_230 + 1;
            if (strnicmp(temp_r30_284, *(char **) MKFont::pStartToken, *(s32 *) MKFont::startTokenLen) == 0) {
                temp_r31_293 = arg1 + *(s32 *) MKFont::startTokenLen;
                *(s32 *) MKFont::currentFont += 1;
                var_r31_295 = temp_r31_293 + 1;
                var_r3_296 = (s8 *) arg0 + var_r31_295;
loop_10:
                if ((s32) (u8) *var_r3_296 != 0x3A) {
                    var_r31_295 += 1;
                    var_r3_296 += 1;
                    goto loop_10;
                }
                var_r30_305 = var_r31_295 + 1;
                var_r3_306 = (s8 *) arg0 + var_r30_305;
loop_13:
                if ((s32) (u8) *var_r3_306 != 0x3E) {
                    var_r30_305 += 1;
                    var_r3_306 += 1;
                    goto loop_13;
                }
                strncpy((char *) (spB + 1), (const char *) ((s8 *) arg0 + (arg1 + *(s32 *) MKFont::startTokenLen + 1)), (u32) (((var_r31_295 - *(s32 *) MKFont::startTokenLen) - arg1) - 1));
                spB[(var_r31_295 - *(s32 *) MKFont::startTokenLen) - arg1] = 0;
                temp_r28_333 = var_r30_305 - var_r31_295;
                *(void **) (*(s8 **) MKFont::currentFontStack + *(s32 *) MKFont::currentFont * 0x14) = ((MKFont *) (spB + 1))->Find((const char *) spB);
                strncpy((char *) (spB + 1), (const char *) ((s8 *) arg0 + var_r31_295 + 1), (u32) (temp_r28_333 - 1));
                spB[temp_r28_333] = 0;
                var_r4_349 = 0;
                *(s32 *) (*(s8 **) MKFont::currentFontStack + *(s32 *) MKFont::currentFont * 0x14 + 4) = atoi(spB + 1);
                *(s32 *) (*(s8 **) MKFont::currentFontStack + *(s32 *) MKFont::currentFont * 0x14 + 0x10) = -1;
                temp_r5_360 = *(s32 *) MKFont::currentFont - 1;
                temp_r9_361 = *(s32 *) MKFont::currentFont * 0x14;
                var_r3_363 = temp_r5_360 * 0x14;
                temp_r7_364 = *(s8 **) MKFont::currentFontStack + temp_r9_361;
                var_ctr_365 = temp_r5_360 + 1;
                if (temp_r5_360 >= 0) {
loop_15:
                    temp_r8_368 = *(s8 **) MKFont::currentFontStack + var_r3_363;
                    var_r0_369 = *(s32 *) (temp_r8_368 + 0x10);
                    if (var_r4_349 > var_r0_369) {
                        var_r0_369 = var_r4_349;
                    }
                    var_r4_349 = var_r0_369;
                    if ((*(u32 *) temp_r8_368 == *(u32 *) temp_r7_364) && (*(u32 *) (temp_r8_368 + 4) == *(u32 *) (temp_r7_364 + 4))) {
                        *(s32 *) (temp_r7_364 + 0x10) = *(s32 *) (*(s8 **) MKFont::currentFontStack + var_r3_363 + 0x10);
                    } else {
                        var_r3_363 -= 0x14;
                        var_ctr_365 -= 1;
                        if (var_ctr_365 != 0) {
                            goto loop_15;
                        }
                    }
                }
                temp_r3_395 = *(s8 **) MKFont::currentFontStack + *(s32 *) MKFont::currentFont * 0x14;
                if (*(s32 *) (temp_r3_395 + 0x10) == -1) {
                    *(s32 *) (temp_r3_395 + 0x10) = var_r4_349 + 1;
                }
                *(s32 *) (*(s8 **) MKFont::currentFontStack + *(s32 *) MKFont::currentFont * 0x14 - 8) = (s32) (arg1 != 0 ? arg1 - 1 : 0);
                *(s32 *) (*(s8 **) MKFont::currentFontStack + *(s32 *) MKFont::currentFont * 0x14 + 8) = var_r30_305 + 1;
                return (var_r30_305 - arg1) + 1;
            }
            if (strnicmp(temp_r30_284, *(char **) MKFont::pPageToken, *(s32 *) MKFont::pageTokenLen) == 0) {
                if (arg1 != 0) {
                    temp_r5_432 = *(s32 *) MKFont::currentFont + 1;
                    *(s32 *) MKFont::currentFont = temp_r5_432;
                    *(s32 *) (*(s8 **) MKFont::currentFontStack + temp_r5_432 * 0x14 - 8) = (s32) (arg1 - 1);
                    temp_r4_439 = *(s32 *) MKFont::currentFont * 0x14;
                    *(s32 *) (*(s8 **) MKFont::currentFontStack + temp_r4_439) = *(s32 *) (*(s8 **) MKFont::currentFontStack + temp_r4_439 - 0x14);
                }
                temp_r5_445 = temp_r5_230;
                temp_r4_448 = temp_r5_445 + *(s32 *) MKFont::pageTokenLen;
                spA[1] = 0;
                spA[0] = temp_r4_448[1];
                var_r4_458 = -1;
                *(s32 *) (*(s8 **) MKFont::currentFontStack + *(s32 *) MKFont::currentFont * 0x14 + 4) = atoi(spA);
                *(s32 *) (*(s8 **) MKFont::currentFontStack + *(s32 *) MKFont::currentFont * 0x14 + 0x10) = -1;
                if (arg1 != 0) {
                    temp_r5_469 = *(s32 *) MKFont::currentFont - 1;
                    temp_r9_470 = *(s32 *) MKFont::currentFont * 0x14;
                    var_r3_472 = temp_r5_469 * 0x14;
                    temp_r7_473 = *(s8 **) MKFont::currentFontStack + temp_r9_470;
                    var_ctr_474 = temp_r5_469 + 1;
                    if (temp_r5_469 >= 0) {
loop_29:
                        temp_r8_477 = *(s8 **) MKFont::currentFontStack + var_r3_472;
                        var_r0_478 = *(s32 *) (temp_r8_477 + 0x10);
                        if (var_r4_458 > var_r0_478) {
                            var_r0_478 = var_r4_458;
                        }
                        var_r4_458 = var_r0_478;
                        if ((*(u32 *) temp_r8_477 == *(u32 *) temp_r7_473) && (*(u32 *) (temp_r8_477 + 4) == *(u32 *) (temp_r7_473 + 4))) {
                            *(s32 *) (temp_r7_473 + 0x10) = *(s32 *) (*(s8 **) MKFont::currentFontStack + var_r3_472 + 0x10);
                        } else {
                            var_r3_472 -= 0x14;
                            var_ctr_474 -= 1;
                            if (var_ctr_474 != 0) {
                                goto loop_29;
                            }
                        }
                    }
                }
                temp_r3_504 = *(s8 **) MKFont::currentFontStack + *(s32 *) MKFont::currentFont * 0x14;
                if (*(s32 *) (temp_r3_504 + 0x10) == -1) {
                    *(s32 *) (temp_r3_504 + 0x10) = var_r4_458 + 1;
                }
                temp_r3_515 = *(s32 *) MKFont::pageTokenLen + 3;
                *(s32 *) (*(s8 **) MKFont::currentFontStack + *(s32 *) MKFont::currentFont * 0x14 + 8) = arg1 + temp_r3_515;
                return temp_r3_515;
            }
            return 1;
        }
    }
    return 1;
}

void MKFont::BuildMaterialList(const char *arg0) {
    u32 temp_r31_548;
    u32 var_r30_543;

    var_r30_543 = 0;
    ResetFontStack(this, 0U);
    temp_r31_548 = strlen(arg0);
loop_2:
    if (var_r30_543 < temp_r31_548) {
        var_r30_543 += ScanForToken(arg0, var_r30_543);
        goto loop_2;
    }
}

void MKFont::ResetFontStack(MKFont *arg0, unsigned int arg1) {
    s32 off = 0;
    u32 i = 0;
    while (i < (u32) M2C_FIELD(&gMKDefaults, u32 *, 0xB0)) {
        M2C_FIELD(*(s8 **) MKFont::currentFontStack + off, s32 *, 0) = 0;
        M2C_FIELD(*(s8 **) MKFont::currentFontStack + off, s32 *, 4) = 0;
        M2C_FIELD(*(s8 **) MKFont::currentFontStack + off, s32 *, 8) = 0;
        M2C_FIELD(*(s8 **) MKFont::currentFontStack + off, s32 *, 0xC) = M2C_FIELD(&gMKDefaults, s32 *, 0xAC);
        M2C_FIELD(*(s8 **) MKFont::currentFontStack + off, s32 *, 0x10) = 0;
        i += 1;
        off += 0x14;
    }
    *(s32 *) MKFont::currentFont = 0;
    if (arg0 != NULL) {
        M2C_FIELD(*(s8 **) MKFont::currentFontStack, MKFont **, 0) = arg0;
        M2C_FIELD(*(s8 **) MKFont::currentFontStack + *(s32 *) MKFont::currentFont * 0x14, s32 *, 4) = 0;
    }
}

CharInfo *MKFont::GetCharacter(const char *arg0, int *arg1, FontPage **arg2) {
    CharInfo *var_r3_703;
    FontPage *temp_r5_684;
    s8 *temp_r4_692;
    s32 temp_cr0_eq_648;
    s32 temp_r7_685;
    s32 var_r3_678;
    s8 *temp_r3_646;
    s8 *temp_r4_656;
    u32 var_ctr_680;
    u8 temp_r3_657;

    if (IsToken(arg0, (u32) *arg1) != 0) {
loop_4:
        temp_r3_646 = (s8 *) (arg0 + *arg1);
        temp_cr0_eq_648 = (s32) M2C_FIELD(temp_r3_646, u8 *, -1) == 0x3E;
        if ((temp_cr0_eq_648 != 0) && ((s32) (u8) M2C_FIELD(temp_r3_646, u8 *, 0) != 0x3C)) {
            goto block_7;
        }
        *arg1 += 1;
        if ((s8) (u8) arg0[*arg1] == 0) {
            return NULL;
        }
        goto loop_4;
    }
block_7:
    temp_r4_656 = (s8 *) (arg0 + *arg1);
    temp_r3_657 = (u8) M2C_FIELD(temp_r4_656, u8 *, 0);
    if ((((s32) temp_r3_657 == 0x3C) && ((s32) M2C_FIELD(temp_r4_656, u8 *, 1) == 0x3C)) || (((s32) (s8) temp_r3_657 == 0x3E) && ((s32) M2C_FIELD(temp_r4_656, u8 *, 1) == 0x3E))) {
        *arg1 += 1;
    }
    var_r3_678 = 0;
    var_ctr_680 = M2C_FIELD(&gMKDefaults, u32 *, 0xB0);
    if (var_ctr_680 > 0U) {
loop_13:
        temp_r5_684 = (FontPage *) (*(s8 **) MKFont::currentFontStack + var_r3_678);
        temp_r7_685 = *arg1;
        if (((u32) temp_r5_684->unk8 <= (u32) temp_r7_685) && ((u32) temp_r5_684->unkC >= (u32) temp_r7_685)) {
            temp_r4_692 = (s8 *) temp_r5_684->unk0;
            if (temp_r4_692 != NULL) {
                var_r3_703 = (CharInfo *) (M2C_FIELD(*(s8 **) (*(s8 **) temp_r4_692 + temp_r5_684->unk4 * 4), s32 *, 0x28) + (((u8) arg0[temp_r7_685] << 5) & 0x1FE0));
                if (arg2 != NULL) {
                    *arg2 = temp_r5_684;
                    return var_r3_703;
                }
                return var_r3_703;
            }
        }
        var_r3_678 += 0x14;
        var_ctr_680 -= 1;
        if (var_ctr_680 == 0U) {
            goto block_19;
        }
        goto loop_13;
    }
block_19:
    var_r3_703 = NULL;
    return var_r3_703;
}

u8 MKFont::IsToken(const char *arg0, unsigned int arg1) {
    s8 *temp_r6_728;
    u8 temp_r4_729;

    if ((s8) (u8) arg0[arg1] == 0x3C) {
        temp_r6_728 = (signed char *) (&arg0[arg1]);
        temp_r4_729 = M2C_FIELD(temp_r6_728, u8 *, 1);
        if (((s8) temp_r4_729 != 0) && ((s8) temp_r4_729 != 0x3C) && ((arg1 == 0) || ((s32) M2C_FIELD(temp_r6_728, u8 *, -1) != 0x3C))) {
            return 1U;
        }
    }
    return 0U;
}

f32 MKFont::GetWidthOfCharacter(char arg0, CharInfo *arg1, FontPage *arg2) {
    if ((u8) arg0 > 0x20U) {
        if (arg1->unk1C != 0) {
            return arg1->unk18 + M2C_FIELD(*(s8 **) (*(s8 **) arg2->unk0 + arg2->unk4 * 4), f32 *, 8);
        }
        return M2C_FIELD(*(s8 **) (*(s8 **) arg2->unk0 + arg2->unk4 * 4), f32 *, 0xC);
    }
    return M2C_FIELD(*(s8 **) (*(s8 **) arg2->unk0 + arg2->unk4 * 4), f32 *, 0xC);
}

f32 MKFont::DrawString2dWrapped(const char *arg0, float arg1, float arg2, float arg3, float arg4, float arg5, int arg6, unsigned int arg7) {
    Matrix sp10;
    M2C_UNK spC;
    f32 temp_f31_840;

    M2C_STRUCT_COPY((s32) &spC + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
    sp10.unk30 = arg1;
    sp10.unk34 = arg2;
    sp10.unk38 = 0.0f;
    sp10.unk3C = 1.0f;
    MKView_Push();
    MKView_SetCameraMatrix(Matrix::identity);
    MKView_SetOrtho(NULL);
    temp_f31_840 = DrawString(arg0, arg3, arg4, &sp10, arg6, arg7, arg5, arg5, NULL, 1U);
    MKView_Pop();
    return temp_f31_840;
}

void *MKFont::GetCharacterFontPage(unsigned int arg0) {
    s32 var_r5_863;
    u32 var_ctr_865;
    void *temp_r3_869;

    var_r5_863 = 0;
    var_ctr_865 = M2C_FIELD(&gMKDefaults, u32 *, 0xB0);
    if ((u32) M2C_FIELD(&gMKDefaults, u32 *, 0xB0) > 0U) {
loop_1:
        temp_r3_869 = (void *) (*MKFont::currentFontStack + var_r5_863);
        if (((u32) M2C_FIELD(temp_r3_869, u32 *, 8) > arg0) || ((u32) M2C_FIELD(temp_r3_869, u32 *, 0xC) < arg0)) {
            var_r5_863 += 0x14;
            var_ctr_865 -= 1;
            if (var_ctr_865 == 0U) {
                /* Duplicate return node #4. Try simplifying control flow for better match */
                return NULL;
            }
            goto loop_1;
        }
        return temp_r3_869;
    }
    return NULL;
}

#if 0 // DRAFT: identifier 'arg9' redeclared
f32 MKFont::DrawString(const char *arg0, float arg1, float arg2, Matrix *arg3, int arg4, unsigned int arg5, float arg6, float arg7, void (*arg9)(TextCharStrip **, int, const Matrix &), bool arg9) {
    TextLineData sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 sp8;
    MKMaterial *temp_r18_1315;
    f32 *var_r3_1164;
    f32 temp_f29_1000;
    f32 temp_f2_1182;
    f32 temp_f31_1098;
    f32 temp_f3_1179;
    f32 var_f26_1054;
    f32 var_f27_999;
    f32 var_f28_1033;
    f32 var_f30_976;
    s32 temp_r23_937;
    s32 temp_r7_1267;
    s32 var_ctr_1064;
    s32 var_r19_1281;
    s32 var_r20_1022;
    s32 var_r20_1250;
    s32 var_r26_968;
    s32 var_r27_1023;
    s32 var_r3_1263;
    s32 var_r3_1282;
    s32 var_r4_1283;
    s32 var_r6_1055;
    s8 *temp_r3_1108;
    s8 *temp_r4_1102;
    s8 *temp_r5_1029;
    s8 *var_r19_1099;
    s8 *var_r3_1063;
    u32 temp_r4_1030;
    u32 var_ctr_1284;
    u32 var_r17_1248;
    u32 var_r21_967;
    u32 var_r8_1261;
    u8 temp_r0_1111;
    u8 temp_r17_1139;
    u8 temp_r3_1122;
    void *temp_r17_1159;
    void *temp_r18_1151;
    void *temp_r18_1254;
    void *temp_r22_1028;
    void *temp_r25_1142;
    void *temp_r3_1141;
    void *temp_r4_1149;
    void *temp_r6_1291;
    void *temp_r7_1290;

    if ((s8) (u8) *arg0 == 0) {
        return 0.0f;
    }
    temp_r23_937 = M2C_FIELD(&gRenderState, s32 *, 4);
    M2C_FIELD(&gRenderState, s32 *, 4) = 0;
    sp10 = 0.0078125f * (f32) (u8) arg5;
    sp14 = 0.0078125f * (f32) (u8) (arg5 >> 8U);
    sp18 = 0.0078125f * (f32) (u8) (arg5 >> 0x10U);
    sp1C = 0.0078125f * (f32) (arg5 >> 0x18U);
    strcpy(pWorkingText, arg0);
    ParseFontColours(pWorkingText);
    BuildMaterialList(pWorkingText);
    var_r21_967 = 0U;
    var_r26_968 = 0;
    MKView_GetProjection(NULL, &sp8, NULL);
    if (sp8 != 0.0f) {
        var_f30_976 = -1.0f;
    } else {
        var_f30_976 = 1.0f;
    }
    BuildLines(pWorkingText, arg1, arg2, &sp20, arg6, arg7, arg9);
    var_f27_999 = 0.5f * -arg2 * var_f30_976;
    temp_f29_1000 = var_f30_976 * (arg7 * (sp20.unk16C * GetHeight()));
    if (arg4 < 8) {
        if (arg4 < 4) {

        } else {
            var_f27_999 += var_f30_976 * (0.5f * (arg2 - sp20.unk170));
        }
    } else if (arg4 < 0xC) {
        var_f27_999 += var_f30_976 * (arg2 - sp20.unk170);
    }
    var_r20_1022 = 0;
    var_r27_1023 = 0;
loop_51:
    if (var_r20_1022 < sp20.unk168) {
        temp_r22_1028 = &sp20 + var_r27_1023;
        temp_r5_1029 = M2C_FIELD(temp_r22_1028, s8 **, 0);
        temp_r4_1030 = M2C_FIELD(temp_r22_1028, u32 *, 4);
        if (temp_r5_1029 != temp_r4_1030) {
            var_f28_1033 = 0.5f * -arg1;
            if ((u32) arg4 <= 0xAU) {
                switch (arg4) {
                case 1:
                case 5:
                case 9:
                    var_f28_1033 += 0.5f * (arg1 - M2C_FIELD(temp_r22_1028, f32 *, 8));
                    break;
                case 2:
                case 6:
                case 10:
                    var_f28_1033 += arg1 - M2C_FIELD(temp_r22_1028, f32 *, 8);
                    break;
                }
            }
            var_f26_1054 = 0.0f;
            var_r6_1055 = 0;
            if ((arg4 == 7) || (arg4 == 3) || (arg4 == 0xB)) {
                var_r3_1063 = temp_r5_1029;
                var_ctr_1064 = temp_r4_1030 - temp_r5_1029;
                if (temp_r5_1029 < temp_r4_1030) {
                    do {
                        if ((s32) *var_r3_1063 == 0x20) {
                            var_r6_1055 += 1;
                        }
                        var_r3_1063 += 1;
                        var_ctr_1064 -= 1;
                    } while (var_ctr_1064 != 0);
                }
                var_f26_1054 = (arg1 - -(((f32) var_r6_1055 * (arg6 * (M2C_FIELD(**this, f32 *, 0xC) * sp20.unk16C))) - M2C_FIELD(temp_r22_1028, f32 *, 8))) / (f32) var_r6_1055;
            }
            temp_f31_1098 = var_f27_999 + temp_f29_1000;
            var_r19_1099 = temp_r5_1029;
loop_49:
            if (var_r19_1099 < (u32) M2C_FIELD(temp_r22_1028, u32 *, 4)) {
                temp_r4_1102 = M2C_FIELD(temp_r22_1028, s8 **, 0);
                if (IsToken(temp_r4_1102, var_r19_1099 - temp_r4_1102) != 0) {
                    temp_r3_1108 = var_r19_1099;
loop_31:
                    if ((s32) (u8) M2C_FIELD(var_r19_1099, s8 *, 0) == 0x3E) {

                    } else {
                        temp_r0_1111 = M2C_FIELD(var_r19_1099, u8 *, 1);
                        var_r19_1099 += 1;
                        if (temp_r0_1111 == 0) {
                            var_r19_1099 = temp_r3_1108;
                        } else {
                            goto loop_31;
                        }
                    }
                } else {
                    temp_r3_1122 = (u8) M2C_FIELD(var_r19_1099, s8 *, 0);
                    if ((((s32) temp_r3_1122 == 0x3C) && ((s32) M2C_FIELD(var_r19_1099, u8 *, 1) == 0x3C)) || (((s32) temp_r3_1122 == 0x3E) && ((s32) M2C_FIELD(var_r19_1099, u8 *, 1) == 0x3E))) {
                        var_r19_1099 += 1;
                    }
                    temp_r17_1139 = (u8) *var_r19_1099;
                    temp_r3_1141 = GetCharacterFontPage(var_r19_1099 - (s32) sp20);
                    temp_r25_1142 = temp_r3_1141;
                    temp_r4_1149 = *(*M2C_FIELD(temp_r3_1141, s32 **, 0) + (M2C_FIELD(temp_r3_1141, s32 *, 4) * 4));
                    temp_r18_1151 = (void *) (M2C_FIELD(temp_r4_1149, s32 *, 0x28) + ((temp_r17_1139 << 5) & 0x1FE0));
                    if ((temp_r17_1139 > 0x20U) && ((s32) M2C_FIELD(temp_r18_1151, s32 *, 0x1C) != 0)) {
                        var_r21_967 += 1;
                        temp_r17_1159 = drawStringChars + var_r26_968;
                        var_r26_968 += 0x78;
                        M2C_FIELD(temp_r17_1159, void **, 0x60) = temp_r25_1142;
                        var_r3_1164 = GetFontColour(var_r19_1099 - pWorkingText);
                        if (var_r3_1164 == NULL) {
                            var_r3_1164 = &sp10;
                        }
                        M2C_FIELD(temp_r17_1159, f64 *, 0x68) = (f64) M2C_FIELD(var_r3_1164, f64 *, 0);
                        M2C_FIELD(temp_r17_1159, f64 *, 0x70) = (f64) M2C_FIELD(var_r3_1164, f64 *, 8);
                        M2C_FIELD(temp_r17_1159, f32 *, 0) = var_f28_1033;
                        M2C_FIELD(temp_r17_1159, f32 *, 4) = var_f27_999;
                        temp_f3_1179 = arg6 * (M2C_FIELD(temp_r18_1151, f32 *, 0x18) * sp20.unk16C);
                        M2C_FIELD(temp_r17_1159, f32 *, 8) = 0.0f;
                        temp_f2_1182 = var_f28_1033 + temp_f3_1179;
                        M2C_FIELD(temp_r17_1159, f32 *, 0x10) = (f32) M2C_FIELD(temp_r18_1151, f32 *, 8);
                        M2C_FIELD(temp_r17_1159, f32 *, 0x14) = (f32) M2C_FIELD(temp_r18_1151, f32 *, 0xC);
                        M2C_FIELD(temp_r17_1159, f32 *, 0x18) = temp_f2_1182;
                        M2C_FIELD(temp_r17_1159, f32 *, 0x1C) = var_f27_999;
                        M2C_FIELD(temp_r17_1159, f32 *, 0x20) = 0.0f;
                        M2C_FIELD(temp_r17_1159, f32 *, 0x28) = (f32) M2C_FIELD(temp_r18_1151, f32 *, 0x10);
                        M2C_FIELD(temp_r17_1159, f32 *, 0x2C) = (f32) M2C_FIELD(temp_r18_1151, f32 *, 0xC);
                        M2C_FIELD(temp_r17_1159, f32 *, 0x30) = var_f28_1033;
                        M2C_FIELD(temp_r17_1159, f32 *, 0x34) = temp_f31_1098;
                        M2C_FIELD(temp_r17_1159, f32 *, 0x38) = 0.0f;
                        M2C_FIELD(temp_r17_1159, f32 *, 0x40) = (f32) M2C_FIELD(temp_r18_1151, f32 *, 8);
                        M2C_FIELD(temp_r17_1159, f32 *, 0x44) = (f32) M2C_FIELD(temp_r18_1151, f32 *, 0x14);
                        M2C_FIELD(temp_r17_1159, f32 *, 0x48) = temp_f2_1182;
                        M2C_FIELD(temp_r17_1159, f32 *, 0x4C) = temp_f31_1098;
                        M2C_FIELD(temp_r17_1159, f32 *, 0x50) = 0.0f;
                        M2C_FIELD(temp_r17_1159, f32 *, 0x58) = (f32) M2C_FIELD(temp_r18_1151, f32 *, 0x10);
                        M2C_FIELD(temp_r17_1159, f32 *, 0x5C) = (f32) M2C_FIELD(temp_r18_1151, f32 *, 0x14);
                        var_f28_1033 += (arg6 * (sp20.unk16C * M2C_FIELD(*(*M2C_FIELD(temp_r25_1142, s32 **, 0) + (M2C_FIELD(temp_r25_1142, s32 *, 4) * 4)), f32 *, 8))) + temp_f3_1179;
                    } else if ((arg4 == 7) || (arg4 == 3) || (arg4 == 0xB)) {
                        var_f28_1033 += var_f26_1054;
                    } else {
                        var_f28_1033 += arg6 * (sp20.unk16C * M2C_FIELD(temp_r4_1149, f32 *, 0xC));
                    }
                }
                var_r19_1099 += 1;
                goto loop_49;
            }
        }
        var_f27_999 += temp_f29_1000;
        var_r20_1022 += 1;
        var_r27_1023 += 0xC;
        goto loop_51;
    }
    var_r17_1248 = 0U;
    var_r20_1250 = 0;
loop_75:
    if (var_r17_1248 < (u32) M2C_FIELD(&gMKDefaults, u32 *, 0xB0)) {
        temp_r18_1254 = (void *) (*MKFont::currentFontStack + var_r20_1250);
        if (((void *) M2C_FIELD(temp_r18_1254, void **, 0) != NULL) && ((s32) M2C_FIELD(temp_r18_1254, s32 *, 0x10) != -1)) {
            var_r8_1261 = var_r17_1248 + 1;
            var_r3_1263 = var_r8_1261 * 0x14;
loop_59:
            if (var_r8_1261 < (u32) M2C_FIELD(&gMKDefaults, u32 *, 0xB0)) {
                temp_r7_1267 = var_r3_1263 + 0x10;
                if ((s32) *(var_r20_1250 + (*MKFont::currentFontStack + 0x10)) == (s32) *(*MKFont::currentFontStack + temp_r7_1267)) {
                    *(*MKFont::currentFontStack + temp_r7_1267) = -1;
                }
                var_r8_1261 += 1;
                var_r3_1263 += 0x14;
                goto loop_59;
            }
            var_r19_1281 = 0;
            var_r3_1282 = 0;
            var_r4_1283 = 0;
            var_ctr_1284 = var_r21_967;
            if (var_r21_967 > 0U) {
                do {
                    temp_r7_1290 = drawStringChars + var_r4_1283;
                    temp_r6_1291 = M2C_FIELD(temp_r7_1290, void **, 0x60);
                    if (((u32) M2C_FIELD(temp_r6_1291, u32 *, 0) == (void *) M2C_FIELD(temp_r18_1254, void **, 0)) && ((u32) M2C_FIELD(temp_r18_1254, u32 *, 4) == (u32) M2C_FIELD(temp_r6_1291, u32 *, 4))) {
                        var_r19_1281 += 1;
                        *(pDrawStringList + var_r3_1282) = (TextCharStrip *) (temp_r7_1290);
                        var_r3_1282 += 4;
                    }
                    var_r4_1283 += 0x78;
                    var_ctr_1284 -= 1;
                } while (var_ctr_1284 != 0U);
            }
            MKMaterial_SetGeometryTransformInfo(&transformInfo_723);
            temp_r18_1315 = *(M2C_FIELD(M2C_FIELD(temp_r18_1254, void **, 0), s32 *, 4) + (M2C_FIELD(temp_r18_1254, u32 *, 4) * 4));
            MKMaterial_SetLocalToWorld(arg3, 1.0f);
            MKMaterial_SetMaterial(temp_r18_1315);
            MKMaterial_SetGeometryColor(MKVector4::one);
loop_72:
            if (MKMaterial_Begin() != 0) {
loop_71:
                if (MKMaterial_BeginInternal() != 0) {
                    if (var_r19_1281 != 0) {
                        if (arg8 != NULL) {
                            arg8(pDrawStringList, var_r19_1281, arg3);
                        } else {
                            RenderChars(pDrawStringList, var_r19_1281, *arg3);
                        }
                    }
                    goto loop_71;
                }
                goto loop_72;
            }
            MKMaterial_SetLocalToWorld(NULL, 1.0f);
        }
        var_r17_1248 += 1;
        var_r20_1250 += 0x14;
        goto loop_75;
    }
    M2C_FIELD(&gRenderState, s32 *, 4) = temp_r23_937;
    return sp20.unk170;
}
#endif

#if 0 // DRAFT: function call 'strcpy(signed char *, signed char *)' does not match 'strcpy(char *, const char *)'
void MKFont::BuildLines(const char *arg0, float arg1, float arg2, TextLineData *arg3, float arg4, float arg5, bool arg6) {
    FontPage *spC;
    s32 sp8;
    CharInfo *var_r22_1478;
    f32 var_f22_1472;
    f32 var_f24_1466;
    f32 var_f25_1462;
    f32 var_f27_1453;
    s32 var_r17_1463;
    s32 var_r24_1475;
    s32 var_r25_1474;
    s32 var_r26_1471;
    s32 var_r27_1461;
    s8 *var_r22_1421;
    s8 *var_r23_1477;
    s8 *var_r29_1459;
    u8 temp_r0_1427;
    u8 temp_r0_1450;
    u8 temp_r0_1611;
    u8 temp_r4_1491;
    u8 temp_r4_1572;
    u8 var_r28_1455;
    void *temp_r30_1467;

    var_r22_1421 = (signed char *) (arg0);
loop_8:
    temp_r0_1450 = (u8) M2C_FIELD(var_r22_1421, s8 *, 0);
    if (temp_r0_1450 != 0) {
        if ((s32) temp_r0_1450 == 0x5C) {
            temp_r0_1427 = M2C_FIELD(var_r22_1421, u8 *, 1);
            if ((s32) temp_r0_1427 == 0x6E) {
                M2C_FIELD(var_r22_1421, s8 *, 0) = 0xA;
                var_r22_1421 += 1;
                strcpy(var_r22_1421, var_r22_1421 + 1);
            } else if ((s32) temp_r0_1427 == 0x5C) {
                var_r22_1421 += 1;
                strcpy(var_r22_1421, var_r22_1421 + 1);
            } else {
                var_r22_1421 += 1;
            }
        } else {
            var_r22_1421 += 1;
        }
        goto loop_8;
    }
    var_f27_1453 = 1.0f;
    var_r28_1455 = 1;
loop_52:
    if (var_r28_1455 != 0) {
        var_r29_1459 = (signed char *) (arg0);
        var_r28_1455 = 0;
        var_r27_1461 = 0;
        var_f25_1462 = 0.0f;
        var_r17_1463 = 0;
loop_49:
        if ((u8) *var_r29_1459 != 0) {
            var_f24_1466 = 0.0f;
            temp_r30_1467 = arg3 + var_r17_1463;
            M2C_FIELD(temp_r30_1467, s8 **, 0) = var_r29_1459;
            var_r26_1471 = 0;
            var_f22_1472 = 0.0f;
            spC = NULL;
            var_r25_1474 = 1;
            var_r24_1475 = 0;
            sp8 = 0;
            var_r23_1477 = NULL;
            var_r22_1478 = NULL;
loop_24:
            if ((var_f24_1466 <= arg1) || (arg1 == 0.0f)) {
                sp8 = var_r29_1459 - arg0;
                var_r22_1478 = GetCharacter(arg0, (int *) &sp8, &spC);
                var_r29_1459 = (signed char *) (&arg0[sp8]);
                temp_r4_1491 = (u8) *var_r29_1459;
                if ((temp_r4_1491 <= 0x20U) || ((s32) var_r22_1478->unk1C == 0)) {
                    if ((temp_r4_1491 == 0) || ((s32) temp_r4_1491 == 0xA)) {
                        if ((s32) temp_r4_1491 == 0xA) {
                            var_r24_1475 = 1;
                        }
                        var_f22_1472 = var_f24_1466;
                        var_r23_1477 = var_r29_1459;
                    } else {
                        if (var_r26_1471 != 0) {
                            var_f22_1472 = var_f24_1466;
                            var_r23_1477 = var_r29_1459;
                            var_r26_1471 = 0;
                        }
                        var_f24_1466 += arg4 * (var_f27_1453 * GetWidthOfCharacter((s8) temp_r4_1491, var_r22_1478, spC));
                        goto block_23;
                    }
                } else {
                    var_r26_1471 = 1;
                    var_r25_1474 = 0;
                    var_f24_1466 += arg4 * (var_f27_1453 * GetWidthOfCharacter((s8) temp_r4_1491, var_r22_1478, spC));
block_23:
                    var_r29_1459 += 1;
                    goto loop_24;
                }
            }
            if (var_r25_1474 != 0) {
                M2C_FIELD(temp_r30_1467, s8 **, 4) = (s8 *) M2C_FIELD(temp_r30_1467, s8 **, 0);
                M2C_FIELD(temp_r30_1467, f32 *, 8) = 0.0f;
                goto block_38;
            }
            if (var_r23_1477 == NULL) {
loop_31:
                temp_r4_1572 = (u8) *var_r29_1459;
                if ((temp_r4_1572 > 0x20U) && ((s32) var_r22_1478->unk1C != 0)) {
                    GetWidthOfCharacter((s8) temp_r4_1572, var_r22_1478, spC);
                    var_r29_1459 += 1;
                    goto loop_31;
                }
                if (arg6 != 0) {
                    var_r28_1455 = 1;
                    var_f27_1453 *= 0.9f;
                } else if (var_f25_1462 > arg2) {
                    var_r28_1455 = 0;
                }
            } else {
                M2C_FIELD(temp_r30_1467, s8 **, 4) = var_r23_1477;
                M2C_FIELD(temp_r30_1467, f32 *, 8) = var_f22_1472;
block_38:
                var_r29_1459 = var_r23_1477;
                if (var_r24_1475 != 0) {
                    var_r29_1459 = var_r23_1477 + 1;
                } else {
loop_42:
                    temp_r0_1611 = (u8) *var_r29_1459;
                    if ((temp_r0_1611 != 0) && (temp_r0_1611 <= 0x20U)) {
                        GetWidthOfCharacter((s8) temp_r0_1611, var_r22_1478, spC);
                        var_r29_1459 += 1;
                        goto loop_42;
                    }
                }
                var_r27_1461 += 1;
                var_r17_1463 += 0xC;
                var_f25_1462 += arg5 * (var_f27_1453 * GetHeight());
                if (arg6 != 0) {
                    if (var_f25_1462 > arg2) {
                        var_r28_1455 = 1;
                        var_f27_1453 *= 0.9f;
                    } else {
                        goto loop_49;
                    }
                } else if (var_f25_1462 > arg2) {
                    var_r28_1455 = 0;
                } else {
                    goto loop_49;
                }
            }
        }
        if (var_r28_1455 == 0) {
            arg3->unk16C = var_f27_1453;
            arg3->unk168 = var_r27_1461;
            arg3->unk170 = var_f25_1462;
        }
        goto loop_52;
    }
}
#endif

void MKFont::RenderChars(TextCharStrip **arg0, int arg1, const Matrix &arg2) {
    s32 var_r24_1713;
    s32 var_r26_1700;
    s32 var_r30_1714;
    s32 var_r31_1701;
    void *temp_r23_1716;
    void *temp_r25_1704;

    MKMaterial_GetVertexComponentHandleFromType((VERTEX_COMPONENT) 1);
    MKMaterial_GetVertexComponentHandleFromType((VERTEX_COMPONENT) 3);
    MKMaterial_GetVertexComponentHandleFromType((VERTEX_COMPONENT) 0);
    MKMaterial_RenderImmediateBegin(4U, 0U);
    var_r26_1700 = 0;
    var_r31_1701 = 0;
loop_4:
    if (var_r26_1700 < arg1) {
        temp_r25_1704 = *(arg0 + var_r31_1701);
        MKMaterial_RenderVerticesBegin(4);
        MKMaterial_SetVertex4F(M2C_ERROR(/* Read from unset register $r3 */), M2C_FIELD(temp_r25_1704, f32 *, 0x68), M2C_FIELD(temp_r25_1704, f32 *, 0x6C), M2C_FIELD(temp_r25_1704, f32 *, 0x70), M2C_FIELD(temp_r25_1704, f32 *, 0x74));
        var_r24_1713 = 0;
        var_r30_1714 = 0;
        do {
            temp_r23_1716 = ((u8 *) temp_r25_1704) + var_r30_1714;
            MKMaterial_SetVertex4F(M2C_ERROR(/* Read from unset register $r3 */), M2C_FIELD(temp_r23_1716, f32 *, 0x10), M2C_FIELD(temp_r23_1716, f32 *, 0x14), 0.0f, 1.0f);
            MKMaterial_SetVertex4F(M2C_ERROR(/* Read from unset register $r3 */), M2C_FIELD(temp_r23_1716, f32 *, 0), M2C_FIELD(temp_r23_1716, f32 *, 4), M2C_FIELD(temp_r23_1716, f32 *, 8), 1.0f);
            var_r24_1713 += 1;
            var_r30_1714 += 0x18;
        } while (var_r24_1713 < 4);
        MKMaterial_RenderVerticesEnd();
        var_r26_1700 += 1;
        var_r31_1701 += 4;
        goto loop_4;
    }
    MKMaterial_RenderImmediateEnd();
}

void MKFont::DeinitModule() {
    M2C_UNK *temp_r0_1787;
    M2C_UNK *temp_r0_1806;
    M2C_UNK *temp_r31_1754;
    M2C_UNK *temp_r31_1768;
    M2C_UNK *var_r31_1783;
    M2C_UNK *var_r3_1784;
    M2C_UNK *var_r4_1782;
    u32 temp_r0_1792;

    temp_r31_1754 = (long *) (*MKFont::fontColours);
    if (MKHeap::Current() != NULL) {
        ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_1754, NULL, 0);
    } else {
        free(temp_r31_1754);
    }
    temp_r31_1768 = (long *) (*MKFont::currentFontStack);
    if (MKHeap::Current() != NULL) {
        ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_1768, NULL, 0);
    } else {
        free(temp_r31_1768);
    }
    var_r4_1782 = (long *) (*MKFont::fontList);
    var_r31_1783 = var_r4_1782;
    var_r3_1784 = var_r4_1782;
loop_9:
    temp_r0_1792 = M2C_FIELD(var_r3_1784, u32 *, -4);
    var_r3_1784 -= 4;
    if (temp_r0_1792 != 0U) {
        temp_r0_1787 = (long *) (*var_r3_1784);
        if (temp_r0_1787 < var_r31_1783) {
            var_r31_1783 = temp_r0_1787;
        }
        goto loop_9;
    }
    if (var_r3_1784 != &gEmptyPtrListDL) {
loop_15:
        temp_r0_1806 = (long *) (*var_r4_1782);
        if (temp_r0_1806 != NULL) {
            if (temp_r0_1806 < var_r31_1783) {
                var_r31_1783 = temp_r0_1806;
            }
            var_r4_1782 += 4;
            goto loop_15;
        }
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(var_r31_1783, NULL, 0);
        } else {
            free(var_r31_1783);
        }
    }
    *MKFont::fontList = NULL;
    *MKFont::bInitialised = 0;
}

void MKFont::InitModule() {
    TextCharStrip **temp_r4_1920;
    TextCharStrip **var_r3_1850;
    TextCharStrip **var_r3_1866;
    TextCharStrip **var_r3_1881;
    TextCharStrip **var_r3_1908;
    TextCharStrip **var_r3_1953;
    TextCharStrip **var_r3_1971;
    s32 temp_r30_1842;
    s32 temp_r30_1858;
    s32 temp_r30_1873;
    s32 temp_r30_1890;
    s32 temp_r30_1945;
    s32 temp_r30_1963;
    s32 var_ctr_1923;

    temp_r30_1842 = M2C_FIELD(&gMKDefaults, s32 *, 0xAC) * 0x78;
    if (MKHeap::Current() != NULL) {
        var_r3_1850 = (TextCharStrip **) (((MKHeap *) (MKHeap::Current()))->Alloc(temp_r30_1842, NULL, 0));
    } else {
        var_r3_1850 = malloc(temp_r30_1842);
    }
    drawStringChars = (MKHeap *) (var_r3_1850);
    temp_r30_1858 = M2C_FIELD(&gMKDefaults, s32 *, 0xAC) * 4;
    if (MKHeap::Current() != NULL) {
        var_r3_1866 = (TextCharStrip **) (((MKHeap *) (MKHeap::Current()))->Alloc(temp_r30_1858, NULL, 0));
    } else {
        var_r3_1866 = malloc(temp_r30_1858);
    }
    pDrawStringList = var_r3_1866;
    temp_r30_1873 = M2C_FIELD(&gMKDefaults, s32 *, 0xAC);
    if (MKHeap::Current() != NULL) {
        var_r3_1881 = (TextCharStrip **) (((MKHeap *) (MKHeap::Current()))->Alloc(temp_r30_1873, NULL, 0));
    } else {
        var_r3_1881 = malloc(temp_r30_1873);
    }
    pWorkingText = (s8 *) var_r3_1881;
    temp_r30_1890 = M2C_FIELD(&gMKDefaults, s32 *, 0xB8);
    if (temp_r30_1890 == 0) {
        *MKFont::fontList = (unsigned char) (&gEmptyPtrListDL + 4);
    } else {
        if (MKHeap::Current() != NULL) {
            var_r3_1908 = (TextCharStrip **) (((MKHeap *) (MKHeap::Current()))->Alloc(((temp_r30_1890 + 2) * 4) + (temp_r30_1890 * 0x30), NULL, 0));
        } else {
            var_r3_1908 = malloc(((temp_r30_1890 + 2) * 4) + (temp_r30_1890 * 0x30));
        }
        *MKFont::fontList = (unsigned char) (var_r3_1908);
        temp_r4_1920 = var_r3_1908 + (temp_r30_1890 * 0x30);
        *MKFont::fontList = (unsigned char) (temp_r4_1920);
        *temp_r4_1920 = NULL;
        var_ctr_1923 = temp_r30_1890;
        if (temp_r30_1890 > 0) {
            do {
                *MKFont::fontList += 4;
                M2C_FIELD(*MKFont::fontList, TextCharStrip ***, 4) = var_r3_1908;
                var_r3_1908 += 0x30;
                var_ctr_1923 -= 1;
            } while (var_ctr_1923 != 0);
        }
        *MKFont::fontList += 4;
        M2C_FIELD(*MKFont::fontList, TextCharStrip ***, 4) = NULL;
    }
    *MKFont::bInitialised = 1;
    temp_r30_1945 = M2C_FIELD(&gMKDefaults, s32 *, 0xB0) * 0x14;
    if (MKHeap::Current() != NULL) {
        var_r3_1953 = (TextCharStrip **) (((MKHeap *) (MKHeap::Current()))->Alloc(temp_r30_1945, NULL, 0));
    } else {
        var_r3_1953 = malloc(temp_r30_1945);
    }
    *MKFont::currentFontStack = (unsigned char) (var_r3_1953);
    temp_r30_1963 = M2C_FIELD(&gMKDefaults, s32 *, 0xB4) * 0x18;
    if (MKHeap::Current() != NULL) {
        var_r3_1971 = (TextCharStrip **) (((MKHeap *) (MKHeap::Current()))->Alloc(temp_r30_1963, NULL, 0));
    } else {
        var_r3_1971 = malloc(temp_r30_1963);
    }
    *MKFont::fontColours = (unsigned char) (var_r3_1971);
}

f32 MKFont::CalcLength(const char *arg0) {
    s32 spC;
    FontPage *sp8;
    CharInfo *temp_r3_2009;
    f32 var_f31_1994;
    u32 temp_r31_2001;

    var_f31_1994 = 0.0f;
    BuildMaterialList(arg0);
    temp_r31_2001 = strlen(arg0);
    spC = 0;
loop_4:
    if (spC < (s32) temp_r31_2001) {
        temp_r3_2009 = GetCharacter(arg0, (int *) &spC, &sp8);
        if (temp_r3_2009 != NULL) {
            var_f31_1994 += GetWidthOfCharacter((s8) (u8) arg0[spC], temp_r3_2009, sp8);
        }
        spC += 1;
        goto loop_4;
    }
    return var_f31_1994;
}

f32 MKFont::GetScale(float arg0) {
    return arg0 / GetHeight();
}

f32 MKFont::GetHeight() {
    return M2C_FIELD(*(s8 **) *(s8 **) this, f32 *, 0x24);
}

extern "C" void free(void *);
void MKFont::Destroy() {
    s32 var_r29;
    s32 var_r31;
    s8 *temp_r30;
    void **entry;
    void *temp_r5;
    s32 temp_r0;

    temp_r0 = M2C_FIELD(this, s32 *, 0x2C) - 1;
    M2C_FIELD(this, s32 *, 0x2C) = temp_r0;
    if (temp_r0 == 0) {
        var_r29 = 0;
        var_r31 = 0;
        while (var_r29 < (s32) M2C_FIELD(this, s32 *, 8)) {
            MKMaterial_Destroy(*(MKMaterial **) (M2C_FIELD(this, s8 **, 4) + var_r31));
            temp_r30 = *(s8 **) (M2C_FIELD(this, s8 **, 0) + var_r31);
            if (MKHeap::Current() != NULL) {
                ((MKHeap *) (MKHeap::Current()))->Free(temp_r30, NULL, 0);
            } else {
                free(temp_r30);
            }
            var_r29 += 1;
            var_r31 += 4;
        }
        temp_r30 = M2C_FIELD(this, s8 **, 4);
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(temp_r30, NULL, 0);
        } else {
            free(temp_r30);
        }
        temp_r30 = M2C_FIELD(this, s8 **, 0);
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(temp_r30, NULL, 0);
        } else {
            free(temp_r30);
        }
        entry = *(void ***) MKFont::fontList;
        while (*entry != NULL) {
            if (*entry == (void *) this) {
                void **head = *(void ***) MKFont::fontList;
                *(s8 **) MKFont::fontList = (s8 *) head + 4;
                temp_r5 = *head;
                *head = *entry;
                *entry = temp_r5;
                return;
            }
            entry += 1;
        }
    }
}

extern "C" s32 stricmp(s8 *, const char *);
void *MKFont::Find(const char *arg0) {
    void **entry = *(void ***) MKFont::fontList;
    while (*entry != NULL) {
        if (stricmp((s8 *) *entry + 0xC, (const char *) this) == 0) {
            return *entry;
        }
        entry += 1;
    }
    return NULL;
}

MKFont *MKFont::Create(const char *arg0) {
    s8 *var_r31;
    s8 *temp_r4;
    s8 *temp_r3;
    s8 *temp_r6;
    s8 *temp_r7;
    s8 *temp_ret;
    MKMaterial *temp_r25;
    u32 var_r30;
    u32 var_r26;
    s32 var_r28;

    var_r31 = (s8 *) Find(arg0);
    if (var_r31 != NULL) {
        M2C_FIELD(var_r31, s32 *, 0x2C) = M2C_FIELD(var_r31, s32 *, 0x2C) + 1;
    } else {
        temp_r4 = *(s8 **) MKFont::fontList;
        var_r30 = 0;
        *(s8 **) MKFont::fontList = temp_r4 - 4;
        var_r31 = M2C_FIELD(temp_r4, s8 **, -4);
        while (MKArchive_Exists((const char *) Str_Printf("%s%d%s", this, var_r30, ".fnt"), NULL) != 0) {
            var_r30 += 1;
        }
        if (MKHeap::Current() != NULL) {
            temp_r3 = (s8 *) (((MKHeap *) (MKHeap::Current()))->Alloc(var_r30 * 4, NULL, 0));
        } else {
            temp_r3 = (s8 *) malloc(var_r30 * 4);
        }
        M2C_FIELD(var_r31, s8 **, 4) = temp_r3;
        if (MKHeap::Current() != NULL) {
            temp_r3 = (s8 *) (((MKHeap *) (MKHeap::Current()))->Alloc(var_r30 * 4, NULL, 0));
        } else {
            temp_r3 = (s8 *) malloc(var_r30 * 4);
        }
        M2C_FIELD(var_r31, s8 **, 0) = temp_r3;
        var_r26 = 0U;
        var_r28 = 0;
        while (var_r26 < var_r30) {
            temp_ret = MKArchive_Load((const char *) Str_Printf("%s%d%s", this, var_r26, ".fnt"), NULL, NULL, -1);
            temp_r3 = temp_ret;
            M2C_FIELD(temp_r3, s32 *, 0x28) = (s32) temp_r3 + M2C_FIELD(temp_r3, s32 *, 0x28);
            *(s8 **) (M2C_FIELD(var_r31, s8 **, 0) + var_r28) = temp_r3;
            temp_r6 = M2C_FIELD(var_r31, s8 **, 0);
            temp_r7 = *(s8 **) temp_r6;
            temp_r6 = *(s8 **) (M2C_FIELD(var_r31, s8 **, 0) + var_r28);
            M2C_FIELD(temp_r6, f32 *, 0xC) = M2C_FIELD(temp_r7, f32 *, 0xC);
            temp_r25 = (MKMaterial *) MKMaterial_Create((const char *) Str_Printf("%s%d", this, var_r26));
            MKMaterial_SetParameter(temp_r25, (MKMaterialParameter) 1, 1);
            MKMaterial_SetParameter(temp_r25, (MKMaterialParameter) 2, 1);
            MKMaterial_SetParameter(temp_r25, (MKMaterialParameter) 0, 0);
            MKMat_MK2_SetMaterialType(temp_r25, (MKMat_MK2_Standard_MaterialType) 3);
            var_r26 += 1;
            *(MKMaterial **) (M2C_FIELD(var_r31, s8 **, 4) + var_r28) = temp_r25;
            var_r28 += 4;
        }
        M2C_FIELD(var_r31, s32 *, 0x2C) = 1;
        M2C_FIELD(var_r31, u32 *, 8) = var_r30;
        strcpy((char *) (var_r31 + 0xC), (const char *) this);
    }
    return (MKFont *) var_r31;
}

#if 0 // DRAFT: function call 'strlen(unsigned char)' does not match 'strlen(const char *)'
void Font_cpp::__sinit() {
    *MKFont::endTokenLen = strlen(*MKFont::pEndToken);
    *MKFont::startTokenLen = strlen(*MKFont::pStartToken);
    *MKFont::colourTokenLen = strlen(*MKFont::pColourToken);
    *MKFont::endColourTokenLen = strlen(*MKFont::pEndColourToken);
    *MKFont::pageTokenLen = strlen(*MKFont::pPageToken);
}
#endif
