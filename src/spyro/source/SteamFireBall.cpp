#include "spyro/source/SteamFireBall.h"
#include "common/Source/Animation.h"
#include "common/Source/Font.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
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
#include "common/Source/MKProp.h"
#include "common/Source/MKPtrList.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/CameraData.h"
#include "spyro/source/DialogBox.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/Explosion4.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/FlyingBurningBits.h"
#include "spyro/source/Game.h"
#include "spyro/source/GameData.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/HeroInterface.h"
#include "spyro/source/KDMatrixProperty.h"
#include "spyro/source/KDMatrixRefProperty.h"
#include "spyro/source/KDPositionProperty.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDProperty.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/Level.h"
#include "spyro/source/ManagedLight.h"
#include "spyro/source/Projectile.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/TargetManager.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "spyro/source/KDMath.h"
#include <m2c_macros.h>

extern MKSceneManager *gMK;
extern f32 gUpdateTimeDelta;
extern GameGlobals gb;
extern MKPropDescriptor *pSteamFireBallDescriptor;

void SteamFireBall::FireAtTarget(const MKVector3 &arg0, const MKVector3 &arg1, float arg2, MKProp *arg3, int arg4, int arg5) {
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
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f64 sp8;
    f64 temp_f0_88;

    sp20 = 0.0f;
    sp18 = 0.0f;
    sp1C = -8000.0f;
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
    sp28 = (f64) sp18;
    sp30 = (f64) sp20;
    temp_f0_88 = M2C_FIELD(&arg0, f64 *, 0) + sp28;
    sp8 = temp_f0_88;
    sp38 = temp_f0_88;
    sp10 = arg0.unk8 + (f32) sp30;
    sp40 = (f64) sp10;
    if (MKCollision_RayCollide(arg0, *((MKVector3 *) &sp38), (MKCollisionResult *) &sp48, (MKCollisionMode) 4, 0x0C000000) != 0) {
        this->unk188 = sp4C;
    } else {
        this->unk188 = arg1.unk4;
    }
    this->unk150.unk28 = this->unk188 - 100.0f;
    this->unk150.Show(1U);
    Projectile::FireAtTarget(arg0, arg1, arg2, arg3, arg4, arg5);
}

