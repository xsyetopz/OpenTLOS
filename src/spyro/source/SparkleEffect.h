#ifndef SPYRO_SOURCE_SPARKLEEFFECT_H
#define SPYRO_SOURCE_SPARKLEEFFECT_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"

class MKProp;
class SparkleEffect;

class SparkleEffect : public MKProp {  // base: ctor/dtor vtable stores
public:
    virtual ~SparkleEffect(void);
    virtual void Init(void);
    virtual s32 LoadDone(void);
    virtual void Deinit(void);
    virtual void * Update(void);
    virtual void Draw(void);
    void FindNewSparklePoint(void);
    /* 0x04c */ u32* unk4C;
    /* 0x050 */ u8 pad50[0xc8];
    /* 0x118 */ f32 unk118;
    /* 0x11c */ f32 unk11C;
    /* 0x120 */ f32 unk120;
    /* 0x124 */ u8 unk124;
    /* 0x125 */ u8 pad125[0x3];
    /* 0x128 */ s32 unk128;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline SparkleEffect::~SparkleEffect() {
    s32 temp_cr0_eq_15;

    temp_cr0_eq_15 = this == NULL;
    if (temp_cr0_eq_15 == 0) {
        if (temp_cr0_eq_15 == 0) {
        }
    }
}

#endif  // SPYRO_SOURCE_SPARKLEEFFECT_H
