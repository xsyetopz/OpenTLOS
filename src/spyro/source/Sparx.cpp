#include "spyro/source/Sparx.h"
#include "common/Source/Frustum.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/Game.h"
#include "spyro/source/KDSpline.h"
#include "spyro/source/SparxFX.h"
#include "spyro/source/SparxPath.h"
#include "spyro/source/SpyroTools.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKView.h"
#include "common/Source/StdMath.h"
#include "spyro/source/PhrasePlayer.h"
#include "spyro/source/Tools.h"
#include <m2c_macros.h>

extern f32 *KDSpline_PositionMixer;
extern f32 SPYRO_BOUNCE_Y_SPEED;
extern f32 SPYRO_MIN_JUMP_Y_VELOCITY;
extern MKSceneManager *gMK;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern GameGlobals gb;
#if 0 // DRAFT: illegal use of incomplete struct/union/class '_struct_localOffset_0x10'
static struct _struct_localOffset_0x10 localOffset[0xF] = {
    { 0, 200.0f, 150.0f, 200.0f },
    { 1, 100.0f, 150.0f, 200.0f },
    { 2, 200.0f, 150.0f, 200.0f },
    { 3, 200.0f, 150.0f, -200.0f },
    { 4, -200.0f, 150.0f, 200.0f },
    { 5, -200.0f, 150.0f, -200.0f },
    { 7, -100.0f, 80.0f, 0.0f },
    { 8, 100.0f, 80.0f, 0.0f },
    { 9, 0.0f, 80.0f, 0.0f },
    { 0xA, 0.0f, 85.0f, 0.0f },
    { 0xB, 0.0f, -20.0f, 0.0f },
    { 0xC, -40.0f, -60.000004f, 0.0f },
    { 0xD, -40.0f, 20.0f, 0.0f },
    { 0xE, 40.0f, 20.0f, 0.0f },
    { 0xF, 40.0f, -60.000004f, 0.0f },
};
#endif
#if 0 // DRAFT: illegal use of incomplete struct/union/class
static KDStateMachine<Sparx>::State sparxStates;    /* unable to generate initializer: confusing struct layout */

void Sparx::StateAction_StrafeTargetUpdate() {
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f64 sp8;
    f32 temp_f1_69;
    f64 temp_f0_88;
    f64 temp_f1_82;
    void **temp_r30_49;
    void *temp_r31_59;
    void *temp_r3_81;

    ((SpyroTargetList *) (((u8 *) this->unk94) + 0xB90))->GetCurrentTarget();
    temp_r30_49 = M2C_ERROR(/* Read from unset register $r3 */);
    if ((temp_r30_49 != NULL) && (M2C_FIELD(*M2C_ERROR(/* Read from unset register $r3 */), u32 (**)(), 8)() != 0U)) {
        temp_r31_59 = checked_cast<SparxDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        temp_f1_69 = (2.0f * M2C_FIELD(*temp_r30_49, f32 (**)(void **), 0x3C)(temp_r30_49)) + 75.0f;
        sp20 = 0.0f;
        sp18 = 0.0f;
        sp1C = temp_f1_69;
        sp30 = (f64) sp20;
        sp28 = (f64) sp18;
        temp_r3_81 = M2C_FIELD(M2C_FIELD(*temp_r30_49, void *(**)(void **, f64, f32, f32), 8)(temp_r30_49, (f64) sp18, 75.0f, 2.0f), void **, 8);
        temp_f1_82 = M2C_FIELD(temp_r3_81, f64 *, 0x30);
        sp38 = temp_f1_82;
        sp40 = M2C_FIELD(temp_r3_81, f64 *, 0x38);
        temp_f0_88 = temp_f1_82 + sp28;
        sp8 = temp_f0_88;
        sp48 = temp_f0_88;
        sp10 = (f32) sp40 + (f32) sp30;
        sp50 = (f64) sp10;
        UpdateLerpToWorldPos(*((MKVector3 *) &sp48), M2C_FIELD(temp_r31_59, f32 *, 0x98), 0.1f);
    }
}
#endif

void Sparx::StateAction_StrafeTargetExit() {

}

void Sparx::StateAction_StrafeTargetEnter() {

}

s32 Sparx::SetPath(SparxPath *arg0) {
    if ((GetTaskMode() == 0) && (arg0 != NULL)) {
        this->unk1F4 = arg0;
        SetState(0xD, 1U);
        return 1;
    }
    if (arg0 == NULL) {
        this->unk1F4 = NULL;
        SetState(0, 1U);
    }
    return 0;
}

#if 0 // DRAFT: undefined identifier '__float_nan'
void Sparx::StateAction_FollowPathUpdate() {
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    MKVector3 sp40;
    f64 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    f32 spC;
    f32 sp8;
    SparxPath *temp_r30_342;
    SparxPath *temp_r4_309;
    f32 temp_f1_271;
    f32 var_f4_201;
    f64 temp_f1_176;
    f64 temp_f1_204;
    f64 temp_f1_210;
    f64 temp_f1_214;
    f64 temp_f1_280;
    f64 temp_f2_279;
    s32 temp_r3_233;
    s32 var_r0_243;
    void *temp_r3_175;
    void *temp_r3_278;

    if ((u8) this->unk1FD == 0) {
        temp_r3_175 = this->unk1F4->unk8;
        temp_f1_176 = M2C_FIELD(temp_r3_175, f64 *, 0x30);
        sp70 = temp_f1_176;
        sp78 = M2C_FIELD(temp_r3_175, f64 *, 0x38);
        sp20 = temp_f1_176 - this->unk208;
        sp80 = sp20;
        sp28 = (f32) sp78 - this->unk210;
        sp88 = (f64) sp28;
        var_f4_201 = ((f32) sp88 * (f32) sp88) + (((f32) sp80 * (f32) sp80) + ((*(f32 *) ((u8 *) &sp80 + 0x4)) * (*(f32 *) ((u8 *) &sp80 + 0x4))));
        if (var_f4_201 > 0.0f) {
            temp_f1_204 = __frsqrte(var_f4_201);
            temp_f1_210 = 0.5 * temp_f1_204 * -(((f64) var_f4_201 * (temp_f1_204 * temp_f1_204)) - 3.0);
            temp_f1_214 = 0.5 * temp_f1_210 * -(((f64) var_f4_201 * (temp_f1_210 * temp_f1_210)) - 3.0);
            var_f4_201 = (f32) ((f64) var_f4_201 * (0.5 * temp_f1_214 * -(((f64) var_f4_201 * (temp_f1_214 * temp_f1_214)) - 3.0)));
        } else if (var_f4_201 < M2C_BITWISE(f32, 0.0)) {
            var_f4_201 = __float_nan;
        } else {
            spC = var_f4_201;
            temp_r3_233 = M2C_BITWISE(s32, spC) & 0x7F800000;
            switch (temp_r3_233) {                  /* irregular */
            case 0x7F800000:
                if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                    var_r0_243 = 1;
                } else {
                    var_r0_243 = 2;
                }
                break;
            case 0x0:
                if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                    var_r0_243 = 5;
                } else {
                    var_r0_243 = 3;
                }
                break;
            default:
                var_r0_243 = 4;
                break;
            }
            if (var_r0_243 == 1) {
                var_f4_201 = __float_nan;
            }
        }
        this->unk200 += this->unk1F4->unkC0 / var_f4_201;
        temp_f1_271 = this->unk200;
        if (temp_f1_271 >= 1.0f) {
            temp_r3_278 = this->unk1F4->unk8;
            temp_f2_279 = M2C_FIELD(temp_r3_278, f64 *, 0x30);
            temp_f1_280 = M2C_FIELD(temp_r3_278, f64 *, 0x38);
            sp60 = temp_f2_279;
            this->unk2B0 = temp_f2_279;
            this->unk2B8 = temp_f1_280;
            this->unk1FD = 1;
            sp68 = temp_f1_280;
            this->unk200 = 0.0f;
            return;
        }
        sp40.operator*(temp_f1_271);
        sp10 = this->unk208 + M2C_BITWISE(f64, sp40);
        this->unk2B0 = sp10;
        sp18 = this->unk210 + sp40.unk8;
        sp50 = sp10;
        sp58 = (f64) sp18;
        this->unk2B8 = (f64) sp18;
        return;
    }
    temp_r4_309 = this->unk1F4;
    this->unk200 += temp_r4_309->unkC0 / temp_r4_309->unkB0->unk30.unk8;
    if (this->unk200 > 1.0f) {
        this->unk200 = 1.0f;
    }
    sp8 = 0.0f;
    ((KDUniformSpline *) &sp30)->GetMeasure(this->unk200, (Matrix *) &this->unk1F4->unkB0->unk30, KDSpline_PositionMixer);
    this->unk2B0 = sp30;
    this->unk2B8 = sp38;
    if (this->unk200 >= 1.0f) {
        temp_r30_342 = this->unk1F4;
        SetState(0, 1U);
        if (temp_r30_342 != NULL) {
            temp_r30_342->unkC4.Send(NULL);
        }
    }
}
#endif

void Sparx::StateAction_FollowPathExit() {
    this->unk1FC = 0;
    this->unk1F4 = NULL;
}

void Sparx::StateAction_FollowPathEnter() {
    f64 sp10;
    f64 sp8;
    f64 temp_f1_378;
    f64 temp_f2_377;
    void *temp_r5_376;

    temp_r5_376 = this->unk8;
    temp_f2_377 = M2C_FIELD(temp_r5_376, f64 *, 0x30);
    temp_f1_378 = M2C_FIELD(temp_r5_376, f64 *, 0x38);
    sp8 = temp_f2_377;
    this->unk208 = temp_f2_377;
    M2C_FIELD(this, f64 *, 0x210) = temp_f1_378;
    this->unk1FC = 1;
    this->unk1FD = 0;
    this->unk200 = 0.0f;
    sp10 = temp_f1_378;
    this->unk1F8 = 0.0f;
}

#if 0 // DRAFT: ')' expected
void Sparx::StateAction_LoadCatapultUpdate() {
    MKVector3 sp8;
    f32 temp_f31_404;
    void *temp_r5_402;

    temp_r5_402 = this->unk290;
    temp_f31_404 = M2C_FIELD(temp_r5_402, f32 *, 0x13C);
    MKModel_CalculateRefPointWorldPosition(M2C_FIELD(this->unk290, MKModel **, 4), (s32) Tools_GetMatchingRefPointIndex(M2C_FIELD(temp_r5_402, MKModel **, 4), "r_ammo"), &sp8);
    sp8.unk4 += 100.0f * -((1.6f * temp_f31_404) - 0.95f);
    UpdateLerpToWorldPos(sp8, M2C_FIELD(checked_cast<SparxDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x98), 0.1f);
}
#endif

void Sparx::StateAction_LoadCatapultExit() {
    this->unk290 = NULL;
}

void Sparx::StateAction_LoadCatapultEnter() {

}

void Sparx::StateAction_SpyroHintUpdate() {
    s32 sp3C;
    s32 sp38;
    s8 sp36;
    s8 sp35;
    s8 sp34;
    s32 sp30;
    s32 sp2C;
    s32 sp28;
    f64 sp20;
    f64 sp18;
    f64 sp10;
    f64 sp8;
    f64 temp_f0_520;
    f64 temp_f1_519;
    void *temp_r30_486;
    void *temp_r3_518;
    void *temp_r5_463;
    void *temp_r6_460;

    temp_r6_460 = checked_cast<SparxDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    temp_r5_463 = M2C_FIELD(this->unk1E8, void **, 8);
    sp18 = M2C_FIELD(temp_r5_463, f64 *, 0x30);
    sp20 = M2C_FIELD(temp_r5_463, f64 *, 0x38);
    if ((UpdateLerpToWorldPos(*((MKVector3 *) &sp18), M2C_FIELD(temp_r6_460, f32 *, 0x98), 0.1f) == 0) && ((u8) this->unk1F1 != 0) && (((Frustum *) (M2C_FIELD(&gb, s32 *, 0x3B8) + 0xB0))->IsVisible((Matrix *) this->unk8, M2C_FIELD(this->unk0, BoundingVolume **, 0x1C)) != 0)) {
        temp_r30_486 = this->unk1E8;
        sp3C = 0;
        sp2C = 0;
        sp28 = 0x18;
        sp30 = 0;
        sp34 = 0;
        sp35 = 0;
        sp38 = 0;
        sp36 = 0;
        sp3C = 0;
        M2C_FIELD(M2C_FIELD(temp_r30_486, void **, 0x44), M2C_UNK (**)(void *, s32 *, M2C_UNK), 0x2C)(temp_r30_486, &sp28, 0);
        if (temp_r30_486 == (void *) this->unk1E8) {
            ResetHint();
            SetState(0, 0U);
        }
    }
    if ((u8) this->unk1F2 != 0) {
        temp_r3_518 = M2C_FIELD(this->unk1E8, void **, 8);
        temp_f1_519 = M2C_FIELD(temp_r3_518, f64 *, 0x30);
        temp_f0_520 = M2C_FIELD(temp_r3_518, f64 *, 0x38);
        sp8 = temp_f1_519;
        this->unk2B0 = temp_f1_519;
        sp10 = temp_f0_520;
        this->unk2B8 = temp_f0_520;
    }
}

