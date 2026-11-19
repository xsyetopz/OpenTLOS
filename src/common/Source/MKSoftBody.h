#ifndef COMMON_SOURCE_MKSOFTBODY_H
#define COMMON_SOURCE_MKSOFTBODY_H

#include <dolphin/types.h>

class ClothCollisionHull;
class ClothNode;
class MKCloth;
class MKClothManager;
class MKCollisionAABB;
class MKHeap;
class MKModel;
class MKVector3;
class MKVector4;
class Matrix;
class ModelCloth;
class SoftSweepSphere;

class ClothCollisionHull {
public:
    /* 0x000 */ f32 unk0;
    /* 0x004 */ f32 unk4;
    /* 0x008 */ f32 unk8;
    /* 0x00c */ u8 padC[0x4];
    /* 0x010 */ f32 unk10;
    /* 0x014 */ f32 unk14;
    /* 0x018 */ f32 unk18;
    /* 0x01c */ u8 pad1C[0x4];
    /* 0x020 */ f32 unk20;
    /* 0x024 */ f32 unk24;
    /* 0x028 */ f32 unk28;
    /* 0x02c */ u8 pad2C[0x4];
    /* 0x030 */ f32 unk30;
    /* 0x034 */ f32 unk34;
    /* 0x038 */ f32 unk38;
};

class MKCloth {
public:
    void DisableClothCreate(bool);
    void LightCloth(void);
    void SatisfyConstraints(void);
    void ApplyCollision(void);
    void CollideHull(ClothNode *, int, ClothCollisionHull &, const Matrix *);
    void UpdatePosition(void);
    void IncludeCollision(void);
    void DrawConstraints(void);
    void UpdateGlobalCollisionPrims(void);
    ClothNode ** GetName(void);
    void SetIterations(int);
    void SetFriction(float);
    void SetCollisionCapsule(int, const MKVector3 &, const MKVector3 &, float);
    s32 AllocateCapsule(void);
    void SetCollisionPlane(int, const MKVector3 &, const MKVector3 &, float);
    s32 AllocatePlane(void);
    void SetCollisionSphere(int, const MKVector4 &);
    s32 AllocateSphere(void);
    void MoveCollisionSweepSphere(int, const MKVector3 &);
    void ResetCollisionSweepSphere(int, MKVector4 *);
    void ReleaseSweepSphere(int);
    s32 AllocateSweepSphere(void);
    void SetInternalCollisionCapsule(int, const MKVector3 &, const MKVector3 &, float, float);
    void CreateInternalCollisionCapsules(int);
    void SetInternalCollisionSphere(int, const MKVector4 &);
    void CreateInternalCollisionSpheres(int);
    void SetInternalCollisionPlane(int, const MKVector3 &, const MKVector3 &, float);
    void CreateInternalCollisionPlanes(int);
    void SetForce(int, const MKVector3 &, int);
    void CreateForces(int);
    void SetNode(int, const MKVector3 &, float);
    void ApplyScale(const MKVector3 &);
    void Teleport(const Matrix &);
    void Settle(int, Matrix *);
    void Reset(void);
    void GetWorldBindPos(int);
    f64 GetWorldPos(MKVector3 &, int, Matrix *);
    void UpdateInternal(Matrix *);
    void UpdateCollisionPrims(void);
    void Draw(void);
    void Deinit(void);
    void Create(void);
    void Init(void);
    static MKCloth globalCollisionPrim;
    static MKCloth sweepSpheres;
    static MKCloth spheres;
    static MKCloth planes;
    static MKCloth capsules;
    static u8 globalForces[0x60];
    static u8 includedSweepCount[0x4];
    static u8 includedSphereCount[0x4];
    static u8 includedPlaneCount[0x4];
    static u8 includedCapsuleCount[0x4];
    static u8 clothCreateDisabled[0x1];
    /* 0x000 */ u8 pad0[0x4];
    /* 0x004 */ MKHeap* unk4;
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ MKModel* unkC;
    /* 0x010 */ f32 unk10;
    /* 0x014 */ f32 unk14;
    /* 0x018 */ f32 unk18;
    /* 0x01c */ u8 pad1C[0x4];
    /* 0x020 */ f32 unk20;
    /* 0x024 */ f32 unk24;
    /* 0x028 */ f32 unk28;
    /* 0x02c */ u8 pad2C[0x4];
    /* 0x030 */ s8* unk30;
    /* 0x034 */ u8 pad34[0x64];
    /* 0x098 */ u32 unk98;
    /* 0x09c */ u8 unk9C;
    /* 0x09d */ u8 unk9D;
    /* 0x09e */ u8 pad9E[0x2];
    /* 0x0a0 */ f32 unkA0;
    /* 0x0a4 */ f32 unkA4;
    /* 0x0a8 */ MKModel** unkA8;
    /* 0x0ac */ s8* unkAC;
    /* 0x0b0 */ s32 unkB0;
    /* 0x0b4 */ MKModel** unkB4;
    /* 0x0b8 */ s8* unkB8;
    /* 0x0bc */ s32 unkBC;
    /* 0x0c0 */ MKModel** unkC0;
    /* 0x0c4 */ s8* unkC4;
    /* 0x0c8 */ s32 unkC8;
    /* 0x0cc */ s32 unkCC;
    /* 0x0d0 */ s32 unkD0;
    /* 0x0d4 */ f32 unkD4;
    /* 0x0d8 */ s32 unkD8;
    /* 0x0dc */ s32 unkDC;
    /* 0x0e0 */ f64 unkE0;
    /* 0x0e8 */ f64 unkE8;
    /* 0x0f0 */ u8 unkF0;
};

class MKClothManager {
public:
    void Update(void);
    void RemoveModel(MKModel *);
    void AddModel(MKModel *);
    void Deinit(void);
    void Init(void);
    /* 0x000 */ MKModel** unk0;
};

class ModelCloth {
public:
    void Draw(void);
    void Update(void);
    /* 0x000 */ s32 unk0;
    /* 0x004 */ s32 unk4;
    /* 0x008 */ void* unk8;
    /* 0x00c */ u8 padC[0x4];
    /* 0x010 */ f64 unk10;
    /* 0x018 */ f64 unk18;
    /* 0x020 */ f64 unk20;
    /* 0x028 */ f64 unk28;
    /* 0x030 */ s8 unk30;
    /* 0x031 */ s8 unk31;
};

class SoftSweepSphere {
public:
    f32 UpdatePos(const MKVector3 &);
    s32 TestPoint(const MKVector3 &, MKVector3 *);
    void GetBoundingBox(MKCollisionAABB *);
    void Init(MKVector4 *);
    /* 0x000 */ f64 unk0;
    /* 0x008 */ f64 unk8;
    /* 0x010 */ f64 unk10;
    /* 0x018 */ f64 unk18;
    /* 0x020 */ f64 unk20;
    /* 0x028 */ f64 unk28;
    /* 0x030 */ f32 unk30;
    /* 0x034 */ f32 unk34;
    /* 0x038 */ u8 unk38;
};

void SoftBody_Deinit(void);
void SoftBody_Init(void);
extern u8 MKSoftBody_enableCloth[0x4];
extern MKClothManager gClothManager;
extern s32 MKSoftBody_showCollision;
extern s32 MKSoftBody_showConstraints;
extern s32 MKSoftBody_enableBoundBox;
#endif  // COMMON_SOURCE_MKSOFTBODY_H
