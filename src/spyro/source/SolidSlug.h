#ifndef SPYRO_SOURCE_SOLIDSLUG_H
#define SPYRO_SOURCE_SOLIDSLUG_H

#include <dolphin/types.h>
#include "spyro/source/Projectile.h"

class MKCollisionResult;
class MKIniLine;
class Projectile;
class ProjectileDescriptor;
class SolidSlug;
class SolidSlugDescriptor;

class SolidSlug : public Projectile {  // base: vtable prefix
public:
    virtual ~SolidSlug(void);
    virtual void LoadDone(void);
    virtual void Update(void);
    virtual void Collided(MKCollisionResult &);
    SolidSlug(void);
    void * CreateInstance(void);
};

class SolidSlugDescriptor : public ProjectileDescriptor {  // base: vtable prefix
public:
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    SolidSlugDescriptor(void);
    /* 0x0f0 */ s32 unkF0;
    /* 0x0f4 */ s32 unkF4;
};

#endif  // SPYRO_SOURCE_SOLIDSLUG_H
