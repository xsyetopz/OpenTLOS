#ifndef SPYRO_SOURCE_UIATTRIBUTES_H
#define SPYRO_SOURCE_UIATTRIBUTES_H

#include <dolphin/types.h>
#include "common/Source/MKVector3.h"

class Attributes;
class MKVector3;
class RenderContext;
class UIDataLine;

class Attributes {
public:
    s32 LoadLine(UIDataLine *);
    void Tween(Attributes *, Attributes *, float);
    void SetIdentity(void);
    /* 0x000 */ f32 unk0;
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ f64 unk8;
    /* 0x010 */ MKVector3 unk10;
    /* 0x020 */ MKVector3 unk20;
    /* 0x030 */ f32 unk30;
    /* 0x034 */ f32 unk34;
    /* 0x038 */ f32 unk38;
    /* 0x03c */ s32 unk3C;
    /* 0x040 */ u16 unk40;
};

class RenderContext {
public:
    RenderContext * AddState(const Attributes &);
    void AddState(const RenderContext &, const Attributes &);
    RenderContext(const RenderContext &, const Attributes &);
    RenderContext(void);
    /* 0x000 */ f32 unk0;
    /* 0x004 */ f32 unk4;
    /* 0x008 */ f32 unk8;
    /* 0x00c */ u8 padC[0x4];
    /* 0x010 */ f32 unk10;
    /* 0x014 */ f32 unk14;
    /* 0x018 */ f32 unk18;
    /* 0x01c */ u8 pad1C[0x4];
    /* 0x020 */ f32 unk20;
    /* 0x024 */ f32 unk24;
    /* 0x028 */ f32 unk28;
    /* 0x02c */ u8 pad2C[0x14];
    /* 0x040 */ f64 unk40;
    /* 0x048 */ f64 unk48;
};

#endif  // SPYRO_SOURCE_UIATTRIBUTES_H
