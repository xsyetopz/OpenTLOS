#include "spyro/source/HitFX.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/Coronas.h"
#include "spyro/source/EmbersPS.h"
#include "spyro/source/LightManager.h"
#include "spyro/source/ManagedLight.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKView.h"
#include "common/Source/StdMath.h"
#include "common/gc/MKMaterial_GC.h"
#include "common/gc/MKPrimitive_GC.h"
#include <m2c_macros.h>

extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern M2C_UNK gb;

static s32 lit_509 = 0;
static u8 lit_510 = 0;

#if 0 // DRAFT: illegal implicit conversion from 'HitFX' to
void HitFX::Deinit() {
    Corona *temp_r4_53;
    ManagedLight *temp_r4_63;
    s32 var_r29_48;
    s32 var_r31_50;

    MKProp::Deinit();
    var_r29_48 = 0;
    var_r31_50 = 0;
    do {
        temp_r4_53 = *(this + (var_r31_50 + 0x78));
        if (temp_r4_53 != NULL) {
            ((Coronas *) (M2C_FIELD(&gb, Coronas **, 0x64)))->Free(temp_r4_53);
        }
        var_r29_48 += 1;
        var_r31_50 += 4;
    } while (var_r29_48 < 3);
    temp_r4_63 = this->unk84;
    if (temp_r4_63 != NULL) {
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->FreeManagedLight(temp_r4_63);
        this->unk84 = NULL;
    }
    MKMaterial_Destroy(this->unk8C);
}
#endif

