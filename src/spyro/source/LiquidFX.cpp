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
#include "spyro/source/KDSpline.h"
#include "spyro/source/KDWaterVolume.h"
#include "spyro/source/LightManager.h"
#include "spyro/source/ManagedLight.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
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
    f64 sp88;
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    f32 sp70;
    f64 sp68;
    f32 sp60;
    f64 sp58;
    f32 sp50;
    f64 sp48;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp30;
    f64 sp28;
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
    f64 temp_f0_242;
    f64 temp_f0_253;
    f64 temp_f0_264;
    f64 temp_f0_297;
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
        var_f4_110 = ((f32) sp130 * (f32) sp130) + (((f32) sp128 * (f32) sp128) + ((*(f32 *) ((u8 *) &sp120 + 0xc)) * (*(f32 *) ((u8 *) &sp120 + 0xc))));
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
        (*(f32 *) ((u8 *) &sp120 + 0xc)) *= var_f27_84;
        sp130 = temp_f0_184;
        sp88 = (f64) sp128 * 5.620037986e-315;
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
            temp_f0_242 = spD8 * (f64) temp_f30_219;
            sp68 = temp_f0_242;
            spE8 = temp_f0_242;
            sp70 = (f32) spE0 * temp_f30_219;
            spF0 = (f64) sp70;
            temp_f0_253 = temp_f0_242 * 5.51933903e-315;
            sp58 = temp_f0_253;
            spF8 = temp_f0_253;
            sp60 = (f32) spF0 * 75.0f;
            sp100 = (f64) sp60;
            temp_f0_264 = arg0->unk0 + temp_f0_253;
            sp48 = temp_f0_264;
            sp108 = temp_f0_264;
            sp50 = arg0->unk8 + (f32) sp100;
            sp110 = (f64) sp50;
            temp_f25_278 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
            temp_f26_283 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
            sp38 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
            sp3C = temp_f26_283;
            sp40 = temp_f25_278;
            spB8 = (f64) sp38;
            spC0 = (f64) sp40;
            temp_f0_297 = spB8 * 5.603848443e-315;
            sp28 = temp_f0_297;
            spC8 = temp_f0_297;
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

#if 0 // DRAFT: illegal explicit conversion from 'const float *' to
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
    f64 sp48;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f64 sp8;
    f32 temp_f29_497;
    f32 temp_f29_524;
    f32 temp_f30_502;
    f32 temp_f30_529;
    f64 temp_f0_428;
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
        temp_f0_428 = M2C_FIELD(&arg1, f64 *, 0) + sp78;
        sp28 = temp_f0_428;
        sp88 = temp_f0_428;
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
    sp8 = sp48 * 5.081185235e-315;
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
    ((KDSpline *) &this->unk3F48)->Deinit();
}

