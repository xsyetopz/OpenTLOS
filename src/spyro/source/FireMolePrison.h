#ifndef SPYRO_SOURCE_FIREMOLEPRISON_H
#define SPYRO_SOURCE_FIREMOLEPRISON_H

#include <dolphin/types.h>
#include "spyro/source/shatterwaypointspawn.h"

class FireMolePrison;
class MKMessage;
class ShatterWaypointSpawn;

class FireMolePrison : public ShatterWaypointSpawn {  // base: vtable prefix
public:
    virtual ~FireMolePrison(void);
    virtual void Init(void);
    virtual void Deinit(void);
    virtual void Update(void);
    virtual void Message(MKMessage *);
    FireMolePrison(void);
};

#endif  // SPYRO_SOURCE_FIREMOLEPRISON_H