#if 0 // DRAFT: undefined identifier 'unksp20C'
void HitFX::Draw() {
    f64 sp308;
    f64 sp300;
    f64 sp2F8;
    f64 sp2F0;
    f64 sp2E8;
    f64 sp2E0;
    f64 sp2D8;
    f64 sp2D0;
    MKVector3 sp2C0;
    MKVector3 sp2B0;
    MKVector3 sp2A0;
    MKVector3 sp290;
    Matrix sp250;
    Matrix sp210;
    f64 sp208;
    f64 sp200;
    f64 sp1F8;
    f64 sp1F0;
    f64 sp1E8;
    f64 sp1E0;
    f64 sp1D8;
    f64 sp1D0;
    MKVector3 sp1C0;
    f64 sp1B8;
    f64 sp1B0;
    MKVector3 sp1A0;
    f64 sp198;
    f64 sp190;
    MKVector3 sp180;
    MKVector3 sp170;
    f64 sp168;
    f64 sp160;
    MKVector3 sp150;
    f64 sp148;
    f64 sp140;
    MKVector3 sp130;
    f64 sp128;
    f64 sp120;
    f64 sp118;
    f64 sp110;
    MKVector3 sp100;
    MKVector3 spF0;
    f64 spE8;
    f64 spE0;
    f64 spD8;
    f64 spD0;
    f32 spC8;
    f32 spC4;
    f32 spC0;
    f32 spB8;
    f32 spB4;
    f32 spB0;
    f32 spAC;
    f32 spA8;
    f32 spA4;
    f32 spA0;
    f32 sp98;
    f32 sp88;
    f32 sp78;
    f32 sp68;
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
    f32 temp_f0_333;
    f32 temp_f29_336;
    f32 temp_f30_122;
    f32 temp_f30_280;
    f32 temp_f31_124;
    f32 temp_f31_334;
    s32 var_ctr_327;
    s32 var_r3_315;
    void *temp_r4_330;
    void *temp_r6_331;

    if ((u8) this->unk50 != 0) {
        spC8 = 0.0f;
        spB8 = 0.0f;
        spC0 = 0.0f;
        spC4 = 1.0f;
        spB0 = 1.0f;
        spB4 = 0.0f;
        sp200 = (f64) spC0;
        sp208 = (f64) spC8;
        sp1F0 = (f64) spB0;
        sp1F8 = (f64) spB8;
        temp_f30_122 = this->unk4C / 0.25f;
        temp_f31_124 = 200.0f * ((3.0f * temp_f30_122) + 1.0f);
        M2C_STRUCT_COPY((s32) &unksp20C + 4, MKView_GetCameraMatrix() - 4 + 4, 0x40);
        sp210.unk30 = this->unk68;
        sp210.unk34 = this->unk6C;
        sp210.unk38 = this->unk70;
        sp210.unk3C = 1.0f;
        sp1A0.operator*(temp_f31_124);
        sp40 = -(f32) sp1F0;
        sp44 = -unksp1F4;
        sp48 = -(f32) sp1F8;
        sp1B0 = (f64) sp40;
        sp1B8 = (f64) sp48;
        sp1C0.operator*(temp_f31_124);
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        sp1D0 = sp90;
        sp98 = sp1C0.unk8 + sp1A0.unk8;
        sp2D0 = sp90;
        sp1D8 = (f64) sp98;
        sp2D8 = (f64) sp98;
        sp170.operator*(temp_f31_124);
        sp180.operator*(temp_f31_124);
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        sp30 = -(f32) sp200;
        sp34 = -unksp204;
        sp88 = sp180.unk8 + sp170.unk8;
        sp38 = -(f32) sp208;
        sp190 = sp80;
        sp198 = (f64) sp88;
        sp2E0 = sp80;
        sp2E8 = (f64) sp88;
        sp120 = (f64) sp30;
        sp128 = (f64) sp38;
        sp130.operator*(temp_f31_124);
        sp20 = -(f32) sp1F0;
        sp24 = -unksp1F4;
        sp28 = -(f32) sp1F8;
        sp140 = (f64) sp20;
        sp148 = (f64) sp28;
        sp150.operator*(temp_f31_124);
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        sp10 = -(f32) sp200;
        sp14 = -unksp204;
        sp78 = sp150.unk8 + sp130.unk8;
        sp18 = -(f32) sp208;
        sp160 = sp70;
        sp168 = (f64) sp78;
        sp2F0 = sp70;
        sp2F8 = (f64) sp78;
        spE0 = (f64) sp10;
        spE8 = (f64) sp18;
        spF0.operator*(temp_f31_124);
        sp100.operator*(temp_f31_124);
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        temp_f30_280 = 1.0f - temp_f30_122;
        spAC = 1.0f;
        spA8 = temp_f30_280;
        sp68 = sp100.unk8 + spF0.unk8;
        spA0 = temp_f30_280;
        spA4 = temp_f30_280;
        sp1E8 = (f64) spA8;
        sp1E0 = (f64) spA0;
        sp110 = sp60;
        sp118 = (f64) sp68;
        sp300 = sp60;
        sp308 = (f64) sp68;
        MKMaterial_SetMaterial(this->unk8C);
        MKPrimitive(0xC, 0);
        MKSetMatrix(sp210);
        sp250.SetIdentity();
        sp250.SetRotationRoll((0.62831855f * temp_f30_280) + this->unk94);
        var_r3_315 = 0;
        var_ctr_327 = 4;
        do {
            temp_r4_330 = &sp290 + var_r3_315;
            temp_r6_331 = &sp2D0 + var_r3_315;
            var_r3_315 += 0x10;
            temp_f0_333 = M2C_FIELD(temp_r6_331, f32 *, 4);
            temp_f31_334 = M2C_FIELD(temp_r6_331, f32 *, 0);
            temp_f29_336 = M2C_FIELD(temp_r6_331, f32 *, 8);
            sp50 = sp250.unk30 + ((temp_f29_336 * sp250.unk20) + ((temp_f31_334 * M2C_BITWISE(f32, sp250)) + (temp_f0_333 * sp250.unk10)));
            sp54 = sp250.unk34 + ((temp_f29_336 * sp250.unk24) + ((temp_f31_334 * sp250.unk4) + (temp_f0_333 * sp250.unk14)));
            sp58 = sp250.unk38 + ((temp_f29_336 * sp250.unk28) + ((temp_f31_334 * sp250.unk8) + (temp_f0_333 * sp250.unk18)));
            M2C_FIELD(temp_r4_330, f64 *, 0) = (f64) sp50;
            spD0 = (f64) sp50;
            spD8 = (f64) sp58;
            M2C_FIELD(temp_r4_330, f64 *, 8) = (f64) sp58;
            var_ctr_327 -= 1;
        } while (var_ctr_327 != 0);
        MKBegin(4);
        MKSetColorV(*((MKVector4 *) &sp1E0));
        MKSetTexCoord1F(0.0f, this->unk88);
        MKSetPositionV(sp290);
        MKSetColorV(*((MKVector4 *) &sp1E0));
        MKSetTexCoord1F(1.0f, this->unk88);
        MKSetPositionV(sp2A0);
        MKSetColorV(*((MKVector4 *) &sp1E0));
        MKSetTexCoord1F(0.0f, 0.25f + this->unk88);
        MKSetPositionV(sp2B0);
        MKSetColorV(*((MKVector4 *) &sp1E0));
        MKSetTexCoord1F(1.0f, 0.25f + this->unk88);
        MKSetPositionV(sp2C0);
        MKEnd();
        MKEndPrimitive();
    }
}
#endif

