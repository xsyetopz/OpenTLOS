#ifndef COMMON_SOURCE_THPAUDIODECODE_H
#define COMMON_SOURCE_THPAUDIODECODE_H

#include <dolphin/types.h>

void PushDecodedAudioBuffer(void *);
s32 PopDecodedAudioBuffer(long);
void PushFreeAudioBuffer(void *);
void * PopFreeAudioBuffer(void);
void AudioDecodeThreadCancel(void);
void AudioDecodeThreadStart(void);
s32 CreateAudioDecodeThread(long, unsigned char *);
#endif  // COMMON_SOURCE_THPAUDIODECODE_H
