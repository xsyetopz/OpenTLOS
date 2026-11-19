#ifndef SPYRO_SOURCE_BONEBLURFX_H
#define SPYRO_SOURCE_BONEBLURFX_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"

class BoneBlurFX;
class BoneBlurFXDescriptor;
class BoneBlurFXNodeDef;
class MKMaterial;
class MKModel;
class MKProp;
class MKPropDescriptor;

class BoneBlurFX : public MKProp {  // base: ctor/dtor vtable stores
public:
    class BlurNode;
    virtual ~BoneBlurFX(void);
    virtual void Init(void);
    virtual void Deinit(void);
    virtual void * Update(void);
    virtual void Draw(void);
    void FreePoolMem(void);
    u8 AllocPoolMem(void);
    void Teleport(void);
    void CalcUVs(void);
    void TakeFrameSnapshot(void);
    void EnableBlur(bool);
    void InitData(MKModel *, BoneBlurFXNodeDef *, int, int **, int, int, bool);
    /* 0x04c */ s32 unk4C;
    /* 0x050 */ s32 unk50;
    /* 0x054 */ s32 unk54;
    /* 0x058 */ BoneBlurFX::BlurNode** unk58;
    /* 0x05c */ s32** unk5C;
    /* 0x060 */ s32 unk60;
    /* 0x064 */ BoneBlurFXNodeDef* unk64;
    /* 0x068 */ s32 unk68;
    /* 0x06c */ u8 unk6C;
    /* 0x06d */ u8 pad6D[0x3];
    /* 0x070 */ MKMaterial* unk70;
    /* 0x074 */ MKModel* unk74;
    /* 0x078 */ s32* unk78;
    /* 0x07c */ u8 unk7C;
};

class BoneBlurFXDescriptor : public MKPropDescriptor {  // base: inlined ctor vtable stores
public:
    virtual void Init(void);
    virtual void Deinit(void);
    void DrawInstances(void);
    static u8 pFirstDesc[0x4];
    /* 0x044 */ u8 pad44[0x1c];
    /* 0x060 */ void* unk60;
    /* 0x064 */ BoneBlurFXDescriptor* unk64;
    /* 0x068 */ BoneBlurFXDescriptor* unk68;
};

extern u8 gBoneBlurFXPool[0xc];
extern s32 BONE_BLUR_FX_NODE_POOL_MAX_ALLOCS;
extern s32 BONE_BLUR_FX_NODE_POOL_MAX_NODES;
// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline BoneBlurFX::~BoneBlurFX() {
    s32 temp_cr0_eq_15;

    temp_cr0_eq_15 = this == NULL;
    if (temp_cr0_eq_15 == 0) {
        if (temp_cr0_eq_15 == 0) {
        }
    }
}

#endif  // SPYRO_SOURCE_BONEBLURFX_H
