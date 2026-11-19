#include "spyro/source/MiningMole.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "spyro/source/CrashFirePS.h"
#include "spyro/source/Enemy.h"
#include "spyro/source/EnemyDataTypes.h"
#include "spyro/source/MoleTether.h"
#include "spyro/source/NPCGoal_Think.h"
#include "unplaced_templates.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKModel.h"
#include "common/Source/StdMath.h"
#include "spyro/source/KDRandom.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/Tools.h"
#include <m2c_macros.h>

extern s32 GS_MoleLeaderCandleLP1;
extern MKSceneManager *gMK;
extern s32 gViewSeed;
extern M2C_UNK gb;

#if 0 // DRAFT: undefined identifier 'FreeMiningMoleBounceMessage'
void MiningMole::Message(MKMessage *arg0) {
    if ((s32) arg0->unk0 != 0x98) {

    } else if (checked_cast<FreeMiningMoleBounceMessage *, MKMessage>(arg0) != 0U) {
        ((NPCGoal_Think *) (checked_cast<P13NPCGoal_Think))->AddGoal_Rescue(12Goal<5Enemy>>__FP12Goal<5Enemy>((Goal<Enemy> *) this->unkA24));
    }
    Enemy::Message(arg0);
}
#endif

#if 0 // DRAFT: expression syntax error
void Exhumor::Message(MKMessage *arg0) {
    this->unkAFC.Message(arg0);
    Enemy::Message(arg0);
}
#endif

