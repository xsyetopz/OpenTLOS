#ifndef SPYRO_SOURCE_LAVABALL_H
#define SPYRO_SOURCE_LAVABALL_H

#include <dolphin/types.h>
#include "spyro/source/Projectile.h"

class LavaBall;
class LavaBallDescriptor;
class MKCollisionResult;
class MKProp;
class MKVector3;
class Projectile;
class ProjectileDescriptor;
class ShapedTrailFX;

class LavaBall : public Projectile {  // base: vtable prefix
public:
    virtual ~LavaBall(void);
    virtual void LoadDone(void);
    virtual void Fire(const MKVector3 &, const MKVector3 &, MKProp *, int, int);
    virtual void FireAtTarget(const MKVector3 &, const MKVector3 &, float, MKProp *, int, int);
    virtual void Collided(MKCollisionResult &);
    LavaBall(void);
    void * CreateInstance(void);
    /* 0x14d */ u8 pad14D[0x3];
    /* 0x150 */ ShapedTrailFX* unk150;
};

class LavaBallDescriptor : public ProjectileDescriptor {  // base: vtable prefix
public:
    virtual void LoadDone(void);
    virtual void Deinit(void);
    LavaBallDescriptor(void);
    /* 0x0f0 */ s32 unkF0;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline LavaBall::LavaBall() {
    return this;
}
#endif

inline LavaBall::~LavaBall() {
}

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline LavaBallDescriptor::LavaBallDescriptor() {
    return this;
}
#endif

#endif  // SPYRO_SOURCE_LAVABALL_H