void Sparx::StateAction_SpyroHintExit() {

}

#if 0 // DRAFT: ')' expected
void Sparx::StateAction_SpyroHintEnter() {
    f64 sp10;
    f64 sp8;
    f64 temp_f0_590;
    f64 temp_f1_589;
    s32 temp_r0_558;
    void *temp_r3_588;

    if (((s32) this->unk4C != 2) && (PhrasePlayer_IsAnyEventPlaying() == 0) && (this->unk2AC <= 0.0f)) {
        temp_r0_558 = this->unk4C;
        switch (temp_r0_558) {                      /* irregular */
        case 0:
            this->unk2A8 = PhrasePlayer_PlayEvent("SparxSomethingOfInterest");
            break;
        case 1:
            this->unk2A8 = PhrasePlayer_PlayEvent("SparxDojoComeHere");
            break;
        }
        this->unk2AC = M2C_FIELD(checked_cast<SparxDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0xB4);
    }
    if ((u8) this->unk1F2 != 0) {
        temp_r3_588 = M2C_FIELD(this->unk1E8, void **, 8);
        temp_f1_589 = M2C_FIELD(temp_r3_588, f64 *, 0x30);
        temp_f0_590 = M2C_FIELD(temp_r3_588, f64 *, 0x38);
        sp8 = temp_f1_589;
        this->unk2B0 = temp_f1_589;
        sp10 = temp_f0_590;
        this->unk2B8 = temp_f0_590;
    }
}
#endif

#if 0 // DRAFT: ')' expected
void Sparx::StateAction_SpyroFallUpdate() {
    UpdateLerpToLocalOffset(M2C_FIELD(checked_cast<SparxDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x94));
}
#endif

void Sparx::StateAction_SpyroFallExit() {

}

#if 0 // DRAFT: undefined identifier 'unkC0'
void Sparx::StateAction_SpyroFallEnter() {
    this->unkC0 = (struct _struct_localOffset_0x10 (*)[]) localOffset;
}
#endif

#if 0 // DRAFT: ')' expected
void Sparx::StateAction_SpyroJumpUpdate() {
    UpdateLerpToLocalOffset(0.9f * M2C_FIELD(checked_cast<SparxDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x94));
}
#endif

void Sparx::StateAction_SpyroJumpExit() {

}

#if 0 // DRAFT: undefined identifier 'unkC0'
void Sparx::StateAction_SpyroJumpEnter() {
    struct _struct_localOffset_0x10 (*temp_r3_673)[];

    this->unkC0 = (struct _struct_localOffset_0x10 (*)[]) localOffset;
    temp_r3_673 = this->unkC0;
    temp_r3_673[0][0].unk4 = -temp_r3_673[0][0].unk4;
}
#endif

void Sparx::StateAction_SpyroDeadDieUpdate() {
    UpdateLerpToWorldPos(this->unk298, 0.2f, 0.1f);
}

void Sparx::StateAction_SpyroDeadDieExit() {

}

void Sparx::StateAction_SpyroDeadDieEnter() {
    M2C_FIELD(this, f64 *, 0x298) = (f64) this->unk2B0;
    M2C_FIELD(this, f64 *, 0x2A0) = (f64) this->unk2B8;
}

void Sparx::StateAction_SpyroSpeedwayUpdate() {

}

void Sparx::StateAction_SpyroSpeedwayExit() {

}

#if 0 // DRAFT: undefined identifier 'unkC0'
void Sparx::StateAction_SpyroSpeedwayEnter() {
    this->unkC0 = (struct _struct_localOffset_0x10 (*)[]) &localOffset[1];
}
#endif

#if 0 // DRAFT: ')' expected
void Sparx::StateAction_SpyroFuryUpdate() {
    this->unk28C += gUpdateTimeDelta;
    if (this->unk28C > M2C_FIELD(checked_cast<SparxDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x80)) {
        CalculateAttackPosition(1U);
        this->unk28C = 0.0f;
    }
    UpdateLerpToWorldPos(this->unk278, M2C_FIELD(checked_cast<SparxDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x98), 0.1f);
}
#endif

void Sparx::StateAction_SpyroFuryExit() {
    this->unk218 = 0;
}

#if 0 // DRAFT: ')' expected
void Sparx::StateAction_SpyroFuryEnter() {
    this->unk218 = 1;
    this->unk288 = 0.0f;
    this->unk28C = 0.0f;
    this->unk28C = 2.0f * M2C_FIELD(checked_cast<SparxDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x80);
}
#endif

#if 0 // DRAFT: ')' expected
void Sparx::StateAction_SpyroAirCombatUpdate() {
    this->unk28C += gUpdateTimeDelta;
    if (this->unk28C > M2C_FIELD(checked_cast<SparxDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x80)) {
        CalculateAttackPosition(0U);
        this->unk28C = 0.0f;
    }
    UpdateLerpToWorldPos(this->unk278, M2C_FIELD(checked_cast<SparxDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x98), 0.1f);
}
#endif

void Sparx::StateAction_SpyroAirCombatExit() {

}

#if 0 // DRAFT: ')' expected
void Sparx::StateAction_SpyroAirCombatEnter() {
    this->unk288 = 0.0f;
    this->unk28C = 0.0f;
    this->unk28C = 2.0f * M2C_FIELD(checked_cast<SparxDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x80);
}
#endif

#if 0 // DRAFT: ')' expected
void Sparx::StateAction_SpyroGroundCombatUpdate() {
    this->unk28C += gUpdateTimeDelta;
    if (this->unk28C > M2C_FIELD(checked_cast<SparxDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x80)) {
        CalculateAttackPosition(0U);
        this->unk28C = 0.0f;
    }
    UpdateLerpToWorldPos(this->unk278, M2C_FIELD(checked_cast<SparxDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x98), 0.1f);
}
#endif

void Sparx::StateAction_SpyroGroundCombatExit() {

}

#if 0 // DRAFT: ')' expected
void Sparx::StateAction_SpyroGroundCombatEnter() {
    this->unk288 = 0.0f;
    this->unk28C = 0.0f;
    this->unk28C = 2.0f * M2C_FIELD(checked_cast<SparxDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x80);
}
#endif

#if 0 // DRAFT: ')' expected
void Sparx::CalculateAttackPosition(bool arg0) {
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
    f64 sp48;
    f32 sp40;
    f64 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f2_1000;
    f32 temp_f3_965;
    void *temp_r3_1003;
    void *temp_r3_963;
    void *temp_r4_1017;

    if (arg0 != 0) {
        temp_r3_963 = M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 8);
        temp_f3_965 = 100.0f * (2.0f * M2C_FIELD(checked_cast<SparxDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x88));
        sp8 = -M2C_FIELD(temp_r3_963, f32 *, 0x20);
        spC = -M2C_FIELD(temp_r3_963, f32 *, 0x24);
        sp10 = -M2C_FIELD(temp_r3_963, f32 *, 0x28);
        sp78 = (f64) sp8;
        sp80 = (f64) sp10;
        sp38 = sp78 * (f64) temp_f3_965;
        sp88 = sp38;
        sp40 = (f32) sp80 * temp_f3_965;
        sp98 = sp38;
        sp90 = (f64) sp40;
        spA0 = (f64) sp40;
    } else {
        temp_f2_1000 = 100.0f * M2C_FIELD(checked_cast<SparxDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x88);
        temp_r3_1003 = M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 8) + 0x20;
        sp28 = M2C_FIELD(temp_r3_1003, f64 *, 0) * (f64) temp_f2_1000;
        sp68 = sp28;
        sp30 = M2C_FIELD(temp_r3_1003, f32 *, 8) * temp_f2_1000;
        sp98 = sp28;
        sp70 = (f64) sp30;
        spA0 = (f64) sp30;
    }
    temp_r4_1017 = this->unk94;
    M2C_FIELD(M2C_FIELD(temp_r4_1017, void **, 0x44), M2C_UNK (**)(f64 *, void *), 0x84)(&sp48, temp_r4_1017);
    sp18 = sp48 + sp98;
    M2C_FIELD(this, f64 *, 0x278) = sp18;
    sp20 = sp50 + (f32) spA0;
    sp58 = sp18;
    M2C_FIELD(this, f64 *, 0x280) = (f64) sp20;
    sp60 = (f64) sp20;
    this->unk278.unk4 += 100.0f * M2C_FIELD(checked_cast<SparxDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x84);
    if (MKCollision_RayCollide(*((MKVector3 *) &this->unk2B0), this->unk278, &this->unk220, (MKCollisionMode) 4, 0x04000000) != 0) {
        M2C_FIELD(this, f64 *, 0x278) = (f64) M2C_FIELD(this, f64 *, 0x220);
        M2C_FIELD(this, f64 *, 0x280) = (f64) M2C_FIELD(this, f64 *, 0x228);
    }
}
#endif

#if 0 // DRAFT: ')' expected
void Sparx::StateAction_SpyroChargeUpdate() {
    UpdateLerpToLocalOffset(0.5f * M2C_FIELD(checked_cast<SparxDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x94));
}
#endif

void Sparx::StateAction_SpyroChargeExit() {

}

#if 0 // DRAFT: undefined identifier 'unkC0'
void Sparx::StateAction_SpyroChargeEnter() {
    this->unkC0 = (struct _struct_localOffset_0x10 (*)[]) &localOffset[1];
}
#endif

#if 0 // DRAFT: ')' expected
void Sparx::StateAction_SpyroWalkRunUpdate() {
    UpdateLerpToLocalOffset(M2C_FIELD(checked_cast<SparxDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x94));
}
#endif

void Sparx::StateAction_SpyroWalkRunExit() {

}

