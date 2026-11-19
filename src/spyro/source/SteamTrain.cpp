#include "spyro/source/SteamTrain.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKDynamicBone.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKParticleSystem.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "common/Source/Texture.h"
#include "spyro/source/AssaultCannon.h"
#include "spyro/source/Crate.h"
#include "spyro/source/EmbersPS.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/ExpShock.h"
#include "spyro/source/ExpSmokeAndFlamesPS.h"
#include "spyro/source/Explosion3.h"
#include "spyro/source/ExplosionFX.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/FlyingChunkPS.h"
#include "spyro/source/GameMessages.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/GlowingPropManager.h"
#include "spyro/source/HeroInterface.h"
#include "spyro/source/KDFaderObject.h"
#include "spyro/source/KDInput.h"
#include "spyro/source/KDMatrixProperty.h"
#include "spyro/source/KDMatrixRefProperty.h"
#include "spyro/source/KDParticleSystem.h"
#include "spyro/source/KDPositionProperty.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDProperty.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/KDSpline.h"
#include "spyro/source/KDStateMachine.h"
#include "spyro/source/Level.h"
#include "spyro/source/LightManager.h"
#include "spyro/source/LightProp.h"
#include "spyro/source/ManagedLight.h"
#include "spyro/source/PlatformObject.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/ShatterablePlatform.h"
#include "spyro/source/SpyroEffects.h"
#include "spyro/source/SpyroUtils.h"
#include "spyro/source/TargetManager.h"
#include "spyro/source/Tools.h"
#include "spyro/source/TrainChaseSpyro.h"
#include "spyro/source/TrainTrack.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "common/Source/StdMath.h"
#include "common/Source/Str.h"
#include "spyro/source/SpyroHud.h"
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
static M2C_UNK lit_743;                                /* unable to generate initializer: unknown type */
u8 states__10SteamTrain[0xD8] = {
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
};
static s8 *pSteamAnimEvents = (signed char *) ("SteamPuff");

static s32 lit_1019 = 0;
static u8 lit_1020 = 1;

void SteamTrain::Stop(bool arg0) {
    if (arg0 != 0) {
        ((KDStateMachine<SteamTrain> *) &this->unk378)->SetState(this, 3, 0U);
        return;
    }
    ((KDStateMachine<SteamTrain> *) &this->unk378)->SetState(this, 4, 0U);
}

