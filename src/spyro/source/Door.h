#ifndef SPYRO_SOURCE_DOOR_H
#define SPYRO_SOURCE_DOOR_H

#include <dolphin/types.h>
#include "spyro/source/Trap.h"
#include "unplaced_enums.h"

class Door;
class DoorDescriptor;
class MKIniLine;
class MKMessage;
class Trap;
class TrapDescriptor;

class Door : public Trap {  // base: base ctor call
public:
    virtual ~Door(void);
    virtual void Init(void);
    virtual void Reset(void);
    virtual void * Update(void);
    virtual void Message(MKMessage *);
    Door(void);
    void SetState(DoorStates);
    /* 0x0e0 */ s32 unkE0;
    /* 0x0e4 */ s32 unkE4;
};

class DoorDescriptor : public TrapDescriptor {  // base: base ctor call
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    DoorDescriptor(void);
    /* 0x0e8 */ s32 unkE8;
    /* 0x0ec */ s32 unkEC;
    /* 0x0f0 */ s32 unkF0;
    /* 0x0f4 */ u8 unkF4;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#include <m2c_macros.h>

#if 0 // DRAFT: undefined identifier '__vt'
inline Door::~Door() {
    M2C_FIELD(this, void **, 0xC8) = (void *) (&__vt + 0x48);
}
#endif

#if 0 // DRAFT: undefined identifier '__vt'
inline Door::Door() {
    M2C_FIELD(this, void **, 0xC8) = (void *) (&__vt + 0x48);
}
#endif

inline DoorDescriptor::DoorDescriptor() {
}

#endif  // SPYRO_SOURCE_DOOR_H
