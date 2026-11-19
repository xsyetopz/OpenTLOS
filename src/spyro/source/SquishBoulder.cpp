#include "spyro/source/SquishBoulder.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/FallingLeaves.h"
#include "spyro/source/Game.h"
#include "spyro/source/HeroInterface.h"
#include "spyro/source/KDInput.h"
#include "spyro/source/KDParticleSystem.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/PooledShatterProp.h"
#include "spyro/source/Shatterable.h"
#include "unplaced_templates.h"
#include "common/Source/MKModel.h"
#include "common/Source/StdMath.h"
#include "spyro/source/KDMath.h"
#include "spyro/source/KDRandom.h"
#include "spyro/source/KDSound.h"
#include <m2c_macros.h>

extern s32 GS_SpyroEarthFuryFall;
extern s32 GS_SpyroEarthFurySmash;
extern MKSceneManager *gMK;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern GameGlobals gb;

#if 0 // DRAFT: undefined identifier 'arg_sp2E0'
static s8 lit_stringBase0[0x23] = {
    0x45,
    0x61,
    0x72,
    0x74,
    0x68,
    0x42,
    0x65,
    0x61,
    0x6D,
    0x42,
    0x6C,
    0x61,
    0x73,
    0x74,
    0x50,
    0x53,
    0,
    0x46,
    0x61,
    0x6C,
    0x6C,
    0x69,
    0x6E,
    0x67,
    0x47,
    0x6C,
    0x6F,
    0x77,
    0x4C,
    0x65,
    0x61,
    0x76,
    0x65,
    0x73,
    0,
}; /* const */

