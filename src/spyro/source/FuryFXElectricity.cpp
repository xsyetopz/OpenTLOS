#include "spyro/source/FuryFXElectricity.h"
#include "common/Source/Animation.h"
#include "common/Source/Font.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKFont.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKMemoryCard.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKParticleSystem.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "common/Source/Texture.h"
#include "spyro/source/CameraData.h"
#include "spyro/source/DialogBox.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/FuryFX.h"
#include "spyro/source/Game.h"
#include "spyro/source/GameData.h"
#include "spyro/source/GameMessages.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/HeroInterface.h"
#include "spyro/source/InputModifier.h"
#include "spyro/source/KDCamera.h"
#include "spyro/source/KDCameraHeroData.h"
#include "spyro/source/KDCameraHeroMoveYaw.h"
#include "spyro/source/KDCameraJumpTargetOffset.h"
#include "spyro/source/KDCameraMessageStorage.h"
#include "spyro/source/KDCameraPoint.h"
#include "spyro/source/KDCameraSimpleDelta.h"
#include "spyro/source/KDCameraState.h"
#include "spyro/source/KDCollisionObject.h"
#include "spyro/source/KDInput.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/KDStateMachine.h"
#include "spyro/source/Level.h"
#include "spyro/source/LightManager.h"
#include "spyro/source/LitCloudPS.h"
#include "spyro/source/ManagedLight.h"
#include "spyro/source/NodeLookAt.h"
#include "spyro/source/Spyro.h"
#include "spyro/source/SpyroCombatState.h"
#include "spyro/source/SpyroState.h"
#include "spyro/source/SpyroTools.h"
#include "spyro/source/SpyroUtils.h"
#include "spyro/source/TargetManager.h"
#include "spyro/source/Tools.h"
#include "spyro/source/TimeDeltaModifier.h"
#include "spyro/source/WaterDripPS.h"
#include "spyro/source/ZapArcFX.h"
#include "spyro/source/ZapPS.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "common/Source/StdMath.h"
#include "common/gc/MKMaterial_GC.h"
#include "common/gc/MKPrimitive_GC.h"
#include "spyro/source/KDRandom.h"
#include "unplaced_inlines.h"
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

#if 0 // DRAFT: undefined identifier 'unk2CC'
void FuryFXElectricity::ResetFury() {
    s32 spC;
    s32 sp8;
    LitCloudPS *temp_r3_64;
    ManagedLight *temp_r4_55;
    ZapPS *temp_r3_69;

    SetDefaults();
    temp_r4_55 = this->unkC4;
    if (temp_r4_55 != NULL) {
        ((LightManager *) gb.unk80)->EnableLight(temp_r4_55, 0U);
    }
    temp_r3_64 = this->unkC0;
    temp_r3_64->Disable();
    temp_r3_69 = this->unk100;
    temp_r3_69->Disable();
    gb.unk2CC.Disable(this->unk188);
    this->unk188 = -1;
    if ((void *) M2C_FIELD(&gb, void **, 0x3B8) != NULL) {
        spC = 0;
        sp8 = 0x459;
        M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp8);
    }
    this->unk18C = 0;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'MKVector3' to 'double'
