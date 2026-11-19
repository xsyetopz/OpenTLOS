#include "spyro/source/MagicFireball.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/KDParticleSystem.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/LightManager.h"
#include "spyro/source/ManagedLight.h"
#include "spyro/source/Projectile.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKModel.h"
#include "common/Source/StdMath.h"
#include "spyro/source/KDMath.h"
#include "spyro/source/KDRandom.h"
#include "spyro/source/KDSound.h"
#include <m2c_macros.h>

extern s32 GS_IceOrgeMagicExplode;
extern s32 GS_IceOrgeMagicLP;
extern MKSceneManager *gMK;
extern s32 gViewSeed;
extern M2C_UNK gb;
extern MKPropDescriptor *pMagicFireballDescriptor;

static s32 lit_555 = 0;
static u8 lit_556 = 1;

void MagicFireball::Activate() {
    ManagedLight *temp_r4_53;

    GameProp::Activate();
    temp_r4_53 = this->unk160;
    if (temp_r4_53 != NULL) {
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->EnableLight(temp_r4_53, 1U);
    }
    this->unk18C = 1;
}

void MagicFireball::Disable() {
    ManagedLight *temp_r4_79;

    temp_r4_79 = this->unk160;
    if (temp_r4_79 != NULL) {
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->EnableLight(temp_r4_79, 0U);
    }
    Projectile::Disable();
}

void MagicFireball::Deactivate() {
    ManagedLight *temp_r4_105;

    temp_r4_105 = this->unk160;
    if (temp_r4_105 != NULL) {
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->EnableLight(temp_r4_105, 0U);
    }
    this->unk18C = 0;
    GameProp::Deactivate();
}

