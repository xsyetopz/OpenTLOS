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
    /* 0x0c8 */ KDSoundFader unkC8;
    /* 0x13c */ u8 pad13C[0x4];
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

#endif  // SPYRO_SOURCE_LEVELUPSCREEN_H
