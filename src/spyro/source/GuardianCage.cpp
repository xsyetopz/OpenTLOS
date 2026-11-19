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

#if 0 // DRAFT: function call 'KDSound_Play3d(long, unsigned char *, unsigned int, int,
void GuardianCage::StateDeadEnter() {
    f64 sp140;
    f64 sp138;
    f64 sp130;
    f64 sp128;
    f64 sp120;
    f64 sp118;
    f64 sp110;
    f64 sp108;
    f64 sp100;
    f64 spF8;
    f64 spF0;
    f64 spE8;
    f64 spE0;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    f64 spC0;
    f64 spB8;
    f64 spB0;
    f64 spA8;
    f32 spA0;
    f32 sp9C;
    f32 sp98;
    f32 sp90;
    f64 sp88;
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    f32 sp70;
    f64 sp68;
    f32 sp60;
    f64 sp58;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp40;
    f64 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f1_226;
    f32 temp_f25_122;
    f32 temp_f25_168;
    f32 temp_f25_195;
    f32 temp_f25_90;
    f32 temp_f26_117;
    f32 temp_f26_163;
    f32 temp_f26_200;
    f32 temp_f26_85;
    f64 temp_f0_104;
    f64 temp_f0_136;
    f64 temp_f0_149;
    f64 temp_f0_182;
    f64 temp_f0_214;
    s32 var_r30_78;
    void *temp_r4_143;

    var_r30_78 = 0;
    do {
        temp_f26_85 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
        temp_f25_90 = MKRand_Float((int *) &gViewSeed, 1.0f, 3.0f);
        sp98 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
        sp9C = temp_f25_90;
        spA0 = temp_f26_85;
        sp128 = (f64) sp98;
        sp130 = (f64) spA0;
        temp_f0_104 = sp128 * 5.676053805e-315;
        sp88 = temp_f0_104;
        sp138 = temp_f0_104;
        sp90 = (f32) sp130 * 1000.0f;
        sp140 = (f64) sp90;
        temp_f26_117 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
        temp_f25_122 = MKRand_Float((int *) &gViewSeed, 0.0f, 1.0f);
        sp78 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
        sp7C = temp_f25_122;
        sp80 = temp_f26_117;
        spF8 = (f64) sp78;
        sp100 = (f64) sp80;
        temp_f0_136 = spF8 * 5.61841903e-315;
        sp68 = temp_f0_136;
        sp108 = temp_f0_136;
        temp_r4_143 = ((u8 *) this->unk8) + 0x30;
        sp70 = (f32) sp100 * 400.0f;
        sp110 = (f64) sp70;
        temp_f0_149 = M2C_FIELD(temp_r4_143, f64 *, 0) + temp_f0_136;
        sp58 = temp_f0_149;
        sp118 = temp_f0_149;
        sp60 = M2C_FIELD(temp_r4_143, f32 *, 8) + (f32) sp110;
        sp120 = (f64) sp60;
        temp_f26_163 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
        temp_f25_168 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
        sp48 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
        sp4C = temp_f25_168;
        sp50 = temp_f26_163;
        spD8 = (f64) sp48;
        spE0 = (f64) sp50;
        temp_f0_182 = spD8 * 5.328646264e-315;
        sp38 = temp_f0_182;
        spE8 = temp_f0_182;
        sp40 = (f32) spE0 * 3.1415927f;
        spF0 = (f64) sp40;
        temp_f25_195 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
        temp_f26_200 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
        sp28 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
        sp2C = temp_f26_200;
        sp30 = temp_f25_195;
        spB8 = (f64) sp28;
        spC0 = (f64) sp30;
        temp_f0_214 = spB8 * 5.328646264e-315;
        sp18 = temp_f0_214;
        spC8 = temp_f0_214;
        sp20 = (f32) spC0 * 3.1415927f;
        spD0 = (f64) sp20;
        temp_f1_226 = MKRand_Float((int *) &gViewSeed, 1.0f, 2.0f);
        sp8 = 1.0f;
        spC = 1.0f;
        sp10 = 1.0f;
        sp14 = 1.0f;
        spA8 = (f64) sp8;
        spB0 = (f64) sp10;
        ((FlyingChunkPS *) gb.unkA0)->Emit(*((MKVector3 *) &sp118), *((MKVector3 *) &sp138), *((MKVector3 *) &spE8), *((MKVector3 *) &spC8), temp_f1_226, *((MKVector4 *) &spA8), 0, NULL);
        var_r30_78 += 1;
    } while (var_r30_78 < 0xF);
    KDSound_Play3d(GS_PrisonBallShatter, ((u8 *) this->unk8) + 0x30, 0U, -1, 0.0f, 0U);
    this->unk148.Send(NULL);
}
#endif

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

