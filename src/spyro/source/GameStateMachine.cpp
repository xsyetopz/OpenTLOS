#include "spyro/source/GameStateMachine.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKVector4.h"
#include "spyro/source/TimeDeltaModifier.h"
#include "common/gc/MKView_GC.h"
#include <m2c_macros.h>

extern M2C_UNK gDisplay;
extern M2C_UNK gb;

#if 0 // DRAFT: illegal use of non-static member
void GameStateHeap::HeapMarkPopAll() {
    if (MKHeap::Current() != NULL) {
loop_3:
        if ((s32) this->unk0 > -1) {
            HeapMarkPop();
            goto loop_3;
        }
    }
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void GameStateHeap::HeapMarkPop() {
    MKHeap *temp_r3_43;
    s32 temp_r4_53;

    temp_r3_43 = MKHeap::Current();
    if (temp_r3_43 != NULL) {
        ((MKHeap *) (temp_r3_43->Current()))->Release(M2C_FIELD(&this[this->unk0], s32 *, 4));
    }
    temp_r4_53 = this->unk0;
    this->unk0 = temp_r4_53 - 1;
    M2C_FIELD(&this[temp_r4_53], s32 *, 4) = 0;
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void GameStateHeap::HeapMarkPush() {
    MKHeap *temp_r3_75;
    s32 temp_r3_79;
    s32 temp_r4_81;

    temp_r3_75 = MKHeap::Current();
    if (temp_r3_75 != NULL) {
        temp_r3_79 = ((MKHeap *) (temp_r3_75->Current()))->Mark();
        temp_r4_81 = this->unk0 + 1;
        this->unk0 = temp_r4_81;
        M2C_FIELD(&this[temp_r4_81], s32 *, 4) = temp_r3_79;
    }
}
#endif

#if 0 // DRAFT: illegal operand
void GameStateHeap::Init() {
    s32 temp_r0_103;
    s32 var_ctr_101;
    s32 var_r4_100;

    this->unk0 = -1;
    var_r4_100 = 0;
    var_ctr_101 = 8;
    do {
        temp_r0_103 = var_r4_100 + 4;
        var_r4_100 += 4;
        *(this + temp_r0_103) = -1;
        var_ctr_101 -= 1;
    } while (var_ctr_101 != 0);
}
#endif

u8 GameStateMachine::GetFadeColor() {
    GameStateMachineInit *temp_r4_118;
    s32 temp_r0_114;
    s32 var_r5_116;

    temp_r0_114 = this->unk20;
    var_r5_116 = temp_r0_114;
    if (temp_r0_114 == 0) {
        temp_r4_118 = this->unk34;
        if (temp_r4_118 != NULL) {
            var_r5_116 = temp_r4_118->unkC;
        }
    }
    return var_r5_116 | ((s32) (128.0f * this->unk24) << 0x18);
}

s32 GameStateMachine::StateIsValid() {
    return this->unk1C != NULL;
}

void *GameStateMachine::GetCurrState() {
    return this->unk1C;
}

void *GameStateMachine::GetLastState() {
    return this->unk18 + (this->unk0 << 5);
}

void GameStateMachine::Draw() {
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    GameStateMachineInit *temp_r4_203;
    GameStateMachineInit *temp_r4_256;
    GameStateMachineInit *temp_r4_309;
    M2C_UNK (*temp_r12_176)();
    M2C_UNK (*temp_r12_206)(f32);
    M2C_UNK (*temp_r12_259)(f32);
    M2C_UNK (*temp_r12_312)(f32);
    s32 temp_r0_187;
    u32 temp_r10_192;
    u8 temp_r3_186;
    u8 temp_r5_188;
    u8 temp_r6_189;
    u8 temp_r9_190;
    void *temp_r3_170;

    temp_r3_170 = this->unk1C;
    if ((temp_r3_170 != NULL) && ((s32) this->unk30 != 2)) {
        temp_r12_176 = M2C_FIELD(temp_r3_170, M2C_UNK (**)(), 0x18);
        if (temp_r12_176 != NULL) {
            temp_r12_176();
        }
    }
    if ((s32) this->unk30 != 0) {
        temp_r3_186 = GetFadeColor();
        temp_r0_187 = this->unk30;
        temp_r5_188 = temp_r3_186;
        temp_r6_189 = (u8) (temp_r3_186 >> 8U);
        temp_r9_190 = (u8) (temp_r3_186 >> 0x10U);
        temp_r10_192 = temp_r3_186 >> 0x18U;
        switch (temp_r0_187) {                      /* irregular */
        case 1:
            temp_r4_203 = this->unk34;
            if (temp_r4_203 != NULL) {
                temp_r12_206 = M2C_FIELD(temp_r4_203, M2C_UNK (**)(f32), 0x18);
                if (temp_r12_206 != NULL) {
                    temp_r12_206(this->unk24);
                    return;
                }
            }
            sp28 = (f32) temp_r5_188 / 255.0f;
            sp2C = (f32) temp_r6_189 / 255.0f;
            sp58 = (f64) sp28;
            sp30 = (f32) temp_r9_190 / 255.0f;
            sp34 = (f32) temp_r10_192 / 255.0f;
            sp60 = (f64) sp30;
            MKView_Clear(3, *((MKVector4 *) &sp58), 0.0f, 0U);
            return;
        case 2:
            temp_r4_256 = this->unk34;
            if (temp_r4_256 != NULL) {
                temp_r12_259 = M2C_FIELD(temp_r4_256, M2C_UNK (**)(f32), 0x14);
                if (temp_r12_259 != NULL) {
                    temp_r12_259(this->unk24);
                    return;
                }
            }
            sp18 = (f32) temp_r5_188 / 255.0f;
            sp1C = (f32) temp_r6_189 / 255.0f;
            sp48 = (f64) sp18;
            sp20 = (f32) temp_r9_190 / 255.0f;
            sp24 = (f32) temp_r10_192 / 255.0f;
            sp50 = (f64) sp20;
            MKView_Clear(3, *((MKVector4 *) &sp48), 0.0f, 0U);
            return;
        case 3:
            temp_r4_309 = this->unk34;
            if (temp_r4_309 != NULL) {
                temp_r12_312 = M2C_FIELD(temp_r4_309, M2C_UNK (**)(f32), 0x10);
                if (temp_r12_312 != NULL) {
                    temp_r12_312(this->unk24);
                    return;
                }
            }
            sp8 = (f32) temp_r5_188 / 255.0f;
            spC = (f32) temp_r6_189 / 255.0f;
            sp38 = (f64) sp8;
            sp10 = (f32) temp_r9_190 / 255.0f;
            sp14 = (f32) temp_r10_192 / 255.0f;
            sp40 = (f64) sp10;
            MKView_Clear(3, *((MKVector4 *) &sp38), 0.0f, 0U);
            break;
        }
    }
}

void GameStateMachine::Update() {
    GameStateMachineInit *temp_r3_428;
    GameStateMachineInit *temp_r3_486;
    M2C_UNK (*temp_r12_518)();
    f32 var_f3_431;
    f32 var_f3_489;
    s32 temp_r0_377;
    s32 temp_r4_393;
    s32 var_r30_376;
    void *temp_r3_515;

    var_r30_376 = 1;
    temp_r0_377 = this->unk30;
    switch (temp_r0_377) {                          /* irregular */
    case 0:
        if ((s32) this->unk8 != -1) {
            temp_r4_393 = this->unk28;
            if (temp_r4_393 & 6) {
                this->unk24 = 0.0f;
                this->unk30 = 1;
                var_r30_376 = this->unk28 & 4;
            } else if (temp_r4_393 & 1) {
                SwitchOut();
                this->unk2C = 0;
                var_r30_376 = 0;
                this->unk30 = 2;
                this->unk24 = 1.0f;
            } else {
                SwitchOut();
                SwitchIn();
                if (this->unk28 & 0x18) {
                    this->unk30 = 3;
                    var_r30_376 = this->unk28 & 0x10;
                }
            }
        }
        break;
    case 1:
        temp_r3_428 = this->unk34;
        if (temp_r3_428 != NULL) {
            var_f3_431 = temp_r3_428->unk8;
        } else {
            var_f3_431 = 0.5f;
        }
        this->unk24 += M2C_FIELD(&gDisplay, f32 *, 0xC) / var_f3_431;
        M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
        if (this->unk24 == 1.0f) {
            SwitchOut();
            this->unk2C = 0;
            var_r30_376 = 0;
            this->unk30 = 2;
            this->unk24 = 1.0f;
        } else {
            var_r30_376 = this->unk28 & 4;
        }
        break;
    case 2:
        this->unk2C += 1;
        if ((s32) this->unk2C > 3) {
            SwitchIn();
            if (this->unk28 & 0x18) {
                this->unk30 = 3;
            } else {
                this->unk30 = 0;
            }
            var_r30_376 = 1;
        } else {
            var_r30_376 = 0;
        }
        break;
    case 3:
        temp_r3_486 = this->unk34;
        if (temp_r3_486 != NULL) {
            var_f3_489 = temp_r3_486->unk4;
        } else {
            var_f3_489 = 0.5f;
        }
        this->unk24 -= M2C_FIELD(&gDisplay, f32 *, 0xC) / var_f3_489;
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if (this->unk24 == 0.0f) {
            this->unk30 = 0;
            this->unk24 = 0.0f;
        }
        var_r30_376 = this->unk28 & 0x10;
        break;
    }
    if (var_r30_376 != 0) {
        temp_r3_515 = this->unk1C;
        if (temp_r3_515 != NULL) {
            temp_r12_518 = M2C_FIELD(temp_r3_515, M2C_UNK (**)(), 0x14);
            if (temp_r12_518 != NULL) {
                temp_r12_518();
            }
        }
    }
    this->unk10 += 1;
    this->unk14 += M2C_FIELD(&gDisplay, f32 *, 0xC);
}

void GameStateMachine::SwitchIn() {
    M2C_UNK (*temp_r12_591)();
    s32 temp_r0_562;

    this->unk4 = this->unk8;
    this->unk8 = -1;
    this->unk10 = 0;
    this->unk14 = 0.0f;
    if ((s32) this->unk4 == -1) {
        this->unk1C = NULL;
        return;
    }
    temp_r0_562 = this->unk0;
    if ((temp_r0_562 != -1) && (M2C_FIELD((this->unk18 + (temp_r0_562 << 5)), s32 *, 8) & 2)) {
        this->unk38.HeapMarkPopAll();
    }
    this->unk1C = this->unk18 + (this->unk4 << 5);
    if (M2C_FIELD(this->unk1C, s32 *, 8) & 1) {
        this->unk38.HeapMarkPush();
    }
    ((TimeDeltaModifier *) (&gb + 0x2CC))->Reset();
    temp_r12_591 = M2C_FIELD(this->unk1C, M2C_UNK (**)(), 0x10);
    if (temp_r12_591 != NULL) {
        temp_r12_591();
    }
}

void GameStateMachine::SwitchOut() {
    M2C_UNK (*temp_r12_615)();
    void *temp_r3_612;

    temp_r3_612 = this->unk1C;
    if (temp_r3_612 != NULL) {
        temp_r12_615 = M2C_FIELD(temp_r3_612, M2C_UNK (**)(), 0x1C);
        if (temp_r12_615 != NULL) {
            temp_r12_615();
        }
    }
    this->unk0 = this->unk4;
    this->unk1C = NULL;
    this->unk4 = -1;
}

void GameStateMachine::SwitchState(int arg0, int arg1, unsigned int arg2) {
    s32 var_r5_0;
    void *temp_r6_641;

    var_r5_0 = arg1;
    if (arg2 != 0) {
        this->unk20 = (s32) arg2;
    }
    temp_r6_641 = this->unk1C;
    if ((temp_r6_641 != NULL) && (M2C_FIELD(temp_r6_641, s32 *, 8) & 2)) {
        var_r5_0 |= 1;
    }
    this->unk28 = var_r5_0;
    this->unk8 = arg0;
}

void GameStateMachine::Deinit() {
    M2C_UNK (*temp_r12_663)();
    void *temp_r3_660;

    temp_r3_660 = this->unk1C;
    if (temp_r3_660 != NULL) {
        temp_r12_663 = M2C_FIELD(temp_r3_660, M2C_UNK (**)(), 0x1C);
        if (temp_r12_663 != NULL) {
            temp_r12_663();
        }
    }
}

void GameStateMachine::Init(GameStateMachineState *arg0, GameStateMachineInit *arg1) {
    GameStateMachineInit *temp_r3_715;
    GameStateMachineState *var_r4_0;
    M2C_UNK (*temp_r12_734)();
    s32 var_r0_714;

    var_r4_0 = arg0;
    this->unk18 = var_r4_0;
    this->unkC = 0;
loop_2:
    if ((s32) var_r4_0->unk0 != -1) {
        var_r4_0 += 0x20;
        this->unkC += 1;
        goto loop_2;
    }
    this->unk0 = -1;
    this->unk8 = -1;
    this->unk1C = NULL;
    this->unk28 = 0;
    this->unk20 = 0;
    this->unk24 = 0.0f;
    this->unk28 = 0;
    this->unk30 = 0;
    this->unk2C = 0;
    this->unk10 = 0;
    this->unk14 = 0.0f;
    this->unk38.Init();
    this->unk34 = arg1;
    var_r0_714 = 0;
    temp_r3_715 = this->unk34;
    if (temp_r3_715 != NULL) {
        var_r0_714 = temp_r3_715->unk0;
    }
    this->unk4 = var_r0_714;
    this->unk1C = this->unk18 + (this->unk4 << 5);
    if (M2C_FIELD(this->unk1C, s32 *, 8) & 1) {
        this->unk38.HeapMarkPush();
    }
    temp_r12_734 = M2C_FIELD(this->unk1C, M2C_UNK (**)(), 0x10);
    if (temp_r12_734 != NULL) {
        temp_r12_734();
    }
}