#if 0 // DRAFT: undefined identifier 'unkC0'
void Sparx::StateAction_SpyroWalkRunEnter() {
    this->unkC0 = (struct _struct_localOffset_0x10 (*)[]) &localOffset[1];
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'Sparx' to
void Sparx::CalculateLongIdle2Spline() {
    f64 sp128;                                      /* compiler-managed */
    f64 sp120;                                      /* compiler-managed */
    f64 sp118;
    f64 sp110;
    MKVector3 sp100;
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
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f32 sp78;
    f32 sp74;
    f32 sp70;
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
    f32 sp18;
    f64 sp10;
    f32 sp8;
    Frustum *temp_r28_1165;
    f32 temp_f27_1203;
    f32 temp_f4_1336;
    f32 var_f4_1222;
    f32 var_f5_1288;
    f64 temp_f0_1352;
    f64 temp_f1_1227;
    f64 temp_f1_1233;
    f64 temp_f1_1237;
    f64 temp_f5_1332;
    s32 temp_r3_1256;
    s32 var_r0_1266;
    s32 var_r24_1169;
    s32 var_r24_1487;
    s32 var_r24_1501;
    s32 var_r26_1191;
    s32 var_r26_1488;
    s32 var_r27_1162;
    s32 var_r29_1160;
    u8 var_r0_1174;
    u8 var_r26_1443;
    void *temp_r30_1173;
    void *temp_r3_1398;
    void *temp_r8_1442;

    var_r29_1160 = 0;
    var_r27_1162 = this->unk1DC;
    temp_r28_1165 = MKView_GetWorldFrustum();
    var_r24_1169 = var_r27_1162 * 0x10;
loop_46:
    if (var_r27_1162 >= 0xA) {
        this->unk104.unk8 = 0.0f;
        this->unk104.unk4 = 0;
        this->unk104.AddNode(*((MKVector3 *) &this->unk2B0));
        var_r24_1487 = 0;
        var_r26_1488 = 0;
        do {
            this->unk104.AddNode(*(this + (var_r26_1488 + 0x118)));
            var_r24_1487 += 1;
            var_r26_1488 += 0x10;
        } while (var_r24_1487 < 0xA);
        this->unk104.AddNode(*((MKVector3 *) &this->unk2B0));
        var_r24_1501 = 0;
        do {
            this->unk104.Smooth();
            var_r24_1501 += 1;
        } while (var_r24_1501 < 3);
        this->unk1D8 = 0.0f;
        this->unk1E5 = 1;
        return;
    }
    temp_r30_1173 = this + var_r24_1169;
    var_r0_1174 = 1;
loop_44:
    if (var_r0_1174 == 0) {
        var_r27_1162 += 1;
        var_r24_1169 += 0x10;
        M2C_FIELD(temp_r30_1173, f64 *, 0x118) = (f64) this->unk1B8;
        M2C_FIELD(temp_r30_1173, f64 *, 0x120) = (f64) this->unk1C0;
        this->unk1E4 = 0;
        this->unk1E0 = 0;
        goto loop_46;
    }
    if ((s32) this->unk1E0 == 4) {
        this->unk1E4 = 0;
    }
    this->unk1E0 += 1;
    if (var_r29_1160 == 2) {
        this->unk1DC = var_r27_1162;
        return;
    }
    var_r26_1191 = 0;
loop_35:
    if ((u8) this->unk1E4 != 0) {
        if ((var_r27_1162 == 0) || (var_r27_1162 == 9)) {
            this->unk1C8 = this->unk2B0;
            this->unk1D0 = this->unk2B8;
        } else {
            this->unk1C8 = M2C_FIELD(temp_r30_1173, f64 *, 0x108);
            this->unk1D0 = M2C_FIELD(temp_r30_1173, f64 *, 0x110);
        }
        temp_r8_1442 = M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 8);
        var_r26_1443 = 1;
        sp80 = M2C_FIELD(temp_r8_1442, f64 *, 0x30);
        sp88 = M2C_FIELD(temp_r8_1442, f64 *, 0x38);
        if ((MKCollision_RayCollide(*((MKVector3 *) &sp80), *((MKVector3 *) &this->unk1B8), &this->unk220, (MKCollisionMode) 4, 0x04000000) == 0) && (MKCollision_RayCollide(*((MKVector3 *) &this->unk1B8), *((MKVector3 *) &this->unk1C8), &this->unk220, (MKCollisionMode) 7, 0x04000000) == 0)) {
            var_r26_1443 = 0;
        }
        var_r0_1174 = var_r26_1443;
        var_r29_1160 += 1;
        goto loop_44;
    }
    if (var_r26_1191 == 2) {
        this->unk1DC = var_r27_1162;
        return;
    }
    temp_f27_1203 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
    sp70 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
    sp74 = 0.0f;
    sp78 = temp_f27_1203;
    sp120 = (f64) sp70;
    sp128 = (f64) sp78;
    var_f4_1222 = ((f32) sp128 * (f32) sp128) + (((f32) sp120 * (f32) sp120) + ((*(f32 *) ((u8 *) &sp118 + 0xc)) * (*(f32 *) ((u8 *) &sp118 + 0xc))));
    if (var_f4_1222 > 0.000001f) {
        if (var_f4_1222 > 0.0f) {
            temp_f1_1227 = __frsqrte(var_f4_1222);
            temp_f1_1233 = 0.5 * temp_f1_1227 * -(((f64) var_f4_1222 * (temp_f1_1227 * temp_f1_1227)) - 3.0);
            temp_f1_1237 = 0.5 * temp_f1_1233 * -(((f64) var_f4_1222 * (temp_f1_1233 * temp_f1_1233)) - 3.0);
            var_f4_1222 = (f32) ((f64) var_f4_1222 * (0.5 * temp_f1_1237 * -(((f64) var_f4_1222 * (temp_f1_1237 * temp_f1_1237)) - 3.0)));
        } else if (var_f4_1222 < M2C_BITWISE(f32, 0.0)) {
            var_f4_1222 = __float_nan;
        } else {
            sp8 = var_f4_1222;
            temp_r3_1256 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r3_1256) {                 /* irregular */
            case 0x7F800000:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_1266 = 1;
                } else {
                    var_r0_1266 = 2;
                }
                break;
            case 0x0:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_1266 = 5;
                } else {
                    var_r0_1266 = 3;
                }
                break;
            default:
                var_r0_1266 = 4;
                break;
            }
            if (var_r0_1266 == 1) {
                var_f4_1222 = __float_nan;
            }
        }
        var_f5_1288 = 1.0f / var_f4_1222;
    } else {
        var_f5_1288 = 0.0f;
    }
    sp120 = (f32) sp120 * var_f5_1288;
    (*(f32 *) ((u8 *) &sp118 + 0xc)) *= var_f5_1288;
    sp128 = (f32) sp128 * var_f5_1288;
    sp100.operator*(MKRand_Float(&gViewSeed, 250.0f, 5250.0f));
    sp20 = this->unk2B0 + M2C_BITWISE(f64, sp100);
    sp40 = 0.0f;
    sp44 = 10000.0f;
    sp28 = M2C_FIELD(this, f32 *, 0x2B8) + sp100.unk8;
    sp48 = 0.0f;
    this->unk1B8 = sp20;
    this->unk1C0 = (f64) sp28;
    spC0 = (f64) sp40;
    sp110 = sp20;
    sp118 = (f64) sp28;
    spC8 = (f64) sp48;
    temp_f5_1332 = this->unk1B8;
    sp30 = temp_f5_1332 + spC0;
    temp_f4_1336 = (f32) M2C_FIELD(this, f64 *, 0x1C0);
    sp68 = 0.0f;
    sp60 = 0.0f;
    sp64 = -10000.0f;
    sp38 = temp_f4_1336 + (f32) spC8;
    spE0 = (f64) sp60;
    spD0 = sp30;
    spD8 = (f64) sp38;
    spE8 = (f64) sp68;
    temp_f0_1352 = temp_f5_1332 + spE0;
    sp50 = temp_f0_1352;
    spF0 = temp_f0_1352;
    sp58 = temp_f4_1336 + (f32) spE8;
    spF8 = (f64) sp58;
    if (MKCollision_RayCollide(*((MKVector3 *) &spF0), *((MKVector3 *) &spD0), &this->unk220, (MKCollisionMode) 7, 0x04000000) != 0) {
        MKVector(0.0f, MKRand_Float(&gViewSeed, 500.0f, 1500.0f), 0.0f);
        sp10 = M2C_FIELD(this, f64 *, 0x220) + spA0;
        this->unk1B8 = sp10;
        sp18 = this->unk220.unk8 + spA8;
        spB0 = sp10;
        spB8 = (f64) sp18;
        this->unk1C0 = (f64) sp18;
    } else {
        gb.GetSpyro();
        temp_r3_1398 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), void **, 8);
        sp90 = M2C_FIELD(temp_r3_1398, f64 *, 0x30);
        sp98 = M2C_FIELD(temp_r3_1398, f64 *, 0x38);
        M2C_FIELD(this, f32 *, 0x1BC) = (*(f32 *) ((u8 *) &sp90 + 0x4));
    }
    if (temp_r28_1165->IsVisible(*((MKVector3 *) &this->unk1B8), 1.0f) != 0) {
        this->unk1E4 = 1;
        this->unk1E0 = 0;
    }
    var_r26_1191 += 1;
    goto loop_35;
}
#endif

#if 0 // DRAFT: ')' expected
void Sparx::StateAction_SpyroLongIdle2Update() {
    KDUniformSpline sp10;
    f32 sp8;
    void *temp_r31_1560;

    this->unk1D8 += gUpdateTimeDelta * (1.0f / M2C_FIELD(checked_cast<SparxDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0xBC));
    if (this->unk1D8 >= 1.0f) {
        SetState(0, 0U);
        return;
    }
    temp_r31_1560 = checked_cast<SparxDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    sp8 = 0.0f;
    sp10.GetMeasure(this->unk1D8, (Matrix *) &this->unk104, KDSpline_PositionMixer);
    UpdateLerpToWorldPos(*((MKVector3 *) &sp10), M2C_FIELD(temp_r31_1560, f32 *, 0x98), 0.1f);
}
#endif

#if 0 // DRAFT: undefined identifier 'unkC0'
void Sparx::StateAction_SpyroLongIdle2Exit() {
    this->unkC0 = (struct _struct_localOffset_0x10 (*)[]) &localOffset[1];
}
#endif

void Sparx::StateAction_SpyroLongIdle2Enter() {

}

