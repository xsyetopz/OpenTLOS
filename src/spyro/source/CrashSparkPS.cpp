#include "spyro/source/CrashSparkPS.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "common/Source/Texture.h"
#include "spyro/source/Level.h"
#include "unplaced_enums.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKView.h"
#include "common/Source/StdMath.h"
#include "common/gc/MKMaterial_GC.h"
#include "common/gc/MKPrimitive_GC.h"
#include <m2c_macros.h>

M2C_UNK free(void *);                               /* extern */
void *malloc(M2C_UNK);                              /* extern */
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;

#if 0 // DRAFT: undefined identifier '__float_nan'
void CrashSparkPS::Draw() {
    f32 sp410;
    f64 sp408;
    f32 sp400;
    f32 sp3FC;
    f32 sp3F8;
    f32 sp3F4;
    f32 sp3F0;
    M2C_UNK sp3BC;
    f64 sp3B0;
    f64 sp3A8;
    f64 sp3A0;
    f64 sp398;
    f64 sp390;
    f64 sp388;
    f64 sp380;
    f64 sp378;
    f64 sp370;                                      /* compiler-managed */
    f64 sp368;
    f64 sp360;                                      /* compiler-managed */
    f64 sp358;
    f64 sp350;                                      /* compiler-managed */
    f64 sp348;
    f64 sp340;                                      /* compiler-managed */
    f64 sp338;
    f64 sp330;                                      /* compiler-managed */
    f64 sp328;                                      /* compiler-managed */
    f64 sp320;                                      /* compiler-managed */
    f64 sp318;                                      /* compiler-managed */
    f64 sp310;
    f64 sp308;
    f64 sp300;
    f64 sp2F8;
    MKVector3 sp2E8;
    MKVector3 sp2D8;
    f64 sp2D0;
    f64 sp2C8;
    f64 sp2C0;
    f64 sp2B8;
    MKVector3 sp2A8;
    MKVector3 sp298;
    f64 sp290;
    f64 sp288;
    MKVector3 sp278;
    f64 sp270;
    f64 sp268;
    MKVector3 sp258;
    f64 sp250;
    f64 sp248;
    f64 sp240;
    f64 sp238;
    MKVector3 sp228;
    f64 sp220;
    f64 sp218;
    MKVector3 sp208;
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
    f64 sp1A0;
    f64 sp198;
    f64 sp190;
    f64 sp188;
    f64 sp180;
    f64 sp178;
    MKVector4 sp168;
    M2C_UNK sp158;
    f32 sp150;
    f32 sp14C;
    f32 sp148;
    f32 sp140;
    f32 sp13C;
    f32 sp138;
    f32 sp134;
    f32 sp130;
    f32 sp12C;
    f32 sp128;
    f32 sp120;
    f64 sp118;
    f32 sp110;
    f64 sp108;
    f32 sp100;
    f64 spF8;
    f32 spF0;
    f64 spE8;
    f32 spE0;
    f64 spD8;
    f32 spD0;
    f64 spC8;
    f32 spC0;
    f64 spB8;
    f32 spB0;
    f64 spA8;
    f32 spA0;
    f32 sp9C;
    f32 sp98;
    f32 sp90;
    f32 sp8C;
    f32 sp88;
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
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
    f32 sp14;
    f32 sp10;
    f32 temp_f14_665;
    f32 temp_f15_489;
    f32 temp_f1_488;
    f32 temp_f1_637;
    f32 temp_f7_295;
    f32 temp_f8_293;
    f32 temp_f9_291;
    f32 var_f2_282;
    f32 var_f5_123;
    f32 var_f6_102;
    f32 var_f7_211;
    f64 temp_f1_135;
    f64 temp_f1_141;
    f64 temp_f1_145;
    f64 temp_f1_221;
    f64 temp_f1_227;
    f64 temp_f1_231;
    f64 temp_f29_462;
    f64 temp_f2_518;
    f64 temp_f2_633;
    f64 temp_f31_459;
    s32 temp_r3_164;
    s32 temp_r3_250;
    s32 var_r0_174;
    s32 var_r0_260;
    s32 var_r25_441;
    s32 var_r30_443;
    void *temp_r3_479;

    MKMaterial_SetMaterial(M2C_FIELD(this->unk0, MKMaterial **, 0x38));
    MKPrimitive(0xC, 0);
    M2C_STRUCT_COPY((s32) &sp3BC + 4, MKView_GetCameraMatrix() - 4 + 4, 0x40);
    var_f6_102 = 0.0f;
    sp148 = 0.0f;
    sp14C = 1.0f;
    sp150 = 0.0f;
    sp328 = (f64) sp148;
    sp330 = (f64) sp150;
    sp140 = 0.0f;
    sp138 = 1.0f;
    sp13C = 0.0f;
    var_f5_123 = ((f32) sp330 * (f32) sp330) + (((f32) sp328 * (f32) sp328) + ((*(f32 *) ((u8 *) &sp310 + 0x1c)) * (*(f32 *) ((u8 *) &sp310 + 0x1c))));
    sp3F0 = 0.0f;
    sp3F4 = 0.0f;
    sp3F8 = 0.0f;
    sp3FC = 1.0f;
    sp318 = (f64) sp138;
    sp320 = (f64) sp140;
    if (var_f5_123 > 0.000001f) {
        if (var_f5_123 > 0.0f) {
            temp_f1_135 = __frsqrte(var_f5_123);
            temp_f1_141 = 0.5 * temp_f1_135 * -(((f64) var_f5_123 * (temp_f1_135 * temp_f1_135)) - 3.0);
            temp_f1_145 = 0.5 * temp_f1_141 * -(((f64) var_f5_123 * (temp_f1_141 * temp_f1_141)) - 3.0);
            var_f5_123 = (f32) ((f64) var_f5_123 * (0.5 * temp_f1_145 * -(((f64) var_f5_123 * (temp_f1_145 * temp_f1_145)) - 3.0)));
        } else if (var_f5_123 < M2C_BITWISE(f32, 0.0)) {
            var_f5_123 = __float_nan;
        } else {
            sp14 = var_f5_123;
            temp_r3_164 = M2C_BITWISE(s32, sp14) & 0x7F800000;
            switch (temp_r3_164) {                  /* switch 1; irregular */
            case 0x7F800000:                        /* switch 1 */
                if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                    var_r0_174 = 1;
                } else {
                    var_r0_174 = 2;
                }
                break;
            case 0x0:                               /* switch 1 */
                if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                    var_r0_174 = 5;
                } else {
                    var_r0_174 = 3;
                }
                break;
            default:                                /* switch 1 */
                var_r0_174 = 4;
                break;
            }
            if (var_r0_174 == 1) {
                var_f5_123 = __float_nan;
            }
        }
        var_f6_102 = 1.0f / var_f5_123;
    }
    var_f7_211 = ((f32) sp320 * (f32) sp320) + (((f32) sp318 * (f32) sp318) + ((*(f32 *) ((u8 *) &sp310 + 0xc)) * (*(f32 *) ((u8 *) &sp310 + 0xc))));
    sp328 = (f32) sp328 * var_f6_102;
    (*(f32 *) ((u8 *) &sp310 + 0x1c)) *= var_f6_102;
    sp330 = (f32) sp330 * var_f6_102;
    if (var_f7_211 > 0.000001f) {
        if (var_f7_211 > 0.0f) {
            temp_f1_221 = __frsqrte(var_f7_211);
            temp_f1_227 = 0.5 * temp_f1_221 * -(((f64) var_f7_211 * (temp_f1_221 * temp_f1_221)) - 3.0);
            temp_f1_231 = 0.5 * temp_f1_227 * -(((f64) var_f7_211 * (temp_f1_227 * temp_f1_227)) - 3.0);
            var_f7_211 = (f32) ((f64) var_f7_211 * (0.5 * temp_f1_231 * -(((f64) var_f7_211 * (temp_f1_231 * temp_f1_231)) - 3.0)));
        } else if (var_f7_211 < M2C_BITWISE(f32, 0.0)) {
            var_f7_211 = __float_nan;
        } else {
            sp10 = var_f7_211;
            temp_r3_250 = M2C_BITWISE(s32, sp10) & 0x7F800000;
            switch (temp_r3_250) {                  /* switch 2; irregular */
            case 0x7F800000:                        /* switch 2 */
                if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                    var_r0_260 = 1;
                } else {
                    var_r0_260 = 2;
                }
                break;
            case 0x0:                               /* switch 2 */
                if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                    var_r0_260 = 5;
                } else {
                    var_r0_260 = 3;
                }
                break;
            default:                                /* switch 2 */
                var_r0_260 = 4;
                break;
            }
            if (var_r0_260 == 1) {
                var_f7_211 = __float_nan;
            }
        }
        var_f2_282 = 1.0f / var_f7_211;
    } else {
        var_f2_282 = 0.0f;
    }
    temp_f9_291 = (f32) sp318 * var_f2_282;
    temp_f8_293 = (*(f32 *) ((u8 *) &sp310 + 0xc)) * var_f2_282;
    temp_f7_295 = (f32) sp320 * var_f2_282;
    sp128 = 1.0f;
    sp12C = 1.0f;
    sp50 = -temp_f7_295;
    sp130 = 1.0f;
    sp134 = 0.0f;
    sp48 = -temp_f9_291;
    sp4C = -temp_f8_293;
    sp318 = temp_f9_291;
    (*(f32 *) ((u8 *) &sp310 + 0xc)) = temp_f8_293;
    sp320 = temp_f7_295;
    sp308 = (f64) sp128;
    sp310 = (f64) sp130;
    sp2C8 = (f64) sp48;
    sp2D0 = (f64) sp50;
    sp2D8.operator*(10.0f);
    sp2E8.operator*(10.0f);
    sp118 = sp2E8 + M2C_BITWISE(f64, sp2D8);
    sp2F8 = sp118;
    sp120 = sp2E8.unk8 + sp2D8.unk8;
    sp378 = sp118;
    sp300 = (f64) sp120;
    sp380 = (f64) sp120;
    sp298.operator*(10.0f);
    sp2A8.operator*(10.0f);
    sp108 = sp2A8 + M2C_BITWISE(f64, sp298);
    sp40 = -sp320;
    sp110 = sp2A8.unk8 + sp298.unk8;
    sp38 = -sp318;
    sp3C = -(*(f32 *) ((u8 *) &sp310 + 0xc));
    sp2B8 = sp108;
    sp2C0 = (f64) sp110;
    sp388 = sp108;
    sp390 = (f64) sp110;
    sp248 = (f64) sp38;
    sp250 = (f64) sp40;
    sp258.operator*(10.0f);
    sp28 = -sp328;
    sp2C = -(*(f32 *) ((u8 *) &sp310 + 0x1c));
    sp30 = -sp330;
    sp268 = (f64) sp28;
    sp270 = (f64) sp30;
    sp278.operator*(10.0f);
    spF8 = sp278 + M2C_BITWISE(f64, sp258);
    sp288 = spF8;
    sp100 = sp278.unk8 + sp258.unk8;
    sp398 = spF8;
    sp290 = (f64) sp100;
    sp3A0 = (f64) sp100;
    sp208.operator*(10.0f);
    sp18 = -sp328;
    sp1C = -(*(f32 *) ((u8 *) &sp310 + 0x1c));
    sp20 = -sp330;
    sp218 = (f64) sp18;
    sp220 = (f64) sp20;
    sp228.operator*(10.0f);
    spE8 = sp228 + M2C_BITWISE(f64, sp208);
    var_r25_441 = 0;
    var_r30_443 = 0;
    sp3A8 = spE8;
    spF0 = sp228.unk8 + sp208.unk8;
    sp410 = (f32) sp380;
    sp238 = spE8;
    sp3B0 = (f64) spF0;
    sp240 = (f64) spF0;
    sp408 = sp388;
    sp400 = (f32) sp390;
    temp_f31_459 = sp398;
    temp_f29_462 = sp3A8;
    do {
        temp_r3_479 = ((u8 *) this->unk4C) + var_r30_443;
        if ((u8) M2C_FIELD(temp_r3_479, u8 *, 0x34) != 0) {
            temp_f1_488 = 1.0f - (M2C_FIELD(temp_r3_479, f32 *, 0x38) / M2C_FIELD(temp_r3_479, f32 *, 0x48));
            temp_f15_489 = temp_f1_488 * M2C_FIELD(temp_r3_479, f32 *, 0x30);
            spD8 = sp378 * (f64) temp_f15_489;
            spE0 = sp410 * temp_f15_489;
            sp1F8 = spD8;
            sp200 = (f64) spE0;
            sp338 = spD8;
            sp340 = (f64) spE0;
            spC8 = sp408 * (f64) temp_f15_489;
            sp1E8 = spC8;
            spD0 = sp400 * temp_f15_489;
            sp348 = spC8;
            sp1F0 = (f64) spD0;
            sp350 = (f64) spD0;
            spB8 = temp_f31_459 * (f64) temp_f15_489;
            temp_f2_518 = temp_f29_462 * (f64) temp_f15_489;
            spC0 = (f32) sp3A0 * temp_f15_489;
            sp1D8 = spB8;
            sp1E0 = (f64) spC0;
            sp358 = spB8;
            sp360 = (f64) spC0;
            spA8 = temp_f2_518;
            spB0 = (f32) sp3B0 * temp_f15_489;
            sp1C8 = temp_f2_518;
            sp368 = temp_f2_518;
            sp1D0 = (f64) spB0;
            sp370 = (f64) spB0;
            sp98 = sp3F0 + (((f32) sp340 * sp3E0) + (((f32) sp338 * sp3C0) + ((*(f32 *) ((u8 *) &sp338 + 0x4)) * sp3D0)));
            sp9C = sp3F4 + (((f32) sp340 * sp3E4) + (((f32) sp338 * sp3C4) + ((*(f32 *) ((u8 *) &sp338 + 0x4)) * sp3D4)));
            spA0 = sp3F8 + (((f32) sp340 * sp3E8) + (((f32) sp338 * sp3C8) + ((*(f32 *) ((u8 *) &sp338 + 0x4)) * sp3D8)));
            sp1B8 = (f64) sp98;
            sp1C0 = (f64) spA0;
            sp338 = (f64) sp98;
            sp340 = (f64) spA0;
            sp88 = sp3F0 + (((f32) sp350 * sp3E0) + (((f32) sp348 * sp3C0) + ((*(f32 *) ((u8 *) &sp348 + 0x4)) * sp3D0)));
            sp8C = sp3F4 + (((f32) sp350 * sp3E4) + (((f32) sp348 * sp3C4) + ((*(f32 *) ((u8 *) &sp348 + 0x4)) * sp3D4)));
            sp90 = sp3F8 + (((f32) sp350 * sp3E8) + (((f32) sp348 * sp3C8) + ((*(f32 *) ((u8 *) &sp348 + 0x4)) * sp3D8)));
            sp80 = sp3F8 + (((f32) sp360 * sp3E8) + (((f32) sp358 * sp3C8) + ((*(f32 *) ((u8 *) &sp358 + 0x4)) * sp3D8)));
            sp70 = sp3F8 + (((f32) sp370 * sp3E8) + (((f32) sp368 * sp3C8) + ((*(f32 *) ((u8 *) &sp368 + 0x4)) * sp3D8)));
            sp78 = sp3F0 + (((f32) sp360 * sp3E0) + (((f32) sp358 * sp3C0) + ((*(f32 *) ((u8 *) &sp358 + 0x4)) * sp3D0)));
            sp7C = sp3F4 + (((f32) sp360 * sp3E4) + (((f32) sp358 * sp3C4) + ((*(f32 *) ((u8 *) &sp358 + 0x4)) * sp3D4)));
            sp68 = sp3F0 + (((f32) sp370 * sp3E0) + (((f32) sp368 * sp3C0) + ((*(f32 *) ((u8 *) &sp368 + 0x4)) * sp3D0)));
            sp6C = sp3F4 + (((f32) sp370 * sp3E4) + (((f32) sp368 * sp3C4) + ((*(f32 *) ((u8 *) &sp368 + 0x4)) * sp3D4)));
            sp348 = (f64) sp88;
            sp350 = (f64) sp90;
            sp358 = (f64) sp78;
            sp360 = (f64) sp80;
            sp368 = (f64) sp68;
            sp370 = (f64) sp70;
            sp1A8 = (f64) sp88;
            sp1B0 = (f64) sp90;
            sp198 = (f64) sp78;
            sp1A0 = (f64) sp80;
            sp188 = (f64) sp68;
            sp190 = (f64) sp70;
            temp_f2_633 = M2C_FIELD(temp_r3_479, f64 *, 0);
            sp338 += temp_f2_633;
            temp_f1_637 = M2C_FIELD(temp_r3_479, f32 *, 8);
            sp340 = (f32) sp340 + temp_f1_637;
            sp348 += temp_f2_633;
            sp350 = (f32) sp350 + temp_f1_637;
            sp358 += temp_f2_633;
            sp360 = (f32) sp360 + temp_f1_637;
            sp368 += temp_f2_633;
            sp370 = (f32) sp370 + temp_f1_637;
            MKSetMatrix(Matrix::identity);
            temp_f14_665 = MKRand_Float((int *) &gViewSeed, 0.2f, 1.0f);
            MKVector(1.0f, 1.0f, 0.8f, 1.0f);
            sp168.operator*(temp_f14_665);
            sp58 = M2C_FIELD(&sp168, f64 *, 0) * (f64) temp_f1_488;
            sp60 = M2C_FIELD(&sp168, f64 *, 8) * (f64) temp_f1_488;
            sp310 = sp60;
            sp178 = sp58;
            sp180 = sp60;
            sp308 = sp58;
            (*(f32 *) ((u8 *) &sp310 + 0x4)) = 1.0f;
            MKBegin(4);
            MKSetColorV(*((MKVector4 *) &sp308));
            MKSetTexCoord1F(0.0f, 0.0f);
            MKSetPositionV(*((MKVector3 *) &sp338));
            MKSetColorV(*((MKVector4 *) &sp308));
            MKSetTexCoord1F(1.0f, 0.0f);
            MKSetPositionV(*((MKVector3 *) &sp348));
            MKSetColorV(*((MKVector4 *) &sp308));
            MKSetTexCoord1F(0.0f, 1.0f);
            MKSetPositionV(*((MKVector3 *) &sp358));
            MKSetColorV(*((MKVector4 *) &sp308));
            MKSetTexCoord1F(1.0f, 1.0f);
            MKSetPositionV(*((MKVector3 *) &sp368));
            MKEnd();
        }
        var_r25_441 += 1;
        var_r30_443 += 0x50;
    } while (var_r25_441 < 0xC8);
    MKEndPrimitive();
}
#endif

