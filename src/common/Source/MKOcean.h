#ifndef COMMON_SOURCE_MKOCEAN_H
#define COMMON_SOURCE_MKOCEAN_H

#include <dolphin/types.h>
#include "common/Source/MKFFTWater.h"

class MKFFTNormalMap;
class MKFFTWater;
class MKIniLine;
class MKModel;
class MKOcean;

class MKOcean {
public:
    void Draw(unsigned short *);
    void EndDraw(unsigned short *);
    void Update(void);
    void BuildOceanWaves(void);
    void Deinit(void);
    void LoadDone(void);
    s32 LoadLine(MKIniLine *);
    void Init(MKModel *, const char *, MKFFTWater *);
    /* 0x000 */ s16 unk0;
    /* 0x002 */ u8 pad2[0x2];
    /* 0x004 */ s32 unk4;
    /* 0x008 */ s32 unk8;
    /* 0x00c */ u8 padC[0x4];
    /* 0x010 */ MKFFTNormalMap unk10;
    /* 0x5040 */ u8 pad5040[0x90];
    /* 0x50d0 */ f32 unk50D0;
    /* 0x50d4 */ f32 unk50D4;
    /* 0x50d8 */ u8 pad50D8[0x98];
    /* 0x5170 */ f32 unk5170;
    /* 0x5174 */ f32 unk5174;
    /* 0x5178 */ f32 unk5178;
    /* 0x517c */ f32 unk517C;
    /* 0x5180 */ f32 unk5180;
    /* 0x5184 */ f32 unk5184;
    /* 0x5188 */ u8 pad5188[0x34];
    /* 0x51bc */ u8 unk51BC;
    /* 0x51bd */ u8 pad51BD[0x43];
    /* 0x5200 */ f32 unk5200;
    /* 0x5204 */ f32 unk5204;
    /* 0x5208 */ MKFFTWater* unk5208;
    /* 0x520c */ u8 unk520C;
    /* 0x520d */ u8 pad520D[0x3];
    /* 0x5210 */ f32 unk5210;
    /* 0x5214 */ f32 unk5214;
    /* 0x5218 */ f32 unk5218;
    /* 0x521c */ f32 unk521C;
};

extern u8 areaList[0xc];
#endif  // COMMON_SOURCE_MKOCEAN_H
