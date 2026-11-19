#include "spyro/source/SpyroTools.h"
#include "common/Source/Animation.h"
#include "common/Source/Frustum.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "spyro/source/HeroInterface.h"
#include "spyro/source/TargetManager.h"
#include "unplaced_enums.h"
#include "spyro/source/KDMath.h"
#include <m2c_macros.h>

M2C_UNK free(void ****);                            /* extern */
void ****malloc(M2C_UNK);                           /* extern */
M2C_UNK qsort(s32, M2C_UNK, s32 (*)(SpyroTargetList *, void *, void *)); /* extern */
extern f32 SPYRO_BOUNCE_Y_SPEED;
extern f32 SPYRO_MIN_JUMP_Y_VELOCITY;
extern M2C_UNK gEmptyPtrListDL;
extern f32 gUpdateTimeDelta;
extern M2C_UNK gb;

#if 0 // DRAFT: pointer/array required
s32 SpyroTargetList::CompareTargets(const void *arg0, const void *arg1) {
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f64 sp20;
    f64 sp18;
    f64 sp10;
    f64 sp8;
    f32 temp_f0_50;
    f32 temp_f1_45;
    f32 temp_f2_41;
    f32 temp_f2_56;
    f32 temp_f2_77;
    f32 temp_f3_51;
    f32 temp_f3_72;
    f32 temp_f4_54;
    f32 temp_f4_73;
    f64 temp_f1_25;
    f64 temp_f1_53;
    void **temp_r3_22;
    void **temp_r3_47;
    void *temp_r3_63;
    void *temp_r4_23;
    void *temp_r4_32;
    void *temp_r4_49;

    temp_r3_22 = **arg0;
    temp_r4_23 = M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 8);
    temp_f1_25 = M2C_FIELD(temp_r4_23, f64 *, 0x30);
    sp8 = temp_f1_25;
    sp10 = M2C_FIELD(temp_r4_23, f64 *, 0x38);
    temp_r4_32 = M2C_FIELD(M2C_FIELD(*temp_r3_22, void *(**)(void **, void *, void *, f64), 8)(temp_r3_22, temp_r4_23, M2C_FIELD(&gb, void **, 0x3B8), temp_f1_25), void **, 8);
    sp18 = M2C_FIELD(temp_r4_32, f64 *, 0x30);
    sp20 = M2C_FIELD(temp_r4_32, f64 *, 0x38);
    temp_f2_41 = (*(f32 *) ((u8 *) &sp18 + 0x4)) - (*(f32 *) ((u8 *) &sp8 + 0x4));
    temp_f1_45 = (f32) sp18 - (f32) sp8;
    temp_r3_47 = *this->unk0;
    temp_r4_49 = M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 8);
    temp_f0_50 = (f32) sp20 - (f32) sp10;
    temp_f3_51 = temp_f1_45 * temp_f1_45;
    temp_f1_53 = M2C_FIELD(temp_r4_49, f64 *, 0x30);
    temp_f4_54 = temp_f0_50 * temp_f0_50;
    temp_f2_56 = temp_f3_51 + (temp_f2_41 * temp_f2_41);
    sp28 = temp_f1_53;
    sp30 = M2C_FIELD(temp_r4_49, f64 *, 0x38);
    temp_r3_63 = M2C_FIELD(M2C_FIELD(*temp_r3_47, void *(**)(void **, void *, f64, f32, f32, f32), 8)(temp_r3_47, temp_r4_49, temp_f1_53, temp_f2_56, temp_f3_51, temp_f4_54), void **, 8);
    sp38 = M2C_FIELD(temp_r3_63, f64 *, 0x30);
    sp40 = M2C_FIELD(temp_r3_63, f64 *, 0x38);
    temp_f3_72 = (*(f32 *) ((u8 *) &sp38 + 0x4)) - (*(f32 *) ((u8 *) &sp28 + 0x4));
    temp_f4_73 = (f32) sp38 - (f32) sp28;
    temp_f2_77 = (f32) sp40 - (f32) sp30;
    if (((temp_f2_77 * temp_f2_77) + ((temp_f4_73 * temp_f4_73) + (temp_f3_72 * temp_f3_72))) < (temp_f4_54 + temp_f2_56)) {
        return -1;
    }
    return 1;
}
#endif

