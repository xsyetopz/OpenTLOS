#include "spyro/source/FireBombFX.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/ClusterBomb.h"
#include "spyro/source/Explosion4.h"
#include "spyro/source/Game.h"
#include "spyro/source/GameData.h"
#include "spyro/source/GameMessages.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/HeroInterface.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/ManagedLight.h"
#include "spyro/source/ShapedTrailFX.h"
#include "unplaced_templates.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKView.h"
#include "common/Source/StdMath.h"
#include "common/gc/MKMaterial_GC.h"
#include "common/gc/MKPrimitive_GC.h"
#include "spyro/source/KDMath.h"
#include "spyro/source/KDRandom.h"
#include "spyro/source/KDSound.h"
#include <m2c_macros.h>

extern s32 GS_CynderBreathEnd2;
extern s32 GS_CynderBreathHitSpyro;
extern s32 GS_CynderBreathStart2;
extern s32 GS_CynderBreathStart3;
extern s32 GS_Explosion7;
extern s32 GS_SWCynderFireball2;
extern s32 GS_SWCynderFireball3;
extern s32 GS_SpyroSWFireballLP;
extern s32 GS_SpyroSpare2;
extern f32 *KDSpline_PositionMixer;
extern void **gMK;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern GameGlobals gb;

static s32 lit_536 = 0;
static u8 lit_537 = 1;
static s32 lit_540 = -1;
static s32 lit_541 = 6;

static u8 lit_687 = 0;
static u8 lit_762 = 1;

#if 0 // DRAFT: illegal use of non-static member
void FireBombFXDescriptor::Deinit() {
    MKMaterial_Destroy(this->unkEC);
    KDPropExDescriptor::Deinit();
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void FireBombFXDescriptor::LoadDone() {
    GamePropDescriptor::LoadDone();
    this->unkEC = MKMaterial_Create(this->unkE8);
}
#endif

#if 0 // DRAFT: illegal use of non-static member
s32 FireBombFXDescriptor::LoadLine(MKIniLine *arg0) {
    s32 var_r31_55;

    var_r31_55 = 0;
    if ((GamePropDescriptor::LoadLine(arg0) != 0) || (arg0->LoadString("flamemat", &this->unkE8, 0) != 0) || (arg0->LoadString("trailmat", &this->unkE4, 0) != 0)) {
        var_r31_55 = 1;
    }
    return var_r31_55;
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void FireBombFXDescriptor::Init() {
    GamePropDescriptor::Init();
    this->unkE8 = NULL;
    this->unkE4 = NULL;
}
#endif

#if 0 // DRAFT: pointer/array required
void FireBombFX::Fire(const MKVector3 &arg0, const MKVector3 &arg1, float arg2, MKProp *arg3, bool arg4, bool arg5, int arg6, const MKVector3 &arg7) {
    s8 spC8;
    s32 spC4;
    MKCollisionInfo *spC0;
    s32 spBC;
    f32 spB8;
    s32 spB4;
    s8 spB3;
    s8 spB2;
    s16 spB0;
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
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f32 sp40;
    f32 sp30;
    f32 sp20;
    u8 sp10;
    void *spC;
    f32 sp8;
    MKProp *temp_r3_231;
    MKProp *temp_r3_291;
    ManagedLight *temp_r4_161;
    ShapedTrailFX *temp_r3_130;
    ShapedTrailFX *temp_r3_147;
    ShapedTrailFX *temp_r4_136;
    f32 temp_f1_137;
    f32 var_f4_346;
    f64 temp_f1_245;
    f64 temp_f1_349;
    f64 temp_f1_355;
    f64 temp_f1_359;
    s32 temp_r0_242;
    s32 temp_r30_175;
    s32 temp_r31_178;
    s32 temp_r3_378;
    s32 temp_r4_176;
    s32 var_r0_388;
    s32 var_r23_213;
    s32 var_r6_194;
    s32 var_r7_269;
    u8 var_r4_184;
    u8 var_r4_203;
    void *temp_r3_255;
    void *temp_r5_180;

    MKModel_SetPosition(this->unk4, arg0);
    this->unkE0 = 1;
    temp_r3_130 = this->unkCC;
    temp_r3_130->Reset();
    temp_r4_136 = this->unkCC;
    temp_f1_137 = 2.5f * arg2;
    temp_r4_136->unkA0 = (temp_r4_136->unkA0 & ~0x80) | ((lit_762 << 7) & 0x80);
    if (temp_f1_137 != 0.0f) {
        temp_r4_136->unk98 = temp_f1_137;
    }
    temp_r3_147 = this->unkCC;
    temp_r3_147->unkA0 |= 0x40;
    this->unk120 = arg3;
    M2C_FIELD(this, u8 *, 0x1B8) = arg5;
    this->unkFC = 0.0f;
    this->unk104 = 0.0f;
    this->unk128 = arg2;
    this->unk1B0 = arg4;
    this->unkC8 = 10.0f;
    temp_r4_161 = this->unk108;
    if (temp_r4_161 != NULL) {
        gb.unk80->EnableLight(temp_r4_161, 1U);
    }
    this->unk124 = 10000.0f;
    temp_r30_175 = GameData::gameData.unk70.unkE8;
    temp_r4_176 = temp_r30_175 << 5;
    temp_r31_178 = *(&GameData::gameData.unk70 + (temp_r4_176 + 0x7C));
    temp_r5_180 = &GameData::gameData.unk70 + (temp_r4_176 + 0x64);
    if (temp_r31_178 == 3) {
        var_r4_184 = 0;
        if (((s32) M2C_FIELD(temp_r5_180, s32 *, 0) == 3) && ((s32) M2C_FIELD(temp_r5_180, s32 *, 4) == 3)) {
            var_r4_184 = 1;
        }
        var_r6_194 = var_r4_184 != 0;
    } else {
        var_r6_194 = *(temp_r5_180 + (temp_r31_178 * 4));
    }
    if (temp_r31_178 == 3) {
        var_r4_203 = 0;
        if (((s32) M2C_FIELD(temp_r5_180, s32 *, 0) == 3) && ((s32) M2C_FIELD(temp_r5_180, s32 *, 4) == 3)) {
            var_r4_203 = 1;
        }
        var_r23_213 = var_r4_203 != 0;
    } else {
        var_r23_213 = *(temp_r5_180 + (temp_r31_178 * 4));
    }
    this->unk130.Init(arg3, ((GameStats *) (&GameData::gameData.unk70))->GetBreathAttackDamage(temp_r30_175, temp_r31_178, var_r6_194), temp_r31_178, var_r23_213, temp_r30_175, temp_r30_175, 0, -1);
    temp_r3_231 = this->unk120;
    if ((temp_r3_231 != NULL) && (M2C_FIELD(temp_r3_231->unk0, s32 *, 0xC) & 8)) {
        this->unk130.unk34 = 5.0f;
    }
    M2C_FIELD(this, s32 *, 0x1BC) = arg6;
    temp_r0_242 = M2C_FIELD(this, s32 *, 0x1BC);
    switch (temp_r0_242) {                          /* switch 1; irregular */
    case 0:                                         /* switch 1 */
        temp_f1_245 = M2C_FIELD(&arg1, f64 *, 0);
        this->unkD0 = temp_f1_245;
        this->unkD8 = M2C_FIELD(&arg1, f64 *, 8);
        temp_r3_255 = M2C_FIELD(gb.unk0->__vptr, void *(**)(HeroInterface *, f64), 0x34)(gb.unk0, temp_f1_245);
        spC = temp_r3_255;
        if (temp_r3_255 != NULL) {
            sp10 = M2C_FIELD(temp_r3_255, u8 *, 4);
            M2C_FIELD(temp_r3_255, u8 *, 4) = 0U;
        }
        var_r7_269 = 0;
        sp78 = 0.0f;
        sp7C = 0.0f;
        sp80 = 0.0f;
        sp88 = 0.0f;
        sp8C = 0.0f;
        sp90 = 0.0f;
        sp98 = 0.0f;
        sp9C = 0.0f;
        spA0 = 0.0f;
        spA4 = 1.0f;
        spA8 = 0.0f;
        spAC = 0.0f;
        spB0 = 0;
        spB2 = 0;
        spB3 = 0;
        spB4 = 0;
        spB8 = 3.4028235e38f;
        spBC = 0;
        spC0 = NULL;
        spC4 = -1;
        spC8 = 0;
        temp_r3_291 = this->unk120;
        if ((temp_r3_291 != NULL) && (M2C_FIELD(temp_r3_291->unk0, s32 *, 0xC) & 8)) {
            var_r7_269 = 0x08000000;
        }
        if (MKCollision_SphereCollide(arg0, 50.0f, (MKCollisionResult *) &sp78, 1, (MKCollisionMode) 7, var_r7_269) != 0) {
            Explode(MKVector3::up, *((MKVector3 *) &sp78), spC0);
        }
        if (spC != NULL) {
            M2C_FIELD(spC, u8 *, 4) = sp10;
            return;
        }
        return;
    case 1:                                         /* switch 1 */
    case 2:                                         /* switch 1 */
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r29, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r25, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
        sp58 = sp38;
        sp40 = arg7.unk8 - arg0.unk8;
        sp60 = (f64) sp40;
        var_f4_346 = ((f32) sp60 * (f32) sp60) + (((f32) sp58 * (f32) sp58) + (unksp5C * unksp5C));
        if (var_f4_346 > 0.0f) {
            temp_f1_349 = __frsqrte(var_f4_346);
            temp_f1_355 = 0.5 * temp_f1_349 * -(((f64) var_f4_346 * (temp_f1_349 * temp_f1_349)) - 3.0);
            temp_f1_359 = 0.5 * temp_f1_355 * -(((f64) var_f4_346 * (temp_f1_355 * temp_f1_355)) - 3.0);
            var_f4_346 = (f32) ((f64) var_f4_346 * (0.5 * temp_f1_359 * -(((f64) var_f4_346 * (temp_f1_359 * temp_f1_359)) - 3.0)));
        } else if (var_f4_346 < M2C_BITWISE(f32, 0.0)) {
            var_f4_346 = __float_nan;
        } else {
            sp8 = var_f4_346;
            temp_r3_378 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r3_378) {                  /* switch 2; irregular */
            case 0x7F800000:                        /* switch 2 */
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_388 = 1;
                } else {
                    var_r0_388 = 2;
                }
                break;
            case 0x0:                               /* switch 2 */
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_388 = 5;
                } else {
                    var_r0_388 = 3;
                }
                break;
            default:                                /* switch 2 */
                var_r0_388 = 4;
                break;
            }
            if (var_r0_388 == 1) {
                var_f4_346 = __float_nan;
            }
        }
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r26, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
        sp48 = sp28;
        sp30 = arg1.unk8 * (0.5f * var_f4_346);
        sp50 = (f64) sp30;
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r25, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        sp68 = sp18;
        sp20 = arg0.unk8 + (f32) sp50;
        sp70 = (f64) sp20;
        this->unk1C4 = 0.0f;
        this->unk1C0 = 0;
        this->unk1BC.AddNode(arg0);
        this->unk1BC.AddNode(*((MKVector3 *) &sp68));
        this->unk1BC.AddNode(arg7);
        this->unk1D4 = 0.0f;
        this->unk1D4 = 10000.0f / M2C_BITWISE(f32, this->unk1C4);
        if (((s32) M2C_FIELD(this, s32 *, 0x1BC) == 2) && (M2C_FIELD(gb.unk0->__vptr, s32 (**)(HeroInterface *), 8)(gb.unk0) == 0)) {
            KDSound_Play3d(GS_CynderBreathStart2, this->unk8 + 0x30, 0U, -1, 0.0f, 0U);
        }
        break;
    }
}
#endif

