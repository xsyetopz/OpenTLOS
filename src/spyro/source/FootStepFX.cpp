#include "spyro/source/FootStepFX.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKParticleSystem.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "common/Source/Texture.h"
#include "spyro/source/KDParticleSystem.h"
#include "spyro/source/Level.h"
#include "spyro/source/WaterDripPS.h"
#include "unplaced_templates.h"
#include "common/Source/MKView.h"
#include "common/Source/StdMath.h"
#include "common/gc/MKMaterial_GC.h"
#include "common/gc/MKPrimitive_GC.h"
#include "spyro/source/KDRandom.h"
#include <m2c_macros.h>

M2C_UNK free(void *);                               /* extern */
void *malloc(M2C_UNK);                              /* extern */
extern MKSceneManager *gMK;
extern s32 gViewSeed;
extern M2C_UNK gb;
static s32 lit_522 = 0;
static s32 lit_523 = 0xF;

#if 0 // DRAFT: undefined identifier 'MKVector'
void FootStepFX::EmitFootFX(const MKVector3 &arg0, const MKVector3 &arg1, const MKVector3 &arg2, MKVector4 arg3, float arg4, float arg5, int arg6) {
    f64 sp388;
    f64 sp380;
    f64 sp378;
    f64 sp370;
    MKVector3 sp360;
    f64 sp358;
    f64 sp350;
    f64 sp348;
    f64 sp340;
    f64 sp338;
    f64 sp330;
    MKVector3 sp320;
    MKVector3 sp310;
    M2C_UNK sp300;
    f64 sp2F8;
    f64 sp2F0;
    MKVector3 sp2E0;
    MKVector3 sp2D0;
    M2C_UNK sp2C0;
    f64 sp2B8;
    f64 sp2B0;
    MKVector3 sp2A0;
    f64 sp298;
    f64 sp290;
    f64 sp288;
    f64 sp280;
    f64 sp278;
    f64 sp270;
    MKVector3 sp260;
    MKVector3 sp250;
    M2C_UNK sp240;
    f64 sp238;
    f64 sp230;
    f64 sp228;
    f64 sp220;
    MKVector3 sp210;
    f64 sp208;
    f64 sp200;
    f64 sp1F8;
    f64 sp1F0;
    f64 sp1E8;
    f64 sp1E0;
    MKVector3 sp1D0;
    MKVector3 sp1C0;
    M2C_UNK sp1B0;
    f64 sp1A8;
    f64 sp1A0;
    MKVector3 sp190;
    f64 sp188;
    f64 sp180;
    f64 sp178;
    f64 sp170;
    f64 sp168;
    f64 sp160;
    MKVector3 sp150;
    MKVector3 sp140;
    M2C_UNK sp130;
    f32 sp128;
    f64 sp120;
    f32 sp118;
    f64 sp110;
    f32 sp108;
    f64 sp100;
    f32 spF8;
    f64 spF0;
    f32 spE8;
    f64 spE0;
    f32 spD8;
    f64 spD0;
    f32 spC8;
    f32 spC4;
    f32 spC0;
    f32 spB8;
    f64 spB0;
    f32 spA8;
    f64 spA0;
    f32 sp98;
    f32 sp94;
    f32 sp90;
    f32 sp88;
    f64 sp80;
    f32 sp78;
    f64 sp70;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp58;
    f64 sp50;
    f32 sp48;
    f64 sp40;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    f32 sp8;
    f32 temp_f27_256;
    f32 temp_f27_379;
    f32 temp_f27_495;
    f32 temp_f27_83;
    f32 temp_f28_257;
    f32 temp_f28_380;
    f32 temp_f28_496;
    f32 temp_f28_84;
    f32 temp_f29_255;
    f32 temp_f29_378;
    f32 temp_f29_498;
    f32 temp_f29_82;
    f32 temp_f30_254;
    f32 temp_f30_377;
    f32 temp_f30_497;
    f32 temp_f30_81;
    f64 temp_f0_110;
    f64 temp_f0_121;
    f64 temp_f0_283;
    f64 temp_f0_294;
    f64 temp_f0_407;
    f64 temp_f0_418;
    f64 temp_f0_525;
    f64 temp_f0_536;
    s32 temp_r30_72;
    s32 var_r24_191;
    s32 var_r24_250;
    s32 var_r24_77;
    s32 var_r27_381;
    s32 var_r27_499;
    void *temp_r24_451;
    void *temp_r24_569;
    void *temp_r27_154;
    void *temp_r27_327;
    void *temp_r31_70;
    void *temp_r3_146;
    void *temp_r3_151;
    void *temp_r3_319;
    void *temp_r3_324;
    void *temp_r3_443;
    void *temp_r3_448;
    void *temp_r3_561;
    void *temp_r3_566;

    temp_r31_70 = checked_cast<FootStepFXDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    temp_r30_72 = (s32) arg5;
    if (arg6 & 0x40) {
        var_r24_77 = 0;
        temp_f30_81 = -arg1.unk0;
        temp_f29_82 = -arg1.unk4;
        temp_f27_83 = arg2.unk8;
        temp_f28_84 = -arg1.unk8;
loop_5:
        if (var_r24_77 < temp_r30_72) {
            MKVector(1.0f, 1.0f, 1.0f);
            MKVector(-1.0f, -1.0f, -1.0f);
            KDRand_Vector(sp320, sp310);
            spC0 = temp_f30_81;
            spC4 = temp_f29_82;
            spC8 = temp_f28_84;
            sp330 = (f64) spC0;
            sp338 = (f64) spC8;
            temp_f0_110 = (f64) spC0 + M2C_FIELD(&arg2, f64 *, 0);
            spB0 = temp_f0_110;
            sp340 = temp_f0_110;
            spB8 = (f32) sp338 + temp_f27_83;
            sp348 = (f64) spB8;
            temp_f0_121 = sp340 + M2C_BITWISE(f64, sp320);
            spA0 = temp_f0_121;
            sp350 = temp_f0_121;
            spA8 = (f32) sp348 + sp320.unk8;
            sp358 = (f64) spA8;
            sp360.operator*(50.0f);
            sp120 = sp360 * (f64) arg5;
            sp380 = sp120;
            sp128 = sp360.unk8 * arg5;
            sp370 = sp120;
            sp388 = (f64) sp128;
            temp_r3_146 = M2C_FIELD(temp_r31_70, void **, 0x64);
            sp378 = (f64) sp128;
            temp_r3_151 = M2C_FIELD(M2C_FIELD(temp_r3_146, void **, 0x44), void *(**)(void *, f64), 0x3C)(temp_r3_146, sp120);
            if (temp_r3_151 != NULL) {
                temp_r27_154 = M2C_FIELD(temp_r3_151, void **, 0x2C);
                M2C_FIELD(temp_r3_151, f64 *, 0) = (f64) M2C_FIELD(&arg0, f64 *, 0);
                M2C_FIELD(temp_r3_151, f64 *, 8) = (f64) M2C_FIELD(&arg0, f64 *, 8);
                M2C_FIELD(temp_r3_151, f32 *, 0x20) = 0.0f;
                M2C_FIELD(temp_r3_151, f32 *, 0x28) = 0.0f;
                M2C_FIELD(temp_r3_151, f64 *, 0x10) = (f64) M2C_FIELD(arg3, f64 *, 0);
                M2C_FIELD(temp_r3_151, f64 *, 0x18) = (f64) M2C_FIELD(arg3, f64 *, 8);
                M2C_FIELD(temp_r27_154, f64 *, 0) = sp380;
                M2C_FIELD(temp_r27_154, f64 *, 8) = sp388;
                M2C_FIELD(temp_r27_154, f32 *, 0x18) = (f32) (0.25f * arg4);
                M2C_FIELD(temp_r27_154, f32 *, 0x10) = MKRand_Float((int *) &gViewSeed, -3.1415927f, 3.1415927f);
                M2C_FIELD(temp_r27_154, f32 *, 0x14) = (f32) M2C_FIELD(M2C_FIELD(temp_r31_70, void **, 0x64), f32 *, 0xF4);
            }
            var_r24_77 += 1;
            goto loop_5;
        }
        return;
    }
    if (arg6 & 0x200) {
        var_r24_191 = 0;
        do {
            MKVector(1.0f, 2.0f, 1.0f);
            MKVector(-1.0f, 1.0f, -1.0f);
            KDRand_Vector(sp2E0, sp2D0);
            sp110 = sp2E0 * 5.60222949e-315;
            sp2F0 = sp110;
            sp118 = sp2E0.unk8 * 300.0f;
            sp380 = sp110;
            sp2F8 = (f64) sp118;
            sp388 = (f64) sp118;
            sp8 = MKRand_Float((int *) &gViewSeed, 2.0f, 2.5f);
            ((WaterDripPS *) (M2C_FIELD(&gb, WaterDripPS **, 0x6C)))->Emit(arg0, *((MKVector3 *) &sp380), sp8, 1U, 1U, NULL);
            var_r24_191 += 1;
        } while (var_r24_191 < 5);
        return;
    }
    if ((arg6 & 0x10) || (arg6 & 0x800) || (arg6 & 0x80000) || (arg6 & 0x8000)) {
        var_r24_250 = 0;
        temp_f30_254 = -arg1.unk0;
        temp_f29_255 = -arg1.unk4;
        temp_f27_256 = arg2.unk8;
        temp_f28_257 = -arg1.unk8;
loop_19:
        if (var_r24_250 < temp_r30_72) {
            MKVector(1.0f, 1.0f, 1.0f);
            MKVector(-1.0f, -1.0f, -1.0f);
            KDRand_Vector(sp260, sp250);
            sp90 = temp_f30_254;
            sp94 = temp_f29_255;
            sp98 = temp_f28_257;
            sp270 = (f64) sp90;
            sp278 = (f64) sp98;
            temp_f0_283 = (f64) sp90 + M2C_FIELD(&arg2, f64 *, 0);
            sp80 = temp_f0_283;
            sp280 = temp_f0_283;
            sp88 = (f32) sp278 + temp_f27_256;
            sp288 = (f64) sp88;
            temp_f0_294 = sp280 + M2C_BITWISE(f64, sp260);
            sp70 = temp_f0_294;
            sp290 = temp_f0_294;
            sp78 = (f32) sp288 + sp260.unk8;
            sp298 = (f64) sp78;
            sp2A0.operator*(50.0f);
            sp100 = sp2A0 * (f64) arg5;
            sp380 = sp100;
            sp108 = sp2A0.unk8 * arg5;
            sp2B0 = sp100;
            sp388 = (f64) sp108;
            temp_r3_319 = M2C_FIELD(temp_r31_70, void **, 0x60);
            sp2B8 = (f64) sp108;
            temp_r3_324 = M2C_FIELD(M2C_FIELD(temp_r3_319, void **, 0x44), void *(**)(void *, f64), 0x3C)(temp_r3_319, sp100);
            if (temp_r3_324 != NULL) {
                temp_r27_327 = M2C_FIELD(temp_r3_324, void **, 0x2C);
                M2C_FIELD(temp_r3_324, f64 *, 0) = (f64) M2C_FIELD(&arg0, f64 *, 0);
                M2C_FIELD(temp_r3_324, f64 *, 8) = (f64) M2C_FIELD(&arg0, f64 *, 8);
                M2C_FIELD(temp_r3_324, f32 *, 0x20) = 0.0f;
                M2C_FIELD(temp_r3_324, f32 *, 0x28) = 0.0f;
                M2C_FIELD(temp_r3_324, f64 *, 0x10) = (f64) M2C_FIELD(arg3, f64 *, 0);
                M2C_FIELD(temp_r3_324, f64 *, 0x18) = (f64) M2C_FIELD(arg3, f64 *, 8);
                spF0 = sp380 * 5.180653787e-315;
                M2C_FIELD(temp_r27_327, f64 *, 0) = spF0;
                spF8 = (f32) sp388 * 0.25f;
                sp230 = spF0;
                M2C_FIELD(temp_r27_327, f64 *, 8) = (f64) spF8;
                sp238 = (f64) spF8;
                M2C_FIELD(temp_r27_327, f32 *, 0x18) = (f32) (0.1f * arg4);
                M2C_FIELD(temp_r27_327, f32 *, 0x10) = MKRand_Float((int *) &gViewSeed, -3.1415927f, 3.1415927f);
                M2C_FIELD(temp_r27_327, f32 *, 0x14) = (f32) M2C_FIELD(M2C_FIELD(temp_r31_70, void **, 0x60), f32 *, 0xF4);
            }
            var_r24_250 += 1;
            goto loop_19;
        }
        return;
    }
    if (arg6 & 0x10000) {
        temp_f30_377 = -arg1.unk0;
        temp_f29_378 = -arg1.unk4;
        temp_f27_379 = arg2.unk8;
        temp_f28_380 = -arg1.unk8;
        var_r27_381 = 0;
loop_26:
        if (var_r27_381 < (s32) (temp_r30_72 * 2)) {
            MKVector(1.0f, 1.0f, 1.0f);
            MKVector(-1.0f, -1.0f, -1.0f);
            KDRand_Vector(sp1D0, sp1C0);
            sp60 = temp_f30_377;
            sp64 = temp_f29_378;
            sp68 = temp_f28_380;
            sp1E0 = (f64) sp60;
            sp1E8 = (f64) sp68;
            temp_f0_407 = (f64) sp60 + M2C_FIELD(&arg2, f64 *, 0);
            sp50 = temp_f0_407;
            sp1F0 = temp_f0_407;
            sp58 = (f32) sp1E8 + temp_f27_379;
            sp1F8 = (f64) sp58;
            temp_f0_418 = sp1F0 + M2C_BITWISE(f64, sp1D0);
            sp40 = temp_f0_418;
            sp200 = temp_f0_418;
            sp48 = (f32) sp1F8 + sp1D0.unk8;
            sp208 = (f64) sp48;
            sp210.operator*(50.0f);
            spE0 = sp210 * (f64) arg5;
            sp380 = spE0;
            spE8 = sp210.unk8 * arg5;
            sp220 = spE0;
            sp388 = (f64) spE8;
            temp_r3_443 = M2C_FIELD(temp_r31_70, void **, 0x68);
            sp228 = (f64) spE8;
            temp_r3_448 = M2C_FIELD(M2C_FIELD(temp_r3_443, void **, 0x44), void *(**)(void *, f64), 0x3C)(temp_r3_443, spE0);
            if (temp_r3_448 != NULL) {
                temp_r24_451 = M2C_FIELD(temp_r3_448, void **, 0x2C);
                M2C_FIELD(temp_r3_448, f64 *, 0) = (f64) M2C_FIELD(&arg0, f64 *, 0);
                M2C_FIELD(temp_r3_448, f64 *, 8) = (f64) M2C_FIELD(&arg0, f64 *, 8);
                M2C_FIELD(temp_r3_448, f32 *, 0x20) = 0.0f;
                M2C_FIELD(temp_r3_448, f32 *, 0x28) = 0.0f;
                M2C_FIELD(temp_r3_448, f64 *, 0x10) = (f64) M2C_FIELD(arg3, f64 *, 0);
                M2C_FIELD(temp_r3_448, f64 *, 0x18) = (f64) M2C_FIELD(arg3, f64 *, 8);
                M2C_FIELD(temp_r24_451, f64 *, 0) = sp380;
                M2C_FIELD(temp_r24_451, f64 *, 8) = sp388;
                M2C_FIELD(temp_r24_451, f32 *, 0x18) = (f32) (0.25f * arg4);
                M2C_FIELD(temp_r24_451, f32 *, 0x10) = MKRand_Float((int *) &gViewSeed, -3.1415927f, 3.1415927f);
                M2C_FIELD(temp_r24_451, f32 *, 0x14) = (f32) M2C_FIELD(M2C_FIELD(temp_r31_70, void **, 0x68), f32 *, 0xF4);
            }
            var_r27_381 += 1;
            goto loop_26;
        }
        return;
    }
    if ((arg6 & 0x20000) || (arg6 & 0x40000)) {
        temp_f27_495 = -arg1.unk0;
        temp_f28_496 = -arg1.unk4;
        temp_f30_497 = arg2.unk8;
        temp_f29_498 = -arg1.unk8;
        var_r27_499 = 0;
loop_34:
        if (var_r27_499 < (s32) (temp_r30_72 * 2)) {
            MKVector(1.0f, 1.0f, 1.0f);
            MKVector(-1.0f, -1.0f, -1.0f);
            KDRand_Vector(sp150, sp140);
            sp30 = temp_f27_495;
            sp34 = temp_f28_496;
            sp38 = temp_f29_498;
            sp160 = (f64) sp30;
            sp168 = (f64) sp38;
            temp_f0_525 = (f64) sp30 + M2C_FIELD(&arg2, f64 *, 0);
            sp20 = temp_f0_525;
            sp170 = temp_f0_525;
            sp28 = (f32) sp168 + temp_f30_497;
            sp178 = (f64) sp28;
            temp_f0_536 = sp170 + M2C_BITWISE(f64, sp150);
            sp10 = temp_f0_536;
            sp180 = temp_f0_536;
            sp18 = (f32) sp178 + sp150.unk8;
            sp188 = (f64) sp18;
            sp190.operator*(50.0f);
            spD0 = sp190 * (f64) arg5;
            sp380 = spD0;
            spD8 = sp190.unk8 * arg5;
            sp1A0 = spD0;
            sp388 = (f64) spD8;
            temp_r3_561 = M2C_FIELD(temp_r31_70, void **, 0x68);
            sp1A8 = (f64) spD8;
            temp_r3_566 = M2C_FIELD(M2C_FIELD(temp_r3_561, void **, 0x44), void *(**)(void *, f64), 0x3C)(temp_r3_561, spD0);
            if (temp_r3_566 != NULL) {
                temp_r24_569 = M2C_FIELD(temp_r3_566, void **, 0x2C);
                M2C_FIELD(temp_r3_566, f64 *, 0) = (f64) M2C_FIELD(&arg0, f64 *, 0);
                M2C_FIELD(temp_r3_566, f64 *, 8) = (f64) M2C_FIELD(&arg0, f64 *, 8);
                M2C_FIELD(temp_r3_566, f32 *, 0x20) = 0.0f;
                M2C_FIELD(temp_r3_566, f32 *, 0x28) = 0.0f;
                M2C_FIELD(temp_r3_566, f64 *, 0x10) = (f64) M2C_FIELD(arg3, f64 *, 0);
                M2C_FIELD(temp_r3_566, f64 *, 0x18) = (f64) M2C_FIELD(arg3, f64 *, 8);
                M2C_FIELD(temp_r24_569, f64 *, 0) = sp380;
                M2C_FIELD(temp_r24_569, f64 *, 8) = sp388;
                M2C_FIELD(temp_r24_569, f32 *, 0x18) = (f32) (0.25f * arg4);
                M2C_FIELD(temp_r24_569, f32 *, 0x10) = MKRand_Float((int *) &gViewSeed, -3.1415927f, 3.1415927f);
                M2C_FIELD(temp_r24_569, f32 *, 0x14) = (f32) M2C_FIELD(M2C_FIELD(temp_r31_70, void **, 0x68), f32 *, 0xF4);
            }
            var_r27_499 += 1;
            goto loop_34;
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier '__float_nan'
void FootStepFX::AddFootStep(const MKVector3 &arg0, const MKVector3 &arg1, const MKVector3 &arg2, float arg3) {
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
    MKVector3 sp220;
    MKVector3 sp210;
    f64 sp208;
    f64 sp200;
    f64 sp1F8;
    f64 sp1F0;
    f64 sp1E8;
    f64 sp1E0;
    MKVector3 sp1D0;
    MKVector3 sp1C0;
    f64 sp1B8;
    f64 sp1B0;
    f64 sp1A8;
    f64 sp1A0;
    MKVector3 sp190;
    f64 sp188;
    f64 sp180;
    MKVector3 sp170;
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
    f32 sp104;
    f32 sp100;
    f32 spF8;
    f32 spF4;
    f32 spF0;
    f32 spE8;
    f32 spE4;
    f32 spE0;
    f32 spD8;
    f32 spD4;
    f32 spD0;
    f32 spC8;
    f64 spC0;
    f32 spB8;
    f64 spB0;
    f32 spA8;
    f64 spA0;
    f32 sp98;
    f64 sp90;
    f32 sp88;
    f64 sp80;
    f32 sp78;
    f32 sp74;
    f32 sp70;
    f32 sp68;
    f64 sp60;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp48;
    f64 sp40;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f64 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f2_634;
    f32 temp_f4_630;
    f32 temp_f5_638;
    f32 temp_f5_734;
    f32 temp_f6_639;
    f32 temp_f7_636;
    f32 temp_f7_738;
    f32 temp_f8_632;
    f32 temp_f9_736;
    f32 var_f3_726;
    f32 var_f3_835;
    f32 var_f4_659;
    f32 var_f4_768;
    f64 temp_f0_1029;
    f64 temp_f0_1041;
    f64 temp_f0_861;
    f64 temp_f0_873;
    f64 temp_f0_912;
    f64 temp_f0_924;
    f64 temp_f0_964;
    f64 temp_f0_976;
    f64 temp_f1_665;
    f64 temp_f1_671;
    f64 temp_f1_675;
    f64 temp_f1_774;
    f64 temp_f1_780;
    f64 temp_f1_784;
    s32 temp_r3_1067;
    s32 temp_r3_694;
    s32 temp_r3_803;
    s32 var_r0_704;
    s32 var_r0_813;
    void *temp_r3_1052;
    void *temp_r5_886;
    void *temp_r5_938;
    void *temp_r5_990;

    temp_f4_630 = arg1.unk8;
    temp_f8_632 = arg2.unk0;
    temp_f2_634 = arg2.unk8;
    temp_f7_636 = arg1.unk4;
    temp_f5_638 = arg1.unk0;
    temp_f6_639 = arg2.unk4;
    sp104 = (temp_f2_634 * temp_f5_638) - (temp_f8_632 * temp_f4_630);
    sp100 = (temp_f6_639 * temp_f4_630) - (temp_f2_634 * temp_f7_636);
    sp108 = (temp_f8_632 * temp_f7_636) - (temp_f6_639 * temp_f5_638);
    sp260 = (f64) sp100;
    sp268 = (f64) sp108;
    var_f4_659 = ((f32) sp268 * (f32) sp268) + (((f32) sp260 * (f32) sp260) + ((*(f32 *) ((u8 *) &sp260 + 0x4)) * (*(f32 *) ((u8 *) &sp260 + 0x4))));
    if (var_f4_659 > 1e-12f) {
        if (var_f4_659 > 0.0f) {
            temp_f1_665 = __frsqrte(var_f4_659);
            temp_f1_671 = 0.5 * temp_f1_665 * -(((f64) var_f4_659 * (temp_f1_665 * temp_f1_665)) - 3.0);
            temp_f1_675 = 0.5 * temp_f1_671 * -(((f64) var_f4_659 * (temp_f1_671 * temp_f1_671)) - 3.0);
            var_f4_659 = (f32) ((f64) var_f4_659 * (0.5 * temp_f1_675 * -(((f64) var_f4_659 * (temp_f1_675 * temp_f1_675)) - 3.0)));
        } else if (var_f4_659 < M2C_BITWISE(f32, 0.0)) {
            var_f4_659 = __float_nan;
        } else {
            spC = var_f4_659;
            temp_r3_694 = M2C_BITWISE(s32, spC) & 0x7F800000;
            switch (temp_r3_694) {                  /* switch 1; irregular */
            case 0x7F800000:                        /* switch 1 */
                if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                    var_r0_704 = 1;
                } else {
                    var_r0_704 = 2;
                }
                break;
            case 0x0:                               /* switch 1 */
                if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                    var_r0_704 = 5;
                } else {
                    var_r0_704 = 3;
                }
                break;
            default:                                /* switch 1 */
                var_r0_704 = 4;
                break;
            }
            if (var_r0_704 == 1) {
                var_f4_659 = __float_nan;
            }
        }
        var_f3_726 = 1.0f / var_f4_659;
    } else {
        var_f3_726 = 0.0f;
    }
    temp_f5_734 = arg1.unk8;
    temp_f9_736 = arg1.unk0;
    spF4 = (*(f32 *) ((u8 *) &sp260 + 0x4)) * var_f3_726;
    temp_f7_738 = arg1.unk4;
    spF0 = (f32) sp260 * var_f3_726;
    spF8 = (f32) sp268 * var_f3_726;
    sp280 = (f64) spF0;
    sp288 = (f64) spF8;
    spE0 = (temp_f7_738 * (f32) sp288) - (temp_f5_734 * (*(f32 *) ((u8 *) &sp280 + 0x4)));
    spE4 = (temp_f5_734 * (f32) sp280) - (temp_f9_736 * (f32) sp288);
    spE8 = (temp_f9_736 * (*(f32 *) ((u8 *) &sp280 + 0x4))) - (temp_f7_738 * (f32) sp280);
    sp250 = (f64) spE0;
    sp258 = (f64) spE8;
    var_f4_768 = ((f32) sp258 * (f32) sp258) + (((f32) sp250 * (f32) sp250) + ((*(f32 *) ((u8 *) &sp250 + 0x4)) * (*(f32 *) ((u8 *) &sp250 + 0x4))));
    if (var_f4_768 > 1e-12f) {
        if (var_f4_768 > 0.0f) {
            temp_f1_774 = __frsqrte(var_f4_768);
            temp_f1_780 = 0.5 * temp_f1_774 * -(((f64) var_f4_768 * (temp_f1_774 * temp_f1_774)) - 3.0);
            temp_f1_784 = 0.5 * temp_f1_780 * -(((f64) var_f4_768 * (temp_f1_780 * temp_f1_780)) - 3.0);
            var_f4_768 = (f32) ((f64) var_f4_768 * (0.5 * temp_f1_784 * -(((f64) var_f4_768 * (temp_f1_784 * temp_f1_784)) - 3.0)));
        } else if (var_f4_768 < M2C_BITWISE(f32, 0.0)) {
            var_f4_768 = __float_nan;
        } else {
            sp8 = var_f4_768;
            temp_r3_803 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r3_803) {                  /* switch 2; irregular */
            case 0x7F800000:                        /* switch 2 */
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_813 = 1;
                } else {
                    var_r0_813 = 2;
                }
                break;
            case 0x0:                               /* switch 2 */
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_813 = 5;
                } else {
                    var_r0_813 = 3;
                }
                break;
            default:                                /* switch 2 */
                var_r0_813 = 4;
                break;
            }
            if (var_r0_813 == 1) {
                var_f4_768 = __float_nan;
            }
        }
        var_f3_835 = 1.0f / var_f4_768;
    } else {
        var_f3_835 = 0.0f;
    }
    spD4 = (*(f32 *) ((u8 *) &sp250 + 0x4)) * var_f3_835;
    spD0 = (f32) sp250 * var_f3_835;
    spD8 = (f32) sp258 * var_f3_835;
    sp270 = (f64) spD0;
    sp278 = (f64) spD8;
    sp210.operator*(arg3);
    sp220.operator*(arg3);
    temp_f0_861 = M2C_FIELD(&arg0, f64 *, 0) + M2C_BITWISE(f64, sp220);
    sp80 = temp_f0_861;
    sp230 = temp_f0_861;
    sp88 = arg0.unk8 + sp220.unk8;
    sp238 = (f64) sp88;
    temp_f0_873 = sp230 + M2C_BITWISE(f64, sp210);
    spC0 = temp_f0_873;
    sp240 = temp_f0_873;
    temp_r5_886 = ((u8 *) this->unk4C) + (this->unk50 << 6);
    M2C_FIELD(temp_r5_886, f64 *, 0) = temp_f0_873;
    spC8 = (f32) sp238 + sp210.unk8;
    sp248 = (f64) spC8;
    M2C_FIELD(temp_r5_886, f64 *, 8) = (f64) spC8;
    sp1C0.operator*(arg3);
    sp1D0.operator*(arg3);
    sp70 = -M2C_BITWISE(f32, sp1D0);
    sp74 = -sp1D0.unk4;
    sp78 = -sp1D0.unk8;
    sp1E0 = (f64) sp70;
    sp1E8 = (f64) sp78;
    temp_f0_912 = M2C_FIELD(&arg0, f64 *, 0) + sp1E0;
    sp60 = temp_f0_912;
    sp1F0 = temp_f0_912;
    sp68 = arg0.unk8 + (f32) sp1E8;
    sp1F8 = (f64) sp68;
    temp_f0_924 = sp1F0 + M2C_BITWISE(f64, sp1C0);
    spB0 = temp_f0_924;
    sp200 = temp_f0_924;
    temp_r5_938 = ((u8 *) this->unk4C) + ((this->unk50 << 6) + 0x10);
    M2C_FIELD(temp_r5_938, f64 *, 0) = temp_f0_924;
    spB8 = (f32) sp1F8 + sp1C0.unk8;
    sp208 = (f64) spB8;
    M2C_FIELD(temp_r5_938, f64 *, 8) = (f64) spB8;
    sp170.operator*(arg3);
    sp50 = -M2C_BITWISE(f32, sp170);
    sp54 = -sp170.unk4;
    sp58 = -sp170.unk8;
    sp180 = (f64) sp50;
    sp188 = (f64) sp58;
    sp190.operator*(arg3);
    temp_f0_964 = M2C_FIELD(&arg0, f64 *, 0) + M2C_BITWISE(f64, sp190);
    sp40 = temp_f0_964;
    sp1A0 = temp_f0_964;
    sp48 = arg0.unk8 + sp190.unk8;
    sp1A8 = (f64) sp48;
    temp_f0_976 = sp1A0 + sp180;
    spA0 = temp_f0_976;
    sp1B0 = temp_f0_976;
    temp_r5_990 = ((u8 *) this->unk4C) + ((this->unk50 << 6) + 0x20);
    M2C_FIELD(temp_r5_990, f64 *, 0) = temp_f0_976;
    spA8 = (f32) sp1A8 + (f32) sp188;
    sp1B8 = (f64) spA8;
    M2C_FIELD(temp_r5_990, f64 *, 8) = (f64) spA8;
    sp110.operator*(arg3);
    sp30 = -M2C_BITWISE(f32, sp110);
    sp34 = -sp110.unk4;
    sp38 = -sp110.unk8;
    sp120 = (f64) sp30;
    sp128 = (f64) sp38;
    sp130.operator*(arg3);
    sp20 = -M2C_BITWISE(f32, sp130);
    sp24 = -sp130.unk4;
    sp28 = -sp130.unk8;
    sp140 = (f64) sp20;
    sp148 = (f64) sp28;
    temp_f0_1029 = M2C_FIELD(&arg0, f64 *, 0) + sp140;
    sp10 = temp_f0_1029;
    sp150 = temp_f0_1029;
    sp18 = arg0.unk8 + (f32) sp148;
    sp158 = (f64) sp18;
    temp_f0_1041 = sp150 + sp120;
    sp90 = temp_f0_1041;
    sp160 = temp_f0_1041;
    temp_r3_1052 = ((u8 *) this->unk4C) + ((this->unk50 << 6) + 0x30);
    M2C_FIELD(temp_r3_1052, f64 *, 0) = temp_f0_1041;
    sp98 = (f32) sp158 + (f32) sp128;
    M2C_FIELD(temp_r3_1052, f64 *, 8) = (f64) sp98;
    sp168 = (f64) sp98;
    this->unk50 += 1;
    if ((s32) this->unk50 >= 0x1E) {
        this->unk50 = 0;
    }
    temp_r3_1067 = this->unk50;
    if (temp_r3_1067 == (s32) this->unk54) {
        this->unk54 = temp_r3_1067 + 1;
        if ((s32) this->unk54 >= 0x1E) {
            this->unk54 = 0;
        }
    }
    this->unk60 = 1;
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void FootStepFX::Deinit() {
    MKHeap *temp_r3_1099;
    void *temp_r31_1098;

    temp_r31_1098 = this->unk4C;
    temp_r3_1099 = MKHeap::Current();
    if (temp_r3_1099 != NULL) {
        ((MKHeap *) (temp_r3_1099->Current()))->Free(temp_r31_1098, NULL, 0);
    } else {
        free(temp_r31_1098);
    }
    MKMaterial_Destroy(this->unk58);
    MKMaterial_Destroy(this->unk5C);
    MKProp::Deinit();
}
#endif

