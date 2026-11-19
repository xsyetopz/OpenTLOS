#ifndef COMMON_GC_MKMATERIAL_GC_H
#define COMMON_GC_MKMATERIAL_GC_H

#include <dolphin/types.h>
#include "unplaced_enums.h"

class BoundingVolume;
class GeometryTransformationInfo;
class MKMat_MK2_Standard;
class MKMaterial;
class MKMaterial_GC_cpp;
class MKVector4;
class Matrix;
class MeshChunk;

class GeometryTransformationInfo {
public:
    /* 0x000 */ s32 unk0;
    /* 0x004 */ s32 unk4;
};

class MKMaterial_GC_cpp {
public:
    void __sinit(void);
};

class MeshChunk {
public:
    /* 0x000 */ u8 pad0[0x6];
    /* 0x006 */ u16 unk6;
    /* 0x008 */ u8 pad8[0x8];
    /* 0x010 */ u32 unk10;
    /* 0x014 */ s32 unk14;
    /* 0x018 */ s32 unk18;
    /* 0x01c */ s32 unk1C;
};

u8 MKMaterial_EnableFog(bool);
void MKMaterial_SetFogColor(const MKVector4 &);
void MKMaterial_SetFogPlanes(float, float);
f32 MKMaterial_SetVertex4F(int, float, float, float, float);
void MKMaterial_GetVertexComponentHandleFromType(VERTEX_COMPONENT);
void MKMaterial_UseLocality(int);
void MKMaterial_SetLocalities(const Matrix *, const BoundingVolume *, int, int);
void MKMaterial_RenderMeshChunk(MeshChunk *);
void MKMaterial_RenderVerticesEnd(void);
void MKMaterial_RenderVerticesBegin(int);
void MKMaterial_RenderImmediateEnd(void);
void MKMaterial_RenderImmediateBegin(unsigned int, unsigned int);
s32 MKMaterial_BeginInternal(void);
s32 MKMaterial_Begin(void);
void MKMaterial_SetMaterial(MKMaterial *);
void MKMaterial_SetGeometryColor(const MKVector4 &);
void MKMaterial_SetGeometryTransformInfo(GeometryTransformationInfo *);
void MKMaterial_SetAnimationMatrices(const Matrix *, int);
void MKMaterial_SetLocalToWorld(const Matrix *, float);
void MKMaterial_DeinitModule_PlatformSpecific(void);
void MKMaterial_InitModule_PlatformSpecific(void);
void SetZCompLoc(unsigned char);
extern u8 MKMaterial_GeometryColor[0x10];
extern u8 MKPrimitive_CurrentVertex[0x18];
extern u8 gCurrentMaterialColorGC[0x10];
extern u8 MKMaterial_LocalityArray[0x400];
extern u8 MKPrimitive_colorModulate[0x10];
extern u8 MKMaterial_fogColor[0x4];
extern u8 attemptToLockTextureInCache;
extern s8 MKMaterialGC_bForceSkinnedVertexFormat;
extern f32 MKMaterial_fogNear;
extern f32 MKMaterial_fogFar;
extern u8 MKMaterial_bFogEnabled;
extern u8 MKPrimitive_bAlphaModulate;
extern s32 gpMKcurrentMaterialEffectorMask;
extern MKMat_MK2_Standard * gpPreviousMaterial;
extern s32 MKMaterial_CurrentLocalityIndex;
#endif  // COMMON_GC_MKMATERIAL_GC_H
