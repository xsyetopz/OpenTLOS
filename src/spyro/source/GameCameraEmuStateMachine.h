#ifndef SPYRO_SOURCE_GAMECAMERAEMUSTATEMACHINE_H
#define SPYRO_SOURCE_GAMECAMERAEMUSTATEMACHINE_H

#include <dolphin/types.h>

class GameCamera2;
class GameCameraEmuStateDescriptor;
class GameCameraEmuStateMachine;

class GameCameraEmuStateDescriptor {
public:
    /* 0x000 */ u8 pad0[0x4];
    /* 0x004 */ s32 unk4;
    /* 0x008 */ s32 unk8;
    /* 0x00c */ s32 unkC;
};

class GameCameraEmuStateMachine {
public:
    void SetDisabledStates(void);
    u8 IsStateActive(GameCameraEmuStateDescriptor *, bool);
    void DeactivateState(GameCameraEmuStateDescriptor *, GameCamera2 *);
    s32 IsEmuStateMessage(int);
    s32 HandleGameCameraMessage(GameCamera2 *, int);
    void UpdateStates(GameCamera2 *);
    void ClearData(GameCamera2 *);
    void Init(GameCamera2 *, GameCameraEmuStateDescriptor *);
    /* 0x000 */ s32 unk0;
    /* 0x004 */ s32 unk4;
    /* 0x008 */ GameCameraEmuStateDescriptor* unk8;
    /* 0x00c */ s32 unkC;
};

#endif  // SPYRO_SOURCE_GAMECAMERAEMUSTATEMACHINE_H
