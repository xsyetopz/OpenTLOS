#ifndef SPYRO_SOURCE_GUARDTOWERDESCRIPTOR_H
#define SPYRO_SOURCE_GUARDTOWERDESCRIPTOR_H

#include <dolphin/types.h>
#include "spyro/source/LavaSmashProp.h"

class GuardTowerDescriptor;
class LavaSmashPropDescriptor;

class GuardTowerDescriptor : public LavaSmashPropDescriptor {  // base: vtable prefix
public:
    GuardTowerDescriptor(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline GuardTowerDescriptor::GuardTowerDescriptor() {
    return this;
}
#endif

#endif  // SPYRO_SOURCE_GUARDTOWERDESCRIPTOR_H
