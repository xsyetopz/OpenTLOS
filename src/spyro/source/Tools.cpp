#include "spyro/source/Tools.h"
#include "common/Source/Animation.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKMemoryCard.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKView.h"
#include "common/Source/Matrix.h"
#include "spyro/source/KDSpline.h"
#include "unplaced_enums.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKSystem.h"
#include "common/Source/Str.h"
#include "common/Source/Timer.h"
#include "common/gc/MKMaterial_GC.h"
#include "spyro/source/KDSound.h"
#include <m2c_macros.h>

M2C_UNK free(void *);                               /* extern */
void *malloc(s32);                                  /* extern */
s32 stricmp(s8 *, s8 *);                            /* extern */
extern s32 Tools_PropCreator_Count;
extern s8 *Tools_PropCreator_Name;
extern MKSceneManager *gMK;
extern M2C_UNK gb;
extern s32 pauseSndCount;
#if 0 // DRAFT: illegal implicit conversion from 'long' to
static M2C_UNK Tools_ClosestPropsPos;               /* unable to generate initializer: unknown type */
static M2C_UNK lit_1474;                               /* unable to generate initializer: unknown type; const */

MKMaterial *Tools_GetMatchingMaterial(MKModel *arg0, const char *arg1) {
    MKMaterial *temp_r3_56;
    s16 temp_r31_49;
    s32 var_r29_50;

    if (arg1 != NULL) {
        temp_r31_49 = MKModel_GetNmbrOfMaterials(arg0);
        var_r29_50 = 0;
loop_5:
        if (var_r29_50 >= temp_r31_49) {
            goto block_6;
        }
        temp_r3_56 = MKModel_GetMaterial(arg0, var_r29_50, 1U);
        MKMaterial_GetName(temp_r3_56);
        if (stricmp(arg1) == 0) {
            return temp_r3_56;
        }
        var_r29_50 += 1;
        goto loop_5;
    }
block_6:
    return NULL;
}
#endif

Tools_Ortho::~Tools_Ortho() {
    MKView_Pop();
    MKMaterial_EnableFog(this->unk0);
}

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
Tools_Ortho::Tools_Ortho() {
    s32 sp14;
    f32 sp10;
    s32 spC;
    f32 sp8;
    f32 var_f0_131;
    f32 var_f0_139;
    s32 temp_cr0_eq_120;
    u8 temp_r3_118;

    this->unk0 = MKMaterial_EnableFog(0U);
    MKView_Push();
    temp_r3_118 = System_IsWideScreenEnabled();
    temp_cr0_eq_120 = temp_r3_118 == 0;
    sp8 = M2C_FIELD(&lit_1474, f32 *, 0);
    spC = M2C_FIELD(&lit_1474, s32 *, 4);
    sp10 = M2C_FIELD(&lit_1474, f32 *, 8);
    sp14 = M2C_FIELD(&lit_1474, s32 *, 0xC);
    if (temp_cr0_eq_120 == 0) {
        var_f0_131 = -108.0f;
    } else {
        var_f0_131 = 0.0f;
    }
    sp8 = var_f0_131;
    if (temp_r3_118 != 0) {
        var_f0_139 = 856.0f;
    } else {
        var_f0_139 = 640.0f;
    }
    sp10 = var_f0_139;
    MKView_SetOrtho((MKRect *) &sp8);
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier 'sp20'
void Tools_CalculateVelocity(const MKVector3 &arg0, const MKVector3 &arg1, float arg2, float arg3) {
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f32 sp28;
    f32 sp18;
    f32 sp8;
    f32 temp_f6_245;
    f32 var_f6_179;
    f64 temp_f3_182;
    f64 temp_f3_188;
    f64 temp_f3_192;
    s32 temp_r6_211;
    s32 var_r0_221;

    M2C_ERROR(/* unknown instruction: psq_lx $f3, $zero, $r5, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r4, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f3, $f0 */);
    sp40 = sp20;
    sp28 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r5 */), f32 *, 8) - arg1.unk8;
    unksp44 = 0.0f;
    sp48 = (f64) sp28;
    var_f6_179 = ((f32) sp48 * (f32) sp48) + (((f32) sp40 * (f32) sp40) + (0.0f * 0.0f));
    if (var_f6_179 > 0.0f) {
        temp_f3_182 = __frsqrte(var_f6_179);
        temp_f3_188 = 0.5 * temp_f3_182 * -(((f64) var_f6_179 * (temp_f3_182 * temp_f3_182)) - 3.0);
        temp_f3_192 = 0.5 * temp_f3_188 * -(((f64) var_f6_179 * (temp_f3_188 * temp_f3_188)) - 3.0);
        var_f6_179 = (f32) ((f64) var_f6_179 * (0.5 * temp_f3_192 * -(((f64) var_f6_179 * (temp_f3_192 * temp_f3_192)) - 3.0)));
    } else if (var_f6_179 < M2C_BITWISE(f32, 0.0)) {
        var_f6_179 = __float_nan;
    } else {
        sp8 = var_f6_179;
        temp_r6_211 = M2C_BITWISE(s32, sp8) & 0x7F800000;
        switch (temp_r6_211) {                      /* irregular */
        case 0x7F800000:
            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                var_r0_221 = 1;
            } else {
                var_r0_221 = 2;
            }
            break;
        case 0x0:
            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                var_r0_221 = 5;
            } else {
                var_r0_221 = 3;
            }
            break;
        default:
            var_r0_221 = 4;
            break;
        }
        if (var_r0_221 == 1) {
            var_f6_179 = __float_nan;
        }
    }
    if (var_f6_179 > 0.0f) {
        temp_f6_245 = var_f6_179 / arg2;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f1 */);
        sp18 = (f32) sp48 * (1.0f / temp_f6_245);
        sp30 = sp10;
        sp38 = (f64) sp18;
        unksp34 = -((0.5f * arg3 * temp_f6_245) - ((M2C_FIELD(M2C_ERROR(/* Read from unset register $r5 */), f32 *, 4) - arg1.unk4) / temp_f6_245));
        M2C_FIELD(&arg0, f64 *, 0) = sp30;
        M2C_FIELD(&arg0, f64 *, 8) = (f64) sp18;
        return;
    }
    M2C_FIELD(&arg0, f64 *, 0) = (f64) M2C_FIELD(&MKVector3::zero, f64 *, 0);
    M2C_FIELD(&arg0, f64 *, 8) = (f64) M2C_FIELD(&MKVector3::zero, f64 *, 8);
}
#endif