#if 0 // DRAFT: illegal explicit conversion from 'TrainTrack' to 'double'
void SteamTrain::StateRamUpdate() {
    s8 sp1F1;
    s8 sp1F0;
    s32 sp1EC;
    f32 sp1E8;
    s32 sp1E4;
    s8 sp1E2;
    s8 sp1E1;
    s8 sp1E0;
    f64 sp1D8;                                      /* compiler-managed */
    f32 sp1D4;
    TrainTrack sp138;
    f64 sp130;
    f64 sp128;
    f32 sp118;
    f32 sp108;
    f64 sp100;
    f64 spF8;
    f64 spF0;
    f64 spE8;
    MKVector3 spD8;
    f64 spD0;
    f64 spC8;
    MKProp sp78;
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
    f64 sp28;
    f32 sp20;
    f64 sp18;
    s32 sp14;
    s32 sp10;
    ManagedLight *temp_r3_681;
    f32 temp_f1_366;
    f32 temp_f1_463;
    f32 temp_f1_466;
    f32 temp_f1_474;
    f32 temp_f1_490;
    f32 temp_f1_514;
    f32 temp_f1_517;
    f32 temp_f2_326;
    f32 temp_f2_342;
    f32 temp_f2_361;
    f32 temp_f2_449;
    f32 temp_f2_606;
    f32 temp_f3_327;
    f32 temp_f3_331;
    f32 temp_f3_348;
    f32 temp_f3_566;
    f32 temp_f4_562;
    f32 temp_f5_568;
    f32 temp_f7_605;
    f32 temp_f9_607;
    f32 var_f0_369;
    f32 var_f0_477;
    f32 var_f0_491;
    f32 var_f2_455;
    f32 var_f2_506;
    f64 temp_f0_663;
    s32 temp_r3_314;
    u8 temp_r0_344;
    void *temp_r3_339;
    void *temp_r3_687;

    if ((u8) this->unk130 != 0) {
        this->unk38C -= gUpdateTimeDelta;
    }
    temp_r3_314 = (long) (checked_cast<TrainTrack *, MKProp>(this->unk124->PropResolver_Resolve(M2C_ERROR(/* Read from unset register $r4 */))));
    if (temp_r3_314 != 0) {
        sp138.GetTrackZAxis(temp_r3_314, this->unk110);
        sp138.unk10 = M2C_BITWISE(f64, sp138);
        temp_f2_326 = M2C_BITWISE(f32, sp138.unk10);
        temp_f3_327 = M2C_BITWISE(f32, sp138.unk14);
        sp138.unk18 = M2C_BITWISE(f64, sp138.unk8);
        temp_f3_331 = M2C_BITWISE(f32, sp138.unk18);
        if (!(((temp_f3_331 * temp_f3_331) + ((temp_f2_326 * temp_f2_326) + (temp_f3_327 * temp_f3_327))) < 0.0001f)) {
            temp_r3_339 = checked_cast<TrainChaseSpyro *, MKProp>(this->unk12C->PropResolver_Resolve(M2C_ERROR(/* Read from unset register $r4 */)));
            if (temp_r3_339 != NULL) {
                temp_f2_342 = M2C_FIELD(temp_r3_339, f32 *, 0xDC);
                temp_r0_344 = this->unk130;
                temp_f3_348 = -((0.3f * (temp_f2_342 - M2C_FIELD(temp_r3_339, f32 *, 0xD8))) - temp_f2_342);
                if ((temp_r0_344 != 0) && (this->unk38C < 0.0f)) {
                    this->unk130 = 0;
                } else {
                    temp_f2_361 = M2C_FIELD(temp_r3_339, f32 *, 0xE0) - this->unk110;
                    if (temp_f2_361 < 1000.0f) {
                        temp_f1_366 = ((TrainTrack *) temp_r3_314)->GetTrackLength(1);
                        var_f0_369 = M2C_FIELD(temp_r3_339, f32 *, 0xE0) - 1000.0f;
                        if (var_f0_369 < temp_f1_366) {

                        } else {
                            var_f0_369 = temp_f1_366;
                        }
                        if (var_f0_369 > 0.0f) {

                        } else {
                            var_f0_369 = 0.0f;
                        }
                        this->unk110 = var_f0_369;
                        sp70 = 0.0f;
                        sp68 = 0.0f;
                        sp6C = 0.0f;
                        sp138.unk60.unkC = 0;
                        sp128 = (f64) sp68;
                        sp130 = (f64) sp70;
                        sp138.unk60.unk8 = 1e-44f;
                        sp138.unk88.unk8 = 1e-45f;
                        sp138.unk88.unkC = (s32) this;
                        sp138.unk60.unk10 = (f64) sp68;
                        sp138.unk74.unk4 = (f64) sp70;
                        sp1E0 = 0;
                        sp1EC = 2;
                        sp1E8 = 10.0f;
                        sp1E1 = 0;
                        sp1E2 = 1;
                        sp1E4 = -1;
                        sp138.unk74.unkC = M2C_FIELD(&MKVector3::one, f64 *, 0);
                        sp138.unk88 = M2C_FIELD(&MKVector3::one, f64 *, 8);
                        sp1F0 = 0;
                        if (this != NULL) {
                            sp78.GetPos();
                            sp138.unk88.unk10 = M2C_BITWISE(f64, sp78);
                            sp1D8 = M2C_BITWISE(f64, sp78.unk8);
                        } else {
                            sp138.unk88.unk10 = 0.0f;
                            sp1D4 = 0.0f;
                            sp1D8 = 0.0f;
                        }
                        sp1F1 = 0;
                        M2C_FIELD(M2C_FIELD(temp_r3_339, void **, 0x44), M2C_UNK (**)(void *, f32 *), 0x2C)(temp_r3_339, &sp138.unk60.unk8);
                        this->unk130 = 1;
                        this->unk38C = 0.7f;
                    } else if (temp_r0_344 != 0) {
                        temp_f2_449 = this->unk108;
                        this->unk108 = -((0.4f * temp_f2_449 * gUpdateTimeDelta) - temp_f2_449);
                        this->unk138.EmitBrakingEffects();
                        var_f2_455 = 0.25f;
                        if (1.0f > 0.25f) {

                        } else {
                            var_f2_455 = 1.0f;
                        }
                        temp_f1_463 = this->unk114;
                        temp_f1_466 = (var_f2_455 * (1.0f - temp_f1_463)) + temp_f1_463;
                        this->unk114 = (var_f2_455 * (1.0f - temp_f1_466)) + temp_f1_466;
                    } else {
                        temp_f1_474 = temp_f2_361 - 3000.0f;
                        if (temp_f1_474 > 0.0f) {
                            var_f0_477 = temp_f1_474 + temp_f3_348;
                        } else {
                            var_f0_477 = temp_f3_348;
                        }
                        this->unk108 = var_f0_477;
                        this->unk110 += this->unk108 * gUpdateTimeDelta;
                        temp_f1_490 = ((TrainTrack *) temp_r3_314)->GetTrackLength(1);
                        var_f0_491 = this->unk110;
                        if (var_f0_491 < temp_f1_490) {

                        } else {
                            var_f0_491 = temp_f1_490;
                        }
                        if (var_f0_491 > 0.0f) {

                        } else {
                            var_f0_491 = 0.0f;
                        }
                        this->unk110 = var_f0_491;
                        var_f2_506 = 0.25f;
                        if (1.0f > 0.25f) {

                        } else {
                            var_f2_506 = 1.0f;
                        }
                        temp_f1_514 = this->unk114;
                        temp_f1_517 = (var_f2_506 * (0.0f - temp_f1_514)) + temp_f1_514;
                        this->unk114 = (var_f2_506 * (0.0f - temp_f1_517)) + temp_f1_517;
                    }
                }
                if (this->unk110 < ((TrainTrack *) temp_r3_314)->GetTrackLength(1)) {
                    M2C_STRUCT_COPY((s32) &sp138.unk24 + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
                    ((TrainTrack *) &sp118)->GetTrackPos(temp_r3_314, this->unk110, 1);
                    sp138.unk4C.unkC = sp118;
                    sp138.unk4C.unk10 = sp11C;
                    sp138.unk60 = sp120;
                    sp138.unk60.unk4 = 1.0f;
                    ((TrainTrack *) &sp108)->GetTrackXAxis(temp_r3_314, this->unk110);
                    temp_f4_562 = M2C_BITWISE(f32, sp138.unk14);
                    temp_f3_566 = M2C_BITWISE(f32, sp138.unk18);
                    temp_f5_568 = M2C_BITWISE(f32, sp138.unk10);
                    sp138.unk28 = sp108;
                    sp60 = (temp_f5_568 * sp10C) - (temp_f4_562 * sp108);
                    sp58 = (temp_f4_562 * sp110) - (temp_f3_566 * sp10C);
                    sp5C = (temp_f3_566 * sp108) - (temp_f5_568 * sp110);
                    sp100 = (f64) sp60;
                    spF8 = (f64) sp58;
                    sp138.unk2C = sp10C;
                    sp138.unk30 = sp110;
                    sp138.unk34 = 0.0f;
                    sp138.unk48 = temp_f5_568;
                    sp138.unk4C = temp_f4_562;
                    sp138.unk4C.unk4 = temp_f3_566;
                    sp138.unk4C.unk8 = 0.0f;
                    sp138.unk38 = (f32) spF8;
                    sp138.unk3C = (*(f32 *) ((u8 *) &spF8 + 0x4));
                    sp138.unk40 = (f32) sp100;
                    sp138.__vptr = 0.0f;
                    Normalise(spD8);
                    temp_f7_605 = M2C_BITWISE(f32, sp138.unk4C.unk4);
                    temp_f2_606 = M2C_BITWISE(f32, spD8);
                    temp_f9_607 = M2C_BITWISE(f32, sp138.unk4C);
                    sp138.unk34 = 0.0f;
                    sp138.__vptr = 0.0f;
                    sp50 = (temp_f2_606 * temp_f9_607) - (spD8.unk4 * sp138.unk48);
                    sp48 = (spD8.unk4 * temp_f7_605) - (spD8.unk8 * temp_f9_607);
                    sp4C = (spD8.unk8 * sp138.unk48) - (temp_f2_606 * temp_f7_605);
                    spF0 = (f64) sp50;
                    spE8 = (f64) sp48;
                    sp138.unk28 = (f32) spE8;
                    sp138.unk2C = (*(f32 *) ((u8 *) &spE8 + 0x4));
                    sp138.unk30 = (f32) spF0;
                    sp40 = (sp138.unk48 * (*(f32 *) ((u8 *) &spE8 + 0x4))) - (temp_f9_607 * (f32) spE8);
                    sp38 = (temp_f9_607 * (f32) spF0) - (temp_f7_605 * (*(f32 *) ((u8 *) &spE8 + 0x4)));
                    sp3C = (temp_f7_605 * (f32) spE8) - (sp138.unk48 * (f32) spF0);
                    spD0 = (f64) sp40;
                    spC8 = (f64) sp38;
                    sp138.unk38 = (f32) spC8;
                    sp138.unk3C = (*(f32 *) ((u8 *) &spC8 + 0x4));
                    sp138.unk40 = (f32) spD0;
                    MKModel_SetWorldMatrix(this->unk4, *((Matrix *) &sp138.unk28));
                    if ((ManagedLight *) this->unk390 != NULL) {
                        ((MKVector3 *) &sp78.unk10)->operator*(500.0f);
                        ((MKVector3 *) &sp78.unk20)->operator*(500.0f);
                        temp_f0_663 = sp138.unk4C.unkC + (f64) sp78.unk20;
                        sp18 = temp_f0_663;
                        sp78.unk30 = temp_f0_663;
                        sp20 = M2C_BITWISE(f32, sp138.unk60) + M2C_BITWISE(f32, sp78.unk28);
                        sp78.unk38 = (f64) sp20;
                        sp28 = M2C_BITWISE(f64, sp78.unk30) + M2C_BITWISE(f64, sp78.unk10);
                        temp_r3_681 = this->unk390;
                        sp78.unk40 = sp28;
                        sp30 = M2C_BITWISE(f32, sp78.unk38) + M2C_BITWISE(f32, sp78.unk18);
                        temp_r3_681->unk10 = sp28;
                        temp_r3_681->unk18 = (f64) sp30;
                        temp_r3_687 = temp_r3_681->unk3C;
                        sp78.unk48 = (f64) sp30;
                        if (temp_r3_687 != NULL) {
                            M2C_FIELD(temp_r3_687, f64 *, 0x10) = sp28;
                            M2C_FIELD(temp_r3_687, f64 *, 0x18) = (f64) sp30;
                        }
                    }
                } else {
                    sp14 = 0;
                    sp10 = 0xB4;
                    Message(&sp10);
                }
                this->unk138.EmitSteam();
                this->unk3EC = (this->unk110 - M2C_FIELD(temp_r3_339, f32 *, 0xE0)) >= 4500.0f;
            }
        }
    }
}
#endif

void SteamTrain::StateChaseExit() {
    ManagedLight *temp_r4_734;

    temp_r4_734 = this->unk390;
    if (temp_r4_734 != NULL) {
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->FreeManagedLight(temp_r4_734);
        this->unk390 = NULL;
    }
    this->unk38C = 0.0f;
    this->unk130 = 0;
}

#if 0 // DRAFT: undefined identifier 'sp110'
void SteamTrain::StateChaseUpdate() {
    f32 sp16C;
    f32 sp168;
    f32 sp164;
    f32 sp160;
    f32 sp15C;
    f32 sp158;
    f32 sp154;
    f32 sp150;
    f32 sp14C;
    f32 sp148;
    f32 sp144;
    f32 sp140;
    f32 sp13C;
    f32 sp138;
    f32 sp134;
    f32 sp130;
    M2C_UNK sp12C;
    f64 sp120;
    f64 sp118;
    f64 sp108;
    f32 spF8;
    f32 spE8;
    f64 spE0;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    MKVector3 spB8;
    f64 spB0;
    f64 spA8;
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    MKVector3 sp78;
    MKVector3 sp68;
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
    f64 sp28;
    f32 sp20;
    f64 sp18;
    s32 sp14;
    s32 sp10;
    ManagedLight *temp_r3_998;
    f32 temp_f1_799;
    f32 temp_f1_822;
    f32 temp_f2_923;
    f32 var_f0_823;
    f64 temp_f0_980;
    s32 temp_r3_768;
    void *temp_r3_1004;
    void *temp_r3_793;

    temp_r3_768 = (long) (checked_cast<TrainTrack *, MKProp>(this->unk124->PropResolver_Resolve(M2C_ERROR(/* Read from unset register $r4 */))));
    if (temp_r3_768 != 0) {
        ((TrainTrack *) &sp108)->GetTrackZAxis(temp_r3_768, this->unk110);
        sp118 = sp108;
        sp120 = sp110;
        if (!((((f32) sp120 * (f32) sp120) + (((f32) sp118 * (f32) sp118) + ((*(f32 *) ((u8 *) &sp118 + 0x4)) * (*(f32 *) ((u8 *) &sp118 + 0x4))))) < 0.0001f)) {
            temp_r3_793 = checked_cast<TrainChaseSpyro *, MKProp>(this->unk12C->PropResolver_Resolve(M2C_ERROR(/* Read from unset register $r4 */)));
            if (temp_r3_793 != NULL) {
                temp_f1_799 = M2C_FIELD(temp_r3_793, f32 *, 0xE0) - this->unk110;
                if (temp_f1_799 < 1000.0f) {
                    ((KDStateMachine<SteamTrain> *) &this->unk378)->SetState(this, 5, 0U);
                } else {
                    this->unk104 = temp_f1_799;
                    this->unk108 += this->unk104 * gUpdateTimeDelta;
                    this->unk110 += this->unk108 * gUpdateTimeDelta;
                    temp_f1_822 = ((TrainTrack *) temp_r3_768)->GetTrackLength(1);
                    var_f0_823 = this->unk110;
                    if (var_f0_823 < temp_f1_822) {

                    } else {
                        var_f0_823 = temp_f1_822;
                    }
                    if (var_f0_823 > 0.0f) {

                    } else {
                        var_f0_823 = 0.0f;
                    }
                    this->unk110 = var_f0_823;
                }
                if (this->unk110 < ((TrainTrack *) temp_r3_768)->GetTrackLength(1)) {
                    M2C_STRUCT_COPY((s32) &sp12C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
                    ((TrainTrack *) &spF8)->GetTrackPos(temp_r3_768, this->unk110, 1);
                    sp160 = spF8;
                    sp164 = spFC;
                    sp168 = sp100;
                    sp16C = 1.0f;
                    ((TrainTrack *) &spE8)->GetTrackXAxis(temp_r3_768, this->unk110);
                    sp130 = spE8;
                    sp60 = ((f32) sp118 * spEC) - ((*(f32 *) ((u8 *) &sp118 + 0x4)) * spE8);
                    sp58 = ((*(f32 *) ((u8 *) &sp118 + 0x4)) * spF0) - ((f32) sp120 * spEC);
                    sp5C = ((f32) sp120 * spE8) - ((f32) sp118 * spF0);
                    spE0 = (f64) sp60;
                    spD8 = (f64) sp58;
                    sp134 = spEC;
                    sp138 = spF0;
                    sp13C = 0.0f;
                    sp150 = (f32) sp118;
                    sp154 = (*(f32 *) ((u8 *) &sp118 + 0x4));
                    sp158 = (f32) sp120;
                    sp15C = 0.0f;
                    sp140 = (f32) spD8;
                    sp144 = (*(f32 *) ((u8 *) &spD8 + 0x4));
                    sp148 = (f32) spE0;
                    sp14C = 0.0f;
                    Normalise(spB8);
                    temp_f2_923 = M2C_BITWISE(f32, spB8);
                    sp13C = 0.0f;
                    sp14C = 0.0f;
                    sp50 = (temp_f2_923 * sp154) - (spB8.unk4 * sp150);
                    sp48 = (spB8.unk4 * sp158) - (spB8.unk8 * sp154);
                    sp4C = (spB8.unk8 * sp150) - (temp_f2_923 * sp158);
                    spD0 = (f64) sp50;
                    spC8 = (f64) sp48;
                    sp130 = (f32) spC8;
                    sp134 = (*(f32 *) ((u8 *) &spC8 + 0x4));
                    sp138 = (f32) spD0;
                    sp40 = (sp150 * (*(f32 *) ((u8 *) &spC8 + 0x4))) - (sp154 * (f32) spC8);
                    sp38 = (sp154 * (f32) spD0) - (sp158 * (*(f32 *) ((u8 *) &spC8 + 0x4)));
                    sp3C = (sp158 * (f32) spC8) - (sp150 * (f32) spD0);
                    spB0 = (f64) sp40;
                    spA8 = (f64) sp38;
                    sp140 = (f32) spA8;
                    sp144 = (*(f32 *) ((u8 *) &spA8 + 0x4));
                    sp148 = (f32) spB0;
                    MKModel_SetWorldMatrix(this->unk4, *((Matrix *) &sp130));
                    if ((ManagedLight *) this->unk390 != NULL) {
                        sp68.operator*(500.0f);
                        sp78.operator*(500.0f);
                        temp_f0_980 = sp160 + M2C_BITWISE(f64, sp78);
                        sp18 = temp_f0_980;
                        sp88 = temp_f0_980;
                        sp20 = sp168 + sp78.unk8;
                        sp90 = (f64) sp20;
                        sp28 = sp88 + M2C_BITWISE(f64, sp68);
                        temp_r3_998 = this->unk390;
                        sp98 = sp28;
                        sp30 = (f32) sp90 + sp68.unk8;
                        temp_r3_998->unk10 = sp28;
                        temp_r3_998->unk18 = (f64) sp30;
                        temp_r3_1004 = temp_r3_998->unk3C;
                        spA0 = (f64) sp30;
                        if (temp_r3_1004 != NULL) {
                            M2C_FIELD(temp_r3_1004, f64 *, 0x10) = sp28;
                            M2C_FIELD(temp_r3_1004, f64 *, 0x18) = (f64) sp30;
                        }
                    }
                } else {
                    sp14 = 0;
                    sp10 = 0xB4;
                    Message(&sp10);
                }
                this->unk138.EmitSteam();
                this->unk3EC = (this->unk110 - M2C_FIELD(temp_r3_793, f32 *, 0xE0)) >= 4500.0f;
            }
        }
    }
}
#endif

void SteamTrain::StateChaseEnter() {
    this->unk114 = 0.0f;
}

void SteamTrain::StateFallBackExit() {

}

#if 0 // DRAFT: undefined identifier 'sp104'
void SteamTrain::StateFallBackUpdate() {
    f32 sp14C;
    f32 sp148;
    f32 sp144;
    f32 sp140;
    f32 sp13C;
    f32 sp138;
    f32 sp134;
    f32 sp130;
    f32 sp12C;
    f32 sp128;
    f32 sp124;
    f32 sp120;
    f32 sp11C;
    f32 sp118;
    f32 sp114;
    f32 sp110;
    BoundingVolume *sp10C;
    f32 sp100;
    f32 spF0;
    f32 spE0;
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
    MKVector3 sp70;
    MKVector3 sp60;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    ManagedLight *temp_r3_1267;
    f32 temp_f2_1075;
    f32 temp_f2_1089;
    f32 temp_f2_1093;
    f32 temp_f2_1097;
    f32 temp_f2_1192;
    f32 var_f3_1081;
    f64 temp_f0_1249;
    s32 temp_r3_1070;
    void *temp_r3_1273;
    void *temp_r3_1282;

    temp_r3_1070 = (long) (checked_cast<TrainTrack *, MKProp>(this->unk124->PropResolver_Resolve(M2C_ERROR(/* Read from unset register $r4 */))));
    if (temp_r3_1070 != 0) {
        temp_f2_1075 = this->unk108;
        this->unk108 = -((0.8f * temp_f2_1075 * gUpdateTimeDelta) - temp_f2_1075);
        this->unk138.EmitBrakingEffects();
        var_f3_1081 = 0.25f;
        if (1.0f > 0.25f) {

        } else {
            var_f3_1081 = 1.0f;
        }
        temp_f2_1089 = this->unk114;
        temp_f2_1093 = (var_f3_1081 * (1.0f - temp_f2_1089)) + temp_f2_1089;
        this->unk114 = (var_f3_1081 * (1.0f - temp_f2_1093)) + temp_f2_1093;
        temp_f2_1097 = this->unk108;
        if (temp_f2_1097 > 0.0f) {
            this->unk110 += temp_f2_1097 * gUpdateTimeDelta;
        }
        M2C_STRUCT_COPY((s32) &sp10C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
        ((TrainTrack *) &sp100)->GetTrackPos(temp_r3_1070, this->unk110, 1);
        sp140 = sp100;
        sp144 = sp104;
        sp148 = sp108;
        sp14C = 1.0f;
        ((TrainTrack *) &spF0)->GetTrackXAxis(temp_r3_1070, this->unk110);
        sp110 = spF0;
        sp114 = spF4;
        sp118 = spF8;
        sp11C = 0.0f;
        ((TrainTrack *) &spE0)->GetTrackZAxis(temp_r3_1070, this->unk110);
        sp130 = spE0;
        sp134 = spE4;
        sp50 = (spE4 * sp118) - (spE8 * sp114);
        sp54 = (spE8 * sp110) - (spE0 * sp118);
        sp58 = (spE0 * sp114) - (spE4 * sp110);
        spD0 = (f64) sp50;
        spD8 = (f64) sp58;
        sp138 = spE8;
        sp13C = 0.0f;
        sp120 = (f32) spD0;
        sp124 = (*(f32 *) ((u8 *) &spD0 + 0x4));
        sp128 = (f32) spD8;
        sp12C = 0.0f;
        Normalise(spB0);
        temp_f2_1192 = M2C_BITWISE(f32, spB0);
        sp11C = 0.0f;
        sp12C = 0.0f;
        sp48 = (temp_f2_1192 * sp134) - (spB0.unk4 * sp130);
        sp40 = (spB0.unk4 * sp138) - (spB0.unk8 * sp134);
        sp44 = (spB0.unk8 * sp130) - (temp_f2_1192 * sp138);
        spC8 = (f64) sp48;
        spC0 = (f64) sp40;
        sp110 = (f32) spC0;
        sp114 = (*(f32 *) ((u8 *) &spC0 + 0x4));
        sp118 = (f32) spC8;
        sp38 = (sp130 * (*(f32 *) ((u8 *) &spC0 + 0x4))) - (sp134 * (f32) spC0);
        sp30 = (sp134 * (f32) spC8) - (sp138 * (*(f32 *) ((u8 *) &spC0 + 0x4)));
        sp34 = (sp138 * (f32) spC0) - (sp130 * (f32) spC8);
        spA8 = (f64) sp38;
        spA0 = (f64) sp30;
        sp120 = (f32) spA0;
        sp124 = (*(f32 *) ((u8 *) &spA0 + 0x4));
        sp128 = (f32) spA8;
        MKModel_SetWorldMatrix(this->unk4, *((Matrix *) &sp110));
        if ((ManagedLight *) this->unk390 != NULL) {
            sp60.operator*(500.0f);
            sp70.operator*(500.0f);
            temp_f0_1249 = sp140 + M2C_BITWISE(f64, sp70);
            sp10 = temp_f0_1249;
            sp80 = temp_f0_1249;
            sp18 = sp148 + sp70.unk8;
            sp88 = (f64) sp18;
            sp20 = sp80 + M2C_BITWISE(f64, sp60);
            temp_r3_1267 = this->unk390;
            sp90 = sp20;
            sp28 = (f32) sp88 + sp60.unk8;
            temp_r3_1267->unk10 = sp20;
            temp_r3_1267->unk18 = (f64) sp28;
            temp_r3_1273 = temp_r3_1267->unk3C;
            sp98 = (f64) sp28;
            if (temp_r3_1273 != NULL) {
                M2C_FIELD(temp_r3_1273, f64 *, 0x10) = sp20;
                M2C_FIELD(temp_r3_1273, f64 *, 0x18) = (f64) sp28;
            }
        }
        temp_r3_1282 = checked_cast<TrainChaseSpyro *, MKProp>(this->unk12C->PropResolver_Resolve(M2C_ERROR(/* Read from unset register $r4 */)));
        if (temp_r3_1282 != NULL) {
            this->unk3EC = (this->unk110 - M2C_FIELD(temp_r3_1282, f32 *, 0xE0)) >= 4500.0f;
        }
    }
}
#endif

void SteamTrain::StateFallBackEnter() {

}

void SteamTrain::StateFleeExit() {

}

#if 0 // DRAFT: undefined identifier 'sp108'
void SteamTrain::StateFleeUpdate() {
    f32 sp15C;
    f32 sp158;
    f32 sp154;
    f32 sp150;
    f32 sp14C;
    f32 sp148;
    f32 sp144;
    f32 sp140;
    f32 sp13C;
    f32 sp138;
    f32 sp134;
    f32 sp130;
    f32 sp12C;
    f32 sp128;
    f32 sp124;
    f32 sp120;
    f64 sp118;
    f64 sp110;
    f64 sp100;
    f32 spF0;
    f32 spE0;
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
    MKVector3 sp70;
    MKVector3 sp60;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    ManagedLight *temp_r3_1643;
    f32 temp_f1_1436;
    f32 temp_f1_1439;
    f32 temp_f1_1460;
    f32 temp_f1_1463;
    f32 temp_f1_1479;
    f32 temp_f2_1422;
    f32 temp_f2_1568;
    f32 temp_f4_1379;
    f32 var_f1_1349;
    f32 var_f1_1394;
    f32 var_f2_1378;
    f32 var_f2_1428;
    f32 var_f2_1452;
    f32 var_f31_1343;
    f64 temp_f0_1625;
    s32 temp_r3_1330;
    void *temp_r3_1373;
    void *temp_r3_1649;

    temp_r3_1330 = (long) (checked_cast<TrainTrack *, MKProp>(this->unk124->PropResolver_Resolve(M2C_ERROR(/* Read from unset register $r4 */))));
    if (temp_r3_1330 != 0) {
        ((TrainTrack *) &sp100)->GetTrackZAxis(temp_r3_1330, this->unk110);
        sp110 = sp100;
        var_f31_1343 = 1.0f;
        sp118 = sp108;
        if (((u8) this->unk3ED == 0) && ((u8) this->unk3EE == 0)) {
            var_f1_1349 = (*(f32 *) ((u8 *) &sp110 + 0x4));
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
        temp_r3_1373 = checked_cast<TrainChaseSpyro *, MKProp>(this->unk12C->PropResolver_Resolve(M2C_ERROR(/* Read from unset register $r4 */)));
        if (temp_r3_1373 != NULL) {
            var_f2_1378 = 0.0f;
            temp_f4_1379 = this->unk110 - M2C_FIELD(temp_r3_1373, f32 *, 0xE0);
            if (var_f2_1378 > temp_f4_1379) {

            } else {
                var_f2_1378 = temp_f4_1379;
            }
            this->unk104 = 2000.0f * (1.0f - (var_f2_1378 / this->unk120));
            var_f1_1394 = this->unk104;
            if (var_f1_1394 < 2000.0f) {

            } else {
                var_f1_1394 = 2000.0f;
            }
            if (var_f1_1394 > -500.0f) {

            } else {
                var_f1_1394 = -500.0f;
            }
            this->unk104 = var_f1_1394;
            if (temp_f4_1379 < 0.0f) {
                var_f31_1343 += 0.15f;
            }
            if ((u8) this->unk130 != 0) {
                this->unk130 = 0;
                temp_f2_1422 = this->unk108;
                this->unk108 = -((0.8f * temp_f2_1422 * gUpdateTimeDelta) - temp_f2_1422);
                this->unk138.EmitBrakingEffects();
                var_f2_1428 = 0.25f;
                if (1.0f > 0.25f) {

                } else {
                    var_f2_1428 = 1.0f;
                }
                temp_f1_1436 = this->unk114;
                temp_f1_1439 = (var_f2_1428 * (1.0f - temp_f1_1436)) + temp_f1_1436;
                this->unk114 = (var_f2_1428 * (1.0f - temp_f1_1439)) + temp_f1_1439;
            } else {
                this->unk108 += this->unk104 * gUpdateTimeDelta;
                this->unk138.EmitSteam();
                var_f2_1452 = 0.25f;
                if (1.0f > 0.25f) {

                } else {
                    var_f2_1452 = 1.0f;
                }
                temp_f1_1460 = this->unk114;
                temp_f1_1463 = (var_f2_1452 * (0.0f - temp_f1_1460)) + temp_f1_1460;
                this->unk114 = (var_f2_1452 * (0.0f - temp_f1_1463)) + temp_f1_1463;
            }
            if (((u8) this->unk131 == 0) || !((this->unk110 - M2C_FIELD(temp_r3_1373, f32 *, 0xE0)) < 6000.0f)) {
                temp_f1_1479 = this->unk10C;
                if (this->unk108 > temp_f1_1479) {
                    this->unk108 = temp_f1_1479;
                }
            }
            this->unk110 += gUpdateTimeDelta * (this->unk108 * var_f31_1343);
            M2C_STRUCT_COPY((s32) &unksp11C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
            ((TrainTrack *) &spF0)->GetTrackPos(temp_r3_1330, this->unk110, 1);
            sp150 = spF0;
            sp154 = spF4;
            sp158 = spF8;
            sp15C = 1.0f;
            ((TrainTrack *) &spE0)->GetTrackXAxis(temp_r3_1330, this->unk110);
            sp120 = spE0;
            sp58 = ((f32) sp110 * spE4) - ((*(f32 *) ((u8 *) &sp110 + 0x4)) * spE0);
            sp50 = ((*(f32 *) ((u8 *) &sp110 + 0x4)) * spE8) - ((f32) sp118 * spE4);
            sp54 = ((f32) sp118 * spE0) - ((f32) sp110 * spE8);
            spD8 = (f64) sp58;
            spD0 = (f64) sp50;
            sp124 = spE4;
            sp128 = spE8;
            sp12C = 0.0f;
            sp140 = (f32) sp110;
            sp144 = (*(f32 *) ((u8 *) &sp110 + 0x4));
            sp148 = (f32) sp118;
            sp14C = 0.0f;
            sp130 = (f32) spD0;
            sp134 = (*(f32 *) ((u8 *) &spD0 + 0x4));
            sp138 = (f32) spD8;
            sp13C = 0.0f;
            Normalise(spB0);
            temp_f2_1568 = M2C_BITWISE(f32, spB0);
            sp12C = 0.0f;
            sp13C = 0.0f;
            sp48 = (temp_f2_1568 * sp144) - (spB0.unk4 * sp140);
            sp40 = (spB0.unk4 * sp148) - (spB0.unk8 * sp144);
            sp44 = (spB0.unk8 * sp140) - (temp_f2_1568 * sp148);
            spC8 = (f64) sp48;
            spC0 = (f64) sp40;
            sp120 = (f32) spC0;
            sp124 = (*(f32 *) ((u8 *) &spC0 + 0x4));
            sp128 = (f32) spC8;
            sp38 = (sp140 * (*(f32 *) ((u8 *) &spC0 + 0x4))) - (sp144 * (f32) spC0);
            sp30 = (sp144 * (f32) spC8) - (sp148 * (*(f32 *) ((u8 *) &spC0 + 0x4)));
            sp34 = (sp148 * (f32) spC0) - (sp140 * (f32) spC8);
            spA8 = (f64) sp38;
            spA0 = (f64) sp30;
            sp130 = (f32) spA0;
            sp134 = (*(f32 *) ((u8 *) &spA0 + 0x4));
            sp138 = (f32) spA8;
            MKModel_SetWorldMatrix(this->unk4, *((Matrix *) &sp120));
            if ((ManagedLight *) this->unk390 != NULL) {
                sp60.operator*(500.0f);
                sp70.operator*(500.0f);
                temp_f0_1625 = sp150 + M2C_BITWISE(f64, sp70);
                sp10 = temp_f0_1625;
                sp80 = temp_f0_1625;
                sp18 = sp158 + sp70.unk8;
                sp88 = (f64) sp18;
                sp20 = sp80 + M2C_BITWISE(f64, sp60);
                temp_r3_1643 = this->unk390;
                sp90 = sp20;
                sp28 = (f32) sp88 + sp60.unk8;
                temp_r3_1643->unk10 = sp20;
                temp_r3_1643->unk18 = (f64) sp28;
                temp_r3_1649 = temp_r3_1643->unk3C;
                sp98 = (f64) sp28;
                if (temp_r3_1649 != NULL) {
                    M2C_FIELD(temp_r3_1649, f64 *, 0x10) = sp20;
                    M2C_FIELD(temp_r3_1649, f64 *, 0x18) = (f64) sp28;
                }
            }
            this->unk3EC = (this->unk110 - M2C_FIELD(temp_r3_1373, f32 *, 0xE0)) >= 4500.0f;
        }
    }
}
#endif

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
    ManagedLight *temp_r4_1724;

    if ((ManagedLight *) this->unk390 == NULL) {
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
        this->unk390 = (ManagedLight *) (((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->AllocManagedLight(*((MKVector3 *) &sp58), *((MKVector3 *) &sp48), *((MKVector4 *) &sp38), 1500.0f, lit_1019, lit_1020));
        temp_r4_1724 = this->unk390;
        if (temp_r4_1724 != NULL) {
            ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->EnableLight(temp_r4_1724, 1U);
        }
    }
}

#if 0 // DRAFT: function call 'KDSound_Play3d(long, unsigned char *, unsigned int, int, float, unsigned int)' does not match 'KDSound_Play3d(MKAnimScript *, const MKVector3 *, 
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
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f64 sp8;
    SteamTrain *var_r0_1945;
    f32 temp_f1_1870;
    f32 temp_f1_1913;
    f64 temp_f0_1856;
    f64 temp_f4_1818;
    f64 temp_f5_1817;
    s32 temp_r0_1752;
    s32 temp_r31_1930;
    void *temp_r3_1814;
    void *temp_r3_1943;
    void *temp_r4_1815;

    ((KDSoundPlayer *) &this->unk394)->Message(arg0);
    ((KDSoundPlayer *) &this->unk3BC)->Message(arg0);
    temp_r0_1752 = arg0->unk0;
    switch (temp_r0_1752) {                         /* irregular */
    case 0xB5:
        Enable();
        ((KDStateMachine<SteamTrain> *) &this->unk378)->SetState(this, 2, 0U);
        this->unk3F0 = 1;
    default:
block_30:
        GameProp::Message(arg0);
        return;
    case 0xB4:
        ((KDStateMachine<SteamTrain> *) &this->unk378)->SetState(this, 1, 0U);
        this->unk3F0 = 0;
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
        sp28 = M2C_FIELD(temp_r3_1814, f64 *, 0x10) - sp58;
        sp68 = sp28;
        sp30 = M2C_FIELD(temp_r3_1814, f32 *, 0x18) - (f32) sp60;
        sp70 = (f64) sp30;
        if ((((f32) sp70 * (f32) sp70) + (((f32) sp68 * (f32) sp68) + ((*(f32 *) ((u8 *) &sp68 + 0x4)) * (*(f32 *) ((u8 *) &sp68 + 0x4))))) < 1000000.0f) {
            sp18 = 0.0f;
            sp1C = 500.0f;
            sp20 = 0.0f;
            sp38 = (f64) sp18;
            sp48 = temp_f5_1817;
            sp40 = (f64) sp20;
            sp50 = temp_f4_1818;
            temp_f0_1856 = sp48 + sp38;
            sp8 = temp_f0_1856;
            sp78 = temp_f0_1856;
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
        if (this->unk118 <= 0.0f) {
            this->unk118 = 0.75f;
            KDSound_Play3d(GS_TrainHit, ((u8 *) this->unk8) + 0x30, 0U, -1, 0.0f, 0U);
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
        ((KDStateMachine<SteamTrain> *) &this->unk378)->SetState(this, 2, 0U);
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

void SteamTrain::Deinit() {
    MKMaterial *temp_r3_1984;
    ManagedLight *temp_r4_1974;

    ((KDStateMachine<SteamTrain> *) &this->unk378)->Deinit(this);
    temp_r4_1974 = this->unk390;
    if (temp_r4_1974 != NULL) {
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->FreeManagedLight(temp_r4_1974);
        this->unk390 = NULL;
    }
    temp_r3_1984 = this->unk100;
    if (temp_r3_1984 != NULL) {
        MKMaterial_Destroy(temp_r3_1984);
        this->unk100 = NULL;
    }
    this->unkD0.Deinit();
    KDSound_Stop((int *) &this->unk394);
    KDSound_Stop((int *) &this->unk3BC);
    this->unk3EF = 0;
    this->unk3F0 = 0;
    GameProp::Deinit();
}

void SteamTrain::Draw() {
    GameProp::Draw();
    this->unk138.Draw();
}

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
    f64 sp88;
    f32 sp80;
    f64 sp78;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp60;
    f64 sp58;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp40;
    f64 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f64 sp18;
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
    f64 temp_f0_2085;
    f64 temp_f0_2115;
    f64 temp_f0_2148;
    f64 temp_f0_2180;
    s32 var_r30_2060;
    void *temp_r4_2111;

    var_r30_2060 = 0;
    do {
        temp_f24_2066 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
        temp_f23_2071 = MKRand_Float((int *) &gViewSeed, 1.0f, 3.0f);
        sp98 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
        sp9C = temp_f23_2071;
        spA0 = temp_f24_2066;
        sp118 = (f64) sp98;
        sp120 = (f64) spA0;
        temp_f0_2085 = sp118 * 5.70130949e-315;
        sp88 = temp_f0_2085;
        sp128 = temp_f0_2085;
        sp90 = (f32) sp120 * 1600.0f;
        sp130 = (f64) sp90;
        sp78 = temp_f0_2085 * (f64) arg1;
        sp68 = 0.0f;
        sp6C = 300.0f;
        sp80 = (f32) sp130 * arg1;
        sp70 = 0.0f;
        sp138 = sp78;
        sp140 = (f64) sp80;
        spF8 = (f64) sp68;
        temp_r4_2111 = ((u8 *) this->unk8) + 0x30;
        sp100 = (f64) sp70;
        temp_f0_2115 = M2C_FIELD(temp_r4_2111, f64 *, 0) + spF8;
        sp58 = temp_f0_2115;
        sp108 = temp_f0_2115;
        sp60 = M2C_FIELD(temp_r4_2111, f32 *, 8) + (f32) sp100;
        sp110 = (f64) sp60;
        temp_f24_2129 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
        temp_f23_2134 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
        sp48 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
        sp4C = temp_f23_2134;
        sp50 = temp_f24_2129;
        spD8 = (f64) sp48;
        spE0 = (f64) sp50;
        temp_f0_2148 = spD8 * 5.328646264e-315;
        sp38 = temp_f0_2148;
        spE8 = temp_f0_2148;
        sp40 = (f32) spE0 * 3.1415927f;
        spF0 = (f64) sp40;
        temp_f23_2161 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
        temp_f24_2166 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
        sp28 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
        sp2C = temp_f24_2166;
        sp30 = temp_f23_2161;
        spB8 = (f64) sp28;
        spC0 = (f64) sp30;
        temp_f0_2180 = spB8 * 5.328646264e-315;
        sp18 = temp_f0_2180;
        spC8 = temp_f0_2180;
        sp20 = (f32) spC0 * 3.1415927f;
        spD0 = (f64) sp20;
        temp_f1_2192 = MKRand_Float((int *) &gViewSeed, 0.75f, 1.0f);
        sp8 = 1.0f;
        spC = 1.0f;
        sp10 = 1.0f;
        sp14 = 1.0f;
        spA8 = (f64) sp8;
        spB0 = (f64) sp10;
        ((FlyingChunkPS *) (M2C_FIELD(&gb, FlyingChunkPS **, 0xA0)))->Emit(*((MKVector3 *) &sp108), *((MKVector3 *) &sp138), *((MKVector3 *) &spE8), *((MKVector3 *) &spC8), arg1 * temp_f1_2192, *((MKVector4 *) &spA8), 0, NULL);
        var_r30_2060 += 1;
    } while (var_r30_2060 < 0xA);
    if (this->unk11C <= 0.0f) {
        this->unk11C = 1.0f;
        KDSound_Play3d(GS_CabooseExtra1, &arg0, 0U, -1, 0.0f, 0U);
    }
}

#if 0 // DRAFT: function call 'KDSound_Play3d(long, unsigned char *, unsigned int, int, float, unsigned int)' does not match 'KDSound_Play3d(MKAnimScript *, const MKVector3 *, 
void *SteamTrain::Update() {
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
    ((KDStateMachine<SteamTrain> *) &this->unk378)->Update(this, 0);
    this->unk138.unk230 = this->unk108;
    this->unk138.unk234 = this->unk10C;
    this->unk138.Update();
    temp_f1_2272 = this->unk118;
    if (temp_f1_2272 > 0.0f) {
        this->unk118 = temp_f1_2272 - gUpdateTimeDelta;
    }
    temp_f1_2280 = this->unk11C;
    if (temp_f1_2280 > 0.0f) {
        this->unk11C = temp_f1_2280 - gUpdateTimeDelta;
    }
    if ((u8) this->unk3EC != 0) {
        temp_f1_2291 = this->unk3E8;
        if (temp_f1_2291 >= 15.0f) {
            this->unk3E8 = 0.0f;
            KDSound_Play3d(GS_Train4, ((u8 *) this->unk8) + 0x30, 0U, -1, 0.0f, 0U);
        } else {
            this->unk3E8 = temp_f1_2291 + gUpdateTimeDelta;
        }
    } else {
        this->unk3E8 = 0.0f;
    }
    temp_f2_2315 = this->unk114;
    if (temp_f2_2315 <= 0.01f) {
        MKMaterial_SetParameter(this->unk100, (MKMaterialParameter) 6, 1);
        this->unk3EF = 0;
    } else {
        sp20 = temp_f2_2315;
        sp24 = 0.0f;
        sp28 = 0.0f;
        sp2C = 1.0f;
        MKMaterial_SetColor(this->unk100, *((MKVector4 *) &sp20));
        MKMaterial_SetParameter(this->unk100, (MKMaterialParameter) 6, 0);
        this->unk3EF = 1;
    }
    sp8 = 1;
    ((KDSoundFader *) &this->unk394)->Update(GS_TrainEngineBreakLP, 1U, this->unk3EF, (MKProp *) this, NULL, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    temp_f2_2355 = this->unk108;
    if (temp_f2_2355 <= 1800.0f) {
        KDSound_SetPitch(this->unk3BC, 0.9f);
    } else {
        KDSound_SetPitch(this->unk3BC, (0.000025f * temp_f2_2355) + 0.98f);
    }
    sp8 = 1;
    ((KDSoundFader *) &this->unk3BC)->Update(GS_TrainEngineLP, 1U, this->unk3F0, (MKProp *) this, NULL, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    temp_r3_2382 = this->unk8;
    sp10 = M2C_FIELD(temp_r3_2382, f64 *, 0x30);
    sp18 = M2C_FIELD(temp_r3_2382, f64 *, 0x38);
    this->unkD0.unk28 = (*(f32 *) ((u8 *) &sp10 + 0x4));
}
#endif

void SteamTrain::Reset() {
    void *temp_r3_2424;

    GameProp::Reset();
    this->unk104 = 0.0f;
    this->unk108 = 3500.0f;
    this->unk110 = 3000.0f;
    this->unk114 = 0.0f;
    this->unk118 = 0.75f;
    this->unk11C = 1.0f;
    this->unk3E8 = 0.0f;
    this->unk3EC = 0;
    this->unk3ED = 0;
    this->unk3EE = 0;
    this->unk130 = 0;
    this->unk131 = 0;
    temp_r3_2424 = this->unk128->PropResolver_Resolve(M2C_ERROR(/* Read from unset register $r4 */));
    if (temp_r3_2424 != NULL) {
        M2C_FIELD(M2C_FIELD(temp_r3_2424, void **, 0x44), M2C_UNK (**)(), 0x20)();
    }
}

f32 SteamTrain::Resolve() {
    KDPropEx::Resolve();
    this->unk138.Resolve();
}

#if 0 // DRAFT: illegal implicit conversion from 'signed char **' to 'const char **'
s32 SteamTrain::LoadDone() {
    s32 var_r30_2501;
    s32 var_r31_2502;

    GameProp::LoadDone();
    this->unk80->InitEvents(&pSteamAnimEvents);
    this->unk134 = (long) (checked_cast<Explosion3 *, MKProp>(gMK->CreateProp("Explosion3")));
    ((Animation *) (MKModel_GetAnimation(this->unk4)))->EnableCustomMatrices(1U);
    this->unk138.Init((Matrix *) this->unk8, this->unk4, this->unk80);
    this->unk138.unkC = this;
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
    ((KDStateMachine<SteamTrain> *) &this->unk378)->Init((KDStateMachine<SteamTrain>::State *) SteamTrain::states, NULL);
    ((KDStateMachine<SteamTrain> *) &this->unk378)->SetState(this, 1, 0U);
    Disable();
}
#endif

s32 SteamTrain::LoadLine(MKIniLine *arg0) {
    s32 var_r31_2549;

    var_r31_2549 = 0;
    if ((GameProp::LoadLine(arg0) != 0) || (arg0->LoadInt("trackID", (int *) &this->unk124, 0) != 0) || (arg0->LoadInt("cabooseID", (int *) &this->unk128, 0) != 0) || (arg0->LoadInt("SpyroCartID", (int *) &this->unk12C, 0) != 0)) {
        var_r31_2549 = 1;
    }
    return var_r31_2549;
}

void SteamTrain::Init() {
    GameProp::Init();
    this->unk104 = 0.0f;
    this->unk108 = 3500.0f;
    this->unk110 = 3000.0f;
    this->unk390 = NULL;
    this->unk114 = 0.0f;
    this->unk124 = NULL;
    this->unk128 = NULL;
    this->unk12C = NULL;
    this->unk118 = 0.75f;
    this->unk11C = 1.0f;
    this->unk3E8 = 0.0f;
    this->unk120 = 6000.0f;
    ((KDSoundFader *) &this->unk394)->Init(0.25f, 0.5f);
    ((KDSoundFader *) &this->unk3BC)->Init(0.25f, 0.25f);
    this->unk3EF = 0;
    this->unk3F0 = 0;
    this->unk3EC = 0;
    this->unk3ED = 0;
    this->unk3EE = 0;
    this->unk130 = 0;
    this->unk131 = 0;
    this->unk3E4 = 50.0f;
}

#if 0 // DRAFT: undefined identifier 'unkE4'
void SteamTrainDescriptor::LoadDone() {
    GamePropDescriptor::LoadDone();
    this->unkE4 = ((MKAnimScript *) this->unk34)->GetAnim("idle01");
    this->unkE8 = (s32) Tools_GetMatchingSubObjectIndex((SubObjectType) 0, this->unk2C, "Engine_damaged");
    this->unkEC = (s32) Tools_GetMatchingSubObjectIndex((SubObjectType) 0, this->unk2C, "Guard_F_R_damaged");
    this->unkF0 = (s32) Tools_GetMatchingSubObjectIndex((SubObjectType) 0, this->unk2C, "Pipe_damaged");
    this->unkF4 = (s32) Tools_GetMatchingSubObjectIndex((SubObjectType) 0, this->unk2C, "Piston_R_damaged");
    this->unkF8 = (s32) Tools_GetMatchingSubObjectIndex((SubObjectType) 0, this->unk2C, "spike_01_damaged");
}
#endif

void SteamTrainEffects::UpdateWheelBone(MKDynamicBone *arg0, void *arg1) {
    Matrix sp30;
    M2C_UNK sp2C;
    f64 sp28;
    f64 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    s16 temp_r31_2757;

    M2C_STRUCT_COPY((s32) &sp2C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
    sp10 = -arg0->unk0;
    sp14 = -arg0->unk4;
    sp18 = -arg0->unk8;
    sp20 = (f64) sp10;
    sp28 = (f64) sp18;
    sp30.Translate(&sp30, *((MKVector3 *) &sp20));
    sp30.RotatePitch(&sp30, arg0->unk10);
    sp30.Translate(&sp30, *((MKVector3 *) arg0));
    temp_r31_2757 = M2C_FIELD(this->unk20, s16 *, 0x70);
    ((Animation *) (MKModel_GetAnimation(this->unk24)))->SetCustomMatrix((s32) temp_r31_2757, &sp30, (AnimationMatrixPosition) 4, 0U);
}

#if 0 // DRAFT: undefined identifier 'MKVector'
void SteamTrainEffects::UpdateAnimEvents() {
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f64 sp8;
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
                M2C_FIELD(temp_r3_2797, f32 *, 0x24) = MKRand_Float((int *) &gViewSeed, -6.2831855f, 6.2831855f);
                temp_f30_2821 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
                temp_f29_2826 = MKRand_Float((int *) &gViewSeed, 0.75f, 1.0f);
                MKVector(MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f), temp_f29_2826, temp_f30_2821);
                sp8 = sp28 * 5.65986426e-315;
                M2C_FIELD(temp_r29_2802, f64 *, 0) = sp8;
                sp10 = sp30 * 800.0f;
                sp38 = sp8;
                sp40 = (f64) sp10;
                M2C_FIELD(temp_r29_2802, f64 *, 8) = (f64) sp10;
                M2C_FIELD(temp_r29_2802, f32 *, 0x18) = MKRand_Float((int *) &gViewSeed, 0.5f, 1.0f);
                M2C_FIELD(temp_r29_2802, f32 *, 0x10) = MKRand_Float((int *) &gViewSeed, -6.2831855f, 6.2831855f);
                M2C_FIELD(temp_r29_2802, f32 *, 0x14) = (f32) M2C_FIELD(this->unk1E4, f32 *, 0xF4);
            }
            var_r30_2791 += 1;
        } while (var_r30_2791 < 5);
    }
}
#endif

#if 0 // DRAFT: function call 'MKModel_GetRefPointMatrix(MKModel *, SteamTrainEffects, Matrix *, unsigned int)' does not match 'MKModel_GetRefPointMatrix(const MKModel *, int, 
void SteamTrainEffects::DrawEffects() {
    Matrix sp10;
    M2C_UNK spC;
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
        MKModel_GetRefPointMatrix(this->unk4, *(this + (var_r30_2892 + 0x1F0)), &sp10, 0U);
        sp10.Multiply(&sp10, this->unk0);
        temp_r5_2907 = ((u8 *) this->unk1D8) + 0x5C;
        M2C_STRUCT_COPY((s32) ((u8 *) temp_r5_2907) + 4, (s32) &spC + 4, 0x40);
        temp_r3_2915 = this->unk1D8;
        M2C_FIELD(M2C_FIELD(temp_r3_2915, void **, 0x44), M2C_UNK (**)(void *, void *, void *), 0x28)(temp_r3_2915, &spC + 0x40, ((u8 *) temp_r5_2907) + 0x40);
        var_r29_2891 += 1;
        var_r30_2892 += 4;
    } while (var_r29_2891 < 4);
    var_r29_2924 = 0;
    var_r30_2925 = 0;
    do {
        MKModel_GetRefPointMatrix(this->unk4, *(this + (var_r30_2925 + 0x218)), &sp10, 0U);
        sp10.Multiply(&sp10, this->unk0);
        temp_r5_2940 = ((u8 *) this->unk1E4) + 0x5C;
        M2C_STRUCT_COPY((s32) ((u8 *) temp_r5_2940) + 4, (s32) &spC + 4, 0x40);
        temp_r3_2948 = this->unk1E4;
        M2C_FIELD(M2C_FIELD(temp_r3_2948, void **, 0x44), M2C_UNK (**)(void *, void *, void *), 0x28)(temp_r3_2948, &spC + 0x40, ((u8 *) temp_r5_2940) + 0x40);
        var_r29_2924 += 1;
        var_r30_2925 += 4;
    } while (var_r29_2924 < 2);
}
#endif

void SteamTrainEffects::Draw() {
    DrawEffects();
}

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
    f64 sp50;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp38;
    f64 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 sp8;
    Matrix *temp_r5_2997;
    f32 temp_f27_3033;
    f32 temp_f28_3038;
    f32 temp_f31_3081;
    f32 temp_f4_2999;
    f64 temp_f0_3015;
    f64 temp_f0_3052;
    f64 temp_f0_3063;

    temp_r5_2997 = this->unk0;
    temp_f4_2999 = this->unk230;
    sp60 = -temp_r5_2997->unk20;
    sp64 = -temp_r5_2997->unk24;
    sp68 = -temp_r5_2997->unk28;
    spB0 = (f64) sp60;
    spB8 = (f64) sp68;
    temp_f0_3015 = spB0 * (f64) temp_f4_2999;
    sp50 = temp_f0_3015;
    spC0 = temp_f0_3015;
    sp58 = (f32) spB8 * temp_f4_2999;
    spC8 = (f64) sp58;
    temp_f27_3033 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
    temp_f28_3038 = MKRand_Float((int *) &gViewSeed, 0.5f, 1.0f);
    sp40 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
    sp44 = temp_f28_3038;
    sp48 = temp_f27_3033;
    sp80 = (f64) sp40;
    sp88 = (f64) sp48;
    temp_f0_3052 = sp80 * 5.65986426e-315;
    sp30 = temp_f0_3052;
    sp90 = temp_f0_3052;
    sp38 = (f32) sp88 * 800.0f;
    sp98 = (f64) sp38;
    temp_f0_3063 = sp90 + temp_f0_3015;
    sp20 = temp_f0_3063;
    spA0 = temp_f0_3063;
    sp28 = (f32) sp98 + (f32) spC8;
    spA8 = (f64) sp28;
    sp8 = MKRand_Float((int *) &gViewSeed, 5.0f, 8.0f);
    temp_f31_3081 = MKRand_Float((int *) &gViewSeed, 0.75f, 1.0f);
    sp10 = MKRand_Float((int *) &gViewSeed, 0.85f, 1.0f);
    sp14 = temp_f31_3081;
    sp18 = 0.5f;
    sp1C = 1.0f;
    sp70 = (f64) sp10;
    sp78 = (f64) sp18;
    ((EmbersPS *) (M2C_FIELD(&gb, EmbersPS **, 0x74)))->Emit(arg0, *((MKVector3 *) &spA0), sp8, *((MKVector4 *) &sp70), -1000.0f);
}

#if 0 // DRAFT: undefined identifier 'MKVector'
void SteamTrainEffects::EmitSmoke() {
    f64 sp30;
    f64 sp28;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    MKVector3 *temp_r3_3134;
    void *temp_r30_3137;
    void *temp_r3_3130;

    temp_r3_3130 = this->unk1DC;
    temp_r3_3134 = M2C_FIELD(M2C_FIELD(temp_r3_3130, void **, 0x44), MKVector3 *(**)(void *), 0x3C)(temp_r3_3130);
    if (temp_r3_3134 != NULL) {
        temp_r30_3137 = M2C_FIELD(temp_r3_3134, void **, 0x2C);
        MKModel_CalculateRefPointWorldPosition(this->unk4, this->unk200, temp_r3_3134);
        M2C_FIELD(temp_r3_3134, f32 *, 0x20) = 0.0f;
        M2C_FIELD(temp_r3_3134, f32 *, 0x24) = MKRand_Float((int *) &gViewSeed, -6.2831855f, 6.2831855f);
        MKVector(0.0f, MKRand_Float((int *) &gViewSeed, 0.75f, 1.0f), 0.0f);
        sp8 = sp18 * 5.61841903e-315;
        M2C_FIELD(temp_r30_3137, f64 *, 0) = sp8;
        sp10 = sp20 * 400.0f;
        sp28 = sp8;
        sp30 = (f64) sp10;
        M2C_FIELD(temp_r30_3137, f64 *, 8) = (f64) sp10;
        M2C_FIELD(temp_r30_3137, f32 *, 0x18) = (f32) (this->unk238 * MKRand_Float((int *) &gViewSeed, 0.5f, 1.0f));
        M2C_FIELD(temp_r30_3137, f32 *, 0x10) = MKRand_Float((int *) &gViewSeed, -6.2831855f, 6.2831855f);
        M2C_FIELD(temp_r30_3137, f32 *, 0x14) = (f32) M2C_FIELD(this->unk1DC, f32 *, 0xF4);
    }
}
#endif

#if 0 // DRAFT: function call 'MKModel_CalculateRefPointWorldPosition(MKModel *, SteamTrainEffects, MKVector3 *)' does not match 'MKModel_CalculateRefPointWorldPosition(const M
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

#if 0 // DRAFT: undefined identifier 'MKVector'
void SteamTrainEffects::EmitSteam() {
    f64 sp30;
    f64 sp28;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    MKVector3 *temp_r3_3262;
    void *temp_r30_3265;
    void *temp_r3_3258;

    temp_r3_3258 = this->unk1E0;
    temp_r3_3262 = M2C_FIELD(M2C_FIELD(temp_r3_3258, void **, 0x44), MKVector3 *(**)(void *), 0x3C)(temp_r3_3258);
    if (temp_r3_3262 != NULL) {
        temp_r30_3265 = M2C_FIELD(temp_r3_3262, void **, 0x2C);
        MKModel_CalculateRefPointWorldPosition(this->unk4, this->unk200, temp_r3_3262);
        M2C_FIELD(temp_r3_3262, f32 *, 0x20) = 0.0f;
        M2C_FIELD(temp_r3_3262, f32 *, 0x24) = MKRand_Float((int *) &gViewSeed, -6.2831855f, 6.2831855f);
        MKVector(0.0f, MKRand_Float((int *) &gViewSeed, 0.75f, 1.0f), 0.0f);
        sp8 = sp18 * 5.61841903e-315;
        M2C_FIELD(temp_r30_3265, f64 *, 0) = sp8;
        sp10 = sp20 * 400.0f;
        sp28 = sp8;
        sp30 = (f64) sp10;
        M2C_FIELD(temp_r30_3265, f64 *, 8) = (f64) sp10;
        M2C_FIELD(temp_r30_3265, f32 *, 0x18) = (f32) (this->unk238 * MKRand_Float((int *) &gViewSeed, 0.5f, 1.0f));
        M2C_FIELD(temp_r30_3265, f32 *, 0x10) = MKRand_Float((int *) &gViewSeed, -6.2831855f, 6.2831855f);
        M2C_FIELD(temp_r30_3265, f32 *, 0x14) = (f32) M2C_FIELD(this->unk1E0, f32 *, 0xF4);
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'MKVector'
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
    f64 sp8;
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
        M2C_FIELD(temp_r3_3339, f32 *, 0x24) = MKRand_Float((int *) &gViewSeed, -6.2831855f, 6.2831855f);
        temp_f31_3361 = this->unk224;
        MKVector(0.0f, 0.0f, -MKRand_Float((int *) &gViewSeed, 0.75f, 1.0f));
        sp38.operator*(1000.0f);
        sp8 = sp38 * (f64) temp_f31_3361;
        M2C_FIELD(temp_r30_3344, f64 *, 0) = sp8;
        sp10 = sp38.unk8 * temp_f31_3361;
        sp48 = sp8;
        sp50 = (f64) sp10;
        M2C_FIELD(temp_r30_3344, f64 *, 8) = (f64) sp10;
        M2C_FIELD(temp_r30_3344, f32 *, 0x18) = (f32) (this->unk224 * MKRand_Float((int *) &gViewSeed, 0.5f, 1.0f));
        M2C_FIELD(temp_r30_3344, f32 *, 0x10) = MKRand_Float((int *) &gViewSeed, -6.2831855f, 6.2831855f);
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
    if (this->unk228 >= this->unk22C) {
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
        if (temp_f0_3514 >= 6.2831855f) {
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

#if 0 // DRAFT: function call 'Tools_GetMatchingNodeIndex(MKModel *, signed char *)' does not match 'Tools_GetMatchingNodeIndex(MKModel *, const char *)'
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
        MKDynamicBone_SetUpdater(MKDynamicBone_AddDynamicBone(this->unk4, (s32) temp_r25_3569), (void (*)(MKDynamicBone *, void *)) &SteamTrainEffects::UpdateWheelBone, ((u8 *) temp_r27_3577) + 0x18);
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
        ((Animation *) &sp18)->GetNodeOrigin(MKModel_GetAnimation(this->unk4));
        M2C_FIELD(temp_r27_3677, f64 *, 0xA8) = sp18;
        M2C_FIELD(temp_r27_3677, f64 *, 0xB0) = sp20;
        ((Animation *) &sp8)->GetNodeOrigin(MKModel_GetAnimation(this->unk4));
        M2C_FIELD(temp_r27_3677, f64 *, 0xB8) = sp8;
        M2C_FIELD(temp_r27_3677, f64 *, 0xC0) = sp10;
        MKDynamicBone_SetUpdater(MKDynamicBone_GetDynamicBone(this->unk4, M2C_FIELD(temp_r27_3677, s32 *, 0x98)), UpdateLookAtBone, ((u8 *) temp_r27_3677) + 0x98);
        var_r25_3650 += 1;
        var_r30_3652 += 0x50;
    } while (var_r25_3650 < 4);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'signed char **' to 'const char **'
void SteamTrainEffects::Init(const Matrix *arg0, MKModel *arg1, MKAnimScript *arg2) {
    f32 var_f0_3740;
    s32 var_ctr_3731;
    s32 var_r3_3727;
    u32 temp_r4_3733;
    u32 var_r7_3719;
    void *temp_r5_3736;

    var_r7_3719 = 1;
    this->unk0 = (Matrix *) (arg0);
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
    this->unk1E8 = (long) (checked_cast<Explosion3 *, MKProp>(gMK->CreateProp("Explosion3")));
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

#if 0 // DRAFT: illegal explicit conversion from 'Matrix' to 'float'
void UpdateLookAtBone(MKDynamicBone *arg0, void *arg1) {
    Matrix sp260;
    Matrix sp220;
    Matrix sp1E0;
    f32 sp1DC;
    f32 sp1D8;
    f32 sp1D4;
    f32 sp1D0;
    f32 sp1CC;
    f32 sp1C8;
    f32 sp1C4;
    f32 sp1C0;
    f32 sp1BC;
    f32 sp1B8;
    f32 sp1B4;
    f32 sp1B0;
    f32 sp1AC;
    f32 sp1A8;
    f32 sp1A4;
    f32 sp1A0;
    Matrix sp160;
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
    MKVector3 spE8;
    f64 spE0;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    MKVector3 spB8;
    f64 spB0;
    f64 spA8;
    MKVector3 sp98;
    f64 sp90;
    f64 sp88;
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp60;
    f64 sp58;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    s16 sp14;
    s16 sp12;
    s16 sp10;
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
    f64 temp_f0_4054;
    f64 temp_f0_4069;
    s32 temp_r31_3924;
    s32 temp_r31_3933;
    s32 temp_r31_3941;
    s32 temp_r31_3975;
    s32 temp_r31_4188;

    temp_r31_3924 = M2C_FIELD(arg1, s32 *, 4);
    temp_r3_3926 = MKModel_GetAnimation(arg0->unk24);
    sp14 = (s16) temp_r31_3924;
    temp_r3_3926->CalculateMatrices(&sp220, 1, &sp14, NULL);
    temp_r31_3933 = M2C_FIELD(arg1, s32 *, 0);
    ((Animation *) (MKModel_GetAnimation(arg0->unk24)))->SetCustomMatrix(temp_r31_3933, NULL, (AnimationMatrixPosition) 2, 0U);
    temp_r31_3941 = M2C_FIELD(arg1, s32 *, 0);
    temp_r3_3943 = MKModel_GetAnimation(arg0->unk24);
    sp12 = (s16) temp_r31_3941;
    temp_r3_3943->CalculateMatrices(&sp260, 1, &sp12, NULL);
    temp_f3_3950 = M2C_FIELD(arg1, f32 *, 0x14);
    temp_f6_3956 = M2C_FIELD(arg1, f32 *, 0x10);
    temp_f7_3962 = M2C_FIELD(arg1, f32 *, 0x18);
    temp_r31_3975 = M2C_FIELD(arg1, s32 *, 8);
    sp78 = sp260.unk30 + ((temp_f7_3962 * sp260.unk20) + ((temp_f6_3956 * M2C_BITWISE(f32, sp260)) + (temp_f3_3950 * sp260.unk10)));
    sp7C = sp260.unk34 + ((temp_f7_3962 * sp260.unk24) + ((temp_f6_3956 * sp260.unk4) + (temp_f3_3950 * sp260.unk14)));
    sp80 = sp260.unk38 + ((temp_f7_3962 * sp260.unk28) + ((temp_f6_3956 * sp260.unk8) + (temp_f3_3950 * sp260.unk18)));
    sp118 = (f64) sp78;
    sp120 = (f64) sp80;
    sp148 = (f64) sp78;
    sp150 = (f64) sp80;
    temp_r3_3988 = MKModel_GetAnimation(arg0->unk24);
    sp10 = (s16) temp_r31_3975;
    temp_r3_3988->CalculateMatrices(&sp1E0, 1, &sp10, NULL);
    temp_f3_3995 = M2C_FIELD(arg1, f32 *, 0x24);
    temp_f6_4004 = M2C_FIELD(arg1, f32 *, 0x20);
    temp_f7_4010 = M2C_FIELD(arg1, f32 *, 0x28);
    sp68 = sp1E0.unk30 + ((temp_f7_4010 * sp1E0.unk20) + ((temp_f6_4004 * M2C_BITWISE(f32, sp1E0)) + (temp_f3_3995 * sp1E0.unk10)));
    sp6C = sp1E0.unk34 + ((temp_f7_4010 * sp1E0.unk24) + ((temp_f6_4004 * sp1E0.unk4) + (temp_f3_3995 * sp1E0.unk14)));
    sp70 = sp1E0.unk38 + ((temp_f7_4010 * sp1E0.unk28) + ((temp_f6_4004 * sp1E0.unk8) + (temp_f3_3995 * sp1E0.unk18)));
    sp108 = (f64) sp68;
    sp110 = (f64) sp70;
    sp138 = (f64) sp68;
    sp140 = (f64) sp70;
    M2C_STRUCT_COPY((s32) &sp160.unk3C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
    temp_f31_4044 = M2C_FIELD(arg1, f32 *, 0x30);
    if (temp_f31_4044 != 0.0f) {
        temp_r3_4047 = arg0->unk20;
        sp128 = M2C_FIELD(temp_r3_4047, f64 *, 0x10);
        sp130 = M2C_FIELD(temp_r3_4047, f64 *, 0x18);
        temp_f0_4054 = sp138 - sp148;
        sp28 = temp_f0_4054;
        spD8 = temp_f0_4054;
        sp30 = (f32) sp140 - (f32) sp150;
        spE0 = (f64) sp30;
        Normalise(spE8);
        temp_f0_4069 = spE8 * (f64) temp_f31_4044;
        sp58 = temp_f0_4069;
        spF8 = temp_f0_4069;
        sp60 = spE8.unk8 * temp_f31_4044;
        sp100 = (f64) sp60;
        sp1A0 = (f32) spF8;
        sp1A4 = (*(f32 *) ((u8 *) &spF8 + 0x4));
        sp1A8 = (f32) sp100;
        sp20 = ((f32) sp128 * (*(f32 *) ((u8 *) &spF8 + 0x4))) - ((*(f32 *) ((u8 *) &sp128 + 0x4)) * (f32) spF8);
        sp18 = ((*(f32 *) ((u8 *) &sp128 + 0x4)) * (f32) sp100) - ((f32) sp130 * (*(f32 *) ((u8 *) &spF8 + 0x4)));
        sp1C = ((f32) sp130 * (f32) spF8) - ((f32) sp128 * (f32) sp100);
        sp1AC = 0.0f;
        spA8 = (f64) sp18;
        spB0 = (f64) sp20;
        Normalise(spB8);
        sp48 = -M2C_BITWISE(f32, spB8);
        sp4C = -spB8.unk4;
        sp50 = -spB8.unk8;
        spC8 = (f64) sp48;
        spD0 = (f64) sp50;
        sp1C0 = (f32) spC8;
        sp1C4 = (*(f32 *) ((u8 *) &spC8 + 0x4));
        sp1C8 = (f32) spD0;
        sp40 = ((f32) spC8 * sp1A4) - ((*(f32 *) ((u8 *) &spC8 + 0x4)) * sp1A0);
        sp38 = ((*(f32 *) ((u8 *) &spC8 + 0x4)) * sp1A8) - ((f32) spD0 * sp1A4);
        sp3C = ((f32) spD0 * sp1A0) - ((f32) spC8 * sp1A8);
        sp1CC = 0.0f;
        sp88 = (f64) sp38;
        sp90 = (f64) sp40;
        Normalise(sp98);
        sp1B0 = M2C_BITWISE(f32, sp98);
        sp1B4 = sp98.unk4;
        sp1B8 = sp98.unk8;
        sp1BC = 0.0f;
    }
    sp1D0 = (f32) sp148;
    sp1D4 = (*(f32 *) ((u8 *) &sp148 + 0x4));
    sp1D8 = (f32) sp150;
    sp1DC = 1.0f;
    sp160.Multiply(arg0->unk20, &sp260);
    sp160.Inverse(&sp160);
    ((Matrix *) &sp1A0)->Multiply(&sp160, (Matrix *) &sp1A0);
    sp260.Multiply(&sp260, (Matrix *) &sp1A0);
    sp220.Inverse(&sp220);
    sp260.Multiply(&sp260, &sp220);
    M2C_FIELD(arg0, f64 *, 0x10) = (f64) M2C_FIELD(arg0, f64 *, 0);
    M2C_FIELD(arg0, f64 *, 0x18) = (f64) M2C_FIELD(arg0, f64 *, 8);
    temp_r31_4188 = M2C_FIELD(arg1, s32 *, 0);
    ((Animation *) (MKModel_GetAnimation(arg0->unk24)))->SetCustomMatrix(temp_r31_4188, &sp260, (AnimationMatrixPosition) 4, 0U);
}
#endif

#if 0 // DRAFT: undefined identifier '__ptmf_null'
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