#if 0 // DRAFT: illegal implicit conversion from 'void' to
void LiquidFX::Draw() {
    f64 sp3F50;
    f64 sp3F48;
    f64 sp3F40;
    f64 sp3F38;
    f64 sp3F30;
    f32 sp3F2C;
    f32 sp3F28;
    f32 sp3F24;
    f32 sp3F20;
    f32 sp3F1C;
    f32 sp3F18;
    f32 sp3F14;
    f32 sp3F10;
    M2C_UNK sp1960;
    M2C_UNK sp1320;
    M2C_UNK spCE0;
    f64 spCD8;
    f64 spCD0;
    f64 spCC8;
    f64 spCC0;
    f64 spCB8;
    f64 spCB0;
    f64 spCA8;
    f64 spCA0;
    MKVector3 spC90;
    MKVector3 spC80;
    MKVector3 spC70;
    MKVector3 spC60;
    MKVector3 spC50;
    MKVector3 spC40;
    MKVector3 spC30;
    MKVector3 spC20;
    Matrix spBE0;
    Matrix spBA0;
    Matrix spB60;
    Matrix spB20;
    f64 spB18;
    f64 spB10;
    f64 spB08;
    f64 spB00;
    f64 spAF8;
    f64 spAF0;
    f64 spAE8;
    f64 spAE0;
    f64 spAD8;
    f64 spAD0;
    f64 spAC8;
    f64 spAC0;
    f64 spAB8;
    f64 spAB0;
    f64 spAA8;
    f64 spAA0;
    f64 spA98;
    f64 spA90;
    f64 spA88;
    f64 spA80;
    f64 spA78;
    f64 spA70;
    f64 spA68;                                      /* compiler-managed */
    f64 spA60;                                      /* compiler-managed */
    f64 spA58;                                      /* compiler-managed */
    f64 spA50;                                      /* compiler-managed */
    f64 spA48;
    f64 spA40;
    f64 spA38;
    f64 spA30;
    f64 spA28;
    f64 spA20;
    f64 spA18;
    f64 spA10;
    f64 spA08;
    f64 spA00;
    MKVector3 sp9F0;
    f64 sp9E8;
    f64 sp9E0;
    MKVector3 sp9D0;
    f64 sp9C8;
    f64 sp9C0;
    MKVector3 sp9B0;
    MKVector3 sp9A0;
    f64 sp998;
    f64 sp990;
    MKVector3 sp980;
    MKVector3 sp970;
    f64 sp968;
    f64 sp960;
    f64 sp958;
    f64 sp950;
    MKVector3 sp940;
    f64 sp938;
    f64 sp930;
    MKVector3 sp920;
    f64 sp918;
    f64 sp910;
    f64 sp908;
    f64 sp900;
    f64 sp8F8;
    f64 sp8F0;
    f64 sp8E0;
    f64 sp8D8;
    f64 sp8D0;
    f64 sp8C0;
    f64 sp8B0;
    f64 sp8A0;
    f64 sp890;
    f64 sp880;
    f64 sp878;
    f64 sp870;
    f64 sp868;
    f64 sp860;
    f64 sp858;
    f64 sp850;
    MKVector3 sp840;
    MKVector3 sp830;
    f64 sp828;
    f64 sp820;
    f64 sp818;
    f64 sp810;
    f64 sp808;
    f64 sp800;
    f64 sp7F8;
    f64 sp7F0;
    f64 sp7E8;
    f64 sp7E0;
    f64 sp7D8;
    f64 sp7D0;
    MKVector3 sp7C0;
    f64 sp7B8;
    f64 sp7B0;
    MKVector3 sp7A0;
    MKVector3 sp790;
    f64 sp788;
    f64 sp780;
    f64 sp778;
    f64 sp770;
    f64 sp768;
    f64 sp760;
    f64 sp758;
    f64 sp750;
    f64 sp748;
    f64 sp740;
    f64 sp738;
    f64 sp730;
    f64 sp728;
    f64 sp720;
    f64 sp718;
    f64 sp710;
    f64 sp708;
    f64 sp700;
    f64 sp6F8;
    f64 sp6F0;
    f64 sp6E8;
    f64 sp6E0;
    f64 sp6D8;
    f64 sp6D0;
    f64 sp6C8;
    f64 sp6C0;
    f64 sp6B8;
    f64 sp6B0;
    f64 sp6A8;
    f64 sp6A0;
    f64 sp698;
    f64 sp690;
    f64 sp688;
    f64 sp680;
    f64 sp678;
    f64 sp670;
    f64 sp668;
    f64 sp660;
    f64 sp658;
    f64 sp650;
    f64 sp648;
    f64 sp640;
    f64 sp638;
    f64 sp630;
    f64 sp628;
    f64 sp620;
    f64 sp618;
    f64 sp610;
    f64 sp608;
    f64 sp600;
    f64 sp5F8;
    f64 sp5F0;
    f64 sp5E8;
    f64 sp5E0;
    f64 sp5D8;
    f64 sp5D0;
    f64 sp5C8;
    f64 sp5C0;
    f64 sp5B8;
    f64 sp5B0;
    f64 sp5A8;
    f64 sp5A0;
    f64 sp598;
    f64 sp590;
    f64 sp588;
    f64 sp580;
    f64 sp578;
    f64 sp570;
    f64 sp568;
    f64 sp560;
    f64 sp558;
    f64 sp550;
    f64 sp548;
    f64 sp540;
    f64 sp538;
    f64 sp530;
    f64 sp528;
    f64 sp520;
    f64 sp518;
    f64 sp510;
    f64 sp508;
    f64 sp500;
    f64 sp4F8;
    f64 sp4F0;
    f64 sp4E8;
    f64 sp4E0;
    f64 sp4D8;
    f64 sp4D0;
    f64 sp4C8;
    f64 sp4C0;
    f64 sp4B8;
    f64 sp4B0;
    f32 sp4A8;
    f32 sp4A4;
    f32 sp4A0;
    f32 sp498;
    f32 sp494;
    f32 sp490;
    f32 sp488;
    f64 sp480;
    f32 sp478;
    f32 sp474;
    f32 sp470;
    f32 sp46C;
    f32 sp468;
    f32 sp464;
    f32 sp460;
    f32 sp45C;
    f32 sp458;
    f32 sp454;
    f32 sp450;
    f32 sp44C;
    f32 sp448;
    f32 sp444;
    f32 sp440;
    f32 sp438;
    f32 sp434;
    f32 sp430;
    f32 sp428;
    f32 sp424;
    f32 sp420;
    f32 sp41C;
    f32 sp418;
    f32 sp414;
    f32 sp410;
    f32 sp408;
    f64 sp400;
    f32 sp3F8;
    f32 sp3F4;
    f32 sp3F0;
    f32 sp3E8;
    f64 sp3E0;
    f32 sp3D8;
    f32 sp3D4;
    f32 sp3D0;
    f32 sp3C8;
    f64 sp3C0;
    f32 sp3B8;
    f64 sp3B0;
    f32 sp3A8;
    f32 sp3A4;
    f32 sp3A0;
    f32 sp398;
    f64 sp390;
    f32 sp388;
    f32 sp384;
    f32 sp380;
    f32 sp378;
    f64 sp370;
    f32 sp368;
    f64 sp360;
    f32 sp358;
    f32 sp354;
    f32 sp350;
    f32 sp348;
    f64 sp340;
    f32 sp338;
    f32 sp334;
    f32 sp330;
    f32 sp328;
    f64 sp320;
    f32 sp318;
    f32 sp314;
    f32 sp310;
    f32 sp308;
    f64 sp300;
    f32 sp2F8;
    f32 sp2F4;
    f32 sp2F0;
    f32 sp2E8;
    f64 sp2E0;
    f32 sp2D8;
    f32 sp2D4;
    f32 sp2D0;
    f32 sp2C8;
    f64 sp2C0;
    f32 sp2B8;
    f32 sp2B4;
    f32 sp2B0;
    f32 sp2A8;
    f64 sp2A0;
    f32 sp298;
    f64 sp290;
    f32 sp288;
    f64 sp280;
    f32 sp278;
    f64 sp270;
    f32 sp268;
    f32 sp264;
    f32 sp260;
    f32 sp258;
    f64 sp250;
    f32 sp248;
    f64 sp240;
    f32 sp238;
    f64 sp230;
    f32 sp228;
    f64 sp220;
    f32 sp218;
    f64 sp210;
    f32 sp208;
    f64 sp200;
    f32 sp1F8;
    f64 sp1F0;
    f32 sp1E8;
    f64 sp1E0;
    f32 sp1D8;
    f64 sp1D0;
    f32 sp1C8;
    f32 sp1C4;
    f32 sp1C0;
    f32 sp1B8;
    f64 sp1B0;
    f32 sp1A8;
    f64 sp1A0;
    f32 sp198;
    f64 sp190;
    f32 sp188;
    f64 sp180;
    f32 sp178;
    f32 sp174;
    f32 sp170;
    f32 sp168;
    f32 sp164;
    f32 sp160;
    f32 sp158;
    f32 sp154;
    f32 sp150;
    f32 sp148;
    f64 sp140;
    f32 sp138;
    f64 sp130;
    f32 sp128;
    f64 sp120;
    f32 sp118;
    f64 sp110;
    f32 sp108;
    f64 sp100;
    f32 spF8;
    f64 spF0;
    f32 spE8;
    f64 spE0;
    f32 spD8;
    f64 spD0;
    f32 spC8;
    f64 spC0;
    f32 spB8;
    f64 spB0;
    f32 spA8;
    f64 spA0;
    f32 sp98;
    f64 sp90;
    f32 sp88;
    f64 sp80;
    f32 sp78;
    f64 sp70;
    f32 sp68;
    f64 sp60;
    f32 sp58;
    f64 sp50;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    Matrix *temp_r19_1274;
    f32 temp_f0_1509;
    f32 temp_f14_1423;
    f32 temp_f1_1683;
    f32 temp_f1_946;
    f32 temp_f4_1808;
    f32 var_f17_1045;
    f32 var_f18_1023;
    f32 var_f8_1779;
    f64 *temp_r17_1881;
    f64 *temp_r3_1609;
    f64 temp_f0_1214;
    f64 temp_f0_1249;
    f64 temp_f0_1557;
    f64 temp_f0_1672;
    f64 temp_f0_1708;
    f64 temp_f0_1827;
    f64 temp_f0_1891;
    f64 temp_f0_1903;
    f64 temp_f0_1994;
    f64 temp_f0_2006;
    f64 temp_f0_2018;
    f64 temp_f0_2064;
    f64 temp_f0_2120;
    f64 temp_f0_2131;
    f64 temp_f0_2143;
    f64 temp_f0_2178;
    f64 temp_f0_2189;
    f64 temp_f0_2245;
    f64 temp_f0_2256;
    f64 temp_f0_2268;
    f64 temp_f0_2315;
    f64 temp_f0_2327;
    f64 temp_f0_2398;
    f64 temp_f0_2410;
    f64 temp_f0_2422;
    f64 temp_f0_935;
    f64 temp_f1_1512;
    f64 temp_f1_2053;
    f64 var_f15_1157;
    f64 var_f16_1146;
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
    void *temp_r3_1103;
    void *temp_r3_1135;
    void *temp_r3_1290;
    void *temp_r3_1665;
    void *temp_r3_928;
    void *temp_r3_988;
    void *temp_r4_1705;
    void *temp_r4_969;
    void *temp_r4_986;
    void *temp_r6_1280;

    this->unk3F50 = 0.0f;
    sp4A8 = 0.0f;
    var_r31_731 = 0;
    var_r16_732 = 0;
    sp498 = 0.0f;
    this->unk3F4C = 0;
    sp4A0 = 0.0f;
    sp4A4 = 1.0f;
    sp490 = 1.0f;
    sp494 = 0.0f;
    spB10 = (f64) sp4A0;
    spB18 = (f64) sp4A8;
    spB00 = (f64) sp490;
    spB08 = (f64) sp498;
    sp9D0.operator*(35.0f);
    sp40 = -(f32) spB00;
    sp44 = -(*(f32 *) ((u8 *) &spB00 + 0x4));
    sp48 = -(f32) spB08;
    sp9E0 = (f64) sp40;
    sp9E8 = (f64) sp48;
    sp9F0.operator*(35.0f);
    sp230 = sp9F0 + sp9D0;
    spA00 = sp230;
    sp238 = sp9F0.unk8 + sp9D0.unk8;
    spCA0 = sp230;
    spA08 = (f64) sp238;
    spCA8 = (f64) sp238;
    sp9A0.operator*(35.0f);
    sp9B0.operator*(35.0f);
    sp220 = sp9B0 + sp9A0;
    sp30 = -(f32) spB10;
    sp34 = -(*(f32 *) ((u8 *) &spB10 + 0x4));
    sp38 = -(f32) spB18;
    sp228 = sp9B0.unk8 + sp9A0.unk8;
    sp9C0 = sp220;
    sp9C8 = (f64) sp228;
    spCB0 = sp220;
    spCB8 = (f64) sp228;
    sp960 = (f64) sp30;
    sp968 = (f64) sp38;
    sp970.operator*(35.0f);
    sp980.operator*(35.0f);
    sp210 = sp980 + sp970;
    sp20 = -(f32) spB10;
    sp24 = -(*(f32 *) ((u8 *) &spB10 + 0x4));
    sp28 = -(f32) spB18;
    sp218 = sp980.unk8 + sp970.unk8;
    sp990 = sp210;
    sp998 = (f64) sp218;
    spCC0 = sp210;
    spCC8 = (f64) sp218;
    sp910 = (f64) sp20;
    sp918 = (f64) sp28;
    sp920.operator*(35.0f);
    sp10 = -(f32) spB00;
    sp14 = -(*(f32 *) ((u8 *) &spB00 + 0x4));
    sp18 = -(f32) spB08;
    sp930 = (f64) sp10;
    sp938 = (f64) sp18;
    sp940.operator*(35.0f);
    sp200 = sp940 + sp920;
    spCD0 = sp200;
    sp208 = sp940.unk8 + sp920.unk8;
    sp950 = sp200;
    spCD8 = (f64) sp208;
    sp958 = (f64) sp208;
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
                        temp_f0_935 = M2C_FIELD(temp_r20_913, f64 *, 0xC8) - M2C_FIELD(temp_r3_928, f64 *, 0xC8);
                        sp480 = temp_f0_935;
                        sp900 = temp_f0_935;
                        sp488 = M2C_FIELD(temp_r20_913, f32 *, 0xD0) - M2C_FIELD(temp_r3_928, f32 *, 0xD0);
                        temp_f1_946 = 90.0f * M2C_FIELD(temp_r20_913, f32 *, 0x100);
                        sp908 = (f64) sp488;
                        if ((((f32) sp908 * (f32) sp908) + (((f32) sp900 * (f32) sp900) + ((*(f32 *) ((u8 *) &sp900 + 0x4)) * (*(f32 *) ((u8 *) &sp900 + 0x4))))) < (temp_f1_946 * temp_f1_946)) {
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
                        ((KDSpline *) &this->unk3F48)->AddNode(*(temp_r4_969 + 0xC8));
                    } else {
                        ((KDSpline *) &this->unk3F48)->AddNode(*(temp_r20_913 + 0xC8));
                    }
                    temp_r5_982 = var_r16_732 * 0x10;
                    temp_r4_986 = &sp1320 + temp_r5_982;
                    temp_r3_988 = &spCE0 + temp_r5_982;
                    M2C_FIELD(temp_r4_986, f64 *, 0) = (f64) M2C_FIELD(temp_r20_913, f64 *, 0x108);
                    var_r16_732 += 1;
                    M2C_FIELD(temp_r3_988, f64 *, 0) = (f64) M2C_FIELD(temp_r20_913, f64 *, 0xE8);
                    M2C_FIELD(temp_r4_986, f64 *, 8) = (f64) M2C_FIELD(temp_r20_913, f64 *, 0x110);
                    M2C_FIELD(temp_r3_988, f64 *, 8) = (f64) M2C_FIELD(temp_r20_913, f64 *, 0xF0);
                }
            }
            if ((var_r18_912 == 0) && ((s32) this->unk3F4C > 1)) {
                temp_r0_1003 = var_r16_732 - 1;
                sp3F30 = 5.06792276e-315;
                var_r18_1013 = 0;
                do {
                    var_f18_1023 = (f32) sp3F30 * (f32) var_r18_1013;
                    if (var_f18_1023 < 1.0f) {

                    } else {
                        var_f18_1023 = 1.0f;
                    }
                    if (var_f18_1023 > 0.0f) {

                    } else {
                        var_f18_1023 = 0.0f;
                    }
                    var_f17_1045 = (f32) sp3F30 * (f32) (var_r18_1013 + 1);
                    if (var_f17_1045 < 1.0f) {

                    } else {
                        var_f17_1045 = 1.0f;
                    }
                    if (var_f17_1045 > 0.0f) {

                    } else {
                        var_f17_1045 = 0.0f;
                    }
                    temp_r16_1073 = (s32) ((f32) temp_r0_1003 * var_f18_1023) * 0x10;
                    temp_r3_1074 = &sp1320 + temp_r16_1073;
                    spAF8 = M2C_FIELD(temp_r3_1074, f64 *, 8);
                    temp_r19_1079 = (s32) ((f32) temp_r0_1003 * var_f17_1045) * 0x10;
                    temp_r3_1081 = &sp1320 + temp_r19_1079;
                    spAF0 = M2C_FIELD(temp_r3_1074, f64 *, 0);
                    spAE0 = M2C_FIELD(temp_r3_1081, f64 *, 0);
                    spAE8 = M2C_FIELD(temp_r3_1081, f64 *, 8);
                    sp3F38 = (f64) (0.05f * _table_sinf((f32) spAF8));
                    sp3F40 = (f64) (0.05f * _table_sinf((*(f32 *) ((u8 *) &spAF0 + 0x4))));
                    MKVector(0.05f * _table_sinf((f32) spAF0), (f32) sp3F40, (f32) sp3F38);
                    temp_r3_1103 = &spCE0 + temp_r16_1073;
                    sp1F0 = M2C_FIELD(temp_r3_1103, f64 *, 0) + sp8E0;
                    sp8F0 = sp1F0;
                    sp1F8 = M2C_FIELD(temp_r3_1103, f32 *, 8) + sp8E8;
                    spAF0 = sp1F0;
                    sp8F8 = (f64) sp1F8;
                    spAF8 = (f64) sp1F8;
                    sp3F48 = (f64) (0.05f * _table_sinf((f32) spAE8));
                    sp3F50 = (f64) (0.05f * _table_sinf((*(f32 *) ((u8 *) &spAE0 + 0x4))));
                    MKVector(0.05f * _table_sinf((f32) spAE0), (f32) sp3F50, (f32) sp3F48);
                    temp_r3_1135 = &spCE0 + temp_r19_1079;
                    sp1E0 = M2C_FIELD(temp_r3_1135, f64 *, 0) + sp8C0;
                    var_f16_1146 = 5.263544247e-315;
                    sp8D0 = sp1E0;
                    sp1E8 = M2C_FIELD(temp_r3_1135, f32 *, 8) + sp8C8;
                    spAE0 = sp1E0;
                    sp8D8 = (f64) sp1E8;
                    spAE8 = (f64) sp1E8;
                    if (var_r18_1013 == 0) {
                        var_f16_1146 = 0.0;
                    }
                    var_f15_1157 = 5.263544247e-315;
                    if (var_r18_1013 == 0x18) {
                        var_f15_1157 = 0.0;
                    }
                    ((KDSpline *) &sp8B0)->GetMeasure(var_f18_1023, (Matrix *) &this->unk3F48);
                    spAD0 = sp8B0;
                    spAD8 = sp8B8;
                    ((KDSpline *) &sp8A0)->GetMeasure(var_f18_1023, (Matrix *) &this->unk3F48);
                    spAC0 = sp8A0;
                    spAC8 = sp8A8;
                    ((KDSpline *) &sp890)->GetMeasure(var_f17_1045, (Matrix *) &this->unk3F48);
                    spAB0 = sp890;
                    spAB8 = sp898;
                    ((KDSpline *) &sp880)->GetMeasure(var_f17_1045, (Matrix *) &this->unk3F48);
                    spAA0 = sp880;
                    spAA8 = sp888;
                    ((MKVector3 *) &spAC0)->Normalise();
                    ((MKVector3 *) &spAA0)->Normalise();
                    sp478 = 0.0f;
                    sp470 = 0.0f;
                    sp474 = 1.0f;
                    spA98 = (f64) sp478;
                    spA90 = (f64) sp470;
                    KDMath_BuildMatrixFromFwd(&spBE0, *((MKVector3 *) &spAC0), (MKVector3 *) &spA90);
                    temp_f0_1214 = spAF0 * var_f16_1146;
                    sp1D0 = temp_f0_1214;
                    sp870 = temp_f0_1214;
                    sp1D8 = (f32) spAF8 * (f32) var_f16_1146;
                    sp878 = (f64) sp1D8;
                    spBE0.Scale3x3(&spBE0, *((MKVector3 *) &sp870));
                    sp1C8 = 0.0f;
                    sp1C0 = 0.0f;
                    sp1C4 = 1.0f;
                    spBE0.unk30 = (f32) spAD0;
                    spBE0.unk34 = (*(f32 *) ((u8 *) &spAD0 + 0x4));
                    spBE0.unk38 = (f32) spAD8;
                    spBE0.unk3C = 1.0f;
                    sp860 = (f64) sp1C0;
                    sp868 = (f64) sp1C8;
                    spA90 = (f64) sp1C0;
                    spA98 = (f64) sp1C8;
                    KDMath_BuildMatrixFromFwd(&spBA0, *((MKVector3 *) &spAA0), (MKVector3 *) &spA90);
                    temp_f0_1249 = spAE0 * var_f15_1157;
                    sp1B0 = temp_f0_1249;
                    sp850 = temp_f0_1249;
                    sp1B8 = (f32) spAE8 * (f32) var_f15_1157;
                    sp858 = (f64) sp1B8;
                    spBA0.Scale3x3(&spBA0, *((MKVector3 *) &sp850));
                    var_r16_1263 = 0;
                    var_r30_1265 = 0;
                    spBA0.unk30 = (f32) spAB0;
                    spBA0.unk34 = (*(f32 *) ((u8 *) &spAB0 + 0x4));
                    spBA0.unk38 = (f32) spAB8;
                    spBA0.unk3C = 1.0f;
loop_39:
                    temp_r19_1274 = &spCA0 + var_r30_1265;
                    ApplyMatrix(sp840, temp_r19_1274);
                    temp_r6_1280 = &spC60 + var_r30_1265;
                    M2C_FIELD(temp_r6_1280, f64 *, 0) = M2C_BITWISE(f64, sp840);
                    M2C_FIELD(temp_r6_1280, f64 *, 8) = (f64) sp840.unk8;
                    ApplyMatrix(sp830, temp_r19_1274);
                    temp_r3_1290 = &spC20 + var_r30_1265;
                    var_r16_1263 += 1;
                    M2C_FIELD(temp_r3_1290, f64 *, 0) = M2C_BITWISE(f64, sp830);
                    var_r30_1265 += 0x10;
                    M2C_FIELD(temp_r3_1290, f64 *, 8) = (f64) sp830.unk8;
                    if (var_r16_1263 < 4) {
                        goto loop_39;
                    }
                    sp460 = 1.0f;
                    sp464 = 1.0f;
                    sp468 = 1.0f;
                    sp46C = 1.0f;
                    spA80 = (f64) sp460;
                    spA88 = (f64) sp468;
                    temp_r0_1306 = this->unk3F78;
                    if (temp_r0_1306 == 1) {
                        MKMaterial_SetMaterial(this->unk3F64);
                    } else if (temp_r0_1306 == 3) {
                        MKMaterial_SetMaterial(this->unk3F6C);
                    }
                    MKPrimitive(0xC, 0);
                    MKSetMatrix(Matrix::identity);
                    MKBegin(0xA);
                    MKSetColorV(*((MKVector4 *) &spA80));
                    MKSetTexCoord1F(0.0f, var_f18_1023);
                    MKSetPositionV(spC60);
                    MKSetColorV(*((MKVector4 *) &spA80));
                    MKSetTexCoord1F(0.0f, var_f17_1045);
                    MKSetPositionV(spC20);
                    MKSetColorV(*((MKVector4 *) &spA80));
                    MKSetTexCoord1F(0.25f, var_f18_1023);
                    MKSetPositionV(spC70);
                    MKSetColorV(*((MKVector4 *) &spA80));
                    MKSetTexCoord1F(0.25f, var_f17_1045);
                    MKSetPositionV(spC30);
                    MKSetColorV(*((MKVector4 *) &spA80));
                    MKSetTexCoord1F(0.5f, var_f18_1023);
                    MKSetPositionV(spC80);
                    MKSetColorV(*((MKVector4 *) &spA80));
                    MKSetTexCoord1F(0.5f, var_f17_1045);
                    MKSetPositionV(spC40);
                    MKSetColorV(*((MKVector4 *) &spA80));
                    MKSetTexCoord1F(0.75f, var_f18_1023);
                    MKSetPositionV(spC90);
                    MKSetColorV(*((MKVector4 *) &spA80));
                    MKSetTexCoord1F(0.75f, var_f17_1045);
                    MKSetPositionV(spC50);
                    MKSetColorV(*((MKVector4 *) &spA80));
                    MKSetTexCoord1F(1.0f, var_f18_1023);
                    MKSetPositionV(spC60);
                    MKSetColorV(*((MKVector4 *) &spA80));
                    MKSetTexCoord1F(1.0f, var_f17_1045);
                    MKSetPositionV(spC20);
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
                        sp450 = temp_f14_1423;
                        sp454 = temp_f14_1423;
                        sp458 = temp_f14_1423;
                        sp45C = 1.0f;
                        sp820 = (f64) sp450;
                        sp828 = (f64) sp458;
                        MKModel_SetColor(this->unk4, *((MKVector4 *) &sp820));
                    } else {
                        sp440 = 1.0f;
                        sp444 = 1.0f;
                        sp448 = 1.0f;
                        sp44C = 1.0f;
                        sp810 = (f64) sp440;
                        sp818 = (f64) sp448;
                        MKModel_SetColor(this->unk4, *((MKVector4 *) &sp810));
                    }
                    if ((s32) this->unk3F78 == 3) {
                        gRenderState = this->unk3F70;
                    }
                    if ((u8) M2C_FIELD(temp_r20_913, u8 *, 0x159) == 0) {
                        M2C_STRUCT_COPY((s32) &spB20.unk3C + 4, MKModel_GetWorldMatrix(this->unk4) - 4 + 4, 0x40);
                        spB60.SetIdentity();
                        sp438 = 0.0f;
                        sp430 = 0.0f;
                        sp434 = 1.0f;
                        spA78 = (f64) sp438;
                        spA70 = (f64) sp430;
                        KDMath_BuildMatrixFromFwd(&spB60, *(temp_r20_913 + 0xD8), (MKVector3 *) &spA70);
                        spA60 = M2C_FIELD(temp_r20_913, f64 *, 0xE8);
                        spA68 = M2C_FIELD(temp_r20_913, f64 *, 0xF0);
                        spA60 = (0.1f * _table_sinf((f32) M2C_FIELD(temp_r20_913, f64 *, 0x108))) + (f32) spA60;
                        (*(f32 *) ((u8 *) &spA48 + 0x1c)) += 0.1f * _table_sinf(M2C_FIELD(temp_r20_913, f32 *, 0x10C));
                        temp_f0_1509 = (0.1f * _table_sinf((f32) M2C_FIELD(temp_r20_913, f64 *, 0x110))) + (f32) spA68;
                        spA68 = temp_f0_1509;
                        temp_f1_1512 = spA60 * 5.271833295e-315;
                        sp1A0 = temp_f1_1512;
                        sp1A8 = temp_f0_1509 * 1.2f;
                        sp800 = temp_f1_1512;
                        sp808 = (f64) sp1A8;
                        spB60.Scale3x3(&spB60, *((MKVector3 *) &sp800));
                        spB60.unk30 = (f32) M2C_FIELD(temp_r20_913, f64 *, 0xC8);
                        spB60.unk34 = M2C_FIELD(temp_r20_913, f32 *, 0xCC);
                        spB60.unk38 = M2C_FIELD(temp_r20_913, f32 *, 0xD0);
                        spB60.unk3C = 1.0f;
                        MKModel_SetWorldMatrix(this->unk4, spB60);
                        MKModel_Draw(this->unk4, NULL);
                    } else {
                        spB20.SetIdentity();
                        sp420 = 0.0f;
                        sp424 = 0.0f;
                        sp428 = 1.0f;
                        sp7F0 = (f64) sp420;
                        sp7F8 = (f64) sp428;
                        KDMath_BuildMatrixFromUp(&spB20, *(temp_r20_913 + 0x128), *((MKVector3 *) &sp7F0));
                        temp_f0_1557 = M2C_FIELD(temp_r20_913, f64 *, 0xE8) * (f64) temp_f14_1423;
                        sp190 = temp_f0_1557;
                        sp7E0 = temp_f0_1557;
                        sp198 = (f32) M2C_FIELD(temp_r20_913, f64 *, 0xF0) * temp_f14_1423;
                        sp7E8 = (f64) sp198;
                        spB20.Scale3x3(&spB20, *((MKVector3 *) &sp7E0));
                        spB20.unk30 = (f32) M2C_FIELD(temp_r20_913, f64 *, 0xC8);
                        spB20.unk34 = M2C_FIELD(temp_r20_913, f32 *, 0xCC);
                        spB20.unk38 = M2C_FIELD(temp_r20_913, f32 *, 0xD0);
                        spB20.unk3C = 1.0f;
                        MKModel_SetWorldMatrix(this->unk4, spB20);
                        MKModel_Draw(this->unk4, NULL);
                    }
                    if ((s32) this->unk3F78 == 3) {
                        gRenderState = NULL;
                    }
                    temp_r18_1596 = &sp1960 + var_r31_731;
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
        sp410 = 1.0f;
        sp414 = 1.0f;
        sp418 = 1.0f;
        sp41C = 1.0f;
        spA50 = (f64) sp410;
        spA58 = (f64) sp418;
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
                        temp_f0_1672 = M2C_FIELD(temp_r14_1650, f64 *, 0xC8) - M2C_FIELD(temp_r3_1665, f64 *, 0xC8);
                        sp400 = temp_f0_1672;
                        sp7D0 = temp_f0_1672;
                        sp408 = M2C_FIELD(temp_r14_1650, f32 *, 0xD0) - M2C_FIELD(temp_r3_1665, f32 *, 0xD0);
                        temp_f1_1683 = 90.0f * M2C_FIELD(temp_r14_1650, f32 *, 0x100);
                        sp7D8 = (f64) sp408;
                        if ((((f32) sp7D8 * (f32) sp7D8) + (((f32) sp7D0 * (f32) sp7D0) + ((*(f32 *) ((u8 *) &sp7D0 + 0x4)) * (*(f32 *) ((u8 *) &sp7D0 + 0x4))))) < (temp_f1_1683 * temp_f1_1683)) {
                            var_r5_1662 = 1;
                        } else {
                            var_r5_1662 = 0;
                        }
                    }
                }
                if (var_r5_1662 != 0) {
                    temp_r4_1705 = this + (var_r4_1657 * 0xA0);
                    temp_f0_1708 = M2C_FIELD(temp_r4_1705, f64 *, 0xC8) - M2C_FIELD(temp_r14_1650, f64 *, 0xC8);
                    sp180 = temp_f0_1708;
                    sp7B0 = temp_f0_1708;
                    sp188 = M2C_FIELD(temp_r4_1705, f32 *, 0xD0) - M2C_FIELD(temp_r14_1650, f32 *, 0xD0);
                    sp7B8 = (f64) sp188;
                    Normalise(sp7C0);
                    spA40 = M2C_BITWISE(f64, sp7C0);
                    spA48 = (f64) sp7C0.unk8;
                } else {
                    Normalise(sp7A0);
                    spA40 = M2C_BITWISE(f64, sp7A0);
                    spA48 = (f64) sp7A0.unk8;
                }
                sp178 = 0.0f;
                sp170 = 0.0f;
                sp174 = 1.0f;
                sp778 = (f64) sp178;
                sp770 = (f64) sp170;
                sp160 = ((*(f32 *) ((u8 *) &sp770 + 0x4)) * (f32) spA48) - ((f32) sp778 * (*(f32 *) ((u8 *) &spA40 + 0x4)));
                sp164 = ((f32) sp778 * (f32) spA40) - ((f32) sp770 * (f32) spA48);
                sp168 = ((f32) sp770 * (*(f32 *) ((u8 *) &spA40 + 0x4))) - ((*(f32 *) ((u8 *) &sp770 + 0x4)) * (f32) spA40);
                sp780 = (f64) sp160;
                sp788 = (f64) sp168;
                Normalise(sp790);
                spA20 = M2C_BITWISE(f64, sp790);
                spA28 = (f64) sp790.unk8;
                var_f8_1779 = M2C_FIELD(temp_r14_1650, f32 *, 0x14C);
                sp158 = ((f32) spA40 * (*(f32 *) ((u8 *) &spA20 + 0x4))) - ((*(f32 *) ((u8 *) &spA40 + 0x4)) * (f32) spA20);
                sp154 = ((f32) spA48 * (f32) spA20) - ((f32) spA40 * (f32) spA28);
                sp150 = ((*(f32 *) ((u8 *) &spA40 + 0x4)) * (f32) spA28) - ((f32) spA48 * (*(f32 *) ((u8 *) &spA20 + 0x4)));
                sp768 = (f64) sp158;
                sp760 = (f64) sp150;
                spA30 = (f64) sp150;
                spA38 = (f64) sp158;
                if (var_f8_1779 < 0.2f) {

                } else {
                    var_f8_1779 = 0.2f;
                }
                if (var_f8_1779 > 0.0f) {

                } else {
                    var_f8_1779 = 0.0f;
                }
                temp_f4_1808 = var_f8_1779 / 0.2f;
                sp3F8 = 35.0f;
                sp3F0 = 40.0f;
                spA50 = temp_f4_1808;
                sp3F4 = 300.0f * temp_f4_1808;
                (*(f32 *) ((u8 *) &spA48 + 0xc)) = temp_f4_1808;
                sp750 = (f64) sp3F0;
                spA58 = temp_f4_1808;
                (*(f32 *) ((u8 *) &spA48 + 0x14)) = 1.0f;
                sp758 = (f64) sp3F8;
                temp_f0_1827 = (f64) sp3F0 * M2C_FIELD(temp_r14_1650, f64 *, 0xE8);
                sp3E0 = temp_f0_1827;
                spA10 = temp_f0_1827;
                sp3E8 = (f32) sp758 * M2C_FIELD(temp_r14_1650, f32 *, 0xF0);
                spA18 = (f64) sp3E8;
                MKBegin(4);
                MKSetColorV(*((MKVector4 *) &spA50));
                MKSetTexCoord1F(0.99f, 0.0f);
                sp3F2C = (f32) spA18;
                sp140 = spA40 * (f64) (f32) (f32) spA18;
                sp3D0 = -(f32) spA20;
                sp3D4 = -(*(f32 *) ((u8 *) &spA20 + 0x4));
                sp148 = (f32) spA48 * (f32) spA18;
                sp3D8 = -(f32) spA28;
                sp3F1C = (f32) spA10;
                sp710 = (f64) sp3D0;
                sp700 = sp140;
                sp708 = (f64) sp148;
                sp718 = (f64) sp3D8;
                sp130 = (f64) sp3D0 * (f64) (f32) spA10;
                temp_r17_1881 = ((u8 *) temp_r14_1650) + 0xC8;
                sp720 = sp130;
                sp138 = (f32) sp718 * (f32) spA10;
                sp728 = (f64) sp138;
                temp_f0_1891 = *temp_r17_1881 + sp130;
                sp3C0 = temp_f0_1891;
                sp730 = temp_f0_1891;
                sp3C8 = M2C_FIELD(temp_r14_1650, f32 *, 0xD0) + (f32) sp728;
                sp738 = (f64) sp3C8;
                temp_f0_1903 = sp730 + sp700;
                sp3B0 = temp_f0_1903;
                sp740 = temp_f0_1903;
                sp3B8 = (f32) sp738 + (f32) sp708;
                sp748 = (f64) sp3B8;
                MKSetPositionV(*((MKVector3 *) &sp740));
                MKSetColorV(*((MKVector4 *) &spA50));
                MKSetTexCoord1F(0.99f, 1.0f);
                sp3F24 = (f32) spA18;
                sp120 = spA40 * (f64) (f32) (f32) spA18;
                sp380 = -(f32) spA30;
                sp384 = -(*(f32 *) ((u8 *) &spA30 + 0x4));
                sp128 = (f32) spA48 * (f32) spA18;
                sp388 = -(f32) spA38;
                sp3F28 = (*(f32 *) ((u8 *) &spA10 + 0x4));
                sp690 = (f64) sp380;
                sp680 = sp120;
                sp688 = (f64) sp128;
                sp698 = (f64) sp388;
                sp110 = (f64) sp380 * (f64) (*(f32 *) ((u8 *) &spA10 + 0x4));
                sp3A0 = -(f32) spA20;
                sp3A4 = -(*(f32 *) ((u8 *) &spA20 + 0x4));
                sp118 = (f32) sp698 * (*(f32 *) ((u8 *) &spA10 + 0x4));
                sp3A8 = -(f32) spA28;
                sp3F18 = (f32) spA10;
                sp6B0 = (f64) sp3A0;
                sp6A0 = sp110;
                sp6A8 = (f64) sp118;
                sp6B8 = (f64) sp3A8;
                sp100 = (f64) sp3A0 * (f64) (f32) spA10;
                sp6C0 = sp100;
                sp108 = (f32) sp6B8 * (f32) spA10;
                sp6C8 = (f64) sp108;
                temp_f0_1994 = *temp_r17_1881 + sp100;
                sp390 = temp_f0_1994;
                sp6D0 = temp_f0_1994;
                sp398 = M2C_FIELD(temp_r14_1650, f32 *, 0xD0) + (f32) sp6C8;
                sp6D8 = (f64) sp398;
                temp_f0_2006 = sp6D0 + sp6A0;
                sp370 = temp_f0_2006;
                sp6E0 = temp_f0_2006;
                sp378 = (f32) sp6D8 + (f32) sp6A8;
                sp6E8 = (f64) sp378;
                temp_f0_2018 = sp6E0 + sp680;
                sp360 = temp_f0_2018;
                sp6F0 = temp_f0_2018;
                sp368 = (f32) sp6E8 + (f32) sp688;
                sp6F8 = (f64) sp368;
                MKSetPositionV(*((MKVector3 *) &sp6F0));
                MKSetColorV(*((MKVector4 *) &spA50));
                MKSetTexCoord1F(0.0f, 0.0f);
                sp350 = -(f32) spA40;
                sp3F20 = (f32) spA18;
                sp354 = -(*(f32 *) ((u8 *) &spA40 + 0x4));
                sp358 = -(f32) spA48;
                sp650 = (f64) sp350;
                sp658 = (f64) sp358;
                temp_f1_2053 = (f64) sp350 * (f64) (f32) spA18;
                spF0 = temp_f1_2053;
                sp660 = temp_f1_2053;
                spF8 = (f32) sp658 * (f32) spA18;
                sp668 = (f64) spF8;
                temp_f0_2064 = *temp_r17_1881 + sp660;
                sp340 = temp_f0_2064;
                sp670 = temp_f0_2064;
                sp348 = M2C_FIELD(temp_r14_1650, f32 *, 0xD0) + (f32) sp668;
                sp678 = (f64) sp348;
                MKSetPositionV(*((MKVector3 *) &sp670));
                MKSetColorV(*((MKVector4 *) &spA50));
                MKSetTexCoord1F(0.0f, 1.0f);
                sp310 = -(f32) spA40;
                sp314 = -(*(f32 *) ((u8 *) &spA40 + 0x4));
                sp318 = -(f32) spA48;
                sp5F0 = (f64) sp310;
                sp5F8 = (f64) sp318;
                spE0 = sp5F0 * (f64) (f32) spA18;
                sp330 = -(f32) spA30;
                sp334 = -(*(f32 *) ((u8 *) &spA30 + 0x4));
                spE8 = (f32) sp5F8 * (f32) spA18;
                sp338 = -(f32) spA38;
                sp610 = (f64) sp330;
                sp600 = spE0;
                sp608 = (f64) spE8;
                sp618 = (f64) sp338;
                temp_f0_2120 = sp610 * (f64) (*(f32 *) ((u8 *) &spA10 + 0x4));
                spD0 = temp_f0_2120;
                sp620 = temp_f0_2120;
                spD8 = (f32) sp618 * (*(f32 *) ((u8 *) &spA10 + 0x4));
                sp628 = (f64) spD8;
                temp_f0_2131 = *temp_r17_1881 + temp_f0_2120;
                sp320 = temp_f0_2131;
                sp630 = temp_f0_2131;
                sp328 = M2C_FIELD(temp_r14_1650, f32 *, 0xD0) + (f32) sp628;
                sp638 = (f64) sp328;
                temp_f0_2143 = sp630 + sp600;
                sp300 = temp_f0_2143;
                sp640 = temp_f0_2143;
                sp308 = (f32) sp638 + (f32) sp608;
                sp648 = (f64) sp308;
                MKSetPositionV(*((MKVector3 *) &sp640));
                MKEnd();
                MKBegin(4);
                MKSetColorV(*((MKVector4 *) &spA50));
                MKSetTexCoord1F(0.0f, 0.0f);
                sp2F0 = -(f32) spA40;
                sp2F4 = -(*(f32 *) ((u8 *) &spA40 + 0x4));
                sp2F8 = -(f32) spA48;
                sp5C0 = (f64) sp2F0;
                sp5C8 = (f64) sp2F8;
                temp_f0_2178 = sp5C0 * (f64) (f32) spA18;
                spC0 = temp_f0_2178;
                sp5D0 = temp_f0_2178;
                spC8 = (f32) sp5C8 * (f32) spA18;
                sp5D8 = (f64) spC8;
                temp_f0_2189 = *temp_r17_1881 + temp_f0_2178;
                sp2E0 = temp_f0_2189;
                sp5E0 = temp_f0_2189;
                sp2E8 = M2C_FIELD(temp_r14_1650, f32 *, 0xD0) + (f32) sp5D8;
                sp5E8 = (f64) sp2E8;
                MKSetPositionV(*((MKVector3 *) &sp5E0));
                MKSetColorV(*((MKVector4 *) &spA50));
                MKSetTexCoord1F(0.0f, 1.0f);
                sp2B0 = -(f32) spA40;
                sp2B4 = -(*(f32 *) ((u8 *) &spA40 + 0x4));
                sp2B8 = -(f32) spA48;
                sp560 = (f64) sp2B0;
                sp568 = (f64) sp2B8;
                spB0 = sp560 * (f64) (f32) spA18;
                sp2D0 = -(f32) spA30;
                sp2D4 = -(*(f32 *) ((u8 *) &spA30 + 0x4));
                spB8 = (f32) sp568 * (f32) spA18;
                sp2D8 = -(f32) spA38;
                sp580 = (f64) sp2D0;
                sp570 = spB0;
                sp578 = (f64) spB8;
                sp588 = (f64) sp2D8;
                temp_f0_2245 = sp580 * (f64) (*(f32 *) ((u8 *) &spA10 + 0x4));
                spA0 = temp_f0_2245;
                sp590 = temp_f0_2245;
                spA8 = (f32) sp588 * (*(f32 *) ((u8 *) &spA10 + 0x4));
                sp598 = (f64) spA8;
                temp_f0_2256 = *temp_r17_1881 + temp_f0_2245;
                sp2C0 = temp_f0_2256;
                sp5A0 = temp_f0_2256;
                sp2C8 = M2C_FIELD(temp_r14_1650, f32 *, 0xD0) + (f32) sp598;
                sp5A8 = (f64) sp2C8;
                temp_f0_2268 = sp5A0 + sp570;
                sp2A0 = temp_f0_2268;
                sp5B0 = temp_f0_2268;
                sp2A8 = (f32) sp5A8 + (f32) sp578;
                sp5B8 = (f64) sp2A8;
                MKSetPositionV(*((MKVector3 *) &sp5B0));
                MKSetColorV(*((MKVector4 *) &spA50));
                MKSetTexCoord1F(0.99f, 0.0f);
                sp90 = spA40 * (f64) (f32) spA18;
                sp98 = (f32) spA48 * (f32) spA18;
                sp3F14 = (f32) spA10;
                sp520 = sp90;
                sp528 = (f64) sp98;
                sp80 = spA20 * (f64) (f32) spA10;
                sp530 = sp80;
                sp88 = (f32) spA28 * (f32) spA10;
                sp538 = (f64) sp88;
                temp_f0_2315 = *temp_r17_1881 + sp80;
                sp290 = temp_f0_2315;
                sp540 = temp_f0_2315;
                sp298 = M2C_FIELD(temp_r14_1650, f32 *, 0xD0) + (f32) sp538;
                sp548 = (f64) sp298;
                temp_f0_2327 = sp540 + sp520;
                sp280 = temp_f0_2327;
                sp550 = temp_f0_2327;
                sp288 = (f32) sp548 + (f32) sp528;
                sp558 = (f64) sp288;
                MKSetPositionV(*((MKVector3 *) &sp550));
                MKSetColorV(*((MKVector4 *) &spA50));
                MKSetTexCoord1F(0.99f, 1.0f);
                sp70 = spA40 * (f64) (f32) spA18;
                sp260 = -(f32) spA30;
                sp264 = -(*(f32 *) ((u8 *) &spA30 + 0x4));
                sp78 = (f32) spA48 * (f32) spA18;
                sp268 = -(f32) spA38;
                sp4C0 = (f64) sp260;
                sp4B0 = sp70;
                sp4B8 = (f64) sp78;
                sp4C8 = (f64) sp268;
                sp60 = sp4C0 * (f64) (*(f32 *) ((u8 *) &spA10 + 0x4));
                sp4D0 = sp60;
                sp68 = (f32) sp4C8 * (*(f32 *) ((u8 *) &spA10 + 0x4));
                sp3F10 = (f32) spA10;
                sp4D8 = (f64) sp68;
                sp50 = spA20 * (f64) (f32) spA10;
                sp4E0 = sp50;
                sp58 = (f32) spA28 * (f32) spA10;
                sp4E8 = (f64) sp58;
                temp_f0_2398 = *temp_r17_1881 + sp50;
                sp270 = temp_f0_2398;
                sp4F0 = temp_f0_2398;
                sp278 = M2C_FIELD(temp_r14_1650, f32 *, 0xD0) + (f32) sp4E8;
                sp4F8 = (f64) sp278;
                temp_f0_2410 = sp4F0 + sp4D0;
                sp250 = temp_f0_2410;
                sp500 = temp_f0_2410;
                sp258 = (f32) sp4F8 + (f32) sp4D8;
                sp508 = (f64) sp258;
                temp_f0_2422 = sp500 + sp4B0;
                sp240 = temp_f0_2422;
                sp510 = temp_f0_2422;
                sp248 = (f32) sp508 + (f32) sp4B8;
                sp518 = (f64) sp248;
                MKSetPositionV(*((MKVector3 *) &sp510));
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
    u8 sp360;
    s32 sp35C;
    void *sp358;
    s32 sp354;
    f32 sp350;
    s32 sp34C;
    s8 sp34B;
    s8 sp34A;
    s16 sp348;
    f32 sp344;
    f32 sp340;
    f32 sp33C;
    f32 sp338;
    f32 sp334;
    f32 sp330;
    f32 sp328;
    f32 sp324;
    f32 sp320;
    f32 sp318;
    f32 sp314;
    f32 sp310;
    Matrix sp2D0;
    M2C_UNK sp2CC;
    f64 sp2C0;
    f64 sp2B8;
    f64 sp2B0;
    f64 sp2A8;
    f64 sp2A0;
    f64 sp298;
    f64 sp288;
    f64 sp280;
    f64 sp278;
    f64 sp270;
    f64 sp268;
    f64 sp260;
    f64 sp258;
    MKVector3 sp248;
    f64 sp240;
    f64 sp238;
    f64 sp230;
    f64 sp228;
    f64 sp220;
    f64 sp218;
    f64 sp210;
    f64 sp208;
    MKVector3 sp1F8;
    f64 sp1F0;
    f64 sp1E8;
    f64 sp1E0;
    f64 sp1D8;
    f64 sp1D0;
    f64 sp1C8;
    f64 sp1C0;
    f64 sp1B8;
    f64 sp1B0;
    f64 sp1A8;
    f64 sp1A0;
    f64 sp198;
    f64 sp190;
    f64 sp188;
    f64 sp180;
    f64 sp178;
    f64 sp170;
    f64 sp168;
    f64 sp160;
    f64 sp158;
    f32 sp150;
    f32 sp14C;
    f32 sp148;
    f32 sp140;
    f32 sp13C;
    f32 sp138;
    f32 sp130;
    f32 sp12C;
    f32 sp128;
    f32 sp120;
    f32 sp11C;
    f32 sp118;
    f32 sp110;
    f64 sp108;
    f32 sp104;
    f32 sp100;
    f32 spFC;
    f32 spF8;
    f32 spF0;
    f64 spE8;
    f32 spE0;
    f64 spD8;
    f32 spD0;
    f64 spC8;
    f32 spC0;
    f64 spB8;
    f32 spB4;
    f32 spB0;
    f32 spAC;
    f32 spA8;
    f32 spA4;
    f32 spA0;
    f32 sp9C;
    f32 sp98;
    f32 sp90;
    f32 sp8C;
    f32 sp88;
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp50;
    f64 sp48;
    f32 sp40;
    f64 sp38;
    MKVector3 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
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
    f64 *temp_r0_2783;
    f64 *temp_r0_3482;
    f64 *temp_r26_2736;
    f64 temp_f0_2734;
    f64 temp_f0_2760;
    f64 temp_f0_2781;
    f64 temp_f0_3448;
    f64 temp_f0_3480;
    f64 temp_f0_3734;
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
    void *temp_r25_2748;
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
        if ((this->unk3F88 <= 0.0f) || (EventCamera_GetCurrent() != NULL)) {
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
                    temp_f0_2734 = sp288 * (f64) temp_f29_2729;
                    spE8 = temp_f0_2734;
                    temp_r26_2736 = ((u8 *) temp_r27_2717) + 0xD8;
                    sp298 = temp_f0_2734;
                    spF0 = sp290 * temp_f29_2729;
                    sp2A0 = (f64) spF0;
                    *temp_r26_2736 += temp_f0_2734;
                    temp_r25_2748 = ((u8 *) temp_r27_2717) + 0xC8;
                    M2C_FIELD(temp_r27_2717, f32 *, 0xE0) = (f32) (M2C_FIELD(temp_r27_2717, f32 *, 0xE0) + (f32) sp2A0);
                    sp2B8 = M2C_FIELD(temp_r27_2717, f64 *, 0xC8);
                    sp2C0 = M2C_FIELD(temp_r27_2717, f64 *, 0xD0);
                    temp_f0_2760 = *temp_r26_2736 * (f64) gUpdateTimeDelta;
                    spD8 = temp_f0_2760;
                    sp278 = temp_f0_2760;
                    spE0 = M2C_FIELD(temp_r27_2717, f32 *, 0xE0) * gUpdateTimeDelta;
                    sp280 = (f64) spE0;
                    M2C_FIELD(temp_r25_2748, f64 *, 0) = (f64) (M2C_FIELD(temp_r25_2748, f64 *, 0) + temp_f0_2760);
                    M2C_FIELD(temp_r27_2717, f64 *, 0xD0) = (f32) ((f32) M2C_FIELD(temp_r27_2717, f64 *, 0xD0) + (f32) sp280);
                    temp_f0_2781 = M2C_FIELD(temp_r27_2717, f64 *, 0x118) * (f64) gUpdateTimeDelta;
                    spC8 = temp_f0_2781;
                    temp_r0_2783 = ((u8 *) temp_r27_2717) + 0x108;
                    sp268 = temp_f0_2781;
                    spD0 = M2C_FIELD(temp_r27_2717, f32 *, 0x120) * gUpdateTimeDelta;
                    sp270 = (f64) spD0;
                    *temp_r0_2783 += temp_f0_2781;
                    M2C_FIELD(temp_r27_2717, f32 *, 0x110) = (f32) (M2C_FIELD(temp_r27_2717, f32 *, 0x110) + (f32) sp270);
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
                        sp18 = var_f4_2807;
                        temp_r3_2839 = M2C_BITWISE(s32, sp18) & 0x7F800000;
                        switch (temp_r3_2839) {     /* switch 1; irregular */
                        case 0x7F800000:            /* switch 1 */
                            if (M2C_BITWISE(s32, sp18) & 0x7FFFFF) {
                                var_r0_2849 = 1;
                            } else {
                                var_r0_2849 = 2;
                            }
                            break;
                        case 0x0:                   /* switch 1 */
                            if (M2C_BITWISE(s32, sp18) & 0x7FFFFF) {
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
                    temp_r24_2994 = ((u8 *) temp_r27_2717) + 0xC8;
                    temp_f4_3003 = (var_f6_2986 * (var_f5_2966 - temp_f4_2993)) + temp_f4_2993;
                    M2C_FIELD(temp_r27_2717, f32 *, 0xF0) = (f32) ((var_f6_2986 * (var_f5_2966 - temp_f4_3003)) + temp_f4_3003);
                    sp310 = 0.0f;
                    sp314 = 0.0f;
                    sp318 = 0.0f;
                    sp320 = 0.0f;
                    sp324 = 0.0f;
                    sp328 = 0.0f;
                    sp330 = 0.0f;
                    sp334 = 0.0f;
                    sp338 = 0.0f;
                    sp33C = 1.0f;
                    sp340 = 0.0f;
                    sp344 = 0.0f;
                    sp348 = 0;
                    sp34A = 0;
                    sp34B = 0;
                    sp34C = 0;
                    sp350 = 3.4028235e38f;
                    sp354 = 0;
                    sp358 = NULL;
                    sp35C = -1;
                    sp360 = 0;
                    if (MKCollision_RayCollide(*((MKVector3 *) &sp2B8), *temp_r24_2994, (MKCollisionResult *) &sp310, (MKCollisionMode) 7, 0) != 0) {
                        M2C_FIELD(temp_r27_2717, u8 *, 0x159) = 1U;
                        M2C_FIELD(temp_r27_2717, f64 *, 0x128) = (f64) sp320;
                        M2C_FIELD(temp_r27_2717, f64 *, 0x130) = (f64) sp328;
                        if ((sp360 != 0) && (sp358 != NULL) && (var_r3_3046 = M2C_FIELD(sp358, void **, 8), ((var_r3_3046 == NULL) == 0))) {

                        } else {
                            var_r3_3046 = NULL;
                        }
                        temp_r4_3053 = this->unk3F80;
                        if ((temp_r4_3053 != NULL) && (var_r3_3046 != NULL)) {
                            M2C_FIELD(temp_r4_3053, f64 *, 0x10) = (f64) sp310;
                            M2C_FIELD(temp_r4_3053, f64 *, 0x18) = (f64) sp318;
                            M2C_FIELD(M2C_FIELD(var_r3_3046, void **, 0x44), M2C_UNK (**)(BreathHitMessage *, f64), 0x2C)(this->unk3F80, (f64) sp310);
                        }
                        M2C_FIELD(temp_r27_2717, f64 *, 0xC8) = (f64) sp310;
                        M2C_FIELD(temp_r25_2748, f64 *, 8) = (f64) sp318;
                        M2C_FIELD(temp_r27_2717, f32 *, 0x154) = sp314;
                        M2C_FIELD(temp_r27_2717, f64 *, 0x128) = (f64) sp320;
                        M2C_FIELD(temp_r27_2717, f64 *, 0x130) = (f64) sp328;
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
                            sp14 = var_f4_3086;
                            temp_r3_3118 = M2C_BITWISE(s32, sp14) & 0x7F800000;
                            switch (temp_r3_3118) { /* switch 2; irregular */
                            case 0x7F800000:        /* switch 2 */
                                if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                                    var_r0_3128 = 1;
                                } else {
                                    var_r0_3128 = 2;
                                }
                                break;
                            case 0x0:               /* switch 2 */
                                if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
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
                            sp248.operator*(100.0f);
                            spB8 = (f64) sp310 + M2C_BITWISE(f64, sp248);
                            temp_r3_3178 = this->unk3F84;
                            sp258 = spB8;
                            spC0 = sp318 + sp248.unk8;
                            temp_r3_3178->unk10 = spB8;
                            temp_r3_3178->unk18 = (f64) spC0;
                            temp_r3_3184 = temp_r3_3178->unk3C;
                            sp260 = (f64) spC0;
                            if (temp_r3_3184 != NULL) {
                                M2C_FIELD(temp_r3_3184, f64 *, 0x10) = spB8;
                                M2C_FIELD(temp_r3_3184, f64 *, 0x18) = (f64) spC0;
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
                                spA8 = 1.0f;
                                temp_r3_3214 = this->unk3F84;
                                spAC = 0.7f;
                                spB0 = 0.1f;
                                spB4 = 1.0f;
                                temp_r3_3214->unk20 = (f64) spA8;
                                temp_r3_3214->unk28 = (f64) spB0;
                                temp_r3_3222 = temp_r3_3214->unk3C;
                                sp238 = (f64) spA8;
                                sp240 = (f64) spB0;
                                if (temp_r3_3222 != NULL) {
                                    M2C_FIELD(temp_r3_3222, f64 *, 0) = (f64) spA8;
                                    M2C_FIELD(temp_r3_3222, f64 *, 8) = (f64) spB0;
                                }
                            } else if (temp_r0_3207 == 3) {
                                sp98 = 0.125f;
                                temp_r3_3236 = this->unk3F84;
                                sp9C = 0.125f;
                                spA0 = 1.0f;
                                spA4 = 1.0f;
                                temp_r3_3236->unk20 = (f64) sp98;
                                temp_r3_3236->unk28 = (f64) spA0;
                                temp_r3_3244 = temp_r3_3236->unk3C;
                                sp228 = (f64) sp98;
                                sp230 = (f64) spA0;
                                if (temp_r3_3244 != NULL) {
                                    M2C_FIELD(temp_r3_3244, f64 *, 0) = (f64) sp98;
                                    M2C_FIELD(temp_r3_3244, f64 *, 8) = (f64) spA0;
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
                        temp_r24_3267 = ((u8 *) temp_r27_2717) + 0x138;
                        M2C_FIELD(temp_r27_2717, f32 *, 0x138) = 0.0f;
                        M2C_FIELD(temp_r27_2717, f32 *, 0x13C) = 0.0f;
                        M2C_FIELD(temp_r27_2717, f32 *, 0x140) = 0.0f;
                        if ((sp360 != 0) && (sp358 != NULL) && (var_r0_3277 = M2C_FIELD(sp358, void **, 8), ((var_r0_3277 == NULL) == 0))) {

                        } else {
                            var_r0_3277 = NULL;
                        }
                        if (var_r0_3277 != NULL) {
                            var_f0_3286 = 0.0f;
                            sp88 = 0.0f;
                            sp8C = 1.0f;
                            sp90 = 0.0f;
                            M2C_FIELD(temp_r27_2717, f32 *, 0x138) = (f64) sp88;
                            M2C_FIELD(temp_r24_3267, f64 *, 8) = (f64) sp90;
                            temp_f3_3297 = M2C_FIELD(temp_r27_2717, f32 *, 0x138);
                            temp_f4_3298 = M2C_FIELD(temp_r27_2717, f32 *, 0x140);
                            temp_f9_3302 = M2C_FIELD(temp_r27_2717, f32 *, 0x13C);
                            sp218 = (f64) sp88;
                            sp220 = (f64) sp90;
                            sp14C = (temp_f4_3298 * sp320) - (temp_f3_3297 * sp328);
                            sp148 = (temp_f9_3302 * sp328) - (temp_f4_3298 * sp324);
                            sp150 = (temp_f3_3297 * sp324) - (temp_f9_3302 * sp320);
                            sp208 = (f64) sp148;
                            sp210 = (f64) sp150;
                            var_f4_3324 = ((f32) sp210 * (f32) sp210) + (((f32) sp208 * (f32) sp208) + ((*(f32 *) ((u8 *) &sp208 + 0x4)) * (*(f32 *) ((u8 *) &sp208 + 0x4))));
                            if (var_f4_3324 > 1e-12f) {
                                if (var_f4_3324 > 0.0f) {
                                    temp_f1_3329 = __frsqrte(var_f4_3324);
                                    temp_f1_3335 = 0.5 * temp_f1_3329 * -(((f64) var_f4_3324 * (temp_f1_3329 * temp_f1_3329)) - 3.0);
                                    temp_f1_3339 = 0.5 * temp_f1_3335 * -(((f64) var_f4_3324 * (temp_f1_3335 * temp_f1_3335)) - 3.0);
                                    var_f4_3324 = (f32) ((f64) var_f4_3324 * (0.5 * temp_f1_3339 * -(((f64) var_f4_3324 * (temp_f1_3339 * temp_f1_3339)) - 3.0)));
                                } else if (var_f4_3324 < M2C_BITWISE(f32, 0.0)) {
                                    var_f4_3324 = __float_nan;
                                } else {
                                    sp10 = var_f4_3324;
                                    temp_r3_3358 = M2C_BITWISE(s32, sp10) & 0x7F800000;
                                    switch (temp_r3_3358) { /* switch 3; irregular */
                                    case 0x7F800000: /* switch 3 */
                                        if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                                            var_r0_3368 = 1;
                                        } else {
                                            var_r0_3368 = 2;
                                        }
                                        break;
                                    case 0x0:       /* switch 3 */
                                        if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
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
                            sp138 = (f32) sp208 * var_f0_3286;
                            sp13C = (*(f32 *) ((u8 *) &sp208 + 0x4)) * var_f0_3286;
                            sp140 = (f32) sp210 * var_f0_3286;
                            sp2A8 = (f64) sp138;
                            sp2B0 = (f64) sp140;
                            sp60 = 0.0f;
                            sp58 = 0.0f;
                            sp78 = (sp324 * (f32) sp2B0) - (sp328 * (*(f32 *) ((u8 *) &sp2A8 + 0x4)));
                            sp7C = (sp328 * (f32) sp2A8) - (sp320 * (f32) sp2B0);
                            sp80 = (sp320 * (*(f32 *) ((u8 *) &sp2A8 + 0x4))) - (sp324 * (f32) sp2A8);
                            sp1C8 = (f64) sp78;
                            sp1D0 = (f64) sp80;
                            sp5C = -1.0f;
                            sp68 = -(f32) sp1C8;
                            sp6C = -(*(f32 *) ((u8 *) &sp1C8 + 0x4));
                            sp70 = -(f32) sp1D0;
                            sp1B8 = (f64) sp58;
                            sp1D8 = (f64) sp68;
                            sp1C0 = (f64) sp60;
                            sp1E0 = (f64) sp70;
                            temp_f0_3448 = (f64) sp68 + sp1B8;
                            sp48 = temp_f0_3448;
                            sp1E8 = temp_f0_3448;
                            sp50 = (f32) sp1E0 + (f32) sp1C0;
                            sp1F0 = (f64) sp50;
                            Normalise(sp1F8);
                            M2C_FIELD(temp_r27_2717, f32 *, 0x138) = M2C_BITWISE(f64, sp1F8);
                            M2C_FIELD(temp_r24_3267, f64 *, 8) = (f64) sp1F8.unk8;
                            M2C_FIELD(temp_r24_3267, f64 *, 0) = (f64) (M2C_FIELD(temp_r24_3267, f64 *, 0) * 5.67443485e-315);
                            M2C_FIELD(temp_r27_2717, f32 *, 0x140) = (f32) (M2C_FIELD(temp_r27_2717, f32 *, 0x140) * 980.0f);
                        }
                    }
                }
                if ((u8) M2C_FIELD(temp_r27_2717, u8 *, 0x159) != 0) {
                    temp_f0_3480 = (f64) M2C_FIELD(temp_r27_2717, f32 *, 0x138) * (f64) gUpdateTimeDelta;
                    sp38 = temp_f0_3480;
                    temp_r0_3482 = ((u8 *) temp_r27_2717) + 0xC8;
                    sp1A8 = temp_f0_3480;
                    sp40 = M2C_FIELD(temp_r27_2717, f32 *, 0x140) * gUpdateTimeDelta;
                    sp1B0 = (f64) sp40;
                    *temp_r0_3482 += temp_f0_3480;
                    M2C_FIELD(temp_r27_2717, f64 *, 0xD0) = (f32) ((f32) M2C_FIELD(temp_r27_2717, f64 *, 0xD0) + (f32) sp1B0);
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
                if ((M2C_FIELD(temp_r27_2717, f32 *, 0x14C) >= M2C_FIELD(temp_r27_2717, f32 *, 0x150)) || (EventCamera_GetCurrent() != NULL)) {
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
                            sp12C = MKRand_Float(&gViewSeed, 400.0f, 600.0f);
                            sp128 = 0.0f;
                            sp130 = 0.0f;
                            sp198 = (f64) sp128;
                            sp1A0 = (f64) sp130;
                            ((HeatDistortPS *) (&gb + 0x240))->Emit(*(temp_r27_2717 + 0xC8), *((MKVector3 *) &sp198), temp_f24_3670, 1.0f);
                        }
                        if (M2C_FIELD(temp_r27_2717, f32 *, 0x160) >= MKRand_Float(&gViewSeed, 0.01f, 0.135f)) {
                            M2C_FIELD(temp_r27_2717, f32 *, 0x160) = 0.0f;
                        }
                        temp_r24_3701 = ((u8 *) temp_r27_2717) + 0xC8;
                        if ((temp_r24_3701->IsWithin(sp24, &sp20, M2C_ERROR(/* Read from unset register $r6 */)) != 0) && (M2C_BITWISE(s32, sp20) == 0)) {
                            temp_f24_3715 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                            temp_f25_3720 = MKRand_Float(&gViewSeed, 0.0f, 1.0f);
                            sp118 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                            sp11C = temp_f25_3720;
                            sp120 = temp_f24_3715;
                            sp178 = (f64) sp118;
                            sp180 = (f64) sp120;
                            temp_f0_3734 = sp178 * 5.5769738e-315;
                            sp108 = temp_f0_3734;
                            sp188 = temp_f0_3734;
                            sp110 = (f32) sp180 * 200.0f;
                            sp190 = (f64) sp110;
                            sp1C = MKRand_Float(&gViewSeed, 5.0f, 10.0f);
                            spF8 = 1.0f;
                            spFC = 1.0f;
                            sp100 = 1.0f;
                            sp104 = 1.0f;
                            sp168 = (f64) spF8;
                            sp170 = (f64) sp100;
                            ((CrashMistPS *) (M2C_FIELD(temp_r30_2661, CrashMistPS **, 0xE4)))->Emit(*((MKVector3 *) temp_r24_3701), *((MKVector3 *) &sp188), sp1C, 0.1f, *((MKVector4 *) &sp168), 1.0f);
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
        if (temp_f0_3784 >= 5.0f) {
            this->unk3F7C = temp_f0_3784 - 5.0f;
        }
        M2C_STRUCT_COPY((s32) &sp2CC + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
        sp2D0.Scale3x3(&sp2D0, 4.0f);
        sp24.unkC = 0.0f;
        sp24.unk4 = 0.0f;
        sp24.unk8 = -this->unk3F7C;
        sp160 = (f64) sp24.unkC;
        sp158 = (f64) sp24.unk4;
        sp2D0.unk30 = (f32) sp158;
        sp2D0.unk34 = (*(f32 *) ((u8 *) &sp158 + 0x4));
        sp2D0.unk38 = (f32) sp160;
        sp2D0.unk3C = 1.0f;
        MKMaterial_SetTextureMatrix(this->unk3F6C, &sp2D0);
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
    ((KDSpline *) &this->unk3F48)->Init(0x64, 0U);
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

#if 0 // DRAFT: illegal implicit conversion from 'CrashMistPS *' to
void LiquidFXDescriptor::LoadDone() {
    GamePropDescriptor::LoadDone();
    this->unkE4 = checked_cast<CrashMistPS *, MKProp>(gMK->CreateProp("CrashMistPS"));
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'LiquidFXDescriptor *' to
void LiquidFXDescriptor::Deinit() {
    LiquidFXDescriptor *temp_r3_4028;
    LiquidFXDescriptor *temp_r3_4034;

    KDPropExDescriptor::Deinit();
    if ((LiquidFXDescriptor *) *LiquidFXDescriptor::pFirstDesc == this) {
        *LiquidFXDescriptor::pFirstDesc = this->unkF0;
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

#if 0 // DRAFT: illegal implicit conversion from 'unsigned char' to
void LiquidFXDescriptor::Init() {
    GamePropDescriptor::Init();
    this->unkF0 = *LiquidFXDescriptor::pFirstDesc;
    this->unkEC = NULL;
    if ((LiquidFXDescriptor *) *LiquidFXDescriptor::pFirstDesc != NULL) {
        (*LiquidFXDescriptor::pFirstDesc)->unkEC = this;
    }
    *LiquidFXDescriptor::pFirstDesc = this;
    this->unkE8 = gMK->GetWorkingChunk();
}
#endif
