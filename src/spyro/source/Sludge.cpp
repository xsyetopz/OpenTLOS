#include "spyro/source/Sludge.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKCollisionResult.h"
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
#include "spyro/source/EmbersPS.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/GoopFX.h"
#include "spyro/source/KDMatrixProperty.h"
#include "spyro/source/KDMatrixRefProperty.h"
#include "spyro/source/KDPositionProperty.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDProperty.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/Projectile.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "common/Source/StdMath.h"
#include "spyro/source/KDMath.h"
#include "spyro/source/KDRandom.h"
#include <m2c_macros.h>

extern s32 GS_GrowthExtra1;
extern MKSceneManager *gMK;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern M2C_UNK gb;
extern MKPropDescriptor *pSludgeDescriptor;

#if 0 // DRAFT: undefined identifier '__float_nan'
void *Sludge::Update() {
    Matrix sp1B0;
    Matrix sp170;
    f64 sp160;                                      /* compiler-managed */
    f64 sp158;                                      /* compiler-managed */
    f64 sp150;
    f64 sp148;
    f64 sp140;
    f64 sp138;
    f64 sp130;
    f64 sp128;
    MKVector3 sp118;
    M2C_UNK sp108;
    f64 sp100;
    f64 spF8;
    f64 spE8;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    MKVector3 spB8;
    MKVector3 spA8;
    MKVector3 sp98;
    MKVector3 sp88;
    M2C_UNK sp78;
    f64 sp70;
    f64 sp68;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp40;
    f64 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp14;
    f32 sp10;
    f32 temp_f1_228;
    f32 temp_f1_238;
    f32 temp_f29_190;
    f32 temp_f30_185;
    f32 temp_f31_180;
    f32 var_f1_248;
    f32 var_f29_232;
    f32 var_f30_242;
    f32 var_f4_76;
    f32 var_f5_97;
    f64 temp_f0_205;
    f64 temp_f0_267;
    f64 temp_f1_102;
    f64 temp_f1_108;
    f64 temp_f1_112;
    s32 temp_r3_131;
    s32 var_r0_141;

    Projectile::Update();
    if (MKModel_GetAttachment(this->unk4) != NULL) {
        MKModel_GetWorldMatrixWithAttachment(this->unk4, &sp1B0);
    } else {
        M2C_STRUCT_COPY((s32) &sp170.unk3C + 4, MKModel_GetWorldMatrix(this->unk4) - 4 + 4, 0x40);
    }
    var_f4_76 = 0.0f;
    sp60 = 0.0f;
    sp58 = 0.0f;
    sp5C = 1.0f;
    sp150 = (f64) sp60;
    sp148 = (f64) sp58;
    sp158 = this->unkC8;
    sp160 = this->unkD0;
    var_f5_97 = ((f32) sp160 * (f32) sp160) + (((f32) sp158 * (f32) sp158) + ((*(f32 *) ((u8 *) &sp150 + 0xc)) * (*(f32 *) ((u8 *) &sp150 + 0xc))));
    if (var_f5_97 > 0.000001f) {
        if (var_f5_97 > 0.0f) {
            temp_f1_102 = __frsqrte(var_f5_97);
            temp_f1_108 = 0.5 * temp_f1_102 * -(((f64) var_f5_97 * (temp_f1_102 * temp_f1_102)) - 3.0);
            temp_f1_112 = 0.5 * temp_f1_108 * -(((f64) var_f5_97 * (temp_f1_108 * temp_f1_108)) - 3.0);
            var_f5_97 = (f32) ((f64) var_f5_97 * (0.5 * temp_f1_112 * -(((f64) var_f5_97 * (temp_f1_112 * temp_f1_112)) - 3.0)));
        } else if (var_f5_97 < M2C_BITWISE(f32, 0.0)) {
            var_f5_97 = __float_nan;
        } else {
            sp10 = var_f5_97;
            temp_r3_131 = M2C_BITWISE(s32, sp10) & 0x7F800000;
            switch (temp_r3_131) {                  /* irregular */
            case 0x7F800000:
                if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                    var_r0_141 = 1;
                } else {
                    var_r0_141 = 2;
                }
                break;
            case 0x0:
                if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                    var_r0_141 = 5;
                } else {
                    var_r0_141 = 3;
                }
                break;
            default:
                var_r0_141 = 4;
                break;
            }
            if (var_r0_141 == 1) {
                var_f5_97 = __float_nan;
            }
        }
        var_f4_76 = 1.0f / var_f5_97;
    } else {
        var_f5_97 = 0.0f;
    }
    sp158 = (f32) sp158 * var_f4_76;
    (*(f32 *) ((u8 *) &sp150 + 0xc)) *= var_f4_76;
    sp160 = (f32) sp160 * var_f4_76;
    if (var_f5_97 != 0.0f) {
        temp_f31_180 = gUpdateTimeDelta;
        temp_f30_185 = MKRand_Float((int *) &gViewSeed, 1.0f, 3.0f);
        temp_f29_190 = MKRand_Float((int *) &gViewSeed, 1.0f, 3.0f);
        MKVector(MKRand_Float((int *) &gViewSeed, 1.0f, 3.0f), temp_f29_190, temp_f30_185);
        sp118.operator*(3.0f);
        temp_f0_205 = sp118 * (f64) temp_f31_180;
        sp38 = temp_f0_205;
        sp128 = temp_f0_205;
        sp40 = sp118.unk8 * temp_f31_180;
        sp130 = (f64) sp40;
        M2C_FIELD(this, f64 *, 0x150) = (f64) (M2C_FIELD(this, f64 *, 0x150) + temp_f0_205);
        this->unk158 += (f32) sp130;
        KDMath_BuildMatrixFromFwd(&sp170, *((MKVector3 *) &sp158), (MKVector3 *) &sp148);
        temp_f1_228 = _table_sinf(this->unk158);
        if (temp_f1_228 < 0.0f) {
            var_f29_232 = -temp_f1_228;
        } else {
            var_f29_232 = temp_f1_228;
        }
        temp_f1_238 = _table_sinf(this->unk154);
        if (temp_f1_238 < 0.0f) {
            var_f30_242 = -temp_f1_238;
        } else {
            var_f30_242 = temp_f1_238;
        }
        var_f1_248 = _table_sinf(this->unk150);
        if (var_f1_248 < 0.0f) {
            var_f1_248 = -var_f1_248;
        }
        MKVector(var_f1_248, var_f30_242, 0.25f * var_f29_232);
        MKVector(1.0f, 1.0f, 1.0f);
        temp_f0_267 = spE8 + spD8;
        sp28 = temp_f0_267;
        spF8 = temp_f0_267;
        sp30 = spF0 + spE0;
        sp100 = (f64) sp30;
        sp170.Scale3x3(&sp170, *((MKVector3 *) &spF8));
        sp170.unk30 = sp1B0.unk30;
        sp170.unk34 = sp1B0.unk34;
        sp170.unk38 = sp1B0.unk38;
        sp170.unk3C = 1.0f;
        MKModel_SetWorldMatrix(this->unk4, sp170);
    }
    MKVector(1.0f, 0.0f, 1.0f);
    MKVector(-1.0f, 0.0f, -1.0f);
    KDRand_Vector(sp98, sp88);
    spA8.operator*(500.0f);
    spB8.operator*(0.5f);
    sp18 = spB8 + M2C_BITWISE(f64, spA8);
    spC8 = sp18;
    sp20 = spB8.unk8 + spA8.unk8;
    sp138 = sp18;
    spD0 = (f64) sp20;
    sp140 = (f64) sp20;
    sp4C = MKRand_Float((int *) &gViewSeed, 0.75f, 1.0f);
    sp48 = 0.5f;
    sp50 = 0.0f;
    sp54 = 1.0f;
    sp68 = (f64) sp48;
    sp70 = (f64) sp50;
    sp14 = MKRand_Float((int *) &gViewSeed, 10.0f, 20.0f);
    ((EmbersPS *) (M2C_FIELD(&gb, EmbersPS **, 0x74)))->Emit(*((MKVector3 *) &sp1B0.unk30), *((MKVector3 *) &sp138), sp14, *((MKVector4 *) &sp68), -500.0f);
}
#endif

