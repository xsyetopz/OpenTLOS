#include "spyro/source/GameCameraEmuStateMachine.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "spyro/source/GameCamera2.h"
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
#include "spyro/source/TargetManager.h"
#include <m2c_macros.h>

#if 0 // DRAFT: illegal operand
void GameCameraEmuStateMachine::SetDisabledStates() {
    s32 var_r30_17;
    s32 var_r31_15;

    var_r31_15 = 0;
    var_r30_17 = 0;
    this->unk4 = 0;
loop_4:
    if (var_r30_17 < (s32) this->unkC) {
        if (IsStateActive(this->unk8 + var_r31_15, 0U) != 0) {
            this->unk4 |= *(this->unk8 + (var_r31_15 + 0x34));
        }
        var_r30_17 += 1;
        var_r31_15 += 0x38;
        goto loop_4;
    }
}
#endif

u8 GameCameraEmuStateMachine::IsStateActive(GameCameraEmuStateDescriptor *arg0, bool arg1) {
    s32 temp_r7_51;
    u8 var_r0_64;
    u8 var_r4_52;

    temp_r7_51 = arg0->unk4;
    var_r4_52 = 0;
    if ((u8) ((temp_r7_51 & this->unk0) != 0) != 0) {
        if (arg1 != 0) {
            var_r0_64 = (temp_r7_51 & this->unk4) != 0;
        } else {
            var_r0_64 = 0;
        }
        if (var_r0_64 == 0) {
            var_r4_52 = 1;
        }
    }
    return var_r4_52;
}

#if 0 // DRAFT: undefined identifier '__ptmf_test'
void GameCameraEmuStateMachine::DeactivateState(GameCameraEmuStateDescriptor *arg0, GameCamera2 *arg1) {
    if (IsStateActive(arg0, 0U) != 0) {
        if ((IsStateActive(arg0, 1U) != 0) && (__ptmf_test(arg0 + 0x1C) != 0)) {
            __ptmf_scall(arg1);
        }
        this->unk0 &= ~arg0->unk4;
        SetDisabledStates();
    }
}
#endif

s32 GameCameraEmuStateMachine::IsEmuStateMessage(int arg0) {
    s32 temp_r0_123;
    s32 var_ctr_125;
    s32 var_r5_124;
    void *temp_r6_130;

    temp_r0_123 = this->unkC;
    var_r5_124 = 0;
    var_ctr_125 = temp_r0_123;
    if (temp_r0_123 > 0) {
loop_1:
        temp_r6_130 = this->unk8 + var_r5_124;
        if ((arg0 == (s32) M2C_FIELD(temp_r6_130, s32 *, 8)) || (arg0 == (s32) M2C_FIELD(temp_r6_130, s32 *, 0xC))) {
            return 1;
        }
        var_r5_124 += 0x38;
        var_ctr_125 -= 1;
        if (var_ctr_125 == 0) {
            /* Duplicate return node #5. Try simplifying control flow for better match */
            return 0;
        }
        goto loop_1;
    }
    return 0;
}

#if 0 // DRAFT: undefined identifier '__ptmf_test'
s32 GameCameraEmuStateMachine::HandleGameCameraMessage(GameCamera2 *arg0, int arg1) {
    GameCameraEmuStateDescriptor *temp_r31_164;
    GameCameraEmuStateDescriptor *temp_r4_207;
    s32 temp_r4_157;
    s32 var_ctr_159;
    s32 var_ctr_202;
    s32 var_r3_158;
    s32 var_r3_201;

    temp_r4_157 = this->unkC;
    var_r3_158 = 0;
    var_ctr_159 = temp_r4_157;
    if (temp_r4_157 > 0) {
loop_1:
        temp_r31_164 = this->unk8 + var_r3_158;
        if (arg1 == (s32) temp_r31_164->unk8) {
            if (IsStateActive(temp_r31_164, 0U) == 0) {
                this->unk0 |= temp_r31_164->unk4;
                SetDisabledStates();
                if ((IsStateActive(temp_r31_164, 1U) != 0) && (__ptmf_test(temp_r31_164 + 0x10) != 0)) {
                    __ptmf_scall(arg0);
                }
            }
            return 1;
        }
        var_r3_158 += 0x38;
        var_ctr_159 -= 1;
        if (var_ctr_159 == 0) {
            goto block_8;
        }
        goto loop_1;
    }
block_8:
    var_r3_201 = 0;
    var_ctr_202 = temp_r4_157;
    if (temp_r4_157 > 0) {
loop_9:
        temp_r4_207 = this->unk8 + var_r3_201;
        if (arg1 == (s32) temp_r4_207->unkC) {
            DeactivateState(temp_r4_207, arg0);
            return 1;
        }
        var_r3_201 += 0x38;
        var_ctr_202 -= 1;
        if (var_ctr_202 == 0) {
            goto block_12;
        }
        goto loop_9;
    }
block_12:
    return 0;
}
#endif

#if 0 // DRAFT: undefined identifier '__ptmf_test'
void GameCameraEmuStateMachine::UpdateStates(GameCamera2 *arg0) {
    s32 var_r30_238;
    s32 var_r31_239;

    var_r30_238 = 0;
    var_r31_239 = 0;
loop_5:
    if (var_r30_238 < (s32) this->unkC) {
        if ((IsStateActive(this->unk8 + var_r31_239, 1U) != 0) && (__ptmf_test(this->unk8 + (var_r31_239 + 0x28)) != 0)) {
            __ptmf_scall(arg0);
        }
        var_r30_238 += 1;
        var_r31_239 += 0x38;
        goto loop_5;
    }
}
#endif

void GameCameraEmuStateMachine::ClearData(GameCamera2 *arg0) {
    s32 var_r30_284;
    s32 var_r31_285;

    var_r30_284 = 0;
    var_r31_285 = 0;
loop_4:
    if (var_r30_284 < (s32) this->unkC) {
        if (IsStateActive(this->unk8 + var_r31_285, 0U) != 0) {
            DeactivateState(this->unk8 + var_r31_285, arg0);
        }
        var_r30_284 += 1;
        var_r31_285 += 0x38;
        goto loop_4;
    }
}

#if 0 // DRAFT: illegal explicit conversion from 'GameCameraEmuStateDescriptor' to 'unsigned long'
void GameCameraEmuStateMachine::Init(GameCamera2 *arg0, GameCameraEmuStateDescriptor *arg1) {
    s32 temp_r5_324;

    this->unk8 = arg1;
    this->unkC = 0;
    do {
        temp_r5_324 = this->unkC;
        if ((u32) *(this->unk8 + (temp_r5_324 * 0x38)) != 0U) {
            this->unkC = temp_r5_324 + 1;
        }
    } while ((u32) *(this->unk8 + (this->unkC * 0x38)) != 0U);
    this->unk0 = 0;
    this->unk4 = 0;
    ClearData(arg0);
}
#endif