#if 0 // DRAFT: undefined identifier 'arg_sp8'
void MagicFireball::Update() {
    MagicFireball *var_r7_150;
    ManagedLight *temp_r3_403;
    ManagedLight *temp_r3_423;
    f32 temp_f0_424;
    f32 temp_f30_352;
    f32 var_f4_181;
    f32 var_f5_202;
    f64 temp_f1_207;
    f64 temp_f1_213;
    f64 temp_f1_217;
    s32 temp_r3_236;
    s32 var_r0_246;
    void *temp_r28_313;
    void *temp_r3_302;
    void *temp_r3_304;
    void *temp_r3_308;
    void *temp_r3_410;
    void *temp_r3_426;
    Projectile::Update();
    arg_sp8 = 1;
    if (((u8) this->unk14C >> 7U) & 1) {
        var_r7_150 = this;
    } else {
        var_r7_150 = (MagicFireball *) this->unk130;
    }
    this->unk164.Update(GS_IceOrgeMagicLP, 1U, this->unk18C, (MKProp *) var_r7_150, NULL, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    if (MKModel_GetAttachment(this->unk4) != NULL) {
        MKModel_GetWorldMatrixWithAttachment(this->unk4, (Matrix *) &arg_sp130);
    } else {
        M2C_STRUCT_COPY((s32) &arg_sp12C + 4, MKModel_GetWorldMatrix(this->unk4) - 4 + 4, 0x40);
    }
    var_f4_181 = 0.0f;
    arg_sp50 = 0.0f;
    arg_sp48 = 0.0f;
    arg_sp4C = 1.0f;
    arg_spD0 = (f64) arg_sp50;
    arg_spC8 = (f64) arg_sp48;
    arg_spD8 = this->unkC8;
    arg_spE0 = this->unkD0;
    var_f5_202 = ((f32) arg_spE0 * (f32) arg_spE0) + (((f32) arg_spD8 * (f32) arg_spD8) + (arg_spDC * arg_spDC));
    if (var_f5_202 > 0.000001f) {
        if (var_f5_202 > 0.0f) {
            temp_f1_207 = __frsqrte(var_f5_202);
            temp_f1_213 = 0.5 * temp_f1_207 * -(((f64) var_f5_202 * (temp_f1_207 * temp_f1_207)) - 3.0);
            temp_f1_217 = 0.5 * temp_f1_213 * -(((f64) var_f5_202 * (temp_f1_213 * temp_f1_213)) - 3.0);
            var_f5_202 = (f32) ((f64) var_f5_202 * (0.5 * temp_f1_217 * -(((f64) var_f5_202 * (temp_f1_217 * temp_f1_217)) - 3.0)));
        } else if (var_f5_202 < M2C_BITWISE(f32, 0.0)) {
            var_f5_202 = __float_nan;
        } else {
            arg_sp10 = var_f5_202;
            temp_r3_236 = M2C_BITWISE(s32, arg_sp10) & 0x7F800000;
            switch (temp_r3_236) {                  /* irregular */
            case 0x7F800000:
                if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                    var_r0_246 = 1;
                } else {
                    var_r0_246 = 2;
                }
                break;
            case 0x0:
                if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                    var_r0_246 = 5;
                } else {
                    var_r0_246 = 3;
                }
                break;
            default:
                var_r0_246 = 4;
                break;
            }
            if (var_r0_246 == 1) {
                var_f5_202 = __float_nan;
            }
        }
        var_f4_181 = 1.0f / var_f5_202;
    } else {
        var_f5_202 = 0.0f;
    }
    arg_spD8 = (f32) arg_spD8 * var_f4_181;
    arg_spDC *= var_f4_181;
    arg_spE0 = (f32) arg_spE0 * var_f4_181;
    if (var_f5_202 != 0.0f) {
        KDMath_BuildMatrixFromFwd((Matrix *) &arg_spF0, *((MKVector3 *) &arg_spD8), (MKVector3 *) &arg_spC8);
        arg_sp120 = arg_sp160;
        arg_sp124 = arg_sp164;
        arg_sp128 = arg_sp168;
        arg_sp12C = 1.0f;
        MKModel_SetWorldMatrix(this->unk4, *((Matrix *) &arg_spF0));
    }
    temp_r3_302 = checked_cast<MagicFireballDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    temp_r3_304 = M2C_FIELD(temp_r3_302, void **, 0xF0);
    temp_r3_308 = M2C_FIELD(M2C_FIELD(temp_r3_304, void **, 0x44), void *(**)(void *), 0x3C)(temp_r3_304);
    if (temp_r3_308 != NULL) {
        temp_r28_313 = M2C_FIELD(temp_r3_308, void **, 0x2C);
        MKVector(1.0f, 1.0f, 1.0f);
        MKVector(-1.0f, -1.0f, -1.0f);
        KDRand_Vector(*((MKVector3 *) &arg_sp98), *((MKVector3 *) &arg_sp88));
        arg_spA8.operator*(25.0f);
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        M2C_FIELD(temp_r3_308, f64 *, 0) = arg_sp38;
        arg_sp40 = arg_sp168 + arg_spB0;
        arg_spB8 = arg_sp38;
        M2C_FIELD(temp_r3_308, f64 *, 8) = (f64) arg_sp40;
        M2C_FIELD(temp_r3_308, f32 *, 0x20) = 0.0f;
        arg_spC0 = (f64) arg_sp40;
        M2C_FIELD(temp_r3_308, f32 *, 0x28) = 0.0f;
        temp_f30_352 = MKRand_Float(&gViewSeed, 0.25f, 0.5f);
        arg_sp2C = MKRand_Float(&gViewSeed, 0.75f, 1.0f);
        arg_sp28 = temp_f30_352;
        arg_sp30 = temp_f30_352;
        arg_sp34 = 1.0f;
        M2C_FIELD(temp_r3_308, f64 *, 0x10) = (f64) arg_sp28;
        arg_sp68 = (f64) arg_sp28;
        arg_sp70 = (f64) arg_sp30;
        M2C_FIELD(temp_r3_308, f64 *, 0x18) = (f64) arg_sp30;
        M2C_FIELD(temp_r3_308, f32 *, 0x24) = (f32) (2.0f * (3.1415927f * MKRand_Float(&gViewSeed, -1.0f, 1.0f)));
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $r31, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
        M2C_FIELD(temp_r28_313, f64 *, 0) = arg_sp18;
        arg_sp20 = (f32) M2C_FIELD(this, f64 *, 0xD0) * 0.5f;
        arg_sp58 = arg_sp18;
        arg_sp60 = (f64) arg_sp20;
        M2C_FIELD(temp_r28_313, f64 *, 8) = (f64) arg_sp20;
        M2C_FIELD(temp_r28_313, f32 *, 0x18) = MKRand_Float(&gViewSeed, 1.0f, 2.0f);
        M2C_FIELD(temp_r28_313, f32 *, 0x10) = MKRand_Float(&gViewSeed, -6.2831855f, 6.2831855f);
        M2C_FIELD(temp_r28_313, f32 *, 0x14) = (f32) M2C_FIELD(M2C_FIELD(temp_r3_302, void **, 0xF0), f32 *, 0xF4);
    }
    temp_r3_403 = this->unk160;
    if (temp_r3_403 != NULL) {
        temp_r3_403->unk10 = (f64) arg_sp160;
        temp_r3_403->unk18 = (f64) arg_sp168;
        temp_r3_410 = temp_r3_403->unk3C;
        if (temp_r3_410 != NULL) {
            M2C_FIELD(temp_r3_410, f64 *, 0x10) = (f64) arg_sp160;
            M2C_FIELD(temp_r3_410, f64 *, 0x18) = (f64) arg_sp168;
        }
        temp_r3_423 = this->unk160;
        temp_f0_424 = 500.0f * MKRand_Float(&gViewSeed, 1.0f, 1.5f);
        temp_r3_423->unk38 = temp_f0_424;
        temp_r3_426 = temp_r3_423->unk3C;
        if (temp_r3_426 != NULL) {
            M2C_FIELD(temp_r3_426, f32 *, 0x20) = temp_f0_424;
            M2C_FIELD(temp_r3_426, f32 *, 0x24) = (f32) (temp_f0_424 * temp_f0_424);
            M2C_FIELD(temp_r3_426, f32 *, 0x28) = (f32) (1.0f / temp_f0_424);
            M2C_FIELD(temp_r3_426, f32 *, 0x2C) = (f32) (1.0f / M2C_FIELD(temp_r3_426, f32 *, 0x24));
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_sp1C0'
void MagicFireball::Collided(MKCollisionResult &arg0) {
    MKProp *temp_r4_630;
    MKProp *temp_r4_819;
    ManagedLight *temp_r4_921;
    f32 temp_f29_552;
    f32 var_f4_705;
    f32 var_f5_743;
    f64 temp_f1_748;
    f64 temp_f1_754;
    f64 temp_f1_758;
    s32 temp_r3_777;
    s32 var_r0_787;
    s32 var_r26_499;
    void *temp_r25_514;
    void *temp_r27_495;
    void *temp_r3_505;
    void *temp_r3_509;
    void *temp_r3_687;
    void *var_r3_690;
    void *var_r3_906;
    Projectile::Collided(arg0);
    if (MKModel_GetAttachment(this->unk4) != NULL) {
        MKModel_GetWorldMatrixWithAttachment(this->unk4, (Matrix *) &arg_sp1C0);
    } else {
        M2C_STRUCT_COPY((s32) &arg_sp1BC + 4, MKModel_GetWorldMatrix(this->unk4) - 4 + 4, 0x40);
    }
    temp_r27_495 = checked_cast<MagicFireballDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    arg_sp1A8 = this->unkC8;
    var_r26_499 = 0;
    arg_sp1B0 = this->unkD0;
    arg_sp1AC = 0.0f;
    do {
        temp_r3_505 = M2C_FIELD(temp_r27_495, void **, 0xF0);
        temp_r3_509 = M2C_FIELD(M2C_FIELD(temp_r3_505, void **, 0x44), void *(**)(void *), 0x3C)(temp_r3_505);
        if (temp_r3_509 != NULL) {
            temp_r25_514 = M2C_FIELD(temp_r3_509, void **, 0x2C);
            MKVector(1.0f, 1.0f, 1.0f);
            MKVector(-1.0f, 0.0f, -1.0f);
            KDRand_Vector(*((MKVector3 *) &arg_sp168), *((MKVector3 *) &arg_sp158));
            arg_sp178.operator*(25.0f);
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r31, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            M2C_FIELD(temp_r3_509, f64 *, 0) = arg_sp58;
            arg_sp60 = arg_sp1F8 + arg_sp180;
            arg_sp188 = arg_sp58;
            M2C_FIELD(temp_r3_509, f64 *, 8) = (f64) arg_sp60;
            M2C_FIELD(temp_r3_509, f32 *, 0x20) = 0.0f;
            arg_sp190 = (f64) arg_sp60;
            M2C_FIELD(temp_r3_509, f32 *, 0x28) = 0.0f;
            temp_f29_552 = MKRand_Float(&gViewSeed, 0.25f, 0.5f);
            arg_sp4C = MKRand_Float(&gViewSeed, 0.75f, 1.0f);
            arg_sp48 = temp_f29_552;
            arg_sp50 = temp_f29_552;
            arg_sp54 = 1.0f;
            M2C_FIELD(temp_r3_509, f64 *, 0x10) = (f64) arg_sp48;
            arg_sp138 = (f64) arg_sp48;
            arg_sp140 = (f64) arg_sp50;
            M2C_FIELD(temp_r3_509, f64 *, 0x18) = (f64) arg_sp50;
            M2C_FIELD(temp_r3_509, f32 *, 0x24) = (f32) (2.0f * (3.1415927f * MKRand_Float(&gViewSeed, -1.0f, 1.0f)));
            MKVector(1.0f, 1.0f, 1.0f);
            MKVector(-1.0f, 0.0f, -1.0f);
            KDRand_Vector(*((MKVector3 *) &arg_sp108), *((MKVector3 *) &arg_spF8));
            arg_sp118.operator*(500.0f);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            M2C_FIELD(temp_r25_514, f64 *, 0) = arg_sp38;
            arg_sp40 = (f32) arg_sp1B0 + arg_sp120;
            arg_sp128 = arg_sp38;
            arg_sp130 = (f64) arg_sp40;
            M2C_FIELD(temp_r25_514, f64 *, 8) = (f64) arg_sp40;
            M2C_FIELD(temp_r25_514, f32 *, 0x18) = MKRand_Float(&gViewSeed, 1.0f, 2.0f);
            M2C_FIELD(temp_r25_514, f32 *, 0x10) = MKRand_Float(&gViewSeed, -6.2831855f, 6.2831855f);
            M2C_FIELD(temp_r25_514, f32 *, 0x14) = (f32) M2C_FIELD(M2C_FIELD(temp_r27_495, void **, 0xF0), f32 *, 0xF4);
        }
        var_r26_499 += 1;
    } while (var_r26_499 < 0x14);
    arg_sp25C = 0;
    temp_r4_630 = this->unk130;
    arg_sp30 = 0.0f;
    arg_sp28 = 0.0f;
    arg_sp2C = 0.0f;
    arg_spE0 = (f64) arg_sp30;
    arg_spD8 = (f64) arg_sp28;
    arg_sp258 = 7;
    arg_sp280 = 1;
    arg_sp284 = temp_r4_630;
    arg_sp260 = (f64) arg_sp28;
    arg_sp268 = (f64) arg_sp30;
    arg_sp298 = 0;
    arg_sp2A4 = 2;
    arg_sp2A0 = 10.0f;
    arg_sp298 = 0;
    (s16) arg_sp298 = 1;
    arg_sp29C = -1;
    arg_sp270 = M2C_FIELD(&MKVector3::one, f64 *, 0);
    arg_sp278 = M2C_FIELD(&MKVector3::one, f64 *, 8);
    arg_sp2A8 = 0;
    if (temp_r4_630 != NULL) {
        arg_sp98.GetPos();
        arg_sp288 = arg_sp98;
        arg_sp290 = arg_spA0;
    } else {
        arg_sp288 = 0.0f;
        arg_sp28C = 0.0f;
        arg_sp290 = 0.0f;
    }
    arg_sp2A8 = 0;
    this->unk18C = 0;
    KDSound_Stop(&this->unk164);
    KDSound_Play3d(GS_IceOrgeMagicExplode, this->unk8 + 0x30, 0U, -1, 0.0f, 0U);
    if (((u8) arg0.unk50 != 0) && (temp_r3_687 = arg0.unk48, ((temp_r3_687 == NULL) == 0)) && (var_r3_690 = M2C_FIELD(temp_r3_687, void **, 8), ((var_r3_690 == NULL) == 0))) {

    } else {
        var_r3_690 = NULL;
    }
    if (var_r3_690 != NULL) {
        M2C_FIELD(M2C_FIELD(var_r3_690, void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&arg_sp258);
    }
    var_f4_705 = 0.0f;
    arg_sp200 = 0.0f;
    arg_sp204 = 0.0f;
    arg_sp208 = 0.0f;
    arg_sp210 = 0.0f;
    arg_sp214 = 0.0f;
    arg_sp218 = 0.0f;
    arg_sp220 = 0.0f;
    arg_sp224 = 0.0f;
    arg_sp228 = 0.0f;
    arg_sp22C = 1.0f;
    arg_sp230 = 0.0f;
    arg_sp234 = 0.0f;
    arg_sp238 = 0;
    arg_sp238 = 0;
    (s8) arg_sp238 = 0;
    arg_sp23C = 0;
    arg_sp240 = 3.4028235e38f;
    arg_sp244 = 0;
    arg_sp248 = NULL;
    arg_sp24C = -1;
    arg_sp250 = 0U;
    arg_sp198 = this->unkC8;
    arg_sp1A0 = this->unkD0;
    arg_sp19C = 0.0f;
    var_f5_743 = ((f32) arg_sp1A0 * (f32) arg_sp1A0) + (((f32) arg_sp198 * (f32) arg_sp198) + (0.0f * 0.0f));
    if (var_f5_743 > 0.000001f) {
        if (var_f5_743 > 0.0f) {
            temp_f1_748 = __frsqrte(var_f5_743);
            temp_f1_754 = 0.5 * temp_f1_748 * -(((f64) var_f5_743 * (temp_f1_748 * temp_f1_748)) - 3.0);
            temp_f1_758 = 0.5 * temp_f1_754 * -(((f64) var_f5_743 * (temp_f1_754 * temp_f1_754)) - 3.0);
            var_f5_743 = (f32) ((f64) var_f5_743 * (0.5 * temp_f1_758 * -(((f64) var_f5_743 * (temp_f1_758 * temp_f1_758)) - 3.0)));
        } else if (var_f5_743 < M2C_BITWISE(f32, 0.0)) {
            var_f5_743 = __float_nan;
        } else {
            arg_sp10 = var_f5_743;
            temp_r3_777 = M2C_BITWISE(s32, arg_sp10) & 0x7F800000;
            switch (temp_r3_777) {                  /* irregular */
            case 0x7F800000:
                if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                    var_r0_787 = 1;
                } else {
                    var_r0_787 = 2;
                }
                break;
            case 0x0:
                if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                    var_r0_787 = 5;
                } else {
                    var_r0_787 = 3;
                }
                break;
            default:
                var_r0_787 = 4;
                break;
            }
            if (var_r0_787 == 1) {
                var_f5_743 = __float_nan;
            }
        }
        var_f4_705 = 1.0f / var_f5_743;
    }
    temp_r4_819 = this->unk130;
    arg_sp20 = 0.0f;
    arg_sp18 = 0.0f;
    arg_sp1C = 0.0f;
    arg_sp198 = (f32) arg_sp198 * var_f4_705;
    arg_sp19C *= var_f4_705;
    arg_sp1A0 = (f32) arg_sp1A0 * var_f4_705;
    arg_spC8 = (f64) arg_sp18;
    arg_spD0 = (f64) arg_sp20;
    arg_sp258 = 7;
    arg_sp280 = 1;
    arg_sp284 = temp_r4_819;
    arg_sp260 = (f64) arg_sp18;
    arg_sp268 = (f64) arg_sp20;
    arg_sp298 = 0;
    arg_sp2A4 = 2;
    arg_sp2A0 = 10.0f;
    arg_sp298 = 0;
    (s16) arg_sp298 = 1;
    arg_sp29C = -1;
    arg_sp270 = M2C_FIELD(&MKVector3::one, f64 *, 0);
    arg_sp278 = M2C_FIELD(&MKVector3::one, f64 *, 8);
    arg_sp2A8 = 0;
    if (temp_r4_819 != NULL) {
        arg_sp88.GetPos();
        arg_sp288 = arg_sp88;
        arg_sp290 = arg_sp90;
    } else {
        arg_sp288 = 0.0f;
        arg_sp28C = 0.0f;
        arg_sp290 = 0.0f;
    }
    arg_sp2A8 = 0;
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
    arg_spA8 = arg_sp78;
    arg_sp80 = (f32) arg_sp1A0 * 600.0f;
    arg_spB0 = (f64) arg_sp80;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r31, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    arg_spB8 = arg_sp68;
    arg_sp70 = arg_sp1F8 + (f32) arg_spB0;
    arg_spC0 = (f64) arg_sp70;
    if (MKCollision_SweepSphereCollide(*((MKVector3 *) &arg_sp1F0), *((MKVector3 *) &arg_spB8), 200.0f, (MKCollisionResult *) &arg_sp200, (MKCollisionMode) 2, 0x08000000) != 0) {
        if ((arg_sp250 != 0) && (arg_sp248 != NULL) && (var_r3_906 = M2C_FIELD(arg_sp248, void **, 8), ((var_r3_906 == NULL) == 0))) {

        } else {
            var_r3_906 = NULL;
        }
        if (var_r3_906 != NULL) {
            M2C_FIELD(M2C_FIELD(var_r3_906, void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&arg_sp258);
        }
    }
    temp_r4_921 = this->unk160;
    if (temp_r4_921 != NULL) {
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->EnableLight(temp_r4_921, 0U);
    }
    Disable();
}
#endif

void MagicFireball::Fire(const MKVector3 &arg0, const MKVector3 &arg1, MKProp *arg2, int arg3, int arg4) {
    ManagedLight *temp_r3_970;
    ManagedLight *temp_r4_962;
    void *temp_r3_973;

    temp_r4_962 = this->unk160;
    if (temp_r4_962 != NULL) {
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->EnableLight(temp_r4_962, 1U);
        temp_r3_970 = this->unk160;
        temp_r3_970->unk38 = 500.0f;
        temp_r3_973 = temp_r3_970->unk3C;
        if (temp_r3_973 != NULL) {
            M2C_FIELD(temp_r3_973, f32 *, 0x20) = 500.0f;
            M2C_FIELD(temp_r3_973, f32 *, 0x24) = 250000.0f;
            M2C_FIELD(temp_r3_973, f32 *, 0x28) = 0.002f;
            M2C_FIELD(temp_r3_973, f32 *, 0x2C) = (f32) (1.0f / M2C_FIELD(temp_r3_973, f32 *, 0x24));
        }
    }
    Projectile::Fire(arg0, arg1, arg2, arg3, arg4);
}

#if 0 // DRAFT: illegal implicit conversion from 'void *' to
void MagicFireball::LoadDone() {
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
    ManagedLight *temp_r4_1044;

    Projectile::LoadDone();
    sp20 = 0.0f;
    sp30 = 0.0f;
    sp8 = 0.0f;
    spC = 1.0f;
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
    this->unk160 = ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->AllocManagedLight(*((MKVector3 *) &sp58), *((MKVector3 *) &sp48), *((MKVector4 *) &sp38), 500.0f, lit_555, lit_556);
    temp_r4_1044 = this->unk160;
    if (temp_r4_1044 != NULL) {
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->EnableLight(temp_r4_1044, 0U);
    }
}
#endif

void *MagicFireball::CreateInstance() {
    void *temp_r3_1068;

    if ((MKPropDescriptor *) pMagicFireballDescriptor != NULL) {
        temp_r3_1068 = pMagicFireballDescriptor->CreateInstance();
        if (temp_r3_1068 != NULL) {
            M2C_FIELD(M2C_FIELD(temp_r3_1068, void **, 0x44), M2C_UNK (**)(), 0x20)();
            return temp_r3_1068;
        }
    }
    return NULL;
}

void MagicFireball::Reset() {
    Projectile::Reset();
    this->unk18C = 1;
}

#if 0 // DRAFT: expression syntax error
void MagicFireball::Message(MKMessage *arg0) {
    Projectile::Message(arg0);
    this->unk164.Message(arg0);
}
#endif

#if 0 // DRAFT: function call 'KDSound_Stop(long *)' does not match
void MagicFireball::Deinit() {
    ManagedLight *temp_r4_1134;

    Projectile::Deinit();
    temp_r4_1134 = this->unk160;
    if (temp_r4_1134 != NULL) {
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->FreeManagedLight(temp_r4_1134);
    }
    KDSound_Stop(&this->unk164);
    this->unk18C = 0;
}
#endif

#if 0 // DRAFT: expression syntax error
void MagicFireball::Init() {
    Projectile::Init();
    this->unk164.Init(0.25f, 0.25f);
    this->unk18C = 1;
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void MagicFireballDescriptor::LoadDone() {
    GamePropDescriptor::LoadDone();
    pMagicFireballDescriptor = (MKPropDescriptor *) this;
    this->unkF0 = checked_cast<KDEnvParticleSystem *, MKProp>(gMK->CreateProp("MagicFlamePS"));
}
#endif

void MagicFireballDescriptor::Deinit() {
    pMagicFireballDescriptor = NULL;
    KDPropExDescriptor::Deinit();
}
