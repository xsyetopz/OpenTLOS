#ifndef SPYRO_SOURCE_ICESHARD_H
#define SPYRO_SOURCE_ICESHARD_H

#include <dolphin/types.h>
#include "spyro/source/Projectile.h"

class IceShard;
class IceShardDescriptor;
class MKCollisionResult;
class Projectile;
class ProjectileDescriptor;

class IceShard : public Projectile {  // base: vtable prefix
public:
    virtual ~IceShard(void);
    virtual void LoadDone(void);
    virtual void Update(void);
    virtual void Collided(MKCollisionResult &);
    IceShard(void);
    void * CreateInstance(void);
};

class IceShardDescriptor : public ProjectileDescriptor {  // base: vtable prefix
public:
    virtual void LoadDone(void);
    virtual void Deinit(void);
    IceShardDescriptor(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline IceShard::IceShard() {
    return this;
}
#endif

inline IceShard::~IceShard() {
}

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline IceShardDescriptor::IceShardDescriptor() {
    return this;
}
#endif

#endif  // SPYRO_SOURCE_ICESHARD_H