void SquishBoulder::EmitLandingEffects() {
    f32 temp_f1_121;
    f32 temp_f1_257;
    f32 temp_f20_102;
    f32 temp_f21_105;
    f32 temp_f26_165;
    f32 temp_f26_197;
    f32 temp_f27_160;
    f32 var_f4_352;
    f32 var_f5_400;
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
        arg_sp2E0 = _table_sinf(temp_f20_102);
        arg_sp2E4 = 0.0f;
        arg_sp2E8 = temp_f21_105;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f25 */);
        arg_sp2E8 = (f32) temp_f21_105 * 1500.0f;
        temp_f1_121 = MKRand_Float(&gViewSeed, 0.8f, 1.2f);
        arg_sp130 = 0.0f;
        arg_sp134 = 100.0f;
        arg_sp138 = 0.0f;
        arg_sp1C = temp_f1_121;
        arg_sp270 = (f64) arg_sp130;
        arg_sp278 = (f64) arg_sp138;
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r30, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        arg_sp280 = arg_sp120;
        arg_sp128 = this->unk260.unk24 + (f32) arg_sp278;
        arg_sp288 = (f64) arg_sp128;
        gb.EmitDust(*((MKVector3 *) &arg_sp280), *((MKVector3 *) &arg_sp2E0), arg_sp1C, 0.0f);
        var_r27_92 += 1;
    } while (var_r27_92 < 0x14);
    var_r29_153 = 0;
    do {
        temp_f27_160 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        temp_f26_165 = MKRand_Float(&gViewSeed, 0.0f, 1.0f);
        arg_sp110 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        arg_sp114 = temp_f26_165;
        arg_sp118 = temp_f27_160;
        arg_sp250 = (f64) arg_sp110;
        arg_sp258 = (f64) arg_sp118;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f24 */);
        arg_sp260 = arg_sp100;
        arg_sp108 = (f32) arg_sp258 * 1000.0f;
        arg_sp268 = (f64) arg_sp108;
        arg_sp18 = MKRand_Float(&gViewSeed, 25.0f, 35.0f);
        temp_f26_197 = MKRand_Float(&gViewSeed, 0.0f, 0.2f);
        arg_spF0 = MKRand_Float(&gViewSeed, 0.0f, 0.2f);
        arg_spF4 = 1.0f;
        arg_spF8 = temp_f26_197;
        arg_spFC = 1.0f;
        arg_sp240 = (f64) arg_spF0;
        arg_sp248 = (f64) arg_spF8;
        gb.unk74->Emit(*((MKVector3 *) &this->unk260.unk1C), *((MKVector3 *) &arg_sp260), arg_sp18, *((MKVector4 *) &arg_sp240), -980.0f);
        var_r29_153 += 1;
    } while (var_r29_153 < 0x1E);
    temp_r3_220 = M2C_FIELD(temp_r28_88, void **, 0x16C);
    temp_r3_224 = M2C_FIELD(M2C_FIELD(temp_r3_220, void **, 0x44), void *(**)(void *), 0x3C)(temp_r3_220);
    if (temp_r3_224 != NULL) {
        temp_r27_229 = M2C_FIELD(temp_r3_224, void **, 0x2C);
        MKVector(0.0f, 100.0f, 0.0f);
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r30, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        M2C_FIELD(temp_r3_224, f64 *, 0) = arg_sp80;
        arg_sp88 = this->unk260.unk24 + arg_sp228;
        arg_sp230 = arg_sp80;
        M2C_FIELD(temp_r3_224, f64 *, 8) = (f64) arg_sp88;
        M2C_FIELD(temp_r3_224, f32 *, 0x20) = 0.0f;
        arg_sp238 = (f64) arg_sp88;
        M2C_FIELD(temp_r3_224, f32 *, 0x28) = 0.0f;
        temp_f1_257 = 3.1415927f * MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        arg_sp78 = 0.0f;
        arg_sp70 = 0.0f;
        arg_sp74 = 0.0f;
        M2C_FIELD(temp_r3_224, f32 *, 0x24) = (f32) (2.0f * temp_f1_257);
        M2C_FIELD(temp_r27_229, f64 *, 0) = (f64) arg_sp70;
        M2C_FIELD(temp_r27_229, f64 *, 8) = (f64) arg_sp78;
        arg_sp210 = (f64) arg_sp70;
        arg_sp218 = (f64) arg_sp78;
        M2C_FIELD(temp_r27_229, f32 *, 0x18) = 30.0f;
        M2C_FIELD(temp_r27_229, f32 *, 0x10) = MKRand_Float(&gViewSeed, -6.2831855f, 6.2831855f);
        M2C_FIELD(temp_r27_229, f32 *, 0x14) = (f32) M2C_FIELD(M2C_FIELD(temp_r28_88, void **, 0x16C), f32 *, 0xF4);
    }
    var_r29_281 = 0;
    do {
        MKVector(0.0f, 100.0f, 0.0f);
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r30, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        arg_sp48 = 1.0f;
        arg_sp58 = -1.0f;
        arg_sp68 = this->unk260.unk24 + arg_sp1F8;
        arg_sp40 = 1.0f;
        arg_sp44 = 1.0f;
        arg_sp50 = -1.0f;
        arg_sp54 = 0.25f;
        arg_sp200 = arg_sp60;
        arg_sp208 = (f64) arg_sp68;
        arg_sp2D0 = arg_sp60;
        arg_sp2D8 = (f64) arg_sp68;
        arg_sp1C0 = (f64) arg_sp40;
        arg_sp1C8 = (f64) arg_sp48;
        arg_sp1D0 = (f64) arg_sp50;
        arg_sp1D8 = (f64) arg_sp58;
        KDRand_Vector(*((MKVector3 *) &arg_sp1E0), *((MKVector3 *) &arg_sp1D0));
        arg_sp2C0 = arg_sp1E0;
        arg_sp2C8 = arg_sp1E8;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f23 */);
        arg_sp1B0 = arg_spE0;
        arg_spE8 = (f32) arg_sp2C8 * 300.0f;
        arg_sp1B8 = (f64) arg_spE8;
        arg_sp14 = MKRand_Int(&gViewSeed, 0, 3);
        ((FallingLeaves *) (M2C_FIELD(temp_r28_88, FallingLeaves **, 0x170)))->Emit(*((MKVector3 *) &arg_sp2D0), *((MKVector3 *) &arg_sp1B0), 2.0f, arg_sp14, 1U);
        var_r29_281 += 1;
    } while (var_r29_281 < 0x14);
    var_f4_352 = 0.0f;
    arg_spD0 = 0.0f;
    temp_r3_358 = M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 8);
    arg_spD4 = 200.0f;
    arg_spD8 = 0.0f;
    arg_sp180 = (f64) arg_spD0;
    arg_sp2B0 = M2C_FIELD(temp_r3_358, f64 *, 0x30);
    arg_sp2B8 = M2C_FIELD(temp_r3_358, f64 *, 0x38);
    arg_sp188 = (f64) arg_spD8;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r30, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    arg_sp190 = arg_spC0;
    arg_spC8 = this->unk260.unk24 + (f32) arg_sp188;
    arg_sp198 = (f64) arg_spC8;
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    arg_sp1A0 = arg_spB0;
    arg_spB8 = (f32) arg_sp198 - (f32) arg_sp2B8;
    arg_sp1A8 = (f64) arg_spB8;
    var_f5_400 = ((f32) arg_sp1A8 * (f32) arg_sp1A8) + (((f32) arg_sp1A0 * (f32) arg_sp1A0) + (arg_sp1A4 * arg_sp1A4));
    if (var_f5_400 > 1e-12f) {
        if (var_f5_400 > 0.0f) {
            temp_f1_405 = __frsqrte(var_f5_400);
            temp_f1_411 = 0.5 * temp_f1_405 * -(((f64) var_f5_400 * (temp_f1_405 * temp_f1_405)) - 3.0);
            temp_f1_415 = 0.5 * temp_f1_411 * -(((f64) var_f5_400 * (temp_f1_411 * temp_f1_411)) - 3.0);
            var_f5_400 = (f32) ((f64) var_f5_400 * (0.5 * temp_f1_415 * -(((f64) var_f5_400 * (temp_f1_415 * temp_f1_415)) - 3.0)));
        } else if (var_f5_400 < M2C_BITWISE(f32, 0.0)) {
            var_f5_400 = __float_nan;
        } else {
            arg_sp10 = var_f5_400;
            temp_r3_434 = M2C_BITWISE(s32, arg_sp10) & 0x7F800000;
            switch (temp_r3_434) {                  /* irregular */
            case 0x7F800000:
                if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                    var_r0_444 = 1;
                } else {
                    var_r0_444 = 2;
                }
                break;
            case 0x0:
                if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
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
    arg_spA4 = arg_sp1A4 * var_f4_352;
    arg_spA0 = (f32) arg_sp1A0 * var_f4_352;
    arg_spA8 = (f32) arg_sp1A8 * var_f4_352;
    arg_sp2A0 = (f64) arg_spA0;
    arg_sp2A8 = (f64) arg_spA8;
    M2C_STRUCT_COPY((s32) &arg_sp30C + 4, (s32) (&identity - 4) + 4, 0x40);
    arg_sp98 = 0.0f;
    arg_sp90 = 0.0f;
    arg_sp94 = 1.0f;
    arg_sp298 = (f64) arg_sp98;
    arg_sp290 = (f64) arg_sp90;
    KDMath_BuildMatrixFromFwd((Matrix *) &arg_sp310, *((MKVector3 *) &arg_sp2A0), (MKVector3 *) &arg_sp290);
    arg_sp310.Scale3x3((Matrix *) &arg_sp310, 2.5f);
    MKVector(0.0f, 200.0f, 0.0f);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r30, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    arg_sp170 = arg_sp30;
    arg_sp38 = this->unk260.unk24 + arg_sp168;
    arg_sp178 = (f64) arg_sp38;
    arg_sp340 = (f32) arg_sp170;
    arg_sp344 = arg_sp174;
    arg_sp348 = (f32) arg_sp178;
    arg_sp34C = 1.0f;
    gb.unk1C0.StartWarp((Matrix *) &arg_sp310);
    if ((void *) M2C_FIELD(&gb, void **, 0x3B8) != NULL) {
        arg_sp2F4 = 0;
        MKVector(0.0f, 1.0f, 0.0f);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f22 */);
        arg_sp2F0 = 0x417;
        arg_sp2F8 = arg_sp20;
        arg_sp28 = arg_sp148 * 1000.0f;
        arg_sp308 = 1;
        arg_sp300 = (f64) arg_sp28;
        arg_sp150 = arg_sp20;
        arg_sp158 = (f64) arg_sp28;
        M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, f64), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &arg_sp2F0, arg_sp20);
    }
}
#endif

