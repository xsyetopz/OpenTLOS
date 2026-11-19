#include "spyro/source/Gondola.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "common/Source/Texture.h"
#include "spyro/source/AssaultCannon.h"
#include "spyro/source/Crate.h"
#include "spyro/source/EnemyGenerator.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/GlowingPropManager.h"
#include "spyro/source/KDMatrixProperty.h"
#include "spyro/source/KDMatrixRefProperty.h"
#include "spyro/source/KDPositionProperty.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDProperty.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/KDSpline.h"
#include "spyro/source/KDStateMachine.h"
#include "spyro/source/Platform.h"
#include "spyro/source/PlatformObject.h"
#include "spyro/source/SeeSaw.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/ShatterablePlatform.h"
#include "spyro/source/SkyClouds.h"
#include "spyro/source/SpawnPointObject.h"
#include "spyro/source/SpawnerObject.h"
#include "spyro/source/TargetManager.h"
#include "unplaced_templates.h"
#include "common/Source/StdMath.h"
#include "spyro/source/PhrasePlayer.h"
#include "unplaced_inlines.h"
#include <m2c_macros.h>

s32 stricmp(s8 *);                                  /* extern */
extern f32 *KDSpline_PositionMixer;
extern f32 *KDSpline_VelocityMixer;
extern f32 SPYRO_BOUNCE_Y_SPEED;
extern f32 SPYRO_MIN_JUMP_Y_VELOCITY;
extern M2C_UNK fingerprintData;
extern MKSceneManager *gMK;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern void **gb;

void Gondola::WaveMotion::Update() {
    *(f32 *) this = *(f32 *) this + gUpdateTimeDelta;
}

void Gondola::WaveMotion::Init() {
    *(f32 *) this = 0.0f;
}

void Gondola::Deinit() {
    MKCollisionInfo *sp10;
    s32 spC;
    s32 sp8;

    spC = 0;
    sp8 = 0x410;
    sp10 = &this->unk70;
    M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, M2C_UNK), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &sp8, 0x410);
    ((KDUniformSpline *) &this->unk180)->Deinit();
    ((KDUniformSpline *) &this->unk194)->Deinit();
    this->unk1B0.Deinit();
    Platform::Deinit();
}

void Gondola::Draw() {
    GameProp::Draw();
}

void Gondola::Message(MKMessage *arg0) {
    s32 temp_r0_140;
    s32 temp_r0_177;
    s32 temp_r3_174;
    s32 var_r6_153;
    u32 var_r5_151;
    void *temp_r3_156;

    temp_r0_140 = arg0->unk0;
    switch (temp_r0_140) {                          /* irregular */
    case 0xB5:
        var_r5_151 = 0U;
        var_r6_153 = 0;
loop_7:
        if ((s8) M2C_FIELD((&fingerprintData + var_r6_153), u8 *, 8) != 0) {
            temp_r3_156 = &fingerprintData + var_r6_153;
            var_r6_153 += 1;
            var_r5_151 += (s8) M2C_FIELD(temp_r3_156, u8 *, 8);
            goto loop_7;
        }
        if ((var_r5_151 == (u32) M2C_FIELD(&fingerprintData, u32 *, 0x108)) && (this->unk1B0.Message(arg0), temp_r3_174 = this->unk240, ((temp_r3_174 == 2) != 0))) {
            temp_r0_177 = this->unk244;
            if ((temp_r0_177 == 1) || (temp_r0_177 == 2)) {
                this->unk244 = temp_r3_174;
                this->unk240 = 0;
                this->unk1A8 = 0.0f;
                return;
            }
            if ((temp_r0_177 == 0) || (temp_r0_177 == 2)) {
                this->unk244 = temp_r3_174;
                this->unk240 = 1;
                this->unk1A8 = 0.0f;
                return;
            }
        } else {
            return;
        }
        break;
    case 0xB4:
        this->unk1B0.Message(arg0);
    default:
block_18:
        Platform::Message(arg0);
        break;
    case 0x15:
        SetDefaults();
        goto block_18;
    }
}

void *Gondola::Update() {
    s32 temp_r0_245;

    if (M2C_FIELD(*gb, u8 (**)(void **, void ***), 0x70)(gb, &gb) == 0) {
        this->unk1AC.Update();
    }
    GameProp::Update();
    if (this->unk1B0.HasEnemyWaveFinished() != 0) {
        temp_r0_245 = this->unk1B0.unk7C;
        switch (temp_r0_245) {                      /* irregular */
        case 0:
            this->unk248 = PhrasePlayer_PlayEvent("TPGondolaSoldiersCleared");
            break;
        case 1:
            this->unk248 = PhrasePlayer_PlayEvent("TPGondolaLeadersCleared");
            break;
        case 2:
            this->unk248 = PhrasePlayer_PlayEvent("TPGondolaCommandersCleared");
            break;
        }
    }
    this->unk1B0.Update();
    if ((this->unk1A8 < 1.0f) && ((s32) this->unk240 != 2)) {
        if ((s32) this->unk1B0.unk7C >= 3) {
            this->unk1B0.unk7C = 0;
            this->unk1B0.StartEnemyWave();
        }
    } else {
        ((SpawnerObject *) &this->unk1B0)->FunctionOff();
    }
}

