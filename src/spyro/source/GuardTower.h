#ifndef SPYRO_SOURCE_GUARDTOWER_H
#define SPYRO_SOURCE_GUARDTOWER_H

#include <dolphin/types.h>
#include "spyro/source/LavaSmashProp.h"

class GuardTower;
class LavaSmashProp;

class GuardTower : public LavaSmashProp {  // base: vtable prefix
public:
    virtual ~GuardTower(void);
    virtual void Init(void);
    virtual void Update(void);
    GuardTower(void);
};

#endif  // SPYRO_SOURCE_GUARDTOWER_H
