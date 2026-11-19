#ifndef SPYRO_SOURCE_COLLISIONOBJECT_H
#define SPYRO_SOURCE_COLLISIONOBJECT_H

#include <dolphin/types.h>
#include "spyro/source/TargetManager.h"

class ColObjDescriptor;
class CollisionObject;
class ContextInfo;
class MKCollisionInfo;
class MKCollisionMode;
class MKCollisionResult;
class MKMessage;
class MKProp;
class MKVector3;
class Targetable;

class ColObjDescriptor {
public:
    void Init(void);
    /* 0x000 */ f32 unk0;
    /* 0x004 */ f32 unk4;
    /* 0x008 */ s32 unk8;
    /* 0x00c */ s32 unkC;
    /* 0x010 */ s32 unk10;
    /* 0x014 */ s8 unk14;
    /* 0x015 */ u8 pad15[0x3];
    /* 0x018 */ s32 unk18;
    /* 0x01c */ f32 unk1C;
    /* 0x020 */ f32 unk20;
    /* 0x024 */ s32 unk24;
    /* 0x028 */ s32 unk28;
    /* 0x02c */ f32 unk2C;
    /* 0x030 */ f32 unk30;
    /* 0x034 */ s32 unk34;
    /* 0x038 */ s32 unk38;
    /* 0x03c */ f32 unk3C;
    /* 0x040 */ f32 unk40;
    /* 0x044 */ s32 unk44;
    /* 0x048 */ s32 unk48;
};

class ContextInfo {
public:
    s32 HitID(unsigned int);
    /* 0x000 */ u8 pad0[0x160];
    /* 0x160 */ s32 unk160;
    /* 0x164 */ s32 unk164;
};

class CollisionObject : public Targetable {  // base: ctor/dtor vtable stores
public:
    virtual void Init(ColObjDescriptor *, const MKVector3 &, bool, MKCollisionInfo *, bool, bool, unsigned int, MKProp *, bool);
    virtual void Deinit(void);
    virtual s32 Update(MKVector3 *, float, bool);
    virtual s32 Teleport(const MKVector3 &, float, int);
    virtual s32 HasHitFloor(void);
    virtual s32 HasHitWall(void);
    virtual s32 HasHitRoof(void);
    virtual s32 HasHitAnything(void);
    virtual u32 GetFloorProp(void);
    virtual s32 GetOwner(void);
    virtual void SetOwner(MKProp *);
    virtual s32 GetFloorMaterialID(void);
    virtual u32 GetProp(void);
    virtual void SetRotation(MKVector3 *, MKVector3);
    virtual void SetScale(float);
    virtual void Reset(const MKVector3 &, const MKVector3 &);
    virtual void IgnoreAll(bool);
    virtual void GetPos(void);
    virtual void GetOffset(void);
    virtual s32 SphereCheck(const MKVector3 &, const MKVector3 &, float, MKCollisionResult *, MKCollisionMode, int);
    virtual void ResolveCollisions(MKVector3 *, MKVector3 *, int);
    virtual void ResolveCollisionsQuick(MKVector3 *, MKVector3 *, int);
    void CalculateNewVelocity(MKVector3 *, const MKVector3 *, float, ContextInfo *, MKCollisionResult *, const MKVector3 &);
    void SortResults(void);
    void PerformPushOut(MKVector3 *);
    void ResetResults(void);
    ContextInfo * StoreResult(MKCollisionResult *, MKVector3 *);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ f64 unk8;
    /* 0x010 */ u8 pad10[0x40];
    /* 0x050 */ void* unk50;
    /* 0x054 */ u8 pad54[0x4];
    /* 0x058 */ u8 unk58;
    /* 0x059 */ u8 pad59[0x113];
    /* 0x16c */ s32 unk16C;
    /* 0x170 */ ContextInfo unk170;
    /* 0x2d8 */ ContextInfo unk2D8;
    /* 0x440 */ MKMessage* unk440;
    /* 0x444 */ u8 pad444[0x4];
    /* 0x448 */ s32 unk448;
    /* 0x44c */ s32 unk44C;
    /* 0x450 */ f64 unk450;
    /* 0x458 */ f64 unk458;
    /* 0x460 */ f32* unk460;
    /* 0x464 */ MKCollisionInfo* unk464;
    /* 0x468 */ s32 unk468;
    /* 0x46c */ s32 unk46C;
    /* 0x470 */ MKProp* unk470;
};

#endif  // SPYRO_SOURCE_COLLISIONOBJECT_H
