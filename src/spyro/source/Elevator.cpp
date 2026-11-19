#include "spyro/source/Elevator.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKCollisionManager.h"
#include "common/Source/MKIni.h"
#include "spyro/source/GameProp.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "common/Source/MKModel.h"
#include "common/Source/StdMath.h"
#include <m2c_macros.h>

extern void **gMK;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern void **gb;

#if 0 // DRAFT: undefined identifier 'sp8'
void Elevator::Move(float arg0) {
    s8 sp80;
    s32 sp7C;
    s32 sp78;
    s32 sp74;
    f64 *sp70;
    s32 sp6C;
    s32 sp68;
    f64 sp60;
    f64 sp58;
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
    f32 temp_f1_71;
    f32 temp_f2_141;
    f32 temp_f30_81;
    f32 temp_f3_63;
    f32 temp_f4_51;
    f32 var_f0_52;
    f32 var_f0_64;
    void **temp_r3_80;
    void *temp_r3_90;
    void *var_r30_87;

    temp_f4_51 = this->unk134;
    var_f0_52 = (this->unk138 * gUpdateTimeDelta) + this->unk130;
    if (var_f0_52 < temp_f4_51) {

    } else {
        var_f0_52 = temp_f4_51;
    }
    this->unk130 = var_f0_52;
    temp_f3_63 = this->unk128;
    var_f0_64 = (arg0 * this->unk130) + this->unk13C;
    if (var_f0_64 < temp_f3_63) {

    } else {
        var_f0_64 = temp_f3_63;
    }
    temp_f1_71 = this->unk12C;
    if (var_f0_64 > temp_f1_71) {

    } else {
        var_f0_64 = temp_f1_71;
    }
    this->unk13C = var_f0_64;
    temp_r3_80 = this->unk120;
    temp_f30_81 = this->unk13C - this->unk13C;
    if (temp_r3_80 != NULL) {
        var_r30_87 = M2C_FIELD(*temp_r3_80, void **, 0x28);
loop_12:
        if (var_r30_87 != NULL) {
            temp_r3_90 = M2C_FIELD(var_r30_87, void **, 8);
            sp18 = 0.0f;
            sp1C = temp_f30_81;
            sp20 = 0.0f;
            sp28 = (f64) sp18;
            sp38 = M2C_FIELD(temp_r3_90, f64 *, 0x30);
            sp30 = (f64) sp20;
            sp40 = M2C_FIELD(temp_r3_90, f64 *, 0x38);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            sp58 = sp8;
            sp6C = 0;
            sp10 = (f32) sp40 + (f32) sp30;
            sp68 = 0x22;
            sp60 = (f64) sp10;
            sp70 = &sp58;
            sp74 = 0;
            sp78 = 0;
            sp7C = 0;
            sp80 = 1;
            M2C_FIELD(M2C_FIELD(var_r30_87, void **, 0x44), M2C_UNK (**)(void *, s32 *, M2C_UNK, M2C_UNK, f32, f32, f64), 0x2C)(var_r30_87, &sp68, 0x22, 0, (f32) sp30, (f32) sp40, (f64) sp18);
            var_r30_87 = M2C_FIELD(var_r30_87, void **, 0x38);
            goto loop_12;
        }
    }
    sp48 = M2C_FIELD(this, f64 *, 0x110);
    temp_f2_141 = this->unk13C - 650.0f;
    sp50 = M2C_FIELD(this, f64 *, 0x118);
    this->unkE0.unk30 = (f32) sp48;
    this->unkE0.unk34 = temp_f2_141;
    this->unkE0.unk38 = (f32) sp50;
    unksp4C = temp_f2_141;
    this->unkE0.unk3C = 1.0f;
}
#endif

void Elevator::WaitState() {
    if (this->unk148 < this->unkB8) {
        if ((u8) this->unk154 != 0) {
            this->unk150 = 3;
            this->unk154 = 0;
        } else {
            this->unk150 = 2;
        }
        this->unk14C = this->unkB8;
    }
}

