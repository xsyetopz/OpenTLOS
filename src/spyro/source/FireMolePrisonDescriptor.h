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

#endif  // SPYRO_SOURCE_FIREMOLEPRISONDESCRIPTOR_H
