#ifndef SPYRO_SOURCE_MAGMASQUIRT_H
#define SPYRO_SOURCE_MAGMASQUIRT_H

#include <dolphin/types.h>
#include "spyro/source/GameMessages.h"
#include "spyro/source/Projectile.h"

class BreathHitMessage;
class LiquidFX;
class MKCollisionResult;
class MKProp;
class MKVector3;
class MagmaSquirt;
class MagmaSquirtDescriptor;
class ManagedLight;
class Projectile;
class ProjectileDescriptor;

class MagmaSquirt : public Projectile {  // base: vtable prefix
public:
    virtual ~MagmaSquirt(void);
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
    MagmaSquirt(void);
    void SetDefaults(void);
    void * CreateInstance(void);
    /* 0x14d */ u8 pad14D[0x3];
    /* 0x150 */ LiquidFX* unk150;
    /* 0x154 */ MKVector3* unk154;
    /* 0x158 */ MKVector3* unk158;
    /* 0x15c */ u8 unk15C;
    /* 0x15d */ u8 pad15D[0x3];
    /* 0x160 */ ManagedLight* unk160;
    /* 0x164 */ s32 unk164;
    /* 0x168 */ s32 unk168;
    /* 0x16c */ u8 pad16C[0x4];
    /* 0x170 */ BreathHitMessage unk170;
};

class MagmaSquirtDescriptor : public ProjectileDescriptor {  // base: vtable prefix
public:
    virtual void LoadDone(void);
    virtual void Deinit(void);
    MagmaSquirtDescriptor(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: undefined identifier 'unk4'
inline MagmaSquirt::MagmaSquirt() {
    this->unk170.unk4 = 0;
    return this;
}
#endif

inline MagmaSquirt::~MagmaSquirt() {
}

inline s32 MagmaSquirt::IsBurst() {
    return 1;
}

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline MagmaSquirtDescriptor::MagmaSquirtDescriptor() {
    return this;
}
#endif

#endif  // SPYRO_SOURCE_MAGMASQUIRT_H
