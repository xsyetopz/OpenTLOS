#ifndef SPYRO_SOURCE_FURYFXCONVEXITY_H
#define SPYRO_SOURCE_FURYFXCONVEXITY_H

#include <dolphin/types.h>
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "spyro/source/FuryFX.h"
#include "spyro/source/WindFX.h"

class FuryFX;
class FuryFXConvexity;
class FuryFXConvexity_cpp;
class KDSoundFader;
class MKHeap;
class MKMessage;
class MKModel;
class MKVector3;
class ManagedLight;
class Matrix;
class WindFX;

class FuryFXConvexity : public FuryFX {  // base: ctor/dtor vtable stores
public:
    virtual ~FuryFXConvexity(void);
    virtual void Init(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Update(void);
    virtual void Draw(void);
    virtual void Message(MKMessage *);
    FuryFXConvexity(void);
    void EmitVortexParticles(void);
    void DisableChaserLights(void);
    u8 LightActiveOnChasers(void);
    void DrawDragonChasers(void);
    void UpdateDragonChasers(void);
    s32 LaunchDragonChaser(const MKVector3 &, const MKVector3 &);
    void ResetFury(void);
    s32 Trigger(const MKVector3 &);
    void SetDefaults(void);
    /* 0x089 */ u8 pad89[0x7];
    /* 0x090 */ Matrix unk90;
    /* 0x0d0 */ f64 unkD0;
    /* 0x0d8 */ f64 unkD8;
    /* 0x0e0 */ MKVector3 unkE0;
    /* 0x0f0 */ s32 unkF0;
    /* 0x0f4 */ f32 unkF4;
    /* 0x0f8 */ ManagedLight* unkF8;
    /* 0x0fc */ s32 unkFC;
    /* 0x100 */ u8 pad100[0x24];
    /* 0x124 */ s32 unk124;
    /* 0x128 */ u8 pad128[0x24];
    /* 0x14c */ u8 unk14C;
    /* 0x14d */ u8 unk14D;
    /* 0x14e */ u8 pad14E[0x2];
    /* 0x150 */ f32 unk150;
    /* 0x154 */ f32 unk154;
    /* 0x158 */ KDSoundFader** unk158;
    /* 0x15c */ MKHeap* unk15C;
    /* 0x160 */ MKHeap* unk160;
    /* 0x164 */ f32 unk164;
    /* 0x168 */ s32 unk168;
    /* 0x16c */ u8 pad16C[0x4];
    /* 0x170 */ WindFX unk170;
    /* 0x1a0 */ Matrix unk1A0;
    /* 0x1e0 */ MKModel* unk1E0;
};

class FuryFXConvexity_cpp {
public:
    void __sinit(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: undefined identifier 'unk6C'
inline FuryFXConvexity::FuryFXConvexity() {
    this->unk90.unk6C = 0.0f;
    this->unk124 = 0;
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier 'KDSound_Stop'
inline FuryFXConvexity::~FuryFXConvexity() {
    s32 temp_cr0_eq_35;

    if (this != NULL) {
        if ((&this->unk124 != NULL) && (&this->unk124 != NULL)) {
            KDSound_Stop(&this->unk124);
        }
        if ((&this->unk90.unk6C != NULL) && (&this->unk90.unk6C != NULL)) {
            KDSound_Stop((s32 *) &this->unk90.unk6C);
        }
        temp_cr0_eq_35 = this == NULL;
        if (temp_cr0_eq_35 == 0) {
            if (temp_cr0_eq_35 == 0) {
                if (temp_cr0_eq_35 == 0) {
                }
            }
        }
    }
}
#endif

#endif  // SPYRO_SOURCE_FURYFXCONVEXITY_H