#if 0 // DRAFT: illegal use of abstract class ('HeroInterface::GetHeroType()')
void ****SpyroTargetList::UpdateTargetList() {
    Targetable *sp140;
    f64 sp138;
    f64 sp130;
    f64 sp128;
    f64 sp120;
    f64 sp118;
    f64 sp110;
    f64 sp108;
    f64 sp100;
    f64 spF8;
    f64 spF0;
    f64 spE8;
    f64 spE0;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    f64 spC0;
    f64 spB8;
    f64 spB0;
    f64 spA8;
    f64 spA0;
    HeroInterface sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f32 sp68;
    f64 sp60;
    f32 sp58;
    f64 sp50;
    f32 sp48;
    f64 sp40;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    Frustum *temp_r21_154;
    f32 temp_f1_167;
    f32 temp_f1_189;
    f32 temp_f4_482;
    f32 var_f1_491;
    f32 var_f2_321;
    f32 var_f4_254;
    f32 var_f4_331;
    f32 var_f5_357;
    f64 temp_f0_162;
    f64 temp_f0_183;
    f64 temp_f1_157;
    f64 temp_f1_177;
    f64 temp_f1_222;
    f64 temp_f1_230;
    f64 temp_f1_260;
    f64 temp_f1_266;
    f64 temp_f1_270;
    f64 temp_f1_362;
    f64 temp_f1_368;
    f64 temp_f1_372;
    f64 temp_f1_463;
    s32 temp_r29_126;
    s32 temp_r3_289;
    s32 temp_r3_391;
    s32 var_r0_299;
    s32 var_r0_401;
    s32 var_r22_143;
    s32 var_r25_142;
    s32 var_r26_141;
    s32 var_r3_147;
    u32 temp_r0_549;
    void ****temp_r3_505;
    void ****var_r21_528;
    void ****var_r27_127;
    void **temp_r24_148;
    void *temp_r3_176;
    void *temp_r3_229;
    void *temp_r3_471;
    void *temp_r4_219;
    void *temp_r5_460;
    void *temp_r6_115;

    temp_r6_115 = M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 8);
    sp130 = M2C_FIELD(temp_r6_115, f64 *, 0x20);
    sp138 = M2C_FIELD(temp_r6_115, f64 *, 0x28);
    temp_r29_126 = ((TargetManager *) (M2C_FIELD(&gb, TargetManager **, 0x20)))->GetTargets(&sp140, 0x10, this->unk10, temp_r6_115 + 0x30, this->unkC, 1U, (MKVector3 *) &sp130, 3.1415927f);
    var_r27_127 = NULL;
loop_2:
    if ((void ***) *this->unk8 != NULL) {
        this->unk8 += 4;
        goto loop_2;
    }
    var_r26_141 = 0;
    var_r25_142 = 0;
    var_r22_143 = 0;