void FuryFXElectricity::DrawWindyRing(FuryFXElectricity::WindyRing *arg1) {
    M2C_UNK sp120;
    Matrix spE0;
    M2C_UNK spDC;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    f64 spC0;
    MKVector3 spB0;
    f64 spA8;
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp58;
    f64 sp50;
    f32 sp4C;
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
    f32 temp_f25_202;
    f32 temp_f25_254;
    f32 temp_f26_205;
    f32 temp_f29_135;
    f32 var_f1_137;
    f32 var_f2_144;
    f64 temp_f0_263;
    f64 temp_f0_296;
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
    sp60 = var_f2_144;
    sp64 = var_f2_144;
    sp68 = var_f2_144;
    sp6C = 1.0f;
    spD0 = (f64) sp60;
    spD8 = (f64) sp68;
    M2C_STRUCT_COPY((s32) &spDC + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
    spE0.unk30 = this->unkB0;
    var_r27_185 = 0;
    var_r31_187 = 0;
    spE0.unk34 = this->unkB4;
    spE0.unk38 = this->unkB8;
    spE0.unk3C = 1.0f;
    do {
        temp_f25_202 = (f32) var_r27_185 * 0.44879895f;
        temp_f26_205 = -_table_sinf(1.5707964f + temp_f25_202);
        spB0 = MKVector(_table_sinf(temp_f25_202), 0.0f, temp_f26_205);
        sp10 = spB0 * (f64) temp_f29_135;
        temp_r3_215 = &sp120 + var_r31_187;
        var_r27_185 += 1;
        var_r31_187 += 0x10;
        M2C_FIELD(temp_r3_215, f64 *, 0) = sp10;
        sp18 = spB0.unk8 * temp_f29_135;
        spC0 = sp10;
        spC8 = (f64) sp18;
        M2C_FIELD(temp_r3_215, f64 *, 8) = (f64) sp18;
    } while (var_r27_185 < 0xF);
    MKMaterial_SetMaterial(M2C_FIELD(arg1, MKMaterial **, 8));
    MKPrimitive(0xC, 0x10);
    MKSetMatrix(spE0);
    MKBegin(0x1E);
    var_r29_239 = 0;
    var_r31_241 = 0;
    do {
        temp_f25_254 = 4.0f * ((f32) var_r29_239 / 14.0f);
        MKSetColorV(*((MKVector4 *) &spD0));
        MKSetTexCoord1F(temp_f25_254, 2.0f);
        temp_r28_261 = &sp120 + var_r31_241;
        temp_f0_263 = M2C_FIELD(temp_r28_261, f64 *, 0) * 5.24282163e-315;
        sp50 = temp_f0_263;
        spA0 = temp_f0_263;
        sp58 = M2C_FIELD(temp_r28_261, f32 *, 8) * 0.75f;
        spA8 = (f64) sp58;
        MKSetPositionV(*((MKVector3 *) &spA0));
        sp40 = 0.0f;
        sp44 = 0.0f;
        sp48 = 0.0f;
        sp4C = 0.0f;
        sp90 = (f64) sp40;
        sp98 = (f64) sp48;
        MKSetColorV(*((MKVector4 *) &sp90));
        MKSetTexCoord1F(temp_f25_254, 0.0f);
        sp30 = 0.0f;
        sp34 = 700.0f;
        sp38 = 0.0f;
        sp70 = (f64) sp30;
        sp78 = (f64) sp38;
        temp_f0_296 = M2C_FIELD(temp_r28_261, f64 *, 0) + sp70;
        sp20 = temp_f0_296;
        sp80 = temp_f0_296;
        sp28 = M2C_FIELD(temp_r28_261, f32 *, 8) + (f32) sp78;
        sp88 = (f64) sp28;
        MKSetPositionV(*((MKVector3 *) &sp80));
        var_r29_239 += 1;
        var_r31_241 += 0x10;
    } while (var_r29_239 < 0xF);
    MKEnd();
    MKEndPrimitive();
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'MKVector3' to 'double'
void FuryFXElectricity::DrawElectricityRing() {
    M2C_UNK sp100;
    Matrix spC0;
    M2C_UNK spBC;
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
    f32 sp5C;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp4C;
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
    MKVector3 *temp_r28_468;
    f32 temp_f25_410;
    f32 temp_f25_462;
    f32 temp_f28_413;
    f64 temp_f0_493;
    s32 var_r27_400;
    s32 var_r29_447;
    s32 var_r31_402;
    s32 var_r31_449;
    void *temp_r3_423;

    sp50 = 1.0f;
    sp54 = 1.0f;
    sp58 = 1.0f;
    sp5C = 1.0f;
    spB0 = (f64) sp50;
    spB8 = (f64) sp58;
    M2C_STRUCT_COPY((s32) &spBC + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
    spC0.unk30 = this->unk164;
    spC0.unk34 = this->unk168;
    spC0.unk38 = this->unk168;
    spC0.unk3C = 1.0f;
    spC0.Scale3x3(&spC0, this->unk98);
    var_r27_400 = 0;
    var_r31_402 = 0;
    do {
        temp_f25_410 = (f32) var_r27_400 * 0.44879895f;
        temp_f28_413 = -_table_sinf(1.5707964f + temp_f25_410);
        sp90 = MKVector(_table_sinf(temp_f25_410), 0.0f, temp_f28_413);
        sp10 = sp90 * 5.5769738e-315;
        temp_r3_423 = &sp100 + var_r31_402;
        var_r27_400 += 1;
        var_r31_402 += 0x10;
        M2C_FIELD(temp_r3_423, f64 *, 0) = sp10;
        sp18 = sp90.unk8 * 200.0f;
        spA0 = sp10;
        spA8 = (f64) sp18;
        M2C_FIELD(temp_r3_423, f64 *, 8) = (f64) sp18;
    } while (var_r27_400 < 0xF);
    MKMaterial_SetMaterial(this->unkA8);
    MKPrimitive(0xC, 0x10);
    MKSetMatrix(spC0);
    MKBegin(0x1E);
    var_r29_447 = 0;
    var_r31_449 = 0;
    do {
        temp_f25_462 = 4.0f * ((f32) var_r29_447 / 15.0f);
        MKSetColorV(*((MKVector4 *) &spB0));
        MKSetTexCoord1F(temp_f25_462, 0.95f);
        temp_r28_468 = (MKVector3 *) (&sp100 + var_r31_449);
        MKSetPositionV(*temp_r28_468);
        sp40 = 0.0f;
        sp44 = 0.0f;
        sp48 = 0.0f;
        sp4C = 0.0f;
        sp80 = (f64) sp40;
        sp88 = (f64) sp48;
        MKSetColorV(*((MKVector4 *) &sp80));
        MKSetTexCoord1F(temp_f25_462, 0.05f);
        sp30 = 0.0f;
        sp34 = 200.0f;
        sp38 = 0.0f;
        sp60 = (f64) sp30;
        sp68 = (f64) sp38;
        temp_f0_493 = M2C_FIELD(temp_r28_468, f64 *, 0) + sp60;
        sp20 = temp_f0_493;
        sp70 = temp_f0_493;
        sp28 = temp_r28_468->unk8 + (f32) sp68;
        sp78 = (f64) sp28;
        MKSetPositionV(*((MKVector3 *) &sp70));
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
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f64 sp8;
    LitCloudPS *temp_r3_543;
    LitCloudPS *temp_r3_548;
    ZapPS *temp_r3_553;
    ZapPS *temp_r3_558;
    f64 temp_f0_682;
    f64 temp_f0_720;
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
    this->unk180 = 0.0f;
    this->unk184 = 0.0f;
    this->unk170 = M2C_FIELD(&arg0, f64 *, 0);
    this->unk178 = M2C_FIELD(&arg0, f64 *, 8);
    M2C_FIELD(this, f64 *, 0x160) = (f64) this->unk170;
    M2C_FIELD(this, f64 *, 0x168) = (f64) this->unk178;
    M2C_FIELD(this, f64 *, 0xB0) = (f64) M2C_FIELD(this, f64 *, 0x160);
    M2C_FIELD(this, f64 *, 0xB8) = (f64) M2C_FIELD(this, f64 *, 0x168);
    this->unk90 = 1;
    this->unkAC = 1.0f;
    this->unk188 = gb.unk2CC.Enable(0.5f, 0.0f, 0.0f, -1.0f);
    temp_r3_600 = M2C_FIELD(GameData::gameData, s32 *, 0x158) << 5;
    temp_r0_602 = *(&GameData::gameData[0x70] + (temp_r3_600 + 0x7C));
    temp_r4_604 = &GameData::gameData[0x70] + (temp_r3_600 + 0x64);
    if (temp_r0_602 == 3) {
        var_r3_608 = 0;
        if (((s32) M2C_FIELD(temp_r4_604, s32 *, 0) == 3) && ((s32) M2C_FIELD(temp_r4_604, s32 *, 4) == 3)) {
            var_r3_608 = 1;
        }
        var_r28_618 = var_r3_608 != 0;
    } else {
        var_r28_618 = *(temp_r4_604 + (temp_r0_602 * 4));
    }
    temp_r27_625 = M2C_FIELD(GameData::gameData, s32 *, 0x158);
    this->unk108.Init(gb.unk0->GetProp(), 15.0f * gb.unk37C, 3, var_r28_618, temp_r27_625, temp_r27_625, 0, -1);
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
    temp_f0_682 = M2C_FIELD(&arg0, f64 *, 0) + sp68;
    sp28 = temp_f0_682;
    sp78 = temp_f0_682;
    sp30 = arg0.unk8 + (f32) sp70;
    sp80 = (f64) sp30;
    if (MKCollision_RayCollide(arg0, *((MKVector3 *) &sp78), (MKCollisionResult *) &sp88, (MKCollisionMode) 4, 0x0C000000) != 0) {
        this->unk170 = (f64) sp88;
        this->unk178 = (f64) sp90;
    }
    sp18 = 0.0f;
    sp1C = 700.0f;
    this->unk18C = arg1;
    sp20 = 0.0f;
    this->unk194 = 0.25f;
    sp48 = (f64) sp18;
    sp50 = (f64) sp20;
    temp_f0_720 = M2C_FIELD(this, f64 *, 0xB0) + sp48;
    sp8 = temp_f0_720;
    sp58 = temp_f0_720;
    sp10 = this->unkB8 + (f32) sp50;
    sp60 = (f64) sp10;
    this->unkC0->Trigger(*((MKVector3 *) &sp58));
    this->unkC0->SetScale(this->unk194);
    gb.unk381 = 1;
    return 1;
}
#endif

void FuryFXElectricity::SetDefaults() {
    FuryFX::SetDefaults();
    this->unk180 = -1.0f;
    this->unk184 = 0.0f;
    this->unk90 = 0;
}

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
        ((LightManager *) gb.unk80)->FreeManagedLight(temp_r4_794);
    }
    M2C_FIELD(&gb, TimeDeltaModifier *, 0x2CC).Disable(this->unk188);
    this->unk188 = -1;
    FuryFX::Deinit();
}

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
                DrawWindyRing((FuryFXElectricity::WindyRing *) ((s8 *) this + (var_r31_840 + 0xD0)));
                var_r30_839 += 1;
                var_r31_840 += 0x10;
            } while (var_r30_839 < 3);
        }
    }
}