#if 0 // DRAFT: undefined identifier 'sp20'
s32 Tools_GetPointDistanceFromLine(const MKVector3 &arg0, const MKVector3 &arg1, const MKVector3 &arg2, float *arg3) {
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f32 sp28;
    f32 sp18;
    f32 spC;
    f32 sp8;
    f32 temp_f10_384;
    f32 temp_f11_385;
    f32 temp_f2_394;
    f32 temp_f2_406;
    f32 temp_f4_390;
    f32 temp_f6_377;
    f32 temp_f7_373;
    f32 temp_f8_383;
    f32 temp_f9_380;
    f32 var_f4_304;
    f32 var_f4_426;
    f64 temp_f1_307;
    f64 temp_f1_313;
    f64 temp_f1_317;
    f64 temp_f1_429;
    f64 temp_f1_435;
    f64 temp_f1_439;
    s32 temp_r3_458;
    s32 temp_r7_336;
    s32 var_r0_346;
    s32 var_r0_468;

    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r5, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r4, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    sp40 = sp20;
    sp28 = arg2.unk8 - arg1.unk8;
    sp48 = (f64) sp28;
    var_f4_304 = ((f32) sp48 * (f32) sp48) + (((f32) sp40 * (f32) sp40) + (unksp44 * unksp44));
    if (var_f4_304 > 0.0f) {
        temp_f1_307 = __frsqrte(var_f4_304);
        temp_f1_313 = 0.5 * temp_f1_307 * -(((f64) var_f4_304 * (temp_f1_307 * temp_f1_307)) - 3.0);
        temp_f1_317 = 0.5 * temp_f1_313 * -(((f64) var_f4_304 * (temp_f1_313 * temp_f1_313)) - 3.0);
        var_f4_304 = (f32) ((f64) var_f4_304 * (0.5 * temp_f1_317 * -(((f64) var_f4_304 * (temp_f1_317 * temp_f1_317)) - 3.0)));
    } else if (var_f4_304 < M2C_BITWISE(f32, 0.0)) {
        var_f4_304 = __float_nan;
    } else {
        spC = var_f4_304;
        temp_r7_336 = M2C_BITWISE(s32, spC) & 0x7F800000;
        switch (temp_r7_336) {                      /* switch 1; irregular */
        case 0x7F800000:                            /* switch 1 */
            if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                var_r0_346 = 1;
            } else {
                var_r0_346 = 2;
            }
            break;
        case 0x0:                                   /* switch 1 */
            if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                var_r0_346 = 5;
            } else {
                var_r0_346 = 3;
            }
            break;
        default:                                    /* switch 1 */
            var_r0_346 = 4;
            break;
        }
        if (var_r0_346 == 1) {
            var_f4_304 = __float_nan;
        }
    }
    if (var_f4_304 == 0.0f) {
        return 0;
    }
    temp_f7_373 = arg1.unk0;
    temp_f6_377 = arg1.unk4;
    temp_f9_380 = arg2.unk0 - temp_f7_373;
    temp_f8_383 = arg1.unk8;
    temp_f10_384 = arg2.unk4 - temp_f6_377;
    temp_f11_385 = arg0.unk8;
    temp_f4_390 = arg2.unk8 - temp_f8_383;
    temp_f2_394 = (((temp_f11_385 - temp_f8_383) * temp_f4_390) + (((arg0.unk0 - temp_f7_373) * temp_f9_380) + ((arg0.unk4 - temp_f6_377) * temp_f10_384))) / (var_f4_304 * var_f4_304);
    if ((temp_f2_394 < 0.0f) || (temp_f2_394 > 1.0f)) {
        return 0;
    }
    temp_f2_406 = (temp_f2_394 * temp_f4_390) + temp_f8_383;
    sp50 = (temp_f2_394 * temp_f9_380) + temp_f7_373;
    sp54 = (temp_f2_394 * temp_f10_384) + temp_f6_377;
    sp58 = temp_f2_406;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r3, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    sp18 = temp_f11_385 - temp_f2_406;
    sp30 = sp10;
    sp38 = (f64) sp18;
    var_f4_426 = ((f32) sp38 * (f32) sp38) + (((f32) sp30 * (f32) sp30) + (unksp34 * unksp34));
    if (var_f4_426 > 0.0f) {
        temp_f1_429 = __frsqrte(var_f4_426);
        temp_f1_435 = 0.5 * temp_f1_429 * -(((f64) var_f4_426 * (temp_f1_429 * temp_f1_429)) - 3.0);
        temp_f1_439 = 0.5 * temp_f1_435 * -(((f64) var_f4_426 * (temp_f1_435 * temp_f1_435)) - 3.0);
        var_f4_426 = (f32) ((f64) var_f4_426 * (0.5 * temp_f1_439 * -(((f64) var_f4_426 * (temp_f1_439 * temp_f1_439)) - 3.0)));
    } else if (var_f4_426 < M2C_BITWISE(f32, 0.0)) {
        var_f4_426 = __float_nan;
    } else {
        sp8 = var_f4_426;
        temp_r3_458 = M2C_BITWISE(s32, sp8) & 0x7F800000;
        switch (temp_r3_458) {                      /* switch 2; irregular */
        case 0x7F800000:                            /* switch 2 */
            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                var_r0_468 = 1;
            } else {
                var_r0_468 = 2;
            }
            break;
        case 0x0:                                   /* switch 2 */
            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                var_r0_468 = 5;
            } else {
                var_r0_468 = 3;
            }
            break;
        default:                                    /* switch 2 */
            var_r0_468 = 4;
            break;
        }
        if (var_r0_468 == 1) {
            var_f4_426 = __float_nan;
        }
    }
    *arg3 = var_f4_426;
    return 1;
}
#endif

void Tools_UnPauseAll() {
    pauseSndCount = 0;
    KDSound_PauseAll(0U);
}

void Tools_ResetEachInstance(MKPropDescriptor *arg0) {
    void *var_r31_521;

    if (arg0 != NULL) {
        var_r31_521 = arg0->unk28;
loop_3:
        if (var_r31_521 != NULL) {
            M2C_FIELD(M2C_FIELD(var_r31_521, void **, 0x44), M2C_UNK (**)(void *), 0x20)(var_r31_521);
            var_r31_521 = M2C_FIELD(var_r31_521, void **, 0x38);
            goto loop_3;
        }
    }
}

