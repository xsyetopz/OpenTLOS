#include "spyro/source/ScreenWobbleFX.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "spyro/source/Tools.h"
#include "common/Source/MKShape.h"
#include "common/Source/MKView.h"
#include "common/Source/StdMath.h"
#include "common/gc/MKMaterial_GC.h"
#include "common/gc/MKPrimitive_GC.h"
#include "spyro/source/KDRandom.h"
#include <m2c_macros.h>

M2C_UNK free(void *);                               /* extern */
void *malloc(M2C_UNK);                              /* extern */
extern f32 gUpdateTimeDelta;

void ScreenWobbleFX::SetMotionBlurCapEnable(bool arg0) {
    if (arg0 != 0) {
        this->unk64 += 1;
        this->unk60 = 1;
        return;
    }
    this->unk64 -= 1;
    if ((s32) this->unk64 <= 0) {
        this->unk60 = 0;
        this->unk64 = 0;
    }
}

void ScreenWobbleFX::GetMotionBlurCap() {

}

void ScreenWobbleFX::SetSpeedEffectCenter(const MKVector3 &arg0) {
    this->unk28 = M2C_FIELD(&arg0, f64 *, 0);
    this->unk30 = M2C_FIELD(&arg0, f64 *, 8);
}

void ScreenWobbleFX::EnableSpeedEffect(bool arg0, float arg1, float arg2) {
    if ((u8) this->unk20 != arg0) {
        this->unk20 = arg0;
        this->unk24 = 1.0f;
        if (arg0 != 0) {
            this->unk38 = 1;
            this->unk3C = arg1;
            this->unk40 = arg2;
            SetMotionBlurCapEnable(1U);
            this->unk68 = 0;
        }
    }
}

void ScreenWobbleFX::DrawSpeedEffect() {
    if ((u8) this->unk20 == 0) {

    }
}

#if 0 // DRAFT: function call 'operator*(float, MKVector3)' does not match
void ScreenWobbleFX::AddRandomWobbleForce(float arg0) {
    MKVector3 sp58;
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
    s32 var_r29_113;
    s32 var_r30_109;
    s32 var_r31_111;
    void *temp_r3_141;

    var_r30_109 = 0;
    var_r31_111 = 0;
    do {
        var_r29_113 = 0;
loop_2:
        sp10 = 0.0f;
        sp20 = 0.0f;
        sp8 = 1.0f;
        spC = 1.0f;
        sp18 = -1.0f;
        sp1C = -1.0f;
        sp28 = (f64) sp8;
        sp30 = (f64) sp10;
        sp38 = (f64) sp18;
        sp40 = (f64) sp20;
        KDRand_Vector(sp48, *((MKVector3 *) &sp38));
        __ml(gUpdateTimeDelta, sp58);
        temp_r3_141 = this->unk0 + (((var_r29_113 + var_r31_111) * 0x38) + 0x20);
        M2C_FIELD(temp_r3_141, f64 *, 0) = (f64) (M2C_FIELD(temp_r3_141, f64 *, 0) + M2C_BITWISE(f64, sp58));
        var_r29_113 += 1;
        M2C_FIELD(temp_r3_141, f32 *, 8) = (f32) (M2C_FIELD(temp_r3_141, f32 *, 8) + sp58.unk8);
        if (var_r29_113 < 0xF) {
            goto loop_2;
        }
        var_r30_109 += 1;
        var_r31_111 += 0xF;
    } while (var_r30_109 < 0xF);
}
#endif

