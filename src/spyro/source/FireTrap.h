#ifndef SPYRO_SOURCE_FIRETRAP_H
#define SPYRO_SOURCE_FIRETRAP_H

#include <dolphin/types.h>
#include "spyro/source/KDPropEx.h"
#include "spyro/source/Trap.h"

class FireTrap;
class FireTrapDescriptor;
class KDPropExDescriptor;
class MKMessage;
class Trap;

class FireTrap : public Trap {  // base: vtable prefix
public:
    virtual ~FireTrap(void);
    virtual void Reset(void);
    virtual void Update(void);
    virtual void Message(MKMessage *);
    FireTrap(void);
    /* 0x0e0 */ f32 unkE0;
};

class FireTrapDescriptor : public KDPropExDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
    FireTrapDescriptor(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#include <m2c_macros.h>

#if 0 // DRAFT: undefined identifier '__vt'
inline FireTrap::FireTrap() {
    M2C_FIELD(this, void **, 0xC8) = (void *) (&__vt + 0x48);
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier '__vt'
inline FireTrap::~FireTrap() {
    M2C_FIELD(this, s32 **, 0xC8) = &__vt.unk48;
}
#endif

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline FireTrapDescriptor::FireTrapDescriptor() {
    return this;
}
#endif

#endif  // SPYRO_SOURCE_FIRETRAP_H
