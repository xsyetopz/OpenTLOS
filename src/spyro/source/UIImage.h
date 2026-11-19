#ifndef SPYRO_SOURCE_UIIMAGE_H
#define SPYRO_SOURCE_UIIMAGE_H

#include <dolphin/types.h>
#include "spyro/source/UIAttributes.h"
#include "spyro/source/UIObject.h"

class Attributes;
class MKMaterial;
class RenderContext;
class UIDataLine;
class UIImage;
class UIObject;

class UIImage : public UIObject {  // base: ctor/dtor vtable stores
public:
    virtual void Init(void);
    virtual void Deinit(void);
    virtual s32 LoadLine(UIDataLine *);
    virtual void Update(void);
    virtual void Draw(const RenderContext &);
    virtual void LoadResources(void);
    virtual void FreeResources(void);
    void SetUVs(float, float, float, float);
    static u8 descriptor[0x14];
    /* 0x004 */ u8 pad4[0x14];
    /* 0x018 */ Attributes unk18;
    /* 0x05a */ u8 pad5A[0x6];
    /* 0x060 */ s8* unk60;
    /* 0x064 */ MKMaterial* unk64;
    /* 0x068 */ f32 unk68;
    /* 0x06c */ f32 unk6C;
    /* 0x070 */ f32 unk70;
    /* 0x074 */ f32 unk74;
};

#endif  // SPYRO_SOURCE_UIIMAGE_H
