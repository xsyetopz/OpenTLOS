#ifndef SPYRO_SOURCE_MAINMENUSCREEN_H
#define SPYRO_SOURCE_MAINMENUSCREEN_H

#include <dolphin/types.h>
#include "spyro/source/UIScreen.h"

class KDMemoryCard;
class MainMenuScreen;
class UIContainer;
class UIScreen;

class MainMenuScreen : public UIScreen {  // base: ctor/dtor vtable stores
public:
    virtual void Update(void);
    virtual void OnEnter(void);
    virtual void OnExit(void);
    MainMenuScreen(void);
    static u8 descriptor[0x14];
    /* 0x0c8 */ s32 unkC8;
    /* 0x0cc */ KDMemoryCard* unkCC;
    /* 0x0d0 */ KDMemoryCard* unkD0;
    /* 0x0d4 */ f32 unkD4;
    /* 0x0d8 */ UIContainer* unkD8;
};

extern u8 selectedIndex[0x4];
// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline MainMenuScreen::MainMenuScreen() {
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

#endif  // SPYRO_SOURCE_MAINMENUSCREEN_H
