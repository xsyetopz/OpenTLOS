#ifndef SPYRO_SOURCE_SHATTERABLEPLATFORMDESCRIPTOR_H
#define SPYRO_SOURCE_SHATTERABLEPLATFORMDESCRIPTOR_H

#include <dolphin/types.h>
#include "spyro/source/Shatterable.h"

class ShatterableDescriptor;
class ShatterablePlatformDescriptor;

class ShatterablePlatformDescriptor : public ShatterableDescriptor {  // base: base ctor call
public:
    ShatterablePlatformDescriptor(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline ShatterablePlatformDescriptor::ShatterablePlatformDescriptor() {
}

#endif  // SPYRO_SOURCE_SHATTERABLEPLATFORMDESCRIPTOR_H
