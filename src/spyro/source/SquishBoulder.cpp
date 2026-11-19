#include "spyro/source/SquishBoulder.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/EmbersPS.h"
#include "spyro/source/FallingLeaves.h"
#include "spyro/source/Game.h"
#include "spyro/source/GameData.h"
#include "spyro/source/GameMessages.h"
#include "spyro/source/KDInput.h"
#include "spyro/source/KDParticleSystem.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/PooledShatterProp.h"
#include "spyro/source/Shatterable.h"
#include "unplaced_templates.h"
#include "common/Source/MKModel.h"
#include "common/Source/StdMath.h"
#include "spyro/source/KDMath.h"
#include "spyro/source/KDRandom.h"
#include <m2c_macros.h>

extern s32 GS_SpyroEarthFuryFall;
extern s32 GS_SpyroEarthFurySmash;
extern MKSceneManager *gMK;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern GameGlobals gb;

#if 0 // DRAFT: function call 'MKRand_Float(long *, float, float)' does not match
void SquishBoulder::EmitLandingEffects() {
    Matrix sp310;
    M2C_UNK sp30C;
    s8 sp308;
    f64 sp300;
    f64 sp2F8;
    s32 sp2F4;
    s32 sp2F0;
    f32 sp2E8;
    f32 sp2E4;
    f32 sp2E0;                                      /* compiler-managed */
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
    f64 sp220;
    f64 sp218;
    f64 sp210;
    f64 sp208;
    f64 sp200;
    f64 sp1F0;
    MKVector3 sp1E0;
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
    f64 sp170;
    f64 sp160;
    f64 sp158;
    f64 sp150;
    f64 sp140;
    f32 sp138;
    f32 sp134;
    f32 sp130;
    f32 sp128;
    f64 sp120;
    f32 sp118;
    f32 sp114;
    f32 sp110;
    f32 sp108;
    f64 sp100;
    f32 spFC;
    f32 spF8;
    f32 spF4;
    f32 spF0;
    f32 spE8;
    f64 spE0;
    f32 spD8;
    f32 spD4;
    f32 spD0;
    f32 spC8;
    f64 spC0;
    f32 spB8;
    f64 spB0;
    f32 spA8;
    f32 spA4;
    f32 spA0;
    f32 sp98;
    f32 sp94;
    f32 sp90;
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
    f32 sp44;
    f32 sp40;
    f32 sp38;
    f64 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp1C;
    f32 sp18;
    s32 sp14;
    f32 sp10;
    f32 temp_f1_121;
    f32 temp_f1_257;
    f32 temp_f20_102;
    f32 temp_f21_105;
    f32 temp_f26_165;
    f32 temp_f26_197;
    f32 temp_f27_160;
    f32 var_f4_352;
    f32 var_f5_400;
    f64 temp_f0_132;
    f64 temp_f0_179;
    f64 temp_f0_328;
    f64 temp_f0_371;
    f64 temp_f1_405;
    f64 temp_f1_411;
    f64 temp_f1_415;
    s32 temp_r3_434;
    s32 var_r0_444;
    s32 var_r27_92;
    s32 var_r29_153;
    s32 var_r29_281;
    void *temp_r27_229;
    void *temp_r28_88;
    void *temp_r3_220;
    void *temp_r3_224;
    void *temp_r3_358;

    temp_r28_88 = checked_cast<SquishBoulderDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    var_r27_92 = 0;
    do {
        temp_f20_102 = 6.2831855f * ((f32) var_r27_92 / 19.0f);
        temp_f21_105 = -_table_sinf(1.5707964f + temp_f20_102);
        sp2E0 = _table_sinf(temp_f20_102);
        sp2E4 = 0.0f;
        sp2E8 = temp_f21_105;
        sp2E0 = (f64) sp2E0 * 5.697262106e-315;
        sp2E8 = (f32) temp_f21_105 * 1500.0f;
        temp_f1_121 = MKRand_Float(&gViewSeed, 0.8f, 1.2f);
        sp130 = 0.0f;
        sp134 = 100.0f;
        sp138 = 0.0f;
        sp1C = temp_f1_121;
        sp270 = (f64) sp130;
        sp278 = (f64) sp138;
        temp_f0_132 = M2C_FIELD(this, f64 *, 0x290) + sp270;
        sp120 = temp_f0_132;
        sp280 = temp_f0_132;
        sp128 = this->unk260.unk38 + (f32) sp278;
        sp288 = (f64) sp128;
        gb.EmitDust(*((MKVector3 *) &sp280), *((MKVector3 *) &sp2E0), sp1C, 0.0f);
        var_r27_92 += 1;
    } while (var_r27_92 < 0x14);
    var_r29_153 = 0;
    do {
        temp_f27_160 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        temp_f26_165 = MKRand_Float(&gViewSeed, 0.0f, 1.0f);
        sp110 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        sp114 = temp_f26_165;
        sp118 = temp_f27_160;
        sp250 = (f64) sp110;
        sp258 = (f64) sp118;
        temp_f0_179 = sp250 * 5.676053805e-315;
        sp100 = temp_f0_179;
        sp260 = temp_f0_179;
        sp108 = (f32) sp258 * 1000.0f;
        sp268 = (f64) sp108;
        sp18 = MKRand_Float(&gViewSeed, 25.0f, 35.0f);
        temp_f26_197 = MKRand_Float(&gViewSeed, 0.0f, 0.2f);
        spF0 = MKRand_Float(&gViewSeed, 0.0f, 0.2f);
        spF4 = 1.0f;
        spF8 = temp_f26_197;
        spFC = 1.0f;
        sp240 = (f64) spF0;
        sp248 = (f64) spF8;
        ((EmbersPS *) gb.unk74)->Emit(*((MKVector3 *) &this->unk260.unk30), *((MKVector3 *) &sp260), sp18, *((MKVector4 *) &sp240), -980.0f);
        var_r29_153 += 1;
    } while (var_r29_153 < 0x1E);
    temp_r3_220 = M2C_FIELD(temp_r28_88, void **, 0x16C);
    temp_r3_224 = M2C_FIELD(M2C_FIELD(temp_r3_220, void **, 0x44), void *(**)(void *), 0x3C)(temp_r3_220);
    if (temp_r3_224 != NULL) {
        temp_r27_229 = M2C_FIELD(temp_r3_224, void **, 0x2C);
        MKVector(0.0f, 100.0f, 0.0f);
        sp80 = M2C_FIELD(this, f64 *, 0x290) + sp220;
        M2C_FIELD(temp_r3_224, f64 *, 0) = sp80;
        sp88 = this->unk260.unk38 + sp228;
        sp230 = sp80;
        M2C_FIELD(temp_r3_224, f64 *, 8) = (f64) sp88;
        M2C_FIELD(temp_r3_224, f32 *, 0x20) = 0.0f;
        sp238 = (f64) sp88;
        M2C_FIELD(temp_r3_224, f32 *, 0x28) = 0.0f;
        temp_f1_257 = 3.1415927f * MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        sp78 = 0.0f;
        sp70 = 0.0f;
        sp74 = 0.0f;
        M2C_FIELD(temp_r3_224, f32 *, 0x24) = (f32) (2.0f * temp_f1_257);
        M2C_FIELD(temp_r27_229, f64 *, 0) = (f64) sp70;
        M2C_FIELD(temp_r27_229, f64 *, 8) = (f64) sp78;
        sp210 = (f64) sp70;
        sp218 = (f64) sp78;
        M2C_FIELD(temp_r27_229, f32 *, 0x18) = 30.0f;
        M2C_FIELD(temp_r27_229, f32 *, 0x10) = MKRand_Float(&gViewSeed, -6.2831855f, 6.2831855f);
        M2C_FIELD(temp_r27_229, f32 *, 0x14) = (f32) M2C_FIELD(M2C_FIELD(temp_r28_88, void **, 0x16C), f32 *, 0xF4);
    }
    var_r29_281 = 0;
    do {
        MKVector(0.0f, 100.0f, 0.0f);
        sp60 = M2C_FIELD(this, f64 *, 0x290) + sp1F0;
        sp48 = 1.0f;
        sp58 = -1.0f;
        sp68 = this->unk260.unk38 + sp1F8;
        sp40 = 1.0f;
        sp44 = 1.0f;
        sp50 = -1.0f;
        sp54 = 0.25f;
        sp200 = sp60;
        sp208 = (f64) sp68;
        sp2D0 = sp60;
        sp2D8 = (f64) sp68;
        sp1C0 = (f64) sp40;
        sp1C8 = (f64) sp48;
        sp1D0 = (f64) sp50;
        sp1D8 = (f64) sp58;
        KDRand_Vector(sp1E0, *((MKVector3 *) &sp1D0));
        sp2C0 = M2C_BITWISE(f64, sp1E0);
        sp2C8 = (f64) sp1E0.unk8;
        temp_f0_328 = sp2C0 * 5.60222949e-315;
        spE0 = temp_f0_328;
        sp1B0 = temp_f0_328;
        spE8 = (f32) sp2C8 * 300.0f;
        sp1B8 = (f64) spE8;
        sp14 = MKRand_Int(&gViewSeed, 0, 3);
        ((FallingLeaves *) (M2C_FIELD(temp_r28_88, FallingLeaves **, 0x170)))->Emit(*((MKVector3 *) &sp2D0), *((MKVector3 *) &sp1B0), 2.0f, sp14, 1U);
        var_r29_281 += 1;
    } while (var_r29_281 < 0x14);
    var_f4_352 = 0.0f;
    spD0 = 0.0f;
    temp_r3_358 = M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 8);
    spD4 = 200.0f;
    spD8 = 0.0f;
    sp180 = (f64) spD0;
    sp2B0 = M2C_FIELD(temp_r3_358, f64 *, 0x30);
    sp2B8 = M2C_FIELD(temp_r3_358, f64 *, 0x38);
    sp188 = (f64) spD8;
    temp_f0_371 = M2C_FIELD(this, f64 *, 0x290) + sp180;
    spC0 = temp_f0_371;
    sp190 = temp_f0_371;
    spC8 = this->unk260.unk38 + (f32) sp188;
    sp198 = (f64) spC8;
    spB0 = sp190 - sp2B0;
    sp1A0 = spB0;
    spB8 = (f32) sp198 - (f32) sp2B8;
    sp1A8 = (f64) spB8;
    var_f5_400 = ((f32) sp1A8 * (f32) sp1A8) + (((f32) sp1A0 * (f32) sp1A0) + ((*(f32 *) ((u8 *) &sp1A0 + 0x4)) * (*(f32 *) ((u8 *) &sp1A0 + 0x4))));
    if (var_f5_400 > 1e-12f) {
        if (var_f5_400 > 0.0f) {
            temp_f1_405 = __frsqrte(var_f5_400);
            temp_f1_411 = 0.5 * temp_f1_405 * -(((f64) var_f5_400 * (temp_f1_405 * temp_f1_405)) - 3.0);
            temp_f1_415 = 0.5 * temp_f1_411 * -(((f64) var_f5_400 * (temp_f1_411 * temp_f1_411)) - 3.0);
            var_f5_400 = (f32) ((f64) var_f5_400 * (0.5 * temp_f1_415 * -(((f64) var_f5_400 * (temp_f1_415 * temp_f1_415)) - 3.0)));
        } else if (var_f5_400 < M2C_BITWISE(f32, 0.0)) {
            var_f5_400 = __float_nan;
        } else {
            sp10 = var_f5_400;
            temp_r3_434 = M2C_BITWISE(s32, sp10) & 0x7F800000;
            switch (temp_r3_434) {                  /* irregular */
            case 0x7F800000:
                if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                    var_r0_444 = 1;
                } else {
                    var_r0_444 = 2;
                }
                break;
            case 0x0:
                if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                    var_r0_444 = 5;
                } else {
                    var_r0_444 = 3;
                }
                break;
            default:
                var_r0_444 = 4;
                break;
            }
            if (var_r0_444 == 1) {
                var_f5_400 = __float_nan;
            }
        }
        var_f4_352 = 1.0f / var_f5_400;
    }
    spA4 = (*(f32 *) ((u8 *) &sp1A0 + 0x4)) * var_f4_352;
    spA0 = (f32) sp1A0 * var_f4_352;
    spA8 = (f32) sp1A8 * var_f4_352;
    sp2A0 = (f64) spA0;
    sp2A8 = (f64) spA8;
    M2C_STRUCT_COPY((s32) &sp30C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
    sp98 = 0.0f;
    sp90 = 0.0f;
    sp94 = 1.0f;
    sp298 = (f64) sp98;
    sp290 = (f64) sp90;
    KDMath_BuildMatrixFromFwd(&sp310, *((MKVector3 *) &sp2A0), (MKVector3 *) &sp290);
    sp310.Scale3x3(&sp310, 2.5f);
    MKVector(0.0f, 200.0f, 0.0f);
    sp30 = M2C_FIELD(this, f64 *, 0x290) + sp160;
    sp170 = sp30;
    sp38 = this->unk260.unk38 + sp168;
    sp178 = (f64) sp38;
    sp310.unk30 = (f32) sp170;
    sp310.unk34 = (*(f32 *) ((u8 *) &sp170 + 0x4));
    sp310.unk38 = (f32) sp178;
    sp310.unk3C = 1.0f;
    gb.unk1C0.StartWarp(&sp310);
    if ((void *) M2C_FIELD(&gb, void **, 0x3B8) != NULL) {
        sp2F4 = 0;
        MKVector(0.0f, 1.0f, 0.0f);
        sp20 = sp140 * 5.676053805e-315;
        sp2F0 = 0x417;
        sp2F8 = sp20;
        sp28 = sp148 * 1000.0f;
        sp308 = 1;
        sp300 = (f64) sp28;
        sp150 = sp20;
        sp158 = (f64) sp28;
        M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, f64), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &sp2F0, sp20);
    }
}
#endif

