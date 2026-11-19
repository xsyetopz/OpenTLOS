#ifndef SPYRO_SOURCE_FURYFXICE2_H
#define SPYRO_SOURCE_FURYFXICE2_H

#include <dolphin/types.h>
#include "spyro/source/FuryFX.h"
#include "spyro/source/GameMessages.h"

class BreathHitMessage;
class FuryFX;
class FuryFXIce2;
class IceExplosion;
class MKModel;
class MKVector3;
class Matrix;
class Targetable;

class FuryFXIce2 : public FuryFX {  // base: ctor/dtor vtable stores
public:
    virtual ~FuryFXIce2(void);
    virtual void Init(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Update(void);
    virtual void Draw(void);
    FuryFXIce2(void);
    void ResetFury(void);
    void TargetAndSpawnIceSpear(void);
    void SpawnIceSpear(Targetable *);
    void DrawIceSpears(void);
    Matrix ** UpdateIceSpears(void);
    void FindInRangeTargets(float);
    s32 Trigger(const MKVector3 &);
    void SetDefaults(void);
    /* 0x089 */ u8 pad89[0x7];
    /* 0x090 */ s32 unk90;
    /* 0x094 */ f32 unk94;
    /* 0x098 */ f64 unk98;
    /* 0x0a0 */ f32 unkA0;
    /* 0x0a4 */ u8 padA4[0x4];
    /* 0x0a8 */ BreathHitMessage unkA8;
    /* 0x0f9 */ u8 padF9[0x7];
    /* 0x100 */ Matrix** unk100;
    /* 0x104 */ MKModel* unk104;
    /* 0x108 */ Targetable*** unk108;
    /* 0x10c */ Targetable*** unk10C;
    /* 0x110 */ f32 unk110;
    /* 0x114 */ IceExplosion* unk114;
};

#endif  // SPYRO_SOURCE_FURYFXICE2_H
