#include "spyro/source/FlyingBurningBits.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/CrashFirePS.h"
#include "unplaced_enums.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKView.h"
#include "common/Source/StdMath.h"
#include "common/gc/MKMaterial_GC.h"
#include "common/gc/MKPrimitive_GC.h"
#include "spyro/source/KDRandom.h"
#include <m2c_macros.h>

M2C_UNK free(MKVector3 **);                         /* extern */
MKVector3 **malloc(M2C_UNK);                        /* extern */
extern M2C_UNK gEmptyPtrListDL;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern M2C_UNK gb;

#if 0 // DRAFT: undefined identifier 'sp18'
void FlyingBurningBits::Emit(const MKVector3 &arg0, const MKVector3 &arg1) {
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
    f32 sp20;
    f32 sp10;
    MKVector3 **temp_r6_15;
    MKVector3 **temp_r6_19;
    MKVector3 *temp_r31_21;

    temp_r6_15 = this->unk0;
    if ((u32) M2C_FIELD(temp_r6_15, u32 *, -4) != 0U) {
        temp_r6_19 = temp_r6_15 - 4;
        this->unk0 = temp_r6_19;
        temp_r31_21 = *temp_r6_19;
        if (temp_r31_21 != NULL) {
            M2C_FIELD(temp_r31_21, f64 *, 0) = (f64) M2C_FIELD(&arg0, f64 *, 0);
            M2C_FIELD(temp_r31_21, f64 *, 8) = (f64) M2C_FIELD(&arg0, f64 *, 8);
            M2C_FIELD(temp_r31_21, f64 *, 0x10) = (f64) M2C_FIELD(&arg1, f64 *, 0);
            M2C_FIELD(temp_r31_21, f64 *, 0x18) = (f64) M2C_FIELD(&arg1, f64 *, 8);
            M2C_FIELD(temp_r31_21, f32 *, 0x20) = 1.0f;
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
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $r31, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f2 */);
            sp28 = sp18;
            sp20 = (f32) M2C_FIELD(temp_r31_21, f64 *, 0x18) * 1.0f;
            sp30 = (f64) sp20;
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r31, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            sp38 = sp8;
            sp10 = temp_r31_21->unk8 + (f32) sp30;
            sp40 = (f64) sp10;
            if (MKCollision_RayCollide(*temp_r31_21, *((MKVector3 *) &sp38), (MKCollisionResult *) &sp48, (MKCollisionMode) 7, 0) != 0) {
                M2C_FIELD(temp_r31_21, f32 *, 0x20) = sp88;
            }
        }
    }
}
#endif

#if 0 // DRAFT: type mismatch
void FlyingBurningBits::Deinit() {
    MKHeap *temp_r3_137;
    MKVector3 **var_r31_111;
    MKVector3 **var_r3_112;
    MKVector3 **var_r4_110;
    MKVector3 *temp_r0_115;
    MKVector3 *temp_r0_134;
    u32 temp_r0_120;

    MKMaterial_Destroy(this->unk4);
    var_r4_110 = this->unk0;
    var_r31_111 = var_r4_110;
    var_r3_112 = var_r4_110;
loop_3:
    temp_r0_120 = M2C_FIELD(var_r3_112, u32 *, -4);
    var_r3_112 -= 4;
    if (temp_r0_120 != 0U) {
        temp_r0_115 = *var_r3_112;
        if (temp_r0_115 < var_r31_111) {
            var_r31_111 = (MKVector3 **) temp_r0_115;
        }
        goto loop_3;
    }
    if (var_r3_112 != &gEmptyPtrListDL) {
loop_9:
        temp_r0_134 = *var_r4_110;
        if (temp_r0_134 != NULL) {
            if (temp_r0_134 < var_r31_111) {
                var_r31_111 = (MKVector3 **) temp_r0_134;
            }
            var_r4_110 += 4;
            goto loop_9;
        }
        temp_r3_137 = var_r3_112->Current();
        if (temp_r3_137 != NULL) {
            ((MKHeap *) (temp_r3_137->Current()))->Free(var_r31_111, NULL, 0);
        } else {
            free(var_r31_111);
        }
    }
    this->unk0 = NULL;
}
#endif

