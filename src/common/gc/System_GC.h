#ifndef COMMON_GC_SYSTEM_GC_H
#define COMMON_GC_SYSTEM_GC_H

#include <dolphin.h>
#include "common/Source/MKHeap.h"

class MKHeap;
class MKMaterial;
class MKZRequest;
class _GXTexRegion;

class MKZRequest {
public:
    /* 0x000 */ f32 unk0;
    /* 0x004 */ f32 unk4;
    /* 0x008 */ f32 unk8;
    /* 0x00c */ u8 padC[0x4];
    /* 0x010 */ f32 unk10;
    /* 0x014 */ s8 unk14;
    /* 0x015 */ u8 pad15[0xb];
    /* 0x020 */ void* unk20;
};

s32 System_GetWideScreenPreference(void);
void MKZRequest_CheckRequest(MKZRequest *);
void MKZRequest_Destroy(MKZRequest *);
void * MKZRequest_Create(void);
void MKZRequest_DeinitModule(void);
void MKZRequest_InitModule(void);
void ReleasePreloadedTextureRegion(_GXTexRegion *);
void * RequestPreloadedTextureRegion(int, unsigned int *);
void System_DoReset(bool, bool, bool);
void System_SetOrthoSize(int, int);
void System_SetDisplayMode(int, int, int, int, int);
void System_GameDraw(void);
u8 System_Update_Normal(void);
void System_DoGameLoop(void);
void System_DeinitModule(void);
void System_InitModule(void *, char *);
void SeekHackFinished(long, DVDFileInfo *);
extern MKHeap gMKDefaults;
extern s32 gDisplay;
extern MKMaterial * gRenderState;
extern MKHeap gMainHeap;
extern f32 gUpdateTimeDelta;
extern s8 * gpBuildVersion;
extern OSThread * pMainThread;
extern s8 resetSoundDeinit;
extern s32 gFrameCounter;
extern s32 gDrawCounter;
extern s32 gMKLastIdleTime;
#endif  // COMMON_GC_SYSTEM_GC_H
