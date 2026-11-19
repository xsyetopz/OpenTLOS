#include "spyro/source/SpeedWaySpyro.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "spyro/source/Character.h"
#include "spyro/source/FireBombFX.h"
#include "spyro/source/Game.h"
#include "spyro/source/GameData.h"
#include "spyro/source/GameMessages.h"
#include "spyro/source/KDInput.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/ScreenWobbleFX.h"
#include "spyro/source/SpeedWay.h"
#include "spyro/source/SpeedwayCynder.h"
#include "spyro/source/Spyro.h"
#include "spyro/source/TargetManager.h"
#include "unplaced_templates.h"
#include "common/Source/MKInput.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKSystem.h"
#include "common/Source/Str.h"
#include "common/gc/MKModel_GC.h"
#include "spyro/source/ConnectingProps.h"
#include "spyro/source/EventCamera.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/Music.h"
#include "spyro/source/PhrasePlayer.h"
#include "spyro/source/Tools.h"
#include <m2c_macros.h>

s32 stricmp(void *);                                /* extern */
extern s32 GS_SpyroDeathFall;
extern s32 GS_SpyroLavaBurn;
extern s32 GS_SpyroSWFireballLaunch;
extern s32 GS_SpyroSpeedwayFlinch;
extern s32 GS_SpyroSpeedwayGlideLP;
extern f32 SPYRO_BOUNCE_Y_SPEED;
extern f32 SPYRO_MIN_JUMP_Y_VELOCITY;
extern u8 bUsePulledBackCamera;
extern s8 gAssertBool;
extern void **gMK;
extern f32 gUpdateTimeDelta;
extern f32 g_invPathMaxDistance;
extern f32 g_pathMaxDistance;
#if 0 // DRAFT: identifier 'gb' redeclared
extern void **gb;
#endif
#if 0 // DRAFT: illegal use of abstract class ('SpeedWaySpyro::pure_slot13()')
static M2C_UNK lit_818;                                /* unable to generate initializer: unknown type */
static SpeedWaySpyro states__13SpeedWaySpyro;       /* type too large by 0x78C; unable to generate initializer: confusing struct layout */

static M2C_UNK lit_869;                                /* unable to generate initializer: unknown type; const */

void SpeedwayFX::Deinit() {

}
#endif

#if 0 // DRAFT: function call 'checked_cast(void *)' does not match
u8 SpeedwayFX::ShootFireBomb(const MKVector3 &arg0, const MKVector3 &arg1, const MKVector3 &arg2) {
    FireBombFX *temp_r3_263;

    temp_r3_263 = checked_cast<FireBombFX *, MKProp>(this->unk0->CreateInstance());
    if (temp_r3_263 == NULL) {
        return 0U;
    }
    M2C_FIELD(temp_r3_263->__vptr, M2C_UNK (**)(), 0x30)();
    temp_r3_263->Fire(arg0, arg1, 1.0f, M2C_FIELD(*gb, MKProp *(**)(void **), 0xC)(gb), 1U, 0U, 1, arg2);
    KDSound_Play3d(GS_SpyroSWFireballLaunch, &arg0, 0U, -1, 0.0f, 0U);
    ((KDInput *) (M2C_FIELD(*gb, KDInput *(**)(void **), 0x40)(gb)))->RumblePlay(0.0f, 0.4f, 0.04f, 0, 4.0f, 0U);
    return 1U;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'long' to
u8 SpeedwayFX::Update(const Matrix *arg0, bool arg1) {
    f64 sp138;
    f64 sp130;
    f64 sp128;
    f64 sp120;
    f64 sp118;                                      /* compiler-managed */
    f64 sp110;                                      /* compiler-managed */
    f32 sp108;                                      /* compiler-managed */
    f64 sp100;
    f64 spF8;
    f64 spF0;
    f64 spE8;
    f64 spE0;
    f64 spD0;
    f64 spC8;
    f64 spC0;
    f64 spB8;
    f64 spB0;
    f64 spA8;
    f64 spA0;
    MKVector3 sp90;
    MKVector3 sp80;
    f64 sp78;
    f64 sp70;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp58;
    f32 sp48;
    f32 sp38;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f32 sp8;
    TargetManager ***var_r30_382;
    TargetManager **temp_r27_549;
    TargetManager **var_r31_372;
    f32 temp_f4_523;
    f32 temp_f5_524;
    f32 temp_f6_521;
    f32 var_f0_445;
    f32 var_f30_370;
    f32 var_f5_512;
    f64 temp_f2_451;
    f64 temp_f2_457;
    f64 temp_f2_461;
    s32 temp_r3_480;
    s32 var_r0_490;
    s32 var_r3_350;
    u8 var_r3_336;
    void *temp_r3_420;

    if (arg1 != 0) {
        var_r3_336 = 0;
        if (((u8) M2C_FIELD(M2C_FIELD(&gb, void **, 0x354), u8 *, 5) != 0) || ((u8) M2C_FIELD(M2C_FIELD(&gb, void **, 0x354), u8 *, 4) != 0)) {
            var_r3_336 = 1;
        }
        if (var_r3_336 != 0) {
            var_r3_350 = 0;
        } else {
            var_r3_350 = MKInput_Pressed(0xC, (MKInputDevices) M2C_FIELD(M2C_FIELD(&gb, void **, 0x354), s32 *, 0));
        }
        if ((u8) var_r3_350 != 0) {
            sp60 = -arg0->unk20;
            var_f30_370 = 3.4028235e38f;
            sp64 = -arg0->unk24;
            var_r31_372 = NULL;
            sp68 = -arg0->unk28;
            sp130 = M2C_FIELD(arg0, f64 *, 0x30);
            sp138 = M2C_FIELD(arg0, f64 *, 0x38);
            sp120 = (f64) sp60;
            sp128 = (f64) sp68;
            var_r30_382 = ((TargetManager *) (M2C_FIELD(&gb, TargetManager **, 0x20)))->Begin();
loop_38:
            if (var_r30_382 != NULL) {
                temp_r27_549 = *var_r30_382;
                if (temp_r27_549 != NULL) {
                    if (((*temp_r27_549)->unk8.unk0(temp_r27_549) != NULL) && (M2C_FIELD(*temp_r27_549, u8 (**)(TargetManager **), 0x18)(temp_r27_549) != 0) && ((((u32 (*)(TargetManager **)) (*temp_r27_549)->unk8.unk4)(temp_r27_549) == 0U) || (((Character *) (((Character *(*)(TargetManager **)) (*temp_r27_549)->unk8.unk4)(temp_r27_549)))->IsActive() != 0))) {
                        temp_r3_420 = M2C_FIELD((*temp_r27_549)->unk8.unk0(temp_r27_549), void **, 8);
                        spE0 = M2C_FIELD(temp_r3_420, f64 *, 0x30);
                        spE8 = M2C_FIELD(temp_r3_420, f64 *, 0x38);
                        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
                        sp110 = sp50;
                        sp58 = (f32) spE8 - (f32) sp138;
                        sp118 = (f64) sp58;
                        var_f0_445 = ((f32) sp118 * (f32) sp118) + (((f32) sp110 * (f32) sp110) + (unksp114 * unksp114));
                        if (var_f0_445 > 0.000001f) {
                            if (var_f0_445 > 0.0f) {
                                temp_f2_451 = __frsqrte(var_f0_445);
                                temp_f2_457 = 0.5 * temp_f2_451 * -(((f64) var_f0_445 * (temp_f2_451 * temp_f2_451)) - 3.0);
                                temp_f2_461 = 0.5 * temp_f2_457 * -(((f64) var_f0_445 * (temp_f2_457 * temp_f2_457)) - 3.0);
                                var_f0_445 = (f32) ((f64) var_f0_445 * (0.5 * temp_f2_461 * -(((f64) var_f0_445 * (temp_f2_461 * temp_f2_461)) - 3.0)));
                            } else if (var_f0_445 < M2C_BITWISE(f32, 0.0)) {
                                var_f0_445 = __float_nan;
                            } else {
                                sp8 = var_f0_445;
                                temp_r3_480 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                                switch (temp_r3_480) { /* irregular */
                                case 0x7F800000:
                                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                        var_r0_490 = 1;
                                    } else {
                                        var_r0_490 = 2;
                                    }
                                    break;
                                case 0x0:
                                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                        var_r0_490 = 5;
                                    } else {
                                        var_r0_490 = 3;
                                    }
                                    break;
                                default:
                                    var_r0_490 = 4;
                                    break;
                                }
                                if (var_r0_490 == 1) {
                                    var_f0_445 = __float_nan;
                                }
                            }
                            var_f5_512 = 1.0f / var_f0_445;
                        } else {
                            var_f5_512 = 0.0f;
                            var_f0_445 = 0.0f;
                        }
                        temp_f6_521 = (f32) sp110 * var_f5_512;
                        temp_f4_523 = unksp114 * var_f5_512;
                        temp_f5_524 = (f32) sp118 * var_f5_512;
                        sp110 = temp_f6_521;
                        unksp114 = temp_f4_523;
                        sp118 = temp_f5_524;
                        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
                        if ((var_f0_445 == 30000.0f) && (var_f0_445 < var_f30_370) && (((temp_f5_524 * (f32) sp128) + ((temp_f6_521 * (f32) sp120) + (temp_f4_523 * unksp124))) > 0.85f)) {
                            var_f30_370 = var_f0_445;
                            var_r31_372 = temp_r27_549;
                        }
                    }
                    var_r30_382 += 4;
                    goto loop_38;
                }
            }
            if (var_r31_372 != NULL) {
                M2C_FIELD(*var_r31_372, M2C_UNK (**)(TargetManager **, f64 *, f64 *), 0x2C)(var_r31_372, &sp130, &sp100);
                M2C_FIELD(*var_r31_372, M2C_UNK (**)(f64 *, TargetManager **), 0x30)(&spD0, var_r31_372);
                spF0 = spD0;
                spF8 = spD8;
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
                spC0 = sp40;
                sp48 = (f32) spF8 * 60.0f;
                spC8 = (f64) sp48;
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                sp108 += (f32) spC8;
            } else {
                sp20 = -arg0->unk10;
                sp24 = -arg0->unk14;
                sp28 = -arg0->unk18;
                sp70 = (f64) sp20;
                sp78 = (f64) sp28;
                sp80.operator*(10000.0f);
                sp90.operator*(20000.0f);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                spA0 = sp10;
                sp18 = (f32) sp138 + sp90.unk8;
                spA8 = (f64) sp18;
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                spB0 = sp30;
                sp100 = sp30;
                sp38 = (f32) spA8 + sp80.unk8;
                spB8 = (f64) sp38;
                sp108 = (f64) sp38;
            }
            return ShootFireBomb(*((MKVector3 *) &sp130), *((MKVector3 *) &sp120), *((MKVector3 *) &sp100));
        }
        goto block_44;
    }
block_44:
    return 0U;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'const char[17]' to
void SpeedwayFX::Resolve() {
    this->unk0 = checked_cast<FireBombFXDescriptor *, MKPropDescriptor>(M2C_FIELD(*gMK, MKPropDescriptor *(**)(void **, void *), 0x5C)(gMK, "SpeedwayFirebomb"));
}
#endif

#if 0 // DRAFT: expression syntax error
void SpeedwayFX::Init() {
    FireBombFX *temp_r3_702;
    s32 var_r30_696;

    var_r30_696 = 0;
    this->unk0 = NULL;
    do {
        temp_r3_702 = checked_cast<FireBombFX *, MKProp>(gMK->CreateProp("SpeedwayFirebomb"));
        if (temp_r3_702 != NULL) {
            M2C_FIELD(temp_r3_702->__vptr, M2C_UNK (**)(), 0x34)();
        }
        var_r30_696 += 1;
    } while (var_r30_696 < 8);
}
#endif

u8 SpeedWaySpyro::UsePulledBackCamera() {
    return bUsePulledBackCamera;
}

