#ifndef SPYRO_SOURCE_ICESHARD_H
#define SPYRO_SOURCE_ICESHARD_H

#include <dolphin/types.h>
#include "spyro/source/Projectile.h"

class IceShard;
class IceShardDescriptor;
class MKCollisionResult;
class Projectile;
class ProjectileDescriptor;

class IceShard : public Projectile {  // base: base ctor call
public:
    virtual ~IceShard(void);
    virtual s32 LoadDone(void);
    virtual void * Update(void);
    virtual void Collided(MKCollisionResult &);
    IceShard(void);
    void * CreateInstance(void);
};

class IceShardDescriptor : public ProjectileDescriptor {  // base: base ctor call
public:
    virtual void LoadDone(void);
    virtual void Deinit(void);
    IceShardDescriptor(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline IceShard::IceShard() {
}

inline IceShard::~IceShard() {
}

inline IceShardDescriptor::IceShardDescriptor() {
}

#endif  // SPYRO_SOURCE_ICESHARD_H
