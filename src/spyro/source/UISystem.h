#ifndef SPYRO_SOURCE_UISYSTEM_H
#define SPYRO_SOURCE_UISYSTEM_H

#include <dolphin/types.h>
#include "spyro/source/UIContainer.h"

class RenderContext;
class UIContainer;
class UIMessage;
class UIScreen;
class UISystem;

class UISystem : public UIContainer {  // base: ctor/dtor vtable stores
public:
    virtual void Init(void);
    virtual void Deinit(void);
    virtual void Update(void);
    virtual void Draw(const RenderContext &);
    virtual void Message(UIMessage *);
    void ClearStack(UIScreen *);
    void PopScreen_Internal(void);
    void PushScreen_Internal(UIScreen *);
    void PushScreen(const char *);
    void ChangeScreen_Internal(UIScreen *);
    void ChangeScreen(const char *);
    void DoTransition(void);
    void ProvokeTransition(void);
    static u8 descriptor[0x14];
    /* 0x068 */ s32 unk68;
    /* 0x06c */ s32 unk6C;
    /* 0x070 */ u8 pad70[0x24];
    /* 0x094 */ UIScreen* unk94;
    /* 0x098 */ void* unk98;
    /* 0x09c */ u8 unk9C;
    /* 0x09d */ u8 unk9D;
    /* 0x09e */ u8 unk9E;
};

#endif  // SPYRO_SOURCE_UISYSTEM_H
