#ifndef SPYRO_SOURCE_CHARACTERBREATHFX_H
#define SPYRO_SOURCE_CHARACTERBREATHFX_H

#include <dolphin/types.h>

class CharacterBreathFX;
class CharacterBreathFXDescriptor;
class MKModel;

class CharacterBreathFX {
public:
    void UpdateBreathingFX(void);
    void EmitConeBreathFx(int, float, float, float, float, float);
    void EmitBreathFx(int, float, float, float, float, float);
    void SetDefaults(void);
    void Deinit(void);
    void Init(CharacterBreathFXDescriptor *, MKModel *);
    /* 0x000 */ s32* unk0;
    /* 0x004 */ MKModel* unk4;
    /* 0x008 */ f32 unk8;
    /* 0x00c */ f32 unkC;
    /* 0x010 */ u8 unk10;
};

class CharacterBreathFXDescriptor {
public:
    void Init(void);
    /* 0x000 */ u32 unk0;
    /* 0x004 */ s32 unk4;
    /* 0x008 */ f32 unk8;
    /* 0x00c */ f32 unkC;
    /* 0x010 */ f32 unk10;
    /* 0x014 */ f32 unk14;
    /* 0x018 */ f32 unk18;
    /* 0x01c */ f32 unk1C;
};

#endif  // SPYRO_SOURCE_CHARACTERBREATHFX_H
