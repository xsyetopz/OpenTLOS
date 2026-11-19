#include "spyro/source/SpyroEffects.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "spyro/source/BoneBlurFX.h"
#include "spyro/source/CharacterBodyFX.h"
#include "spyro/source/CharacterGlowFX.h"
#include "spyro/source/CharacterIceCubesFX.h"
#include "spyro/source/CharacterZapFX.h"
#include "spyro/source/ConvexityBreathFX.h"
#include "spyro/source/EarthBreathFX.h"
#include "spyro/source/EarthShockwave.h"
#include "spyro/source/FlameBreathFX.h"
#include "spyro/source/FuryFXConvexity.h"
#include "spyro/source/GameData.h"
#include "spyro/source/HitFX.h"
#include "spyro/source/IceBreathFX.h"
#include "spyro/source/KDInput.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/KDSynkerPlayer3.h"
#include "spyro/source/LineSegmentTrail.h"
#include "spyro/source/MeleeTrails.h"
#include "spyro/source/MoltenMetalPS.h"
#include "spyro/source/SpyroUtils.h"
#include "spyro/source/WaterSurfaceFX.h"
#include "spyro/source/ZapBreathFX.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "common/Source/MKInput.h"
#include "common/Source/MKMaterial.h"
#include "spyro/source/EventCamera.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/Tools.h"
#include <m2c_macros.h>

extern s32 GS_Rumble1;
extern s32 GS_SpyroFuryStartSound;
extern f32 SPYRO_BOUNCE_Y_SPEED;
extern f32 SPYRO_MIN_JUMP_Y_VELOCITY;
extern MKSceneManager *gMK;
extern M2C_UNK gb;
#if 0 // DRAFT: illegal use of incomplete struct/union/class 'CharacterBodyFxInit'
static CharacterBodyFxInit spyroBodyFXData;         /* unable to generate initializer: confusing struct layout */
static M2C_UNK spyroGlowFXData;                     /* unable to generate initializer: unknown type */

static s32 lit_1018 = 3;
#endif

static s32 lit_1024 = 3;

static s32 lit_1032 = 3;

void SpyroEffects::SoundFadeOut() {
    SpyroSoundPlayer *temp_r3_16;

    temp_r3_16 = this->unk10;
    if (temp_r3_16 != NULL) {
        temp_r3_16->FadeOut(5);
        this->unk10->FadeOut(6);
        this->unk10->FadeOut(7);
        this->unk10->FadeOut(8);
        this->unk10->FadeOut(0xA);
        this->unk10->FadeOut(9);
    }
}

#if 0 // DRAFT: undefined identifier 'unksp24'
void SpyroEffects::TriggerConvexity(SpyroEffectsUpdateData *arg0) {
    f64 sp38;
    f64 sp30;
    f64 sp28;                                       /* compiler-managed */
    f64 sp20;                                       /* compiler-managed */
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 sp8;
    f32 var_f4_71;
    f32 var_f5_80;
    f64 temp_f1_85;
    f64 temp_f1_91;
    f64 temp_f1_95;
    s32 temp_r4_114;
    s32 var_r0_124;
    void *temp_r5_50;

    temp_r5_50 = arg0->unk20;
    sp30 = M2C_FIELD(temp_r5_50, f64 *, 0x30);
    sp38 = M2C_FIELD(temp_r5_50, f64 *, 0x38);
    sp10 = -M2C_FIELD(temp_r5_50, f32 *, 0x20);
    sp14 = -M2C_FIELD(temp_r5_50, f32 *, 0x24);
    sp18 = -M2C_FIELD(temp_r5_50, f32 *, 0x28);
    sp20 = (f64) sp10;
    sp28 = (f64) sp18;
    if ((u8) arg0->unk3C != 0) {
        var_f4_71 = 0.0f;
        unksp24 = 0.0f;
        var_f5_80 = ((f32) sp28 * (f32) sp28) + (((f32) sp20 * (f32) sp20) + (0.0f * 0.0f));
        if (var_f5_80 > 0.000001f) {
            if (var_f5_80 > 0.0f) {
                temp_f1_85 = __frsqrte(var_f5_80);
                temp_f1_91 = 0.5 * temp_f1_85 * -(((f64) var_f5_80 * (temp_f1_85 * temp_f1_85)) - 3.0);
                temp_f1_95 = 0.5 * temp_f1_91 * -(((f64) var_f5_80 * (temp_f1_91 * temp_f1_91)) - 3.0);
                var_f5_80 = (f32) ((f64) var_f5_80 * (0.5 * temp_f1_95 * -(((f64) var_f5_80 * (temp_f1_95 * temp_f1_95)) - 3.0)));
            } else if (var_f5_80 < M2C_BITWISE(f32, 0.0)) {
                var_f5_80 = __float_nan;
            } else {
                sp8 = var_f5_80;
                temp_r4_114 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                switch (temp_r4_114) {              /* irregular */
                case 0x7F800000:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_124 = 1;
                    } else {
                        var_r0_124 = 2;
                    }
                    break;
                case 0x0:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_124 = 5;
                    } else {
                        var_r0_124 = 3;
                    }
                    break;
                default:
                    var_r0_124 = 4;
                    break;
                }
                if (var_r0_124 == 1) {
                    var_f5_80 = __float_nan;
                }
            }
            var_f4_71 = 1.0f / var_f5_80;
        }
        sp20 = (f32) sp20 * var_f4_71;
        unksp24 *= var_f4_71;
        sp28 = (f32) sp28 * var_f4_71;
    }
    ((ConvexityBreathFX *) (M2C_FIELD(this->unk4, ConvexityBreathFX **, 0xC0)))->Trigger(this->unk8, *((MKVector3 *) &sp30), *((MKVector3 *) &sp20), 1.0f);
}
#endif

