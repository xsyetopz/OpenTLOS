#ifndef SPYRO_SOURCE_MCLOADCHECKSCREEN_H
#define SPYRO_SOURCE_MCLOADCHECKSCREEN_H

#include <dolphin/types.h>
#include "spyro/source/MemoryCard.h"

class MCLoadCheckScreen;
class MemoryCardScreen;

class MCLoadCheckScreen : public MemoryCardScreen {  // base: vtable prefix
public:
    virtual void Init(void);
    virtual void Update(void);
    virtual void Resolve(void);
    virtual void OnEnter(void);
    MCLoadCheckScreen(void);
    /* 0x004 */ u8 pad4[0xcc];
    /* 0x0d0 */ s32 unkD0;
    /* 0x0d4 */ void** unkD4;
    /* 0x0d8 */ void** unkD8;
    /* 0x0dc */ void** unkDC;
};

#endif  // SPYRO_SOURCE_MCLOADCHECKSCREEN_H
