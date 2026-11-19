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

#endif  // SPYRO_SOURCE_CUTSCENEPROPDESCRIPTOR_H
