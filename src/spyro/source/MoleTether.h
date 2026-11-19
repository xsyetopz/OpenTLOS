#ifndef SPYRO_SOURCE_MOLETETHER_H
#define SPYRO_SOURCE_MOLETETHER_H

#include <dolphin/types.h>
#include "spyro/source/Shatterable.h"

class MKMessage;
class MKVector3;
class Matrix;
class MoleTether;
class MoleTetherDescriptor;
class Shatterable;
class ShatterableDescriptor;

class MoleTether : public Shatterable {  // base: vtable prefix
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
};

class MoleTetherDescriptor : public ShatterableDescriptor {  // base: vtable prefix
public:
    virtual void LoadDone(void);
    MoleTetherDescriptor(void);
    /* 0x16c */ s32 unk16C;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#include <m2c_macros.h>

#if 0 // DRAFT: undefined identifier 'unkC8'
inline MoleTether::MoleTether() {
    this->unkC8 = &__vt + 0x48;
    M2C_FIELD(this, s32 *, 0x1C8) = 0;
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier 'unkC8'
inline MoleTether::~MoleTether() {
    this->unkC8 = &__vt.unk48;
    if ((&this->unk1B8 != NULL) && (&this->unk1B8 != NULL)) {
        KDSound_Stop((s32 *) &this->unk1B8);
    }
}
#endif

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline MoleTetherDescriptor::MoleTetherDescriptor() {
    return this;
}
#endif

#endif  // SPYRO_SOURCE_MOLETETHER_H
