#ifndef SPYRO_SOURCE_FIGHTELEVATORANCHOR_H
#define SPYRO_SOURCE_FIGHTELEVATORANCHOR_H

#include <dolphin/types.h>
#include "spyro/source/Shatterable.h"

class FightElevatorAnchor;
class MKIniLine;
class Shatterable;

class FightElevatorAnchor : public Shatterable {  // base: vtable prefix
public:
    virtual ~FightElevatorAnchor(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Update(void);
    FightElevatorAnchor(void);
    void GetZapAnchorPos(void);
};

#endif  // SPYRO_SOURCE_FIGHTELEVATORANCHOR_H
