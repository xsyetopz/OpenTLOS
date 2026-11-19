#include "spyro/source/VolcanoRumble.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "spyro/source/FlyingChunkPS.h"
#include "spyro/source/HeroInterface.h"
#include "spyro/source/KDInput.h"
#include "spyro/source/KDSound.h"
#include "common/Source/StdMath.h"
#include "spyro/source/KDRandom.h"
#include <m2c_macros.h>

M2C_UNK __destroy_arr(KDSoundFader *, KDSoundFader *(*)(KDSoundFader *, s16), M2C_UNK, M2C_UNK); /* extern */
extern s32 GS_Rumble2;
extern s32 GS_Rumble3;
extern s32 GS_Rumble4;
extern f32 fTimer_624;
extern f32 fTimer_660;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern void **gb;
extern u8 init_625;
extern u8 init_661;

#if 0 // DRAFT: illegal use of abstract class ('HeroInterface::GetHeroType()')
void VolcanoRumble::MakeRumbleSoundCameraShakeCrud() {
    s8 sp190;
    f64 sp188;
    f64 sp180;
    s32 sp17C;
    s32 sp178;
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
    M2C_UNK sp118;
    f64 sp110;
    f64 sp108;
    HeroInterface spF8;
    M2C_UNK spE8;
    f64 spE0;
    f64 spD8;
    HeroInterface spC8;
    M2C_UNK spB8;
    f64 spB0;
    f64 spA8;
    HeroInterface sp98;
    M2C_UNK sp88;
    f64 sp80;
    f64 sp78;
    HeroInterface sp68;
    M2C_UNK sp58;
    f32 sp50;
    f32 sp40;
    f32 sp30;
    f32 sp20;
    f32 sp10;

    M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
    if (this->unkEC == 0.0f) {
        this->unkF0 = 0;
        sp17C = 0;
        MKVector(0.4f, 0.4f, 0.4f);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
        sp178 = 0x417;
        sp50 = sp120 * 500.0f;
        sp180 = sp48;
        sp188 = (f64) sp50;
        sp190 = 1;
        sp128 = sp48;
        sp130 = (f64) sp50;
        M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, f64), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &sp178, sp48);
        ((KDInput *) (M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), KDInput *(**)(void **), 0x40)(M2C_FIELD(&gb, void ***, 0))))->RumblePlay(0.03f, 0.3f, 0.5f, 0, 4.0f, 0U);
        MKVector(2000.0f, 0.0f, 0.0f);
        spF8.GetPos();
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        sp108 = sp38;
        sp40 = sp100 + spF0;
        sp168 = sp38;
        sp110 = (f64) sp40;
        sp170 = (f64) sp40;
        MKVector(-2000.0f, 0.0f, 0.0f);
        spC8.GetPos();
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        spD8 = sp28;
        sp30 = spD0 + spC0;
        sp158 = sp28;
        spE0 = (f64) sp30;
        sp160 = (f64) sp30;
        MKVector(0.0f, 0.0f, 2000.0f);
        sp98.GetPos();
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        spA8 = sp18;
        sp20 = spA0 + sp90;
        sp148 = sp18;
        spB0 = (f64) sp20;
        sp150 = (f64) sp20;
        MKVector(0.0f, 0.0f, -2000.0f);
        sp68.GetPos();
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        sp78 = sp8;
        sp10 = sp70 + sp60;
        sp138 = sp8;
        sp80 = (f64) sp10;
        sp140 = (f64) sp10;
        KDSound_Play3d(GS_Rumble2, (MKVector3 *) &sp168, 0U, -1, 0.0f, 0U);
        KDSound_Play3d(GS_Rumble2, (MKVector3 *) &sp158, 0U, -1, 0.0f, 0U);
        KDSound_Play3d(GS_Rumble3, (MKVector3 *) &sp148, 0U, -1, 0.0f, 0U);
        KDSound_Play3d(GS_Rumble3, (MKVector3 *) &sp138, 0U, -1, 0.0f, 0U);
        this->unkEC = 4.0f;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unksp1F4'
