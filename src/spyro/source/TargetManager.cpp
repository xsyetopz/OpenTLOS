#include "spyro/source/TargetManager.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "spyro/source/Character.h"
#include "common/Source/StdMath.h"
#include <m2c_macros.h>

M2C_UNK free(TargetManager ***);                    /* extern */
TargetManager ***malloc(s32);                       /* extern */
extern M2C_UNK gEmptyPtrList;
extern M2C_UNK gEmptyPtrListDL;
extern void **gMK;
extern M2C_UNK gb;

#if 0 // DRAFT: undefined identifier 'unk0'
TargetManager **TargetManager::GetNearestFacingEnemy(const MKVector3 &arg0, float arg1, const MKVector3 &arg2, float arg3, bool arg4, bool arg5) {
    f64 sp48;
    f64 sp40;
    f64 sp38;                                       /* compiler-managed */
    f64 sp30;                                       /* compiler-managed */
    f64 sp28;
    f64 sp20;
    f32 sp18;
    f32 sp8;
    TargetManager ***var_r30_37;
    TargetManager **temp_r3_116;
    TargetManager **temp_r3_243;
    TargetManager **temp_r3_46;
    TargetManager **temp_r3_53;
    TargetManager **temp_r3_62;
    TargetManager **temp_r3_74;
    TargetManager **temp_r3_98;
    TargetManager **var_r31_34;
    f32 temp_f0_107;
    f32 temp_f2_92;
    f32 temp_f31_96;
    f32 temp_f3_89;
    f32 temp_f4_224;
    f32 temp_f4_86;
    f32 temp_f5_217;
    f32 temp_f6_219;
    f32 var_f1_102;
    f32 var_f30_29;
    f32 var_f4_134;
    f32 var_f5_147;
    f64 temp_f1_152;
    f64 temp_f1_158;
    f64 temp_f1_162;
    s32 temp_r3_181;
    s32 var_r0_191;
    void *temp_r3_121;
    void *temp_r3_67;

    var_f30_29 = 3.4028235e38f;
    var_r31_34 = NULL;
    if ((s32) M2C_FIELD(&gb, s32 *, 0x340) == 0) {
        var_r30_37 = Begin();
loop_36:
        if (var_r30_37 != NULL) {
            temp_r3_243 = *var_r30_37;
            if (temp_r3_243 != NULL) {
                if ((M2C_FIELD(*temp_r3_243, u8 (**)(), 0x18)() != 0) && ((temp_r3_46 = *var_r30_37, ((((u32 (*)(TargetManager **)) (*temp_r3_46)->unk8.unk4)(temp_r3_46) == 0U) != 0)) || (temp_r3_53 = *var_r30_37, ((((Character *) (((Character *(*)(TargetManager **)) (*temp_r3_53)->unk8.unk4)(temp_r3_53)))->IsActive() == 0) == 0)))) {
                    temp_r3_62 = *var_r30_37;
                    temp_r3_67 = M2C_FIELD((*temp_r3_62)->unk8.unk0(temp_r3_62), void **, 8);
                    sp40 = M2C_FIELD(temp_r3_67, f64 *, 0x30);
                    sp48 = M2C_FIELD(temp_r3_67, f64 *, 0x38);
                    if (arg5 != 0) {
                        temp_r3_74 = *var_r30_37;
                        M2C_FIELD(*temp_r3_74, M2C_UNK (**)(TargetManager **, MKVector3 *, f64 *), 0x28)(temp_r3_74, &arg0, &sp40);
                    }
                    temp_f4_86 = arg0.unk4 - unksp44;
                    temp_f3_89 = arg0.unk0 - (f32) sp40;
                    temp_f2_92 = arg0.unk8 - (f32) sp48;
                    temp_f31_96 = (temp_f2_92 * temp_f2_92) + ((temp_f3_89 * temp_f3_89) + (temp_f4_86 * temp_f4_86));
                    if (arg4 != 0) {
                        temp_r3_98 = *var_r30_37;
                        var_f1_102 = M2C_FIELD(*temp_r3_98, f32 (**)(TargetManager **), 0x38)(temp_r3_98);
                    } else {
                        var_f1_102 = 0.0f;
                    }
                    temp_f0_107 = arg1 + var_f1_102;
                    if ((temp_f31_96 < (temp_f0_107 * temp_f0_107)) && ((var_r31_34 == NULL) || (temp_f31_96 < var_f30_29))) {
                        temp_r3_116 = *var_r30_37;
                        temp_r3_121 = M2C_FIELD((*temp_r3_116)->unk8.unk0(temp_r3_116), void **, 8);
                        sp20 = M2C_FIELD(temp_r3_121, f64 *, 0x30);
                        sp28 = M2C_FIELD(temp_r3_121, f64 *, 0x38);
                        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r26, 0x0, qr0 */);
                        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
                        var_f4_134 = 0.0f;
                        sp30 = sp10;
                        sp18 = (f32) sp28 - arg0.unk8;
                        unksp34 = 0.0f;
                        sp38 = (f64) sp18;
                        var_f5_147 = ((f32) sp38 * (f32) sp38) + (((f32) sp30 * (f32) sp30) + (0.0f * 0.0f));
                        if (var_f5_147 > 0.000001f) {
                            if (var_f5_147 > 0.0f) {
                                temp_f1_152 = __frsqrte(var_f5_147);
                                temp_f1_158 = 0.5 * temp_f1_152 * -(((f64) var_f5_147 * (temp_f1_152 * temp_f1_152)) - 3.0);
                                temp_f1_162 = 0.5 * temp_f1_158 * -(((f64) var_f5_147 * (temp_f1_158 * temp_f1_158)) - 3.0);
                                var_f5_147 = (f32) ((f64) var_f5_147 * (0.5 * temp_f1_162 * -(((f64) var_f5_147 * (temp_f1_162 * temp_f1_162)) - 3.0)));
                            } else if (var_f5_147 < M2C_BITWISE(f32, 0.0)) {
                                var_f5_147 = __float_nan;
                            } else {
                                sp8 = var_f5_147;
                                temp_r3_181 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                                switch (temp_r3_181) { /* irregular */
                                case 0x7F800000:
                                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                        var_r0_191 = 1;
                                    } else {
                                        var_r0_191 = 2;
                                    }
                                    break;
                                case 0x0:
                                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                        var_r0_191 = 5;
                                    } else {
                                        var_r0_191 = 3;
                                    }
                                    break;
                                default:
                                    var_r0_191 = 4;
                                    break;
                                }
                                if (var_r0_191 == 1) {
                                    var_f5_147 = __float_nan;
                                }
                            }
                            var_f4_134 = 1.0f / var_f5_147;
                        }
                        temp_f5_217 = unksp34 * var_f4_134;
                        temp_f6_219 = (f32) sp30 * var_f4_134;
                        temp_f4_224 = (f32) sp38 * var_f4_134;
                        sp30 = temp_f6_219;
                        unksp34 = temp_f5_217;
                        sp38 = temp_f4_224;
                        if ((arg3 == -1.0f) || (((temp_f4_224 * arg2.unk8) + ((temp_f6_219 * arg2.unk0) + (temp_f5_217 * arg2.unk4))) > arg3)) {
                            var_r31_34 = *var_r30_37;
                            var_f30_29 = temp_f31_96;
                        }
                    }
                }
                var_r30_37 += 4;
                goto loop_36;
            }
        }
    }
    return var_r31_34;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk0'
