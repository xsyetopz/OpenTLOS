#include "spyro/source/SpeedwayCynder.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "spyro/source/FireBombFX.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/NodeLookAt.h"
#include "spyro/source/SpeedWay.h"
#include "spyro/source/SpeedWaySpyro.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKInput.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKView.h"
#include "common/Source/StdMath.h"
#include "common/Source/Str.h"
#include "spyro/source/EventCamera.h"
#include "spyro/source/KDMath.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/Tools.h"
#include <m2c_macros.h>

M2C_UNK free(MKHeap *);                             /* extern */
MKHeap *malloc(M2C_UNK);                            /* extern */
extern s32 GS_SWCynderFireBreathLP;
extern s32 GS_SWCynderFireBreathStart;
extern s32 GS_SWCynderFireBreathStop;
extern s32 GS_SWCynderFireball1;
extern s32 GS_SWCynderGlideLP;
extern s32 GS_SWCynderTaunt;
extern f32 SPYRO_BOUNCE_Y_SPEED;
extern f32 SPYRO_MIN_JUMP_Y_VELOCITY;
extern s32 bHitSpyro;
extern f32 enterX;
extern f32 enterY;
extern M2C_UNK gEmptyPtrList;
extern void **gMK;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern void **gb;
static M2C_UNK lit_739;                                /* unable to generate initializer: unknown type */
static f32 CYNDER_CAMERA_Y_OFFSET = 490.0f;
static f32 CYNDER_CAMERA_MIN_Z_OFFSET = -1200.0f;
static f32 CYNDER_CAMERA_MAX_Z_OFFSET = 60.000004f;
static f32 CYNDER_BURST_BREATH_START_TIME = 0.825f;
static f32 CYNDER_FULL_BREATH_START_TIME = 0.95f;
static f32 CYNDER_SHOOT_FIRE_BALL_END_TIME = 0.7f;
static f32 CYNDER_HEAD_TURN_START_TIME = 0.8f;
static f32 CYNDER_HEAD_COLLISION_RADIUS = 150.0f;
static f32 CYNDER_MAX_Z_TIME = 1.2f;
static f32 CYNDER_MAX_BITE_SIDE_OFFSET = 1000.0f;