void VolcanoRumble::EmitCrudAbovePlayer() {
    f64 sp1F8;                                      /* compiler-managed */
    f64 sp1F0;
    f64 sp1E8;
    f64 sp1E0;
    f64 sp1D8;
    f64 sp1D0;
    M2C_UNK sp1C0;
    MKVector3 sp1B0;
    f64 sp1A8;
    f64 sp1A0;
    f64 sp198;
    f64 sp190;
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
    f64 spF8;
    f64 spF0;
    f32 spE8;
    f32 spE4;
    f32 spE0;
    f32 spD8;
    f32 spD4;
    f32 spD0;
    f32 spC8;
    f32 spC4;
    f32 spC0;
    f32 spB8;
    f32 spA8;
    f32 sp98;
    f32 sp88;
    f32 sp78;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp58;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp38;
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f32 sp8;
    f32 temp_f19_323;
    f32 temp_f19_529;
    f32 temp_f19_556;
    f32 temp_f1_284;
    f32 temp_f1_374;
    f32 temp_f1_587;
    f32 temp_f20_328;
    f32 temp_f20_524;
    f32 temp_f20_561;
    f32 var_f3_448;
    f32 var_f4_381;
    f64 temp_f1_387;
    f64 temp_f1_393;
    f64 temp_f1_397;
    s32 temp_r3_416;
    s32 var_r0_426;
    s32 var_r28_308;
    void *temp_r4_313;

    temp_f1_284 = this->unkEC;
    if ((temp_f1_284 < 4.0f) && (temp_f1_284 > -1.0f)) {
        if ((s8) init_661 == 0) {
            fTimer_660 = -1.0f;
            init_661 = 1;
        }
        if (fTimer_660 < 0.0f) {
            var_r28_308 = 0;
            do {
                temp_r4_313 = M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 8);
                sp1F0 = M2C_FIELD(temp_r4_313, f64 *, 0x30);
                sp1F8 = M2C_FIELD(temp_r4_313, f64 *, 0x38);
                unksp1F4 += 1000.0f;
                temp_f19_323 = MKRand_Float(&gViewSeed, -10.0f, 10.0f);
                temp_f20_328 = MKRand_Float(&gViewSeed, 4.0f, 6.0f);
                MKVector(MKRand_Float(&gViewSeed, -10.0f, 10.0f), temp_f20_328, temp_f19_323);
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r29, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f22 */);
                sp1D0 = sp10;
                sp18 = sp1C8 * 100.0f;
                sp1D8 = (f64) sp18;
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                spE8 = -1.0f;
                spD8 = 1.0f;
                spE0 = -1.0f;
                spE4 = 0.0f;
                spD0 = 1.0f;
                spD4 = 1.0f;
                sp1F8 = (f32) sp1F8 + (f32) sp1D8;
                sp1A0 = (f64) spE0;
                sp1A8 = (f64) spE8;
                sp190 = (f64) spD0;
                sp198 = (f64) spD8;
                KDRand_Vector(sp1B0, *((MKVector3 *) &sp1A0));
                temp_f1_374 = M2C_BITWISE(f32, sp1B0);
                var_f4_381 = (sp1B0.unk8 * sp1B0.unk8) + ((temp_f1_374 * temp_f1_374) + (sp1B0.unk4 * sp1B0.unk4));
                if (var_f4_381 > 1e-12f) {
                    if (var_f4_381 > 0.0f) {
                        temp_f1_387 = __frsqrte(var_f4_381);
                        temp_f1_393 = 0.5 * temp_f1_387 * -(((f64) var_f4_381 * (temp_f1_387 * temp_f1_387)) - 3.0);
                        temp_f1_397 = 0.5 * temp_f1_393 * -(((f64) var_f4_381 * (temp_f1_393 * temp_f1_393)) - 3.0);
                        var_f4_381 = (f32) ((f64) var_f4_381 * (0.5 * temp_f1_397 * -(((f64) var_f4_381 * (temp_f1_397 * temp_f1_397)) - 3.0)));
                    } else if (var_f4_381 < M2C_BITWISE(f32, 0.0)) {
                        var_f4_381 = __float_nan;
                    } else {
                        sp8 = var_f4_381;
                        temp_r3_416 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                        switch (temp_r3_416) {      /* irregular */
                        case 0x7F800000:
                            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                var_r0_426 = 1;
                            } else {
                                var_r0_426 = 2;
                            }
                            break;
                        case 0x0:
                            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                var_r0_426 = 5;
                            } else {
                                var_r0_426 = 3;
                            }
                            break;
                        default:
                            var_r0_426 = 4;
                            break;
                        }
                        if (var_r0_426 == 1) {
                            var_f4_381 = __float_nan;
                        }
                    }
                    var_f3_448 = 1.0f / var_f4_381;
                } else {
                    var_f3_448 = 0.0f;
                }
                spC0 = M2C_BITWISE(f32, sp1B0) * var_f3_448;
                spC4 = sp1B0.unk4 * var_f3_448;
                spC8 = sp1B0.unk8 * var_f3_448;
                sp1E0 = (f64) spC0;
                sp1E8 = (f64) spC8;
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f26 */);
                sp160 = spB0;
                spB8 = (f32) sp1E8 * 100.0f;
                sp168 = (f64) spB8;
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f21 */);
                sp170 = spA0;
                spA8 = (f32) sp168 * 1.0f;
                sp178 = (f64) spA8;
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                sp180 = sp90;
                sp98 = sp1F8 + (f32) sp178;
                sp188 = (f64) sp98;
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f25 */);
                sp88 = (f32) sp1E8 * 4000.0f;
                sp140 = sp80;
                sp148 = (f64) sp88;
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f21 */);
                sp150 = sp70;
                sp78 = (f32) sp148 * 1.0f;
                sp158 = (f64) sp78;
                temp_f20_524 = MKRand_Float(&gViewSeed, -1.0f, M2C_ERROR(/* unknown instruction: ps_mr $f2, $f21 */));
                temp_f19_529 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                sp60 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                sp64 = temp_f19_529;
                sp68 = temp_f20_524;
                sp120 = (f64) sp60;
                sp128 = (f64) sp68;
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f24 */);
                sp130 = sp50;
                sp58 = (f32) sp128 * 3.1415927f;
                sp138 = (f64) sp58;
                temp_f19_556 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                temp_f20_561 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                sp40 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                sp44 = temp_f20_561;
                sp48 = temp_f19_556;
                sp100 = (f64) sp40;
                sp108 = (f64) sp48;
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f23 */);
                sp110 = sp30;
                sp38 = (f32) sp108 * 3.1415927f;
                sp118 = (f64) sp38;
                temp_f1_587 = MKRand_Float(&gViewSeed, 0.75f, 1.0f);
                sp20 = 1.0f;
                sp24 = 1.0f;
                sp28 = 1.0f;
                sp2C = 1.0f;
                spF0 = (f64) sp20;
                spF8 = (f64) sp28;
                ((FlyingChunkPS *) (M2C_FIELD(&gb, FlyingChunkPS **, 0xA4)))->Emit(*((MKVector3 *) &sp180), *((MKVector3 *) &sp150), *((MKVector3 *) &sp130), *((MKVector3 *) &sp110), 1.0f * temp_f1_587, *((MKVector4 *) &spF0), 0xA, NULL);
                var_r28_308 += 1;
            } while (var_r28_308 < 2);
            fTimer_660 = -((0.01f * this->unkEC) - 0.25f);
        }
        fTimer_660 -= gUpdateTimeDelta;
    }
}
#endif