#if 0 // DRAFT: illegal type
void ScreenWobbleFX::InitWobbleNodes() {
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
    s32 temp_r11_190;
    s32 var_ctr_185;
    s32 var_r12_174;
    s32 var_r31_184;
    s32 var_r4_176;
    void *temp_r6_230;
    void *temp_r8_195;
    void *temp_r8_224;

    var_r12_174 = 0;
    var_r4_176 = 0;
    do {
        var_r31_184 = 0;
        var_ctr_185 = 0xF;
loop_2:
        temp_r11_190 = (var_r31_184 + var_r4_176) * 0x38;
        temp_r8_195 = this->unk0 + temp_r11_190;
        sp20 = 0.0f;
        sp10 = 0.0f;
        sp8 = 0.0f;
        sp18 = (f32) var_r31_184 / 14.0f;
        spC = 0.0f;
        sp40 = (f64) sp20;
        sp28 = (f64) sp8;
        sp30 = (f64) sp10;
        sp1C = (f32) var_r12_174 / 14.0f;
        M2C_FIELD(temp_r8_195, f64 *, 0) = (f64) sp18;
        M2C_FIELD(temp_r8_195, f64 *, 8) = (f64) sp20;
        sp38 = (f64) sp18;
        temp_r8_224 = this->unk0 + temp_r11_190;
        M2C_FIELD(temp_r8_224, f64 *, 0x10) = (f64) M2C_FIELD(temp_r8_224, f64 *, 0);
        M2C_FIELD(temp_r8_224, f64 *, 0x18) = (f64) M2C_FIELD(temp_r8_224, f64 *, 8);
        temp_r6_230 = this->unk0 + (temp_r11_190 + 0x20);
        M2C_FIELD(temp_r6_230, f64 *, 0) = (f64) sp8;
        M2C_FIELD(temp_r6_230, f64 *, 8) = (f64) sp10;
        *(this->unk0 + (temp_r11_190 + 0x30)) = 0;
        *(this->unk0 + (temp_r11_190 + 0x34)) = 0.0f;
        if ((var_r31_184 == 0) || (var_r12_174 == 0) || (var_r31_184 == 0xE) || (var_r12_174 == 0xE)) {
            *(this->unk0 + (temp_r11_190 + 0x30)) = 1;
        }
        var_r31_184 += 1;
        var_ctr_185 -= 1;
        if (var_ctr_185 != 0) {
            goto loop_2;
        }
        var_r12_174 += 1;
        var_r4_176 += 0xF;
    } while (var_r12_174 < 0xF);
}
#endif

void ScreenWobbleFX::Deinit() {
    MKHeap *temp_r3_291;
    MKMaterial *temp_r3_269;
    MKMaterial *temp_r3_276;
    MKMaterial *temp_r3_283;
    void *temp_r31_290;

    temp_r3_269 = this->unk5C;
    if (temp_r3_269 != NULL) {
        MKMaterial_Destroy(temp_r3_269);
        this->unk5C = NULL;
    }
    temp_r3_276 = this->unkC;
    if (temp_r3_276 != NULL) {
        MKMaterial_Destroy(temp_r3_276);
        this->unkC = NULL;
    }
    temp_r3_283 = this->unk1C;
    if (temp_r3_283 != NULL) {
        MKMaterial_Destroy(temp_r3_283);
        this->unk1C = NULL;
    }
    temp_r31_290 = this->unk0;
    temp_r3_291 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_291 != NULL) {
        ((MKHeap *) (temp_r3_291->Current()))->Free(temp_r31_290, NULL, 0);
    } else {
        free(temp_r31_290);
    }
    this->unk0 = NULL;
    SetMotionBlurCapEnable(0U);
}

