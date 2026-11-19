#ifndef COMMON_GC_SOUND_GC_H
#define COMMON_GC_SOUND_GC_H

#include <dolphin/types.h>
#include "unplaced_enums.h"

class MKVector3;
class Matrix;
class SoundBankHeader;
class Sound_GC_cpp;
class _3DSoundInfo;

class SoundBankHeader {
public:
    /* 0x000 */ s8 unk0;
    /* 0x001 */ u8 pad1[0x3];
    /* 0x004 */ s32 unk4;
    /* 0x008 */ s32 unk8;
    /* 0x00c */ u8 padC[0x14];
    /* 0x020 */ s32 unk20;
    /* 0x024 */ s32 unk24;
    /* 0x028 */ s32 unk28;
    /* 0x02c */ u16 unk2C;
    /* 0x02e */ u8 unk2E;
    /* 0x02f */ u8 pad2F[0x1];
    /* 0x030 */ u16 unk30;
    /* 0x032 */ u8 unk32;
    /* 0x033 */ u8 pad33[0x1f];
    /* 0x052 */ u16 unk52;
    /* 0x054 */ u16 unk54;
    /* 0x056 */ s16 unk56;
    /* 0x058 */ s16 unk58;
    /* 0x05a */ u16 unk5A;
    /* 0x05c */ s16 unk5C;
    /* 0x05e */ s16 unk5E;
};

class Sound_GC_cpp {
public:
    void __sinit(void);
};

class _3DSoundInfo {
public:
    /* 0x000 */ f32 unk0;
    /* 0x004 */ f32 unk4;
    /* 0x008 */ f64 unk8;
    /* 0x010 */ f64 unk10;
    /* 0x018 */ f32 unk18;
};

s32 Sound_MusicGetResumePosition(void);
void Sound_MusicDuckVolume(unsigned char, int, int);
u8 Sound_MusicGetVolume(void);
void Sound_MusicSetVolume(unsigned char);
void Sound_MusicStop(void);
void Sound_MusicPause(bool);
s32 Sound_MusicIsPlaying(void);
void Sound_MusicPlay(const char *, bool, int);
void Sound_SysResumeVoices(void);
void Sound_SysPauseVoices(void);
s32 GetVideoVolume(void);
void Sound_Update3d(int, int, MKVector3 *);
void Sound_Play3d(int, unsigned char, MKVector3 *, float, float);
void Sound_PlayV(int, unsigned char, unsigned char);
void Sound_Play(int);
void Sound_SetListener(Matrix *);
void Sound_PauseAll(bool);
void Sound_SetPitch(int, float);
void Sound_SetPitch3d(int, float);
void Sound_Stop3d(int);
s32 Sound_IsVoicePlaying(int);
s32 Sound_IsBankLoaded(int *);
s32 Sound_LoadBank(const char *, bool, int);
s32 Sound_ReserveMemory(int, int);
s32 Sound_LoadBankFromMemory(SoundBankHeader *, bool, int);
void Sound_SetAcousticProperty(Sound_AcousticProperty);
s32 Sound_GetAcousticProperty(void);
void Sound_SetSystemAudioMode(int);
s32 Sound_GetSystemAudioMode(void);
void AudioCallbackNormal(void);
s32 Sound_IsBankLoading(void);
void Sound_Update(void);
void Sound_StopAll(void);
void Sound_SetMasterVolume(float, float);
void Sound_GetVolume(int, unsigned char *, unsigned char *);
void Sound_SetVolume(int, unsigned char, unsigned char);
void Sound_Stop(int);
s32 Sound_GetID(const char *);
s32 Sound_UnloadBank(int);
void Sound_DeinitModule(void);
void Sound_InitModule(void);
void ARAMTransfer(unsigned long, unsigned long, unsigned long);
void * BinarySearch(void *, void *, int, int, int (*)(const void *, const void *));
extern u8 reservedBankIDs[0x460];
extern s32 Sound_CurrentState;
#endif  // COMMON_GC_SOUND_GC_H
