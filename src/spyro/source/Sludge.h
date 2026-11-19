#ifndef SPYRO_SOURCE_SLUDGE_H
#define SPYRO_SOURCE_SLUDGE_H

#include <dolphin/types.h>
#include "spyro/source/Projectile.h"

class MKCollisionResult;
class Projectile;
class ProjectileDescriptor;
class Sludge;
class SludgeDescriptor;

class Sludge : public Projectile {  // base: vtable prefix
public:
    virtual ~Sludge(void);
    virtual void LoadDone(void);
    virtual void Update(void);
    virtual void Collided(MKCollisionResult &);
    Sludge(void);
    void * CreateInstance(void);
    /* 0x14d */ u8 pad14D[0x3];
    /* 0x150 */ f32 unk150;
    /* 0x154 */ f32 unk154;
    /* 0x158 */ f32 unk158;
};

class SludgeDescriptor : public ProjectileDescriptor {  // base: vtable prefix
public:
    virtual void LoadDone(void);
    virtual void Deinit(void);
    SludgeDescriptor(void);
    /* 0x0f0 */ s32 unkF0;
};

#endif  // SPYRO_SOURCE_SLUDGE_H
