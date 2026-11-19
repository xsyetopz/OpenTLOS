#ifndef SPYRO_SOURCE_ENEMYGENERATOR_H
#define SPYRO_SOURCE_ENEMYGENERATOR_H

#include <dolphin/types.h>
#include "spyro/source/EventMessage.h"
#include "spyro/source/SpawnerObject.h"

class EnemyGenerator;
class EnemyGeneratorDescriptor;
class EnemyGeneratorDoor;
class EnemyGeneratorDoorData;
class EventMessage;
class MKIniLine;
class MKMessage;
class MKProp;
class SpawnPointObject;
class SpawnerObject;

class EnemyGenerator : public SpawnerObject {  // base: ctor/dtor vtable stores
public:
    virtual s32 LoadLine(MKIniLine *);
    virtual void UpdateUsedSpawnPointMask(void);
    virtual SpawnPointObject * GetSpawnPointObject(void);
    u8 HasEnemyWaveFinished(void);
    void StartEnemyWave(void);
    void DespawnAll(void);
    void * GetDoor(SpawnPointObject *);
    void Message(MKMessage *);
    void Update(void);
    void SetDefaults(void);
    void Resolve(void);
    void LoadDone(void);
    void Deinit(void);
    void Init(EnemyGeneratorDescriptor *, MKProp *);
    /* 0x004 */ u8 pad4[0x18];
    /* 0x01c */ s32 unk1C;
    /* 0x020 */ s32 unk20;
    /* 0x024 */ s32 unk24;
    /* 0x028 */ s32 unk28;
    /* 0x02c */ u8 pad2C[0x4];
    /* 0x030 */ f32 unk30;
    /* 0x034 */ f32 unk34;
    /* 0x038 */ u8 pad38[0xc];
    /* 0x044 */ SpawnPointObject** unk44;
    /* 0x048 */ u8 pad48[0x4];
    /* 0x04c */ u8 unk4C;
    /* 0x04d */ u8 pad4D[0x3];
    /* 0x050 */ EnemyGeneratorDescriptor* unk50;
    /* 0x054 */ void* unk54;
    /* 0x058 */ void* unk58;
    /* 0x05c */ void* unk5C;
    /* 0x060 */ MKProp* unk60;
    /* 0x064 */ u8 pad64[0x4];
    /* 0x068 */ EventMessage unk68;
    /* 0x06c */ EventMessage unk6C;
    /* 0x070 */ s32 unk70;
    /* 0x074 */ s32 unk74;
    /* 0x078 */ s32 unk78;
    /* 0x07c */ s32 unk7C;
    /* 0x080 */ s32 unk80;
    /* 0x084 */ u8 unk84;
    /* 0x085 */ u8 unk85;
};

class EnemyGeneratorDescriptor {
public:
    void LoadDone(void);
    s32 LoadLine(MKIniLine *);
    void Deinit(void);
    void Init(void);
    /* 0x000 */ s32 unk0;
    /* 0x004 */ s32 unk4;
    /* 0x008 */ s32 unk8;
    /* 0x00c */ s32 unkC;
    /* 0x010 */ void* unk10;
    /* 0x014 */ void* unk14;
    /* 0x018 */ u8 unk18;
    /* 0x019 */ u8 unk19;
};

class EnemyGeneratorDoor {
public:
    void GetSpawnPos(void);
    void GetDoorDir(void);
    void GetDoorPos(void);
    void Close(void);
    void Open(void);
    void Deinit(void);
    void Init(EnemyGenerator *, EnemyGeneratorDoorData *, MKProp *, SpawnPointObject *);
    /* 0x000 */ f64 unk0;
    /* 0x008 */ f64 unk8;
    /* 0x010 */ s32 unk10;
    /* 0x014 */ s32 unk14;
    /* 0x018 */ SpawnPointObject* unk18;
    /* 0x01c */ void** unk1C;
    /* 0x020 */ void** unk20;
    /* 0x024 */ void** unk24;
    /* 0x028 */ void** unk28;
    /* 0x02c */ u8 unk2C;
};

class EnemyGeneratorDoorData {
public:
    /* 0x000 */ u8 pad0[0x8];
    /* 0x008 */ s8* unk8;
    /* 0x00c */ s8* unkC;
    /* 0x010 */ s8* unk10;
    /* 0x014 */ s8* unk14;
    /* 0x018 */ s8* unk18;
    /* 0x01c */ s8* unk1C;
    /* 0x020 */ u8 unk20;
};

#endif  // SPYRO_SOURCE_ENEMYGENERATOR_H
