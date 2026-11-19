#include "spyro/source/CynderElecAttack.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
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
#include "spyro/source/EnergyBeam.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/KDMatrixProperty.h"
#include "spyro/source/KDMatrixRefProperty.h"
#include "spyro/source/KDPositionProperty.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDProperty.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/KDSpline.h"
#include "spyro/source/Level.h"
#include "spyro/source/LightManager.h"
#include "spyro/source/ManagedLight.h"
#include "spyro/source/Projectile.h"
#include "unplaced_templates.h"
#include "common/Source/StdMath.h"
#include <m2c_macros.h>

extern MKSceneManager *gMK;
extern s32 gViewSeed;
extern M2C_UNK gb;
extern MKPropDescriptor *pCynderElecAttackDescriptor;

static s32 lit_611 = 0;
static u8 lit_612 = 1;

#if 0 // DRAFT: ')' expected
void CynderElecAttack::Deinit() {
    ManagedLight *temp_r4_51;

    temp_r4_51 = this->unk15C;
    if (temp_r4_51 != NULL) {
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->FreeManagedLight(temp_r4_51);
    }
    if ((EnergyBeam::Beam *) this->unk160 != NULL) {
        ((EnergyBeam *) (M2C_FIELD(checked_cast<CynderElecAttackDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), EnergyBeam **, 0xF0)))->FreeEnergyBeam(this->unk160);
        this->unk160 = NULL;
    }
    Projectile::Deinit();
}
#endif

#if 0 // DRAFT: ')' expected
void CynderElecAttack::FireBurstEnd() {
    ManagedLight *temp_r4_91;

    this->unk158 = 0;
    this->unk150 = NULL;
    this->unk154 = NULL;
    temp_r4_91 = this->unk15C;
    if (temp_r4_91 != NULL) {
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->EnableLight(temp_r4_91, 0U);
    }
    if ((EnergyBeam::Beam *) this->unk160 != NULL) {
        ((EnergyBeam *) (M2C_FIELD(checked_cast<CynderElecAttackDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), EnergyBeam **, 0xF0)))->FreeEnergyBeam(this->unk160);
        this->unk160 = NULL;
    }
    Disable();
}
#endif

#if 0 // DRAFT: ')' expected
void CynderElecAttack::FireBurst(MKVector3 *arg0, MKVector3 *arg1, int arg2, int arg3) {
    MKVector3 *temp_r4_149;
    ManagedLight *temp_r3_150;
    ManagedLight *temp_r4_141;
    void *temp_r3_155;

    this->unk158 = 1;
    this->unk150 = arg0;
    this->unk154 = arg1;
    Enable();
    temp_r4_141 = this->unk15C;
    if (temp_r4_141 != NULL) {
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->EnableLight(temp_r4_141, 1U);
        temp_r4_149 = this->unk150;
        temp_r3_150 = this->unk15C;
        temp_r3_150->unk10 = M2C_FIELD(temp_r4_149, f64 *, 0);
        temp_r3_150->unk18 = M2C_FIELD(temp_r4_149, f64 *, 8);
        temp_r3_155 = temp_r3_150->unk3C;
        if (temp_r3_155 != NULL) {
            M2C_FIELD(temp_r3_155, f64 *, 0x10) = (f64) M2C_FIELD(temp_r4_149, f64 *, 0);
            M2C_FIELD(temp_r3_155, f64 *, 0x18) = (f64) M2C_FIELD(temp_r4_149, f64 *, 8);
        }
    }
    if ((EnergyBeam::Beam *) this->unk160 != NULL) {
        ((EnergyBeam *) (M2C_FIELD(checked_cast<CynderElecAttackDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), EnergyBeam **, 0xF0)))->FreeEnergyBeam(this->unk160);
        this->unk160 = NULL;
    }
    ((EnergyBeam *) (M2C_FIELD(checked_cast<CynderElecAttackDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), EnergyBeam **, 0xF0)))->SpawnEnergyBeam(arg0, arg1, 0.1f);
    this->unk160 = M2C_ERROR(/* Read from unset register $r3 */);
}
#endif

void CynderElecAttack::Fire(const MKVector3 &arg0, const MKVector3 &arg1, MKProp *arg2, int arg3, int arg4) {
    Disable();
}