#if 0 // DRAFT: illegal implicit conversion from 'bool *' to
void Tools_PushOut(MKCollisionResult *arg0, MKVector3 &arg1, int arg2, float arg3, bool *arg4, float arg5) {
    PushOutResult spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    MKVector3 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f32 sp38;
    f32 sp28;
    f32 sp18;
    f32 sp8;
    f32 temp_f8_637;
    s32 var_ctr_564;
    s32 var_r11_552;
    s32 var_r12_557;
    s32 var_r4_553;
    s32 var_r7_558;
    s32 var_r8_563;
    u8 *var_r6_0;
    u8 var_r0_571;
    u8 var_r31_562;
    void *temp_r10_570;
    void *temp_r8_598;
    void *temp_r9_561;

    var_r6_0 = arg4;
    sp8 = arg3;
    var_r11_552 = 0;
    var_r4_553 = 0;
    if ((u8) arg0->unk50 != 0) {
        var_r12_557 = 0;
        var_r7_558 = 0;
loop_14:
        if (var_r12_557 < arg2) {
            temp_r9_561 = arg0 + var_r7_558;
            var_r31_562 = 0;
            var_r8_563 = 0;
            var_ctr_564 = var_r11_552;
            if (var_r11_552 > 0) {
loop_3:
                temp_r10_570 = &spA0 + var_r8_563;
                var_r0_571 = 0;
                if ((M2C_FIELD(temp_r9_561, f32 *, 0) == M2C_FIELD(temp_r10_570, f32 *, 0)) && (M2C_FIELD(temp_r9_561, f32 *, 4) == M2C_FIELD(temp_r10_570, f32 *, 4)) && (M2C_FIELD(temp_r9_561, f32 *, 8) == M2C_FIELD(temp_r10_570, f32 *, 8))) {
                    var_r0_571 = 1;
                }
                if (var_r0_571 != 0) {
                    var_r31_562 = 1;
                } else {
                    var_r8_563 += 0x20;
                    var_ctr_564 -= 1;
                    if (var_ctr_564 != 0) {
                        goto loop_3;
                    }
                }
            }
            if (var_r31_562 == 0) {
                *var_r6_0 = 1;
                temp_r8_598 = &spA0 + var_r4_553;
                var_r11_552 += 1;
                var_r4_553 += 0x20;
                M2C_FIELD(temp_r8_598, f64 *, 0) = (f64) M2C_FIELD(temp_r9_561, f32 *, 0);
                M2C_FIELD(temp_r8_598, f64 *, 8) = (f64) M2C_FIELD(temp_r9_561, f32 *, 8);
                M2C_FIELD(temp_r8_598, f64 *, 0x10) = (f64) M2C_FIELD(temp_r9_561, f64 *, 0x10);
                M2C_FIELD(temp_r8_598, f64 *, 0x18) = (f64) M2C_FIELD(temp_r9_561, f64 *, 0x18);
            } else {
                *var_r6_0 = 0;
            }
            var_r12_557 += 1;
            var_r6_0 += 1;
            var_r7_558 += 0x58;
            goto loop_14;
        }
        sp90 = M2C_FIELD(&arg1, f64 *, 0);
        sp98 = M2C_FIELD(&arg1, f64 *, 8);
        DoPush(&spA0, arg1, var_r11_552, sp8, arg5);
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r30, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_sub $f7, $f1, $f0 */);
        temp_f8_637 = arg1.unk8 - (f32) sp98;
        sp40 = sp20;
        sp28 = temp_f8_637;
        sp48 = (f64) sp28;
        sp50 = sp20;
        sp58 = (f64) sp28;
        if (!((((f32) sp48 * (f32) sp48) + (((f32) sp40 * (f32) sp40) + (unksp44 * unksp44))) < (sp8 * sp8))) {
            sp18 = temp_f8_637;
            sp60 = sp10;
            sp68 = (f64) sp18;
            ClampMagnitude(sp70, sp8);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            M2C_FIELD(&arg1, f64 *, 0) = sp30;
            sp38 = (f32) sp98 + sp70.unk8;
            sp80 = sp30;
            sp88 = (f64) sp38;
            M2C_FIELD(&arg1, f64 *, 8) = (f64) sp38;
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_sp10'
void DoPush(PushOutResult *arg0, MKVector3 &arg1, int arg2, float &arg3, float arg4) {
    f32 temp_f0_782;
    f32 temp_f0_828;
    f32 temp_f23_732;
    f32 temp_f4_990;
    f32 temp_f6_856;
    arg_sp10 = arg2;
    arg_sp108 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    arg_sp110 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
    temp_f23_732 = &arg3 * arg4;
    &arg3 = 0.0f;
    if (GetClosest(arg0, arg_sp10, arg1, *((MKVector3 *) &arg_sp108), arg3, temp_f23_732, *((PushOutResult *) &arg_sp160)) != 0) {
        arg_sp108 = arg_sp170;
        arg_sp110 = arg_sp178;
        if (GetClosest(arg0, arg_sp10, arg1, *((MKVector3 *) &arg_sp108), arg3, temp_f23_732, *((PushOutResult *) &arg_sp180)) != 0) {
loop_3:
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r26, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r31, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            arg_sp108 = arg_sp28;
            arg_sp30 = (f32) arg_sp178 + arg_sp198;
            arg_spA8 = arg_sp28;
            arg_sp110 = (f64) arg_sp30;
            arg_spB0 = (f64) arg_sp30;
            temp_f0_782 = ((f32) arg_sp110 * (f32) arg_sp178) + (((f32) arg_sp108 * (f32) arg_sp170) + (arg_sp10C * arg_sp174));
            if (!(temp_f0_782 < 0.01f)) {
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
                arg_sp110 = (f32) arg_sp110 * (1.0f / temp_f0_782);
                if (GetClosest(arg0, arg_sp10, arg1, *((MKVector3 *) &arg_sp108), arg3, temp_f23_732, *((PushOutResult *) &arg_sp1A0)) != 0) {
                    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r26, 0x0, qr0 */);
                    M2C_ERROR(/* unknown instruction: psq_lx $f7, $zero, $r29, 0x0, qr0 */);
                    M2C_ERROR(/* unknown instruction: ps_add $f0, $f0, $f7 */);
                    arg_spF8 = arg_sp78;
                    arg_sp80 = (f32) arg_sp178 + arg_sp1B8;
                    arg_sp100 = (f64) arg_sp80;
                    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f28 */);
                    temp_f0_828 = (f32) arg_sp100 * (1.0f / (((f32) arg_sp100 * (f32) arg_sp178) + (((f32) arg_spF8 * (f32) arg_sp170) + (arg_spFC * arg_sp174))));
                    arg_sp100 = temp_f0_828;
                    M2C_ERROR(/* unknown instruction: psq_lx $f4, $zero, $r31, 0x0, qr0 */);
                    M2C_ERROR(/* unknown instruction: ps_add $f4, $f4, $f7 */);
                    arg_spE8 = arg_sp68;
                    arg_sp70 = arg_sp198 + arg_sp1B8;
                    arg_spF0 = (f64) arg_sp70;
                    M2C_ERROR(/* unknown instruction: ps_muls0 $f4, $f4, $f27 */);
                    temp_f6_856 = (f32) arg_spF0 * (1.0f / (((f32) arg_spF0 * arg_sp198) + (((f32) arg_spE8 * arg_sp190) + (arg_spEC * arg_sp194))));
                    arg_spF0 = temp_f6_856;
                    if (((temp_f0_828 * arg_sp198) + (((f32) arg_spF8 * arg_sp190) + (arg_spFC * arg_sp194))) > 1.0f) {
                        arg_sp180 = arg_sp1A0;
                        arg_sp188 = arg_sp1A8;
                        arg_sp190 = arg_sp1B0;
                        arg_sp198 = (f64) arg_sp1B8;
                        goto loop_3;
                    }
                    if (((temp_f6_856 * (f32) arg_sp178) + (((f32) arg_spE8 * (f32) arg_sp170) + (arg_spEC * arg_sp174))) > 1.0f) {
                        arg_sp160 = arg_sp1A0;
                        arg_sp168 = arg_sp1A8;
                        arg_sp170 = arg_sp1B0;
                        arg_sp178 = (f64) arg_sp1B8;
                        goto loop_3;
                    }
                    arg_sp120.SetIdentity();
                    arg_sp120 = (f32) arg_sp170;
                    arg_sp124 = arg_sp174;
                    arg_sp128 = (f32) arg_sp178;
                    arg_sp12C = 0.0f;
                    arg_sp130 = arg_sp190;
                    arg_sp134 = arg_sp194;
                    arg_sp138 = arg_sp198;
                    arg_sp13C = 0.0f;
                    arg_sp140 = (f32) arg_sp1B0;
                    arg_sp144 = arg_sp1B4;
                    arg_sp148 = arg_sp1B8;
                    arg_sp14C = 0.0f;
                    arg_sp120.Transpose3x3((Matrix *) &arg_sp120);
                    arg_sp120.Inverse((Matrix *) &arg_sp120);
                    MKVector(1.0f, 1.0f, 1.0f);
                    arg_sp18 = (arg_sp90 * arg_sp140) + ((arg_sp88 * arg_sp120) + (arg_sp8C * arg_sp130));
                    arg_sp1C = (arg_sp90 * arg_sp144) + ((arg_sp88 * arg_sp124) + (arg_sp8C * arg_sp134));
                    arg_sp20 = (arg_sp90 * arg_sp148) + ((arg_sp88 * arg_sp128) + (arg_sp8C * arg_sp138));
                    arg_sp98 = (f64) arg_sp18;
                    arg_spA0 = (f64) arg_sp20;
                    arg_sp108 = (f64) arg_sp18;
                    arg_sp110 = (f64) arg_sp20;
                    if (GetClosest(arg0, arg_sp10, arg1, *((MKVector3 *) &arg_sp108), arg3, temp_f23_732, *((PushOutResult *) &arg_sp1C0)) != 0) {
                        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r26, 0x0, qr0 */);
                        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r27, 0x0, qr0 */);
                        M2C_ERROR(/* unknown instruction: ps_add $f1, $f1, $f0 */);
                        arg_spD8 = arg_sp58;
                        arg_sp60 = (f32) arg_sp178 + arg_sp1D8;
                        arg_spE0 = (f64) arg_sp60;
                        M2C_ERROR(/* unknown instruction: ps_muls0 $f1, $f1, $f26 */);
                        temp_f4_990 = (f32) arg_spE0 * (1.0f / (((f32) arg_spE0 * (f32) arg_sp178) + (((f32) arg_spD8 * (f32) arg_sp170) + (arg_spDC * arg_sp174))));
                        arg_spE0 = temp_f4_990;
                        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r31, 0x0, qr0 */);
                        M2C_ERROR(/* unknown instruction: ps_add $f1, $f1, $f0 */);
                        arg_spC8 = arg_sp48;
                        arg_sp50 = arg_sp198 + arg_sp1D8;
                        arg_spD0 = (f64) arg_sp50;
                        M2C_ERROR(/* unknown instruction: ps_muls0 $f7, $f7, $f25 */);
                        arg_spD0 = (f32) arg_spD0 * (1.0f / (((f32) arg_spD0 * arg_sp198) + (((f32) arg_spC8 * arg_sp190) + (arg_spCC * arg_sp194))));
                        M2C_ERROR(/* unknown instruction: psq_lx $f7, $zero, $r29, 0x0, qr0 */);
                        M2C_ERROR(/* unknown instruction: ps_add $f0, $f7, $f0 */);
                        arg_spB8 = arg_sp38;
                        arg_sp40 = arg_sp1B8 + arg_sp1D8;
                        arg_spC0 = (f64) arg_sp40;
                        M2C_ERROR(/* unknown instruction: ps_muls0 $f6, $f6, $f24 */);
                        arg_spC0 = (f32) arg_spC0 * (1.0f / (((f32) arg_spC0 * arg_sp1B8) + (((f32) arg_spB8 * (f32) arg_sp1B0) + (arg_spBC * arg_sp1B4))));
                        if ((((temp_f4_990 * arg_sp198) + (((f32) arg_spD8 * arg_sp190) + (arg_spDC * arg_sp194))) > 1.0f) && (((temp_f4_990 * arg_sp1B8) + (((f32) arg_spD8 * (f32) arg_sp1B0) + (arg_spDC * arg_sp1B4))) > 1.0f)) {
                            arg_sp180 = arg_sp1C0;
                            arg_sp188 = arg_sp1C8;
                            arg_sp190 = arg_sp1D0;
                            arg_sp198 = (f64) arg_sp1D8;
                            goto loop_3;
                        }
                        if (((((f32) arg_spD0 * (f32) arg_sp178) + (((f32) arg_spC8 * (f32) arg_sp170) + (arg_spCC * arg_sp174))) > 1.0f) && ((((f32) arg_spD0 * arg_sp1B8) + (((f32) arg_spC8 * (f32) arg_sp1B0) + (arg_spCC * arg_sp1B4))) > 1.0f)) {
                            arg_sp160 = arg_sp1C0;
                            arg_sp168 = arg_sp1C8;
                            arg_sp170 = arg_sp1D0;
                            arg_sp178 = (f64) arg_sp1D8;
                            goto loop_3;
                        }
                        if (((((f32) arg_spC0 * (f32) arg_sp178) + (((f32) arg_spB8 * (f32) arg_sp170) + (arg_spBC * arg_sp174))) > 1.0f) && ((((f32) arg_spC0 * arg_sp198) + (((f32) arg_spB8 * arg_sp190) + (arg_spBC * arg_sp194))) > 1.0f)) {
                            arg_sp160 = arg_sp1A0;
                            arg_sp168 = arg_sp1A8;
                            arg_sp170 = arg_sp1B0;
                            arg_sp178 = (f64) arg_sp1B8;
                            arg_sp180 = arg_sp1C0;
                            arg_sp188 = arg_sp1C8;
                            arg_sp190 = arg_sp1D0;
                            arg_sp198 = (f64) arg_sp1D8;
                            goto loop_3;
                        }
                    }
                }
            }
        }
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'int *' to
u8 GetClosest(PushOutResult *arg0, int &arg1, MKVector3 &arg2, const MKVector3 &arg3, float &arg4, float arg5, PushOutResult &arg6) {
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp10;
    PushOutResult *temp_r4_1252;
    PushOutResult *temp_r6_1239;
    f32 temp_f10_1179;
    f32 temp_f10_1196;
    f32 temp_f11_1183;
    f32 temp_f12_1188;
    f32 temp_f2_1202;
    f32 var_f0_1162;
    s32 temp_r0_1161;
    s32 temp_r5_1249;
    s32 var_ctr_1167;
    s32 var_r11_1156;
    s32 var_r12_1157;
    s32 var_r9_1160;
    void *temp_r10_1172;

    var_r11_1156 = -1;
    var_r12_1157 = 0;
    var_r9_1160 = 0;
    temp_r0_1161 = &arg1;
    var_f0_1162 = arg5 - &arg4;
    var_ctr_1167 = temp_r0_1161;
    if (temp_r0_1161 > 0) {
        do {
            M2C_ERROR(/* unknown instruction: psq_lx $f7, $zero, $r5, 0x0, qr0 */);
            temp_r10_1172 = arg0 + var_r9_1160;
            M2C_ERROR(/* unknown instruction: psq_lx $f2, $zero, $r10, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_sub $f2, $f7, $f2 */);
            temp_f10_1179 = M2C_FIELD(temp_r10_1172, f32 *, 0x14);
            sp38 = sp18;
            temp_f11_1183 = M2C_FIELD(temp_r10_1172, f32 *, 0x10);
            sp20 = arg2.unk8 - M2C_FIELD(temp_r10_1172, f32 *, 8);
            temp_f12_1188 = M2C_FIELD(temp_r10_1172, f32 *, 0x18);
            sp40 = (f64) sp20;
            temp_f10_1196 = 1.0f - ((arg3.unk8 * temp_f12_1188) + ((arg3.unk0 * temp_f11_1183) + (arg3.unk4 * temp_f10_1179)));
            M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
            if (temp_f10_1196 != 0.01f) {
                temp_f2_1202 = ((((f32) sp40 * temp_f12_1188) + (((f32) sp38 * temp_f11_1183) + (unksp3C * temp_f10_1179))) - &arg4) / temp_f10_1196;
                if (temp_f2_1202 < var_f0_1162) {
                    var_r11_1156 = var_r12_1157;
                    var_f0_1162 = temp_f2_1202;
                }
            }
            var_r12_1157 += 1;
            var_r9_1160 += 0x20;
            var_ctr_1167 -= 1;
        } while (var_ctr_1167 != 0);
    }
    &arg4 += var_f0_1162;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r6, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f1, $f1, $f0 */);
    sp28 = sp8;
    sp10 = arg3.unk8 * var_f0_1162;
    sp30 = (f64) sp10;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r5, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    M2C_ERROR(/* unknown instruction: psq_stx $f0, $zero, $r5, 0x0, qr0 */);
    arg2.unk8 += (f32) sp30;
    if (var_r11_1156 == -1) {
        return 0U;
    }
    temp_r6_1239 = &arg0[var_r11_1156];
    arg6.unk0 = temp_r6_1239->unk0;
    arg6.unk8 = temp_r6_1239->unk8;
    arg6.unk10 = temp_r6_1239->unk10;
    arg6.unk18 = temp_r6_1239->unk18;
    temp_r5_1249 = &arg1 - 1;
    &arg1 = temp_r5_1249;
    temp_r4_1252 = &arg0[temp_r5_1249];
    temp_r6_1239->unk0 = temp_r4_1252->unk0;
    temp_r6_1239->unk8 = temp_r4_1252->unk8;
    temp_r6_1239->unk10 = temp_r4_1252->unk10;
    temp_r6_1239->unk18 = temp_r4_1252->unk18;
    return 1U;
}
#endif

