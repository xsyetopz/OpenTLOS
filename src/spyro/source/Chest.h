#ifndef SPYRO_SOURCE_CHEST_H
#define SPYRO_SOURCE_CHEST_H

#include <dolphin/types.h>
#include "spyro/source/Trap.h"

class Chest;
class ChestDescriptor;
class MKMessage;
class Trap;
class TrapDescriptor;

class Chest : public Trap {  // base: vtable prefix
public:
    virtual ~Chest(void);
    virtual void Init(void);
    virtual void Reset(void);
    virtual void Update(void);
    virtual void Message(MKMessage *);
    Chest(void);
    void SetState(int);
    /* 0x0e0 */ s32 unkE0;
    /* 0x0e4 */ s32 unkE4;
    /* 0x0e8 */ f32 unkE8;
};

class ChestDescriptor : public TrapDescriptor {  // base: vtable prefix
public:
    virtual void LoadDone(void);
    ChestDescriptor(void);
    /* 0x0c0 */ u8 padC0[0x24];
    /* 0x0e4 */ s32 unkE4;
    /* 0x0e8 */ s32 unkE8;
    /* 0x0ec */ s32 unkEC;
};

#endif  // SPYRO_SOURCE_CHEST_H
