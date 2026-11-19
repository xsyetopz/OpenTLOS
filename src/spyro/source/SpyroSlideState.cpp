#include "spyro/source/SpyroSlideState.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "spyro/source/KDInput.h"
#include "spyro/source/Spyro.h"
#include <m2c_macros.h>

extern f32 SPYRO_BOUNCE_Y_SPEED;
extern f32 SPYRO_MIN_JUMP_Y_VELOCITY;
extern f32 gUpdateTimeDelta;
u8 states__15SpyroSlideState[0x24] = {
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

s32 SpyroSlideState::Transition() {
    MKProp *temp_r4_32;
    Spyro *temp_r3_121;
    Spyro *temp_r3_31;
    f32 temp_f0_55;
    f32 temp_f1_53;
    f32 temp_f3_58;
    s32 temp_r4_34;
    u32 var_r0_48;
    u8 var_r26_86;
    u8 var_r27_74;
    u8 var_r27_98;
    u8 var_r29_56;
    u8 var_r29_88;
    u8 var_r30_87;
    u8 var_r31_85;
    void *var_r4_43;

    temp_r3_31 = this->unk10;
    temp_r4_32 = temp_r3_31->unk26C.unk8;
    temp_r4_34 = M2C_FIELD(temp_r4_32, s32 *, 0x16C);
    if (((u32) (-temp_r4_34 & ~temp_r4_34) >> 0x1FU) != 0) {
        if (temp_r4_34 != 0) {
            var_r4_43 = &temp_r4_32->unk8 + ((temp_r4_34 - 1) * 0x58);
        } else {
            var_r4_43 = NULL;
        }
        var_r0_48 = M2C_FIELD(var_r4_43, u32 *, 0x44);
    } else {
        var_r0_48 = 0;
    }
    temp_f1_53 = temp_r3_31->unk330;
    temp_f0_55 = temp_r3_31->unk33C;
    var_r29_56 = 0;
    temp_f3_58 = temp_r3_31->unk338;
    if ((((temp_f3_58 * temp_f3_58) + ((temp_f1_53 * temp_f1_53) + (temp_f0_55 * temp_f0_55))) < 22500.0f) && (((KDInput *) (temp_r3_31->GetInput()))->GetLeftMag() != 0.0f)) {
        var_r29_56 = 1;
    }
    var_r27_74 = 0;
    if ((((u32) ((var_r0_48 >> 1U) & 1) == 0) && (var_r29_56 != 0)) || (var_r29_56 != 0)) {
        var_r27_74 = 1;
    }
    var_r31_85 = 1;
    var_r26_86 = 0;
    var_r30_87 = 1;
    var_r29_88 = 1;
    if ((var_r27_74 == 0) || (this->unk10->LandToMoveTransition(1U, 1U) == 0)) {
        var_r27_98 = 0;
        if ((var_r27_74 != 0) && (((KDInput *) (this->unk10->GetInput()))->GetLeftMag() == 0.0f)) {
            var_r27_98 = 1;
        }
        if (this->unk10->TryChangeState(var_r27_98, 4U, NULL, 0U) != 0) {
            goto block_19;
        }
    } else {
block_19:
        var_r26_86 = 1;
    }
    if (var_r26_86 == 0) {
        temp_r3_121 = this->unk10;
        if (temp_r3_121->TryChangeState((M2C_FIELD(temp_r3_121->unk26C.unk8, s32 *, 0x16C) > 0) == 0, 6U, NULL, 0U) == 0) {
            var_r29_88 = 0;
        }
    }
    if ((var_r29_88 == 0) && (this->unk10->LandToMoveTransition(1U, 1U) == 0)) {
        var_r30_87 = 0;
    }
    if (var_r30_87 == 0) {
        this->unk10->LandToAirTransition(1U, 0U, 0U);
        if ((u8) M2C_ERROR(/* Read from unset register $r3 */) == 0) {
            var_r31_85 = 0;
        }
    }
    return var_r31_85;
}

#if 0 // DRAFT: undefined identifier 'unk14'
void SpyroSlideState::Update() {
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f32 sp40;
    f64 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    Spyro *temp_r3_176;
    f32 temp_f0_181;
    f32 temp_f4_192;
    f32 var_f2_184;
    f64 temp_f0_190;
    f64 temp_f0_200;
    f64 temp_f0_210;
    f64 temp_f0_221;
    f64 temp_f3_189;

    temp_r3_176 = this->unk10;
    temp_f0_181 = 0.5f * (8.0f * gUpdateTimeDelta);
    if (temp_f0_181 < 1.0f) {
        var_f2_184 = temp_f0_181;
    } else {
        var_f2_184 = 1.0f;
    }
    temp_f3_189 = M2C_FIELD(temp_r3_176, f64 *, 0x338);
    temp_f0_190 = temp_f3_189 * (f64) var_f2_184;
    sp38 = temp_f0_190;
    temp_f4_192 = temp_r3_176->unk338;
    sp58 = temp_f0_190;
    sp40 = temp_f4_192 * var_f2_184;
    sp60 = (f64) sp40;
    temp_f0_200 = temp_f3_189 - temp_f0_190;
    sp28 = temp_f0_200;
    sp48 = temp_f0_200;
    sp30 = temp_f4_192 - (f32) sp60;
    sp50 = (f64) sp30;
    temp_f0_210 = temp_f0_200 * (f64) var_f2_184;
    sp18 = temp_f0_210;
    sp68 = temp_f0_210;
    sp20 = (f32) sp50 * var_f2_184;
    sp70 = (f64) sp20;
    temp_f0_221 = sp48 - temp_f0_210;
    sp8 = temp_f0_221;
    sp78 = temp_f0_221;
    sp10 = (f32) sp50 - (f32) sp70;
    sp80 = (f64) sp10;
    this->unk10->SetDesiredVelocity(*((MKVector3 *) &sp78), 540000.0f);
    this->unk14.Update(this, 0);
    this->unk28.Update();
}
#endif

#if 0 // DRAFT: undefined identifier 'unk14'
void SpyroSlideState::Exit() {
    this->unk14.Exit(this);
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void SpyroSlideState::Enter(SpyroStateMessages &arg0) {
    Spyro *temp_r3_275;

    temp_r3_275 = this->unk10;
    temp_r3_275->unk428 &= 0xFFFFFFFE;
    this->unk10->SetAnim(0U, 0.17f, (Spyro::AnimScriptNode) 0, 0U, 1.0f);
    Init__33KDStateMachine<15SpyroSlideState>FPQ233KDStateMachine<15SpyroSlideState>5StateP33KDStateMachine<15SpyroSlideState>(&this->unk14, (KDStateMachine<SpyroSlideState>::State *) SpyroSlideState::states, NULL);
    this->unk28.Reset();
}
#endif

#if 0 // DRAFT: undefined identifier 'unk14'
void SpyroSlideState::Deinit() {
    this->unk14.Deinit(this);
}
#endif

void SpyroSlideState::Init(Spyro *arg0) {
    this->unk10 = arg0;
    this->unk28.Init((MKProp *) arg0);
}

#if 0 // DRAFT: undefined identifier '__ptmf_null'
void SpyroSlideState_cpp::__sinit() {
    s32 sp10;
    s32 spC;
    s32 sp8;
    f64 temp_f0_504;
    f64 temp_f1_501;
    f64 temp_f1_517;
    f64 temp_f1_531;
    f64 temp_f3_495;
    f64 temp_f4_515;
    f64 temp_f4_530;
    f64 temp_f8_497;

    temp_f3_495 = __frsqrte(2014000.0);
    temp_f8_497 = __frsqrte(380000.0);
    temp_f1_501 = temp_f3_495 * temp_f3_495;
    temp_f0_504 = temp_f8_497 * temp_f8_497;
    sp8 = M2C_FIELD(&__ptmf_null, s32 *, 0);
    M2C_FIELD(SpyroSlideState::states, s32 *, 0) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 0);
    spC = M2C_FIELD(&__ptmf_null, s32 *, 4);
    sp10 = M2C_FIELD(&__ptmf_null, s32 *, 8);
    M2C_FIELD(SpyroSlideState::states, s32 *, 4) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 4);
    temp_f4_515 = 0.5 * temp_f3_495 * -((2014000.0 * temp_f1_501) - 3.0);
    M2C_FIELD(SpyroSlideState::states, s32 *, 8) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 8);
    temp_f1_517 = 0.5 * temp_f8_497 * -((380000.0 * temp_f0_504) - 3.0);
    M2C_FIELD(SpyroSlideState::states, s32 *, 0xC) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 0);
    M2C_FIELD(SpyroSlideState::states, s32 *, 0x10) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 4);
    M2C_FIELD(SpyroSlideState::states, s32 *, 0x14) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 8);
    M2C_FIELD(SpyroSlideState::states, s32 *, 0x18) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 0);
    M2C_FIELD(SpyroSlideState::states, s32 *, 0x1C) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 4);
    M2C_FIELD(SpyroSlideState::states, s32 *, 0x20) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 8);
    temp_f4_530 = 0.5 * temp_f4_515 * -((2014000.0 * (temp_f4_515 * temp_f4_515)) - 3.0);
    temp_f1_531 = 0.5 * temp_f1_517 * -((380000.0 * (temp_f1_517 * temp_f1_517)) - 3.0);
    SPYRO_BOUNCE_Y_SPEED = (f32) (2014000.0 * (0.5 * temp_f4_530 * -((2014000.0 * (temp_f4_530 * temp_f4_530)) - 3.0)));
    SPYRO_MIN_JUMP_Y_VELOCITY = (f32) (380000.0 * (0.5 * temp_f1_531 * -((380000.0 * (temp_f1_531 * temp_f1_531)) - 3.0)));
}
#endif
