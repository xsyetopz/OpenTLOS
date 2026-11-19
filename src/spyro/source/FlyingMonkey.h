#ifndef SPYRO_SOURCE_FLYINGMONKEY_H
#define SPYRO_SOURCE_FLYINGMONKEY_H

#include <dolphin/types.h>
#include "spyro/source/Projectile.h"

class FlyingMonkey;
class FlyingMonkeyDescriptor;
class MKCollisionResult;
class MKProp;
class MKVector3;
class Projectile;
class ProjectileDescriptor;

class FlyingMonkey : public Projectile {  // base: vtable prefix
public:
    virtual ~FlyingMonkey(void);
    virtual void Update(void);
    virtual void Fire(const MKVector3 &, const MKVector3 &, MKProp *, int, int);
    virtual void FireAtTarget(const MKVector3 &, const MKVector3 &, float, MKProp *, int, int);
    virtual void Collided(MKCollisionResult &);
    FlyingMonkey(void);
    void * CreateInstance(void);
};

class FlyingMonkeyDescriptor : public ProjectileDescriptor {  // base: vtable prefix
public:
    virtual void LoadDone(void);
    virtual void Deinit(void);
    FlyingMonkeyDescriptor(void);
    /* 0x0f0 */ s32 unkF0;
    /* 0x0f4 */ s32 unkF4;
    /* 0x0f8 */ s32 unkF8;
    /* 0x0fc */ s32 unkFC;
    /* 0x100 */ s32 unk100;
    /* 0x104 */ s32 unk104;
    /* 0x108 */ s32 unk108;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline FlyingMonkey::FlyingMonkey() {
    return this;
}
#endif

inline FlyingMonkey::~FlyingMonkey() {
}

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline FlyingMonkeyDescriptor::FlyingMonkeyDescriptor() {
    return this;
}
#endif

#endif  // SPYRO_SOURCE_FLYINGMONKEY_H
