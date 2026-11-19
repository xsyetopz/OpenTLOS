#include "common/Source/MKDynamicBone.h"
#include "common/Source/Animation.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "common/Source/MKSystem.h"
#include <m2c_macros.h>

#if 0 // DRAFT: identifier 'gDynamicBones' redeclared
f64 atan2(f32, f32, f32, f32, f32);                 /* extern */
M2C_UNK free(MKDynamicBone **);                     /* extern */
MKDynamicBone **malloc(s32);                        /* extern */
extern void **gDynamicBones;
#endif
extern M2C_UNK gEmptyPtrListDL;
extern MKHeap gMKDefaults;
extern f32 gUpdateTimeDelta;
extern MKDynamicBone **spareTemplates;
#if 0 // DRAFT: identifier 'gDynamicBoneEnable' redeclared
static u32 gDynamicBoneEnable = 1U;
#endif

void MKDynamicBone::DefaultUpdater(MKDynamicBone *arg0, void *arg1) {
    Update();
}

#if 0 // DRAFT: undefined identifier 'unk74'
void MKDynamicBone::Reset() {
    Animation *temp_r3_49;
    Matrix *temp_r30_34;
    f32 temp_f31_37;
    s16 temp_r29_36;
    s32 temp_r31_47;
    u16 temp_r28_38;
    u32 temp_r0_62;
    temp_r30_34 = this->unk20;
    temp_r29_36 = M2C_FIELD(temp_r30_34, s16 *, 0x70);
    temp_f31_37 = temp_r30_34->unk74;
    temp_r28_38 = M2C_FIELD(temp_r30_34, u16 *, 0x72);
    ((Animation *) (MKModel_GetAnimation(this->unk24)))->SetCustomMatrix((s32) temp_r29_36, NULL, (AnimationMatrixPosition) 2, 0U);
    temp_r31_47 = MKModel_GetWorldMatrix(this->unk24);
    temp_r3_49 = MKModel_GetAnimation(this->unk24);
    arg_sp10 = temp_r29_36;
    temp_r3_49->CalculateMatrices((Matrix *) &arg_spE0, 1, &arg_sp10, (Matrix *) temp_r31_47);
    arg_spE0.Multiply(temp_r30_34, (Matrix *) &arg_spE0);
    temp_r0_62 = temp_r28_38 & 0x1E;
    arg_spC8 = M2C_FIELD(&zero, f64 *, 0);
    arg_spD0 = M2C_FIELD(&zero, f64 *, 8);
    switch (temp_r0_62) {
    case 2:
        arg_spC8 = arg_spE0;
        arg_spD0 = arg_spE8;
        break;
    case 4:
        arg_spC8 = arg_spF0;
        arg_spD0 = arg_spF8;
        break;
    case 8:
        arg_spC8 = arg_sp100;
        arg_spD0 = arg_sp108;
        break;
    case 18:
        arg_sp58 = -(f32) arg_spE0;
        arg_sp5C = -arg_spE4;
        arg_sp60 = -(f32) arg_spE8;
        arg_spB8 = (f64) arg_sp58;
        arg_spC0 = (f64) arg_sp60;
        arg_spC8 = (f64) arg_sp58;
        arg_spD0 = (f64) arg_sp60;
        break;
    case 20:
        arg_sp48 = -(f32) arg_spF0;
        arg_sp4C = -arg_spF4;
        arg_sp50 = -(f32) arg_spF8;
        arg_spA8 = (f64) arg_sp48;
        arg_spB0 = (f64) arg_sp50;
        arg_spC8 = (f64) arg_sp48;
        arg_spD0 = (f64) arg_sp50;
        break;
    case 24:
        arg_sp38 = -(f32) arg_sp100;
        arg_sp3C = -arg_sp104;
        arg_sp40 = -(f32) arg_sp108;
        arg_sp98 = (f64) arg_sp38;
        arg_spA0 = (f64) arg_sp40;
        arg_spC8 = (f64) arg_sp38;
        arg_spD0 = (f64) arg_sp40;
        break;
    }
    Normalise(*((MKVector3 *) &arg_sp68));
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
    arg_sp78 = arg_sp28;
    arg_sp30 = arg_sp70 * temp_f31_37;
    arg_sp80 = (f64) arg_sp30;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    M2C_FIELD(this, f64 *, 0) = arg_sp18;
    arg_sp88 = arg_sp18;
    arg_sp20 = arg_sp118 + (f32) arg_sp80;
    M2C_FIELD(this, f64 *, 8) = (f64) arg_sp20;
    arg_sp90 = (f64) arg_sp20;
    M2C_FIELD(this, f64 *, 0x10) = (f64) M2C_FIELD(this, f64 *, 0);
    M2C_FIELD(this, f64 *, 0x18) = (f64) M2C_FIELD(this, f64 *, 8);
}
#endif

