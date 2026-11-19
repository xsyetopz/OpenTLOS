#ifndef SPYRO_SOURCE_MINECARTDOOR_H
#define SPYRO_SOURCE_MINECARTDOOR_H

#include <dolphin/types.h>
#include "spyro/source/GameProp.h"
#include "spyro/source/KDPropEx.h"

class GameProp;
class KDPropExDescriptor;
class MKMessage;
class MineCartDoor;
class MineCartDoorDescriptor;

class MineCartDoor : public GameProp {  // base: vtable prefix
public:
    virtual ~MineCartDoor(void);
    virtual void Reset(void);
    virtual void Update(void);
    virtual void Message(MKMessage *);
    MineCartDoor(void);
    void SetState(int);
    /* 0x0c4 */ u8 padC4[0x4];
    /* 0x0c8 */ s32 unkC8;
};

class MineCartDoorDescriptor : public KDPropExDescriptor {  // base: vtable prefix
public:
    virtual void LoadDone(void);
    MineCartDoorDescriptor(void);
    /* 0x0c0 */ u8 padC0[0x24];
    /* 0x0e4 */ s32 unkE4;
    /* 0x0e8 */ s32 unkE8;
    /* 0x0ec */ s32 unkEC;
    /* 0x0f0 */ s32 unkF0;
};

#endif  // SPYRO_SOURCE_MINECARTDOOR_H
