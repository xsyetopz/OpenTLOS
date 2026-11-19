#include "spyro/source/HeatDistortPS.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "common/Source/MKView.h"
#include "common/Source/StdMath.h"
#include "common/gc/MKMaterial_GC.h"
#include "common/gc/MKPrimitive_GC.h"
#include "spyro/source/KDRandom.h"
#include "spyro/source/ShotgunWarpFX.h"
#include <m2c_macros.h>

M2C_UNK free(MKHeap *);                             /* extern */
MKHeap *malloc(M2C_UNK);                            /* extern */
f64 pow(f64, f32);                                  /* extern */
M2C_UNK qsort(MKHeap *, M2C_UNK, s32 (*)(void *, void *)); /* extern */
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;

#if 0 // DRAFT: undefined identifier 'arg_sp23C'
static s8 lit_stringBase0[0xD] = { 0x66, 0x78, 0x5F, 0x77, 0x6F, 0x62, 0x62, 0x6C, 0x65, 0x6D, 0x61, 0x74, 0 }; /* const */

void HeatDistortPS::DrawParticle(HeatDistortPS::DistortParticle *arg1, Matrix *arg2) {
    f32 temp_f26_71;
    f32 temp_f27_73;
    f32 var_f3_64;
    M2C_STRUCT_COPY((s32) &arg_sp23C + 4, (s32) (arg2 - 4) + 4, 0x40);
    arg_sp240.Scale3x3((Matrix *) &arg_sp240, M2C_FIELD(arg1, f32 *, 0x50));
    arg_sp270 = M2C_FIELD(arg1, f32 *, 0);
    arg_sp274 = M2C_FIELD(arg1, f32 *, 4);
    arg_sp278 = M2C_FIELD(arg1, f32 *, 8);
    arg_sp27C = 1.0f;
    MKSetMatrix(*((Matrix *) &arg_sp200));
    MKSetMatrix(*((Matrix *) &arg_sp240));
    var_f3_64 = (M2C_FIELD(arg1, f32 *, 0x54) / M2C_FIELD(arg1, f32 *, 0x58)) - 0.5f;
    if (var_f3_64 < 0.0f) {
        var_f3_64 = -var_f3_64;
    }
    temp_f26_71 = -((2.0f * var_f3_64) - 1.0f);
    temp_f27_73 = _table_sinf(M2C_FIELD(arg1, f32 *, 0x34));
    arg_spF0 = _table_sinf(M2C_FIELD(arg1, f32 *, 0x30));
    arg_spF4 = temp_f27_73;
    arg_spF8 = 0.0f;
    arg_sp1D0 = (f64) arg_spF0;
    arg_sp1D8 = (f64) arg_spF8;
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
    arg_sp1E0 = arg_spE0;
    arg_spE8 = (f32) arg_sp1D8 * 12.5f;
    arg_sp1E8 = (f64) arg_spE8;
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f26 */);
    arg_sp48 = 0.0f;
    arg_sp1F0 = arg_spD0;
    arg_spD8 = (f32) arg_sp1E8 * temp_f26_71;
    arg_sp38 = 0.0f;
    arg_sp1F8 = (f64) arg_spD8;
    arg_sp40 = M2C_FIELD(arg1, f32 *, 0x20);
    arg_sp44 = M2C_FIELD(arg1, f32 *, 0x14);
    arg_sp30 = M2C_FIELD(arg1, f32 *, 0x10);
    arg_sp34 = M2C_FIELD(arg1, f32 *, 0x24);
    arg_sp280 = (f64) M2C_FIELD(arg1, f32 *, 0x10);
    arg_sp288 = M2C_FIELD(arg1, f64 *, 0x18);
    arg_sp1C0 = (f64) arg_sp40;
    arg_sp1C8 = (f64) arg_sp48;
    arg_sp290 = (f64) arg_sp40;
    arg_sp298 = (f64) arg_sp48;
    arg_sp1B0 = (f64) arg_sp30;
    arg_sp1B8 = (f64) arg_sp38;
    arg_sp2A0 = (f64) arg_sp30;
    arg_sp2A8 = (f64) arg_sp38;
    arg_sp2B0 = (f64) M2C_FIELD(arg1, f32 *, 0x20);
    arg_sp2B8 = M2C_FIELD(arg1, f64 *, 0x28);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $r31, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    arg_sp180 = arg_sp10;
    arg_sp18 = (f32) M2C_FIELD(arg1, f64 *, 0x28) - (f32) M2C_FIELD(arg1, f64 *, 0x18);
    arg_sp188 = (f64) arg_sp18;
    arg_sp190.operator*(0.5f);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    arg_sp1A0 = arg_sp20;
    arg_sp28 = (f32) M2C_FIELD(arg1, f64 *, 0x18) + arg_sp198;
    arg_sp2C0 = arg_sp20;
    arg_sp1A8 = (f64) arg_sp28;
    arg_sp2C8 = (f64) arg_sp28;
    MKBegin(4);
    arg_spC0 = 1.0f;
    arg_spC4 = 1.0f;
    arg_spC8 = 1.0f;
    arg_spCC = 0.0f;
    arg_sp170 = (f64) arg_spC0;
    arg_sp178 = (f64) arg_spC8;
    MKSetColorV(*((MKVector4 *) &arg_sp170));
    MKSetTexCoord1F((f32) arg_sp280, arg_sp284);
    MKSetPositionV(this->unk10);
    arg_spBC = temp_f26_71;
    arg_spB8 = 1.0f;
    arg_spB0 = 1.0f;
    arg_spB4 = 1.0f;
    arg_sp168 = (f64) arg_spB8;
    arg_sp160 = (f64) arg_spB0;
    MKSetColorV(*((MKVector4 *) &arg_sp160));
    MKSetTexCoord1F((f32) arg_sp2C0, arg_sp2C4);
    MKSetPositionV(*((MKVector3 *) &arg_sp1F0));
    arg_spA0 = 1.0f;
    arg_spA4 = 1.0f;
    arg_spA8 = 1.0f;
    arg_spAC = 0.0f;
    arg_sp150 = (f64) arg_spA0;
    arg_sp158 = (f64) arg_spA8;
    MKSetColorV(*((MKVector4 *) &arg_sp150));
    MKSetTexCoord1F((f32) arg_sp290, arg_sp294);
    MKSetPositionV(this->unk20);
    arg_sp90 = 1.0f;
    arg_sp94 = 1.0f;
    arg_sp98 = 1.0f;
    arg_sp9C = 0.0f;
    arg_sp140 = (f64) arg_sp90;
    arg_sp148 = (f64) arg_sp98;
    MKSetColorV(*((MKVector4 *) &arg_sp140));
    MKSetTexCoord1F((f32) arg_sp2B0, arg_sp2B4);
    MKSetPositionV(this->unk40);
    MKEnd();
    MKBegin(4);
    arg_sp80 = 1.0f;
    arg_sp84 = 1.0f;
    arg_sp88 = 1.0f;
    arg_sp8C = 0.0f;
    arg_sp130 = (f64) arg_sp80;
    arg_sp138 = (f64) arg_sp88;
    MKSetColorV(*((MKVector4 *) &arg_sp130));
    MKSetTexCoord1F((f32) arg_sp280, arg_sp284);
    MKSetPositionV(this->unk10);
    arg_sp7C = temp_f26_71;
    arg_sp78 = 1.0f;
    arg_sp70 = 1.0f;
    arg_sp74 = 1.0f;
    arg_sp128 = (f64) arg_sp78;
    arg_sp120 = (f64) arg_sp70;
    MKSetColorV(*((MKVector4 *) &arg_sp120));
    MKSetTexCoord1F((f32) arg_sp2C0, arg_sp2C4);
    MKSetPositionV(*((MKVector3 *) &arg_sp1F0));
    arg_sp60 = 1.0f;
    arg_sp64 = 1.0f;
    arg_sp68 = 1.0f;
    arg_sp6C = 0.0f;
    arg_sp110 = (f64) arg_sp60;
    arg_sp118 = (f64) arg_sp68;
    MKSetColorV(*((MKVector4 *) &arg_sp110));
    MKSetTexCoord1F((f32) arg_sp2A0, arg_sp2A4);
    MKSetPositionV(this->unk30);
    arg_sp50 = 1.0f;
    arg_sp54 = 1.0f;
    arg_sp58 = 1.0f;
    arg_sp5C = 0.0f;
    arg_sp100 = (f64) arg_sp50;
    arg_sp108 = (f64) arg_sp58;
    MKSetColorV(*((MKVector4 *) &arg_sp100));
    MKSetTexCoord1F((f32) arg_sp2B0, arg_sp2B4);
    MKSetPositionV(this->unk40);
    MKEnd();
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'MKHeap' to
void HeatDistortPS::Emit(const MKVector3 &arg0, const MKVector3 &arg1, float arg2, float arg3) {
    MKVector3 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    MKHeap *temp_r3_348;
    s32 var_ctr_346;
    s32 var_r30_345;
    void *temp_r3_402;
    void *temp_r6_361;
    void *temp_r6_372;

    if ((s32) this->unkC < 0x63) {
        var_r30_345 = 0;
        var_ctr_346 = 0x64;
loop_2:
        temp_r3_348 = this->unk4;
        if ((u8) *(temp_r3_348 + (var_r30_345 + 0x60)) == 0) {
            M2C_FIELD((temp_r3_348 + var_r30_345), s8 *, 0x60) = 1;
            temp_r6_361 = this->unk4 + var_r30_345;
            M2C_FIELD(temp_r6_361, f64 *, 0) = (f64) M2C_FIELD(&arg0, f64 *, 0);
            M2C_FIELD(temp_r6_361, f64 *, 8) = (f64) M2C_FIELD(&arg0, f64 *, 8);
            sp10 = 6.2831855f;
            temp_r6_372 = this->unk4 + (var_r30_345 + 0x40);
            M2C_FIELD(temp_r6_372, f64 *, 0) = (f64) M2C_FIELD(&arg1, f64 *, 0);
            M2C_FIELD(temp_r6_372, f64 *, 8) = (f64) M2C_FIELD(&arg1, f64 *, 8);
            sp20 = 0.0f;
            M2C_FIELD((this->unk4 + var_r30_345), f32 *, 0x50) = arg2;
            sp8 = 6.2831855f;
            M2C_FIELD((this->unk4 + var_r30_345), f32 *, 0x54) = arg3;
            spC = 6.2831855f;
            M2C_FIELD((this->unk4 + var_r30_345), f32 *, 0x58) = arg3;
            sp18 = 0.0f;
            sp1C = 0.0f;
            sp28 = (f64) sp8;
            sp30 = (f64) sp10;
            sp38 = (f64) sp18;
            sp40 = (f64) sp20;
            KDRand_Vector(sp48, *((MKVector3 *) &sp38));
            temp_r3_402 = this->unk4 + (var_r30_345 + 0x30);
            M2C_FIELD(temp_r3_402, f64 *, 0) = M2C_BITWISE(f64, sp48);
            M2C_FIELD(temp_r3_402, f64 *, 8) = (f64) sp48.unk8;
            *(this->unk8 + (this->unkC * 4)) = this->unk4 + var_r30_345;
            this->unkC += 1;
            return;
        }
        var_r30_345 += 0x70;
        var_ctr_346 -= 1;
        if (var_ctr_346 == 0) {

        } else {
            goto loop_2;
        }
    }
}
#endif

