#include "spyro/source/SpyroJumpState.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "spyro/source/GameData.h"
#include "spyro/source/InputModifier.h"
#include "spyro/source/KDCamera.h"
#include "spyro/source/KDInput.h"
#include "spyro/source/Spyro.h"
#include "spyro/source/SpyroState.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "common/Source/MKInput.h"
#include <m2c_macros.h>

extern f32 SPYRO_BOUNCE_Y_SPEED;
extern f32 SPYRO_MIN_JUMP_Y_VELOCITY;
extern f32 gUpdateTimeDelta;
#if 0 // DRAFT: undefined identifier '__vptr'
static M2C_UNK lit_728;                                /* unable to generate initializer: unknown type */
SpyroJumpState states__14SpyroJumpState;            /* unable to generate initializer: confusing struct layout */

void SpyroJumpState::SetStrafeJump(bool arg0) {
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    KDCamera *temp_r3_38;
    KDCamera *temp_r3_56;

    if ((arg0 != 0) && ((u8) this->unk30 == 0)) {
        temp_r3_38 = this->unk10->GetCamera();
        sp14 = 0;
        sp10 = 0x43D;
        M2C_FIELD(temp_r3_38->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp10);
    } else if ((arg0 == 0) && ((u8) this->unk30 != 0)) {
        temp_r3_56 = this->unk10->GetCamera();
        spC = 0;
        sp8 = 0x43F;
        M2C_FIELD(temp_r3_56->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp8);
    }
    this->unk30 = arg0;
}
#endif

s32 SpyroJumpState::DoubleJumpTransition() {
    return 0;
}

void SpyroJumpState::DoubleJumpUpdate() {
    DoubleJumpTransition();
}

void SpyroJumpState::DoubleJumpExit() {
    M2C_FIELD(this->unk10, f32 *, 0x38C) = 1900.0f;
}

#if 0 // DRAFT: undefined identifier 'unksp24'
void SpyroJumpState::DoubleJumpEnter() {
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f64 sp20;
    f64 sp10;
    f32 sp8;
    f32 temp_f7_127;
    f32 var_f31_144;
    f32 var_f3_134;
    f64 temp_f1_147;
    f64 temp_f1_153;
    f64 temp_f1_157;
    s32 temp_r3_176;
    s32 var_r0_186;
    void *temp_r3_119;

    M2C_FIELD(this, s8 *, 0x2E) = 0;
    temp_r3_119 = this->unk10->unk8;
    sp20 = M2C_FIELD(temp_r3_119, f64 *, 0x30);
    temp_f7_127 = unksp24 - this->unk34;
    sp28 = M2C_FIELD(temp_r3_119, f64 *, 0x38);
    var_f3_134 = (150.0f * (1.0f - ((temp_f7_127 - 100.0f) / 200.0f))) + 250.0f;
    if ((var_f3_134 + temp_f7_127) > 550.0f) {
        var_f3_134 = 550.0f - temp_f7_127;
    }
    var_f31_144 = 1900.0f * (2.0f * var_f3_134);
    if (var_f31_144 > 0.0f) {
        temp_f1_147 = __frsqrte(var_f31_144);
        temp_f1_153 = 0.5 * temp_f1_147 * -(((f64) var_f31_144 * (temp_f1_147 * temp_f1_147)) - 3.0);
        temp_f1_157 = 0.5 * temp_f1_153 * -(((f64) var_f31_144 * (temp_f1_153 * temp_f1_153)) - 3.0);
        var_f31_144 = (f32) ((f64) var_f31_144 * (0.5 * temp_f1_157 * -(((f64) var_f31_144 * (temp_f1_157 * temp_f1_157)) - 3.0)));
    } else if (var_f31_144 < M2C_BITWISE(f32, 0.0)) {
        var_f31_144 = __float_nan;
    } else {
        sp8 = var_f31_144;
        temp_r3_176 = M2C_BITWISE(s32, sp8) & 0x7F800000;
        switch (temp_r3_176) {                      /* irregular */
        case 0x7F800000:
            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                var_r0_186 = 1;
            } else {
                var_r0_186 = 2;
            }
            break;
        case 0x0:
            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                var_r0_186 = 5;
            } else {
                var_r0_186 = 3;
            }
            break;
        default:
            var_r0_186 = 4;
            break;
        }
        if (var_r0_186 == 1) {
            var_f31_144 = __float_nan;
        }
    }
    this->unk10->SetDesiredVelocityVectical(var_f31_144, 540000.0f);
    this->unk10->SetAnim(0x32U, 0.0f, (Spyro::AnimScriptNode) 0, 0U, 1.0f);
    sp10.GetJumpVel();
    sp30 = sp10;
    sp38 = sp18;
    unksp34 = var_f31_144;
    this->unk10->SetDesiredVelocity(*((MKVector3 *) &sp30), 540000.0f);
    this->unk10->unk430.unk28.SetTailStrikeEnabled(1U);
}
#endif

