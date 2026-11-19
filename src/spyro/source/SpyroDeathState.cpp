#include "spyro/source/SpyroDeathState.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "spyro/source/Game.h"
#include "spyro/source/KDCamera.h"
#include "spyro/source/LineSegmentTrail.h"
#include "spyro/source/Spyro.h"
#include "spyro/source/checkpoint.h"
#include "spyro/source/ConnectingProps.h"
#include "spyro/source/DialogBox.h"
#include "spyro/source/EventCamera.h"
#include "spyro/source/KDMath.h"
#include "spyro/source/Music.h"
#include "spyro/source/SpyroHud.h"
#include <m2c_macros.h>

extern f32 SPYRO_BOUNCE_Y_SPEED;
extern f32 SPYRO_MIN_JUMP_Y_VELOCITY;
extern void **gMK;
#if 0 // DRAFT: identifier 'gb' redeclared
extern M2C_UNK gb;
#endif
#if 0 // DRAFT: undefined identifier 'unk14'
static M2C_UNK lit_779;                                /* unable to generate initializer: unknown type */
SpyroDeathState states__15SpyroDeathState;          /* unable to generate initializer: confusing struct layout */

s32 SpyroDeathState::SpawnTransition() {
    if (((u32) *CheckPoint::pCurrentCheckPoint != 0U) && ((s32) this->unk14.unk0 != 3)) {
        this->unk14.SetState(this, 3, 0U);
        return 1;
    }
    return 0;
}
#endif

void SpyroDeathState::SpawnUpdate() {
    f64 sp20;
    f64 sp18;
    f64 sp10;
    f64 sp8;
    u8 var_r3_101;
    void *temp_r4_107;
    void *temp_r4_77;

    this->unk28 = 0;
    if ((void *) *CheckPoint::pCurrentCheckPoint != NULL) {
        sp18 = M2C_FIELD(*CheckPoint::pCurrentCheckPoint, f64 *, 0xF0);
        sp20 = M2C_FIELD(*CheckPoint::pCurrentCheckPoint, f64 *, 0xF8);
        KDMath_GetYaw(M2C_FIELD(*CheckPoint::pCurrentCheckPoint, Matrix **, 8));
        this->unk10->StableReposition(*((MKVector3 *) &sp18), M2C_ERROR(/* Read from unset register $f1 */), 0U, 0U);
        temp_r4_77 = this->unk10->unk8;
        sp8 = M2C_FIELD(temp_r4_77, f64 *, 0x30);
        sp10 = M2C_FIELD(temp_r4_77, f64 *, 0x38);
        if (Connector_Update(*((MKVector3 *) &sp8)) == 0) {
            Music_Pause(1U);
            M2C_FIELD(M2C_FIELD(&gb, void **, 0x32C), u8 *, 8) = 1U;
            M2C_FIELD(M2C_FIELD(&gb, void **, 0x32C), s8 *, 9) = 1;
            ((GameGlobals::Fade *) (&gb + 0x30))->Reset();
            if ((u8) M2C_FIELD(M2C_FIELD(&gb, void **, 0x32C), u8 *, 8) != 0) {
                var_r3_101 = 0;
                if (((u8) M2C_FIELD(M2C_FIELD(&gb, void **, 0xC), u8 *, 0xAA) != 0) || ((temp_r4_107 = M2C_FIELD(M2C_FIELD(&gb, void **, 0xC), void **, 0x68), ((temp_r4_107 == NULL) == 0)) && ((u8) M2C_FIELD(temp_r4_107, u8 *, 0x5D) != 0))) {
                    var_r3_101 = 1;
                }
                if (var_r3_101 == 0) {
                    M2C_FIELD(M2C_FIELD(&gb, void **, 0xC), s8 *, 0xA9) = 0;
                }
            }
        } else {
            ((GameGlobals::Fade *) (&gb + 0x30))->FadeIn(NULL);
        }
    }
    SpawnTransition();
}

