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

#endif  // SPYRO_SOURCE_ICESHARD_H
