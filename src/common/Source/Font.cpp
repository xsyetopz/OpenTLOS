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
M2C_UNK free(MKHeap *);                             /* extern */
MKHeap *malloc(s32);                                /* extern */
s32 stricmp(s32, MKFont *);                         /* extern */
s32 strnicmp(s8 *, s32, s32);                       /* extern */
extern MKHeap *drawStringChars;
extern M2C_UNK gEmptyPtrListDL;
extern MKHeap gMKDefaults;
extern M2C_UNK gRenderState;
extern TextCharStrip **pDrawStringList;
extern s8 *pWorkingText;
u8 pEndToken__6MKFont[4];                           /* unable to generate initializer: cannot parse "/FONT" as integer */
u8 pStartToken__6MKFont[4];                         /* unable to generate initializer: cannot parse .L_8036DA2E as integer */
u8 pColourToken__6MKFont[4];                        /* unable to generate initializer: cannot parse .L_8036DA34 as integer */
u8 pEndColourToken__6MKFont[4];                     /* unable to generate initializer: cannot parse .L_8036DA3B as integer */
u8 pPageToken__6MKFont[4];                          /* unable to generate initializer: cannot parse .L_8036DA43 as integer */
static GeometryTransformationInfo transformInfo_723 = { 1, 0 };

#if 0 // DRAFT: illegal implicit conversion from 'long' to
f32 *MKFont::GetFontColour(int arg0) {
    s32 temp_r0_22;
    s32 var_r3_12;
    u32 var_ctr_14;
    void *temp_r5_18;

    var_r3_12 = 0;
    var_ctr_14 = *MKFont::currentColour;
    if ((u32) *MKFont::currentColour > 0U) {
loop_1:
        temp_r5_18 = *MKFont::fontColours + var_r3_12;
        if (((s32) M2C_FIELD(temp_r5_18, s32 *, 0x10) <= arg0) && ((temp_r0_22 = M2C_FIELD(temp_r5_18, s32 *, 0x14), ((temp_r0_22 > arg0) != 0)) || (temp_r0_22 == -1))) {
            return *MKFont::fontColours + var_r3_12;
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
#endif

#if 0 // DRAFT: illegal implicit conversion from 'char *' to
void MKFont::ParseFontColours(char *arg0) {
    s32 temp_r3_199;
    s32 temp_r4_159;
    s32 temp_r4_98;
    s32 temp_r6_153;
    s32 temp_r6_196;
    s32 temp_r7_89;
    s32 var_ctr_156;
    s32 var_r3_155;
    s8 *var_r31_48;
    s8 *var_r31_59;
    s8 *var_r31_80;
    u8 temp_r0_108;
    u8 temp_r0_121;
    u8 temp_r0_134;
    u8 temp_r0_147;
    u8 temp_r0_188;

    var_r31_48 = arg0;
    *MKFont::currentColour = 0;
loop_30:
    if ((s8) (u8) *var_r31_48 != 0) {
        if (IsToken(arg0, var_r31_48 - arg0) != 0) {
            var_r31_59 = var_r31_48 + 1;
            if (strnicmp(var_r31_59, *MKFont::pColourToken, *MKFont::colourTokenLen) == 0) {
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
                temp_r7_89 = var_r31_48 - arg0;
                *(*MKFont::fontColours + ((*MKFont::currentColour * 0x18) + 0x10)) = temp_r7_89;
                temp_r4_98 = *MKFont::currentColour * 0x18;
                *(*MKFont::fontColours + (temp_r4_98 + 0x14)) = -1;
                *(*MKFont::fontColours + (*MKFont::currentColour * 0x18)) = (f32) atof(var_r31_80, temp_r4_98, *MKFont::fontColours, -1, temp_r7_89);
                do {
                    temp_r0_108 = (u8) *var_r31_80;
                    var_r31_80 += 1;
                } while ((s32) temp_r0_108 != 0x2C);
                *(*MKFont::fontColours + ((*MKFont::currentColour * 0x18) + 4)) = (f32) atof(var_r31_80);
                do {
                    temp_r0_121 = (u8) *var_r31_80;
                    var_r31_80 += 1;
                } while ((s32) temp_r0_121 != 0x2C);
                *(*MKFont::fontColours + ((*MKFont::currentColour * 0x18) + 8)) = (f32) atof(var_r31_80);
                do {
                    temp_r0_134 = (u8) *var_r31_80;
                    var_r31_80 += 1;
                } while ((s32) temp_r0_134 != 0x2C);
                *(*MKFont::fontColours + ((*MKFont::currentColour * 0x18) + 0xC)) = (f32) atof(var_r31_80);
                do {
                    temp_r0_147 = (u8) *var_r31_80;
                    var_r31_80 += 1;
                } while ((s32) temp_r0_147 != 0x3E);
                temp_r6_153 = *MKFont::currentFont - 1;
                var_r3_155 = temp_r6_153 * 0x18;
                var_ctr_156 = temp_r6_153 + 1;
                if (temp_r6_153 >= 0) {
loop_21:
                    temp_r4_159 = var_r3_155 + 0x14;
                    if ((s32) *(*MKFont::fontColours + temp_r4_159) == -1) {
                        *(*MKFont::fontColours + temp_r4_159) = *(*MKFont::fontColours + ((*MKFont::currentColour * 0x18) + 0x10)) - 1;
                    } else {
                        var_r3_155 -= 0x18;
                        var_ctr_156 -= 1;
                        if (var_ctr_156 != 0) {
                            goto loop_21;
                        }
                    }
                }
                strcpy(var_r31_48, var_r31_80);
            } else if (strnicmp(var_r31_59, *MKFont::pEndColourToken, *MKFont::endColourTokenLen) == 0) {
                do {
                    temp_r0_188 = (u8) *var_r31_59;
                    var_r31_59 += 1;
                } while ((s32) temp_r0_188 != 0x3E);
                strcpy(var_r31_48, var_r31_59);
                temp_r6_196 = var_r31_48 - arg0;
                temp_r3_199 = *MKFont::currentColour * 0x18;
                *MKFont::currentColour += 1;
                *(*MKFont::fontColours + (temp_r3_199 + 0x14)) = temp_r6_196;
            } else {
                var_r31_48 = var_r31_59 + 1;
            }
        } else {
            var_r31_48 += 1;
        }
        goto loop_30;
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'const char *' to
s32 MKFont::ScanForToken(const char *arg0, unsigned int arg1) {
    s8 spC;
    s8 spB;
    s8 sp9;
    u8 sp8;
    s32 temp_r0_255;
    s32 temp_r28_333;
    s32 temp_r31_293;
    s32 temp_r3_258;
    s32 temp_r3_515;
    s32 temp_r4_439;
    s32 temp_r5_360;
    s32 temp_r5_403;
    s32 temp_r5_432;
    s32 temp_r5_469;
    s32 temp_r7_257;
    s32 temp_r9_361;
    s32 temp_r9_470;
    s32 var_ctr_365;
    s32 var_ctr_474;
    s32 var_r0_369;
    s32 var_r0_478;
    s32 var_r30_305;
    s32 var_r31_295;
    s32 var_r3_363;
    s32 var_r3_472;
    s32 var_r4_349;
    s32 var_r4_458;
    s8 *temp_r30_284;
    s8 *temp_r4_448;
    s8 *temp_r5_230;
    s8 *temp_r5_445;
    u8 *var_r3_296;
    u8 *var_r3_306;
    u8 temp_r3_234;
    void *temp_r3_395;
    void *temp_r3_504;
    void *temp_r4_267;
    void *temp_r7_364;
    void *temp_r7_473;
    void *temp_r8_368;
    void *temp_r8_477;

    temp_r5_230 = &arg0[arg1];
    if ((s32) (u8) M2C_FIELD(temp_r5_230, s8 *, 0) == 0x3C) {
        temp_r3_234 = M2C_FIELD(temp_r5_230, u8 *, 1);
        if (((s8) temp_r3_234 != 0) && ((s8) temp_r3_234 != 0x3C) && ((arg1 == 0) || ((s32) M2C_FIELD(temp_r5_230, u8 *, -1) != 0x3C))) {
            if (strnicmp(temp_r5_230 + 1, *MKFont::pEndToken, *MKFont::endTokenLen) == 0) {
                temp_r0_255 = *MKFont::currentFont + 1;
                temp_r7_257 = temp_r0_255 * 0x14;
                temp_r3_258 = *MKFont::endTokenLen + 2;
                *MKFont::currentFont = temp_r0_255;
                *(*MKFont::currentFontStack + temp_r7_257) = M2C_FIELD((*MKFont::currentFontStack + temp_r7_257), s32 *, -0x28);
                temp_r4_267 = *MKFont::currentFontStack + (*MKFont::currentFont * 0x14);
                M2C_FIELD(temp_r4_267, s32 *, 4) = (s32) M2C_FIELD(temp_r4_267, s32 *, -0x24);
                M2C_FIELD((*MKFont::currentFontStack + (*MKFont::currentFont * 0x14)), s32 *, -8) = (s32) (arg1 - 1);
                M2C_FIELD((*MKFont::currentFontStack + (*MKFont::currentFont * 0x14)), s32 *, 8) = (s32) (arg1 + temp_r3_258);
                return temp_r3_258;
            }
            temp_r30_284 = &arg0[arg1] + 1;
            if (strnicmp(temp_r30_284, *MKFont::pStartToken, *MKFont::startTokenLen) == 0) {
                temp_r31_293 = arg1 + *MKFont::startTokenLen;
                *MKFont::currentFont += 1;
                var_r31_295 = temp_r31_293 + 1;
                var_r3_296 = &M2C_FIELD(&arg0[temp_r31_293], u8 *, 1);
loop_10:
                if ((s32) *var_r3_296 != 0x3A) {
                    var_r31_295 += 1;
                    var_r3_296 += 1;
                    goto loop_10;
                }
                var_r30_305 = var_r31_295 + 1;
                var_r3_306 = &M2C_FIELD(&arg0[var_r31_295], u8 *, 1);
loop_13:
                if ((s32) *var_r3_306 != 0x3E) {
                    var_r30_305 += 1;
                    var_r3_306 += 1;
                    goto loop_13;
                }
                strncpy(&spC, arg1 + &M2C_FIELD(&arg0[*MKFont::startTokenLen], M2C_UNK *, 1), ((var_r31_295 - *MKFont::startTokenLen) - arg1) - 1);
                (&spB)[(var_r31_295 - *MKFont::startTokenLen) - arg1] = 0;
                temp_r28_333 = var_r30_305 - var_r31_295;
                *(*MKFont::currentFontStack + (*MKFont::currentFont * 0x14)) = ((MKFont *) &spC)->Find(&spB);
                strncpy(&spC, &arg0[var_r31_295] + 1, temp_r28_333 - 1);
                (&spB)[temp_r28_333] = 0;
                var_r4_349 = 0;
                M2C_FIELD((*MKFont::currentFontStack + (*MKFont::currentFont * 0x14)), s32 *, 4) = atoi(&spC);
                M2C_FIELD((*MKFont::currentFontStack + (*MKFont::currentFont * 0x14)), s32 *, 0x10) = -1;
                temp_r5_360 = *MKFont::currentFont - 1;
                temp_r9_361 = *MKFont::currentFont * 0x14;
                var_r3_363 = temp_r5_360 * 0x14;
                temp_r7_364 = *MKFont::currentFontStack + temp_r9_361;
                var_ctr_365 = temp_r5_360 + 1;
                if (temp_r5_360 >= 0) {
loop_15:
                    temp_r8_368 = *MKFont::currentFontStack + var_r3_363;
                    var_r0_369 = M2C_FIELD(temp_r8_368, s32 *, 0x10);
                    if (var_r4_349 > var_r0_369) {
                        var_r0_369 = var_r4_349;
                    }
                    var_r4_349 = var_r0_369;
                    if (((u32) M2C_FIELD(temp_r8_368, u32 *, 0) == (u32) M2C_FIELD(temp_r7_364, u32 *, 0)) && ((u32) M2C_FIELD(temp_r8_368, u32 *, 4) == (u32) M2C_FIELD(temp_r7_364, u32 *, 4))) {
                        M2C_FIELD((*MKFont::currentFontStack + temp_r9_361), s32 *, 0x10) = (s32) M2C_FIELD((*MKFont::currentFontStack + var_r3_363), s32 *, 0x10);
                    } else {
                        var_r3_363 -= 0x14;
                        var_ctr_365 -= 1;
                        if (var_ctr_365 != 0) {
                            goto loop_15;
                        }
                    }
                }
                temp_r3_395 = *MKFont::currentFontStack + (*MKFont::currentFont * 0x14);
                if ((s32) M2C_FIELD(temp_r3_395, s32 *, 0x10) == -1) {
                    M2C_FIELD(temp_r3_395, s32 *, 0x10) = (s32) (var_r4_349 + 1);
                }
                temp_r5_403 = 0 - arg1;
                M2C_FIELD((*MKFont::currentFontStack + (*MKFont::currentFont * 0x14)), s32 *, -8) = (s32) ((arg1 - 1) & ((temp_r5_403 - temp_r5_403) - !M2C_CARRY));
                M2C_FIELD((*MKFont::currentFontStack + (*MKFont::currentFont * 0x14)), s32 *, 8) = (s32) (var_r30_305 + 1);
                return (var_r30_305 - arg1) + 1;
            }
            if (strnicmp(temp_r30_284, *MKFont::pPageToken, *MKFont::pageTokenLen) == 0) {
                if (arg1 != 0) {
                    temp_r5_432 = *MKFont::currentFont + 1;
                    *MKFont::currentFont = temp_r5_432;
                    M2C_FIELD((*MKFont::currentFontStack + (temp_r5_432 * 0x14)), s32 *, -8) = (s32) (arg1 - 1);
                    temp_r4_439 = *MKFont::currentFont * 0x14;
                    *(*MKFont::currentFontStack + temp_r4_439) = M2C_FIELD((*MKFont::currentFontStack + temp_r4_439), s32 *, -0x14);
                }
                temp_r5_445 = &arg0[arg1];
                temp_r4_448 = &temp_r5_445[*MKFont::pageTokenLen];
                sp9 = 0;
                sp8 = M2C_FIELD(temp_r4_448, u8 *, 1);
                var_r4_458 = -1;
                M2C_FIELD((*MKFont::currentFontStack + (*MKFont::currentFont * 0x14)), s32 *, 4) = atoi((s8 *) &sp8, temp_r4_448, temp_r5_445);
                M2C_FIELD((*MKFont::currentFontStack + (*MKFont::currentFont * 0x14)), s32 *, 0x10) = -1;
                if (arg1 != 0) {
                    temp_r5_469 = *MKFont::currentFont - 1;
                    temp_r9_470 = *MKFont::currentFont * 0x14;
                    var_r3_472 = temp_r5_469 * 0x14;
                    temp_r7_473 = *MKFont::currentFontStack + temp_r9_470;
                    var_ctr_474 = temp_r5_469 + 1;
                    if (temp_r5_469 >= 0) {
loop_29:
                        temp_r8_477 = *MKFont::currentFontStack + var_r3_472;
                        var_r0_478 = M2C_FIELD(temp_r8_477, s32 *, 0x10);
                        if (var_r4_458 > var_r0_478) {
                            var_r0_478 = var_r4_458;
                        }
                        var_r4_458 = var_r0_478;
                        if (((u32) M2C_FIELD(temp_r8_477, u32 *, 0) == (u32) M2C_FIELD(temp_r7_473, u32 *, 0)) && ((u32) M2C_FIELD(temp_r8_477, u32 *, 4) == (u32) M2C_FIELD(temp_r7_473, u32 *, 4))) {
                            M2C_FIELD((*MKFont::currentFontStack + temp_r9_470), s32 *, 0x10) = (s32) M2C_FIELD((*MKFont::currentFontStack + var_r3_472), s32 *, 0x10);
                        } else {
                            var_r3_472 -= 0x14;
                            var_ctr_474 -= 1;
                            if (var_ctr_474 != 0) {
                                goto loop_29;
                            }
                        }
                    }
                }
                temp_r3_504 = *MKFont::currentFontStack + (*MKFont::currentFont * 0x14);
                if ((s32) M2C_FIELD(temp_r3_504, s32 *, 0x10) == -1) {
                    M2C_FIELD(temp_r3_504, s32 *, 0x10) = (s32) (var_r4_458 + 1);
                }
                temp_r3_515 = *MKFont::pageTokenLen + 3;
                M2C_FIELD((*MKFont::currentFontStack + (*MKFont::currentFont * 0x14)), s32 *, 8) = (s32) (arg1 + temp_r3_515);
                return temp_r3_515;
            }
            return 1;
        }
    }
    return 1;
}
#endif

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

#if 0 // DRAFT: pointer/array required
void MKFont::ResetFontStack(MKFont *arg0, unsigned int arg1) {
    s32 temp_r0_586;
    s32 temp_r5_584;
    s32 temp_r7_583;
    s32 temp_r8_582;
    s32 var_r3_570;
    u32 var_r30_574;

    var_r3_570 = 0;
    var_r30_574 = 0U;
loop_2:
    if (var_r30_574 < M2C_BITWISE(u32, gMKDefaults.unkB0)) {
        temp_r8_582 = var_r3_570 + 4;
        temp_r7_583 = var_r3_570 + 8;
        temp_r5_584 = var_r3_570 + 0xC;
        *(*MKFont::currentFontStack + var_r3_570) = 0;
        temp_r0_586 = var_r3_570 + 0x10;
        var_r30_574 += 1;
        var_r3_570 += 0x14;
        *(*MKFont::currentFontStack + temp_r8_582) = 0;
        *(*MKFont::currentFontStack + temp_r7_583) = 0;
        *(*MKFont::currentFontStack + temp_r5_584) = gMKDefaults.unkAC;
        *(*MKFont::currentFontStack + temp_r0_586) = 0;
        goto loop_2;
    }
    *MKFont::currentFont = 0;
    if (arg0 != NULL) {
        **MKFont::currentFontStack = arg0;
        M2C_FIELD((*MKFont::currentFontStack + (*MKFont::currentFont * 0x14)), s32 *, 4) = 0;
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'const char *' to
CharInfo *MKFont::GetCharacter(const char *arg0, int *arg1, FontPage **arg2) {
    CharInfo *var_r3_703;
    FontPage *temp_r5_684;
    f32 var_ctr_680;
    s32 *temp_r4_692;
    s32 temp_cr0_eq_648;
    s32 temp_r7_685;
    s32 var_r3_678;
    s8 *temp_r3_646;
    s8 *temp_r4_656;
    u8 temp_r3_657;

    if (IsToken(arg0, (u32) *arg1) != 0) {
loop_4:
        temp_r3_646 = &arg0[*arg1];
        temp_cr0_eq_648 = (s32) M2C_FIELD(temp_r3_646, u8 *, -1) == 0x3E;
        if ((temp_cr0_eq_648 != 0) && ((temp_cr0_eq_648 == 0) || ((s32) (u8) M2C_FIELD(temp_r3_646, s8 *, 0) != 0x3C))) {
            goto block_7;
        }
        *arg1 += 1;
        if ((s8) (u8) arg0[*arg1] == 0) {
            return NULL;
        }
        goto loop_4;
    }
block_7:
    temp_r4_656 = &arg0[*arg1];
    temp_r3_657 = (u8) M2C_FIELD(temp_r4_656, s8 *, 0);
    if ((((s32) temp_r3_657 == 0x3C) && ((s32) M2C_FIELD(temp_r4_656, u8 *, 1) == 0x3C)) || (((s8) temp_r3_657 == 0x3E) && ((s32) M2C_FIELD(temp_r4_656, u8 *, 1) == 0x3E))) {
        *arg1 += 1;
    }
    var_r3_678 = 0;
    var_ctr_680 = gMKDefaults.unkB0;
    if (M2C_BITWISE(u32, gMKDefaults.unkB0) > 0U) {
loop_13:
        temp_r5_684 = *MKFont::currentFontStack + var_r3_678;
        temp_r7_685 = *arg1;
        if (((u32) temp_r5_684->unk8 <= (u32) temp_r7_685) && ((u32) temp_r5_684->unkC >= (u32) temp_r7_685)) {
            temp_r4_692 = temp_r5_684->unk0;
            if (temp_r4_692 != NULL) {
                var_r3_703 = M2C_FIELD(*(*temp_r4_692 + (temp_r5_684->unk4 * 4)), s32 *, 0x28) + (((u8) arg0[temp_r7_685] << 5) & 0x1FE0);
                if (arg2 != NULL) {
                    *arg2 = temp_r5_684;
                    return var_r3_703;
                }
                /* Duplicate return node #20. Try simplifying control flow for better match */
                return var_r3_703;
            }
        }
        var_r3_678 += 0x14;
        var_ctr_680 = M2C_BITWISE(f32, (M2C_BITWISE(s32, var_ctr_680) - 1));
        if (M2C_BITWISE(s32, var_ctr_680) == 0) {
            goto block_19;
        }
        goto loop_13;
    }
block_19:
    var_r3_703 = NULL;
    return var_r3_703;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'const char *' to
u8 MKFont::IsToken(const char *arg0, unsigned int arg1) {
    s8 *temp_r6_728;
    u8 temp_r4_729;

    if ((s8) (u8) arg0[arg1] == 0x3C) {
        temp_r6_728 = &arg0[arg1];
        temp_r4_729 = M2C_FIELD(temp_r6_728, u8 *, 1);
        if (((s8) temp_r4_729 != 0) && ((s8) temp_r4_729 != 0x3C) && ((arg1 == 0) || ((s32) M2C_FIELD(temp_r6_728, u8 *, -1) != 0x3C))) {
            return 1U;
        }
    }
    return 0U;
}
#endif

#if 0 // DRAFT: pointer/array required
f32 MKFont::GetWidthOfCharacter(char arg0, CharInfo *arg1, FontPage *arg2) {
    if ((u8) arg0 > 0x20U) {
        if ((s32) arg1->unk1C != 0) {
            return arg1->unk18 + M2C_FIELD(*(*arg2->unk0 + (arg2->unk4 * 4)), f32 *, 8);
        }
        return M2C_FIELD(*(*arg2->unk0 + (arg2->unk4 * 4)), f32 *, 0xC);
    }
    return M2C_FIELD(*(*arg2->unk0 + (arg2->unk4 * 4)), f32 *, 0xC);
}
#endif

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

#if 0 // DRAFT: illegal implicit conversion from 'long' to
void *MKFont::GetCharacterFontPage(unsigned int arg0) {
    f32 var_ctr_865;
    s32 var_r5_863;
    void *temp_r3_869;

    var_r5_863 = 0;
    var_ctr_865 = gMKDefaults.unkB0;
    if (M2C_BITWISE(u32, gMKDefaults.unkB0) > 0U) {
loop_1:
        temp_r3_869 = *MKFont::currentFontStack + var_r5_863;
        if (((u32) M2C_FIELD(temp_r3_869, u32 *, 8) > arg0) || ((u32) M2C_FIELD(temp_r3_869, u32 *, 0xC) < arg0)) {
            var_r5_863 += 0x14;
            var_ctr_865 = M2C_BITWISE(f32, (M2C_BITWISE(s32, var_ctr_865) - 1));
            if (M2C_BITWISE(s32, var_ctr_865) == 0) {
                /* Duplicate return node #4. Try simplifying control flow for better match */
                return NULL;
            }
            goto loop_1;
        }
        return temp_r3_869;
    }
    return NULL;
}
#endif

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
                    temp_r18_1151 = M2C_FIELD(temp_r4_1149, s32 *, 0x28) + ((temp_r17_1139 << 5) & 0x1FE0);
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
    if (var_r17_1248 < M2C_BITWISE(u32, gMKDefaults.unkB0)) {
        temp_r18_1254 = *MKFont::currentFontStack + var_r20_1250;
        if (((void *) M2C_FIELD(temp_r18_1254, void **, 0) != NULL) && ((s32) M2C_FIELD(temp_r18_1254, s32 *, 0x10) != -1)) {
            var_r8_1261 = var_r17_1248 + 1;
            var_r3_1263 = var_r8_1261 * 0x14;
loop_59:
            if (var_r8_1261 < M2C_BITWISE(u32, gMKDefaults.unkB0)) {
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
                        *(pDrawStringList + var_r3_1282) = temp_r7_1290;
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

#if 0 // DRAFT: illegal implicit conversion from 'const char *' to
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

    var_r22_1421 = arg0;
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
        var_r29_1459 = arg0;
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
                var_r29_1459 = &arg0[sp8];
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

#if 0 // DRAFT: illegal implicit conversion from 'unsigned char' to
void MKFont::DeinitModule() {
    MKHeap *temp_r0_1787;
    MKHeap *temp_r0_1806;
    MKHeap *temp_r31_1754;
    MKHeap *temp_r31_1768;
    MKHeap *temp_r3_1755;
    MKHeap *temp_r3_1769;
    MKHeap *temp_r3_1809;
    MKHeap *var_r31_1783;
    MKHeap *var_r3_1784;
    MKHeap *var_r4_1782;
    u32 temp_r0_1792;

    temp_r31_1754 = *MKFont::fontColours;
    temp_r3_1755 = MKHeap::Current();
    if (temp_r3_1755 != NULL) {
        ((MKHeap *) (temp_r3_1755->Current()))->Free(temp_r31_1754, NULL, 0);
    } else {
        free(temp_r31_1754);
    }
    temp_r31_1768 = *MKFont::currentFontStack;
    temp_r3_1769 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_1769 != NULL) {
        ((MKHeap *) (temp_r3_1769->Current()))->Free(temp_r31_1768, NULL, 0);
    } else {
        free(temp_r31_1768);
    }
    var_r4_1782 = *MKFont::fontList;
    var_r31_1783 = var_r4_1782;
    var_r3_1784 = var_r4_1782;
loop_9:
    temp_r0_1792 = M2C_FIELD(var_r3_1784, u32 *, -4);
    var_r3_1784 -= 4;
    if (temp_r0_1792 != 0U) {
        temp_r0_1787 = var_r3_1784->unk0;
        if (temp_r0_1787 < var_r31_1783) {
            var_r31_1783 = temp_r0_1787;
        }
        goto loop_9;
    }
    if (var_r3_1784 != &gEmptyPtrListDL) {
loop_15:
        temp_r0_1806 = var_r4_1782->unk0;
        if (temp_r0_1806 != NULL) {
            if (temp_r0_1806 < var_r31_1783) {
                var_r31_1783 = temp_r0_1806;
            }
            var_r4_1782 += 4;
            goto loop_15;
        }
        temp_r3_1809 = var_r3_1784->Current();
        if (temp_r3_1809 != NULL) {
            ((MKHeap *) (temp_r3_1809->Current()))->Free(var_r31_1783, NULL, 0);
        } else {
            free(var_r31_1783);
        }
    }
    *MKFont::fontList = NULL;
    *MKFont::bInitialised = 0;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void *' to
void MKFont::InitModule() {
    MKHeap *temp_r3_1843;
    MKHeap *temp_r3_1859;
    MKHeap *temp_r3_1874;
    MKHeap *temp_r3_1898;
    MKHeap *temp_r3_1946;
    MKHeap *temp_r3_1964;
    MKHeap *temp_r4_1920;
    MKHeap *var_r3_1850;
    MKHeap *var_r3_1866;
    MKHeap *var_r3_1881;
    MKHeap *var_r3_1908;
    MKHeap *var_r3_1953;
    MKHeap *var_r3_1971;
    f32 temp_r30_1873;
    s32 temp_r30_1842;
    s32 temp_r30_1858;
    s32 temp_r30_1890;
    s32 temp_r30_1945;
    s32 temp_r30_1963;
    s32 var_ctr_1923;

    temp_r30_1842 = M2C_BITWISE(s32, gMKDefaults.unkAC) * 0x78;
    temp_r3_1843 = gMKDefaults.Current();
    if (temp_r3_1843 != NULL) {
        var_r3_1850 = ((MKHeap *) (temp_r3_1843->Current()))->Alloc(temp_r30_1842, NULL, 0);
    } else {
        var_r3_1850 = malloc(temp_r30_1842);
    }
    drawStringChars = var_r3_1850;
    temp_r30_1858 = M2C_BITWISE(s32, gMKDefaults.unkAC) * 4;
    temp_r3_1859 = var_r3_1850->Current();
    if (temp_r3_1859 != NULL) {
        var_r3_1866 = ((MKHeap *) (temp_r3_1859->Current()))->Alloc(temp_r30_1858, NULL, 0);
    } else {
        var_r3_1866 = malloc(temp_r30_1858);
    }
    pDrawStringList = (TextCharStrip **) var_r3_1866;
    temp_r30_1873 = gMKDefaults.unkAC;
    temp_r3_1874 = var_r3_1866->Current();
    if (temp_r3_1874 != NULL) {
        var_r3_1881 = ((MKHeap *) (temp_r3_1874->Current()))->Alloc(M2C_BITWISE(s32, temp_r30_1873), NULL, 0);
    } else {
        var_r3_1881 = malloc(M2C_BITWISE(s32, temp_r30_1873));
    }
    pWorkingText = (s8 *) var_r3_1881;
    temp_r30_1890 = gMKDefaults.unkB8;
    if (temp_r30_1890 == 0) {
        *MKFont::fontList = &gEmptyPtrListDL + 4;
    } else {
        temp_r3_1898 = gMKDefaults.Current();
        if (temp_r3_1898 != NULL) {
            var_r3_1908 = ((MKHeap *) (temp_r3_1898->Current()))->Alloc(((temp_r30_1890 + 2) * 4) + (temp_r30_1890 * 0x30), NULL, 0);
        } else {
            var_r3_1908 = malloc(((temp_r30_1890 + 2) * 4) + (temp_r30_1890 * 0x30));
        }
        *MKFont::fontList = var_r3_1908;
        temp_r4_1920 = var_r3_1908 + (temp_r30_1890 * 0x30);
        *MKFont::fontList = temp_r4_1920;
        temp_r4_1920->unk0 = NULL;
        var_ctr_1923 = temp_r30_1890;
        if (temp_r30_1890 > 0) {
            do {
                *MKFont::fontList = (MKHeap *) &(*MKFont::fontList)->unk4;
                (*MKFont::fontList)->unk4 = (s32) var_r3_1908;
                var_r3_1908 += 0x30;
                var_ctr_1923 -= 1;
            } while (var_ctr_1923 != 0);
        }
        *MKFont::fontList = (MKHeap *) &(*MKFont::fontList)->unk4;
        (*MKFont::fontList)->unk4 = 0;
    }
    *MKFont::bInitialised = 1;
    temp_r30_1945 = M2C_BITWISE(s32, gMKDefaults.unkB0) * 0x14;
    temp_r3_1946 = gMKDefaults.Current();
    if (temp_r3_1946 != NULL) {
        var_r3_1953 = ((MKHeap *) (temp_r3_1946->Current()))->Alloc(temp_r30_1945, NULL, 0);
    } else {
        var_r3_1953 = malloc(temp_r30_1945);
    }
    *MKFont::currentFontStack = var_r3_1953;
    temp_r30_1963 = gMKDefaults.unkB4 * 0x18;
    temp_r3_1964 = gMKDefaults.Current();
    if (temp_r3_1964 != NULL) {
        var_r3_1971 = ((MKHeap *) (temp_r3_1964->Current()))->Alloc(temp_r30_1963, NULL, 0);
    } else {
        var_r3_1971 = malloc(temp_r30_1963);
    }
    *MKFont::fontColours = var_r3_1971;
}
#endif

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

#if 0 // DRAFT: pointer/array required
f32 MKFont::GetHeight() {
    return M2C_FIELD(**this, f32 *, 0x24);
}
#endif

#if 0 // DRAFT: function call 'MKMaterial_Destroy(MKHeap)' does not match
void MKFont::Destroy() {
    MKHeap *temp_r30_2084;
    MKHeap *temp_r30_2104;
    MKHeap *temp_r30_2118;
    MKHeap *temp_r3_2083;
    MKHeap *temp_r3_2085;
    MKHeap *temp_r3_2105;
    MKHeap *temp_r3_2119;
    s32 temp_r0_2073;
    s32 var_r29_2076;
    s32 var_r31_2077;
    u32 *temp_r3_2137;
    u32 *var_r4_2132;
    u32 temp_r0_2148;
    u32 temp_r5_2140;

    temp_r0_2073 = M2C_FIELD(this, s32 *, 0x2C) - 1;
    M2C_FIELD(this, s32 *, 0x2C) = temp_r0_2073;
    if (temp_r0_2073 == 0) {
        var_r29_2076 = 0;
        var_r31_2077 = 0;
loop_6:
        if (var_r29_2076 < (s32) this->unk8) {
            MKMaterial_Destroy(*(M2C_FIELD(this, MKHeap **, 4) + var_r31_2077));
            temp_r3_2083 = M2C_FIELD(this, MKHeap **, 0);
            temp_r30_2084 = *(temp_r3_2083 + var_r31_2077);
            temp_r3_2085 = temp_r3_2083->Current();
            if (temp_r3_2085 != NULL) {
                ((MKHeap *) (temp_r3_2085->Current()))->Free(temp_r30_2084, NULL, 0);
            } else {
                free(temp_r30_2084);
            }
            var_r29_2076 += 1;
            var_r31_2077 += 4;
            goto loop_6;
        }
        temp_r30_2104 = M2C_FIELD(this, MKHeap **, 4);
        temp_r3_2105 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_2105 != NULL) {
            ((MKHeap *) (temp_r3_2105->Current()))->Free(temp_r30_2104, NULL, 0);
        } else {
            free(temp_r30_2104);
        }
        temp_r30_2118 = M2C_FIELD(this, MKHeap **, 0);
        temp_r3_2119 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_2119 != NULL) {
            ((MKHeap *) (temp_r3_2119->Current()))->Free(temp_r30_2118, NULL, 0);
        } else {
            free(temp_r30_2118);
        }
        var_r4_2132 = *MKFont::fontList;
loop_17:
        temp_r0_2148 = *var_r4_2132;
        if (temp_r0_2148 == 0U) {

        } else {
            if (temp_r0_2148 == this) {
                temp_r3_2137 = *MKFont::fontList;
                *MKFont::fontList = temp_r3_2137 + 4;
                temp_r5_2140 = *temp_r3_2137;
                *temp_r3_2137 = *var_r4_2132;
                *var_r4_2132 = temp_r5_2140;
                return;
            }
            var_r4_2132 += 4;
            goto loop_17;
        }
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'unsigned char' to
void *MKFont::Find(const char *arg0) {
    void **var_r31_2167;
    void *temp_r3_2180;

    var_r31_2167 = *MKFont::fontList;
loop_4:
    temp_r3_2180 = *var_r31_2167;
    if (temp_r3_2180 == NULL) {
        return NULL;
    }
    if (stricmp(((u8 *) temp_r3_2180) + 0xC, this) == 0) {
        return *var_r31_2167;
    }
    var_r31_2167 += 4;
    goto loop_4;
}
#endif

#if 0 // DRAFT: identifier 'MKFont::Create(const char *)' redeclared
void *MKFont::Create(const char *arg0) {
    MKHeap *temp_r3_2229;
    MKHeap *temp_r3_2243;
    MKHeap *temp_r6_2281;
    MKHeap *temp_r7_2282;
    MKHeap *temp_ret_2250;
    MKHeap *temp_ret_2254;
    MKHeap *var_r3_2236;
    MKHeap *var_r3_2250;
    MKMaterial *temp_r3_2288;
    f32 var_f1_2200;
    f32 var_f1_2250;
    s32 temp_ret_2226;
    s32 var_r28_2260;
    s8 *temp_r3_2272;
    s8 *temp_ret_2272;
    u32 var_r26_2259;
    u32 var_r30_2211;
    u8 temp_r3_2226;
    void *temp_r4_2208;
    void *temp_r6_2283;
    void *temp_ret_2200;
    void *var_r31_2201;

    temp_ret_2200 = Find(arg0);
    var_f1_2200 = M2C_BITWISE(f32, temp_ret_2200);
    var_r31_2201 = temp_ret_2200;
    if (var_r31_2201 != NULL) {
        M2C_FIELD(var_r31_2201, s32 *, 0x2C) = (s32) (M2C_FIELD(var_r31_2201, s32 *, 0x2C) + 1);
    } else {
        temp_r4_2208 = *MKFont::fontList;
        var_r30_2211 = 0;
        *MKFont::fontList = ((u8 *) temp_r4_2208) - 4;
        var_r31_2201 = M2C_FIELD(temp_r4_2208, void **, -4);
loop_4:
        temp_ret_2226 = MKArchive_Exists(Str_Printf("%s%d%s", this, var_r30_2211, ".fnt", var_f1_2200), NULL);
        var_f1_2200 = M2C_BITWISE(f32, temp_ret_2226);
        temp_r3_2226 = temp_ret_2226;
        if (temp_r3_2226 != 0) {
            var_r30_2211 += 1;
            goto loop_4;
        }
        temp_r3_2229 = ((MKHeap *) temp_r3_2226)->Current();
        if (temp_r3_2229 != NULL) {
            var_r3_2236 = ((MKHeap *) (temp_r3_2229->Current()))->Alloc(var_r30_2211 * 4, NULL, 0);
        } else {
            var_r3_2236 = malloc(var_r30_2211 * 4);
        }
        M2C_FIELD(var_r31_2201, MKHeap **, 4) = var_r3_2236;
        temp_r3_2243 = var_r3_2236->Current();
        if (temp_r3_2243 != NULL) {
            temp_ret_2250 = ((MKHeap *) (temp_r3_2243->Current()))->Alloc(var_r30_2211 * 4, NULL, 0);
            var_f1_2250 = M2C_BITWISE(f32, temp_ret_2250);
            var_r3_2250 = temp_ret_2250;
        } else {
            temp_ret_2254 = malloc(var_r30_2211 * 4);
            var_f1_2250 = M2C_BITWISE(f32, temp_ret_2254);
            var_r3_2250 = temp_ret_2254;
        }
        M2C_FIELD(var_r31_2201, MKHeap **, 0) = var_r3_2250;
        var_r26_2259 = 0U;
        var_r28_2260 = 0;
loop_13:
        if (var_r26_2259 < var_r30_2211) {
            temp_ret_2272 = MKArchive_Load(Str_Printf("%s%d%s", this, var_r26_2259, ".fnt", var_f1_2250), NULL, NULL, -1);
            temp_r3_2272 = temp_ret_2272;
            M2C_FIELD(temp_r3_2272, void **, 0x28) = (void *) (temp_r3_2272 + M2C_FIELD(temp_r3_2272, void **, 0x28));
            *(M2C_FIELD(var_r31_2201, MKHeap **, 0) + var_r28_2260) = temp_r3_2272;
            temp_r6_2281 = M2C_FIELD(var_r31_2201, MKHeap **, 0);
            temp_r7_2282 = temp_r6_2281->unk0;
            temp_r6_2283 = *(temp_r6_2281 + var_r28_2260);
            M2C_FIELD(temp_r6_2283, f32 *, 0xC) = M2C_BITWISE(f32, temp_r7_2282->unkC);
            temp_r3_2288 = MKMaterial_Create(Str_Printf("%s%d", this, var_r26_2259, temp_r6_2283, temp_r7_2282, M2C_BITWISE(f32, temp_ret_2272)));
            MKMaterial_SetParameter(temp_r3_2288, (MKMaterialParameter) 1, 1);
            MKMaterial_SetParameter(temp_r3_2288, (MKMaterialParameter) 2, 1);
            MKMaterial_SetParameter(temp_r3_2288, (MKMaterialParameter) 0, 0);
            var_f1_2250 = M2C_BITWISE(f32, MKMat_MK2_SetMaterialType(temp_r3_2288, (MKMat_MK2_Standard_MaterialType) 3));
            var_r26_2259 += 1;
            *(M2C_FIELD(var_r31_2201, MKHeap **, 4) + var_r28_2260) = temp_r3_2288;
            var_r28_2260 += 4;
            goto loop_13;
        }
        M2C_FIELD(var_r31_2201, s32 *, 0x2C) = 1;
        M2C_FIELD(var_r31_2201, u32 *, 8) = var_r30_2211;
        strcpy(((u8 *) var_r31_2201) + 0xC, (s8 *) this);
    }
    return var_r31_2201;
}
#endif

#if 0 // DRAFT: function call 'strlen(unsigned char)' does not match
void Font_cpp::__sinit() {
    *MKFont::endTokenLen = strlen(*MKFont::pEndToken);
    *MKFont::startTokenLen = strlen(*MKFont::pStartToken);
    *MKFont::colourTokenLen = strlen(*MKFont::pColourToken);
    *MKFont::endColourTokenLen = strlen(*MKFont::pEndColourToken);
    *MKFont::pageTokenLen = strlen(*MKFont::pPageToken);
}
#endif