#if 0 // DRAFT: illegal type
void ScreenWobbleFX::Draw() {
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f64 sp18;                                       /* compiler-managed */
    f64 sp10;                                       /* compiler-managed */
    Tools_Ortho sp8;
    f32 *temp_r3_347;
    s32 temp_r26_380;
    s32 temp_r26_412;
    s32 var_r27_370;
    s32 var_r29_375;
    s32 var_r30_368;
    void *temp_r3_390;
    void *temp_r3_422;
    void *temp_r4_397;
    void *temp_r4_429;

    if (((u8) this->unk18 != 0) && ((this->unk4 > 0.0f) || ((u8) this->unk8 != 0))) {
        sp8.Tools_Ortho();
        temp_r3_347 = MKView_GetOrthoRect();
        sp24 = M2C_FIELD(temp_r3_347, f32 *, 4);
        sp28 = M2C_FIELD(temp_r3_347, f32 *, 8);
        sp2C = M2C_FIELD(temp_r3_347, f32 *, 0xC);
        sp20 = M2C_FIELD(temp_r3_347, f32 *, 0);
        MKMaterial_SetMaterial(this->unkC);
        MKPrimitive(0xC, 0x10);
        MKSetMatrix(Matrix::identity);
        var_r30_368 = 0;
        var_r27_370 = 0;
        do {
            MKBegin(0x1E);
            var_r29_375 = 0;
loop_5:
            temp_r26_380 = (var_r29_375 + var_r27_370) * 0x38;
            MKSetColorF(1.0f, 1.0f, 1.0f, this->unk4 * *(this->unk0 + (temp_r26_380 + 0x34)));
            temp_r3_390 = this->unk0 + temp_r26_380;
            MKSetTexCoord1F(M2C_FIELD(temp_r3_390, f32 *, 0), M2C_FIELD(temp_r3_390, f32 *, 4));
            temp_r4_397 = this->unk0 + (temp_r26_380 + 0x10);
            sp10 = M2C_FIELD(temp_r4_397, f64 *, 0);
            sp18 = M2C_FIELD(temp_r4_397, f64 *, 8);
            sp18 = 0.0f;
            sp10 = ((f32) sp10 * sp28) + sp20;
            unksp14 = (unksp14 * sp2C) + sp24;
            MKSetPositionV(*((MKVector3 *) &sp10));
            temp_r26_412 = (var_r29_375 + ((var_r30_368 + 1) * 0xF)) * 0x38;
            MKSetColorF(1.0f, 1.0f, 1.0f, this->unk4 * *(this->unk0 + (temp_r26_412 + 0x34)));
            temp_r3_422 = this->unk0 + temp_r26_412;
            MKSetTexCoord1F(M2C_FIELD(temp_r3_422, f32 *, 0), M2C_FIELD(temp_r3_422, f32 *, 4));
            temp_r4_429 = this->unk0 + (temp_r26_412 + 0x10);
            sp10 = M2C_FIELD(temp_r4_429, f64 *, 0);
            sp18 = M2C_FIELD(temp_r4_429, f64 *, 8);
            sp18 = 0.0f;
            sp10 = ((f32) sp10 * sp28) + sp20;
            unksp14 = (unksp14 * sp2C) + sp24;
            MKSetPositionV(*((MKVector3 *) &sp10));
            var_r29_375 += 1;
            if (var_r29_375 < 0xF) {
                goto loop_5;
            }
            MKEnd();
            var_r30_368 += 1;
            var_r27_370 += 0xF;
        } while (var_r30_368 < 0xE);
        MKEndPrimitive();
        sp8.~Tools_Ortho(-1);
    }
    DrawScreenFlash();
}
#endif

#if 0 // DRAFT: ')' expected
void ScreenWobbleFX::DrawScreenFlash() {
    f32 sp5C;
    f32 sp58;
    f32 sp54;
    f32 sp50;
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
    Tools_Ortho sp8;
    f32 *temp_r3_487;

    if ((u8) this->unk58 != 0) {
        sp8.Tools_Ortho();
        temp_r3_487 = MKView_GetOrthoRect();
        sp50 = M2C_FIELD(temp_r3_487, f32 *, 0);
        sp54 = M2C_FIELD(temp_r3_487, f32 *, 4);
        sp58 = M2C_FIELD(temp_r3_487, f32 *, 8);
        sp5C = M2C_FIELD(temp_r3_487, f32 *, 0xC);
        MKMaterial_SetMaterial(this->unk5C);
        sp18 = 0.0f;
        sp28 = 0.0f;
        sp10 = sp50 + sp58;
        sp14 = sp54 + sp5C;
        sp20 = sp50;
        sp24 = sp50;
        sp30 = (f64) sp10;
        sp38 = (f64) sp18;
        sp40 = (f64) sp20;
        sp48 = (f64) sp28;
        MKShape_DrawSprite(*((MKVector3 *) &sp40), *((MKVector3 *) &sp30), this->unk48);
        sp8.~Tools_Ortho(-1);
    }
}
#endif

