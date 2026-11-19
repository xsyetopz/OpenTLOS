#include "spyro/source/SpyroUtils.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKVector3.h"
#include "spyro/source/GameData.h"
#include "spyro/source/HeroInterface.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/EventCamera.h"
#include <m2c_macros.h>

extern s32 GS_PLACEHOLDER;
extern s32 GS_SpyBreathFireLP;
extern s32 GS_SpyBreathFireLP2;
extern s32 GS_SpyBreathFireLP3;
extern s32 GS_SpyBreathFireLP4;
extern s32 GS_SpyBreathIceLP;
extern s32 GS_SpyBreathIceLP2;
extern s32 GS_SpyBreathIceLP3;
extern s32 GS_SpyBreathIceLP4;
extern s32 GS_SpyroBrEnergyLP;
extern s32 GS_SpyroBrEnergyLP2;
extern s32 GS_SpyroBrEnergyLP3;
extern s32 GS_SpyroBrEnergyLP4;
extern s32 GS_SpyroBrEnergyRandom;
extern s32 GS_SpyroBreathCharge1;
extern s32 GS_SpyroBreathEarthChargeLP;
extern s32 GS_SpyroBreathIce2LP;
extern s32 GS_SpyroBreathIce2LP2;
extern s32 GS_SpyroBreathIce2LP3;
extern s32 GS_SpyroBreathIce2LP4;
extern s32 GS_SpyroDeathFall;
extern s32 GS_SpyroFuryRageEarthLP;
extern s32 GS_SpyroFuryRageFireLP;
extern s32 GS_SpyroFuryRageIceLP;
extern s32 GS_SpyroGlideLP;
extern s32 GS_SpyroIceSlide;
extern s32 GS_SpyroWaterMoveLP;
extern s32 GS_StaticLP;
extern f32 SPYRO_BOUNCE_Y_SPEED;
extern f32 SPYRO_MIN_JUMP_Y_VELOCITY;
extern M2C_UNK gb;

