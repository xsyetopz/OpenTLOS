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

class MagicDrain : public Projectile {  // base: base ctor call
public:
    virtual ~MagicDrain(void);
    virtual void Init(void);
    virtual s32 LoadDone(void);
    virtual void Deinit(void);
    virtual f32 Resolve(void);
    virtual void Reset(void);
    virtual void * Update(void);
    virtual void Draw(void);
    virtual void Fire(const MKVector3 &, const MKVector3 &, MKProp *, int, int);
    virtual void FireBurst(MKVector3 *, MKVector3 *, int, int);
    virtual void FireBurstEnd(void);
    virtual s32 IsBurst(void);
    virtual void Collided(MKCollisionResult &);
    MagicDrain(void);
    void SetDefaults(void);
    static void * CreateInstance(void);
    /* 0x150 */ MKVector3* unk150;
    /* 0x154 */ MKVector3* unk154;
    /* 0x158 */ u8 unk158;
    /* 0x159 */ u8 pad159[0x3];
    /* 0x15c */ ManagedLight* unk15C;
    /* 0x160 */ BreathHitMessage unk160;
    /* 0x1b4 */ u8 pad1B4[0x4];
    /* 0x1b8 */ f32 unk1B8;
};

class MagicDrainDescriptor : public ProjectileDescriptor {  // base: base ctor call
public:
    virtual void LoadDone(void);
    virtual void Deinit(void);
    MagicDrainDescriptor(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline MagicDrain::MagicDrain() {
    this->unk160.unk4 = 0;
}

inline MagicDrain::~MagicDrain() {
}

inline s32 MagicDrain::IsBurst() {
    return 1;
}

inline MagicDrainDescriptor::MagicDrainDescriptor() {
}

#endif  // SPYRO_SOURCE_MAGICDRAIN_H
