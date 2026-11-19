#ifndef SPYRO_SOURCE_ELEMENTALSHIELDDESCRIPTOR_H
#define SPYRO_SOURCE_ELEMENTALSHIELDDESCRIPTOR_H

#include <dolphin/types.h>
#include "spyro/source/KDProp.h"

class ElementalShieldDescriptor;
class KDPropDescriptor;

class ElementalShieldDescriptor : public KDPropDescriptor {  // base: vtable prefix
public:
    virtual void LoadDone(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline void ElementalShieldDescriptor::LoadDone() {
    KDPropDescriptor::LoadDone();
    this->unk64 = 0x20000080;
}

#endif  // SPYRO_SOURCE_ELEMENTALSHIELDDESCRIPTOR_H
