#include "spyro/source/GemMagicFX.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/CharacterGlowFX.h"
#include "spyro/source/EmbersPS.h"
#include "spyro/source/ShapedTrailFX.h"
#include "spyro/source/Spyro.h"
#include "unplaced_templates.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKView.h"
#include "common/gc/MKMaterial_GC.h"
#include "common/gc/MKPrimitive_GC.h"
#include "spyro/source/KDMath.h"
#include "spyro/source/KDRandom.h"
#include <m2c_macros.h>

M2C_UNK free(MKHeap *);                             /* extern */
MKHeap *malloc(M2C_UNK);                            /* extern */
extern f32 SPYRO_BOUNCE_Y_SPEED;
extern f32 SPYRO_MIN_JUMP_Y_VELOCITY;
extern M2C_UNK gEmptyPtrListDL;
extern MKSceneManager *gMK;
extern f32 gUpdateTimeDelta;
extern M2C_UNK gb;
static s32 lit_697 = -1;
static s32 lit_698 = 3;

static u8 lit_729 = 0;

static u8 lit_833 = 1;
#if 0 // DRAFT: undefined identifier 'arg_sp2C'
static s8 lit_stringBase0[0x1C] = {
    0x53,
    0x68,
    0x61,
    0x70,
    0x65,
    0x64,
    0x54,
    0x72,
    0x61,
    0x69,
    0x6C,
    0x46,
    0x58,
    0,
    0x66,
    0x78,
    0x5F,
    0x33,
    0x36,
    0x32,
    0,
    0x66,
    0x78,
    0x5F,
    0x30,
    0x30,
    0x32,
    0,
}; /* const */

void GemMagicFX::DrawGlow(GemMagicFX::Magic *arg1, Matrix *arg2, MKVector3 *arg3) {
    M2C_STRUCT_COPY((s32) &arg_sp2C + 4, (s32) (arg2 - 4) + 4, 0x40);
    arg_sp60 = M2C_FIELD(arg1, f32 *, 0);
    arg_sp64 = M2C_FIELD(arg1, f32 *, 4);
    arg_sp68 = M2C_FIELD(arg1, f32 *, 8);
    arg_sp6C = 1.0f;
    MKSetMatrix(*((Matrix *) &arg_sp30));
    arg_sp10 = 1.0f;
    arg_sp14 = 1.0f;
    arg_sp18 = 1.0f;
    arg_sp1C = 1.0f;
    arg_sp20 = (f64) arg_sp10;
    arg_sp28 = (f64) arg_sp18;
    MKBegin(4);
    MKSetColorV(*((MKVector4 *) &arg_sp20));
    MKSetTexCoord1F(0.0f, 1.0f);
    MKSetPositionV(*arg3);
    MKSetColorV(*((MKVector4 *) &arg_sp20));
    MKSetTexCoord1F(1.0f, 1.0f);
    MKSetPositionV(*(arg3 + 0x10));
    MKSetColorV(*((MKVector4 *) &arg_sp20));
    MKSetTexCoord1F(0.0f, 0.0f);
    MKSetPositionV(*(arg3 + 0x20));
    MKSetColorV(*((MKVector4 *) &arg_sp20));
    MKSetTexCoord1F(1.0f, 0.0f);
    MKSetPositionV(*(arg3 + 0x30));
    MKEnd();
}
#endif

