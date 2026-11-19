#ifndef SPYRO_SOURCE_MININGMOLE_H
#define SPYRO_SOURCE_MININGMOLE_H

#include <dolphin/types.h>
#include "spyro/source/Enemy.h"

class Enemy;
class Exhumor;
class MKMessage;
class Matrix;
class MiningMole;
class MiningMoleLeader;
class SpawnPointRef;

class Exhumor : public Enemy {  // base: vtable prefix
public:
    virtual ~Exhumor(void);
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Update(void);
    virtual void Message(MKMessage *);
    Exhumor(void);
};

class MiningMole : public Enemy {  // base: vtable prefix
public:
    virtual ~MiningMole(void);
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Message(MKMessage *);
    virtual void Despawn(bool);
    virtual s32 Spawn(const Matrix *, SpawnPointRef *);
    MiningMole(void);
};

class MiningMoleLeader : public Enemy {  // base: vtable prefix
public:
    virtual ~MiningMoleLeader(void);
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Update(void);
    virtual void Message(MKMessage *);
    MiningMoleLeader(void);
};

#endif  // SPYRO_SOURCE_MININGMOLE_H
