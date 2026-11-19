#ifndef SPYRO_SOURCE_SMASHWALLDESCRIPTOR_H
#define SPYRO_SOURCE_SMASHWALLDESCRIPTOR_H

#include <dolphin/types.h>
#include "spyro/source/Shatterable.h"

class ShatterableDescriptor;
class SmashWallDescriptor;

class SmashWallDescriptor : public ShatterableDescriptor {  // base: vtable prefix
public:
    SmashWallDescriptor(void);
};

#endif  // SPYRO_SOURCE_SMASHWALLDESCRIPTOR_H