#if 0 // DRAFT: function call 'memcpy(long, Matrix *, int)' does not match
void FlyingBurningBits::Draw() {
    M2C_UNK sp34C;
    f64 sp340;
    f64 sp338;
    f64 sp330;                                      /* compiler-managed */
    f64 sp328;                                      /* compiler-managed */
    f64 sp320;
    f64 sp318;
    f64 sp310;
    f64 sp308;
    f64 sp300;
    f64 sp2F8;
    f64 sp2F0;
    f64 sp2E8;
    f64 sp2E0;
    f64 sp2D8;
    f64 sp2D0;
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
    f64 sp278;
    f64 sp270;
    f64 sp268;
    f64 sp260;
    f64 sp258;
    f64 sp250;
    f64 sp248;
    f64 sp240;
    f64 sp238;
    f64 sp230;
    f64 sp228;
    f64 sp220;
    f64 sp218;
    f64 sp210;
    f64 sp208;
    f64 sp200;
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
    f32 sp1A4;
    f32 sp1A0;
    f32 sp19C;
    f32 sp198;
    f32 sp190;
    f32 sp18C;
    f32 sp188;
    f32 sp180;
    f32 sp170;
    f32 sp160;
    f32 sp150;
    f32 sp14C;
    f32 sp148;
    f32 sp140;
    f32 sp130;
    f32 sp120;
    f32 sp110;
    f32 sp100;
    f32 spF0;
    f32 spE0;
    f32 spD0;
    f32 spCC;
    f32 spC8;
    f32 spC0;
    f32 spB0;
    f32 spAC;
    f32 spA8;
    f32 spA0;
    f32 sp90;
    f32 sp80;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp60;
    f32 sp50;
    f32 sp40;
    f32 sp30;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    MKVector3 **var_r31_226;
    MKVector3 *temp_r3_664;
    f32 temp_f18_345;
    f32 var_f3_314;
    f32 var_f4_247;
    f32 var_f4_320;
    f64 temp_f1_253;
    f64 temp_f1_259;
    f64 temp_f1_263;
    s32 temp_r3_282;
    s32 var_r0_292;

    M2C_STRUCT_COPY((s32) &sp34C + 4, MKView_GetCameraMatrix() - 4 + 4, 0x40);
    sp198 = 1.0f;
    sp19C = 1.0f;
    sp1A0 = 1.0f;
    sp1A4 = 1.0f;
    sp338 = (f64) sp198;
    sp340 = (f64) sp1A0;
    MKMaterial_SetMaterial(this->unk4);
    MKPrimitive(0xC, 0);
    MKSetMatrix(Matrix::identity);
    var_r31_226 = this->unk0;
loop_28:
    if (var_r31_226 != NULL) {
        temp_r3_664 = *var_r31_226;
        if (temp_r3_664 != NULL) {
            sp328 = M2C_FIELD(temp_r3_664, f64 *, 0x10);
            sp330 = M2C_FIELD(temp_r3_664, f64 *, 0x18);
            var_f4_247 = ((f32) sp330 * (f32) sp330) + (((f32) sp328 * (f32) sp328) + (unksp32C * unksp32C));
            if (var_f4_247 > 0.000001f) {
                if (var_f4_247 > 0.0f) {
                    temp_f1_253 = __frsqrte(var_f4_247);
                    temp_f1_259 = 0.5 * temp_f1_253 * -(((f64) var_f4_247 * (temp_f1_253 * temp_f1_253)) - 3.0);
                    temp_f1_263 = 0.5 * temp_f1_259 * -(((f64) var_f4_247 * (temp_f1_259 * temp_f1_259)) - 3.0);
                    var_f4_247 = (f32) ((f64) var_f4_247 * (0.5 * temp_f1_263 * -(((f64) var_f4_247 * (temp_f1_263 * temp_f1_263)) - 3.0)));
                } else if (var_f4_247 < M2C_BITWISE(f32, 0.0)) {
                    var_f4_247 = __float_nan;
                } else {
                    sp10 = var_f4_247;
                    temp_r3_282 = M2C_BITWISE(s32, sp10) & 0x7F800000;
                    switch (temp_r3_282) {          /* irregular */
                    case 0x7F800000:
                        if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                            var_r0_292 = 1;
                        } else {
                            var_r0_292 = 2;
                        }
                        break;
                    case 0x0:
                        if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                            var_r0_292 = 5;
                        } else {
                            var_r0_292 = 3;
                        }
                        break;
                    default:
                        var_r0_292 = 4;
                        break;
                    }
                    if (var_r0_292 == 1) {
                        var_f4_247 = __float_nan;
                    }
                }
                var_f3_314 = 1.0f / var_f4_247;
            } else {
                var_f3_314 = 0.0f;
                var_f4_247 = 0.0f;
            }
            var_f4_320 = var_f4_247 / 1000.0f;
            sp328 = (f32) sp328 * var_f3_314;
            unksp32C *= var_f3_314;
            sp330 = (f32) sp330 * var_f3_314;
            if (var_f4_320 < 2.0f) {

            } else {
                var_f4_320 = 2.0f;
            }
            if (var_f4_320 > 0.0f) {

            } else {
                var_f4_320 = 0.0f;
            }
            temp_f18_345 = 150.0f * var_f4_320;
            sp18 = 1.0f;
            sp1C = 1.0f;
            sp18C = (sp378 * sp328) - (sp370 * sp330);
            sp188 = (sp374 * sp330) - (sp378 * unksp32C);
            sp190 = (sp370 * unksp32C) - (sp374 * sp328);
            sp20 = 1.0f;
            sp24 = 1.0f;
            sp318 = (f64) sp188;
            sp320 = (f64) sp190;
            sp308 = (f64) sp18;
            sp310 = (f64) sp20;
            sp338 = (f64) sp18;
            sp340 = (f64) sp20;
            MKBegin(4);
            MKSetColorV(*((MKVector4 *) &sp338));
            MKSetTexCoord1F(0.0f, 1.0f);
            sp148 = -(f32) sp318;
            sp14C = -unksp31C;
            sp150 = -(f32) sp320;
            sp2A8 = (f64) sp148;
            sp2B0 = (f64) sp150;
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f24 */);
            sp2B8 = sp138;
            sp140 = (f32) sp2B0 * 35.0f;
            sp2C0 = (f64) sp140;
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f18 */);
            sp2C8 = sp178;
            sp180 = sp330 * temp_f18_345;
            sp2D0 = (f64) sp180;
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f23 */);
            sp2D8 = sp168;
            sp170 = (f32) sp2D0 * 0.125f;
            sp2E0 = (f64) sp170;
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r3, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            sp2E8 = sp158;
            sp160 = (*var_r31_226)->unk8 + (f32) sp2E0;
            sp2F0 = (f64) sp160;
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            sp2F8 = sp128;
            sp130 = (f32) sp2F0 + (f32) sp2C0;
            sp300 = (f64) sp130;
            MKSetPositionV(*((MKVector3 *) &sp2F8));
            MKSetColorV(*((MKVector4 *) &sp338));
            MKSetTexCoord1F(0.0f, 0.0f);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f22 */);
            sp258 = spE8;
            spF0 = (f32) sp320 * 35.0f;
            sp260 = (f64) spF0;
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f18 */);
            sp268 = sp118;
            sp120 = sp330 * temp_f18_345;
            sp270 = (f64) sp120;
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f21 */);
            sp278 = sp108;
            sp110 = (f32) sp270 * 0.125f;
            sp280 = (f64) sp110;
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r3, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            sp288 = spF8;
            sp100 = (*var_r31_226)->unk8 + (f32) sp280;
            sp290 = (f64) sp100;
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            sp298 = spD8;
            spE0 = (f32) sp290 + (f32) sp260;
            sp2A0 = (f64) spE0;
            MKSetPositionV(*((MKVector3 *) &sp298));
            MKSetColorV(*((MKVector4 *) &sp338));
            MKSetTexCoord1F(1.0f, 1.0f);
            spA8 = -(f32) sp318;
            spAC = -unksp31C;
            spB0 = -(f32) sp320;
            sp1F8 = (f64) spA8;
            sp200 = (f64) spB0;
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f20 */);
            spC8 = -sp328;
            spCC = -unksp32C;
            spA0 = (f32) sp200 * 35.0f;
            spD0 = -sp330;
            sp218 = (f64) spC8;
            sp208 = sp98;
            sp210 = (f64) spA0;
            sp220 = (f64) spD0;
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f18 */);
            sp228 = spB8;
            spC0 = (f32) sp220 * temp_f18_345;
            sp230 = (f64) spC0;
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            sp238 = sp88;
            sp90 = (f32) sp230 + (f32) sp210;
            sp240 = (f64) sp90;
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r4, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            sp248 = sp78;
            sp80 = (*var_r31_226)->unk8 + (f32) sp240;
            sp250 = (f64) sp80;
            MKSetPositionV(*((MKVector3 *) &sp248));
            MKSetColorV(*((MKVector4 *) &sp338));
            MKSetTexCoord1F(1.0f, 0.0f);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f19 */);
            sp68 = -sp328;
            sp6C = -unksp32C;
            sp50 = (f32) sp320 * 35.0f;
            sp70 = -sp330;
            sp1B8 = (f64) sp68;
            sp1A8 = sp48;
            sp1B0 = (f64) sp50;
            sp1C0 = (f64) sp70;
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f18 */);
            sp1C8 = sp58;
            sp60 = (f32) sp1C0 * temp_f18_345;
            sp1D0 = (f64) sp60;
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            sp1D8 = sp38;
            sp40 = (f32) sp1D0 + (f32) sp1B0;
            sp1E0 = (f64) sp40;
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r4, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            sp1E8 = sp28;
            sp30 = (*var_r31_226)->unk8 + (f32) sp1E0;
            sp1F0 = (f64) sp30;
            MKSetPositionV(*((MKVector3 *) &sp1E8));
            MKEnd();
            var_r31_226 += 4;
            goto loop_28;
        }
    }
    MKEndPrimitive();
}
#endif

