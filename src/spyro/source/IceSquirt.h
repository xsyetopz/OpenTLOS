#ifndef SPYRO_SOURCE_ICESQUIRT_H
#define SPYRO_SOURCE_ICESQUIRT_H

#include <dolphin/types.h>
#include "spyro/source/GameMessages.h"
#include "spyro/source/Projectile.h"

class BreathHitMessage;
class IceSquirt;
class IceSquirtDescriptor;
class LiquidFX;
class MKCollisionResult;
class MKProp;
class MKVector3;
class ManagedLight;
class Projectile;
class ProjectileDescriptor;

class IceSquirt : public Projectile {  // base: base ctor call
public:
    virtual ~IceSquirt(void);
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
    IceSquirt(void);
    void SetDefaults(void);
    void * CreateInstance(void);
    /* 0x150 */ LiquidFX* unk150;
    /* 0x154 */ MKVector3* unk154;
    /* 0x158 */ MKVector3* unk158;
    /* 0x15c */ u8 unk15C;
    /* 0x15d */ u8 pad15D[0x3];
    /* 0x160 */ ManagedLight* unk160;
    /* 0x164 */ u8 pad164[0x4];
    /* 0x168 */ BreathHitMessage unk168;
};

class IceSquirtDescriptor : public ProjectileDescriptor {  // base: base ctor call
public:
    virtual void LoadDone(void);
    virtual void Deinit(void);
    IceSquirtDescriptor(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline IceSquirt::IceSquirt() {
    this->unk168.unk4 = 0;
    return this;
}
#endif

inline IceSquirt::~IceSquirt() {
}

inline s32 IceSquirt::IsBurst() {
    return 1;
}

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline IceSquirtDescriptor::IceSquirtDescriptor() {
    return this;
}
#endif

#endif  // SPYRO_SOURCE_ICESQUIRT_H