void Tools_PropCreator::Resolve() {
    MKProp::Resolve();
}

#if 0 // DRAFT: function call 'stricmp(signed char *, const char[1])' does not match
void Tools_PropCreator::LoadDone() {
    MKProp::LoadDone();
    if (stricmp(Tools_PropCreator_Name, "") == 0) {
        Tools_PropCreator_Name = NULL;
    }
    this->unk4C.Init(Tools_PropCreator_Name, Tools_PropCreator_Count);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long *' to
s32 Tools_PropCreator::LoadLine(MKIniLine *arg0) {
    s32 var_r31_1318;

    var_r31_1318 = 0;
    if ((MKProp::LoadLine(arg0) != 0) || (arg0->LoadInt("createPropCount", &Tools_PropCreator_Count, 0) != 0) || (arg0->LoadString("createPropName", &Tools_PropCreator_Name, 0) != 0)) {
        var_r31_1318 = 1;
    }
    return var_r31_1318;
}
#endif

void Tools_PropCreator::Deinit() {
    this->unk4C.Deinit();
    MKProp::Deinit();
}

void Tools_PropCreator::Init() {
    MKProp::Init();
    Tools_PropCreator_Count = 0;
    Tools_PropCreator_Name = NULL;
}

#if 0 // DRAFT: illegal use of non-static member
void Tools_PropCreatorObject::Deinit() {
    MKHeap *temp_r3_1397;
    void *temp_r31_1394;

    temp_r31_1394 = this->unk4;
    if (temp_r31_1394 != NULL) {
        temp_r3_1397 = MKHeap::Current();
        if (temp_r3_1397 != NULL) {
            ((MKHeap *) (temp_r3_1397->Current()))->Free(temp_r31_1394, NULL, 0);
        } else {
            free(temp_r31_1394);
        }
        this->unk4 = NULL;
    }
    this->unk0 = 0;
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void Tools_PropCreatorObject::Init(const char *arg0, int arg1) {
    MKHeap *temp_r3_1439;
    s32 temp_r0_1435;
    s32 temp_r31_1438;
    s32 var_r30_1453;
    s32 var_r31_1454;
    void *var_r3_1446;

    this->unk0 = arg1;
    this->unk4 = NULL;
    this->unk8 = 0;
    temp_r0_1435 = this->unk0;
    if (temp_r0_1435 != 0) {
        temp_r31_1438 = temp_r0_1435 * 4;
        temp_r3_1439 = MKHeap::Current();
        if (temp_r3_1439 != NULL) {
            var_r3_1446 = ((MKHeap *) (temp_r3_1439->Current()))->Alloc(temp_r31_1438, NULL, 0);
        } else {
            var_r3_1446 = malloc(temp_r31_1438);
        }
        this->unk4 = var_r3_1446;
        var_r30_1453 = 0;
        var_r31_1454 = 0;
loop_6:
        if (var_r30_1453 < (s32) this->unk0) {
            gMK->CreatePropDeferred(arg0, this->unk4 + var_r31_1454);
            var_r30_1453 += 1;
            var_r31_1454 += 4;
            goto loop_6;
        }
    }
}
#endif

void Tools_SendMessageHelper::ClearData() {
    memset(this, 0, 0x7FCU);
    this->unk7F8 = 0;
}

void Tools_SendMessageHelper::SendMessage(MKMessage *arg0, int arg1, float arg2) {
    s32 var_r30_1509;
    s32 var_r31_1510;
    void *temp_r3_1528;
    void *temp_r4_1519;
    void *temp_r5_1513;

    var_r30_1509 = 0;
    var_r31_1510 = 0;
loop_7:
    if (var_r30_1509 < (s32) this->unk7F8) {
        temp_r5_1513 = this + var_r31_1510;
        if ((M2C_FIELD(temp_r5_1513, f32 *, 4) < (arg2 * arg2)) && ((arg1 == 0) || ((temp_r4_1519 = M2C_FIELD(temp_r5_1513, void **, 0), (((arg1 & M2C_FIELD(M2C_FIELD(temp_r4_1519, void **, 0), s32 *, 0xC)) == 0) == 0)) && !(M2C_FIELD(temp_r4_1519, s32 *, 0x18) & 0x80000000)))) {
            temp_r3_1528 = M2C_FIELD(temp_r5_1513, void **, 0);
            M2C_FIELD(M2C_FIELD(temp_r3_1528, void **, 0x44), M2C_UNK (**)(void *, MKMessage *), 0x2C)(temp_r3_1528, arg0);
        }
        var_r30_1509 += 1;
        var_r31_1510 += 8;
        goto loop_7;
    }
}

#if 0 // DRAFT: illegal implicit conversion from 'long *' to
void Tools_SendMessageHelper::StoreClosestProps(const MKVector3 &arg0, float arg1, int arg2) {
    M2C_UNK sp18;
    f64 sp10;
    f64 sp8;
    f32 temp_f2_1613;
    f32 temp_f3_1610;
    f32 temp_f4_1609;
    s32 temp_r31_1576;
    s32 temp_r4_1599;
    s32 var_r26_1575;
    s32 var_r29_1579;
    void *temp_r3_1602;

    ClearData();
    var_r26_1575 = 0;
    temp_r31_1576 = gMK->GetPropsInRange(&sp18, 0xFF, arg0, arg2, 0, arg1);
    this->unk7F8 = 0;
    var_r29_1579 = 0;
loop_4:
    if (var_r29_1579 < temp_r31_1576) {
        if (gMK->IsEnabled(*(&sp18 + var_r26_1575), *MKResource::sWorkingChunkID) != 0) {
            *(this + (this->unk7F8 * 8)) = *(&sp18 + var_r26_1575);
            temp_r4_1599 = this->unk7F8 * 8;
            temp_r3_1602 = M2C_FIELD(*(this + temp_r4_1599), void **, 8);
            sp8 = M2C_FIELD(temp_r3_1602, f64 *, 0x30);
            sp10 = M2C_FIELD(temp_r3_1602, f64 *, 0x38);
            temp_f4_1609 = arg0.unk4 - unkspC;
            temp_f3_1610 = arg0.unk0 - (f32) sp8;
            temp_f2_1613 = arg0.unk8 - (f32) sp10;
            *(this + (temp_r4_1599 + 4)) = (temp_f2_1613 * temp_f2_1613) + ((temp_f3_1610 * temp_f3_1610) + (temp_f4_1609 * temp_f4_1609));
            this->unk7F8 += 1;
        }
        var_r29_1579 += 1;
        var_r26_1575 += 4;
        goto loop_4;
    }
}
#endif

void Tools_GetClosestSplineTimeXZ(KDUniformSpline *arg0, const MKVector3 &arg1, int arg2) {
    Tools_GetClosestSplineTimeXZ(arg0, arg1, arg2, 0.0f, 1.0f);
}

#if 0 // DRAFT: undefined identifier 'arg_sp3C'
f32 Tools_GetClosestSplineTimeXZ(KDUniformSpline *arg0, const MKVector3 &arg1, int arg2, float arg3, float arg4) {
    f32 temp_f0_1738;
    f32 temp_f1_1736;
    f32 temp_f28_1713;
    f32 temp_f29_1714;
    f32 temp_f2_1734;
    f32 var_f22_1717;
    f32 var_f24_1710;
    f32 var_f25_1708;
    f32 var_f31_1704;
    M2C_STRUCT_COPY((s32) &arg_sp3C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
    var_f31_1704 = 0.0f;
    arg_sp14 = 0.0f;
    var_f25_1708 = -1.0f;
    arg_sp10 = 0.0f;
    var_f24_1710 = 3.4028235e38f;
    temp_f28_1713 = arg1.unk0;
    temp_f29_1714 = arg1.unk8;
loop_6:
    if (var_f31_1704 < (f32) arg2) {
        var_f22_1717 = (((arg4 - arg3) / (f32) arg2) * var_f31_1704) + arg3;
        if (var_f22_1717 > 1.0f) {
            var_f22_1717 -= 1.0f;
        }
        arg_sp18.GetNextPositionFast(var_f22_1717, (Matrix *) arg0, &arg_sp40, &arg_sp14);
        arg_sp30 = arg_sp20;
        arg_sp28 = arg_sp18;
        temp_f2_1734 = (f32) arg_sp30 - temp_f29_1714;
        temp_f1_1736 = (f32) arg_sp28 - temp_f28_1713;
        temp_f0_1738 = (temp_f1_1736 * temp_f1_1736) + (temp_f2_1734 * temp_f2_1734);
        if (temp_f0_1738 < var_f24_1710) {
            var_f24_1710 = temp_f0_1738;
            var_f25_1708 = var_f22_1717;
        }
        var_f31_1704 += 1.0f;
        goto loop_6;
    }
    return var_f25_1708;
}
#endif

void Tools_GetClosestSplineTime(KDUniformSpline *arg0, const MKVector3 &arg1, int arg2) {
    Tools_GetClosestSplineTime(arg0, arg1, arg2, 0.0f, 1.0f);
}

#if 0 // DRAFT: undefined identifier 'arg_sp5C'
f32 Tools_GetClosestSplineTime(KDUniformSpline *arg0, const MKVector3 &arg1, int arg2, float arg3, float arg4) {
    f32 temp_f0_1889;
    f32 temp_f23_1855;
    f32 temp_f26_1859;
    f32 var_f27_1847;
    f32 var_f29_1853;
    f32 var_f30_1851;
    M2C_STRUCT_COPY((s32) &arg_sp5C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
    var_f27_1847 = 0.0f;
    arg_sp14 = 0.0f;
    var_f30_1851 = -1.0f;
    arg_sp10 = 0.0f;
    var_f29_1853 = 3.4028235e38f;
    temp_f23_1855 = arg1.unk8;
loop_4:
    if (var_f27_1847 < (f32) arg2) {
        temp_f26_1859 = (((arg4 - arg3) / (f32) arg2) * var_f27_1847) + arg3;
        arg_sp38.GetNextPositionFast(temp_f26_1859, (Matrix *) arg0, &arg_sp60, &arg_sp14);
        arg_sp48 = arg_sp38;
        arg_sp50 = arg_sp40;
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r29, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
        arg_sp28 = arg_sp18;
        arg_sp20 = (f32) arg_sp50 - temp_f23_1855;
        arg_sp30 = (f64) arg_sp20;
        temp_f0_1889 = ((f32) arg_sp30 * (f32) arg_sp30) + (((f32) arg_sp28 * (f32) arg_sp28) + (arg_sp2C * arg_sp2C));
        if (temp_f0_1889 < var_f29_1853) {
            var_f29_1853 = temp_f0_1889;
            var_f30_1851 = temp_f26_1859;
        }
        var_f27_1847 += 1.0f;
        goto loop_4;
    }
    return var_f30_1851;
}
#endif

void Tools_EnableWideScreen(bool arg0) {
    f32 var_f1_1941;

    System_EnableWideScreenMode(arg0);
    if (arg0 != 0) {
        var_f1_1941 = 1.7777778f;
    } else {
        var_f1_1941 = 1.3333334f;
    }
    MKView_SetAspectRatio(var_f1_1941);
}

#if 0 // DRAFT: undefined identifier 'unksp24'
s32 Tools_Line2DToCircleIntersect(const MKVector3 &arg0, const MKVector3 &arg1, const MKVector3 &arg2, float arg3, float &arg4) {
    f64 sp28;
    f64 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 sp8;
    f32 temp_f0_2040;
    f32 temp_f5_2020;
    f32 temp_f6_1999;
    f32 temp_f7_2033;
    f32 var_f5_2046;
    f64 temp_f1_2049;
    f64 temp_f1_2055;
    f64 temp_f1_2059;
    s32 temp_r3_2078;
    s32 var_r0_2088;

    temp_f6_1999 = arg3 * arg3;
    sp14 = 0.0f;
    sp10 = arg2.unk0 - arg0.unk0;
    sp18 = arg2.unk8 - arg0.unk8;
    sp20 = (f64) sp10;
    sp28 = (f64) sp18;
    temp_f5_2020 = ((f32) sp28 * (f32) sp28) + (((f32) sp20 * (f32) sp20) + (unksp24 * unksp24));
    M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
    if (temp_f5_2020 == temp_f6_1999) {
        &arg4 = 0.0f;
        return 1;
    }
    temp_f7_2033 = ((f32) sp28 * arg1.unk8) + (((f32) sp20 * arg1.unk0) + (unksp24 * arg1.unk4));
    if (temp_f7_2033 < 0.0f) {
        return 0;
    }
    temp_f0_2040 = temp_f5_2020 - (temp_f7_2033 * temp_f7_2033);
    if (temp_f0_2040 > temp_f6_1999) {
        return 0;
    }
    var_f5_2046 = temp_f6_1999 - temp_f0_2040;
    if (var_f5_2046 > 0.0f) {
        temp_f1_2049 = __frsqrte(var_f5_2046);
        temp_f1_2055 = 0.5 * temp_f1_2049 * -(((f64) var_f5_2046 * (temp_f1_2049 * temp_f1_2049)) - 3.0);
        temp_f1_2059 = 0.5 * temp_f1_2055 * -(((f64) var_f5_2046 * (temp_f1_2055 * temp_f1_2055)) - 3.0);
        var_f5_2046 = (f32) ((f64) var_f5_2046 * (0.5 * temp_f1_2059 * -(((f64) var_f5_2046 * (temp_f1_2059 * temp_f1_2059)) - 3.0)));
    } else if (var_f5_2046 < M2C_BITWISE(f32, 0.0)) {
        var_f5_2046 = __float_nan;
    } else {
        sp8 = var_f5_2046;
        temp_r3_2078 = M2C_BITWISE(s32, sp8) & 0x7F800000;
        switch (temp_r3_2078) {                     /* irregular */
        case 0x7F800000:
            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                var_r0_2088 = 1;
            } else {
                var_r0_2088 = 2;
            }
            break;
        case 0x0:
            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                var_r0_2088 = 5;
            } else {
                var_r0_2088 = 3;
            }
            break;
        default:
            var_r0_2088 = 4;
            break;
        }
        if (var_r0_2088 == 1) {
            var_f5_2046 = __float_nan;
        }
    }
    &arg4 = temp_f7_2033 - var_f5_2046;
    return 1;
}
#endif

#if 0 // DRAFT: pointer/array required
void Tools_GetClosestPtOnLine2D(const MKVector3 &arg0, const MKVector3 &arg1, const MKVector3 &arg2) {
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    MKVector3 sp38;
    f32 sp30;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f1_2173;
    f32 temp_f4_2122;
    f32 temp_f4_2155;
    f32 temp_f5_2133;

    temp_f4_2122 = arg1.unk0;
    sp8 = arg2.unk0 - temp_f4_2122;
    temp_f5_2133 = arg1.unk8;
    spC = 0.0f;
    sp10 = arg2.unk8 - temp_f5_2133;
    sp48 = (f64) sp8;
    sp50 = (f64) sp10;
    sp20 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r6 */), f32 *, 8) - temp_f5_2133;
    sp18 = *M2C_ERROR(/* Read from unset register $r6 */) - temp_f4_2122;
    sp1C = 0.0f;
    temp_f4_2155 = ((f32) sp50 * (f32) sp50) + (((f32) sp48 * (f32) sp48) + (unksp4C * unksp4C));
    sp60 = (f64) sp20;
    sp58 = (f64) sp18;
    if (temp_f4_2155 == 0.0f) {
        M2C_FIELD(&arg0, f64 *, 0) = (f64) M2C_FIELD(&arg2, f32 *, 0);
        M2C_FIELD(&arg0, f64 *, 8) = (f64) M2C_FIELD(&arg2, f32 *, 8);
        return;
    }
    temp_f1_2173 = (((f32) sp60 * (f32) sp50) + (((f32) sp58 * (f32) sp48) + (unksp5C * unksp4C))) / temp_f4_2155;
    if (temp_f1_2173 < 0.0f) {
        M2C_FIELD(&arg0, f64 *, 0) = (f64) M2C_FIELD(&arg1, f32 *, 0);
        M2C_FIELD(&arg0, f64 *, 8) = (f64) M2C_FIELD(&arg1, f32 *, 8);
        return;
    }
    if (temp_f1_2173 > 1.0f) {
        M2C_FIELD(&arg0, f64 *, 0) = (f64) M2C_FIELD(&arg2, f32 *, 0);
        M2C_FIELD(&arg0, f64 *, 8) = (f64) M2C_FIELD(&arg2, f32 *, 8);
        return;
    }
    __ml(temp_f1_2173, sp38);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r31, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    M2C_FIELD(&arg0, f64 *, 0) = sp28;
    sp30 = arg1.unk8 + sp38.unk8;
    M2C_FIELD(&arg0, f64 *, 8) = (f64) sp30;
}
#endif

