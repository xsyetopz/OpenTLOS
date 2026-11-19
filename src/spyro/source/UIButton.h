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
    virtual void Message(UIMessage *);
    virtual void OnActivate(void);
    virtual void OnSelection(void);
    virtual void OnDeselection(void);
    virtual void SetColor(void);
    /* 0x004 */ u8 pad4[0x11];
    /* 0x015 */ u8 unk15;
    /* 0x016 */ u8 unk16;
    /* 0x017 */ u8 pad17[0x1];
    /* 0x018 */ f32 unk18;
    /* 0x01c */ f32 unk1C;
    /* 0x020 */ f32 unk20;
    /* 0x024 */ u8 pad24[0x34];
    /* 0x058 */ u16 unk58;
    /* 0x05a */ u8 pad5A[0xe];
    /* 0x068 */ UIEvent unk68;
    /* 0x074 */ UIEvent unk74;
    /* 0x080 */ UIEvent unk80;
};

class UIButtonGroup : public UIContainer {  // base: ctor/dtor vtable stores
public:
    virtual void Init(void);
    virtual s32 LoadLine(UIDataLine *);
    virtual void Resolve(void);
    virtual void Message(UIMessage *);
    virtual s32 SetSelection(int);
    virtual void OnSelectionChanged(void);
    /* 0x004 */ u8 pad4[0x11];
    /* 0x015 */ u8 unk15;
    /* 0x016 */ u8 pad16[0x4e];
    /* 0x064 */ s32 unk64;
    /* 0x068 */ s32 unk68;
    /* 0x06c */ UIEvent unk6C;
};

#endif  // SPYRO_SOURCE_UIBUTTON_H
