#ifndef SPYRO_SOURCE_UITEXT_H
#define SPYRO_SOURCE_UITEXT_H

#include <dolphin/types.h>
#include "spyro/source/UIObject.h"

class MKFont;
class RenderContext;
class UIDataLine;
class UIObject;
class UIText;

class UIText : public UIObject {  // base: ctor/dtor vtable stores
public:
    virtual void Init(void);
    virtual void Deinit(void);
    virtual s32 LoadLine(UIDataLine *);
    virtual void Update(void);
    virtual void Draw(const RenderContext &);
    virtual void LoadResources(void);
    virtual void FreeResources(void);
    void GetStringWidth(void);
    static u8 descriptor[0x14];
    /* 0x060 */ s8* unk60;
    /* 0x064 */ MKFont* unk64;
    /* 0x068 */ s8* unk68;
    /* 0x06c */ s32 unk6C;
    /* 0x070 */ f32 unk70;
    /* 0x074 */ f32 unk74;
};

#endif  // SPYRO_SOURCE_UITEXT_H
