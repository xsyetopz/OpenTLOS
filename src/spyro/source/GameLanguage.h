#ifndef SPYRO_SOURCE_GAMELANGUAGE_H
#define SPYRO_SOURCE_GAMELANGUAGE_H

#include <dolphin/types.h>

s32 GameLanguage_GetPrev(int *, bool);
s32 GameLanguage_GetLast(int *, bool);
u8 GameLanguage_GetNext(int *, bool);
u8 GameLanguage_GetFirst(int *, bool);
void GameLanguage_GetAudioCode(int);
s32 GameLanguage_GetAudioTrack(int);
void GameLanguage_GetName(int);
void GameLanguage_GetCode(int);
s32 GameLanguage_LanguageByCode(const char *);
s32 GameLanguage_Count(void);
u8 GameLanguage_Available(int);
void GameLanguage_Set(int);
s32 GameLanguage_GetDefault(void);
void GameLanguage_Get(void);
void GameLanguage_InitModule(void);
#endif  // SPYRO_SOURCE_GAMELANGUAGE_H
