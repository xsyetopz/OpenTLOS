#ifndef SPYRO_SOURCE_SPEEDWAYAA_H
#define SPYRO_SOURCE_SPEEDWAYAA_H

#include <dolphin/types.h>
#include "spyro/source/Projectile.h"

class MKCollisionResult;
class MKProp;
class MKVector3;
class Projectile;
class ProjectileDescriptor;
class SpeedwayAA;
class SpeedwayAADescriptor;

class SpeedwayAA : public Projectile {  // base: vtable prefix
public:
    virtual ~SpeedwayAA(void);
    virtual void LoadDone(void);
    virtual void Update(void);
    virtual void Draw(void);
    virtual void Fire(const MKVector3 &, const MKVector3 &, MKProp *, int, int);
    virtual void FireAtTarget(const MKVector3 &, const MKVector3 &, float, MKProp *, int, int);
    virtual void Collided(MKCollisionResult &);
    SpeedwayAA(void);
    void * CreateInstance(void);
};

class SpeedwayAADescriptor : public ProjectileDescriptor {  // base: vtable prefix
public:
    virtual void LoadDone(void);
    virtual void Deinit(void);
    SpeedwayAADescriptor(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline SpeedwayAA::SpeedwayAA() {
    return this;
}
#endif

inline SpeedwayAA::~SpeedwayAA() {
}

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline SpeedwayAADescriptor::SpeedwayAADescriptor() {
    return this;
}
#endif

#endif  // SPYRO_SOURCE_SPEEDWAYAA_H