#if 0 // DRAFT: undefined identifier 'MKVector'
void CrashSparkPS::Update() {
    f64 sp58;
    f64 sp50;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    s32 sp8;
    f32 temp_f31_848;
    f64 temp_f0_854;
    f64 temp_f0_884;
    s32 temp_r3_878;
    void *temp_r0_879;
    void *temp_r3_826;
    void *temp_r3_837;
    void *temp_r3_865;
    void *temp_r4_882;
    void *temp_r5_886;

    sp8 = 0;
loop_6:
    if (sp8 < 0xC8) {
        temp_r3_826 = ((u8 *) this->unk4C) + (sp8 * 0x50);
        if ((u8) M2C_FIELD(temp_r3_826, u8 *, 0x34) != 0) {
            M2C_FIELD(temp_r3_826, f32 *, 0x38) = (f32) (M2C_FIELD(temp_r3_826, f32 *, 0x38) + gUpdateTimeDelta);
            temp_r3_837 = ((u8 *) this->unk4C) + (sp8 * 0x50);
            if (M2C_FIELD(temp_r3_837, f32 *, 0x38) >= M2C_FIELD(temp_r3_837, f32 *, 0x48)) {
                M2C_FIELD(temp_r3_837, s8 *, 0x34) = 0;
            }
            temp_f31_848 = gUpdateTimeDelta;
            MKVector(0.0f, -980.0f, 0.0f);
            temp_f0_854 = sp40 * (f64) temp_f31_848;
            sp20 = temp_f0_854;
            sp50 = temp_f0_854;
            sp28 = sp48 * temp_f31_848;
            temp_r3_865 = ((u8 *) this->unk4C) + ((sp8 * 0x50) + 0x20);
            sp58 = (f64) sp28;
            M2C_FIELD(temp_r3_865, f64 *, 0) = (f64) (M2C_FIELD(temp_r3_865, f64 *, 0) + temp_f0_854);
            M2C_FIELD(temp_r3_865, f32 *, 8) = (f32) (M2C_FIELD(temp_r3_865, f32 *, 8) + (f32) sp58);
            temp_r3_878 = sp8 * 0x50;
            temp_r0_879 = this->unk4C;
            temp_r4_882 = ((u8 *) temp_r0_879) + (temp_r3_878 + 0x20);
            temp_f0_884 = M2C_FIELD(temp_r4_882, f64 *, 0) * (f64) gUpdateTimeDelta;
            sp10 = temp_f0_884;
            temp_r5_886 = ((u8 *) temp_r0_879) + temp_r3_878;
            sp30 = temp_f0_884;
            sp18 = M2C_FIELD(temp_r4_882, f32 *, 8) * gUpdateTimeDelta;
            sp38 = (f64) sp18;
            M2C_FIELD(temp_r5_886, f64 *, 0) = (f64) (M2C_FIELD(temp_r5_886, f64 *, 0) + temp_f0_884);
            M2C_FIELD(temp_r5_886, f32 *, 8) = (f32) (M2C_FIELD(temp_r5_886, f32 *, 8) + (f32) sp38);
            UpdateCollision(sp8);
        }
        sp8 += 1;
        goto loop_6;
    }
}
#endif