#if 0 // DRAFT: undefined identifier 'sp30'
void FlyingBurningBits::Update() {
    f64 spB8;
    f64 spB0;
    f64 spA8;
    f64 spA0;
    MKVector3 sp90;
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
    f32 sp28;
    f32 sp18;
    f32 sp8;
    MKVector3 **temp_r3_798;
    MKVector3 **var_r29_724;
    MKVector3 *temp_r3_833;
    MKVector3 *temp_r4_801;
    s32 var_r27_741;

    var_r29_724 = this->unk0;
loop_7:
    if (var_r29_724 != NULL) {
        temp_r3_833 = *var_r29_724;
        if (temp_r3_833 != NULL) {
            M2C_FIELD(temp_r3_833, f32 *, 0x20) = (f32) (M2C_FIELD(temp_r3_833, f32 *, 0x20) - gUpdateTimeDelta);
            M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
            if (M2C_FIELD(temp_r3_833, f32 *, 0x20) == 0.0f) {
                var_r27_741 = 0;
                do {
                    sp58 = -1.0f;
                    sp48 = 1.0f;
                    sp50 = -1.0f;
                    sp54 = -1.0f;
                    sp40 = 1.0f;
                    sp44 = 1.0f;
                    sp80 = (f64) sp50;
                    sp88 = (f64) sp58;
                    sp70 = (f64) sp40;
                    sp78 = (f64) sp48;
                    KDRand_Vector(sp90, *((MKVector3 *) &sp80));
                    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r30, 0x0, qr0 */);
                    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f28 */);
                    spA0 = sp30;
                    sp38 = sp90.unk8 * 240.00002f;
                    spA8 = (f64) sp38;
                    M2C_ERROR(/* unknown instruction: psq_lx $f0, $r28, $r0, 0x0, qr0 */);
                    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                    spB0 = sp20;
                    sp28 = (f32) spA8 + M2C_FIELD(temp_r3_833, f32 *, 0x18);
                    spB8 = (f64) sp28;
                    sp8 = MKRand_Float(&gViewSeed, 6.0f, 7.0f);
                    ((CrashFirePS *) (M2C_FIELD(&gb, CrashFirePS **, 0x68)))->Emit(*temp_r3_833, *((MKVector3 *) &spB0), sp8);
                    var_r27_741 += 1;
                } while (var_r27_741 < 4);
                temp_r3_798 = this->unk0;
                this->unk0 = temp_r3_798 + 4;
                temp_r4_801 = *temp_r3_798;
                *temp_r3_798 = *var_r29_724;
                *var_r29_724 = temp_r4_801;
            } else {
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $r3, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f27 */);
                sp60 = sp10;
                sp18 = M2C_FIELD(temp_r3_833, f32 *, 0x18) * gUpdateTimeDelta;
                sp68 = (f64) sp18;
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r3, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                M2C_ERROR(/* unknown instruction: psq_stx $f0, $zero, $r3, 0x0, qr0 */);
                temp_r3_833->unk8 += (f32) sp68;
            }
            var_r29_724 += 4;
            goto loop_7;
        }
    }
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void FlyingBurningBits::Init() {
    MKHeap *temp_r3_862;
    MKVector3 **temp_r3_884;
    MKVector3 **temp_r4_890;
    MKVector3 **var_r3_869;
    MKVector3 **var_r5_878;
    s32 var_ctr_882;

    temp_r3_862 = MKHeap::Current();
    if (temp_r3_862 != NULL) {
        var_r3_869 = ((MKHeap *) (temp_r3_862->Current()))->Alloc(0x378, NULL, 0);
    } else {
        var_r3_869 = malloc(0x378);
    }
    this->unk0 = var_r3_869;
    var_r5_878 = this->unk0;
    this->unk0 = var_r5_878 + 0x320;
    M2C_FIELD(var_r5_878, s32 *, 0x320) = 0;
    var_ctr_882 = 0x14;
    do {
        temp_r3_884 = this->unk0;
        this->unk0 = temp_r3_884 + 4;
        M2C_FIELD(temp_r3_884, MKVector3 ***, 4) = var_r5_878;
        var_r5_878 += 0x28;
        var_ctr_882 -= 1;
    } while (var_ctr_882 != 0);
    temp_r4_890 = this->unk0;
    this->unk0 = temp_r4_890 + 4;
    M2C_FIELD(temp_r4_890, MKVector3 ***, 4) = NULL;
    this->unk4 = MKMaterial_Create("fx_353");
}
#endif
