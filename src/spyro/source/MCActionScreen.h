#ifndef SPYRO_SOURCE_MCACTIONSCREEN_H
#define SPYRO_SOURCE_MCACTIONSCREEN_H

#include <dolphin/types.h>
#include "spyro/source/MemoryCard.h"

class MCActionScreen;
class MemoryCardScreen;

class MCActionScreen : public MemoryCardScreen {  // base: vtable prefix
public:
    virtual void Init(void);
    virtual void Update(void);
    virtual void LoadResources(void);
    virtual void FreeResources(void);
    virtual void Resolve(void);
    virtual void OnEnter(void);
    void Abort(void);
    MCActionScreen(void);
    static u8 descriptor[0x14];
    static u8 action[0x4];
    /* 0x004 */ u8 pad4[0xc4];
    /* 0x0c8 */ void** unkC8;
    /* 0x0cc */ u8 padCC[0x4];
    /* 0x0d0 */ void** unkD0;
    /* 0x0d4 */ void** unkD4;
    /* 0x0d8 */ void** unkD8;
    /* 0x0dc */ void** unkDC;
    /* 0x0e0 */ void* unkE0;
    /* 0x0e4 */ void** unkE4;
    /* 0x0e8 */ void* unkE8;
    /* 0x0ec */ void* unkEC;
    /* 0x0f0 */ f32 unkF0;
    /* 0x0f4 */ s32 unkF4;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline MCActionScreen::MCActionScreen() {
    return this;
}
#endif

#endif  // SPYRO_SOURCE_MCACTIONSCREEN_H
