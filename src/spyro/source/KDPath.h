#ifndef SPYRO_SOURCE_KDPATH_H
#define SPYRO_SOURCE_KDPATH_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"
#include "spyro/source/KDSpline.h"

class KDLocalPathSegment;
class KDLocalPathSegmentProp;
class KDPathIterator;
class KDPathManager;
class KDPathNode;
class KDPathPoint;
class KDPathSegment;
class KDPathSegmentProp;
class KDSplinePathSegment;
class KDSplinePathSegmentProp;
class KDUniformSpline;
class MKHeap;
class MKIniLine;
class MKProp;
class MKSceneManager;
class MKVector3;
class Matrix;

class KDLocalPathSegment {
public:
    void Init(KDLocalPathSegmentProp *);
    /* 0x000 */ u8 pad0[0x1a];
    /* 0x01a */ s16 unk1A;
    /* 0x01c */ u8 pad1C[0x14];
    /* 0x030 */ void* unk30;
    /* 0x034 */ KDLocalPathSegmentProp* unk34;
};

class KDPathSegment {
public:
    void GetPositionAlongPath(float, MKVector3 &);
    void * GetNearestPointXZ(const MKVector3 &);
    s32 GetIndexOf(KDPathPoint *) const;
    void Resolve(void);
    void LoadDone(void);
    void CopyWaypointArray(MKVector3 *, int);
    u8 LoadWaypoints(MKIniLine *, const char *);
    u8 LoadLine(MKIniLine *);
    void Deinit(void);
    void Init(void);
    /* 0x000 */ u8 pad0[0x8];
    /* 0x008 */ f64 unk8;
    /* 0x010 */ MKHeap* unk10;
    /* 0x014 */ s32 unk14;
    /* 0x018 */ s16 unk18;
    /* 0x01a */ s16 unk1A;
    /* 0x01c */ s32 unk1C;
    /* 0x020 */ s32 unk20;
    /* 0x024 */ void* unk24;
    /* 0x028 */ KDPathSegment* unk28;
    /* 0x02c */ s32 unk2C;
    /* 0x030 */ Matrix* unk30;
};

class KDLocalPathSegmentProp : public MKProp {  // base: ctor/dtor vtable stores
public:
    virtual ~KDLocalPathSegmentProp(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    /* 0x04c */ KDPathSegment unk4C;
    /* 0x080 */ u8 pad80[0x4];
    /* 0x084 */ MKSceneManager* unk84;
};

class KDPathIterator {
public:
    void SetTo(KDPathSegment *, int);
    void Init(void);
    /* 0x000 */ void* unk0;
    /* 0x004 */ s32 unk4;
    /* 0x008 */ u8 unk8;
};

class KDPathManager {
public:
    void NearestPointLocalSegment(int, const MKVector3 &);
    void NearestPoint(int, const MKVector3 &);
    KDPathSegment * GetPathList(int);
    void RemovePath(KDPathSegment *);
    void AddPath(KDPathSegment *);
    void Deinit(void);
    void Init(int);
    /* 0x000 */ u8 pad0[0x4];
    /* 0x004 */ s32 unk4;
    /* 0x008 */ f32 unk8;
    /* 0x00c */ f32 unkC;
    /* 0x010 */ u8 pad10[0x8];
    /* 0x018 */ s16 unk18;
    /* 0x01a */ u8 pad1A[0x2];
    /* 0x01c */ s32 unk1C;
    /* 0x020 */ s32 unk20;
    /* 0x024 */ void* unk24;
    /* 0x028 */ KDPathNode* unk28;
    /* 0x02c */ KDPathNode* unk2C;
};

class KDPathNode {
public:
    void CountBranches(void);
    void Unlink(void);
    void Link(KDPathNode *);
    void Init(KDPathSegment *, bool);
    /* 0x000 */ KDPathNode* unk0;
    /* 0x004 */ u8 unk4;
    /* 0x005 */ u8 unk5;
    /* 0x006 */ s8 unk6;
    /* 0x007 */ s8 unk7;
    /* 0x008 */ u8 pad8[0x14];
    /* 0x01c */ s32 unk1C;
    /* 0x020 */ s32 unk20;
    /* 0x024 */ void* unk24;
    /* 0x028 */ KDPathNode* unk28;
    /* 0x02c */ KDPathNode* unk2C;
};

class KDPathSegmentProp : public MKProp {  // base: ctor/dtor vtable stores
public:
    virtual ~KDPathSegmentProp(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    /* 0x04c */ KDPathSegment unk4C;
};

class KDSplinePathSegment {
public:
    void GetVelocity(float);
    void LoadDone(void);
    u8 LoadWaypoints(MKIniLine *, const char *);
    u8 LoadLine(MKIniLine *, const char *);
    u8 LoadLine(MKIniLine *);
    void Deinit(void);
    void Init(void);
    void GetPosition(float);
    /* 0x000 */ u8 pad0[0x18];
    /* 0x018 */ s16 unk18;
    /* 0x01a */ s16 unk1A;
    /* 0x01c */ s32 unk1C;
    /* 0x020 */ s32 unk20;
    /* 0x024 */ MKVector3* unk24;
    /* 0x028 */ u8 pad28[0x8];
    /* 0x030 */ KDUniformSpline unk30;
    /* 0x044 */ s8 unk44;
    /* 0x045 */ s8 unk45;
};

class KDSplinePathSegmentProp : public MKProp {  // base: ctor/dtor vtable stores
public:
    virtual ~KDSplinePathSegmentProp(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    /* 0x04c */ KDSplinePathSegment unk4C;
};

#endif  // SPYRO_SOURCE_KDPATH_H
