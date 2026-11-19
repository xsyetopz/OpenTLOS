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
#include "spyro/source/GameMessages.h"
#include "spyro/source/KDInput.h"
#include "spyro/source/LightManager.h"
#include "spyro/source/ManagedLight.h"
#include "spyro/source/TargetManager.h"
#include "unplaced_templates.h"
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
    M2C_UNK sp240;
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
    M2C_UNK sp120;
    f32 sp118;
    f32 sp108;
    f32 spF8;
    f32 spE8;
    f32 spE4;
    f32 spE0;
    f32 spD8;
    f32 spC8;
    f32 spC4;
    f32 spC0;
    f32 spB8;
    f32 spA8;
    f32 sp98;
    f32 sp94;
    f32 sp90;
    f32 sp88;
    f32 sp84;
    f32 sp80;
    f32 sp78;
    f32 sp68;
    f32 sp58;
    f32 sp48;
    f32 sp38;
    f32 sp28;
    f32 sp18;
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
    f32 var_f0_327;
    f32 var_f25_259;
    f32 var_f26_188;
    f32 var_f27_186;
    f32 var_f4_394;
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
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f25 */);
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
        temp_r3_193 = gameData.unk70.unkE8 << 5;
        temp_r0_195 = *(&gameData.unk70 + (temp_r3_193 + 0x7C));
        temp_r4_197 = &gameData.unk70 + (temp_r3_193 + 0x64);
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
                    sp230 = M2C_FIELD(temp_r3_302, f64 *, 0x30);
                    sp238 = M2C_FIELD(temp_r3_302, f64 *, 0x38);
                    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r30, 0x0, qr0 */);
                    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
                    sp2A0 = sp110;
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
                        M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
                        var_r0_411 = var_f0_327 == (0.5f * this->unkA0);
                    }
                    if (var_r0_411 != 0) {
                        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
                        if ((var_f0_327 == this->unkA0) && (var_f0_327 < var_f25_259)) {
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
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r31, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
            sp210 = sp100;
            sp108 = arg1.unk8 * this->unkA0;
            sp218 = (f64) sp108;
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r30, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
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
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f5, $f0 */);
            spE8 = 0.0f;
            spE0 = 0.0f;
            spE4 = 500.0f;
            spB8 = (f32) sp278 + (f32) sp1D8;
            sp1F0 = (f64) spE0;
            sp1E0 = spB0;
            sp1E8 = (f64) spB8;
            sp1F8 = (f64) spE8;
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f5, $f0 */);
            sp200 = spD0;
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
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r20, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        temp_f1_617 = (f32) sp298 + arg2.unk8;
        sp1B0 = spA0;
        spA8 = temp_f1_617;
        sp1B8 = (f64) spA8;
        temp_r3_141->Fire(arg0, *((MKVector3 *) &sp1B0), var_f26_188, M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), MKProp *(**)(void **, f32, f32), 0xC)(M2C_FIELD(&gb, void ***, 0), temp_f1_617, (f32) sp298), var_r25_190, var_r24_192, 0, *((MKVector3 *) &sp1A0));
        var_r3_638 = 0;
        temp_r4_639 = gameData.unk70.unkE8 << 5;
        temp_r0_641 = *(&gameData.unk70 + (temp_r4_639 + 0x7C));
        temp_r5_643 = &gameData.unk70 + (temp_r4_639 + 0x64);
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
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
            sp190 = sp70;
            sp78 = (f32) sp188 * 0.25f;
            sp198 = (f64) sp78;
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r31, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            sp260 = sp60;
            sp68 = temp_f25_707 + (f32) sp198;
            sp268 = (f64) sp68;
            temp_f29_756 = MKRand_Float(&gViewSeed, 0.8f, 1.0f);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f28 */);
            sp160 = sp50;
            sp58 = (f32) sp268 * 500.0f;
            sp168 = (f64) sp58;
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
            sp170 = sp40;
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
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r30, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            sp140 = sp10;
            sp18 = arg0.unk8 + sp130.unk8;
            sp148 = (f64) sp18;
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
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
    Corona *temp_r3_2173;
    Corona *temp_r4_2159;
    ManagedLight *temp_r3_2217;
    ManagedLight *temp_r3_2233;
    ManagedLight *temp_r4_2178;
    f32 temp_f0_1161;
    f32 temp_f0_1356;
    f32 temp_f0_1437;
    f32 temp_f0_1787;
    f32 temp_f0_2216;
    f32 temp_f0_2389;
    f32 temp_f15_2002;
    f32 temp_f15_2269;
    f32 temp_f16_1042;
    f32 temp_f17_2422;
    f32 temp_f18_2267;
    f32 temp_f1_1201;
    f32 temp_f1_1820;
    f32 temp_f1_2006;
    f32 temp_f1_2253;
    f32 temp_f1_2287;
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
    f32 temp_f2_1209;
    f32 temp_f2_1344;
    f32 temp_f2_1386;
    f32 temp_f2_1835;
    f32 temp_f31_1690;
    f32 temp_f31_1811;
    f32 temp_f3_1570;
    f32 temp_f3_2022;
    f32 temp_f5_2260;
    f32 var_f0_1710;
    f32 var_f3_1150;
    f32 var_f3_1777;
    f32 var_f3_2379;
    f32 var_f4_1083;
    f32 var_f4_2312;
    f64 temp_f1_1089;
    f64 temp_f1_1095;
    f64 temp_f1_1099;
    f64 temp_f1_2318;
    f64 temp_f1_2324;
    f64 temp_f1_2328;
    f64 temp_f2_1716;
    f64 temp_f2_1722;
    f64 temp_f2_1726;
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
        temp_r22_936 = gameData.unk70.unkE8;
        temp_r3_938 = temp_r22_936 << 5;
        temp_r23_940 = *(&gameData.unk70 + (temp_r3_938 + 0x7C));
        temp_r4_942 = &gameData.unk70 + (temp_r3_938 + 0x64);
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
        streamHitMsg.Init(arg0, gameData.unk70.GetBreathAttackDamage(temp_r22_936, temp_r23_940, var_r6_956), temp_r23_940, var_r21_975, temp_r22_936, temp_r22_936, 0, -1);
        if ((u8) M2C_FIELD(&gb, u8 *, 0x3B5) == 0) {
            M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
            if (gameData.unk70.unk30.unk0 == 0.0f) {
                temp_r3_1006 = gameData.unk70.unkE8 << 5;
                temp_r6_1008 = *(&gameData.unk70 + (temp_r3_1006 + 0x7C));
                temp_r4_1010 = &gameData.unk70 + (temp_r3_1006 + 0x64);
                if (temp_r6_1008 == 3) {
                    var_r3_1014 = 0;
                    if (((s32) M2C_FIELD(temp_r4_1010, s32 *, 0) == 3) && ((s32) M2C_FIELD(temp_r4_1010, s32 *, 4) == 3)) {
                        var_r3_1014 = 1;
                    }
                    var_r7_1024 = var_r3_1014 != 0;
                } else {
                    var_r7_1024 = *(temp_r4_1010 + (temp_r6_1008 * 4));
                }
                unksp8 = -1;
                streamHitMsg.Init(arg0, 0, temp_r6_1008, var_r7_1024, gameData.unk70.unkE8, gameData.unk70.unkE8, 0, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
                temp_f16_1042 = arg2.unk8;
                temp_f24_1048 = arg3.unk8;
                var_r22_1051 = 0;
                do {
                    temp_f26_1059 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                    temp_f25_1064 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                    unksp3F8 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                    unksp3FC = temp_f25_1064;
                    unksp400 = temp_f26_1059;
                    unksp808 = unksp3F8;
                    unksp810 = unksp400;
                    var_f4_1083 = (unksp810 * unksp810) + ((unksp808 * unksp808) + (unksp80C * unksp80C));
                    if (var_f4_1083 > 1e-12f) {
                        if (var_f4_1083 > 0.0f) {
                            temp_f1_1089 = __frsqrte(var_f4_1083);
                            temp_f1_1095 = 0.5 * temp_f1_1089 * -(((f64) var_f4_1083 * (temp_f1_1089 * temp_f1_1089)) - 3.0);
                            temp_f1_1099 = 0.5 * temp_f1_1095 * -(((f64) var_f4_1083 * (temp_f1_1095 * temp_f1_1095)) - 3.0);
                            var_f4_1083 = (f32) ((f64) var_f4_1083 * (0.5 * temp_f1_1099 * -(((f64) var_f4_1083 * (temp_f1_1099 * temp_f1_1099)) - 3.0)));
                        } else if (var_f4_1083 < M2C_BITWISE(f32, 0.0)) {
                            var_f4_1083 = __float_nan;
                        } else {
                            unksp18 = var_f4_1083;
                            temp_r3_1118 = unksp18 & 0x7F800000;
                            switch (temp_r3_1118) { /* switch 2; irregular */
                            case 0x7F800000:        /* switch 2 */
                                if (unksp18 & 0x7FFFFF) {
                                    var_r0_1128 = 1;
                                } else {
                                    var_r0_1128 = 2;
                                }
                                break;
                            case 0x0:               /* switch 2 */
                                if (unksp18 & 0x7FFFFF) {
                                    var_r0_1128 = 5;
                                } else {
                                    var_r0_1128 = 3;
                                }
                                break;
                            default:                /* switch 2 */
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
                    temp_f0_1161 = unksp810 * var_f3_1150;
                    unksp3C8 = unksp808 * var_f3_1150;
                    unksp3CC = unksp80C * var_f3_1150;
                    unksp3D0 = temp_f0_1161;
                    unksp818 = unksp3C8;
                    unksp820 = (f64) temp_f0_1161;
                    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r28, 0x0, qr0 */);
                    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f18 */);
                    unksp828 = unksp3E8;
                    unksp3F0 = unksp820 * 0.25f;
                    unksp830 = unksp3F0;
                    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r29, 0x0, qr0 */);
                    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r26, 0x0, qr0 */);
                    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                    unksp898 = unksp3D8;
                    unksp3E0 = temp_f16_1042 + unksp830;
                    unksp8A0 = unksp3E0;
                    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r25, 0x0, qr0 */);
                    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f19 */);
                    temp_f1_1201 = (f32) unksp3E0 * MKRand_Float(&gViewSeed, 300.0f, 600.0f);
                    unksp3C0 = temp_f1_1201;
                    unksp7D8 = unksp3B8;
                    temp_f2_1209 = (f32) var_r22_1051 / 10.0f;
                    unksp7E0 = (f64) temp_f1_1201;
                    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r23, 0x0, qr0 */);
                    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f20 */);
                    unksp7E8 = unksp3A8;
                    unksp3B0 = temp_f1_1201 * temp_f2_1209;
                    unksp7F0 = unksp3B0;
                    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r21, 0x0, qr0 */);
                    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r27, 0x0, qr0 */);
                    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                    unksp7F8 = unksp398;
                    unksp3A0 = unksp7F0 + temp_f24_1048;
                    unksp24 = (2.0f * temp_f2_1209) + 1.0f;
                    unksp800 = unksp3A0;
                    this->unkAC->Emit(arg1, *((MKVector3 *) &unksp7F8), unksp24);
                    var_r22_1051 += 1;
                } while (var_r22_1051 < 0xA);
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r29, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f21 */);
                unksp7B8 = unksp388;
                unksp390 = arg2.unk8 * 300.0f;
                unksp7C0 = unksp390;
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r27, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                unksp7C8 = unksp378;
                unksp380 = unksp7C0 + arg3.unk8;
                unksp7D0 = unksp380;
                CreateCollisionTest(arg1, *((MKVector3 *) &unksp7C8), M2C_BITWISE(f32, this->unk264), 0x04000000U, FlameBreathFXHitCallback);
                KDSound_Play3d(GS_SpyroOutOfBreath, M2C_FIELD(M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), void *(**)(void **), 0xC)(M2C_FIELD(&gb, void ***, 0)), s32 *, 8) + 0x30, 0U, -1, 0.0f, 0U);
                return 1;
            }
        }
        temp_r3_1295 = gameData.unk70.unkE8 << 5;
        temp_r0_1297 = *(&gameData.unk70 + (temp_r3_1295 + 0x7C));
        temp_r4_1299 = &gameData.unk70 + (temp_r3_1295 + 0x64);
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
        GetAttack1UpgradeVariables(this->unk130, unksp30, unksp2C, unksp28);
        this->unk148.unk10C = unksp30;
        unksp350 = 0.0f;
        this->unk148.unk110 = unksp28;
        unksp348 = 0.0f;
        unksp34C = 100.0f;
        unksp790 = unksp350;
        unksp788 = unksp348;
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r29, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
        temp_f2_1344 = arg2.unk8;
        unksp798 = unksp368;
        unksp370 = temp_f2_1344 * unksp2C;
        unksp7A0 = unksp370;
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r30, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        temp_f0_1356 = arg1.unk8;
        unksp7A8 = unksp358;
        unksp360 = temp_f0_1356 + unksp7A0;
        unksp7B0 = unksp360;
        M2C_ERROR(/* unknown instruction: psq_lx $f5, $zero, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f4, $f5, $f4 */);
        unksp888 = unksp338;
        unksp340 = unksp7B0 + unksp790;
        unksp890 = unksp340;
        if ((u8) this->unkB4 == 0) {
            unksp778 = M2C_FIELD(&arg1, f64 *, 0);
            unksp780 = (f64) M2C_FIELD(&arg1, f32 *, 8);
            M2C_ERROR(/* unknown instruction: psq_lx $f4, $zero, $r29, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f4, $f4, $f3 */);
            temp_f2_1386 = temp_f2_1344 * 0.0f;
            unksp330 = temp_f2_1386;
            unksp758 = unksp328;
            unksp760 = (f64) temp_f2_1386;
            M2C_ERROR(/* unknown instruction: ps_add $f1, $f1, $f2 */);
            unksp768 = unksp318;
            unksp320 = temp_f0_1356 + unksp760;
            unksp748 = M2C_FIELD(&arg2, f64 *, 0);
            unksp770 = unksp320;
            unksp750 = (f64) M2C_FIELD(&arg2, f32 *, 8);
            this->unk148.ResetBeamNodes((MKVector3) &unksp778, (MKVector3) &unksp768, (MKVector3) &unksp748);
            this->unk148.unk100 = 1.5f;
            this->unk148.unk104 = 0.5f;
            if ((void *) M2C_FIELD(&gb, void **, 0x3B8) != NULL) {
                unksp8AC = 0;
                MKVector(1.0f, 1.0f, 1.0f);
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f15 */);
                temp_f0_1437 = unksp730 * 50.0f;
                unksp8A8 = 0x417;
                unksp8B0 = unksp98;
                unkspA0 = temp_f0_1437;
                unksp8C0 = 1;
                unksp8B8 = (f64) temp_f0_1437;
                unksp738 = unksp98;
                unksp740 = (f64) temp_f0_1437;
                M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, M2C_UNK *, f64), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &unksp8A8, unksp98);
            }
            if ((s32) this->unk130 == 0) {
                this->unk134 = 1.5f;
            }
            goto block_64;
        }
        if ((s32) this->unk130 == 0) {
            M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
            if (this->unk134 == 0.0f) {
                return 0;
            }
        }
