#ifndef SPYRO_SOURCE_UIREFERENCE_H
#define SPYRO_SOURCE_UIREFERENCE_H

#include <dolphin/types.h>
#include "spyro/source/UIAttributes.h"
#include "spyro/source/UIObject.h"

class Attributes;
class RenderContext;
class UIDataLine;
class UIObject;
class UIReference;

class UIReference : public UIObject {  // base: vtable prefix
public:
    virtual void Init(void);
    virtual s32 LoadLine(UIDataLine *);
    virtual void Draw(const RenderContext &);
    virtual void LoadResources(void);
    virtual void FreeResources(void);
    virtual void Resolve(void);
    static u8 descriptor[0x14];
    /* 0x004 */ u8 pad4[0x14];
    /* 0x018 */ Attributes unk18;
    /* 0x05a */ u8 pad5A[0x6];
    /* 0x060 */ void** unk60;
    /* 0x064 */ u8 unk64;
};

#endif  // SPYRO_SOURCE_UIREFERENCE_H
