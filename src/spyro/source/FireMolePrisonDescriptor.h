#ifndef SPYRO_SOURCE_FIREMOLEPRISONDESCRIPTOR_H
#define SPYRO_SOURCE_FIREMOLEPRISONDESCRIPTOR_H

#include <dolphin/types.h>
#include "spyro/source/shatterwaypointspawn.h"

class FireMolePrisonDescriptor;
class ShatterWaypointSpawnDescriptor;

class FireMolePrisonDescriptor : public ShatterWaypointSpawnDescriptor {  // base: vtable prefix
public:
    virtual s32 GetSpawnEnemyType(void);
    FireMolePrisonDescriptor(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline FireMolePrisonDescriptor::FireMolePrisonDescriptor() {
    return this;
}
#endif

inline s32 FireMolePrisonDescriptor::GetSpawnEnemyType() {
    return 0x15;
}

#endif  // SPYRO_SOURCE_FIREMOLEPRISONDESCRIPTOR_H
