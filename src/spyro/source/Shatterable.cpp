#include "spyro/source/Shatterable.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "spyro/source/Collectable.h"
#include "spyro/source/Crate.h"
#include "spyro/source/ExplodeMsg.h"
#include "spyro/source/FXBase.h"
#include "spyro/source/FlyingChunkPS.h"
#include "spyro/source/GameMessages.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/KDInput.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDProperty.h"
#include "spyro/source/KDShatter2.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/MeleeAttackHitMsg.h"
#include "spyro/source/ShatterExtendedMsg.h"
#include "spyro/source/ShatterOnCollisionMsg.h"
#include "unplaced_templates.h"
#include "common/Source/MKModel.h"
#include "common/Source/StdMath.h"
#include "spyro/source/DataMap.h"
#include "spyro/source/KDRandom.h"
#include "spyro/source/PropFlags.h"
#include <m2c_macros.h>

f64 ceil(s32, f32);                                 /* extern */
M2C_UNK free(void *);                               /* extern */
void *malloc(s32);                                  /* extern */
s32 stricmp(void *);                                /* extern */
M2C_UNK strlwr(s8 *, M2C_UNK);                      /* extern */
u32 strstr(s8 *);                                   /* extern */
extern s32 GS_GemSpawn2;
extern s32 GS_PLACEHOLDER;
extern s32 GS_SpyroStompLand;
extern s8 gAssertBool;
extern MKSceneManager *gMK;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern void **gb;
#if 0 // DRAFT: illegal use of incomplete struct/union/class 'DataMap'
static M2C_UNK pShatterAnimNames;                   /* unable to generate initializer: unknown type */
static DataMap ShatterableHitFXDataMap;             /* unable to generate initializer: confusing struct layout */
static M2C_UNK unshatteredNames;
#endif

static s32 lit_1509 = 0;

#if 0 // DRAFT: undefined identifier 'MKVector'
s32 Shatterable::GetAimPoint(const MKVector3 &arg0, MKVector3 *arg1) {
    f64 sp30;
    f64 sp28;
    M2C_UNK sp18;
    f32 sp10;

    MKVector(0.0f, 150.0f, 0.0f);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r4, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    M2C_FIELD(arg1, f64 *, 0) = sp8;
    sp10 = M2C_FIELD((this->unk8 + 0x30), f32 *, 8) + sp20;
    sp28 = sp8;
    sp30 = (f64) sp10;
    M2C_FIELD(arg1, f64 *, 8) = (f64) sp10;
    return 0;
}
#endif

#if 0 // DRAFT: illegal type
void Shatterable::ResetPercentageShattered() {
    s32 temp_r0_69;
    s32 var_r0_75;
    s32 var_r31_58;
    s32 var_r3_70;

    var_r31_58 = checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk160 - 1;
    if ((u8) M2C_FIELD((checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk11C + (var_r31_58 * 0x17C)), u8 *, 0x178) == 0) {
        temp_r0_69 = var_r31_58 - 1;
        var_r3_70 = checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk160 - 1;
        if (temp_r0_69 < var_r3_70) {
            var_r3_70 = temp_r0_69;
        }
        var_r0_75 = lit_1509;
        if (var_r3_70 > var_r0_75) {
            var_r0_75 = var_r3_70;
        }
        var_r31_58 = var_r0_75;
    }
    this->unk170 = (MKProp *) (s32) (this->unk188 * (f32) var_r31_58);
}
#endif

#if 0 // DRAFT: undefined identifier 'unksp3C8'
void ShatterableDescriptor::EmitHitEffects(const MKVector3 &arg0, const MKVector3 &arg1, const MKVector4 &arg2, MKProp *arg3, int arg4) {
    f32 temp_f0_1146;
    f32 temp_f0_1364;
    f32 temp_f0_274;
    f32 temp_f0_492;
    f32 temp_f0_710;
    f32 temp_f0_928;
    f32 temp_f28_1024;
    f32 temp_f28_152;
    f32 temp_f28_370;
    f32 temp_f28_588;
    f32 temp_f28_806;
    f32 temp_f30_1242;
    f32 var_f3_1135;
    f32 var_f3_1353;
    f32 var_f3_263;
    f32 var_f3_481;
    f32 var_f3_699;
    f32 var_f3_917;
    f32 var_f4_1068;
    f32 var_f4_1286;
    f32 var_f4_196;
    f32 var_f4_414;
    f32 var_f4_632;
    f32 var_f4_850;
    f64 temp_f1_1074;
    f64 temp_f1_1080;
    f64 temp_f1_1084;
    f64 temp_f1_1292;
    f64 temp_f1_1298;
    f64 temp_f1_1302;
    f64 temp_f1_202;
    f64 temp_f1_208;
    f64 temp_f1_212;
    f64 temp_f1_420;
    f64 temp_f1_426;
    f64 temp_f1_430;
    f64 temp_f1_638;
    f64 temp_f1_644;
    f64 temp_f1_648;
    f64 temp_f1_856;
    f64 temp_f1_862;
    f64 temp_f1_866;
    s32 temp_r0_125;
    s32 temp_r3_1103;
    s32 temp_r3_1321;
    s32 temp_r3_231;
    s32 temp_r3_449;
    s32 temp_r3_667;
    s32 temp_r3_885;
    s32 var_r0_1113;
    s32 var_r0_1331;
    s32 var_r0_241;
    s32 var_r0_459;
    s32 var_r0_677;
    s32 var_r0_895;
    s32 var_r22_1029;
    s32 var_r22_1247;
    s32 var_r22_157;
    s32 var_r22_375;
    s32 var_r22_593;
    s32 var_r22_811;

    temp_r0_125 = this->unk168;
    switch (temp_r0_125) {                          /* switch 1; irregular */
    case 1:                                         /* switch 1 */
        temp_f28_152 = arg1.unk8;
        var_r22_157 = 0;
loop_31:
        if (var_r22_157 < arg4) {
            unksp3C8 = 1.0f;
            unksp3D8 = -1.0f;
            unksp3C0 = 1.0f;
            unksp3C4 = 2.0f;
            unksp3D0 = -1.0f;
            unksp3D4 = 1.0f;
            unksp830 = unksp3C0;
            unksp838 = unksp3C8;
            unksp840 = unksp3D0;
            unksp848 = unksp3D8;
            KDRand_Vector(*((MKVector3 *) &unksp850), *((MKVector3 *) &unksp840));
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r25, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r28, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            unksp8B0 = unksp3B0;
            unksp3B8 = unksp858 + temp_f28_152;
            unksp8B8 = unksp3B8;
            var_f4_196 = (unksp8B8 * unksp8B8) + ((unksp8B0 * unksp8B0) + (unksp8B4 * unksp8B4));
            if (var_f4_196 > 0.000001f) {
                if (var_f4_196 > 0.0f) {
                    temp_f1_202 = __frsqrte(var_f4_196);
                    temp_f1_208 = 0.5 * temp_f1_202 * -(((f64) var_f4_196 * (temp_f1_202 * temp_f1_202)) - 3.0);
                    temp_f1_212 = 0.5 * temp_f1_208 * -(((f64) var_f4_196 * (temp_f1_208 * temp_f1_208)) - 3.0);
                    var_f4_196 = (f32) ((f64) var_f4_196 * (0.5 * temp_f1_212 * -(((f64) var_f4_196 * (temp_f1_212 * temp_f1_212)) - 3.0)));
                } else if (var_f4_196 < M2C_BITWISE(f32, 0.0)) {
                    var_f4_196 = __float_nan;
                } else {
                    unksp1C = var_f4_196;
                    temp_r3_231 = unksp1C & 0x7F800000;
                    switch (temp_r3_231) {          /* switch 2; irregular */
                    case 0x7F800000:                /* switch 2 */
                        if (unksp1C & 0x7FFFFF) {
                            var_r0_241 = 1;
                        } else {
                            var_r0_241 = 2;
                        }
                        break;
                    case 0x0:                       /* switch 2 */
                        if (unksp1C & 0x7FFFFF) {
                            var_r0_241 = 5;
                        } else {
                            var_r0_241 = 3;
                        }
                        break;
                    default:                        /* switch 2 */
                        var_r0_241 = 4;
                        break;
                    }
                    if (var_r0_241 == 1) {
                        var_f4_196 = __float_nan;
                    }
                }
                var_f3_263 = 1.0f / var_f4_196;
            } else {
                var_f3_263 = 0.0f;
            }
            temp_f0_274 = unksp8B8 * var_f3_263;
            unksp8B0 *= var_f3_263;
            unksp8B4 *= var_f3_263;
            unksp8B8 = temp_f0_274;
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r21, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f1, $f1, $f26 */);
            unksp398 = -1.0f;
            unksp3A8 = temp_f0_274 * 2000.0f;
            unksp388 = 1.0f;
            unksp390 = -1.0f;
            unksp394 = -1.0f;
            unksp380 = 1.0f;
            unksp384 = 1.0f;
            unksp820 = unksp3A0;
            unksp828 = unksp3A8;
            unksp7F0 = unksp390;
            unksp7F8 = unksp398;
            unksp7E0 = unksp380;
            unksp7E8 = unksp388;
            KDRand_Vector(*((MKVector3 *) &unksp800), *((MKVector3 *) &unksp7F0));
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r24, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f25 */);
            unksp368 = -1.0f;
            unksp358 = 1.0f;
            unksp378 = unksp808 * 6.2831855f;
            unksp360 = -1.0f;
            unksp364 = -1.0f;
            unksp350 = 1.0f;
            unksp354 = 1.0f;
            unksp810 = unksp370;
            unksp818 = unksp378;
            unksp7B0 = unksp360;
            unksp7B8 = unksp368;
            unksp7A0 = unksp350;
            unksp7A8 = unksp358;
            KDRand_Vector(*((MKVector3 *) &unksp7C0), *((MKVector3 *) &unksp7B0));
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r23, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f24 */);
            unksp7D0 = unksp340;
            unksp348 = unksp7C8 * 6.2831855f;
            unksp7D8 = unksp348;
            ((FlyingChunkPS *) (M2C_FIELD(&gb, FlyingChunkPS **, 0xA0)))->Emit(arg0, *((MKVector3 *) &unksp820), *((MKVector3 *) &unksp810), *((MKVector3 *) &unksp7D0), MKRand_Float(&gViewSeed, 0.125f, 0.5f), arg2, 0, arg3);
            var_r22_157 += 1;
            goto loop_31;
        }
        return;
    case 2:                                         /* switch 1 */
        temp_f28_370 = arg1.unk8;
        var_r22_375 = 0;
loop_55:
        if (var_r22_375 < arg4) {
            unksp328 = 1.0f;
            unksp338 = -1.0f;
            unksp320 = 1.0f;
            unksp324 = 2.0f;
            unksp330 = -1.0f;
            unksp334 = 1.0f;
            unksp770 = unksp320;
            unksp778 = unksp328;
            unksp780 = unksp330;
            unksp788 = unksp338;
            KDRand_Vector(*((MKVector3 *) &unksp790), *((MKVector3 *) &unksp780));
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r23, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r28, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            unksp8A0 = unksp310;
            unksp318 = unksp798 + temp_f28_370;
            unksp8A8 = unksp318;
            var_f4_414 = (unksp8A8 * unksp8A8) + ((unksp8A0 * unksp8A0) + (unksp8A4 * unksp8A4));
            if (var_f4_414 > 0.000001f) {
                if (var_f4_414 > 0.0f) {
                    temp_f1_420 = __frsqrte(var_f4_414);
                    temp_f1_426 = 0.5 * temp_f1_420 * -(((f64) var_f4_414 * (temp_f1_420 * temp_f1_420)) - 3.0);
                    temp_f1_430 = 0.5 * temp_f1_426 * -(((f64) var_f4_414 * (temp_f1_426 * temp_f1_426)) - 3.0);
                    var_f4_414 = (f32) ((f64) var_f4_414 * (0.5 * temp_f1_430 * -(((f64) var_f4_414 * (temp_f1_430 * temp_f1_430)) - 3.0)));
                } else if (var_f4_414 < M2C_BITWISE(f32, 0.0)) {
                    var_f4_414 = __float_nan;
                } else {
                    unksp18 = var_f4_414;
                    temp_r3_449 = unksp18 & 0x7F800000;
                    switch (temp_r3_449) {          /* switch 3; irregular */
                    case 0x7F800000:                /* switch 3 */
                        if (unksp18 & 0x7FFFFF) {
                            var_r0_459 = 1;
                        } else {
                            var_r0_459 = 2;
                        }
                        break;
                    case 0x0:                       /* switch 3 */
                        if (unksp18 & 0x7FFFFF) {
                            var_r0_459 = 5;
                        } else {
                            var_r0_459 = 3;
                        }
                        break;
                    default:                        /* switch 3 */
                        var_r0_459 = 4;
                        break;
                    }
                    if (var_r0_459 == 1) {
                        var_f4_414 = __float_nan;
                    }
                }
                var_f3_481 = 1.0f / var_f4_414;
            } else {
                var_f3_481 = 0.0f;
            }
            temp_f0_492 = unksp8A8 * var_f3_481;
            unksp8A0 *= var_f3_481;
            unksp8A4 *= var_f3_481;
            unksp8A8 = temp_f0_492;
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r21, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f1, $f1, $f24 */);
            unksp2F8 = -1.0f;
            unksp308 = temp_f0_492 * 2000.0f;
            unksp2E8 = 1.0f;
            unksp2F0 = -1.0f;
            unksp2F4 = -1.0f;
            unksp2E0 = 1.0f;
            unksp2E4 = 1.0f;
            unksp760 = unksp300;
            unksp768 = unksp308;
            unksp730 = unksp2F0;
            unksp738 = unksp2F8;
            unksp720 = unksp2E0;
            unksp728 = unksp2E8;
            KDRand_Vector(*((MKVector3 *) &unksp740), *((MKVector3 *) &unksp730));
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r24, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f25 */);
            unksp2C8 = -1.0f;
            unksp2B8 = 1.0f;
            unksp2D8 = unksp748 * 6.2831855f;
            unksp2C0 = -1.0f;
            unksp2C4 = -1.0f;
            unksp2B0 = 1.0f;
            unksp2B4 = 1.0f;
            unksp750 = unksp2D0;
            unksp758 = unksp2D8;
            unksp6F0 = unksp2C0;
            unksp6F8 = unksp2C8;
            unksp6E0 = unksp2B0;
            unksp6E8 = unksp2B8;
            KDRand_Vector(*((MKVector3 *) &unksp700), *((MKVector3 *) &unksp6F0));
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r25, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f26 */);
            unksp710 = unksp2A0;
            unksp2A8 = unksp708 * 6.2831855f;
            unksp718 = unksp2A8;
            ((FlyingChunkPS *) (M2C_FIELD(&gb, FlyingChunkPS **, 0xA4)))->Emit(arg0, *((MKVector3 *) &unksp760), *((MKVector3 *) &unksp750), *((MKVector3 *) &unksp710), MKRand_Float(&gViewSeed, 0.125f, 0.5f), arg2, 0, arg3);
            var_r22_375 += 1;
            goto loop_55;
        }
        return;
    case 3:                                         /* switch 1 */
        temp_f28_588 = arg1.unk8;
        var_r22_593 = 0;
loop_79:
        if (var_r22_593 < arg4) {
            unksp288 = 1.0f;
            unksp298 = -1.0f;
            unksp280 = 1.0f;
            unksp284 = 2.0f;
            unksp290 = -1.0f;
            unksp294 = 1.0f;
            unksp6B0 = unksp280;
            unksp6B8 = unksp288;
            unksp6C0 = unksp290;
            unksp6C8 = unksp298;
            KDRand_Vector(*((MKVector3 *) &unksp6D0), *((MKVector3 *) &unksp6C0));
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r23, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r28, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            unksp890 = unksp270;
            unksp278 = unksp6D8 + temp_f28_588;
            unksp898 = unksp278;
            var_f4_632 = (unksp898 * unksp898) + ((unksp890 * unksp890) + (unksp894 * unksp894));
            if (var_f4_632 > 0.000001f) {
                if (var_f4_632 > 0.0f) {
                    temp_f1_638 = __frsqrte(var_f4_632);
                    temp_f1_644 = 0.5 * temp_f1_638 * -(((f64) var_f4_632 * (temp_f1_638 * temp_f1_638)) - 3.0);
                    temp_f1_648 = 0.5 * temp_f1_644 * -(((f64) var_f4_632 * (temp_f1_644 * temp_f1_644)) - 3.0);
                    var_f4_632 = (f32) ((f64) var_f4_632 * (0.5 * temp_f1_648 * -(((f64) var_f4_632 * (temp_f1_648 * temp_f1_648)) - 3.0)));
                } else if (var_f4_632 < M2C_BITWISE(f32, 0.0)) {
                    var_f4_632 = __float_nan;
                } else {
                    unksp14 = var_f4_632;
                    temp_r3_667 = unksp14 & 0x7F800000;
                    switch (temp_r3_667) {          /* switch 4; irregular */
                    case 0x7F800000:                /* switch 4 */
                        if (unksp14 & 0x7FFFFF) {
                            var_r0_677 = 1;
                        } else {
                            var_r0_677 = 2;
                        }
                        break;
                    case 0x0:                       /* switch 4 */
                        if (unksp14 & 0x7FFFFF) {
                            var_r0_677 = 5;
                        } else {
                            var_r0_677 = 3;
                        }
                        break;
                    default:                        /* switch 4 */
                        var_r0_677 = 4;
                        break;
                    }
                    if (var_r0_677 == 1) {
                        var_f4_632 = __float_nan;
                    }
                }
                var_f3_699 = 1.0f / var_f4_632;
            } else {
                var_f3_699 = 0.0f;
            }
            temp_f0_710 = unksp898 * var_f3_699;
            unksp890 *= var_f3_699;
            unksp894 *= var_f3_699;
            unksp898 = temp_f0_710;
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r21, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f1, $f1, $f24 */);
            unksp258 = -1.0f;
            unksp268 = temp_f0_710 * 2000.0f;
            unksp248 = 1.0f;
            unksp250 = -1.0f;
            unksp254 = -1.0f;
            unksp240 = 1.0f;
            unksp244 = 1.0f;
            unksp6A0 = unksp260;
            unksp6A8 = unksp268;
            unksp670 = unksp250;
            unksp678 = unksp258;
            unksp660 = unksp240;
            unksp668 = unksp248;
            KDRand_Vector(*((MKVector3 *) &unksp680), *((MKVector3 *) &unksp670));
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r24, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f25 */);
            unksp228 = -1.0f;
            unksp218 = 1.0f;
            unksp238 = unksp688 * 6.2831855f;
            unksp220 = -1.0f;
            unksp224 = -1.0f;
            unksp210 = 1.0f;
            unksp214 = 1.0f;
            unksp690 = unksp230;
            unksp698 = unksp238;
            unksp630 = unksp220;
            unksp638 = unksp228;
            unksp620 = unksp210;
            unksp628 = unksp218;
            KDRand_Vector(*((MKVector3 *) &unksp640), *((MKVector3 *) &unksp630));
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r25, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f26 */);
            unksp650 = unksp200;
            unksp208 = unksp648 * 6.2831855f;
            unksp658 = unksp208;
            ((FlyingChunkPS *) (M2C_FIELD(&gb, FlyingChunkPS **, 0xAC)))->Emit(arg0, *((MKVector3 *) &unksp6A0), *((MKVector3 *) &unksp690), *((MKVector3 *) &unksp650), MKRand_Float(&gViewSeed, 0.125f, 0.5f), arg2, 0, arg3);
            var_r22_593 += 1;
            goto loop_79;
        }
        return;
    case 4:                                         /* switch 1 */
        temp_f28_806 = arg1.unk8;
        var_r22_811 = 0;