#if 0 // DRAFT: ')' expected
void Sparx::StateAction_SpyroLongIdle1Update() {
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f64 sp20;
    f64 sp18;
    f64 sp10;
    f64 sp8;
    f32 temp_f1_1727;
    s32 temp_r4_1734;
    void *temp_r3_1662;
    void *temp_r3_1676;
    void *temp_r3_1690;
    void *temp_r3_1706;
    void *temp_r3_1716;
    void *temp_r3_1733;

    UpdateLerpToLocalOffset(M2C_FIELD(checked_cast<SparxDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x94));
    this->unkEC += gUpdateTimeDelta * M2C_FIELD(checked_cast<SparxDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0xB0);
    if (((this->unkF4 == 1.0f) && (this->unkF0 >= (100.0f * M2C_FIELD(checked_cast<SparxDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0xAC)))) || ((this->unkF4 == -1.0f) && (this->unkF0 <= (100.0f * M2C_FIELD(checked_cast<SparxDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0xA8))))) {
        this->unkF4 = -this->unkF4;
    }
    this->unkF0 += 100.0f * this->unkF4 * gUpdateTimeDelta;
    if ((s32) this->unk100 == 0) {
        temp_r3_1662 = M2C_FIELD(this->unk94, void **, 8);
        sp48 = M2C_FIELD(temp_r3_1662, f64 *, 0x30);
        sp50 = M2C_FIELD(temp_r3_1662, f64 *, 0x38);
        this->unkD8 = (this->unkE8 * _table_sinf(this->unkEC)) + (f32) sp48;
    } else {
        temp_r3_1676 = M2C_FIELD(this->unk94, void **, 8);
        sp38 = M2C_FIELD(temp_r3_1676, f64 *, 0x30);
        sp40 = M2C_FIELD(temp_r3_1676, f64 *, 0x38);
        this->unkD8 = (this->unkE8 * -_table_sinf(this->unkEC)) + (f32) sp38;
    }
    temp_r3_1690 = M2C_FIELD(this->unk94, void **, 8);
    sp28 = M2C_FIELD(temp_r3_1690, f64 *, 0x30);
    sp30 = M2C_FIELD(temp_r3_1690, f64 *, 0x38);
    this->unkE0 = (this->unkE8 * _table_sinf(1.5707964f + this->unkEC)) + (f32) sp30;
    temp_r3_1706 = M2C_FIELD(this->unk94, void **, 8);
    sp18 = M2C_FIELD(temp_r3_1706, f64 *, 0x30);
    sp20 = M2C_FIELD(temp_r3_1706, f64 *, 0x38);
    this->unkB4 = this->unkD8 - (f32) sp18;
    temp_r3_1716 = M2C_FIELD(this->unk94, void **, 8);
    sp10 = M2C_FIELD(temp_r3_1716, f64 *, 0x38);
    sp8 = M2C_FIELD(temp_r3_1716, f64 *, 0x30);
    this->unkBC = this->unkE0 - (f32) sp10;
    this->unkB8 = this->unkF0;
    this->unkC0 = (struct _struct_localOffset_0x10 (*)[]) this->unkB0;
    temp_f1_1727 = this->unkEC;
    if (temp_f1_1727 > 6.2831855f) {
        this->unkEC = temp_f1_1727 - 6.2831855f;
        temp_r3_1733 = checked_cast<SparxDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        temp_r4_1734 = this->unkFC;
        this->unkFC = temp_r4_1734 + 1;
        if (temp_r4_1734 > (s32) M2C_FIELD(temp_r3_1733, s32 *, 0xA4)) {
            SetState(0, 0U);
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unkC0'
void Sparx::StateAction_SpyroLongIdle1Exit() {
    this->unkC0 = (struct _struct_localOffset_0x10 (*)[]) &localOffset[1];
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to
void Sparx::StateAction_SpyroLongIdle1Enter() {
    f64 sp40;
    f64 sp38;
    f64 sp28;
    MKVector3 sp18;
    f32 sp10;
    f64 sp8;
    void *temp_r4_1777;

    sp18.operator*(200.0f);
    temp_r4_1777 = this->unk94;
    M2C_FIELD(M2C_FIELD(temp_r4_1777, void **, 0x44), M2C_UNK (**)(f64 *, void *), 0x84)(&sp28, temp_r4_1777);
    sp8 = sp28 + M2C_BITWISE(f64, sp18);
    M2C_FIELD(this, f64 *, 0xD8) = sp8;
    sp10 = sp30 + sp18.unk8;
    sp38 = sp8;
    M2C_FIELD(this, f64 *, 0xE0) = (f64) sp10;
    this->unkE8 = 1000.0f;
    this->unkEC = 0.0f;
    this->unkF0 = 0.0f;
    this->unkF4 = 1.0f;
    sp40 = (f64) sp10;
    this->unkFC = 0;
    this->unk100 = MKRand_Int(&gViewSeed, 0, 2);
}
#endif

#if 0 // DRAFT: ')' expected
void Sparx::StateAction_SpyroIdleUpdate() {
    s32 temp_r4_1873;
    s32 var_r3_1860;

    if ((u8) this->unk1E5 == 0) {
        CalculateLongIdle2Spline();
    }
    UpdateLerpToLocalOffset(M2C_FIELD(checked_cast<SparxDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x94));
    this->unkC8 += gUpdateTimeDelta;
    this->unkCC += gUpdateTimeDelta;
    if (this->unkCC > M2C_FIELD(checked_cast<SparxDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x9C)) {
        this->unkCC = 0.0f;
        if ((u8) this->unkD4 == 1) {
            var_r3_1860 = MKRand_Int(&gViewSeed, 1, 3);
loop_6:
            if (var_r3_1860 == (s32) this->unkF8) {
                var_r3_1860 = MKRand_Int(&gViewSeed, 1, 3);
                goto loop_6;
            }
            this->unkF8 = var_r3_1860;
        }
        temp_r4_1873 = this->unkF8;
        if (temp_r4_1873 == 2) {
            if ((u8) this->unk1E5 == 0) {
                GetNextLocalIdlePos();
                this->unkC0 = (struct _struct_localOffset_0x10 (*)[]) &localOffset[M2C_ERROR(/* Read from unset register $r3 */)];
                this->unkD4 = 0;
                this->unkC8 = 0.0f;
                return;
            }
            SetState(2, 0U);
            this->unk1E5 = 0;
            this->unkD4 = 1;
            return;
        }
        SetState(temp_r4_1873, 0U);
        this->unkD4 = 1;
        return;
    }
    if (this->unkC8 > M2C_FIELD(checked_cast<SparxDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0xA0)) {
        this->unkC8 = 0.0f;
        GetNextLocalIdlePos();
        this->unkC0 = (struct _struct_localOffset_0x10 (*)[]) &localOffset[M2C_ERROR(/* Read from unset register $r3 */)];
    }
}
#endif

void Sparx::StateAction_SpyroIdleExit() {

}

#if 0 // DRAFT: undefined identifier 'unkC0'
void Sparx::StateAction_SpyroIdleEnter() {
    struct _struct_localOffset_0x10 (*temp_r4_1949)[];

    this->unkC0 = (struct _struct_localOffset_0x10 (*)[]) &localOffset[1];
    temp_r4_1949 = this->unkC0;
    temp_r4_1949[0][0].unk4 = -temp_r4_1949[0][0].unk4;
    this->unkC8 = 0.0f;
    this->unkCC = 0.0f;
    ResetLongIdle2();
}
#endif

void Sparx::ResetLongIdle2() {
    this->unk1DC = 0;
    this->unk1E4 = 0;
    this->unk1E0 = 0;
    this->unkD4 = 1;
    this->unk1E5 = 0;
}

#if 0 // DRAFT: function call 'MKRand_Int(long *, int, int)' does not match
void Sparx::GetNextLocalIdlePos() {
    s32 var_r3_1986;

    var_r3_1986 = MKRand_Int(&gViewSeed, 2, 6);
loop_2:
    if (var_r3_1986 == (s32) this->unkD0) {
        var_r3_1986 = MKRand_Int(&gViewSeed, 1, 3);
        goto loop_2;
    }
    this->unkD0 = var_r3_1986;
}
#endif

void Sparx::Disable() {
    SparxFX *temp_r3_2014;

    this->unk18 |= 0x80000000;
    temp_r3_2014 = this->unk98;
    temp_r3_2014->Disable();
}

void Sparx::Enable() {
    SparxFX *temp_r3_2034;

    this->unk18 &= 0x7FFFFFFF;
    temp_r3_2034 = this->unk98;
    temp_r3_2034->Enable();
}

u8 Sparx::UpdateLerpToWorldPos(const MKVector3 &arg0, float arg1, float arg2) {
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    f64 temp_f0_2053;

    temp_f0_2053 = M2C_FIELD(&arg0, f64 *, 0) - this->unk2B0;
    sp18 = temp_f0_2053;
    sp38 = temp_f0_2053;
    sp20 = arg0.unk8 - M2C_FIELD(this, f32 *, 0x2B8);
    sp40 = (f64) sp20;
    if ((((f32) sp40 * (f32) sp40) + (((f32) sp38 * (f32) sp38) + ((*(f32 *) ((u8 *) &sp38 + 0x4)) * (*(f32 *) ((u8 *) &sp38 + 0x4))))) < arg2) {
        return 0U;
    }
    sp8 = sp38 * (f64) arg1;
    sp10 = (f32) sp40 * arg1;
    this->unk2C0 = sp8;
    this->unk2C8 = (f64) sp10;
    sp28 = sp8;
    sp30 = (f64) sp10;
    return 1U;
}

#if 0 // DRAFT: ')' expected
void Sparx::UpdateLerpToLocalOffset(float arg0) {
    f64 sp128;
    f64 sp120;
    f64 sp118;
    f64 sp110;
    f64 sp108;                                      /* compiler-managed */
    f64 sp100;                                      /* compiler-managed */
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
    f32 sp98;
    f32 sp94;
    f32 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f32 sp68;
    f64 sp60;
    f32 sp58;
    f64 sp50;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp38;
    f64 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    f32 sp8;
    f32 var_f4_2221;
    f32 var_f4_2288;
    f64 temp_f0_2331;
    f64 temp_f1_2227;
    f64 temp_f1_2233;
    f64 temp_f1_2237;
    s32 temp_r3_2256;
    s32 var_r0_2266;
    struct _struct_localOffset_0x10 (*temp_r4_2109)[];
    void *temp_r3_2114;

    if (this->unk288 > M2C_FIELD(checked_cast<SparxDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x90)) {
        temp_r4_2109 = this->unkC0;
        sp90 = temp_r4_2109[0][0].unk4;
        temp_r3_2114 = M2C_FIELD(this->unk94, void **, 8);
        sp94 = temp_r4_2109[0][0].unk8;
        sp98 = temp_r4_2109[0][0].unkC;
        sp110 = (f64) sp90;
        sp118 = (f64) sp98;
        sp40 = M2C_FIELD(temp_r3_2114, f32 *, 0x30) + (((f32) sp118 * M2C_FIELD(temp_r3_2114, f32 *, 0x20)) + (((f32) sp110 * M2C_FIELD(temp_r3_2114, f32 *, 0)) + ((*(f32 *) ((u8 *) &sp110 + 0x4)) * M2C_FIELD(temp_r3_2114, f32 *, 0x10))));
        sp44 = M2C_FIELD(temp_r3_2114, f32 *, 0x34) + (((f32) sp118 * M2C_FIELD(temp_r3_2114, f32 *, 0x24)) + (((f32) sp110 * M2C_FIELD(temp_r3_2114, f32 *, 4)) + ((*(f32 *) ((u8 *) &sp110 + 0x4)) * M2C_FIELD(temp_r3_2114, f32 *, 0x14))));
        sp48 = M2C_FIELD(temp_r3_2114, f32 *, 0x38) + (((f32) sp118 * M2C_FIELD(temp_r3_2114, f32 *, 0x28)) + (((f32) sp110 * M2C_FIELD(temp_r3_2114, f32 *, 8)) + ((*(f32 *) ((u8 *) &sp110 + 0x4)) * M2C_FIELD(temp_r3_2114, f32 *, 0x18))));
        sp120 = (f64) sp40;
        sp128 = (f64) sp48;
        spE0 = (f64) sp40;
        spE8 = (f64) sp48;
        if (this->unkC4 > 3.0f) {
            spD0 = (f64) M2C_FIELD(temp_r3_2114, f32 *, 0x30);
            spD8 = (f64) M2C_FIELD(temp_r3_2114, f32 *, 0x38);
            sp10 = this->unk2B0 - spD0;
            sp70 = sp10;
            sp18 = M2C_FIELD(this, f32 *, 0x2B8) - (f32) spD8;
            sp80 = sp10;
            sp78 = (f64) sp18;
            sp88 = (f64) sp18;
            if (((((f32) sp78 * (f32) sp78) + (((f32) sp70 * (f32) sp70) + ((*(f32 *) ((u8 *) &sp70 + 0x4)) * (*(f32 *) ((u8 *) &sp70 + 0x4))))) < 2250000.0f) && (MKCollision_RayCollide(*((MKVector3 *) &this->unk2B0), *((MKVector3 *) &sp120), &this->unk220, (MKCollisionMode) 7, 0x04000000) != 0)) {
                sp60 = M2C_FIELD(this, f64 *, 0x220) - this->unk2B0;
                sp100 = sp60;
                sp68 = this->unk220.unk8 - M2C_FIELD(this, f32 *, 0x2B8);
                sp108 = (f64) sp68;
                var_f4_2221 = ((f32) sp108 * (f32) sp108) + (((f32) sp100 * (f32) sp100) + ((*(f32 *) ((u8 *) &spF8 + 0xc)) * (*(f32 *) ((u8 *) &spF8 + 0xc))));
                if (var_f4_2221 > 0.000001f) {
                    if (var_f4_2221 > 0.0f) {
                        temp_f1_2227 = __frsqrte(var_f4_2221);
                        temp_f1_2233 = 0.5 * temp_f1_2227 * -(((f64) var_f4_2221 * (temp_f1_2227 * temp_f1_2227)) - 3.0);
                        temp_f1_2237 = 0.5 * temp_f1_2233 * -(((f64) var_f4_2221 * (temp_f1_2233 * temp_f1_2233)) - 3.0);
                        var_f4_2221 = (f32) ((f64) var_f4_2221 * (0.5 * temp_f1_2237 * -(((f64) var_f4_2221 * (temp_f1_2237 * temp_f1_2237)) - 3.0)));
                    } else if (var_f4_2221 < M2C_BITWISE(f32, 0.0)) {
                        var_f4_2221 = __float_nan;
                    } else {
                        sp8 = var_f4_2221;
                        temp_r3_2256 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                        switch (temp_r3_2256) {     /* irregular */
                        case 0x7F800000:
                            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                var_r0_2266 = 1;
                            } else {
                                var_r0_2266 = 2;
                            }
                            break;
                        case 0x0:
                            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                var_r0_2266 = 5;
                            } else {
                                var_r0_2266 = 3;
                            }
                            break;
                        default:
                            var_r0_2266 = 4;
                            break;
                        }
                        if (var_r0_2266 == 1) {
                            var_f4_2221 = __float_nan;
                        }
                    }
                    var_f4_2288 = 1.0f / var_f4_2221;
                } else {
                    var_f4_2288 = 0.0f;
                }
                sp100 = (f32) sp100 * var_f4_2288;
                (*(f32 *) ((u8 *) &spF8 + 0xc)) *= var_f4_2288;
                sp108 = (f32) sp108 * var_f4_2288;
                spB0.operator*(50.0f);
                sp30 = M2C_FIELD(this, f64 *, 0x220) - M2C_BITWISE(f64, spB0);
                spC0 = sp30;
                sp38 = this->unk220.unk8 - spB0.unk8;
                sp120 = sp30;
                spC8 = (f64) sp38;
                sp128 = (f64) sp38;
            }
        }
    } else {
        sp120 = this->unk2B0;
        sp128 = this->unk2B8;
    }
    temp_f0_2331 = sp120 - this->unk2B0;
    sp50 = temp_f0_2331;
    spF0 = temp_f0_2331;
    sp58 = (f32) sp128 - M2C_FIELD(this, f32 *, 0x2B8);
    spF8 = (f64) sp58;
    sp20 = temp_f0_2331 * (f64) arg0;
    this->unk2C0 = sp20;
    sp28 = (f32) spF8 * arg0;
    spA0 = sp20;
    spA8 = (f64) sp28;
    this->unk2C8 = (f64) sp28;
}
#endif

void Sparx::Draw() {
    if ((u8) gb.unk35E != 0) {
        MKProp::Draw();
    }
}

#if 0 // DRAFT: undefined identifier '__float_nan'
void Sparx::Update() {
    MKCollisionResult sp130;
    f64 sp128;
    f64 sp120;
    f64 sp118;
    f64 sp110;
    f64 sp108;
    f64 sp100;
    f64 spF8;
    f64 spF0;
    MKVector4 spE0;
    f64 spD8;
    f64 spD0;
    MKVector4 spC0;
    f64 spB8;
    f64 spB0;
    f64 spA8;
    f64 spA0;
    MKVector4 sp90;
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
    f64 sp40;
    f32 sp38;
    f64 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 sp8;
    SparxFX *temp_r3_2631;
    SparxFX *temp_r3_2653;
    SparxFX *temp_r6_2638;
    SparxFX *temp_r7_2619;
    f32 *temp_r30_2553;
    f32 temp_f1_2418;
    f32 temp_f2_2394;
    f32 temp_f2_2417;
    f32 temp_f30_2538;
    f32 temp_f3_2419;
    f32 var_f0_2399;
    f32 var_f2_2492;
    f32 var_f31_2491;
    f32 var_f4_2424;
    f64 temp_f0_2513;
    f64 temp_f0_2579;
    f64 temp_f1_2430;
    f64 temp_f1_2436;
    f64 temp_f1_2440;
    s32 temp_r3_2459;
    s32 var_r0_2469;

    MKProp::Update();
    temp_f2_2394 = this->unk2AC;
    if (temp_f2_2394 != 0.0f) {
        var_f0_2399 = temp_f2_2394 - gUpdateTimeDelta;
        if (var_f0_2399 > 0.0f) {

        } else {
            var_f0_2399 = 0.0f;
        }
        this->unk2AC = var_f0_2399;
    }
    this->unk288 += gUpdateTimeDelta;
    this->unkC4 += gUpdateTimeDelta;
    temp_f2_2417 = M2C_FIELD(this, f32 *, 0x2C0);
    temp_f1_2418 = M2C_FIELD(this, f32 *, 0x2C4);
    temp_f3_2419 = M2C_FIELD(this, f32 *, 0x2C8);
    var_f4_2424 = (temp_f3_2419 * temp_f3_2419) + ((temp_f2_2417 * temp_f2_2417) + (temp_f1_2418 * temp_f1_2418));
    if (var_f4_2424 > 0.000001f) {
        if (var_f4_2424 > 0.0f) {
            temp_f1_2430 = __frsqrte(var_f4_2424);
            temp_f1_2436 = 0.5 * temp_f1_2430 * -(((f64) var_f4_2424 * (temp_f1_2430 * temp_f1_2430)) - 3.0);
            temp_f1_2440 = 0.5 * temp_f1_2436 * -(((f64) var_f4_2424 * (temp_f1_2436 * temp_f1_2436)) - 3.0);
            var_f4_2424 = (f32) ((f64) var_f4_2424 * (0.5 * temp_f1_2440 * -(((f64) var_f4_2424 * (temp_f1_2440 * temp_f1_2440)) - 3.0)));
        } else if (var_f4_2424 < M2C_BITWISE(f32, 0.0)) {
            var_f4_2424 = __float_nan;
        } else {
            sp8 = var_f4_2424;
            temp_r3_2459 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r3_2459) {                 /* irregular */
            case 0x7F800000:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_2469 = 1;
                } else {
                    var_r0_2469 = 2;
                }
                break;
            case 0x0:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_2469 = 5;
                } else {
                    var_r0_2469 = 3;
                }
                break;
            default:
                var_r0_2469 = 4;
                break;
            }
            if (var_r0_2469 == 1) {
                var_f4_2424 = __float_nan;
            }
        }
        var_f31_2491 = var_f4_2424;
        var_f2_2492 = 1.0f / var_f4_2424;
    } else {
        var_f2_2492 = 0.0f;
        var_f31_2491 = 0.0f;
    }
    M2C_FIELD(this, f32 *, 0x2C0) = (f32) (M2C_FIELD(this, f32 *, 0x2C0) * var_f2_2492);
    M2C_FIELD(this, f32 *, 0x2C4) = (f32) (M2C_FIELD(this, f32 *, 0x2C4) * var_f2_2492);
    M2C_FIELD(this, f32 *, 0x2C8) = (f32) (M2C_FIELD(this, f32 *, 0x2C8) * var_f2_2492);
    if (var_f31_2491 > 0.0f) {
        temp_f0_2513 = this->unk2C0 * (f64) var_f31_2491;
        sp40 = temp_f0_2513;
        sp120 = temp_f0_2513;
        sp48 = M2C_FIELD(this, f32 *, 0x2C8) * var_f31_2491;
        sp128 = (f64) sp48;
        this->unk2B0 += temp_f0_2513;
        M2C_FIELD(this, f32 *, 0x2B8) = (f32) (M2C_FIELD(this, f32 *, 0x2B8) + (f32) sp128);
        temp_f30_2538 = -((gUpdateTimeDelta * (100.0f * M2C_FIELD(checked_cast<SparxDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x8C))) - var_f31_2491);
        sp30 = this->unk2C0 * (f64) temp_f30_2538;
        this->unk2C0 = sp30;
        sp38 = M2C_FIELD(this, f32 *, 0x2C8) * temp_f30_2538;
        sp110 = sp30;
        sp118 = (f64) sp38;
        this->unk2C8 = (f64) sp38;
    }
    temp_r30_2553 = &this->unk50.unk30;
    this->unk50.unk30 = (f32) M2C_FIELD(this, f64 *, 0x2B0);
    this->unk50.unk34 = M2C_FIELD(this, f32 *, 0x2B4);
    this->unk50.unk38 = M2C_FIELD(this, f32 *, 0x2B8);
    this->unk50.unk3C = 1.0f;
    this->unk98->SetSparxPos(*((MKVector3 *) temp_r30_2553));
    this->unk9C.Update(this, 0);
    sp60 = 0.0f;
    sp64 = -3000.0f;
    sp68 = 0.0f;
    spF0 = (f64) sp60;
    spF8 = (f64) sp68;
    temp_f0_2579 = (f64) M2C_FIELD(this, f32 *, 0x80) + spF0;
    sp50 = temp_f0_2579;
    sp100 = temp_f0_2579;
    sp58 = this->unk50.unk38 + (f32) spF8;
    sp108 = (f64) sp58;
    if (MKCollision_RayCollide(*((MKVector3 *) temp_r30_2553), *((MKVector3 *) &sp100), &sp130, (MKCollisionMode) 4, 0x04000000) != 0) {
        sp10 = 1.0f;
        sp14 = 1.0f;
        sp18 = 1.0f;
        sp1C = 1.0f;
        sp20 = 0.5f;
        sp24 = 0.5f;
        sp28 = 0.5f;
        sp2C = 1.0f;
        spA0 = (f64) sp10;
        spA8 = (f64) sp18;
        spB0 = (f64) sp20;
        spB8 = (f64) sp28;
        temp_r7_2619 = this->unk98;
        spD0 = temp_r7_2619->unkD8;
        spD8 = temp_r7_2619->unkE0;
        Clamp<MKVector4>(spC0, *((MKVector4 *) &spB0), *((MKVector4 *) &sp130.unk20));
        KDMath_Smooth<MKVector4>(spE0, *((MKVector4 *) &spD0), 1.0f, gUpdateTimeDelta);
        temp_r3_2631 = this->unk98;
        temp_r3_2631->unkD8 = M2C_BITWISE(f64, spE0);
        temp_r3_2631->unkE0 = (f64) spE0.unk8;
        return;
    }
    temp_r6_2638 = this->unk98;
    sp70 = M2C_FIELD(temp_r6_2638, f64 *, 0x68);
    sp78 = M2C_FIELD(temp_r6_2638, f64 *, 0x70);
    sp80 = temp_r6_2638->unkD8;
    sp88 = temp_r6_2638->unkE0;
    KDMath_Smooth<MKVector4>(sp90, *((MKVector4 *) &sp80), 1.0f, gUpdateTimeDelta);
    temp_r3_2653 = this->unk98;
    temp_r3_2653->unkD8 = M2C_BITWISE(f64, sp90);
    temp_r3_2653->unkE0 = (f64) sp90.unk8;
}
#endif