void SquishBoulder::Disable() {
    this->unk198 = 0.0f;
    KDProp::Disable();
}

#if 0 // DRAFT: illegal explicit conversion from 'MKProp *' to
void SquishBoulder::Trigger(const MKVector3 &arg0, const MKVector3 &arg1, float arg2, MKProp *arg3) {
    s32 temp_r0_670;
    s32 temp_r28_693;
    s32 temp_r3_668;
    s32 var_r29_686;
    u8 var_r3_676;
    void *temp_r4_672;

    this->unk198 = M2C_BITWISE(f32, arg3);
    M2C_FIELD(this, f64 *, 0x1B0) = (f64) M2C_FIELD(&arg0, f64 *, 0);
    M2C_FIELD(this, f64 *, 0x1B8) = (f64) M2C_FIELD(&arg0, f64 *, 8);
    this->unk1B0 = M2C_FIELD(&arg1, f64 *, 0);
    this->unk1B8 = M2C_FIELD(&arg1, f64 *, 8);
    M2C_FIELD(this, f32 *, 0x1D0) = arg2;
    M2C_FIELD(this, s32 *, 0x1D4) = 0;
    M2C_STRUCT_COPY((s32) &this->unk200.unk4C + 4, (s32) (&identity - 4) + 4, 0x40);
    this->unk260.unk1C = arg0.unk0;
    this->unk260.unk20 = arg0.unk4;
    this->unk260.unk24 = arg0.unk8;
    this->unk260.unk28 = 1.0f;
    MKModel_SetWorldMatrix(this->unk4, *((Matrix *) &this->unk200.unk50));
    temp_r3_668 = gameData.unk158 << 5;
    temp_r0_670 = *(&gameData.unk70 + (temp_r3_668 + 0x7C));
    temp_r4_672 = &gameData.unk70 + (temp_r3_668 + 0x64);
    if (temp_r0_670 == 3) {
        var_r3_676 = 0;
        if (((s32) M2C_FIELD(temp_r4_672, s32 *, 0) == 3) && ((s32) M2C_FIELD(temp_r4_672, s32 *, 4) == 3)) {
            var_r3_676 = 1;
        }
        var_r29_686 = var_r3_676 != 0;
    } else {
        var_r29_686 = *(temp_r4_672 + (temp_r0_670 * 4));
    }
    temp_r28_693 = gameData.unk158;
    this->unk200.Init(M2C_FIELD(gb.unk0->__vptr, MKProp *(**)(HeroInterface *), 0xC)(gb.unk0), 15.0f * gb.unk37C, 3, var_r29_686, temp_r28_693, temp_r28_693, 0, -1);
    M2C_FIELD(this, f64 *, 0x210) = (f64) M2C_FIELD(&arg1, f64 *, 0);
    M2C_FIELD(this, f64 *, 0x218) = (f64) M2C_FIELD(&arg1, f64 *, 8);
}
#endif

