#include "spyro/source/GoopFX.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "common/Source/Texture.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/FXBase.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/KDMatrixProperty.h"
#include "spyro/source/KDMatrixRefProperty.h"
#include "spyro/source/KDPositionProperty.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDProperty.h"
#include "spyro/source/Level.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "common/Source/MKView.h"
#include "common/Source/StdMath.h"
#include "common/gc/MKMaterial_GC.h"
#include "common/gc/MKPrimitive_GC.h"
#include <m2c_macros.h>

M2C_UNK free(GoopFXDescriptor::Goop **);            /* extern */
GoopFXDescriptor::Goop **malloc(M2C_UNK);           /* extern */
f64 pow(f64, f32);                                  /* extern */
extern M2C_UNK gEmptyPtrListDL;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;

#if 0 // DRAFT: illegal type
void GoopFXDescriptor::DrawGoop(GoopFXDescriptor::Goop *arg1) {
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
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;

    sp50 = 0.0f;
    sp40 = 0.0f;
    sp30 = 0.0f;
    sp20 = 0.0f;
    sp10 = 0.0f;
    sp48 = 0.0f;
    sp4C = 0.0f;
    sp38 = 1.0f;
    sp3C = 0.0f;
    sp28 = 1.0f;
    sp2C = 1.0f;
    sp18 = 0.0f;
    sp1C = 1.0f;
    sp8 = 0.5f;
    spC = 0.5f;
    sp98 = (f64) sp48;
    spA0 = (f64) sp50;
    spA8 = (f64) sp48;
    spB0 = (f64) sp50;
    sp88 = (f64) sp38;
    sp90 = (f64) sp40;
    spB8 = (f64) sp38;
    spC0 = (f64) sp40;
    sp78 = (f64) sp28;
    sp80 = (f64) sp30;
    spC8 = (f64) sp28;
    spD0 = (f64) sp30;
    sp68 = (f64) sp18;
    sp70 = (f64) sp20;
    spD8 = (f64) sp18;
    spE0 = (f64) sp20;
    sp58 = (f64) sp8;
    sp60 = (f64) sp10;
    spE8 = (f64) sp8;
    spF0 = (f64) sp10;
    MKBegin(4);
    MKSetColorV(*(arg1 + 0xC8));
    MKSetTexCoord1F((f32) spA8, (*(f32 *) ((u8 *) &spA8 + 0x4)));
    MKSetPositionV(*((MKVector3 *) arg1));
    MKSetTexCoord1F((f32) spE8, (*(f32 *) ((u8 *) &spE8 + 0x4)));
    MKSetPositionV(*(arg1 + 0xA0));
    MKSetTexCoord1F((f32) spB8, (*(f32 *) ((u8 *) &spB8 + 0x4)));
    MKSetPositionV(*(arg1 + 0x28));
    MKSetTexCoord1F((f32) spC8, (*(f32 *) ((u8 *) &spC8 + 0x4)));
    MKSetPositionV(*(arg1 + 0x50));
    MKEnd();
    MKBegin(4);
    MKSetColorV(*(arg1 + 0xC8));
    MKSetTexCoord1F((f32) spA8, (*(f32 *) ((u8 *) &spA8 + 0x4)));
    MKSetPositionV(*((MKVector3 *) arg1));
    MKSetTexCoord1F((f32) spE8, (*(f32 *) ((u8 *) &spE8 + 0x4)));
    MKSetPositionV(*(arg1 + 0xA0));
    MKSetTexCoord1F((f32) spD8, (*(f32 *) ((u8 *) &spD8 + 0x4)));
    MKSetPositionV(*(arg1 + 0x78));
    MKSetTexCoord1F((f32) spC8, (*(f32 *) ((u8 *) &spC8 + 0x4)));
    MKSetPositionV(*(arg1 + 0x50));
    MKEnd();
}
#endif

