#ifndef SPYRO_SOURCE_LEVELSELECT_H
#define SPYRO_SOURCE_LEVELSELECT_H

#include <dolphin/types.h>
#include "spyro/source/UIScreen.h"
#include "spyro/source/UITools.h"

class LevelButton;
class LevelSelectButtons;
class LevelSelectScreen;
class MarkerButtonGroup;
class RenderContext;
class ThrobButton;
class UIScreen;

class LevelButton : public ThrobButton {  // base: base ctor call
public:
    virtual void Init(void);
    LevelButton(void);
    static u8 descriptor[0x14];
    /* 0x0a0 */ s32 unkA0;
};

class LevelSelectButtons : public MarkerButtonGroup {  // base: base ctor call
public:
    virtual void Init(void);
    LevelSelectButtons(void);
    static u8 descriptor[0x14];
};

class LevelSelectScreen : public UIScreen {  // base: ctor/dtor vtable stores
public:
    virtual void Init(void);
    virtual void Deinit(void);
    virtual void LoadDone(void);
    virtual void Update(void);
    virtual void Draw(const RenderContext &);
    virtual void OnEnter(void);
    void Populate(void);
    LevelSelectScreen(void);
    static u8 descriptor[0x14];
    /* 0x0c8 */ void** unkC8;
};

extern u8 bZ3AttractHack;
// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline LevelButton::LevelButton() {
}

inline LevelSelectButtons::LevelSelectButtons() {
}

inline LevelSelectScreen::LevelSelectScreen() {
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

#endif  // SPYRO_SOURCE_LEVELSELECT_H
