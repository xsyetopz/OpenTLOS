#ifndef SPYRO_SOURCE_LEVELUPSCREEN_H
#define SPYRO_SOURCE_LEVELUPSCREEN_H

#include <dolphin/types.h>
#include "spyro/source/KDSound.h"
#include "spyro/source/UIScreen.h"

class DialogBoxContext;
class KDSoundFader;
class LevelUpScreen;
class LevelUpScreen_cpp;
class RenderContext;
class UIScreen;
class UpgradeBar;

class LevelUpScreen : public UIScreen {  // base: ctor/dtor vtable stores
public:
    virtual void Init(void);
    virtual void Deinit(void);
    virtual void Update(void);
    virtual void Draw(const RenderContext &);
    virtual void OnEnter(void);
    virtual void OnExit(void);
    void SetBreathText(void);
    LevelUpScreen(void);
    static u8 descriptor[0x14];
    /* 0x0c8 */ KDSoundFader unkC8;
    /* 0x140 */ DialogBoxContext* unk140;
    /* 0x144 */ DialogBoxContext* unk144;
    /* 0x148 */ f32 unk148;
    /* 0x14c */ s32 unk14C;
    /* 0x150 */ s32 unk150;
    /* 0x154 */ u8 unk154;
    /* 0x155 */ u8 unk155;
    /* 0x156 */ u8 unk156;
};

class LevelUpScreen_cpp {
public:
    void __sinit(void);
};

class UpgradeBar {
public:
    /* 0x000 */ f32 unk0;
    /* 0x004 */ f32 unk4;
    /* 0x008 */ f32 unk8;
    /* 0x00c */ f32 unkC;
    /* 0x010 */ f32 unk10;
    /* 0x014 */ f32 unk14;
    /* 0x018 */ f32 unk18;
    /* 0x01c */ f32 unk1C;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#include <m2c_macros.h>

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline LevelUpScreen::LevelUpScreen() {
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
    this->unkC8.unk0 = 0;
    M2C_FIELD(this, s32 *, 0xF0) = 0;
    this->unkC8.unk50 = 0.0f;
    return this;
}
#endif

#endif  // SPYRO_SOURCE_LEVELUPSCREEN_H