loop_103:
        if (var_r22_811 < arg4) {
            unksp1E8 = 1.0f;
            unksp1F8 = -1.0f;
            unksp1E0 = 1.0f;
            unksp1E4 = 2.0f;
            unksp1F0 = -1.0f;
            unksp1F4 = 1.0f;
            unksp5F0 = unksp1E0;
            unksp5F8 = unksp1E8;
            unksp600 = unksp1F0;
            unksp608 = unksp1F8;
            KDRand_Vector(*((MKVector3 *) &unksp610), *((MKVector3 *) &unksp600));
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r23, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r28, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            unksp880 = unksp1D0;
            unksp1D8 = unksp618 + temp_f28_806;
            unksp888 = unksp1D8;
            var_f4_850 = (unksp888 * unksp888) + ((unksp880 * unksp880) + (unksp884 * unksp884));
            if (var_f4_850 > 0.000001f) {
                if (var_f4_850 > 0.0f) {
                    temp_f1_856 = __frsqrte(var_f4_850);
                    temp_f1_862 = 0.5 * temp_f1_856 * -(((f64) var_f4_850 * (temp_f1_856 * temp_f1_856)) - 3.0);
                    temp_f1_866 = 0.5 * temp_f1_862 * -(((f64) var_f4_850 * (temp_f1_862 * temp_f1_862)) - 3.0);
                    var_f4_850 = (f32) ((f64) var_f4_850 * (0.5 * temp_f1_866 * -(((f64) var_f4_850 * (temp_f1_866 * temp_f1_866)) - 3.0)));
                } else if (var_f4_850 < M2C_BITWISE(f32, 0.0)) {
                    var_f4_850 = __float_nan;
                } else {
                    unksp10 = var_f4_850;
                    temp_r3_885 = unksp10 & 0x7F800000;
                    switch (temp_r3_885) {          /* switch 5; irregular */
                    case 0x7F800000:                /* switch 5 */
                        if (unksp10 & 0x7FFFFF) {
                            var_r0_895 = 1;
                        } else {
                            var_r0_895 = 2;
                        }
                        break;
                    case 0x0:                       /* switch 5 */
                        if (unksp10 & 0x7FFFFF) {
                            var_r0_895 = 5;
                        } else {
                            var_r0_895 = 3;
                        }
                        break;
                    default:                        /* switch 5 */
                        var_r0_895 = 4;
                        break;
                    }
                    if (var_r0_895 == 1) {
                        var_f4_850 = __float_nan;
                    }
                }
                var_f3_917 = 1.0f / var_f4_850;
            } else {
                var_f3_917 = 0.0f;
            }
            temp_f0_928 = unksp888 * var_f3_917;
            unksp880 *= var_f3_917;
            unksp884 *= var_f3_917;
            unksp888 = temp_f0_928;
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r21, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f1, $f1, $f24 */);
            unksp1B8 = -1.0f;
            unksp1C8 = temp_f0_928 * 2000.0f;
            unksp1A8 = 1.0f;
            unksp1B0 = -1.0f;
            unksp1B4 = -1.0f;
            unksp1A0 = 1.0f;
            unksp1A4 = 1.0f;
            unksp5E0 = unksp1C0;
            unksp5E8 = unksp1C8;
            unksp5B0 = unksp1B0;
            unksp5B8 = unksp1B8;
            unksp5A0 = unksp1A0;
            unksp5A8 = unksp1A8;
            KDRand_Vector(*((MKVector3 *) &unksp5C0), *((MKVector3 *) &unksp5B0));
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r24, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f25 */);
            unksp188 = -1.0f;
            unksp178 = 1.0f;
            unksp198 = unksp5C8 * 6.2831855f;
            unksp180 = -1.0f;
            unksp184 = -1.0f;
            unksp170 = 1.0f;
            unksp174 = 1.0f;
            unksp5D0 = unksp190;
            unksp5D8 = unksp198;
            unksp570 = unksp180;
            unksp578 = unksp188;
            unksp560 = unksp170;
            unksp568 = unksp178;
            KDRand_Vector(*((MKVector3 *) &unksp580), *((MKVector3 *) &unksp570));
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r25, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f26 */);
            unksp590 = unksp160;
            unksp168 = unksp588 * 6.2831855f;
            unksp598 = unksp168;
            ((FlyingChunkPS *) (M2C_FIELD(&gb, FlyingChunkPS **, 0xA8)))->Emit(arg0, *((MKVector3 *) &unksp5E0), *((MKVector3 *) &unksp5D0), *((MKVector3 *) &unksp590), MKRand_Float(&gViewSeed, 0.125f, 0.5f), arg2, 0, arg3);
            var_r22_811 += 1;
            goto loop_103;
        }
        return;
    case 5:                                         /* switch 1 */
        temp_f28_1024 = arg1.unk8;
        var_r22_1029 = 0;
loop_127:
        if (var_r22_1029 < arg4) {
            unksp148 = 1.0f;
            unksp158 = -1.0f;
            unksp140 = 1.0f;
            unksp144 = 2.0f;
            unksp150 = -1.0f;
            unksp154 = 1.0f;
            unksp530 = unksp140;
            unksp538 = unksp148;
            unksp540 = unksp150;
            unksp548 = unksp158;
            KDRand_Vector(*((MKVector3 *) &unksp550), *((MKVector3 *) &unksp540));
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r23, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r28, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            unksp870 = unksp130;
            unksp138 = unksp558 + temp_f28_1024;
            unksp878 = unksp138;
            var_f4_1068 = (unksp878 * unksp878) + ((unksp870 * unksp870) + (unksp874 * unksp874));
            if (var_f4_1068 > 0.000001f) {
                if (var_f4_1068 > 0.0f) {
                    temp_f1_1074 = __frsqrte(var_f4_1068);
                    temp_f1_1080 = 0.5 * temp_f1_1074 * -(((f64) var_f4_1068 * (temp_f1_1074 * temp_f1_1074)) - 3.0);
                    temp_f1_1084 = 0.5 * temp_f1_1080 * -(((f64) var_f4_1068 * (temp_f1_1080 * temp_f1_1080)) - 3.0);
                    var_f4_1068 = (f32) ((f64) var_f4_1068 * (0.5 * temp_f1_1084 * -(((f64) var_f4_1068 * (temp_f1_1084 * temp_f1_1084)) - 3.0)));
                } else if (var_f4_1068 < M2C_BITWISE(f32, 0.0)) {
                    var_f4_1068 = __float_nan;
                } else {
                    unkspC = var_f4_1068;
                    temp_r3_1103 = unkspC & 0x7F800000;
                    switch (temp_r3_1103) {         /* switch 6; irregular */
                    case 0x7F800000:                /* switch 6 */
                        if (unkspC & 0x7FFFFF) {
                            var_r0_1113 = 1;
                        } else {
                            var_r0_1113 = 2;
                        }
                        break;
                    case 0x0:                       /* switch 6 */
                        if (unkspC & 0x7FFFFF) {
                            var_r0_1113 = 5;
                        } else {
                            var_r0_1113 = 3;
                        }
                        break;
                    default:                        /* switch 6 */
                        var_r0_1113 = 4;
                        break;
                    }
                    if (var_r0_1113 == 1) {
                        var_f4_1068 = __float_nan;
                    }
                }
                var_f3_1135 = 1.0f / var_f4_1068;
            } else {
                var_f3_1135 = 0.0f;
            }
            temp_f0_1146 = unksp878 * var_f3_1135;
            unksp870 *= var_f3_1135;
            unksp874 *= var_f3_1135;
            unksp878 = temp_f0_1146;
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r21, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f1, $f1, $f24 */);
            unksp118 = -1.0f;
            unksp128 = temp_f0_1146 * 2000.0f;
            unksp108 = 1.0f;
            unksp110 = -1.0f;
            unksp114 = -1.0f;
            unksp100 = 1.0f;
            unksp104 = 1.0f;
            unksp520 = unksp120;
            unksp528 = unksp128;
            unksp4F0 = unksp110;
            unksp4F8 = unksp118;
            unksp4E0 = unksp100;
            unksp4E8 = unksp108;
            KDRand_Vector(*((MKVector3 *) &unksp500), *((MKVector3 *) &unksp4F0));
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r24, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f25 */);
            unkspE8 = -1.0f;
            unkspD8 = 1.0f;
            unkspF8 = unksp508 * 6.2831855f;
            unkspE0 = -1.0f;
            unkspE4 = -1.0f;
            unkspD0 = 1.0f;
            unkspD4 = 1.0f;
            unksp510 = unkspF0;
            unksp518 = unkspF8;
            unksp4B0 = unkspE0;
            unksp4B8 = unkspE8;
            unksp4A0 = unkspD0;
            unksp4A8 = unkspD8;
            KDRand_Vector(*((MKVector3 *) &unksp4C0), *((MKVector3 *) &unksp4B0));
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r25, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f26 */);
            unksp4D0 = unkspC0;
            unkspC8 = unksp4C8 * 6.2831855f;
            unksp4D8 = unkspC8;
            ((FlyingChunkPS *) (M2C_FIELD(&gb, FlyingChunkPS **, 0xB0)))->Emit(arg0, *((MKVector3 *) &unksp520), *((MKVector3 *) &unksp510), *((MKVector3 *) &unksp4D0), MKRand_Float(&gViewSeed, 0.125f, 0.5f), arg2, 0, arg3);
            var_r22_1029 += 1;
            goto loop_127;
        }
        return;
    case 6:                                         /* switch 1 */
        temp_f30_1242 = arg1.unk8;
        var_r22_1247 = 0;
loop_151:
        if (var_r22_1247 < arg4) {
            unkspA8 = 1.0f;
            unkspB8 = -1.0f;
            unkspA0 = 1.0f;
            unkspA4 = 2.0f;
            unkspB0 = -1.0f;
            unkspB4 = 1.0f;
            unksp470 = unkspA0;
            unksp478 = unkspA8;
            unksp480 = unkspB0;
            unksp488 = unkspB8;
            KDRand_Vector(*((MKVector3 *) &unksp490), *((MKVector3 *) &unksp480));
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r23, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r28, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            unksp860 = unksp90;
            unksp98 = unksp498 + temp_f30_1242;
            unksp868 = unksp98;
            var_f4_1286 = (unksp868 * unksp868) + ((unksp860 * unksp860) + (unksp864 * unksp864));
            if (var_f4_1286 > 0.000001f) {
                if (var_f4_1286 > 0.0f) {
                    temp_f1_1292 = __frsqrte(var_f4_1286);
                    temp_f1_1298 = 0.5 * temp_f1_1292 * -(((f64) var_f4_1286 * (temp_f1_1292 * temp_f1_1292)) - 3.0);
                    temp_f1_1302 = 0.5 * temp_f1_1298 * -(((f64) var_f4_1286 * (temp_f1_1298 * temp_f1_1298)) - 3.0);
                    var_f4_1286 = (f32) ((f64) var_f4_1286 * (0.5 * temp_f1_1302 * -(((f64) var_f4_1286 * (temp_f1_1302 * temp_f1_1302)) - 3.0)));
                } else if (var_f4_1286 < M2C_BITWISE(f32, 0.0)) {
                    var_f4_1286 = __float_nan;
                } else {
                    unksp8 = var_f4_1286;
                    temp_r3_1321 = unksp8 & 0x7F800000;
                    switch (temp_r3_1321) {         /* switch 7; irregular */
                    case 0x7F800000:                /* switch 7 */
                        if (unksp8 & 0x7FFFFF) {
                            var_r0_1331 = 1;
                        } else {
                            var_r0_1331 = 2;
                        }
                        break;
                    case 0x0:                       /* switch 7 */
                        if (unksp8 & 0x7FFFFF) {
                            var_r0_1331 = 5;
                        } else {
                            var_r0_1331 = 3;
                        }
                        break;
                    default:                        /* switch 7 */
                        var_r0_1331 = 4;
                        break;
                    }
                    if (var_r0_1331 == 1) {
                        var_f4_1286 = __float_nan;
                    }
                }
                var_f3_1353 = 1.0f / var_f4_1286;
            } else {
                var_f3_1353 = 0.0f;
            }
            temp_f0_1364 = unksp868 * var_f3_1353;
            unksp860 *= var_f3_1353;
            unksp864 *= var_f3_1353;
            unksp868 = temp_f0_1364;
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r21, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f1, $f1, $f24 */);
            unksp78 = -1.0f;
            unksp88 = temp_f0_1364 * 2000.0f;
            unksp68 = 1.0f;
            unksp70 = -1.0f;
            unksp74 = -1.0f;
            unksp60 = 1.0f;
            unksp64 = 1.0f;
            unksp460 = unksp80;
            unksp468 = unksp88;
            unksp430 = unksp70;
            unksp438 = unksp78;
            unksp420 = unksp60;
            unksp428 = unksp68;
            KDRand_Vector(*((MKVector3 *) &unksp440), *((MKVector3 *) &unksp430));
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r24, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f25 */);
            unksp48 = -1.0f;
            unksp38 = 1.0f;
            unksp58 = unksp448 * 6.2831855f;
            unksp40 = -1.0f;
            unksp44 = -1.0f;
            unksp30 = 1.0f;
            unksp34 = 1.0f;
            unksp450 = unksp50;
            unksp458 = unksp58;
            unksp3F0 = unksp40;
            unksp3F8 = unksp48;
            unksp3E0 = unksp30;
            unksp3E8 = unksp38;
            KDRand_Vector(*((MKVector3 *) &unksp400), *((MKVector3 *) &unksp3F0));
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r25, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f26 */);
            unksp410 = unksp20;
            unksp28 = unksp408 * 6.2831855f;
            unksp418 = unksp28;
            ((FlyingChunkPS *) (M2C_FIELD(&gb, FlyingChunkPS **, 0xB4)))->Emit(arg0, *((MKVector3 *) &unksp460), *((MKVector3 *) &unksp450), *((MKVector3 *) &unksp410), MKRand_Float(&gViewSeed, 0.125f, 0.5f), arg2, 0, arg3);
            var_r22_1247 += 1;
            goto loop_151;
        }
        return;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'sp8'
void Shatterable::SpawnGems(int arg0) {
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    MKVector3 *temp_r29_1519;
    s32 temp_r29_1540;
    s32 var_r26_1532;
    s32 var_r27_1530;
    void *temp_r3_1488;

    if (arg0 != 0) {
        temp_r3_1488 = this->unk8;
        sp18 = 0.0f;
        sp1C = 150.0f;
        sp20 = 0.0f;
        sp28 = (f64) sp18;
        sp38 = M2C_FIELD(temp_r3_1488, f64 *, 0x30);
        sp30 = (f64) sp20;
        sp40 = M2C_FIELD(temp_r3_1488, f64 *, 0x38);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        sp48 = sp8;
        sp10 = (f32) sp40 + (f32) sp30;
        sp50 = (f64) sp10;
        if ((s32) checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk10C != 0) {
            temp_r29_1519 = this->unk8 + 0x30;
            KDSound_Play3d(checked_cast<P21ShatterableDescriptor, 16MKPropDescriptor>__FP16MKPropDescriptor((MKPropDescriptor *) this->unk0)->unk10C, temp_r29_1519, 0U, -1, 0.0f, 0U);
        }
        var_r27_1530 = 0;
        var_r26_1532 = 0;
loop_9:
        if (var_r26_1532 < arg0) {
            temp_r29_1540 = MKRand_Int(&gViewSeed, 0, 4);
            if ((((u8) checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unkF8 != 0) || (temp_r29_1540 != 3)) && (gameData.unk70.GetGemAvailable((StatType) temp_r29_1540) != 0)) {
                ((CollectableSpawner *) (M2C_FIELD(&(&gb)[temp_r29_1540], CollectableSpawner **, 0x10)))->Spawn(*((MKVector3 *) &sp48), 1, 200.0f, 500.0f, -1, (MKProp *) this);
                var_r27_1530 += 1;
            }
            var_r26_1532 += 1;
            goto loop_9;
        }
        if (var_r27_1530 == 0) {
            ((CollectableSpawner *) (M2C_FIELD(&gb, CollectableSpawner **, 0x10)))->Spawn(*((MKVector3 *) &sp48), 1, 200.0f, 500.0f, -1, (MKProp *) this);
        }
    }
}
#endif

