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

#endif  // SPYRO_SOURCE_FIRETRAP_H
