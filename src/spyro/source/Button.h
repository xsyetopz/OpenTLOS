#ifndef SPYRO_SOURCE_BUTTON_H
#define SPYRO_SOURCE_BUTTON_H

#include <dolphin/types.h>
#include "spyro/source/EventMessage.h"
#include "spyro/source/Trap.h"

class Button;
class ButtonDescriptor;
class EventMessage;
class MKIniLine;
class MKMessage;
class Trap;
class TrapDescriptor;

class Button : public Trap {  // base: vtable prefix
public:
    virtual ~Button(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void Reset(void);
    virtual void Update(void);
    virtual void Message(MKMessage *);
    Button(void);
    void SetState(int);
    /* 0x0e0 */ s32 unkE0;
    /* 0x0e4 */ EventMessage unkE4;
    /* 0x0e8 */ EventMessage unkE8;
    /* 0x0ec */ u8 unkEC;
};

class ButtonDescriptor : public TrapDescriptor {  // base: vtable prefix
public:
    virtual void LoadDone(void);
    ButtonDescriptor(void);
    /* 0x0c0 */ u8 padC0[0x24];
    /* 0x0e4 */ s32 unkE4;
    /* 0x0e8 */ s32 unkE8;
    /* 0x0ec */ s32 unkEC;
    /* 0x0f0 */ s32 unkF0;
};

#endif  // SPYRO_SOURCE_BUTTON_H