#if 0 // DRAFT: undefined identifier 'P16GoopFXDescriptor'
void GoopFX::Emit(const MKVector3 &arg0, const MKVector3 &arg1, float arg2, const MKVector4 &arg3) {
    ((GoopFXDescriptor *) (checked_cast<P16GoopFXDescriptor))->Emit(*(16MKPropDescriptor>__FP16MKPropDescriptor((MKPropDescriptor *) this->unk0)), arg0, &arg1, *arg2, &arg3);
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void GoopFX::Deinit() {
    KDPropEx::Deinit();
}
#endif

#if 0 // DRAFT: undefined identifier 'P16GoopFXDescriptor'
void GoopFX::Draw() {
    ((GoopFXDescriptor *) (checked_cast<P16GoopFXDescriptor))->DrawGoopList(16MKPropDescriptor>__FP16MKPropDescriptor((MKPropDescriptor *) this->unk0));
}
#endif

#if 0 // DRAFT: undefined identifier 'P16GoopFXDescriptor'
void GoopFX::Update() {
    ((GoopFXDescriptor *) (checked_cast<P16GoopFXDescriptor))->UpdateGoopList(16MKPropDescriptor>__FP16MKPropDescriptor((MKPropDescriptor *) this->unk0));
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void GoopFX::Init() {
    KDPropEx::Init();
}
#endif

#if 0 // DRAFT: illegal type
void GoopFXDescriptor::Emit(const MKVector3 &arg0, const MKVector3 &arg1, float arg2, const MKVector4 &arg3) {
    f32 sp10C;
    f32 sp108;
    f32 sp104;
    f32 sp100;
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
    f64 sp70;
    f32 sp68;
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
    GoopFXDescriptor::Goop **temp_r3_275;
    GoopFXDescriptor::Goop **temp_r3_281;
    GoopFXDescriptor::Goop *temp_r28_283;
    f32 temp_f0_401;
    f32 temp_f31_297;
    f32 temp_f4_403;
    f32 temp_f5_405;
    f32 temp_f6_383;
    f32 temp_f7_381;
    f32 temp_f8_379;
    f64 temp_f1_308;
    s32 var_ctr_397;
    s32 var_r27_299;
    s32 var_r30_292;
    s32 var_r3_382;
    void *temp_r3_314;
    void *temp_r4_399;

    temp_r3_275 = this->unkE8;
    if ((u32) M2C_FIELD(temp_r3_275, u32 *, -4) != 0U) {
        temp_r3_281 = temp_r3_275 - 4;
        this->unkE8 = temp_r3_281;
        temp_r28_283 = *temp_r3_281;
        if (temp_r28_283 != NULL) {
            M2C_FIELD(temp_r28_283, f32 *, 0xDC) = arg2;
            var_r30_292 = 0;
            temp_f31_297 = arg1.unk8;
            var_r27_299 = 0;
            M2C_FIELD(temp_r28_283, f32 *, 0xD8) = (f32) (4.0f * MKRand_Float((int *) &gViewSeed, 0.75f, 1.0f));
            M2C_FIELD(temp_r28_283, s32 *, 0xE0) = 1;
            M2C_FIELD(temp_r28_283, f64 *, 0xC8) = (f64) M2C_FIELD(&arg3, f64 *, 0);
            M2C_FIELD(temp_r28_283, f64 *, 0xD0) = (f64) M2C_FIELD(&arg3, f64 *, 8);
            do {
                temp_f1_308 = MKRand_Float((int *) &gViewSeed, 0.25f, 1.0f);
                sp60 = M2C_FIELD(&arg1, f64 *, 0) * temp_f1_308;
                temp_r3_314 = temp_r28_283 + var_r30_292;
                var_r27_299 += 1;
                var_r30_292 += 0x28;
                sp68 = temp_f31_297 * (f32) temp_f1_308;
                M2C_FIELD(temp_r3_314, f64 *, 0x10) = sp60;
                M2C_FIELD(temp_r3_314, f64 *, 0x18) = (f64) sp68;
                spC0 = sp60;
                spC8 = (f64) sp68;
                M2C_FIELD(temp_r3_314, s8 *, 0x20) = 0;
            } while (var_r27_299 < 5);
            sp50 = -1.0f;
            sp54 = 1.0f;
            sp58 = 0.0f;
            M2C_FIELD(temp_r28_283, f64 *, 0) = (f64) sp50;
            sp48 = 0.0f;
            sp38 = 0.0f;
            sp28 = 0.0f;
            sp40 = 1.0f;
            sp44 = 1.0f;
            M2C_FIELD(temp_r28_283, f64 *, 8) = (f64) sp58;
            M2C_FIELD(temp_r28_283, f64 *, 0x28) = (f64) sp40;
            sp30 = 1.0f;
            sp34 = -1.0f;
            M2C_FIELD(temp_r28_283, f64 *, 0x30) = (f64) sp48;
            M2C_FIELD(temp_r28_283, f64 *, 0x50) = (f64) sp30;
            sp20 = -1.0f;
            sp24 = -1.0f;
            M2C_FIELD(temp_r28_283, f64 *, 0x58) = (f64) sp38;
            M2C_FIELD(temp_r28_283, f64 *, 0x78) = (f64) sp20;
            M2C_FIELD(temp_r28_283, f64 *, 0x80) = (f64) sp28;
            M2C_FIELD(temp_r28_283, f32 *, 0xA0) = 0.0f;
            M2C_FIELD(temp_r28_283, f32 *, 0xA4) = 0.0f;
            spB0 = (f64) sp50;
            spB8 = (f64) sp58;
            spA0 = (f64) sp40;
            spA8 = (f64) sp48;
            sp90 = (f64) sp30;
            sp98 = (f64) sp38;
            sp80 = (f64) sp20;
            sp88 = (f64) sp28;
            M2C_FIELD(temp_r28_283, f32 *, 0xA8) = 0.0f;
            M2C_STRUCT_COPY((s32) &unkspCC + 4, (s32) &this->unkEC + 4, 0x40);
            temp_f8_379 = arg0.unk0;
            temp_f7_381 = arg0.unk4;
            var_r3_382 = 0;
            temp_f6_383 = arg0.unk8;
            sp100 = temp_f8_379;
            sp104 = temp_f7_381;
            sp108 = temp_f6_383;
            sp10C = 1.0f;
            var_ctr_397 = 5;
            do {
                temp_r4_399 = temp_r28_283 + var_r3_382;
                temp_f0_401 = M2C_FIELD(temp_r4_399, f32 *, 4);
                var_r3_382 += 0x28;
                temp_f4_403 = M2C_FIELD(temp_r4_399, f32 *, 0);
                temp_f5_405 = M2C_FIELD(temp_r4_399, f32 *, 8);
                sp10 = temp_f8_379 + ((temp_f5_405 * spF0) + ((temp_f4_403 * spD0) + (temp_f0_401 * spE0)));
                sp14 = temp_f7_381 + ((temp_f5_405 * spF4) + ((temp_f4_403 * spD4) + (temp_f0_401 * spE4)));
                sp18 = temp_f6_383 + ((temp_f5_405 * spF8) + ((temp_f4_403 * spD8) + (temp_f0_401 * spE8)));
                M2C_FIELD(temp_r4_399, f32 *, 0) = (f64) sp10;
                sp70 = (f64) sp10;
                sp78 = (f64) sp18;
                M2C_FIELD(temp_r4_399, f32 *, 8) = (f64) sp18;
                var_ctr_397 -= 1;
            } while (var_ctr_397 != 0);
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier '__float_nan'
void GoopFXDescriptor::UpdateGoopNodes(GoopFXDescriptor::GoopNode *arg1, GoopFXDescriptor::GoopNode *arg2, GoopFXDescriptor::Goop *arg3) {
    f64 spA8;                                       /* compiler-managed */
    f64 spA0;                                       /* compiler-managed */
    f64 sp98;
    f64 sp90;
    MKVector3 sp80;
    f64 sp78;
    f64 sp70;
    MKVector3 sp60;
    f64 sp58;
    f64 sp50;
    f32 sp48;
    f64 sp40;
    f32 sp38;
    f64 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 sp8;
    f32 temp_f29_569;
    f32 temp_f30_612;
    f32 temp_f31_576;
    f32 var_f5_554;
    f32 var_f6_487;
    f64 temp_f0_582;
    f64 temp_f0_624;
    f64 temp_f2_493;
    f64 temp_f2_499;
    f64 temp_f2_503;
    s32 temp_r3_522;
    s32 var_r0_532;

    if (((u8) M2C_FIELD(arg1, u8 *, 0x20) == 0) || ((u8) M2C_FIELD(arg2, u8 *, 0x20) == 0)) {
        sp40 = M2C_FIELD(arg1, f64 *, 0) - M2C_FIELD(arg2, f64 *, 0);
        spA0 = sp40;
        sp48 = M2C_FIELD(arg1, f32 *, 8) - M2C_FIELD(arg2, f32 *, 8);
        spA8 = (f64) sp48;
        var_f6_487 = ((f32) spA8 * (f32) spA8) + (((f32) spA0 * (f32) spA0) + ((*(f32 *) ((u8 *) &sp98 + 0xc)) * (*(f32 *) ((u8 *) &sp98 + 0xc))));
        if (var_f6_487 > 0.000001f) {
            if (var_f6_487 > 0.0f) {
                temp_f2_493 = __frsqrte(var_f6_487);
                temp_f2_499 = 0.5 * temp_f2_493 * -(((f64) var_f6_487 * (temp_f2_493 * temp_f2_493)) - 3.0);
                temp_f2_503 = 0.5 * temp_f2_499 * -(((f64) var_f6_487 * (temp_f2_499 * temp_f2_499)) - 3.0);
                var_f6_487 = (f32) ((f64) var_f6_487 * (0.5 * temp_f2_503 * -(((f64) var_f6_487 * (temp_f2_503 * temp_f2_503)) - 3.0)));
            } else if (var_f6_487 < M2C_BITWISE(f32, 0.0)) {
                var_f6_487 = __float_nan;
            } else {
                sp8 = var_f6_487;
                temp_r3_522 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                switch (temp_r3_522) {              /* irregular */
                case 0x7F800000:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_532 = 1;
                    } else {
                        var_r0_532 = 2;
                    }
                    break;
                case 0x0:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_532 = 5;
                    } else {
                        var_r0_532 = 3;
                    }
                    break;
                default:
                    var_r0_532 = 4;
                    break;
                }
                if (var_r0_532 == 1) {
                    var_f6_487 = __float_nan;
                }
            }
            var_f5_554 = 1.0f / var_f6_487;
        } else {
            var_f5_554 = 0.0f;
            var_f6_487 = 0.0f;
        }
        spA0 = (f32) spA0 * var_f5_554;
        temp_f29_569 = 30.0f * ((100.0f * M2C_FIELD(arg3, f32 *, 0xDC)) - var_f6_487);
        (*(f32 *) ((u8 *) &sp98 + 0xc)) *= var_f5_554;
        spA8 = (f32) spA8 * var_f5_554;
        if ((u8) M2C_FIELD(arg1, u8 *, 0x20) == 0) {
            temp_f31_576 = gUpdateTimeDelta;
            sp80.operator*(temp_f29_569);
            temp_f0_582 = sp80 * (f64) temp_f31_576;
            sp30 = temp_f0_582;
            sp90 = temp_f0_582;
            sp38 = sp80.unk8 * temp_f31_576;
            sp98 = (f64) sp38;
            M2C_FIELD(arg1, f64 *, 0x10) = (f64) (M2C_FIELD(arg1, f64 *, 0x10) + temp_f0_582);
            M2C_FIELD(arg1, f32 *, 0x18) = (f32) (M2C_FIELD(arg1, f32 *, 0x18) + (f32) sp98);
        }
        if ((u8) M2C_FIELD(arg2, u8 *, 0x20) == 0) {
            temp_f30_612 = gUpdateTimeDelta;
            sp10 = -spA0;
            sp14 = -(*(f32 *) ((u8 *) &sp98 + 0xc));
            sp18 = -spA8;
            sp50 = (f64) sp10;
            sp58 = (f64) sp18;
            sp60.operator*(temp_f29_569);
            temp_f0_624 = sp60 * (f64) temp_f30_612;
            sp20 = temp_f0_624;
            sp70 = temp_f0_624;
            sp28 = sp60.unk8 * temp_f30_612;
            sp78 = (f64) sp28;
            M2C_FIELD(arg2, f64 *, 0x10) = (f64) (M2C_FIELD(arg2, f64 *, 0x10) + temp_f0_624);
            M2C_FIELD(arg2, f32 *, 0x18) = (f32) (M2C_FIELD(arg2, f32 *, 0x18) + (f32) sp78);
        }
    }
}
#endif

#if 0 // DRAFT: illegal type
u8 GoopFXDescriptor::TwoFrozenNodes(GoopFXDescriptor::Goop *arg1) {
    s32 var_ctr_662;
    s32 var_r3_661;
    s32 var_r5_660;

    var_r5_660 = 0;
    var_r3_661 = 0;
    var_ctr_662 = 4;
    do {
        if ((u8) *(arg1 + (var_r3_661 + 0x20)) != 0) {
            var_r5_660 += 1;
        }
        var_r3_661 += 0x28;
        var_ctr_662 -= 1;
    } while (var_ctr_662 != 0);
    return var_r5_660 > 1;
}
#endif

#if 0 // DRAFT: illegal type
u8 GoopFXDescriptor::UpdateGoop(GoopFXDescriptor::Goop *arg1) {
    s8 sp160;
    s32 sp15C;
    s32 sp158;
    s32 sp154;
    f32 sp150;
    s32 sp14C;
    s8 sp14B;
    s8 sp14A;
    s16 sp148;
    f32 sp144;
    f32 sp140;
    f32 sp13C;
    f32 sp138;
    f32 sp134;
    f32 sp130;
    f32 sp128;
    f32 sp124;
    f32 sp120;
    f32 sp118;
    f32 sp114;
    f32 sp110;
    f64 sp108;
    f64 sp100;
    f64 spF8;
    f64 spF0;
    f64 spE8;
    f64 spE0;
    f64 spD0;
    f64 spC8;
    f64 spC0;
    MKVector3 spB0;
    f64 spA8;
    f64 spA0;
    MKVector3 sp90;
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
    f64 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    f32 sp8;
    MKVector3 *temp_r30_787;
    f32 temp_f0_918;
    f32 temp_f1_917;
    f32 temp_f28_703;
    f32 temp_f30_820;
    f32 temp_f3_920;
    f32 var_f1_771;
    f32 var_f1_925;
    f32 var_f2_992;
    f64 temp_f0_1009;
    f64 temp_f0_799;
    f64 temp_f0_824;
    f64 temp_f2_931;
    f64 temp_f2_937;
    f64 temp_f2_941;
    s32 temp_r0_765;
    s32 temp_r3_960;
    s32 var_ctr_763;
    s32 var_r0_970;
    s32 var_r25_784;
    s32 var_r28_783;
    s32 var_r3_757;
    void *temp_r29_792;

    temp_f28_703 = (f32) pow(0.125, gUpdateTimeDelta);
    UpdateGoopNodes((GoopFXDescriptor::GoopNode *) arg1, arg1 + 0x28, arg1);
    UpdateGoopNodes(arg1 + 0x28, arg1 + 0x50, arg1);
    UpdateGoopNodes(arg1 + 0x50, arg1 + 0x78, arg1);
    UpdateGoopNodes(arg1 + 0x78, (GoopFXDescriptor::GoopNode *) arg1, arg1);
    UpdateGoopNodes(arg1 + 0xA0, (GoopFXDescriptor::GoopNode *) arg1, arg1);
    UpdateGoopNodes(arg1 + 0xA0, arg1 + 0x28, arg1);
    UpdateGoopNodes(arg1 + 0xA0, arg1 + 0x50, arg1);
    UpdateGoopNodes(arg1 + 0xA0, arg1 + 0x78, arg1);
    M2C_FIELD(arg1, f32 *, 0xD8) = (f32) (M2C_FIELD(arg1, f32 *, 0xD8) - gUpdateTimeDelta);
    if (((s32) M2C_FIELD(arg1, s32 *, 0xE0) == 1) && (M2C_FIELD(arg1, f32 *, 0xD8) <= 0.0f)) {
        var_r3_757 = 0;
        M2C_FIELD(arg1, s32 *, 0xE0) = 2;
        M2C_FIELD(arg1, f32 *, 0xD8) = 2.0f;
        var_ctr_763 = 5;
        do {
            temp_r0_765 = var_r3_757 + 0x20;
            var_r3_757 += 0x28;
            *(arg1 + temp_r0_765) = 0;
            var_ctr_763 -= 1;
        } while (var_ctr_763 != 0);
    }
    var_f1_771 = 2.0f;
    if ((s32) M2C_FIELD(arg1, s32 *, 0xE0) == 1) {
        var_f1_771 = (3.0f * -((M2C_FIELD(arg1, f32 *, 0xD8) * 0.25f) - 1.0f)) + 1.0f;
    }
    var_r28_783 = 0;
    var_r25_784 = 0;
    do {
        temp_r30_787 = arg1 + var_r25_784;
        if ((u8) M2C_FIELD(temp_r30_787, u8 *, 0x20) == 0) {
            temp_r29_792 = temp_r30_787 + 0x10;
            sp100 = M2C_FIELD(temp_r30_787, f64 *, 0);
            sp108 = M2C_FIELD(temp_r30_787, f64 *, 8);
            temp_f0_799 = M2C_FIELD(temp_r29_792, f64 *, 0) * (f64) gUpdateTimeDelta;
            sp60 = temp_f0_799;
            spF0 = temp_f0_799;
            sp68 = M2C_FIELD(temp_r30_787, f32 *, 0x18) * gUpdateTimeDelta;
            spF8 = (f64) sp68;
            M2C_FIELD(temp_r30_787, f64 *, 0) = (f64) (M2C_FIELD(temp_r30_787, f64 *, 0) + temp_f0_799);
            temp_r30_787->unk8 = (f32) temp_r30_787->unk8 + (f32) spF8;
            temp_f30_820 = gUpdateTimeDelta;
            MKVector(0.0f, -3000.0f * var_f1_771, 0.0f);
            temp_f0_824 = spD0 * (f64) temp_f30_820;
            sp50 = temp_f0_824;
            spE0 = temp_f0_824;
            sp58 = spD8 * temp_f30_820;
            spE8 = (f64) sp58;
            M2C_FIELD(temp_r29_792, f64 *, 0) = (f64) (M2C_FIELD(temp_r29_792, f64 *, 0) + temp_f0_824);
            M2C_FIELD(temp_r30_787, f32 *, 0x18) = (f32) (M2C_FIELD(temp_r30_787, f32 *, 0x18) + (f32) spE8);
            M2C_FIELD(temp_r29_792, f64 *, 0) = (f64) (M2C_FIELD(temp_r29_792, f64 *, 0) * (f64) temp_f28_703);
            M2C_FIELD(temp_r30_787, f32 *, 0x18) = (f32) (M2C_FIELD(temp_r30_787, f32 *, 0x18) * temp_f28_703);
            if ((s32) M2C_FIELD(arg1, s32 *, 0xE0) == 1) {
                sp110 = 0.0f;
                sp114 = 0.0f;
                sp118 = 0.0f;
                sp120 = 0.0f;
                sp124 = 0.0f;
                sp128 = 0.0f;
                sp130 = 0.0f;
                sp134 = 0.0f;
                sp138 = 0.0f;
                sp13C = 1.0f;
                sp140 = 0.0f;
                sp144 = 0.0f;
                sp148 = 0;
                sp14A = 0;
                sp14B = 0;
                sp14C = 0;
                sp150 = 3.4028235e38f;
                sp154 = 0;
                sp158 = 0;
                sp15C = -1;
                sp160 = 0;
                if (MKCollision_RayCollide(*((MKVector3 *) &sp100), *temp_r30_787, (MKCollisionResult *) &sp110, (MKCollisionMode) 7, 0x0C000000) != 0) {
                    if ((TwoFrozenNodes(arg1) == 0) && (var_r28_783 != 4)) {
                        spB0.operator*(5.0f);
                        sp40 = (f64) sp110 + M2C_BITWISE(f64, spB0);
                        M2C_FIELD(temp_r30_787, f64 *, 0) = sp40;
                        sp48 = sp118 + spB0.unk8;
                        spC0 = sp40;
                        M2C_FIELD(temp_r30_787, f64 *, 8) = (f64) sp48;
                        M2C_FIELD(temp_r30_787, f32 *, 0x10) = 0.0f;
                        M2C_FIELD(temp_r30_787, f32 *, 0x14) = 0.0f;
                        M2C_FIELD(temp_r30_787, f32 *, 0x18) = 0.0f;
                        spC8 = (f64) sp48;
                        M2C_FIELD(temp_r30_787, u8 *, 0x20) = 1U;
                    } else {
                        temp_f1_917 = M2C_FIELD(temp_r30_787, f32 *, 0x10);
                        temp_f0_918 = M2C_FIELD(temp_r30_787, f32 *, 0x14);
                        temp_f3_920 = M2C_FIELD(temp_r30_787, f32 *, 0x18);
                        var_f1_925 = (temp_f3_920 * temp_f3_920) + ((temp_f1_917 * temp_f1_917) + (temp_f0_918 * temp_f0_918));
                        if (var_f1_925 > 0.000001f) {
                            if (var_f1_925 > 0.0f) {
                                temp_f2_931 = __frsqrte(var_f1_925);
                                temp_f2_937 = 0.5 * temp_f2_931 * -(((f64) var_f1_925 * (temp_f2_931 * temp_f2_931)) - 3.0);
                                temp_f2_941 = 0.5 * temp_f2_937 * -(((f64) var_f1_925 * (temp_f2_937 * temp_f2_937)) - 3.0);
                                var_f1_925 = (f32) ((f64) var_f1_925 * (0.5 * temp_f2_941 * -(((f64) var_f1_925 * (temp_f2_941 * temp_f2_941)) - 3.0)));
                            } else if (var_f1_925 < M2C_BITWISE(f32, 0.0)) {
                                var_f1_925 = __float_nan;
                            } else {
                                sp8 = var_f1_925;
                                temp_r3_960 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                                switch (temp_r3_960) { /* irregular */
                                case 0x7F800000:
                                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                        var_r0_970 = 1;
                                    } else {
                                        var_r0_970 = 2;
                                    }
                                    break;
                                case 0x0:
                                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                        var_r0_970 = 5;
                                    } else {
                                        var_r0_970 = 3;
                                    }
                                    break;
                                default:
                                    var_r0_970 = 4;
                                    break;
                                }
                                if (var_r0_970 == 1) {
                                    var_f1_925 = __float_nan;
                                }
                            }
                            var_f2_992 = 1.0f / var_f1_925;
                        } else {
                            var_f2_992 = 0.0f;
                            var_f1_925 = 0.0f;
                        }
                        M2C_FIELD(temp_r30_787, f32 *, 0x10) = (f32) (M2C_FIELD(temp_r30_787, f32 *, 0x10) * var_f2_992);
                        M2C_FIELD(temp_r30_787, f32 *, 0x14) = (f32) (M2C_FIELD(temp_r30_787, f32 *, 0x14) * var_f2_992);
                        M2C_FIELD(temp_r30_787, f32 *, 0x18) = (f32) (M2C_FIELD(temp_r30_787, f32 *, 0x18) * var_f2_992);
                        temp_f0_1009 = M2C_FIELD(temp_r29_792, f64 *, 0) + sp120;
                        sp10 = temp_f0_1009;
                        sp80 = temp_f0_1009;
                        sp18 = M2C_FIELD(temp_r30_787, f32 *, 0x18) + sp128;
                        sp88 = (f64) sp18;
                        sp90.operator*(var_f1_925);
                        sp30 = sp90 * 5.24282163e-315;
                        M2C_FIELD(temp_r30_787, f32 *, 0x10) = sp30;
                        sp38 = sp90.unk8 * 0.75f;
                        spA0 = sp30;
                        M2C_FIELD(temp_r29_792, f64 *, 8) = (f64) sp38;
                        spA8 = (f64) sp38;
                        sp20 = (f64) sp110 + sp120;
                        M2C_FIELD(temp_r30_787, f64 *, 0) = sp20;
                        sp28 = sp118 + sp128;
                        sp70 = sp20;
                        sp78 = (f64) sp28;
                        M2C_FIELD(temp_r30_787, f64 *, 8) = (f64) sp28;
                    }
                }
            }
        }
        var_r28_783 += 1;
        var_r25_784 += 0x28;
    } while (var_r28_783 < 5);
    if ((M2C_FIELD(arg1, f32 *, 0xD8) <= 0.0f) && ((s32) M2C_FIELD(arg1, s32 *, 0xE0) == 2)) {
        return 0U;
    }
    return 1U;
}
#endif

void GoopFXDescriptor::DrawGoopList() {
    GoopFXDescriptor::Goop **var_r31_1121;
    GoopFXDescriptor::Goop *temp_r4_1130;
    MKMaterial *temp_r3_1111;

    if (((u8) this->unkE5 == 0) && ((GoopFXDescriptor::Goop *) *this->unkE8 != NULL)) {
        M2C_STRUCT_COPY((s32) &this->unkEC + 4, MKView_GetCameraMatrix() - 4 + 4, 0x40);
        temp_r3_1111 = this->unkE0;
        if (temp_r3_1111 != NULL) {
            MKMaterial_SetMaterial(temp_r3_1111);
            MKPrimitive(0xC, 0x10);
            MKSetMatrix(Matrix::identity);
            var_r31_1121 = this->unkE8;
loop_5:
            if (var_r31_1121 != NULL) {
                temp_r4_1130 = *var_r31_1121;
                if (temp_r4_1130 != NULL) {
                    DrawGoop(temp_r4_1130);
                    var_r31_1121 += 4;
                    goto loop_5;
                }
            }
            MKEndPrimitive();
            this->unkE4 = 0;
            this->unkE5 = 1;
        }
    }
}

void GoopFXDescriptor::UpdateGoopList() {
    GoopFXDescriptor::Goop **temp_r3_1165;
    GoopFXDescriptor::Goop **var_r31_1158;
    GoopFXDescriptor::Goop *temp_r4_1168;
    GoopFXDescriptor::Goop *temp_r4_1177;

    if ((u8) this->unkE4 == 0) {
        var_r31_1158 = this->unkE8;
loop_5:
        if (var_r31_1158 != NULL) {
            temp_r4_1177 = *var_r31_1158;
            if (temp_r4_1177 != NULL) {
                if (UpdateGoop(temp_r4_1177) == 0) {
                    temp_r3_1165 = this->unkE8;
                    this->unkE8 = temp_r3_1165 + 4;
                    temp_r4_1168 = *temp_r3_1165;
                    *temp_r3_1165 = *var_r31_1158;
                    *var_r31_1158 = temp_r4_1168;
                }
                var_r31_1158 += 4;
                goto loop_5;
            }
        }
        this->unkE4 = 1;
        this->unkE5 = 0;
    }
}

#if 0 // DRAFT: type mismatch
void GoopFXDescriptor::Deinit() {
    GoopFXDescriptor::Goop **var_r31_1207;
    GoopFXDescriptor::Goop **var_r3_1208;
    GoopFXDescriptor::Goop **var_r4_1206;
    GoopFXDescriptor::Goop *temp_r0_1211;
    GoopFXDescriptor::Goop *temp_r0_1230;
    MKHeap *temp_r3_1233;
    MKMaterial *temp_r3_1201;
    u32 temp_r0_1216;

    temp_r3_1201 = this->unkE0;
    if (temp_r3_1201 != NULL) {
        MKMaterial_Destroy(temp_r3_1201);
    }
    var_r4_1206 = this->unkE8;
    var_r31_1207 = var_r4_1206;
    var_r3_1208 = var_r4_1206;
loop_5:
    temp_r0_1216 = M2C_FIELD(var_r3_1208, u32 *, -4);
    var_r3_1208 -= 4;
    if (temp_r0_1216 != 0U) {
        temp_r0_1211 = *var_r3_1208;
        if (temp_r0_1211 < var_r31_1207) {
            var_r31_1207 = (GoopFXDescriptor::Goop **) temp_r0_1211;
        }
        goto loop_5;
    }
    if (var_r3_1208 != &gEmptyPtrListDL) {
loop_11:
        temp_r0_1230 = *var_r4_1206;
        if (temp_r0_1230 != NULL) {
            if (temp_r0_1230 < var_r31_1207) {
                var_r31_1207 = (GoopFXDescriptor::Goop **) temp_r0_1230;
            }
            var_r4_1206 += 4;
            goto loop_11;
        }
        temp_r3_1233 = ((MKHeap *) var_r3_1208)->Current();
        if (temp_r3_1233 != NULL) {
            ((MKHeap *) (temp_r3_1233->Current()))->Free(var_r31_1207, NULL, 0);
        } else {
            free(var_r31_1207);
        }
    }
    this->unkE8 = NULL;
    KDPropExDescriptor::Deinit();
}
#endif

#if 0 // DRAFT: illegal use of non-static member
s32 GoopFXDescriptor::LoadLine(MKIniLine *arg0) {
    s8 *sp8;

    if (FXBaseDescriptor::LoadLine(arg0) != 0) {
        return 1;
    }
    sp8 = NULL;
    if ((arg0->LoadString("GoopMaterial", &sp8, 0) != 0) && ((MKMaterial *) this->unkE0 == NULL)) {
        this->unkE0 = MKMaterial_Create(sp8);
        return 1;
    }
    return 0;
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void GoopFXDescriptor::Init() {
    GoopFXDescriptor::Goop **temp_r3_1333;
    GoopFXDescriptor::Goop **temp_r4_1339;
    GoopFXDescriptor::Goop **var_r3_1318;
    GoopFXDescriptor::Goop **var_r5_1327;
    MKHeap *temp_r3_1311;
    s32 var_ctr_1331;

    FXBaseDescriptor::Init();
    this->unkE0 = NULL;
    temp_r3_1311 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_1311 != NULL) {
        var_r3_1318 = ((MKHeap *) (temp_r3_1311->Current()))->Alloc(0x5C38, NULL, 0);
    } else {
        var_r3_1318 = malloc(0x5C38);
    }
    this->unkE8 = var_r3_1318;
    var_r5_1327 = this->unkE8;
    this->unkE8 = var_r5_1327 + 0x5AA0;
    M2C_FIELD(var_r5_1327, s32 *, 0x5AA0) = 0;
    var_ctr_1331 = 0x64;
    do {
        temp_r3_1333 = this->unkE8;
        this->unkE8 = temp_r3_1333 + 4;
        M2C_FIELD(temp_r3_1333, GoopFXDescriptor::Goop ***, 4) = var_r5_1327;
        var_r5_1327 += 0xE8;
        var_ctr_1331 -= 1;
    } while (var_ctr_1331 != 0);
    temp_r4_1339 = this->unkE8;
    this->unkE8 = temp_r4_1339 + 4;
    M2C_FIELD(temp_r4_1339, GoopFXDescriptor::Goop ***, 4) = NULL;
    this->unkE4 = 0;
    this->unkE5 = 0;
    this->unkF0.SetIdentity();
}
#endif
