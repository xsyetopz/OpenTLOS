#ifndef SPYRO_SOURCE_SHAPEDTRAILFX_H
#define SPYRO_SOURCE_SHAPEDTRAILFX_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"
#include "common/Source/MKVector4.h"
#include "spyro/source/KDSpline.h"

class KDUniformSpline;
class MKHeap;
class MKMaterial;
class MKModel;
class MKProp;
class MKVector4;
class ShapedTrailFX;

class ShapedTrailFX : public MKProp {  // base: ctor/dtor vtable stores
public:
    virtual ~ShapedTrailFX(void);
    virtual void Init(void);
    virtual void Deinit(void);
    virtual void Reset(void);
    virtual void Update(void);
    virtual void Draw(void);
    void UpdateTrail(void);
    void InitData(MKModel *, const int &, char *, const int &, const MKVector4 &, const float &, bool, float);
    /* 0x04c */ u8 pad4C[0x4];
    /* 0x050 */ MKVector4 unk50;
    /* 0x060 */ KDUniformSpline unk60;
    /* 0x074 */ void* unk74;
    /* 0x078 */ MKModel* unk78;
    /* 0x07c */ MKMaterial* unk7C;
    /* 0x080 */ MKHeap* unk80;
    /* 0x084 */ MKHeap* unk84;
    /* 0x088 */ s32 unk88;
    /* 0x08c */ s32 unk8C;
    /* 0x090 */ s32 unk90;
    /* 0x094 */ f32 unk94;
    /* 0x098 */ f32 unk98;
    /* 0x09c */ f32 unk9C;
    /* 0x0a0 */ u8 unkA0;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline ShapedTrailFX::~ShapedTrailFX() {
    s32 temp_cr0_eq_15;

    temp_cr0_eq_15 = this == NULL;
    if (temp_cr0_eq_15 == 0) {
        if (temp_cr0_eq_15 == 0) {
        }
    }
}

#endif  // SPYRO_SOURCE_SHAPEDTRAILFX_H
