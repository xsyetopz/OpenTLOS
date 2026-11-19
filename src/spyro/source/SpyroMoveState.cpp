#include "spyro/source/SpyroMoveState.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "spyro/source/CollisionObject.h"
#include "spyro/source/InputModifier.h"
#include "spyro/source/KDCamera.h"
#include "spyro/source/KDCameraHeroData.h"
#include "spyro/source/KDCameraHeroMoveYaw.h"
#include "spyro/source/KDCameraJumpTargetOffset.h"
#include "spyro/source/KDCameraMessageStorage.h"
#include "spyro/source/KDCameraPoint.h"
#include "spyro/source/KDCameraSimpleDelta.h"
#include "spyro/source/KDCameraState.h"
#include "spyro/source/KDCollisionObject.h"
#include "spyro/source/KDInput.h"
#include "spyro/source/KDStateMachine.h"
#include "spyro/source/NodeLookAt.h"
#include "spyro/source/Spyro.h"
#include "spyro/source/SpyroAnimTables.h"
#include "spyro/source/SpyroCombatState.h"
#include "spyro/source/SpyroState.h"
#include "spyro/source/SpyroTools.h"
#include "spyro/source/SpyroUtils.h"
#include "spyro/source/TargetManager.h"
#include "spyro/source/Tools.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "common/Source/MKInput.h"
#include "spyro/source/KDMath.h"
#include <m2c_macros.h>

extern f32 SPYRO_BOUNCE_Y_SPEED;
extern f32 SPYRO_MIN_JUMP_Y_VELOCITY;
extern M2C_UNK gb;
static M2C_UNK lit_723;                                /* unable to generate initializer: unknown type */
SpyroMoveState states__14SpyroMoveState;            /* unable to generate initializer: confusing struct layout */

s32 SpyroMoveState::RunTransition() {
    return 0;
}

void SpyroMoveState::RunUpdate() {
    this->unk40.Update(this->unk10);
    RunTransition();
}

void SpyroMoveState::RunDeinit() {

}

void SpyroMoveState::RunInit() {
    this->unk4C = 750.0f;
    this->unk40.Start(this->unk10, 0.2f);
}

s32 SpyroMoveState::WalkTransition() {
    return 0;
}

void SpyroMoveState::WalkUpdate() {
    this->unk38.Update(this->unk10);
    WalkTransition();
}

void SpyroMoveState::WalkDeinit() {
    Spyro *temp_r3_105;

    temp_r3_105 = this->unk10;
    temp_r3_105->unk428 &= 0xFFFFFFF7;
}

void SpyroMoveState::WalkInit() {
    Spyro *temp_r3_126;

    this->unk4C = 190.0f;
    this->unk38.Start(this->unk10, 0.2f);
    temp_r3_126 = this->unk10;
    temp_r3_126->unk428 |= 8;
}

#if 0 // DRAFT: undefined identifier 'unk0'
u8 SpyroMoveState::SelectState(float arg0) {
    f32 temp_f0_171;
    f32 temp_f0_192;
    f32 temp_f1_156;
    f32 temp_f31_153;
    f32 var_f31_160;
    u8 var_r3_184;

    temp_f31_153 = ((InputModifier *) (this->unk10->GetInput()))->GetLeftX();
    temp_f1_156 = ((InputModifier *) (this->unk10->GetInput()))->GetLeftY();
    var_f31_160 = (temp_f1_156 * temp_f1_156) + (temp_f31_153 * temp_f31_153);
    if (var_f31_160 < 1.0f) {

    } else {
        var_f31_160 = 1.0f;
    }
    if (var_f31_160 != 0.0f) {
        temp_f0_171 = 0.75f - arg0;
        if ((var_f31_160 <= (temp_f0_171 * temp_f0_171)) && ((s32) this->unk14.unk0 != 1)) {
            this->unk14.SetState(this, 1, 0U);
            var_r3_184 = 1;
        } else {
            var_r3_184 = 0;
        }
        if (var_r3_184 == 0) {
            temp_f0_192 = 0.75f + arg0;
            if ((var_f31_160 >= (temp_f0_192 * temp_f0_192)) && ((s32) this->unk14.unk0 != 2)) {
                this->unk14.SetState(this, 2, 0U);
                return 1U;
            }
            return 0U;
        }
        /* Duplicate return node #14. Try simplifying control flow for better match */
        return var_r3_184;
    }
    var_r3_184 = 0;
    return var_r3_184;
}
#endif