#if 0 // DRAFT: expression syntax error
void SpeedwayCynder::UpdateSound() {
    s32 sp8;
    f32 temp_f1_90;

    sp8 = 1;
    this->unk3A8.Update(GS_SWCynderGlideLP, 1U, 1U, NULL, this->unk8 + 0x30, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    sp8 = 1;
    this->unk3D0.Update(GS_SWCynderFireBreathLP, 1U, this->unk3F8, NULL, this->unk8 + 0x30, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    temp_f1_90 = this->unk36C;
    if (temp_f1_90 > 0.0f) {
        this->unk36C = temp_f1_90 - gUpdateTimeDelta;
    }
    M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
    if (this->unk368 == 0.5f) {
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if (this->unk36C == 0.0f) {
            this->unk370 = KDSound_Play3d(GS_SWCynderTaunt, this->unk8 + 0x30, 0U, -1, 0.0f, 0U);
            this->unk36C = 10.0f;
        }
    }
}
#endif

void SpeedwayCynder::UpdateCameraRoll() {
    f32 temp_f5_208;
    f32 temp_f6_193;
    f32 temp_f8_190;
    f32 var_f0_223;
    f32 var_f1_149;
    f32 var_f1_179;
    u8 var_r3_136;
    u8 var_r3_167;

    var_r3_136 = 0;
    if (((u8) M2C_FIELD(M2C_FIELD(&gb, void **, 0x354), u8 *, 5) != 0) || ((u8) M2C_FIELD(M2C_FIELD(&gb, void **, 0x354), u8 *, 4) != 0)) {
        var_r3_136 = 1;
    }
    if (var_r3_136 != 0) {
        var_f1_149 = 0.0f;
    } else {
        var_f1_149 = MKInput_GetState(0x11, (MKInputDevices) M2C_FIELD(M2C_FIELD(&gb, void **, 0x354), s32 *, 0), NULL, NULL);
    }
    if (var_f1_149 < 0.0f) {
        var_f1_149 = -var_f1_149;
    }
    if (var_f1_149 > 0.4f) {
        var_r3_167 = 0;
        if (((u8) M2C_FIELD(M2C_FIELD(&gb, void **, 0x354), u8 *, 5) != 0) || ((u8) M2C_FIELD(M2C_FIELD(&gb, void **, 0x354), u8 *, 4) != 0)) {
            var_r3_167 = 1;
        }
        if (var_r3_167 != 0) {
            var_f1_179 = 0.0f;
        } else {
            var_f1_179 = MKInput_GetState(0x11, (MKInputDevices) M2C_FIELD(M2C_FIELD(&gb, void **, 0x354), s32 *, 0), NULL, NULL);
        }
        temp_f8_190 = this->unk3A4;
        temp_f6_193 = this->unk3A0;
        this->unk3A0 += temp_f8_190 + (gUpdateTimeDelta * (((((0.4f * gUpdateTimeDelta * var_f1_179) + temp_f6_193) - temp_f6_193) * 9.0f) - (2.0f * temp_f8_190 * 3.0f)));
    } else {
        temp_f5_208 = this->unk3A4;
        this->unk3A0 += (gUpdateTimeDelta * (((0.0f - this->unk3A0) * 1.0f) - (2.0f * temp_f5_208 * 1.0f))) + temp_f5_208;
    }
    var_f0_223 = this->unk3A0;
    if (var_f0_223 < 0.392699f) {

    } else {
        var_f0_223 = 0.392699f;
    }
    if (var_f0_223 > -0.392699f) {

    } else {
        var_f0_223 = -0.392699f;
    }
    this->unk3A0 = var_f0_223;
    memset(&this->unk3A4, 0, 4U);
}

f32 SpeedwayCynder::GetCameraZOffset() {
    return (this->unk390 * (CYNDER_CAMERA_MAX_Z_OFFSET - CYNDER_CAMERA_MIN_Z_OFFSET)) + CYNDER_CAMERA_MIN_Z_OFFSET;
}

void SpeedwayCynder::SetTargetZTime(float arg0, float arg1) {
    this->unk398 = arg0;
    this->unk39C = arg1;
}

void SpeedwayCynder::UpdateCameraZTime() {
    SpeedWaySpyro *temp_r3_316;
    f32 temp_f1_300;
    f32 temp_f1_331;
    f32 temp_f1_357;
    f32 temp_f1_383;
    f32 temp_f3_329;
    f32 temp_f3_355;
    f32 temp_f3_381;
    f32 temp_f5_282;
    f32 temp_f6_279;
    f32 temp_f6_338;
    f32 temp_f6_364;
    f32 temp_f6_390;
    f32 temp_f7_285;
    f32 var_f0_276;
    f32 var_f0_402;
    f32 var_f2_330;
    f32 var_f2_356;
    f32 var_f2_382;
    s32 temp_r0_324;

    var_f0_276 = 7.5f;
    temp_f6_279 = this->unk398;
    if ((temp_f6_279 != -1.0f) && (temp_f5_282 = this->unk39C, ((temp_f5_282 == -1.0f) == 0))) {
        temp_f7_285 = this->unk394;
        this->unk390 += (gUpdateTimeDelta * (((temp_f6_279 - this->unk390) * (temp_f5_282 * temp_f5_282)) - (2.0f * temp_f7_285 * temp_f5_282))) + temp_f7_285;
    } else {
        temp_f1_300 = this->unk390;
        if (temp_f1_300 > 0.5f) {
            var_f0_276 = ((1.0f - _table_sinf((((temp_f1_300 - 0.5f) / 0.5f) * 1.4726212f) + 0.0f)) * 4.5f) + 3.0f;
        }
        temp_r3_316 = this->unk37C;
        if (temp_r3_316->unk810 > 0.0f) {
            var_f0_276 *= 2.5f;
        }
        temp_r0_324 = temp_r3_316->unkA0;
        switch (temp_r0_324) {                      /* irregular */
        case 2:
            temp_f3_329 = this->unk390;
            var_f2_330 = 1.0f;
            temp_f1_331 = -((0.3f * gUpdateTimeDelta) - temp_f3_329);
            if (var_f2_330 < temp_f1_331) {

            } else {
                var_f2_330 = temp_f1_331;
            }
            temp_f6_338 = this->unk394;
            this->unk390 += (gUpdateTimeDelta * (((var_f2_330 - temp_f3_329) * (var_f0_276 * var_f0_276)) - (2.0f * temp_f6_338 * var_f0_276))) + temp_f6_338;
            break;
        case 0:
            temp_f3_355 = this->unk390;
            var_f2_356 = 1.0f;
            temp_f1_357 = (0.25f * gUpdateTimeDelta) + temp_f3_355;
            if (var_f2_356 < temp_f1_357) {

            } else {
                var_f2_356 = temp_f1_357;
            }
            temp_f6_364 = this->unk394;
            this->unk390 += (gUpdateTimeDelta * (((var_f2_356 - temp_f3_355) * (var_f0_276 * var_f0_276)) - (2.0f * temp_f6_364 * var_f0_276))) + temp_f6_364;
            break;
        case 1:
            temp_f3_381 = this->unk390;
            var_f2_382 = 1.0f;
            temp_f1_383 = (0.05f * gUpdateTimeDelta) + temp_f3_381;
            if (var_f2_382 < temp_f1_383) {

            } else {
                var_f2_382 = temp_f1_383;
            }
            temp_f6_390 = this->unk394;
            this->unk390 += (gUpdateTimeDelta * (((var_f2_382 - temp_f3_381) * (var_f0_276 * var_f0_276)) - (2.0f * temp_f6_390 * var_f0_276))) + temp_f6_390;
            break;
        }
    }
    var_f0_402 = this->unk390;
    if (var_f0_402 < CYNDER_MAX_Z_TIME) {

    } else {
        var_f0_402 = CYNDER_MAX_Z_TIME;
    }
    if (var_f0_402 > 0.0f) {

    } else {
        var_f0_402 = 0.0f;
    }
    this->unk390 = var_f0_402;
    memset(&this->unk394, 0, 4U);
}

#if 0 // DRAFT: undefined identifier '__vptr'
s32 SpeedwayCynder::ShootFireBomb(const MKVector3 &arg0, const MKVector3 &arg1, const MKVector3 &arg2) {
    FireBombFX *temp_r3_442;

    temp_r3_442 = checked_cast<FireBombFX *, MKProp>(this->unk380->CreateInstance());
    if (temp_r3_442 == NULL) {
        return 0;
    }
    M2C_FIELD(temp_r3_442->__vptr, M2C_UNK (**)(), 0x30)();
    temp_r3_442->Fire(arg0, arg1, 1.0f, (MKProp *) this, 1U, 0U, 2, arg2);
    KDSound_Play3d(GS_SWCynderFireball1, &arg0, 0U, -1, 0.0f, 0U);
    return 1;
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_sp180'
void SpeedwayCynder::UpdateFireBomb() {
    f32 temp_f1_552;
    f32 temp_f1_579;
    void *temp_r3_588;
    this->unk374 -= gUpdateTimeDelta;
    M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
    if ((this->unk374 == 0.0f) && (this->unk390 < CYNDER_SHOOT_FIRE_BALL_END_TIME)) {
        arg_sp180.GetPathMatrix(this->unk37C->unk2C0);
        M2C_STRUCT_COPY((s32) &arg_sp1BC + 4, (s32) &arg_sp17C + 4, 0x40);
        arg_spB0 = -arg_sp1E0;
        arg_spB4 = -arg_sp1E4;
        arg_spB8 = -arg_sp1E8;
        arg_sp170 = (f64) arg_spB0;
        arg_sp178 = (f64) arg_spB8;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
        temp_f1_552 = arg_sp1C8 * MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        arg_spF0 = arg_sp70;
        arg_sp78 = temp_f1_552;
        arg_spF8 = (f64) arg_sp78;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f28 */);
        arg_sp100 = arg_sp60;
        arg_sp68 = (f32) arg_spF8 * 1000.0f;
        arg_sp108 = (f64) arg_sp68;
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
        temp_f1_579 = arg_sp1D8 * MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        arg_sp110 = arg_spA0;
        arg_spA8 = temp_f1_579;
        arg_sp118 = (f64) arg_spA8;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f27 */);
        temp_r3_588 = this->unk8;
        arg_sp120 = arg_sp90;
        arg_sp98 = (f32) arg_sp118 * 1000.0f;
        arg_sp130 = M2C_FIELD(temp_r3_588, f64 *, 0x30);
        arg_sp128 = (f64) arg_sp98;
        arg_sp138 = M2C_FIELD(temp_r3_588, f64 *, 0x38);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        arg_sp140 = arg_sp80;
        arg_sp88 = (f32) arg_sp138 + (f32) arg_sp128;
        arg_sp148 = (f64) arg_sp88;
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        arg_sp160 = arg_sp50;
        arg_sp40 = -arg_sp1E0;
        arg_sp58 = (f32) arg_sp148 + (f32) arg_sp108;
        arg_sp44 = -arg_sp1E4;
        arg_sp168 = (f64) arg_sp58;
        arg_sp48 = -arg_sp1E8;
        arg_spC0 = (f64) arg_sp40;
        arg_spC8 = (f64) arg_sp48;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f26 */);
        arg_spD0 = arg_sp30;
        arg_sp38 = (f32) arg_spC8 * 15000.0f;
        arg_spD8 = (f64) arg_sp38;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
        arg_spE0 = arg_sp20;
        arg_sp28 = (f32) arg_spD8 * (0.5f + this->unk368);
        arg_spE8 = (f64) arg_sp28;
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        arg_sp18 = (f32) arg_sp168 + (f32) arg_spE8;
        arg_sp150 = arg_sp10;
        arg_sp158 = (f64) arg_sp18;
        ShootFireBomb(*((MKVector3 *) &arg_sp160), *((MKVector3 *) &arg_sp170), *((MKVector3 *) &arg_sp150));
        this->unk374 = 5.0f * (0.5f + this->unk368);
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_sp110'
void SpeedwayCynder::UpdateBreath() {
    f32 temp_f1_856;
    f32 temp_f2_733;
    f32 temp_f31_743;
    f32 var_f4_771;
    f32 var_f4_838;
    f64 temp_f0_887;
    f64 temp_f1_777;
    f64 temp_f1_783;
    f64 temp_f1_787;
    f64 temp_f2_885;
    f64 temp_f3_912;
    f64 temp_f4_911;
    s32 temp_r3_806;
    s32 var_r0_816;
    void *temp_r3_747;
    if (MKModel_GetRefPointMatrix(this->unk4, this->unk388, (Matrix *) &arg_sp110, 1U) != 0) {
        if (this->unk390 > CYNDER_BURST_BREATH_START_TIME) {
            temp_f2_733 = this->unk38C;
            arg_spF8 = arg_sp140;
            arg_sp100 = arg_sp148;
            temp_f31_743 = temp_f2_733 + gUpdateTimeDelta;
            temp_r3_747 = M2C_FIELD(M2C_FIELD(*gb, void *(**)(void **, f64, f32), 0xC)(gb, arg_sp140, temp_f2_733), void **, 8);
            arg_spC8 = M2C_FIELD(temp_r3_747, f64 *, 0x30);
            arg_spD0 = M2C_FIELD(temp_r3_747, f64 *, 0x38);
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r30, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
            arg_spD8 = arg_sp48;
            arg_sp50 = (f32) arg_spD0 - (f32) arg_sp148;
            arg_spE0 = (f64) arg_sp50;
            var_f4_771 = ((f32) arg_spE0 * (f32) arg_spE0) + (((f32) arg_spD8 * (f32) arg_spD8) + (arg_spDC * arg_spDC));
            if (var_f4_771 > 1e-12f) {
                if (var_f4_771 > 0.0f) {
                    temp_f1_777 = __frsqrte(var_f4_771);
                    temp_f1_783 = 0.5 * temp_f1_777 * -(((f64) var_f4_771 * (temp_f1_777 * temp_f1_777)) - 3.0);
                    temp_f1_787 = 0.5 * temp_f1_783 * -(((f64) var_f4_771 * (temp_f1_783 * temp_f1_783)) - 3.0);
                    var_f4_771 = (f32) ((f64) var_f4_771 * (0.5 * temp_f1_787 * -(((f64) var_f4_771 * (temp_f1_787 * temp_f1_787)) - 3.0)));
                } else if (var_f4_771 < M2C_BITWISE(f32, 0.0)) {
                    var_f4_771 = __float_nan;
                } else {
                    arg_sp10 = var_f4_771;
                    temp_r3_806 = M2C_BITWISE(s32, arg_sp10) & 0x7F800000;
                    switch (temp_r3_806) {          /* irregular */
                    case 0x7F800000:
                        if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                            var_r0_816 = 1;
                        } else {
                            var_r0_816 = 2;
                        }
                        break;
                    case 0x0:
                        if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                            var_r0_816 = 5;
                        } else {
                            var_r0_816 = 3;
                        }
                        break;
                    default:
                        var_r0_816 = 4;
                        break;
                    }
                    if (var_r0_816 == 1) {
                        var_f4_771 = __float_nan;
                    }
                }
                var_f4_838 = 1.0f / var_f4_771;
            } else {
                var_f4_838 = 0.0f;
            }
            arg_sp3C = arg_spDC * var_f4_838;
            arg_sp38 = (f32) arg_spD8 * var_f4_838;
            arg_sp40 = (f32) arg_spE0 * var_f4_838;
            arg_spE8 = (f64) arg_sp38;
            arg_spF0 = (f64) arg_sp40;
            temp_f1_856 = this->unk38C;
            if ((temp_f1_856 == 0.0f) || ((temp_f1_856 < 0.0f) && (temp_f31_743 > 0.0f))) {
                this->unk320 = arg_spE8;
                this->unk328 = arg_spF0;
                memset(&this->unk330, 0, 0x10U);
                KDSound_Play3d(GS_SWCynderFireBreathStart, this->unk8 + 0x30, 0U, -1, 0.0f, 0U);
                this->unk3F8 = 1;
                SetHitList__14CynderBreathFXFP18MKPtrList<6MKProp>(this->unk384, &this->unk3FC);
                temp_f2_885 = this->unk320;
                temp_f0_887 = this->unk328;
                arg_spA8 = temp_f2_885;
                arg_spB0 = temp_f0_887;
                arg_spB8 = temp_f2_885;
                arg_spC0 = temp_f0_887;
                this->unk384->Trigger((MKProp *) this, *((MKVector3 *) &arg_spF8), *((MKVector3 *) &arg_spB8), *((MKVector3 *) &arg_spA8), 1.5f, this->unk388, 5.0f);
            }
            this->unk38C = temp_f31_743;
            if (this->unk38C > 0.0f) {
                arg_sp98.Update(*((MKVector3 *) &this->unk320), 1.3f);
                temp_f4_911 = this->unk320;
                temp_f3_912 = this->unk328;
                arg_sp68 = temp_f4_911;
                arg_sp70 = temp_f3_912;
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
                arg_sp78 = arg_sp28;
                arg_sp30 = (f32) arg_sp70 * 2800.0f;
                arg_sp80 = (f64) arg_sp30;
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                arg_sp58 = temp_f4_911;
                arg_sp88 = arg_sp18;
                arg_sp20 = (f32) arg_sp100 + (f32) arg_sp80;
                arg_sp60 = temp_f3_912;
                arg_sp90 = (f64) arg_sp20;
                this->unk384->UpdateBeamSpeedWay(*((MKVector3 *) &arg_spF8), *((MKVector3 *) &arg_sp88), *((MKVector3 *) &arg_sp58));
                if ((this->unk390 < CYNDER_FULL_BREATH_START_TIME) && (this->unk38C > 1.0f)) {
                    this->unk38C = -1.0f;
                    this->unk384->End();
                    this->unk3F8 = 0;
                    KDSound_Play3d(GS_SWCynderFireBreathStop, this->unk8 + 0x30, 0U, -1, 0.0f, 0U);
                }
            }
        } else if (this->unk38C > 0.0f) {
            this->unk38C = 0.0f;
            this->unk384->End();
            this->unk3F8 = 0;
            KDSound_Play3d(GS_SWCynderFireBreathStop, this->unk8 + 0x30, 0U, -1, 0.0f, 0U);
        }
    }
}
#endif

