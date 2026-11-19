#include "spyro/source/IceExplosion.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "unplaced_templates.h"
#include "common/Source/StdMath.h"
#include <m2c_macros.h>

extern MKSceneManager *gMK;
extern s32 gViewSeed;

void IceExplosion::Trigger(const MKVector3 &arg0, float arg1) {
    f64 temp_f1_52;
    void *temp_r29_67;
    void *temp_r29_97;
    void *temp_r30_55;
    void *temp_r3_51;
    void *temp_r3_60;
    void *temp_r3_64;
    void *temp_r3_90;
    void *temp_r3_94;

    temp_r3_51 = checked_cast<IceExplosionDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    temp_f1_52 = M2C_FIELD(&arg0, f64 *, 0);
    temp_r30_55 = temp_r3_51;
    this->unk50 = temp_f1_52;
    this->unk58 = M2C_FIELD(&arg0, f64 *, 8);
    this->unk60 = arg1;
    this->unk4C = 1;
    temp_r3_60 = M2C_FIELD(temp_r3_51, void **, 0x60);
    temp_r3_64 = M2C_FIELD(M2C_FIELD(temp_r3_60, void **, 0x44), void *(**)(void *, f64), 0x3C)(temp_r3_60, temp_f1_52);
    if (temp_r3_64 != NULL) {
        temp_r29_67 = M2C_FIELD(temp_r3_64, void **, 0x2C);
        M2C_FIELD(temp_r3_64, f64 *, 0) = (f64) M2C_FIELD(&arg0, f64 *, 0);
        M2C_FIELD(temp_r3_64, f64 *, 8) = (f64) M2C_FIELD(&arg0, f64 *, 8);
        M2C_FIELD(temp_r3_64, f32 *, 0x20) = 0.0f;
        M2C_FIELD(temp_r3_64, f32 *, 0x28) = 0.0f;
        M2C_FIELD(temp_r3_64, f32 *, 0x24) = MKRand_Float((int *) &gViewSeed, 0.0f, 6.2831855f);
        M2C_FIELD(temp_r29_67, f32 *, 0) = 0.0f;
        M2C_FIELD(temp_r29_67, f32 *, 4) = 0.0f;
        M2C_FIELD(temp_r29_67, f32 *, 8) = 0.0f;
        M2C_FIELD(temp_r29_67, f32 *, 0x18) = arg1;
        M2C_FIELD(temp_r29_67, f32 *, 0x10) = 6.2831855f;
        M2C_FIELD(temp_r29_67, f32 *, 0x14) = (f32) M2C_FIELD(M2C_FIELD(temp_r30_55, void **, 0x60), f32 *, 0xF4);
    }
    temp_r3_90 = M2C_FIELD(temp_r30_55, void **, 0x64);
    temp_r3_94 = M2C_FIELD(M2C_FIELD(temp_r3_90, void **, 0x44), void *(**)(void *), 0x3C)(temp_r3_90);
    if (temp_r3_94 != NULL) {
        temp_r29_97 = M2C_FIELD(temp_r3_94, void **, 0x2C);
        M2C_FIELD(temp_r3_94, f64 *, 0) = (f64) M2C_FIELD(&arg0, f64 *, 0);
        M2C_FIELD(temp_r3_94, f64 *, 8) = (f64) M2C_FIELD(&arg0, f64 *, 8);
        M2C_FIELD(temp_r3_94, f32 *, 0x20) = 0.0f;
        M2C_FIELD(temp_r3_94, f32 *, 0x28) = 0.0f;
        M2C_FIELD(temp_r3_94, f32 *, 0x24) = MKRand_Float((int *) &gViewSeed, 0.0f, 6.2831855f);
        M2C_FIELD(temp_r29_97, f32 *, 0) = 0.0f;
        M2C_FIELD(temp_r29_97, f32 *, 4) = 0.0f;
        M2C_FIELD(temp_r29_97, f32 *, 8) = 0.0f;
        M2C_FIELD(temp_r29_97, f32 *, 0x18) = arg1;
        M2C_FIELD(temp_r29_97, f32 *, 0x10) = 6.2831855f;
        M2C_FIELD(temp_r29_97, f32 *, 0x14) = (f32) M2C_FIELD(M2C_FIELD(temp_r30_55, void **, 0x64), f32 *, 0xF4);
    }
}

void IceExplosion::Draw() {

}

void *IceExplosion::Update() {

}

void IceExplosionDescriptor::Init() {
    MKPropDescriptor::Init();
    this->unk60 = NULL;
    gMK->CreatePropDeferred("IceExplosionFlashPS", &this->unk60);
    gMK->CreatePropDeferred("IceExplosionShockPS", &this->unk64);
}