TargetManager **TargetManager::GetNearestEnemy(const MKVector3 &arg0, float arg1, bool arg2, bool arg3) {
    f64 sp10;
    f64 sp8;
    TargetManager ***var_r30_288;
    TargetManager **temp_r3_297;
    TargetManager **temp_r3_304;
    TargetManager **temp_r3_313;
    TargetManager **temp_r3_325;
    TargetManager **temp_r3_349;
    TargetManager **temp_r3_374;
    TargetManager **var_r31_285;
    f32 temp_f0_358;
    f32 temp_f29_347;
    f32 temp_f2_343;
    f32 temp_f3_340;
    f32 temp_f4_337;
    f32 var_f1_353;
    f32 var_f31_279;
    void *temp_r3_318;

    var_f31_279 = 3.4028235e38f;
    var_r31_285 = NULL;
    if ((s32) M2C_FIELD(&gb, s32 *, 0x340) == 0) {
        var_r30_288 = Begin();
loop_15:
        if (var_r30_288 != NULL) {
            temp_r3_374 = *var_r30_288;
            if (temp_r3_374 != NULL) {
                if ((M2C_FIELD(*temp_r3_374, u8 (**)(), 0x18)() != 0) && ((temp_r3_297 = *var_r30_288, ((((u32 (*)(TargetManager **)) (*temp_r3_297)->unk8.unk4)(temp_r3_297) == 0U) != 0)) || (temp_r3_304 = *var_r30_288, ((((Character *) (((Character *(*)(TargetManager **)) (*temp_r3_304)->unk8.unk4)(temp_r3_304)))->IsActive() == 0) == 0)))) {
                    temp_r3_313 = *var_r30_288;
                    temp_r3_318 = M2C_FIELD((*temp_r3_313)->unk8.unk0(temp_r3_313), void **, 8);
                    sp8 = M2C_FIELD(temp_r3_318, f64 *, 0x30);
                    sp10 = M2C_FIELD(temp_r3_318, f64 *, 0x38);
                    if (arg3 != 0) {
                        temp_r3_325 = *var_r30_288;
                        M2C_FIELD(*temp_r3_325, M2C_UNK (**)(TargetManager **, MKVector3 *, f64 *), 0x28)(temp_r3_325, &arg0, &sp8);
                    }
                    temp_f4_337 = arg0.unk4 - unkspC;
                    temp_f3_340 = arg0.unk0 - (f32) sp8;
                    temp_f2_343 = arg0.unk8 - (f32) sp10;
                    temp_f29_347 = (temp_f2_343 * temp_f2_343) + ((temp_f3_340 * temp_f3_340) + (temp_f4_337 * temp_f4_337));
                    if (arg2 != 0) {
                        temp_r3_349 = *var_r30_288;
                        var_f1_353 = M2C_FIELD(*temp_r3_349, f32 (**)(TargetManager **), 0x38)(temp_r3_349);
                    } else {
                        var_f1_353 = 0.0f;
                    }
                    temp_f0_358 = arg1 + var_f1_353;
                    if ((temp_f29_347 < (temp_f0_358 * temp_f0_358)) && ((var_r31_285 == NULL) || (temp_f29_347 < var_f31_279))) {
                        var_r31_285 = *var_r30_288;
                        var_f31_279 = temp_f29_347;
                    }
                }
                var_r30_288 += 4;
                goto loop_15;
            }
        }
    }
    return var_r31_285;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk0'
s32 TargetManager::GetTargets(Targetable **arg0, int arg1, unsigned int arg2, MKVector3 *arg3, float arg4, bool arg5, MKVector3 *arg6, float arg7) {
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
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp60;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f32 sp30;
    f32 sp20;
    f32 sp10;
    TargetManager ***var_r29_425;
    TargetManager **temp_r31_639;
    f32 temp_f0_559;
    f32 temp_f1_518;
    f32 temp_f1_545;
    f32 temp_f2_554;
    f32 temp_f31_421;
    s32 var_r22_419;
    s32 var_r30_418;
    u8 var_r21_468;
    void *temp_r3_475;
    void *temp_r3_532;
    void *temp_r3_597;

    var_r30_418 = 0;
    var_r22_419 = 0;
    temp_f31_421 = _table_sinf(1.5707964f + arg7);
    var_r29_425 = Begin();
loop_20:
    if ((var_r30_418 < arg1) && (var_r29_425 != NULL)) {
        temp_r31_639 = *var_r29_425;
        if (temp_r31_639 != NULL) {
            if ((arg2 & M2C_FIELD(*(*temp_r31_639)->unk8.unk0(temp_r31_639), s32 *, 0xC)) && (M2C_FIELD(*gMK, u8 (**)(void **, void **, s32), 0x9C)(gMK, (*temp_r31_639)->unk8.unk0(temp_r31_639), sWorkingChunkID.unk0) != 0) && ((((u32 (*)(TargetManager **)) (*temp_r31_639)->unk8.unk4)(temp_r31_639) == 0U) || (((Character *) (((Character *(*)(TargetManager **)) (*temp_r31_639)->unk8.unk4)(temp_r31_639)))->IsActive() != 0))) {
                var_r21_468 = 1;
                if (arg3 != NULL) {
                    temp_r3_475 = M2C_FIELD((*temp_r31_639)->unk8.unk0(temp_r31_639), void **, 8);
                    spC8 = M2C_FIELD(temp_r3_475, f64 *, 0x30);
                    spD0 = M2C_FIELD(temp_r3_475, f64 *, 0x38);
                    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r26, 0x0, qr0 */);
                    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
                    sp78 = sp18;
                    sp20 = arg3->unk8 - (f32) spD0;
                    sp88 = sp18;
                    sp80 = (f64) sp20;
                    sp90 = (f64) sp20;
                    if (((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1FU) == 0) {
                        var_r21_468 = 0;
                    }
                }
                if ((var_r21_468 == 0) && (arg3 != NULL) && (arg5 != 0)) {
                    temp_f1_518 = M2C_FIELD(*temp_r31_639, f32 (**)(TargetManager **, f32), 0x38)(temp_r31_639);
                    sp70 = 0.0f;
                    sp68 = 0.0f;
                    sp6C = temp_f1_518;
                    spB0 = (f64) sp70;
                    spA8 = (f64) sp68;
                    temp_r3_532 = M2C_FIELD((*temp_r31_639)->unk8.unk0(temp_r31_639, (f64) sp68, 0.0f), void **, 8);
                    spB8 = M2C_FIELD(temp_r3_532, f64 *, 0x30);
                    spC0 = M2C_FIELD(temp_r3_532, f64 *, 0x38);
                    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                    temp_f1_545 = (f32) spC0 + (f32) spB0;
                    spE8 = sp58;
                    sp60 = temp_f1_545;
                    spF0 = (f64) sp60;
                    temp_f2_554 = arg4 + M2C_FIELD(*temp_r31_639, f32 (**)(TargetManager **, f32), 0x38)(temp_r31_639, temp_f1_545);
                    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r26, 0x0, qr0 */);
                    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
                    temp_f0_559 = temp_f2_554 * temp_f2_554;
                    sp38 = sp8;
                    sp10 = arg3->unk8 - (f32) spF0;
                    sp40 = (f64) sp10;
                    sp48 = sp8;
                    sp50 = (f64) sp10;
                    var_r21_468 = (((f32) sp40 * (f32) sp40) + (((f32) sp38 * (f32) sp38) + (unksp3C * unksp3C))) < temp_f0_559;
                }
                if ((var_r21_468 != 0) && (arg6 != NULL) && ((arg7 - 0.001f) < 3.1415927f)) {
                    temp_r3_597 = M2C_FIELD((*temp_r31_639)->unk8.unk0(temp_r31_639), void **, 8);
                    sp98 = M2C_FIELD(temp_r3_597, f64 *, 0x30);
                    spA0 = M2C_FIELD(temp_r3_597, f64 *, 0x38);
                    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r26, 0x0, qr0 */);
                    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
                    spD8 = sp28;
                    sp30 = (f32) spA0 - arg3->unk8;
                    spE0 = (f64) sp30;
                    if (((arg6->unk8 * (f32) spE0) + ((arg6->unk0 * (f32) spD8) + (arg6->unk4 * unkspDC))) < temp_f31_421) {
                        var_r21_468 = 0;
                    }
                }
                if (var_r21_468 != 0) {
                    *(arg0 + var_r22_419) = temp_r31_639;
                    var_r30_418 += 1;
                    var_r22_419 += 4;
                }
            }
            var_r29_425 += 4;
            goto loop_20;
        }
    }
    return var_r30_418;
}
#endif

