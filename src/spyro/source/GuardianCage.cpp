#include "spyro/source/GuardianCage.h"
#include "common/Source/Animation.h"
#include "common/Source/Font.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKFont.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/AssaultCannon.h"
#include "spyro/source/Crate.h"
#include "spyro/source/DialogBox.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/FlyingChunkPS.h"
#include "spyro/source/Game.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/GlowingPropManager.h"
#include "spyro/source/Guardian.h"
#include "spyro/source/HeroInterface.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/KDStateMachine.h"
#include "spyro/source/Level.h"
#include "spyro/source/PlatformObject.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/ShatterablePlatform.h"
#include "spyro/source/TargetManager.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "common/Source/StdMath.h"
#include "spyro/source/Tools.h"
#include "unplaced_inlines.h"
#include <m2c_macros.h>

extern s32 GS_PrisonBallShatter;
extern void **gMK;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern GameGlobals gb;
static M2C_UNK lit_623;                                /* unable to generate initializer: unknown type */
u8 states__12GuardianCage[0x90] = {
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

void GuardianCage::StateDeadExit() {

}

void GuardianCage::StateDeadUpdate() {

}

void GuardianCage::StateDeadEnter() {
    MKVector3 vA;
    MKVector3 vC;
    MKVector3 vD;
    MKVector3 vF;
    MKVector4 vW;
    f32 rA;
    f32 rB;
    f32 rC;
    f32 rD;
    f32 rE;
    f32 rF;
    f32 rG;
    f32 rH;
    f32 rI;
    f32 rJ;
    f32 rK;
    f32 rL;
    f32 rScale;
    u8 *temp_r4;
    s32 var_r30_78;

    var_r30_78 = 0;
    do {
        rA = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
        rB = MKRand_Float((int *) &gViewSeed, 1.0f, 3.0f);
        rC = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
        vA.unk0 = rC * 1000.0f;
        vA.unk4 = rB * 1000.0f;
        vA.unk8 = rA * 1000.0f;

        rD = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
        rE = MKRand_Float((int *) &gViewSeed, 0.0f, 1.0f);
        rF = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
        temp_r4 = ((u8 *) this->unk8) + 0x30;
        vC.unk0 = M2C_FIELD(temp_r4, f32 *, 0x0) + rF * 400.0f;
        vC.unk4 = M2C_FIELD(temp_r4, f32 *, 0x4) + rE * 400.0f;
        vC.unk8 = M2C_FIELD(temp_r4, f32 *, 0x8) + rD * 400.0f;

        rG = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
        rH = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
        rI = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
        vD.unk0 = rI * 3.1415927f;
        vD.unk4 = rH * 3.1415927f;
        vD.unk8 = rG * 3.1415927f;

        rJ = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
        rK = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
        rL = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
        vF.unk0 = rL * 3.1415927f;
        vF.unk4 = rK * 3.1415927f;
        vF.unk8 = rJ * 3.1415927f;

        rScale = MKRand_Float((int *) &gViewSeed, 1.0f, 2.0f);
        vW.unk0 = 1.0f;
        vW.unk4 = 1.0f;
        vW.unk8 = 1.0f;
        vW.unkC = 1.0f;
        ((FlyingChunkPS *) gb.unkA0)->Emit(vC, vA, vD, vF, rScale, vW, 0, NULL);
        var_r30_78 += 1;
    } while (var_r30_78 < 0xF);
    KDSound_Play3d(GS_PrisonBallShatter, (const MKVector3 *) (((u8 *) this->unk8) + 0x30), 0U, -1, 0.0f, false);
    this->unk148.Send(NULL);
}

void GuardianCage::StateDyingExit() {
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp38;
    f64 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f64 sp10;
    f32 sp8;
    Guardian *temp_r3_370;
    f32 temp_f27_328;
    f32 temp_f28_333;
    f64 temp_f0_314;
    f64 temp_f0_347;
    s32 var_r30_301;
    void *temp_r4_306;

    var_r30_301 = 0;
    do {
        sp40 = 0.0f;
        sp44 = 25.0f;
        temp_r4_306 = ((u8 *) this->unk8) + 0x30;
        sp48 = 0.0f;
        sp70 = (f64) sp40;
        sp78 = (f64) sp48;
        temp_f0_314 = M2C_FIELD(temp_r4_306, f64 *, 0) + sp70;
        sp30 = temp_f0_314;
        sp80 = temp_f0_314;
        sp38 = M2C_FIELD(temp_r4_306, f32 *, 8) + (f32) sp78;
        sp88 = (f64) sp38;
        temp_f27_328 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
        temp_f28_333 = MKRand_Float((int *) &gViewSeed, 0.0f, 1.0f);
        sp20 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
        sp24 = temp_f28_333;
        sp28 = temp_f27_328;
        sp50 = (f64) sp20;
        sp58 = (f64) sp28;
        temp_f0_347 = sp50 * 5.697262106e-315;
        sp10 = temp_f0_347;
        sp60 = temp_f0_347;
        sp18 = (f32) sp58 * 1500.0f;
        sp68 = (f64) sp18;
        sp8 = MKRand_Float((int *) &gViewSeed, 2.0f, 3.0f);
        gb.EmitDust(*((MKVector3 *) &sp80), *((MKVector3 *) &sp60), sp8, 0.0f);
        var_r30_301 += 1;
    } while (var_r30_301 < 0x14);
    temp_r3_370 = this->unk144;
    if (temp_r3_370 != NULL) {
        temp_r3_370->AttachToCage(0U);
    }
}

void GuardianCage::StateDyingUpdate() {
    Matrix spD0;
    M2C_UNK spCC;
    f64 spC8;
    f64 spC0;
    f64 spB8;
    f64 spB0;
    f64 spA8;
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp58;
    f64 sp50;
    f32 sp48;
    f64 sp40;
    f32 sp38;
    f64 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    f32 temp_f28_453;
    f32 temp_f29_456;
    f32 temp_f2_496;
    f64 temp_f0_433;
    f64 temp_f0_468;
    f64 temp_f0_490;
    f64 temp_f0_515;

    this->unk11C += -1960.0f * gUpdateTimeDelta;
    M2C_STRUCT_COPY((s32) &spCC + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
    temp_f0_433 = M2C_FIELD(this, f64 *, 0x118) * (f64) gUpdateTimeDelta;
    sp10 = temp_f0_433;
    sp90 = temp_f0_433;
    sp18 = this->unk120 * gUpdateTimeDelta;
    sp98 = (f64) sp18;
    this->unk128 += temp_f0_433;
    this->unk130 += (f32) sp98;
    temp_f28_453 = _table_sinf(this->unkF0);
    temp_f29_456 = _table_sinf(this->unkEC);
    sp60 = _table_sinf(this->unkE8);
    sp64 = temp_f29_456;
    sp68 = temp_f28_453;
    spC0 = (f64) sp60;
    spC8 = (f64) sp68;
    temp_f0_468 = spC0 * 5.122630465e-315;
    sp50 = temp_f0_468;
    spB0 = temp_f0_468;
    sp58 = (f32) spC8 * 0.1f;
    spB8 = (f64) sp58;
    sp40 = spC0 * 5.53552857e-315;
    sp48 = (f32) spC8 * 100.0f;
    sp80 = sp40;
    sp88 = (f64) sp48;
    temp_f0_490 = this->unk128 + sp80;
    sp30 = temp_f0_490;
    temp_f2_496 = this->unk10C;
    spA0 = temp_f0_490;
    sp38 = this->unk130 + (f32) sp88;
    spA8 = (f64) sp38;
    M2C_ERROR(/* unknown instruction: cror 0x2, 0x0, 0x2 */);
    if ((*(f32 *) ((u8 *) &spA0 + 0x4)) == temp_f2_496) {
        (*(f32 *) ((u8 *) &spA0 + 0x4)) = temp_f2_496;
        ((KDStateMachine<GuardianCage> *) &this->unk14C)->SetState(this, 3, 0U);
    }
    temp_f0_515 = this->unkF8 + spB0;
    sp20 = temp_f0_515;
    sp70 = temp_f0_515;
    sp28 = this->unk100 + (f32) spB8;
    sp78 = (f64) sp28;
    spD0.SetRotationPYR(*((MKVector3 *) &sp70));
    spD0.unk30 = (f32) spA0;
    spD0.unk34 = (*(f32 *) ((u8 *) &spA0 + 0x4));
    spD0.unk38 = (f32) spA8;
    spD0.unk3C = 1.0f;
    MKModel_SetWorldMatrix(this->unk4, spD0);
}

void GuardianCage::StateDyingEnter() {
    u8 spRes[0x58];
    MKVector3 sp78;
    MKVector3 sp68;
    f64 sp18;
    f64 sp20;
    f64 spPair;
    f64 sp10Pair;
    f32 p2x;
    f32 p2y;
    f32 p2z;
    void *temp_r4_569;
    MKVector3 *temp_r3_616;

    sp78 = MKVector(0.0f, 800.0f, 0.0f);
    temp_r4_569 = ((u8 *) this->unk8) + 0x30;
    M2C_FIELD(&sp18, f32 *, 0) = M2C_FIELD(temp_r4_569, f32 *, 0) - sp78.unk0;
    M2C_FIELD(&sp18, f32 *, 4) = M2C_FIELD(temp_r4_569, f32 *, 4) - sp78.unk4;
    M2C_FIELD(this, f64 *, 0x108) = sp18;
    M2C_FIELD(&sp20, f32 *, 0) = M2C_FIELD(temp_r4_569, f32 *, 8) - sp78.unk8;
    M2C_FIELD(this, f64 *, 0x110) = sp20;

    M2C_FIELD(spRes, f32 *, 0x00) = 0.0f;
    M2C_FIELD(spRes, f32 *, 0x04) = 0.0f;
    M2C_FIELD(spRes, f32 *, 0x08) = 0.0f;
    M2C_FIELD(spRes, f32 *, 0x10) = 0.0f;
    M2C_FIELD(spRes, f32 *, 0x14) = 0.0f;
    M2C_FIELD(spRes, f32 *, 0x18) = 0.0f;
    M2C_FIELD(spRes, f32 *, 0x20) = 0.0f;
    M2C_FIELD(spRes, f32 *, 0x24) = 0.0f;
    M2C_FIELD(spRes, f32 *, 0x28) = 0.0f;
    M2C_FIELD(spRes, f32 *, 0x2C) = 1.0f;
    M2C_FIELD(spRes, f32 *, 0x30) = 0.0f;
    M2C_FIELD(spRes, f32 *, 0x34) = 0.0f;
    M2C_FIELD(spRes, s16 *, 0x38) = 0;
    M2C_FIELD(spRes, s8 *, 0x3A) = 0;
    M2C_FIELD(spRes, s8 *, 0x3B) = 0;
    M2C_FIELD(spRes, s32 *, 0x3C) = 0;
    M2C_FIELD(spRes, f32 *, 0x40) = 3.4028235e38f;
    M2C_FIELD(spRes, s32 *, 0x44) = 0;
    M2C_FIELD(spRes, s32 *, 0x48) = 0;
    M2C_FIELD(spRes, s32 *, 0x4C) = -1;
    M2C_FIELD(spRes, s8 *, 0x50) = 0;

    p2x = M2C_FIELD(temp_r4_569, f32 *, 0) + 0.0f;
    p2y = M2C_FIELD(temp_r4_569, f32 *, 4) + -10000.0f;
    p2z = M2C_FIELD(temp_r4_569, f32 *, 8) + 0.0f;
    sp68.unk0 = p2x;
    sp68.unk4 = p2y;
    sp68.unk8 = p2z;

    temp_r3_616 = (MKVector3 *) (((u8 *) this->unk8) + 0x30);
    if (MKCollision_RayCollide(*temp_r3_616, sp68, (MKCollisionResult *) spRes, (MKCollisionMode) 7, 0) != 0) {
        M2C_FIELD(this, f64 *, 0x108) = M2C_FIELD(spRes, f64 *, 0x00);
        M2C_FIELD(this, f64 *, 0x110) = M2C_FIELD(spRes, f64 *, 0x08);
    }

    M2C_FIELD(&spPair, f32 *, 0) = 0.0f;
    M2C_FIELD(&spPair, f32 *, 4) = -1960.0f;
    M2C_FIELD(this, f64 *, 0x118) = spPair;
    M2C_FIELD(&sp10Pair, f32 *, 0) = 0.0f;
    M2C_FIELD(this, f64 *, 0x120) = sp10Pair;
    M2C_FIELD(this, f64 *, 0x128) = M2C_FIELD(this, f64 *, 0xD8);
    M2C_FIELD(this, f64 *, 0x130) = M2C_FIELD(this, f64 *, 0xE0);
}

void GuardianCage::StateFloatingExit() {
    MKModel_EnableSubObject(this->unk4, (SubObjectType) 0, this->unk140, 0U, 1U);
}

#if 0 // DRAFT: illegal implicit conversion from 'MKVector3' to 'double'
void GuardianCage::StateFloatingUpdate() {
    Matrix spE0;
    M2C_UNK spDC;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    f64 spC0;
    f64 spB8;
    f64 spB0;
    f64 spA8;
    f64 spA0;
    MKVector3 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp58;
    f64 sp50;
    f32 sp48;
    f64 sp40;
    f32 sp38;
    f64 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    f32 temp_f28_703;
    f32 temp_f28_744;
    f32 temp_f29_747;
    f64 temp_f0_712;
    f64 temp_f0_759;
    f64 temp_f0_781;
    f64 temp_f0_794;

    temp_f28_703 = gUpdateTimeDelta;
    sp90 = MKVector(1.0f, 3.0f, 2.0f);
    temp_f0_712 = sp90 * (f64) temp_f28_703;
    sp10 = temp_f0_712;
    spA0 = temp_f0_712;
    sp18 = sp90.unk8 * temp_f28_703;
    spA8 = (f64) sp18;
    M2C_FIELD(this, f64 *, 0xE8) = (f64) (M2C_FIELD(this, f64 *, 0xE8) + temp_f0_712);
    this->unkF0 += (f32) spA8;
    M2C_STRUCT_COPY((s32) &spDC + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
    temp_f28_744 = _table_sinf(this->unkF0);
    temp_f29_747 = _table_sinf(this->unkEC);
    sp60 = _table_sinf(this->unkE8);
    sp64 = temp_f29_747;
    sp68 = temp_f28_744;
    spD0 = (f64) sp60;
    spD8 = (f64) sp68;
    temp_f0_759 = spD0 * 5.122630465e-315;
    sp50 = temp_f0_759;
    spC0 = temp_f0_759;
    sp58 = (f32) spD8 * 0.1f;
    spC8 = (f64) sp58;
    sp40 = spD0 * 5.53552857e-315;
    sp48 = (f32) spD8 * 100.0f;
    sp80 = sp40;
    sp88 = (f64) sp48;
    temp_f0_781 = this->unkD8 + sp80;
    sp30 = temp_f0_781;
    spB0 = temp_f0_781;
    sp38 = M2C_FIELD(this, f32 *, 0xE0) + (f32) sp88;
    spB8 = (f64) sp38;
    temp_f0_794 = this->unkF8 + temp_f0_759;
    sp20 = temp_f0_794;
    sp70 = temp_f0_794;
    sp28 = this->unk100 + (f32) spC8;
    sp78 = (f64) sp28;
    spE0.SetRotationPYR(*((MKVector3 *) &sp70));
    spE0.unk30 = (f32) spB0;
    spE0.unk34 = (*(f32 *) ((u8 *) &spB0 + 0x4));
    spE0.unk38 = (f32) spB8;
    spE0.unk3C = 1.0f;
    MKModel_SetWorldMatrix(this->unk4, spE0);
}
#endif

void GuardianCage::StateFloatingEnter() {
    Guardian *temp_r3_848;

    MKModel_EnableSubObject(this->unk4, (SubObjectType) 0, this->unk140, 1U, 1U);
    temp_r3_848 = this->unk144;
    if (temp_r3_848 != NULL) {
        temp_r3_848->AttachToCage(1U);
    }
}

MKVector3 GuardianCage::GetBeamPosition(int arg2) {
    MKVector3 sp8;
    s32 temp_r4;

    temp_r4 = *((s32 *) (((u8 *) this) + (arg2 * 4) + 0xC8));
    MKModel_CalculateRefPointWorldPosition(this->unk4, temp_r4, &sp8);
    return sp8;
}

void GuardianCage::Deinit() {
    ((KDStateMachine<GuardianCage> *) &this->unk14C)->Exit(this);
    GameProp::Deinit();
}

void GuardianCage::Message(MKMessage *arg0) {
    s32 temp_r3_920;

    if ((s32) arg0->unk0 != 0x87) {

    } else {
        temp_r3_920 = this->unk13C;
        if (temp_r3_920 > 0) {
            this->unk13C = temp_r3_920 - 1;
            if ((s32) this->unk13C <= 0) {
                ((KDStateMachine<GuardianCage> *) &this->unk14C)->SetState(this, 2, 0U);
            }
        }
    }
    GameProp::Message(arg0);
}

void GuardianCage::Draw() {
    if (((KDStateMachine<GuardianCage> *) &this->unk14C)->GetState() != 3) {
        GameProp::Draw();
    }
}

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to 'float'
void *GuardianCage::Update() {
    Matrix sp20;
    MKVector3 sp10;

    GameProp::Update();
    ((KDStateMachine<GuardianCage> *) &this->unk14C)->Update(this, 0);
    if ((Guardian *) this->unk144 != NULL) {
        M2C_STRUCT_COPY((s32) &sp10.unkC + 4, (s32) (((u8 *) this->unk8) - 4) + 4, 0x40);
        MKModel_CalculateRefPointWorldPosition(this->unk4, this->unkD0, &sp10);
        sp20.unk30 = M2C_BITWISE(f32, sp10);
        sp20.unk34 = sp10.unk4;
        sp20.unk38 = sp10.unk8;
        sp20.unk3C = 1.0f;
        MKModel_SetWorldMatrix(this->unk144->unk4, sp20);
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'const char[14]' to 'long *'
f32 GuardianCage::Resolve() {
    KDPropEx::Resolve();
    this->unk144 = (long *) (checked_cast<Guardian *, MKProp>(M2C_FIELD(*gMK, MKProp *(**)(void **, M2C_UNK *), 0x60)(gMK, "EarthGuardian")));
    ((KDStateMachine<GuardianCage> *) &this->unk14C)->Init((KDStateMachine<GuardianCage>::State *) GuardianCage::states, NULL);
    ((KDStateMachine<GuardianCage> *) &this->unk14C)->SetState(this, 1, 0U);
}
#endif

s32 GuardianCage::LoadDone() {
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    void *temp_r3_1078;

    GameProp::LoadDone();
    sp10 = 0.0f;
    this->unkF8 = M2C_FIELD(&MKProp::loadInfo, f64 *, 0x50);
    M2C_FIELD(this, f64 *, 0x100) = (f64) M2C_FIELD(&MKProp::loadInfo, f64 *, 0x58);
    temp_r3_1078 = this->unk8;
    sp8 = 0.0f;
    spC = 0.0f;
    this->unkD8 = M2C_FIELD(temp_r3_1078, f64 *, 0x30);
    this->unkE0 = M2C_FIELD(temp_r3_1078, f64 *, 0x38);
    M2C_FIELD(this, f64 *, 0xE8) = (f64) sp8;
    M2C_FIELD(this, f64 *, 0xF0) = (f64) sp10;
    sp18 = (f64) sp8;
    this->unk13C = this->unk138;
    sp20 = (f64) sp10;
    this->unk140 = MKModel_GetSubObjectIndex(this->unk4, (SubObjectType) 0, "m_cage_sphere");
    this->unkC8 = (s32) Tools_GetMatchingRefPointIndex(this->unk4, "top");
    this->unkCC = (s32) Tools_GetMatchingRefPointIndex(this->unk4, "bottom");
    this->unkD0 = (s32) Tools_GetMatchingRefPointIndex(this->unk4, "guardian");
}

s32 GuardianCage::LoadLine(MKIniLine *arg0) {
    s32 var_r31_1132;

    var_r31_1132 = 0;
    if ((GameProp::LoadLine(arg0) != 0) || (arg0->LoadInt("NumCrystals", (int *) &this->unk138, 0) != 0) || (this->unk148.LoadLine(arg0, "OnDestruction") != 0)) {
        var_r31_1132 = 1;
    }
    return var_r31_1132;
}

void GuardianCage::Reset() {
    Matrix sp10;
    M2C_UNK spC;

    GameProp::Reset();
    this->unk13C = this->unk138;
    M2C_STRUCT_COPY((s32) &spC + 4, MKModel_GetWorldMatrix(this->unk4) - 4 + 4, 0x40);
    sp10.unk30 = M2C_FIELD(this, f32 *, 0xD8);
    sp10.unk34 = M2C_FIELD(this, f32 *, 0xDC);
    sp10.unk38 = M2C_FIELD(this, f32 *, 0xE0);
    sp10.unk3C = 1.0f;
    MKModel_SetWorldMatrix(this->unk4, sp10);
    ((KDStateMachine<GuardianCage> *) &this->unk14C)->SetState(this, 1, 0U);
}

void GuardianCage::Init() {
    GameProp::Init();
    this->unk138 = 2;
    this->unk13C = 2;
}

#if 0 // DRAFT: undefined identifier '__ptmf_null'
void GuardianCage_cpp::__sinit() {
    s32 sp20;
    s32 sp1C;
    s32 sp18;
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    void *temp_r20_1420;

    temp_r20_1420 = &lit_623 + 0x6C;
    sp20 = M2C_FIELD(&lit_623, s32 *, 0x5C);
    M2C_FIELD(temp_r20_1420, s32 *, 0x78) = (s32) M2C_FIELD(&lit_623, s32 *, 0x54);
    sp14 = M2C_FIELD(&lit_623, s32 *, 0x60);
    M2C_FIELD(temp_r20_1420, s32 *, 0x80) = sp20;
    sp18 = M2C_FIELD(&lit_623, s32 *, 0x64);
    M2C_FIELD(temp_r20_1420, s32 *, 0x84) = sp14;
    M2C_FIELD(temp_r20_1420, s32 *, 0x88) = sp18;
    M2C_FIELD(&lit_623, s32 *, 0x6C) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 0);
    M2C_FIELD(&lit_623, s32 *, 0x70) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 4);
    M2C_FIELD(&lit_623, s32 *, 0x74) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 8);
    M2C_FIELD(temp_r20_1420, s32 *, 0xC) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 0);
    M2C_FIELD(temp_r20_1420, s32 *, 0x10) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 4);
    M2C_FIELD(temp_r20_1420, s32 *, 0x14) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 8);
    M2C_FIELD(temp_r20_1420, s32 *, 0x18) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 0);
    M2C_FIELD(temp_r20_1420, s32 *, 0x1C) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 4);
    M2C_FIELD(temp_r20_1420, s32 *, 0x20) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 8);
    M2C_FIELD(temp_r20_1420, s32 *, 0x24) = (s32) M2C_FIELD(&lit_623, s32 *, 0);
    M2C_FIELD(temp_r20_1420, s32 *, 0x28) = (s32) M2C_FIELD(&lit_623, s32 *, 4);
    M2C_FIELD(temp_r20_1420, s32 *, 0x2C) = (s32) M2C_FIELD(&lit_623, s32 *, 8);
    M2C_FIELD(temp_r20_1420, s32 *, 0x30) = (s32) M2C_FIELD(&lit_623, s32 *, 0xC);
    M2C_FIELD(temp_r20_1420, s32 *, 0x34) = (s32) M2C_FIELD(&lit_623, s32 *, 0x10);
    M2C_FIELD(temp_r20_1420, s32 *, 0x38) = (s32) M2C_FIELD(&lit_623, s32 *, 0x14);
    M2C_FIELD(temp_r20_1420, s32 *, 0x3C) = (s32) M2C_FIELD(&lit_623, s32 *, 0x18);
    M2C_FIELD(temp_r20_1420, s32 *, 0x40) = (s32) M2C_FIELD(&lit_623, s32 *, 0x1C);
    M2C_FIELD(temp_r20_1420, s32 *, 0x44) = (s32) M2C_FIELD(&lit_623, s32 *, 0x20);
    M2C_FIELD(temp_r20_1420, s32 *, 0x48) = (s32) M2C_FIELD(&lit_623, s32 *, 0x24);
    M2C_FIELD(temp_r20_1420, s32 *, 0x4C) = (s32) M2C_FIELD(&lit_623, s32 *, 0x28);
    M2C_FIELD(temp_r20_1420, s32 *, 0x50) = (s32) M2C_FIELD(&lit_623, s32 *, 0x2C);
    M2C_FIELD(temp_r20_1420, s32 *, 0x54) = (s32) M2C_FIELD(&lit_623, s32 *, 0x30);
    M2C_FIELD(temp_r20_1420, s32 *, 0x58) = (s32) M2C_FIELD(&lit_623, s32 *, 0x34);
    M2C_FIELD(temp_r20_1420, s32 *, 0x5C) = (s32) M2C_FIELD(&lit_623, s32 *, 0x38);
    M2C_FIELD(temp_r20_1420, s32 *, 0x60) = (s32) M2C_FIELD(&lit_623, s32 *, 0x3C);
    M2C_FIELD(temp_r20_1420, s32 *, 0x64) = (s32) M2C_FIELD(&lit_623, s32 *, 0x40);
    M2C_FIELD(temp_r20_1420, s32 *, 0x68) = (s32) M2C_FIELD(&lit_623, s32 *, 0x44);
    M2C_FIELD(temp_r20_1420, s32 *, 0x6C) = (s32) M2C_FIELD(&lit_623, s32 *, 0x48);
    M2C_FIELD(temp_r20_1420, s32 *, 0x70) = (s32) M2C_FIELD(&lit_623, s32 *, 0x4C);
    M2C_FIELD(temp_r20_1420, s32 *, 0x74) = (s32) M2C_FIELD(&lit_623, s32 *, 0x50);
    M2C_FIELD(temp_r20_1420, s32 *, 0x7C) = (s32) M2C_FIELD(&lit_623, s32 *, 0x58);
    M2C_FIELD(temp_r20_1420, s32 *, 0x8C) = (s32) M2C_FIELD(&lit_623, s32 *, 0x68);
    sp1C = M2C_FIELD(&lit_623, s32 *, 0x68);
    sp8 = M2C_FIELD(&__ptmf_null, s32 *, 0);
    spC = M2C_FIELD(&__ptmf_null, s32 *, 4);
    sp10 = M2C_FIELD(&__ptmf_null, s32 *, 8);
}
#endif
