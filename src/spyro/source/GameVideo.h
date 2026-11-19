#ifndef SPYRO_SOURCE_GAMEVIDEO_H
#define SPYRO_SOURCE_GAMEVIDEO_H

#include <dolphin/types.h>
#include "unplaced_enums.h"

class GameVideo;
class Video;

class GameVideo {
public:
    /* 0x000 */ Video* unk0;
    /* 0x004 */ s32 unk4;
    /* 0x008 */ f32 unk8;
};

s32 GameVideo_Ready(GameVideo *);
s32 GameVideo_Active(void);
f32 GameVideo_GetRemainingTime(GameVideo *);
f32 GameVideo_GetElapsedTime(GameVideo *);
void GameVideo_Draw(GameVideo *);
s32 GameVideo_Update(GameVideo *);
void GameVideo_Destroy(GameVideo *);
s32 GameVideo_Create(const char *, int, int);
void GameVideo_Init(void (*)(GameVideoEvent));
#endif  // SPYRO_SOURCE_GAMEVIDEO_H