void CynderElecAttack::Collided(MKCollisionResult &arg0) {
    Disable();
}

void CynderElecAttack::Draw() {

}

void *CynderElecAttack::Update() {
    MKVector3 *temp_r3_239;
    ManagedLight *temp_r3_264;
    ManagedLight *temp_r4_245;
    f32 temp_f1_263;
    void *temp_r3_266;
    void *temp_r4_252;

    Projectile::Update();
    if ((u8) this->unk158 != 0) {
        temp_r3_239 = this->unk150;
        if ((temp_r3_239 != NULL) && ((MKVector3 *) this->unk154 != NULL)) {
            temp_r4_245 = this->unk15C;
            if (temp_r4_245 != NULL) {
                temp_r4_245->unk10 = M2C_FIELD(temp_r3_239, f64 *, 0);
                temp_r4_245->unk18 = M2C_FIELD(temp_r3_239, f64 *, 8);
                temp_r4_252 = temp_r4_245->unk3C;
                if (temp_r4_252 != NULL) {
                    M2C_FIELD(temp_r4_252, f64 *, 0x10) = (f64) M2C_FIELD(temp_r3_239, f64 *, 0);
                    M2C_FIELD(temp_r4_252, f64 *, 0x18) = (f64) M2C_FIELD(temp_r3_239, f64 *, 8);
                }
                temp_f1_263 = MKRand_Float((int *) &gViewSeed, 500.0f, 600.0f);
                temp_r3_264 = this->unk15C;
                temp_r3_264->unk38 = temp_f1_263;
                temp_r3_266 = temp_r3_264->unk3C;
                if (temp_r3_266 != NULL) {
                    M2C_FIELD(temp_r3_266, f32 *, 0x20) = temp_f1_263;
                    M2C_FIELD(temp_r3_266, f32 *, 0x24) = (f32) (temp_f1_263 * temp_f1_263);
                    M2C_FIELD(temp_r3_266, f32 *, 0x28) = (f32) (1.0f / temp_f1_263);
                    M2C_FIELD(temp_r3_266, f32 *, 0x2C) = (f32) (1.0f / M2C_FIELD(temp_r3_266, f32 *, 0x24));
                }
            }
        }
    }
}

f32 CynderElecAttack::Resolve() {
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
    ManagedLight *temp_r4_330;

    KDPropEx::Resolve();
    sp20 = 0.0f;
    sp30 = 0.0f;
    sp8 = 1.0f;
    spC = 0.0f;
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
    this->unk15C = (ManagedLight *) (((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->AllocManagedLight(*((MKVector3 *) &sp58), *((MKVector3 *) &sp48), *((MKVector4 *) &sp38), 500.0f, lit_611, lit_612));
    temp_r4_330 = this->unk15C;
    if (temp_r4_330 != NULL) {
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->EnableLight(temp_r4_330, 0U);
    }
}

s32 CynderElecAttack::LoadDone() {
    Projectile::LoadDone();
}

void CynderElecAttack::Init() {
    Projectile::Init();
    SetDefaults();
}

void CynderElecAttack::Reset() {
    Projectile::Reset();
    SetDefaults();
}

void CynderElecAttack::SetDefaults() {
    this->unk150 = NULL;
    this->unk154 = NULL;
    this->unk158 = 0;
}

void *CynderElecAttack::CreateInstance() {
    void *temp_r3_413;

    if ((MKPropDescriptor *) pCynderElecAttackDescriptor != NULL) {
        temp_r3_413 = pCynderElecAttackDescriptor->CreateInstance();
        if (temp_r3_413 != NULL) {
            M2C_FIELD(M2C_FIELD(temp_r3_413, void **, 0x44), M2C_UNK (**)(), 0x20)();
            return temp_r3_413;
        }
    }
    return NULL;
}

void CynderElecAttackDescriptor::LoadDone() {
    GamePropDescriptor::LoadDone();
    pCynderElecAttackDescriptor = (MKPropDescriptor *) this;
    this->unkF0 = (long) (checked_cast<EnergyBeam *, MKProp>(gMK->CreateProp("EnergyBeam")));
}

void CynderElecAttackDescriptor::Deinit() {
    pCynderElecAttackDescriptor = NULL;
    KDPropExDescriptor::Deinit();
}
