#ifndef SPYRO_SOURCE_STEAMFIREBALL_H
#define SPYRO_SOURCE_STEAMFIREBALL_H

#include <dolphin/types.h>
#include "spyro/source/Projectile.h"
#include "spyro/source/Shadow.h"

class MKCollisionResult;
class MKModel;
class MKProp;
class MKVector3;
class Projectile;
class ProjectileDescriptor;
class Shadow;
class SteamFireBall;
class SteamFireBallDescriptor;

class SteamFireBall : public Projectile {  // base: vtable prefix
public:
    virtual ~SteamFireBall(void);
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Update(void);
    virtual void FireAtTarget(const MKVector3 &, const MKVector3 &, float, MKProp *, int, int);
    virtual void Collided(MKCollisionResult &);
    SteamFireBall(void);
    void * CreateInstance(void);
    /* 0x150 */ Shadow unk150;
    /* 0x180 */ MKModel* unk180;
    /* 0x184 */ f32 unk184;
    /* 0x188 */ f32 unk188;
};

class SteamFireBallDescriptor : public ProjectileDescriptor {  // base: vtable prefix
public:
    virtual void LoadDone(void);
    virtual void Deinit(void);
    SteamFireBallDescriptor(void);
    /* 0x0f0 */ s32 unkF0;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline SteamFireBall::SteamFireBall() {
    return this;
}
#endif

inline SteamFireBall::~SteamFireBall() {
}

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline SteamFireBallDescriptor::SteamFireBallDescriptor() {
    return this;
}
#endif

#endif  // SPYRO_SOURCE_STEAMFIREBALL_H
