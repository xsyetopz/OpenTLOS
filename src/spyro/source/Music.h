#ifndef SPYRO_SOURCE_MUSIC_H
#define SPYRO_SOURCE_MUSIC_H

#include <dolphin/types.h>

class MusicTrack;
class Music_cpp;

class MusicTrack {
public:
    /* 0x000 */ s8* unk0;
    /* 0x004 */ s8* unk4;
    /* 0x008 */ u8 pad8[0x4];
    /* 0x00c */ f32 unkC;
    /* 0x010 */ f32 unk10;
    /* 0x014 */ s32 unk14;
    /* 0x018 */ u8 pad18[0x5];
    /* 0x01d */ u8 unk1D;
    /* 0x01e */ u8 pad1E[0x2];
    /* 0x020 */ s32 unk20;
    /* 0x024 */ s8 unk24;
};

class Music_cpp {
public:
    void __sinit(void);
};

void Music_Clear(void);
void Music_ClearDelayedPlayBuffer(void);
void Music_SetDelayedPlay(const char *, bool);
void Music_SetMasterVolume(float);
void Music_UnDuck(float);
void Music_Duck(float, float);
u8 Music_IsPaused(void);
void Music_Resume(void);
void Music_Pause(bool);
void Music_Stop(float);
s32 Music_Play(const char *, bool);
void Music_Update(void);
void Music_Deinit(void);
void Music_Init(void);
#endif  // SPYRO_SOURCE_MUSIC_H
