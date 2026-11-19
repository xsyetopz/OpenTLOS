#ifndef SPYRO_SOURCE_AITARGETDATA_H
#define SPYRO_SOURCE_AITARGETDATA_H

#include <dolphin/types.h>
#include "spyro/source/TargetManager.h"

class AITargetData;
class MKVector3;
class TargetContext;
class Targetable;

class AITargetData {
public:
    f32 GetDistSq(void);
    f32 GetDist(void);
    void GetVel(void);
    void GetDir(void);
    void GetPos(void);
    void * GetProp(void);
    s32 IsAttackable(void);
    void Update(const MKVector3 &);
    void SetIsNew(bool);
    void SetInsideFOV(bool);
    void SetInsideExclusionRegion(bool);
    void SetInsideRegion(bool);
    void Set(const MKVector3 &, bool);
    void Set(Targetable *, bool);
    void SetDefaults(void);
    /* 0x000 */ f64 unk0;
    /* 0x008 */ f32 unk8;
    /* 0x00c */ f32 unkC;
    /* 0x010 */ f64 unk10;
    /* 0x018 */ f64 unk18;
    /* 0x020 */ f64 unk20;
    /* 0x028 */ f64 unk28;
    /* 0x030 */ f32 unk30;
    /* 0x034 */ f32 unk34;
    /* 0x038 */ f32 unk38;
    /* 0x03c */ f32 unk3C;
    /* 0x040 */ TargetContext unk40;
};

#endif  // SPYRO_SOURCE_AITARGETDATA_H
