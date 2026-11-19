#ifndef SPYRO_SOURCE_LANGUAGESELECTSCREEN_H
#define SPYRO_SOURCE_LANGUAGESELECTSCREEN_H

#include <dolphin/types.h>
#include "spyro/source/UIScreen.h"

class LanguageSelectScreen;
class LanguageSelectScreen_cpp;
class UIScreen;

class LanguageSelectScreen : public UIScreen {  // base: ctor/dtor vtable stores
public:
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Update(void);
    virtual void OnEnter(void);
    LanguageSelectScreen(void);
    static u8 descriptor[0x14];
    /* 0x0c8 */ void** unkC8;
    /* 0x0cc */ s32 unkCC;
};

class LanguageSelectScreen_cpp {
public:
    void __sinit(void);
};

void NoController_Draw(void);
void NoController_Update(void);
void ControllerInit_Update(void);
void Language_Draw(void);
void Language_Update(void);
void Language_Deinit(void);
void Language_Init(void);
// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline LanguageSelectScreen::LanguageSelectScreen() {
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
}

#endif  // SPYRO_SOURCE_LANGUAGESELECTSCREEN_H
