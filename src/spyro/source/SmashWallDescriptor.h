#ifndef SPYRO_SOURCE_SMASHWALLDESCRIPTOR_H
#define SPYRO_SOURCE_SMASHWALLDESCRIPTOR_H

#include <dolphin/types.h>
#include "spyro/source/Shatterable.h"

class ShatterableDescriptor;
class SmashWallDescriptor;

class SmashWallDescriptor : public ShatterableDescriptor {  // base: base ctor call
public:
    SmashWallDescriptor(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline SmashWallDescriptor::SmashWallDescriptor() {
}

#endif  // SPYRO_SOURCE_SMASHWALLDESCRIPTOR_H
