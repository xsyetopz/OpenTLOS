#ifndef SPYRO_SOURCE_ENEMIES_CYNDER_H
#define SPYRO_SOURCE_ENEMIES_CYNDER_H

#include <dolphin/types.h>
#include "spyro/source/Enemy.h"
#include "spyro/source/EnemyDescriptor.h"

class CynderTier1;
class CynderTier1Descriptor;
class CynderTier2;
class CynderTier2Descriptor;
class CynderTier2Train;
class CynderTier2TrainDescriptor;
class CynderTier3;
class CynderTier3Descriptor;
class Enemies_Cynder_cpp;
class Enemy;
class EnemyDescriptor;
class EnemyGeneratorDoor;
class EnemyTest;
class EnemyTestDescriptor;
class MKIniLine;
class MKMessage;
class SpawnPointObject;

class CynderTier1 : public Enemy {  // base: vtable prefix
public:
    virtual ~CynderTier1(void);
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Update(void);
    virtual void Message(MKMessage *);
    virtual void CheckAnimEvents(void);
    virtual s32 Spawn(SpawnPointObject *);
    virtual void Spawn(EnemyGeneratorDoor *);
    virtual s32 TryFreezeBall(void);
    virtual void UpdateFrozenBallMovement(void);
    virtual void DefrostBall(void);
    virtual s32 IsInFrozenBall(void);
    CynderTier1(void);
};

class CynderTier1Descriptor : public EnemyDescriptor {  // base: ctor/dtor vtable stores
public:
    virtual void LoadDone(void);
    virtual void Deinit(void);
    CynderTier1Descriptor(void);
    /* 0x2b4 */ s32 unk2B4;
    /* 0x2b8 */ s32 unk2B8;
};

class CynderTier2 : public Enemy {  // base: vtable prefix
public:
    virtual ~CynderTier2(void);
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Update(void);
    virtual void Spawn(EnemyGeneratorDoor *);
    CynderTier2(void);
};

class CynderTier2Descriptor : public EnemyDescriptor {  // base: ctor/dtor vtable stores
public:
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    CynderTier2Descriptor(void);
    /* 0x2b4 */ s8 unk2B4;
};

class CynderTier2Train : public Enemy {  // base: vtable prefix
public:
    virtual ~CynderTier2Train(void);
    virtual void Init(void);
    virtual void UpdateMovementCustom(void);
    CynderTier2Train(void);
};

class CynderTier2TrainDescriptor : public CynderTier2Descriptor {  // base: vtable prefix
public:
    virtual void Init(void);
    CynderTier2TrainDescriptor(void);
};

class CynderTier3 : public Enemy {  // base: vtable prefix
public:
    virtual ~CynderTier3(void);
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Update(void);
    virtual void Message(MKMessage *);
    virtual void Spawn(EnemyGeneratorDoor *);
    CynderTier3(void);
    void EmitClubEffects(void);
};

class CynderTier3Descriptor : public EnemyDescriptor {  // base: ctor/dtor vtable stores
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    CynderTier3Descriptor(void);
    /* 0x2b4 */ s32 unk2B4;
    /* 0x2b8 */ s32 unk2B8;
};

class Enemies_Cynder_cpp {
public:
    void __sinit(void);
};

class EnemyTest : public Enemy {  // base: vtable prefix
public:
    virtual ~EnemyTest(void);
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    EnemyTest(void);
};

class EnemyTestDescriptor : public EnemyDescriptor {  // base: ctor/dtor vtable stores
public:
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    EnemyTestDescriptor(void);
};

#endif  // SPYRO_SOURCE_ENEMIES_CYNDER_H