#if 0 // DRAFT: undefined identifier 'MKVector'
void Sludge::Collided(MKCollisionResult &arg0) {
    s8 sp2E9;
    s8 sp2E8;
    s32 sp2E4;
    f32 sp2E0;
    s32 sp2DC;
    s8 sp2DA;
    s8 sp2D9;
    s8 sp2D8;
    f64 sp2D0;                                      /* compiler-managed */
    f64 sp2C8;                                      /* compiler-managed */
    MKProp *sp2C4;
    s32 sp2C0;
    f64 sp2B8;
    f64 sp2B0;
    f64 sp2A8;
    f64 sp2A0;
    s32 sp29C;
    s32 sp298;
    u8 sp290;
    s32 sp28C;
    void *sp288;
    s32 sp284;
    f32 sp280;
    s32 sp27C;
    s8 sp27B;
    s8 sp27A;
    s16 sp278;
    f32 sp274;
    f32 sp270;
    f32 sp26C;
    f32 sp268;
    f32 sp264;
    f32 sp260;
    f32 sp258;
    f32 sp254;
    f32 sp250;
    f32 sp248;
    f32 sp244;
    f32 sp240;
    Matrix sp200;
    M2C_UNK sp1FC;
    f64 sp1F0;
    f64 sp1E8;
    f64 sp1E0;                                      /* compiler-managed */
    f64 sp1D8;                                      /* compiler-managed */
    f64 sp1D0;
    f64 sp1C8;
    MKVector3 sp1B8;
    MKVector3 sp1A8;
    MKVector3 sp198;
    MKVector3 sp188;
    M2C_UNK sp178;
    f64 sp170;
    f64 sp168;
    f64 sp160;
    f64 sp158;
    MKVector3 sp148;
    MKVector3 sp138;
    MKVector3 sp128;
    MKVector3 sp118;
    M2C_UNK sp108;
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
    f32 spB4;
    f32 spB0;
    f32 spAC;
    f32 spA8;
    f32 spA4;
    f32 spA0;
    f32 sp9C;
    f32 sp98;
    f64 sp88;
    f64 sp78;
    f32 sp70;
    f64 sp68;
    f32 sp60;
    f64 sp58;
    f32 sp50;
    f64 sp48;
    f32 sp40;
    f64 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    MKProp *temp_r4_557;
    MKProp *temp_r4_742;
    f32 var_f4_628;
    f32 var_f5_666;
    f64 temp_f0_793;
    f64 temp_f0_804;
    f64 temp_f1_671;
    f64 temp_f1_677;
    f64 temp_f1_681;
    s32 temp_r3_700;
    s32 var_r0_710;
    s32 var_r26_422;
    s32 var_r26_486;
    void *temp_r28_396;
    void *temp_r3_470;
    void *temp_r3_610;
    void *var_r3_613;
    void *var_r3_829;

    Projectile::Collided(arg0);
    temp_r28_396 = checked_cast<SludgeDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    if (MKModel_GetAttachment(this->unk4) != NULL) {
        MKModel_GetWorldMatrixWithAttachment(this->unk4, &sp200);
    } else {
        M2C_STRUCT_COPY((s32) &sp1FC + 4, MKModel_GetWorldMatrix(this->unk4) - 4 + 4, 0x40);
    }
    var_r26_422 = 0;
    do {
        MKVector(1.0f, 1.5f, 1.0f);
        MKVector(-1.0f, 1.0f, -1.0f);
        KDRand_Vector(sp198, sp188);
        sp1A8.operator*(3000.0f);
        sp1B8.operator*(2.0f);
        sp48 = sp1B8 + M2C_BITWISE(f64, sp1A8);
        spA8 = 1.0f;
        spAC = 1.0f;
        sp50 = sp1B8.unk8 + sp1A8.unk8;
        spB0 = 1.0f;
        spB4 = 1.0f;
        sp1E8 = sp48;
        sp1F0 = (f64) sp50;
        sp168 = (f64) spA8;
        sp170 = (f64) spB0;
        temp_r3_470 = M2C_FIELD(temp_r28_396, void **, 0xF0);
        sp1C8 = sp48;
        sp1D0 = (f64) sp50;
        M2C_FIELD(M2C_FIELD(temp_r3_470, void **, 0x44), M2C_UNK (**)(void *, f32 *, f64 *, f64 *, f32, f64, f64, f64), 0x3C)(temp_r3_470, &sp200.unk30, &sp1E8, &sp168, 2.0f, (f64) spA8, (f64) sp50, sp48);
        var_r26_422 += 1;
    } while (var_r26_422 < 5);
    var_r26_486 = 0;
    do {
        MKVector(1.0f, 1.5f, 1.0f);
        MKVector(-1.0f, 1.0f, -1.0f);
        KDRand_Vector(sp128, sp118);
        sp138.operator*(1000.0f);
        sp148.operator*(0.5f);
        sp38 = sp148 + M2C_BITWISE(f64, sp138);
        sp158 = sp38;
        sp40 = sp148.unk8 + sp138.unk8;
        sp1E8 = sp38;
        sp160 = (f64) sp40;
        sp1F0 = (f64) sp40;
        sp9C = MKRand_Float((int *) &gViewSeed, 0.75f, 1.0f);
        sp98 = 0.5f;
        spA0 = 0.0f;
        spA4 = 1.0f;
        spF8 = (f64) sp98;
        sp100 = (f64) spA0;
        sp14 = MKRand_Float((int *) &gViewSeed, 10.0f, 20.0f);
        ((EmbersPS *) (M2C_FIELD(&gb, EmbersPS **, 0x74)))->Emit(*((MKVector3 *) &sp200.unk30), *((MKVector3 *) &sp1E8), sp14, *((MKVector4 *) &spF8), -500.0f);
        var_r26_486 += 1;
    } while (var_r26_486 < 0xA);
    sp29C = 0;
    temp_r4_557 = this->unk130;
    sp30 = 0.0f;
    sp28 = 0.0f;
    sp2C = 0.0f;
    spF0 = (f64) sp30;
    spE8 = (f64) sp28;
    sp298 = 7;
    sp2C0 = 1;
    sp2C4 = temp_r4_557;
    sp2A0 = (f64) sp28;
    sp2A8 = (f64) sp30;
    sp2D8 = 0;
    sp2E4 = 2;
    sp2E0 = 10.0f;
    sp2D9 = 0;
    sp2DA = 1;
    sp2DC = -1;
    sp2B0 = M2C_FIELD(&MKVector3::one, f64 *, 0);
    sp2B8 = M2C_FIELD(&MKVector3::one, f64 *, 8);
    sp2E8 = 0;
    if (temp_r4_557 != NULL) {
        ((MKProp *) &sp88)->GetPos();
        sp2C8 = sp88;
        sp2D0 = sp90;
    } else {
        sp2C8 = 0.0f;
        (*(f32 *) ((u8 *) &sp2C4 + 0x8)) = 0.0f;
        sp2D0 = 0.0f;
    }
    sp2E9 = 0;
    KDSound_Play3d(GS_GrowthExtra1, (MKVector3 *) &sp200.unk30, 0U, -1, 0.0f, 0U);
    if (((u8) arg0.unk50 != 0) && (temp_r3_610 = arg0.unk48, ((temp_r3_610 == NULL) == 0)) && (var_r3_613 = M2C_FIELD(temp_r3_610, void **, 8), ((var_r3_613 == NULL) == 0))) {

    } else {
        var_r3_613 = NULL;
    }
    if (var_r3_613 != NULL) {
        M2C_FIELD(M2C_FIELD(var_r3_613, void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp298);
    }
    var_f4_628 = 0.0f;
    sp240 = 0.0f;
    sp244 = 0.0f;
    sp248 = 0.0f;
    sp250 = 0.0f;
    sp254 = 0.0f;
    sp258 = 0.0f;
    sp260 = 0.0f;
    sp264 = 0.0f;
    sp268 = 0.0f;
    sp26C = 1.0f;
    sp270 = 0.0f;
    sp274 = 0.0f;
    sp278 = 0;
    sp27A = 0;
    sp27B = 0;
    sp27C = 0;
    sp280 = 3.4028235e38f;
    sp284 = 0;
    sp288 = NULL;
    sp28C = -1;
    sp290 = 0;
    sp1D8 = this->unkC8;
    sp1E0 = this->unkD0;
    (*(f32 *) ((u8 *) &sp1D0 + 0xc)) = 0.0f;
    var_f5_666 = ((f32) sp1E0 * (f32) sp1E0) + (((f32) sp1D8 * (f32) sp1D8) + (0.0f * 0.0f));
    if (var_f5_666 > 0.000001f) {
        if (var_f5_666 > 0.0f) {
            temp_f1_671 = __frsqrte(var_f5_666);
            temp_f1_677 = 0.5 * temp_f1_671 * -(((f64) var_f5_666 * (temp_f1_671 * temp_f1_671)) - 3.0);
            temp_f1_681 = 0.5 * temp_f1_677 * -(((f64) var_f5_666 * (temp_f1_677 * temp_f1_677)) - 3.0);
            var_f5_666 = (f32) ((f64) var_f5_666 * (0.5 * temp_f1_681 * -(((f64) var_f5_666 * (temp_f1_681 * temp_f1_681)) - 3.0)));
        } else if (var_f5_666 < M2C_BITWISE(f32, 0.0)) {
            var_f5_666 = __float_nan;
        } else {
            sp10 = var_f5_666;
            temp_r3_700 = M2C_BITWISE(s32, sp10) & 0x7F800000;
            switch (temp_r3_700) {                  /* irregular */
            case 0x7F800000:
                if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                    var_r0_710 = 1;
                } else {
                    var_r0_710 = 2;
                }
                break;
            case 0x0:
                if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                    var_r0_710 = 5;
                } else {
                    var_r0_710 = 3;
                }
                break;
            default:
                var_r0_710 = 4;
                break;
            }
            if (var_r0_710 == 1) {
                var_f5_666 = __float_nan;
            }
        }
        var_f4_628 = 1.0f / var_f5_666;
    }
    temp_r4_742 = this->unk130;
    sp20 = 0.0f;
    sp18 = 0.0f;
    sp1C = 0.0f;
    sp1D8 = (f32) sp1D8 * var_f4_628;
    (*(f32 *) ((u8 *) &sp1D0 + 0xc)) *= var_f4_628;
    sp1E0 = (f32) sp1E0 * var_f4_628;
    spD8 = (f64) sp18;
    spE0 = (f64) sp20;
    sp298 = 7;
    sp2C0 = 1;
    sp2C4 = temp_r4_742;
    sp2A0 = (f64) sp18;
    sp2A8 = (f64) sp20;
    sp2D8 = 0;
    sp2E4 = 2;
    sp2E0 = 10.0f;
    sp2D9 = 0;
    sp2DA = 1;
    sp2DC = -1;
    sp2B0 = M2C_FIELD(&MKVector3::one, f64 *, 0);
    sp2B8 = M2C_FIELD(&MKVector3::one, f64 *, 8);
    sp2E8 = 0;
    if (temp_r4_742 != NULL) {
        ((MKProp *) &sp78)->GetPos();
        sp2C8 = sp78;
        sp2D0 = sp80;
    } else {
        sp2C8 = 0.0f;
        (*(f32 *) ((u8 *) &sp2C4 + 0x8)) = 0.0f;
        sp2D0 = 0.0f;
    }
    sp2E9 = 0;
    temp_f0_793 = (f64) sp1D8 * 5.64367472e-315;
    sp68 = temp_f0_793;
    spB8 = temp_f0_793;
    sp70 = sp1E0 * 600.0f;
    spC0 = (f64) sp70;
    temp_f0_804 = sp200.unk30 + temp_f0_793;
    sp58 = temp_f0_804;
    spC8 = temp_f0_804;
    sp60 = sp200.unk38 + (f32) spC0;
    spD0 = (f64) sp60;
    if (MKCollision_SweepSphereCollide(*((MKVector3 *) &sp200.unk30), *((MKVector3 *) &spC8), 200.0f, (MKCollisionResult *) &sp240, (MKCollisionMode) 2, 0x08000000) != 0) {
        if ((sp290 != 0) && (sp288 != NULL) && (var_r3_829 = M2C_FIELD(sp288, void **, 8), ((var_r3_829 == NULL) == 0))) {

        } else {
            var_r3_829 = NULL;
        }
        if (var_r3_829 != NULL) {
            M2C_FIELD(M2C_FIELD(var_r3_829, void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp298);
        }
    }
    Disable();
}
#endif

