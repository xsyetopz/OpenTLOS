#include "common/Source/OmniLight.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKView.h"
#include <m2c_macros.h>

M2C_UNK free(M2C_UNK *);                            /* extern */
M2C_UNK *malloc(M2C_UNK);                           /* extern */
extern u8 bSuspendAll;
extern M2C_UNK gEmptyPtrListDL;
extern M2C_UNK *lightList;

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'MKVector3'
void OmniLight::CalculateColor(const MKVector3 &arg0, const MKVector3 &arg1) {
    f64 sp48;                                       /* compiler-managed */
    f64 sp40;                                       /* compiler-managed */
    f64 sp38;
    f64 sp30;
    f32 sp28;
    f64 sp20;
    f64 sp18;
    f64 sp10;
    f32 sp8;
    f32 temp_f0_143;
    f32 temp_f5_131;
    f32 temp_f6_125;
    f32 temp_f7_127;
    f32 var_f2_137;
    f32 var_f3_35;
    f32 var_f5_118;
    f32 var_f6_34;
    f64 temp_f1_149;
    f64 temp_f2_57;
    f64 temp_f2_63;
    f64 temp_f2_67;
    s32 temp_r5_86;
    s32 var_r0_96;

    sp20 = M2C_FIELD(&arg1, f64 *, 0) - M2C_FIELD(&arg0, f64 *, 0x10);
    sp40 = sp20;
    sp28 = arg1.unk8 - M2C_FIELD(&arg0, f32 *, 0x18);
    sp48 = (f64) sp28;
    var_f6_34 = ((f32) sp48 * (f32) sp48) + (((f32) sp40 * (f32) sp40) + (unksp44 * unksp44));
    var_f3_35 = var_f6_34 / M2C_FIELD(&arg0, f32 *, 0x24);
    if (var_f3_35 < 1.0f) {

    } else {
        var_f3_35 = 1.0f;
    }
    if (var_f3_35 > 0.0f) {

    } else {
        var_f3_35 = 0.0f;
    }
    if (var_f6_34 > 0.000001f) {
        if (var_f6_34 > 0.0f) {
            temp_f2_57 = __frsqrte(var_f6_34);
            temp_f2_63 = 0.5 * temp_f2_57 * -(((f64) var_f6_34 * (temp_f2_57 * temp_f2_57)) - 3.0);
            temp_f2_67 = 0.5 * temp_f2_63 * -(((f64) var_f6_34 * (temp_f2_63 * temp_f2_63)) - 3.0);
            var_f6_34 = (f32) ((f64) var_f6_34 * (0.5 * temp_f2_67 * -(((f64) var_f6_34 * (temp_f2_67 * temp_f2_67)) - 3.0)));
        } else if (var_f6_34 < M2C_BITWISE(f32, 0.0)) {
            var_f6_34 = __float_nan;
        } else {
            sp8 = var_f6_34;
            temp_r5_86 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r5_86) {                   /* irregular */
            case 0x7F800000:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_96 = 1;
                } else {
                    var_r0_96 = 2;
                }
                break;
            case 0x0:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_96 = 5;
                } else {
                    var_r0_96 = 3;
                }
                break;
            default:
                var_r0_96 = 4;
                break;
            }
            if (var_r0_96 == 1) {
                var_f6_34 = __float_nan;
            }
        }
        var_f5_118 = 1.0f / var_f6_34;
    } else {
        var_f5_118 = 0.0f;
    }
    temp_f6_125 = unksp44 * var_f5_118;
    temp_f7_127 = (f32) sp40 * var_f5_118;
    temp_f5_131 = (f32) sp48 * var_f5_118;
    sp40 = temp_f7_127;
    unksp44 = temp_f6_125;
    var_f2_137 = (temp_f5_131 * M2C_FIELD(M2C_ERROR(/* Read from unset register $r6 */), f32 *, 8)) + ((temp_f7_127 * *M2C_ERROR(/* Read from unset register $r6 */)) + (temp_f6_125 * M2C_FIELD(M2C_ERROR(/* Read from unset register $r6 */), f32 *, 4)));
    sp48 = temp_f5_131;
    if (var_f2_137 < 0.0f) {
        var_f2_137 = -var_f2_137;
    }
    temp_f0_143 = (1.0f - var_f3_35) * var_f2_137;
    sp10 = M2C_FIELD(&arg0, f64 *, 0) * (f64) temp_f0_143;
    temp_f1_149 = M2C_FIELD(&arg0, f64 *, 8) * (f64) temp_f0_143;
    sp18 = temp_f1_149;
    sp38 = temp_f1_149;
    unksp3C = 1.0f;
    this->unk0 = sp10;
    sp30 = sp10;
    this->unk8 = sp38;
}
#endif

