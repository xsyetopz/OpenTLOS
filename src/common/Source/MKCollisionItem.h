#ifndef COMMON_SOURCE_MKCOLLISIONITEM_H
#define COMMON_SOURCE_MKCOLLISIONITEM_H

#include <dolphin/types.h>
#include "common/Source/MKCollisionManager.h"
#include "common/Source/MKCollisionUtil.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"

class MKBestResult;
class MKCollisionAABB;
class MKCollisionBox;
class MKCollisionCapsuleItem;
class MKCollisionEllipsoid;
class MKCollisionGroundHint;
class MKCollisionInfo;
class MKCollisionItem;
class MKCollisionItemBase;
class MKCollisionManager;
class MKCollisionMode;
class MKCollisionModel;
class MKCollisionModelItem;
class MKCollisionRay;
class MKCollisionResult;
class MKCollisionSphereItem;
class MKHeap;
class MKModel;
class MKSweptBox;
class MKVector3;
class MKVector4;
class Matrix;

class MKCollisionItem : public MKCollisionItemBase {  // base: inlined ctor vtable stores
public:
    virtual void Deinit(void);
    virtual s32 RayCollide(MKCollisionRay &, MKCollisionResult *) = 0;
    virtual s32 GetGroundPoint(const MKCollisionRay &, MKCollisionResult *, MKCollisionGroundHint *);
    virtual void SweepSphereCollide(MKCollisionRay &, MKCollisionResult *) = 0;
    virtual s32 SphereCollide(MKCollisionRay &, MKCollisionResult *, int) = 0;
    virtual s32 BoxCollide(MKCollisionBox &, MKCollisionResult *, int) = 0;
    virtual void SweepBoxCollide(const MKSweptBox &, MKBestResult *, MKBestResult *, MKBestResult *, int) = 0;
    virtual void EllipsoidsTest(MKCollisionEllipsoid *, int, MKCollisionAABB, MKCollisionResult *) = 0;
    virtual void Update(void) = 0;
    virtual s32 GetVerts(unsigned int, MKVector3 *);
    virtual void GetRadius(void) = 0;
    virtual void UnLoad(void);
    virtual void ReLoad(MKModel *);
    void Init(MKCollisionInfo *, int, unsigned int, MKCollisionManager *);
    /* 0x004 */ s32 unk4;
    /* 0x008 */ MKCollisionInfo* unk8;
    /* 0x00c */ s32 unkC;
    /* 0x010 */ u8 pad10[0x20];
    /* 0x030 */ f32 unk30;
    /* 0x034 */ f32 unk34;
    /* 0x038 */ f32 unk38;
    /* 0x03c */ u8 pad3C[0x4];
    /* 0x040 */ f32 unk40;
    /* 0x044 */ f32 unk44;
    /* 0x048 */ f32 unk48;
    /* 0x04c */ u8 pad4C[0x4];
    /* 0x050 */ MKCollisionManager* unk50;
    /* 0x054 */ u32 unk54;
    /* 0x058 */ MKHeap* unk58;
};

class MKCollisionCapsuleItem : public MKCollisionItem {  // base: inlined ctor vtable stores
public:
    virtual s32 RayCollide(MKCollisionRay &, MKCollisionResult *);
    virtual void SweepSphereCollide(MKCollisionRay &, MKCollisionResult *);
    virtual s32 SphereCollide(MKCollisionRay &, MKCollisionResult *, int);
    virtual s32 BoxCollide(MKCollisionBox &, MKCollisionResult *, int);
    virtual void SweepBoxCollide(const MKSweptBox &, MKBestResult *, MKBestResult *, MKBestResult *, int);
    virtual void EllipsoidsTest(MKCollisionEllipsoid *, int, MKCollisionAABB, MKCollisionResult *);
    virtual void Update(void);
    virtual void GetRadius(void);
    void Init(MKVector3 *, MKVector3 *, float, const MKVector4 &, const MKVector4 &, MKCollisionMode, MKCollisionInfo *, int, unsigned int, MKCollisionManager *);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ f64 unk8;
    /* 0x010 */ f64 unk10;
    /* 0x018 */ f64 unk18;
    /* 0x020 */ f64 unk20;
    /* 0x028 */ f64 unk28;
    /* 0x030 */ u8 pad30[0x24];
    /* 0x054 */ s32 unk54;
    /* 0x058 */ u8 pad58[0x8];
    /* 0x060 */ MKVector3 unk60;
    /* 0x070 */ MKVector3 unk70;
    /* 0x080 */ MKVector4 unk80;
    /* 0x090 */ u8 pad90[0x8];
    /* 0x098 */ f64 unk98;
    /* 0x0a0 */ f32 unkA0;
    /* 0x0a4 */ u8 padA4[0x4];
    /* 0x0a8 */ MKVector3* unkA8;
    /* 0x0ac */ MKVector3* unkAC;
};

