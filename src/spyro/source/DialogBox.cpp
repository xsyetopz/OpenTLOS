#include "spyro/source/DialogBox.h"
#include "common/Source/MKFont.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "unplaced_enums.h"
#include "common/Source/MKInput.h"
#include "common/Source/StdMath.h"
#include "common/Source/Str.h"
#include "common/gc/MKMaterial_GC.h"
#include "common/gc/MKPrimitive_GC.h"
#include "spyro/source/Hud.h"
#include <m2c_macros.h>

extern u8 bDrawnThisFrame;
extern s32 contextCount;
extern s32 gViewSeed;
extern M2C_UNK gb;
extern void *gpTranslation_StringArray;
#if 0 // DRAFT: undefined identifier 'lit_stringBase0'
static M2C_UNK buttonColorBright;                   /* unable to generate initializer: unknown type */
static M2C_UNK buttonColorDull;                     /* unable to generate initializer: unknown type */
static u8 *pTags[3] = { NULL, lit_stringBase0, .L_8035CF68 };
#endif
static s8 themes[0x40];
static M2C_UNK contexts;
#if 0 // DRAFT: identifier 'Dialog_bEnableDraw' redeclared
static u8 Dialog_bEnableDraw = 1;
#endif
#if 0 // DRAFT: declaration syntax error
static u8 lit_stringBase0[8] = { 0x3C, 0x2F, 0x66, 0x6F, 0x6E, 0x74, 0x3E, 0 }; /* const */
static u8 .L_8035CF68[0x62] = {
    0x3C,
    0x2F,
    0x63,
    0x6F,
    0x6C,
    0x6F,
    0x75,
    0x72,
    0x3E,
    0,
    0x75,
    0x69,
    0x5F,
    0x74,
    0x68,
    0x65,
    0x6D,
    0x65,
    0x5F,
    0x65,
    0x64,
    0x67,
    0x65,
    0x25,
    0x64,
    0x5F,
    0x25,
    0x73,
    0,
    0x75,
    0x69,
    0x5F,
    0x74,
    0x68,
    0x65,
    0x6D,
    0x65,
    0x5F,
    0x63,
    0x72,
    0x6E,
    0x72,
    0x31,
    0x5F,
    0x25,
    0x73,
    0,
    0x75,
    0x69,
    0x5F,
    0x74,
    0x68,
    0x65,
    0x6D,
    0x65,
    0x5F,
    0x63,
    0x72,
    0x6E,
    0x72,
    0x32,
    0x5F,
    0x25,
    0x73,
    0,
    0x3C,
    0x63,
    0x6F,
    0x6C,
    0x6F,
    0x75,
    0x72,
    0x3D,
    0x25,
    0x30,
    0x2E,
    0x31,
    0x66,
    0x2C,
    0x25,
    0x30,
    0x2E,
    0x31,
    0x66,
    0x2C,
    0x25,
    0x30,
    0x2E,
    0x31,
    0x66,
    0x2C,
    0x25,
    0x30,
    0x2E,
    0x31,
    0x66,
    0x3E,
    0,
}; /* const */

