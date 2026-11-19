#ifndef UNPLACED_INLINES_H
#define UNPLACED_INLINES_H

#include <dolphin/types.h>

class MKCollisionRay;
class MKCollisionResult;
class MKVector3;
class MKVector4;
class Matrix;

MKVector3 MKVector(float, float, float);
void MKRand_Float(float, float);
MKVector3 Normalise(const MKVector3 &);
MKVector3 KDMath_Sub2D(const MKVector3 &, const MKVector3 &);
MKVector3 NProjection(const MKVector3 &, const MKVector3 &);
MKVector3 ClampMagnitude(const MKVector3 &, float);
MKVector3 InterpolateLinear(const MKVector3 &, const MKVector3 &, float);
MKVector4 MKVector(float, float, float, float);
MKVector3 ApplyMatrix(const MKVector3 &, const Matrix *);
MKVector3 Cross(const MKVector3 &, const MKVector3 &);
MKVector4 InterpolateLinear(const MKVector4 &, const MKVector4 &, float);
MKVector3 Projection(const MKVector3 &, const MKVector3 &);
MKVector3 KDMath_GetReflectedVector(const MKVector3 &, const MKVector3 &);
void Tools_RotateMatrixToDirection(Matrix *, const MKVector3 &, const MKVector3 &, float);
MKVector3 Lerp(MKVector3, MKVector3, float);
u8 MKCollision_RayToSphere(const MKCollisionRay &, const MKVector3 &, float, MKCollisionResult *);
u8 MKCollision_InsideTriBary(const MKVector3 &, const MKVector3 *, unsigned int, unsigned int);
#endif  // UNPLACED_INLINES_H
