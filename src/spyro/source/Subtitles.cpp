#include "spyro/source/Subtitles.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "common/Source/Texture.h"
#include "spyro/source/CutsceneObject.h"
#include "spyro/source/CutsceneSystem.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/GameVideo.h"
#include "spyro/source/KDStateMachine.h"
#include "spyro/source/Level.h"
#include "common/Source/FileSys.h"
#include "common/Source/Str.h"
#include "common/gc/MKMaterial_GC.h"
#include "common/gc/MKPrimitive_GC.h"
#include "spyro/source/GameLanguage.h"
#include <m2c_macros.h>

M2C_UNK free(void *);                               /* extern */
void *malloc(s32);                                  /* extern */
s32 stricmp(s32, s8 *);                             /* extern */
extern s32 gDisplay;
extern M2C_UNK gb;
static MKHeap sub;                                  /* type too large by 0x98 */

void Subtitles_Draw() {
    f64 sp20;
    f64 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f28_57;
    f32 temp_f2_28;
    s32 var_r27_37;
    s32 var_r31_39;

    if ((u8) M2C_FIELD(&sub, u8 *, 0x84) != 0) {
        temp_f2_28 = M2C_BITWISE(f32, sub.unkC);
        if (temp_f2_28 > 0.0f) {
            sp14 = temp_f2_28;
            var_r27_37 = 0;
            sp10 = 1.0f;
            var_r31_39 = 0;
            sp8 = 1.0f;
            spC = 1.0f;
            sp20 = (f64) sp10;
            sp18 = (f64) sp8;
            do {
                temp_f28_57 = ((f32) var_r27_37 * 256.0f) + 64.0f;
                MKMaterial_SetMaterial(M2C_FIELD((&sub + var_r31_39), MKMaterial **, 0x68));
                MKSetBaseColorV(MKVector4::one);
                MKPrimitive(0xC, 0x101);
                MKBegin(4);
                MKSetColorV(*((MKVector4 *) &sp18));
                MKSetTexCoord1F(0.0f, 0.0f);
                MKSetPositionF(temp_f28_57, 128.0f, 0.0f);
                MKSetTexCoord1F(1.0f, 0.0f);
                MKSetPositionF(temp_f28_57 + 256.0f, 128.0f, 0.0f);
                MKSetTexCoord1F(0.0f, 1.0f);
                MKSetPositionF(temp_f28_57, 384.0f, 0.0f);
                MKSetTexCoord1F(1.0f, 1.0f);
                MKSetPositionF(temp_f28_57 + 256.0f, 384.0f, 0.0f);
                MKEnd();
                MKEndPrimitive();
                var_r27_37 += 1;
                var_r31_39 += 4;
            } while (var_r27_37 < 2);
        }
    }
}