s32 SpeedWaySpyro::IsDead() {
    M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
    return ((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1DU) & 1;
}

#if 0 // DRAFT: expression syntax error
void SpeedWaySpyro::UpdateSound() {
    s32 sp8;
    f32 *temp_r31_755;
    f32 temp_f1_776;
    f32 temp_f1_781;
    f32 temp_f30_784;
    f32 temp_f30_798;
    f32 temp_f31_779;
    f32 temp_f31_797;
    f32 temp_f5_788;
    void *temp_r3_775;
    void *temp_r3_780;
    void *temp_r3_785;

    sp8 = 1;
    temp_r31_755 = &this->unk1A0.unk30;
    this->unk888.Update(GS_SpyroDeathFall, 1U, this->unk8B0, NULL, (MKVector3 *) temp_r31_755, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    this->unk818.Update(GS_SpyroSpeedwayGlideLP, 1U, this->unk8B1, NULL, (MKVector3 *) temp_r31_755, 0U, -1);
    temp_r3_775 = checked_cast<SpeedWaySpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    temp_f1_776 = M2C_FIELD(temp_r3_775, f32 *, 0xA8);
    temp_f31_779 = -((temp_f1_776 * M2C_FIELD(temp_r3_775, f32 *, 0x160)) - temp_f1_776);
    temp_r3_780 = checked_cast<SpeedWaySpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    temp_f1_781 = M2C_FIELD(temp_r3_780, f32 *, 0x118);
    temp_f30_784 = (temp_f1_781 * M2C_FIELD(temp_r3_780, f32 *, 0x160)) + temp_f1_781;
    temp_r3_785 = checked_cast<SpeedWaySpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    temp_f5_788 = M2C_FIELD(temp_r3_785, f32 *, 0xA8);
    temp_f31_797 = (this->unk140 - -((temp_f5_788 * M2C_FIELD(temp_r3_785, f32 *, 0x160)) - temp_f5_788)) * (1.0f / (temp_f30_784 - temp_f31_779));
    temp_f30_798 = 0.5f * temp_f31_797;
    KDSound_SetVolume(this->unk818, (0.5f * this->unk8B4) + temp_f30_798);
    KDSound_SetVolume(this->unk840, (0.5f * this->unk8B4) + temp_f30_798);
    KDSound_SetPitch(this->unk818, (0.3f * temp_f31_797) + 0.8f);
    KDSound_Play3d(this->unk80, this->unk8 + 0x30, 0U, 0.0f, 0U);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'GameGlobals *' to
void SpeedWaySpyro::UpdateEffects() {
    f32 temp_f0_899;
    f32 temp_f1_894;
    f32 temp_f31_930;
    f32 var_f2_898;
    u8 var_r30_926;
    void ***temp_r30_844;
    temp_r30_844 = &gb + 0xB8;
    temp_r30_844->SetSpeedEffectCenter(*((MKVector3 *) &this->unk1A0.unk30));
    if ((this->unk98 & 0x10) && ((s32) this->unkA0 == 2)) {
        temp_r30_844->EnableSpeedEffect(1U, 0.0f, 0.5f);
    } else {
        temp_r30_844->EnableSpeedEffect(0U, 0.0f, 1.0f);
    }
    MKModel_CalculateRefPointWorldPosition(this->unk4, M2C_FIELD(checked_cast<SpeedWaySpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x190), (MKVector3 *) &arg_sp10);
    M2C_STRUCT_COPY((s32) &arg_sp1C + 4, (s32) (this->unk8 - 4) + 4, 0x40);
    arg_sp50 = arg_sp10;
    arg_sp54 = arg_sp14;
    arg_sp58 = arg_sp18;
    arg_sp5C = 1.0f;
    temp_f1_894 = this->unk304;
    if (temp_f1_894 != 0.0f) {
        var_f2_898 = 0.0f;
        temp_f0_899 = temp_f1_894 - gUpdateTimeDelta;
        if (var_f2_898 > temp_f0_899) {

        } else {
            var_f2_898 = temp_f0_899;
        }
        this->unk304 = var_f2_898;
    }
    if ((this->unk304 == 0.0f) && (gameData.unkA0.unk0 < gameData.unkA0.unk4)) {
        gameData.unkA0.Add(15.0f * gUpdateTimeDelta, 1U);
    }
    var_r30_926 = 0;
    temp_f31_930 = gameData.unkA0.unk0;
    if ((temp_f31_930 > gameData.unk70.GetInitialBreathCost()) && (this->unk98 & 0x10)) {
        var_r30_926 = 1;
    }
    this->unk300 = this->unk2FC.Update((Matrix *) &arg_sp20, var_r30_926);
    if ((u8) this->unk300 != 0) {
        ((Stat *) ((Stat *) (&gameData.unk70 + 0x30)))->Add(-gameData.unk70.GetInitialBreathCost(), 1U);
        this->unk304 = 1.0f;
    }
}
#endif

void SpeedWaySpyro::SetColObjEnabled(bool arg0) {
    if (arg0 != (u8) this->unk814) {
        this->unk814 = arg0;
        if (arg0 != 0) {
            SetMatrix(this->unk1A0, 1U);
        }
    }
}

#if 0 // DRAFT: undefined identifier 'zero'
void SpeedWaySpyro::Teleport(float arg0, bool arg1) {
    this->unk328 = M2C_FIELD(&zero, f64 *, 0);
    this->unk330 = M2C_FIELD(&zero, f64 *, 8);
    this->unk318 = this->unk328;
    this->unk320 = this->unk330;
    this->unk308 = this->unk318;
    this->unk310 = this->unk320;
    this->unk360 = M2C_FIELD(&zero, f64 *, 0);
    this->unk368 = M2C_FIELD(&zero, f64 *, 8);
    this->unk350 = this->unk360;
    this->unk358 = this->unk368;
    this->unk340 = this->unk350;
    this->unk348 = this->unk358;
    this->unk2C0 = arg0;
    UpdateCameraAndSpyro(arg0, 1U, arg1);
    M2C_STRUCT_COPY((s32) &this->unk21C + 4, (s32) &this->unk1A0.unk3C + 4, 0x40);
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_sp4C'
void SpeedWaySpyro::SetMatrix(const Matrix &arg0, bool arg1) {
    f32 temp_f2_1099;
    f32 var_f0_1111;
    void *temp_r3_1083;
    M2C_STRUCT_COPY((s32) &arg_sp4C + 4, (s32) (&arg0 - 4) + 4, 0x40);
    if ((u8) this->unk814 != 0) {
        if (arg1 != 0) {
            if (M2C_FIELD(M2C_FIELD(this, void **, 0x398), u8 (**)(M2C_UNK *, f32 *, M2C_UNK, f32), 0x14)(&this->unk398, &arg_sp80, 0xA, 1.0f) != 0) {
                this->unk810 = 0.0f;
            }
        } else {
            temp_r3_1083 = this->unk8;
            arg_sp30 = M2C_FIELD(temp_r3_1083, f64 *, 0x30);
            arg_sp38 = M2C_FIELD(temp_r3_1083, f64 *, 0x38);
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
            temp_f2_1099 = arg_sp88 - (f32) arg_sp38;
            arg_sp40 = arg_sp10;
            arg_sp18 = temp_f2_1099;
            arg_sp48 = (f64) arg_sp18;
            if (M2C_FIELD(M2C_FIELD(this, void **, 0x398), s32 (**)(M2C_UNK *, f64 *, M2C_UNK, f32, f32), 0x10)(&this->unk398, &arg_sp40, 0, 0.0f, temp_f2_1099) == 8) {
                var_f0_1111 = 0.0f;
            } else {
                var_f0_1111 = this->unk810 + gUpdateTimeDelta;
            }
            this->unk810 = var_f0_1111;
        }
        M2C_FIELD(M2C_FIELD(this, void **, 0x398), M2C_UNK (**)(f32 *, M2C_UNK *), 0x4C)(&arg_sp20, &this->unk398);
        arg_sp80 = arg_sp20;
        arg_sp84 = arg_sp24;
        arg_sp88 = arg_sp28;
        arg_sp8C = 1.0f;
    } else {
        this->unk810 = 0.0f;
    }
    MKModel_SetWorldMatrix(this->unk4, *((Matrix *) &arg_sp50));
}
#endif

#if 0 // DRAFT: undefined identifier 'gameData'
void SpeedWaySpyro::Hurt(HurtMessage *arg0) {
    if (DealDamage(-arg0->unk48) != 0) {
        arg0->unk50 = 1;
        if (gameData.unk70 > 0.0f) {
            this->unk180.SetState(this, 5, 1U);
            return;
        }
        this->unk180.SetState(this, 7, 1U);
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'gameData'
u8 SpeedWaySpyro::DealDamage(float arg0) {
    if (((u8) M2C_FIELD(&gb, u8 *, 0x3B4) != 0) || (M2C_ERROR(/* unknown instruction: cror eq, gt, eq */), (((((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1DU) & 1) == 0) != 0)) || !(this->unk98 & 0x20) || (M2C_ERROR(/* unknown instruction: cror eq, lt, eq */), ((gameData.unk70 == 0.0f) != 0))) {
        return 0U;
    }
    gameData.unk70.Add(arg0, 1U);
    this->unk2F8 = M2C_FIELD(&gb, f32 *, 0x30C) + M2C_FIELD(checked_cast<SpeedWaySpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x18C);
    this->unk2EC = M2C_FIELD(&gb, f32 *, 0x30C);
    return 1U;
}
#endif

void SpeedWaySpyro::SetStageIndex(int arg0) {
    this->unk2F4 = arg0;
}

void SpeedWaySpyro::SetAnim(MKAnim *arg0, float arg1, unsigned int arg2) {
    this->unk80->SetAnim(arg0, 1.0f, arg1, (s32) arg2, -1);
}

void *SpeedWaySpyro::GetCamera() {
    return M2C_FIELD(&gb, void **, 0x3B8);
}

KDInput *SpeedWaySpyro::GetInput() {
    return M2C_FIELD(&gb, KDInput **, 0x354);
}

#if 0 // DRAFT: undefined identifier 'gameData'
void SpeedWaySpyro::GetJoyDir() {
    f32 sp10;
    f32 spC;
    f32 sp8;
    KDInput *temp_r3_1310;
    KDInput *temp_r3_1334;
    SpeedWaySpyro *temp_r31_1299;
    f32 var_f1_1323;
    f32 var_f1_1347;
    f32 var_f31_1304;
    u8 var_r4_1312;
    u8 var_r4_1336;

    temp_r31_1299 = M2C_ERROR(/* Read from unset register $r4 */);
    gameData.GetGameSettings();
    if ((u8) M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), u8 *, 0x13) != 0) {
        var_f31_1304 = -1.0f;
    } else {
        var_f31_1304 = 1.0f;
    }
    temp_r3_1310 = temp_r31_1299->GetInput();
    var_r4_1312 = 0;
    if (((u8) temp_r3_1310->unk5 != 0) || ((u8) temp_r3_1310->unk4 != 0)) {
        var_r4_1312 = 1;
    }
    if (var_r4_1312 != 0) {
        var_f1_1323 = 0.0f;
    } else {
        var_f1_1323 = MKInput_GetState(0x10, (MKInputDevices) temp_r3_1310->unk0, NULL, NULL);
    }
    temp_r3_1334 = temp_r31_1299->GetInput();
    var_r4_1336 = 0;
    if (((u8) temp_r3_1334->unk5 != 0) || ((u8) temp_r3_1334->unk4 != 0)) {
        var_r4_1336 = 1;
    }
    if (var_r4_1336 != 0) {
        var_f1_1347 = 0.0f;
    } else {
        var_f1_1347 = MKInput_GetState(0x11, (MKInputDevices) temp_r3_1334->unk0, NULL, NULL);
    }
    spC = var_f1_1323 * var_f31_1304;
    sp8 = -var_f1_1347;
    sp10 = 0.0f;
    M2C_FIELD(this, f64 *, 0) = (f64) sp8;
    M2C_FIELD(this, f64 *, 8) = (f64) sp10;
}
#endif

#if 0 // DRAFT: undefined identifier 'zero'
void SpeedWaySpyro::UpdateDrift(float arg0) {
    MKVector3 sp68;
    MKVector3 sp58;
    f64 sp50;
    f64 sp48;
    MKVector3 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp10;
    f32 temp_f2_1460;
    f32 temp_f2_1496;
    f32 temp_f2_1509;
    f32 temp_f2_1545;
    f32 temp_f30_1478;
    f32 temp_f30_1518;
    f32 temp_f31_1469;
    f32 temp_f31_1527;
    f32 temp_f3_1462;
    f32 temp_f3_1511;
    f32 temp_f5_1465;
    f32 temp_f5_1514;
    f32 var_f1_1498;
    f32 var_f1_1547;
    s32 var_r30_1485;
    s32 var_r30_1534;
    u8 var_r0_1400;
    void *temp_r5_1578;
    void *temp_r5_1603;

    if (this->unk98 & 0x40) {
        this->unk350 = M2C_FIELD(&zero, f64 *, 0);
        this->unk358 = M2C_FIELD(&zero, f64 *, 8);
        if (arg0 != 0.0f) {
            var_r0_1400 = 0;
            if (((f32) M2C_FIELD(&identity, f64 *, 0) == (f32) this->unk220) && ((f32) M2C_FIELD(&identity, f64 *, 8) == (f32) this->unk228) && ((f32) M2C_FIELD(&identity, f64 *, 0x10) == (f32) this->unk230) && ((f32) M2C_FIELD(&identity, f64 *, 0x18) == (f32) this->unk238) && ((f32) M2C_FIELD(&identity, f64 *, 0x20) == (f32) this->unk240) && ((f32) M2C_FIELD(&identity, f64 *, 0x28) == (f32) this->unk248) && ((f32) M2C_FIELD(&identity, f64 *, 0x30) == (f32) this->unk250) && ((f32) M2C_FIELD(&identity, f64 *, 0x38) == (f32) this->unk258)) {
                var_r0_1400 = 1;
            }
            if (var_r0_1400 != 0) {
                goto block_12;
            }
        } else {
block_12:
            this->unk360 = M2C_FIELD(&zero, f64 *, 0);
            this->unk368 = M2C_FIELD(&zero, f64 *, 8);
            this->unk350 = this->unk360;
            this->unk358 = this->unk368;
            this->unk340 = this->unk350;
            this->unk348 = this->unk358;
            M2C_STRUCT_COPY((s32) &this->unk21C + 4, (s32) &this->unk1A0.unk3C + 4, 0x40);
        }
        temp_f2_1460 = this->unk1E4;
        temp_f3_1462 = this->unk1E0;
        temp_f5_1465 = this->unk1E8;
        temp_f31_1469 = (temp_f5_1465 * (f32) M2C_FIELD(this, f64 *, 0x228)) + ((temp_f3_1462 * (f32) M2C_FIELD(this, f64 *, 0x220)) + (temp_f2_1460 * M2C_FIELD(this, f32 *, 0x224)));
        if (temp_f31_1469 < 0.999999f) {
            temp_f30_1478 = (temp_f5_1465 * (f32) M2C_FIELD(this, f64 *, 0x248)) + ((temp_f3_1462 * (f32) M2C_FIELD(this, f64 *, 0x240)) + (temp_f2_1460 * M2C_FIELD(this, f32 *, 0x244)));
            if ((s32) M2C_FIELD(checked_cast<SpeedWaySpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x15C) > 0) {
                var_r30_1485 = M2C_FIELD(checked_cast<SpeedWaySpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x15C);
            } else {
                var_r30_1485 = this->unk2F4;
            }
            temp_f2_1496 = M2C_FIELD((checked_cast<SpeedWaySpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + (var_r30_1485 * 0x38)), f32 *, 0x7C);
            if (temp_f30_1478 > 0.0f) {
                var_f1_1498 = -1.0f;
            } else {
                var_f1_1498 = 1.0f;
            }
            M2C_FIELD(this, f64 *, 0x350) = (f32) (var_f1_1498 * ((1.0f - temp_f31_1469) * temp_f2_1496));
        }
        temp_f2_1509 = this->unk1F4;
        temp_f3_1511 = this->unk1F0;
        temp_f5_1514 = this->unk1F8;
        temp_f30_1518 = (temp_f5_1514 * (f32) M2C_FIELD(this, f64 *, 0x238)) + ((temp_f3_1511 * (f32) M2C_FIELD(this, f64 *, 0x230)) + (temp_f2_1509 * M2C_FIELD(this, f32 *, 0x234)));
        if (temp_f30_1518 < 0.999999f) {
            temp_f31_1527 = (temp_f5_1514 * (f32) M2C_FIELD(this, f64 *, 0x248)) + ((temp_f3_1511 * (f32) M2C_FIELD(this, f64 *, 0x240)) + (temp_f2_1509 * M2C_FIELD(this, f32 *, 0x244)));
            if ((s32) M2C_FIELD(checked_cast<SpeedWaySpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x15C) > 0) {
                var_r30_1534 = M2C_FIELD(checked_cast<SpeedWaySpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x15C);
            } else {
                var_r30_1534 = this->unk2F4;
            }
            temp_f2_1545 = M2C_FIELD((checked_cast<SpeedWaySpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + (var_r30_1534 * 0x38)), f32 *, 0x80);
            if (temp_f31_1527 > 0.0f) {
                var_f1_1547 = -1.0f;
            } else {
                var_f1_1547 = 1.0f;
            }
            M2C_FIELD(this, f32 *, 0x354) = (f32) (var_f1_1547 * ((1.0f - temp_f30_1518) * temp_f2_1545));
        }
        KDMath_CriticalDamp<MKVector3>(sp68, *((MKVector3 *) &this->unk340), *((MKVector3 *) &this->unk350), GetCurrXYDriftFactor(), gUpdateTimeDelta);
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        M2C_ERROR(/* unknown instruction: psq_stx $f0, $r31, $r0, 0x0, qr0 */);
        M2C_FIELD(this, f64 *, 0x348) = (f32) ((f32) M2C_FIELD(this, f64 *, 0x348) + sp68.unk8);
        temp_r5_1578 = checked_cast<SpeedWaySpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $r31, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        sp48 = sp18;
        sp20 = M2C_FIELD(this, f32 *, 0x320) + (f32) M2C_FIELD(this, f64 *, 0x348);
        sp50 = (f64) sp20;
        ClampMagnitude(sp58, M2C_FIELD(temp_r5_1578, f32 *, 0x164));
        this->unk318 = M2C_BITWISE(f64, sp58);
        this->unk320 = (f64) sp58.unk8;
        temp_r5_1603 = checked_cast<SpeedWaySpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $r31, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        sp28 = sp8;
        sp10 = M2C_FIELD(this, f32 *, 0x310) + (f32) M2C_FIELD(this, f64 *, 0x348);
        sp30 = (f64) sp10;
        ClampMagnitude(sp38, M2C_FIELD(temp_r5_1603, f32 *, 0x164));
        this->unk308 = M2C_BITWISE(f64, sp38);
        this->unk310 = (f64) sp38.unk8;
    }
}
#endif

#if 0 // DRAFT: ')' expected
u8 SpeedWaySpyro::GetBestMovementOffset(const MKVector3 &arg0, const MKVector3 &arg1, const MKVector3 &arg2, float *arg3) {
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
    f32 sp58;
    f32 sp48;
    f32 sp38;
    f32 sp28;
    f32 sp18;
    f32 spC;
    f32 sp8;
    f32 temp_f1_1779;
    f32 temp_f1_1805;
    f32 temp_f1_1927;
    f32 temp_f30_1922;
    f32 temp_f31_1920;
    f32 var_f30_1851;
    f64 temp_f1_1854;
    f64 temp_f1_1860;
    f64 temp_f1_1864;
    s32 temp_r3_1883;
    s32 var_r0_1893;

    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r30, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
    temp_f1_1779 = arg2.unk8 * M2C_FIELD(checked_cast<SpeedWaySpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x164);
    sp80 = sp50;
    sp58 = temp_f1_1779;
    sp88 = (f64) sp58;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r29, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    spA0 = sp40;
    sp48 = arg1.unk8 - (f32) sp88;
    spA8 = (f64) sp48;
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r30, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
    temp_f1_1805 = arg2.unk8 * M2C_FIELD(checked_cast<SpeedWaySpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x164);
    sp70 = sp30;
    sp38 = temp_f1_1805;
    sp78 = (f64) sp38;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r29, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    sp90 = sp20;
    sp28 = arg1.unk8 + (f32) sp78;
    sp98 = (f64) sp28;
    if (Tools_GetPointDistanceFromLine(arg0, *((MKVector3 *) &spA0), *((MKVector3 *) &sp90), &spC) != 0) {
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r28, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
        sp60 = sp10;
        sp18 = arg0.unk8 - (f32) spA8;
        sp68 = (f64) sp18;
        var_f30_1851 = (((f32) sp68 * (f32) sp68) + (((f32) sp60 * (f32) sp60) + (unksp64 * unksp64))) - (spC * spC);
        if (var_f30_1851 > 0.0f) {
            temp_f1_1854 = __frsqrte(var_f30_1851);
            temp_f1_1860 = 0.5 * temp_f1_1854 * -(((f64) var_f30_1851 * (temp_f1_1854 * temp_f1_1854)) - 3.0);
            temp_f1_1864 = 0.5 * temp_f1_1860 * -(((f64) var_f30_1851 * (temp_f1_1860 * temp_f1_1860)) - 3.0);
            var_f30_1851 = (f32) ((f64) var_f30_1851 * (0.5 * temp_f1_1864 * -(((f64) var_f30_1851 * (temp_f1_1864 * temp_f1_1864)) - 3.0)));
        } else if (var_f30_1851 < M2C_BITWISE(f32, 0.0)) {
            var_f30_1851 = __float_nan;
        } else {
            sp8 = var_f30_1851;
            temp_r3_1883 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r3_1883) {                 /* irregular */
            case 0x7F800000:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_1893 = 1;
                } else {
                    var_r0_1893 = 2;
                }
                break;
            case 0x0:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_1893 = 5;
                } else {
                    var_r0_1893 = 3;
                }
                break;
            default:
                var_r0_1893 = 4;
                break;
            }
            if (var_r0_1893 == 1) {
                var_f30_1851 = __float_nan;
            }
        }
        temp_f31_1920 = var_f30_1851 / (2.0f * M2C_FIELD(checked_cast<SpeedWaySpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x164));
        temp_f30_1922 = M2C_FIELD(checked_cast<SpeedWaySpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x164);
        temp_f1_1927 = -M2C_FIELD(checked_cast<SpeedWaySpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x164);
        *arg3 = (temp_f31_1920 * (temp_f30_1922 - temp_f1_1927)) + temp_f1_1927;
        return 1U;
    }
    return 0U;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk21C'
void SpeedWaySpyro::UpdateCameraAndSpyro(float arg0, bool arg1, bool arg2) {
    f32 *temp_r29_2092;
    f32 temp_f1_2296;
    f32 temp_f1_2315;
    f32 temp_f1_2409;
    f32 temp_f3_2349;
    f32 temp_f3_2377;
    f32 var_f1_2017;
    f32 var_f30_2200;
    f32 var_f3_2267;
    f64 temp_f1_2206;
    f64 temp_f1_2212;
    f64 temp_f1_2216;
    s32 temp_r3_2235;
    s32 var_r0_2245;
    u8 var_r5_2134;
    void *temp_r7_2151;
    void *temp_r7_2168;
    M2C_STRUCT_COPY((s32) &this->unk21C + 4, (s32) &this->unk1A0.unk3C + 4, 0x40);
    arg_sp390.GetPathMatrix(arg0);
    M2C_STRUCT_COPY((s32) &arg_sp44C + 4, (s32) &arg_sp38C + 4, 0x40);
    this->unk1E0.CopyRotation((Matrix *) &arg_sp450);
    arg_sp2C0.operator*(M2C_FIELD(checked_cast<SpeedWaySpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x188));
    if ((u8) bUsePulledBackCamera != 0) {
        var_f1_2017 = 3000.0f;
    } else {
        var_f1_2017 = GetCurrCameraZ();
    }
    arg_sp2D0.operator*(var_f1_2017);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r31, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    arg_sp2E0 = arg_sp50;
    arg_sp58 = arg_sp488 - arg_sp2D8;
    arg_sp2E8 = (f64) arg_sp58;
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    arg_sp2F0 = arg_spA0;
    arg_spA8 = (f32) arg_sp2E8 - arg_sp2C8;
    this->unk210 = (f32) arg_sp2F0;
    arg_sp2F8 = (f64) arg_spA8;
    this->unk214 = arg_sp2F4;
    this->unk218 = (f32) arg_sp2F8;
    M2C_FIELD(this, f32 *, 0x21C) = 1.0f;
    if (arg1 == 0) {
        UpdateDrift(arg0);
    }
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
    arg_sp380 = arg_sp180;
    arg_sp188 = arg_sp458 * M2C_FIELD(this, f32 *, 0x308);
    arg_sp388 = (f64) arg_sp188;
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r30, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
    arg_sp370 = arg_sp170;
    arg_sp178 = arg_sp468 * M2C_FIELD(this, f32 *, 0x30C);
    arg_sp378 = (f64) arg_sp178;
    this->unk1A0.CopyRotation((Matrix *) &arg_sp450);
    temp_r29_2092 = &this->unk210;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r29, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    arg_sp2A0 = arg_sp40;
    arg_sp48 = this->unk218 + (f32) arg_sp388;
    arg_sp2A8 = (f64) arg_sp48;
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    arg_sp2B0 = arg_sp90;
    arg_sp98 = (f32) arg_sp2A8 + (f32) arg_sp378;
    this->unk1A0.unk30 = (f32) arg_sp2B0;
    arg_sp2B8 = (f64) arg_sp98;
    this->unk1A0.unk34 = arg_sp2B4;
    this->unk1A0.unk38 = (f32) arg_sp2B8;
    this->unk1A0.unk3C = 1.0f;
    if ((this->unk98 & 8) || (arg1 != 0)) {
        var_r5_2134 = 0;
        if ((arg1 != 0) || (arg0 == 0.0f)) {
            var_r5_2134 = 1;
        }
        SetMatrix(this->unk1A0, var_r5_2134);
    }
    if ((this->unk98 & 4) && (this->unk810 > 0.0f)) {
        temp_r7_2151 = this->unk8;
        arg_sp290 = M2C_FIELD(temp_r7_2151, f64 *, 0x30);
        arg_sp298 = M2C_FIELD(temp_r7_2151, f64 *, 0x38);
        if (GetBestMovementOffset(*((MKVector3 *) &arg_sp290), *((MKVector3 *) temp_r29_2092), *((MKVector3 *) &this->unk1E0), &arg_sp18) != 0) {
            M2C_FIELD(this, f32 *, 0x318) = arg_sp18;
            M2C_FIELD(this, f32 *, 0x308) = arg_sp18;
        }
        temp_r7_2168 = this->unk8;
        arg_sp280 = M2C_FIELD(temp_r7_2168, f64 *, 0x30);
        arg_sp288 = M2C_FIELD(temp_r7_2168, f64 *, 0x38);
        if (GetBestMovementOffset(*((MKVector3 *) &arg_sp280), *((MKVector3 *) temp_r29_2092), *((MKVector3 *) &this->unk1F0), &arg_sp14) != 0) {
            M2C_FIELD(this, f32 *, 0x31C) = arg_sp14;
            M2C_FIELD(this, f32 *, 0x30C) = arg_sp14;
        }
    }
    if (EventCamera_GetCurrent() == NULL) {
        arg_sp360 = this->unk308;
        arg_sp368 = this->unk310;
        var_f30_2200 = ((f32) arg_sp368 * (f32) arg_sp368) + (((f32) arg_sp360 * (f32) arg_sp360) + (arg_sp364 * arg_sp364));
        if (var_f30_2200 > 0.000001f) {
            if (var_f30_2200 > 0.0f) {
                temp_f1_2206 = __frsqrte(var_f30_2200);
                temp_f1_2212 = 0.5 * temp_f1_2206 * -(((f64) var_f30_2200 * (temp_f1_2206 * temp_f1_2206)) - 3.0);
                temp_f1_2216 = 0.5 * temp_f1_2212 * -(((f64) var_f30_2200 * (temp_f1_2212 * temp_f1_2212)) - 3.0);
                var_f30_2200 = (f32) ((f64) var_f30_2200 * (0.5 * temp_f1_2216 * -(((f64) var_f30_2200 * (temp_f1_2216 * temp_f1_2216)) - 3.0)));
            } else if (var_f30_2200 < M2C_BITWISE(f32, 0.0)) {
                var_f30_2200 = __float_nan;
            } else {
                arg_sp10 = var_f30_2200;
                temp_r3_2235 = M2C_BITWISE(s32, arg_sp10) & 0x7F800000;
                switch (temp_r3_2235) {             /* irregular */
                case 0x7F800000:
                    if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                        var_r0_2245 = 1;
                    } else {
                        var_r0_2245 = 2;
                    }
                    break;
                case 0x0:
                    if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                        var_r0_2245 = 5;
                    } else {
                        var_r0_2245 = 3;
                    }
                    break;
                default:
                    var_r0_2245 = 4;
                    break;
                }
                if (var_r0_2245 == 1) {
                    var_f30_2200 = __float_nan;
                }
            }
            var_f3_2267 = 1.0f / var_f30_2200;
        } else {
            var_f3_2267 = 0.0f;
            var_f30_2200 = 0.0f;
        }
        arg_sp360 = (f32) arg_sp360 * var_f3_2267;
        arg_sp364 *= var_f3_2267;
        arg_sp368 = (f32) arg_sp368 * var_f3_2267;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
        temp_f1_2296 = arg_sp458 * ((f32) arg_sp360 * (var_f30_2200 / M2C_FIELD(checked_cast<SpeedWaySpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x164)) * this->unk164);
        arg_sp350 = arg_sp160;
        arg_sp168 = temp_f1_2296;
        arg_sp358 = (f64) arg_sp168;
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r30, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f28 */);
        temp_f1_2315 = arg_sp468 * (arg_sp364 * (var_f30_2200 / M2C_FIELD(checked_cast<SpeedWaySpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x164)) * this->unk16C);
        arg_sp340 = arg_sp150;
        arg_sp158 = temp_f1_2315;
        arg_sp348 = (f64) arg_sp158;
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r31, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        arg_sp270 = arg_sp140;
        arg_sp148 = arg_sp488 + (f32) arg_sp358;
        arg_sp278 = (f64) arg_sp148;
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        arg_sp330 = arg_sp130;
        arg_sp138 = (f32) arg_sp278 + (f32) arg_sp348;
        arg_sp338 = (f64) arg_sp138;
        temp_f3_2349 = M2C_FIELD(this, f32 *, 0x308) / M2C_FIELD(checked_cast<SpeedWaySpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x164);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f24 */);
        arg_sp260 = arg_sp120;
        arg_sp128 = arg_sp458 * this->unk154;
        arg_sp268 = (f64) arg_sp128;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f27 */);
        arg_sp320 = arg_sp110;
        arg_sp118 = (f32) arg_sp268 * temp_f3_2349;
        arg_sp328 = (f64) arg_sp118;
        temp_f3_2377 = M2C_FIELD(this, f32 *, 0x30C) / M2C_FIELD(checked_cast<SpeedWaySpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x164);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r30, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f23 */);
        arg_sp250 = arg_sp100;
        arg_sp108 = arg_sp468 * this->unk15C;
        arg_sp258 = (f64) arg_sp108;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f26 */);
        arg_sp310 = arg_spF0;
        arg_spF8 = (f32) arg_sp258 * temp_f3_2377;
        arg_sp318 = (f64) arg_spF8;
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r30, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f25 */);
        temp_f1_2409 = arg_sp468 * M2C_FIELD(checked_cast<SpeedWaySpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x188);
        arg_sp220 = arg_spE0;
        arg_spE8 = temp_f1_2409;
        arg_sp228 = (f64) arg_spE8;
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r29, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        arg_sp230 = arg_spD0;
        arg_spD8 = this->unk218 + (f32) arg_sp228;
        arg_sp238 = (f64) arg_spD8;
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        arg_sp240 = arg_spC0;
        arg_spC8 = (f32) arg_sp238 + (f32) arg_sp328;
        arg_sp248 = (f64) arg_spC8;
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        arg_sp300 = arg_spB0;
        arg_spB8 = (f32) arg_sp248 + (f32) arg_sp318;
        arg_sp308 = (f64) arg_spB8;
        M2C_STRUCT_COPY((s32) &arg_sp40C + 4, (s32) &arg_sp44C + 4, 0x40);
        arg_sp440 = (f32) arg_sp330;
        arg_sp444 = arg_sp334;
        arg_sp448 = (f32) arg_sp338;
        arg_sp44C = 1.0f;
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
        arg_sp200 = arg_sp80;
        arg_sp88 = (f32) arg_sp308 - (f32) arg_sp338;
        arg_sp208 = (f64) arg_sp88;
        Normalise(*((MKVector3 *) &arg_sp210));
        arg_sp430 = arg_sp210;
        arg_sp434 = arg_sp214;
        arg_sp30 = (arg_sp214 * arg_sp428) - (arg_sp218 * arg_sp424);
        arg_sp34 = (arg_sp218 * arg_sp420) - (arg_sp210 * arg_sp428);
        arg_sp38 = (arg_sp210 * arg_sp424) - (arg_sp214 * arg_sp420);
        arg_sp1E0 = (f64) arg_sp30;
        arg_sp1E8 = (f64) arg_sp38;
        arg_sp438 = arg_sp218;
        arg_sp70 = -(f32) arg_sp1E0;
        arg_sp74 = -arg_sp1E4;
        arg_sp78 = -(f32) arg_sp1E8;
        arg_sp1F0 = (f64) arg_sp70;
        arg_sp1F8 = (f64) arg_sp78;
        arg_sp43C = 0.0f;
        arg_sp410 = (f32) arg_sp1F0;
        arg_sp414 = arg_sp1F4;
        arg_sp28 = ((f32) arg_sp1F0 * arg_sp214) - (arg_sp1F4 * arg_sp210);
        arg_sp20 = (arg_sp1F4 * arg_sp218) - ((f32) arg_sp1F8 * arg_sp214);
        arg_sp24 = ((f32) arg_sp1F8 * arg_sp210) - ((f32) arg_sp1F0 * arg_sp218);
        arg_sp1C8 = (f64) arg_sp28;
        arg_sp1C0 = (f64) arg_sp20;
        arg_sp418 = (f32) arg_sp1F8;
        arg_sp68 = -(f32) arg_sp1C8;
        arg_sp60 = -(f32) arg_sp1C0;
        arg_sp64 = -arg_sp1C4;
        arg_sp1D8 = (f64) arg_sp68;
        arg_sp1D0 = (f64) arg_sp60;
        arg_sp41C = 0.0f;
        arg_sp420 = (f32) arg_sp1D0;
        arg_sp424 = arg_sp1D4;
        arg_sp428 = (f32) arg_sp1D8;
        arg_sp42C = 0.0f;
        if (arg2 != 0) {
            M2C_STRUCT_COPY((s32) &arg_sp3CC + 4, (s32) &arg_sp40C + 4, 0x40);
            this->unk260 = arg_sp3D0;
            this->unk268 = arg_sp3D8;
            memset(&this->unk270, 0, 0x10U);
            this->unk280 = arg_sp3E0;
            this->unk288 = arg_sp3E8;
            memset(&this->unk290, 0, 0x10U);
            this->unk2A0 = arg_sp3F0;
            this->unk2A8 = arg_sp3F8;
            memset(&this->unk2B0, 0, 0x10U);
        } else {
            arg_sp1B0.Update(*((MKVector3 *) &this->unk260), M2C_FIELD(checked_cast<SpeedWaySpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x158));
            arg_sp3D0 = arg_sp1B0;
            arg_sp3D4 = arg_sp1B4;
            arg_sp3D8 = arg_sp1B8;
            arg_sp3DC = 0.0f;
            arg_sp1A0.Update(*((MKVector3 *) &this->unk280), M2C_FIELD(checked_cast<SpeedWaySpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x158));
            arg_sp3E0 = arg_sp1A0;
            arg_sp3E4 = arg_sp1A4;
            arg_sp3E8 = arg_sp1A8;
            arg_sp3EC = 0.0f;
            arg_sp190.Update(*((MKVector3 *) &this->unk2A0), M2C_FIELD(checked_cast<SpeedWaySpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x158));
            arg_sp3FC = 0.0f;
            arg_sp40C = 1.0f;
            arg_sp3F0 = arg_sp190;
            arg_sp3F4 = arg_sp194;
            arg_sp3F8 = arg_sp198;
            arg_sp400 = arg_sp440;
            arg_sp404 = arg_sp444;
            arg_sp408 = arg_sp448;
            arg_sp3FC = 0.0f;
            arg_sp3EC = 0.0f;
            arg_sp3DC = 0.0f;
            arg_sp40C = 1.0f;
        }
        arg_sp494 = 0;
        arg_sp490.Init(*((Matrix *) &arg_sp3D0));
        M2C_FIELD(M2C_FIELD(GetCamera(), void **, 0x44), M2C_UNK (**)(M2C_UNK *), 0x2C)(&arg_sp490);
        arg_sp4E4 = 0;
        arg_sp4E0.ClearData();
        arg_sp4E0.Init(&this->unk1A0);
        arg_sp588 = this;
        M2C_FIELD(M2C_FIELD(GetCamera(), void **, 0x44), M2C_UNK (**)(M2C_UNK *), 0x2C)(&arg_sp4E0);
    }
}
#endif

