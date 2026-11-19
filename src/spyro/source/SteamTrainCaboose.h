#ifndef SPYRO_SOURCE_STEAMTRAINCABOOSE_H
#define SPYRO_SOURCE_STEAMTRAINCABOOSE_H

#include <dolphin/types.h>
#include "spyro/source/EventMessage.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/SpawnerObject.h"

class Enemy;
class EventMessage;
class GameProp;
class KDPropExDescriptor;
class MKIniLine;
class MKMessage;
class MKProp;
class MKSceneManager;
class Shadow;
class SpawnAction;
class SpawnerObject;
class SteamTrainCaboose;
class SteamTrainCabooseDescriptor;
class SteamTrainCabooseState;
class TrainChaseSpawnPool;

class SteamTrainCaboose : public GameProp {  // base: vtable prefix
public:
    virtual ~SteamTrainCaboose(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Reset(void);
    virtual void Update(void);
    virtual void Message(MKMessage *);
    virtual void Enable(void);
    virtual void Disable(void);
    SteamTrainCaboose(void);
    void GetVel(void);
    void SetState(SteamTrainCabooseState);
    u8 IsBlownUp(void);
    void BlowUp(void);
    /* 0x0c4 */ u8 padC4[0x4];
    /* 0x0c8 */ s32 unkC8;
    /* 0x0cc */ MKSceneManager* unkCC;
    /* 0x0d0 */ MKSceneManager* unkD0;
    /* 0x0d4 */ f32 unkD4;
    /* 0x0d8 */ u8 unkD8;
    /* 0x0d9 */ u8 padD9[0x3];
    /* 0x0dc */ f32 unkDC;
    /* 0x0e0 */ Shadow unkE0;
    /* 0x10d */ u8 pad10D[0x3];
    /* 0x110 */ SpawnerObject unk110;
    /* 0x15d */ u8 pad15D[0x3];
    /* 0x160 */ TrainChaseSpawnPool* unk160;
};

class SteamTrainCabooseDescriptor : public KDPropExDescriptor {  // base: vtable prefix
public:
    virtual void LoadDone(void);
    SteamTrainCabooseDescriptor(void);
    /* 0x0c0 */ u8 padC0[0x24];
    /* 0x0e4 */ s32 unkE4;
    /* 0x0e8 */ s32 unkE8;
    /* 0x0ec */ s32 unkEC;
    /* 0x0f0 */ s32 unkF0;
    /* 0x0f4 */ s32 unkF4;
};

class TrainChaseSpawnPool {
public:
    void Destroy(Enemy *);
    Enemy * Create(void);
    void Action(SpawnAction, int, MKProp **, SpawnerObject *);
    void Deinit(void);
    void Init(void);
    static u8 pInstance[0x4];
    /* 0x000 */ u8 pad0[0x8];
    /* 0x008 */ EventMessage unk8;
    /* 0x00c */ EventMessage unkC;
    /* 0x010 */ EventMessage unk10;
    /* 0x014 */ EventMessage unk14;
};

#endif  // SPYRO_SOURCE_STEAMTRAINCABOOSE_H
