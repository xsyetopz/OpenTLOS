#ifndef COMMON_SOURCE_MKCOLLISIONMODEL_H
#define COMMON_SOURCE_MKCOLLISIONMODEL_H

#include <dolphin/types.h>
#include "common/Source/MKCollisionUtil.h"

class ColGridData;
class MKBestResult;
class MKCollisionAABB;
class MKCollisionBox;
class MKCollisionEllipsoid;
class MKCollisionGroundHint;
class MKCollisionInfo;
class MKCollisionModel;
class MKCollisionRay;
class MKCollisionResult;
class MKHeap;
class MKModel;
class MKSweptBox;
class MKVector3;

class ColGridData {
public:
    /* 0x000 */ u8 pad0[0x4];
    /* 0x004 */ u32 unk4;
    /* 0x008 */ u32 unk8;
    /* 0x00c */ u32 unkC;
    /* 0x010 */ u8 pad10[0x18];
    /* 0x028 */ f32 unk28;
    /* 0x02c */ u8 pad2C[0xa0];
    /* 0x0cc */ s32 unkCC;
};

class MKCollisionGroundHint {
public:
    virtual void Set(MKCollisionGroundHint *);
    virtual void Set(ColGridData *, const MKVector3 &, unsigned int, unsigned int, unsigned short *);
    virtual s32 Update(const MKCollisionRay &, MKCollisionResult *, int);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ f64 unk8;
    /* 0x010 */ f64 unk10;
    /* 0x018 */ f64 unk18;
    /* 0x020 */ f64 unk20;
    /* 0x028 */ s32 unk28;
    /* 0x02c */ s32 unk2C;
    /* 0x030 */ s32 unk30;
    /* 0x034 */ s32 unk34;
};

class MKCollisionModel {
public:
    virtual void Deinit(void);
    s32 EllipsoidIntersectTri(MKCollisionEllipsoid &, MKVector3 *, MKCollisionResult *);
    u8 BoxTestTri(const MKCollisionBox &, MKVector3 *, MKCollisionResult *);
    f64 SweepBoxToTri(const MKSweptBox &, MKVector3 *, MKBestResult *, MKBestResult *, MKBestResult *, unsigned int, MKCollisionInfo *);
    void SphereTestTri(const MKCollisionRay &, int, MKVector3 *, MKCollisionResult *);
    void SweepSphereTest(const MKCollisionRay &, MKCollisionResult *);
    void RayTest(const MKCollisionRay &, MKCollisionResult *);
    s32 GetGroundPoint(const MKCollisionRay &, MKCollisionResult *, MKCollisionGroundHint *);
    void EllipsoidsTest(MKCollisionEllipsoid *, int, MKCollisionAABB, MKCollisionResult *);
    void SweepBoxTest(const MKSweptBox &, MKBestResult *, MKBestResult *, MKBestResult *, int, MKCollisionInfo *);
    s32 BoxTest(const MKCollisionBox &, MKCollisionResult *, int);
    s32 SphereTest(const MKCollisionRay &, MKCollisionResult *, int);
    s32 GetVerts(unsigned int, MKVector3 *);
    MKVector3 * GetVerts(MKVector3 *, const unsigned short *);
    s32 Load(void *, int);
    MKCollisionModel * Create(void *, int);
    MKCollisionModel * Create(const char *, MKModel *);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ MKCollisionAABB unk8;
    /* 0x024 */ u8 pad24[0x4];
    /* 0x028 */ f32* unk28;
    /* 0x02c */ MKCollisionRay* unk2C;
    /* 0x030 */ MKHeap* unk30;
    /* 0x034 */ u8 pad34[0x4];
    /* 0x038 */ f64 unk38;
    /* 0x040 */ f32 unk40;
};

u8 MKCollision_Scissor(MKVector3 *, MKVector3 *, int &, int, float);
u8 FindClippedLocalRay(const MKVector3 &, ColGridData *, MKVector3 *, MKVector3 *);
u8 MKCollision_Clip2(float, float, float, float &, float &);
#endif  // COMMON_SOURCE_MKCOLLISIONMODEL_H
