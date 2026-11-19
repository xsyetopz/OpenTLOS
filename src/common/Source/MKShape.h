#ifndef COMMON_SOURCE_MKSHAPE_H
#define COMMON_SOURCE_MKSHAPE_H

#include <dolphin/types.h>

class MKCollisionAABB;
class MKVector3;
class MKVector4;
class Matrix;

void MKShape_DrawLine(const MKVector3 &, const MKVector3 &, const MKVector4 &, const MKVector4 &, const Matrix &);
void MKShape_DrawSprite(const MKVector3 &, const MKVector3 &, const MKVector4 &);
void MKShape_DrawPlane(const MKVector3 &, const MKVector3 &, float, const MKVector4 &, const Matrix &, bool);
void MKShape_DrawCapsule(const MKVector3 &, const MKVector3 &, float, int, int, const MKVector4 &, const Matrix &, bool);
void MKShape_DrawSphere(const MKVector4 &, int, int, const MKVector4 &, const Matrix &, bool);
void MKShape_DrawBox(const MKCollisionAABB &, const MKVector4 &, const Matrix &, bool);
void MKShape_DrawBox(const MKVector3 &, const MKVector3 &, const MKVector4 &, const Matrix &, bool);
void MKShape_Deinit(void);
void MKShape_Init(void);
#endif  // COMMON_SOURCE_MKSHAPE_H
