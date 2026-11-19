#include "spyro/source/SpyroFallState.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "spyro/source/InputModifier.h"
#include "spyro/source/KDCamera.h"
#include "spyro/source/KDInput.h"
#include "spyro/source/LineSegmentTrail.h"
#include "spyro/source/Spyro.h"
#include "unplaced_templates.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKInput.h"
#include "spyro/source/KDSound.h"
#include <m2c_macros.h>

extern s32 GS_SpyroFlinch1;
extern s32 GS_SpyroLand;
extern f32 SPYRO_BOUNCE_Y_SPEED;
extern f32 SPYRO_MIN_JUMP_Y_VELOCITY;
extern M2C_UNK gb;
#if 0 // DRAFT: undefined identifier '__vptr'
static M2C_UNK lit_728;                                /* unable to generate initializer: unknown type */
static SpyroFallState states__14SpyroFallState;     /* type too large by 0x10; unable to generate initializer: confusing struct layout */

void SpyroFallState::SetStrafeJump(bool arg0) {
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    KDCamera *temp_r3_38;
    KDCamera *temp_r3_56;

    if ((arg0 != 0) && ((u8) this->unk38 == 0)) {
        temp_r3_38 = this->unk10->GetCamera();
        sp14 = 0;
        sp10 = 0x43D;
        M2C_FIELD(temp_r3_38->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp10);
    } else if ((arg0 == 0) && ((u8) this->unk38 != 0)) {
        temp_r3_56 = this->unk10->GetCamera();
        spC = 0;
        sp8 = 0x43F;
        M2C_FIELD(temp_r3_56->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp8);
    }
    this->unk38 = arg0;
}
#endif

#if 0 // DRAFT: illegal type
void SpyroFallState::GetFallVel() {
    M2C_UNK sp38;
    M2C_UNK sp28;
    f32 sp20;
    f32 sp10;
    f32 temp_f1_142;
    s32 temp_r3_89;
    void *temp_r31_84;
    void *temp_r3_87;
    void *var_r3_95;

    temp_r31_84 = M2C_ERROR(/* Read from unset register $r4 */);
    temp_r3_87 = M2C_FIELD(M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), void **, 0x10), void **, 0x27C);
    temp_r3_89 = M2C_FIELD(temp_r3_87, s32 *, 0x2D4);
    if (temp_r3_89 > 0) {
        if (temp_r3_89 != 0) {
            var_r3_95 = temp_r3_87 + 0x170 + ((temp_r3_89 - 1) * 0x58);
        } else {
            var_r3_95 = NULL;
        }
        if (M2C_FIELD(var_r3_95, s32 *, 0x44) & 3) {
            M2C_FIELD(this, f64 *, 0) = (f64) M2C_FIELD(&zero, f64 *, 0);
            this->unk8 = M2C_FIELD(&zero, f64 *, 8);
            return;
        }
        goto block_6;
    }
