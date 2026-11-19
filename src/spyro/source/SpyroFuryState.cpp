#include "spyro/source/SpyroFuryState.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKVector3.h"
#include "spyro/source/GameData.h"
#include "spyro/source/KDCamera.h"
#include "spyro/source/Spyro.h"
#include "common/Source/MKCollision.h"
#include <m2c_macros.h>

extern f32 SPYRO_BOUNCE_Y_SPEED;
extern f32 SPYRO_MIN_JUMP_Y_VELOCITY;
extern M2C_UNK gb;
u8 states__14SpyroFuryState[0x24] = {
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

void SpyroFuryState::ProcessAnimEvent(unsigned int arg0) {

}

void SpyroFuryState::Message(MKMessage *arg0) {

}

#if 0 // DRAFT: illegal explicit conversion from 'int' to
s32 SpyroFuryState::Transition() {
    s32 var_r31_70;

    if (((u8) this->unk39 == 0) && ((this->unk10->GetAnimScript((Spyro::AnimScriptNode) 0)->unk2C & 1) || ((s32) M2C_FIELD(this->unk10->unk26C.unk8, s32 *, 0x16C) > 0))) {
        if ((u8) this->unk38 != 0) {
            return this->unk10->TryChangeState(1U, 6U, (SpyroStateMsg) 0x175, 0U);
        }
        var_r31_70 = 0;
        this->unk10->LandToAirTransition(0U, 0U, 0U);
        if (((u8) M2C_ERROR(/* Read from unset register $r3 */) != 0) || (this->unk10->TryChangeState(1U, 4U, NULL, 0U) != 0)) {
            var_r31_70 = 1;
        }
        return var_r31_70;
    }
    return 0;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void SpyroFuryState::Update() {
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
    void *temp_r8_153;

    if (((u8) this->unk39 != 0) && (this->unk10->GetAnimScript((Spyro::AnimScriptNode) 0)->unk2C & 1)) {
        this->unk10->GetAnimScript((Spyro::AnimScriptNode) 0)->unk38 = 1.0f;
        if (((u8) this->unk38 != 0) || (sp18 = 0.0f, sp1C = -50.0f, sp20 = 0.0f, sp28 = (f64) sp18, sp30 = (f64) sp20, M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */), M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */), sp38 = sp8, sp10 = this->unk30 + (f32) sp30, sp40 = (f64) sp10, temp_r8_153 = this->unk10->unk8, sp48 = M2C_FIELD(temp_r8_153, f64 *, 0x30), sp50 = M2C_FIELD(temp_r8_153, f64 *, 0x38), ((MKCollision_RayCollide(*((MKVector3 *) &sp48), *((MKVector3 *) &sp38), NULL, (MKCollisionMode) 7, 0x04000000) == 0) != 0))) {
            this->unk10->SetAnim(0x49U, 0.1f, (Spyro::AnimScriptNode) 0, 0U, 1.0f);
        } else {
            this->unk10->SetAnim(0x47U, 0.1f, (Spyro::AnimScriptNode) 0, 0U, 1.0f);
        }
        this->unk39 = 0;
    }
    this->unk14.Update(this, 0);
}
#endif

#if 0 // DRAFT: undefined identifier 'unk14'
void SpyroFuryState::Exit() {
    M2C_FIELD(this->unk10, f32 *, 0x38C) = 1900.0f;
    M2C_FIELD(GameData::gameData, s32 *, 0x158) = (s32) M2C_FIELD(GameData::gameData, s32 *, 0x15C);
    this->unk10->UpdateWaterSurfaceFX(1U);
    this->unk10->SetMeleeButtonStateTimeout(0U);
    this->unk14.Exit(this);
}
#endif

