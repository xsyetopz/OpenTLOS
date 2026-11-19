#ifndef SPYRO_SOURCE_KDSOUND_H
#define SPYRO_SOURCE_KDSOUND_H

#include <dolphin/types.h>
#include "spyro/source/KDFaderObject.h"
#include "spyro/source/Level.h"

class GlobalSoundData;
class KDFaderObject;
class KDSoundData;
class KDSoundFader;
class KDSoundPlayer;
class Level;
class MKAnimScript;
class MKHeap;
class MKIni;
class MKIniLine;
class MKMessage;
class MKModel;
class MKProp;
class MKStringCache;
class MKVector3;
class Matrix;
class SoundEvent;
class SoundEventInstance;
class SoundMaterial;
class Sound_AcousticProperty;

class GlobalSoundData {
public:
    void * GetSoundDataBlock(int);
    SoundMaterial * GetSoundMatBlock(int);
    u8 CountMaterials(MKIniLine *);
    MKIniLine * ParseSound(SoundMaterial *, MKIniLine *);
    MKIniLine * ParseSoundMaterial(SoundMaterial *, MKIniLine *, unsigned char, float, float);
    MKIniLine * ParseSoundEvent(SoundEvent *, MKIniLine *);
    MKIniLine * SkipSetupSection(MKIni *);
    void ParseInSoundEvents(MKIni *);
    void ParseAndBuildHeaps(MKIni *);
    void Update(void);
    void InvalidateSoundIDRange(int, int);
    void ResolveSoundIDs(float);
    void ResolveSoundIDs(void);
    void Deinit(void);
    void Init(const char *, int);
    static u8 firstInvalidSoundID[0x4];
    static u8 lastInvalidSoundID[0x4];
    /* 0x000 */ u8 pad0[0x4];
    /* 0x004 */ s32 unk4;
    /* 0x008 */ MKHeap* unk8;
    /* 0x00c */ MKHeap* unkC;
    /* 0x010 */ void* unk10;
    /* 0x014 */ s32 unk14;
    /* 0x018 */ s32 unk18;
    /* 0x01c */ s32 unk1C;
    /* 0x020 */ MKStringCache* unk20;
    /* 0x024 */ s32 unk24;
    /* 0x028 */ f32 unk28;
};

class KDSoundData {
public:
    void Deinit(void);
    void Init(bool);
    /* 0x000 */ s32 unk0;
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ s8 unk8;
    /* 0x009 */ u8 pad9[0x9];
    /* 0x012 */ s8 unk12;
    /* 0x013 */ u8 pad13[0x15];
    /* 0x028 */ s32 unk28;
    /* 0x02c */ s32 unk2C;
    /* 0x030 */ s32 unk30;
    /* 0x034 */ s32 unk34;
    /* 0x038 */ s32 unk38;
    /* 0x03c */ f32 unk3C;
    /* 0x040 */ f32 unk40;
    /* 0x044 */ f32 unk44;
    /* 0x048 */ f32 unk48;
    /* 0x04c */ f32 unk4C;
    /* 0x050 */ f32 unk50;
    /* 0x054 */ s32 unk54;
    /* 0x058 */ s32 unk58;
    /* 0x05c */ KDFaderObject unk5C;
    /* 0x078 */ s32 unk78;
    /* 0x07c */ s8 unk7C;
    /* 0x07d */ u8 pad7D[0x1f];
    /* 0x09c */ s8 unk9C;
    /* 0x09d */ u8 pad9D[0x1f];
    /* 0x0bc */ s8 unkBC;
    /* 0x0bd */ u8 padBD[0x3];
    /* 0x0c0 */ s32 unkC0;
    /* 0x0c4 */ s32 unkC4;
    /* 0x0c8 */ s8 unkC8;
    /* 0x0c9 */ s8 unkC9;
    /* 0x0ca */ u8 padCA[0x2];
    /* 0x0cc */ f32 unkCC;
    /* 0x0d0 */ s8 unkD0;
    /* 0x0d1 */ s8 unkD1;
    /* 0x0d2 */ u8 padD2[0x22];
    /* 0x0f4 */ f32 unkF4;
    /* 0x0f8 */ f32 unkF8;
    /* 0x0fc */ f32 unkFC;
    /* 0x100 */ f32 unk100;
    /* 0x104 */ s8 unk104;
    /* 0x105 */ s8 unk105;
    /* 0x106 */ s8 unk106;
    /* 0x107 */ u8 pad107[0x21];
    /* 0x128 */ f32 unk128;
    /* 0x12c */ f32 unk12C;
    /* 0x130 */ f32 unk130;
    /* 0x134 */ u8 pad134[0x4];
    /* 0x138 */ s32 unk138;
    /* 0x13c */ s32 unk13C;
    /* 0x140 */ s32 unk140;
    /* 0x144 */ s32 unk144;
};