void Sparx::Teleport() {
    this->unkC4 = 0.0f;
}

void Sparx::SetHint(SparxHintMsg *arg0) {
    s32 spEC;
    s32 spE8;
    s8 spE6;
    s8 spE5;
    s8 spE4;
    s32 spE0;
    s32 spDC;
    s32 spD8;
    Sparx *spD4;
    s32 spD0;
    s8 spCE;
    s8 spCD;
    s8 spCC;
    s32 spC8;
    s32 spC4;
    s32 spC0;
    s32 spBC;
    s32 spB8;
    s8 spB6;
    s8 spB5;
    s8 spB4;
    s32 spB0;
    s32 spAC;
    s32 spA8;
    Sparx *spA4;
    s32 spA0;
    s8 sp9E;
    s8 sp9D;
    s8 sp9C;
    s32 sp98;
    s32 sp94;
    s32 sp90;
    Sparx *sp8C;
    s32 sp88;
    s8 sp86;
    s8 sp85;
    s8 sp84;
    s32 sp80;
    s32 sp7C;
    s32 sp78;
    f64 sp70;
    f64 sp68;
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
    f64 sp8;
    f64 temp_f0_2965;
    f64 temp_f0_2983;
    s32 temp_r5_2906;
    s32 temp_r5_3023;
    s32 temp_r5_3055;
    u8 temp_r4_2873;
    void *temp_r3_2896;
    void *temp_r3_2917;
    void *temp_r3_2958;
    void *temp_r3_3013;
    void *temp_r3_3034;
    void *temp_r3_3066;
    void *temp_r4_2948;
    void *temp_r5_2863;
    void *temp_r5_2947;

    this->unk4C = arg0->unk10;
    this->unk1F2 = arg0->unkE;
    this->unk1F1 = arg0->unkC;
    temp_r5_2863 = arg0->unk14;
    if (temp_r5_2863 == NULL) {
        ResetHint();
        SetState(0, 0U);
        return;
    }
    temp_r4_2873 = this->unk1F0;
    if ((temp_r4_2873 == 1) && (((s32) arg0->unk8 > (s32) this->unk1EC) || ((u8) arg0->unkD != 0))) {
        spEC = 0;
        spDC = 0;
        spD8 = 0x18;
        spE0 = 0;
        spE4 = 0;
        spE5 = 0;
        spE8 = 0;
        spE6 = 0;
        spEC = 0;
        temp_r3_2896 = this->unk1E8;
        M2C_FIELD(M2C_FIELD(temp_r3_2896, void **, 0x44), M2C_UNK (**)(void *, s32 *), 0x2C)(temp_r3_2896, &spD8);
        this->unk1E8 = arg0->unk14;
        temp_r5_2906 = arg0->unk8;
        this->unk1EC = temp_r5_2906;
        spD4 = NULL;
        spC4 = 0;
        spC0 = 0x18;
        spC8 = 0;
        spCC = 0;
        spCD = 0;
        spD0 = 0;
        spCE = 0;
        spD4 = this;
        temp_r3_2917 = this->unk1E8;
        M2C_FIELD(M2C_FIELD(temp_r3_2917, void **, 0x44), M2C_UNK (**)(void *, s32 *, s32), 0x2C)(temp_r3_2917, &spC0, temp_r5_2906);
        SetState(0xB, 1U);
        return;
    }
    switch (temp_r4_2873) {                         /* irregular */
    case 1:
        if (((s32) arg0->unk8 == (s32) this->unk1EC) && ((void *) this->unk1E8 != temp_r5_2863) && (gb.GetSpyro(), (((u32) M2C_ERROR(/* Read from unset register $r3 */) == 0U) == 0))) {
            temp_r5_2947 = M2C_FIELD(this->unk1E8, void **, 8);
            temp_r4_2948 = M2C_FIELD(arg0->unk14, void **, 8);
            sp68 = M2C_FIELD(temp_r5_2947, f64 *, 0x30);
            sp70 = M2C_FIELD(temp_r5_2947, f64 *, 0x38);
            sp58 = M2C_FIELD(temp_r4_2948, f64 *, 0x30);
            sp60 = M2C_FIELD(temp_r4_2948, f64 *, 0x38);
            gb.GetSpyro();
            temp_r3_2958 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), void **, 8);
            sp48 = M2C_FIELD(temp_r3_2958, f64 *, 0x30);
            sp50 = M2C_FIELD(temp_r3_2958, f64 *, 0x38);
            temp_f0_2965 = sp48 - sp68;
            sp8 = temp_f0_2965;
            sp28 = temp_f0_2965;
            sp10 = (f32) sp50 - (f32) sp70;
            sp30 = (f64) sp10;
            temp_f0_2983 = sp48 - sp58;
            sp18 = temp_f0_2983;
            sp38 = temp_f0_2983;
            sp20 = (f32) sp50 - (f32) sp60;
            sp40 = (f64) sp20;
            if ((((f32) sp40 * (f32) sp40) + (((f32) sp38 * (f32) sp38) + ((*(f32 *) ((u8 *) &sp38 + 0x4)) * (*(f32 *) ((u8 *) &sp38 + 0x4))))) < (((f32) sp30 * (f32) sp30) + (((f32) sp28 * (f32) sp28) + ((*(f32 *) ((u8 *) &sp28 + 0x4)) * (*(f32 *) ((u8 *) &sp28 + 0x4)))))) {
                spBC = 0;
                spAC = 0;
                spA8 = 0x18;
                spB0 = 0;
                spB4 = 0;
                spB5 = 0;
                spB8 = 0;
                spB6 = 0;
                spBC = 0;
                temp_r3_3013 = this->unk1E8;
                M2C_FIELD(M2C_FIELD(temp_r3_3013, void **, 0x44), M2C_UNK (**)(void *, s32 *), 0x2C)(temp_r3_3013, &spA8);
                this->unk1E8 = arg0->unk14;
                temp_r5_3023 = arg0->unk8;
                this->unk1EC = temp_r5_3023;
                spA4 = NULL;
                sp94 = 0;
                sp90 = 0x18;
                sp98 = 0;
                sp9C = 0;
                sp9D = 0;
                spA0 = 0;
                sp9E = 0;
                spA4 = this;
                temp_r3_3034 = this->unk1E8;
                M2C_FIELD(M2C_FIELD(temp_r3_3034, void **, 0x44), M2C_UNK (**)(void *, s32 *, s32), 0x2C)(temp_r3_3034, &sp90, temp_r5_3023);
                SetState(0xB, 1U);
                return;
            }
        } else {
            if ((u8) this->unk1F0 == 0) {
            case 0:
                this->unk1F0 = 1;
                this->unk1E8 = arg0->unk14;
                temp_r5_3055 = arg0->unk8;
                this->unk1EC = temp_r5_3055;
                sp8C = NULL;
                sp7C = 0;
                sp78 = 0x18;
                sp80 = 0;
                sp84 = 0;
                sp85 = 0;
                sp88 = 0;
                sp86 = 0;
                sp8C = this;
                temp_r3_3066 = this->unk1E8;
                M2C_FIELD(M2C_FIELD(temp_r3_3066, void **, 0x44), M2C_UNK (**)(void *, s32 *, s32), 0x2C)(temp_r3_3066, &sp78, temp_r5_3055);
                SetState(0xB, 1U);
            }
            return;
        }
        break;
    }
}