#if 0 // DRAFT: undefined identifier 'unk40'
void MKDynamicBone::Update() {
    Animation *temp_r3_236;
    Animation *temp_r3_254;
    Matrix *temp_r31_217;
    f32 *temp_r28_220;
    f32 temp_f0_1035;
    f32 temp_f0_507;
    f32 temp_f0_526;
    f32 temp_f0_847;
    f32 temp_f0_941;
    f32 temp_f1_1058;
    f32 temp_f1_468;
    f32 temp_f1_500;
    f32 temp_f1_870;
    f32 temp_f1_964;
    f32 temp_f22_404;
    f32 temp_f22_701;
    f32 temp_f23_224;
    f32 temp_f24_223;
    f32 temp_f25_222;
    f32 temp_f3_410;
    f32 temp_f3_698;
    f32 temp_f8_1005;
    f32 temp_f8_818;
    f32 temp_f8_911;
    f32 var_f28_479;
    f32 var_f28_631;
    f32 var_f29_444;
    f64 temp_f5_634;
    f64 temp_f5_640;
    f64 temp_f5_644;
    s16 temp_r29_219;
    s32 temp_r26_234;
    s32 temp_r26_252;
    s32 temp_r30_391;
    s32 temp_r3_663;
    s32 var_r0_673;
    s8 temp_r25_232;
    u16 temp_r30_221;
    u32 temp_r26_277;
    temp_r31_217 = this->unk20;
    temp_r29_219 = M2C_FIELD(temp_r31_217, s16 *, 0x70);
    temp_r28_220 = &temp_r31_217->unk40;
    temp_r30_221 = M2C_FIELD(temp_r31_217, u16 *, 0x72);
    temp_f25_222 = temp_r31_217->unk74;
    temp_f24_223 = temp_r31_217->unk7C;
    temp_f23_224 = temp_r31_217->unk78;
    temp_r25_232 = (s8) M2C_FIELD((M2C_FIELD(MKModel_GetAnimation(this->unk24)->unk0, s32 *, 0x28) + (temp_r29_219 << 5)), u8 *, 0x36);
    temp_r26_234 = MKModel_GetWorldMatrix(this->unk24);
    temp_r3_236 = MKModel_GetAnimation(this->unk24);
    arg_sp10 = (s16) temp_r25_232;
    temp_r3_236->CalculateMatrices((Matrix *) &arg_sp620, 1, &arg_sp10, (Matrix *) temp_r26_234);
    ((Animation *) (MKModel_GetAnimation(this->unk24)))->SetCustomMatrix((s32) temp_r29_219, NULL, (AnimationMatrixPosition) 2, 0U);
    temp_r26_252 = MKModel_GetWorldMatrix(this->unk24);
    temp_r3_254 = MKModel_GetAnimation(this->unk24);
    arg_sp10 = temp_r29_219;
    temp_r3_254->CalculateMatrices((Matrix *) &arg_sp660, 1, &arg_sp10, (Matrix *) temp_r26_252);
    M2C_STRUCT_COPY((s32) &arg_sp5DC + 4, (s32) &arg_sp65C + 4, 0x40);
    if (((u32) gDynamicBoneEnable != 0U) && ((u8) this->unk30 != 0)) {
        temp_r26_277 = temp_r30_221 & 0x1E;
        if (temp_r26_277 != 0) {
            arg_sp6A0.Multiply(temp_r31_217, (Matrix *) &arg_sp660);
            arg_sp588 = arg_sp6D0;
            arg_sp590 = arg_sp6D8;
            arg_sp558 = M2C_FIELD(&zero, f64 *, 0);
            arg_sp560 = M2C_FIELD(&zero, f64 *, 8);
            switch (temp_r26_277) {                 /* switch 1 */
            case 2:                                 /* switch 1 */
                arg_sp558 = arg_sp6A0;
                arg_sp560 = arg_sp6A8;
                break;
            case 4:                                 /* switch 1 */
                arg_sp558 = arg_sp6B0;
                arg_sp560 = arg_sp6B8;
                break;
            case 8:                                 /* switch 1 */
                arg_sp558 = arg_sp6C0;
                arg_sp560 = arg_sp6C8;
                break;
            case 18:                                /* switch 1 */
                arg_sp1C8 = -(f32) arg_sp6A0;
                arg_sp1CC = -arg_sp6A4;
                arg_sp1D0 = -(f32) arg_sp6A8;
                arg_sp4F8 = (f64) arg_sp1C8;
                arg_sp500 = (f64) arg_sp1D0;
                arg_sp558 = (f64) arg_sp1C8;
                arg_sp560 = (f64) arg_sp1D0;
                break;
            case 20:                                /* switch 1 */
                arg_sp1B8 = -(f32) arg_sp6B0;
                arg_sp1BC = -arg_sp6B4;
                arg_sp1C0 = -(f32) arg_sp6B8;
                arg_sp4E8 = (f64) arg_sp1B8;
                arg_sp4F0 = (f64) arg_sp1C0;
                arg_sp558 = (f64) arg_sp1B8;
                arg_sp560 = (f64) arg_sp1C0;
                break;
            case 24:                                /* switch 1 */
                arg_sp1A8 = -(f32) arg_sp6C0;
                arg_sp1AC = -arg_sp6C4;
                arg_sp1B0 = -(f32) arg_sp6C8;
                arg_sp4D8 = (f64) arg_sp1A8;
                arg_sp4E0 = (f64) arg_sp1B0;
                arg_sp558 = (f64) arg_sp1A8;
                arg_sp560 = (f64) arg_sp1B0;
                break;
            }
            Normalise(*((MKVector3 *) &arg_sp4A8));
            arg_sp4B8.operator*(temp_f25_222);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            arg_sp4C8 = arg_sp198;
            arg_sp1A0 = (f32) arg_sp590 + arg_sp4C0;
            arg_sp5A8 = arg_sp198;
            arg_sp4D0 = (f64) arg_sp1A0;
            arg_sp5B0 = (f64) arg_sp1A0;
        }
        temp_r30_391 = temp_r30_221 & 0xE0;
        if (temp_r30_391 != 0) {
            arg_sp6A0.Multiply(temp_r31_217, (Matrix *) &arg_sp660);
            arg_sp5A8 = arg_sp6D0;
            arg_sp5B0 = arg_sp6D8;
        }
        temp_f22_404 = 1.0f / gUpdateTimeDelta;
        M2C_ERROR(/* unknown instruction: psq_lx $f2, $zero, $r27, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $r27, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f2, $f0 */);
        temp_f3_410 = this->unk8;
        arg_sp488 = arg_sp38;
        arg_sp40 = temp_f3_410 - this->unk18;
        arg_sp490 = (f64) arg_sp40;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f22 */);
        arg_sp498 = arg_sp188;
        arg_sp190 = (f32) arg_sp490 * temp_f22_404;
        arg_sp5C8 = arg_sp188;
        arg_sp4A0 = (f64) arg_sp190;
        arg_sp5D0 = (f64) arg_sp190;
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f0, $f2 */);
        arg_sp478 = arg_sp178;
        arg_sp180 = (f32) arg_sp5B0 - temp_f3_410;
        arg_sp598 = arg_sp178;
        arg_sp480 = (f64) arg_sp180;
        arg_sp5A0 = (f64) arg_sp180;
        if (temp_f24_223 < temp_f22_404) {
            var_f29_444 = temp_f24_223;
        } else {
            var_f29_444 = temp_f22_404;
        }
        arg_sp28 = -(f32) arg_sp5C8;
        arg_sp2C = -arg_sp5CC;
        arg_sp30 = -(f32) arg_sp5D0;
        arg_sp458 = (f64) arg_sp28;
        arg_sp460 = (f64) arg_sp30;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
        temp_f1_468 = 1.0f / (gUpdateTimeDelta * gUpdateTimeDelta);
        arg_sp468 = arg_sp168;
        arg_sp5B8 = arg_sp168;
        arg_sp170 = (f32) arg_sp460 * var_f29_444;
        arg_sp470 = (f64) arg_sp170;
        arg_sp5C0 = (f64) arg_sp170;
        if (temp_f23_224 < temp_f1_468) {
            var_f28_479 = temp_f23_224;
        } else {
            var_f28_479 = temp_f1_468;
        }
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f28 */);
        arg_sp448 = arg_sp158;
        arg_sp160 = (f32) arg_sp5A0 * var_f28_479;
        arg_sp450 = (f64) arg_sp160;
        M2C_ERROR(/* unknown instruction: ps_add $f2, $f1, $f0 */);
        temp_f1_500 = (f32) arg_sp5C0 + (f32) arg_sp450;
        arg_sp5C0 = temp_f1_500;
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r28, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f2, $f0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f2, $f0, $f27 */);
        temp_f0_507 = temp_f1_500 + M2C_FIELD(temp_r28_220, f32 *, 8);
        arg_sp5C0 = temp_f0_507;
        arg_sp150 = temp_f0_507 * gUpdateTimeDelta;
        arg_sp438 = arg_sp148;
        arg_sp440 = (f64) arg_sp150;
        M2C_ERROR(/* unknown instruction: ps_add $f3, $f1, $f0 */);
        M2C_FIELD(this, f64 *, 0x10) = (f64) M2C_FIELD(this, f64 *, 0);
        M2C_FIELD(this, f32 *, 0x18) = (f64) M2C_FIELD(this, f32 *, 8);
        temp_f0_526 = (f32) arg_sp5D0 + (f32) arg_sp440;
        arg_sp5D0 = temp_f0_526;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f1, $f3, $f31 */);
        arg_sp140 = temp_f0_526 * gUpdateTimeDelta;
        arg_sp428 = arg_sp138;
        arg_sp430 = (f64) arg_sp140;
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r27, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        M2C_ERROR(/* unknown instruction: psq_stx $f0, $zero, $r27, 0x0, qr0 */);
        this->unk8 += (f32) arg_sp430;
        if ((s32) temp_r26_277 != 0) {
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r27, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
            arg_sp3E8 = arg_sp18;
            arg_sp20 = this->unk8 - (f32) arg_sp590;
            arg_sp3F0 = (f64) arg_sp20;
            Normalise(*((MKVector3 *) &arg_sp3F8));
            arg_sp408.operator*(temp_f25_222);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f2, $f0 */);
            M2C_FIELD(this, f64 *, 0) = arg_sp128;
            arg_sp130 = (f32) arg_sp590 + arg_sp410;
            arg_sp418 = arg_sp128;
            M2C_FIELD(this, f32 *, 8) = (f64) arg_sp130;
            arg_sp420 = (f64) arg_sp130;
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r27, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f0, $f2 */);
            arg_sp3D8 = arg_sp118;
            arg_sp120 = this->unk8 - (f32) arg_sp590;
            arg_sp578 = arg_sp118;
            arg_sp3E0 = (f64) arg_sp120;
            arg_sp580 = (f64) arg_sp120;
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f0, $f2 */);
            arg_sp110 = (f32) arg_sp5B0 - (f32) arg_sp590;
            arg_sp568 = arg_sp108;
            arg_sp570 = (f64) arg_sp110;
            arg_sp3C8 = arg_sp108;
            arg_sp3D0 = (f64) arg_sp110;
            arg_spF8 = (arg_sp56C * (f32) arg_sp580) - ((f32) arg_sp570 * arg_sp57C);
            arg_spFC = ((f32) arg_sp570 * (f32) arg_sp578) - ((f32) arg_sp568 * (f32) arg_sp580);
            arg_sp100 = ((f32) arg_sp568 * arg_sp57C) - (arg_sp56C * (f32) arg_sp578);
            arg_sp548 = (f64) arg_spF8;
            arg_sp550 = (f64) arg_sp100;
            arg_sp3B8 = (f64) arg_spF8;
            arg_sp3C0 = (f64) arg_sp100;
            var_f28_631 = ((f32) arg_sp550 * (f32) arg_sp550) + (((f32) arg_sp548 * (f32) arg_sp548) + (arg_sp54C * arg_sp54C));
            if (var_f28_631 > 0.0f) {
                temp_f5_634 = __frsqrte(var_f28_631);
                temp_f5_640 = 0.5 * temp_f5_634 * -(((f64) var_f28_631 * (temp_f5_634 * temp_f5_634)) - 3.0);
                temp_f5_644 = 0.5 * temp_f5_640 * -(((f64) var_f28_631 * (temp_f5_640 * temp_f5_640)) - 3.0);
                var_f28_631 = (f32) ((f64) var_f28_631 * (0.5 * temp_f5_644 * -(((f64) var_f28_631 * (temp_f5_644 * temp_f5_644)) - 3.0)));
            } else if (var_f28_631 < M2C_BITWISE(f32, 0.0)) {
                var_f28_631 = __float_nan;
            } else {
                arg_sp14 = var_f28_631;
                temp_r3_663 = M2C_BITWISE(s32, arg_sp14) & 0x7F800000;
                switch (temp_r3_663) {              /* switch 2; irregular */
                case 0x7F800000:                    /* switch 2 */
                    if (M2C_BITWISE(s32, arg_sp14) & 0x7FFFFF) {
                        var_r0_673 = 1;
                    } else {
                        var_r0_673 = 2;
                    }
                    break;
                case 0x0:                           /* switch 2 */
                    if (M2C_BITWISE(s32, arg_sp14) & 0x7FFFFF) {
                        var_r0_673 = 5;
                    } else {
                        var_r0_673 = 3;
                    }
                    break;
                default:                            /* switch 2 */
                    var_r0_673 = 4;
                    break;
                }
                if (var_r0_673 == 1) {
                    var_f28_631 = __float_nan;
                }
            }
            temp_f3_698 = ((f32) arg_sp578 * (f32) arg_sp568) + (arg_sp57C * arg_sp56C);
            temp_f22_701 = (f32) atan2(var_f28_631, ((f32) arg_sp580 * (f32) arg_sp570) + temp_f3_698, temp_f3_698, (f32) arg_sp568, (f32) arg_sp578);
            if (temp_f22_701 != 0.0f) {
                arg_sp6A0.SetIdentity();
                if (var_f28_631 > 0.0001f) {
                    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
                    arg_sp220 = (f32) arg_sp550 * (1.0f / var_f28_631);
                    arg_sp3A8 = arg_sp218;
                    arg_sp3B0 = (f64) arg_sp220;
                    arg_sp6A0.SetRotateAroundAxis(*((MKVector3 *) &arg_sp3A8), temp_f22_701);
                }
                arg_sp388.GetNodeOrigin(MKModel_GetAnimation(this->unk24));
                arg_spE8 = arg_sp690 + ((arg_sp390 * arg_sp680) + ((arg_sp388 * arg_sp660) + (arg_sp38C * arg_sp670)));
                arg_spEC = arg_sp694 + ((arg_sp390 * arg_sp684) + ((arg_sp388 * arg_sp664) + (arg_sp38C * arg_sp674)));
                arg_spF0 = arg_sp698 + ((arg_sp390 * arg_sp688) + ((arg_sp388 * arg_sp668) + (arg_sp38C * arg_sp678)));
                arg_sp538 = (f64) arg_spE8;
                arg_sp540 = (f64) arg_spF0;
                arg_sp398 = (f64) arg_spE8;
                arg_spD8 = -(f32) arg_sp538;
                arg_spDC = -arg_sp53C;
                arg_spE0 = -(f32) arg_sp540;
                arg_sp3A0 = (f64) arg_spF0;
                arg_sp378 = (f64) arg_spD8;
                arg_sp380 = (f64) arg_spE0;
                arg_sp5E0.Translate((Matrix *) &arg_sp5E0, *((MKVector3 *) &arg_sp378));
                arg_sp5E0.Multiply((Matrix *) &arg_sp5E0, (Matrix *) &arg_sp6A0);
                arg_sp5E0.Translate((Matrix *) &arg_sp5E0, *((MKVector3 *) &arg_sp538));
            }
        }
        if (temp_r30_391 != 0) {
            Normalise(*((MKVector3 *) &arg_sp368));
            arg_sp518 = arg_sp368;
            arg_sp520 = arg_sp370;
            arg_spC8 = (f32) arg_sp518;
            arg_spCC = arg_sp51C;
            temp_f8_818 = M2C_BITWISE(f32, temp_r31_217->unk60);
            arg_sp208 = this->unk0;
            arg_sp528 = (f64) arg_spC8;
            arg_sp20C = this->unk4;
            arg_spD0 = (f32) arg_sp520;
            arg_sp348 = (f64) arg_sp208;
            arg_spD4 = -(((f32) arg_sp5B0 * (f32) arg_sp520) + (((f32) arg_sp5A8 * (f32) arg_sp518) + (arg_sp5AC * arg_sp51C)));
            arg_sp210 = this->unk8;
            arg_sp530 = (f64) arg_spD0;
            arg_sp214 = 1.0f;
            arg_sp350 = (f64) arg_sp210;
            arg_sp358 = (f64) arg_spC8;
            arg_sp360 = (f64) arg_spD0;
            temp_f0_847 = (arg_sp534 * arg_sp354) + (((f32) arg_sp530 * (f32) arg_sp350) + (((f32) arg_sp528 * (f32) arg_sp348) + (arg_sp52C * arg_sp34C)));
            if (temp_f0_847 > temp_f8_818) {
                arg_sp328.operator*(temp_f8_818 - temp_f0_847);
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r27, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                M2C_FIELD(this, f64 *, 0) = arg_spB8;
                arg_spC0 = this->unk8 + arg_sp330;
                arg_sp338 = arg_spB8;
                arg_sp340 = (f64) arg_spC0;
                M2C_FIELD(this, f32 *, 8) = (f64) arg_spC0;
            } else {
                temp_f1_870 = temp_r31_217->unk50;
                if (temp_f0_847 < temp_f1_870) {
                    arg_sp308.operator*(temp_f1_870 - temp_f0_847);
                    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r27, 0x0, qr0 */);
                    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                    M2C_FIELD(this, f64 *, 0) = arg_spA8;
                    arg_spB0 = this->unk8 + arg_sp310;
                    arg_sp318 = arg_spA8;
                    arg_sp320 = (f64) arg_spB0;
                    M2C_FIELD(this, f32 *, 8) = (f64) arg_spB0;
                }
            }
            Normalise(*((MKVector3 *) &arg_sp2F8));
            arg_sp518 = arg_sp2F8;
            arg_sp520 = arg_sp300;
            arg_sp98 = (f32) arg_sp518;
            temp_f8_911 = temp_r31_217->unk64;
            arg_sp9C = arg_sp51C;
            arg_sp1F8 = this->unk0;
            arg_sp528 = (f64) arg_sp98;
            arg_sp1FC = this->unk4;
            arg_spA0 = (f32) arg_sp520;
            arg_sp2D8 = (f64) arg_sp1F8;
            arg_spA4 = -(((f32) arg_sp5B0 * (f32) arg_sp520) + (((f32) arg_sp5A8 * (f32) arg_sp518) + (arg_sp5AC * arg_sp51C)));
            arg_sp200 = this->unk8;
            arg_sp530 = (f64) arg_spA0;
            arg_sp204 = 1.0f;
            arg_sp2E0 = (f64) arg_sp200;
            arg_sp2E8 = (f64) arg_sp98;
            arg_sp2F0 = (f64) arg_spA0;
            temp_f0_941 = (arg_sp534 * arg_sp2E4) + (((f32) arg_sp530 * (f32) arg_sp2E0) + (((f32) arg_sp528 * (f32) arg_sp2D8) + (arg_sp52C * arg_sp2DC)));
            if (temp_f0_941 > temp_f8_911) {
                arg_sp2B8.operator*(temp_f8_911 - temp_f0_941);
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r27, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                M2C_FIELD(this, f64 *, 0) = arg_sp88;
                arg_sp90 = this->unk8 + arg_sp2C0;
                arg_sp2C8 = arg_sp88;
                arg_sp2D0 = (f64) arg_sp90;
                M2C_FIELD(this, f32 *, 8) = (f64) arg_sp90;
            } else {
                temp_f1_964 = temp_r31_217->unk54;
                if (temp_f0_941 < temp_f1_964) {
                    arg_sp298.operator*(temp_f1_964 - temp_f0_941);
                    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r27, 0x0, qr0 */);
                    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                    M2C_FIELD(this, f64 *, 0) = arg_sp78;
                    arg_sp80 = this->unk8 + arg_sp2A0;
                    arg_sp2A8 = arg_sp78;
                    arg_sp2B0 = (f64) arg_sp80;
                    M2C_FIELD(this, f32 *, 8) = (f64) arg_sp80;
                }
            }
            Normalise(*((MKVector3 *) &arg_sp288));
            arg_sp518 = arg_sp288;
            arg_sp520 = arg_sp290;
            arg_sp68 = (f32) arg_sp518;
            temp_f8_1005 = temp_r31_217->unk68;
            arg_sp6C = arg_sp51C;
            arg_sp1E8 = this->unk0;
            arg_sp528 = (f64) arg_sp68;
            arg_sp1EC = this->unk4;
            arg_sp70 = (f32) arg_sp520;
            arg_sp268 = (f64) arg_sp1E8;
            arg_sp74 = -(((f32) arg_sp5B0 * (f32) arg_sp520) + (((f32) arg_sp5A8 * (f32) arg_sp518) + (arg_sp5AC * arg_sp51C)));
            arg_sp1F0 = this->unk8;
            arg_sp530 = (f64) arg_sp70;
            arg_sp1F4 = 1.0f;
            arg_sp270 = (f64) arg_sp1F0;
            arg_sp278 = (f64) arg_sp68;
            arg_sp280 = (f64) arg_sp70;
            temp_f0_1035 = (arg_sp534 * arg_sp274) + (((f32) arg_sp530 * (f32) arg_sp270) + (((f32) arg_sp528 * (f32) arg_sp268) + (arg_sp52C * arg_sp26C)));
            if (temp_f0_1035 > temp_f8_1005) {
                arg_sp248.operator*(temp_f8_1005 - temp_f0_1035);
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r27, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                M2C_FIELD(this, f64 *, 0) = arg_sp58;
                arg_sp60 = this->unk8 + arg_sp250;
                arg_sp258 = arg_sp58;
                arg_sp260 = (f64) arg_sp60;
                M2C_FIELD(this, f32 *, 8) = (f64) arg_sp60;
            } else {
                temp_f1_1058 = temp_r31_217->unk58;
                if (temp_f0_1035 < temp_f1_1058) {
                    arg_sp228.operator*(temp_f1_1058 - temp_f0_1035);
                    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r27, 0x0, qr0 */);
                    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                    M2C_FIELD(this, f64 *, 0) = arg_sp48;
                    arg_sp50 = this->unk8 + arg_sp230;
                    arg_sp238 = arg_sp48;
                    arg_sp240 = (f64) arg_sp50;
                    M2C_FIELD(this, f32 *, 8) = (f64) arg_sp50;
                }
            }
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r27, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
            arg_sp508 = arg_sp1D8;
            arg_sp1E0 = this->unk8 - (f32) arg_sp5B0;
            arg_sp510 = (f64) arg_sp1E0;
            arg_sp5E0.Translate((Matrix *) &arg_sp5E0, *((MKVector3 *) &arg_sp508));
        }
    }
    arg_sp620.Inverse((Matrix *) &arg_sp620);
    arg_sp5E0.Multiply((Matrix *) &arg_sp5E0, (Matrix *) &arg_sp620);
    ((Animation *) (MKModel_GetAnimation(this->unk24)))->SetCustomMatrix((s32) temp_r29_219, (Matrix *) &arg_sp5E0, (AnimationMatrixPosition) 4, 0U);
}
#endif

