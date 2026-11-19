#ifndef SPYRO_SOURCE_GUARDIANCAGECRYSTAL_H
#define SPYRO_SOURCE_GUARDIANCAGECRYSTAL_H

#include <dolphin/types.h>
#include "spyro/source/Shatterable.h"

class GuardianCageCrystal;
class GuardianCageCrystalDescriptor;
class MKIniLine;
class MKMessage;
class MKVector3;
class Shatterable;
class ShatterableDescriptor;

class GuardianCageCrystal : public Shatterable {  // base: vtable prefix
public:
    virtual ~GuardianCageCrystal(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Reset(void);
    virtual void Update(void);
    virtual void Draw(void);
    virtual void Message(MKMessage *);
    virtual void Shatter(bool, MKVector3 *, int, MKVector3 *, bool, bool);
    GuardianCageCrystal(void);
    void Explode(void);
};

class GuardianCageCrystalDescriptor : public ShatterableDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    GuardianCageCrystalDescriptor(void);
    /* 0x16c */ s32 unk16C;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: undefined identifier 'unkC8'
inline GuardianCageCrystal::GuardianCageCrystal() {
    this->unkC8 = &__vt + 0x48;
    this->unk1C8 = NULL;
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier 'unkC8'
inline GuardianCageCrystal::~GuardianCageCrystal() {
    this->unkC8 = &__vt.unk48;
    if ((&this->unk1C8 != NULL) && (&this->unk1C8 != NULL)) {
        KDSound_Stop((s32 *) &this->unk1C8);
    }
}
#endif

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline GuardianCageCrystalDescriptor::GuardianCageCrystalDescriptor() {
    return this;
}
#endif

#endif  // SPYRO_SOURCE_GUARDIANCAGECRYSTAL_H
