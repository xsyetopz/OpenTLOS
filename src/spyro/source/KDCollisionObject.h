#ifndef SPYRO_SOURCE_KDCOLLISIONOBJECT_H
#define SPYRO_SOURCE_KDCOLLISIONOBJECT_H

#include <dolphin/types.h>
#include "unplaced_enums.h"

class KDColObjDescriptor;
class KDCollisionObject;
class KDContextInfo;
class MKCollisionInfo;
class MKCollisionManager;
class MKCollisionResult;
class MKVector3;

class KDColObjDescriptor {
public:
    /* 0x000 */ f32 unk0;
    /* 0x004 */ f32 unk4;
    /* 0x008 */ s32 unk8;
    /* 0x00c */ s32 unkC;
    /* 0x010 */ s32 unk10;
    /* 0x014 */ u8 pad14[0x4];
    /* 0x018 */ s32 unk18;
    /* 0x01c */ f32 unk1C;
    /* 0x020 */ u8 pad20[0x8];
    /* 0x028 */ f32 unk28;
    /* 0x02c */ u8 pad2C[0x8];
    /* 0x034 */ f32 unk34;
    /* 0x038 */ u8 pad38[0x8];
    /* 0x040 */ u8 unk40;
};

class KDCollisionObject {
public:
    class UpdateResult;
    void PushOutOfThings(MKVector3);
    u8 IsFloorCollision(MKCollisionResult *);
    static void CalculateNewVelocity(MKVector3 *, const MKVector3 *, float, KDContextInfo *, MKCollisionResult *, const MKVector3 &);
    void ResolveCollisions(KDCollisionObject *, MKVector3 *, MKVector3 *, int, float, MKCollisionMode, int);
    void ResolveCollisions(MKVector3 *, MKVector3 *, int);
    MKVector3 * StoreResult(MKCollisionResult *, MKVector3 *);
    static void CalcPushOutPos(const MKVector3 &, MKVector3 *, KDColObjDescriptor *, float, KDCollisionObject::UpdateResult *);
    s32 CalcPushOutPos(const MKVector3 &, MKVector3 *, int, float, MKCollisionMode, int, KDCollisionObject::UpdateResult *);
    s8 Teleport(const MKVector3 &, float, int, MKCollisionResult *);
    s32 Update(MKVector3 *, float);
    void Deinit(void);
    void Init(KDColObjDescriptor *, const MKVector3 &, MKCollisionInfo *, MKCollisionManager *);
    /* 0x000 */ f64 unk0;
    /* 0x008 */ f64 unk8;
    /* 0x010 */ u8 pad10[0xb0];
    /* 0x0c0 */ s32 unkC0;
    /* 0x0c4 */ u8 padC4[0xbc];
    /* 0x180 */ s32 unk180;
    /* 0x184 */ u8 pad184[0xbc];
    /* 0x240 */ f64 unk240;
    /* 0x248 */ f64 unk248;
    /* 0x250 */ KDColObjDescriptor* unk250;
    /* 0x254 */ MKCollisionInfo* unk254;
};

class KDContextInfo {
public:
    /* 0x000 */ u8 pad0[0x10];
    /* 0x010 */ f32 unk10;
    /* 0x014 */ f32 unk14;
    /* 0x018 */ f32 unk18;
};

#endif  // SPYRO_SOURCE_KDCOLLISIONOBJECT_H
