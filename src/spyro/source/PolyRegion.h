#ifndef SPYRO_SOURCE_POLYREGION_H
#define SPYRO_SOURCE_POLYREGION_H

#include <dolphin/types.h>
#include "spyro/source/BoundingRegion.h"

class BoundingRegion;
class MKIniLine;
class MKVector3;
class PolyRegion;

class PolyRegion {
public:
    s32 LoadLine(char *, MKIniLine *);
    void Deinit(void);
    void Init(void);
    /* 0x000 */ MKVector3* unk0;
    /* 0x004 */ BoundingRegion unk4;
    /* 0x020 */ f32 unk20;
    /* 0x024 */ f32 unk24;
    /* 0x028 */ u8 pad28[0x8];
    /* 0x030 */ f32 unk30;
    /* 0x034 */ f32 unk34;
    /* 0x038 */ f32 unk38;
    /* 0x03c */ u8 pad3C[0x4];
    /* 0x040 */ f32 unk40;
    /* 0x044 */ f32 unk44;
    /* 0x048 */ f32 unk48;
};

#endif  // SPYRO_SOURCE_POLYREGION_H
