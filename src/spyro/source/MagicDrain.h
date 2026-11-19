#ifndef SPYRO_SOURCE_MAGICDRAIN_H
#define SPYRO_SOURCE_MAGICDRAIN_H

#include <dolphin/types.h>
#include "spyro/source/GameMessages.h"
#include "spyro/source/Projectile.h"

class BreathHitMessage;
class MKCollisionResult;
class MKProp;
class MKVector3;
class MagicDrain;
class MagicDrainDescriptor;
class ManagedLight;
class Projectile;
class ProjectileDescriptor;

class MagicDrain : public Projectile {  // base: vtable prefix
public:
    virtual ~MagicDrain(void);
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Reset(void);
    virtual void Update(void);
    virtual void Draw(void);
    virtual void Fire(const MKVector3 &, const MKVector3 &, MKProp *, int, int);
    virtual void FireBurst(MKVector3 *, MKVector3 *, int, int);
    virtual void FireBurstEnd(void);
    virtual s32 IsBurst(void);
    virtual void Collided(MKCollisionResult &);
    MagicDrain(void);
    void SetDefaults(void);
    void * CreateInstance(void);
    /* 0x14d */ u8 pad14D[0x3];
    /* 0x150 */ MKVector3* unk150;
    /* 0x154 */ MKVector3* unk154;
    /* 0x158 */ u8 unk158;
    /* 0x159 */ u8 pad159[0x3];
    /* 0x15c */ ManagedLight* unk15C;
    /* 0x160 */ BreathHitMessage unk160;
    /* 0x1b1 */ u8 pad1B1[0x7];
    /* 0x1b8 */ f32 unk1B8;
};

class MagicDrainDescriptor : public ProjectileDescriptor {  // base: vtable prefix
public:
    virtual void LoadDone(void);
    virtual void Deinit(void);
    MagicDrainDescriptor(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline MagicDrain::MagicDrain() {
    this->unk160.unk4 = 0;
    return this;
}
#endif

inline MagicDrain::~MagicDrain() {
}

inline s32 MagicDrain::IsBurst() {
    return 1;
}

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline MagicDrainDescriptor::MagicDrainDescriptor() {
    return this;
}
#endif

#endif  // SPYRO_SOURCE_MAGICDRAIN_H