#if 0 // DRAFT: illegal type
void FootStepFX::Draw() {
    f64 sp28;
    f64 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 sp8;
    f32 temp_f2_1148;
    f32 var_f30_1155;
    s32 temp_r0_1253;
    s32 temp_r26_1221;
    s32 temp_r31_1157;
    s32 var_r0_1183;
    s32 var_r28_1172;
    s32 var_r29_1173;
    s32 var_r30_1156;
    s32 var_r3_1177;
    s32 var_r3_1188;

    if ((u8) this->unk60 != 0) {
        MKView_Push();
        MKView_GetProjection(NULL, &sp8, NULL);
        temp_f2_1148 = sp8 + 0.05f;
        sp8 = temp_f2_1148;
        MKView_SetProjection(0.0f, temp_f2_1148, 0.0f);
        MKSetMatrix(Matrix::identity);
        var_f30_1155 = 1.0f;
        var_r30_1156 = 0;
        temp_r31_1157 = this->unk54;
        do {
            if (var_r30_1156 == 0) {
                MKMaterial_SetMaterial(this->unk5C);
            } else {
                MKMaterial_SetMaterial(this->unk58);
            }
            MKPrimitive(0xC, 0x10);
            var_r28_1172 = temp_r31_1157;
            var_r29_1173 = 0;
loop_17:
            temp_r0_1253 = this->unk50;
            if (var_r28_1172 != temp_r0_1253) {
                var_r3_1177 = this->unk54 - 1;
                if (var_r3_1177 < 0) {
                    var_r3_1177 = 0x1D;
                }
                if (temp_r0_1253 == var_r3_1177) {
                    var_r0_1183 = lit_523;
                    if (var_r29_1173 < var_r0_1183) {
                        var_r0_1183 = var_r29_1173;
                    }
                    var_r3_1188 = lit_522;
                    if (var_r0_1183 > var_r3_1188) {
                        var_r3_1188 = var_r0_1183;
                    }
                    var_f30_1155 = 0.5f * ((f32) var_r3_1188 / 15.0f);
                }
                MKBegin(4);
                sp10 = var_f30_1155;
                sp14 = var_f30_1155;
                sp18 = var_f30_1155;
                sp1C = 1.0f;
                sp20 = (f64) sp10;
                sp28 = (f64) sp18;
                MKSetColorV(*((MKVector4 *) &sp20));
                MKSetTexCoord1F(0.0f, 1.0f);
                temp_r26_1221 = var_r28_1172 << 6;
                MKSetPositionV(*(this->unk4C + temp_r26_1221));
                MKSetTexCoord1F(1.0f, 1.0f);
                MKSetPositionV(*(this->unk4C + (temp_r26_1221 + 0x10)));
                MKSetTexCoord1F(0.0f, 0.0f);
                MKSetPositionV(*(this->unk4C + (temp_r26_1221 + 0x20)));
                MKSetTexCoord1F(1.0f, 0.0f);
                MKSetPositionV(*(this->unk4C + (temp_r26_1221 + 0x30)));
                MKEnd();
                var_r28_1172 += 1;
                if (var_r28_1172 >= 0x1E) {
                    var_r28_1172 = 0;
                }
                var_r29_1173 += 1;
                goto loop_17;
            }
            MKEndPrimitive();
            var_r30_1156 += 1;
        } while (var_r30_1156 < 2);
        MKView_Pop();
    }
}
#endif