#if 0 // DRAFT: illegal operand
void CrashSparkPS::UpdateCollision(const int &arg0) {
    s8 sp1A8;
    s32 sp1A4;
    s32 sp1A0;
    s32 sp19C;
    f32 sp198;
    s32 sp194;
    s8 sp193;
    s8 sp192;
    s16 sp190;
    f32 sp18C;
    f32 sp188;
    f32 sp184;
    f32 sp180;
    f32 sp17C;
    f32 sp178;
    f32 sp170;
    f32 sp16C;
    f32 sp168;
    f32 sp160;
    f32 sp15C;
    f32 sp158;
    f64 sp150;                                      /* compiler-managed */
    f64 sp148;                                      /* compiler-managed */
    f64 sp140;
    f64 sp138;
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
    MKVector3 spC8;
    f64 spC0;
    f64 spB8;
    f64 spB0;
    f64 spA8;
    f32 spA0;
    f64 sp98;
    f32 sp90;
    f64 sp88;
    f32 sp80;
    f64 sp78;
    f32 sp70;
    f64 sp68;
    f32 sp60;
    f64 sp58;
    f32 sp50;
    f64 sp48;
    f32 sp40;
    f64 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    MKVector3 *temp_r3_1477;
    f32 temp_f1_1059;
    f32 temp_f1_1175;
    f32 temp_f29_966;
    f32 temp_f2_1058;
    f32 temp_f2_1174;
    f32 temp_f3_1007;
    f32 temp_f3_1061;
    f32 temp_f3_1176;
    f32 temp_f3_1258;
    f32 temp_f4_951;
    f32 var_f28_1065;
    f32 var_f2_1132;
    f32 var_f2_1248;
    f32 var_f30_1419;
    f32 var_f4_1181;
    f32 var_f4_1281;
    f32 var_f5_1323;
    f64 temp_f0_1031;
    f64 temp_f0_1467;
    f64 temp_f0_1482;
    f64 temp_f0_1505;
    f64 temp_f1_1003;
    f64 temp_f1_1013;
    f64 temp_f1_1023;
    f64 temp_f1_1071;
    f64 temp_f1_1077;
    f64 temp_f1_1081;
    f64 temp_f1_1187;
    f64 temp_f1_1193;
    f64 temp_f1_1197;
    f64 temp_f1_1328;
    f64 temp_f1_1334;
    f64 temp_f1_1338;
    f64 temp_f1_1403;
    f64 temp_f1_1409;
    f64 temp_f1_1413;
    f64 temp_f1_948;
    f64 temp_f5_947;
    s32 temp_r3_1100;
    s32 temp_r3_1153;
    s32 temp_r3_1216;
    s32 temp_r3_1357;
    s32 temp_r3_1432;
    s32 temp_r4_1051;
    s32 temp_r4_1501;
    s32 var_r0_1110;
    s32 var_r0_1226;
    s32 var_r0_1367;
    s32 var_r0_1442;
    void *temp_r3_1269;
    void *temp_r3_1311;
    void *temp_r3_1502;
    void *temp_r3_1539;
    void *temp_r3_945;
    void *temp_r4_1173;
    void *temp_r4_944;
    void *temp_r4_977;
    void *temp_r5_1057;
    void *temp_r5_1155;

    temp_r4_944 = ((u8 *) this->unk4C) + (&arg0 * 0x50);
    temp_r3_945 = ((u8 *) temp_r4_944) + 0x10;
    temp_f5_947 = M2C_FIELD(temp_r4_944, f64 *, 0);
    temp_f1_948 = M2C_FIELD(temp_r3_945, f64 *, 0) - temp_f5_947;
    sp98 = temp_f1_948;
    temp_f4_951 = M2C_FIELD(temp_r4_944, f32 *, 8);
    sp128 = temp_f1_948;
    spA0 = M2C_FIELD(temp_r3_945, f32 *, 8) - temp_f4_951;
    sp130 = (f64) spA0;
    temp_f29_966 = ((f32) sp130 * (f32) sp130) + (((f32) sp128 * (f32) sp128) + ((*(f32 *) ((u8 *) &sp128 + 0x4)) * (*(f32 *) ((u8 *) &sp128 + 0x4))));
    if (((u8) M2C_FIELD(temp_r4_944, u8 *, 0x40) != 0) && (temp_f29_966 >= M2C_FIELD(temp_r4_944, f32 *, 0x44))) {
        temp_r4_977 = ((u8 *) temp_r4_944) + 0x20;
        sp158 = 0.0f;
        sp15C = 0.0f;
        sp160 = 0.0f;
        sp168 = 0.0f;
        sp16C = 0.0f;
        sp170 = 0.0f;
        sp178 = 0.0f;
        sp17C = 0.0f;
        sp180 = 0.0f;
        sp184 = 1.0f;
        sp188 = 0.0f;
        sp18C = 0.0f;
        sp190 = 0;
        sp192 = 0;
        sp193 = 0;
        sp194 = 0;
        sp198 = 3.4028235e38f;
        sp19C = 0;
        sp1A0 = 0;
        sp1A4 = -1;
        sp1A8 = 0;
        temp_f1_1003 = M2C_FIELD(temp_r4_977, f64 *, 0) * (f64) gUpdateTimeDelta;
        sp88 = temp_f1_1003;
        temp_f3_1007 = M2C_FIELD(temp_r4_977, f32 *, 8) * gUpdateTimeDelta;
        sp108 = temp_f1_1003;
        sp90 = temp_f3_1007;
        sp110 = (f64) sp90;
        temp_f1_1013 = temp_f5_947 - temp_f1_1003;
        sp78 = temp_f1_1013;
        sp118 = temp_f1_1013;
        sp80 = temp_f4_951 - (f32) sp110;
        sp120 = (f64) sp80;
        temp_f1_1023 = M2C_FIELD(temp_r4_977, f64 *, 0) * (f64) gUpdateTimeDelta;
        sp68 = temp_f1_1023;
        sp70 = temp_f3_1007;
        spE8 = temp_f1_1023;
        spF0 = (f64) sp70;
        temp_f0_1031 = temp_f5_947 + spE8;
        sp58 = temp_f0_1031;
        spF8 = temp_f0_1031;
        sp60 = temp_f4_951 + (f32) spF0;
        sp100 = (f64) sp60;
        if (MKCollision_RayCollide(*((MKVector3 *) &sp118), *((MKVector3 *) &spF8), (MKCollisionResult *) &sp158, (MKCollisionMode) 7, 0) != 0) {
            temp_r4_1051 = &arg0 * 0x50;
            M2C_FIELD((((u8 *) this->unk4C) + temp_r4_1051), s8 *, 0x40) = 0;
            temp_r5_1057 = ((u8 *) this->unk4C) + (temp_r4_1051 + 0x20);
            temp_f2_1058 = M2C_FIELD(temp_r5_1057, f32 *, 0);
            temp_f1_1059 = M2C_FIELD(temp_r5_1057, f32 *, 4);
            temp_f3_1061 = M2C_FIELD(temp_r5_1057, f32 *, 8);
            var_f28_1065 = (temp_f3_1061 * temp_f3_1061) + ((temp_f2_1058 * temp_f2_1058) + (temp_f1_1059 * temp_f1_1059));
            if (var_f28_1065 > 0.000001f) {
                if (var_f28_1065 > 0.0f) {
                    temp_f1_1071 = __frsqrte(var_f28_1065);
                    temp_f1_1077 = 0.5 * temp_f1_1071 * -(((f64) var_f28_1065 * (temp_f1_1071 * temp_f1_1071)) - 3.0);
                    temp_f1_1081 = 0.5 * temp_f1_1077 * -(((f64) var_f28_1065 * (temp_f1_1077 * temp_f1_1077)) - 3.0);
                    var_f28_1065 = (f32) ((f64) var_f28_1065 * (0.5 * temp_f1_1081 * -(((f64) var_f28_1065 * (temp_f1_1081 * temp_f1_1081)) - 3.0)));
                } else if (var_f28_1065 < M2C_BITWISE(f32, 0.0)) {
                    var_f28_1065 = __float_nan;
                } else {
                    sp14 = var_f28_1065;
                    temp_r3_1100 = M2C_BITWISE(s32, sp14) & 0x7F800000;
                    switch (temp_r3_1100) {         /* switch 1; irregular */
                    case 0x7F800000:                /* switch 1 */
                        if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                            var_r0_1110 = 1;
                        } else {
                            var_r0_1110 = 2;
                        }
                        break;
                    case 0x0:                       /* switch 1 */
                        if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                            var_r0_1110 = 5;
                        } else {
                            var_r0_1110 = 3;
                        }
                        break;
                    default:                        /* switch 1 */
                        var_r0_1110 = 4;
                        break;
                    }
                    if (var_r0_1110 == 1) {
                        var_f28_1065 = __float_nan;
                    }
                }
                var_f2_1132 = 1.0f / var_f28_1065;
            } else {
                var_f2_1132 = 0.0f;
                var_f28_1065 = 0.0f;
            }
            M2C_FIELD(temp_r5_1057, f32 *, 0) = (f32) (M2C_FIELD(temp_r5_1057, f32 *, 0) * var_f2_1132);
            M2C_FIELD(temp_r5_1057, f32 *, 4) = (f32) (M2C_FIELD(temp_r5_1057, f32 *, 4) * var_f2_1132);
            M2C_FIELD(temp_r5_1057, f32 *, 8) = (f32) (M2C_FIELD(temp_r5_1057, f32 *, 8) * var_f2_1132);
            spC8.operator*(2.0f);
            temp_r3_1153 = &arg0 * 0x50;
            temp_r5_1155 = ((u8 *) this->unk4C) + (temp_r3_1153 + 0x20);
            sp18 = M2C_FIELD(temp_r5_1155, f64 *, 0) + M2C_BITWISE(f64, spC8);
            M2C_FIELD(temp_r5_1155, f64 *, 0) = sp18;
            sp20 = M2C_FIELD(temp_r5_1155, f32 *, 8) + spC8.unk8;
            spD8 = sp18;
            M2C_FIELD(temp_r5_1155, f32 *, 8) = (f64) sp20;
            spE0 = (f64) sp20;
            temp_r4_1173 = ((u8 *) this->unk4C) + (temp_r3_1153 + 0x20);
            temp_f2_1174 = M2C_FIELD(temp_r4_1173, f32 *, 0);
            temp_f1_1175 = M2C_FIELD(temp_r4_1173, f32 *, 4);
            temp_f3_1176 = M2C_FIELD(temp_r4_1173, f32 *, 8);
            var_f4_1181 = (temp_f3_1176 * temp_f3_1176) + ((temp_f2_1174 * temp_f2_1174) + (temp_f1_1175 * temp_f1_1175));
            if (var_f4_1181 > 0.000001f) {
                if (var_f4_1181 > 0.0f) {
                    temp_f1_1187 = __frsqrte(var_f4_1181);
                    temp_f1_1193 = 0.5 * temp_f1_1187 * -(((f64) var_f4_1181 * (temp_f1_1187 * temp_f1_1187)) - 3.0);
                    temp_f1_1197 = 0.5 * temp_f1_1193 * -(((f64) var_f4_1181 * (temp_f1_1193 * temp_f1_1193)) - 3.0);
                    var_f4_1181 = (f32) ((f64) var_f4_1181 * (0.5 * temp_f1_1197 * -(((f64) var_f4_1181 * (temp_f1_1197 * temp_f1_1197)) - 3.0)));
                } else if (var_f4_1181 < M2C_BITWISE(f32, 0.0)) {
                    var_f4_1181 = __float_nan;
                } else {
                    sp10 = var_f4_1181;
                    temp_r3_1216 = M2C_BITWISE(s32, sp10) & 0x7F800000;
                    switch (temp_r3_1216) {         /* switch 2; irregular */
                    case 0x7F800000:                /* switch 2 */
                        if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                            var_r0_1226 = 1;
                        } else {
                            var_r0_1226 = 2;
                        }
                        break;
                    case 0x0:                       /* switch 2 */
                        if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                            var_r0_1226 = 5;
                        } else {
                            var_r0_1226 = 3;
                        }
                        break;
                    default:                        /* switch 2 */
                        var_r0_1226 = 4;
                        break;
                    }
                    if (var_r0_1226 == 1) {
                        var_f4_1181 = __float_nan;
                    }
                }
                var_f2_1248 = 1.0f / var_f4_1181;
            } else {
                var_f2_1248 = 0.0f;
            }
            temp_f3_1258 = 0.75f * var_f28_1065;
            M2C_FIELD(temp_r4_1173, f32 *, 0) = (f32) (M2C_FIELD(temp_r4_1173, f32 *, 0) * var_f2_1248);
            M2C_FIELD(temp_r4_1173, f32 *, 4) = (f32) (M2C_FIELD(temp_r4_1173, f32 *, 4) * var_f2_1248);
            M2C_FIELD(temp_r4_1173, f32 *, 8) = (f32) (M2C_FIELD(temp_r4_1173, f32 *, 8) * var_f2_1248);
            temp_r3_1269 = ((u8 *) this->unk4C) + ((&arg0 * 0x50) + 0x20);
            M2C_FIELD(temp_r3_1269, f64 *, 0) = (f64) (M2C_FIELD(temp_r3_1269, f64 *, 0) * (f64) temp_f3_1258);
            M2C_FIELD(temp_r3_1269, f32 *, 8) = (f32) (M2C_FIELD(temp_r3_1269, f32 *, 8) * temp_f3_1258);
        }
    }
    if (temp_f29_966 >= 900.0001f) {
        var_f4_1281 = 0.0f;
        sp158 = 0.0f;
        sp15C = 0.0f;
        sp160 = 0.0f;
        sp168 = 0.0f;
        sp16C = 0.0f;
        sp170 = 0.0f;
        sp178 = 0.0f;
        sp17C = 0.0f;
        sp180 = 0.0f;
        sp184 = 1.0f;
        sp188 = 0.0f;
        sp18C = 0.0f;
        sp190 = 0;
        sp192 = 0;
        sp193 = 0;
        sp194 = 0;
        sp198 = 3.4028235e38f;
        sp19C = 0;
        sp1A0 = 0;
        sp1A4 = -1;
        sp1A8 = 0;
        temp_r3_1311 = ((u8 *) this->unk4C) + (&arg0 * 0x50);
        sp148 = M2C_FIELD(temp_r3_1311, f64 *, 0x20);
        sp150 = M2C_FIELD(temp_r3_1311, f64 *, 0x28);
        var_f5_1323 = ((f32) sp150 * (f32) sp150) + (((f32) sp148 * (f32) sp148) + ((*(f32 *) ((u8 *) &sp140 + 0xc)) * (*(f32 *) ((u8 *) &sp140 + 0xc))));
        if (var_f5_1323 > 0.000001f) {
            if (var_f5_1323 > 0.0f) {
                temp_f1_1328 = __frsqrte(var_f5_1323);
                temp_f1_1334 = 0.5 * temp_f1_1328 * -(((f64) var_f5_1323 * (temp_f1_1328 * temp_f1_1328)) - 3.0);
                temp_f1_1338 = 0.5 * temp_f1_1334 * -(((f64) var_f5_1323 * (temp_f1_1334 * temp_f1_1334)) - 3.0);
                var_f5_1323 = (f32) ((f64) var_f5_1323 * (0.5 * temp_f1_1338 * -(((f64) var_f5_1323 * (temp_f1_1338 * temp_f1_1338)) - 3.0)));
            } else if (var_f5_1323 < M2C_BITWISE(f32, 0.0)) {
                var_f5_1323 = __float_nan;
            } else {
                spC = var_f5_1323;
                temp_r3_1357 = M2C_BITWISE(s32, spC) & 0x7F800000;
                switch (temp_r3_1357) {             /* switch 3; irregular */
                case 0x7F800000:                    /* switch 3 */
                    if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                        var_r0_1367 = 1;
                    } else {
                        var_r0_1367 = 2;
                    }
                    break;
                case 0x0:                           /* switch 3 */
                    if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                        var_r0_1367 = 5;
                    } else {
                        var_r0_1367 = 3;
                    }
                    break;
                default:                            /* switch 3 */
                    var_r0_1367 = 4;
                    break;
                }
                if (var_r0_1367 == 1) {
                    var_f5_1323 = __float_nan;
                }
            }
            var_f4_1281 = 1.0f / var_f5_1323;
        }
        sp148 = (f32) sp148 * var_f4_1281;
        (*(f32 *) ((u8 *) &sp140 + 0xc)) *= var_f4_1281;
        sp150 = (f32) sp150 * var_f4_1281;
        if (temp_f29_966 > 0.0f) {
            temp_f1_1403 = __frsqrte(temp_f29_966);
            temp_f1_1409 = 0.5 * temp_f1_1403 * -(((f64) temp_f29_966 * (temp_f1_1403 * temp_f1_1403)) - 3.0);
            temp_f1_1413 = 0.5 * temp_f1_1409 * -(((f64) temp_f29_966 * (temp_f1_1409 * temp_f1_1409)) - 3.0);
            var_f30_1419 = (f32) ((f64) temp_f29_966 * (0.5 * temp_f1_1413 * -(((f64) temp_f29_966 * (temp_f1_1413 * temp_f1_1413)) - 3.0)));
        } else if (temp_f29_966 < M2C_BITWISE(f32, 0.0)) {
            var_f30_1419 = __float_nan;
        } else {
            sp8 = temp_f29_966;
            temp_r3_1432 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r3_1432) {                 /* switch 4; irregular */
            case 0x7F800000:                        /* switch 4 */
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_1442 = 1;
                } else {
                    var_r0_1442 = 2;
                }
                break;
            case 0x0:                               /* switch 4 */
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_1442 = 5;
                } else {
                    var_r0_1442 = 3;
                }
                break;
            default:                                /* switch 4 */
                var_r0_1442 = 4;
                break;
            }
            if (var_r0_1442 == 1) {
                var_f30_1419 = __float_nan;
            } else {
                var_f30_1419 = temp_f29_966;
            }
        }
        temp_f0_1467 = (f64) sp148 * (f64) var_f30_1419;
        sp48 = temp_f0_1467;
        spA8 = temp_f0_1467;
        sp50 = sp150 * var_f30_1419;
        temp_r3_1477 = ((u8 *) this->unk4C) + (&arg0 * 0x50);
        spB0 = (f64) sp50;
        temp_f0_1482 = M2C_FIELD(temp_r3_1477, f64 *, 0) + temp_f0_1467;
        sp38 = temp_f0_1482;
        spB8 = temp_f0_1482;
        sp40 = temp_r3_1477->unk8 + (f32) spB0;
        spC0 = (f64) sp40;
        if (MKCollision_RayCollide(*temp_r3_1477, *((MKVector3 *) &spB8), (MKCollisionResult *) &sp158, (MKCollisionMode) 7, 0) != 0) {
            temp_r4_1501 = &arg0 * 0x50;
            temp_r3_1502 = ((u8 *) this->unk4C) + temp_r4_1501;
            temp_f0_1505 = (f64) sp158 - M2C_FIELD(temp_r3_1502, f64 *, 0);
            sp28 = temp_f0_1505;
            M2C_FIELD(temp_r3_1502, s8 *, 0x40) = 1;
            sp138 = temp_f0_1505;
            sp30 = sp160 - M2C_FIELD(temp_r3_1502, f32 *, 8);
            sp140 = (f64) sp30;
            M2C_FIELD((((u8 *) this->unk4C) + temp_r4_1501), f32 *, 0x44) = (f32) (((f32) sp140 * (f32) sp140) + (((f32) sp138 * (f32) sp138) + ((*(f32 *) ((u8 *) &sp138 + 0x4)) * (*(f32 *) ((u8 *) &sp138 + 0x4)))));
        } else {
            M2C_FIELD((((u8 *) this->unk4C) + (&arg0 * 0x50)), s8 *, 0x40) = 0;
        }
        temp_r3_1539 = ((u8 *) this->unk4C) + (&arg0 * 0x50);
        M2C_FIELD(temp_r3_1539, f64 *, 0x10) = (f64) M2C_FIELD(temp_r3_1539, f64 *, 0);
        M2C_FIELD(temp_r3_1539, f64 *, 0x18) = (f64) M2C_FIELD(temp_r3_1539, f64 *, 8);
    }
}
#endif

