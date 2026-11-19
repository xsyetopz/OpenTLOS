#ifndef SPYRO_SOURCE_CHEST_H
#define SPYRO_SOURCE_CHEST_H

#include <dolphin/types.h>
#include "spyro/source/Trap.h"

class Chest;
class ChestDescriptor;
class MKMessage;
class Trap;
class TrapDescriptor;

class Chest : public Trap {  // base: base ctor call
public:
    virtual ~Chest(void);
    virtual void Init(void);
    virtual void Reset(void);
    virtual void * Update(void);
    virtual void Message(MKMessage *);
    Chest(void);
    void SetState(int);
    /* 0x0e0 */ s32 unkE0;
    /* 0x0e4 */ s32 unkE4;
    /* 0x0e8 */ f32 unkE8;
};

class ChestDescriptor : public TrapDescriptor {  // base: base ctor call
public:
    virtual void LoadDone(void);
    ChestDescriptor(void);
    /* 0x0e8 */ s32 unkE8;
    /* 0x0ec */ s32 unkEC;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#include <m2c_macros.h>

#if 0 // DRAFT: undefined identifier '__vt'
inline Chest::~Chest() {
    M2C_FIELD(this, s32 **, 0xC8) = &__vt.unk48;
}
#endif

#if 0 // DRAFT: undefined identifier '__vt'
inline Chest::Chest() {
    M2C_FIELD(this, void **, 0xC8) = (void *) (&__vt + 0x48);
}
#endif

inline ChestDescriptor::ChestDescriptor() {
}

#endif  // SPYRO_SOURCE_CHEST_H