block_64:
        unksp978 = 0.0f;
        unksp97C = 0.0f;
        unksp980 = 0.0f;
        unksp988 = 0.0f;
        unksp98C = 0.0f;
        unksp990 = 0.0f;
        unksp998 = 0.0f;
        unksp99C = 0.0f;
        unksp9A0 = 0.0f;
        unksp9A4 = 1.0f;
        unksp9A8 = 0.0f;
        unksp9AC = 0.0f;
        unksp9B0 = 0;
        unksp9B2 = 0;
        unksp9B3 = 0;
        unksp9B4 = 0;
        unksp9B8 = 3.4028235e38f;
        unksp9BC = 0;
        unksp9C0 = 0;
        unksp9C4 = -1;
        unksp9C8 = 0;
        temp_r3_1501 = MKCollision_RayCollide(arg1, *((MKVector3 *) &unksp888), (MKCollisionResult *) &unksp920, (MKCollisionMode) 7, 0);
        if (temp_r3_1501 != 0) {
            unksp888 = unksp920;
            unksp890 = unksp928;
        }
        if (arg6 != 0) {
            unksp6F8 = M2C_FIELD(&arg2, f64 *, 0);
            unksp700 = (f64) M2C_FIELD(&arg2, f32 *, 8);
            unksp708 = unksp888;
            unksp710 = unksp890;
            unksp718 = M2C_FIELD(&arg1, f64 *, 0);
            unksp720 = (f64) M2C_FIELD(&arg1, f32 *, 8);
            this->unk148.SetBeamPositions((MKVector3) &unksp718, (MKVector3) &unksp708, (MKVector3) &unksp6F8);
        } else {
            unksp6C8 = M2C_FIELD(&arg2, f64 *, 0);
            unksp6D0 = (f64) M2C_FIELD(&arg2, f32 *, 8);
            unksp6D8 = unksp888;
            unksp6E0 = unksp890;
            unksp6E8 = M2C_FIELD(&arg1, f64 *, 0);
            unksp6F0 = (f64) M2C_FIELD(&arg1, f32 *, 8);
            this->unk148.UpdateBeam((MKVector3) &unksp6E8, (MKVector3) &unksp6D8, (MKVector3) &unksp6C8);
        }
        if ((s32) this->unk130 >= 2) {
            M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
            if (this->unk144 == 0.0f) {
                this->unk144 = 0.5f;
                temp_f24_1564 = MKRand_Float(&gViewSeed, 0.1f, 1.0f);
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: psq_lx $f2, $zero, $r30, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_sub $f0, $f0, $f2 */);
                temp_f3_1570 = arg1.unk8;
                unksp6A8 = unksp308;
                unksp310 = unksp890 - temp_f3_1570;
                unksp6B0 = unksp310;
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f24 */);
                unksp6B8 = unksp2F8;
                unksp300 = unksp6B0 * temp_f24_1564;
                unksp6C0 = unksp300;
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f2, $f0 */);
                unksp2F0 = temp_f3_1570 + (f32) unksp300;
                unksp2E0 = 0.0f;
                unksp2D8 = 0.0f;
                unksp2DC = -300.0f;
                unksp878 = unksp2E8;
                unksp688 = unksp2D8;
                unksp880 = unksp2F0;
                unksp8C8 = 0.0f;
                unksp8CC = 0.0f;
                unksp8D0 = 0.0f;
                unksp8D8 = 0.0f;
                unksp8DC = 0.0f;
                unksp8E0 = 0.0f;
                unksp8E8 = 0.0f;
                unksp8EC = 0.0f;
                unksp8F0 = 0.0f;
                unksp8F4 = 1.0f;
                unksp8F8 = 0.0f;
                unksp8FC = 0.0f;
                unksp900 = 0;
                unksp902 = 0;
                unksp903 = 0;
                unksp904 = 0;
                unksp908 = 3.4028235e38f;
                unksp90C = 0;
                unksp910 = 0;
                unksp914 = -1;
                unksp918 = 0;
                unksp690 = unksp2E0;
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r3, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                unksp698 = unksp2C8;
                unksp2D0 = unksp880 + unksp690;
                unksp6A0 = unksp2D0;
                if (MKCollision_RayCollide(*((MKVector3 *) &unksp878), *((MKVector3 *) &unksp698), (MKCollisionResult *) &unksp8C8, (MKCollisionMode) 4, 0x04000000) != 0) {
                    this->unk140.Emit(*((MKVector3 *) &unksp8C8), MKRand_Float(&gViewSeed, 2.0f, 3.0f), 0U);
                }
            }
        }
        if (MKCollision_SphereCollide(*((MKVector3 *) &this->unk148.unkB8), 100.0f, (MKCollisionResult *) &unksp978, 1, (MKCollisionMode) 7, 0) != 0) {
            var_r22_1672 = 0;
            unksp9D8 = 3.60985932e-315;
            unksp9E8 = (f64) (2.0f * &arg4);
            unksp9E0 = 1.6145507526e-314;
            do {
                temp_f24_1685 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                temp_f31_1690 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                unksp2B8 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                unksp2BC = temp_f31_1690;
                unksp2C0 = temp_f24_1685;
                unksp668 = unksp2B8;
                unksp670 = unksp2C0;
                var_f0_1710 = (unksp670 * unksp670) + ((unksp668 * unksp668) + (unksp66C * unksp66C));
                if (var_f0_1710 > (f32) unksp9D8) {
                    if (var_f0_1710 > 0.0f) {
                        temp_f2_1716 = __frsqrte(var_f0_1710);
                        temp_f2_1722 = 0.5 * temp_f2_1716 * -(((f64) var_f0_1710 * (temp_f2_1716 * temp_f2_1716)) - 3.0);
                        temp_f2_1726 = 0.5 * temp_f2_1722 * -(((f64) var_f0_1710 * (temp_f2_1722 * temp_f2_1722)) - 3.0);
                        var_f0_1710 = (f32) ((f64) var_f0_1710 * (0.5 * temp_f2_1726 * -(((f64) var_f0_1710 * (temp_f2_1726 * temp_f2_1726)) - 3.0)));
                    } else if (var_f0_1710 < M2C_BITWISE(f32, 0.0)) {
                        var_f0_1710 = __float_nan;
                    } else {
                        unksp14 = var_f0_1710;
                        temp_r3_1745 = unksp14 & 0x7F800000;
                        switch (temp_r3_1745) {     /* switch 3; irregular */
                        case 0x7F800000:            /* switch 3 */
                            if (unksp14 & 0x7FFFFF) {
                                var_r0_1755 = 1;
                            } else {
                                var_r0_1755 = 2;
                            }
                            break;
                        case 0x0:                   /* switch 3 */
                            if (unksp14 & 0x7FFFFF) {
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
                temp_f0_1787 = unksp670 * var_f3_1777;
                unksp298 = unksp668 * var_f3_1777;
                unksp29C = unksp66C * var_f3_1777;
                unksp2A0 = temp_f0_1787;
                unksp678 = unksp298;
                unksp680 = (f64) temp_f0_1787;
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r23, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                unksp868 = unksp2A8;
                unksp2B0 = unksp990 + unksp680;
                unksp870 = unksp2B0;
                temp_f31_1811 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                temp_f24_1816 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                temp_f1_1820 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                unksp268 = temp_f1_1820;
                unksp26C = temp_f24_1816;
                unksp270 = temp_f31_1811;
                unksp618 = (f64) temp_f1_1820;
                unksp620 = unksp270;
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f22 */);
                unksp290 = 0.0f;
                temp_f2_1835 = (f32) unksp270 * 100.0f;
                unksp260 = temp_f2_1835;
                unksp288 = 0.0f;
                unksp28C = (f32) unksp9E0;
                unksp628 = unksp258;
                unksp638 = unksp288;
                unksp630 = (f64) temp_f2_1835;
                unksp640 = unksp290;
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                unksp648 = unksp278;
                unksp280 = M2C_FIELD(this, f32 *, 0x208) + (f32) unksp290;
                unksp650 = unksp280;
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                unksp658 = unksp248;
                unksp250 = unksp650 + unksp630;
                unksp660 = unksp250;
                temp_f23_1876 = MKRand_Float(&gViewSeed, 0.8f, 1.0f);
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r21, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
                unksp5E8 = unksp88;
                unksp90 = unksp870 * &arg4;
                unksp5F0 = unksp90;
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f21 */);
                unksp5F8 = unksp238;
                unksp240 = unksp5F0 * 175.0f;
                unksp600 = unksp240;
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f23 */);
                unksp608 = unksp228;
                unksp230 = (f32) unksp240 * temp_f23_1876;
                unksp20 = (f32) unksp9E8 * unksp30;
                unksp610 = unksp230;
                this->unkAC->Emit(*((MKVector3 *) &unksp658), *((MKVector3 *) &unksp608), unksp20);
                var_r22_1672 += 1;
            } while (var_r22_1672 < 5);
            temp_r3_1922 = gameData.unk70.unkE8 << 5;
            temp_r0_1924 = *(&gameData.unk70 + (temp_r3_1922 + 0x7C));
            temp_r4_1926 = &gameData.unk70 + (temp_r3_1922 + 0x64);
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
                unksp220 = -1.0f;
                unksp210 = 1.0f;
                unksp218 = -1.0f;
                unksp21C = 0.0f;
                unksp208 = 1.0f;
                unksp20C = 1.0f;
                unksp5B8 = unksp218;
                unksp5C0 = unksp220;
                unksp5A8 = 5.263544247e-315;
                unksp5B0 = unksp210;
                KDRand_Vector(*((MKVector3 *) &unksp5C8), *((MKVector3 *) &unksp5B8));
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r29, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                unksp5D8 = unksp1F8;
                unksp200 = unksp5D0 + arg2.unk8;
                unksp5E0 = unksp200;
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f20 */);
                unksp858 = unksp1E8;
                unksp1F0 = unksp5E0 * 1600.0f;
                unksp860 = unksp1F0;
                temp_f20_1997 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                temp_f15_2002 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                temp_f1_2006 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                unksp1B8 = temp_f1_2006;
                unksp1BC = temp_f15_2002;
                unksp1C0 = temp_f20_1997;
                unksp558 = (f64) temp_f1_2006;
                unksp560 = unksp1C0;
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f19 */);
                temp_f3_2022 = (f32) unksp1C0 * 100.0f;
                unksp1E0 = 0.0f;
                unksp1B0 = temp_f3_2022;
                unksp1D8 = 0.0f;
                unksp1DC = -100.0f;
                unksp568 = unksp1A8;
                unksp578 = unksp1D8;
                unksp570 = (f64) temp_f3_2022;
                unksp580 = unksp1E0;
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                unksp588 = unksp1C8;
                unksp1D0 = M2C_FIELD(this, f32 *, 0x208) + unksp580;
                unksp590 = unksp1D0;
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                unksp598 = unksp198;
                unksp1A0 = unksp590 + unksp570;
                unksp5A0 = unksp1A0;
                ((ElectricSparks *) (M2C_FIELD(&gb, ElectricSparks **, 0x230)))->Emit(*((MKVector3 *) &unksp598), *((MKVector3 *) &unksp858), 2.0f, 0U);
            }
        }
        if ((arg6 != 0) && (temp_r3_1501 != 0)) {
            if ((unksp970 != 0) && (unksp968 != NULL) && (var_r3_2078 = M2C_FIELD(unksp968, void **, 8), ((var_r3_2078 == NULL) == 0))) {

            } else {
                var_r3_2078 = NULL;
            }
            if (var_r3_2078 != NULL) {
                streamHitMsg.unk50 = 0;
                M2C_FIELD(&streamHitMsg, f64 *, 0x10) = unksp888;
                M2C_FIELD(&streamHitMsg, f64 *, 0x18) = unksp890;
                streamHitMsg.unk30 = unksp968;
                M2C_FIELD(M2C_FIELD(var_r3_2078, void **, 0x44), M2C_UNK (**)(BreathHitMessage *, M2C_UNK, f64), 0x2C)(&streamHitMsg, 0, unksp888);
            }
        } else {
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r29, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
            unksp518 = unksp78;
            unksp80 = arg2.unk8 * &arg4;
            unksp520 = unksp80;
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f28 */);
            unksp528 = unksp188;
            unksp190 = unksp520 * unksp2C;
            unksp530 = unksp190;
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f18 */);
            unksp538 = unksp178;
            unksp180 = unksp530 * 1.5f;
            unksp540 = unksp180;
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r27, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            unksp548 = unksp168;
            unksp170 = unksp540 + arg3.unk8;
            unksp550 = unksp170;
            CreateCollisionTest(arg1, *((MKVector3 *) &unksp548), M2C_BITWISE(f32, this->unk264), 0x04000000U, FlameBreathFXHitCallback);
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
            unksp4E8.operator*(0.5f * unksp2C);
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r30, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            unksp4F8 = unksp38;
            unksp40 = arg1.unk8 + unksp4F0;
            unksp500 = unksp40;
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            temp_f0_2216 = unksp500 + unksp4E0;
            temp_r3_2217 = this->unkA8;
            unksp508 = unksp68;
            unksp70 = temp_f0_2216;
            temp_r3_2217->unk10 = unksp68;
            temp_r3_2217->unk18 = (f64) temp_f0_2216;
            temp_r3_2223 = temp_r3_2217->unk3C;
            unksp510 = (f64) temp_f0_2216;
            if (temp_r3_2223 != NULL) {
                M2C_FIELD(temp_r3_2223, f64 *, 0x10) = unksp68;
                M2C_FIELD(temp_r3_2223, f64 *, 0x18) = (f64) temp_f0_2216;
            }
            unksp58 = 1.0f;
            temp_r3_2233 = this->unkA8;
            unksp5C = 1.0f;
            unksp60 = 0.0f;
            unksp64 = 1.0f;
            temp_r3_2233->unk20 = unksp58;
            temp_r3_2233->unk28 = 0.0;
            temp_r3_2241 = temp_r3_2233->unk3C;
            unksp4C8 = unksp58;
            unksp4D0 = 0.0;
            if (temp_r3_2241 != NULL) {
                M2C_FIELD(temp_r3_2241, f64 *, 0) = unksp58;
                M2C_FIELD(temp_r3_2241, f64 *, 8) = 0.0;
            }
        }
        this->unkB4 = 1;
        this->unkBC = 1;
        temp_f1_2253 = this->unk148.unk100;
        if (temp_f1_2253 > 0.0f) {
            var_r22_2259 = 0;
            temp_f5_2260 = temp_f1_2253 / 1.5f;
            temp_f18_2267 = arg2.unk8;
            temp_f15_2269 = arg3.unk8;
            temp_f21_2270 = 2.0f * &arg4;
loop_144:
            if (var_r22_2259 < (s32) (f32) ceil(5.0f * temp_f5_2260)) {
                temp_f23_2278 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                temp_f22_2283 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                temp_f1_2287 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                unksp158 = temp_f1_2287;
                unksp15C = temp_f22_2283;
                unksp160 = temp_f23_2278;
                unksp488 = (f64) temp_f1_2287;
                unksp490 = unksp160;
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f27 */);
                unksp498 = unksp148;
                unksp150 = unksp490 * unksp30;
                unksp4A0 = unksp150;
                var_f4_2312 = (unksp4A0 * unksp4A0) + ((unksp498 * unksp498) + (unksp49C * unksp49C));
                if (var_f4_2312 > 1e-12f) {
                    if (var_f4_2312 > 0.0f) {
                        temp_f1_2318 = __frsqrte(var_f4_2312);
                        temp_f1_2324 = 0.5 * temp_f1_2318 * -(((f64) var_f4_2312 * (temp_f1_2318 * temp_f1_2318)) - 3.0);
                        temp_f1_2328 = 0.5 * temp_f1_2324 * -(((f64) var_f4_2312 * (temp_f1_2324 * temp_f1_2324)) - 3.0);
                        var_f4_2312 = (f32) ((f64) var_f4_2312 * (0.5 * temp_f1_2328 * -(((f64) var_f4_2312 * (temp_f1_2328 * temp_f1_2328)) - 3.0)));
                    } else if (var_f4_2312 < M2C_BITWISE(f32, 0.0)) {
                        var_f4_2312 = __float_nan;
                    } else {
                        unksp10 = var_f4_2312;
                        temp_r3_2347 = unksp10 & 0x7F800000;
                        switch (temp_r3_2347) {     /* switch 4; irregular */
                        case 0x7F800000:            /* switch 4 */
                            if (unksp10 & 0x7FFFFF) {
                                var_r0_2357 = 1;
                            } else {
                                var_r0_2357 = 2;
                            }
                            break;
                        case 0x0:                   /* switch 4 */
                            if (unksp10 & 0x7FFFFF) {
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
                temp_f0_2389 = unksp4A0 * var_f3_2379;
                unksp118 = unksp498 * var_f3_2379;
                unksp11C = unksp49C * var_f3_2379;
                unksp120 = temp_f0_2389;
                unksp4A8 = unksp118;
                unksp4B0 = (f64) temp_f0_2389;
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f14 */);
                unksp4B8 = unksp138;
                unksp140 = unksp4B0 * ((0.65f * temp_f5_2260) + 0.1f);
                unksp4C0 = unksp140;
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r29, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                unksp848 = unksp128;
                unksp130 = temp_f18_2267 + unksp4C0;
                unksp850 = unksp130;
                temp_f17_2422 = MKRand_Float(&gViewSeed, 0.8f, 1.0f);
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r23, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f26 */);
                unksp448 = unksp48;
                unksp50 = unksp850 * &arg4;
                unksp450 = unksp50;
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f25 */);
                unksp458 = unksp108;
                unksp110 = unksp450 * unksp2C;
                unksp460 = unksp110;
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f17 */);
                unksp468 = unkspF8;
                unksp100 = unksp460 * temp_f17_2422;
                unksp470 = unksp100;
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r27, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                unksp478 = unkspE8;
                unkspF0 = unksp470 + temp_f15_2269;
                unksp1C = temp_f21_2270 * unksp30;
                unksp480 = unkspF0;
                this->unkAC->Emit(arg1, *((MKVector3 *) &unksp478), unksp1C);
                var_r22_2259 += 1;
                goto loop_144;
            }
        }
        temp_r3_2486 = gameData.unk70.unkE8 << 5;
        temp_r0_2488 = *(&gameData.unk70 + (temp_r3_2486 + 0x7C));
        temp_r4_2490 = &gameData.unk70 + (temp_r3_2486 + 0x64);
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
            unkspE0 = -1.0f;
            unkspD0 = 1.0f;
            unkspD8 = -1.0f;
            unkspDC = -1.0f;
            unkspC8 = 1.0f;
            unkspCC = 1.0f;
            unksp418 = 1.58735232e-314;
            unksp420 = unkspE0;
            unksp408 = 5.263544247e-315;
            unksp410 = unkspD0;
            KDRand_Vector(*((MKVector3 *) &unksp428), *((MKVector3 *) &unksp418));
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r29, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            unksp438 = unkspB8;
            unkspC0 = unksp430 + arg2.unk8;
            unksp440 = unkspC0;
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f16 */);
            unksp838 = unkspA8;
            unkspB0 = unksp440 * 500.0f;
            unksp840 = unkspB0;
            ((ElectricSparks *) (M2C_FIELD(&gb, ElectricSparks **, 0x230)))->Emit(arg1, *((MKVector3 *) &unksp838), 1.0f, 0U);
        }
        this->unkB4 = 1;
        return 1;
    case 1:                                         /* switch 1 */
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if (this->unk13C == 0.0f) {
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
        temp_r4_2595 = &gameData.unk70 + ((gameData.unk70.unkE8 << 5) + 0x64);
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

#if 0 // DRAFT: undefined identifier 'sp118'
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
    f32 var_f0_3404;
    f32 var_f2_2956;
    f32 var_f2_3147;
    f32 var_f3_3161;
    f32 var_f3_3318;
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
    if ((((u8) this->unkB4 == 0) || (((s32) this->unk130 == 0) && (M2C_ERROR(/* unknown instruction: cror eq, lt, eq */), ((this->unk134 == 0.0f) != 0)))) && ((u8) this->unk148.unk108 != 0)) {
        this->unk148.unk104 = 0.5f;
    }
    if (((s32) this->unk130 == 0) && (M2C_ERROR(/* unknown instruction: cror eq, lt, eq */), ((this->unk134 == 0.0f) != 0))) {
        this->unk148.unk108 = 0;
    } else {
        this->unk148.unk108 = this->unkB4;
    }
    this->unk148.Update();
    if (((u8) this->unkB4 == 0) || (((s32) this->unk130 == 0) && (M2C_ERROR(/* unknown instruction: cror eq, lt, eq */), ((this->unk134 == 0.0f) != 0))) || (EventCamera_GetCurrent() != NULL)) {
        temp_r4_2852 = this->unkA8;
        if (temp_r4_2852 != NULL) {
            sp258 = 0.0f;
            sp25C = 0.0f;
            sp260 = 0.0f;
            sp264 = 1.0f;
            sp2C8 = (f64) sp258;
            sp2D0 = (f64) sp260;
            if ((0.5f * (2.5f * gUpdateTimeDelta)) < 1.0f) {

            }
            M2C_ERROR(/* unknown instruction: psq_lx $f2, $zero, $r3, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f3, $f2 */);
            M2C_ERROR(/* unknown instruction: psq_lx $f4, $r3, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f5, $f4 */);
            sp228 = sp118;
            sp230 = sp120;
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
            sp218 = sp108;
            sp220 = sp110;
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f2, $f0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f4, $f0 */);
            sp208 = spF8;
            sp210 = sp100;
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f3, $f2 */);
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f5, $f3 */);
            sp248 = spE8;
            sp250 = spF0;
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
            sp238 = spD8;
            sp240 = spE0;
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f2, $f0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f3, $f0 */);
            temp_r4_2852->unk20 = spC8;
            temp_r4_2852->unk28 = spD0;
            temp_r3_2942 = temp_r4_2852->unk3C;
            sp2F8 = spC8;
            sp300 = spD0;
            if (temp_r3_2942 != NULL) {
                M2C_FIELD(temp_r3_2942, f64 *, 0) = spC8;
                M2C_FIELD(temp_r3_2942, f64 *, 8) = spD0;
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
            M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
            if ((f32) sp2F8 == 0.05f) {
                M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
                if (unksp2FC == 0.05f) {
                    M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
                    if ((f32) sp300 == 0.05f) {
                        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->EnableLight(this->unkA8, 0U);
                    }
                }
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
            if ((0.5f * temp_f0_3024) < 1.0f) {

            }
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f3, $f2 */);
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f5, $f4 */);
            sp1B8 = spB8;
            sp1C0 = spC0;
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
            sp1A8 = spA8;
            sp1B0 = spB0;
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f2, $f0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f4, $f0 */);
            sp198 = sp98;
            sp1A0 = spA0;
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f3, $f2 */);
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f5, $f3 */);
            sp1D8 = sp88;
            sp1E0 = sp90;
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
            sp1C8 = sp78;
            sp1D0 = sp80;
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f2, $f0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f3, $f0 */);
            sp2E8 = sp68;
            sp2F0 = sp70;
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
            if ((0.5f * temp_f0_3206) < 1.0f) {

            }
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f3, $f2 */);
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f5, $f4 */);
            sp148 = sp58;
            sp150 = sp60;
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
            sp138 = sp48;
            sp140 = sp50;
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f2, $f0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f4, $f0 */);
            sp128 = sp38;
            sp130 = sp40;
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f3, $f2 */);
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f5, $f3 */);
            sp168 = sp28;
            sp170 = sp30;
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
            sp158 = sp18;
            sp160 = sp20;
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f2, $f0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f3, $f0 */);
            sp2D8 = sp8;
            sp2E0 = sp10;
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
        if (((temp_r0_3368 == 0) && (M2C_ERROR(/* unknown instruction: cror eq, gt, eq */), ((this->unk134 == 0.0f) != 0))) || ((temp_r0_3368 != 0) && (M2C_ERROR(/* unknown instruction: cror eq, gt, eq */), ((this->unk138 == 0.0f) != 0)))) {
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

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<FireBombFX *, MKProp>(MKProp *arg0) {

}
#endif

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<FuryFXFire2 *, MKProp>(MKProp *arg0) {

}
#endif

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<FuryFXFire *, MKProp>(MKProp *arg0) {

}
#endif

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<FlameBreathPS *, MKProp>(MKProp *arg0) {

}
#endif

#if 0 // DRAFT: undefined identifier 'unk4'
void FlameBreathFX_cpp::__sinit() {
    streamHitMsg.unk4 = 0;
}
#endif
