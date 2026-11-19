#ifndef SPYRO_SOURCE_MOLETETHER_H
#define SPYRO_SOURCE_MOLETETHER_H

#include <dolphin/types.h>
#include "common/Source/MKVector3.h"
#include "spyro/source/EnergyBeam.h"
#include "spyro/source/Shatterable.h"

class MKMessage;
class MKVector3;
class Matrix;
class MiningMole;
class MoleTether;
class MoleTetherDescriptor;
class Shatterable;
class ShatterableDescriptor;

class MoleTether : public Shatterable {  // base: base ctor call
public:
    virtual ~MoleTether(void);
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Update(void);
    virtual void Message(MKMessage *);
    virtual void Shatter(bool, MKVector3 *, int, MKVector3 *, bool);
    MoleTether(void);
    void SetWorldMatrix(Matrix &);
    /* 0x1a8 */ MKVector3 unk1A8;
    /* 0x1b8 */ f64 unk1B8;
    /* 0x1c0 */ f64 unk1C0;
    /* 0x1c8 */ s32 unk1C8;
    /* 0x1cc */ u8 pad1CC[0x24];
    /* 0x1f0 */ MiningMole* unk1F0;
    /* 0x1f4 */ EnergyBeam::Beam* unk1F4;
    /* 0x1f8 */ u32 unk1F8;
    /* 0x1fc */ u8 unk1FC;
};

class MoleTetherDescriptor : public ShatterableDescriptor {  // base: base ctor call
public:
    virtual void LoadDone(void);
    MoleTetherDescriptor(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: undefined identifier 'unkC8'
inline MoleTether::MoleTether() {
    this->unkC8 = &__vt + 0x48;
    this->unk1C8 = 0;
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier 'unkC8'
inline MoleTether::~MoleTether() {
    this->unkC8 = &__vt.unk48;
    if ((&this->unk1C8 != NULL) && (&this->unk1C8 != NULL)) {
        KDSound_Stop((int *) &this->unk1C8);
    }
}
#endif

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline MoleTetherDescriptor::MoleTetherDescriptor() {
    return this;
}
#endif

#endif  // SPYRO_SOURCE_MOLETETHER_H
