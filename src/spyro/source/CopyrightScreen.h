#ifndef SPYRO_SOURCE_COPYRIGHTSCREEN_H
#define SPYRO_SOURCE_COPYRIGHTSCREEN_H

#include <dolphin/types.h>
#include "spyro/source/UIScreen.h"

class CopyrightScreen;
class KDMemoryCard;
class UIScreen;

class CopyrightScreen : public UIScreen {  // base: ctor/dtor vtable stores
public:
    virtual void Update(void);
    virtual void OnEnter(void);
    CopyrightScreen(void);
    static u8 descriptor[0x14];
    static u8 bMemoryCardCheckDone[0x1];
    /* 0x0c8 */ s32 unkC8;
    /* 0x0cc */ f32 unkCC;
    /* 0x0d0 */ s32 unkD0;
    /* 0x0d4 */ KDMemoryCard* unkD4;
    /* 0x0d8 */ KDMemoryCard* unkD8;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline CopyrightScreen::CopyrightScreen() {
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

#endif  // SPYRO_SOURCE_COPYRIGHTSCREEN_H
