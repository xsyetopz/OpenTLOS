#ifndef SPYRO_SOURCE_KDVOLUME_H
#define SPYRO_SOURCE_KDVOLUME_H

#include <dolphin/types.h>
#include "common/Source/Matrix.h"

class KDVolume;
class KDVolume_cpp;
class MKVector3;
class Matrix;

class KDVolume {
public:
    f32 GetDepth(void);
    f32 GetHeight(void);
    f32 GetWidth(void);
    void UpdateMatrix(Matrix &);
    void GetCenterPos(void);
    s32 IsWithinXZ(const MKVector3 &, float *);
    s32 IsWithin(const MKVector3 &, float *);
    void Deinit(void);
    void Init(Matrix &);
    static u8 boundingVolume[0x20];
    /* 0x000 */ u8 pad0[0x20];
    /* 0x020 */ f32 unk20;
    /* 0x024 */ f32 unk24;
    /* 0x028 */ f32 unk28;
    /* 0x02c */ u8 pad2C[0x4];
    /* 0x030 */ f32 unk30;
    /* 0x034 */ f32 unk34;
    /* 0x038 */ f32 unk38;
    /* 0x03c */ u8 pad3C[0x4];
    /* 0x040 */ Matrix unk40;
    /* 0x080 */ f32 unk80;
    /* 0x084 */ f32 unk84;
};

class KDVolume_cpp {
public:
    void __sinit(void);
};

#endif  // SPYRO_SOURCE_KDVOLUME_H
