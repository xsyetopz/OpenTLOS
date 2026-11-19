#include "spyro/source/FuryFXElectricity.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/FuryFX.h"
#include "spyro/source/Game.h"
#include "spyro/source/GameData.h"
#include "spyro/source/GameMessages.h"
#include "spyro/source/HeroInterface.h"
#include "spyro/source/KDInput.h"
#include "spyro/source/LitCloudPS.h"
#include "spyro/source/ManagedLight.h"
#include "spyro/source/Spyro.h"
#include "spyro/source/ZapPS.h"
#include "unplaced_templates.h"
#include "common/Source/MKCollision.h"
#include "common/Source/StdMath.h"
#include "common/gc/MKMaterial_GC.h"
#include "common/gc/MKPrimitive_GC.h"
#include "spyro/source/KDRandom.h"
#include "spyro/source/KDSound.h"
#include <m2c_macros.h>

extern s32 GS_Rumble1;
extern s32 GS_SpyroFuryAttackLightning1;
extern s32 GS_SpyroFuryAttackLightning2;
extern f32 SPYRO_BOUNCE_Y_SPEED;
extern f32 SPYRO_MIN_JUMP_Y_VELOCITY;
extern void **gMK;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern GameGlobals gb;

static s32 lit_739 = 0;
static u8 lit_740 = 1;

static u8 lit_828 = 1;

static u8 lit_837 = 1;

