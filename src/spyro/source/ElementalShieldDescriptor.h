#ifndef SPYRO_SOURCE_ELEMENTALSHIELDDESCRIPTOR_H
#define SPYRO_SOURCE_ELEMENTALSHIELDDESCRIPTOR_H

#include <dolphin/types.h>
#include "spyro/source/KDProp.h"

class ElementalShieldDescriptor;
class KDPropDescriptor;

class ElementalShieldDescriptor : public KDPropDescriptor {  // base: vtable prefix
public:
    virtual void LoadDone(void);
};

#endif  // SPYRO_SOURCE_ELEMENTALSHIELDDESCRIPTOR_H
