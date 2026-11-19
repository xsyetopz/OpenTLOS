#ifndef SPYRO_SOURCE_MCLOADCHECKSCREEN_H
#define SPYRO_SOURCE_MCLOADCHECKSCREEN_H

#include <dolphin/types.h>
#include "spyro/source/MemoryCard.h"

class MCLoadCheckScreen;
class MemoryCardScreen;

class MCLoadCheckScreen : public MemoryCardScreen {  // base: base ctor call
public:
    virtual void Init(void);
    virtual void Update(void);
    virtual void Resolve(void);
    virtual void OnEnter(void);
    MCLoadCheckScreen(void);
    static u8 descriptor[0x14];
    /* 0x0d0 */ s32 unkD0;
    /* 0x0d4 */ void** unkD4;
    /* 0x0d8 */ void** unkD8;
    /* 0x0dc */ void** unkDC;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline MCLoadCheckScreen::MCLoadCheckScreen() {
}

#endif  // SPYRO_SOURCE_MCLOADCHECKSCREEN_H
