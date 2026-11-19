#ifndef SPYRO_SOURCE_MCSELECTFILESCREEN_H
#define SPYRO_SOURCE_MCSELECTFILESCREEN_H

#include <dolphin/types.h>
#include "spyro/source/MemoryCard.h"

class MCSelectFileScreen;
class MemoryCardScreen;

class MCSelectFileScreen : public MemoryCardScreen {  // base: vtable prefix
public:
    virtual void Init(void);
    virtual void Update(void);
    virtual void Resolve(void);
    virtual void OnEnter(void);
    MCSelectFileScreen(void);
    static u8 descriptor[0x14];
    /* 0x004 */ u8 pad4[0xc4];
    /* 0x0c8 */ void** unkC8;
    /* 0x0cc */ u8 padCC[0x4];
    /* 0x0d0 */ void** unkD0;
    /* 0x0d4 */ void** unkD4;
    /* 0x0d8 */ void** unkD8;
    /* 0x0dc */ void* unkDC;
    /* 0x0e0 */ void** unkE0;
    /* 0x0e4 */ void** unkE4;
    /* 0x0e8 */ void** unkE8;
};

#endif  // SPYRO_SOURCE_MCSELECTFILESCREEN_H
