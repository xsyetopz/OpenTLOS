#include "spyro/source/GuardianCage.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/Game.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/Guardian.h"
#include "spyro/source/KDPropEx.h"
#include "unplaced_templates.h"
#include "common/Source/MKCollision.h"
#include "common/Source/StdMath.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/Tools.h"
#include <m2c_macros.h>

extern s32 GS_PrisonBallShatter;
extern void **gMK;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern GameGlobals gb;
static M2C_UNK lit_623;                                /* unable to generate initializer: unknown type */
static GuardianCage states__12GuardianCage;         /* type too large by 0xC0; unable to generate initializer: not enough data */

void GuardianCage::StateDeadExit() {

}

void GuardianCage::StateDeadUpdate() {

}

#if 0 // DRAFT: function call 'MKRand_Float(long *, float, float)' does not match
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
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    f32 sp70;
    f32 sp60;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp40;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
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
    s32 var_r30_78;

    var_r30_78 = 0;
    do {
        temp_f26_85 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        temp_f25_90 = MKRand_Float(&gViewSeed, 1.0f, 3.0f);
        sp98 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        sp9C = temp_f25_90;
        spA0 = temp_f26_85;
        sp128 = (f64) sp98;
        sp130 = (f64) spA0;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
        sp138 = sp88;
        sp90 = (f32) sp130 * 1000.0f;
        sp140 = (f64) sp90;
        temp_f26_117 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        temp_f25_122 = MKRand_Float(&gViewSeed, 0.0f, 1.0f);
        sp78 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        sp7C = temp_f25_122;
        sp80 = temp_f26_117;
        spF8 = (f64) sp78;
        sp100 = (f64) sp80;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
        sp108 = sp68;
        sp70 = (f32) sp100 * 400.0f;
        sp110 = (f64) sp70;
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r4, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        sp118 = sp58;
        sp60 = M2C_FIELD((this->unk8 + 0x30), f32 *, 8) + (f32) sp110;
        sp120 = (f64) sp60;
        temp_f26_163 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        temp_f25_168 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        sp48 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        sp4C = temp_f25_168;
        sp50 = temp_f26_163;
        spD8 = (f64) sp48;
        spE0 = (f64) sp50;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
        spE8 = sp38;
        sp40 = (f32) spE0 * 3.1415927f;
        spF0 = (f64) sp40;
        temp_f25_195 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        temp_f26_200 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        sp28 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        sp2C = temp_f26_200;
        sp30 = temp_f25_195;
        spB8 = (f64) sp28;
        spC0 = (f64) sp30;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f28 */);
        spC8 = sp18;
        sp20 = (f32) spC0 * 3.1415927f;
        spD0 = (f64) sp20;
        temp_f1_226 = MKRand_Float(&gViewSeed, 1.0f, 2.0f);
        sp8 = 1.0f;
        spC = 1.0f;
        sp10 = 1.0f;
        sp14 = 1.0f;
        spA8 = (f64) sp8;
        spB0 = (f64) sp10;
        gb.unkA0->Emit(*((MKVector3 *) &sp118), *((MKVector3 *) &sp138), *((MKVector3 *) &spE8), *((MKVector3 *) &spC8), temp_f1_226, *((MKVector4 *) &spA8), 0, NULL);
        var_r30_78 += 1;
    } while (var_r30_78 < 0xF);
    KDSound_Play3d(GS_PrisonBallShatter, this->unk8 + 0x30, 0U, -1, 0.0f, 0U);
    this->unk148.Send(NULL);
}
#endif