void GemMagicFX::Emit(const MKVector3 &arg0, const MKVector3 &arg1, MKVector3 *arg2, const MKVector4 &arg3, bool arg4) {
    MKHeap *temp_r9_125;
    void **temp_r3_152;
    void *temp_r31_131;
    void *temp_r3_155;
    void *temp_r3_165;
    void *temp_r3_176;
    void *temp_r5_171;

    temp_r9_125 = this->unk4C;
    if ((void *) M2C_FIELD(temp_r9_125, void **, -4) != NULL) {
        this->unk4C = temp_r9_125 - 4;
        temp_r31_131 = M2C_FIELD(temp_r9_125, void **, -4);
        if (temp_r31_131 != NULL) {
            M2C_FIELD(temp_r31_131, f64 *, 0) = (f64) M2C_FIELD(&arg0, f64 *, 0);
            M2C_FIELD(temp_r31_131, f64 *, 8) = (f64) M2C_FIELD(&arg0, f64 *, 8);
            M2C_FIELD(temp_r31_131, f64 *, 0x10) = (f64) M2C_FIELD(&arg1, f64 *, 0);
            M2C_FIELD(temp_r31_131, f64 *, 0x18) = (f64) M2C_FIELD(&arg1, f64 *, 8);
            M2C_FIELD(temp_r31_131, MKVector3 **, 0x30) = arg2;
            M2C_FIELD(temp_r31_131, f64 *, 0x20) = (f64) M2C_FIELD(&arg3, f64 *, 0);
            M2C_FIELD(temp_r31_131, f64 *, 0x28) = (f64) M2C_FIELD(&arg3, f64 *, 8);
            M2C_FIELD(temp_r31_131, f32 *, 0x38) = 0.5f;
            M2C_FIELD(temp_r31_131, u8 *, 0x3C) = arg4;
            M2C_FIELD(temp_r31_131, void ***, 0x34) = GetTrail();
            temp_r3_152 = M2C_FIELD(temp_r31_131, void ***, 0x34);
            if (temp_r3_152 != NULL) {
                temp_r3_155 = *temp_r3_152;
                if (temp_r3_155 != NULL) {
                    M2C_FIELD(M2C_FIELD(temp_r3_155, void **, 0x44), M2C_UNK (**)(), 0x20)();
                    temp_r3_165 = *M2C_FIELD(temp_r31_131, void ***, 0x34);
                    M2C_FIELD(temp_r3_165, f64 *, 0x50) = (f64) M2C_FIELD(&arg3, f64 *, 0);
                    M2C_FIELD(temp_r3_165, f64 *, 0x58) = (f64) M2C_FIELD(&arg3, f64 *, 8);
                    temp_r5_171 = *M2C_FIELD(temp_r31_131, void ***, 0x34);
                    M2C_FIELD(temp_r5_171, u8 *, 0xA0) = (u8) ((M2C_FIELD(temp_r5_171, u8 *, 0xA0) & ~0x80) | ((lit_833 << 7) & 0x80));
                    temp_r3_176 = *M2C_FIELD(temp_r31_131, void ***, 0x34);
                    M2C_FIELD(temp_r3_176, u8 *, 0xA0) = (u8) (M2C_FIELD(temp_r3_176, u8 *, 0xA0) | 0x40);
                    M2C_FIELD(*M2C_FIELD(temp_r31_131, void ***, 0x34), void **, 0x74) = temp_r31_131;
                }
            }
        }
    }
}

