#ifndef SPYRO_SOURCE_TIMEDELTAMODIFIER_H
#define SPYRO_SOURCE_TIMEDELTAMODIFIER_H

#include <dolphin/types.h>

class TimeDeltaModifier;

class TimeDeltaModifier {
public:
    void Disable(int);
    s32 Enable(float, float, float, float);
    void End(void);
    void Begin(void);
    void Reset(void);
    void Init(void);
    /* 0x000 */ f32 unk0;
    /* 0x004 */ f32 unk4;
    /* 0x008 */ f32 unk8;
    /* 0x00c */ f32 unkC;
    /* 0x010 */ f32 unk10;
    /* 0x014 */ f32 unk14;
    /* 0x018 */ f32 unk18;
    /* 0x01c */ f32 unk1C;
    /* 0x020 */ s32 unk20;
    /* 0x024 */ u8 unk24;
};

#endif  // SPYRO_SOURCE_TIMEDELTAMODIFIER_H