#if 0 // DRAFT: ')' expected
void SpeedWaySpyro::SetTargetMovementOffset(const MKVector3 &arg0) {
    MKVector3 sp8;

    ClampMagnitude(sp8, M2C_FIELD(checked_cast<SpeedWaySpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x164));
    this->unk318 = M2C_BITWISE(f64, sp8);
    this->unk320 = (f64) sp8.unk8;
}
#endif

void SpeedWaySpyro::UpdateMovementOffset() {
    MKVector3 sp8;

    if (this->unk98 & 2) {
        KDMath_CriticalDamp<MKVector3>(sp8, *((MKVector3 *) &this->unk308), *((MKVector3 *) &this->unk318), this->unk338, gUpdateTimeDelta);
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        M2C_ERROR(/* unknown instruction: psq_stx $f0, $r31, $r0, 0x0, qr0 */);
        M2C_FIELD(this, f32 *, 0x310) = (f32) (M2C_FIELD(this, f32 *, 0x310) + sp8.unk8);
    }
}

void SpeedWaySpyro::UpdateSplineTime() {
    f32 temp_f1_2830;

    if (this->unk98 & 1) {
        temp_f1_2830 = (this->unk2C0 * g_pathMaxDistance) + (gUpdateTimeDelta * this->unk140);
        if (temp_f1_2830 > g_pathMaxDistance) {
            Start();
            return;
        }
        this->unk2C0 = temp_f1_2830 * g_invPathMaxDistance;
    }
}

