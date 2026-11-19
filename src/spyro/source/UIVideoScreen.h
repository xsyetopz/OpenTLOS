#ifndef SPYRO_SOURCE_UIVIDEOSCREEN_H
#define SPYRO_SOURCE_UIVIDEOSCREEN_H

#include <dolphin/types.h>
#include "spyro/source/UIScreen.h"

class GameVideo;
class RenderContext;
class UIDataLine;
class UIMessage;
class UIScreen;
class UIVideoScreen;

class UIVideoScreen : public UIScreen {  // base: ctor/dtor vtable stores
public:
    virtual void Init(void);
    virtual void Deinit(void);
    virtual s32 LoadLine(UIDataLine *);
    virtual void Update(void);
    virtual void Draw(const RenderContext &);
    virtual void Resolve(void);
    virtual s32 Message(UIMessage *);
    virtual void OnEnter(void);
    virtual void OnExit(void);
    virtual void DoExit(void);
    UIVideoScreen(void);
    static u8 descriptor[0x14];
    /* 0x0c8 */ s32 unkC8;
    /* 0x0cc */ u8 padCC[0x8];
    /* 0x0d4 */ s32 unkD4;
    /* 0x0d8 */ u8 padD8[0x8];
    /* 0x0e0 */ s8* unkE0;
    /* 0x0e4 */ GameVideo* unkE4;
    /* 0x0e8 */ f32 unkE8;
    /* 0x0ec */ f32 unkEC;
    /* 0x0f0 */ s32 unkF0;
    /* 0x0f4 */ u8 unkF4;
    /* 0x0f5 */ u8 unkF5;
    /* 0x0f6 */ u8 padF6[0x2];
    /* 0x0f8 */ u8 unkF8;
    /* 0x0f9 */ u8 unkF9;
    /* 0x0fa */ u8 unkFA;
    /* 0x0fb */ u8 unkFB;
    /* 0x0fc */ f32 unkFC;
    /* 0x100 */ f32 unk100;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline void UIVideoScreen::DoExit() {

}

#if 0 // DRAFT: undefined identifier 'unkCC'
inline UIVideoScreen::UIVideoScreen() {
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
    this->unkC8 = 0;
    this->unkCC = 0;
    this->unkD0 = 0;
    this->unkD4 = 0;
    this->unkD8 = 0;
    this->unkDC = 0;
}
#endif

#endif  // SPYRO_SOURCE_UIVIDEOSCREEN_H
