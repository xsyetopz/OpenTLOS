#ifndef SPYRO_SOURCE_SPARX_H
#define SPYRO_SOURCE_SPARX_H

#include <dolphin/types.h>
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "spyro/source/KDSpline.h"
#include "spyro/source/KDStateMachine.h"

class KDUniformSpline;
class MKCollisionResult;
class MKIniLine;
class MKMessage;
class MKProp;
class MKPropDescriptor;
class MKVector3;
class Matrix;
class Sparx;
class SparxDescriptor;
class SparxFX;
class SparxHintMsg;
class SparxPath;
class Sparx_cpp;

class Sparx : public MKProp {  // base: ctor/dtor vtable stores
public:
    virtual ~Sparx(void);
    virtual void Init(void);
    virtual s32 LoadDone(void);
    virtual void Deinit(void);
    virtual f32 Resolve(void);
    virtual void Reset(void);
    virtual void * Update(void);
    virtual void Draw(void);
    virtual void Message(MKMessage *);
    virtual void Enable(void);
    virtual void Disable(void);
    void StateAction_StrafeTargetUpdate(void);
    void StateAction_StrafeTargetExit(void);
    void StateAction_StrafeTargetEnter(void);
    s32 SetPath(SparxPath *);
    void StateAction_FollowPathUpdate(void);
    void StateAction_FollowPathExit(void);
    void StateAction_FollowPathEnter(void);
    void StateAction_LoadCatapultUpdate(void);
    void StateAction_LoadCatapultExit(void);
    void StateAction_LoadCatapultEnter(void);
    void StateAction_SpyroHintUpdate(void);
    void StateAction_SpyroHintExit(void);
    void StateAction_SpyroHintEnter(void);
    void StateAction_SpyroFallUpdate(void);
    void StateAction_SpyroFallExit(void);
    void StateAction_SpyroFallEnter(void);
    void StateAction_SpyroJumpUpdate(void);
    void StateAction_SpyroJumpExit(void);
    void StateAction_SpyroJumpEnter(void);
    void StateAction_SpyroDeadDieUpdate(void);
    void StateAction_SpyroDeadDieExit(void);
    void StateAction_SpyroDeadDieEnter(void);
    void StateAction_SpyroSpeedwayUpdate(void);
    void StateAction_SpyroSpeedwayExit(void);
    void StateAction_SpyroSpeedwayEnter(void);
    void StateAction_SpyroFuryUpdate(void);
    void StateAction_SpyroFuryExit(void);
    void StateAction_SpyroFuryEnter(void);
    void StateAction_SpyroAirCombatUpdate(void);
    void StateAction_SpyroAirCombatExit(void);
    void StateAction_SpyroAirCombatEnter(void);
    void StateAction_SpyroGroundCombatUpdate(void);
    void StateAction_SpyroGroundCombatExit(void);
    void StateAction_SpyroGroundCombatEnter(void);
    void CalculateAttackPosition(bool);
    void StateAction_SpyroChargeUpdate(void);
    void StateAction_SpyroChargeExit(void);
    void StateAction_SpyroChargeEnter(void);
    void StateAction_SpyroWalkRunUpdate(void);
    void StateAction_SpyroWalkRunExit(void);
    void StateAction_SpyroWalkRunEnter(void);
    void CalculateLongIdle2Spline(void);
    void StateAction_SpyroLongIdle2Update(void);
    void StateAction_SpyroLongIdle2Exit(void);
    void StateAction_SpyroLongIdle2Enter(void);
    void StateAction_SpyroLongIdle1Update(void);
    void StateAction_SpyroLongIdle1Exit(void);
    void StateAction_SpyroLongIdle1Enter(void);
    void StateAction_SpyroIdleUpdate(void);
    void StateAction_SpyroIdleExit(void);
    void StateAction_SpyroIdleEnter(void);
    void ResetLongIdle2(void);
    void GetNextLocalIdlePos(void);
    u8 UpdateLerpToWorldPos(const MKVector3 &, float, float);
    void UpdateLerpToLocalOffset(float);
    void Teleport(void);
    void SetHint(SparxHintMsg *);
    void ResetHint(void);
    void SetState(int, bool);
    u8 GetTaskMode(void);
    void Spawn(void);
    void RespawnOnSpyroDeath(void);
    void SetDefaults(void);
    /* 0x04c */ s32 unk4C;
    /* 0x050 */ Matrix unk50;
    /* 0x090 */ void* unk90;
    /* 0x094 */ void* unk94;
    /* 0x098 */ SparxFX* unk98;
    /* 0x09c */ KDStateMachine<Sparx> unk9C;
    /* 0x09d */ u8 pad9D[0x17];
    /* 0x0b4 */ f32 unkB4;
    /* 0x0b8 */ f32 unkB8;
    /* 0x0bc */ f32 unkBC;
    /* 0x0c0 */ u8 padC0[0x4];
    /* 0x0c4 */ f32 unkC4;
    /* 0x0c8 */ f32 unkC8;
    /* 0x0cc */ f32 unkCC;
    /* 0x0d0 */ s32 unkD0;
    /* 0x0d4 */ u8 unkD4;
    /* 0x0d5 */ u8 padD5[0x3];
    /* 0x0d8 */ f32 unkD8;
    /* 0x0dc */ u8 padDC[0x4];
    /* 0x0e0 */ f32 unkE0;
    /* 0x0e4 */ u8 padE4[0x4];
    /* 0x0e8 */ f32 unkE8;
    /* 0x0ec */ f32 unkEC;
    /* 0x0f0 */ f32 unkF0;
    /* 0x0f4 */ f32 unkF4;
    /* 0x0f8 */ s32 unkF8;
    /* 0x0fc */ s32 unkFC;
    /* 0x100 */ s32 unk100;
    /* 0x104 */ KDUniformSpline unk104;
    /* 0x118 */ u8 pad118[0xa0];
    /* 0x1b8 */ f64 unk1B8;
    /* 0x1c0 */ f64 unk1C0;
    /* 0x1c8 */ f64 unk1C8;
    /* 0x1d0 */ f64 unk1D0;
    /* 0x1d8 */ f32 unk1D8;
    /* 0x1dc */ s32 unk1DC;
    /* 0x1e0 */ s32 unk1E0;
    /* 0x1e4 */ u8 unk1E4;
    /* 0x1e5 */ u8 unk1E5;
    /* 0x1e6 */ u8 pad1E6[0x2];
    /* 0x1e8 */ void* unk1E8;
    /* 0x1ec */ s32 unk1EC;
    /* 0x1f0 */ u8 unk1F0;
    /* 0x1f1 */ u8 unk1F1;
    /* 0x1f2 */ u8 unk1F2;
    /* 0x1f3 */ u8 pad1F3[0x1];
    /* 0x1f4 */ SparxPath* unk1F4;
    /* 0x1f8 */ f32 unk1F8;
    /* 0x1fc */ u8 unk1FC;
    /* 0x1fd */ u8 unk1FD;
    /* 0x1fe */ u8 pad1FE[0x2];
    /* 0x200 */ f32 unk200;
    /* 0x204 */ u8 pad204[0x4];
    /* 0x208 */ f64 unk208;
    /* 0x210 */ f32 unk210;
    /* 0x214 */ u8 pad214[0x4];
    /* 0x218 */ s8 unk218;
    /* 0x219 */ u8 pad219[0x7];
    /* 0x220 */ MKCollisionResult unk220;
    /* 0x274 */ u8 pad274[0x4];
    /* 0x278 */ MKVector3 unk278;
    /* 0x288 */ f32 unk288;
    /* 0x28c */ f32 unk28C;
    /* 0x290 */ void* unk290;
    /* 0x294 */ u8 pad294[0x4];
    /* 0x298 */ MKVector3 unk298;
    /* 0x2a8 */ s32 unk2A8;
    /* 0x2ac */ f32 unk2AC;
    /* 0x2b0 */ f64 unk2B0;
    /* 0x2b8 */ f64 unk2B8;
    /* 0x2c0 */ f64 unk2C0;
    /* 0x2c8 */ f64 unk2C8;
    /* 0x2d0 */ f32 unk2D0;
};

