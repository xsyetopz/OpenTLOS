#ifndef SPYRO_SOURCE_BASEBREATHFX_H
#define SPYRO_SOURCE_BASEBREATHFX_H

#include <dolphin/types.h>
#include "spyro/source/KDProp.h"

class BaseBreathFX;
class BreathFXCollisionSphereTest;
class KDProp;
class KDSplinePathSegment;
class MKHeap;
class MKVector3;

class BaseBreathFX : public KDProp {  // base: ctor/dtor vtable stores
public:
    virtual ~BaseBreathFX(void);
    virtual void Init(void);
    virtual void Deinit(void);
    virtual void * Update(void);
    f32 SplineCollide(KDSplinePathSegment *, float);
    void CreateCollisionTest(const MKVector3 &, const MKVector3 &, float, unsigned int, void (*)(BreathFXCollisionSphereTest *));
    /* 0x090 */ void* unk90;
    /* 0x094 */ f32 unk94;
    /* 0x098 */ u8 pad98[0x4];
    /* 0x09c */ MKHeap* unk9C;
    /* 0x0a0 */ f32 unkA0;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline BaseBreathFX::~BaseBreathFX() {
    s32 temp_cr0_eq_7590;

    temp_cr0_eq_7590 = this == NULL;
    if (temp_cr0_eq_7590 == 0) {
        if (temp_cr0_eq_7590 == 0) {
            if (temp_cr0_eq_7590 == 0) {
            }
        }
    }
}

#endif  // SPYRO_SOURCE_BASEBREATHFX_H
