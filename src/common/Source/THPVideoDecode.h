#ifndef COMMON_SOURCE_THPVIDEODECODE_H
#define COMMON_SOURCE_THPVIDEODECODE_H

#include <dolphin/types.h>

class THPReadBuffer;

class THPReadBuffer {
public:
    /* 0x000 */ s32 unk0;
    /* 0x004 */ s32 unk4;
};

void PushDecodedTextureSet(void *);
s32 PopDecodedTextureSet(long);
void PushFreeTextureSet(void *);
void * PopFreeTextureSet(void);
void VideoDecodeThreadCancel(void);
void VideoDecodeThreadStart(void);
s32 CreateVideoDecodeThread(long, unsigned char *);
#endif  // COMMON_SOURCE_THPVIDEODECODE_H
