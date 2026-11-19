#ifndef SPYRO_SOURCE_GAMESTATEMACHINE_H
#define SPYRO_SOURCE_GAMESTATEMACHINE_H

#include <dolphin/types.h>

class GameStateHeap;
class GameStateMachine;
class GameStateMachineInit;
class GameStateMachineState;

class GameStateHeap {
public:
    void HeapMarkPopAll(void);
    void HeapMarkPop(void);
    void HeapMarkPush(void);
    void Init(void);
    /* 0x000 */ s32 unk0;
};

class GameStateMachine {
public:
    u8 GetFadeColor(void);
    s32 StateIsValid(void);
    void * GetCurrState(void);
    void * GetLastState(void);
    void Draw(void);
    void Update(void);
    void SwitchIn(void);
    void SwitchOut(void);
    void SwitchState(int, int, unsigned int);
    void Deinit(void);
    void Init(GameStateMachineState *, GameStateMachineInit *);
    /* 0x000 */ s32 unk0;
    /* 0x004 */ s32 unk4;
    /* 0x008 */ s32 unk8;
    /* 0x00c */ s32 unkC;
    /* 0x010 */ s32 unk10;
    /* 0x014 */ f32 unk14;
    /* 0x018 */ GameStateMachineState* unk18;
    /* 0x01c */ void* unk1C;
    /* 0x020 */ s32 unk20;
    /* 0x024 */ f32 unk24;
    /* 0x028 */ s32 unk28;
    /* 0x02c */ s32 unk2C;
    /* 0x030 */ s32 unk30;
    /* 0x034 */ GameStateMachineInit* unk34;
    /* 0x038 */ GameStateHeap unk38;
};

class GameStateMachineInit {
public:
    /* 0x000 */ s32 unk0;
    /* 0x004 */ f32 unk4;
    /* 0x008 */ f32 unk8;
    /* 0x00c */ s32 unkC;
};

class GameStateMachineState {
public:
    /* 0x000 */ s32 unk0;
};

#endif  // SPYRO_SOURCE_GAMESTATEMACHINE_H