void Sparx::ResetHint() {
    this->unk1E8 = NULL;
    this->unk1EC = -1;
    this->unk1F0 = 0;
}

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'HeroInterface'
void Sparx::Message(MKMessage *arg0) {
    s32 temp_r0_3103;
    void *temp_r0_3154;

    temp_r0_3103 = arg0->unk0;
    switch (temp_r0_3103) {                         /* irregular */
    case 0xA:
        gb.unk0->Message();
    default:
block_19:
        MKProp::Message(arg0);
        break;
    case 0x17:
        if (GetTaskMode() == 0) {
            SetState(M2C_FIELD(checked_cast<LeaderStateMsg *, MKMessage>(arg0), s32 *, 8), 0U);
        }
        goto block_19;
    case 0x18:
        SetHint(checked_cast<P12SparxHintMsg, 9MKMessage>__FP9MKMessage(arg0));
        goto block_19;
    case 0x19:
        if ((u8) this->unk1F0 != 1) {
            temp_r0_3154 = M2C_FIELD(checked_cast<SparxCatapultMsg *, MKMessage>(arg0), void **, 8);
            if (temp_r0_3154 != NULL) {
                this->unk290 = temp_r0_3154;
                SetState(0xC, 0U);
            } else {
                SetState(0, 0U);
            }
            goto block_19;
        }
        break;
    case 0xA0:
        this->unk98->SetColor(*(checked_cast<P16SetSparxColorMsg), 9MKMessage>__FP9MKMessage(arg0) + 8);
        goto block_19;
    }
}
#endif

void Sparx::SetState(int arg0, bool arg1) {
    this->unk9C.SetState(this, arg0, arg1);
}

u8 Sparx::GetTaskMode() {
    u8 var_r4_3210;
    u8 var_r5_3211;

    var_r4_3210 = 1;
    var_r5_3211 = 1;
    if (((void *) this->unk290 == NULL) && ((u8) this->unk1F0 == 0)) {
        var_r5_3211 = 0;
    }
    if ((var_r5_3211 == 0) && ((s32) this->unk1FC == 0)) {
        var_r4_3210 = 0;
    }
    return var_r4_3210;
}

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'HeroInterface'
void Sparx::Spawn() {
    f64 sp60;
    f64 sp58;
    f64 sp48;
    MKVector3 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    void *temp_r4_3268;

    if (gb.unk0->IsDying(&gb) != 0) {
        RespawnOnSpyroDeath();
        return;
    }
    Reset();
    this->unk288 = 2.0f * M2C_FIELD(checked_cast<SparxDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x80);
    sp38.operator*(1000.0f);
    temp_r4_3268 = this->unk94;
    M2C_FIELD(M2C_FIELD(temp_r4_3268, void **, 0x44), M2C_UNK (**)(f64 *, void *), 0x84)(&sp48, temp_r4_3268);
    sp18 = sp48 + M2C_BITWISE(f64, sp38);
    sp10 = 0.0f;
    sp20 = sp50 + sp38.unk8;
    this->unk2B0 = sp18;
    sp8 = 0.0f;
    spC = 0.0f;
    this->unk2B8 = (f64) sp20;
    this->unk2C0 = (f64) sp8;
    this->unk2C8 = (f64) sp10;
    this->unk2D0 = 100.0f;
    sp58 = sp18;
    this->unk50.unk30 = (f32) M2C_FIELD(this, f64 *, 0x2B0);
    sp60 = (f64) sp20;
    this->unk50.unk34 = M2C_FIELD(this, f32 *, 0x2B4);
    sp28 = (f64) sp8;
    this->unk50.unk38 = (f32) M2C_FIELD(this, f64 *, 0x2B8);
    sp30 = (f64) sp10;
    this->unk50.unk3C = 1.0f;
    this->unkC0 = (struct _struct_localOffset_0x10 (*)[]) &localOffset[MKRand_Int(&gViewSeed, 2, 5)];
    SetState(0, 0U);
}
#endif

