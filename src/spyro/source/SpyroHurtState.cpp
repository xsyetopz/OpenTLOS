#include "spyro/source/SpyroHurtState.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "spyro/source/CharacterIceCubesFX.h"
#include "spyro/source/Game.h"
#include "spyro/source/GameData.h"
#include "spyro/source/InputModifier.h"
#include "spyro/source/KDCamera.h"
#include "spyro/source/LineSegmentTrail.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/Spyro.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKInput.h"
#include "common/Source/StdMath.h"
#include "spyro/source/KDSound.h"
#include <m2c_macros.h>

extern s32 GS_IceBossSpyroFreeze;
extern s32 GS_IceBossSpyroUnfreeze;
extern f32 *Hurt_pKnockToSafePosTime;
extern f32 SPYRO_BOUNCE_Y_SPEED;
extern f32 SPYRO_MIN_JUMP_Y_VELOCITY;
extern void **gMK;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern GameGlobals gb;
#if 0 // DRAFT: illegal explicit conversion from 'int' to
static M2C_UNK lit_727;                                /* unable to generate initializer: unknown type */
SpyroHurtState states__14SpyroHurtState;            /* unable to generate initializer: confusing struct layout */

s32 SpyroHurtState::CynderFuryDazedTransition() {
    Spyro *temp_r4_40;
    Spyro *temp_r4_58;
    s32 temp_r0_65;

    if (this->unk10->GetAnimScript((Spyro::AnimScriptNode) 0)->unk2C & 1) {
        temp_r4_40 = this->unk10;
        if ((u32) this->unk10->GetAnimScript((Spyro::AnimScriptNode) 0)->unk20 == (u32) M2C_FIELD(temp_r4_40->unkB4, u32 *, 0x284)) {
            temp_r4_40->SetAnim(0x51U, 0.0f, (Spyro::AnimScriptNode) 0, 0U, 1.0f);
            goto block_8;
        }
        temp_r4_58 = this->unk10;
        if ((u32) temp_r4_40->GetAnimScript((Spyro::AnimScriptNode) 0)->unk20 == (u32) M2C_FIELD(temp_r4_58->unkB4, u32 *, 0x28C)) {
            temp_r0_65 = this->unk94 + 1;
            this->unk94 = temp_r0_65;
            if (temp_r0_65 >= 2) {
                this->unk10->SetAnim(0x52U, 0.0f, (Spyro::AnimScriptNode) 0, 0U, 1.0f);
            } else {
                this->unk10->SetAnim(0x51U, 0.0f, (Spyro::AnimScriptNode) 0, 4U, 1.0f);
            }
            goto block_8;
        }
        temp_r4_58->TryChangeState(1U, 4U, NULL, 0U);
        return 1;
    }
block_8:
    return 0;
}
#endif

void SpyroHurtState::CynderFuryDazedUpdate() {
    CynderFuryDazedTransition();
}

void SpyroHurtState::CynderFuryDazedExit() {
    ((Stat *) ((Stat *) &GameData::gameData[0x70]))->SetValue(M2C_FIELD(GameData::gameData, f32 *, 0x74), 1U);
}

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void SpyroHurtState::CynderFuryDazedEnter() {
    Spyro *temp_r4_156;

    this->unk10->SetDesiredVelocity(MKVector3::zero, 540000.0f);
    this->unk10->SetAnim(0x50U, 0.15f, (Spyro::AnimScriptNode) 0, 0U, 1.0f);
    temp_r4_156 = this->unk10;
    temp_r4_156->unk428 |= 0x20;
    this->unk94 = 0;
}
#endif

#if 0 // DRAFT: undefined identifier 'unksp1C'
u8 SpyroHurtState::TransitionToIdle() {
    f64 sp20;
    f64 sp18;
    f64 sp10;
    f64 sp8;
    MKProp *temp_r5_178;
    Spyro *temp_r3_177;
    Spyro *temp_r3_226;
    s32 temp_r4_179;
    u32 var_r30_182;
    u32 var_r4_190;
    u8 var_r29_202;
    u8 var_r3_243;
    u8 var_r4_203;
    void *temp_r4_187;

    temp_r3_177 = this->unk10;
    temp_r5_178 = temp_r3_177->unk26C.unk8;
    temp_r4_179 = M2C_FIELD(temp_r5_178, s32 *, 0x2D4);
    var_r30_182 = (u32) (-temp_r4_179 & ~temp_r4_179) >> 0x1FU;
    if (var_r30_182 != 0) {
        if (((u8) M2C_FIELD(temp_r5_178, u8 *, 0x1C0) != 0) && (temp_r4_187 = M2C_FIELD(temp_r5_178, void **, 0x1B8), ((temp_r4_187 == NULL) == 0)) && (var_r4_190 = M2C_FIELD(temp_r4_187, u32 *, 8), ((var_r4_190 == 0U) == 0))) {

        } else {
            var_r4_190 = 0U;
        }
        var_r30_182 = (u32) (u8) (var_r4_190 != 0U);
    }
    var_r29_202 = 0;
    var_r4_203 = 1;
    if ((s32) M2C_FIELD(temp_r5_178, s32 *, 0x16C) <= 0) {
        sp18 = M2C_FIELD(temp_r3_177, f64 *, 0x338);
        sp20 = M2C_FIELD(temp_r3_177, f64 *, 0x340);
        if (!(unksp1C > -5.0f)) {
            var_r4_203 = 0;
        }
    }
    if ((var_r4_203 != 0) && (temp_r3_177->GetAnimScript((Spyro::AnimScriptNode) 0)->unk24 > 0.5f)) {
        var_r29_202 = 1;
    }
    temp_r3_226 = this->unk10;
    sp8 = M2C_FIELD(temp_r3_226, f64 *, 0x338);
    sp10 = M2C_FIELD(temp_r3_226, f64 *, 0x340);
    var_r3_243 = 0;
    if ((var_r29_202 != 0) || ((u8) var_r30_182 != 0) || ((u32) ((u32) M2C_ERROR(/* unknown instruction: mfcr $r3 */) >> 0x1FU) != 0)) {
        var_r3_243 = 1;
    }
    return var_r3_243;
}
#endif

s32 SpyroHurtState::KnockToSafePosTransition() {
    s8 sp1D;
    s8 sp1C;
    f32 sp18;
    f32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    InputModifier *temp_r3_299;
    f32 var_f1_312;
    s32 var_r31_271;
    u8 var_r27_274;
    u8 var_r28_270;
    u8 var_r29_275;
    u8 var_r4_301;

    var_r28_270 = 0;
    var_r31_271 = 1;
    var_r27_274 = 0;
    var_r29_275 = 0;
    spC = 0;
    sp10 = 0x55;
    sp8 = 0x187;
    sp14 = 0.0f;
    sp18 = 0.2f;
    sp1C = 1;
    sp1D = 1;
    M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
    if ((this->unk84 == 1.0f) && (this->unk10->CanStrafe() != 0) && ((u8) this->unk99 != 0)) {
        var_r29_275 = 1;
    }
    if (var_r29_275 != 0) {
        temp_r3_299 = this->unk10->GetInput();
        var_r4_301 = 0;
        if (((u8) temp_r3_299->unk5 != 0) || ((u8) temp_r3_299->unk4 != 0)) {
            var_r4_301 = 1;
        }
        if (var_r4_301 != 0) {
            var_f1_312 = 0.0f;
        } else {
            var_f1_312 = MKInput_GetState(0xA, (MKInputDevices) temp_r3_299->unk0, NULL, NULL);
        }
        if (var_f1_312 != 0.0f) {
            var_r27_274 = 1;
        }
    }
    if (var_r27_274 != 0) {
        this->unk10->IsAgainstMatID(2);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) == 0U) {
            var_r28_270 = 1;
        }
    }
    if (this->unk10->TryChangeState(var_r28_270, 2U, NULL, 0U) == 0) {
        M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
        if (this->unk10->TryChangeState(((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1DU) & 1, 4U, (MKMessage *) &sp8, 0U) == 0) {
            var_r31_271 = 0;
        }
    }
    return var_r31_271;
}

