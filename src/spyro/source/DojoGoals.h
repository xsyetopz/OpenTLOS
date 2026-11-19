#ifndef SPYRO_SOURCE_DOJOGOALS_H
#define SPYRO_SOURCE_DOJOGOALS_H

#include <dolphin/types.h>
#include "spyro/source/Goal.h"

class Character;
class DojoGoal_SpawnIdle;
class Enemy;

class DojoGoal_SpawnIdle : public Goal<Enemy> {  // base: inlined ctor vtable stores
public:
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Character* unkC;
};

#endif  // SPYRO_SOURCE_DOJOGOALS_H
