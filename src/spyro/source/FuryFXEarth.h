#ifndef SPYRO_SOURCE_FURYFXEARTH_H
#define SPYRO_SOURCE_FURYFXEARTH_H

#include <dolphin/types.h>
#include "common/Source/Matrix.h"
#include "spyro/source/FuryFX.h"
#include "spyro/source/GameMessages.h"
#include "spyro/source/WindFX.h"

class BreathHitMessage;
class Corona;
class FuryFX;
class FuryFXEarth;
class FuryFXEarth_cpp;
class MKPropDescriptor;
class MKVector3;
class ManagedLight;
class Matrix;
class SuckeyPS;
class WindFX;

class FuryFXEarth : public FuryFX {  // base: ctor/dtor vtable stores
public:
    virtual ~FuryFXEarth(void);
    virtual void Init(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Update(void);
    virtual void Draw(void);
    FuryFXEarth(void);
    void TriggerBoulders(void);
    void ResetFury(void);
    s32 Trigger(const MKVector3 &, bool);
    void SetDefaults(void);
    void EmitLeaves(void);
    /* 0x089 */ u8 pad89[0x7];
    /* 0x090 */ WindFX unk90;
    /* 0x0c0 */ Matrix unkC0;
    /* 0x14c */ u8 pad14C[0x4];
    /* 0x150 */ f32 unk150;
    /* 0x154 */ f32 unk154;
    /* 0x158 */ f32 unk158;
    /* 0x15c */ f32 unk15C;
    /* 0x160 */ SuckeyPS* unk160;
    /* 0x164 */ Corona* unk164;
    /* 0x168 */ BreathHitMessage unk168;
    /* 0x1b9 */ u8 pad1B9[0x7];
    /* 0x1c0 */ MKPropDescriptor* unk1C0;
    /* 0x1c4 */ s32 unk1C4;
    /* 0x1c8 */ u8 unk1C8;
    /* 0x1c9 */ u8 pad1C9[0x3];
    /* 0x1cc */ ManagedLight* unk1CC;
};

class FuryFXEarth_cpp {
public:
    void __sinit(void);
};

#endif  // SPYRO_SOURCE_FURYFXEARTH_H
