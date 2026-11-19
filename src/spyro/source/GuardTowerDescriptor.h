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

#endif  // SPYRO_SOURCE_GUARDTOWERDESCRIPTOR_H
