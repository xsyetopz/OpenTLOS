#ifndef COMMON_SOURCE_THPPLAYER_H
#define COMMON_SOURCE_THPPLAYER_H

#include <dolphin.h>

void DrawDoneCallback(void);
void PrepareReady(int);
extern DVDCommandBlock ActivePlayer;
extern s32 THP_Initialized;
#endif  // COMMON_SOURCE_THPPLAYER_H