void SpeedwayCynder::SetAnim(MKAnim *arg0, float arg1, unsigned int arg2) {
    this->unk80->SetAnim(arg0, 1.0f, arg1, (s32) arg2, -1);
}

void SpeedwayCynder::SetAnim(int arg0, float arg1, unsigned int arg2) {
    SetAnim(M2C_FIELD((this + (arg0 * 4)), MKAnim **, 0x260), arg1, arg2);
}

#if 0 // DRAFT: undefined identifier 'unk24C'
void SpeedwayCynder::PostLTWUpdate() {
    f32 temp_f0_1064;
    f32 var_f1_1054;
    f32 var_f2_1063;

    this->unk350 = M2C_FIELD(this, f64 *, 0x340);
    this->unk358 = M2C_FIELD(this, f64 *, 0x348);
    MKModel_CalculateNodeWorldPosition(this->unk4, this->unk360, &this->unk340);
    this->unk364 += 0.1f * gUpdateTimeDelta;
    var_f1_1054 = _table_sinf(this->unk364);
    if (var_f1_1054 < 0.0f) {
        var_f1_1054 = -var_f1_1054;
    }
    this->unk368 = var_f1_1054;
    var_f2_1063 = 0.0f;
    temp_f0_1064 = this->unk244 - gUpdateTimeDelta;
    if (var_f2_1063 > temp_f0_1064) {

    } else {
        var_f2_1063 = temp_f0_1064;
    }
    this->unk244 = var_f2_1063;
    if ((EventCamera_GetCurrent() != NULL) && (this->unk24C.GetState() != 3)) {
        SetState((SpeedwayCynder::State) 3);
    } else if ((EventCamera_GetCurrent() == NULL) && (this->unk24C.GetState() == 3)) {
        SetState((SpeedwayCynder::State) 0);
    }
    this->unk24C.Update(this, 0);
    UpdateSound();
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_sp18C'
void SpeedwayCynder::UpdateLTW(const Matrix *arg0, bool arg1) {
    f32 *temp_r3_1324;
    f32 var_f1_1270;
    f32 var_f31_1261;
    M2C_STRUCT_COPY((s32) &arg_sp18C + 4, (s32) (arg0 - 4) + 4, 0x40);
    if (arg1 != 0) {
        arg_sp40 = -arg_sp190;
        arg_sp44 = -arg_sp194;
        arg_sp48 = -arg_sp198;
        this->unk280 = (f64) arg_sp40;
        arg_sp140 = (f64) arg_sp40;
        arg_sp148 = (f64) arg_sp48;
        this->unk288 = (f64) arg_sp48;
        memset(&this->unk290, 0, 0x10U);
        this->unk2A0 = arg_sp1A0;
        this->unk2A8 = arg_sp1A8;
        memset(&this->unk2B0, 0, 0x10U);
        arg_sp30 = -arg_sp1B0;
        arg_sp34 = -arg_sp1B4;
        arg_sp38 = -arg_sp1B8;
        this->unk2C0 = (f64) arg_sp30;
        arg_sp130 = (f64) arg_sp30;
        arg_sp138 = (f64) arg_sp38;
        this->unk2C8 = (f64) arg_sp38;
        memset(&this->unk2D0, 0, 0x10U);
    } else {
        arg_sp60 = -arg_sp190;
        arg_sp64 = -arg_sp194;
        arg_sp68 = -arg_sp198;
        arg_sp110 = (f64) arg_sp60;
        arg_sp118 = (f64) arg_sp68;
        arg_sp120.Update(*((MKVector3 *) &this->unk280), 1.7f);
        arg_sp100.Update(*((MKVector3 *) &this->unk2A0), 1.7f);
        arg_sp50 = -arg_sp1B0;
        arg_sp54 = -arg_sp1B4;
        arg_sp58 = -arg_sp1B8;
        arg_spE0 = (f64) arg_sp50;
        arg_spE8 = (f64) arg_sp58;
        arg_spF0.Update(*((MKVector3 *) &this->unk2C0), 1.7f);
    }
    arg_spD0 = this->unk280;
    arg_spD8 = this->unk288;
    this->unk2E0 = (f32) arg_spD0;
    this->unk2E4 = arg_spD4;
    this->unk2E8 = (f32) arg_spD8;
    this->unk2EC = 0.0f;
    arg_spC0 = this->unk2A0;
    arg_spC8 = this->unk2A8;
    this->unk2F0 = (f32) arg_spC0;
    this->unk2F4 = arg_spC4;
    this->unk2F8 = (f32) arg_spC8;
    this->unk2FC = 0.0f;
    arg_spB0 = this->unk2C0;
    arg_spB8 = this->unk2C8;
    this->unk300 = (f32) arg_spB0;
    this->unk304 = arg_spB4;
    this->unk308 = (f32) arg_spB8;
    this->unk30C = 0.0f;
    if (this->unk37C->UsePulledBackCamera() != 0) {
        var_f31_1261 = 650.0f;
    } else {
        var_f31_1261 = CYNDER_CAMERA_Y_OFFSET;
    }
    if (this->unk37C->UsePulledBackCamera() != 0) {
        var_f1_1270 = 1200.0f;
    } else {
        var_f1_1270 = GetCameraZOffset();
    }
    arg_sp70.operator*(var_f1_1270);
    arg_sp80.operator*(var_f31_1261);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    arg_sp90 = arg_sp10;
    arg_sp18 = arg_sp1C8 - arg_sp88;
    arg_sp98 = (f64) arg_sp18;
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    arg_spA0 = arg_sp20;
    arg_sp28 = (f32) arg_sp98 - arg_sp78;
    this->unk310 = (f32) arg_spA0;
    arg_spA8 = (f64) arg_sp28;
    this->unk314 = arg_spA4;
    this->unk318 = (f32) arg_spA8;
    this->unk31C = 1.0f;
    this->unk30C = 0.0f;
    this->unk2FC = 0.0f;
    this->unk2EC = 0.0f;
    this->unk31C = 1.0f;
    arg_sp150.SetRotationRoll(this->unk3A0);
    temp_r3_1324 = &this->unk2E0;
    temp_r3_1324->Multiply3x3((Matrix *) temp_r3_1324, (Matrix *) &arg_sp150);
    MKModel_SetWorldMatrix(this->unk4, *((Matrix *) &this->unk2E0));
}
#endif

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'SpeedwayCynder::State'
void SpeedwayCynder::SetState(SpeedwayCynder::State arg1) {
    this->unk24C.SetState(this, (s32) arg1, 1U);
}
#endif

#if 0 // DRAFT: undefined identifier 'unk24C'
u8 SpeedwayCynder::AnyToFlinchTransition() {
    if (MKCollision_SweepSphereCollide(*((MKVector3 *) &this->unk350), this->unk340, CYNDER_HEAD_COLLISION_RADIUS, NULL, (MKCollisionMode) 5, 0) != 0) {
        if ((s32) this->unk24C.unk0 != 2) {
            this->unk24C.SetState(this, 2, 0U);
            return 1U;
        }
        return 0U;
    }
    return 0U;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk24C'
s32 SpeedwayCynder::FlinchTransition() {
    if ((this->unk390 < 0.025f) && ((s32) this->unk24C.unk0 != 0)) {
        this->unk24C.SetState(this, 0, 0U);
        return 1;
    }
    return 0;
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_sp10C'
void SpeedwayCynder::EventCameraUpdate() {
    f32 var_f1_1454;
    f32 var_f3_1581;
    f32 var_f4_1514;
    f64 temp_f1_1520;
    f64 temp_f1_1526;
    f64 temp_f1_1530;
    s32 temp_r3_1549;
    s32 var_r0_1559;
    M2C_STRUCT_COPY((s32) &arg_sp10C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
    var_f1_1454 = this->unk37C->unk2C0 - 0.001f;
    if (var_f1_1454 > 0.0f) {

    } else {
        var_f1_1454 = 0.0f;
    }
    arg_sp90.GetPathMatrix(var_f1_1454);
    M2C_STRUCT_COPY((s32) &arg_spCC + 4, (s32) &arg_sp8C + 4, 0x40);
    arg_sp38 = arg_sp100;
    arg_sp40 = arg_sp108;
    arg_sp50.GetPathMatrix(this->unk37C->unk2C0);
    M2C_STRUCT_COPY((s32) &arg_spCC + 4, (s32) &arg_sp4C + 4, 0x40);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r30, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    arg_sp28 = arg_sp18;
    arg_sp20 = (f32) arg_sp40 - (f32) arg_sp108;
    arg_sp30 = (f64) arg_sp20;
    var_f4_1514 = ((f32) arg_sp30 * (f32) arg_sp30) + (((f32) arg_sp28 * (f32) arg_sp28) + (arg_sp2C * arg_sp2C));
    if (var_f4_1514 > 0.000001f) {
        if (var_f4_1514 > 0.0f) {
            temp_f1_1520 = __frsqrte(var_f4_1514);
            temp_f1_1526 = 0.5 * temp_f1_1520 * -(((f64) var_f4_1514 * (temp_f1_1520 * temp_f1_1520)) - 3.0);
            temp_f1_1530 = 0.5 * temp_f1_1526 * -(((f64) var_f4_1514 * (temp_f1_1526 * temp_f1_1526)) - 3.0);
            var_f4_1514 = (f32) ((f64) var_f4_1514 * (0.5 * temp_f1_1530 * -(((f64) var_f4_1514 * (temp_f1_1530 * temp_f1_1530)) - 3.0)));
        } else if (var_f4_1514 < M2C_BITWISE(f32, 0.0)) {
            var_f4_1514 = __float_nan;
        } else {
            arg_sp10 = var_f4_1514;
            temp_r3_1549 = M2C_BITWISE(s32, arg_sp10) & 0x7F800000;
            switch (temp_r3_1549) {                 /* irregular */
            case 0x7F800000:
                if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                    var_r0_1559 = 1;
                } else {
                    var_r0_1559 = 2;
                }
                break;
            case 0x0:
                if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                    var_r0_1559 = 5;
                } else {
                    var_r0_1559 = 3;
                }
                break;
            default:
                var_r0_1559 = 4;
                break;
            }
            if (var_r0_1559 == 1) {
                var_f4_1514 = __float_nan;
            }
        }
        var_f3_1581 = 1.0f / var_f4_1514;
    } else {
        var_f3_1581 = 0.0f;
    }
    arg_sp28 = (f32) arg_sp28 * var_f3_1581;
    arg_sp2C *= var_f3_1581;
    arg_sp30 = (f32) arg_sp30 * var_f3_1581;
    KDMath_BuildMatrixFromFwd((Matrix *) &arg_sp110, *((MKVector3 *) &arg_sp28), NULL);
    arg_sp140 = (f32) arg_sp38;
    arg_sp144 = arg_sp3C;
    arg_sp148 = (f32) arg_sp40;
    arg_sp14C = 1.0f;
    UpdateLTW((Matrix *) &arg_sp110, 0U);
}
#endif

void SpeedwayCynder::EventCameraExit() {

}

void SpeedwayCynder::EventCameraEnter() {
    StateEnter();
    SetAnim(0, 0.1f, 0U);
    SetTargetZTime(0.0f, 1.0f);
}

void SpeedwayCynder::FlinchUpdate() {
    FlinchTransition();
}

void SpeedwayCynder::FlinchExit() {

}

void SpeedwayCynder::FlinchEnter() {
    StateEnter();
    SetAnim(6, 0.1f, 0U);
    SetTargetZTime(0.0f, 1.0f);
}

#if 0 // DRAFT: undefined identifier 'unkspC'
u8 SpeedwayCynder::AnyToBiteTransition() {
    f64 sp20;
    f64 sp18;
    f64 sp10;
    f64 sp8;
    SpeedWaySpyro *temp_r4_1715;
    SpeedWaySpyro *temp_r4_1733;
    u8 var_r4_1704;

    var_r4_1704 = ((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1DU) & 1;
    if (var_r4_1704 != 0) {
        M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
        var_r4_1704 = ((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1DU) & 1;
    }
    if (var_r4_1704 != 0) {
        temp_r4_1715 = this->unk37C;
        sp18 = temp_r4_1715->unk308;
        sp20 = temp_r4_1715->unk310;
        if ((f32) sp18 < 0.0f) {

        }
        var_r4_1704 = (u8) ((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1FU);
    }
    if (var_r4_1704 != 0) {
        temp_r4_1733 = this->unk37C;
        sp8 = temp_r4_1733->unk308;
        sp10 = temp_r4_1733->unk310;
        if (unkspC < 0.0f) {

        }
        var_r4_1704 = (u8) ((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1FU);
    }
    if ((var_r4_1704 != 0) && ((s32) this->unk24C.unk0 != 1)) {
        this->unk24C.SetState(this, 1, 0U);
        return 1U;
    }
    return 0U;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk24C'
void SpeedwayCynder::BiteTransition() {
    s32 temp_r0_1778;
    u8 var_r0_1782;
    u8 var_r3_1798;

    temp_r0_1778 = this->unk240;
    var_r0_1782 = temp_r0_1778 == 3;
    if ((u8) (temp_r0_1778 == 3) != 0) {
        var_r0_1782 = this->unk80->unk2C & 1;
    }
    if ((var_r0_1782 != 0) && ((s32) this->unk24C.unk0 != 0)) {
        this->unk24C.SetState(this, 0, 0U);
        var_r3_1798 = 1;
    } else {
        var_r3_1798 = 0;
    }
    if (var_r3_1798 == 0) {
        AnyToFlinchTransition();
    }
}
#endif

#if 0 // DRAFT: expression syntax error
void SpeedwayCynder::BiteUpdate() {
    u8 sp110;
    s32 sp10C;
    void *sp108;
    s32 sp104;
    f32 sp100;
    s32 spFC;
    s8 spFB;
    s8 spFA;
    s16 spF8;
    f32 spF4;
    f32 spF0;
    f32 spEC;
    f32 spE8;
    f32 spE4;
    f32 spE0;
    f32 spD8;
    f32 spD4;
    f32 spD0;
    f32 spC8;
    f32 spC4;
    f32 spC0;
    s8 spB9;
    s8 spB8;
    s32 spB4;
    f32 spB0;
    s32 spAC;
    s8 spAA;
    s8 spA9;
    s8 spA8;
    f64 spA0;                                       /* compiler-managed */
    f64 sp98;                                       /* compiler-managed */
    SpeedwayCynder *sp94;
    s32 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    s32 sp6C;
    s32 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f64 sp18;
    f64 sp10;
    f64 sp8;
    SpeedWaySpyro *temp_r3_2014;
    SpeedWaySpyro *temp_r4_1844;
    SpeedWaySpyro *temp_r4_1851;
    SpeedWaySpyro *temp_r4_1858;
    f64 temp_f1_1859;
    f64 temp_f2_1860;
    s32 temp_r0_1827;
    u32 var_r30_1951;

    this->unk248 += gUpdateTimeDelta;
    temp_r0_1827 = this->unk240;
    switch (temp_r0_1827) {                         /* irregular */
    case 0:
        if (this->unk248 > 0.33f) {
            bHitSpyro = 0;
            temp_r4_1844 = this->unk37C;
            sp58 = temp_r4_1844->unk308;
            sp60 = temp_r4_1844->unk310;
            enterX = (f32) sp58;
            temp_r4_1851 = this->unk37C;
            sp48 = temp_r4_1851->unk308;
            sp50 = temp_r4_1851->unk310;
            enterY = (f32) sp48;
            temp_r4_1858 = this->unk37C;
            temp_f1_1859 = temp_r4_1858->unk308;
            temp_f2_1860 = temp_r4_1858->unk310;
            sp38 = temp_f1_1859;
            sp8 = temp_f1_1859;
            sp10 = temp_f2_1860;
            sp40 = temp_f2_1860;
            M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
            if ((f32) sp38 == CYNDER_MAX_BITE_SIDE_OFFSET) {
                SetAnim(4, 0.0f, 0U);
            } else {
                sp28 = temp_f1_1859;
                sp30 = temp_f2_1860;
                M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
                if ((f32) sp28 == -CYNDER_MAX_BITE_SIDE_OFFSET) {
                    SetAnim(5, 0.0f, 0U);
                } else {
                    SetAnim(3, 0.0f, 0U);
                }
            }
            this->unk240 = 1;
        }
        break;
    case 1:
        if (this->unk80->CheckEvent(0) != 0) {
            this->unk240 = 2;
            SetTargetZTime(CYNDER_MAX_Z_TIME, 5.0f);
        }
        break;
    case 2:
        spC0 = 0.0f;
        spC4 = 0.0f;
        spC8 = 0.0f;
        spD0 = 0.0f;
        spD4 = 0.0f;
        spD8 = 0.0f;
        spE0 = 0.0f;
        spE4 = 0.0f;
        spE8 = 0.0f;
        spEC = 1.0f;
        spF0 = 0.0f;
        spF4 = 0.0f;
        spF8 = 0;
        spFA = 0;
        spFB = 0;
        spFC = 0;
        sp100 = 3.4028235e38f;
        sp104 = 0;
        sp108 = NULL;
        sp10C = -1;
        sp110 = 0;
        if (MKCollision_SweepSphereCollide(*((MKVector3 *) &this->unk350), this->unk340, CYNDER_HEAD_COLLISION_RADIUS, (MKCollisionResult *) &spC0, (MKCollisionMode) 2, 0) != 0) {
            if ((sp110 != 0) && (sp108 != NULL) && (var_r30_1951 = M2C_FIELD(sp108, u32 *, 8), ((var_r30_1951 == 0U) == 0))) {

            } else {
                var_r30_1951 = 0U;
            }
            if (var_r30_1951 == M2C_FIELD(*gb, u32 (**)(void **), 0xC)(gb)) {
                bHitSpyro = 1;
                sp6C = 0;
                sp68 = 7;
                sp90 = 1;
                sp94 = this;
                sp70 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
                sp78 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
                spA8 = 0;
                spB4 = 2;
                spB0 = 15.0f;
                spA9 = 0;
                spAA = 1;
                spAC = -1;
                sp80 = M2C_FIELD(&MKVector3::one, f64 *, 0);
                sp88 = M2C_FIELD(&MKVector3::one, f64 *, 8);
                spB8 = 0;
                if (this != NULL) {
                    sp18.GetPos();
                    sp98 = sp18;
                    spA0 = sp20;
                } else {
                    sp98 = 0.0f;
                    unksp9C = 0.0f;
                    spA0 = 0.0f;
                }
                spB9 = 0;
                temp_r3_2014 = this->unk37C;
                temp_r3_2014->Message(&sp68);
            }
        }
        if (this->unk80->CheckEvent(1) != 0) {
            this->unk240 = 3;
            SetTargetZTime(1.0f, 3.0f);
        }
        break;
    }
    BiteTransition();
}
#endif

#if 0 // DRAFT: function call 'MKRand_Float(long *, float, float)' does not match
void SpeedwayCynder::BiteExit() {
    this->unk244 = MKRand_Float(&gViewSeed, 1.5f, 3.0f);
}
#endif

void SpeedwayCynder::BiteEnter() {
    StateEnter();
    this->unk240 = 0;
    this->unk248 = 0.0f;
}

s32 SpeedwayCynder::GlideTransition() {
    s32 var_r31_2089;

    var_r31_2089 = 0;
    if ((AnyToFlinchTransition() != 0) || (AnyToBiteTransition() != 0)) {
        var_r31_2089 = 1;
    }
    return var_r31_2089;
}

void SpeedwayCynder::GlideUpdate() {
    MKAnimScript *temp_r4_2116;
    u32 temp_r5_2118;

    temp_r4_2116 = this->unk80;
    temp_r5_2118 = temp_r4_2116->unk20;
    if ((temp_r5_2118 == (u32) this->unk260) && ((s32) temp_r4_2116->unk44 == 3)) {
        SetAnim(1, 0.1f, 0U);
    } else if ((temp_r5_2118 == (u32) this->unk264) && (temp_r4_2116->unk2C & 1)) {
        SetAnim(0, 0.1f, 0U);
    }
    UpdateBreath();
    UpdateFireBomb();
    GlideTransition();
}

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'CynderBreathFX'
void SpeedwayCynder::GlideExit() {
    this->unk384->End();
    this->unk3F8 = 0;
    KDSound_Play3d(GS_SWCynderFireBreathStop, this->unk8 + 0x30, 0U, -1, 0.0f, 0U);
}
#endif

void SpeedwayCynder::GlideEnter() {
    StateEnter();
    SetAnim(0, 0.2f, 0U);
    this->unk38C = 0.0f;
    this->unk374 = 5.0f;
}

void SpeedwayCynder::StateEnter() {
    this->unk398 = -1.0f;
    this->unk39C = -1.0f;
}

#if 0 // DRAFT: undefined identifier 'unk24C'
void SpeedwayCynder::UpdateLookAtNodes() {
    f64 sp10;
    f64 sp8;
    s32 var_r30_2252;
    s32 var_r30_2264;
    s32 var_r31_2253;
    s32 var_r31_2265;
    void *temp_r5_2242;

    if ((this->unk390 > CYNDER_HEAD_TURN_START_TIME) || (this->unk24C.GetState() == 1)) {
        this->unk1F8 = 5.0f;
        temp_r5_2242 = M2C_FIELD(M2C_FIELD(*gb, void *(**)(void **), 0xC)(gb), void **, 8);
        sp8 = M2C_FIELD(temp_r5_2242, f64 *, 0x30);
        sp10 = M2C_FIELD(temp_r5_2242, f64 *, 0x38);
        this->unk204 = 0.5235987f;
        this->unk1F8.Update((MKVector3 *) &sp8);
        var_r30_2252 = 4;
        var_r31_2253 = 0x120;
        do {
            ((NodeLookAtIK *) (this + (var_r31_2253 + 0x90)))->Update(NULL);
            var_r30_2252 -= 1;
            var_r31_2253 -= 0x48;
        } while (var_r30_2252 >= 0);
        return;
    }
    var_r30_2264 = 0;
    var_r31_2265 = 0;
    do {
        ((NodeLookAtIK *) (this + (var_r31_2265 + 0x90)))->Update(NULL);
        var_r30_2264 += 1;
        var_r31_2265 += 0x48;
    } while (var_r30_2264 < 6);
}
#endif

#if 0 // DRAFT: undefined identifier 'unk24C'
void SpeedwayCynder::Deinit() {
    MKHeap *temp_r31_2300;
    MKHeap *temp_r3_2295;
    MKHeap *temp_r3_2304;

    this->unk24C.Deinit();
    do {
        temp_r3_2295 = this->unk3FC.unk0 - 4;
        this->unk3FC.unk0 = temp_r3_2295;
    } while ((MKHeap *) temp_r3_2295->unk0 != NULL);
    temp_r31_2300 = this->unk3FC.unk0;
    if (temp_r31_2300 != &gEmptyPtrList) {
        temp_r3_2304 = temp_r3_2295->Current();
        if (temp_r3_2304 != NULL) {
            ((MKHeap *) (temp_r3_2304->Current()))->Free(temp_r31_2300, NULL, 0);
        } else {
            free(temp_r31_2300);
        }
    }
    this->unk3FC.unk0 = NULL;
    KDSound_Stop(&this->unk3A8);
    KDSound_Stop(&this->unk3D0);
    KDSound_Stop(&this->unk370);
    KDProp::Deinit();
}
#endif

#if 0 // DRAFT: expression syntax error
void SpeedwayCynder::Message(MKMessage *arg0) {
    this->unk3A8.Message(arg0);
    this->unk3D0.Message(arg0);
    KDProp::Message(arg0);
    if ((s32) arg0->unk0 != 0x423) {
        return;
    }
    if (EventCamera_GetCurrent() == NULL) {
        UpdateLTW(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), Matrix **, 8), 0U);
    }
    PostLTWUpdate();
}
#endif

void SpeedwayCynder::Draw() {
    if (!(this->unk37C->unk2C0 < 0.003f)) {
        if (EventCamera_GetCurrent() == NULL) {
            MKView_Push();
            MKView_SetProjection(0.0f, 0.0f, 5000.0f);
        }
        KDProp::Draw();
        if (EventCamera_GetCurrent() == NULL) {
            MKView_Pop();
        }
    }
}

#if 0 // DRAFT: illegal type
void SpeedwayCynder::Update() {
    KDProp::Update();
    UpdateLookAtNodes();
    UpdateCameraZTime();
    UpdateCameraRoll();
    KDSound_Play3d(this->unk80, this->unk8 + 0x30, 0U, 0.0f, 0U);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'const char[15]' to
void SpeedwayCynder::Resolve() {
    MKProp::Resolve();
    this->unk380 = checked_cast<FireBombFXDescriptor *, MKPropDescriptor>(M2C_FIELD(*gMK, MKPropDescriptor *(**)(void **, void *), 0x5C)(gMK, "CynderFireBomb"));
    this->unk378 = checked_cast<SpeedWay *, MKProp>(M2C_FIELD(*gMK, MKProp *(**)(void **, void *), 0x60)(gMK, "SpeedWay"));
    this->unk37C = checked_cast<SpeedWaySpyro *, MKProp>(M2C_FIELD(*gMK, MKProp *(**)(void **, void *), 0x60)(gMK, "SpeedWaySpyro"));
}
#endif

#if 0 // DRAFT: undefined identifier 'unk330'
void SpeedwayCynder::Reset() {
    this->unk374 = 5.0f;
    this->unk36C = 10.0f;
    this->unk370 = 0;
    this->unk38C = 0.0f;
    this->unk3F8 = 0;
    this->unk320 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    this->unk328 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
    memset(&this->unk330, 0, 0x10U);
    this->unk240 = 1;
    this->unk248 = 0.0f;
    this->unk244 = 0.0f;
    this->unk390 = 0.0f;
    memset(&this->unk394, 0, 4U);
    this->unk398 = -1.0f;
    this->unk39C = -1.0f;
    this->unk3A0 = 0.0f;
    memset(&this->unk3A4, 0, 4U);
    this->unk8 = &this->unk2E0;
    arg_sp10.GetPathMatrix(0.0f);
    M2C_STRUCT_COPY((s32) &arg_sp4C + 4, (s32) &arg_spC + 4, 0x40);
    UpdateLTW((Matrix *) &arg_sp50, 1U);
    MKModel_CalculateNodeWorldPosition(this->unk4, this->unk360, &this->unk340);
    this->unk350 = M2C_FIELD(this, f64 *, 0x340);
    this->unk358 = M2C_FIELD(this, f64 *, 0x348);
    SetState((SpeedwayCynder::State) 0);
}
#endif

#if 0 // DRAFT: function call 'GetAnim(signed char *)' does not match
void SpeedwayCynder::LoadDone() {
    s32 temp_r0_2710;
    s32 temp_r0_2715;
    s32 temp_r0_2733;
    s32 temp_r4_2711;
    s32 var_ctr_2681;
    s32 var_ctr_2708;
    s32 var_ctr_2731;
    s32 var_r26_2591;
    s32 var_r30_2592;
    s32 var_r3_2679;
    s32 var_r3_2706;
    s32 var_r3_2730;
    s32 var_r7_2678;
    s32 var_r7_2705;
    void *temp_r4_2684;
    void *temp_r4_2694;
    void *temp_r6_2683;

    KDProp::LoadDone();
    var_r26_2591 = 0;
    var_r30_2592 = 0;
    do {
        var_r26_2591 += 1;
        *(this + (var_r30_2592 + 0x260)) = this->unk80->GetAnim(Str_Printf("speedway_%s", *(&lit_739 + 0x120 + var_r30_2592)));
        var_r30_2592 += 4;
    } while (var_r26_2591 < 7);
    this->unk80->InitEvents(&lit_739 + 0x140);
    Init__32KDStateMachine<14SpeedwayCynder>FPQ232KDStateMachine<14SpeedwayCynder>5StateP32KDStateMachine<14SpeedwayCynder>(&this->unk24C, &lit_739 + 0x90, NULL);
    this->unk388 = (s32) Tools_GetMatchingRefPointIndex(this->unk4, "BreathDir");
    this->unk360 = (s32) Tools_GetMatchingNodeIndex(this->unk4, "Head");
    this->unk90.Init(this->unk4, (s32) Tools_GetMatchingNodeIndex(this->unk4, "Neck01"));
    this->unkD8.Init(this->unk4, (s32) Tools_GetMatchingNodeIndex(this->unk4, "Neck02"));
    this->unk120.Init(this->unk4, (s32) Tools_GetMatchingNodeIndex(this->unk4, "Neck03"));
    this->unk168.Init(this->unk4, (s32) Tools_GetMatchingNodeIndex(this->unk4, "Neck04"));
    this->unk1B0.Init(this->unk4, (s32) Tools_GetMatchingNodeIndex(this->unk4, "Neck05"));
    this->unk1F8.Init(this->unk4, this->unk360);
    var_r7_2678 = 1;
    var_r3_2679 = 0x48;
    var_ctr_2681 = 5;
    do {
        temp_r6_2683 = this + var_r3_2679;
        temp_r4_2684 = M2C_FIELD(temp_r6_2683, void **, 0xD0);
        if (temp_r4_2684 != NULL) {
            M2C_FIELD(temp_r4_2684, void **, 0x44) = NULL;
        }
        M2C_FIELD(temp_r6_2683, void **, 0xD0) = (void *) (this + (((var_r7_2678 - 1) * 0x48) + 0x90));
        temp_r4_2694 = M2C_FIELD(temp_r6_2683, void **, 0xD0);
        if (temp_r4_2694 != NULL) {
            M2C_FIELD(temp_r4_2694, void **, 0x44) = (void *) (temp_r6_2683 + 0x90);
        }
        var_r7_2678 += 1;
        var_r3_2679 += 0x48;
        var_ctr_2681 -= 1;
    } while (var_ctr_2681 != 0);
    var_r7_2705 = 0;
    var_r3_2706 = 0;
    var_ctr_2708 = 5;
    do {
        temp_r0_2710 = var_r7_2705 + 1;
        temp_r4_2711 = var_r7_2705 + 2;
        temp_r0_2715 = var_r3_2706 + 0xA8;
        var_r7_2705 += 1;
        var_r3_2706 += 0x48;
        *(this + temp_r0_2715) = (f32) temp_r0_2710 / (f32) temp_r4_2711;
        var_ctr_2708 -= 1;
    } while (var_ctr_2708 != 0);
    var_r3_2730 = 0;
    var_ctr_2731 = 6;
    do {
        temp_r0_2733 = var_r3_2730 + 0x90;
        var_r3_2730 += 0x48;
        *(this + temp_r0_2733) = 5.0f;
        var_ctr_2731 -= 1;
    } while (var_ctr_2731 != 0);
    this->unk204 = 0.5235987f;
    this->unk208 = 2.8274333f;
    gMK->CreatePropDeferred("CynderBreathFX", (MKProp **) &this->unk384);
}
#endif

#if 0 // DRAFT: expression syntax error
void SpeedwayCynder::Init() {
    FireBombFX *temp_r3_2790;
    MKHeap *temp_r3_2803;
    MKHeap *temp_r3_2825;
    MKHeap *temp_r3_2830;
    MKHeap *var_r3_2810;
    s32 var_ctr_2823;
    s32 var_r29_2784;

    KDProp::Init();
    this->unk364 = 0.0f;
    this->unk368 = 0.0f;
    this->unk3F8 = 0;
    this->unk380 = NULL;
    this->unk384 = NULL;
    this->unk3A8.Init(0.25f, 0.25f);
    this->unk3D0.Init(0.25f, 0.25f);
    this->unk388 = 0xFFFF;
    var_r29_2784 = 0;
    this->unk38C = 0.0f;
    do {
        temp_r3_2790 = checked_cast<FireBombFX *, MKProp>(gMK->CreateProp("CynderFireBomb"));
        if (temp_r3_2790 != NULL) {
            M2C_FIELD(temp_r3_2790->__vptr, M2C_UNK (**)(), 0x34)();
        }
        var_r29_2784 += 1;
    } while (var_r29_2784 < 8);
    this->unk2E0.SetIdentity();
    temp_r3_2803 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_2803 != NULL) {
        var_r3_2810 = ((MKHeap *) (temp_r3_2803->Current()))->Alloc(0x30, NULL, 0);
    } else {
        var_r3_2810 = malloc(0x30);
    }
    this->unk3FC.unk0 = var_r3_2810;
    this->unk3FC.unk0->unk0 = NULL;
    var_ctr_2823 = 0xA;
    do {
        temp_r3_2825 = this->unk3FC.unk0;
        this->unk3FC.unk0 = (MKHeap *) &temp_r3_2825->unk4;
        temp_r3_2825->unk4 = -0x21524111;
        var_ctr_2823 -= 1;
    } while (var_ctr_2823 != 0);
    temp_r3_2830 = this->unk3FC.unk0;
    this->unk3FC.unk0 = (MKHeap *) &temp_r3_2830->unk4;
    temp_r3_2830->unk4 = 0;
}
#endif

void SpeedwayCynder_cpp::__sinit() {
    f64 temp_f0_3083;
    f64 temp_f1_3053;
    f64 temp_f1_3077;
    f64 temp_f3_3039;
    f64 temp_f3_3080;
    f64 temp_f4_3052;
    f64 temp_f4_3074;
    f64 temp_f8_3041;
    void *temp_r3_3044;

    temp_f3_3039 = __frsqrte(2014000.0);
    temp_f8_3041 = __frsqrte(380000.0);
    temp_r3_3044 = &lit_739 + 0x90;
    temp_f4_3052 = 0.5 * temp_f3_3039 * -((2014000.0 * (temp_f3_3039 * temp_f3_3039)) - 3.0);
    temp_f1_3053 = 0.5 * temp_f8_3041 * -((380000.0 * (temp_f8_3041 * temp_f8_3041)) - 3.0);
    temp_f4_3074 = 0.5 * temp_f4_3052 * -((2014000.0 * (temp_f4_3052 * temp_f4_3052)) - 3.0);
    temp_f1_3077 = 0.5 * temp_f1_3053 * -((380000.0 * (temp_f1_3053 * temp_f1_3053)) - 3.0);
    temp_f3_3080 = temp_f4_3074 * temp_f4_3074;
    temp_f0_3083 = temp_f1_3077 * temp_f1_3077;
    M2C_FIELD(&lit_739, s32 *, 0x90) = (s32) M2C_FIELD(&lit_739, s32 *, 0);
    M2C_FIELD(&lit_739, s32 *, 0x94) = (s32) M2C_FIELD(&lit_739, s32 *, 4);
    M2C_FIELD(&lit_739, s32 *, 0x98) = (s32) M2C_FIELD(&lit_739, s32 *, 8);
    M2C_FIELD(temp_r3_3044, s32 *, 0xC) = (s32) M2C_FIELD(&lit_739, s32 *, 0xC);
    M2C_FIELD(temp_r3_3044, s32 *, 0x10) = (s32) M2C_FIELD(&lit_739, s32 *, 0x10);
    M2C_FIELD(temp_r3_3044, s32 *, 0x14) = (s32) M2C_FIELD(&lit_739, s32 *, 0x14);
    M2C_FIELD(temp_r3_3044, s32 *, 0x18) = (s32) M2C_FIELD(&lit_739, s32 *, 0x18);
    M2C_FIELD(temp_r3_3044, s32 *, 0x1C) = (s32) M2C_FIELD(&lit_739, s32 *, 0x1C);
    M2C_FIELD(temp_r3_3044, s32 *, 0x20) = (s32) M2C_FIELD(&lit_739, s32 *, 0x20);
    M2C_FIELD(temp_r3_3044, s32 *, 0x24) = (s32) M2C_FIELD(&lit_739, s32 *, 0x24);
    M2C_FIELD(temp_r3_3044, s32 *, 0x28) = (s32) M2C_FIELD(&lit_739, s32 *, 0x28);
    M2C_FIELD(temp_r3_3044, s32 *, 0x2C) = (s32) M2C_FIELD(&lit_739, s32 *, 0x2C);
    M2C_FIELD(temp_r3_3044, s32 *, 0x30) = (s32) M2C_FIELD(&lit_739, s32 *, 0x30);
    M2C_FIELD(temp_r3_3044, s32 *, 0x34) = (s32) M2C_FIELD(&lit_739, s32 *, 0x34);
    M2C_FIELD(temp_r3_3044, s32 *, 0x38) = (s32) M2C_FIELD(&lit_739, s32 *, 0x38);
    M2C_FIELD(temp_r3_3044, s32 *, 0x3C) = (s32) M2C_FIELD(&lit_739, s32 *, 0x3C);
    M2C_FIELD(temp_r3_3044, s32 *, 0x40) = (s32) M2C_FIELD(&lit_739, s32 *, 0x40);
    M2C_FIELD(temp_r3_3044, s32 *, 0x44) = (s32) M2C_FIELD(&lit_739, s32 *, 0x44);
    SPYRO_BOUNCE_Y_SPEED = (f32) (2014000.0 * (0.5 * temp_f4_3074 * -((2014000.0 * temp_f3_3080) - 3.0)));
    SPYRO_MIN_JUMP_Y_VELOCITY = (f32) (380000.0 * (0.5 * temp_f1_3077 * -((380000.0 * temp_f0_3083) - 3.0)));
    M2C_FIELD(temp_r3_3044, s32 *, 0x48) = (s32) M2C_FIELD(&lit_739, s32 *, 0x48);
    M2C_FIELD(temp_r3_3044, s32 *, 0x4C) = (s32) M2C_FIELD(&lit_739, s32 *, 0x4C);
    M2C_FIELD(temp_r3_3044, s32 *, 0x50) = (s32) M2C_FIELD(&lit_739, s32 *, 0x50);
    M2C_FIELD(temp_r3_3044, s32 *, 0x54) = (s32) M2C_FIELD(&lit_739, s32 *, 0x54);
    M2C_FIELD(temp_r3_3044, s32 *, 0x58) = (s32) M2C_FIELD(&lit_739, s32 *, 0x58);
    M2C_FIELD(temp_r3_3044, s32 *, 0x5C) = (s32) M2C_FIELD(&lit_739, s32 *, 0x5C);
    M2C_FIELD(temp_r3_3044, s32 *, 0x60) = (s32) M2C_FIELD(&lit_739, s32 *, 0x60);
    M2C_FIELD(temp_r3_3044, s32 *, 0x64) = (s32) M2C_FIELD(&lit_739, s32 *, 0x64);
    M2C_FIELD(temp_r3_3044, s32 *, 0x68) = (s32) M2C_FIELD(&lit_739, s32 *, 0x68);
    M2C_FIELD(temp_r3_3044, s32 *, 0x6C) = (s32) M2C_FIELD(&lit_739, s32 *, 0x6C);
    M2C_FIELD(temp_r3_3044, s32 *, 0x70) = (s32) M2C_FIELD(&lit_739, s32 *, 0x70);
    M2C_FIELD(temp_r3_3044, s32 *, 0x74) = (s32) M2C_FIELD(&lit_739, s32 *, 0x74);
    M2C_FIELD(temp_r3_3044, s32 *, 0x78) = (s32) M2C_FIELD(&lit_739, s32 *, 0x78);
    M2C_FIELD(temp_r3_3044, s32 *, 0x7C) = (s32) M2C_FIELD(&lit_739, s32 *, 0x7C);
    M2C_FIELD(temp_r3_3044, s32 *, 0x80) = (s32) M2C_FIELD(&lit_739, s32 *, 0x80);
    M2C_FIELD(temp_r3_3044, s32 *, 0x84) = (s32) M2C_FIELD(&lit_739, s32 *, 0x84);
    M2C_FIELD(temp_r3_3044, s32 *, 0x88) = (s32) M2C_FIELD(&lit_739, s32 *, 0x88);
    M2C_FIELD(temp_r3_3044, s32 *, 0x8C) = (s32) M2C_FIELD(&lit_739, s32 *, 0x8C);
}