#if 0 // DRAFT: undefined identifier 'MKVector'
void Exhumor::Update() {
    MKVector3 sp88;
    f64 sp80;
    f64 sp78;
    MKVector3 sp68;
    MKVector3 sp58;
    M2C_UNK sp48;
    f64 sp40;
    f64 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f32 sp10;
    s32 sp8;
    s32 temp_cr0_eq_197;
    u8 var_r31_154;
    u8 var_r31_196;

    Enemy::Update();
    MKModel_CalculateRefPointWorldPosition(this->unk4, this->unkAF8, &sp88);
    MKVector(1.0f, 1.0f, 1.0f);
    MKVector(-1.0f, -1.0f, -1.0f);
    KDRand_Vector(sp68, sp58);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
    sp78 = sp18;
    sp20 = sp68.unk8 * 1.0f;
    sp80 = (f64) sp20;
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    sp88.unk8 += (f32) sp80;
    if ((void *) M2C_FIELD(&gb, void **, 0xC) != NULL) {
        var_r31_154 = 0;
        if ((((u32) M2C_FIELD(M2C_FIELD(&gb, void **, 0xC), u32 *, 0x78) != 0U) || ((u32) M2C_FIELD(M2C_FIELD(&gb, void **, 0xC), u32 *, 0x84) != 0U)) && (((KDStateMachine<CutsceneSystem> *) (M2C_FIELD(&gb, void **, 0xC) + 0x24))->GetState() != 0)) {
            var_r31_154 = 1;
        }
        if (var_r31_154 == 0) {
            goto block_6;
        }
    } else {
block_6:
        sp10 = MKRand_Float(&gViewSeed, 2.0f, 3.0f);
        sp2C = MKRand_Float(&gViewSeed, 0.0f, 200.0f);
        sp28 = 0.0f;
        sp30 = 0.0f;
        sp38 = (f64) sp28;
        sp40 = (f64) sp30;
        ((CrashFirePS *) (M2C_FIELD(&gb, CrashFirePS **, 0x68)))->Emit(sp88, *((MKVector3 *) &sp38), sp10);
    }
    var_r31_196 = 0;
    temp_cr0_eq_197 = (void *) M2C_FIELD(&gb, void **, 0xC) == NULL;
    if ((temp_cr0_eq_197 != 0) || ((temp_cr0_eq_197 == 0) && ((((u32) M2C_FIELD(M2C_FIELD(&gb, void **, 0xC), u32 *, 0x78) == 0U) && ((u32) M2C_FIELD(M2C_FIELD(&gb, void **, 0xC), u32 *, 0x84) == 0U)) || (((KDStateMachine<CutsceneSystem> *) (M2C_FIELD(&gb, void **, 0xC) + 0x24))->GetState() == 0)))) {
        var_r31_196 = 1;
    }
    sp8 = 1;
    this->unkAFC.Update(GS_MoleLeaderCandleLP1, 1U, var_r31_196, NULL, &sp88, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
}
#endif

void Exhumor::LoadDone() {
    Enemy::LoadDone();
    this->unkAF8 = (s32) Tools_GetMatchingRefPointIndex(this->unk4, "candle");
}

#if 0 // DRAFT: function call 'KDSound_Stop(long *)' does not match
void Exhumor::Deinit() {
    KDSound_Stop(&this->unkAFC);
    Enemy::Deinit();
}
#endif

#if 0 // DRAFT: function call 'operator new(unsigned int, int, int)' does not match
void Exhumor::Init() {
    NPCGoal_Think *temp_r31_288;

    Enemy::Init();
    operator new(0x3CU, NULL, 0);
    temp_r31_288 = M2C_ERROR(/* Read from unset register $r3 */);
    if (temp_r31_288 != NULL) {
        temp_r31_288->__vptr = &__vt__12Goal<5Enemy>;
        temp_r31_288->unk4 = 0;
        temp_r31_288->unk8 = 1;
        temp_r31_288->unk9 = 0;
        temp_r31_288->unkC = 0;
        temp_r31_288->__vptr = &__vt__21CompositeGoal<5Enemy>;
        temp_r31_288->unk1C = 0;
        temp_r31_288->unk18 = 0;
        temp_r31_288->unk10 = 0;
        temp_r31_288->unk14 = 0;
        temp_r31_288->__vptr = &__vt;
    }
    temp_r31_288->Init((Enemy *) this);
    temp_r31_288->unk38 = 0;
    this->unkA24 = (EnemyAttack *) temp_r31_288;
    this->unkAFC.Init(0.25f, 0.25f);
}
#endif

#if 0 // DRAFT: expression syntax error
void MiningMoleLeader::Message(MKMessage *arg0) {
    if ((s32) arg0->unk0 != 0x169) {
        this->unkAFC.Message(arg0);
        Enemy::Message(arg0);
        return;
    }
    ((NPCGoal_Think *) (checked_cast<P13NPCGoal_Think))->AddGoal_BreakRock(12Goal<5Enemy>>__FP12Goal<5Enemy>((Goal<Enemy> *) this->unkA24));
}
#endif

#if 0 // DRAFT: undefined identifier 'sp38'
void MiningMoleLeader::Update() {
    f64 spE0;
    f64 spD8;
    f64 spD0;                                       /* compiler-managed */
    f64 spC8;                                       /* compiler-managed */
    MKVector3 spB8;
    f64 spB0;
    f64 spA8;
    f64 spA0;
    f64 sp98;
    MKVector3 sp88;
    MKVector3 sp78;
    M2C_UNK sp68;
    f64 sp60;
    f64 sp58;
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
    s32 sp8;
    f32 var_f3_472;
    f32 var_f4_405;
    f64 temp_f1_411;
    f64 temp_f1_417;
    f64 temp_f1_421;
    s32 temp_r3_440;
    s32 var_r0_450;
    u8 var_r30_542;
    u8 var_r30_584;
    void *temp_r3_372;

    Enemy::Update();
    temp_r3_372 = this->unk8;
    sp50 = -10420.48f;
    sp48 = -22817.3f;
    sp4C = -3229.19f;
    spA8 = M2C_FIELD(temp_r3_372, f64 *, 0x30);
    spD8 = (f64) sp48;
    spE0 = (f64) sp50;
    spB0 = M2C_FIELD(temp_r3_372, f64 *, 0x38);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    spC8 = sp38;
    sp40 = (f32) spE0 - (f32) spB0;
    spD0 = (f64) sp40;
    var_f4_405 = ((f32) spD0 * (f32) spD0) + (((f32) spC8 * (f32) spC8) + (unkspCC * unkspCC));
    if (var_f4_405 > 0.000001f) {
        if (var_f4_405 > 0.0f) {
            temp_f1_411 = __frsqrte(var_f4_405);
            temp_f1_417 = 0.5 * temp_f1_411 * -(((f64) var_f4_405 * (temp_f1_411 * temp_f1_411)) - 3.0);
            temp_f1_421 = 0.5 * temp_f1_417 * -(((f64) var_f4_405 * (temp_f1_417 * temp_f1_417)) - 3.0);
            var_f4_405 = (f32) ((f64) var_f4_405 * (0.5 * temp_f1_421 * -(((f64) var_f4_405 * (temp_f1_421 * temp_f1_421)) - 3.0)));
        } else if (var_f4_405 < M2C_BITWISE(f32, 0.0)) {
            var_f4_405 = __float_nan;
        } else {
            sp10 = var_f4_405;
            temp_r3_440 = M2C_BITWISE(s32, sp10) & 0x7F800000;
            switch (temp_r3_440) {                  /* irregular */
            case 0x7F800000:
                if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                    var_r0_450 = 1;
                } else {
                    var_r0_450 = 2;
                }
                break;
            case 0x0:
                if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                    var_r0_450 = 5;
                } else {
                    var_r0_450 = 3;
                }
                break;
            default:
                var_r0_450 = 4;
                break;
            }
            if (var_r0_450 == 1) {
                var_f4_405 = __float_nan;
            }
        }
        var_f3_472 = 1.0f / var_f4_405;
    } else {
        var_f3_472 = 0.0f;
    }
    spC8 = (f32) spC8 * var_f3_472;
    unkspCC *= var_f3_472;
    spD0 = (f32) spD0 * var_f3_472;
    M2C_FIELD(this, f64 *, 0xE0) = (f64) spC8;
    M2C_FIELD(this, f64 *, 0xE8) = (f64) spD0;
    M2C_FIELD(this, f64 *, 0xC0) = (f64) M2C_FIELD(this, f64 *, 0xE0);
    M2C_FIELD(this, f64 *, 0xC8) = (f64) M2C_FIELD(this, f64 *, 0xE8);
    this->unk6B5 |= 0x40;
    MKModel_CalculateRefPointWorldPosition(this->unk4, this->unkAF8, &spB8);
    MKVector(1.0f, 1.0f, 1.0f);
    MKVector(-1.0f, -1.0f, -1.0f);
    KDRand_Vector(sp88, sp78);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
    sp98 = sp18;
    sp20 = sp88.unk8 * 1.0f;
    spA0 = (f64) sp20;
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    spB8.unk8 += (f32) spA0;
    if ((void *) M2C_FIELD(&gb, void **, 0xC) != NULL) {
        var_r30_542 = 0;
        if ((((u32) M2C_FIELD(M2C_FIELD(&gb, void **, 0xC), u32 *, 0x78) != 0U) || ((u32) M2C_FIELD(M2C_FIELD(&gb, void **, 0xC), u32 *, 0x84) != 0U)) && (((KDStateMachine<CutsceneSystem> *) (M2C_FIELD(&gb, void **, 0xC) + 0x24))->GetState() != 0)) {
            var_r30_542 = 1;
        }
        if (var_r30_542 == 0) {
            goto block_26;
        }
    } else {
block_26:
        sp14 = MKRand_Float(&gViewSeed, 2.0f, 3.0f);
        sp2C = MKRand_Float(&gViewSeed, 0.0f, 200.0f);
        sp28 = 0.0f;
        sp30 = 0.0f;
        sp58 = (f64) sp28;
        sp60 = (f64) sp30;
        ((CrashFirePS *) (M2C_FIELD(&gb, CrashFirePS **, 0x68)))->Emit(spB8, *((MKVector3 *) &sp58), sp14);
    }
    var_r30_584 = 0;
    if (((void *) M2C_FIELD(&gb, void **, 0xC) == NULL) || (((u32) M2C_FIELD(M2C_FIELD(&gb, void **, 0xC), u32 *, 0x78) == 0U) && ((u32) M2C_FIELD(M2C_FIELD(&gb, void **, 0xC), u32 *, 0x84) == 0U)) || (((KDStateMachine<CutsceneSystem> *) (M2C_FIELD(&gb, void **, 0xC) + 0x24))->GetState() == 0)) {
        var_r30_584 = 1;
    }
    sp8 = 1;
    this->unkAFC.Update(GS_MoleLeaderCandleLP1, 1U, var_r30_584, NULL, &spB8, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
}
#endif

