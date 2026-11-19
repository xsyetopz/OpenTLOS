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
    /* 0x150 */ u8 pad150[0x10];
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

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline MagicFireball::MagicFireball() {
    this->unk164 = 0;
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier 'KDSound_Stop'
inline MagicFireball::~MagicFireball() {
    if ((&this->unk164 != NULL) && (&this->unk164 != NULL)) {
        KDSound_Stop((int *) &this->unk164);
    }
}
#endif

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline MagicFireballDescriptor::MagicFireballDescriptor() {
    return this;
}
#endif

#endif  // SPYRO_SOURCE_MAGICFIREBALL_H
