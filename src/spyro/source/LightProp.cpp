#include "spyro/source/LightProp.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/LightManager.h"
#include "spyro/source/ManagedLight.h"
#include "unplaced_templates.h"
#include "spyro/source/Tools.h"
#include <m2c_macros.h>

extern M2C_UNK gb;

static s32 lit_589 = 0;
static u8 lit_590 = 1;

void LightProp::Deinit() {
    ManagedLight *temp_r4_44;

    temp_r4_44 = this->unkC8;
    if (temp_r4_44 != NULL) {
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->FreeManagedLight(temp_r4_44);
    }
    GameProp::Deinit();
}

void LightProp::SetOrientation(Matrix *arg0) {
    MKVector3 sp28;
    f64 sp20;
    f64 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    ManagedLight *temp_r3_78;
    ManagedLight *temp_r3_94;
    void *temp_r3_102;
    void *temp_r3_83;

    MKModel_SetWorldMatrix(this->unk4, *arg0);
    if ((ManagedLight *) this->unkC8 != NULL) {
        MKModel_CalculateRefPointWorldPosition(this->unk4, this->unkE0, &sp28);
        temp_r3_78 = this->unkC8;
        *(MKVector3 *) &temp_r3_78->unk10 = sp28;
        temp_r3_83 = temp_r3_78->unk3C;
        if (temp_r3_83 != NULL) {
            M2C_FIELD(temp_r3_83, MKVector3 *, 0x10) = sp28;
        }
        sp8 = 0.0f;
        temp_r3_94 = this->unkC8;
        spC = 0.0f;
        sp10 = 0.0f;
        sp14 = 1.0f;
        temp_r3_94->unk20 = (f64) sp8;
        temp_r3_94->unk28 = (f64) sp10;
        temp_r3_102 = temp_r3_94->unk3C;
        sp18 = (f64) sp8;
        sp20 = (f64) sp10;
        if (temp_r3_102 != NULL) {
            M2C_FIELD(temp_r3_102, f64 *, 0) = (f64) sp8;
            M2C_FIELD(temp_r3_102, f64 *, 8) = (f64) sp10;
        }
    }
}

#if 0 // DRAFT: illegal explicit conversion from 'MKVector4' to 'double'
void *LightProp::Update() {
    f64 sp20;
    f64 sp18;
    MKVector4 sp8;
    ManagedLight *temp_r3_142;
    ManagedLight *temp_r4_125;
    f64 temp_f1_138;
    void *temp_r3_145;

    temp_r4_125 = this->unkC8;
    if (temp_r4_125 != NULL) {
        sp18 = temp_r4_125->unk20;
        sp20 = temp_r4_125->unk28;
        KDMath_Smooth<MKVector4>(sp8, *((MKVector4 *) &sp18), 0.25f, 1.0f);
        temp_f1_138 = M2C_BITWISE(f64, sp8);
        sp18 = temp_f1_138;
        sp20 = (f64) sp8.unk8;
        temp_r3_142 = this->unkC8;
        temp_r3_142->unk20 = temp_f1_138;
        temp_r3_142->unk28 = (f64) sp8.unk8;
        temp_r3_145 = temp_r3_142->unk3C;
        if (temp_r3_145 != NULL) {
            M2C_FIELD(temp_r3_145, f64 *, 0) = sp18;
            M2C_FIELD(temp_r3_145, f64 *, 8) = sp20;
        }
    }
}
#endif

s32 LightProp::LoadDone() {
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

    GameProp::LoadDone();
    sp20 = 0.0f;
    sp30 = 0.0f;
    sp8 = 1.0f;
    spC = 0.75f;
    sp10 = 0.2f;
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
    this->unkC8 = (ManagedLight *) (((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->AllocManagedLight(*((MKVector3 *) &sp58), *((MKVector3 *) &sp48), *((MKVector4 *) &sp38), 1500.0f, lit_589, lit_590));
    ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->EnableLight(this->unkC8, 1U);
    this->unkE0 = (s32) Tools_GetMatchingRefPointIndex(this->unk4, "fxemit0");
}

void LightProp::Init() {
    GameProp::Init();
    this->unkC8 = NULL;
    M2C_FIELD(this, f32 *, 0xD0) = 1.0f;
    this->unkD4 = 0.75f;
    this->unkD8 = 0.2f;
    this->unkDC = 1.0f;
    this->unkE0 = -1;
}