#if 0 // DRAFT: illegal type
u8 SpyroEffects::TriggerFury(SpyroEffectsUpdateData *arg0) {
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
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    s32 sp8;
    f32 var_f1_290;
    s32 temp_r0_212;
    u8 temp_r3_195;
    u8 temp_r3_244;
    u8 temp_r3_284;
    u8 temp_r3_340;
    u8 temp_r3_389;
    u8 var_r31_184;
    u8 var_r3_289;
    void *temp_r4_293;

    var_r31_184 = 0;
    *(&GameData::gameData[0x70] + ((M2C_FIELD(GameData::gameData, s32 *, 0x158) << 5) + 0x7C)) = 3;
    if ((u8) arg0->unk3E != 0) {
        temp_r3_195 = ((FuryFXConvexity *) (M2C_FIELD(this->unk4, FuryFXConvexity **, 0xBC)))->Trigger(arg0->unk10);
        var_r31_184 = temp_r3_195;
        if (temp_r3_195 != 0) {
            sp110 = M2C_FIELD(arg0, f64 *, 0x10);
            sp118 = M2C_FIELD(arg0, f64 *, 0x18);
            ((KDSound_AfterRumble *) (this->unk4 + 0x40))->Trigger((MKVector3) &sp110, GS_Rumble1, 7.5f, 2000.0f);
        }
    } else {
        temp_r0_212 = arg0->unk24;
        switch (temp_r0_212) {                      /* irregular */
        case 0:
            sp68 = 0.0f;
            sp60 = 0.0f;
            sp64 = 0.0f;
            sp108 = (f64) sp68;
            sp100 = (f64) sp60;
            sp8 = 0;
            temp_r3_244 = ((FlameBreathFX *) (M2C_FIELD(this->unk4, FlameBreathFX **, 0x14)))->Trigger(this->unk8, arg0->unk10, *((MKVector3 *) &sp100), *((MKVector3 *) arg0), 1.0f, lit_1018, 0U, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
            var_r31_184 = temp_r3_244;
            if (temp_r3_244 != 0) {
                KDSound_Play3d(GS_SpyroFuryStartSound, &arg0->unk10, 0U, -1, 0.0f, 0U);
                spF0 = M2C_FIELD(arg0, f64 *, 0x10);
                spF8 = M2C_FIELD(arg0, f64 *, 0x18);
                ((KDSound_AfterRumble *) (this->unk4 + 0x40))->Trigger((MKVector3) &spF0, GS_Rumble1, 5.0f, 2000.0f);
            }
            break;
        case 1:
            sp58 = 0.0f;
            sp50 = 0.0f;
            sp54 = 0.0f;
            spE8 = (f64) sp58;
            spE0 = (f64) sp50;
            temp_r3_284 = ((ZapBreathFX *) (M2C_FIELD(this->unk4, ZapBreathFX **, 0x18)))->Trigger(this->unk8, arg0->unk10, *((MKVector3 *) &spE0), 1.0f, lit_1024, 0U);
            var_r31_184 = temp_r3_284;
            if (temp_r3_284 != 0) {
                var_r3_289 = 0;
                var_f1_290 = 7.0f;
                temp_r4_293 = &GameData::gameData[0x70] + ((M2C_FIELD(GameData::gameData, s32 *, 0x158) << 5) + 0x64);
                if (((s32) M2C_FIELD(temp_r4_293, s32 *, 0) == 3) && ((s32) M2C_FIELD(temp_r4_293, s32 *, 4) == 3)) {
                    var_r3_289 = 1;
                }
                if (var_r3_289 != 0) {
                    var_f1_290 = 12.0f;
                }
                ((CharacterZapFX *) (M2C_FIELD(this->unk4, CharacterZapFX **, 0xB4)))->Enable(1U, var_f1_290, 1U);
                spD0 = M2C_FIELD(arg0, f64 *, 0x10);
                spD8 = M2C_FIELD(arg0, f64 *, 0x18);
                ((KDSound_AfterRumble *) (this->unk4 + 0x40))->Trigger((MKVector3) &spD0, GS_Rumble1, 8.0f, 2000.0f);
            }
            break;
        case 2:
            sp48 = 0.0f;
            sp40 = 0.0f;
            sp44 = 0.0f;
            spC8 = (f64) sp48;
            spC0 = (f64) sp40;
            temp_r3_340 = ((IceBreathFX *) (M2C_FIELD(this->unk4, IceBreathFX **, 0x1C)))->Trigger(this->unk8, arg0->unk10, *((MKVector3 *) &spC0), *((MKVector3 *) arg0), 1.0f, lit_1032);
            var_r31_184 = temp_r3_340;
            if (temp_r3_340 != 0) {
                spB0 = M2C_FIELD(arg0, f64 *, 0x10);
                spB8 = M2C_FIELD(arg0, f64 *, 0x18);
                ((KDSound_AfterRumble *) (this->unk4 + 0x40))->Trigger((MKVector3) &spB0, GS_Rumble1, 7.5f, 2000.0f);
                sp30 = 0.5f;
                sp34 = 0.5f;
                sp38 = 1.0f;
                sp3C = 1.0f;
                spA0 = (f64) sp30;
                spA8 = (f64) sp38;
                ((CharacterGlowFX *) (M2C_FIELD(this->unk4, CharacterGlowFX **, 0x28)))->Enable(1U, *((MKVector4 *) &spA0), 10.0f);
            }
            break;
        case 3:
            sp28 = 0.0f;
            sp20 = 0.0f;
            sp24 = 0.0f;
            sp98 = (f64) sp28;
            sp90 = (f64) sp20;
            temp_r3_389 = ((EarthBreathFX *) (M2C_FIELD(this->unk4, EarthBreathFX **, 0x20)))->Trigger(this->unk8, arg0->unk10, *((MKVector3 *) &sp90), *((MKVector3 *) arg0), 3, 0U);
            var_r31_184 = temp_r3_389;
            if (temp_r3_389 != 0) {
                sp80 = M2C_FIELD(arg0, f64 *, 0x10);
                sp88 = M2C_FIELD(arg0, f64 *, 0x18);
                ((KDSound_AfterRumble *) (this->unk4 + 0x40))->Trigger((MKVector3) &sp80, GS_Rumble1, 7.5f, 2000.0f);
                sp10 = 0.25f;
                sp14 = 1.0f;
                sp18 = 0.25f;
                sp1C = 1.0f;
                sp70 = (f64) sp10;
                sp78 = (f64) sp18;
                ((CharacterGlowFX *) (M2C_FIELD(this->unk4, CharacterGlowFX **, 0x28)))->Enable(1U, *((MKVector4 *) &sp70), 10.0f);
            }
            break;
        }
    }
    return var_r31_184;
}
#endif

#if 0 // DRAFT: undefined identifier 'unksp24'
void SpyroEffects::TriggerEarth(SpyroEffectsUpdateData *arg0) {
    f64 sp38;
    f64 sp30;
    f64 sp28;                                       /* compiler-managed */
    f64 sp20;                                       /* compiler-managed */
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 sp8;
    f32 var_f3_535;
    f32 var_f4_468;
    f64 temp_f1_474;
    f64 temp_f1_480;
    f64 temp_f1_484;
    s32 temp_r4_503;
    s32 var_r0_513;
    void *temp_r4_436;

    temp_r4_436 = arg0->unk20;
    sp30 = M2C_FIELD(temp_r4_436, f64 *, 0x30);
    sp38 = M2C_FIELD(temp_r4_436, f64 *, 0x38);
    sp10 = -M2C_FIELD(temp_r4_436, f32 *, 0x20);
    sp14 = -M2C_FIELD(temp_r4_436, f32 *, 0x24);
    sp18 = -M2C_FIELD(temp_r4_436, f32 *, 0x28);
    sp20 = (f64) sp10;
    sp28 = (f64) sp18;
    if ((u8) arg0->unk3C != 0) {
        unksp24 = 0.0f;
    }
    var_f4_468 = ((f32) sp28 * (f32) sp28) + (((f32) sp20 * (f32) sp20) + (unksp24 * unksp24));
    if (var_f4_468 > 0.000001f) {
        if (var_f4_468 > 0.0f) {
            temp_f1_474 = __frsqrte(var_f4_468);
            temp_f1_480 = 0.5 * temp_f1_474 * -(((f64) var_f4_468 * (temp_f1_474 * temp_f1_474)) - 3.0);
            temp_f1_484 = 0.5 * temp_f1_480 * -(((f64) var_f4_468 * (temp_f1_480 * temp_f1_480)) - 3.0);
            var_f4_468 = (f32) ((f64) var_f4_468 * (0.5 * temp_f1_484 * -(((f64) var_f4_468 * (temp_f1_484 * temp_f1_484)) - 3.0)));
        } else if (var_f4_468 < M2C_BITWISE(f32, 0.0)) {
            var_f4_468 = __float_nan;
        } else {
            sp8 = var_f4_468;
            temp_r4_503 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r4_503) {                  /* irregular */
            case 0x7F800000:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_513 = 1;
                } else {
                    var_r0_513 = 2;
                }
                break;
            case 0x0:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_513 = 5;
                } else {
                    var_r0_513 = 3;
                }
                break;
            default:
                var_r0_513 = 4;
                break;
            }
            if (var_r0_513 == 1) {
                var_f4_468 = __float_nan;
            }
        }
        var_f3_535 = 1.0f / var_f4_468;
    } else {
        var_f3_535 = 0.0f;
    }
    sp20 = (f32) sp20 * var_f3_535;
    unksp24 *= var_f3_535;
    sp28 = (f32) sp28 * var_f3_535;
    ((EarthBreathFX *) (M2C_FIELD(this->unk4, EarthBreathFX **, 0x20)))->Trigger(this->unk8, *((MKVector3 *) &sp30), *((MKVector3 *) &sp20), *((MKVector3 *) arg0), arg0->unk28, arg0->unk3F);
}
#endif

#if 0 // DRAFT: undefined identifier 'unksp24'
u8 SpyroEffects::TriggerElectricity(SpyroEffectsUpdateData *arg0) {
    f64 sp38;
    f64 sp30;
    f64 sp28;                                       /* compiler-managed */
    f64 sp20;                                       /* compiler-managed */
    f32 sp18;
    f32 sp14;
    f32 sp10;
    s32 spC;
    f32 sp8;
    SpyroSoundPlayer *temp_r0_696;
    f32 var_f3_671;
    f32 var_f4_604;
    f64 temp_f1_610;
    f64 temp_f1_616;
    f64 temp_f1_620;
    s32 temp_r3_639;
    s32 temp_r3_700;
    s32 var_r0_649;
    u8 temp_r29_697;
    void *temp_r3_572;

    temp_r3_572 = arg0->unk20;
    sp30 = M2C_FIELD(temp_r3_572, f64 *, 0x30);
    sp38 = M2C_FIELD(temp_r3_572, f64 *, 0x38);
    sp10 = -M2C_FIELD(temp_r3_572, f32 *, 0x20);
    sp14 = -M2C_FIELD(temp_r3_572, f32 *, 0x24);
    sp18 = -M2C_FIELD(temp_r3_572, f32 *, 0x28);
    sp20 = (f64) sp10;
    sp28 = (f64) sp18;
    if ((u8) arg0->unk3C != 0) {
        unksp24 = 0.0f;
    }
    var_f4_604 = ((f32) sp28 * (f32) sp28) + (((f32) sp20 * (f32) sp20) + (unksp24 * unksp24));
    if (var_f4_604 > 0.000001f) {
        if (var_f4_604 > 0.0f) {
            temp_f1_610 = __frsqrte(var_f4_604);
            temp_f1_616 = 0.5 * temp_f1_610 * -(((f64) var_f4_604 * (temp_f1_610 * temp_f1_610)) - 3.0);
            temp_f1_620 = 0.5 * temp_f1_616 * -(((f64) var_f4_604 * (temp_f1_616 * temp_f1_616)) - 3.0);
            var_f4_604 = (f32) ((f64) var_f4_604 * (0.5 * temp_f1_620 * -(((f64) var_f4_604 * (temp_f1_620 * temp_f1_620)) - 3.0)));
        } else if (var_f4_604 < M2C_BITWISE(f32, 0.0)) {
            var_f4_604 = __float_nan;
        } else {
            sp8 = var_f4_604;
            temp_r3_639 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r3_639) {                  /* irregular */
            case 0x7F800000:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_649 = 1;
                } else {
                    var_r0_649 = 2;
                }
                break;
            case 0x0:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_649 = 5;
                } else {
                    var_r0_649 = 3;
                }
                break;
            default:
                var_r0_649 = 4;
                break;
            }
            if (var_r0_649 == 1) {
                var_f4_604 = __float_nan;
            }
        }
        var_f3_671 = 1.0f / var_f4_604;
    } else {
        var_f3_671 = 0.0f;
    }
    sp20 = (f32) sp20 * var_f3_671;
    unksp24 *= var_f3_671;
    sp28 = (f32) sp28 * var_f3_671;
    spC = arg0->unk28;
    temp_r0_696 = this->unk10;
    temp_r29_697 = ((ZapBreathFX *) (M2C_FIELD(this->unk4, ZapBreathFX **, 0x18)))->Trigger(this->unk8, *((MKVector3 *) &sp30), *((MKVector3 *) &sp20), 1.0f, spC, arg0->unk3D);
    if (temp_r0_696 != NULL) {
        temp_r3_700 = arg0->unk28;
        if (temp_r3_700 == 0) {
            temp_r0_696->FadeIn(8, -1);
            this->unk10->FadeIn(9, -1);
        } else if (temp_r3_700 == 1) {
            temp_r0_696->FadeIn(0xA, -1);
        }
    }
    return temp_r29_697;
}
#endif

