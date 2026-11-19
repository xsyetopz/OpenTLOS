#ifndef SPYRO_SOURCE_ENEMIES_CONVEX_H
#define SPYRO_SOURCE_ENEMIES_CONVEX_H

#include <dolphin/types.h>
#include "spyro/source/Enemy.h"
#include "spyro/source/EnemyDescriptor.h"

class ConvexTier2;
class ConvexTier2Descriptor;
class ConvexTier3;
class ConvexTier3Descriptor;
class Enemy;
class EnemyDescriptor;
class MKMessage;
class Matrix;
class SpawnPointRef;

class ConvexTier2 : public Enemy {  // base: vtable prefix
public:
    virtual ~ConvexTier2(void);
    virtual void Init(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Update(void);
    virtual void Message(MKMessage *);
    virtual void Despawn(bool);
    virtual void UpdateMovementCustom(void);
    virtual void SetupCollision(void);
    virtual void UpdateCollisionItems(void);
    virtual s32 Spawn(const Matrix *, SpawnPointRef *);
    ConvexTier2(void);
};

class ConvexTier2Descriptor : public EnemyDescriptor {  // base: ctor/dtor vtable stores
public:
    virtual void Init(void);
    virtual void Deinit(void);
    ConvexTier2Descriptor(void);
};

class ConvexTier3 : public Enemy {  // base: vtable prefix
public:
    virtual ~ConvexTier3(void);
    virtual void Init(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Update(void);
    virtual void Message(MKMessage *);
    virtual void Despawn(bool);
    virtual void UpdateMovementCustom(void);
    virtual void SetupCollision(void);
    virtual void UpdateCollisionItems(void);
    virtual s32 Spawn(const Matrix *, SpawnPointRef *);
    ConvexTier3(void);
};

class ConvexTier3Descriptor : public EnemyDescriptor {  // base: ctor/dtor vtable stores
public:
    virtual void Init(void);
    virtual void Deinit(void);
    ConvexTier3Descriptor(void);
};

#endif  // SPYRO_SOURCE_ENEMIES_CONVEX_H
