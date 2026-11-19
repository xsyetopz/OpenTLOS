#include "spyro/source/IceExplosion.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKProp.h"
#include "unplaced_templates.h"
#include "common/Source/StdMath.h"
#include <m2c_macros.h>

extern MKSceneManager *gMK;
extern s32 gViewSeed;
#if 0 // DRAFT: function call 'MKRand_Float(long *, float, float)' does not match
static s8 lit_stringBase0[0x28] = {
    0x49,
    0x63,
    0x65,
    0x45,
    0x78,
    0x70,
    0x6C,
    0x6F,
    0x73,
    0x69,
    0x6F,
    0x6E,
    0x46,
    0x6C,
    0x61,
    0x73,
    0x68,
    0x50,
    0x53,
    0,
    0x49,
    0x63,
    0x65,
    0x45,
    0x78,
    0x70,
    0x6C,
    0x6F,
    0x73,
    0x69,
    0x6F,
    0x6E,
    0x53,
    0x68,
    0x6F,
    0x63,
    0x6B,
    0x50,
    0x53,
    0,
}; /* const */

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
        M2C_FIELD(temp_r3_64, f32 *, 0x24) = MKRand_Float(&gViewSeed, 0.0f, 6.2831855f);
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
        M2C_FIELD(temp_r3_94, f32 *, 0x24) = MKRand_Float(&gViewSeed, 0.0f, 6.2831855f);
        M2C_FIELD(temp_r29_97, f32 *, 0) = 0.0f;
        M2C_FIELD(temp_r29_97, f32 *, 4) = 0.0f;
        M2C_FIELD(temp_r29_97, f32 *, 8) = 0.0f;
        M2C_FIELD(temp_r29_97, f32 *, 0x18) = arg1;
        M2C_FIELD(temp_r29_97, f32 *, 0x10) = 6.2831855f;
        M2C_FIELD(temp_r29_97, f32 *, 0x14) = (f32) M2C_FIELD(M2C_FIELD(temp_r30_55, void **, 0x64), f32 *, 0xF4);
    }
}
#endif

void IceExplosion::Draw() {

}

void IceExplosion::Update() {

}

#if 0 // DRAFT: illegal implicit conversion from 'signed char[40]' to
void IceExplosionDescriptor::Init() {
    MKPropDescriptor::Init();
    this->unk60 = NULL;
    gMK->CreatePropDeferred(lit_stringBase0, &this->unk60);
    gMK->CreatePropDeferred(&lit_stringBase0[0x14], &this->unk64);
}
#endif

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<IceExplosionDescriptor *, MKPropDescriptor>(MKPropDescriptor *arg0) {

}
#endif
