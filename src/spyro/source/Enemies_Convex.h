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

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#include <m2c_macros.h>

#if 0 // DRAFT: undefined identifier '__vt'
inline ConvexTier2::ConvexTier2() {
    M2C_FIELD(this, void **, 0x6B8) = (void *) (&__vt + 0x84);
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier '__vt'
inline ConvexTier2::~ConvexTier2() {
    M2C_FIELD(this, s32 **, 0x6B8) = &__vt.unk84;
}
#endif

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline ConvexTier2Descriptor::ConvexTier2Descriptor() {
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier '__vt'
inline ConvexTier3::ConvexTier3() {
    M2C_FIELD(this, void **, 0x6B8) = (void *) (&__vt + 0x84);
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier '__vt'
inline ConvexTier3::~ConvexTier3() {
    M2C_FIELD(this, s32 **, 0x6B8) = &__vt.unk84;
}
#endif

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline ConvexTier3Descriptor::ConvexTier3Descriptor() {
    return this;
}
#endif

#endif  // SPYRO_SOURCE_ENEMIES_CONVEX_H
