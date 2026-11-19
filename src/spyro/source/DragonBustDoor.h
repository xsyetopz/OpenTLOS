#ifndef SPYRO_SOURCE_DRAGONBUSTDOOR_H
#define SPYRO_SOURCE_DRAGONBUSTDOOR_H

#include <dolphin/types.h>
#include "spyro/source/Door.h"

class Door;
class DragonBustDoor;
class MKIniLine;
class MKMessage;

class DragonBustDoor : public Door {  // base: base ctor call
public:
    virtual ~DragonBustDoor(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual s32 LoadDone(void);
    virtual void Deinit(void);
    virtual void * Update(void);
    virtual void Draw(void);
    virtual void Message(MKMessage *);
    DragonBustDoor(void);
    /* 0x0e8 */ s32 unkE8;
    /* 0x0ec */ s32 unkEC;
    /* 0x0f0 */ s32 unkF0;
    /* 0x0f4 */ s32 unkF4;
    /* 0x0f8 */ s32 unkF8;
    /* 0x0fc */ s32 unkFC;
    /* 0x100 */ s32 unk100;
    /* 0x104 */ s32 unk104;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#include <m2c_macros.h>

#if 0 // DRAFT: undefined identifier '__vt'
inline DragonBustDoor::DragonBustDoor() {
    M2C_FIELD(this, void **, 0xC8) = (void *) (&__vt + 0x48);
}
#endif

#if 0 // DRAFT: undefined identifier '__vt'
inline DragonBustDoor::~DragonBustDoor() {
    M2C_FIELD(this, s32 **, 0xC8) = &__vt.unk48;
}
#endif

#endif  // SPYRO_SOURCE_DRAGONBUSTDOOR_H
