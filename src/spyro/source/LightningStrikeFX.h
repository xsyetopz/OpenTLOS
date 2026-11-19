#ifndef SPYRO_SOURCE_LIGHTNINGSTRIKEFX_H
#define SPYRO_SOURCE_LIGHTNINGSTRIKEFX_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"

class LightningStrikeFX;
class LightningStrikeFXDescriptor;
class MKIniLine;
class MKMaterial;
class MKProp;
class MKPropDescriptor;
class MKVector3;
class ManagedLight;

class LightningStrikeFX : public MKProp {  // base: ctor/dtor vtable stores
public:
    virtual ~LightningStrikeFX(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Update(void);
    virtual void Draw(void);
    void Strike(void);
    /* 0x04c */ MKVector3* unk4C;
    /* 0x050 */ s32 unk50;
    /* 0x054 */ u8 pad54[0xc];
    /* 0x060 */ f64 unk60;
    /* 0x068 */ f64 unk68;
    /* 0x070 */ f64 unk70;
    /* 0x078 */ f64 unk78;
    /* 0x080 */ u8 pad80[0x30];
    /* 0x0b0 */ f32 unkB0;
    /* 0x0b4 */ f32 unkB4;
    /* 0x0b8 */ f32 unkB8;
    /* 0x0bc */ f32 unkBC;
    /* 0x0c0 */ f32 unkC0;
    /* 0x0c4 */ f32 unkC4;
};

class LightningStrikeFXDescriptor : public MKPropDescriptor {  // base: inlined ctor vtable stores
public:
    class StrikeArc;
    virtual void Init(void);
    virtual void Deinit(void);
    virtual void Update(void);
    virtual void Resolve(void);
    void FlashLightningLight(const MKVector3 &);
    void SpawnStrikeArc(const MKVector3 &, const MKVector3 &, float, float);
    void DrawStrikeArc(LightningStrikeFXDescriptor::StrikeArc *);
    void DrawStrikeArcs(void);
    /* 0x044 */ u8 pad44[0x1c];
    /* 0x060 */ ManagedLight* unk60;
    /* 0x064 */ u8 pad64[0x14];
    /* 0x078 */ f64 unk78;
    /* 0x080 */ f64 unk80;
    /* 0x088 */ f64 unk88;
    /* 0x090 */ f32 unk90;
    /* 0x094 */ MKMaterial* unk94;
    /* 0x098 */ LightningStrikeFXDescriptor::StrikeArc** unk98;
    /* 0x09c */ u8 unk9C;
    /* 0x09d */ u8 pad9D[0x3];
    /* 0x0a0 */ f32 unkA0;
    /* 0x0a4 */ s32 unkA4;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline LightningStrikeFX::~LightningStrikeFX() {
    s32 temp_cr0_eq_15;

    temp_cr0_eq_15 = this == NULL;
    if (temp_cr0_eq_15 == 0) {
        if (temp_cr0_eq_15 == 0) {
        }
    }
}

#endif  // SPYRO_SOURCE_LIGHTNINGSTRIKEFX_H
