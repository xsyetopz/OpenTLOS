#ifndef SPYRO_SOURCE_SMASHWALL_H
#define SPYRO_SOURCE_SMASHWALL_H

#include <dolphin/types.h>
#include "spyro/source/Shatterable.h"

class MKMessage;
class Shatterable;
class SmashWall;

class SmashWall : public Shatterable {  // base: vtable prefix
public:
    virtual ~SmashWall(void);
    virtual void Message(MKMessage *);
    SmashWall(void);
};

#endif  // SPYRO_SOURCE_SMASHWALL_H