#if 0 // DRAFT: undefined identifier 'sp30'
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
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f32 sp8;
    Guardian *temp_r3_370;
    f32 temp_f27_328;
    f32 temp_f28_333;
    s32 var_r30_301;

    var_r30_301 = 0;
    do {
        sp40 = 0.0f;
        sp44 = 25.0f;
        sp48 = 0.0f;
        sp70 = (f64) sp40;
        sp78 = (f64) sp48;
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r4, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        sp80 = sp30;
        sp38 = M2C_FIELD((this->unk8 + 0x30), f32 *, 8) + (f32) sp78;
        sp88 = (f64) sp38;
        temp_f27_328 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        temp_f28_333 = MKRand_Float(&gViewSeed, 0.0f, 1.0f);
        sp20 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        sp24 = temp_f28_333;
        sp28 = temp_f27_328;
        sp50 = (f64) sp20;
        sp58 = (f64) sp28;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
        sp60 = sp10;
        sp18 = (f32) sp58 * 1500.0f;
        sp68 = (f64) sp18;
        sp8 = MKRand_Float(&gViewSeed, 2.0f, 3.0f);
        gb.EmitDust(*((MKVector3 *) &sp80), *((MKVector3 *) &sp60), sp8, 0.0f);
        var_r30_301 += 1;
    } while (var_r30_301 < 0x14);
    temp_r3_370 = this->unk144;
    if (temp_r3_370 != NULL) {
        temp_r3_370->AttachToCage(0U);
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_spCC'
void GuardianCage::StateDyingUpdate() {
    f32 temp_f28_453;
    f32 temp_f29_456;
    f32 temp_f2_496;
    this->unk11C += -1960.0f * gUpdateTimeDelta;
    M2C_STRUCT_COPY((s32) &arg_spCC + 4, (s32) (&identity - 4) + 4, 0x40);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $r31, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f3 */);
    arg_sp90 = arg_sp10;
    arg_sp18 = this->unk120 * gUpdateTimeDelta;
    arg_sp98 = (f64) arg_sp18;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    M2C_ERROR(/* unknown instruction: psq_stx $f0, $r31, $r0, 0x0, qr0 */);
    this->unk130 += (f32) arg_sp98;
    temp_f28_453 = _table_sinf(this->unkF0);
    temp_f29_456 = _table_sinf(this->unkEC);
    arg_sp60 = _table_sinf(this->unkE8);
    arg_sp64 = temp_f29_456;
    arg_sp68 = temp_f28_453;
    arg_spC0 = (f64) arg_sp60;
    arg_spC8 = (f64) arg_sp68;
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
    arg_spB0 = arg_sp50;
    arg_sp58 = (f32) arg_spC8 * 0.1f;
    arg_spB8 = (f64) arg_sp58;
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
    arg_sp48 = (f32) arg_spC8 * 100.0f;
    arg_sp80 = arg_sp40;
    arg_sp88 = (f64) arg_sp48;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    temp_f2_496 = this->unk10C;
    arg_spA0 = arg_sp30;
    arg_sp38 = this->unk130 + (f32) arg_sp88;
    arg_spA8 = (f64) arg_sp38;
    M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
    if (arg_spA4 == temp_f2_496) {
        arg_spA4 = temp_f2_496;
        this->unk14C.SetState(this, 3, 0U);
    }
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    arg_sp70 = arg_sp20;
    arg_sp28 = this->unk100 + (f32) arg_spB8;
    arg_sp78 = (f64) arg_sp28;
    arg_spD0.SetRotationPYR(*((MKVector3 *) &arg_sp70));
    arg_sp100 = (f32) arg_spA0;
    arg_sp104 = arg_spA4;
    arg_sp108 = (f32) arg_spA8;
    arg_sp10C = 1.0f;
    MKModel_SetWorldMatrix(this->unk4, *((Matrix *) &arg_spD0));
}
#endif

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
    M2C_UNK sp78;
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
    f32 sp20;
    f32 sp10;
    f32 spC;
    f32 sp8;
    MKVector3 *temp_r3_616;

    MKVector(0.0f, 800.0f, 0.0f);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r4, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    M2C_FIELD(this, f64 *, 0x108) = sp18;
    sp20 = M2C_FIELD((this->unk8 + 0x30), f32 *, 8) - sp80;
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
    temp_r3_616 = this->unk8 + 0x30;
    sp88 = sp18;
    sp90 = (f64) sp20;
    sp60 = (f64) sp40;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r3, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    sp68 = sp28;
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

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void GuardianCage::StateFloatingExit() {
    MKModel_EnableSubObject(this->unk4, (SubObjectType) 0, this->unk140, 0U, 1U);
}
#endif

