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
    virtual void Message(UIMessage *);
    virtual void OnEnter(void);
    virtual void OnExit(void);
    virtual void DoExit(void);
    UIVideoScreen(void);
    /* 0x004 */ u8 pad4[0xc4];
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

#endif  // SPYRO_SOURCE_UIVIDEOSCREEN_H
