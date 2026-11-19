#ifndef COMMON_SOURCE_STDMATH_H
#define COMMON_SOURCE_STDMATH_H

#include <dolphin/types.h>

class MKVector3;

s32 MKLinesIntersect(const MKVector3 &, const MKVector3 &, const MKVector3 &, const MKVector3 &);
f32 NormaliseAngle(float);
void _table_sincosf(float, float &, float &);
f32 _table_sinf(float);
f32 ApproxMagnitude(float, float);
f32 MKRand_Float(int *, float, float);
s32 MKRand_Int(int *, int, int);
extern u8 _sinTable[0x1004];
extern s32 gViewSeed;
#endif  // COMMON_SOURCE_STDMATH_H
