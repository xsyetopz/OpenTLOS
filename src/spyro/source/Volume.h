#ifndef SPYRO_SOURCE_VOLUME_H
#define SPYRO_SOURCE_VOLUME_H

#include <dolphin/types.h>
#include "common/Source/Matrix.h"

class Matrix;
class Volume;
class Volume_cpp;

class Volume {
public:
    void GetRandPos(void);
    void UpdateMatrix(Matrix &);
    void Init(Matrix &);
    static u8 boundingVolume[0x20];
    /* 0x000 */ f64 unk0;
    /* 0x008 */ f64 unk8;
    /* 0x010 */ f64 unk10;
    /* 0x018 */ f64 unk18;
    /* 0x020 */ f64 unk20;
    /* 0x028 */ f64 unk28;
    /* 0x030 */ f64 unk30;
    /* 0x038 */ f64 unk38;
    /* 0x040 */ Matrix unk40;
    /* 0x080 */ f32 unk80;
    /* 0x084 */ f32 unk84;
};

class Volume_cpp {
public:
    void __sinit(void);
};

#endif  // SPYRO_SOURCE_VOLUME_H
