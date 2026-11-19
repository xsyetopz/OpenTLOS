#ifndef SPYRO_SOURCE_ENEMYGOAL_FOLLOWGRAPH_H
#define SPYRO_SOURCE_ENEMYGOAL_FOLLOWGRAPH_H

#include <dolphin/types.h>
#include "common/Source/MKVector3.h"
#include "spyro/source/CompositeGoal.h"
#include "spyro/source/Goal.h"
#include "spyro/source/KDSpline.h"
#include "spyro/source/TargetManager.h"

class Character;
class Enemy;
class EnemyGoal_BarricadeHide;
class EnemyGoal_BarricadeKick;
class EnemyGoal_Despawn;
class EnemyGoal_FollowGraph;
class EnemyGoal_GraphBarricade;
class EnemyGoal_GraphFly;
class EnemyGoal_GraphFlyPath;
class EnemyGoal_GraphGlidePath;
class EnemyGoal_GraphHover;
class EnemyGoal_GraphJump;
class EnemyGoal_GraphRun;
class EnemyGoal_GraphSummonWall;
class EnemyGoal_GraphTurn;
class EnemyGoal_GraphWalk;
class KDUniformSpline;
class MKProp;
class MKVector3;
class TargetContext;

class EnemyGoal_BarricadeHide : public Goal<Enemy> {  // base: vtable prefix
public:
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
};

class EnemyGoal_BarricadeKick : public Goal<Enemy> {  // base: vtable prefix
public:
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Enemy* unkC;
};

class EnemyGoal_Despawn : public Goal<Enemy> {  // base: vtable prefix
public:
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ MKProp* unkC;
};

class EnemyGoal_FollowGraph : public CompositeGoal<Enemy> {  // base: vtable prefix
public:
    virtual void Deinit(void);
    virtual void Reset(void);
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    virtual void Arbitrate(void);
    void AddGoal_OperateLever(void);
    void AddGoal_GraphHover(void);
    void AddGoal_SummonWall(void);
    void AddGoal_Summon(void);
    void AddGoal_Drop(void);
    void AddGoal_PickUp(void);
    void AddGoal_GiveOrders(void);
    void AddGoal_RangeAttackMode(void);
    void AddGoal_Death(void);
    void AddGoal_Cower(void);
    void AddGoal_Taunt(bool);
    void AddGoal_Alert(void);
    void AddGoal_Sleep(void);
    void AddGoal_Cheer(void);
    void AddGoal_SpawnUntilTrigger(void);
    void AddGoal_IdleAndAlertOnTrigger(int);
    void AddGoal_IdleUntilTrigger(int);
    void AddGoal_Turn(void);
    void AddGoal_Idle(void);
    void AddGoal_Barricade(void);
    void AddGoal_FollowPath(void);
    void AddGoal_Jump(void);
    void AddGoal_GlidePath(void);
    void AddGoal_FlyPath(void);
    void AddGoal_Fly(void);
    void AddGoal_Flee(void);
    void AddGoal_Run(void);
    void AddGoal_Walk(void);
    void Init(Enemy *);
    /* 0x004 */ s32 unk4;
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 unk9;
    /* 0x00a */ u8 padA[0x2];
    /* 0x00c */ Character* unkC;
    /* 0x010 */ s32 unk10;
    /* 0x014 */ s32 unk14;
    /* 0x018 */ s32 unk18;
    /* 0x01c */ void* unk1C;
    /* 0x020 */ f32 unk20;
    /* 0x024 */ Goal<Enemy>* unk24;
    /* 0x028 */ Goal<Enemy>* unk28;
    /* 0x02c */ Goal<Enemy>* unk2C;
    /* 0x030 */ Goal<Enemy>* unk30;
    /* 0x034 */ Goal<Enemy>* unk34;
    /* 0x038 */ Goal<Enemy>* unk38;
    /* 0x03c */ Goal<Enemy>* unk3C;
    /* 0x040 */ Goal<Enemy>* unk40;
    /* 0x044 */ Goal<Enemy>* unk44;
    /* 0x048 */ Goal<Enemy>* unk48;
    /* 0x04c */ Goal<Enemy>* unk4C;
    /* 0x050 */ Goal<Enemy>* unk50;
    /* 0x054 */ Goal<Enemy>* unk54;
    /* 0x058 */ Goal<Enemy>* unk58;
    /* 0x05c */ Goal<Enemy>* unk5C;
    /* 0x060 */ Goal<Enemy>* unk60;
    /* 0x064 */ Goal<Enemy>* unk64;
    /* 0x068 */ Goal<Enemy>* unk68;
    /* 0x06c */ Goal<Enemy>* unk6C;
    /* 0x070 */ Goal<Enemy>* unk70;
    /* 0x074 */ Goal<Enemy>* unk74;
    /* 0x078 */ Goal<Enemy>* unk78;
    /* 0x07c */ Goal<Enemy>* unk7C;
    /* 0x080 */ Goal<Enemy>* unk80;
    /* 0x084 */ void** unk84;
    /* 0x088 */ Goal<Enemy>* unk88;
    /* 0x08c */ f32 unk8C;
    /* 0x090 */ s32 unk90;
    /* 0x094 */ u8 unk94;
    /* 0x095 */ u8 unk95;
};