#if 0 // DRAFT: undefined identifier 'unk14'
void SpyroFuryState::Enter(SpyroStateMessages &arg0) {
    s32 sp30;
    s32 sp2C;
    s32 sp28;
    f64 sp20;
    f64 sp18;
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    KDCamera *temp_r3_338;
    Spyro *temp_r3_291;
    Spyro *temp_r3_327;
    Spyro *temp_r6_282;
    f64 temp_f0_242;
    f64 temp_f1_241;
    void *temp_r3_301;
    void *temp_r4_240;

    this->unk14.SetState(this, 0, 0U);
    temp_r4_240 = this->unk10->unk8;
    temp_f1_241 = M2C_FIELD(temp_r4_240, f64 *, 0x30);
    temp_f0_242 = M2C_FIELD(temp_r4_240, f64 *, 0x38);
    sp18 = temp_f1_241;
    this->unk28 = temp_f1_241;
    M2C_FIELD(this, f64 *, 0x30) = temp_f0_242;
    this->unk39 = 1;
    this->unk38 = 0;
    sp20 = temp_f0_242;
    if (this->unk10->OnFloor() != 0) {
        this->unk10->SetAnim(0x46U, 0.2f, (Spyro::AnimScriptNode) 0, 0U, 1.0f);
        this->unk10->GetAnimScript((Spyro::AnimScriptNode) 0)->unk38 = 2.58f;
    } else {
        this->unk38 = 1;
        this->unk10->SetAnim(0x48U, 0.2f, (Spyro::AnimScriptNode) 0, 0U, 1.0f);
        this->unk10->GetAnimScript((Spyro::AnimScriptNode) 0)->unk38 = 0.75f;
    }
    temp_r6_282 = this->unk10;
    temp_r6_282->unk428 &= 0xFFF3BE5E;
    temp_r3_291 = this->unk10;
    temp_r3_291->unk428 |= 0x4000;
    this->unk10->SetDesiredVelocity(MKVector3::zero, 540000.0f);
    M2C_FIELD(this->unk10, f32 *, 0x38C) = 0.0f;
    temp_r3_301 = this->unk10->unkB70;
    if (temp_r3_301 != NULL) {
        sp2C = 0;
        sp28 = 0x17;
        sp30 = 0xF;
        M2C_FIELD(M2C_FIELD(temp_r3_301, void **, 0x44), M2C_UNK (**)(s32 *, M2C_UNK), 0x2C)(&sp28, 0x17);
    }
    this->unk10->SetMeleeButtonStateTimeout(1U);
    this->unk10->UpdateWaterSurfaceFX(1U);
    if ((u8) M2C_FIELD(&gb, u8 *, 0x35D) != 0) {
        temp_r3_327 = this->unk10;
        sp14 = 0;
        sp10 = 0xAB;
        temp_r3_327->Message(&sp10, 0);
        temp_r3_338 = this->unk10->GetCamera();
        spC = 0;
        sp8 = 0x42B;
        M2C_FIELD(temp_r3_338->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp8);
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk14'
void SpyroFuryState::Deinit() {
    this->unk14.Deinit();
}
#endif

#if 0 // DRAFT: undefined identifier 'Init__32KDStateMachine'
void SpyroFuryState::Init(Spyro *arg0) {
    this->unk10 = arg0;
    Init__32KDStateMachine<14SpyroFuryState>FPQ232KDStateMachine<14SpyroFuryState>5StateP32KDStateMachine<14SpyroFuryState>(&this->unk14, (KDStateMachine<SpyroFuryState>::State *) SpyroFuryState::states, NULL);
    this->unk38 = 0;
}
#endif

#if 0 // DRAFT: undefined identifier '__ptmf_null'
void SpyroFuryState_cpp::__sinit() {
    s32 sp10;
    s32 spC;
    s32 sp8;
    f64 temp_f0_611;
    f64 temp_f1_608;
    f64 temp_f1_624;
    f64 temp_f1_638;
    f64 temp_f3_602;
    f64 temp_f4_622;
    f64 temp_f4_637;
    f64 temp_f8_604;

    temp_f3_602 = __frsqrte(2014000.0);
    temp_f8_604 = __frsqrte(380000.0);
    temp_f1_608 = temp_f3_602 * temp_f3_602;
    temp_f0_611 = temp_f8_604 * temp_f8_604;
    sp8 = M2C_FIELD(&__ptmf_null, s32 *, 0);
    M2C_FIELD(SpyroFuryState::states, s32 *, 0) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 0);
    spC = M2C_FIELD(&__ptmf_null, s32 *, 4);
    sp10 = M2C_FIELD(&__ptmf_null, s32 *, 8);
    M2C_FIELD(SpyroFuryState::states, s32 *, 4) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 4);
    temp_f4_622 = 0.5 * temp_f3_602 * -((2014000.0 * temp_f1_608) - 3.0);
    M2C_FIELD(SpyroFuryState::states, s32 *, 8) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 8);
    temp_f1_624 = 0.5 * temp_f8_604 * -((380000.0 * temp_f0_611) - 3.0);
    M2C_FIELD(SpyroFuryState::states, s32 *, 0xC) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 0);
    M2C_FIELD(SpyroFuryState::states, s32 *, 0x10) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 4);
    M2C_FIELD(SpyroFuryState::states, s32 *, 0x14) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 8);
    M2C_FIELD(SpyroFuryState::states, s32 *, 0x18) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 0);
    M2C_FIELD(SpyroFuryState::states, s32 *, 0x1C) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 4);
    M2C_FIELD(SpyroFuryState::states, s32 *, 0x20) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 8);
    temp_f4_637 = 0.5 * temp_f4_622 * -((2014000.0 * (temp_f4_622 * temp_f4_622)) - 3.0);
    temp_f1_638 = 0.5 * temp_f1_624 * -((380000.0 * (temp_f1_624 * temp_f1_624)) - 3.0);
    SPYRO_BOUNCE_Y_SPEED = (f32) (2014000.0 * (0.5 * temp_f4_637 * -((2014000.0 * (temp_f4_637 * temp_f4_637)) - 3.0)));
    SPYRO_MIN_JUMP_Y_VELOCITY = (f32) (380000.0 * (0.5 * temp_f1_638 * -((380000.0 * (temp_f1_638 * temp_f1_638)) - 3.0)));
}
#endif