void HeatDistortPS::Deinit() {
    MKHeap *temp_r31_436;
    MKHeap *temp_r31_450;
    MKHeap *temp_r3_437;
    MKHeap *temp_r3_451;

    MKMaterial_Destroy(this->unk0);
    temp_r31_436 = this->unk8;
    temp_r3_437 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_437 != NULL) {
        ((MKHeap *) (temp_r3_437->Current()))->Free(temp_r31_436, NULL, 0);
    } else {
        free(temp_r31_436);
    }
    temp_r31_450 = this->unk4;
    temp_r3_451 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_451 != NULL) {
        ((MKHeap *) (temp_r3_451->Current()))->Free(temp_r31_450, NULL, 0);
        return;
    }
    free(temp_r31_450);
}

#if 0 // DRAFT: undefined identifier 'arg_sp9C'
void HeatDistortPS::Draw() {
    HeatDistortPS::DistortParticle *temp_r4_642;
    f32 temp_f11_553;
    f32 temp_f12_544;
    f32 temp_f13_540;
    f32 temp_f30_535;
    f32 temp_f3_580;
    f32 temp_f6_586;
    f32 temp_f7_550;
    f32 temp_f7_592;
    f32 temp_f9_551;
    s32 var_r29_509;
    s32 var_r29_637;
    s32 var_r30_510;
    s32 var_r30_638;
    void *temp_r6_533;
    M2C_STRUCT_COPY((s32) &arg_sp9C + 4, MKView_GetCameraMatrix() - 4 + 4, 0x40);
    M2C_STRUCT_COPY((s32) &arg_sp5C + 4, MKView_GetWorldToScreenMatrix() - 4 + 4, 0x40);
    var_r29_509 = 0;
    var_r30_510 = 0;
loop_2:
    if (var_r29_509 < (s32) this->unkC) {
        M2C_STRUCT_COPY((s32) &arg_spDC + 4, (s32) &arg_sp9C + 4, 0x40);
        arg_spE0.Scale3x3((Matrix *) &arg_spE0, M2C_FIELD(*(this->unk8 + var_r30_510), f32 *, 0x50));
        temp_r6_533 = *(this->unk8 + var_r30_510);
        temp_f30_535 = M2C_FIELD(temp_r6_533, f32 *, 0);
        arg_sp110 = temp_f30_535;
        temp_f13_540 = M2C_FIELD(temp_r6_533, f32 *, 4);
        arg_sp114 = temp_f13_540;
        temp_f12_544 = M2C_FIELD(temp_r6_533, f32 *, 8);
        arg_sp118 = temp_f12_544;
        arg_sp11C = 1.0f;
        temp_f7_550 = this->unk10.unk4;
        temp_f9_551 = this->unk10.unk0;
        temp_f11_553 = this->unk10.unk8;
        arg_sp20 = temp_f30_535 + ((temp_f11_553 * arg_sp100) + ((temp_f9_551 * arg_spE0) + (temp_f7_550 * arg_spF0)));
        arg_sp24 = temp_f13_540 + ((temp_f11_553 * arg_sp104) + ((temp_f9_551 * arg_spE4) + (temp_f7_550 * arg_spF4)));
        arg_sp28 = temp_f12_544 + ((temp_f11_553 * arg_sp108) + ((temp_f9_551 * arg_spE8) + (temp_f7_550 * arg_spF8)));
        arg_sp40 = (f64) arg_sp20;
        arg_sp48 = (f64) arg_sp28;
        arg_sp50 = (f64) arg_sp20;
        arg_sp58 = (f64) arg_sp28;
        M2C_FIELD(*(this->unk8 + var_r30_510), f32 *, 0x5C) = Xform3D2D(temp_r6_533 + 0x10, *((MKVector3 *) &arg_sp50), (Matrix *) &arg_sp60);
        temp_f3_580 = this->unk40.unk4;
        temp_f6_586 = this->unk40.unk0;
        temp_f7_592 = this->unk40.unk8;
        arg_sp10 = arg_sp110 + ((temp_f7_592 * arg_sp100) + ((temp_f6_586 * arg_spE0) + (temp_f3_580 * arg_spF0)));
        arg_sp14 = arg_sp114 + ((temp_f7_592 * arg_sp104) + ((temp_f6_586 * arg_spE4) + (temp_f3_580 * arg_spF4)));
        arg_sp18 = arg_sp118 + ((temp_f7_592 * arg_sp108) + ((temp_f6_586 * arg_spE8) + (temp_f3_580 * arg_spF8)));
        arg_sp50 = (f64) arg_sp10;
        arg_sp58 = (f64) arg_sp18;
        arg_sp30 = (f64) arg_sp10;
        arg_sp38 = (f64) arg_sp18;
        Xform3D2D(*(this->unk8 + var_r30_510) + 0x20, *((MKVector3 *) &arg_sp50), (Matrix *) &arg_sp60);
        var_r29_509 += 1;
        var_r30_510 += 4;
        goto loop_2;
    }
    qsort(this->unk8, 4, DistortParticleCompare);
    MKMaterial_SetMaterial(this->unk0);
    MKPrimitive(0xC, 0x10);
    var_r29_637 = 0;
    var_r30_638 = 0;
loop_7:
    if (var_r29_637 < (s32) this->unkC) {
        temp_r4_642 = *(this->unk8 + var_r30_638);
        if (M2C_FIELD(temp_r4_642, f32 *, 0x5C) > 800.0f) {
            DrawParticle(temp_r4_642, (Matrix *) &arg_spA0);
        }
        var_r29_637 += 1;
        var_r30_638 += 4;
        goto loop_7;
    }
    MKEndPrimitive();
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'MKHeap' to
void HeatDistortPS::Update() {
    f64 sp60;
    f64 sp58;
    MKVector3 sp48;
    M2C_UNK sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp10;
    MKHeap *temp_r5_727;
    f32 temp_f27_743;
    f32 temp_f28_690;
    f32 temp_f2_700;
    f32 var_f0_701;
    s32 temp_r31_696;
    s32 temp_r3_723;
    s32 var_r30_692;
    void *temp_r3_698;
    void *temp_r3_767;
    void *temp_r3_781;
    void *temp_r3_804;
    void *temp_r4_717;

    temp_f28_690 = (f32) pow(0.75, gUpdateTimeDelta);
    var_r30_692 = 0;
loop_11:
    if (var_r30_692 < (s32) this->unkC) {
        temp_r31_696 = var_r30_692 * 4;
        temp_r3_698 = *(this->unk8 + temp_r31_696);
        temp_f2_700 = M2C_FIELD(temp_r3_698, f32 *, 0x58);
        var_f0_701 = M2C_FIELD(temp_r3_698, f32 *, 0x54) - gUpdateTimeDelta;
        if (var_f0_701 < temp_f2_700) {

        } else {
            var_f0_701 = temp_f2_700;
        }
        if (var_f0_701 > 0.0f) {

        } else {
            var_f0_701 = 0.0f;
        }
        M2C_FIELD(temp_r3_698, f32 *, 0x54) = var_f0_701;
        temp_r4_717 = *(this->unk8 + temp_r31_696);
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if (M2C_FIELD(temp_r4_717, f32 *, 0x54) == 0.0f) {
            temp_r3_723 = var_r30_692 + 1;
            M2C_FIELD(temp_r4_717, s8 *, 0x60) = 0;
            temp_r5_727 = this->unk8;
            memcpy(temp_r5_727 + temp_r31_696, temp_r5_727 + (temp_r3_723 * 4), (this->unkC - temp_r3_723) * 4);
            var_r30_692 -= 1;
            this->unkC -= 1;
        } else {
            temp_f27_743 = MKRand_Float(&gViewSeed, 6.2831855f, 6.2831855f);
            MKVector(MKRand_Float(&gViewSeed, 3.1415927f, 3.1415927f), temp_f27_743, 0.0f);
            sp48.operator*(gUpdateTimeDelta);
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
            sp58 = sp18;
            temp_r3_767 = *(this->unk8 + temp_r31_696) + 0x30;
            sp20 = sp48.unk8 * 1.0f;
            sp60 = (f64) sp20;
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r3, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            M2C_ERROR(/* unknown instruction: psq_stx $f0, $zero, $r3, 0x0, qr0 */);
            M2C_FIELD(temp_r3_767, f32 *, 8) = (f32) (M2C_FIELD(temp_r3_767, f32 *, 8) + (f32) sp60);
            temp_r3_781 = *(this->unk8 + temp_r31_696);
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r4, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
            sp28 = sp8;
            sp10 = M2C_FIELD(temp_r3_781, f32 *, 0x48) * gUpdateTimeDelta;
            sp30 = (f64) sp10;
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r3, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            M2C_ERROR(/* unknown instruction: psq_stx $f0, $zero, $r3, 0x0, qr0 */);
            M2C_FIELD(temp_r3_781, f32 *, 8) = (f32) (M2C_FIELD(temp_r3_781, f32 *, 8) + (f32) sp30);
            temp_r3_804 = *(this->unk8 + temp_r31_696) + 0x40;
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r3, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f28 */);
            M2C_ERROR(/* unknown instruction: psq_stx $f0, $zero, $r3, 0x0, qr0 */);
            M2C_FIELD(temp_r3_804, f32 *, 8) = (f32) (M2C_FIELD(temp_r3_804, f32 *, 8) * temp_f28_690);
        }
        var_r30_692 += 1;
        goto loop_11;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_stringBase0'
void HeatDistortPS::Init() {
    f64 sp1C0;
    f64 sp1B8;
    f64 sp1B0;
    f64 sp1A8;
    f64 sp1A0;
    f64 sp198;
    MKVector3 sp188;
    MKVector3 sp178;
    f64 sp170;
    f64 sp168;
    f64 sp160;
    f64 sp158;
    MKVector3 sp148;
    MKVector3 sp138;
    f64 sp130;
    f64 sp128;
    MKVector3 sp118;
    f64 sp110;
    f64 sp108;
    MKVector3 spF8;
    f64 spF0;
    f64 spE8;
    f64 spE0;
    f64 spD8;
    MKVector3 spC8;
    f64 spC0;
    f64 spB8;
    MKVector3 spA8;
    f32 spA0;
    f32 sp9C;
    f32 sp98;
    f32 sp90;
    f32 sp8C;
    f32 sp88;
    f32 sp80;
    f32 sp70;
    f32 sp60;
    f32 sp50;
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
    MKHeap *temp_r3_1010;
    MKHeap *temp_r3_1024;
    MKHeap *var_r3_1017;
    MKHeap *var_r3_1031;
    MKResource *temp_r3_844;
    s32 temp_r0_1045;
    s32 var_ctr_1042;
    s32 var_r3_1040;

    temp_r3_844 = MKMaterial_Create(lit_stringBase0);
    sp90 = 0.0f;
    this->unk0 = (MKMaterial *) temp_r3_844;
    sp88 = 1.0f;
    sp8C = 0.0f;
    sp1B0 = (f64) sp90;
    sp1A8 = (f64) sp88;
    spA0 = 0.0f;
    sp40 = -(f32) sp1B0;
    sp98 = 0.0f;
    sp9C = 1.0f;
    sp38 = -(f32) sp1A8;
    sp3C = -unksp1AC;
    sp1B8 = (f64) sp98;
    sp1C0 = (f64) spA0;
    sp168 = (f64) sp38;
    sp170 = (f64) sp40;
    sp178.operator*(50.0f);
    sp188.operator*(50.0f);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    M2C_FIELD(this, f64 *, 0x10) = sp78;
    sp80 = sp188.unk8 + sp178.unk8;
    sp198 = sp78;
    sp1A0 = (f64) sp80;
    M2C_FIELD(this, f64 *, 0x18) = (f64) sp80;
    sp138.operator*(50.0f);
    sp148.operator*(50.0f);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    M2C_FIELD(this, f64 *, 0x20) = sp68;
    sp70 = sp148.unk8 + sp138.unk8;
    sp158 = sp68;
    M2C_FIELD(this, f64 *, 0x28) = (f64) sp70;
    sp160 = (f64) sp70;
    sp28 = -(f32) sp1A8;
    sp2C = -unksp1AC;
    sp30 = -(f32) sp1B0;
    spE8 = (f64) sp28;
    spF0 = (f64) sp30;
    spF8.operator*(50.0f);
    sp18 = -(f32) sp1B8;
    sp1C = -unksp1BC;
    sp20 = -(f32) sp1C0;
    sp108 = (f64) sp18;
    sp110 = (f64) sp20;
    sp118.operator*(50.0f);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    M2C_FIELD(this, f64 *, 0x30) = sp58;
    sp60 = sp118.unk8 + spF8.unk8;
    sp128 = sp58;
    sp130 = (f64) sp60;
    M2C_FIELD(this, f64 *, 0x38) = (f64) sp60;
    spA8.operator*(50.0f);
    sp8 = -(f32) sp1B8;
    spC = -unksp1BC;
    sp10 = -(f32) sp1C0;
    spB8 = (f64) sp8;
    spC0 = (f64) sp10;
    spC8.operator*(50.0f);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    M2C_FIELD(this, f64 *, 0x40) = sp48;
    sp50 = spC8.unk8 + spA8.unk8;
    spD8 = sp48;
    M2C_FIELD(this, f64 *, 0x48) = (f64) sp50;
    this->unk50 = 0.0f;
    this->unk54 = 0.0f;
    spE0 = (f64) sp50;
    this->unk58 = 0.0f;
    temp_r3_1010 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_1010 != NULL) {
        var_r3_1017 = ((MKHeap *) (temp_r3_1010->Current()))->Alloc(0x2BC0, NULL, 0);
    } else {
        var_r3_1017 = malloc(0x2BC0);
    }
    this->unk4 = var_r3_1017;
    temp_r3_1024 = var_r3_1017->Current();
    if (temp_r3_1024 != NULL) {
        var_r3_1031 = ((MKHeap *) (temp_r3_1024->Current()))->Alloc(0x190, NULL, 0);
    } else {
        var_r3_1031 = malloc(0x190);
    }
    this->unk8 = var_r3_1031;
    var_r3_1040 = 0;
    this->unkC = 0;
    var_ctr_1042 = 0x64;
    do {
        temp_r0_1045 = var_r3_1040 + 0x60;
        var_r3_1040 += 0x70;
        *(this->unk4 + temp_r0_1045) = 0;
        var_ctr_1042 -= 1;
    } while (var_ctr_1042 != 0);
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'const void' to
s32 DistortParticleCompare(const void *arg0, const void *arg1) {
    return -(s32) (M2C_FIELD(*arg0, f32 *, 0x5C) - M2C_FIELD(*arg1, f32 *, 0x5C));
}
#endif