#if 0 // DRAFT: illegal implicit conversion from 'SpyroSoundPlayer' to
void SpyroSoundPlayer::UpdatePitch(int arg0) {
    s32 temp_r31_15;
    s32 temp_r3_17;

    temp_r31_15 = arg0 * 0x58;
    temp_r3_17 = *(this + temp_r31_15);
    if (temp_r3_17 > 0) {
        KDSound_SetPitch(temp_r3_17, M2C_FIELD((this + temp_r31_15), f32 *, 0x40));
        M2C_FIELD((this + temp_r31_15), s8 *, 0x35) = 0;
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'SpyroSoundPlayer *' to
void SpyroSoundPlayer::PlaySounds(int arg0, bool arg1) {
    s32 sp8;
    KDSoundFader *temp_r3_60;
    s32 temp_r28_48;
    s32 temp_r29_46;
    s32 temp_r30_41;
    u8 var_r31_52;
    u8 var_r31_73;
    void *temp_r3_91;
    void *temp_r5_44;

    temp_r30_41 = arg0 * 0x58;
    temp_r5_44 = this + temp_r30_41;
    temp_r29_46 = M2C_FIELD(temp_r5_44, s32 *, 0x2C);
    temp_r28_48 = M2C_FIELD(temp_r5_44, s32 *, 0x30);
    if ((u8) M2C_FIELD(temp_r5_44, u8 *, 0x34) == 1) {
        DetermineSoundPos(arg0);
        var_r31_52 = 0;
        if ((arg1 != 0) && (EventCamera_GetCurrent() == NULL)) {
            var_r31_52 = 1;
        }
        temp_r3_60 = this + temp_r30_41;
        sp8 = 1;
        temp_r3_60->Update(temp_r29_46, 1U, var_r31_52, NULL, temp_r3_60 + 0x48, 0U, temp_r28_48, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
        return;
    }
    var_r31_73 = 0;
    if ((arg1 != 0) && (EventCamera_GetCurrent() == NULL)) {
        var_r31_73 = 1;
    }
    sp8 = 1;
    ((KDSoundFader *) (this + temp_r30_41))->Update(temp_r29_46, 0U, var_r31_73, NULL, NULL, 0U, temp_r28_48, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    temp_r3_91 = this + temp_r30_41;
    M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
    if (M2C_FIELD(temp_r3_91, f32 *, 8) == 0.0f) {
        M2C_FIELD(temp_r3_91, s32 *, 0x28) = 2;
    }
}
#endif

#if 0 // DRAFT: illegal use of abstract class ('HeroInterface::pure_slot0()')
void SpyroSoundPlayer::DetermineSoundPos(int arg0) {
    f64 spE8;
    f64 spE0;
    HeroInterface spD0;
    HeroInterface spC0;
    HeroInterface spB0;
    HeroInterface spA0;
    HeroInterface sp90;
    HeroInterface sp80;
    HeroInterface sp70;
    HeroInterface sp60;
    HeroInterface sp50;
    HeroInterface sp40;
    HeroInterface sp30;
    HeroInterface sp20;
    HeroInterface sp10;
    f32 sp8;
    f32 temp_f1_128;
    f32 temp_f2_127;
    f32 temp_f4_130;
    f32 var_f1_202;
    f32 var_f4_135;
    f64 temp_f1_122;
    f64 temp_f1_141;
    f64 temp_f1_147;
    f64 temp_f1_151;
    f64 temp_f3_123;
    s32 temp_r3_170;
    s32 var_r0_180;
    void *temp_r31_120;
    void *temp_r5_121;

    temp_r31_120 = this + ((arg0 * 0x58) + 0x48);
    temp_r5_121 = M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 8);
    temp_f1_122 = M2C_FIELD(temp_r5_121, f64 *, 0x30);
    temp_f3_123 = M2C_FIELD(temp_r5_121, f64 *, 0x38);
    spE0 = temp_f1_122;
    M2C_FIELD(temp_r31_120, f64 *, 0) = temp_f1_122;
    M2C_FIELD(temp_r31_120, f64 *, 8) = temp_f3_123;
    temp_f2_127 = (f32) M2C_FIELD(temp_r31_120, f64 *, 0);
    temp_f1_128 = M2C_FIELD(temp_r31_120, f32 *, 4);
    temp_f4_130 = (f32) M2C_FIELD(temp_r31_120, f64 *, 8);
    spE8 = temp_f3_123;
    var_f4_135 = (temp_f4_130 * temp_f4_130) + ((temp_f2_127 * temp_f2_127) + (temp_f1_128 * temp_f1_128));
    if (var_f4_135 > 0.000001f) {
        if (var_f4_135 > 0.0f) {
            temp_f1_141 = __frsqrte(var_f4_135);
            temp_f1_147 = 0.5 * temp_f1_141 * -(((f64) var_f4_135 * (temp_f1_141 * temp_f1_141)) - 3.0);
            temp_f1_151 = 0.5 * temp_f1_147 * -(((f64) var_f4_135 * (temp_f1_147 * temp_f1_147)) - 3.0);
            var_f4_135 = (f32) ((f64) var_f4_135 * (0.5 * temp_f1_151 * -(((f64) var_f4_135 * (temp_f1_151 * temp_f1_151)) - 3.0)));
        } else if (var_f4_135 < M2C_BITWISE(f32, 0.0)) {
            var_f4_135 = __float_nan;
        } else {
            sp8 = var_f4_135;
            temp_r3_170 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r3_170) {                  /* switch 1; irregular */
            case 0x7F800000:                        /* switch 1 */
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_180 = 1;
                } else {
                    var_r0_180 = 2;
                }
                break;
            case 0x0:                               /* switch 1 */
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_180 = 5;
                } else {
                    var_r0_180 = 3;
                }
                break;
            default:                                /* switch 1 */
                var_r0_180 = 4;
                break;
            }
            if (var_r0_180 == 1) {
                var_f4_135 = __float_nan;
            }
        }
        var_f1_202 = 1.0f / var_f4_135;
    } else {
        var_f1_202 = 0.0f;
    }
    M2C_FIELD(temp_r31_120, f64 *, 0) = (f32) ((f32) M2C_FIELD(temp_r31_120, f64 *, 0) * var_f1_202);
    M2C_FIELD(temp_r31_120, f32 *, 4) = (f32) (M2C_FIELD(temp_r31_120, f32 *, 4) * var_f1_202);
    M2C_FIELD(temp_r31_120, f64 *, 8) = (f32) ((f32) M2C_FIELD(temp_r31_120, f64 *, 8) * var_f1_202);
    if ((u32) arg0 <= 0xCU) {
        switch (arg0) {                             /* switch 2 */
        case 0:                                     /* switch 2 */
            spD0.GetPos();
            M2C_FIELD(temp_r31_120, f64 *, 0) = M2C_BITWISE(f64, spD0);
            M2C_FIELD(temp_r31_120, f64 *, 8) = spD0.unk8;
            return;
        case 2:                                     /* switch 2 */
            spC0.GetPos();
            M2C_FIELD(temp_r31_120, f64 *, 0) = M2C_BITWISE(f64, spC0);
            M2C_FIELD(temp_r31_120, f64 *, 8) = spC0.unk8;
            return;
        case 1:                                     /* switch 2 */
            spB0.GetPos();
            M2C_FIELD(temp_r31_120, f64 *, 0) = M2C_BITWISE(f64, spB0);
            M2C_FIELD(temp_r31_120, f64 *, 8) = spB0.unk8;
            return;
        case 3:                                     /* switch 2 */
            spA0.GetPos();
            M2C_FIELD(temp_r31_120, f64 *, 0) = M2C_BITWISE(f64, spA0);
            M2C_FIELD(temp_r31_120, f64 *, 8) = spA0.unk8;
            return;
        case 4:                                     /* switch 2 */
            sp90.GetPos();
            M2C_FIELD(temp_r31_120, f64 *, 0) = M2C_BITWISE(f64, sp90);
            M2C_FIELD(temp_r31_120, f64 *, 8) = sp90.unk8;
            return;
        case 5:                                     /* switch 2 */
            sp80.GetPos();
            M2C_FIELD(temp_r31_120, f64 *, 0) = M2C_BITWISE(f64, sp80);
            M2C_FIELD(temp_r31_120, f64 *, 8) = sp80.unk8;
            return;
        case 6:                                     /* switch 2 */
            sp70.GetPos();
            M2C_FIELD(temp_r31_120, f64 *, 0) = M2C_BITWISE(f64, sp70);
            M2C_FIELD(temp_r31_120, f64 *, 8) = sp70.unk8;
            return;
        case 7:                                     /* switch 2 */
            sp60.GetPos();
            M2C_FIELD(temp_r31_120, f64 *, 0) = M2C_BITWISE(f64, sp60);
            M2C_FIELD(temp_r31_120, f64 *, 8) = sp60.unk8;
            return;
        case 8:                                     /* switch 2 */
            sp50.GetPos();
            M2C_FIELD(temp_r31_120, f64 *, 0) = M2C_BITWISE(f64, sp50);
            M2C_FIELD(temp_r31_120, f64 *, 8) = sp50.unk8;
            return;
        case 9:                                     /* switch 2 */
            sp40.GetPos();
            M2C_FIELD(temp_r31_120, f64 *, 0) = M2C_BITWISE(f64, sp40);
            M2C_FIELD(temp_r31_120, f64 *, 8) = sp40.unk8;
            return;
        case 10:                                    /* switch 2 */
            sp30.GetPos();
            M2C_FIELD(temp_r31_120, f64 *, 0) = M2C_BITWISE(f64, sp30);
            M2C_FIELD(temp_r31_120, f64 *, 8) = sp30.unk8;
            return;
        case 12:                                    /* switch 2 */
            sp20.GetPos();
            M2C_FIELD(temp_r31_120, f64 *, 0) = M2C_BITWISE(f64, sp20);
            M2C_FIELD(temp_r31_120, f64 *, 8) = sp20.unk8;
            return;
        case 11:                                    /* switch 2 */
            sp10.GetPos();
            M2C_FIELD(temp_r31_120, f64 *, 0) = M2C_BITWISE(f64, sp10);
            M2C_FIELD(temp_r31_120, f64 *, 8) = sp10.unk8;
            break;
        }
    }
}
#endif

