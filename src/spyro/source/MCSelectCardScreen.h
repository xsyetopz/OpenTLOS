#ifndef SPYRO_SOURCE_MCSELECTCARDSCREEN_H
#define SPYRO_SOURCE_MCSELECTCARDSCREEN_H

#include <dolphin/types.h>
#include "spyro/source/MemoryCard.h"

class MCSelectCardScreen;
class MemoryCardScreen;

class MCSelectCardScreen : public MemoryCardScreen {  // base: vtable prefix
public:
    virtual void Init(void);
    virtual void Update(void);
    virtual void Resolve(void);
    virtual void OnEnter(void);
    void ClearDisplay(void);
    void UpdateDisplay(void);
    MCSelectCardScreen(void);
    /* 0x004 */ u8 pad4[0xc4];
    /* 0x0c8 */ void** unkC8;
    /* 0x0cc */ u8 padCC[0x4];
    /* 0x0d0 */ s32 unkD0;
    /* 0x0d4 */ void** unkD4;
    /* 0x0d8 */ void** unkD8;
    /* 0x0dc */ void** unkDC;
    /* 0x0e0 */ void** unkE0;
    /* 0x0e4 */ void** unkE4;
    /* 0x0e8 */ void** unkE8;
    /* 0x0ec */ void** unkEC;
    /* 0x0f0 */ u8 unkF0;
};

#endif  // SPYRO_SOURCE_MCSELECTCARDSCREEN_H
