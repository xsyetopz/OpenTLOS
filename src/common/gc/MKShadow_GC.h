#ifndef COMMON_GC_MKSHADOW_GC_H
#define COMMON_GC_MKSHADOW_GC_H

#include <dolphin/types.h>

class MKModel;
class MKVector3;
class MKVector4;
class Matrix;

void MKShadow_EndScene(bool, bool, MKVector4 *);
void MKShadow_Render(MKModel *, const MKVector3 &, float, const MKVector3 &, const MKVector3 *, bool);
void MKShadow_BeginScene(void);
void MKShadow_InitModule(void);
extern void * pShadowVertexBuffer;
extern Matrix * pShadowEdgeResultBuffer;
#endif  // COMMON_GC_MKSHADOW_GC_H
