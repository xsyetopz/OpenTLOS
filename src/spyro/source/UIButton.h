#ifndef SPYRO_SOURCE_UIBUTTON_H
#define SPYRO_SOURCE_UIBUTTON_H

#include <dolphin/types.h>
#include "spyro/source/UIContainer.h"
#include "spyro/source/UIMessage.h"

class UIButton;
class UIButtonGroup;
class UIContainer;
class UIDataLine;
class UIEvent;
class UIMessage;

class UIButton : public UIContainer {  // base: ctor/dtor vtable stores
public:
    virtual s32 LoadLine(UIDataLine *);
    virtual void Update(void);
    virtual void Resolve(void);
    virtual s32 Message(UIMessage *);
    virtual void OnActivate(void);
    virtual void OnSelection(void);
    virtual void OnDeselection(void);
    virtual void SetColor(void);
    static u8 descriptor[0x14];
    /* 0x068 */ UIEvent unk68;
    /* 0x074 */ UIEvent unk74;
    /* 0x080 */ UIEvent unk80;
};

class UIButtonGroup : public UIContainer {  // base: ctor/dtor vtable stores
public:
    virtual void Init(void);
    virtual s32 LoadLine(UIDataLine *);
    virtual void Resolve(void);
    virtual s32 Message(UIMessage *);
    virtual s32 SetSelection(int);
    virtual void OnSelectionChanged(void);
    static u8 descriptor[0x14];
    /* 0x068 */ s32 unk68;
    /* 0x06c */ UIEvent unk6C;
};

#endif  // SPYRO_SOURCE_UIBUTTON_H
