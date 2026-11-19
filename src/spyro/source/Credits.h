#ifndef SPYRO_SOURCE_CREDITS_H
#define SPYRO_SOURCE_CREDITS_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/UIScreen.h"

class CreditsProp;
class CreditsScreen;
class EventMessage;
class MKIniLine;
class MKMessage;
class MKProp;
class RenderContext;
class UIScreen;

class CreditsProp : public MKProp {  // base: ctor/dtor vtable stores
public:
    virtual ~CreditsProp(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void Deinit(void);
    virtual void Message(MKMessage *);
    /* 0x04c */ EventMessage unk4C;
};

class CreditsScreen : public UIScreen {  // base: ctor/dtor vtable stores
public:
    virtual void Update(void);
    virtual void Draw(const RenderContext &);
    virtual void OnEnter(void);
    virtual void OnExit(void);
    CreditsScreen(void);
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
};

s32 Credits_Active(void);
void Credits_Message(MKMessage *);
void Credits_Draw(void);
s32 Credits_Update(void);
void Credits_Deinit(void);
void Credits_Init(MKProp *);
#endif  // SPYRO_SOURCE_CREDITS_H
