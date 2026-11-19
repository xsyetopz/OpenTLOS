#ifndef SPYRO_SOURCE_KDBASICENVELOPE_H
#define SPYRO_SOURCE_KDBASICENVELOPE_H

#include <dolphin/types.h>

class KDBasicEnvelope;

class KDBasicEnvelope {
public:
    f32 GetValue(float);
    void Add(float, float);
    /* 0x000 */ s32 unk0;
    /* 0x004 */ f32 unk4;
    /* 0x008 */ f32 unk8;
    /* 0x00c */ u8 padC[0x4];
    /* 0x010 */ f32 unk10;
};

#endif  // SPYRO_SOURCE_KDBASICENVELOPE_H
