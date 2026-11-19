#include "spyro/source/SteamTrain.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKDynamicBone.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/EmbersPS.h"
#include "spyro/source/Explosion3.h"
#include "spyro/source/FlyingChunkPS.h"
#include "spyro/source/GameMessages.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/KDInput.h"
#include "spyro/source/KDParticleSystem.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/LightManager.h"
#include "spyro/source/ManagedLight.h"
#include "spyro/source/TrainChaseSpyro.h"
#include "spyro/source/TrainTrack.h"
#include "unplaced_templates.h"
#include "common/Source/StdMath.h"
#include "common/Source/Str.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/SpyroHud.h"
#include "spyro/source/Tools.h"
#include <m2c_macros.h>

f64 asin(f32);                                      /* extern */
extern s32 GS_CabooseExtra1;
extern s32 GS_Train4;
extern s32 GS_TrainEngineBreakLP;
extern s32 GS_TrainEngineLP;
extern s32 GS_TrainHit;
extern f32 SPYRO_BOUNCE_Y_SPEED;
extern f32 SPYRO_MIN_JUMP_Y_VELOCITY;
extern MKSceneManager *gMK;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern void **gb;
extern void *gpTranslation_StringArray;
#if 0 // DRAFT: illegal use of abstract class ('SteamTrain::pure_slot16()')
static M2C_UNK lit_743;                                /* unable to generate initializer: unknown type */
static SteamTrain states__10SteamTrain;             /* type too large by 0x320; unable to generate initializer: confusing struct layout */
static s8 *pSteamAnimEvents = "SteamPuff";
#endif

static s32 lit_1019 = 0;
static u8 lit_1020 = 1;