void MiningMoleLeader::LoadDone() {
    Enemy::LoadDone();
    this->unkAF8 = (s32) Tools_GetMatchingRefPointIndex(this->unk4, "candle");
}

#if 0 // DRAFT: function call 'KDSound_Stop(long *)' does not match
void MiningMoleLeader::Deinit() {
    KDSound_Stop(&this->unkAFC);
    Enemy::Deinit();
}
#endif

#if 0 // DRAFT: function call 'operator new(unsigned int, int, int)' does not match
void MiningMoleLeader::Init() {
    NPCGoal_Think *temp_r31_675;

    Enemy::Init();
    operator new(0x3CU, NULL, 0);
    temp_r31_675 = M2C_ERROR(/* Read from unset register $r3 */);
    if (temp_r31_675 != NULL) {
        temp_r31_675->__vptr = &__vt__12Goal<5Enemy>;
        temp_r31_675->unk4 = 0;
        temp_r31_675->unk8 = 1;
        temp_r31_675->unk9 = 0;
        temp_r31_675->unkC = 0;
        temp_r31_675->__vptr = &__vt__21CompositeGoal<5Enemy>;
        temp_r31_675->unk1C = 0;
        temp_r31_675->unk18 = 0;
        temp_r31_675->unk10 = 0;
        temp_r31_675->unk14 = 0;
        temp_r31_675->__vptr = &__vt;
    }
    temp_r31_675->Init((Enemy *) this);
    temp_r31_675->unk38 = 0;
    this->unkA24 = (EnemyAttack *) temp_r31_675;
    this->unkAF8 = -1;
    this->unkAFC.Init(0.25f, 0.25f);
}
#endif