void MKDynamicBoneSystem::ResetModel(MKModel *arg0) {
    MKDynamicBone **var_r31_1146;
    MKDynamicBone *temp_r3_1161;

    var_r31_1146 = this->unk0;
loop_5:
    temp_r3_1161 = *var_r31_1146;
    if (temp_r3_1161 != NULL) {
        if (((MKModel *) temp_r3_1161->unk24 == arg0) && (MKModel_GetAnimation(arg0) != NULL)) {
            ((MKDynamicBone *) (*var_r31_1146))->Reset();
        }
        var_r31_1146 += 4;
        goto loop_5;
    }
}

#if 0 // DRAFT: undefined identifier 'unk2C'
void MKDynamicBoneSystem::Update() {
    MKDynamicBone **var_r31_1181;
    MKDynamicBone *temp_r3_1188;
    MKDynamicBone *temp_r3_1196;

    if ((u8) this->unk4 == 0) {
        var_r31_1181 = this->unk0;
loop_5:
        temp_r3_1196 = *var_r31_1181;
        if (temp_r3_1196 != NULL) {
            if (MKModel_GetAnimation(temp_r3_1196->unk24) != NULL) {
                temp_r3_1188 = *var_r31_1181;
                temp_r3_1188->unk2C(temp_r3_1188, (MKDynamicBone *) temp_r3_1188->unk28, M2C_ERROR(/* Read from unset register $r5 */));
            }
            var_r31_1181 += 4;
            goto loop_5;
        }
    }
}
#endif

