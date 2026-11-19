#ifndef SPYRO_SOURCE_CAMERADATA_H
#define SPYRO_SOURCE_CAMERADATA_H

#include <dolphin/types.h>

class CameraData;

class CameraData {
public:
    void ClearData(void);
    static u8 GetJumpWithTy(void);
    f32 GetPlayerRotatePitchMultiplier(void);
    f32 GetPlayerRotateYawMultiplier(void);
    void Deinit(void);
    void Init(void);
    CameraData(void);
    /* 0x000 */ f32 unk0;
    /* 0x004 */ f32 unk4;
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ f32 unkC;
};

#endif  // SPYRO_SOURCE_CAMERADATA_H