#if 0 // DRAFT: pointer/array required
void FuryFXElectricity::ResetFury() {
    s32 spC;
    s32 sp8;
    LitCloudPS *temp_r3_64;
    ManagedLight *temp_r4_55;
    ZapPS *temp_r3_69;

    SetDefaults();
    temp_r4_55 = this->unkC4;
    if (temp_r4_55 != NULL) {
        gb.unk80->EnableLight(temp_r4_55, 0U);
    }
    temp_r3_64 = this->unkC0;
    temp_r3_64->Disable();
    temp_r3_69 = this->unk100;
    temp_r3_69->Disable();
    gb.unk2CC.Disable(M2C_BITWISE(s32, this->unk180));
    this->unk180 = nanf;
    if ((void *) M2C_FIELD(&gb, void **, 0x3B8) != NULL) {
        spC = 0;
        sp8 = 0x459;
        M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp8);
    }
    M2C_FIELD(this, s8 *, 0x18C) = 0;
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_sp60'
void FuryFXElectricity::DrawWindyRing(FuryFXElectricity::WindyRing *arg1) {
    f32 temp_f25_202;
    f32 temp_f25_254;
    f32 temp_f26_205;
    f32 temp_f29_135;
    f32 var_f1_137;
    f32 var_f2_144;
    s32 var_r27_185;
    s32 var_r29_239;
    s32 var_r31_187;
    s32 var_r31_241;
    void *temp_r28_261;
    void *temp_r3_215;
    temp_f29_135 = (350.0f * _table_sinf(M2C_FIELD(arg1, f32 *, 4))) + 550.0f;
    var_f1_137 = _table_sinf(M2C_FIELD(arg1, f32 *, 0));
    if (var_f1_137 < 0.0f) {
        var_f1_137 = -var_f1_137;
    }
    var_f2_144 = 0.5f + var_f1_137;
    if (var_f2_144 < 1.0f) {

    } else {
        var_f2_144 = 1.0f;
    }
    if (var_f2_144 > 0.0f) {

    } else {
        var_f2_144 = 0.0f;
    }
    arg_sp60 = var_f2_144;
    arg_sp64 = var_f2_144;
    arg_sp68 = var_f2_144;
    arg_sp6C = 1.0f;
    arg_spD0 = (f64) arg_sp60;
    arg_spD8 = (f64) arg_sp68;
    M2C_STRUCT_COPY((s32) &arg_spDC + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
    arg_sp110 = this->unkB0;
    var_r27_185 = 0;
    var_r31_187 = 0;
    arg_sp114 = this->unkB4;
    arg_sp118 = this->unkB8;
    arg_sp11C = 1.0f;
    do {
        temp_f25_202 = (f32) var_r27_185 * 0.44879895f;
        temp_f26_205 = -_table_sinf(1.5707964f + temp_f25_202);
        MKVector(_table_sinf(temp_f25_202), 0.0f, temp_f26_205);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r28, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
        temp_r3_215 = &arg_sp120 + var_r31_187;
        var_r27_185 += 1;
        var_r31_187 += 0x10;
        M2C_FIELD(temp_r3_215, f64 *, 0) = arg_sp10;
        arg_sp18 = arg_spB8 * temp_f29_135;
        arg_spC0 = arg_sp10;
        arg_spC8 = (f64) arg_sp18;
        M2C_FIELD(temp_r3_215, f64 *, 8) = (f64) arg_sp18;
    } while (var_r27_185 < 0xF);
    MKMaterial_SetMaterial(M2C_FIELD(arg1, MKMaterial **, 8));
    MKPrimitive(0xC, 0x10);
    MKSetMatrix(*((Matrix *) &arg_spE0));
    MKBegin(0x1E);
    var_r29_239 = 0;
    var_r31_241 = 0;
    do {
        temp_f25_254 = 4.0f * ((f32) var_r29_239 / 14.0f);
        MKSetColorV(*((MKVector4 *) &arg_spD0));
        MKSetTexCoord1F(temp_f25_254, 2.0f);
        temp_r28_261 = &arg_sp120 + var_r31_241;
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r28, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f28 */);
        arg_spA0 = arg_sp50;
        arg_sp58 = M2C_FIELD(temp_r28_261, f32 *, 8) * 0.75f;
        arg_spA8 = (f64) arg_sp58;
        MKSetPositionV(*((MKVector3 *) &arg_spA0));
        arg_sp40 = 0.0f;
        arg_sp44 = 0.0f;
        arg_sp48 = 0.0f;
        arg_sp4C = 0.0f;
        arg_sp90 = (f64) arg_sp40;
        arg_sp98 = (f64) arg_sp48;
        MKSetColorV(*((MKVector4 *) &arg_sp90));
        MKSetTexCoord1F(temp_f25_254, 0.0f);
        arg_sp30 = 0.0f;
        arg_sp34 = 700.0f;
        arg_sp38 = 0.0f;
        arg_sp70 = (f64) arg_sp30;
        arg_sp78 = (f64) arg_sp38;
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r28, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        arg_sp80 = arg_sp20;
        arg_sp28 = M2C_FIELD(temp_r28_261, f32 *, 8) + (f32) arg_sp78;
        arg_sp88 = (f64) arg_sp28;
        MKSetPositionV(*((MKVector3 *) &arg_sp80));
        var_r29_239 += 1;
        var_r31_241 += 0x10;
    } while (var_r29_239 < 0xF);
    MKEnd();
    MKEndPrimitive();
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_sp50'
void FuryFXElectricity::DrawElectricityRing() {
    MKVector3 *temp_r28_468;
    f32 temp_f25_410;
    f32 temp_f25_462;
    f32 temp_f28_413;
    s32 var_r27_400;
    s32 var_r29_447;
    s32 var_r31_402;
    s32 var_r31_449;
    void *temp_r3_423;
    arg_sp50 = 1.0f;
    arg_sp54 = 1.0f;
    arg_sp58 = 1.0f;
    arg_sp5C = 1.0f;
    arg_spB0 = (f64) arg_sp50;
    arg_spB8 = (f64) arg_sp58;
    M2C_STRUCT_COPY((s32) &arg_spBC + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
    arg_spF0 = this->unk160;
    arg_spF4 = this->unk160;
    arg_spF8 = this->unk164;
    arg_spFC = 1.0f;
    arg_spC0.Scale3x3((Matrix *) &arg_spC0, this->unk98);
    var_r27_400 = 0;
    var_r31_402 = 0;
    do {
        temp_f25_410 = (f32) var_r27_400 * 0.44879895f;
        temp_f28_413 = -_table_sinf(1.5707964f + temp_f25_410);
        MKVector(_table_sinf(temp_f25_410), 0.0f, temp_f28_413);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r28, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
        temp_r3_423 = &arg_sp100 + var_r31_402;
        var_r27_400 += 1;
        var_r31_402 += 0x10;
        M2C_FIELD(temp_r3_423, f64 *, 0) = arg_sp10;
        arg_sp18 = arg_sp98 * 200.0f;
        arg_spA0 = arg_sp10;
        arg_spA8 = (f64) arg_sp18;
        M2C_FIELD(temp_r3_423, f64 *, 8) = (f64) arg_sp18;
    } while (var_r27_400 < 0xF);
    MKMaterial_SetMaterial(this->unkA8);
    MKPrimitive(0xC, 0x10);
    MKSetMatrix(*((Matrix *) &arg_spC0));
    MKBegin(0x1E);
    var_r29_447 = 0;
    var_r31_449 = 0;
    do {
        temp_f25_462 = 4.0f * ((f32) var_r29_447 / 15.0f);
        MKSetColorV(*((MKVector4 *) &arg_spB0));
        MKSetTexCoord1F(temp_f25_462, 0.95f);
        temp_r28_468 = &arg_sp100 + var_r31_449;
        MKSetPositionV(*temp_r28_468);
        arg_sp40 = 0.0f;
        arg_sp44 = 0.0f;
        arg_sp48 = 0.0f;
        arg_sp4C = 0.0f;
        arg_sp80 = (f64) arg_sp40;
        arg_sp88 = (f64) arg_sp48;
        MKSetColorV(*((MKVector4 *) &arg_sp80));
        MKSetTexCoord1F(temp_f25_462, 0.05f);
        arg_sp30 = 0.0f;
        arg_sp34 = 200.0f;
        arg_sp38 = 0.0f;
        arg_sp60 = (f64) arg_sp30;
        arg_sp68 = (f64) arg_sp38;
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r28, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        arg_sp70 = arg_sp20;
        arg_sp28 = temp_r28_468->unk8 + (f32) arg_sp68;
        arg_sp78 = (f64) arg_sp28;
        MKSetPositionV(*((MKVector3 *) &arg_sp70));
        var_r29_447 += 1;
        var_r31_449 += 0x10;
    } while (var_r29_447 < 0xF);
    MKEnd();
    MKEndPrimitive();
}
#endif

#if 0 // DRAFT: undefined identifier 'unk2CC'
s32 FuryFXElectricity::Trigger(const MKVector3 &arg0, bool arg1) {
    s8 spD8;
    s32 spD4;
    s32 spD0;
    s32 spCC;
    f32 spC8;
    s32 spC4;
    s8 spC3;
    s8 spC2;
    s16 spC0;
    f32 spBC;
    f32 spB8;
    f32 spB4;
    f32 spB0;
    f32 spAC;
    f32 spA8;
    f32 spA0;
    f32 sp9C;
    f32 sp98;
    f32 sp90;
    f32 sp8C;
    f32 sp88;
    f64 sp80;
    f64 sp78;
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
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    LitCloudPS *temp_r3_543;
    LitCloudPS *temp_r3_548;
    ZapPS *temp_r3_553;
    ZapPS *temp_r3_558;
    s32 temp_r0_602;
    s32 temp_r27_625;
    s32 temp_r3_600;
    s32 var_r28_618;
    u8 var_r3_608;
    void *temp_r4_604;

    temp_r3_543 = this->unkC0;
    temp_r3_543->Reset();
    temp_r3_548 = this->unkC0;
    temp_r3_548->Enable();
    temp_r3_553 = this->unk100;
    temp_r3_553->Reset();
    temp_r3_558 = this->unk100;
    temp_r3_558->Enable();
    if ((s32) this->unk90 != 0) {
        return 0;
    }
    M2C_FIELD(this, f32 *, 0x180) = 0.0f;
    M2C_FIELD(this, f32 *, 0x184) = 0.0f;
    this->unk170 = M2C_FIELD(&arg0, f64 *, 0);
    this->unk170 = M2C_FIELD(&arg0, f64 *, 8);
    M2C_FIELD(this, f64 *, 0x160) = (f64) this->unk170;
    M2C_FIELD(this, f64 *, 0x168) = (f64) this->unk170;
    M2C_FIELD(this, f64 *, 0xB0) = (f64) M2C_FIELD(this, f64 *, 0x160);
    M2C_FIELD(this, f64 *, 0xB8) = (f64) M2C_FIELD(this, f64 *, 0x168);
    this->unk90 = 1;
    this->unkAC = 1.0f;
    this->unk180 = M2C_BITWISE(f32, gb.unk2CC.Enable(0.5f, 0.0f, 0.0f, -1.0f));
    temp_r3_600 = GameData::gameData.unk158 << 5;
    temp_r0_602 = *(&GameData::gameData.unk70 + (temp_r3_600 + 0x7C));
    temp_r4_604 = &GameData::gameData.unk70 + (temp_r3_600 + 0x64);
    if (temp_r0_602 == 3) {
        var_r3_608 = 0;
        if (((s32) M2C_FIELD(temp_r4_604, s32 *, 0) == 3) && ((s32) M2C_FIELD(temp_r4_604, s32 *, 4) == 3)) {
            var_r3_608 = 1;
        }
        var_r28_618 = var_r3_608 != 0;
    } else {
        var_r28_618 = *(temp_r4_604 + (temp_r0_602 * 4));
    }
    temp_r27_625 = GameData::gameData.unk158;
    this->unk108.Init(M2C_FIELD(gb.unk0->__vptr, MKProp *(**)(HeroInterface *), 0xC)(gb.unk0), 15.0f * gb.unk37C, 3, var_r28_618, temp_r27_625, temp_r27_625, 0, -1);
    sp38 = 0.0f;
    sp3C = -5000.0f;
    sp40 = 0.0f;
    sp68 = (f64) sp38;
    sp88 = 0.0f;
    sp8C = 0.0f;
    sp90 = 0.0f;
    sp98 = 0.0f;
    sp9C = 0.0f;
    spA0 = 0.0f;
    spA8 = 0.0f;
    spAC = 0.0f;
    spB0 = 0.0f;
    spB4 = 1.0f;
    spB8 = 0.0f;
    spBC = 0.0f;
    spC0 = 0;
    spC2 = 0;
    spC3 = 0;
    spC4 = 0;
    spC8 = 3.4028235e38f;
    spCC = 0;
    spD0 = 0;
    spD4 = -1;
    spD8 = 0;
    sp70 = (f64) sp40;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r30, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    sp78 = sp28;
    sp30 = arg0.unk8 + (f32) sp70;
    sp80 = (f64) sp30;
    if (MKCollision_RayCollide(arg0, *((MKVector3 *) &sp78), (MKCollisionResult *) &sp88, (MKCollisionMode) 4, 0x0C000000) != 0) {
        this->unk170 = (f64) sp88;
        this->unk170 = (f64) sp90;
    }
    sp18 = 0.0f;
    sp1C = 700.0f;
    M2C_FIELD(this, u8 *, 0x18C) = arg1;
    sp20 = 0.0f;
    M2C_FIELD(this, f32 *, 0x194) = 0.25f;
    sp48 = (f64) sp18;
    sp50 = (f64) sp20;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r29, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    sp58 = sp8;
    sp10 = this->unkB8 + (f32) sp50;
    sp60 = (f64) sp10;
    this->unkC0->Trigger(*((MKVector3 *) &sp58));
    this->unkC0->SetScale(M2C_FIELD(this, f32 *, 0x194));
    gb.unk381 = 1;
    return 1;
}
#endif

void FuryFXElectricity::SetDefaults() {
    SetDefaults();
    M2C_FIELD(this, f32 *, 0x180) = -1.0f;
    M2C_FIELD(this, f32 *, 0x184) = 0.0f;
    this->unk90 = 0;
}

#if 0 // DRAFT: pointer/array required
void FuryFXElectricity::Deinit() {
    MKMaterial *temp_r3_779;
    MKMaterial *temp_r3_784;
    MKMaterial *temp_r3_789;
    ManagedLight *temp_r4_794;

    temp_r3_779 = this->unkA8;
    if (temp_r3_779 != NULL) {
        MKMaterial_Destroy(temp_r3_779);
    }
    temp_r3_784 = this->unkC8;
    if (temp_r3_784 != NULL) {
        MKMaterial_Destroy(temp_r3_784);
    }
    temp_r3_789 = this->unkCC;
    if (temp_r3_789 != NULL) {
        MKMaterial_Destroy(temp_r3_789);
    }
    temp_r4_794 = this->unkC4;
    if (temp_r4_794 != NULL) {
        gb.unk80->FreeManagedLight(temp_r4_794);
    }
    gb.unk2CC.Disable(M2C_BITWISE(s32, this->unk180));
    this->unk180 = nanf;
    FuryFX::Deinit();
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'FuryFXElectricity *' to
void FuryFXElectricity::Draw() {
    s32 temp_r0_826;
    s32 var_r30_839;
    s32 var_r31_840;

    temp_r0_826 = this->unk90;
    if ((temp_r0_826 == 2) || (temp_r0_826 == 3) || (temp_r0_826 == 4)) {
        DrawElectricityRing();
        if ((s32) this->unk90 != 4) {
            var_r30_839 = 0;
            var_r31_840 = 0;
            do {
                DrawWindyRing(this + (var_r31_840 + 0xD0));
                var_r30_839 += 1;
                var_r31_840 += 0x10;
            } while (var_r30_839 < 3);
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void FuryFXElectricity::Update() {
    ManagedLight *temp_r3_1168;
    ManagedLight *temp_r3_1181;
    ManagedLight *temp_r3_1644;
    ManagedLight *temp_r3_1664;
    ManagedLight *temp_r3_2002;
    ManagedLight *temp_r3_2024;
    ManagedLight *temp_r3_2367;
    ManagedLight *temp_r4_1145;
    ManagedLight *temp_r4_2345;
    ManagedLight *temp_r4_2636;
    f32 temp_f0_1167;
    f32 temp_f0_1230;
    f32 temp_f0_1443;
    f32 temp_f0_1643;
    f32 temp_f0_2075;
    f32 temp_f0_2255;
    f32 temp_f0_2354;
    f32 temp_f0_2565;
    f32 temp_f1_1094;
    f32 temp_f1_1666;
    f32 temp_f1_2026;
    f32 temp_f1_2444;
    f32 temp_f1_2592;
    f32 temp_f1_889;
    f32 temp_f1_920;
    f32 temp_f21_2430;
    f32 temp_f22_1025;
    f32 temp_f22_1206;
    f32 temp_f22_1419;
    f32 temp_f22_2051;
    f32 temp_f22_2231;
    f32 temp_f22_2439;
    f32 temp_f22_2538;
    f32 temp_f23_1211;
    f32 temp_f23_1424;
    f32 temp_f23_2056;
    f32 temp_f23_2236;
    f32 temp_f23_2432;
    f32 temp_f23_2441;
    f32 temp_f23_2543;
    f32 temp_f25_2418;
    f32 temp_f26_1727;
    f32 temp_f28_2423;
    f32 temp_f29_1775;
    f32 temp_f2_955;
    f32 temp_f3_1809;
    f32 temp_f5_1852;
    f32 var_f0_2372;
    f32 var_f0_2511;
    f32 var_f1_1067;
    f32 var_f22_1274;
    f32 var_f22_1466;
    f32 var_f22_1602;
    f32 var_f26_2522;
    f32 var_f2_1584;
    f32 var_f2_1605;
    f32 var_f2_1705;
    f32 var_f3_1942;
    f32 var_f4_1875;
    f64 temp_f1_1881;
    f64 temp_f1_1887;
    f64 temp_f1_1891;
    f64 temp_f2_2119;
    s32 temp_r0_1052;
    s32 temp_r29_2404;
    s32 temp_r3_1910;
    s32 temp_r3_2692;
    s32 var_r0_1920;
    s32 var_r28_2411;
    s32 var_r28_2664;
    s32 var_r31_2666;
    void *temp_r29_2673;
    void *temp_r3_1174;
    void *temp_r3_1184;
    void *temp_r3_1650;
    void *temp_r3_1668;
    void *temp_r3_2009;
    void *temp_r3_2028;
    void *temp_r3_2360;
    void *temp_r3_2387;

    temp_f1_889 = M2C_FIELD(this, f32 *, 0x180);
    M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
    if (temp_f1_889 == 0.0f) {
        M2C_FIELD(this, f32 *, 0x180) = (f32) (temp_f1_889 + gUpdateTimeDelta);
        if (((u8) M2C_FIELD(M2C_FIELD(M2C_FIELD(M2C_FIELD(gb.unk0->__vptr, void *(**)(HeroInterface *), 0x3C)(gb.unk0), void **, 4), void **, 0xB4), u8 *, 0x16) != 0) && ((u8) M2C_FIELD(M2C_FIELD(M2C_FIELD(M2C_FIELD(gb.unk0->__vptr, void *(**)(HeroInterface *), 0x3C)(gb.unk0), void **, 4), void **, 0xB4), u8 *, 0x17) != 0) && (((temp_f1_920 = M2C_FIELD(this, f32 *, 0x180), M2C_ERROR(/* unknown instruction: cror eq, gt, eq */), ((temp_f1_920 == 0.0f) != 0)) && (M2C_ERROR(/* unknown instruction: cror eq, lt, eq */), ((temp_f1_920 == 1.0f) != 0))) || ((M2C_ERROR(/* unknown instruction: cror eq, gt, eq */), ((temp_f1_920 == 5.0f) != 0)) && (M2C_ERROR(/* unknown instruction: cror eq, lt, eq */), ((temp_f1_920 == 7.0f) != 0))))) {
            ((KDInput *) (M2C_FIELD(gb.unk0->__vptr, KDInput *(**)(HeroInterface *), 0x40)(gb.unk0)))->RumblePlay(0.0f, 0.5f, 0.15f, 0, 4.0f, 0U);
        } else {
            temp_f2_955 = M2C_FIELD(this, f32 *, 0x180);
            if ((temp_f2_955 > 1.0f) && (M2C_ERROR(/* unknown instruction: cror eq, lt, eq */), ((temp_f2_955 == 4.4f) != 0))) {
                if ((temp_f2_955 > 1.0f) && (M2C_ERROR(/* unknown instruction: cror eq, lt, eq */), ((temp_f2_955 == 2.1f) != 0))) {
                    M2C_FIELD(this, f32 *, 0x184) = (f32) ((0.909f * (temp_f2_955 - 1.0f) * 0.125f) + 0.0f);
                } else if ((temp_f2_955 > 2.1f) && (M2C_ERROR(/* unknown instruction: cror eq, lt, eq */), ((temp_f2_955 == 2.9f) != 0))) {
                    M2C_FIELD(this, f32 *, 0x184) = (f32) ((1.25f * (temp_f2_955 - 2.1f) * 0.125f) + 0.125f);
                } else if ((temp_f2_955 > 2.9f) && (M2C_ERROR(/* unknown instruction: cror eq, lt, eq */), ((temp_f2_955 == 3.7f) != 0))) {
                    M2C_FIELD(this, f32 *, 0x184) = (f32) ((1.25f * (temp_f2_955 - 2.9f) * 0.06999999f) + 0.25f);
                } else if (temp_f2_955 > 3.7f) {
                    M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
                    if (temp_f2_955 == 4.4f) {
                        M2C_FIELD(this, f32 *, 0x184) = (f32) ((1.429f * (temp_f2_955 - 3.7f) * 0.18f) + 0.32f);
                    }
                }
                temp_f22_1025 = M2C_FIELD(this, f32 *, 0x184);
                ((KDInput *) (M2C_FIELD(gb.unk0->__vptr, KDInput *(**)(HeroInterface *), 0x40)(gb.unk0)))->RumblePlay(0.7f * temp_f22_1025, temp_f22_1025, 0.033f, 0, 4.0f, 0U);
            } else if (temp_f2_955 > 7.0f) {
                M2C_FIELD(this, f32 *, 0x180) = -1.0f;
            }
        }
    }
    this->unkAC -= gUpdateTimeDelta;
    temp_r0_1052 = this->unk90;
    switch (temp_r0_1052) {                         /* switch 1; irregular */
    case 1:                                         /* switch 1 */
        var_f1_1067 = this->unkAC;
        if (var_f1_1067 < 1.0f) {

        } else {
            var_f1_1067 = 1.0f;
        }
        if (var_f1_1067 > 0.0f) {

        } else {
            var_f1_1067 = 0.0f;
        }
        if ((void *) M2C_FIELD(&gb, void **, 0x3B8) != NULL) {
            unksp84C = 0;
            temp_f1_1094 = M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), f32 (**)(), 0x54)();
            unksp848 = 0x458;
            unksp850 = temp_f1_1094 + (0.017453292f * (30.0f * (1.0f - var_f1_1067)));
            M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, M2C_UNK *, f32), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &unksp848, 0.017453292f);
        }
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if (this->unkAC == 0.0f) {
            this->unk90 = 2;
            if ((u8) M2C_FIELD(this, u8 *, 0x18C) != 0) {
                this->unkAC = 3.0f;
            } else {
                this->unkAC = 0.8f;
            }
            unksp188 = 6.0f;
            unksp18C = 0.25f;
            unksp190 = 6.0f;
            M2C_FIELD(this, f64 *, 0x98) = unksp188;
            M2C_FIELD(this, f64 *, 0xA0) = unksp190;
            unksp7F8 = unksp188;
            unksp800 = unksp190;
            KDSound_Play3d(GS_SpyroFuryAttackLightning1, (MKVector3 *) &this->unkB0, 0U, -1, 0.0f, 0U);
            temp_r4_1145 = this->unkC4;
            if (temp_r4_1145 != NULL) {
                gb.unk80->EnableLight(temp_r4_1145, 1U);
                MKVector(0.0f, 300.0f, 0.0f);
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $r30, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                temp_f0_1167 = this->unkB8 + unksp7E0;
                temp_r3_1168 = this->unkC4;
                unksp7E8 = unksp178;
                unksp180 = temp_f0_1167;
                temp_r3_1168->unk10 = unksp178;
                temp_r3_1168->unk18 = (f64) temp_f0_1167;
                temp_r3_1174 = temp_r3_1168->unk3C;
                unksp7F0 = (f64) temp_f0_1167;
                if (temp_r3_1174 != NULL) {
                    M2C_FIELD(temp_r3_1174, f64 *, 0x10) = unksp178;
                    M2C_FIELD(temp_r3_1174, f64 *, 0x18) = (f64) temp_f0_1167;
                }
                temp_r3_1181 = this->unkC4;
                temp_r3_1181->unk38 = 1000.0f;
                temp_r3_1184 = temp_r3_1181->unk3C;
                if (temp_r3_1184 != NULL) {
                    M2C_FIELD(temp_r3_1184, f32 *, 0x20) = 1000.0f;
                    M2C_FIELD(temp_r3_1184, f32 *, 0x24) = 1000000.0f;
                    M2C_FIELD(temp_r3_1184, f32 *, 0x28) = 0.001f;
                    M2C_FIELD(temp_r3_1184, f32 *, 0x2C) = (f32) (1.0f / M2C_FIELD(temp_r3_1184, f32 *, 0x24));
                }
            }
            if ((void *) M2C_FIELD(&gb, void **, 0x3B8) != NULL) {
                unksp8DC = 0;
                temp_f22_1206 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                temp_f23_1211 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                MKVector(MKRand_Float(&gViewSeed, -1.0f, 1.0f), temp_f23_1211, temp_f22_1206);
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f27 */);
                temp_f0_1230 = unksp7C0 * 10.0f;
                unksp8D8 = 0x417;
                unksp8E0 = unksp168;
                unksp170 = temp_f0_1230;
                unksp8F0 = 1;
                unksp8E8 = (f64) temp_f0_1230;
                unksp7C8 = unksp168;
                unksp7D0 = (f64) temp_f0_1230;
                M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, M2C_UNK *, f64), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &unksp8D8, unksp168);
            }
            gb.unk2CC.Disable(M2C_BITWISE(s32, this->unk180));
            this->unk180 = nanf;
            if ((u8) M2C_FIELD(this, u8 *, 0x18C) != 0) {
                gb.GetSpyro();
                this->unk188 = ((Spyro *) (M2C_ERROR(/* Read from unset register $r3 */)))->SetFuryAnimSpeed(0.9f);
            }
        }
    default:                                        /* switch 1 */
block_172:
        var_r28_2664 = 0;
        var_r31_2666 = 0;
        do {
            temp_r29_2673 = this + var_r31_2666;
            M2C_FIELD(temp_r29_2673, f32 *, 0xD4) = (f32) ((gUpdateTimeDelta * (3.1415927f * MKRand_Float(&gViewSeed, 0.1f, 1.0f))) + M2C_FIELD(temp_r29_2673, f32 *, 0xD4));
            var_r28_2664 += 1;
            var_r31_2666 += 0x10;
            M2C_FIELD(temp_r29_2673, f32 *, 0xD0) = (f32) ((gUpdateTimeDelta * (2.0f * (3.1415927f * MKRand_Float(&gViewSeed, 0.1f, 1.0f)))) + M2C_FIELD(temp_r29_2673, f32 *, 0xD0));
        } while (var_r28_2664 < 3);
        temp_r3_2692 = this->unk90;
        if (temp_r3_2692 != 4) {
            if (((u8) M2C_FIELD(this, u8 *, 0x18C) != 0) && (temp_r3_2692 != 3)) {
                M2C_FIELD(this, f32 *, 0x194) = (f32) ((0.6f * gUpdateTimeDelta) + M2C_FIELD(this, f32 *, 0x194));
            } else {
                M2C_FIELD(this, f32 *, 0x194) = (f32) (M2C_FIELD(this, f32 *, 0x194) + gUpdateTimeDelta);
            }
            this->unkC0->SetScale(M2C_FIELD(this, f32 *, 0x194));
        }
        break;
    case 2:                                         /* switch 1 */
        if (this->unk98.unk0 == 0.1f) {
            M2C_FIELD(this, f64 *, 0x160) = (f64) this->unk170;
            M2C_FIELD(this, f64 *, 0x168) = (f64) this->unk170;
            if ((u8) M2C_FIELD(this, u8 *, 0x18C) != 0) {
                var_f22_1274 = this->unkAC;
                if (var_f22_1274 < 3.0f) {

                } else {
                    var_f22_1274 = 3.0f;
                }
                if (var_f22_1274 > 0.0f) {

                } else {
                    var_f22_1274 = 0.0f;
                }
                MKVector(1000.0f, 1000.0f, 1000.0f);
                MKVector(-12.0f, 40.0f, -12.0f);
                unksp768.operator*(gUpdateTimeDelta);
                unksp778.operator*((2.0f * (1.0f - (var_f22_1274 / 3.0f))) + 1.0f);
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $r30, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                unksp788 = unksp68;
                unksp70 = this->unk98.unk8 + unksp780;
                unksp790 = unksp70;
                MKVector(0.1f, 0.2f, 0.1f);
                Min(*((MKVector3 *) &unksp158), *((MKVector3 *) &unksp788));
                Max(*((MKVector3 *) &unksp7A8), *((MKVector3 *) &unksp158));
                M2C_FIELD(this, f64 *, 0x98) = unksp7A8;
                M2C_FIELD(this, f64 *, 0xA0) = unksp7B0;
            } else {
                MKVector(1000.0f, 1000.0f, 1000.0f);
                MKVector(-12.0f, 40.0f, -12.0f);
                unksp708.operator*(gUpdateTimeDelta);
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $r30, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                unksp718 = unksp58;
                unksp60 = this->unk98.unk8 + unksp710;
                unksp720 = unksp60;
                MKVector(0.1f, 0.2f, 0.1f);
                Min(*((MKVector3 *) &unksp148), *((MKVector3 *) &unksp718));
                Max(*((MKVector3 *) &unksp738), *((MKVector3 *) &unksp148));
                M2C_FIELD(this, f64 *, 0x98) = unksp738;
                M2C_FIELD(this, f64 *, 0xA0) = unksp740;
            }
            if ((u8) M2C_FIELD(this, u8 *, 0x18C) != 0) {
                M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
                if (this->unk98.unk4 == 20.0f) {
                    unksp138 = 6.0f;
                    unksp13C = 0.25f;
                    unksp140 = 6.0f;
                    M2C_FIELD(this, f64 *, 0x98) = unksp138;
                    M2C_FIELD(this, f64 *, 0xA0) = unksp140;
                    unksp6D8 = unksp138;
                    unksp6E0 = unksp140;
                    if ((void *) M2C_FIELD(&gb, void **, 0x3B8) != NULL) {
                        unksp8BC = 0;
                        temp_f22_1419 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                        temp_f23_1424 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                        MKVector(MKRand_Float(&gViewSeed, -1.0f, 1.0f), temp_f23_1424, temp_f22_1419);
                        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
                        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f27 */);
                        temp_f0_1443 = unksp6C0 * 50.0f;
                        unksp8B8 = 0x417;
                        unksp8C0 = unksp128;
                        unksp130 = temp_f0_1443;
                        unksp8D0 = 1;
                        unksp8C8 = (f64) temp_f0_1443;
                        unksp6C8 = unksp128;
                        unksp6D0 = (f64) temp_f0_1443;
                        M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, M2C_UNK *, f64), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &unksp8B8, unksp128);
                    }
                }
            }
        } else {
            M2C_FIELD(this, f64 *, 0x160) = (f64) M2C_FIELD(this, f64 *, 0xB0);
            M2C_FIELD(this, f64 *, 0x168) = (f64) M2C_FIELD(this, f32 *, 0xB8);
            if ((u8) M2C_FIELD(this, u8 *, 0x18C) != 0) {
                var_f22_1466 = this->unkAC;
                if (var_f22_1466 < 3.0f) {

                } else {
                    var_f22_1466 = 3.0f;
                }
                if (var_f22_1466 > 0.0f) {

                } else {
                    var_f22_1466 = 0.0f;
                }
                MKVector(1000.0f, 1000.0f, 1000.0f);
                MKVector(-12.0f, 3.0f, -12.0f);
                unksp668.operator*((2.0f * (1.0f - (var_f22_1466 / 3.0f))) + 1.0f);
                unksp678.operator*(gUpdateTimeDelta);
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $r30, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                unksp688 = unksp48;
                unksp50 = this->unk98.unk8 + unksp680;
                unksp690 = unksp50;
                MKVector(0.1f, 0.2f, 0.1f);
                Min(*((MKVector3 *) &unksp118), *((MKVector3 *) &unksp688));
                Max(*((MKVector3 *) &unksp6A8), *((MKVector3 *) &unksp118));
                M2C_FIELD(this, f64 *, 0x98) = unksp6A8;
                M2C_FIELD(this, f64 *, 0xA0) = unksp6B0;
            } else {
                MKVector(1000.0f, 1000.0f, 1000.0f);
                MKVector(-12.0f, 3.0f, -12.0f);
                unksp608.operator*(gUpdateTimeDelta);
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $r30, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                unksp618 = unksp38;
                unksp40 = this->unk98.unk8 + unksp610;
                unksp620 = unksp40;
                MKVector(0.1f, 0.2f, 0.1f);
                Min(*((MKVector3 *) &unksp108), *((MKVector3 *) &unksp618));
                Max(*((MKVector3 *) &unksp638), *((MKVector3 *) &unksp108));
                M2C_FIELD(this, f64 *, 0x98) = unksp638;
                M2C_FIELD(this, f64 *, 0xA0) = unksp640;
            }
        }
        if ((u8) M2C_FIELD(this, u8 *, 0x18C) != 0) {
            var_f2_1584 = this->unkAC;
            if (var_f2_1584 < 3.0f) {

            } else {
                var_f2_1584 = 3.0f;
            }
            if (var_f2_1584 > 0.0f) {

            } else {
                var_f2_1584 = 0.0f;
            }
            var_f22_1602 = 1.0f - (var_f2_1584 / 3.0f);
        } else {
            var_f2_1605 = this->unkAC;
            if (var_f2_1605 < 0.8f) {

            } else {
                var_f2_1605 = 0.8f;
            }
            if (var_f2_1605 > 0.0f) {

            } else {
                var_f2_1605 = 0.0f;
            }
            var_f22_1602 = 1.0f - (var_f2_1605 / 0.8f);
        }
        if ((ManagedLight *) this->unkC4 != NULL) {
            MKVector(0.0f, (400.0f * var_f22_1602) + 25.0f, 0.0f);
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $r30, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            temp_f0_1643 = this->unkB8 + unksp5D0;
            temp_r3_1644 = this->unkC4;
            unksp5D8 = unkspF8;
            unksp100 = temp_f0_1643;
            temp_r3_1644->unk10 = unkspF8;
            temp_r3_1644->unk18 = (f64) temp_f0_1643;
            temp_r3_1650 = temp_r3_1644->unk3C;
            unksp5E0 = (f64) temp_f0_1643;
            if (temp_r3_1650 != NULL) {
                M2C_FIELD(temp_r3_1650, f64 *, 0x10) = unkspF8;
                M2C_FIELD(temp_r3_1650, f64 *, 0x18) = (f64) temp_f0_1643;
            }
            temp_r3_1664 = this->unkC4;
            temp_f1_1666 = (1.0f + var_f22_1602) * (1000.0f * MKRand_Float(&gViewSeed, 1.0f, 1.2f));
            temp_r3_1664->unk38 = temp_f1_1666;
            temp_r3_1668 = temp_r3_1664->unk3C;
            if (temp_r3_1668 != NULL) {
                M2C_FIELD(temp_r3_1668, f32 *, 0x20) = temp_f1_1666;
                M2C_FIELD(temp_r3_1668, f32 *, 0x24) = (f32) (temp_f1_1666 * temp_f1_1666);
                M2C_FIELD(temp_r3_1668, f32 *, 0x28) = (f32) (1.0f / temp_f1_1666);
                M2C_FIELD(temp_r3_1668, f32 *, 0x2C) = (f32) (1.0f / M2C_FIELD(temp_r3_1668, f32 *, 0x24));
            }
        }
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if (this->unkAC == 0.0f) {
            this->unk90 = 3;
            this->unkAC = 1.2f;
            if ((u8) M2C_FIELD(this, u8 *, 0x18C) != 0) {
                unkspE8 = 0.1f;
                unkspEC = 1000.0f;
                unkspF0 = 0.1f;
                M2C_FIELD(this, f64 *, 0x98) = unkspE8;
                unksp5B8 = unkspE8;
                unksp5C0 = unkspF0;
                M2C_FIELD(this, f64 *, 0xA0) = unkspF0;
            }
        }
        goto block_172;
    case 3:                                         /* switch 1 */
        var_f2_1705 = this->unkAC;
        if (var_f2_1705 < 1.2f) {

        } else {
            var_f2_1705 = 1.2f;
        }
        if (var_f2_1705 > 0.0f) {

        } else {
            var_f2_1705 = 0.0f;
        }
        temp_f26_1727 = 1.0f - (var_f2_1705 / 1.2f);
        MKVector(1000.0f, 1000.0f, 1000.0f);
        MKVector(-0.25f, 0.0f, -0.25f);
        unksp578.operator*(gUpdateTimeDelta);
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $r30, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        unksp588 = unksp28;
        unksp30 = this->unk98.unk8 + unksp580;
        unksp590 = unksp30;
        MKVector(0.0f, 0.2f, 0.0f);
        Min(*((MKVector3 *) &unkspD8), *((MKVector3 *) &unksp588));
        Max(*((MKVector3 *) &unksp5A8), *((MKVector3 *) &unkspD8));
        M2C_FIELD(this, f64 *, 0x98) = unksp5A8;
        M2C_FIELD(this, f64 *, 0xA0) = unksp5B0;
        unksp2E0 = -1.0f;
        temp_f29_1775 = M2C_FIELD(this, f32 *, 0x194);
        unksp2D0 = 1.0f;
        unksp2D8 = -1.0f;
        unksp2DC = 0.0f;
        unksp2C8 = 1.0f;
        unksp2CC = 0.0f;
        unksp4F8 = 1.58735232e-314;
        unksp500 = unksp2E0;
        unksp4E8 = 5.263544247e-315;
        unksp4F0 = unksp2D0;
        KDRand_Vector(*((MKVector3 *) &unksp508), *((MKVector3 *) &unksp4F8));
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f28 */);
        unksp518 = unksp2B8;
        unksp2C0 = unksp510 * 200.0f;
        unksp520 = unksp2C0;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
        temp_f3_1809 = (f32) unksp2C0 * temp_f29_1775;
        unksp300 = 0.0f;
        unksp2B0 = temp_f3_1809;
        unksp2F8 = 0.0f;
        unksp2FC = 850.0f;
        unksp528 = unksp2A8;
        unksp538 = unksp2F8;
        unksp530 = (f64) temp_f3_1809;
        unksp540 = unksp300;
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $r30, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        unksp548 = unksp2E8;
        unksp2F0 = this->unkB8 + unksp540;
        unksp550 = unksp2F0;
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        unksp290 = -1.0f;
        unksp280 = 1.0f;
        unksp288 = -1.0f;
        temp_f5_1852 = unksp550 + unksp530;
        unksp28C = -1.0f;
        unksp2A0 = temp_f5_1852;
        unksp278 = 1.0f;
        unksp27C = -0.5f;
        unksp838 = unksp298;
        unksp840 = (f64) temp_f5_1852;
        unksp4C8 = 1.58735232e-314;
        unksp4D0 = unksp290;
        unksp4B8 = unksp278;
        unksp4C0 = unksp280;
        KDRand_Vector(*((MKVector3 *) &unksp4D8), *((MKVector3 *) &unksp4C8));
        var_f4_1875 = (unksp4E0 * unksp4E0) + ((unksp4D8 * unksp4D8) + (unksp4DC * unksp4DC));
        if (var_f4_1875 > 1e-12f) {
            if (var_f4_1875 > 0.0f) {
                temp_f1_1881 = __frsqrte(var_f4_1875);
                temp_f1_1887 = 0.5 * temp_f1_1881 * -(((f64) var_f4_1875 * (temp_f1_1881 * temp_f1_1881)) - 3.0);
                temp_f1_1891 = 0.5 * temp_f1_1887 * -(((f64) var_f4_1875 * (temp_f1_1887 * temp_f1_1887)) - 3.0);
                var_f4_1875 = (f32) ((f64) var_f4_1875 * (0.5 * temp_f1_1891 * -(((f64) var_f4_1875 * (temp_f1_1891 * temp_f1_1891)) - 3.0)));
            } else if (var_f4_1875 < M2C_BITWISE(f32, 0.0)) {
                var_f4_1875 = __float_nan;
            } else {
                unksp8 = var_f4_1875;
                temp_r3_1910 = unksp8 & 0x7F800000;
                switch (temp_r3_1910) {             /* switch 2; irregular */
                case 0x7F800000:                    /* switch 2 */
                    if (unksp8 & 0x7FFFFF) {
                        var_r0_1920 = 1;
                    } else {
                        var_r0_1920 = 2;
                    }
                    break;
                case 0x0:                           /* switch 2 */
                    if (unksp8 & 0x7FFFFF) {
                        var_r0_1920 = 5;
                    } else {
                        var_r0_1920 = 3;
                    }
                    break;
                default:                            /* switch 2 */
                    var_r0_1920 = 4;
                    break;
                }
                if (var_r0_1920 == 1) {
                    var_f4_1875 = __float_nan;
                }
            }
            var_f3_1942 = 1.0f / var_f4_1875;
        } else {
            var_f3_1942 = 0.0f;
        }
        unksp270 = unksp4E0 * var_f3_1942;
        unksp268 = unksp4D8 * var_f3_1942;
        unksp26C = unksp4DC * var_f3_1942;
        unksp258 = 1.0f;
        unksp25C = 1.0f;
        unksp260 = 0.2f;
        unksp264 = 1.0f;
        unksp828 = unksp268;
        unksp830 = unksp270;
        unksp4A8 = unksp258;
        unksp4B0 = unksp260;
        unkspC = (2.5f * temp_f26_1727) + 0.1f;
        gb.unk94->Trigger(*((MKVector3 *) &unksp838), *((MKVector3 *) &unksp828), unkspC, lit_828, (MKVector4) &unksp4A8);
        unksp250 = 0.0f;
        unksp248 = 0.0f;
        unksp24C = -980.0f;
        unksp4A0 = unksp250;
        unksp498 = unksp248;
        gb.unk6C->Emit(*((MKVector3 *) &unksp838), *((MKVector3 *) &unksp498), 2.0f, 1U, 0U, NULL);
        temp_r3_2002 = this->unkC4;
        if (temp_r3_2002 != NULL) {
            temp_r3_2002->unk10 = unksp838;
            temp_r3_2002->unk18 = unksp840;
            temp_r3_2009 = temp_r3_2002->unk3C;
            if (temp_r3_2009 != NULL) {
                M2C_FIELD(temp_r3_2009, f64 *, 0x10) = unksp838;
                M2C_FIELD(temp_r3_2009, f64 *, 0x18) = unksp840;
            }
            temp_r3_2024 = this->unkC4;
            temp_f1_2026 = (1.0f + temp_f26_1727) * (1000.0f * MKRand_Float(&gViewSeed, 1.0f, 2.0f));
            temp_r3_2024->unk38 = temp_f1_2026;
            temp_r3_2028 = temp_r3_2024->unk3C;
            if (temp_r3_2028 != NULL) {
                M2C_FIELD(temp_r3_2028, f32 *, 0x20) = temp_f1_2026;
                M2C_FIELD(temp_r3_2028, f32 *, 0x24) = (f32) (temp_f1_2026 * temp_f1_2026);
                M2C_FIELD(temp_r3_2028, f32 *, 0x28) = (f32) (1.0f / temp_f1_2026);
                M2C_FIELD(temp_r3_2028, f32 *, 0x2C) = (f32) (1.0f / M2C_FIELD(temp_r3_2028, f32 *, 0x24));
            }
        }
        if ((void *) M2C_FIELD(&gb, void **, 0x3B8) != NULL) {
            unksp89C = 0;
            temp_f22_2051 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
            temp_f23_2056 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
            MKVector(MKRand_Float(&gViewSeed, -1.0f, 1.0f), temp_f23_2056, temp_f22_2051);
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f27 */);
            temp_f0_2075 = unksp480 * 50.0f;
            unksp898 = 0x417;
            unksp8A0 = unkspC8;
            unkspD0 = temp_f0_2075;
            unksp8B0 = 1;
            unksp8A8 = (f64) temp_f0_2075;
            unksp488 = unkspC8;
            unksp490 = (f64) temp_f0_2075;
            M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, M2C_UNK *, f64), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &unksp898, unkspC8);
        }
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if (this->unkAC == 0.0f) {
            this->unk90 = 4;
            unkspC0 = 1.0f;
            unkspB8 = 1.0f;
            unkspBC = 6.0f;
            this->unkAC = 1.0f;
            M2C_FIELD(this, f64 *, 0x98) = unkspB8;
            M2C_FIELD(this, f64 *, 0xA0) = unkspC0;
            unksp468 = unkspB8;
            unksp470 = unkspC0;
            this->unkC0->Explode();
            this->unkC0->Stop();
            this->unk108.unk50 = 0;
            temp_f2_2119 = M2C_FIELD(this, f64 *, 0xB0);
            M2C_FIELD(this, f64 *, 0x118) = temp_f2_2119;
            M2C_FIELD(this, f64 *, 0x120) = (f64) M2C_FIELD(this, f32 *, 0xB8);
            M2C_FIELD(*gMK, M2C_UNK (**)(void **, BreathHitMessage *, M2C_UNK, M2C_UNK, f32 *, M2C_UNK, f32, f64), 0x94)(gMK, &this->unk108, 0, 0, &this->unkB0, 1, 3000.0f, temp_f2_2119);
            unksp220 = 0.0f;
            unksp240 = 0.0f;
            unksp208 = 1.0f;
            unksp20C = 1.0f;
            unksp210 = 0.2f;
            unksp214 = 1.0f;
            unksp218 = 0.0f;
            unksp21C = -1.0f;
            unksp238 = 0.0f;
            unksp23C = 500.0f;
            unksp4A8 = unksp208;
            unksp4B0 = 5.164075695e-315;
            unksp438 = unksp218;
            unksp440 = unksp220;
            unksp448 = unksp238;
            unksp450 = unksp240;
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $r30, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            unksp458 = unksp228;
            unksp230 = this->unkB8 + unksp450;
            unksp460 = unksp230;
            gb.unk94->Trigger(*((MKVector3 *) &unksp458), *((MKVector3 *) &unksp438), 4.0f, lit_837, (MKVector4) &unksp4A8);
            unksp1F8 = 1.0f;
            unksp1FC = 1.0f;
            unksp200 = 1.0f;
            unksp204 = 1.0f;
            unksp428 = unksp1F8;
            unksp430 = unksp200;
            gb.unkB8.EnableScreenFlash(*((MKVector4 *) &unksp428), 3.0f * gUpdateTimeDelta);
            KDSound_Play3d(GS_SpyroFuryAttackLightning2, (MKVector3 *) &this->unkB0, 0U, -1, 0.0f, 0U);
            KDSound_Play3d(GS_Rumble1, (MKVector3 *) &this->unkB0, 0U, -1, 0.0f, 0U);
            ((KDInput *) (M2C_FIELD(gb.unk0->__vptr, KDInput *(**)(HeroInterface *), 0x40)(gb.unk0)))->RumblePlay(0.99f, 0.99f, 0.65f, 0, 4.0f, 0U);
            if ((void *) M2C_FIELD(&gb, void **, 0x3B8) != NULL) {
                unksp87C = 0;
                temp_f22_2231 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                temp_f23_2236 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                MKVector(MKRand_Float(&gViewSeed, -1.0f, 1.0f), temp_f23_2236, temp_f22_2231);
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
                temp_f0_2255 = unksp410 * 600.0f;
                unksp878 = 0x417;
                unksp880 = unkspA8;
                unkspB0 = temp_f0_2255;
                unksp890 = 1;
                unksp888 = (f64) temp_f0_2255;
                unksp418 = unkspA8;
                unksp420 = (f64) temp_f0_2255;
                M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, M2C_UNK *, f64), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &unksp878, unkspA8);
            }
            this->unk180 = M2C_BITWISE(f32, gb.unk2CC.Enable(0.5f, 0.0f, 0.0f, -1.0f));
            M2C_FIELD(this, f64 *, 0x160) = (f64) M2C_FIELD(this, f64 *, 0xB0);
            M2C_FIELD(this, f64 *, 0x168) = (f64) M2C_FIELD(this, f32 *, 0xB8);
            gb.GetSpyro();
            ((Spyro *) (M2C_ERROR(/* Read from unset register $r3 */)))->SetRage(1, 15.0f);
        }
        goto block_172;
    case 4:                                         /* switch 1 */
        MKVector(1000.0f, 1000.0f, 1000.0f);
        MKVector(18.0f, -10.0f, 18.0f);
        unksp3C8.operator*(gUpdateTimeDelta);
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $r30, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        unksp3D8 = unksp18;
        unksp20 = this->unk98.unk8 + unksp3D0;
        unksp3E0 = unksp20;
        MKVector(0.0f, 0.0f, 0.0f);
        Min(*((MKVector3 *) &unksp98), *((MKVector3 *) &unksp3D8));
        Max(*((MKVector3 *) &unksp3F8), *((MKVector3 *) &unksp98));
        M2C_FIELD(this, f64 *, 0x98) = unksp3F8;
        M2C_FIELD(this, f64 *, 0xA0) = unksp400;
        if ((ManagedLight *) this->unkC4 != NULL) {
            MKVector(0.0f, 2000.0f * gUpdateTimeDelta, 0.0f);
            temp_r4_2345 = this->unkC4;
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r3, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            temp_f0_2354 = (f32) M2C_FIELD(temp_r4_2345, f64 *, 0x18) + unksp390;
            temp_r4_2345->unk10 = unksp88;
            unksp90 = temp_f0_2354;
            unksp398 = unksp88;
            temp_r4_2345->unk18 = (f64) temp_f0_2354;
            temp_r3_2360 = temp_r4_2345->unk3C;
            unksp3A0 = (f64) temp_f0_2354;
            if (temp_r3_2360 != NULL) {
                M2C_FIELD(temp_r3_2360, f64 *, 0x10) = unksp88;
                M2C_FIELD(temp_r3_2360, f64 *, 0x18) = (f64) temp_f0_2354;
            }
            temp_r3_2367 = this->unkC4;
            var_f0_2372 = -((500.0f * gUpdateTimeDelta) - temp_r3_2367->unk38);
            if (var_f0_2372 < 200000.0f) {

            } else {
                var_f0_2372 = 200000.0f;
            }
            if (var_f0_2372 > 0.0f) {

            } else {
                var_f0_2372 = 0.0f;
            }
            temp_r3_2367->unk38 = var_f0_2372;
            temp_r3_2387 = temp_r3_2367->unk3C;
            if (temp_r3_2387 != NULL) {
                M2C_FIELD(temp_r3_2387, f32 *, 0x20) = var_f0_2372;
                M2C_FIELD(temp_r3_2387, f32 *, 0x24) = (f32) (var_f0_2372 * var_f0_2372);
                M2C_FIELD(temp_r3_2387, f32 *, 0x28) = (f32) (1.0f / var_f0_2372);
                M2C_FIELD(temp_r3_2387, f32 *, 0x2C) = (f32) (1.0f / M2C_FIELD(temp_r3_2387, f32 *, 0x24));
            }
        }
        temp_r29_2404 = MKRand_Int(&gViewSeed, 0xF, 0x1E);
        var_r28_2411 = 0;
        temp_f25_2418 = 6.2831855f / (f32) (temp_r29_2404 - 1);