class KDSoundFader {
public:
    ~KDSoundFader(void);
    KDSoundFader(void);
    void Update(int, bool, bool, MKProp *, const MKVector3 *, unsigned int, int, bool);
    void Init(float, float);
    /* 0x000 */ s32 unk0;
    /* 0x004 */ f32 unk4;
    /* 0x008 */ f32 unk8;
    /* 0x00c */ KDFaderObject unkC;
    /* 0x028 */ f64 unk28;
    /* 0x030 */ f32 unk30;
    /* 0x034 */ u8 pad34[0x4];
    /* 0x038 */ f32 unk38;
    /* 0x03c */ u8 pad3C[0x4];
    /* 0x040 */ f32 unk40;
    /* 0x044 */ u8 pad44[0x4];
    /* 0x048 */ f32 unk48;
    /* 0x04c */ u8 pad4C[0x4];
    /* 0x050 */ f32 unk50;
    /* 0x054 */ u8 pad54[0xc];
    /* 0x060 */ f64 unk60;
    /* 0x068 */ f32 unk68;
    /* 0x06c */ f32 unk6C;
    /* 0x070 */ MKModel* unk70;
};

class KDSoundPlayer {
public:
    void Update(int, bool, bool, MKProp *, const MKVector3 *, unsigned int, int, bool);
    void Message(MKMessage *);
    /* 0x000 */ s32 unk0;
};

class SoundEvent {
public:
    s32 Play(const MKVector3 *, unsigned int, int);
    void Reset(void);
    /* 0x000 */ s32 unk0;
    /* 0x004 */ s32 unk4;
    /* 0x008 */ s32 unk8;
    /* 0x00c */ u8 unkC;
    /* 0x00d */ u8 padD[0x3];
    /* 0x010 */ SoundMaterial* unk10;
    /* 0x014 */ u8 pad14[0x14];
    /* 0x028 */ s32 unk28;
    /* 0x02c */ u8 unk2C;
};

class SoundEventInstance {
public:
    /* 0x000 */ s32 unk0;
    /* 0x004 */ f32 unk4;
    /* 0x008 */ f32 unk8;
};

class SoundMaterial {
public:
    s32 Play(const MKVector3 *, SoundEvent *, int, float *);
    /* 0x000 */ s32 unk0;
    /* 0x004 */ f32 unk4;
    /* 0x008 */ f32 unk8;
    /* 0x00c */ u8 unkC;
    /* 0x00d */ u8 unkD;
    /* 0x00e */ u8 padE[0x2];
    /* 0x010 */ void* unk10;
};

