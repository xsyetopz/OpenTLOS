#ifndef SPYRO_SOURCE_SPYROEFFECTS_H
#define SPYRO_SOURCE_SPYROEFFECTS_H

#include <dolphin/types.h>
#include "common/Source/MKVector3.h"
#include "spyro/source/CharacterBodyFX.h"
#include "spyro/source/KDSoundTools.h"

class BoneBlurFX;
class CharacterBodyFX;
class CharacterBodyFXData;
class ConvexityBreathFX;
class EarthBreathFX;
class FlameBreathFX;
class FuryFXConvexity;
class IceBreathFX;
class KDInput;
class KDSound_AfterRumble;
class LineSegmentTrail;
class MKAnimScript;
class MKMaterial;
class MKModel;
class MKProp;
class MKVector3;
class MeleeTrails;
class SpyroEffects;
class SpyroEffectsUpdateData;
class SpyroEffects_cpp;
class SpyroFXData;
class SpyroSoundPlayer;
class ZapBreathFX;

class SpyroEffects {
public:
    virtual u8 TriggerFire(SpyroEffectsUpdateData *);
    virtual u8 TriggerIce(SpyroEffectsUpdateData *);
    virtual u8 TriggerElectricity(SpyroEffectsUpdateData *);
    virtual void TriggerEarth(SpyroEffectsUpdateData *);
    virtual u8 TriggerFury(SpyroEffectsUpdateData *);
    virtual void TriggerConvexity(SpyroEffectsUpdateData *);
    virtual void SoundFadeOut(void);
    void UpdateFury(SpyroEffectsUpdateData *);
    void Update(SpyroEffectsUpdateData *, KDInput *);
    void ResetFury(void);
    void Deinit(void);
    void Init(SpyroFXData *, MKProp *, SpyroSoundPlayer *);
    /* 0x004 */ void* unk4;
    /* 0x008 */ MKProp* unk8;
    /* 0x00c */ KDInput* unkC;
    /* 0x010 */ SpyroSoundPlayer* unk10;
    /* 0x014 */ u8 unk14;
};

class SpyroEffectsUpdateData {
public:
    /* 0x000 */ u8 pad0[0x8];
    /* 0x008 */ f32 unk8;
    /* 0x00c */ u8 padC[0x4];
    /* 0x010 */ MKVector3 unk10;
    /* 0x020 */ void* unk20;
    /* 0x024 */ s32 unk24;
    /* 0x028 */ s32 unk28;
    /* 0x02c */ u8 unk2C;
    /* 0x02d */ u8 pad2D[0x3];
    /* 0x030 */ u8* unk30;
    /* 0x034 */ u8 unk34;
    /* 0x035 */ u8 pad35[0x3];
    /* 0x038 */ u8* unk38;
    /* 0x03c */ u8 unk3C;
    /* 0x03d */ u8 unk3D;
    /* 0x03e */ u8 unk3E;
    /* 0x03f */ u8 unk3F;
};

class SpyroEffects_cpp {
public:
    void __sinit(void);
};

class SpyroFXData {
public:
    void Deinit(void);
    void Init(MKProp *, MKModel *, MKAnimScript *);
    /* 0x000 */ CharacterBodyFXData unk0;
    /* 0x008 */ CharacterBodyFXData unk8;
    /* 0x010 */ s32 unk10;
    /* 0x014 */ FlameBreathFX* unk14;
    /* 0x018 */ ZapBreathFX* unk18;
    /* 0x01c */ IceBreathFX* unk1C;
    /* 0x020 */ EarthBreathFX* unk20;
    /* 0x024 */ s32 unk24;
    /* 0x028 */ CharacterBodyFX* unk28;
    /* 0x02c */ MeleeTrails* unk2C;
    /* 0x030 */ MKMaterial* unk30;
    /* 0x034 */ s32 unk34;
    /* 0x038 */ s32 unk38;
    /* 0x03c */ u8 pad3C[0x4];
    /* 0x040 */ KDSound_AfterRumble unk40;
    /* 0x0b0 */ BoneBlurFX* unkB0;
    /* 0x0b4 */ CharacterBodyFX* unkB4;
    /* 0x0b8 */ s32 unkB8;
    /* 0x0bc */ FuryFXConvexity* unkBC;
    /* 0x0c0 */ ConvexityBreathFX* unkC0;
    /* 0x0c4 */ CharacterBodyFX* unkC4;
    /* 0x0c8 */ LineSegmentTrail* unkC8;
    /* 0x0cc */ LineSegmentTrail* unkCC;
};

#endif  // SPYRO_SOURCE_SPYROEFFECTS_H
