#ifndef SPYRO_SOURCE_GUARDTOWERDESCRIPTOR_H
#define SPYRO_SOURCE_GUARDTOWERDESCRIPTOR_H

#include <dolphin/types.h>
#include "spyro/source/LavaSmashProp.h"

class GuardTowerDescriptor;
class LavaSmashPropDescriptor;

class GuardTowerDescriptor : public LavaSmashPropDescriptor {  // base: base ctor call
public:
    GuardTowerDescriptor(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline GuardTowerDescriptor::GuardTowerDescriptor() {
}

#endif  // SPYRO_SOURCE_GUARDTOWERDESCRIPTOR_H