#if 0 // DRAFT: function call 'MKRand_Float(long *, float, float)' does not match
void VolcanoRumble::MakeCrudRainSound() {
    f64 sp98;                                       /* compiler-managed */
    f64 sp90;
    f64 sp88;                                       /* compiler-managed */
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    M2C_UNK sp50;
    f64 sp48;
    f64 sp40;
    M2C_UNK sp30;
    f32 sp28;
    f32 sp18;
    s32 sp8;
    f32 temp_f1_670;
    f32 temp_f29_718;
    f32 temp_f29_793;
    f32 temp_f30_713;
    f32 temp_f30_798;
    s32 var_r27_776;
    s32 var_r27_845;
    s32 var_r30_777;
    s32 var_r30_847;
    void *temp_r4_704;
    void *temp_r4_784;
    void *temp_r4_856;

    if ((u8) this->unkF0 == 0) {
        temp_f1_670 = this->unkEC;
        if (((temp_f1_670 < 3.0f) && (temp_f1_670 > 2.5f)) || ((temp_f1_670 < 0.75f) && (temp_f1_670 > 0.0f))) {
            if ((s8) init_625 == 0) {
                init_625 = 1;
                fTimer_624 = -1.0f;
            }
            if (fTimer_624 < 0.0f) {
                temp_r4_704 = M2C_FIELD(M2C_FIELD(*gb, void *(**)(void **), 0xC)(gb), void **, 8);
                sp90 = M2C_FIELD(temp_r4_704, f64 *, 0x30);
                sp98 = M2C_FIELD(temp_r4_704, f64 *, 0x38);
                temp_f30_713 = MKRand_Float(&gViewSeed, -10.0f, 10.0f);
                temp_f29_718 = MKRand_Float(&gViewSeed, 4.0f, 10.0f);
                MKVector(MKRand_Float(&gViewSeed, -10.0f, 10.0f), temp_f29_718, temp_f30_713);
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
                sp60 = sp20;
                sp28 = sp58 * 100.0f;
                sp68 = (f64) sp28;
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                sp98 = (f32) sp98 + (f32) sp68;
                sp8 = 1;
                this->unk4C.Update(GS_Rumble4, 1U, 1U, NULL, (MKVector3 *) &sp90, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
                fTimer_624 = 0.75f;
            }
            fTimer_624 -= gUpdateTimeDelta;
            return;
        }
        if ((temp_f1_670 < 2.5f) && (temp_f1_670 > 0.75f)) {
            var_r27_776 = 0;
            var_r30_777 = 0;
            do {
                temp_r4_784 = M2C_FIELD(M2C_FIELD(*gb, void *(**)(void **), 0xC)(gb), void **, 8);
                sp80 = M2C_FIELD(temp_r4_784, f64 *, 0x30);
                sp88 = M2C_FIELD(temp_r4_784, f64 *, 0x38);
                temp_f29_793 = MKRand_Float(&gViewSeed, -2.0f, 2.0f);
                temp_f30_798 = MKRand_Float(&gViewSeed, 2.0f, 3.0f);
                MKVector(MKRand_Float(&gViewSeed, -2.0f, 2.0f), temp_f30_798, temp_f29_793);
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r28, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
                sp40 = sp10;
                sp18 = sp38 * 100.0f;
                sp48 = (f64) sp18;
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                sp88 = (f32) sp88 + (f32) sp48;
                sp8 = 1;
                ((KDSoundFader *) (this + (var_r30_777 + 0x4C)))->Update(GS_Rumble4, 1U, 1U, NULL, (MKVector3 *) &sp80, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
                var_r27_776 += 1;
                var_r30_777 += 0x28;
            } while (var_r27_776 < 4);
            return;
        }
        var_r27_845 = 0;
        var_r30_847 = 0;
        do {
            if ((void **) gb != NULL) {
                temp_r4_856 = M2C_FIELD(M2C_FIELD(*gb, void *(**)(), 0xC)(), void **, 8);
                sp70 = M2C_FIELD(temp_r4_856, f64 *, 0x30);
                sp78 = M2C_FIELD(temp_r4_856, f64 *, 0x38);
                sp8 = 1;
                ((KDSoundFader *) (this + (var_r30_847 + 0x4C)))->Update(GS_Rumble4, 1U, 0U, NULL, (MKVector3 *) &sp70, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
            }
            var_r27_845 += 1;
            var_r30_847 += 0x28;
        } while (var_r27_845 < 4);
    }
}
#endif

void VolcanoRumble::Update() {
    MKProp::Update();
    EmitCrudAbovePlayer();
    MakeCrudRainSound();
    this->unkEC -= gUpdateTimeDelta;
}

void VolcanoRumble::Message(MKMessage *arg0) {
    if ((s32) arg0->unk0 != 0x144) {

    } else {
        MakeRumbleSoundCameraShakeCrud();
    }
    MKProp::Message(arg0);
}

void VolcanoRumble::Reset() {
    MKProp::Reset();
    this->unkEC = -1.0f;
    this->unkF0 = 0;
}

#if 0 // DRAFT: function call 'KDSound_Stop(VolcanoRumble *)' does not match
void VolcanoRumble::Deinit() {
    s32 var_r30_970;
    s32 var_r31_971;

    var_r30_970 = 0;
    var_r31_971 = 0;
    do {
        KDSound_Stop(this + (var_r31_971 + 0x4C));
        var_r30_970 += 1;
        var_r31_971 += 0x28;
    } while (var_r30_970 < 4);
    this->unkF0 = 0;
    if ((u32) M2C_FIELD(&gb, u32 *, 0x2B0) == this) {
        M2C_FIELD(&gb, u32 *, 0x2B0) = 0U;
    }
    MKProp::Deinit();
}
#endif

void VolcanoRumble::Init() {
    s32 var_r30_1008;
    s32 var_r31_1009;

    MKProp::Init();
    var_r30_1008 = 0;
    var_r31_1009 = 0;
    this->unkEC = -1.0f;
    do {
        ((KDSoundFader *) (this + (var_r31_1009 + 0x4C)))->Init(0.5f, 2.0f);
        var_r30_1008 += 1;
        var_r31_1009 += 0x28;
    } while (var_r30_1008 < 4);
    this->unkF0 = 0;
    M2C_FIELD(&gb, VolcanoRumble **, 0x2B0) = this;
}