class EnemyGoal_GraphBarricade : public CompositeGoal<Enemy> {  // base: vtable prefix
public:
    virtual void Deinit(void);
    virtual void Reset(void);
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    virtual void Arbitrate(void);
    void AddGoal_Summon(void);
    void AddGoal_GiveOrders(void);
    void AddGoal_Attack(void);
    void AddGoal_Kick(void);
    void AddGoal_MoveTo(void);
    void Init(Enemy *);
    /* 0x004 */ s32 unk4;
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 unk9;
    /* 0x00a */ u8 padA[0x2];
    /* 0x00c */ Enemy* unkC;
    /* 0x010 */ s32 unk10;
    /* 0x014 */ s32 unk14;
    /* 0x018 */ s32 unk18;
    /* 0x01c */ void* unk1C;
    /* 0x020 */ TargetContext unk20;
    /* 0x030 */ void** unk30;
    /* 0x034 */ Goal<Enemy>* unk34;
    /* 0x038 */ Goal<Enemy>* unk38;
    /* 0x03c */ Goal<Enemy>* unk3C;
    /* 0x040 */ u8 unk40;
    /* 0x041 */ u8 pad41[0x1db];
    /* 0x21c */ s32 unk21C;
};

class EnemyGoal_GraphFly : public Goal<Enemy> {  // base: vtable prefix
public:
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Enemy* unkC;
    /* 0x010 */ u8 unk10;
};

class EnemyGoal_GraphFlyPath : public Goal<Enemy> {  // base: vtable prefix
public:
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Enemy* unkC;
    /* 0x010 */ void* unk10;
    /* 0x014 */ u8 pad14[0x4];
    /* 0x018 */ MKVector3 unk18;
    /* 0x028 */ f32 unk28;
    /* 0x02c */ f32 unk2C;
};

class EnemyGoal_GraphGlidePath : public Goal<Enemy> {  // base: vtable prefix
public:
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Enemy* unkC;
    /* 0x010 */ void* unk10;
    /* 0x014 */ u8 pad14[0x4];
    /* 0x018 */ MKVector3 unk18;
    /* 0x028 */ f32 unk28;
    /* 0x02c */ f32 unk2C;
};

class EnemyGoal_GraphHover : public Goal<Enemy> {  // base: vtable prefix
public:
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    void Init(Enemy *);
    /* 0x004 */ s32 unk4;
    /* 0x008 */ u8 unk8;
    /* 0x009 */ s8 unk9;
    /* 0x00a */ u8 padA[0x2];
    /* 0x00c */ Enemy* unkC;
    /* 0x010 */ f32 unk10;
};

