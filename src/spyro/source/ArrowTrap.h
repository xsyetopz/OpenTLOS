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

#endif  // SPYRO_SOURCE_ARROWTRAP_H
