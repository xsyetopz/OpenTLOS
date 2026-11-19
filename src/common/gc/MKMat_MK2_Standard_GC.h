#ifndef COMMON_GC_MKMAT_MK2_STANDARD_GC_H
#define COMMON_GC_MKMAT_MK2_STANDARD_GC_H

#include <dolphin/types.h>
#include "unplaced_enums.h"

class MKMat_MK2_Standard_GC_cpp;
class MKMaterial;
class MKVector3;

class MKMat_MK2_Standard_GC_cpp {
public:
    void __sinit(void);
};

void DrawQuad(const MKVector3 &, const MKVector3 &, const MKVector3 &, const MKVector3 &, unsigned int);
void MKMat_MK2_ApplyGlow(float, MKMat_Glow_Viewport);
void MKMat_MK2_Standard_DEREGISTER(void);
void MKMat_MK2_Standard_REGISTER(void *);
s32 MKMat_MK2_Standard_BEGIN_INTERNAL(void);
s32 MKMat_MK2_Standard_BEGIN(MKMaterial *);
extern s8 MKMat_MK2_Standard_CaptureTextureData;
extern u8 MKMaterial_NumTexGens[0x1];
extern u8 MKMaterial_NumTevStages;
extern u8 MKLight_LightMask;
#endif  // COMMON_GC_MKMAT_MK2_STANDARD_GC_H
