#include "spyro/source/FlameBreathFX.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "spyro/source/BaseBreathFX.h"
#include "spyro/source/Character.h"
#include "spyro/source/Coronas.h"
#include "spyro/source/CynderBreathFX.h"
#include "spyro/source/ElectricSparks.h"
#include "spyro/source/FireBombFX.h"
#include "spyro/source/FlameBreathPS.h"
#include "spyro/source/FuryFXFire.h"
#include "spyro/source/FuryFXFire2.h"
#include "spyro/source/GameData.h"
#include "spyro/source/GameMessages.h"
#include "spyro/source/KDInput.h"
#include "spyro/source/LightManager.h"
#include "spyro/source/ManagedLight.h"
#include "spyro/source/TargetManager.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "common/Source/StdMath.h"
#include "spyro/source/EventCamera.h"
#include "spyro/source/KDRandom.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/Tools.h"
#include <m2c_macros.h>

f64 ceil(f32);                                      /* extern */
extern s32 GS_SpyBreathFireball;
extern s32 GS_SpyBreathFireball2;
extern s32 GS_SpyBreathFireball3;
extern s32 GS_SpyBreathFireball4;
extern s32 GS_SpyroOutOfBreath;
extern void **gMK;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern M2C_UNK gb;
static BreathHitMessage streamHitMsg;

static s32 lit_734 = 0;
static u8 lit_735 = 1;

static s32 lit_737 = 1;
static u8 lit_738 = 0;

void FlameBreathFX::ResetFury() {
    this->unk260->ResetFury();
    this->unk260->ResetFury();
}

#if 0 // DRAFT: illegal implicit conversion from 'float' to
void FlameBreathFX::GetAttack1UpgradeVariables(int arg0, float &arg1, float &arg2, float &arg3) {
    switch (arg0) {                                 /* irregular */
    case 0:
        &arg1 = 0.3f;
        &arg2 = 500.0f;
        &arg3 = 1.0f;
        return;
    case 1:
        &arg1 = 0.75f;
        &arg2 = 700.0f;
        &arg3 = 1.2f;
        return;
    case 2:
        &arg1 = 1.0f;
        &arg2 = 900.0f;
        &arg3 = 1.4f;
        return;
    case 3:
        &arg1 = 1.2f;
        &arg2 = 1000.0f;
        &arg3 = 1.6f;
        return;
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'float' to
u8 FlameBreathFX::ShootFireBomb(const MKVector3 &arg0, const MKVector3 &arg1, const MKVector3 &arg2, bool arg3) {
    s8 sp320;
    s32 sp31C;
    s32 sp318;
    s32 sp314;
    f32 sp310;
    s32 sp30C;
    s8 sp30B;
    s8 sp30A;
    s16 sp308;
    f32 sp304;
    f32 sp300;
    f32 sp2FC;
    f32 sp2F8;
    f32 sp2F4;
    f32 sp2F0;
    f32 sp2E8;
    f32 sp2E4;
    f32 sp2E0;
    f32 sp2D8;
    f32 sp2D4;
    f32 sp2D0;
    s8 sp2C8;
    f64 sp2C0;
    f64 sp2B8;
    s32 sp2B4;
    s32 sp2B0;
    f64 sp2A8;                                      /* compiler-managed */
    f64 sp2A0;                                      /* compiler-managed */
    f64 sp298;
    f64 sp290;
    M2C_UNK sp280;
    f64 sp278;
    f64 sp270;
    f64 sp268;
    f64 sp260;
    f64 sp258;
    f64 sp250;
    f64 sp240;
    f64 sp238;
    f64 sp230;
    MKVector3 sp220;
    f64 sp218;
    f64 sp210;
    f64 sp208;
    f64 sp200;
    f64 sp1F8;
    f64 sp1F0;
    f64 sp1E8;
    f64 sp1E0;
    f64 sp1D8;
    f64 sp1D0;
    MKVector3 sp1C0;
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
    f64 sp150;
    f64 sp148;
    f64 sp140;
    MKVector3 sp130;
    f64 sp120;
    f32 sp118;
    f64 sp110;
    f32 sp108;
    f64 sp100;
    f32 spF8;
    f64 spF0;
    f32 spE8;
    f32 spE4;
    f32 spE0;
    f32 spD8;
    f64 spD0;
    f32 spC8;
    f32 spC4;
    f32 spC0;
    f32 spB8;
    f64 spB0;
    f32 spA8;
    f64 spA0;
    f32 sp98;
    f32 sp94;
    f32 sp90;
    f32 sp88;
    f32 sp84;
    f32 sp80;
    f32 sp78;
    f64 sp70;
    f32 sp68;
    f64 sp60;
    f32 sp58;
    f64 sp50;
    f32 sp48;
    f64 sp40;
    f32 sp38;
    f64 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    f32 sp8;
    FireBombFX *temp_r3_141;
    ManagedLight *temp_r3_825;
    ManagedLight *temp_r4_788;
    TargetManager ***var_r22_264;
    TargetManager **temp_r27_461;
    TargetManager **var_r23_261;
    f32 temp_f1_617;
    f32 temp_f25_707;
    f32 temp_f26_718;
    f32 temp_f27_713;
    f32 temp_f29_756;
    f32 temp_f2_439;
    f32 temp_f2_488;
    f32 var_f0_327;
    f32 var_f25_259;
    f32 var_f26_188;
    f32 var_f27_186;
    f32 var_f4_394;
    f64 temp_f0_309;
    f64 temp_f0_491;
    f64 temp_f0_567;
    f64 temp_f0_610;
    f64 temp_f0_732;
    f64 temp_f0_743;
    f64 temp_f0_759;
    f64 temp_f0_769;
    f64 temp_f0_807;
    f64 temp_f1_303;
    f64 temp_f2_333;
    f64 temp_f2_339;
    f64 temp_f2_343;
    s32 temp_r0_195;
    s32 temp_r0_641;
    s32 temp_r3_193;
    s32 temp_r3_362;
    s32 temp_r4_639;
    s32 var_r0_211;
    s32 var_r0_372;
    s32 var_r0_411;
    s32 var_r0_657;
    s32 var_r20_706;
    s32 var_r3_638;
    u8 var_r0_443;
    u8 var_r24_192;
    u8 var_r25_190;
    u8 var_r3_201;
    u8 var_r4_647;
    void *temp_r3_302;
    void *temp_r3_831;
    void *temp_r4_197;
    void *temp_r5_643;

    temp_r3_141 = checked_cast<FireBombFX *, MKProp>(((MKPropDescriptor *) (M2C_BITWISE(MKPropDescriptor *, this->unk268)))->CreateInstance());
    if (temp_r3_141 != NULL) {
        M2C_FIELD(temp_r3_141->__vptr, M2C_UNK (**)(), 0x30)();
        if ((void *) M2C_FIELD(&gb, void **, 0x3B8) != NULL) {
            sp2B4 = 0;
            MKVector(1.0f, 1.0f, 1.0f);
            sp30 = sp240 * 5.49408334e-315;
            sp2B0 = 0x417;
            sp2B8 = sp30;
            sp38 = sp248 * 50.0f;
            sp2C8 = 1;
            sp2C0 = (f64) sp38;
            sp250 = sp30;
            sp258 = (f64) sp38;
            M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, f64), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &sp2B0, sp30);
        }
        var_f27_186 = 2000.0f;
        var_f26_188 = 1.0f;
        var_r25_190 = 0;
        var_r24_192 = 0;
        temp_r3_193 = M2C_FIELD(GameData::gameData, s32 *, 0x158) << 5;
        temp_r0_195 = *(&GameData::gameData[0x70] + (temp_r3_193 + 0x7C));
        temp_r4_197 = &GameData::gameData[0x70] + (temp_r3_193 + 0x64);
        if (temp_r0_195 == 3) {
            var_r3_201 = 0;
            if (((s32) M2C_FIELD(temp_r4_197, s32 *, 0) == 3) && ((s32) M2C_FIELD(temp_r4_197, s32 *, 4) == 3)) {
                var_r3_201 = 1;
            }
            var_r0_211 = var_r3_201 != 0;
        } else {
            var_r0_211 = *(temp_r4_197 + (temp_r0_195 * 4));
        }
        switch (var_r0_211) {                       /* switch 1; irregular */
        case 0:                                     /* switch 1 */
            var_f27_186 = 1000.0f;
            var_r25_190 = 0;
            var_f26_188 = 0.5f;
            var_r24_192 = 0;
            this->unkA0 = 1000.0f;
            break;
        case 1:                                     /* switch 1 */
            var_f27_186 = 2000.0f;
            var_r25_190 = 0;
            var_f26_188 = 0.7f;
            var_r24_192 = 0;
            this->unkA0 = 2000.0f;
            break;
        case 2:                                     /* switch 1 */
            var_r25_190 = 1;
            var_f27_186 = 2000.0f;
            var_r24_192 = 0;
            this->unkA0 = 2500.0f;
            var_f26_188 = 0.85f;
            break;
        case 3:                                     /* switch 1 */
            var_r25_190 = 1;
            var_f27_186 = 2000.0f;
            var_r24_192 = 1;
            this->unkA0 = 2500.0f;
            var_f26_188 = 0.85f;
            break;
        }
        var_f25_259 = 3.4028235e38f;
        var_r23_261 = NULL;
        var_r22_264 = ((TargetManager *) (M2C_FIELD(&gb, TargetManager **, 0x20)))->Begin();
loop_57:
        if (var_r22_264 != NULL) {
            temp_r27_461 = *var_r22_264;
            if (temp_r27_461 != NULL) {
                if (((*temp_r27_461)->unk8.unk0(temp_r27_461) != NULL) && (M2C_FIELD(*temp_r27_461, u8 (**)(TargetManager **), 0x18)(temp_r27_461) != 0) && ((((u32 (*)(TargetManager **)) (*temp_r27_461)->unk8.unk4)(temp_r27_461) == 0U) || (((Character *) (((Character *(*)(TargetManager **)) (*temp_r27_461)->unk8.unk4)(temp_r27_461)))->IsActive() != 0))) {
                    temp_r3_302 = M2C_FIELD((*temp_r27_461)->unk8.unk0(temp_r27_461), void **, 8);
                    temp_f1_303 = M2C_FIELD(temp_r3_302, f64 *, 0x30);
                    sp230 = temp_f1_303;
                    sp238 = M2C_FIELD(temp_r3_302, f64 *, 0x38);
                    temp_f0_309 = temp_f1_303 - M2C_FIELD(&arg0, f64 *, 0);
                    sp110 = temp_f0_309;
                    sp2A0 = temp_f0_309;
                    sp118 = (f32) sp238 - arg0.unk8;
                    sp2A8 = (f64) sp118;
                    var_f0_327 = ((f32) sp2A8 * (f32) sp2A8) + (((f32) sp2A0 * (f32) sp2A0) + (unksp2A4 * unksp2A4));
                    if (var_f0_327 > 0.000001f) {
                        if (var_f0_327 > 0.0f) {
                            temp_f2_333 = __frsqrte(var_f0_327);
                            temp_f2_339 = 0.5 * temp_f2_333 * -(((f64) var_f0_327 * (temp_f2_333 * temp_f2_333)) - 3.0);
                            temp_f2_343 = 0.5 * temp_f2_339 * -(((f64) var_f0_327 * (temp_f2_339 * temp_f2_339)) - 3.0);
                            var_f0_327 = (f32) ((f64) var_f0_327 * (0.5 * temp_f2_343 * -(((f64) var_f0_327 * (temp_f2_343 * temp_f2_343)) - 3.0)));
                        } else if (var_f0_327 < M2C_BITWISE(f32, 0.0)) {
                            var_f0_327 = __float_nan;
                        } else {
                            sp8 = var_f0_327;
                            temp_r3_362 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                            switch (temp_r3_362) {  /* switch 2; irregular */
                            case 0x7F800000:        /* switch 2 */
                                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                    var_r0_372 = 1;
                                } else {
                                    var_r0_372 = 2;
                                }
                                break;
                            case 0x0:               /* switch 2 */
                                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                    var_r0_372 = 5;
                                } else {
                                    var_r0_372 = 3;
                                }
                                break;
                            default:                /* switch 2 */
                                var_r0_372 = 4;
                                break;
                            }
                            if (var_r0_372 == 1) {
                                var_f0_327 = __float_nan;
                            }
                        }
                        var_f4_394 = 1.0f / var_f0_327;
                    } else {
                        var_f4_394 = 0.0f;
                        var_f0_327 = 0.0f;
                    }
                    sp2A0 = (f32) sp2A0 * var_f4_394;
                    unksp2A4 *= var_f4_394;
                    sp2A8 = (f32) sp2A8 * var_f4_394;
                    if (arg3 != 0) {
                        var_r0_411 = 1;
                    } else {
                        var_r0_411 = var_f0_327 >= (0.5f * this->unkA0);
                    }
                    if ((var_r0_411 != 0) && (var_f0_327 <= this->unkA0) && (var_f0_327 < var_f25_259)) {
                        temp_f2_439 = (sp2A8 * arg1.unk8) + ((sp2A0 * arg1.unk0) + (unksp2A4 * arg1.unk4));
                        if (arg3 != 0) {
                            var_r0_443 = temp_f2_439 > 0.2f;
                        } else {
                            var_r0_443 = temp_f2_439 > 0.8f;
                        }
                        if (var_r0_443 != 0) {
                            var_f25_259 = var_f0_327;
                            var_r23_261 = temp_r27_461;
                        }
                    }
                }
                var_r22_264 += 4;
                goto loop_57;
            }
        }
        if ((var_r23_261 != NULL) && (M2C_FIELD(*var_r23_261, u8 (**)(TargetManager **, MKVector3 *, M2C_UNK *), 0x2C)(var_r23_261, &arg0, &sp280) != 0)) {
            Tools_CalculateVelocity(sp220, arg0, var_f27_186, -1960.0f);
            sp290 = M2C_BITWISE(f64, sp220);
            sp298 = (f64) sp220.unk8;
        } else {
            temp_f2_488 = this->unkA0;
            temp_f0_491 = (f64) M2C_FIELD(&arg1, f32 *, 0) * (f64) temp_f2_488;
            sp100 = temp_f0_491;
            sp210 = temp_f0_491;
            sp108 = arg1.unk8 * temp_f2_488;
            sp218 = (f64) sp108;
            spF0 = M2C_FIELD(&arg0, f64 *, 0) + temp_f0_491;
            spC8 = 0.0f;
            spC0 = 0.0f;
            spC4 = -500.0f;
            spF8 = arg0.unk8 + (f32) sp218;
            sp270 = spF0;
            sp1D0 = (f64) spC0;
            sp278 = (f64) spF8;
            sp2D0 = 0.0f;
            sp2D4 = 0.0f;
            sp2D8 = 0.0f;
            sp2E0 = 0.0f;
            sp2E4 = 0.0f;
            sp2E8 = 0.0f;
            sp2F0 = 0.0f;
            sp2F4 = 0.0f;
            sp2F8 = 0.0f;
            sp2FC = 1.0f;
            sp300 = 0.0f;
            sp304 = 0.0f;
            sp308 = 0;
            sp30A = 0;
            sp30B = 0;
            sp30C = 0;
            sp310 = 3.4028235e38f;
            sp314 = 0;
            sp318 = 0;
            sp31C = -1;
            sp320 = 0;
            sp1D8 = (f64) spC8;
            spB0 = sp270 + sp1D0;
            spE8 = 0.0f;
            spE0 = 0.0f;
            spE4 = 500.0f;
            spB8 = (f32) sp278 + (f32) sp1D8;
            sp1F0 = (f64) spE0;
            sp1E0 = spB0;
            sp1E8 = (f64) spB8;
            sp1F8 = (f64) spE8;
            temp_f0_567 = sp270 + sp1F0;
            spD0 = temp_f0_567;
            sp200 = temp_f0_567;
            spD8 = (f32) sp278 + (f32) sp1F8;
            sp208 = (f64) spD8;
            if (MKCollision_RayCollide(*((MKVector3 *) &sp200), *((MKVector3 *) &sp1E0), (MKCollisionResult *) &sp2D0, (MKCollisionMode) 4, 0x0C000000) != 0) {
                sp270 = (f64) sp2D0;
                sp278 = (f64) sp2D8;
            }
            Tools_CalculateVelocity(sp1C0, arg0, var_f27_186, -1960.0f);
            sp290 = M2C_BITWISE(f64, sp1C0);
            sp298 = (f64) sp1C0.unk8;
        }
        sp98 = 0.0f;
        sp90 = 0.0f;
        sp94 = 0.0f;
        sp1A8 = (f64) sp98;
        sp1A0 = (f64) sp90;
        temp_f0_610 = sp290 + M2C_FIELD(&arg2, f64 *, 0);
        spA0 = temp_f0_610;
        temp_f1_617 = (f32) sp298 + arg2.unk8;
        sp1B0 = temp_f0_610;
        spA8 = temp_f1_617;
        sp1B8 = (f64) spA8;
        temp_r3_141->Fire(arg0, *((MKVector3 *) &sp1B0), var_f26_188, M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), MKProp *(**)(void **, f32, f32), 0xC)(M2C_FIELD(&gb, void ***, 0), temp_f1_617, (f32) sp298), var_r25_190, var_r24_192, 0, *((MKVector3 *) &sp1A0));
        var_r3_638 = 0;
        temp_r4_639 = M2C_FIELD(GameData::gameData, s32 *, 0x158) << 5;
        temp_r0_641 = *(&GameData::gameData[0x70] + (temp_r4_639 + 0x7C));
        temp_r5_643 = &GameData::gameData[0x70] + (temp_r4_639 + 0x64);
        if (temp_r0_641 == 3) {
            var_r4_647 = 0;
            if (((s32) M2C_FIELD(temp_r5_643, s32 *, 0) == 3) && ((s32) M2C_FIELD(temp_r5_643, s32 *, 4) == 3)) {
                var_r4_647 = 1;
            }
            var_r0_657 = var_r4_647 != 0;
        } else {
            var_r0_657 = *(temp_r5_643 + (temp_r0_641 * 4));
        }
        switch (var_r0_657) {                       /* switch 3; irregular */
        case 0:                                     /* switch 3 */
            var_r3_638 = GS_SpyBreathFireball;
            break;
        case 1:                                     /* switch 3 */
            var_r3_638 = GS_SpyBreathFireball2;
            break;
        case 2:                                     /* switch 3 */
            var_r3_638 = GS_SpyBreathFireball3;
            break;
        case 3:                                     /* switch 3 */
            var_r3_638 = GS_SpyBreathFireball4;
            break;
        }
        KDSound_Play3d(var_r3_638, &arg0, 0U, -1, 0.0f, 0U);
        ((KDInput *) (M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), KDInput *(**)(void **), 0x40)(M2C_FIELD(&gb, void ***, 0))))->RumblePlay(0.0f, 0.4f, 0.04f, 0, 4.0f, 0U);
        var_r20_706 = 0;
        temp_f25_707 = arg1.unk8;
        do {
            temp_f27_713 = MKRand_Float(&gViewSeed, -0.7f, 0.7f);
            temp_f26_718 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
            sp80 = MKRand_Float(&gViewSeed, -0.7f, 0.7f);
            sp84 = temp_f26_718;
            sp88 = temp_f27_713;
            sp180 = (f64) sp80;
            sp188 = (f64) sp88;
            temp_f0_732 = sp180 * 5.180653787e-315;
            sp70 = temp_f0_732;
            sp190 = temp_f0_732;
            sp78 = (f32) sp188 * 0.25f;
            sp198 = (f64) sp78;
            temp_f0_743 = (f64) M2C_FIELD(&arg1, f32 *, 0) + temp_f0_732;
            sp60 = temp_f0_743;
            sp260 = temp_f0_743;
            sp68 = temp_f25_707 + (f32) sp198;
            sp268 = (f64) sp68;
            temp_f29_756 = MKRand_Float(&gViewSeed, 0.8f, 1.0f);
            temp_f0_759 = temp_f0_743 * 5.634608575e-315;
            sp50 = temp_f0_759;
            sp160 = temp_f0_759;
            sp58 = (f32) sp268 * 500.0f;
            sp168 = (f64) sp58;
            temp_f0_769 = temp_f0_759 * (f64) temp_f29_756;
            sp40 = temp_f0_769;
            sp170 = temp_f0_769;
            sp48 = (f32) sp168 * temp_f29_756;
            sp178 = (f64) sp48;
            this->unkAC->Emit(arg0, *((MKVector3 *) &sp170), 1.0f);
            var_r20_706 += 1;
        } while (var_r20_706 < 5);
        this->unkC0 = 1.5f;
        temp_r4_788 = this->unkA8;
        if (temp_r4_788 != NULL) {
            ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->EnableLight(temp_r4_788, 1U);
            MKVector(0.0f, 300.0f, 0.0f);
            sp130.operator*(500.0f);
            temp_f0_807 = M2C_FIELD(&arg0, f64 *, 0) + M2C_BITWISE(f64, sp130);
            sp10 = temp_f0_807;
            sp140 = temp_f0_807;
            sp18 = arg0.unk8 + sp130.unk8;
            sp148 = (f64) sp18;
            sp20 = sp140 + sp120;
            temp_r3_825 = this->unkA8;
            sp150 = sp20;
            sp28 = (f32) sp148 + sp128;
            temp_r3_825->unk10 = sp20;
            temp_r3_825->unk18 = (f64) sp28;
            temp_r3_831 = temp_r3_825->unk3C;
            sp158 = (f64) sp28;
            if (temp_r3_831 != NULL) {
                M2C_FIELD(temp_r3_831, f64 *, 0x10) = sp20;
                M2C_FIELD(temp_r3_831, f64 *, 0x18) = (f64) sp28;
            }
        }
        this->unkBC = 2;
        this->unkD8 = 1.0f;
        return 1U;
    }
    return 0U;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'const int *' to
