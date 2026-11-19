#ifndef SPYRO_SOURCE_SKYCLOUDS_H
#define SPYRO_SOURCE_SKYCLOUDS_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"

class MKMaterial;
class MKProp;
class MKPropDescriptor;
class MKVector3;
class MKVector4;
class Matrix;
class SkyClouds;
class SkyCloudsDescriptor;

class SkyClouds : public MKProp {  // base: ctor/dtor vtable stores
public:
    class CloudEmitter;
    class CloudParticle;
    virtual ~SkyClouds(void);
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Update(void);
    virtual void Draw(void);
    u8 DestroyByOwner(SkyClouds::CloudEmitter *);
    void UpdateCameraVel(void);
    void UpdateClouds(void);
    void SpawnCloudEmitter(const MKVector3 &, const MKVector3 &, float);
    void Emit(const MKVector3 &, const MKVector4 &, float, SkyClouds::CloudEmitter *);
    void DrawCloudlet(SkyClouds::CloudParticle *, Matrix *);
    /* 0x04c */ s32 unk4C;
    /* 0x050 */ SkyClouds::CloudEmitter** unk50;
    /* 0x054 */ SkyClouds::CloudEmitter** unk54;
    /* 0x058 */ MKMaterial* unk58;
    /* 0x05c */ u8 pad5C[0xc];
    /* 0x068 */ f64 unk68;
    /* 0x070 */ f64 unk70;
    /* 0x078 */ u8 pad78[0x48];
    /* 0x0c0 */ SkyClouds::CloudEmitter** unkC0;
    /* 0x0c4 */ u8 padC4[0x4];
    /* 0x0c8 */ f32 unkC8;
    /* 0x0cc */ f32 unkCC;
    /* 0x0d0 */ f32 unkD0;
};

class SkyCloudsDescriptor : public MKPropDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
    /* 0x044 */ u8 pad44[0x24];
    /* 0x068 */ f64 unk68;
    /* 0x070 */ f64 unk70;
    /* 0x078 */ f64 unk78;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline SkyClouds::~SkyClouds() {
    s32 temp_cr0_eq_15;

    temp_cr0_eq_15 = this == NULL;
    if (temp_cr0_eq_15 == 0) {
        if (temp_cr0_eq_15 == 0) {
        }
    }
}

#endif  // SPYRO_SOURCE_SKYCLOUDS_H