TargetManager ***TargetManager::Begin() {
    return this->unk0;
}

#if 0 // DRAFT: ambiguous access to overloaded function
void TargetManager::Remove(Targetable *arg0) {
    TargetManager ***temp_r3_700;
    TargetManager ***var_r4_684;
    TargetManager **temp_r0_693;

    if ((arg0 != NULL) && (this->unk8.Get() == arg0)) {
        this->unk8.Set(NULL);
    }
    var_r4_684 = this->unk0;
loop_7:
    temp_r0_693 = *var_r4_684;
    if (temp_r0_693 == NULL) {
        var_r4_684 = NULL;
    } else if (temp_r0_693 == arg0) {

    } else {
        var_r4_684 += 4;
        goto loop_7;
    }
    if (var_r4_684 != NULL) {
        temp_r3_700 = this->unk0;
        this->unk0 = temp_r3_700 + 4;
        *var_r4_684 = *temp_r3_700;
    }
}
#endif

#if 0 // DRAFT: type mismatch
void TargetManager::Add(Targetable *arg0) {
    TargetManager ***temp_r4_740;
    TargetManager ***var_r3_722;
    TargetManager **temp_r0_731;

    var_r3_722 = this->unk0;
loop_4:
    temp_r0_731 = *var_r3_722;
    if (temp_r0_731 == NULL) {
        var_r3_722 = NULL;
    } else if (temp_r0_731 == arg0) {

    } else {
        var_r3_722 += 4;
        goto loop_4;
    }
    if (var_r3_722 == NULL) {
        temp_r4_740 = this->unk0 - 4;
        this->unk0 = temp_r4_740;
        *temp_r4_740 = (TargetManager **) arg0;
        GetNewTargetID();
        arg0->unk4 = M2C_ERROR(/* Read from unset register $r3 */);
    }
    if (arg0->Update() != 0) {
        if (((void **(*)(TargetManager **, f64, f32)) arg0->unk4) == (void **(*)(TargetManager **, f64, f32))-1) {
            GetNewTargetID();
            arg0->unk4 = M2C_ERROR(/* Read from unset register $r3 */);
        }
        this->unk8.Set(arg0);
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk4'
void TargetManager::Clear() {
loop_2:
    if ((TargetManager **) *this->unk0 != NULL) {
        this->unk0 += 4;
        goto loop_2;
    }
    this->unk4 = 0;
    this->unk8.Set(NULL);
}
#endif

#if 0 // DRAFT: undefined identifier 'unk4'
void TargetManager::GetNewTargetID() {
    this->unk4 += 1;
}
#endif

#if 0 // DRAFT: type mismatch
void TargetManager::Deinit() {
    MKHeap *temp_r3_828;
    TargetManager ***temp_r31_824;
    TargetManager ***temp_r3_819;

    do {
        temp_r3_819 = this->unk0 - 4;
        this->unk0 = temp_r3_819;
    } while ((TargetManager **) *temp_r3_819 != NULL);
    temp_r31_824 = this->unk0;
    if (temp_r31_824 != &gEmptyPtrList) {
        temp_r3_828 = temp_r3_819->Current();
        if (temp_r3_828 != NULL) {
            ((MKHeap *) (temp_r3_828->Current()))->Free(temp_r31_824, NULL, 0);
        } else {
            free(temp_r31_824);
        }
    }
    this->unk0 = NULL;
    pTargetManager.__vptr = NULL;
    this->unk4 = 0;
    this->unk8.Set(NULL);
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void TargetManager::Init() {
    MKHeap *temp_r3_863;
    TargetManager ***temp_r3_885;
    TargetManager ***temp_r5_890;
    TargetManager ***var_r3_870;
    s32 var_ctr_883;

    temp_r3_863 = MKHeap::Current();
    if (temp_r3_863 != NULL) {
        var_r3_870 = ((MKHeap *) (temp_r3_863->Current()))->Alloc(0x788, NULL, 0);
    } else {
        var_r3_870 = malloc(0x788);
    }
    this->unk0 = var_r3_870;
    M2C_FIELD(this->unk0, TargetManager ***, 0) = NULL;
    var_ctr_883 = 0x1E0;
    do {
        temp_r3_885 = this->unk0;
        this->unk0 = temp_r3_885 + 4;
        M2C_FIELD(temp_r3_885, s32 *, 4) = 0xDEADBEEF;
        var_ctr_883 -= 1;
    } while (var_ctr_883 != 0);
    temp_r5_890 = this->unk0;
    this->unk0 = temp_r5_890 + 4;
    M2C_FIELD(temp_r5_890, s32 *, 4) = 0;
    pTargetManager.__vptr = this;
    this->unk4 = 0;
    this->unk8.Set(NULL);
}
#endif

#if 0 // DRAFT: expression syntax error
void Targetable::UnregisterTargetable() {
    pTargetManager.__vptr->Remove(this);
    this->unk4 = (void **(*)(TargetManager **, f64, f32))-1;
}
#endif

#if 0 // DRAFT: ';' expected
void Targetable::RegisterTargetable() {
    pTargetManager.__vptr->Add(this);
}
#endif

s32 AttackerManager::GetAttackerCount(int arg0) {
    TargetContext **temp_r3_958;
    TargetContext **var_r30_952;
    TargetContext *temp_r3_978;
    TargetContext *temp_r4_961;
    s32 var_r31_951;

    var_r31_951 = 0;
    var_r30_952 = this->unk0;
loop_6:
    if (var_r30_952 != NULL) {
        temp_r3_978 = *var_r30_952;
        if (temp_r3_978 != NULL) {
            if (temp_r3_978->Get() == NULL) {
                temp_r3_958 = this->unk0;
                this->unk0 = temp_r3_958 + 4;
                temp_r4_961 = *temp_r3_958;
                *temp_r3_958 = *var_r30_952;
                *var_r30_952 = temp_r4_961;
            } else if (arg0 == (s32) (arg0 & (*var_r30_952)->unk8)) {
                var_r31_951 += 1;
            }
            var_r30_952 += 4;
            goto loop_6;
        }
    }
    return var_r31_951;
}

void AttackerManager::Remove(Targetable *arg0, int arg1) {
    TargetContext **temp_r3_1015;
    TargetContext **var_r31_1001;
    TargetContext *temp_r3_1007;
    TargetContext *temp_r3_1028;
    TargetContext *temp_r4_1018;

    if (arg0 != NULL) {
        var_r31_1001 = this->unk0;
loop_6:
        if ((var_r31_1001 == NULL) || (temp_r3_1028 = *var_r31_1001, ((temp_r3_1028 == NULL) != 0))) {

        } else if (temp_r3_1028->Get() == arg0) {
            temp_r3_1007 = *var_r31_1001;
            temp_r3_1007->unk8 &= ~arg1;
            if ((s32) (*var_r31_1001)->unk8 == 0) {
                temp_r3_1015 = this->unk0;
                this->unk0 = temp_r3_1015 + 4;
                temp_r4_1018 = *temp_r3_1015;
                *temp_r3_1015 = *var_r31_1001;
                *var_r31_1001 = temp_r4_1018;
            }
        } else {
            var_r31_1001 += 4;
            goto loop_6;
        }
    }
}

void AttackerManager::Add(Targetable *arg0, int arg1) {
    TargetContext **temp_r3_1075;
    TargetContext **temp_r3_1079;
    TargetContext **var_r31_1050;
    TargetContext *temp_r31_1082;
    TargetContext *temp_r3_1071;
    TargetContext *temp_r4_1056;

    if (arg0 != NULL) {
        var_r31_1050 = this->unk0;
loop_5:
        if ((var_r31_1050 == NULL) || (temp_r3_1071 = *var_r31_1050, ((temp_r3_1071 == NULL) != 0))) {
            temp_r3_1075 = this->unk0;
            if ((u32) M2C_FIELD(temp_r3_1075, u32 *, -4) != 0U) {
                temp_r3_1079 = temp_r3_1075 - 4;
                this->unk0 = temp_r3_1079;
                temp_r31_1082 = *temp_r3_1079;
                temp_r31_1082->Set(arg0);
                temp_r31_1082->unkC = M2C_FIELD(&gb, f32 *, 0x30C);
                temp_r31_1082->unk8 = arg1;
            }
        } else {
            if (temp_r3_1071->Get() == arg0) {
                temp_r4_1056 = *var_r31_1050;
                temp_r4_1056->unk8 |= arg1;
                (*var_r31_1050)->unkC = M2C_FIELD(&gb, f32 *, 0x30C);
                return;
            }
            var_r31_1050 += 4;
            goto loop_5;
        }
    }
}

void AttackerManager::Reset() {
loop_2:
    if ((TargetContext *) *this->unk0 != NULL) {
        this->unk0 += 4;
        goto loop_2;
    }
}

#if 0 // DRAFT: type mismatch
void AttackerManager::Deinit() {
    MKHeap *temp_r3_1149;
    TargetContext **var_r31_1123;
    TargetContext **var_r3_1124;
    TargetContext **var_r4_1122;
    TargetContext *temp_r0_1127;
    TargetContext *temp_r0_1146;
    u32 temp_r0_1132;

    var_r4_1122 = this->unk0;
    var_r31_1123 = var_r4_1122;
    var_r3_1124 = var_r4_1122;
loop_3:
    temp_r0_1132 = M2C_FIELD(var_r3_1124, u32 *, -4);
    var_r3_1124 -= 4;
    if (temp_r0_1132 != 0U) {
        temp_r0_1127 = *var_r3_1124;
        if (temp_r0_1127 < var_r31_1123) {
            var_r31_1123 = (TargetContext **) temp_r0_1127;
        }
        goto loop_3;
    }
    if (var_r3_1124 != &gEmptyPtrListDL) {
loop_9:
        temp_r0_1146 = *var_r4_1122;
        if (temp_r0_1146 != NULL) {
            if (temp_r0_1146 < var_r31_1123) {
                var_r31_1123 = (TargetContext **) temp_r0_1146;
            }
            var_r4_1122 += 4;
            goto loop_9;
        }
        temp_r3_1149 = var_r3_1124->Current();
        if (temp_r3_1149 != NULL) {
            ((MKHeap *) (temp_r3_1149->Current()))->Free(var_r31_1123, NULL, 0);
        } else {
            free((TargetManager ***) var_r31_1123);
        }
    }
    this->unk0 = NULL;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long *' to
void AttackerManager::Init(int arg0) {
    MKHeap *temp_r3_1186;
    TargetContext **temp_r3_1209;
    TargetContext **temp_r3_1216;
    TargetContext **temp_r3_1223;
    TargetContext **var_r5_1208;
    TargetManager ***var_r3_1196;
    s32 var_ctr_1212;

    if (arg0 == 0) {
        this->unk0 = &gEmptyPtrListDL + 4;
        return;
    }
    temp_r3_1186 = MKHeap::Current();
    if (temp_r3_1186 != NULL) {
        var_r3_1196 = ((MKHeap *) (temp_r3_1186->Current()))->Alloc(((arg0 + 2) * 4) + (arg0 * 0x10), NULL, 0);
    } else {
        var_r3_1196 = malloc(((arg0 + 2) * 4) + (arg0 * 0x10));
    }
    this->unk0 = (TargetContext **) var_r3_1196;
    var_r5_1208 = this->unk0;
    temp_r3_1209 = var_r5_1208 + (arg0 * 0x10);
    this->unk0 = temp_r3_1209;
    *temp_r3_1209 = NULL;
    var_ctr_1212 = arg0;
    if (arg0 > 0) {
        do {
            temp_r3_1216 = this->unk0;
            this->unk0 = temp_r3_1216 + 4;
            M2C_FIELD(temp_r3_1216, TargetContext ***, 4) = var_r5_1208;
            var_r5_1208 += 0x10;
            var_ctr_1212 -= 1;
        } while (var_ctr_1212 != 0);
    }
    temp_r3_1223 = this->unk0;
    this->unk0 = temp_r3_1223 + 4;
    M2C_FIELD(temp_r3_1223, TargetContext ***, 4) = NULL;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long *' to
void TargetContext::Set(MKProp *arg0) {
    Targetable *sp10;
    s32 spC;
    s32 sp8;

    spC = 0;
    sp10 = NULL;
    sp8 = 0x8E;
    if (arg0 != NULL) {
        arg0->Message(&sp8);
        Set(sp10);
        return;
    }
    Set(NULL);
}
#endif

#if 0 // DRAFT: undefined identifier 'unk0'
void TargetContext::Set(Targetable *arg0) {
    Targetable *temp_r4_1278;

    this->unk4 = arg0;
    this->unk0 = (void **(*)(TargetManager **, f64, f32))-1;
    temp_r4_1278 = this->unk4;
    if (temp_r4_1278 != NULL) {
        this->unk0 = temp_r4_1278->unk4;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk0'
Targetable *TargetContext::Get() {
    Targetable *temp_r4_1293;
    u8 var_r5_1290;
    void **(*temp_r6_1289)(TargetManager **, f64, f32);

    temp_r6_1289 = this->unk0;
    var_r5_1290 = 0;
    if (temp_r6_1289 >= 0) {
        temp_r4_1293 = this->unk4;
        if ((temp_r4_1293 != NULL) && (temp_r6_1289 == ((void **(*)(TargetManager **, f64, f32)) temp_r4_1293->unk4))) {
            var_r5_1290 = 1;
        }
    }
    if (var_r5_1290 != 0) {
        return this->unk4;
    }
    return NULL;
}
#endif
