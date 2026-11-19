#ifndef COMMON_GC_MKVIEW_GC_H
#define COMMON_GC_MKVIEW_GC_H

#include <dolphin/types.h>

class MKVector3;
class MKVector4;

void * MKView_GetLightDirection(int);
void * MKView_GetLightColor(int);
void MKView_Clear(int, const MKVector4 &, float, unsigned int);
void MKView_SetAmbientColor(const MKVector4 &);
void MKView_SetLightColor(int, const MKVector4 &);
void MKView_SetLightDirection(int, const MKVector3 &);
#endif  // COMMON_GC_MKVIEW_GC_H