#if 0 // DRAFT: undefined identifier 'unksp34'
void SpyroJumpState::JumpCommonUpdate() {
    SpyroJumpState sp10;
    f32 sp8;
    InputModifier *temp_r3_254;
    Spyro *temp_r4_282;
    f32 temp_f31_293;
    f32 var_f1_267;
    f32 var_f5_313;
    f64 temp_f1_318;
    f64 temp_f1_324;
    f64 temp_f1_328;
    s32 temp_r3_347;
    s32 var_r0_357;
    u8 var_r4_256;
    void *temp_r3_284;

    temp_r3_254 = this->unk10->GetInput();
    var_r4_256 = 0;
    if (((u8) temp_r3_254->unk5 != 0) || ((u8) temp_r3_254->unk4 != 0)) {
        var_r4_256 = 1;
    }
    if (var_r4_256 != 0) {
        var_f1_267 = 0.0f;
    } else {
        var_f1_267 = MKInput_GetState(0xE, (MKInputDevices) temp_r3_254->unk0, NULL, NULL);
    }
    if (var_f1_267 != 0.0f) {
        if ((u8) M2C_FIELD(this, u8 *, 0x2C) == 0) {
            temp_r4_282 = this->unk10;
            temp_r3_284 = temp_r4_282->unk8;
            sp10.unk20 = M2C_FIELD(temp_r3_284, f64 *, 0x30);
            sp10.unk28 = M2C_FIELD(temp_r3_284, f64 *, 0x38);
            temp_f31_293 = 300.0f - (unksp34 - this->unk34);
            if ((temp_f31_293 < 100.0f) || ((s32) M2C_FIELD(temp_r4_282->unk26C.unk8, s32 *, 0x43C) > 0)) {
                if ((u8) M2C_FIELD(this, u8 *, 0x2D) == 0) {
                    sp10.unk10.GetJumpVel();
                    var_f5_313 = 1900.0f * (2.0f * temp_f31_293);
                    sp10.unk40 = M2C_BITWISE(f64, sp10.unk10);
                    sp10.unk48 = M2C_BITWISE(f64, sp10.unk18);
                    if (var_f5_313 > 0.0f) {
                        temp_f1_318 = __frsqrte(var_f5_313);
                        temp_f1_324 = 0.5 * temp_f1_318 * -(((f64) var_f5_313 * (temp_f1_318 * temp_f1_318)) - 3.0);
                        temp_f1_328 = 0.5 * temp_f1_324 * -(((f64) var_f5_313 * (temp_f1_324 * temp_f1_324)) - 3.0);
                        var_f5_313 = (f32) ((f64) var_f5_313 * (0.5 * temp_f1_328 * -(((f64) var_f5_313 * (temp_f1_328 * temp_f1_328)) - 3.0)));
                    } else if (var_f5_313 < M2C_BITWISE(f32, 0.0)) {
                        var_f5_313 = __float_nan;
                    } else {
                        sp8 = var_f5_313;
                        temp_r3_347 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                        switch (temp_r3_347) {      /* irregular */
                        case 0x7F800000:
                            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                var_r0_357 = 1;
                            } else {
                                var_r0_357 = 2;
                            }
                            break;
                        case 0x0:
                            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                var_r0_357 = 5;
                            } else {
                                var_r0_357 = 3;
                            }
                            break;
                        default:
                            var_r0_357 = 4;
                            break;
                        }
                        if (var_r0_357 == 1) {
                            var_f5_313 = __float_nan;
                        }
                    }
                    unksp54 = var_f5_313;
                    this->unk10->SetDesiredVelocity(*((MKVector3 *) &sp10.unk40), 540000.0f);
                    M2C_FIELD(this, u8 *, 0x2D) = 1U;
                }
            } else {
                sp10.GetJumpVel();
                sp10.unk30 = M2C_BITWISE(f64, sp10);
                sp10.unk38 = sp10.unk8;
                sp10.unk34 = SPYRO_MIN_JUMP_Y_VELOCITY;
                this->unk10->SetDesiredVelocity(*((MKVector3 *) &sp10.unk30), 540000.0f);
            }
        }
    } else {
        M2C_FIELD(this, u8 *, 0x2C) = 1U;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk18'
s32 SpyroJumpState::JumpLoftTransition() {
    InputModifier *temp_r3_433;
    u8 var_r0_434;
    u8 var_r3_422;

    var_r3_422 = M2C_FIELD(this, u8 *, 0x2F);
    if (var_r3_422 != 0) {
        var_r3_422 = GameData::gameData[0x168] & 1;
    }
    if (var_r3_422 != 0) {
        temp_r3_433 = this->unk10->GetInput();
        var_r0_434 = temp_r3_433->unk5;
        if (var_r0_434 == 0) {
            var_r0_434 = temp_r3_433->unk4;
        }
        if (var_r0_434 != 0) {
            var_r3_422 = 0;
        } else {
            var_r3_422 = MKInput_Pressed(0xE, (MKInputDevices) temp_r3_433->unk0);
        }
    }
    if (var_r3_422 != 0) {
        var_r3_422 = M2C_FIELD(this->unk10, u8 *, 0x3D2) == 0;
    }
    if ((var_r3_422 != 0) && ((s32) this->unk18.unk0 != 3)) {
        this->unk18.SetState(this, 3, 0U);
        return 1;
    }
    return 0;
}
#endif

void SpyroJumpState::JumpLoftUpdate() {
    JumpCommonUpdate();
    JumpLoftTransition();
}

void SpyroJumpState::JumpLoftExit() {

}

#if 0 // DRAFT: illegal type
void SpyroJumpState::JumpLoftEnter() {
    s16 spA;
    s16 sp8;
    MKAnim *temp_r31_518;
    MKAnim *temp_r31_547;
    Spyro *temp_r3_512;
    Spyro *temp_r3_539;
    f32 temp_f31_548;

    temp_r3_512 = this->unk10;
    temp_r31_518 = M2C_FIELD((temp_r3_512->unkB4 + (M2C_FIELD(this->unk60, s32 *, 4) * 8)), MKAnim **, 4);
    ((MKAnimScript *) (temp_r3_512->GetAnimScript((Spyro::AnimScriptNode) 0)))->GetStartAndEnd(temp_r31_518, &spA, &sp8);
    temp_r3_539 = this->unk10;
    temp_r31_547 = M2C_FIELD((temp_r3_539->unkB4 + (M2C_FIELD(this->unk60, s32 *, 4) * 8)), MKAnim **, 4);
    temp_f31_548 = ((f32) (sp8 - ((MKAnimScript *) (this->unk10->GetAnimScript((Spyro::AnimScriptNode) 0)))->GetCurrentFrame()) / 30.0f) / 0.3f;
    ((MKAnimScript *) (temp_r3_539->GetAnimScript((Spyro::AnimScriptNode) 0)))->SetAnim(temp_r31_547, temp_f31_548, 0.0f, 0, -1);
}
#endif

#if 0 // DRAFT: undefined identifier 'unk18'
u8 SpyroJumpState::JumpCycleTransition() {
    InputModifier *temp_r3_606;
    u8 var_r0_573;
    u8 var_r0_607;
    u8 var_r3_588;
    u8 var_r3_595;

    var_r0_573 = M2C_FIELD(this, u8 *, 0x2D);
    if (var_r0_573 == 0) {
        var_r0_573 = M2C_FIELD(this, u8 *, 0x2C);
    }
    if ((var_r0_573 != 0) && ((s32) this->unk18.unk0 != 2)) {
        this->unk18.SetState(this, 2, 0U);
        var_r3_588 = 1;
    } else {
        var_r3_588 = 0;
    }
    if (var_r3_588 == 0) {
        var_r3_595 = M2C_FIELD(this, u8 *, 0x2F);
        if (var_r3_595 != 0) {
            var_r3_595 = GameData::gameData[0x168] & 1;
        }
        if (var_r3_595 != 0) {
            temp_r3_606 = this->unk10->GetInput();
            var_r0_607 = temp_r3_606->unk5;
            if (var_r0_607 == 0) {
                var_r0_607 = temp_r3_606->unk4;
            }
            if (var_r0_607 != 0) {
                var_r3_595 = 0;
            } else {
                var_r3_595 = MKInput_Pressed(0xE, (MKInputDevices) temp_r3_606->unk0);
            }
        }
        if (var_r3_595 != 0) {
            var_r3_595 = M2C_FIELD(this->unk10, u8 *, 0x3D2) == 0;
        }
        if ((var_r3_595 != 0) && ((s32) this->unk18.unk0 != 3)) {
            this->unk18.SetState(this, 3, 0U);
            return 1U;
        }
        var_r3_588 = 0;
        /* Duplicate return node #21. Try simplifying control flow for better match */
        return var_r3_588;
    }
    return var_r3_588;
}
#endif

void SpyroJumpState::JumpCycleUpdate() {
    JumpCommonUpdate();
    JumpCycleTransition();
}

void SpyroJumpState::JumpCycleExit() {

}

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void SpyroJumpState::JumpCycleEnter() {
    this->unk10->SetAnim(M2C_FIELD(this->unk60, u32 *, 4), 0.0f, (Spyro::AnimScriptNode) 0, 0U, 1.0f);
}
#endif

#if 0 // DRAFT: undefined identifier 'unk18'
u8 SpyroJumpState::JumpStartTransition() {
    InputModifier *temp_r3_756;
    u8 var_r0_702;
    u8 var_r0_757;
    u8 var_r3_717;
    u8 var_r3_745;

    var_r0_702 = M2C_FIELD(this, u8 *, 0x2D);
    if (var_r0_702 == 0) {
        var_r0_702 = M2C_FIELD(this, u8 *, 0x2C);
    }
    if ((var_r0_702 != 0) && ((s32) this->unk18.unk0 != 2)) {
        this->unk18.SetState(this, 2, 0U);
        var_r3_717 = 1;
    } else {
        var_r3_717 = 0;
    }
    if (var_r3_717 == 0) {
        if ((this->unk10->GetAnimScript((Spyro::AnimScriptNode) 0)->unk2C & 1) && ((s32) this->unk18.unk0 != 1)) {
            this->unk18.SetState(this, 1, 0U);
            var_r3_717 = 1;
        } else {
            var_r3_717 = 0;
        }
    }
    if (var_r3_717 == 0) {
        var_r3_745 = M2C_FIELD(this, u8 *, 0x2F);
        if (var_r3_745 != 0) {
            var_r3_745 = GameData::gameData[0x168] & 1;
        }
        if (var_r3_745 != 0) {
            temp_r3_756 = this->unk10->GetInput();
            var_r0_757 = temp_r3_756->unk5;
            if (var_r0_757 == 0) {
                var_r0_757 = temp_r3_756->unk4;
            }
            if (var_r0_757 != 0) {
                var_r3_745 = 0;
            } else {
                var_r3_745 = MKInput_Pressed(0xE, (MKInputDevices) temp_r3_756->unk0);
            }
        }
        if (var_r3_745 != 0) {
            var_r3_745 = M2C_FIELD(this->unk10, u8 *, 0x3D2) == 0;
        }
        if ((var_r3_745 != 0) && ((s32) this->unk18.unk0 != 3)) {
            this->unk18.SetState(this, 3, 0U);
            return 1U;
        }
        var_r3_717 = 0;
        /* Duplicate return node #26. Try simplifying control flow for better match */
        return var_r3_717;
    }
    return var_r3_717;
}
#endif

void SpyroJumpState::JumpStartUpdate() {
    JumpCommonUpdate();
    JumpStartTransition();
}

void SpyroJumpState::JumpStartExit() {

}

#if 0 // DRAFT: expression syntax error
void SpyroJumpState::JumpStartEnter() {
    M2C_FIELD(this, s8 *, 0x2C) = 0;
    M2C_FIELD(this, s8 *, 0x2D) = 0;
    this->unk10->unk430.unk28.SetTailSweepComboCount(0);
    this->unk10->SetAnim(*this->unk60, 0.2f, (Spyro::AnimScriptNode) 0, 0U, 1.0f);
}
#endif

#if 0 // DRAFT: undefined identifier 'unk18'
s32 SpyroJumpState::Transition() {
    SpyroStateMessages sp8;
    InputModifier *temp_r3_905;
    Spyro *temp_r3_970;
    f32 var_f1_918;
    s8 var_r3_935;
    u8 var_r0_976;
    u8 var_r4_907;

    sp8.unk50 = 0;
    sp8.AddMessage(0x172);
    if ((u8) M2C_FIELD(this, u8 *, 0x2E) != 0) {
        sp8.AddMessage(0x17D);
    }
    if (((u8) M2C_FIELD(this, u8 *, 0x2F) != 0) && ((this->unk18.GetState() == 0) || (this->unk18.GetState() == 1) || (this->unk18.GetState() == 2)) && ((s32) (GameData::gameData[0x168] & 1) == 1)) {
        sp8.AddMessage(0x16F);
    }
    if (this->unk18.GetState() == 3) {
        temp_r3_905 = this->unk10->GetInput();
        var_r4_907 = 0;
        if (((u8) temp_r3_905->unk5 != 0) || ((u8) temp_r3_905->unk4 != 0)) {
            var_r4_907 = 1;
        }
        if (var_r4_907 != 0) {
            var_f1_918 = 0.0f;
        } else {
            var_f1_918 = MKInput_GetState(0xE, (MKInputDevices) temp_r3_905->unk0, NULL, NULL);
        }
        if (var_f1_918 != 0.0f) {
            sp8.AddMessage(0x16D);
        }
    }
    var_r3_935 = this->unk10->SpikyTransition();
    if ((u8) var_r3_935 == 0) {
        var_r3_935 = this->unk10->LavaTransition();
    }
    if ((u8) var_r3_935 == 0) {
        var_r3_935 = this->unk10->AirToStrafeDodgeTransition();
    }
    if ((u8) var_r3_935 == 0) {
        var_r3_935 = this->unk10->TailSweepTailStrikeTransition();
    }
    if ((u8) var_r3_935 == 0) {
        this->unk10->HornDiveTranstion();
    }
    if ((u8) M2C_ERROR(/* Read from unset register $r3 */) == 0) {
        if (this->unk18.GetLastState() == 2) {
            this->unk10->AirToLedgeGrabTransition();
        }
    }
    if ((u8) M2C_ERROR(/* Read from unset register $r3 */) == 0) {
        temp_r3_970 = this->unk10;
        var_r0_976 = ((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1DU) & 1;
        if (var_r0_976 == 0) {
            var_r0_976 = this->unk3C > 1.0f;
        }
        if ((var_r0_976 != 0) && ((s32) temp_r3_970->unk54.unk8 != 6)) {
            temp_r3_970->unk54.SetState(6, sp8);
        }
    }
}
#endif

#if 0 // DRAFT: pointer/array required
void SpyroJumpState::Update() {
    f64 sp270;
    f64 sp268;
    f64 sp260;
    f64 sp258;
    s32 sp254;
    s32 sp250;
    f64 sp248;
    f64 sp240;
    s32 sp23C;
    s32 sp238;
    f64 sp230;
    f64 sp228;
    f64 sp220;
    f64 sp218;
    f64 sp210;                                      /* compiler-managed */
    f64 sp208;                                      /* compiler-managed */
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
    f64 sp188;
    f64 sp180;
    f64 sp178;
    f64 sp170;
    f64 sp168;
    f64 sp160;
    f64 sp158;
    f64 sp148;
    MKVector3 sp138;
    MKVector3 sp128;
    f64 sp120;
    f64 sp118;
    f64 sp110;
    f64 sp108;
    f64 sp100;
    f64 spF8;
    f64 spE8;
    f64 spE0;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    f32 spC0;
    f64 spB8;
    f32 spB0;
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
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    InputModifier *temp_r3_1064;
    MKProp *temp_r3_1024;
    MKProp *temp_r3_1749;
    Spyro *temp_r3_1276;
    Spyro *temp_r3_1289;
    Spyro *temp_r3_1740;
    Spyro *temp_r4_1780;
    f32 temp_f0_1612;
    f32 temp_f1_1454;
    f32 temp_f1_1516;
    f32 temp_f1_1519;
    f32 temp_f2_1611;
    f32 temp_f30_1321;
    f32 temp_f4_1614;
    f32 var_f1_1077;
    f32 var_f1_1548;
    f32 var_f1_1718;
    f32 var_f27_1431;
    f32 var_f2_1509;
    f32 var_f2_1725;
    f32 var_f4_1130;
    f32 var_f4_1322;
    f32 var_f5_1147;
    f32 var_f5_1360;
    f32 var_f5_1619;
    f64 temp_f0_1128;
    f64 temp_f0_1308;
    f64 temp_f0_1332;
    f64 temp_f0_1691;
    f64 temp_f0_1786;
    f64 temp_f1_1152;
    f64 temp_f1_1158;
    f64 temp_f1_1162;
    f64 temp_f1_1305;
    f64 temp_f1_1365;
    f64 temp_f1_1371;
    f64 temp_f1_1375;
    f64 temp_f2_1551;
    f64 temp_f2_1557;
    f64 temp_f2_1561;
    f64 temp_f2_1622;
    f64 temp_f2_1628;
    f64 temp_f2_1632;
    s32 temp_r3_1026;
    s32 temp_r3_1181;
    s32 temp_r3_1394;
    s32 temp_r3_1580;
    s32 temp_r3_1651;
    s32 temp_r3_1751;
    s32 temp_r4_1810;
    s32 var_r0_1191;
    s32 var_r0_1404;
    s32 var_r0_1590;
    s32 var_r0_1661;
    u32 var_r0_1768;
    u8 var_r4_1066;
    void *temp_r3_1117;
    void *temp_r3_1726;
    void *temp_r3_1765;
    void *temp_r3_1809;
    void *temp_r3_1823;
    void *temp_r4_1290;
    void *temp_r5_1116;
    void *var_r3_1757;
    void *var_r3_1815;
    void *var_r3_1826;
    void *var_r4_1032;

    temp_r3_1024 = this->unk10->unk26C.unk8;
    temp_r3_1026 = M2C_FIELD(temp_r3_1024, s32 *, 0x2D4);
    if (temp_r3_1026 > 0) {
        if (temp_r3_1026 != 0) {
            var_r4_1032 = temp_r3_1024 + 0x170 + ((temp_r3_1026 - 1) * 0x58);
        } else {
            var_r4_1032 = NULL;
        }
        if (((M2C_FIELD(var_r4_1032, f32 *, 0x18) * MKVector3::one.unk8) + ((M2C_FIELD(var_r4_1032, f32 *, 0x10) * MKVector3::one.unk0) + (M2C_FIELD(var_r4_1032, f32 *, 0x14) * MKVector3::one.unk4))) < -0.8f) {
            this->unk3C += gUpdateTimeDelta;
        } else {
            goto block_6;
        }
    } else {
block_6:
        this->unk3C = 0.0f;
    }
    if ((u8) this->unk30 != 0) {
        temp_r3_1064 = this->unk10->GetInput();
        var_r4_1066 = 0;
        if (((u8) temp_r3_1064->unk5 != 0) || ((u8) temp_r3_1064->unk4 != 0)) {
            var_r4_1066 = 1;
        }
        if (var_r4_1066 != 0) {
            var_f1_1077 = 0.0f;
        } else {
            var_f1_1077 = MKInput_GetState(0xA, (MKInputDevices) temp_r3_1064->unk0, NULL, NULL);
        }
        if (var_f1_1077 == 0.0f) {
            SetStrafeJump(0U);
        } else {
            this->unk10->unkB90.GetCurrentTarget();
            if ((u32) M2C_ERROR(/* Read from unset register $r3 */) == 0U) {
                this->unk10->SelectStrafeTarget(0U);
            }
            this->unk10->unkB90.GetCurrentTarget();
            if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
                this->unk10->unkB90.GetCurrentTarget();
                temp_r5_1116 = M2C_FIELD(M2C_FIELD(*M2C_ERROR(/* Read from unset register $r3 */), void *(**)(), 8)(), void **, 8);
                temp_r3_1117 = this->unk10->unk8;
                sp218 = M2C_FIELD(temp_r5_1116, f64 *, 0x30);
                sp1A8 = M2C_FIELD(temp_r3_1117, f64 *, 0x30);
                sp220 = M2C_FIELD(temp_r5_1116, f64 *, 0x38);
                sp1B0 = M2C_FIELD(temp_r3_1117, f64 *, 0x38);
                temp_f0_1128 = sp218 - sp1A8;
                spB8 = temp_f0_1128;
                var_f4_1130 = 0.0f;
                sp208 = temp_f0_1128;
                unksp20C = 0.0f;
                spC0 = (f32) sp220 - (f32) sp1B0;
                sp210 = (f64) spC0;
                var_f5_1147 = ((f32) sp210 * (f32) sp210) + (((f32) sp208 * (f32) sp208) + (0.0f * 0.0f));
                if (var_f5_1147 > 0.000001f) {
                    if (var_f5_1147 > 0.0f) {
                        temp_f1_1152 = __frsqrte(var_f5_1147);
                        temp_f1_1158 = 0.5 * temp_f1_1152 * -(((f64) var_f5_1147 * (temp_f1_1152 * temp_f1_1152)) - 3.0);
                        temp_f1_1162 = 0.5 * temp_f1_1158 * -(((f64) var_f5_1147 * (temp_f1_1158 * temp_f1_1158)) - 3.0);
                        var_f5_1147 = (f32) ((f64) var_f5_1147 * (0.5 * temp_f1_1162 * -(((f64) var_f5_1147 * (temp_f1_1162 * temp_f1_1162)) - 3.0)));
                    } else if (var_f5_1147 < M2C_BITWISE(f32, 0.0)) {
                        var_f5_1147 = __float_nan;
                    } else {
                        sp14 = var_f5_1147;
                        temp_r3_1181 = M2C_BITWISE(s32, sp14) & 0x7F800000;
                        switch (temp_r3_1181) {     /* switch 1; irregular */
                        case 0x7F800000:            /* switch 1 */
                            if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                                var_r0_1191 = 1;
                            } else {
                                var_r0_1191 = 2;
                            }
                            break;
                        case 0x0:                   /* switch 1 */
                            if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                                var_r0_1191 = 5;
                            } else {
                                var_r0_1191 = 3;
                            }
                            break;
                        default:                    /* switch 1 */
                            var_r0_1191 = 4;
                            break;
                        }
                        if (var_r0_1191 == 1) {
                            var_f5_1147 = __float_nan;
                        }
                    }
                    var_f4_1130 = 1.0f / var_f5_1147;
                }
                sp208 = (f32) sp208 * var_f4_1130;
                unksp20C *= var_f4_1130;
                sp210 = (f32) sp210 * var_f4_1130;
                sp228 = (f64) sp208;
                sp230 = (f64) sp210;
                this->unk10->unk3A0.YawTowards(*((MKVector3 *) &sp208), 15.0f);
            } else {
                this->unk10->unk8->ZAxis3();
                sp18 = -*M2C_ERROR(/* Read from unset register $r3 */);
                sp1C = -M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), f32 *, 4);
                sp20 = -M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), f32 *, 8);
                sp198 = (f64) sp18;
                sp1A0 = (f64) sp20;
                sp228 = (f64) sp18;
                sp230 = (f64) sp20;
            }
            sp23C = 0;
            sp238 = 0x43E;
            sp240 = sp228;
            sp248 = sp230;
            sp188 = sp228;
            sp190 = sp230;
            M2C_FIELD(this->unk10->GetCamera()->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp238);
        }
    }
    this->unk18.Update(this, 0);
    temp_r3_1276 = this->unk10;
    if ((s32) temp_r3_1276->unk54.unk8 == 5) {
        if (temp_r3_1276->IsPlayingStrafeAnim() != 0) {
            if (((KDInput *) (this->unk10->GetInput()))->GetLeftMag() != 0.0f) {
                temp_r3_1289 = this->unk10;
                temp_r4_1290 = temp_r3_1289->unk8;
                sp48 = -M2C_FIELD(temp_r4_1290, f32 *, 0x20);
                sp4C = -M2C_FIELD(temp_r4_1290, f32 *, 0x24);
                sp50 = -M2C_FIELD(temp_r4_1290, f32 *, 0x28);
                sp1F8 = (f64) sp48;
                sp200 = (f64) sp50;
                temp_f1_1305 = ((InputModifier *) (temp_r3_1289->GetInput()))->GetLeftY();
                temp_f0_1308 = sp1F8 * temp_f1_1305;
                spA8 = temp_f0_1308;
                sp1E8 = temp_f0_1308;
                spB0 = (f32) sp200 * (f32) temp_f1_1305;
                sp1F0 = (f64) spB0;
                temp_f30_1321 = ((InputModifier *) (this->unk10->GetInput()))->GetLeftX();
                var_f4_1322 = 0.0f;
                sp98 = (f32) sp200;
                sp9C = 0.0f;
                spA0 = -(f32) sp1F8;
                sp178 = (f64) sp98;
                sp180 = (f64) spA0;
                temp_f0_1332 = sp178 * (f64) temp_f30_1321;
                sp88 = temp_f0_1332;
                sp1D8 = temp_f0_1332;
                sp90 = (f32) sp180 * temp_f30_1321;
                sp1E0 = (f64) sp90;
                sp78 = sp1E8 + temp_f0_1332;
                sp168 = sp78;
                sp80 = (f32) sp1F0 + (f32) sp1E0;
                sp170 = (f64) sp80;
                var_f5_1360 = ((f32) sp170 * (f32) sp170) + (((f32) sp168 * (f32) sp168) + (unksp16C * unksp16C));
                if (var_f5_1360 > 1e-12f) {
                    if (var_f5_1360 > 0.0f) {
                        temp_f1_1365 = __frsqrte(var_f5_1360);
                        temp_f1_1371 = 0.5 * temp_f1_1365 * -(((f64) var_f5_1360 * (temp_f1_1365 * temp_f1_1365)) - 3.0);
                        temp_f1_1375 = 0.5 * temp_f1_1371 * -(((f64) var_f5_1360 * (temp_f1_1371 * temp_f1_1371)) - 3.0);
                        var_f5_1360 = (f32) ((f64) var_f5_1360 * (0.5 * temp_f1_1375 * -(((f64) var_f5_1360 * (temp_f1_1375 * temp_f1_1375)) - 3.0)));
                    } else if (var_f5_1360 < M2C_BITWISE(f32, 0.0)) {
                        var_f5_1360 = __float_nan;
                    } else {
                        sp10 = var_f5_1360;
                        temp_r3_1394 = M2C_BITWISE(s32, sp10) & 0x7F800000;
                        switch (temp_r3_1394) {     /* switch 2; irregular */
                        case 0x7F800000:            /* switch 2 */
                            if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                                var_r0_1404 = 1;
                            } else {
                                var_r0_1404 = 2;
                            }
                            break;
                        case 0x0:                   /* switch 2 */
                            if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                                var_r0_1404 = 5;
                            } else {
                                var_r0_1404 = 3;
                            }
                            break;
                        default:                    /* switch 2 */
                            var_r0_1404 = 4;
                            break;
                        }
                        if (var_r0_1404 == 1) {
                            var_f5_1360 = __float_nan;
                        }
                    }
                    var_f4_1322 = 1.0f / var_f5_1360;
                }
                var_f27_1431 = 0.0f;
                sp6C = unksp16C * var_f4_1322;
                sp68 = (f32) sp168 * var_f4_1322;
                sp70 = (f32) sp170 * var_f4_1322;
                sp1C8 = (f64) sp68;
                sp1D0 = (f64) sp70;
                if ((((f32) sp1D0 * (f32) sp1D0) + (((f32) sp1C8 * (f32) sp1C8) + (unksp1CC * unksp1CC))) != 0.0f) {
                    temp_f1_1454 = ((f32) sp1D0 * (f32) sp200) + (((f32) sp1C8 * (f32) sp1F8) + (unksp1CC * unksp1FC));
                    if ((temp_f1_1454 > 0.5f) || (temp_f1_1454 < -0.5f)) {
                        var_f27_1431 = 0.75f * (750.0f * ((KDInput *) (this->unk10->GetInput()))->GetLeftMag());
                    } else {
                        var_f27_1431 = 750.0f * ((KDInput *) (this->unk10->GetInput()))->GetLeftMag();
                    }
                }
                sp58 = sp1C8 * (f64) var_f27_1431;
                sp60 = (f32) sp1D0 * var_f27_1431;
                sp158 = sp58;
                sp160 = (f64) sp60;
                this->unk10->SetDesiredVelocityHoriz(*((MKVector3 *) &sp158), 3800.0f);
            } else {
                this->unk10->SetDesiredVelocityHoriz(MKVector3::zero, 3800.0f);
            }
        } else {
            if (((KDInput *) (this->unk10->GetInput()))->GetLeftMag() != 0.0f) {
                var_f2_1509 = 0.5f * (6.0f * gUpdateTimeDelta);
                if (var_f2_1509 < 1.0f) {

                } else {
                    var_f2_1509 = 1.0f;
                }
                temp_f1_1516 = this->unk14;
                temp_f1_1519 = (var_f2_1509 * (2.3999999f - temp_f1_1516)) + temp_f1_1516;
                this->unk14 = (var_f2_1509 * (2.3999999f - temp_f1_1519)) + temp_f1_1519;
            }
            sp148.GetJumpVel();
            sp1B8 = sp148;
            sp1C0 = sp150;
            KDMath_Dampen<MKVector3>(sp138, 2.0f, gUpdateTimeDelta);
            this->unk40 = M2C_BITWISE(f64, sp138);
            this->unk48 = (f64) sp138.unk8;
            var_f1_1548 = ((f32) sp1C0 * (f32) sp1C0) + (((f32) sp1B8 * (f32) sp1B8) + (unksp1BC * unksp1BC));
            if (var_f1_1548 > 0.0f) {
                temp_f2_1551 = __frsqrte(var_f1_1548);
                temp_f2_1557 = 0.5 * temp_f2_1551 * -(((f64) var_f1_1548 * (temp_f2_1551 * temp_f2_1551)) - 3.0);
                temp_f2_1561 = 0.5 * temp_f2_1557 * -(((f64) var_f1_1548 * (temp_f2_1557 * temp_f2_1557)) - 3.0);
                var_f1_1548 = (f32) ((f64) var_f1_1548 * (0.5 * temp_f2_1561 * -(((f64) var_f1_1548 * (temp_f2_1561 * temp_f2_1561)) - 3.0)));
            } else if (var_f1_1548 < M2C_BITWISE(f32, 0.0)) {
                var_f1_1548 = __float_nan;
            } else {
                spC = var_f1_1548;
                temp_r3_1580 = M2C_BITWISE(s32, spC) & 0x7F800000;
                switch (temp_r3_1580) {             /* switch 3; irregular */
                case 0x7F800000:                    /* switch 3 */
                    if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                        var_r0_1590 = 1;
                    } else {
                        var_r0_1590 = 2;
                    }
                    break;
                case 0x0:                           /* switch 3 */
                    if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                        var_r0_1590 = 5;
                    } else {
                        var_r0_1590 = 3;
                    }
                    break;
                default:                            /* switch 3 */
                    var_r0_1590 = 4;
                    break;
                }
                if (var_r0_1590 == 1) {
                    var_f1_1548 = __float_nan;
                }
            }
            temp_f2_1611 = (f32) M2C_FIELD(this, f64 *, 0x40);
            temp_f0_1612 = M2C_FIELD(this, f32 *, 0x44);
            temp_f4_1614 = (f32) M2C_FIELD(this, f64 *, 0x48);
            var_f5_1619 = (temp_f4_1614 * temp_f4_1614) + ((temp_f2_1611 * temp_f2_1611) + (temp_f0_1612 * temp_f0_1612));
            if (var_f5_1619 > 0.0f) {
                temp_f2_1622 = __frsqrte(var_f5_1619);
                temp_f2_1628 = 0.5 * temp_f2_1622 * -(((f64) var_f5_1619 * (temp_f2_1622 * temp_f2_1622)) - 3.0);
                temp_f2_1632 = 0.5 * temp_f2_1628 * -(((f64) var_f5_1619 * (temp_f2_1628 * temp_f2_1628)) - 3.0);
                var_f5_1619 = (f32) ((f64) var_f5_1619 * (0.5 * temp_f2_1632 * -(((f64) var_f5_1619 * (temp_f2_1632 * temp_f2_1632)) - 3.0)));
            } else if (var_f5_1619 < M2C_BITWISE(f32, 0.0)) {
                var_f5_1619 = __float_nan;
            } else {
                sp8 = var_f5_1619;
                temp_r3_1651 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                switch (temp_r3_1651) {             /* switch 4; irregular */
                case 0x7F800000:                    /* switch 4 */
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_1661 = 1;
                    } else {
                        var_r0_1661 = 2;
                    }
                    break;
                case 0x0:                           /* switch 4 */
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_1661 = 5;
                    } else {
                        var_r0_1661 = 3;
                    }
                    break;
                default:                            /* switch 4 */
                    var_r0_1661 = 4;
                    break;
                }
                if (var_r0_1661 == 1) {
                    var_f5_1619 = __float_nan;
                }
            }
            if (var_f1_1548 > var_f5_1619) {

            } else {
                var_f1_1548 = var_f5_1619;
            }
            temp_f0_1691 = sp1B8 + this->unk40;
            sp38 = temp_f0_1691;
            sp118 = temp_f0_1691;
            sp40 = (f32) sp1C0 + (f32) M2C_FIELD(this, f64 *, 0x48);
            sp120 = (f64) sp40;
            ClampMagnitude(sp128, var_f1_1548);
            sp1B8 = M2C_BITWISE(f64, sp128);
            sp1C0 = (f64) sp128.unk8;
            this->unk10->SetDesiredVelocityHoriz(*((MKVector3 *) &sp1B8), 3800.0f);
            if ((u8) M2C_FIELD(this, u8 *, 0x2E) != 0) {
                var_f1_1718 = 3.5f;
            } else {
                var_f1_1718 = 900.0f;
            }
            this->unk10->unk3A0.YawTowards(*((MKVector3 *) &sp1B8), var_f1_1718);
            var_f2_1725 = this->unk38;
            temp_r3_1726 = this->unk10->unk8;
            sp108 = M2C_FIELD(temp_r3_1726, f64 *, 0x30);
            sp110 = M2C_FIELD(temp_r3_1726, f64 *, 0x38);
            if (var_f2_1725 > unksp10C) {

            } else {
                var_f2_1725 = unksp10C;
            }
            this->unk38 = var_f2_1725;
        }
        temp_r3_1740 = this->unk10;
        spF8 = M2C_FIELD(temp_r3_1740, f64 *, 0x338);
        sp100 = M2C_FIELD(temp_r3_1740, f64 *, 0x340);
        if (unkspFC > 0.0f) {
            temp_r3_1749 = temp_r3_1740->unk26C.unk8;
            temp_r3_1751 = M2C_FIELD(temp_r3_1749, s32 *, 0x43C);
            if (temp_r3_1751 > 0) {
                if (temp_r3_1751 != 0) {
                    var_r3_1757 = temp_r3_1749 + 0x2D8 + ((temp_r3_1751 - 1) * 0x58);
                } else {
                    var_r3_1757 = NULL;
                }
                if (((u8) M2C_FIELD(var_r3_1757, u8 *, 0x50) != 0) && (temp_r3_1765 = M2C_FIELD(var_r3_1757, void **, 0x48), ((temp_r3_1765 == NULL) == 0)) && (var_r0_1768 = M2C_FIELD(temp_r3_1765, u32 *, 8), ((var_r0_1768 == 0U) == 0))) {

                } else {
                    var_r0_1768 = 0U;
                }
                if (var_r0_1768 != 0U) {
                    sp254 = 0;
                    temp_r4_1780 = this->unk10;
                    spC8 = M2C_FIELD(temp_r4_1780, f64 *, 0x338);
                    spD0 = M2C_FIELD(temp_r4_1780, f64 *, 0x340);
                    temp_f0_1786 = spC8 * 5.164075695e-315;
                    sp28 = temp_f0_1786;
                    spD8 = temp_f0_1786;
                    sp30 = (f32) spD0 * 0.2f;
                    spE0 = (f64) sp30;
                    spE8.GetCollisionCentre();
                    sp258 = spE8;
                    sp260 = spF0;
                    sp268 = spD8;
                    sp270 = spE0;
                    sp250 = 0x3C;
                    temp_r3_1809 = this->unk10->unk26C.unk8 + 0x2D8;
                    temp_r4_1810 = M2C_FIELD(temp_r3_1809, s32 *, 0x164);
                    if (temp_r4_1810 != 0) {
                        var_r3_1815 = temp_r3_1809 + ((temp_r4_1810 - 1) * 0x58);
                    } else {
                        var_r3_1815 = NULL;
                    }
                    if (((u8) M2C_FIELD(var_r3_1815, u8 *, 0x50) != 0) && (temp_r3_1823 = M2C_FIELD(var_r3_1815, void **, 0x48), ((temp_r3_1823 == NULL) == 0)) && (var_r3_1826 = M2C_FIELD(temp_r3_1823, void **, 8), ((var_r3_1826 == NULL) == 0))) {

                    } else {
                        var_r3_1826 = NULL;
                    }
                    M2C_FIELD(M2C_FIELD(var_r3_1826, void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp250);
                }
            }
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk18'
void SpyroJumpState::Exit() {
    s32 spC;
    s32 sp8;
    KDCamera *temp_r3_1984;
    Spyro *temp_r3_1994;
    Spyro *temp_r3_1998;

    this->unk18.Exit(this);
    M2C_FIELD(this->unk10, s8 *, 0x3D2) = 0;
    M2C_FIELD(this->unk10, f32 *, 0x388) = 0.0f;
    SetStrafeJump(0U);
    temp_r3_1984 = this->unk10->GetCamera();
    spC = 0;
    sp8 = 0x43F;
    M2C_FIELD(temp_r3_1984->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp8);
    temp_r3_1994 = this->unk10;
    temp_r3_1994->unk428 |= 0x20000;
    temp_r3_1998 = this->unk10;
    temp_r3_1998->unk428 &= 0xFFFF7FFF;
}
#endif

#if 0 // DRAFT: expression syntax error
void SpyroJumpState::GetJumpVel() {
    f64 sp38;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    f32 temp_f31_2048;
    f64 temp_f0_2029;
    f64 temp_f0_2050;
    void *temp_r31_2018;

    temp_r31_2018 = M2C_ERROR(/* Read from unset register $r4 */);
    if ((u8) M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), u8 *, 0x2E) != 0) {
        sp38.CalcYawTurnDir(3.5f);
        temp_f0_2029 = sp38 * 5.655816876e-315;
        sp18 = temp_f0_2029;
        M2C_FIELD(this, f64 *, 0) = temp_f0_2029;
        sp20 = sp40 * 750.0f;
        this->unk8 = (f64) sp20;
        return;
    }
    sp28.CalcVelTurnDir(M2C_FIELD(temp_r31_2018, f32 *, 0x14));
    temp_f31_2048 = 750.0f * ((KDInput *) (((Spyro *) (M2C_FIELD(temp_r31_2018, Spyro **, 0x10)))->GetInput()))->GetLeftMag();
    temp_f0_2050 = sp28 * (f64) temp_f31_2048;
    sp8 = temp_f0_2050;
    M2C_FIELD(this, f64 *, 0) = temp_f0_2050;
    sp10 = sp30 * temp_f31_2048;
    this->unk8 = (f64) sp10;
}
#endif