#if 0 // DRAFT: illegal explicit conversion from 'KDUniformSpline' to 'double'
void Gondola::UpdateMove() {
    f32 sp44C;
    f32 sp448;
    f32 sp444;
    f32 sp440;
    f32 sp43C;
    f32 sp438;
    f32 sp434;
    f32 sp430;
    f32 sp42C;
    f32 sp428;
    f32 sp424;
    f32 sp420;
    f32 sp41C;
    f32 sp418;
    f32 sp414;
    f32 sp410;
    f64 sp408;                                      /* compiler-managed */
    f64 sp400;
    f64 sp3F8;                                      /* compiler-managed */
    f64 sp3F0;                                      /* compiler-managed */
    f64 sp3E8;                                      /* compiler-managed */
    f64 sp3E0;
    f64 sp3D8;
    f64 sp3D0;
    f64 sp3C8;
    f64 sp3C0;
    f64 sp3B8;                                      /* compiler-managed */
    f64 sp3B0;                                      /* compiler-managed */
    f64 sp3A8;                                      /* compiler-managed */
    f64 sp3A0;                                      /* compiler-managed */
    f64 sp398;
    KDUniformSpline sp380;
    f64 sp370;
    f64 sp360;
    f64 sp350;
    f64 sp348;
    f64 sp340;
    f64 sp338;
    f64 sp330;
    f64 sp328;
    f64 sp320;
    f64 sp310;
    f64 sp300;
    f64 sp2F0;
    f64 sp2E0;
    f64 sp2D0;
    f64 sp2C0;
    f64 sp2B0;
    f64 sp2A8;
    f64 sp2A0;
    f64 sp298;
    f64 sp290;
    f64 sp288;
    f64 sp280;
    f64 sp278;
    f64 sp270;
    MKVector3 sp260;
    MKVector3 sp250;
    MKVector3 sp240;
    f64 sp238;
    f64 sp230;
    f64 sp228;
    f64 sp220;
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
    f64 sp1C8;
    f64 sp1C0;
    f64 sp1B8;
    f64 sp1B0;
    f64 sp1A8;
    f64 sp1A0;
    f64 sp198;
    f64 sp190;
    MKVector3 sp180;
    f32 sp178;
    f64 sp170;
    f64 sp160;
    f64 sp158;
    f64 sp150;
    f32 sp148;
    f64 sp140;
    f32 sp138;
    f32 sp134;
    f32 sp130;
    f32 sp128;
    f32 sp124;
    f32 sp120;
    f32 sp118;
    f32 sp114;
    f32 sp110;
    f32 sp108;
    f32 sp104;
    f32 sp100;
    f32 spF8;
    f64 spF0;
    f32 spE8;
    f64 spE0;
    f32 spD8;
    f32 spD4;
    f32 spD0;
    f32 spC8;
    f64 spC0;
    f32 spB8;
    f32 spB4;
    f32 spB0;
    f32 spA8;
    f32 spA4;
    f32 spA0;
    f32 sp98;
    f64 sp90;
    f32 sp88;
    f64 sp80;
    f32 sp78;
    f32 sp74;
    f32 sp70;
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
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 temp_f10_1315;
    f32 temp_f1_1276;
    f32 temp_f2_920;
    f32 temp_f30_946;
    f32 temp_f3_1263;
    f32 temp_f3_1278;
    f32 temp_f4_1259;
    f32 temp_f5_1176;
    f32 temp_f5_1261;
    f32 temp_f6_1162;
    f32 temp_f7_1169;
    f32 temp_f8_1317;
    f32 temp_f9_1314;
    f32 var_f0_345;
    f32 var_f0_757;
    f32 var_f1_384;
    f32 var_f1_422;
    f32 var_f1_499;
    f32 var_f1_553;
    f32 var_f1_593;
    f32 var_f31_1186;
    f32 var_f3_750;
    f32 var_f4_1090;
    f32 var_f4_683;
    f32 var_f4_801;
    f32 var_f4_992;
    f32 var_f7_983;
    f32 var_f8_1065;
    f32 var_f8_1184;
    f32 var_f9_1164;
    f64 temp_f0_1377;
    f64 temp_f0_468;
    f64 temp_f0_903;
    f64 temp_f0_932;
    f64 temp_f0_956;
    f64 temp_f1_1003;
    f64 temp_f1_1007;
    f64 temp_f1_1096;
    f64 temp_f1_1102;
    f64 temp_f1_1106;
    f64 temp_f1_1194;
    f64 temp_f1_1200;
    f64 temp_f1_1204;
    f64 temp_f1_453;
    f64 temp_f1_462;
    f64 temp_f1_689;
    f64 temp_f1_695;
    f64 temp_f1_699;
    f64 temp_f1_806;
    f64 temp_f1_812;
    f64 temp_f1_816;
    f64 temp_f1_997;
    f64 temp_f3_915;
    f64 temp_f5_1287;
    f64 temp_f6_1277;
    s32 temp_r0_361;
    s32 temp_r0_474;
    s32 temp_r0_623;
    s32 temp_r3_1026;
    s32 temp_r3_1125;
    s32 temp_r3_1223;
    s32 temp_r3_718;
    s32 temp_r3_835;
    s32 var_r0_1036;
    s32 var_r0_1135;
    s32 var_r0_1233;
    s32 var_r0_728;
    s32 var_r0_845;
    void *temp_r3_461;
    void *temp_r4_450;

    if ((M2C_FIELD(*gb, u8 (**)(void **, void ***), 0x70)(gb, &gb) == 0) && ((u32) this->unk18C != 0U) && ((u32) this->unk1A0 != 0U)) {
        if ((s32) this->unk240 != 2) {
            var_f0_345 = (0.005f * gUpdateTimeDelta) + this->unk1A8;
            if (var_f0_345 < 1.0f) {

            } else {
                var_f0_345 = 1.0f;
            }
            if (var_f0_345 > 0.0f) {

            } else {
                var_f0_345 = 0.0f;
            }
            this->unk1A8 = var_f0_345;
        }
        temp_r0_361 = this->unk240;
        switch (temp_r0_361) {                      /* switch 1; irregular */
        case 0:                                     /* switch 1 */
            sp34 = 0.0f;
            sp380.GetMeasure(this->unk1A8, (Matrix *) &this->unk180, KDSpline_PositionMixer);
            var_f1_384 = this->unk1A8 - 0.001f;
            sp400 = M2C_BITWISE(f64, sp380);
            sp408 = (f64) sp380.unk8;
            if (var_f1_384 < 1.0f) {

            } else {
                var_f1_384 = 1.0f;
            }
            if (var_f1_384 > 0.0f) {

            } else {
                var_f1_384 = 0.0f;
            }
            ((KDUniformSpline *) &sp370)->GetVelocity(var_f1_384);
            sp3F0 = sp370;
            sp3F8 = sp378;
            break;
        case 1:                                     /* switch 1 */
            sp30 = 0.0f;
            ((KDUniformSpline *) &sp360)->GetMeasure(this->unk1A8, (Matrix *) &this->unk194, KDSpline_PositionMixer);
            var_f1_422 = this->unk1A8 - 0.001f;
            sp400 = sp360;
            sp408 = sp368;
            if (var_f1_422 < 1.0f) {

            } else {
                var_f1_422 = 1.0f;
            }
            if (var_f1_422 > 0.0f) {

            } else {
                var_f1_422 = 0.0f;
            }
            ((KDUniformSpline *) &sp350)->GetVelocity(var_f1_422);
            sp3F0 = sp350;
            sp3F8 = sp358;
            break;
        case 2:                                     /* switch 1 */
            temp_r4_450 = this->unk8;
            temp_f1_453 = M2C_FIELD(temp_r4_450, f64 *, 0x30);
            sp320 = temp_f1_453;
            sp328 = M2C_FIELD(temp_r4_450, f64 *, 0x38);
            temp_r3_461 = M2C_FIELD(M2C_FIELD(*gb, void *(**)(void **, void *, f64), 0xC)(gb, temp_r4_450, temp_f1_453), void **, 8);
            temp_f1_462 = M2C_FIELD(temp_r3_461, f64 *, 0x30);
            sp330 = temp_f1_462;
            sp338 = M2C_FIELD(temp_r3_461, f64 *, 0x38);
            temp_f0_468 = temp_f1_462 - sp320;
            sp170 = temp_f0_468;
            temp_r0_474 = this->unk244;
            sp340 = temp_f0_468;
            sp178 = (f32) sp338 - (f32) sp328;
            sp348 = (f64) sp178;
            if (temp_r0_474 == 0) {
                sp2C = 0.0f;
                ((KDUniformSpline *) &sp310)->GetMeasure(this->unk1A8, (Matrix *) &this->unk180, KDSpline_PositionMixer);
                var_f1_499 = this->unk1A8 - 0.001f;
                sp400 = sp310;
                sp408 = sp318;
                if (var_f1_499 < 1.0f) {

                } else {
                    var_f1_499 = 1.0f;
                }
                if (var_f1_499 > 0.0f) {

                } else {
                    var_f1_499 = 0.0f;
                }
                ((KDUniformSpline *) &sp300)->GetVelocity(var_f1_499);
                sp3F0 = sp300;
                sp3F8 = sp308;
                M2C_ERROR(/* unknown instruction: cror 0x2, 0x1, 0x2 */);
                if ((((f32) sp348 * (f32) sp348) + (((f32) sp340 * (f32) sp340) + ((*(f32 *) ((u8 *) &sp340 + 0x4)) * (*(f32 *) ((u8 *) &sp340 + 0x4))))) == 4e8f) {
                    this->unk244 = this->unk240;
                    this->unk240 = 1;
                    this->unk1A8 = 0.0f;
                }
            } else if (temp_r0_474 == 1) {
                this->unk244 = 2;
                this->unk240 = 2;
                this->unk1A8 = 0.0f;
                sp28 = 0.0f;
                ((KDUniformSpline *) &sp2F0)->GetMeasure(this->unk1A8, (Matrix *) &this->unk180, KDSpline_PositionMixer);
                var_f1_553 = this->unk1A8 - 0.001f;
                sp400 = sp2F0;
                sp408 = sp2F8;
                if (var_f1_553 < 1.0f) {

                } else {
                    var_f1_553 = 1.0f;
                }
                if (var_f1_553 > 0.0f) {

                } else {
                    var_f1_553 = 0.0f;
                }
                ((KDUniformSpline *) &sp2E0)->GetVelocity(var_f1_553);
                sp3F0 = sp2E0;
                sp3F8 = sp2E8;
            } else {
                this->unk24C = 1;
                sp24 = 0.0f;
                ((KDUniformSpline *) &sp2D0)->GetMeasure(this->unk1A8, (Matrix *) &this->unk180, KDSpline_PositionMixer);
                var_f1_593 = this->unk1A8 - 0.001f;
                sp400 = sp2D0;
                sp408 = sp2D8;
                if (var_f1_593 < 1.0f) {

                } else {
                    var_f1_593 = 1.0f;
                }
                if (var_f1_593 > 0.0f) {

                } else {
                    var_f1_593 = 0.0f;
                }
                ((KDUniformSpline *) &sp2C0)->GetVelocity(var_f1_593);
                sp3F0 = sp2C0;
                sp3F8 = sp2C8;
            }
            break;
        }
        if (this->unk1A8 == 1.0f) {
            temp_r0_623 = this->unk240;
            if (temp_r0_623 != 2) {
                this->unk244 = temp_r0_623;
                this->unk240 = 2;
            }
        }
        this->unk23C -= gUpdateTimeDelta;
        if (this->unk23C <= 0.0f) {
            this->unk23C = 10.0f;
            sp3C = 0.0f;
            ((KDUniformSpline *) &sp2B0)->GetMeasure(this->unk1A8, (Matrix *) &this->unk180, KDSpline_PositionMixer);
            sp3E0 = sp2B0;
            sp3E8 = sp2B8;
            sp38 = 0.0f;
            ((KDUniformSpline *) &sp160)->GetMeasure(this->unk1A8, (Matrix *) &this->unk180, KDSpline_VelocityMixer);
            sp150 = sp160;
            sp158 = sp168;
            sp140 = sp150 * (f64) sp38;
            sp2A0 = sp140;
            sp148 = (f32) sp158 * sp38;
            sp2A8 = (f64) sp148;
            var_f4_683 = ((f32) sp2A8 * (f32) sp2A8) + (((f32) sp2A0 * (f32) sp2A0) + ((*(f32 *) ((u8 *) &sp2A0 + 0x4)) * (*(f32 *) ((u8 *) &sp2A0 + 0x4))));
            if (var_f4_683 > 1e-12f) {
                if (var_f4_683 > 0.0f) {
                    temp_f1_689 = __frsqrte(var_f4_683);
                    temp_f1_695 = 0.5 * temp_f1_689 * -(((f64) var_f4_683 * (temp_f1_689 * temp_f1_689)) - 3.0);
                    temp_f1_699 = 0.5 * temp_f1_695 * -(((f64) var_f4_683 * (temp_f1_695 * temp_f1_695)) - 3.0);
                    var_f4_683 = (f32) ((f64) var_f4_683 * (0.5 * temp_f1_699 * -(((f64) var_f4_683 * (temp_f1_699 * temp_f1_699)) - 3.0)));
                } else if (var_f4_683 < M2C_BITWISE(f32, 0.0)) {
                    var_f4_683 = __float_nan;
                } else {
                    sp20 = var_f4_683;
                    temp_r3_718 = M2C_BITWISE(s32, sp20) & 0x7F800000;
                    switch (temp_r3_718) {          /* switch 2; irregular */
                    case 0x7F800000:                /* switch 2 */
                        if (M2C_BITWISE(s32, sp20) & 0x7FFFFF) {
                            var_r0_728 = 1;
                        } else {
                            var_r0_728 = 2;
                        }
                        break;
                    case 0x0:                       /* switch 2 */
                        if (M2C_BITWISE(s32, sp20) & 0x7FFFFF) {
                            var_r0_728 = 5;
                        } else {
                            var_r0_728 = 3;
                        }
                        break;
                    default:                        /* switch 2 */
                        var_r0_728 = 4;
                        break;
                    }
                    if (var_r0_728 == 1) {
                        var_f4_683 = __float_nan;
                    }
                }
                var_f3_750 = 1.0f / var_f4_683;
            } else {
                var_f3_750 = 0.0f;
            }
            var_f0_757 = 0.0f;
            sp128 = 0.0f;
            sp138 = (f32) sp2A8 * var_f3_750;
            sp130 = (f32) sp2A0 * var_f3_750;
            sp134 = (*(f32 *) ((u8 *) &sp2A0 + 0x4)) * var_f3_750;
            sp3D8 = (f64) sp138;
            sp3D0 = (f64) sp130;
            sp288 = (f64) sp128;
            sp120 = 0.0f;
            sp124 = 1.0f;
            sp280 = (f64) sp120;
            sp110 = ((*(f32 *) ((u8 *) &sp280 + 0x4)) * (f32) sp3D8) - ((f32) sp288 * (*(f32 *) ((u8 *) &sp3D0 + 0x4)));
            sp114 = ((f32) sp288 * (f32) sp3D0) - ((f32) sp280 * (f32) sp3D8);
            sp118 = ((f32) sp280 * (*(f32 *) ((u8 *) &sp3D0 + 0x4))) - ((*(f32 *) ((u8 *) &sp280 + 0x4)) * (f32) sp3D0);
            sp290 = (f64) sp110;
            sp298 = (f64) sp118;
            var_f4_801 = ((f32) sp298 * (f32) sp298) + (((f32) sp290 * (f32) sp290) + ((*(f32 *) ((u8 *) &sp290 + 0x4)) * (*(f32 *) ((u8 *) &sp290 + 0x4))));
            if (var_f4_801 > 1e-12f) {
                if (var_f4_801 > 0.0f) {
                    temp_f1_806 = __frsqrte(var_f4_801);
                    temp_f1_812 = 0.5 * temp_f1_806 * -(((f64) var_f4_801 * (temp_f1_806 * temp_f1_806)) - 3.0);
                    temp_f1_816 = 0.5 * temp_f1_812 * -(((f64) var_f4_801 * (temp_f1_812 * temp_f1_812)) - 3.0);
                    var_f4_801 = (f32) ((f64) var_f4_801 * (0.5 * temp_f1_816 * -(((f64) var_f4_801 * (temp_f1_816 * temp_f1_816)) - 3.0)));
                } else if (var_f4_801 < M2C_BITWISE(f32, 0.0)) {
                    var_f4_801 = __float_nan;
                } else {
                    sp1C = var_f4_801;
                    temp_r3_835 = M2C_BITWISE(s32, sp1C) & 0x7F800000;
                    switch (temp_r3_835) {          /* switch 3; irregular */
                    case 0x7F800000:                /* switch 3 */
                        if (M2C_BITWISE(s32, sp1C) & 0x7FFFFF) {
                            var_r0_845 = 1;
                        } else {
                            var_r0_845 = 2;
                        }
                        break;
                    case 0x0:                       /* switch 3 */
                        if (M2C_BITWISE(s32, sp1C) & 0x7FFFFF) {
                            var_r0_845 = 5;
                        } else {
                            var_r0_845 = 3;
                        }
                        break;
                    default:                        /* switch 3 */
                        var_r0_845 = 4;
                        break;
                    }
                    if (var_r0_845 == 1) {
                        var_f4_801 = __float_nan;
                    }
                }
                var_f0_757 = 1.0f / var_f4_801;
            }
            sp104 = (*(f32 *) ((u8 *) &sp290 + 0x4)) * var_f0_757;
            sp100 = (f32) sp290 * var_f0_757;
            sp108 = (f32) sp298 * var_f0_757;
            sp3C0 = (f64) sp100;
            sp3C8 = (f64) sp108;
            sp240 = MKVector(0.0f, MKRand_Float((int *) &gViewSeed, 0.0f, 2000.0f), 0.0f);
            sp250 = __ml(MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f), *((MKVector3 *) &sp3C0));
            sp260 = sp250.operator*(2000.0f);
            temp_f0_903 = sp260 + M2C_BITWISE(f64, sp240);
            sp80 = temp_f0_903;
            sp270 = temp_f0_903;
            sp88 = sp260.unk8 + sp240.unk8;
            sp278 = (f64) sp88;
            temp_f3_915 = sp3E0 + temp_f0_903;
            sp3E0 = temp_f3_915;
            temp_f2_920 = (f32) sp3E8 + (f32) sp278;
            sp3E8 = temp_f2_920;
            spF0 = sp3D0 * 5.780152567e-315;
            spF8 = (f32) sp3D8 * 6000.0f;
            sp220 = spF0;
            sp228 = (f64) spF8;
            temp_f0_932 = temp_f3_915 + sp220;
            spE0 = temp_f0_932;
            sp230 = temp_f0_932;
            spE8 = temp_f2_920 + (f32) sp228;
            sp238 = (f64) spE8;
            temp_f30_946 = MKRand_Float((int *) &gViewSeed, 1.0f, 1.25f);
            spD0 = 600.0f;
            spD4 = 300.0f;
            spD8 = 600.0f;
            sp200 = (f64) spD0;
            sp208 = (f64) spD8;
            temp_f0_956 = sp200 * (f64) temp_f30_946;
            spC0 = temp_f0_956;
            sp210 = temp_f0_956;
            spC8 = (f32) sp208 * temp_f30_946;
            sp218 = (f64) spC8;
            this->unk238->SpawnCloudEmitter(*((MKVector3 *) &sp230), *((MKVector3 *) &sp210), 0.0f);
        }
        M2C_STRUCT_COPY((s32) &sp44C + 4, MKModel_GetWorldMatrix(this->unk4) - 4 + 4, 0x40);
        var_f7_983 = 0.0f;
        (*(f32 *) ((u8 *) &sp3E0 + 0x14)) = 0.0f;
        var_f4_992 = ((f32) sp3F8 * (f32) sp3F8) + (((f32) sp3F0 * (f32) sp3F0) + (0.0f * 0.0f));
        if (var_f4_992 > 0.000001f) {
            if (var_f4_992 > 0.0f) {
                temp_f1_997 = __frsqrte(var_f4_992);
                temp_f1_1003 = 0.5 * temp_f1_997 * -(((f64) var_f4_992 * (temp_f1_997 * temp_f1_997)) - 3.0);
                temp_f1_1007 = 0.5 * temp_f1_1003 * -(((f64) var_f4_992 * (temp_f1_1003 * temp_f1_1003)) - 3.0);
                var_f4_992 = (f32) ((f64) var_f4_992 * (0.5 * temp_f1_1007 * -(((f64) var_f4_992 * (temp_f1_1007 * temp_f1_1007)) - 3.0)));
            } else if (var_f4_992 < M2C_BITWISE(f32, 0.0)) {
                var_f4_992 = __float_nan;
            } else {
                sp18 = var_f4_992;
                temp_r3_1026 = M2C_BITWISE(s32, sp18) & 0x7F800000;
                switch (temp_r3_1026) {             /* switch 4; irregular */
                case 0x7F800000:                    /* switch 4 */
                    if (M2C_BITWISE(s32, sp18) & 0x7FFFFF) {
                        var_r0_1036 = 1;
                    } else {
                        var_r0_1036 = 2;
                    }
                    break;
                case 0x0:                           /* switch 4 */
                    if (M2C_BITWISE(s32, sp18) & 0x7FFFFF) {
                        var_r0_1036 = 5;
                    } else {
                        var_r0_1036 = 3;
                    }
                    break;
                default:                            /* switch 4 */
                    var_r0_1036 = 4;
                    break;
                }
                if (var_r0_1036 == 1) {
                    var_f4_992 = __float_nan;
                }
            }
            var_f7_983 = 1.0f / var_f4_992;
        }
        var_f8_1065 = 0.0f;
        spB0 = -sp470;
        spB4 = -sp474;
        spB8 = -sp478;
        sp3B0 = (f64) spB0;
        sp3B8 = (f64) spB8;
        sp3F0 = (f32) sp3F0 * var_f7_983;
        (*(f32 *) ((u8 *) &sp3E0 + 0x14)) *= var_f7_983;
        sp3F8 = (f32) sp3F8 * var_f7_983;
        var_f4_1090 = ((f32) sp3B8 * (f32) sp3B8) + (((f32) sp3B0 * (f32) sp3B0) + (0.0f * 0.0f));
        (*(f32 *) ((u8 *) &sp398 + 0x1c)) = 0.0f;
        if (var_f4_1090 > 0.000001f) {
            if (var_f4_1090 > 0.0f) {
                temp_f1_1096 = __frsqrte(var_f4_1090);
                temp_f1_1102 = 0.5 * temp_f1_1096 * -(((f64) var_f4_1090 * (temp_f1_1096 * temp_f1_1096)) - 3.0);
                temp_f1_1106 = 0.5 * temp_f1_1102 * -(((f64) var_f4_1090 * (temp_f1_1102 * temp_f1_1102)) - 3.0);
                var_f4_1090 = (f32) ((f64) var_f4_1090 * (0.5 * temp_f1_1106 * -(((f64) var_f4_1090 * (temp_f1_1106 * temp_f1_1106)) - 3.0)));
            } else if (var_f4_1090 < M2C_BITWISE(f32, 0.0)) {
                var_f4_1090 = __float_nan;
            } else {
                sp14 = var_f4_1090;
                temp_r3_1125 = M2C_BITWISE(s32, sp14) & 0x7F800000;
                switch (temp_r3_1125) {             /* switch 5; irregular */
                case 0x7F800000:                    /* switch 5 */
                    if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                        var_r0_1135 = 1;
                    } else {
                        var_r0_1135 = 2;
                    }
                    break;
                case 0x0:                           /* switch 5 */
                    if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                        var_r0_1135 = 5;
                    } else {
                        var_r0_1135 = 3;
                    }
                    break;
                default:                            /* switch 5 */
                    var_r0_1135 = 4;
                    break;
                }
                if (var_r0_1135 == 1) {
                    var_f4_1090 = __float_nan;
                }
            }
            var_f8_1065 = 1.0f / var_f4_1090;
        }
        sp3A0 = sp450;
        temp_f6_1162 = (*(f32 *) ((u8 *) &sp398 + 0x1c)) * var_f8_1065;
        var_f9_1164 = 0.0f;
        temp_f7_1169 = (f32) sp3B0 * var_f8_1065;
        sp3A8 = sp458;
        temp_f5_1176 = (f32) sp3B8 * var_f8_1065;
        var_f8_1184 = ((f32) sp3A8 * (f32) sp3A8) + (((f32) sp3A0 * (f32) sp3A0) + (0.0f * 0.0f));
        sp3B0 = temp_f7_1169;
        var_f31_1186 = 1.0f - ((temp_f5_1176 * sp3F8) + ((temp_f7_1169 * sp3F0) + (temp_f6_1162 * (*(f32 *) ((u8 *) &sp3E0 + 0x14)))));
        (*(f32 *) ((u8 *) &sp398 + 0x1c)) = temp_f6_1162;
        sp3B8 = temp_f5_1176;
        (*(f32 *) ((u8 *) &sp398 + 0xc)) = 0.0f;
        if (var_f8_1184 > 0.000001f) {
            if (var_f8_1184 > 0.0f) {
                temp_f1_1194 = __frsqrte(var_f8_1184);
                temp_f1_1200 = 0.5 * temp_f1_1194 * -(((f64) var_f8_1184 * (temp_f1_1194 * temp_f1_1194)) - 3.0);
                temp_f1_1204 = 0.5 * temp_f1_1200 * -(((f64) var_f8_1184 * (temp_f1_1200 * temp_f1_1200)) - 3.0);
                var_f8_1184 = (f32) ((f64) var_f8_1184 * (0.5 * temp_f1_1204 * -(((f64) var_f8_1184 * (temp_f1_1204 * temp_f1_1204)) - 3.0)));
            } else if (var_f8_1184 < M2C_BITWISE(f32, 0.0)) {
                var_f8_1184 = __float_nan;
            } else {
                sp10 = var_f8_1184;
                temp_r3_1223 = M2C_BITWISE(s32, sp10) & 0x7F800000;
                switch (temp_r3_1223) {             /* switch 6; irregular */
                case 0x7F800000:                    /* switch 6 */
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_1233 = 1;
                    } else {
                        var_r0_1233 = 2;
                    }
                    break;
                case 0x0:                           /* switch 6 */
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_1233 = 5;
                    } else {
                        var_r0_1233 = 3;
                    }
                    break;
                default:                            /* switch 6 */
                    var_r0_1233 = 4;
                    break;
                }
                if (var_r0_1233 == 1) {
                    var_f8_1184 = __float_nan;
                }
            }
            var_f9_1164 = 1.0f / var_f8_1184;
        }
        temp_f4_1259 = (*(f32 *) ((u8 *) &sp398 + 0xc)) * var_f9_1164;
        temp_f5_1261 = (f32) sp3A0 * var_f9_1164;
        temp_f3_1263 = (f32) sp3A8 * var_f9_1164;
        sp3A0 = temp_f5_1261;
        (*(f32 *) ((u8 *) &sp398 + 0xc)) = temp_f4_1259;
        sp3A8 = temp_f3_1263;
        if (((sp3F8 * temp_f3_1263) + ((sp3F0 * temp_f5_1261) + ((*(f32 *) ((u8 *) &sp3E0 + 0x14)) * temp_f4_1259))) < 0.0f) {
            var_f31_1186 = -var_f31_1186;
        }
        temp_f1_1276 = _table_sinf(M2C_FIELD(this, f32 *, 0x1AC));
        temp_f6_1277 = M2C_FIELD(this, f64 *, 0x110);
        temp_f3_1278 = -temp_f1_1276;
        sp1F0 = temp_f6_1277;
        spA8 = 0.0f;
        temp_f5_1287 = M2C_FIELD(this, f64 *, 0x118);
        sp70 = 0.0f;
        sp74 = 100.0f * temp_f1_1276;
        sp78 = 0.0f;
        spA0 = (0.03f * temp_f3_1278) - (f32) sp1F0;
        spA4 = var_f31_1186;
        sp1E0 = (f64) sp70;
        sp1F8 = temp_f5_1287;
        sp380.unk10 = (f64) spA0;
        sp398 = (f64) spA8;
        sp1E8 = (f64) sp78;
        sp400 += sp1E0;
        sp408 = (f32) sp408 + (f32) sp1E8;
        if ((u8) this->unk24C != 0) {
            temp_f9_1314 = -(*(f32 *) ((u8 *) &sp3E0 + 0x14));
            temp_f10_1315 = -sp3F8;
            temp_f8_1317 = -sp3F0;
            sp44 = temp_f9_1314;
            sp48 = temp_f10_1315;
            sp40 = temp_f8_1317;
            sp1B8 = (f64) sp48;
            sp1B0 = (f64) sp40;
            sp68 = temp_f10_1315;
            sp60 = temp_f8_1317;
            sp64 = temp_f9_1314;
            sp58 = (MKVector3::up.unk0 * (*(f32 *) ((u8 *) &sp1B0 + 0x4))) - (MKVector3::up.unk4 * (f32) sp1B0);
            sp1D0 = (f64) sp60;
            sp1D8 = (f64) sp68;
            sp1C8 = (f64) sp58;
            sp50 = (MKVector3::up.unk4 * (f32) sp1B8) - (MKVector3::up.unk8 * (*(f32 *) ((u8 *) &sp1B0 + 0x4)));
            sp54 = (MKVector3::up.unk8 * (f32) sp1B0) - (MKVector3::up.unk0 * (f32) sp1B8);
            sp430 = (f32) sp1D0;
            sp1C0 = (f64) sp50;
            sp434 = (*(f32 *) ((u8 *) &sp1D0 + 0x4));
            sp438 = (f32) sp1D8;
            sp43C = 0.0f;
            sp420 = MKVector3::up.unk0;
            sp424 = MKVector3::up.unk4;
            sp428 = MKVector3::up.unk8;
            sp42C = 0.0f;
            sp410 = (f32) sp1C0;
            sp414 = (*(f32 *) ((u8 *) &sp1C0 + 0x4));
            sp418 = (f32) sp1C8;
            sp41C = 0.0f;
            this->unk24C = 0;
        } else {
            sp190 = temp_f6_1277;
            sp198 = temp_f5_1287;
            temp_f0_1377 = sp190 + M2C_BITWISE(f64, sp380.unk10);
            sp90 = temp_f0_1377;
            sp1A0 = temp_f0_1377;
            sp98 = (f32) sp198 + (f32) sp398;
            sp1A8 = (f64) sp98;
            ((Matrix *) &sp410)->SetRotationPYR(*((MKVector3 *) &sp1A0));
        }
        sp440 = (f32) sp400;
        sp444 = (*(f32 *) ((u8 *) &sp400 + 0x4));
        sp448 = sp408;
        sp44C = 1.0f;
        MKModel_SetWorldMatrix(this->unk4, *((Matrix *) &sp410));
        sp180 = ((Matrix *) &sp410)->GetRotationPYR();
        M2C_FIELD(this, MKVector3 *, 0x110) = sp180;
    }
}
#endif