#if 0 // DRAFT: undefined identifier 'MKVector'
void GuardianCage::StateDyingEnter() {
    s8 spE8;
    s32 spE4;
    s32 spE0;
    s32 spDC;
    f32 spD8;
    s32 spD4;
    s8 spD3;
    s8 spD2;
    s16 spD0;
    f32 spCC;
    f32 spC8;
    f32 spC4;
    f32 spC0;
    f32 spBC;
    f32 spB8;
    f32 spB0;
    f32 spAC;
    f32 spA8;
    f32 spA0;
    f32 sp9C;
    f32 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    MKVector3 *temp_r3_616;
    f64 temp_f0_622;
    void *temp_r4_569;

    MKVector(0.0f, 800.0f, 0.0f);
    temp_r4_569 = ((u8 *) this->unk8) + 0x30;
    sp18 = M2C_FIELD(temp_r4_569, f64 *, 0) - sp78;
    M2C_FIELD(this, f64 *, 0x108) = sp18;
    sp20 = M2C_FIELD(temp_r4_569, f32 *, 8) - sp80;
    sp40 = 0.0f;
    this->unk110 = (f64) sp20;
    sp38 = 0.0f;
    sp3C = -10000.0f;
    sp98 = 0.0f;
    sp9C = 0.0f;
    spA0 = 0.0f;
    spA8 = 0.0f;
    spAC = 0.0f;
    spB0 = 0.0f;
    spB8 = 0.0f;
    spBC = 0.0f;
    spC0 = 0.0f;
    spC4 = 1.0f;
    spC8 = 0.0f;
    spCC = 0.0f;
    spD0 = 0;
    spD2 = 0;
    spD3 = 0;
    spD4 = 0;
    spD8 = 3.4028235e38f;
    spDC = 0;
    spE0 = 0;
    spE4 = -1;
    spE8 = 0;
    sp58 = (f64) sp38;
    temp_r3_616 = ((u8 *) this->unk8) + 0x30;
    sp88 = sp18;
    sp90 = (f64) sp20;
    sp60 = (f64) sp40;
    temp_f0_622 = M2C_FIELD(temp_r3_616, f64 *, 0) + sp58;
    sp28 = temp_f0_622;
    sp68 = temp_f0_622;
    sp30 = temp_r3_616->unk8 + (f32) sp60;
    sp70 = (f64) sp30;
    if (MKCollision_RayCollide(*temp_r3_616, *((MKVector3 *) &sp68), (MKCollisionResult *) &sp98, (MKCollisionMode) 7, 0) != 0) {
        M2C_FIELD(this, f64 *, 0x108) = (f64) sp98;
        this->unk110 = (f64) spA0;
    }
    sp8 = 0.0f;
    spC = -1960.0f;
    sp10 = 0.0f;
    M2C_FIELD(this, f64 *, 0x118) = (f64) sp8;
    M2C_FIELD(this, f64 *, 0x120) = (f64) sp10;
    sp48 = (f64) sp8;
    this->unk128 = this->unkD8;
    sp50 = (f64) sp10;
    M2C_FIELD(this, f64 *, 0x130) = (f64) this->unkE0;
}
#endif

void GuardianCage::StateFloatingExit() {
    MKModel_EnableSubObject(this->unk4, (SubObjectType) 0, this->unk140, 0U, 1U);
}

#if 0 // DRAFT: undefined identifier 'MKVector'
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
    f32 temp_f28_703;
    f32 temp_f28_744;
    f32 temp_f29_747;
    f64 temp_f0_712;
    f64 temp_f0_759;
    f64 temp_f0_781;
    f64 temp_f0_794;

    temp_f28_703 = gUpdateTimeDelta;
    MKVector(1.0f, 3.0f, 2.0f);
    temp_f0_712 = sp90 * (f64) temp_f28_703;
    sp10 = temp_f0_712;
    spA0 = temp_f0_712;
    sp18 = sp98 * temp_f28_703;
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

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to
void GuardianCage::GetBeamPosition(int arg0) {
    MKVector3 sp8;

    MKModel_CalculateRefPointWorldPosition(M2C_FIELD(arg0, MKModel **, 4), M2C_FIELD((arg0 + (M2C_ERROR(/* Read from unset register $r5 */) * 4)), s32 *, 0xC8), &sp8);
    M2C_FIELD(this, f64 *, 0) = M2C_BITWISE(f64, sp8);
    M2C_FIELD(this, f64 *, 8) = (f64) sp8.unk8;
}
#endif

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

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to
void GuardianCage::Update() {
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

#if 0 // DRAFT: illegal implicit conversion from 'const char[14]' to
void GuardianCage::Resolve() {
    KDPropEx::Resolve();
    this->unk144 = checked_cast<Guardian *, MKProp>(M2C_FIELD(*gMK, MKProp *(**)(void **, M2C_UNK *), 0x60)(gMK, "EarthGuardian"));
    Init__30KDStateMachine<12GuardianCage>FPQ230KDStateMachine<12GuardianCage>5StateP30KDStateMachine<12GuardianCage>((KDStateMachine<GuardianCage> *) &this->unk14C, (KDStateMachine<GuardianCage>::State *) GuardianCage::states, NULL);
    ((KDStateMachine<GuardianCage> *) &this->unk14C)->SetState(this, 1, 0U);
}
#endif

void GuardianCage::LoadDone() {
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
