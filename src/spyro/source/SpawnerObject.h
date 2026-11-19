#ifndef SPYRO_SOURCE_SPAWNEROBJECT_H
#define SPYRO_SOURCE_SPAWNEROBJECT_H

#include <dolphin/types.h>
#include "spyro/source/EventMessage.h"
#include "unplaced_enums.h"

class EventMessage;
class MKIniLine;
class MKMessage;
class MKProp;
class SpawnItemObject;
class SpawnPointObject;
class SpawnerObject;

class SpawnItemObject {
public:
    void SetDefaults(void);
    /* 0x000 */ MKProp* unk0;
    /* 0x004 */ void* unk4;
    /* 0x008 */ s32 unk8;
};

class SpawnerObject {
public:
    virtual s32 LoadLine(MKIniLine *);
    virtual void UpdateUsedSpawnPointMask(void);
    virtual SpawnPointObject * GetSpawnPointObject(void);
    void AllDied(void);
    void AllChildrenDied(SpawnerObject *);
    void RemoveChildSpawner(SpawnerObject *);
    void AddChildSpawner(SpawnerObject *);
    void SetParentSpawner(SpawnerObject *);
    SpawnPointObject * GetSpawnPoint(int);
    s32 IsDying(void);
    s32 IsSpawning(void);
    MKProp * GetActive(int);
    void GetNumberActive(void);
    void * Spawn(MKProp *);
    void FreeSpawnItemObject(SpawnItemObject *);
    MKProp ** GetSpawnItemObject(void);
    void ItemWasRecycled(MKProp *);
    void KillAll(void);
    void DespawnAll(void);
    void DespawnItem(SpawnItemObject *, bool);
    void SendMessageToActive(MKMessage *);
    void DespawnItem(MKProp *, bool);
    MKProp * TrySpawnItem(int);
    void TrySpawnItems(int, bool);
    void FunctionOff(void);
    void FunctionOn(void);
    void SetDefaults(void);
    void RemoveItem(MKProp *);
    void RemoveAllSpawnPoints(bool);
    void RemoveSpawnPoint(SpawnPointObject *);
    void AddSpawnPointEnd(void);
    void AddSpawnPoint(SpawnPointObject *);
    void AddSpawnPointBegin(int);
    void Deinit(void);
    void LoadDone(unsigned int);
    void LoadDone(int, int, bool, unsigned int);
    void Init(void (*)(SpawnAction, int, MKProp **, SpawnerObject *), int);
    /* 0x004 */ SpawnerObject* unk4;
    /* 0x008 */ EventMessage unk8;
    /* 0x00c */ EventMessage unkC;
    /* 0x010 */ EventMessage unk10;
    /* 0x014 */ EventMessage unk14;
    /* 0x018 */ s32 unk18;
    /* 0x01c */ s32 unk1C;
    /* 0x020 */ s32 unk20;
    /* 0x024 */ s32 unk24;
    /* 0x028 */ s32 unk28;
    /* 0x02c */ s32 unk2C;
    /* 0x030 */ f32 unk30;
    /* 0x034 */ f32 unk34;
    /* 0x038 */ f32 unk38;
    /* 0x03c */ EventMessage unk3C;
    /* 0x040 */ EventMessage unk40;
    /* 0x044 */ u32* unk44;
    /* 0x048 */ MKProp*** unk48;
    /* 0x04c */ u8 unk4C;
};

#endif  // SPYRO_SOURCE_SPAWNEROBJECT_H
