#ifndef COMMON_SOURCE_MKVIEW_H
#define COMMON_SOURCE_MKVIEW_H

#include <dolphin/types.h>

class BoundingVolume;
class Frustum;
class MKRect;
class MKVector3;
class Matrix;
class Texture;

class MKRect {
public:
    /* 0x000 */ f32 unk0;
    /* 0x004 */ f32 unk4;
    /* 0x008 */ f32 unk8;
    /* 0x00c */ f32 unkC;
};

f32 MKView_GetAspectRatio(void);
void MKView_SetAspectRatio(float);
f32 * MKView_GetOrthoRect(void);
Texture * MKView_GetRenderTarget(Texture **);
Frustum * MKView_GetWorldFrustum(void);
s32 MKView_VisibilityTest(const BoundingVolume &, const Matrix &);
void MKView_TransformPoint2Dto3D(float, float, float, MKVector3 *);
f32 MKView_TransformPoint3Dto2D(MKVector3 *, const MKVector3 &);
s32 MKView_GetFlags(void);
u8 MKView_IsOrtho(void);
void MKView_SetOrthoRect(const MKRect *);
void MKView_SetOrtho(const MKRect *);
void MKView_GetProjection(float *, float *, float *);
void MKView_SetProjection(float, float, float);
Matrix * MKView_GetProjectionMatrix(void);
Matrix * MKView_GetWorldToScreenMatrix(void);
Matrix * MKView_GetWorldToViewMatrix(void);
Matrix * MKView_GetCameraMatrix(void);
void MKView_SetCameraMatrix(const Matrix &);
void MKView_SetCameraLookAt(const MKVector3 &, const MKVector3 &, float);
void MKView_GetViewport(void);
void MKView_Pop(void);
void MKView_Push(void);
void MKView_SetRenderTarget(Texture *, Texture *);
void MKView_InitModule(void);
extern s32 MKView_SettingsCounter;
#endif  // COMMON_SOURCE_MKVIEW_H
