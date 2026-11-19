#include "spyro/source/IceSquirt.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKPtrList.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "common/Source/Texture.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/GameMessages.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/KDMatrixProperty.h"
#include "spyro/source/KDMatrixRefProperty.h"
#include "spyro/source/KDPositionProperty.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDProperty.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/LightManager.h"
#include "spyro/source/LiquidFX.h"
#include "spyro/source/ManagedLight.h"
#include "spyro/source/Projectile.h"
#include "unplaced_templates.h"
#include "common/Source/StdMath.h"
#include "spyro/source/Tools.h"
#include <m2c_macros.h>

extern s32 GS_SpyroIceBurn;
extern MKSceneManager *gMK;
extern s32 gViewSeed;
extern M2C_UNK gb;
extern MKPropDescriptor *pIceSquirtDescriptor;

static s32 lit_650 = 0;
static u8 lit_651 = 1;
static s32 lit_666 = 3;

void IceSquirt::Deinit() {
    ManagedLight *temp_r4_51;

    temp_r4_51 = this->unk160;
    if (temp_r4_51 != NULL) {
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->FreeManagedLight(temp_r4_51);
    }
    Projectile::Deinit();
}

void IceSquirt::FireBurstEnd() {
    ManagedLight *temp_r4_80;

    this->unk15C = 0;
    this->unk154 = NULL;
    this->unk158 = NULL;
    temp_r4_80 = this->unk160;
    if (temp_r4_80 != NULL) {
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->EnableLight(temp_r4_80, 0U);
    }
    Disable();
}