s8 SpyroSoundPlayer::Determine3DSound(int arg0) {
    if ((u32) arg0 <= 0xCU) {
        switch (arg0) {
        case 0:
            return 1;
        case 2:
            return 1;
        case 1:
            return 1;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 1;
        case 6:
            return 1;
        case 7:
            return 1;
        case 8:
            return 1;
        case 9:
            return 1;
        case 10:
            return 1;
        case 12:
            return 1;
        case 11:
            return 1;
        }
    } else {
        return 0;
    }
}

void SpyroSoundPlayer::DetermineFadeTimes(int arg0) {
    void *temp_r3_468;
    void *temp_r3_475;
    void *temp_r3_483;
    void *temp_r3_490;
    void *temp_r3_498;
    void *temp_r3_506;
    void *temp_r3_514;
    void *temp_r3_522;
    void *temp_r3_530;
    void *temp_r3_537;
    void *temp_r3_545;
    void *temp_r3_552;
    void *temp_r3_559;

    if ((u32) arg0 <= 0xCU) {
        switch (arg0) {
        case 0:
            temp_r3_468 = this + (arg0 * 0x58);
            M2C_FIELD(temp_r3_468, f32 *, 4) = 0.5f;
            M2C_FIELD(temp_r3_468, f32 *, 8) = 0.5f;
            return;
        case 2:
            temp_r3_475 = this + (arg0 * 0x58);
            M2C_FIELD(temp_r3_475, f32 *, 4) = 0.75f;
            M2C_FIELD(temp_r3_475, f32 *, 8) = 0.75f;
            return;
        case 1:
            temp_r3_483 = this + (arg0 * 0x58);
            M2C_FIELD(temp_r3_483, f32 *, 4) = 0.25f;
            M2C_FIELD(temp_r3_483, f32 *, 8) = 0.75f;
            return;
        case 3:
            temp_r3_490 = this + (arg0 * 0x58);
            M2C_FIELD(temp_r3_490, f32 *, 4) = 0.5f;
            M2C_FIELD(temp_r3_490, f32 *, 8) = 0.5f;
            return;
        case 4:
            temp_r3_498 = this + (arg0 * 0x58);
            M2C_FIELD(temp_r3_498, f32 *, 4) = 0.5f;
            M2C_FIELD(temp_r3_498, f32 *, 8) = 0.05f;
            return;
        case 5:
            temp_r3_506 = this + (arg0 * 0x58);
            M2C_FIELD(temp_r3_506, f32 *, 4) = 0.05f;
            M2C_FIELD(temp_r3_506, f32 *, 8) = 0.5f;
            return;
        case 6:
            temp_r3_514 = this + (arg0 * 0x58);
            M2C_FIELD(temp_r3_514, f32 *, 4) = 0.05f;
            M2C_FIELD(temp_r3_514, f32 *, 8) = 0.75f;
            return;
        case 7:
            temp_r3_522 = this + (arg0 * 0x58);
            M2C_FIELD(temp_r3_522, f32 *, 4) = 0.05f;
            M2C_FIELD(temp_r3_522, f32 *, 8) = 0.75f;
            return;
        case 8:
            temp_r3_530 = this + (arg0 * 0x58);
            M2C_FIELD(temp_r3_530, f32 *, 4) = 0.05f;
            M2C_FIELD(temp_r3_530, f32 *, 8) = 0.75f;
            return;
        case 9:
            temp_r3_537 = this + (arg0 * 0x58);
            M2C_FIELD(temp_r3_537, f32 *, 4) = 0.05f;
            M2C_FIELD(temp_r3_537, f32 *, 8) = 0.05f;
            return;
        case 10:
            temp_r3_545 = this + (arg0 * 0x58);
            M2C_FIELD(temp_r3_545, f32 *, 4) = 0.05f;
            M2C_FIELD(temp_r3_545, f32 *, 8) = 0.25f;
            return;
        case 12:
            temp_r3_552 = this + (arg0 * 0x58);
            M2C_FIELD(temp_r3_552, f32 *, 4) = 0.25f;
            M2C_FIELD(temp_r3_552, f32 *, 8) = 0.25f;
            return;
        case 11:
            temp_r3_559 = this + (arg0 * 0x58);
            M2C_FIELD(temp_r3_559, f32 *, 4) = 0.25f;
            M2C_FIELD(temp_r3_559, f32 *, 8) = 0.25f;
            return;
        }
    }
}

