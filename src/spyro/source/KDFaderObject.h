#ifndef SPYRO_SOURCE_KDFADEROBJECT_H
#define SPYRO_SOURCE_KDFADEROBJECT_H

#include <dolphin/types.h>

class KDFaderObject;

class KDFaderObject {
public:
    class FadeMode;
    class FadeState;
    f32 GetFadePercentage(void);
    s32 GetNextState(KDFaderObject::FadeState, KDFaderObject::FadeMode);
    void Fade(KDFaderObject::FadeMode, float, float, float, bool);
    void Update(void);
    void Reset(void);
    /* 0x000 */ s32 unk0;
    /* 0x004 */ s32 unk4;
    /* 0x008 */ s32 unk8;
    /* 0x00c */ f32 unkC;
    /* 0x010 */ f32 unk10;
    /* 0x014 */ f32 unk14;
    /* 0x018 */ f32 unk18;
};

#endif  // SPYRO_SOURCE_KDFADEROBJECT_H