#if 0 // DRAFT: expression syntax error
void SteamTrain::Stop(bool arg0) {
    if (arg0 != 0) {
        this->unk378.SetState(this, 3, 0U);
        return;
    }
    this->unk378.SetState(this, 4, 0U);
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'float' to
void SteamTrain::StateRamUpdate() {
    f32 temp_f1_366;
    f32 temp_f1_463;
    f32 temp_f1_466;
    f32 temp_f1_474;
    f32 temp_f1_490;
    f32 temp_f1_514;
    f32 temp_f1_517;
    f32 temp_f2_342;
    f32 temp_f2_361;
    f32 temp_f2_449;
    f32 temp_f3_348;
    f32 temp_r3_681;
    f32 var_f0_369;
    f32 var_f0_477;
    f32 var_f0_491;
    f32 var_f2_455;
    f32 var_f2_506;
    s32 temp_r3_314;
    u8 temp_r0_344;
    void *temp_r3_339;
    void *temp_r3_687;
    if ((u8) M2C_FIELD(this, u8 *, 0x130) != 0) {
        this->unk38C -= gUpdateTimeDelta;
    }
    temp_r3_314 = checked_cast<TrainTrack *, MKProp>(((MKSceneManager *) (M2C_BITWISE(MKSceneManager *, this->unk120)))->PropResolver_Resolve(M2C_ERROR(/* Read from unset register $r4 */)));
    if (temp_r3_314 != 0) {
        arg_sp138.GetTrackZAxis(temp_r3_314, this->unk10C);
        arg_sp148 = arg_sp138;
        arg_sp150 = arg_sp140;
        if (!((((f32) arg_sp150 * (f32) arg_sp150) + (((f32) arg_sp148 * (f32) arg_sp148) + (arg_sp14C * arg_sp14C))) < 0.0001f)) {
            temp_r3_339 = checked_cast<TrainChaseSpyro *, MKProp>(this->unk128->PropResolver_Resolve(M2C_ERROR(/* Read from unset register $r4 */)));
            if (temp_r3_339 != NULL) {
                temp_f2_342 = M2C_FIELD(temp_r3_339, f32 *, 0xDC);
                temp_r0_344 = M2C_FIELD(this, u8 *, 0x130);
                temp_f3_348 = -((0.3f * (temp_f2_342 - M2C_FIELD(temp_r3_339, f32 *, 0xD8))) - temp_f2_342);
                if ((temp_r0_344 != 0) && (this->unk38C < 0.0f)) {
                    M2C_FIELD(this, u8 *, 0x130) = 0U;
                } else {
                    temp_f2_361 = M2C_FIELD(temp_r3_339, f32 *, 0xE0) - this->unk10C;
                    if (temp_f2_361 < 1000.0f) {
                        temp_f1_366 = temp_r3_314->GetTrackLength(1);
                        var_f0_369 = M2C_FIELD(temp_r3_339, f32 *, 0xE0) - 1000.0f;
                        if (var_f0_369 < temp_f1_366) {

                        } else {
                            var_f0_369 = temp_f1_366;
                        }
                        if (var_f0_369 > 0.0f) {

                        } else {
                            var_f0_369 = 0.0f;
                        }
                        this->unk10C = var_f0_369;
                        arg_sp70 = 0.0f;
                        arg_sp68 = 0.0f;
                        arg_sp6C = 0.0f;
                        arg_sp1A4 = 0;
                        arg_sp128 = (f64) arg_sp68;
                        arg_sp130 = (f64) arg_sp70;
                        arg_sp1A0 = 7;
                        arg_sp1C8 = 1;
                        arg_sp1CC = this;
                        arg_sp1A8 = (f64) arg_sp68;
                        arg_sp1B0 = (f64) arg_sp70;
                        arg_sp1E0 = 0;
                        arg_sp1EC = 2;
                        arg_sp1E8 = 10.0f;
                        arg_sp1E0 = 0;
                        (s16) arg_sp1E0 = 1;
                        arg_sp1E4 = -1;
                        arg_sp1B8 = M2C_FIELD(&MKVector3::one, f64 *, 0);
                        arg_sp1C0 = M2C_FIELD(&MKVector3::one, f64 *, 8);
                        arg_sp1F0 = 0;
                        if (this != NULL) {
                            arg_sp78.GetPos();
                            arg_sp1D0 = arg_sp78;
                            arg_sp1D8 = arg_sp80;
                        } else {
                            arg_sp1D0 = 0.0f;
                            arg_sp1D4 = 0.0f;
                            arg_sp1D8 = 0.0f;
                        }
                        arg_sp1F0 = 0;
                        M2C_FIELD(M2C_FIELD(temp_r3_339, void **, 0x44), M2C_UNK (**)(void *, s32 *), 0x2C)(temp_r3_339, &arg_sp1A0);
                        M2C_FIELD(this, u8 *, 0x130) = 1U;
                        this->unk38C = 0.7f;
                    } else if (temp_r0_344 != 0) {
                        temp_f2_449 = this->unk104;
                        this->unk104 = -((0.4f * temp_f2_449 * gUpdateTimeDelta) - temp_f2_449);
                        this->unk134.EmitBrakingEffects();
                        var_f2_455 = 0.25f;
                        if (1.0f > 0.25f) {

                        } else {
                            var_f2_455 = 1.0f;
                        }
                        temp_f1_463 = this->unk110;
                        temp_f1_466 = (var_f2_455 * (1.0f - temp_f1_463)) + temp_f1_463;
                        this->unk110 = (var_f2_455 * (1.0f - temp_f1_466)) + temp_f1_466;
                    } else {
                        temp_f1_474 = temp_f2_361 - 3000.0f;
                        if (temp_f1_474 > 0.0f) {
                            var_f0_477 = temp_f1_474 + temp_f3_348;
                        } else {
                            var_f0_477 = temp_f3_348;
                        }
                        this->unk104 = var_f0_477;
                        this->unk10C += this->unk104 * gUpdateTimeDelta;
                        temp_f1_490 = temp_r3_314->GetTrackLength(1);
                        var_f0_491 = this->unk10C;
                        if (var_f0_491 < temp_f1_490) {

                        } else {
                            var_f0_491 = temp_f1_490;
                        }
                        if (var_f0_491 > 0.0f) {

                        } else {
                            var_f0_491 = 0.0f;
                        }
                        this->unk10C = var_f0_491;
                        var_f2_506 = 0.25f;
                        if (1.0f > 0.25f) {

                        } else {
                            var_f2_506 = 1.0f;
                        }
                        temp_f1_514 = this->unk110;
                        temp_f1_517 = (var_f2_506 * (0.0f - temp_f1_514)) + temp_f1_514;
                        this->unk110 = (var_f2_506 * (0.0f - temp_f1_517)) + temp_f1_517;
                    }
                }
                if (this->unk10C < temp_r3_314->GetTrackLength(1)) {
                    M2C_STRUCT_COPY((s32) &arg_sp15C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
                    arg_sp118.GetTrackPos(temp_r3_314, this->unk10C, 1);
                    arg_sp190 = arg_sp118;
                    arg_sp194 = arg_sp11C;
                    arg_sp198 = arg_sp120;
                    arg_sp19C = 1.0f;
                    arg_sp108.GetTrackXAxis(temp_r3_314, this->unk10C);
                    arg_sp160 = arg_sp108;
                    arg_sp60 = ((f32) arg_sp148 * arg_sp10C) - (arg_sp14C * arg_sp108);
                    arg_sp58 = (arg_sp14C * arg_sp110) - ((f32) arg_sp150 * arg_sp10C);
                    arg_sp5C = ((f32) arg_sp150 * arg_sp108) - ((f32) arg_sp148 * arg_sp110);
                    arg_sp100 = (f64) arg_sp60;
                    arg_spF8 = (f64) arg_sp58;
                    arg_sp164 = arg_sp10C;
                    arg_sp168 = arg_sp110;
                    arg_sp16C = 0.0f;
                    arg_sp180 = (f32) arg_sp148;
                    arg_sp184 = arg_sp14C;
                    arg_sp188 = (f32) arg_sp150;
                    arg_sp18C = 0.0f;
                    arg_sp170 = (f32) arg_spF8;
                    arg_sp174 = arg_spFC;
                    arg_sp178 = (f32) arg_sp100;
                    arg_sp17C = 0.0f;
                    Normalise(*((MKVector3 *) &arg_spD8));
                    arg_sp16C = 0.0f;
                    arg_sp17C = 0.0f;
                    arg_sp50 = (arg_spD8 * arg_sp184) - (arg_spDC * arg_sp180);
                    arg_sp48 = (arg_spDC * arg_sp188) - (arg_spE0 * arg_sp184);
                    arg_sp4C = (arg_spE0 * arg_sp180) - (arg_spD8 * arg_sp188);
                    arg_spF0 = (f64) arg_sp50;
                    arg_spE8 = (f64) arg_sp48;
                    arg_sp160 = (f32) arg_spE8;
                    arg_sp164 = arg_spEC;
                    arg_sp168 = (f32) arg_spF0;
                    arg_sp40 = (arg_sp180 * arg_spEC) - (arg_sp184 * (f32) arg_spE8);
                    arg_sp38 = (arg_sp184 * (f32) arg_spF0) - (arg_sp188 * arg_spEC);
                    arg_sp3C = (arg_sp188 * (f32) arg_spE8) - (arg_sp180 * (f32) arg_spF0);
                    arg_spD0 = (f64) arg_sp40;
                    arg_spC8 = (f64) arg_sp38;
                    arg_sp170 = (f32) arg_spC8;
                    arg_sp174 = arg_spCC;
                    arg_sp178 = (f32) arg_spD0;
                    MKModel_SetWorldMatrix(this->unk4, *((Matrix *) &arg_sp160));
                    if (M2C_BITWISE(u32, this->unk38C) != 0U) {
                        arg_sp88.operator*(500.0f);
                        arg_sp98.operator*(500.0f);
                        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r27, 0x0, qr0 */);
                        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                        arg_spA8 = arg_sp18;
                        arg_sp20 = arg_sp198 + arg_spA0;
                        arg_spB0 = (f64) arg_sp20;
                        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                        temp_r3_681 = this->unk38C;
                        arg_spB8 = arg_sp28;
                        arg_sp30 = (f32) arg_spB0 + arg_sp90;
                        M2C_FIELD(temp_r3_681, f64 *, 0x10) = arg_sp28;
                        M2C_FIELD(temp_r3_681, f64 *, 0x18) = (f64) arg_sp30;
                        temp_r3_687 = M2C_FIELD(temp_r3_681, void **, 0x3C);
                        arg_spC0 = (f64) arg_sp30;
                        if (temp_r3_687 != NULL) {
                            M2C_FIELD(temp_r3_687, f64 *, 0x10) = arg_sp28;
                            M2C_FIELD(temp_r3_687, f64 *, 0x18) = (f64) arg_sp30;
                        }
                    }
                } else {
                    arg_sp14 = 0;
                    arg_sp10 = 0xB4;
                    Message(&arg_sp10);
                }
                this->unk134.EmitSteam();
                M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
                M2C_FIELD(this, s8 *, 0x3EC) = (s8) ((this->unk10C - M2C_FIELD(temp_r3_339, f32 *, 0xE0)) == 4500.0f);
            }
        }
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'float' to
void SteamTrain::StateChaseExit() {
    f32 temp_r4_734;

    temp_r4_734 = this->unk38C;
    if (M2C_BITWISE(u32, temp_r4_734) != 0U) {
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->FreeManagedLight(M2C_BITWISE(ManagedLight *, temp_r4_734));
        this->unk38C = 0.0f;
    }
    this->unk38C = 0.0f;
    M2C_FIELD(this, s8 *, 0x130) = 0;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'float' to
void SteamTrain::StateChaseUpdate() {
    f32 temp_f1_799;
    f32 temp_f1_822;
    f32 temp_r3_998;
    f32 var_f0_823;
    s32 temp_r3_768;
    void *temp_r3_1004;
    void *temp_r3_793;
    temp_r3_768 = checked_cast<TrainTrack *, MKProp>(((MKSceneManager *) (M2C_BITWISE(MKSceneManager *, this->unk120)))->PropResolver_Resolve(M2C_ERROR(/* Read from unset register $r4 */)));
    if (temp_r3_768 != 0) {
        arg_sp108.GetTrackZAxis(temp_r3_768, this->unk10C);
        arg_sp118 = arg_sp108;
        arg_sp120 = arg_sp110;
        if (!((((f32) arg_sp120 * (f32) arg_sp120) + (((f32) arg_sp118 * (f32) arg_sp118) + (arg_sp11C * arg_sp11C))) < 0.0001f)) {
            temp_r3_793 = checked_cast<TrainChaseSpyro *, MKProp>(this->unk128->PropResolver_Resolve(M2C_ERROR(/* Read from unset register $r4 */)));
            if (temp_r3_793 != NULL) {
                temp_f1_799 = M2C_FIELD(temp_r3_793, f32 *, 0xE0) - this->unk10C;
                if (temp_f1_799 < 1000.0f) {
                    this->unk378.SetState(this, 5, 0U);
                } else {
                    this->unk100 = temp_f1_799;
                    this->unk104 += M2C_BITWISE(f32, this->unk100) * gUpdateTimeDelta;
                    this->unk10C += this->unk104 * gUpdateTimeDelta;
                    temp_f1_822 = temp_r3_768->GetTrackLength(1);
                    var_f0_823 = this->unk10C;
                    if (var_f0_823 < temp_f1_822) {

                    } else {
                        var_f0_823 = temp_f1_822;
                    }
                    if (var_f0_823 > 0.0f) {

                    } else {
                        var_f0_823 = 0.0f;
                    }
                    this->unk10C = var_f0_823;
                }
                if (this->unk10C < temp_r3_768->GetTrackLength(1)) {
                    M2C_STRUCT_COPY((s32) &arg_sp12C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
                    arg_spF8.GetTrackPos(temp_r3_768, this->unk10C, 1);
                    arg_sp160 = arg_spF8;
                    arg_sp164 = arg_spFC;
                    arg_sp168 = arg_sp100;
                    arg_sp16C = 1.0f;
                    arg_spE8.GetTrackXAxis(temp_r3_768, this->unk10C);
                    arg_sp130 = arg_spE8;
                    arg_sp60 = ((f32) arg_sp118 * arg_spEC) - (arg_sp11C * arg_spE8);
                    arg_sp58 = (arg_sp11C * arg_spF0) - ((f32) arg_sp120 * arg_spEC);
                    arg_sp5C = ((f32) arg_sp120 * arg_spE8) - ((f32) arg_sp118 * arg_spF0);
                    arg_spE0 = (f64) arg_sp60;
                    arg_spD8 = (f64) arg_sp58;
                    arg_sp134 = arg_spEC;
                    arg_sp138 = arg_spF0;
                    arg_sp13C = 0.0f;
                    arg_sp150 = (f32) arg_sp118;
                    arg_sp154 = arg_sp11C;
                    arg_sp158 = (f32) arg_sp120;
                    arg_sp15C = 0.0f;
                    arg_sp140 = (f32) arg_spD8;
                    arg_sp144 = arg_spDC;
                    arg_sp148 = (f32) arg_spE0;
                    arg_sp14C = 0.0f;
                    Normalise(*((MKVector3 *) &arg_spB8));
                    arg_sp13C = 0.0f;
                    arg_sp14C = 0.0f;
                    arg_sp50 = (arg_spB8 * arg_sp154) - (arg_spBC * arg_sp150);
                    arg_sp48 = (arg_spBC * arg_sp158) - (arg_spC0 * arg_sp154);
                    arg_sp4C = (arg_spC0 * arg_sp150) - (arg_spB8 * arg_sp158);
                    arg_spD0 = (f64) arg_sp50;
                    arg_spC8 = (f64) arg_sp48;
                    arg_sp130 = (f32) arg_spC8;
                    arg_sp134 = arg_spCC;
                    arg_sp138 = (f32) arg_spD0;
                    arg_sp40 = (arg_sp150 * arg_spCC) - (arg_sp154 * (f32) arg_spC8);
                    arg_sp38 = (arg_sp154 * (f32) arg_spD0) - (arg_sp158 * arg_spCC);
                    arg_sp3C = (arg_sp158 * (f32) arg_spC8) - (arg_sp150 * (f32) arg_spD0);
                    arg_spB0 = (f64) arg_sp40;
                    arg_spA8 = (f64) arg_sp38;
                    arg_sp140 = (f32) arg_spA8;
                    arg_sp144 = arg_spAC;
                    arg_sp148 = (f32) arg_spB0;
                    MKModel_SetWorldMatrix(this->unk4, *((Matrix *) &arg_sp130));
                    if (M2C_BITWISE(u32, this->unk38C) != 0U) {
                        arg_sp68.operator*(500.0f);
                        arg_sp78.operator*(500.0f);
                        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r27, 0x0, qr0 */);
                        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                        arg_sp88 = arg_sp18;
                        arg_sp20 = arg_sp168 + arg_sp80;
                        arg_sp90 = (f64) arg_sp20;
                        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                        temp_r3_998 = this->unk38C;
                        arg_sp98 = arg_sp28;
                        arg_sp30 = (f32) arg_sp90 + arg_sp70;
                        M2C_FIELD(temp_r3_998, f64 *, 0x10) = arg_sp28;
                        M2C_FIELD(temp_r3_998, f64 *, 0x18) = (f64) arg_sp30;
                        temp_r3_1004 = M2C_FIELD(temp_r3_998, void **, 0x3C);
                        arg_spA0 = (f64) arg_sp30;
                        if (temp_r3_1004 != NULL) {
                            M2C_FIELD(temp_r3_1004, f64 *, 0x10) = arg_sp28;
                            M2C_FIELD(temp_r3_1004, f64 *, 0x18) = (f64) arg_sp30;
                        }
                    }
                } else {
                    arg_sp14 = 0;
                    arg_sp10 = 0xB4;
                    Message(&arg_sp10);
                }
                this->unk134.EmitSteam();
                M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
                M2C_FIELD(this, s8 *, 0x3EC) = (s8) ((this->unk10C - M2C_FIELD(temp_r3_793, f32 *, 0xE0)) == 4500.0f);
            }
        }
    }
}
#endif

void SteamTrain::StateChaseEnter() {
    this->unk110 = 0.0f;
}

void SteamTrain::StateFallBackExit() {

}

#if 0 // DRAFT: illegal explicit conversion from 'float' to
void SteamTrain::StateFallBackUpdate() {
    f32 temp_f2_1075;
    f32 temp_f2_1089;
    f32 temp_f2_1093;
    f32 temp_f2_1097;
    f32 temp_r3_1267;
    f32 var_f3_1081;
    s32 temp_r3_1070;
    void *temp_r3_1273;
    void *temp_r3_1282;
    temp_r3_1070 = checked_cast<TrainTrack *, MKProp>(((MKSceneManager *) (M2C_BITWISE(MKSceneManager *, this->unk120)))->PropResolver_Resolve(M2C_ERROR(/* Read from unset register $r4 */)));
    if (temp_r3_1070 != 0) {
        temp_f2_1075 = this->unk104;
        this->unk104 = -((0.8f * temp_f2_1075 * gUpdateTimeDelta) - temp_f2_1075);
        this->unk134.EmitBrakingEffects();
        var_f3_1081 = 0.25f;
        if (1.0f > 0.25f) {

        } else {
            var_f3_1081 = 1.0f;
        }
        temp_f2_1089 = this->unk110;
        temp_f2_1093 = (var_f3_1081 * (1.0f - temp_f2_1089)) + temp_f2_1089;
        this->unk110 = (var_f3_1081 * (1.0f - temp_f2_1093)) + temp_f2_1093;
        temp_f2_1097 = this->unk104;
        if (temp_f2_1097 > 0.0f) {
            this->unk10C += temp_f2_1097 * gUpdateTimeDelta;
        }
        M2C_STRUCT_COPY((s32) &arg_sp10C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
        arg_sp100.GetTrackPos(temp_r3_1070, this->unk10C, 1);
        arg_sp140 = arg_sp100;
        arg_sp144 = arg_sp104;
        arg_sp148 = arg_sp108;
        arg_sp14C = 1.0f;
        arg_spF0.GetTrackXAxis(temp_r3_1070, this->unk10C);
        arg_sp110 = arg_spF0;
        arg_sp114 = arg_spF4;
        arg_sp118 = arg_spF8;
        arg_sp11C = 0.0f;
        arg_spE0.GetTrackZAxis(temp_r3_1070, this->unk10C);
        arg_sp130 = arg_spE0;
        arg_sp134 = arg_spE4;
        arg_sp50 = (arg_spE4 * arg_sp118) - (arg_spE8 * arg_sp114);
        arg_sp54 = (arg_spE8 * arg_sp110) - (arg_spE0 * arg_sp118);
        arg_sp58 = (arg_spE0 * arg_sp114) - (arg_spE4 * arg_sp110);
        arg_spD0 = (f64) arg_sp50;
        arg_spD8 = (f64) arg_sp58;
        arg_sp138 = arg_spE8;
        arg_sp13C = 0.0f;
        arg_sp120 = (f32) arg_spD0;
        arg_sp124 = arg_spD4;
        arg_sp128 = (f32) arg_spD8;
        arg_sp12C = 0.0f;
        Normalise(*((MKVector3 *) &arg_spB0));
        arg_sp11C = 0.0f;
        arg_sp12C = 0.0f;
        arg_sp48 = (arg_spB0 * arg_sp134) - (arg_spB4 * arg_sp130);
        arg_sp40 = (arg_spB4 * arg_sp138) - (arg_spB8 * arg_sp134);
        arg_sp44 = (arg_spB8 * arg_sp130) - (arg_spB0 * arg_sp138);
        arg_spC8 = (f64) arg_sp48;
        arg_spC0 = (f64) arg_sp40;
        arg_sp110 = (f32) arg_spC0;
        arg_sp114 = arg_spC4;
        arg_sp118 = (f32) arg_spC8;
        arg_sp38 = (arg_sp130 * arg_spC4) - (arg_sp134 * (f32) arg_spC0);
        arg_sp30 = (arg_sp134 * (f32) arg_spC8) - (arg_sp138 * arg_spC4);
        arg_sp34 = (arg_sp138 * (f32) arg_spC0) - (arg_sp130 * (f32) arg_spC8);
        arg_spA8 = (f64) arg_sp38;
        arg_spA0 = (f64) arg_sp30;
        arg_sp120 = (f32) arg_spA0;
        arg_sp124 = arg_spA4;
        arg_sp128 = (f32) arg_spA8;
        MKModel_SetWorldMatrix(this->unk4, *((Matrix *) &arg_sp110));
        if (M2C_BITWISE(u32, this->unk38C) != 0U) {
            arg_sp60.operator*(500.0f);
            arg_sp70.operator*(500.0f);
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r28, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            arg_sp80 = arg_sp10;
            arg_sp18 = arg_sp148 + arg_sp78;
            arg_sp88 = (f64) arg_sp18;
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            temp_r3_1267 = this->unk38C;
            arg_sp90 = arg_sp20;
            arg_sp28 = (f32) arg_sp88 + arg_sp68;
            M2C_FIELD(temp_r3_1267, f64 *, 0x10) = arg_sp20;
            M2C_FIELD(temp_r3_1267, f64 *, 0x18) = (f64) arg_sp28;
            temp_r3_1273 = M2C_FIELD(temp_r3_1267, void **, 0x3C);
            arg_sp98 = (f64) arg_sp28;
            if (temp_r3_1273 != NULL) {
                M2C_FIELD(temp_r3_1273, f64 *, 0x10) = arg_sp20;
                M2C_FIELD(temp_r3_1273, f64 *, 0x18) = (f64) arg_sp28;
            }
        }
        temp_r3_1282 = checked_cast<TrainChaseSpyro *, MKProp>(this->unk128->PropResolver_Resolve(M2C_ERROR(/* Read from unset register $r4 */)));
        if (temp_r3_1282 != NULL) {
            M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
            M2C_FIELD(this, s8 *, 0x3EC) = (s8) ((this->unk10C - M2C_FIELD(temp_r3_1282, f32 *, 0xE0)) == 4500.0f);
        }
    }
}
#endif

void SteamTrain::StateFallBackEnter() {

}

void SteamTrain::StateFleeExit() {

}

#if 0 // DRAFT: illegal explicit conversion from 'float' to
void SteamTrain::StateFleeUpdate() {
    f32 temp_f1_1436;
    f32 temp_f1_1439;
    f32 temp_f1_1460;
    f32 temp_f1_1463;
    f32 temp_f1_1479;
    f32 temp_f2_1422;
    f32 temp_f4_1379;
    f32 temp_r3_1643;
    f32 var_f1_1349;
    f32 var_f1_1394;
    f32 var_f2_1378;
    f32 var_f2_1428;
    f32 var_f2_1452;
    f32 var_f31_1343;
    s32 temp_r3_1330;
    void *temp_r3_1373;
    void *temp_r3_1649;
    temp_r3_1330 = checked_cast<TrainTrack *, MKProp>(((MKSceneManager *) (M2C_BITWISE(MKSceneManager *, this->unk120)))->PropResolver_Resolve(M2C_ERROR(/* Read from unset register $r4 */)));
    if (temp_r3_1330 != 0) {
        arg_sp100.GetTrackZAxis(temp_r3_1330, this->unk10C);
        arg_sp110 = arg_sp100;
        var_f31_1343 = 1.0f;
        arg_sp118 = arg_sp108;
        if (((u8) M2C_FIELD(this, u8 *, 0x3ED) == 0) && ((u8) M2C_FIELD(this, u8 *, 0x3EE) == 0)) {
            var_f1_1349 = arg_sp114;
            if (var_f1_1349 < 1.0f) {

            } else {
                var_f1_1349 = 1.0f;
            }
            if (var_f1_1349 > -1.0f) {

            } else {
                var_f1_1349 = -1.0f;
            }
            var_f31_1343 = (0.5f * ((f32) asin(var_f1_1349) / 1.5707964f)) + 1.0f;
        }
        temp_r3_1373 = checked_cast<TrainChaseSpyro *, MKProp>(this->unk128->PropResolver_Resolve(M2C_ERROR(/* Read from unset register $r4 */)));
        if (temp_r3_1373 != NULL) {
            var_f2_1378 = 0.0f;
            temp_f4_1379 = this->unk10C - M2C_FIELD(temp_r3_1373, f32 *, 0xE0);
            if (var_f2_1378 > temp_f4_1379) {

            } else {
                var_f2_1378 = temp_f4_1379;
            }
            this->unk100 = 2000.0f * (1.0f - (var_f2_1378 / this->unk11C));
            var_f1_1394 = M2C_BITWISE(f32, this->unk100);
            if (var_f1_1394 < 2000.0f) {

            } else {
                var_f1_1394 = 2000.0f;
            }
            if (var_f1_1394 > -500.0f) {

            } else {
                var_f1_1394 = -500.0f;
            }
            this->unk100 = var_f1_1394;
            if (temp_f4_1379 < 0.0f) {
                var_f31_1343 += 0.15f;
            }
            if ((u8) M2C_FIELD(this, u8 *, 0x130) != 0) {
                M2C_FIELD(this, u8 *, 0x130) = 0U;
                temp_f2_1422 = this->unk104;
                this->unk104 = -((0.8f * temp_f2_1422 * gUpdateTimeDelta) - temp_f2_1422);
                this->unk134.EmitBrakingEffects();
                var_f2_1428 = 0.25f;
                if (1.0f > 0.25f) {

                } else {
                    var_f2_1428 = 1.0f;
                }
                temp_f1_1436 = this->unk110;
                temp_f1_1439 = (var_f2_1428 * (1.0f - temp_f1_1436)) + temp_f1_1436;
                this->unk110 = (var_f2_1428 * (1.0f - temp_f1_1439)) + temp_f1_1439;
            } else {
                this->unk104 += M2C_BITWISE(f32, this->unk100) * gUpdateTimeDelta;
                this->unk134.EmitSteam();
                var_f2_1452 = 0.25f;
                if (1.0f > 0.25f) {

                } else {
                    var_f2_1452 = 1.0f;
                }
                temp_f1_1460 = this->unk110;
                temp_f1_1463 = (var_f2_1452 * (0.0f - temp_f1_1460)) + temp_f1_1460;
                this->unk110 = (var_f2_1452 * (0.0f - temp_f1_1463)) + temp_f1_1463;
            }
            if (((u8) M2C_FIELD(this, u8 *, 0x131) == 0) || !((this->unk10C - M2C_FIELD(temp_r3_1373, f32 *, 0xE0)) < 6000.0f)) {
                temp_f1_1479 = this->unk108;
                if (this->unk104 > temp_f1_1479) {
                    this->unk104 = temp_f1_1479;
                }
            }
            this->unk10C += gUpdateTimeDelta * (this->unk104 * var_f31_1343);
            M2C_STRUCT_COPY((s32) &arg_sp11C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
            arg_spF0.GetTrackPos(temp_r3_1330, this->unk10C, 1);
            arg_sp150 = arg_spF0;
            arg_sp154 = arg_spF4;
            arg_sp158 = arg_spF8;
            arg_sp15C = 1.0f;
            arg_spE0.GetTrackXAxis(temp_r3_1330, this->unk10C);
            arg_sp120 = arg_spE0;
            arg_sp58 = ((f32) arg_sp110 * arg_spE4) - (arg_sp114 * arg_spE0);
            arg_sp50 = (arg_sp114 * arg_spE8) - ((f32) arg_sp118 * arg_spE4);
            arg_sp54 = ((f32) arg_sp118 * arg_spE0) - ((f32) arg_sp110 * arg_spE8);
            arg_spD8 = (f64) arg_sp58;
            arg_spD0 = (f64) arg_sp50;
            arg_sp124 = arg_spE4;
            arg_sp128 = arg_spE8;
            arg_sp12C = 0.0f;
            arg_sp140 = (f32) arg_sp110;
            arg_sp144 = arg_sp114;
            arg_sp148 = (f32) arg_sp118;
            arg_sp14C = 0.0f;
            arg_sp130 = (f32) arg_spD0;
            arg_sp134 = arg_spD4;
            arg_sp138 = (f32) arg_spD8;
            arg_sp13C = 0.0f;
            Normalise(*((MKVector3 *) &arg_spB0));
            arg_sp12C = 0.0f;
            arg_sp13C = 0.0f;
            arg_sp48 = (arg_spB0 * arg_sp144) - (arg_spB4 * arg_sp140);
            arg_sp40 = (arg_spB4 * arg_sp148) - (arg_spB8 * arg_sp144);
            arg_sp44 = (arg_spB8 * arg_sp140) - (arg_spB0 * arg_sp148);
            arg_spC8 = (f64) arg_sp48;
            arg_spC0 = (f64) arg_sp40;
            arg_sp120 = (f32) arg_spC0;
            arg_sp124 = arg_spC4;
            arg_sp128 = (f32) arg_spC8;
            arg_sp38 = (arg_sp140 * arg_spC4) - (arg_sp144 * (f32) arg_spC0);
            arg_sp30 = (arg_sp144 * (f32) arg_spC8) - (arg_sp148 * arg_spC4);
            arg_sp34 = (arg_sp148 * (f32) arg_spC0) - (arg_sp140 * (f32) arg_spC8);
            arg_spA8 = (f64) arg_sp38;
            arg_spA0 = (f64) arg_sp30;
            arg_sp130 = (f32) arg_spA0;
            arg_sp134 = arg_spA4;
            arg_sp138 = (f32) arg_spA8;
            MKModel_SetWorldMatrix(this->unk4, *((Matrix *) &arg_sp120));
            if (M2C_BITWISE(u32, this->unk38C) != 0U) {
                arg_sp60.operator*(500.0f);
                arg_sp70.operator*(500.0f);
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r27, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                arg_sp80 = arg_sp10;
                arg_sp18 = arg_sp158 + arg_sp78;
                arg_sp88 = (f64) arg_sp18;
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                temp_r3_1643 = this->unk38C;
                arg_sp90 = arg_sp20;
                arg_sp28 = (f32) arg_sp88 + arg_sp68;
                M2C_FIELD(temp_r3_1643, f64 *, 0x10) = arg_sp20;
                M2C_FIELD(temp_r3_1643, f64 *, 0x18) = (f64) arg_sp28;
                temp_r3_1649 = M2C_FIELD(temp_r3_1643, void **, 0x3C);
                arg_sp98 = (f64) arg_sp28;
                if (temp_r3_1649 != NULL) {
                    M2C_FIELD(temp_r3_1649, f64 *, 0x10) = arg_sp20;
                    M2C_FIELD(temp_r3_1649, f64 *, 0x18) = (f64) arg_sp28;
                }
            }
            M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
            M2C_FIELD(this, s8 *, 0x3EC) = (s8) ((this->unk10C - M2C_FIELD(temp_r3_1373, f32 *, 0xE0)) == 4500.0f);
        }
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'void *' to
void SteamTrain::StateFleeEnter() {
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
    f32 temp_r4_1724;

    if (M2C_BITWISE(u32, this->unk38C) == 0U) {
        sp20 = 0.0f;
        sp30 = 0.0f;
        sp8 = 1.0f;
        spC = 0.75f;
        sp10 = 0.2f;
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
        this->unk38C = M2C_BITWISE(f32, ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->AllocManagedLight(*((MKVector3 *) &sp58), *((MKVector3 *) &sp48), *((MKVector4 *) &sp38), 1500.0f, lit_1019, lit_1020));
        temp_r4_1724 = this->unk38C;
        if (M2C_BITWISE(u32, temp_r4_1724) != 0U) {
            ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->EnableLight(M2C_BITWISE(ManagedLight *, temp_r4_1724), 1U);
        }
    }
}
#endif

#if 0 // DRAFT: expression syntax error
void SteamTrain::Message(MKMessage *arg0) {
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
    f32 sp30;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    SteamTrain *var_r0_1945;
    f32 temp_f1_1870;
    f32 temp_f1_1913;
    f64 temp_f4_1818;
    f64 temp_f5_1817;
    s32 temp_r0_1752;
    s32 temp_r31_1930;
    void *temp_r3_1814;
    void *temp_r3_1943;
    void *temp_r4_1815;

    this->unk390.Message(arg0);
    this->unk3BC.Message(arg0);
    temp_r0_1752 = arg0->unk0;
    switch (temp_r0_1752) {                         /* irregular */
    case 0xB5:
        Enable();
        this->unk378.SetState(this, 2, 0U);
        this->unk3EC = 1;
    default:
block_30:
        GameProp::Message(arg0);
        return;
    case 0xB4:
        this->unk378.SetState(this, 1, 0U);
        this->unk3EC = 0;
        Disable();
        EnemyHud_Modified(NULL, 0.0f, 0.0f, 0.0f);
        goto block_30;
    case 0x5:
        temp_r3_1814 = checked_cast<BreathHitMessage *, MKMessage>(arg0);
        temp_r4_1815 = this->unk8;
        temp_f5_1817 = M2C_FIELD(temp_r4_1815, f64 *, 0x30);
        temp_f4_1818 = M2C_FIELD(temp_r4_1815, f64 *, 0x38);
        sp58 = temp_f5_1817;
        sp60 = temp_f4_1818;
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $r3, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
        sp68 = sp28;
        sp30 = M2C_FIELD(temp_r3_1814, f32 *, 0x18) - (f32) sp60;
        sp70 = (f64) sp30;
        if ((((f32) sp70 * (f32) sp70) + (((f32) sp68 * (f32) sp68) + (unksp6C * unksp6C))) < 1000000.0f) {
            sp18 = 0.0f;
            sp1C = 500.0f;
            sp20 = 0.0f;
            sp38 = (f64) sp18;
            sp48 = temp_f5_1817;
            sp40 = (f64) sp20;
            sp50 = temp_f4_1818;
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            sp78 = sp8;
            sp10 = (f32) sp50 + (f32) sp40;
            sp80 = (f64) sp10;
            TriggerDamageFX(*((MKVector3 *) &sp78), 1.0f);
            temp_f1_1870 = this->unk3E4;
            this->unk3E4 = temp_f1_1870 - 1.0f;
            if (this->unk3E4 < 1.0f) {
                this->unk3E4 = 1.0f;
            }
            EnemyHud_Modified((MKProp *) this, temp_f1_1870, this->unk3E4, 50.0f);
        }
        goto block_30;
    case 0x7:
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if (this->unk114 == 0.0f) {
            this->unk114 = 0.75f;
            KDSound_Play3d(GS_TrainHit, this->unk8 + 0x30, 0U, -1, 0.0f, 0U);
            ((KDInput *) (M2C_FIELD(*gb, KDInput *(**)(void **), 0x40)(gb)))->RumblePlay(0.99f, 0.8f, 0.15f, 0, 4.0f, 0U);
            temp_f1_1913 = this->unk3E4;
            this->unk3E4 = temp_f1_1913 - 1.0f;
            if (this->unk3E4 < 1.0f) {
                this->unk3E4 = 1.0f;
            }
            EnemyHud_Modified((MKProp *) this, temp_f1_1913, this->unk3E4, 50.0f);
        }
        goto block_30;
    case 0x8D:
        temp_r31_1930 = M2C_FIELD(gpTranslation_StringArray, s32 *, 0x324);
        M2C_FIELD(checked_cast<GetNameMsg *, MKMessage>(arg0), s32 *, 8) = temp_r31_1930;
        return;
    case 0x14A:
        this->unk378.SetState(this, 2, 0U);
        goto block_30;
    case 0x8E:
        temp_r3_1943 = checked_cast<GetTargetableMsg *, MKMessage>(arg0);
        var_r0_1945 = this;
        if (this != NULL) {
            var_r0_1945 = (SteamTrain *) &this->unkC8;
        }
        M2C_FIELD(temp_r3_1943, SteamTrain **, 8) = var_r0_1945;
        return;
    }
}
#endif

#if 0 // DRAFT: expression syntax error
void SteamTrain::Deinit() {
    MKMaterial *temp_r3_1984;
    f32 temp_r4_1974;

    this->unk378.Deinit(this);
    temp_r4_1974 = this->unk38C;
    if (M2C_BITWISE(u32, temp_r4_1974) != 0U) {
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->FreeManagedLight(M2C_BITWISE(ManagedLight *, temp_r4_1974));
        this->unk38C = 0.0f;
    }
    temp_r3_1984 = this->unk100;
    if (temp_r3_1984 != NULL) {
        MKMaterial_Destroy(temp_r3_1984);
        this->unk100 = NULL;
    }
    this->unkD0.Deinit();
    KDSound_Stop((s32 *) &this->unk390);
    KDSound_Stop(&this->unk3BC);
    M2C_FIELD(this, s8 *, 0x3EF) = 0;
    this->unk3EC = 0;
    GameProp::Deinit();
}
#endif

#if 0 // DRAFT: expression syntax error
void SteamTrain::Draw() {
    GameProp::Draw();
    this->unk134.Draw();
}
#endif

#if 0 // DRAFT: function call 'MKRand_Float(long *, float, float)' does not match
void SteamTrain::TriggerDamageFX(const MKVector3 &arg0, float arg1) {
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
    f32 spA0;
    f32 sp9C;
    f32 sp98;
    f32 sp90;
    f32 sp80;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp60;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp40;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f1_2192;
    f32 temp_f23_2071;
    f32 temp_f23_2134;
    f32 temp_f23_2161;
    f32 temp_f24_2066;
    f32 temp_f24_2129;
    f32 temp_f24_2166;
    s32 var_r30_2060;

    var_r30_2060 = 0;
    do {
        temp_f24_2066 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        temp_f23_2071 = MKRand_Float(&gViewSeed, 1.0f, 3.0f);
        sp98 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        sp9C = temp_f23_2071;
        spA0 = temp_f24_2066;
        sp118 = (f64) sp98;
        sp120 = (f64) spA0;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
        sp128 = sp88;
        sp90 = (f32) sp120 * 1600.0f;
        sp130 = (f64) sp90;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f26 */);
        sp68 = 0.0f;
        sp6C = 300.0f;
        sp80 = (f32) sp130 * arg1;
        sp70 = 0.0f;
        sp138 = sp78;
        sp140 = (f64) sp80;
        spF8 = (f64) sp68;
        sp100 = (f64) sp70;
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r4, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        sp108 = sp58;
        sp60 = M2C_FIELD((this->unk8 + 0x30), f32 *, 8) + (f32) sp100;
        sp110 = (f64) sp60;
        temp_f24_2129 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        temp_f23_2134 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        sp48 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        sp4C = temp_f23_2134;
        sp50 = temp_f24_2129;
        spD8 = (f64) sp48;
        spE0 = (f64) sp50;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f28 */);
        spE8 = sp38;
        sp40 = (f32) spE0 * 3.1415927f;
        spF0 = (f64) sp40;
        temp_f23_2161 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        temp_f24_2166 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        sp28 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        sp2C = temp_f24_2166;
        sp30 = temp_f23_2161;
        spB8 = (f64) sp28;
        spC0 = (f64) sp30;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f27 */);
        spC8 = sp18;
        sp20 = (f32) spC0 * 3.1415927f;
        spD0 = (f64) sp20;
        temp_f1_2192 = MKRand_Float(&gViewSeed, 0.75f, 1.0f);
        sp8 = 1.0f;
        spC = 1.0f;
        sp10 = 1.0f;
        sp14 = 1.0f;
        spA8 = (f64) sp8;
        spB0 = (f64) sp10;
        ((FlyingChunkPS *) (M2C_FIELD(&gb, FlyingChunkPS **, 0xA0)))->Emit(*((MKVector3 *) &sp108), *((MKVector3 *) &sp138), *((MKVector3 *) &spE8), *((MKVector3 *) &spC8), arg1 * temp_f1_2192, *((MKVector4 *) &spA8), 0, NULL);
        var_r30_2060 += 1;
    } while (var_r30_2060 < 0xA);
    M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
    if (this->unk118 == 0.0f) {
        this->unk118 = 1.0f;
        KDSound_Play3d(GS_CabooseExtra1, &arg0, 0U, -1, 0.0f, 0U);
    }
}
#endif

#if 0 // DRAFT: expression syntax error
void SteamTrain::Update() {
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f64 sp18;
    f64 sp10;
    s32 sp8;
    f32 temp_f1_2272;
    f32 temp_f1_2280;
    f32 temp_f1_2291;
    f32 temp_f2_2315;
    f32 temp_f2_2355;
    void *temp_r3_2382;

    GameProp::Update();
    this->unk378.Update(this, 0);
    this->unk138.unk22C = this->unk104;
    this->unk138.unk230 = this->unk108;
    this->unk134.Update();
    temp_f1_2272 = this->unk114;
    if (temp_f1_2272 > 0.0f) {
        this->unk114 = temp_f1_2272 - gUpdateTimeDelta;
    }
    temp_f1_2280 = this->unk118;
    if (temp_f1_2280 > 0.0f) {
        this->unk118 = temp_f1_2280 - gUpdateTimeDelta;
    }
    if ((u8) M2C_FIELD(this, u8 *, 0x3EC) != 0) {
        temp_f1_2291 = this->unk3E4;
        M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
        if (temp_f1_2291 == 15.0f) {
            this->unk3E4 = 0.0f;
            KDSound_Play3d(GS_Train4, this->unk8 + 0x30, 0U, -1, 0.0f, 0U);
        } else {
            this->unk3E4 = temp_f1_2291 + gUpdateTimeDelta;
        }
    } else {
        this->unk3E4 = 0.0f;
    }
    temp_f2_2315 = this->unk110;
    M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
    if (temp_f2_2315 == 0.01f) {
        MKMaterial_SetParameter(this->unk100, (MKMaterialParameter) 6, 1);
        M2C_FIELD(this, u8 *, 0x3EF) = 0U;
    } else {
        sp20 = temp_f2_2315;
        sp24 = 0.0f;
        sp28 = 0.0f;
        sp2C = 1.0f;
        MKMaterial_SetColor(this->unk100, *((MKVector4 *) &sp20));
        MKMaterial_SetParameter(this->unk100, (MKMaterialParameter) 6, 0);
        M2C_FIELD(this, u8 *, 0x3EF) = 1U;
    }
    sp8 = 1;
    this->unk390.Update(GS_TrainEngineBreakLP, 1U, M2C_FIELD(this, u8 *, 0x3EF), (MKProp *) this, NULL, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    temp_f2_2355 = this->unk104;
    M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
    if (temp_f2_2355 == 1800.0f) {
        KDSound_SetPitch(this->unk3BC, 0.9f);
    } else {
        KDSound_SetPitch(this->unk3BC, (0.000025f * temp_f2_2355) + 0.98f);
    }
    sp8 = 1;
    this->unk3BC.Update(GS_TrainEngineLP, 1U, this->unk3EC, (MKProp *) this, NULL, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    temp_r3_2382 = this->unk8;
    sp10 = M2C_FIELD(temp_r3_2382, f64 *, 0x30);
    sp18 = M2C_FIELD(temp_r3_2382, f64 *, 0x38);
    this->unkD0.unk28 = unksp14;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'float' to
void SteamTrain::Reset() {
    void *temp_r3_2424;

    GameProp::Reset();
    this->unk100 = 0.0f;
    this->unk104 = 3500.0f;
    this->unk10C = 3000.0f;
    this->unk110 = 0.0f;
    this->unk114 = 0.75f;
    this->unk118 = 1.0f;
    this->unk3E4 = 0.0f;
    M2C_FIELD(this, s8 *, 0x3EC) = 0;
    M2C_FIELD(this, s8 *, 0x3ED) = 0;
    M2C_FIELD(this, s8 *, 0x3EE) = 0;
    M2C_FIELD(this, s8 *, 0x130) = 0;
    M2C_FIELD(this, s8 *, 0x131) = 0;
    temp_r3_2424 = this->unk124->PropResolver_Resolve(M2C_ERROR(/* Read from unset register $r4 */));
    if (temp_r3_2424 != NULL) {
        M2C_FIELD(M2C_FIELD(temp_r3_2424, void **, 0x44), M2C_UNK (**)(), 0x20)();
    }
}
#endif

#if 0 // DRAFT: expression syntax error
void SteamTrain::Resolve() {
    KDPropEx::Resolve();
    this->unk134.Resolve();
}
#endif

#if 0 // DRAFT: undefined identifier 'pSteamAnimEvents'
void SteamTrain::LoadDone() {
    s32 var_r30_2501;
    s32 var_r31_2502;

    GameProp::LoadDone();
    this->unk80->InitEvents(&pSteamAnimEvents);
    M2C_FIELD(this, s32 *, 0x134) = checked_cast<Explosion3 *, MKProp>(gMK->CreateProp("Explosion3"));
    ((Animation *) (MKModel_GetAnimation(this->unk4)))->EnableCustomMatrices(1U);
    this->unk134.Init((Matrix *) this->unk8, this->unk4, this->unk80);
    this->unk138.unk8 = (MKAnimScript *) this;
    this->unk100 = MKMaterial_Create"steamBrakeGlow";
    this->unkD0.Init(this->unk4, (MKProp *) this, 2000.0f, NULL, 1500.0f);
    this->unkD0.Show(1U);
    var_r30_2501 = 0;
    var_r31_2502 = 0;
    do {
        MKModel_EnableSubObject(this->unk4, (SubObjectType) 0, *(checked_cast<SteamTrainDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + (var_r31_2502 + 0xE8)), 0U, 1U);
        var_r30_2501 += 1;
        var_r31_2502 += 4;
    } while (var_r30_2501 < 5);
    Init__28KDStateMachine<10SteamTrain>FPQ228KDStateMachine<10SteamTrain>5StateP28KDStateMachine<10SteamTrain>(&this->unk378, (KDStateMachine<SteamTrain>::State *) &SteamTrain::states, NULL);
    this->unk378.SetState(this, 1, 0U);
    Disable();
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long *' to
s32 SteamTrain::LoadLine(MKIniLine *arg0) {
    s32 var_r31_2549;

    var_r31_2549 = 0;
    if ((GameProp::LoadLine(arg0) != 0) || (arg0->LoadInt("trackID", (s32 *) &this->unk120, 0) != 0) || (arg0->LoadInt("cabooseID", (s32 *) &this->unk124, 0) != 0) || (arg0->LoadInt("SpyroCartID", (s32 *) &this->unk128, 0) != 0)) {
        var_r31_2549 = 1;
    }
    return var_r31_2549;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'float' to
void SteamTrain::Init() {
    GameProp::Init();
    this->unk100 = 0.0f;
    this->unk104 = 3500.0f;
    this->unk10C = 3000.0f;
    this->unk38C = 0.0f;
    this->unk110 = 0.0f;
    this->unk120 = 0.0f;
    this->unk124 = NULL;
    this->unk128 = NULL;
    this->unk114 = 0.75f;
    this->unk118 = 1.0f;
    this->unk3E4 = 0.0f;
    this->unk11C = 6000.0f;
    this->unk390.Init(0.25f, 0.5f);
    this->unk3BC.Init(0.25f, 0.25f);
    M2C_FIELD(this, s8 *, 0x3EF) = 0;
    this->unk3EC = 0;
    M2C_FIELD(this, s8 *, 0x3EC) = 0;
    M2C_FIELD(this, s8 *, 0x3ED) = 0;
    M2C_FIELD(this, s8 *, 0x3EE) = 0;
    M2C_FIELD(this, s8 *, 0x130) = 0;
    M2C_FIELD(this, s8 *, 0x131) = 0;
    this->unk3E4 = 50.0f;
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void SteamTrainDescriptor::LoadDone() {
    GamePropDescriptor::LoadDone();
    this->unkE4 = this->unk34->GetAnim("idle01");
    this->unkE8 = (s32) Tools_GetMatchingSubObjectIndex((SubObjectType) 0, this->unk2C, "Engine_damaged");
    this->unkEC = (s32) Tools_GetMatchingSubObjectIndex((SubObjectType) 0, this->unk2C, "Guard_F_R_damaged");
    this->unkF0 = (s32) Tools_GetMatchingSubObjectIndex((SubObjectType) 0, this->unk2C, "Pipe_damaged");
    this->unkF4 = (s32) Tools_GetMatchingSubObjectIndex((SubObjectType) 0, this->unk2C, "Piston_R_damaged");
    this->unkF8 = (s32) Tools_GetMatchingSubObjectIndex((SubObjectType) 0, this->unk2C, "spike_01_damaged");
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_sp2C'
void SteamTrainEffects::UpdateWheelBone(MKDynamicBone *arg0, void *arg1) {
    s16 temp_r31_2757;
    M2C_STRUCT_COPY((s32) &arg_sp2C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
    arg_sp10 = -arg0->unk0;
    arg_sp14 = -arg0->unk4;
    arg_sp18 = -arg0->unk8;
    arg_sp20 = (f64) arg_sp10;
    arg_sp28 = (f64) arg_sp18;
    arg_sp30.Translate((Matrix *) &arg_sp30, *((MKVector3 *) &arg_sp20));
    arg_sp30.RotatePitch((Matrix *) &arg_sp30, arg0->unk10);
    arg_sp30.Translate((Matrix *) &arg_sp30, *((MKVector3 *) arg0));
    temp_r31_2757 = M2C_FIELD(this->unk20, s16 *, 0x70);
    ((Animation *) (MKModel_GetAnimation(this->unk24)))->SetCustomMatrix((s32) temp_r31_2757, (Matrix *) &arg_sp30, (AnimationMatrixPosition) 4, 0U);
}
#endif

#if 0 // DRAFT: function call 'MKRand_Float(long *, float, float)' does not match
void SteamTrainEffects::UpdateAnimEvents() {
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    M2C_UNK sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 temp_f29_2826;
    f32 temp_f30_2821;
    s32 var_r30_2791;
    void *temp_r29_2802;
    void *temp_r3_2793;
    void *temp_r3_2797;

    if (this->unk8->CheckEvent(0) != 0) {
        var_r30_2791 = 0;
        do {
            temp_r3_2793 = this->unk1E4;
            temp_r3_2797 = M2C_FIELD(M2C_FIELD(temp_r3_2793, void **, 0x44), void *(**)(void *), 0x3C)(temp_r3_2793);
            if (temp_r3_2797 != NULL) {
                temp_r29_2802 = M2C_FIELD(temp_r3_2797, void **, 0x2C);
                sp18 = 0.0f;
                sp1C = 0.0f;
                sp20 = 0.0f;
                M2C_FIELD(temp_r3_2797, f64 *, 0) = (f64) sp18;
                M2C_FIELD(temp_r3_2797, f64 *, 8) = (f64) sp20;
                sp48 = (f64) sp18;
                sp50 = (f64) sp20;
                M2C_FIELD(temp_r3_2797, f32 *, 0x20) = 0.0f;
                M2C_FIELD(temp_r3_2797, f32 *, 0x24) = MKRand_Float(&gViewSeed, -6.2831855f, 6.2831855f);
                temp_f30_2821 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                temp_f29_2826 = MKRand_Float(&gViewSeed, 0.75f, 1.0f);
                MKVector(MKRand_Float(&gViewSeed, -1.0f, 1.0f), temp_f29_2826, temp_f30_2821);
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
                M2C_FIELD(temp_r29_2802, f64 *, 0) = sp8;
                sp10 = sp30 * 800.0f;
                sp38 = sp8;
                sp40 = (f64) sp10;
                M2C_FIELD(temp_r29_2802, f64 *, 8) = (f64) sp10;
                M2C_FIELD(temp_r29_2802, f32 *, 0x18) = MKRand_Float(&gViewSeed, 0.5f, 1.0f);
                M2C_FIELD(temp_r29_2802, f32 *, 0x10) = MKRand_Float(&gViewSeed, -6.2831855f, 6.2831855f);
                M2C_FIELD(temp_r29_2802, f32 *, 0x14) = (f32) M2C_FIELD(this->unk1E4, f32 *, 0xF4);
            }
            var_r30_2791 += 1;
        } while (var_r30_2791 < 5);
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_sp10'
void SteamTrainEffects::DrawEffects() {
    s32 var_r29_2891;
    s32 var_r29_2924;
    s32 var_r30_2892;
    s32 var_r30_2925;
    void *temp_r3_2915;
    void *temp_r3_2948;
    void *temp_r5_2907;
    void *temp_r5_2940;
    var_r29_2891 = 0;
    var_r30_2892 = 0;
    do {
        MKModel_GetRefPointMatrix(this->unk4, *(this + (var_r30_2892 + 0x1F0)), (Matrix *) &arg_sp10, 0U);
        arg_sp10.Multiply((Matrix *) &arg_sp10, this->unk0);
        temp_r5_2907 = this->unk1D8 + 0x5C;
        M2C_STRUCT_COPY((s32) temp_r5_2907 + 4, (s32) &arg_spC + 4, 0x40);
        temp_r3_2915 = this->unk1D8;
        M2C_FIELD(M2C_FIELD(temp_r3_2915, void **, 0x44), M2C_UNK (**)(void *, void *, void *), 0x28)(temp_r3_2915, &arg_spC + 0x40, temp_r5_2907 + 0x40);
        var_r29_2891 += 1;
        var_r30_2892 += 4;
    } while (var_r29_2891 < 4);
    var_r29_2924 = 0;
    var_r30_2925 = 0;
    do {
        MKModel_GetRefPointMatrix(this->unk4, *(this + (var_r30_2925 + 0x218)), (Matrix *) &arg_sp10, 0U);
        arg_sp10.Multiply((Matrix *) &arg_sp10, this->unk0);
        temp_r5_2940 = this->unk1E4 + 0x5C;
        M2C_STRUCT_COPY((s32) temp_r5_2940 + 4, (s32) &arg_spC + 4, 0x40);
        temp_r3_2948 = this->unk1E4;
        M2C_FIELD(M2C_FIELD(temp_r3_2948, void **, 0x44), M2C_UNK (**)(void *, void *, void *), 0x28)(temp_r3_2948, &arg_spC + 0x40, temp_r5_2940 + 0x40);
        var_r29_2924 += 1;
        var_r30_2925 += 4;
    } while (var_r29_2924 < 2);
}
#endif

void SteamTrainEffects::Draw() {
    DrawEffects();
}

#if 0 // DRAFT: undefined identifier 'sp50'
void SteamTrainEffects::EmitSparks(const MKVector3 &arg0) {
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
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp38;
    f32 sp28;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 sp8;
    Matrix *temp_r5_2997;
    f32 temp_f27_3033;
    f32 temp_f28_3038;
    f32 temp_f31_3081;

    temp_r5_2997 = this->unk0;
    sp60 = -temp_r5_2997->unk20;
    sp64 = -temp_r5_2997->unk24;
    sp68 = -temp_r5_2997->unk28;
    spB0 = (f64) sp60;
    spB8 = (f64) sp68;
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f3 */);
    spC0 = sp50;
    sp58 = (f32) spB8 * this->unk230;
    spC8 = (f64) sp58;
    temp_f27_3033 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
    temp_f28_3038 = MKRand_Float(&gViewSeed, 0.5f, 1.0f);
    sp40 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
    sp44 = temp_f28_3038;
    sp48 = temp_f27_3033;
    sp80 = (f64) sp40;
    sp88 = (f64) sp48;
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
    sp90 = sp30;
    sp38 = (f32) sp88 * 800.0f;
    sp98 = (f64) sp38;
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    spA0 = sp20;
    sp28 = (f32) sp98 + (f32) spC8;
    spA8 = (f64) sp28;
    sp8 = MKRand_Float(&gViewSeed, 5.0f, 8.0f);
    temp_f31_3081 = MKRand_Float(&gViewSeed, 0.75f, 1.0f);
    sp10 = MKRand_Float(&gViewSeed, 0.85f, 1.0f);
    sp14 = temp_f31_3081;
    sp18 = 0.5f;
    sp1C = 1.0f;
    sp70 = (f64) sp10;
    sp78 = (f64) sp18;
    ((EmbersPS *) (M2C_FIELD(&gb, EmbersPS **, 0x74)))->Emit(arg0, *((MKVector3 *) &spA0), sp8, *((MKVector4 *) &sp70), -1000.0f);
}
#endif

#if 0 // DRAFT: function call 'MKRand_Float(long *, float, float)' does not match
void SteamTrainEffects::EmitSmoke() {
    f64 sp30;
    f64 sp28;
    M2C_UNK sp18;
    f32 sp10;
    MKVector3 *temp_r3_3134;
    void *temp_r30_3137;
    void *temp_r3_3130;

    temp_r3_3130 = this->unk1DC;
    temp_r3_3134 = M2C_FIELD(M2C_FIELD(temp_r3_3130, void **, 0x44), MKVector3 *(**)(void *), 0x3C)(temp_r3_3130);
    if (temp_r3_3134 != NULL) {
        temp_r30_3137 = M2C_FIELD(temp_r3_3134, void **, 0x2C);
        MKModel_CalculateRefPointWorldPosition(this->unk4, this->unk200, temp_r3_3134);
        M2C_FIELD(temp_r3_3134, f32 *, 0x20) = 0.0f;
        M2C_FIELD(temp_r3_3134, f32 *, 0x24) = MKRand_Float(&gViewSeed, -6.2831855f, 6.2831855f);
        MKVector(0.0f, MKRand_Float(&gViewSeed, 0.75f, 1.0f), 0.0f);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
        M2C_FIELD(temp_r30_3137, f64 *, 0) = sp8;
        sp10 = sp20 * 400.0f;
        sp28 = sp8;
        sp30 = (f64) sp10;
        M2C_FIELD(temp_r30_3137, f64 *, 8) = (f64) sp10;
        M2C_FIELD(temp_r30_3137, f32 *, 0x18) = (f32) (this->unk238 * MKRand_Float(&gViewSeed, 0.5f, 1.0f));
        M2C_FIELD(temp_r30_3137, f32 *, 0x10) = MKRand_Float(&gViewSeed, -6.2831855f, 6.2831855f);
        M2C_FIELD(temp_r30_3137, f32 *, 0x14) = (f32) M2C_FIELD(this->unk1DC, f32 *, 0xF4);
    }
}
#endif

#if 0 // DRAFT: function call 'MKModel_CalculateRefPointWorldPosition(MKModel *,
void SteamTrainEffects::EmitBrakingEffects() {
    MKVector3 sp8;
    f32 temp_f2_3206;
    s32 temp_r30_3217;
    s32 var_r28_3224;
    s32 var_r29_3210;
    s32 var_r31_3212;

    temp_f2_3206 = this->unk234;
    if (temp_f2_3206 > 0.0f) {
        var_r29_3210 = 0;
        var_r31_3212 = 0;
        temp_r30_3217 = (s32) (5.0f * (this->unk230 / temp_f2_3206));
        do {
            MKModel_CalculateRefPointWorldPosition(this->unk4, *(this + (var_r31_3212 + 0x204)), &sp8);
            var_r28_3224 = 0;
loop_4:
            if (var_r28_3224 < temp_r30_3217) {
                EmitSparks(sp8);
                var_r28_3224 += 1;
                goto loop_4;
            }
            var_r29_3210 += 1;
            var_r31_3212 += 4;
        } while (var_r29_3210 < 5);
    }
    EmitSmoke();
}
#endif

#if 0 // DRAFT: function call 'MKRand_Float(long *, float, float)' does not match
void SteamTrainEffects::EmitSteam() {
    f64 sp30;
    f64 sp28;
    M2C_UNK sp18;
    f32 sp10;
    MKVector3 *temp_r3_3262;
    void *temp_r30_3265;
    void *temp_r3_3258;

    temp_r3_3258 = this->unk1E0;
    temp_r3_3262 = M2C_FIELD(M2C_FIELD(temp_r3_3258, void **, 0x44), MKVector3 *(**)(void *), 0x3C)(temp_r3_3258);
    if (temp_r3_3262 != NULL) {
        temp_r30_3265 = M2C_FIELD(temp_r3_3262, void **, 0x2C);
        MKModel_CalculateRefPointWorldPosition(this->unk4, this->unk200, temp_r3_3262);
        M2C_FIELD(temp_r3_3262, f32 *, 0x20) = 0.0f;
        M2C_FIELD(temp_r3_3262, f32 *, 0x24) = MKRand_Float(&gViewSeed, -6.2831855f, 6.2831855f);
        MKVector(0.0f, MKRand_Float(&gViewSeed, 0.75f, 1.0f), 0.0f);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
        M2C_FIELD(temp_r30_3265, f64 *, 0) = sp8;
        sp10 = sp20 * 400.0f;
        sp28 = sp8;
        sp30 = (f64) sp10;
        M2C_FIELD(temp_r30_3265, f64 *, 8) = (f64) sp10;
        M2C_FIELD(temp_r30_3265, f32 *, 0x18) = (f32) (this->unk238 * MKRand_Float(&gViewSeed, 0.5f, 1.0f));
        M2C_FIELD(temp_r30_3265, f32 *, 0x10) = MKRand_Float(&gViewSeed, -6.2831855f, 6.2831855f);
        M2C_FIELD(temp_r30_3265, f32 *, 0x14) = (f32) M2C_FIELD(this->unk1E0, f32 *, 0xF4);
    }
}
#endif

#if 0 // DRAFT: function call 'MKRand_Float(long *, float, float)' does not match
void SteamTrainEffects::UpdateEffects() {
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    MKVector3 sp38;
    M2C_UNK sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 temp_f1_3404;
    f32 temp_f1_3440;
    f32 temp_f1_3443;
    f32 temp_f1_3458;
    f32 temp_f1_3461;
    f32 temp_f1_3475;
    f32 temp_f1_3478;
    f32 temp_f31_3361;
    f32 var_f2_3432;
    f32 var_f2_3450;
    f32 var_f2_3467;
    f32 var_f3_3403;
    void *temp_r30_3344;
    void *temp_r3_3335;
    void *temp_r3_3339;

    temp_r3_3335 = this->unk1D8;
    temp_r3_3339 = M2C_FIELD(M2C_FIELD(temp_r3_3335, void **, 0x44), void *(**)(void *), 0x3C)(temp_r3_3335);
    if (temp_r3_3339 != NULL) {
        temp_r30_3344 = M2C_FIELD(temp_r3_3339, void **, 0x2C);
        sp18 = 0.0f;
        sp1C = 0.0f;
        sp20 = 0.0f;
        M2C_FIELD(temp_r3_3339, f64 *, 0) = (f64) sp18;
        M2C_FIELD(temp_r3_3339, f64 *, 8) = (f64) sp20;
        sp58 = (f64) sp18;
        sp60 = (f64) sp20;
        M2C_FIELD(temp_r3_3339, f32 *, 0x20) = 0.0f;
        M2C_FIELD(temp_r3_3339, f32 *, 0x24) = MKRand_Float(&gViewSeed, -6.2831855f, 6.2831855f);
        temp_f31_3361 = this->unk224;
        MKVector(0.0f, 0.0f, -MKRand_Float(&gViewSeed, 0.75f, 1.0f));
        sp38.operator*(1000.0f);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
        M2C_FIELD(temp_r30_3344, f64 *, 0) = sp8;
        sp10 = sp38.unk8 * temp_f31_3361;
        sp48 = sp8;
        sp50 = (f64) sp10;
        M2C_FIELD(temp_r30_3344, f64 *, 8) = (f64) sp10;
        M2C_FIELD(temp_r30_3344, f32 *, 0x18) = (f32) (this->unk224 * MKRand_Float(&gViewSeed, 0.5f, 1.0f));
        M2C_FIELD(temp_r30_3344, f32 *, 0x10) = MKRand_Float(&gViewSeed, -6.2831855f, 6.2831855f);
        M2C_FIELD(temp_r30_3344, f32 *, 0x14) = (f32) M2C_FIELD(this->unk1D8, f32 *, 0xF4);
    }
    var_f3_3403 = 0.0f;
    temp_f1_3404 = this->unk234;
    if (temp_f1_3404 > 0.0f) {
        var_f3_3403 = this->unk230 / temp_f1_3404;
    }
    this->unk10 = var_f3_3403 * this->unk14;
    this->unk22C = 0.25f + (1.0f - var_f3_3403);
    this->unk228 += gUpdateTimeDelta;
    M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
    if (this->unk228 == this->unk22C) {
        this->unk228 = 0.0f;
        this->unk238 = 2.0f;
    }
    var_f2_3432 = 0.125f;
    if (1.0f > 0.125f) {

    } else {
        var_f2_3432 = 1.0f;
    }
    temp_f1_3440 = this->unk238;
    temp_f1_3443 = (var_f2_3432 * (1.0f - temp_f1_3440)) + temp_f1_3440;
    this->unk238 = (var_f2_3432 * (1.0f - temp_f1_3443)) + temp_f1_3443;
    if ((u8) this->unk90 == 0) {
        var_f2_3450 = 0.125f;
        if (1.0f > 0.125f) {

        } else {
            var_f2_3450 = 1.0f;
        }
        temp_f1_3458 = this->unk224;
        temp_f1_3461 = (var_f2_3450 * (1.0f - temp_f1_3458)) + temp_f1_3458;
        this->unk224 = (var_f2_3450 * (1.0f - temp_f1_3461)) + temp_f1_3461;
        return;
    }
    var_f2_3467 = 0.125f;
    if (1.0f > 0.125f) {

    } else {
        var_f2_3467 = 1.0f;
    }
    temp_f1_3475 = this->unk224;
    temp_f1_3478 = (var_f2_3467 * (7.0f - temp_f1_3475)) + temp_f1_3475;
    this->unk224 = (var_f2_3467 * (7.0f - temp_f1_3478)) + temp_f1_3478;
}
#endif

#if 0 // DRAFT: illegal operand
void SteamTrainEffects::Update() {
    f32 temp_f0_3514;
    s32 temp_r0_3508;
    s32 var_ctr_3506;
    s32 var_r3_3505;

    UpdateEffects();
    UpdateAnimEvents();
    var_r3_3505 = 0;
    var_ctr_3506 = 5;
    do {
        temp_r0_3508 = var_r3_3505 + 0x28;
        *(this + temp_r0_3508) = (gUpdateTimeDelta * this->unk10) + *(this + temp_r0_3508);
        temp_f0_3514 = *(this + temp_r0_3508);
        M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
        if (temp_f0_3514 == 6.2831855f) {
            *(this + temp_r0_3508) = temp_f0_3514 - 6.2831855f;
        }
        var_r3_3505 += 0x18;
        var_ctr_3506 -= 1;
    } while (var_ctr_3506 != 0);
}
#endif

void SteamTrainEffects::Reset() {
    this->unk230 = 0.0f;
    this->unk234 = 0.0f;
    this->unk224 = 0.5f;
    this->unk10 = 0.0f;
    this->unk228 = 0.0f;
    this->unk238 = 1.0f;
    this->unk90 = 0;
}

#if 0 // DRAFT: function call 'Tools_GetMatchingNodeIndex(MKModel *, signed char *)' does
void SteamTrainEffects::Resolve() {
    Animation sp28;
    f64 sp18;
    f64 sp8;
    s32 var_r25_3650;
    s32 var_r26_3557;
    s32 var_r30_3560;
    s32 var_r30_3652;
    u16 temp_r25_3569;
    void *temp_r27_3577;
    void *temp_r27_3677;

    var_r26_3557 = 0;
    var_r30_3560 = 0;
    do {
        temp_r25_3569 = Tools_GetMatchingNodeIndex(this->unk4, Str_Printf("wheel_%.2d", var_r26_3557));
        sp28.GetNodeOrigin(MKModel_GetAnimation(this->unk4));
        temp_r27_3577 = this + var_r30_3560;
        M2C_FIELD(temp_r27_3577, f64 *, 0x18) = M2C_BITWISE(f64, sp28);
        M2C_FIELD(temp_r27_3577, f64 *, 0x20) = sp28.unk8;
        MKDynamicBone_SetUpdater(MKDynamicBone_AddDynamicBone(this->unk4, (s32) temp_r25_3569), (void (*)(MKDynamicBone *, void *)) &SteamTrainEffects::UpdateWheelBone, temp_r27_3577 + 0x18);
        var_r26_3557 += 1;
        var_r30_3560 += 0x18;
    } while (var_r26_3557 < 5);
    this->unk98 = (s32) Tools_GetMatchingNodeIndex(this->unk4, "Piston_B_R");
    this->unkE8 = (s32) Tools_GetMatchingNodeIndex(this->unk4, "Piston_F_R");
    this->unk138 = (s32) Tools_GetMatchingNodeIndex(this->unk4, "Piston_B_L");
    this->unk188 = (s32) Tools_GetMatchingNodeIndex(this->unk4, "Piston_F_L");
    this->unk9C = (s32) Tools_GetMatchingNodeIndex(this->unk4, "wheel_04");
    this->unkEC = (s32) Tools_GetMatchingNodeIndex(this->unk4, "wheel_02");
    this->unk13C = (s32) Tools_GetMatchingNodeIndex(this->unk4, "wheel_03");
    this->unk18C = (s32) Tools_GetMatchingNodeIndex(this->unk4, "wheel_01");
    var_r25_3650 = 0;
    var_r30_3652 = 0;
    this->unkA0 = this->unkE8;
    this->unkF0 = this->unk98;
    this->unk140 = this->unk188;
    this->unk190 = this->unk138;
    this->unkC8 = -1.0f;
    this->unkCC = 0.0f;
    this->unkD0 = 0.0f;
    this->unk118 = -1.0f;
    this->unk11C = 0.0f;
    this->unk120 = 0.0f;
    this->unk168 = 1.0f;
    this->unk16C = 0.0f;
    this->unk170 = 0.0f;
    this->unk1B8 = 1.0f;
    this->unk1BC = 0.0f;
    this->unk1C0 = 0.0f;
    do {
        temp_r27_3677 = this + var_r30_3652;
        sp18.GetNodeOrigin(MKModel_GetAnimation(this->unk4));
        M2C_FIELD(temp_r27_3677, f64 *, 0xA8) = sp18;
        M2C_FIELD(temp_r27_3677, f64 *, 0xB0) = sp20;
        sp8.GetNodeOrigin(MKModel_GetAnimation(this->unk4));
        M2C_FIELD(temp_r27_3677, f64 *, 0xB8) = sp8;
        M2C_FIELD(temp_r27_3677, f64 *, 0xC0) = sp10;
        MKDynamicBone_SetUpdater(MKDynamicBone_GetDynamicBone(this->unk4, M2C_FIELD(temp_r27_3677, s32 *, 0x98)), UpdateLookAtBone, temp_r27_3677 + 0x98);
        var_r25_3650 += 1;
        var_r30_3652 += 0x50;
    } while (var_r25_3650 < 4);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'const Matrix *' to
void SteamTrainEffects::Init(const Matrix *arg0, MKModel *arg1, MKAnimScript *arg2) {
    f32 var_f0_3740;
    s32 var_ctr_3731;
    s32 var_r3_3727;
    u32 temp_r4_3733;
    u32 var_r7_3719;
    void *temp_r5_3736;

    var_r7_3719 = 1;
    this->unk0 = arg0;
    this->unk4 = arg1;
    var_r3_3727 = 0x18;
    this->unk8 = arg2;
    this->unk28 = 0.0f;
    this->unk2C = 0.0f;
    var_ctr_3731 = 4;
    do {
        temp_r4_3733 = var_r7_3719 >> 0x1FU;
        temp_r5_3736 = this + var_r3_3727;
        M2C_FIELD(temp_r5_3736, f32 *, 0x28) = 0.0f;
        if ((((var_r7_3719 & 1) ^ temp_r4_3733) - temp_r4_3733) == 0) {
            var_f0_3740 = -1.0f;
        } else {
            var_f0_3740 = 1.0f;
        }
        var_r7_3719 += 1;
        var_r3_3727 += 0x18;
        M2C_FIELD(temp_r5_3736, f32 *, 0x2C) = (f32) (var_f0_3740 * 0.43633232f);
        var_ctr_3731 -= 1;
    } while (var_ctr_3731 != 0);
    this->unk8->InitEvents(&pSteamAnimEvents);
    this->unk1D8 = checked_cast<KDEnvParticleSystem *, MKProp>(gMK->CreateProp("SteamTrainFlamePS"));
    this->unk1DC = checked_cast<KDEnvParticleSystem *, MKProp>(gMK->CreateProp("SteamTrainSmokePS"));
    this->unk1E0 = checked_cast<KDEnvParticleSystem *, MKProp>(gMK->CreateProp("SteamTrainSteamPS"));
    this->unk1E4 = checked_cast<KDEnvParticleSystem *, MKProp>(gMK->CreateProp("SteamTrainSteamPuffPS"));
    this->unk1E8 = checked_cast<Explosion3 *, MKProp>(gMK->CreateProp("Explosion3"));
    this->unk1EC = (s32) Tools_GetMatchingRefPointIndex(this->unk4, "caboose");
    this->unk1F0 = (s32) Tools_GetMatchingRefPointIndex(this->unk4, "flame_01");
    this->unk1F4 = (s32) Tools_GetMatchingRefPointIndex(this->unk4, "flame_02");
    this->unk1F8 = (s32) Tools_GetMatchingRefPointIndex(this->unk4, "flame_03");
    this->unk1FC = (s32) Tools_GetMatchingRefPointIndex(this->unk4, "flame_04");
    this->unk200 = (s32) Tools_GetMatchingRefPointIndex(this->unk4, "smoke");
    this->unk204 = (s32) Tools_GetMatchingRefPointIndex(this->unk4, "wheelsparks_00");
    this->unk208 = (s32) Tools_GetMatchingRefPointIndex(this->unk4, "wheelsparks_01");
    this->unk20C = (s32) Tools_GetMatchingRefPointIndex(this->unk4, "wheelsparks_02");
    this->unk210 = (s32) Tools_GetMatchingRefPointIndex(this->unk4, "wheelsparks_03");
    this->unk214 = (s32) Tools_GetMatchingRefPointIndex(this->unk4, "wheelsparks_04");
    this->unk218 = (s32) Tools_GetMatchingRefPointIndex(this->unk4, "piston_00");
    this->unk21C = (s32) Tools_GetMatchingRefPointIndex(this->unk4, "piston_01");
    this->unk220 = (s32) Tools_GetMatchingRefPointIndex(this->unk4, "target");
    ((Animation *) (MKModel_GetAnimation(this->unk4)))->EnableCustomMatrices(1U);
    this->unk228 = 0.0f;
    this->unk224 = 0.5f;
    this->unk10 = 0.0f;
    this->unk14 = 20.0f;
    this->unk230 = 0.0f;
    this->unk234 = 0.0f;
    this->unk238 = 1.0f;
    this->unk90 = 0;
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_sp14'
void UpdateLookAtBone(MKDynamicBone *arg0, void *arg1) {
    Animation *temp_r3_3926;
    Animation *temp_r3_3943;
    Animation *temp_r3_3988;
    Matrix *temp_r3_4047;
    f32 temp_f31_4044;
    f32 temp_f3_3950;
    f32 temp_f3_3995;
    f32 temp_f6_3956;
    f32 temp_f6_4004;
    f32 temp_f7_3962;
    f32 temp_f7_4010;
    s32 temp_r31_3924;
    s32 temp_r31_3933;
    s32 temp_r31_3941;
    s32 temp_r31_3975;
    s32 temp_r31_4188;
    temp_r31_3924 = M2C_FIELD(arg1, s32 *, 4);
    temp_r3_3926 = MKModel_GetAnimation(arg0->unk24);
    arg_sp14 = (s16) temp_r31_3924;
    temp_r3_3926->CalculateMatrices((Matrix *) &arg_sp220, 1, &arg_sp14, NULL);
    temp_r31_3933 = M2C_FIELD(arg1, s32 *, 0);
    ((Animation *) (MKModel_GetAnimation(arg0->unk24)))->SetCustomMatrix(temp_r31_3933, NULL, (AnimationMatrixPosition) 2, 0U);
    temp_r31_3941 = M2C_FIELD(arg1, s32 *, 0);
    temp_r3_3943 = MKModel_GetAnimation(arg0->unk24);
    arg_sp10 = (s16) temp_r31_3941;
    temp_r3_3943->CalculateMatrices((Matrix *) &arg_sp260, 1, &arg_sp10, NULL);
    temp_f3_3950 = M2C_FIELD(arg1, f32 *, 0x14);
    temp_f6_3956 = M2C_FIELD(arg1, f32 *, 0x10);
    temp_f7_3962 = M2C_FIELD(arg1, f32 *, 0x18);
    temp_r31_3975 = M2C_FIELD(arg1, s32 *, 8);
    arg_sp78 = arg_sp290 + ((temp_f7_3962 * arg_sp280) + ((temp_f6_3956 * arg_sp260) + (temp_f3_3950 * arg_sp270)));
    arg_sp7C = arg_sp294 + ((temp_f7_3962 * arg_sp284) + ((temp_f6_3956 * arg_sp264) + (temp_f3_3950 * arg_sp274)));
    arg_sp80 = arg_sp298 + ((temp_f7_3962 * arg_sp288) + ((temp_f6_3956 * arg_sp268) + (temp_f3_3950 * arg_sp278)));
    arg_sp118 = (f64) arg_sp78;
    arg_sp120 = (f64) arg_sp80;
    arg_sp148 = (f64) arg_sp78;
    arg_sp150 = (f64) arg_sp80;
    temp_r3_3988 = MKModel_GetAnimation(arg0->unk24);
    arg_sp10 = (s16) temp_r31_3975;
    temp_r3_3988->CalculateMatrices((Matrix *) &arg_sp1E0, 1, &arg_sp10, NULL);
    temp_f3_3995 = M2C_FIELD(arg1, f32 *, 0x24);
    temp_f6_4004 = M2C_FIELD(arg1, f32 *, 0x20);
    temp_f7_4010 = M2C_FIELD(arg1, f32 *, 0x28);
    arg_sp68 = arg_sp210 + ((temp_f7_4010 * arg_sp200) + ((temp_f6_4004 * arg_sp1E0) + (temp_f3_3995 * arg_sp1F0)));
    arg_sp6C = arg_sp214 + ((temp_f7_4010 * arg_sp204) + ((temp_f6_4004 * arg_sp1E4) + (temp_f3_3995 * arg_sp1F4)));
    arg_sp70 = arg_sp218 + ((temp_f7_4010 * arg_sp208) + ((temp_f6_4004 * arg_sp1E8) + (temp_f3_3995 * arg_sp1F8)));
    arg_sp108 = (f64) arg_sp68;
    arg_sp110 = (f64) arg_sp70;
    arg_sp138 = (f64) arg_sp68;
    arg_sp140 = (f64) arg_sp70;
    M2C_STRUCT_COPY((s32) &arg_sp19C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
    temp_f31_4044 = M2C_FIELD(arg1, f32 *, 0x30);
    if (temp_f31_4044 != 0.0f) {
        temp_r3_4047 = arg0->unk20;
        arg_sp128 = M2C_FIELD(temp_r3_4047, f64 *, 0x10);
        arg_sp130 = M2C_FIELD(temp_r3_4047, f64 *, 0x18);
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
        arg_spD8 = arg_sp28;
        arg_sp30 = (f32) arg_sp140 - (f32) arg_sp150;
        arg_spE0 = (f64) arg_sp30;
        Normalise(*((MKVector3 *) &arg_spE8));
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
        arg_spF8 = arg_sp58;
        arg_sp60 = arg_spF0 * temp_f31_4044;
        arg_sp100 = (f64) arg_sp60;
        arg_sp1A0 = (f32) arg_spF8;
        arg_sp1A4 = arg_spFC;
        arg_sp1A8 = (f32) arg_sp100;
        arg_sp20 = ((f32) arg_sp128 * arg_spFC) - (arg_sp12C * (f32) arg_spF8);
        arg_sp18 = (arg_sp12C * (f32) arg_sp100) - ((f32) arg_sp130 * arg_spFC);
        arg_sp1C = ((f32) arg_sp130 * (f32) arg_spF8) - ((f32) arg_sp128 * (f32) arg_sp100);
        arg_sp1AC = 0.0f;
        arg_spA8 = (f64) arg_sp18;
        arg_spB0 = (f64) arg_sp20;
        Normalise(*((MKVector3 *) &arg_spB8));
        arg_sp48 = -arg_spB8;
        arg_sp4C = -arg_spBC;
        arg_sp50 = -arg_spC0;
        arg_spC8 = (f64) arg_sp48;
        arg_spD0 = (f64) arg_sp50;
        arg_sp1C0 = (f32) arg_spC8;
        arg_sp1C4 = arg_spCC;
        arg_sp1C8 = (f32) arg_spD0;
        arg_sp40 = ((f32) arg_spC8 * arg_sp1A4) - (arg_spCC * arg_sp1A0);
        arg_sp38 = (arg_spCC * arg_sp1A8) - ((f32) arg_spD0 * arg_sp1A4);
        arg_sp3C = ((f32) arg_spD0 * arg_sp1A0) - ((f32) arg_spC8 * arg_sp1A8);
        arg_sp1CC = 0.0f;
        arg_sp88 = (f64) arg_sp38;
        arg_sp90 = (f64) arg_sp40;
        Normalise(*((MKVector3 *) &arg_sp98));
        arg_sp1B0 = arg_sp98;
        arg_sp1B4 = arg_sp9C;
        arg_sp1B8 = arg_spA0;
        arg_sp1BC = 0.0f;
    }
    arg_sp1D0 = (f32) arg_sp148;
    arg_sp1D4 = arg_sp14C;
    arg_sp1D8 = (f32) arg_sp150;
    arg_sp1DC = 1.0f;
    arg_sp160.Multiply(arg0->unk20, (Matrix *) &arg_sp260);
    arg_sp160.Inverse((Matrix *) &arg_sp160);
    arg_sp1A0.Multiply((Matrix *) &arg_sp160, (Matrix *) &arg_sp1A0);
    arg_sp260.Multiply((Matrix *) &arg_sp260, (Matrix *) &arg_sp1A0);
    arg_sp220.Inverse((Matrix *) &arg_sp220);
    arg_sp260.Multiply((Matrix *) &arg_sp260, (Matrix *) &arg_sp220);
    M2C_FIELD(arg0, f64 *, 0x10) = (f64) M2C_FIELD(arg0, f64 *, 0);
    M2C_FIELD(arg0, f64 *, 0x18) = (f64) M2C_FIELD(arg0, f64 *, 8);
    temp_r31_4188 = M2C_FIELD(arg1, s32 *, 0);
    ((Animation *) (MKModel_GetAnimation(arg0->unk24)))->SetCustomMatrix(temp_r31_4188, (Matrix *) &arg_sp260, (AnimationMatrixPosition) 4, 0U);
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_743'
void SteamTrain_cpp::__sinit() {
    s32 sp28;
    s32 sp24;
    s32 sp20;
    s32 sp1C;
    s32 sp18;
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    f64 temp_f0_4468;
    f64 temp_f1_4466;
    f64 temp_f1_4473;
    f64 temp_f1_4480;
    f64 temp_f3_4451;
    f64 temp_f3_4471;
    f64 temp_f4_4465;
    f64 temp_f4_4469;
    f64 temp_f4_4478;
    f64 temp_f8_4453;
    void *temp_r20_4460;

    temp_f3_4451 = __frsqrte(2014000.0);
    temp_f8_4453 = __frsqrte(380000.0);
    temp_r20_4460 = &lit_743 + 0x78;
    temp_f4_4465 = 0.5 * temp_f3_4451 * -((2014000.0 * (temp_f3_4451 * temp_f3_4451)) - 3.0);
    temp_f1_4466 = 0.5 * temp_f8_4453 * -((380000.0 * (temp_f8_4453 * temp_f8_4453)) - 3.0);
    temp_f0_4468 = temp_f1_4466 * temp_f1_4466;
    temp_f4_4469 = 0.5 * temp_f4_4465;
    temp_f3_4471 = -((2014000.0 * (temp_f4_4465 * temp_f4_4465)) - 3.0);
    temp_f1_4473 = 0.5 * temp_f1_4466;
    sp8 = M2C_FIELD(&__ptmf_null, s32 *, 0);
    spC = M2C_FIELD(&__ptmf_null, s32 *, 4);
    temp_f4_4478 = temp_f4_4469 * temp_f3_4471;
    sp10 = M2C_FIELD(&__ptmf_null, s32 *, 8);
    temp_f1_4480 = temp_f1_4473 * -((380000.0 * temp_f0_4468) - 3.0);
    M2C_FIELD(&lit_743, s32 *, 0x78) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 0);
    M2C_FIELD(&lit_743, s32 *, 0x7C) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 4);
    M2C_FIELD(&lit_743, s32 *, 0x80) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 8);
    M2C_FIELD(temp_r20_4460, s32 *, 0xC) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 0);
    M2C_FIELD(temp_r20_4460, s32 *, 0x10) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 4);
    M2C_FIELD(temp_r20_4460, s32 *, 0x14) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 8);
    M2C_FIELD(temp_r20_4460, s32 *, 0x18) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 0);
    M2C_FIELD(temp_r20_4460, s32 *, 0x1C) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 4);
    M2C_FIELD(temp_r20_4460, s32 *, 0x20) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 8);
    M2C_FIELD(temp_r20_4460, s32 *, 0x24) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 0);
    M2C_FIELD(temp_r20_4460, s32 *, 0x28) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 4);
    M2C_FIELD(temp_r20_4460, s32 *, 0x2C) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 8);
    M2C_FIELD(temp_r20_4460, s32 *, 0x30) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 0);
    M2C_FIELD(temp_r20_4460, s32 *, 0x34) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 4);
    M2C_FIELD(temp_r20_4460, s32 *, 0x38) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 8);
    M2C_FIELD(temp_r20_4460, s32 *, 0x3C) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 0);
    M2C_FIELD(temp_r20_4460, s32 *, 0x40) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 4);
    M2C_FIELD(temp_r20_4460, s32 *, 0x44) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 8);
    SPYRO_BOUNCE_Y_SPEED = (f32) (2014000.0 * (0.5 * temp_f4_4478 * -((2014000.0 * (temp_f4_4478 * temp_f4_4478)) - 3.0)));
    SPYRO_MIN_JUMP_Y_VELOCITY = (f32) (380000.0 * (0.5 * temp_f1_4480 * -((380000.0 * (temp_f1_4480 * temp_f1_4480)) - 3.0)));
    sp28 = M2C_FIELD(&lit_743, s32 *, 0x5C);
    M2C_FIELD(temp_r20_4460, s32 *, 0x9C) = (s32) M2C_FIELD(&lit_743, s32 *, 0x54);
    sp14 = M2C_FIELD(&lit_743, s32 *, 0x60);
    M2C_FIELD(temp_r20_4460, s32 *, 0xA4) = sp28;
    sp18 = M2C_FIELD(&lit_743, s32 *, 0x64);
    M2C_FIELD(temp_r20_4460, s32 *, 0xA8) = sp14;
    sp1C = M2C_FIELD(&lit_743, s32 *, 0x68);
    M2C_FIELD(temp_r20_4460, s32 *, 0xAC) = sp18;
    sp20 = M2C_FIELD(&lit_743, s32 *, 0x6C);
    M2C_FIELD(temp_r20_4460, s32 *, 0xB0) = sp1C;
    sp24 = M2C_FIELD(&lit_743, s32 *, 0x70);
    M2C_FIELD(temp_r20_4460, s32 *, 0xCC) = sp20;
    M2C_FIELD(temp_r20_4460, s32 *, 0x48) = (s32) M2C_FIELD(&lit_743, s32 *, 0);
    M2C_FIELD(temp_r20_4460, s32 *, 0x4C) = (s32) M2C_FIELD(&lit_743, s32 *, 4);
    M2C_FIELD(temp_r20_4460, s32 *, 0x50) = (s32) M2C_FIELD(&lit_743, s32 *, 8);
    M2C_FIELD(temp_r20_4460, s32 *, 0x54) = (s32) M2C_FIELD(&lit_743, s32 *, 0xC);
    M2C_FIELD(temp_r20_4460, s32 *, 0x58) = (s32) M2C_FIELD(&lit_743, s32 *, 0x10);
    M2C_FIELD(temp_r20_4460, s32 *, 0x5C) = (s32) M2C_FIELD(&lit_743, s32 *, 0x14);
    M2C_FIELD(temp_r20_4460, s32 *, 0x60) = (s32) M2C_FIELD(&lit_743, s32 *, 0x18);
    M2C_FIELD(temp_r20_4460, s32 *, 0x64) = (s32) M2C_FIELD(&lit_743, s32 *, 0x1C);
    M2C_FIELD(temp_r20_4460, s32 *, 0x68) = (s32) M2C_FIELD(&lit_743, s32 *, 0x20);
    M2C_FIELD(temp_r20_4460, s32 *, 0x6C) = (s32) M2C_FIELD(&lit_743, s32 *, 0x24);
    M2C_FIELD(temp_r20_4460, s32 *, 0x70) = (s32) M2C_FIELD(&lit_743, s32 *, 0x28);
    M2C_FIELD(temp_r20_4460, s32 *, 0x74) = (s32) M2C_FIELD(&lit_743, s32 *, 0x2C);
    M2C_FIELD(temp_r20_4460, s32 *, 0x78) = (s32) M2C_FIELD(&lit_743, s32 *, 0x30);
    M2C_FIELD(temp_r20_4460, s32 *, 0x7C) = (s32) M2C_FIELD(&lit_743, s32 *, 0x34);
    M2C_FIELD(temp_r20_4460, s32 *, 0x80) = (s32) M2C_FIELD(&lit_743, s32 *, 0x38);
    M2C_FIELD(temp_r20_4460, s32 *, 0x84) = (s32) M2C_FIELD(&lit_743, s32 *, 0x3C);
    M2C_FIELD(temp_r20_4460, s32 *, 0x88) = (s32) M2C_FIELD(&lit_743, s32 *, 0x40);
    M2C_FIELD(temp_r20_4460, s32 *, 0x8C) = (s32) M2C_FIELD(&lit_743, s32 *, 0x44);
    M2C_FIELD(temp_r20_4460, s32 *, 0x90) = (s32) M2C_FIELD(&lit_743, s32 *, 0x48);
    M2C_FIELD(temp_r20_4460, s32 *, 0x94) = (s32) M2C_FIELD(&lit_743, s32 *, 0x4C);
    M2C_FIELD(temp_r20_4460, s32 *, 0x98) = (s32) M2C_FIELD(&lit_743, s32 *, 0x50);
    M2C_FIELD(temp_r20_4460, s32 *, 0xA0) = (s32) M2C_FIELD(&lit_743, s32 *, 0x58);
    M2C_FIELD(temp_r20_4460, s32 *, 0xB4) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 0);
    M2C_FIELD(temp_r20_4460, s32 *, 0xB8) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 4);
    M2C_FIELD(temp_r20_4460, s32 *, 0xBC) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 8);
    M2C_FIELD(temp_r20_4460, s32 *, 0xC0) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 0);
    M2C_FIELD(temp_r20_4460, s32 *, 0xC4) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 4);
    M2C_FIELD(temp_r20_4460, s32 *, 0xC8) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 8);
    M2C_FIELD(temp_r20_4460, s32 *, 0xD0) = sp24;
    M2C_FIELD(temp_r20_4460, s32 *, 0xD4) = (s32) M2C_FIELD(&lit_743, s32 *, 0x74);
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_200lit_IsAttacking'
void SteamTrain::lit_200lit_IsAttacking() {
    ((SteamTrain *) (this - 0xC8))->SteamTrain::IsAttacking();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_200lit_GetTimeLastHit'
void SteamTrain::lit_200lit_GetTimeLastHit() {
    ((SteamTrain *) (this - 0xC8))->SteamTrain::GetTimeLastHit();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_200lit_GetCollisionHeight'
void SteamTrain::lit_200lit_GetCollisionHeight() {
    ((SteamTrain *) (this - 0xC8))->SteamTrain::GetCollisionHeight();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_200lit_GetCollisionRadius'
void SteamTrain::lit_200lit_GetCollisionRadius() {
    ((SteamTrain *) (this - 0xC8))->SteamTrain::GetCollisionRadius();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_200lit_GetCollisionInfo'
void SteamTrain::lit_200lit_GetCollisionInfo() {
    ((SteamTrain *) (this - 0xC8))->SteamTrain::GetCollisionInfo();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_200lit_GetVel'
void SteamTrain::lit_200lit_GetVel() {
    SteamTrain::GetVel();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_200lit_GetAimPoint'
void SteamTrain::lit_200lit_GetAimPoint(const MKVector3 &arg0, MKVector3 *arg1) {
    ((SteamTrain *) (this - 0xC8))->SteamTrain::GetAimPoint(arg0, arg1);
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_200lit_GetLookToPoint'
void SteamTrain::lit_200lit_GetLookToPoint(const MKVector3 &arg0, MKVector3 *arg1) {
    ((SteamTrain *) (this - 0xC8))->SteamTrain::GetLookToPoint(arg0, arg1);
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_200lit_GetMoveToPoint'
void SteamTrain::lit_200lit_GetMoveToPoint(const MKVector3 &arg0, MKVector3 *arg1) {
    ((SteamTrain *) (this - 0xC8))->SteamTrain::GetMoveToPoint(arg0, arg1);
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_200lit_IsDead'
void SteamTrain::lit_200lit_IsDead() {
    ((SteamTrain *) (this - 0xC8))->SteamTrain::IsDead();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_200lit_IsShatterable'
void SteamTrain::lit_200lit_IsShatterable() {
    ((SteamTrain *) (this - 0xC8))->SteamTrain::IsShatterable();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_200lit_IsEnemy'
void SteamTrain::lit_200lit_IsEnemy() {
    ((SteamTrain *) (this - 0xC8))->SteamTrain::IsEnemy();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_200lit_IsFriend'
void SteamTrain::lit_200lit_IsFriend() {
    ((SteamTrain *) (this - 0xC8))->SteamTrain::IsFriend();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_200lit_IsHero'
void SteamTrain::lit_200lit_IsHero() {
    ((SteamTrain *) (this - 0xC8))->SteamTrain::IsHero();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_200lit_GetEnemy'
void SteamTrain::lit_200lit_GetEnemy() {
    ((SteamTrain *) (this - 0xC8))->SteamTrain::GetEnemy();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_200lit_GetProp'
void SteamTrain::lit_200lit_GetProp() {
    ((SteamTrain *) (this - 0xC8))->SteamTrain::GetProp();
}
#endif
