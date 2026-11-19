#ifndef SPYRO_SOURCE_EARTHTIER3GOALS_H
#define SPYRO_SOURCE_EARTHTIER3GOALS_H

#include <dolphin/types.h>
#include "spyro/source/Goal.h"

class EarthTier3Goal_Spawn;
class Enemy;

class EarthTier3Goal_Spawn : public Goal<Enemy> {  // base: vtable prefix
public:
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Enemy* unkC;
};

#endif  // SPYRO_SOURCE_EARTHTIER3GOALS_H