#if 0 // DRAFT: pointer/array required
void FireBombFX::Deinit() {
    ManagedLight *temp_r4_493;

    temp_r4_493 = this->unk108;
    if (temp_r4_493 != NULL) {
        gb.unk80->EnableLight(temp_r4_493, 0U);
        gb.unk80->FreeManagedLight(this->unk108);
    }
    this->unk1BC.Deinit();
    KDSound_Stop(&this->unk188);
    GameProp::Deinit();
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_sp2BC'
void FireBombFX::DrawFlameBall() {
    f32 temp_f3_851;
    f32 temp_f4_850;
    f32 temp_f5_848;
    f32 var_f2_839;
    f32 var_f4_677;
    f32 var_f5_751;
    f32 var_f6_768;
    f64 temp_f1_690;
    f64 temp_f1_696;
    f64 temp_f1_700;
    f64 temp_f1_778;
    f64 temp_f1_784;
    f64 temp_f1_788;
    s32 temp_r3_719;
    s32 temp_r3_807;
    s32 var_r0_729;
    s32 var_r0_817;
    s32 var_r24_585;
    void *temp_r3_1007;
    M2C_STRUCT_COPY((s32) &arg_sp2BC + 4, MKView_GetCameraMatrix() - 4 + 4, 0x40);
    arg_spD8 = 0.5f;
    arg_spDC = 0.5f;
    arg_spE0 = 0.5f;
    arg_spE4 = 1.0f;
    arg_sp228 = (f64) arg_spD8;
    arg_sp230 = (f64) arg_spE0;
    MKMaterial_SetMaterial(M2C_FIELD(checked_cast<FireBombFXDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), MKMaterial **, 0xEC));
    MKPrimitive(0xC, 0);
    var_r24_585 = 0;
    do {
        arg_spD0 = 0.0f;
        arg_spC0 = 0.0f;
        arg_spC8 = 0.0f;
        arg_spCC = 1.0f;
        arg_spB8 = 1.0f;
        arg_spBC = 0.0f;
        arg_sp218 = (f64) arg_spC8;
        arg_sp220 = (f64) arg_spD0;
        arg_sp208 = (f64) arg_spB8;
        arg_sp210 = (f64) arg_spC0;
        arg_sp280.SetIdentity();
        if (var_r24_585 == 1) {
            arg_sp280.RotateRoll((Matrix *) &arg_sp280, this->unk100);
        } else {
            arg_sp280.RotateRoll((Matrix *) &arg_sp280, -this->unk100);
        }
        arg_spA8 = arg_sp2B0 + (((f32) arg_sp220 * arg_sp2A0) + (((f32) arg_sp218 * arg_sp280) + (arg_sp21C * arg_sp290)));
        arg_spAC = arg_sp2B4 + (((f32) arg_sp220 * arg_sp2A4) + (((f32) arg_sp218 * arg_sp284) + (arg_sp21C * arg_sp294)));
        arg_spB0 = arg_sp2B8 + (((f32) arg_sp220 * arg_sp2A8) + (((f32) arg_sp218 * arg_sp288) + (arg_sp21C * arg_sp298)));
        arg_sp218 = (f64) arg_spA8;
        arg_sp220 = (f64) arg_spB0;
        arg_sp98 = arg_sp2B0 + (((f32) arg_sp210 * arg_sp2A0) + (((f32) arg_sp208 * arg_sp280) + (arg_sp20C * arg_sp290)));
        arg_sp9C = arg_sp2B4 + (((f32) arg_sp210 * arg_sp2A4) + (((f32) arg_sp208 * arg_sp284) + (arg_sp20C * arg_sp294)));
        arg_spA0 = arg_sp2B8 + (((f32) arg_sp210 * arg_sp2A8) + (((f32) arg_sp208 * arg_sp288) + (arg_sp20C * arg_sp298)));
        var_f4_677 = ((f32) arg_sp220 * (f32) arg_sp220) + (((f32) arg_sp218 * (f32) arg_sp218) + (arg_sp21C * arg_sp21C));
        arg_sp1F8 = (f64) arg_spA8;
        arg_sp200 = (f64) arg_spB0;
        arg_sp1E8 = (f64) arg_sp98;
        arg_sp1F0 = (f64) arg_spA0;
        arg_sp208 = (f64) arg_sp98;
        arg_sp210 = (f64) arg_spA0;
        if (var_f4_677 > 0.000001f) {
            if (var_f4_677 > 0.0f) {
                temp_f1_690 = __frsqrte(var_f4_677);
                temp_f1_696 = 0.5 * temp_f1_690 * -(((f64) var_f4_677 * (temp_f1_690 * temp_f1_690)) - 3.0);
                temp_f1_700 = 0.5 * temp_f1_696 * -(((f64) var_f4_677 * (temp_f1_696 * temp_f1_696)) - 3.0);
                var_f4_677 = (f32) ((f64) var_f4_677 * (0.5 * temp_f1_700 * -(((f64) var_f4_677 * (temp_f1_700 * temp_f1_700)) - 3.0)));
            } else if (var_f4_677 < M2C_BITWISE(f32, 0.0)) {
                var_f4_677 = __float_nan;
            } else {
                arg_sp14 = var_f4_677;
                temp_r3_719 = M2C_BITWISE(s32, arg_sp14) & 0x7F800000;
                switch (temp_r3_719) {              /* switch 1; irregular */
                case 0x7F800000:                    /* switch 1 */
                    if (M2C_BITWISE(s32, arg_sp14) & 0x7FFFFF) {
                        var_r0_729 = 1;
                    } else {
                        var_r0_729 = 2;
                    }
                    break;
                case 0x0:                           /* switch 1 */
                    if (M2C_BITWISE(s32, arg_sp14) & 0x7FFFFF) {
                        var_r0_729 = 5;
                    } else {
                        var_r0_729 = 3;
                    }
                    break;
                default:                            /* switch 1 */
                    var_r0_729 = 4;
                    break;
                }
                if (var_r0_729 == 1) {
                    var_f4_677 = __float_nan;
                }
            }
            var_f5_751 = 1.0f / var_f4_677;
        } else {
            var_f5_751 = 0.0f;
        }
        var_f6_768 = ((f32) arg_sp210 * (f32) arg_sp210) + (((f32) arg_sp208 * (f32) arg_sp208) + (arg_sp20C * arg_sp20C));
        arg_sp218 = (f32) arg_sp218 * var_f5_751;
        arg_sp21C *= var_f5_751;
        arg_sp220 = (f32) arg_sp220 * var_f5_751;
        if (var_f6_768 > 0.000001f) {
            if (var_f6_768 > 0.0f) {
                temp_f1_778 = __frsqrte(var_f6_768);
                temp_f1_784 = 0.5 * temp_f1_778 * -(((f64) var_f6_768 * (temp_f1_778 * temp_f1_778)) - 3.0);
                temp_f1_788 = 0.5 * temp_f1_784 * -(((f64) var_f6_768 * (temp_f1_784 * temp_f1_784)) - 3.0);
                var_f6_768 = (f32) ((f64) var_f6_768 * (0.5 * temp_f1_788 * -(((f64) var_f6_768 * (temp_f1_788 * temp_f1_788)) - 3.0)));
            } else if (var_f6_768 < M2C_BITWISE(f32, 0.0)) {
                var_f6_768 = __float_nan;
            } else {
                arg_sp10 = var_f6_768;
                temp_r3_807 = M2C_BITWISE(s32, arg_sp10) & 0x7F800000;
                switch (temp_r3_807) {              /* switch 2; irregular */
                case 0x7F800000:                    /* switch 2 */
                    if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                        var_r0_817 = 1;
                    } else {
                        var_r0_817 = 2;
                    }
                    break;
                case 0x0:                           /* switch 2 */
                    if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                        var_r0_817 = 5;
                    } else {
                        var_r0_817 = 3;
                    }
                    break;
                default:                            /* switch 2 */
                    var_r0_817 = 4;
                    break;
                }
                if (var_r0_817 == 1) {
                    var_f6_768 = __float_nan;
                }
            }
            var_f2_839 = 1.0f / var_f6_768;
        } else {
            var_f2_839 = 0.0f;
        }
        temp_f5_848 = (f32) arg_sp208 * var_f2_839;
        temp_f4_850 = arg_sp20C * var_f2_839;
        temp_f3_851 = (f32) arg_sp210 * var_f2_839;
        arg_sp208 = temp_f5_848;
        arg_sp20C = temp_f4_850;
        arg_sp48 = -temp_f5_848;
        arg_sp4C = -temp_f4_850;
        arg_sp50 = -temp_f3_851;
        arg_sp210 = temp_f3_851;
        arg_sp1A8 = (f64) arg_sp48;
        arg_sp1B0 = (f64) arg_sp50;
        arg_sp1B8.operator*(this->unkC8 * this->unk128);
        arg_sp1C8.operator*(this->unkC8 * this->unk128);
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r31, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        arg_sp238 = arg_sp88;
        arg_sp90 = arg_sp1D0 + arg_sp1C0;
        arg_sp1D8 = arg_sp88;
        arg_sp240 = (f64) arg_sp90;
        arg_sp1E0 = (f64) arg_sp90;
        arg_sp178.operator*(this->unkC8 * this->unk128);
        arg_sp188.operator*(this->unkC8 * this->unk128);
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r30, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        arg_sp40 = -(f32) arg_sp210;
        arg_sp80 = arg_sp190 + arg_sp180;
        arg_sp38 = -(f32) arg_sp208;
        arg_sp3C = -arg_sp20C;
        arg_sp248 = arg_sp78;
        arg_sp250 = (f64) arg_sp80;
        arg_sp128 = (f64) arg_sp38;
        arg_sp130 = (f64) arg_sp40;
        arg_sp198 = arg_sp78;
        arg_sp1A0 = (f64) arg_sp80;
        arg_sp138.operator*(this->unkC8 * this->unk128);
        arg_sp28 = -(f32) arg_sp218;
        arg_sp2C = -arg_sp21C;
        arg_sp30 = -(f32) arg_sp220;
        arg_sp148 = (f64) arg_sp28;
        arg_sp150 = (f64) arg_sp30;
        arg_sp158.operator*(this->unkC8 * this->unk128);
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r29, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        arg_sp258 = arg_sp68;
        arg_sp70 = arg_sp160 + arg_sp140;
        arg_sp168 = arg_sp68;
        arg_sp260 = (f64) arg_sp70;
        arg_sp170 = (f64) arg_sp70;
        arg_spE8.operator*(this->unkC8 * this->unk128);
        arg_sp18 = -(f32) arg_sp218;
        arg_sp1C = -arg_sp21C;
        arg_sp20 = -(f32) arg_sp220;
        arg_spF8 = (f64) arg_sp18;
        arg_sp100 = (f64) arg_sp20;
        arg_sp108.operator*(this->unkC8 * this->unk128);
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r28, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        arg_sp268 = arg_sp58;
        arg_sp60 = arg_sp110 + arg_spF0;
        arg_sp118 = arg_sp58;
        arg_sp270 = (f64) arg_sp60;
        arg_sp120 = (f64) arg_sp60;
        temp_r3_1007 = MKModel_GetWorldMatrix(this->unk4);
        arg_sp2F0 = M2C_FIELD(temp_r3_1007, f32 *, 0x30);
        arg_sp2F4 = M2C_FIELD(temp_r3_1007, f32 *, 0x34);
        arg_sp2F8 = M2C_FIELD(temp_r3_1007, f32 *, 0x38);
        arg_sp2FC = 1.0f;
        MKSetMatrix(*((Matrix *) &arg_sp2C0));
        MKBegin(4);
        MKSetColorV(*((MKVector4 *) &arg_sp228));
        MKSetTexCoord1F(0.0f, 1.0f);
        MKSetPositionV(*((MKVector3 *) &arg_sp238));
        MKSetColorV(*((MKVector4 *) &arg_sp228));
        MKSetTexCoord1F(1.0f, 1.0f);
        MKSetPositionV(*((MKVector3 *) &arg_sp248));
        MKSetColorV(*((MKVector4 *) &arg_sp228));
        MKSetTexCoord1F(0.0f, 0.0f);
        MKSetPositionV(*((MKVector3 *) &arg_sp258));
        MKSetColorV(*((MKVector4 *) &arg_sp228));
        MKSetTexCoord1F(1.0f, 0.0f);
        MKSetPositionV(*((MKVector3 *) &arg_sp268));
        MKEnd();
        var_r24_585 += 1;
    } while (var_r24_585 < 2);
    MKEndPrimitive();
}
#endif