#if 0 // DRAFT: illegal explicit conversion from 'void' to 'KDInput *'
void *FuryFXElectricity::Update() {
    s8 sp8F0;
    f64 sp8E8;
    f64 sp8E0;
    s32 sp8DC;
    s32 sp8D8;
    s8 sp8D0;
    f64 sp8C8;
    f64 sp8C0;
    s32 sp8BC;
    s32 sp8B8;
    s8 sp8B0;
    f64 sp8A8;
    f64 sp8A0;
    s32 sp89C;
    s32 sp898;
    s8 sp890;
    f64 sp888;
    f64 sp880;
    s32 sp87C;
    s32 sp878;
    s8 sp870;
    f64 sp868;
    f64 sp860;
    s32 sp85C;
    s32 sp858;
    f32 sp850;
    s32 sp84C;
    s32 sp848;
    f64 sp840;
    f64 sp838;
    f64 sp830;
    f64 sp828;
    f64 sp820;
    f64 sp818;
    f32 sp810;
    s32 sp80C;
    s32 sp808;
    f64 sp800;
    f64 sp7F8;
    f64 sp7F0;
    f64 sp7E8;
    MKVector3 sp7D8;
    f64 sp7D0;
    f64 sp7C8;
    MKVector3 sp7B8;
    MKVector3 sp7A8;
    MKVector3 sp798;
    f64 sp790;
    f64 sp788;
    MKVector3 sp778;
    MKVector3 sp768;
    MKVector3 sp758;
    MKVector3 sp748;
    MKVector3 sp738;
    MKVector3 sp728;
    f64 sp720;
    f64 sp718;
    MKVector3 sp708;
    MKVector3 sp6F8;
    MKVector3 sp6E8;
    f64 sp6E0;
    f64 sp6D8;
    f64 sp6D0;
    f64 sp6C8;
    MKVector3 sp6B8;
    MKVector3 sp6A8;
    MKVector3 sp698;
    f64 sp690;
    f64 sp688;
    MKVector3 sp678;
    MKVector3 sp668;
    MKVector3 sp658;
    MKVector3 sp648;
    MKVector3 sp638;
    MKVector3 sp628;
    f64 sp620;
    f64 sp618;
    MKVector3 sp608;
    MKVector3 sp5F8;
    MKVector3 sp5E8;
    f64 sp5E0;
    f64 sp5D8;
    MKVector3 sp5C8;
    f64 sp5C0;
    f64 sp5B8;
    MKVector3 sp5A8;
    MKVector3 sp598;
    f64 sp590;
    f64 sp588;
    MKVector3 sp578;
    MKVector3 sp568;
    MKVector3 sp558;
    f64 sp550;
    f64 sp548;
    f64 sp540;
    f64 sp538;
    f64 sp530;
    f64 sp528;
    f64 sp520;
    f64 sp518;
    MKVector3 sp508;
    f64 sp500;
    f64 sp4F8;
    f64 sp4F0;
    f64 sp4E8;
    MKVector3 sp4D8;
    f64 sp4D0;
    f64 sp4C8;
    f64 sp4C0;
    f64 sp4B8;
    f64 sp4B0;
    f64 sp4A8;
    f64 sp4A0;
    f64 sp498;
    f64 sp490;
    f64 sp488;
    MKVector3 sp478;
    f64 sp470;
    f64 sp468;
    f64 sp460;
    f64 sp458;
    f64 sp450;
    f64 sp448;
    f64 sp440;
    f64 sp438;
    f64 sp430;
    f64 sp428;
    f64 sp420;
    f64 sp418;
    MKVector3 sp408;
    MKVector3 sp3F8;
    MKVector3 sp3E8;
    f64 sp3E0;
    f64 sp3D8;
    MKVector3 sp3C8;
    MKVector3 sp3B8;
    MKVector3 sp3A8;
    f64 sp3A0;
    f64 sp398;
    MKVector3 sp388;
    f64 sp380;
    f64 sp378;
    f64 sp370;
    f64 sp368;
    f64 sp360;
    f64 sp358;
    f64 sp350;
    f64 sp348;
    f64 sp340;
    f64 sp338;
    f64 sp330;
    f64 sp328;
    MKVector3 sp318;
    MKVector3 sp308;
    f32 sp300;
    f32 sp2FC;
    f32 sp2F8;
    f32 sp2F0;
    f64 sp2E8;
    f32 sp2E0;
    f32 sp2DC;
    f32 sp2D8;
    f32 sp2D0;
    f32 sp2CC;
    f32 sp2C8;
    f32 sp2C0;
    f64 sp2B8;
    f32 sp2B0;
    f64 sp2A8;
    f32 sp2A0;
    f64 sp298;
    f32 sp290;
    f32 sp28C;
    f32 sp288;
    f32 sp280;
    f32 sp27C;
    f32 sp278;
    f32 sp270;
    f32 sp26C;
    f32 sp268;
    f32 sp264;
    f32 sp260;
    f32 sp25C;
    f32 sp258;
    f32 sp250;
    f32 sp24C;
    f32 sp248;
    f32 sp240;
    f32 sp23C;
    f32 sp238;
    f32 sp230;
    f64 sp228;
    f32 sp220;
    f32 sp21C;
    f32 sp218;
    f32 sp214;
    f32 sp210;
    f32 sp20C;
    f32 sp208;
    f32 sp204;
    f32 sp200;
    f32 sp1FC;
    f32 sp1F8;
    f32 sp1F0;
    f32 sp1EC;
    f32 sp1E8;
    f32 sp1E0;
    f64 sp1D8;
    f32 sp1D0;
    f64 sp1C8;
    f32 sp1C0;
    f64 sp1B8;
    f32 sp1B0;
    f32 sp1AC;
    f32 sp1A8;
    f32 sp1A4;
    f32 sp1A0;
    f32 sp19C;
    f32 sp198;
    f32 sp190;
    f32 sp18C;
    f32 sp188;
    f32 sp180;
    f64 sp178;
    f32 sp170;
    f64 sp168;
    MKVector3 sp158;
    MKVector3 sp148;
    f32 sp140;
    f32 sp13C;
    f32 sp138;
    f32 sp130;
    f64 sp128;
    MKVector3 sp118;
    MKVector3 sp108;
    f32 sp100;
    f64 spF8;
    f32 spF0;
    f32 spEC;
    f32 spE8;
    MKVector3 spD8;
    f32 spD0;
    f64 spC8;
    f32 spC0;
    f32 spBC;
    f32 spB8;
    f32 spB0;
    f64 spA8;
    MKVector3 sp98;
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
    s32 sp14;
    s32 sp10;
    f32 spC;
    f32 sp8;
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
    f32 temp_f1_1094;
    f32 temp_f1_1666;
    f32 temp_f1_1867;
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
    f64 temp_f0_1315;
    f64 temp_f0_1361;
    f64 temp_f0_1507;
    f64 temp_f0_1553;
    f64 temp_f0_1741;
    f64 temp_f0_1793;
    f64 temp_f0_1824;
    f64 temp_f0_2160;
    f64 temp_f0_2308;
    f64 temp_f0_2454;
    f64 temp_f0_2464;
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

    temp_f1_889 = this->unk180;
    if (temp_f1_889 >= 0.0f) {
        this->unk180 = temp_f1_889 + gUpdateTimeDelta;
        if (((u8) M2C_FIELD(M2C_FIELD(M2C_FIELD(gb.unk0->GetEffects(), void **, 4), void **, 0xB4), u8 *, 0x16) != 0) && ((u8) M2C_FIELD(M2C_FIELD(M2C_FIELD(gb.unk0->GetEffects(), void **, 4), void **, 0xB4), u8 *, 0x17) != 0) && (((temp_f1_920 = this->unk180, ((temp_f1_920 >= 0.0f) != 0)) && (temp_f1_920 <= 1.0f)) || ((temp_f1_920 >= 5.0f) && (temp_f1_920 <= 7.0f)))) {
            ((KDInput *) (gb.unk0->GetInput()))->RumblePlay(0.0f, 0.5f, 0.15f, 0, 4.0f, 0U);
        } else {
            temp_f2_955 = this->unk180;
            if ((temp_f2_955 > 1.0f) && (temp_f2_955 <= 4.4f)) {
                if ((temp_f2_955 > 1.0f) && (temp_f2_955 <= 2.1f)) {
                    this->unk184 = (0.909f * (temp_f2_955 - 1.0f) * 0.125f) + 0.0f;
                } else if ((temp_f2_955 > 2.1f) && (temp_f2_955 <= 2.9f)) {
                    this->unk184 = (1.25f * (temp_f2_955 - 2.1f) * 0.125f) + 0.125f;
                } else if ((temp_f2_955 > 2.9f) && (temp_f2_955 <= 3.7f)) {
                    this->unk184 = (1.25f * (temp_f2_955 - 2.9f) * 0.06999999f) + 0.25f;
                } else if ((temp_f2_955 > 3.7f) && (temp_f2_955 <= 4.4f)) {
                    this->unk184 = (1.429f * (temp_f2_955 - 3.7f) * 0.18f) + 0.32f;
                }
                temp_f22_1025 = this->unk184;
                ((KDInput *) (gb.unk0->GetInput()))->RumblePlay(0.7f * temp_f22_1025, temp_f22_1025, 0.033f, 0, 4.0f, 0U);
            } else if (temp_f2_955 > 7.0f) {
                this->unk180 = -1.0f;
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
            sp84C = 0;
            temp_f1_1094 = M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), f32 (**)(), 0x54)();
            sp848 = 0x458;
            sp850 = temp_f1_1094 + (0.017453292f * (30.0f * (1.0f - var_f1_1067)));
            M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, f32), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &sp848, 0.017453292f);
        }
        if (this->unkAC <= 0.0f) {
            this->unk90 = 2;
            if ((u8) this->unk18C != 0) {
                this->unkAC = 3.0f;
            } else {
                this->unkAC = 0.8f;
            }
            sp188 = 6.0f;
            sp18C = 0.25f;
            sp190 = 6.0f;
            M2C_FIELD(this, f64 *, 0x98) = (f64) sp188;
            M2C_FIELD(this, f64 *, 0xA0) = (f64) sp190;
            sp7F8 = (f64) sp188;
            sp800 = (f64) sp190;
            KDSound_Play3d(GS_SpyroFuryAttackLightning1, (MKVector3 *) &this->unkB0, 0U, -1, 0.0f, 0U);
            temp_r4_1145 = this->unkC4;
            if (temp_r4_1145 != NULL) {
                ((LightManager *) gb.unk80)->EnableLight(temp_r4_1145, 1U);
                sp7D8 = MKVector(0.0f, 300.0f, 0.0f);
                sp178 = M2C_FIELD(this, f64 *, 0xB0) + sp7D8;
                temp_r3_1168 = this->unkC4;
                sp7E8 = sp178;
                sp180 = this->unkB8 + sp7D8.unk8;
                temp_r3_1168->unk10 = sp178;
                temp_r3_1168->unk18 = (f64) sp180;
                temp_r3_1174 = temp_r3_1168->unk3C;
                sp7F0 = (f64) sp180;
                if (temp_r3_1174 != NULL) {
                    M2C_FIELD(temp_r3_1174, f64 *, 0x10) = sp178;
                    M2C_FIELD(temp_r3_1174, f64 *, 0x18) = (f64) sp180;
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
                sp8DC = 0;
                temp_f22_1206 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
                temp_f23_1211 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
                sp7B8 = MKVector(MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f), temp_f23_1211, temp_f22_1206);
                sp168 = sp7B8 * 5.398241246e-315;
                sp8D8 = 0x417;
                sp8E0 = sp168;
                sp170 = sp7B8.unk8 * 10.0f;
                sp8F0 = 1;
                sp8E8 = (f64) sp170;
                sp7C8 = sp168;
                sp7D0 = (f64) sp170;
                M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, f64), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &sp8D8, sp168);
            }
            gb.unk2CC.Disable(this->unk188);
            this->unk188 = -1;
            if ((u8) this->unk18C != 0) {
                gb.GetSpyro();
                this->unk190 = ((Spyro *) (M2C_ERROR(/* Read from unset register $r3 */)))->SetFuryAnimSpeed(0.9f);
            }
        }
    default:                                        /* switch 1 */
