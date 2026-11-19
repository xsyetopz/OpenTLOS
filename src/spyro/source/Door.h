#ifndef SPYRO_SOURCE_DOOR_H
#define SPYRO_SOURCE_DOOR_H

#include <dolphin/types.h>
#include "spyro/source/KDPropEx.h"
#include "spyro/source/Trap.h"

class Door;
class DoorDescriptor;
class DoorStates;
class KDPropExDescriptor;
class MKIniLine;
class MKMessage;
class Trap;

class Door : public Trap {  // base: vtable prefix
public:
    virtual ~Door(void);
    virtual void Init(void);
    virtual void Reset(void);
    virtual void Update(void);
    virtual void Message(MKMessage *);
    Door(void);
    void SetState(DoorStates);
    /* 0x0e0 */ s32 unkE0;
    /* 0x0e4 */ s32 unkE4;
};

class DoorDescriptor : public KDPropExDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    DoorDescriptor(void);
    /* 0x0c0 */ u8 padC0[0x24];
    /* 0x0e4 */ s32 unkE4;
    /* 0x0e8 */ s32 unkE8;
    /* 0x0ec */ s32 unkEC;
    /* 0x0f0 */ s32 unkF0;
    /* 0x0f4 */ u8 unkF4;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: undefined identifier 'unkC8'
inline Door::~Door() {
    this->unkC8 = &__vt + 0x48;
}
#endif

#if 0 // DRAFT: undefined identifier 'unkC8'
inline Door::Door() {
    this->unkC8 = &__vt + 0x48;
    return this;
}
#endif

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline DoorDescriptor::DoorDescriptor() {
    return this;
}
#endif

#endif  // SPYRO_SOURCE_DOOR_H
