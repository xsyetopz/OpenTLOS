#ifndef COMMON_SOURCE_MKPACKAGE_H
#define COMMON_SOURCE_MKPACKAGE_H

#include <dolphin/types.h>

class MKHeap;
class PackageQueueInfo;

class PackageQueueInfo {
public:
    /* 0x000 */ s32 unk0;
    /* 0x004 */ s8 unk4;
    /* 0x005 */ u8 pad5[0x1f];
    /* 0x024 */ s8 unk24;
    /* 0x025 */ u8 pad25[0xff];
    /* 0x124 */ MKHeap* unk124;
    /* 0x128 */ u8 unk128;
    /* 0x129 */ u8 unk129;
};

void MKPackage_ShowStatus(int);
s32 MKPackage_QFree(int);
void MKPackage_QCancel(int);
u8 MKPackage_QIsLoaded(int, float *, int *);
s32 MKPackage_QLoadDynamic(const char *, int, const char *);
s32 MKPackage_QLoad(const char *, int);
void MKPackage_UseQ(void);
s32 MKPackage_Free(void);
void MKPackage_Cancel(void);
u8 MKPackage_IsLoaded(float *, int *);
void MKPackage_LoadDynamic(char *, bool, char *);
void MKPackage_Load(char *, bool);
void MKPackage_Update(void);
void MKPackage_DeinitModule(void);
void MKPackage_InitModule(void);
extern u8 gDisablePackages;
extern s32 MKPackage_kLoadedPerSecond;
extern s32 MKPackage_memoryDelivered;
extern s32 MKPackage_misses;
extern s32 MKPackage_missesAccumulator;
extern s32 MKPackage_undelivered;
#endif  // COMMON_SOURCE_MKPACKAGE_H