#if 0 // DRAFT: undefined identifier 'unkspC'
void Elevator::ShudderState() {
    f64 sp10;
    f64 sp8;
    f32 temp_f1_196;
    f32 temp_f2_233;
    f32 temp_f31_203;
    f32 temp_f4_197;
    f32 var_f0_220;
    f32 var_f1_212;

    temp_f1_196 = this->unk148;
    temp_f4_197 = this->unkB8;
    temp_f31_203 = (temp_f1_196 - temp_f4_197) / 0.5f;
    var_f1_212 = 10.0f * (this->unk130 * _table_sinf(4.712389f / ((1.0f + temp_f1_196) - temp_f4_197)) * (temp_f31_203 * temp_f31_203));
    if (var_f1_212 < 0.0f) {
        var_f1_212 = -var_f1_212;
    }
    if ((u8) this->unk154 != 0) {
        var_f0_220 = this->unk128;
    } else {
        var_f0_220 = this->unk12C;
    }
    this->unk13C = var_f1_212 + var_f0_220;
    sp8 = M2C_FIELD(this, f64 *, 0x110);
    temp_f2_233 = this->unk13C - 650.0f;
    sp10 = M2C_FIELD(this, f64 *, 0x118);
    this->unkE0.unk30 = (f32) sp8;
    this->unkE0.unk34 = temp_f2_233;
    this->unkE0.unk38 = (f32) sp10;
    this->unkE0.unk3C = 1.0f;
    unkspC = temp_f2_233;
    if (this->unk148 < this->unkB8) {
        this->unk150 = 1;
        this->unk148 = this->unkB8 + this->unk144;
        this->unk130 = 0.0f;
    }
}
#endif

void Elevator::GoingDownState() {
    Move(-1.0f);
    M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
    if (this->unk13C == this->unk12C) {
        this->unk150 = 4;
        this->unk148 = 0.5f + this->unkB8;
    }
}

void Elevator::GoingUpState() {
    Move(1.0f);
    M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
    if (this->unk13C == this->unk128) {
        this->unk154 = 1;
        this->unk150 = 4;
        this->unk148 = 0.5f + this->unkB8;
    }
}

#if 0 // DRAFT: undefined identifier 'PlatformAttachDetachMsg'
void Elevator::Message(MKMessage *arg0) {
    s32 spC;
    s32 sp8;
    s32 temp_r0_333;
    u32 *temp_r3_421;
    void ***temp_r3_362;
    void **temp_r3_379;
    void **temp_r5_376;
    void *temp_r3_360;
    void *temp_r3_419;
    void *temp_r4_384;
    void *var_r26_388;

    temp_r0_333 = arg0->unk0;
    switch (temp_r0_333) {                          /* irregular */
    case -3:
        M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
        if (this->unk140 == this->unk128) {
            this->unk154 = 1;
        }
        this->unk150 = 0;
        this->unk14C = this->unkB8;
        break;
    case 35:
        temp_r3_360 = checked_cast<PlatformAttachDetachMsg *, MKMessage>(arg0);
        temp_r3_362 = M2C_FIELD(temp_r3_360, void ****, 8);
        if ((temp_r3_362 != NULL) && ((void **) *temp_r3_362 != NULL)) {
            temp_r5_376 = *M2C_FIELD(temp_r3_360, void ****, 8);
            if (temp_r5_376 != M2C_FIELD(*gb, u32 (**)(void **), 0xC)(gb)) {
                temp_r3_379 = this->unk120;
                if (temp_r3_379 != NULL) {
                    temp_r4_384 = M2C_FIELD(*temp_r3_379, void **, 0x28);
                    if (temp_r4_384 != (u32) M2C_FIELD(*temp_r5_376, u32 *, 0x28)) {
                        var_r26_388 = temp_r4_384;
loop_16:
                        if (var_r26_388 != NULL) {
                            spC = 0;
                            sp8 = 0x24;
                            M2C_FIELD(M2C_FIELD(var_r26_388, void **, 0x44), M2C_UNK (**)(void *, s32 *), 0x2C)(var_r26_388, &sp8);
                            var_r26_388 = M2C_FIELD(var_r26_388, void **, 0x38);
                            goto loop_16;
                        }
                        this->unk124 = 0;
                    }
                }
                this->unk124 += 1;
                this->unk120 = *M2C_FIELD(temp_r3_360, void ****, 8);
                M2C_FIELD(temp_r3_360, s8 *, 0xC) = 1;
            }
        }
        break;
    case 36:
        temp_r3_419 = checked_cast<PlatformAttachDetachMsg *, MKMessage>(arg0);
        temp_r3_421 = M2C_FIELD(temp_r3_419, u32 **, 8);
        if ((temp_r3_421 != NULL) && ((u32) *temp_r3_421 != 0U) && ((u32) *M2C_FIELD(temp_r3_419, u32 **, 8) != M2C_FIELD(*gb, u32 (**)(void **), 0xC)(gb))) {
            this->unk124 -= 1;
            if ((s32) this->unk124 <= 0) {
                this->unk120 = NULL;
            }
        }
        break;
    }
    GameProp::Message(arg0);
}
#endif

