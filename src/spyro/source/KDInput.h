#ifndef SPYRO_SOURCE_KDINPUT_H
#define SPYRO_SOURCE_KDINPUT_H

#include <dolphin/types.h>

class KDInput;
class MKVector3;

class KDInput {
public:
    f32 GetRightMag(void);
    f32 GetLeftMag(void);
    f32 RumblePlay3D(float, float, float, MKVector3 *, float, char, float, bool);
    void RumbleStop(void);
    void RumblePlay(float, float, float, char, float, bool);
    /* 0x000 */ s32 unk0;
    /* 0x004 */ u8 unk4;
    /* 0x005 */ u8 unk5;
};

#endif  // SPYRO_SOURCE_KDINPUT_H