#if 0 // DRAFT: illegal type
s32 OmniLight_FindNearestGroup(const MKVector3 &arg0, float arg1, OmniLight **arg2, int arg3) {
    M2C_UNK spDC;
    M2C_UNK sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    M2C_UNK *temp_r3_202;
    M2C_UNK *temp_r5_222;
    M2C_UNK *temp_r7_279;
    M2C_UNK *var_r8_186;
    f32 temp_f0_207;
    f32 temp_f0_256;
    f32 temp_f1_257;
    f64 temp_f0_225;
    s32 *temp_r7_262;
    s32 temp_r4_264;
    s32 temp_r9_231;
    s32 var_ctr_250;
    s32 var_ctr_284;
    s32 var_r27_180;
    s32 var_r31_179;
    s32 var_r3_249;
    s32 var_r3_283;
    void *temp_r5_255;
    void *temp_r6_187;

    var_r31_179 = 0;
    var_r27_180 = 0;
    if (((u8) bSuspendAll == 0) && ((s32) *OmniLight::totalEnabled != 0)) {
        var_r8_186 = lightList;
        temp_r6_187 = MKView_GetCameraMatrix() + 0x30;
loop_11:
        temp_r7_279 = *var_r8_186;
        if (temp_r7_279 != NULL) {
            if ((u8) M2C_FIELD(temp_r7_279, u8 *, 0x30) != 0) {
                sp8 = M2C_FIELD(&arg0, f64 *, 0) - *(temp_r7_279 + 0x10);
                temp_r3_202 = *var_r8_186;
                sp48 = sp8;
                sp10 = arg0.unk8 - M2C_FIELD(temp_r7_279, f32 *, 0x18);
                temp_f0_207 = arg1 + M2C_FIELD(temp_r3_202, f32 *, 0x20);
                sp50 = (f64) sp10;
                sp38 = sp8;
                sp40 = (f64) sp10;
                if ((((f32) sp50 * (f32) sp50) + (((f32) sp48 * (f32) sp48) + (unksp4C * unksp4C))) < (temp_f0_207 * temp_f0_207)) {
                    temp_r5_222 = temp_r3_202 + 0x10;
                    temp_f0_225 = M2C_FIELD(temp_r6_187, f64 *, 0) - M2C_FIELD(temp_r5_222, f64 *, 0);
                    sp18 = temp_f0_225;
                    temp_r9_231 = var_r31_179 - 1;
                    *(&sp58 + var_r27_180) = temp_r7_279;
                    sp28 = temp_f0_225;
                    sp20 = M2C_FIELD(temp_r6_187, f32 *, 8) - M2C_FIELD(temp_r5_222, f32 *, 8);
                    sp30 = (f64) sp20;
                    *(&spDC + var_r27_180) = ((f32) sp30 * (f32) sp30) + (((f32) sp28 * (f32) sp28) + (unksp2C * unksp2C));
                    var_r3_249 = temp_r9_231 * 4;
                    var_ctr_250 = temp_r9_231 + 1;
                    if (temp_r9_231 >= 0) {
loop_6:
                        temp_r5_255 = &spDC + var_r3_249;
                        temp_f0_256 = M2C_FIELD(temp_r5_255, f32 *, 0);
                        temp_f1_257 = M2C_FIELD(temp_r5_255, f32 *, 4);
                        if (temp_f0_256 > temp_f1_257) {
                            M2C_FIELD(temp_r5_255, f32 *, 0) = temp_f1_257;
                            temp_r7_262 = &sp58 + var_r3_249;
                            temp_r4_264 = M2C_FIELD(temp_r7_262, s32 *, 0);
                            var_r3_249 -= 4;
                            M2C_FIELD(temp_r5_255, f32 *, 4) = temp_f0_256;
                            M2C_FIELD(temp_r7_262, s32 *, 0) = M2C_FIELD(temp_r7_262, s32 *, 4);
                            M2C_FIELD(temp_r7_262, s32 *, 4) = temp_r4_264;
                            var_ctr_250 -= 1;
                            if (var_ctr_250 != 0) {
                                goto loop_6;
                            }
                        }
                    }
                    if (var_r31_179 < arg3) {
                        var_r31_179 += 1;
                        var_r27_180 += 4;
                    }
                }
            }
            var_r8_186 += 4;
            goto loop_11;
        }
        var_r3_283 = 0;
        var_ctr_284 = var_r31_179;
        if (var_r31_179 > 0) {
            do {
                *(arg2 + var_r3_283) = *(&sp58 + var_r3_283);
                var_r3_283 += 4;
                var_ctr_284 -= 1;
            } while (var_ctr_284 != 0);
        }
    }
    return var_r31_179;
}
#endif

