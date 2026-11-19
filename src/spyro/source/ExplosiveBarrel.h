#ifndef SPYRO_SOURCE_EXPLOSIVEBARREL_H
#define SPYRO_SOURCE_EXPLOSIVEBARREL_H

#include <dolphin/types.h>
#include "spyro/source/Shatterable.h"

class BurningWick;
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
    /* 0x1a3 */ u8 pad1A3[0x5];
    /* 0x1a8 */ ExplosiveBarrelPath* unk1A8;
    /* 0x1ac */ BurningWick* unk1AC;
    /* 0x1b0 */ f32 unk1B0;
    /* 0x1b4 */ s32 unk1B4;
    /* 0x1b8 */ u8 unk1B8;
    /* 0x1b9 */ u8 unk1B9;
    /* 0x1ba */ u8 unk1BA;
    /* 0x1bb */ u8 pad1BB[0x1];
    /* 0x1bc */ s32 unk1BC;
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
