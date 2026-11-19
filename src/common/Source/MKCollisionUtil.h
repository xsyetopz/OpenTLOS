#ifndef COMMON_SOURCE_MKCOLLISIONUTIL_H
#define COMMON_SOURCE_MKCOLLISIONUTIL_H

#include <dolphin/types.h>
#include "unplaced_enums.h"

class MKCollisionAABB;
class MKCollisionBox;
class MKCollisionEllipsoid;
class MKCollisionRay;
class MKCollisionResult;
class MKSweptBox;
class MKVector3;
class MKVector4;
class Matrix;

class MKCollisionAABB {
public:
    /* 0x000 */ f32 unk0;
    /* 0x004 */ f32 unk4;
    /* 0x008 */ f32 unk8;
    /* 0x00c */ u8 padC[0x4];
    /* 0x010 */ f32 unk10;
    /* 0x014 */ f32 unk14;
    /* 0x018 */ f32 unk18;
};

class MKCollisionBox {
public:
    void Init(const Matrix &, const MKVector3 &, unsigned int);
    /* 0x000 */ f32 unk0;
    /* 0x004 */ f32 unk4;
    /* 0x008 */ f32 unk8;
    /* 0x00c */ u8 padC[0x4];
    /* 0x010 */ f32 unk10;
    /* 0x014 */ f32 unk14;
    /* 0x018 */ f32 unk18;
    /* 0x01c */ u8 pad1C[0x4];
    /* 0x020 */ f32 unk20;
    /* 0x024 */ f32 unk24;
    /* 0x028 */ f32 unk28;
    /* 0x02c */ u8 pad2C[0x4];
    /* 0x030 */ f32 unk30;
    /* 0x034 */ f32 unk34;
    /* 0x038 */ f32 unk38;
    /* 0x03c */ u8 pad3C[0x4];
    /* 0x040 */ f32 unk40;
    /* 0x044 */ f32 unk44;
    /* 0x048 */ f32 unk48;
    /* 0x04c */ u8 pad4C[0x4];
    /* 0x050 */ f32 unk50;
    /* 0x054 */ f32 unk54;
    /* 0x058 */ f32 unk58;
    /* 0x05c */ u8 pad5C[0x4];
    /* 0x060 */ f32 unk60;
    /* 0x064 */ f32 unk64;
    /* 0x068 */ f32 unk68;
    /* 0x06c */ u8 pad6C[0x4];
    /* 0x070 */ f32 unk70;
    /* 0x074 */ f32 unk74;
    /* 0x078 */ f32 unk78;
    /* 0x07c */ u8 pad7C[0x4];
    /* 0x080 */ f32 unk80;
    /* 0x084 */ f32 unk84;
    /* 0x088 */ f32 unk88;
    /* 0x08c */ u8 pad8C[0x4];
    /* 0x090 */ f64 unk90;
    /* 0x098 */ f64 unk98;
    /* 0x0a0 */ f64 unkA0;
    /* 0x0a8 */ f64 unkA8;
    /* 0x0b0 */ u32 unkB0;
    /* 0x0b4 */ u8 padB4[0x4];
    /* 0x0b8 */ f64 unkB8;
    /* 0x0c0 */ f64 unkC0;
    /* 0x0c8 */ f64 unkC8;
    /* 0x0d0 */ f64 unkD0;
    /* 0x0d8 */ f64 unkD8;
    /* 0x0e0 */ f64 unkE0;
    /* 0x0e8 */ f64 unkE8;
    /* 0x0f0 */ f64 unkF0;
    /* 0x0f8 */ f64 unkF8;
    /* 0x100 */ f64 unk100;
    /* 0x108 */ f64 unk108;
    /* 0x110 */ f64 unk110;
    /* 0x118 */ f64 unk118;
    /* 0x120 */ f64 unk120;
    /* 0x128 */ f64 unk128;
    /* 0x130 */ f64 unk130;
    /* 0x138 */ f64 unk138;
    /* 0x140 */ f64 unk140;
    /* 0x148 */ f64 unk148;
    /* 0x150 */ f64 unk150;
    /* 0x158 */ f64 unk158;
    /* 0x160 */ f64 unk160;
    /* 0x168 */ f64 unk168;
    /* 0x170 */ f64 unk170;
};

class MKCollisionEllipsoid {
public:
    void GetTotalAABB(MKCollisionEllipsoid *, int);
    void CreateAABB(Matrix *);
    /* 0x000 */ u8 pad0[0x40];
    /* 0x040 */ f32 unk40;
    /* 0x044 */ u8 pad44[0x3c];
    /* 0x080 */ f32 unk80;
    /* 0x084 */ u8 pad84[0xc];
    /* 0x090 */ f64 unk90;
    /* 0x098 */ f32 unk98;
    /* 0x09c */ u8 pad9C[0x4];
    /* 0x0a0 */ f64 unkA0;
    /* 0x0a8 */ f32 unkA8;
};

class MKCollisionRay {
public:
    void Init(const MKVector3 &, const MKVector3 &, float, unsigned int);
    /* 0x000 */ f64 unk0;
    /* 0x008 */ f64 unk8;
    /* 0x010 */ f64 unk10;
    /* 0x018 */ f64 unk18;
    /* 0x020 */ f64 unk20;
    /* 0x028 */ f32 unk28;
    /* 0x02c */ u8 pad2C[0x4];
    /* 0x030 */ f64 unk30;
    /* 0x038 */ f32 unk38;
    /* 0x03c */ u8 pad3C[0x4];
    /* 0x040 */ f32 unk40;
    /* 0x044 */ f32 unk44;
    /* 0x048 */ f32 unk48;
    /* 0x04c */ u8 pad4C[0x4];
    /* 0x050 */ f32 unk50;
    /* 0x054 */ f32 unk54;
    /* 0x058 */ s32 unk58;
};

class MKSweptBox {
public:
    void SetAABB(Matrix &, const MKVector3 &, const MKVector3 &, float);
    /* 0x000 */ u8 pad0[0x930];
    /* 0x930 */ f64 unk930;
    /* 0x938 */ f64 unk938;
    /* 0x940 */ f64 unk940;
    /* 0x948 */ f64 unk948;
};

void MKCollision_GetVertexColorFromPoly(const MKVector3 *, MKVector4 *);
u8 MKCollision_SweepSphereToEdge(const MKCollisionRay &, const MKVector3 &, const MKVector3 &, MKCollisionResult *, float *);
u8 MKCollision_SweepSphereTest(const MKCollisionRay &, MKVector3 *, MKCollisionResult *, int, MKCollisionDirection);
u8 MKCollision_SphereTest(const MKCollisionRay &, MKVector3 *, MKCollisionResult *, int, MKCollisionDirection);
s32 MKCollision_Clip3D(const MKVector3 &, const MKVector3 &, const MKVector3 &, float &, float &);
u8 Clip(float, float, float, float &, float &);
MKVector3 VectorAbs(const MKVector3 &);
void MKCollision_CalcAABB(Matrix *, const MKCollisionAABB &, MKCollisionAABB *);
s32 MKCollision_ResolveMaterialNameToID(const char *);
#endif  // COMMON_SOURCE_MKCOLLISIONUTIL_H