s32 Tools_Line2DToLine2DIntersect(const MKVector3 &arg0, const MKVector3 &arg1, const MKVector3 &arg2, const MKVector3 &arg3, float *arg4) {
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f0_2300;
    f32 temp_f4_2247;
    f32 temp_f4_2282;
    f32 temp_f5_2238;
    f32 temp_f7_2236;
    f32 temp_f7_2288;
    f32 temp_f8_2241;

    temp_f7_2236 = arg2.unk0;
    temp_f5_2238 = arg0.unk8;
    temp_f8_2241 = arg2.unk8;
    temp_f4_2247 = arg0.unk0;
    sp20 = arg1.unk8 - temp_f5_2238;
    sp10 = arg3.unk8 - temp_f8_2241;
    sp8 = arg3.unk0 - temp_f7_2236;
    sp30 = temp_f5_2238 - temp_f8_2241;
    sp40 = (f64) sp10;
    spC = 0.0f;
    sp50 = (f64) sp20;
    sp60 = (f64) sp30;
    sp38 = (f64) sp8;
    sp28 = temp_f4_2247 - temp_f7_2236;
    sp2C = 0.0f;
    sp18 = arg1.unk0 - temp_f4_2247;
    sp58 = (f64) sp28;
    sp1C = 0.0f;
    sp48 = (f64) sp18;
    temp_f4_2282 = ((f32) sp48 * (f32) sp40) - ((f32) sp50 * (f32) sp38);
    if (temp_f4_2282 == 0.0f) {
        return 0;
    }
    temp_f7_2288 = (((f32) sp60 * (f32) sp38) - ((f32) sp58 * (f32) sp40)) / temp_f4_2282;
    if ((temp_f7_2288 < 0.0f) || (temp_f7_2288 > 1.0f)) {
        return 0;
    }
    temp_f0_2300 = (((f32) sp60 * (f32) sp48) - ((f32) sp58 * (f32) sp50)) / temp_f4_2282;
    if ((temp_f0_2300 < 0.0f) || (temp_f0_2300 > 1.0f)) {
        return 0;
    }
    if (arg4 != NULL) {
        *arg4 = temp_f7_2288;
    }
    return 1;
}