class EnemyGoal_GraphJump : public Goal<Enemy> {  // base: vtable prefix
public:
    virtual void Deinit(void);
    virtual void Reset(void);
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    void GetParabolaCentre(MKVector3, MKVector3, float, float);
    f32 GetParabolaApexTimeFromP2(MKVector3, MKVector3, float, float);
    f32 GetParabolaApexTimeFromP1(MKVector3, MKVector3, float, float);
    f32 GetTotalTime(MKVector3, MKVector3, float, float);
    void Init(Enemy *);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ s8 unk9;
    /* 0x00a */ u8 padA[0x2];
    /* 0x00c */ Character* unkC;
    /* 0x010 */ f64 unk10;
    /* 0x018 */ f64 unk18;
    /* 0x020 */ f64 unk20;
    /* 0x028 */ f64 unk28;
    /* 0x030 */ KDUniformSpline unk30;
    /* 0x044 */ f32 unk44;
    /* 0x048 */ f32 unk48;
    /* 0x04c */ f32 unk4C;
};

class EnemyGoal_GraphRun : public Goal<Enemy> {  // base: vtable prefix
public:
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Character* unkC;
    /* 0x010 */ s8 unk10;
    /* 0x011 */ u8 unk11;
    /* 0x012 */ u8 pad12[0x2];
    /* 0x014 */ s32 unk14;
    /* 0x018 */ s32 unk18;
};

class EnemyGoal_GraphSummonWall : public Goal<Enemy> {  // base: vtable prefix
public:
    virtual void Reset(void);
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Enemy* unkC;
    /* 0x010 */ void* unk10;
};

class EnemyGoal_GraphTurn : public Goal<Enemy> {  // base: vtable prefix
public:
    virtual void Reset(void);
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Character* unkC;
    /* 0x010 */ f64 unk10;
    /* 0x018 */ f64 unk18;
    /* 0x020 */ f32 unk20;
};

class EnemyGoal_GraphWalk : public Goal<Enemy> {  // base: vtable prefix
public:
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Character* unkC;
    /* 0x010 */ s8 unk10;
    /* 0x011 */ u8 unk11;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#include <m2c_macros.h>

#if 0 // DRAFT: pointer/array required
inline void EnemyGoal_GraphJump::GetParabolaCentre(MKVector3 arg0, MKVector3 arg1, float arg2, float arg3) {
    f64 spC0;
    f64 spB8;
    f64 spB0;                                       /* compiler-managed */
    f64 spA8;
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp10;
    f32 temp_f1_9057;
    f32 temp_f29_9019;
    f32 temp_f3_9040;
    f32 temp_f5_9041;
    f32 var_f2_9081;
    void *temp_r31_9001;

    temp_r31_9001 = M2C_ERROR(/* Read from unset register $r6 */);
    sp88 = *M2C_ERROR(/* Read from unset register $r6 */);
    sp90 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r6 */), f64 *, 8);
    sp98 = M2C_FIELD(arg1, f64 *, 0);
    spA0 = M2C_FIELD(arg1, f64 *, 8);
    temp_f29_9019 = arg0->GetParabolaApexTimeFromP1((MKVector3) &sp98, (MKVector3) &sp88, arg2, arg3);
    sp68 = M2C_FIELD(temp_r31_9001, f64 *, 0);
    sp70 = M2C_FIELD(temp_r31_9001, f64 *, 8);
    sp78 = M2C_FIELD(arg1, f64 *, 0);
    sp80 = M2C_FIELD(arg1, f64 *, 8);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r31, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: psq_lx $f4, $zero, $r30, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f0, $f4 */);
    temp_f3_9040 = temp_f29_9019 / (temp_f29_9019 + arg0->GetParabolaApexTimeFromP2((MKVector3) &sp78, (MKVector3) &sp68, arg2, arg3));
    temp_f5_9041 = (f32) M2C_FIELD(arg1, f64 *, 8);
    spA8 = sp18;
    sp58 = sp18;
    unkspAC = 0.0f;
    sp20 = (f32) M2C_FIELD(temp_r31_9001, f64 *, 8) - temp_f5_9041;
    sp60 = (f64) sp20;
    spB0 = (f64) sp20;
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f4, $f0 */);
    temp_f1_9057 = (f32) spB0 * temp_f3_9040;
    spB0 = temp_f1_9057;
    sp38 = M2C_FIELD(arg1, f64 *, 0);
    sp28 = M2C_FIELD(temp_r31_9001, f64 *, 0);
    sp10 = temp_f5_9041 + temp_f1_9057;
    sp48 = sp8;
    sp50 = (f64) sp10;
    spB8 = sp8;
    spC0 = (f64) sp10;
    sp40 = M2C_FIELD(arg1, f64 *, 8);
    sp30 = M2C_FIELD(temp_r31_9001, f64 *, 8);
    M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
    if (unksp3C == unksp2C) {
        var_f2_9081 = arg2;
    } else {
        var_f2_9081 = arg2 + (unksp2C - unksp3C);
    }
    unkspBC = M2C_FIELD(arg1, f32 *, 4) + var_f2_9081;
    M2C_FIELD(this, f64 *, 0) = spB8;
    M2C_FIELD(this, f64 *, 8) = spC0;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to