void FireBombFX::Draw() {
    if ((u8) this->unkE0 != 0) {
        DrawFlameBall();
    }
}

#if 0 // DRAFT: undefined identifier '__vptr'
void FireBombFX::Explode(const MKVector3 &arg0, const MKVector3 &arg1, MKCollisionInfo *arg2) {
    f64 spF8;
    f64 spF0;
    f64 spE8;
    f64 spE0;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    f64 spC0;
    MKVector3 spB0;
    f64 spA8;
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f32 sp68;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp38;
    f32 sp28;
    f32 sp18;
    s32 sp8;
    MKProp *temp_r3_1197;
    ManagedLight *temp_r4_1297;
    ShapedTrailFX *temp_r4_1179;
    f32 temp_f26_1313;
    f32 temp_f27_1314;
    f32 var_f26_1207;
    f64 temp_f1_1190;
    f64 temp_f2_1279;
    s32 var_r31_1312;
    u8 var_r31_1121;
    void *temp_r3_1221;

    this->unkE0 = 0;
    var_r31_1121 = 1;
    if ((s32) this->unk130.unk3C == 0) {
        var_r31_1121 = 0;
    }
    if (((s32) M2C_FIELD(this, s32 *, 0x1BC) == 1) || (M2C_FIELD(gb.unk0->__vptr, s32 (**)(HeroInterface *), 8)(gb.unk0) == 2)) {
        this->unkF8->unk88 = GS_Explosion7;
    } else if ((s32) M2C_FIELD(this, s32 *, 0x1BC) == 2) {
        if (M2C_FIELD(gb.unk0->__vptr, s32 (**)(HeroInterface *), 8)(gb.unk0) == 1) {
            this->unkF8->unk88 = GS_SWCynderFireball3;
        } else {
            this->unkF8->unk88 = GS_CynderBreathEnd2;
        }
    }
    sp8 = 1;
    this->unkF8->Trigger(arg1, 0.9f * this->unk128, 0U, this->unk120, 5, this->unk1B0, 1U, var_r31_1121, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    temp_r4_1179 = this->unkCC;
    temp_r4_1179->unkA0 = (temp_r4_1179->unkA0 & ~0x80) | ((lit_687 << 7) & 0x80);
    if ((arg2 != NULL) && ((MKProp *) arg2->unk8 != NULL)) {
        temp_f1_1190 = M2C_FIELD(&arg1, f64 *, 0);
        this->unk130.unk50 = 0;
        M2C_FIELD(this, f64 *, 0x140) = temp_f1_1190;
        M2C_FIELD(this, f64 *, 0x148) = (f64) M2C_FIELD(&arg1, f64 *, 8);
        this->unk130.unk30 = arg2;
        temp_r3_1197 = arg2->unk8;
        temp_r3_1197->Message(&this->unk130, temp_f1_1190);
    }
    if ((s32) M2C_FIELD(this, s32 *, 0x1BC) == 2) {
        var_f26_1207 = 750.0f;
        if ((u8) gb.unk35D != 0) {
            var_f26_1207 = 400.0f;
        }
        temp_r3_1221 = M2C_FIELD(M2C_FIELD(gb.unk0->__vptr, void *(**)(HeroInterface *), 0xC)(gb.unk0), void **, 8);
        spC0 = M2C_FIELD(temp_r3_1221, f64 *, 0x30);
        spC8 = M2C_FIELD(temp_r3_1221, f64 *, 0x38);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r29, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
        spD0 = sp60;
        sp68 = (f32) spC8 - arg1.unk8;
        spD8 = (f64) sp68;
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if ((((f32) spD8 * (f32) spD8) + (((f32) spD0 * (f32) spD0) + (unkspD4 * unkspD4))) == (var_f26_1207 * var_f26_1207)) {
            this->unk130.unk50 = 0;
            this->unk130.unk30 = NULL;
            if (M2C_FIELD(gb.unk0->__vptr, s32 (**)(HeroInterface *), 8)(gb.unk0) == 0) {
                this->unk130.unk4C = GS_CynderBreathHitSpyro;
            }
            M2C_FIELD(M2C_FIELD(M2C_FIELD(gb.unk0->__vptr, void *(**)(HeroInterface *), 0xC)(gb.unk0), void **, 0x44), M2C_UNK (**)(BreathHitMessage *), 0x2C)(&this->unk130);
        }
    } else {
        temp_f2_1279 = M2C_FIELD(&arg1, f64 *, 0);
        this->unk130.unk50 = 0;
        this->unk130.unk30 = NULL;
        spF0 = temp_f2_1279;
        spF8 = M2C_FIELD(&arg1, f64 *, 8);
        M2C_FIELD(*gMK, M2C_UNK (**)(void **, BreathHitMessage *, M2C_UNK, M2C_UNK, f64 *, M2C_UNK, f32, f64), 0x94)(gMK, &this->unk130, 0, 1, &spF0, 1, 750.0f, temp_f2_1279);
    }
    temp_r4_1297 = this->unk108;
    if (temp_r4_1297 != NULL) {
        gb.unk80->EnableLight(temp_r4_1297, 0U);
    }
    if ((u8) M2C_FIELD(this, u8 *, 0x1B8) != 0) {
        var_r31_1312 = 0;
        temp_f26_1313 = arg0.unk8;
        temp_f27_1314 = arg1.unk8;
        do {
            sp58 = -1.0f;
            sp48 = 1.0f;
            sp50 = -1.0f;
            sp54 = -1.0f;
            sp40 = 1.0f;
            sp44 = 1.0f;
            spA0 = (f64) sp50;
            spA8 = (f64) sp58;
            sp90 = (f64) sp40;
            sp98 = (f64) sp48;
            KDRand_Vector(spB0, *((MKVector3 *) &spA0));
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r30, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
            spE0 = sp30;
            sp38 = spB0.unk8 * 2000.0f;
            spE8 = (f64) sp38;
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r28, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f28 */);
            sp28 = temp_f26_1313 * 100.0f;
            sp70 = sp20;
            sp78 = (f64) sp28;
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r29, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            sp80 = sp10;
            sp18 = temp_f27_1314 + (f32) sp78;
            sp88 = (f64) sp18;
            ((ClusterBomb *) (M2C_FIELD(this, ClusterBomb **, 0x1B4)))->SpawnClusterBomb(*((MKVector3 *) &sp80), *((MKVector3 *) &spE0));
            var_r31_1312 += 1;
        } while (var_r31_1312 < 5);
    }
    Disable();
}
#endif