block_6:
    if ((u8) M2C_FIELD(temp_r31_84, u8 *, 0x34) != 0) {
        sp38.CalcYawTurnDir(3.5f);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
        M2C_FIELD(this, f64 *, 0) = sp18;
        sp20 = sp40 * 750.0f;
        this->unk8 = (f64) sp20;
        return;
    }
    sp28.CalcVelTurnDir(2.3999999f);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
    temp_f1_142 = sp30 * (750.0f * ((KDInput *) (((Spyro *) (M2C_FIELD(temp_r31_84, Spyro **, 0x10)))->GetInput()))->GetLeftMag());
    M2C_FIELD(this, f64 *, 0) = sp8;
    sp10 = temp_f1_142;
    this->unk8 = (f64) sp10;
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void SpyroFallState::Landed(bool arg0) {
    s8 sp32;
    s8 sp31;
    s8 sp30;
    f64 sp28;
    f64 sp20;
    s32 sp1C;
    s32 sp18;
    f64 sp10;
    f64 sp8;
    Spyro *temp_r3_188;
    Spyro *temp_r3_207;
    f64 temp_f0_191;
    f64 temp_f1_190;
    void *temp_r5_189;

    if (arg0 != 0) {
        this->unk10->AddFootEffect(2);
        this->unk10->AddFootEffect(3);
        this->unk10->AddFootEffect(4);
        this->unk10->AddFootEffect(5);
    }
    if (this->unk10->OnProp() != NULL) {
        sp1C = 0;
        temp_r3_188 = this->unk10;
        temp_r5_189 = temp_r3_188->unk8;
        temp_f1_190 = M2C_FIELD(temp_r5_189, f64 *, 0x30);
        temp_f0_191 = M2C_FIELD(temp_r5_189, f64 *, 0x38);
        sp8 = temp_f1_190;
        sp10 = temp_f0_191;
        sp18 = 0xF;
        sp20 = temp_f1_190;
        sp28 = temp_f0_191;
        sp30 = 0;
        sp31 = 0;
        sp32 = 1;
        M2C_FIELD(temp_r3_188->OnProp()->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp18);
    }
    temp_r3_207 = this->unk10;
    if (((s32) M2C_FIELD(temp_r3_207->unk26C.unk8, s32 *, 0x16C) > 0) && ((u32) temp_r3_207->unk40C != 0U)) {
        temp_r3_207->BridgeHit(0.0f, 1000.0f);
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'long' to
u8 SpyroFallState::HoverTransition() {
    InputModifier *temp_r3_235;
    f32 var_f1_248;
    u8 var_r3_268;
    u8 var_r4_237;

    temp_r3_235 = this->unk10->GetInput();
    var_r4_237 = 0;
    if (((u8) temp_r3_235->unk5 != 0) || ((u8) temp_r3_235->unk4 != 0)) {
        var_r4_237 = 1;
    }
    if (var_r4_237 != 0) {
        var_f1_248 = 0.0f;
    } else {
        var_f1_248 = MKInput_GetState(0xE, (MKInputDevices) temp_r3_235->unk0, NULL, NULL);
    }
    if ((var_f1_248 == 0.0f) && ((s32) this->unk14.unk0 != 0)) {
        this->unk14.SetState(this, 0, 0U);
        var_r3_268 = 1;
    } else {
        var_r3_268 = 0;
    }
    if (var_r3_268 == 0) {
        if (((u8) (((KDInput *) (this->unk10->GetInput()))->GetLeftMag() != 0.0f) != 0) && ((s32) this->unk14.unk0 != 2)) {
            this->unk14.SetState(this, 2, 0U);
            return 1U;
        }
        var_r3_268 = 0;
        /* Duplicate return node #15. Try simplifying control flow for better match */
        return var_r3_268;
    }
    return var_r3_268;
}
#endif

#if 0 // DRAFT: undefined identifier 'zero'
void SpyroFallState::HoverUpdate() {
    this->unk74.Update(this->unk10);
    this->unk10->SetDesiredVelocityHoriz(zero, 3800.0f);
    HoverTransition();
}
#endif

void SpyroFallState::HoverExit() {

}

#if 0 // DRAFT: undefined identifier 'zero'
void SpyroFallState::HoverEnter() {
    Spyro *temp_r3_357;
    f32 temp_f0_361;
    f32 temp_f1_359;
    f32 var_f2_360;

    this->unk74.Start(this->unk10, 0.2f);
    this->unk10->SetDesiredVelocityHoriz(zero, 3800.0f);
    M2C_FIELD(this->unk10, f32 *, 0x38C) = 3240.0002f;
    temp_r3_357 = this->unk10;
    temp_r3_357->unk388 = 500.0f;
    temp_f1_359 = temp_r3_357->unk388;
    var_f2_360 = temp_r3_357->unk33C;
    temp_f0_361 = -temp_f1_359;
    if (var_f2_360 < temp_f1_359) {

    } else {
        var_f2_360 = temp_f1_359;
    }
    if (var_f2_360 > temp_f0_361) {

    } else {
        var_f2_360 = temp_f0_361;
    }
    temp_r3_357->unk33C = var_f2_360;
    this->unk44 = 0x3A;
    this->unk3C = 0x187;
    this->unk48 = 0.0f;
    this->unk4C = 0.2f;
    this->unk50 = 1;
    this->unk51 = 1;
    this->unk4C = 0.0f;
}
#endif

#if 0 // DRAFT: undefined identifier 'sp18'
u8 SpyroFallState::GlideTransition() {
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp10;
    InputModifier *temp_r3_458;
    f32 var_f1_471;
    f64 temp_f2_407;
    f64 temp_f3_405;
    u8 var_r3_450;
    u8 var_r4_460;
    void *temp_r3_404;

    temp_r3_404 = this->unk10->unk8;
    temp_f3_405 = M2C_FIELD(temp_r3_404, f64 *, 0x30);
    temp_f2_407 = M2C_FIELD(temp_r3_404, f64 *, 0x38);
    sp58 = temp_f3_405;
    sp60 = temp_f2_407;
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r4, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f4 */);
    sp38 = temp_f3_405;
    sp28 = sp18;
    sp20 = M2C_FIELD((temp_r3_404 + 0x20), f32 *, 8) * 100.0f;
    sp40 = temp_f2_407;
    sp30 = (f64) sp20;
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    sp48 = sp8;
    sp10 = (f32) sp40 - (f32) sp30;
    sp50 = (f64) sp10;
    if ((MKCollision_RayCollide(*((MKVector3 *) &sp58), *((MKVector3 *) &sp48), NULL, (MKCollisionMode) 4, 0x04000000) != 0) && ((s32) this->unk14.unk0 != 0)) {
        this->unk14.SetState(this, 0, 0U);
        var_r3_450 = 1;
    } else {
        var_r3_450 = 0;
    }
    if (var_r3_450 == 0) {
        temp_r3_458 = this->unk10->GetInput();
        var_r4_460 = 0;
        if (((u8) temp_r3_458->unk5 != 0) || ((u8) temp_r3_458->unk4 != 0)) {
            var_r4_460 = 1;
        }
        if (var_r4_460 != 0) {
            var_f1_471 = 0.0f;
        } else {
            var_f1_471 = MKInput_GetState(0xE, (MKInputDevices) temp_r3_458->unk0, NULL, NULL);
        }
        if ((var_f1_471 == 0.0f) && ((s32) this->unk14.unk0 != 0)) {
            this->unk14.SetState(this, 0, 0U);
            var_r3_450 = 1;
        } else {
            var_r3_450 = 0;
        }
    }
    if (var_r3_450 == 0) {
        ((KDInput *) (this->unk10->GetInput()))->GetLeftMag();
        if ((((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1DU) & 1) && ((s32) this->unk14.unk0 != 3)) {
            this->unk14.SetState(this, 3, 0U);
            return 1U;
        }
        var_r3_450 = 0;
        /* Duplicate return node #20. Try simplifying control flow for better match */
        return var_r3_450;
    }
    return var_r3_450;
}
#endif

#if 0 // DRAFT: expression syntax error
void SpyroFallState::GlideUpdate() {
    f64 sp30;
    f64 sp28;
    M2C_UNK sp18;
    f32 sp10;
    f32 temp_f2_554;

    this->unk6C.Update(this->unk10);
    sp18.CalcYawTurnDir(2.3999999f);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
    temp_f2_554 = sp20 * (1000.0f * ((KDInput *) (this->unk10->GetInput()))->GetLeftMag());
    sp28 = sp8;
    sp10 = temp_f2_554;
    sp30 = (f64) sp10;
    this->unk10->SetDesiredVelocityHoriz(*((MKVector3 *) &sp28), 3800.0f);
    this->unk10->unk3A0.YawTowards(*((MKVector3 *) &sp28), 900.0f);
    GlideTransition();
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void SpyroFallState::GlideExit() {
    s32 spC;
    s32 sp8;
    KDCamera *temp_r3_595;
    Spyro *temp_r3_590;

    this->unk10->unk6F8.FadeOut(2);
    temp_r3_590 = this->unk10;
    temp_r3_590->unk428 &= 0xFFFF7FFF;
    temp_r3_595 = this->unk10->GetCamera();
    spC = 0;
    sp8 = 0x438;
    M2C_FIELD(temp_r3_595->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp8);
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void SpyroFallState::GlideEnter() {
    s32 spC;
    s32 sp8;
    KDCamera *temp_r3_651;
    Spyro *temp_r3_624;
    Spyro *temp_r3_632;
    f32 temp_f0_636;
    f32 temp_f1_634;
    f32 var_f2_635;

    this->unk6C.Start(this->unk10, 0.17f);
    temp_r3_624 = this->unk10;
    temp_r3_624->unk428 |= 0x8000;
    M2C_FIELD(this->unk10, f32 *, 0x38C) = 3240.0002f;
    temp_r3_632 = this->unk10;
    temp_r3_632->unk388 = 500.0f;
    temp_f1_634 = temp_r3_632->unk388;
    var_f2_635 = temp_r3_632->unk33C;
    temp_f0_636 = -temp_f1_634;
    if (var_f2_635 < temp_f1_634) {

    } else {
        var_f2_635 = temp_f1_634;
    }
    if (var_f2_635 > temp_f0_636) {

    } else {
        var_f2_635 = temp_f0_636;
    }
    temp_r3_632->unk33C = var_f2_635;
    temp_r3_651 = this->unk10->GetCamera();
    spC = 0;
    sp8 = 0x437;
    M2C_FIELD(temp_r3_651->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp8);
    this->unk10->unk6F8.FadeIn(2, -1);
    this->unk44 = 0x37;
    this->unk3C = 0x187;
    this->unk48 = 0.0f;
    this->unk4C = 0.2f;
    this->unk50 = 1;
    this->unk51 = 1;
    this->unk4C = 0.0f;
}
#endif

s32 SpyroFallState::LongFallTransition() {
    return 0;
}

#if 0 // DRAFT: expression syntax error
void SpyroFallState::LongFallUpdate() {
    f64 sp20;
    f64 sp18;
    f64 sp8;

    sp8.GetFallVel();
    sp18 = sp8;
    sp20 = sp10;
    this->unk10->SetDesiredVelocityHoriz(*((MKVector3 *) &sp18), 3800.0f);
    this->unk10->unk3A0.YawTowards(*((MKVector3 *) &sp18), 900.0f);
    this->unk80.Update();
    LongFallTransition();
}
#endif

void SpyroFallState::LongFallExit() {
    Spyro *temp_r3_730;

    temp_r3_730 = this->unk10;
    temp_r3_730->unk428 = temp_r3_730->unk428 | 0x40000 | 1;
}

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void SpyroFallState::LongFallEnter() {
    Spyro *temp_r3_747;
    Spyro *temp_r7_775;
    f32 temp_f0_751;
    f32 temp_f1_749;
    f32 var_f2_750;

    temp_r3_747 = this->unk10;
    temp_r3_747->unk388 = 3800.0f;
    temp_f1_749 = temp_r3_747->unk388;
    var_f2_750 = temp_r3_747->unk33C;
    temp_f0_751 = -temp_f1_749;
    if (var_f2_750 < temp_f1_749) {

    } else {
        var_f2_750 = temp_f1_749;
    }
    if (var_f2_750 > temp_f0_751) {

    } else {
        var_f2_750 = temp_f0_751;
    }
    temp_r3_747->unk33C = var_f2_750;
    M2C_FIELD(this->unk10, f32 *, 0x38C) = 1900.0f;
    this->unk10->SetAnim(0x3FU, 0.17f, (Spyro::AnimScriptNode) 0, 0U, 1.0f);
    temp_r7_775 = this->unk10;
    temp_r7_775->unk428 &= 0xFFFBFFFE;
    this->unk44 = 0x40;
    this->unk3C = 0x187;
    this->unk48 = 1.0f;
    this->unk4C = 0.2f;
    this->unk50 = 1;
    this->unk51 = 1;
    this->unk51 = 0;
    this->unk50 = 0;
    this->unk35 = 0;
    this->unk80.Reset();
}
#endif

#if 0 // DRAFT: illegal type
void SpyroFallState::FallTransition() {
    f64 sp10;
    f64 sp8;
    InputModifier *temp_r3_889;
    MKProp *temp_r3_830;
    f32 var_f1_902;
    s32 temp_r3_832;
    s32 temp_r3_853;
    s8 var_r3_873;
    u8 var_r31_812;
    u8 var_r4_814;
    u8 var_r4_828;
    u8 var_r4_891;
    u8 var_r5_829;
    void *temp_r3_936;
    void *temp_r6_831;
    void *var_r3_841;
    void *var_r3_858;

    var_r31_812 = 0;
    var_r4_814 = 0;
    if (((u8) this->unk38 == 0) && ((s32) M2C_FIELD(this->unk10->unk26C.unk8, s32 *, 0x16C) <= 0)) {
        var_r4_814 = 1;
    }
    if (var_r4_814 != 0) {
        var_r4_828 = 1;
        var_r5_829 = 1;
        temp_r3_830 = this->unk10->unk26C.unk8;
        temp_r6_831 = temp_r3_830 + 0x170;
        temp_r3_832 = M2C_FIELD(temp_r3_830, s32 *, 0x2D4);
        if (((u32) (-temp_r3_832 & ~temp_r3_832) >> 0x1FU) != 0) {
            if (temp_r3_832 != 0) {
                var_r3_841 = temp_r6_831 + ((temp_r3_832 - 1) * 0x58);
            } else {
                var_r3_841 = NULL;
            }
            if (!(M2C_FIELD(var_r3_841, s32 *, 0x44) & 0x08000000)) {
                var_r5_829 = 0;
            }
        }
        if (var_r5_829 == 0) {
            temp_r3_853 = M2C_FIELD(temp_r6_831, s32 *, 0x164);
            if (temp_r3_853 != 0) {
                var_r3_858 = temp_r6_831 + ((temp_r3_853 - 1) * 0x58);
            } else {
                var_r3_858 = NULL;
            }
            if (M2C_FIELD(var_r3_858, s32 *, 0x44) & 3) {
                var_r4_828 = 0;
            }
        }
        if (var_r4_828 != 0) {
            var_r31_812 = 1;
        }
    }
    var_r3_873 = this->unk10->SpikyTransition();
    if ((u8) var_r3_873 == 0) {
        var_r3_873 = this->unk10->LavaTransition();
    }
    if ((u8) var_r3_873 == 0) {
        var_r3_873 = this->unk10->AirToStrafeDodgeTransition();
    }
    if ((u8) var_r3_873 == 0) {
        if (var_r31_812 != 0) {
            temp_r3_889 = this->unk10->GetInput();
            var_r4_891 = 0;
            if (((u8) temp_r3_889->unk5 != 0) || ((u8) temp_r3_889->unk4 != 0)) {
                var_r4_891 = 1;
            }
            if (var_r4_891 != 0) {
                var_f1_902 = 0.0f;
            } else {
                var_f1_902 = MKInput_GetState(0xE, (MKInputDevices) temp_r3_889->unk0, NULL, NULL);
            }
            var_r31_812 = var_f1_902 != 0.0f;
        }
        if ((var_r31_812 != 0) && ((s32) this->unk14.unk0 != 2)) {
            this->unk14.SetState(this, 2, 0U);
            var_r3_873 = 1;
        } else {
            var_r3_873 = 0;
        }
    }
    if ((u8) var_r3_873 == 0) {
        temp_r3_936 = this->unk10->unk8;
        sp8 = M2C_FIELD(temp_r3_936, f64 *, 0x30);
        sp10 = M2C_FIELD(temp_r3_936, f64 *, 0x38);
        if (((this->unk28 - unkspC) > 1300.0f) && ((s32) this->unk14.unk0 != 1)) {
            this->unk14.SetState(this, 1, 0U);
            var_r3_873 = 1;
        } else {
            var_r3_873 = 0;
        }
    }
    if ((u8) var_r3_873 == 0) {
        this->unk10->TailSweepTailStrikeTransition();
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void SpyroFallState::FallUpdate() {
    f64 sp20;
    f64 sp18;
    f64 sp8;
    f32 var_f1_1042;

    if ((u8) this->unk39 == 0) {
        if (this->unk5C.IsAnimInTable(this->unk10, this->unk10->GetAnimScript((Spyro::AnimScriptNode) 0)->unk20) != 0) {
            this->unk5C.Update(this->unk10);
        }
        if (this->unk54.IsAnimInTable(this->unk10, this->unk10->GetAnimScript((Spyro::AnimScriptNode) 0)->unk20) != 0) {
            this->unk54.Update(this->unk10);
        }
        if (this->unk64.IsAnimInTable(this->unk10, this->unk10->GetAnimScript((Spyro::AnimScriptNode) 0)->unk20) != 0) {
            this->unk64.Update(this->unk10);
        }
    }
    sp8.GetFallVel();
    sp18 = sp8;
    sp20 = sp10;
    this->unk10->SetDesiredVelocityHoriz(*((MKVector3 *) &sp18), 3800.0f);
    if (this->unk10->IsPlayingStrafeAnim() == 0) {
        if ((u8) this->unk34 != 0) {
            var_f1_1042 = 3.5f;
        } else {
            var_f1_1042 = 900.0f;
        }
        this->unk10->unk3A0.YawTowards(*((MKVector3 *) &sp18), var_f1_1042);
    }
    this->unk80.Update();
    FallTransition();
}
#endif

void SpyroFallState::FallExit() {
    Spyro *temp_r3_1063;

    temp_r3_1063 = this->unk10;
    temp_r3_1063->unk428 &= 0xFFFF7FFF;
}

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void SpyroFallState::FallEnter() {
    f64 sp10;
    f64 sp8;
    Spyro *temp_r3_1087;
    Spyro *temp_r3_1108;
    f32 temp_f0_1091;
    f32 temp_f1_1089;
    f32 var_f2_1090;
    void *temp_r3_1080;

    temp_r3_1080 = this->unk10->unk8;
    sp8 = M2C_FIELD(temp_r3_1080, f64 *, 0x30);
    sp10 = M2C_FIELD(temp_r3_1080, f64 *, 0x38);
    this->unk28 = unkspC;
    temp_r3_1087 = this->unk10;
    temp_r3_1087->unk388 = 3800.0f;
    temp_f1_1089 = temp_r3_1087->unk388;
    var_f2_1090 = temp_r3_1087->unk33C;
    temp_f0_1091 = -temp_f1_1089;
    if (var_f2_1090 < temp_f1_1089) {

    } else {
        var_f2_1090 = temp_f1_1089;
    }
    if (var_f2_1090 > temp_f0_1091) {

    } else {
        var_f2_1090 = temp_f0_1091;
    }
    temp_r3_1087->unk33C = var_f2_1090;
    M2C_FIELD(this->unk10, f32 *, 0x38C) = 1900.0f;
    temp_r3_1108 = this->unk10;
    temp_r3_1108->unk428 |= 0x8000;
    if (((u8) this->unk3A != 0) || (((u32) this->unk10->GetAnimScript((Spyro::AnimScriptNode) 0)->unk20 != 0U) && ((u32) this->unk10->GetAnimScript((Spyro::AnimScriptNode) 0)->unk20 == (u32) M2C_FIELD(this->unk10->unkB4, u32 *, 0x194)))) {
        this->unk5C.Start(this->unk10, 0.1f);
        this->unk44 = 0x3E;
        this->unk3C = 0x187;
        this->unk48 = 0.0f;
        this->unk4C = 0.2f;
        this->unk50 = 1;
        this->unk51 = 1;
    } else if ((u8) this->unk38 != 0) {
        this->unk64.Start(this->unk10, 0.0f);
        this->unk44 = 0x1C;
        this->unk3C = 0x187;
        this->unk48 = 0.0f;
        this->unk4C = 0.2f;
        this->unk50 = 1;
        this->unk51 = 1;
    } else if ((u8) this->unk39 != 0) {
        this->unk10->SetAnim(0x3CU, 0.167f, (Spyro::AnimScriptNode) 0, 0U, 1.0f);
        this->unk44 = 0x3D;
        this->unk3C = 0x187;
        this->unk48 = 0.0f;
        this->unk4C = 0.2f;
        this->unk50 = 1;
        this->unk51 = 1;
        this->unk4C = 0.1f;
    } else {
        this->unk54.Start(this->unk10, 0.1f);
        this->unk44 = 0x3D;
        this->unk3C = 0x187;
        this->unk48 = 0.0f;
        this->unk4C = 0.2f;
        this->unk50 = 1;
        this->unk51 = 1;
        this->unk4C = 0.1f;
    }
    this->unk80.Reset();
}
#endif

#if 0 // DRAFT: undefined identifier 'TeleportMsg'
void SpyroFallState::Message(MKMessage *arg0) {
    f64 sp10;
    f64 sp8;
    Spyro *temp_r3_1251;
    s32 temp_r0_1228;
    void *temp_r31_1242;
    void *temp_r4_1253;

    temp_r0_1228 = arg0->unk0;
    switch (temp_r0_1228) {                         /* irregular */
    case 0x38:
    case 0xE:
        temp_r31_1242 = checked_cast<TeleportMsg *, MKMessage>(arg0);
        if (this->unk14.GetState() == 0) {
            this->unk28 = M2C_FIELD(temp_r31_1242, f32 *, 0xC);
            return;
        }
        return;
    case 0xA3:
        temp_r3_1251 = this->unk10;
        temp_r4_1253 = temp_r3_1251->unk8;
        sp8 = M2C_FIELD(temp_r4_1253, f64 *, 0x30);
        sp10 = M2C_FIELD(temp_r4_1253, f64 *, 0x38);
        if ((this->unk28 - unkspC) > 1300.0f) {
            temp_r3_1251->TryChangeState(1U, 0xAU, (SpyroStateMsg) 0x188, 1U);
        }
        break;
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'long' to
u8 SpyroFallState::Transition() {
    s8 sp81;
    s8 sp80;
    s32 sp7C;
    f32 sp78;
    s32 sp74;
    s8 sp72;
    s8 sp71;
    s8 sp70;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    s32 sp5C;
    s32 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    s32 sp34;
    s32 sp30;
    f64 sp28;
    f64 sp20;
    s32 spC;
    s32 sp8;
    InputModifier *temp_r3_1307;
    InputModifier *temp_r3_1357;
    InputModifier *temp_r3_1699;
    MKProp *temp_r3_1434;
    MKProp *temp_r4_1390;
    MKProp *temp_r4_1661;
    MKProp *temp_r4_1748;
    MKProp *temp_r4_1807;
    MKProp *temp_r4_1828;
    MKProp *temp_r5_1554;
    MKProp *temp_r5_1577;
    Spyro *temp_r3_1287;
    Spyro *temp_r3_1552;
    Spyro *temp_r3_1660;
    Spyro *temp_r3_1747;
    Spyro *temp_r3_1806;
    Spyro *temp_r6_1389;
    f32 var_f1_1712;
    s32 *var_r18_1771;
    s32 temp_cr0_gt_1392;
    s32 temp_r0_1391;
    s32 temp_r3_1436;
    s32 temp_r4_1663;
    s32 temp_r4_1750;
    s32 temp_r4_1809;
    s32 temp_r4_1831;
    s32 temp_r5_1556;
    s32 temp_r5_1579;
    s32 var_ctr_1396;
    s32 var_r0_1570;
    s32 var_r0_1593;
    s32 var_r0_1764;
    s32 var_r3_1320;
    s32 var_r3_1370;
    s32 var_r3_1395;
    u32 temp_r29_1294;
    u32 var_r0_1430;
    u32 var_r0_1677;
    u32 var_r0_1823;
    u32 var_r0_1845;
    u8 var_r0_1343;
    u8 var_r18_1341;
    u8 var_r18_1532;
    u8 var_r19_1539;
    u8 var_r19_1637;
    u8 var_r19_1777;
    u8 var_r19_1804;
    u8 var_r20_1538;
    u8 var_r20_1684;
    u8 var_r21_1537;
    u8 var_r21_1687;
    u8 var_r22_1536;
    u8 var_r22_1688;
    u8 var_r23_1535;
    u8 var_r24_1534;
    u8 var_r25_1533;
    u8 var_r26_1531;
    u8 var_r27_1529;
    u8 var_r28_1285;
    u8 var_r28_1340;
    u8 var_r31_1284;
    u8 var_r4_1309;
    u8 var_r4_1359;
    u8 var_r4_1553;
    u8 var_r4_1701;
    u8 var_r5_1286;
    void *temp_r5_1399;
    void *temp_r6_1422;
    void *var_r3_1445;
    void *var_r4_1672;
    void *var_r4_1759;
    void *var_r4_1818;
    void *var_r4_1840;
    void *var_r5_1565;
    void *var_r5_1588;

    var_r31_1284 = 0;
    var_r28_1285 = 0;
    var_r5_1286 = 0;
    temp_r3_1287 = this->unk10;
    temp_r29_1294 = M2C_FIELD(temp_r3_1287->unk26C.unk8, s32 *, 0x16C) > 0;
    if ((u8) this->unk38 == 0) {
        M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
        if (M2C_FIELD(&gb, f32 *, 0x30C) != this->unk2C) {
            var_r5_1286 = 1;
        }
    }
    if (var_r5_1286 != 0) {
        temp_r3_1307 = temp_r3_1287->GetInput();
        var_r4_1309 = 0;
        if (((u8) temp_r3_1307->unk5 != 0) || ((u8) temp_r3_1307->unk4 != 0)) {
            var_r4_1309 = 1;
        }
        if (var_r4_1309 != 0) {
            var_r3_1320 = 0;
        } else {
            var_r3_1320 = MKInput_Pressed(0xE, (MKInputDevices) temp_r3_1307->unk0);
        }
        if ((u8) var_r3_1320 != 0) {
            var_r28_1285 = 1;
        }
    }
    if ((var_r28_1285 != 0) && ((s32) this->unk10->unk54.unkC != 8)) {
        var_r31_1284 = 1;
    }
    var_r28_1340 = 0;
    var_r18_1341 = 0;
    var_r0_1343 = 0;
    if ((u8) this->unk38 == 0) {
        M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
        if (M2C_FIELD(&gb, f32 *, 0x30C) != this->unk30) {
            var_r0_1343 = 1;
        }
    }
    if (var_r0_1343 != 0) {
        temp_r3_1357 = this->unk10->GetInput();
        var_r4_1359 = 0;
        if (((u8) temp_r3_1357->unk5 != 0) || ((u8) temp_r3_1357->unk4 != 0)) {
            var_r4_1359 = 1;
        }
        if (var_r4_1359 != 0) {
            var_r3_1370 = 0;
        } else {
            var_r3_1370 = MKInput_Pressed(0xE, (MKInputDevices) temp_r3_1357->unk0);
        }
        if ((u8) var_r3_1370 != 0) {
            var_r18_1341 = 1;
        }
    }
    if ((var_r18_1341 != 0) && ((s32) this->unk10->unk54.unkC != 8)) {
        var_r28_1340 = 1;
    }
    temp_r6_1389 = this->unk10;
    temp_r4_1390 = temp_r6_1389->unk26C.unk8;
    temp_r0_1391 = M2C_FIELD(temp_r4_1390, s32 *, 0x2D4);
    temp_cr0_gt_1392 = temp_r0_1391 > 0;
    if (temp_cr0_gt_1392 != 0) {
        var_r3_1395 = 0;
        var_ctr_1396 = temp_r0_1391;
        if (temp_cr0_gt_1392 != 0) {
            do {
                temp_r5_1399 = temp_r4_1390 + var_r3_1395;
                if ((M2C_FIELD(temp_r5_1399, s32 *, 0x1B4) & 1) && (M2C_FIELD(temp_r5_1399, f32 *, 0x184) > 0.5f)) {
                    var_r31_1284 = 0;
                }
                var_r3_1395 += 0x58;
                var_ctr_1396 -= 1;
            } while (var_ctr_1396 != 0);
        }
    }
    M2C_FIELD(temp_r6_1389, s8 *, 0x3D2) = 0;
    spC = 0;
    sp8 = 0x176;
    if (temp_r29_1294 != 0) {
        temp_r6_1422 = this->unk10->unk8;
        sp20 = M2C_FIELD(temp_r6_1422, f64 *, 0x30);
        sp28 = M2C_FIELD(temp_r6_1422, f64 *, 0x38);
        if (sp20.IsWithin(*NULL, NULL, (s32 *) temp_r6_1422) != 0) {
            var_r0_1430 = 0x01000000;
        } else {
            temp_r3_1434 = this->unk10->unk26C.unk8;
            temp_r3_1436 = M2C_FIELD(temp_r3_1434, s32 *, 0x16C);
            if (((u32) (-temp_r3_1436 & ~temp_r3_1436) >> 0x1FU) != 0) {
                if (temp_r3_1436 != 0) {
                    var_r3_1445 = &temp_r3_1434->unk8 + ((temp_r3_1436 - 1) * 0x58);
                } else {
                    var_r3_1445 = NULL;
                }
                var_r0_1430 = M2C_FIELD(var_r3_1445, u32 *, 0x44);
            } else {
                var_r0_1430 = 0;
            }
        }
        Landed(1U);
        this->unk10->SetDesiredVelocityVectical(0.0f, 540000.0f);
        if (this->unk14.GetState() == 1) {
            sp34 = 0;
            sp30 = 7;
            sp58 = 0;
            sp5C = 0;
            sp38 = M2C_FIELD(&zero, f64 *, 0);
            sp40 = M2C_FIELD(&zero, f64 *, 8);
            sp70 = 0;
            sp7C = 2;
            sp78 = 5.0f;
            sp71 = 0;
            sp72 = 1;
            sp74 = -1;
            sp48 = M2C_FIELD(&one, f64 *, 0);
            sp50 = M2C_FIELD(&one, f64 *, 8);
            sp80 = 0;
            sp60 = 0.0f;
            sp64 = 0.0f;
            sp68 = 0.0f;
            sp81 = 0;
            this->unk10->Hurt((HurtMessage *) &sp30);
            if ((s32) this->unk10->unk54.unk8 == 0xA) {
                return 1U;
            }
            KDSound_Play(GS_SpyroFlinch1, var_r0_1430, -1);
            goto block_52;
        }
block_52:
        KDSound_Play(GS_SpyroLand, var_r0_1430, 0xFF);
        goto block_53;
    }
block_53:
    var_r27_1529 = 1;
    var_r26_1531 = 1;
    var_r18_1532 = 0;
    var_r25_1533 = 1;
    var_r24_1534 = 1;
    var_r23_1535 = 1;
    var_r22_1536 = 1;
    var_r21_1537 = 1;
    var_r20_1538 = 1;
    var_r19_1539 = 1;
    if ((this->unk10->LavaTransition() != 0) || (this->unk10->SpikyTransition() != 0)) {
        var_r18_1532 = 1;
    }
    if (var_r18_1532 == 0) {
        temp_r3_1552 = this->unk10;
        var_r4_1553 = 0;
        temp_r5_1554 = temp_r3_1552->unk26C.unk8;
        temp_r5_1556 = M2C_FIELD(temp_r5_1554, s32 *, 0x16C);
        if (((u32) (-temp_r5_1556 & ~temp_r5_1556) >> 0x1FU) != 0) {
            if (temp_r5_1556 != 0) {
                var_r5_1565 = &temp_r5_1554->unk8 + ((temp_r5_1556 - 1) * 0x58);
            } else {
                var_r5_1565 = NULL;
            }
            var_r0_1570 = M2C_FIELD(var_r5_1565, s32 *, 0x44);
        } else {
            var_r0_1570 = 0;
        }
        if (var_r0_1570 & 3) {
            temp_r5_1577 = temp_r3_1552->unk26C.unk8;
            temp_r5_1579 = M2C_FIELD(temp_r5_1577, s32 *, 0x16C);
            if (((u32) (-temp_r5_1579 & ~temp_r5_1579) >> 0x1FU) != 0) {
                if (temp_r5_1579 != 0) {
                    var_r5_1588 = &temp_r5_1577->unk8 + ((temp_r5_1579 - 1) * 0x58);
                } else {
                    var_r5_1588 = NULL;
                }
                var_r0_1593 = M2C_FIELD(var_r5_1588, s32 *, 0x44);
            } else {
                var_r0_1593 = 0;
            }
            if (!(var_r0_1593 & 0x08000000)) {
                var_r4_1553 = 1;
            }
        }
        if (temp_r3_1552->TryChangeState(var_r4_1553, 8U, NULL, 0U) == 0) {
            var_r19_1539 = 0;
        }
    }
    if ((var_r19_1539 == 0) && (this->unk10->TryChangeState(var_r31_1284, 5U, (SpyroStateMsg) 0x16F, 0U) == 0)) {
        var_r20_1538 = 0;
    }
    if ((var_r20_1538 == 0) && (this->unk10->TryChangeState(var_r28_1340, 5U, (SpyroStateMsg) 0x16E, 0U) == 0)) {
        var_r21_1537 = 0;
    }
    if (var_r21_1537 == 0) {
        var_r19_1637 = 0;
        if (((u8) this->unk35 != 0) && (this->unk10->TailSweepTailStrikeTransition() != 0)) {
            var_r19_1637 = 1;
        }
        if (var_r19_1637 == 0) {
            var_r22_1536 = 0;
        }
    }
    if (var_r22_1536 == 0) {
        this->unk10->HornDiveTranstion();
        if ((u8) M2C_ERROR(/* Read from unset register $r3 */) == 0) {
            var_r23_1535 = 0;
        }
    }
    if (var_r23_1535 == 0) {
        temp_r3_1660 = this->unk10;
        temp_r4_1661 = temp_r3_1660->unk26C.unk8;
        temp_r4_1663 = M2C_FIELD(temp_r4_1661, s32 *, 0x16C);
        if (((u32) (-temp_r4_1663 & ~temp_r4_1663) >> 0x1FU) != 0) {
            if (temp_r4_1663 != 0) {
                var_r4_1672 = &temp_r4_1661->unk8 + ((temp_r4_1663 - 1) * 0x58);
            } else {
                var_r4_1672 = NULL;
            }
            var_r0_1677 = M2C_FIELD(var_r4_1672, u32 *, 0x44);
        } else {
            var_r0_1677 = 0;
        }
        var_r20_1684 = 0;
        var_r21_1687 = 0;
        var_r22_1688 = 0;
        if ((temp_r29_1294 != 0) && (temp_r3_1660->IsPlayingStrafeAnim() != 0)) {
            var_r22_1688 = 1;
        }
        if (var_r22_1688 != 0) {
            temp_r3_1699 = this->unk10->GetInput();
            var_r4_1701 = 0;
            if (((u8) temp_r3_1699->unk5 != 0) || ((u8) temp_r3_1699->unk4 != 0)) {
                var_r4_1701 = 1;
            }
            if (var_r4_1701 != 0) {
                var_f1_1712 = 0.0f;
            } else {
                var_f1_1712 = MKInput_GetState(0xA, (MKInputDevices) temp_r3_1699->unk0, NULL, NULL);
            }
            if (var_f1_1712 != 0.0f) {
                var_r21_1687 = 1;
            }
        }
        if (var_r21_1687 != 0) {
            this->unk10->IsAgainstMatID(2);
            if ((u32) M2C_ERROR(/* Read from unset register $r3 */) == 0U) {
                var_r20_1684 = 1;
            }
        }
        if (this->unk10->TryChangeState(var_r20_1684, 2U, (MKMessage *) ((s32) &sp8 & -((var_r0_1677 >> 1U) & 1)), 0U) == 0) {
            var_r24_1534 = 0;
        }
    }
    if (var_r24_1534 == 0) {
        temp_r3_1747 = this->unk10;
        temp_r4_1748 = temp_r3_1747->unk26C.unk8;
        temp_r4_1750 = M2C_FIELD(temp_r4_1748, s32 *, 0x16C);
        if (((u32) (-temp_r4_1750 & ~temp_r4_1750) >> 0x1FU) != 0) {
            if (temp_r4_1750 != 0) {
                var_r4_1759 = &temp_r4_1748->unk8 + ((temp_r4_1750 - 1) * 0x58);
            } else {
                var_r4_1759 = NULL;
            }
            var_r0_1764 = M2C_FIELD(var_r4_1759, s32 *, 0x44);
        } else {
            var_r0_1764 = 0;
        }
        if (var_r0_1764 & 2) {
            var_r18_1771 = &sp8;
        } else {
            var_r18_1771 = &this->unk3C;
        }
        var_r19_1777 = 0;
        if ((temp_r29_1294 != 0) && ((((KDInput *) (temp_r3_1747->GetInput()))->GetLeftMag() == 0.0f) || (this->unk14.GetState() == 1))) {
            var_r19_1777 = 1;
        }
        if (this->unk10->TryChangeState(var_r19_1777, 4U, (MKMessage *) var_r18_1771, 0U) == 0) {
            var_r25_1533 = 0;
        }
    }
    if (var_r25_1533 == 0) {
        var_r19_1804 = 0;
        if (temp_r29_1294 != 0) {
            temp_r3_1806 = this->unk10;
            temp_r4_1807 = temp_r3_1806->unk26C.unk8;
            temp_r4_1809 = M2C_FIELD(temp_r4_1807, s32 *, 0x16C);
            if (((u32) (-temp_r4_1809 & ~temp_r4_1809) >> 0x1FU) != 0) {
                if (temp_r4_1809 != 0) {
                    var_r4_1818 = &temp_r4_1807->unk8 + ((temp_r4_1809 - 1) * 0x58);
                } else {
                    var_r4_1818 = NULL;
                }
                var_r0_1823 = M2C_FIELD(var_r4_1818, u32 *, 0x44);
            } else {
                var_r0_1823 = 0;
            }
            temp_r4_1828 = temp_r3_1806->unk26C.unk8;
            temp_r4_1831 = M2C_FIELD(temp_r4_1828, s32 *, 0x16C);
            if (((u32) (-temp_r4_1831 & ~temp_r4_1831) >> 0x1FU) != 0) {
                if (temp_r4_1831 != 0) {
                    var_r4_1840 = &temp_r4_1828->unk8 + ((temp_r4_1831 - 1) * 0x58);
                } else {
                    var_r4_1840 = NULL;
                }
                var_r0_1845 = M2C_FIELD(var_r4_1840, u32 *, 0x44);
            } else {
                var_r0_1845 = 0;
            }
            if (temp_r3_1806->LandToMoveTransition(((var_r0_1845 >> 1U) & 1) ^ 1, ((var_r0_1823 >> 1U) & 1) == 0) != 0) {
                var_r19_1804 = 1;
            }
        }
        if (var_r19_1804 == 0) {
            var_r26_1531 = 0;
        }
    }
    if ((var_r26_1531 == 0) && (this->unk10->AirToLedgeGrabTransition() == 0)) {
        var_r27_1529 = 0;
    }
    return var_r27_1529;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'long' to
void SpyroFallState::Update() {
    f64 spA8;
    f64 spA0;
    s32 sp9C;
    s32 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;                                       /* compiler-managed */
    f64 sp68;                                       /* compiler-managed */
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
    s32 sp10;
    s32 spC;
    f32 sp8;
    InputModifier *temp_r3_1892;
    KDCamera *temp_r3_1918;
    f32 var_f1_1905;
    f32 var_f4_1969;
    f32 var_f5_1986;
    f64 temp_f1_1991;
    f64 temp_f1_1997;
    f64 temp_f1_2001;
    s32 temp_r3_2020;
    s32 var_r0_2030;
    u8 var_r4_1894;
    void *temp_r3_1956;
    void *temp_r5_1955;

    if ((u8) this->unk38 != 0) {
        temp_r3_1892 = this->unk10->GetInput();
        var_r4_1894 = 0;
        if (((u8) temp_r3_1892->unk5 != 0) || ((u8) temp_r3_1892->unk4 != 0)) {
            var_r4_1894 = 1;
        }
        if (var_r4_1894 != 0) {
            var_f1_1905 = 0.0f;
        } else {
            var_f1_1905 = MKInput_GetState(0xA, (MKInputDevices) temp_r3_1892->unk0, NULL, NULL);
        }
        if (var_f1_1905 == 0.0f) {
            temp_r3_1918 = this->unk10->GetCamera();
            sp10 = 0;
            spC = 0x433;
            M2C_FIELD(temp_r3_1918->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&spC);
            SetStrafeJump(0U);
        } else {
            this->unk10->unkB90.GetCurrentTarget();
            if ((u32) M2C_ERROR(/* Read from unset register $r3 */) == 0U) {
                this->unk10->SelectStrafeTarget(0U);
            }
            this->unk10->unkB90.GetCurrentTarget();
            if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
                this->unk10->unkB90.GetCurrentTarget();
                temp_r5_1955 = M2C_FIELD(M2C_FIELD(*M2C_ERROR(/* Read from unset register $r3 */), void *(**)(), 8)(), void **, 8);
                temp_r3_1956 = this->unk10->unk8;
                sp78 = M2C_FIELD(temp_r5_1955, f64 *, 0x30);
                sp58 = M2C_FIELD(temp_r3_1956, f64 *, 0x30);
                sp80 = M2C_FIELD(temp_r5_1955, f64 *, 0x38);
                sp60 = M2C_FIELD(temp_r3_1956, f64 *, 0x38);
                M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
                var_f4_1969 = 0.0f;
                sp68 = sp28;
                unksp6C = 0.0f;
                sp30 = (f32) sp80 - (f32) sp60;
                sp70 = (f64) sp30;
                var_f5_1986 = ((f32) sp70 * (f32) sp70) + (((f32) sp68 * (f32) sp68) + (0.0f * 0.0f));
                if (var_f5_1986 > 0.000001f) {
                    if (var_f5_1986 > 0.0f) {
                        temp_f1_1991 = __frsqrte(var_f5_1986);
                        temp_f1_1997 = 0.5 * temp_f1_1991 * -(((f64) var_f5_1986 * (temp_f1_1991 * temp_f1_1991)) - 3.0);
                        temp_f1_2001 = 0.5 * temp_f1_1997 * -(((f64) var_f5_1986 * (temp_f1_1997 * temp_f1_1997)) - 3.0);
                        var_f5_1986 = (f32) ((f64) var_f5_1986 * (0.5 * temp_f1_2001 * -(((f64) var_f5_1986 * (temp_f1_2001 * temp_f1_2001)) - 3.0)));
                    } else if (var_f5_1986 < M2C_BITWISE(f32, 0.0)) {
                        var_f5_1986 = __float_nan;
                    } else {
                        sp8 = var_f5_1986;
                        temp_r3_2020 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                        switch (temp_r3_2020) {     /* irregular */
                        case 0x7F800000:
                            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                var_r0_2030 = 1;
                            } else {
                                var_r0_2030 = 2;
                            }
                            break;
                        case 0x0:
                            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                var_r0_2030 = 5;
                            } else {
                                var_r0_2030 = 3;
                            }
                            break;
                        default:
                            var_r0_2030 = 4;
                            break;
                        }
                        if (var_r0_2030 == 1) {
                            var_f5_1986 = __float_nan;
                        }
                    }
                    var_f4_1969 = 1.0f / var_f5_1986;
                }
                sp68 = (f32) sp68 * var_f4_1969;
                unksp6C *= var_f4_1969;
                sp70 = (f32) sp70 * var_f4_1969;
                sp88 = (f64) sp68;
                sp90 = (f64) sp70;
                this->unk10->unk3A0.YawTowards(*((MKVector3 *) &sp68), 15.0f);
            } else {
                this->unk10->unk8->ZAxis3();
                sp18 = -*M2C_ERROR(/* Read from unset register $r3 */);
                sp1C = -M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), f32 *, 4);
                sp20 = -M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), f32 *, 8);
                sp48 = (f64) sp18;
                sp50 = (f64) sp20;
                sp88 = (f64) sp18;
                sp90 = (f64) sp20;
            }
            sp9C = 0;
            sp98 = 0x43E;
            spA0 = sp88;
            spA8 = sp90;
            sp38 = sp88;
            sp40 = sp90;
            M2C_FIELD(this->unk10->GetCamera()->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp98);
        }
    }
    this->unk14.Update(this, 0);
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void SpyroFallState::Exit() {
    s32 spC;
    s32 sp8;
    KDCamera *temp_r3_2141;
    Spyro *temp_r5_2159;

    this->unk10->SetMeleeButtonStateTimeout(0U);
    temp_r3_2141 = this->unk10->GetCamera();
    spC = 0;
    sp8 = 0x450;
    M2C_FIELD(temp_r3_2141->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp8);
    this->unk14.Exit(this);
    M2C_FIELD(this->unk10, f32 *, 0x388) = 0.0f;
    temp_r5_2159 = this->unk10;
    temp_r5_2159->unk428 |= 0x80;
    SetStrafeJump(0U);
    ((LineSegmentTrail *) (M2C_FIELD(M2C_FIELD(this->unk10->unk258, void **, 4), LineSegmentTrail **, 0xC8)))->EndTrail();
    ((LineSegmentTrail *) (M2C_FIELD(M2C_FIELD(this->unk10->unk258, void **, 4), LineSegmentTrail **, 0xCC)))->EndTrail();
}
#endif

#if 0 // DRAFT: undefined identifier 'unksp1C'
void SpyroFallState::Enter(SpyroStateMessages &arg0) {
    s32 sp30;
    s32 sp2C;
    s32 sp28;
    f64 sp20;
    f64 sp18;
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    KDCamera *temp_r3_2309;
    KDCamera *temp_r3_2320;
    Spyro *temp_r3_2200;
    Spyro *temp_r5_2194;
    Spyro *temp_r6_2247;
    f32 temp_f0_2204;
    f32 temp_f1_2202;
    f32 var_f2_2203;
    s32 temp_r3_2248;
    s32 var_r0_2341;
    s32 var_r29_2346;
    u8 var_r0_2246;
    void *temp_r3_2381;
    void *temp_r5_2262;

    temp_r5_2194 = this->unk10;
    temp_r5_2194->unk428 &= 0xFFFDFFDF;
    M2C_FIELD(this->unk10, f32 *, 0x388) = 0.5f;
    temp_r3_2200 = this->unk10;
    temp_r3_2200->unk388 = 3800.0f;
    temp_f1_2202 = temp_r3_2200->unk388;
    var_f2_2203 = temp_r3_2200->unk33C;
    temp_f0_2204 = -temp_f1_2202;
    if (var_f2_2203 < temp_f1_2202) {

    } else {
        var_f2_2203 = temp_f1_2202;
    }
    if (var_f2_2203 > temp_f0_2204) {

    } else {
        var_f2_2203 = temp_f0_2204;
    }
    temp_r3_2200->unk33C = var_f2_2203;
    M2C_FIELD(this->unk10, f32 *, 0x38C) = 1900.0f;
    this->unk2C = 0.0f;
    this->unk30 = 0.0f;
    this->unk44 = 0x3D;
    this->unk3C = 0x187;
    this->unk48 = 0.0f;
    this->unk4C = 0.2f;
    this->unk50 = 1;
    this->unk51 = 1;
    this->unk35 = 1;
    this->unk38 = 0;
    this->unk3A = 0;
    this->unk39 = arg0.IsMessageOnList(0x175);
    this->unk3A = arg0.IsMessageOnList(0x182);
    var_r0_2246 = 1;
    temp_r6_2247 = this->unk10;
    temp_r3_2248 = temp_r6_2247->unk54.unkC;
    if ((temp_r3_2248 != 9) && (temp_r3_2248 != 4)) {
        var_r0_2246 = 0;
    }
    temp_r6_2247->unk3CC = var_r0_2246 != 0;
    temp_r5_2262 = this->unk10->unk8;
    sp18 = M2C_FIELD(temp_r5_2262, f64 *, 0x30);
    sp20 = M2C_FIELD(temp_r5_2262, f64 *, 0x38);
    this->unk28 = unksp1C;
    this->unk34 = arg0.IsMessageOnList(0x17D);
    this->unk36 = this->unk10->unk430.unk28.GetTailSweepEnabled();
    if (arg0.IsMessageOnList(0x170) != 0) {
        this->unk2C = M2C_FIELD(&gb, f32 *, 0x30C) + 0.1667f;
    }
    if (arg0.IsMessageOnList(0x16F) != 0) {
        this->unk30 = M2C_FIELD(&gb, f32 *, 0x30C) + 0.1667f;
    }
    if (arg0.IsMessageOnList(0x178) != 0) {
        SetStrafeJump(1U);
    }
    temp_r3_2309 = this->unk10->GetCamera();
    sp14 = 0;
    sp10 = 0x44F;
    M2C_FIELD(temp_r3_2309->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp10);
    temp_r3_2320 = this->unk10->GetCamera();
    spC = 0;
    sp8 = 0x414;
    M2C_FIELD(temp_r3_2320->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp8);
    if (arg0.IsMessageOnList(0x16D) != 0) {
        if (((KDInput *) (this->unk10->GetInput()))->GetLeftMag() != 0.0f) {
            var_r0_2341 = 2;
        } else {
            var_r0_2341 = 3;
        }
        var_r29_2346 = var_r0_2341;
    } else {
        var_r29_2346 = 0;
    }
    if (arg0.IsMessageOnList(0x174) != 0) {
        this->unk44 = 0x45;
        this->unk3C = 0x187;
        this->unk48 = 0.0f;
        this->unk4C = 0.2f;
        this->unk50 = 1;
        this->unk51 = 1;
    }
    this->unk14.SetState(this, var_r29_2346, 0U);
    sp2C = 0;
    sp28 = 0x17;
    sp30 = 0xA;
    temp_r3_2381 = this->unk10->unkB70;
    M2C_FIELD(M2C_FIELD(temp_r3_2381, void **, 0x44), M2C_UNK (**)(void *, s32 *), 0x2C)(temp_r3_2381, &sp28);
    this->unk10->SetMeleeButtonStateTimeout(1U);
}
#endif

#if 0 // DRAFT: undefined identifier 'unk14'
void SpyroFallState::Deinit() {
    this->unk14.Deinit(this);
}
#endif

#if 0 // DRAFT: undefined identifier 'Init__32KDStateMachine'
void SpyroFallState::Init(Spyro *arg0) {
    this->unk10 = arg0;
    Init__32KDStateMachine<14SpyroFallState>FPQ232KDStateMachine<14SpyroFallState>5StateP32KDStateMachine<14SpyroFallState>(&this->unk14, (KDStateMachine<SpyroFallState>::State *) &states, NULL);
    this->unk44 = 0x3D;
    this->unk3C = 0x187;
    this->unk48 = 0.0f;
    this->unk4C = 0.2f;
    this->unk50 = 1;
    this->unk51 = 1;
    this->unk28 = 0.0f;
    this->unk2C = 0.0f;
    this->unk30 = 0.0f;
    this->unk34 = 0;
    this->unk35 = 0;
    this->unk36 = 0;
    this->unk37 = 1;
    this->unk39 = 0;
    this->unk3A = 0;
    this->unk54.unk0 = 0x3B;
    this->unk54.unk4 = 0x3C;
    this->unk5C.unk0 = 0x33;
    this->unk5C.unk4 = 0x34;
    this->unk64.unk0 = 0x1A;
    this->unk64.unk4 = 0x1B;
    this->unk6C.unk0 = 0x35;
    this->unk6C.unk4 = 0x36;
    this->unk74.unk0 = 0x38;
    this->unk74.unk4 = 0x39;
    this->unk80.Init((MKProp *) this->unk10);
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_728'
void SpyroFallState_cpp::__sinit() {
    f64 temp_f0_2773;
    f64 temp_f1_2743;
    f64 temp_f1_2767;
    f64 temp_f3_2729;
    f64 temp_f3_2770;
    f64 temp_f4_2742;
    f64 temp_f4_2764;
    f64 temp_f8_2731;
    void *temp_r3_2734;

    temp_f3_2729 = __frsqrte(2014000.0);
    temp_f8_2731 = __frsqrte(380000.0);
    temp_r3_2734 = &lit_728 + 0x90;
    temp_f4_2742 = 0.5 * temp_f3_2729 * -((2014000.0 * (temp_f3_2729 * temp_f3_2729)) - 3.0);
    temp_f1_2743 = 0.5 * temp_f8_2731 * -((380000.0 * (temp_f8_2731 * temp_f8_2731)) - 3.0);
    temp_f4_2764 = 0.5 * temp_f4_2742 * -((2014000.0 * (temp_f4_2742 * temp_f4_2742)) - 3.0);
    temp_f1_2767 = 0.5 * temp_f1_2743 * -((380000.0 * (temp_f1_2743 * temp_f1_2743)) - 3.0);
    temp_f3_2770 = temp_f4_2764 * temp_f4_2764;
    temp_f0_2773 = temp_f1_2767 * temp_f1_2767;
    M2C_FIELD(&lit_728, s32 *, 0x90) = (s32) M2C_FIELD(&lit_728, s32 *, 0);
    M2C_FIELD(&lit_728, s32 *, 0x94) = (s32) M2C_FIELD(&lit_728, s32 *, 4);
    M2C_FIELD(&lit_728, s32 *, 0x98) = (s32) M2C_FIELD(&lit_728, s32 *, 8);
    M2C_FIELD(temp_r3_2734, s32 *, 0xC) = (s32) M2C_FIELD(&lit_728, s32 *, 0xC);
    M2C_FIELD(temp_r3_2734, s32 *, 0x10) = (s32) M2C_FIELD(&lit_728, s32 *, 0x10);
    M2C_FIELD(temp_r3_2734, s32 *, 0x14) = (s32) M2C_FIELD(&lit_728, s32 *, 0x14);
    M2C_FIELD(temp_r3_2734, s32 *, 0x18) = (s32) M2C_FIELD(&lit_728, s32 *, 0x18);
    M2C_FIELD(temp_r3_2734, s32 *, 0x1C) = (s32) M2C_FIELD(&lit_728, s32 *, 0x1C);
    M2C_FIELD(temp_r3_2734, s32 *, 0x20) = (s32) M2C_FIELD(&lit_728, s32 *, 0x20);
    M2C_FIELD(temp_r3_2734, s32 *, 0x24) = (s32) M2C_FIELD(&lit_728, s32 *, 0x24);
    M2C_FIELD(temp_r3_2734, s32 *, 0x28) = (s32) M2C_FIELD(&lit_728, s32 *, 0x28);
    M2C_FIELD(temp_r3_2734, s32 *, 0x2C) = (s32) M2C_FIELD(&lit_728, s32 *, 0x2C);
    M2C_FIELD(temp_r3_2734, s32 *, 0x30) = (s32) M2C_FIELD(&lit_728, s32 *, 0x30);
    M2C_FIELD(temp_r3_2734, s32 *, 0x34) = (s32) M2C_FIELD(&lit_728, s32 *, 0x34);
    M2C_FIELD(temp_r3_2734, s32 *, 0x38) = (s32) M2C_FIELD(&lit_728, s32 *, 0x38);
    M2C_FIELD(temp_r3_2734, s32 *, 0x3C) = (s32) M2C_FIELD(&lit_728, s32 *, 0x3C);
    M2C_FIELD(temp_r3_2734, s32 *, 0x40) = (s32) M2C_FIELD(&lit_728, s32 *, 0x40);
    M2C_FIELD(temp_r3_2734, s32 *, 0x44) = (s32) M2C_FIELD(&lit_728, s32 *, 0x44);
    SPYRO_BOUNCE_Y_SPEED = (f32) (2014000.0 * (0.5 * temp_f4_2764 * -((2014000.0 * temp_f3_2770) - 3.0)));
    SPYRO_MIN_JUMP_Y_VELOCITY = (f32) (380000.0 * (0.5 * temp_f1_2767 * -((380000.0 * temp_f0_2773) - 3.0)));
    M2C_FIELD(temp_r3_2734, s32 *, 0x48) = (s32) M2C_FIELD(&lit_728, s32 *, 0x48);
    M2C_FIELD(temp_r3_2734, s32 *, 0x4C) = (s32) M2C_FIELD(&lit_728, s32 *, 0x4C);
    M2C_FIELD(temp_r3_2734, s32 *, 0x50) = (s32) M2C_FIELD(&lit_728, s32 *, 0x50);
    M2C_FIELD(temp_r3_2734, s32 *, 0x54) = (s32) M2C_FIELD(&lit_728, s32 *, 0x54);
    M2C_FIELD(temp_r3_2734, s32 *, 0x58) = (s32) M2C_FIELD(&lit_728, s32 *, 0x58);
    M2C_FIELD(temp_r3_2734, s32 *, 0x5C) = (s32) M2C_FIELD(&lit_728, s32 *, 0x5C);
    M2C_FIELD(temp_r3_2734, s32 *, 0x60) = (s32) M2C_FIELD(&lit_728, s32 *, 0x60);
    M2C_FIELD(temp_r3_2734, s32 *, 0x64) = (s32) M2C_FIELD(&lit_728, s32 *, 0x64);
    M2C_FIELD(temp_r3_2734, s32 *, 0x68) = (s32) M2C_FIELD(&lit_728, s32 *, 0x68);
    M2C_FIELD(temp_r3_2734, s32 *, 0x6C) = (s32) M2C_FIELD(&lit_728, s32 *, 0x6C);
    M2C_FIELD(temp_r3_2734, s32 *, 0x70) = (s32) M2C_FIELD(&lit_728, s32 *, 0x70);
    M2C_FIELD(temp_r3_2734, s32 *, 0x74) = (s32) M2C_FIELD(&lit_728, s32 *, 0x74);
    M2C_FIELD(temp_r3_2734, s32 *, 0x78) = (s32) M2C_FIELD(&lit_728, s32 *, 0x78);
    M2C_FIELD(temp_r3_2734, s32 *, 0x7C) = (s32) M2C_FIELD(&lit_728, s32 *, 0x7C);
    M2C_FIELD(temp_r3_2734, s32 *, 0x80) = (s32) M2C_FIELD(&lit_728, s32 *, 0x80);
    M2C_FIELD(temp_r3_2734, s32 *, 0x84) = (s32) M2C_FIELD(&lit_728, s32 *, 0x84);
    M2C_FIELD(temp_r3_2734, s32 *, 0x88) = (s32) M2C_FIELD(&lit_728, s32 *, 0x88);
    M2C_FIELD(temp_r3_2734, s32 *, 0x8C) = (s32) M2C_FIELD(&lit_728, s32 *, 0x8C);
}
#endif