#if 0 // DRAFT: ')' expected
void SpeedWaySpyro::UpdateStageInfo() {
    f32 sp10;
    s32 spC;
    s32 sp8;
    KDInput *temp_r3_2883;
    KDInput *temp_r3_2919;
    KDInput *temp_r3_2966;
    KDInput *temp_r3_3035;
    f32 temp_f0_3009;
    f32 temp_f0_3079;
    f32 temp_f0_3124;
    f32 temp_f1_3123;
    f32 temp_f1_3152;
    f32 temp_f30_2957;
    f32 temp_f30_3120;
    f32 temp_f31_2877;
    f32 temp_f5_3103;
    f32 temp_f5_3188;
    f32 temp_f5_3204;
    f32 temp_f5_3221;
    f32 temp_f5_3238;
    f32 temp_f5_3255;
    f32 temp_f6_3101;
    f32 temp_f6_3185;
    f32 temp_f6_3202;
    f32 temp_f6_3219;
    f32 temp_f6_3236;
    f32 temp_f6_3253;
    f32 temp_f6_3274;
    f32 temp_f7_3270;
    f32 var_f1_2896;
    f32 var_f1_2932;
    f32 var_f1_2979;
    f32 var_f1_3048;
    f32 var_f29_3125;
    f32 var_f2_3008;
    f32 var_f2_3078;
    s32 var_r29_3142;
    s32 var_r29_3168;
    s32 var_r31_2867;
    u8 var_r4_2885;
    u8 var_r4_2921;
    u8 var_r4_2968;
    u8 var_r4_3037;
    void *temp_r31_2876;

    if ((s32) M2C_FIELD(checked_cast<SpeedWaySpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x15C) > 0) {
        var_r31_2867 = M2C_FIELD(checked_cast<SpeedWaySpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x15C);
    } else {
        var_r31_2867 = this->unk2F4;
    }
    temp_r31_2876 = checked_cast<SpeedWaySpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + ((var_r31_2867 * 0x38) + 0x70);
    temp_f31_2877 = M2C_FIELD(temp_r31_2876, f32 *, 0);
    this->unk148 = temp_f31_2877;
    if ((u8) this->unkA4 == 0) {
        temp_r3_2883 = GetInput();
        var_r4_2885 = 0;
        if (((u8) temp_r3_2883->unk5 != 0) || ((u8) temp_r3_2883->unk4 != 0)) {
            var_r4_2885 = 1;
        }
        if (var_r4_2885 != 0) {
            var_f1_2896 = 0.0f;
        } else {
            var_f1_2896 = MKInput_GetState(0xB, (MKInputDevices) temp_r3_2883->unk0, NULL, NULL);
        }
        this->unkA4 = (u8) (var_f1_2896 != 0.0f) == 0;
    }
    if ((u8) this->unkA5 == 0) {
        temp_r3_2919 = GetInput();
        var_r4_2921 = 0;
        if (((u8) temp_r3_2919->unk5 != 0) || ((u8) temp_r3_2919->unk4 != 0)) {
            var_r4_2921 = 1;
        }
        if (var_r4_2921 != 0) {
            var_f1_2932 = 0.0f;
        } else {
            var_f1_2932 = MKInput_GetState(0xA, (MKInputDevices) temp_r3_2919->unk0, NULL, NULL);
        }
        this->unkA5 = (u8) (var_f1_2932 != 0.0f) == 0;
    }
    temp_f30_2957 = gameData.unk70.GetSpeedwayBoostCost();
    if ((this->unk98 & 0x80) && (gameData.unkA0.unk0 > 0.0f)) {
        temp_r3_2966 = GetInput();
        var_r4_2968 = 0;
        if (((u8) temp_r3_2966->unk5 != 0) || ((u8) temp_r3_2966->unk4 != 0)) {
            var_r4_2968 = 1;
        }
        if (var_r4_2968 != 0) {
            var_f1_2979 = 0.0f;
        } else {
            var_f1_2979 = MKInput_GetState(0xB, (MKInputDevices) temp_r3_2966->unk0, NULL, NULL);
        }
        if ((var_f1_2979 != 0.0f) && ((u8) this->unkA4 != 0)) {
            this->unkA0 = 2;
            this->unk148 += temp_f31_2877 * M2C_FIELD(checked_cast<SpeedWaySpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x160);
            ((Stat *) ((Stat *) (&gameData.unk70 + 0x30)))->Add(-temp_f30_2957, 1U);
            var_f2_3008 = this->unk304;
            temp_f0_3009 = 2.0f * gUpdateTimeDelta;
            if (var_f2_3008 > temp_f0_3009) {

            } else {
                var_f2_3008 = temp_f0_3009;
            }
            this->unk304 = var_f2_3008;
            M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
            if (gameData.unkA0.unk0 == 0.0f) {
                this->unkA4 = 0;
            }
        } else {
            goto block_34;
        }
    } else {
block_34:
        if ((this->unk98 & 0x80) && (gameData.unkA0.unk0 > 0.0f)) {
            temp_r3_3035 = GetInput();
            var_r4_3037 = 0;
            if (((u8) temp_r3_3035->unk5 != 0) || ((u8) temp_r3_3035->unk4 != 0)) {
                var_r4_3037 = 1;
            }
            if (var_r4_3037 != 0) {
                var_f1_3048 = 0.0f;
            } else {
                var_f1_3048 = MKInput_GetState(0xA, (MKInputDevices) temp_r3_3035->unk0, NULL, NULL);
            }
            if ((var_f1_3048 != 0.0f) && ((u8) this->unkA5 != 0)) {
                this->unkA0 = 0;
                this->unk148 += -temp_f31_2877 * M2C_FIELD(checked_cast<SpeedWaySpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x160);
                ((Stat *) ((Stat *) (&gameData.unk70 + 0x30)))->Add(-temp_f30_2957, 1U);
                var_f2_3078 = this->unk304;
                temp_f0_3079 = 2.0f * gUpdateTimeDelta;
                if (var_f2_3078 > temp_f0_3079) {

                } else {
                    var_f2_3078 = temp_f0_3079;
                }
                this->unk304 = var_f2_3078;
                M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
                if (gameData.unkA0.unk0 == 0.0f) {
                    this->unkA5 = 0;
                }
            } else {
                goto block_49;
            }
        } else {
block_49:
            this->unkA0 = 1;
        }
    }
    temp_f6_3101 = this->unk144;
    temp_f5_3103 = M2C_FIELD(checked_cast<SpeedWaySpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x150);
    this->unk140 += (gUpdateTimeDelta * (((this->unk148 - this->unk140) * (temp_f5_3103 * temp_f5_3103)) - (2.0f * temp_f6_3101 * temp_f5_3103))) + temp_f6_3101;
    temp_f30_3120 = -((temp_f31_2877 * M2C_FIELD(checked_cast<SpeedWaySpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x160)) - temp_f31_2877);
    temp_f1_3123 = this->unk148;
    temp_f0_3124 = (temp_f31_2877 * M2C_FIELD(checked_cast<SpeedWaySpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x160)) + temp_f31_2877;
    var_f29_3125 = 0.0f;
    if (temp_f1_3123 == temp_f31_2877) {

    } else if (temp_f1_3123 < temp_f31_2877) {
        if ((s32) M2C_FIELD(checked_cast<SpeedWaySpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x15C) > 0) {
            var_r29_3142 = M2C_FIELD(checked_cast<SpeedWaySpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x15C);
        } else {
            var_r29_3142 = this->unk2F4;
        }
        temp_f1_3152 = M2C_FIELD((checked_cast<SpeedWaySpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + (var_r29_3142 * 0x38)), f32 *, 0x90);
        var_f29_3125 = (((temp_f1_3123 - temp_f30_3120) / (temp_f31_2877 - temp_f30_3120)) * (0.0f - temp_f1_3152)) + temp_f1_3152;
    } else if (temp_f1_3123 > temp_f31_2877) {
        if ((s32) M2C_FIELD(checked_cast<SpeedWaySpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x15C) > 0) {
            var_r29_3168 = M2C_FIELD(checked_cast<SpeedWaySpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x15C);
        } else {
            var_r29_3168 = this->unk2F4;
        }
        var_f29_3125 = (((temp_f1_3123 - temp_f31_2877) / (temp_f0_3124 - temp_f31_2877)) * (M2C_FIELD((checked_cast<SpeedWaySpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + (var_r29_3168 * 0x38)), f32 *, 0x8C) - 0.0f)) + 0.0f;
    }
    temp_f6_3185 = this->unk150;
    temp_f5_3188 = M2C_FIELD(checked_cast<SpeedWaySpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x154);
    this->unk14C += (gUpdateTimeDelta * ((((M2C_FIELD(temp_r31_2876, f32 *, 0x18) + var_f29_3125) - this->unk14C) * (temp_f5_3188 * temp_f5_3188)) - (2.0f * temp_f6_3185 * temp_f5_3188))) + temp_f6_3185;
    temp_f6_3202 = this->unk158;
    temp_f5_3204 = M2C_FIELD(checked_cast<SpeedWaySpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x154);
    this->unk154 += (gUpdateTimeDelta * (((M2C_FIELD(temp_r31_2876, f32 *, 0x24) - this->unk154) * (temp_f5_3204 * temp_f5_3204)) - (2.0f * temp_f6_3202 * temp_f5_3204))) + temp_f6_3202;
    temp_f6_3219 = this->unk160;
    temp_f5_3221 = M2C_FIELD(checked_cast<SpeedWaySpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x154);
    this->unk15C += (gUpdateTimeDelta * (((M2C_FIELD(temp_r31_2876, f32 *, 0x28) - this->unk15C) * (temp_f5_3221 * temp_f5_3221)) - (2.0f * temp_f6_3219 * temp_f5_3221))) + temp_f6_3219;
    temp_f6_3236 = this->unk168;
    temp_f5_3238 = M2C_FIELD(checked_cast<SpeedWaySpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x154);
    this->unk164 += (gUpdateTimeDelta * (((M2C_FIELD(temp_r31_2876, f32 *, 0x2C) - this->unk164) * (temp_f5_3238 * temp_f5_3238)) - (2.0f * temp_f6_3236 * temp_f5_3238))) + temp_f6_3236;
    temp_f6_3253 = this->unk170;
    temp_f5_3255 = M2C_FIELD(checked_cast<SpeedWaySpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x154);
    this->unk16C += (gUpdateTimeDelta * (((M2C_FIELD(temp_r31_2876, f32 *, 0x30) - this->unk16C) * (temp_f5_3255 * temp_f5_3255)) - (2.0f * temp_f6_3253 * temp_f5_3255))) + temp_f6_3253;
    temp_f7_3270 = this->unk178;
    temp_f6_3274 = M2C_FIELD(checked_cast<SpeedWaySpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x154);
    this->unk174 += (gUpdateTimeDelta * (((M2C_FIELD(temp_r31_2876, f32 *, 0x34) - this->unk174) * (temp_f6_3274 * temp_f6_3274)) - (2.0f * temp_f7_3270 * temp_f6_3274))) + temp_f7_3270;
    spC = 0;
    sp8 = 0x458;
    sp10 = 0.017453292f * this->unk174;
    M2C_FIELD(M2C_FIELD(GetCamera(), void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp8);
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'long' to
u8 SpeedWaySpyro::AnyToPowerRollTransition() {
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    KDInput *temp_r3_3323;
    KDInput *temp_r3_3347;
    KDInput *temp_r3_3397;
    KDInput *temp_r3_3420;
    f32 var_f1_3360;
    f32 var_f1_3433;
    f32 var_f31_3336;
    f32 var_f31_3396;
    s32 var_r3_3410;
    u8 var_r29_3372;
    u8 var_r30_3370;
    u8 var_r4_3325;
    u8 var_r4_3349;
    u8 var_r4_3399;
    u8 var_r4_3422;

    temp_r3_3323 = GetInput();
    var_r4_3325 = 0;
    if (((u8) temp_r3_3323->unk5 != 0) || ((u8) temp_r3_3323->unk4 != 0)) {
        var_r4_3325 = 1;
    }
    if (var_r4_3325 != 0) {
        var_f31_3336 = 0.0f;
    } else {
        var_f31_3336 = MKInput_GetState(0x10, (MKInputDevices) temp_r3_3323->unk0, NULL, NULL);
    }
    temp_r3_3347 = GetInput();
    var_r4_3349 = 0;
    if (((u8) temp_r3_3347->unk5 != 0) || ((u8) temp_r3_3347->unk4 != 0)) {
        var_r4_3349 = 1;
    }
    if (var_r4_3349 != 0) {
        var_f1_3360 = 0.0f;
    } else {
        var_f1_3360 = MKInput_GetState(0x11, (MKInputDevices) temp_r3_3347->unk0, NULL, NULL);
    }
    var_r30_3370 = 0;
    var_r29_3372 = 0;
    sp8 = var_f1_3360;
    spC = var_f31_3336;
    sp18 = 1.0f;
    sp28 = (f64) sp8;
    sp1C = 0.0f;
    sp10 = 0.0f;
    sp38 = (f64) sp18;
    sp20 = 0.0f;
    sp30 = (f64) sp10;
    sp40 = (f64) sp20;
    var_f31_3396 = ((f32) sp40 * (f32) sp30) + (((f32) sp38 * (f32) sp28) + (unksp3C * unksp2C));
    temp_r3_3397 = GetInput();
    var_r4_3399 = 0;
    if (((u8) temp_r3_3397->unk5 != 0) || ((u8) temp_r3_3397->unk4 != 0)) {
        var_r4_3399 = 1;
    }
    if (var_r4_3399 != 0) {
        var_r3_3410 = 0;
    } else {
        var_r3_3410 = MKInput_Pressed(0xE, (MKInputDevices) temp_r3_3397->unk0);
    }
    if ((u8) var_r3_3410 != 0) {
        temp_r3_3420 = GetInput();
        var_r4_3422 = 0;
        if (((u8) temp_r3_3420->unk5 != 0) || ((u8) temp_r3_3420->unk4 != 0)) {
            var_r4_3422 = 1;
        }
        if (var_r4_3422 != 0) {
            var_f1_3433 = 0.0f;
        } else {
            var_f1_3433 = MKInput_GetState(0x11, (MKInputDevices) temp_r3_3420->unk0, NULL, NULL);
        }
        if (var_f1_3433 < 0.0f) {
            var_f1_3433 = -var_f1_3433;
        }
        if (var_f1_3433 > 0.4f) {
            var_r29_3372 = 1;
        }
    }
    if (var_r29_3372 != 0) {
        if (var_f31_3396 < 0.0f) {
            var_f31_3396 = -var_f31_3396;
        }
        if (var_f31_3396 > 0.33f) {
            var_r30_3370 = 1;
        }
    }
    if ((var_r30_3370 != 0) && ((s32) this->unk180 != 4)) {
        this->unk180.SetState(this, 4, 0U);
        return 1U;
    }
    return 0U;
}
#endif

#if 0 // DRAFT: undefined identifier '__float_nan'
u8 SpeedWaySpyro::AnyToHitCollisionTransition() {
    f64 sp28;
    f64 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 sp8;
    f32 temp_f0_3544;
    f32 temp_f1_3543;
    f32 temp_f3_3546;
    f32 var_f3_3618;
    f32 var_f4_3551;
    f64 temp_f1_3557;
    f64 temp_f1_3563;
    f64 temp_f1_3567;
    s32 temp_r3_3497;
    s32 temp_r3_3512;
    s32 temp_r3_3527;
    s32 temp_r3_3586;
    s32 var_r0_3596;
    u8 var_r3_3674;
    void *var_r30_3496;
    void *var_r3_3504;
    void *var_r3_3519;
    void *var_r3_3534;

    var_r30_3496 = NULL;
    temp_r3_3497 = this->unk66C;
    if (temp_r3_3497 > 0) {
        if (temp_r3_3497 != 0) {
            var_r3_3504 = this + ((temp_r3_3497 - 1) * 0x58) + 0x508;
        } else {
            var_r3_3504 = NULL;
        }
        var_r30_3496 = var_r3_3504;
    } else {
        temp_r3_3512 = this->unk7D4;
        if (temp_r3_3512 > 0) {
            if (temp_r3_3512 != 0) {
                var_r3_3519 = this + ((temp_r3_3512 - 1) * 0x58) + 0x670;
            } else {
                var_r3_3519 = NULL;
            }
            var_r30_3496 = var_r3_3519;
        } else {
            temp_r3_3527 = this->unk504;
            if (temp_r3_3527 > 0) {
                if (temp_r3_3527 != 0) {
                    var_r3_3534 = this + ((temp_r3_3527 - 1) * 0x58) + 0x3A0;
                } else {
                    var_r3_3534 = NULL;
                }
                var_r30_3496 = var_r3_3534;
            }
        }
    }
    if (var_r30_3496 != NULL) {
        temp_f1_3543 = this->unk2C8;
        temp_f0_3544 = this->unk2CC;
        temp_f3_3546 = this->unk2D0;
        var_f4_3551 = (temp_f3_3546 * temp_f3_3546) + ((temp_f1_3543 * temp_f1_3543) + (temp_f0_3544 * temp_f0_3544));
        if (var_f4_3551 > 1e-12f) {
            if (var_f4_3551 > 0.0f) {
                temp_f1_3557 = __frsqrte(var_f4_3551);
                temp_f1_3563 = 0.5 * temp_f1_3557 * -(((f64) var_f4_3551 * (temp_f1_3557 * temp_f1_3557)) - 3.0);
                temp_f1_3567 = 0.5 * temp_f1_3563 * -(((f64) var_f4_3551 * (temp_f1_3563 * temp_f1_3563)) - 3.0);
                var_f4_3551 = (f32) ((f64) var_f4_3551 * (0.5 * temp_f1_3567 * -(((f64) var_f4_3551 * (temp_f1_3567 * temp_f1_3567)) - 3.0)));
            } else if (var_f4_3551 < M2C_BITWISE(f32, 0.0)) {
                var_f4_3551 = __float_nan;
            } else {
                sp8 = var_f4_3551;
                temp_r3_3586 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                switch (temp_r3_3586) {             /* irregular */
                case 0x7F800000:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_3596 = 1;
                    } else {
                        var_r0_3596 = 2;
                    }
                    break;
                case 0x0:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_3596 = 5;
                    } else {
                        var_r0_3596 = 3;
                    }
                    break;
                default:
                    var_r0_3596 = 4;
                    break;
                }
                if (var_r0_3596 == 1) {
                    var_f4_3551 = __float_nan;
                }
            }
            var_f3_3618 = 1.0f / var_f4_3551;
        } else {
            var_f3_3618 = 0.0f;
        }
        sp10 = this->unk2C8 * var_f3_3618;
        sp14 = this->unk2CC * var_f3_3618;
        sp18 = this->unk2D0 * var_f3_3618;
        sp20 = (f64) sp10;
        sp28 = (f64) sp18;
        if (((((f32) sp28 * M2C_FIELD(var_r30_3496, f32 *, 0x18)) + (((f32) sp20 * M2C_FIELD(var_r30_3496, f32 *, 0x10)) + (unksp24 * M2C_FIELD(var_r30_3496, f32 *, 0x14)))) < -0.9f) && (DealDamage(-5.0f) != 0)) {
            if (M2C_FIELD(var_r30_3496, s32 *, 0x44) & 0x100) {
                KDSound_Play(GS_SpyroLavaBurn, 0U, -1);
                if ((gameData.unk70 == 0.0f) && ((s32) this->unk180 != 7)) {
                    this->unk180.SetState(this, 7, 0U);
                    var_r3_3674 = 1;
                } else {
                    var_r3_3674 = 0;
                }
                if (var_r3_3674 == 0) {
                    if ((gameData.unk70 > 0.0f) && ((s32) this->unk180 != 5)) {
                        this->unk180.SetState(this, 5, 0U);
                        return 1U;
                    }
                    return 0U;
                }
                /* Duplicate return node #61. Try simplifying control flow for better match */
                return var_r3_3674;
            }
            if ((gameData.unk70 == 0.0f) && ((s32) this->unk180 != 7)) {
                this->unk180.SetState(this, 7, 0U);
                var_r3_3674 = 1;
            } else {
                var_r3_3674 = 0;
            }
            if (var_r3_3674 == 0) {
                if ((gameData.unk70 > 0.0f) && ((s32) this->unk180 != 6)) {
                    this->unk180.SetState(this, 6, 0U);
                    return 1U;
                }
                return 0U;
            }
            /* Duplicate return node #61. Try simplifying control flow for better match */
            return var_r3_3674;
        }
        goto block_57;
    }
block_57:
    if ((this->unk810 > 0.5f) && ((s32) this->unk180 != 6)) {
        this->unk180.SetState(this, 6, 0U);
        return 1U;
    }
    var_r3_3674 = 0;
    return var_r3_3674;
}
#endif

