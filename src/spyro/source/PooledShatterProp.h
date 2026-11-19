#ifndef SPYRO_SOURCE_POOLEDSHATTERPROP_H
#define SPYRO_SOURCE_POOLEDSHATTERPROP_H

#include <dolphin/types.h>
#include "spyro/source/Shatterable.h"

class PooledShatterProp;
class Shatterable;

class PooledShatterProp : public Shatterable {  // base: vtable prefix
public:
    virtual ~PooledShatterProp(void);
    virtual void Update(void);
    PooledShatterProp(void);
};

#endif  // SPYRO_SOURCE_POOLEDSHATTERPROP_H