s32 SpyroMoveState::Transition() {
    InputModifier *temp_r3_340;
    InputModifier *temp_r3_422;
    M2C_UNK var_r23_470;
    Spyro *temp_r3_236;
    Spyro *temp_r3_388;
    f32 var_f1_353;
    s32 temp_r3_289;
    s32 temp_r4_239;
    s32 temp_r4_397;
    s32 var_r0_253;
    s32 var_r0_303;
    s32 var_r0_411;
    s32 var_r3_435;
    u8 var_r23_282;
    u8 var_r23_333;
    u8 var_r25_281;
    u8 var_r25_335;
    u8 var_r25_389;
    u8 var_r25_475;
    u8 var_r25_501;
    u8 var_r25_527;
    u8 var_r26_280;
    u8 var_r26_390;
    u8 var_r27_279;
    u8 var_r28_278;
    u8 var_r29_277;
    u8 var_r30_276;
    u8 var_r31_275;
    u8 var_r4_342;
    u8 var_r4_424;
    u8 var_r5_392;
    void *temp_r3_287;
    void *temp_r4_237;
    void *temp_r4_395;
    void *var_r3_298;
    void *var_r4_248;
    void *var_r4_406;

    if (this->unk10->SlipTest() == 0) {
        temp_r3_236 = this->unk10;
        temp_r4_237 = temp_r3_236->unk27C;
        temp_r4_239 = M2C_FIELD(temp_r4_237, s32 *, 0x16C);
        if (((u32) (-temp_r4_239 & ~temp_r4_239) >> 0x1FU) != 0) {
            if (temp_r4_239 != 0) {
                var_r4_248 = ((u8 *) temp_r4_237) + 8 + ((temp_r4_239 - 1) * 0x58);
            } else {
                var_r4_248 = NULL;
            }
            var_r0_253 = M2C_FIELD(var_r4_248, s32 *, 0x44);
        } else {
            var_r0_253 = 0;
        }
        if (var_r0_253 & 2) {
            goto block_8;
        }
        var_r31_275 = 1;
        var_r30_276 = 1;
        var_r29_277 = 1;
        var_r28_278 = 1;
        var_r27_279 = 1;
        var_r26_280 = 1;
        var_r25_281 = 1;
        var_r23_282 = 1;
        if (temp_r3_236->SlipTest() == 0) {
            temp_r3_287 = this->unk10->unk27C;
            temp_r3_289 = M2C_FIELD(temp_r3_287, s32 *, 0x16C);
            if (((u32) (-temp_r3_289 & ~temp_r3_289) >> 0x1FU) != 0) {
                if (temp_r3_289 != 0) {
                    var_r3_298 = ((u8 *) temp_r3_287) + 8 + ((temp_r3_289 - 1) * 0x58);
                } else {
                    var_r3_298 = NULL;
                }
                var_r0_303 = M2C_FIELD(var_r3_298, s32 *, 0x44);
            } else {
                var_r0_303 = 0;
            }
            if (!(var_r0_303 & 2)) {
                var_r23_282 = 0;
            }
        }
        if (this->unk10->TryChangeState(var_r23_282, 8U, NULL, 0U) == 0) {
            this->unk10->LandToAirTransition(this->unk50 == 0, 0U, 0U);
            if ((u8) M2C_ERROR(/* Read from unset register $r3 */) == 0) {
                var_r25_281 = 0;
            }
        }
        if (var_r25_281 == 0) {
            var_r23_333 = 0;
            var_r25_335 = 0;
            if (this->unk10->CanStrafe() != 0) {
                temp_r3_340 = this->unk10->GetInput();
                var_r4_342 = 0;
                if (((u8) temp_r3_340->unk5 != 0) || ((u8) temp_r3_340->unk4 != 0)) {
                    var_r4_342 = 1;
                }
                if (var_r4_342 != 0) {
                    var_f1_353 = 0.0f;
                } else {
                    var_f1_353 = MKInput_GetState(0xA, (MKInputDevices) temp_r3_340->unk0, NULL, NULL);
                }
                if (var_f1_353 != 0.0f) {
                    var_r25_335 = 1;
                }
            }
            if (var_r25_335 != 0) {
                this->unk10->IsAgainstMatID(2);
                if ((u32) M2C_ERROR(/* Read from unset register $r3 */) == 0U) {
                    var_r23_333 = 1;
                }
            }
            if (this->unk10->TryChangeState(var_r23_333, 2U, NULL, 0U) == 0) {
                var_r26_280 = 0;
            }
        }
        if (var_r26_280 == 0) {
            temp_r3_388 = this->unk10;
            var_r25_389 = 0;
            var_r26_390 = 0;
            var_r5_392 = 0;
            if ((u8) temp_r3_388->unk3D5 == 0) {
                temp_r4_395 = temp_r3_388->unk27C;
                temp_r4_397 = M2C_FIELD(temp_r4_395, s32 *, 0x16C);
                if (((u32) (-temp_r4_397 & ~temp_r4_397) >> 0x1FU) != 0) {
                    if (temp_r4_397 != 0) {
                        var_r4_406 = ((u8 *) temp_r4_395) + 8 + ((temp_r4_397 - 1) * 0x58);
                    } else {
                        var_r4_406 = NULL;
                    }
                    var_r0_411 = M2C_FIELD(var_r4_406, s32 *, 0x44);
                } else {
                    var_r0_411 = 0;
                }
                if (!(var_r0_411 & 2)) {
                    var_r5_392 = 1;
                }
            }
            if (var_r5_392 != 0) {
                temp_r3_422 = temp_r3_388->GetInput();
                var_r4_424 = 0;
                if (((u8) temp_r3_422->unk5 != 0) || ((u8) temp_r3_422->unk4 != 0)) {
                    var_r4_424 = 1;
                }
                if (var_r4_424 != 0) {
                    var_r3_435 = 0;
                } else {
                    var_r3_435 = MKInput_Pressed(0xB, (MKInputDevices) temp_r3_422->unk0);
                }
                if ((u8) var_r3_435 != 0) {
                    var_r26_390 = 1;
                }
            }
            if ((var_r26_390 != 0) && (this->unk10->unk3C4 == 0.0f)) {
                var_r25_389 = 1;
            }
            if (this->unk10->TryChangeState(var_r25_389, 1U, NULL, 0U) == 0) {
                var_r27_279 = 0;
            }
        }
        if (var_r27_279 == 0) {
            var_r23_470 = 0x16C;
            if (this->unk10->GetMeleeButtonState() == 2) {
                var_r23_470 = 0x17E;
            }
            var_r25_475 = 0;
            if (((u8) M2C_FIELD(&gb, u8 *, 5) != 0) && (this->unk10->GetMeleeButtonState() != 0)) {
                var_r25_475 = 1;
            }
            if (this->unk10->TryChangeState(var_r25_475, 0xBU, (SpyroStateMsg) var_r23_470, 0U) == 0) {
                var_r28_278 = 0;
            }
        }
        if (var_r28_278 == 0) {
            var_r25_501 = 0;
            if ((M2C_FIELD(&gb, f32 *, 0x30C) >= this->unk54) && (this->unk10->LavaTransition() != 0)) {
                var_r25_501 = 1;
            }
            if (var_r25_501 == 0) {
                var_r29_277 = 0;
            }
        }
        if ((var_r29_277 == 0) && (this->unk10->SpikyTransition() == 0)) {
            var_r30_276 = 0;
        }
        if (var_r30_276 == 0) {
            var_r25_527 = 0;
            if ((((KDInput *) (this->unk10->GetInput()))->GetLeftMag() == 0.0f) || ((u8) this->unk10->unk1C4 == 0)) {
                var_r25_527 = 1;
            }
            if (this->unk10->TryChangeState(var_r25_527, 4U, NULL, 0U) == 0) {
                var_r31_275 = 0;
            }
        }
        return var_r31_275;
    }
block_8:
    ((KDInput *) (this->unk10->GetInput()))->GetLeftMag();
    return this->unk10->TryChangeState(((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1DU) & 1, 8U, NULL, 0U);
}

#if 0 // DRAFT: ')' expected
void SpyroMoveState::Update() {
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp38;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    ContextInfo *temp_r3_706;
    Spyro *temp_r5_581;
    f32 temp_f2_627;
    f32 temp_f2_683;
    f32 temp_f31_650;
    f32 var_f0_657;
    f64 temp_f0_577;
    f64 temp_f0_630;
    f64 temp_f0_686;
    f64 temp_f1_576;
    s32 temp_r3_588;
    s32 temp_r3_724;
    s32 var_r0_602;
    s32 var_r0_738;
    u8 var_r4_574;
    void *temp_r3_575;
    void *temp_r3_586;
    void *temp_r3_722;
    void *var_r3_597;
    void *var_r3_733;

    SelectState(0.0025f);
    var_r4_574 = 0;
    temp_r3_575 = this->unk10->unk8;
    temp_f1_576 = M2C_FIELD(temp_r3_575, f64 *, 0x30);
    temp_f0_577 = M2C_FIELD(temp_r3_575, f64 *, 0x38);
    sp48 = temp_f1_576;
    this->unk58 = temp_f1_576;
    this->unk60 = temp_f0_577;
    temp_r5_581 = this->unk10;
    sp50 = temp_f0_577;
    if (((u32) temp_r5_581->unk428 >> 5U) & 1) {
        temp_r3_586 = temp_r5_581->unk27C;
        temp_r3_588 = M2C_FIELD(temp_r3_586, s32 *, 0x16C);
        if (((u32) (-temp_r3_588 & ~temp_r3_588) >> 0x1FU) != 0) {
            if (temp_r3_588 != 0) {
                var_r3_597 = ((u8 *) temp_r3_586) + 8 + ((temp_r3_588 - 1) * 0x58);
            } else {
                var_r3_597 = NULL;
            }
            var_r0_602 = M2C_FIELD(var_r3_597, s32 *, 0x44);
        } else {
            var_r0_602 = 0;
        }
        if (var_r0_602 & 0x40) {
            var_r4_574 = 1;
        }
    }
    if (var_r4_574 != 0) {
        this->unk4C *= M2C_FIELD(checked_cast<SpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) temp_r5_581->unk0), f32 *, 0xD8);
    }
    this->unk10->unk3D2 = 0;
    ((Spyro *) &sp38)->CalcYawTurnDir(30.0f);
    temp_f2_627 = this->unk4C;
    temp_f0_630 = sp38 * (f64) temp_f2_627;
    sp18 = temp_f0_630;
    sp68 = temp_f0_630;
    sp20 = sp40 * temp_f2_627;
    sp70 = (f64) sp20;
    this->unk10->SetDesiredVelocityHoriz(*((MKVector3 *) &sp68), 3800.0f);
    if (this->unk14.GetState() == 2) {
        temp_f31_650 = KDMath_GetYaw(*((MKVector3 *) &sp68));
        KDMath_GetYaw((Matrix *) this->unk10->unk8);
        var_f0_657 = 3.0f * KDMath_GetSmallestAngle(M2C_ERROR(/* Read from unset register $f1 */), temp_f31_650);
        if (var_f0_657 < 0.15f) {

        } else {
            var_f0_657 = 0.15f;
        }
        if (var_f0_657 > -0.15f) {

        } else {
            var_f0_657 = -0.15f;
        }
        this->unk10->unk3C0 = var_f0_657;
    } else {
        this->unk10->unk3C0 = 0.0f;
    }
    ((Spyro *) &sp28)->CalcYawTurnDir(30.0f);
    temp_f2_683 = this->unk4C;
    temp_f0_686 = sp28 * (f64) temp_f2_683;
    sp8 = temp_f0_686;
    sp58 = temp_f0_686;
    sp10 = sp30 * temp_f2_683;
    sp60 = (f64) sp10;
    this->unk10->unk3A8.YawTowards(*((MKVector3 *) &sp58), 30.0f);
    this->unk14.Update(this, 0);
    temp_r3_706 = this->unk10->unk27C + 8;
    if ((s32) temp_r3_706->unk164 > 0) {
        if (temp_r3_706->HitID(2U) != 0) {
            this->unk50 = 1;
        } else {
            this->unk50 = 0;
        }
    }
    temp_r3_722 = this->unk10->unk27C;
    temp_r3_724 = M2C_FIELD(temp_r3_722, s32 *, 0x16C);
    if (((u32) (-temp_r3_724 & ~temp_r3_724) >> 0x1FU) != 0) {
        if (temp_r3_724 != 0) {
            var_r3_733 = ((u8 *) temp_r3_722) + 8 + ((temp_r3_724 - 1) * 0x58);
        } else {
            var_r3_733 = NULL;
        }
        var_r0_738 = M2C_FIELD(var_r3_733, s32 *, 0x44);
    } else {
        var_r0_738 = 0;
    }
    if (var_r0_738 & 0x100) {
        if ((u8) this->unk51 == 0) {
            this->unk54 = M2C_FIELD(&gb, f32 *, 0x30C) + 0.1667f;
        }
        this->unk51 = 1;
        return;
    }
    this->unk54 = 0.0f;
    this->unk51 = 0;
}
#endif

