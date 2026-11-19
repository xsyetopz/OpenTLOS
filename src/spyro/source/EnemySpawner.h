#ifndef SPYRO_SOURCE_ENEMYSPAWNER_H
#define SPYRO_SOURCE_ENEMYSPAWNER_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"
#include "common/Source/Matrix.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/SpawnPointData.h"
#include "spyro/source/SpawnPointObject.h"

class EnemySpawnPointData;
class EnemySpawner;
class EnemySpawnerDescriptor;
class EventMessage;
class KDPathSegment;
class KDSplinePathSegment;
class MKIniLine;
class MKMessage;
class MKProp;
class MKPropDescriptor;
class MKSceneManager;
class Matrix;
class SpawnPoint;
class SpawnPointData;
class SpawnPointObject;

class EnemySpawnPointData : public SpawnPointData {  // base: ctor/dtor vtable stores
public:
    virtual ~EnemySpawnPointData(void);
    virtual void Init(void);
    virtual void Deinit(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Resolve(void);
    /* 0x004 */ s32 unk4;
    /* 0x008 */ EventMessage unk8;
    /* 0x00c */ EventMessage unkC;
    /* 0x010 */ EventMessage unk10;
    /* 0x014 */ EventMessage unk14;
    /* 0x018 */ KDSplinePathSegment* unk18;
    /* 0x01c */ KDPathSegment* unk1C;
    /* 0x020 */ MKSceneManager* unk20;
    /* 0x024 */ MKSceneManager* unk24;
};

class EnemySpawner : public MKProp {  // base: ctor/dtor vtable stores
public:
    virtual ~EnemySpawner(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Reset(void);
    virtual void Update(void);
    virtual void Message(MKMessage *);
    /* 0x04c */ u8 pad4C[0x4];
    /* 0x050 */ Matrix unk50;
    /* 0x0dc */ u8 padDC[0x4];
    /* 0x0e0 */ s32 unkE0;
    /* 0x0e4 */ u32 unkE4;
};

class EnemySpawnerDescriptor : public MKPropDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    /* 0x048 */ u8 pad48[0x1c];
    /* 0x064 */ f32 unk64;
    /* 0x068 */ f32 unk68;
    /* 0x06c */ u8 pad6C[0x4];
    /* 0x070 */ f32 unk70;
    /* 0x074 */ f32 unk74;
    /* 0x078 */ f32 unk78;
};

class SpawnPoint : public MKProp {  // base: ctor/dtor vtable stores
public:
    virtual ~SpawnPoint(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Message(MKMessage *);
    /* 0x04c */ u8 pad4C[0x4];
    /* 0x050 */ SpawnPointObject unk50;
};

#endif  // SPYRO_SOURCE_ENEMYSPAWNER_H