#if 0 // DRAFT: undefined identifier 'sp8'
void Tools_UpdateSphereCollideResults(MKCollisionResult *arg0, int arg1, const MKVector3 &arg2) {
    f64 sp40;
    f64 sp38;
    MKVector3 sp28;
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f32 temp_f30_2332;
    f64 temp_f5_2354;
    s32 var_r29_2335;
    s32 var_r31_2336;
    void *temp_r30_2340;

    temp_f30_2332 = arg2.unk8;
    var_r29_2335 = 0;
    var_r31_2336 = 0;
loop_4:
    if (var_r29_2335 < arg1) {
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r28, 0x0, qr0 */);
        temp_r30_2340 = arg0 + var_r31_2336;
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r30, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
        sp18 = sp8;
        sp10 = temp_f30_2332 - M2C_FIELD(temp_r30_2340, f32 *, 8);
        sp20 = (f64) sp10;
        Normalise(sp28);
        temp_f5_2354 = M2C_BITWISE(f64, sp28);
        sp38 = temp_f5_2354;
        sp40 = (f64) sp28.unk8;
        if ((((f32) sp40 * M2C_FIELD(temp_r30_2340, f32 *, 0x18)) + (((f32) sp38 * M2C_FIELD(temp_r30_2340, f32 *, 0x10)) + (unksp3C * M2C_FIELD(temp_r30_2340, f32 *, 0x14)))) > -0.95f) {
            M2C_FIELD(temp_r30_2340, f32 *, 0x10) = temp_f5_2354;
            M2C_FIELD(temp_r30_2340, f32 *, 0x18) = (f64) sp28.unk8;
        }
        var_r29_2335 += 1;
        var_r31_2336 += 0x58;
        goto loop_4;
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long *' to
void Tools_ResolvableProp::LoadLine(MKIniLine *arg0, const char *arg1) {
    arg0->LoadInt(arg1, &this->unk4, 0);
}
#endif

#if 0 // DRAFT: undefined identifier '__float_nan'
void Tools_SetMatrixScale(Matrix *arg0, float arg1) {
    f32 sp8;
    f32 temp_f2_2415;
    f32 temp_f3_2414;
    f32 temp_f4_2417;
    f32 var_f5_2421;
    f64 temp_f2_2424;
    f64 temp_f2_2430;
    f64 temp_f2_2434;
    s32 temp_r4_2453;
    s32 var_r0_2463;

    temp_f3_2414 = arg0->unk0;
    temp_f2_2415 = arg0->unk4;
    temp_f4_2417 = arg0->unk8;
    var_f5_2421 = (temp_f4_2417 * temp_f4_2417) + ((temp_f3_2414 * temp_f3_2414) + (temp_f2_2415 * temp_f2_2415));
    if (var_f5_2421 > 0.0f) {
        temp_f2_2424 = __frsqrte(var_f5_2421);
        temp_f2_2430 = 0.5 * temp_f2_2424 * -(((f64) var_f5_2421 * (temp_f2_2424 * temp_f2_2424)) - 3.0);
        temp_f2_2434 = 0.5 * temp_f2_2430 * -(((f64) var_f5_2421 * (temp_f2_2430 * temp_f2_2430)) - 3.0);
        var_f5_2421 = (f32) ((f64) var_f5_2421 * (0.5 * temp_f2_2434 * -(((f64) var_f5_2421 * (temp_f2_2434 * temp_f2_2434)) - 3.0)));
    } else if (var_f5_2421 < M2C_BITWISE(f32, 0.0)) {
        var_f5_2421 = __float_nan;
    } else {
        sp8 = var_f5_2421;
        temp_r4_2453 = M2C_BITWISE(s32, sp8) & 0x7F800000;
        switch (temp_r4_2453) {                     /* irregular */
        case 0x7F800000:
            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                var_r0_2463 = 1;
            } else {
                var_r0_2463 = 2;
            }
            break;
        case 0x0:
            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                var_r0_2463 = 5;
            } else {
                var_r0_2463 = 3;
            }
            break;
        default:
            var_r0_2463 = 4;
            break;
        }
        if (var_r0_2463 == 1) {
            var_f5_2421 = __float_nan;
        }
    }
    if (var_f5_2421 > 0.00001f) {
        arg0->Scale3x3(arg0, arg1 / var_f5_2421);
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'GetWaterHeight'
s32 Tools_GetFloor(const MKVector3 &arg0, float arg1, float *arg2) {
    u8 sp60;
    s32 sp5C;
    s32 sp58;
    s32 sp54;
    f32 sp50;
    s32 sp4C;
    s8 sp4B;
    s8 sp4A;
    s16 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    MKVector3 sp8;
    f32 temp_f0_2540;

    sp8.unk8 = 0.0f;
    sp8.unkC = 0.0f;
    sp18 = 0.0f;
    sp20 = 0.0f;
    sp24 = 0.0f;
    sp28 = 0.0f;
    sp30 = 0.0f;
    sp34 = 0.0f;
    sp38 = 0.0f;
    sp3C = 1.0f;
    sp40 = 0.0f;
    sp44 = 0.0f;
    sp48 = 0;
    sp4A = 0;
    sp4B = 0;
    sp4C = 0;
    sp50 = 3.4028235e38f;
    sp54 = 0;
    sp58 = 0;
    sp5C = -1;
    sp60 = 0;
    if ((arg0.GetWaterHeight(sp8, arg1, &sp8.unk8, (MKCollisionResult *)0x200, 0) != 0) && (sp60 != 0)) {
        temp_f0_2540 = M2C_BITWISE(f32, sp8);
        if (temp_f0_2540 > sp8.unkC) {
            if (arg2 != NULL) {
                *arg2 = temp_f0_2540;
            }
            return 1;
        }
        if (arg2 != NULL) {
            *arg2 = sp8.unkC;
        }
        return 2;
    }
    if (sp60 != 0) {
        if (arg2 != NULL) {
            *arg2 = sp8.unkC;
        }
        return 2;
    }
    return 0;
}
#endif

#if 0 // DRAFT: undefined identifier 'sp18'
f32 Tools_CylinderTest(const MKVector3 &arg0, const MKVector3 &arg1, float arg2, const MKVector3 &arg3) {
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp10;
    f32 temp_f10_2588;
    f32 temp_f1_2621;
    f32 temp_f7_2603;
    f32 var_f1_2637;

    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r4, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: psq_lx $f3, $zero, $r3, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f0, $f3 */);
    temp_f10_2588 = arg0.unk8;
    sp58 = sp18;
    sp20 = arg1.unk8 - temp_f10_2588;
    sp60 = (f64) sp20;
    sp38 = sp18;
    sp40 = (f64) sp20;
    temp_f7_2603 = ((f32) sp60 * (f32) sp60) + (((f32) sp58 * (f32) sp58) + (unksp5C * unksp5C));
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r5, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f0, $f3 */);
    sp48 = sp8;
    sp10 = arg3.unk8 - temp_f10_2588;
    sp50 = (f64) sp10;
    sp28 = sp8;
    temp_f1_2621 = ((f32) sp60 * (f32) sp50) + (((f32) sp58 * (f32) sp48) + (unksp5C * unksp4C));
    sp30 = (f64) sp10;
    M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
    if ((temp_f1_2621 == 0.0f) || (temp_f1_2621 > temp_f7_2603)) {
        return -1.0f;
    }
    var_f1_2637 = (((f32) sp50 * (f32) sp50) + (((f32) sp48 * (f32) sp48) + (unksp4C * unksp4C))) - ((temp_f1_2621 * temp_f1_2621) / temp_f7_2603);
    if (var_f1_2637 > (arg2 * arg2)) {
        var_f1_2637 = -1.0f;
    }
    return var_f1_2637;
}
#endif

