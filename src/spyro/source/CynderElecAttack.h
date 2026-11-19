#ifndef SPYRO_SOURCE_CYNDERELECATTACK_H
#define SPYRO_SOURCE_CYNDERELECATTACK_H

#include <dolphin/types.h>
#include "spyro/source/EnergyBeam.h"
#include "spyro/source/Projectile.h"

class CynderElecAttack;
class CynderElecAttackDescriptor;
class MKCollisionResult;
class MKProp;
class MKVector3;
class ManagedLight;
class Projectile;
class ProjectileDescriptor;

class CynderElecAttack : public Projectile {  // base: vtable prefix
public:
    virtual ~CynderElecAttack(void);
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
    CynderElecAttack(void);
    void SetDefaults(void);
    void * CreateInstance(void);
    /* 0x14d */ u8 pad14D[0x3];
    /* 0x150 */ MKVector3* unk150;
    /* 0x154 */ MKVector3* unk154;
    /* 0x158 */ u8 unk158;
    /* 0x159 */ u8 pad159[0x3];
    /* 0x15c */ ManagedLight* unk15C;
    /* 0x160 */ EnergyBeam::Beam* unk160;
};

class CynderElecAttackDescriptor : public ProjectileDescriptor {  // base: vtable prefix
public:
    virtual void LoadDone(void);
    virtual void Deinit(void);
    CynderElecAttackDescriptor(void);
    /* 0x0f0 */ s32 unkF0;
};

#endif  // SPYRO_SOURCE_CYNDERELECATTACK_H
