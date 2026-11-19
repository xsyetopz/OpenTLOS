#ifndef SPYRO_SOURCE_FURYFXICE_H
#define SPYRO_SOURCE_FURYFXICE_H

#include <dolphin/types.h>
#include "common/Source/Matrix.h"
#include "spyro/source/FuryFX.h"
#include "spyro/source/GameMessages.h"
#include "spyro/source/WindFX.h"

class BreathHitMessage;
class FuryFX;
class FuryFXIce;
class FuryFXIce_cpp;
class IceBreathSnowFlakes;
class MKMaterial;
class MKModel;
class MKPropDescriptor;
class MKVector3;
class ManagedLight;
class Matrix;
class WindFX;

class FuryFXIce : public FuryFX {  // base: ctor/dtor vtable stores
public:
    virtual ~FuryFXIce(void);
    virtual void Init(void);
    virtual void Deinit(void);
    virtual f32 Resolve(void);
    virtual void * Update(void);
    virtual void Draw(void);
    FuryFXIce(void);
    void ResetFury(void);
    void DrawIcePatches(void);
    void UpdateIcePatches(void);
    void SpawnIcePatch(const MKVector3 &, const MKVector3 &, float);
    s32 Trigger(const MKVector3 &, bool);
    void SetDefaults(void);
    /* 0x090 */ s32 unk90;
    /* 0x094 */ f32 unk94;
    /* 0x098 */ ManagedLight* unk98;
    /* 0x09c */ u8 pad9C[0x4];
    /* 0x0a0 */ f64 unkA0;
    /* 0x0a8 */ f64 unkA8;
    /* 0x0b0 */ u8 unkB0;
    /* 0x0b1 */ s8 unkB1;
    /* 0x0b2 */ u8 padB2[0x6];
    /* 0x0b8 */ BreathHitMessage unkB8;
    /* 0x110 */ void* unk110;
    /* 0x114 */ MKMaterial* unk114;
    /* 0x118 */ IceBreathSnowFlakes* unk118;
    /* 0x11c */ u8 pad11C[0x4];
    /* 0x120 */ WindFX unk120;
    /* 0x150 */ Matrix unk150;
    /* 0x190 */ MKModel* unk190;
    /* 0x194 */ MKMaterial* unk194;
    /* 0x198 */ s32 unk198;
    /* 0x19c */ MKPropDescriptor* unk19C;
};

class FuryFXIce_cpp {
public:
    void __sinit(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline FuryFXIce::FuryFXIce() {
    this->unkB8.unk4 = 0;
}

inline FuryFXIce::~FuryFXIce() {
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

#endif  // SPYRO_SOURCE_FURYFXICE_H
