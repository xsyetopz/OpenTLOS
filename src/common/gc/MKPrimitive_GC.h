#ifndef COMMON_GC_MKPRIMITIVE_GC_H
#define COMMON_GC_MKPRIMITIVE_GC_H

#include <dolphin/types.h>

class MKVector3;
class MKVector4;
class Matrix;

void MKPrimitive_DeinitModule(void);
void MKEndPrimitive(void);
void MKEnd(void);
void MKSetPositionV(const MKVector3 &);
void MKSetPositionF(float, float, float);
void MKSetNormalF(float, float, float);
void MKSetTexCoord1F(float, float);
void MKSetColorV(const MKVector4 &);
void MKSetColorF(float, float, float, float);
void MKBegin(int);
void MKSetBaseColorV(const MKVector4 &);
void MKSetBaseColorF(float, float, float, float);
void MKSetMatrix(const Matrix &);
void MKPrimitive(int, int);
#endif  // COMMON_GC_MKPRIMITIVE_GC_H
