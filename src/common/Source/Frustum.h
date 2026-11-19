#ifndef COMMON_SOURCE_FRUSTUM_H
#define COMMON_SOURCE_FRUSTUM_H

#include <dolphin/types.h>

class BoundingVolume;
class Frustum;
class MKVector3;
class Matrix;

class Frustum {
public:
    void ApplyMatrix(Frustum *, Matrix *);
    s32 IsVisible(const Matrix *, const BoundingVolume *) const;
    s32 IsVisible(const BoundingVolume *) const;
    s32 IsVisible(const MKVector3 &, float) const;
    /* 0x000 */ f32 unk0;
    /* 0x004 */ f32 unk4;
    /* 0x008 */ f32 unk8;
    /* 0x00c */ u8 padC[0x4];
    /* 0x010 */ f32 unk10;
    /* 0x014 */ f32 unk14;
    /* 0x018 */ f32 unk18;
    /* 0x01c */ u8 pad1C[0x4];
    /* 0x020 */ f32 unk20;
    /* 0x024 */ f32 unk24;
    /* 0x028 */ f32 unk28;
    /* 0x02c */ u8 pad2C[0x4];
    /* 0x030 */ f32 unk30;
    /* 0x034 */ f32 unk34;
    /* 0x038 */ f32 unk38;
    /* 0x03c */ u8 pad3C[0x4];
    /* 0x040 */ f32 unk40;
    /* 0x044 */ f32 unk44;
    /* 0x048 */ f32 unk48;
    /* 0x04c */ u8 pad4C[0xc];
    /* 0x058 */ f32 unk58;
    /* 0x05c */ u8 pad5C[0x4];
    /* 0x060 */ f32 unk60;
    /* 0x064 */ f32 unk64;
};

#endif  // COMMON_SOURCE_FRUSTUM_H
