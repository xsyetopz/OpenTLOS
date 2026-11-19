#ifndef SPYRO_SOURCE_MCFILEINFO_H
#define SPYRO_SOURCE_MCFILEINFO_H

#include <dolphin/types.h>
#include "spyro/source/UIContainer.h"

class MCFileInfo;
class RenderContext;
class UIContainer;
class UIMessage;

class MCFileInfo : public UIContainer {  // base: inlined ctor vtable stores
public:
    virtual void Init(void);
    virtual void Deinit(void);
    virtual void Draw(const RenderContext &);
    virtual void Resolve(void);
    virtual s32 Message(UIMessage *);
    void Reset(void);
    static u8 descriptor[0x14];
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
