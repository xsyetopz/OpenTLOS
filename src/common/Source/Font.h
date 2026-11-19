#ifndef COMMON_SOURCE_FONT_H
#define COMMON_SOURCE_FONT_H

#include <dolphin/types.h>

class CharInfo;
class FontPage;
class Font_cpp;
class MKHeap;
class TextCharStrip;
class TextLineData;

class CharInfo {
public:
    /* 0x000 */ u8 pad0[0x18];
    /* 0x018 */ f32 unk18;
    /* 0x01c */ s32 unk1C;
};

class FontPage {
public:
    /* 0x000 */ s32* unk0;
    /* 0x004 */ s32 unk4;
    /* 0x008 */ u32 unk8;
    /* 0x00c */ u32 unkC;
};

class Font_cpp {
public:
    void __sinit(void);
};

class TextLineData {
public:
    /* 0x000 */ u8 pad0[0x168];
    /* 0x168 */ s32 unk168;
    /* 0x16c */ f32 unk16C;
    /* 0x170 */ f32 unk170;
};

extern MKHeap * drawStringChars;
extern TextCharStrip ** pDrawStringList;
extern s8 * pWorkingText;
#endif  // COMMON_SOURCE_FONT_H
