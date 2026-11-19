#ifndef SPYRO_SOURCE_ELEVATOR_H
#define SPYRO_SOURCE_ELEVATOR_H

#include <dolphin/types.h>
#include "common/Source/Matrix.h"
#include "spyro/source/GameProp.h"

class Elevator;
class GameProp;
class MKIniLine;
class MKMessage;
class Matrix;

class Elevator : public GameProp {  // base: vtable prefix
public:
    virtual ~Elevator(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Reset(void);
    virtual void Message(MKMessage *);
    virtual void PropUpdate(void);
    Elevator(void);
    void Move(float);
    void WaitState(void);
    void ShudderState(void);
    void GoingDownState(void);
    void GoingUpState(void);
    /* 0x0c4 */ u8 padC4[0x4];
    /* 0x0c8 */ f64 unkC8;
    /* 0x0d0 */ f64 unkD0;
    /* 0x0d8 */ u8 padD8[0x8];
    /* 0x0e0 */ Matrix unkE0;
    /* 0x120 */ void** unk120;
    /* 0x124 */ s32 unk124;
    /* 0x128 */ f32 unk128;
    /* 0x12c */ f32 unk12C;
    /* 0x130 */ f32 unk130;
    /* 0x134 */ f32 unk134;
    /* 0x138 */ f32 unk138;
    /* 0x13c */ f32 unk13C;
    /* 0x140 */ f32 unk140;
    /* 0x144 */ f32 unk144;
    /* 0x148 */ f32 unk148;
    /* 0x14c */ f32 unk14C;
    /* 0x150 */ s32 unk150;
    /* 0x154 */ u8 unk154;
};

#endif  // SPYRO_SOURCE_ELEVATOR_H