block_172:
        var_r28_2664 = 0;
        var_r31_2666 = 0;
        do {
            temp_r29_2673 = this + var_r31_2666;
            M2C_FIELD(temp_r29_2673, f32 *, 0xD4) = (f32) ((gUpdateTimeDelta * (3.1415927f * MKRand_Float((int *) &gViewSeed, 0.1f, 1.0f))) + M2C_FIELD(temp_r29_2673, f32 *, 0xD4));
            var_r28_2664 += 1;
            var_r31_2666 += 0x10;
            M2C_FIELD(temp_r29_2673, f32 *, 0xD0) = (f32) ((gUpdateTimeDelta * (2.0f * (3.1415927f * MKRand_Float((int *) &gViewSeed, 0.1f, 1.0f)))) + M2C_FIELD(temp_r29_2673, f32 *, 0xD0));
        } while (var_r28_2664 < 3);
        temp_r3_2692 = this->unk90;
        if (temp_r3_2692 != 4) {
            if (((u8) this->unk18C != 0) && (temp_r3_2692 != 3)) {
                this->unk194 += 0.6f * gUpdateTimeDelta;
            } else {
                this->unk194 += gUpdateTimeDelta;
            }
            this->unkC0->SetScale(this->unk194);
        }
        break;
    case 2:                                         /* switch 1 */
        if (this->unk98.unk0 == 0.1f) {
            M2C_FIELD(this, f64 *, 0x160) = (f64) this->unk170;
            M2C_FIELD(this, f64 *, 0x168) = (f64) this->unk178;
            if ((u8) this->unk18C != 0) {
                var_f22_1274 = this->unkAC;
                if (var_f22_1274 < 3.0f) {

                } else {
                    var_f22_1274 = 3.0f;
                }
                if (var_f22_1274 > 0.0f) {

                } else {
                    var_f22_1274 = 0.0f;
                }
                sp748 = MKVector(1000.0f, 1000.0f, 1000.0f);
                sp758 = MKVector(-12.0f, 40.0f, -12.0f);
                sp768 = sp758.operator*(gUpdateTimeDelta);
                sp778 = sp768.operator*((2.0f * (1.0f - (var_f22_1274 / 3.0f))) + 1.0f);
                temp_f0_1315 = M2C_FIELD(this, f64 *, 0x98) + M2C_BITWISE(f64, sp778);
                sp68 = temp_f0_1315;
                sp788 = temp_f0_1315;
                sp70 = this->unk98.unk8 + sp778.unk8;
                sp790 = (f64) sp70;
                sp798 = MKVector(0.1f, 0.2f, 0.1f);
                sp158 = Min(*((MKVector3 *) &sp788), sp748);
                sp7A8 = Max(sp158, sp798);
                M2C_FIELD(this, MKVector3 *, 0x98) = sp7A8;
            } else {
                sp6E8 = MKVector(1000.0f, 1000.0f, 1000.0f);
                sp6F8 = MKVector(-12.0f, 40.0f, -12.0f);
                sp708 = sp6F8.operator*(gUpdateTimeDelta);
                temp_f0_1361 = M2C_FIELD(this, f64 *, 0x98) + M2C_BITWISE(f64, sp708);
                sp58 = temp_f0_1361;
                sp718 = temp_f0_1361;
                sp60 = this->unk98.unk8 + sp708.unk8;
                sp720 = (f64) sp60;
                sp728 = MKVector(0.1f, 0.2f, 0.1f);
                sp148 = Min(*((MKVector3 *) &sp718), sp6E8);
                sp738 = Max(sp148, sp728);
                M2C_FIELD(this, MKVector3 *, 0x98) = sp738;
            }
            if (((u8) this->unk18C != 0) && (this->unk98.unk4 >= 20.0f)) {
                sp138 = 6.0f;
                sp13C = 0.25f;
                sp140 = 6.0f;
                M2C_FIELD(this, f64 *, 0x98) = (f64) sp138;
                M2C_FIELD(this, f64 *, 0xA0) = (f64) sp140;
                sp6D8 = (f64) sp138;
                sp6E0 = (f64) sp140;
                if ((void *) M2C_FIELD(&gb, void **, 0x3B8) != NULL) {
                    sp8BC = 0;
                    temp_f22_1419 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
                    temp_f23_1424 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
                    sp6B8 = MKVector(MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f), temp_f23_1424, temp_f22_1419);
                    sp128 = sp6B8 * 5.49408334e-315;
                    sp8B8 = 0x417;
                    sp8C0 = sp128;
                    sp130 = sp6B8.unk8 * 50.0f;
                    sp8D0 = 1;
                    sp8C8 = (f64) sp130;
                    sp6C8 = sp128;
                    sp6D0 = (f64) sp130;
                    M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, f64), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &sp8B8, sp128);
                }
            }
        } else {
            M2C_FIELD(this, f64 *, 0x160) = (f64) M2C_FIELD(this, f64 *, 0xB0);
            M2C_FIELD(this, f64 *, 0x168) = (f64) M2C_FIELD(this, f32 *, 0xB8);
            if ((u8) this->unk18C != 0) {
                var_f22_1466 = this->unkAC;
                if (var_f22_1466 < 3.0f) {

                } else {
                    var_f22_1466 = 3.0f;
                }
                if (var_f22_1466 > 0.0f) {

                } else {
                    var_f22_1466 = 0.0f;
                }
                sp648 = MKVector(1000.0f, 1000.0f, 1000.0f);
                sp658 = MKVector(-12.0f, 3.0f, -12.0f);
                sp668 = sp658.operator*((2.0f * (1.0f - (var_f22_1466 / 3.0f))) + 1.0f);
                sp678 = sp668.operator*(gUpdateTimeDelta);
                temp_f0_1507 = M2C_FIELD(this, f64 *, 0x98) + M2C_BITWISE(f64, sp678);
                sp48 = temp_f0_1507;
                sp688 = temp_f0_1507;
                sp50 = this->unk98.unk8 + sp678.unk8;
                sp690 = (f64) sp50;
                sp698 = MKVector(0.1f, 0.2f, 0.1f);
                sp118 = Min(*((MKVector3 *) &sp688), sp648);
                sp6A8 = Max(sp118, sp698);
                M2C_FIELD(this, MKVector3 *, 0x98) = sp6A8;
            } else {
                sp5E8 = MKVector(1000.0f, 1000.0f, 1000.0f);
                sp5F8 = MKVector(-12.0f, 3.0f, -12.0f);
                sp608 = sp5F8.operator*(gUpdateTimeDelta);
                temp_f0_1553 = M2C_FIELD(this, f64 *, 0x98) + M2C_BITWISE(f64, sp608);
                sp38 = temp_f0_1553;
                sp618 = temp_f0_1553;
                sp40 = this->unk98.unk8 + sp608.unk8;
                sp620 = (f64) sp40;
                sp628 = MKVector(0.1f, 0.2f, 0.1f);
                sp108 = Min(*((MKVector3 *) &sp618), sp5E8);
                sp638 = Max(sp108, sp628);
                M2C_FIELD(this, MKVector3 *, 0x98) = sp638;
            }
        }
        if ((u8) this->unk18C != 0) {
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
            sp5C8 = MKVector(0.0f, (400.0f * var_f22_1602) + 25.0f, 0.0f);
            spF8 = M2C_FIELD(this, f64 *, 0xB0) + M2C_BITWISE(f64, sp5C8);
            temp_r3_1644 = this->unkC4;
            sp5D8 = spF8;
            sp100 = this->unkB8 + sp5C8.unk8;
            temp_r3_1644->unk10 = spF8;
            temp_r3_1644->unk18 = (f64) sp100;
            temp_r3_1650 = temp_r3_1644->unk3C;
            sp5E0 = (f64) sp100;
            if (temp_r3_1650 != NULL) {
                M2C_FIELD(temp_r3_1650, f64 *, 0x10) = spF8;
                M2C_FIELD(temp_r3_1650, f64 *, 0x18) = (f64) sp100;
            }
            temp_r3_1664 = this->unkC4;
            temp_f1_1666 = (1.0f + var_f22_1602) * (1000.0f * MKRand_Float((int *) &gViewSeed, 1.0f, 1.2f));
            temp_r3_1664->unk38 = temp_f1_1666;
            temp_r3_1668 = temp_r3_1664->unk3C;
            if (temp_r3_1668 != NULL) {
                M2C_FIELD(temp_r3_1668, f32 *, 0x20) = temp_f1_1666;
                M2C_FIELD(temp_r3_1668, f32 *, 0x24) = (f32) (temp_f1_1666 * temp_f1_1666);
                M2C_FIELD(temp_r3_1668, f32 *, 0x28) = (f32) (1.0f / temp_f1_1666);
                M2C_FIELD(temp_r3_1668, f32 *, 0x2C) = (f32) (1.0f / M2C_FIELD(temp_r3_1668, f32 *, 0x24));
            }
        }
        if (this->unkAC <= 0.0f) {
            this->unk90 = 3;
            this->unkAC = 1.2f;
            if ((u8) this->unk18C != 0) {
                spE8 = 0.1f;
                spEC = 1000.0f;
                spF0 = 0.1f;
                M2C_FIELD(this, f64 *, 0x98) = (f64) spE8;
                sp5B8 = (f64) spE8;
                sp5C0 = (f64) spF0;
                M2C_FIELD(this, f64 *, 0xA0) = (f64) spF0;
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
        sp558 = MKVector(1000.0f, 1000.0f, 1000.0f);
        sp568 = MKVector(-0.25f, 0.0f, -0.25f);
        sp578 = sp568.operator*(gUpdateTimeDelta);
        temp_f0_1741 = M2C_FIELD(this, f64 *, 0x98) + M2C_BITWISE(f64, sp578);
        sp28 = temp_f0_1741;
        sp588 = temp_f0_1741;
        sp30 = this->unk98.unk8 + sp578.unk8;
        sp590 = (f64) sp30;
        sp598 = MKVector(0.0f, 0.2f, 0.0f);
        spD8 = Min(*((MKVector3 *) &sp588), sp558);
        sp5A8 = Max(spD8, sp598);
        M2C_FIELD(this, MKVector3 *, 0x98) = sp5A8;
        sp2E0 = -1.0f;
        temp_f29_1775 = this->unk194;
        sp2D0 = 1.0f;
        sp2D8 = -1.0f;
        sp2DC = 0.0f;
        sp2C8 = 1.0f;
        sp2CC = 0.0f;
        sp4F8 = (f64) sp2D8;
        sp500 = (f64) sp2E0;
        sp4E8 = (f64) sp2C8;
        sp4F0 = (f64) sp2D0;
        sp508 = KDRand_Vector(*((MKVector3 *) &sp4F8), *((MKVector3 *) &sp4E8));
        temp_f0_1793 = sp508 * 5.5769738e-315;
        sp2B8 = temp_f0_1793;
        sp518 = temp_f0_1793;
        sp2C0 = sp508.unk8 * 200.0f;
        sp520 = (f64) sp2C0;
        sp2A8 = temp_f0_1793 * (f64) temp_f29_1775;
        sp300 = 0.0f;
        sp2B0 = (f32) sp520 * temp_f29_1775;
        sp2F8 = 0.0f;
        sp2FC = 850.0f;
        sp528 = sp2A8;
        sp538 = (f64) sp2F8;
        sp530 = (f64) sp2B0;
        sp540 = (f64) sp300;
        temp_f0_1824 = M2C_FIELD(this, f64 *, 0xB0) + sp538;
        sp2E8 = temp_f0_1824;
        sp548 = temp_f0_1824;
        sp2F0 = this->unkB8 + (f32) sp540;
        sp550 = (f64) sp2F0;
        sp298 = sp548 + sp528;
        sp290 = -1.0f;
        sp280 = 1.0f;
        sp288 = -1.0f;
        sp28C = -1.0f;
        sp2A0 = (f32) sp550 + (f32) sp530;
        sp278 = 1.0f;
        sp27C = -0.5f;
        sp838 = sp298;
        sp840 = (f64) sp2A0;
        sp4C8 = (f64) sp288;
        sp4D0 = (f64) sp290;
        sp4B8 = (f64) sp278;
        sp4C0 = (f64) sp280;
        sp4D8 = KDRand_Vector(*((MKVector3 *) &sp4C8), *((MKVector3 *) &sp4B8));
        temp_f1_1867 = M2C_BITWISE(f32, sp4D8);
        var_f4_1875 = (sp4D8.unk8 * sp4D8.unk8) + ((temp_f1_1867 * temp_f1_1867) + (sp4D8.unk4 * sp4D8.unk4));
        if (var_f4_1875 > 1e-12f) {
            if (var_f4_1875 > 0.0f) {
                temp_f1_1881 = __frsqrte(var_f4_1875);
                temp_f1_1887 = 0.5 * temp_f1_1881 * -(((f64) var_f4_1875 * (temp_f1_1881 * temp_f1_1881)) - 3.0);
                temp_f1_1891 = 0.5 * temp_f1_1887 * -(((f64) var_f4_1875 * (temp_f1_1887 * temp_f1_1887)) - 3.0);
                var_f4_1875 = (f32) ((f64) var_f4_1875 * (0.5 * temp_f1_1891 * -(((f64) var_f4_1875 * (temp_f1_1891 * temp_f1_1891)) - 3.0)));
            } else if (var_f4_1875 < M2C_BITWISE(f32, 0.0)) {
                var_f4_1875 = __float_nan;
            } else {
                sp8 = var_f4_1875;
                temp_r3_1910 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                switch (temp_r3_1910) {             /* switch 2; irregular */
                case 0x7F800000:                    /* switch 2 */
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_1920 = 1;
                    } else {
                        var_r0_1920 = 2;
                    }
                    break;
                case 0x0:                           /* switch 2 */
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
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
        sp270 = sp4D8.unk8 * var_f3_1942;
        sp268 = M2C_BITWISE(f32, sp4D8) * var_f3_1942;
        sp26C = sp4D8.unk4 * var_f3_1942;
        sp258 = 1.0f;
        sp25C = 1.0f;
        sp260 = 0.2f;
        sp264 = 1.0f;
        sp828 = (f64) sp268;
        sp830 = (f64) sp270;
        sp4A8 = (f64) sp258;
        sp4B0 = (f64) sp260;
        spC = (2.5f * temp_f26_1727) + 0.1f;
        ((ZapArcFX *) gb.unk94)->Trigger(*((MKVector3 *) &sp838), *((MKVector3 *) &sp828), spC, lit_828, (MKVector4) &sp4A8);
        sp250 = 0.0f;
        sp248 = 0.0f;
        sp24C = -980.0f;
        sp4A0 = (f64) sp250;
        sp498 = (f64) sp248;
        ((WaterDripPS *) gb.unk6C)->Emit(*((MKVector3 *) &sp838), *((MKVector3 *) &sp498), 2.0f, 1U, 0U, NULL);
        temp_r3_2002 = this->unkC4;
        if (temp_r3_2002 != NULL) {
            temp_r3_2002->unk10 = sp838;
            temp_r3_2002->unk18 = sp840;
            temp_r3_2009 = temp_r3_2002->unk3C;
            if (temp_r3_2009 != NULL) {
                M2C_FIELD(temp_r3_2009, f64 *, 0x10) = sp838;
                M2C_FIELD(temp_r3_2009, f64 *, 0x18) = sp840;
            }
            temp_r3_2024 = this->unkC4;
            temp_f1_2026 = (1.0f + temp_f26_1727) * (1000.0f * MKRand_Float((int *) &gViewSeed, 1.0f, 2.0f));
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
            sp89C = 0;
            temp_f22_2051 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
            temp_f23_2056 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
            sp478 = MKVector(MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f), temp_f23_2056, temp_f22_2051);
            spC8 = sp478 * 5.49408334e-315;
            sp898 = 0x417;
            sp8A0 = spC8;
            spD0 = sp478.unk8 * 50.0f;
            sp8B0 = 1;
            sp8A8 = (f64) spD0;
            sp488 = spC8;
            sp490 = (f64) spD0;
            M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, f64), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &sp898, spC8);
        }
        if (this->unkAC <= 0.0f) {
            this->unk90 = 4;
            spC0 = 1.0f;
            spB8 = 1.0f;
            spBC = 6.0f;
            this->unkAC = 1.0f;
            M2C_FIELD(this, f64 *, 0x98) = (f64) spB8;
            M2C_FIELD(this, f64 *, 0xA0) = (f64) spC0;
            sp468 = (f64) spB8;
            sp470 = (f64) spC0;
            this->unkC0->Explode();
            this->unkC0->Stop();
            this->unk108.unk50 = 0;
            temp_f2_2119 = M2C_FIELD(this, f64 *, 0xB0);
            M2C_FIELD(this, f64 *, 0x118) = temp_f2_2119;
            M2C_FIELD(this, f64 *, 0x120) = (f64) M2C_FIELD(this, f32 *, 0xB8);
            M2C_FIELD(*gMK, M2C_UNK (**)(void **, BreathHitMessage *, M2C_UNK, M2C_UNK, f32 *, M2C_UNK, f32, f64), 0x94)(gMK, &this->unk108, 0, 0, &this->unkB0, 1, 3000.0f, temp_f2_2119);
            sp220 = 0.0f;
            sp240 = 0.0f;
            sp208 = 1.0f;
            sp20C = 1.0f;
            sp210 = 0.2f;
            sp214 = 1.0f;
            sp218 = 0.0f;
            sp21C = -1.0f;
            sp238 = 0.0f;
            sp23C = 500.0f;
            sp4A8 = (f64) sp208;
            sp4B0 = (f64) sp210;
            sp438 = (f64) sp218;
            sp440 = (f64) sp220;
            sp448 = (f64) sp238;
            sp450 = (f64) sp240;
            temp_f0_2160 = M2C_FIELD(this, f64 *, 0xB0) + sp448;
            sp228 = temp_f0_2160;
            sp458 = temp_f0_2160;
            sp230 = this->unkB8 + (f32) sp450;
            sp460 = (f64) sp230;
            ((ZapArcFX *) gb.unk94)->Trigger(*((MKVector3 *) &sp458), *((MKVector3 *) &sp438), 4.0f, lit_837, (MKVector4) &sp4A8);
            sp1F8 = 1.0f;
            sp1FC = 1.0f;
            sp200 = 1.0f;
            sp204 = 1.0f;
            sp428 = (f64) sp1F8;
            sp430 = (f64) sp200;
            gb.unkB8.EnableScreenFlash(*((MKVector4 *) &sp428), 3.0f * gUpdateTimeDelta);
            KDSound_Play3d(GS_SpyroFuryAttackLightning2, (MKVector3 *) &this->unkB0, 0U, -1, 0.0f, 0U);
            KDSound_Play3d(GS_Rumble1, (MKVector3 *) &this->unkB0, 0U, -1, 0.0f, 0U);
            ((KDInput *) (gb.unk0->GetInput()))->RumblePlay(0.99f, 0.99f, 0.65f, 0, 4.0f, 0U);
            if ((void *) M2C_FIELD(&gb, void **, 0x3B8) != NULL) {
                sp87C = 0;
                temp_f22_2231 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
                temp_f23_2236 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
                sp408 = MKVector(MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f), temp_f23_2236, temp_f22_2231);
                spA8 = sp408 * 5.64367472e-315;
                sp878 = 0x417;
                sp880 = spA8;
                spB0 = sp408.unk8 * 600.0f;
                sp890 = 1;
                sp888 = (f64) spB0;
                sp418 = spA8;
                sp420 = (f64) spB0;
                M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, f64), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &sp878, spA8);
            }
            this->unk188 = gb.unk2CC.Enable(0.5f, 0.0f, 0.0f, -1.0f);
            M2C_FIELD(this, f64 *, 0x160) = (f64) M2C_FIELD(this, f64 *, 0xB0);
            M2C_FIELD(this, f64 *, 0x168) = (f64) M2C_FIELD(this, f32 *, 0xB8);
            gb.GetSpyro();
            ((Spyro *) (M2C_ERROR(/* Read from unset register $r3 */)))->SetRage(1, 15.0f);
        }
        goto block_172;
    case 4:                                         /* switch 1 */
        sp3A8 = MKVector(1000.0f, 1000.0f, 1000.0f);
        sp3B8 = MKVector(18.0f, -10.0f, 18.0f);
        sp3C8 = sp3B8.operator*(gUpdateTimeDelta);
        temp_f0_2308 = M2C_FIELD(this, f64 *, 0x98) + M2C_BITWISE(f64, sp3C8);
        sp18 = temp_f0_2308;
        sp3D8 = temp_f0_2308;
        sp20 = this->unk98.unk8 + sp3C8.unk8;
        sp3E0 = (f64) sp20;
        sp3E8 = MKVector(0.0f, 0.0f, 0.0f);
        sp98 = Min(*((MKVector3 *) &sp3D8), sp3A8);
        sp3F8 = Max(sp98, sp3E8);
        M2C_FIELD(this, MKVector3 *, 0x98) = sp3F8;
        if ((ManagedLight *) this->unkC4 != NULL) {
            sp388 = MKVector(0.0f, 2000.0f * gUpdateTimeDelta, 0.0f);
            temp_r4_2345 = this->unkC4;
            sp88 = temp_r4_2345->unk10 + M2C_BITWISE(f64, sp388);
            temp_r4_2345->unk10 = sp88;
            sp90 = (f32) M2C_FIELD(temp_r4_2345, f64 *, 0x18) + sp388.unk8;
            sp398 = sp88;
            temp_r4_2345->unk18 = (f64) sp90;
            temp_r3_2360 = temp_r4_2345->unk3C;
            sp3A0 = (f64) sp90;
            if (temp_r3_2360 != NULL) {
                M2C_FIELD(temp_r3_2360, f64 *, 0x10) = sp88;
                M2C_FIELD(temp_r3_2360, f64 *, 0x18) = (f64) sp90;
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
        temp_r29_2404 = MKRand_Int((int *) &gViewSeed, 0xF, 0x1E);
        var_r28_2411 = 0;
        temp_f25_2418 = 6.2831855f / (f32) (temp_r29_2404 - 1);
loop_151:
        if (var_r28_2411 < temp_r29_2404) {
            temp_f28_2423 = this->unk98.unk0;
            temp_f21_2430 = (f32) var_r28_2411 * temp_f25_2418;
            temp_f23_2432 = MKRand_Float((int *) &gViewSeed, 0.8f, 1.0f);
            temp_f22_2439 = -_table_sinf(1.5707964f + temp_f21_2430) * temp_f23_2432;
            temp_f23_2441 = MKRand_Float((int *) &gViewSeed, 0.8f, 1.0f);
            temp_f1_2444 = _table_sinf(temp_f21_2430) * temp_f23_2441;
            sp1F0 = temp_f22_2439;
            sp1E8 = temp_f1_2444;
            sp1EC = 0.0f;
            sp360 = (f64) sp1F0;
            sp358 = (f64) sp1E8;
            temp_f0_2454 = sp358 * 5.5769738e-315;
            sp1D8 = temp_f0_2454;
            sp368 = temp_f0_2454;
            sp1E0 = (f32) sp360 * 200.0f;
            sp370 = (f64) sp1E0;
            temp_f0_2464 = temp_f0_2454 * (f64) temp_f28_2423;
            sp1C8 = temp_f0_2464;
            sp378 = temp_f0_2464;
            sp1D0 = (f32) sp370 * temp_f28_2423;
            sp380 = (f64) sp1D0;
            sp1B8 = M2C_FIELD(this, f64 *, 0xB0) + temp_f0_2464;
            sp1B0 = 0.0f;
            sp198 = 1.0f;
            sp1C0 = this->unkB8 + (f32) sp380;
            sp19C = 1.0f;
            sp1A0 = 1.0f;
            sp1A4 = 1.0f;
            sp1A8 = 0.0f;
            sp1AC = 0.0f;
            sp818 = sp1B8;
            sp820 = (f64) sp1C0;
            sp338 = (f64) sp198;
            sp340 = (f64) sp1A0;
            sp348 = (f64) sp1A8;
            sp350 = (f64) sp1B0;
            this->unk100->Emit(*((MKVector3 *) &sp818), *((MKVector3 *) &sp348), 30.0f, (MKVector4) &sp338);
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
            sp85C = 0;
            temp_f22_2538 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
            temp_f23_2543 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
            sp308 = MKVector(MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f), temp_f23_2543, temp_f22_2538);
            sp318 = sp308.operator*(200.0f);
            sp78 = sp318 * (f64) var_f26_2522;
            sp858 = 0x417;
            sp860 = sp78;
            sp80 = sp318.unk8 * var_f26_2522;
            sp870 = 1;
            sp868 = (f64) sp80;
            sp328 = sp78;
            sp330 = (f64) sp80;
            M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, f64), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &sp858, sp78);
        }
        if (((void *) M2C_FIELD(&gb, void **, 0x3B8) != NULL) && (var_f26_2522 <= 0.5f)) {
            sp80C = 0;
            temp_f1_2592 = M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), f32 (**)(), 0x54)();
            sp808 = 0x458;
            sp810 = temp_f1_2592 + (0.017453292f * (30.0f * (var_f26_2522 / 0.5f)));
            M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, f32, f32), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &sp808, 30.0f, 0.017453292f);
        }
        if (var_f26_2522 < 0.5f) {
            gb.unk2CC.Disable(this->unk188);
            this->unk188 = -1;
            if ((u8) this->unk18C != 0) {
                gb.GetSpyro();
                ((Spyro *) (M2C_ERROR(/* Read from unset register $r3 */)))->SetFuryAnimSpeed(1.0f);
            }
        }
        if (this->unkAC <= 0.0f) {
            this->unk90 = 0;
            temp_r4_2636 = this->unkC4;
            if (temp_r4_2636 != NULL) {
                ((LightManager *) gb.unk80)->EnableLight(temp_r4_2636, 0U);
            }
            if ((void *) M2C_FIELD(&gb, void **, 0x3B8) != NULL) {
                sp14 = 0;
                sp10 = 0x459;
                M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp10);
            }
            gb.unk381 = 0;
        }
        goto block_172;
    }
}
#endif

