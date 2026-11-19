#ifndef SPYRO_SOURCE_SLUDGE_H
#define SPYRO_SOURCE_SLUDGE_H

#include <dolphin/types.h>
#include "spyro/source/Projectile.h"

class MKCollisionResult;
class Projectile;
class ProjectileDescriptor;
class Sludge;
class SludgeDescriptor;

class Sludge : public Projectile {  // base: base ctor call
public:
    virtual ~Sludge(void);
    virtual s32 LoadDone(void);
    virtual void * Update(void);
    virtual void Collided(MKCollisionResult &);
    Sludge(void);
    static void * CreateInstance(void);
    /* 0x150 */ f32 unk150;
    /* 0x154 */ f32 unk154;
    /* 0x158 */ f32 unk158;
};

class SludgeDescriptor : public ProjectileDescriptor {  // base: base ctor call
public:
    virtual void LoadDone(void);
    virtual void Deinit(void);
    SludgeDescriptor(void);
    /* 0x0f0 */ s32 unkF0;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline Sludge::Sludge() {
}

inline Sludge::~Sludge() {
}

inline SludgeDescriptor::SludgeDescriptor() {
}

#endif  // SPYRO_SOURCE_SLUDGE_H