loop_151:
        if (var_r28_2411 < temp_r29_2404) {
            temp_f28_2423 = this->unk98.unk0;
            temp_f21_2430 = (f32) var_r28_2411 * temp_f25_2418;
            temp_f23_2432 = MKRand_Float(&gViewSeed, 0.8f, 1.0f);
            temp_f22_2439 = -_table_sinf(1.5707964f + temp_f21_2430) * temp_f23_2432;
            temp_f23_2441 = MKRand_Float(&gViewSeed, 0.8f, 1.0f);
            temp_f1_2444 = _table_sinf(temp_f21_2430) * temp_f23_2441;
            unksp1F0 = temp_f22_2439;
            unksp1E8 = temp_f1_2444;
            unksp1EC = 0.0f;
            unksp360 = unksp1F0;
            unksp358 = (f64) temp_f1_2444;
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f27 */);
            unksp368 = unksp1D8;
            unksp1E0 = unksp360 * 200.0f;
            unksp370 = unksp1E0;
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f28 */);
            unksp378 = unksp1C8;
            unksp1D0 = unksp370 * temp_f28_2423;
            unksp380 = unksp1D0;
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $r30, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            unksp1B0 = 0.0f;
            unksp198 = 1.0f;
            unksp1C0 = this->unkB8 + (f32) unksp1D0;
            unksp19C = 1.0f;
            unksp1A0 = 1.0f;
            unksp1A4 = 1.0f;
            unksp1A8 = 0.0f;
            unksp1AC = 0.0f;
            unksp818 = unksp1B8;
            unksp820 = unksp1C0;
            unksp338 = unksp198;
            unksp340 = unksp1A0;
            unksp348 = unksp1A8;
            unksp350 = unksp1B0;
            this->unk100->Emit(*((MKVector3 *) &unksp818), *((MKVector3 *) &unksp348), 30.0f, (MKVector4) &unksp338);
            var_r28_2411 += 1;
            goto loop_151;
        }
        var_f0_2511 = this->unkAC;
        if (var_f0_2511 < 1.0f) {

        } else {
            var_f0_2511 = 1.0f;
        }
        if (var_f0_2511 > 0.0f) {
            var_f26_2522 = var_f0_2511;
        } else {
            var_f26_2522 = 0.0f;
        }
        if ((void *) M2C_FIELD(&gb, void **, 0x3B8) != NULL) {
            unksp85C = 0;
            temp_f22_2538 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
            temp_f23_2543 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
            MKVector(MKRand_Float(&gViewSeed, -1.0f, 1.0f), temp_f23_2543, temp_f22_2538);
            unksp318.operator*(200.0f);
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f26 */);
            temp_f0_2565 = unksp320 * var_f26_2522;
            unksp858 = 0x417;
            unksp860 = unksp78;
            unksp80 = temp_f0_2565;
            unksp870 = 1;
            unksp868 = (f64) temp_f0_2565;
            unksp328 = unksp78;
            unksp330 = (f64) temp_f0_2565;
            M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, M2C_UNK *, f64), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &unksp858, unksp78);
        }
        if ((void *) M2C_FIELD(&gb, void **, 0x3B8) != NULL) {
            M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
            if (var_f26_2522 == 0.5f) {
                unksp80C = 0;
                temp_f1_2592 = M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), f32 (**)(), 0x54)();
                unksp808 = 0x458;
                unksp810 = temp_f1_2592 + (0.017453292f * (30.0f * (var_f26_2522 / 0.5f)));
                M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, M2C_UNK *, f32, f32), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &unksp808, 30.0f, 0.017453292f);
            }
        }
        if (var_f26_2522 < 0.5f) {
            gb.unk2CC.Disable(M2C_BITWISE(s32, this->unk180));
            this->unk180 = nanf;
            if ((u8) M2C_FIELD(this, u8 *, 0x18C) != 0) {
                gb.GetSpyro();
                ((Spyro *) (M2C_ERROR(/* Read from unset register $r3 */)))->SetFuryAnimSpeed(1.0f);
            }
        }
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if (this->unkAC == 0.0f) {
            this->unk90 = 0;
            temp_r4_2636 = this->unkC4;
            if (temp_r4_2636 != NULL) {
                gb.unk80->EnableLight(temp_r4_2636, 0U);
            }
            if ((void *) M2C_FIELD(&gb, void **, 0x3B8) != NULL) {
                unksp14 = 0;
                unksp10 = 0x459;
                M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(M2C_UNK *), 0x2C)(&unksp10);
            }
            gb.unk381 = 0;
        }
        goto block_172;
    }
}
#endif

