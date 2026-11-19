#ifndef COMMON_SOURCE_VIDEO_H
#define COMMON_SOURCE_VIDEO_H

#include <dolphin/types.h>
#include "common/Source/MKHeap.h"

class MKHeap;
class Video;

f32 Video_GetRemainingTime(Video *);
s32 Video_IsReady(Video *);
void Video_Draw(Video *, float, float, float, float, float);
void Video_Destroy(Video *);
void Video_SetLooping(Video *, bool);
s32 Video_Update(Video *);
MKHeap * Video_CreateStreaming(const char *, bool, int, void *, int);
void Video_DeinitModule(void);
void Video_InitModule(void);
extern MKHeap currentVideo;
#endif  // COMMON_SOURCE_VIDEO_H