void MKDynamicBoneSystem::Enable(MKModel *arg0, bool arg1) {
    MKDynamicBone **var_r6_1210;
    MKDynamicBone *temp_r3_1220;

    var_r6_1210 = this->unk0;
loop_4:
    temp_r3_1220 = *var_r6_1210;
    if (temp_r3_1220 != NULL) {
        if ((MKModel *) temp_r3_1220->unk24 == arg0) {
            temp_r3_1220->unk30 = arg1;
        }
        var_r6_1210 += 4;
        goto loop_4;
    }
}

#if 0 // DRAFT: type mismatch
void MKDynamicBoneSystem::RemoveModel(MKModel *arg0) {
    MKDynamicBone **temp_r5_1255;
    MKDynamicBone **temp_r5_1263;
    MKDynamicBone **var_r6_1239;
    MKDynamicBone **var_r8_1229;
    MKDynamicBone *temp_r0_1248;
    MKDynamicBone *temp_r5_1273;
    MKDynamicBone *temp_r6_1266;
    MKDynamicBone *temp_r7_1258;
    Matrix *temp_r5_1235;

    var_r8_1229 = this->unk0;
loop_13:
    temp_r5_1273 = *var_r8_1229;
    if (temp_r5_1273 != NULL) {
        if ((MKModel *) temp_r5_1273->unk24 == arg0) {
            temp_r5_1235 = temp_r5_1273->unk20;
            if (M2C_FIELD(temp_r5_1235, u16 *, 0x72) & 0x100) {
                var_r6_1239 = spareTemplates;
loop_7:
                temp_r0_1248 = *var_r6_1239;
                if (temp_r0_1248 == NULL) {
                    var_r6_1239 = NULL;
                } else if (temp_r0_1248 == temp_r5_1235) {

                } else {
                    var_r6_1239 += 4;
                    goto loop_7;
                }
                if (var_r6_1239 != NULL) {
                    temp_r5_1255 = spareTemplates;
                    spareTemplates = temp_r5_1255 + 4;
                    temp_r7_1258 = *temp_r5_1255;
                    *temp_r5_1255 = *var_r6_1239;
                    *var_r6_1239 = temp_r7_1258;
                }
            }
            temp_r5_1263 = this->unk0;
            this->unk0 = temp_r5_1263 + 4;
            temp_r6_1266 = *temp_r5_1263;
            *temp_r5_1263 = *var_r8_1229;
            *var_r8_1229 = temp_r6_1266;
        }
        var_r8_1229 += 4;
        goto loop_13;
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long' to
void MKDynamicBoneSystem::AddModel(MKModel *arg0) {
    Animation *temp_r3_1311;
    MKDynamicBone **temp_r5_1330;
    MKDynamicBone *temp_r30_1332;
    f32 *temp_r22_1361;
    f32 *temp_r22_1402;
    s16 temp_r0_1293;
    s16 var_ctr_1294;
    s32 *temp_r22_1412;
    s32 temp_r28_1319;
    s32 var_r20_1345;
    s32 var_r21_1342;
    s32 var_r22_1346;
    s32 var_r23_1343;
    s32 var_r24_1323;
    s32 var_r27_1322;
    s32 var_r5_1291;
    u16 *var_r29_1299;
    void *temp_r3_1292;

    var_r5_1291 = 0;
    temp_r3_1292 = M2C_FIELD(arg0->unk0, void **, 0x30);
    temp_r0_1293 = M2C_FIELD(temp_r3_1292, s16 *, 0xC);
    var_ctr_1294 = temp_r0_1293;
    if (temp_r0_1293 > 0) {
loop_1:
        var_r29_1299 = M2C_FIELD(temp_r3_1292, s32 *, 0x60) + var_r5_1291;
        if ((u16) *var_r29_1299 == 7) {

        } else {
            var_r5_1291 += 0x10;
            var_ctr_1294 -= 1;
            if (var_ctr_1294 == 0) {
                goto block_4;
            }
            goto loop_1;
        }
    } else {
block_4:
        var_r29_1299 = NULL;
    }
    temp_r3_1311 = MKModel_GetAnimation(arg0);
    if ((var_r29_1299 != NULL) && (temp_r3_1311 != NULL)) {
        temp_r3_1311->EnableCustomMatrices(1U);
        temp_r28_1319 = M2C_FIELD(var_r29_1299, s32 *, 4);
        var_r27_1322 = 0;
        var_r24_1323 = 0;
loop_15:
        if (var_r27_1322 < (s32) M2C_FIELD(var_r29_1299, s32 *, 8)) {
            temp_r5_1330 = this->unk0 - 4;
            this->unk0 = temp_r5_1330;
            temp_r30_1332 = *temp_r5_1330;
            temp_r30_1332->unk24 = arg0;
            temp_r30_1332->unk20 = temp_r28_1319 + var_r24_1323;
            temp_r30_1332->unk2C = &MKDynamicBone::DefaultUpdater;
            temp_r30_1332->unk28 = NULL;
            temp_r30_1332->unk30 = 1;
            if (temp_r30_1332->unk20->unk3C != 1.0f) {
                var_r21_1342 = 0;
                var_r23_1343 = 0;
                do {
                    var_r20_1345 = 0;
                    var_r22_1346 = 0;
loop_11:
                    FlipEndian(temp_r30_1332->unk20 + (var_r23_1343 + var_r22_1346));
                    var_r20_1345 += 1;
                    var_r22_1346 += 4;
                    if (var_r20_1345 < 4) {
                        goto loop_11;
                    }
                    var_r21_1342 += 1;
                    var_r23_1343 += 0x10;
                } while (var_r21_1342 < 4);
                temp_r22_1361 = &temp_r30_1332->unk20->unk40;
                FlipEndian(temp_r22_1361);
                FlipEndian(temp_r22_1361 + 4);
                FlipEndian(temp_r22_1361 + 8);
                FlipEndian(temp_r22_1361 + 0xC);
                FlipEndian(&temp_r30_1332->unk0);
                FlipEndian(&temp_r30_1332->unk4);
                FlipEndian(&temp_r30_1332->unk8);
                FlipEndian(&temp_r30_1332->unkC);
                FlipEndian(&temp_r30_1332->unk10);
                FlipEndian(&temp_r30_1332->unk14);
                FlipEndian(&temp_r30_1332->unk18);
                FlipEndian(&temp_r30_1332->unk1C);
                FlipEndian((s16 *) &temp_r30_1332->unk20->unk70);
                FlipEndian(&temp_r30_1332->unk20->unk74);
                FlipEndian(&temp_r30_1332->unk20->unk78);
                FlipEndian(&temp_r30_1332->unk20->unk7C);
                FlipEndian(temp_r30_1332->unk20 + 0x72);
                temp_r22_1402 = &temp_r30_1332->unk20->unk50;
                FlipEndian(temp_r22_1402);
                FlipEndian(temp_r22_1402 + 4);
                FlipEndian(temp_r22_1402 + 8);
                FlipEndian(temp_r22_1402 + 0xC);
                temp_r22_1412 = &temp_r30_1332->unk20->unk60;
                FlipEndian((f32 *) temp_r22_1412);
                FlipEndian((f32 *) (temp_r22_1412 + 4));
                FlipEndian((f32 *) (temp_r22_1412 + 8));
                FlipEndian((f32 *) (temp_r22_1412 + 0xC));
            }
            temp_r30_1332->Reset();
            var_r27_1322 += 1;
            var_r24_1323 += 0x80;
            goto loop_15;
        }
    }
}
#endif

#if 0 // DRAFT: type mismatch
void MKDynamicBoneSystem::Deinit() {
    MKDynamicBone **var_r30_1449;
    MKDynamicBone **var_r30_1491;
    MKDynamicBone **var_r3_1450;
    MKDynamicBone **var_r3_1492;
    MKDynamicBone **var_r4_1448;
    MKDynamicBone **var_r4_1490;
    MKDynamicBone *temp_r0_1453;
    MKDynamicBone *temp_r0_1472;
    MKDynamicBone *temp_r0_1495;
    MKDynamicBone *temp_r0_1514;
    MKHeap *temp_r3_1475;
    MKHeap *temp_r3_1517;
    u32 temp_r0_1458;
    u32 temp_r0_1500;

    var_r4_1448 = spareTemplates;
    var_r30_1449 = var_r4_1448;
    var_r3_1450 = var_r4_1448;
loop_3:
    temp_r0_1458 = M2C_FIELD(var_r3_1450, u32 *, -4);
    var_r3_1450 -= 4;
    if (temp_r0_1458 != 0U) {
        temp_r0_1453 = *var_r3_1450;
        if (temp_r0_1453 < var_r30_1449) {
            var_r30_1449 = (MKDynamicBone **) temp_r0_1453;
        }
        goto loop_3;
    }
    if (var_r3_1450 != &gEmptyPtrListDL) {
loop_9:
        temp_r0_1472 = *var_r4_1448;
        if (temp_r0_1472 != NULL) {
            if (temp_r0_1472 < var_r30_1449) {
                var_r30_1449 = (MKDynamicBone **) temp_r0_1472;
            }
            var_r4_1448 += 4;
            goto loop_9;
        }
        temp_r3_1475 = var_r3_1450->Current();
        if (temp_r3_1475 != NULL) {
            ((MKHeap *) (temp_r3_1475->Current()))->Free(var_r30_1449, NULL, 0);
        } else {
            free(var_r30_1449);
        }
    }
    spareTemplates = NULL;
    var_r4_1490 = this->unk0;
    var_r30_1491 = var_r4_1490;
    var_r3_1492 = var_r4_1490;
loop_16:
    temp_r0_1500 = M2C_FIELD(var_r3_1492, u32 *, -4);
    var_r3_1492 -= 4;
    if (temp_r0_1500 != 0U) {
        temp_r0_1495 = *var_r3_1492;
        if (temp_r0_1495 < var_r30_1491) {
            var_r30_1491 = (MKDynamicBone **) temp_r0_1495;
        }
        goto loop_16;
    }
    if (var_r3_1492 != &gEmptyPtrListDL) {
loop_22:
        temp_r0_1514 = *var_r4_1490;
        if (temp_r0_1514 != NULL) {
            if (temp_r0_1514 < var_r30_1491) {
                var_r30_1491 = (MKDynamicBone **) temp_r0_1514;
            }
            var_r4_1490 += 4;
            goto loop_22;
        }
        temp_r3_1517 = var_r3_1492->Current();
        if (temp_r3_1517 != NULL) {
            ((MKHeap *) (temp_r3_1517->Current()))->Free(var_r30_1491, NULL, 0);
        } else {
            free(var_r30_1491);
        }
    }
    this->unk0 = NULL;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long *' to
void MKDynamicBoneSystem::Init() {
    MKDynamicBone **temp_r3_1580;
    MKDynamicBone **temp_r3_1587;
    MKDynamicBone **temp_r3_1594;
    MKDynamicBone **temp_r4_1631;
    MKDynamicBone **var_r3_1567;
    MKDynamicBone **var_r3_1620;
    MKDynamicBone **var_r5_1579;
    MKHeap *temp_r3_1557;
    MKHeap *temp_r3_1610;
    MKModel *temp_r30_1549;
    MKModel *var_ctr_1583;
    s32 temp_r30_1602;
    s32 var_ctr_1635;

    temp_r30_1549 = gMKDefaults.unk9C;
    if (temp_r30_1549 == NULL) {
        this->unk0 = &gEmptyPtrListDL + 4;
    } else {
        temp_r3_1557 = gMKDefaults.Current();
        if (temp_r3_1557 != NULL) {
            var_r3_1567 = ((MKHeap *) (temp_r3_1557->Current()))->Alloc(((s32) (temp_r30_1549 + 2) * 4) + ((s32) temp_r30_1549 * 0x38), NULL, 0);
        } else {
            var_r3_1567 = malloc(((s32) (temp_r30_1549 + 2) * 4) + ((s32) temp_r30_1549 * 0x38));
        }
        this->unk0 = var_r3_1567;
        var_r5_1579 = this->unk0;
        temp_r3_1580 = var_r5_1579 + ((s32) temp_r30_1549 * 0x38);
        this->unk0 = temp_r3_1580;
        *temp_r3_1580 = NULL;
        var_ctr_1583 = temp_r30_1549;
        if (temp_r30_1549 > 0) {
            do {
                temp_r3_1587 = this->unk0;
                this->unk0 = temp_r3_1587 + 4;
                M2C_FIELD(temp_r3_1587, MKDynamicBone ***, 4) = var_r5_1579;
                var_r5_1579 += 0x38;
                var_ctr_1583 -= 1;
            } while (var_ctr_1583 != NULL);
        }
        temp_r3_1594 = this->unk0;
        this->unk0 = temp_r3_1594 + 4;
        M2C_FIELD(temp_r3_1594, MKDynamicBone ***, 4) = NULL;
    }
    temp_r30_1602 = gMKDefaults.unkA0;
    if (temp_r30_1602 == 0) {
        spareTemplates = &gEmptyPtrListDL + 4;
    } else {
        temp_r3_1610 = gMKDefaults.Current();
        if (temp_r3_1610 != NULL) {
            var_r3_1620 = ((MKHeap *) (temp_r3_1610->Current()))->Alloc(((temp_r30_1602 + 2) * 4) + (temp_r30_1602 << 7), NULL, 0);
        } else {
            var_r3_1620 = malloc(((temp_r30_1602 + 2) * 4) + (temp_r30_1602 << 7));
        }
        spareTemplates = var_r3_1620;
        temp_r4_1631 = var_r3_1620 + (temp_r30_1602 << 7);
        spareTemplates = temp_r4_1631;
        *temp_r4_1631 = NULL;
        var_ctr_1635 = temp_r30_1602;
        if (temp_r30_1602 > 0) {
            do {
                spareTemplates += 4;
                M2C_FIELD(spareTemplates, MKDynamicBone ***, 4) = var_r3_1620;
                var_r3_1620 += 0x80;
                var_ctr_1635 -= 1;
            } while (var_ctr_1635 != 0);
        }
        spareTemplates += 4;
        M2C_FIELD(spareTemplates, MKDynamicBone ***, 4) = NULL;
    }
    this->unk4 = 0;
}
#endif

#if 0 // DRAFT: identifier 'arg2' redeclared
void MKDynamicBone_SetUpdater(MKDynamicBone *arg0, void (*arg2)(MKDynamicBone *, void *), void *arg2) {
    if (arg1 != NULL) {
        arg0->unk2C = (void (*)(MKDynamicBone *, MKDynamicBone *, void *)) arg1;
        arg0->unk28 = arg2;
        return;
    }
    arg0->unk2C = &MKDynamicBone::DefaultUpdater;
    arg0->unk28 = NULL;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'MKDynamicBoneSystem' to
void *MKDynamicBone_GetDynamicBone(MKModel *arg0, int arg1) {
    void **var_r30_1687;
    void *temp_r3_1697;
    void *temp_r3_1706;

    var_r30_1687 = gDynamicBones;
loop_6:
    temp_r3_1706 = *var_r30_1687;
    if (temp_r3_1706 == NULL) {
        return NULL;
    }
    if (((u32) M2C_FIELD(temp_r3_1706, u32 *, 0x24) == arg0) && (MKModel_GetAnimation(arg0) != NULL)) {
        temp_r3_1697 = *var_r30_1687;
        if ((s16) M2C_FIELD(M2C_FIELD(temp_r3_1697, void **, 0x20), s16 *, 0x70) == (s16) arg1) {
            return temp_r3_1697;
        }
    }
    var_r30_1687 += 4;
    goto loop_6;
}
#endif

#if 0 // DRAFT: undefined identifier 'identity'
void *MKDynamicBone_AddDynamicBone(MKModel *arg0, int arg1) {
    Animation *temp_r3_1727;
    MKDynamicBone **temp_r3_1736;
    MKDynamicBone *temp_r31_1738;
    void **temp_r3_1761;
    void *var_r30_1729;

    temp_r3_1727 = MKModel_GetAnimation(arg0);
    var_r30_1729 = NULL;
    if (temp_r3_1727 != NULL) {
        temp_r3_1727->EnableCustomMatrices(1U);
        temp_r3_1736 = spareTemplates - 4;
        spareTemplates = temp_r3_1736;
        temp_r31_1738 = *temp_r3_1736;
        memset(temp_r31_1738, 0, 0x80U);
        temp_r31_1738->unk70 = (s16) arg1;
        temp_r31_1738->unk72 = 0x100;
        temp_r31_1738->unk74 = 10.0f;
        M2C_STRUCT_COPY(temp_r31_1738, &identity, 0x40);
        temp_r3_1761 = gDynamicBones - 4;
        gDynamicBones = temp_r3_1761;
        var_r30_1729 = *temp_r3_1761;
        memset(var_r30_1729, 0, 0x38U);
        M2C_FIELD(var_r30_1729, MKModel **, 0x24) = arg0;
        M2C_FIELD(var_r30_1729, MKDynamicBone **, 0x20) = temp_r31_1738;
        M2C_FIELD(var_r30_1729, void (**)(MKDynamicBone *, MKDynamicBone *, void *), 0x2C) = &MKDynamicBone::DefaultUpdater;
        M2C_FIELD(var_r30_1729, s32 *, 0x28) = 0;
        M2C_FIELD(var_r30_1729, s8 *, 0x30) = 1;
    }
    return var_r30_1729;
}
#endif

void MKDynamicBone_ResetModel(MKModel *arg0) {
    gDynamicBones.ResetModel(arg0);
}
