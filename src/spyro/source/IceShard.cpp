#include "spyro/source/IceShard.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKPtrList.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
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
#include "spyro/source/Projectile.h"
#include "spyro/source/KDMath.h"
#include <m2c_macros.h>

extern MKPropDescriptor *pIceShardDescriptor;

void *IceShard::Update() {
    Matrix sp90;
    Matrix sp50;
    f64 sp40;                                       /* compiler-managed */
    f64 sp38;                                       /* compiler-managed */
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 var_f4_70;
    f32 var_f5_91;
    f64 temp_f1_102;
    f64 temp_f1_106;
    f64 temp_f1_96;
    s32 temp_r3_125;
    s32 var_r0_135;

    Projectile::Update();
    if (MKModel_GetAttachment(this->unk4) != NULL) {
        MKModel_GetWorldMatrixWithAttachment(this->unk4, &sp90);
    } else {
        M2C_STRUCT_COPY((s32) &sp50.unk3C + 4, MKModel_GetWorldMatrix(this->unk4) - 4 + 4, 0x40);
    }
    var_f4_70 = 0.0f;
    sp20 = 0.0f;
    sp18 = 0.0f;
    sp1C = 1.0f;
    sp30 = (f64) sp20;
    sp28 = (f64) sp18;
    sp38 = this->unkC8;
    sp40 = this->unkD0;
    var_f5_91 = ((f32) sp40 * (f32) sp40) + (((f32) sp38 * (f32) sp38) + ((*(f32 *) ((u8 *) &sp30 + 0xc)) * (*(f32 *) ((u8 *) &sp30 + 0xc))));
    if (var_f5_91 > 0.000001f) {
        if (var_f5_91 > 0.0f) {
            temp_f1_96 = __frsqrte(var_f5_91);
            temp_f1_102 = 0.5 * temp_f1_96 * -(((f64) var_f5_91 * (temp_f1_96 * temp_f1_96)) - 3.0);
            temp_f1_106 = 0.5 * temp_f1_102 * -(((f64) var_f5_91 * (temp_f1_102 * temp_f1_102)) - 3.0);
            var_f5_91 = (f32) ((f64) var_f5_91 * (0.5 * temp_f1_106 * -(((f64) var_f5_91 * (temp_f1_106 * temp_f1_106)) - 3.0)));
        } else if (var_f5_91 < M2C_BITWISE(f32, 0.0)) {
            var_f5_91 = __float_nan;
        } else {
            sp10 = var_f5_91;
            temp_r3_125 = M2C_BITWISE(s32, sp10) & 0x7F800000;
            switch (temp_r3_125) {                  /* irregular */
            case 0x7F800000:
                if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                    var_r0_135 = 1;
                } else {
                    var_r0_135 = 2;
                }
                break;
            case 0x0:
                if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                    var_r0_135 = 5;
                } else {
                    var_r0_135 = 3;
                }
                break;
            default:
                var_r0_135 = 4;
                break;
            }
            if (var_r0_135 == 1) {
                var_f5_91 = __float_nan;
            }
        }
        var_f4_70 = 1.0f / var_f5_91;
    } else {
        var_f5_91 = 0.0f;
    }
    sp38 = (f32) sp38 * var_f4_70;
    (*(f32 *) ((u8 *) &sp30 + 0xc)) *= var_f4_70;
    sp40 = (f32) sp40 * var_f4_70;
    if (var_f5_91 != 0.0f) {
        KDMath_BuildMatrixFromFwd(&sp50, *((MKVector3 *) &sp38), (MKVector3 *) &sp28);
        sp50.unk30 = sp90.unk30;
        sp50.unk34 = sp90.unk34;
        sp50.unk38 = sp90.unk38;
        sp50.unk3C = 1.0f;
        MKModel_SetWorldMatrix(this->unk4, sp50);
    }
}

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'MKCollisionResult'
void IceShard::Collided(MKCollisionResult &arg0) {
    s8 sp89;
    s8 sp88;
    s32 sp84;
    f32 sp80;
    s32 sp7C;
    s8 sp7A;
    s8 sp79;
    s8 sp78;
    f64 sp70;                                       /* compiler-managed */
    f64 sp68;                                       /* compiler-managed */
    MKProp *sp64;
    s32 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    s32 sp3C;
    s32 sp38;
    f64 sp30;
    f64 sp28;
    MKVector3 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    MKProp *temp_r4_214;
    void *temp_r3_260;
    void *var_r3_263;

    Projectile::Collided(arg0);
    sp3C = 0;
    temp_r4_214 = this->unk130;
    sp10 = 0.0f;
    sp8 = 0.0f;
    spC = 0.0f;
    sp30 = (f64) sp10;
    sp28 = (f64) sp8;
    sp38 = 7;
    sp60 = 1;
    sp64 = temp_r4_214;
    sp40 = (f64) sp8;
    sp48 = (f64) sp10;
    sp78 = 0;
    sp84 = 2;
    sp80 = 10.0f;
    sp79 = 0;
    sp7A = 1;
    sp7C = -1;
    sp50 = M2C_FIELD(&MKVector3::one, f64 *, 0);
    sp58 = M2C_FIELD(&MKVector3::one, f64 *, 8);
    sp88 = 0;
    if (temp_r4_214 != NULL) {
        sp18 = temp_r4_214->GetPos();
        *(MKVector3 *) &sp68 = sp18;
    } else {
        sp68 = 0.0f;
        (*(f32 *) ((u8 *) &sp64 + 0x8)) = 0.0f;
        sp70 = 0.0f;
    }
    sp89 = 0;
    if (((u8) arg0.unk50 != 0) && (temp_r3_260 = arg0.unk48, ((temp_r3_260 == NULL) == 0)) && (var_r3_263 = M2C_FIELD(temp_r3_260, void **, 8), ((var_r3_263 == NULL) == 0))) {

    } else {
        var_r3_263 = NULL;
    }
    if (var_r3_263 != NULL) {
        M2C_FIELD(M2C_FIELD(var_r3_263, void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp38);
    }
    Disable();
}
#endif

s32 IceShard::LoadDone() {
    Projectile::LoadDone();
}

void *IceShard::CreateInstance() {
    void *temp_r3_313;

    if ((MKPropDescriptor *) pIceShardDescriptor != NULL) {
        temp_r3_313 = pIceShardDescriptor->CreateInstance();
        if (temp_r3_313 != NULL) {
            M2C_FIELD(M2C_FIELD(temp_r3_313, void **, 0x44), M2C_UNK (**)(), 0x20)();
            return temp_r3_313;
        }
    }
    return NULL;
}

void IceShardDescriptor::LoadDone() {
    GamePropDescriptor::LoadDone();
    pIceShardDescriptor = (MKPropDescriptor *) this;
}

void IceShardDescriptor::Deinit() {
    pIceShardDescriptor = NULL;
    KDPropExDescriptor::Deinit();
}
