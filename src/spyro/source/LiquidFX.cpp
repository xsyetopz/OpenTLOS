#include "spyro/source/LiquidFX.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/CrashFirePS.h"
#include "spyro/source/CrashMistPS.h"
#include "spyro/source/EmbersPS.h"
#include "spyro/source/GameMessages.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/HeatDistortPS.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDWaterVolume.h"
#include "spyro/source/LightManager.h"
#include "spyro/source/ManagedLight.h"
#include "unplaced_templates.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKModel.h"
#include "common/Source/StdMath.h"
#include "common/gc/MKMaterial_GC.h"
#include "common/gc/MKModel_GC.h"
#include "common/gc/MKPrimitive_GC.h"
#include "spyro/source/EventCamera.h"
#include "spyro/source/KDMath.h"
#include "spyro/source/KDSound.h"
#include <m2c_macros.h>

extern MKSceneManager *gMK;
extern MKMaterial *gRenderState;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern M2C_UNK gb;
static s32 lit_688 = 0;
static u8 lit_689 = 1;

#if 0 // DRAFT: function call 'MKRand_Float(long *, float, float)' does not match
static f32 IMPACT_LIGHT_RADIUS = 1000.0f;           /* const */

void LiquidFX::SpawnGroundCollisionFX(LFX_Blob *arg0) {
    f64 sp130;                                      /* compiler-managed */
    f64 sp128;                                      /* compiler-managed */
    f64 sp120;
    f64 sp118;
    f64 sp110;
    f64 sp108;
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
    f64 spB0;
    f64 spA8;
    f32 spA0;
    f32 sp9C;
    f32 sp98;
    f32 sp90;
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    f32 sp70;
    f32 sp60;
    f32 sp50;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp30;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f0_184;
    f32 temp_f1_309;
    f32 temp_f25_229;
    f32 temp_f25_278;
    f32 temp_f26_224;
    f32 temp_f26_283;
    f32 temp_f26_91;
    f32 temp_f30_219;
    f32 temp_f31_218;
    f32 var_f27_84;
    f32 var_f4_110;
    f64 temp_f1_115;
    f64 temp_f1_121;
    f64 temp_f1_125;
    s32 temp_r0_70;
    s32 temp_r3_144;
    s32 temp_r3_59;
    s32 var_r0_154;
    s32 var_r29_212;

    temp_r3_59 = arg0->unk9C;
    if (temp_r3_59 != 0) {
        KDSound_Play3d(temp_r3_59, (MKVector3 *) arg0, 0U, -1, 0.0f, 0U);
        arg0->unk9C = 0;
    }
    temp_r0_70 = this->unk3F78;
    switch (temp_r0_70) {                           /* switch 1; irregular */
    case 1:                                         /* switch 1 */
        var_f27_84 = 0.0f;
        temp_f26_91 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        sp98 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        sp9C = 0.0f;
        spA0 = temp_f26_91;
        sp128 = (f64) sp98;
        sp130 = (f64) spA0;
        var_f4_110 = ((f32) sp130 * (f32) sp130) + (((f32) sp128 * (f32) sp128) + (unksp12C * unksp12C));
        if (var_f4_110 > 0.000001f) {
            if (var_f4_110 > 0.0f) {
                temp_f1_115 = __frsqrte(var_f4_110);
                temp_f1_121 = 0.5 * temp_f1_115 * -(((f64) var_f4_110 * (temp_f1_115 * temp_f1_115)) - 3.0);
                temp_f1_125 = 0.5 * temp_f1_121 * -(((f64) var_f4_110 * (temp_f1_121 * temp_f1_121)) - 3.0);
                var_f4_110 = (f32) ((f64) var_f4_110 * (0.5 * temp_f1_125 * -(((f64) var_f4_110 * (temp_f1_125 * temp_f1_125)) - 3.0)));
            } else if (var_f4_110 < M2C_BITWISE(f32, 0.0)) {
                var_f4_110 = __float_nan;
            } else {
                sp8 = var_f4_110;
                temp_r3_144 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                switch (temp_r3_144) {              /* switch 2; irregular */
                case 0x7F800000:                    /* switch 2 */
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_154 = 1;
                    } else {
                        var_r0_154 = 2;
                    }
                    break;
                case 0x0:                           /* switch 2 */
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_154 = 5;
                    } else {
                        var_r0_154 = 3;
                    }
                    break;
                default:                            /* switch 2 */
                    var_r0_154 = 4;
                    break;
                }
                if (var_r0_154 == 1) {
                    var_f4_110 = __float_nan;
                }
            }
            var_f27_84 = 1.0f / var_f4_110;
        }
        temp_f0_184 = (f32) sp130 * var_f27_84;
        sp128 = (f32) sp128 * var_f27_84;
        unksp12C *= var_f27_84;
        sp130 = temp_f0_184;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f1, $f1, $f30 */);
        sp90 = temp_f0_184 * 410.0f;
        sp118 = sp88;
        sp120 = (f64) sp90;
        sp10 = MKRand_Float(&gViewSeed, 6.1f, 8.0f);
        ((CrashFirePS *) (M2C_FIELD(&gb, CrashFirePS **, 0x68)))->Emit(*((MKVector3 *) arg0), *((MKVector3 *) &sp118), sp10);
        return;
    case 3:                                         /* switch 1 */
        var_r29_212 = 0;
        do {
            temp_f31_218 = MKRand_Float(&gViewSeed, 0.1f, 1.0f);
            temp_f30_219 = arg0->unk28;
            temp_f26_224 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
            temp_f25_229 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
            sp78 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
            sp7C = temp_f25_229;
            sp80 = temp_f26_224;
            spD8 = (f64) sp78;
            spE0 = (f64) sp80;
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
            spE8 = sp68;
            sp70 = (f32) spE0 * temp_f30_219;
            spF0 = (f64) sp70;
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
            spF8 = sp58;
            sp60 = (f32) spF0 * 75.0f;
            sp100 = (f64) sp60;
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r31, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            sp108 = sp48;
            sp50 = arg0->unk8 + (f32) sp100;
            sp110 = (f64) sp50;
            temp_f25_278 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
            temp_f26_283 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
            sp38 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
            sp3C = temp_f26_283;
            sp40 = temp_f25_278;
            spB8 = (f64) sp38;
            spC0 = (f64) sp40;
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f28 */);
            spC8 = sp28;
            sp30 = (f32) spC0 * 310.0f;
            spD0 = (f64) sp30;
            temp_f1_309 = MKRand_Float(&gViewSeed, 7.1f, 15.0f);
            sp18 = temp_f31_218;
            sp1C = temp_f31_218;
            spC = temp_f1_309;
            sp20 = 1.0f;
            sp24 = 1.0f;
            spA8 = (f64) sp18;
            spB0 = (f64) sp20;
            ((EmbersPS *) (M2C_FIELD(&gb, EmbersPS **, 0x74)))->Emit(*((MKVector3 *) &sp108), *((MKVector3 *) &spC8), spC, *((MKVector4 *) &spA8), 0.0f);
            var_r29_212 += 1;
        } while (var_r29_212 < 5);
        /* fallthrough */
    case 2:                                         /* switch 1 */
    case 0:                                         /* switch 1 */
        return;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'sp28'
s32 LiquidFX::Emit(const int &arg0, const MKVector3 &arg1, const MKVector3 &arg2, const MKVector3 &arg3, const float &arg4, float arg5, bool arg6, BreathHitMessage *arg7, int arg8, int arg9) {
    s8 spE8;
    s32 spE4;
    s32 spE0;
    s32 spDC;
    f32 spD8;
    s32 spD4;
    s8 spD3;
    s8 spD2;
    s16 spD0;
    f32 spCC;
    f32 spC8;
    f32 spC4;
    f32 spC0;
    f32 spBC;
    f32 spB8;
    f32 spB0;
    f32 spAC;
    f32 spA8;
    f32 spA0;
    f32 sp9C;
    f32 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    M2C_UNK sp48;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp30;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 temp_f29_497;
    f32 temp_f29_524;
    f32 temp_f30_502;
    f32 temp_f30_529;
    f64 temp_f4_464;
    f64 temp_f5_462;
    void *temp_r3_554;
    void *temp_r3_574;
    void *temp_r3_585;
    void *temp_r4_374;
    void *temp_r4_475;
    void *temp_r4_481;
    void *temp_r4_487;
    void *temp_r4_493;
    void *temp_r4_517;

    temp_r4_374 = this + (this->unk3F5C * 0xA0);
    if ((u8) M2C_FIELD(temp_r4_374, u8 *, 0x158) != 0) {
        return 0;
    }
    M2C_FIELD(temp_r4_374, u8 *, 0x158) = 1U;
    sp98 = 0.0f;
    sp9C = 0.0f;
    spA0 = 0.0f;
    spA8 = 0.0f;
    spAC = 0.0f;
    spB0 = 0.0f;
    spB8 = 0.0f;
    spBC = 0.0f;
    spC0 = 0.0f;
    spC4 = 1.0f;
    spC8 = 0.0f;
    spCC = 0.0f;
    spD0 = 0;
    spD2 = 0;
    spD3 = 0;
    spD4 = 0;
    spD8 = 3.4028235e38f;
    spDC = 0;
    spE0 = 0;
    spE4 = -1;
    spE8 = 0;
    if (arg6 != 0) {
        M2C_FIELD((this + (this->unk3F5C * 0xA0)), f32 *, 0x154) = arg5;
    } else {
        sp40 = 0.0f;
        sp38 = 0.0f;
        sp3C = 200.0f;
        sp80 = (f64) sp40;
        sp78 = (f64) sp38;
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r25, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        sp88 = sp28;
        sp30 = arg1.unk8 + (f32) sp80;
        sp90 = (f64) sp30;
        if (MKCollision_GetGroundPoint(*((MKVector3 *) &sp88), 3000.0f, (MKCollisionResult *) &sp98, 0, 2, NULL, (MKCollisionMode) 6) != 0) {
            M2C_FIELD((this + (this->unk3F5C * 0xA0)), f32 *, 0x154) = sp9C;
        }
    }
    temp_f5_462 = M2C_FIELD(&arg3, f64 *, 0);
    M2C_FIELD((this + (this->unk3F5C * 0xA0)), f32 *, 0x14C) = 0.0f;
    temp_f4_464 = M2C_FIELD(&arg3, f64 *, 8);
    M2C_FIELD((this + (this->unk3F5C * 0xA0)), f32 *, 0x150) = (f32) &arg4;
    temp_r4_475 = this + ((this->unk3F5C * 0xA0) + 0xC8);
    M2C_FIELD(temp_r4_475, f64 *, 0) = (f64) M2C_FIELD(&arg1, f64 *, 0);
    M2C_FIELD(temp_r4_475, f64 *, 8) = (f64) M2C_FIELD(&arg1, f32 *, 8);
    temp_r4_481 = this + ((this->unk3F5C * 0xA0) + 0xE8);
    M2C_FIELD(temp_r4_481, f64 *, 0) = temp_f5_462;
    M2C_FIELD(temp_r4_481, f64 *, 8) = temp_f4_464;
    temp_r4_487 = this + ((this->unk3F5C * 0xA0) + 0xF8);
    M2C_FIELD(temp_r4_487, f64 *, 0) = temp_f5_462;
    M2C_FIELD(temp_r4_487, f64 *, 8) = temp_f4_464;
    temp_r4_493 = this + ((this->unk3F5C * 0xA0) + 0xD8);
    M2C_FIELD(temp_r4_493, f64 *, 0) = (f64) M2C_FIELD(&arg2, f64 *, 0);
    M2C_FIELD(temp_r4_493, f64 *, 8) = (f64) M2C_FIELD(&arg2, f64 *, 8);
    temp_f29_497 = MKRand_Float(&gViewSeed, 0.0f, 20.0f);
    temp_f30_502 = MKRand_Float(&gViewSeed, 0.0f, 20.0f);
    sp18 = MKRand_Float(&gViewSeed, 0.0f, 20.0f);
    sp1C = temp_f30_502;
    sp20 = temp_f29_497;
    temp_r4_517 = this + ((this->unk3F5C * 0xA0) + 0x108);
    M2C_FIELD(temp_r4_517, f64 *, 0) = (f64) sp18;
    sp68 = (f64) sp18;
    sp70 = (f64) sp20;
    M2C_FIELD(temp_r4_517, f64 *, 8) = (f64) sp20;
    temp_f29_524 = MKRand_Float(&gViewSeed, 20.0f, 60.0f);
    temp_f30_529 = MKRand_Float(&gViewSeed, 20.0f, 60.0f);
    MKVector(MKRand_Float(&gViewSeed, 20.0f, 60.0f), temp_f30_529, temp_f29_524);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
    sp10 = sp50 * 0.05f;
    temp_r3_554 = this + ((this->unk3F5C * 0xA0) + 0x118);
    M2C_FIELD(temp_r3_554, f64 *, 0) = sp8;
    M2C_FIELD(temp_r3_554, f64 *, 8) = (f64) sp10;
    sp58 = sp8;
    sp60 = (f64) sp10;
    M2C_FIELD((this + (this->unk3F5C * 0xA0)), s8 *, 0x159) = 0;
    M2C_FIELD((this + (this->unk3F5C * 0xA0)), f32 *, 0x148) = 0.0f;
    M2C_FIELD((this + (this->unk3F5C * 0xA0)), f32 *, 0x160) = 0.0f;
    temp_r3_574 = this + (this->unk3F5C * 0xA0);
    M2C_FIELD(temp_r3_574, f32 *, 0x15C) = (f32) ((M2C_FIELD(temp_r3_574, f32 *, 0x100) + (M2C_FIELD(temp_r3_574, f32 *, 0xF8) + M2C_FIELD(temp_r3_574, f32 *, 0xFC))) / 3.0f);
    temp_r3_585 = this + ((this->unk3F5C * 0xA0) + 0x138);
    M2C_FIELD(temp_r3_585, f32 *, 0) = 0.0f;
    M2C_FIELD(temp_r3_585, f32 *, 4) = 0.0f;
    M2C_FIELD(temp_r3_585, f32 *, 8) = 0.0f;
    M2C_FIELD((this + (this->unk3F5C * 0xA0)), s32 *, 0x164) = arg_spC;
    if (arg_sp8 != 0) {
        KDSound_Play3d(arg_sp8, this + ((this->unk3F5C * 0xA0) + 0xC8), 0U, -1, 0.0f, 0U);
    }
    this->unk3F5C += 1;
    this->unk3F60 += 1;
    if ((s32) this->unk3F5C >= 0x64) {
        this->unk3F5C = 0;
    }
    this->unk3F78 = &arg0;
    this->unk3F80 = arg7;
    return 1;
}
#endif