#if 0 // DRAFT: illegal type
void ScreenWobbleFX::Update() {
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
    f32 spC;
    f32 sp8;
    f32 temp_f1_719;
    f32 temp_f2_575;
    f32 temp_f2_718;
    f32 temp_f30_855;
    f32 temp_f31_706;
    f32 temp_f3_720;
    f32 var_f0_555;
    f32 var_f0_576;
    f32 var_f1_646;
    f32 var_f4_725;
    f32 var_f4_909;
    f64 temp_f0_658;
    f64 temp_f0_682;
    f64 temp_f0_809;
    f64 temp_f0_833;
    f64 temp_f0_868;
    f64 temp_f0_883;
    f64 temp_f1_728;
    f64 temp_f1_734;
    f64 temp_f1_738;
    f64 temp_f1_912;
    f64 temp_f1_918;
    f64 temp_f1_922;
    s32 temp_r0_645;
    s32 temp_r4_640;
    s32 temp_r7_757;
    s32 temp_r7_941;
    s32 var_ctr_636;
    s32 var_r0_767;
    s32 var_r0_951;
    s32 var_r3_630;
    s32 var_r5_631;
    s32 var_r6_635;
    void *temp_r0_677;
    void *temp_r0_828;
    void *temp_r0_863;
    void *temp_r7_639;
    void *temp_r7_686;
    void *temp_r7_717;
    void *temp_r7_856;
    void *temp_r7_887;
    void *temp_r8_641;
    void *temp_r8_662;
    void *temp_r8_707;
    void *temp_r8_813;
    void *temp_r8_837;
    void *temp_r8_864;
    void *temp_r9_655;
    void *temp_r9_678;
    void *temp_r9_806;
    void *temp_r9_829;

    var_f0_555 = this->unk24 - gUpdateTimeDelta;
    if (var_f0_555 < 1.0f) {

    } else {
        var_f0_555 = 1.0f;
    }
    if (var_f0_555 > 0.0f) {

    } else {
        var_f0_555 = 0.0f;
    }
    this->unk24 = var_f0_555;
    if ((u8) this->unk58 != 0) {
        temp_f2_575 = this->unk70;
        var_f0_576 = this->unk6C - gUpdateTimeDelta;
        if (var_f0_576 < temp_f2_575) {

        } else {
            var_f0_576 = temp_f2_575;
        }
        if (var_f0_576 > 0.0f) {

        } else {
            var_f0_576 = 0.0f;
        }
        this->unk6C = var_f0_576;
        this->unk48.unkC = 1.0f - _table_sinf((0.5f * (3.1415927f * (this->unk6C / this->unk70))) + 1.5707964f);
        if (this->unk6C <= 0.0f) {
            this->unk58 = 0;
        }
    }
    if (((u8) this->unk20 == 0) && (this->unk24 == 0.0f) && ((u8) this->unk68 == 0)) {
        this->unk68 = 1;
        SetMotionBlurCapEnable(0U);
    }
    if ((u8) this->unk18 != 0) {
        var_r3_630 = 0;
        var_r5_631 = 0;
        this->unk8 = 0;
        do {
            var_r6_635 = 0;
            var_ctr_636 = 0xF;
loop_22:
            temp_r7_639 = this->unk0;
            temp_r4_640 = (var_r6_635 + var_r3_630) * 0x38;
            temp_r8_641 = temp_r7_639 + temp_r4_640;
            if ((u8) M2C_FIELD(temp_r8_641, u8 *, 0x30) == 0) {
                temp_r0_645 = this->unk14;
                var_f1_646 = 1.0f;
                switch (temp_r0_645) {              /* switch 1; irregular */
                case 0:                             /* switch 1 */
                    temp_r9_655 = temp_r8_641 + 0x20;
                    temp_f0_658 = M2C_FIELD(temp_r9_655, f64 *, 0) * (f64) gUpdateTimeDelta;
                    sp50 = temp_f0_658;
                    temp_r8_662 = temp_r7_639 + (temp_r4_640 + 0x10);
                    spB0 = temp_f0_658;
                    sp58 = M2C_FIELD(temp_r9_655, f32 *, 8) * gUpdateTimeDelta;
                    spB8 = (f64) sp58;
                    M2C_FIELD(temp_r8_662, f64 *, 0) = (f64) (M2C_FIELD(temp_r8_662, f64 *, 0) + temp_f0_658);
                    M2C_FIELD(temp_r8_662, f32 *, 8) = (f32) (M2C_FIELD(temp_r8_662, f32 *, 8) + (f32) spB8);
                    temp_r0_677 = this->unk0;
                    temp_r9_678 = temp_r0_677 + temp_r4_640;
                    temp_f0_682 = M2C_FIELD(temp_r9_678, f64 *, 0) - *(temp_r9_678 + 0x10);
                    sp40 = temp_f0_682;
                    temp_r7_686 = temp_r0_677 + (temp_r4_640 + 0x20);
                    spD0 = temp_f0_682;
                    spA0 = temp_f0_682;
                    sp48 = M2C_FIELD(temp_r9_678, f32 *, 8) - M2C_FIELD(temp_r9_678, f32 *, 0x18);
                    spA8 = (f64) sp48;
                    spD8 = (f64) sp48;
                    M2C_FIELD(temp_r7_686, f64 *, 0) = (f64) (M2C_FIELD(temp_r7_686, f64 *, 0) + temp_f0_682);
                    M2C_FIELD(temp_r7_686, f32 *, 8) = (f32) (M2C_FIELD(temp_r7_686, f32 *, 8) + (f32) spD8);
                    temp_f31_706 = this->unk10;
                    temp_r8_707 = this->unk0 + (temp_r4_640 + 0x20);
                    M2C_FIELD(temp_r8_707, f64 *, 0) = (f64) (M2C_FIELD(temp_r8_707, f64 *, 0) * (f64) temp_f31_706);
                    M2C_FIELD(temp_r8_707, f32 *, 8) = (f32) (M2C_FIELD(temp_r8_707, f32 *, 8) * temp_f31_706);
                    temp_r7_717 = this->unk0 + (temp_r4_640 + 0x20);
                    temp_f2_718 = M2C_FIELD(temp_r7_717, f32 *, 0);
                    temp_f1_719 = M2C_FIELD(temp_r7_717, f32 *, 4);
                    temp_f3_720 = M2C_FIELD(temp_r7_717, f32 *, 8);
                    var_f4_725 = (temp_f3_720 * temp_f3_720) + ((temp_f2_718 * temp_f2_718) + (temp_f1_719 * temp_f1_719));
                    if (var_f4_725 > 0.0f) {
                        temp_f1_728 = __frsqrte(var_f4_725);
                        temp_f1_734 = 0.5 * temp_f1_728 * -(((f64) var_f4_725 * (temp_f1_728 * temp_f1_728)) - 3.0);
                        temp_f1_738 = 0.5 * temp_f1_734 * -(((f64) var_f4_725 * (temp_f1_734 * temp_f1_734)) - 3.0);
                        var_f4_725 = (f32) ((f64) var_f4_725 * (0.5 * temp_f1_738 * -(((f64) var_f4_725 * (temp_f1_738 * temp_f1_738)) - 3.0)));
                    } else if (var_f4_725 < M2C_BITWISE(f32, 0.0)) {
                        var_f4_725 = __float_nan;
                    } else {
                        spC = var_f4_725;
                        temp_r7_757 = M2C_BITWISE(s32, spC) & 0x7F800000;
                        switch (temp_r7_757) {      /* switch 2; irregular */
                        case 0x7F800000:            /* switch 2 */
                            if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                                var_r0_767 = 1;
                            } else {
                                var_r0_767 = 2;
                            }
                            break;
                        case 0x0:                   /* switch 2 */
                            if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                                var_r0_767 = 5;
                            } else {
                                var_r0_767 = 3;
                            }
                            break;
                        default:                    /* switch 2 */
                            var_r0_767 = 4;
                            break;
                        }
                        if (var_r0_767 == 1) {
                            var_f4_725 = __float_nan;
                        }
                    }
                    if (var_f4_725 < 0.3f) {

                    } else {
                        var_f4_725 = 0.3f;
                    }
                    if (var_f4_725 > 0.0f) {

                    } else {
                        var_f4_725 = 0.0f;
                    }
                    var_f1_646 = var_f4_725;
                    break;
                case 1:                             /* switch 1 */
                    temp_r9_806 = temp_r8_641 + 0x20;
                    temp_f0_809 = M2C_FIELD(temp_r9_806, f64 *, 0) * (f64) gUpdateTimeDelta;
                    sp30 = temp_f0_809;
                    temp_r8_813 = temp_r7_639 + (temp_r4_640 + 0x10);
                    sp90 = temp_f0_809;
                    sp38 = M2C_FIELD(temp_r9_806, f32 *, 8) * gUpdateTimeDelta;
                    sp98 = (f64) sp38;
                    M2C_FIELD(temp_r8_813, f64 *, 0) = (f64) (M2C_FIELD(temp_r8_813, f64 *, 0) + temp_f0_809);
                    M2C_FIELD(temp_r8_813, f32 *, 8) = (f32) (M2C_FIELD(temp_r8_813, f32 *, 8) + (f32) sp98);
                    temp_r0_828 = this->unk0;
                    temp_r9_829 = temp_r0_828 + temp_r4_640;
                    temp_f0_833 = M2C_FIELD(temp_r9_829, f64 *, 0) - *(temp_r9_829 + 0x10);
                    sp60 = temp_f0_833;
                    temp_r8_837 = temp_r0_828 + (temp_r4_640 + 0x20);
                    spC0 = temp_f0_833;
                    sp68 = M2C_FIELD(temp_r9_829, f32 *, 8) - M2C_FIELD(temp_r9_829, f32 *, 0x18);
                    spC8 = (f64) sp68;
                    M2C_FIELD(temp_r8_837, f64 *, 0) = (f64) (M2C_FIELD(temp_r8_837, f64 *, 0) + temp_f0_833);
                    M2C_FIELD(temp_r8_837, f32 *, 8) = (f32) (M2C_FIELD(temp_r8_837, f32 *, 8) + (f32) spC8);
                    temp_f30_855 = this->unk10;
                    temp_r7_856 = this->unk0 + (temp_r4_640 + 0x20);
                    M2C_FIELD(temp_r7_856, f64 *, 0) = (f64) (M2C_FIELD(temp_r7_856, f64 *, 0) * (f64) temp_f30_855);
                    M2C_FIELD(temp_r7_856, f32 *, 8) = (f32) (M2C_FIELD(temp_r7_856, f32 *, 8) * temp_f30_855);
                    temp_r0_863 = this->unk0;
                    temp_r8_864 = temp_r0_863 + temp_r4_640;
                    temp_f0_868 = M2C_FIELD(temp_r8_864, f64 *, 0) - *(temp_r8_864 + 0x10);
                    sp20 = temp_f0_868;
                    spC0 = temp_f0_868;
                    sp80 = temp_f0_868;
                    sp28 = M2C_FIELD(temp_r8_864, f32 *, 8) - M2C_FIELD(temp_r8_864, f32 *, 0x18);
                    sp88 = (f64) sp28;
                    spC8 = (f64) sp28;
                    temp_f0_883 = temp_f0_868 * (f64) gUpdateTimeDelta;
                    sp10 = temp_f0_883;
                    temp_r7_887 = temp_r0_863 + (temp_r4_640 + 0x10);
                    sp70 = temp_f0_883;
                    sp18 = (f32) spC8 * gUpdateTimeDelta;
                    sp78 = (f64) sp18;
                    M2C_FIELD(temp_r7_887, f64 *, 0) = (f64) (M2C_FIELD(temp_r7_887, f64 *, 0) + temp_f0_883);
                    M2C_FIELD(temp_r7_887, f32 *, 8) = (f32) (M2C_FIELD(temp_r7_887, f32 *, 8) + (f32) sp78);
                    var_f4_909 = ((f32) spC8 * (f32) spC8) + (((f32) spC0 * (f32) spC0) + (unkspC4 * unkspC4));
                    if (var_f4_909 > 0.0f) {
                        temp_f1_912 = __frsqrte(var_f4_909);
                        temp_f1_918 = 0.5 * temp_f1_912 * -(((f64) var_f4_909 * (temp_f1_912 * temp_f1_912)) - 3.0);
                        temp_f1_922 = 0.5 * temp_f1_918 * -(((f64) var_f4_909 * (temp_f1_918 * temp_f1_918)) - 3.0);
                        var_f4_909 = (f32) ((f64) var_f4_909 * (0.5 * temp_f1_922 * -(((f64) var_f4_909 * (temp_f1_922 * temp_f1_922)) - 3.0)));
                    } else if (var_f4_909 < M2C_BITWISE(f32, 0.0)) {
                        var_f4_909 = __float_nan;
                    } else {
                        sp8 = var_f4_909;
                        temp_r7_941 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                        switch (temp_r7_941) {      /* switch 3; irregular */
                        case 0x7F800000:            /* switch 3 */
                            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                var_r0_951 = 1;
                            } else {
                                var_r0_951 = 2;
                            }
                            break;
                        case 0x0:                   /* switch 3 */
                            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                var_r0_951 = 5;
                            } else {
                                var_r0_951 = 3;
                            }
                            break;
                        default:                    /* switch 3 */
                            var_r0_951 = 4;
                            break;
                        }
                        if (var_r0_951 == 1) {
                            var_f4_909 = __float_nan;
                        }
                    }
                    if (var_f4_909 < 1.0f) {

                    } else {
                        var_f4_909 = 1.0f;
                    }
                    if (var_f4_909 > 0.0f) {

                    } else {
                        var_f4_909 = 0.0f;
                    }
                    var_f1_646 = var_f4_909;
                    break;
                }
                if (var_f1_646 > 0.001f) {
                    this->unk8 = 1;
                    *(this->unk0 + (temp_r4_640 + 0x34)) = 1.0f;
                } else {
                    *(this->unk0 + (temp_r4_640 + 0x34)) = 0.0f;
                }
            }
            var_r6_635 += 1;
            var_ctr_636 -= 1;
            if (var_ctr_636 != 0) {
                goto loop_22;
            }
            var_r5_631 += 1;
            var_r3_630 += 0xF;
        } while (var_r5_631 < 0xF);
    }
}
#endif