f32 Gondola::Resolve() {
    s8 sp14;
    MKCollisionInfo *sp10;
    s32 spC;
    s32 sp8;
    MKCollisionInfo *temp_r5_1440;

    Platform::Resolve();
    this->unk1B0.Resolve();
    ((SpawnerObject *) &this->unk1B0)->FunctionOff();
    temp_r5_1440 = &this->unk70;
    spC = 0;
    sp8 = 0x40F;
    sp10 = temp_r5_1440;
    sp14 = 1;
    M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, MKCollisionInfo *, M2C_UNK), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &sp8, temp_r5_1440, 0x40F);
}

s32 Gondola::LoadDone() {
    Platform::LoadDone();
    this->unk1B0.LoadDone();
    this->unk238 = checked_cast<SkyClouds *, MKProp>(gMK->CreateProp("SkyClouds"));
}

extern "C" s32 stricmp(s8 *, s8 *);
s32 Gondola::LoadLine(MKIniLine *arg0) {
    MKVector3 sp18;
    MKVector3 sp8;
    MKIniLine *var_r30_1539;
    MKIniLine *var_r30_1587;
    s32 temp_r3_1526;
    s32 temp_r3_1574;

    if ((Platform::LoadLine(arg0) != 0) || (this->unk1B0.LoadLine(arg0) != 0)) {
        return 1;
    }
    if (stricmp(arg0->GetFieldName(), (s8 *) "waypoints") == 0) {
        if ((u32) this->unk18C != 0U) {
            return 0;
        }
        temp_r3_1526 = arg0->GetNmbrOfSubLines();
        if (temp_r3_1526 == 0) {
            return 0;
        }
        ((KDUniformSpline *) &this->unk180)->Init(temp_r3_1526, 0U);
        var_r30_1539 = arg0->unkC->GetSubLine(arg0);
loop_10:
        if (var_r30_1539 != NULL) {
            var_r30_1539->AsVector3(0, &sp18);
            ((KDUniformSpline *) &this->unk180)->AddNode(sp18);
            var_r30_1539 = var_r30_1539->unkC->GetNextLine(var_r30_1539);
            goto loop_10;
        }
        return 1;
    }
    if (stricmp(arg0->GetFieldName(), (s8 *) "returnwaypoints") == 0) {
        if ((u32) this->unk1A0 != 0U) {
            return 0;
        }
        temp_r3_1574 = arg0->GetNmbrOfSubLines();
        if (temp_r3_1574 == 0) {
            return 0;
        }
        ((KDUniformSpline *) &this->unk194)->Init(temp_r3_1574, 0U);
        var_r30_1587 = arg0->unkC->GetSubLine(arg0);
loop_19:
        if (var_r30_1587 != NULL) {
            var_r30_1587->AsVector3(0, &sp8);
            ((KDUniformSpline *) &this->unk194)->AddNode(sp8);
            var_r30_1587 = var_r30_1587->unkC->GetNextLine(var_r30_1587);
            goto loop_19;
        }
        return 1;
    }
    return 0;
}

