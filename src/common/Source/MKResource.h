#ifndef COMMON_SOURCE_MKRESOURCE_H
#define COMMON_SOURCE_MKRESOURCE_H

#include <dolphin/types.h>

class MKResource;

class MKResource {
public:
    void InitialiseResource(void);
    s32 IsResourceAvailable(void);
    static u8 sWorkingChunkID[0x4];
    static u8 sWorkingChunkIndex[0x4];
    /* 0x000 */ s8 unk0;
    /* 0x001 */ u8 pad1[0x1f];
    /* 0x020 */ s32 unk20;
    /* 0x024 */ u8 pad24[0x4];
    /* 0x028 */ s32 unk28;
};

#endif  // COMMON_SOURCE_MKRESOURCE_H
