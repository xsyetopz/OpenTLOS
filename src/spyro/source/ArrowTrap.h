#ifndef SPYRO_SOURCE_ARROWTRAP_H
#define SPYRO_SOURCE_ARROWTRAP_H

#include <dolphin/types.h>
#include "spyro/source/KDPropEx.h"
#include "spyro/source/Trap.h"

class ArrowTrap;
class ArrowTrapDescriptor;
class KDPropExDescriptor;
class MKMessage;
class Trap;

class ArrowTrap : public Trap {  // base: vtable prefix
public:
    virtual ~ArrowTrap(void);
    virtual void Reset(void);
    virtual void Message(MKMessage *);
    ArrowTrap(void);
};

class ArrowTrapDescriptor : public KDPropExDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
    ArrowTrapDescriptor(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: undefined identifier 'unkC8'
inline ArrowTrap::~ArrowTrap() {
    this->unkC8 = &__vt.unk48;
}
#endif

#if 0 // DRAFT: undefined identifier 'unkC8'
inline ArrowTrap::ArrowTrap() {
    this->unkC8 = &__vt + 0x48;
    return this;
}
#endif

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline ArrowTrapDescriptor::ArrowTrapDescriptor() {
    return this;
}
#endif

#endif  // SPYRO_SOURCE_ARROWTRAP_H
