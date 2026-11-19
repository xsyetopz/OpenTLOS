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
    /* 0x050 */ f64 unk50;
    /* 0x058 */ f64 unk58;
    /* 0x060 */ f64 unk60;
    /* 0x068 */ f64 unk68;
    /* 0x070 */ f64 unk70;
    /* 0x078 */ f64 unk78;
    /* 0x080 */ f64 unk80;
    /* 0x088 */ f64 unk88;
    /* 0x090 */ f32 unk90;
    /* 0x094 */ u8 unk94;
    /* 0x095 */ u8 pad95[0x3];
    /* 0x098 */ f32 unk98;
    /* 0x09c */ s32 unk9C;
    /* 0x0a0 */ s32 unkA0;
    /* 0x0a4 */ void* unkA4;
    /* 0x0a8 */ void* unkA8;
    /* 0x0ac */ f32 unkAC;
    /* 0x0b0 */ f32 unkB0;
};

#endif  // SPYRO_SOURCE_KDCAMERAMESSAGES_H
