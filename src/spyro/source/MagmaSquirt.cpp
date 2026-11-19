#include "spyro/source/MagmaSquirt.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKParticleSystem.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKPtrList.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "common/Source/Texture.h"
#include "spyro/source/CrashFirePS.h"
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
#include "spyro/source/KDRandom.h"
#include "spyro/source/Tools.h"
#include <m2c_macros.h>

extern MKSceneManager *gMK;
extern s32 gViewSeed;
extern M2C_UNK gb;
extern MKPropDescriptor *pMagmaSquirtDescriptor;

static s32 lit_650 = 0;
static u8 lit_651 = 1;
static s32 lit_664 = 1;

void MagmaSquirt::Deinit() {
    ManagedLight *temp_r4_51;

    temp_r4_51 = this->unk160;
    if (temp_r4_51 != NULL) {
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->FreeManagedLight(temp_r4_51);
    }
    Projectile::Deinit();
}

void MagmaSquirt::FireBurstEnd() {
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

void MagmaSquirt::FireBurst(MKVector3 *arg0, MKVector3 *arg1, int arg2, int arg3) {
    s32 sp8;
    MKVector3 *temp_r4_127;
    ManagedLight *temp_r3_128;
    ManagedLight *temp_r4_119;
    void *temp_r3_133;

    this->unk15C = 1;
    this->unk154 = arg0;
    this->unk158 = arg1;
    this->unk164 = arg2;
    this->unk168 = arg3;
    Enable();
    temp_r4_119 = this->unk160;
    if (temp_r4_119 != NULL) {
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->EnableLight(temp_r4_119, 1U);
        temp_r4_127 = this->unk154;
        temp_r3_128 = this->unk160;
        temp_r3_128->unk10 = M2C_FIELD(temp_r4_127, f64 *, 0);
        temp_r3_128->unk18 = M2C_FIELD(temp_r4_127, f64 *, 8);
        temp_r3_133 = temp_r3_128->unk3C;
        if (temp_r3_133 != NULL) {
            M2C_FIELD(temp_r3_133, f64 *, 0x10) = (f64) M2C_FIELD(temp_r4_127, f64 *, 0);
            M2C_FIELD(temp_r3_133, f64 *, 0x18) = (f64) M2C_FIELD(temp_r4_127, f64 *, 8);
        }
    }
    sp8 = -1;
    this->unk170.Init((MKProp *) this, 1, 0, 0, 0, 0, 0, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
}

void MagmaSquirt::Fire(const MKVector3 &arg0, const MKVector3 &arg1, MKProp *arg2, int arg3, int arg4) {
    Disable();
}

void MagmaSquirt::Collided(MKCollisionResult &arg0) {
    Disable();
}

void MagmaSquirt::Draw() {

}

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to
void MagmaSquirt::Update() {
    f64 sp140;
    f64 sp138;
    MKVector3 sp128;
    f64 sp120;
    f64 sp118;
    f64 sp110;
    f64 sp108;
    f64 sp100;
    f64 spF8;
    f64 spF0;
    f64 spE8;
    MKVector3 spD8;
    f64 spD0;
    f64 spC8;
    f64 spC0;
    f64 spB8;
    f64 spB0;
    f64 spA8;
    f64 spA0;
    f64 sp98;
    f32 sp90;
    f32 sp8C;
    f32 sp88;
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    f32 sp70;
    f64 sp68;
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
    f32 sp14;
    f32 sp10;
    s32 spC;
    s32 sp8;
    MKVector3 *temp_r3_423;
    MKVector3 *temp_r4_213;
    ManagedLight *temp_r3_440;
    ManagedLight *temp_r4_420;
    f32 temp_f1_439;
    f32 var_f3_367;
    f32 var_f4_300;
    f64 temp_f0_279;
    f64 temp_f0_387;
    f64 temp_f0_399;
    f64 temp_f1_306;
    f64 temp_f1_312;
    f64 temp_f1_316;
    s32 temp_r3_335;
    s32 var_r0_345;
    void *temp_r3_442;
    void *temp_r4_428;

    Projectile::Update();
    if ((u8) this->unk15C != 0) {
        temp_r4_213 = this->unk154;
        if ((temp_r4_213 != NULL) && ((MKVector3 *) this->unk158 != NULL)) {
            Tools_CalculateVelocity(sp128, *temp_r4_213, 2000.0f, -1500.0f);
            sp88 = 0.5f;
            sp8C = 0.5f;
            sp90 = 1.5f;
            sp138 = M2C_BITWISE(f64, sp128);
            sp140 = (f64) sp128.unk8;
            sp118 = (f64) sp88;
            sp120 = (f64) sp90;
            sp8 = this->unk164;
            spC = this->unk168;
            this->unk150->Emit(lit_664, *this->unk154, *((MKVector3 *) &sp138), *((MKVector3 *) &sp118), 3.0f, this->unk158->unk4, 1U, &this->unk170, M2C_ERROR(/* Unable to find stack arg 0x0 in block */), M2C_ERROR(/* Unable to find stack arg 0x4 in block */));
            sp78 = -1.0f;
            sp7C = -1.0f;
            sp80 = -1.0f;
            spB8 = (f64) sp78;
            spC0 = (f64) sp80;
            sp68 = spB8 * 5.139208556e-315;
            sp60 = 1.0f;
            sp58 = 1.0f;
            sp5C = 1.0f;
            sp70 = (f32) spC0 * 0.125f;
            sp98 = (f64) sp58;
            spC8 = sp68;
            spD0 = (f64) sp70;
            spA0 = (f64) sp60;
            temp_f0_279 = sp98 * 5.139208556e-315;
            sp48 = temp_f0_279;
            spA8 = temp_f0_279;
            sp50 = (f32) spA0 * 0.125f;
            spB0 = (f64) sp50;
            KDRand_Vector(spD8, *((MKVector3 *) &spC8));
            var_f4_300 = ((f32) sp140 * (f32) sp140) + (((f32) sp138 * (f32) sp138) + ((*(f32 *) ((u8 *) &sp138 + 0x4)) * (*(f32 *) ((u8 *) &sp138 + 0x4))));
            if (var_f4_300 > 1e-12f) {
                if (var_f4_300 > 0.0f) {
                    temp_f1_306 = __frsqrte(var_f4_300);
                    temp_f1_312 = 0.5 * temp_f1_306 * -(((f64) var_f4_300 * (temp_f1_306 * temp_f1_306)) - 3.0);
                    temp_f1_316 = 0.5 * temp_f1_312 * -(((f64) var_f4_300 * (temp_f1_312 * temp_f1_312)) - 3.0);
                    var_f4_300 = (f32) ((f64) var_f4_300 * (0.5 * temp_f1_316 * -(((f64) var_f4_300 * (temp_f1_316 * temp_f1_316)) - 3.0)));
                } else if (var_f4_300 < M2C_BITWISE(f32, 0.0)) {
                    var_f4_300 = __float_nan;
                } else {
                    sp10 = var_f4_300;
                    temp_r3_335 = M2C_BITWISE(s32, sp10) & 0x7F800000;
                    switch (temp_r3_335) {          /* irregular */
                    case 0x7F800000:
                        if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                            var_r0_345 = 1;
                        } else {
                            var_r0_345 = 2;
                        }
                        break;
                    case 0x0:
                        if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                            var_r0_345 = 5;
                        } else {
                            var_r0_345 = 3;
                        }
                        break;
                    default:
                        var_r0_345 = 4;
                        break;
                    }
                    if (var_r0_345 == 1) {
                        var_f4_300 = __float_nan;
                    }
                }
                var_f3_367 = 1.0f / var_f4_300;
            } else {
                var_f3_367 = 0.0f;
            }
            sp18 = (f32) sp138 * var_f3_367;
            sp1C = (*(f32 *) ((u8 *) &sp138 + 0x4)) * var_f3_367;
            sp20 = (f32) sp140 * var_f3_367;
            spE8 = (f64) sp18;
            spF0 = (f64) sp20;
            temp_f0_387 = (f64) sp18 + M2C_BITWISE(f64, spD8);
            sp38 = temp_f0_387;
            spF8 = temp_f0_387;
            sp40 = (f32) spF0 + spD8.unk8;
            sp100 = (f64) sp40;
            temp_f0_399 = temp_f0_387 * 5.65176949e-315;
            sp28 = temp_f0_399;
            sp108 = temp_f0_399;
            sp30 = (f32) sp100 * 700.0f;
            sp110 = (f64) sp30;
            sp14 = MKRand_Float((int *) &gViewSeed, 5.0f, 7.0f);
            ((CrashFirePS *) (M2C_FIELD(&gb, CrashFirePS **, 0x68)))->Emit(*this->unk154, *((MKVector3 *) &sp108), sp14);
            temp_r4_420 = this->unk160;
            if (temp_r4_420 != NULL) {
                temp_r3_423 = this->unk154;
                temp_r4_420->unk10 = M2C_FIELD(temp_r3_423, f64 *, 0);
                temp_r4_420->unk18 = M2C_FIELD(temp_r3_423, f64 *, 8);
                temp_r4_428 = temp_r4_420->unk3C;
                if (temp_r4_428 != NULL) {
                    M2C_FIELD(temp_r4_428, f64 *, 0x10) = (f64) M2C_FIELD(temp_r3_423, f64 *, 0);
                    M2C_FIELD(temp_r4_428, f64 *, 0x18) = (f64) M2C_FIELD(temp_r3_423, f64 *, 8);
                }
                temp_f1_439 = MKRand_Float((int *) &gViewSeed, 500.0f, 600.0f);
                temp_r3_440 = this->unk160;
                temp_r3_440->unk38 = temp_f1_439;
                temp_r3_442 = temp_r3_440->unk3C;
                if (temp_r3_442 != NULL) {
                    M2C_FIELD(temp_r3_442, f32 *, 0x20) = temp_f1_439;
                    M2C_FIELD(temp_r3_442, f32 *, 0x24) = (f32) (temp_f1_439 * temp_f1_439);
                    M2C_FIELD(temp_r3_442, f32 *, 0x28) = (f32) (1.0f / temp_f1_439);
                    M2C_FIELD(temp_r3_442, f32 *, 0x2C) = (f32) (1.0f / M2C_FIELD(temp_r3_442, f32 *, 0x24));
                }
            }
        }
    }
}
#endif