void SquishBoulder::Disable() {
    this->unk1A8 = NULL;
    KDProp::Disable();
}

#if 0 // DRAFT: undefined identifier 'unk25C'
void SquishBoulder::Trigger(const MKVector3 &arg0, const MKVector3 &arg1, float arg2, MKProp *arg3) {
    s32 temp_r0_670;
    s32 temp_r28_693;
    s32 temp_r3_668;
    s32 var_r29_686;
    u8 var_r3_676;
    void *temp_r4_672;

    this->unk1A8 = arg3;
    this->unk1B0 = M2C_FIELD(&arg0, f64 *, 0);
    this->unk1B8 = M2C_FIELD(&arg0, f64 *, 8);
    this->unk1C0 = M2C_FIELD(&arg1, f64 *, 0);
    this->unk1C8 = M2C_FIELD(&arg1, f64 *, 8);
    this->unk1D0 = arg2;
    this->unk1D4 = 0;
    M2C_STRUCT_COPY((s32) &this->unk25C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
    this->unk260.unk30 = arg0.unk0;
    this->unk260.unk34 = arg0.unk4;
    this->unk260.unk38 = arg0.unk8;
    this->unk260.unk3C = 1.0f;
    MKModel_SetWorldMatrix(this->unk4, this->unk260);
    temp_r3_668 = M2C_FIELD(GameData::gameData, s32 *, 0x158) << 5;
    temp_r0_670 = *(&GameData::gameData[0x70] + (temp_r3_668 + 0x7C));
    temp_r4_672 = &GameData::gameData[0x70] + (temp_r3_668 + 0x64);
    if (temp_r0_670 == 3) {
        var_r3_676 = 0;
        if (((s32) M2C_FIELD(temp_r4_672, s32 *, 0) == 3) && ((s32) M2C_FIELD(temp_r4_672, s32 *, 4) == 3)) {
            var_r3_676 = 1;
        }
        var_r29_686 = var_r3_676 != 0;
    } else {
        var_r29_686 = *(temp_r4_672 + (temp_r0_670 * 4));
    }
    temp_r28_693 = M2C_FIELD(GameData::gameData, s32 *, 0x158);
    this->unk200.Init(gb.unk0->GetProp(), 15.0f * gb.unk37C, 3, var_r29_686, temp_r28_693, temp_r28_693, 0, -1);
    M2C_FIELD(this, f64 *, 0x210) = (f64) M2C_FIELD(&arg1, f64 *, 0);
    M2C_FIELD(this, f64 *, 0x218) = (f64) M2C_FIELD(&arg1, f64 *, 8);
}
#endif

#if 0 // DRAFT: function call 'KDSound_Stop(long *)' does not match
void SquishBoulder::Deinit() {
    KDSound_Stop(&this->unk1D8);
    Shatterable::Deinit();
}
#endif

void SquishBoulder::Draw() {
    s32 temp_r0_750;

    temp_r0_750 = this->unk1D4;
    if ((temp_r0_750 != 0) && (temp_r0_750 != 2)) {
        Shatterable::Draw();
    }
}

void SquishBoulder::Message(MKMessage *arg0) {
    ((KDSoundPlayer *) &this->unk1D8)->Message(arg0);
    Shatterable::Message(arg0);
}

#if 0 // DRAFT: illegal implicit conversion from 'long *' to
void SquishBoulder::Update() {
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    s32 sp14;
    s32 sp10;
    s32 sp8;
    MKProp *temp_r3_899;
    f32 temp_f2_865;
    f64 temp_f0_846;
    f64 temp_f0_858;
    s32 temp_r0_813;
    u8 var_r0_860;

    PooledShatterProp::Update();
    sp8 = 1;
    ((KDSoundFader *) &this->unk1D8)->Update(GS_SpyroEarthFuryFall, 1U, this->unk1D4 == 1, (MKProp *) this, NULL, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    this->unk1D0 -= gUpdateTimeDelta;
    temp_r0_813 = this->unk1D4;
    switch (temp_r0_813) {                          /* irregular */
    case 0:
        if (this->unk1D0 <= 0.0f) {
            this->unk1D4 = 1;
        }
    default:
block_15:
        MKModel_SetWorldMatrix(this->unk4, this->unk260);
        return;
    case 1:
        sp38 = 0.0f;
        sp3C = -4000.0f;
        sp40 = 0.0f;
        sp48 = (f64) sp38;
        sp50 = (f64) sp40;
        temp_f0_846 = sp48 * (f64) gUpdateTimeDelta;
        sp28 = temp_f0_846;
        sp58 = temp_f0_846;
        sp30 = (f32) sp50 * gUpdateTimeDelta;
        sp60 = (f64) sp30;
        temp_f0_858 = M2C_FIELD(this, f64 *, 0x290) + temp_f0_846;
        sp18 = temp_f0_858;
        var_r0_860 = 0;
        temp_f2_865 = M2C_FIELD(this, f32 *, 0x1C4);
        sp68 = temp_f0_858;
        sp20 = this->unk260.unk38 + (f32) sp60;
        sp70 = (f64) sp20;
        M2C_ERROR(/* unknown instruction: cror 0x2, 0x0, 0x2 */);
        if ((*(f32 *) ((u8 *) &sp68 + 0x4)) == temp_f2_865) {
            (*(f32 *) ((u8 *) &sp68 + 0x4)) = temp_f2_865;
            var_r0_860 = 1;
        }
        this->unk260.unk30 = (f32) sp68;
        this->unk260.unk34 = (*(f32 *) ((u8 *) &sp68 + 0x4));
        this->unk260.unk38 = (f32) sp70;
        this->unk260.unk3C = 1.0f;
        if (var_r0_860 != 0) {
            sp14 = 0;
            sp10 = 0xBA;
            Message(&sp10);
            this->unk1D4 = 2;
            temp_r3_899 = this->unk1A8;
            if (temp_r3_899 != NULL) {
                M2C_FIELD(temp_r3_899->__vptr, M2C_UNK (**)(BreathHitMessage *), 0x2C)(&this->unk200);
            }
            KDSound_Play3d(GS_SpyroEarthFurySmash, ((u8 *) this->unk8) + 0x30, 0U, -1, 0.0f, 0U);
            ((KDInput *) (gb.unk0->GetInput()))->RumblePlay3D(0.3f, 0.1f, 0.3f, ((u8 *) this->unk8) + 0x30, 37.0f, 0, 4.0f, 0U);
            EmitLandingEffects();
        }
        goto block_15;
    }
}
#endif

void SquishBoulder::Init() {
    Shatterable::Init();
    this->unk1A8 = NULL;
    ((KDSoundFader *) &this->unk1D8)->Init(0.25f, 0.25f);
}

#if 0 // DRAFT: undefined identifier 'unk16C'
void SquishBoulderDescriptor::Init() {
    void *temp_r3_1000;
    void *temp_r3_995;

    ShatterableDescriptor::Init();
    this->unk16C = checked_cast<KDEnvParticleSystem *, MKProp>(gMK->CreateProp("EarthBeamBlastPS"));
    this->unk170 = checked_cast<FallingLeaves *, MKProp>(gMK->CreateProp("FallingGlowLeaves"));
    temp_r3_995 = this->unk170;
    M2C_FIELD(M2C_FIELD(temp_r3_995, void **, 0x44), M2C_UNK (**)(void *), 0x20)(temp_r3_995);
    temp_r3_1000 = this->unk170;
    M2C_FIELD(M2C_FIELD(temp_r3_1000, void **, 0x44), M2C_UNK (**)(void *), 0x30)(temp_r3_1000);
}
#endif
