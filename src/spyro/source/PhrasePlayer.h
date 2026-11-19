#ifndef SPYRO_SOURCE_PHRASEPLAYER_H
#define SPYRO_SOURCE_PHRASEPLAYER_H

#include <dolphin/types.h>

class PhraseEvent;
class PhrasePlayer_cpp;

class PhraseEvent {
public:
    /* 0x000 */ u8 unk0;
    /* 0x001 */ s8 unk1;
};

class PhrasePlayer_cpp {
public:
    void __sinit(void);
};

s8 * PhrasePlayer_GetCurrentActor(void);
s32 PhrasePlayer_IsLevelIniLoaded(void);
void PhrasePlayer_UnloadLevelIni(void);
void PhrasePlayer_LoadLevelIni(const char *);
void PhrasePlayer_StopAnyEvent(void);
s32 PhrasePlayer_IsAnyEventPlaying(void);
s32 PhrasePlayer_IsEventPlaying(int);
void PhrasePlayer_StopEvent(int);
s32 PhrasePlayer_PlayEvent(const char *);
void PhrasePlayer_Update(void);
void PhrasePlayer_Deinit(void);
void PhrasePlayer_Init(void);
extern s8 phraseData;
#endif  // SPYRO_SOURCE_PHRASEPLAYER_H
