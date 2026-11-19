#ifndef SPYRO_SOURCE_SCREENWOBBLEFX_H
#define SPYRO_SOURCE_SCREENWOBBLEFX_H

#include <dolphin/types.h>
#include "common/Source/MKVector4.h"

class MKMaterial;
class MKVector3;
class MKVector4;
class ScreenWobbleFX;

class ScreenWobbleFX {
public:
    void SetMotionBlurCapEnable(bool);
    void GetMotionBlurCap(void);
    void SetSpeedEffectCenter(const MKVector3 &);
    void EnableSpeedEffect(bool, float, float);
    void DrawSpeedEffect(void);
    void AddRandomWobbleForce(float);
    void InitWobbleNodes(void);
    void Deinit(void);
    void Draw(void);
    void DrawScreenFlash(void);
    void Update(void);
    void EnableScreenFlash(const MKVector4 &, float);
    void Init(void);
    /* 0x000 */ void* unk0;
    /* 0x004 */ f32 unk4;
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ MKMaterial* unkC;
    /* 0x010 */ f32 unk10;
    /* 0x014 */ s32 unk14;
    /* 0x018 */ u8 unk18;
    /* 0x019 */ u8 pad19[0x3];
    /* 0x01c */ MKMaterial* unk1C;
    /* 0x020 */ u8 unk20;
    /* 0x021 */ u8 pad21[0x3];
    /* 0x024 */ f32 unk24;
    /* 0x028 */ f64 unk28;
    /* 0x030 */ f64 unk30;
    /* 0x038 */ s8 unk38;
    /* 0x039 */ u8 pad39[0x3];
    /* 0x03c */ f32 unk3C;
    /* 0x040 */ f32 unk40;
    /* 0x044 */ u8 pad44[0x4];
    /* 0x048 */ MKVector4 unk48;
    /* 0x058 */ u8 unk58;
    /* 0x059 */ u8 pad59[0x3];
    /* 0x05c */ MKMaterial* unk5C;
    /* 0x060 */ s8 unk60;
    /* 0x061 */ u8 pad61[0x3];
    /* 0x064 */ s32 unk64;
    /* 0x068 */ u8 unk68;
    /* 0x069 */ u8 pad69[0x3];
    /* 0x06c */ f32 unk6C;
    /* 0x070 */ f32 unk70;
};

#endif  // SPYRO_SOURCE_SCREENWOBBLEFX_H
