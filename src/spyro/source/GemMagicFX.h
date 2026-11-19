#ifndef SPYRO_SOURCE_GEMMAGICFX_H
#define SPYRO_SOURCE_GEMMAGICFX_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"

class GemMagicFX;
class GemMagicFX_cpp;
class MKHeap;
class MKMaterial;
class MKProp;
class MKVector3;
class MKVector4;
class Matrix;

class GemMagicFX : public MKProp {  // base: ctor/dtor vtable stores
public:
    class Magic;
    virtual ~GemMagicFX(void);
    virtual void Init(void);
    virtual void Deinit(void);
    virtual void Update(void);
    virtual void Draw(void);
    void DrawGlow(GemMagicFX::Magic *, Matrix *, MKVector3 *);
    void Emit(const MKVector3 &, const MKVector3 &, MKVector3 *, const MKVector4 &, bool);
    void ** GetTrail(void);
    /* 0x04c */ MKHeap* unk4C;
    /* 0x050 */ MKHeap* unk50;
    /* 0x054 */ MKMaterial* unk54;
};

class GemMagicFX_cpp {
public:
    void __sinit(void);
};

#endif  // SPYRO_SOURCE_GEMMAGICFX_H