#if 0 // DRAFT: function call 'MKRand_Float(long *, float, float)' does not match
void HitFX::Trigger(const MKVector3 &arg0, const MKVector3 &arg1, const MKVector4 &arg2, int arg3) {
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f32 sp8;
    ManagedLight *temp_r3_559;
    ManagedLight *temp_r3_570;
    ManagedLight *temp_r4_551;
    f32 temp_f29_508;
    f32 temp_f30_513;
    f64 temp_f0_561;
    f64 temp_f0_572;
    f64 temp_f1_560;
    f64 temp_f1_571;
    s32 temp_r6_482;
    s32 var_ctr_480;
    s32 var_r27_501;
    s32 var_r3_475;
    void *temp_r3_564;
    void *temp_r3_575;
    void *temp_r4_483;
    void *temp_r4_489;
    void *temp_r4_494;

    M2C_FIELD(this, f64 *, 0x68) = (f64) M2C_FIELD(&arg0, f64 *, 0);
    M2C_FIELD(this, f64 *, 0x70) = (f64) M2C_FIELD(&arg0, f64 *, 8);
    this->unk58 = M2C_FIELD(&arg1, f64 *, 0);
    this->unk60 = M2C_FIELD(&arg1, f64 *, 8);
    this->unk4C = 0.0f;
    this->unk50 = 1;
    this->unk88 = 0.0f;
    this->unk90 = 0.0f;
    this->unk94 = MKRand_Float(&gViewSeed, -3.1415927f, 3.1415927f);
    switch (arg3) {                                 /* irregular */
    case 0:
        this->unk88 = 0.0f;
        break;
    case 2:
        this->unk88 = 0.5f;
        break;
    case 1:
        this->unk88 = 0.25f;
        break;
    case 3:
        this->unk88 = 0.75f;
        break;
    }
    var_r3_475 = 0;
    var_ctr_480 = 3;
    do {
        temp_r6_482 = var_r3_475 + 0x78;
        temp_r4_483 = *(this + temp_r6_482);
        if (temp_r4_483 != NULL) {
            M2C_FIELD(temp_r4_483, u8 *, 0x31) = (u8) (M2C_FIELD(temp_r4_483, u8 *, 0x31) | 0x40);
            temp_r4_489 = *(this + temp_r6_482);
            M2C_FIELD(temp_r4_489, f64 *, 0) = (f64) M2C_FIELD(&arg0, f64 *, 0);
            M2C_FIELD(temp_r4_489, f64 *, 8) = (f64) M2C_FIELD(&arg0, f64 *, 8);
            M2C_FIELD(*(this + temp_r6_482), f32 *, 0x24) = 1.0f;
            temp_r4_494 = *(this + temp_r6_482);
            M2C_FIELD(temp_r4_494, f64 *, 0x10) = (f64) M2C_FIELD(&arg2, f64 *, 0);
            M2C_FIELD(temp_r4_494, f64 *, 0x18) = (f64) M2C_FIELD(&arg2, f64 *, 8);
        }
        var_r3_475 += 4;
        var_ctr_480 -= 1;
    } while (var_ctr_480 != 0);
    var_r27_501 = 0;
    do {
        temp_f29_508 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        temp_f30_513 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        sp20 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        sp24 = temp_f30_513;
        sp28 = temp_f29_508;
        sp30 = (f64) sp20;
        sp38 = (f64) sp28;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
        sp40 = sp10;
        sp18 = (f32) sp38 * 1050.0f;
        sp48 = (f64) sp18;
        sp8 = MKRand_Float(&gViewSeed, 6.0f, 12.0f);
        ((EmbersPS *) (M2C_FIELD(&gb, EmbersPS **, 0x74)))->Emit(arg0, *((MKVector3 *) &sp40), sp8, arg2, -980.0f);
        var_r27_501 += 1;
    } while (var_r27_501 < 0xA);
    temp_r4_551 = this->unk84;
    if (temp_r4_551 != NULL) {
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->EnableLight(temp_r4_551, 1U);
        temp_r3_559 = this->unk84;
        temp_f1_560 = M2C_FIELD(&arg2, f64 *, 0);
        temp_f0_561 = M2C_FIELD(&arg2, f64 *, 8);
        temp_r3_559->unk20 = temp_f1_560;
        temp_r3_559->unk28 = temp_f0_561;
        temp_r3_564 = temp_r3_559->unk3C;
        if (temp_r3_564 != NULL) {
            M2C_FIELD(temp_r3_564, f64 *, 0) = temp_f1_560;
            M2C_FIELD(temp_r3_564, f64 *, 8) = temp_f0_561;
        }
        temp_r3_570 = this->unk84;
        temp_f1_571 = M2C_FIELD(&arg0, f64 *, 0);
        temp_f0_572 = M2C_FIELD(&arg0, f64 *, 8);
        temp_r3_570->unk10 = temp_f1_571;
        temp_r3_570->unk18 = temp_f0_572;
        temp_r3_575 = temp_r3_570->unk3C;
        if (temp_r3_575 != NULL) {
            M2C_FIELD(temp_r3_575, f64 *, 0x10) = temp_f1_571;
            M2C_FIELD(temp_r3_575, f64 *, 0x18) = temp_f0_572;
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'sp58'
void HitFX::Update() {
    f64 spE0;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    f32 spC4;
    f32 spC0;
    f32 spBC;
    f32 spB8;
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
    ManagedLight *temp_r3_620;
    ManagedLight *temp_r4_645;
    ManagedLight *temp_r4_740;
    f32 temp_f1_771;
    f32 temp_f2_627;
    f32 temp_f3_793;
    f32 temp_f4_623;
    f32 var_f0_755;
    f32 var_f1_605;
    s32 var_ctr_779;
    s32 var_ctr_824;
    s32 var_r3_777;
    s32 var_r3_822;
    void *temp_r3_629;
    void *temp_r3_727;
    void *temp_r3_794;
    void *temp_r3_803;
    void *temp_r3_812;
    void *temp_r3_834;
    void *temp_r4_827;
    void *temp_r5_782;

    var_f1_605 = this->unk90 + gUpdateTimeDelta;
    if (var_f1_605 < 1.0f) {

    } else {
        var_f1_605 = 1.0f;
    }
    if (var_f1_605 > 0.0f) {

    } else {
        var_f1_605 = 0.0f;
    }
    this->unk90 = var_f1_605;
    temp_r3_620 = this->unk84;
    if (temp_r3_620 != NULL) {
        temp_f4_623 = this->unk90;
        temp_f2_627 = 800.0f * (1.0f + temp_f4_623);
        temp_r3_620->unk38 = temp_f2_627;
        temp_r3_629 = temp_r3_620->unk3C;
        if (temp_r3_629 != NULL) {
            M2C_FIELD(temp_r3_629, f32 *, 0x20) = temp_f2_627;
            M2C_FIELD(temp_r3_629, f32 *, 0x24) = (f32) (temp_f2_627 * temp_f2_627);
            M2C_FIELD(temp_r3_629, f32 *, 0x28) = (f32) (1.0f / temp_f2_627);
            M2C_FIELD(temp_r3_629, f32 *, 0x2C) = (f32) (1.0f / M2C_FIELD(temp_r3_629, f32 *, 0x24));
        }
        temp_r4_645 = this->unk84;
        spB8 = 0.0f;
        spBC = 0.0f;
        spC0 = 0.0f;
        spC4 = 0.0f;
        spC8 = (f64) spB8;
        spD0 = (f64) spC0;
        if ((0.5f * (temp_f4_623 * 1.0f)) < 1.0f) {

        }
        M2C_ERROR(/* unknown instruction: psq_lx $f3, $zero, $r3, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_sub $f1, $f4, $f3 */);
        M2C_ERROR(/* unknown instruction: psq_lx $f5, $r3, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_sub $f1, $f6, $f5 */);
        sp88 = sp58;
        sp90 = sp60;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f1, $f1, $f0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f1, $f1, $f0 */);
        sp78 = sp48;
        sp80 = sp50;
        M2C_ERROR(/* unknown instruction: ps_add $f1, $f3, $f1 */);
        M2C_ERROR(/* unknown instruction: ps_add $f1, $f5, $f1 */);
        sp68 = sp38;
        sp70 = sp40;
        M2C_ERROR(/* unknown instruction: ps_sub $f1, $f4, $f3 */);
        M2C_ERROR(/* unknown instruction: ps_sub $f1, $f6, $f4 */);
        spA8 = sp28;
        spB0 = sp30;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f1, $f1, $f0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f1, $f1, $f0 */);
        sp98 = sp18;
        spA0 = sp20;
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f3, $f0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f4, $f0 */);
        temp_r4_645->unk20 = sp8;
        temp_r4_645->unk28 = sp10;
        temp_r3_727 = temp_r4_645->unk3C;
        spD8 = sp8;
        spE0 = sp10;
        if (temp_r3_727 != NULL) {
            M2C_FIELD(temp_r3_727, f64 *, 0) = sp8;
            M2C_FIELD(temp_r3_727, f64 *, 8) = sp10;
        }
    }
    M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
    if (this->unk90 == 1.0f) {
        temp_r4_740 = this->unk84;
        if (temp_r4_740 != NULL) {
            ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->EnableLight(temp_r4_740, 0U);
        }
    }
    if ((u8) this->unk50 != 0) {
        var_f0_755 = this->unk4C + gUpdateTimeDelta;
        if (var_f0_755 < 0.25f) {

        } else {
            var_f0_755 = 0.25f;
        }
        if (var_f0_755 > 0.0f) {

        } else {
            var_f0_755 = 0.0f;
        }
        this->unk4C = var_f0_755;
        temp_f1_771 = this->unk4C;
        M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
        if (temp_f1_771 == 0.25f) {
            var_r3_777 = 0;
            this->unk50 = 0;
            var_ctr_779 = 3;
            do {
                temp_r5_782 = *(this + (var_r3_777 + 0x78));
                if (temp_r5_782 != NULL) {
                    M2C_FIELD(temp_r5_782, u8 *, 0x31) = (u8) (M2C_FIELD(temp_r5_782, u8 *, 0x31) & ~0x40);
                }
                var_r3_777 += 4;
                var_ctr_779 -= 1;
            } while (var_ctr_779 != 0);
            return;
        }
        temp_f3_793 = temp_f1_771 / 0.25f;
        temp_r3_794 = this->unk78;
        if (temp_r3_794 != NULL) {
            M2C_FIELD(temp_r3_794, f32 *, 0x2C) = (f32) ((3.0f * gUpdateTimeDelta) + M2C_FIELD(temp_r3_794, f32 *, 0x2C));
        }
        temp_r3_803 = this->unk7C;
        if (temp_r3_803 != NULL) {
            M2C_FIELD(temp_r3_803, f32 *, 0x2C) = (f32) -((3.0f * gUpdateTimeDelta) - M2C_FIELD(temp_r3_803, f32 *, 0x2C));
        }
        temp_r3_812 = this->unk80;
        if (temp_r3_812 != NULL) {
            M2C_FIELD(temp_r3_812, f32 *, 0x2C) = (f32) (M2C_FIELD(temp_r3_812, f32 *, 0x2C) + gUpdateTimeDelta);
        }
        var_r3_822 = 0;
        var_ctr_824 = 3;
        do {
            temp_r4_827 = *(this + (var_r3_822 + 0x78));
            if (temp_r4_827 != NULL) {
                M2C_FIELD(temp_r4_827, f32 *, 0x24) = (f32) (4.0f * temp_f3_793);
            }
            var_r3_822 += 4;
            var_ctr_824 -= 1;
        } while (var_ctr_824 != 0);
        temp_r3_834 = this->unk78;
        if (temp_r3_834 != NULL) {
            M2C_FIELD(temp_r3_834, f32 *, 0x24) = (f32) (7.0f * temp_f3_793);
        }
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void *' to
void HitFX::Resolve() {
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
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    ManagedLight *temp_r4_891;

    sp20 = 0.0f;
    sp30 = 0.0f;
    sp8 = 1.0f;
    spC = 1.0f;
    sp10 = 1.0f;
    sp14 = 1.0f;
    sp18 = 0.0f;
    sp1C = 0.0f;
    sp28 = 0.0f;
    sp2C = 0.0f;
    sp38 = (f64) sp8;
    sp40 = (f64) sp10;
    sp48 = (f64) sp18;
    sp50 = (f64) sp20;
    sp58 = (f64) sp28;
    sp60 = (f64) sp30;
    this->unk84 = ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->AllocManagedLight(*((MKVector3 *) &sp58), *((MKVector3 *) &sp48), *((MKVector4 *) &sp38), 500.0f, lit_509, lit_510);
    temp_r4_891 = this->unk84;
    if (temp_r4_891 != NULL) {
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->EnableLight(temp_r4_891, 0U);
    }
    this->unk8C = MKMaterial_Create("FX_346");
}
#endif

#if 0 // DRAFT: illegal operand
void HitFX::Init() {
    s32 temp_r0_929;
    s32 var_ctr_927;
    s32 var_r3_922;

    MKProp::Init();
    this->unk4C = 0.0f;
    var_r3_922 = 0;
    this->unk50 = 0;
    this->unk84 = NULL;
    this->unk8C = NULL;
    this->unk90 = 0.0f;
    var_ctr_927 = 3;
    do {
        temp_r0_929 = var_r3_922 + 0x78;
        var_r3_922 += 4;
        *(this + temp_r0_929) = 0;
        var_ctr_927 -= 1;
    } while (var_ctr_927 != 0);
}
#endif
