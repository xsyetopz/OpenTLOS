#ifndef SPYRO_SOURCE_CYNDERBREATHFX_H
#define SPYRO_SOURCE_CYNDERBREATHFX_H

#include <dolphin/types.h>
#include "common/Source/MKPtrList.h"
#include "spyro/source/BaseBreathFX.h"
#include "spyro/source/FlameBreathBeamFX.h"
#include "spyro/source/KDProp.h"

class BaseBreathFX;
class BreathFXCollisionSphereTest;
class CynderBreathFX;
class CynderBreathFXDescriptor;
class CynderBreathFX_cpp;
class FlameBreathBeam;
class KDPropDescriptor;
class MKProp;
class MKVector3;

class BreathFXCollisionSphereTest {
public:
    /* 0x000 */ f64 unk0;
    /* 0x008 */ f64 unk8;
    /* 0x010 */ u8 pad10[0x2c];
    /* 0x03c */ void* unk3C;
    /* 0x040 */ s32 unk40;
};

class CynderBreathFX : public BaseBreathFX {  // base: ctor/dtor vtable stores
public:
    virtual ~CynderBreathFX(void);
    virtual void Init(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Update(void);
    virtual void Draw(void);
    CynderBreathFX(void);
    void SetHitList(MKPtrList<MKProp> *);
    void End(void);
    void UpdateBeamSpeedWay(const MKVector3 &, const MKVector3 &, const MKVector3 &);
    void UpdateBeam(MKVector3, MKVector3, MKVector3);
    s32 Trigger(MKProp *, const MKVector3 &, const MKVector3 &, const MKVector3 &, const float &, int, float);
    void BreathFire(void);
    /* 0x0a8 */ u8 padA8[0x4];
    /* 0x0ac */ s32 unkAC;
    /* 0x0b0 */ FlameBreathBeam unkB0;
    /* 0x1c8 */ f32 unk1C8;
    /* 0x1cc */ MKProp* unk1CC;
    /* 0x1d0 */ f32 unk1D0;
};

class CynderBreathFXDescriptor : public KDPropDescriptor {  // base: inlined ctor vtable stores
public:
    virtual void Init(void);
    /* 0x070 */ s32 unk70;
    /* 0x074 */ s32 unk74;
};

class CynderBreathFX_cpp {
public:
    void __sinit(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline CynderBreathFX::CynderBreathFX() {
    this->unkB0.unkC8.unk0 = 0;
    this->unkB0.unkC8.unk4 = 0;
    this->unkB0.unkC8.unk8 = 0.0f;
    this->unkB0.unkC8.unkC = 0;
    return this;
}
#endif

inline CynderBreathFX::~CynderBreathFX() {
    s32 temp_cr0_eq_15;

    temp_cr0_eq_15 = this == NULL;
    if (temp_cr0_eq_15 == 0) {
        if (temp_cr0_eq_15 == 0) {
            if (temp_cr0_eq_15 == 0) {
                if (temp_cr0_eq_15 == 0) {
                }
            }
        }
    }
}

#endif  // SPYRO_SOURCE_CYNDERBREATHFX_H
