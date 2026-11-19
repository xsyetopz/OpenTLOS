#ifndef COMMON_SOURCE_MKSHOCKWAVE_MP_H
#define COMMON_SOURCE_MKSHOCKWAVE_MP_H

#include <dolphin/types.h>

class MKVector3;

f32 MKShockWave_Height(const MKVector3 &);
u32 MKShockWave_IsWithin(const MKVector3 &, float);
void MKShockWave_Disable(void);
void MKShockWave_Set(int, float, float, float);
void MKShockWave_Enable(const MKVector3 &);
extern u8 gShockWaveData[0x70];
#endif  // COMMON_SOURCE_MKSHOCKWAVE_MP_H