#if 0 // DRAFT: function call 'MKRand_Float(long *, float, float)' does not match
void Elevator::PropUpdate() {
    s32 temp_r0_469;

    GameProp::PropUpdate();
    if (this->unk10 & 0x80000) {
        temp_r0_469 = this->unk150;
        switch (temp_r0_469) {                      /* irregular */
        case 0:
            this->unk148 = this->unkB8 + MKRand_Float(&gViewSeed, 0.0f, 2.0f);
            this->unk150 = 1;
            break;
        case 1:
            WaitState();
            break;
        case 2:
            GoingUpState();
            break;
        case 3:
            GoingDownState();
            break;
        case 4:
            ShudderState();
            break;
        }
        ((MKCollisionManager *) (M2C_FIELD(*gMK, MKCollisionManager *(**)(void **), 0x84)(gMK)))->ForceUpdate((u32) this->unk70.unkC);
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unkspC'
void Elevator::Reset() {
    f64 sp10;
    f64 sp8;
    f32 temp_f3_540;

    GameProp::Reset();
    sp8 = M2C_FIELD(this, f64 *, 0x110);
    temp_f3_540 = this->unk140 - 650.0f;
    sp10 = M2C_FIELD(this, f64 *, 0x118);
    this->unkE0.unk30 = (f32) sp8;
    this->unkE0.unk34 = temp_f3_540;
    this->unkE0.unk38 = (f32) sp10;
    unkspC = temp_f3_540;
    this->unkE0.unk3C = 1.0f;
    this->unk148 = this->unkB8 + MKRand_Float(&gViewSeed, 0.0f, 2.0f);
    this->unk150 = 1;
    M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
    if (this->unk140 == this->unk128) {
        this->unk154 = 1;
    } else {
        this->unk154 = 0;
    }
    this->unk13C = 50.0f;
    ((MKCollisionManager *) (M2C_FIELD(*gMK, MKCollisionManager *(**)(void **), 0x84)(gMK)))->ForceUpdate((u32) this->unk70.unkC);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long' to
void Elevator::LoadDone() {
    f64 sp10;
    f64 sp8;
    f32 temp_f0_637;
    f32 temp_f0_646;
    f32 temp_f1_636;
    f32 temp_f2_658;
    s32 temp_r3_597;
    void *temp_r3_608;

    GameProp::LoadDone();
    temp_r3_597 = MKModel_GetSubObjectIndex(this->unk4, (SubObjectType) 0, "m_Post");
    MKModel_SetSubObjectLocalMatrix(this->unk4, (SubObjectType) 0, temp_r3_597, &this->unkE0);
    temp_r3_608 = MKModel_GetSubObjectOrigin(this->unk4, (SubObjectType) 0, temp_r3_597);
    this->unkC8 = M2C_FIELD(temp_r3_608, f64 *, 0);
    this->unkD0 = M2C_FIELD(temp_r3_608, f64 *, 8);
    MKModel_SetSubObjectLocalMatrix(this->unk4, (SubObjectType) 0, MKModel_GetSubObjectIndex(this->unk4, (SubObjectType) 0, "c_collide01"), &this->unkE0);
    if (this->unk128 > 600.0f) {
        this->unk128 = 600.0f;
    }
    if (this->unk12C < 50.0f) {
        this->unk12C = 50.0f;
    }
    temp_f1_636 = this->unk140;
    temp_f0_637 = this->unk128;
    M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
    if (temp_f1_636 == temp_f0_637) {
        this->unk140 = temp_f0_637;
        this->unk154 = 1;
    } else {
        temp_f0_646 = this->unk12C;
        if (temp_f1_636 < temp_f0_646) {
            this->unk140 = temp_f0_646;
        }
    }
    sp8 = M2C_FIELD(this, f64 *, 0x110);
    temp_f2_658 = this->unk140 - 650.0f;
    sp10 = M2C_FIELD(this, f64 *, 0x118);
    this->unkE0.unk30 = (f32) sp8;
    this->unkE0.unk34 = temp_f2_658;
    this->unkE0.unk38 = (f32) sp10;
    this->unkE0.unk3C = 1.0f;
    unkspC = temp_f2_658;
    this->unk150 = 0;
}
#endif

s32 Elevator::LoadLine(MKIniLine *arg0) {
    s32 var_r31_684;

    var_r31_684 = 0;
    if ((GameProp::LoadLine(arg0) != 0) || (arg0->LoadFloat("maxHeight", &this->unk128, 0) != 0) || (arg0->LoadFloat("minHeight", &this->unk12C, 0) != 0) || (arg0->LoadFloat("startHeight", &this->unk140, 0) != 0) || (arg0->LoadFloat("maxYSpeed", &this->unk134, 0) != 0) || (arg0->LoadFloat("yAcceleration", &this->unk138, 0) != 0) || (arg0->LoadFloat("waitTime", &this->unk144, 0) != 0)) {
        var_r31_684 = 1;
    }
    return var_r31_684;
}

void Elevator::Deinit() {
    s32 spC;
    s32 sp8;
    void **temp_r3_761;
    void *var_r29_767;

    temp_r3_761 = this->unk120;
    if (temp_r3_761 != NULL) {
        var_r29_767 = M2C_FIELD(*temp_r3_761, void **, 0x28);
loop_3:
        if (var_r29_767 != NULL) {
            spC = 0;
            sp8 = 0x24;
            M2C_FIELD(M2C_FIELD(var_r29_767, void **, 0x44), M2C_UNK (**)(void *, s32 *), 0x2C)(var_r29_767, &sp8);
            var_r29_767 = M2C_FIELD(var_r29_767, void **, 0x38);
            goto loop_3;
        }
        this->unk124 = 0;
    }
    this->unk120 = NULL;
    GameProp::Deinit();
}

void Elevator::Init() {
    GameProp::Init();
    this->unkE0.SetIdentity();
    this->unk128 = 400.0f;
    this->unk12C = 50.0f;
    this->unk130 = 0.0f;
    this->unk13C = 50.0f;
    this->unk140 = 50.0f;
    this->unk134 = 30.000002f;
    this->unk138 = 5.0f;
    this->unk144 = 3.0f;
    this->unk148 = 0.0f;
    this->unk154 = 0;
    this->unk14C = 0.0f;
    this->unk120 = NULL;
    this->unk124 = 0;
}
