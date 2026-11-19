#ifndef SPYRO_SOURCE_KDCAMERAMESSAGES_H
#define SPYRO_SOURCE_KDCAMERAMESSAGES_H

#include <dolphin/types.h>
#include "common/Source/Matrix.h"

class HeroDataMessage;
class Matrix;

class HeroDataMessage {
public:
    void ClearData(void);
    void Init(const Matrix *);
    /* 0x000 */ s32 unk0;
    /* 0x004 */ u8 pad4[0xc];
    /* 0x010 */ Matrix unk10;
    /* 0x09c */ s32 unk9C;
    /* 0x0a0 */ s32 unkA0;
    /* 0x0a4 */ void* unkA4;
    /* 0x0a8 */ void* unkA8;
    /* 0x0ac */ f32 unkAC;
    /* 0x0b0 */ f32 unkB0;
};

#endif  // SPYRO_SOURCE_KDCAMERAMESSAGES_H