s32 FlameBreathFX::Trigger(MKProp *arg0, const MKVector3 &arg1, const MKVector3 &arg2, const MKVector3 &arg3, const float &arg4, const int &arg5, bool arg6, bool arg7) {
    f64 sp9E8;
    f64 sp9E0;
    f64 sp9D8;
    s8 sp9C8;
    s32 sp9C4;
    s32 sp9C0;
    s32 sp9BC;
    f32 sp9B8;
    s32 sp9B4;
    s8 sp9B3;
    s8 sp9B2;
    s16 sp9B0;
    f32 sp9AC;
    f32 sp9A8;
    f32 sp9A4;
    f32 sp9A0;
    f32 sp99C;
    f32 sp998;
    f32 sp990;
    f32 sp98C;
    f32 sp988;
    f32 sp980;
    f32 sp97C;
    f32 sp978;
    MKCollisionResult sp920;
    s8 sp918;
    s32 sp914;
    s32 sp910;
    s32 sp90C;
    f32 sp908;
    s32 sp904;
    s8 sp903;
    s8 sp902;
    s16 sp900;
    f32 sp8FC;
    f32 sp8F8;
    f32 sp8F4;
    f32 sp8F0;
    f32 sp8EC;
    f32 sp8E8;
    f32 sp8E0;
    f32 sp8DC;
    f32 sp8D8;
    f32 sp8D0;
    f32 sp8CC;
    f32 sp8C8;
    s8 sp8C0;
    f64 sp8B8;
    f64 sp8B0;
    s32 sp8AC;
    s32 sp8A8;
    f64 sp8A0;
    f64 sp898;
    f64 sp890;
    f64 sp888;
    f64 sp880;
    f64 sp878;
    f64 sp870;
    f64 sp868;
    f64 sp860;
    f64 sp858;
    f64 sp850;
    f64 sp848;
    f64 sp840;
    f64 sp838;
    f64 sp830;
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
    f64 sp7C8;
    f64 sp7C0;
    f64 sp7B8;
    f64 sp7B0;
    f64 sp7A8;
    f64 sp7A0;
    f64 sp798;
    f64 sp790;
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
    MKVector3 sp5C8;
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
    MKVector3 sp4E8;
    f64 sp4D8;
    f64 sp4D0;
    f64 sp4C8;
    f64 sp4C0;
    f64 sp4B8;
    f64 sp4B0;
    f64 sp4A8;
    f64 sp4A0;
    f64 sp498;
    f64 sp490;
    f64 sp488;
    f64 sp480;
    f64 sp478;
    f64 sp470;
    f64 sp468;
    f64 sp460;
    f64 sp458;
    f64 sp450;
    f64 sp448;
    f64 sp440;
    f64 sp438;
    MKVector3 sp428;
    f64 sp420;
    f64 sp418;
    f64 sp410;
    f64 sp408;
    f32 sp400;
    f32 sp3FC;
    f32 sp3F8;
    f32 sp3F0;
    f64 sp3E8;
    f32 sp3E0;
    f64 sp3D8;
    f32 sp3D0;
    f32 sp3CC;
    f32 sp3C8;
    f32 sp3C0;
    f64 sp3B8;
    f32 sp3B0;
    f64 sp3A8;
    f32 sp3A0;
    f64 sp398;
    f32 sp390;
    f64 sp388;
    f32 sp380;
    f64 sp378;
    f32 sp370;
    f64 sp368;
    f32 sp360;
    f64 sp358;
    f32 sp350;
    f32 sp34C;
    f32 sp348;
    f32 sp340;
    f64 sp338;
    f32 sp330;
    f64 sp328;
    f32 sp320;
    f64 sp318;
    f32 sp310;
    f64 sp308;
    f32 sp300;
    f64 sp2F8;
    f32 sp2F0;
    f64 sp2E8;
    f32 sp2E0;
    f32 sp2DC;
    f32 sp2D8;
    f32 sp2D0;
    f64 sp2C8;
    f32 sp2C0;
    f32 sp2BC;
    f32 sp2B8;
    f32 sp2B0;
    f64 sp2A8;
    f32 sp2A0;
    f32 sp29C;
    f32 sp298;
    f32 sp290;
    f32 sp28C;
    f32 sp288;
    f32 sp280;
    f64 sp278;
    f32 sp270;
    f32 sp26C;
    f32 sp268;
    f32 sp260;
    f64 sp258;
    f32 sp250;
    f64 sp248;
    f32 sp240;
    f64 sp238;
    f32 sp230;
    f64 sp228;
    f32 sp220;
    f32 sp21C;
    f32 sp218;
    f32 sp210;
    f32 sp20C;
    f32 sp208;
    f32 sp200;
    f64 sp1F8;
    f32 sp1F0;
    f64 sp1E8;
    f32 sp1E0;
    f32 sp1DC;
    f32 sp1D8;
    f32 sp1D0;
    f64 sp1C8;
    f32 sp1C0;
    f32 sp1BC;
    f32 sp1B8;
    f32 sp1B0;
    f64 sp1A8;
    f32 sp1A0;
    f64 sp198;
    f32 sp190;
    f64 sp188;
    f32 sp180;
    f64 sp178;
    f32 sp170;
    f64 sp168;
    f32 sp160;
    f32 sp15C;
    f32 sp158;
    f32 sp150;
    f64 sp148;
    f32 sp140;
    f64 sp138;
    f32 sp130;
    f64 sp128;
    f32 sp120;
    f32 sp11C;
    f32 sp118;
    f32 sp110;
    f64 sp108;
    f32 sp100;
    f64 spF8;
    f32 spF0;
    f64 spE8;
    f32 spE0;
    f32 spDC;
    f32 spD8;
    f32 spD0;
    f32 spCC;
    f32 spC8;
    f32 spC0;
    f64 spB8;
    f32 spB0;
    f64 spA8;
    f32 spA0;
    f64 sp98;
    f32 sp90;
    f64 sp88;
    f32 sp80;
    f64 sp78;
    f32 sp70;
    f64 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp50;
    f64 sp48;
    f32 sp40;
    f64 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    s32 sp8;
    Corona *temp_r3_2173;
    Corona *temp_r4_2159;
    ManagedLight *temp_r3_2217;
    ManagedLight *temp_r3_2233;
    ManagedLight *temp_r4_2178;
    f32 temp_f0_1356;
    f32 temp_f14_2266;
    f32 temp_f15_2002;
    f32 temp_f15_2269;
    f32 temp_f16_1042;
    f32 temp_f17_2422;
    f32 temp_f18_2267;
    f32 temp_f1_2253;
    f32 temp_f20_1997;
    f32 temp_f21_2270;
    f32 temp_f22_2283;
    f32 temp_f23_1876;
    f32 temp_f23_2278;
    f32 temp_f24_1048;
    f32 temp_f24_1564;
    f32 temp_f24_1685;
    f32 temp_f24_1816;
    f32 temp_f25_1064;
    f32 temp_f26_1059;
    f32 temp_f26_2424;
    f32 temp_f2_1209;
    f32 temp_f2_1344;
    f32 temp_f30_1877;
    f32 temp_f31_1690;
    f32 temp_f31_1811;
    f32 temp_f3_1570;
    f32 temp_f3_2103;
    f32 temp_f5_2260;
    f32 var_f0_1710;
    f32 var_f3_1150;
    f32 var_f3_1777;
    f32 var_f3_2379;
    f32 var_f4_1083;
    f32 var_f4_2312;
    f64 temp_f0_1170;
    f64 temp_f0_1181;
    f64 temp_f0_1213;
    f64 temp_f0_1245;
    f64 temp_f0_1257;
    f64 temp_f0_1342;
    f64 temp_f0_1567;
    f64 temp_f0_1578;
    f64 temp_f0_1634;
    f64 temp_f0_1797;
    f64 temp_f0_1850;
    f64 temp_f0_1862;
    f64 temp_f0_1879;
    f64 temp_f0_1890;
    f64 temp_f0_1972;
    f64 temp_f0_1984;
    f64 temp_f0_2037;
    f64 temp_f0_2049;
    f64 temp_f0_2108;
    f64 temp_f0_2118;
    f64 temp_f0_2129;
    f64 temp_f0_2140;
    f64 temp_f0_2199;
    f64 temp_f0_2296;
    f64 temp_f0_2398;
    f64 temp_f0_2409;
    f64 temp_f0_2426;
    f64 temp_f0_2436;
    f64 temp_f0_2446;
    f64 temp_f0_2535;
    f64 temp_f0_2547;
    f64 temp_f1_1089;
    f64 temp_f1_1095;
    f64 temp_f1_1099;
    f64 temp_f1_1193;
    f64 temp_f1_1351;
    f64 temp_f1_2318;
    f64 temp_f1_2324;
    f64 temp_f1_2328;
    f64 temp_f2_1566;
    f64 temp_f2_1716;
    f64 temp_f2_1722;
    f64 temp_f2_1726;
    f64 temp_f4_1366;
    s32 temp_r0_1297;
    s32 temp_r0_1924;
    s32 temp_r0_2488;
    s32 temp_r0_919;
    s32 temp_r22_936;
    s32 temp_r23_940;
    s32 temp_r3_1006;
    s32 temp_r3_1118;
    s32 temp_r3_1295;
    s32 temp_r3_1745;
    s32 temp_r3_1922;
    s32 temp_r3_2347;
    s32 temp_r3_2486;
    s32 temp_r3_938;
    s32 temp_r6_1008;
    s32 var_r0_1128;
    s32 var_r0_1313;
    s32 var_r0_1755;
    s32 var_r0_1940;
    s32 var_r0_2357;
    s32 var_r0_2504;
    s32 var_r21_975;
    s32 var_r22_1051;
    s32 var_r22_1672;
    s32 var_r22_2259;
    s32 var_r6_956;
    s32 var_r7_1024;
    u8 temp_r3_1501;
    u8 var_r3_1014;
    u8 var_r3_1303;
    u8 var_r3_1930;
    u8 var_r3_2494;
    u8 var_r3_2589;
    u8 var_r3_946;
    u8 var_r3_965;
    void *temp_r3_2223;
    void *temp_r3_2241;
    void *temp_r4_1010;
    void *temp_r4_1299;
    void *temp_r4_1926;
    void *temp_r4_2490;
    void *temp_r4_2595;
    void *temp_r4_942;
    void *var_r3_2078;

    this->unkB8 = &arg5;
    temp_r0_919 = this->unkB8;
    switch (temp_r0_919) {                          /* switch 1; irregular */
    case 0:                                         /* switch 1 */
        temp_r22_936 = M2C_FIELD(GameData::gameData, s32 *, 0x158);
        temp_r3_938 = temp_r22_936 << 5;
        temp_r23_940 = *(&GameData::gameData[0x70] + (temp_r3_938 + 0x7C));
        temp_r4_942 = &GameData::gameData[0x70] + (temp_r3_938 + 0x64);
        if (temp_r23_940 == 3) {
            var_r3_946 = 0;
            if (((s32) M2C_FIELD(temp_r4_942, s32 *, 0) == 3) && ((s32) M2C_FIELD(temp_r4_942, s32 *, 4) == 3)) {
                var_r3_946 = 1;
            }
            var_r6_956 = var_r3_946 != 0;
        } else {
            var_r6_956 = *(temp_r4_942 + (temp_r23_940 * 4));
        }
        if (temp_r23_940 == 3) {
            var_r3_965 = 0;
            if (((s32) M2C_FIELD(temp_r4_942, s32 *, 0) == 3) && ((s32) M2C_FIELD(temp_r4_942, s32 *, 4) == 3)) {
                var_r3_965 = 1;
            }
            var_r21_975 = var_r3_965 != 0;
        } else {
            var_r21_975 = *(temp_r4_942 + (temp_r23_940 * 4));
        }
        streamHitMsg.Init(arg0, ((GameStats *) ((GameStats *) &GameData::gameData[0x70]))->GetBreathAttackDamage(temp_r22_936, temp_r23_940, var_r6_956), temp_r23_940, var_r21_975, temp_r22_936, temp_r22_936, 0, -1);
        if (((u8) M2C_FIELD(&gb, u8 *, 0x3B5) == 0) && (M2C_FIELD(GameData::gameData, f32 *, 0xA0) <= 0.0f)) {
            temp_r3_1006 = M2C_FIELD(GameData::gameData, s32 *, 0x158) << 5;
            temp_r6_1008 = *(&GameData::gameData[0x70] + (temp_r3_1006 + 0x7C));
            temp_r4_1010 = &GameData::gameData[0x70] + (temp_r3_1006 + 0x64);
            if (temp_r6_1008 == 3) {
                var_r3_1014 = 0;
                if (((s32) M2C_FIELD(temp_r4_1010, s32 *, 0) == 3) && ((s32) M2C_FIELD(temp_r4_1010, s32 *, 4) == 3)) {
                    var_r3_1014 = 1;
                }
                var_r7_1024 = var_r3_1014 != 0;
            } else {
                var_r7_1024 = *(temp_r4_1010 + (temp_r6_1008 * 4));
            }
            sp8 = -1;
            streamHitMsg.Init(arg0, 0, temp_r6_1008, var_r7_1024, M2C_FIELD(GameData::gameData, s32 *, 0x158), M2C_FIELD(GameData::gameData, s32 *, 0x158), 0, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
            temp_f16_1042 = arg2.unk8;
            temp_f24_1048 = arg3.unk8;
            var_r22_1051 = 0;
            do {
                temp_f26_1059 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                temp_f25_1064 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                sp3F8 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                sp3FC = temp_f25_1064;
                sp400 = temp_f26_1059;
                sp808 = (f64) sp3F8;
                sp810 = (f64) sp400;
                var_f4_1083 = ((f32) sp810 * (f32) sp810) + (((f32) sp808 * (f32) sp808) + (unksp80C * unksp80C));
                if (var_f4_1083 > 1e-12f) {
                    if (var_f4_1083 > 0.0f) {
                        temp_f1_1089 = __frsqrte(var_f4_1083);
                        temp_f1_1095 = 0.5 * temp_f1_1089 * -(((f64) var_f4_1083 * (temp_f1_1089 * temp_f1_1089)) - 3.0);
                        temp_f1_1099 = 0.5 * temp_f1_1095 * -(((f64) var_f4_1083 * (temp_f1_1095 * temp_f1_1095)) - 3.0);
                        var_f4_1083 = (f32) ((f64) var_f4_1083 * (0.5 * temp_f1_1099 * -(((f64) var_f4_1083 * (temp_f1_1099 * temp_f1_1099)) - 3.0)));
                    } else if (var_f4_1083 < M2C_BITWISE(f32, 0.0)) {
                        var_f4_1083 = __float_nan;
                    } else {
                        sp18 = var_f4_1083;
                        temp_r3_1118 = M2C_BITWISE(s32, sp18) & 0x7F800000;
                        switch (temp_r3_1118) {     /* switch 2; irregular */
                        case 0x7F800000:            /* switch 2 */
                            if (M2C_BITWISE(s32, sp18) & 0x7FFFFF) {
                                var_r0_1128 = 1;
                            } else {
                                var_r0_1128 = 2;
                            }
                            break;
                        case 0x0:                   /* switch 2 */
                            if (M2C_BITWISE(s32, sp18) & 0x7FFFFF) {
                                var_r0_1128 = 5;
                            } else {
                                var_r0_1128 = 3;
                            }
                            break;
                        default:                    /* switch 2 */
                            var_r0_1128 = 4;
                            break;
                        }
                        if (var_r0_1128 == 1) {
                            var_f4_1083 = __float_nan;
                        }
                    }
                    var_f3_1150 = 1.0f / var_f4_1083;
                } else {
                    var_f3_1150 = 0.0f;
                }
                sp3C8 = (f32) sp808 * var_f3_1150;
                sp3CC = unksp80C * var_f3_1150;
                sp3D0 = (f32) sp810 * var_f3_1150;
                sp818 = (f64) sp3C8;
                sp820 = (f64) sp3D0;
                temp_f0_1170 = sp818 * 5.180653787e-315;
                sp3E8 = temp_f0_1170;
                sp828 = temp_f0_1170;
                sp3F0 = (f32) sp820 * 0.25f;
                sp830 = (f64) sp3F0;
                temp_f0_1181 = M2C_FIELD(&arg2, f64 *, 0) + sp828;
                sp3D8 = temp_f0_1181;
                sp898 = temp_f0_1181;
                sp3E0 = temp_f16_1042 + (f32) sp830;
                sp8A0 = (f64) sp3E0;
                temp_f1_1193 = MKRand_Float(&gViewSeed, 300.0f, 600.0f);
                sp3B8 = sp898 * temp_f1_1193;
                sp3C0 = (f32) sp8A0 * (f32) temp_f1_1193;
                sp7D8 = sp3B8;
                temp_f2_1209 = (f32) var_r22_1051 / 10.0f;
                sp7E0 = (f64) sp3C0;
                temp_f0_1213 = sp7D8 * (f64) temp_f2_1209;
                sp3A8 = temp_f0_1213;
                sp7E8 = temp_f0_1213;
                sp3B0 = (f32) sp7E0 * temp_f2_1209;
                sp7F0 = (f64) sp3B0;
                sp398 = sp7E8 + M2C_FIELD(&arg3, f64 *, 0);
                sp7F8 = sp398;
                sp3A0 = (f32) sp7F0 + temp_f24_1048;
                sp24 = (2.0f * temp_f2_1209) + 1.0f;
                sp800 = (f64) sp3A0;
                this->unkAC->Emit(arg1, *((MKVector3 *) &sp7F8), sp24);
                var_r22_1051 += 1;
            } while (var_r22_1051 < 0xA);
            temp_f0_1245 = M2C_FIELD(&arg2, f64 *, 0) * 5.60222949e-315;
            sp388 = temp_f0_1245;
            sp7B8 = temp_f0_1245;
            sp390 = arg2.unk8 * 300.0f;
            sp7C0 = (f64) sp390;
            temp_f0_1257 = sp7B8 + M2C_FIELD(&arg3, f64 *, 0);
            sp378 = temp_f0_1257;
            sp7C8 = temp_f0_1257;
            sp380 = (f32) sp7C0 + arg3.unk8;
            sp7D0 = (f64) sp380;
            CreateCollisionTest(arg1, *((MKVector3 *) &sp7C8), M2C_BITWISE(f32, this->unk264), 0x04000000U, FlameBreathFXHitCallback);
            KDSound_Play3d(GS_SpyroOutOfBreath, M2C_FIELD(M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), void *(**)(void **), 0xC)(M2C_FIELD(&gb, void ***, 0)), s32 *, 8) + 0x30, 0U, -1, 0.0f, 0U);
            return 1;
        }
        temp_r3_1295 = M2C_FIELD(GameData::gameData, s32 *, 0x158) << 5;
        temp_r0_1297 = *(&GameData::gameData[0x70] + (temp_r3_1295 + 0x7C));
        temp_r4_1299 = &GameData::gameData[0x70] + (temp_r3_1295 + 0x64);
        if (temp_r0_1297 == 3) {
            var_r3_1303 = 0;
            if (((s32) M2C_FIELD(temp_r4_1299, s32 *, 0) == 3) && ((s32) M2C_FIELD(temp_r4_1299, s32 *, 4) == 3)) {
                var_r3_1303 = 1;
            }
            var_r0_1313 = var_r3_1303 != 0;
        } else {
            var_r0_1313 = *(temp_r4_1299 + (temp_r0_1297 * 4));
        }
        this->unk130 = var_r0_1313;
        GetAttack1UpgradeVariables(this->unk130, sp30, sp2C, sp28);
        this->unk148.unk10C = sp30;
        sp350 = 0.0f;
        this->unk148.unk110 = sp28;
        sp348 = 0.0f;
        sp34C = 100.0f;
        sp790 = (f64) sp350;
        sp788 = (f64) sp348;
        temp_f0_1342 = M2C_FIELD(&arg2, f64 *, 0) * (f64) sp2C;
        sp368 = temp_f0_1342;
        temp_f2_1344 = arg2.unk8;
        sp798 = temp_f0_1342;
        sp370 = temp_f2_1344 * sp2C;
        sp7A0 = (f64) sp370;
        temp_f1_1351 = M2C_FIELD(&arg1, f64 *, 0);
        sp358 = temp_f1_1351 + temp_f0_1342;
        temp_f0_1356 = arg1.unk8;
        sp7A8 = sp358;
        sp360 = temp_f0_1356 + (f32) sp7A0;
        sp7B0 = (f64) sp360;
        temp_f4_1366 = sp7A8 + sp788;
        sp338 = temp_f4_1366;
        sp888 = temp_f4_1366;
        sp340 = (f32) sp7B0 + (f32) sp790;
        sp890 = (f64) sp340;
        if ((u8) this->unkB4 == 0) {
            sp778 = M2C_FIELD(&arg1, f64 *, 0);
            sp780 = (f64) M2C_FIELD(&arg1, f32 *, 8);
            sp328 = M2C_FIELD(&arg2, f64 *, 0) * 0.0;
            sp330 = temp_f2_1344 * 0.0f;
            sp758 = sp328;
            sp760 = (f64) sp330;
            sp318 = temp_f1_1351 + sp758;
            sp768 = sp318;
            sp320 = temp_f0_1356 + (f32) sp760;
            sp748 = M2C_FIELD(&arg2, f64 *, 0);
            sp770 = (f64) sp320;
            sp750 = (f64) M2C_FIELD(&arg2, f32 *, 8);
            this->unk148.ResetBeamNodes((MKVector3) &sp778, (MKVector3) &sp768, (MKVector3) &sp748);
            this->unk148.unk100 = 1.5f;
            this->unk148.unk104 = 0.5f;
            if ((void *) M2C_FIELD(&gb, void **, 0x3B8) != NULL) {
                sp8AC = 0;
                MKVector(1.0f, 1.0f, 1.0f);
                sp98 = sp728 * 5.49408334e-315;
                sp8A8 = 0x417;
                sp8B0 = sp98;
                spA0 = sp730 * 50.0f;
                sp8C0 = 1;
                sp8B8 = (f64) spA0;
                sp738 = sp98;
                sp740 = (f64) spA0;
                M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, f64), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &sp8A8, sp98);
            }
            if ((s32) this->unk130 == 0) {
                this->unk134 = 1.5f;
            }
            goto block_64;
        }
        if (((s32) this->unk130 == 0) && (this->unk134 <= 0.0f)) {
            return 0;
        }
