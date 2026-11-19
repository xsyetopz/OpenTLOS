#ifndef SPYRO_SOURCE_WAKEDESCRIPTOR_H
#define SPYRO_SOURCE_WAKEDESCRIPTOR_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"

class MKPropDescriptor;
class WakeDescriptor;

class WakeDescriptor : public MKPropDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline void WakeDescriptor::Init() {
    MKPropDescriptor::Init();
    this->unk14 |= 0x20;
}

#endif  // SPYRO_SOURCE_WAKEDESCRIPTOR_H
