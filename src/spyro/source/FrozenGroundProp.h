#ifndef SPYRO_SOURCE_FROZENGROUNDPROP_H
#define SPYRO_SOURCE_FROZENGROUNDPROP_H

#include <dolphin/types.h>
#include "spyro/source/KDProp.h"

class FrozenGroundProp;
class KDProp;

class FrozenGroundProp : public KDProp {  // base: ctor/dtor vtable stores
public:
    virtual ~FrozenGroundProp(void);
    virtual void Init(void);
    virtual void Deinit(void);
};

#endif  // SPYRO_SOURCE_FROZENGROUNDPROP_H