#if 0 // DRAFT: expression syntax error
void Shatterable::TriggerShatterFX() {
    s32 spC;
    s32 sp8;
    ShatterableDescriptor *temp_r3_1601;
    s8 *temp_r3_1603;
    s8 *temp_r3_1612;

    temp_r3_1601 = checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    temp_r3_1603 = temp_r3_1601->unk110;
    if (temp_r3_1603 != NULL) {
        M2C_FIELD(temp_r3_1603, void **, 8) = (void *) this->unk8;
        temp_r3_1601->unk110->Burst(*(this->unk8 + 0x30));
        temp_r3_1612 = temp_r3_1601->unk110;
        spC = 0;
        sp8 = 0xB5;
        M2C_FIELD(M2C_FIELD(temp_r3_1612, void **, 0x44), M2C_UNK (**)(s8 *, s32 *, M2C_UNK), 0x2C)(temp_r3_1612, &sp8, 0);
    }
}
#endif

#if 0 // DRAFT: type mismatch
void Shatterable::PostShatter() {
    if (((MKProp *) this->unk170 < (s32) checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk160) && ((u8) M2C_FIELD((checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk11C + ((s32) this->unk170 * 0x17C)), u8 *, 0x178) != 0)) {
        SetSmashPropState((SmashPropState) 0);
        this->unk168 = checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unkF0;
        return;
    }
    SetSmashPropState((SmashPropState) 3);
    this->unk15C.Send(NULL);
    M2C_FIELD(this, u8 *, 0x1A1) = (u8) (M2C_FIELD(this, u8 *, 0x1A1) & ~0x40);
}
#endif

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'SmashPropState'
void Shatterable::SetSmashPropState(SmashPropState arg0) {
    s32 spC;
    s32 sp8;
    s32 temp_r3_1760;

    if ((MKAnimScript *) this->unk80 != NULL) {
        if (((s32) arg0 == 0) && ((u32) checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unkE8 != NULL)) {
            this->unk80->SetAnim(checked_cast<P21ShatterableDescriptor, 16MKPropDescriptor>__FP16MKPropDescriptor((MKPropDescriptor *) this->unk0)->unkE4, 1.0f, 0.0f, 0, -1);
        } else if (((s32) this->unk16C == 0) && ((s32) arg0 == 1) && ((u32) checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unkE8 != NULL)) {
            this->unk80->SetAnim(checked_cast<P21ShatterableDescriptor, 16MKPropDescriptor>__FP16MKPropDescriptor((MKPropDescriptor *) this->unk0)->unkE8, 1.0f, 0.0f, 0, -1);
        }
    }
    if ((s32) arg0 == 2) {
        this->unk16C = (s32) arg0;
        spC = 0;
        sp8 = 0xBA;
        Message(&sp8);
        return;
    }
    if ((s32) arg0 == 1) {
        this->unk154.Send((MKProp *) this);
        this->unk180 += 1;
        if ((s32) checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unkF4 != 0) {
            temp_r3_1760 = this->unk180;
            SpawnGems((s32) ((f32) this->unk184 * (f32) ceil(temp_r3_1760, (f32) temp_r3_1760 * 0.25f)));
        }
        this->unk184 = NULL;
    }
    this->unk16C = (s32) arg0;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long *' to
void Shatterable::DestroyShatterable() {
    s32 spC;
    s32 sp8;
    s32 var_r30_1815;

    if ((s32) M2C_FIELD(&gb, s32 *, 0x340) == 0) {
        spC = 0;
        var_r30_1815 = 0;
        sp8 = 0xBA;
loop_3:
        if (var_r30_1815 < (s32) checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk160) {
            this->unk16C = 2;
            Message(&sp8);
            var_r30_1815 += 1;
            goto loop_3;
        }
    }
}
#endif

void Shatterable::PlatformDetach() {
    s32 sp18;
    s8 sp14;
    f64 *sp10;
    s32 spC;
    s32 sp8;
    s32 temp_r3_1850;

    temp_r3_1850 = this->unk160.unk0;
    if ((u32) temp_r3_1850 != 0U) {
        spC = 0;
        sp8 = 0x24;
        sp10 = &this->unk130;
        sp14 = 0;
        sp18 = 0;
        M2C_FIELD(M2C_FIELD(temp_r3_1850, void **, 0x44), M2C_UNK (**)(s32 *, M2C_UNK, M2C_UNK), 0x2C)(&sp8, 0x24, 0);
        this->unk160.unk0 = 0;
    }
}

void Shatterable::PlatformAttach(MKProp *arg0, MKCollisionInfo *arg1) {
    MKCollisionInfo *sp18;
    u8 sp14;
    f64 *sp10;
    s32 spC;
    s32 sp8;
    s32 temp_r3_1888;

    PlatformDetach();
    this->unk160.unk0 = (s32) arg0;
    temp_r3_1888 = this->unk160.unk0;
    if ((u32) temp_r3_1888 != 0U) {
        spC = 0;
        sp8 = 0x23;
        sp10 = &this->unk130;
        sp14 = 0;
        sp18 = arg1;
        M2C_FIELD(M2C_FIELD(temp_r3_1888, void **, 0x44), M2C_UNK (**)(s32 *, M2C_UNK, M2C_UNK), 0x2C)(&sp8, 0x23, 0);
        if (sp14 == 0) {
            this->unk160.unk0 = 0;
        }
    }
}

void Shatterable::SetStateAnim(int arg0) {
    s32 temp_r31_1931;

    if ((MKAnimScript *) this->unk80 != NULL) {
        temp_r31_1931 = arg0 * 4;
        if ((u32) M2C_FIELD((checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + temp_r31_1931), u32 *, 0x120) != 0U) {
            this->unk80->SetAnim(M2C_FIELD((checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + temp_r31_1931), MKAnim **, 0x120), 1.0f, 0.0f, 0, -1);
        }
    }
}

#if 0 // DRAFT: function call 'PropFlagsSet(unsigned long *, unsigned int)' does not match
void Shatterable::EnableCollision() {
    PropFlagsSet((u32 *) &this->unk10, 0x100000U);
    *(this->unk158 + (((s32) this->unk170 << 7) + 0x6C)) = 1;
}
#endif

#if 0 // DRAFT: function call 'PropFlagsClear(unsigned long *, unsigned int)' does not
void Shatterable::DisableCollision() {
    PropFlagsClear((u32 *) &this->unk10, 0x100000U);
    *(this->unk158 + (((s32) this->unk170 << 7) + 0x6C)) = 0;
}
#endif

#if 0 // DRAFT: illegal type
void Shatterable::Shatter(bool arg0, MKVector3 *arg1, int arg2, MKVector3 *arg3, bool arg4, bool arg5) {
    s8 sp70;
    f64 sp68;
    f64 sp60;
    s32 sp5C;
    s32 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    M2C_UNK sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    MKProp *temp_r4_2095;
    MKProp *temp_r4_2148;
    MKProp *temp_r4_2221;
    MKProp *temp_r4_2330;
    MKVector3 *temp_r29_2254;
    MKVector3 *var_r26_2164;
    MKVector3 *var_r3_2114;
    ShatterableDescriptor *temp_r26_2263;
    ShatterableDescriptor *temp_r27_2259;
    ShatterableDescriptor *temp_r28_2256;
    f32 temp_f4_2379;
    f32 var_f0_2125;
    s32 temp_r0_2196;
    s32 temp_r0_2208;
    s32 temp_r0_2236;
    s32 temp_r3_2052;
    s32 var_r26_2202;
    s32 var_r28_2203;
    s32 var_r4_2174;
    void **temp_r3_2307;
    void *temp_r26_2301;
    void *temp_r4_2112;
    void *temp_r5_2099;

    if (((s32) M2C_FIELD(&gb, s32 *, 0x340) == 0) && ((u8) M2C_FIELD((checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk11C + ((s32) this->unk170 * 0x17C)), u8 *, 0x178) != 0) && ((MKProp *) this->unk170 < (s32) checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk160)) {
        if (((u8) M2C_FIELD(this, u8 *, 0x1A2) != 0) && ((s32) checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk104 != 0)) {
            temp_r3_2052 = KDSound_Play(checked_cast<P21ShatterableDescriptor, 16MKPropDescriptor>__FP16MKPropDescriptor((MKPropDescriptor *) this->unk0)->unk104, 0U, -1);
            if (temp_r3_2052 != 0) {
                KDSound_SetPitch(temp_r3_2052, (0.1f * (f32) this->unk170) + 1.0f);
            }
        }
        if (((u8) checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk118 >> 3U) & 1) {
            this->unkD0.Show(0U);
        }
        TriggerShatterFX();
        if (((s32) checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unkF4 != 0) && (arg5 == 0)) {
            SpawnGems(checked_cast<P21ShatterableDescriptor, 16MKPropDescriptor>__FP16MKPropDescriptor((MKPropDescriptor *) this->unk0)->unkF4);
        }
        temp_r4_2095 = this->unk170;
        temp_r5_2099 = checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk11C;
        sp20 = 0.0f;
        sp18 = 0.0f;
        sp1C = M2C_FIELD((temp_r5_2099 + ((s32) temp_r4_2095 * 0x17C)), f32 *, 0x15C);
        sp50 = (f64) sp20;
        sp48 = (f64) sp18;
        temp_r4_2112 = this->unk158 + (((s32) temp_r4_2095 << 7) + 0x20);
        if (arg3 != NULL) {
            var_r3_2114 = arg3;
        } else {
            var_r3_2114 = (MKVector3 *) &sp48;
        }
        M2C_FIELD(temp_r4_2112, f64 *, 0) = (f64) M2C_FIELD(var_r3_2114, f64 *, 0);
        M2C_FIELD(temp_r4_2112, f64 *, 8) = (f64) M2C_FIELD(var_r3_2114, f64 *, 8);
        if (arg0 != 0) {
            var_f0_2125 = 0.2f;
        } else {
            var_f0_2125 = 1.0f;
        }
        M2C_FIELD((this->unk158 + ((s32) this->unk170 << 7)), f32 *, 0x38) = var_f0_2125;
        *(this->unk158 + (((s32) this->unk170 << 7) + 0x6C)) = 0;
        if (((u8) checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk108 != 0) && (temp_r4_2148 = this->unk170, (((void *) (temp_r4_2148 + 1) < (s32) checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk160) != 0))) {
            ((KDShatter2 *) (this->unk158 + ((s32) temp_r4_2148 << 7)))->Shatter(0, this->unk8 + 0x30);
        } else {
            if (arg1 != NULL) {
                var_r26_2164 = arg1;
            } else {
                var_r26_2164 = this->unk8 + 0x30;
            }
            if (arg2 == -1) {
                var_r4_2174 = checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk15C;
            } else {
                var_r4_2174 = arg2;
            }
            ((KDShatter2 *) (this->unk158 + ((s32) this->unk170 << 7)))->Shatter(var_r4_2174, var_r26_2164);
        }
        *(this->unk158 + (((s32) this->unk170 << 7) + 0x6C)) = 1;
        temp_r0_2196 = *(this->unk158 + (((s32) this->unk170 << 7) + 0x44));
        if ((temp_r0_2196 == 1) || (temp_r0_2196 == 2)) {
            var_r26_2202 = 0;
            var_r28_2203 = 0;
loop_32:
            if (var_r28_2203 < (s32) checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk160) {
                temp_r0_2208 = var_r26_2202 + 0x6C;
                var_r28_2203 += 1;
                var_r26_2202 += 0x80;
                *(this->unk158 + temp_r0_2208) = 0;
                goto loop_32;
            }
            temp_r4_2221 = this->unk170;
            if (temp_r4_2221 < (s32) (checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk160 - 1)) {
                *(this->unk158 + (((s32) (temp_r4_2221 + 1) << 7) + 0x6C)) = 1;
            }
            temp_r0_2236 = *(this->unk158 + (((s32) this->unk170 << 7) + 0x44));
            if (temp_r0_2236 == 1) {
                this->unk15C.unk0 = 2;
                SetStateAnim(1);
                if ((checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk154 > 0.0f) && (arg4 != 0)) {
                    temp_r29_2254 = this->unk8 + 0x30;
                    temp_r28_2256 = checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
                    temp_r27_2259 = checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
                    temp_r26_2263 = checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
                    ((KDInput *) (M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), KDInput *(**)(void **, void ***), 0x40)(M2C_FIELD(&gb, void ***, 0), &gb)))->RumblePlay3D(temp_r26_2263->unk14C, temp_r27_2259->unk150, temp_r28_2256->unk154, temp_r29_2254, 37.0f, 0, 4.0f, 0U);
                }
            } else if (temp_r0_2236 == 2) {
                this->unk15C.unk0 = 0;
                this->unk178 = 0.0f;
                SetStateAnim(2);
            }
            this->unk160.Send((MKProp *) this);
            if ((u32) M2C_FIELD((this->unk158 + ((s32) this->unk170 << 7)), u32 *, 0x78) != 0U) {
                temp_r26_2301 = pInstanceMem.__vptr;
                pInstanceMem.__vptr = this;
                temp_r3_2307 = M2C_FIELD((this->unk158 + ((s32) this->unk170 << 7)), void ***, 0x78);
                M2C_FIELD(*temp_r3_2307, M2C_UNK (**)(void **), 0x4C)(temp_r3_2307);
                pInstanceMem.__vptr = temp_r26_2301;
            }
        }
        ((KDShatter2 *) (this->unk158 + ((s32) this->unk170 << 7)))->ClearVisible();
        this->unk170 += 1;
        if (!(this->unk10 & 0x100000)) {
            DisableCollision();
        }
        temp_r4_2330 = this->unk170;
        if (temp_r4_2330 < (s32) checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk160) {
            ((KDShatter2 *) (this->unk158 + ((s32) temp_r4_2330 << 7)))->SetVisibleUnshattered();
        }
        if (((u8) checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk114 != 0) && (((s32) checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk160 == 0) || ((MKProp *) this->unk170 == (s32) checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk160) || ((u8) M2C_FIELD((checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk11C + ((s32) this->unk170 * 0x17C)), u8 *, 0x178) == 0))) {
            this->unkC8.UnregisterTargetable();
        }
        if (((void *) M2C_FIELD(&gb, void **, 0x3B8) != NULL) && ((u8) checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk166 != 0)) {
            temp_f4_2379 = M2C_BITWISE(f32, this->unk17C);
            if (temp_f4_2379 != 0.0f) {
                sp5C = 0;
                MKVector(1.0f, 1.0f, 1.0f);
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
                sp58 = 0x417;
                sp60 = sp8;
                sp10 = sp30 * (100.0f * temp_f4_2379);
                sp70 = 1;
                sp68 = (f64) sp10;
                sp38 = sp8;
                sp40 = (f64) sp10;
                M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, f64), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &sp58, sp8);
            }
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unksp10C'
void Shatterable::Message(MKMessage *arg0) {
    struct __vt *vtable174;
    s32 sp170;
    s8 sp16C;
    s32 sp168;
    s32 sp164;
    s8 sp160;
    f32 sp158;
    f32 sp154;
    f32 sp150;
    s32 sp14C;
    s32 sp148;
    f64 sp140;
    f64 sp138;                                      /* compiler-managed */
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
    f64 sp98;
    f32 sp90;
    f32 sp80;
    f32 sp70;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp50;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    s32 sp20;
    s32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    KDSoundPlayer *temp_r3_2486;
    MKHeap **temp_r3_2890;
    MKSceneManager *temp_r0_3687;
    MKVector3 *temp_r28_2803;
    Shatterable ***temp_r4_2716;
    Shatterable **temp_r3_2738;
    Shatterable **temp_r3_2742;
    Shatterable **var_r3_2719;
    Shatterable *temp_r0_2728;
    Shatterable *var_r0_3856;
    ShatterableDescriptor *temp_r28_3363;
    ShatterableDescriptor *temp_r28_3771;
    f32 temp_f0_2610;
    f32 temp_f0_2894;
    f32 temp_f1_2893;
    f32 temp_f1_2971;
    f32 temp_f2_2638;
    f32 temp_f2_2836;
    f32 temp_f2_2896;
    f32 temp_f2_3586;
    f32 temp_f3_2623;
    f32 temp_f3_2970;
    f32 temp_f3_3043;
    f32 temp_f4_2620;
    f32 temp_f4_2973;
    f32 temp_f4_3042;
    f32 temp_f5_2616;
    f32 temp_f5_3045;
    f32 var_f0_2639;
    f32 var_f0_2837;
    f32 var_f0_2904;
    f32 var_f0_3587;
    f32 var_f1_2977;
    f32 var_f4_3191;
    f32 var_f4_3237;
    f32 var_f5_3124;
    f32 var_f6_3049;
    f32 var_f6_3197;
    f64 temp_f1_3130;
    f64 temp_f1_3136;
    f64 temp_f1_3140;
    f64 temp_f1_3242;
    f64 temp_f1_3248;
    f64 temp_f1_3252;
    f64 temp_f2_2908;
    f64 temp_f2_2914;
    f64 temp_f2_2918;
    f64 temp_f3_2980;
    f64 temp_f3_2986;
    f64 temp_f3_2990;
    f64 temp_f3_3052;
    f64 temp_f3_3058;
    f64 temp_f3_3062;
    s32 temp_r0_2491;
    s32 temp_r0_3570;
    s32 temp_r3_2814;
    s32 temp_r3_2937;
    s32 temp_r3_3009;
    s32 temp_r3_3081;
    s32 temp_r3_3159;
    s32 temp_r3_3271;
    s32 temp_r3_3561;
    s32 temp_r3_3644;
    s32 var_r0_2947;
    s32 var_r0_3019;
    s32 var_r0_3091;
    s32 var_r0_3169;
    s32 var_r0_3281;
    s32 var_r28_3756;
    s32 var_r28_3783;
    u32 temp_r3_3870;
    u32 temp_r3_3881;
    u32 temp_r4_3686;
    u64 temp_r28_3688;
    u64 temp_ret_3686;
    void **temp_r3_3461;
    void *temp_r28_2595;
    void *temp_r28_3455;
    void *temp_r31_2713;
    void *temp_r3_2606;
    void *temp_r3_2968;
    void *temp_r3_3040;
    void *temp_r3_3535;
    void *temp_r3_3754;
    void *temp_r3_3854;
    void *temp_r4_2891;
    void *temp_r4_3458;
    void *temp_r4_3872;
    void *temp_r4_3882;
    void *temp_r5_2680;

    temp_r3_2486 = this->unk100;
    if (temp_r3_2486 != NULL) {
        temp_r3_2486->Message(arg0);
    }
    temp_r0_2491 = arg0->unk0;
    switch (temp_r0_2491) {                         /* switch 1; irregular */
    case 179:                                       /* switch 1 */
        EnableCollision();
    default:                                        /* switch 1 */
block_296:
        GameProp::Message(arg0);
        return;
    case 178:                                       /* switch 1 */
        DisableCollision();
        goto block_296;
    case 353:                                       /* switch 1 */
        M2C_FIELD(this, u8 *, 0x19C) = 1U;
        goto block_296;
    case 352:                                       /* switch 1 */
        M2C_FIELD(this, u8 *, 0x19C) = 0U;
        goto block_296;
    case 1:                                         /* switch 1 */
        if (this->unk10 & 0x160000) {
            if ((u8) M2C_FIELD(this, u8 *, 0x19C) == 0) {
                return;
            }
            if (((s32) this->unk15C.unk0 == 2) && ((s32) this->unk16C == 0)) {
                temp_r28_2595 = checked_cast<ExplodeMsg *, MKMessage>(arg0);
                if (((u8) checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk118 >> 4U) & 1) {
                    temp_r3_2606 = this->unk8;
                    temp_f0_2610 = M2C_FIELD(temp_r28_2595, f32 *, 0x20) + GetCollisionRadius();
                    sp108 = M2C_FIELD(temp_r3_2606, f64 *, 0x30);
                    sp110 = M2C_FIELD(temp_r3_2606, f64 *, 0x38);
                    temp_f5_2616 = unksp10C - M2C_FIELD(temp_r28_2595, f32 *, 0x14);
                    temp_f4_2620 = (f32) sp108 - M2C_FIELD(temp_r28_2595, f32 *, 0x10);
                    temp_f3_2623 = (f32) sp110 - M2C_FIELD(temp_r28_2595, f32 *, 0x18);
                    if (((temp_f3_2623 * temp_f3_2623) + ((temp_f4_2620 * temp_f4_2620) + (temp_f5_2616 * temp_f5_2616))) < (temp_f0_2610 * temp_f0_2610)) {
                        if (M2C_BITWISE(f32, this->unk168) > 0.0f) {
                            temp_f2_2638 = checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unkF0;
                            var_f0_2639 = M2C_BITWISE(f32, this->unk168) - M2C_FIELD(temp_r28_2595, f32 *, 0x2C);
                            if (var_f0_2639 < temp_f2_2638) {

                            } else {
                                var_f0_2639 = temp_f2_2638;
                            }
                            if (var_f0_2639 > 0.0f) {

                            } else {
                                var_f0_2639 = 0.0f;
                            }
                            this->unk168 = var_f0_2639;
                            this->unk184 = (MKSceneManager *) (s32) M2C_FIELD(temp_r28_2595, f32 *, 0x2C);
                        } else {
                            this->unk184 = NULL;
                        }
                        SetSmashPropState((SmashPropState) 1);
                        return;
                    }
                }
            } else {
                if (!(((u8) checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk164 >> 6U) & 1) && ((u32) M2C_FIELD(checked_cast<ExplodeMsg *, MKMessage>(arg0), u32 *, 8) != this)) {
                    temp_r5_2680 = this->unk8;
                    spF8 = M2C_FIELD(temp_r5_2680, f64 *, 0x30);
                    sp100 = M2C_FIELD(temp_r5_2680, f64 *, 0x38);
                }
                goto block_296;
            }
        }
        break;
    case 4:                                         /* switch 1 */
        if ((this->unk10 & 0x160000) && ((u8) M2C_FIELD(this, u8 *, 0x19C) != 0)) {
            if ((u8) M2C_FIELD((checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk11C + ((s32) this->unk170 * 0x17C)), u8 *, 0x179) == 0) {
                return;
            }
            if (((s32) this->unk15C.unk0 == 2) && ((s32) this->unk16C == 0) && (temp_r31_2713 = checked_cast<MeleeAttackHitMsg *, MKMessage>(arg0), (((s32) this->unk16C == 0) != 0))) {
                temp_r4_2716 = M2C_FIELD(temp_r31_2713, Shatterable ****, 0x34);
                if (temp_r4_2716 != NULL) {
                    var_r3_2719 = *temp_r4_2716;
loop_81:
                    temp_r0_2728 = *var_r3_2719;
                    if (temp_r0_2728 == NULL) {
                        var_r3_2719 = NULL;
                    } else if (temp_r0_2728 == this) {

                    } else {
                        var_r3_2719 += 4;
                        goto loop_81;
                    }
                    if (var_r3_2719 == NULL) {
                        goto block_84;
                    }
                } else {
block_84:
                    if (temp_r4_2716 != NULL) {
                        temp_r3_2738 = *temp_r4_2716;
                        if ((u32) M2C_FIELD(temp_r3_2738, u32 *, -4) != 0U) {
                            temp_r3_2742 = temp_r3_2738 - 4;
                            *temp_r4_2716 = temp_r3_2742;
                            *temp_r3_2742 = this;
                        }
                    }
                    if (((((u8) checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk118 >> 7U) & 1) && (M2C_FIELD(temp_r31_2713, s32 *, 0x30) & 0x1FF)) || ((((u8) checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk118 >> 6U) & 1) && (M2C_FIELD(temp_r31_2713, s32 *, 0x30) & 0x200)) || ((((u8) checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk118 >> 5U) & 1) && (M2C_FIELD(temp_r31_2713, s32 *, 0x30) & 0x400)) || ((((u8) checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk118 >> 1U) & 1) && (M2C_FIELD(temp_r31_2713, s32 *, 0x30) & 0x2000)) || ((((u8) checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk118 >> 4U) & 1) && (M2C_FIELD(temp_r31_2713, s32 *, 0x30) & 0x1000))) {
                        M2C_FIELD(this, u8 *, 0x1A1) = (u8) (M2C_FIELD(this, u8 *, 0x1A1) | 0x80);
                        M2C_FIELD(temp_r31_2713, s8 *, 0x3E) = 1;
                        if ((s32) checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk100 != 0) {
                            temp_r28_2803 = this->unk8 + 0x30;
                            KDSound_Play3d(checked_cast<P21ShatterableDescriptor, 16MKPropDescriptor>__FP16MKPropDescriptor((MKPropDescriptor *) this->unk0)->unk100, temp_r28_2803, 0U, -1, 0.0f, 0U);
                        } else {
                            temp_r3_2814 = M2C_FIELD(temp_r31_2713, s32 *, 0x2C);
                            if ((temp_r3_2814 > 0) && (M2C_FIELD(temp_r31_2713, s32 *, 0x30) & 0x400)) {
                                KDSound_Play3d(temp_r3_2814, this->unk8 + 0x30, 0U, -1, 0.0f, 0U);
                            }
                        }
                        if (M2C_BITWISE(f32, this->unk168) > 0.0f) {
                            temp_f2_2836 = checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unkF0;
                            var_f0_2837 = M2C_BITWISE(f32, this->unk168) - M2C_FIELD(temp_r31_2713, f32 *, 0x20);
                            if (var_f0_2837 < temp_f2_2836) {

                            } else {
                                var_f0_2837 = temp_f2_2836;
                            }
                            if (var_f0_2837 > 0.0f) {

                            } else {
                                var_f0_2837 = 0.0f;
                            }
                            this->unk168 = var_f0_2837;
                            this->unk184 = (MKSceneManager *) (s32) M2C_FIELD(temp_r31_2713, f32 *, 0x20);
                        } else {
                            this->unk184 = NULL;
                        }
                        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
                        if ((M2C_BITWISE(f32, this->unk168) == 0.0f) && ((s32) this->unk15C.unk0 == 2) && ((s32) this->unk16C == 0)) {
                            SetSmashPropState((SmashPropState) 1);
                        } else if (((s32) this->unk15C.unk0 == 2) && ((s32) this->unk16C == 0)) {
                            SetSmashPropState((SmashPropState) 1);
                            temp_r3_2890 = MKModel_GetBoundingVolume(this->unk4, (SubObjectType) 0, -1);
                            temp_r4_2891 = this->unk8;
                            temp_f1_2893 = M2C_FIELD(temp_r4_2891, f32 *, 0x20);
                            temp_f0_2894 = M2C_FIELD(temp_r4_2891, f32 *, 0x24);
                            temp_f2_2896 = M2C_FIELD(temp_r4_2891, f32 *, 0x28);
                            sp138 = M2C_FIELD(temp_r3_2890, f64 *, 0x10);
                            sp140 = M2C_FIELD(temp_r3_2890, f64 *, 0x18);
                            var_f0_2904 = (temp_f2_2896 * temp_f2_2896) + ((temp_f1_2893 * temp_f1_2893) + (temp_f0_2894 * temp_f0_2894));
                            unksp13C = 0.0f;
                            if (var_f0_2904 > 0.0f) {
                                temp_f2_2908 = __frsqrte(var_f0_2904);
                                temp_f2_2914 = 0.5 * temp_f2_2908 * -(((f64) var_f0_2904 * (temp_f2_2908 * temp_f2_2908)) - 3.0);
                                temp_f2_2918 = 0.5 * temp_f2_2914 * -(((f64) var_f0_2904 * (temp_f2_2914 * temp_f2_2914)) - 3.0);
                                var_f0_2904 = (f32) ((f64) var_f0_2904 * (0.5 * temp_f2_2918 * -(((f64) var_f0_2904 * (temp_f2_2918 * temp_f2_2918)) - 3.0)));
                            } else if (var_f0_2904 < M2C_BITWISE(f32, 0.0)) {
                                var_f0_2904 = __float_nan;
                            } else {
                                sp18 = var_f0_2904;
                                temp_r3_2937 = M2C_BITWISE(s32, sp18) & 0x7F800000;
                                switch (temp_r3_2937) { /* switch 2; irregular */
                                case 0x7F800000:    /* switch 2 */
                                    if (M2C_BITWISE(s32, sp18) & 0x7FFFFF) {
                                        var_r0_2947 = 1;
                                    } else {
                                        var_r0_2947 = 2;
                                    }
                                    break;
                                case 0x0:           /* switch 2 */
                                    if (M2C_BITWISE(s32, sp18) & 0x7FFFFF) {
                                        var_r0_2947 = 5;
                                    } else {
                                        var_r0_2947 = 3;
                                    }
                                    break;
                                default:            /* switch 2 */
                                    var_r0_2947 = 4;
                                    break;
                                }
                                if (var_r0_2947 == 1) {
                                    var_f0_2904 = __float_nan;
                                }
                            }
                            temp_r3_2968 = this->unk8;
                            temp_f3_2970 = M2C_FIELD(temp_r3_2968, f32 *, 0);
                            temp_f1_2971 = M2C_FIELD(temp_r3_2968, f32 *, 4);
                            temp_f4_2973 = M2C_FIELD(temp_r3_2968, f32 *, 8);
                            var_f1_2977 = (temp_f4_2973 * temp_f4_2973) + ((temp_f3_2970 * temp_f3_2970) + (temp_f1_2971 * temp_f1_2971));
                            if (var_f1_2977 > 0.0f) {
                                temp_f3_2980 = __frsqrte(var_f1_2977);
                                temp_f3_2986 = 0.5 * temp_f3_2980 * -(((f64) var_f1_2977 * (temp_f3_2980 * temp_f3_2980)) - 3.0);
                                temp_f3_2990 = 0.5 * temp_f3_2986 * -(((f64) var_f1_2977 * (temp_f3_2986 * temp_f3_2986)) - 3.0);
                                var_f1_2977 = (f32) ((f64) var_f1_2977 * (0.5 * temp_f3_2990 * -(((f64) var_f1_2977 * (temp_f3_2990 * temp_f3_2990)) - 3.0)));
                            } else if (var_f1_2977 < M2C_BITWISE(f32, 0.0)) {
                                var_f1_2977 = __float_nan;
                            } else {
                                sp14 = var_f1_2977;
                                temp_r3_3009 = M2C_BITWISE(s32, sp14) & 0x7F800000;
                                switch (temp_r3_3009) { /* switch 3; irregular */
                                case 0x7F800000:    /* switch 3 */
                                    if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                                        var_r0_3019 = 1;
                                    } else {
                                        var_r0_3019 = 2;
                                    }
                                    break;
                                case 0x0:           /* switch 3 */
                                    if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                                        var_r0_3019 = 5;
                                    } else {
                                        var_r0_3019 = 3;
                                    }
                                    break;
                                default:            /* switch 3 */
                                    var_r0_3019 = 4;
                                    break;
                                }
                                if (var_r0_3019 == 1) {
                                    var_f1_2977 = __float_nan;
                                }
                            }
                            temp_r3_3040 = this->unk8;
                            temp_f4_3042 = M2C_FIELD(temp_r3_3040, f32 *, 0x10);
                            temp_f3_3043 = M2C_FIELD(temp_r3_3040, f32 *, 0x14);
                            temp_f5_3045 = M2C_FIELD(temp_r3_3040, f32 *, 0x18);
                            var_f6_3049 = (temp_f5_3045 * temp_f5_3045) + ((temp_f4_3042 * temp_f4_3042) + (temp_f3_3043 * temp_f3_3043));
                            if (var_f6_3049 > 0.0f) {
                                temp_f3_3052 = __frsqrte(var_f6_3049);
                                temp_f3_3058 = 0.5 * temp_f3_3052 * -(((f64) var_f6_3049 * (temp_f3_3052 * temp_f3_3052)) - 3.0);
                                temp_f3_3062 = 0.5 * temp_f3_3058 * -(((f64) var_f6_3049 * (temp_f3_3058 * temp_f3_3058)) - 3.0);
                                var_f6_3049 = (f32) ((f64) var_f6_3049 * (0.5 * temp_f3_3062 * -(((f64) var_f6_3049 * (temp_f3_3062 * temp_f3_3062)) - 3.0)));
                            } else if (var_f6_3049 < M2C_BITWISE(f32, 0.0)) {
                                var_f6_3049 = __float_nan;
                            } else {
                                sp10 = var_f6_3049;
                                temp_r3_3081 = M2C_BITWISE(s32, sp10) & 0x7F800000;
                                switch (temp_r3_3081) { /* switch 4; irregular */
                                case 0x7F800000:    /* switch 4 */
                                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                                        var_r0_3091 = 1;
                                    } else {
                                        var_r0_3091 = 2;
                                    }
                                    break;
                                case 0x0:           /* switch 4 */
                                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                                        var_r0_3091 = 5;
                                    } else {
                                        var_r0_3091 = 3;
                                    }
                                    break;
                                default:            /* switch 4 */
                                    var_r0_3091 = 4;
                                    break;
                                }
                                if (var_r0_3091 == 1) {
                                    var_f6_3049 = __float_nan;
                                }
                            }
                            var_f5_3124 = ((f32) sp140 * (f32) sp140) + (((f32) sp138 * (f32) sp138) + (unksp13C * unksp13C));
                            if (var_f5_3124 > 0.000001f) {
                                if (var_f5_3124 > 0.0f) {
                                    temp_f1_3130 = __frsqrte(var_f5_3124);
                                    temp_f1_3136 = 0.5 * temp_f1_3130 * -(((f64) var_f5_3124 * (temp_f1_3130 * temp_f1_3130)) - 3.0);
                                    temp_f1_3140 = 0.5 * temp_f1_3136 * -(((f64) var_f5_3124 * (temp_f1_3136 * temp_f1_3136)) - 3.0);
                                    var_f5_3124 = (f32) ((f64) var_f5_3124 * (0.5 * temp_f1_3140 * -(((f64) var_f5_3124 * (temp_f1_3140 * temp_f1_3140)) - 3.0)));
                                } else if (var_f5_3124 < M2C_BITWISE(f32, 0.0)) {
                                    var_f5_3124 = __float_nan;
                                } else {
                                    spC = var_f5_3124;
                                    temp_r3_3159 = M2C_BITWISE(s32, spC) & 0x7F800000;
                                    switch (temp_r3_3159) { /* switch 5; irregular */
                                    case 0x7F800000: /* switch 5 */
                                        if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                                            var_r0_3169 = 1;
                                        } else {
                                            var_r0_3169 = 2;
                                        }
                                        break;
                                    case 0x0:       /* switch 5 */
                                        if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                                            var_r0_3169 = 5;
                                        } else {
                                            var_r0_3169 = 3;
                                        }
                                        break;
                                    default:        /* switch 5 */
                                        var_r0_3169 = 4;
                                        break;
                                    }
                                    if (var_r0_3169 == 1) {
                                        var_f5_3124 = __float_nan;
                                    }
                                }
                                var_f4_3191 = 1.0f / var_f5_3124;
                            } else {
                                var_f4_3191 = 0.0f;
                                var_f5_3124 = 0.0f;
                            }
                            var_f6_3197 = 0.0f;
                            sp60 = 0.0f;
                            sp58 = 0.0f;
                            sp5C = 200.0f;
                            sp138 = (f32) sp138 * var_f4_3191;
                            unksp13C *= var_f4_3191;
                            spA8 = (f64) sp58;
                            spB0 = (f64) sp60;
                            M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
                            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r3, 0x0, qr0 */);
                            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
                            spB8 = sp88;
                            sp90 = M2C_FIELD(temp_r31_2713, f32 *, 0x18) - M2C_FIELD((this->unk8 + 0x30), f32 *, 8);
                            spC0 = (f64) sp90;
                            var_f4_3237 = ((f32) spC0 * (f32) spC0) + (((f32) spB8 * (f32) spB8) + (unkspBC * unkspBC));
                            if (var_f4_3237 > 1e-12f) {
                                if (var_f4_3237 > 0.0f) {
                                    temp_f1_3242 = __frsqrte(var_f4_3237);
                                    temp_f1_3248 = 0.5 * temp_f1_3242 * -(((f64) var_f4_3237 * (temp_f1_3242 * temp_f1_3242)) - 3.0);
                                    temp_f1_3252 = 0.5 * temp_f1_3248 * -(((f64) var_f4_3237 * (temp_f1_3248 * temp_f1_3248)) - 3.0);
                                    var_f4_3237 = (f32) ((f64) var_f4_3237 * (0.5 * temp_f1_3252 * -(((f64) var_f4_3237 * (temp_f1_3252 * temp_f1_3252)) - 3.0)));
                                } else if (var_f4_3237 < M2C_BITWISE(f32, 0.0)) {
                                    var_f4_3237 = __float_nan;
                                } else {
                                    sp8 = var_f4_3237;
                                    temp_r3_3271 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                                    switch (temp_r3_3271) { /* switch 6; irregular */
                                    case 0x7F800000: /* switch 6 */
                                        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                            var_r0_3281 = 1;
                                        } else {
                                            var_r0_3281 = 2;
                                        }
                                        break;
                                    case 0x0:       /* switch 6 */
                                        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                            var_r0_3281 = 5;
                                        } else {
                                            var_r0_3281 = 3;
                                        }
                                        break;
                                    default:        /* switch 6 */
                                        var_r0_3281 = 4;
                                        break;
                                    }
                                    if (var_r0_3281 == 1) {
                                        var_f4_3237 = __float_nan;
                                    }
                                }
                                var_f6_3197 = 1.0f / var_f4_3237;
                            }
                            sp3C = unkspBC * var_f6_3197;
                            sp38 = (f32) spB8 * var_f6_3197;
                            sp40 = (f32) spC0 * var_f6_3197;
                            spC8 = (f64) sp38;
                            spD0 = (f64) sp40;
                            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
                            spD8 = sp78;
                            sp80 = (f32) spD0 * (0.5f * (0.333333f * (var_f0_2904 + (var_f1_2977 + var_f6_3049)) * var_f5_3124));
                            spE0 = (f64) sp80;
                            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r3, 0x0, qr0 */);
                            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                            spE8 = sp68;
                            sp70 = M2C_FIELD((this->unk8 + 0x30), f32 *, 8) + (f32) spE0;
                            spF0 = (f64) sp70;
                            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                            sp30 = 0.0f;
                            sp28 = 0.0f;
                            sp2C = 1.0f;
                            sp50 = (f32) spF0 + (f32) spB0;
                            sp128 = sp48;
                            sp130 = (f64) sp50;
                            sp98 = (f64) sp28;
                            spA0 = (f64) sp30;
                            temp_r28_3363 = checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
                            temp_r28_3363->EmitHitEffects(*((MKVector3 *) &sp128), *((MKVector3 *) &sp98), *(MKModel_GetColor(this->unk4)), (MKProp *) this, 5);
                        }
                        goto block_296;
                    }
                    if ((M2C_FIELD(temp_r31_2713, s32 *, 0x30) & 0x400) && !(((u8) checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk118 >> 5U) & 1)) {
                        KDSound_Play3d(GS_SpyroStompLand, temp_r31_2713 + 0x10, 0U, -1, 0.0f, 0U);
                        ((KDInput *) (M2C_FIELD(*gb, KDInput *(**)(void **), 0x40)(gb)))->RumblePlay(0.5f, 0.7f, 0.1f, 0, 4.0f, 0U);
                        return;
                    }
                }
            } else {
                goto block_296;
            }
        }
        break;
    case 49:                                        /* switch 1 */
        if ((this->unk10 & 0x160000) && ((u8) M2C_FIELD(this, u8 *, 0x19C) != 0)) {
            if ((u8) M2C_FIELD((checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk11C + ((s32) this->unk170 * 0x17C)), u8 *, 0x179) == 0) {
                return;
            }
            if (((s32) this->unk15C.unk0 == 2) && ((s32) this->unk16C == 0) && (checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk118 & 1) && ((u8) M2C_FIELD((checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk11C + ((s32) this->unk170 * 0x17C)), u8 *, 0x178) != 0)) {
loop_223:
                if (((MKProp *) this->unk170 < (s32) (checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk160 - 1)) && ((u8) *(checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk11C + (((s32) this->unk170 * 0x17C) + 0x2F4)) != 0)) {
                    this->unk160.Send((MKProp *) this);
                    if ((u32) *(this->unk158 + (((s32) this->unk170 << 7) + 0x78)) != 0U) {
                        temp_r28_3455 = pInstanceMem.__vptr;
                        pInstanceMem.__vptr = this;
                        temp_r4_3458 = this->unk158;
                        temp_r3_3461 = *(temp_r4_3458 + (((s32) this->unk170 << 7) + 0x78));
                        M2C_FIELD(*temp_r3_3461, M2C_UNK (**)(void **, void *), 0x4C)(temp_r3_3461, temp_r4_3458);
                        pInstanceMem.__vptr = temp_r28_3455;
                    }
                    this->unk170 += 1;
                    goto loop_223;
                }
                this->unk168 = 0.0f;
                SetSmashPropState((SmashPropState) 1);
                M2C_FIELD(checked_cast<ShatterOnCollisionMsg *, MKMessage>(arg0), s8 *, 0x18) = 1;
            }
            goto block_296;
        }
        break;
    case 136:                                       /* switch 1 */
        if (((s32) this->unk15C.unk0 == 2) && ((s32) this->unk16C == 0) && ((u8) checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk115 == 1)) {
            M2C_FIELD(checked_cast<CanHeroHurtYouMsg *, MKMessage>(arg0), s8 *, 8) = 1;
        }
        goto block_296;
    case 5:                                         /* switch 1 */
        if ((this->unk10 & 0x160000) && ((u8) M2C_FIELD(this, u8 *, 0x19C) != 0)) {
            if ((u8) M2C_FIELD((checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk11C + ((s32) this->unk170 * 0x17C)), u8 *, 0x179) == 0) {
                return;
            }
            temp_r3_3535 = checked_cast<BreathHitMessage *, MKMessage>(arg0);
            if ((s32) M2C_FIELD(temp_r3_3535, s32 *, 0x38) == 3) {
                if ((((u8) checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk118 >> 2U) & 1) && ((s32) this->unk16C != 3)) {
                    DestroyShatterable();
                    return;
                }
            } else {
                if ((((u8) checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk118 >> 1U) & 1) && (((temp_r3_3561 = M2C_FIELD(temp_r3_3535, s32 *, 0x38), ((temp_r3_3561 == 0) != 0)) && ((s32) M2C_FIELD(temp_r3_3535, s32 *, 0x40) == 3)) || ((temp_r3_3561 == 1) && ((temp_r0_3570 = M2C_FIELD(temp_r3_3535, s32 *, 0x40), ((temp_r0_3570 == 0) != 0)) || (temp_r0_3570 == 3) || (temp_r0_3570 == 2))))) {
                    if (M2C_BITWISE(f32, this->unk168) > 0.0f) {
                        temp_f2_3586 = checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unkF0;
                        var_f0_3587 = M2C_BITWISE(f32, this->unk168) - M2C_FIELD(temp_r3_3535, f32 *, 0x34);
                        if (var_f0_3587 < temp_f2_3586) {

                        } else {
                            var_f0_3587 = temp_f2_3586;
                        }
                        if (var_f0_3587 > 0.0f) {

                        } else {
                            var_f0_3587 = 0.0f;
                        }
                        this->unk168 = var_f0_3587;
                        this->unk184 = (MKSceneManager *) (s32) M2C_FIELD(temp_r3_3535, f32 *, 0x34);
                    } else {
                        this->unk184 = NULL;
                    }
                    M2C_FIELD(temp_r3_3535, s8 *, 0x50) = 1;
                    M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
                    if ((M2C_BITWISE(f32, this->unk168) == 0.0f) && ((s32) this->unk15C.unk0 == 2) && ((s32) this->unk16C == 0)) {
                        SetSmashPropState((SmashPropState) 2);
                    } else if (((s32) this->unk15C.unk0 == 2) && ((s32) this->unk16C == 0)) {
                        SetSmashPropState((SmashPropState) 1);
                    }
                }
                goto block_296;
            }
        }
        break;
    case 186:                                       /* switch 1 */
        if (this->unk10 & 0x160000) {
            temp_r3_3644 = this->unk15C.unk0;
            if ((temp_r3_3644 == 2) && ((s32) this->unk16C == 0)) {
                SetSmashPropState((SmashPropState) 2);
                return;
            }
            if (temp_r3_3644 == 2) {
                sp14C = 0;
                vtable174 = &__vt;
                sp148 = 0x30;
                sp150 = 0.0f;
                sp154 = 0.0f;
                sp158 = 0.0f;
                sp160 = 0;
                sp164 = -1;
                sp168 = 0;
                sp16C = 0;
                sp170 = 0;
                Message(&sp148, 0x30, &__vt, 0);
            }
            goto block_296;
        }
        break;
    case 48:                                        /* switch 1 */
        if (((s32) this->unk15C.unk0 == 2) && ((temp_ret_3686 = checked_cast<ShatterExtendedMsg *, MKMessage>(arg0), temp_r4_3686 = (u32) temp_ret_3686, temp_r0_3687 = this->unk174, temp_r28_3688 = temp_ret_3686, ((temp_r0_3687 == NULL) != 0)) || (temp_r0_3687->PropResolver_Resolve((s32) temp_r4_3686) == (u32) M2C_FIELD(temp_r28_3688, u32 *, 0x28)))) {
            M2C_FIELD(temp_r28_3688, s8 *, 0x18) = 1;
            sp118 = M2C_FIELD(temp_r28_3688, f64 *, 8);
            sp120 = M2C_FIELD(temp_r28_3688, f64 *, 0x10);
            unksp11C = M2C_FIELD((checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk11C + ((s32) this->unk170 * 0x17C)), f32 *, 0x15C);
            Shatter(M2C_FIELD(temp_r28_3688, u8 *, 0x24), M2C_FIELD(temp_r28_3688, s32 *, 0x20), M2C_FIELD(temp_r28_3688, s32 *, 0x1C), &sp118, 1, 0);
        }
        goto block_296;
    case 77:                                        /* switch 1 */
        if ((s32) this->unk15C.unk0 == 2) {
            sp20 = 0;
            sp1C = 0xBA;
            Message(&sp1C);
        }
        goto block_296;
    case 181:                                       /* switch 1 */
        if ((s32) this->unk15C.unk0 == 1) {
            this->unk15C.unk0 = 2;
        }
        goto block_296;
    case 180:                                       /* switch 1 */
        if ((s32) this->unk15C.unk0 == 2) {
            this->unk15C.unk0 = 1;
        }
        goto block_296;
    case 139:                                       /* switch 1 */
        temp_r3_3754 = checked_cast<GetNumHitsToDestroyMsg *, MKMessage>(arg0);
        var_r28_3756 = 0x3E8;
        if (((s32) M2C_FIELD(temp_r3_3754, s32 *, 0xC) != 0) && ((u8) M2C_FIELD((checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk11C + ((s32) this->unk170 * 0x17C)), u8 *, 0x178) != 0)) {
            temp_r28_3771 = checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
            if ((u8) M2C_FIELD((checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk11C + (temp_r28_3771->unk160 * 0x17C)), u8 *, -4) != 0) {
                var_r28_3783 = checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk160;
            } else {
                var_r28_3783 = checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk160 - 1;
            }
            var_r28_3756 = (s32) ((f32) (s32) (((f32) ((var_r28_3783 - 1) - this->unk170) * checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unkF0) + M2C_BITWISE(f32, this->unk168)) / (f32) M2C_FIELD(temp_r3_3754, s32 *, 0xC));
        }
        M2C_FIELD(temp_r3_3754, s32 *, 8) = var_r28_3756;
        goto block_296;
    case -4:                                        /* switch 1 */
        if ((s32) this->unk15C.unk0 == 3) {
            ((KDShatter2 *) (this->unk158 + ((s32) this->unk170 << 7)))->Finish();
        }
        goto block_296;
    case -3:                                        /* switch 1 */
        if (AbleToRespawn() != 0) {
            Reset();
        }
        goto block_296;
    case 38:                                        /* switch 1 */
        PlatformDetach();
        goto block_296;
    case 142:                                       /* switch 1 */
        temp_r3_3854 = checked_cast<GetTargetableMsg *, MKMessage>(arg0);
        var_r0_3856 = this;
        if (this != NULL) {
            var_r0_3856 = (Shatterable *) &this->unkC8;
        }
        M2C_FIELD(temp_r3_3854, Shatterable **, 8) = var_r0_3856;
        return;
    case 356:                                       /* switch 1 */
        Reset();
        return;
    case 92:                                        /* switch 1 */
        temp_r3_3870 = arg0->unk4;
        temp_r4_3872 = temp_r3_3870 + 0x128;
        M2C_FIELD(temp_r3_3870, M2C_UNK **, 0x12C) = &this->unk150;
        M2C_FIELD(temp_r3_3870, void **, 0x130) = (void *) this->unk158;
        this->unk158 = temp_r4_3872;
        M2C_FIELD(M2C_FIELD(temp_r3_3870, void **, 0x130), void **, 4) = temp_r4_3872;
        goto block_296;
    case 93:                                        /* switch 1 */
        temp_r3_3881 = arg0->unk4;
        temp_r4_3882 = temp_r3_3881 + 0x128;
        M2C_FIELD(M2C_FIELD(temp_r3_3881, void **, 0x130), M2C_UNK **, 4) = (M2C_UNK *) M2C_FIELD(temp_r3_3881, M2C_UNK **, 0x12C);
        M2C_FIELD(M2C_FIELD(temp_r4_3882, void **, 4), void **, 8) = (void *) M2C_FIELD(temp_r4_3882, void **, 8);
        M2C_FIELD(temp_r4_3882, void **, 8) = temp_r4_3882;
        M2C_FIELD(temp_r4_3882, void **, 4) = temp_r4_3882;
        goto block_296;
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
u8 Shatterable::AbleToRespawn() {
    s8 sp98;
    s32 sp94;
    s32 sp90;
    s32 sp8C;
    f32 sp88;
    s32 sp84;
    s8 sp83;
    s8 sp82;
    s16 sp80;
    f32 sp7C;
    f32 sp78;
    f32 sp74;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f32 temp_f31_3939;
    f32 temp_f31_3953;
    f32 temp_f3_3948;
    f64 temp_f1_3951;
    void *temp_r3_3959;
    void *temp_r5_3947;

    if (((s32) this->unk15C.unk0 == 0) && ((u8) M2C_FIELD(this, u8 *, 0x19D) != 0) && ((u8) M2C_FIELD(this, u8 *, 0x19E) == 0)) {
        this->unk178 -= gUpdateTimeDelta;
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if (this->unk178 == 0.0f) {
            this->unk178 = 0.5f;
            temp_f31_3939 = M2C_FIELD(MKModel_GetBoundingVolume(this->unk4, (SubObjectType) 0, -1), f32 *, 0x18);
            temp_r5_3947 = this->unk8;
            temp_f3_3948 = M2C_FIELD(MKModel_GetBoundingVolume(this->unk4, (SubObjectType) 0, -1), f32 *, 0x10) + temp_f31_3939;
            temp_f1_3951 = M2C_FIELD(temp_r5_3947, f64 *, 0x30);
            temp_f31_3953 = temp_f3_3948 * 0.5f;
            sp18 = temp_f1_3951;
            sp20 = M2C_FIELD(temp_r5_3947, f64 *, 0x38);
            temp_r3_3959 = M2C_FIELD(M2C_FIELD(*gb, void *(**)(void **, void ***, void *, f64, f32, f32), 0xC)(gb, &gb, temp_r5_3947, temp_f1_3951, 0.5f, temp_f3_3948), void **, 8);
            sp28 = M2C_FIELD(temp_r3_3959, f64 *, 0x30);
            sp30 = M2C_FIELD(temp_r3_3959, f64 *, 0x38);
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
            sp38 = sp8;
            sp10 = (f32) sp30 - (f32) sp20;
            sp40 = (f64) sp10;
            if ((((f32) sp40 * (f32) sp40) + (((f32) sp38 * (f32) sp38) + (unksp3C * unksp3C))) < (temp_f31_3953 * temp_f31_3953)) {
                return 0U;
            }
            sp48 = 0.0f;
            sp4C = 0.0f;
            sp50 = 0.0f;
            sp58 = 0.0f;
            sp5C = 0.0f;
            sp60 = 0.0f;
            sp68 = 0.0f;
            sp6C = 0.0f;
            sp70 = 0.0f;
            sp74 = 1.0f;
            sp78 = 0.0f;
            sp7C = 0.0f;
            sp80 = 0;
            sp82 = 0;
            sp83 = 0;
            sp84 = 0;
            sp88 = 3.4028235e38f;
            sp8C = 0;
            sp90 = 0;
            sp94 = -1;
            sp98 = 0;
            if (MKCollision_SphereCollide(*(this->unk8 + 0x30), temp_f31_3953, (MKCollisionResult *) &sp48, 1, (MKCollisionMode) 2, 0) == 0) {
                return 1U;
            }
            goto block_8;
        }
    }
block_8:
    return 0U;
}
#endif

