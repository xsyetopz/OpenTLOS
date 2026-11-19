#ifndef SPYRO_SOURCE_KDSPLINE_H
#define SPYRO_SOURCE_KDSPLINE_H

#include <dolphin/types.h>
#include "common/Source/Matrix.h"

class KDSpline;
class KDSpline_cpp;
class KDUniformSpline;
class MKVector3;
class Matrix;

class KDSpline {
public:
    KDSpline(void);
    void Deinit(void);
    void GetMeasure(float, Matrix *);
    s32 AddNode(const MKVector3 &);
    void Init(int, bool);
    /* 0x000 */ s32 unk0;
    /* 0x004 */ s32 unk4;
    /* 0x008 */ f32 unk8;
    /* 0x00c */ s32 unkC;
    /* 0x010 */ u8 unk10;
};

class KDSpline_cpp {
public:
    void __sinit(void);
};

class KDUniformSpline {
public:
    KDUniformSpline(void);
    void GetAcceleration(float) const;
    void GetVelocity(float) const;
    void RegulateSpeed(void);
    void Smooth(void);
    s32 MergeEnds(void);
    void Deinit(void);
    void GetMeasure(float, Matrix *, float *) const;
    void GetMatrix(int, Matrix *) const;
    void GetNextPositionFast(float, Matrix *, int *, float *) const;
    s32 AddNode(const MKVector3 &);
    void Init(void *, int, bool);
    void Init(int, bool);
    /* 0x000 */ s32 unk0;
    /* 0x004 */ s32 unk4;
    /* 0x008 */ f32 unk8;
    /* 0x00c */ s32 unkC;
    /* 0x010 */ u8 unk10;
};

void KDSpline_GetMeasure(const MKVector3 &, const MKVector3 &, const MKVector3 &, const MKVector3 &, float, Matrix *);
extern Matrix splinePosMixer;
extern u8 splineVelMixer[0x40];
extern u8 splineAccMixer[0x40];
extern f32 * KDSpline_PositionMixer;
extern f32 * KDSpline_VelocityMixer;
extern f32 * KDSpline_AccelerationMixer;
#endif  // SPYRO_SOURCE_KDSPLINE_H
