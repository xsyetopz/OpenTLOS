#ifndef COMMON_SOURCE_OMNILIGHT_H
#define COMMON_SOURCE_OMNILIGHT_H

#include <dolphin/types.h>

class MKVector3;
class OmniLight;

class OmniLight {
public:
    void CalculateColor(const MKVector3 &, const MKVector3 &);
    /* 0x000 */ f64 unk0;
    /* 0x008 */ f64 unk8;
    /* 0x010 */ u8 pad10[0x20];
    /* 0x030 */ u8 unk30;
};

s32 OmniLight_FindNearestGroup(const MKVector3 &, float, OmniLight **, int);
void OmniLight_FindNearest(const MKVector3 &, float);
u8 OmniLight_SuspendAll(bool);
void OmniLight_Destroy(OmniLight *);
void OmniLight_Create(void);
void OmniLight_DeinitModule(void);
void OmniLight_InitModule(void);
#endif  // COMMON_SOURCE_OMNILIGHT_H