#if 0 // DRAFT: illegal type
void OmniLight_FindNearest(const MKVector3 &arg0, float arg1) {
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    M2C_UNK *temp_r3_330;
    M2C_UNK *temp_r3_339;
    M2C_UNK *temp_r3_359;
    M2C_UNK *temp_r3_390;
    M2C_UNK *var_r31_315;
    M2C_UNK *var_r5_324;
    f32 temp_f1_344;
    f32 temp_f1_380;
    f32 var_f0_322;
    f64 temp_f1_362;
    void *temp_r4_323;

    var_r31_315 = NULL;
    if (((u8) bSuspendAll == 0) && ((s32) *OmniLight::totalEnabled != 0)) {
        var_f0_322 = 0.0f;
        temp_r4_323 = MKView_GetCameraMatrix() + 0x30;
        var_r5_324 = lightList;
loop_9:
        temp_r3_390 = *var_r5_324;
        if (temp_r3_390 != NULL) {
            if ((u8) M2C_FIELD(temp_r3_390, u8 *, 0x30) != 0) {
                temp_r3_330 = temp_r3_390 + 0x10;
                sp8 = M2C_FIELD(&arg0, f64 *, 0) - M2C_FIELD(temp_r3_330, f64 *, 0);
                temp_r3_339 = *var_r5_324;
                sp48 = sp8;
                sp10 = arg0.unk8 - M2C_FIELD(temp_r3_330, f32 *, 8);
                temp_f1_344 = arg1 + M2C_FIELD(temp_r3_339, f32 *, 0x20);
                sp50 = (f64) sp10;
                sp38 = sp8;
                sp40 = (f64) sp10;
                if (((((f32) sp50 * (f32) sp50) + (((f32) sp48 * (f32) sp48) + (unksp4C * unksp4C))) < (temp_f1_344 * temp_f1_344)) && ((temp_r3_359 = temp_r3_339 + 0x10, temp_f1_362 = M2C_FIELD(temp_r4_323, f64 *, 0) - M2C_FIELD(temp_r3_359, f64 *, 0), sp18 = temp_f1_362, sp28 = temp_f1_362, sp20 = M2C_FIELD(temp_r4_323, f32 *, 8) - M2C_FIELD(temp_r3_359, f32 *, 8), sp30 = (f64) sp20, temp_f1_380 = ((f32) sp30 * (f32) sp30) + (((f32) sp28 * (f32) sp28) + (unksp2C * unksp2C)), ((var_r31_315 == NULL) != 0)) || (temp_f1_380 < var_f0_322))) {
                    var_r31_315 = *var_r5_324;
                    var_f0_322 = temp_f1_380;
                }
            }
            var_r5_324 += 4;
            goto loop_9;
        }
    }
}
#endif