#if 0 // DRAFT: undefined identifier 'unk1C8'
void SquishBoulder::Deinit() {
    KDSound_Stop((s32 *) &this->unk1C8);
    Shatterable::Deinit();
}
#endif

void SquishBoulder::Draw() {
    s32 temp_r0_750;

    temp_r0_750 = M2C_FIELD(this, s32 *, 0x1D4);
    if ((temp_r0_750 != 0) && (temp_r0_750 != 2)) {
        Shatterable::Draw();
    }
}

#if 0 // DRAFT: undefined identifier 'unk1C8'
void SquishBoulder::Message(MKMessage *arg0) {
    this->unk1C8.Message(arg0);
    Shatterable::Message(arg0);
}
#endif

#if 0 // DRAFT: illegal use of non-static member
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
    f32 sp20;
    s32 sp14;
    s32 sp10;
    s32 sp8;
    f32 temp_f2_865;
    f32 temp_r3_899;
    s32 temp_r0_813;
    u8 var_r0_860;

    PooledShatterProp::Update();
    sp8 = 1;
    this->unk1C8.Update(GS_SpyroEarthFuryFall, 1U, M2C_FIELD(this, s32 *, 0x1D4) == 1, (MKProp *) this, NULL, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    M2C_FIELD(this, f32 *, 0x1D0) = (f32) (M2C_FIELD(this, f32 *, 0x1D0) - gUpdateTimeDelta);
    temp_r0_813 = M2C_FIELD(this, s32 *, 0x1D4);
    switch (temp_r0_813) {                          /* irregular */
    case 0:
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if (M2C_FIELD(this, f32 *, 0x1D0) == 0.0f) {
            M2C_FIELD(this, s32 *, 0x1D4) = 1;
        }
    default:
block_15:
        MKModel_SetWorldMatrix(this->unk4, *((Matrix *) &this->unk200.unk50));
        return;
    case 1:
        sp38 = 0.0f;
        sp3C = -4000.0f;
        sp40 = 0.0f;
        sp48 = (f64) sp38;
        sp50 = (f64) sp40;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
        sp58 = sp28;
        sp30 = (f32) sp50 * gUpdateTimeDelta;
        sp60 = (f64) sp30;
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r3, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        var_r0_860 = 0;
        temp_f2_865 = M2C_FIELD(this, f32 *, 0x1C4);
        sp68 = sp18;
        sp20 = this->unk260.unk24 + (f32) sp60;
        sp70 = (f64) sp20;
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if (unksp6C == temp_f2_865) {
            unksp6C = temp_f2_865;
            var_r0_860 = 1;
        }
        this->unk260.unk1C = (f32) sp68;
        this->unk260.unk20 = unksp6C;
        this->unk260.unk24 = (f32) sp70;
        this->unk260.unk28 = 1.0f;
        if (var_r0_860 != 0) {
            sp14 = 0;
            sp10 = 0xBA;
            Message(&sp10);
            M2C_FIELD(this, s32 *, 0x1D4) = 2;
            temp_r3_899 = this->unk198;
            if (M2C_BITWISE(u32, temp_r3_899) != 0U) {
                M2C_FIELD(M2C_FIELD(temp_r3_899, void **, 0x44), M2C_UNK (**)(M2C_UNK *), 0x2C)(&this->unk200);
            }
            KDSound_Play3d(GS_SpyroEarthFurySmash, this->unk8 + 0x30, 0U, -1, 0.0f, 0U);
            ((KDInput *) (M2C_FIELD(gb.unk0->__vptr, KDInput *(**)(HeroInterface *), 0x40)(gb.unk0)))->RumblePlay3D(0.3f, 0.1f, 0.3f, this->unk8 + 0x30, 37.0f, 0, 4.0f, 0U);
            EmitLandingEffects();
        }
        goto block_15;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk1C8'
void SquishBoulder::Init() {
    Shatterable::Init();
    this->unk198 = 0.0f;
    this->unk1C8.Init(0.25f, 0.25f);
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_stringBase0'
void SquishBoulderDescriptor::Init() {
    void *temp_r3_1000;
    void *temp_r3_995;

    ShatterableDescriptor::Init();
    this->unk16C = checked_cast<KDEnvParticleSystem *, MKProp>(gMK->CreateProp(lit_stringBase0));
    this->unk170 = checked_cast<FallingLeaves *, MKProp>(gMK->CreateProp(&lit_stringBase0[0x11]));
    temp_r3_995 = this->unk170;
    M2C_FIELD(M2C_FIELD(temp_r3_995, void **, 0x44), M2C_UNK (**)(void *), 0x20)(temp_r3_995);
    temp_r3_1000 = this->unk170;
    M2C_FIELD(M2C_FIELD(temp_r3_1000, void **, 0x44), M2C_UNK (**)(void *), 0x30)(temp_r3_1000);
}
#endif
