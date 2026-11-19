#ifndef COMMON_SOURCE_ANIMATION_H
#define COMMON_SOURCE_ANIMATION_H

#include <dolphin/types.h>
#include "unplaced_enums.h"

class Animation;
class AnimationData;
class Animation_cpp;
class BlendShapeState;
class MKHeap;
class MKVector3;
class MKVector4;
class Matrix;

class AnimationData {
public:
    class BlendShape;
    class Node;
    void UnpackTemplatePointers(bool);
    /* 0x000 */ u8 pad0[0x4];
    /* 0x004 */ u8 unk4;
    /* 0x005 */ u8 pad5[0x3];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0xb];
    /* 0x014 */ void* unk14;
    /* 0x018 */ s32 unk18;
    /* 0x01c */ AnimationData::BlendShape* unk1C;
};

class Animation {
public:
    class FrameInstance;
    void EnableCustomMatrices(bool);
    BlendShapeState * CalculateBlendShape(int, BlendShapeState *);
    void DecompressWeights(float *, unsigned char *, int, float);
    Matrix * CalculateMatrices(Matrix *, int, short *, const Matrix *);
    void ConvertFrameToMatrix(Matrix *, int);
    void CalculateFrame(Animation::FrameInstance *, AnimationData::Node *, bool, bool);
    void GetPositionalOffset(float);
    s32 GetNodeName(int);
    void GetNodeOrigin(int);
    s8 GetNodeParentIndex(int);
    s8 GetNodeIndex(const char *);
    u8 NodeExists(const char *, int *);
    s8 GetNmbrOfNodes(void);
    MKHeap * GetName(void);
    f32 InterpolateFrameData(Animation::FrameInstance *, float, const MKVector3 &, const MKVector4 &, const MKVector3 &, const MKVector3 &, const MKVector4 &, const MKVector3 &);
    void InterpolateFrame(Animation::FrameInstance *, AnimationData::Node *, float);
    void SetCustomMatrix(int, const Matrix *, AnimationMatrixPosition, bool);
    void TweenNode(float, float, int, bool, bool);
    void Tween(float, float);
    void ReloadGuts(void);
    void * GetTemplate(float);
    void LinkBlendShapeToNode(const char *, const char *);
    void Destroy(void);
    Animation * Create(const char *, int);
    /* 0x000 */ void* unk0;
    /* 0x004 */ f32 unk4;
    /* 0x008 */ f64 unk8;
    /* 0x010 */ s32 unk10;
    /* 0x014 */ MKHeap* unk14;
    /* 0x018 */ u32 unk18;
    /* 0x01c */ void* unk1C;
    /* 0x020 */ s8* unk20;
    /* 0x024 */ u8 unk24;
    /* 0x025 */ u8 pad25[0x3];
    /* 0x028 */ s32 unk28;
};

class Animation_cpp {
public:
    void __sinit(void);
};

class BlendShapeState {
public:
    /* 0x000 */ u8 pad0[0x4];
    /* 0x004 */ s32 unk4;
    /* 0x008 */ f32 unk8;
};

MKHeap * CreateTemplate(const char *);
void Animation_DeinitModule(void);
void Animation_InitModule(void);
extern s8 * Animation_pTemplates;
#endif  // COMMON_SOURCE_ANIMATION_H
