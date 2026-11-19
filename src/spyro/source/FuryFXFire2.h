#ifndef SPYRO_SOURCE_FURYFXFIRE2_H
#define SPYRO_SOURCE_FURYFXFIRE2_H

#include <dolphin/types.h>
#include "common/Source/Matrix.h"
#include "spyro/source/FuryFX.h"
#include "spyro/source/GroundFire.h"

class ClusterBomb;
class Explosion4;
class FuryFX;
class FuryFXFire2;
class FuryFXFire2_cpp;
class GroundFire;
class MKModel;
class MKVector3;
class Matrix;

class FuryFXFire2 : public FuryFX {  // base: ctor/dtor vtable stores
public:
    class Meteor;
    virtual ~FuryFXFire2(void);
    virtual void Init(void);
    virtual void Deinit(void);
    virtual void Update(void);
    virtual void Draw(void);
    FuryFXFire2(void);
    void ResetFury(void);
    void SpawnMeteor(void);
    void DrawMeteor(FuryFXFire2::Meteor *);
    void DrawMeteors(void);
    void UpdateMeteors(void);
    s32 Trigger(const MKVector3 &);
    void SetDefaults(void);
    /* 0x089 */ u8 pad89[0x7];
    /* 0x090 */ Matrix unk90;
    /* 0x11c */ u8 pad11C[0x24];
    /* 0x140 */ s8 unk140;
    /* 0x141 */ u8 pad141[0x7];
    /* 0x148 */ MKModel* unk148;
    /* 0x14c */ f32 unk14C;
    /* 0x150 */ FuryFXFire2::Meteor** unk150;
    /* 0x154 */ Explosion4* unk154;
    /* 0x158 */ s32 unk158;
    /* 0x15c */ f32 unk15C;
    /* 0x160 */ ClusterBomb* unk160;
    /* 0x164 */ GroundFire unk164;
};

class FuryFXFire2_cpp {
public:
    void __sinit(void);
};

#endif  // SPYRO_SOURCE_FURYFXFIRE2_H