void ScreenWobbleFX::EnableScreenFlash(const MKVector4 &arg0, float arg1) {
    M2C_FIELD(this, f64 *, 0x48) = (f64) M2C_FIELD(&arg0, f64 *, 0);
    M2C_FIELD(this, f64 *, 0x50) = (f64) M2C_FIELD(&arg0, f64 *, 8);
    this->unk58 = 1;
    this->unk70 = arg1;
    this->unk6C = arg1;
}

#if 0 // DRAFT: illegal use of non-static member
void ScreenWobbleFX::Init() {
    f64 sp20;
    f64 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    MKHeap *temp_r3_1050;
    void *var_r3_1057;

    temp_r3_1050 = MKHeap::Current();
    if (temp_r3_1050 != NULL) {
        var_r3_1057 = ((MKHeap *) (temp_r3_1050->Current()))->Alloc(0x3138, NULL, 0);
    } else {
        var_r3_1057 = malloc(0x3138);
    }
    this->unk0 = var_r3_1057;
    InitWobbleNodes();
    this->unkC = MKMaterial_Create("fx_wobblemat");
    this->unk1C = MKMaterial_Create("motionblurmat");
    this->unk4 = 1.0f;
    this->unk10 = 1.0f;
    sp8 = 1.0f;
    spC = 1.0f;
    this->unk18 = 1;
    sp10 = 0.0f;
    sp14 = 1.0f;
    M2C_FIELD(this, f64 *, 0x48) = (f64) sp8;
    M2C_FIELD(this, f64 *, 0x50) = (f64) sp10;
    sp18 = (f64) sp8;
    sp20 = (f64) sp10;
    this->unk58 = 0;
    this->unk5C = MKMaterial_Create("ScreenFlashMat");
    this->unk20 = 0;
    this->unk24 = 0.0f;
    this->unk38 = 1;
    this->unk60 = 0;
    this->unk64 = 0;
    this->unk68 = 1;
    this->unk6C = 0.0f;
    this->unk70 = 0.01f;
    this->unk3C = 0.0f;
    this->unk40 = 1.0f;
}
#endif