void Tools_TestFloor(const MKVector3 &arg0, MKCollisionResult *arg1, float arg2, MKCollisionMode arg3) {
    MKCollisionResult sp28;
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    MKCollisionResult *var_r4_0;

    var_r4_0 = arg1;
    if (var_r4_0 != NULL) {

    } else {
        var_r4_0 = &sp28;
    }
    sp8 = arg0.unk0;
    spC = arg0.unk4 - arg2;
    sp10 = arg0.unk8;
    sp18 = (f64) sp8;
    sp20 = (f64) sp10;
    MKCollision_RayCollide(arg0, *((MKVector3 *) &sp18), var_r4_0, arg3, 0);
}

#if 0 // DRAFT: illegal type
void Tools_GroundColor(MKCollisionResult *arg0) {
    f64 sp48;
    f64 sp40;
    s32 sp3C;
    s32 sp38;
    f64 sp30;                                       /* compiler-managed */
    f64 sp28;                                       /* compiler-managed */
    f64 sp20;
    f64 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    MKModel *temp_r3_2722;
    f32 temp_f31_2696;
    f32 temp_f6_2742;
    f32 temp_f6_2761;
    f64 *temp_r3_2725;
    f64 temp_f1_2730;
    void *temp_r3_2707;
    void *var_r31_2710;

    sp8 = 1.0f;
    temp_f31_2696 = M2C_FIELD(&gb, f32 *, 0x314);
    spC = 1.0f;
    sp10 = 1.0f;
    sp14 = 1.0f;
    sp18 = (f64) sp8;
    sp20 = (f64) sp10;
    sp28 = (f64) sp8;
    sp30 = (f64) sp10;
    if (((u8) M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), u8 *, 0x50) != 0) && (temp_r3_2707 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), void **, 0x48), ((temp_r3_2707 == NULL) == 0)) && (var_r31_2710 = M2C_FIELD(temp_r3_2707, void **, 8), ((var_r31_2710 == NULL) == 0))) {

    } else {
        var_r31_2710 = NULL;
    }
    if ((var_r31_2710 != NULL) && ((u32) (var_r31_2710 + 0x10000) != -1U) && (temp_r3_2722 = M2C_FIELD(var_r31_2710, MKModel **, 4), ((temp_r3_2722 == NULL) == 0))) {
        temp_r3_2725 = MKModel_GetColor(temp_r3_2722);
        sp3C = 0;
        temp_f1_2730 = M2C_FIELD(temp_r3_2725, f64 *, 0);
        sp40 = temp_f1_2730;
        sp48 = M2C_FIELD(temp_r3_2725, f64 *, 8);
        sp38 = 0x808;
        M2C_FIELD(M2C_FIELD(var_r31_2710, void **, 0x44), M2C_UNK (**)(void *, s32 *, f64), 0x2C)(var_r31_2710, &sp38, temp_f1_2730);
        temp_f6_2742 = 1.0f - temp_f31_2696;
        sp28 = ((f32) sp40 * temp_f31_2696) + ((f32) sp28 * temp_f6_2742);
        unksp2C = (unksp44 * temp_f31_2696) + (unksp2C * temp_f6_2742);
        sp30 = ((f32) sp48 * temp_f31_2696) + ((f32) sp30 * temp_f6_2742);
    } else {
        temp_f6_2761 = 1.0f - temp_f31_2696;
        sp28 = (M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), f32 *, 0x20) * temp_f31_2696) + (sp28 * temp_f6_2761);
        unksp2C = (M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), f32 *, 0x24) * temp_f31_2696) + (unksp2C * temp_f6_2761);
        sp30 = (M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), f32 *, 0x28) * temp_f31_2696) + (sp30 * temp_f6_2761);
    }
    if (sp28 > 1.0f) {
        sp28 = 1.0f;
    }
    if (unksp2C > 1.0f) {
        unksp2C = 1.0f;
    }
    if (sp30 > 1.0f) {
        sp30 = 1.0f;
    }
    M2C_FIELD(arg0, f64 *, 0) = (f64) sp28;
    M2C_FIELD(arg0, f64 *, 8) = (f64) sp30;
}
#endif

