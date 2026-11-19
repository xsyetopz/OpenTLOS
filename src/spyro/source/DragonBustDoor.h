#ifndef SPYRO_SOURCE_DRAGONBUSTDOOR_H
#define SPYRO_SOURCE_DRAGONBUSTDOOR_H

#include <dolphin/types.h>
#include "spyro/source/Trap.h"

class DragonBustDoor;
class MKIniLine;
class MKMessage;
class Trap;

class DragonBustDoor : public Trap {  // base: vtable prefix
public:
    virtual ~DragonBustDoor(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Update(void);
    virtual void Draw(void);
    virtual void Message(MKMessage *);
    DragonBustDoor(void);
    /* 0x0e0 */ u8 padE0[0x8];
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

#if 0 // DRAFT: undefined identifier 'unkC8'
inline DragonBustDoor::DragonBustDoor() {
    this->unkC8 = &__vt + 0x48;
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier 'unkC8'
inline DragonBustDoor::~DragonBustDoor() {
    this->unkC8 = &__vt.unk48;
}
#endif

#endif  // SPYRO_SOURCE_DRAGONBUSTDOOR_H