#if 0 // DRAFT: undefined identifier 'unk30C'
void SpyroHurtState::KnockToSafePosUpdate() {
    f64 spE0;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    f64 spC0;
    f64 spB8;
    f64 spB0;
    f64 spA8;
    f64 spA0;
    f64 sp98;
    M2C_UNK sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f32 sp50;
    f32 sp40;
    f32 sp30;
    f32 sp20;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f1_442;
    f32 temp_f5_405;
    f32 var_f0_388;
    f32 var_f6_446;

    this->unk28.Update(this->unk10);
    var_f0_388 = 1.0f - ((this->unk80 - gb.unk30C) / 0.55555f);
    if (var_f0_388 < 1.0f) {

    } else {
        var_f0_388 = 1.0f;
    }
    if (var_f0_388 > 0.0f) {

    } else {
        var_f0_388 = 0.0f;
    }
    this->unk84 = var_f0_388;
    temp_f5_405 = this->unk84;
    spA8 = this->unk70;
    spB8 = this->unk60;
    spB0 = this->unk78;
    spC0 = this->unk68;
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f0, $f2 */);
    sp68 = sp48;
    sp50 = (f32) spB0 - (f32) spC0;
    sp70 = (f64) sp50;
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
    sp58 = sp38;
    sp40 = (f32) sp70 * temp_f5_405;
    sp60 = (f64) sp40;
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f2, $f0 */);
    temp_f1_442 = temp_f5_405 - 0.5f;
    sp30 = (f32) spC0 + (f32) sp60;
    var_f6_446 = M2C_FIELD(this, f32 *, 0x64) - M2C_FIELD(this, f32 *, 0x74);
    spD8 = sp28;
    spE0 = (f64) sp30;
    if (var_f6_446 < 0.0f) {
        var_f6_446 = -var_f6_446;
    }
    unkspDC += (-((4.0f * (temp_f1_442 * temp_f1_442)) - 1.0f) * ((var_f6_446 * 0.5f) + 250.0f)) + 5.0f;
    M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
    if (gb.unk30C == this->unk80) {
        this->unk10->GetYaw();
        this->unk10->Teleport(*((MKVector3 *) &this->unk70), M2C_ERROR(/* Read from unset register $f1 */), 0x1E, 0U, 1U);
    } else {
        sp88.GetPos();
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
        spC8 = sp18;
        sp20 = (f32) spE0 - sp90;
        sp98 = sp18;
        spD0 = (f64) sp20;
        spA0 = (f64) sp20;
        this->unk10->SetDeltaPos(*((MKVector3 *) &spC8));
    }
    sp8 = -this->unk50;
    spC = -this->unk54;
    sp10 = -this->unk58;
    sp78 = (f64) sp8;
    sp80 = (f64) sp10;
    this->unk10->unk3A0.YawTowards(*((MKVector3 *) &sp78), 3.0f);
    KnockToSafePosTransition();
}
#endif

#if 0 // DRAFT: ')' expected
void SpyroHurtState::KnockToSafePosExit() {
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    KDCamera *temp_r3_578;
    KDCamera *temp_r3_589;
    Spyro *temp_r3_573;
    void **temp_r3_543;
    void **temp_r3_552;

    gb.GetSpyro();
    temp_r3_543 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), void ***, 0x27C);
    M2C_FIELD(*temp_r3_543, M2C_UNK (**)(void **, M2C_UNK), 0x48)(temp_r3_543, 0);
    gb.GetSpyro();
    temp_r3_552 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), void ***, 0x27C);
    M2C_FIELD(*temp_r3_552, M2C_UNK (**)(void **, f64 *, M2C_UNK, f32), 0x14)(temp_r3_552, &this->unk70, 0x1E, 2.5f);
    M2C_FIELD(this->unk10, f32 *, 0x38C) = 1900.0f;
    this->unk10->SetDesiredVelocity(MKVector3::zero, 540000.0f);
    M2C_FIELD(checked_cast<SpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk10->unk0), s32 *, 0x78) = (s32) this->unk90;
    temp_r3_573 = this->unk10;
    temp_r3_573->unk428 |= 0x40000;
    temp_r3_578 = this->unk10->GetCamera();
    sp14 = 0;
    sp10 = 0x44B;
    M2C_FIELD(temp_r3_578->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp10);
    temp_r3_589 = this->unk10->GetCamera();
    spC = 0;
    sp8 = 0x414;
    M2C_FIELD(temp_r3_589->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp8);
}
#endif

#if 0 // DRAFT: undefined identifier 'unk30C'
void SpyroHurtState::KnockToSafePosEnter() {
    f64 sp28;
    f64 sp20;
    f32 sp18;
    s32 spC;
    s32 sp8;
    KDCamera *temp_r3_692;
    Spyro *temp_r3_671;
    Spyro *temp_r3_675;
    u8 var_r4_668;
    void **temp_r3_617;

    gb.GetSpyro();
    temp_r3_617 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), void ***, 0x27C);
    M2C_FIELD(*temp_r3_617, M2C_UNK (**)(void **, M2C_UNK), 0x48)(temp_r3_617, 1);
    M2C_FIELD(this->unk10, f32 *, 0x38C) = 0.0f;
    this->unk28.Start(this->unk10, 0.05f);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $r31, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    M2C_FIELD(this, f64 *, 0x50) = sp10;
    sp18 = M2C_FIELD(this, f32 *, 0x78) - M2C_FIELD(this, f32 *, 0x68);
    sp20 = sp10;
    M2C_FIELD(this, f64 *, 0x58) = (f64) sp18;
    sp28 = (f64) sp18;
    this->unk80 = gb.unk30C + 0.55555f;
    this->unk10->SetDesiredVelocity(MKVector3::zero, 540000.0f);
    this->unk90 = M2C_FIELD(checked_cast<SpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk10->unk0), s32 *, 0x78);
    var_r4_668 = 0;
    M2C_FIELD(checked_cast<SpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk10->unk0), s32 *, 0x78) = 0x7FFFFFFF;
    this->unk84 = 0.0f;
    temp_r3_671 = this->unk10;
    temp_r3_671->unk428 &= 0xFFFBFFFF;
    temp_r3_675 = this->unk10;
    if (((s32) temp_r3_675->unk54.unkC == 6) && ((u8) temp_r3_675->unk3CC != 0)) {
        var_r4_668 = 1;
    }
    this->unk98 = var_r4_668 != 0;
    this->unk10->unk3CC = 0;
    temp_r3_692 = this->unk10->GetCamera();
    spC = 0;
    sp8 = 0x416;
    M2C_FIELD(temp_r3_692->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp8);
}
#endif

