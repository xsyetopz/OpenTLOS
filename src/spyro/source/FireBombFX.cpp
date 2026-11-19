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
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDSpline.h"
#include "spyro/source/ManagedLight.h"
#include "spyro/source/ShapedTrailFX.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
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
    temp_r30_175 = M2C_FIELD(GameData::gameData, s32 *, 0x158);
    temp_r4_176 = temp_r30_175 << 5;
    temp_r31_178 = *(&GameData::gameData[0x70] + (temp_r4_176 + 0x7C));
    temp_r5_180 = &GameData::gameData[0x70] + (temp_r4_176 + 0x64);
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
    this->unk130.Init(arg3, ((GameStats *) ((GameStats *) &GameData::gameData[0x70]))->GetBreathAttackDamage(temp_r30_175, temp_r31_178, var_r6_194), temp_r31_178, var_r23_213, temp_r30_175, temp_r30_175, 0, -1);
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
        temp_r3_255 = gb.unk0->GetCollisionInfo(temp_f1_245);
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
        if (((s32) M2C_FIELD(this, s32 *, 0x1BC) == 2) && (gb.unk0->GetHeroType() == 0)) {
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

#if 0 // DRAFT: function call 'memcpy(long, Matrix *, int)' does not match
void FireBombFX::DrawFlameBall() {
    Matrix sp2C0;
    Matrix sp280;
    f64 sp270;
    f64 sp268;
    f64 sp260;
    f64 sp258;
    f64 sp250;
    f64 sp248;
    f64 sp240;
    f64 sp238;
    f64 sp230;
    f64 sp228;
    f64 sp220;                                      /* compiler-managed */
    f64 sp218;                                      /* compiler-managed */
    f64 sp210;                                      /* compiler-managed */
    f64 sp208;                                      /* compiler-managed */
    f64 sp200;
    f64 sp1F8;
    f64 sp1F0;
    f64 sp1E8;
    f64 sp1E0;
    f64 sp1D8;
    MKVector3 sp1C8;
    MKVector3 sp1B8;
    f64 sp1B0;
    f64 sp1A8;
    f64 sp1A0;
    f64 sp198;
    MKVector3 sp188;
    MKVector3 sp178;
    f64 sp170;
    f64 sp168;
    MKVector3 sp158;
    f64 sp150;
    f64 sp148;
    MKVector3 sp138;
    f64 sp130;
    f64 sp128;
    f64 sp120;
    f64 sp118;
    MKVector3 sp108;
    f64 sp100;
    f64 spF8;
    MKVector3 spE8;
    f32 spE4;
    f32 spE0;
    f32 spDC;
    f32 spD8;
    f32 spD0;
    f32 spCC;
    f32 spC8;
    f32 spC0;
    f32 spBC;
    f32 spB8;
    f32 spB0;
    f32 spAC;
    f32 spA8;
    f32 spA0;
    f32 sp9C;
    f32 sp98;
    f32 sp90;
    f32 sp80;
    f32 sp70;
    f32 sp60;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 temp_f0_624;
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

    M2C_STRUCT_COPY((s32) &sp280.unk3C + 4, MKView_GetCameraMatrix() - 4 + 4, 0x40);
    spD8 = 0.5f;
    spDC = 0.5f;
    spE0 = 0.5f;
    spE4 = 1.0f;
    sp228 = (f64) spD8;
    sp230 = (f64) spE0;
    MKMaterial_SetMaterial(M2C_FIELD(checked_cast<FireBombFXDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), MKMaterial **, 0xEC));
    MKPrimitive(0xC, 0);
    var_r24_585 = 0;
    do {
        spD0 = 0.0f;
        spC0 = 0.0f;
        spC8 = 0.0f;
        spCC = 1.0f;
        spB8 = 1.0f;
        spBC = 0.0f;
        sp218 = (f64) spC8;
        sp220 = (f64) spD0;
        sp208 = (f64) spB8;
        sp210 = (f64) spC0;
        sp280.SetIdentity();
        if (var_r24_585 == 1) {
            sp280.RotateRoll(&sp280, this->unk100);
        } else {
            sp280.RotateRoll(&sp280, -this->unk100);
        }
        temp_f0_624 = M2C_BITWISE(f32, sp280);
        spA8 = sp280.unk30 + (((f32) sp220 * sp280.unk20) + (((f32) sp218 * temp_f0_624) + (unksp21C * sp280.unk10)));
        spAC = sp280.unk34 + (((f32) sp220 * sp280.unk24) + (((f32) sp218 * sp280.unk4) + (unksp21C * sp280.unk14)));
        spB0 = sp280.unk38 + (((f32) sp220 * sp280.unk28) + (((f32) sp218 * sp280.unk8) + (unksp21C * sp280.unk18)));
        sp218 = (f64) spA8;
        sp220 = (f64) spB0;
        sp98 = sp280.unk30 + (((f32) sp210 * sp280.unk20) + (((f32) sp208 * temp_f0_624) + (unksp20C * sp280.unk10)));
        sp9C = sp280.unk34 + (((f32) sp210 * sp280.unk24) + (((f32) sp208 * sp280.unk4) + (unksp20C * sp280.unk14)));
        spA0 = sp280.unk38 + (((f32) sp210 * sp280.unk28) + (((f32) sp208 * sp280.unk8) + (unksp20C * sp280.unk18)));
        var_f4_677 = ((f32) sp220 * (f32) sp220) + (((f32) sp218 * (f32) sp218) + (unksp21C * unksp21C));
        sp1F8 = (f64) spA8;
        sp200 = (f64) spB0;
        sp1E8 = (f64) sp98;
        sp1F0 = (f64) spA0;
        sp208 = (f64) sp98;
        sp210 = (f64) spA0;
        if (var_f4_677 > 0.000001f) {
            if (var_f4_677 > 0.0f) {
                temp_f1_690 = __frsqrte(var_f4_677);
                temp_f1_696 = 0.5 * temp_f1_690 * -(((f64) var_f4_677 * (temp_f1_690 * temp_f1_690)) - 3.0);
                temp_f1_700 = 0.5 * temp_f1_696 * -(((f64) var_f4_677 * (temp_f1_696 * temp_f1_696)) - 3.0);
                var_f4_677 = (f32) ((f64) var_f4_677 * (0.5 * temp_f1_700 * -(((f64) var_f4_677 * (temp_f1_700 * temp_f1_700)) - 3.0)));
            } else if (var_f4_677 < M2C_BITWISE(f32, 0.0)) {
                var_f4_677 = __float_nan;
            } else {
                sp14 = var_f4_677;
                temp_r3_719 = M2C_BITWISE(s32, sp14) & 0x7F800000;
                switch (temp_r3_719) {              /* switch 1; irregular */
                case 0x7F800000:                    /* switch 1 */
                    if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                        var_r0_729 = 1;
                    } else {
                        var_r0_729 = 2;
                    }
                    break;
                case 0x0:                           /* switch 1 */
                    if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
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
        var_f6_768 = ((f32) sp210 * (f32) sp210) + (((f32) sp208 * (f32) sp208) + (unksp20C * unksp20C));
        sp218 = (f32) sp218 * var_f5_751;
        unksp21C *= var_f5_751;
        sp220 = (f32) sp220 * var_f5_751;
        if (var_f6_768 > 0.000001f) {
            if (var_f6_768 > 0.0f) {
                temp_f1_778 = __frsqrte(var_f6_768);
                temp_f1_784 = 0.5 * temp_f1_778 * -(((f64) var_f6_768 * (temp_f1_778 * temp_f1_778)) - 3.0);
                temp_f1_788 = 0.5 * temp_f1_784 * -(((f64) var_f6_768 * (temp_f1_784 * temp_f1_784)) - 3.0);
                var_f6_768 = (f32) ((f64) var_f6_768 * (0.5 * temp_f1_788 * -(((f64) var_f6_768 * (temp_f1_788 * temp_f1_788)) - 3.0)));
            } else if (var_f6_768 < M2C_BITWISE(f32, 0.0)) {
                var_f6_768 = __float_nan;
            } else {
                sp10 = var_f6_768;
                temp_r3_807 = M2C_BITWISE(s32, sp10) & 0x7F800000;
                switch (temp_r3_807) {              /* switch 2; irregular */
                case 0x7F800000:                    /* switch 2 */
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_817 = 1;
                    } else {
                        var_r0_817 = 2;
                    }
                    break;
                case 0x0:                           /* switch 2 */
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
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
        temp_f5_848 = (f32) sp208 * var_f2_839;
        temp_f4_850 = unksp20C * var_f2_839;
        temp_f3_851 = (f32) sp210 * var_f2_839;
        sp208 = temp_f5_848;
        unksp20C = temp_f4_850;
        sp48 = -temp_f5_848;
        sp4C = -temp_f4_850;
        sp50 = -temp_f3_851;
        sp210 = temp_f3_851;
        sp1A8 = (f64) sp48;
        sp1B0 = (f64) sp50;
        sp1B8.operator*(this->unkC8 * this->unk128);
        sp1C8.operator*(this->unkC8 * this->unk128);
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r31, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        sp238 = sp88;
        sp90 = sp1C8.unk8 + sp1B8.unk8;
        sp1D8 = sp88;
        sp240 = (f64) sp90;
        sp1E0 = (f64) sp90;
        sp178.operator*(this->unkC8 * this->unk128);
        sp188.operator*(this->unkC8 * this->unk128);
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r30, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        sp40 = -sp210;
        sp80 = sp188.unk8 + sp178.unk8;
        sp38 = -sp208;
        sp3C = -unksp20C;
        sp248 = sp78;
        sp250 = (f64) sp80;
        sp128 = (f64) sp38;
        sp130 = (f64) sp40;
        sp198 = sp78;
        sp1A0 = (f64) sp80;
        sp138.operator*(this->unkC8 * this->unk128);
        sp28 = -sp218;
        sp2C = -unksp21C;
        sp30 = -sp220;
        sp148 = (f64) sp28;
        sp150 = (f64) sp30;
        sp158.operator*(this->unkC8 * this->unk128);
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r29, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        sp258 = sp68;
        sp70 = sp158.unk8 + sp138.unk8;
        sp168 = sp68;
        sp260 = (f64) sp70;
        sp170 = (f64) sp70;
        spE8.operator*(this->unkC8 * this->unk128);
        sp18 = -sp218;
        sp1C = -unksp21C;
        sp20 = -sp220;
        spF8 = (f64) sp18;
        sp100 = (f64) sp20;
        sp108.operator*(this->unkC8 * this->unk128);
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r28, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        sp268 = sp58;
        sp60 = sp108.unk8 + spE8.unk8;
        sp118 = sp58;
        sp270 = (f64) sp60;
        sp120 = (f64) sp60;
        temp_r3_1007 = MKModel_GetWorldMatrix(this->unk4);
        sp2C0.unk30 = M2C_FIELD(temp_r3_1007, f32 *, 0x30);
        sp2C0.unk34 = M2C_FIELD(temp_r3_1007, f32 *, 0x34);
        sp2C0.unk38 = M2C_FIELD(temp_r3_1007, f32 *, 0x38);
        sp2C0.unk3C = 1.0f;
        MKSetMatrix(sp2C0);
        MKBegin(4);
        MKSetColorV(*((MKVector4 *) &sp228));
        MKSetTexCoord1F(0.0f, 1.0f);
        MKSetPositionV(*((MKVector3 *) &sp238));
        MKSetColorV(*((MKVector4 *) &sp228));
        MKSetTexCoord1F(1.0f, 1.0f);
        MKSetPositionV(*((MKVector3 *) &sp248));
        MKSetColorV(*((MKVector4 *) &sp228));
        MKSetTexCoord1F(0.0f, 0.0f);
        MKSetPositionV(*((MKVector3 *) &sp258));
        MKSetColorV(*((MKVector4 *) &sp228));
        MKSetTexCoord1F(1.0f, 0.0f);
        MKSetPositionV(*((MKVector3 *) &sp268));
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

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'HeroInterface'
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
    if (((s32) M2C_FIELD(this, s32 *, 0x1BC) == 1) || (gb.unk0->GetHeroType() == 2)) {
        this->unkF8->unk88 = GS_Explosion7;
    } else if ((s32) M2C_FIELD(this, s32 *, 0x1BC) == 2) {
        if (gb.unk0->GetHeroType() == 1) {
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
        temp_r3_1221 = M2C_FIELD(gb.unk0->GetProp(), void **, 8);
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
            if (gb.unk0->GetHeroType() == 0) {
                this->unk130.unk4C = GS_CynderBreathHitSpyro;
            }
            M2C_FIELD(M2C_FIELD(gb.unk0->GetProp(), void **, 0x44), M2C_UNK (**)(BreathHitMessage *), 0x2C)(&this->unk130);
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

#if 0 // DRAFT: expression syntax error
void FireBombFX::Update() {
    u8 sp5E0;
    s32 sp5DC;
    MKCollisionInfo *sp5D8;
    s32 sp5D4;
    f32 sp5D0;
    s32 sp5CC;
    s8 sp5CB;
    s8 sp5CA;
    s16 sp5C8;
    f32 sp5C4;
    f32 sp5C0;
    f32 sp5BC;
    f32 sp5B8;
    f32 sp5B4;
    f32 sp5B0;
    f32 sp5A8;
    f32 sp5A4;
    f32 sp5A0;
    f32 sp598;
    f32 sp594;
    f32 sp590;
    Matrix sp550;
    Matrix sp510;
    M2C_UNK sp50C;
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
    f64 sp4A8;
    f64 sp4A0;
    f64 sp498;
    f64 sp490;
    f64 sp488;
    f64 sp480;
    f64 sp478;
    f64 sp470;
    f64 sp468;
    MKVector3 sp458;
    f64 sp450;
    f64 sp448;
    f64 sp440;
    f64 sp438;
    f64 sp430;
    f64 sp428;
    f64 sp420;
    f64 sp418;
    MKVector3 sp408;
    f64 sp400;
    f64 sp3F8;
    KDUniformSpline sp3D8;
    f64 sp3D0;
    f64 sp3C8;
    f64 sp3C0;
    f64 sp3B8;
    f64 sp3B0;
    f64 sp3A8;
    f64 sp3A0;
    f64 sp398;
    f64 sp390;
    f64 sp388;
    f64 sp380;
    f64 sp378;
    f64 sp370;
    f64 sp368;
    f64 sp360;
    f64 sp358;
    f64 sp350;
    f64 sp348;
    f64 sp340;
    f64 sp338;
    f64 sp330;
    f64 sp328;
    f64 sp320;
    f64 sp318;
    f64 sp310;
    f64 sp308;
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
    MKVector4 sp2A8;
    f32 sp2A0;
    f32 sp29C;
    f32 sp298;
    f32 sp290;
    f32 sp28C;
    f32 sp288;
    f32 sp280;
    f32 sp270;
    f32 sp260;
    f32 sp25C;
    f32 sp258;
    f32 sp250;
    f32 sp24C;
    f32 sp248;
    f32 sp240;
    f32 sp23C;
    f32 sp238;
    f32 sp230;
    f32 sp220;
    f32 sp21C;
    f32 sp218;
    f32 sp210;
    f32 sp200;
    f32 sp1F0;
    f32 sp1EC;
    f32 sp1E8;
    f32 sp1E0;
    f32 sp1D0;
    f32 sp1CC;
    f32 sp1C8;
    f32 sp1C0;
    f32 sp1B0;
    f32 sp1A0;
    f32 sp19C;
    f32 sp198;
    f32 sp190;
    f32 sp184;
    f32 sp180;
    f32 sp17C;
    f32 sp178;
    f32 sp170;
    f32 sp16C;
    f32 sp168;
    f32 sp160;
    f32 sp150;
    f32 sp140;
    f32 sp13C;
    f32 sp138;
    f32 sp130;
    f32 sp124;
    f32 sp120;
    f32 sp11C;
    f32 sp118;
    f32 sp114;
    f32 sp110;
    f32 sp10C;
    f32 sp108;
    f32 sp104;
    f32 sp100;
    f32 spFC;
    f32 spF8;
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
    f32 sp90;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    s32 sp8;
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
        sp8 = 1;
        this->unk188.Update(GS_SpyroSWFireballLP, 1U, this->unkE0, (MKProp *) this, NULL, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
        break;
    case 2:                                         /* switch 1 */
        if (gb.unk0->GetHeroType() == 1) {
            sp8 = 1;
            this->unk188.Update(GS_SWCynderFireball2, 1U, this->unkE0, (MKProp *) this, NULL, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
        } else {
            sp8 = 1;
            this->unk188.Update(GS_CynderBreathStart3, 1U, this->unkE0, (MKProp *) this, NULL, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
        }
        break;
    case 0:                                         /* switch 1 */
        sp8 = 1;
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
        sp2A0 = -1.0f;
        temp_f5_1541 = (var_f7_1524 * (150.0f - temp_f2_1531)) + temp_f2_1531;
        sp290 = 1.0f;
        sp298 = -1.0f;
        sp29C = -1.0f;
        sp288 = 1.0f;
        sp28C = 1.0f;
        this->unkC8 = (var_f7_1524 * (150.0f - temp_f5_1541)) + temp_f5_1541;
        this->unk100 += 7.0f * gUpdateTimeDelta;
        sp448 = (f64) sp298;
        sp450 = (f64) sp2A0;
        sp438 = (f64) sp288;
        sp440 = (f64) sp290;
        KDRand_Vector(sp458, *((MKVector3 *) &sp448));
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
        sp468 = sp278;
        sp280 = sp458.unk8 * 50.0f;
        sp470 = (f64) sp280;
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r4, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        sp478 = sp268;
        sp270 = M2C_FIELD((this->unk8 + 0x30), f32 *, 8) + (f32) sp470;
        sp480 = (f64) sp270;
        sp25C = MKRand_Float(&gViewSeed, 100.0f, 200.0f);
        sp258 = 0.0f;
        sp260 = 0.0f;
        sp428 = (f64) sp258;
        sp430 = (f64) sp260;
        gb.unk240.Emit(*((MKVector3 *) &sp478), *((MKVector3 *) &sp428), 3.0f, 1.0f);
        temp_r3_1609 = this->unk8;
        temp_f1_1610 = M2C_FIELD(temp_r3_1609, f64 *, 0x30);
        temp_f0_1611 = M2C_FIELD(temp_r3_1609, f64 *, 0x38);
        sp4F8 = temp_f1_1610;
        sp500 = temp_f0_1611;
        sp4E8 = temp_f1_1610;
        sp4F0 = temp_f0_1611;
        temp_r0_1616 = M2C_FIELD(this, s32 *, 0x1BC);
        switch (temp_r0_1616) {                     /* switch 2; irregular */
        case 0:                                     /* switch 2 */
            sp408.operator*(gUpdateTimeDelta);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            sp418 = sp98;
            temp_f28_1635 = gUpdateTimeDelta;
            spA0 = (f32) sp500 + sp408.unk8;
            sp4E8 = sp98;
            sp420 = (f64) spA0;
            sp4F0 = (f64) spA0;
            MKVector(0.0f, -1960.0f, 0.0f);
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f28 */);
            sp3F8 = sp88;
            sp90 = sp3F0 * temp_f28_1635;
            sp400 = (f64) sp90;
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $r30, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            M2C_ERROR(/* unknown instruction: psq_stx $f0, $r30, $r0, 0x0, qr0 */);
            M2C_FIELD(this, f32 *, 0xD8) = (f32) (M2C_FIELD(this, f32 *, 0xD8) + (f32) sp400);
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
            sp14 = 0.0f;
            sp3D8.GetMeasure(this->unk1D4, (Matrix *) &this->unk1BC, KDSpline_PositionMixer);
            sp4E8 = M2C_BITWISE(f64, sp3D8);
            sp4F0 = (f64) sp3D8.unk8;
            if (this->unk1D4 == 1.0f) {
                this->unk104 = 4.0f;
            }
            break;
        }
        var_r31_1713 = 0;
        sp590 = 0.0f;
        sp594 = 0.0f;
        sp598 = 0.0f;
        sp5A0 = 0.0f;
        sp5A4 = 0.0f;
        sp5A8 = 0.0f;
        sp5B0 = 0.0f;
        sp5B4 = 0.0f;
        sp5B8 = 0.0f;
        sp5BC = 1.0f;
        sp5C0 = 0.0f;
        sp5C4 = 0.0f;
        sp5C8 = 0;
        sp5CA = 0;
        sp5CB = 0;
        sp5CC = 0;
        sp5D0 = 3.4028235e38f;
        sp5D4 = 0;
        sp5D8 = NULL;
        sp5DC = -1;
        sp5E0 = 0;
        sp4D8 = sp4E8;
        sp4E0 = sp4F0;
        temp_f29_1742 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        temp_f28_1747 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        sp248 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        sp24C = temp_f28_1747;
        sp250 = temp_f29_1742;
        sp3C8 = (f64) sp248;
        sp3D0 = (f64) sp250;
        var_f6_1766 = ((f32) sp3D0 * (f32) sp3D0) + (((f32) sp3C8 * (f32) sp3C8) + (unksp3CC * unksp3CC));
        if (var_f6_1766 > 1e-12f) {
            if (var_f6_1766 > 0.0f) {
                temp_f3_1772 = __frsqrte(var_f6_1766);
                temp_f3_1778 = 0.5 * temp_f3_1772 * -(((f64) var_f6_1766 * (temp_f3_1772 * temp_f3_1772)) - 3.0);
                temp_f3_1782 = 0.5 * temp_f3_1778 * -(((f64) var_f6_1766 * (temp_f3_1778 * temp_f3_1778)) - 3.0);
                var_f6_1766 = (f32) ((f64) var_f6_1766 * (0.5 * temp_f3_1782 * -(((f64) var_f6_1766 * (temp_f3_1782 * temp_f3_1782)) - 3.0)));
            } else if (var_f6_1766 < M2C_BITWISE(f32, 0.0)) {
                var_f6_1766 = __float_nan;
            } else {
                sp10 = var_f6_1766;
                temp_r3_1801 = M2C_BITWISE(s32, sp10) & 0x7F800000;
                switch (temp_r3_1801) {             /* switch 3; irregular */
                case 0x7F800000:                    /* switch 3 */
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_1811 = 1;
                    } else {
                        var_r0_1811 = 2;
                    }
                    break;
                case 0x0:                           /* switch 3 */
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
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
        sp23C = unksp3CC * var_f4_1833;
        sp238 = (f32) sp3C8 * var_f4_1833;
        sp240 = (f32) sp3D0 * var_f4_1833;
        sp4C8 = (f64) sp238;
        sp4D0 = (f64) sp240;
        temp_r3_1850 = this->unk120;
        if ((temp_r3_1850 != NULL) && (M2C_FIELD(temp_r3_1850->unk0, s32 *, 0xC) & 8)) {
            var_r7_1841 = 0x08000000;
        }
        if (MKCollision_SweepSphereCollide(*((MKVector3 *) &sp4F8), *((MKVector3 *) &sp4E8), 40.0f, (MKCollisionResult *) &sp590, (MKCollisionMode) 7, var_r7_1841) != 0) {
            if ((sp5E0 != 0) && (sp5D8 != NULL) && (var_r29_1873 = sp5D8->unk8, ((var_r29_1873 == NULL) == 0))) {

            } else {
                var_r29_1873 = NULL;
            }
            if ((var_r29_1873 != NULL) && (var_r29_1873 != gb.unk0->GetProp())) {
                var_r31_1713 = 1;
            } else if (var_r29_1873 == NULL) {
                var_r31_1713 = 1;
                sp4C8 = (f64) sp5A0;
                sp4D0 = (f64) sp5A8;
            }
            sp4D8 = (f64) sp590;
            sp4E0 = (f64) sp598;
        }
        if (var_r31_1713 != 0) {
            Explode(*((MKVector3 *) &sp4C8), *((MKVector3 *) &sp4D8), sp5D8);
        } else {
            M2C_STRUCT_COPY((s32) &sp510.unk3C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r5, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
            temp_f0_1941 = (f32) sp4F0 - M2C_FIELD((MKModel_GetWorldMatrix(this->unk4) + 0x30), f32 *, 8);
            sp220 = 0.0f;
            sp230 = temp_f0_1941;
            sp218 = 0.0f;
            sp21C = 1.0f;
            sp4B8 = sp228;
            sp4C0 = (f64) sp230;
            sp4A8 = (f64) sp218;
            sp4B0 = (f64) sp220;
            KDMath_BuildMatrixFromFwd(&sp550, *((MKVector3 *) &sp4B8), (MKVector3 *) &sp4A8);
            M2C_STRUCT_COPY((s32) &sp50C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
            sp510.RotateRoll(&sp510, 2.0f * this->unk100);
            sp510.Multiply3x3(&sp510, &sp550);
            MKModel_SetPosition(this->unk4, *((MKVector3 *) &sp4E8));
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r3, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
            sp3B8 = sp208;
            sp210 = sp510.unk18 * this->unkC8;
            sp3C0 = (f64) sp210;
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            sp498 = sp1F8;
            sp200 = (f32) sp4F0 + (f32) sp3C0;
            sp4A0 = (f64) sp200;
            if ((s32) M2C_FIELD(this, s32 *, 0x1BC) == 2) {
                sp24 = MKRand_Float(&gViewSeed, 6.0f, 8.0f);
                sp1F0 = 0.0f;
                sp1E8 = 0.0f;
                sp1EC = 0.0f;
                sp3B0 = (f64) sp1F0;
                sp3A8 = (f64) sp1E8;
                gb.unk68->Emit(*((MKVector3 *) &sp498), *((MKVector3 *) &sp3A8), sp24);
            } else {
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r3, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f27 */);
                sp1E0 = sp510.unk18 * 150.0f;
                sp398 = sp1D8;
                sp3A0 = (f64) sp1E0;
                sp20 = 1.4f * this->unk128;
                gb.EmitDust(*((MKVector3 *) &sp498), *((MKVector3 *) &sp398), sp20, 0.0f);
            }
            this->unk104 += gUpdateTimeDelta;
            if (this->unk104 > 4.0f) {
                Explode(*((MKVector3 *) &sp4C8), *((MKVector3 *) &sp4E8), NULL);
            }
        }
        if ((s32) M2C_FIELD(this, s32 *, 0x1BC) == 2) {
            temp_f30_2070 = this->unkC8;
            temp_f28_2075 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
            temp_f27_2080 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
            sp1C8 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
            sp1CC = temp_f27_2080;
            sp1D0 = temp_f28_2075;
            sp368 = (f64) sp1C8;
            sp370 = (f64) sp1D0;
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
            sp378 = sp1B8;
            sp1C0 = (f32) sp370 * temp_f30_2070;
            sp380 = (f64) sp1C0;
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            sp388 = sp1A8;
            sp1B0 = (f32) sp4F0 + (f32) sp380;
            sp390 = (f64) sp1B0;
            temp_f28_2118 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
            temp_f27_2123 = MKRand_Float(&gViewSeed, 0.0f, 1.0f);
            sp198 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
            sp19C = temp_f27_2123;
            sp1A0 = temp_f28_2118;
            sp348 = (f64) sp198;
            sp350 = (f64) sp1A0;
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f26 */);
            sp358 = sp188;
            sp190 = (f32) sp350 * 1000.0f;
            sp360 = (f64) sp190;
            temp_f1_2149 = MKRand_Float(&gViewSeed, 15.0f, 20.0f);
            sp178 = 1.0f;
            sp17C = 0.2f;
            sp1C = temp_f1_2149;
            sp180 = 0.7f;
            sp184 = 1.0f;
            sp338 = (f64) sp178;
            sp340 = (f64) sp180;
            gb.unk74->Emit(*((MKVector3 *) &sp388), *((MKVector3 *) &sp358), sp1C, *((MKVector4 *) &sp338), -1000.0f);
        } else {
            temp_f30_2173 = this->unkC8;
            temp_f28_2178 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
            temp_f27_2183 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
            sp168 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
            sp16C = temp_f27_2183;
            sp170 = temp_f28_2178;
            sp308 = (f64) sp168;
            sp310 = (f64) sp170;
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
            sp318 = sp158;
            sp160 = (f32) sp310 * temp_f30_2173;
            sp320 = (f64) sp160;
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            sp328 = sp148;
            sp150 = (f32) sp4F0 + (f32) sp320;
            sp330 = (f64) sp150;
            temp_f28_2221 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
            temp_f27_2226 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
            sp138 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
            sp13C = temp_f27_2226;
            sp140 = temp_f28_2221;
            sp2E8 = (f64) sp138;
            sp2F0 = (f64) sp140;
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f26 */);
            sp2F8 = sp128;
            sp130 = (f32) sp2F0 * 400.0f;
            sp300 = (f64) sp130;
            sp18 = MKRand_Float(&gViewSeed, 2.5f, 8.0f);
            temp_f26_2258 = MKRand_Float(&gViewSeed, 0.8f, 1.0f);
            sp118 = MKRand_Float(&gViewSeed, 0.8f, 1.0f);
            sp11C = temp_f26_2258;
            sp120 = 0.0f;
            sp124 = 1.0f;
            sp2D8 = (f64) sp118;
            sp2E0 = (f64) sp120;
            gb.unk74->Emit(*((MKVector3 *) &sp328), *((MKVector3 *) &sp2F8), sp18, *((MKVector4 *) &sp2D8), -1000.0f);
        }
        if ((ManagedLight *) this->unk108 != NULL) {
            temp_f1_2289 = MKRand_Float(&gViewSeed, 0.2f, 0.6f);
            temp_r3_2290 = this->unk108;
            temp_r3_2290->unk10 = sp4E8;
            temp_r3_2290->unk18 = sp4F0;
            temp_r3_2295 = temp_r3_2290->unk3C;
            if (temp_r3_2295 != NULL) {
                M2C_FIELD(temp_r3_2295, f64 *, 0x10) = sp4E8;
                M2C_FIELD(temp_r3_2295, f64 *, 0x18) = sp4F0;
            }
            var_f7_2303 = 0.1f;
            if (1.0f > 0.1f) {

            } else {
                var_f7_2303 = 1.0f;
            }
            temp_f3_2311 = this->unk124;
            spF8 = 1.0f;
            temp_f2_2319 = (var_f7_2303 * (1000.0f - temp_f3_2311)) + temp_f3_2311;
            spFC = 0.0f;
            sp100 = 0.0f;
            sp104 = 1.0f;
            this->unk124 = (var_f7_2303 * (1000.0f - temp_f2_2319)) + temp_f2_2319;
            sp108 = 1.0f;
            sp10C = 1.0f;
            sp110 = 0.0f;
            sp114 = 1.0f;
            sp2B8 = (f64) spF8;
            sp2C0 = (f64) sp100;
            sp2C8 = (f64) sp108;
            sp2D0 = (f64) sp110;
            if ((0.5f * (temp_f1_2289 * 1.0f)) < 1.0f) {

            }
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f3, $f2 */);
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f5, $f4 */);
            spC8 = sp78;
            spD0 = sp80;
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f25 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f25 */);
            spB8 = sp68;
            spC0 = sp70;
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f2, $f0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f4, $f0 */);
            spA8 = sp58;
            spB0 = sp60;
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f3, $f2 */);
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f5, $f3 */);
            spE8 = sp48;
            spF0 = sp50;
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f25 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f25 */);
            spD8 = sp38;
            spE0 = sp40;
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f2, $f0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f3, $f0 */);
            sp488 = sp28;
            sp490 = sp30;
            KDMath_Smooth<MKVector4>(sp2A8, this->unk110, 0.5f, 1.0f);
            M2C_FIELD(this, f64 *, 0x110) = M2C_BITWISE(f64, sp2A8);
            M2C_FIELD(this, f64 *, 0x118) = (f64) sp2A8.unk8;
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
