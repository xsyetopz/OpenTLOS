#ifndef SPYRO_SOURCE_TOOLS_H
#define SPYRO_SOURCE_TOOLS_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"

class KDUniformSpline;
class MKCollisionMode;
class MKCollisionResult;
class MKIniLine;
class MKMaterial;
class MKMessage;
class MKModel;
class MKProp;
class MKPropDescriptor;
class MKVector3;
class Matrix;
class PushOutResult;
class SubObjectType;
class TimerInfo;
class Tools_Ortho;
class Tools_PropCreator;
class Tools_PropCreatorObject;
class Tools_ResolvableProp;
class Tools_SendMessageHelper;
class Tools_cpp;

class PushOutResult {
public:
    /* 0x000 */ f64 unk0;
    /* 0x008 */ f64 unk8;
    /* 0x010 */ f64 unk10;
    /* 0x018 */ f64 unk18;
};

class Tools_Ortho {
public:
    ~Tools_Ortho(void);
    Tools_Ortho(void);
    /* 0x000 */ u8 unk0;
};

class Tools_PropCreatorObject {
public:
    void Deinit(void);
    void Init(const char *, int);
    /* 0x000 */ s32 unk0;
    /* 0x004 */ void* unk4;
    /* 0x008 */ s32 unk8;
};

class Tools_PropCreator : public MKProp {  // base: ctor/dtor vtable stores
public:
    virtual ~Tools_PropCreator(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    /* 0x04c */ Tools_PropCreatorObject unk4C;
};

class Tools_ResolvableProp {
public:
    void LoadLine(MKIniLine *, const char *);
    /* 0x000 */ u8 pad0[0x4];
    /* 0x004 */ s32 unk4;
};

class Tools_SendMessageHelper {
public:
    void ClearData(void);
    void SendMessage(MKMessage *, int, float);
    void StoreClosestProps(const MKVector3 &, float, int);
    /* 0x000 */ u8 pad0[0x7f8];
    /* 0x7f8 */ s32 unk7F8;
};

class Tools_cpp {
public:
    void __sinit(void);
};

MKMaterial * Tools_GetMatchingMaterial(MKModel *, const char *);
void Tools_CalculateVelocity(const MKVector3 &, const MKVector3 &, float, float);
s32 Tools_GetPointDistanceFromLine(const MKVector3 &, const MKVector3 &, const MKVector3 &, float *);
void Tools_UnPauseAll(void);
void Tools_ResetEachInstance(MKPropDescriptor *);
void Tools_PushOut(MKCollisionResult *, MKVector3 &, int, float, bool *, float);
void Tools_GetClosestSplineTimeXZ(KDUniformSpline *, const MKVector3 &, int);
f32 Tools_GetClosestSplineTimeXZ(KDUniformSpline *, const MKVector3 &, int, float, float);
void Tools_GetClosestSplineTime(KDUniformSpline *, const MKVector3 &, int);
f32 Tools_GetClosestSplineTime(KDUniformSpline *, const MKVector3 &, int, float, float);
void Tools_EnableWideScreen(bool);
s32 Tools_Line2DToCircleIntersect(const MKVector3 &, const MKVector3 &, const MKVector3 &, float, float &);
void Tools_GetClosestPtOnLine2D(const MKVector3 &, const MKVector3 &, const MKVector3 &);
s32 Tools_Line2DToLine2DIntersect(const MKVector3 &, const MKVector3 &, const MKVector3 &, const MKVector3 &, float *);
void Tools_UpdateSphereCollideResults(MKCollisionResult *, int, const MKVector3 &);
void Tools_SetMatrixScale(Matrix *, float);
s32 Tools_GetFloor(const MKVector3 &, float, float *);
f32 Tools_CylinderTest(const MKVector3 &, const MKVector3 &, float, const MKVector3 &);
void Tools_TestFloor(const MKVector3 &, MKCollisionResult *, float, MKCollisionMode);
void Tools_GroundColor(MKCollisionResult *);
void Tools_GetGradient(const MKVector3 &);
void Tools_GetDateString(TimerInfo *);
s32 Tools_GetTimeInSeconds(void);
u16 Tools_GetMatchingSubObjectIndex(SubObjectType, MKModel *, const char *);
u16 Tools_GetMatchingRefPointIndex(MKModel *, const char *);
u16 Tools_GetMatchingNodeIndex(MKModel *, const char *);
extern s32 pauseSndCount;
// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline Tools_PropCreator::~Tools_PropCreator() {
    s32 temp_cr0_eq_15;

    temp_cr0_eq_15 = this == NULL;
    if (temp_cr0_eq_15 == 0) {
        if (temp_cr0_eq_15 == 0) {
        }
    }
}

#endif  // SPYRO_SOURCE_TOOLS_H
