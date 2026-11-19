#ifndef SPYRO_SOURCE_SUBTITLES_H
#define SPYRO_SOURCE_SUBTITLES_H

#include <dolphin/types.h>

void Subtitles_Draw(void);
void Subtitles_Update(void);
void Subtitles_Deinit(void);
void Subtitles_Init(const char *);
void Subtitles_DeinitModule(void);
void Subtitles_InitModule(void);
#endif  // SPYRO_SOURCE_SUBTITLES_H