#if 0 // DRAFT: illegal explicit conversion from 'MKHeap *' to
void Subtitles_Update() {
    f32 temp_f0_218;
    f32 temp_f1_147;
    f32 temp_f1_188;
    f32 temp_f1_246;
    f32 temp_f1_292;
    f32 temp_f1_320;
    f32 var_f0_139;
    f32 var_f0_179;
    f32 var_f0_208;
    f32 var_f1_260;
    f32 var_f2_235;
    s32 var_r5_155;

    if ((u8) M2C_FIELD(&sub, u8 *, 0x84) != 0) {
        if ((u32) sub.unk4 != 0U) {
            if ((s32) gDisplay == 1) {
                var_f0_139 = 60.0f;
            } else {
                var_f0_139 = 50.0f;
            }
            temp_f1_147 = M2C_BITWISE(f32, sub.unk0) - (1.0f / var_f0_139);
            sub.unk0 = temp_f1_147;
            M2C_ERROR(/* unknown instruction: cror 0x2, 0x0, 0x2 */);
            if (temp_f1_147 == 0.0f) {
                sub.unk4 = 0;
                var_r5_155 = 5;
                if ((s32) sub.unk8 == 0) {
                    var_r5_155 = 9;
                }
                ((CutsceneSystem *) (M2C_FIELD(&gb, CutsceneSystem **, 0xC)))->SetCustomSubtitle(NULL, var_r5_155, sub.unk8 == 1);
            }
        } else if ((s32) sub.unk8 == 2) {
            if ((s32) gDisplay == 1) {
                var_f0_179 = 60.0f;
            } else {
                var_f0_179 = 50.0f;
            }
            temp_f1_188 = M2C_BITWISE(f32, sub.unk0) - (1.0f / var_f0_179);
            sub.unk0 = temp_f1_188;
            M2C_ERROR(/* unknown instruction: cror 0x2, 0x0, 0x2 */);
            if (temp_f1_188 == 0.0f) {
                sub.unk8 = 0;
                M2C_FIELD(&sub, u8 *, 0x10) = 0U;
                M2C_FIELD(&sub, u8 *, 0x11) = 1U;
            }
        }
        if ((u8) M2C_FIELD(&sub, u8 *, 0x10) != 0) {
            if ((s32) gDisplay == 1) {
                var_f0_208 = 60.0f;
            } else {
                var_f0_208 = 50.0f;
            }
            temp_f0_218 = M2C_BITWISE(f32, sub.unkC) + (1.0f / var_f0_208);
            sub.unkC = temp_f0_218;
            M2C_ERROR(/* unknown instruction: cror 0x2, 0x1, 0x2 */);
            if (temp_f0_218 == 1.0f) {
                sub.unkC = 1.0f;
                M2C_FIELD(&sub, u8 *, 0x10) = 0U;
            }
        } else if ((u8) M2C_FIELD(&sub, u8 *, 0x11) != 0) {
            if ((s32) gDisplay == 1) {
                var_f2_235 = 60.0f;
            } else {
                var_f2_235 = 50.0f;
            }
            temp_f1_246 = M2C_BITWISE(f32, sub.unkC) - (1.0f / var_f2_235);
            sub.unkC = temp_f1_246;
            M2C_ERROR(/* unknown instruction: cror 0x2, 0x0, 0x2 */);
            if (temp_f1_246 == 0.0f) {
                sub.unkC = 0.0f;
                M2C_FIELD(&sub, u8 *, 0x10) = 0U;
                M2C_FIELD(&sub, u8 *, 0x11) = 0U;
            }
        }
        if ((s32) gDisplay == 1) {
            var_f1_260 = 60.0f;
        } else {
            var_f1_260 = 50.0f;
        }
        sub.unk70 = M2C_BITWISE(f32, sub.unk70) + (1.0f / var_f1_260);
loop_38:
        if (((u32) sub.unk64 != 0) && (((MKIniLine *) sub.unk64)->GetFloat(0) <= M2C_BITWISE(f32, sub.unk70))) {
            if (((MKIniLine *) sub.unk64)->IsField("subtitle") != 0) {
                sub.unk4 = Subtitles_GetText(((MKIniLine *) sub.unk64)->GetString(2), (int *) &sub.unk80);
                temp_f1_292 = ((MKIniLine *) sub.unk64)->GetFloat(1);
                sub.unk8 = 0;
                sub.unk0 = temp_f1_292;
                ((CutsceneSystem *) (M2C_FIELD(&gb, CutsceneSystem **, 0xC)))->SetCustomSubtitle((s8 *) sub.unk4, 9, 0U);
            } else if (((MKIniLine *) sub.unk64)->IsField("credit") != 0) {
                sub.unk4 = Subtitles_GetText(((MKIniLine *) sub.unk64)->GetString(2), (int *) &sub.unk80);
                temp_f1_320 = ((MKIniLine *) sub.unk64)->GetFloat(1);
                sub.unk8 = 1;
                sub.unk0 = temp_f1_320;
                ((CutsceneSystem *) (M2C_FIELD(&gb, CutsceneSystem **, 0xC)))->SetCustomSubtitle((s8 *) sub.unk4, 5, 1U);
            } else if (((MKIniLine *) sub.unk64)->IsField("logo") != 0) {
                sub.unk4 = 0;
                sub.unk0 = ((MKIniLine *) sub.unk64)->GetFloat(1);
                sub.unk8 = 2;
                M2C_FIELD(&sub, u8 *, 0x10) = 1U;
                M2C_FIELD(&sub, u8 *, 0x11) = 0U;
                sub.unkC = 0.0f;
            }
            sub.unk64 = ((MKIni *) (M2C_FIELD(sub.unk64, MKIni **, 0xC)))->GetNextLine((MKIniLine *) sub.unk64);
            goto loop_38;
        }
    }
}
#endif