#if 0 // DRAFT: illegal implicit conversion from 'MKHeap *' to
void **GemMagicFX::GetTrail() {
    s32 var_ctr_201;
    s32 var_r31_200;
    void *temp_r3_204;
    void *temp_r3_208;

    var_r31_200 = 0;
    var_ctr_201 = 0xA;
loop_1:
    temp_r3_204 = this->unk50 + var_r31_200;
    if ((u8) M2C_FIELD(temp_r3_204, u8 *, 4) == 0) {
        temp_r3_208 = M2C_FIELD(temp_r3_204, void **, 0);
        M2C_FIELD(M2C_FIELD(temp_r3_208, void **, 0x44), M2C_UNK (**)(void *), 0x20)(temp_r3_208);
        M2C_FIELD((this->unk50 + var_r31_200), s8 *, 4) = 1;
        return this->unk50 + var_r31_200;
    }
    var_r31_200 += 8;
    var_ctr_201 -= 1;
    if (var_ctr_201 == 0) {
        return NULL;
    }
    goto loop_1;
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void GemMagicFX::Deinit() {
    MKHeap *temp_r0_259;
    MKHeap *temp_r0_278;
    MKHeap *temp_r31_240;
    MKHeap *temp_r3_241;
    MKHeap *temp_r3_281;
    MKHeap *var_r31_255;
    MKHeap *var_r3_256;
    MKHeap *var_r4_254;
    u32 temp_r0_264;

    temp_r31_240 = this->unk50;
    temp_r3_241 = MKHeap::Current();
    if (temp_r3_241 != NULL) {
        ((MKHeap *) (temp_r3_241->Current()))->Free(temp_r31_240, NULL, 0);
    } else {
        free(temp_r31_240);
    }
    var_r4_254 = this->unk4C;
    var_r31_255 = var_r4_254;
    var_r3_256 = var_r4_254;
loop_6:
    temp_r0_264 = M2C_FIELD(var_r3_256, u32 *, -4);
    var_r3_256 -= 4;
    if (temp_r0_264 != 0U) {
        temp_r0_259 = var_r3_256->unk0;
        if (temp_r0_259 < var_r31_255) {
            var_r31_255 = temp_r0_259;
        }
        goto loop_6;
    }
    if (var_r3_256 != &gEmptyPtrListDL) {
loop_12:
        temp_r0_278 = var_r4_254->unk0;
        if (temp_r0_278 != NULL) {
            if (temp_r0_278 < var_r31_255) {
                var_r31_255 = temp_r0_278;
            }
            var_r4_254 += 4;
            goto loop_12;
        }
        temp_r3_281 = var_r3_256->Current();
        if (temp_r3_281 != NULL) {
            ((MKHeap *) (temp_r3_281->Current()))->Free(var_r31_255, NULL, 0);
        } else {
            free(var_r31_255);
        }
    }
    this->unk4C = NULL;
    MKMaterial_Destroy(this->unk54);
    MKProp::Deinit();
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_sp98'
void GemMagicFX::Draw() {
    MKHeap *temp_r4_505;
    MKHeap *var_r31_494;
    arg_sp98 = 0.0f;
    arg_sp90 = 1.0f;
    arg_sp94 = 0.0f;
    arg_sp1B8 = (f64) arg_sp98;
    arg_sp1B0 = (f64) arg_sp90;
    arg_spA8 = 0.0f;
    arg_sp48 = -(f32) arg_sp1B8;
    arg_spA0 = 0.0f;
    arg_spA4 = 1.0f;
    arg_sp40 = -(f32) arg_sp1B0;
    arg_sp44 = -arg_sp1B4;
    arg_sp1C0 = (f64) arg_spA0;
    arg_sp1C8 = (f64) arg_spA8;
    arg_sp170 = (f64) arg_sp40;
    arg_sp178 = (f64) arg_sp48;
    arg_sp180.operator*(30.000002f);
    arg_sp190.operator*(30.000002f);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    arg_sp1A0 = arg_sp80;
    arg_sp88 = arg_sp198 + arg_sp188;
    arg_sp210 = arg_sp80;
    arg_sp1A8 = (f64) arg_sp88;
    arg_sp218 = (f64) arg_sp88;
    arg_sp140.operator*(30.000002f);
    arg_sp150.operator*(30.000002f);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    arg_sp38 = -(f32) arg_sp1B8;
    arg_sp78 = arg_sp158 + arg_sp148;
    arg_sp30 = -(f32) arg_sp1B0;
    arg_sp34 = -arg_sp1B4;
    arg_sp160 = arg_sp70;
    arg_sp168 = (f64) arg_sp78;
    arg_sp220 = arg_sp70;
    arg_sp228 = (f64) arg_sp78;
    arg_spF0 = (f64) arg_sp30;
    arg_spF8 = (f64) arg_sp38;
    arg_sp100.operator*(30.000002f);
    arg_sp20 = -(f32) arg_sp1C0;
    arg_sp24 = -arg_sp1C4;
    arg_sp28 = -(f32) arg_sp1C8;
    arg_sp110 = (f64) arg_sp20;
    arg_sp118 = (f64) arg_sp28;
    arg_sp120.operator*(30.000002f);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    arg_sp130 = arg_sp60;
    arg_sp68 = arg_sp128 + arg_sp108;
    arg_sp230 = arg_sp60;
    arg_sp138 = (f64) arg_sp68;
    arg_sp238 = (f64) arg_sp68;
    arg_spB0.operator*(30.000002f);
    arg_sp10 = -(f32) arg_sp1C0;
    arg_sp14 = -arg_sp1C4;
    arg_sp18 = -(f32) arg_sp1C8;
    arg_spC0 = (f64) arg_sp10;
    arg_spC8 = (f64) arg_sp18;
    arg_spD0.operator*(30.000002f);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    arg_spE0 = arg_sp50;
    arg_sp58 = arg_spD8 + arg_spB8;
    arg_sp240 = arg_sp50;
    arg_spE8 = (f64) arg_sp58;
    arg_sp248 = (f64) arg_sp58;
    M2C_STRUCT_COPY((s32) &arg_sp1CC + 4, MKView_GetCameraMatrix() - 4 + 4, 0x40);
    MKMaterial_SetMaterial(this->unk54);
    MKPrimitive(0xC, 0);
    var_r31_494 = this->unk4C;
loop_2:
    if (var_r31_494 != NULL) {
        temp_r4_505 = var_r31_494->unk0;
        if (temp_r4_505 != NULL) {
            DrawGlow((GemMagicFX::Magic *) temp_r4_505, (Matrix *) &arg_sp1D0, (MKVector3 *) &arg_sp210);
            var_r31_494 += 4;
            goto loop_2;
        }
    }
    MKEndPrimitive();
}
#endif

#if 0 // DRAFT: undefined identifier 'sp100'
void GemMagicFX::Update() {
    f64 sp228;                                      /* compiler-managed */
    f64 sp220;                                      /* compiler-managed */
    f64 sp218;
    f64 sp210;
    f64 sp208;
    f64 sp200;
    f64 sp1F8;
    f64 sp1F0;
    f64 sp1E8;
    f64 sp1E0;
    MKVector3 sp1D0;
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
    MKVector3 sp130;
    f64 sp128;
    f64 sp120;
    MKVector3 sp110;
    f32 sp108;
    f32 spF8;
    f32 spF4;
    f32 spF0;
    f32 spE8;
    f32 spE4;
    f32 spE0;
    f32 spD8;
    f32 spC8;
    f32 spB8;
    f32 spB4;
    f32 spB0;
    f32 spA8;
    f32 spA4;
    f32 spA0;
    f32 sp98;
    f32 sp94;
    f32 sp90;
    f32 sp88;
    f32 sp7C;
    f32 sp78;
    f32 sp74;
    f32 sp70;
    f64 sp68;
    f32 sp5C;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f64 sp48;
    f64 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f32 sp8;
    MKHeap *temp_r29_993;
    MKHeap *temp_r3_939;
    MKHeap *temp_r4_942;
    MKHeap *var_r28_543;
    f32 temp_f24_956;
    f32 temp_f27_967;
    f32 var_f0_551;
    f32 var_f0_848;
    f32 var_f0_888;
    f32 var_f0_906;
    f32 var_f1_857;
    f32 var_f1_880;
    f32 var_f1_897;
    f32 var_f26_589;
    f32 var_f2_866;
    f32 var_f4_832;
    f32 var_f7_656;
    f64 temp_f1_595;
    f64 temp_f1_601;
    f64 temp_f1_605;
    s32 temp_r3_624;
    s32 var_r0_634;
    s32 var_r25_755;
    void *temp_r3_566;
    void *temp_r3_738;
    void *temp_r3_927;
    void *temp_r4_744;

    var_r28_543 = this->unk4C;
loop_66:
    if (var_r28_543 != NULL) {
        temp_r29_993 = var_r28_543->unk0;
        if (temp_r29_993 != NULL) {
            var_f0_551 = temp_r29_993->unk38 - gUpdateTimeDelta;
            if (var_f0_551 < 0.5f) {

            } else {
                var_f0_551 = 0.5f;
            }
            if (var_f0_551 > 0.0f) {

            } else {
                var_f0_551 = 0.0f;
            }
            temp_r29_993->unk38 = var_f0_551;
            temp_r3_566 = M2C_FIELD(temp_r29_993, void **, 0x30);
            if (temp_r3_566 != NULL) {
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r3, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r29, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
                sp220 = sp100;
                sp108 = M2C_FIELD(temp_r3_566, f32 *, 8) - M2C_BITWISE(f32, temp_r29_993->unk8);
                sp228 = (f64) sp108;
                var_f26_589 = ((f32) sp228 * (f32) sp228) + (((f32) sp220 * (f32) sp220) + (unksp224 * unksp224));
                if (var_f26_589 > 0.000001f) {
                    if (var_f26_589 > 0.0f) {
                        temp_f1_595 = __frsqrte(var_f26_589);
                        temp_f1_601 = 0.5 * temp_f1_595 * -(((f64) var_f26_589 * (temp_f1_595 * temp_f1_595)) - 3.0);
                        temp_f1_605 = 0.5 * temp_f1_601 * -(((f64) var_f26_589 * (temp_f1_601 * temp_f1_601)) - 3.0);
                        var_f26_589 = (f32) ((f64) var_f26_589 * (0.5 * temp_f1_605 * -(((f64) var_f26_589 * (temp_f1_605 * temp_f1_605)) - 3.0)));
                    } else if (var_f26_589 < M2C_BITWISE(f32, 0.0)) {
                        var_f26_589 = __float_nan;
                    } else {
                        sp8 = var_f26_589;
                        temp_r3_624 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                        switch (temp_r3_624) {      /* irregular */
                        case 0x7F800000:
                            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                var_r0_634 = 1;
                            } else {
                                var_r0_634 = 2;
                            }
                            break;
                        case 0x0:
                            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                var_r0_634 = 5;
                            } else {
                                var_r0_634 = 3;
                            }
                            break;
                        default:
                            var_r0_634 = 4;
                            break;
                        }
                        if (var_r0_634 == 1) {
                            var_f26_589 = __float_nan;
                        }
                    }
                    var_f7_656 = 1.0f / var_f26_589;
                } else {
                    var_f7_656 = 0.0f;
                    var_f26_589 = 0.0f;
                }
                spF8 = -1.0f;
                spE8 = 1.0f;
                spF0 = -1.0f;
                spF4 = -1.0f;
                spE0 = 1.0f;
                spE4 = 1.0f;
                sp220 = (f32) sp220 * var_f7_656;
                unksp224 *= var_f7_656;
                sp228 = (f32) sp228 * var_f7_656;
                sp1C0 = (f64) spF0;
                sp1C8 = (f64) spF8;
                sp1B0 = (f64) spE0;
                sp1B8 = (f64) spE8;
                KDRand_Vector(sp1D0, *((MKVector3 *) &sp1C0));
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
                sp1E0 = spD0;
                spD8 = sp1D0.unk8 * 10.0f;
                sp1E8 = (f64) spD8;
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r29, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                spB8 = 0.0f;
                spC8 = M2C_BITWISE(f32, temp_r29_993->unk8) + (f32) sp1E8;
                spB0 = 0.0f;
                spB4 = 0.0f;
                sp1F0 = spC0;
                sp1F8 = (f64) spC8;
                sp1A0 = (f64) spB0;
                sp1A8 = (f64) spB8;
                ((EmbersPS *) (M2C_FIELD(&gb, EmbersPS **, 0x74)))->Emit(*((MKVector3 *) &sp1F0), *((MKVector3 *) &sp1A0), 3.0f, *((MKVector4 *) &temp_r29_993->unk20), 0.0f);
                M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
                if ((var_f26_589 == 100.0f) && (M2C_ERROR(/* unknown instruction: cror eq, lt, eq */), ((temp_r29_993->unk38 == 0.0f) != 0))) {
                    temp_r3_738 = M2C_FIELD(temp_r29_993, void **, 0x34);
                    if (temp_r3_738 != NULL) {
                        M2C_FIELD(temp_r3_738, s8 *, 4) = 0;
                        temp_r4_744 = M2C_FIELD(M2C_FIELD(temp_r29_993, void **, 0x34), void **, 0);
                        if (temp_r4_744 != NULL) {
                            M2C_FIELD(temp_r4_744, u8 *, 0xA0) = (u8) ((M2C_FIELD(temp_r4_744, u8 *, 0xA0) & ~0x80) | ((lit_729 << 7) & 0x80));
                        }
                    }
                    var_r25_755 = 0;
                    do {
                        spA8 = -1.0f;
                        sp98 = 1.0f;
                        spA0 = -1.0f;
                        spA4 = 0.0f;
                        sp90 = 1.0f;
                        sp94 = 1.0f;
                        sp180 = (f64) spA0;
                        sp188 = (f64) spA8;
                        sp170 = (f64) sp90;
                        sp178 = (f64) sp98;
                        KDRand_Vector(sp190, *((MKVector3 *) &sp180));
                        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r26, 0x0, qr0 */);
                        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
                        sp210 = sp80;
                        sp88 = sp190.unk8 * 1000.0f;
                        sp218 = (f64) sp88;
                        ((EmbersPS *) (M2C_FIELD(&gb, EmbersPS **, 0x74)))->Emit(*((MKVector3 *) temp_r29_993), *((MKVector3 *) &sp210), 3.0f, *((MKVector4 *) &temp_r29_993->unk20), -2000.0f);
                        var_r25_755 += 1;
                    } while (var_r25_755 < 3);
                    if (((u8) M2C_FIELD(temp_r29_993, u8 *, 0x3C) != 0) && (M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), s32 (**)(void **), 8)(M2C_FIELD(&gb, void ***, 0)) == 0)) {
                        sp50 = 1.0f;
                        sp54 = 1.0f;
                        sp58 = 1.0f;
                        sp5C = 1.0f;
                        sp140 = (f64) sp50;
                        sp148 = (f64) sp58;
                        M2C_ERROR(/* unknown instruction: psq_lx $f0, $r29, $r0, 0x0, qr0 */);
                        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f28 */);
                        M2C_ERROR(/* unknown instruction: psq_lx $f0, $r29, $r0, 0x0, qr0 */);
                        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f28 */);
                        M2C_ERROR(/* unknown instruction: psq_stx $f0, $zero, $r30, 0x0, qr0 */);
                        sp150 = sp60;
                        var_f4_832 = (f32) sp150;
                        sp70 = 0.0f;
                        sp74 = 0.0f;
                        sp78 = 0.0f;
                        sp7C = 1.0f;
                        sp158 = sp68;
                        sp160 = (f64) sp70;
                        sp168 = (f64) sp78;
                        if (var_f4_832 < (f32) sp140) {

                        } else {
                            var_f4_832 = (f32) sp140;
                        }
                        var_f0_848 = unksp154;
                        sp30 = var_f4_832;
                        if (var_f0_848 < unksp144) {

                        } else {
                            var_f0_848 = unksp144;
                        }
                        var_f1_857 = (f32) sp158;
                        sp34 = var_f0_848;
                        if (var_f1_857 < (f32) sp148) {

                        } else {
                            var_f1_857 = (f32) sp148;
                        }
                        var_f2_866 = unksp15C;
                        sp38 = var_f1_857;
                        if (var_f2_866 < unksp14C) {

                        } else {
                            var_f2_866 = unksp14C;
                        }
                        sp3C = var_f2_866;
                        sp40 = (f64) sp30;
                        var_f1_880 = (f32) sp40;
                        sp48 = (f64) sp38;
                        if (var_f1_880 > (f32) sp160) {

                        } else {
                            var_f1_880 = (f32) sp160;
                        }
                        var_f0_888 = unksp44;
                        sp20 = var_f1_880;
                        if (var_f0_888 > unksp164) {

                        } else {
                            var_f0_888 = unksp164;
                        }
                        var_f1_897 = (f32) sp48;
                        sp24 = var_f0_888;
                        if (var_f1_897 > (f32) sp168) {

                        } else {
                            var_f1_897 = (f32) sp168;
                        }
                        var_f0_906 = unksp4C;
                        sp28 = var_f1_897;
                        if (var_f0_906 > unksp16C) {

                        } else {
                            var_f0_906 = unksp16C;
                        }
                        sp2C = var_f0_906;
                        sp200 = (f64) sp20;
                        sp208 = (f64) sp28;
                        temp_r3_927 = checked_cast<Spyro *, MKProp>(M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), MKProp *(**)(void **, f64), 0xC)(M2C_FIELD(&gb, void ***, 0), (f64) sp20));
                        if ((u8) M2C_FIELD(temp_r3_927, u8 *, 0x25D) == 0) {
                            ((CharacterGlowFX *) (M2C_FIELD(M2C_FIELD(M2C_FIELD(temp_r3_927, void **, 0x260), void **, 4), CharacterGlowFX **, 0x28)))->Enable(1U, *((MKVector4 *) &sp200), 1.75f);
                        }
                    }
                    temp_r3_939 = this->unk4C;
                    this->unk4C = (MKHeap *) &temp_r3_939->unk4;
                    temp_r4_942 = temp_r3_939->unk0;
                    temp_r3_939->unk0 = var_r28_543->unk0;
                    var_r28_543->unk0 = temp_r4_942;
                } else {
                    temp_f24_956 = 1.0f - (temp_r29_993->unk38 / 0.5f);
                    KDMath_Slerp(sp130, *((MKVector3 *) &temp_r29_993->unk10), 0.75f * temp_f24_956);
                    M2C_FIELD(temp_r29_993, f64 *, 0x10) = M2C_BITWISE(f64, sp130);
                    M2C_FIELD(temp_r29_993, f64 *, 0x18) = (f64) sp130.unk8;
                    temp_f27_967 = gUpdateTimeDelta;
                    sp110.operator*((1000.0f * temp_f24_956) + 1000.0f);
                    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
                    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f27 */);
                    sp120 = sp10;
                    sp18 = sp110.unk8 * temp_f27_967;
                    sp128 = (f64) sp18;
                    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r29, 0x0, qr0 */);
                    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                    M2C_ERROR(/* unknown instruction: psq_stx $f0, $zero, $r29, 0x0, qr0 */);
                    temp_r29_993->unk8 = M2C_BITWISE(f32, temp_r29_993->unk8) + (f32) sp128;
                }
            }
            var_r28_543 += 4;
            goto loop_66;
        }
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void *' to
void GemMagicFX::Init() {
    f64 sp20;
    f64 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    MKHeap *temp_r3_1031;
    MKHeap *temp_r3_1053;
    MKHeap *temp_r3_1059;
    MKHeap *temp_r3_1064;
    MKHeap *var_r3_1038;
    MKHeap *var_r3_1071;
    MKHeap *var_r5_1047;
    s32 *temp_r3_1061;
    s32 temp_r3_1087;
    s32 var_ctr_1051;
    s32 var_r28_1081;
    s32 var_r30_1082;

    MKProp::Init();
    temp_r3_1031 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_1031 != NULL) {
        var_r3_1038 = ((MKHeap *) (temp_r3_1031->Current()))->Alloc(0x558, NULL, 0);
    } else {
        var_r3_1038 = malloc(0x558);
    }
    this->unk4C = var_r3_1038;
    var_r5_1047 = this->unk4C;
    this->unk4C = var_r5_1047 + 0x500;
    M2C_FIELD(var_r5_1047, s32 *, 0x500) = 0;
    var_ctr_1051 = 0x14;
    do {
        temp_r3_1053 = this->unk4C;
        this->unk4C = (MKHeap *) &temp_r3_1053->unk4;
        temp_r3_1053->unk4 = (s32) var_r5_1047;
        var_r5_1047 += 0x40;
        var_ctr_1051 -= 1;
    } while (var_ctr_1051 != 0);
    temp_r3_1059 = this->unk4C;
    temp_r3_1061 = &temp_r3_1059->unk4;
    this->unk4C = (MKHeap *) temp_r3_1061;
    temp_r3_1059->unk4 = 0;
    temp_r3_1064 = temp_r3_1061->Current();
    if (temp_r3_1064 != NULL) {
        var_r3_1071 = ((MKHeap *) (temp_r3_1064->Current()))->Alloc(0x50, NULL, 0);
    } else {
        var_r3_1071 = malloc(0x50);
    }
    this->unk50 = var_r3_1071;
    var_r28_1081 = 0;
    var_r30_1082 = 0;
    do {
        temp_r3_1087 = checked_cast<ShapedTrailFX *, MKProp>(gMK->CreateProp(lit_stringBase0));
        sp8 = 1.0f;
        spC = 1.0f;
        sp10 = 1.0f;
        sp14 = 1.0f;
        *(this->unk50 + var_r30_1082) = temp_r3_1087;
        sp18 = (f64) sp8;
        sp20 = (f64) sp10;
        ((ShapedTrailFX *) (*(this->unk50 + var_r30_1082)))->InitData(NULL, lit_697, &lit_stringBase0[0xE], lit_698, *((MKVector4 *) &sp18), 0.7f, 1U, 0.3f);
        var_r28_1081 += 1;
        *(this->unk50 + (var_r30_1082 + 4)) = 0;
        var_r30_1082 += 8;
    } while (var_r28_1081 < 0xA);
    this->unk54 = MKMaterial_Create(&lit_stringBase0[0x15]);
}
#endif

