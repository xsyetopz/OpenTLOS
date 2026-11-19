#ifndef SPYRO_SOURCE_EXPLOSIONFX_H
#define SPYRO_SOURCE_EXPLOSIONFX_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"

class ExplosionFX;
class MKMaterial;
class MKProp;
class MKVector3;
class Matrix;

class ExplosionFX : public MKProp {  // base: ctor/dtor vtable stores
public:
    virtual ~ExplosionFX(void);
    virtual void Init(void);
    virtual void Deinit(void);
    virtual void Update(void);
    virtual void Draw(void);
    void CreateShockwave(const MKVector3 &, const MKVector3 &, float);
    void CreateTendril(const MKVector3 &, float);
    void DrawShockwaves(void);
    void DrawTendrils(void);
    /* 0x04c */ MKMaterial* unk4C;
    /* 0x050 */ Matrix** unk50;
    /* 0x054 */ MKMaterial* unk54;
    /* 0x058 */ Matrix** unk58;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline ExplosionFX::~ExplosionFX() {
    s32 temp_cr0_eq_15;

    temp_cr0_eq_15 = this == NULL;
    if (temp_cr0_eq_15 == 0) {
        if (temp_cr0_eq_15 == 0) {
        }
    }
}

#endif  // SPYRO_SOURCE_EXPLOSIONFX_H