block_64:
        sp978 = 0.0f;
        sp97C = 0.0f;
        sp980 = 0.0f;
        sp988 = 0.0f;
        sp98C = 0.0f;
        sp990 = 0.0f;
        sp998 = 0.0f;
        sp99C = 0.0f;
        sp9A0 = 0.0f;
        sp9A4 = 1.0f;
        sp9A8 = 0.0f;
        sp9AC = 0.0f;
        sp9B0 = 0;
        sp9B2 = 0;
        sp9B3 = 0;
        sp9B4 = 0;
        sp9B8 = 3.4028235e38f;
        sp9BC = 0;
        sp9C0 = 0;
        sp9C4 = -1;
        sp9C8 = 0;
        temp_r3_1501 = MKCollision_RayCollide(arg1, *((MKVector3 *) &sp888), &sp920, (MKCollisionMode) 7, 0);
        if (temp_r3_1501 != 0) {
            sp888 = M2C_BITWISE(f64, sp920);
            sp890 = (f64) sp920.unk8;
        }
        if (arg6 != 0) {
            sp6F8 = M2C_FIELD(&arg2, f64 *, 0);
            sp700 = (f64) M2C_FIELD(&arg2, f32 *, 8);
            sp708 = sp888;
            sp710 = sp890;
            sp718 = M2C_FIELD(&arg1, f64 *, 0);
            sp720 = (f64) M2C_FIELD(&arg1, f32 *, 8);
            this->unk148.SetBeamPositions((MKVector3) &sp718, (MKVector3) &sp708, (MKVector3) &sp6F8);
        } else {
            sp6C8 = M2C_FIELD(&arg2, f64 *, 0);
            sp6D0 = (f64) M2C_FIELD(&arg2, f32 *, 8);
            sp6D8 = sp888;
            sp6E0 = sp890;
            sp6E8 = M2C_FIELD(&arg1, f64 *, 0);
            sp6F0 = (f64) M2C_FIELD(&arg1, f32 *, 8);
            this->unk148.UpdateBeam((MKVector3) &sp6E8, (MKVector3) &sp6D8, (MKVector3) &sp6C8);
        }
        if (((s32) this->unk130 >= 2) && (this->unk144 <= 0.0f)) {
            this->unk144 = 0.5f;
            temp_f24_1564 = MKRand_Float(&gViewSeed, 0.1f, 1.0f);
            temp_f2_1566 = M2C_FIELD(&arg1, f64 *, 0);
            temp_f0_1567 = sp888 - temp_f2_1566;
            sp308 = temp_f0_1567;
            temp_f3_1570 = arg1.unk8;
            sp6A8 = temp_f0_1567;
            sp310 = (f32) sp890 - temp_f3_1570;
            sp6B0 = (f64) sp310;
            temp_f0_1578 = temp_f0_1567 * (f64) temp_f24_1564;
            sp2F8 = temp_f0_1578;
            sp6B8 = temp_f0_1578;
            sp300 = (f32) sp6B0 * temp_f24_1564;
            sp6C0 = (f64) sp300;
            sp2E8 = temp_f2_1566 + temp_f0_1578;
            sp2F0 = temp_f3_1570 + (f32) sp6C0;
            sp2E0 = 0.0f;
            sp2D8 = 0.0f;
            sp2DC = -300.0f;
            sp878 = sp2E8;
            sp688 = (f64) sp2D8;
            sp880 = (f64) sp2F0;
            sp8C8 = 0.0f;
            sp8CC = 0.0f;
            sp8D0 = 0.0f;
            sp8D8 = 0.0f;
            sp8DC = 0.0f;
            sp8E0 = 0.0f;
            sp8E8 = 0.0f;
            sp8EC = 0.0f;
            sp8F0 = 0.0f;
            sp8F4 = 1.0f;
            sp8F8 = 0.0f;
            sp8FC = 0.0f;
            sp900 = 0;
            sp902 = 0;
            sp903 = 0;
            sp904 = 0;
            sp908 = 3.4028235e38f;
            sp90C = 0;
            sp910 = 0;
            sp914 = -1;
            sp918 = 0;
            sp690 = (f64) sp2E0;
            temp_f0_1634 = sp878 + sp688;
            sp2C8 = temp_f0_1634;
            sp698 = temp_f0_1634;
            sp2D0 = (f32) sp880 + (f32) sp690;
            sp6A0 = (f64) sp2D0;
            if (MKCollision_RayCollide(*((MKVector3 *) &sp878), *((MKVector3 *) &sp698), (MKCollisionResult *) &sp8C8, (MKCollisionMode) 4, 0x04000000) != 0) {
                this->unk140.Emit(*((MKVector3 *) &sp8C8), MKRand_Float(&gViewSeed, 2.0f, 3.0f), 0U);
            }
        }
        if (MKCollision_SphereCollide(*((MKVector3 *) &this->unk148.unkB8), 100.0f, (MKCollisionResult *) &sp978, 1, (MKCollisionMode) 7, 0) != 0) {
            var_r22_1672 = 0;
            sp9D8 = 3.60985932e-315;
            sp9E8 = (f64) (2.0f * &arg4);
            sp9E0 = 1.6145507526e-314;
            do {
                temp_f24_1685 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                temp_f31_1690 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                sp2B8 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                sp2BC = temp_f31_1690;
                sp2C0 = temp_f24_1685;
                sp668 = (f64) sp2B8;
                sp670 = (f64) sp2C0;
                var_f0_1710 = ((f32) sp670 * (f32) sp670) + (((f32) sp668 * (f32) sp668) + (unksp66C * unksp66C));
                if (var_f0_1710 > (f32) sp9D8) {
                    if (var_f0_1710 > 0.0f) {
                        temp_f2_1716 = __frsqrte(var_f0_1710);
                        temp_f2_1722 = 0.5 * temp_f2_1716 * -(((f64) var_f0_1710 * (temp_f2_1716 * temp_f2_1716)) - 3.0);
                        temp_f2_1726 = 0.5 * temp_f2_1722 * -(((f64) var_f0_1710 * (temp_f2_1722 * temp_f2_1722)) - 3.0);
                        var_f0_1710 = (f32) ((f64) var_f0_1710 * (0.5 * temp_f2_1726 * -(((f64) var_f0_1710 * (temp_f2_1726 * temp_f2_1726)) - 3.0)));
                    } else if (var_f0_1710 < M2C_BITWISE(f32, 0.0)) {
                        var_f0_1710 = __float_nan;
                    } else {
                        sp14 = var_f0_1710;
                        temp_r3_1745 = M2C_BITWISE(s32, sp14) & 0x7F800000;
                        switch (temp_r3_1745) {     /* switch 3; irregular */
                        case 0x7F800000:            /* switch 3 */
                            if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                                var_r0_1755 = 1;
                            } else {
                                var_r0_1755 = 2;
                            }
                            break;
                        case 0x0:                   /* switch 3 */
                            if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                                var_r0_1755 = 5;
                            } else {
                                var_r0_1755 = 3;
                            }
                            break;
                        default:                    /* switch 3 */
                            var_r0_1755 = 4;
                            break;
                        }
                        if (var_r0_1755 == 1) {
                            var_f0_1710 = __float_nan;
                        }
                    }
                    var_f3_1777 = 1.0f / var_f0_1710;
                } else {
                    var_f3_1777 = 0.0f;
                }
                sp298 = (f32) sp668 * var_f3_1777;
                sp29C = unksp66C * var_f3_1777;
                sp2A0 = (f32) sp670 * var_f3_1777;
                sp678 = (f64) sp298;
                sp680 = (f64) sp2A0;
                temp_f0_1797 = sp988 + sp678;
                sp2A8 = temp_f0_1797;
                sp868 = temp_f0_1797;
                sp2B0 = sp990 + (f32) sp680;
                sp870 = (f64) sp2B0;
                temp_f31_1811 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                temp_f24_1816 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                sp268 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                sp26C = temp_f24_1816;
                sp270 = temp_f31_1811;
                sp618 = (f64) sp268;
                sp620 = (f64) sp270;
                sp258 = sp618 * 5.53552857e-315;
                sp290 = 0.0f;
                sp260 = (f32) sp620 * 100.0f;
                sp288 = 0.0f;
                sp28C = (f32) sp9E0;
                sp628 = sp258;
                sp638 = (f64) sp288;
                sp630 = (f64) sp260;
                sp640 = (f64) sp290;
                temp_f0_1850 = this->unk148.unkB8 + (f64) sp288;
                sp278 = temp_f0_1850;
                sp648 = temp_f0_1850;
                sp280 = M2C_FIELD(this, f32 *, 0x208) + (f32) sp640;
                sp650 = (f64) sp280;
                temp_f0_1862 = sp648 + sp628;
                sp248 = temp_f0_1862;
                sp658 = temp_f0_1862;
                sp250 = (f32) sp650 + (f32) sp630;
                sp660 = (f64) sp250;
                temp_f23_1876 = MKRand_Float(&gViewSeed, 0.8f, 1.0f);
                temp_f30_1877 = &arg4;
                temp_f0_1879 = sp868 * (f64) temp_f30_1877;
                sp88 = temp_f0_1879;
                sp5E8 = temp_f0_1879;
                sp90 = (f32) sp870 * temp_f30_1877;
                sp5F0 = (f64) sp90;
                temp_f0_1890 = temp_f0_1879 * 5.56887903e-315;
                sp238 = temp_f0_1890;
                sp5F8 = temp_f0_1890;
                sp240 = (f32) sp5F0 * 175.0f;
                sp600 = (f64) sp240;
                sp228 = temp_f0_1890 * (f64) temp_f23_1876;
                sp608 = sp228;
                sp230 = (f32) sp600 * temp_f23_1876;
                sp20 = (f32) sp9E8 * sp30;
                sp610 = (f64) sp230;
                this->unkAC->Emit(*((MKVector3 *) &sp658), *((MKVector3 *) &sp608), sp20);
                var_r22_1672 += 1;
            } while (var_r22_1672 < 5);
            temp_r3_1922 = M2C_FIELD(GameData::gameData, s32 *, 0x158) << 5;
            temp_r0_1924 = *(&GameData::gameData[0x70] + (temp_r3_1922 + 0x7C));
            temp_r4_1926 = &GameData::gameData[0x70] + (temp_r3_1922 + 0x64);
            if (temp_r0_1924 == 3) {
                var_r3_1930 = 0;
                if (((s32) M2C_FIELD(temp_r4_1926, s32 *, 0) == 3) && ((s32) M2C_FIELD(temp_r4_1926, s32 *, 4) == 3)) {
                    var_r3_1930 = 1;
                }
                var_r0_1940 = var_r3_1930 != 0;
            } else {
                var_r0_1940 = *(temp_r4_1926 + (temp_r0_1924 * 4));
            }
            if (var_r0_1940 == 3) {
                sp220 = -1.0f;
                sp210 = 1.0f;
                sp218 = -1.0f;
                sp21C = 0.0f;
                sp208 = 1.0f;
                sp20C = 1.0f;
                sp5B8 = (f64) sp218;
                sp5C0 = (f64) sp220;
                sp5A8 = (f64) sp208;
                sp5B0 = (f64) sp210;
                KDRand_Vector(sp5C8, *((MKVector3 *) &sp5B8));
                temp_f0_1972 = sp5C8 + M2C_FIELD(&arg2, f64 *, 0);
                sp1F8 = temp_f0_1972;
                sp5D8 = temp_f0_1972;
                sp200 = sp5C8.unk8 + arg2.unk8;
                sp5E0 = (f64) sp200;
                temp_f0_1984 = temp_f0_1972 * 5.70130949e-315;
                sp1E8 = temp_f0_1984;
                sp858 = temp_f0_1984;
                sp1F0 = (f32) sp5E0 * 1600.0f;
                sp860 = (f64) sp1F0;
                temp_f20_1997 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                temp_f15_2002 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                sp1B8 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                sp1BC = temp_f15_2002;
                sp1C0 = temp_f20_1997;
                sp558 = (f64) sp1B8;
                sp560 = (f64) sp1C0;
                sp1A8 = sp558 * 5.53552857e-315;
                sp1E0 = 0.0f;
                sp1B0 = (f32) sp560 * 100.0f;
                sp1D8 = 0.0f;
                sp1DC = -100.0f;
                sp568 = sp1A8;
                sp578 = (f64) sp1D8;
                sp570 = (f64) sp1B0;
                sp580 = (f64) sp1E0;
                temp_f0_2037 = this->unk148.unkB8 + sp578;
                sp1C8 = temp_f0_2037;
                sp588 = temp_f0_2037;
                sp1D0 = M2C_FIELD(this, f32 *, 0x208) + (f32) sp580;
                sp590 = (f64) sp1D0;
                temp_f0_2049 = sp588 + sp568;
                sp198 = temp_f0_2049;
                sp598 = temp_f0_2049;
                sp1A0 = (f32) sp590 + (f32) sp570;
                sp5A0 = (f64) sp1A0;
                ((ElectricSparks *) (M2C_FIELD(&gb, ElectricSparks **, 0x230)))->Emit(*((MKVector3 *) &sp598), *((MKVector3 *) &sp858), 2.0f, 0U);
            }
        }
        if ((arg6 != 0) && (temp_r3_1501 != 0)) {
            if ((sp920.unk50 != 0) && (sp920.unk48 != NULL) && (var_r3_2078 = M2C_FIELD(sp920.unk48, void **, 8), ((var_r3_2078 == NULL) == 0))) {

            } else {
                var_r3_2078 = NULL;
            }
            if (var_r3_2078 != NULL) {
                streamHitMsg.unk50 = 0;
                M2C_FIELD(&streamHitMsg, f64 *, 0x10) = sp888;
                M2C_FIELD(&streamHitMsg, f64 *, 0x18) = sp890;
                streamHitMsg.unk30 = (MKCollisionInfo *) sp920.unk48;
                M2C_FIELD(M2C_FIELD(var_r3_2078, void **, 0x44), M2C_UNK (**)(BreathHitMessage *, M2C_UNK, f64), 0x2C)(&streamHitMsg, 0, sp888);
            }
        } else {
            temp_f3_2103 = &arg4;
            temp_f0_2108 = M2C_FIELD(&arg2, f64 *, 0) * (f64) temp_f3_2103;
            sp78 = temp_f0_2108;
            sp518 = temp_f0_2108;
            sp80 = arg2.unk8 * temp_f3_2103;
            sp520 = (f64) sp80;
            temp_f0_2118 = temp_f0_2108 * (f64) sp2C;
            sp188 = temp_f0_2118;
            sp528 = temp_f0_2118;
            sp190 = (f32) sp520 * sp2C;
            sp530 = (f64) sp190;
            temp_f0_2129 = temp_f0_2118 * 5.28426686e-315;
            sp178 = temp_f0_2129;
            sp538 = temp_f0_2129;
            sp180 = (f32) sp530 * 1.5f;
            sp540 = (f64) sp180;
            temp_f0_2140 = sp538 + M2C_FIELD(&arg3, f64 *, 0);
            sp168 = temp_f0_2140;
            sp548 = temp_f0_2140;
            sp170 = (f32) sp540 + arg3.unk8;
            sp550 = (f64) sp170;
            CreateCollisionTest(arg1, *((MKVector3 *) &sp548), M2C_BITWISE(f32, this->unk264), 0x04000000U, FlameBreathFXHitCallback);
        }
        temp_r4_2159 = this->unkDC;
        if (temp_r4_2159 != NULL) {
            temp_r4_2159->unk0 = M2C_FIELD(&arg1, f64 *, 0);
            temp_r4_2159->unk8 = (f64) M2C_FIELD(&arg1, f32 *, 8);
            this->unkDC->unk24 = MKRand_Float(&gViewSeed, 0.45f, 0.5f);
            temp_r3_2173 = this->unkDC;
            temp_r3_2173->unk31 |= 0x40;
        }
        temp_r4_2178 = this->unkA8;
        if (temp_r4_2178 != NULL) {
            ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->EnableLight(temp_r4_2178, 1U);
            MKVector(0.0f, 300.0f, 0.0f);
            sp4E8.operator*(0.5f * sp2C);
            temp_f0_2199 = M2C_FIELD(&arg1, f64 *, 0) + M2C_BITWISE(f64, sp4E8);
            sp38 = temp_f0_2199;
            sp4F8 = temp_f0_2199;
            sp40 = arg1.unk8 + sp4E8.unk8;
            sp500 = (f64) sp40;
            sp68 = sp4F8 + sp4D8;
            temp_r3_2217 = this->unkA8;
            sp508 = sp68;
            sp70 = (f32) sp500 + sp4E0;
            temp_r3_2217->unk10 = sp68;
            temp_r3_2217->unk18 = (f64) sp70;
            temp_r3_2223 = temp_r3_2217->unk3C;
            sp510 = (f64) sp70;
            if (temp_r3_2223 != NULL) {
                M2C_FIELD(temp_r3_2223, f64 *, 0x10) = sp68;
                M2C_FIELD(temp_r3_2223, f64 *, 0x18) = (f64) sp70;
            }
            sp58 = 1.0f;
            temp_r3_2233 = this->unkA8;
            sp5C = 1.0f;
            sp60 = 0.0f;
            sp64 = 1.0f;
            temp_r3_2233->unk20 = (f64) sp58;
            temp_r3_2233->unk28 = (f64) sp60;
            temp_r3_2241 = temp_r3_2233->unk3C;
            sp4C8 = (f64) sp58;
            sp4D0 = (f64) sp60;
            if (temp_r3_2241 != NULL) {
                M2C_FIELD(temp_r3_2241, f64 *, 0) = (f64) sp58;
                M2C_FIELD(temp_r3_2241, f64 *, 8) = (f64) sp60;
            }
        }
        this->unkB4 = 1;
        this->unkBC = 1;
        temp_f1_2253 = this->unk148.unk100;
        if (temp_f1_2253 > 0.0f) {
            var_r22_2259 = 0;
            temp_f5_2260 = temp_f1_2253 / 1.5f;
            temp_f14_2266 = (0.65f * temp_f5_2260) + 0.1f;
            temp_f18_2267 = arg2.unk8;
            temp_f15_2269 = arg3.unk8;
            temp_f21_2270 = 2.0f * &arg4;
loop_144:
            if (var_r22_2259 < (s32) (f32) ceil(5.0f * temp_f5_2260)) {
                temp_f23_2278 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                temp_f22_2283 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                sp158 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                sp15C = temp_f22_2283;
                sp160 = temp_f23_2278;
                sp488 = (f64) sp158;
                sp490 = (f64) sp160;
                temp_f0_2296 = sp488 * (f64) sp30;
                sp148 = temp_f0_2296;
                sp498 = temp_f0_2296;
                sp150 = (f32) sp490 * sp30;
                sp4A0 = (f64) sp150;
                var_f4_2312 = ((f32) sp4A0 * (f32) sp4A0) + (((f32) sp498 * (f32) sp498) + (unksp49C * unksp49C));
                if (var_f4_2312 > 1e-12f) {
                    if (var_f4_2312 > 0.0f) {
                        temp_f1_2318 = __frsqrte(var_f4_2312);
                        temp_f1_2324 = 0.5 * temp_f1_2318 * -(((f64) var_f4_2312 * (temp_f1_2318 * temp_f1_2318)) - 3.0);
                        temp_f1_2328 = 0.5 * temp_f1_2324 * -(((f64) var_f4_2312 * (temp_f1_2324 * temp_f1_2324)) - 3.0);
                        var_f4_2312 = (f32) ((f64) var_f4_2312 * (0.5 * temp_f1_2328 * -(((f64) var_f4_2312 * (temp_f1_2328 * temp_f1_2328)) - 3.0)));
                    } else if (var_f4_2312 < M2C_BITWISE(f32, 0.0)) {
                        var_f4_2312 = __float_nan;
                    } else {
                        sp10 = var_f4_2312;
                        temp_r3_2347 = M2C_BITWISE(s32, sp10) & 0x7F800000;
                        switch (temp_r3_2347) {     /* switch 4; irregular */
                        case 0x7F800000:            /* switch 4 */
                            if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                                var_r0_2357 = 1;
                            } else {
                                var_r0_2357 = 2;
                            }
                            break;
                        case 0x0:                   /* switch 4 */
                            if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                                var_r0_2357 = 5;
                            } else {
                                var_r0_2357 = 3;
                            }
                            break;
                        default:                    /* switch 4 */
                            var_r0_2357 = 4;
                            break;
                        }
                        if (var_r0_2357 == 1) {
                            var_f4_2312 = __float_nan;
                        }
                    }
                    var_f3_2379 = 1.0f / var_f4_2312;
                } else {
                    var_f3_2379 = 0.0f;
                }
                sp118 = (f32) sp498 * var_f3_2379;
                sp11C = unksp49C * var_f3_2379;
                sp120 = (f32) sp4A0 * var_f3_2379;
                sp4A8 = (f64) sp118;
                sp4B0 = (f64) sp120;
                temp_f0_2398 = sp4A8 * (f64) temp_f14_2266;
                sp138 = temp_f0_2398;
                sp4B8 = temp_f0_2398;
                sp140 = (f32) sp4B0 * temp_f14_2266;
                sp4C0 = (f64) sp140;
                temp_f0_2409 = M2C_FIELD(&arg2, f64 *, 0) + temp_f0_2398;
                sp128 = temp_f0_2409;
                sp848 = temp_f0_2409;
                sp130 = temp_f18_2267 + (f32) sp4C0;
                sp850 = (f64) sp130;
                temp_f17_2422 = MKRand_Float(&gViewSeed, 0.8f, 1.0f);
                temp_f26_2424 = &arg4;
                temp_f0_2426 = sp848 * (f64) temp_f26_2424;
                sp48 = temp_f0_2426;
                sp448 = temp_f0_2426;
                sp50 = (f32) sp850 * temp_f26_2424;
                sp450 = (f64) sp50;
                temp_f0_2436 = temp_f0_2426 * (f64) sp2C;
                sp108 = temp_f0_2436;
                sp458 = temp_f0_2436;
                sp110 = (f32) sp450 * sp2C;
                sp460 = (f64) sp110;
                temp_f0_2446 = temp_f0_2436 * (f64) temp_f17_2422;
                spF8 = temp_f0_2446;
                sp468 = temp_f0_2446;
                sp100 = (f32) sp460 * temp_f17_2422;
                sp470 = (f64) sp100;
                spE8 = sp468 + M2C_FIELD(&arg3, f64 *, 0);
                sp478 = spE8;
                spF0 = (f32) sp470 + temp_f15_2269;
                sp1C = temp_f21_2270 * sp30;
                sp480 = (f64) spF0;
                this->unkAC->Emit(arg1, *((MKVector3 *) &sp478), sp1C);
                var_r22_2259 += 1;
                goto loop_144;
            }
        }
        temp_r3_2486 = M2C_FIELD(GameData::gameData, s32 *, 0x158) << 5;
        temp_r0_2488 = *(&GameData::gameData[0x70] + (temp_r3_2486 + 0x7C));
        temp_r4_2490 = &GameData::gameData[0x70] + (temp_r3_2486 + 0x64);
        if (temp_r0_2488 == 3) {
            var_r3_2494 = 0;
            if (((s32) M2C_FIELD(temp_r4_2490, s32 *, 0) == 3) && ((s32) M2C_FIELD(temp_r4_2490, s32 *, 4) == 3)) {
                var_r3_2494 = 1;
            }
            var_r0_2504 = var_r3_2494 != 0;
        } else {
            var_r0_2504 = *(temp_r4_2490 + (temp_r0_2488 * 4));
        }
        if (var_r0_2504 == 3) {
            spE0 = -1.0f;
            spD0 = 1.0f;
            spD8 = -1.0f;
            spDC = -1.0f;
            spC8 = 1.0f;
            spCC = 1.0f;
            sp418 = (f64) spD8;
            sp420 = (f64) spE0;
            sp408 = (f64) spC8;
            sp410 = (f64) spD0;
            KDRand_Vector(sp428, *((MKVector3 *) &sp418));
            temp_f0_2535 = sp428 + M2C_FIELD(&arg2, f64 *, 0);
            spB8 = temp_f0_2535;
            sp438 = temp_f0_2535;
            spC0 = sp428.unk8 + arg2.unk8;
            sp440 = (f64) spC0;
            temp_f0_2547 = temp_f0_2535 * 5.634608575e-315;
            spA8 = temp_f0_2547;
            sp838 = temp_f0_2547;
            spB0 = (f32) sp440 * 500.0f;
            sp840 = (f64) spB0;
            ((ElectricSparks *) (M2C_FIELD(&gb, ElectricSparks **, 0x230)))->Emit(arg1, *((MKVector3 *) &sp838), 1.0f, 0U);
        }
        this->unkB4 = 1;
        return 1;
    case 1:                                         /* switch 1 */
        if (this->unk13C <= 0.0f) {
            this->unkD8 = 0.0f;
            if (ShootFireBomb(arg1, arg2, arg3, arg_sp8) != 0) {
                this->unk13C = 1.0f;
                return 1;
            }
        }
    case 2:                                         /* switch 1 */
    default:                                        /* switch 1 */
        return 0;
    case 3:                                         /* switch 1 */
        var_r3_2589 = 0;
        temp_r4_2595 = &GameData::gameData[0x70] + ((M2C_FIELD(GameData::gameData, s32 *, 0x158) << 5) + 0x64);
        if (((s32) M2C_FIELD(temp_r4_2595, s32 *, 0) == 3) && ((s32) M2C_FIELD(temp_r4_2595, s32 *, 4) == 3)) {
            var_r3_2589 = 1;
        }
        if (var_r3_2589 == 0) {
            return this->unk260->Trigger(arg1, 0U, 0U, (HeroHurtReactionType) 1);
        }
        this->unk260->Trigger(arg1, 1U, 0U, (HeroHurtReactionType) 1);
        return this->unk260->Trigger(arg1);
    }
}
#endif