void DialogBox_Draw() {
    DialogBoxContext *temp_r27_35;
    s32 var_r28_31;
    s32 var_r31_33;

    if ((u8) bDrawnThisFrame == 0) {
        if ((u8) Dialog_bEnableDraw == 0) {
            return;
        }
        bDrawnThisFrame = 1;
        if ((s32) contextCount != 0) {
            var_r28_31 = 0;
            var_r31_33 = 0;
            do {
                temp_r27_35 = &contexts + var_r31_33;
                if (((u32) temp_r27_35->unk30 != NULL) && ((u8) temp_r27_35->unkAC == (u8) M2C_FIELD(&gb, u8 *, 0x395))) {
                    if ((u32) temp_r27_35->unk0 != 0U) {
                        DialogBox_DrawBackground(temp_r27_35);
                        DialogBox_DrawBorder(temp_r27_35);
                        DialogBox_DrawTab(temp_r27_35);
                    }
                    DialogBox_DrawText(temp_r27_35);
                }
                var_r28_31 += 1;
                var_r31_33 += 0xB0;
            } while (var_r28_31 < 0xA);
        }
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long *' to
void DialogBox_Update() {
    DialogBoxContext *temp_r31_86;
    f32 temp_f2_94;
    s32 var_r28_83;
    s32 var_r29_78;
    s32 var_r3_149;
    s32 var_r3_171;
    s32 var_r3_206;
    s32 var_r3_237;
    s32 var_r3_268;
    s32 var_r3_299;
    s32 var_r3_327;
    s32 var_r3_355;
    s32 var_r3_383;
    u8 var_r3_137;
    u8 var_r3_159;
    u8 var_r3_194;
    u8 var_r3_225;
    u8 var_r3_256;
    u8 var_r3_287;
    u8 var_r3_315;
    u8 var_r3_343;
    u8 var_r3_371;

    if ((s32) contextCount != 0) {
        var_r29_78 = 0;
        bDrawnThisFrame = 0;
        var_r28_83 = 0;
        do {
            temp_r31_86 = &contexts + var_r29_78;
            if (((u32) temp_r31_86->unk30 != NULL) && ((u8) temp_r31_86->unkAC == (u8) M2C_FIELD(&gb, u8 *, 0x395)) && ((temp_f2_94 = temp_r31_86->unk68, ((temp_f2_94 > 0.0f) == 0)) || (temp_r31_86->unk68 = temp_f2_94 - 0.033333335f, ((temp_r31_86->unk68 > 0.0f) == 0)))) {
                temp_r31_86->unk60 += 0.033333335f;
                temp_r31_86->unk38 += 0.033333335f * temp_r31_86->unk3C;
                if ((temp_r31_86->unkC & 0x200) && (temp_r31_86->unk60 > temp_r31_86->unk64)) {
                    DialogBox_ReleaseContext(temp_r31_86);
                } else {
                    if ((u8) temp_r31_86->unk44 != 0) {
                        temp_r31_86->unk40 += 1;
                        temp_r31_86->unk44 = 0;
                    }
                    if (temp_r31_86->unkC & 0x100) {
                        var_r3_137 = 0;
                        if (((u8) M2C_FIELD(M2C_FIELD(&gb, void **, 0x354), u8 *, 5) != 0) || ((u8) M2C_FIELD(M2C_FIELD(&gb, void **, 0x354), u8 *, 4) != 0)) {
                            var_r3_137 = 1;
                        }
                        if (var_r3_137 != 0) {
                            var_r3_149 = 0;
                        } else {
                            var_r3_149 = MKInput_Pressed(0xC, (MKInputDevices) M2C_FIELD(M2C_FIELD(&gb, void **, 0x354), s32 *, 0));
                        }
                        if ((u8) var_r3_149 == 0) {
                            var_r3_159 = 0;
                            if (((u8) M2C_FIELD(M2C_FIELD(&gb, void **, 0x354), u8 *, 5) != 0) || ((u8) M2C_FIELD(M2C_FIELD(&gb, void **, 0x354), u8 *, 4) != 0)) {
                                var_r3_159 = 1;
                            }
                            if (var_r3_159 != 0) {
                                var_r3_171 = 0;
                            } else {
                                var_r3_171 = MKInput_Pressed(0xE, (MKInputDevices) M2C_FIELD(M2C_FIELD(&gb, void **, 0x354), s32 *, 0));
                            }
                            if ((u8) var_r3_171 != 0) {
                                goto block_26;
                            }
                        } else {
block_26:
                            temp_r31_86->unk3C = 256.0f;
                        }
                    }
                    if ((((M2C_UNK (*)(DialogBoxContext *, M2C_UNK)) temp_r31_86->unk6C) != NULL) && ((u8) temp_r31_86->unk45 != 0)) {
                        if (temp_r31_86->unkC & 0x10) {
                            var_r3_194 = 0;
                            if (((u8) M2C_FIELD(M2C_FIELD(&gb, void **, 0x354), u8 *, 5) != 0) || ((u8) M2C_FIELD(M2C_FIELD(&gb, void **, 0x354), u8 *, 4) != 0)) {
                                var_r3_194 = 1;
                            }
                            if (var_r3_194 != 0) {
                                var_r3_206 = 0;
                            } else {
                                var_r3_206 = MKInput_Pressed(0xE, (MKInputDevices) M2C_FIELD(M2C_FIELD(&gb, void **, 0x354), s32 *, 0));
                            }
                            if ((u8) var_r3_206 != 0) {
                                temp_r31_86->unk6C(temp_r31_86, 0);
                            }
                        }
                        if (temp_r31_86->unkC & 0x20) {
                            var_r3_225 = 0;
                            if (((u8) M2C_FIELD(M2C_FIELD(&gb, void **, 0x354), u8 *, 5) != 0) || ((u8) M2C_FIELD(M2C_FIELD(&gb, void **, 0x354), u8 *, 4) != 0)) {
                                var_r3_225 = 1;
                            }
                            if (var_r3_225 != 0) {
                                var_r3_237 = 0;
                            } else {
                                var_r3_237 = MKInput_Pressed(0xE, (MKInputDevices) M2C_FIELD(M2C_FIELD(&gb, void **, 0x354), s32 *, 0));
                            }
                            if ((u8) var_r3_237 != 0) {
                                temp_r31_86->unk6C(temp_r31_86, 1);
                            }
                        }
                        if (temp_r31_86->unkC & 0x40) {
                            var_r3_256 = 0;
                            if (((u8) M2C_FIELD(M2C_FIELD(&gb, void **, 0x354), u8 *, 5) != 0) || ((u8) M2C_FIELD(M2C_FIELD(&gb, void **, 0x354), u8 *, 4) != 0)) {
                                var_r3_256 = 1;
                            }
                            if (var_r3_256 != 0) {
                                var_r3_268 = 0;
                            } else {
                                var_r3_268 = MKInput_Pressed(0xF, (MKInputDevices) M2C_FIELD(M2C_FIELD(&gb, void **, 0x354), s32 *, 0));
                            }
                            if ((u8) var_r3_268 != 0) {
                                temp_r31_86->unk6C(temp_r31_86, 2);
                            }
                        }
                        if (temp_r31_86->unkC & 0x80) {
                            var_r3_287 = 0;
                            if (((u8) M2C_FIELD(M2C_FIELD(&gb, void **, 0x354), u8 *, 5) != 0) || ((u8) M2C_FIELD(M2C_FIELD(&gb, void **, 0x354), u8 *, 4) != 0)) {
                                var_r3_287 = 1;
                            }
                            if (var_r3_287 != 0) {
                                var_r3_299 = 0;
                            } else {
                                var_r3_299 = MKInput_Pressed(4, (MKInputDevices) M2C_FIELD(M2C_FIELD(&gb, void **, 0x354), s32 *, 0));
                            }
                            if ((u8) var_r3_299 != 0) {
                                temp_r31_86->unk6C(temp_r31_86, 3);
                            }
                            var_r3_315 = 0;
                            if (((u8) M2C_FIELD(M2C_FIELD(&gb, void **, 0x354), u8 *, 5) != 0) || ((u8) M2C_FIELD(M2C_FIELD(&gb, void **, 0x354), u8 *, 4) != 0)) {
                                var_r3_315 = 1;
                            }
                            if (var_r3_315 != 0) {
                                var_r3_327 = 0;
                            } else {
                                var_r3_327 = MKInput_Pressed(6, (MKInputDevices) M2C_FIELD(M2C_FIELD(&gb, void **, 0x354), s32 *, 0));
                            }
                            if ((u8) var_r3_327 != 0) {
                                temp_r31_86->unk6C(temp_r31_86, 4);
                            }
                            var_r3_343 = 0;
                            if (((u8) M2C_FIELD(M2C_FIELD(&gb, void **, 0x354), u8 *, 5) != 0) || ((u8) M2C_FIELD(M2C_FIELD(&gb, void **, 0x354), u8 *, 4) != 0)) {
                                var_r3_343 = 1;
                            }
                            if (var_r3_343 != 0) {
                                var_r3_355 = 0;
                            } else {
                                var_r3_355 = MKInput_Pressed(7, (MKInputDevices) M2C_FIELD(M2C_FIELD(&gb, void **, 0x354), s32 *, 0));
                            }
                            if ((u8) var_r3_355 != 0) {
                                temp_r31_86->unk6C(temp_r31_86, 5);
                            }
                            var_r3_371 = 0;
                            if (((u8) M2C_FIELD(M2C_FIELD(&gb, void **, 0x354), u8 *, 5) != 0) || ((u8) M2C_FIELD(M2C_FIELD(&gb, void **, 0x354), u8 *, 4) != 0)) {
                                var_r3_371 = 1;
                            }
                            if (var_r3_371 != 0) {
                                var_r3_383 = 0;
                            } else {
                                var_r3_383 = MKInput_Pressed(5, (MKInputDevices) M2C_FIELD(M2C_FIELD(&gb, void **, 0x354), s32 *, 0));
                            }
                            if ((u8) var_r3_383 != 0) {
                                temp_r31_86->unk6C(temp_r31_86, 6);
                            }
                        }
                    }
                }
            }
            var_r28_83 += 1;
            var_r29_78 += 0xB0;
        } while (var_r28_83 < 0xA);
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long *' to
void DialogBox_ReleaseContexts() {
    DialogBoxContext *temp_r3_422;
    s32 var_r29_418;
    s32 var_r31_420;

    var_r29_418 = 0;
    var_r31_420 = 0;
    do {
        temp_r3_422 = &contexts + var_r31_420;
        if ((u32) temp_r3_422->unk30 != NULL) {
            DialogBox_ReleaseContext(temp_r3_422);
        }
        var_r29_418 += 1;
        var_r31_420 += 0xB0;
    } while (var_r29_418 < 0xA);
}
#endif

#if 0 // DRAFT: undefined identifier 'unk6C'
void DialogBox_ReleaseContext(DialogBoxContext *arg0) {
    M2C_UNK (*temp_r12_451)(DialogBoxContext *, M2C_UNK);

    if ((arg0 != NULL) && ((s8 *) arg0->unk30 != NULL)) {
        temp_r12_451 = arg0->unk6C;
        if (temp_r12_451 != NULL) {
            temp_r12_451((DialogBoxContext *)7);
        }
        memset(arg0, 0, 0xB0U);
        contextCount -= 1;
    }
}
#endif

#if 0 // DRAFT: function call 'MKRand_Int(long *, int, int)' does not match
void *DialogBox_InitContext() {
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    s32 var_r3_482;
    s32 var_r6_479;
    void *temp_r5_487;
    void *var_r31_484;

    var_r6_479 = 0;
    var_r3_482 = 0;
    var_r31_484 = NULL;
loop_4:
    if ((var_r6_479 < 0xA) && (var_r31_484 == NULL)) {
        temp_r5_487 = &contexts + var_r3_482;
        if ((u32) M2C_FIELD(temp_r5_487, u32 *, 0x30) == 0U) {
            var_r31_484 = temp_r5_487;
        }
        var_r6_479 += 1;
        var_r3_482 += 0xB0;
        goto loop_4;
    }
    contextCount += 1;
    memset(var_r31_484, 0, 0xB0U);
    M2C_FIELD(var_r31_484, f32 *, 0x8C) = 1.0f;
    sp38 = 0.0f;
    sp3C = 0.0f;
    M2C_FIELD(var_r31_484, f32 *, 0x90) = 1.0f;
    sp40 = 0.0f;
    sp44 = 0.5f;
    M2C_FIELD(var_r31_484, f64 *, 0x70) = (f64) sp38;
    sp28 = 1.0f;
    sp2C = 1.0f;
    M2C_FIELD(var_r31_484, f64 *, 0x78) = (f64) sp40;
    sp30 = 1.0f;
    sp34 = 1.0f;
    M2C_FIELD(var_r31_484, f64 *, 0x98) = (f64) sp28;
    sp18 = 1.0f;
    sp1C = 1.0f;
    M2C_FIELD(var_r31_484, f64 *, 0xA0) = (f64) sp30;
    sp20 = 1.0f;
    sp24 = 1.0f;
    M2C_FIELD(var_r31_484, f64 *, 0x20) = (f64) sp18;
    sp8 = 1.0f;
    spC = 1.0f;
    M2C_FIELD(var_r31_484, f64 *, 0x28) = (f64) sp20;
    sp10 = 1.0f;
    sp14 = 1.0f;
    M2C_FIELD(var_r31_484, f64 *, 0x48) = (f64) sp8;
    M2C_FIELD(var_r31_484, f64 *, 0x50) = (f64) sp10;
    M2C_FIELD(var_r31_484, f32 *, 0x3C) = 12.0f;
    M2C_FIELD(var_r31_484, s8 *, 0x45) = 0;
    sp78 = (f64) sp38;
    sp80 = (f64) sp40;
    sp68 = (f64) sp28;
    sp70 = (f64) sp30;
    sp58 = (f64) sp18;
    sp60 = (f64) sp20;
    sp48 = (f64) sp8;
    sp50 = (f64) sp10;
    M2C_FIELD(var_r31_484, f32 *, 0x34) = 1.0f;
    M2C_FIELD(var_r31_484, s32 *, 0xA8) = MKRand_Int(&gViewSeed, 0, 0x1869F);
    M2C_FIELD(var_r31_484, u8 *, 0xAC) = (u8) M2C_FIELD(&gb, u8 *, 0x395);
    return var_r31_484;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'DialogBoxTheme' to
void DialogBox_FreeTheme(DialogBoxTheme *arg0) {
    MKFont *temp_r3_584;
    MKMaterial *temp_r3_589;
    MKMaterial *temp_r3_594;
    MKMaterial *temp_r3_602;
    s32 var_r30_599;
    s32 var_r31_600;

    temp_r3_584 = arg0->unk1C;
    if (temp_r3_584 != NULL) {
        temp_r3_584->Destroy();
    }
    temp_r3_589 = arg0->unk10;
    if (temp_r3_589 != NULL) {
        MKMaterial_Destroy(temp_r3_589);
    }
    temp_r3_594 = arg0->unkC;
    if (temp_r3_594 != NULL) {
        MKMaterial_Destroy(temp_r3_594);
    }
    var_r30_599 = 2;
    var_r31_600 = 8;
    do {
        temp_r3_602 = *(arg0 + var_r31_600);
        if (temp_r3_602 != NULL) {
            MKMaterial_Destroy(temp_r3_602);
        }
        var_r30_599 -= 1;
        var_r31_600 -= 4;
    } while (var_r30_599 >= 0);
    memset(arg0, 0, 0x20U);
}
#endif

#if 0 // DRAFT: function call 'Str_Printf(signed char *, long, const char *, float)' does
s8 *DialogBox_LoadTheme(const char *arg0, const char *arg1, float arg2, float arg3) {
    MKResource *temp_ret_667;
    MKResource *temp_ret_679;
    MKResource *temp_ret_687;
    f32 temp_f30_632;
    f32 var_f1_0;
    s32 var_r29_658;
    s32 var_r31_660;
    s32 var_r3_638;
    s32 var_r6_627;
    s8 *temp_r5_641;
    s8 *var_r28_637;
    s8 *var_r4_636;

    var_f1_0 = arg2;
    var_r6_627 = 0;
    temp_f30_632 = var_f1_0;
    var_r4_636 = themes;
    var_r28_637 = NULL;
    var_r3_638 = 0;
loop_4:
    if ((var_r6_627 < 2) && (var_r28_637 == NULL)) {
        temp_r5_641 = &themes[var_r3_638];
        if ((u32) M2C_FIELD(temp_r5_641, u32 *, 0x1C) == 0U) {
            var_r28_637 = temp_r5_641;
        }
        var_r6_627 += 1;
        var_r3_638 += 0x20;
        goto loop_4;
    }
    if (arg0 != NULL) {
        var_r29_658 = 0;
        var_r31_660 = 0;
        do {
            temp_ret_667 = MKMaterial_Create(Str_Printf((s8 *) (lit_stringBase0 + 0x12), var_r29_658 + 1, arg0, var_f1_0));
            var_f1_0 = M2C_BITWISE(f32, temp_ret_667);
            var_r29_658 += 1;
            var_r28_637[var_r31_660] = temp_ret_667;
            var_r31_660 += 4;
        } while (var_r29_658 < 3);
        temp_ret_679 = MKMaterial_Create(Str_Printf((s8 *) (lit_stringBase0 + 0x25), arg0, var_f1_0));
        M2C_FIELD(var_r28_637, MKResource **, 0xC) = temp_ret_679;
        temp_ret_687 = MKMaterial_Create(Str_Printf((s8 *) (lit_stringBase0 + 0x37), arg0, M2C_BITWISE(f32, temp_ret_679)));
        var_r4_636 = (s8 *) (u32) (u64) temp_ret_687;
        M2C_FIELD(var_r28_637, MKResource **, 0x10) = temp_ret_687;
    }
    M2C_FIELD(var_r28_637, f32 *, 0x14) = temp_f30_632;
    M2C_FIELD(var_r28_637, f32 *, 0x18) = arg3;
    M2C_FIELD(var_r28_637, void **, 0x1C) = ((MKFont *) arg1)->Create(var_r4_636);
    return var_r28_637;
}
#endif

void DialogBox_DeinitModule() {
    s32 var_r29_713;
    s32 var_r31_715;

    var_r29_713 = 0;
    var_r31_715 = 0;
    do {
        DialogBox_FreeTheme((DialogBoxTheme *) &themes[var_r31_715]);
        var_r29_713 += 1;
        var_r31_715 += 0x20;
    } while (var_r29_713 < 2);
    memset(&contexts, 0, 0x6E0U);
    contextCount = 0;
}

void DialogBox_InitModule() {
    contextCount = 0;
    memset(&contexts, 0, 0x6E0U);
    memset(themes, 0, 0x40U);
}

#if 0 // DRAFT: undefined identifier 'DialogBox_BuildLines'
void DialogBox_DrawText(DialogBoxContext *arg0) {
    DialogBoxLine sp2A0;
    s8 spA0;
    Matrix sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    DialogBoxLine *temp_r28_904;
    MKFont *var_r30_810;
    f32 temp_f25_1098;
    f32 temp_f25_800;
    f32 temp_f26_820;
    f32 temp_f27_807;
    f32 temp_f28_808;
    f32 temp_f29_806;
    f32 temp_f30_803;
    f32 temp_f31_805;
    f32 temp_f5_995;
    f32 var_f1_1023;
    f32 var_f1_949;
    f32 var_f25_830;
    f32 var_f27_1103;
    f32 var_f28_935;
    f32 var_f4_792;
    s32 temp_r0_907;
    s32 temp_r26_867;
    s32 temp_r3_1074;
    s32 temp_r3_1097;
    s32 temp_r3_789;
    s32 var_r21_891;
    s32 var_r23_905;
    s32 var_r25_889;
    s32 var_r27_853;
    s32 var_r3_870;
    s32 var_r6_927;
    s8 *var_r3_923;
    s8 *var_r4_1078;
    u32 temp_r21_1155;
    u32 temp_r21_856;
    u8 var_r24_894;

    if ((s8 *) arg0->unk30 != NULL) {
        temp_r3_789 = arg0->unk0;
        if ((u32) temp_r3_789 != 0U) {
            var_f4_792 = M2C_FIELD(temp_r3_789, f32 *, 0x18);
        } else {
            var_f4_792 = 0.0f;
        }
        temp_f25_800 = 2.0f * var_f4_792;
        temp_f30_803 = arg0->unk10 - var_f4_792;
        temp_f31_805 = arg0->unk14 - var_f4_792;
        temp_f29_806 = arg0->unk18 + temp_f25_800;
        temp_f27_807 = arg0->unk34;
        temp_f28_808 = arg0->unk1C + temp_f25_800;
        if ((u32) temp_r3_789 != 0U) {
            var_r30_810 = M2C_FIELD(temp_r3_789, MKFont **, 0x1C);
        } else {
            var_r30_810 = M2C_FIELD(&gb, MKFont **, 0x318);
        }
        temp_f26_820 = temp_f27_807 * var_r30_810->GetHeight();
        var_f25_830 = arg0->unk38;
        var_r27_853 = (s32) ((arg0->unk1C + temp_f25_800) / temp_f26_820);
        temp_r21_856 = (s32) (128.0f * arg0->unk20) | (((s32) (128.0f * arg0->unk24) << 8) | (((s32) (128.0f * arg0->unk2C) << 0x18) | ((s32) (128.0f * arg0->unk28) << 0x10)));
        if (arg0->unkC & 0x70) {
            var_r27_853 -= 1;
        }
        temp_r26_867 = DialogBox_BuildLines(var_r30_810, arg0->unk30, &sp2A0, temp_f29_806, temp_f27_807);
        sp60.SetIdentity();
        var_r3_870 = var_r27_853;
        if ((arg0->unkC & 4) && (temp_r26_867 < var_r27_853)) {
            var_r3_870 = temp_r26_867;
        }
        var_r25_889 = 0;
        var_r21_891 = 0;
        sp60.unk30 = (0.5f * temp_f29_806) + temp_f30_803;
        var_r24_894 = 0;
        sp60.unk38 = 0.0f;
        sp60.unk3C = 1.0f;
        sp60.unk34 = -((0.5f * ((f32) (var_r3_870 - 1) * temp_f26_820)) - ((0.5f * temp_f28_808) + temp_f31_805));
loop_33:
        if ((var_r25_889 < temp_r26_867) && (var_f25_830 >= 1.0f) && ((u8) arg0->unk44 == 0)) {
            temp_r28_904 = &sp2A0 + var_r21_891;
            var_r23_905 = temp_r28_904->unk4;
            temp_r0_907 = (s32) var_f25_830;
            if (var_r23_905 > temp_r0_907) {
                var_r23_905 = temp_r0_907;
                var_r24_894 = 1;
            }
            var_f25_830 -= (f32) var_r23_905;
            if (var_r25_889 >= (s32) arg0->unk40) {
                var_r3_923 = &spA0;
                if (var_r23_905 > 0) {
                    var_r6_927 = var_r23_905;
                    if (var_r24_894 != 0) {
                        var_r6_927 = var_r23_905 - 1;
                    }
                    var_r3_923 = DialogBox_strncpy(var_r3_923, temp_r28_904, 0, var_r6_927);
                }
                var_f28_935 = 0.0f;
                *var_r3_923 = 0;
                if ((s8) (u8) spA0 != 0) {
                    var_f28_935 = temp_f27_807 * var_r30_810->CalcLength(&spA0);
                    if (arg0->unkC & 8) {
                        var_f1_949 = temp_r28_904->unk10;
                    } else {
                        var_f1_949 = temp_f29_806;
                    }
                    var_r30_810->DrawString(&spA0, var_f1_949, temp_f26_820, &sp60, 0, temp_r21_856, temp_f27_807, temp_f27_807, NULL, 1U);
                }
                if (var_r24_894 != 0) {
                    sp20 = var_f28_935;
                    sp24 = 0.0f;
                    sp28 = 0.0f;
                    sp40 = (f64) sp20;
                    sp48 = (f64) sp28;
                    sp60.Translate(&sp60, *((MKVector3 *) &sp40));
                    *DialogBox_strncpy(&spA0, temp_r28_904, var_r23_905 - 1, 1) = 0;
                    sp58 = (f64) M2C_FIELD(arg0, f32 *, 0x28);
                    sp50 = (f64) M2C_FIELD(arg0, f32 *, 0x20);
                    temp_f5_995 = (*(f32 *) ((u8 *) &sp58 + 0x4)) * var_f25_830;
                    (*(f32 *) ((u8 *) &sp58 + 0x4)) = temp_f5_995;
                    if (arg0->unkC & 8) {
                        var_f1_1023 = temp_r28_904->unk10;
                    } else {
                        var_f1_1023 = temp_f29_806;
                    }
                    var_r30_810->DrawString(&spA0, var_f1_1023, temp_f26_820, &sp60, 0, (s32) (128.0f * (f32) sp50) | (((s32) (128.0f * (*(f32 *) ((u8 *) &sp50 + 0x4))) << 8) | (((s32) (128.0f * temp_f5_995) << 0x18) | ((s32) (128.0f * (f32) sp58) << 0x10))), temp_f27_807, temp_f27_807, NULL, 1U);
                }
                sp14 = temp_f26_820;
                sp10 = 0.0f;
                sp18 = 0.0f;
                sp30 = (f64) sp10;
                sp38 = (f64) sp18;
                sp60.Translate(&sp60, *((MKVector3 *) &sp30));
            }
            var_r25_889 += 1;
            var_r21_891 += 0x14;
            if ((s32) (var_r25_889 - arg0->unk40) > var_r27_853) {
                arg0->unk44 = 1;
            }
            goto loop_33;
        }
        if ((var_r25_889 >= temp_r26_867) && (var_r24_894 == 0)) {
            arg0->unk45 = 1;
            temp_r3_1074 = arg0->unkC;
            if (temp_r3_1074 & 0x70) {
                var_r4_1078 = NULL;
                if (temp_r3_1074 & 0x10) {
                    var_r4_1078 = M2C_FIELD(gpTranslation_StringArray, s8 **, 0x14);
                } else if (temp_r3_1074 & 0x20) {
                    var_r4_1078 = M2C_FIELD(gpTranslation_StringArray, s8 **, 0x18);
                } else if (temp_r3_1074 & 0x40) {
                    var_r4_1078 = M2C_FIELD(gpTranslation_StringArray, s8 **, 0x1C);
                }
                temp_r3_1097 = arg0->unk0;
                temp_f25_1098 = var_r30_810->CalcLength(var_r4_1078);
                if ((u32) temp_r3_1097 != 0U) {
                    var_f27_1103 = 1.5f * M2C_FIELD(temp_r3_1097, f32 *, 0x14);
                } else {
                    var_f27_1103 = 0.0f;
                }
                sp60.SetIdentity();
                sp60.unk38 = 0.0f;
                sp60.unk3C = 1.0f;
                sp60.unk34 = -((0.5f * temp_f26_820) - (var_f27_1103 + (arg0->unk14 + arg0->unk1C)));
                sp60.unk30 = -((0.5f * temp_f25_1098) - (var_f27_1103 + (arg0->unk10 + arg0->unk18)));
                temp_r21_1155 = (s32) (128.0f * arg0->unk98) | (((s32) (128.0f * arg0->unk9C) << 8) | (((s32) (128.0f * arg0->unkA4) << 0x18) | ((s32) (128.0f * arg0->unkA0) << 0x10)));
                if (arg0->unkC & 0x10) {
                    var_r30_810->DrawString(M2C_FIELD(gpTranslation_StringArray, s8 **, 0x14), temp_f29_806, temp_f26_820, &sp60, 5, temp_r21_1155, 1.0f, 1.0f, NULL, 1U);
                }
                if (arg0->unkC & 0x20) {
                    var_r30_810->DrawString(M2C_FIELD(gpTranslation_StringArray, s8 **, 0x18), temp_f29_806, temp_f26_820, &sp60, 5, temp_r21_1155, 1.0f, 1.0f, NULL, 1U);
                }
                if (arg0->unkC & 0x40) {
                    var_r30_810->DrawString(M2C_FIELD(gpTranslation_StringArray, s8 **, 0x1C), temp_f29_806, temp_f26_820, &sp60, 5, temp_r21_1155, 1.0f, 1.0f, NULL, 1U);
                }
            }
        }
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'const char *' to
s32 DialogBox_BuildLines(MKFont *arg0, const char *arg1, DialogBoxLine *arg2, float arg3, float arg4) {
    s8 sp8;
    f32 var_f31_1245;
    f32 var_f3_1239;
    s32 var_r20_1240;
    s32 var_r23_1261;
    s32 var_r26_1253;
    s32 var_r28_1251;
    s32 var_r29_1250;
    s32 var_r30_1249;
    s8 *temp_r19_1301;
    s8 *var_r24_1248;
    s8 *var_r25_1247;
    u32 temp_r18_1300;
    u8 temp_r0_1267;
    u8 temp_r4_1293;
    u8 var_r27_1252;
    void *temp_r31_1256;

    var_f3_1239 = 0.0f;
    var_r20_1240 = 0;
    sp8 = 0;
    var_f31_1245 = 0.0f;
    var_r25_1247 = arg1;
    var_r24_1248 = arg1;
    var_r30_1249 = 0;
    var_r29_1250 = 0;
    var_r28_1251 = 0;
    var_r27_1252 = 0;
    var_r26_1253 = 0;
loop_24:
    if ((s8) (u8) *var_r25_1247 != 0) {
        temp_r31_1256 = arg2 + var_r20_1240;
        M2C_FIELD(temp_r31_1256, s8 **, 0) = var_r25_1247;
        M2C_FIELD(temp_r31_1256, s32 *, 0xC) = var_r26_1253;
loop_21:
        if (((s8) (u8) *var_r24_1248 != 0) && (var_f3_1239 < arg3)) {
            var_r23_1261 = 0;
loop_13:
            temp_r4_1293 = (u8) M2C_FIELD(var_r24_1248, s8 *, 0);
            if (((s32) temp_r4_1293 != 0x20) && ((s8) temp_r4_1293 != 0)) {
                if (((s8) temp_r4_1293 == 0x3C) && ((temp_r0_1267 = M2C_FIELD(var_r24_1248, u8 *, 1), var_r27_1252 = 1, (((s8) temp_r0_1267 == 0x50) != 0)) || ((s8) temp_r0_1267 == 0x70)) && ((s32) M2C_FIELD(var_r24_1248, u8 *, 3) == 0x3E)) {
                    var_r26_1253 = (s8) M2C_FIELD(var_r24_1248, u8 *, 2) - 0x30;
                }
                if (var_r27_1252 == 0) {
                    var_r23_1261 += 1;
                }
                if ((s8) temp_r4_1293 == 0x3E) {
                    var_r27_1252 = 0;
                }
                var_r24_1248 += 1;
                goto loop_13;
            }
            temp_r18_1300 = var_r24_1248 - var_r25_1247;
            temp_r19_1301 = &(&sp8)[var_r29_1250];
            strncpy(temp_r19_1301, var_r25_1247, temp_r18_1300);
            temp_r19_1301[temp_r18_1300] = 0;
            var_f3_1239 = arg4 * arg0->CalcLength(&sp8);
            if (var_f3_1239 < arg3) {
                var_r25_1247 = var_r24_1248;
                var_r29_1250 += temp_r18_1300;
                var_r28_1251 += var_r23_1261;
                if ((s8) (u8) M2C_FIELD(var_r24_1248, s8 *, 0) == 0) {
                    M2C_FIELD(temp_r31_1256, s32 *, 8) = var_r29_1250;
                    M2C_FIELD(temp_r31_1256, s32 *, 4) = var_r28_1251;
                    M2C_FIELD(temp_r31_1256, f32 *, 0x10) = (f32) (4.0f + var_f3_1239);
                }
            } else {
                M2C_FIELD(temp_r31_1256, s32 *, 8) = (s32) (var_r29_1250 - 1);
                M2C_FIELD(temp_r31_1256, s32 *, 4) = (s32) (var_r28_1251 - 1);
                M2C_FIELD(temp_r31_1256, f32 *, 0x10) = (f32) (4.0f + var_f31_1245);
            }
            var_f31_1245 = var_f3_1239;
            if ((s32) (u8) *var_r25_1247 == 0x20) {
                (&sp8)[var_r29_1250] = 0x20;
                var_r29_1250 += 1;
                var_r25_1247 += 1;
                (&sp8)[var_r29_1250] = 0;
                var_r24_1248 += 1;
                var_r28_1251 += 1;
            }
            goto loop_21;
        }
        var_f3_1239 = 0.0f;
        var_r24_1248 = var_r25_1247;
        var_r29_1250 = 0;
        var_r28_1251 = 0;
        var_f31_1245 = 0.0f;
        var_r30_1249 += 1;
        var_r20_1240 += 0x14;
        goto loop_24;
    }
    return var_r30_1249;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'char *' to
u8 *DialogBox_strncpy(char *arg0, DialogBoxLine *arg1, int arg2, int arg3) {
    s32 sp18;
    s32 temp_r0_1501;
    s32 temp_r5_1565;
    s32 temp_r5_1576;
    s32 temp_r8_1447;
    s32 temp_r8_1458;
    s32 var_r0_1503;
    s32 var_r0_1528;
    s32 var_r5_0;
    s32 var_r6_0;
    s8 *var_r7_1392;
    u8 *var_r3_1509;
    u8 temp_r0_1512;
    u8 temp_r3_1411;
    u8 temp_r3_1540;
    u8 temp_r3_1601;
    u8 temp_r5_1606;
    u8 temp_r8_1481;
    u8 var_r0_1394;
    u8 var_r9_1485;
    void *var_r4_1388;

    var_r5_0 = arg2;
    var_r6_0 = arg3;
    var_r4_1388 = arg1->unk0;
    M2C_FIELD(arg0, s8 *, 0) = 0x3C;
    var_r7_1392 = arg0 + 4;
    M2C_FIELD(arg0, s8 *, 1) = 0x70;
    var_r0_1394 = 0;
    M2C_FIELD(arg0, s8 *, 2) = (s8) (arg1->unkC + 0x30);
    sp18 = -1;
    M2C_FIELD(arg0, s8 *, 3) = 0x3E;
loop_30:
    temp_r8_1481 = M2C_FIELD(var_r4_1388, u8 *, 0);
    if ((s8) temp_r8_1481 != 0) {
        if ((var_r5_0 > 0) || (var_r0_1394 != 0) || ((s32) M2C_FIELD(var_r4_1388, u8 *, 1) == 0x3C)) {
            if ((s8) temp_r8_1481 == 0x3C) {
                temp_r3_1411 = M2C_FIELD(var_r4_1388, u8 *, 1);
                var_r0_1394 = 1;
                switch ((s8) temp_r3_1411) {        /* switch 1; irregular */
                case 0x2F:                          /* switch 1 */
                    if (sp18 > -1) {
                        sp18 -= 1;
                    }
                    break;
                case 0x63:                          /* switch 1 */
                case 0x43:                          /* switch 1 */
                    if (sp18 < 3) {
                        temp_r8_1447 = sp18 + 1;
                        sp18 = temp_r8_1447;
                        (&sp8[0])[temp_r8_1447] = 2;
                    }
                    break;
                case 0x66:                          /* switch 1 */
                case 0x46:                          /* switch 1 */
                    if (sp18 < 3) {
                        temp_r8_1458 = sp18 + 1;
                        sp18 = temp_r8_1458;
                        (&sp8[0])[temp_r8_1458] = 1;
                    }
                    break;
                }
            }
            if (var_r0_1394 == 0) {
                var_r5_0 -= 1;
            } else {
                *var_r7_1392 = (s8) M2C_FIELD(var_r4_1388, u8 *, 0);
                var_r7_1392 += 1;
            }
            if ((s32) M2C_FIELD(var_r4_1388, u8 *, 0) == 0x3E) {
                var_r0_1394 = 0;
            }
            var_r4_1388 += 1;
            goto loop_30;
        }
    }
    var_r9_1485 = 0;
loop_70:
    temp_r5_1606 = M2C_FIELD(var_r4_1388, u8 *, 0);
    if ((s8) temp_r5_1606 != 0) {
        if ((var_r6_0 <= 0) && (var_r0_1394 == 0)) {
loop_42:
            if (sp18 > -1) {
                var_r0_1528 = (&sp8[0])[sp18];
            } else {
                var_r0_1528 = 0;
            }
            if (var_r0_1528 != 0) {
                if (sp18 > -1) {
                    temp_r0_1501 = sp18 * 4;
                    sp18 -= 1;
                    var_r0_1503 = *(&sp8[0] + temp_r0_1501);
                } else {
                    var_r0_1503 = 0;
                }
                var_r3_1509 = pTags[var_r0_1503];
loop_40:
                if ((var_r3_1509 != NULL) && ((s8) *var_r3_1509 != 0)) {
                    temp_r0_1512 = *var_r3_1509;
                    var_r3_1509 += 1;
                    *var_r7_1392 = (s8) temp_r0_1512;
                    var_r7_1392 += 1;
                    goto loop_40;
                }
                goto loop_42;
            }
        } else {
            if ((s8) temp_r5_1606 == 0x3C) {
                temp_r3_1540 = M2C_FIELD(var_r4_1388, u8 *, 1);
                var_r0_1394 = 1;
                switch ((s8) temp_r3_1540) {        /* switch 2; irregular */
                case 0x2F:                          /* switch 2 */
                    var_r9_1485 = 1;
                    break;
                case 0x63:                          /* switch 2 */
                case 0x43:                          /* switch 2 */
                    if (sp18 < 3) {
                        temp_r5_1565 = sp18 + 1;
                        sp18 = temp_r5_1565;
                        (&sp8[0])[temp_r5_1565] = 2;
                    }
                    break;
                case 0x66:                          /* switch 2 */
                case 0x46:                          /* switch 2 */
                    if (sp18 < 3) {
                        temp_r5_1576 = sp18 + 1;
                        sp18 = temp_r5_1576;
                        (&sp8[0])[temp_r5_1576] = 1;
                    }
                    break;
                }
            }
            if (var_r0_1394 == 0) {
                var_r6_0 -= 1;
            }
            if ((s32) M2C_FIELD(var_r4_1388, u8 *, 0) == 0x3E) {
                var_r0_1394 = 0;
                if ((var_r9_1485 != 0) && (sp18 > -1)) {
                    sp18 -= 1;
                }
                var_r9_1485 = 0;
            }
            temp_r3_1601 = M2C_FIELD(var_r4_1388, u8 *, 0);
            var_r4_1388 += 1;
            *var_r7_1392 = (s8) temp_r3_1601;
            var_r7_1392 += 1;
            goto loop_70;
        }
    }
    *var_r7_1392 = 0;
    return (u8 *) var_r7_1392;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'const char *' to
void DialogBox_ColorButtons(const char *arg0, char *arg1, int arg2, int arg3) {
    s32 var_r29_1624;
    s8 *var_r27_1625;
    s8 *var_r28_1626;
    s8 *var_r28_1648;
    s8 *var_r28_1735;
    s8 *var_r28_1744;
    s8 *var_r3_1640;
    s8 *var_r3_1727;
    u8 *var_r4_1704;
    u8 *var_r4_1746;
    u8 temp_r0_1654;
    u8 temp_r0_1659;
    u8 temp_r0_1691;
    u8 temp_r3_1696;
    u8 temp_r3_1706;
    u8 temp_r3_1737;
    u8 temp_r3_1748;
    u8 temp_r4_1642;
    u8 temp_r4_1729;
    u8 var_r30_1628;
    u8 var_r31_1627;

    var_r29_1624 = arg2;
    var_r27_1625 = arg0;
    var_r28_1626 = arg1;
    var_r31_1627 = 0;
    var_r30_1628 = 0;
    if (var_r29_1624 != 0) {
        var_r3_1640 = Str_Printf((s8 *) (lit_stringBase0 + 0x49), &buttonColorBright, lit_stringBase0, M2C_FIELD(&buttonColorBright, f32 *, 0), M2C_FIELD(&buttonColorBright, f32 *, 4), M2C_FIELD(&buttonColorBright, f32 *, 8), M2C_FIELD(&buttonColorBright, f32 *, 0xC));
        do {
            temp_r4_1642 = (u8) *var_r3_1640;
            var_r3_1640 += 1;
            *var_r28_1626 = (s8) temp_r4_1642;
            var_r28_1626 += 1;
        } while ((s8) temp_r4_1642 != 0);
        var_r28_1648 = var_r28_1626 - 1;
loop_22:
        temp_r3_1696 = (u8) M2C_FIELD(var_r27_1625, s8 *, 0);
        if (((s8) temp_r3_1696 != 0) && (var_r29_1624 != 0)) {
            if ((s8) temp_r3_1696 == 0x3C) {
                temp_r0_1654 = M2C_FIELD(var_r27_1625, u8 *, 1);
                var_r31_1627 = 1;
                switch ((s8) temp_r0_1654) {        /* irregular */
                case 0x2F:
                    temp_r0_1659 = M2C_FIELD(var_r27_1625, u8 *, 2);
                    if ((s8) temp_r0_1659 != 0x66) {
                        if ((s8) temp_r0_1659 < 0x66) {
                            if ((s8) temp_r0_1659 != 0x46) {

                            } else {
                                goto block_10;
                            }
                        }
                    } else {
block_10:
                        var_r30_1628 = 0;
                    }
                    break;
                case 0x66:
                case 0x46:
                    var_r30_1628 = 1;
                    break;
                }
            }
            if ((var_r31_1627 == 0) && (var_r30_1628 != 0)) {
                var_r29_1624 -= 1;
            }
            if ((s8) temp_r3_1696 == 0x3E) {
                var_r31_1627 = 0;
            }
            temp_r0_1691 = (u8) M2C_FIELD(var_r27_1625, s8 *, 0);
            var_r27_1625 += 1;
            *var_r28_1648 = (s8) temp_r0_1691;
            var_r28_1648 += 1;
            goto loop_22;
        }
        var_r4_1704 = lit_stringBase0 + 8;
        do {
            temp_r3_1706 = *var_r4_1704;
            var_r4_1704 += 1;
            *var_r28_1648 = (s8) temp_r3_1706;
            var_r28_1648 += 1;
        } while ((s8) temp_r3_1706 != 0);
        var_r28_1626 = var_r28_1648 - 1;
    }
    if ((s8) (u8) *var_r27_1625 != 0) {
        var_r3_1727 = Str_Printf((s8 *) (lit_stringBase0 + 0x49), &buttonColorDull, lit_stringBase0, M2C_FIELD(&buttonColorDull, f32 *, 0), M2C_FIELD(&buttonColorDull, f32 *, 4), M2C_FIELD(&buttonColorDull, f32 *, 8), M2C_FIELD(&buttonColorDull, f32 *, 0xC));
        do {
            temp_r4_1729 = (u8) *var_r3_1727;
            var_r3_1727 += 1;
            *var_r28_1626 = (s8) temp_r4_1729;
            var_r28_1626 += 1;
        } while ((s8) temp_r4_1729 != 0);
        var_r28_1735 = var_r28_1626 - 1;
        do {
            temp_r3_1737 = (u8) *var_r27_1625;
            var_r27_1625 += 1;
            *var_r28_1735 = (s8) temp_r3_1737;
            var_r28_1735 += 1;
        } while ((s8) temp_r3_1737 != 0);
        var_r28_1744 = var_r28_1735 - 1;
        var_r4_1746 = lit_stringBase0 + 8;
        do {
            temp_r3_1748 = *var_r4_1746;
            var_r4_1746 += 1;
            *var_r28_1744 = (s8) temp_r3_1748;
            var_r28_1744 += 1;
        } while ((s8) temp_r3_1748 != 0);
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'signed char *' to
void DialogBox_DrawTab(DialogBoxContext *arg0) {
    Matrix sp10;
    f32 temp_f27_1807;
    f32 temp_f28_1805;
    f32 temp_f29_1803;
    f32 temp_f2_1792;
    f32 temp_f30_1802;
    f32 temp_f31_1796;
    f32 temp_f5_1793;
    s32 temp_r3_1791;

    if (arg0->unkC & 1) {
        if ((u8 *) arg0->unk58 == NULL) {
            return;
        }
        temp_r3_1791 = arg0->unk0;
        temp_f2_1792 = arg0->unk10;
        temp_f5_1793 = M2C_FIELD(temp_r3_1791, f32 *, 0x18);
        temp_f31_1796 = temp_f2_1792 - temp_f5_1793;
        temp_f30_1802 = temp_f5_1793 + (temp_f2_1792 + arg0->unk18);
        temp_f29_1803 = (arg0->unk14 - temp_f5_1793) - 32.0f;
        temp_f28_1805 = (2.0f * temp_f5_1793) + arg0->unk5C;
        temp_f27_1807 = ((MKFont *) (M2C_FIELD(temp_r3_1791, MKFont **, 0x1C)))->GetHeight();
        sp10.SetIdentity();
        if (arg0->unkC & 2) {
            sp10.unk38 = 0.0f;
            sp10.unk30 = -((temp_f28_1805 * 0.5f) - temp_f30_1802);
            sp10.unk34 = (temp_f27_1807 * 0.5f) + temp_f29_1803;
            sp10.unk3C = 1.0f;
        } else {
            sp10.unk38 = 0.0f;
            sp10.unk30 = (temp_f28_1805 * 0.5f) + temp_f31_1796;
            sp10.unk34 = (temp_f27_1807 * 0.5f) + temp_f29_1803;
            sp10.unk3C = 1.0f;
        }
        ((MKFont *) (M2C_FIELD(arg0->unk0, MKFont **, 0x1C)))->DrawString((s8 *) arg0->unk58, temp_f28_1805, temp_f27_1807, &sp10, 5, (s32) (128.0f * arg0->unk48) | (((s32) (128.0f * arg0->unk4C) << 8) | (((s32) (128.0f * arg0->unk54) << 0x18) | ((s32) (128.0f * arg0->unk50) << 0x10))), 1.0f, 1.0f, NULL, 1U);
    }
}
#endif

void DialogBox_DrawBorder(DialogBoxContext *arg0) {
    f32 temp_f24_1942;
    f32 temp_f25_1925;
    f32 temp_f26_1936;
    f32 temp_f27_1930;
    f32 temp_f27_1963;
    f32 temp_f28_1938;
    f32 temp_f28_1946;
    f32 temp_f29_1935;
    f32 temp_f30_1931;
    f32 temp_f31_1927;
    f32 temp_f3_2000;
    f32 temp_f3_2017;
    f32 temp_f4_2034;
    f32 temp_f4_2051;

    temp_f25_1925 = 1.5f * M2C_FIELD(arg0->unk0, f32 *, 0x14);
    temp_f31_1927 = arg0->unk10;
    temp_f27_1930 = 0.5f * temp_f25_1925;
    temp_f30_1931 = arg0->unk14;
    temp_f29_1935 = temp_f30_1931 - temp_f27_1930;
    temp_f26_1936 = temp_f31_1927 - temp_f27_1930;
    temp_f28_1938 = temp_f31_1927 + arg0->unk18;
    temp_f24_1942 = temp_f30_1931 + arg0->unk1C;
    Hud_DrawIcon(0, 4, temp_f26_1936, temp_f29_1935, temp_f25_1925, temp_f25_1925, *((MKVector4 *) &arg0->unk98), 0.0f, 0.0f, 1.0f, 1.0f, 0U, 0U, Matrix::identity);
    temp_f28_1946 = temp_f28_1938 + temp_f27_1930;
    Hud_DrawIcon(0, 5, temp_f28_1946, temp_f29_1935, temp_f25_1925, temp_f25_1925, *((MKVector4 *) &arg0->unk98), 0.0f, 0.0f, 1.0f, 1.0f, 0U, 0U, Matrix::identity);
    temp_f27_1963 = temp_f24_1942 + temp_f27_1930;
    Hud_DrawIcon(0, 6, temp_f28_1946, temp_f27_1963, temp_f25_1925, temp_f25_1925, *((MKVector4 *) &arg0->unk98), 0.0f, 0.0f, 1.0f, 1.0f, 0U, 0U, Matrix::identity);
    Hud_DrawIcon(0, 7, temp_f26_1936, temp_f27_1963, temp_f25_1925, temp_f25_1925, *((MKVector4 *) &arg0->unk98), 0.0f, 0.0f, 1.0f, 1.0f, 0U, 0U, Matrix::identity);
    temp_f3_2000 = arg0->unk18;
    Hud_DrawIcon(0, 9, (0.5f * temp_f3_2000) + temp_f31_1927, temp_f29_1935, temp_f3_2000, temp_f25_1925, *((MKVector4 *) &arg0->unk98), 0.0f, 0.0f, 1.0f, 1.0f, 0U, 0U, Matrix::identity);
    temp_f3_2017 = arg0->unk18;
    Hud_DrawIcon(0, 0xA, (0.5f * temp_f3_2017) + temp_f31_1927, temp_f27_1963, temp_f3_2017, temp_f25_1925, *((MKVector4 *) &arg0->unk98), 0.0f, 0.0f, 1.0f, 1.0f, 0U, 0U, Matrix::identity);
    temp_f4_2034 = arg0->unk1C;
    Hud_DrawIcon(0, 0xB, temp_f26_1936, (0.5f * temp_f4_2034) + temp_f30_1931, temp_f25_1925, temp_f4_2034, *((MKVector4 *) &arg0->unk98), 0.0f, 0.0f, 1.0f, 1.0f, 0U, 0U, Matrix::identity);
    temp_f4_2051 = arg0->unk1C;
    Hud_DrawIcon(0, 0xC, temp_f28_1946, (0.5f * temp_f4_2051) + temp_f30_1931, temp_f25_1925, temp_f4_2051, *((MKVector4 *) &arg0->unk98), 0.0f, 0.0f, 1.0f, 1.0f, 0U, 0U, Matrix::identity);
}

#if 0 // DRAFT: undefined identifier 'DialogBox_DrawTile'
void DialogBox_DrawBackground(DialogBoxContext *arg0) {
    MKMaterial *temp_r3_2103;
    f32 temp_f28_2127;
    f32 temp_f29_2126;
    f32 temp_f2_2122;
    f32 temp_f30_2125;
    f32 temp_f31_2124;
    f32 temp_f3_2114;
    f32 temp_f4_2116;
    f32 temp_f7_2132;
    s32 temp_r4_2120;

    temp_r3_2103 = arg0->unk80;
    if (temp_r3_2103 != NULL) {
        MKMaterial_SetMaterial(temp_r3_2103);
    } else {
        MKMaterial_SetMaterial(M2C_FIELD(&gb, MKMaterial **, 0x328));
    }
    temp_f3_2114 = arg0->unk10;
    temp_f4_2116 = arg0->unk14;
    temp_r4_2120 = arg0->unkC;
    temp_f2_2122 = M2C_FIELD(arg0->unk0, f32 *, 0x14);
    temp_f31_2124 = temp_f3_2114 - temp_f2_2122;
    temp_f30_2125 = temp_f4_2116 - temp_f2_2122;
    temp_f29_2126 = temp_f2_2122 + (temp_f3_2114 + arg0->unk18);
    temp_f28_2127 = temp_f2_2122 + (temp_f4_2116 + arg0->unk1C);
    if (temp_r4_2120 & 1) {
        temp_f7_2132 = (2.0f * temp_f2_2122) + arg0->unk5C;
        if (temp_r4_2120 & 2) {
            DialogBox_DrawTile(temp_f29_2126 - temp_f7_2132, temp_f30_2125 - 32.0f, temp_f29_2126, temp_f30_2125, arg0->unk70, arg0->unk84, arg0->unk88, arg0->unk8C, arg0->unk90, 0);
        } else {
            DialogBox_DrawTile(temp_f31_2124, temp_f30_2125 - 32.0f, temp_f31_2124 + temp_f7_2132, temp_f30_2125, arg0->unk70, arg0->unk84, arg0->unk88, arg0->unk8C, arg0->unk90, 0);
        }
    }
    DialogBox_DrawTile(temp_f31_2124, temp_f30_2125, temp_f29_2126, temp_f28_2127, arg0->unk70, arg0->unk84, arg0->unk88, arg0->unk8C, arg0->unk90, 0);
}
#endif

void DialogBox_DrawTile(float arg0, float arg1, float arg2, float arg3, const MKVector4 &arg4, float arg5, float arg6, float arg7, float arg8, int arg9) {
    MKPrimitive(0xC, 1);
    MKBegin(4);
    MKSetColorV(arg4);
    switch (arg9) {                                 /* irregular */
    case 0:
        MKSetTexCoord1F(arg5, arg6);
        MKSetPositionF(arg0, arg1, 0.0f);
        MKSetTexCoord1F(arg7, arg6);
        MKSetPositionF(arg2, arg1, 0.0f);
        MKSetTexCoord1F(arg5, arg8);
        MKSetPositionF(arg0, arg3, 0.0f);
        MKSetTexCoord1F(arg7, arg8);
        MKSetPositionF(arg2, arg3, 0.0f);
        break;
    case 1:
        MKSetTexCoord1F(arg5, arg6);
        MKSetPositionF(arg2, arg1, 0.0f);
        MKSetTexCoord1F(arg7, arg6);
        MKSetPositionF(arg2, arg3, 0.0f);
        MKSetTexCoord1F(arg5, arg8);
        MKSetPositionF(arg0, arg1, 0.0f);
        MKSetTexCoord1F(arg7, arg8);
        MKSetPositionF(arg0, arg3, 0.0f);
        break;
    case 2:
        MKSetTexCoord1F(arg5, arg6);
        MKSetPositionF(arg2, arg3, 0.0f);
        MKSetTexCoord1F(arg7, arg6);
        MKSetPositionF(arg0, arg3, 0.0f);
        MKSetTexCoord1F(arg5, arg8);
        MKSetPositionF(arg2, arg1, 0.0f);
        MKSetTexCoord1F(arg7, arg8);
        MKSetPositionF(arg0, arg1, 0.0f);
        break;
    case 3:
        MKSetTexCoord1F(arg5, arg6);
        MKSetPositionF(arg0, arg3, 0.0f);
        MKSetTexCoord1F(arg7, arg6);
        MKSetPositionF(arg0, arg1, 0.0f);
        MKSetTexCoord1F(arg5, arg8);
        MKSetPositionF(arg2, arg3, 0.0f);
        MKSetTexCoord1F(arg7, arg8);
        MKSetPositionF(arg2, arg1, 0.0f);
        break;
    }
    MKEnd();
    MKEndPrimitive();
}

#if 0 // DRAFT: undefined identifier 'buttonColorBright'
void DialogBox_cpp::__sinit() {
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;

    sp18 = 1.0f;
    sp1C = 1.0f;
    sp8 = 0.5f;
    spC = 0.5f;
    sp20 = 1.0f;
    sp24 = 1.0f;
    sp10 = 0.5f;
    sp14 = 1.0f;
    M2C_FIELD(&buttonColorBright, f64 *, 0) = (f64) sp18;
    M2C_FIELD(&buttonColorDull, f64 *, 0) = (f64) sp8;
    M2C_FIELD(&buttonColorBright, f64 *, 8) = (f64) sp20;
    M2C_FIELD(&buttonColorDull, f64 *, 8) = (f64) sp10;
}
#endif
