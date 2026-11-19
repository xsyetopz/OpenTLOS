#ifndef SPYRO_SOURCE_WINDFX_H
#define SPYRO_SOURCE_WINDFX_H

#include <dolphin/types.h>

class MKVector3;
class WindFX;

class WindFX {
public:
    MKVector3 GetSwirlVelocity(const MKVector3 &);
    void GetGlobalVelocity(const MKVector3 &);
    void GetVelocity(const MKVector3 &);
    void Init(int, float, const MKVector3 &, const MKVector3 &);
    /* 0x000 */ f64 unk0;
    /* 0x008 */ f64 unk8;
    /* 0x010 */ f32 unk10;
    /* 0x014 */ s32 unk14;
    /* 0x018 */ f32 unk18;
    /* 0x01c */ f32 unk1C;
    /* 0x020 */ f64 unk20;
    /* 0x028 */ f64 unk28;
};

#endif  // SPYRO_SOURCE_WINDFX_H