#if 0 // DRAFT: undefined identifier 'unksp24'
u8 SpyroEffects::TriggerIce(SpyroEffectsUpdateData *arg0) {
    f64 sp38;
    f64 sp30;
    f64 sp28;                                       /* compiler-managed */
    f64 sp20;                                       /* compiler-managed */
    f32 sp18;
    f32 sp14;
    f32 sp10;
    s32 spC;
    f32 sp8;
    SpyroSoundPlayer *temp_r4_861;
    f32 var_f3_836;
    f32 var_f4_769;
    f64 temp_f1_775;
    f64 temp_f1_781;
    f64 temp_f1_785;
    s32 temp_r3_804;
    s32 var_r0_814;
    u8 temp_r29_862;
    void *temp_r3_737;

    temp_r3_737 = arg0->unk20;
    sp30 = M2C_FIELD(temp_r3_737, f64 *, 0x30);
    sp38 = M2C_FIELD(temp_r3_737, f64 *, 0x38);
    sp10 = -M2C_FIELD(temp_r3_737, f32 *, 0x20);
    sp14 = -M2C_FIELD(temp_r3_737, f32 *, 0x24);
    sp18 = -M2C_FIELD(temp_r3_737, f32 *, 0x28);
    sp20 = (f64) sp10;
    sp28 = (f64) sp18;
    if ((u8) arg0->unk3C != 0) {
        unksp24 = 0.0f;
    }
    var_f4_769 = ((f32) sp28 * (f32) sp28) + (((f32) sp20 * (f32) sp20) + (unksp24 * unksp24));
    if (var_f4_769 > 0.000001f) {
        if (var_f4_769 > 0.0f) {
            temp_f1_775 = __frsqrte(var_f4_769);
            temp_f1_781 = 0.5 * temp_f1_775 * -(((f64) var_f4_769 * (temp_f1_775 * temp_f1_775)) - 3.0);
            temp_f1_785 = 0.5 * temp_f1_781 * -(((f64) var_f4_769 * (temp_f1_781 * temp_f1_781)) - 3.0);
            var_f4_769 = (f32) ((f64) var_f4_769 * (0.5 * temp_f1_785 * -(((f64) var_f4_769 * (temp_f1_785 * temp_f1_785)) - 3.0)));
        } else if (var_f4_769 < M2C_BITWISE(f32, 0.0)) {
            var_f4_769 = __float_nan;
        } else {
            sp8 = var_f4_769;
            temp_r3_804 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r3_804) {                  /* irregular */
            case 0x7F800000:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_814 = 1;
                } else {
                    var_r0_814 = 2;
                }
                break;
            case 0x0:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_814 = 5;
                } else {
                    var_r0_814 = 3;
                }
                break;
            default:
                var_r0_814 = 4;
                break;
            }
            if (var_r0_814 == 1) {
                var_f4_769 = __float_nan;
            }
        }
        var_f3_836 = 1.0f / var_f4_769;
    } else {
        var_f3_836 = 0.0f;
    }
    sp20 = (f32) sp20 * var_f3_836;
    unksp24 *= var_f3_836;
    sp28 = (f32) sp28 * var_f3_836;
    spC = arg0->unk28;
    temp_r4_861 = this->unk10;
    temp_r29_862 = ((IceBreathFX *) (M2C_FIELD(this->unk4, IceBreathFX **, 0x1C)))->Trigger(this->unk8, *((MKVector3 *) &sp30), *((MKVector3 *) &sp20), *((MKVector3 *) arg0), 1.5f, spC);
    if (temp_r4_861 != NULL) {
        if (((s32) arg0->unk28 == 1) && (temp_r29_862 != 0)) {
            temp_r4_861->FadeIn(5, -1);
        } else {
            temp_r4_861->FadeOut(5);
        }
        if (((s32) arg0->unk28 == 0) && (temp_r29_862 != 0)) {
            this->unk10->FadeIn(6, -1);
        } else {
            this->unk10->FadeOut(6);
        }
    }
    return temp_r29_862;
}
#endif

#if 0 // DRAFT: undefined identifier 'unksp4C'
u8 SpyroEffects::TriggerFire(SpyroEffectsUpdateData *arg0) {
    f64 sp60;
    f64 sp58;
    f64 sp50;                                       /* compiler-managed */
    f64 sp48;                                       /* compiler-managed */
    f64 sp40;
    f64 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f64 sp18;
    s32 sp14;
    f32 sp10;
    s32 sp8;
    SpyroSoundPlayer *temp_r4_1045;
    f32 var_f5_933;
    f32 var_f6_942;
    f64 temp_f1_1022;
    f64 temp_f2_947;
    f64 temp_f2_953;
    f64 temp_f2_957;
    s32 temp_r30_1046;
    s32 temp_r3_976;
    s32 var_r0_986;
    void *temp_r3_912;

    temp_r3_912 = arg0->unk20;
    sp58 = M2C_FIELD(temp_r3_912, f64 *, 0x30);
    sp60 = M2C_FIELD(temp_r3_912, f64 *, 0x38);
    sp28 = -M2C_FIELD(temp_r3_912, f32 *, 0x20);
    sp2C = -M2C_FIELD(temp_r3_912, f32 *, 0x24);
    sp30 = -M2C_FIELD(temp_r3_912, f32 *, 0x28);
    sp48 = (f64) sp28;
    sp50 = (f64) sp30;
    if ((u8) arg0->unk3C != 0) {
        var_f5_933 = 0.0f;
        unksp4C = 0.0f;
        var_f6_942 = ((f32) sp50 * (f32) sp50) + (((f32) sp48 * (f32) sp48) + (0.0f * 0.0f));
        if (var_f6_942 > 0.000001f) {
            if (var_f6_942 > 0.0f) {
                temp_f2_947 = __frsqrte(var_f6_942);
                temp_f2_953 = 0.5 * temp_f2_947 * -(((f64) var_f6_942 * (temp_f2_947 * temp_f2_947)) - 3.0);
                temp_f2_957 = 0.5 * temp_f2_953 * -(((f64) var_f6_942 * (temp_f2_953 * temp_f2_953)) - 3.0);
                var_f6_942 = (f32) ((f64) var_f6_942 * (0.5 * temp_f2_957 * -(((f64) var_f6_942 * (temp_f2_957 * temp_f2_957)) - 3.0)));
            } else if (var_f6_942 < M2C_BITWISE(f32, 0.0)) {
                var_f6_942 = __float_nan;
            } else {
                sp10 = var_f6_942;
                temp_r3_976 = M2C_BITWISE(s32, sp10) & 0x7F800000;
                switch (temp_r3_976) {              /* irregular */
                case 0x7F800000:
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_986 = 1;
                    } else {
                        var_r0_986 = 2;
                    }
                    break;
                case 0x0:
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_986 = 5;
                    } else {
                        var_r0_986 = 3;
                    }
                    break;
                default:
                    var_r0_986 = 4;
                    break;
                }
                if (var_r0_986 == 1) {
                    var_f6_942 = __float_nan;
                }
            }
            var_f5_933 = 1.0f / var_f6_942;
        }
        sp48 = (f32) sp48 * var_f5_933;
        unksp4C *= var_f5_933;
        sp50 = (f32) sp50 * var_f5_933;
    }
    temp_f1_1022 = arg0->unk0 * 5.23867711e-315;
    sp18 = temp_f1_1022;
    sp38 = temp_f1_1022;
    sp20 = arg0->unk8 * 0.7f;
    sp40 = (f64) sp20;
    sp14 = arg0->unk28;
    sp8 = (s32) arg0->unk3F;
    temp_r4_1045 = this->unk10;
    temp_r30_1046 = ((FlameBreathFX *) (M2C_FIELD(this->unk4, FlameBreathFX **, 0x14)))->Trigger(this->unk8, *((MKVector3 *) &sp58), *((MKVector3 *) &sp48), *((MKVector3 *) &sp38), 1.5f, sp14, arg0->unk3D, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    if (temp_r4_1045 != NULL) {
        if (((s32) arg0->unk28 == 0) && ((u8) temp_r30_1046 != 0)) {
            temp_r4_1045->FadeIn(7, -1);
        } else {
            temp_r4_1045->FadeOut(7);
        }
    }
    return (u8) temp_r30_1046;
}
#endif