#if 0 // DRAFT: expression syntax error
void LiquidFX::Deinit() {
    ManagedLight *temp_r4_659;

    GameProp::Deinit();
    MKMaterial_Destroy(this->unk3F64);
    this->unk3F64 = NULL;
    MKMaterial_Destroy(this->unk3F6C);
    this->unk3F6C = NULL;
    MKMaterial_Destroy(this->unk3F70);
    this->unk3F70 = NULL;
    MKMaterial_Destroy(this->unk3F74);
    this->unk3F74 = NULL;
    temp_r4_659 = this->unk3F84;
    if (temp_r4_659 != NULL) {
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->FreeManagedLight(temp_r4_659);
    }
    this->unk3F48.Deinit();
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_sp4A8'
void LiquidFX::Draw() {
    Matrix *temp_r19_1274;
    f32 temp_f0_1509;
    f32 temp_f14_1423;
    f32 temp_f1_1683;
    f32 temp_f1_946;
    f32 temp_f4_1808;
    f32 var_f15_1157;
    f32 var_f16_1146;
    f32 var_f17_1045;
    f32 var_f18_1023;
    f32 var_f8_1779;
    f64 *temp_r3_1609;
    s32 temp_r0_1003;
    s32 temp_r0_1306;
    s32 temp_r16_1073;
    s32 temp_r19_1079;
    s32 temp_r3_1646;
    s32 temp_r3_908;
    s32 temp_r5_982;
    s32 var_r16_1263;
    s32 var_r16_1624;
    s32 var_r16_732;
    s32 var_r17_895;
    s32 var_r18_1013;
    s32 var_r30_1265;
    s32 var_r31_731;
    s32 var_r4_1657;
    s32 var_r4_920;
    u8 var_r18_912;
    u8 var_r5_1662;
    u8 var_r5_925;
    void *temp_r14_1650;
    void *temp_r18_1596;
    void *temp_r20_913;
    void *temp_r3_1074;
    void *temp_r3_1081;
    void *temp_r3_1290;
    void *temp_r3_1665;
    void *temp_r3_928;
    void *temp_r3_988;
    void *temp_r4_969;
    void *temp_r4_986;
    void *temp_r6_1280;
    this->unk3F50 = 0.0f;
    arg_sp4A8 = 0.0f;
    var_r31_731 = 0;
    var_r16_732 = 0;
    arg_sp498 = 0.0f;
    this->unk3F4C = 0;
    arg_sp4A0 = 0.0f;
    arg_sp4A4 = 1.0f;
    arg_sp490 = 1.0f;
    arg_sp494 = 0.0f;
    arg_spB10 = (f64) arg_sp4A0;
    arg_spB18 = (f64) arg_sp4A8;
    arg_spB00 = (f64) arg_sp490;
    arg_spB08 = (f64) arg_sp498;
    arg_sp9D0.operator*(35.0f);
    arg_sp40 = -(f32) arg_spB00;
    arg_sp44 = -arg_spB04;
    arg_sp48 = -(f32) arg_spB08;
    arg_sp9E0 = (f64) arg_sp40;
    arg_sp9E8 = (f64) arg_sp48;
    arg_sp9F0.operator*(35.0f);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    arg_spA00 = arg_sp230;
    arg_sp238 = arg_sp9F8 + arg_sp9D8;
    arg_spCA0 = arg_sp230;
    arg_spA08 = (f64) arg_sp238;
    arg_spCA8 = (f64) arg_sp238;
    arg_sp9A0.operator*(35.0f);
    arg_sp9B0.operator*(35.0f);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    arg_sp30 = -(f32) arg_spB10;
    arg_sp34 = -arg_spB14;
    arg_sp38 = -(f32) arg_spB18;
    arg_sp228 = arg_sp9B8 + arg_sp9A8;
    arg_sp9C0 = arg_sp220;
    arg_sp9C8 = (f64) arg_sp228;
    arg_spCB0 = arg_sp220;
    arg_spCB8 = (f64) arg_sp228;
    arg_sp960 = (f64) arg_sp30;
    arg_sp968 = (f64) arg_sp38;
    arg_sp970.operator*(35.0f);
    arg_sp980.operator*(35.0f);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    arg_sp20 = -(f32) arg_spB10;
    arg_sp24 = -arg_spB14;
    arg_sp28 = -(f32) arg_spB18;
    arg_sp218 = arg_sp988 + arg_sp978;
    arg_sp990 = arg_sp210;
    arg_sp998 = (f64) arg_sp218;
    arg_spCC0 = arg_sp210;
    arg_spCC8 = (f64) arg_sp218;
    arg_sp910 = (f64) arg_sp20;
    arg_sp918 = (f64) arg_sp28;
    arg_sp920.operator*(35.0f);
    arg_sp10 = -(f32) arg_spB00;
    arg_sp14 = -arg_spB04;
    arg_sp18 = -(f32) arg_spB08;
    arg_sp930 = (f64) arg_sp10;
    arg_sp938 = (f64) arg_sp18;
    arg_sp940.operator*(35.0f);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    arg_spCD0 = arg_sp200;
    arg_sp208 = arg_sp948 + arg_sp928;
    arg_sp950 = arg_sp200;
    arg_spCD8 = (f64) arg_sp208;
    arg_sp958 = (f64) arg_sp208;
    var_r17_895 = this->unk3F5C - 1;
    if ((s32) this->unk3F60 > 0) {
loop_2:
        if (var_r17_895 < 0) {
            var_r17_895 = 0x63;
        }
        temp_r3_908 = this->unk3F5C;
        if (var_r17_895 != temp_r3_908) {
            var_r18_912 = 0;
            temp_r20_913 = this + (var_r17_895 * 0xA0);
            if (((u8) M2C_FIELD(temp_r20_913, u8 *, 0x158) != 0) && ((u8) M2C_FIELD(temp_r20_913, u8 *, 0x159) == 0)) {
                var_r4_920 = var_r17_895 - 1;
                if (var_r4_920 < 0) {
                    var_r4_920 = 0x63;
                }
                var_r5_925 = 0;
                if (var_r4_920 != temp_r3_908) {
                    temp_r3_928 = this + (var_r4_920 * 0xA0);
                    if ((u8) M2C_FIELD(temp_r3_928, u8 *, 0x158) != 0) {
                        M2C_ERROR(/* unknown instruction: psq_lx $f1, $r20, $r0, 0x0, qr0 */);
                        M2C_ERROR(/* unknown instruction: psq_lx $f0, $r3, $r0, 0x0, qr0 */);
                        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
                        arg_sp900 = arg_sp480;
                        arg_sp488 = M2C_FIELD(temp_r20_913, f32 *, 0xD0) - M2C_FIELD(temp_r3_928, f32 *, 0xD0);
                        temp_f1_946 = 90.0f * M2C_FIELD(temp_r20_913, f32 *, 0x100);
                        arg_sp908 = (f64) arg_sp488;
                        if ((((f32) arg_sp908 * (f32) arg_sp908) + (((f32) arg_sp900 * (f32) arg_sp900) + (arg_sp904 * arg_sp904))) < (temp_f1_946 * temp_f1_946)) {
                            var_r5_925 = 1;
                            var_r18_912 = 1;
                        } else {
                            var_r5_925 = 0;
                            var_r18_912 = 0;
                        }
                    }
                }
                if (var_r5_925 != 0) {
                    temp_r4_969 = this + (var_r4_920 * 0xA0);
                    if ((u8) M2C_FIELD(temp_r4_969, u8 *, 0x159) != 0) {
                        this->unk3F48.AddNode(*(temp_r4_969 + 0xC8));
                    } else {
                        this->unk3F48.AddNode(*(temp_r20_913 + 0xC8));
                    }
                    temp_r5_982 = var_r16_732 * 0x10;
                    temp_r4_986 = &arg_sp1320 + temp_r5_982;
                    temp_r3_988 = &arg_spCE0 + temp_r5_982;
                    M2C_FIELD(temp_r4_986, f64 *, 0) = (f64) M2C_FIELD(temp_r20_913, f64 *, 0x108);
                    var_r16_732 += 1;
                    M2C_FIELD(temp_r3_988, f64 *, 0) = (f64) M2C_FIELD(temp_r20_913, f64 *, 0xE8);
                    M2C_FIELD(temp_r4_986, f64 *, 8) = (f64) M2C_FIELD(temp_r20_913, f64 *, 0x110);
                    M2C_FIELD(temp_r3_988, f64 *, 8) = (f64) M2C_FIELD(temp_r20_913, f64 *, 0xF0);
                }
            }
            if ((var_r18_912 == 0) && ((s32) this->unk3F4C > 1)) {
                temp_r0_1003 = var_r16_732 - 1;
                arg_sp3F30 = 5.06792276e-315;
                var_r18_1013 = 0;
                do {
                    var_f18_1023 = (f32) arg_sp3F30 * (f32) var_r18_1013;
                    if (var_f18_1023 < 1.0f) {

                    } else {
                        var_f18_1023 = 1.0f;
                    }
                    if (var_f18_1023 > 0.0f) {

                    } else {
                        var_f18_1023 = 0.0f;
                    }
                    var_f17_1045 = (f32) arg_sp3F30 * (f32) (var_r18_1013 + 1);
                    if (var_f17_1045 < 1.0f) {

                    } else {
                        var_f17_1045 = 1.0f;
                    }
                    if (var_f17_1045 > 0.0f) {

                    } else {
                        var_f17_1045 = 0.0f;
                    }
                    temp_r16_1073 = (s32) ((f32) temp_r0_1003 * var_f18_1023) * 0x10;
                    temp_r3_1074 = &arg_sp1320 + temp_r16_1073;
                    arg_spAF8 = M2C_FIELD(temp_r3_1074, f64 *, 8);
                    temp_r19_1079 = (s32) ((f32) temp_r0_1003 * var_f17_1045) * 0x10;
                    temp_r3_1081 = &arg_sp1320 + temp_r19_1079;
                    arg_spAF0 = M2C_FIELD(temp_r3_1074, f64 *, 0);
                    arg_spAE0 = M2C_FIELD(temp_r3_1081, f64 *, 0);
                    arg_spAE8 = M2C_FIELD(temp_r3_1081, f64 *, 8);
                    arg_sp3F38 = (f64) (0.05f * _table_sinf((f32) arg_spAF8));
                    arg_sp3F40 = (f64) (0.05f * _table_sinf(arg_spAF4));
                    MKVector(0.05f * _table_sinf((f32) arg_spAF0), (f32) arg_sp3F40, (f32) arg_sp3F38);
                    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r3, 0x0, qr0 */);
                    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
                    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                    arg_sp8F0 = arg_sp1F0;
                    arg_sp1F8 = M2C_FIELD((&arg_spCE0 + temp_r16_1073), f32 *, 8) + arg_sp8E8;
                    arg_spAF0 = arg_sp1F0;
                    arg_sp8F8 = (f64) arg_sp1F8;
                    arg_spAF8 = (f64) arg_sp1F8;
                    arg_sp3F48 = (f64) (0.05f * _table_sinf((f32) arg_spAE8));
                    arg_sp3F50 = (f64) (0.05f * _table_sinf(arg_spAE4));
                    MKVector(0.05f * _table_sinf((f32) arg_spAE0), (f32) arg_sp3F50, (f32) arg_sp3F48);
                    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r3, 0x0, qr0 */);
                    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
                    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                    var_f16_1146 = 1.0f;
                    arg_sp8D0 = arg_sp1E0;
                    arg_sp1E8 = M2C_FIELD((&arg_spCE0 + temp_r19_1079), f32 *, 8) + arg_sp8C8;
                    arg_spAE0 = arg_sp1E0;
                    arg_sp8D8 = (f64) arg_sp1E8;
                    arg_spAE8 = (f64) arg_sp1E8;
                    if (var_r18_1013 == 0) {
                        var_f16_1146 = 0.0f;
                    }
                    var_f15_1157 = 1.0f;
                    if (var_r18_1013 == 0x18) {
                        var_f15_1157 = 0.0f;
                    }
                    arg_sp8B0.GetMeasure(var_f18_1023, (Matrix *) &this->unk3F48);
                    arg_spAD0 = arg_sp8B0;
                    arg_spAD8 = arg_sp8B8;
                    arg_sp8A0.GetMeasure(var_f18_1023, (Matrix *) &this->unk3F48);
                    arg_spAC0 = arg_sp8A0;
                    arg_spAC8 = arg_sp8A8;
                    arg_sp890.GetMeasure(var_f17_1045, (Matrix *) &this->unk3F48);
                    arg_spAB0 = arg_sp890;
                    arg_spAB8 = arg_sp898;
                    arg_sp880.GetMeasure(var_f17_1045, (Matrix *) &this->unk3F48);
                    arg_spAA0 = arg_sp880;
                    arg_spAA8 = arg_sp888;
                    arg_spAC0.Normalise();
                    arg_spAA0.Normalise();
                    arg_sp478 = 0.0f;
                    arg_sp470 = 0.0f;
                    arg_sp474 = 1.0f;
                    arg_spA98 = (f64) arg_sp478;
                    arg_spA90 = (f64) arg_sp470;
                    KDMath_BuildMatrixFromFwd((Matrix *) &arg_spBE0, *((MKVector3 *) &arg_spAC0), (MKVector3 *) &arg_spA90);
                    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
                    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f16 */);
                    arg_sp870 = arg_sp1D0;
                    arg_sp1D8 = (f32) arg_spAF8 * var_f16_1146;
                    arg_sp878 = (f64) arg_sp1D8;
                    arg_spBE0.Scale3x3((Matrix *) &arg_spBE0, *((MKVector3 *) &arg_sp870));
                    arg_sp1C8 = 0.0f;
                    arg_sp1C0 = 0.0f;
                    arg_sp1C4 = 1.0f;
                    arg_spC10 = (f32) arg_spAD0;
                    arg_spC14 = arg_spAD4;
                    arg_spC18 = (f32) arg_spAD8;
                    arg_spC1C = 1.0f;
                    arg_sp860 = (f64) arg_sp1C0;
                    arg_sp868 = (f64) arg_sp1C8;
                    arg_spA90 = (f64) arg_sp1C0;
                    arg_spA98 = (f64) arg_sp1C8;
                    KDMath_BuildMatrixFromFwd((Matrix *) &arg_spBA0, *((MKVector3 *) &arg_spAA0), (MKVector3 *) &arg_spA90);
                    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
                    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f15 */);
                    arg_sp850 = arg_sp1B0;
                    arg_sp1B8 = (f32) arg_spAE8 * var_f15_1157;
                    arg_sp858 = (f64) arg_sp1B8;
                    arg_spBA0.Scale3x3((Matrix *) &arg_spBA0, *((MKVector3 *) &arg_sp850));
                    var_r16_1263 = 0;
                    var_r30_1265 = 0;
                    arg_spBD0 = (f32) arg_spAB0;
                    arg_spBD4 = arg_spAB4;
                    arg_spBD8 = (f32) arg_spAB8;
                    arg_spBDC = 1.0f;
loop_39:
                    temp_r19_1274 = &arg_spCA0 + var_r30_1265;
                    ApplyMatrix(*((MKVector3 *) &arg_sp840), temp_r19_1274);
                    temp_r6_1280 = &arg_spC60 + var_r30_1265;
                    M2C_FIELD(temp_r6_1280, f64 *, 0) = arg_sp840;
                    M2C_FIELD(temp_r6_1280, f64 *, 8) = arg_sp848;
                    ApplyMatrix(*((MKVector3 *) &arg_sp830), temp_r19_1274);
                    temp_r3_1290 = &arg_spC20 + var_r30_1265;
                    var_r16_1263 += 1;
                    M2C_FIELD(temp_r3_1290, f64 *, 0) = arg_sp830;
                    var_r30_1265 += 0x10;
                    M2C_FIELD(temp_r3_1290, f64 *, 8) = arg_sp838;
                    if (var_r16_1263 < 4) {
                        goto loop_39;
                    }
                    arg_sp460 = 1.0f;
                    arg_sp464 = 1.0f;
                    arg_sp468 = 1.0f;
                    arg_sp46C = 1.0f;
                    arg_spA80 = (f64) arg_sp460;
                    arg_spA88 = (f64) arg_sp468;
                    temp_r0_1306 = this->unk3F78;
                    if (temp_r0_1306 == 1) {
                        MKMaterial_SetMaterial(this->unk3F64);
                    } else if (temp_r0_1306 == 3) {
                        MKMaterial_SetMaterial(this->unk3F6C);
                    }
                    MKPrimitive(0xC, 0);
                    MKSetMatrix(Matrix::identity);
                    MKBegin(0xA);
                    MKSetColorV(*((MKVector4 *) &arg_spA80));
                    MKSetTexCoord1F(0.0f, var_f18_1023);
                    MKSetPositionV(*((MKVector3 *) &arg_spC60));
                    MKSetColorV(*((MKVector4 *) &arg_spA80));
                    MKSetTexCoord1F(0.0f, var_f17_1045);
                    MKSetPositionV(*((MKVector3 *) &arg_spC20));
                    MKSetColorV(*((MKVector4 *) &arg_spA80));
                    MKSetTexCoord1F(0.25f, var_f18_1023);
                    MKSetPositionV(*((MKVector3 *) &arg_spC70));
                    MKSetColorV(*((MKVector4 *) &arg_spA80));
                    MKSetTexCoord1F(0.25f, var_f17_1045);
                    MKSetPositionV(*((MKVector3 *) &arg_spC30));
                    MKSetColorV(*((MKVector4 *) &arg_spA80));
                    MKSetTexCoord1F(0.5f, var_f18_1023);
                    MKSetPositionV(*((MKVector3 *) &arg_spC80));
                    MKSetColorV(*((MKVector4 *) &arg_spA80));
                    MKSetTexCoord1F(0.5f, var_f17_1045);
                    MKSetPositionV(*((MKVector3 *) &arg_spC40));
                    MKSetColorV(*((MKVector4 *) &arg_spA80));
                    MKSetTexCoord1F(0.75f, var_f18_1023);
                    MKSetPositionV(*((MKVector3 *) &arg_spC90));
                    MKSetColorV(*((MKVector4 *) &arg_spA80));
                    MKSetTexCoord1F(0.75f, var_f17_1045);
                    MKSetPositionV(*((MKVector3 *) &arg_spC50));
                    MKSetColorV(*((MKVector4 *) &arg_spA80));
                    MKSetTexCoord1F(1.0f, var_f18_1023);
                    MKSetPositionV(*((MKVector3 *) &arg_spC60));
                    MKSetColorV(*((MKVector4 *) &arg_spA80));
                    MKSetTexCoord1F(1.0f, var_f17_1045);
                    MKSetPositionV(*((MKVector3 *) &arg_spC20));
                    MKEnd();
                    MKEndPrimitive();
                    var_r18_1013 += 1;
                } while (var_r18_1013 < 0x19);
                var_r16_732 = 0;
                var_r18_912 = 0;
                this->unk3F50 = 0.0f;
                this->unk3F4C = 0;
            }
            if (var_r18_912 == 0) {
                var_r16_732 = 0;
                this->unk3F50 = 0.0f;
                this->unk3F4C = 0;
                if ((u8) M2C_FIELD(temp_r20_913, u8 *, 0x158) != 0) {
                    temp_f14_1423 = 1.0f - (M2C_FIELD(temp_r20_913, f32 *, 0x14C) / M2C_FIELD(temp_r20_913, f32 *, 0x150));
                    if ((s32) this->unk3F78 == 1) {
                        arg_sp450 = temp_f14_1423;
                        arg_sp454 = temp_f14_1423;
                        arg_sp458 = temp_f14_1423;
                        arg_sp45C = 1.0f;
                        arg_sp820 = (f64) arg_sp450;
                        arg_sp828 = (f64) arg_sp458;
                        MKModel_SetColor(this->unk4, *((MKVector4 *) &arg_sp820));
                    } else {
                        arg_sp440 = 1.0f;
                        arg_sp444 = 1.0f;
                        arg_sp448 = 1.0f;
                        arg_sp44C = 1.0f;
                        arg_sp810 = (f64) arg_sp440;
                        arg_sp818 = (f64) arg_sp448;
                        MKModel_SetColor(this->unk4, *((MKVector4 *) &arg_sp810));
                    }
                    if ((s32) this->unk3F78 == 3) {
                        gRenderState = this->unk3F70;
                    }
                    if ((u8) M2C_FIELD(temp_r20_913, u8 *, 0x159) == 0) {
                        M2C_STRUCT_COPY((s32) &arg_spB5C + 4, MKModel_GetWorldMatrix(this->unk4) - 4 + 4, 0x40);
                        arg_spB60.SetIdentity();
                        arg_sp438 = 0.0f;
                        arg_sp430 = 0.0f;
                        arg_sp434 = 1.0f;
                        arg_spA78 = (f64) arg_sp438;
                        arg_spA70 = (f64) arg_sp430;
                        KDMath_BuildMatrixFromFwd((Matrix *) &arg_spB60, *(temp_r20_913 + 0xD8), (MKVector3 *) &arg_spA70);
                        arg_spA60 = M2C_FIELD(temp_r20_913, f64 *, 0xE8);
                        arg_spA68 = M2C_FIELD(temp_r20_913, f64 *, 0xF0);
                        arg_spA60 = (0.1f * _table_sinf((f32) M2C_FIELD(temp_r20_913, f64 *, 0x108))) + (f32) arg_spA60;
                        arg_spA64 += 0.1f * _table_sinf(M2C_FIELD(temp_r20_913, f32 *, 0x10C));
                        temp_f0_1509 = (0.1f * _table_sinf((f32) M2C_FIELD(temp_r20_913, f64 *, 0x110))) + (f32) arg_spA68;
                        arg_spA68 = temp_f0_1509;
                        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
                        M2C_ERROR(/* unknown instruction: ps_muls0 $f1, $f1, $f19 */);
                        arg_sp1A8 = temp_f0_1509 * 1.2f;
                        arg_sp800 = arg_sp1A0;
                        arg_sp808 = (f64) arg_sp1A8;
                        arg_spB60.Scale3x3((Matrix *) &arg_spB60, *((MKVector3 *) &arg_sp800));
                        arg_spB90 = M2C_FIELD(temp_r20_913, f32 *, 0xC8);
                        arg_spB94 = M2C_FIELD(temp_r20_913, f32 *, 0xCC);
                        arg_spB98 = M2C_FIELD(temp_r20_913, f32 *, 0xD0);
                        arg_spB9C = 1.0f;
                        MKModel_SetWorldMatrix(this->unk4, *((Matrix *) &arg_spB60));
                        MKModel_Draw(this->unk4, NULL);
                    } else {
                        arg_spB20.SetIdentity();
                        arg_sp420 = 0.0f;
                        arg_sp424 = 0.0f;
                        arg_sp428 = 1.0f;
                        arg_sp7F0 = (f64) arg_sp420;
                        arg_sp7F8 = (f64) arg_sp428;
                        KDMath_BuildMatrixFromUp((Matrix *) &arg_spB20, *(temp_r20_913 + 0x128), *((MKVector3 *) &arg_sp7F0));
                        M2C_ERROR(/* unknown instruction: psq_lx $f0, $r20, $r0, 0x0, qr0 */);
                        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f14 */);
                        arg_sp7E0 = arg_sp190;
                        arg_sp198 = (f32) M2C_FIELD(temp_r20_913, f64 *, 0xF0) * temp_f14_1423;
                        arg_sp7E8 = (f64) arg_sp198;
                        arg_spB20.Scale3x3((Matrix *) &arg_spB20, *((MKVector3 *) &arg_sp7E0));
                        arg_spB50 = M2C_FIELD(temp_r20_913, f32 *, 0xC8);
                        arg_spB54 = M2C_FIELD(temp_r20_913, f32 *, 0xCC);
                        arg_spB58 = M2C_FIELD(temp_r20_913, f32 *, 0xD0);
                        arg_spB5C = 1.0f;
                        MKModel_SetWorldMatrix(this->unk4, *((Matrix *) &arg_spB20));
                        MKModel_Draw(this->unk4, NULL);
                    }
                    if ((s32) this->unk3F78 == 3) {
                        gRenderState = NULL;
                    }
                    temp_r18_1596 = &arg_sp1960 + var_r31_731;
                    M2C_STRUCT_COPY(temp_r18_1596, MKModel_GetWorldMatrix(this->unk4), 0x40);
                    M2C_FIELD(temp_r18_1596, s32 *, 0x50) = 0;
                    temp_r3_1609 = MKModel_GetColor(this->unk4);
                    var_r31_731 += 0x60;
                    M2C_FIELD(temp_r18_1596, f64 *, 0x40) = (f64) M2C_FIELD(temp_r3_1609, f64 *, 0);
                    M2C_FIELD(temp_r18_1596, f64 *, 0x48) = (f64) M2C_FIELD(temp_r3_1609, f64 *, 8);
                }
            }
            var_r17_895 -= 1;
            goto loop_2;
        }
    }
    if ((s32) this->unk3F78 == 3) {
        var_r16_1624 = this->unk3F5C - 1;
        MKMaterial_SetMaterial(this->unk3F74);
        MKPrimitive(0xC, 0);
        MKSetMatrix(Matrix::identity);
        arg_sp410 = 1.0f;
        arg_sp414 = 1.0f;
        arg_sp418 = 1.0f;
        arg_sp41C = 1.0f;
        arg_spA50 = (f64) arg_sp410;
        arg_spA58 = (f64) arg_sp418;
loop_62:
        if (var_r16_1624 < 0) {
            var_r16_1624 = 0x63;
        }
        temp_r3_1646 = this->unk3F5C;
        if (var_r16_1624 != temp_r3_1646) {
            temp_r14_1650 = this + (var_r16_1624 * 0xA0);
            if (((u8) M2C_FIELD(temp_r14_1650, u8 *, 0x158) != 0) && ((u8) M2C_FIELD(temp_r14_1650, u8 *, 0x159) == 0)) {
                var_r4_1657 = var_r16_1624 - 1;
                if (var_r4_1657 < 0) {
                    var_r4_1657 = 0x63;
                }
                var_r5_1662 = 0;
                if (var_r4_1657 != temp_r3_1646) {
                    temp_r3_1665 = this + (var_r4_1657 * 0xA0);
                    if ((u8) M2C_FIELD(temp_r3_1665, u8 *, 0x158) != 0) {
                        M2C_ERROR(/* unknown instruction: psq_lx $f1, $r14, $r0, 0x0, qr0 */);
                        M2C_ERROR(/* unknown instruction: psq_lx $f0, $r3, $r0, 0x0, qr0 */);
                        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
                        arg_sp7D0 = arg_sp400;
                        arg_sp408 = M2C_FIELD(temp_r14_1650, f32 *, 0xD0) - M2C_FIELD(temp_r3_1665, f32 *, 0xD0);
                        temp_f1_1683 = 90.0f * M2C_FIELD(temp_r14_1650, f32 *, 0x100);
                        arg_sp7D8 = (f64) arg_sp408;
                        if ((((f32) arg_sp7D8 * (f32) arg_sp7D8) + (((f32) arg_sp7D0 * (f32) arg_sp7D0) + (arg_sp7D4 * arg_sp7D4))) < (temp_f1_1683 * temp_f1_1683)) {
                            var_r5_1662 = 1;
                        } else {
                            var_r5_1662 = 0;
                        }
                    }
                }
                if (var_r5_1662 != 0) {
                    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r4, $r0, 0x0, qr0 */);
                    M2C_ERROR(/* unknown instruction: psq_lx $f0, $r14, $r0, 0x0, qr0 */);
                    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
                    arg_sp7B0 = arg_sp180;
                    arg_sp188 = M2C_FIELD((this + (var_r4_1657 * 0xA0)), f32 *, 0xD0) - M2C_FIELD(temp_r14_1650, f32 *, 0xD0);
                    arg_sp7B8 = (f64) arg_sp188;
                    Normalise(*((MKVector3 *) &arg_sp7C0));
                    arg_spA40 = arg_sp7C0;
                    arg_spA48 = arg_sp7C8;
                } else {
                    Normalise(*((MKVector3 *) &arg_sp7A0));
                    arg_spA40 = arg_sp7A0;
                    arg_spA48 = arg_sp7A8;
                }
                arg_sp178 = 0.0f;
                arg_sp170 = 0.0f;
                arg_sp174 = 1.0f;
                arg_sp778 = (f64) arg_sp178;
                arg_sp770 = (f64) arg_sp170;
                arg_sp160 = (arg_sp774 * (f32) arg_spA48) - ((f32) arg_sp778 * arg_spA44);
                arg_sp164 = ((f32) arg_sp778 * (f32) arg_spA40) - ((f32) arg_sp770 * (f32) arg_spA48);
                arg_sp168 = ((f32) arg_sp770 * arg_spA44) - (arg_sp774 * (f32) arg_spA40);
                arg_sp780 = (f64) arg_sp160;
                arg_sp788 = (f64) arg_sp168;
                Normalise(*((MKVector3 *) &arg_sp790));
                arg_spA20 = arg_sp790;
                arg_spA28 = arg_sp798;
                var_f8_1779 = M2C_FIELD(temp_r14_1650, f32 *, 0x14C);
                arg_sp158 = ((f32) arg_spA40 * arg_spA24) - (arg_spA44 * (f32) arg_spA20);
                arg_sp154 = ((f32) arg_spA48 * (f32) arg_spA20) - ((f32) arg_spA40 * (f32) arg_spA28);
                arg_sp150 = (arg_spA44 * (f32) arg_spA28) - ((f32) arg_spA48 * arg_spA24);
                arg_sp768 = (f64) arg_sp158;
                arg_sp760 = (f64) arg_sp150;
                arg_spA30 = (f64) arg_sp150;
                arg_spA38 = (f64) arg_sp158;
                if (var_f8_1779 < 0.2f) {

                } else {
                    var_f8_1779 = 0.2f;
                }
                if (var_f8_1779 > 0.0f) {

                } else {
                    var_f8_1779 = 0.0f;
                }
                temp_f4_1808 = var_f8_1779 / 0.2f;
                arg_sp3F8 = 35.0f;
                arg_sp3F0 = 40.0f;
                arg_spA50 = temp_f4_1808;
                arg_sp3F4 = 300.0f * temp_f4_1808;
                arg_spA54 = temp_f4_1808;
                arg_sp750 = (f64) arg_sp3F0;
                arg_spA58 = temp_f4_1808;
                arg_spA5C = 1.0f;
                arg_sp758 = (f64) arg_sp3F8;
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $r14, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_mul $f0, $f1, $f0 */);
                arg_spA10 = arg_sp3E0;
                arg_sp3E8 = (f32) arg_sp758 * M2C_FIELD(temp_r14_1650, f32 *, 0xF0);
                arg_spA18 = (f64) arg_sp3E8;
                MKBegin(4);
                MKSetColorV(*((MKVector4 *) &arg_spA50));
                MKSetTexCoord1F(0.99f, 0.0f);
                arg_sp3F2C = (f32) arg_spA18;
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f1, $f1, $f0 */);
                arg_sp3D0 = -(f32) arg_spA20;
                arg_sp3D4 = -arg_spA24;
                arg_sp148 = (f32) arg_spA48 * arg_sp3F2C;
                arg_sp3D8 = -(f32) arg_spA28;
                arg_sp3F1C = (f32) arg_spA10;
                arg_sp710 = (f64) arg_sp3D0;
                arg_sp700 = arg_sp140;
                arg_sp708 = (f64) arg_sp148;
                arg_sp718 = (f64) arg_sp3D8;
                M2C_ERROR(/* unknown instruction: ps_muls0 $f1, $f1, $f0 */);
                arg_sp720 = arg_sp130;
                arg_sp138 = (f32) arg_sp718 * (f32) arg_spA10;
                arg_sp728 = (f64) arg_sp138;
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r17, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                arg_sp730 = arg_sp3C0;
                arg_sp3C8 = M2C_FIELD(temp_r14_1650, f32 *, 0xD0) + (f32) arg_sp728;
                arg_sp738 = (f64) arg_sp3C8;
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                arg_sp740 = arg_sp3B0;
                arg_sp3B8 = (f32) arg_sp738 + (f32) arg_sp708;
                arg_sp748 = (f64) arg_sp3B8;
                MKSetPositionV(*((MKVector3 *) &arg_sp740));
                MKSetColorV(*((MKVector4 *) &arg_spA50));
                MKSetTexCoord1F(0.99f, 1.0f);
                arg_sp3F24 = (f32) arg_spA18;
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f1, $f1, $f0 */);
                arg_sp380 = -(f32) arg_spA30;
                arg_sp384 = -arg_spA34;
                arg_sp128 = (f32) arg_spA48 * arg_sp3F24;
                arg_sp388 = -(f32) arg_spA38;
                arg_sp3F28 = arg_spA14;
                arg_sp690 = (f64) arg_sp380;
                arg_sp680 = arg_sp120;
                arg_sp688 = (f64) arg_sp128;
                arg_sp698 = (f64) arg_sp388;
                M2C_ERROR(/* unknown instruction: ps_muls0 $f1, $f1, $f0 */);
                arg_sp3A0 = -(f32) arg_spA20;
                arg_sp3A4 = -arg_spA24;
                arg_sp118 = (f32) arg_sp698 * arg_sp3F28;
                arg_sp3A8 = -(f32) arg_spA28;
                arg_sp3F18 = (f32) arg_spA10;
                arg_sp6B0 = (f64) arg_sp3A0;
                arg_sp6A0 = arg_sp110;
                arg_sp6A8 = (f64) arg_sp118;
                arg_sp6B8 = (f64) arg_sp3A8;
                M2C_ERROR(/* unknown instruction: ps_muls0 $f1, $f1, $f0 */);
                arg_sp6C0 = arg_sp100;
                arg_sp108 = (f32) arg_sp6B8 * (f32) arg_spA10;
                arg_sp6C8 = (f64) arg_sp108;
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r17, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                arg_sp6D0 = arg_sp390;
                arg_sp398 = M2C_FIELD(temp_r14_1650, f32 *, 0xD0) + (f32) arg_sp6C8;
                arg_sp6D8 = (f64) arg_sp398;
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                arg_sp6E0 = arg_sp370;
                arg_sp378 = (f32) arg_sp6D8 + (f32) arg_sp6A8;
                arg_sp6E8 = (f64) arg_sp378;
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                arg_sp6F0 = arg_sp360;
                arg_sp368 = (f32) arg_sp6E8 + (f32) arg_sp688;
                arg_sp6F8 = (f64) arg_sp368;
                MKSetPositionV(*((MKVector3 *) &arg_sp6F0));
                MKSetColorV(*((MKVector4 *) &arg_spA50));
                MKSetTexCoord1F(0.0f, 0.0f);
                arg_sp350 = -(f32) arg_spA40;
                arg_sp3F20 = (f32) arg_spA18;
                arg_sp354 = -arg_spA44;
                arg_sp358 = -(f32) arg_spA48;
                arg_sp650 = (f64) arg_sp350;
                arg_sp658 = (f64) arg_sp358;
                M2C_ERROR(/* unknown instruction: ps_muls0 $f1, $f1, $f0 */);
                arg_sp660 = arg_spF0;
                arg_spF8 = (f32) arg_sp658 * arg_sp3F20;
                arg_sp668 = (f64) arg_spF8;
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r17, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                arg_sp670 = arg_sp340;
                arg_sp348 = M2C_FIELD(temp_r14_1650, f32 *, 0xD0) + (f32) arg_sp668;
                arg_sp678 = (f64) arg_sp348;
                MKSetPositionV(*((MKVector3 *) &arg_sp670));
                MKSetColorV(*((MKVector4 *) &arg_spA50));
                MKSetTexCoord1F(0.0f, 1.0f);
                arg_sp310 = -(f32) arg_spA40;
                arg_sp314 = -arg_spA44;
                arg_sp318 = -(f32) arg_spA48;
                arg_sp5F0 = (f64) arg_sp310;
                arg_sp5F8 = (f64) arg_sp318;
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f26 */);
                arg_sp330 = -(f32) arg_spA30;
                arg_sp334 = -arg_spA34;
                arg_spE8 = (f32) arg_sp5F8 * (f32) arg_spA18;
                arg_sp338 = -(f32) arg_spA38;
                arg_sp610 = (f64) arg_sp330;
                arg_sp600 = arg_spE0;
                arg_sp608 = (f64) arg_spE8;
                arg_sp618 = (f64) arg_sp338;
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f27 */);
                arg_sp620 = arg_spD0;
                arg_spD8 = (f32) arg_sp618 * arg_spA14;
                arg_sp628 = (f64) arg_spD8;
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r17, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                arg_sp630 = arg_sp320;
                arg_sp328 = M2C_FIELD(temp_r14_1650, f32 *, 0xD0) + (f32) arg_sp628;
                arg_sp638 = (f64) arg_sp328;
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                arg_sp640 = arg_sp300;
                arg_sp308 = (f32) arg_sp638 + (f32) arg_sp608;
                arg_sp648 = (f64) arg_sp308;
                MKSetPositionV(*((MKVector3 *) &arg_sp640));
                MKEnd();
                MKBegin(4);
                MKSetColorV(*((MKVector4 *) &arg_spA50));
                MKSetTexCoord1F(0.0f, 0.0f);
                arg_sp2F0 = -(f32) arg_spA40;
                arg_sp2F4 = -arg_spA44;
                arg_sp2F8 = -(f32) arg_spA48;
                arg_sp5C0 = (f64) arg_sp2F0;
                arg_sp5C8 = (f64) arg_sp2F8;
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f25 */);
                arg_sp5D0 = arg_spC0;
                arg_spC8 = (f32) arg_sp5C8 * M2C_ERROR(/* unknown instruction: ps_mr $f25, $f26 */);
                arg_sp5D8 = (f64) arg_spC8;
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r17, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                arg_sp5E0 = arg_sp2E0;
                arg_sp2E8 = M2C_FIELD(temp_r14_1650, f32 *, 0xD0) + (f32) arg_sp5D8;
                arg_sp5E8 = (f64) arg_sp2E8;
                MKSetPositionV(*((MKVector3 *) &arg_sp5E0));
                MKSetColorV(*((MKVector4 *) &arg_spA50));
                MKSetTexCoord1F(0.0f, 1.0f);
                arg_sp2B0 = -(f32) arg_spA40;
                arg_sp2B4 = -arg_spA44;
                arg_sp2B8 = -(f32) arg_spA48;
                arg_sp560 = (f64) arg_sp2B0;
                arg_sp568 = (f64) arg_sp2B8;
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f23 */);
                arg_sp2D0 = -(f32) arg_spA30;
                arg_sp2D4 = -arg_spA34;
                arg_spB8 = (f32) arg_sp568 * M2C_ERROR(/* unknown instruction: ps_mr $f23, $f26 */);
                arg_sp2D8 = -(f32) arg_spA38;
                arg_sp580 = (f64) arg_sp2D0;
                arg_sp570 = arg_spB0;
                arg_sp578 = (f64) arg_spB8;
                arg_sp588 = (f64) arg_sp2D8;
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f24 */);
                arg_sp590 = arg_spA0;
                arg_spA8 = (f32) arg_sp588 * M2C_ERROR(/* unknown instruction: ps_mr $f24, $f27 */);
                arg_sp598 = (f64) arg_spA8;
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r17, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                arg_sp5A0 = arg_sp2C0;
                arg_sp2C8 = M2C_FIELD(temp_r14_1650, f32 *, 0xD0) + (f32) arg_sp598;
                arg_sp5A8 = (f64) arg_sp2C8;
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                arg_sp5B0 = arg_sp2A0;
                arg_sp2A8 = (f32) arg_sp5A8 + (f32) arg_sp578;
                arg_sp5B8 = (f64) arg_sp2A8;
                MKSetPositionV(*((MKVector3 *) &arg_sp5B0));
                MKSetColorV(*((MKVector4 *) &arg_spA50));
                MKSetTexCoord1F(0.99f, 0.0f);
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f22 */);
                arg_sp98 = (f32) arg_spA48 * M2C_ERROR(/* unknown instruction: ps_mr $f22, $f26 */);
                arg_sp3F14 = (f32) arg_spA10;
                arg_sp520 = arg_sp90;
                arg_sp528 = (f64) arg_sp98;
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f1, $f1, $f0 */);
                arg_sp530 = arg_sp80;
                arg_sp88 = (f32) arg_spA28 * (f32) arg_spA10;
                arg_sp538 = (f64) arg_sp88;
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r17, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                arg_sp540 = arg_sp290;
                arg_sp298 = M2C_FIELD(temp_r14_1650, f32 *, 0xD0) + (f32) arg_sp538;
                arg_sp548 = (f64) arg_sp298;
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                arg_sp550 = arg_sp280;
                arg_sp288 = (f32) arg_sp548 + (f32) arg_sp528;
                arg_sp558 = (f64) arg_sp288;
                MKSetPositionV(*((MKVector3 *) &arg_sp550));
                MKSetColorV(*((MKVector4 *) &arg_spA50));
                MKSetTexCoord1F(0.99f, 1.0f);
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f20 */);
                arg_sp260 = -(f32) arg_spA30;
                arg_sp264 = -arg_spA34;
                arg_sp78 = (f32) arg_spA48 * M2C_ERROR(/* unknown instruction: ps_mr $f20, $f26 */);
                arg_sp268 = -(f32) arg_spA38;
                arg_sp4C0 = (f64) arg_sp260;
                arg_sp4B0 = arg_sp70;
                arg_sp4B8 = (f64) arg_sp78;
                arg_sp4C8 = (f64) arg_sp268;
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f21 */);
                arg_sp4D0 = arg_sp60;
                arg_sp68 = (f32) arg_sp4C8 * M2C_ERROR(/* unknown instruction: ps_mr $f21, $f27 */);
                arg_sp3F10 = (f32) arg_spA10;
                arg_sp4D8 = (f64) arg_sp68;
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f1, $f1, $f0 */);
                arg_sp4E0 = arg_sp50;
                arg_sp58 = (f32) arg_spA28 * (f32) arg_spA10;
                arg_sp4E8 = (f64) arg_sp58;
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r17, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                arg_sp4F0 = arg_sp270;
                arg_sp278 = M2C_FIELD(temp_r14_1650, f32 *, 0xD0) + (f32) arg_sp4E8;
                arg_sp4F8 = (f64) arg_sp278;
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                arg_sp500 = arg_sp250;
                arg_sp258 = (f32) arg_sp4F8 + (f32) arg_sp4D8;
                arg_sp508 = (f64) arg_sp258;
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                arg_sp510 = arg_sp240;
                arg_sp248 = (f32) arg_sp508 + (f32) arg_sp4B8;
                arg_sp518 = (f64) arg_sp248;
                MKSetPositionV(*((MKVector3 *) &arg_sp510));
                MKEnd();
            }
            var_r16_1624 -= 1;
            goto loop_62;
        }
        MKEndPrimitive();
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'MKVector'
void LiquidFX::Update() {
    BreathHitMessage *temp_r4_3053;
    KDWaterVolume *temp_r24_3701;
    MKVector3 *temp_r24_2994;
    ManagedLight *temp_r3_2691;
    ManagedLight *temp_r3_3178;
    ManagedLight *temp_r3_3191;
    ManagedLight *temp_r3_3214;
    ManagedLight *temp_r3_3236;
    ManagedLight *temp_r4_3256;
    f32 temp_f0_2692;
    f32 temp_f0_2892;
    f32 temp_f0_2969;
    f32 temp_f0_3784;
    f32 temp_f1_2801;
    f32 temp_f1_2894;
    f32 temp_f1_2932;
    f32 temp_f1_3080;
    f32 temp_f1_3503;
    f32 temp_f1_3534;
    f32 temp_f1_3572;
    f32 temp_f1_3608;
    f32 temp_f24_3670;
    f32 temp_f24_3715;
    f32 temp_f25_3720;
    f32 temp_f29_2729;
    f32 temp_f2_2800;
    f32 temp_f2_3079;
    f32 temp_f2_3541;
    f32 temp_f2_3579;
    f32 temp_f2_3615;
    f32 temp_f3_2802;
    f32 temp_f3_3081;
    f32 temp_f3_3297;
    f32 temp_f4_2919;
    f32 temp_f4_2923;
    f32 temp_f4_2927;
    f32 temp_f4_2956;
    f32 temp_f4_2960;
    f32 temp_f4_2964;
    f32 temp_f4_2993;
    f32 temp_f4_3003;
    f32 temp_f4_3298;
    f32 temp_f5_2887;
    f32 temp_f5_3577;
    f32 temp_f6_3502;
    f32 temp_f6_3539;
    f32 temp_f9_3302;
    f32 var_f0_3286;
    f32 var_f0_3616;
    f32 var_f2_3600;
    f32 var_f4_2807;
    f32 var_f4_3086;
    f32 var_f4_3324;
    f32 var_f4_3506;
    f32 var_f4_3543;
    f32 var_f4_3581;
    f32 var_f5_2895;
    f32 var_f5_2929;
    f32 var_f5_2966;
    f32 var_f5_3524;
    f32 var_f5_3562;
    f32 var_f6_2912;
    f32 var_f6_2949;
    f32 var_f6_2986;
    f64 temp_f1_2810;
    f64 temp_f1_2816;
    f64 temp_f1_2820;
    f64 temp_f1_3089;
    f64 temp_f1_3095;
    f64 temp_f1_3099;
    f64 temp_f1_3329;
    f64 temp_f1_3335;
    f64 temp_f1_3339;
    s32 temp_r0_3207;
    s32 temp_r0_3646;
    s32 temp_r3_2839;
    s32 temp_r3_3118;
    s32 temp_r3_3358;
    s32 var_r0_2849;
    s32 var_r0_3128;
    s32 var_r0_3368;
    s32 var_r21_2715;
    s32 var_r23_2713;
    void *temp_r24_3267;
    void *temp_r27_2717;
    void *temp_r30_2661;
    void *temp_r3_2694;
    void *temp_r3_3184;
    void *temp_r3_3194;
    void *temp_r3_3222;
    void *temp_r3_3244;
    void *var_r0_3277;
    void *var_r3_3046;
    this->unk3F68 += 10.0f * gUpdateTimeDelta;
    temp_r30_2661 = checked_cast<LiquidFXDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    if ((ManagedLight *) this->unk3F84 != NULL) {
        this->unk3F88 -= gUpdateTimeDelta;
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if ((this->unk3F88 == 0.0f) || (EventCamera_GetCurrent() != NULL)) {
            this->unk3F88 = 0.0f;
            ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->EnableLight(this->unk3F84, 0U);
        } else {
            temp_r3_2691 = this->unk3F84;
            temp_f0_2692 = 1000.0f * (this->unk3F88 / 0.5f);
            temp_r3_2691->unk38 = temp_f0_2692;
            temp_r3_2694 = temp_r3_2691->unk3C;
            if (temp_r3_2694 != NULL) {
                M2C_FIELD(temp_r3_2694, f32 *, 0x20) = temp_f0_2692;
                M2C_FIELD(temp_r3_2694, f32 *, 0x24) = (f32) (temp_f0_2692 * temp_f0_2692);
                M2C_FIELD(temp_r3_2694, f32 *, 0x28) = (f32) (1.0f / temp_f0_2692);
                M2C_FIELD(temp_r3_2694, f32 *, 0x2C) = (f32) (1.0f / M2C_FIELD(temp_r3_2694, f32 *, 0x24));
            }
        }
    }
    if ((s32) this->unk3F60 > 0) {
        var_r23_2713 = 0;
        var_r21_2715 = 0;
        do {
            temp_r27_2717 = this + var_r21_2715;
            if ((u8) M2C_FIELD(temp_r27_2717, u8 *, 0x158) != 0) {
                if ((u8) M2C_FIELD(temp_r27_2717, u8 *, 0x159) == 0) {
                    temp_f29_2729 = gUpdateTimeDelta;
                    MKVector(0.0f, -3000.0f * M2C_FIELD(temp_r27_2717, f32 *, 0xFC), 0.0f);
                    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
                    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
                    arg_sp298 = arg_spE8;
                    arg_spF0 = arg_sp290 * temp_f29_2729;
                    arg_sp2A0 = (f64) arg_spF0;
                    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r26, 0x0, qr0 */);
                    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                    M2C_ERROR(/* unknown instruction: psq_stx $f0, $zero, $r26, 0x0, qr0 */);
                    M2C_FIELD(temp_r27_2717, f32 *, 0xE0) = (f32) (M2C_FIELD(temp_r27_2717, f32 *, 0xE0) + (f32) arg_sp2A0);
                    arg_sp2B8 = M2C_FIELD(temp_r27_2717, f64 *, 0xC8);
                    arg_sp2C0 = M2C_FIELD(temp_r27_2717, f64 *, 0xD0);
                    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r26, 0x0, qr0 */);
                    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f26 */);
                    arg_sp278 = arg_spD8;
                    arg_spE0 = M2C_FIELD(temp_r27_2717, f32 *, 0xE0) * gUpdateTimeDelta;
                    arg_sp280 = (f64) arg_spE0;
                    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r25, 0x0, qr0 */);
                    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                    M2C_ERROR(/* unknown instruction: psq_stx $f0, $zero, $r25, 0x0, qr0 */);
                    M2C_FIELD(temp_r27_2717, f64 *, 0xD0) = (f32) ((f32) M2C_FIELD(temp_r27_2717, f64 *, 0xD0) + (f32) arg_sp280);
                    M2C_ERROR(/* unknown instruction: psq_lx $f0, $r27, $r0, 0x0, qr0 */);
                    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f27 */);
                    arg_sp268 = arg_spC8;
                    arg_spD0 = M2C_FIELD(temp_r27_2717, f32 *, 0x120) * gUpdateTimeDelta;
                    arg_sp270 = (f64) arg_spD0;
                    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
                    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                    M2C_ERROR(/* unknown instruction: psq_stx $f0, $zero, $r0, 0x0, qr0 */);
                    M2C_FIELD(temp_r27_2717, f32 *, 0x110) = (f32) (M2C_FIELD(temp_r27_2717, f32 *, 0x110) + (f32) arg_sp270);
                    temp_f2_2800 = M2C_FIELD(temp_r27_2717, f32 *, 0xD8);
                    temp_f1_2801 = M2C_FIELD(temp_r27_2717, f32 *, 0xDC);
                    temp_f3_2802 = M2C_FIELD(temp_r27_2717, f32 *, 0xE0);
                    var_f4_2807 = (temp_f3_2802 * temp_f3_2802) + ((temp_f2_2800 * temp_f2_2800) + (temp_f1_2801 * temp_f1_2801));
                    if (var_f4_2807 > 0.0f) {
                        temp_f1_2810 = __frsqrte(var_f4_2807);
                        temp_f1_2816 = 0.5 * temp_f1_2810 * -(((f64) var_f4_2807 * (temp_f1_2810 * temp_f1_2810)) - 3.0);
                        temp_f1_2820 = 0.5 * temp_f1_2816 * -(((f64) var_f4_2807 * (temp_f1_2816 * temp_f1_2816)) - 3.0);
                        var_f4_2807 = (f32) ((f64) var_f4_2807 * (0.5 * temp_f1_2820 * -(((f64) var_f4_2807 * (temp_f1_2820 * temp_f1_2820)) - 3.0)));
                    } else if (var_f4_2807 < M2C_BITWISE(f32, 0.0)) {
                        var_f4_2807 = __float_nan;
                    } else {
                        arg_sp18 = var_f4_2807;
                        temp_r3_2839 = M2C_BITWISE(s32, arg_sp18) & 0x7F800000;
                        switch (temp_r3_2839) {     /* switch 1; irregular */
                        case 0x7F800000:            /* switch 1 */
                            if (M2C_BITWISE(s32, arg_sp18) & 0x7FFFFF) {
                                var_r0_2849 = 1;
                            } else {
                                var_r0_2849 = 2;
                            }
                            break;
                        case 0x0:                   /* switch 1 */
                            if (M2C_BITWISE(s32, arg_sp18) & 0x7FFFFF) {
                                var_r0_2849 = 5;
                            } else {
                                var_r0_2849 = 3;
                            }
                            break;
                        default:                    /* switch 1 */
                            var_r0_2849 = 4;
                            break;
                        }
                        if (var_r0_2849 == 1) {
                            var_f4_2807 = __float_nan;
                        }
                    }
                    if (var_f4_2807 < 980.0f) {

                    } else {
                        var_f4_2807 = 980.0f;
                    }
                    if (var_f4_2807 > 0.0f) {

                    } else {
                        var_f4_2807 = 0.0f;
                    }
                    temp_f5_2887 = M2C_FIELD(temp_r27_2717, f32 *, 0xFC);
                    temp_f0_2892 = 0.5f * (var_f4_2807 / 980.0f);
                    temp_f1_2894 = 0.15f * temp_f5_2887;
                    var_f5_2895 = -((temp_f0_2892 * temp_f5_2887) - temp_f5_2887);
                    if (var_f5_2895 < 100.0f) {

                    } else {
                        var_f5_2895 = 100.0f;
                    }
                    if (var_f5_2895 > temp_f1_2894) {

                    } else {
                        var_f5_2895 = temp_f1_2894;
                    }
                    var_f6_2912 = 0.5f * (0.95f * (10.0f * gUpdateTimeDelta));
                    if (var_f6_2912 < 1.0f) {

                    } else {
                        var_f6_2912 = 1.0f;
                    }
                    temp_f4_2919 = M2C_FIELD(temp_r27_2717, f32 *, 0xEC);
                    temp_f4_2923 = (var_f6_2912 * (var_f5_2895 - temp_f4_2919)) + temp_f4_2919;
                    M2C_FIELD(temp_r27_2717, f32 *, 0xEC) = (f32) ((var_f6_2912 * (var_f5_2895 - temp_f4_2923)) + temp_f4_2923);
                    temp_f4_2927 = M2C_FIELD(temp_r27_2717, f32 *, 0xF8);
                    var_f5_2929 = -((temp_f0_2892 * temp_f4_2927) - temp_f4_2927);
                    temp_f1_2932 = 0.15f * temp_f4_2927;
                    if (var_f5_2929 < 100.0f) {

                    } else {
                        var_f5_2929 = 100.0f;
                    }
                    if (var_f5_2929 > temp_f1_2932) {

                    } else {
                        var_f5_2929 = temp_f1_2932;
                    }
                    var_f6_2949 = 0.5f * (0.95f * (10.0f * gUpdateTimeDelta));
                    if (var_f6_2949 < 1.0f) {

                    } else {
                        var_f6_2949 = 1.0f;
                    }
                    temp_f4_2956 = M2C_FIELD(temp_r27_2717, f32 *, 0xE8);
                    temp_f4_2960 = (var_f6_2949 * (var_f5_2929 - temp_f4_2956)) + temp_f4_2956;
                    M2C_FIELD(temp_r27_2717, f32 *, 0xE8) = (f32) ((var_f6_2949 * (var_f5_2929 - temp_f4_2960)) + temp_f4_2960);
                    temp_f4_2964 = M2C_FIELD(temp_r27_2717, f32 *, 0x100);
                    var_f5_2966 = (temp_f0_2892 * temp_f4_2964) + temp_f4_2964;
                    temp_f0_2969 = 0.15f * temp_f4_2964;
                    if (var_f5_2966 < 100.0f) {

                    } else {
                        var_f5_2966 = 100.0f;
                    }
                    if (var_f5_2966 > temp_f0_2969) {

                    } else {
                        var_f5_2966 = temp_f0_2969;
                    }
                    var_f6_2986 = 0.5f * (0.95f * (10.0f * gUpdateTimeDelta));
                    if (var_f6_2986 < 1.0f) {

                    } else {
                        var_f6_2986 = 1.0f;
                    }
                    temp_f4_2993 = M2C_FIELD(temp_r27_2717, f32 *, 0xF0);
                    temp_r24_2994 = temp_r27_2717 + 0xC8;
                    temp_f4_3003 = (var_f6_2986 * (var_f5_2966 - temp_f4_2993)) + temp_f4_2993;
                    M2C_FIELD(temp_r27_2717, f32 *, 0xF0) = (f32) ((var_f6_2986 * (var_f5_2966 - temp_f4_3003)) + temp_f4_3003);
                    arg_sp310 = 0.0f;
                    arg_sp314 = 0.0f;
                    arg_sp318 = 0.0f;
                    arg_sp320 = 0.0f;
                    arg_sp324 = 0.0f;
                    arg_sp328 = 0.0f;
                    arg_sp330 = 0.0f;
                    arg_sp334 = 0.0f;
                    arg_sp338 = 0.0f;
                    arg_sp33C = 1.0f;
                    arg_sp340 = 0.0f;
                    arg_sp344 = 0.0f;
                    arg_sp348 = 0;
                    arg_sp348 = 0;
                    (s8) arg_sp348 = 0;
                    arg_sp34C = 0;
                    arg_sp350 = 3.4028235e38f;
                    arg_sp354 = 0;
                    arg_sp358 = NULL;
                    arg_sp35C = -1;
                    arg_sp360 = 0U;
                    if (MKCollision_RayCollide(*((MKVector3 *) &arg_sp2B8), *temp_r24_2994, (MKCollisionResult *) &arg_sp310, (MKCollisionMode) 7, 0) != 0) {
                        M2C_FIELD(temp_r27_2717, u8 *, 0x159) = 1U;
                        M2C_FIELD(temp_r27_2717, f64 *, 0x128) = (f64) arg_sp320;
                        M2C_FIELD(temp_r27_2717, f64 *, 0x130) = (f64) arg_sp328;
                        if ((arg_sp360 != 0) && (arg_sp358 != NULL) && (var_r3_3046 = M2C_FIELD(arg_sp358, void **, 8), ((var_r3_3046 == NULL) == 0))) {

                        } else {
                            var_r3_3046 = NULL;
                        }
                        temp_r4_3053 = this->unk3F80;
                        if ((temp_r4_3053 != NULL) && (var_r3_3046 != NULL)) {
                            M2C_FIELD(temp_r4_3053, f64 *, 0x10) = (f64) arg_sp310;
                            M2C_FIELD(temp_r4_3053, f64 *, 0x18) = (f64) arg_sp318;
                            M2C_FIELD(M2C_FIELD(var_r3_3046, void **, 0x44), M2C_UNK (**)(BreathHitMessage *, f64), 0x2C)(this->unk3F80, (f64) arg_sp310);
                        }
                        M2C_FIELD(temp_r27_2717, f64 *, 0xC8) = (f64) arg_sp310;
                        M2C_FIELD((temp_r27_2717 + 0xC8), f64 *, 8) = (f64) arg_sp318;
                        M2C_FIELD(temp_r27_2717, f32 *, 0x154) = arg_sp314;
                        M2C_FIELD(temp_r27_2717, f64 *, 0x128) = (f64) arg_sp320;
                        M2C_FIELD(temp_r27_2717, f64 *, 0x130) = (f64) arg_sp328;
                        temp_f2_3079 = M2C_FIELD(temp_r27_2717, f32 *, 0xD8);
                        temp_f1_3080 = M2C_FIELD(temp_r27_2717, f32 *, 0xDC);
                        temp_f3_3081 = M2C_FIELD(temp_r27_2717, f32 *, 0xE0);
                        var_f4_3086 = (temp_f3_3081 * temp_f3_3081) + ((temp_f2_3079 * temp_f2_3079) + (temp_f1_3080 * temp_f1_3080));
                        if (var_f4_3086 > 0.0f) {
                            temp_f1_3089 = __frsqrte(var_f4_3086);
                            temp_f1_3095 = 0.5 * temp_f1_3089 * -(((f64) var_f4_3086 * (temp_f1_3089 * temp_f1_3089)) - 3.0);
                            temp_f1_3099 = 0.5 * temp_f1_3095 * -(((f64) var_f4_3086 * (temp_f1_3095 * temp_f1_3095)) - 3.0);
                            var_f4_3086 = (f32) ((f64) var_f4_3086 * (0.5 * temp_f1_3099 * -(((f64) var_f4_3086 * (temp_f1_3099 * temp_f1_3099)) - 3.0)));
                        } else if (var_f4_3086 < M2C_BITWISE(f32, 0.0)) {
                            var_f4_3086 = __float_nan;
                        } else {
                            arg_sp14 = var_f4_3086;
                            temp_r3_3118 = M2C_BITWISE(s32, arg_sp14) & 0x7F800000;
                            switch (temp_r3_3118) { /* switch 2; irregular */
                            case 0x7F800000:        /* switch 2 */
                                if (M2C_BITWISE(s32, arg_sp14) & 0x7FFFFF) {
                                    var_r0_3128 = 1;
                                } else {
                                    var_r0_3128 = 2;
                                }
                                break;
                            case 0x0:               /* switch 2 */
                                if (M2C_BITWISE(s32, arg_sp14) & 0x7FFFFF) {
                                    var_r0_3128 = 5;
                                } else {
                                    var_r0_3128 = 3;
                                }
                                break;
                            default:                /* switch 2 */
                                var_r0_3128 = 4;
                                break;
                            }
                            if (var_r0_3128 == 1) {
                                var_f4_3086 = __float_nan;
                            }
                        }
                        M2C_FIELD(temp_r27_2717, f32 *, 0x148) = (f32) (1000.0f + var_f4_3086);
                        M2C_FIELD(temp_r27_2717, u8 *, 0x159) = 1U;
                        M2C_FIELD(temp_r27_2717, f32 *, 0x14C) = 0.0f;
                        if (((ManagedLight *) this->unk3F84 != NULL) && (EventCamera_GetCurrent() == NULL)) {
                            ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->EnableLight(this->unk3F84, 1U);
                            arg_sp248.operator*(100.0f);
                            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                            temp_r3_3178 = this->unk3F84;
                            arg_sp258 = arg_spB8;
                            arg_spC0 = arg_sp318 + arg_sp250;
                            temp_r3_3178->unk10 = arg_spB8;
                            temp_r3_3178->unk18 = (f64) arg_spC0;
                            temp_r3_3184 = temp_r3_3178->unk3C;
                            arg_sp260 = (f64) arg_spC0;
                            if (temp_r3_3184 != NULL) {
                                M2C_FIELD(temp_r3_3184, f64 *, 0x10) = arg_spB8;
                                M2C_FIELD(temp_r3_3184, f64 *, 0x18) = (f64) arg_spC0;
                            }
                            temp_r3_3191 = this->unk3F84;
                            temp_r3_3191->unk38 = 1000.0f;
                            temp_r3_3194 = temp_r3_3191->unk3C;
                            if (temp_r3_3194 != NULL) {
                                M2C_FIELD(temp_r3_3194, f32 *, 0x20) = 1000.0f;
                                M2C_FIELD(temp_r3_3194, f32 *, 0x24) = 1000000.0f;
                                M2C_FIELD(temp_r3_3194, f32 *, 0x28) = 0.001f;
                                M2C_FIELD(temp_r3_3194, f32 *, 0x2C) = (f32) (1.0f / M2C_FIELD(temp_r3_3194, f32 *, 0x24));
                            }
                            temp_r0_3207 = this->unk3F78;
                            if (temp_r0_3207 == 1) {
                                arg_spA8 = 1.0f;
                                temp_r3_3214 = this->unk3F84;
                                arg_spAC = 0.7f;
                                arg_spB0 = 0.1f;
                                arg_spB4 = 1.0f;
                                temp_r3_3214->unk20 = (f64) arg_spA8;
                                temp_r3_3214->unk28 = (f64) arg_spB0;
                                temp_r3_3222 = temp_r3_3214->unk3C;
                                arg_sp238 = (f64) arg_spA8;
                                arg_sp240 = (f64) arg_spB0;
                                if (temp_r3_3222 != NULL) {
                                    M2C_FIELD(temp_r3_3222, f64 *, 0) = (f64) arg_spA8;
                                    M2C_FIELD(temp_r3_3222, f64 *, 8) = (f64) arg_spB0;
                                }
                            } else if (temp_r0_3207 == 3) {
                                arg_sp98 = 0.125f;
                                temp_r3_3236 = this->unk3F84;
                                arg_sp9C = 0.125f;
                                arg_spA0 = 1.0f;
                                arg_spA4 = 1.0f;
                                temp_r3_3236->unk20 = (f64) arg_sp98;
                                temp_r3_3236->unk28 = (f64) arg_spA0;
                                temp_r3_3244 = temp_r3_3236->unk3C;
                                arg_sp228 = (f64) arg_sp98;
                                arg_sp230 = (f64) arg_spA0;
                                if (temp_r3_3244 != NULL) {
                                    M2C_FIELD(temp_r3_3244, f64 *, 0) = (f64) arg_sp98;
                                    M2C_FIELD(temp_r3_3244, f64 *, 8) = (f64) arg_spA0;
                                }
                            }
                            this->unk3F88 = 0.5f;
                        } else {
                            temp_r4_3256 = this->unk3F84;
                            if (temp_r4_3256 != NULL) {
                                ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->EnableLight(temp_r4_3256, 0U);
                            }
                        }
                        SpawnGroundCollisionFX((LFX_Blob *) temp_r24_2994);
                        temp_r24_3267 = temp_r27_2717 + 0x138;
                        M2C_FIELD(temp_r27_2717, f32 *, 0x138) = 0.0f;
                        M2C_FIELD(temp_r27_2717, f32 *, 0x13C) = 0.0f;
                        M2C_FIELD(temp_r27_2717, f32 *, 0x140) = 0.0f;
                        if ((arg_sp360 != 0) && (arg_sp358 != NULL) && (var_r0_3277 = M2C_FIELD(arg_sp358, void **, 8), ((var_r0_3277 == NULL) == 0))) {

                        } else {
                            var_r0_3277 = NULL;
                        }
                        if (var_r0_3277 != NULL) {
                            var_f0_3286 = 0.0f;
                            arg_sp88 = 0.0f;
                            arg_sp8C = 1.0f;
                            arg_sp90 = 0.0f;
                            M2C_FIELD(temp_r27_2717, f32 *, 0x138) = (f64) arg_sp88;
                            M2C_FIELD(temp_r24_3267, f64 *, 8) = (f64) arg_sp90;
                            temp_f3_3297 = M2C_FIELD(temp_r27_2717, f32 *, 0x138);
                            temp_f4_3298 = M2C_FIELD(temp_r27_2717, f32 *, 0x140);
                            temp_f9_3302 = M2C_FIELD(temp_r27_2717, f32 *, 0x13C);
                            arg_sp218 = (f64) arg_sp88;
                            arg_sp220 = (f64) arg_sp90;
                            arg_sp14C = (temp_f4_3298 * arg_sp320) - (temp_f3_3297 * arg_sp328);
                            arg_sp148 = (temp_f9_3302 * arg_sp328) - (temp_f4_3298 * arg_sp324);
                            arg_sp150 = (temp_f3_3297 * arg_sp324) - (temp_f9_3302 * arg_sp320);
                            arg_sp208 = (f64) arg_sp148;
                            arg_sp210 = (f64) arg_sp150;
                            var_f4_3324 = ((f32) arg_sp210 * (f32) arg_sp210) + (((f32) arg_sp208 * (f32) arg_sp208) + (arg_sp20C * arg_sp20C));
                            if (var_f4_3324 > 1e-12f) {
                                if (var_f4_3324 > 0.0f) {
                                    temp_f1_3329 = __frsqrte(var_f4_3324);
                                    temp_f1_3335 = 0.5 * temp_f1_3329 * -(((f64) var_f4_3324 * (temp_f1_3329 * temp_f1_3329)) - 3.0);
                                    temp_f1_3339 = 0.5 * temp_f1_3335 * -(((f64) var_f4_3324 * (temp_f1_3335 * temp_f1_3335)) - 3.0);
                                    var_f4_3324 = (f32) ((f64) var_f4_3324 * (0.5 * temp_f1_3339 * -(((f64) var_f4_3324 * (temp_f1_3339 * temp_f1_3339)) - 3.0)));
                                } else if (var_f4_3324 < M2C_BITWISE(f32, 0.0)) {
                                    var_f4_3324 = __float_nan;
                                } else {
                                    arg_sp10 = var_f4_3324;
                                    temp_r3_3358 = M2C_BITWISE(s32, arg_sp10) & 0x7F800000;
                                    switch (temp_r3_3358) { /* switch 3; irregular */
                                    case 0x7F800000: /* switch 3 */
                                        if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                                            var_r0_3368 = 1;
                                        } else {
                                            var_r0_3368 = 2;
                                        }
                                        break;
                                    case 0x0:       /* switch 3 */
                                        if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                                            var_r0_3368 = 5;
                                        } else {
                                            var_r0_3368 = 3;
                                        }
                                        break;
                                    default:        /* switch 3 */
                                        var_r0_3368 = 4;
                                        break;
                                    }
                                    if (var_r0_3368 == 1) {
                                        var_f4_3324 = __float_nan;
                                    }
                                }
                                var_f0_3286 = 1.0f / var_f4_3324;
                            }
                            arg_sp138 = (f32) arg_sp208 * var_f0_3286;
                            arg_sp13C = arg_sp20C * var_f0_3286;
                            arg_sp140 = (f32) arg_sp210 * var_f0_3286;
                            arg_sp2A8 = (f64) arg_sp138;
                            arg_sp2B0 = (f64) arg_sp140;
                            arg_sp60 = 0.0f;
                            arg_sp58 = 0.0f;
                            arg_sp78 = (arg_sp324 * (f32) arg_sp2B0) - (arg_sp328 * arg_sp2AC);
                            arg_sp7C = (arg_sp328 * (f32) arg_sp2A8) - (arg_sp320 * (f32) arg_sp2B0);
                            arg_sp80 = (arg_sp320 * arg_sp2AC) - (arg_sp324 * (f32) arg_sp2A8);
                            arg_sp1C8 = (f64) arg_sp78;
                            arg_sp1D0 = (f64) arg_sp80;
                            arg_sp5C = -1.0f;
                            arg_sp68 = -(f32) arg_sp1C8;
                            arg_sp6C = -arg_sp1CC;
                            arg_sp70 = -(f32) arg_sp1D0;
                            arg_sp1B8 = (f64) arg_sp58;
                            arg_sp1D8 = (f64) arg_sp68;
                            arg_sp1C0 = (f64) arg_sp60;
                            arg_sp1E0 = (f64) arg_sp70;
                            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                            arg_sp1E8 = arg_sp48;
                            arg_sp50 = (f32) arg_sp1E0 + (f32) arg_sp1C0;
                            arg_sp1F0 = (f64) arg_sp50;
                            Normalise(*((MKVector3 *) &arg_sp1F8));
                            M2C_FIELD(temp_r27_2717, f32 *, 0x138) = arg_sp1F8;
                            M2C_FIELD(temp_r24_3267, f64 *, 8) = arg_sp200;
                            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r24, 0x0, qr0 */);
                            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
                            M2C_ERROR(/* unknown instruction: psq_stx $f0, $zero, $r24, 0x0, qr0 */);
                            M2C_FIELD(temp_r27_2717, f32 *, 0x140) = (f32) (M2C_FIELD(temp_r27_2717, f32 *, 0x140) * 980.0f);
                        }
                    }
                }
                if ((u8) M2C_FIELD(temp_r27_2717, u8 *, 0x159) != 0) {
                    M2C_ERROR(/* unknown instruction: psq_lx $f0, $r27, $r0, 0x0, qr0 */);
                    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f28 */);
                    arg_sp1A8 = arg_sp38;
                    arg_sp40 = M2C_FIELD(temp_r27_2717, f32 *, 0x140) * gUpdateTimeDelta;
                    arg_sp1B0 = (f64) arg_sp40;
                    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
                    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                    M2C_ERROR(/* unknown instruction: psq_stx $f0, $zero, $r0, 0x0, qr0 */);
                    M2C_FIELD(temp_r27_2717, f64 *, 0xD0) = (f32) ((f32) M2C_FIELD(temp_r27_2717, f64 *, 0xD0) + (f32) arg_sp1B0);
                    temp_f6_3502 = M2C_FIELD(temp_r27_2717, f32 *, 0xEC);
                    temp_f1_3503 = 3.0f * M2C_FIELD(temp_r27_2717, f32 *, 0x15C);
                    var_f4_3506 = temp_f6_3502 - M2C_FIELD(temp_r27_2717, f32 *, 0x148);
                    if (var_f4_3506 < temp_f1_3503) {

                    } else {
                        var_f4_3506 = temp_f1_3503;
                    }
                    if (var_f4_3506 > 0.1f) {

                    } else {
                        var_f4_3506 = 0.1f;
                    }
                    var_f5_3524 = 0.5f * (0.95f * (15.0f * gUpdateTimeDelta));
                    if (var_f5_3524 < 1.0f) {

                    } else {
                        var_f5_3524 = 1.0f;
                    }
                    temp_f1_3534 = (var_f5_3524 * (var_f4_3506 - temp_f6_3502)) + temp_f6_3502;
                    M2C_FIELD(temp_r27_2717, f32 *, 0xEC) = (f32) ((var_f5_3524 * (var_f4_3506 - temp_f1_3534)) + temp_f1_3534);
                    temp_f6_3539 = M2C_FIELD(temp_r27_2717, f32 *, 0xE8);
                    temp_f2_3541 = 3.0f * M2C_FIELD(temp_r27_2717, f32 *, 0x15C);
                    var_f4_3543 = temp_f6_3539 + M2C_FIELD(temp_r27_2717, f32 *, 0x148);
                    if (var_f4_3543 < temp_f2_3541) {

                    } else {
                        var_f4_3543 = temp_f2_3541;
                    }
                    if (var_f4_3543 > 0.1f) {

                    } else {
                        var_f4_3543 = 0.1f;
                    }
                    var_f5_3562 = 0.5f * (0.95f * (15.0f * gUpdateTimeDelta));
                    if (var_f5_3562 < 1.0f) {

                    } else {
                        var_f5_3562 = 1.0f;
                    }
                    temp_f1_3572 = (var_f5_3562 * (var_f4_3543 - temp_f6_3539)) + temp_f6_3539;
                    M2C_FIELD(temp_r27_2717, f32 *, 0xE8) = (f32) ((var_f5_3562 * (var_f4_3543 - temp_f1_3572)) + temp_f1_3572);
                    temp_f5_3577 = M2C_FIELD(temp_r27_2717, f32 *, 0xF0);
                    temp_f2_3579 = 3.0f * M2C_FIELD(temp_r27_2717, f32 *, 0x15C);
                    var_f4_3581 = temp_f5_3577 + M2C_FIELD(temp_r27_2717, f32 *, 0x148);
                    if (var_f4_3581 < temp_f2_3579) {

                    } else {
                        var_f4_3581 = temp_f2_3579;
                    }
                    if (var_f4_3581 > 0.1f) {

                    } else {
                        var_f4_3581 = 0.1f;
                    }
                    var_f2_3600 = 0.5f * (0.95f * (15.0f * gUpdateTimeDelta));
                    if (var_f2_3600 < 1.0f) {

                    } else {
                        var_f2_3600 = 1.0f;
                    }
                    temp_f1_3608 = (var_f2_3600 * (var_f4_3581 - temp_f5_3577)) + temp_f5_3577;
                    M2C_FIELD(temp_r27_2717, f32 *, 0xF0) = (f32) ((var_f2_3600 * (var_f4_3581 - temp_f1_3608)) + temp_f1_3608);
                }
                temp_f2_3615 = M2C_FIELD(temp_r27_2717, f32 *, 0x150);
                var_f0_3616 = M2C_FIELD(temp_r27_2717, f32 *, 0x14C) + gUpdateTimeDelta;
                if (var_f0_3616 < temp_f2_3615) {

                } else {
                    var_f0_3616 = temp_f2_3615;
                }
                if (var_f0_3616 > 0.0f) {

                } else {
                    var_f0_3616 = 0.0f;
                }
                M2C_FIELD(temp_r27_2717, f32 *, 0x14C) = var_f0_3616;
                M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
                if ((M2C_FIELD(temp_r27_2717, f32 *, 0x14C) == M2C_FIELD(temp_r27_2717, f32 *, 0x150)) || (EventCamera_GetCurrent() != NULL)) {
                    M2C_FIELD(temp_r27_2717, u8 *, 0x158) = 0U;
                    this->unk3F60 -= 1;
                }
                temp_r0_3646 = this->unk3F78;
                if (temp_r0_3646 != 1) {
                    if (temp_r0_3646 < 1) {

                    }
                } else {
                    M2C_FIELD(temp_r27_2717, f32 *, 0x160) = (f32) (M2C_FIELD(temp_r27_2717, f32 *, 0x160) + gUpdateTimeDelta);
                    if ((u8) M2C_FIELD(temp_r27_2717, u8 *, 0x159) == 0) {
                        if (MKRand_Int(&gViewSeed, 0, 0xA) == 0) {
                            temp_f24_3670 = MKRand_Float(&gViewSeed, 1.0f, 2.0f);
                            arg_sp12C = MKRand_Float(&gViewSeed, 400.0f, 600.0f);
                            arg_sp128 = 0.0f;
                            arg_sp130 = 0.0f;
                            arg_sp198 = (f64) arg_sp128;
                            arg_sp1A0 = (f64) arg_sp130;
                            ((HeatDistortPS *) (&gb + 0x240))->Emit(*(temp_r27_2717 + 0xC8), *((MKVector3 *) &arg_sp198), temp_f24_3670, 1.0f);
                        }
                        M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
                        if (M2C_FIELD(temp_r27_2717, f32 *, 0x160) == MKRand_Float(&gViewSeed, 0.01f, 0.135f)) {
                            M2C_FIELD(temp_r27_2717, f32 *, 0x160) = 0.0f;
                        }
                        temp_r24_3701 = temp_r27_2717 + 0xC8;
                        if ((temp_r24_3701->IsWithin(*((MKVector3 *) &arg_sp24), &arg_sp20, M2C_ERROR(/* Read from unset register $r6 */)) != 0) && (M2C_BITWISE(s32, arg_sp20) == 0)) {
                            temp_f24_3715 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                            temp_f25_3720 = MKRand_Float(&gViewSeed, 0.0f, 1.0f);
                            arg_sp118 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                            arg_sp11C = temp_f25_3720;
                            arg_sp120 = temp_f24_3715;
                            arg_sp178 = (f64) arg_sp118;
                            arg_sp180 = (f64) arg_sp120;
                            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
                            arg_sp188 = arg_sp108;
                            arg_sp110 = (f32) arg_sp180 * 200.0f;
                            arg_sp190 = (f64) arg_sp110;
                            arg_sp1C = MKRand_Float(&gViewSeed, 5.0f, 10.0f);
                            arg_spF8 = 1.0f;
                            arg_spFC = 1.0f;
                            arg_sp100 = 1.0f;
                            arg_sp104 = 1.0f;
                            arg_sp168 = (f64) arg_spF8;
                            arg_sp170 = (f64) arg_sp100;
                            ((CrashMistPS *) (M2C_FIELD(temp_r30_2661, CrashMistPS **, 0xE4)))->Emit(*((MKVector3 *) temp_r24_3701), *((MKVector3 *) &arg_sp188), arg_sp1C, 0.1f, *((MKVector4 *) &arg_sp168), 1.0f);
                            M2C_FIELD(temp_r27_2717, u8 *, 0x158) = 0U;
                            this->unk3F60 -= 1;
                        }
                    }
                }
            }
            var_r23_2713 += 1;
            var_r21_2715 += 0xA0;
        } while (var_r23_2713 < 0x64);
    }
    if ((s32) this->unk3F78 == 3) {
        this->unk3F7C += 5.0f * gUpdateTimeDelta;
        temp_f0_3784 = this->unk3F7C;
        M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
        if (temp_f0_3784 == 5.0f) {
            this->unk3F7C = temp_f0_3784 - 5.0f;
        }
        M2C_STRUCT_COPY((s32) &arg_sp2CC + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
        arg_sp2D0.Scale3x3((Matrix *) &arg_sp2D0, 4.0f);
        arg_sp30 = 0.0f;
        arg_sp28 = 0.0f;
        arg_sp2C = -this->unk3F7C;
        arg_sp160 = (f64) arg_sp30;
        arg_sp158 = (f64) arg_sp28;
        arg_sp300 = (f32) arg_sp158;
        arg_sp304 = arg_sp15C;
        arg_sp308 = (f32) arg_sp160;
        arg_sp30C = 1.0f;
        MKMaterial_SetTextureMatrix(this->unk3F6C, (Matrix *) &arg_sp2D0);
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'IMPACT_LIGHT_RADIUS'
void LiquidFX::Resolve() {
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
    ManagedLight *temp_r4_3898;

    KDPropEx::Resolve();
    sp20 = 0.0f;
    sp30 = 0.0f;
    sp8 = 0.5f;
    spC = 0.5f;
    sp10 = 1.0f;
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
    this->unk3F84 = ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->AllocManagedLight(*((MKVector3 *) &sp58), *((MKVector3 *) &sp48), *((MKVector4 *) &sp38), IMPACT_LIGHT_RADIUS, lit_688, lit_689);
    temp_r4_3898 = this->unk3F84;
    if (temp_r4_3898 != NULL) {
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->EnableLight(temp_r4_3898, 0U);
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'MKResource *' to
void LiquidFX::LoadDone() {
    GameProp::LoadDone();
    this->unk3F64 = MKMaterial_Create("p_debris_lava");
    this->unk3F6C = MKMaterial_Create("liquidice");
    this->unk3F70 = MKMaterial_Create("liquidiceblob");
    this->unk3F74 = MKMaterial_Create("fx_380");
}
#endif

#if 0 // DRAFT: illegal operand
void LiquidFX::Init() {
    s32 temp_r0_3961;
    s32 var_ctr_3959;
    s32 var_r3_3956;

    GameProp::Init();
    var_r3_3956 = 0;
    var_ctr_3959 = 0x64;
    do {
        temp_r0_3961 = var_r3_3956 + 0x158;
        var_r3_3956 += 0xA0;
        *(this + temp_r0_3961) = 0;
        var_ctr_3959 -= 1;
    } while (var_ctr_3959 != 0);
    this->unk3F48.Init(0x64, 0U);
    this->unk3F5C = 0;
    this->unk3F60 = 0;
    this->unk3F64 = NULL;
    this->unk3F6C = NULL;
    this->unk3F70 = NULL;
    this->unk3F74 = NULL;
    this->unk3F68 = 0.0f;
    this->unk3F7C = 0.0f;
    this->unk3F80 = NULL;
    this->unk3F88 = 0.0f;
    this->unk3F78 = 1;
}
#endif

#if 0 // DRAFT: undefined identifier 'unkE4'
void LiquidFXDescriptor::LoadDone() {
    GamePropDescriptor::LoadDone();
    this->unkE4 = checked_cast<CrashMistPS *, MKProp>(gMK->CreateProp("CrashMistPS"));
}
#endif

#if 0 // DRAFT: expression syntax error
void LiquidFXDescriptor::Deinit() {
    LiquidFXDescriptor *temp_r3_4028;
    LiquidFXDescriptor *temp_r3_4034;

    KDPropExDescriptor::Deinit();
    if ((s8 *) LiquidFXDescriptor::pFirstDesc.unk0 == this) {
        LiquidFXDescriptor::pFirstDesc.unk0 = (s8 *) this->unkF0;
    }
    temp_r3_4028 = this->unkEC;
    if (temp_r3_4028 != NULL) {
        temp_r3_4028->unkF0 = this->unkF0;
    }
    temp_r3_4034 = this->unkF0;
    if (temp_r3_4034 != NULL) {
        temp_r3_4034->unkEC = this->unkEC;
    }
    this->unkEC = NULL;
    this->unkF0 = NULL;
    this->unkE8 = 0;
}
#endif

#if 0 // DRAFT: expression syntax error
void LiquidFXDescriptor::Init() {
    GamePropDescriptor::Init();
    this->unkF0 = (LiquidFXDescriptor *) LiquidFXDescriptor::pFirstDesc.unk0;
    this->unkEC = NULL;
    if ((s8 *) LiquidFXDescriptor::pFirstDesc.unk0 != NULL) {
        M2C_FIELD(LiquidFXDescriptor::pFirstDesc.unk0, LiquidFXDescriptor **, 0xEC) = this;
    }
    LiquidFXDescriptor::pFirstDesc.unk0 = (s8 *) this;
    this->unkE8 = gMK->GetWorkingChunk();
}
#endif
