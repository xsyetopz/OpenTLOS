#ifndef COMMON_SOURCE_OMNILIGHT_H
#define COMMON_SOURCE_OMNILIGHT_H

#include <dolphin/types.h>

class MKVector3;
class OmniLight;

class OmniLight {
public:
    void CalculateColor(const MKVector3 &, const MKVector3 &);
    static u8 totalEnabled[0x4];
    /* 0x000 */ f64 unk0;
    /* 0x008 */ f64 unk8;
    /* 0x010 */ f64 unk10;
    /* 0x018 */ f64 unk18;
    /* 0x020 */ f32 unk20;
    /* 0x024 */ u8 pad24[0x4];
    /* 0x028 */ f32 unk28;
    /* 0x02c */ u8 pad2C[0x4];
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
