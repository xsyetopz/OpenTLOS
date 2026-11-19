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

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#include <m2c_macros.h>

#if 0 // DRAFT: undefined identifier '__vt'
inline Button::~Button() {
    M2C_FIELD(this, s32 **, 0xC8) = &__vt.unk48;
    if (&this->unkE8 != NULL) {
        this->unkE8.Deinit();
    }
    if (&this->unkE4 != NULL) {
        this->unkE4.Deinit();
    }
}
#endif

#if 0 // DRAFT: undefined identifier '__vt'
inline Button::Button() {
    M2C_FIELD(this, void **, 0xC8) = (void *) (&__vt + 0x48);
    this->unkE4.unk0 = 0;
    this->unkE4.Init();
    this->unkE8.unk0 = 0;
    this->unkE8.Init();
    return this;
}
#endif

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline ButtonDescriptor::ButtonDescriptor() {
    return this;
}
#endif

#endif  // SPYRO_SOURCE_BUTTON_H
