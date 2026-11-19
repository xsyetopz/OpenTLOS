#ifndef SPYRO_SOURCE_MEMORYCARD_H
#define SPYRO_SOURCE_MEMORYCARD_H

#include <dolphin/types.h>
#include "spyro/source/UIAttributes.h"
#include "spyro/source/UIScreen.h"
#include "spyro/source/UITools.h"

class Attributes;
class DSText;
class MCSaveScreen;
class MCText;
class MKFont;
class MemoryCardScreen;
class RenderContext;
class UIContainer;
class UIScreen;

class MemoryCardScreen : public UIScreen {  // base: ctor/dtor vtable stores
public:
    virtual void Init(void);
    virtual void Resolve(void);
    virtual void OnEnter(void);
    virtual void OnExit(void);
    void PopScreen(void);
    MemoryCardScreen(void);
    void ExamineCard(void);
    static u8 selectedFile[0x4];
    static u8 operation[0x4];
    static u8 selectedCard[0x4];
    static u8 bNewGame[0x1];
    /* 0x004 */ u8 pad4[0xc4];
    /* 0x0c8 */ UIContainer* unkC8;
};

class MCSaveScreen : public MemoryCardScreen {  // base: vtable prefix
public:
    virtual void Update(void);
    virtual void OnEnter(void);
    MCSaveScreen(void);
    static u8 descriptor[0x14];
    /* 0x004 */ s8* unk4;
};

class MCText : public DSText {  // base: ctor/dtor vtable stores
public:
    virtual void Draw(const RenderContext &);
    MCText(void);
    static u8 descriptor[0x14];
    /* 0x004 */ u8 pad4[0x14];
    /* 0x018 */ Attributes unk18;
    /* 0x05a */ u8 pad5A[0xa];
    /* 0x064 */ MKFont* unk64;
    /* 0x068 */ u8 pad68[0x4];
    /* 0x06c */ s32 unk6C;
    /* 0x070 */ f32 unk70;
    /* 0x074 */ f32 unk74;
};

s32 MemoryCard_GetSaveGameBlockSize(void);
void MemoryCard_DeinitModule(void);
void MemoryCard_InitModule(void);
#endif  // SPYRO_SOURCE_MEMORYCARD_H