s32 SpyroSoundPlayer::DetermineGameSound(int arg0, int arg1) {
    if ((u32) arg0 <= 0xCU) {
        switch (arg0) {                             /* switch 1 */
        case 0:                                     /* switch 1 */
            return GS_SpyroWaterMoveLP;
        case 2:                                     /* switch 1 */
            return GS_SpyroGlideLP;
        case 3:                                     /* switch 1 */
            return GS_SpyroIceSlide;
        case 4:                                     /* switch 1 */
            return GS_SpyroDeathFall;
        case 5:                                     /* switch 1 */
            switch (arg1) {                         /* switch 2; irregular */
            case 0:                                 /* switch 2 */
                return GS_SpyBreathIceLP;
            case 1:                                 /* switch 2 */
                return GS_SpyBreathIceLP2;
            case 2:                                 /* switch 2 */
                return GS_SpyBreathIceLP3;
            case 3:                                 /* switch 2 */
                return GS_SpyBreathIceLP4;
            }
            break;
        case 6:                                     /* switch 1 */
            switch (arg1) {                         /* switch 3; irregular */
            case 0:                                 /* switch 3 */
                return GS_SpyroBreathIce2LP;
            case 1:                                 /* switch 3 */
                return GS_SpyroBreathIce2LP2;
            case 2:                                 /* switch 3 */
                return GS_SpyroBreathIce2LP3;
            case 3:                                 /* switch 3 */
                return GS_SpyroBreathIce2LP4;
            }
            break;
        case 7:                                     /* switch 1 */
            switch (arg1) {                         /* switch 4; irregular */
            case 0:                                 /* switch 4 */
                return GS_SpyBreathFireLP;
            case 1:                                 /* switch 4 */
                return GS_SpyBreathFireLP2;
            case 2:                                 /* switch 4 */
                return GS_SpyBreathFireLP3;
            case 3:                                 /* switch 4 */
                return GS_SpyBreathFireLP4;
            }
            break;
        case 8:                                     /* switch 1 */
            switch (arg1) {                         /* switch 5; irregular */
            case 0:                                 /* switch 5 */
                return GS_SpyroBrEnergyLP;
            case 1:                                 /* switch 5 */
                return GS_SpyroBrEnergyLP2;
            case 2:                                 /* switch 5 */
                return GS_SpyroBrEnergyLP3;
            case 3:                                 /* switch 5 */
                return GS_SpyroBrEnergyLP4;
            }
            break;
        case 1:                                     /* switch 1 */
            switch (arg1) {                         /* switch 6; irregular */
            case 0:                                 /* switch 6 */
                return GS_SpyroFuryRageFireLP;
            case 2:                                 /* switch 6 */
                return GS_SpyroFuryRageIceLP;
            case 3:                                 /* switch 6 */
                return GS_SpyroFuryRageEarthLP;
            case 9:                                 /* switch 1 */
            default:                                /* switch 6 */
                return GS_SpyroBrEnergyRandom;
            }
            break;
        case 10:                                    /* switch 1 */
            return GS_SpyroBreathCharge1;
        case 12:                                    /* switch 1 */
            return GS_SpyroBreathEarthChargeLP;
        case 11:                                    /* switch 1 */
            return GS_StaticLP;
        }
    } else {
        return GS_PLACEHOLDER;
    }
}

