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

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline ShatterablePlatformDescriptor::ShatterablePlatformDescriptor() {
    return this;
}
#endif

#endif  // SPYRO_SOURCE_SHATTERABLEPLATFORMDESCRIPTOR_H
