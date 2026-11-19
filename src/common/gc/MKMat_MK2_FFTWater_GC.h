#ifndef COMMON_GC_MKMAT_MK2_FFTWATER_GC_H
#define COMMON_GC_MKMAT_MK2_FFTWATER_GC_H

#include <dolphin/types.h>

class MKMaterial;
class MatInfo;

s32 MKMat_MK2_FFTWater_BEGIN_INTERNAL(void);
s32 MKMat_MK2_FFTWater_BEGIN(MKMaterial *);
void MKMat_MK2_FFTWater_DESTROY(MKMaterial *);
void * MKMat_MK2_FFTWater_INIT(MatInfo *);
void MKMat_MK2_FFTWater_DEREGISTER(void);
void MKMat_MK2_FFTWater_REGISTER(void *);
#endif  // COMMON_GC_MKMAT_MK2_FFTWATER_GC_H
