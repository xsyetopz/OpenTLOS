#ifndef SPYRO_SOURCE_PAUSEMAINSCREEN_H
#define SPYRO_SOURCE_PAUSEMAINSCREEN_H

#include <dolphin/types.h>
#include "spyro/source/UIScreen.h"

class ExitConfirmScreen;
class PauseMainScreen;
class UIContainer;
class UIScreen;

class ExitConfirmScreen : public UIScreen {  // base: ctor/dtor vtable stores
public:
    virtual void Init(void);
    virtual void Update(void);
    virtual void Resolve(void);
    virtual void OnEnter(void);
    ExitConfirmScreen(void);
    static u8 descriptor[0x14];
    /* 0x0c8 */ void** unkC8;
    /* 0x0cc */ s32 unkCC;
};

class PauseMainScreen : public UIScreen {  // base: ctor/dtor vtable stores
public:
    virtual void LoadDone(void);
    virtual void Update(void);
    virtual void Resolve(void);
    virtual void OnEnter(void);
    virtual void OnExit(void);
    PauseMainScreen(void);
    static u8 descriptor[0x14];
    /* 0x0c8 */ UIContainer* unkC8;
    /* 0x0cc */ s32 unkCC;
    /* 0x0d0 */ u8 unkD0;
    /* 0x0d1 */ u8 unkD1;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline ExitConfirmScreen::ExitConfirmScreen() {
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

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline PauseMainScreen::PauseMainScreen() {
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

#endif  // SPYRO_SOURCE_PAUSEMAINSCREEN_H