void CrashSparkPS::Deinit() {
    MKHeap *temp_r3_1572;
    void *temp_r31_1569;

    MKProp::Deinit();
    temp_r31_1569 = this->unk4C;
    if (temp_r31_1569 != NULL) {
        temp_r3_1572 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_1572 != NULL) {
            ((MKHeap *) (temp_r3_1572->Current()))->Free(temp_r31_1569, NULL, 0);
        } else {
            free(temp_r31_1569);
        }
        this->unk4C = NULL;
    }
}

#if 0 // DRAFT: illegal type
void CrashSparkPS::Init() {
    MKHeap *temp_r3_1604;
    s32 temp_r0_1624;
    s32 var_ctr_1621;
    s32 var_r4_1617;
    void *var_r3_1611;

    MKProp::Init();
    temp_r3_1604 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_1604 != NULL) {
        var_r3_1611 = ((MKHeap *) (temp_r3_1604->Current()))->Alloc(0x3E80, NULL, 0);
    } else {
        var_r3_1611 = malloc(0x3E80);
    }
    var_r4_1617 = 0;
    this->unk4C = var_r3_1611;
    var_ctr_1621 = 0xC8;
    do {
        temp_r0_1624 = var_r4_1617 + 0x34;
        var_r4_1617 += 0x50;
        *(this->unk4C + temp_r0_1624) = 0;
        var_ctr_1621 -= 1;
    } while (var_ctr_1621 != 0);
}
#endif