#if 0 // DRAFT: expression syntax error
void SpyroEffects::UpdateFury(SpyroEffectsUpdateData *arg0) {
    f64 sp20;
    f64 sp18;
    f64 sp10;
    f64 sp8;
    KDInput *temp_r4_1104;
    f64 temp_f0_1141;
    f64 temp_f1_1140;
    s32 var_r3_1117;
    u8 *temp_r28_1149;
    u8 temp_r3_1158;
    u8 var_r27_1134;
    u8 var_r3_1105;
    void *temp_r3_1139;

    if ((u8) GameData::gameData[0x156] != 0) {
        ((Stat *) ((Stat *) (&GameData::gameData[0x70] + 0x48)))->SetValue(M2C_FIELD(GameData::gameData, f32 *, 0xBC), 0U);
    }
    if (((u8) M2C_FIELD(&gb, u8 *, 8) != 0) && ((u8 *) arg0->unk38 != NULL) && ((s32) (GameData::gameData[0x168] & 0x10) == 0x10)) {
        temp_r4_1104 = this->unkC;
        var_r3_1105 = 0;
        if (((u8) temp_r4_1104->unk5 != 0) || ((u8) temp_r4_1104->unk4 != 0)) {
            var_r3_1105 = 1;
        }
        if (var_r3_1105 != 0) {
            var_r3_1117 = 0;
        } else {
            var_r3_1117 = MKInput_Pressed(9, (MKInputDevices) temp_r4_1104->unk0);
        }
        if (((u8) var_r3_1117 != 0) && ((s32) (M2C_FIELD((&GameData::gameData[0x70] + (M2C_FIELD(GameData::gameData, s32 *, 0x158) << 5)), s32 *, 0x60) & 8) == 8)) {
            var_r27_1134 = 0;
            arg0->unk3E = M2C_FIELD(&gb, u8 *, 0x35D);
            temp_r3_1139 = this->unk8->unk8;
            temp_f1_1140 = M2C_FIELD(temp_r3_1139, f64 *, 0x30);
            temp_f0_1141 = M2C_FIELD(temp_r3_1139, f64 *, 0x38);
            sp18 = temp_f1_1140;
            M2C_FIELD(arg0, f64 *, 0x10) = temp_f1_1140;
            M2C_FIELD(arg0, f64 *, 0x18) = temp_f0_1141;
            sp20 = temp_f0_1141;
            if ((u8) arg0->unk3E != 0) {
                temp_r28_1149 = &GameData::gameData[0x70] + 0x48;
                if (M2C_FIELD(GameData::gameData, f32 *, 0xBC) <= M2C_FIELD(GameData::gameData, f32 *, 0xB8)) {
                    temp_r3_1158 = ((FuryFXConvexity *) (M2C_FIELD(this->unk4, FuryFXConvexity **, 0xBC)))->Trigger(arg0->unk10);
                    var_r27_1134 = temp_r3_1158;
                    if (temp_r3_1158 != 0) {
                        if ((u8) GameData::gameData[0x156] != 0) {
                            temp_r28_1149->SetValue(M2C_FIELD(temp_r28_1149, f32 *, 4), 0U);
                        } else {
                            temp_r28_1149->SetValue(0.0f, 0U);
                        }
                        sp8 = M2C_FIELD(arg0, f64 *, 0x10);
                        sp10 = M2C_FIELD(arg0, f64 *, 0x18);
                        ((KDSound_AfterRumble *) (this->unk4 + 0x40))->Trigger((MKVector3) &sp8, GS_Rumble1, 7.5f, 2000.0f);
                    }
                }
            } else if (M2C_FIELD(GameData::gameData, f32 *, 0xBC) <= M2C_FIELD(GameData::gameData, f32 *, 0xB8)) {
                arg0->unk24 = M2C_FIELD(GameData::gameData, s32 *, 0x158);
                var_r27_1134 = TriggerFury(arg0);
            }
            *arg0->unk38 = var_r27_1134;
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unkA0'
void SpyroEffects::Update(SpyroEffectsUpdateData *arg0, KDInput *arg1) {
    KDInput *temp_r4_1245;
    KDInput *temp_r4_1267;
    KDInput *temp_r4_1292;
    KDInput *temp_r4_1314;
    KDInput *temp_r4_1348;
    KDInput *temp_r4_1386;
    KDInput *temp_r4_1424;
    KDInput *temp_r4_1462;
    KDInput *temp_r4_1508;
    KDInput *temp_r4_1534;
    KDInput *temp_r4_1560;
    KDInput *temp_r4_1581;
    KDInput *temp_r4_1617;
    KDInput *temp_r4_1637;
    KDInput *temp_r4_1680;
    KDInput *temp_r4_1716;
    KDInput *temp_r4_1736;
    KDInput *temp_r4_1783;
    KDInput *temp_r4_1825;
    KDInput *temp_r4_1871;
    KDInput *temp_r4_1893;
    KDSynkerPlayer3 *temp_r3_2224;
    f32 temp_f31_1942;
    f32 var_f1_1280;
    f32 var_f1_1327;
    f32 var_f1_1594;
    f32 var_f1_1651;
    f32 var_f1_1693;
    f32 var_f1_1750;
    f32 var_f1_1796;
    f32 var_f1_1838;
    f32 var_f30_1938;
    s32 temp_r0_2071;
    s32 temp_r3_1943;
    s32 temp_r4_1608;
    s32 temp_r4_1706;
    s32 temp_r4_1952;
    s32 temp_r4_1957;
    s32 temp_r4_1983;
    s32 temp_r4_2045;
    s32 var_r24_1629;
    s32 var_r24_1728;
    s32 var_r26_1501;
    s32 var_r3_1258;
    s32 var_r3_1305;
    s32 var_r3_1361;
    s32 var_r3_1399;
    s32 var_r3_1437;
    s32 var_r3_1475;
    s32 var_r3_1521;
    s32 var_r3_1547;
    s32 var_r3_1572;
    s32 var_r3_1884;
    s32 var_r3_1906;
    u8 temp_r7_1944;
    u8 var_r24_1506;
    u8 var_r24_1941;
    u8 var_r24_2221;
    u8 var_r25_1502;
    u8 var_r27_1505;
    u8 var_r28_1503;
    u8 var_r3_1246;
    u8 var_r3_1268;
    u8 var_r3_1293;
    u8 var_r3_1315;
    u8 var_r3_1349;
    u8 var_r3_1387;
    u8 var_r3_1425;
    u8 var_r3_1463;
    u8 var_r3_1509;
    u8 var_r3_1535;
    u8 var_r3_1559;
    u8 var_r3_1582;
    u8 var_r3_1614;
    u8 var_r3_1639;
    u8 var_r3_1663;
    u8 var_r3_1681;
    u8 var_r3_1715;
    u8 var_r3_1738;
    u8 var_r3_1762;
    u8 var_r3_1784;
    u8 var_r3_1826;
    u8 var_r3_1872;
    u8 var_r3_1894;
    void *temp_r25_2223;
    void *temp_r4_2254;

    this->unkC = arg1;
    if ((EventCamera_GetCurrent() == NULL) && ((s32) (GameData::gameData[0x168] & 8) == 8)) {
        arg0->unk3E = M2C_FIELD(&gb, u8 *, 0x35D);
        if ((u8) M2C_FIELD(&gb, u8 *, 4) != 0) {
            temp_r4_1245 = this->unkC;
            var_r3_1246 = 0;
            if (((u8) temp_r4_1245->unk5 != 0) || ((u8) temp_r4_1245->unk4 != 0)) {
                var_r3_1246 = 1;
            }
            if (var_r3_1246 != 0) {
                var_r3_1258 = 0;
            } else {
                var_r3_1258 = MKInput_Pressed(0xF, (MKInputDevices) temp_r4_1245->unk0);
            }
            if ((u8) var_r3_1258 == 0) {
                temp_r4_1267 = this->unkC;
                var_r3_1268 = 0;
                if (((u8) temp_r4_1267->unk5 != 0) || ((u8) temp_r4_1267->unk4 != 0)) {
                    var_r3_1268 = 1;
                }
                if (var_r3_1268 != 0) {
                    var_f1_1280 = 0.0f;
                } else {
                    var_f1_1280 = MKInput_GetState(0xF, (MKInputDevices) temp_r4_1267->unk0, NULL, NULL);
                }
                if (var_f1_1280 == 0.0f) {
                    temp_r4_1292 = this->unkC;
                    var_r3_1293 = 0;
                    if (((u8) temp_r4_1292->unk5 != 0) || ((u8) temp_r4_1292->unk4 != 0)) {
                        var_r3_1293 = 1;
                    }
                    if (var_r3_1293 != 0) {
                        var_r3_1305 = 0;
                    } else {
                        var_r3_1305 = MKInput_Pressed(0xC, (MKInputDevices) temp_r4_1292->unk0);
                    }
                    if ((u8) var_r3_1305 == 0) {
                        temp_r4_1314 = this->unkC;
                        var_r3_1315 = 0;
                        if (((u8) temp_r4_1314->unk5 != 0) || ((u8) temp_r4_1314->unk4 != 0)) {
                            var_r3_1315 = 1;
                        }
                        if (var_r3_1315 != 0) {
                            var_f1_1327 = 0.0f;
                        } else {
                            var_f1_1327 = MKInput_GetState(0xC, (MKInputDevices) temp_r4_1314->unk0, NULL, NULL);
                        }
                        if ((var_f1_1327 == 0.0f) && (M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), u8 (**)(void **), 0x54)(M2C_FIELD(&gb, void ***, 0)) == 0)) {
                            temp_r4_1348 = this->unkC;
                            var_r3_1349 = 0;
                            if (((u8) temp_r4_1348->unk5 != 0) || ((u8) temp_r4_1348->unk4 != 0)) {
                                var_r3_1349 = 1;
                            }
                            if (var_r3_1349 != 0) {
                                var_r3_1361 = 0;
                            } else {
                                var_r3_1361 = MKInput_Pressed(4, (MKInputDevices) temp_r4_1348->unk0);
                            }
                            if (((u8) var_r3_1361 != 0) && (((s32) (M2C_FIELD(GameData::gameData, s32 *, 0xD0) & 1) == 1) || ((s32) (M2C_FIELD(GameData::gameData, s32 *, 0xD0) & 2) == 2))) {
                                ((GameStats *) ((GameStats *) &GameData::gameData[0x70]))->SetCurrentBreath((BreathElement) 0);
                                M2C_FIELD(GameData::gameData, f32 *, 0x160) = (f32) M2C_FIELD(M2C_FIELD(this->unk4, void **, 0x14), f32 *, 0xA0);
                            }
                            temp_r4_1386 = this->unkC;
                            var_r3_1387 = 0;
                            if (((u8) temp_r4_1386->unk5 != 0) || ((u8) temp_r4_1386->unk4 != 0)) {
                                var_r3_1387 = 1;
                            }
                            if (var_r3_1387 != 0) {
                                var_r3_1399 = 0;
                            } else {
                                var_r3_1399 = MKInput_Pressed(5, (MKInputDevices) temp_r4_1386->unk0);
                            }
                            if (((u8) var_r3_1399 != 0) && (((s32) (M2C_FIELD(GameData::gameData, s32 *, 0xF0) & 1) == 1) || ((s32) (M2C_FIELD(GameData::gameData, s32 *, 0xF0) & 2) == 2))) {
                                ((GameStats *) ((GameStats *) &GameData::gameData[0x70]))->SetCurrentBreath((BreathElement) 1);
                                M2C_FIELD(GameData::gameData, f32 *, 0x160) = (f32) M2C_FIELD(this->unk4, ZapBreathFX **, 0x18)->unkA0;
                            }
                            temp_r4_1424 = this->unkC;
                            var_r3_1425 = 0;
                            if (((u8) temp_r4_1424->unk5 != 0) || ((u8) temp_r4_1424->unk4 != 0)) {
                                var_r3_1425 = 1;
                            }
                            if (var_r3_1425 != 0) {
                                var_r3_1437 = 0;
                            } else {
                                var_r3_1437 = MKInput_Pressed(6, (MKInputDevices) temp_r4_1424->unk0);
                            }
                            if (((u8) var_r3_1437 != 0) && (((s32) (M2C_FIELD(GameData::gameData, s32 *, 0x110) & 1) == 1) || ((s32) (M2C_FIELD(GameData::gameData, s32 *, 0x110) & 2) == 2))) {
                                ((GameStats *) ((GameStats *) &GameData::gameData[0x70]))->SetCurrentBreath((BreathElement) 2);
                                M2C_FIELD(GameData::gameData, f32 *, 0x160) = (f32) M2C_FIELD(M2C_FIELD(this->unk4, void **, 0x1C), f32 *, 0xA0);
                            }
                            temp_r4_1462 = this->unkC;
                            var_r3_1463 = 0;
                            if (((u8) temp_r4_1462->unk5 != 0) || ((u8) temp_r4_1462->unk4 != 0)) {
                                var_r3_1463 = 1;
                            }
                            if (var_r3_1463 != 0) {
                                var_r3_1475 = 0;
                            } else {
                                var_r3_1475 = MKInput_Pressed(7, (MKInputDevices) temp_r4_1462->unk0);
                            }
                            if (((u8) var_r3_1475 != 0) && (((s32) (M2C_FIELD(GameData::gameData, s32 *, 0x130) & 1) == 1) || ((s32) (M2C_FIELD(GameData::gameData, s32 *, 0x130) & 2) == 2))) {
                                ((GameStats *) ((GameStats *) &GameData::gameData[0x70]))->SetCurrentBreath((BreathElement) 3);
                                M2C_FIELD(GameData::gameData, f32 *, 0x160) = (f32) M2C_FIELD(M2C_FIELD(this->unk4, void **, 0x20), f32 *, 0xA0);
                            }
                        }
                    }
                }
            }
        }
        var_r26_1501 = 0;
        var_r25_1502 = 0;
        var_r28_1503 = 1;
        var_r27_1505 = 0;
        var_r24_1506 = 1;
        if ((u8) this->unk14 == 0) {
            temp_r4_1508 = this->unkC;
            var_r3_1509 = 0;
            if (((u8) temp_r4_1508->unk5 != 0) || ((u8) temp_r4_1508->unk4 != 0)) {
                var_r3_1509 = 1;
            }
            if (var_r3_1509 != 0) {
                var_r3_1521 = 0;
            } else {
                var_r3_1521 = MKInput_Pressed(0xC, (MKInputDevices) temp_r4_1508->unk0);
            }
            if ((u8) var_r3_1521 == 0) {
                var_r24_1506 = 0;
            }
        }
        if (var_r24_1506 != 0) {
            temp_r4_1534 = this->unkC;
            var_r3_1535 = 0;
            if (((u8) temp_r4_1534->unk5 != 0) || ((u8) temp_r4_1534->unk4 != 0)) {
                var_r3_1535 = 1;
            }
            if (var_r3_1535 != 0) {
                var_r3_1547 = 0;
            } else {
                var_r3_1547 = MKInput_Released(0xC, (MKInputDevices) temp_r4_1534->unk0);
            }
            if ((u8) var_r3_1547 == 0) {
                var_r27_1505 = 1;
            }
        }
        this->unk14 = var_r27_1505;
        var_r3_1559 = 0;
        temp_r4_1560 = this->unkC;
        if (((u8) temp_r4_1560->unk5 != 0) || ((u8) temp_r4_1560->unk4 != 0)) {
            var_r3_1559 = 1;
        }
        if (var_r3_1559 != 0) {
            var_r3_1572 = 0;
        } else {
            var_r3_1572 = MKInput_Pressed(0xF, (MKInputDevices) temp_r4_1560->unk0);
        }
        if ((u8) var_r3_1572 == 0) {
            temp_r4_1581 = this->unkC;
            var_r3_1582 = 0;
            if (((u8) temp_r4_1581->unk5 != 0) || ((u8) temp_r4_1581->unk4 != 0)) {
                var_r3_1582 = 1;
            }
            if (var_r3_1582 != 0) {
                var_f1_1594 = 0.0f;
            } else {
                var_f1_1594 = MKInput_GetState(0xF, (MKInputDevices) temp_r4_1581->unk0, NULL, NULL);
            }
            if (var_f1_1594 != 0.0f) {
                goto block_104;
            }
            goto block_123;
        }
block_104:
        temp_r4_1608 = M2C_FIELD(GameData::gameData, s32 *, 0x158) << 5;
        if ((s32) (M2C_FIELD((&GameData::gameData[0x70] + temp_r4_1608), s32 *, 0x60) & 1) == 1) {
            var_r3_1614 = 0;
            *(&GameData::gameData[0x70] + (temp_r4_1608 + 0x7C)) = 0;
            temp_r4_1617 = this->unkC;
            if (((u8) temp_r4_1617->unk5 != 0) || ((u8) temp_r4_1617->unk4 != 0)) {
                var_r3_1614 = 1;
            }
            if (var_r3_1614 != 0) {
                var_r24_1629 = 0;
            } else {
                var_r24_1629 = MKInput_Pressed(0xF, (MKInputDevices) temp_r4_1617->unk0);
            }
            temp_r4_1637 = this->unkC;
            var_r26_1501 = var_r24_1629;
            var_r3_1639 = 0;
            if (((u8) temp_r4_1637->unk5 != 0) || ((u8) temp_r4_1637->unk4 != 0)) {
                var_r3_1639 = 1;
            }
            if (var_r3_1639 != 0) {
                var_f1_1651 = 0.0f;
            } else {
                var_f1_1651 = MKInput_GetState(0xF, (MKInputDevices) temp_r4_1637->unk0, NULL, NULL);
            }
            if (var_f1_1651 != 0.0f) {
                var_r3_1663 = 1;
            } else {
                var_r3_1663 = 0;
            }
            var_r25_1502 = var_r3_1663;
            if (((u8) var_r24_1629 != 0) || (var_r3_1663 != 0)) {
                var_r28_1503 = 0;
            }
        } else {
block_123:
            if ((u8) this->unk14 != 0) {
                temp_r4_1680 = this->unkC;
                var_r3_1681 = 0;
                if (((u8) temp_r4_1680->unk5 != 0) || ((u8) temp_r4_1680->unk4 != 0)) {
                    var_r3_1681 = 1;
                }
                if (var_r3_1681 != 0) {
                    var_f1_1693 = 0.0f;
                } else {
                    var_f1_1693 = MKInput_GetState(0xC, (MKInputDevices) temp_r4_1680->unk0, NULL, NULL);
                }
                if (var_f1_1693 != 0.0f) {
                    temp_r4_1706 = M2C_FIELD(GameData::gameData, s32 *, 0x158) << 5;
                    if ((s32) (M2C_FIELD((&GameData::gameData[0x70] + temp_r4_1706), s32 *, 0x60) & 2) == 2) {
                        *(&GameData::gameData[0x70] + (temp_r4_1706 + 0x7C)) = 1;
                        var_r3_1715 = 0;
                        temp_r4_1716 = this->unkC;
                        if (((u8) temp_r4_1716->unk5 != 0) || ((u8) temp_r4_1716->unk4 != 0)) {
                            var_r3_1715 = 1;
                        }
                        if (var_r3_1715 != 0) {
                            var_r24_1728 = 0;
                        } else {
                            var_r24_1728 = MKInput_Pressed(0xC, (MKInputDevices) temp_r4_1716->unk0);
                        }
                        temp_r4_1736 = this->unkC;
                        var_r26_1501 = var_r24_1728;
                        var_r3_1738 = 0;
                        if (((u8) temp_r4_1736->unk5 != 0) || ((u8) temp_r4_1736->unk4 != 0)) {
                            var_r3_1738 = 1;
                        }
                        if (var_r3_1738 != 0) {
                            var_f1_1750 = 0.0f;
                        } else {
                            var_f1_1750 = MKInput_GetState(0xC, (MKInputDevices) temp_r4_1736->unk0, NULL, NULL);
                        }
                        if (var_f1_1750 != 0.0f) {
                            var_r3_1762 = 1;
                        } else {
                            var_r3_1762 = 0;
                        }
                        var_r25_1502 = var_r3_1762;
                        if (((u8) var_r24_1728 != 0) || (var_r3_1762 != 0)) {
                            var_r28_1503 = 0;
                        }
                        if (((u8) M2C_FIELD(this->unk4, ZapBreathFX **, 0x18)->unk9E0 != 0) && ((s32) M2C_FIELD(GameData::gameData, s32 *, 0x158) == 1)) {
                            temp_r4_1783 = this->unkC;
                            var_r3_1784 = 0;
                            if (((u8) temp_r4_1783->unk5 != 0) || ((u8) temp_r4_1783->unk4 != 0)) {
                                var_r3_1784 = 1;
                            }
                            if (var_r3_1784 != 0) {
                                var_f1_1796 = 0.0f;
                            } else {
                                var_f1_1796 = MKInput_GetState(0xF, (MKInputDevices) temp_r4_1783->unk0, NULL, NULL);
                            }
                            if ((var_f1_1796 == 0.0f) && ((s32) (M2C_FIELD((&GameData::gameData[0x70] + (M2C_FIELD(GameData::gameData, s32 *, 0x158) << 5)), s32 *, 0x60) & 1) == 1)) {
                                var_r28_1503 = 1;
                            }
                        }
                        if (((u8) M2C_FIELD(M2C_FIELD(this->unk4, void **, 0x14), u8 *, 0xB4) != 0) && ((s32) M2C_FIELD(GameData::gameData, s32 *, 0x158) == 0)) {
                            temp_r4_1825 = this->unkC;
                            var_r3_1826 = 0;
                            if (((u8) temp_r4_1825->unk5 != 0) || ((u8) temp_r4_1825->unk4 != 0)) {
                                var_r3_1826 = 1;
                            }
                            if (var_r3_1826 != 0) {
                                var_f1_1838 = 0.0f;
                            } else {
                                var_f1_1838 = MKInput_GetState(0xF, (MKInputDevices) temp_r4_1825->unk0, NULL, NULL);
                            }
                            if ((var_f1_1838 == 0.0f) && ((s32) (M2C_FIELD((&GameData::gameData[0x70] + (M2C_FIELD(GameData::gameData, s32 *, 0x158) << 5)), s32 *, 0x60) & 1) == 1)) {
                                var_r28_1503 = 1;
                            }
                        }
                    }
                }
            }
        }
        if ((u8) arg0->unk3D != 0) {
            ((GameStats *) ((GameStats *) &GameData::gameData[0x70]))->SetCurrentBreath((BreathElement) 0);
            *(&GameData::gameData[0x70] + ((M2C_FIELD(GameData::gameData, s32 *, 0x158) << 5) + 0x7C)) = 1;
        }
        temp_r4_1871 = this->unkC;
        var_r3_1872 = 0;
        if (((u8) temp_r4_1871->unk5 != 0) || ((u8) temp_r4_1871->unk4 != 0)) {
            var_r3_1872 = 1;
        }
        if (var_r3_1872 != 0) {
            var_r3_1884 = 0;
        } else {
            var_r3_1884 = MKInput_Released(0xF, (MKInputDevices) temp_r4_1871->unk0);
        }
        if ((u8) var_r3_1884 == 0) {
            temp_r4_1893 = this->unkC;
            var_r3_1894 = 0;
            if (((u8) temp_r4_1893->unk5 != 0) || ((u8) temp_r4_1893->unk4 != 0)) {
                var_r3_1894 = 1;
            }
            if (var_r3_1894 != 0) {
                var_r3_1906 = 0;
            } else {
                var_r3_1906 = MKInput_Released(0xC, (MKInputDevices) temp_r4_1893->unk0);
            }
            if ((u8) var_r3_1906 != 0) {
                goto block_188;
            }
            goto block_190;
        }
block_188:
        if ((var_r25_1502 != 0) || ((u8) var_r26_1501 != 0)) {
block_190:
            if (((u8) M2C_FIELD(&gb, u8 *, 0x394) != 0) || ((u8) arg0->unk2C != 0)) {
                goto block_192;
            }
        } else {
block_192:
            var_r28_1503 = 1;
        }
        ((KDSound_AfterRumble *) (this->unk4 + 0x40))->Update();
        var_f30_1938 = 0.0f;
        *arg0->unk30 = 0;
        var_r24_1941 = 0;
        temp_f31_1942 = M2C_FIELD(GameData::gameData, f32 *, 0xA0);
        temp_r3_1943 = ((GameStats *) ((GameStats *) &GameData::gameData[0x70]))->GetBreathAttackShotType();
        temp_r7_1944 = arg0->unk3E;
        if (((temp_r7_1944 == 0) && ((u8) arg0->unk34 != 0) && (temp_r4_1952 = M2C_FIELD(GameData::gameData, s32 *, 0x158) << 5, temp_r4_1957 = 1 << *(&GameData::gameData[0x70] + (temp_r4_1952 + 0x7C)), ((temp_r4_1957 == (s32) (temp_r4_1957 & M2C_FIELD((&GameData::gameData[0x70] + temp_r4_1952), s32 *, 0x60))) != 0)) && (((temp_r3_1943 == 1) && ((u8) var_r26_1501 != 0)) || ((temp_r3_1943 == 0) && (var_r25_1502 != 0)))) || ((temp_r7_1944 != 0) && ((u8) var_r26_1501 != 0) && ((u8) arg0->unk34 != 0)) || (((u8) arg0->unk34 != 0) && (temp_r4_1983 = M2C_FIELD(GameData::gameData, s32 *, 0x158) << 5, (((s32) (M2C_FIELD((&GameData::gameData[0x70] + temp_r4_1983), s32 *, 0x60) & 1) == 1) != 0)) && ((s32) M2C_FIELD(GameData::gameData, s32 *, 0x158) == 3) && ((s32) *(&GameData::gameData[0x70] + (temp_r4_1983 + 0x7C)) == 0) && ((s32) *(&GameData::gameData[0x70] + (temp_r4_1983 + 0x64)) == 3) && (var_r25_1502 != 0))) {
            arg0->unk24 = M2C_FIELD(GameData::gameData, s32 *, 0x158);
            arg0->unk28 = *(&GameData::gameData[0x70] + ((M2C_FIELD(GameData::gameData, s32 *, 0x158) << 5) + 0x7C));
            if ((u8) M2C_FIELD(&gb, u8 *, 0x3B5) == 0) {
                if (((u8) var_r26_1501 != 0) || (((s32) arg0->unk24 == 3) && ((s32) arg0->unk28 == 0) && ((s32) *(&GameData::gameData[0x70] + ((M2C_FIELD(GameData::gameData, s32 *, 0x158) << 5) + 0x64)) == 3))) {
                    var_f30_1938 = 0.0f + ((GameStats *) ((GameStats *) &GameData::gameData[0x70]))->GetInitialBreathCost();
                }
                var_f30_1938 += ((GameStats *) ((GameStats *) &GameData::gameData[0x70]))->GetOngoingBreathCost();
            }
            if ((var_f30_1938 <= M2C_FIELD(GameData::gameData, f32 *, 0xA0)) || ((u8) arg0->unk3E != 0) || ((temp_r4_2045 = M2C_FIELD(GameData::gameData, s32 *, 0x158) << 5, (((s32) (M2C_FIELD((&GameData::gameData[0x70] + temp_r4_2045), s32 *, 0x60) & 1) == 1) != 0)) && ((s32) M2C_FIELD(GameData::gameData, s32 *, 0x158) == 0) && ((s32) *(&GameData::gameData[0x70] + (temp_r4_2045 + 0x7C)) == 0) && ((u8) var_r26_1501 != 0))) {
                if ((u8) arg0->unk3E != 0) {
                    TriggerConvexity(arg0);
                } else {
                    temp_r0_2071 = arg0->unk24;
                    switch (temp_r0_2071) {         /* irregular */
                    case 0:
                        if ((((u8) M2C_FIELD(&gb, u8 *, 6) != 0) && ((s32) arg0->unk28 == 0)) || (((u8) M2C_FIELD(&gb, u8 *, 7) != 0) && ((s32) arg0->unk28 == 1))) {
                            var_r24_1941 = TriggerFire(arg0);
                        }
                        break;
                    case 1:
                        if ((((u8) M2C_FIELD(&gb, u8 *, 6) != 0) && ((s32) arg0->unk28 == 0)) || (((u8) M2C_FIELD(&gb, u8 *, 7) != 0) && ((s32) arg0->unk28 == 1))) {
                            var_r24_1941 = TriggerElectricity(arg0);
                        }
                        break;
                    case 2:
                        if ((((u8) M2C_FIELD(&gb, u8 *, 6) != 0) && ((s32) arg0->unk28 == 0)) || (((u8) M2C_FIELD(&gb, u8 *, 7) != 0) && ((s32) arg0->unk28 == 1))) {
                            var_r24_1941 = TriggerIce(arg0);
                        }
                        break;
                    case 3:
                        if ((((u8) M2C_FIELD(&gb, u8 *, 6) != 0) && ((s32) arg0->unk28 == 0)) || (((u8) M2C_FIELD(&gb, u8 *, 7) != 0) && ((s32) arg0->unk28 == 1))) {
                            var_r24_1941 = TriggerEarth(arg0);
                        }
                        break;
                    }
                    *arg0->unk30 = var_r24_1941;
                    if ((var_r24_1941 != 0) && ((u8) M2C_FIELD(&gb, u8 *, 0xB) == 0)) {
                        ((Stat *) ((Stat *) (&GameData::gameData[0x70] + 0x30)))->Add(-var_f30_1938, 1U);
                    }
                }
            }
        }
        if ((var_r28_1503 == 0) && ((u8) arg0->unk34 != 0) && (((u8) M2C_FIELD(&gb, u8 *, 0x3B5) != 0) || !((temp_f31_1942 - var_f30_1938) < 0.0f))) {
            var_r24_2221 = 0;
            temp_r25_2223 = M2C_FIELD(&gb, void **, 0xC);
            temp_r3_2224 = M2C_FIELD(temp_r25_2223, KDSynkerPlayer3 **, 0x78);
            if (((temp_r3_2224 != NULL) && (temp_r3_2224->IsPlaying() != 0)) || (((s32) M2C_FIELD(temp_r25_2223, s32 *, 0x74) == 2) && (((KDStateMachine<CutsceneSystem> *) (temp_r25_2223 + 0x24))->GetState() == 2))) {
                var_r24_2221 = 1;
            }
            if (var_r24_2221 != 0) {
                goto block_264;
            }
        } else {
block_264:
            M2C_FIELD(this->unk4, ZapBreathFX **, 0x18)->unk9E0 = 0;
            ((ZapBreathFX *) (M2C_FIELD(this->unk4, ZapBreathFX **, 0x18)))->ButtonReleased();
            temp_r4_2254 = M2C_FIELD(this->unk4, void **, 0x14);
            M2C_FIELD(temp_r4_2254, s8 *, 0xB4) = 0;
            SoundFadeOut(temp_r4_2254);
        }
        UpdateFury(arg0);
    }
}
#endif

void SpyroEffects::ResetFury() {
    EarthBreathFX *temp_r3_2303;
    FlameBreathFX *temp_r3_2285;
    IceBreathFX *temp_r3_2297;
    ZapBreathFX *temp_r3_2291;
    void *temp_r3_2308;

    temp_r3_2285 = M2C_FIELD(this->unk4, FlameBreathFX **, 0x14);
    if (temp_r3_2285 != NULL) {
        temp_r3_2285->ResetFury();
    }
    temp_r3_2291 = M2C_FIELD(this->unk4, ZapBreathFX **, 0x18);
    if (temp_r3_2291 != NULL) {
        temp_r3_2291->ResetFury();
    }
    temp_r3_2297 = M2C_FIELD(this->unk4, IceBreathFX **, 0x1C);
    if (temp_r3_2297 != NULL) {
        temp_r3_2297->ResetFury();
    }
    temp_r3_2303 = M2C_FIELD(this->unk4, EarthBreathFX **, 0x20);
    if (temp_r3_2303 != NULL) {
        temp_r3_2303->ResetFury();
    }
    temp_r3_2308 = this->unk4;
    if ((u32) M2C_FIELD(temp_r3_2308, u32 *, 0xC0) != 0U) {
        ((FuryFXConvexity *) (M2C_FIELD(temp_r3_2308, FuryFXConvexity **, 0xBC)))->ResetFury();
    }
    M2C_FIELD(&gb, s8 *, 0x381) = 0;
}

void SpyroEffects::Deinit() {

}

void SpyroEffects::Init(SpyroFXData *arg0, MKProp *arg1, SpyroSoundPlayer *arg2) {
    this->unk4 = arg0;
    this->unk8 = arg1;
    this->unkC = NULL;
    this->unk10 = arg2;
    this->unk14 = 0;
}

#if 0 // DRAFT: illegal implicit conversion from 'long *' to
void SpyroFXData::Deinit() {
    CharacterBodyFXManager *temp_r31_2354;

    temp_r31_2354 = &gb + 0x2A8;
    temp_r31_2354->DestroyInstance(this->unkB4);
    temp_r31_2354->DestroyInstance(this->unk28);
    this->unk0.Deinit();
    this->unk8.Deinit();
    MKMaterial_Destroy(this->unk30);
    temp_r31_2354->DestroyInstance(this->unkC4);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'HitFX *' to
void SpyroFXData::Init(MKProp *arg0, MKModel *arg1, MKAnimScript *arg2) {
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    CharacterBodyFX *temp_r3_2540;
    CharacterBodyFX *temp_r3_2558;
    CharacterBodyFX *temp_r3_2618;
    CharacterBodyFX *temp_r3_2623;
    CharacterBodyFXManager *temp_r27_2532;

    this->unk40.Init();
    this->unk10 = checked_cast<HitFX *, MKProp>(gMK->CreateProp("HitFX"));
    this->unk14 = checked_cast<FlameBreathFX *, MKProp>(gMK->CreateProp("FlameBreathFX"));
    this->unk14->unk9C = (MKHeap *) &this->unk14;
    this->unk18 = checked_cast<ZapBreathFX *, MKProp>(gMK->CreateProp("ZapBreathFX"));
    this->unk18->unk9C = &this->unk18;
    this->unk1C = checked_cast<IceBreathFX *, MKProp>(gMK->CreateProp("IceBreathFX"));
    this->unk1C->unk9C = (MKHeap *) &this->unk1C;
    this->unk24 = checked_cast<MoltenMetalPS *, MKProp>(gMK->CreateProp("MoltenMetalPS"));
    this->unk20 = checked_cast<EarthBreathFX *, MKProp>(gMK->CreateProp("EarthBreathFX"));
    this->unk20->unk9C = (MKHeap *) &this->unk20;
    this->unk34 = checked_cast<EarthShockwave *, MKProp>(gMK->CreateProp("TailStrikeShockwave"));
    this->unkC8 = checked_cast<LineSegmentTrail *, MKProp>(gMK->CreateProp("LineSegmentTrail"));
    this->unkCC = checked_cast<LineSegmentTrail *, MKProp>(gMK->CreateProp("LineSegmentTrail"));
    this->unkBC = checked_cast<FuryFXConvexity *, MKProp>(gMK->CreateProp("FuryFXConvexity"));
    this->unkC0 = checked_cast<ConvexityBreathFX *, MKProp>(gMK->CreateProp("ConvexityBreathFX"));
    sp14 = (s32) Tools_GetMatchingRefPointIndex(arg1, "WTStart_L");
    sp10 = (s32) Tools_GetMatchingRefPointIndex(arg1, "WTEnd_L");
    spC = (s32) Tools_GetMatchingRefPointIndex(arg1, "WTStart_R");
    sp8 = (s32) Tools_GetMatchingRefPointIndex(arg1, "WTEnd_R");
    this->unkC8->SetUserData(arg2, sp14, sp10, "fx_306");
    this->unkCC->SetUserData(arg2, spC, sp8, "fx_306");
    this->unk0.Init(&spyroBodyFXData, 0xC, arg2);
    temp_r27_2532 = &gb + 0x2A8;
    this->unkB4 = checked_cast<CharacterZapFX *, CharacterBodyFX>(temp_r27_2532->CreateInstance(2));
    temp_r3_2540 = this->unkB4;
    temp_r3_2540->InitData(this, arg1, 0);
    this->unk8.Init(&spyroBodyFXData + 0x240, 9, arg2);
    this->unk28 = checked_cast<CharacterGlowFX *, CharacterBodyFX>(temp_r27_2532->CreateInstance(1));
    temp_r3_2558 = this->unk28;
    temp_r3_2558->InitData(&this->unk8, arg1, 0);
    this->unk38 = MKModel_GetRefPointIndex(arg1, "r_a001_nose");
    this->unk2C = checked_cast<MeleeTrails *, MKProp>(gMK->CreateProp("SpyroMeleeTrails"));
    this->unk2C->ResolveAnims(arg2);
    this->unk30 = MKMaterial_Create"fx_HDRGLowOverlay";
    this->unkB0 = checked_cast<BoneBlurFX *, MKProp>(gMK->CreateProp("BoneBlurFX"));
    this->unkB0->InitData(arg1, &spyroBodyFXData + 0x3F0, 0x21, &spyroBodyFXData + 0x61C, 7, 3, 1U);
    this->unkB0->EnableBlur(1U);
    this->unkB0->unk78 = (s32 *) &this->unkB0;
    this->unkB8 = checked_cast<WaterSurfaceFX *, MKProp>(gMK->CreateProp("WaterSurfaceFX"));
    this->unkC4 = checked_cast<CharacterIceCubesFX *, CharacterBodyFX>(temp_r27_2532->CreateInstance(0));
    temp_r3_2618 = this->unkC4;
    temp_r3_2618->Init();
    temp_r3_2623 = this->unkC4;
    temp_r3_2623->InitData(this, arg1, 0);
}
#endif

#if 0 // DRAFT: undefined identifier 'spyroBodyFXData'
void SpyroEffects_cpp::__sinit() {
    f32 sp2A0;
    f32 sp29C;
    f32 sp298;
    f32 sp290;
    f32 sp28C;
    f32 sp288;
    f32 sp280;
    f32 sp27C;
    f32 sp278;
    f32 sp270;
    f32 sp26C;
    f32 sp268;
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
    f32 sp22C;
    f32 sp228;
    f32 sp220;
    f32 sp21C;
    f32 sp218;
    f32 sp210;
    f32 sp20C;
    f32 sp208;
    f32 sp200;
    f32 sp1FC;
    f32 sp1F8;
    f32 sp1F0;
    f32 sp1EC;
    f32 sp1E8;
    f32 sp1E0;
    f32 sp1DC;
    f32 sp1D8;
    f32 sp1D0;
    f32 sp1CC;
    f32 sp1C8;
    f32 sp1C0;
    f32 sp1BC;
    f32 sp1B8;
    f32 sp1B0;
    f32 sp1AC;
    f32 sp1A8;
    f32 sp1A0;
    f32 sp19C;
    f32 sp198;
    f32 sp190;
    f32 sp18C;
    f32 sp188;
    f32 sp180;
    f32 sp17C;
    f32 sp178;
    f32 sp170;
    f32 sp16C;
    f32 sp168;
    f32 sp160;
    f32 sp15C;
    f32 sp158;
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
    f32 sp10C;
    f32 sp108;
    f32 sp100;
    f32 spFC;
    f32 spF8;
    f32 spF0;
    f32 spEC;
    f32 spE8;
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
    f32 sp10;
    f32 spC;
    f32 sp8;
    f64 temp_f0_2746;
    f64 temp_f10_2762;
    f64 temp_f20_2773;
    f64 temp_f21_2779;
    f64 temp_f3_2744;
    f64 temp_f4_2739;
    f64 temp_f5_2741;
    f64 temp_f9_2755;

    temp_f4_2739 = __frsqrte(2014000.0);
    temp_f5_2741 = __frsqrte(380000.0);
    temp_f3_2744 = temp_f4_2739 * temp_f4_2739;
    temp_f0_2746 = temp_f5_2741 * temp_f5_2741;
    sp2A0 = 1.0f;
    sp290 = 0.0f;
    sp280 = 1.0f;
    sp270 = 0.0f;
    temp_f9_2755 = 0.5 * temp_f4_2739 * -((2014000.0 * temp_f3_2744) - 3.0);
    sp298 = 1.0f;
    temp_f10_2762 = 0.5 * temp_f5_2741 * -((380000.0 * temp_f0_2746) - 3.0);
    sp29C = 1.0f;
    sp288 = 0.0f;
    sp28C = 0.0f;
    sp278 = 1.0f;
    temp_f20_2773 = 0.5 * temp_f9_2755 * -((2014000.0 * (temp_f9_2755 * temp_f9_2755)) - 3.0);
    sp27C = 1.0f;
    sp268 = 0.0f;
    temp_f21_2779 = 0.5 * temp_f10_2762 * -((380000.0 * (temp_f10_2762 * temp_f10_2762)) - 3.0);
    sp26C = 0.0f;
    M2C_FIELD(&spyroBodyFXData, f64 *, 0x10) = (f64) sp298;
    M2C_FIELD(&spyroBodyFXData, f64 *, 0x18) = (f64) sp2A0;
    M2C_FIELD(&spyroBodyFXData, f64 *, 0x20) = (f64) sp288;
    M2C_FIELD(&spyroBodyFXData, f64 *, 0x28) = (f64) sp290;
    M2C_FIELD(&spyroBodyFXData, f64 *, 0x40) = (f64) sp278;
    M2C_FIELD(&spyroBodyFXData, f64 *, 0x48) = (f64) sp280;
    M2C_FIELD(&spyroBodyFXData, f64 *, 0x50) = (f64) sp268;
    M2C_FIELD(&spyroBodyFXData, f64 *, 0x58) = (f64) sp270;
    SPYRO_BOUNCE_Y_SPEED = (f32) (2014000.0 * (0.5 * temp_f20_2773 * -((2014000.0 * (temp_f20_2773 * temp_f20_2773)) - 3.0)));
    SPYRO_MIN_JUMP_Y_VELOCITY = (f32) (380000.0 * (0.5 * temp_f21_2779 * -((380000.0 * (temp_f21_2779 * temp_f21_2779)) - 3.0)));
    sp260 = 1.0f;
    sp250 = 0.0f;
    sp240 = 1.0f;
    sp230 = 0.0f;
    sp220 = 1.0f;
    sp210 = 0.0f;
    sp200 = 1.0f;
    sp1F0 = 0.0f;
    sp258 = 1.0f;
    sp25C = 1.0f;
    sp248 = 0.0f;
    sp24C = 0.0f;
    sp238 = 1.0f;
    sp23C = 1.0f;
    sp228 = 0.0f;
    sp22C = 0.0f;
    sp218 = 1.0f;
    sp21C = 1.0f;
    sp208 = 0.0f;
    sp20C = 0.0f;
    sp1F8 = 1.0f;
    sp1FC = 1.0f;
    sp1E8 = 0.0f;
    sp1EC = 0.0f;
    M2C_FIELD(&spyroBodyFXData, f64 *, 0x70) = (f64) sp258;
    M2C_FIELD(&spyroBodyFXData, f64 *, 0x78) = (f64) sp260;
    M2C_FIELD(&spyroBodyFXData, f64 *, 0x80) = (f64) sp248;
    M2C_FIELD(&spyroBodyFXData, f64 *, 0x88) = (f64) sp250;
    M2C_FIELD(&spyroBodyFXData, f64 *, 0xA0) = (f64) sp238;
    M2C_FIELD(&spyroBodyFXData, f64 *, 0xA8) = (f64) sp240;
    M2C_FIELD(&spyroBodyFXData, f64 *, 0xB0) = (f64) sp228;
    M2C_FIELD(&spyroBodyFXData, f64 *, 0xB8) = (f64) sp230;
    M2C_FIELD(&spyroBodyFXData, f64 *, 0xD0) = (f64) sp218;
    M2C_FIELD(&spyroBodyFXData, f64 *, 0xD8) = (f64) sp220;
    M2C_FIELD(&spyroBodyFXData, f64 *, 0xE0) = (f64) sp208;
    M2C_FIELD(&spyroBodyFXData, f64 *, 0xE8) = (f64) sp210;
    M2C_FIELD(&spyroBodyFXData, f64 *, 0x100) = (f64) sp1F8;
    M2C_FIELD(&spyroBodyFXData, f64 *, 0x108) = (f64) sp200;
    M2C_FIELD(&spyroBodyFXData, f64 *, 0x110) = (f64) sp1E8;
    M2C_FIELD(&spyroBodyFXData, f64 *, 0x118) = (f64) sp1F0;
    sp1D8 = 1.0f;
    sp1DC = 1.0f;
    sp1E0 = 1.0f;
    sp1D0 = 0.0f;
    sp1C0 = 1.0f;
    sp1B0 = 0.0f;
    sp1A0 = 1.0f;
    sp190 = 0.0f;
    sp180 = 1.0f;
    sp170 = 0.0f;
    sp160 = 1.0f;
    sp1C8 = 0.0f;
    sp1CC = 0.0f;
    sp1B8 = 1.0f;
    sp1BC = 1.0f;
    sp1A8 = 0.0f;
    sp1AC = 0.0f;
    sp198 = 1.0f;
    sp19C = 1.0f;
    sp188 = 0.0f;
    sp18C = 0.0f;
    sp178 = 1.0f;
    sp17C = 1.0f;
    sp168 = 0.0f;
    sp16C = 0.0f;
    sp158 = 1.0f;
    sp15C = 1.0f;
    M2C_FIELD(&spyroBodyFXData, f64 *, 0x130) = (f64) sp1D8;
    M2C_FIELD(&spyroBodyFXData, f64 *, 0x138) = (f64) sp1E0;
    M2C_FIELD(&spyroBodyFXData, f64 *, 0x140) = (f64) sp1C8;
    M2C_FIELD(&spyroBodyFXData, f64 *, 0x148) = (f64) sp1D0;
    M2C_FIELD(&spyroBodyFXData, f64 *, 0x160) = (f64) sp1B8;
    M2C_FIELD(&spyroBodyFXData, f64 *, 0x168) = (f64) sp1C0;
    M2C_FIELD(&spyroBodyFXData, f64 *, 0x170) = (f64) sp1A8;
    M2C_FIELD(&spyroBodyFXData, f64 *, 0x178) = (f64) sp1B0;
    M2C_FIELD(&spyroBodyFXData, f64 *, 0x190) = (f64) sp198;
    M2C_FIELD(&spyroBodyFXData, f64 *, 0x198) = (f64) sp1A0;
    M2C_FIELD(&spyroBodyFXData, f64 *, 0x1A0) = (f64) sp188;
    M2C_FIELD(&spyroBodyFXData, f64 *, 0x1A8) = (f64) sp190;
    M2C_FIELD(&spyroBodyFXData, f64 *, 0x1C0) = (f64) sp178;
    M2C_FIELD(&spyroBodyFXData, f64 *, 0x1C8) = (f64) sp180;
    M2C_FIELD(&spyroBodyFXData, f64 *, 0x1D0) = (f64) sp168;
    M2C_FIELD(&spyroBodyFXData, f64 *, 0x1D8) = (f64) sp170;
    M2C_FIELD(&spyroBodyFXData, f64 *, 0x1F0) = (f64) sp158;
    M2C_FIELD(&spyroBodyFXData, f64 *, 0x1F8) = (f64) sp160;
    sp150 = 0.0f;
    sp140 = 1.0f;
    sp130 = 0.0f;
    sp120 = 1.0f;
    sp110 = 0.0f;
    sp100 = 1.0f;
    spF0 = 0.0f;
    spE0 = 1.0f;
    sp148 = 0.0f;
    sp14C = 0.0f;
    sp138 = 1.0f;
    sp13C = 1.0f;
    sp128 = 0.0f;
    sp12C = 0.0f;
    sp118 = 3.0f;
    sp11C = 1.0f;
    sp108 = 0.0f;
    sp10C = 0.0f;
    spF8 = 2.0f;
    spFC = 1.0f;
    spE8 = 0.0f;
    spEC = 0.0f;
    spD8 = 1.5f;
    spDC = 1.0f;
    M2C_FIELD(&spyroBodyFXData, f64 *, 0x200) = (f64) sp148;
    M2C_FIELD(&spyroBodyFXData, f64 *, 0x208) = (f64) sp150;
    M2C_FIELD(&spyroBodyFXData, f64 *, 0x220) = (f64) sp138;
    M2C_FIELD(&spyroBodyFXData, f64 *, 0x228) = (f64) sp140;
    M2C_FIELD(&spyroBodyFXData, f64 *, 0x230) = (f64) sp128;
    M2C_FIELD(&spyroBodyFXData, f64 *, 0x238) = (f64) sp130;
    M2C_FIELD(&spyroGlowFXData, f64 *, 0x10) = (f64) sp118;
    M2C_FIELD(&spyroGlowFXData, f64 *, 0x18) = (f64) sp120;
    M2C_FIELD(&spyroGlowFXData, f64 *, 0x20) = (f64) sp108;
    M2C_FIELD(&spyroGlowFXData, f64 *, 0x28) = (f64) sp110;
    M2C_FIELD(&spyroGlowFXData, f64 *, 0x40) = (f64) spF8;
    M2C_FIELD(&spyroGlowFXData, f64 *, 0x48) = (f64) sp100;
    M2C_FIELD(&spyroGlowFXData, f64 *, 0x50) = (f64) spE8;
    M2C_FIELD(&spyroGlowFXData, f64 *, 0x58) = (f64) spF0;
    M2C_FIELD(&spyroGlowFXData, f64 *, 0x70) = (f64) spD8;
    M2C_FIELD(&spyroGlowFXData, f64 *, 0x78) = (f64) spE0;
    spC8 = 0.0f;
    spCC = 0.0f;
    spD0 = 0.0f;
    spC0 = 1.0f;
    spB0 = 0.0f;
    spA0 = 1.0f;
    sp90 = 0.0f;
    sp80 = 1.0f;
    sp70 = 0.0f;
    sp60 = 1.0f;
    sp50 = 0.0f;
    sp40 = 1.0f;
    sp30 = 0.0f;
    sp20 = 1.0f;
    sp10 = -12.5f;
    spB8 = 1.0f;
    spBC = 1.0f;
    spA8 = 0.0f;
    spAC = 0.0f;
    sp98 = 3.0f;
    sp9C = 1.0f;
    sp88 = 0.0f;
    sp8C = 0.0f;
    sp78 = 2.5f;
    sp7C = 1.0f;
    sp68 = 0.0f;
    sp6C = 0.0f;
    sp58 = 2.5f;
    sp5C = 1.0f;
    sp48 = 0.0f;
    sp4C = 0.0f;
    sp38 = 2.5f;
    sp3C = 1.0f;
    sp28 = 0.0f;
    sp2C = 0.0f;
    sp18 = 3.0f;
    sp1C = 1.0f;
    sp8 = 0.0f;
    spC = 25.0f;
    M2C_FIELD(&spyroGlowFXData, f64 *, 0x80) = (f64) spC8;
    M2C_FIELD(&spyroGlowFXData, f64 *, 0x88) = (f64) spD0;
    M2C_FIELD(&spyroGlowFXData, f64 *, 0xA0) = (f64) spB8;
    M2C_FIELD(&spyroGlowFXData, f64 *, 0xA8) = (f64) spC0;
    M2C_FIELD(&spyroGlowFXData, f64 *, 0xB0) = (f64) spA8;
    M2C_FIELD(&spyroGlowFXData, f64 *, 0xB8) = (f64) spB0;
    M2C_FIELD(&spyroGlowFXData, f64 *, 0xD0) = (f64) sp98;
    M2C_FIELD(&spyroGlowFXData, f64 *, 0xD8) = (f64) spA0;
    M2C_FIELD(&spyroGlowFXData, f64 *, 0xE0) = (f64) sp88;
    M2C_FIELD(&spyroGlowFXData, f64 *, 0xE8) = (f64) sp90;
    M2C_FIELD(&spyroGlowFXData, f64 *, 0x100) = (f64) sp78;
    M2C_FIELD(&spyroGlowFXData, f64 *, 0x108) = (f64) sp80;
    M2C_FIELD(&spyroGlowFXData, f64 *, 0x110) = (f64) sp68;
    M2C_FIELD(&spyroGlowFXData, f64 *, 0x118) = (f64) sp70;
    M2C_FIELD(&spyroGlowFXData, f64 *, 0x130) = (f64) sp58;
    M2C_FIELD(&spyroGlowFXData, f64 *, 0x138) = (f64) sp60;
    M2C_FIELD(&spyroGlowFXData, f64 *, 0x140) = (f64) sp48;
    M2C_FIELD(&spyroGlowFXData, f64 *, 0x148) = (f64) sp50;
    M2C_FIELD(&spyroGlowFXData, f64 *, 0x160) = (f64) sp38;
    M2C_FIELD(&spyroGlowFXData, f64 *, 0x168) = (f64) sp40;
    M2C_FIELD(&spyroGlowFXData, f64 *, 0x170) = (f64) sp28;
    M2C_FIELD(&spyroGlowFXData, f64 *, 0x178) = (f64) sp30;
    M2C_FIELD(&spyroGlowFXData, f64 *, 0x190) = (f64) sp18;
    M2C_FIELD(&spyroGlowFXData, f64 *, 0x198) = (f64) sp20;
    M2C_FIELD(&spyroGlowFXData, f64 *, 0x1A0) = (f64) sp8;
    M2C_FIELD(&spyroGlowFXData, f64 *, 0x1A8) = (f64) sp10;
}
#endif