loop_55:
    if (var_r25_142 < temp_r29_126) {
        var_r3_147 = 1;
        temp_r24_148 = *(&sp140 + var_r22_143);
        if ((u8) this->unk14 != 0) {
            temp_r21_154 = M2C_FIELD(&gb, void **, 0x3B8) + 0xB0;
            temp_f1_157 = M2C_FIELD(*temp_r24_148, f64 (**)(void **, void *, f32), 0x38)(temp_r24_148, M2C_FIELD(&gb, void **, 0x3B8));
            temp_f0_162 = M2C_FIELD(&MKVector3::up, f64 *, 0) * temp_f1_157;
            sp60 = temp_f0_162;
            temp_f1_167 = MKVector3::up.unk8 * (f32) temp_f1_157;
            spE0 = temp_f0_162;
            sp68 = temp_f1_167;
            spE8 = (f64) sp68;
            temp_r3_176 = M2C_FIELD(M2C_FIELD(*temp_r24_148, void *(**)(void **, f32, f64), 8)(temp_r24_148, temp_f1_167), void **, 8);
            temp_f1_177 = M2C_FIELD(temp_r3_176, f64 *, 0x30);
            spF0 = temp_f1_177;
            spF8 = M2C_FIELD(temp_r3_176, f64 *, 0x38);
            temp_f0_183 = temp_f1_177 + temp_f0_162;
            sp50 = temp_f0_183;
            temp_f1_189 = (f32) spF8 + (f32) spE8;
            sp100 = temp_f0_183;
            sp58 = temp_f1_189;
            sp108 = (f64) sp58;
            var_r3_147 = temp_r21_154->IsVisible(*((MKVector3 *) &sp100), M2C_FIELD(*temp_r24_148, f64 (**)(void **, void *, f32), 0x38)(temp_r24_148, M2C_BITWISE(void *, temp_f1_189), (f32) spF8));
        }
        if (((u8) var_r3_147 != 0) && (M2C_FIELD(M2C_FIELD(*temp_r24_148, void *(**)(void **, f32, f64), 8)(temp_r24_148), s32 *, 0x10) & 0x40000)) {
            temp_r4_219 = M2C_FIELD(M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), void *(**)(void **), 0xC)(M2C_FIELD(&gb, void ***, 0)), void **, 8);
            temp_f1_222 = M2C_FIELD(temp_r4_219, f64 *, 0x30);
            spB0 = temp_f1_222;
            spB8 = M2C_FIELD(temp_r4_219, f64 *, 0x38);
            temp_r3_229 = M2C_FIELD(M2C_FIELD(*temp_r24_148, void *(**)(void **, f32, f64), 8)(temp_r24_148, M2C_BITWISE(f32, temp_r4_219), temp_f1_222), void **, 8);
            temp_f1_230 = M2C_FIELD(temp_r3_229, f64 *, 0x30);
            spC0 = temp_f1_230;
            spC8 = M2C_FIELD(temp_r3_229, f64 *, 0x38);
            sp40 = temp_f1_230 - spB0;
            spD0 = sp40;
            sp48 = (f32) spC8 - (f32) spB8;
            spD8 = (f64) sp48;
            var_f4_254 = ((f32) spD8 * (f32) spD8) + (((f32) spD0 * (f32) spD0) + ((*(f32 *) ((u8 *) &spD0 + 0x4)) * (*(f32 *) ((u8 *) &spD0 + 0x4))));
            if (var_f4_254 > 1e-12f) {
                if (var_f4_254 > 0.0f) {
                    temp_f1_260 = __frsqrte(var_f4_254);
                    temp_f1_266 = 0.5 * temp_f1_260 * -(((f64) var_f4_254 * (temp_f1_260 * temp_f1_260)) - 3.0);
                    temp_f1_270 = 0.5 * temp_f1_266 * -(((f64) var_f4_254 * (temp_f1_266 * temp_f1_266)) - 3.0);
                    var_f4_254 = (f32) ((f64) var_f4_254 * (0.5 * temp_f1_270 * -(((f64) var_f4_254 * (temp_f1_270 * temp_f1_270)) - 3.0)));
                } else if (var_f4_254 < M2C_BITWISE(f32, 0.0)) {
                    var_f4_254 = __float_nan;
                } else {
                    spC = var_f4_254;
                    temp_r3_289 = M2C_BITWISE(s32, spC) & 0x7F800000;
                    switch (temp_r3_289) {          /* switch 1; irregular */
                    case 0x7F800000:                /* switch 1 */
                        if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                            var_r0_299 = 1;
                        } else {
                            var_r0_299 = 2;
                        }
                        break;
                    case 0x0:                       /* switch 1 */
                        if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                            var_r0_299 = 5;
                        } else {
                            var_r0_299 = 3;
                        }
                        break;
                    default:                        /* switch 1 */
                        var_r0_299 = 4;
                        break;
                    }
                    if (var_r0_299 == 1) {
                        var_f4_254 = __float_nan;
                    }
                }
                var_f2_321 = 1.0f / var_f4_254;
            } else {
                var_f2_321 = 0.0f;
            }
            var_f4_331 = 0.0f;
            sp30 = (f32) spD0 * var_f2_321;
            sp34 = (*(f32 *) ((u8 *) &spD0 + 0x4)) * var_f2_321;
            sp38 = (f32) spD8 * var_f2_321;
            sp120 = (f64) sp30;
            sp128 = (f64) sp38;
            sp20 = (f32) sp120;
            sp24 = 0.0f;
            sp28 = (f32) sp128;
            spA0 = (f64) sp20;
            spA8 = (f64) sp28;
            var_f5_357 = ((f32) spA8 * (f32) spA8) + (((f32) spA0 * (f32) spA0) + ((*(f32 *) ((u8 *) &spA0 + 0x4)) * (*(f32 *) ((u8 *) &spA0 + 0x4))));
            if (var_f5_357 > 1e-12f) {
                if (var_f5_357 > 0.0f) {
                    temp_f1_362 = __frsqrte(var_f5_357);
                    temp_f1_368 = 0.5 * temp_f1_362 * -(((f64) var_f5_357 * (temp_f1_362 * temp_f1_362)) - 3.0);
                    temp_f1_372 = 0.5 * temp_f1_368 * -(((f64) var_f5_357 * (temp_f1_368 * temp_f1_368)) - 3.0);
                    var_f5_357 = (f32) ((f64) var_f5_357 * (0.5 * temp_f1_372 * -(((f64) var_f5_357 * (temp_f1_372 * temp_f1_372)) - 3.0)));
                } else if (var_f5_357 < M2C_BITWISE(f32, 0.0)) {
                    var_f5_357 = __float_nan;
                } else {
                    sp8 = var_f5_357;
                    temp_r3_391 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                    switch (temp_r3_391) {          /* switch 2; irregular */
                    case 0x7F800000:                /* switch 2 */
                        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                            var_r0_401 = 1;
                        } else {
                            var_r0_401 = 2;
                        }
                        break;
                    case 0x0:                       /* switch 2 */
                        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                            var_r0_401 = 5;
                        } else {
                            var_r0_401 = 3;
                        }
                        break;
                    default:                        /* switch 2 */
                        var_r0_401 = 4;
                        break;
                    }
                    if (var_r0_401 == 1) {
                        var_f5_357 = __float_nan;
                    }
                }
                var_f4_331 = 1.0f / var_f5_357;
            }
            sp10 = (f32) spA0 * var_f4_331;
            sp14 = (*(f32 *) ((u8 *) &spA0 + 0x4)) * var_f4_331;
            sp18 = (f32) spA8 * var_f4_331;
            sp110 = (f64) sp10;
            sp118 = (f64) sp18;
            sp90.GetXZDir();
            if (!((((f32) sp118 * sp98) + (((f32) sp110 * M2C_BITWISE(f32, sp90)) + ((*(f32 *) ((u8 *) &sp110 + 0x4)) * sp94))) < 0.25f)) {
                temp_r5_460 = M2C_FIELD(M2C_FIELD(*temp_r24_148, void *(**)(void **, f32, f64), 8)(temp_r24_148), void **, 8);
                temp_f1_463 = M2C_FIELD(temp_r5_460, f64 *, 0x30);
                sp70 = temp_f1_463;
                sp78 = M2C_FIELD(temp_r5_460, f64 *, 0x38);
                temp_r3_471 = M2C_FIELD(M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), void *(**)(void **, M2C_UNK *, void *, f64), 0xC)(M2C_FIELD(&gb, void ***, 0), &gb, temp_r5_460, temp_f1_463), void **, 8);
                sp80 = M2C_FIELD(temp_r3_471, f64 *, 0x30);
                temp_f4_482 = (*(f32 *) ((u8 *) &sp80 + 0x4)) - (*(f32 *) ((u8 *) &sp70 + 0x4));
                sp88 = M2C_FIELD(temp_r3_471, f64 *, 0x38);
                if (temp_f4_482 < 0.0f) {
                    var_f1_491 = -temp_f4_482;
                } else {
                    var_f1_491 = temp_f4_482;
                }
                if (!(var_f1_491 > 500.0f) || !((((f32) sp128 * (f32) sp118) + (((f32) sp120 * (f32) sp110) + ((*(f32 *) ((u8 *) &sp120 + 0x4)) * (*(f32 *) ((u8 *) &sp110 + 0x4))))) < 0.8f)) {
                    var_r26_141 += 1;
                    temp_r3_505 = this->unk8 - 4;
                    this->unk8 = temp_r3_505;
                    **temp_r3_505 = temp_r24_148;
                }
            }
        }
        var_r25_142 += 1;
        var_r22_143 += 4;
        goto loop_55;
    }
    if ((void ***) *this->unk8 != NULL) {
        qsort(var_r26_141, 4, &SpyroTargetList::CompareTargets);
        if (TargetContext::Get() != NULL) {
            var_r21_528 = this->unk8;
loop_62:
            if (((void ***) *var_r21_528 != NULL) && (var_r27_127 == NULL)) {
                if ((void **) **var_r21_528 == TargetContext::Get()) {
                    var_r27_127 = var_r21_528;
                }
                var_r21_528 += 4;
                goto loop_62;
            }
            if (var_r27_127 != NULL) {
                temp_r0_549 = M2C_FIELD(var_r27_127, u32 *, 4);
                var_r27_127 += 4;
                if (temp_r0_549 == 0U) {
                    var_r27_127 = this->unk8;
                }
            }
        } else {
            var_r27_127 = this->unk8;
        }
    }
    return var_r27_127;
}
#endif