u8 KDSound_SoundDucking_IsPaused(void);
s32 KDSound_SoundDucking_GetState(void);
f32 KDSound_SoundDucking_ForceDuck(SoundEventInstance **);
s32 KDSound_SoundDucking_UnDuck(void);
s32 KDSound_SoundDucking_Duck(void);
void KDSound_SoundDucking_Update(void);
void KDSound_SoundDucking_Deinit(void);
void KDSound_SoundDucking_Init(float, float, float, bool);
void KDS_FollowSndPosArrayShuffleDown(int);
u8 KDS_FollowSndPosArraySndEventIsIn(int, int &);
s32 KDS_FollowSndPosArrayGetNextSlot(void);
void KDS_FollowSndPosArrayRemove(int);
void KDS_FollowSndPosArrayAdd(int, const MKVector3 *);
void KDS_FollowSndPosArrayInit(void);
u8 KDS_IsSoundInRange(int, MKProp *, const MKVector3 *);
void KDS_UpdateMusicFading(void);
s32 KDSound_IsVoicePlaying(int);
void KDSound_ScaleMasterVolume(float, int);
void KDSound_SetMasterMusicVolume(float);
void KDSound_SetMasterSoundVolume(float);
void KDSound_SetMasterVolume(float, float);
s32 KDSound_LoadLine(MKIniLine *, const char *, int *);
s32 KDSound_ResolveSound(const char *, int *);
void KDSound_SetMusicNotInterrupt(bool);
u8 KDSound_IsMusicPaused(void);
void KDSound_IsMusicPlaying(void);
void KDSound_UnDuckMusic(float);
void KDSound_DuckMusic(float, float);
void KDSound_PauseMusic(bool, bool);
s32 KDSound_MusicIsStopping(void);
void KDSound_ResetMusic(void);
void KDSound_StopMusic(float);
void KDSound_PlayMusic(const char *, float, float, int);
void KDSound_SetSFXLimit(bool, int);
void KDSound_GetAcousticProperty(void);
void KDSound_SetAcousticProperty(Sound_AcousticProperty);
s8 * KDSound_GetCurrentMusicTrackName(void);
void KDSound_MusicGetResumePosition(void);
f32 KDSound_GetMasterMusicVolume(void);
f32 KDSound_GetMasterSoundVolume(void);
void KDSound_StopAll(void);
void KDSound_PauseAll(bool);
void KDSound_SetPitch(int, float);
void KDSound_GetVolume(int, float *, float *);
f32 KDSound_GetVolume(int);
void KDSound_SetVolume(int, float, float);
void KDSound_SetVolume(int, float);
void KDSound_Stop(int *);
void KDS_UpdateEnvironmentalAudio(void);
void KDS_UpdatePlay3dFollowSounds(void);
s32 KDSound_Play3d(MKAnimScript *, const MKVector3 *, unsigned int, float, bool);
s32 KDSound_Play3d(int, const MKVector3 *, unsigned int, int, float, bool);
s32 KDSound_Play(MKAnimScript *, unsigned int);
s32 KDSound_Play(int, unsigned int, int);
u8 KDSound_GetSoundEventVol(int);
void KDSound_SetListener(const Matrix *);
void KDSound_Update(void);
void KDSound_Deinit(void);
void KDSound_SetLevelID(const char *);
s32 KDSound_IsChronoSoundWarpActive(void);
s32 KDSound_IsChronoSoundWarpEnabled(void);
void KDSound_EnableChronoSoundWarp(bool, bool);
void KDSound_ProcessChronoSound(void);
void KDSound_InvalidateSoundIDRange(int, int);
void KDSound_ResolveSoundIDs(float);
void KDSound_Init(const char *);
void KDSound_DeinitModule(void);
void KDSound_InitModule(bool, int);
extern u32 gsData;
extern Level kdsData;
extern u8 soundPlayFollowArray;
extern u8 bSplitScreen;
// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: function call 'KDSound_Stop(long *)' does not match
inline KDSoundFader::~KDSoundFader() {
    s32 temp_cr0_eq_4916;

    temp_cr0_eq_4916 = this == NULL;
    if (temp_cr0_eq_4916 == 0) {
        if (temp_cr0_eq_4916 == 0) {
            KDSound_Stop(&this->unk0);
        }
    }
}
#endif

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline KDSoundFader::KDSoundFader() {
    this->unk0 = 0;
    return this;
}
#endif

#endif  // SPYRO_SOURCE_KDSOUND_H
