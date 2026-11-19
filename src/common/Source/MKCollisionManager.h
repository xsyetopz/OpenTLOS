#ifndef COMMON_SOURCE_MKCOLLISIONMANAGER_H
#define COMMON_SOURCE_MKCOLLISIONMANAGER_H

#include <dolphin/types.h>

class MKCollisionAABB;
class MKCollisionCapsuleItem;
class MKCollisionGroundHint;
class MKCollisionInfo;
class MKCollisionItem;
class MKCollisionItemBase;
class MKCollisionManager;
class MKCollisionMode;
class MKCollisionModel;
class MKCollisionResult;
class MKHeap;
class MKModel;
class MKSceneManager;
class MKVector3;
class MKVector4;
class Matrix;

class MKCollisionItemBase {
public:
    virtual void pure_slot0() = 0;  // name unknown: no descendant fills this slot
};

class MKCollisionManager {
public:
    s32 CalcMaxGridOverlap(const MKCollisionAABB &, Matrix *, MKCollisionMode);
    void UpdateItemLinks(MKCollisionItem *, MKCollisionMode);
    MKHeap * CreateCollisionModel(const char *, int);
    MKHeap * CreateCollisionModel(MKModel *, int);
    MKHeap * FindTemplate(const char *);
    s8 * GetFileName(MKModel *, int);
    u8 GetTriVerts(MKCollisionModel *, const MKCollisionResult &, MKVector3 *);
    s32 SphereCollide(const MKVector3 &, float, MKCollisionResult *, int, MKCollisionMode, int);
    u8 SweepSphereCollide(const MKVector3 &, const MKVector3 &, float, MKCollisionResult *, MKCollisionMode, int);
    s32 GetGroundPoint(const MKVector3 &, const MKVector3 &, MKCollisionResult *, int, int, MKCollisionGroundHint *, MKCollisionMode);
    u8 RayCollide(const MKVector3 &, const MKVector3 &, MKCollisionResult *, MKCollisionMode, int);
    void ForceUpdate(unsigned int);
    void AddCapsule(MKVector3 *, MKVector3 *, float, const MKVector4 &, const MKVector4 &, MKCollisionMode, MKCollisionInfo *, unsigned int);
    void AddSphere(MKVector3 *, float, float, const MKVector4 &, MKCollisionMode, MKCollisionInfo *, unsigned int);
    void AddModel(MKModel *, int, MKCollisionMode, MKCollisionInfo *, unsigned int);
    void Update(void);
    u8 Enable(bool);
    void Deinit(void);
    void Init(const char **, int, MKSceneManager *, int);
    MKCollisionManager(void);
    void FindGridOverlap(const MKCollisionAABB &, int *, int *, int *, int *);
    s32 UpdateSphereResults(MKCollisionModel *, int, MKCollisionResult *, int, MKCollisionMode, int);
    /* 0x000 */ f32 unk0;
    /* 0x004 */ f32 unk4;
    /* 0x008 */ f32 unk8;
    /* 0x00c */ u8 padC[0x4];
    /* 0x010 */ f32 unk10;
    /* 0x014 */ f32 unk14;
    /* 0x018 */ f32 unk18;
    /* 0x01c */ u8 pad1C[0x4];
    /* 0x020 */ s32 unk20;
    /* 0x024 */ s8* unk24;
    /* 0x028 */ MKCollisionModel* unk28;
    /* 0x02c */ MKHeap* unk2C;
    /* 0x030 */ MKCollisionCapsuleItem* unk30;
    /* 0x034 */ void** unk34;
    /* 0x038 */ u8 unk38;
};

void GetInterpolatedColorFromPoly(const MKVector3 &, const MKVector3 *);
#endif  // COMMON_SOURCE_MKCOLLISIONMANAGER_H
