#ifndef SPYRO_SOURCE_KDRANDOM_H
#define SPYRO_SOURCE_KDRANDOM_H

#include <dolphin/types.h>

class MKVector3;

void KDRand_Box(float);
void KDRand_Vector(const MKVector3 &, const MKVector3 &);
void KDRand_UnitVectorXZ(void);
void KDRand_UnitVector(void);
f32 KDRand_Gaussian(void);
void KDRand_SetSeed(int);
#endif  // SPYRO_SOURCE_KDRANDOM_H