void FlameBreathFXHitCallback(BreathFXCollisionSphereTest *arg0) {
    f64 temp_f1_2685;
    void *temp_r5_2678;

    if (arg0 != NULL) {
        temp_r5_2678 = arg0->unk3C;
        if (temp_r5_2678 != NULL) {
            streamHitMsg.unk50 = 0;
            temp_f1_2685 = arg0->unk0;
            M2C_FIELD(&streamHitMsg, f64 *, 0x10) = temp_f1_2685;
            M2C_FIELD(&streamHitMsg, f64 *, 0x18) = (f64) arg0->unk8;
            streamHitMsg.unk30 = (MKCollisionInfo *) arg0->unk40;
            M2C_FIELD(M2C_FIELD(temp_r5_2678, void **, 0x44), M2C_UNK (**)(void *, BreathHitMessage *, f64), 0x2C)(temp_r5_2678, &streamHitMsg, temp_f1_2685);
        }
    }
}

void FlameBreathFX::DrawFlameBreath() {

}

void FlameBreathFX::Deinit() {
    Corona *temp_r4_2729;
    MKMaterial *temp_r3_2739;
    ManagedLight *temp_r4_2717;

    temp_r4_2717 = this->unkA8;
    if (temp_r4_2717 != NULL) {
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->EnableLight(temp_r4_2717, 0U);
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->FreeManagedLight(this->unkA8);
    }
    temp_r4_2729 = this->unkDC;
    if (temp_r4_2729 != NULL) {
        ((Coronas *) (M2C_FIELD(&gb, Coronas **, 0x64)))->Free(temp_r4_2729);
        this->unkDC = NULL;
    }
    temp_r3_2739 = this->unkE0;
    if (temp_r3_2739 != NULL) {
        MKMaterial_Destroy(temp_r3_2739);
    }
    this->unk148.Deinit();
    this->unk140.Deinit();
    BaseBreathFX::Deinit();
}