#if 0 // DRAFT: undefined identifier 'unk18'
void SteamFireBall::Collided(MKCollisionResult &arg0) {
    s32 sp8;
    f32 temp_f1_170;
    s32 var_r5_167;
    void *temp_r3_148;

    Projectile::Collided(arg0);
    temp_r3_148 = checked_cast<SteamFireBallDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    sp8 = 1;
    ((Explosion4 *) (M2C_FIELD(temp_r3_148, Explosion4 **, 0xF0)))->Trigger(*((MKVector3 *) &arg0), 0.3f, 1U, this->unk130, 5, 1U, 1U, 1U, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    this->unk150.Show(0U);
    var_r5_167 = 3;
    temp_f1_170 = M2C_FIELD(GameData::gameData, f32 *, 0xA0) / M2C_FIELD(GameData::gameData, f32 *, 0xA4);
    if (temp_f1_170 >= 0.9f) {
        var_r5_167 = 0;
    } else if (temp_f1_170 > 0.75f) {
        var_r5_167 = 1;
    } else if (temp_f1_170 > 0.25f) {
        var_r5_167 = 2;
    }
    gb.unk18->Spawn(*((MKVector3 *) &arg0), var_r5_167, 200.0f, 500.0f, -1, NULL);
    Disable();
}
#endif

void *SteamFireBall::Update() {
    Matrix sp190;
    Matrix sp150;
    Matrix sp110;
    M2C_UNK sp10C;
    f64 sp100;
    f64 spF8;
    f64 spF0;
    f64 spE8;
    f64 spE0;
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
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp50;
    f64 sp48;
    f32 sp40;
    f64 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 temp_f0_243;
    f32 temp_f1_242;
    f32 temp_f3_245;
    f32 var_f1_441;
    f32 var_f3_317;
    f32 var_f4_250;
    f64 temp_f0_373;
    f64 temp_f0_386;
    f64 temp_f1_256;
    f64 temp_f1_262;
    f64 temp_f1_266;
    f64 temp_f3_465;
    f64 temp_f4_464;
    s32 temp_r3_285;
    s32 var_r0_295;
    void *temp_r3_380;
    void *temp_r3_428;
    void *temp_r3_461;

    Projectile::Update();
    this->unk184 += 10.0f * gUpdateTimeDelta;
    M2C_STRUCT_COPY((s32) &sp150.unk3C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
    temp_f1_242 = M2C_FIELD(this, f32 *, 0xC8);
    temp_f0_243 = M2C_FIELD(this, f32 *, 0xCC);
    temp_f3_245 = M2C_FIELD(this, f32 *, 0xD0);
    var_f4_250 = (temp_f3_245 * temp_f3_245) + ((temp_f1_242 * temp_f1_242) + (temp_f0_243 * temp_f0_243));
    if (var_f4_250 > 1e-12f) {
        if (var_f4_250 > 0.0f) {
            temp_f1_256 = __frsqrte(var_f4_250);
            temp_f1_262 = 0.5 * temp_f1_256 * -(((f64) var_f4_250 * (temp_f1_256 * temp_f1_256)) - 3.0);
            temp_f1_266 = 0.5 * temp_f1_262 * -(((f64) var_f4_250 * (temp_f1_262 * temp_f1_262)) - 3.0);
            var_f4_250 = (f32) ((f64) var_f4_250 * (0.5 * temp_f1_266 * -(((f64) var_f4_250 * (temp_f1_266 * temp_f1_266)) - 3.0)));
        } else if (var_f4_250 < M2C_BITWISE(f32, 0.0)) {
            var_f4_250 = __float_nan;
        } else {
            sp10 = var_f4_250;
            temp_r3_285 = M2C_BITWISE(s32, sp10) & 0x7F800000;
            switch (temp_r3_285) {                  /* irregular */
            case 0x7F800000:
                if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                    var_r0_295 = 1;
                } else {
                    var_r0_295 = 2;
                }
                break;
            case 0x0:
                if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                    var_r0_295 = 5;
                } else {
                    var_r0_295 = 3;
                }
                break;
            default:
                var_r0_295 = 4;
                break;
            }
            if (var_r0_295 == 1) {
                var_f4_250 = __float_nan;
            }
        }
        var_f3_317 = 1.0f / var_f4_250;
    } else {
        var_f3_317 = 0.0f;
    }
    sp60 = 0.0f;
    sp70 = M2C_FIELD(this, f32 *, 0xD0) * var_f3_317;
    sp68 = M2C_FIELD(this, f32 *, 0xC8) * var_f3_317;
    sp6C = M2C_FIELD(this, f32 *, 0xCC) * var_f3_317;
    sp58 = 0.0f;
    sp5C = 1.0f;
    spF8 = (f64) sp68;
    sp100 = (f64) sp70;
    spE8 = (f64) sp58;
    spF0 = (f64) sp60;
    KDMath_BuildMatrixFromFwd(&sp190, *((MKVector3 *) &spF8), (MKVector3 *) &spE8);
    M2C_STRUCT_COPY((s32) &sp110.unk3C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
    sp150.RotateRoll(&sp150, 2.0f * this->unk184);
    sp150.Multiply3x3(&sp150, &sp190);
    temp_f0_373 = sp150.unk10 * 5.53552857e-315;
    sp48 = temp_f0_373;
    spC8 = temp_f0_373;
    temp_r3_380 = ((u8 *) this->unk8) + 0x30;
    sp50 = sp150.unk18 * 100.0f;
    spD0 = (f64) sp50;
    temp_f0_386 = M2C_FIELD(temp_r3_380, f64 *, 0) + temp_f0_373;
    sp38 = temp_f0_386;
    spD8 = temp_f0_386;
    sp40 = M2C_FIELD(temp_r3_380, f32 *, 8) + (f32) spD0;
    spE0 = (f64) sp40;
    sp28 = sp150.unk10 * 5.56078426e-315;
    sp30 = sp150.unk18 * 150.0f;
    spB8 = sp28;
    spC0 = (f64) sp30;
    gb.EmitDust(*((MKVector3 *) &spD8), *((MKVector3 *) &spB8), 1.0f, 0.0f);
    if ((u8) this->unk150.unk2C != 0) {
        M2C_STRUCT_COPY((s32) &sp10C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
        temp_r3_428 = this->unk8;
        spA8 = M2C_FIELD(temp_r3_428, f64 *, 0x30);
        spB0 = M2C_FIELD(temp_r3_428, f64 *, 0x38);
        var_f1_441 = 0.18f * -((0.00022222222f * ((*(f32 *) ((u8 *) &spA8 + 0x4)) - this->unk188)) - 1.0f);
        if (var_f1_441 < 1.0f) {

        } else {
            var_f1_441 = 1.0f;
        }
        if (var_f1_441 > 0.001f) {

        } else {
            var_f1_441 = 0.001f;
        }
        sp110.Scale3x3(&sp110, var_f1_441);
        MKModel_SetWorldMatrix(this->unk180, sp110);
        temp_r3_461 = this->unk8;
        temp_f4_464 = M2C_FIELD(temp_r3_461, f64 *, 0x30);
        temp_f3_465 = M2C_FIELD(temp_r3_461, f64 *, 0x38);
        sp88 = temp_f4_464;
        sp80 = temp_f3_465;
        sp18 = (f32) sp88;
        sp1C = this->unk188;
        sp20 = (f32) sp80;
        sp98 = (f64) sp18;
        spA0 = (f64) sp20;
        sp78 = temp_f4_464;
        sp90 = temp_f3_465;
        MKModel_SetPosition(this->unk180, *((MKVector3 *) &sp98));
    }
}

f32 SteamFireBall::Resolve() {
    KDPropEx::Resolve();
    this->unk150.Init(this->unk180, (MKProp *) this, 2000.0f, NULL, 1500.0f);
    this->unk150.Show(0U);
}

s32 SteamFireBall::LoadDone() {
    Projectile::LoadDone();
    this->unk180 = MKModel_Create("P9022_DropBoxShadow", NULL, 2, NULL);
}

void SteamFireBall::Deinit() {
    MKModel_Destroy(this->unk180);
    this->unk150.Deinit();
    Projectile::Deinit();
}

void SteamFireBall::Init() {
    Projectile::Init();
    this->unk184 = 0.0f;
    this->unk188 = 0.0f;
}

void *SteamFireBall::CreateInstance() {
    void *temp_r3_593;

    if ((MKPropDescriptor *) pSteamFireBallDescriptor != NULL) {
        temp_r3_593 = pSteamFireBallDescriptor->CreateInstance();
        if (temp_r3_593 != NULL) {
            M2C_FIELD(M2C_FIELD(temp_r3_593, void **, 0x44), M2C_UNK (**)(), 0x20)();
            return temp_r3_593;
        }
    }
    return NULL;
}

void SteamFireBallDescriptor::LoadDone() {
    GamePropDescriptor::LoadDone();
    this->unkF0 = (long) (checked_cast<Explosion4 *, MKProp>(gMK->CreateProp("Explosion4")));
    pSteamFireBallDescriptor = (MKPropDescriptor *) this;
}

void SteamFireBallDescriptor::Deinit() {
    pSteamFireBallDescriptor = NULL;
    KDPropExDescriptor::Deinit();
}
