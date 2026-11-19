#ifndef SPYRO_SOURCE_UIMODEL_H
#define SPYRO_SOURCE_UIMODEL_H

#include <dolphin/types.h>
#include "common/Source/MKAnimScript.h"
#include "spyro/source/UIObject.h"

class MKAnimScript;
class MKModel;
class RenderContext;
class UIAnimatedModel;
class UIDataLine;
class UIModel;
class UIObject;

class UIModel : public UIObject {  // base: inlined ctor vtable stores
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
    /* 0x060 */ s8* unk60;
    /* 0x064 */ MKModel* unk64;
};

class UIAnimatedModel : public UIModel {  // base: inlined ctor vtable stores
public:
    virtual void Update(void);
    virtual void LoadResources(void);
    virtual void FreeResources(void);
    static u8 descriptor[0x14];
    /* 0x068 */ MKAnimScript unk68;
};

#endif  // SPYRO_SOURCE_UIMODEL_H
