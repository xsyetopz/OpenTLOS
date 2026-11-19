#ifndef SPYRO_SOURCE_GUARDIANCAGE_H
#define SPYRO_SOURCE_GUARDIANCAGE_H

#include <dolphin/types.h>
#include "spyro/source/EventMessage.h"
#include "spyro/source/GameProp.h"

class EventMessage;
class GameProp;
class Guardian;
class GuardianCage;
class GuardianCage_cpp;
class MKIniLine;
class MKMessage;

class GuardianCage : public GameProp {  // base: vtable prefix
public:
    virtual ~GuardianCage(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Reset(void);
    virtual void Update(void);
    virtual void Draw(void);
    virtual void Message(MKMessage *);
    GuardianCage(void);
    void StateDeadExit(void);
    void StateDeadUpdate(void);
    void StateDeadEnter(void);
    void StateDyingExit(void);
    void StateDyingUpdate(void);
    void StateDyingEnter(void);
    void StateFloatingExit(void);
    void StateFloatingUpdate(void);
    void StateFloatingEnter(void);
    void GetBeamPosition(int);
    static u8 states[0x90];
    /* 0x0c4 */ u8 padC4[0x4];
    /* 0x0c8 */ s32 unkC8;
    /* 0x0cc */ s32 unkCC;
    /* 0x0d0 */ s32 unkD0;
    /* 0x0d4 */ u8 padD4[0x4];
    /* 0x0d8 */ f64 unkD8;
    /* 0x0e0 */ f64 unkE0;
    /* 0x0e8 */ f32 unkE8;
    /* 0x0ec */ f32 unkEC;
    /* 0x0f0 */ f32 unkF0;
    /* 0x0f4 */ u8 padF4[0x4];
    /* 0x0f8 */ f64 unkF8;
    /* 0x100 */ f32 unk100;
    /* 0x104 */ u8 pad104[0x8];
    /* 0x10c */ f32 unk10C;
    /* 0x110 */ f64 unk110;
    /* 0x118 */ u8 pad118[0x4];
    /* 0x11c */ f32 unk11C;
    /* 0x120 */ f32 unk120;
    /* 0x124 */ u8 pad124[0x4];
    /* 0x128 */ f64 unk128;
    /* 0x130 */ f32 unk130;
    /* 0x134 */ u8 pad134[0x4];
    /* 0x138 */ s32 unk138;
    /* 0x13c */ s32 unk13C;
    /* 0x140 */ s32 unk140;
    /* 0x144 */ Guardian* unk144;
    /* 0x148 */ EventMessage unk148;
    /* 0x14c */ s32 unk14C;
};

class GuardianCage_cpp {
public:
    void __sinit(void);
};

#endif  // SPYRO_SOURCE_GUARDIANCAGE_H
