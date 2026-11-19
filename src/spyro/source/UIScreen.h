#ifndef SPYRO_SOURCE_UISCREEN_H
#define SPYRO_SOURCE_UISCREEN_H

#include <dolphin/types.h>
#include "spyro/source/UIContainer.h"
#include "spyro/source/UIMessage.h"

class UIContainer;
class UIDataLine;
class UIEvent;
class UIMessage;
class UIScreen;

class UIScreen : public UIContainer {  // base: ctor/dtor vtable stores
public:
    virtual s32 LoadLine(UIDataLine *);
    virtual void Update(void);
    virtual void Resolve(void);
    virtual void Message(UIMessage *);
    virtual void OnEnter(void);
    virtual void OnExit(void);
    virtual void OnUp(void);
    virtual void OnDown(void);
    virtual void OnLeft(void);
    virtual void OnRight(void);
    virtual void OnSelect(void);
    virtual void OnCancel(void);
    /* 0x004 */ u8 pad4[0x8];
    /* 0x00c */ void** unkC;
    /* 0x010 */ u8 pad10[0x58];
    /* 0x068 */ UIEvent unk68;
    /* 0x074 */ UIEvent unk74;
    /* 0x080 */ UIEvent unk80;
    /* 0x08c */ UIEvent unk8C;
    /* 0x098 */ UIEvent unk98;
    /* 0x0a4 */ UIEvent unkA4;
    /* 0x0b0 */ UIEvent unkB0;
    /* 0x0bc */ UIEvent unkBC;
};

#endif  // SPYRO_SOURCE_UISCREEN_H