void Gondola::SetDefaults() {
    this->unk1A8 = 0.0f;
    this->unk23C = 0.0f;
    this->unk244 = 2;
    this->unk240 = 2;
    PhrasePlayer_StopEvent(this->unk248);
    this->unk1B0.SetDefaults();
    this->unk1B0.DespawnAll();
    PropUpdate();
}

void Gondola::Init() {
    GondolaDescriptor *desc;

    Platform::Init();
    this->unk1A8 = 0.0f;
    this->unk244 = 2;
    this->unk240 = 2;
    this->unk1AC.Init();
    this->unk23C = 0.0f;
    this->unk248 = 0;
    desc = checked_cast<GondolaDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    this->unk1B0.Init((EnemyGeneratorDescriptor *) ((u8 *) desc + 0x124), (MKProp *) this);
    this->unk24C = 0;
}

void GondolaDescriptor::LoadDone() {
    PlatformDescriptor::LoadDone();
    ((EnemyGeneratorDescriptor *) ((u8 *) this + 0x124))->LoadDone();
}

s32 GondolaDescriptor::LoadLine(MKIniLine *arg0) {
    s32 var_r31_1711;

    var_r31_1711 = 0;
    if ((PlatformDescriptor::LoadLine(arg0) != 0) || (((EnemyGeneratorDescriptor *) ((u8 *) this + 0x124))->LoadLine(arg0) != 0)) {
        var_r31_1711 = 1;
    }
    return var_r31_1711;
}