void FootStepFX::Update() {

}

#if 0 // DRAFT: illegal implicit conversion from 'MKResource *' to
void FootStepFX::Init() {
    MKHeap *temp_r3_1288;
    void *var_r3_1295;

    MKProp::Init();
    temp_r3_1288 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_1288 != NULL) {
        var_r3_1295 = ((MKHeap *) (temp_r3_1288->Current()))->Alloc(0x780, NULL, 0);
    } else {
        var_r3_1295 = malloc(0x780);
    }
    this->unk4C = var_r3_1295;
    this->unk50 = 0;
    this->unk54 = 0;
    this->unk58 = MKMaterial_Create("spyro_footprintAdd");
    this->unk5C = MKMaterial_Create("spyro_footprintSub");
    this->unk60 = 0;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'KDEnvParticleSystem *' to
void FootStepFXDescriptor::LoadDone() {
    MKPropDescriptor::LoadDone();
    this->unk60 = checked_cast<KDEnvParticleSystem *, MKProp>(gMK->CreateProp("FootStepWoodDustPS"));
    this->unk64 = checked_cast<KDEnvParticleSystem *, MKProp>(gMK->CreateProp("FootStepMudPS"));
    this->unk68 = checked_cast<KDEnvParticleSystem *, MKProp>(gMK->CreateProp("FootStepSnowPS"));
}
#endif

void FootStepFXDescriptor::Init() {
    MKPropDescriptor::Init();
}