#if 0 // DRAFT: undefined identifier 'unkC0'
void Sparx::RespawnOnSpyroDeath() {
    f64 sp60;
    f64 sp58;
    f64 sp48;
    MKVector3 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    void *temp_r4_3404;

    MKProp::Reset();
    this->unkC0 = NULL;
    this->unkCC = 0.0f;
    this->unkC8 = 0.0f;
    this->unkF8 = MKRand_Int(&gViewSeed, 1, 3);
    this->unkD0 = MKRand_Int(&gViewSeed, 1, 3);
    this->unk1EC = -1;
    memset(&this->unk2B0, 0, 0x28U);
    this->unk220.unk0 = 0.0f;
    this->unk220.unk4 = 0.0f;
    this->unk220.unk8 = 0.0f;
    this->unk220.unk10 = 0.0f;
    this->unk220.unk14 = 0.0f;
    this->unk220.unk18 = 0.0f;
    this->unk220.unk20 = 0.0f;
    this->unk220.unk24 = 0.0f;
    this->unk220.unk28 = 0.0f;
    this->unk220.unk2C = 1.0f;
    this->unk220.unk30 = 0.0f;
    this->unk220.unk34 = 0.0f;
    M2C_FIELD(this, s16 *, 0x258) = 0;
    M2C_FIELD(this, s8 *, 0x25A) = 0;
    M2C_FIELD(this, s8 *, 0x25B) = 0;
    this->unk220.unk3C = 0;
    this->unk220.unk40 = 3.4028235e38f;
    this->unk220.unk44 = 0;
    this->unk220.unk48 = NULL;
    this->unk220.unk4C = -1;
    this->unk220.unk50 = 0;
    this->unk290 = NULL;
    if ((u8) this->unk1F0 == 0) {
        ResetHint();
        this->unk288 = 2.0f * M2C_FIELD(checked_cast<SparxDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x80);
        sp38.operator*(1000.0f);
        temp_r4_3404 = this->unk94;
        M2C_FIELD(M2C_FIELD(temp_r4_3404, void **, 0x44), M2C_UNK (**)(f64 *, void *), 0x84)(&sp48, temp_r4_3404);
        sp18 = sp48 + M2C_BITWISE(f64, sp38);
        sp10 = 0.0f;
        sp20 = sp50 + sp38.unk8;
        this->unk2B0 = sp18;
        sp8 = 0.0f;
        spC = 0.0f;
        this->unk2B8 = (f64) sp20;
        this->unk2C0 = (f64) sp8;
        this->unk2C8 = (f64) sp10;
        this->unk2D0 = 100.0f;
        sp58 = sp18;
        this->unk50.unk30 = (f32) M2C_FIELD(this, f64 *, 0x2B0);
        sp60 = (f64) sp20;
        this->unk50.unk34 = M2C_FIELD(this, f32 *, 0x2B4);
        sp28 = (f64) sp8;
        this->unk50.unk38 = (f32) M2C_FIELD(this, f64 *, 0x2B8);
        sp30 = (f64) sp10;
        this->unk50.unk3C = 1.0f;
        this->unkC0 = (struct _struct_localOffset_0x10 (*)[]) &localOffset[MKRand_Int(&gViewSeed, 2, 5)];
        SetState(0, 0U);
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unkC0'
void Sparx::Reset() {
    MKProp::Reset();
    this->unkC0 = NULL;
    this->unkCC = 0.0f;
    this->unkC8 = 0.0f;
    this->unkF8 = MKRand_Int(&gViewSeed, 1, 3);
    this->unkD0 = MKRand_Int(&gViewSeed, 1, 3);
    this->unk1E8 = NULL;
    this->unk1EC = -1;
    memset(&this->unk2B0, 0, 0x28U);
    this->unk220.unk0 = 0.0f;
    this->unk220.unk4 = 0.0f;
    this->unk220.unk8 = 0.0f;
    this->unk220.unk10 = 0.0f;
    this->unk220.unk14 = 0.0f;
    this->unk220.unk18 = 0.0f;
    this->unk220.unk20 = 0.0f;
    this->unk220.unk24 = 0.0f;
    this->unk220.unk28 = 0.0f;
    this->unk220.unk2C = 1.0f;
    this->unk220.unk30 = 0.0f;
    this->unk220.unk34 = 0.0f;
    M2C_FIELD(this, s16 *, 0x258) = 0;
    M2C_FIELD(this, s8 *, 0x25A) = 0;
    M2C_FIELD(this, s8 *, 0x25B) = 0;
    this->unk220.unk3C = 0;
    this->unk220.unk40 = 3.4028235e38f;
    this->unk220.unk44 = 0;
    this->unk220.unk48 = NULL;
    this->unk220.unk4C = -1;
    this->unk220.unk50 = 0;
    this->unk290 = NULL;
    ResetHint();
}
#endif

void Sparx::Resolve() {
    MKProp::Resolve();
    gb.GetSpyro();
    this->unk94 = M2C_ERROR(/* Read from unset register $r3 */);
    M2C_FIELD(this->unk94, Sparx **, 0xB70) = this;
    Spawn();
}

void Sparx::SetDefaults() {

}

void Sparx::LoadDone() {
    this->unk8 = &this->unk50;
    MKProp::LoadDone();
    M2C_STRUCT_COPY((s32) &this->unk4C + 4, (s32) (&MKProp::loadInfo - 4) + 4, 0x40);
    SetDefaults();
    this->unk2B0 = M2C_FIELD(&MKProp::loadInfo, f64 *, 0x40);
    this->unk2B8 = M2C_FIELD(&MKProp::loadInfo, f64 *, 0x48);
    this->unk50.unk30 = (f32) M2C_FIELD(this, f64 *, 0x2B0);
    this->unk50.unk34 = M2C_FIELD(this, f32 *, 0x2B4);
    this->unk50.unk38 = (f32) M2C_FIELD(this, f64 *, 0x2B8);
    this->unk50.unk3C = 1.0f;
    this->unk98->SetSparxPos(*((MKVector3 *) &this->unk2B0));
}

void Sparx::Deinit() {
    s32 temp_r3_3624;

    M2C_FIELD(this->unk94, s32 *, 0xB70) = 0;
    temp_r3_3624 = this->unk2A8;
    if (temp_r3_3624 != 0) {
        PhrasePlayer_StopEvent(temp_r3_3624);
    }
    this->unk104.Deinit();
    MKProp::Deinit();
}

#if 0 // DRAFT: undefined identifier 'Init__22KDStateMachine'
void Sparx::Init() {
    MKProp::Init();
    this->unk90 = checked_cast<SparxDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    Init__22KDStateMachine<5Sparx>FPQ222KDStateMachine<5Sparx>5StateP22KDStateMachine<5Sparx>(&this->unk9C, &sparxStates, NULL);
    memset(&this->unk2B0, 0, 0x28U);
    this->unk220.unk0 = 0.0f;
    this->unk220.unk4 = 0.0f;
    this->unk220.unk8 = 0.0f;
    this->unk220.unk10 = 0.0f;
    this->unk220.unk14 = 0.0f;
    this->unk220.unk18 = 0.0f;
    this->unk220.unk20 = 0.0f;
    this->unk220.unk24 = 0.0f;
    this->unk220.unk28 = 0.0f;
    this->unk220.unk2C = 1.0f;
    this->unk220.unk30 = 0.0f;
    this->unk220.unk34 = 0.0f;
    M2C_FIELD(this, s16 *, 0x258) = 0;
    M2C_FIELD(this, s8 *, 0x25A) = 0;
    M2C_FIELD(this, s8 *, 0x25B) = 0;
    this->unk220.unk3C = 0;
    this->unk220.unk40 = 3.4028235e38f;
    this->unk220.unk44 = 0;
    this->unk220.unk48 = NULL;
    this->unk220.unk4C = -1;
    this->unk220.unk50 = 0;
    this->unk104.Init(0xC, 0U);
    ResetHint();
    this->unkC0 = NULL;
    this->unkCC = 0.0f;
    this->unkC8 = 0.0f;
    this->unk2AC = 0.0f;
    this->unkC4 = 0.0f;
    this->unkF8 = MKRand_Int(&gViewSeed, 1, 3);
    this->unkD0 = MKRand_Int(&gViewSeed, 1, 3);
    this->unk1EC = -1;
    this->unk1E8 = NULL;
    this->unk98 = checked_cast<SparxFX *, MKProp>(gMK->CreateProp("SparxFX"));
    this->unk2A8 = 0;
    this->unk1FC = 0;
    this->unk94 = NULL;
    this->unk1F4 = NULL;
    this->unk290 = NULL;
    this->unk1F1 = 0;
    this->unk1F2 = 0;
    this->unk4C = 0;
    this->unk218 = 0;
}
#endif

void SparxDescriptor::LoadDone() {
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f64 sp8;

    MKPropDescriptor::LoadDone();
    sp18 = -1.0f;
    sp1C = -1.0f;
    sp20 = -1.0f;
    this->unk60 = (f64) sp18;
    this->unk68 = (f64) sp20;
    sp38 = (f64) sp18;
    sp40 = (f64) sp20;
    sp8 = this->unk60 * 1.591496843e-314;
    this->unk70 = sp8;
    sp10 = (f32) M2C_FIELD(this, f64 *, 0x68) * -2.0f;
    sp28 = sp8;
    this->unk78 = (f64) sp10;
    sp30 = (f64) sp10;
    this->unk1C = (BoundingVolume *) &this->unk60;
}

#if 0 // DRAFT: illegal implicit conversion from 'long *' to
s32 SparxDescriptor::LoadLine(MKIniLine *arg0) {
    s32 var_r31_3793;

    var_r31_3793 = 0;
    if ((MKPropDescriptor::LoadLine(arg0) != 0) || (arg0->LoadFloat("attackwoldyoffset", &this->unk84, 0) != 0) || (arg0->LoadFloat("attackworlddistance", &this->unk88, 0) != 0) || (arg0->LoadFloat("attacktimerdelay", &this->unk80, 0) != 0) || (arg0->LoadFloat("velocityfalloffpct", &this->unk8C, 0) != 0) || (arg0->LoadFloat("afterattackholdtime", &this->unk90, 0) != 0) || (arg0->LoadFloat("movechaselerppct", &this->unk94, 0) != 0) || (arg0->LoadFloat("moveattacklerppct", &this->unk98, 0) != 0) || (arg0->LoadFloat("longidletime", &this->unk9C, 0) != 0) || (arg0->LoadFloat("shortidletime", &this->unkA0, 0) != 0) || (arg0->LoadInt("longidleloops", &this->unkA4, 0) != 0) || (arg0->LoadFloat("longidleyoffsetmin", &this->unkA8, 0) != 0) || (arg0->LoadFloat("longidleyoffsetmax", &this->unkAC, 0) != 0) || (arg0->LoadFloat("hintphrasedelay", &this->unkB4, 0) != 0) || (arg0->LoadInt("idlePhraseChance", &this->unkB8, 0) != 0) || (arg0->LoadFloat("longidlerotspeed", &this->unkB0, 0) != 0) || (arg0->LoadFloat("longidle2speed", &this->unkBC, 0) != 0)) {
        var_r31_3793 = 1;
    }
    return var_r31_3793;
}
#endif

void SparxDescriptor::Init() {
    MKPropDescriptor::Init();
    this->unkC |= 0x20;
    this->unk84 = 6.0f;
    this->unk88 = 7.0f;
    this->unk80 = 0.5f;
    this->unk8C = 0.25f;
    this->unk90 = 2.0f;
    this->unk94 = 0.085f;
    this->unk98 = 0.085f;
    this->unk9C = 16.0f;
    this->unkA0 = 4.0f;
    this->unkA4 = 4;
    this->unkA8 = -0.25f;
    this->unkAC = 1.0f;
    this->unkB0 = 12.0f;
    this->unkB4 = 10.0f;
    this->unkB8 = 3;
    this->unkBC = 8.0f;
}

#if 0 // DRAFT: undefined identifier 'localOffset'
void Sparx_cpp::__sinit() {
    s32 spB4;
    s32 spB0;
    f32 spAC;
    s32 spA8;
    s32 spA4;
    s32 spA0;
    s32 sp9C;
    s32 sp98;
    s32 sp94;
    s32 sp90;
    s32 sp8C;
    s32 sp88;
    s32 sp84;
    s32 sp80;
    s32 sp7C;
    s32 sp78;
    s32 sp74;
    s32 sp70;
    s32 sp6C;
    s32 sp68;
    s32 sp64;
    s32 sp60;
    s32 sp5C;
    s32 sp58;
    s32 sp54;
    s32 sp50;
    s32 sp4C;
    s32 sp48;
    s32 sp44;
    s32 sp40;
    s32 sp3C;
    s32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp2C;
    s32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    s32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    s32 sp8;
    f64 temp_f0_4260;
    f64 temp_f1_4225;
    f64 temp_f1_4240;
    f64 temp_f1_4263;
    f64 temp_f3_4210;
    f64 temp_f4_4224;
    f64 temp_f4_4237;
    f64 temp_f8_4212;
    struct _struct_localOffset_0x10 *temp_r17_4219;

    temp_f3_4210 = __frsqrte(2014000.0);
    temp_f8_4212 = __frsqrte(380000.0);
    temp_r17_4219 = localOffset + 0x330;
    temp_f4_4224 = 0.5 * temp_f3_4210 * -((2014000.0 * (temp_f3_4210 * temp_f3_4210)) - 3.0);
    temp_f1_4225 = 0.5 * temp_f8_4212 * -((380000.0 * (temp_f8_4212 * temp_f8_4212)) - 3.0);
    temp_f4_4237 = 0.5 * temp_f4_4224 * -((2014000.0 * (temp_f4_4224 * temp_f4_4224)) - 3.0);
    temp_f1_4240 = 0.5 * temp_f1_4225 * -((380000.0 * (temp_f1_4225 * temp_f1_4225)) - 3.0);
    temp_f0_4260 = 0.5 * temp_f1_4240 * -((380000.0 * (temp_f1_4240 * temp_f1_4240)) - 3.0);
    temp_f1_4263 = 2014000.0 * (0.5 * temp_f4_4237 * -((2014000.0 * (temp_f4_4237 * temp_f4_4237)) - 3.0));
    M2C_FIELD(localOffset, s32 *, 0x330) = (s32) M2C_FIELD(localOffset, s32 *, 0xF0);
    M2C_FIELD(localOffset, s32 *, 0x334) = (s32) M2C_FIELD(localOffset, s32 *, 0xF4);
    M2C_FIELD(localOffset, s32 *, 0x338) = (s32) M2C_FIELD(localOffset, s32 *, 0xF8);
    temp_r17_4219->unkC = M2C_FIELD(localOffset, f32 *, 0xFC);
    temp_r17_4219[1].unk0 = M2C_FIELD(localOffset, s32 *, 0x100);
    temp_r17_4219[1].unk4 = M2C_FIELD(localOffset, f32 *, 0x104);
    temp_r17_4219[1].unk8 = M2C_FIELD(localOffset, f32 *, 0x108);
    temp_r17_4219[1].unkC = M2C_FIELD(localOffset, f32 *, 0x10C);
    temp_r17_4219[2].unk0 = M2C_FIELD(localOffset, s32 *, 0x110);
    temp_r17_4219[2].unk4 = M2C_FIELD(localOffset, f32 *, 0x114);
    temp_r17_4219[2].unk8 = M2C_FIELD(localOffset, f32 *, 0x118);
    temp_r17_4219[2].unkC = M2C_FIELD(localOffset, f32 *, 0x11C);
    temp_r17_4219[3].unk0 = M2C_FIELD(localOffset, s32 *, 0x120);
    temp_r17_4219[3].unk4 = M2C_FIELD(localOffset, f32 *, 0x124);
    temp_r17_4219[3].unk8 = M2C_FIELD(localOffset, f32 *, 0x128);
    temp_r17_4219[3].unkC = M2C_FIELD(localOffset, f32 *, 0x12C);
    temp_r17_4219[4].unk0 = M2C_FIELD(localOffset, s32 *, 0x130);
    temp_r17_4219[4].unk4 = M2C_FIELD(localOffset, f32 *, 0x134);
    SPYRO_BOUNCE_Y_SPEED = (f32) temp_f1_4263;
    SPYRO_MIN_JUMP_Y_VELOCITY = (f32) (380000.0 * temp_f0_4260);
    temp_r17_4219[4].unk8 = M2C_FIELD(localOffset, f32 *, 0x138);
    temp_r17_4219[4].unkC = M2C_FIELD(localOffset, f32 *, 0x13C);
    temp_r17_4219[5].unk0 = M2C_FIELD(localOffset, s32 *, 0x140);
    spAC = M2C_FIELD(localOffset, f32 *, 0x1AC);
    temp_r17_4219[0xB].unk4 = M2C_FIELD(localOffset, f32 *, 0x1A4);
    sp8 = M2C_FIELD(localOffset, s32 *, 0x1B0);
    temp_r17_4219[0xB].unkC = spAC;
    spC = M2C_FIELD(localOffset, f32 *, 0x1B4);
    temp_r17_4219[0xC].unk0 = sp8;
    sp10 = M2C_FIELD(localOffset, f32 *, 0x1B8);
    temp_r17_4219[0xC].unk4 = spC;
    sp14 = M2C_FIELD(localOffset, f32 *, 0x1BC);
    temp_r17_4219[0xC].unk8 = sp10;
    sp18 = M2C_FIELD(localOffset, s32 *, 0x1C0);
    temp_r17_4219[0xC].unkC = sp14;
    sp1C = M2C_FIELD(localOffset, f32 *, 0x1C4);
    temp_r17_4219[0xD].unk0 = sp18;
    sp20 = M2C_FIELD(localOffset, f32 *, 0x1C8);
    temp_r17_4219[0xD].unk4 = sp1C;
    sp24 = M2C_FIELD(localOffset, f32 *, 0x1CC);
    temp_r17_4219[0xD].unk8 = sp20;
    sp28 = M2C_FIELD(localOffset, s32 *, 0x1D0);
    temp_r17_4219[0xD].unkC = sp24;
    sp2C = M2C_FIELD(localOffset, f32 *, 0x1D4);
    temp_r17_4219[0xE].unk0 = sp28;
    sp30 = M2C_FIELD(localOffset, f32 *, 0x1D8);
    temp_r17_4219[0xE].unk4 = sp2C;
    sp34 = M2C_FIELD(localOffset, f32 *, 0x1DC);
    temp_r17_4219[0xE].unk8 = sp30;
    sp38 = M2C_FIELD(localOffset, s32 *, 0x1E0);
    temp_r17_4219[0xE].unkC = sp34;
    sp3C = M2C_FIELD(localOffset, s32 *, 0x1E4);
    M2C_FIELD(temp_r17_4219, s32 *, 0xF0) = sp38;
    sp40 = M2C_FIELD(localOffset, s32 *, 0x1E8);
    M2C_FIELD(temp_r17_4219, s32 *, 0xF4) = sp3C;
    sp44 = M2C_FIELD(localOffset, s32 *, 0x1EC);
    M2C_FIELD(temp_r17_4219, s32 *, 0xF8) = sp40;
    sp48 = M2C_FIELD(localOffset, s32 *, 0x1F0);
    M2C_FIELD(temp_r17_4219, s32 *, 0xFC) = sp44;
    M2C_FIELD(temp_r17_4219, s32 *, 0x100) = sp48;
    sp4C = M2C_FIELD(localOffset, s32 *, 0x1F4);
    temp_r17_4219[5].unk4 = M2C_FIELD(localOffset, f32 *, 0x144);
    temp_r17_4219[5].unk8 = M2C_FIELD(localOffset, f32 *, 0x148);
    temp_r17_4219[5].unkC = M2C_FIELD(localOffset, f32 *, 0x14C);
    temp_r17_4219[6].unk0 = M2C_FIELD(localOffset, s32 *, 0x150);
    temp_r17_4219[6].unk4 = M2C_FIELD(localOffset, f32 *, 0x154);
    temp_r17_4219[6].unk8 = M2C_FIELD(localOffset, f32 *, 0x158);
    temp_r17_4219[6].unkC = M2C_FIELD(localOffset, f32 *, 0x15C);
    temp_r17_4219[7].unk0 = M2C_FIELD(localOffset, s32 *, 0x160);
    temp_r17_4219[7].unk4 = M2C_FIELD(localOffset, f32 *, 0x164);
    temp_r17_4219[7].unk8 = M2C_FIELD(localOffset, f32 *, 0x168);
    temp_r17_4219[7].unkC = M2C_FIELD(localOffset, f32 *, 0x16C);
    temp_r17_4219[8].unk0 = M2C_FIELD(localOffset, s32 *, 0x170);
    temp_r17_4219[8].unk4 = M2C_FIELD(localOffset, f32 *, 0x174);
    temp_r17_4219[8].unk8 = M2C_FIELD(localOffset, f32 *, 0x178);
    temp_r17_4219[8].unkC = M2C_FIELD(localOffset, f32 *, 0x17C);
    temp_r17_4219[9].unk0 = M2C_FIELD(localOffset, s32 *, 0x180);
    temp_r17_4219[9].unk4 = M2C_FIELD(localOffset, f32 *, 0x184);
    temp_r17_4219[9].unk8 = M2C_FIELD(localOffset, f32 *, 0x188);
    temp_r17_4219[9].unkC = M2C_FIELD(localOffset, f32 *, 0x18C);
    temp_r17_4219[0xA].unk0 = M2C_FIELD(localOffset, s32 *, 0x190);
    temp_r17_4219[0xA].unk4 = M2C_FIELD(localOffset, f32 *, 0x194);
    temp_r17_4219[0xA].unk8 = M2C_FIELD(localOffset, f32 *, 0x198);
    temp_r17_4219[0xA].unkC = M2C_FIELD(localOffset, f32 *, 0x19C);
    temp_r17_4219[0xB].unk0 = M2C_FIELD(localOffset, s32 *, 0x1A0);
    temp_r17_4219[0xB].unk8 = M2C_FIELD(localOffset, f32 *, 0x1A8);
    M2C_FIELD(temp_r17_4219, s32 *, 0x104) = (s32) M2C_FIELD(localOffset, s32 *, 0x1F4);
    spB0 = M2C_FIELD(localOffset, s32 *, 0x260);
    M2C_FIELD(temp_r17_4219, s32 *, 0x168) = (s32) M2C_FIELD(localOffset, s32 *, 0x258);
    sp50 = M2C_FIELD(localOffset, s32 *, 0x264);
    M2C_FIELD(temp_r17_4219, s32 *, 0x170) = spB0;
    sp54 = M2C_FIELD(localOffset, s32 *, 0x268);
    M2C_FIELD(temp_r17_4219, s32 *, 0x174) = sp50;
    sp58 = M2C_FIELD(localOffset, s32 *, 0x26C);
    M2C_FIELD(temp_r17_4219, s32 *, 0x178) = sp54;
    sp5C = M2C_FIELD(localOffset, s32 *, 0x270);
    M2C_FIELD(temp_r17_4219, s32 *, 0x17C) = sp58;
    sp60 = M2C_FIELD(localOffset, s32 *, 0x274);
    M2C_FIELD(temp_r17_4219, s32 *, 0x180) = sp5C;
    sp64 = M2C_FIELD(localOffset, s32 *, 0x278);
    M2C_FIELD(temp_r17_4219, s32 *, 0x184) = sp60;
    sp68 = M2C_FIELD(localOffset, s32 *, 0x27C);
    M2C_FIELD(temp_r17_4219, s32 *, 0x188) = sp64;
    sp6C = M2C_FIELD(localOffset, s32 *, 0x280);
    M2C_FIELD(temp_r17_4219, s32 *, 0x18C) = sp68;
    sp70 = M2C_FIELD(localOffset, s32 *, 0x284);
    M2C_FIELD(temp_r17_4219, s32 *, 0x190) = sp6C;
    sp74 = M2C_FIELD(localOffset, s32 *, 0x288);
    M2C_FIELD(temp_r17_4219, s32 *, 0x194) = sp70;
    sp78 = M2C_FIELD(localOffset, s32 *, 0x28C);
    M2C_FIELD(temp_r17_4219, s32 *, 0x198) = sp74;
    sp7C = M2C_FIELD(localOffset, s32 *, 0x290);
    M2C_FIELD(temp_r17_4219, s32 *, 0x19C) = sp78;
    sp80 = M2C_FIELD(localOffset, s32 *, 0x294);
    M2C_FIELD(temp_r17_4219, s32 *, 0x1A0) = sp7C;
    sp84 = M2C_FIELD(localOffset, s32 *, 0x298);
    M2C_FIELD(temp_r17_4219, s32 *, 0x1A4) = sp80;
    sp88 = M2C_FIELD(localOffset, s32 *, 0x29C);
    M2C_FIELD(temp_r17_4219, s32 *, 0x1A8) = sp84;
    sp8C = M2C_FIELD(localOffset, s32 *, 0x2A0);
    M2C_FIELD(temp_r17_4219, s32 *, 0x1AC) = sp88;
    sp90 = M2C_FIELD(localOffset, s32 *, 0x2A4);
    M2C_FIELD(temp_r17_4219, s32 *, 0x1B0) = sp8C;
    M2C_FIELD(temp_r17_4219, s32 *, 0x1B4) = sp90;
    sp94 = M2C_FIELD(localOffset, s32 *, 0x2A8);
    M2C_FIELD(temp_r17_4219, s32 *, 0x108) = (s32) M2C_FIELD(localOffset, s32 *, 0x1F8);
    M2C_FIELD(temp_r17_4219, s32 *, 0x10C) = (s32) M2C_FIELD(localOffset, s32 *, 0x1FC);
    M2C_FIELD(temp_r17_4219, s32 *, 0x110) = (s32) M2C_FIELD(localOffset, s32 *, 0x200);
    M2C_FIELD(temp_r17_4219, s32 *, 0x114) = (s32) M2C_FIELD(localOffset, s32 *, 0x204);
    M2C_FIELD(temp_r17_4219, s32 *, 0x118) = (s32) M2C_FIELD(localOffset, s32 *, 0x208);
    M2C_FIELD(temp_r17_4219, s32 *, 0x11C) = (s32) M2C_FIELD(localOffset, s32 *, 0x20C);
    M2C_FIELD(temp_r17_4219, s32 *, 0x120) = (s32) M2C_FIELD(localOffset, s32 *, 0x210);
    M2C_FIELD(temp_r17_4219, s32 *, 0x124) = (s32) M2C_FIELD(localOffset, s32 *, 0x214);
    M2C_FIELD(temp_r17_4219, s32 *, 0x128) = (s32) M2C_FIELD(localOffset, s32 *, 0x218);
    M2C_FIELD(temp_r17_4219, s32 *, 0x12C) = (s32) M2C_FIELD(localOffset, s32 *, 0x21C);
    M2C_FIELD(temp_r17_4219, s32 *, 0x130) = (s32) M2C_FIELD(localOffset, s32 *, 0x220);
    M2C_FIELD(temp_r17_4219, s32 *, 0x134) = (s32) M2C_FIELD(localOffset, s32 *, 0x224);
    M2C_FIELD(temp_r17_4219, s32 *, 0x138) = (s32) M2C_FIELD(localOffset, s32 *, 0x228);
    M2C_FIELD(temp_r17_4219, s32 *, 0x13C) = (s32) M2C_FIELD(localOffset, s32 *, 0x22C);
    M2C_FIELD(temp_r17_4219, s32 *, 0x140) = (s32) M2C_FIELD(localOffset, s32 *, 0x230);
    M2C_FIELD(temp_r17_4219, s32 *, 0x144) = (s32) M2C_FIELD(localOffset, s32 *, 0x234);
    M2C_FIELD(temp_r17_4219, s32 *, 0x148) = (s32) M2C_FIELD(localOffset, s32 *, 0x238);
    M2C_FIELD(temp_r17_4219, s32 *, 0x14C) = (s32) M2C_FIELD(localOffset, s32 *, 0x23C);
    M2C_FIELD(temp_r17_4219, s32 *, 0x150) = (s32) M2C_FIELD(localOffset, s32 *, 0x240);
    M2C_FIELD(temp_r17_4219, s32 *, 0x154) = (s32) M2C_FIELD(localOffset, s32 *, 0x244);
    M2C_FIELD(temp_r17_4219, s32 *, 0x158) = (s32) M2C_FIELD(localOffset, s32 *, 0x248);
    M2C_FIELD(temp_r17_4219, s32 *, 0x15C) = (s32) M2C_FIELD(localOffset, s32 *, 0x24C);
    M2C_FIELD(temp_r17_4219, s32 *, 0x160) = (s32) M2C_FIELD(localOffset, s32 *, 0x250);
    M2C_FIELD(temp_r17_4219, s32 *, 0x164) = (s32) M2C_FIELD(localOffset, s32 *, 0x254);
    M2C_FIELD(temp_r17_4219, s32 *, 0x16C) = (s32) M2C_FIELD(localOffset, s32 *, 0x25C);
    M2C_FIELD(temp_r17_4219, s32 *, 0x1B8) = (s32) M2C_FIELD(localOffset, s32 *, 0x2A8);
    spB4 = M2C_FIELD(localOffset, s32 *, 0x314);
    M2C_FIELD(temp_r17_4219, s32 *, 0x21C) = (s32) M2C_FIELD(localOffset, s32 *, 0x30C);
    sp98 = M2C_FIELD(localOffset, s32 *, 0x318);
    M2C_FIELD(temp_r17_4219, s32 *, 0x224) = spB4;
    sp9C = M2C_FIELD(localOffset, s32 *, 0x31C);
    M2C_FIELD(temp_r17_4219, s32 *, 0x228) = sp98;
    spA0 = M2C_FIELD(localOffset, s32 *, 0x320);
    M2C_FIELD(temp_r17_4219, s32 *, 0x22C) = sp9C;
    spA4 = M2C_FIELD(localOffset, s32 *, 0x324);
    M2C_FIELD(temp_r17_4219, s32 *, 0x230) = spA0;
    spA8 = M2C_FIELD(localOffset, s32 *, 0x328);
    M2C_FIELD(temp_r17_4219, s32 *, 0x234) = spA4;
    M2C_FIELD(temp_r17_4219, s32 *, 0x1BC) = (s32) M2C_FIELD(localOffset, s32 *, 0x2AC);
    M2C_FIELD(temp_r17_4219, s32 *, 0x1C0) = (s32) M2C_FIELD(localOffset, s32 *, 0x2B0);
    M2C_FIELD(temp_r17_4219, s32 *, 0x1C4) = (s32) M2C_FIELD(localOffset, s32 *, 0x2B4);
    M2C_FIELD(temp_r17_4219, s32 *, 0x1C8) = (s32) M2C_FIELD(localOffset, s32 *, 0x2B8);
    M2C_FIELD(temp_r17_4219, s32 *, 0x1CC) = (s32) M2C_FIELD(localOffset, s32 *, 0x2BC);
    M2C_FIELD(temp_r17_4219, s32 *, 0x1D0) = (s32) M2C_FIELD(localOffset, s32 *, 0x2C0);
    M2C_FIELD(temp_r17_4219, s32 *, 0x1D4) = (s32) M2C_FIELD(localOffset, s32 *, 0x2C4);
    M2C_FIELD(temp_r17_4219, s32 *, 0x1D8) = (s32) M2C_FIELD(localOffset, s32 *, 0x2C8);
    M2C_FIELD(temp_r17_4219, s32 *, 0x1DC) = (s32) M2C_FIELD(localOffset, s32 *, 0x2CC);
    M2C_FIELD(temp_r17_4219, s32 *, 0x1E0) = (s32) M2C_FIELD(localOffset, s32 *, 0x2D0);
    M2C_FIELD(temp_r17_4219, s32 *, 0x1E4) = (s32) M2C_FIELD(localOffset, s32 *, 0x2D4);
    M2C_FIELD(temp_r17_4219, s32 *, 0x1E8) = (s32) M2C_FIELD(localOffset, s32 *, 0x2D8);
    M2C_FIELD(temp_r17_4219, s32 *, 0x1EC) = (s32) M2C_FIELD(localOffset, s32 *, 0x2DC);
    M2C_FIELD(temp_r17_4219, s32 *, 0x1F0) = (s32) M2C_FIELD(localOffset, s32 *, 0x2E0);
    M2C_FIELD(temp_r17_4219, s32 *, 0x1F4) = (s32) M2C_FIELD(localOffset, s32 *, 0x2E4);
    M2C_FIELD(temp_r17_4219, s32 *, 0x1F8) = (s32) M2C_FIELD(localOffset, s32 *, 0x2E8);
    M2C_FIELD(temp_r17_4219, s32 *, 0x1FC) = (s32) M2C_FIELD(localOffset, s32 *, 0x2EC);
    M2C_FIELD(temp_r17_4219, s32 *, 0x200) = (s32) M2C_FIELD(localOffset, s32 *, 0x2F0);
    M2C_FIELD(temp_r17_4219, s32 *, 0x204) = (s32) M2C_FIELD(localOffset, s32 *, 0x2F4);
    M2C_FIELD(temp_r17_4219, s32 *, 0x208) = (s32) M2C_FIELD(localOffset, s32 *, 0x2F8);
    M2C_FIELD(temp_r17_4219, s32 *, 0x20C) = (s32) M2C_FIELD(localOffset, s32 *, 0x2FC);
    M2C_FIELD(temp_r17_4219, s32 *, 0x210) = (s32) M2C_FIELD(localOffset, s32 *, 0x300);
    M2C_FIELD(temp_r17_4219, s32 *, 0x214) = (s32) M2C_FIELD(localOffset, s32 *, 0x304);
    M2C_FIELD(temp_r17_4219, s32 *, 0x218) = (s32) M2C_FIELD(localOffset, s32 *, 0x308);
    M2C_FIELD(temp_r17_4219, s32 *, 0x220) = (s32) M2C_FIELD(localOffset, s32 *, 0x310);
    M2C_FIELD(temp_r17_4219, s32 *, 0x238) = spA8;
    M2C_FIELD(temp_r17_4219, s32 *, 0x23C) = (s32) M2C_FIELD(localOffset, s32 *, 0x32C);
}
#endif