#if 0 // DRAFT: pointer/array required
void Tools_GetGradient(const MKVector3 &arg0) {
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 sp8;
    f32 temp_f10_2818;
    f32 temp_f7_2815;
    f32 temp_f8_2820;
    f32 var_f0_2812;
    f32 var_f4_2879;
    f64 temp_f1_2884;
    f64 temp_f1_2890;
    f64 temp_f1_2894;
    s32 temp_r4_2913;
    s32 var_r0_2923;

    var_f0_2812 = 0.0f;
    sp58 = 0.0f;
    temp_f7_2815 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), f32 *, 8);
    sp50 = 0.0f;
    temp_f10_2818 = *M2C_ERROR(/* Read from unset register $r4 */);
    sp88 = (f64) sp58;
    temp_f8_2820 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), f32 *, 4);
    sp54 = 1.0f;
    sp80 = (f64) sp50;
    sp44 = (temp_f7_2815 * (f32) sp80) - (temp_f10_2818 * (f32) sp88);
    sp40 = (temp_f8_2820 * (f32) sp88) - (temp_f7_2815 * unksp84);
    sp48 = (temp_f10_2818 * unksp84) - (temp_f8_2820 * (f32) sp80);
    sp70 = (f64) sp40;
    sp78 = (f64) sp48;
    if ((((f32) sp78 * (f32) sp78) + (((f32) sp70 * (f32) sp70) + (unksp74 * unksp74))) < 0.001f) {
        sp30 = 0.0f;
        sp34 = 0.0f;
        sp38 = 0.0f;
        M2C_FIELD(&arg0, f64 *, 0) = (f64) sp30;
        M2C_FIELD(&arg0, f64 *, 8) = (f64) sp38;
        return;
    }
    sp10 = (temp_f8_2820 * (f32) sp78) - (temp_f7_2815 * unksp74);
    sp14 = (temp_f7_2815 * (f32) sp70) - (temp_f10_2818 * (f32) sp78);
    sp18 = (temp_f10_2818 * unksp74) - (temp_f8_2820 * (f32) sp70);
    sp60 = (f64) sp10;
    sp68 = (f64) sp18;
    var_f4_2879 = ((f32) sp68 * (f32) sp68) + (((f32) sp60 * (f32) sp60) + (unksp64 * unksp64));
    if (var_f4_2879 > 1e-12f) {
        if (var_f4_2879 > 0.0f) {
            temp_f1_2884 = __frsqrte(var_f4_2879);
            temp_f1_2890 = 0.5 * temp_f1_2884 * -(((f64) var_f4_2879 * (temp_f1_2884 * temp_f1_2884)) - 3.0);
            temp_f1_2894 = 0.5 * temp_f1_2890 * -(((f64) var_f4_2879 * (temp_f1_2890 * temp_f1_2890)) - 3.0);
            var_f4_2879 = (f32) ((f64) var_f4_2879 * (0.5 * temp_f1_2894 * -(((f64) var_f4_2879 * (temp_f1_2894 * temp_f1_2894)) - 3.0)));
        } else if (var_f4_2879 < M2C_BITWISE(f32, 0.0)) {
            var_f4_2879 = __float_nan;
        } else {
            sp8 = var_f4_2879;
            temp_r4_2913 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r4_2913) {                 /* irregular */
            case 0x7F800000:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_2923 = 1;
                } else {
                    var_r0_2923 = 2;
                }
                break;
            case 0x0:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_2923 = 5;
                } else {
                    var_r0_2923 = 3;
                }
                break;
            default:
                var_r0_2923 = 4;
                break;
            }
            if (var_r0_2923 == 1) {
                var_f4_2879 = __float_nan;
            }
        }
        var_f0_2812 = 1.0f / var_f4_2879;
    }
    sp24 = unksp64 * var_f0_2812;
    sp20 = (f32) sp60 * var_f0_2812;
    sp28 = (f32) sp68 * var_f0_2812;
    M2C_FIELD(&arg0, f64 *, 0) = (f64) sp20;
    M2C_FIELD(&arg0, f64 *, 8) = (f64) sp28;
}
#endif

void Tools_GetDateString(TimerInfo *arg0) {
    Str_Printf("%04d-%02d-%02d %02d:%02d", arg0->unk18, arg0->unk14, arg0->unk10, arg0->unk0, arg0->unk4);
}

#if 0 // DRAFT: illegal explicit conversion from 'TimerInfo' to
s32 Tools_GetTimeInSeconds() {
    TimerInfo sp8;

    Timer_GetSystemTime(&sp8);
    return (sp8.unk14 * 0x278D00) + (sp8.unk10 * 0x15180) + ((s32) sp8 * 0xE10) + (sp8.unk4 * 0x3C) + sp8.unk8;
}
#endif

#if 0 // DRAFT: function call 'stricmp(signed char *, const char *)' does not match
u16 Tools_GetMatchingSubObjectIndex(SubObjectType arg0, MKModel *arg1, const char *arg2) {
    s16 temp_r31_3030;
    s8 *var_r29_3037;
    u16 var_r30_3031;
    u8 temp_r3_3050;

    temp_r31_3030 = MKModel_GetNmbrOfSubObjects(arg1, arg0);
    var_r30_3031 = 0;
loop_8:
    if ((s32) var_r30_3031 >= temp_r31_3030) {
        return 0xFFFFU;
    }
    var_r29_3037 = MKModel_GetSubObjectName(arg1, arg0, (s32) var_r30_3031);
loop_5:
    temp_r3_3050 = (u8) *var_r29_3037;
    if (((s8) temp_r3_3050 == 0) || ((s8) temp_r3_3050 == 0)) {
        var_r30_3031 += 1;
        goto loop_8;
    }
    if (stricmp(var_r29_3037, arg2) == 0) {
        return var_r30_3031;
    }
    var_r29_3037 += 1;
    goto loop_5;
}
#endif

#if 0 // DRAFT: function call 'stricmp(signed char *, const char *)' does not match
u16 Tools_GetMatchingRefPointIndex(MKModel *arg0, const char *arg1) {
    s16 temp_r31_3081;
    s8 *var_r29_3087;
    u16 var_r30_3082;
    u8 temp_r3_3100;

    temp_r31_3081 = MKModel_GetNmbrOfRefPoints(arg0);
    var_r30_3082 = 0;
loop_8:
    if ((s32) var_r30_3082 >= temp_r31_3081) {
        return 0xFFFFU;
    }
    var_r29_3087 = MKModel_GetRefPointName(arg0, (s32) var_r30_3082);
loop_5:
    temp_r3_3100 = (u8) *var_r29_3087;
    if (((s8) temp_r3_3100 == 0) || ((s8) temp_r3_3100 == 0)) {
        var_r30_3082 += 1;
        goto loop_8;
    }
    if (stricmp(var_r29_3087, arg1) == 0) {
        return var_r30_3082;
    }
    var_r29_3087 += 1;
    goto loop_5;
}
#endif

#if 0 // DRAFT: pointer/array required
u16 Tools_GetMatchingNodeIndex(MKModel *arg0, const char *arg1) {
    s32 var_r30_3140;
    s8 temp_r31_3132;
    u16 var_r29_3133;
    u8 temp_r3_3153;

    temp_r31_3132 = ((Animation *) (MKModel_GetAnimation(arg0)))->GetNmbrOfNodes();
    var_r29_3133 = 0;
loop_8:
    if ((s32) var_r29_3133 >= temp_r31_3132) {
        return 0xFFFFU;
    }
    var_r30_3140 = ((Animation *) (MKModel_GetAnimation(arg0)))->GetNodeName((s32) var_r29_3133);
loop_5:
    temp_r3_3153 = *var_r30_3140;
    if (((s8) temp_r3_3153 == 0) || ((s8) temp_r3_3153 == 0)) {
        var_r29_3133 += 1;
        goto loop_8;
    }
    if (stricmp((s8 *) var_r30_3140, arg1) == 0) {
        return var_r29_3133;
    }
    var_r30_3140 += 1;
    goto loop_5;
}
#endif

#if 0 // DRAFT: undefined identifier 'Tools_ClosestPropsPos'
void Tools_cpp::__sinit() {
    M2C_FIELD(&Tools_ClosestPropsPos, f64 *, 0) = (f64) M2C_FIELD(&MKVector3::zero, f64 *, 0);
    M2C_FIELD(&Tools_ClosestPropsPos, f64 *, 8) = (f64) M2C_FIELD(&MKVector3::zero, f64 *, 8);
}
#endif
