#ifndef SPYRO_SOURCE_KDMATH_H
#define SPYRO_SOURCE_KDMATH_H

#include <dolphin/types.h>

class MKVector3;
class Matrix;

f32 KDMath_GetTurningCircleRadius(float, float);
void KDMath_NormalisedSlerp(const MKVector3 &, const MKVector3 &, float);
void KDMath_Slerp(const MKVector3 &, const MKVector3 &, float);
void KDMath_LocaliseVector(const MKVector3 &, MKVector3 *, const MKVector3 &);
void KDMath_LocaliseVector(const Matrix *, const MKVector3 &);
void KDMath_RotateVectorByYaw(const MKVector3 &, float);
s32 KDMath_BuildMatrixFromUp(Matrix *, const MKVector3 &, const MKVector3 &);
s8 KDMath_BuildMatrixFromFwd(Matrix *, const MKVector3 &, MKVector3 *);
f32 KDMath_GetPitch(const MKVector3 &);
f32 KDMath_GetYaw(const MKVector3 &);
void KDMath_GetYaw(const Matrix *);
void KDMath_GetDirection(float, float);
void KDMath_GetDirection(float);
void KDMath_GetDirection(const Matrix *);
void KDMath_TurnToAngle(float, float, float);
void KDMath_TurnToAngle(float, float, float, float);
void KDMath_SmoothToAngle(float, float, float);
void KDMath_SmoothToAngle(float, float, float, float);
f32 KDMath_NormaliseAngle(float);
f32 KDMath_GetSmallestAngle(float, float);
#endif  // SPYRO_SOURCE_KDMATH_H
