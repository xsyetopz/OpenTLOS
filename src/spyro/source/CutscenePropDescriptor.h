#ifndef SPYRO_SOURCE_CUTSCENEPROPDESCRIPTOR_H
#define SPYRO_SOURCE_CUTSCENEPROPDESCRIPTOR_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"

class CutscenePropDescriptor;
class MKPropDescriptor;

class CutscenePropDescriptor : public MKPropDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline void CutscenePropDescriptor::Init() {
    MKPropDescriptor::Init();
    this->unkC |= 0x20;
}

#endif  // SPYRO_SOURCE_CUTSCENEPROPDESCRIPTOR_H