#if 0 // DRAFT: expression syntax error
void FireBombFX::Message(MKMessage *arg0) {
    this->unk188.Message(arg0);
    GameProp::Message(arg0);
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_sp8'
void FireBombFX::Update() {
    MKProp *temp_r3_1850;
    MKProp *var_r29_1873;
    ManagedLight *temp_r3_2290;
    ManagedLight *temp_r3_2419;
    ManagedLight *temp_r3_2436;
    f32 temp_f0_1941;
    f32 temp_f0_2437;
    f32 temp_f1_2149;
    f32 temp_f1_2289;
    f32 temp_f26_2258;
    f32 temp_f27_2080;
    f32 temp_f27_2123;
    f32 temp_f27_2183;
    f32 temp_f27_2226;
    f32 temp_f28_1635;
    f32 temp_f28_1747;
    f32 temp_f28_2075;
    f32 temp_f28_2118;
    f32 temp_f28_2178;
    f32 temp_f28_2221;
    f32 temp_f29_1742;
    f32 temp_f2_1531;
    f32 temp_f2_2319;
    f32 temp_f30_2070;
    f32 temp_f30_2173;
    f32 temp_f3_2311;
    f32 temp_f5_1541;
    f32 var_f0_1674;
    f32 var_f4_1833;
    f32 var_f6_1766;
    f32 var_f7_1524;
    f32 var_f7_2303;
    f64 temp_f0_1611;
    f64 temp_f1_1610;
    f64 temp_f3_1772;
    f64 temp_f3_1778;
    f64 temp_f3_1782;
    s32 temp_r0_1444;
    s32 temp_r0_1616;
    s32 temp_r3_1801;
    s32 var_r0_1811;
    s32 var_r7_1841;
    u8 var_r31_1713;
    void *temp_r3_1609;
    void *temp_r3_2295;
    void *temp_r3_2424;
    void *temp_r3_2439;
    temp_r0_1444 = M2C_FIELD(this, s32 *, 0x1BC);
    switch (temp_r0_1444) {                         /* switch 1; irregular */
    case 1:                                         /* switch 1 */
        arg_sp8 = 1;
        this->unk188.Update(GS_SpyroSWFireballLP, 1U, this->unkE0, (MKProp *) this, NULL, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
        break;
    case 2:                                         /* switch 1 */
        if (M2C_FIELD(gb.unk0->__vptr, s32 (**)(HeroInterface *), 8)(gb.unk0) == 1) {
            arg_sp8 = 1;
            this->unk188.Update(GS_SWCynderFireball2, 1U, this->unkE0, (MKProp *) this, NULL, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
        } else {
            arg_sp8 = 1;
            this->unk188.Update(GS_CynderBreathStart3, 1U, this->unkE0, (MKProp *) this, NULL, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
        }
        break;
    case 0:                                         /* switch 1 */
        arg_sp8 = 1;
        this->unk188.Update(GS_SpyroSpare2, 1U, this->unkE0, (MKProp *) this, NULL, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
        break;
    }
    if ((u8) this->unkE0 != 0) {
        var_f7_1524 = 0.5f * (0.85f * gUpdateTimeDelta);
        if (var_f7_1524 < 1.0f) {

        } else {
            var_f7_1524 = 1.0f;
        }
        temp_f2_1531 = this->unkC8;
        arg_sp2A0 = -1.0f;
        temp_f5_1541 = (var_f7_1524 * (150.0f - temp_f2_1531)) + temp_f2_1531;
        arg_sp290 = 1.0f;
        arg_sp298 = -1.0f;
        arg_sp29C = -1.0f;
        arg_sp288 = 1.0f;
        arg_sp28C = 1.0f;
        this->unkC8 = (var_f7_1524 * (150.0f - temp_f5_1541)) + temp_f5_1541;
        this->unk100 += 7.0f * gUpdateTimeDelta;
        arg_sp448 = (f64) arg_sp298;
        arg_sp450 = (f64) arg_sp2A0;
        arg_sp438 = (f64) arg_sp288;
        arg_sp440 = (f64) arg_sp290;
        KDRand_Vector(*((MKVector3 *) &arg_sp458), *((MKVector3 *) &arg_sp448));
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
        arg_sp468 = arg_sp278;
        arg_sp280 = arg_sp460 * 50.0f;
        arg_sp470 = (f64) arg_sp280;
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r4, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        arg_sp478 = arg_sp268;
        arg_sp270 = M2C_FIELD((this->unk8 + 0x30), f32 *, 8) + (f32) arg_sp470;
        arg_sp480 = (f64) arg_sp270;
        arg_sp25C = MKRand_Float(&gViewSeed, 100.0f, 200.0f);
        arg_sp258 = 0.0f;
        arg_sp260 = 0.0f;
        arg_sp428 = (f64) arg_sp258;
        arg_sp430 = (f64) arg_sp260;
        gb.unk240.Emit(*((MKVector3 *) &arg_sp478), *((MKVector3 *) &arg_sp428), 3.0f, 1.0f);
        temp_r3_1609 = this->unk8;
        temp_f1_1610 = M2C_FIELD(temp_r3_1609, f64 *, 0x30);
        temp_f0_1611 = M2C_FIELD(temp_r3_1609, f64 *, 0x38);
        arg_sp4F8 = temp_f1_1610;
        arg_sp500 = temp_f0_1611;
        arg_sp4E8 = temp_f1_1610;
        arg_sp4F0 = temp_f0_1611;
        temp_r0_1616 = M2C_FIELD(this, s32 *, 0x1BC);
        switch (temp_r0_1616) {                     /* switch 2; irregular */
        case 0:                                     /* switch 2 */
            arg_sp408.operator*(gUpdateTimeDelta);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            arg_sp418 = arg_sp98;
            temp_f28_1635 = gUpdateTimeDelta;
            arg_spA0 = (f32) arg_sp500 + arg_sp410;
            arg_sp4E8 = arg_sp98;
            arg_sp420 = (f64) arg_spA0;
            arg_sp4F0 = (f64) arg_spA0;
            MKVector(0.0f, -1960.0f, 0.0f);
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f28 */);
            arg_sp3F8 = arg_sp88;
            arg_sp90 = arg_sp3F0 * temp_f28_1635;
            arg_sp400 = (f64) arg_sp90;
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $r30, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            M2C_ERROR(/* unknown instruction: psq_stx $f0, $r30, $r0, 0x0, qr0 */);
            M2C_FIELD(this, f32 *, 0xD8) = (f32) (M2C_FIELD(this, f32 *, 0xD8) + (f32) arg_sp400);
            break;
        case 1:                                     /* switch 2 */
        case 2:                                     /* switch 2 */
            var_f0_1674 = (this->unk1D4 * gUpdateTimeDelta) + this->unk1D4;
            if (var_f0_1674 < 1.0f) {

            } else {
                var_f0_1674 = 1.0f;
            }
            if (var_f0_1674 > 0.0f) {

            } else {
                var_f0_1674 = 0.0f;
            }
            this->unk1D4 = var_f0_1674;
            arg_sp14 = 0.0f;
            arg_sp3D8.GetMeasure(this->unk1D4, (Matrix *) &this->unk1BC, KDSpline_PositionMixer);
            arg_sp4E8 = arg_sp3D8;
            arg_sp4F0 = arg_sp3E0;
            if (this->unk1D4 == 1.0f) {
                this->unk104 = 4.0f;
            }
            break;
        }
        var_r31_1713 = 0;
        arg_sp590 = 0.0f;
        arg_sp594 = 0.0f;
        arg_sp598 = 0.0f;
        arg_sp5A0 = 0.0f;
        arg_sp5A4 = 0.0f;
        arg_sp5A8 = 0.0f;
        arg_sp5B0 = 0.0f;
        arg_sp5B4 = 0.0f;
        arg_sp5B8 = 0.0f;
        arg_sp5BC = 1.0f;
        arg_sp5C0 = 0.0f;
        arg_sp5C4 = 0.0f;
        arg_sp5C8 = 0;
        arg_sp5C8 = 0;
        (s8) arg_sp5C8 = 0;
        arg_sp5CC = 0;
        arg_sp5D0 = 3.4028235e38f;
        arg_sp5D4 = 0;
        arg_sp5D8 = NULL;
        arg_sp5DC = -1;
        arg_sp5E0 = 0U;
        arg_sp4D8 = arg_sp4E8;
        arg_sp4E0 = arg_sp4F0;
        temp_f29_1742 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        temp_f28_1747 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        arg_sp248 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        arg_sp24C = temp_f28_1747;
        arg_sp250 = temp_f29_1742;
        arg_sp3C8 = (f64) arg_sp248;
        arg_sp3D0 = (f64) arg_sp250;
        var_f6_1766 = ((f32) arg_sp3D0 * (f32) arg_sp3D0) + (((f32) arg_sp3C8 * (f32) arg_sp3C8) + (arg_sp3CC * arg_sp3CC));
        if (var_f6_1766 > 1e-12f) {
            if (var_f6_1766 > 0.0f) {
                temp_f3_1772 = __frsqrte(var_f6_1766);
                temp_f3_1778 = 0.5 * temp_f3_1772 * -(((f64) var_f6_1766 * (temp_f3_1772 * temp_f3_1772)) - 3.0);
                temp_f3_1782 = 0.5 * temp_f3_1778 * -(((f64) var_f6_1766 * (temp_f3_1778 * temp_f3_1778)) - 3.0);
                var_f6_1766 = (f32) ((f64) var_f6_1766 * (0.5 * temp_f3_1782 * -(((f64) var_f6_1766 * (temp_f3_1782 * temp_f3_1782)) - 3.0)));
            } else if (var_f6_1766 < M2C_BITWISE(f32, 0.0)) {
                var_f6_1766 = __float_nan;
            } else {
                arg_sp10 = var_f6_1766;
                temp_r3_1801 = M2C_BITWISE(s32, arg_sp10) & 0x7F800000;
                switch (temp_r3_1801) {             /* switch 3; irregular */
                case 0x7F800000:                    /* switch 3 */
                    if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                        var_r0_1811 = 1;
                    } else {
                        var_r0_1811 = 2;
                    }
                    break;
                case 0x0:                           /* switch 3 */
                    if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                        var_r0_1811 = 5;
                    } else {
                        var_r0_1811 = 3;
                    }
                    break;
                default:                            /* switch 3 */
                    var_r0_1811 = 4;
                    break;
                }
                if (var_r0_1811 == 1) {
                    var_f6_1766 = __float_nan;
                }
            }
            var_f4_1833 = 1.0f / var_f6_1766;
        } else {
            var_f4_1833 = 0.0f;
        }
        var_r7_1841 = 0;
        arg_sp23C = arg_sp3CC * var_f4_1833;
        arg_sp238 = (f32) arg_sp3C8 * var_f4_1833;
        arg_sp240 = (f32) arg_sp3D0 * var_f4_1833;
        arg_sp4C8 = (f64) arg_sp238;
        arg_sp4D0 = (f64) arg_sp240;
        temp_r3_1850 = this->unk120;
        if ((temp_r3_1850 != NULL) && (M2C_FIELD(temp_r3_1850->unk0, s32 *, 0xC) & 8)) {
            var_r7_1841 = 0x08000000;
        }
        if (MKCollision_SweepSphereCollide(*((MKVector3 *) &arg_sp4F8), *((MKVector3 *) &arg_sp4E8), 40.0f, (MKCollisionResult *) &arg_sp590, (MKCollisionMode) 7, var_r7_1841) != 0) {
            if ((arg_sp5E0 != 0) && (arg_sp5D8 != NULL) && (var_r29_1873 = arg_sp5D8->unk8, ((var_r29_1873 == NULL) == 0))) {

            } else {
                var_r29_1873 = NULL;
            }
            if ((var_r29_1873 != NULL) && (var_r29_1873 != M2C_FIELD(gb.unk0->__vptr, u32 (**)(HeroInterface *), 0xC)(gb.unk0))) {
                var_r31_1713 = 1;
            } else if (var_r29_1873 == NULL) {
                var_r31_1713 = 1;
                arg_sp4C8 = (f64) arg_sp5A0;
                arg_sp4D0 = (f64) arg_sp5A8;
            }
            arg_sp4D8 = (f64) arg_sp590;
            arg_sp4E0 = (f64) arg_sp598;
        }
        if (var_r31_1713 != 0) {
            Explode(*((MKVector3 *) &arg_sp4C8), *((MKVector3 *) &arg_sp4D8), arg_sp5D8);
        } else {
            M2C_STRUCT_COPY((s32) &arg_sp54C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r5, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
            temp_f0_1941 = (f32) arg_sp4F0 - M2C_FIELD((MKModel_GetWorldMatrix(this->unk4) + 0x30), f32 *, 8);
            arg_sp220 = 0.0f;
            arg_sp230 = temp_f0_1941;
            arg_sp218 = 0.0f;
            arg_sp21C = 1.0f;
            arg_sp4B8 = arg_sp228;
            arg_sp4C0 = (f64) arg_sp230;
            arg_sp4A8 = (f64) arg_sp218;
            arg_sp4B0 = (f64) arg_sp220;
            KDMath_BuildMatrixFromFwd((Matrix *) &arg_sp550, *((MKVector3 *) &arg_sp4B8), (MKVector3 *) &arg_sp4A8);
            M2C_STRUCT_COPY((s32) &arg_sp50C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
            arg_sp510.RotateRoll((Matrix *) &arg_sp510, 2.0f * this->unk100);
            arg_sp510.Multiply3x3((Matrix *) &arg_sp510, (Matrix *) &arg_sp550);
            MKModel_SetPosition(this->unk4, *((MKVector3 *) &arg_sp4E8));
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r3, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
            arg_sp3B8 = arg_sp208;
            arg_sp210 = arg_sp528 * this->unkC8;
            arg_sp3C0 = (f64) arg_sp210;
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            arg_sp498 = arg_sp1F8;
            arg_sp200 = (f32) arg_sp4F0 + (f32) arg_sp3C0;
            arg_sp4A0 = (f64) arg_sp200;
            if ((s32) M2C_FIELD(this, s32 *, 0x1BC) == 2) {
                arg_sp24 = MKRand_Float(&gViewSeed, 6.0f, 8.0f);
                arg_sp1F0 = 0.0f;
                arg_sp1E8 = 0.0f;
                arg_sp1EC = 0.0f;
                arg_sp3B0 = (f64) arg_sp1F0;
                arg_sp3A8 = (f64) arg_sp1E8;
                gb.unk68->Emit(*((MKVector3 *) &arg_sp498), *((MKVector3 *) &arg_sp3A8), arg_sp24);
            } else {
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r3, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f27 */);
                arg_sp1E0 = arg_sp528 * 150.0f;
                arg_sp398 = arg_sp1D8;
                arg_sp3A0 = (f64) arg_sp1E0;
                arg_sp20 = 1.4f * this->unk128;
                gb.EmitDust(*((MKVector3 *) &arg_sp498), *((MKVector3 *) &arg_sp398), arg_sp20, 0.0f);
            }
            this->unk104 += gUpdateTimeDelta;
            if (this->unk104 > 4.0f) {
                Explode(*((MKVector3 *) &arg_sp4C8), *((MKVector3 *) &arg_sp4E8), NULL);
            }
        }
        if ((s32) M2C_FIELD(this, s32 *, 0x1BC) == 2) {
            temp_f30_2070 = this->unkC8;
            temp_f28_2075 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
            temp_f27_2080 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
            arg_sp1C8 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
            arg_sp1CC = temp_f27_2080;
            arg_sp1D0 = temp_f28_2075;
            arg_sp368 = (f64) arg_sp1C8;
            arg_sp370 = (f64) arg_sp1D0;
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
            arg_sp378 = arg_sp1B8;
            arg_sp1C0 = (f32) arg_sp370 * temp_f30_2070;
            arg_sp380 = (f64) arg_sp1C0;
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            arg_sp388 = arg_sp1A8;
            arg_sp1B0 = (f32) arg_sp4F0 + (f32) arg_sp380;
            arg_sp390 = (f64) arg_sp1B0;
            temp_f28_2118 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
            temp_f27_2123 = MKRand_Float(&gViewSeed, 0.0f, 1.0f);
            arg_sp198 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
            arg_sp19C = temp_f27_2123;
            arg_sp1A0 = temp_f28_2118;
            arg_sp348 = (f64) arg_sp198;
            arg_sp350 = (f64) arg_sp1A0;
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f26 */);
            arg_sp358 = arg_sp188;
            arg_sp190 = (f32) arg_sp350 * 1000.0f;
            arg_sp360 = (f64) arg_sp190;
            temp_f1_2149 = MKRand_Float(&gViewSeed, 15.0f, 20.0f);
            arg_sp178 = 1.0f;
            arg_sp17C = 0.2f;
            arg_sp1C = temp_f1_2149;
            arg_sp180 = 0.7f;
            arg_sp184 = 1.0f;
            arg_sp338 = (f64) arg_sp178;
            arg_sp340 = (f64) arg_sp180;
            gb.unk74->Emit(*((MKVector3 *) &arg_sp388), *((MKVector3 *) &arg_sp358), arg_sp1C, *((MKVector4 *) &arg_sp338), -1000.0f);
        } else {
            temp_f30_2173 = this->unkC8;
            temp_f28_2178 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
            temp_f27_2183 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
            arg_sp168 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
            arg_sp16C = temp_f27_2183;
            arg_sp170 = temp_f28_2178;
            arg_sp308 = (f64) arg_sp168;
            arg_sp310 = (f64) arg_sp170;
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
            arg_sp318 = arg_sp158;
            arg_sp160 = (f32) arg_sp310 * temp_f30_2173;
            arg_sp320 = (f64) arg_sp160;
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            arg_sp328 = arg_sp148;
            arg_sp150 = (f32) arg_sp4F0 + (f32) arg_sp320;
            arg_sp330 = (f64) arg_sp150;
            temp_f28_2221 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
            temp_f27_2226 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
            arg_sp138 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
            arg_sp13C = temp_f27_2226;
            arg_sp140 = temp_f28_2221;
            arg_sp2E8 = (f64) arg_sp138;
            arg_sp2F0 = (f64) arg_sp140;
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f26 */);
            arg_sp2F8 = arg_sp128;
            arg_sp130 = (f32) arg_sp2F0 * 400.0f;
            arg_sp300 = (f64) arg_sp130;
            arg_sp18 = MKRand_Float(&gViewSeed, 2.5f, 8.0f);
            temp_f26_2258 = MKRand_Float(&gViewSeed, 0.8f, 1.0f);
            arg_sp118 = MKRand_Float(&gViewSeed, 0.8f, 1.0f);
            arg_sp11C = temp_f26_2258;
            arg_sp120 = 0.0f;
            arg_sp124 = 1.0f;
            arg_sp2D8 = (f64) arg_sp118;
            arg_sp2E0 = (f64) arg_sp120;
            gb.unk74->Emit(*((MKVector3 *) &arg_sp328), *((MKVector3 *) &arg_sp2F8), arg_sp18, *((MKVector4 *) &arg_sp2D8), -1000.0f);
        }
        if ((ManagedLight *) this->unk108 != NULL) {
            temp_f1_2289 = MKRand_Float(&gViewSeed, 0.2f, 0.6f);
            temp_r3_2290 = this->unk108;
            temp_r3_2290->unk10 = arg_sp4E8;
            temp_r3_2290->unk18 = arg_sp4F0;
            temp_r3_2295 = temp_r3_2290->unk3C;
            if (temp_r3_2295 != NULL) {
                M2C_FIELD(temp_r3_2295, f64 *, 0x10) = arg_sp4E8;
                M2C_FIELD(temp_r3_2295, f64 *, 0x18) = arg_sp4F0;
            }
            var_f7_2303 = 0.1f;
            if (1.0f > 0.1f) {

            } else {
                var_f7_2303 = 1.0f;
            }
            temp_f3_2311 = this->unk124;
            arg_spF8 = 1.0f;
            temp_f2_2319 = (var_f7_2303 * (1000.0f - temp_f3_2311)) + temp_f3_2311;
            arg_spFC = 0.0f;
            arg_sp100 = 0.0f;
            arg_sp104 = 1.0f;
            this->unk124 = (var_f7_2303 * (1000.0f - temp_f2_2319)) + temp_f2_2319;
            arg_sp108 = 1.0f;
            arg_sp10C = 1.0f;
            arg_sp110 = 0.0f;
            arg_sp114 = 1.0f;
            arg_sp2B8 = (f64) arg_spF8;
            arg_sp2C0 = (f64) arg_sp100;
            arg_sp2C8 = (f64) arg_sp108;
            arg_sp2D0 = (f64) arg_sp110;
            if ((0.5f * (temp_f1_2289 * 1.0f)) < 1.0f) {

            }
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f3, $f2 */);
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f5, $f4 */);
            arg_spC8 = arg_sp78;
            arg_spD0 = arg_sp80;
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f25 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f25 */);
            arg_spB8 = arg_sp68;
            arg_spC0 = arg_sp70;
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f2, $f0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f4, $f0 */);
            arg_spA8 = arg_sp58;
            arg_spB0 = arg_sp60;
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f3, $f2 */);
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f5, $f3 */);
            arg_spE8 = arg_sp48;
            arg_spF0 = arg_sp50;
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f25 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f25 */);
            arg_spD8 = arg_sp38;
            arg_spE0 = arg_sp40;
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f2, $f0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f3, $f0 */);
            arg_sp488 = arg_sp28;
            arg_sp490 = arg_sp30;
            KDMath_Smooth<MKVector4>(*((MKVector4 *) &arg_sp2A8), this->unk110, 0.5f, 1.0f);
            M2C_FIELD(this, f64 *, 0x110) = arg_sp2A8;
            M2C_FIELD(this, f64 *, 0x118) = arg_sp2B0;
            temp_r3_2419 = this->unk108;
            temp_r3_2419->unk20 = M2C_FIELD(this, f64 *, 0x110);
            temp_r3_2419->unk28 = M2C_FIELD(this, f64 *, 0x118);
            temp_r3_2424 = temp_r3_2419->unk3C;
            if (temp_r3_2424 != NULL) {
                M2C_FIELD(temp_r3_2424, f64 *, 0) = (f64) M2C_FIELD(this, f64 *, 0x110);
                M2C_FIELD(temp_r3_2424, f64 *, 8) = (f64) M2C_FIELD(this, f64 *, 0x118);
            }
            temp_r3_2436 = this->unk108;
            temp_f0_2437 = (this->unkC8 / 50.0f) * this->unk124;
            temp_r3_2436->unk38 = temp_f0_2437;
            temp_r3_2439 = temp_r3_2436->unk3C;
            if (temp_r3_2439 != NULL) {
                M2C_FIELD(temp_r3_2439, f32 *, 0x20) = temp_f0_2437;
                M2C_FIELD(temp_r3_2439, f32 *, 0x24) = (f32) (temp_f0_2437 * temp_f0_2437);
                M2C_FIELD(temp_r3_2439, f32 *, 0x28) = (f32) (1.0f / temp_f0_2437);
                M2C_FIELD(temp_r3_2439, f32 *, 0x2C) = (f32) (1.0f / M2C_FIELD(temp_r3_2439, f32 *, 0x24));
            }
        }
    }
}
#endif