s32 Sludge::LoadDone() {
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;

    sp8 = 0.0f;
    spC = 0.0f;
    sp10 = 0.0f;
    M2C_FIELD(this, f64 *, 0x150) = (f64) sp8;
    sp18 = (f64) sp8;
    sp20 = (f64) sp10;
    M2C_FIELD(this, f64 *, 0x158) = (f64) sp10;
    Projectile::LoadDone();
}

void *Sludge::CreateInstance() {
    void *temp_r3_898;

    if ((MKPropDescriptor *) pSludgeDescriptor != NULL) {
        temp_r3_898 = pSludgeDescriptor->CreateInstance();
        if (temp_r3_898 != NULL) {
            M2C_FIELD(M2C_FIELD(temp_r3_898, void **, 0x44), M2C_UNK (**)(), 0x20)();
            return temp_r3_898;
        }
    }
    return NULL;
}

#if 0 // DRAFT: illegal implicit conversion from 'GoopFX *' to
void SludgeDescriptor::LoadDone() {
    GamePropDescriptor::LoadDone();
    pSludgeDescriptor = (MKPropDescriptor *) this;
    this->unkF0 = checked_cast<GoopFX *, MKProp>(gMK->CreateProp("SludgeSplatter"));
}
#endif

void SludgeDescriptor::Deinit() {
    pSludgeDescriptor = NULL;
    KDPropExDescriptor::Deinit();
}
