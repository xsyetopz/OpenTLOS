#ifndef SPYRO_SOURCE_FURYFXEARTH2_H
#define SPYRO_SOURCE_FURYFXEARTH2_H

#include <dolphin/types.h>
#include "common/Source/MKVector4.h"
#include "spyro/source/FuryFX.h"
#include "spyro/source/GameMessages.h"

class BreathHitMessage;
class FuryFX;
class FuryFXEarth2;
class FuryFXEarth2_cpp;
class MKModel;
class MKVector3;
class MKVector4;
class ManagedLight;

class FuryFXEarth2 : public FuryFX {  // base: ctor/dtor vtable stores
public:
    class VortexAttachmentPoint;
    virtual ~FuryFXEarth2(void);
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Update(void);
    virtual void Draw(void);
    FuryFXEarth2(void);
    void ResetFury(void);
    void CalcMatrixForVortexElement(FuryFXEarth2::VortexAttachmentPoint *);
    void EmitTimedSparks(void);
    void ExplodeVortex(void);
    void SpawnVortexElement(void);
    void DrawVortex(void);
    void UpdateVortex(void);
    void UpdateLightPosition(float, float);
    s32 Trigger(const MKVector3 &);
    void SetDefaults(void);
    /* 0x090 */ s32 unk90;
    /* 0x094 */ s32 unk94;
    /* 0x098 */ f32 unk98;
    /* 0x09c */ u8 pad9C[0x4];
    /* 0x0a0 */ f64 unkA0;
    /* 0x0a8 */ f32 unkA8;
    /* 0x0ac */ u8 padAC[0x4];
    /* 0x0b0 */ MKModel* unkB0;
    /* 0x0b4 */ MKModel* unkB4;
    /* 0x0b8 */ MKModel* unkB8;
    /* 0x0bc */ MKModel* unkBC;
    /* 0x0c0 */ void* unkC0;
    /* 0x0c4 */ f32 unkC4;
    /* 0x0c8 */ f32 unkC8;
    /* 0x0cc */ ManagedLight* unkCC;
    /* 0x0d0 */ MKVector4 unkD0;
    /* 0x0e0 */ f32 unkE0;
    /* 0x0e4 */ f32 unkE4;
    /* 0x0e8 */ BreathHitMessage unkE8;
};

class FuryFXEarth2_cpp {
public:
    void __sinit(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline FuryFXEarth2::FuryFXEarth2() {
    this->unkE8.unk4 = 0;
    return this;
}
#endif

inline FuryFXEarth2::~FuryFXEarth2() {
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

#endif  // SPYRO_SOURCE_FURYFXEARTH2_H
