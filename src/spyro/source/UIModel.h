#ifndef SPYRO_SOURCE_UIMODEL_H
#define SPYRO_SOURCE_UIMODEL_H

#include <dolphin/types.h>
#include "common/Source/MKAnimScript.h"
#include "spyro/source/UIAttributes.h"
#include "spyro/source/UIObject.h"

class Attributes;
class MKAnimScript;
class MKModel;
class RenderContext;
class UIAnimatedModel;
class UIDataLine;
class UIModel;
class UIObject;

class UIAnimatedModel : public UIObject {  // base: vtable prefix
public:
    virtual void Update(void);
    virtual void LoadResources(void);
    virtual void FreeResources(void);
    static u8 descriptor[0x14];
    /* 0x004 */ u8 pad4[0x11];
    /* 0x015 */ u8 unk15;
    /* 0x016 */ u8 pad16[0x4a];
    /* 0x060 */ s8* unk60;
    /* 0x064 */ MKModel* unk64;
    /* 0x068 */ MKAnimScript unk68;
};

class UIModel : public UIObject {  // base: vtable prefix
public:
    virtual void Init(void);
    virtual void Deinit(void);
    virtual s32 LoadLine(UIDataLine *);
    virtual void Update(void);
    virtual void Draw(const RenderContext &);
    virtual void LoadResources(void);
    virtual void FreeResources(void);
    void UpdateMatrix(RenderContext *);
    static u8 descriptor[0x14];
    /* 0x004 */ u8 pad4[0x14];
    /* 0x018 */ Attributes unk18;
    /* 0x05a */ u8 pad5A[0x6];
    /* 0x060 */ s8* unk60;
    /* 0x064 */ MKModel* unk64;
};

#endif  // SPYRO_SOURCE_UIMODEL_H
