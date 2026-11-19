#ifndef SPYRO_SOURCE_FURYFXCONVEXITY_H
#define SPYRO_SOURCE_FURYFXCONVEXITY_H

#include <dolphin/types.h>
#include "common/Source/Matrix.h"
#include "spyro/source/FuryFX.h"
#include "spyro/source/WindFX.h"

class FuryFX;
class FuryFXConvexity;
class FuryFXConvexity_cpp;
class KDSoundFader;
class MKHeap;
class MKMessage;
class MKVector3;
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
    /* 0x11c */ u8 pad11C[0x8];
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
};

class FuryFXConvexity_cpp {
public:
    void __sinit(void);
};

#endif  // SPYRO_SOURCE_FURYFXCONVEXITY_H
