#ifndef SPYRO_SOURCE_FLAMEBREATHFX_H
#define SPYRO_SOURCE_FLAMEBREATHFX_H

#include <dolphin/types.h>
#include "common/Source/MKVector4.h"
#include "spyro/source/BaseBreathFX.h"
#include "spyro/source/FlameBreathBeamFX.h"
#include "spyro/source/GroundFire.h"

class BaseBreathFX;
class Corona;
class FlameBreathBeam;
class FlameBreathFX;
class FlameBreathFX_cpp;
class FlameBreathPS;
class FuryFXFire;
class FuryFXFire2;
class GroundFire;
class MKMaterial;
class MKProp;
class MKPropDescriptor;
class MKVector3;
class MKVector4;
class ManagedLight;

class FlameBreathFX : public BaseBreathFX {  // base: ctor/dtor vtable stores
public:
    virtual ~FlameBreathFX(void);
    virtual void Init(void);
    virtual void Deinit(void);
    virtual f32 Resolve(void);
    virtual void * Update(void);
    virtual void Draw(void);
    FlameBreathFX(void);
    void ResetFury(void);
    void GetAttack1UpgradeVariables(int, float &, float &, float &);
    u8 ShootFireBomb(const MKVector3 &, const MKVector3 &, const MKVector3 &, bool);
    s32 Trigger(MKProp *, const MKVector3 &, const MKVector3 &, const MKVector3 &, const float &, const int &, bool, bool);
    void DrawFlameBreath(void);
    /* 0x0a8 */ ManagedLight* unkA8;
    /* 0x0ac */ FlameBreathPS* unkAC;
    /* 0x0b0 */ u8 padB0[0x4];
    /* 0x0b4 */ u8 unkB4;
    /* 0x0b5 */ u8 padB5[0x3];
    /* 0x0b8 */ s32 unkB8;
    /* 0x0bc */ s32 unkBC;
    /* 0x0c0 */ f32 unkC0;
    /* 0x0c4 */ u8 padC4[0x4];
    /* 0x0c8 */ MKVector4 unkC8;
    /* 0x0d8 */ f32 unkD8;
    /* 0x0dc */ Corona* unkDC;
    /* 0x0e0 */ MKMaterial* unkE0;
    /* 0x0e4 */ u8 padE4[0x4c];
    /* 0x130 */ s32 unk130;
    /* 0x134 */ f32 unk134;
    /* 0x138 */ f32 unk138;
    /* 0x13c */ f32 unk13C;
    /* 0x140 */ GroundFire unk140;
    /* 0x144 */ f32 unk144;
    /* 0x148 */ FlameBreathBeam unk148;
    /* 0x260 */ FuryFXFire* unk260;
    /* 0x264 */ FuryFXFire2* unk264;
    /* 0x268 */ f32 unk268;
    /* 0x26c */ MKPropDescriptor* unk26C;
};

class FlameBreathFX_cpp {
public:
    void __sinit(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline FlameBreathFX::FlameBreathFX() {
    this->unk148.unkC8.unk0 = 0;
    this->unk148.unkC8.unk4 = 0;
    this->unk148.unkC8.unk8 = 0.0f;
    this->unk148.unkC8.unkC = 0;
}

inline FlameBreathFX::~FlameBreathFX() {
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

#endif  // SPYRO_SOURCE_FLAMEBREATHFX_H
