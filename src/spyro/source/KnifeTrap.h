#ifndef SPYRO_SOURCE_KNIFETRAP_H
#define SPYRO_SOURCE_KNIFETRAP_H

#include <dolphin/types.h>
#include "spyro/source/KDPropEx.h"
#include "spyro/source/Trap.h"

class KDPropExDescriptor;
class KnifeTrap;
class KnifeTrapDescriptor;
class Trap;

class KnifeTrap : public Trap {  // base: vtable prefix
public:
    virtual ~KnifeTrap(void);
    virtual void Reset(void);
    virtual void Update(void);
    KnifeTrap(void);
};

class KnifeTrapDescriptor : public KDPropExDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
    KnifeTrapDescriptor(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: undefined identifier 'unkC8'
inline KnifeTrap::KnifeTrap() {
    this->unkC8 = &__vt + 0x48;
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier 'unkC8'
inline KnifeTrap::~KnifeTrap() {
    this->unkC8 = &__vt.unk48;
}
#endif

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline KnifeTrapDescriptor::KnifeTrapDescriptor() {
    return this;
}
#endif

#endif  // SPYRO_SOURCE_KNIFETRAP_H