void FlameBreathFX::Draw() {
    if (EventCamera_GetCurrent() == NULL) {
        DrawFlameBreath();
        this->unk148.Draw();
    }
}

#if 0 // DRAFT: undefined identifier 'unksp2FC'
void FlameBreathFX::Update() {
    f64 sp300;
    f64 sp2F8;
    f64 sp2F0;
    f64 sp2E8;
    f64 sp2E0;
    f64 sp2D8;
    f64 sp2D0;
    f64 sp2C8;
    f64 sp2C0;
    f64 sp2B8;
    f64 sp2B0;
    f64 sp2A8;
    MKVector4 sp298;
    f64 sp290;
    f64 sp288;
    f64 sp280;
    f64 sp278;
    MKVector4 sp268;
    f32 sp264;
    f32 sp260;
    f32 sp25C;
    f32 sp258;
    f64 sp250;
    f64 sp248;
    f64 sp240;
    f64 sp238;
    f64 sp230;
    f64 sp228;
    f64 sp220;
    f64 sp218;
    f64 sp210;
    f64 sp208;
    f32 sp204;
    f32 sp200;
    f32 sp1FC;
    f32 sp1F8;
    f32 sp1F4;
    f32 sp1F0;
    f32 sp1EC;
    f32 sp1E8;
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
    f32 sp194;
    f32 sp190;
    f32 sp18C;
    f32 sp188;
    f32 sp184;
    f32 sp180;
    f32 sp17C;
    f32 sp178;
    f64 sp170;
    f64 sp168;
    f64 sp160;
    f64 sp158;
    f64 sp150;
    f64 sp148;
    f64 sp140;
    f64 sp138;
    f64 sp130;
    f64 sp128;
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
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f64 sp20;
    f64 sp18;
    f64 sp10;
    f64 sp8;
    Corona *temp_r4_3003;
    ManagedLight *temp_r3_2955;
    ManagedLight *temp_r3_3012;
    ManagedLight *temp_r3_3123;
    ManagedLight *temp_r3_3178;
    ManagedLight *temp_r3_3305;
    ManagedLight *temp_r3_3335;
    ManagedLight *temp_r4_2852;
    f32 temp_f0_2968;
    f32 temp_f0_3024;
    f32 temp_f0_3179;
    f32 temp_f0_3206;
    f32 temp_f0_3336;
    f32 temp_f1_2963;
    f32 temp_f1_2966;
    f32 temp_f1_3160;
    f32 temp_f1_3400;
    f32 temp_f2_3169;
    f32 temp_f2_3171;
    f32 temp_f2_3326;
    f32 temp_f2_3330;
    f32 temp_f4_2863;
    f32 temp_f6_3029;
    f32 temp_f6_3211;
    f32 var_f0_3404;
    f32 var_f2_2956;
    f32 var_f2_3147;
    f32 var_f31_2874;
    f32 var_f31_3046;
    f32 var_f31_3228;
    f32 var_f3_3161;
    f32 var_f3_3318;
    f64 temp_f0_2886;
    f64 temp_f0_2896;
    f64 temp_f0_2906;
    f64 temp_f0_2916;
    f64 temp_f0_2926;
    f64 temp_f0_2936;
    f64 temp_f0_3057;
    f64 temp_f0_3067;
    f64 temp_f0_3077;
    f64 temp_f0_3087;
    f64 temp_f0_3097;
    f64 temp_f0_3107;
    f64 temp_f0_3239;
    f64 temp_f0_3249;
    f64 temp_f0_3259;
    f64 temp_f0_3269;
    f64 temp_f0_3279;
    f64 temp_f0_3289;
    f64 temp_f2_2880;
    f64 temp_f4_2885;
    s32 temp_r0_3368;
    void *temp_r3_2942;
    void *temp_r3_2970;
    void *temp_r3_3128;
    void *temp_r3_3181;
    void *temp_r3_3310;
    void *temp_r3_3338;

    BaseBreathFX::Update();
    this->unk140.Update();
    this->unk144 -= gUpdateTimeDelta;
    this->unk13C -= gUpdateTimeDelta;
    if ((((u8) this->unkB4 == 0) || (((s32) this->unk130 == 0) && (this->unk134 <= 0.0f))) && ((u8) this->unk148.unk108 != 0)) {
        this->unk148.unk104 = 0.5f;
    }
    if (((s32) this->unk130 == 0) && (this->unk134 <= 0.0f)) {
        this->unk148.unk108 = 0;
    } else {
        this->unk148.unk108 = this->unkB4;
    }
    this->unk148.Update();
    if (((u8) this->unkB4 == 0) || (((s32) this->unk130 == 0) && (this->unk134 <= 0.0f)) || (EventCamera_GetCurrent() != NULL)) {
        temp_r4_2852 = this->unkA8;
        if (temp_r4_2852 != NULL) {
            sp258 = 0.0f;
            temp_f4_2863 = 0.5f * (2.5f * gUpdateTimeDelta);
            sp25C = 0.0f;
            sp260 = 0.0f;
            sp264 = 1.0f;
            sp2C8 = (f64) sp258;
            sp2D0 = (f64) sp260;
            if (temp_f4_2863 < 1.0f) {
                var_f31_2874 = temp_f4_2863;
            } else {
                var_f31_2874 = 1.0f;
            }
            temp_f2_2880 = temp_r4_2852->unk20;
            sp118 = sp2C8 - temp_f2_2880;
            temp_f4_2885 = temp_r4_2852->unk28;
            temp_f0_2886 = sp2D0 - temp_f4_2885;
            sp120 = temp_f0_2886;
            sp228 = sp118;
            sp230 = temp_f0_2886;
            sp108 = sp228 * (f64) var_f31_2874;
            temp_f0_2896 = temp_f0_2886 * (f64) var_f31_2874;
            sp110 = temp_f0_2896;
            sp218 = sp108;
            sp220 = temp_f0_2896;
            spF8 = temp_f2_2880 + sp218;
            temp_f0_2906 = temp_f4_2885 + temp_f0_2896;
            sp100 = temp_f0_2906;
            sp208 = spF8;
            sp210 = temp_f0_2906;
            spE8 = sp2C8 - sp208;
            temp_f0_2916 = sp2D0 - sp210;
            spF0 = temp_f0_2916;
            sp248 = spE8;
            sp250 = temp_f0_2916;
            spD8 = sp248 * (f64) var_f31_2874;
            temp_f0_2926 = temp_f0_2916 * (f64) var_f31_2874;
            spE0 = temp_f0_2926;
            sp238 = spD8;
            sp240 = temp_f0_2926;
            spC8 = sp208 + sp238;
            temp_f0_2936 = sp210 + temp_f0_2926;
            spD0 = temp_f0_2936;
            temp_r4_2852->unk20 = spC8;
            temp_r4_2852->unk28 = temp_f0_2936;
            temp_r3_2942 = temp_r4_2852->unk3C;
            sp2F8 = spC8;
            sp300 = temp_f0_2936;
            if (temp_r3_2942 != NULL) {
                M2C_FIELD(temp_r3_2942, f64 *, 0) = spC8;
                M2C_FIELD(temp_r3_2942, f64 *, 8) = temp_f0_2936;
            }
            temp_r3_2955 = this->unkA8;
            var_f2_2956 = 0.5f * (2.5f * gUpdateTimeDelta);
            if (var_f2_2956 < 1.0f) {

            } else {
                var_f2_2956 = 1.0f;
            }
            temp_f1_2963 = temp_r3_2955->unk38;
            temp_f1_2966 = (var_f2_2956 * (0.0f - temp_f1_2963)) + temp_f1_2963;
            temp_f0_2968 = (var_f2_2956 * (0.0f - temp_f1_2966)) + temp_f1_2966;
            temp_r3_2955->unk38 = temp_f0_2968;
            temp_r3_2970 = temp_r3_2955->unk3C;
            if (temp_r3_2970 != NULL) {
                M2C_FIELD(temp_r3_2970, f32 *, 0x20) = temp_f0_2968;
                M2C_FIELD(temp_r3_2970, f32 *, 0x24) = (f32) (temp_f0_2968 * temp_f0_2968);
                M2C_FIELD(temp_r3_2970, f32 *, 0x28) = (f32) (1.0f / temp_f0_2968);
                M2C_FIELD(temp_r3_2970, f32 *, 0x2C) = (f32) (1.0f / M2C_FIELD(temp_r3_2970, f32 *, 0x24));
            }
            if (((f32) sp2F8 <= 0.05f) && (unksp2FC <= 0.05f) && ((f32) sp300 <= 0.05f)) {
                ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->EnableLight(this->unkA8, 0U);
            }
        }
        temp_r4_3003 = this->unkDC;
        if (temp_r4_3003 != NULL) {
            temp_r4_3003->unk31 &= ~0x40;
        }
    } else {
        temp_r3_3012 = this->unkA8;
        if ((temp_r3_3012 != NULL) && ((s32) this->unkBC == 1)) {
            temp_f0_3024 = MKRand_Float(&gViewSeed, 0.2f, 0.6f) * 1.0f;
            sp1E8 = 1.0f;
            sp1EC = 0.0f;
            temp_f6_3029 = 0.5f * temp_f0_3024;
            sp1F0 = 0.0f;
            sp1F4 = 1.0f;
            sp1F8 = 1.0f;
            sp1FC = 1.0f;
            sp200 = 0.0f;
            sp204 = 1.0f;
            sp2A8 = (f64) sp1E8;
            sp2B0 = (f64) sp1F0;
            sp2B8 = (f64) sp1F8;
            sp2C0 = (f64) sp200;
            if (temp_f6_3029 < 1.0f) {
                var_f31_3046 = temp_f6_3029;
            } else {
                var_f31_3046 = 1.0f;
            }
            spB8 = sp2A8 - sp2B8;
            temp_f0_3057 = sp2B0 - sp2C0;
            spC0 = temp_f0_3057;
            sp1B8 = spB8;
            sp1C0 = temp_f0_3057;
            spA8 = sp1B8 * (f64) var_f31_3046;
            temp_f0_3067 = temp_f0_3057 * (f64) var_f31_3046;
            spB0 = temp_f0_3067;
            sp1A8 = spA8;
            sp1B0 = temp_f0_3067;
            sp98 = sp2B8 + sp1A8;
            temp_f0_3077 = sp2C0 + temp_f0_3067;
            spA0 = temp_f0_3077;
            sp198 = sp98;
            sp1A0 = temp_f0_3077;
            sp88 = sp2A8 - sp198;
            temp_f0_3087 = sp2B0 - sp1A0;
            sp90 = temp_f0_3087;
            sp1D8 = sp88;
            sp1E0 = temp_f0_3087;
            sp78 = sp1D8 * (f64) var_f31_3046;
            temp_f0_3097 = temp_f0_3087 * (f64) var_f31_3046;
            sp80 = temp_f0_3097;
            sp1C8 = sp78;
            sp1D0 = temp_f0_3097;
            sp68 = sp198 + sp1C8;
            temp_f0_3107 = sp1A0 + temp_f0_3097;
            sp70 = temp_f0_3107;
            sp2E8 = sp68;
            sp2F0 = temp_f0_3107;
            KDMath_Smooth<MKVector4>(sp298, this->unkC8, 0.5f, 1.0f);
            M2C_FIELD(this, f64 *, 0xC8) = M2C_BITWISE(f64, sp298);
            M2C_FIELD(this, f64 *, 0xD0) = (f64) sp298.unk8;
            temp_r3_3123 = this->unkA8;
            temp_r3_3123->unk20 = M2C_FIELD(this, f64 *, 0xC8);
            temp_r3_3123->unk28 = M2C_FIELD(this, f64 *, 0xD0);
            temp_r3_3128 = temp_r3_3123->unk3C;
            if (temp_r3_3128 != NULL) {
                M2C_FIELD(temp_r3_3128, f64 *, 0) = (f64) M2C_FIELD(this, f64 *, 0xC8);
                M2C_FIELD(temp_r3_3128, f64 *, 8) = (f64) M2C_FIELD(this, f64 *, 0xD0);
            }
            if ((s32) this->unkBC == 0) {
                var_f2_3147 = 2.0f * ((this->unkC0 / 0.75f) - 0.5f);
                if (var_f2_3147 < 0.0f) {
                    var_f2_3147 = -var_f2_3147;
                }
                this->unkD8 = 1.0f + (1.0f - var_f2_3147);
            } else {
                temp_f1_3160 = MKRand_Float(&gViewSeed, 0.8f, 1.0f);
                var_f3_3161 = 0.125f;
                if (1.0f > 0.125f) {

                } else {
                    var_f3_3161 = 1.0f;
                }
                temp_f2_3169 = this->unkD8;
                temp_f2_3171 = (var_f3_3161 * (temp_f1_3160 - temp_f2_3169)) + temp_f2_3169;
                this->unkD8 = (var_f3_3161 * (temp_f1_3160 - temp_f2_3171)) + temp_f2_3171;
            }
            temp_r3_3178 = this->unkA8;
            temp_f0_3179 = 1000.0f * this->unkD8;
            temp_r3_3178->unk38 = temp_f0_3179;
            temp_r3_3181 = temp_r3_3178->unk3C;
            if (temp_r3_3181 != NULL) {
                M2C_FIELD(temp_r3_3181, f32 *, 0x20) = temp_f0_3179;
                M2C_FIELD(temp_r3_3181, f32 *, 0x24) = (f32) (temp_f0_3179 * temp_f0_3179);
                M2C_FIELD(temp_r3_3181, f32 *, 0x28) = (f32) (1.0f / temp_f0_3179);
                M2C_FIELD(temp_r3_3181, f32 *, 0x2C) = (f32) (1.0f / M2C_FIELD(temp_r3_3181, f32 *, 0x24));
            }
        } else if ((temp_r3_3012 != NULL) && ((s32) this->unkBC == 2)) {
            temp_f0_3206 = MKRand_Float(&gViewSeed, 0.2f, 0.6f) * 1.0f;
            sp178 = 1.0f;
            sp17C = 0.0f;
            temp_f6_3211 = 0.5f * temp_f0_3206;
            sp180 = 0.0f;
            sp184 = 1.0f;
            sp188 = 1.0f;
            sp18C = 1.0f;
            sp190 = 0.0f;
            sp194 = 1.0f;
            sp278 = (f64) sp178;
            sp280 = (f64) sp180;
            sp288 = (f64) sp188;
            sp290 = (f64) sp190;
            if (temp_f6_3211 < 1.0f) {
                var_f31_3228 = temp_f6_3211;
            } else {
                var_f31_3228 = 1.0f;
            }
            sp58 = sp278 - sp288;
            temp_f0_3239 = sp280 - sp290;
            sp60 = temp_f0_3239;
            sp148 = sp58;
            sp150 = temp_f0_3239;
            sp48 = sp148 * (f64) var_f31_3228;
            temp_f0_3249 = temp_f0_3239 * (f64) var_f31_3228;
            sp50 = temp_f0_3249;
            sp138 = sp48;
            sp140 = temp_f0_3249;
            sp38 = sp288 + sp138;
            temp_f0_3259 = sp290 + temp_f0_3249;
            sp40 = temp_f0_3259;
            sp128 = sp38;
            sp130 = temp_f0_3259;
            sp28 = sp278 - sp128;
            temp_f0_3269 = sp280 - sp130;
            sp30 = temp_f0_3269;
            sp168 = sp28;
            sp170 = temp_f0_3269;
            sp18 = sp168 * (f64) var_f31_3228;
            temp_f0_3279 = temp_f0_3269 * (f64) var_f31_3228;
            sp20 = temp_f0_3279;
            sp158 = sp18;
            sp160 = temp_f0_3279;
            sp8 = sp128 + sp158;
            temp_f0_3289 = sp130 + temp_f0_3279;
            sp10 = temp_f0_3289;
            sp2D8 = sp8;
            sp2E0 = temp_f0_3289;
            KDMath_Smooth<MKVector4>(sp268, this->unkC8, 0.5f, 1.0f);
            M2C_FIELD(this, f64 *, 0xC8) = M2C_BITWISE(f64, sp268);
            M2C_FIELD(this, f64 *, 0xD0) = (f64) sp268.unk8;
            temp_r3_3305 = this->unkA8;
            temp_r3_3305->unk20 = M2C_FIELD(this, f64 *, 0xC8);
            temp_r3_3305->unk28 = M2C_FIELD(this, f64 *, 0xD0);
            temp_r3_3310 = temp_r3_3305->unk3C;
            if (temp_r3_3310 != NULL) {
                M2C_FIELD(temp_r3_3310, f64 *, 0) = (f64) M2C_FIELD(this, f64 *, 0xC8);
                M2C_FIELD(temp_r3_3310, f64 *, 8) = (f64) M2C_FIELD(this, f64 *, 0xD0);
            }
            var_f3_3318 = 0.125f;
            if (1.0f > 0.125f) {

            } else {
                var_f3_3318 = 1.0f;
            }
            temp_f2_3326 = this->unkD8;
            temp_f2_3330 = (var_f3_3318 * (0.0f - temp_f2_3326)) + temp_f2_3326;
            this->unkD8 = (var_f3_3318 * (0.0f - temp_f2_3330)) + temp_f2_3330;
            temp_r3_3335 = this->unkA8;
            temp_f0_3336 = 1000.0f * this->unkD8;
            temp_r3_3335->unk38 = temp_f0_3336;
            temp_r3_3338 = temp_r3_3335->unk3C;
            if (temp_r3_3338 != NULL) {
                M2C_FIELD(temp_r3_3338, f32 *, 0x20) = temp_f0_3336;
                M2C_FIELD(temp_r3_3338, f32 *, 0x24) = (f32) (temp_f0_3336 * temp_f0_3336);
                M2C_FIELD(temp_r3_3338, f32 *, 0x28) = (f32) (1.0f / temp_f0_3336);
                M2C_FIELD(temp_r3_3338, f32 *, 0x2C) = (f32) (1.0f / M2C_FIELD(temp_r3_3338, f32 *, 0x24));
            }
        }
        if ((s32) this->unk130 == 0) {
            this->unk134 -= gUpdateTimeDelta;
        }
    }
    if (((u8) this->unkB4 != 0) && ((s32) this->unkB8 == 0) && (EventCamera_GetCurrent() == NULL)) {
        temp_r0_3368 = this->unk130;
        if (((temp_r0_3368 == 0) && (this->unk134 >= 0.0f)) || ((temp_r0_3368 != 0) && (this->unk138 >= 0.0f))) {
            ((KDInput *) (M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), KDInput *(**)(void **), 0x40)(M2C_FIELD(&gb, void ***, 0))))->RumblePlay(0.05f, 0.0f, 0.04f, 0, 4.0f, 0U);
        }
        temp_f1_3400 = this->unk138;
        if (temp_f1_3400 < -0.5f) {
            var_f0_3404 = 2.0f;
        } else {
            var_f0_3404 = temp_f1_3400 - gUpdateTimeDelta;
        }
        this->unk138 = var_f0_3404;
        return;
    }
    this->unk138 = 2.0f;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void *' to