#if 0 // DRAFT: pointer/array required
s8 *Subtitles_GetText(const char *arg0, int *arg1) {
    s32 var_r29_391;
    s32 var_r29_413;
    s32 var_r31_392;
    s32 var_r31_414;

    var_r29_391 = *arg1 + 1;
    var_r31_392 = var_r29_391 * 8;
loop_4:
    if (var_r29_391 >= M2C_BITWISE(s32, sub.unk7C)) {
        var_r29_413 = 0;
        var_r31_414 = 0;
loop_9:
        if (var_r29_413 >= (s32) *arg1) {
            return NULL;
        }
        if (stricmp(*(M2C_BITWISE(s32, sub.unk78) + var_r31_414), arg0) == 0) {
            *arg1 = var_r29_413;
            return M2C_FIELD((M2C_BITWISE(s32, sub.unk78) + var_r31_414), s8 **, 4);
        }
        var_r29_413 += 1;
        var_r31_414 += 8;
        goto loop_9;
    }
    if (stricmp(*(M2C_BITWISE(s32, sub.unk78) + var_r31_392), arg0) == 0) {
        *arg1 = var_r29_391;
        return M2C_FIELD((M2C_BITWISE(s32, sub.unk78) + var_r31_392), s8 **, 4);
    }
    var_r29_391 += 1;
    var_r31_392 += 8;
    goto loop_4;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'float' to
void Subtitles_Deinit() {
    MKHeap *temp_r3_486;
    MKHeap *temp_r3_502;
    MKMaterial *temp_r3_462;
    f32 temp_r29_485;
    f32 temp_r29_501;
    s32 var_r27_457;
    s32 var_r30_456;
    void *temp_r3_460;

    if ((u8) M2C_FIELD(&sub, u8 *, 0x84) != 0) {
        var_r30_456 = 0;
        var_r27_457 = 0;
        do {
            temp_r3_460 = &sub + var_r30_456;
            temp_r3_462 = M2C_FIELD(temp_r3_460, MKMaterial **, 0x68);
            if (temp_r3_462 != NULL) {
                MKMaterial_Destroy(temp_r3_462);
                M2C_FIELD(temp_r3_460, MKMaterial **, 0x68) = NULL;
            }
            var_r27_457 += 1;
            var_r30_456 += 4;
        } while (var_r27_457 < 2);
        sub.unk7C = 0.0f;
        ((CutsceneSystem *) (M2C_FIELD(&gb, CutsceneSystem **, 0xC)))->SetCustomSubtitle(NULL, 9, 0U);
        temp_r29_485 = sub.unk78;
        temp_r3_486 = sub.Current();
        if (temp_r3_486 != NULL) {
            ((MKHeap *) (temp_r3_486->Current()))->Free(M2C_BITWISE(void *, temp_r29_485), NULL, 0);
        } else {
            free(M2C_BITWISE(void *, temp_r29_485));
        }
        temp_r29_501 = sub.unk74;
        temp_r3_502 = sub.Current();
        if (temp_r3_502 != NULL) {
            ((MKHeap *) (temp_r3_502->Current()))->Free(M2C_BITWISE(void *, temp_r29_501), NULL, 0);
        } else {
            free(M2C_BITWISE(void *, temp_r29_501));
        }
        ((MKIni *) &sub.unk14)->Deinit();
        M2C_FIELD(&sub, u8 *, 0x84) = 0U;
        sub.unk64 = 0;
    }
}
#endif

#if 0 // DRAFT: function call 'MKArchive_Exists(signed char *, int)' does not match
void Subtitles_Init(const char *arg0) {
    s32 sp8;
    MKHeap *temp_r3_647;
    MKHeap *temp_r3_709;
    f32 temp_r30_674;
    f32 var_r5_677;
    f32 var_r6_726;
    f32 var_r7_727;
    s32 temp_r27_708;
    s32 temp_r28_646;
    s32 var_ctr_591;
    s32 var_r29_672;
    s32 var_r3_642;
    s32 var_r4_581;
    s8 *temp_r3_639;
    s8 *var_r3_666;
    s8 var_r4_729;
    u32 temp_r3_567;
    u8 temp_r0_680;
    u8 temp_r0_732;
    u8 temp_r0_763;
    u8 temp_r3_548;
    void *temp_r3_593;
    void *var_r3_716;
    void *var_r5_655;

    Subtitles_Deinit();
    temp_r3_548 = MKArchive_Exists(Str_Printf("%s.ini.bni", arg0), NULL);
    if (temp_r3_548 != 0) {
        ((MKHeap *) temp_r3_548)->ActivateTempMemOverride();
        ((MKIni *) &sub.unk14)->Init(Str_Printf("%s.ini", arg0), 0, NULL);
        temp_r3_567 = ((MKIni *) &sub.unk14)->GetFirstLine();
        sub.unk64 = temp_r3_567;
        var_r4_581 = 0;
        sub.unk64 = ((MKIni *) (M2C_FIELD(temp_r3_567, MKIni **, 0xC)))->GetSubLine((MKIniLine *) temp_r3_567);
        sub.unk70 = 0.0f;
        sub.unk4 = 0;
        sub.unk80 = nanf;
        M2C_FIELD(&sub, s8 *, 0x84) = 1;
        sub.unk8 = 0;
        M2C_FIELD(&sub, s8 *, 0x10) = 0;
        M2C_FIELD(&sub, s8 *, 0x11) = 0;
        sub.unkC = 0.0f;
        var_ctr_591 = 2;
        do {
            temp_r3_593 = &sub + var_r4_581;
            var_r4_581 += 4;
            M2C_FIELD(temp_r3_593, s32 *, 0x68) = 0;
            var_ctr_591 -= 1;
        } while (var_ctr_591 != 0);
        sub.unk7C = 0.0f;
        if (((MKIniLine *) sub.unk64)->IsField("preload") != 0) {
            sub.unk68 = MKMaterial_Create("ui_logo1");
            sub.unk6C = M2C_BITWISE(f32, MKMaterial_Create("ui_logo2"));
            sub.unk7C = 3e-45f;
            sub.unk64 = ((MKIni *) (M2C_FIELD(sub.unk64, MKIni **, 0xC)))->GetNextLine((MKIniLine *) sub.unk64);
        }
        sp8 = 0;
        GameLanguage_GetCode(-1);
        temp_r3_639 = Str_Printf("%s%s.sub", arg0, M2C_ERROR(/* Read from unset register $r3 */), "subtitle");
        var_r3_642 = MKArchive_Exists(temp_r3_639, (int *) &sp8);
        if ((u8) var_r3_642 != 0) {
            temp_r28_646 = sp8 + 1;
            temp_r3_647 = ((MKHeap *) sp8)->Current();
            if (temp_r3_647 != NULL) {
                var_r5_655 = ((MKHeap *) (temp_r3_647->Current()))->Alloc(temp_r28_646, NULL, 0);
            } else {
                var_r5_655 = malloc(temp_r28_646);
            }
            var_r3_666 = MKArchive_Load(temp_r3_639, NULL, var_r5_655, sp8 + 1);
            sub.unk74 = M2C_BITWISE(f32, var_r3_666);
            var_r29_672 = 0;
            var_r3_666[sp8] = 0;
            temp_r30_674 = sub.unk74;
            sub.unk7C = 0.0f;
            var_r5_677 = temp_r30_674;
loop_18:
            if ((s32) (M2C_BITWISE(s32, var_r5_677) - M2C_BITWISE(s32, temp_r30_674)) < sp8) {
                temp_r0_680 = *var_r5_677;
                switch ((s8) temp_r0_680) {         /* switch 1; irregular */
                case 13:                            /* switch 1 */
                case 10:                            /* switch 1 */
                    var_r29_672 = 0;
                    break;
                case 32:                            /* switch 1 */
                case 9:                             /* switch 1 */
                    var_r29_672 += 1;
                    if (var_r29_672 == 1) {
                        var_r3_666 = M2C_BITWISE(s8 *, sub.unk7C);
                        sub.unk7C = M2C_BITWISE(f32, (var_r3_666 + 1));
                    }
                    break;
                }
                var_r5_677 = M2C_BITWISE(f32, (M2C_BITWISE(s32, var_r5_677) + 1));
                goto loop_18;
            }
            temp_r27_708 = M2C_BITWISE(s32, sub.unk7C) * 8;
            temp_r3_709 = ((MKHeap *) var_r3_666)->Current();
            if (temp_r3_709 != NULL) {
                var_r3_716 = ((MKHeap *) (temp_r3_709->Current()))->Alloc(temp_r27_708, NULL, 0);
            } else {
                var_r3_716 = malloc(temp_r27_708);
            }
            sub.unk7C = 0.0f;
            var_r6_726 = sub.unk74;
            var_r7_727 = 0.0f;
            sub.unk78 = M2C_BITWISE(f32, var_r3_716);
            var_r4_729 = 0;
loop_38:
            var_r3_642 = M2C_BITWISE(s32, var_r6_726) - M2C_BITWISE(s32, temp_r30_674);
            if (var_r3_642 < sp8) {
                temp_r0_732 = M2C_FIELD(var_r6_726, u8 *, 0);
                switch ((s8) temp_r0_732) {         /* switch 2; irregular */
                case 13:                            /* switch 2 */
                case 10:                            /* switch 2 */
                    var_r29_672 = 0;
                    M2C_FIELD(var_r6_726, u8 *, 0) = 0U;
                    break;
                case 32:                            /* switch 2 */
                case 9:                             /* switch 2 */
                    var_r29_672 += 1;
                    if (var_r29_672 == 1) {
                        M2C_FIELD(var_r6_726, s8 *, -2) = 0;
                        var_r6_726 = M2C_BITWISE(f32, (M2C_BITWISE(s32, var_r6_726) + 1));
                        *(M2C_BITWISE(s32, sub.unk78) + (M2C_BITWISE(s32, sub.unk7C) * 8)) = var_r7_727;
loop_31:
                        temp_r0_763 = *var_r6_726;
                        if ((s8) temp_r0_763 == 0x20) {
block_30:
                            var_r6_726 = M2C_BITWISE(f32, (M2C_BITWISE(s32, var_r6_726) + 1));
                            goto loop_31;
                        }
                        if ((s8) temp_r0_763 == 9) {
                            goto block_30;
                        }
                        *(M2C_BITWISE(s32, sub.unk78) + ((M2C_BITWISE(s32, sub.unk7C) * 8) + 4)) = var_r6_726;
                        sub.unk7C = M2C_BITWISE(f32, (M2C_BITWISE(s32, sub.unk7C) + 1));
                    }
                    break;
                default:                            /* switch 2 */
                    if (var_r4_729 == 0) {
                        var_r7_727 = var_r6_726;
                    }
                    break;
                }
                var_r4_729 = (s8) *var_r6_726;
                var_r6_726 = M2C_BITWISE(f32, (M2C_BITWISE(s32, var_r6_726) + 1));
                goto loop_38;
            }
        }
        ((MKHeap *) var_r3_642)->DeactivateTempMemOverride();
    }
}
#endif

void Subtitles_DeinitModule() {
    Subtitles_Deinit();
}

void Subtitles_InitModule() {
    M2C_FIELD(&sub, s8 *, 0x84) = 0;
}