void GemMagicFX_cpp::__sinit() {
    f32 temp_f0_1166;
    f64 temp_f1_1147;
    f64 temp_f1_1155;
    f64 temp_f3_1135;
    f64 temp_f4_1144;
    f64 temp_f4_1152;
    f64 temp_f8_1137;

    temp_f3_1135 = __frsqrte(2014000.0);
    temp_f8_1137 = __frsqrte(380000.0);
    temp_f4_1144 = 0.5 * temp_f3_1135 * -((2014000.0 * (temp_f3_1135 * temp_f3_1135)) - 3.0);
    temp_f1_1147 = 0.5 * temp_f8_1137 * -((380000.0 * (temp_f8_1137 * temp_f8_1137)) - 3.0);
    temp_f4_1152 = 0.5 * temp_f4_1144 * -((2014000.0 * (temp_f4_1144 * temp_f4_1144)) - 3.0);
    temp_f1_1155 = 0.5 * temp_f1_1147 * -((380000.0 * (temp_f1_1147 * temp_f1_1147)) - 3.0);
    temp_f0_1166 = (f32) (380000.0 * (0.5 * temp_f1_1155 * -((380000.0 * (temp_f1_1155 * temp_f1_1155)) - 3.0)));
    SPYRO_BOUNCE_Y_SPEED = (f32) (2014000.0 * (0.5 * temp_f4_1152 * -((2014000.0 * (temp_f4_1152 * temp_f4_1152)) - 3.0)));
    SPYRO_MIN_JUMP_Y_VELOCITY = temp_f0_1166;
}
