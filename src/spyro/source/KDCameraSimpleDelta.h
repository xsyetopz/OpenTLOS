#ifndef SPYRO_SOURCE_KDCAMERASIMPLEDELTA_H
#define SPYRO_SOURCE_KDCAMERASIMPLEDELTA_H

#include <dolphin/types.h>

class KDCameraDeltaStages;
class KDCameraDeltaStagesEx;
class KDCameraSimpleDelta;
class MKIniLine;
class MKVector3;

class KDCameraDeltaStages {
public:
    s32 LoadLine(MKIniLine *, char *);
    /* 0x000 */ f32 unk0;
    /* 0x004 */ f32 unk4;
    /* 0x008 */ f32 unk8;
};

class KDCameraDeltaStagesEx {
public:
    f32 GetPitch(void);
    f32 GetYDelta(void);
    f32 GetZDelta(void);
    void SetStages(float, float, float);
    void Init(float *, float *);
    /* 0x000 */ f32 unk0;
    /* 0x004 */ f32 unk4;
    /* 0x008 */ f32 unk8;
    /* 0x00c */ f32* unkC;
    /* 0x010 */ f32* unk10;
};

class KDCameraSimpleDelta {
public:
    class Override {
    public:
        void DisableSmoothDelta(void);
        void EnableSmoothDelta(float);
        void DisableSmoothPitch(void);
        void EnableSmoothPitch(float, float, bool);
        void EnableSmoothPitch(float, float);
    };
    f32 GetIdealPitch(void);
    u8 IsUsingIdealPitch(void);
    f32 GetIdealDelta(void);
    f32 GetCurrentPitch(void);
    void GetIdealDeltaVector(void);
    void GetCurrentDeltaVector(void);
    u8 IsUsingIdealStages(void);
    void GetCurrentTargetOffset(void);
    u8 IsUsingIdealDelta(void);
    void OverrideUpdate(void);
    void DisableDeltaOverride(float);
    void DisablePitchOverride(float);
    void DisableOverride(float, float);
    void EnablePitchOverride(float, float);
    void EnableOverride(float, float, float);
    void SetDeltaStages(KDCameraDeltaStages *, bool, bool);
    void GetDeltaVectorAtPitch(float);
    f32 GetCurrentDelta(void);
    void Update(const MKVector3 &);
    void ClearData(void);
    void Init(const KDCameraDeltaStages &, float, float);
    /* 0x000 */ f32 unk0;
    /* 0x004 */ f32 unk4;
    /* 0x008 */ f32 unk8;
    /* 0x00c */ f32* unkC;
    /* 0x010 */ f32* unk10;
    /* 0x014 */ f32 unk14;
    /* 0x018 */ f32 unk18;
    /* 0x01c */ f32 unk1C;
    /* 0x020 */ f32* unk20;
    /* 0x024 */ f32* unk24;
    /* 0x028 */ f32 unk28;
    /* 0x02c */ u8 pad2C[0x8];
    /* 0x034 */ f32 unk34;
    /* 0x038 */ u8 pad38[0x4];
    /* 0x03c */ f32 unk3C;
    /* 0x040 */ f32 unk40;
    /* 0x044 */ u8 unk44;
    /* 0x045 */ u8 pad45[0x3];
    /* 0x048 */ f32 unk48;
    /* 0x04c */ f32 unk4C;
    /* 0x050 */ f32 unk50;
    /* 0x054 */ u32 unk54;
};

#endif  // SPYRO_SOURCE_KDCAMERASIMPLEDELTA_H