void MagmaSquirt::Resolve() {
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
    ManagedLight *temp_r4_511;

    KDPropEx::Resolve();
    sp20 = 0.0f;
    sp30 = 0.0f;
    sp8 = 1.0f;
    spC = 0.7f;
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
    this->unk160 = (ManagedLight *) ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->AllocManagedLight(*((MKVector3 *) &sp58), *((MKVector3 *) &sp48), *((MKVector4 *) &sp38), 500.0f, lit_650, lit_651);
    temp_r4_511 = this->unk160;
    if (temp_r4_511 != NULL) {
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->EnableLight(temp_r4_511, 0U);
    }
}

void MagmaSquirt::LoadDone() {
    Projectile::LoadDone();
    this->unk150 = checked_cast<LiquidFX *, MKProp>(gMK->CreateProp("MoltenMetalFX"));
}

void MagmaSquirt::Init() {
    Projectile::Init();
    SetDefaults();
}

void MagmaSquirt::Reset() {
    Projectile::Reset();
    SetDefaults();
}

void MagmaSquirt::SetDefaults() {
    this->unk154 = NULL;
    this->unk158 = NULL;
    this->unk15C = 0;
}

void *MagmaSquirt::CreateInstance() {
    void *temp_r3_603;

    if ((MKPropDescriptor *) pMagmaSquirtDescriptor != NULL) {
        temp_r3_603 = pMagmaSquirtDescriptor->CreateInstance();
        if (temp_r3_603 != NULL) {
            M2C_FIELD(M2C_FIELD(temp_r3_603, void **, 0x44), M2C_UNK (**)(), 0x20)();
            return temp_r3_603;
        }
    }
    return NULL;
}

void MagmaSquirtDescriptor::LoadDone() {
    GamePropDescriptor::LoadDone();
    pMagmaSquirtDescriptor = (MKPropDescriptor *) this;
}

void MagmaSquirtDescriptor::Deinit() {
    pMagmaSquirtDescriptor = NULL;
    KDPropExDescriptor::Deinit();
}