#if 0 // DRAFT: pointer/array required
void FireBombFX::Resolve() {
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    ManagedLight *temp_r4_2600;

    KDPropEx::Resolve();
    sp30 = 0.0f;
    sp40 = 0.0f;
    sp18 = 1.0f;
    sp1C = 1.0f;
    sp20 = 0.0f;
    sp24 = 1.0f;
    sp28 = 0.0f;
    sp2C = 0.0f;
    sp38 = 0.0f;
    sp3C = 0.0f;
    sp58 = (f64) sp18;
    sp60 = (f64) sp20;
    sp68 = (f64) sp28;
    sp70 = (f64) sp30;
    sp78 = (f64) sp38;
    sp80 = (f64) sp40;
    this->unk108 = gb.unk80->AllocManagedLight(*((MKVector3 *) &sp78), *((MKVector3 *) &sp68), *((MKVector4 *) &sp58), 1000.0f, lit_536, lit_537);
    temp_r4_2600 = this->unk108;
    if (temp_r4_2600 != NULL) {
        gb.unk80->EnableLight(temp_r4_2600, 0U);
    }
    sp8 = 1.0f;
    spC = 1.0f;
    sp10 = 1.0f;
    sp14 = 1.0f;
    sp48 = (f64) sp8;
    sp50 = (f64) sp10;
    this->unkCC->InitData(this->unk4, lit_540, M2C_FIELD(checked_cast<FireBombFXDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s8 **, 0xE4), lit_541, *((MKVector4 *) &sp48), 2.5f, 1U, 0.4f);
}
#endif

#if 0 // DRAFT: expression syntax error
void FireBombFX::Init() {
    GameProp::Init();
    this->unkCC = checked_cast<ShapedTrailFX *, MKProp>(gMK->CreateProp("ShapedTrailFX"));
    this->unkF8 = checked_cast<Explosion4 *, MKProp>(gMK->CreateProp("Explosion4"));
    this->unkE0 = 0;
    this->unkFC = 0.0f;
    this->unk100 = 0.0f;
    this->unk104 = 0.0f;
    this->unkC8 = 0.0f;
    this->unk108 = NULL;
    this->unk110.unk0 = 1.0f;
    this->unk110.unk4 = 1.0f;
    this->unk110.unk8 = 0.0f;
    this->unk110.unkC = 1.0f;
    this->unk120 = NULL;
    this->unk124 = 1000.0f;
    this->unk188.Init(0.25f, 0.25f);
    M2C_FIELD(this, s32 *, 0x1B4) = checked_cast<ClusterBomb *, MKProp>(gMK->CreateProp("ClusterBomb"));
    M2C_FIELD(this, s8 *, 0x1B8) = 0;
    this->unk1BC.Init(3, 0U);
}
#endif
