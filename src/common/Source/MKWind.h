#ifndef COMMON_SOURCE_MKWIND_H
#define COMMON_SOURCE_MKWIND_H

#include <dolphin/types.h>

class MKVector3;
class MKWind;

class MKWind {
public:
    void Init(float, float, float, float, const MKVector3 &, float);
    /* 0x000 */ s8 unk0;
};

void MKWind_GetVelocity(const MKVector3 &);
void MKWind_Update(void);
void MKWind_SetConstantWind(const MKVector3 &);
void MKWind_Set(float, float, float, float, const MKVector3 &, float);
extern MKWind wind;
#endif  // COMMON_SOURCE_MKWIND_H
