#ifndef SPYRO_SOURCE_SPLINETOOLS_H
#define SPYRO_SOURCE_SPLINETOOLS_H

#include <dolphin/types.h>

class KDUniformSpline;
class Matrix;
class SplitPath;

class SplitPath {
public:
    Matrix ** GetPathData(float, float *);
    void GetVelocity(float);
    void GetPosition(float);
    void Deinit(void);
    void Init(const KDUniformSpline &, int, int);
    /* 0x000 */ void* unk0;
    /* 0x004 */ s32 unk4;
    /* 0x008 */ f64 unk8;
};

f32 SplineTools_GetNodeTime(const KDUniformSpline &, int);
#endif  // SPYRO_SOURCE_SPLINETOOLS_H
