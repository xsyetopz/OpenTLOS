#ifndef SPYRO_SOURCE_FLOATINGPLATFORMDESCRIPTOR_H
#define SPYRO_SOURCE_FLOATINGPLATFORMDESCRIPTOR_H

#include <dolphin/types.h>
#include "spyro/source/KDPropEx.h"

class FloatingPlatformDescriptor;
class KDPropExDescriptor;

class FloatingPlatformDescriptor : public KDPropExDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
    FloatingPlatformDescriptor(void);
};

#endif  // SPYRO_SOURCE_FLOATINGPLATFORMDESCRIPTOR_H