void SpyroMoveState::Exit() {
    this->unk14.Exit(this);
}

#if 0 // DRAFT: undefined identifier 'sp20'
void SpyroMoveState::Enter(SpyroStateMessages &arg0) {
    s32 sp30;
    s32 sp2C;
    s32 sp28;
    f64 sp18;
    f64 sp10;
    f64 sp8;
    Spyro *temp_r3_835;
    f64 temp_f0_830;
    f64 temp_f1_829;
    void *temp_r3_828;
    void *temp_r3_856;

    this->unk48 = 0;
    this->unk14.Init((KDStateMachine<SpyroMoveState>::State *) &SpyroMoveState::states, NULL);
    SelectState(0.0f);
    this->unk50 = arg0.IsMessageOnList(0x176);
    ((Spyro *) &sp18)->GetJoyDir();
    this->unk28 = sp18;
    this->unk30 = sp20;
    this->unk54 = 0.0f;
    this->unk51 = 0;
    temp_r3_828 = this->unk10->unk8;
    temp_f1_829 = M2C_FIELD(temp_r3_828, f64 *, 0x30);
    temp_f0_830 = M2C_FIELD(temp_r3_828, f64 *, 0x38);
    sp8 = temp_f1_829;
    this->unk58 = temp_f1_829;
    this->unk60 = temp_f0_830;
    this->unk48 = 1;
    temp_r3_835 = this->unk10;
    sp10 = temp_f0_830;
    temp_r3_835->unk428 = temp_r3_835->unk428 | 0x100000 | 0x8000;
    this->unk10->unk460.SetTailSweepEnabled(1U);
    this->unk10->unk460.SetHornDiveEnabled(1U);
    sp2C = 0;
    sp28 = 0x17;
    sp30 = 3;
    temp_r3_856 = this->unk10->unkB70;
    M2C_FIELD(M2C_FIELD(temp_r3_856, void **, 0x44), M2C_UNK (**)(void *, s32 *), 0x2C)(temp_r3_856, &sp28);
}
#endif

