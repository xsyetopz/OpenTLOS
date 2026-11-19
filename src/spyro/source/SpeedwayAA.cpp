#include "spyro/source/SpeedwayAA.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/Projectile.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKModel.h"
#include "spyro/source/KDMath.h"
#include <m2c_macros.h>

extern f32 gUpdateTimeDelta;
extern MKPropDescriptor *pSpeedwayAADescriptor;

void SpeedwayAA::Draw() {
    Projectile::Draw();
}

#if 0 // DRAFT: undefined identifier '__vptr'
void SpeedwayAA::Update() {
    MKCollisionResult sp130;
    Matrix spF0;
    Matrix spB0;
    void *spA8;
    s32 spA4;
    s32 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;                                       /* compiler-managed */
    f64 sp70;                                       /* compiler-managed */
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f32 sp48;
    f64 sp40;
    f32 sp38;
    f64 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    u8 sp18;
    void *sp14;
    f32 sp10;
    s32 sp8;
    MKProp *temp_r3_87;
    f32 var_f4_200;
    f32 var_f5_221;
    f64 temp_f0_136;
    f64 temp_f0_147;
    f64 temp_f1_130;
    f64 temp_f1_226;
    f64 temp_f1_232;
    f64 temp_f1_236;
    s32 temp_r3_255;
    s32 var_r0_265;
    u8 temp_r3_122;
    void *temp_r3_127;
    void *temp_r4_68;
    void *var_r4_84;

    if ((s32 *) this->unk138 != NULL) {
        temp_r4_68 = checked_cast<SpeedwayAADescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        sp8 = 1;
        ((KDSoundFader *) this->unk138)->Update(M2C_FIELD(temp_r4_68, s32 *, 0xE8), 1U, ((u8) this->unk14C >> 4U) & 1, (MKProp *) this, NULL, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    }
    spA4 = 0;
    var_r4_84 = NULL;
    spA8 = NULL;
    spA0 = 0x27;
    temp_r3_87 = this->unk130;
    if (temp_r3_87 != NULL) {
        M2C_FIELD(temp_r3_87->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&spA0);
        var_r4_84 = spA8;
    }
    sp14 = var_r4_84;
    if (var_r4_84 != NULL) {
        sp18 = M2C_FIELD(var_r4_84, u8 *, 4);
        M2C_FIELD(var_r4_84, u8 *, 4) = 0U;
    }
    this->unk140 -= gUpdateTimeDelta;
    if (this->unk140 <= 0.0f) {
        this->unk140 = 0.0f;
        Disable();
    } else {
        temp_r3_122 = this->unk14C;
        if (((temp_r3_122 >> 7U) & 1) && ((temp_r3_122 >> 6U) & 1)) {
            temp_r3_127 = this->unk8;
            temp_f1_130 = M2C_FIELD(temp_r3_127, f64 *, 0x30);
            sp90 = temp_f1_130;
            sp98 = M2C_FIELD(temp_r3_127, f64 *, 0x38);
            temp_f0_136 = this->unkC8 * (f64) gUpdateTimeDelta;
            sp40 = temp_f0_136;
            sp50 = temp_f0_136;
            sp48 = M2C_FIELD(this, f32 *, 0xD0) * gUpdateTimeDelta;
            sp58 = (f64) sp48;
            temp_f0_147 = temp_f1_130 + temp_f0_136;
            sp30 = temp_f0_147;
            sp80 = temp_f0_147;
            sp38 = (f32) sp98 + (f32) sp58;
            sp88 = (f64) sp38;
            if (MKCollision_SweepSphereCollide(*((MKVector3 *) &sp90), *((MKVector3 *) &sp80), 10.0f, &sp130, (MKCollisionMode) 7, 0) != 0) {
                Collided(sp130);
            } else {
                MKModel_SetPosition(this->unk4, *((MKVector3 *) &sp80));
            }
        }
    }
    if (MKModel_GetAttachment(this->unk4) != NULL) {
        MKModel_GetWorldMatrixWithAttachment(this->unk4, &spF0);
    } else {
        M2C_STRUCT_COPY((s32) &spB0.unk3C + 4, MKModel_GetWorldMatrix(this->unk4) - 4 + 4, 0x40);
    }
    var_f4_200 = 0.0f;
    sp28 = 0.0f;
    sp20 = 0.0f;
    sp24 = 1.0f;
    sp68 = (f64) sp28;
    sp60 = (f64) sp20;
    sp70 = this->unkC8;
    sp78 = this->unkD0;
    var_f5_221 = ((f32) sp78 * (f32) sp78) + (((f32) sp70 * (f32) sp70) + (unksp74 * unksp74));
    if (var_f5_221 > 0.000001f) {
        if (var_f5_221 > 0.0f) {
            temp_f1_226 = __frsqrte(var_f5_221);
            temp_f1_232 = 0.5 * temp_f1_226 * -(((f64) var_f5_221 * (temp_f1_226 * temp_f1_226)) - 3.0);
            temp_f1_236 = 0.5 * temp_f1_232 * -(((f64) var_f5_221 * (temp_f1_232 * temp_f1_232)) - 3.0);
            var_f5_221 = (f32) ((f64) var_f5_221 * (0.5 * temp_f1_236 * -(((f64) var_f5_221 * (temp_f1_236 * temp_f1_236)) - 3.0)));
        } else if (var_f5_221 < M2C_BITWISE(f32, 0.0)) {
            var_f5_221 = __float_nan;
        } else {
            sp10 = var_f5_221;
            temp_r3_255 = M2C_BITWISE(s32, sp10) & 0x7F800000;
            switch (temp_r3_255) {                  /* irregular */
            case 0x7F800000:
                if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                    var_r0_265 = 1;
                } else {
                    var_r0_265 = 2;
                }
                break;
            case 0x0:
                if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                    var_r0_265 = 5;
                } else {
                    var_r0_265 = 3;
                }
                break;
            default:
                var_r0_265 = 4;
                break;
            }
            if (var_r0_265 == 1) {
                var_f5_221 = __float_nan;
            }
        }
        var_f4_200 = 1.0f / var_f5_221;
    } else {
        var_f5_221 = 0.0f;
    }
    sp70 = (f32) sp70 * var_f4_200;
    unksp74 *= var_f4_200;
    sp78 = (f32) sp78 * var_f4_200;
    if (var_f5_221 != 0.0f) {
        KDMath_BuildMatrixFromFwd(&spB0, *((MKVector3 *) &sp70), (MKVector3 *) &sp60);
        spB0.unk30 = spF0.unk30;
        spB0.unk34 = spF0.unk34;
        spB0.unk38 = spF0.unk38;
        spB0.unk3C = 1.0f;
        MKModel_SetWorldMatrix(this->unk4, spB0);
    }
    if (sp14 != NULL) {
        M2C_FIELD(sp14, u8 *, 4) = sp18;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'sp20'
void SpeedwayAA::Collided(MKCollisionResult &arg0) {
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
    f32 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f32 sp3C;
    f32 sp38;
    f64 sp30;
    f64 sp28;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    MKProp *temp_r4_352;
    void *temp_r3_398;
    void *var_r3_401;

    Projectile::Collided(arg0);
    sp3C = 0.0f;
    temp_r4_352 = this->unk130;
    sp10 = 0.0f;
    sp8 = 0.0f;
    spC = 0.0f;
    sp30 = (f64) sp10;
    sp28 = (f64) sp8;
    sp38 = 1e-44f;
    sp60 = 1e-45f;
    sp64 = temp_r4_352;
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
    if (temp_r4_352 != NULL) {
        ((MKProp *) &sp18)->GetPos();
        sp68 = sp18;
        sp70 = sp20;
    } else {
        sp68 = 0.0f;
        unksp6C = 0.0f;
        sp70 = 0.0f;
    }
    sp89 = 0;
    if (((u8) arg0.unk50 != 0) && (temp_r3_398 = arg0.unk48, ((temp_r3_398 == NULL) == 0)) && (var_r3_401 = M2C_FIELD(temp_r3_398, void **, 8), ((var_r3_401 == NULL) == 0))) {

    } else {
        var_r3_401 = NULL;
    }
    if (var_r3_401 != NULL) {
        M2C_FIELD(M2C_FIELD(var_r3_401, void **, 0x44), M2C_UNK (**)(f32 *), 0x2C)(&sp38);
    }
    Disable();
}
#endif

void SpeedwayAA::FireAtTarget(const MKVector3 &arg0, const MKVector3 &arg1, float arg2, MKProp *arg3, int arg4, int arg5) {
    Projectile::FireAtTarget(arg0, arg1, arg2, arg3, arg4, arg5);
    this->unk140 = 4.0f;
}

void SpeedwayAA::Fire(const MKVector3 &arg0, const MKVector3 &arg1, MKProp *arg2, int arg3, int arg4) {
    Projectile::Fire(arg0, arg1, arg2, arg3, arg4);
    this->unk140 = 4.0f;
}

void SpeedwayAA::LoadDone() {
    Projectile::LoadDone();
}

void *SpeedwayAA::CreateInstance() {
    void *temp_r3_487;

    if ((MKPropDescriptor *) pSpeedwayAADescriptor != NULL) {
        temp_r3_487 = pSpeedwayAADescriptor->CreateInstance();
        if (temp_r3_487 != NULL) {
            M2C_FIELD(M2C_FIELD(temp_r3_487, void **, 0x44), M2C_UNK (**)(), 0x20)();
            return temp_r3_487;
        }
    }
    return NULL;
}

#if 0 // DRAFT: illegal use of non-static member
void SpeedwayAADescriptor::LoadDone() {
    GamePropDescriptor::LoadDone();
    pSpeedwayAADescriptor = (MKPropDescriptor *) this;
}
#endif

void SpeedwayAADescriptor::Deinit() {
    pSpeedwayAADescriptor = NULL;
    KDPropExDescriptor::Deinit();
}