#if 0 // DRAFT: expression syntax error
void SpyroJumpState::Enter(SpyroStateMessages &arg0) {
    f64 sp48;
    f64 sp40;
    s32 sp38;
    s32 sp34;
    s32 sp30;
    f64 sp20;
    f64 sp18;
    f64 sp10;
    s32 spC;
    s32 sp8;
    KDCamera *temp_r3_2205;
    Spyro *temp_r3_2148;
    Spyro *temp_r5_2085;
    Spyro *temp_r5_2089;
    f64 temp_f1_2222;
    s32 var_r5_2193;
    u8 var_r29_2179;
    void *temp_r3_2137;
    void *temp_r3_2232;
    void *temp_r6_2219;

    this->unk30 = 0;
    this->unk3C = 0.0f;
    temp_r5_2085 = this->unk10;
    temp_r5_2085->unk428 |= 0x8007;
    temp_r5_2089 = this->unk10;
    temp_r5_2089->unk428 &= 0xFFFDFFD7;
    this->unk10->unk430.unk28.SetTailSweepEnabled(1U);
    this->unk10->unk430.unk28.SetHornDiveEnabled(1U);
    if (arg0.IsMessageOnList(0x178) != 0) {
        SetStrafeJump(1U);
        this->unk60 = &this->unk58;
    } else {
        this->unk60 = &this->unk50;
    }
    M2C_FIELD(this, s8 *, 0x2F) = arg0.IsMessageOnList(0x16F);
    M2C_FIELD(this, s8 *, 0x2E) = arg0.IsMessageOnList(0x17D);
    this->unk14 = 24.0f;
    M2C_FIELD(this, f32 *, 0x40) = 0.0f;
    M2C_FIELD(this, f32 *, 0x44) = 0.0f;
    M2C_FIELD(this, f32 *, 0x48) = 0.0f;
    if (arg0.IsMessageOnList(0x177) != 0) {
        temp_r3_2137 = checked_cast<SpyroProjectVelMsg *, MKMessage>(arg0.GetMessage(0x177));
        this->unk40 = M2C_FIELD(temp_r3_2137, f64 *, 8);
        this->unk48 = M2C_FIELD(temp_r3_2137, f64 *, 0x10);
        this->unk10->SetDesiredVelocityVectical(M2C_FIELD(this, f32 *, 0x44), 540000.0f);
    } else {
        temp_r3_2148 = this->unk10;
        if (((u8) M2C_FIELD(temp_r3_2148, u8 *, 0x3D2) != 0) || ((u8) M2C_FIELD(temp_r3_2148, u8 *, 0x3D1) != 0)) {
            M2C_FIELD(temp_r3_2148, f32 *, 0x38C) = 3420.0f;
            this->unk10->SetDesiredVelocityVectical(600.0f, 540000.0f);
        } else {
            sp20.GetJumpVel();
            sp40 = sp20;
            sp48 = sp28;
            unksp44 = SPYRO_MIN_JUMP_Y_VELOCITY;
            this->unk10->SetDesiredVelocity(*((MKVector3 *) &sp40), 540000.0f);
        }
    }
    var_r29_2179 = 0;
    if (((s32) (GameData::gameData[0x168] & 1) == 1) && (arg0.IsMessageOnList(0x16E) != 0)) {
        var_r29_2179 = 1;
    }
    var_r5_2193 = 0;
    if (var_r29_2179 != 0) {
        var_r5_2193 = 3;
    }
    this->unk18.SetState(this, var_r5_2193, 0U);
    M2C_FIELD(this->unk10, f32 *, 0x388) = 0.5f;
    temp_r3_2205 = this->unk10->GetCamera();
    spC = 0;
    sp8 = 0x414;
    M2C_FIELD(temp_r3_2205->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp8);
    temp_r6_2219 = this->unk10->unk8;
    temp_f1_2222 = M2C_FIELD(temp_r6_2219, f64 *, 0x38);
    sp10 = M2C_FIELD(temp_r6_2219, f64 *, 0x30);
    sp18 = temp_f1_2222;
    this->unk34 = unksp14;
    this->unk38 = unksp14;
    sp34 = 0;
    sp30 = 0x17;
    sp38 = 9;
    temp_r3_2232 = this->unk10->unkB70;
    M2C_FIELD(M2C_FIELD(temp_r3_2232, void **, 0x44), M2C_UNK (**)(void *, s32 *, M2C_UNK, void *, f64), 0x2C)(temp_r3_2232, &sp30, 0, temp_r6_2219, temp_f1_2222);
}
#endif