class SparxDescriptor : public MKPropDescriptor {  // base: inlined ctor vtable stores
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    /* 0x044 */ u8 pad44[0x1c];
    /* 0x060 */ f64 unk60;
    /* 0x068 */ f64 unk68;
    /* 0x070 */ f64 unk70;
    /* 0x078 */ f64 unk78;
    /* 0x080 */ f32 unk80;
    /* 0x084 */ f32 unk84;
    /* 0x088 */ f32 unk88;
    /* 0x08c */ f32 unk8C;
    /* 0x090 */ f32 unk90;
    /* 0x094 */ f32 unk94;
    /* 0x098 */ f32 unk98;
    /* 0x09c */ f32 unk9C;
    /* 0x0a0 */ f32 unkA0;
    /* 0x0a4 */ s32 unkA4;
    /* 0x0a8 */ f32 unkA8;
    /* 0x0ac */ f32 unkAC;
    /* 0x0b0 */ f32 unkB0;
    /* 0x0b4 */ f32 unkB4;
    /* 0x0b8 */ s32 unkB8;
    /* 0x0bc */ f32 unkBC;
};

class SparxHintMsg {
public:
    /* 0x000 */ u8 pad0[0x8];
    /* 0x008 */ s32 unk8;
    /* 0x00c */ u8 unkC;
    /* 0x00d */ u8 unkD;
    /* 0x00e */ u8 unkE;
    /* 0x00f */ u8 padF[0x1];
    /* 0x010 */ s32 unk10;
    /* 0x014 */ void* unk14;
};

class Sparx_cpp {
public:
    void __sinit(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline Sparx::~Sparx() {
    s32 temp_cr0_eq_15;

    temp_cr0_eq_15 = this == NULL;
    if (temp_cr0_eq_15 == 0) {
        if (temp_cr0_eq_15 == 0) {
        }
    }
}

#endif  // SPYRO_SOURCE_SPARX_H
