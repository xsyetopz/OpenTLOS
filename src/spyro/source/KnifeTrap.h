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

#endif  // SPYRO_SOURCE_KNIFETRAP_H