#if 0 // DRAFT: undefined identifier 'MKVector'
void GuardianCage::StateFloatingUpdate() {
    f32 temp_f28_703;
    f32 temp_f28_744;
    f32 temp_f29_747;
    temp_f28_703 = gUpdateTimeDelta;
    MKVector(1.0f, 3.0f, 2.0f);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f28 */);
    arg_spA0 = arg_sp10;
    arg_sp18 = arg_sp98 * temp_f28_703;
    arg_spA8 = (f64) arg_sp18;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    M2C_ERROR(/* unknown instruction: psq_stx $f0, $r31, $r0, 0x0, qr0 */);
    this->unkF0 += (f32) arg_spA8;
    M2C_STRUCT_COPY((s32) &arg_spDC + 4, (s32) (&identity - 4) + 4, 0x40);
    temp_f28_744 = _table_sinf(this->unkF0);
    temp_f29_747 = _table_sinf(this->unkEC);
    arg_sp60 = _table_sinf(this->unkE8);
    arg_sp64 = temp_f29_747;
    arg_sp68 = temp_f28_744;
    arg_spD0 = (f64) arg_sp60;
    arg_spD8 = (f64) arg_sp68;
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
    arg_spC0 = arg_sp50;
    arg_sp58 = (f32) arg_spD8 * 0.1f;
    arg_spC8 = (f64) arg_sp58;
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
    arg_sp48 = (f32) arg_spD8 * 100.0f;
    arg_sp80 = arg_sp40;
    arg_sp88 = (f64) arg_sp48;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    arg_spB0 = arg_sp30;
    arg_sp38 = M2C_FIELD(this, f32 *, 0xE0) + (f32) arg_sp88;
    arg_spB8 = (f64) arg_sp38;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    arg_sp70 = arg_sp20;
    arg_sp28 = this->unk100 + (f32) arg_spC8;
    arg_sp78 = (f64) arg_sp28;
    arg_spE0.SetRotationPYR(*((MKVector3 *) &arg_sp70));
    arg_sp110 = (f32) arg_spB0;
    arg_sp114 = arg_spB4;
    arg_sp118 = (f32) arg_spB8;
    arg_sp11C = 1.0f;
    MKModel_SetWorldMatrix(this->unk4, *((Matrix *) &arg_spE0));
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void GuardianCage::StateFloatingEnter() {
    Guardian *temp_r3_848;

    MKModel_EnableSubObject(this->unk4, (SubObjectType) 0, this->unk140, 1U, 1U);
    temp_r3_848 = this->unk144;
    if (temp_r3_848 != NULL) {
        temp_r3_848->AttachToCage(1U);
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to
void GuardianCage::GetBeamPosition(int arg0) {
    MKVector3 sp8;

    MKModel_CalculateRefPointWorldPosition(M2C_FIELD(arg0, MKModel **, 4), M2C_FIELD((arg0 + (M2C_ERROR(/* Read from unset register $r5 */) * 4)), s32 *, 0xC8), &sp8);
    M2C_FIELD(this, f64 *, 0) = M2C_BITWISE(f64, sp8);
    M2C_FIELD(this, f64 *, 8) = (f64) sp8.unk8;
}
#endif

#if 0 // DRAFT: expression syntax error
void GuardianCage::Deinit() {
    this->unk14C.Exit(this);
    GameProp::Deinit();
}
#endif

#if 0 // DRAFT: expression syntax error
void GuardianCage::Message(MKMessage *arg0) {
    s32 temp_r3_920;

    if ((s32) arg0->unk0 != 0x87) {

    } else {
        temp_r3_920 = this->unk13C;
        if (temp_r3_920 > 0) {
            this->unk13C = temp_r3_920 - 1;
            if ((s32) this->unk13C <= 0) {
                this->unk14C.SetState(this, 2, 0U);
            }
        }
    }
    GameProp::Message(arg0);
}
#endif

#if 0 // DRAFT: expression syntax error
void GuardianCage::Draw() {
    if (this->unk14C.GetState() != 3) {
        GameProp::Draw();
    }
}
#endif

#if 0 // DRAFT: expression syntax error
void GuardianCage::Update() {
    GameProp::Update();
    this->unk14C.Update(this, 0);
    if ((Guardian *) this->unk144 != NULL) {
        M2C_STRUCT_COPY((s32) &arg_sp1C + 4, (s32) (this->unk8 - 4) + 4, 0x40);
        MKModel_CalculateRefPointWorldPosition(this->unk4, this->unkD0, (MKVector3 *) &arg_sp10);
        arg_sp50 = arg_sp10;
        arg_sp54 = arg_sp14;
        arg_sp58 = arg_sp18;
        arg_sp5C = 1.0f;
        MKModel_SetWorldMatrix(this->unk144->unk4, *((Matrix *) &arg_sp20));
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'const char[14]' to
void GuardianCage::Resolve() {
    KDPropEx::Resolve();
    this->unk144 = checked_cast<Guardian *, MKProp>(M2C_FIELD(*gMK, MKProp *(**)(void **, M2C_UNK *), 0x60)(gMK, "EarthGuardian"));
    Init__30KDStateMachine<12GuardianCage>FPQ230KDStateMachine<12GuardianCage>5StateP30KDStateMachine<12GuardianCage>((KDStateMachine<GuardianCage> *) &this->unk14C, (KDStateMachine<GuardianCage>::State *) &states, NULL);
    this->unk14C.SetState(this, 1, 0U);
}
#endif

#if 0 // DRAFT: undefined identifier 'loadInfo'
void GuardianCage::LoadDone() {
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    void *temp_r3_1078;

    GameProp::LoadDone();
    sp10 = 0.0f;
    this->unkF8 = M2C_FIELD(&loadInfo, f64 *, 0x50);
    M2C_FIELD(this, f64 *, 0x100) = (f64) M2C_FIELD(&loadInfo, f64 *, 0x58);
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
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long *' to
s32 GuardianCage::LoadLine(MKIniLine *arg0) {
    s32 var_r31_1132;

    var_r31_1132 = 0;
    if ((GameProp::LoadLine(arg0) != 0) || (arg0->LoadInt("NumCrystals", &this->unk138, 0) != 0) || (this->unk148.LoadLine(arg0, "OnDestruction") != 0)) {
        var_r31_1132 = 1;
    }
    return var_r31_1132;
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_spC'
void GuardianCage::Reset() {
    GameProp::Reset();
    this->unk13C = this->unk138;
    M2C_STRUCT_COPY((s32) &arg_spC + 4, MKModel_GetWorldMatrix(this->unk4) - 4 + 4, 0x40);
    arg_sp40 = M2C_FIELD(this, f32 *, 0xD8);
    arg_sp44 = M2C_FIELD(this, f32 *, 0xDC);
    arg_sp48 = M2C_FIELD(this, f32 *, 0xE0);
    arg_sp4C = 1.0f;
    MKModel_SetWorldMatrix(this->unk4, *((Matrix *) &arg_sp10));
    this->unk14C.SetState(this, 1, 0U);
}
#endif

void GuardianCage::Init() {
    GameProp::Init();
    this->unk138 = 2;
    this->unk13C = 2;
}

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<Guardian *, MKProp>(MKProp *arg0) {

}
#endif

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
