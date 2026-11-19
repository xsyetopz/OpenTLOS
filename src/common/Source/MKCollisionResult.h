#ifndef COMMON_SOURCE_MKCOLLISIONRESULT_H
#define COMMON_SOURCE_MKCOLLISIONRESULT_H

#include <dolphin/types.h>

class MKCollisionResult;

class MKCollisionResult {
public:
    void Init(void);
    void * GetProp(void);
    /* 0x000 */ f32 unk0;
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ f32 unk8;
    /* 0x00c */ u8 padC[0x4];
    /* 0x010 */ f32 unk10;
    /* 0x014 */ f32 unk14;
    /* 0x018 */ f32 unk18;
    /* 0x01c */ u8 pad1C[0x4];
    /* 0x020 */ f32 unk20;
    /* 0x024 */ u8 pad24[0x4];
    /* 0x028 */ f32 unk28;
    /* 0x02c */ u8 pad2C[0x4];
    /* 0x030 */ f32 unk30;
    /* 0x034 */ f32 unk34;
    /* 0x038 */ s32 unk38;
    /* 0x03c */ s32 unk3C;
    /* 0x040 */ f32 unk40;
    /* 0x044 */ s32 unk44;
    /* 0x048 */ void* unk48;
    /* 0x04c */ s32 unk4C;
    /* 0x050 */ u8 unk50;
};

#endif  // COMMON_SOURCE_MKCOLLISIONRESULT_H
