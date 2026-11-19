#ifndef SPYRO_SOURCE_MCFILEINFO_H
#define SPYRO_SOURCE_MCFILEINFO_H

#include <dolphin/types.h>
#include "spyro/source/UIAttributes.h"
#include "spyro/source/UIContainer.h"

class Attributes;
class MCFileInfo;
class RenderContext;
class UIContainer;
class UIMessage;

class MCFileInfo : public UIContainer {  // base: vtable prefix
public:
    virtual void Init(void);
    virtual void Deinit(void);
    virtual void Draw(const RenderContext &);
    virtual void Resolve(void);
    virtual void Message(UIMessage *);
    void Reset(void);
    /* 0x004 */ u8* unk4;
    /* 0x008 */ u8 pad8[0x10];
    /* 0x018 */ Attributes unk18;
    /* 0x05a */ u8 pad5A[0x6];
    /* 0x060 */ void* unk60;
    /* 0x064 */ u8 pad64[0x4];
    /* 0x068 */ void* unk68;
    /* 0x06c */ void* unk6C;
    /* 0x070 */ void* unk70;
    /* 0x074 */ void* unk74;
    /* 0x078 */ s8 unk78;
    /* 0x079 */ u8 pad79[0xff];
    /* 0x178 */ s8 unk178;
    /* 0x179 */ u8 pad179[0x3f];
    /* 0x1b8 */ s8 unk1B8;
    /* 0x1b9 */ u8 pad1B9[0x5f];
    /* 0x218 */ s32 unk218;
};

#endif  // SPYRO_SOURCE_MCFILEINFO_H
