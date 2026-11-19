#ifndef COMMON_SOURCE_MKMEMORYCARD_H
#define COMMON_SOURCE_MKMEMORYCARD_H

#include <dolphin/types.h>

class MKMemoryCardFileInfo;
class TimerInfo;

class MKMemoryCardFileInfo {
public:
    /* 0x000 */ u8 pad0[0x80];
    /* 0x080 */ s32 unk80;
    /* 0x084 */ s32 unk84;
    /* 0x088 */ s32 unk88;
    /* 0x08c */ s32 unk8C;
    /* 0x090 */ s32 unk90;
    /* 0x094 */ s32 unk94;
    /* 0x098 */ s32 unk98;
    /* 0x09c */ u32 unk9C;
    /* 0x0a0 */ u32 unkA0;
    /* 0x0a4 */ s8 unkA4;
    /* 0x0a5 */ s8 unkA5;
};

class TimerInfo {
public:
    /* 0x000 */ s32 unk0;
    /* 0x004 */ s32 unk4;
    /* 0x008 */ s32 unk8;
    /* 0x00c */ s32 unkC;
    /* 0x010 */ s32 unk10;
    /* 0x014 */ s32 unk14;
    /* 0x018 */ s32 unk18;
};

s32 MKMemoryCard_CalculateFileSize(void);
void MKMemoryCard_Update(void);
s32 MKMemoryCard_GetStatus(int);
void MKMemoryCard_DeinitModule(void);
void MKMemoryCard_InitModule(void);
void MKMemoryCard_GetDirInfo(int, MKMemoryCardFileInfo *);
void MKMemoryCard_GetInfo(int, int *, int *, int *, int *);
void MKMemoryCard_Load(int, int, void *, int);
void MKMemoryCard_Save(int, int, void *, int, const char *, TimerInfo *);
void MKMemoryCard_Format(int);
void MKMemoryCard_IsPrepared(int);
void MKMemoryCard_Prepare(int);
void MKMemoryCard_SetAppInfo(const char *, const char *, int *);
void MKMemoryCard_IsAttached(int);
void MKMemoryCard_Delete(int, int);
#endif  // COMMON_SOURCE_MKMEMORYCARD_H