#if 0 // DRAFT: illegal type
void Shatterable::Update() {
    s32 sp8;
    ShatterableDescriptor *temp_r29_4050;
    ShatterableDescriptor *temp_r4_4082;
    s32 var_r28_4051;
    s32 var_r30_4052;

    GameProp::Update();
    temp_r29_4050 = checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    var_r28_4051 = 0;
    var_r30_4052 = 0;
loop_2:
    if (var_r28_4051 < (s32) temp_r29_4050->unk160) {
        ((KDShatter2 *) (this->unk158 + var_r30_4052))->Update();
        var_r28_4051 += 1;
        var_r30_4052 += 0x80;
        goto loop_2;
    }
    if (AbleToRespawn() != 0) {
        Reset();
    }
    M2C_FIELD(this, s8 *, 0x19E) = 0;
    if ((KDSoundPlayer *) this->unk100 != NULL) {
        temp_r4_4082 = checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        sp8 = 1;
        this->unk100->Update(temp_r4_4082->unkFC, 1U, ((u8) M2C_FIELD(this, u8 *, 0x1A1) >> 6U) & 1, (MKProp *) this, NULL, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    }
    if ((s32) this->unk16C == 1) {
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if (M2C_BITWISE(f32, this->unk168) == 0.0f) {
            SetSmashPropState((SmashPropState) 2);
        } else if (((MKAnimScript *) this->unk80 != NULL) && ((u32) checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unkE8 != NULL) && (this->unk80->unk2C & 1)) {
            PostShatter();
        }
    }
    if ((s32) this->unk16C == 2) {
        PostShatter();
    }
    if (((s32) this->unk16C == 1) && (((MKAnimScript *) this->unk80 == NULL) || ((u32) checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unkE8 == NULL) || ((this->unk80->unk2C & 1) && !(((u8) M2C_FIELD(this, u8 *, 0x1A1) >> 7U) & 1)))) {
        SetSmashPropState((SmashPropState) 0);
    }
    M2C_FIELD(this, u8 *, 0x1A1) = (u8) (M2C_FIELD(this, u8 *, 0x1A1) & ~0x80);
}
#endif

#if 0 // DRAFT: illegal type
void Shatterable::Draw() {
    ShatterableDescriptor *temp_r29_4189;
    f32 var_f1_4197;
    s32 temp_r0_4205;
    s32 temp_r0_4215;
    s32 var_ctr_4209;
    s32 var_r27_4206;
    s32 var_r28_4230;
    s32 var_r28_4247;
    s32 var_r30_4231;
    s32 var_r30_4248;
    s32 var_r3_4208;
    s32 var_r5_4207;

    if ((u8) M2C_FIELD(this, u8 *, 0x1A0) != 0) {
        this->unk118.BeginGlowingPropDraw((MKProp *) this);
    }
    M2C_FIELD(this, s8 *, 0x19E) = 1;
    temp_r29_4189 = checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    MKModel_EnableScissoring(this->unk4, ((u32) this->unk10 >> 0xFU) & 1);
    if (((u8) this->unk88 >> 7U) & 1) {
        var_f1_4197 = 1.0f;
    } else {
        var_f1_4197 = this->unk20 * this->unk84;
    }
    MKModel_SetAlpha(this->unk4, var_f1_4197);
    temp_r0_4205 = temp_r29_4189->unk160;
    var_r27_4206 = 0;
    var_r5_4207 = 0;
    var_r3_4208 = 0;
    var_ctr_4209 = temp_r0_4205;
    if (temp_r0_4205 > 0) {
        do {
            temp_r0_4215 = *(this->unk158 + (var_r3_4208 + 0x44));
            if ((temp_r0_4215 == 1) || (temp_r0_4215 == 2) || (var_r5_4207 < (MKProp *) this->unk170)) {
                var_r27_4206 = var_r5_4207 + 1;
            }
            var_r5_4207 += 1;
            var_r3_4208 += 0x80;
            var_ctr_4209 -= 1;
        } while (var_ctr_4209 != 0);
    }
    var_r28_4230 = 0;
    var_r30_4231 = 0;
loop_15:
    if (var_r28_4230 < (s32) temp_r29_4189->unk160) {
        if (var_r28_4230 == var_r27_4206) {
            ((KDShatter2 *) (this->unk158 + var_r30_4231))->Draw(1U);
        }
        var_r28_4230 += 1;
        var_r30_4231 += 0x80;
        goto loop_15;
    }
    var_r28_4247 = 0;
    var_r30_4248 = 0;
loop_18:
    if (var_r28_4247 < (s32) temp_r29_4189->unk160) {
        ((KDShatter2 *) (this->unk158 + var_r30_4248))->Draw(0U);
        var_r28_4247 += 1;
        var_r30_4248 += 0x80;
        goto loop_18;
    }
    if ((u8) M2C_FIELD(this, u8 *, 0x1A0) != 0) {
        this->unk118.EndGlowingPropDraw();
    }
}
#endif

#if 0 // DRAFT: pointer/array required
void Shatterable::Resolve() {
    MKProp *temp_r3_4287;
    s32 temp_r3_4283;

    KDPropEx::Resolve();
    temp_r3_4283 = this->unk164.unk0;
    if (temp_r3_4283 != 0) {
        temp_r3_4287 = checked_cast<KDProp *, MKProp>(temp_r3_4283->PropResolver_Resolve(M2C_ERROR(/* Read from unset register $r4 */)));
        PlatformAttach(temp_r3_4287, temp_r3_4287 + 0x70);
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'float' to
void Shatterable::Reset() {
    s32 var_r29_4329;
    s32 var_r30_4328;

    GameProp::Reset();
    this->unk168 = checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unkF0;
    M2C_FIELD(this, u8 *, 0x1A1) = (u8) (M2C_FIELD(this, u8 *, 0x1A1) & ~0x80);
    M2C_FIELD(this, u8 *, 0x1A1) = (u8) (M2C_FIELD(this, u8 *, 0x1A1) | 0x40);
    SetSmashPropState((SmashPropState) 0);
    this->unk15C.unk0 = 2;
    var_r30_4328 = 0;
    var_r29_4329 = 0;
    this->unk178 = 0.0f;
    M2C_FIELD(this, s8 *, 0x19E) = 0;
loop_2:
    if (var_r29_4329 < (s32) checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk160) {
        *(this->unk158 + (var_r30_4328 + 0x3C)) = M2C_FIELD(this->unk0, f32 *, 0x20);
        ((KDShatter2 *) (this->unk158 + var_r30_4328))->Reset();
        ((KDShatter2 *) (this->unk158 + var_r30_4328))->ClearVisible();
        var_r29_4329 += 1;
        var_r30_4328 += 0x80;
        goto loop_2;
    }
    ResetPercentageShattered();
    ((KDShatter2 *) (this->unk158 + ((s32) this->unk170 << 7)))->SetVisibleUnshattered();
    EnableCollision();
    this->unk70.unk4 = 0;
    if ((u8) M2C_FIELD(this, u8 *, 0x19F) == 0) {
        this->unk15C.unk0 = 1;
    }
    SetStateAnim(0);
    this->unk180 = 0;
    this->unk184 = NULL;
    if ((u8) checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk114 != 0) {
        this->unkC8.RegisterTargetable();
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unkspC'
void Shatterable::LoadDone() {
    f64 sp10;
    f64 sp8;
    ShatterableDescriptor *temp_r31_4474;
    f32 var_f0_4400;
    s32 var_r25_4482;
    s32 var_r26_4485;
    s32 var_r27_4477;
    s32 var_r28_4476;
    s32 var_r30_4475;
    s8 *temp_r4_4575;
    void *temp_r3_4550;
    void *temp_r4_4484;
    void *temp_r4_4503;
    void *temp_r4_4549;
    void *temp_r5_4428;

    GameProp::LoadDone();
    var_f0_4400 = this->unk188;
    if (var_f0_4400 < 1.0f) {

    } else {
        var_f0_4400 = 1.0f;
    }
    if (var_f0_4400 > 0.0f) {

    } else {
        var_f0_4400 = 0.0f;
    }
    this->unk188 = var_f0_4400;
    ResetPercentageShattered();
    this->unkD0.Init(this->unk4, (MKProp *) this, 2000.0f, NULL, 1500.0f);
    this->unkD0.Show(1U);
    temp_r5_4428 = this->unk8;
    sp8 = M2C_FIELD(temp_r5_4428, f64 *, 0x30);
    sp10 = M2C_FIELD(temp_r5_4428, f64 *, 0x38);
    this->unkD0.unk28 = unkspC;
    SetSmashPropState((SmashPropState) 0);
    if ((MKAnimScript *) this->unk80 != NULL) {
        this->unk80->SetAnim(checked_cast<P21ShatterableDescriptor, 16MKPropDescriptor>__FP16MKPropDescriptor((MKPropDescriptor *) this->unk0)->unkE4, 1.0f, 0.0f, 0, -1);
    }
    if ((s32) checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unkFC != 0) {
        operator new(0x28U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = 0;
        }
        this->unk100 = M2C_ERROR(/* Read from unset register $r3 */);
        this->unk100->Init(0.25f, 0.25f);
    }
    temp_r31_4474 = checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    var_r30_4475 = 0;
    var_r28_4476 = 0;
    var_r27_4477 = 0;
loop_19:
    if (var_r30_4475 < (s32) temp_r31_4474->unk160) {
        var_r25_4482 = 0;
        temp_r4_4484 = this->unk158 + (var_r27_4477 + 0x68);
        var_r26_4485 = 0;
        M2C_FIELD(temp_r4_4484, s32 *, 0) = 0;
        M2C_FIELD(temp_r4_4484, s8 *, 4) = 1;
        M2C_FIELD(temp_r4_4484, Shatterable **, 8) = this;
        M2C_FIELD(temp_r4_4484, s32 *, 0xC) = 0;
loop_15:
        temp_r4_4503 = var_r28_4476 + temp_r31_4474->unk11C;
        if (var_r26_4485 < (s32) M2C_FIELD(temp_r4_4503, u16 *, 0x110)) {
            AddCollisionSubObject((s32) *(temp_r4_4503 + (var_r25_4482 + 0x112)), this->unk158 + (var_r27_4477 + 0x68));
            var_r26_4485 += 1;
            var_r25_4482 += 2;
            goto loop_15;
        }
        *(this->unk158 + (var_r27_4477 + 0x6C)) = 0;
        *(this->unk158 + var_r27_4477) = *(temp_r31_4474->unk11C + (var_r28_4476 + 0x168));
        *(this->unk158 + (var_r27_4477 + 4)) = *(temp_r31_4474->unk11C + (var_r28_4476 + 0x164));
        *(this->unk158 + (var_r27_4477 + 0x10)) = *(temp_r31_4474->unk11C + (var_r28_4476 + 0x16C));
        *(this->unk158 + (var_r27_4477 + 8)) = *(temp_r31_4474->unk11C + (var_r28_4476 + 0x170));
        *(this->unk158 + (var_r27_4477 + 0x14)) = *(temp_r31_4474->unk11C + (var_r28_4476 + 0x174));
        *(this->unk158 + (var_r27_4477 + 0x18)) = *(temp_r31_4474->unk11C + (var_r28_4476 + 0x160));
        temp_r4_4549 = temp_r31_4474->unk11C + var_r28_4476;
        temp_r3_4550 = this->unk158 + var_r27_4477;
        M2C_FIELD(temp_r3_4550, void **, 0x54) = temp_r4_4549;
        M2C_FIELD(temp_r3_4550, void **, 0x58) = (void *) (temp_r4_4549 + 0x44);
        M2C_FIELD(temp_r3_4550, void **, 0x5C) = (void *) (temp_r4_4549 + 0x88);
        ((KDShatter2 *) (this->unk158 + var_r27_4477))->LoadDone(this->unk4, temp_r31_4474->unk11C + (var_r28_4476 + 0xCC));
        ((KDShatter2 *) (this->unk158 + var_r27_4477))->ClearVisible();
        *(this->unk158 + (var_r27_4477 + 0x30)) = temp_r31_4474->unk158;
        *(this->unk158 + (var_r27_4477 + 0x60)) = temp_r31_4474->unk165;
        temp_r4_4575 = *(temp_r31_4474->unk11C + (var_r28_4476 + 0x158));
        if (temp_r4_4575 != NULL) {
            *(this->unk158 + (var_r27_4477 + 0x78)) = property_cast<KDScriptProperty *, KDProperty *>(temp_r31_4474->unk74.Find(temp_r4_4575));
        }
        var_r30_4475 += 1;
        var_r28_4476 += 0x17C;
        var_r27_4477 += 0x80;
        goto loop_19;
    }
    ((KDShatter2 *) (this->unk158 + ((s32) this->unk170 << 7)))->SetVisibleUnshattered();
    *(this->unk158 + (((s32) this->unk170 << 7) + 0x6C)) = 1;
    M2C_FIELD(this, f64 *, 0x130) = (f64) M2C_FIELD(&zero, f64 *, 0);
    this->unk138 = M2C_FIELD(&zero, f64 *, 8);
    if ((u8) M2C_FIELD(this, u8 *, 0x19F) == 0) {
        this->unk15C.unk0 = 1;
    }
    if ((u8) M2C_FIELD(this, u8 *, 0x1A0) != 0) {
        this->unk118.Init();
    }
    if ((u8) checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk114 != 0) {
        this->unkC8.RegisterTargetable();
    }
    this->unk168 = checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unkF0;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long *' to
s32 Shatterable::LoadLine(MKIniLine *arg0) {
    s32 var_r31_4647;

    var_r31_4647 = 0;
    if ((GameProp::LoadLine(arg0) != 0) || (this->unk15C.LoadLine(arg0, "onDestruction") != 0) || (arg0->LoadInt("shattererID", (s32 *) &this->unk174, 0) != 0) || (arg0->LoadBool("bRespawnWhenNotInView", this + 0x19D, 0) != 0) || (arg0->LoadBool("bStartActive", this + 0x19F, 0) != 0) || (this->unk160.LoadLine(arg0, "onShatter") != 0) || (this->unk154.LoadLine(arg0, "onHit") != 0) || (arg0->LoadBool("bGlowHint", (u8 *) &this->unk190, 0) != 0) || (arg0->LoadBool("bPlayShatterNote", this + 0x1A2, 0) != 0) || (arg0->LoadInt("platformAttachID", &this->unk164.unk0, 0) != 0) || (arg0->LoadFloat("shakeCameraStrength", (f32 *) &this->unk17C, 0) != 0) || (arg0->LoadFloat("ShatteredPercentage", &this->unk188, 0) != 0) || (arg0->LoadBool("Hitable", (u8 *) &this->unk18C, 0) != 0)) {
        var_r31_4647 = 1;
    }
    return var_r31_4647;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk150'
void Shatterable::Deinit() {
    Attachment *temp_r30_4779;
    Attachment *var_r3_4776;
    KDSoundPlayer *temp_r30_4795;
    KDSoundPlayer *temp_r3_4791;
    MKHeap *temp_r3_4821;
    ShatterableDescriptor *temp_r3_4816;
    s32 temp_cr0_eq_4796;
    s32 var_r30_4805;
    s32 var_r31_4806;
    void *temp_r30_4820;

    var_r3_4776 = this->unk154;
loop_3:
    if (var_r3_4776 != &this->unk150) {
        temp_r30_4779 = var_r3_4776->unk4;
        if (Shatterable_ParentDestroyed(var_r3_4776, this) != 0) {
            var_r3_4776 = temp_r30_4779;
            goto loop_3;
        }
    }
    this->unkD0.Deinit();
    temp_r3_4791 = this->unk100;
    if (temp_r3_4791 != NULL) {
        KDSound_Stop(&temp_r3_4791->unk0);
        temp_r30_4795 = this->unk100;
        temp_cr0_eq_4796 = temp_r30_4795 == NULL;
        if (temp_cr0_eq_4796 == 0) {
            if (temp_cr0_eq_4796 == 0) {
                KDSound_Stop(&temp_r30_4795->unk0);
            }
            operator delete(temp_r30_4795);
        }
    }
    var_r30_4805 = 0;
    var_r31_4806 = 0;
loop_11:
    temp_r3_4816 = checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    if (var_r30_4805 < (s32) temp_r3_4816->unk160) {
        ((KDShatter2 *) (this->unk158 + var_r31_4806))->Deinit();
        var_r30_4805 += 1;
        var_r31_4806 += 0x80;
        goto loop_11;
    }
    temp_r30_4820 = this->unk158;
    temp_r3_4821 = temp_r3_4816->Current();
    if (temp_r3_4821 != NULL) {
        ((MKHeap *) (temp_r3_4821->Current()))->Free(temp_r30_4820, NULL, 0);
    } else {
        free(temp_r30_4820);
    }
    if ((u8) M2C_FIELD(this, u8 *, 0x1A0) != 0) {
        this->unk118.Deinit();
    }
    PlatformDetach();
    if ((u8) checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unk114 != 0) {
        this->unkC8.UnregisterTargetable();
    }
    GameProp::Deinit();
}
#endif

u8 Shatterable_ParentDestroyed(Attachment *arg0, void *arg1) {
    void *spC;
    s32 sp8;
    void *temp_r3_4871;

    spC = NULL;
    spC = arg1;
    sp8 = 0x5E;
    temp_r3_4871 = arg0->unk0;
    M2C_FIELD(M2C_FIELD(temp_r3_4871, void **, 0x44), M2C_UNK (**)(void *, s32 *, M2C_UNK), 0x2C)(temp_r3_4871, &sp8, 0);
    return 1U;
}

#if 0 // DRAFT: undefined identifier 'temp_r3_4909'
void Shatterable::Init() {
    MKHeap *temp_r3_4909;
    MKHeap *temp_r3_4912;
    s32 temp_r0_4935;
    s32 temp_r29_4911;
    s32 var_r28_4928;
    s32 var_r30_4925;
    void *var_r3_4919;

    GameProp::Init();
    M2C_FIELD(this, u8 *, 0x1A1) = (u8) (M2C_FIELD(this, u8 *, 0x1A1) & ~0x80);
    this->unk100 = NULL;
    M2C_FIELD(this, u8 *, 0x1A1) = (u8) (M2C_FIELD(this, u8 *, 0x1A1) | 0x40);
    this->unk10 |= 0x10;
    this->unk178 = 0.0f;
    this->unk174 = NULL;
    M2C_FIELD(this, s8 *, 0x19D) = 0;
    temp_r3_4909 = checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    temp_r29_4911 = M2C_FIELD(temp_r3_4909, s32 *, 0x160) << 7;
    temp_r3_4912 = temp_r3_4909->Current();
    if (temp_r3_4912 != NULL) {
        var_r3_4919 = ((MKHeap *) (temp_r3_4912->Current()))->Alloc(temp_r29_4911, NULL, 0);
    } else {
        var_r3_4919 = malloc(temp_r29_4911);
    }
    var_r30_4925 = 0;
    this->unk158 = var_r3_4919;
    var_r28_4928 = 0;
    do {
        ((KDShatter2 *) (this->unk158 + var_r30_4925))->Init();
        var_r28_4928 += 1;
        temp_r0_4935 = var_r30_4925 + 0x78;
        var_r30_4925 += 0x80;
        *(this->unk158 + temp_r0_4935) = 0;
    } while (var_r28_4928 < 0xA);
    M2C_FIELD(this, s8 *, 0x19F) = 1;
    M2C_FIELD(this, s8 *, 0x1A0) = 0;
    M2C_FIELD(this, s8 *, 0x1A2) = 0;
    this->unk160.unk0 = 0;
    this->unk17C = 0.0f;
    this->unk164.unk0 = 0;
    M2C_FIELD(this, Shatterable **, 0x140) = this;
    this->unk180 = 0;
    this->unk184 = NULL;
    this->unk188 = 0.0f;
    M2C_FIELD(this, s8 *, 0x19C) = 1;
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void ShatterableDescriptor::LoadDone() {
    s8 sp3C;
    s8 sp1C;
    s32 sp18;
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    f32 temp_f2_5334;
    s16 temp_r30_5171;
    s32 temp_cr0_eq_5324;
    s32 temp_r0_5324;
    s32 temp_r24_5302;
    s32 var_r23_5030;
    s32 var_r23_5069;
    s32 var_r23_5109;
    s32 var_r23_5215;
    s32 var_r23_5255;
    s32 var_r23_5299;
    s32 var_r24_5022;
    s32 var_r25_5021;
    s32 var_r26_5032;
    s32 var_r26_5071;
    s32 var_r26_5111;
    s32 var_r26_5173;
    s32 var_r26_5217;
    s32 var_r26_5257;
    s32 var_r26_5300;
    s32 var_r27_5020;
    s32 var_r28_5033;
    s32 var_r28_5072;
    s32 var_r28_5112;
    s32 var_r28_5218;
    s32 var_r28_5258;
    s32 var_r4_5315;
    s8 *temp_r24_4996;
    s8 *temp_r25_4993;
    s8 *temp_r3_5152;
    s8 *temp_r3_5179;
    s8 *temp_r4_5010;
    s8 *temp_r4_5303;
    s8 *var_r3_4984;
    s8 *var_r3_5004;
    u16 *temp_r5_5055;
    u32 temp_r26_5158;
    u8 temp_r0_5191;
    void *temp_r3_5046;
    void *temp_r3_5051;
    void *temp_r3_5085;
    void *temp_r3_5090;
    void *temp_r3_5125;
    void *temp_r3_5130;
    void *temp_r3_5144;
    void *temp_r3_5231;
    void *temp_r3_5236;
    void *temp_r3_5271;
    void *temp_r3_5276;
    void *temp_r4_5204;
    void *temp_r5_5095;
    void *temp_r5_5135;
    void *temp_r5_5241;
    void *temp_r5_5281;

    GamePropDescriptor::LoadDone();
    if ((s8 *) this->unk110 != NULL) {
        if (stricmp"none" != 0) {
            var_r3_4984 = checked_cast<FXBase *, MKProp>(gMK->CreateProp(this->unk110));
        } else {
            var_r3_4984 = NULL;
        }
    } else {
        var_r3_4984 = NULL;
    }
    this->unk110 = var_r3_4984;
    temp_r25_4993 = this->unk34;
    if (temp_r25_4993 != NULL) {
        temp_r24_4996 = this->unkE4;
        if (temp_r25_4993->Exists(temp_r24_4996) != 0) {
            var_r3_5004 = temp_r25_4993->GetAnim(temp_r24_4996);
        } else {
            var_r3_5004 = NULL;
        }
        this->unkE4 = var_r3_5004;
        temp_r4_5010 = this->unkE8;
        if (temp_r4_5010 != NULL) {
            this->unkE8 = this->unk34->GetAnim(temp_r4_5010);
        }
        this->unkEC = this->unkE4;
    }
    var_r27_5020 = 0;
    var_r25_5021 = 0;
    var_r24_5022 = 0;
loop_48:
    if (var_r27_5020 < (s32) this->unk160) {
        if ((u16) *(this->unk11C + var_r24_5022) != 0) {
            var_r23_5030 = 0;
            var_r26_5032 = 0;
            var_r28_5033 = 0;
loop_16:
            temp_r3_5051 = this->unk11C;
            if (var_r23_5030 < (s32) *(var_r24_5022 + temp_r3_5051)) {
                gAssertBool = MKModel_SubObjectExists(this->unk2C, (SubObjectType) 0, *(&unshatteredNames + var_r25_5021 + var_r28_5033), &sp18);
                var_r23_5030 += 1;
                var_r28_5033 += 4;
                temp_r3_5046 = this->unk11C + var_r26_5032;
                var_r26_5032 += 2;
                *(var_r24_5022 + (temp_r3_5046 + 2)) = (s16) sp18;
                goto loop_16;
            }
            temp_r5_5055 = temp_r3_5051 + var_r24_5022;
            *(temp_r5_5055 + ((*temp_r5_5055 * 2) + 2)) = 0xFFFF;
        }
        if ((u16) *(this->unk11C + (var_r24_5022 + 0x44)) != 0) {
            var_r23_5069 = 0;
            var_r26_5071 = 0;
            var_r28_5072 = 0;
loop_21:
            temp_r3_5090 = this->unk11C;
            if (var_r23_5069 < (s32) *(var_r24_5022 + (temp_r3_5090 + 0x44))) {
                gAssertBool = MKModel_SubObjectExists(this->unk2C, (SubObjectType) 0, *(&unshatteredNames + 0x500 + var_r25_5021 + var_r28_5072), &sp14);
                var_r23_5069 += 1;
                var_r28_5072 += 4;
                temp_r3_5085 = this->unk11C + var_r26_5071;
                var_r26_5071 += 2;
                *(var_r24_5022 + (temp_r3_5085 + 0x46)) = (s16) sp14;
                goto loop_21;
            }
            temp_r5_5095 = temp_r3_5090 + var_r24_5022;
            *(temp_r5_5095 + ((M2C_FIELD(temp_r5_5095, u16 *, 0x44) * 2) + 0x46)) = 0xFFFF;
        }
        if ((u16) *(this->unk11C + (var_r24_5022 + 0x88)) != 0) {
            var_r23_5109 = 0;
            var_r26_5111 = 0;
            var_r28_5112 = 0;
loop_26:
            temp_r3_5130 = this->unk11C;
            if (var_r23_5109 < (s32) *(var_r24_5022 + (temp_r3_5130 + 0x88))) {
                gAssertBool = MKModel_SubObjectExists(this->unk2C, (SubObjectType) 0, *(&unshatteredNames + 0xA00 + var_r25_5021 + var_r28_5112), &sp10);
                var_r23_5109 += 1;
                var_r28_5112 += 4;
                temp_r3_5125 = this->unk11C + var_r26_5111;
                var_r26_5111 += 2;
                *(var_r24_5022 + (temp_r3_5125 + 0x8A)) = (s16) sp10;
                goto loop_26;
            }
            temp_r5_5135 = temp_r3_5130 + var_r24_5022;
            *(temp_r5_5135 + ((M2C_FIELD(temp_r5_5135, u16 *, 0x88) * 2) + 0x8A)) = 0xFFFF;
        }
        temp_r3_5144 = this->unk11C + var_r24_5022;
        if (((u16) M2C_FIELD(temp_r3_5144, u16 *, 0xCC) != 0) || ((s8 *) M2C_FIELD(temp_r3_5144, s8 **, 0x154) != NULL)) {
            temp_r3_5152 = M2C_FIELD(temp_r3_5144, s8 **, 0x154);
            if (temp_r3_5152 != NULL) {
                temp_r26_5158 = strlen(temp_r3_5152);
                strcpy(&sp1C, *(this->unk11C + (var_r24_5022 + 0x154)));
                M2C_FIELD(&(&sp1C)[temp_r26_5158], s8 *, -1) = 0;
                strlwr(&sp1C, 0);
                temp_r30_5171 = MKModel_GetNmbrOfSubObjects(this->unk2C, (SubObjectType) 0);
                var_r26_5173 = 0;
loop_37:
                if (var_r26_5173 < temp_r30_5171) {
                    temp_r3_5179 = MKModel_GetSubObjectName(this->unk2C, (SubObjectType) 0, var_r26_5173);
                    strcpy(&sp3C, temp_r3_5179);
                    strlwr(&sp3C);
                    if ((strstr(&sp1C) != 0U) && ((temp_r0_5191 = (u8) *temp_r3_5179, (((s8) temp_r0_5191 == 0x66) != 0)) || ((s8) temp_r0_5191 == 0x46))) {
                        *(&unshatteredNames + 0xF00 + var_r25_5021 + (*(var_r24_5022 + (this->unk11C + 0xCC)) * 4)) = temp_r3_5179;
                        temp_r4_5204 = this->unk11C + 0xCC;
                        *(var_r24_5022 + temp_r4_5204) = *(var_r24_5022 + temp_r4_5204) + 1;
                    }
                    var_r26_5173 += 1;
                    goto loop_37;
                }
            }
            var_r23_5215 = 0;
            var_r26_5217 = 0;
            var_r28_5218 = 0;
loop_40:
            temp_r3_5236 = this->unk11C;
            if (var_r23_5215 < (s32) *(var_r24_5022 + (temp_r3_5236 + 0xCC))) {
                gAssertBool = MKModel_SubObjectExists(this->unk2C, (SubObjectType) 0, *(&unshatteredNames + 0xF00 + var_r25_5021 + var_r28_5218), &spC);
                var_r23_5215 += 1;
                var_r28_5218 += 4;
                temp_r3_5231 = this->unk11C + var_r26_5217;
                var_r26_5217 += 2;
                *(var_r24_5022 + (temp_r3_5231 + 0xCE)) = (s16) spC;
                goto loop_40;
            }
            temp_r5_5241 = temp_r3_5236 + var_r24_5022;
            *(temp_r5_5241 + ((M2C_FIELD(temp_r5_5241, u16 *, 0xCC) * 2) + 0xCE)) = 0xFFFF;
        }
        if ((u16) *(this->unk11C + (var_r24_5022 + 0x110)) != 0) {
            var_r23_5255 = 0;
            var_r26_5257 = 0;
            var_r28_5258 = 0;
loop_45:
            temp_r3_5276 = this->unk11C;
            if (var_r23_5255 < (s32) *(var_r24_5022 + (temp_r3_5276 + 0x110))) {
                gAssertBool = MKModel_SubObjectExists(this->unk2C, (SubObjectType) 0, *(&unshatteredNames + 0x1400 + var_r25_5021 + var_r28_5258), &sp8);
                var_r23_5255 += 1;
                var_r28_5258 += 4;
                temp_r3_5271 = this->unk11C + var_r26_5257;
                var_r26_5257 += 2;
                *(var_r24_5022 + (temp_r3_5271 + 0x112)) = (s16) sp8;
                goto loop_45;
            }
            temp_r5_5281 = temp_r3_5276 + var_r24_5022;
            *(temp_r5_5281 + ((M2C_FIELD(temp_r5_5281, u16 *, 0x110) * 2) + 0x112)) = 0xFFFF;
        }
        var_r27_5020 += 1;
        var_r25_5021 += 0x80;
        var_r24_5022 += 0x17C;
        goto loop_48;
    }
    if ((s8 *) this->unk34 != NULL) {
        var_r23_5299 = 0;
        var_r26_5300 = 0;
        do {
            temp_r24_5302 = var_r26_5300 + 0x120;
            temp_r4_5303 = *(this + temp_r24_5302);
            if (temp_r4_5303 != NULL) {
                *(this + temp_r24_5302) = this->unk34->GetAnim(temp_r4_5303);
            }
            var_r23_5299 += 1;
            var_r26_5300 += 4;
        } while (var_r23_5299 < 3);
    }
    var_r4_5315 = this->unk160;
    if ((u8) M2C_FIELD((this->unk11C + (var_r4_5315 * 0x17C)), u8 *, -4) != 0) {

    } else {
        temp_r0_5324 = var_r4_5315 - 1;
        temp_cr0_eq_5324 = temp_r0_5324 == 0;
        var_r4_5315 = 1;
        if (temp_cr0_eq_5324 == 0) {
            var_r4_5315 = temp_r0_5324;
        }
    }
    temp_f2_5334 = this->unkF0;
    this->unkF0 = (f32) ceil(M2C_BITWISE(s32, (temp_f2_5334 / (f32) var_r4_5315)), temp_f2_5334);
}
#endif

#if 0 // DRAFT: illegal use of non-static member
s32 ShatterableDescriptor::LoadLine(MKIniLine *arg0) {
    s8 *spC;
    u8 sp8;
    MKHeap *temp_r3_5791;
    MKHeap *temp_r3_5793;
    MKHeap *var_ctr_5810;
    MKIniLine *temp_r3_5938;
    MKIniLine *var_r25_5901;
    MKIniLine *var_r25_5940;
    MKIniLine *var_r25_6004;
    MKIniLine *var_r25_6070;
    MKIniLine *var_r29_5889;
    MKIniLine *var_r30_5882;
    s32 temp_r0_5968;
    s32 temp_r0_6009;
    s32 temp_r0_6047;
    s32 temp_r0_6075;
    s32 temp_r4_6060;
    s32 temp_r5_5917;
    s32 temp_r5_5981;
    s32 temp_r5_6022;
    s32 temp_r5_6088;
    s32 temp_r6_5906;
    s32 var_r24_5604;
    s32 var_r26_5606;
    s32 var_r4_5809;
    u8 var_r26_6158;
    void *temp_r25_6159;
    void *temp_r3_5859;
    void *temp_r5_6058;
    void *temp_r6_5916;
    void *temp_r6_5979;
    void *temp_r6_6020;
    void *temp_r6_6086;
    void *var_r3_5800;

    if ((GamePropDescriptor::LoadLine(arg0) != 0) || (arg0->LoadInt("gemCount", &this->unkF4, 0) != 0) || (arg0->LoadBool("SpawnFuryGems", &this->unkF8, 0) != 0) || (KDSound_LoadLine(arg0, "sndAmbient", &this->unkFC) != 0) || (KDSound_LoadLine(arg0, "sndHit", &this->unk100) != 0) || (KDSound_LoadLine(arg0, "sndSpawnGems", &this->unk10C) != 0) || (arg0->LoadBool("bPlayShatterOnLastStage", &this->unk108, 0) != 0) || (arg0->LoadFloat("hitPoints", &this->unkF0, 0) != 0) || (arg0->LoadString("hitAnimation", &this->unkE8, 0) != 0) || (arg0->LoadString("idleAnimation", &this->unkE4, 0) != 0) || (arg0->LoadString("shatterFX", &this->unk110, 0) != 0) || (arg0->LoadFloat("upVel", &this->unk130, 0) != 0) || (arg0->LoadFloat("power", &this->unk134, 0) != 0) || (arg0->LoadFloat("bounce", &this->unk13C, 0) != 0) || (arg0->LoadFloat("gravity", &this->unk140, 0) != 0) || (arg0->LoadFloat("life", &this->unk144, 0) != 0) || (arg0->LoadFloat("airResistance", &this->unk148, 0) != 0) || (arg0->LoadFloat("spinRate", &this->unk138, 0) != 0) || (arg0->LoadFloat("controlerLrg", &this->unk14C, 0) != 0) || (arg0->LoadFloat("controlerSml", &this->unk150, 0) != 0) || (arg0->LoadFloat("controlerRmbl", &this->unk154, 0) != 0) || (KDSound_LoadLine(arg0, "sndShatter", &this->unk15C) != 0) || (KDSound_LoadLine(arg0, "sndShatterNote", &this->unk104) != 0) || (KDProp_LoadMaterialID(arg0, "ignoreMaterialID", &this->unk158) != 0) || (arg0->LoadBool("ShrinkFade", &this->unk165, 0) != 0) || (arg0->LoadBool("shakeCameraOnDamage", &this->unk166, 0) != 0) || (arg0->LoadBool("Targetable", &this->unk114, 0) != 0) || (arg0->LoadBool("hitable", &this->unk115, 0) != 0)) {
        return 1;
    }
    var_r24_5604 = 0;
    var_r26_5606 = 0;
loop_30:
    if (arg0->LoadString(*(&pShatterAnimNames + var_r26_5606), this + (var_r26_5606 + 0x120), 0) != 0) {
        return 1;
    }
    var_r24_5604 += 1;
    var_r26_5606 += 4;
    if (var_r24_5604 >= 3) {
        if (arg0->LoadBool("bIgnoreExplosion", &sp8, 0) != 0) {
            this->unk164 = (this->unk164 & ~0x40) | ((sp8 << 6) & 0x40);
            return 1;
        }
        if (arg0->IsField("cartIgnore") != 0) {
            if (arg0->GetBool(0) != 0) {
                this->unkC |= 0x80;
            } else {
                this->unkC &= 0xFFFFFF7F;
            }
            return 1;
        }
        if (arg0->LoadBool("TakeMeleeDamage", &sp8, 0) != 0) {
            this->unk118 = (this->unk118 & ~0x80) | ((sp8 << 7) & 0x80);
            goto block_109;
        }
        if (arg0->LoadBool("TakeTailSweepDamage", &sp8, 0) != 0) {
            this->unk118 = (this->unk118 & ~0x40) | ((sp8 << 6) & 0x40);
            goto block_109;
        }
        if (arg0->LoadBool("TakeTailStrikeDamage", &sp8, 0) != 0) {
            this->unk118 = (this->unk118 & ~0x20) | ((sp8 << 5) & 0x20);
            goto block_109;
        }
        if (arg0->LoadBool("TakeExplosiveDamage", &sp8, 0) != 0) {
            this->unk118 = (this->unk118 & ~0x10) | ((sp8 << 4) & 0x10);
            goto block_109;
        }
        if (arg0->LoadBool("TakeProjectileDamage", &sp8, 0) != 0) {
            this->unk118 = (this->unk118 & ~2) | ((sp8 << 1) & 2);
            goto block_109;
        }
        if (arg0->LoadBool("TakeCollisionDamage", &sp8, 0) != 0) {
            this->unk118 = (this->unk118 & ~1) | (sp8 & 1);
            goto block_109;
        }
        if (arg0->LoadBool("TakeFuryDamage", &sp8, 0) != 0) {
            this->unk118 = (this->unk118 & ~4) | ((sp8 << 2) & 4);
            goto block_109;
        }
        if (arg0->LoadBool("disableShadowOnShatter", &sp8, 0) != 0) {
            this->unk118 = (this->unk118 & ~8) | ((sp8 << 3) & 8);
            goto block_109;
        }
        if (arg0->IsField("multiStageShatter") != 0) {
            temp_r3_5791 = arg0->GetNmbrOfSubLines();
            temp_r3_5793 = temp_r3_5791->Current();
            if (temp_r3_5793 != NULL) {
                var_r3_5800 = ((MKHeap *) (temp_r3_5793->Current()))->Alloc((s32) temp_r3_5791 * 0x17C, NULL, 0);
            } else {
                var_r3_5800 = malloc((s32) temp_r3_5791 * 0x17C);
            }
            this->unk11C = var_r3_5800;
            var_r4_5809 = 0;
            var_ctr_5810 = temp_r3_5791;
            if ((s32) temp_r3_5791 > 0) {
                do {
                    *(this->unk11C + var_r4_5809) = 0;
                    *(this->unk11C + (var_r4_5809 + 2)) = 0xFFFF;
                    *(this->unk11C + (var_r4_5809 + 0x44)) = 0;
                    *(this->unk11C + (var_r4_5809 + 0x46)) = 0xFFFF;
                    *(this->unk11C + (var_r4_5809 + 0x88)) = 0;
                    *(this->unk11C + (var_r4_5809 + 0x8A)) = 0xFFFF;
                    *(this->unk11C + (var_r4_5809 + 0xCC)) = 0;
                    *(this->unk11C + (var_r4_5809 + 0xCE)) = 0xFFFF;
                    *(this->unk11C + (var_r4_5809 + 0x110)) = 0;
                    *(this->unk11C + (var_r4_5809 + 0x112)) = 0xFFFF;
                    *(this->unk11C + (var_r4_5809 + 0x178)) = 1;
                    *(this->unk11C + (var_r4_5809 + 0x154)) = 0;
                    *(this->unk11C + (var_r4_5809 + 0x158)) = 0;
                    *(this->unk11C + (var_r4_5809 + 0x179)) = 1;
                    temp_r3_5859 = this->unk11C + var_r4_5809;
                    var_r4_5809 += 0x17C;
                    M2C_FIELD(temp_r3_5859, f32 *, 0x15C) = (f32) this->unk130;
                    M2C_FIELD(temp_r3_5859, f32 *, 0x160) = (f32) this->unk134;
                    M2C_FIELD(temp_r3_5859, f32 *, 0x164) = (f32) this->unk13C;
                    M2C_FIELD(temp_r3_5859, f32 *, 0x168) = (f32) this->unk140;
                    M2C_FIELD(temp_r3_5859, f32 *, 0x16C) = (f32) this->unk144;
                    M2C_FIELD(temp_r3_5859, f32 *, 0x170) = (f32) this->unk148;
                    M2C_FIELD(temp_r3_5859, f32 *, 0x174) = (f32) this->unk138;
                    var_ctr_5810 -= 1;
                } while (var_ctr_5810 != NULL);
            }
            this->unk160 = 0;
            var_r30_5882 = arg0->unkC->GetSubLine(arg0);
loop_107:
            if (var_r30_5882 != NULL) {
                var_r29_5889 = var_r30_5882->unkC->GetSubLine(var_r30_5882);
loop_105:
                if (var_r29_5889 != NULL) {
                    if (var_r29_5889->IsField("meshes") != 0) {
                        var_r25_5901 = var_r29_5889->unkC->GetSubLine(var_r29_5889);
loop_67:
                        if (var_r25_5901 != NULL) {
                            temp_r6_5906 = this->unk160;
                            *(&unshatteredNames + ((temp_r6_5906 << 7) + (*(this->unk11C + (temp_r6_5906 * 0x17C)) * 4))) = var_r25_5901->GetFieldName();
                            temp_r6_5916 = this->unk11C;
                            temp_r5_5917 = this->unk160 * 0x17C;
                            *(temp_r6_5916 + temp_r5_5917) = *(temp_r6_5916 + temp_r5_5917) + 1;
                            var_r25_5901 = var_r25_5901->unkC->GetNextLine(var_r25_5901);
                            goto loop_67;
                        }
                    } else if (var_r29_5889->IsField("frags") != 0) {
                        temp_r3_5938 = var_r29_5889->unkC->GetSubLine(var_r29_5889);
                        var_r25_5940 = temp_r3_5938;
                        temp_r3_5938->GetFieldName();
                        if (strstr"*" != 0U) {
                            *(this->unk11C + ((this->unk160 * 0x17C) + 0x154)) = temp_r3_5938->GetFieldName();
                        }
                        if ((u32) *(this->unk11C + ((this->unk160 * 0x17C) + 0x154)) == 0U) {
loop_75:
                            if (var_r25_5940 != NULL) {
                                temp_r0_5968 = this->unk160;
                                *(&unshatteredNames + 0xF00 + ((temp_r0_5968 << 7) + (*(this->unk11C + ((temp_r0_5968 * 0x17C) + 0xCC)) * 4))) = var_r25_5940->GetFieldName();
                                temp_r6_5979 = this->unk11C;
                                temp_r5_5981 = (this->unk160 * 0x17C) + 0xCC;
                                *(temp_r6_5979 + temp_r5_5981) = *(temp_r6_5979 + temp_r5_5981) + 1;
                                var_r25_5940 = var_r25_5940->unkC->GetNextLine(var_r25_5940);
                                goto loop_75;
                            }
                        }
                    } else if (var_r29_5889->IsField("remnants") != 0) {
                        var_r25_6004 = var_r29_5889->unkC->GetSubLine(var_r29_5889);
loop_80:
                        if (var_r25_6004 != NULL) {
                            temp_r0_6009 = this->unk160;
                            *(&unshatteredNames + 0xA00 + ((temp_r0_6009 << 7) + (*(this->unk11C + ((temp_r0_6009 * 0x17C) + 0x88)) * 4))) = var_r25_6004->GetFieldName();
                            temp_r6_6020 = this->unk11C;
                            temp_r5_6022 = (this->unk160 * 0x17C) + 0x88;
                            *(temp_r6_6020 + temp_r5_6022) = *(temp_r6_6020 + temp_r5_6022) + 1;
                            var_r25_6004 = var_r25_6004->unkC->GetNextLine(var_r25_6004);
                            goto loop_80;
                        }
                    } else if (var_r29_5889->IsField("collision") != 0) {
                        if ((s16) var_r29_5889->unk0 > 0) {
                            temp_r0_6047 = this->unk160;
                            *(&unshatteredNames + 0x1400 + ((temp_r0_6047 << 7) + (*(this->unk11C + ((temp_r0_6047 * 0x17C) + 0x110)) * 4))) = var_r29_5889->GetString(0);
                            temp_r5_6058 = this->unk11C;
                            temp_r4_6060 = (this->unk160 * 0x17C) + 0x110;
                            *(temp_r5_6058 + temp_r4_6060) = *(temp_r5_6058 + temp_r4_6060) + 1;
                        } else {
                            var_r25_6070 = var_r29_5889->unkC->GetSubLine(var_r29_5889);
loop_87:
                            if (var_r25_6070 != NULL) {
                                temp_r0_6075 = this->unk160;
                                *(&unshatteredNames + 0x1400 + ((temp_r0_6075 << 7) + (*(this->unk11C + ((temp_r0_6075 * 0x17C) + 0x110)) * 4))) = var_r25_6070->GetFieldName();
                                temp_r6_6086 = this->unk11C;
                                temp_r5_6088 = (this->unk160 * 0x17C) + 0x110;
                                *(temp_r6_6086 + temp_r5_6088) = *(temp_r6_6086 + temp_r5_6088) + 1;
                                var_r25_6070 = var_r25_6070->unkC->GetNextLine(var_r25_6070);
                                goto loop_87;
                            }
                        }
                    } else if (var_r29_5889->IsField("destructible") != 0) {
                        *(this->unk11C + ((this->unk160 * 0x17C) + 0x178)) = var_r29_5889->GetBool(0);
                    } else if (var_r29_5889->IsField("shatterScript") != 0) {
                        *(this->unk11C + ((this->unk160 * 0x17C) + 0x158)) = var_r29_5889->GetString(0);
                    } else if (var_r29_5889->IsField("hitable") != 0) {
                        *(this->unk11C + ((this->unk160 * 0x17C) + 0x179)) = var_r29_5889->GetBool(0);
                    } else {
                        var_r26_6158 = 0;
                        temp_r25_6159 = this->unk11C + (this->unk160 * 0x17C);
                        if ((var_r29_5889->LoadFloat("upVel", temp_r25_6159 + 0x15C, 0) != 0) || (var_r29_5889->LoadFloat("power", temp_r25_6159 + 0x160, 0) != 0) || (var_r29_5889->LoadFloat("bounce", temp_r25_6159 + 0x164, 0) != 0) || (var_r29_5889->LoadFloat("gravity", temp_r25_6159 + 0x168, 0) != 0) || (var_r29_5889->LoadFloat("life", temp_r25_6159 + 0x16C, 0) != 0) || (var_r29_5889->LoadFloat("airResistance", temp_r25_6159 + 0x170, 0) != 0)) {
                            var_r26_6158 = 1;
                        }
                        if (var_r26_6158 == 0) {
                            var_r29_5889->LoadFloat("spinRate", temp_r25_6159 + 0x174, 0);
                        }
                    }
                    var_r29_5889 = var_r29_5889->unkC->GetNextLine(var_r29_5889);
                    goto loop_105;
                }
                this->unk160 += 1;
                var_r30_5882 = var_r30_5882->unkC->GetNextLine(var_r30_5882);
                goto loop_107;
            }
            return 1;
        }
block_109:
        if (arg0->IsField("HitFX") != 0) {
            arg0->AsString(0, &spC);
            this->unk168 = DataMap_GetValue(&ShatterableHitFXDataMap, spC);
        }
        return 0;
    }
    goto loop_30;
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void ShatterableDescriptor::Deinit() {
    MKHeap *temp_r3_6280;
    void *temp_r31_6277;

    temp_r31_6277 = this->unk11C;
    if (temp_r31_6277 != NULL) {
        temp_r3_6280 = MKHeap::Current();
        if (temp_r3_6280 != NULL) {
            ((MKHeap *) (temp_r3_6280->Current()))->Free(temp_r31_6277, NULL, 0);
        } else {
            free(temp_r31_6277);
        }
        this->unk11C = NULL;
    }
    KDPropExDescriptor::Deinit();
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void ShatterableDescriptor::Init() {
    s32 temp_r0_6383;
    s32 var_ctr_6381;
    s32 var_r3_6331;

    GamePropDescriptor::Init();
    memset(&this->unk118, 0, 4U);
    this->unkF4 = 0;
    this->unkF8 = 0;
    this->unkF0 = 1.0f;
    var_r3_6331 = 0;
    this->unkE4 = "idle";
    this->unkE8 = NULL;
    this->unk118 &= ~0x80;
    this->unk118 &= ~0x20;
    this->unk118 &= ~0x10;
    this->unk118 |= 4;
    this->unk118 |= 8;
    this->unk118 |= 2;
    this->unk118 |= 1;
    this->unkFC = 0;
    this->unk100 = 0;
    this->unk10C = GS_GemSpawn2;
    this->unk108 = 0;
    this->unk104 = GS_PLACEHOLDER;
    this->unk110 = NULL;
    this->unk12C = 0;
    this->unkC = 0x202;
    this->unk11C = NULL;
    this->unk160 = 1;
    this->unk15C = GS_PLACEHOLDER;
    this->unkC |= 0x80;
    this->unk164 &= ~0x40;
    this->unk14C = 0.65f;
    this->unk150 = 0.8f;
    this->unk154 = 0.15f;
    this->unk166 = 0;
    this->unk158 = 0;
    var_ctr_6381 = 3;
    do {
        temp_r0_6383 = var_r3_6331 + 0x120;
        var_r3_6331 += 4;
        *(this + temp_r0_6383) = 0;
        var_ctr_6381 -= 1;
    } while (var_ctr_6381 != 0);
    this->unk165 = 0;
    this->unk168 = 0;
    this->unk114 = 0;
    this->unk115 = 1;
}
#endif

#if 0 // DRAFT: identifier 'property_cast<...>(T1)' redeclared
KDScriptProperty *property_cast<KDScriptProperty *, KDProperty *>(KDProperty *arg0) {
    KDScriptProperty *sp8;

    sp8 = NULL;
    property_cast_ptr<KDScriptProperty, KDProperty>(sp8, arg0);
    return sp8;
}
#endif

#if 0 // DRAFT: identifier 'property_cast_ptr<...>(T0 *&, T1 *)' redeclared
void property_cast_ptr<KDScriptProperty, KDProperty>(KDScriptProperty *&arg0, KDProperty *arg1) {
    if ((arg1 != NULL) && (arg1->IsOfType((KDPropertyClassInfo *) &classInfo) != 0)) {
        &arg0 = checked_cast<KDScriptProperty *, KDProperty>(arg1);
    }
}
#endif

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<KDScriptProperty *, KDProperty>(KDProperty *arg0) {

}
#endif

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<GetTargetableMsg *, MKMessage>(MKMessage *arg0) {

}
#endif

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<GetNumHitsToDestroyMsg *, MKMessage>(MKMessage *arg0) {

}
#endif

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<ShatterExtendedMsg *, MKMessage>(MKMessage *arg0) {

}
#endif

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<BreathHitMessage *, MKMessage>(MKMessage *arg0) {

}
#endif

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<CanHeroHurtYouMsg *, MKMessage>(MKMessage *arg0) {

}
#endif

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<ShatterOnCollisionMsg *, MKMessage>(MKMessage *arg0) {

}
#endif

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<MeleeAttackHitMsg *, MKMessage>(MKMessage *arg0) {

}
#endif

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<ExplodeMsg *, MKMessage>(MKMessage *arg0) {

}
#endif

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<FXBase *, MKProp>(MKProp *arg0) {

}
#endif
