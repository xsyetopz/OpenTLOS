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
    /* 0x0a4 */ u8 padA4[0x8];
    /* 0x0ac */ s32 unkAC;
    /* 0x0b0 */ FlameBreathBeam unkB0;
    /* 0x1c4 */ u8 pad1C4[0x4];
    /* 0x1c8 */ f32 unk1C8;
    /* 0x1cc */ MKProp* unk1CC;
    /* 0x1d0 */ f32 unk1D0;
};

class CynderBreathFXDescriptor : public KDPropDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
    /* 0x06d */ u8 pad6D[0x3];
    /* 0x070 */ s32 unk70;
    /* 0x074 */ s32 unk74;
};

class CynderBreathFX_cpp {
public:
    void __sinit(void);
};

#endif  // SPYRO_SOURCE_CYNDERBREATHFX_H
