#ifndef COMMON_SOURCE_MKCOLLISION_H
#define COMMON_SOURCE_MKCOLLISION_H

#include <dolphin/types.h>

class MKCollisionGroundHint;
class MKCollisionInfo;
class MKCollisionManager;
class MKCollisionMode;
class MKCollisionResult;
class MKProp;
class MKVector3;

class MKCollisionInfo {
public:
    void GetRadius(void);
    /* 0x000 */ s32 unk0;
    /* 0x004 */ u8 unk4;
    /* 0x005 */ u8 pad5[0x3];
    /* 0x008 */ MKProp* unk8;
    /* 0x00c */ s32 unkC;
};

void MKCollision_MangleName(const char *, int, bool);
void MKCollision_MangleName(const char *, int);
u8 MKCollision_GetGroundPoint(const MKVector3 &, float, MKCollisionResult *, int, int, MKCollisionGroundHint *, MKCollisionMode);
s32 MKCollision_SphereCollide(const MKVector3 &, float, MKCollisionResult *, int, MKCollisionMode, int);
u8 MKCollision_SweepSphereCollide(const MKVector3 &, const MKVector3 &, float, MKCollisionResult *, MKCollisionMode, int);
u8 MKCollision_RayCollide(const MKVector3 &, const MKVector3 &, MKCollisionResult *, MKCollisionMode, int);
void MKCollision_RemoveManager(MKCollisionManager *);
void MKCollision_AddManager(MKCollisionManager *);
void MKCollision_Draw(void);
void MKCollision_Update(void);
void MKCollision_Deinit(void);
void MKCollision_Init(void);
void MKCollision_DeinitModule(void);
void MKCollision_SetDefaultBoundingBox(const MKVector3 &, const MKVector3 &);
void MKCollision_InitModule(void);
extern u8 defaultCollisionMin[0x10];
extern u8 defaultCollisionMax[0x10];
#endif  // COMMON_SOURCE_MKCOLLISION_H
