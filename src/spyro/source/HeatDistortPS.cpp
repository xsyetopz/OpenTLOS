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

#if 0 // DRAFT: function call 'memcpy(long, long, int)' does not match
void HeatDistortPS::DrawParticle(HeatDistortPS::DistortParticle *arg1, Matrix *arg2) {
    f64 sp2C8;
    f64 sp2C0;
    f64 sp2B8;
    f64 sp2B0;
    f64 sp2A8;
    f64 sp2A0;
    f64 sp298;
    f64 sp290;
    f64 sp288;
    f64 sp280;
    Matrix sp240;
    Matrix sp200;
    f64 sp1F8;
    f64 sp1F0;
    f64 sp1E8;
    f64 sp1E0;
    f64 sp1D8;
    f64 sp1D0;
    f64 sp1C8;
    f64 sp1C0;
    f64 sp1B8;
    f64 sp1B0;
    f64 sp1A8;
    f64 sp1A0;
    MKVector3 sp190;
    f64 sp188;
    f64 sp180;
    f64 sp178;
    f64 sp170;
    f64 sp168;
    f64 sp160;
    f64 sp158;
    f64 sp150;
    f64 sp148;
    f64 sp140;
    f64 sp138;
    f64 sp130;
    f64 sp128;
    f64 sp120;
    f64 sp118;
    f64 sp110;
    f64 sp108;
    f64 sp100;
    f32 spF8;
    f32 spF4;
    f32 spF0;
    f32 spE8;
    f64 spE0;
    f32 spD8;
    f64 spD0;
    f32 spCC;
    f32 spC8;
    f32 spC4;
    f32 spC0;
    f32 spBC;
    f32 spB8;
    f32 spB4;
    f32 spB0;
    f32 spAC;
    f32 spA8;
    f32 spA4;
    f32 spA0;
    f32 sp9C;
    f32 sp98;
    f32 sp94;
    f32 sp90;
    f32 sp8C;
    f32 sp88;
    f32 sp84;
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    f32 sp74;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp5C;
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
    f64 sp20;
    f32 sp18;
    f64 sp10;
    f32 temp_f26_71;
    f32 temp_f27_73;
    f32 var_f3_64;
    f64 temp_f0_139;
    f64 temp_f0_86;
    f64 temp_f0_96;

    M2C_STRUCT_COPY((s32) &sp200.unk3C + 4, (s32) (arg2 - 4) + 4, 0x40);
    sp240.Scale3x3(&sp240, M2C_FIELD(arg1, f32 *, 0x50));
    sp240.unk30 = M2C_FIELD(arg1, f32 *, 0);
    sp240.unk34 = M2C_FIELD(arg1, f32 *, 4);
    sp240.unk38 = M2C_FIELD(arg1, f32 *, 8);
    sp240.unk3C = 1.0f;
    MKSetMatrix(sp200);
    MKSetMatrix(sp240);
    var_f3_64 = (M2C_FIELD(arg1, f32 *, 0x54) / M2C_FIELD(arg1, f32 *, 0x58)) - 0.5f;
    if (var_f3_64 < 0.0f) {
        var_f3_64 = -var_f3_64;
    }
    temp_f26_71 = -((2.0f * var_f3_64) - 1.0f);
    temp_f27_73 = _table_sinf(M2C_FIELD(arg1, f32 *, 0x34));
    spF0 = _table_sinf(M2C_FIELD(arg1, f32 *, 0x30));
    spF4 = temp_f27_73;
    spF8 = 0.0f;
    sp1D0 = (f64) spF0;
    sp1D8 = (f64) spF8;
    temp_f0_86 = sp1D0 * 5.41119288e-315;
    spE0 = temp_f0_86;
    sp1E0 = temp_f0_86;
    spE8 = (f32) sp1D8 * 12.5f;
    sp1E8 = (f64) spE8;
    temp_f0_96 = temp_f0_86 * (f64) temp_f26_71;
    spD0 = temp_f0_96;
    sp48 = 0.0f;
    sp1F0 = temp_f0_96;
    spD8 = (f32) sp1E8 * temp_f26_71;
    sp38 = 0.0f;
    sp1F8 = (f64) spD8;
    sp40 = M2C_FIELD(arg1, f32 *, 0x20);
    sp44 = M2C_FIELD(arg1, f32 *, 0x14);
    sp30 = M2C_FIELD(arg1, f32 *, 0x10);
    sp34 = M2C_FIELD(arg1, f32 *, 0x24);
    sp280 = (f64) M2C_FIELD(arg1, f32 *, 0x10);
    sp288 = M2C_FIELD(arg1, f64 *, 0x18);
    sp1C0 = (f64) sp40;
    sp1C8 = (f64) sp48;
    sp290 = (f64) sp40;
    sp298 = (f64) sp48;
    sp1B0 = (f64) sp30;
    sp1B8 = (f64) sp38;
    sp2A0 = (f64) sp30;
    sp2A8 = (f64) sp38;
    sp2B0 = (f64) M2C_FIELD(arg1, f32 *, 0x20);
    sp2B8 = M2C_FIELD(arg1, f64 *, 0x28);
    temp_f0_139 = (f64) M2C_FIELD(arg1, f32 *, 0x20) - (f64) M2C_FIELD(arg1, f32 *, 0x10);
    sp10 = temp_f0_139;
    sp180 = temp_f0_139;
    sp18 = (f32) M2C_FIELD(arg1, f64 *, 0x28) - (f32) M2C_FIELD(arg1, f64 *, 0x18);
    sp188 = (f64) sp18;
    sp190.operator*(0.5f);
    sp20 = (f64) M2C_FIELD(arg1, f32 *, 0x10) + M2C_BITWISE(f64, sp190);
    sp1A0 = sp20;
    sp28 = (f32) M2C_FIELD(arg1, f64 *, 0x18) + sp190.unk8;
    sp2C0 = sp20;
    sp1A8 = (f64) sp28;
    sp2C8 = (f64) sp28;
    MKBegin(4);
    spC0 = 1.0f;
    spC4 = 1.0f;
    spC8 = 1.0f;
    spCC = 0.0f;
    sp170 = (f64) spC0;
    sp178 = (f64) spC8;
    MKSetColorV(*((MKVector4 *) &sp170));
    MKSetTexCoord1F((f32) sp280, (*(f32 *) ((u8 *) &sp280 + 0x4)));
    MKSetPositionV(this->unk10);
    spBC = temp_f26_71;
    spB8 = 1.0f;
    spB0 = 1.0f;
    spB4 = 1.0f;
    sp168 = (f64) spB8;
    sp160 = (f64) spB0;
    MKSetColorV(*((MKVector4 *) &sp160));
    MKSetTexCoord1F((f32) sp2C0, (*(f32 *) ((u8 *) &sp2C0 + 0x4)));
    MKSetPositionV(*((MKVector3 *) &sp1F0));
    spA0 = 1.0f;
    spA4 = 1.0f;
    spA8 = 1.0f;
    spAC = 0.0f;
    sp150 = (f64) spA0;
    sp158 = (f64) spA8;
    MKSetColorV(*((MKVector4 *) &sp150));
    MKSetTexCoord1F((f32) sp290, (*(f32 *) ((u8 *) &sp290 + 0x4)));
    MKSetPositionV(this->unk20);
    sp90 = 1.0f;
    sp94 = 1.0f;
    sp98 = 1.0f;
    sp9C = 0.0f;
    sp140 = (f64) sp90;
    sp148 = (f64) sp98;
    MKSetColorV(*((MKVector4 *) &sp140));
    MKSetTexCoord1F((f32) sp2B0, (*(f32 *) ((u8 *) &sp2B0 + 0x4)));
    MKSetPositionV(this->unk40);
    MKEnd();
    MKBegin(4);
    sp80 = 1.0f;
    sp84 = 1.0f;
    sp88 = 1.0f;
    sp8C = 0.0f;
    sp130 = (f64) sp80;
    sp138 = (f64) sp88;
    MKSetColorV(*((MKVector4 *) &sp130));
    MKSetTexCoord1F((f32) sp280, (*(f32 *) ((u8 *) &sp280 + 0x4)));
    MKSetPositionV(this->unk10);
    sp7C = temp_f26_71;
    sp78 = 1.0f;
    sp70 = 1.0f;
    sp74 = 1.0f;
    sp128 = (f64) sp78;
    sp120 = (f64) sp70;
    MKSetColorV(*((MKVector4 *) &sp120));
    MKSetTexCoord1F((f32) sp2C0, (*(f32 *) ((u8 *) &sp2C0 + 0x4)));
    MKSetPositionV(*((MKVector3 *) &sp1F0));
    sp60 = 1.0f;
    sp64 = 1.0f;
    sp68 = 1.0f;
    sp6C = 0.0f;
    sp110 = (f64) sp60;
    sp118 = (f64) sp68;
    MKSetColorV(*((MKVector4 *) &sp110));
    MKSetTexCoord1F((f32) sp2A0, (*(f32 *) ((u8 *) &sp2A0 + 0x4)));
    MKSetPositionV(this->unk30);
    sp50 = 1.0f;
    sp54 = 1.0f;
    sp58 = 1.0f;
    sp5C = 0.0f;
    sp100 = (f64) sp50;
    sp108 = (f64) sp58;
    MKSetColorV(*((MKVector4 *) &sp100));
    MKSetTexCoord1F((f32) sp2B0, (*(f32 *) ((u8 *) &sp2B0 + 0x4)));
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

#if 0 // DRAFT: function call 'memcpy(long, Matrix *, int)' does not match
void HeatDistortPS::Draw() {
    Matrix spE0;
    Matrix spA0;
    Matrix sp60;
    M2C_UNK sp5C;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
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

    M2C_STRUCT_COPY((s32) &sp60.unk3C + 4, MKView_GetCameraMatrix() - 4 + 4, 0x40);
    M2C_STRUCT_COPY((s32) &sp5C + 4, MKView_GetWorldToScreenMatrix() - 4 + 4, 0x40);
    var_r29_509 = 0;
    var_r30_510 = 0;
loop_2:
    if (var_r29_509 < (s32) this->unkC) {
        M2C_STRUCT_COPY((s32) &spA0.unk3C + 4, (s32) &sp60.unk3C + 4, 0x40);
        spE0.Scale3x3(&spE0, M2C_FIELD(*(this->unk8 + var_r30_510), f32 *, 0x50));
        temp_r6_533 = *(this->unk8 + var_r30_510);
        temp_f30_535 = M2C_FIELD(temp_r6_533, f32 *, 0);
        spE0.unk30 = temp_f30_535;
        temp_f13_540 = M2C_FIELD(temp_r6_533, f32 *, 4);
        spE0.unk34 = temp_f13_540;
        temp_f12_544 = M2C_FIELD(temp_r6_533, f32 *, 8);
        spE0.unk38 = temp_f12_544;
        spE0.unk3C = 1.0f;
        temp_f7_550 = this->unk10.unk4;
        temp_f9_551 = this->unk10.unk0;
        temp_f11_553 = this->unk10.unk8;
        sp20 = temp_f30_535 + ((temp_f11_553 * spE0.unk20) + ((temp_f9_551 * M2C_BITWISE(f32, spE0)) + (temp_f7_550 * spE0.unk10)));
        sp24 = temp_f13_540 + ((temp_f11_553 * spE0.unk24) + ((temp_f9_551 * spE0.unk4) + (temp_f7_550 * spE0.unk14)));
        sp28 = temp_f12_544 + ((temp_f11_553 * spE0.unk28) + ((temp_f9_551 * spE0.unk8) + (temp_f7_550 * spE0.unk18)));
        sp40 = (f64) sp20;
        sp48 = (f64) sp28;
        sp50 = (f64) sp20;
        sp58 = (f64) sp28;
        M2C_FIELD(*(this->unk8 + var_r30_510), f32 *, 0x5C) = Xform3D2D(((u8 *) temp_r6_533) + 0x10, *((MKVector3 *) &sp50), &sp60);
        temp_f3_580 = this->unk40.unk4;
        temp_f6_586 = this->unk40.unk0;
        temp_f7_592 = this->unk40.unk8;
        sp10 = spE0.unk30 + ((temp_f7_592 * spE0.unk20) + ((temp_f6_586 * M2C_BITWISE(f32, spE0)) + (temp_f3_580 * spE0.unk10)));
        sp14 = spE0.unk34 + ((temp_f7_592 * spE0.unk24) + ((temp_f6_586 * spE0.unk4) + (temp_f3_580 * spE0.unk14)));
        sp18 = spE0.unk38 + ((temp_f7_592 * spE0.unk28) + ((temp_f6_586 * spE0.unk8) + (temp_f3_580 * spE0.unk18)));
        sp50 = (f64) sp10;
        sp58 = (f64) sp18;
        sp30 = (f64) sp10;
        sp38 = (f64) sp18;
        Xform3D2D(*(this->unk8 + var_r30_510) + 0x20, *((MKVector3 *) &sp50), &sp60);
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
            DrawParticle(temp_r4_642, &spA0);
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
    f64 sp18;
    f32 sp10;
    f64 sp8;
    MKHeap *temp_r5_727;
    f32 temp_f27_743;
    f32 temp_f28_690;
    f32 temp_f2_700;
    f32 var_f0_701;
    f64 temp_f0_759;
    f64 temp_f0_785;
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
        if (M2C_FIELD(temp_r4_717, f32 *, 0x54) <= 0.0f) {
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
            temp_f0_759 = sp48 * 5.263544247e-315;
            sp18 = temp_f0_759;
            sp58 = temp_f0_759;
            temp_r3_767 = *(this->unk8 + temp_r31_696) + 0x30;
            sp20 = sp48.unk8 * 1.0f;
            sp60 = (f64) sp20;
            M2C_FIELD(temp_r3_767, f64 *, 0) = (f64) (M2C_FIELD(temp_r3_767, f64 *, 0) + temp_f0_759);
            M2C_FIELD(temp_r3_767, f32 *, 8) = (f32) (M2C_FIELD(temp_r3_767, f32 *, 8) + (f32) sp60);
            temp_r3_781 = *(this->unk8 + temp_r31_696);
            temp_f0_785 = *(temp_r3_781 + 0x40) * (f64) gUpdateTimeDelta;
            sp8 = temp_f0_785;
            sp28 = temp_f0_785;
            sp10 = M2C_FIELD(temp_r3_781, f32 *, 0x48) * gUpdateTimeDelta;
            sp30 = (f64) sp10;
            M2C_FIELD(temp_r3_781, f64 *, 0) = (f64) (M2C_FIELD(temp_r3_781, f64 *, 0) + temp_f0_785);
            M2C_FIELD(temp_r3_781, f32 *, 8) = (f32) (M2C_FIELD(temp_r3_781, f32 *, 8) + (f32) sp30);
            temp_r3_804 = *(this->unk8 + temp_r31_696) + 0x40;
            M2C_FIELD(temp_r3_804, f64 *, 0) = (f64) (M2C_FIELD(temp_r3_804, f64 *, 0) * (f64) temp_f28_690);
            M2C_FIELD(temp_r3_804, f32 *, 8) = (f32) (M2C_FIELD(temp_r3_804, f32 *, 8) * temp_f28_690);
        }
        var_r30_692 += 1;
        goto loop_11;
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to
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
    f64 sp78;
    f32 sp70;
    f64 sp68;
    f32 sp60;
    f64 sp58;
    f32 sp50;
    f64 sp48;
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
    f64 temp_f0_909;
    s32 temp_r0_1045;
    s32 var_ctr_1042;
    s32 var_r3_1040;

    temp_r3_844 = MKMaterial_Create("fx_wobblemat");
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
    sp3C = -(*(f32 *) ((u8 *) &sp1A8 + 0x4));
    sp1B8 = (f64) sp98;
    sp1C0 = (f64) spA0;
    sp168 = (f64) sp38;
    sp170 = (f64) sp40;
    sp178.operator*(50.0f);
    sp188.operator*(50.0f);
    sp78 = sp188 + M2C_BITWISE(f64, sp178);
    M2C_FIELD(this, f64 *, 0x10) = sp78;
    sp80 = sp188.unk8 + sp178.unk8;
    sp198 = sp78;
    sp1A0 = (f64) sp80;
    M2C_FIELD(this, f64 *, 0x18) = (f64) sp80;
    sp138.operator*(50.0f);
    sp148.operator*(50.0f);
    temp_f0_909 = sp148 + M2C_BITWISE(f64, sp138);
    sp68 = temp_f0_909;
    M2C_FIELD(this, f64 *, 0x20) = temp_f0_909;
    sp70 = sp148.unk8 + sp138.unk8;
    sp158 = temp_f0_909;
    M2C_FIELD(this, f64 *, 0x28) = (f64) sp70;
    sp160 = (f64) sp70;
    sp28 = -(f32) sp1A8;
    sp2C = -(*(f32 *) ((u8 *) &sp1A8 + 0x4));
    sp30 = -(f32) sp1B0;
    spE8 = (f64) sp28;
    spF0 = (f64) sp30;
    spF8.operator*(50.0f);
    sp18 = -(f32) sp1B8;
    sp1C = -(*(f32 *) ((u8 *) &sp1B8 + 0x4));
    sp20 = -(f32) sp1C0;
    sp108 = (f64) sp18;
    sp110 = (f64) sp20;
    sp118.operator*(50.0f);
    sp58 = sp118 + M2C_BITWISE(f64, spF8);
    M2C_FIELD(this, f64 *, 0x30) = sp58;
    sp60 = sp118.unk8 + spF8.unk8;
    sp128 = sp58;
    sp130 = (f64) sp60;
    M2C_FIELD(this, f64 *, 0x38) = (f64) sp60;
    spA8.operator*(50.0f);
    sp8 = -(f32) sp1B8;
    spC = -(*(f32 *) ((u8 *) &sp1B8 + 0x4));
    sp10 = -(f32) sp1C0;
    spB8 = (f64) sp8;
    spC0 = (f64) sp10;
    spC8.operator*(50.0f);
    sp48 = spC8 + M2C_BITWISE(f64, spA8);
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
