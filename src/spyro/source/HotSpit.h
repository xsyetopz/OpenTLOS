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

class HotSpit : public Projectile {  // base: base ctor call
public:
    virtual ~HotSpit(void);
    virtual s32 LoadDone(void);
    virtual void * Update(void);
    virtual void Fire(const MKVector3 &, const MKVector3 &, MKProp *, int, int);
    virtual void Collided(MKCollisionResult &);
    HotSpit(void);
    static void * CreateInstance(void);
    /* 0x150 */ f32 unk150;
    /* 0x154 */ f32 unk154;
    /* 0x158 */ f32 unk158;
};

class HotSpitDescriptor : public ProjectileDescriptor {  // base: base ctor call
public:
    virtual void LoadDone(void);
    virtual void Deinit(void);
    HotSpitDescriptor(void);
    /* 0x0f0 */ s32 unkF0;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline HotSpit::HotSpit() {
}

inline HotSpit::~HotSpit() {
}

inline HotSpitDescriptor::HotSpitDescriptor() {
}

#endif  // SPYRO_SOURCE_HOTSPIT_H