void SpeedWaySpyro::EventCameraUpdate() {

}

void SpeedWaySpyro::EventCameraExit() {

}

#if 0 // DRAFT: ')' expected
void SpeedWaySpyro::EventCameraEnter() {
    f32 var_f1_3786;

    StateEnter();
    if ((u8) this->unk2E8 != 0) {
        var_f1_3786 = 0.0f;
    } else {
        var_f1_3786 = M2C_FIELD(checked_cast<SpeedWaySpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x168);
    }
    SetAnim(M2C_FIELD((this + (this->unkA0 * 0x24)), MKAnim **, 0xA8), var_f1_3786, 1U);
    SetTargetMovementOffset(zero);
    this->unk338 = 2.3f;
}
#endif

s32 SpeedWaySpyro::DeathTransition() {
    s32 spC;
    s32 sp8;

    if (this->unk194 > 2.0f) {
        Start();
        spC = 0;
        sp8 = 0x15;
        M2C_FIELD(*gMK, M2C_UNK (**)(void **, s32 *, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, f32), 0x94)(gMK, &sp8, 0, 0, 0, 1, 0.0f);
        return 1;
    }
    return 0;
}

#if 0 // DRAFT: undefined identifier 'sp8'
void SpeedWaySpyro::DeathUpdate() {
    f64 sp60;
    f64 sp58;
    MKVector3 sp48;
    MKVector3 sp38;
    MKVector3 sp28;
    MKVector3 sp18;
    f32 sp10;
    f32 temp_f2_3870;
    f32 temp_f2_3876;
    f32 var_f3_3863;

    var_f3_3863 = 0.5f * (2.0f * gUpdateTimeDelta);
    if (var_f3_3863 < 1.0f) {

    } else {
        var_f3_3863 = 1.0f;
    }
    temp_f2_3870 = this->unk9C;
    temp_f2_3876 = (var_f3_3863 * (0.0f - temp_f2_3870)) + temp_f2_3870;
    this->unk9C = (var_f3_3863 * (0.0f - temp_f2_3876)) + temp_f2_3876;
    sp18.operator*(-980.0f);
    sp28.operator*(gUpdateTimeDelta);
    sp38.operator*(this->unk9C);
    sp48.operator*(gUpdateTimeDelta);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    sp58 = sp8;
    sp10 = sp48.unk8 + sp28.unk8;
    sp60 = (f64) sp10;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    M2C_ERROR(/* unknown instruction: psq_stx $f0, $r31, $r0, 0x0, qr0 */);
    this->unk2E0 += (f32) sp60;
    SetTargetMovementOffset(zero);
    DeathTransition();
}
#endif

#if 0 // DRAFT: undefined identifier 'zero'
void SpeedWaySpyro::DeathExit() {
    if (!(this->unk18 & 0x80000000)) {
        this->unk2D8 = M2C_FIELD(&zero, f64 *, 0);
        M2C_FIELD(this, f64 *, 0x2E0) = (f64) M2C_FIELD(&zero, f64 *, 8);
        this->unk8B0 = 0;
        this->unk8C4 = PhrasePlayer_PlayEvent"WhenSpyroRespawns";
    }
}
#endif

#if 0 // DRAFT: ')' expected
void SpeedWaySpyro::DeathEnter() {
    s32 var_r31_3982;

    StateEnter();
    this->unk98 &= ~0xD4;
    SetColObjEnabled(0U);
    if ((s32) M2C_FIELD(checked_cast<SpeedWaySpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x15C) > 0) {
        var_r31_3982 = M2C_FIELD(checked_cast<SpeedWaySpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x15C);
    } else {
        var_r31_3982 = this->unk2F4;
    }
    this->unk338 = M2C_FIELD((checked_cast<SpeedWaySpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + (var_r31_3982 * 0x38)), f32 *, 0x78);
    this->unk338 = 2.3f;
    ((ScreenWobbleFX *) ((ScreenWobbleFX *) (&gb + 0xB8)))->EnableSpeedEffect(0U, 0.0f, 1.0f);
    SetAnim(this->unk128, 0.2f, 0U);
    this->unk8B0 = 1;
    this->unk9C = -this->unk140;
    this->unk2D8 = M2C_FIELD(&zero, f64 *, 0);
    M2C_FIELD(this, f64 *, 0x2E0) = (f64) M2C_FIELD(&zero, f64 *, 8);
}
#endif

#if 0 // DRAFT: expression syntax error
s32 SpeedWaySpyro::HurtCenterTransition() {
    if ((this->unk308.IsNear(zero, 15.000001f) != 0) && ((s32) this->unk180 != 2)) {
        this->unk180.SetState(this, 2, 0U);
        return 1;
    }
    return 0;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'int' to
void SpeedWaySpyro::HurtCenterUpdate() {
    if (this->unk80->unk2C & 1) {
        SetAnim(this->unkCC, 0.2f, 0U);
    }
    SetTargetMovementOffset(zero);
    HurtCenterTransition();
}
#endif

void SpeedWaySpyro::HurtCenterExit() {

}

#if 0 // DRAFT: expression syntax error
void SpeedWaySpyro::HurtCenterEnter() {
    StateEnter();
    this->unk98 &= 0xFFFFFF3F;
    this->unk338 = 2.3f;
    SetColObjEnabled(0U);
    ((ScreenWobbleFX *) ((ScreenWobbleFX *) (&gb + 0xB8)))->EnableSpeedEffect(0U, 0.0f, 1.0f);
    SetAnim(this->unk124, 0.2f, 0U);
    ((KDInput *) (GetInput()))->RumblePlay(0.03f, 0.3f, 0.05f, 0, 4.0f, 0U);
}
#endif

#if 0 // DRAFT: expression syntax error
s32 SpeedWaySpyro::HurtFlinchTransition() {
    if ((this->unk80->unk2C & 1) && ((s32) this->unk180 != 2)) {
        this->unk180.SetState(this, 2, 0U);
        return 1;
    }
    return 0;
}
#endif

void SpeedWaySpyro::HurtFlinchUpdate() {
    HurtFlinchTransition();
}

#if 0 // DRAFT: ')' expected
void SpeedWaySpyro::HurtFlinchEnter() {
    s32 var_r31_4246;

    StateEnter();
    this->unk98 &= 0xFFFFFFCF;
    PhrasePlayer_GetCurrentActor();
    if (stricmp"SP" != 0) {
        KDSound_Play(GS_SpyroSpeedwayFlinch, 0U, -1);
    }
    if ((s32) M2C_FIELD(checked_cast<SpeedWaySpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x15C) > 0) {
        var_r31_4246 = M2C_FIELD(checked_cast<SpeedWaySpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x15C);
    } else {
        var_r31_4246 = this->unk2F4;
    }
    this->unk338 = M2C_FIELD((checked_cast<SpeedWaySpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + (var_r31_4246 * 0x38)), f32 *, 0x78);
    SetAnim(this->unk124, 0.2f, 0U);
}
#endif

#if 0 // DRAFT: expression syntax error
u8 SpeedWaySpyro::PowerRollTransition() {
    u8 var_r30_4279;
    u8 var_r3_4280;
    u8 var_r3_4284;

    var_r30_4279 = this->unk80->unk2C & 1;
    var_r3_4280 = AnyToHitCollisionTransition();
    if (var_r3_4280 == 0) {
        var_r3_4284 = var_r30_4279;
        if (var_r30_4279 != 0) {
            ((KDInput *) (GetInput()))->GetLeftMag();
            var_r3_4284 = ((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1DU) & 1;
        }
        if ((var_r3_4284 != 0) && ((s32) this->unk180 != 2)) {
            this->unk180.SetState(this, 2, 0U);
            var_r3_4280 = 1;
        } else {
            var_r3_4280 = 0;
        }
    }
    if (var_r3_4280 == 0) {
        if (var_r30_4279 != 0) {
            var_r30_4279 = ((KDInput *) (GetInput()))->GetLeftMag() != 0.0f;
        }
        if ((var_r30_4279 != 0) && ((s32) this->unk180 != 3)) {
            this->unk180.SetState(this, 3, 0U);
            return 1U;
        }
        var_r3_4280 = 0;
        /* Duplicate return node #14. Try simplifying control flow for better match */
        return var_r3_4280;
    }
    return var_r3_4280;
}
#endif

#if 0 // DRAFT: undefined identifier 'sp18'
void SpeedWaySpyro::PowerRollUpdate() {
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp10;

    M2C_ERROR(/* unknown instruction: psq_lx $f0, $r31, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f2 */);
    sp28 = sp18;
    sp20 = this->unk130.unk8 * 3.0f;
    sp30 = (f64) sp20;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    sp38 = sp8;
    sp10 = M2C_FIELD(this, f32 *, 0x320) + (f32) sp30;
    sp40 = (f64) sp10;
    SetTargetMovementOffset(*((MKVector3 *) &sp38));
    PowerRollTransition();
}
#endif

#if 0 // DRAFT: undefined identifier 'zero'
void SpeedWaySpyro::PowerRollExit() {
    this->unk370 = M2C_FIELD(&zero, f64 *, 0);
    this->unk378 = M2C_FIELD(&zero, f64 *, 8);
    this->unk380 = 0.0f;
}
#endif

#if 0 // DRAFT: ')' expected
void SpeedWaySpyro::PowerRollEnter() {
    MKVector3 sp18;
    M2C_UNK sp8;
    MKAnim *var_r4_4432;

    StateEnter();
    this->unk338 = M2C_FIELD(checked_cast<SpeedWaySpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x170);
    this->unk380 = 0.0f;
    sp8.GetJoyDir();
    Normalise(sp18);
    this->unk370 = M2C_BITWISE(f64, sp18);
    this->unk378 = (f64) sp18.unk8;
    if ((f32) M2C_FIELD(this, f64 *, 0x370) > 0.0f) {
        var_r4_4432 = this->unk11C;
    } else {
        var_r4_4432 = this->unk120;
    }
    SetAnim(var_r4_4432, 0.2f, 0U);
}
#endif

#if 0 // DRAFT: expression syntax error
void SpeedWaySpyro::MoveSelectAnim() {
    f64 sp78;
    f64 sp70;
    f32 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 sp8;
    MKAnim *var_r30_4589;
    f32 temp_f1_4583;
    f32 temp_f2_4598;
    f32 temp_f3_4572;
    f32 var_f3_4533;
    f32 var_f4_4466;
    f64 temp_f1_4472;
    f64 temp_f1_4478;
    f64 temp_f1_4482;
    s32 temp_r3_4501;
    s32 var_r0_4511;

    sp60.GetJoyDir();
    var_f4_4466 = (sp68 * sp68) + ((sp60 * sp60) + (sp64 * sp64));
    if (var_f4_4466 > 1e-12f) {
        if (var_f4_4466 > 0.0f) {
            temp_f1_4472 = __frsqrte(var_f4_4466);
            temp_f1_4478 = 0.5 * temp_f1_4472 * -(((f64) var_f4_4466 * (temp_f1_4472 * temp_f1_4472)) - 3.0);
            temp_f1_4482 = 0.5 * temp_f1_4478 * -(((f64) var_f4_4466 * (temp_f1_4478 * temp_f1_4478)) - 3.0);
            var_f4_4466 = (f32) ((f64) var_f4_4466 * (0.5 * temp_f1_4482 * -(((f64) var_f4_4466 * (temp_f1_4482 * temp_f1_4482)) - 3.0)));
        } else if (var_f4_4466 < M2C_BITWISE(f32, 0.0)) {
            var_f4_4466 = __float_nan;
        } else {
            sp8 = var_f4_4466;
            temp_r3_4501 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r3_4501) {                 /* irregular */
            case 0x7F800000:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_4511 = 1;
                } else {
                    var_r0_4511 = 2;
                }
                break;
            case 0x0:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_4511 = 5;
                } else {
                    var_r0_4511 = 3;
                }
                break;
            default:
                var_r0_4511 = 4;
                break;
            }
            if (var_r0_4511 == 1) {
                var_f4_4466 = __float_nan;
            }
        }
        var_f3_4533 = 1.0f / var_f4_4466;
    } else {
        var_f3_4533 = 0.0f;
    }
    sp30 = sp60 * var_f3_4533;
    sp34 = sp64 * var_f3_4533;
    sp20 = 0.0f;
    sp70 = (f64) sp30;
    sp24 = 1.0f;
    sp38 = sp68 * var_f3_4533;
    sp50 = (f64) sp20;
    sp28 = 0.0f;
    sp18 = 0.0f;
    sp78 = (f64) sp38;
    sp58 = (f64) sp28;
    sp48 = (f64) sp18;
    temp_f3_4572 = ((f32) sp78 * (f32) sp58) + (((f32) sp70 * (f32) sp50) + (unksp74 * unksp54));
    sp10 = -1.0f;
    sp14 = 0.0f;
    sp40 = (f64) sp10;
    temp_f1_4583 = ((f32) sp78 * (f32) sp48) + (((f32) sp70 * (f32) sp40) + (unksp74 * unksp44));
    if ((temp_f3_4572 != 0.0f) || (temp_f1_4583 != 0.0f)) {
        var_r30_4589 = NULL;
        if (temp_f3_4572 > 0.91f) {
            var_r30_4589 = M2C_FIELD((this + (this->unkA0 * 0x24)), MKAnim **, 0xB4);
        } else {
            temp_f2_4598 = -0.91f;
            if (temp_f3_4572 < temp_f2_4598) {
                var_r30_4589 = M2C_FIELD((this + (this->unkA0 * 0x24)), MKAnim **, 0xB8);
            } else if (temp_f1_4583 > 0.91f) {
                var_r30_4589 = M2C_FIELD((this + (this->unkA0 * 0x24)), MKAnim **, 0xB0);
            } else if (temp_f1_4583 < temp_f2_4598) {
                var_r30_4589 = M2C_FIELD((this + (this->unkA0 * 0x24)), MKAnim **, 0xAC);
            } else if ((temp_f3_4572 > 0.0f) && (temp_f1_4583 > 0.0f)) {
                var_r30_4589 = M2C_FIELD((this + (this->unkA0 * 0x24)), MKAnim **, 0xC0);
            } else if ((temp_f3_4572 > 0.0f) && (temp_f1_4583 < 0.0f)) {
                var_r30_4589 = M2C_FIELD((this + (this->unkA0 * 0x24)), MKAnim **, 0xBC);
            } else if ((temp_f3_4572 < 0.0f) && (temp_f1_4583 > 0.0f)) {
                var_r30_4589 = M2C_FIELD((this + (this->unkA0 * 0x24)), MKAnim **, 0xC8);
            } else if ((temp_f3_4572 < 0.0f) && (temp_f1_4583 < 0.0f)) {
                var_r30_4589 = M2C_FIELD((this + (this->unkA0 * 0x24)), MKAnim **, 0xC4);
            }
        }
        if ((var_r30_4589 != NULL) && (var_r30_4589 != (u32) this->unk80->unk20)) {
            SetAnim(var_r30_4589, M2C_FIELD(checked_cast<SpeedWaySpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x168), 1U);
        }
    }
}
#endif

