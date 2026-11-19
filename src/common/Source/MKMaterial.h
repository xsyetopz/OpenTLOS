#ifndef COMMON_SOURCE_MKMATERIAL_H
#define COMMON_SOURCE_MKMATERIAL_H

#include <dolphin/types.h>
#include "unplaced_enums.h"

class MKHeap;
class MKMaterial;
class MKMaterialUpdater;
class MKResource;
class MKVector4;
class MatInfo;
class Matrix;
class Texture;

class MKMaterial {
public:
    s8 * Create(const char *);
    /* 0x000 */ f32 unk0;
    /* 0x004 */ f32 unk4;
    /* 0x008 */ u8 pad8[0x1c];
    /* 0x024 */ void* unk24;
    /* 0x028 */ s32 unk28;
    /* 0x02c */ u8 pad2C[0x8];
    /* 0x034 */ void* unk34;
    /* 0x038 */ Texture* unk38;
    /* 0x03c */ MKMaterial* unk3C;
};

class MKMaterialUpdater {
public:
    /* 0x000 */ MKMaterial* unk0;
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ MKHeap* unk8;
    /* 0x00c */ MKMaterialUpdater* unkC;
    /* 0x010 */ MKMaterialUpdater* unk10;
    /* 0x014 */ u8 pad14[0x1a8];
    /* 0x1bc */ s8 unk1BC;
};

s32 MKMaterial_GetMaterialIDMask(const char *);
void MKMaterial_InitMaterialIDs(void);
void MKMaterial_SetWhite(void);
void MKMaterialInternal_Update(void);
void MKMaterialInternal_RemoveUpdatersForMaterial(MKMaterial *);
void MKMaterialInternal_RemoveUpdater(MKMaterialUpdater *);
void MKMaterialInternal_AddUpdater(MKMaterial *, void (*)(MKMaterial *, void *), void *);
s32 MKMaterialInternal_GetCurrent(void);
s8 * MKMaterialInternal_Find(const char *);
void * MKMaterialInternal_GetMaterialTypeInfoFromID(int);
s32 MKMaterialInternal_GetMaterialTypeIDFromName(const char *);
s8 MKMaterial_GetParameter(MKMaterial *, MKMaterialParameter);
MKHeap * MKMaterial_GetName(MKMaterial *);
void MKMaterial_SetParameter(MKMaterial *, MKMaterialParameter, int);
f64 * MKMaterial_GetColor(MKMaterial *);
void MKMaterial_SetColor(MKMaterial *, const MKVector4 &);
void MKMaterial_SetTextureMatrix(MKMaterial *, const Matrix *);
void MKMaterial_GetEffectType(MKMaterial *, const char **);
s32 MKMaterial_GetMaterialID(MKMaterial *);
void MKMaterial_Destroy(MKMaterial *);
MKResource * MKMaterial_Create(const char *);
void MKMaterial_DeinitModule(void);
void MKMaterial_InitModule(void);
void MKMatInfo_Merge(MatInfo *, MatInfo *);
void MKMatInfo_Endian(MatInfo *);
void MKMatInfo_Init(MatInfo *, const char *);
extern s8 materialList;
extern MKMaterial * gpMKWhiteMaterial;
extern s32 gpCurrentMaterial;
extern s8 bMaterialIniting;
extern s8 bMaterialDeiniting;
#endif  // COMMON_SOURCE_MKMATERIAL_H
