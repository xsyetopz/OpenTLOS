#ifndef SPYRO_SOURCE_WATERSURFACEFX_H
#define SPYRO_SOURCE_WATERSURFACEFX_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"

class MKMaterial;
class MKProp;
class MKPropDescriptor;
class MKVector3;
class WaterSurfaceFX;
class WaterSurfaceFXDescriptor;

class WaterSurfaceFX : public MKProp {  // base: ctor/dtor vtable stores
public:
    class Ripple;
    class Wake;
    virtual ~WaterSurfaceFX(void);
    virtual void Init(void);
    virtual void Deinit(void);
    virtual void Update(void);
    virtual void Draw(void);
    void UpdateRipples(void);
    void DrawRipple(WaterSurfaceFX::Ripple *);
    void SpawnRipple(const MKVector3 &, float);
    void AddWakeNode(WaterSurfaceFX::Wake *, const MKVector3 &, const MKVector3 &, float);
    void SpawnWake(void);
    void DrawWake(WaterSurfaceFX::Wake *);
    u8 UpdateWake(WaterSurfaceFX::Wake *);
    void AddMovementForce(const MKVector3 &, const MKVector3 &);
    /* 0x04c */ WaterSurfaceFX::Wake** unk4C;
    /* 0x050 */ WaterSurfaceFX::Wake* unk50;
    /* 0x054 */ f32 unk54;
    /* 0x058 */ f32 unk58;
    /* 0x05c */ WaterSurfaceFX::Wake** unk5C;
};

class WaterSurfaceFXDescriptor : public MKPropDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
    virtual void Deinit(void);
    /* 0x044 */ u8 pad44[0x1c];
    /* 0x060 */ MKMaterial* unk60;
    /* 0x064 */ MKMaterial* unk64;
    /* 0x068 */ MKMaterial* unk68;
    /* 0x06c */ MKMaterial* unk6C;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline WaterSurfaceFX::~WaterSurfaceFX() {
    s32 temp_cr0_eq_15;

    temp_cr0_eq_15 = this == NULL;
    if (temp_cr0_eq_15 == 0) {
        if (temp_cr0_eq_15 == 0) {
        }
    }
}

#endif  // SPYRO_SOURCE_WATERSURFACEFX_H