void IceSquirt::FireBurst(MKVector3 *arg0, MKVector3 *arg1, int arg2, int arg3) {
    s32 sp8;
    MKVector3 *temp_r4_125;
    ManagedLight *temp_r3_126;
    ManagedLight *temp_r4_117;
    void *temp_r3_131;

    this->unk15C = 1;
    this->unk154 = arg0;
    this->unk158 = arg1;
    Enable();
    temp_r4_117 = this->unk160;
    if (temp_r4_117 != NULL) {
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->EnableLight(temp_r4_117, 1U);
        temp_r4_125 = this->unk154;
        temp_r3_126 = this->unk160;
        temp_r3_126->unk10 = M2C_FIELD(temp_r4_125, f64 *, 0);
        temp_r3_126->unk18 = M2C_FIELD(temp_r4_125, f64 *, 8);
        temp_r3_131 = temp_r3_126->unk3C;
        if (temp_r3_131 != NULL) {
            M2C_FIELD(temp_r3_131, f64 *, 0x10) = (f64) M2C_FIELD(temp_r4_125, f64 *, 0);
            M2C_FIELD(temp_r3_131, f64 *, 0x18) = (f64) M2C_FIELD(temp_r4_125, f64 *, 8);
        }
    }
    sp8 = -1;
    this->unk168.Init((MKProp *) this, 1, 0, 0, 2, 0, 0, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    this->unk168.unk4C = GS_SpyroIceBurn;
}

void IceSquirt::Fire(const MKVector3 &arg0, const MKVector3 &arg1, MKProp *arg2, int arg3, int arg4) {
    Disable();
}

void IceSquirt::Collided(MKCollisionResult &arg0) {
    Disable();
}

void IceSquirt::Draw() {

}

void *IceSquirt::Update() {
    f64 sp48;
    f64 sp40;
    MKVector3 sp30;
    f64 sp28;
    f64 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    s32 spC;
    s32 sp8;
    MKVector3 *temp_r3_268;
    MKVector3 *temp_r4_209;
    MKVector3 *temp_r5_212;
    ManagedLight *temp_r3_285;
    ManagedLight *temp_r4_265;
    f32 temp_f1_284;
    u8 var_r0_222;
    void *temp_r3_287;
    void *temp_r4_273;

    Projectile::Update();
    if ((u8) this->unk15C != 0) {
        temp_r4_209 = this->unk154;
        if (temp_r4_209 != NULL) {
            temp_r5_212 = this->unk158;
            if (temp_r5_212 != NULL) {
                sp30 = Tools_CalculateVelocity(*temp_r4_209, *temp_r5_212, 2000.0f, -1500.0f);
                var_r0_222 = 0;
                *(MKVector3 *) &sp40 = sp30;
                if (((f32) sp40 == MKVector3::zero.unk0) && ((*(f32 *) ((u8 *) &sp40 + 0x4)) == MKVector3::zero.unk4) && ((f32) sp48 == MKVector3::zero.unk8)) {
                    var_r0_222 = 1;
                }
                if (var_r0_222 == 0) {
                    sp10 = 0.5f;
                    sp14 = 0.5f;
                    sp18 = 1.5f;
                    sp20 = (f64) sp10;
                    sp28 = (f64) sp18;
                    sp8 = 0;
                    spC = 0;
                    this->unk150->Emit(lit_666, *this->unk154, *((MKVector3 *) &sp40), *((MKVector3 *) &sp20), 3.0f, this->unk158->unk4, 1U, &this->unk168, M2C_ERROR(/* Unable to find stack arg 0x0 in block */), M2C_ERROR(/* Unable to find stack arg 0x4 in block */));
                }
                temp_r4_265 = this->unk160;
                if (temp_r4_265 != NULL) {
                    temp_r3_268 = this->unk154;
                    temp_r4_265->unk10 = M2C_FIELD(temp_r3_268, f64 *, 0);
                    temp_r4_265->unk18 = M2C_FIELD(temp_r3_268, f64 *, 8);
                    temp_r4_273 = temp_r4_265->unk3C;
                    if (temp_r4_273 != NULL) {
                        M2C_FIELD(temp_r4_273, f64 *, 0x10) = (f64) M2C_FIELD(temp_r3_268, f64 *, 0);
                        M2C_FIELD(temp_r4_273, f64 *, 0x18) = (f64) M2C_FIELD(temp_r3_268, f64 *, 8);
                    }
                    temp_f1_284 = MKRand_Float((int *) &gViewSeed, 500.0f, 600.0f);
                    temp_r3_285 = this->unk160;
                    temp_r3_285->unk38 = temp_f1_284;
                    temp_r3_287 = temp_r3_285->unk3C;
                    if (temp_r3_287 != NULL) {
                        M2C_FIELD(temp_r3_287, f32 *, 0x20) = temp_f1_284;
                        M2C_FIELD(temp_r3_287, f32 *, 0x24) = (f32) (temp_f1_284 * temp_f1_284);
                        M2C_FIELD(temp_r3_287, f32 *, 0x28) = (f32) (1.0f / temp_f1_284);
                        M2C_FIELD(temp_r3_287, f32 *, 0x2C) = (f32) (1.0f / M2C_FIELD(temp_r3_287, f32 *, 0x24));
                    }
                }
            }
        }
    }
}

#if 0 // DRAFT: identifier 'IceSquirt::Resolve()' redeclared was declared as: 'float ()' now declared as: 'void ()'
void IceSquirt::Resolve() {
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
    ManagedLight *temp_r4_352;

    KDPropEx::Resolve();
    sp20 = 0.0f;
    sp30 = 0.0f;
    sp8 = 0.5f;
    spC = 0.5f;
    sp10 = 1.0f;
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
    this->unk160 = (ManagedLight *) ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->AllocManagedLight(*((MKVector3 *) &sp58), *((MKVector3 *) &sp48), *((MKVector4 *) &sp38), 500.0f, lit_650, lit_651);
    temp_r4_352 = this->unk160;
    if (temp_r4_352 != NULL) {
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->EnableLight(temp_r4_352, 0U);
    }
}
#endif

s32 IceSquirt::LoadDone() {
    Projectile::LoadDone();
    this->unk150 = checked_cast<LiquidFX *, MKProp>(gMK->CreateProp("LiquidIceFX"));
}

void IceSquirt::Init() {
    Projectile::Init();
    SetDefaults();
}

void IceSquirt::Reset() {
    Projectile::Reset();
    SetDefaults();
}

void IceSquirt::SetDefaults() {
    this->unk154 = NULL;
    this->unk158 = NULL;
    this->unk15C = 0;
}

void *IceSquirt::CreateInstance() {
    void *temp_r3_444;

    if ((MKPropDescriptor *) pIceSquirtDescriptor != NULL) {
        temp_r3_444 = pIceSquirtDescriptor->CreateInstance();
        if (temp_r3_444 != NULL) {
            M2C_FIELD(M2C_FIELD(temp_r3_444, void **, 0x44), M2C_UNK (**)(), 0x20)();
            return temp_r3_444;
        }
    }
    return NULL;
}

void IceSquirtDescriptor::LoadDone() {
    GamePropDescriptor::LoadDone();
    pIceSquirtDescriptor = (MKPropDescriptor *) this;
}

void IceSquirtDescriptor::Deinit() {
    pIceSquirtDescriptor = NULL;
    KDPropExDescriptor::Deinit();
}