void GondolaDescriptor::Deinit() {
    ((EnemyGeneratorDescriptor *) ((u8 *) this + 0x124))->Deinit();
    KDPropExDescriptor::Deinit();
}

void GondolaDescriptor::Init() {
    PlatformDescriptor::Init();
    ((EnemyGeneratorDescriptor *) ((u8 *) this + 0x124))->Init();
}

void Gondola_cpp::__sinit() {
    f32 temp_f0_1815;
    f64 temp_f1_1796;
    f64 temp_f1_1804;
    f64 temp_f3_1784;
    f64 temp_f4_1793;
    f64 temp_f4_1801;
    f64 temp_f8_1786;

    temp_f3_1784 = __frsqrte(2014000.0);
    temp_f8_1786 = __frsqrte(380000.0);
    temp_f4_1793 = 0.5 * temp_f3_1784 * -((2014000.0 * (temp_f3_1784 * temp_f3_1784)) - 3.0);
    temp_f1_1796 = 0.5 * temp_f8_1786 * -((380000.0 * (temp_f8_1786 * temp_f8_1786)) - 3.0);
    temp_f4_1801 = 0.5 * temp_f4_1793 * -((2014000.0 * (temp_f4_1793 * temp_f4_1793)) - 3.0);
    temp_f1_1804 = 0.5 * temp_f1_1796 * -((380000.0 * (temp_f1_1796 * temp_f1_1796)) - 3.0);
    temp_f0_1815 = (f32) (380000.0 * (0.5 * temp_f1_1804 * -((380000.0 * (temp_f1_1804 * temp_f1_1804)) - 3.0)));
    SPYRO_BOUNCE_Y_SPEED = (f32) (2014000.0 * (0.5 * temp_f4_1801 * -((2014000.0 * (temp_f4_1801 * temp_f4_1801)) - 3.0)));
    SPYRO_MIN_JUMP_Y_VELOCITY = temp_f0_1815;
}