void MiningMole::Despawn(bool arg0) {
    s32 spC;
    s32 sp8;
    s32 temp_r3_725;
    s32 temp_r3_737;

    temp_r3_725 = this->unkAFC;
    if ((u32) temp_r3_725 != 0U) {
        spC = 0;
        sp8 = 0xBF;
        M2C_FIELD(M2C_FIELD(temp_r3_725, void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp8);
        temp_r3_737 = this->unkAFC;
        M2C_FIELD(M2C_FIELD(temp_r3_737, void **, 0x44), M2C_UNK (**)(s32), 0x34)(temp_r3_737);
    }
    Enemy::Despawn(arg0);
}

#if 0 // DRAFT: undefined identifier 'arg_spDC'
s32 MiningMole::Spawn(const Matrix *arg0, SpawnPointRef *arg1) {
    s32 temp_r3_772;
    s32 temp_r3_920;
    s32 temp_r3_925;
    void *temp_r3_787;
    void *temp_r4_805;
    if (M2C_FIELD(this->unkA2C, s32 *, 4) & 0x100000) {
        temp_r3_772 = this->unkAFC;
        M2C_FIELD(M2C_FIELD(temp_r3_772, void **, 0x44), M2C_UNK (**)(s32), 0x20)(temp_r3_772);
    }
    if (Enemy::Spawn(arg0, arg1) != 0) {
        M2C_FIELD(this->unkAF8, s32 *, 0x34) = 0;
        temp_r3_787 = this->unkA2C;
        if ((temp_r3_787 != NULL) && (M2C_FIELD(temp_r3_787, s32 *, 4) & 0x100000)) {
            M2C_STRUCT_COPY((s32) &arg_spDC + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
            temp_r4_805 = this->unk8;
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r3, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
            arg_spB8 = arg_sp68;
            arg_sp70 = M2C_FIELD((temp_r4_805 + 0x20), f32 *, 8) * 200.0f;
            arg_spC0 = (f64) arg_sp70;
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r4, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            arg_sp30 = 0.0f;
            arg_sp60 = M2C_FIELD((temp_r4_805 + 0x30), f32 *, 8) + (f32) arg_spC0;
            arg_sp28 = 0.0f;
            arg_sp2C = -200.0f;
            arg_spC8 = arg_sp58;
            arg_sp120 = 0.0f;
            arg_sp124 = 0.0f;
            arg_sp128 = 0.0f;
            arg_sp130 = 0.0f;
            arg_sp134 = 0.0f;
            arg_sp138 = 0.0f;
            arg_sp140 = 0.0f;
            arg_sp144 = 0.0f;
            arg_sp148 = 0.0f;
            arg_sp14C = 1.0f;
            arg_sp150 = 0.0f;
            arg_sp154 = 0.0f;
            arg_sp158 = 0;
            arg_sp158 = 0;
            (s8) arg_sp158 = 0;
            arg_sp15C = 0;
            arg_sp160 = 3.4028235e38f;
            arg_sp164 = 0;
            arg_sp168 = 0;
            arg_sp16C = -1;
            arg_sp170 = 0;
            arg_sp78 = (f64) arg_sp28;
            arg_spD0 = (f64) arg_sp60;
            arg_sp80 = (f64) arg_sp30;
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f5, $f0 */);
            arg_sp50 = 0.0f;
            arg_sp48 = 0.0f;
            arg_sp20 = (f32) arg_spD0 + (f32) arg_sp80;
            arg_sp4C = 200.0f;
            arg_sp88 = arg_sp18;
            arg_sp90 = (f64) arg_sp20;
            arg_sp98 = (f64) arg_sp48;
            arg_spA0 = (f64) arg_sp50;
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f5, $f0 */);
            arg_spA8 = arg_sp38;
            arg_sp40 = (f32) arg_spD0 + (f32) arg_spA0;
            arg_spB0 = (f64) arg_sp40;
            if (MKCollision_RayCollide(*((MKVector3 *) &arg_spA8), *((MKVector3 *) &arg_sp88), (MKCollisionResult *) &arg_sp120, (MKCollisionMode) 4, M2C_FIELD(this->unk110.unk460, s32 *, 0x18) | 0x0C000000) != 0) {
                arg_spC8 = (f64) arg_sp120;
                arg_spD0 = (f64) arg_sp128;
            }
            arg_sp110 = (f32) arg_spC8;
            arg_sp114 = arg_spCC;
            arg_sp118 = (f32) arg_spD0;
            arg_sp11C = 1.0f;
            this->unkAFC->SetWorldMatrix(*((Matrix *) &arg_spE0));
            temp_r3_920 = this->unkAFC;
            M2C_FIELD(M2C_FIELD(temp_r3_920, void **, 0x44), M2C_UNK (**)(s32), 0x30)(temp_r3_920);
            temp_r3_925 = this->unkAFC;
            arg_sp14 = 0;
            arg_sp10 = 0xBE;
            M2C_FIELD(M2C_FIELD(temp_r3_925, void **, 0x44), M2C_UNK (**)(s32, s32 *, M2C_UNK), 0x2C)(temp_r3_925, &arg_sp10, 0);
            M2C_FIELD(this->unkAF8, s32 *, 0x34) = (s32) this->unkAFC;
        }
        return 1;
    }
    return 0;
}
#endif

