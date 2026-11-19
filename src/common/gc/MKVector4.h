#ifndef COMMON_GC_MKVECTOR4_H
#define COMMON_GC_MKVECTOR4_H

#include <dolphin/types.h>

class MKVector4;

class MKVector4 {
public:
    void operator*(float) const;
    /* 0x000 */ f64 unk0;
    /* 0x008 */ f64 unk8;
    /* 0x010 */ u8 pad10[0x8];
    /* 0x018 */ f32 unk18;
    /* 0x01c */ u8 pad1C[0x4];
    /* 0x020 */ f32 unk20;
    /* 0x024 */ u8 pad24[0x4];
    /* 0x028 */ f32 unk28;
};

#endif  // COMMON_GC_MKVECTOR4_H