class MKCollisionModelItem : public MKCollisionItem {  // base: inlined ctor vtable stores
public:
    virtual s32 RayCollide(MKCollisionRay &, MKCollisionResult *);
    virtual s32 GetGroundPoint(const MKCollisionRay &, MKCollisionResult *, MKCollisionGroundHint *);
    virtual void SweepSphereCollide(MKCollisionRay &, MKCollisionResult *);
    virtual s32 SphereCollide(MKCollisionRay &, MKCollisionResult *, int);
    virtual s32 BoxCollide(MKCollisionBox &, MKCollisionResult *, int);
    virtual void SweepBoxCollide(const MKSweptBox &, MKBestResult *, MKBestResult *, MKBestResult *, int);
    virtual void EllipsoidsTest(MKCollisionEllipsoid *, int, MKCollisionAABB, MKCollisionResult *);
    virtual void Update(void);
    virtual s32 GetVerts(unsigned int, MKVector3 *);
    virtual void GetRadius(void);
    virtual void UnLoad(void);
    virtual void ReLoad(MKModel *);
    void LocaliseRay(const MKCollisionRay &);
    void ToWorldResult(const MKCollisionResult &, MKCollisionResult *);
    void Init(MKCollisionModel *, MKModel *, int, MKCollisionMode, MKCollisionInfo *, int, unsigned int, MKCollisionManager *);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ f64 unk8;
    /* 0x010 */ MKCollisionAABB unk10;
    /* 0x02c */ u8 pad2C[0x28];
    /* 0x054 */ s32 unk54;
    /* 0x058 */ u8 pad58[0x8];
    /* 0x060 */ f32 unk60;
    /* 0x064 */ f32 unk64;
    /* 0x068 */ f32 unk68;
    /* 0x06c */ u8 pad6C[0x4];
    /* 0x070 */ f32 unk70;
    /* 0x074 */ f32 unk74;
    /* 0x078 */ f32 unk78;
    /* 0x07c */ u8 pad7C[0x4];
    /* 0x080 */ f32 unk80;
    /* 0x084 */ f32 unk84;
    /* 0x088 */ f32 unk88;
    /* 0x08c */ u8 pad8C[0x4];
    /* 0x090 */ f32 unk90;
    /* 0x094 */ f32 unk94;
    /* 0x098 */ f32 unk98;
    /* 0x09c */ u8 pad9C[0x4];
    /* 0x0a0 */ Matrix unkA0;
    /* 0x0e0 */ u8 padE0[0x40];
    /* 0x120 */ MKCollisionModel* unk120;
    /* 0x124 */ f32 unk124;
    /* 0x128 */ MKModel* unk128;
    /* 0x12c */ s32 unk12C;
};

class MKCollisionSphereItem : public MKCollisionItem {  // base: inlined ctor vtable stores
public:
    virtual s32 RayCollide(MKCollisionRay &, MKCollisionResult *);
    virtual void SweepSphereCollide(MKCollisionRay &, MKCollisionResult *);
    virtual s32 SphereCollide(MKCollisionRay &, MKCollisionResult *, int);
    virtual s32 BoxCollide(MKCollisionBox &, MKCollisionResult *, int);
    virtual void SweepBoxCollide(const MKSweptBox &, MKBestResult *, MKBestResult *, MKBestResult *, int);
    virtual void EllipsoidsTest(MKCollisionEllipsoid *, int, MKCollisionAABB, MKCollisionResult *);
    virtual void Update(void);
    virtual void GetRadius(void);
    void Init(MKVector3 *, float, float, const MKVector4 &, MKCollisionMode, MKCollisionInfo *, int, unsigned int, MKCollisionManager *);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ f64 unk8;
    /* 0x010 */ f64 unk10;
    /* 0x018 */ f64 unk18;
    /* 0x020 */ f64 unk20;
    /* 0x028 */ f64 unk28;
    /* 0x030 */ u8 pad30[0x24];
    /* 0x054 */ s32 unk54;
    /* 0x058 */ u8 pad58[0x8];
    /* 0x060 */ f64 unk60;
    /* 0x068 */ f64 unk68;
    /* 0x070 */ f64 unk70;
    /* 0x078 */ f64 unk78;
    /* 0x080 */ MKVector3* unk80;
    /* 0x084 */ f32 unk84;
    /* 0x088 */ f32 unk88;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#include <m2c_macros.h>

#if 0 // DRAFT: undefined identifier '__vptr'
inline void MKCollisionCapsuleItem::SweepSphereCollide(MKCollisionRay &arg0, MKCollisionResult *arg1) {
    M2C_FIELD(this->__vptr, M2C_UNK (**)(), 0xC)();
}
#endif

inline void MKCollisionCapsuleItem::EllipsoidsTest(MKCollisionEllipsoid *arg0, int arg1, MKCollisionAABB arg2, MKCollisionResult *arg3) {

}

inline s32 MKCollisionItem::GetGroundPoint(const MKCollisionRay &arg0, MKCollisionResult *arg1, MKCollisionGroundHint *arg2) {
    return 0;
}

inline s32 MKCollisionItem::GetVerts(unsigned int arg0, MKVector3 *arg1) {
    return 0;
}

inline void MKCollisionItem::UnLoad() {

}

inline void MKCollisionItem::ReLoad(MKModel *arg0) {

}

inline void MKCollisionSphereItem::EllipsoidsTest(MKCollisionEllipsoid *arg0, int arg1, MKCollisionAABB arg2, MKCollisionResult *arg3) {

}

#endif  // COMMON_SOURCE_MKCOLLISIONITEM_H
