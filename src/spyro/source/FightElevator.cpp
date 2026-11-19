#include "spyro/source/FightElevator.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "spyro/source/EnergyBeam.h"
#include "spyro/source/FightElevatorAnchor.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSpline.h"
#include "spyro/source/Platform.h"
#include "spyro/source/PlatformObject.h"
#include "spyro/source/Shatterable.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "common/Source/MKModel.h"
#include "spyro/source/SplineTools.h"
#include "spyro/source/Tools.h"
#include <m2c_macros.h>

s32 stricmp(void *);                                /* extern */
extern f32 FIGHT_ELEVATOR_HERO_DETACH_DIST_SQ;
extern f32 FIGHT_ELEVATOR_TO_BLOCKER_BLOCK_DISTANCE_SQ;
extern s32 GS_TowerElevatorSparks;
extern f32 *KDSpline_PositionMixer;
extern f32 SPYRO_BOUNCE_Y_SPEED;
extern f32 SPYRO_MIN_JUMP_Y_VELOCITY;
extern M2C_UNK fingerprintData;
extern void **gMK;
extern f32 gUpdateTimeDelta;
extern void **gb;

#if 0 // DRAFT: undefined identifier 'unksp5C'
s32 FightElevator::GetClosestWaypointToPlayerIndex() {
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
    f64 sp18;
    f32 sp10;
    f64 sp8;
    f32 temp_f3_114;
    f32 var_f7_100;
    f64 temp_f0_110;
    f64 temp_f0_129;
    f64 temp_f0_80;
    f64 temp_f1_74;
    f64 temp_f4_109;
    s32 temp_r5_73;
    s32 temp_r5_88;
    s32 var_ctr_102;
    s32 var_r3_72;
    s32 var_r4_84;
    s32 var_r6_82;
    void *temp_r4_71;
    void *temp_r5_107;

    temp_r4_71 = M2C_FIELD(M2C_FIELD(*gb, void *(**)(void **, void ***), 0xC)(gb, &gb), void **, 8);
    var_r3_72 = 0;
    temp_r5_73 = this->unk18C;
    temp_f1_74 = M2C_FIELD(temp_r4_71, f64 *, 0x30);
    sp68 = temp_f1_74;
    sp70 = M2C_FIELD(temp_r4_71, f64 *, 0x38);
    temp_f0_80 = temp_f1_74 - M2C_FIELD(temp_r5_73, f64 *, 0);
    sp28 = temp_f0_80;
    var_r6_82 = 1;
    var_r4_84 = 0x20;
    temp_r5_88 = this->unk184;
    sp58 = temp_f0_80;
    sp30 = (f32) sp70 - M2C_FIELD(temp_r5_73, f32 *, 8);
    sp60 = (f64) sp30;
    var_f7_100 = ((f32) sp60 * (f32) sp60) + (((f32) sp58 * (f32) sp58) + (unksp5C * unksp5C));
    var_ctr_102 = temp_r5_88 - 1;
    if (temp_r5_88 > 1) {
        do {
            temp_r5_107 = this->unk18C + var_r4_84;
            temp_f4_109 = M2C_FIELD(temp_r5_107, f64 *, 0);
            temp_f0_110 = sp68 - temp_f4_109;
            sp18 = temp_f0_110;
            temp_f3_114 = (f32) sp70 - M2C_FIELD(temp_r5_107, f32 *, 8);
            sp48 = temp_f0_110;
            sp20 = temp_f3_114;
            sp50 = (f64) sp20;
            if ((((f32) sp50 * (f32) sp50) + (((f32) sp48 * (f32) sp48) + (unksp4C * unksp4C))) < var_f7_100) {
                temp_f0_129 = sp68 - temp_f4_109;
                var_r3_72 = var_r6_82;
                sp8 = temp_f0_129;
                sp10 = temp_f3_114;
                sp38 = temp_f0_129;
                sp40 = (f64) sp10;
                var_f7_100 = ((f32) sp40 * (f32) sp40) + (((f32) sp38 * (f32) sp38) + (unksp3C * unksp3C));
            }
            var_r6_82 += 1;
            var_r4_84 += 0x20;
            var_ctr_102 -= 1;
        } while (var_ctr_102 != 0);
    }
    return var_r3_72;
}
#endif

void FightElevator::UpdateAnchors() {
    EnergyBeam::Beam *temp_r4_186;
    s32 var_r27_174;
    s32 var_r31_171;
    void *temp_r28_176;
    void *temp_r29_172;
    void *temp_r4_177;

    FindAnchors();
    SetBeamPositions();
    var_r31_171 = 0;
    temp_r29_172 = checked_cast<FightElevatorDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    var_r27_174 = 0;
    do {
        temp_r28_176 = this + var_r31_171;
        temp_r4_177 = M2C_FIELD(temp_r28_176, void **, 0x29C);
        if ((temp_r4_177 != NULL) && ((s32) M2C_FIELD(temp_r4_177, s32 *, 0x180) == (s32) (M2C_FIELD(this->unk298, s32 *, 0x160) - 1))) {
            temp_r4_186 = M2C_FIELD(temp_r28_176, EnergyBeam::Beam **, 0x20C);
            if (temp_r4_186 != NULL) {
                ((EnergyBeam *) (M2C_FIELD(temp_r29_172, EnergyBeam **, 0x130)))->FreeEnergyBeam(temp_r4_186);
                M2C_FIELD(temp_r28_176, EnergyBeam::Beam **, 0x20C) = NULL;
            }
        }
        var_r27_174 += 1;
        var_r31_171 += 4;
    } while (var_r27_174 < 6);
}

