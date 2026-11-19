#ifndef COMMON_SOURCE_MKVECTOR4_H
#define COMMON_SOURCE_MKVECTOR4_H

#include <dolphin/types.h>

class MKVector4;

class MKVector4 {
public:
    MKVector4 operator*(float) const;
    static MKVector4 zero;
    static MKVector4 one;
    static u8 up[0x10];
    static MKVector4 identity;
    /* 0x000 */ f32 unk0;
    /* 0x004 */ f32 unk4;
    /* 0x008 */ f32 unk8;
    /* 0x00c */ f32 unkC;
} __attribute__((aligned(8)));

#endif  // COMMON_SOURCE_MKVECTOR4_H