#if 0 // DRAFT: undefined identifier 'unk18'
void SpyroJumpState::Deinit() {
    this->unk18.Deinit(this);
}
#endif

#if 0 // DRAFT: undefined identifier 'Init__32KDStateMachine'
void SpyroJumpState::Init(Spyro *arg0) {
    this->unk10 = arg0;
    Init__32KDStateMachine<14SpyroJumpState>FPQ232KDStateMachine<14SpyroJumpState>5StateP32KDStateMachine<14SpyroJumpState>(&this->unk18, (KDStateMachine<SpyroJumpState>::State *) &SpyroJumpState::states, NULL);
    this->unk14 = 0.0f;
    M2C_FIELD(this, s8 *, 0x2E) = 0;
    this->unk34 = 0.0f;
    this->unk38 = 0.0f;
    M2C_FIELD(this, s8 *, 0x2C) = 0;
    M2C_FIELD(this, s8 *, 0x2D) = 0;
    M2C_FIELD(this, s8 *, 0x2F) = 0;
    this->unk30 = 0;
    this->unk50 = 0x30;
    this->unk54 = 0x31;
    this->unk58 = 0x19;
    this->unk5C = 0x19;
    this->unk60 = &this->unk50;
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_728'
void SpyroJumpState_cpp::__sinit() {
    f64 temp_f0_2609;
    f64 temp_f1_2579;
    f64 temp_f1_2603;
    f64 temp_f3_2565;
    f64 temp_f3_2606;
    f64 temp_f4_2578;
    f64 temp_f4_2600;
    f64 temp_f8_2567;
    void *temp_r3_2570;

    temp_f3_2565 = __frsqrte(2014000.0);
    temp_f8_2567 = __frsqrte(380000.0);
    temp_r3_2570 = &lit_728 + 0x90;
    temp_f4_2578 = 0.5 * temp_f3_2565 * -((2014000.0 * (temp_f3_2565 * temp_f3_2565)) - 3.0);
    temp_f1_2579 = 0.5 * temp_f8_2567 * -((380000.0 * (temp_f8_2567 * temp_f8_2567)) - 3.0);
    temp_f4_2600 = 0.5 * temp_f4_2578 * -((2014000.0 * (temp_f4_2578 * temp_f4_2578)) - 3.0);
    temp_f1_2603 = 0.5 * temp_f1_2579 * -((380000.0 * (temp_f1_2579 * temp_f1_2579)) - 3.0);
    temp_f3_2606 = temp_f4_2600 * temp_f4_2600;
    temp_f0_2609 = temp_f1_2603 * temp_f1_2603;
    M2C_FIELD(&lit_728, s32 *, 0x90) = (s32) M2C_FIELD(&lit_728, s32 *, 0);
    M2C_FIELD(&lit_728, s32 *, 0x94) = (s32) M2C_FIELD(&lit_728, s32 *, 4);
    M2C_FIELD(&lit_728, s32 *, 0x98) = (s32) M2C_FIELD(&lit_728, s32 *, 8);
    M2C_FIELD(temp_r3_2570, s32 *, 0xC) = (s32) M2C_FIELD(&lit_728, s32 *, 0xC);
    M2C_FIELD(temp_r3_2570, s32 *, 0x10) = (s32) M2C_FIELD(&lit_728, s32 *, 0x10);
    M2C_FIELD(temp_r3_2570, s32 *, 0x14) = (s32) M2C_FIELD(&lit_728, s32 *, 0x14);
    M2C_FIELD(temp_r3_2570, s32 *, 0x18) = (s32) M2C_FIELD(&lit_728, s32 *, 0x18);
    M2C_FIELD(temp_r3_2570, s32 *, 0x1C) = (s32) M2C_FIELD(&lit_728, s32 *, 0x1C);
    M2C_FIELD(temp_r3_2570, s32 *, 0x20) = (s32) M2C_FIELD(&lit_728, s32 *, 0x20);
    M2C_FIELD(temp_r3_2570, s32 *, 0x24) = (s32) M2C_FIELD(&lit_728, s32 *, 0x24);
    M2C_FIELD(temp_r3_2570, s32 *, 0x28) = (s32) M2C_FIELD(&lit_728, s32 *, 0x28);
    M2C_FIELD(temp_r3_2570, s32 *, 0x2C) = (s32) M2C_FIELD(&lit_728, s32 *, 0x2C);
    M2C_FIELD(temp_r3_2570, s32 *, 0x30) = (s32) M2C_FIELD(&lit_728, s32 *, 0x30);
    M2C_FIELD(temp_r3_2570, s32 *, 0x34) = (s32) M2C_FIELD(&lit_728, s32 *, 0x34);
    M2C_FIELD(temp_r3_2570, s32 *, 0x38) = (s32) M2C_FIELD(&lit_728, s32 *, 0x38);
    M2C_FIELD(temp_r3_2570, s32 *, 0x3C) = (s32) M2C_FIELD(&lit_728, s32 *, 0x3C);
    M2C_FIELD(temp_r3_2570, s32 *, 0x40) = (s32) M2C_FIELD(&lit_728, s32 *, 0x40);
    M2C_FIELD(temp_r3_2570, s32 *, 0x44) = (s32) M2C_FIELD(&lit_728, s32 *, 0x44);
    SPYRO_BOUNCE_Y_SPEED = (f32) (2014000.0 * (0.5 * temp_f4_2600 * -((2014000.0 * temp_f3_2606) - 3.0)));
    SPYRO_MIN_JUMP_Y_VELOCITY = (f32) (380000.0 * (0.5 * temp_f1_2603 * -((380000.0 * temp_f0_2609) - 3.0)));
    M2C_FIELD(temp_r3_2570, s32 *, 0x48) = (s32) M2C_FIELD(&lit_728, s32 *, 0x48);
    M2C_FIELD(temp_r3_2570, s32 *, 0x4C) = (s32) M2C_FIELD(&lit_728, s32 *, 0x4C);
    M2C_FIELD(temp_r3_2570, s32 *, 0x50) = (s32) M2C_FIELD(&lit_728, s32 *, 0x50);
    M2C_FIELD(temp_r3_2570, s32 *, 0x54) = (s32) M2C_FIELD(&lit_728, s32 *, 0x54);
    M2C_FIELD(temp_r3_2570, s32 *, 0x58) = (s32) M2C_FIELD(&lit_728, s32 *, 0x58);
    M2C_FIELD(temp_r3_2570, s32 *, 0x5C) = (s32) M2C_FIELD(&lit_728, s32 *, 0x5C);
    M2C_FIELD(temp_r3_2570, s32 *, 0x60) = (s32) M2C_FIELD(&lit_728, s32 *, 0x60);
    M2C_FIELD(temp_r3_2570, s32 *, 0x64) = (s32) M2C_FIELD(&lit_728, s32 *, 0x64);
    M2C_FIELD(temp_r3_2570, s32 *, 0x68) = (s32) M2C_FIELD(&lit_728, s32 *, 0x68);
    M2C_FIELD(temp_r3_2570, s32 *, 0x6C) = (s32) M2C_FIELD(&lit_728, s32 *, 0x6C);
    M2C_FIELD(temp_r3_2570, s32 *, 0x70) = (s32) M2C_FIELD(&lit_728, s32 *, 0x70);
    M2C_FIELD(temp_r3_2570, s32 *, 0x74) = (s32) M2C_FIELD(&lit_728, s32 *, 0x74);
    M2C_FIELD(temp_r3_2570, s32 *, 0x78) = (s32) M2C_FIELD(&lit_728, s32 *, 0x78);
    M2C_FIELD(temp_r3_2570, s32 *, 0x7C) = (s32) M2C_FIELD(&lit_728, s32 *, 0x7C);
    M2C_FIELD(temp_r3_2570, s32 *, 0x80) = (s32) M2C_FIELD(&lit_728, s32 *, 0x80);
    M2C_FIELD(temp_r3_2570, s32 *, 0x84) = (s32) M2C_FIELD(&lit_728, s32 *, 0x84);
    M2C_FIELD(temp_r3_2570, s32 *, 0x88) = (s32) M2C_FIELD(&lit_728, s32 *, 0x88);
    M2C_FIELD(temp_r3_2570, s32 *, 0x8C) = (s32) M2C_FIELD(&lit_728, s32 *, 0x8C);
}
#endif