#if 0 // DRAFT: pointer/array required
void FuryFXElectricity::Resolve() {
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    ManagedLight *temp_r4_2790;

    FuryFX::Resolve();
    sp20 = 0.0f;
    sp30 = 0.0f;
    sp8 = 0.5f;
    spC = 0.5f;
    sp10 = 0.0f;
    sp14 = 1.0f;
    sp18 = 0.0f;
    sp1C = 0.0f;
    sp28 = 0.0f;
    sp2C = 0.0f;
    sp38 = (f64) sp8;
    sp40 = (f64) sp10;
    sp48 = (f64) sp18;
    sp50 = (f64) sp20;
    sp58 = (f64) sp28;
    sp60 = (f64) sp30;
    this->unkC4 = gb.unk80->AllocManagedLight(*((MKVector3 *) &sp58), *((MKVector3 *) &sp48), *((MKVector4 *) &sp38), 300.0f, lit_739, lit_740);
    temp_r4_2790 = this->unkC4;
    if (temp_r4_2790 != NULL) {
        gb.unk80->EnableLight(temp_r4_2790, 0U);
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'MKResource *' to
void FuryFXElectricity::Init() {
    FuryFX::Init();
    this->unk90 = 0;
    M2C_FIELD(this, f32 *, 0x180) = -1.0f;
    M2C_FIELD(this, f32 *, 0x184) = 0.0f;
    this->unkA8 = MKMaterial_Create("fx_370");
    this->unkC8 = MKMaterial_Create("windymat");
    this->unkCC = MKMaterial_Create("windymat2");
    this->unkAC = 0.0f;
    this->unkC0 = checked_cast<LitCloudPS *, MKProp>(gMK->CreateProp("LitCloudPS"));
    this->unkC4 = NULL;
    this->unkD0 = 2.0943952f;
    this->unkE0 = 3.1415927f;
    this->unkF0 = 6.2831855f;
    this->unkD4 = 2.0943952f;
    this->unkE4 = 3.1415927f;
    this->unkF4 = 6.2831855f;
    this->unkD8 = this->unkC8;
    this->unkE8 = this->unkCC;
    this->unkF8 = this->unkC8;
    this->unk100 = checked_cast<ZapPS *, MKProp>(gMK->CreateProp("ZapPS"));
    this->unk180 = nanf;
    M2C_FIELD(this, s8 *, 0x18C) = 0;
    M2C_FIELD(this, f32 *, 0x194) = 0.0f;
}
#endif

void FuryFXElectricity_cpp::__sinit() {
    f32 temp_f0_2920;
    f64 temp_f1_2901;
    f64 temp_f1_2909;
    f64 temp_f3_2889;
    f64 temp_f4_2898;
    f64 temp_f4_2906;
    f64 temp_f8_2891;

    temp_f3_2889 = __frsqrte(2014000.0);
    temp_f8_2891 = __frsqrte(380000.0);
    temp_f4_2898 = 0.5 * temp_f3_2889 * -((2014000.0 * (temp_f3_2889 * temp_f3_2889)) - 3.0);
    temp_f1_2901 = 0.5 * temp_f8_2891 * -((380000.0 * (temp_f8_2891 * temp_f8_2891)) - 3.0);
    temp_f4_2906 = 0.5 * temp_f4_2898 * -((2014000.0 * (temp_f4_2898 * temp_f4_2898)) - 3.0);
    temp_f1_2909 = 0.5 * temp_f1_2901 * -((380000.0 * (temp_f1_2901 * temp_f1_2901)) - 3.0);
    temp_f0_2920 = (f32) (380000.0 * (0.5 * temp_f1_2909 * -((380000.0 * (temp_f1_2909 * temp_f1_2909)) - 3.0)));
    SPYRO_BOUNCE_Y_SPEED = (f32) (2014000.0 * (0.5 * temp_f4_2906 * -((2014000.0 * (temp_f4_2906 * temp_f4_2906)) - 3.0)));
    SPYRO_MIN_JUMP_Y_VELOCITY = temp_f0_2920;
}