void FlameBreathFX::Resolve() {
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp34;
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
    Corona *temp_r4_3583;

    MKProp::Resolve();
    sp40 = 0.0f;
    sp50 = 0.0f;
    sp28 = 1.0f;
    sp2C = 1.0f;
    sp30 = 1.0f;
    sp34 = 1.0f;
    sp38 = 0.0f;
    sp3C = 0.0f;
    sp48 = 0.0f;
    sp4C = 0.0f;
    sp78 = (f64) sp28;
    sp80 = (f64) sp30;
    sp88 = (f64) sp38;
    sp90 = (f64) sp40;
    sp98 = (f64) sp48;
    spA0 = (f64) sp50;
    this->unkA8 = ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->AllocManagedLight(*((MKVector3 *) &sp98), *((MKVector3 *) &sp88), *((MKVector4 *) &sp78), 300.0f, lit_734, lit_735);
    ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->EnableLight(this->unkA8, 0U);
    sp20 = 0.0f;
    sp8 = 1.0f;
    spC = 0.75f;
    sp10 = 0.0f;
    sp14 = 1.0f;
    sp18 = 0.0f;
    sp1C = 0.0f;
    sp58 = (f64) sp8;
    sp60 = (f64) sp10;
    sp68 = (f64) sp18;
    sp70 = (f64) sp20;
    this->unkDC = ((Coronas *) (M2C_FIELD(&gb, Coronas **, 0x64)))->Alloc(*((MKVector3 *) &sp68), *((MKVector4 *) &sp58), 4.0f, lit_737, lit_738);
    temp_r4_3583 = this->unkDC;
    if (temp_r4_3583 != NULL) {
        temp_r4_3583->unk31 &= ~0x40;
    }
    this->unk268 = M2C_BITWISE(f32, checked_cast<FireBombFXDescriptor *, MKPropDescriptor>(M2C_FIELD(*gMK, MKPropDescriptor *(**)(void **, s8 *), 0x5C)(gMK, "FireBombFX")));
}
#endif