u8 OmniLight_SuspendAll(bool arg0) {
    u8 temp_r0_407;

    temp_r0_407 = bSuspendAll;
    bSuspendAll = arg0;
    return temp_r0_407;
}

#if 0 // DRAFT: illegal implicit conversion from 'long' to
void OmniLight_Destroy(OmniLight *arg0) {
    M2C_UNK *temp_r0_441;
    M2C_UNK *temp_r3_430;
    M2C_UNK *temp_r5_433;
    M2C_UNK *var_r4_425;

    if ((u8) arg0->unk30 != 0) {
        arg0->unk30 = 0;
        *OmniLight::totalEnabled -= 1;
    }
    var_r4_425 = lightList;
loop_6:
    temp_r0_441 = *var_r4_425;
    if (temp_r0_441 == NULL) {
        return;
    }
    if (temp_r0_441 == arg0) {
        temp_r3_430 = lightList;
        lightList = temp_r3_430 + 4;
        temp_r5_433 = *temp_r3_430;
        *temp_r3_430 = *var_r4_425;
        *var_r4_425 = temp_r5_433;
        return;
    }
    var_r4_425 += 4;
    goto loop_6;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long' to
void OmniLight_Create() {
    M2C_UNK *temp_r31_457;
    M2C_UNK *temp_r3_455;

    temp_r3_455 = lightList - 4;
    lightList = temp_r3_455;
    temp_r31_457 = *temp_r3_455;
    if (temp_r31_457 != NULL) {
        memset(temp_r31_457, 0, 0x38U);
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long' to
void OmniLight_DeinitModule() {
    M2C_UNK *temp_r0_485;
    M2C_UNK *temp_r0_504;
    M2C_UNK *var_r31_481;
    M2C_UNK *var_r3_482;
    M2C_UNK *var_r4_480;
    MKHeap *temp_r3_507;
    u32 temp_r0_490;

    var_r4_480 = lightList;
    var_r31_481 = var_r4_480;
    var_r3_482 = var_r4_480;
loop_3:
    temp_r0_490 = M2C_FIELD(var_r3_482, u32 *, -4);
    var_r3_482 -= 4;
    if (temp_r0_490 != 0U) {
        temp_r0_485 = *var_r3_482;
        if (temp_r0_485 < var_r31_481) {
            var_r31_481 = temp_r0_485;
        }
        goto loop_3;
    }
    if (var_r3_482 != &gEmptyPtrListDL) {
loop_9:
        temp_r0_504 = *var_r4_480;
        if (temp_r0_504 != NULL) {
            if (temp_r0_504 < var_r31_481) {
                var_r31_481 = temp_r0_504;
            }
            var_r4_480 += 4;
            goto loop_9;
        }
        temp_r3_507 = ((MKHeap *) var_r3_482)->Current();
        if (temp_r3_507 != NULL) {
            ((MKHeap *) (temp_r3_507->Current()))->Free(var_r31_481, NULL, 0);
        } else {
            free(var_r31_481);
        }
    }
    lightList = NULL;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void *' to
void OmniLight_InitModule() {
    M2C_UNK *var_r3_542;
    MKHeap *temp_r3_535;
    s32 var_ctr_554;

    temp_r3_535 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_535 != NULL) {
        var_r3_542 = ((MKHeap *) (temp_r3_535->Current()))->Alloc(0x788, NULL, 0);
    } else {
        var_r3_542 = malloc(0x788);
    }
    lightList = var_r3_542;
    lightList = var_r3_542 + 0x700;
    M2C_FIELD(var_r3_542, s32 *, 0x700) = 0;
    var_ctr_554 = 0x20;
    do {
        lightList += 4;
        M2C_FIELD(lightList, M2C_UNK **, 4) = var_r3_542;
        var_r3_542 += 0x38;
        var_ctr_554 -= 1;
    } while (var_ctr_554 != 0);
    lightList += 4;
    M2C_FIELD(lightList, M2C_UNK **, 4) = NULL;
}
#endif
