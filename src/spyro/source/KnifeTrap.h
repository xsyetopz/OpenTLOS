#ifndef SPYRO_SOURCE_KNIFETRAP_H
#define SPYRO_SOURCE_KNIFETRAP_H

#include <dolphin/types.h>
#include "spyro/source/Trap.h"

class KnifeTrap;
class KnifeTrapDescriptor;
class Trap;
class TrapDescriptor;

class KnifeTrap : public Trap {  // base: base ctor call
public:
    virtual ~KnifeTrap(void);
    virtual void Reset(void);
    virtual void * Update(void);
    KnifeTrap(void);
};

class KnifeTrapDescriptor : public TrapDescriptor {  // base: base ctor call
public:
    virtual void Init(void);
    KnifeTrapDescriptor(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#include <m2c_macros.h>

#if 0 // DRAFT: undefined identifier '__vt'
inline KnifeTrap::KnifeTrap() {
    M2C_FIELD(this, void **, 0xC8) = (void *) (&__vt + 0x48);
}
#endif

#if 0 // DRAFT: undefined identifier '__vt'
inline KnifeTrap::~KnifeTrap() {
    M2C_FIELD(this, s32 **, 0xC8) = &__vt.unk48;
}
#endif

inline KnifeTrapDescriptor::KnifeTrapDescriptor() {
}

#endif  // SPYRO_SOURCE_KNIFETRAP_H
