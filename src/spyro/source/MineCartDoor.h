#ifndef SPYRO_SOURCE_MINECARTDOOR_H
#define SPYRO_SOURCE_MINECARTDOOR_H

#include <dolphin/types.h>
#include "spyro/source/GameProp.h"

class GameProp;
class GamePropDescriptor;
class MKMessage;
class MineCartDoor;
class MineCartDoorDescriptor;

class MineCartDoor : public GameProp {  // base: base ctor call
public:
    virtual ~MineCartDoor(void);
    virtual void Reset(void);
    virtual void * Update(void);
    virtual void Message(MKMessage *);
    MineCartDoor(void);
    void SetState(int);
    /* 0x0c8 */ s32 unkC8;
};

class MineCartDoorDescriptor : public GamePropDescriptor {  // base: base ctor call
public:
    virtual void LoadDone(void);
    MineCartDoorDescriptor(void);
    /* 0x0e8 */ s32 unkE8;
    /* 0x0ec */ s32 unkEC;
    /* 0x0f0 */ s32 unkF0;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline MineCartDoor::MineCartDoor() {
}

inline MineCartDoor::~MineCartDoor() {
}

inline MineCartDoorDescriptor::MineCartDoorDescriptor() {
}

#endif  // SPYRO_SOURCE_MINECARTDOOR_H
