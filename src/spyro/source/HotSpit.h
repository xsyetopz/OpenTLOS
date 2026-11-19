#ifndef SPYRO_SOURCE_HOTSPIT_H
#define SPYRO_SOURCE_HOTSPIT_H

#include <dolphin/types.h>
#include "spyro/source/Projectile.h"

class HotSpit;
class HotSpitDescriptor;
class MKCollisionResult;
class MKProp;
class MKVector3;
class Projectile;
class ProjectileDescriptor;

class HotSpit : public Projectile {  // base: vtable prefix
public:
    virtual ~HotSpit(void);
    virtual void LoadDone(void);
    virtual void Update(void);
    virtual void Fire(const MKVector3 &, const MKVector3 &, MKProp *, int, int);
    virtual void Collided(MKCollisionResult &);
    HotSpit(void);
    void * CreateInstance(void);
    /* 0x14d */ u8 pad14D[0x3];
    /* 0x150 */ f32 unk150;
    /* 0x154 */ f32 unk154;
    /* 0x158 */ f32 unk158;
};

class HotSpitDescriptor : public ProjectileDescriptor {  // base: vtable prefix
public:
    virtual void LoadDone(void);
    virtual void Deinit(void);
    HotSpitDescriptor(void);
    /* 0x0f0 */ s32 unkF0;
};

#endif  // SPYRO_SOURCE_HOTSPIT_H
