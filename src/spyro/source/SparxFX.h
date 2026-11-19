#ifndef SPYRO_SOURCE_SPARXFX_H
#define SPYRO_SOURCE_SPARXFX_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"

class MKAnimScript;
class MKMaterial;
class MKProp;
class MKVector3;
class MKVector4;
class ManagedLight;
class Matrix;
class SparxFX;

class SparxFX : public MKProp {  // base: ctor/dtor vtable stores
public:
    virtual ~SparxFX(void);
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Update(void);
    virtual void Draw(void);
    virtual void Enable(void);
    virtual void Disable(void);
    void SetColor(const MKVector4 &);
    void DrawGlow(MKMaterial *, float, float, MKVector4, Matrix *, bool);
    void SetSparxPos(const MKVector3 &);
    void GetGlowDrawParams(float &, float &);
    /* 0x04c */ u8 pad4C[0x4];
    /* 0x050 */ f32 unk50;
    /* 0x054 */ f32 unk54;
    /* 0x058 */ f32 unk58;
    /* 0x05c */ u8 pad5C[0xc];
    /* 0x068 */ f32 unk68;
    /* 0x06c */ f32 unk6C;
    /* 0x070 */ f32 unk70;
    /* 0x074 */ u8 pad74[0x4];
    /* 0x078 */ f64 unk78;
    /* 0x080 */ f64 unk80;
    /* 0x088 */ f32 unk88;
    /* 0x08c */ u8 unk8C;
    /* 0x08d */ u8 pad8D[0x3];
    /* 0x090 */ MKMaterial* unk90;
    /* 0x094 */ MKMaterial* unk94;
    /* 0x098 */ f32 unk98;
    /* 0x09c */ f32 unk9C;
    /* 0x0a0 */ f32 unkA0;
    /* 0x0a4 */ u8 padA4[0x4];
    /* 0x0a8 */ f32 unkA8;
    /* 0x0ac */ f32 unkAC;
    /* 0x0b0 */ f32 unkB0;
    /* 0x0b4 */ u8 padB4[0x4];
    /* 0x0b8 */ f64 unkB8;
    /* 0x0c0 */ f64 unkC0;
    /* 0x0c8 */ f32 unkC8;
    /* 0x0cc */ f32 unkCC;
    /* 0x0d0 */ ManagedLight* unkD0;
    /* 0x0d4 */ void* unkD4;
    /* 0x0d8 */ f64 unkD8;
    /* 0x0e0 */ f64 unkE0;
    /* 0x0e8 */ MKAnimScript* unkE8;
};

#endif  // SPYRO_SOURCE_SPARXFX_H
