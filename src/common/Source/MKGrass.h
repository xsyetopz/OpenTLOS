#ifndef COMMON_SOURCE_MKGRASS_H
#define COMMON_SOURCE_MKGRASS_H

#include <dolphin/types.h>
#include "common/Source/MKHeap.h"

class MKGrassType;
class MKHeap;
class MKModel;
class MKVector3;

class MKGrassType {
public:
    u8 IsInOverlayChain(MKGrassType *);
    /* 0x000 */ u8 pad0[0x20];
    /* 0x020 */ void* unk20;
    /* 0x024 */ u8 pad24[0x8];
    /* 0x02c */ void* unk2C;
};

void MKGrass_Draw(void);
void MKGrass_QueueDraw(const MKModel *, const unsigned short *);
void MKGrass_DrawStats(void);
void MKGrass_Update(void);
void MKGrass_DestroyGrassData(MKModel *);
void MKGrass_RemoveModel(MKModel *);
void MKGrass_AddModel(MKModel *);
void MKGrass_SetWindDirection(const MKVector3 &, float);
void MKGrass_SetPushAwaySphere(const MKVector3 &, int);
MKHeap * MKGrass_GetGrassTypeId(const char *);
void MKGrass_ProcessTypes(void *);
void MKGrass_LevelDeinit(void);
void MKGrass_LevelInit(void);
u8 MKGrass_Enable(bool);
void MKGrass_DeinitModule(void);
void MKGrass_InitModule(void);
extern f32 MKGrass_cameraPos;
extern u8 MKGrass_pushAwaySpheres[0x40];
extern MKHeap MKGrass_windDirection;
extern u8 MKGrass_bEnable[0x1];
extern s32 gpGrassTypes;
extern s32 gnGrassTypes;
extern void *** grassModelsList;
extern MKModel *** drawQueue;
#endif  // COMMON_SOURCE_MKGRASS_H