#if 0 // DRAFT: expression syntax error
u8 SpeedWaySpyro::MoveTransition() {
    u8 var_r3_4696;

    var_r3_4696 = AnyToHitCollisionTransition();
    if (var_r3_4696 == 0) {
        var_r3_4696 = AnyToPowerRollTransition();
    }
    if (var_r3_4696 == 0) {
        ((KDInput *) (GetInput()))->GetLeftMag();
        if ((((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1DU) & 1) && ((s32) this->unk180 != 2)) {
            this->unk180.SetState(this, 2, 0U);
            return 1U;
        }
        var_r3_4696 = 0;
        /* Duplicate return node #7. Try simplifying control flow for better match */
        return var_r3_4696;
    }
    return var_r3_4696;
}
#endif

#if 0 // DRAFT: ')' expected
void SpeedWaySpyro::MoveUpdate() {
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    M2C_UNK sp28;
    f32 sp20;
    f32 sp10;
    f32 temp_f31_4764;
    s32 var_r0_4753;
    void *temp_r31_4745;

    MoveSelectAnim();
    temp_r31_4745 = checked_cast<SpeedWaySpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    if ((s32) M2C_FIELD(checked_cast<SpeedWaySpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x15C) > 0) {
        var_r0_4753 = M2C_FIELD(checked_cast<SpeedWaySpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x15C);
    } else {
        var_r0_4753 = this->unk2F4;
    }
    temp_f31_4764 = gUpdateTimeDelta * M2C_FIELD((temp_r31_4745 + (var_r0_4753 * 0x38)), f32 *, 0x74);
    sp28.GetJoyDir();
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
    sp38 = sp18;
    sp20 = sp30 * temp_f31_4764;
    sp40 = (f64) sp20;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r30, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    sp48 = sp8;
    sp10 = M2C_FIELD(this, f32 *, 0x320) + (f32) sp40;
    sp50 = (f64) sp10;
    SetTargetMovementOffset(*((MKVector3 *) &sp48));
    MoveTransition();
}
#endif

#if 0 // DRAFT: ')' expected
void SpeedWaySpyro::MoveEnter() {
    s32 var_r31_4820;

    StateEnter();
    if ((s32) M2C_FIELD(checked_cast<SpeedWaySpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x15C) > 0) {
        var_r31_4820 = M2C_FIELD(checked_cast<SpeedWaySpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x15C);
    } else {
        var_r31_4820 = this->unk2F4;
    }
    this->unk338 = M2C_FIELD((checked_cast<SpeedWaySpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + (var_r31_4820 * 0x38)), f32 *, 0x78);
    MoveSelectAnim();
}
#endif

#if 0 // DRAFT: expression syntax error
u8 SpeedWaySpyro::IdleTransition() {
    u8 var_r3_4848;

    var_r3_4848 = AnyToHitCollisionTransition();
    if (var_r3_4848 == 0) {
        var_r3_4848 = AnyToPowerRollTransition();
    }
    if (var_r3_4848 == 0) {
        if (((u8) (((KDInput *) (GetInput()))->GetLeftMag() != 0.0f) != 0) && ((s32) this->unk180 != 3)) {
            this->unk180.SetState(this, 3, 0U);
            return 1U;
        }
        var_r3_4848 = 0;
        /* Duplicate return node #7. Try simplifying control flow for better match */
        return var_r3_4848;
    }
    return var_r3_4848;
}
#endif

#if 0 // DRAFT: illegal operand
void SpeedWaySpyro::IdleUpdate() {
    MKAnim *temp_r4_4899;

    temp_r4_4899 = M2C_FIELD((this + (this->unkA0 * 0x24)), MKAnim **, 0xA8);
    if ((u32) this->unk80->unk20 != temp_r4_4899) {
        SetAnim(temp_r4_4899, 0.4f, 1U);
    }
    if (IdleTransition() != 0) {
        gAssertBool = 1;
    }
}
#endif

#if 0 // DRAFT: ')' expected
void SpeedWaySpyro::IdleEnter() {
    f32 var_f1_4952;
    s32 var_r31_4936;

    StateEnter();
    if ((s32) M2C_FIELD(checked_cast<SpeedWaySpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x15C) > 0) {
        var_r31_4936 = M2C_FIELD(checked_cast<SpeedWaySpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x15C);
    } else {
        var_r31_4936 = this->unk2F4;
    }
    this->unk338 = M2C_FIELD((checked_cast<SpeedWaySpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + (var_r31_4936 * 0x38)), f32 *, 0x78);
    this->unk8B1 = 1;
    if ((u8) this->unk2E8 != 0) {
        var_f1_4952 = 0.0f;
    } else {
        var_f1_4952 = M2C_FIELD(checked_cast<SpeedWaySpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x168);
    }
    SetAnim(M2C_FIELD((this + (this->unkA0 * 0x24)), MKAnim **, 0xA8), var_f1_4952, 1U);
}
#endif

#if 0 // DRAFT: expression syntax error
s32 SpeedWaySpyro::RespawnTransition() {
    if (((u8) M2C_FIELD(M2C_FIELD(&gb, void **, 0x32C), u8 *, 8) == 0) && ((s32) this->unk180 != 2)) {
        this->unk180.SetState(this, 2, 0U);
        return 1;
    }
    return 0;
}
#endif

void SpeedWaySpyro::RespawnUpdate() {
    RespawnTransition();
}

void SpeedWaySpyro::RespawnExit() {
    ((GameGlobals::Fade *) ((GameGlobals::Fade *) (&gb + 0x30)))->FadeIn(NULL);
    this->unk2E8 = 1;
}

void SpeedWaySpyro::RespawnEnter() {
    u8 var_r3_5064;
    void *temp_r4_5070;

    StateEnter();
    this->unk98 &= ~0xA;
    M2C_FIELD(M2C_FIELD(&gb, void **, 0x32C), u8 *, 8) = 1U;
    Music_Pause(1U);
    if ((u8) M2C_FIELD(M2C_FIELD(&gb, void **, 0x32C), u8 *, 8) != 0) {
        var_r3_5064 = 0;
        if (((u8) M2C_FIELD(M2C_FIELD(&gb, void **, 0xC), u8 *, 0xAA) != 0) || ((temp_r4_5070 = M2C_FIELD(M2C_FIELD(&gb, void **, 0xC), void **, 0x68), ((temp_r4_5070 == NULL) == 0)) && ((u8) M2C_FIELD(temp_r4_5070, u8 *, 0x5D) != 0))) {
            var_r3_5064 = 1;
        }
        if (var_r3_5064 == 0) {
            M2C_FIELD(M2C_FIELD(&gb, void **, 0xC), s8 *, 0xA9) = 0;
        }
    }
}

void SpeedWaySpyro::StateEnter() {
    this->unk98 |= 0xFF;
    SetColObjEnabled(1U);
    this->unk338 = 0.0f;
    this->unk194 = 0.0f;
}

#if 0 // DRAFT: undefined identifier 'gameData'
void SpeedWaySpyro::Start() {
    f64 sp18;
    f64 sp10;
    s32 spC;
    s32 sp8;
    void *temp_r3_5161;
    void *temp_r3_5202;
    void *temp_r4_5180;

    ClearData();
    gameData.unk70.Init(50.0f, 50.0f, NULL, NULL);
    ((Stat *) ((Stat *) (&gameData.unk70 + 0x30)))->Init(30.0f, 30.0f, NULL, NULL);
    ((Stat *) ((Stat *) (&gameData.unk70 + 0x48)))->SetValue(0.0f, 0U);
    gameData.unk70.SetCurrentBreath((BreathElement) 0);
    *(&gameData.unk70 + ((gameData.unk158 << 5) + 0x7C)) = 1;
    ((ScreenWobbleFX *) ((ScreenWobbleFX *) (&gb + 0xB8)))->EnableSpeedEffect(0U, 0.0f, 1.0f);
    if ((u8) this->unk2E9 == 0) {
        temp_r3_5161 = GetCamera();
        spC = 0;
        sp8 = 0x402;
        M2C_FIELD(M2C_FIELD(temp_r3_5161, void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp8);
        this->unk2E9 = 1;
    }
    this->unk2E8 = 1;
    Teleport(this->unk2C0, 1U);
    temp_r4_5180 = this->unk8;
    sp10 = M2C_FIELD(temp_r4_5180, f64 *, 0x30);
    sp18 = M2C_FIELD(temp_r4_5180, f64 *, 0x38);
    if (Connector_Update(*((MKVector3 *) &sp10)) == 0) {
        this->unk180.SetState(this, 1, 1U);
    } else {
        this->unk180.SetState(this, 2, 1U);
    }
    temp_r3_5202 = this->unk390;
    if (temp_r3_5202 != NULL) {
        M2C_FIELD(M2C_FIELD(temp_r3_5202, void **, 0x44), M2C_UNK (**)(), 0x20)();
    }
}
#endif

#if 0 // DRAFT: expression syntax error
void SpeedWaySpyro::Update() {
    f64 sp30;
    f64 sp28;
    f64 sp20;
    f64 sp18;
    f32 sp10;
    MKAnimScript *temp_r3_5295;

    this->unk2E8 = 0;
    sp28 = M2C_FIELD(this, f64 *, 0x1D0);
    sp30 = M2C_FIELD(this, f64 *, 0x1D8);
    UpdateStageInfo();
    UpdateSplineTime();
    if ((EventCamera_GetCurrent() != NULL) && (this->unk180.GetState() != 8)) {
        this->unk180.SetState(this, 8, 1U);
    } else if ((EventCamera_GetCurrent() == NULL) && (this->unk180.GetState() == 8)) {
        this->unk180.SetState(this, 2, 1U);
    }
    this->unk180.Update(this, 0);
    this->unk194 += gUpdateTimeDelta;
    UpdateMovementOffset();
    UpdateCameraAndSpyro(this->unk2C0, 0U, 0U);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r31, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    M2C_FIELD(this, f64 *, 0x2C8) = sp8;
    sp10 = this->unk1A0.unk38 - (f32) sp30;
    sp18 = sp8;
    sp20 = (f64) sp10;
    M2C_FIELD(this, f64 *, 0x2D0) = (f64) sp10;
    UpdateEffects();
    UpdateSound();
    temp_r3_5295 = this->unk80;
    if ((u32) temp_r3_5295->unk20 != 0) {
        this->unk80->Animate(MKModel_GetAnimation(temp_r3_5295->unk8), -1, &this->unk130);
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'zero'
void SpeedWaySpyro::ClearData() {
    s32 var_r30_5340;
    s32 var_r30_5364;
    s32 var_r30_5386;
    s32 var_r30_5408;
    s32 var_r30_5430;
    s32 var_r30_5452;
    s32 var_r30_5474;

    this->unk2F4 = 2;
    this->unkA0 = 1;
    this->unkA4 = 1;
    this->unkA5 = 1;
    M2C_FIELD(this, f64 *, 0x130) = (f64) M2C_FIELD(&zero, f64 *, 0);
    M2C_FIELD(this, f64 *, 0x138) = (f64) M2C_FIELD(&zero, f64 *, 8);
    if ((s32) M2C_FIELD(checked_cast<SpeedWaySpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x15C) > 0) {
        var_r30_5340 = M2C_FIELD(checked_cast<SpeedWaySpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x15C);
    } else {
        var_r30_5340 = this->unk2F4;
    }
    this->unk140 = *(checked_cast<SpeedWaySpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + ((var_r30_5340 * 0x38) + 0x70));
    memset(&this->unk144, 0, 4U);
    this->unk148 = this->unk140;
    if ((s32) M2C_FIELD(checked_cast<SpeedWaySpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x15C) > 0) {
        var_r30_5364 = M2C_FIELD(checked_cast<SpeedWaySpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x15C);
    } else {
        var_r30_5364 = this->unk2F4;
    }
    this->unk14C = *(checked_cast<SpeedWaySpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + ((var_r30_5364 * 0x38) + 0x88));
    memset(&this->unk150, 0, 4U);
    if ((s32) M2C_FIELD(checked_cast<SpeedWaySpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x15C) > 0) {
        var_r30_5386 = M2C_FIELD(checked_cast<SpeedWaySpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x15C);
    } else {
        var_r30_5386 = this->unk2F4;
    }
    this->unk164 = *(checked_cast<SpeedWaySpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + ((var_r30_5386 * 0x38) + 0x9C));
    memset(&this->unk168, 0, 4U);
    if ((s32) M2C_FIELD(checked_cast<SpeedWaySpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x15C) > 0) {
        var_r30_5408 = M2C_FIELD(checked_cast<SpeedWaySpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x15C);
    } else {
        var_r30_5408 = this->unk2F4;
    }
    this->unk16C = *(checked_cast<SpeedWaySpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + ((var_r30_5408 * 0x38) + 0xA0));
    memset(&this->unk170, 0, 4U);
    if ((s32) M2C_FIELD(checked_cast<SpeedWaySpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x15C) > 0) {
        var_r30_5430 = M2C_FIELD(checked_cast<SpeedWaySpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x15C);
    } else {
        var_r30_5430 = this->unk2F4;
    }
    this->unk154 = *(checked_cast<SpeedWaySpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + ((var_r30_5430 * 0x38) + 0x94));
    memset(&this->unk158, 0, 4U);
    if ((s32) M2C_FIELD(checked_cast<SpeedWaySpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x15C) > 0) {
        var_r30_5452 = M2C_FIELD(checked_cast<SpeedWaySpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x15C);
    } else {
        var_r30_5452 = this->unk2F4;
    }
    this->unk15C = *(checked_cast<SpeedWaySpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + ((var_r30_5452 * 0x38) + 0x98));
    memset(&this->unk160, 0, 4U);
    if ((s32) M2C_FIELD(checked_cast<SpeedWaySpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x15C) > 0) {
        var_r30_5474 = M2C_FIELD(checked_cast<SpeedWaySpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x15C);
    } else {
        var_r30_5474 = this->unk2F4;
    }
    this->unk174 = *(checked_cast<SpeedWaySpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + ((var_r30_5474 * 0x38) + 0xA4));
    memset(&this->unk178, 0, 4U);
    this->unk17C.Reset();
    M2C_STRUCT_COPY((s32) &this->unk19C + 4, (s32) (&identity - 4) + 4, 0x40);
    M2C_STRUCT_COPY((s32) &this->unk1A0.unk3C + 4, (s32) (&identity - 4) + 4, 0x40);
    M2C_STRUCT_COPY((s32) &this->unk21C + 4, (s32) (&identity - 4) + 4, 0x40);
    this->unk260 = M2C_FIELD(&identity, f64 *, 0);
    this->unk268 = M2C_FIELD(&identity, f64 *, 8);
    memset(&this->unk270, 0, 0x10U);
    this->unk280 = M2C_FIELD(&identity, f64 *, 0x10);
    this->unk288 = M2C_FIELD(&identity, f64 *, 0x18);
    memset(&this->unk290, 0, 0x10U);
    this->unk2A0 = M2C_FIELD(&identity, f64 *, 0x20);
    this->unk2A8 = M2C_FIELD(&identity, f64 *, 0x28);
    memset(&this->unk2B0, 0, 0x10U);
    this->unk300 = 0;
    this->unk304 = 0.0f;
    this->unk2EC = 0.0f;
    this->unk2C0 = 0.0f;
    M2C_FIELD(this, f64 *, 0x2C8) = (f64) M2C_FIELD(&zero, f64 *, 0);
    M2C_FIELD(this, f64 *, 0x2D0) = (f64) M2C_FIELD(&zero, f64 *, 8);
    this->unk2D8 = M2C_FIELD(&zero, f64 *, 0);
    M2C_FIELD(this, f64 *, 0x2E0) = (f64) M2C_FIELD(&zero, f64 *, 8);
    this->unk194 = 0.0f;
    this->unk2E8 = 0;
    this->unk2F8 = 0.0f;
    this->unk328 = M2C_FIELD(&zero, f64 *, 0);
    this->unk330 = M2C_FIELD(&zero, f64 *, 8);
    this->unk318 = this->unk328;
    this->unk320 = this->unk330;
    this->unk308 = this->unk318;
    this->unk310 = this->unk320;
    this->unk338 = 0.0f;
    this->unk360 = M2C_FIELD(&zero, f64 *, 0);
    this->unk368 = M2C_FIELD(&zero, f64 *, 8);
    this->unk350 = this->unk360;
    this->unk358 = this->unk368;
    this->unk340 = this->unk350;
    this->unk348 = this->unk358;
    this->unk370 = M2C_FIELD(&zero, f64 *, 0);
    this->unk378 = M2C_FIELD(&zero, f64 *, 8);
    this->unk380 = 0.0f;
    this->unk810 = 0.0f;
    this->unk814 = 1;
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_sp4C'
void SpeedWaySpyro::Draw() {
    M2C_STRUCT_COPY((s32) &arg_sp4C + 4, MKModel_GetWorldMatrix(this->unk4) - 4 + 4, 0x40);
    M2C_STRUCT_COPY((s32) &arg_spC + 4, (s32) &arg_sp4C + 4, 0x40);
    arg_sp10.Translate((Matrix *) &arg_sp10, *((MKVector3 *) &this->unk2D8));
    MKModel_SetWorldMatrix(this->unk4, *((Matrix *) &arg_sp10));
    MKModel_Draw(this->unk4, NULL);
    MKModel_SetWorldMatrix(this->unk4, *((Matrix *) &arg_sp50));
}
#endif

#if 0 // DRAFT: expression syntax error
void SpeedWaySpyro::Message(MKMessage *arg0) {
    f32 temp_f1_5850;
    f32 var_f1_5853;
    s32 temp_r0_5678;
    u32 temp_r4_5927;
    void ***temp_r29_5779;
    void *temp_r3_5841;
    void *temp_r3_5914;
    void *temp_r3_5925;
    this->unk818.Message(arg0);
    this->unk888.Message(arg0);
    temp_r0_5678 = arg0->unk0;
    switch (temp_r0_5678) {                         /* irregular */
    case 0xB5:
        if (this->unk18 & 0x80000000) {
            M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), M2C_UNK (**)(void **), 0x24)(M2C_FIELD(&gb, void ***, 0));
            Enable();
            this->unk90.RegisterTargetable();
            this->unk38C = gb.SetHero(this->unk388);
            Start();
        }
        break;
    case 0xB4:
        if (!(this->unk18 & 0x80000000)) {
            this->unk8B1 = 0;
            if ((u8) this->unk2E9 != 0) {
                arg_sp84 = 0;
                arg_sp80 = 0x403;
                arg_sp88 = 1;
                M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, M2C_UNK), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &arg_sp80, 0x403);
                this->unk2E9 = 0;
            }
            Disable();
            temp_r29_5779 = &gb + 0xB8;
            temp_r29_5779->EnableSpeedEffect(0U, 0.0f, 1.0f);
            this->unk180.SetState(this, 0, 1U);
            temp_r29_5779->EnableSpeedEffect(0U, 0.0f, 1.0f);
            gb.SetHero(this->unk38C);
            this->unk38C = NULL;
            this->unk90.UnregisterTargetable();
            M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), M2C_UNK (**)(void **), 0x20)(M2C_FIELD(&gb, void ***, 0));
        }
        break;
    case 0x7:
        Hurt(checked_cast<P11HurtMessage, 9MKMessage>__FP9MKMessage(arg0));
        break;
    case 0xE6:
        gameData.unk70.SetValue(gameData.unk74, 0U);
        break;
    case 0x150:
        SetStageIndex(1);
        break;
    case 0x151:
        SetStageIndex(2);
        break;
    case 0x152:
        SetStageIndex(3);
        break;
    case 0x62:
        temp_r3_5841 = checked_cast<SpeedWayFuturePosRequestMsg *, MKMessage>(arg0);
        temp_f1_5850 = (this->unk140 * M2C_FIELD(temp_r3_5841, f32 *, 8)) + (this->unk2C0 * g_pathMaxDistance);
        if (temp_f1_5850 > g_pathMaxDistance) {
            var_f1_5853 = 1.0f;
        } else {
            var_f1_5853 = temp_f1_5850 * g_invPathMaxDistance;
        }
        arg_sp90.GetPathMatrix(var_f1_5853);
        M2C_STRUCT_COPY((s32) &arg_spCC + 4, (s32) &arg_sp8C + 4, 0x40);
        __ml(M2C_FIELD(this, f32 *, 0x30C), *((MKVector3 *) &arg_sp40));
        __ml(M2C_FIELD(this, f32 *, 0x308), *((MKVector3 *) &arg_sp50));
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        arg_sp60 = arg_sp10;
        arg_sp18 = arg_sp108 + arg_sp58;
        arg_sp68 = (f64) arg_sp18;
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        M2C_FIELD(temp_r3_5841, f64 *, 0x10) = arg_sp20;
        arg_sp28 = (f32) arg_sp68 + arg_sp48;
        arg_sp70 = arg_sp20;
        arg_sp78 = (f64) arg_sp28;
        M2C_FIELD(temp_r3_5841, f64 *, 0x18) = (f64) arg_sp28;
        break;
    case 0xE0:
        this->unk180.SetState(this, 7, 1U);
        break;
    case 0x423:
        temp_r3_5914 = this->unk390;
        if (temp_r3_5914 != NULL) {
            M2C_FIELD(M2C_FIELD(temp_r3_5914, void **, 0x44), M2C_UNK (**)(MKMessage *), 0x2C)(arg0);
        }
        break;
    case 0x5:
        temp_r3_5925 = checked_cast<BreathHitMessage *, MKMessage>(arg0);
        temp_r4_5927 = M2C_FIELD(temp_r3_5925, u32 *, 8);
        if (temp_r4_5927 != this) {
            arg_sp114 = 0;
            arg_sp110 = 7;
            arg_sp138 = 1;
            arg_sp13C = temp_r4_5927;
            arg_sp118 = M2C_FIELD(&zero, f64 *, 0);
            arg_sp120 = M2C_FIELD(&zero, f64 *, 8);
            arg_sp150 = 1;
            arg_sp15C = 2;
            arg_sp158 = M2C_FIELD(temp_r3_5925, f32 *, 0x34);
            arg_sp150 = 0;
            (s16) arg_sp150 = 0;
            arg_sp154 = -1;
            arg_sp128 = M2C_FIELD(&one, f64 *, 0);
            arg_sp130 = M2C_FIELD(&one, f64 *, 8);
            arg_sp160 = 0U;
            if (temp_r4_5927 != 0U) {
                arg_sp30.GetPos();
                arg_sp140 = arg_sp30;
                arg_sp148 = arg_sp38;
            } else {
                arg_sp140 = 0.0f;
                arg_sp144 = 0.0f;
                arg_sp148 = 0.0f;
            }
            arg_sp160 = 0U;
            Hurt((HurtMessage *) &arg_sp110);
            M2C_FIELD(temp_r3_5925, u8 *, 0x50) = arg_sp160;
        }
        break;
    }
    KDProp::Message(arg0);
}
#endif

