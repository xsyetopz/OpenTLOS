#ifndef SPYRO_SOURCE_FURYFXELECTRICITY_H
#define SPYRO_SOURCE_FURYFXELECTRICITY_H

#include <dolphin/types.h>
#include "common/Source/MKVector3.h"
#include "spyro/source/FuryFX.h"
#include "spyro/source/GameMessages.h"

class BreathHitMessage;
class FuryFX;
class FuryFXElectricity;
class FuryFXElectricity_cpp;
class LitCloudPS;
class MKMaterial;
class MKVector3;
class ManagedLight;
class ZapPS;

class FuryFXElectricity : public FuryFX {  // base: ctor/dtor vtable stores
public:
    class WindyRing;
    virtual ~FuryFXElectricity(void);
    virtual void Init(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Update(void);
    virtual void Draw(void);
    FuryFXElectricity(void);
    void ResetFury(void);
    void DrawWindyRing(FuryFXElectricity::WindyRing *);
    void DrawElectricityRing(void);
    s32 Trigger(const MKVector3 &, bool);
    void SetDefaults(void);
    /* 0x089 */ u8 pad89[0x7];
    /* 0x090 */ s32 unk90;
    /* 0x094 */ u8 pad94[0x4];
    /* 0x098 */ MKVector3 unk98;
    /* 0x0a8 */ MKMaterial* unkA8;
    /* 0x0ac */ f32 unkAC;
    /* 0x0b0 */ f32 unkB0;
    /* 0x0b4 */ f32 unkB4;
    /* 0x0b8 */ f32 unkB8;
    /* 0x0bc */ u8 padBC[0x4];
    /* 0x0c0 */ LitCloudPS* unkC0;
    /* 0x0c4 */ ManagedLight* unkC4;
    /* 0x0c8 */ MKMaterial* unkC8;
    /* 0x0cc */ MKMaterial* unkCC;
    /* 0x0d0 */ f32 unkD0;
    /* 0x0d4 */ f32 unkD4;
    /* 0x0d8 */ MKMaterial* unkD8;
    /* 0x0dc */ u8 padDC[0x4];
    /* 0x0e0 */ f32 unkE0;
    /* 0x0e4 */ f32 unkE4;
    /* 0x0e8 */ MKMaterial* unkE8;
    /* 0x0ec */ u8 padEC[0x4];
    /* 0x0f0 */ f32 unkF0;
    /* 0x0f4 */ f32 unkF4;
    /* 0x0f8 */ MKMaterial* unkF8;
    /* 0x0fc */ u8 padFC[0x4];
    /* 0x100 */ ZapPS* unk100;
    /* 0x104 */ u8 pad104[0x4];
    /* 0x108 */ BreathHitMessage unk108;
    /* 0x159 */ u8 pad159[0x7];
    /* 0x160 */ f32 unk160;
    /* 0x164 */ f32 unk164;
    /* 0x168 */ f32 unk168;
    /* 0x16c */ u8 pad16C[0x4];
    /* 0x170 */ f64 unk170;
    /* 0x178 */ f64 unk178;
    /* 0x180 */ f32 unk180;
    /* 0x184 */ f32 unk184;
    /* 0x188 */ s32 unk188;
    /* 0x18c */ u8 unk18C;
    /* 0x18d */ u8 pad18D[0x3];
    /* 0x190 */ f32 unk190;
    /* 0x194 */ f32 unk194;
};

class FuryFXElectricity_cpp {
public:
    void __sinit(void);
};

#endif  // SPYRO_SOURCE_FURYFXELECTRICITY_H
