#ifndef SPYRO_SOURCE_GAMECAMERA2_H
#define SPYRO_SOURCE_GAMECAMERA2_H

#include <dolphin/types.h>
#include "common/Source/MKVector3.h"
#include "spyro/source/KDCamera.h"

class GameCamera2;
class GameCamera2Descriptor;
class GameCameraEmuStateMachine;
class KDCamera;
class KDCameraDeltaStages;
class KDCameraDescriptor;
class MKIniLine;
class MKMessage;
class MKVector3;
class Targetable;

class GameCamera2 : public KDCamera {  // base: ctor/dtor vtable stores
public:
    virtual ~GameCamera2(void);
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Message(MKMessage *);
    virtual void ResetCamera(void);
    virtual void ClearData(void);
    virtual void UpdateCamera(void);
    virtual void DrawCamera(void);
    virtual void GetFieldOfView(void);
    virtual f32 GetIdealFieldOfView(void);
    virtual void IsUnderwater(void);
    virtual u32 PlayerRotatedCamera(void);
    virtual void DeltaUpdate(void);
    virtual f32 GetDefaultDeltaTime(void);
    virtual void PreCameraUpdate(void);
    virtual void PostCameraUpdate(void);
    virtual void PostStateUpdate(void);
    virtual u8 ProcessCameraStateRequest(int);
    virtual s32 CameraStatesMessage(MKMessage *);
    virtual void SnapToSafetySetNextMode(void);
    virtual void CollSlideUpdate(const MKVector3 &);
    virtual void CameraEffectsMessage(MKMessage *);
    virtual void CameraEffectsUpdate(void);
    virtual void MiscMessage(MKMessage *);
    u8 CanLowerCamera(float *);
    void HeroStateHelperMessage(MKMessage *);
    void UpdateSnaps(void);
    void TrackedShakePropUpdate(void);
    void AdjustPitchWithFloorUpdateFall(void);
    u8 AdjustPitchWithFloorForPos(const MKVector3 &);
    void AdjustPitchWithFloorUpdate(void);
    void AdjustPitchWithFloorExit(void);
    void AdjustPitchWithFloorDisable(void);
    void LockOnTargetableUpdate(void);
    void LockOnTargetableEnter(void);
    void StrafeUpdate(void);
    void SmoothBehindHeroUpdate(void);
    void SlowMoAirCombatUpdate(void);
    void SlowMoAirCombatExit(void);
    void SlowMoAirCombatEnter(void);
    void GlideSetYawOffset(void);
    void GlideUpdate(void);
    void GlideEnter(void);
    void SmoothToDirectionUpdate(void);
    void HoldGivenDirectionUpdate(void);
    void HoldGivenDirectionEnter(void);
    void HoldCurrentDirectionUpdate(void);
    f32 PlayerAdjustGetRotateSpeed(void);
    void PlayerAdjustUpdate(void);
    void PlayerAdjustExit(void);
    void EmuStatesUpdate(void);
    void DeltaStagesMessage(MKMessage *);
    void SetDeltaStages(int, bool);
    void CenterBehindHeroUpdate(void);
    void CutSceneExit(void);
    void StaticPosUpdate(void);
    void StaticPosEnter(void);
    void TrainUpdate(void);
    void TrainExit(void);
    void TrainEnter(void);
    void InitModule(void);
    static u8 pPossibleStateChanges[0x4];
    static u8 pEmuStateDescriptors[0x4];
    /* 0x218 */ u8 pad218[0x8];
    /* 0x220 */ f32 unk220;
    /* 0x224 */ f32 unk224;
    /* 0x228 */ f32 unk228;
    /* 0x22c */ u8 pad22C[0x4];
    /* 0x230 */ MKVector3 unk230;
    /* 0x240 */ u8 unk240;
    /* 0x241 */ u8 pad241[0x3];
    /* 0x244 */ s32 unk244;
    /* 0x248 */ s32 unk248;
    /* 0x24c */ u8 pad24C[0x1c];
    /* 0x268 */ s32 unk268;
    /* 0x26c */ GameCameraEmuStateMachine* unk26C;
    /* 0x270 */ f64 unk270;
    /* 0x278 */ f32 unk278;
    /* 0x27c */ u8 pad27C[0x4];
    /* 0x280 */ f32 unk280;
    /* 0x284 */ f32 unk284;
    /* 0x288 */ f32 unk288;
    /* 0x28c */ u8 pad28C[0x4];
    /* 0x290 */ f32 unk290;
    /* 0x294 */ f32 unk294;
    /* 0x298 */ Targetable* unk298;
    /* 0x29c */ u8 unk29C;
    /* 0x29d */ u8 pad29D[0x3];
    /* 0x2a0 */ u8 unk2A0;
    /* 0x2a1 */ u8 pad2A1[0x3];
    /* 0x2a4 */ f32 unk2A4;
    /* 0x2a8 */ void* unk2A8;
    /* 0x2ac */ u32 unk2AC;
    /* 0x2b0 */ s8 unk2B0;
    /* 0x2b1 */ u8 pad2B1[0x3];
    /* 0x2b4 */ f32 unk2B4;
};

class GameCamera2Descriptor : public KDCameraDescriptor {  // base: inlined ctor vtable stores
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    u8 LoadDeltaStages(MKIniLine *);
    KDCameraDeltaStages * GetDeltaStages(int);
    /* 0x0ac */ f32 unkAC;
    /* 0x0b0 */ f32 unkB0;
    /* 0x0b4 */ s32 unkB4;
    /* 0x0b8 */ s32 unkB8;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline GameCamera2::~GameCamera2() {
    s32 temp_cr0_eq_15;

    temp_cr0_eq_15 = this == NULL;
    if (temp_cr0_eq_15 == 0) {
        if (temp_cr0_eq_15 == 0) {
            if (temp_cr0_eq_15 == 0) {
            }
        }
    }
}

inline f32 GameCamera2::GetDefaultDeltaTime() {
    return 0.5f;
}

#endif  // SPYRO_SOURCE_GAMECAMERA2_H
