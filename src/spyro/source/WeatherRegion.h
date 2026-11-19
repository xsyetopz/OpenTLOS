#ifndef SPYRO_SOURCE_WEATHERREGION_H
#define SPYRO_SOURCE_WEATHERREGION_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"
#include "spyro/source/PolyRegion.h"

class MKIniLine;
class MKProp;
class MKPropDescriptor;
class MKVector3;
class PolyRegion;
class WeatherRegion;
class WeatherRegionDescriptor;

class WeatherRegion : public MKProp {  // base: ctor/dtor vtable stores
public:
    virtual ~WeatherRegion(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Update(void);
    virtual void Draw(void);
    u8 CalculateEmissionPointRain(MKVector3 &);
    u8 CalculateEmissionParametersConvexity(MKVector3 &, MKVector3 &);
    u8 CalculateEmissionPointSpores(MKVector3 &);
    u8 CalculateEmissionPoint(MKVector3 &);
    /* 0x04c */ u8 pad4C[0x4];
    /* 0x050 */ f64 unk50;
    /* 0x058 */ f32 unk58;
    /* 0x05c */ u8 pad5C[0x4];
    /* 0x060 */ s32 unk60;
    /* 0x064 */ f32 unk64;
    /* 0x068 */ f32 unk68;
    /* 0x06c */ f32 unk6C;
    /* 0x070 */ f32 unk70;
    /* 0x074 */ s32 unk74;
    /* 0x078 */ f32 unk78;
    /* 0x07c */ u8 pad7C[0x4];
    /* 0x080 */ PolyRegion unk80;
};

class WeatherRegionDescriptor : public MKPropDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
    virtual void Update(void);
    virtual void Resolve(void);
    /* 0x048 */ u8 pad48[0x98];
    /* 0x0e0 */ s32 unkE0;
    /* 0x0e4 */ s32 unkE4;
    /* 0x0e8 */ s32 unkE8;
    /* 0x0ec */ s32 unkEC;
    /* 0x0f0 */ s32 unkF0;
    /* 0x0f4 */ s32 unkF4;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline WeatherRegion::~WeatherRegion() {
    s32 temp_cr0_eq_15;

    temp_cr0_eq_15 = this == NULL;
    if (temp_cr0_eq_15 == 0) {
        if (temp_cr0_eq_15 == 0) {
        }
    }
}

#endif  // SPYRO_SOURCE_WEATHERREGION_H
