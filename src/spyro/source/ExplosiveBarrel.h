#ifndef SPYRO_SOURCE_EXPLOSIVEBARREL_H
#define SPYRO_SOURCE_EXPLOSIVEBARREL_H

#include <dolphin/types.h>
#include "spyro/source/Shatterable.h"

class ExplosiveBarrel;
class ExplosiveBarrelDescriptor;
class ExplosiveBarrelPath;
class MKIniLine;
class MKMessage;
class Shatterable;
class ShatterableDescriptor;

class ExplosiveBarrel : public Shatterable {  // base: vtable prefix
public:
    class States;
    virtual ~ExplosiveBarrel(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Update(void);
    virtual void Draw(void);
    virtual void Message(MKMessage *);
    virtual void Enable(void);
    virtual void Disable(void);
    virtual s32 IsDead(void);
    ExplosiveBarrel(void);
    void Ignite(float);
    void Explode(void);
    void SetState(ExplosiveBarrel::States);
    s32 GetState(void);
    void SetActive(bool);
    u8 IsActive(void);
    void TriggerShatterFX(void);
    f32 GetRadius(void);
    void SetOwner(ExplosiveBarrelPath *);
    void SetDefaults(void);
};

class ExplosiveBarrelDescriptor : public ShatterableDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    ExplosiveBarrelDescriptor(void);
    /* 0x16c */ s32 unk16C;
    /* 0x170 */ s32 unk170;
    /* 0x174 */ f32 unk174;
    /* 0x178 */ f32 unk178;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: undefined identifier 'unkC8'
inline ExplosiveBarrel::ExplosiveBarrel() {
    this->unkC8 = &__vt + 0x48;
    this->unk1AC = NULL;
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier 'unkC8'
inline ExplosiveBarrel::~ExplosiveBarrel() {
    this->unkC8 = &__vt.unk48;
    if (&this->unk1AC != NULL) {
        KDSound_Stop((s32 *) &this->unk1AC);
    }
}
#endif

inline s32 ExplosiveBarrel::IsDead() {
    return GetState() == 4;
}

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline ExplosiveBarrelDescriptor::ExplosiveBarrelDescriptor() {
    return this;
}
#endif

#endif  // SPYRO_SOURCE_EXPLOSIVEBARREL_H