#if 0 // DRAFT: function call 'Set(int)' does not match
void SpyroTargetList::ClearCurrentTarget() {
    TargetContext::Set(NULL);
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void SpyroTargetList::GetCurrentTarget() {
    TargetContext::Get();
}
#endif

#if 0 // DRAFT: illegal use of non-static member
s32 SpyroTargetList::SelectTarget(bool arg0) {
    u32 temp_r0_770;
    void ****var_r31_759;

    var_r31_759 = UpdateTargetList();
    if ((var_r31_759 != NULL) && ((void ***) M2C_FIELD(var_r31_759, void ****, 0) != NULL)) {
        if ((arg0 != 0) && (TargetContext::Get() != NULL)) {
            temp_r0_770 = M2C_FIELD(var_r31_759, u32 *, 4);
            var_r31_759 += 4;
            if (temp_r0_770 == 0U) {
                var_r31_759 = this->unk8;
            }
        }
        TargetContext::Set((Targetable *) **var_r31_759);
    }
    return TargetContext::Get() != NULL;
}
#endif

#if 0 // DRAFT: function call 'Set(int)' does not match
void SpyroTargetList::SetDefaults() {
    TargetContext::Set(NULL);
loop_2:
    if ((void ***) *this->unk8 != NULL) {
        this->unk8 += 4;
        goto loop_2;
    }
}
#endif

#if 0 // DRAFT: function call 'Set(int)' does not match
void SpyroTargetList::Deinit() {
    MKHeap *temp_r3_855;
    u32 temp_r0_838;
    void ****var_r31_829;
    void ****var_r3_830;
    void ****var_r4_828;
    void ***temp_r0_833;
    void ***temp_r0_852;

    TargetContext::Set(NULL);
    var_r4_828 = this->unk8;
    var_r31_829 = var_r4_828;
    var_r3_830 = var_r4_828;
loop_3:
    temp_r0_838 = M2C_FIELD(var_r3_830, u32 *, -4);
    var_r3_830 -= 4;
    if (temp_r0_838 != 0U) {
        temp_r0_833 = *var_r3_830;
        if (temp_r0_833 < var_r31_829) {
            var_r31_829 = (void ****) temp_r0_833;
        }
        goto loop_3;
    }
    if (var_r3_830 != &gEmptyPtrListDL) {
loop_9:
        temp_r0_852 = *var_r4_828;
        if (temp_r0_852 != NULL) {
            if (temp_r0_852 < var_r31_829) {
                var_r31_829 = (void ****) temp_r0_852;
            }
            var_r4_828 += 4;
            goto loop_9;
        }
        temp_r3_855 = ((MKHeap *) var_r3_830)->Current();
        if (temp_r3_855 != NULL) {
            ((MKHeap *) (temp_r3_855->Current()))->Free(var_r31_829, NULL, 0);
        } else {
            free(var_r31_829);
        }
    }
    this->unk8 = NULL;
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void SpyroTargetList::Init(float arg0, unsigned int arg1, bool arg2) {
    MKHeap *temp_r3_888;
    s32 var_ctr_908;
    void ****temp_r3_910;
    void ****temp_r4_916;
    void ****var_r3_895;
    void ****var_r5_904;

    this->unkC = arg0;
    this->unk10 = arg1;
    this->unk14 = arg2;
    temp_r3_888 = MKHeap::Current();
    if (temp_r3_888 != NULL) {
        var_r3_895 = ((MKHeap *) (temp_r3_888->Current()))->Alloc(0x88, NULL, 0);
    } else {
        var_r3_895 = malloc(0x88);
    }
    this->unk8 = var_r3_895;
    var_r5_904 = this->unk8;
    this->unk8 = var_r5_904 + 0x40;
    M2C_FIELD(var_r5_904, s32 *, 0x40) = 0;
    var_ctr_908 = 0x10;
    do {
        temp_r3_910 = this->unk8;
        this->unk8 = temp_r3_910 + 4;
        M2C_FIELD(temp_r3_910, void *****, 4) = var_r5_904;
        var_r5_904 += 4;
        var_ctr_908 -= 1;
    } while (var_ctr_908 != 0);
    temp_r4_916 = this->unk8;
    this->unk8 = temp_r4_916 + 4;
    M2C_FIELD(temp_r4_916, void *****, 4) = NULL;
    SetDefaults();
}
#endif

#if 0 // DRAFT: undefined identifier '__float_nan'
void SpyroStuck::Update() {
    s8 spA1;
    s8 spA0;
    s32 sp9C;
    f32 sp98;
    s32 sp94;
    s8 sp92;
    s8 sp91;
    s8 sp90;
    f32 sp88;
    f32 sp84;
    f32 sp80;
    s32 sp7C;
    s32 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    s32 sp54;
    s32 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp8;
    MKProp *temp_r3_1087;
    f32 var_f4_967;
    f64 temp_f1_970;
    f64 temp_f1_976;
    f64 temp_f1_980;
    s32 temp_r3_999;
    s32 var_r0_1009;
    void *temp_r3_941;

    temp_r3_941 = this->unk18->unk8;
    sp40 = M2C_FIELD(temp_r3_941, f64 *, 0x30);
    sp48 = M2C_FIELD(temp_r3_941, f64 *, 0x38);
    this->unk10 -= gUpdateTimeDelta;
    sp20 = sp40 - this->unk0;
    sp30 = sp20;
    sp28 = (f32) sp48 - this->unk8;
    sp38 = (f64) sp28;
    var_f4_967 = ((f32) sp38 * (f32) sp38) + (((f32) sp30 * (f32) sp30) + ((*(f32 *) ((u8 *) &sp30 + 0x4)) * (*(f32 *) ((u8 *) &sp30 + 0x4))));
    if (var_f4_967 > 0.0f) {
        temp_f1_970 = __frsqrte(var_f4_967);
        temp_f1_976 = 0.5 * temp_f1_970 * -(((f64) var_f4_967 * (temp_f1_970 * temp_f1_970)) - 3.0);
        temp_f1_980 = 0.5 * temp_f1_976 * -(((f64) var_f4_967 * (temp_f1_976 * temp_f1_976)) - 3.0);
        var_f4_967 = (f32) ((f64) var_f4_967 * (0.5 * temp_f1_980 * -(((f64) var_f4_967 * (temp_f1_980 * temp_f1_980)) - 3.0)));
    } else if (var_f4_967 < M2C_BITWISE(f32, 0.0)) {
        var_f4_967 = __float_nan;
    } else {
        sp8 = var_f4_967;
        temp_r3_999 = M2C_BITWISE(s32, sp8) & 0x7F800000;
        switch (temp_r3_999) {                      /* irregular */
        case 0x7F800000:
            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                var_r0_1009 = 1;
            } else {
                var_r0_1009 = 2;
            }
            break;
        case 0x0:
            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                var_r0_1009 = 5;
            } else {
                var_r0_1009 = 3;
            }
            break;
        default:
            var_r0_1009 = 4;
            break;
        }
        if (var_r0_1009 == 1) {
            var_f4_967 = __float_nan;
        }
    }
    this->unk14 += var_f4_967;
    this->unk0 = sp40;
    M2C_FIELD(this, f32 *, 8) = sp48;
    if (this->unk10 <= 0.0f) {
        if (this->unk14 < 100.0f) {
            sp54 = 0;
            sp50 = 7;
            sp78 = 5;
            sp7C = 0;
            sp58 = M2C_FIELD(&MKVector3::up, f64 *, 0);
            sp60 = M2C_FIELD(&MKVector3::up, f64 *, 8);
            sp90 = 1;
            sp9C = 0;
            sp98 = 0.0f;
            sp91 = 0;
            sp92 = 0;
            sp94 = -1;
            sp68 = M2C_FIELD(&MKVector3::one, f64 *, 0);
            sp70 = M2C_FIELD(&MKVector3::one, f64 *, 8);
            spA0 = 0;
            sp80 = 0.0f;
            sp84 = 0.0f;
            sp88 = 0.0f;
            spA1 = 0;
            temp_r3_1087 = this->unk18;
            temp_r3_1087->Message(&sp50);
        }
        Reset();
    }
}
#endif

