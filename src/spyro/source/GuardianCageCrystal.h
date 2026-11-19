#ifndef SPYRO_SOURCE_GUARDIANCAGECRYSTAL_H
#define SPYRO_SOURCE_GUARDIANCAGECRYSTAL_H

#include <dolphin/types.h>
#include "common/Source/MKVector3.h"
#include "spyro/source/EnergyBeam.h"
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
    /* 0x1a3 */ u8 pad1A3[0x5];
    /* 0x1a8 */ MKVector3 unk1A8;
    /* 0x1b8 */ f64 unk1B8;
    /* 0x1c0 */ f64 unk1C0;
    /* 0x1c8 */ EnergyBeam::Beam* unk1C8;
    /* 0x1cc */ s32 unk1CC;
    /* 0x1d0 */ void* unk1D0;
    /* 0x1d4 */ u8 unk1D4;
    /* 0x1d5 */ u8 pad1D5[0x3];
    /* 0x1d8 */ s32 unk1D8;
    /* 0x1dc */ u8 pad1DC[0x24];
    /* 0x200 */ MKVector3 unk200;
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
