#ifndef SPYRO_SOURCE_SHATTERABLEPLATFORMDESCRIPTOR_H
#define SPYRO_SOURCE_SHATTERABLEPLATFORMDESCRIPTOR_H

#include <dolphin/types.h>
#include "spyro/source/Shatterable.h"

class ShatterableDescriptor;
class ShatterablePlatformDescriptor;

class ShatterablePlatformDescriptor : public ShatterableDescriptor {  // base: vtable prefix
public:
    ShatterablePlatformDescriptor(void);
};

#endif  // SPYRO_SOURCE_SHATTERABLEPLATFORMDESCRIPTOR_H
