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
    /* 0x000 */ u8 pad0[0x40];
    /* 0x040 */ Matrix unk40;
};

class Volume_cpp {
public:
    void __sinit(void);
};

#endif  // SPYRO_SOURCE_VOLUME_H