void SpyroHurtState::FrozenTransition() {
    u32 var_r5_719;

    var_r5_719 = 6;
    if (TransitionToIdle() != 0) {
        var_r5_719 = 4;
    }
    M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
    this->unk10->TryChangeState(((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1DU) & 1, var_r5_719, NULL, 0U);
}

#if 0 // DRAFT: expression syntax error
void SpyroHurtState::FrozenUpdate() {
    InputModifier *temp_r3_753;
    s32 var_r3_766;
    u8 var_r4_755;

    this->unk88 -= gUpdateTimeDelta;
    temp_r3_753 = this->unk10->GetInput();
    var_r4_755 = 0;
    if (((u8) temp_r3_753->unk5 != 0) || ((u8) temp_r3_753->unk4 != 0)) {
        var_r4_755 = 1;
    }
    if (var_r4_755 != 0) {
        var_r3_766 = 0;
    } else {
        var_r3_766 = MKInput_Pressed(0xD, (MKInputDevices) temp_r3_753->unk0);
    }
    if ((u8) var_r3_766 != 0) {
        this->unk88 -= 0.1f;
        this->unk10->unk3A0.RollTowards(MKRand_Float(&gViewSeed, -0.5f, 0.5f), 900.0f);
    }
    FrozenTransition();
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'float' to
void SpyroHurtState::FrozenExit() {
    CharacterIceCubesFX *temp_r3_828;
    Spyro *temp_r3_813;

    M2C_FIELD(this->unk10, s8 *, 0x3CE) = 0;
    this->unk10->SetModelVisualOffset(MKVector3::zero, 0U);
    temp_r3_813 = this->unk10;
    temp_r3_813->unk428 |= 0x40000;
    if ((u8) this->unk10->unk1C5 == 0) {
        KDSound_Play(GS_IceBossSpyroUnfreeze, 0U, -1);
        temp_r3_828 = M2C_FIELD(M2C_FIELD(this->unk10->unk258, void **, 4), CharacterIceCubesFX **, 0xC4);
        if (temp_r3_828 != NULL) {
            temp_r3_828->Shatter();
        }
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'float' to
void SpyroHurtState::FrozenEnter() {
    Spyro *temp_r3_876;
    Spyro *temp_r6_859;
    Spyro *temp_r7_855;
    f32 temp_f0_880;
    f32 temp_f1_878;
    f32 var_f2_879;
    void *temp_r30_896;
    void *temp_r3_897;

    this->unk88 = 5.0f;
    temp_r7_855 = this->unk10;
    temp_r7_855->unk428 &= 0xFFFBFFFD;
    temp_r6_859 = this->unk10;
    temp_r6_859->unk428 |= 0x20;
    M2C_FIELD(this->unk10, s8 *, 0x3CE) = 1;
    KDSound_Play(GS_IceBossSpyroFreeze, 0U, -1);
    this->unk10->SetDesiredVelocity(MKVector3::zero, 540000.0f);
    M2C_FIELD(this->unk10, f32 *, 0x38C) = 1900.0f;
    temp_r3_876 = this->unk10;
    temp_r3_876->unk388 = 3800.0f;
    temp_f1_878 = temp_r3_876->unk388;
    var_f2_879 = temp_r3_876->unk33C;
    temp_f0_880 = -temp_f1_878;
    if (var_f2_879 < temp_f1_878) {

    } else {
        var_f2_879 = temp_f1_878;
    }
    if (var_f2_879 > temp_f0_880) {

    } else {
        var_f2_879 = temp_f0_880;
    }
    temp_r3_876->unk33C = var_f2_879;
    temp_r30_896 = M2C_FIELD(this->unk10->unk258, void **, 4);
    temp_r3_897 = M2C_FIELD(temp_r30_896, void **, 0xC4);
    if (temp_r3_897 != NULL) {
        if ((u32) M2C_FIELD(temp_r3_897, u32 *, 0x24) == 0U) {
            M2C_FIELD(M2C_FIELD(temp_r30_896, void **, 0xC4), u32 *, 0x24) = checked_cast<ShatterableDescriptor *, MKPropDescriptor>(M2C_FIELD(*gMK, MKPropDescriptor *(**)(void **, M2C_UNK *), 0x5C)(gMK, "IceCube"));
        }
        ((CharacterIceCubesFX *) (M2C_FIELD(M2C_FIELD(this->unk10->unk258, void **, 4), CharacterIceCubesFX **, 0xC4)))->Reset();
        ((CharacterIceCubesFX *) (M2C_FIELD(M2C_FIELD(this->unk10->unk258, void **, 4), CharacterIceCubesFX **, 0xC4)))->Trigger();
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
u8 SpyroHurtState::DazedTransition() {
    s8 sp1D;
    s8 sp1C;
    f32 sp18;
    f32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    Spyro *temp_r3_959;
    Spyro *temp_r4_943;

    temp_r4_943 = this->unk10;
    if (((u32) this->unk10->GetAnimScript((Spyro::AnimScriptNode) 0)->unk20 == (u32) M2C_FIELD(temp_r4_943->unkB4, u32 *, 0x28C)) && (temp_r4_943->GetAnimScript((Spyro::AnimScriptNode) 0)->unk2C & 1)) {
        if (TransitionToIdle() != 0) {
            temp_r3_959 = this->unk10;
            if ((u8) temp_r3_959->unk3CE != 0) {
                return temp_r3_959->TryChangeState(1U, 3U, NULL, 0U);
            }
            sp1C = 1;
            sp1D = 1;
            spC = 0;
            sp10 = 0x52;
            sp8 = 0x187;
            sp14 = 0.5f;
            sp18 = 0.2f;
            sp1D = 0;
            sp1C = 0;
            return temp_r3_959->TryChangeState(1U, 4U, (MKMessage *) &sp8, 0U);
        }
        return this->unk10->TryChangeState(1U, 6U, NULL, 0U);
    }
    return 0U;
}
#endif

void SpyroHurtState::DazedUpdate() {
    this->unk30.Update(this->unk10);
    DazedTransition();
}

void SpyroHurtState::DazedExit() {
    Spyro *temp_r4_1035;

    temp_r4_1035 = this->unk10;
    temp_r4_1035->unk428 |= 0x40000;
    if ((u8) this->unk9A != 0) {
        ((Stat *) ((Stat *) &GameData::gameData[0x70]))->SetValue(M2C_FIELD(GameData::gameData, f32 *, 0x74), 1U);
    }
}

void SpyroHurtState::DazedEnter() {
    Spyro *temp_r3_1072;
    Spyro *temp_r3_1076;

    this->unk10->SetDesiredVelocity(MKVector3::zero, 540000.0f);
    this->unk30.Start(this->unk10, 0.15f);
    temp_r3_1072 = this->unk10;
    temp_r3_1072->unk428 &= 0xFFFBFFFF;
    temp_r3_1076 = this->unk10;
    temp_r3_1076->unk428 |= 0x20;
}

#if 0 // DRAFT: illegal explicit conversion from 'int' to
u8 SpyroHurtState::SquashTransition() {
    s8 sp1D;
    s8 sp1C;
    f32 sp18;
    f32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;

    if (this->unk10->GetAnimScript((Spyro::AnimScriptNode) 0)->unk2C & 1) {
        this->unk8C += gUpdateTimeDelta;
        M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
        if (this->unk8C == 1.0f) {
            if (TransitionToIdle() != 0) {
                sp1C = 1;
                sp1D = 1;
                spC = 0;
                sp10 = 0x4F;
                sp8 = 0x187;
                sp14 = 1.0f;
                sp18 = 0.2f;
                sp1D = 0;
                sp1C = 0;
                return this->unk10->TryChangeState(1U, 4U, (MKMessage *) &sp8, 0U);
            }
            return this->unk10->TryChangeState(1U, 6U, NULL, 0U);
        }
    }
    return 0U;
}
#endif

void SpyroHurtState::SquashUpdate() {
    SquashTransition();
}

void SpyroHurtState::SquashExit() {
    Spyro *temp_r5_1170;

    temp_r5_1170 = this->unk10;
    temp_r5_1170->unk428 = temp_r5_1170->unk428 | 0x40000 | 0x800;
    this->unk10->unk178.unk38 = 1;
}

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void SpyroHurtState::SquashEnter() {
    Spyro *temp_r4_1210;
    Spyro *temp_r5_1206;

    this->unk10->SetDesiredVelocity(MKVector3::zero, 540000.0f);
    this->unk10->SetAnim(0x4EU, 0.15f, (Spyro::AnimScriptNode) 0, 0U, 1.0f);
    this->unk8C = 0.0f;
    temp_r5_1206 = this->unk10;
    temp_r5_1206->unk428 &= 0xFFFBF7FF;
    temp_r4_1210 = this->unk10;
    temp_r4_1210->unk428 |= 0x20;
    this->unk10->unk178.unk38 = 0;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
u8 SpyroHurtState::TumbleTransition() {
    s8 sp1D;
    s8 sp1C;
    f32 sp18;
    f32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    MKProp *temp_r3_1244;
    s32 temp_r3_1246;
    s32 var_r9_1274;
    u32 var_r0_1249;
    u32 var_r0_1263;
    void *temp_r3_1260;
    void *var_r4_1241;

    if (this->unk10->GetAnimScript((Spyro::AnimScriptNode) 0)->unk2C & 1) {
        if (TransitionToIdle() != 0) {
            var_r4_1241 = NULL;
            spC = 0;
            temp_r3_1244 = this->unk10->unk26C.unk8;
            temp_r3_1246 = M2C_FIELD(temp_r3_1244, s32 *, 0x2D4);
            var_r0_1249 = (u32) (-temp_r3_1246 & ~temp_r3_1246) >> 0x1FU;
            if (var_r0_1249 != 0) {
                if (temp_r3_1246 != 0) {
                    var_r4_1241 = temp_r3_1244 + 0x170 + ((temp_r3_1246 - 1) * 0x58);
                }
                if (((u8) M2C_FIELD(var_r4_1241, u8 *, 0x50) != 0) && (temp_r3_1260 = M2C_FIELD(var_r4_1241, void **, 0x48), ((temp_r3_1260 == NULL) == 0)) && (var_r0_1263 = M2C_FIELD(temp_r3_1260, u32 *, 8), ((var_r0_1263 == 0U) == 0))) {

                } else {
                    var_r0_1263 = 0U;
                }
                var_r0_1249 = var_r0_1263 == 0U;
            }
            var_r9_1274 = 0x4C;
            if ((u8) var_r0_1249 != 0) {
                var_r9_1274 = 0x4D;
            }
            sp1C = 1;
            sp1D = 1;
            sp10 = var_r9_1274;
            sp8 = 0x187;
            sp14 = 1.0f;
            sp18 = 0.2f;
            sp1D = 0;
            sp1C = 0;
            return this->unk10->TryChangeState(1U, 4U, (MKMessage *) &sp8, 0U);
        }
        return this->unk10->TryChangeState(1U, 6U, NULL, 0U);
    }
    return 0U;
}
#endif

void SpyroHurtState::TumbleUpdate() {
    TumbleTransition();
}

void SpyroHurtState::TumbleExit() {
    Spyro *temp_r3_1332;

    temp_r3_1332 = this->unk10;
    temp_r3_1332->unk428 |= 0x40000;
}

#if 0 // DRAFT: expression syntax error
void SpyroHurtState::TumbleEnter() {
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    Spyro *temp_r3_1377;
    Spyro *temp_r3_1381;

    this->unk10->SetDesiredVelocity(MKVector3::zero, 540000.0f);
    sp8 = -this->unk50;
    spC = -this->unk54;
    sp10 = -this->unk58;
    sp18 = (f64) sp8;
    sp20 = (f64) sp10;
    this->unk10->unk3A0.YawTowards(*((MKVector3 *) &sp18), 900.0f);
    this->unk10->SetAnim(0x4BU, 0.15f, (Spyro::AnimScriptNode) 0, 0U, 1.0f);
    temp_r3_1377 = this->unk10;
    temp_r3_1377->unk428 &= 0xFFFBFFFF;
    temp_r3_1381 = this->unk10;
    temp_r3_1381->unk428 |= 0x20;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void SpyroHurtState::StrafeFlinchTransition() {
    M2C_UNK var_r29_1402;
    s32 var_r31_1401;
    s32 var_r3_1432;
    u8 temp_r30_1406;
    u8 var_r31_1420;

    var_r31_1401 = 6;
    var_r29_1402 = 0x189;
    temp_r30_1406 = this->unk10->GetAnimScript((Spyro::AnimScriptNode) 0)->unk2C & 1;
    if (temp_r30_1406 != 0) {
        if ((u8) this->unk10->unk3CE != 0) {
            var_r31_1401 = 3;
        } else if (TransitionToIdle() != 0) {
            var_r31_1420 = 0;
            if (this->unk10->CanStrafe() != 0) {
                this->unk10->IsAgainstMatID(2);
                if ((u32) M2C_ERROR(/* Read from unset register $r3 */) == 0U) {
                    var_r31_1420 = 1;
                }
            }
            var_r3_1432 = 4;
            if (var_r31_1420 != 0) {
                var_r3_1432 = 2;
            }
            var_r31_1401 = var_r3_1432;
            if (var_r3_1432 == 2) {
                var_r29_1402 = 0x178;
            }
        }
    }
    this->unk10->TryChangeState(temp_r30_1406, (u32) var_r31_1401, (SpyroStateMsg) var_r29_1402, 0U);
}
#endif

#if 0 // DRAFT: pointer/array required
void SpyroHurtState::StrafeFlinchUpdate() {
    f64 spA0;
    f64 sp98;
    s32 sp94;
    s32 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;                                       /* compiler-managed */
    f64 sp60;                                       /* compiler-managed */
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f32 sp28;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 sp8;
    f32 var_f4_1489;
    f32 var_f5_1506;
    f64 temp_f1_1511;
    f64 temp_f1_1517;
    f64 temp_f1_1521;
    s32 temp_r3_1540;
    s32 var_r0_1550;
    void *temp_r3_1476;
    void *temp_r5_1475;

    this->unk10->unkB90.GetCurrentTarget();
    if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
        this->unk10->unkB90.GetCurrentTarget();
        temp_r5_1475 = M2C_FIELD(M2C_FIELD(*M2C_ERROR(/* Read from unset register $r3 */), void *(**)(), 8)(), void **, 8);
        temp_r3_1476 = this->unk10->unk8;
        sp70 = M2C_FIELD(temp_r5_1475, f64 *, 0x30);
        sp50 = M2C_FIELD(temp_r3_1476, f64 *, 0x30);
        sp78 = M2C_FIELD(temp_r5_1475, f64 *, 0x38);
        sp58 = M2C_FIELD(temp_r3_1476, f64 *, 0x38);
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
        var_f4_1489 = 0.0f;
        sp60 = sp20;
        unksp64 = 0.0f;
        sp28 = (f32) sp78 - (f32) sp58;
        sp68 = (f64) sp28;
        var_f5_1506 = ((f32) sp68 * (f32) sp68) + (((f32) sp60 * (f32) sp60) + (0.0f * 0.0f));
        if (var_f5_1506 > 0.000001f) {
            if (var_f5_1506 > 0.0f) {
                temp_f1_1511 = __frsqrte(var_f5_1506);
                temp_f1_1517 = 0.5 * temp_f1_1511 * -(((f64) var_f5_1506 * (temp_f1_1511 * temp_f1_1511)) - 3.0);
                temp_f1_1521 = 0.5 * temp_f1_1517 * -(((f64) var_f5_1506 * (temp_f1_1517 * temp_f1_1517)) - 3.0);
                var_f5_1506 = (f32) ((f64) var_f5_1506 * (0.5 * temp_f1_1521 * -(((f64) var_f5_1506 * (temp_f1_1521 * temp_f1_1521)) - 3.0)));
            } else if (var_f5_1506 < M2C_BITWISE(f32, 0.0)) {
                var_f5_1506 = __float_nan;
            } else {
                sp8 = var_f5_1506;
                temp_r3_1540 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                switch (temp_r3_1540) {             /* irregular */
                case 0x7F800000:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_1550 = 1;
                    } else {
                        var_r0_1550 = 2;
                    }
                    break;
                case 0x0:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_1550 = 5;
                    } else {
                        var_r0_1550 = 3;
                    }
                    break;
                default:
                    var_r0_1550 = 4;
                    break;
                }
                if (var_r0_1550 == 1) {
                    var_f5_1506 = __float_nan;
                }
            }
            var_f4_1489 = 1.0f / var_f5_1506;
        }
        sp60 = (f32) sp60 * var_f4_1489;
        unksp64 *= var_f4_1489;
        sp68 = (f32) sp68 * var_f4_1489;
        this->unk10->unk3A0.YawTowards(*((MKVector3 *) &sp60), 15.0f);
        sp80 = (f64) sp60;
        sp88 = (f64) sp68;
    } else {
        this->unk10->unk8->ZAxis3();
        sp10 = -*M2C_ERROR(/* Read from unset register $r3 */);
        sp14 = -M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), f32 *, 4);
        sp18 = -M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), f32 *, 8);
        sp40 = (f64) sp10;
        sp48 = (f64) sp18;
        sp80 = (f64) sp10;
        sp88 = (f64) sp18;
    }
    sp94 = 0;
    sp90 = 0x43E;
    sp98 = sp80;
    spA0 = sp88;
    sp30 = sp80;
    sp38 = sp88;
    M2C_FIELD(this->unk10->GetCamera()->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp90);
    StrafeFlinchTransition();
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void SpyroHurtState::StrafeFlinchExit() {
    s32 spC;
    s32 sp8;
    KDCamera *temp_r3_1646;

    temp_r3_1646 = this->unk10->GetCamera();
    spC = 0;
    sp8 = 0x43F;
    M2C_FIELD(temp_r3_1646->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp8);
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void SpyroHurtState::StrafeFlinchEnter() {
    s32 spC;
    s32 sp8;
    KDCamera *temp_r3_1687;
    Spyro *temp_r3_1682;

    this->unk10->SetAnim(0x12U, 0.0f, (Spyro::AnimScriptNode) 0, 0U, 1.0f);
    this->unk10->SetDesiredVelocity(MKVector3::zero, 540000.0f);
    temp_r3_1682 = this->unk10;
    temp_r3_1682->unk428 |= 0x20;
    temp_r3_1687 = this->unk10->GetCamera();
    spC = 0;
    sp8 = 0x43D;
    M2C_FIELD(temp_r3_1687->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp8);
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void SpyroHurtState::FlinchTransition() {
    u32 var_r31_1714;

    var_r31_1714 = 6;
    if (TransitionToIdle() != 0) {
        var_r31_1714 = 4;
    }
    this->unk10->TryChangeState(this->unk10->GetAnimScript((Spyro::AnimScriptNode) 0)->unk2C & 1, var_r31_1714, NULL, 0U);
}
#endif

void SpyroHurtState::FlinchUpdate() {
    FlinchTransition();
}

void SpyroHurtState::FlinchExit() {

}

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void SpyroHurtState::FlinchEnter() {
    MKProp sp48;
    M2C_UNK sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp10;
    f32 spC;
    f32 sp8;
    void **temp_r4_1770;

    this->unk10->SetAnim(0x4AU, 0.0f, (Spyro::AnimScriptNode) 0, 0U, 1.0f);
    temp_r4_1770 = this->unk38;
    if ((temp_r4_1770 != NULL) && (M2C_FIELD(*temp_r4_1770, s32 *, 0xC) & 8)) {
        sp38.GetPos();
        sp48.GetPos();
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
        M2C_FIELD(this, f64 *, 0x50) = sp18;
        sp20 = M2C_BITWISE(f32, sp48.unk8) - sp40;
        sp48.unk10 = sp18;
        M2C_FIELD(this, f64 *, 0x58) = (f64) sp20;
        sp48.unk18 = (f64) sp20;
        sp8 = -this->unk50;
        spC = -this->unk54;
        sp10 = -this->unk58;
        sp28 = (f64) sp8;
        sp30 = (f64) sp10;
        this->unk10->unk3A0.YawTowards(*((MKVector3 *) &sp28), 900.0f);
    }
}
#endif

s32 SpyroHurtState::Transition() {
    return 0;
}

#if 0 // DRAFT: undefined identifier 'unk14'
void SpyroHurtState::Update() {
    this->unk14.Update(this, 0);
}
#endif

#if 0 // DRAFT: undefined identifier 'unk14'
void SpyroHurtState::Exit() {
    s32 spC;
    s32 sp8;
    KDCamera *temp_r3_1862;

    this->unk14.Exit(this);
    this->unk10->SetLVEScale(MKVector3::one);
    temp_r3_1862 = this->unk10->GetCamera();
    spC = 0;
    sp8 = 0x42D;
    M2C_FIELD(temp_r3_1862->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp8);
    this->unk10->SetMeleeButtonStateTimeout(0U);
}
#endif

#if 0 // DRAFT: function call 'checked_cast(long)' does not match
void SpyroHurtState::Enter(SpyroStateMessages &arg0) {
    u8 sp1A8;
    s32 sp1A4;
    void *sp1A0;
    s32 sp19C;
    f32 sp198;
    s32 sp194;
    s8 sp193;
    s8 sp192;
    s16 sp190;
    f32 sp18C;
    f32 sp188;
    f32 sp184;
    f32 sp180;
    f32 sp17C;
    f32 sp178;
    f32 sp170;
    f32 sp16C;
    f32 sp168;
    f32 sp160;
    f32 sp15C;
    f32 sp158;
    f64 sp150;
    f64 sp148;
    f64 sp140;
    f64 sp138;
    f64 sp130;
    f64 sp128;
    f64 sp118;
    f64 sp110;
    f64 sp108;
    M2C_UNK spF8;
    f64 spF0;
    f64 spE8;
    f64 spE0;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    M2C_UNK spB8;
    f64 spB0;
    f64 spA8;
    f64 spA0;
    f64 sp98;
    f32 sp90;
    f32 sp8C;
    f32 sp88;
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
    f32 sp20;
    u8 sp14;
    void *sp10;
    s32 spC;
    s32 sp8;
    KDCamera *temp_r3_1919;
    Spyro *temp_r3_2040;
    Spyro *temp_r3_2210;
    Spyro *temp_r4_1914;
    f32 temp_f4_2070;
    f64 temp_f0_1933;
    f64 temp_f2_1934;
    s32 var_r30_1949;
    u32 temp_r0_1950;
    void **var_r0_2108;
    void **var_r0_2122;
    void **var_r3_2136;
    void *temp_r3_2045;
    void *temp_r5_1932;
    void *var_r31_1900;

    if (arg0.IsMessageOnList(7) != 0) {
        var_r31_1900 = checked_cast<HurtMessage *, MKMessage>(arg0.GetMessage(7));
    } else {
        var_r31_1900 = checked_cast<HurtMessage *, MKMessage>(arg0.GetMessage(8));
    }
    this->unk38 = M2C_FIELD(var_r31_1900, void ***, 0x2C);
    this->unk9A = 0;
    temp_r4_1914 = this->unk10;
    temp_r4_1914->unk428 &= ~0x21;
    temp_r3_1919 = this->unk10->GetCamera();
    spC = 0;
    sp8 = 0x42C;
    M2C_FIELD(temp_r3_1919->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp8);
    temp_r5_1932 = this->unk10->unk8;
    temp_f0_1933 = M2C_FIELD(temp_r5_1932, f64 *, 0x30);
    temp_f2_1934 = M2C_FIELD(temp_r5_1932, f64 *, 0x38);
    sp128 = temp_f0_1933;
    this->unk60 = temp_f0_1933;
    this->unk68 = temp_f2_1934;
    sp130 = temp_f2_1934;
    this->unk70 = this->unk60;
    this->unk78 = this->unk68;
    M2C_FIELD(this, f64 *, 0x50) = (f64) M2C_FIELD(var_r31_1900, f64 *, 8);
    M2C_FIELD(this, f64 *, 0x58) = (f64) M2C_FIELD(var_r31_1900, f64 *, 0x10);
    this->unk99 = arg0.IsMessageOnList(0x178);
    var_r30_1949 = 8;
    temp_r0_1950 = M2C_FIELD(var_r31_1900, u32 *, 0x28);
    switch (temp_r0_1950) {
    case 1:
        if ((u8) this->unk99 != 0) {
            var_r30_1949 = 1;
        } else {
            var_r30_1949 = 0;
        }
        break;
    case 2:
        var_r30_1949 = 2;
        break;
    case 3:
        var_r30_1949 = 3;
        break;
    case 4:
        var_r30_1949 = 4;
        break;
    case 7:
        var_r30_1949 = 5;
        break;
    case 5:
        var_r30_1949 = 6;
        if (this->unk10->LastSafePosAvailable() != NULL) {
            sp118.GetLastSafePos();
            this->unk70 = sp118;
            this->unk78 = sp120;
        }
        break;
    case 6:
        sp158 = 0.0f;
        var_r30_1949 = 0;
        sp15C = 0.0f;
        sp160 = 0.0f;
        sp168 = 0.0f;
        sp16C = 0.0f;
        sp170 = 0.0f;
        sp178 = 0.0f;
        sp17C = 0.0f;
        sp180 = 0.0f;
        sp184 = 1.0f;
        sp188 = 0.0f;
        sp18C = 0.0f;
        sp190 = 0;
        sp192 = 0;
        sp193 = 0;
        sp194 = 0;
        sp198 = 3.4028235e38f;
        sp19C = 0;
        sp1A0 = NULL;
        sp1A4 = -1;
        sp1A8 = 0;
        spF8.GetPos();
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $r29, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        this->unk70 = sp28;
        sp30 = sp100 + this->unk58;
        sp108 = sp28;
        this->unk78 = (f64) sp30;
        temp_r3_2040 = this->unk10;
        sp110 = (f64) sp30;
        temp_r3_2045 = temp_r3_2040->GetCollisionInfo(sp28, sp100);
        sp10 = temp_r3_2045;
        if (temp_r3_2045 != NULL) {
            sp14 = M2C_FIELD(temp_r3_2045, u8 *, 4);
            M2C_FIELD(temp_r3_2045, u8 *, 4) = 0U;
        }
        sp88 = 0.0f;
        sp8C = 300.0f;
        sp90 = 0.0f;
        spE8 = (f64) sp88;
        spF0 = (f64) sp90;
        M2C_ERROR(/* unknown instruction: psq_lx $f5, $r29, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f5, $f0 */);
        sp70 = 0.0f;
        temp_f4_2070 = (f32) M2C_FIELD(this, f64 *, 0x78);
        sp68 = 0.0f;
        sp6C = 600.0f;
        sp80 = temp_f4_2070 + (f32) spF0;
        spD8 = (f64) sp68;
        sp148 = sp78;
        sp150 = (f64) sp80;
        spE0 = (f64) sp70;
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f5, $f0 */);
        sp138 = sp58;
        sp60 = temp_f4_2070 - (f32) spE0;
        sp140 = (f64) sp60;
        if (MKCollision_RayCollide(*((MKVector3 *) &sp148), *((MKVector3 *) &sp138), (MKCollisionResult *) &sp158, (MKCollisionMode) 7, 0) != 0) {
            if ((sp1A8 != 0) && (sp1A0 != NULL) && (var_r0_2108 = M2C_FIELD(sp1A0, void ***, 8), ((var_r0_2108 == NULL) == 0))) {

            } else {
                var_r0_2108 = NULL;
            }
            if (var_r0_2108 != NULL) {
                if ((sp1A8 != 0) && (sp1A0 != NULL) && (var_r0_2122 = M2C_FIELD(sp1A0, void ***, 8), ((var_r0_2122 == NULL) == 0))) {

                } else {
                    var_r0_2122 = NULL;
                }
                if (var_r0_2122 != NULL) {
                    if ((sp1A8 != 0) && (sp1A0 != NULL) && (var_r3_2136 = M2C_FIELD(sp1A0, void ***, 8), ((var_r3_2136 == NULL) == 0))) {

                    } else {
                        var_r3_2136 = NULL;
                    }
                    if (!(M2C_FIELD(*var_r3_2136, s32 *, 0x14) & 1)) {
                        goto block_35;
                    }
                }
            } else {
block_35:
                MKVector(0.0f, 5.0f, 0.0f);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                sp50 = 0.0f;
                sp20 = sp160 + spC0;
                this->unk70 = sp18;
                sp48 = 0.0f;
                sp4C = 50.0f;
                this->unk78 = (f64) sp20;
                sp98 = (f64) sp48;
                spC8 = sp18;
                spD0 = (f64) sp20;
                spA0 = (f64) sp50;
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $r29, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                spA8 = sp38;
                sp40 = (f32) M2C_FIELD(this, f64 *, 0x78) + (f32) spA0;
                spB0 = (f64) sp40;
                if (MKCollision_RayCollide(*((MKVector3 *) &this->unk60), *((MKVector3 *) &spA8), NULL, (MKCollisionMode) 7, 0) == 0) {
                    var_r30_1949 = 6;
                }
            }
        }
        if (sp10 != NULL) {
            M2C_FIELD(sp10, u8 *, 4) = sp14;
        }
        break;
    case 8:
        var_r30_1949 = 4;
        this->unk9A = 1;
        break;
    }
    temp_r3_2210 = this->unk10;
    if (((u8) temp_r3_2210->unk3CE != 0) && (var_r30_1949 != 4)) {
        var_r30_1949 = 1;
    }
    temp_r3_2210->SetMeleeButtonStateTimeout(1U);
    this->unk14.SetState(this, var_r30_1949, 0U);
    ((LineSegmentTrail *) (M2C_FIELD(M2C_FIELD(this->unk10->unk258, void **, 4), LineSegmentTrail **, 0xC8)))->EndTrail();
    ((LineSegmentTrail *) (M2C_FIELD(M2C_FIELD(this->unk10->unk258, void **, 4), LineSegmentTrail **, 0xCC)))->EndTrail();
    this->unk10->SetLVEScale(*(var_r31_1900 + 0x18));
}
#endif

#if 0 // DRAFT: undefined identifier 'unk14'
void SpyroHurtState::Deinit() {
    this->unk14.Deinit(this);
}
#endif

#if 0 // DRAFT: undefined identifier 'Init__32KDStateMachine'
void SpyroHurtState::Init(Spyro *arg0) {
    this->unk10 = arg0;
    Init__32KDStateMachine<14SpyroHurtState>FPQ232KDStateMachine<14SpyroHurtState>5StateP32KDStateMachine<14SpyroHurtState>(&this->unk14, (KDStateMachine<SpyroHurtState>::State *) &SpyroHurtState::states, NULL);
    this->unk40 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    this->unk48 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
    this->unk88 = 0.0f;
    this->unk8C = 0.0f;
    this->unk50 = 0.0f;
    this->unk54 = 0.0f;
    this->unk58 = 0.0f;
    M2C_FIELD(this, f32 *, 0x60) = 0.0f;
    M2C_FIELD(this, f32 *, 0x64) = 0.0f;
    M2C_FIELD(this, f32 *, 0x68) = 0.0f;
    this->unk84 = 0.0f;
    this->unk80 = 0.0f;
    M2C_FIELD(this, f32 *, 0x70) = 0.0f;
    M2C_FIELD(this, f32 *, 0x74) = 0.0f;
    M2C_FIELD(this, f32 *, 0x78) = 0.0f;
    this->unk98 = 0;
    this->unk9A = 0;
    this->unk94 = 0;
    this->unk38 = NULL;
    this->unk28.unk0 = 0x53;
    this->unk28.unk4 = 0x54;
    this->unk30.unk0 = 0x50;
    this->unk30.unk4 = 0x51;
    Hurt_pKnockToSafePosTime = &this->unk84;
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_727'
void SpyroHurtState_cpp::__sinit() {
    s32 sp50;
    s32 sp4C;
    s32 sp48;
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
    f64 temp_f0_2611;
    f64 temp_f1_2576;
    f64 temp_f1_2591;
    f64 temp_f1_2614;
    f64 temp_f3_2561;
    f64 temp_f4_2575;
    f64 temp_f4_2588;
    f64 temp_f8_2563;
    void *temp_r17_2570;

    temp_f3_2561 = __frsqrte(2014000.0);
    temp_f8_2563 = __frsqrte(380000.0);
    temp_r17_2570 = &lit_727 + 0x120;
    temp_f4_2575 = 0.5 * temp_f3_2561 * -((2014000.0 * (temp_f3_2561 * temp_f3_2561)) - 3.0);
    temp_f1_2576 = 0.5 * temp_f8_2563 * -((380000.0 * (temp_f8_2563 * temp_f8_2563)) - 3.0);
    temp_f4_2588 = 0.5 * temp_f4_2575 * -((2014000.0 * (temp_f4_2575 * temp_f4_2575)) - 3.0);
    temp_f1_2591 = 0.5 * temp_f1_2576 * -((380000.0 * (temp_f1_2576 * temp_f1_2576)) - 3.0);
    temp_f0_2611 = 0.5 * temp_f1_2591 * -((380000.0 * (temp_f1_2591 * temp_f1_2591)) - 3.0);
    temp_f1_2614 = 2014000.0 * (0.5 * temp_f4_2588 * -((2014000.0 * (temp_f4_2588 * temp_f4_2588)) - 3.0));
    M2C_FIELD(&lit_727, s32 *, 0x120) = (s32) M2C_FIELD(&lit_727, s32 *, 0);
    M2C_FIELD(&lit_727, s32 *, 0x124) = (s32) M2C_FIELD(&lit_727, s32 *, 4);
    M2C_FIELD(&lit_727, s32 *, 0x128) = (s32) M2C_FIELD(&lit_727, s32 *, 8);
    M2C_FIELD(temp_r17_2570, s32 *, 0xC) = (s32) M2C_FIELD(&lit_727, s32 *, 0xC);
    M2C_FIELD(temp_r17_2570, s32 *, 0x10) = (s32) M2C_FIELD(&lit_727, s32 *, 0x10);
    M2C_FIELD(temp_r17_2570, s32 *, 0x14) = (s32) M2C_FIELD(&lit_727, s32 *, 0x14);
    M2C_FIELD(temp_r17_2570, s32 *, 0x18) = (s32) M2C_FIELD(&lit_727, s32 *, 0x18);
    M2C_FIELD(temp_r17_2570, s32 *, 0x1C) = (s32) M2C_FIELD(&lit_727, s32 *, 0x1C);
    M2C_FIELD(temp_r17_2570, s32 *, 0x20) = (s32) M2C_FIELD(&lit_727, s32 *, 0x20);
    M2C_FIELD(temp_r17_2570, s32 *, 0x24) = (s32) M2C_FIELD(&lit_727, s32 *, 0x24);
    M2C_FIELD(temp_r17_2570, s32 *, 0x28) = (s32) M2C_FIELD(&lit_727, s32 *, 0x28);
    M2C_FIELD(temp_r17_2570, s32 *, 0x2C) = (s32) M2C_FIELD(&lit_727, s32 *, 0x2C);
    M2C_FIELD(temp_r17_2570, s32 *, 0x30) = (s32) M2C_FIELD(&lit_727, s32 *, 0x30);
    M2C_FIELD(temp_r17_2570, s32 *, 0x34) = (s32) M2C_FIELD(&lit_727, s32 *, 0x34);
    M2C_FIELD(temp_r17_2570, s32 *, 0x38) = (s32) M2C_FIELD(&lit_727, s32 *, 0x38);
    M2C_FIELD(temp_r17_2570, s32 *, 0x3C) = (s32) M2C_FIELD(&lit_727, s32 *, 0x3C);
    M2C_FIELD(temp_r17_2570, s32 *, 0x40) = (s32) M2C_FIELD(&lit_727, s32 *, 0x40);
    M2C_FIELD(temp_r17_2570, s32 *, 0x44) = (s32) M2C_FIELD(&lit_727, s32 *, 0x44);
    SPYRO_BOUNCE_Y_SPEED = (f32) temp_f1_2614;
    SPYRO_MIN_JUMP_Y_VELOCITY = (f32) (380000.0 * temp_f0_2611);
    M2C_FIELD(temp_r17_2570, s32 *, 0x48) = (s32) M2C_FIELD(&lit_727, s32 *, 0x48);
    M2C_FIELD(temp_r17_2570, s32 *, 0x4C) = (s32) M2C_FIELD(&lit_727, s32 *, 0x4C);
    M2C_FIELD(temp_r17_2570, s32 *, 0x50) = (s32) M2C_FIELD(&lit_727, s32 *, 0x50);
    sp50 = M2C_FIELD(&lit_727, s32 *, 0xBC);
    M2C_FIELD(temp_r17_2570, s32 *, 0xB4) = (s32) M2C_FIELD(&lit_727, s32 *, 0xB4);
    sp8 = M2C_FIELD(&lit_727, s32 *, 0xC0);
    M2C_FIELD(temp_r17_2570, s32 *, 0xBC) = sp50;
    spC = M2C_FIELD(&lit_727, s32 *, 0xC4);
    M2C_FIELD(temp_r17_2570, s32 *, 0xC0) = sp8;
    sp10 = M2C_FIELD(&lit_727, s32 *, 0xC8);
    M2C_FIELD(temp_r17_2570, s32 *, 0xC4) = spC;
    sp14 = M2C_FIELD(&lit_727, s32 *, 0xCC);
    M2C_FIELD(temp_r17_2570, s32 *, 0xC8) = sp10;
    sp18 = M2C_FIELD(&lit_727, s32 *, 0xD0);
    M2C_FIELD(temp_r17_2570, s32 *, 0xCC) = sp14;
    sp1C = M2C_FIELD(&lit_727, s32 *, 0xD4);
    M2C_FIELD(temp_r17_2570, s32 *, 0xD0) = sp18;
    sp20 = M2C_FIELD(&lit_727, s32 *, 0xD8);
    M2C_FIELD(temp_r17_2570, s32 *, 0xD4) = sp1C;
    sp24 = M2C_FIELD(&lit_727, s32 *, 0xDC);
    M2C_FIELD(temp_r17_2570, s32 *, 0xD8) = sp20;
    sp28 = M2C_FIELD(&lit_727, s32 *, 0xE0);
    M2C_FIELD(temp_r17_2570, s32 *, 0xDC) = sp24;
    sp2C = M2C_FIELD(&lit_727, s32 *, 0xE4);
    M2C_FIELD(temp_r17_2570, s32 *, 0xE0) = sp28;
    sp30 = M2C_FIELD(&lit_727, s32 *, 0xE8);
    M2C_FIELD(temp_r17_2570, s32 *, 0xE4) = sp2C;
    sp34 = M2C_FIELD(&lit_727, s32 *, 0xEC);
    M2C_FIELD(temp_r17_2570, s32 *, 0xE8) = sp30;
    sp38 = M2C_FIELD(&lit_727, s32 *, 0xF0);
    M2C_FIELD(temp_r17_2570, s32 *, 0xEC) = sp34;
    sp3C = M2C_FIELD(&lit_727, s32 *, 0xF4);
    M2C_FIELD(temp_r17_2570, s32 *, 0xF0) = sp38;
    sp40 = M2C_FIELD(&lit_727, s32 *, 0xF8);
    M2C_FIELD(temp_r17_2570, s32 *, 0xF4) = sp3C;
    sp44 = M2C_FIELD(&lit_727, s32 *, 0xFC);
    M2C_FIELD(temp_r17_2570, s32 *, 0xF8) = sp40;
    sp48 = M2C_FIELD(&lit_727, s32 *, 0x100);
    M2C_FIELD(temp_r17_2570, s32 *, 0xFC) = sp44;
    M2C_FIELD(temp_r17_2570, s32 *, 0x100) = sp48;
    sp4C = M2C_FIELD(&lit_727, s32 *, 0x104);
    M2C_FIELD(temp_r17_2570, s32 *, 0x54) = (s32) M2C_FIELD(&lit_727, s32 *, 0x54);
    M2C_FIELD(temp_r17_2570, s32 *, 0x58) = (s32) M2C_FIELD(&lit_727, s32 *, 0x58);
    M2C_FIELD(temp_r17_2570, s32 *, 0x5C) = (s32) M2C_FIELD(&lit_727, s32 *, 0x5C);
    M2C_FIELD(temp_r17_2570, s32 *, 0x60) = (s32) M2C_FIELD(&lit_727, s32 *, 0x60);
    M2C_FIELD(temp_r17_2570, s32 *, 0x64) = (s32) M2C_FIELD(&lit_727, s32 *, 0x64);
    M2C_FIELD(temp_r17_2570, s32 *, 0x68) = (s32) M2C_FIELD(&lit_727, s32 *, 0x68);
    M2C_FIELD(temp_r17_2570, s32 *, 0x6C) = (s32) M2C_FIELD(&lit_727, s32 *, 0x6C);
    M2C_FIELD(temp_r17_2570, s32 *, 0x70) = (s32) M2C_FIELD(&lit_727, s32 *, 0x70);
    M2C_FIELD(temp_r17_2570, s32 *, 0x74) = (s32) M2C_FIELD(&lit_727, s32 *, 0x74);
    M2C_FIELD(temp_r17_2570, s32 *, 0x78) = (s32) M2C_FIELD(&lit_727, s32 *, 0x78);
    M2C_FIELD(temp_r17_2570, s32 *, 0x7C) = (s32) M2C_FIELD(&lit_727, s32 *, 0x7C);
    M2C_FIELD(temp_r17_2570, s32 *, 0x80) = (s32) M2C_FIELD(&lit_727, s32 *, 0x80);
    M2C_FIELD(temp_r17_2570, s32 *, 0x84) = (s32) M2C_FIELD(&lit_727, s32 *, 0x84);
    M2C_FIELD(temp_r17_2570, s32 *, 0x88) = (s32) M2C_FIELD(&lit_727, s32 *, 0x88);
    M2C_FIELD(temp_r17_2570, s32 *, 0x8C) = (s32) M2C_FIELD(&lit_727, s32 *, 0x8C);
    M2C_FIELD(temp_r17_2570, s32 *, 0x90) = (s32) M2C_FIELD(&lit_727, s32 *, 0x90);
    M2C_FIELD(temp_r17_2570, s32 *, 0x94) = (s32) M2C_FIELD(&lit_727, s32 *, 0x94);
    M2C_FIELD(temp_r17_2570, s32 *, 0x98) = (s32) M2C_FIELD(&lit_727, s32 *, 0x98);
    M2C_FIELD(temp_r17_2570, s32 *, 0x9C) = (s32) M2C_FIELD(&lit_727, s32 *, 0x9C);
    M2C_FIELD(temp_r17_2570, s32 *, 0xA0) = (s32) M2C_FIELD(&lit_727, s32 *, 0xA0);
    M2C_FIELD(temp_r17_2570, s32 *, 0xA4) = (s32) M2C_FIELD(&lit_727, s32 *, 0xA4);
    M2C_FIELD(temp_r17_2570, s32 *, 0xA8) = (s32) M2C_FIELD(&lit_727, s32 *, 0xA8);
    M2C_FIELD(temp_r17_2570, s32 *, 0xAC) = (s32) M2C_FIELD(&lit_727, s32 *, 0xAC);
    M2C_FIELD(temp_r17_2570, s32 *, 0xB0) = (s32) M2C_FIELD(&lit_727, s32 *, 0xB0);
    M2C_FIELD(temp_r17_2570, s32 *, 0xB8) = (s32) M2C_FIELD(&lit_727, s32 *, 0xB8);
    M2C_FIELD(temp_r17_2570, s32 *, 0x104) = (s32) M2C_FIELD(&lit_727, s32 *, 0x104);
    M2C_FIELD(temp_r17_2570, s32 *, 0x108) = (s32) M2C_FIELD(&lit_727, s32 *, 0x108);
    M2C_FIELD(temp_r17_2570, s32 *, 0x10C) = (s32) M2C_FIELD(&lit_727, s32 *, 0x10C);
    M2C_FIELD(temp_r17_2570, s32 *, 0x110) = (s32) M2C_FIELD(&lit_727, s32 *, 0x110);
    M2C_FIELD(temp_r17_2570, s32 *, 0x114) = (s32) M2C_FIELD(&lit_727, s32 *, 0x114);
    M2C_FIELD(temp_r17_2570, s32 *, 0x118) = (s32) M2C_FIELD(&lit_727, s32 *, 0x118);
    M2C_FIELD(temp_r17_2570, s32 *, 0x11C) = (s32) M2C_FIELD(&lit_727, s32 *, 0x11C);
}
#endif
