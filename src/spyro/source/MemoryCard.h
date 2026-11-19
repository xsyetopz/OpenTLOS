#ifndef SPYRO_SOURCE_MEMORYCARD_H
#define SPYRO_SOURCE_MEMORYCARD_H

#include <dolphin/types.h>
#include "spyro/source/UIScreen.h"
#include "spyro/source/UITools.h"

class DSText;
class MCSaveScreen;
class MCText;
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
    /* 0x0c8 */ UIContainer* unkC8;
};

class MCSaveScreen : public MemoryCardScreen {  // base: base ctor call
public:
    virtual void Update(void);
    virtual void OnEnter(void);
    MCSaveScreen(void);
    static u8 descriptor[0x14];
};

class MCText : public DSText {  // base: ctor/dtor vtable stores
public:
    virtual void Draw(const RenderContext &);
    MCText(void);
    static u8 descriptor[0x14];
};

s32 MemoryCard_GetSaveGameBlockSize(void);
void MemoryCard_DeinitModule(void);
void MemoryCard_InitModule(void);
// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#include <m2c_macros.h>

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline MCSaveScreen::MCSaveScreen() {
    return this;
}
#endif

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline MCText::MCText() {
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier 'ui_cast'
inline void MemoryCardScreen::PopScreen() {
    s32 sp8;
    UISystem *temp_r3_131;

    temp_r3_131 = ui_cast<UISystem *, UIContainer *>(GetRoot());
    sp8 = 0xF;
    M2C_FIELD(temp_r3_131->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp8);
}
#endif

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline MemoryCardScreen::MemoryCardScreen() {
    this->unk68.unk0 = NULL;
    this->unk68.unk4 = 0;
    this->unk68.unk8 = NULL;
    this->unk74.unk0 = NULL;
    this->unk74.unk4 = 0;
    this->unk74.unk8 = NULL;
    this->unk80.unk0 = NULL;
    this->unk80.unk4 = 0;
    this->unk80.unk8 = NULL;
    this->unk8C.unk0 = NULL;
    this->unk8C.unk4 = 0;
    this->unk8C.unk8 = NULL;
    this->unk98.unk0 = NULL;
    this->unk98.unk4 = 0;
    this->unk98.unk8 = NULL;
    this->unkA4.unk0 = NULL;
    this->unkA4.unk4 = 0;
    this->unkA4.unk8 = NULL;
    this->unkB0.unk0 = NULL;
    this->unkB0.unk4 = 0;
    this->unkB0.unk8 = NULL;
    this->unkBC.unk0 = NULL;
    this->unkBC.unk4 = 0;
    this->unkBC.unk8 = NULL;
    return this;
}
#endif

#endif  // SPYRO_SOURCE_MEMORYCARD_H