u8 SpyroSoundPlayer::SoundIsFadingOut(int arg0) {
    return M2C_FIELD((this + (arg0 * 0x58)), s32 *, 0x28) == 1;
}

u8 SpyroSoundPlayer::SoundIsFadingIn(int arg0) {
    return M2C_FIELD((this + (arg0 * 0x58)), s32 *, 0x28) == 0;
}

u8 SpyroSoundPlayer::SoundIsPlaying(int arg0) {
    u8 var_r31_732;

    var_r31_732 = 0;
    if ((SoundIsFadingIn(arg0) != 0) || (SoundIsFadingOut(arg0) != 0)) {
        var_r31_732 = 1;
    }
    return var_r31_732;
}

#if 0 // DRAFT: function call 'KDSound_Stop(long *)' does not match
void SpyroSoundPlayer::StopAll() {
    SpyroSoundPlayer *temp_r3_764;
    s32 var_r29_760;
    s32 var_r31_761;

    var_r29_760 = 0;
    var_r31_761 = 0;
    do {
        temp_r3_764 = &this[var_r31_761];
        M2C_FIELD(temp_r3_764, s32 *, 0x28) = 2;
        KDSound_Stop((s32 *) temp_r3_764);
        var_r29_760 += 1;
        var_r31_761 += 0x58;
    } while (var_r29_760 < 0xD);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'SpyroSoundPlayer *' to
void SpyroSoundPlayer::Stop(int arg0) {
    s32 *temp_r3_792;

    if (arg0 >= 0) {
        if (arg0 >= 0xD) {
            return;
        }
        temp_r3_792 = this + (arg0 * 0x58);
        M2C_FIELD(temp_r3_792, s32 *, 0x28) = 2;
        KDSound_Stop(temp_r3_792);
    }
}
#endif

void SpyroSoundPlayer::FadeOut(int arg0) {
    if (arg0 >= 0) {
        if (arg0 >= 0xD) {
            return;
        }
        M2C_FIELD((this + (arg0 * 0x58)), s32 *, 0x28) = 1;
    }
}

#if 0 // DRAFT: expression syntax error
void SpyroSoundPlayer::FadeIn(int arg0, int arg1) {
    s32 temp_r0_846;
    s32 temp_r31_832;
    s32 temp_r3_844;
    s32 var_r5_0;
    u8 var_r6_834;
    void *temp_r3_848;

    var_r5_0 = arg1;
    if (arg0 >= 0) {
        if (arg0 >= 0xD) {
            return;
        }
        temp_r31_832 = arg0 * 0x58;
        var_r6_834 = 0;
        M2C_FIELD((this + temp_r31_832), s32 *, 0x28) = 0;
        if (var_r5_0 != -1) {

        } else {
            temp_r3_844 = GameData::gameData.unk158 << 5;
            temp_r0_846 = *(&GameData::gameData.unk70 + (temp_r3_844 + 0x7C));
            temp_r3_848 = &GameData::gameData.unk70 + (temp_r3_844 + 0x64);
            if (temp_r0_846 == 3) {
                if (((s32) M2C_FIELD(temp_r3_848, s32 *, 0) == 3) && ((s32) M2C_FIELD(temp_r3_848, s32 *, 4) == 3)) {
                    var_r6_834 = 1;
                }
                var_r5_0 = var_r6_834 != 0;
            } else {
                var_r5_0 = *(temp_r3_848 + (temp_r0_846 * 4));
            }
        }
        M2C_FIELD((this + temp_r31_832), s32 *, 0x2C) = DetermineGameSound(arg0, var_r5_0);
    }
}
#endif

void SpyroSoundPlayer::Update() {
    s32 var_r30_887;
    s32 var_r31_888;

    var_r30_887 = 0;
    var_r31_888 = 0;
    do {
        if (SoundIsPlaying(var_r30_887) != 0) {
            if ((u8) M2C_FIELD(&this[var_r31_888], u8 *, 0x35) != 0) {
                UpdatePitch(var_r30_887);
            }
            PlaySounds(var_r30_887, SoundIsFadingIn(var_r30_887));
        }
        var_r30_887 += 1;
        var_r31_888 += 0x58;
    } while (var_r30_887 < 0xD);
}

void SpyroSoundPlayer::Message(MKMessage *arg0) {
    s32 var_r30_937;
    s32 var_r31_938;

    if ((s32) arg0->unk0 != -4) {
        return;
    }
    var_r30_937 = 0;
    var_r31_938 = 0;
    do {
        ((KDSoundPlayer *) ((KDSoundPlayer *) &this[var_r31_938]))->Message(arg0);
        var_r30_937 += 1;
        var_r31_938 += 0x58;
    } while (var_r30_937 < 0xD);
}

#if 0 // DRAFT: function call 'KDSound_Stop(long *)' does not match
void SpyroSoundPlayer::Deinit() {
    s32 var_r30_963;
    s32 var_r31_964;

    var_r30_963 = 0;
    var_r31_964 = 0;
    do {
        KDSound_Stop((s32 *) &this[var_r31_964]);
        var_r30_963 += 1;
        var_r31_964 += 0x58;
    } while (var_r30_963 < 0xD);
}
#endif

#if 0 // DRAFT: function call 'Init(SpyroSoundPlayer *, float, float)' does not match
void SpyroSoundPlayer::Init() {
    SpyroSoundPlayer *temp_r30_1001;
    f64 temp_f30_993;
    f64 temp_f31_996;
    s32 var_r29_997;
    s32 var_r31_998;

    temp_f30_993 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    temp_f31_996 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
    var_r29_997 = 0;
    var_r31_998 = 0;
    do {
        temp_r30_1001 = &this[var_r31_998];
        temp_r30_1001->Init(0.75f, 0.75f);
        M2C_FIELD(temp_r30_1001, s32 *, 0x2C) = DetermineGameSound(var_r29_997, 0);
        M2C_FIELD(temp_r30_1001, s32 *, 0x30) = -1;
        M2C_FIELD(temp_r30_1001, s32 *, 0x28) = 2;
        M2C_FIELD(temp_r30_1001, s8 *, 0x34) = Determine3DSound(var_r29_997);
        DetermineFadeTimes(var_r29_997);
        var_r29_997 += 1;
        M2C_FIELD(temp_r30_1001, s8 *, 0x35) = 0;
        var_r31_998 += 0x58;
        M2C_FIELD(temp_r30_1001, f32 *, 0x40) = 0.0f;
        M2C_FIELD(temp_r30_1001, f64 *, 0x48) = temp_f30_993;
        M2C_FIELD(temp_r30_1001, f64 *, 0x50) = temp_f31_996;
    } while (var_r29_997 < 0xD);
}
#endif

void SpyroUtils_cpp::__sinit() {
    f32 temp_f0_1078;
    f64 temp_f1_1059;
    f64 temp_f1_1067;
    f64 temp_f3_1047;
    f64 temp_f4_1056;
    f64 temp_f4_1064;
    f64 temp_f8_1049;

    temp_f3_1047 = __frsqrte(2014000.0);
    temp_f8_1049 = __frsqrte(380000.0);
    temp_f4_1056 = 0.5 * temp_f3_1047 * -((2014000.0 * (temp_f3_1047 * temp_f3_1047)) - 3.0);
    temp_f1_1059 = 0.5 * temp_f8_1049 * -((380000.0 * (temp_f8_1049 * temp_f8_1049)) - 3.0);
    temp_f4_1064 = 0.5 * temp_f4_1056 * -((2014000.0 * (temp_f4_1056 * temp_f4_1056)) - 3.0);
    temp_f1_1067 = 0.5 * temp_f1_1059 * -((380000.0 * (temp_f1_1059 * temp_f1_1059)) - 3.0);
    temp_f0_1078 = (f32) (380000.0 * (0.5 * temp_f1_1067 * -((380000.0 * (temp_f1_1067 * temp_f1_1067)) - 3.0)));
    SPYRO_BOUNCE_Y_SPEED = (f32) (2014000.0 * (0.5 * temp_f4_1064 * -((2014000.0 * (temp_f4_1064 * temp_f4_1064)) - 3.0)));
    SPYRO_MIN_JUMP_Y_VELOCITY = temp_f0_1078;
}