#if 0 // DRAFT: illegal operand
void FightElevator::ClearAnchors() {
    s32 temp_r0_212;
    s32 var_ctr_210;
    s32 var_r4_207;

    var_r4_207 = 0;
    var_ctr_210 = 6;
    do {
        temp_r0_212 = var_r4_207 + 0x29C;
        var_r4_207 += 4;
        *(this + temp_r0_212) = 0;
        var_ctr_210 -= 1;
    } while (var_ctr_210 != 0);
}
#endif

#if 0 // DRAFT: illegal type
void FightElevator::FindAnchors() {
    f64 sp30;
    f64 sp28;
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    f32 temp_f31_232;
    f64 temp_f0_246;
    f64 temp_f1_239;
    s32 temp_r4_290;
    s32 var_ctr_276;
    s32 var_r29_233;
    s32 var_r30_234;
    s32 var_r4_275;
    u8 var_r5_274;
    void *temp_r4_241;
    void *temp_r5_237;
    void *var_r3_231;

    var_r3_231 = checked_cast<FightElevatorAnchor *, MKProp>(M2C_FIELD(this->unk298, MKProp **, 0x28));
    temp_f31_232 = FIGHT_ELEVATOR_TO_BLOCKER_BLOCK_DISTANCE_SQ;
    var_r29_233 = 0;
    var_r30_234 = 0;
loop_12:
    if ((var_r3_231 != NULL) && (var_r29_233 < 6)) {
        temp_r5_237 = M2C_FIELD(var_r3_231, void **, 8);
        temp_f1_239 = M2C_FIELD(temp_r5_237, f64 *, 0x30);
        temp_r4_241 = this->unk8 + 0x30;
        sp28 = temp_f1_239;
        sp30 = M2C_FIELD(temp_r5_237, f64 *, 0x38);
        temp_f0_246 = temp_f1_239 - M2C_FIELD(temp_r4_241, f64 *, 0);
        sp8 = temp_f0_246;
        sp18 = temp_f0_246;
        sp10 = (f32) sp30 - M2C_FIELD(temp_r4_241, f32 *, 8);
        sp20 = (f64) sp10;
        if (((((f32) sp20 * (f32) sp20) + (((f32) sp18 * (f32) sp18) + (unksp1C * unksp1C))) <= temp_f31_232) && (unksp1C < M2C_BITWISE(f32, 209.99998474121094)) && (unksp1C > 0.0f)) {
            var_r5_274 = 0;
            var_r4_275 = 0;
            var_ctr_276 = 6;
loop_5:
            if ((u32) *(this + (var_r4_275 + 0x29C)) == var_r3_231) {
                var_r5_274 = 1;
            } else {
                var_r4_275 += 4;
                var_ctr_276 -= 1;
                if (var_ctr_276 != 0) {
                    goto loop_5;
                }
            }
            if (var_r5_274 == 0) {
                temp_r4_290 = var_r30_234 + 0x29C;
                if ((u32) *(this + temp_r4_290) == 0U) {
                    *(this + temp_r4_290) = var_r3_231;
                    var_r29_233 += 1;
                    var_r30_234 += 4;
                }
            }
        }
        var_r3_231 = checked_cast<FightElevatorAnchor *, MKProp>(M2C_FIELD(var_r3_231, MKProp **, 0x38));
        goto loop_12;
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'FightElevator' to
void FightElevator::SetBeamPositions() {
    f64 sp8;
    s32 var_r29_323;
    s32 var_r30_325;
    s32 var_r31_324;
    void *temp_r3_326;
    void *temp_r3_341;

    var_r29_323 = 0;
    var_r31_324 = 0;
    var_r30_325 = 0;
    temp_r3_326 = this->unk8;
    this->unk288 = M2C_FIELD(temp_r3_326, f64 *, 0x30);
    this->unk290 = M2C_FIELD(temp_r3_326, f64 *, 0x38);
    do {
        if ((u32) *(this + (var_r30_325 + 0x29C)) != 0U) {
            ((FightElevatorAnchor *) &sp8)->GetZapAnchorPos();
            temp_r3_341 = this + (var_r31_324 + 0x228);
            M2C_FIELD(temp_r3_341, f64 *, 0) = sp8;
            M2C_FIELD(temp_r3_341, f64 *, 8) = sp10;
        }
        var_r29_323 += 1;
        var_r30_325 += 4;
        var_r31_324 += 0x10;
    } while (var_r29_323 < 6);
    AllocBeams();
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'FightElevator' to
void FightElevator::FreeBeams() {
    EnergyBeam::Beam *temp_r4_375;
    s32 temp_r28_374;
    s32 var_r27_372;
    s32 var_r31_369;
    void *temp_r29_370;

    var_r31_369 = 0;
    temp_r29_370 = checked_cast<FightElevatorDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    var_r27_372 = 0;
    do {
        temp_r28_374 = var_r31_369 + 0x20C;
        temp_r4_375 = *(this + temp_r28_374);
        if (temp_r4_375 != NULL) {
            ((EnergyBeam *) (M2C_FIELD(temp_r29_370, EnergyBeam **, 0x130)))->FreeEnergyBeam(temp_r4_375);
            *(this + temp_r28_374) = 0;
        }
        var_r27_372 += 1;
        var_r31_369 += 4;
    } while (var_r27_372 < 6);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'FightElevator *' to
void FightElevator::AllocBeams() {
    s32 var_r27_404;
    s32 var_r30_406;
    s32 var_r31_405;
    void *temp_r28_408;
    void *temp_r29_403;

    temp_r29_403 = checked_cast<FightElevatorDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    var_r27_404 = 0;
    var_r31_405 = 0;
    var_r30_406 = 0;
    do {
        temp_r28_408 = this + var_r30_406;
        if (((u32) M2C_FIELD(temp_r28_408, u32 *, 0x20C) == 0U) && ((u32) M2C_FIELD(temp_r28_408, u32 *, 0x29C) != 0U)) {
            ((EnergyBeam *) (M2C_FIELD(temp_r29_403, EnergyBeam **, 0x130)))->SpawnEnergyBeam((MKVector3 *) &this->unk288, this + (var_r31_405 + 0x228), 1.0f);
            M2C_FIELD(temp_r28_408, u32 *, 0x20C) = (u32) M2C_ERROR(/* Read from unset register $r3 */);
        }
        var_r27_404 += 1;
        var_r30_406 += 4;
        var_r31_405 += 0x10;
    } while (var_r27_404 < 6);
}
#endif

#if 0 // DRAFT: function call 'KDSound_Stop(long *)' does not match
void FightElevator::Deinit() {
    KDSound_Stop(&this->unk1BC);
    KDSound_Stop(&this->unk1E4);
    ((KDUniformSpline *) &this->unk180)->Deinit();
    FreeBeams();
    Platform::Deinit();
}
#endif

void FightElevator::Draw() {
    GameProp::Draw();
}

#if 0 // DRAFT: illegal type
void FightElevator::Message(MKMessage *arg0) {
    u8 sp84;
    PlatformObject *sp80;
    s32 sp7C;
    s32 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    u8 sp54;
    PlatformObject *sp50;
    s32 sp4C;
    s32 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    f64 temp_f1_544;
    f64 temp_f1_576;
    s32 temp_r0_487;
    s32 var_ctr_711;
    s32 var_ctr_726;
    s32 var_r3_709;
    s32 var_r3_724;
    s32 var_r6_622;
    u32 var_r5_620;
    void *temp_r29_538;
    void *temp_r3_543;
    void *temp_r3_575;
    void *temp_r3_625;
    void *temp_r4_535;
    void *temp_r4_574;
    void *temp_r5_714;
    void *temp_r5_729;

    ((KDSoundPlayer *) &this->unk1BC)->Message(arg0);
    ((KDSoundPlayer *) &this->unk1E4)->Message(arg0);
    temp_r0_487 = arg0->unk0;
    switch (temp_r0_487) {                          /* irregular */
    case 148:
        if ((u8) this->unk1A4 != 0) {
            this->unk198 = 3;
        } else {
            sp7C = 0;
            sp78 = 0x25;
            sp80 = &this->unk108;
            sp84 = 0;
            M2C_FIELD(M2C_FIELD(M2C_FIELD(*gb, void *(**)(void **, M2C_UNK, M2C_UNK), 0xC)(gb, 0x25, 0), void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp78);
            if ((sp84 != 0) || (temp_r4_535 = this->unk8, temp_r29_538 = temp_r4_535 + 0x30, temp_r3_543 = M2C_FIELD(M2C_FIELD(*gb, void *(**)(void **, void *), 0xC)(gb, temp_r4_535), void **, 8), temp_f1_544 = M2C_FIELD(temp_r3_543, f64 *, 0x30), sp28 = temp_f1_544, sp30 = M2C_FIELD(temp_r3_543, f64 *, 0x38), sp18 = temp_f1_544 - M2C_FIELD(temp_r29_538, f64 *, 0), sp38 = sp18, sp20 = (f32) sp30 - M2C_FIELD(temp_r29_538, f32 *, 8), sp40 = (f64) sp20, (((((f32) sp40 * (f32) sp40) + (((f32) sp38 * (f32) sp38) + (unksp3C * unksp3C))) >= FIGHT_ELEVATOR_HERO_DETACH_DIST_SQ) == 0))) {
                temp_r4_574 = M2C_FIELD(arg0->unk4, void **, 8);
                temp_r3_575 = this->unk8 + 0x30;
                temp_f1_576 = M2C_FIELD(temp_r4_574, f64 *, 0x30);
                sp68 = temp_f1_576;
                sp70 = M2C_FIELD(temp_r4_574, f64 *, 0x38);
                sp8 = temp_f1_576 - M2C_FIELD(temp_r3_575, f64 *, 0);
                sp58 = sp8;
                sp10 = (f32) sp70 - M2C_FIELD(temp_r3_575, f32 *, 8);
                sp60 = (f64) sp10;
                if (((((f32) sp60 * (f32) sp60) + (((f32) sp58 * (f32) sp58) + (unksp5C * unksp5C))) <= FIGHT_ELEVATOR_TO_BLOCKER_BLOCK_DISTANCE_SQ) && (unksp5C < 104.99999f) && (unksp5C > 0.0f)) {
                    FreeBeams();
                    ClearAnchors();
                    this->unk1A4 = 1;
                    this->unk198 = 3;
                }
            }
        }
    default:
block_39:
        Platform::Message(arg0);
        return;
    case 181:
        var_r5_620 = 0U;
        var_r6_622 = 0;
loop_20:
        if ((s8) M2C_FIELD((&fingerprintData + var_r6_622), u8 *, 8) != 0) {
            temp_r3_625 = &fingerprintData + var_r6_622;
            var_r6_622 += 1;
            var_r5_620 += (s8) M2C_FIELD(temp_r3_625, u8 *, 8);
            goto loop_20;
        }
        if (var_r5_620 == (u32) M2C_FIELD(&fingerprintData, u32 *, 0x108)) {
            this->unk1B8 += 1;
            this->unk1A4 = 0;
            sp4C = 0;
            sp48 = 0x25;
            sp50 = &this->unk108;
            sp54 = 0;
            M2C_FIELD(M2C_FIELD(M2C_FIELD(*gb, void *(**)(void **, M2C_UNK, M2C_UNK), 0xC)(gb, 0x25, 0), void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp48);
            if (this->unk194 > SplineTools_GetNodeTime(*((KDUniformSpline *) &this->unk180), GetClosestWaypointToPlayerIndex())) {
                this->unk1A0 = 2;
                this->unk198 = 2;
                if (sp54 == 0) {
                    this->unk198 = 0;
                }
            } else {
                this->unk1A0 = 1;
                this->unk198 = 1;
                if (sp54 == 0) {
                    this->unk198 = 0;
                }
            }
            FreeBeams();
            ClearAnchors();
            return;
        }
        break;
    case 21:
        if ((u8) this->unk1B0 != 0) {
            FreeBeams();
            ClearAnchors();
            SetDefaults();
        }
        goto block_39;
    case -3:
        var_r3_709 = 0;
        var_ctr_711 = 6;
        do {
            temp_r5_714 = *(this + (var_r3_709 + 0x20C));
            if (temp_r5_714 != NULL) {
                M2C_FIELD(temp_r5_714, s8 *, 0x10) = 1;
            }
            var_r3_709 += 4;
            var_ctr_711 -= 1;
        } while (var_ctr_711 != 0);
        goto block_39;
    case -4:
        var_r3_724 = 0;
        var_ctr_726 = 6;
        do {
            temp_r5_729 = *(this + (var_r3_724 + 0x20C));
            if (temp_r5_729 != NULL) {
                M2C_FIELD(temp_r5_729, s8 *, 0x10) = 0;
            }
            var_r3_724 += 4;
            var_ctr_726 -= 1;
        } while (var_ctr_726 != 0);
        goto block_39;
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'KDUniformSpline' to
void FightElevator::UpdateMove() {
    Matrix sp50;
    M2C_UNK sp4C;
    f64 sp40;
    KDUniformSpline sp28;
    f64 sp18;
    f32 sp10;

    sp10 = 0.0f;
    sp28.GetMeasure(this->unk194, (Matrix *) &this->unk180, KDSpline_PositionMixer);
    sp28.unk10 = M2C_BITWISE(f64, sp28);
    sp40 = (f64) sp28.unk8;
    M2C_STRUCT_COPY((s32) &sp4C + 4, MKModel_GetWorldMatrix(this->unk4) - 4 + 4, 0x40);
    sp50.unk30 = M2C_BITWISE(f32, sp28.unk10);
    sp50.unk34 = sp3C;
    sp50.unk38 = (f32) sp40;
    sp50.unk3C = 1.0f;
    MKModel_SetWorldMatrix(this->unk4, sp50);
    ((Matrix *) &sp18)->GetRotationPYR();
    M2C_FIELD(this, f64 *, 0x110) = sp18;
    M2C_FIELD(this, f64 *, 0x118) = sp20;
}
#endif

#if 0 // DRAFT: ')' expected
void FightElevator::Update() {
    u8 sp94;
    PlatformObject *sp90;
    s32 sp8C;
    s32 sp88;
    u8 sp84;
    PlatformObject *sp80;
    s32 sp7C;
    s32 sp78;
    u8 sp74;
    PlatformObject *sp70;
    s32 sp6C;
    s32 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    s32 sp8;
    MKVector3 *temp_r31_907;
    MKVector3 *temp_r31_933;
    f32 temp_f0_1391;
    f32 temp_f1_1050;
    f32 temp_f1_1390;
    f32 temp_f2_1348;
    f32 temp_f2_920;
    f32 temp_f30_1080;
    f32 var_f0_1332;
    f32 var_f29_1136;
    f32 var_f29_1303;
    f64 temp_f1_1104;
    f64 temp_f1_1113;
    f64 temp_f1_1139;
    f64 temp_f1_1145;
    f64 temp_f1_1149;
    s32 temp_r0_1206;
    s32 temp_r0_1306;
    s32 temp_r0_829;
    s32 temp_r0_872;
    s32 temp_r0_945;
    s32 temp_r3_1073;
    s32 temp_r3_1168;
    s32 temp_r3_873;
    s32 temp_r5_1234;
    s32 temp_r5_1269;
    s32 var_ctr_1309;
    s32 var_r0_1178;
    s32 var_r4_1238;
    s32 var_r4_1273;
    u8 var_r31_830;
    u8 var_r6_857;
    void *temp_r3_1112;
    void *temp_r4_1101;
    void *temp_r4_841;
    void *temp_r6_1087;

    GameProp::Update();
    if ((s32) M2C_FIELD(checked_cast<FightElevatorDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x12C) != 0) {
        temp_r0_829 = this->unk198;
        var_r31_830 = 0;
        if ((temp_r0_829 == 1) || (temp_r0_829 == 2)) {
            var_r31_830 = 1;
        }
        temp_r4_841 = checked_cast<FightElevatorDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        sp8 = 1;
        ((KDSoundFader *) &this->unk1BC)->Update(M2C_FIELD(temp_r4_841, s32 *, 0x12C), 1U, var_r31_830, (MKProp *) this, NULL, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    }
    sp8 = 1;
    var_r6_857 = 0;
    if (((s32) this->unk198 == 3) && ((u8) this->unk1A4 != 0)) {
        var_r6_857 = 1;
    }
    ((KDSoundFader *) &this->unk1E4)->Update(GS_TowerElevatorSparks, 1U, var_r6_857, (MKProp *) this, NULL, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    temp_r0_872 = this->unk19C;
    temp_r3_873 = this->unk198;
    if (temp_r0_872 != temp_r3_873) {
        switch (temp_r0_872) {                      /* switch 1; irregular */
        case 0:                                     /* switch 1 */
        case 3:                                     /* switch 1 */
            if ((temp_r3_873 == 1) || (temp_r3_873 == 2)) {
                this->unk1AC = 0.125f;
            } else if (((temp_r0_872 == 1) || (temp_r0_872 == 2)) && ((temp_r3_873 == 0) || (temp_r3_873 == 3))) {
                if (this->unk1AC <= 0.0f) {
                    temp_r31_907 = this->unk8 + 0x30;
                    KDSound_Play3d(M2C_FIELD(checked_cast<FightElevatorDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x128), temp_r31_907, 0U, -1, 0.0f, 0U);
                } else {
                    this->unk1AC = 0.0f;
                }
            }
            break;
        }
    }
    temp_f2_920 = this->unk1AC;
    if (temp_f2_920 > 0.0f) {
        this->unk1AC = temp_f2_920 - gUpdateTimeDelta;
        if (this->unk1AC <= 0.0f) {
            temp_r31_933 = this->unk8 + 0x30;
            KDSound_Play3d(M2C_FIELD(checked_cast<FightElevatorDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x124), temp_r31_933, 0U, -1, 0.0f, 0U);
        }
    }
    this->unk19C = this->unk198;
    temp_r0_945 = this->unk198;
    if (temp_r0_945 != 3) {
        if (temp_r0_945 < 3) {
            if (temp_r0_945 != 0) {
                if (temp_r0_945 < 0) {
                    goto block_100;
                }
                sp7C = 0;
                sp78 = 0x25;
                sp80 = &this->unk108;
                sp84 = 0;
                M2C_FIELD(M2C_FIELD(M2C_FIELD(*gb, void *(**)(void **, M2C_UNK, M2C_UNK), 0xC)(gb, 0x25, 0), void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp78);
                temp_f1_1050 = SplineTools_GetNodeTime(*((KDUniformSpline *) &this->unk180), this->unk1B8);
                if (this->unk194 > temp_f1_1050) {
                    this->unk1A0 = 1;
                    this->unk198 = 0;
                    this->unk1B4 = SplineTools_GetNodeTime(*((KDUniformSpline *) &this->unk180), this->unk1B8);
                    this->unk194 = temp_f1_1050;
                    this->unk1A4 = 1;
                    FreeBeams();
                    ClearAnchors();
                    return;
                }
                temp_r3_1073 = GetClosestWaypointToPlayerIndex();
                temp_f30_1080 = SplineTools_GetNodeTime(*((KDUniformSpline *) &this->unk180), temp_r3_1073);
                temp_r6_1087 = M2C_FIELD(M2C_FIELD(*gb, void *(**)(void **), 0xC)(gb), void **, 8);
                sp58 = M2C_FIELD(temp_r6_1087, f64 *, 0x30);
                sp60 = M2C_FIELD(temp_r6_1087, f64 *, 0x38);
                Tools_GetClosestSplineTime((KDUniformSpline *) &this->unk180, *((MKVector3 *) &sp58), 0xA);
                if (sp84 == 0) {
                    temp_r4_1101 = this->unk8;
                    temp_f1_1104 = M2C_FIELD(temp_r4_1101, f64 *, 0x30);
                    sp28 = temp_f1_1104;
                    sp30 = M2C_FIELD(temp_r4_1101, f64 *, 0x38);
                    temp_r3_1112 = M2C_FIELD(M2C_FIELD(*gb, void *(**)(void **, void *, f64), 0xC)(gb, temp_r4_1101, temp_f1_1104), void **, 8);
                    temp_f1_1113 = M2C_FIELD(temp_r3_1112, f64 *, 0x30);
                    sp38 = temp_f1_1113;
                    sp40 = M2C_FIELD(temp_r3_1112, f64 *, 0x38);
                    sp18 = temp_f1_1113 - sp28;
                    sp48 = sp18;
                    sp20 = (f32) sp40 - (f32) sp30;
                    sp50 = (f64) sp20;
                    var_f29_1136 = ((f32) sp50 * (f32) sp50) + (((f32) sp48 * (f32) sp48) + (unksp4C * unksp4C));
                    if (var_f29_1136 > 0.0f) {
                        temp_f1_1139 = __frsqrte(var_f29_1136);
                        temp_f1_1145 = 0.5 * temp_f1_1139 * -(((f64) var_f29_1136 * (temp_f1_1139 * temp_f1_1139)) - 3.0);
                        temp_f1_1149 = 0.5 * temp_f1_1145 * -(((f64) var_f29_1136 * (temp_f1_1145 * temp_f1_1145)) - 3.0);
                        var_f29_1136 = (f32) ((f64) var_f29_1136 * (0.5 * temp_f1_1149 * -(((f64) var_f29_1136 * (temp_f1_1149 * temp_f1_1149)) - 3.0)));
                    } else if (var_f29_1136 < M2C_BITWISE(f32, 0.0)) {
                        var_f29_1136 = __float_nan;
                    } else {
                        sp10 = var_f29_1136;
                        temp_r3_1168 = M2C_BITWISE(s32, sp10) & 0x7F800000;
                        switch (temp_r3_1168) {     /* switch 2; irregular */
                        case 0x7F800000:            /* switch 2 */
                            if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                                var_r0_1178 = 1;
                            } else {
                                var_r0_1178 = 2;
                            }
                            break;
                        case 0x0:                   /* switch 2 */
                            if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                                var_r0_1178 = 5;
                            } else {
                                var_r0_1178 = 3;
                            }
                            break;
                        default:                    /* switch 2 */
                            var_r0_1178 = 4;
                            break;
                        }
                        if (var_r0_1178 == 1) {
                            var_f29_1136 = __float_nan;
                        }
                    }
                    if (var_f29_1136 > M2C_FIELD(MKModel_GetBoundingVolume(this->unk4, (SubObjectType) 0, -1), f32 *, 0xC)) {
                        temp_r0_1206 = this->unk198;
                        if ((temp_r0_1206 == 1) && (this->unk194 >= temp_f30_1080)) {
                            this->unk1A0 = 2;
                            this->unk198 = 2;
                            this->unk1B4 = temp_f30_1080;
                            this->unk1A4 = 0;
                            FreeBeams();
                            ClearAnchors();
                            return;
                        }
                        if ((temp_r0_1206 == 2) && (this->unk194 <= temp_f30_1080)) {
                            this->unk1A0 = 1;
                            temp_r5_1234 = temp_r3_1073 + 1;
                            this->unk198 = 0;
                            var_r4_1238 = this->unk184 - 1;
                            if (temp_r5_1234 < var_r4_1238) {
                                var_r4_1238 = temp_r5_1234;
                            }
                            this->unk1B4 = SplineTools_GetNodeTime(*((KDUniformSpline *) &this->unk180), var_r4_1238);
                            this->unk1A4 = 0;
                            FreeBeams();
                            ClearAnchors();
                            return;
                        }
                        goto block_76;
                    }
                    if ((((s32) this->unk198 == 2) && (this->unk194 <= temp_f30_1080)) || (this->unk194 <= M2C_ERROR(/* Read from unset register $f1 */))) {
                        this->unk1A0 = 1;
                        temp_r5_1269 = temp_r3_1073 + 1;
                        this->unk198 = 0;
                        var_r4_1273 = this->unk184 - 1;
                        if (temp_r5_1269 < var_r4_1273) {
                            var_r4_1273 = temp_r5_1269;
                        }
                        this->unk1B4 = SplineTools_GetNodeTime(*((KDUniformSpline *) &this->unk180), var_r4_1273);
                        this->unk1A4 = 0;
                        FreeBeams();
                        ClearAnchors();
                        return;
                    }
                    goto block_76;
                }
                if ((s32) this->unk198 == 2) {
                    this->unk1A0 = 1;
                    this->unk198 = 1;
                    this->unk1B4 = temp_f30_1080;
                    this->unk1A4 = 0;
                    FreeBeams();
                    ClearAnchors();
                    return;
                }
block_76:
                var_f29_1303 = this->unk1A8;
                this->unk108.GetNumActorsAttached();
                temp_r0_1306 = M2C_ERROR(/* Read from unset register $r3 */) - 1;
                var_ctr_1309 = temp_r0_1306;
                if (temp_r0_1306 > 0) {
                    do {
                        if ((s32) this->unk198 == 1) {
                            var_f29_1303 *= 0.75f;
                        } else {
                            var_f29_1303 *= 1.25f;
                        }
                        var_ctr_1309 -= 1;
                    } while (var_ctr_1309 != 0);
                }
                if ((s32) this->unk198 == 2) {
                    var_f29_1303 = 1.5f * -var_f29_1303;
                }
                var_f0_1332 = (var_f29_1303 * gUpdateTimeDelta) + this->unk194;
                if (var_f0_1332 < 1.0f) {

                } else {
                    var_f0_1332 = 1.0f;
                }
                if (var_f0_1332 > 0.0f) {

                } else {
                    var_f0_1332 = 0.0f;
                }
                this->unk194 = var_f0_1332;
                temp_f2_1348 = this->unk194;
                if (temp_f2_1348 == 0.0f) {
                    this->unk1A0 = 1;
                    this->unk198 = 0;
                    this->unk1B4 = 1.0f;
                    this->unk1A4 = 0;
                    FreeBeams();
                    ClearAnchors();
                } else if (temp_f2_1348 == 1.0f) {
                    this->unk1A0 = 2;
                    this->unk198 = 0;
                    this->unk1B4 = 0.0f;
                    this->unk1A4 = 0;
                    FreeBeams();
                    ClearAnchors();
                }
                goto block_100;
            }
            sp8C = 0;
            sp88 = 0x25;
            sp90 = &this->unk108;
            sp94 = 0;
            M2C_FIELD(M2C_FIELD(M2C_FIELD(*gb, void *(**)(void **, M2C_UNK, M2C_UNK), 0xC)(gb, 0x25, 0), void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp88);
            if ((sp94 != 0) && ((u8) this->unk2B8 == 0)) {
                this->unk2B4.Send((MKProp *) this);
                this->unk2B8 = 1;
            }
            if ((sp94 != 0) && ((u8) this->unk1A4 == 0) && (this->unk1A8 > 0.0f)) {
                if (GetClosestWaypointToPlayerIndex() != (s32) (this->unk184 - 1)) {
                    this->unk198 = this->unk1A0;
                    FreeBeams();
                    ClearAnchors();
                }
                goto block_100;
            }
            if (this->unk194 > SplineTools_GetNodeTime(*((KDUniformSpline *) &this->unk180), GetClosestWaypointToPlayerIndex())) {
                this->unk1A0 = 2;
                this->unk198 = 2;
                this->unk1A4 = 0;
                FreeBeams();
                ClearAnchors();
                return;
            }
            goto block_100;
        }
        goto block_100;
    }
    if ((u8) this->unk1A4 != 0) {
        UpdateAnchors();
    }
    temp_f1_1390 = SplineTools_GetNodeTime(*((KDUniformSpline *) &this->unk180), GetClosestWaypointToPlayerIndex());
    temp_f0_1391 = this->unk194;
    if ((temp_f0_1391 > temp_f1_1390) && ((f32) fabs(temp_f0_1391 - temp_f1_1390) > M2C_BITWISE(f32, 0.01))) {
        this->unk1A0 = 2;
        this->unk198 = 2;
        this->unk1A4 = 0;
        FreeBeams();
        ClearAnchors();
    } else if ((u8) this->unk1A4 == 0) {
        this->unk198 = this->unk1A0;
        FreeBeams();
        ClearAnchors();
    }
block_100:
    sp6C = 0;
    sp68 = 0x25;
    sp70 = &this->unk108;
    sp74 = 0;
    M2C_FIELD(M2C_FIELD(M2C_FIELD(*gb, void *(**)(void **, M2C_UNK, M2C_UNK), 0xC)(gb, 0x25, 0), void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp68);
    this->unk1A5 = sp74;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'const char[20]' to
void FightElevator::Resolve() {
    f32 temp_f1_1475;

    Platform::Resolve();
    this->unk298 = checked_cast<ShatterableDescriptor *, MKPropDescriptor>(M2C_FIELD(*gMK, MKPropDescriptor *(**)(void **, M2C_UNK *), 0x5C)(gMK, "FightElevatorAnchor"));
    temp_f1_1475 = this->unk188;
    if (temp_f1_1475 > 0.0f) {
        this->unk1A8 /= temp_f1_1475;
        return;
    }
    this->unk1A8 = 0.0f;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'unsigned char *' to
s32 FightElevator::LoadLine(MKIniLine *arg0) {
    MKVector3 sp8;
    MKIniLine *var_r30_1562;
    s32 temp_r3_1549;

    if ((Platform::LoadLine(arg0) != 0) || (arg0->LoadFloat("MoveSpeed", &this->unk1A8, 0) != 0) || (arg0->LoadBool("ResetOnHeroDeath", &this->unk1B0, 0) != 0) || (this->unk2B4.LoadLine(arg0, "OnFirstAttach") != 0)) {
        return 1;
    }
    arg0->GetFieldName();
    if (stricmp"waypoints" == 0) {
        if ((u32) this->unk18C != 0U) {
            return 0;
        }
        temp_r3_1549 = arg0->GetNmbrOfSubLines();
        if (temp_r3_1549 == 0) {
            return 0;
        }
        ((KDUniformSpline *) &this->unk180)->Init(temp_r3_1549, 0U);
        var_r30_1562 = arg0->unkC->GetSubLine(arg0);
loop_12:
        if (var_r30_1562 != NULL) {
            var_r30_1562->AsVector3(0, &sp8);
            ((KDUniformSpline *) &this->unk180)->AddNode(sp8);
            var_r30_1562 = var_r30_1562->unkC->GetNextLine(var_r30_1562);
            goto loop_12;
        }
        return 1;
    }
    return 0;
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void FightElevator::SetDefaults() {
    s32 temp_r4_1603;

    this->unk198 = 0;
    temp_r4_1603 = this->unk198;
    this->unk19C = temp_r4_1603;
    this->unk1A0 = 1;
    this->unk194 = 0.0f;
    this->unk1A5 = 0;
    this->unk1AC = 0.0f;
    this->unk1A4 = 0;
    M2C_FIELD(this->__vptr, M2C_UNK (**)(s32, M2C_UNK), 0x3C)(temp_r4_1603, 0);
    this->unk1B4 = 0.0f;
}
#endif

void FightElevator::Init() {
    s32 var_ctr_1659;
    s32 var_r3_1652;
    void *temp_r4_1661;

    Platform::Init();
    this->unk198 = 0;
    this->unk19C = this->unk198;
    this->unk1A0 = 1;
    ((KDSoundFader *) &this->unk1BC)->Init(0.25f, 0.25f);
    ((KDSoundFader *) &this->unk1E4)->Init(0.25f, 0.25f);
    this->unk194 = 0.0f;
    var_r3_1652 = 0;
    this->unk1A5 = 0;
    this->unk1AC = 0.0f;
    this->unk1A8 = 0.05f;
    this->unk1B0 = 1;
    this->unk1B1 = 1;
    this->unk1B4 = 0.0f;
    var_ctr_1659 = 6;
    do {
        temp_r4_1661 = this + var_r3_1652;
        var_r3_1652 += 4;
        M2C_FIELD(temp_r4_1661, s32 *, 0x20C) = 0;
        M2C_FIELD(temp_r4_1661, s32 *, 0x29C) = 0;
        var_ctr_1659 -= 1;
    } while (var_ctr_1659 != 0);
    this->unk1B8 = 0;
    this->unk1A4 = 0;
    this->unk2B8 = 0;
}

#if 0 // DRAFT: illegal use of non-static member
void FightElevatorDescriptor::LoadDone() {
    PlatformDescriptor::LoadDone();
    this->unk130 = checked_cast<EnergyBeam *, MKProp>(((MKSceneManager *) gMK)->CreateProp("EnergyBeam"));
}
#endif

#if 0 // DRAFT: illegal use of non-static member
s32 FightElevatorDescriptor::LoadLine(MKIniLine *arg0) {
    s32 var_r31_1709;

    var_r31_1709 = 0;
    if ((PlatformDescriptor::LoadLine(arg0) != 0) || (KDSound_LoadLine(arg0, "startSound", &this->unk124) != 0) || (KDSound_LoadLine(arg0, "stopSound", &this->unk128) != 0) || (KDSound_LoadLine(arg0, "moveSound", &this->unk12C) != 0)) {
        var_r31_1709 = 1;
    }
    return var_r31_1709;
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void FightElevatorDescriptor::Init() {
    PlatformDescriptor::Init();
    this->unk124 = 0;
    this->unk128 = 0;
    this->unk12C = 0;
}
#endif

void FightElevator_cpp::__sinit() {
    f64 temp_f1_1800;
    f64 temp_f1_1808;
    f64 temp_f2_1791;
    f64 temp_f4_1789;
    f64 temp_f4_1797;
    f64 temp_f4_1805;
    f64 temp_f6_1784;
    f64 temp_f9_1786;

    temp_f6_1784 = __frsqrte(2014000.0);
    temp_f9_1786 = __frsqrte(380000.0);
    temp_f4_1789 = temp_f6_1784 * temp_f6_1784;
    temp_f2_1791 = temp_f9_1786 * temp_f9_1786;
    FIGHT_ELEVATOR_TO_BLOCKER_BLOCK_DISTANCE_SQ = 2.5e7f;
    FIGHT_ELEVATOR_HERO_DETACH_DIST_SQ = 2250000.0f;
    temp_f4_1797 = 0.5 * temp_f6_1784 * -((2014000.0 * temp_f4_1789) - 3.0);
    temp_f1_1800 = 0.5 * temp_f9_1786 * -((380000.0 * temp_f2_1791) - 3.0);
    temp_f4_1805 = 0.5 * temp_f4_1797 * -((2014000.0 * (temp_f4_1797 * temp_f4_1797)) - 3.0);
    temp_f1_1808 = 0.5 * temp_f1_1800 * -((380000.0 * (temp_f1_1800 * temp_f1_1800)) - 3.0);
    SPYRO_BOUNCE_Y_SPEED = (f32) (2014000.0 * (0.5 * temp_f4_1805 * -((2014000.0 * (temp_f4_1805 * temp_f4_1805)) - 3.0)));
    SPYRO_MIN_JUMP_Y_VELOCITY = (f32) (380000.0 * (0.5 * temp_f1_1808 * -((380000.0 * (temp_f1_1808 * temp_f1_1808)) - 3.0)));
}