f32 FuryFXElectricity::Resolve() {
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
    this->unkC4 = (ManagedLight *) (((LightManager *) gb.unk80)->AllocManagedLight(*((MKVector3 *) &sp58), *((MKVector3 *) &sp48), *((MKVector4 *) &sp38), 300.0f, lit_739, lit_740));
    temp_r4_2790 = this->unkC4;
    if (temp_r4_2790 != NULL) {
        ((LightManager *) gb.unk80)->EnableLight(temp_r4_2790, 0U);
    }
}

void FuryFXElectricity::Init() {
    FuryFX::Init();
    this->unk90 = 0;
    this->unk180 = -1.0f;
    this->unk184 = 0.0f;
    this->unkA8 = (MKMaterial *) (MKMaterial_Create("fx_370"));
    this->unkC8 = (MKMaterial *) (MKMaterial_Create("windymat"));
    this->unkCC = (MKMaterial *) (MKMaterial_Create("windymat2"));
    this->unkAC = 0.0f;
    this->unkC0 = checked_cast<LitCloudPS *, MKProp>(((MKSceneManager *) gMK)->CreateProp("LitCloudPS"));
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
    this->unk100 = checked_cast<ZapPS *, MKProp>(((MKSceneManager *) gMK)->CreateProp("ZapPS"));
    this->unk188 = -1;
    this->unk18C = 0;
    this->unk194 = 0.0f;
}

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