inline f32 EnemyGoal_GraphJump::GetParabolaApexTimeFromP2(MKVector3 arg0, MKVector3 arg1, float arg2, float arg3) {
    f64 sp28;
    f64 sp20;
    f64 sp18;
    f64 sp10;
    f32 sp8;
    f32 var_f1_0;
    f32 var_f1_9134;
    f64 temp_f2_9137;
    f64 temp_f2_9143;
    f64 temp_f2_9147;
    s32 temp_r3_9166;
    s32 var_r0_9176;

    var_f1_0 = arg2;
    sp20 = M2C_FIELD(arg0, f64 *, 0);
    sp10 = M2C_FIELD(arg1, f64 *, 0);
    sp28 = M2C_FIELD(arg0, f64 *, 8);
    sp18 = M2C_FIELD(arg1, f64 *, 8);
    M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
    if (unksp24 == unksp14) {

    } else {
        var_f1_0 += unksp24 - unksp14;
    }
    var_f1_9134 = var_f1_0 / (-0.5f * arg3);
    if (var_f1_9134 > 0.0f) {
        temp_f2_9137 = __frsqrte(var_f1_9134);
        temp_f2_9143 = 0.5 * temp_f2_9137 * -(((f64) var_f1_9134 * (temp_f2_9137 * temp_f2_9137)) - 3.0);
        temp_f2_9147 = 0.5 * temp_f2_9143 * -(((f64) var_f1_9134 * (temp_f2_9143 * temp_f2_9143)) - 3.0);
        return (f32) ((f64) var_f1_9134 * (0.5 * temp_f2_9147 * -(((f64) var_f1_9134 * (temp_f2_9147 * temp_f2_9147)) - 3.0)));
    }
    if (var_f1_9134 < M2C_BITWISE(f32, 0.0)) {
        return __float_nan;
    }
    sp8 = var_f1_9134;
    temp_r3_9166 = M2C_BITWISE(s32, sp8) & 0x7F800000;
    switch (temp_r3_9166) {                         /* irregular */
    case 0x7F800000:
        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
            var_r0_9176 = 1;
        } else {
            var_r0_9176 = 2;
        }
        break;
    case 0x0:
        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
            var_r0_9176 = 5;
        } else {
            var_r0_9176 = 3;
        }
        break;
    default:
        var_r0_9176 = 4;
        break;
    }
    if (var_r0_9176 == 1) {
        var_f1_9134 = __float_nan;
    }
    return var_f1_9134;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to
