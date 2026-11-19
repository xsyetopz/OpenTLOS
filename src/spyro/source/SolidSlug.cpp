#include "spyro/source/SolidSlug.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/Projectile.h"
#include "unplaced_templates.h"
#include "common/Source/MKModel.h"
#include "spyro/source/KDMath.h"
#include "spyro/source/KDSound.h"
#include <m2c_macros.h>

extern s32 GS_PLACEHOLDER;
extern MKPropDescriptor *pSolidSlugDescriptor;

#if 0 // DRAFT: function call 'memcpy(long, long, int)' does not match
void SolidSlug::Update() {
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
    var_f5_91 = ((f32) sp40 * (f32) sp40) + (((f32) sp38 * (f32) sp38) + (unksp3C * unksp3C));
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
    unksp3C *= var_f4_70;
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
#endif

#if 0 // DRAFT: ')' expected
void SolidSlug::Collided(MKCollisionResult &arg0) {
    s8 spD9;
    s8 spD8;
    s32 spD4;
    f32 spD0;
    s32 spCC;
    s8 spCA;
    s8 spC9;
    s8 spC8;
    f64 spC0;                                       /* compiler-managed */
    f64 spB8;                                       /* compiler-managed */
    MKProp *spB4;
    s32 spB0;
    f64 spA8;
    f64 spA0;
    f64 sp98;
    f64 sp90;
    s32 sp8C;
    MKProp *sp88;
    s8 sp86;
    s8 sp85;
    s8 sp84;
    s32 sp80;
    s32 sp7C;
    s32 sp78;
    s32 sp74;
    s32 sp70;
    f32 sp6C;
    f32 sp68;
    f64 sp60;
    f64 sp58;
    MKProp *sp50;
    MKProp *sp4C;
    MKProp *sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    MKProp *temp_r9_233;
    MKVector3 *temp_r31_348;
    MKVector3 *temp_r31_371;
    f64 temp_f2_251;
    f64 temp_f3_250;
    void *temp_r3_221;
    void *temp_r7_246;
    void *var_r31_224;

    if ((u8) M2C_FIELD(checked_cast<SolidSlugDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), u8 *, 0xF0) != 0) {
        this->unk148 = GS_PLACEHOLDER;
    }
    Projectile::Collided(arg0);
    if (((u8) arg0.unk50 != 0) && (temp_r3_221 = arg0.unk48, ((temp_r3_221 == NULL) == 0)) && (var_r31_224 = M2C_FIELD(temp_r3_221, void **, 8), ((var_r31_224 == NULL) == 0))) {

    } else {
        var_r31_224 = NULL;
    }
    if (var_r31_224 != NULL) {
        temp_r9_233 = this->unk130;
        if (temp_r9_233 != NULL) {
            if (M2C_FIELD(M2C_FIELD(var_r31_224, void **, 0), s32 *, 0xC) & 8) {
                sp4C = NULL;
                temp_r7_246 = temp_r9_233->unk8;
                temp_f3_250 = M2C_FIELD(temp_r7_246, f64 *, 0x30);
                temp_f2_251 = M2C_FIELD(temp_r7_246, f64 *, 0x38);
                sp38 = temp_f3_250;
                sp48 = (MKProp *)4;
                sp50 = temp_r9_233;
                sp58 = temp_f3_250;
                sp60 = temp_f2_251;
                sp68 = 10.0f;
                sp84 = 0;
                sp70 = 0;
                sp78 = 0x4000;
                sp85 = 0;
                sp86 = 0;
                sp74 = -1;
                sp7C = 0;
                sp80 = 0;
                sp6C = 1.0f;
                sp40 = temp_f2_251;
                M2C_FIELD(M2C_FIELD(var_r31_224, void **, 0x44), M2C_UNK (**)(void *, MKProp **, M2C_UNK, M2C_UNK, void *, M2C_UNK, f32, f64, f64), 0x2C)(var_r31_224, &sp48, 0x4000, 4, temp_r7_246, 0, 10.0f, temp_f2_251, temp_f3_250);
            } else {
                sp10 = 0.0f;
                sp8 = 0.0f;
                spC = 0.0f;
                sp8C = 0;
                sp28 = (f64) sp8;
                sp30 = (f64) sp10;
                sp88 = (MKProp *)7;
                spB0 = 1;
                spB4 = temp_r9_233;
                sp90 = (f64) sp8;
                sp98 = (f64) sp10;
                spC8 = 0;
                spD4 = 2;
                spD0 = 10.0f;
                spC9 = 0;
                spCA = 1;
                spCC = -1;
                spA0 = M2C_FIELD(&MKVector3::one, f64 *, 0);
                spA8 = M2C_FIELD(&MKVector3::one, f64 *, 8);
                spD8 = 0;
                if (temp_r9_233 != NULL) {
                    sp18.GetPos();
                    spB8 = sp18;
                    spC0 = sp20;
                } else {
                    spB8 = 0.0f;
                    unkspBC = 0.0f;
                    spC0 = 0.0f;
                }
                spD9 = 0;
                M2C_FIELD(M2C_FIELD(var_r31_224, void **, 0x44), M2C_UNK (**)(void *, MKProp **, M2C_UNK, M2C_UNK, void *, M2C_UNK, f32, f64, f64), 0x2C)(var_r31_224, &sp88);
            }
        }
    }
    if ((var_r31_224 != NULL) && (M2C_FIELD(M2C_FIELD(var_r31_224, void **, 0), s32 *, 0xC) & 0x4C)) {
        if (((u8) M2C_FIELD(checked_cast<SolidSlugDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), u8 *, 0xF0) != 0) && ((s32) M2C_FIELD(checked_cast<SolidSlugDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0xEC) != 0)) {
            temp_r31_348 = this->unk8 + 0x30;
            KDSound_Play3d(M2C_FIELD(checked_cast<SolidSlugDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0xEC), temp_r31_348, (u32) arg0.unk44, -1, 0.0f, 0U);
        }
    } else if (((u8) M2C_FIELD(checked_cast<SolidSlugDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), u8 *, 0xF0) != 0) && ((s32) M2C_FIELD(checked_cast<SolidSlugDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0xF4) != 0)) {
        temp_r31_371 = this->unk8 + 0x30;
        KDSound_Play3d(M2C_FIELD(checked_cast<SolidSlugDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0xF4), temp_r31_371, (u32) arg0.unk44, -1, 0.0f, 0U);
    }
    Disable();
}
#endif