#if 0 // DRAFT: function call 'checked_cast(void *)' does not match
void SpeedWaySpyro::Resolve() {
    MKProp *temp_r3_6024;
    MKSceneManager *temp_r5_6010;
    f32 temp_f1_6017;
    f32 temp_f2_6013;
    void *temp_r3_6045;
    MKProp::Resolve();
    this->unk2F0 = checked_cast<SpeedWay *, MKProp>(this->unk2F0->PropResolver_Resolve(M2C_ERROR(/* Read from unset register $r4 */)));
    temp_r5_6010 = this->unk2F0;
    temp_f2_6013 = temp_r5_6010->unk84;
    temp_f1_6017 = 0.5f * (temp_f2_6013 + M2C_BITWISE(f32, temp_r5_6010->unkCC));
    g_pathMaxDistance = temp_f1_6017;
    g_invPathMaxDistance = 1.0f / temp_f1_6017;
    temp_r3_6024 = M2C_FIELD(*gMK, MKProp *(**)(void **, void *, MKSceneManager *, f32, f32, f32), 0x60)(gMK, "SpeedwayCynder", temp_r5_6010, temp_f1_6017, temp_f2_6013, 0.5f);
    if (temp_r3_6024 != NULL) {
        this->unk390 = checked_cast<SpeedwayCynder *, MKProp>(temp_r3_6024);
    }
    arg_sp10.GetPathMatrix(0.0f);
    M2C_STRUCT_COPY((s32) &arg_sp4C + 4, (s32) &arg_spC + 4, 0x40);
    temp_r3_6045 = checked_cast<SpeedWaySpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    arg_sp8 = this;
    arg_spC = 0;
    M2C_FIELD(M2C_FIELD(this, void **, 0x398), M2C_UNK (**)(M2C_UNK *, void *, M2C_UNK *, M2C_UNK, MKCollisionInfo *, M2C_UNK, M2C_UNK, M2C_UNK), 8)(&this->unk398, temp_r3_6045 + 0x194, &arg_sp80, 0, &this->unk70, 1, 1, 0);
    Init__31KDStateMachine<13SpeedWaySpyro>FPQ231KDStateMachine<13SpeedWaySpyro>5StateP31KDStateMachine<13SpeedWaySpyro>((KDStateMachine<SpeedWaySpyro> *) &this->unk180, (KDStateMachine<SpeedWaySpyro>::State *) &states, NULL);
    this->unk180.SetState(this, 0, 1U);
    this->unk2FC.Resolve();
    this->unk8B4 = (f32) KDSound_GetSoundEventVol(GS_SpyroSpeedwayGlideLP) / 255.0f;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'const char[10]' to
void SpeedWaySpyro::LoadDone() {
    s32 sp10;
    s32 spC;
    s32 sp8;
    MKAnim *temp_ret_6215;
    MKAnim *temp_ret_6225;
    MKAnim *temp_ret_6235;
    MKAnim *temp_ret_6245;
    MKAnim *temp_ret_6255;
    s32 temp_r24_6119;
    s32 var_r26_6115;
    s32 var_r27_6114;
    s32 var_r28_6112;
    void *temp_r23_6128;
    void *temp_r29_6110;
    void *temp_ret_6127;
    void *temp_ret_6137;
    void *temp_ret_6146;
    void *temp_ret_6155;
    void *temp_ret_6164;
    void *temp_ret_6173;
    void *temp_ret_6182;
    void *temp_ret_6191;
    void *temp_ret_6200;

    KDProp::LoadDone();
    temp_r29_6110 = "SpeedWay_";
    var_r28_6112 = 0;
    sp8 = M2C_FIELD(&lit_869, s32 *, 0);
    var_r27_6114 = 0;
    var_r26_6115 = 0;
    spC = M2C_FIELD(&lit_869, s32 *, 4);
    sp10 = M2C_FIELD(&lit_869, s32 *, 8);
    do {
        temp_r24_6119 = *(&sp8 + var_r26_6115);
        temp_ret_6127 = this->unk80->GetAnim(Str_Printf("%sIdle%s", temp_r29_6110, temp_r24_6119));
        temp_r23_6128 = this + var_r27_6114;
        M2C_FIELD(temp_r23_6128, void **, 0xA8) = temp_ret_6127;
        temp_ret_6137 = this->unk80->GetAnim(Str_Printf("%sMove_Left%s", temp_r29_6110, temp_r24_6119, M2C_BITWISE(f32, temp_ret_6127)));
        M2C_FIELD(temp_r23_6128, void **, 0xAC) = temp_ret_6137;
        temp_ret_6146 = this->unk80->GetAnim(Str_Printf("%sMove_Right%s", temp_r29_6110, temp_r24_6119, M2C_BITWISE(f32, temp_ret_6137)));
        M2C_FIELD(temp_r23_6128, void **, 0xB0) = temp_ret_6146;
        temp_ret_6155 = this->unk80->GetAnim(Str_Printf("%sMove_Up%s", temp_r29_6110, temp_r24_6119, M2C_BITWISE(f32, temp_ret_6146)));
        M2C_FIELD(temp_r23_6128, void **, 0xB4) = temp_ret_6155;
        temp_ret_6164 = this->unk80->GetAnim(Str_Printf("%sMove_Down%s", temp_r29_6110, temp_r24_6119, M2C_BITWISE(f32, temp_ret_6155)));
        M2C_FIELD(temp_r23_6128, void **, 0xB8) = temp_ret_6164;
        temp_ret_6173 = this->unk80->GetAnim(Str_Printf("%sMove_Left_Up%s", temp_r29_6110, temp_r24_6119, M2C_BITWISE(f32, temp_ret_6164)));
        M2C_FIELD(temp_r23_6128, void **, 0xBC) = temp_ret_6173;
        temp_ret_6182 = this->unk80->GetAnim(Str_Printf("%sMove_Right_Up%s", temp_r29_6110, temp_r24_6119, M2C_BITWISE(f32, temp_ret_6173)));
        M2C_FIELD(temp_r23_6128, void **, 0xC0) = temp_ret_6182;
        temp_ret_6191 = this->unk80->GetAnim(Str_Printf("%sMove_Left_Down%s", temp_r29_6110, temp_r24_6119, M2C_BITWISE(f32, temp_ret_6182)));
        M2C_FIELD(temp_r23_6128, void **, 0xC4) = temp_ret_6191;
        temp_ret_6200 = this->unk80->GetAnim(Str_Printf("%sMove_Right_Down%s", temp_r29_6110, temp_r24_6119, M2C_BITWISE(f32, temp_ret_6191)));
        var_r28_6112 += 1;
        M2C_FIELD(temp_r23_6128, void **, 0xC8) = temp_ret_6200;
        var_r27_6114 += 0x24;
        var_r26_6115 += 4;
    } while (var_r28_6112 < 3);
    temp_ret_6215 = this->unk80->GetAnim(Str_Printf("%sPowerRoll_Left", temp_r29_6110, M2C_BITWISE(f32, temp_ret_6200)));
    this->unk11C = temp_ret_6215;
    temp_ret_6225 = this->unk80->GetAnim(Str_Printf("%sPowerRoll_Right", temp_r29_6110, M2C_BITWISE(f32, temp_ret_6215)));
    this->unk120 = temp_ret_6225;
    temp_ret_6235 = this->unk80->GetAnim(Str_Printf("%sPowerRoll_Up", temp_r29_6110, M2C_BITWISE(f32, temp_ret_6225)));
    this->unk114 = temp_ret_6235;
    temp_ret_6245 = this->unk80->GetAnim(Str_Printf("%sPowerRoll_Down", temp_r29_6110, M2C_BITWISE(f32, temp_ret_6235)));
    this->unk118 = temp_ret_6245;
    temp_ret_6255 = this->unk80->GetAnim(Str_Printf("%sFlinch", temp_r29_6110, M2C_BITWISE(f32, temp_ret_6245)));
    this->unk124 = temp_ret_6255;
    this->unk128 = this->unk80->GetAnim(Str_Printf("%sFall", temp_r29_6110, M2C_BITWISE(f32, temp_ret_6255)));
    this->unk17C.Init(0xF);
    operator new(8U, NULL, 0);
    if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
        *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
    }
    this->unk388 = M2C_ERROR(/* Read from unset register $r3 */);
    this->unk388->unk4 = this;
    this->unk38C = NULL;
    this->unk2F4 = 2;
    ClearData();
    this->unk2E9 = 0;
    Disable();
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long *' to
s32 SpeedWaySpyro::LoadLine(MKIniLine *arg0) {
    s32 var_r31_6315;

    var_r31_6315 = 0;
    if ((KDProp::LoadLine(arg0) != 0) || (arg0->LoadInt("Speedway", (s32 *) &this->unk2F0, 0) != 0)) {
        var_r31_6315 = 1;
    }
    return var_r31_6315;
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void SpeedWaySpyro::Deinit() {
    s32 spC;
    s32 sp8;
    s32 temp_r3_6372;

    spC = 0;
    sp8 = 0xB4;
    M2C_FIELD(this->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp8);
    this->unk180.Deinit();
    this->unk2FC.Deinit();
    this->unk17C.Deinit();
    operator delete(this->unk388);
    this->unk8B1 = 0;
    this->unk818.Deinit();
    this->unk8B0 = 0;
    KDSound_Stop(&this->unk888);
    temp_r3_6372 = this->unk8C4;
    if (temp_r3_6372 != 0) {
        PhrasePlayer_StopEvent(temp_r3_6372);
    }
    KDProp::Deinit();
}
#endif

#if 0 // DRAFT: expression syntax error
void SpeedWaySpyro::Init() {
    KDProp::Init();
    this->unk2FC.Init();
    this->unk818.Init(0, 0.95f, 1.15f, 0.09f, 0.25f, 0.25f);
    this->unk888.Init(0.5f, 0.025f);
    this->unk8B1 = 0;
    this->unk8B0 = 0;
    this->unk8C4 = 0;
    this->unk390 = NULL;
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void SpeedWaySpyroDescriptor::LoadDone() {
    KDPropDescriptor::LoadDone();
    this->unk190 = MKModel_GetRefPointIndex(this->unk2C, "r_a001_nose");
}
#endif

#if 0 // DRAFT: illegal use of non-static member
s32 SpeedWaySpyroDescriptor::LoadLine(MKIniLine *arg0) {
    s32 var_r31_6452;

    var_r31_6452 = 0;
    if ((KDPropDescriptor::LoadLine(arg0) != 0) || (arg0->LoadFloat("accelFraction", &this->unk160, 0) != 0) || (arg0->LoadFloat("xyMoveMaxDist", &this->unk164, 0) != 0)) {
        var_r31_6452 = 1;
    }
    return var_r31_6452;
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void SpeedWaySpyroDescriptor::Deinit() {
    KDPropDescriptor::Deinit();
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void SpeedWaySpyroDescriptor::Init() {
    void *temp_r3_6624;

    KDPropDescriptor::Init();
    memset(&this->unk70, 0, 0x38U);
    this->unkA8 = 2500.0f;
    this->unkAC = 1800.0f;
    this->unkB0 = 2.0f;
    this->unkB4 = 330000.0f;
    this->unkB8 = 500000.0f;
    this->unkBC = 1.7f;
    this->unkC0 = 900.0f;
    this->unkC4 = 250.0f;
    this->unkC8 = -200.0f;
    this->unkCC = 1850.0f;
    this->unkD0 = 2025.0f;
    this->unkD4 = 1500.0f;
    this->unkD8 = 1775.0f;
    this->unkDC = 47.0f;
    this->unkE0 = 4500.0f;
    this->unkE4 = 1800.0f;
    this->unkE8 = 1.5f;
    this->unkEC = 400000.0f;
    this->unkF0 = 600000.0f;
    this->unkF4 = 1.7f;
    this->unkF8 = 1000.0f;
    this->unkFC = 300.0f;
    this->unk100 = -200.0f;
    this->unk104 = 1850.0f;
    this->unk108 = 2025.0f;
    this->unk10C = 1500.0f;
    this->unk110 = 1775.0f;
    this->unk114 = 45.0f;
    this->unk118 = 6500.0f;
    this->unk11C = 1800.0f;
    this->unk120 = 1.7f;
    this->unk124 = 480000.0f;
    this->unk128 = 680000.0f;
    this->unk12C = 1.7f;
    this->unk130 = 1200.0f;
    this->unk134 = 250.0f;
    this->unk138 = -200.0f;
    this->unk13C = 1825.0f;
    this->unk140 = 2000.0f;
    this->unk144 = 1475.0f;
    this->unk148 = 1800.0f;
    this->unk14C = 40.0f;
    this->unk150 = 1.9f;
    this->unk154 = 1.7f;
    this->unk158 = 1.7f;
    this->unk15C = 0;
    this->unk160 = 0.25f;
    this->unk164 = 2400.0f;
    this->unk168 = 0.8f;
    this->unk16C = 2400.0f;
    this->unk170 = 1.8f;
    this->unk174 = 0.75f;
    this->unk178 = 0.9f;
    this->unk17C = 0.5f;
    this->unk180 = 0.25f;
    this->unk184 = 0.67f;
    this->unk188 = 50.0f;
    this->unk18C = 1.0f;
    System_GetCommandLineParameter("UsePulledBackCamera", 0U);
    bUsePulledBackCamera = M2C_ERROR(/* Read from unset register $r3 */) != 0;
    gb.GetSpyro();
    temp_r3_6624 = checked_cast<SpyroDescriptor *, MKPropDescriptor>(*M2C_ERROR(/* Read from unset register $r3 */));
    this->unk194 = M2C_FIELD(temp_r3_6624, f32 *, 0x60);
    this->unk198 = M2C_FIELD(temp_r3_6624, f32 *, 0x64);
    this->unk19C = M2C_FIELD(temp_r3_6624, s32 *, 0x68);
    this->unk1A0 = M2C_FIELD(temp_r3_6624, s32 *, 0x6C);
    this->unk1A4 = M2C_FIELD(temp_r3_6624, s32 *, 0x70);
    this->unk1A8 = M2C_FIELD(temp_r3_6624, u8 *, 0x74);
    this->unk1AC = M2C_FIELD(temp_r3_6624, s32 *, 0x78);
    this->unk1B0 = M2C_FIELD(temp_r3_6624, s32 *, 0x7C);
    this->unk1B4 = M2C_FIELD(temp_r3_6624, s32 *, 0x80);
    this->unk1B8 = M2C_FIELD(temp_r3_6624, s32 *, 0x84);
    this->unk1BC = M2C_FIELD(temp_r3_6624, s32 *, 0x88);
    this->unk1C0 = M2C_FIELD(temp_r3_6624, s32 *, 0x8C);
    this->unk1C4 = M2C_FIELD(temp_r3_6624, s32 *, 0x90);
    this->unk1C8 = M2C_FIELD(temp_r3_6624, s32 *, 0x94);
    this->unk1CC = M2C_FIELD(temp_r3_6624, s32 *, 0x98);
    this->unk1D0 = M2C_FIELD(temp_r3_6624, s32 *, 0x9C);
    this->unk1D4 = M2C_FIELD(temp_r3_6624, s32 *, 0xA0);
    this->unk1D8 = M2C_FIELD(temp_r3_6624, s32 *, 0xA4);
    this->unk1DC = M2C_FIELD(temp_r3_6624, s32 *, 0xA8);
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_818'
void SpeedWaySpyro_cpp::__sinit() {
    s32 sp44;
    s32 sp40;
    s32 sp3C;
    s32 sp38;
    s32 sp34;
    s32 sp30;
    s32 sp2C;
    s32 sp28;
    s32 sp24;
    s32 sp20;
    s32 sp1C;
    s32 sp18;
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    f64 temp_f1_7247;
    f64 temp_f1_7265;
    f64 temp_f3_7231;
    f64 temp_f3_7268;
    f64 temp_f4_7246;
    f64 temp_f4_7262;
    f64 temp_f8_7233;
    void *temp_r20_7241;

    temp_f3_7231 = __frsqrte(2014000.0);
    temp_f8_7233 = __frsqrte(380000.0);
    temp_r20_7241 = &lit_818 + 0xFC;
    temp_f4_7246 = 0.5 * temp_f3_7231 * -((2014000.0 * (temp_f3_7231 * temp_f3_7231)) - 3.0);
    temp_f1_7247 = 0.5 * temp_f8_7233 * -((380000.0 * (temp_f8_7233 * temp_f8_7233)) - 3.0);
    temp_f4_7262 = 0.5 * temp_f4_7246 * -((2014000.0 * (temp_f4_7246 * temp_f4_7246)) - 3.0);
    temp_f1_7265 = 0.5 * temp_f1_7247 * -((380000.0 * (temp_f1_7247 * temp_f1_7247)) - 3.0);
    temp_f3_7268 = temp_f4_7262 * temp_f4_7262;
    sp8 = M2C_FIELD(&__ptmf_null, s32 *, 0);
    spC = M2C_FIELD(&__ptmf_null, s32 *, 4);
    sp10 = M2C_FIELD(&__ptmf_null, s32 *, 8);
    M2C_FIELD(&lit_818, s32 *, 0xFC) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 0);
    M2C_FIELD(&lit_818, s32 *, 0x100) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 4);
    M2C_FIELD(&lit_818, s32 *, 0x104) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 8);
    M2C_FIELD(temp_r20_7241, s32 *, 0xC) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 0);
    M2C_FIELD(temp_r20_7241, s32 *, 0x10) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 4);
    M2C_FIELD(temp_r20_7241, s32 *, 0x14) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 8);
    M2C_FIELD(temp_r20_7241, s32 *, 0x18) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 0);
    M2C_FIELD(temp_r20_7241, s32 *, 0x1C) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 4);
    M2C_FIELD(temp_r20_7241, s32 *, 0x20) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 8);
    M2C_FIELD(temp_r20_7241, s32 *, 0x24) = (s32) M2C_FIELD(&lit_818, s32 *, 0);
    M2C_FIELD(temp_r20_7241, s32 *, 0x28) = (s32) M2C_FIELD(&lit_818, s32 *, 4);
    M2C_FIELD(temp_r20_7241, s32 *, 0x2C) = (s32) M2C_FIELD(&lit_818, s32 *, 8);
    M2C_FIELD(temp_r20_7241, s32 *, 0x30) = (s32) M2C_FIELD(&lit_818, s32 *, 0xC);
    M2C_FIELD(temp_r20_7241, s32 *, 0x34) = (s32) M2C_FIELD(&lit_818, s32 *, 0x10);
    M2C_FIELD(temp_r20_7241, s32 *, 0x38) = (s32) M2C_FIELD(&lit_818, s32 *, 0x14);
    M2C_FIELD(temp_r20_7241, s32 *, 0x3C) = (s32) M2C_FIELD(&lit_818, s32 *, 0x18);
    M2C_FIELD(temp_r20_7241, s32 *, 0x40) = (s32) M2C_FIELD(&lit_818, s32 *, 0x1C);
    M2C_FIELD(temp_r20_7241, s32 *, 0x44) = (s32) M2C_FIELD(&lit_818, s32 *, 0x20);
    SPYRO_BOUNCE_Y_SPEED = (f32) (2014000.0 * (0.5 * temp_f4_7262 * -((2014000.0 * temp_f3_7268) - 3.0)));
    SPYRO_MIN_JUMP_Y_VELOCITY = (f32) (380000.0 * (0.5 * temp_f1_7265 * -((380000.0 * (temp_f1_7265 * temp_f1_7265)) - 3.0)));
    sp44 = M2C_FIELD(&lit_818, s32 *, 0x80);
    M2C_FIELD(temp_r20_7241, s32 *, 0xB4) = (s32) M2C_FIELD(&lit_818, s32 *, 0x78);
    sp14 = M2C_FIELD(&lit_818, s32 *, 0x84);
    M2C_FIELD(temp_r20_7241, s32 *, 0xBC) = sp44;
    sp18 = M2C_FIELD(&lit_818, s32 *, 0x88);
    M2C_FIELD(temp_r20_7241, s32 *, 0xCC) = sp14;
    sp1C = M2C_FIELD(&lit_818, s32 *, 0x8C);
    M2C_FIELD(temp_r20_7241, s32 *, 0xD0) = sp18;
    sp20 = M2C_FIELD(&lit_818, s32 *, 0x90);
    M2C_FIELD(temp_r20_7241, s32 *, 0xD4) = sp1C;
    sp24 = M2C_FIELD(&lit_818, s32 *, 0x94);
    M2C_FIELD(temp_r20_7241, s32 *, 0xD8) = sp20;
    sp28 = M2C_FIELD(&lit_818, s32 *, 0x98);
    M2C_FIELD(temp_r20_7241, s32 *, 0xDC) = sp24;
    sp2C = M2C_FIELD(&lit_818, s32 *, 0x9C);
    M2C_FIELD(temp_r20_7241, s32 *, 0xE0) = sp28;
    sp30 = M2C_FIELD(&lit_818, s32 *, 0xA0);
    M2C_FIELD(temp_r20_7241, s32 *, 0xE4) = sp2C;
    sp34 = M2C_FIELD(&lit_818, s32 *, 0xA4);
    M2C_FIELD(temp_r20_7241, s32 *, 0xE8) = sp30;
    sp38 = M2C_FIELD(&lit_818, s32 *, 0xA8);
    M2C_FIELD(temp_r20_7241, s32 *, 0xEC) = sp34;
    sp3C = M2C_FIELD(&lit_818, s32 *, 0xAC);
    M2C_FIELD(temp_r20_7241, s32 *, 0xF0) = sp38;
    M2C_FIELD(temp_r20_7241, s32 *, 0xF4) = sp3C;
    sp40 = M2C_FIELD(&lit_818, s32 *, 0xB0);
    M2C_FIELD(temp_r20_7241, s32 *, 0x48) = (s32) M2C_FIELD(&lit_818, s32 *, 0x24);
    M2C_FIELD(temp_r20_7241, s32 *, 0x4C) = (s32) M2C_FIELD(&lit_818, s32 *, 0x28);
    M2C_FIELD(temp_r20_7241, s32 *, 0x50) = (s32) M2C_FIELD(&lit_818, s32 *, 0x2C);
    M2C_FIELD(temp_r20_7241, s32 *, 0x54) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 0);
    M2C_FIELD(temp_r20_7241, s32 *, 0x58) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 4);
    M2C_FIELD(temp_r20_7241, s32 *, 0x5C) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 8);
    M2C_FIELD(temp_r20_7241, s32 *, 0x60) = (s32) M2C_FIELD(&lit_818, s32 *, 0x30);
    M2C_FIELD(temp_r20_7241, s32 *, 0x64) = (s32) M2C_FIELD(&lit_818, s32 *, 0x34);
    M2C_FIELD(temp_r20_7241, s32 *, 0x68) = (s32) M2C_FIELD(&lit_818, s32 *, 0x38);
    M2C_FIELD(temp_r20_7241, s32 *, 0x6C) = (s32) M2C_FIELD(&lit_818, s32 *, 0x3C);
    M2C_FIELD(temp_r20_7241, s32 *, 0x70) = (s32) M2C_FIELD(&lit_818, s32 *, 0x40);
    M2C_FIELD(temp_r20_7241, s32 *, 0x74) = (s32) M2C_FIELD(&lit_818, s32 *, 0x44);
    M2C_FIELD(temp_r20_7241, s32 *, 0x78) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 0);
    M2C_FIELD(temp_r20_7241, s32 *, 0x7C) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 4);
    M2C_FIELD(temp_r20_7241, s32 *, 0x80) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 8);
    M2C_FIELD(temp_r20_7241, s32 *, 0x84) = (s32) M2C_FIELD(&lit_818, s32 *, 0x48);
    M2C_FIELD(temp_r20_7241, s32 *, 0x88) = (s32) M2C_FIELD(&lit_818, s32 *, 0x4C);
    M2C_FIELD(temp_r20_7241, s32 *, 0x8C) = (s32) M2C_FIELD(&lit_818, s32 *, 0x50);
    M2C_FIELD(temp_r20_7241, s32 *, 0x90) = (s32) M2C_FIELD(&lit_818, s32 *, 0x54);
    M2C_FIELD(temp_r20_7241, s32 *, 0x94) = (s32) M2C_FIELD(&lit_818, s32 *, 0x58);
    M2C_FIELD(temp_r20_7241, s32 *, 0x98) = (s32) M2C_FIELD(&lit_818, s32 *, 0x5C);
    M2C_FIELD(temp_r20_7241, s32 *, 0x9C) = (s32) M2C_FIELD(&lit_818, s32 *, 0x60);
    M2C_FIELD(temp_r20_7241, s32 *, 0xA0) = (s32) M2C_FIELD(&lit_818, s32 *, 0x64);
    M2C_FIELD(temp_r20_7241, s32 *, 0xA4) = (s32) M2C_FIELD(&lit_818, s32 *, 0x68);
    M2C_FIELD(temp_r20_7241, s32 *, 0xA8) = (s32) M2C_FIELD(&lit_818, s32 *, 0x6C);
    M2C_FIELD(temp_r20_7241, s32 *, 0xAC) = (s32) M2C_FIELD(&lit_818, s32 *, 0x70);
    M2C_FIELD(temp_r20_7241, s32 *, 0xB0) = (s32) M2C_FIELD(&lit_818, s32 *, 0x74);
    M2C_FIELD(temp_r20_7241, s32 *, 0xB8) = (s32) M2C_FIELD(&lit_818, s32 *, 0x7C);
    M2C_FIELD(temp_r20_7241, s32 *, 0xC0) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 0);
    M2C_FIELD(temp_r20_7241, s32 *, 0xC4) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 4);
    M2C_FIELD(temp_r20_7241, s32 *, 0xC8) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 8);
    M2C_FIELD(temp_r20_7241, s32 *, 0xF8) = (s32) M2C_FIELD(&lit_818, s32 *, 0xB0);
    M2C_FIELD(temp_r20_7241, s32 *, 0xFC) = (s32) M2C_FIELD(&lit_818, s32 *, 0xB4);
    M2C_FIELD(temp_r20_7241, s32 *, 0x100) = (s32) M2C_FIELD(&lit_818, s32 *, 0xB8);
    M2C_FIELD(temp_r20_7241, s32 *, 0x104) = (s32) M2C_FIELD(&lit_818, s32 *, 0xBC);
    M2C_FIELD(temp_r20_7241, s32 *, 0x108) = (s32) M2C_FIELD(&lit_818, s32 *, 0xC0);
    M2C_FIELD(temp_r20_7241, s32 *, 0x10C) = (s32) M2C_FIELD(&lit_818, s32 *, 0xC4);
    M2C_FIELD(temp_r20_7241, s32 *, 0x110) = (s32) M2C_FIELD(&lit_818, s32 *, 0xC8);
    M2C_FIELD(temp_r20_7241, s32 *, 0x114) = (s32) M2C_FIELD(&lit_818, s32 *, 0xCC);
    M2C_FIELD(temp_r20_7241, s32 *, 0x118) = (s32) M2C_FIELD(&lit_818, s32 *, 0xD0);
    M2C_FIELD(temp_r20_7241, s32 *, 0x11C) = (s32) M2C_FIELD(&lit_818, s32 *, 0xD4);
    M2C_FIELD(temp_r20_7241, s32 *, 0x120) = (s32) M2C_FIELD(&lit_818, s32 *, 0xD8);
    M2C_FIELD(temp_r20_7241, s32 *, 0x124) = (s32) M2C_FIELD(&lit_818, s32 *, 0xDC);
    M2C_FIELD(temp_r20_7241, s32 *, 0x128) = (s32) M2C_FIELD(&lit_818, s32 *, 0xE0);
    M2C_FIELD(temp_r20_7241, s32 *, 0x12C) = (s32) M2C_FIELD(&lit_818, s32 *, 0xE4);
    M2C_FIELD(temp_r20_7241, s32 *, 0x130) = (s32) M2C_FIELD(&lit_818, s32 *, 0xE8);
    M2C_FIELD(temp_r20_7241, s32 *, 0x134) = (s32) M2C_FIELD(&lit_818, s32 *, 0xEC);
    M2C_FIELD(temp_r20_7241, s32 *, 0x138) = (s32) M2C_FIELD(&lit_818, s32 *, 0xF0);
    M2C_FIELD(temp_r20_7241, s32 *, 0x13C) = (s32) M2C_FIELD(&lit_818, s32 *, 0xF4);
    M2C_FIELD(temp_r20_7241, s32 *, 0x140) = (s32) M2C_FIELD(&lit_818, s32 *, 0xF8);
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_144lit_GetAttackerManager'
void SpeedWaySpyro::lit_144lit_GetAttackerManager() {
    ((SpeedWaySpyro *) (this - 0x90))->SpeedWaySpyro::GetAttackerManager();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_144lit_IsAttacking'
void SpeedWaySpyro::lit_144lit_IsAttacking() {
    ((SpeedWaySpyro *) (this - 0x90))->SpeedWaySpyro::IsAttacking();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_144lit_GetTimeLastHit'
void SpeedWaySpyro::lit_144lit_GetTimeLastHit() {
    ((SpeedWaySpyro *) (this - 0x90))->SpeedWaySpyro::GetTimeLastHit();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_144lit_GetCollisionHeight'
void SpeedWaySpyro::lit_144lit_GetCollisionHeight() {
    ((SpeedWaySpyro *) (this - 0x90))->SpeedWaySpyro::GetCollisionHeight();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_144lit_GetCollisionRadius'
void SpeedWaySpyro::lit_144lit_GetCollisionRadius() {
    ((SpeedWaySpyro *) (this - 0x90))->SpeedWaySpyro::GetCollisionRadius();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_144lit_GetCollisionInfo'
void SpeedWaySpyro::lit_144lit_GetCollisionInfo() {
    ((SpeedWaySpyro *) (this - 0x90))->SpeedWaySpyro::GetCollisionInfo();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_144lit_GetVel'
void SpeedWaySpyro::lit_144lit_GetVel() {
    SpeedWaySpyro::GetVel();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_144lit_GetAimPoint'
void SpeedWaySpyro::lit_144lit_GetAimPoint(const MKVector3 &arg0, MKVector3 *arg1) {
    ((SpeedWaySpyro *) (this - 0x90))->SpeedWaySpyro::GetAimPoint(arg0, arg1);
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_144lit_GetLookToPoint'
void SpeedWaySpyro::lit_144lit_GetLookToPoint(const MKVector3 &arg0, MKVector3 *arg1) {
    ((SpeedWaySpyro *) (this - 0x90))->SpeedWaySpyro::GetLookToPoint(arg0, arg1);
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_144lit_GetMoveToPoint'
void SpeedWaySpyro::lit_144lit_GetMoveToPoint(const MKVector3 &arg0, MKVector3 *arg1) {
    ((SpeedWaySpyro *) (this - 0x90))->SpeedWaySpyro::GetMoveToPoint(arg0, arg1);
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_144lit_IsDead'
void SpeedWaySpyro::lit_144lit_IsDead() {
    ((SpeedWaySpyro *) (this - 0x90))->SpeedWaySpyro::IsDead();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_144lit_IsShatterable'
void SpeedWaySpyro::lit_144lit_IsShatterable() {
    ((SpeedWaySpyro *) (this - 0x90))->SpeedWaySpyro::IsShatterable();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_144lit_IsEnemy'
void SpeedWaySpyro::lit_144lit_IsEnemy() {
    ((SpeedWaySpyro *) (this - 0x90))->SpeedWaySpyro::IsEnemy();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_144lit_IsFriend'
void SpeedWaySpyro::lit_144lit_IsFriend() {
    ((SpeedWaySpyro *) (this - 0x90))->SpeedWaySpyro::IsFriend();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_144lit_IsHero'
void SpeedWaySpyro::lit_144lit_IsHero() {
    ((SpeedWaySpyro *) (this - 0x90))->SpeedWaySpyro::IsHero();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_144lit_GetEnemy'
void SpeedWaySpyro::lit_144lit_GetEnemy() {
    ((SpeedWaySpyro *) (this - 0x90))->SpeedWaySpyro::GetEnemy();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_144lit_GetProp'
void SpeedWaySpyro::lit_144lit_GetProp() {
    ((SpeedWaySpyro *) (this - 0x90))->SpeedWaySpyro::GetProp();
}
#endif
