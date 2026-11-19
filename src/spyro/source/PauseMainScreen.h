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
    /* 0x004 */ s32 unk4;
    /* 0x008 */ u8 pad8[0x60];
    /* 0x068 */ s32 unk68;
    /* 0x06c */ s32 unk6C;
    /* 0x070 */ s32 unk70;
    /* 0x074 */ s32 unk74;
    /* 0x078 */ s32 unk78;
    /* 0x07c */ s32 unk7C;
    /* 0x080 */ s32 unk80;
    /* 0x084 */ s32 unk84;
    /* 0x088 */ s32 unk88;
    /* 0x08c */ s32 unk8C;
    /* 0x090 */ s32 unk90;
    /* 0x094 */ s32 unk94;
    /* 0x098 */ s32 unk98;
    /* 0x09c */ s32 unk9C;
    /* 0x0a0 */ s32 unkA0;
    /* 0x0a4 */ s32 unkA4;
    /* 0x0a8 */ s32 unkA8;
    /* 0x0ac */ s32 unkAC;
    /* 0x0b0 */ s32 unkB0;
    /* 0x0b4 */ s32 unkB4;
    /* 0x0b8 */ s32 unkB8;
    /* 0x0bc */ s32 unkBC;
    /* 0x0c0 */ s32 unkC0;
    /* 0x0c4 */ s32 unkC4;
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
    /* 0x004 */ u8 pad4[0x64];
    /* 0x068 */ s32 unk68;
    /* 0x06c */ s32 unk6C;
    /* 0x070 */ s32 unk70;
    /* 0x074 */ s32 unk74;
    /* 0x078 */ s32 unk78;
    /* 0x07c */ s32 unk7C;
    /* 0x080 */ s32 unk80;
    /* 0x084 */ s32 unk84;
    /* 0x088 */ s32 unk88;
    /* 0x08c */ s32 unk8C;
    /* 0x090 */ s32 unk90;
    /* 0x094 */ s32 unk94;
    /* 0x098 */ s32 unk98;
    /* 0x09c */ s32 unk9C;
    /* 0x0a0 */ s32 unkA0;
    /* 0x0a4 */ s32 unkA4;
    /* 0x0a8 */ s32 unkA8;
    /* 0x0ac */ s32 unkAC;
    /* 0x0b0 */ s32 unkB0;
    /* 0x0b4 */ s32 unkB4;
    /* 0x0b8 */ s32 unkB8;
    /* 0x0bc */ s32 unkBC;
    /* 0x0c0 */ s32 unkC0;
    /* 0x0c4 */ s32 unkC4;
    /* 0x0c8 */ UIContainer* unkC8;
    /* 0x0cc */ s32 unkCC;
    /* 0x0d0 */ u8 unkD0;
    /* 0x0d1 */ u8 unkD1;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: expression syntax error
inline ExitConfirmScreen::ExitConfirmScreen() {
    this->unk60 = NULL;
    this->unk64 = 0;
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
    return this;
}
#endif

#if 0 // DRAFT: expression syntax error
inline PauseMainScreen::PauseMainScreen() {
    this->unk60 = NULL;
    this->unk64 = 0;
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
    return this;
}
#endif

#endif  // SPYRO_SOURCE_PAUSEMAINSCREEN_H