#if 0 // DRAFT: expression syntax error
void FlameBreathFX::Init() {
    f64 sp20;
    f64 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    FireBombFX *temp_r3_3689;
    s32 var_r30_3682;

    BaseBreathFX::Init();
    this->unkB4 = 0;
    this->unkA8 = NULL;
    this->unkAC = checked_cast<FlameBreathPS *, MKProp>(gMK->CreateProp("FlameBreathPS"));
    this->unk94 = 0.0f;
    this->unkBC = 0;
    this->unkC0 = 0.75f;
    sp8 = 1.0f;
    spC = 1.0f;
    this->unk264 = 75.0f;
    sp10 = 0.0f;
    sp14 = 1.0f;
    M2C_FIELD(this, f64 *, 0xC8) = (f64) sp8;
    M2C_FIELD(this, f64 *, 0xD0) = (f64) sp10;
    this->unkD8 = 1.0f;
    this->unkDC = NULL;
    sp18 = (f64) sp8;
    sp20 = (f64) sp10;
    this->unk138 = 2.0f;
    this->unkE0 = MKMaterial_Create("fx_303");
    this->unk144 = 0.0f;
    this->unk148.Init("fx_357", "fx_357Glow", "fx_358", "fx_358Glow");
    this->unk260 = checked_cast<FuryFXFire *, MKProp>(gMK->CreateProp("FuryFXFire"));
    this->unk260 = checked_cast<FuryFXFire2 *, MKProp>(gMK->CreateProp("FuryFXFire2"));
    var_r30_3682 = 0;
    this->unk13C = 0.0f;
    this->unk268 = 0.0f;
    do {
        temp_r3_3689 = checked_cast<FireBombFX *, MKProp>(gMK->CreateProp("FireBombFX"));
        if (temp_r3_3689 != NULL) {
            M2C_FIELD(temp_r3_3689->__vptr, M2C_UNK (**)(), 0x34)();
        }
        var_r30_3682 += 1;
    } while (var_r30_3682 < 8);
    this->unk140.Init(0x19);
}
#endif

void FlameBreathFX_cpp::__sinit() {
    streamHitMsg.unk4 = 0;
}