void SpyroStuck::Reset() {
    f64 sp10;
    f64 sp8;
    f64 temp_f1_1113;
    f64 temp_f2_1112;
    void *temp_r4_1111;

    this->unk10 = 1.0f;
    temp_r4_1111 = this->unk18->unk8;
    temp_f2_1112 = M2C_FIELD(temp_r4_1111, f64 *, 0x30);
    temp_f1_1113 = M2C_FIELD(temp_r4_1111, f64 *, 0x38);
    sp8 = temp_f2_1112;
    this->unk0 = temp_f2_1112;
    M2C_FIELD(this, f64 *, 8) = temp_f1_1113;
    sp10 = temp_f1_1113;
    this->unk14 = 0.0f;
}

void SpyroStuck::Init(MKProp *arg0) {
    this->unk18 = arg0;
    this->unk10 = 1.0f;
    this->unk14 = 0.0f;
}

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to
void SpyroLighting::ApplyPointLight(MKVector3 arg0, float arg1, float arg2) {
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    f32 temp_f4_1139;
    f32 var_f0_1165;
    f64 temp_f0_1149;
    f64 temp_f1_1143;
    void *temp_r5_1142;

    temp_f4_1139 = arg1 * arg1;
    temp_r5_1142 = M2C_FIELD(this->unk28, void **, 8);
    temp_f1_1143 = M2C_FIELD(temp_r5_1142, f64 *, 0x30);
    sp28 = temp_f1_1143;
    sp30 = M2C_FIELD(temp_r5_1142, f64 *, 0x38);
    temp_f0_1149 = temp_f1_1143 - *(f64 *) arg0;
    sp8 = temp_f0_1149;
    sp38 = temp_f0_1149;
    sp10 = (f32) sp30 - M2C_FIELD(arg0, f32 *, 8);
    sp40 = (f64) sp10;
    var_f0_1165 = ((f32) sp40 * (f32) sp40) + (((f32) sp38 * (f32) sp38) + ((*(f32 *) ((u8 *) &sp38 + 0x4)) * (*(f32 *) ((u8 *) &sp38 + 0x4))));
    if (var_f0_1165 < temp_f4_1139) {
        if (var_f0_1165 > 100.0f) {

        } else {
            var_f0_1165 = 100.0f;
        }
        sp18 = M2C_FIELD(arg0, f64 *, 0);
        sp20 = (f64) M2C_FIELD(arg0, f32 *, 8);
        SetLight((MKVector3) &sp18, arg2 * ((temp_f4_1139 / var_f0_1165) - 1.0f));
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to
void SpyroLighting::SetLight(MKVector3 arg0, float arg1) {
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    f32 var_f2_1195;
    f64 temp_f0_1203;

    var_f2_1195 = arg1;
    if (var_f2_1195 < 0.0f) {
        var_f2_1195 = 0.0f;
    }
    temp_f0_1203 = *(f64 *) arg0 * (f64) var_f2_1195;
    sp8 = temp_f0_1203;
    sp18 = temp_f0_1203;
    sp10 = M2C_FIELD(arg0, f32 *, 8) * var_f2_1195;
    sp20 = (f64) sp10;
    M2C_FIELD(this, f64 *, 0x10) = (f64) (M2C_FIELD(this, f64 *, 0x10) + temp_f0_1203);
    this->unk18 += (f32) sp20;
    this->unk20 += var_f2_1195;
}
#endif

void SpyroLighting::Reset() {
    this->unk20 = 0.0f;
    this->unk0 = 0.0f;
    this->unk4 = 0.0f;
    this->unk8 = 0.0f;
    this->unk10 = 0.0f;
    this->unk14 = 0.0f;
    this->unk18 = 0.0f;
    this->unk24 = 0.0f;
}

#if 0 // DRAFT: function call 'memcpy(long, long, int)' does not match
void SpyroNodeHelper::SetPYR(const MKVector3 &arg0) {
    f64 spD8;
    f64 spD0;
    M2C_UNK spA0;
    M2C_UNK sp9C;
    Matrix sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp30;
    f64 sp28;
    f64 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    s32 temp_r31_1349;

    this->unk0 = M2C_FIELD(&arg0, f64 *, 0);
    this->unk8 = M2C_FIELD(&arg0, f64 *, 8);
    if ((s32) this->unk10 < 0) {
        M2C_STRUCT_COPY((s32) &sp9C + 4, MKModel_GetWorldMatrix(this->unk14) - 4 + 4, 0x40);
        sp50 = spD0;
        sp58 = spD8;
        ((Matrix *) &spA0)->SetIdentity();
        ((Matrix *) &spA0)->RotateRoll((Matrix *) &spA0, (f32) M2C_FIELD(this, f64 *, 8));
        ((Matrix *) &spA0)->RotatePitch((Matrix *) &spA0, (f32) M2C_FIELD(this, f64 *, 0));
        ((Matrix *) &spA0)->RotateYaw((Matrix *) &spA0, M2C_FIELD(this, f32 *, 4));
        spD0 = (f32) sp50;
        (*(f32 *) ((u8 *) &spD0 + 0x4)) = (*(f32 *) ((u8 *) &sp50 + 0x4));
        spD8 = (f32) sp58;
        (*(f32 *) ((u8 *) &spD8 + 0x4)) = 1.0f;
        MKModel_SetWorldMatrix(this->unk14, *((Matrix *) &spA0));
        return;
    }
    ((Animation *) &sp30)->GetNodeOrigin(MKModel_GetAnimation(this->unk14));
    sp40 = sp30;
    sp48 = sp38;
    sp60.SetIdentity();
    sp10 = -(f32) sp40;
    sp14 = -(*(f32 *) ((u8 *) &sp40 + 0x4));
    sp18 = -(f32) sp48;
    sp20 = (f64) sp10;
    sp28 = (f64) sp18;
    sp60.Translate(&sp60, *((MKVector3 *) &sp20));
    sp60.RotateYaw(&sp60, M2C_FIELD(this, f32 *, 4));
    sp60.RotatePitch(&sp60, (f32) M2C_FIELD(this, f64 *, 0));
    sp60.RotateRoll(&sp60, (f32) M2C_FIELD(this, f64 *, 8));
    sp60.Translate(&sp60, *((MKVector3 *) &sp40));
    temp_r31_1349 = this->unk10;
    ((Animation *) (MKModel_GetAnimation(this->unk14)))->SetCustomMatrix(temp_r31_1349, &sp60, (AnimationMatrixPosition) 2, 0U);
}
#endif

void SpyroNodeHelper::Init(MKModel *arg0, int arg1) {
    this->unk14 = arg0;
    this->unk10 = arg1;
    M2C_FIELD(this, f32 *, 0) = 0.0f;
    M2C_FIELD(this, f32 *, 4) = 0.0f;
    M2C_FIELD(this, f32 *, 8) = 0.0f;
}

void SpyroRotation::RollTowards(float arg0, float arg1) {
    RotateTowards(this->unk0, this->unk4, arg0, arg1);
}

void SpyroRotation::YawTowards(float arg0, float arg1) {
    RotateTowards(this->unk0, arg0, this->unk8, arg1);
}

void SpyroRotation::YawTowards(const MKVector3 &arg0, float arg1) {
    f32 temp_f1_1424;
    f32 temp_f2_1422;
    f32 temp_f3_1427;

    temp_f2_1422 = arg0.unk0;
    temp_f1_1424 = arg0.unk4;
    temp_f3_1427 = arg0.unk8;
    if (!(((temp_f3_1427 * temp_f3_1427) + ((temp_f2_1422 * temp_f2_1422) + (temp_f1_1424 * temp_f1_1424))) < 0.0009999999f)) {
        RotateTowards(this->unk0, KDMath_GetYaw(arg0), this->unk8, arg1);
    }
}

#if 0 // DRAFT: illegal use of non-static member
void SpyroRotation::RotateTowards(float arg0, float arg1, float arg2, float arg3) {
    f32 sp10;
    f32 spC;
    f32 sp8;

    if (arg3 == 900.0f) {
        sp8 = arg0;
        spC = arg1;
        sp10 = arg2;
    } else {
        KDMath_SmoothToAngle(this->unk0, arg0, arg3, gUpdateTimeDelta);
        sp8 = M2C_ERROR(/* Read from unset register $f1 */);
        KDMath_SmoothToAngle(this->unk4, arg1, arg3, gUpdateTimeDelta);
        spC = M2C_ERROR(/* Read from unset register $f1 */);
        KDMath_SmoothToAngle(this->unk8, arg2, arg3, gUpdateTimeDelta);
        sp10 = M2C_ERROR(/* Read from unset register $f1 */);
    }
    SpyroNodeHelper::SetPYR(*((MKVector3 *) &sp8));
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void SpyroRotation::Init(MKModel *arg0, int arg1) {
    SpyroNodeHelper::Init(arg0, arg1);
}
#endif

void SpyroTools_cpp::__sinit() {
    f32 temp_f0_1561;
    f64 temp_f1_1542;
    f64 temp_f1_1550;
    f64 temp_f3_1530;
    f64 temp_f4_1539;
    f64 temp_f4_1547;
    f64 temp_f8_1532;

    temp_f3_1530 = __frsqrte(2014000.0);
    temp_f8_1532 = __frsqrte(380000.0);
    temp_f4_1539 = 0.5 * temp_f3_1530 * -((2014000.0 * (temp_f3_1530 * temp_f3_1530)) - 3.0);
    temp_f1_1542 = 0.5 * temp_f8_1532 * -((380000.0 * (temp_f8_1532 * temp_f8_1532)) - 3.0);
    temp_f4_1547 = 0.5 * temp_f4_1539 * -((2014000.0 * (temp_f4_1539 * temp_f4_1539)) - 3.0);
    temp_f1_1550 = 0.5 * temp_f1_1542 * -((380000.0 * (temp_f1_1542 * temp_f1_1542)) - 3.0);
    temp_f0_1561 = (f32) (380000.0 * (0.5 * temp_f1_1550 * -((380000.0 * (temp_f1_1550 * temp_f1_1550)) - 3.0)));
    SPYRO_BOUNCE_Y_SPEED = (f32) (2014000.0 * (0.5 * temp_f4_1547 * -((2014000.0 * (temp_f4_1547 * temp_f4_1547)) - 3.0)));
    SPYRO_MIN_JUMP_Y_VELOCITY = temp_f0_1561;
}