void SolidSlug::LoadDone() {
    Projectile::LoadDone();
}

void *SolidSlug::CreateInstance() {
    void *temp_r3_416;

    if ((MKPropDescriptor *) pSolidSlugDescriptor != NULL) {
        temp_r3_416 = pSolidSlugDescriptor->CreateInstance();
        if (temp_r3_416 != NULL) {
            M2C_FIELD(M2C_FIELD(temp_r3_416, void **, 0x44), M2C_UNK (**)(), 0x20)();
            return temp_r3_416;
        }
    }
    return NULL;
}

#if 0 // DRAFT: illegal use of non-static member
void SolidSlugDescriptor::LoadDone() {
    GamePropDescriptor::LoadDone();
    pSolidSlugDescriptor = (MKPropDescriptor *) this;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'unsigned char *' to
s32 SolidSlugDescriptor::LoadLine(MKIniLine *arg0) {
    s32 var_r31_461;

    var_r31_461 = 0;
    if ((ProjectileDescriptor::LoadLine(arg0) != 0) || (arg0->LoadBool("PlayHitMissSounds", (u8 *) &this->unkF0, 0) != 0) || (KDSound_LoadLine(arg0, "sndMiss", &this->unkF4) != 0)) {
        var_r31_461 = 1;
    }
    return var_r31_461;
}
#endif

void SolidSlugDescriptor::Deinit() {
    pSolidSlugDescriptor = NULL;
    this->unkF4 = GS_PLACEHOLDER;
    M2C_FIELD(this, s8 *, 0xF0) = 0;
    KDPropExDescriptor::Deinit();
}