inline f32 EnemyGoal_GraphJump::GetParabolaApexTimeFromP1(MKVector3 arg0, MKVector3 arg1, float arg2, float arg3) {
    f64 sp28;
    f64 sp20;
    f64 sp18;
    f64 sp10;
    f32 sp8;
    f32 var_f1_0;
    f32 var_f1_9227;
    f64 temp_f2_9230;
    f64 temp_f2_9236;
    f64 temp_f2_9240;
    s32 temp_r3_9259;
    s32 var_r0_9269;

    var_f1_0 = arg2;
    sp20 = M2C_FIELD(arg0, f64 *, 0);
    sp10 = M2C_FIELD(arg1, f64 *, 0);
    sp28 = M2C_FIELD(arg0, f64 *, 8);
    sp18 = M2C_FIELD(arg1, f64 *, 8);
    M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
    if (unksp24 == unksp14) {

    } else {
        var_f1_0 += unksp14 - unksp24;
    }
    var_f1_9227 = -var_f1_0 / (0.5f * arg3);
    if (var_f1_9227 > 0.0f) {
        temp_f2_9230 = __frsqrte(var_f1_9227);
        temp_f2_9236 = 0.5 * temp_f2_9230 * -(((f64) var_f1_9227 * (temp_f2_9230 * temp_f2_9230)) - 3.0);
        temp_f2_9240 = 0.5 * temp_f2_9236 * -(((f64) var_f1_9227 * (temp_f2_9236 * temp_f2_9236)) - 3.0);
        return (f32) ((f64) var_f1_9227 * (0.5 * temp_f2_9240 * -(((f64) var_f1_9227 * (temp_f2_9240 * temp_f2_9240)) - 3.0)));
    }
    if (var_f1_9227 < M2C_BITWISE(f32, 0.0)) {
        return __float_nan;
    }
    sp8 = var_f1_9227;
    temp_r3_9259 = M2C_BITWISE(s32, sp8) & 0x7F800000;
    switch (temp_r3_9259) {                         /* irregular */
    case 0x7F800000:
        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
            var_r0_9269 = 1;
        } else {
            var_r0_9269 = 2;
        }
        break;
    case 0x0:
        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
            var_r0_9269 = 5;
        } else {
            var_r0_9269 = 3;
        }
        break;
    default:
        var_r0_9269 = 4;
        break;
    }
    if (var_r0_9269 == 1) {
        var_f1_9227 = __float_nan;
    }
    return var_f1_9227;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to
inline f32 EnemyGoal_GraphJump::GetTotalTime(MKVector3 arg0, MKVector3 arg1, float arg2, float arg3) {
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f64 sp20;
    f64 sp18;
    f64 sp10;
    f64 sp8;
    f32 temp_f31_9325;
    f64 temp_f0_9313;
    f64 temp_f3_9311;
    f64 temp_f4_9309;
    f64 temp_f5_9307;

    temp_f5_9307 = M2C_FIELD(arg1, f64 *, 0);
    temp_f4_9309 = M2C_FIELD(arg1, f64 *, 8);
    temp_f3_9311 = M2C_FIELD(arg0, f64 *, 0);
    temp_f0_9313 = M2C_FIELD(arg0, f64 *, 8);
    sp8 = temp_f5_9307;
    sp10 = temp_f4_9309;
    sp18 = temp_f3_9311;
    sp20 = temp_f0_9313;
    sp28 = temp_f5_9307;
    sp30 = temp_f4_9309;
    sp38 = temp_f3_9311;
    sp40 = temp_f0_9313;
    temp_f31_9325 = GetParabolaApexTimeFromP2((MKVector3) &sp18, (MKVector3) &sp8, arg2, arg3);
    return 0.5f * (GetParabolaApexTimeFromP1((MKVector3) &sp38, (MKVector3) &sp28, arg2, arg3) + temp_f31_9325);
}
#endif

#endif  // SPYRO_SOURCE_ENEMYGOAL_FOLLOWGRAPH_H
