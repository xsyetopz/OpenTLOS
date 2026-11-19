#ifndef SPYRO_SOURCE_MAGICFIREBALL_H
#define SPYRO_SOURCE_MAGICFIREBALL_H

#include <dolphin/types.h>
#include "spyro/source/Projectile.h"

class MKCollisionResult;
class MKMessage;
class MKProp;
class MKVector3;
class MagicFireball;
class MagicFireballDescriptor;
class ManagedLight;
class Projectile;
class ProjectileDescriptor;

class MagicFireball : public Projectile {  // base: vtable prefix
public:
    virtual ~MagicFireball(void);
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Reset(void);
    virtual void Update(void);
    virtual void Message(MKMessage *);
    virtual void Disable(void);
    virtual void Activate(void);
    virtual void Deactivate(void);
    virtual void Fire(const MKVector3 &, const MKVector3 &, MKProp *, int, int);
    virtual void Collided(MKCollisionResult &);
    MagicFireball(void);
    void * CreateInstance(void);
    /* 0x14d */ u8 pad14D[0x13];
    /* 0x160 */ ManagedLight* unk160;
    /* 0x164 */ s32 unk164;
    /* 0x168 */ u8 pad168[0x24];
    /* 0x18c */ u8 unk18C;
};

class MagicFireballDescriptor : public ProjectileDescriptor {  // base: vtable prefix
public:
    virtual void LoadDone(void);
    virtual void Deinit(void);
    MagicFireballDescriptor(void);
    /* 0x0f0 */ s32 unkF0;
};

#endif  // SPYRO_SOURCE_MAGICFIREBALL_H
