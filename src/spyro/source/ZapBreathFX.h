#ifndef SPYRO_SOURCE_ZAPBREATHFX_H
#define SPYRO_SOURCE_ZAPBREATHFX_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"
#include "spyro/source/ElectricBeamFX.h"
#include "spyro/source/GameMessages.h"
#include "spyro/source/KDSpline.h"

class BreathHitMessage;
class Corona;
class ElectricBeam;
class FuryFXElectricity;
class FuryFXElectricity2;
class KDSpline;
class MKMessage;
class MKModel;
class MKProp;
class MKPropDescriptor;
class MKVector3;
class ManagedLight;
class ScorchTrail;
class Zap;
class ZapBreathFX;
class ZapBreathFX_cpp;
class ZapMissile;
class ZapPS;

class Zap {
public:
    void Deinit(void);
    void Resolve(void);
    void Init(void);
    /* 0x000 */ KDSpline unk0;
    /* 0x014 */ u8 pad14[0x18c];
    /* 0x1a0 */ s8 unk1A0;
    /* 0x1a1 */ u8 pad1A1[0x3];
    /* 0x1a4 */ f32 unk1A4;
    /* 0x1a8 */ f32 unk1A8;
    /* 0x1ac */ f32 unk1AC;
    /* 0x1b0 */ f32 unk1B0;
    /* 0x1b4 */ u8 pad1B4[0x4];
    /* 0x1b8 */ f32 unk1B8;
    /* 0x1bc */ Corona* unk1BC;
    /* 0x1c0 */ Corona* unk1C0;
    /* 0x1c4 */ u8 pad1C4[0x4];
    /* 0x1c8 */ f32 unk1C8;
};

class ZapBreathFX : public MKProp {  // base: ctor/dtor vtable stores
public:
    virtual ~ZapBreathFX(void);
    virtual void Init(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Update(void);
    virtual void Draw(void);
    virtual void Message(MKMessage *);
    ZapBreathFX(void);
    void ResetFury(void);
    void ButtonReleased(void);
    u8 LightActiveOnMissiles(void);
    void DisableMissileLight(ZapMissile *);
    u8 ShootZapMissile(const MKVector3 &, const MKVector3 &);
    void UpdateZapMissiles(void);
    u8 Trigger(MKProp *, const MKVector3 &, const MKVector3 &, const float &, const int &, bool);
    /* 0x04c */ u8 pad4C[0x5c];
    /* 0x0a8 */ void* unkA8;
    /* 0x0ac */ void* unkAC;
    /* 0x0b0 */ ManagedLight* unkB0;
    /* 0x0b4 */ s32 unkB4;
    /* 0x0b8 */ u8 padB8[0x10];
    /* 0x0c8 */ s8 unkC8;
    /* 0x0c9 */ u8 unkC9;
    /* 0x0ca */ u8 padCA[0x2];
    /* 0x0cc */ ZapPS* unkCC;
    /* 0x0d0 */ f32 unkD0;
    /* 0x0d4 */ f32 unkD4;
    /* 0x0d8 */ f32 unkD8;
    /* 0x0dc */ f32 unkDC;
    /* 0x0e0 */ MKModel* unkE0;
    /* 0x0e4 */ u8 padE4[0x4];
    /* 0x0e8 */ f64 unkE8;
    /* 0x0f0 */ f64 unkF0;
    /* 0x0f8 */ f32 unkF8;
    /* 0x0fc */ MKPropDescriptor* unkFC;
    /* 0x100 */ f32 unk100;
    /* 0x104 */ f32 unk104;
    /* 0x108 */ BreathHitMessage unk108;
    /* 0x15c */ u8 pad15C[0x4];
    /* 0x160 */ BreathHitMessage unk160;
    /* 0x1b4 */ u8 pad1B4[0xc];
    /* 0x1c0 */ ElectricBeam unk1C0;
    /* 0x3c0 */ u8 pad3C0[0x20];
    /* 0x3e0 */ f64 unk3E0;
    /* 0x3e8 */ f64 unk3E8;
    /* 0x3f0 */ u8 pad3F0[0x1f0];
    /* 0x5e0 */ f64 unk5E0;
    /* 0x5e8 */ f64 unk5E8;
    /* 0x5f0 */ u8 pad5F0[0x1f0];
    /* 0x7e0 */ f64 unk7E0;
    /* 0x7e8 */ f64 unk7E8;
    /* 0x7f0 */ u8 pad7F0[0x1f0];
    /* 0x9e0 */ u8 unk9E0;
    /* 0x9e1 */ u8 pad9E1[0x3];
    /* 0x9e4 */ Corona* unk9E4;
    /* 0x9e8 */ MKProp* unk9E8;
    /* 0x9ec */ s32 unk9EC;
    /* 0x9f0 */ f32 unk9F0;
    /* 0x9f4 */ FuryFXElectricity* unk9F4;
    /* 0x9f8 */ FuryFXElectricity2* unk9F8;
    /* 0x9fc */ s32 unk9FC;
    /* 0xa00 */ ScorchTrail* unkA00;
    /* 0xa04 */ ScorchTrail* unkA04;
    /* 0xa08 */ f32 unkA08;
    /* 0xa0c */ f32 unkA0C;
};

class ZapBreathFX_cpp {
public:
    void __sinit(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: undefined identifier 'unkB8'
inline ZapBreathFX::ZapBreathFX() {
    this->unkB4 = 0;
    this->unkB8 = 0;
    this->unkBC = 0.0f;
    this->unkC0 = 0;
    this->unk108.unk4 = 0;
    this->unk160.unk4 = 0;
    __construct_array((KDUniformSpline *) &this->unk1C0, (MKAnimScript *(*)(MKAnimScript *)) &ElectricBeam::ElectricBeam, NULL, 0x200, 4);
    return this;
}
#endif

inline ZapBreathFX::~ZapBreathFX() {
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

#endif  // SPYRO_SOURCE_ZAPBREATHFX_H