void SpyroMoveState::Deinit() {
    this->unk14.Exit(this);
}

void SpyroMoveState::Init(Spyro *arg0) {
    this->unk10 = arg0;
    this->unk48 = 0;
    this->unk4C = 0.0f;
    this->unk50 = 0;
    this->unk51 = 0;
    M2C_FIELD(this, f32 *, 0x28) = 0.0f;
    M2C_FIELD(this, f32 *, 0x2C) = 0.0f;
    M2C_FIELD(this, f32 *, 0x30) = 0.0f;
    this->unk54 = 0.0f;
    this->unk38.unk0 = 5;
    this->unk38.unk4 = 6;
    this->unk40.unk0 = 7;
    this->unk40.unk4 = 8;
}

#if 0 // DRAFT: undefined identifier '__ptmf_null'
void SpyroMoveState_cpp::__sinit() {
    s32 sp10;
    s32 spC;
    s32 sp8;
    f64 temp_f0_1158;
    f64 temp_f1_1128;
    f64 temp_f1_1152;
    f64 temp_f3_1112;
    f64 temp_f3_1155;
    f64 temp_f4_1127;
    f64 temp_f4_1149;
    f64 temp_f8_1114;
    void *temp_r24_1122;

    temp_f3_1112 = __frsqrte(2014000.0);
    temp_f8_1114 = __frsqrte(380000.0);
    temp_r24_1122 = &lit_723 + 0x48;
    temp_f4_1127 = 0.5 * temp_f3_1112 * -((2014000.0 * (temp_f3_1112 * temp_f3_1112)) - 3.0);
    temp_f1_1128 = 0.5 * temp_f8_1114 * -((380000.0 * (temp_f8_1114 * temp_f8_1114)) - 3.0);
    temp_f4_1149 = 0.5 * temp_f4_1127 * -((2014000.0 * (temp_f4_1127 * temp_f4_1127)) - 3.0);
    temp_f1_1152 = 0.5 * temp_f1_1128 * -((380000.0 * (temp_f1_1128 * temp_f1_1128)) - 3.0);
    temp_f3_1155 = temp_f4_1149 * temp_f4_1149;
    temp_f0_1158 = temp_f1_1152 * temp_f1_1152;
    M2C_FIELD(&lit_723, s32 *, 0x48) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 0);
    M2C_FIELD(&lit_723, s32 *, 0x4C) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 4);
    M2C_FIELD(&lit_723, s32 *, 0x50) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 8);
    M2C_FIELD(temp_r24_1122, s32 *, 0xC) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 0);
    M2C_FIELD(temp_r24_1122, s32 *, 0x10) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 4);
    M2C_FIELD(temp_r24_1122, s32 *, 0x14) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 8);
    M2C_FIELD(temp_r24_1122, s32 *, 0x18) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 0);
    M2C_FIELD(temp_r24_1122, s32 *, 0x1C) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 4);
    M2C_FIELD(temp_r24_1122, s32 *, 0x20) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 8);
    M2C_FIELD(temp_r24_1122, s32 *, 0x24) = (s32) M2C_FIELD(&lit_723, s32 *, 0);
    M2C_FIELD(temp_r24_1122, s32 *, 0x28) = (s32) M2C_FIELD(&lit_723, s32 *, 4);
    M2C_FIELD(temp_r24_1122, s32 *, 0x2C) = (s32) M2C_FIELD(&lit_723, s32 *, 8);
    M2C_FIELD(temp_r24_1122, s32 *, 0x30) = (s32) M2C_FIELD(&lit_723, s32 *, 0xC);
    M2C_FIELD(temp_r24_1122, s32 *, 0x34) = (s32) M2C_FIELD(&lit_723, s32 *, 0x10);
    M2C_FIELD(temp_r24_1122, s32 *, 0x38) = (s32) M2C_FIELD(&lit_723, s32 *, 0x14);
    M2C_FIELD(temp_r24_1122, s32 *, 0x3C) = (s32) M2C_FIELD(&lit_723, s32 *, 0x18);
    M2C_FIELD(temp_r24_1122, s32 *, 0x40) = (s32) M2C_FIELD(&lit_723, s32 *, 0x1C);
    M2C_FIELD(temp_r24_1122, s32 *, 0x44) = (s32) M2C_FIELD(&lit_723, s32 *, 0x20);
    M2C_FIELD(temp_r24_1122, s32 *, 0x48) = (s32) M2C_FIELD(&lit_723, s32 *, 0x24);
    M2C_FIELD(temp_r24_1122, s32 *, 0x4C) = (s32) M2C_FIELD(&lit_723, s32 *, 0x28);
    M2C_FIELD(temp_r24_1122, s32 *, 0x50) = (s32) M2C_FIELD(&lit_723, s32 *, 0x2C);
    M2C_FIELD(temp_r24_1122, s32 *, 0x54) = (s32) M2C_FIELD(&lit_723, s32 *, 0x30);
    M2C_FIELD(temp_r24_1122, s32 *, 0x58) = (s32) M2C_FIELD(&lit_723, s32 *, 0x34);
    M2C_FIELD(temp_r24_1122, s32 *, 0x5C) = (s32) M2C_FIELD(&lit_723, s32 *, 0x38);
    M2C_FIELD(temp_r24_1122, s32 *, 0x60) = (s32) M2C_FIELD(&lit_723, s32 *, 0x3C);
    M2C_FIELD(temp_r24_1122, s32 *, 0x64) = (s32) M2C_FIELD(&lit_723, s32 *, 0x40);
    M2C_FIELD(temp_r24_1122, s32 *, 0x68) = (s32) M2C_FIELD(&lit_723, s32 *, 0x44);
    sp8 = M2C_FIELD(&__ptmf_null, s32 *, 0);
    spC = M2C_FIELD(&__ptmf_null, s32 *, 4);
    sp10 = M2C_FIELD(&__ptmf_null, s32 *, 8);
    SPYRO_BOUNCE_Y_SPEED = (f32) (2014000.0 * (0.5 * temp_f4_1149 * -((2014000.0 * temp_f3_1155) - 3.0)));
    SPYRO_MIN_JUMP_Y_VELOCITY = (f32) (380000.0 * (0.5 * temp_f1_1152 * -((380000.0 * temp_f0_1158) - 3.0)));
}
#endif
