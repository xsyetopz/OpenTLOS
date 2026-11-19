#ifndef COMMON_SOURCE_MKMODEL_H
#define COMMON_SOURCE_MKMODEL_H

#include <dolphin/types.h>
#include "common/Source/Matrix.h"
#include "unplaced_enums.h"

class Animation;
class MKAttachment;
class MKCloth;
class MKHeap;
class MKModel;
class MKModelSLW;
class MKModelTemplateData;
class MKVector3;
class MKVector4;
class Matrix;
class ModelCloth;

class MKModel {
public:
    /* 0x000 */ void* unk0;
    /* 0x004 */ u8 unk4;
    /* 0x005 */ u8 unk5;
    /* 0x006 */ u8 pad6[0x2];
    /* 0x008 */ MKAttachment* unk8;
    /* 0x00c */ u8 padC[0x4];
    /* 0x010 */ Matrix unk10;
    /* 0x050 */ f64 unk50;
    /* 0x058 */ u8 pad58[0x4];
    /* 0x05c */ f32 unk5C;
    /* 0x060 */ f32 unk60;
    /* 0x064 */ f32 unk64;
    /* 0x068 */ f32 unk68;
    /* 0x06c */ f32 unk6C;
    /* 0x070 */ Animation* unk70;
    /* 0x074 */ u8 pad74[0xc];
    /* 0x080 */ void* unk80;
    /* 0x084 */ ModelCloth* unk84;
    /* 0x088 */ void* unk88;
    /* 0x08c */ void* unk8C;
};

class MKModelSLW {
public:
    /* 0x000 */ s8* unk0;
    /* 0x004 */ u8 unk4;
    /* 0x005 */ u8 unk5;
};

class MKModelTemplateData {
public:
    class CustomDataEntry;
    void UnpackTemplatePointers(bool);
    /* 0x000 */ u8 pad0[0x4];
    /* 0x004 */ s16 unk4;
    /* 0x006 */ s16 unk6;
    /* 0x008 */ u8 pad8[0x2];
    /* 0x00a */ s16 unkA;
    /* 0x00c */ s16 unkC;
    /* 0x00e */ u8 padE[0x42];
    /* 0x050 */ void* unk50;
    /* 0x054 */ void* unk54;
    /* 0x058 */ void* unk58;
    /* 0x05c */ void* unk5C;
    /* 0x060 */ void* unk60;
    /* 0x064 */ void* unk64;
    /* 0x068 */ void* unk68;
    /* 0x06c */ MKModelTemplateData* unk6C;
};

void MKModel_EnableClothUpdate(MKModel *, bool);
void MKModel_UpdateCloth(MKModel *);
void MKModel_SetClothManualUpdate(MKModel *, bool);
MKCloth * MKModel_GetClothSubObject(const MKModel *, int);
ModelCloth * MKModel_GetCloth(const MKModel *);
void MKModel_CalculateSubObjectLocalToWorldMatrix(const MKModel *, SubObjectType, int, Matrix *);
void MKModel_CalculateRefPointWorldPosition(const MKModel *, int, MKVector3 *);
void MKModel_CalculateNodeWorldMatrix(const MKModel *, int, Matrix *);
void MKModel_CalculateNodeWorldPosition(const MKModel *, int, MKVector3 *);
void MKModel_CalculateCentre(const MKModel *, MKVector3 *);
s32 MKModel_GetMaterial(const MKModel *, int, bool);
s16 MKModel_GetNmbrOfMaterials(const MKModel *);
s32 MKModel_IsSubObjectPrefixed(const MKModel *, SubObjectType, int, char);
void MKModel_SetSubObjectLocalMatrix(MKModel *, SubObjectType, int, Matrix *);
s32 MKModel_GetSubObjectLocalMatrix(const MKModel *, SubObjectType, int);
s16 MKModel_GetSubObjectBoneIndex(const MKModel *, SubObjectType, int);
s8 * MKModel_GetSubObjectName(const MKModel *, SubObjectType, int);
s16 MKModel_GetNmbrOfSubObjects(const MKModel *, SubObjectType);
void MKModel_EnableOnlySubObject(MKModel *, SubObjectType, int, bool, unsigned char);
void MKModel_EnableSubObject(MKModel *, SubObjectType, int, bool, unsigned char);
u8 MKModel_GetSubObjectFlag(const MKModel *, SubObjectType, int);
s32 MKModel_GetSubObjectOrigin(const MKModel *, SubObjectType, int);
s32 MKModel_IsSubObjectEnabled(const MKModel *, SubObjectType, int);
s32 MKModel_GetSubObjectIndex(const MKModel *, SubObjectType, const char *);
s32 MKModel_SubObjectExists(const MKModel *, SubObjectType, const char *, int *);
s32 MKModel_GetRefPointMatrix(const MKModel *, int, Matrix *, bool);
s32 MKModel_GetRefPointData(const MKModel *, int);
u8 MKModel_GetRefPointType(const MKModel *, int);
f32 MKModel_GetRefPointRadius(const MKModel *, int);
s8 * MKModel_GetRefPointName(const MKModel *, int);
s32 MKModel_GetRefPointIndex(const MKModel *, const char *);
s32 MKModel_RefPointExists(const MKModel *, const char *, int *);
s16 MKModel_GetNmbrOfRefPoints(const MKModel *);
MKHeap ** MKModel_GetBoundingVolume(const MKModel *, SubObjectType, int);
void MKModel_EnableTrivialRejection(MKModel *, bool);
void MKModel_EnableScissoring(MKModel *, bool);
Animation * MKModel_GetAnimation(const MKModel *);
void MKModel_SetPosition(MKModel *, const MKVector3 &);
void MKModel_GetPosition(const MKModel *);
u8 MKModel_IsAtIdentity(const MKModel *);
void MKModel_SetRotation(MKModel *, const MKVector3 &);
MKModel * MKModel_GetAttachment(const MKModel *);
void MKModel_SetAlpha(MKModel *, float);
void MKModel_SetColor(MKModel *, const MKVector4 &);
f32 MKModel_GetAlpha(const MKModel *);
f64 * MKModel_GetColor(const MKModel *);
void MKModel_GetWorldMatrixWithAttachment(const MKModel *, Matrix *);
void MKModel_SetWorldMatrix(MKModel *, const Matrix &);
s32 MKModel_GetWorldMatrix(const MKModel *);
MKHeap * MKModel_GetName(const MKModel *);
void MKModel_DrawModelParticles(const MKModel *, const Matrix *);
void MKModel_RemoveDestroyedModels(void);
void MKModel_Destroy(MKModel *);
void MKModel_SetupCloth(MKModel *);
void MKModel_DestroyCloth(MKModel *);
void UnpackCustomDataEntry_ConvexHull(MKModelTemplateData::CustomDataEntry *, bool, int);
void UnpackCustomDataEntry_Cloth(MKModelTemplateData::CustomDataEntry *, bool, int);
MKModel * MKModel_Create(const char *, const char *, int, MKModelSLW *);
void MKModelInternal_FixUpBlendShapes(MKModel *);
void MKModel_DeinitModule(void);
void MKModel_InitModule(void);
void MKModel_DenitModulePlatformSpecific(void);
extern s8 * pTemplatesList;
#endif  // COMMON_SOURCE_MKMODEL_H