#if 0 // DRAFT: undefined identifier '__vptr'
void SpyroDeathState::SpawnExit() {
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    KDCamera *temp_r3_159;
    Spyro *temp_r4_146;
    Spyro *temp_r4_150;
    void *temp_r3_170;

    temp_r4_146 = this->unk10;
    temp_r4_146->unk428 &= 0xFFFF7FFF;
    temp_r4_150 = this->unk10;
    temp_r4_150->unk428 |= 0x1000;
    M2C_FIELD(this->unk10, s8 *, 0x3CF) = 0;
    M2C_FIELD(this->unk10, s8 *, 0x3CC) = 0;
    temp_r3_159 = this->unk10->GetCamera();
    sp14 = 0;
    sp10 = 0x44A;
    M2C_FIELD(temp_r3_159->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp10);
    temp_r3_170 = this->unk10->unkB70;
    if (temp_r3_170 != NULL) {
        spC = 0;
        sp8 = 0xA8;
        M2C_FIELD(M2C_FIELD(temp_r3_170, void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp8);
    }
}
#endif

void SpyroDeathState::SpawnEnter() {
    Spyro *temp_r3_207;
    Spyro *temp_r3_211;
    Spyro *temp_r3_215;

    M2C_FIELD(this->unk10, s8 *, 0x3CF) = 1;
    this->unk28 = 1;
    this->unk10->SetDesiredVelocity(MKVector3::zero, 540000.0f);
    temp_r3_207 = this->unk10;
    temp_r3_207->unk428 |= 0x8000;
    temp_r3_211 = this->unk10;
    temp_r3_211->unk428 |= 0x20;
    temp_r3_215 = this->unk10;
    temp_r3_215->unk428 &= 0xFFFFEFFF;
    this->unk10->ClearSafePos();
    if ((u32) M2C_FIELD(&gb, u32 *, 0x360) == 0U) {
        EnemyHud_Modified(NULL, 0.0f, 0.0f, 0.0f);
    }
    M2C_FIELD(&gb, s8 *, 0xD0) = 0;
}

#if 0 // DRAFT: undefined identifier 'unk14'
s32 SpyroDeathState::RespawnTransition() {
    if ((s32) this->unk14.unk0 != 5) {
        this->unk14.SetState(this, 5, 0U);
        return 1;
    }
    return 0;
}
#endif

void SpyroDeathState::RespawnUpdate() {
    if ((u8) this->unk28 != 0) {
        this->unk28 = 0;
    }
    RespawnTransition();
}

#if 0 // DRAFT: expression syntax error
void SpyroDeathState::RespawnExit() {
    M2C_FIELD(this->unk10, s8 *, 0x3CF) = 0;
    this->unk10->unk4C.RegisterTargetable();
}
#endif

void SpyroDeathState::RespawnEnter() {
    s32 spC;
    s32 sp8;
    Spyro *temp_r4_314;

    temp_r4_314 = this->unk10;
    temp_r4_314->unk428 &= 0xFFFFEFFF;
    M2C_FIELD(this->unk10, s8 *, 0x3CF) = 1;
    this->unk10->ClearSafePos();
    this->unk28 = 1;
    spC = 0;
    sp8 = 0x9D;
    M2C_FIELD(*gMK, M2C_UNK (**)(void **, s32 *, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, f32), 0x94)(gMK, &sp8, 0x40000, 1, 0, 0, 0.0f);
    DialogBox_ReleaseContexts();
}

#if 0 // DRAFT: undefined identifier 'unk14'
u8 SpyroDeathState::AirTransition() {
    u8 var_r31_358;
    u8 var_r3_390;
    u8 var_r3_398;

    var_r31_358 = 0;
    if (((M2C_FIELD(&gb, f32 *, 0x30C) - this->unk2C) > 4.0f) && ((s32) M2C_FIELD(&gb, s32 *, 0x50) == 3)) {
        var_r31_358 = 1;
    }
    if ((s32) M2C_FIELD(this->unk10->unk26C.unk8, s32 *, 0x16C) > 0) {
        this->unk2A = 0;
    }
    if (((s32) M2C_FIELD(this->unk10->unk26C.unk8, s32 *, 0x16C) > 0) && ((s32) this->unk14.unk0 != 0)) {
        this->unk14.SetState(this, 0, 0U);
        var_r3_390 = 1;
    } else {
        var_r3_390 = 0;
    }
    if (var_r3_390 == 0) {
        var_r3_398 = var_r31_358;
        if (var_r31_358 != 0) {
            var_r3_398 = *CheckPoint::pCurrentCheckPoint != 0;
        }
        if ((var_r3_398 != 0) && ((s32) this->unk14.unk0 != 4)) {
            this->unk14.SetState(this, 4, 0U);
            var_r3_390 = 1;
        } else {
            var_r3_390 = 0;
        }
    }
    if (var_r3_390 == 0) {
        if (var_r31_358 != 0) {
            var_r31_358 = *CheckPoint::pCurrentCheckPoint == 0;
        }
        if ((var_r31_358 != 0) && ((s32) this->unk14.unk0 != 3)) {
            this->unk14.SetState(this, 3, 0U);
            return 1U;
        }
        var_r3_390 = 0;
        /* Duplicate return node #23. Try simplifying control flow for better match */
        return var_r3_390;
    }
    return var_r3_390;
}
#endif

void SpyroDeathState::AirUpdate() {
    if (((M2C_FIELD(&gb, f32 *, 0x30C) - this->unk2C) > 2.67f) && ((s32) M2C_FIELD(&gb, s32 *, 0x50) < 2)) {
        ((GameGlobals::Fade *) (&gb + 0x30))->FadeOut(NULL);
    }
    AirTransition();
}

void SpyroDeathState::AirExit() {
    M2C_FIELD(this->unk10, f32 *, 0x38C) = 1900.0f;
    this->unk10->unk6F8.FadeOut(4);
    M2C_FIELD(this->unk10, f32 *, 0x3DC) = (f32) (M2C_FIELD(&gb, f32 *, 0x30C) + 0.5f);
    if ((u8) this->unk2A != 0) {
        this->unk2A = 0;
        this->unk10->BroadcastMessage(0x15);
    }
}

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void SpyroDeathState::AirEnter() {
    f64 sp28;
    f64 sp20;
    s32 sp1C;
    s32 sp18;
    f64 sp10;
    f64 sp8;
    Spyro *temp_r3_535;
    Spyro *temp_r3_559;
    f32 temp_f0_539;
    f32 temp_f1_537;
    f32 var_f2_538;
    f64 temp_f0_597;
    f64 temp_f1_596;
    void *temp_r3_594;

    this->unk10->SetMedium((Spyro::Medium) 2);
    M2C_FIELD(this->unk10, s8 *, 0x3CD) = 1;
    temp_r3_535 = this->unk10;
    temp_r3_535->unk388 = 3800.0f;
    temp_f1_537 = temp_r3_535->unk388;
    var_f2_538 = temp_r3_535->unk33C;
    temp_f0_539 = -temp_f1_537;
    if (var_f2_538 < temp_f1_537) {

    } else {
        var_f2_538 = temp_f1_537;
    }
    if (var_f2_538 > temp_f0_539) {

    } else {
        var_f2_538 = temp_f0_539;
    }
    temp_r3_535->unk33C = var_f2_538;
    M2C_FIELD(this->unk10, f32 *, 0x38C) = 1900.0f;
    if (((u8) this->unk30 == 0) && (temp_r3_559 = this->unk10, (((u8) M2C_FIELD(temp_r3_559, u8 *, 0x2F0) == 0) == 0)) && (M2C_FIELD(temp_r3_559, f32 *, 0x298) < 1000.0f)) {
        temp_r3_559->SetAnim(0x3FU, 0.4f, (Spyro::AnimScriptNode) 0, 0U, 1.0f);
    } else {
        this->unk10->SetAnim(0x57U, 0.4f, (Spyro::AnimScriptNode) 0, 0U, 1.0f);
        this->unk10->unk6F8.FadeIn(4, -1);
        if (EventCamera_GetCurrent() == NULL) {
            sp1C = 0;
            temp_r3_594 = this->unk10->GetCamera()->unk8;
            temp_f1_596 = M2C_FIELD(temp_r3_594, f64 *, 0x30);
            temp_f0_597 = M2C_FIELD(temp_r3_594, f64 *, 0x38);
            sp8 = temp_f1_596;
            sp18 = 0x428;
            sp20 = temp_f1_596;
            sp28 = temp_f0_597;
            sp10 = temp_f0_597;
            M2C_FIELD(this->unk10->GetCamera()->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp18);
            this->unk29 = 1;
        }
    }
    this->unk10->BroadcastMessage(0x14);
    this->unk10->unk4C.UnregisterTargetable();
    this->unk2A = 1;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void SpyroDeathState::StrafeUpdate() {
    this->unk10->SetDesiredVelocity(MKVector3::zero, 540000.0f);
    if ((this->unk10->GetAnimScript((Spyro::AnimScriptNode) 0)->unk2C & 1) && ((s32) M2C_FIELD(&gb, s32 *, 0x50) < 2)) {
        ((GameGlobals::Fade *) (&gb + 0x30))->FadeOut(NULL);
    }
    LandTransition();
}
#endif

void SpyroDeathState::StrafeExit() {
    M2C_FIELD(this->unk10, f32 *, 0x3DC) = (f32) (M2C_FIELD(&gb, f32 *, 0x30C) + 0.5f);
    this->unk2A = 0;
    this->unk10->BroadcastMessage(0x15);
}

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void SpyroDeathState::StrafeEnter() {
    this->unk10->SetMedium((Spyro::Medium) 1);
    this->unk10->SetAnim(0x13U, 0.0f, (Spyro::AnimScriptNode) 0, 0U, 1.0f);
    this->unk10->BroadcastMessage(0x14);
    M2C_FIELD(this->unk10, s8 *, 0x3CD) = 1;
    this->unk10->unk4C.UnregisterTargetable();
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
u8 SpyroDeathState::LandTransition() {
    u8 var_r31_732;
    u8 var_r3_746;
    u8 var_r3_763;

    var_r31_732 = 0;
    if ((this->unk10->GetAnimScript((Spyro::AnimScriptNode) 0)->unk2C & 1) && ((s32) M2C_FIELD(&gb, s32 *, 0x50) == 3)) {
        var_r31_732 = 1;
    }
    var_r3_746 = var_r31_732;
    if (var_r31_732 != 0) {
        var_r3_746 = *CheckPoint::pCurrentCheckPoint != 0;
    }
    if ((var_r3_746 != 0) && ((s32) this->unk14.unk0 != 4)) {
        this->unk14.SetState(this, 4, 0U);
        var_r3_763 = 1;
    } else {
        var_r3_763 = 0;
    }
    if (var_r3_763 == 0) {
        if (var_r31_732 != 0) {
            var_r31_732 = *CheckPoint::pCurrentCheckPoint == 0;
        }
        if ((var_r31_732 != 0) && ((s32) this->unk14.unk0 != 3)) {
            this->unk14.SetState(this, 3, 0U);
            return 1U;
        }
        var_r3_763 = 0;
        /* Duplicate return node #16. Try simplifying control flow for better match */
        return var_r3_763;
    }
    return var_r3_763;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void SpyroDeathState::LandUpdate() {
    this->unk10->SetDesiredVelocity(MKVector3::zero, 540000.0f);
    if ((this->unk10->GetAnimScript((Spyro::AnimScriptNode) 0)->unk2C & 1) && ((s32) M2C_FIELD(&gb, s32 *, 0x50) < 2)) {
        ((GameGlobals::Fade *) (&gb + 0x30))->FadeOut(NULL);
    }
    LandTransition();
}
#endif

void SpyroDeathState::LandExit() {
    M2C_FIELD(this->unk10, f32 *, 0x3DC) = (f32) (M2C_FIELD(&gb, f32 *, 0x30C) + 0.5f);
    this->unk10->BroadcastMessage(0x15);
}

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void SpyroDeathState::LandEnter() {
    this->unk10->SetMedium((Spyro::Medium) 1);
    this->unk10->SetAnim(0x56U, 0.0f, (Spyro::AnimScriptNode) 0, 0U, 1.0f);
    this->unk10->BroadcastMessage(0x14);
    M2C_FIELD(this->unk10, s8 *, 0x3CD) = 1;
    this->unk10->unk4C.UnregisterTargetable();
}
#endif

#if 0 // DRAFT: undefined identifier 'unk14'
void SpyroDeathState::Message(MKMessage *arg0) {
    if ((s32) arg0->unk0 != 0xA3) {
        return;
    }
    if (this->unk14.GetState() == 2) {
        this->unk14.SetState(this, 4, 0U);
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk14'
u8 SpyroDeathState::Transition() {
    u32 var_r31_929;

    var_r31_929 = 4;
    if ((u8) this->unk10->unk3CE != 0) {
        var_r31_929 = 3;
    }
    this->unk10->TryChangeState(this->unk14.GetState() == 3, var_r31_929, NULL, 0U);
}
#endif

#if 0 // DRAFT: undefined identifier 'unk14'
void SpyroDeathState::Update() {
    this->unk14.Update(this, 0);
}
#endif

#if 0 // DRAFT: undefined identifier 'unk14'
void SpyroDeathState::Exit() {
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    KDCamera *temp_r3_986;
    Spyro *temp_r3_1001;
    Spyro *temp_r3_1022;
    Spyro *temp_r3_997;

    this->unk14.Exit(this);
    if ((u8) this->unk29 != 0) {
        this->unk29 = 0;
        temp_r3_986 = this->unk10->GetCamera();
        sp14 = 0;
        sp10 = 0x429;
        M2C_FIELD(temp_r3_986->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp10);
    }
    temp_r3_997 = this->unk10;
    temp_r3_997->unk428 |= 0x20000;
    temp_r3_1001 = this->unk10;
    temp_r3_1001->unk428 |= 0x800;
    this->unk10->DeathReset();
    M2C_FIELD(this->unk10, s8 *, 0x3CD) = 0;
    M2C_FIELD(this->unk10, s8 *, 0x3CF) = 0;
    ((LineSegmentTrail *) (M2C_FIELD(M2C_FIELD(this->unk10->unk258, void **, 4), LineSegmentTrail **, 0xC8)))->EndTrail();
    ((LineSegmentTrail *) (M2C_FIELD(M2C_FIELD(this->unk10->unk258, void **, 4), LineSegmentTrail **, 0xCC)))->EndTrail();
    temp_r3_1022 = this->unk10;
    spC = 0;
    sp8 = 0xAA;
    temp_r3_1022->Message(&sp8, 0);
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void SpyroDeathState::Enter(SpyroStateMessages &arg0) {
    s32 sp20;
    s32 sp1C;
    s32 sp18;
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    KDCamera *temp_r3_1059;
    Spyro *temp_r3_1054;
    Spyro *temp_r3_1136;
    Spyro *temp_r5_1050;
    void *temp_r3_1147;

    temp_r5_1050 = this->unk10;
    temp_r5_1050->unk428 &= 0xFFF9FD7E;
    temp_r3_1054 = this->unk10;
    temp_r3_1054->unk428 &= 0xFFFFF7FF;
    temp_r3_1059 = this->unk10->GetCamera();
    sp14 = 0;
    sp10 = 0x42B;
    M2C_FIELD(temp_r3_1059->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp10);
    this->unk2C = M2C_FIELD(&gb, f32 *, 0x30C);
    this->unk29 = 0;
    this->unk30 = arg0.IsMessageOnList(0x183);
    if ((u8) M2C_FIELD(this->unk10, u8 *, 0x3CC) != 0) {
        this->unk14.SetState(this, 5, 0U);
    } else if (arg0.IsMessageOnList(0x188) != 0) {
        this->unk14.SetState(this, 4, 0U);
    } else if ((this->unk10->unk7C.GetState() == 2) || ((u8) this->unk30 != 0)) {
        this->unk14.SetState(this, 2, 0U);
    } else if (arg0.IsMessageOnList(0x178) != 0) {
        this->unk14.SetState(this, 1, 0U);
    } else {
        this->unk14.SetState(this, 0, 0U);
    }
    temp_r3_1136 = this->unk10;
    spC = 0;
    sp8 = 0xA9;
    temp_r3_1136->Message(&sp8, 0);
    temp_r3_1147 = this->unk10->unkB70;
    if ((temp_r3_1147 != NULL) && ((u8) M2C_FIELD(temp_r3_1147, u8 *, 0x1F2) == 0)) {
        sp1C = 0;
        sp18 = 0x17;
        sp20 = 8;
        M2C_FIELD(M2C_FIELD(temp_r3_1147, void **, 0x44), M2C_UNK (**)(s32 *, M2C_UNK), 0x2C)(&sp18, 0x17);
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk14'
void SpyroDeathState::Deinit() {
    this->unk14.Deinit(this);
}
#endif

#if 0 // DRAFT: undefined identifier 'Init__33KDStateMachine'
void SpyroDeathState::Init(Spyro *arg0) {
    this->unk10 = arg0;
    this->unk28 = 0;
    this->unk29 = 0;
    this->unk2A = 0;
    this->unk2C = 0.0f;
    this->unk30 = 0;
    Init__33KDStateMachine<15SpyroDeathState>FPQ233KDStateMachine<15SpyroDeathState>5StateP33KDStateMachine<15SpyroDeathState>(&this->unk14, (KDStateMachine<SpyroDeathState>::State *) &SpyroDeathState::states, NULL);
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_779'
void SpyroDeathState_cpp::__sinit() {
    s32 sp10;
    s32 spC;
    s32 sp8;
    f64 temp_f0_1510;
    f64 temp_f1_1480;
    f64 temp_f1_1504;
    f64 temp_f3_1466;
    f64 temp_f3_1507;
    f64 temp_f4_1479;
    f64 temp_f4_1501;
    f64 temp_f8_1468;
    void *temp_r3_1471;

    temp_f3_1466 = __frsqrte(2014000.0);
    temp_f8_1468 = __frsqrte(380000.0);
    temp_r3_1471 = &lit_779 + 0xB4;
    temp_f4_1479 = 0.5 * temp_f3_1466 * -((2014000.0 * (temp_f3_1466 * temp_f3_1466)) - 3.0);
    temp_f1_1480 = 0.5 * temp_f8_1468 * -((380000.0 * (temp_f8_1468 * temp_f8_1468)) - 3.0);
    temp_f4_1501 = 0.5 * temp_f4_1479 * -((2014000.0 * (temp_f4_1479 * temp_f4_1479)) - 3.0);
    temp_f1_1504 = 0.5 * temp_f1_1480 * -((380000.0 * (temp_f1_1480 * temp_f1_1480)) - 3.0);
    temp_f3_1507 = temp_f4_1501 * temp_f4_1501;
    temp_f0_1510 = temp_f1_1504 * temp_f1_1504;
    M2C_FIELD(&lit_779, s32 *, 0xB4) = (s32) M2C_FIELD(&lit_779, s32 *, 0);
    M2C_FIELD(&lit_779, s32 *, 0xB8) = (s32) M2C_FIELD(&lit_779, s32 *, 4);
    M2C_FIELD(&lit_779, s32 *, 0xBC) = (s32) M2C_FIELD(&lit_779, s32 *, 8);
    M2C_FIELD(temp_r3_1471, s32 *, 0xC) = (s32) M2C_FIELD(&lit_779, s32 *, 0xC);
    M2C_FIELD(temp_r3_1471, s32 *, 0x10) = (s32) M2C_FIELD(&lit_779, s32 *, 0x10);
    M2C_FIELD(temp_r3_1471, s32 *, 0x14) = (s32) M2C_FIELD(&lit_779, s32 *, 0x14);
    M2C_FIELD(temp_r3_1471, s32 *, 0x18) = (s32) M2C_FIELD(&lit_779, s32 *, 0x18);
    M2C_FIELD(temp_r3_1471, s32 *, 0x1C) = (s32) M2C_FIELD(&lit_779, s32 *, 0x1C);
    M2C_FIELD(temp_r3_1471, s32 *, 0x20) = (s32) M2C_FIELD(&lit_779, s32 *, 0x20);
    M2C_FIELD(temp_r3_1471, s32 *, 0x24) = (s32) M2C_FIELD(&lit_779, s32 *, 0x24);
    M2C_FIELD(temp_r3_1471, s32 *, 0x28) = (s32) M2C_FIELD(&lit_779, s32 *, 0x28);
    M2C_FIELD(temp_r3_1471, s32 *, 0x2C) = (s32) M2C_FIELD(&lit_779, s32 *, 0x2C);
    M2C_FIELD(temp_r3_1471, s32 *, 0x30) = (s32) M2C_FIELD(&lit_779, s32 *, 0x30);
    M2C_FIELD(temp_r3_1471, s32 *, 0x34) = (s32) M2C_FIELD(&lit_779, s32 *, 0x34);
    M2C_FIELD(temp_r3_1471, s32 *, 0x38) = (s32) M2C_FIELD(&lit_779, s32 *, 0x38);
    M2C_FIELD(temp_r3_1471, s32 *, 0x3C) = (s32) M2C_FIELD(&lit_779, s32 *, 0x3C);
    M2C_FIELD(temp_r3_1471, s32 *, 0x40) = (s32) M2C_FIELD(&lit_779, s32 *, 0x40);
    M2C_FIELD(temp_r3_1471, s32 *, 0x44) = (s32) M2C_FIELD(&lit_779, s32 *, 0x44);
    SPYRO_BOUNCE_Y_SPEED = (f32) (2014000.0 * (0.5 * temp_f4_1501 * -((2014000.0 * temp_f3_1507) - 3.0)));
    SPYRO_MIN_JUMP_Y_VELOCITY = (f32) (380000.0 * (0.5 * temp_f1_1504 * -((380000.0 * temp_f0_1510) - 3.0)));
    M2C_FIELD(temp_r3_1471, s32 *, 0x48) = (s32) M2C_FIELD(&lit_779, s32 *, 0x48);
    M2C_FIELD(temp_r3_1471, s32 *, 0x4C) = (s32) M2C_FIELD(&lit_779, s32 *, 0x4C);
    M2C_FIELD(temp_r3_1471, s32 *, 0x50) = (s32) M2C_FIELD(&lit_779, s32 *, 0x50);
    M2C_FIELD(temp_r3_1471, s32 *, 0x54) = (s32) M2C_FIELD(&lit_779, s32 *, 0x54);
    M2C_FIELD(temp_r3_1471, s32 *, 0x58) = (s32) M2C_FIELD(&lit_779, s32 *, 0x58);
    M2C_FIELD(temp_r3_1471, s32 *, 0x5C) = (s32) M2C_FIELD(&lit_779, s32 *, 0x5C);
    M2C_FIELD(temp_r3_1471, s32 *, 0x60) = (s32) M2C_FIELD(&lit_779, s32 *, 0x60);
    M2C_FIELD(temp_r3_1471, s32 *, 0x64) = (s32) M2C_FIELD(&lit_779, s32 *, 0x64);
    M2C_FIELD(temp_r3_1471, s32 *, 0x68) = (s32) M2C_FIELD(&lit_779, s32 *, 0x68);
    M2C_FIELD(temp_r3_1471, s32 *, 0x6C) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 0);
    M2C_FIELD(temp_r3_1471, s32 *, 0x70) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 4);
    M2C_FIELD(temp_r3_1471, s32 *, 0x74) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 8);
    M2C_FIELD(temp_r3_1471, s32 *, 0x78) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 0);
    M2C_FIELD(temp_r3_1471, s32 *, 0x7C) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 4);
    M2C_FIELD(temp_r3_1471, s32 *, 0x80) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 8);
    M2C_FIELD(temp_r3_1471, s32 *, 0x84) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 0);
    M2C_FIELD(temp_r3_1471, s32 *, 0x88) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 4);
    M2C_FIELD(temp_r3_1471, s32 *, 0x8C) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 8);
    M2C_FIELD(temp_r3_1471, s32 *, 0x90) = (s32) M2C_FIELD(&lit_779, s32 *, 0x6C);
    M2C_FIELD(temp_r3_1471, s32 *, 0x94) = (s32) M2C_FIELD(&lit_779, s32 *, 0x70);
    M2C_FIELD(temp_r3_1471, s32 *, 0x98) = (s32) M2C_FIELD(&lit_779, s32 *, 0x74);
    M2C_FIELD(temp_r3_1471, s32 *, 0x9C) = (s32) M2C_FIELD(&lit_779, s32 *, 0x78);
    M2C_FIELD(temp_r3_1471, s32 *, 0xA0) = (s32) M2C_FIELD(&lit_779, s32 *, 0x7C);
    M2C_FIELD(temp_r3_1471, s32 *, 0xA4) = (s32) M2C_FIELD(&lit_779, s32 *, 0x80);
    M2C_FIELD(temp_r3_1471, s32 *, 0xA8) = (s32) M2C_FIELD(&lit_779, s32 *, 0x84);
    M2C_FIELD(temp_r3_1471, s32 *, 0xAC) = (s32) M2C_FIELD(&lit_779, s32 *, 0x88);
    M2C_FIELD(temp_r3_1471, s32 *, 0xB0) = (s32) M2C_FIELD(&lit_779, s32 *, 0x8C);
    M2C_FIELD(temp_r3_1471, s32 *, 0xB4) = (s32) M2C_FIELD(&lit_779, s32 *, 0x90);
    M2C_FIELD(temp_r3_1471, s32 *, 0xB8) = (s32) M2C_FIELD(&lit_779, s32 *, 0x94);
    M2C_FIELD(temp_r3_1471, s32 *, 0xBC) = (s32) M2C_FIELD(&lit_779, s32 *, 0x98);
    M2C_FIELD(temp_r3_1471, s32 *, 0xC0) = (s32) M2C_FIELD(&lit_779, s32 *, 0x9C);
    M2C_FIELD(temp_r3_1471, s32 *, 0xC4) = (s32) M2C_FIELD(&lit_779, s32 *, 0xA0);
    M2C_FIELD(temp_r3_1471, s32 *, 0xC8) = (s32) M2C_FIELD(&lit_779, s32 *, 0xA4);
    M2C_FIELD(temp_r3_1471, s32 *, 0xCC) = (s32) M2C_FIELD(&lit_779, s32 *, 0xA8);
    M2C_FIELD(temp_r3_1471, s32 *, 0xD0) = (s32) M2C_FIELD(&lit_779, s32 *, 0xAC);
    M2C_FIELD(temp_r3_1471, s32 *, 0xD4) = (s32) M2C_FIELD(&lit_779, s32 *, 0xB0);
    sp8 = M2C_FIELD(&__ptmf_null, s32 *, 0);
    spC = M2C_FIELD(&__ptmf_null, s32 *, 4);
    sp10 = M2C_FIELD(&__ptmf_null, s32 *, 8);
}
#endif
