#ifndef SPYRO_SOURCE_INPUTMODIFIER_H
#define SPYRO_SOURCE_INPUTMODIFIER_H

#include <dolphin/types.h>

class InputModifier;

class InputModifier {
public:
    s32 Update(void);
    f32 GetRightX(void);
    f32 GetLeftY(void);
    f32 GetLeftX(void);
    /* 0x000 */ s32 unk0;
    /* 0x004 */ u8 unk4;
    /* 0x005 */ u8 unk5;
    /* 0x006 */ u8 pad6[0x2];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ f32 unkC;
};

#endif  // SPYRO_SOURCE_INPUTMODIFIER_H
