#include "spyro/source/Sludge.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/EmbersPS.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/GoopFX.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/Projectile.h"
#include "unplaced_templates.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKModel.h"
#include "common/Source/StdMath.h"
#include "spyro/source/KDMath.h"
#include "spyro/source/KDRandom.h"
#include "spyro/source/KDSound.h"
#include <m2c_macros.h>

extern s32 GS_GrowthExtra1;
extern MKSceneManager *gMK;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern M2C_UNK gb;
extern MKPropDescriptor *pSludgeDescriptor;

#if 0 // DRAFT: undefined identifier 'arg_sp1B0'
void Sludge::Update() {
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
    f64 temp_f1_102;
    f64 temp_f1_108;
    f64 temp_f1_112;
    s32 temp_r3_131;
    s32 var_r0_141;
    Projectile::Update();
    if (MKModel_GetAttachment(this->unk4) != NULL) {
        MKModel_GetWorldMatrixWithAttachment(this->unk4, (Matrix *) &arg_sp1B0);
    } else {
        M2C_STRUCT_COPY((s32) &arg_sp1AC + 4, MKModel_GetWorldMatrix(this->unk4) - 4 + 4, 0x40);
    }
    var_f4_76 = 0.0f;
    arg_sp60 = 0.0f;
    arg_sp58 = 0.0f;
    arg_sp5C = 1.0f;
    arg_sp150 = (f64) arg_sp60;
    arg_sp148 = (f64) arg_sp58;
    arg_sp158 = this->unkC8;
    arg_sp160 = this->unkD0;
    var_f5_97 = ((f32) arg_sp160 * (f32) arg_sp160) + (((f32) arg_sp158 * (f32) arg_sp158) + (arg_sp15C * arg_sp15C));
    if (var_f5_97 > 0.000001f) {
        if (var_f5_97 > 0.0f) {
            temp_f1_102 = __frsqrte(var_f5_97);
            temp_f1_108 = 0.5 * temp_f1_102 * -(((f64) var_f5_97 * (temp_f1_102 * temp_f1_102)) - 3.0);
            temp_f1_112 = 0.5 * temp_f1_108 * -(((f64) var_f5_97 * (temp_f1_108 * temp_f1_108)) - 3.0);
            var_f5_97 = (f32) ((f64) var_f5_97 * (0.5 * temp_f1_112 * -(((f64) var_f5_97 * (temp_f1_112 * temp_f1_112)) - 3.0)));
        } else if (var_f5_97 < M2C_BITWISE(f32, 0.0)) {
            var_f5_97 = __float_nan;
        } else {
            arg_sp10 = var_f5_97;
            temp_r3_131 = M2C_BITWISE(s32, arg_sp10) & 0x7F800000;
            switch (temp_r3_131) {                  /* irregular */
            case 0x7F800000:
                if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                    var_r0_141 = 1;
                } else {
                    var_r0_141 = 2;
                }
                break;
            case 0x0:
                if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
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
    arg_sp158 = (f32) arg_sp158 * var_f4_76;
    arg_sp15C *= var_f4_76;
    arg_sp160 = (f32) arg_sp160 * var_f4_76;
    if (var_f5_97 != 0.0f) {
        temp_f31_180 = gUpdateTimeDelta;
        temp_f30_185 = MKRand_Float(&gViewSeed, 1.0f, 3.0f);
        temp_f29_190 = MKRand_Float(&gViewSeed, 1.0f, 3.0f);
        MKVector(MKRand_Float(&gViewSeed, 1.0f, 3.0f), temp_f29_190, temp_f30_185);
        arg_sp118.operator*(3.0f);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
        arg_sp128 = arg_sp38;
        arg_sp40 = arg_sp120 * temp_f31_180;
        arg_sp130 = (f64) arg_sp40;
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        M2C_ERROR(/* unknown instruction: psq_stx $f0, $r31, $r0, 0x0, qr0 */);
        this->unk158 += (f32) arg_sp130;
        KDMath_BuildMatrixFromFwd((Matrix *) &arg_sp170, *((MKVector3 *) &arg_sp158), (MKVector3 *) &arg_sp148);
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
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        arg_spF8 = arg_sp28;
        arg_sp30 = arg_spF0 + arg_spE0;
        arg_sp100 = (f64) arg_sp30;
        arg_sp170.Scale3x3((Matrix *) &arg_sp170, *((MKVector3 *) &arg_spF8));
        arg_sp1A0 = arg_sp1E0;
        arg_sp1A4 = arg_sp1E4;
        arg_sp1A8 = arg_sp1E8;
        arg_sp1AC = 1.0f;
        MKModel_SetWorldMatrix(this->unk4, *((Matrix *) &arg_sp170));
    }
    MKVector(1.0f, 0.0f, 1.0f);
    MKVector(-1.0f, 0.0f, -1.0f);
    KDRand_Vector(*((MKVector3 *) &arg_sp98), *((MKVector3 *) &arg_sp88));
    arg_spA8.operator*(500.0f);
    arg_spB8.operator*(0.5f);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    arg_spC8 = arg_sp18;
    arg_sp20 = arg_spC0 + arg_spB0;
    arg_sp138 = arg_sp18;
    arg_spD0 = (f64) arg_sp20;
    arg_sp140 = (f64) arg_sp20;
    arg_sp4C = MKRand_Float(&gViewSeed, 0.75f, 1.0f);
    arg_sp48 = 0.5f;
    arg_sp50 = 0.0f;
    arg_sp54 = 1.0f;
    arg_sp68 = (f64) arg_sp48;
    arg_sp70 = (f64) arg_sp50;
    arg_sp14 = MKRand_Float(&gViewSeed, 10.0f, 20.0f);
    ((EmbersPS *) (M2C_FIELD(&gb, EmbersPS **, 0x74)))->Emit(*((MKVector3 *) &arg_sp1E0), *((MKVector3 *) &arg_sp138), arg_sp14, *((MKVector4 *) &arg_sp68), -500.0f);
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_sp200'
void Sludge::Collided(MKCollisionResult &arg0) {
    MKProp *temp_r4_557;
    MKProp *temp_r4_742;
    f32 var_f4_628;
    f32 var_f5_666;
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
        MKModel_GetWorldMatrixWithAttachment(this->unk4, (Matrix *) &arg_sp200);
    } else {
        M2C_STRUCT_COPY((s32) &arg_sp1FC + 4, MKModel_GetWorldMatrix(this->unk4) - 4 + 4, 0x40);
    }
    var_r26_422 = 0;
    do {
        MKVector(1.0f, 1.5f, 1.0f);
        MKVector(-1.0f, 1.0f, -1.0f);
        KDRand_Vector(*((MKVector3 *) &arg_sp198), *((MKVector3 *) &arg_sp188));
        arg_sp1A8.operator*(3000.0f);
        arg_sp1B8.operator*(2.0f);
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r27, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        arg_spA8 = 1.0f;
        arg_spAC = 1.0f;
        arg_sp50 = arg_sp1C0 + arg_sp1B0;
        arg_spB0 = 1.0f;
        arg_spB4 = 1.0f;
        arg_sp1E8 = arg_sp48;
        arg_sp1F0 = (f64) arg_sp50;
        arg_sp168 = (f64) arg_spA8;
        arg_sp170 = (f64) arg_spB0;
        temp_r3_470 = M2C_FIELD(temp_r28_396, void **, 0xF0);
        arg_sp1C8 = arg_sp48;
        arg_sp1D0 = (f64) arg_sp50;
        M2C_FIELD(M2C_FIELD(temp_r3_470, void **, 0x44), M2C_UNK (**)(void *, M2C_UNK *, f64 *, f64 *, f32, f64, f64, f64), 0x3C)(temp_r3_470, &arg_sp230, &arg_sp1E8, &arg_sp168, 2.0f, (f64) arg_spA8, (f64) arg_sp50, arg_sp48);
        var_r26_422 += 1;
    } while (var_r26_422 < 5);
    var_r26_486 = 0;
    do {
        MKVector(1.0f, 1.5f, 1.0f);
        MKVector(-1.0f, 1.0f, -1.0f);
        KDRand_Vector(*((MKVector3 *) &arg_sp128), *((MKVector3 *) &arg_sp118));
        arg_sp138.operator*(1000.0f);
        arg_sp148.operator*(0.5f);
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r27, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        arg_sp158 = arg_sp38;
        arg_sp40 = arg_sp150 + arg_sp140;
        arg_sp1E8 = arg_sp38;
        arg_sp160 = (f64) arg_sp40;
        arg_sp1F0 = (f64) arg_sp40;
        arg_sp9C = MKRand_Float(&gViewSeed, 0.75f, 1.0f);
        arg_sp98 = 0.5f;
        arg_spA0 = 0.0f;
        arg_spA4 = 1.0f;
        arg_spF8 = (f64) arg_sp98;
        arg_sp100 = (f64) arg_spA0;
        arg_sp14 = MKRand_Float(&gViewSeed, 10.0f, 20.0f);
        ((EmbersPS *) (M2C_FIELD(&gb, EmbersPS **, 0x74)))->Emit(*((MKVector3 *) &arg_sp230), *((MKVector3 *) &arg_sp1E8), arg_sp14, *((MKVector4 *) &arg_spF8), -500.0f);
        var_r26_486 += 1;
    } while (var_r26_486 < 0xA);
    arg_sp29C = 0;
    temp_r4_557 = this->unk130;
    arg_sp30 = 0.0f;
    arg_sp28 = 0.0f;
    arg_sp2C = 0.0f;
    arg_spF0 = (f64) arg_sp30;
    arg_spE8 = (f64) arg_sp28;
    arg_sp298 = 7;
    arg_sp2C0 = 1;
    arg_sp2C4 = temp_r4_557;
    arg_sp2A0 = (f64) arg_sp28;
    arg_sp2A8 = (f64) arg_sp30;
    arg_sp2D8 = 0;
    arg_sp2E4 = 2;
    arg_sp2E0 = 10.0f;
    arg_sp2D8 = 0;
    (s16) arg_sp2D8 = 1;
    arg_sp2DC = -1;
    arg_sp2B0 = M2C_FIELD(&one, f64 *, 0);
    arg_sp2B8 = M2C_FIELD(&one, f64 *, 8);
    arg_sp2E8 = 0;
    if (temp_r4_557 != NULL) {
        arg_sp88.GetPos();
        arg_sp2C8 = arg_sp88;
        arg_sp2D0 = arg_sp90;
    } else {
        arg_sp2C8 = 0.0f;
        arg_sp2CC = 0.0f;
        arg_sp2D0 = 0.0f;
    }
    arg_sp2E8 = 0;
    KDSound_Play3d(GS_GrowthExtra1, (MKVector3 *) &arg_sp230, 0U, -1, 0.0f, 0U);
    if (((u8) arg0.unk50 != 0) && (temp_r3_610 = arg0.unk48, ((temp_r3_610 == NULL) == 0)) && (var_r3_613 = M2C_FIELD(temp_r3_610, void **, 8), ((var_r3_613 == NULL) == 0))) {

    } else {
        var_r3_613 = NULL;
    }
    if (var_r3_613 != NULL) {
        M2C_FIELD(M2C_FIELD(var_r3_613, void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&arg_sp298);
    }
    var_f4_628 = 0.0f;
    arg_sp240 = 0.0f;
    arg_sp244 = 0.0f;
    arg_sp248 = 0.0f;
    arg_sp250 = 0.0f;
    arg_sp254 = 0.0f;
    arg_sp258 = 0.0f;
    arg_sp260 = 0.0f;
    arg_sp264 = 0.0f;
    arg_sp268 = 0.0f;
    arg_sp26C = 1.0f;
    arg_sp270 = 0.0f;
    arg_sp274 = 0.0f;
    arg_sp278 = 0;
    arg_sp278 = 0;
    (s8) arg_sp278 = 0;
    arg_sp27C = 0;
    arg_sp280 = 3.4028235e38f;
    arg_sp284 = 0;
    arg_sp288 = NULL;
    arg_sp28C = -1;
    arg_sp290 = 0U;
    arg_sp1D8 = this->unkC8;
    arg_sp1E0 = this->unkD0;
    arg_sp1DC = 0.0f;
    var_f5_666 = ((f32) arg_sp1E0 * (f32) arg_sp1E0) + (((f32) arg_sp1D8 * (f32) arg_sp1D8) + (0.0f * 0.0f));
    if (var_f5_666 > 0.000001f) {
        if (var_f5_666 > 0.0f) {
            temp_f1_671 = __frsqrte(var_f5_666);
            temp_f1_677 = 0.5 * temp_f1_671 * -(((f64) var_f5_666 * (temp_f1_671 * temp_f1_671)) - 3.0);
            temp_f1_681 = 0.5 * temp_f1_677 * -(((f64) var_f5_666 * (temp_f1_677 * temp_f1_677)) - 3.0);
            var_f5_666 = (f32) ((f64) var_f5_666 * (0.5 * temp_f1_681 * -(((f64) var_f5_666 * (temp_f1_681 * temp_f1_681)) - 3.0)));
        } else if (var_f5_666 < M2C_BITWISE(f32, 0.0)) {
            var_f5_666 = __float_nan;
        } else {
            arg_sp10 = var_f5_666;
            temp_r3_700 = M2C_BITWISE(s32, arg_sp10) & 0x7F800000;
            switch (temp_r3_700) {                  /* irregular */
            case 0x7F800000:
                if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                    var_r0_710 = 1;
                } else {
                    var_r0_710 = 2;
                }
                break;
            case 0x0:
                if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
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
    arg_sp20 = 0.0f;
    arg_sp18 = 0.0f;
    arg_sp1C = 0.0f;
    arg_sp1D8 = (f32) arg_sp1D8 * var_f4_628;
    arg_sp1DC *= var_f4_628;
    arg_sp1E0 = (f32) arg_sp1E0 * var_f4_628;
    arg_spD8 = (f64) arg_sp18;
    arg_spE0 = (f64) arg_sp20;
    arg_sp298 = 7;
    arg_sp2C0 = 1;
    arg_sp2C4 = temp_r4_742;
    arg_sp2A0 = (f64) arg_sp18;
    arg_sp2A8 = (f64) arg_sp20;
    arg_sp2D8 = 0;
    arg_sp2E4 = 2;
    arg_sp2E0 = 10.0f;
    arg_sp2D8 = 0;
    (s16) arg_sp2D8 = 1;
    arg_sp2DC = -1;
    arg_sp2B0 = M2C_FIELD(&one, f64 *, 0);
    arg_sp2B8 = M2C_FIELD(&one, f64 *, 8);
    arg_sp2E8 = 0;
    if (temp_r4_742 != NULL) {
        arg_sp78.GetPos();
        arg_sp2C8 = arg_sp78;
        arg_sp2D0 = arg_sp80;
    } else {
        arg_sp2C8 = 0.0f;
        arg_sp2CC = 0.0f;
        arg_sp2D0 = 0.0f;
    }
    arg_sp2E8 = 0;
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
    arg_spB8 = arg_sp68;
    arg_sp70 = (f32) arg_sp1E0 * 600.0f;
    arg_spC0 = (f64) arg_sp70;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r31, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    arg_spC8 = arg_sp58;
    arg_sp60 = arg_sp238 + (f32) arg_spC0;
    arg_spD0 = (f64) arg_sp60;
    if (MKCollision_SweepSphereCollide(*((MKVector3 *) &arg_sp230), *((MKVector3 *) &arg_spC8), 200.0f, (MKCollisionResult *) &arg_sp240, (MKCollisionMode) 2, 0x08000000) != 0) {
        if ((arg_sp290 != 0) && (arg_sp288 != NULL) && (var_r3_829 = M2C_FIELD(arg_sp288, void **, 8), ((var_r3_829 == NULL) == 0))) {

        } else {
            var_r3_829 = NULL;
        }
        if (var_r3_829 != NULL) {
            M2C_FIELD(M2C_FIELD(var_r3_829, void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&arg_sp298);
        }
    }
    Disable();
}
#endif

void Sludge::LoadDone() {
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

#if 0 // DRAFT: illegal use of non-static member
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

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<SludgeDescriptor *, MKPropDescriptor>(MKPropDescriptor *arg0) {

}
#endif
