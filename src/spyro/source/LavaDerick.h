#ifndef SPYRO_SOURCE_LAVADERICK_H
#define SPYRO_SOURCE_LAVADERICK_H

#include <dolphin/types.h>
#include "spyro/source/Shatterable.h"

class LavaDerick;
class LavaDerickDescriptor;
class LavaDerick_cpp;
class MKMessage;
class Shatterable;
class ShatterableDescriptor;

class LavaDerick : public Shatterable {  // base: vtable prefix
public:
    virtual ~LavaDerick(void);
    virtual void Message(MKMessage *);
    LavaDerick(void);
};

class LavaDerickDescriptor : public ShatterableDescriptor {  // base: vtable prefix
public:
    virtual void Resolve(void);
    LavaDerickDescriptor(void);
    void * CalcBounds(void);
};

class LavaDerick_cpp {
public:
    void __sinit(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: undefined identifier 'unkC8'
inline LavaDerick::LavaDerick() {
    this->unkC8 = &__vt + 0x48;
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier 'unkC8'
inline LavaDerick::~LavaDerick() {
    this->unkC8 = &__vt.unk48;
}
#endif

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline LavaDerickDescriptor::LavaDerickDescriptor() {
    return this;
}
#endif

#endif  // SPYRO_SOURCE_LAVADERICK_H