#if 0 // DRAFT: function call 'checked_cast(void *)' does not match
void MiningMole::LoadDone() {
    s32 temp_r3_972;

    Enemy::LoadDone();
    this->unkAFC = checked_cast<MoleTether *, MKProp>(gMK->CreateProp("MoleTether"));
    M2C_FIELD(this->unkAFC, MiningMole **, 0x1F0) = this;
    temp_r3_972 = this->unkAFC;
    M2C_FIELD(M2C_FIELD(temp_r3_972, void **, 0x44), M2C_UNK (**)(s32), 0x34)(temp_r3_972);
}
#endif

#if 0 // DRAFT: function call 'operator new(unsigned int, int, int)' does not match
void MiningMole::Init() {
    Enemy::Init();
    operator new(0x3CU, NULL, 0);
    if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
        *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
        M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
        M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
        M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
        M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
        *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__21CompositeGoal<5Enemy>;
        M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x1C) = 0;
        M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x18) = 0;
        M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x10) = 0;
        M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x14) = 0;
        *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
    }
    this->unkAF8 = M2C_ERROR(/* Read from unset register $r3 */);
    this->unkAF8->Init((Enemy *) this);
    M2C_FIELD(this->unkAF8, s8 *, 0x38) = 1;
    this->unkA24 = (EnemyAttack *) this->unkAF8;
}
#endif
