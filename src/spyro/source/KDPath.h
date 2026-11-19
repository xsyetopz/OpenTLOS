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
    /* 0x000 */ f64 unk0;
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
    /* 0x034 */ f32 unk34;
};

class KDLocalPathSegmentProp : public MKProp {  // base: ctor/dtor vtable stores
public:
    virtual ~KDLocalPathSegmentProp(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual s32 LoadDone(void);
    virtual void Deinit(void);
    virtual f32 Resolve(void);
    /* 0x04c */ KDPathSegment unk4C;
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
    static KDPathSegment * GetPathList(int);
    void RemovePath(KDPathSegment *);
    static void AddPath(KDPathSegment *);
    void Deinit(void);
    void Init(int);
    static u8 pPathLists[0x4];
    static u8 numTypes[0x4];
    /* 0x000 */ s32 unk0;
    /* 0x004 */ s32 unk4;
    /* 0x008 */ f32 unk8;
    /* 0x00c */ f32 unkC;
    /* 0x010 */ s32 unk10;
    /* 0x014 */ u8 unk14;
    /* 0x015 */ u8 pad15[0x3];
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
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x13];
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
    virtual s32 LoadDone(void);
    virtual void Deinit(void);
    virtual f32 Resolve(void);
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
    /* 0x000 */ f64 unk0;
    /* 0x008 */ f32 unk8;
    /* 0x00c */ u8 padC[0x4];
    /* 0x010 */ f64 unk10;
    /* 0x018 */ s16 unk18;
    /* 0x01a */ s16 unk1A;
    /* 0x01c */ s32 unk1C;
    /* 0x020 */ s32 unk20;
    /* 0x024 */ MKVector3* unk24;
    /* 0x028 */ f64 unk28;
    /* 0x030 */ KDUniformSpline unk30;
    /* 0x044 */ s8 unk44;
    /* 0x045 */ s8 unk45;
};

class KDSplinePathSegmentProp : public MKProp {  // base: ctor/dtor vtable stores
public:
    virtual ~KDSplinePathSegmentProp(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual s32 LoadDone(void);
    virtual void Deinit(void);
    virtual f32 Resolve(void);
    /* 0x04c */ KDSplinePathSegment unk4C;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#include <m2c_macros.h>

inline KDLocalPathSegmentProp::~KDLocalPathSegmentProp() {
    s32 temp_cr0_eq_2212;

    temp_cr0_eq_2212 = this == NULL;
    if (temp_cr0_eq_2212 == 0) {
        if (temp_cr0_eq_2212 == 0) {
        }
    }
}

inline KDPathSegmentProp::~KDPathSegmentProp() {
    s32 temp_cr0_eq_2242;

    temp_cr0_eq_2242 = this == NULL;
    if (temp_cr0_eq_2242 == 0) {
        if (temp_cr0_eq_2242 == 0) {
        }
    }
}

inline s32 KDPathSegmentProp::LoadLine(MKIniLine *arg0) {
    s32 var_r31_2274;

    var_r31_2274 = 0;
    if ((MKProp::LoadLine(arg0) != 0) || (((KDPathSegment *) &this->unk4C)->LoadLine(arg0) != 0)) {
        var_r31_2274 = 1;
    }
    return var_r31_2274;
}

inline f32 KDPathSegmentProp::Resolve() {
    MKProp::Resolve();
    ((KDPathSegment *) &this->unk4C)->Resolve();
}

#if 0 // DRAFT: illegal implicit conversion from 'int' to 'Matrix *'
inline void KDSplinePathSegment::GetVelocity(float arg0) {
    KDUniformSpline sp30;
    f64 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    f32 sp8;
    f64 temp_f0_373;

    sp8 = 0.0f;
    sp30.GetMeasure(arg0, M2C_ERROR(/* Read from unset register $r4 */) + 0x30, KDSpline_VelocityMixer);
    sp20 = M2C_BITWISE(f64, sp30);
    sp28 = (f64) sp30.unk8;
    temp_f0_373 = sp20 * (f64) sp8;
    sp10 = temp_f0_373;
    this->unk0 = temp_f0_373;
    sp18 = (f32) sp28 * sp8;
    M2C_FIELD(this, f64 *, 8) = (f64) sp18;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'int' to 'Matrix *'
inline void KDSplinePathSegment::GetPosition(float arg0) {
    f32 sp8;

    sp8 = 0.0f;
    ((KDUniformSpline *) this)->GetMeasure(arg0, M2C_ERROR(/* Read from unset register $r4 */) + 0x30, KDSpline_PositionMixer);
}
#endif

inline KDSplinePathSegmentProp::~KDSplinePathSegmentProp() {
    s32 temp_cr0_eq_15;

    temp_cr0_eq_15 = this == NULL;
    if (temp_cr0_eq_15 == 0) {
        if (temp_cr0_eq_15 == 0) {
        }
    }
}

inline s32 KDSplinePathSegmentProp::LoadLine(MKIniLine *arg0) {
    s32 var_r31_47;

    var_r31_47 = 0;
    if ((MKProp::LoadLine(arg0) != 0) || (((KDSplinePathSegment *) &this->unk4C)->LoadLine(arg0) != 0)) {
        var_r31_47 = 1;
    }
    return var_r31_47;
}

inline f32 KDSplinePathSegmentProp::Resolve() {
    MKProp::Resolve();
    ((KDPathSegment *) &this->unk4C)->Resolve();
}

#endif  // SPYRO_SOURCE_KDPATH_H
