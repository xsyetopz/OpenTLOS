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

#endif  // SPYRO_SOURCE_WAKEDESCRIPTOR_H
