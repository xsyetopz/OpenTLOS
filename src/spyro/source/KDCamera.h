#ifndef SPYRO_SOURCE_KDCAMERA_H
#define SPYRO_SOURCE_KDCAMERA_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"
#include "common/Source/Matrix.h"

class KDCamera;
class KDCameraDeltaStagesEx;
class KDCameraDescriptor;
class KDCameraHeroData;
class KDCameraHeroMoveYaw;
class KDCameraJumpTargetOffset;
class KDCameraPoint;
class KDCameraStateChangeRequest;
class KDCameraStateStack;
class KDCollisionObject;
class KDMessageStorage;
class MKCollisionMode;
class MKCollisionResult;
class MKIniLine;
class MKMessage;
class MKProp;
class MKPropDescriptor;
class MKVector3;
class Matrix;

class KDCamera : public MKProp {  // base: ctor/dtor vtable stores
public:
    virtual ~KDCamera(void);
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Message(MKMessage *);
    virtual void ResetCamera(void);
    virtual void ClearData(void);
    virtual void UpdateCamera(void);
    virtual void DrawCamera(void);
    virtual void DrawText(void);
    virtual void Use(void);
    virtual void GetFieldOfView(void);
    virtual f32 GetIdealFieldOfView(void);
    virtual void IsUnderwater(void);
    virtual u32 PlayerRotatedCamera(void);
    virtual void DeltaUpdate(void);
    virtual f32 GetDefaultDeltaTime(void);
    virtual void PreCameraUpdate(void);
    virtual void PostCameraUpdate(void);
    virtual void PreStateEnter(void);
    virtual void PostStateEnter(void);
    virtual void PreStateExit(void);
    virtual void PostStateExit(void);
    virtual void PreStateUpdate(void);
    virtual void PostStateUpdate(void);
    virtual u8 ProcessCameraStateRequest(int);
    virtual s32 CameraStatesMessage(MKMessage *);
    virtual void SnapToSafetySetNextMode(void);
    virtual void CollSlideUpdate(const MKVector3 &);
    virtual void CameraEffectsMessage(MKMessage *);
    virtual void CameraEffectsUpdate(void);
    virtual void CameraWasTeleported(bool);
    virtual s32 IgnoreCollision(MKCollisionResult &);
    virtual void MiscMessage(MKMessage *);
    void GetYaw(void);
    void GetXZDir(void);
    void GetTarget(void);
    f32 GetSafePitch(float, float);
    void GetSmoothToAngleDelta(float, float, float);
    void GetSmoothedAngleOffset(float, float, float);
    void GetIdealSource(const MKVector3 &, const MKVector3 &, MKVector3 *);
    f32 GetUpdatedSourceY(const MKVector3 &, const MKVector3 &, int);
    void GetUpdatedSource(const MKVector3 &, const MKVector3 &, const MKVector3 *, float);
    void GetUpdatedTarget(void);
    void SetCameraCollisionInfoItems(bool);
    s32 SnapToDirectionForce(const MKVector3 &);
    u8 SnapToDirection(const MKVector3 &);
    u8 GetForceSnapPos(const MKVector3 &, const MKVector3 &, MKVector3 *, MKVector3 *);
    u8 GetSnapPos(const MKVector3 &, const MKVector3 &, MKVector3 *, MKVector3 *);
    u8 IsPointSafeAndViewClearSweep(const MKVector3 &, const MKVector3 &, float, int, MKCollisionResult *);
    u8 IsPointSafeAndViewClear(const MKVector3 &, const MKVector3 &, MKCollisionResult *);
    u8 IsPointSafe(const MKVector3 &, MKCollisionResult *);
    void GetCollisionObjectPos(void);
    s8 TryTeleport(const MKVector3 &, bool);
    void Teleport(const MKVector3 &, bool);
    void UpdateStoredCollisionData(bool);
    void CollisionObjectUpdate(const MKVector3 &);
    void CollisionObjectUpdate(void);
    void CollisionUpdate(void);
    void TestFloor(const MKVector3 &, MKCollisionResult *, float);
    void TestFloor(const MKVector3 &, MKCollisionResult *, MKCollisionMode, int, float);
    s32 SphereCollide(const MKVector3 &, float, MKCollisionResult *, int, MKCollisionMode, int, bool);
    u8 SweepSphereCollide(const MKVector3 &, const MKVector3 &, float, MKCollisionResult *, MKCollisionMode, int, bool);
    u8 RayCollide(const MKVector3 &, const MKVector3 &, MKCollisionResult *, MKCollisionMode, int, bool);
    void CutSceneUpdate(void);
    void CutSceneExit(void);
    void ChaseUpdate(void);
    f32 * GetForceDirectionPtr(void);
    void ChaseEnter(void);
    void UpdateCameraStateRequests(void);
    u8 TestUserStateFlag(unsigned int);
    u8 FadeOutPropsUpdate(const MKVector3 &, const MKVector3 &);
    void SnapToSafetyTryForceSnap(const MKVector3 &, const MKVector3 &);
    void SnapToSafetyTryIdealPos(const MKVector3 &, const MKVector3 &);
    void SnapToSafetyTryDesiredPos(const MKVector3 &, const MKVector3 &);
    void SnapToSafetyUpdate(const MKVector3 &);
    void VisibleTargetDisable(void);
    void VisibleTargetUpdate(void);
    void GetDeltaTargetVelocity(void);
    void HeroMoveYawUpdate(void);
    void GetHeroTargetPos(void);
    void GetHeroTargetPos(const MKVector3 &);
    void UpdateLTW(void);
    void SetLTW(const Matrix &);
    f32 GetMoveYaw(void);
    KDCamera(void);
    void InitModule(void);
    void GetDir(bool);
    static u8 bModuleInitialised[0x1];
    static u8 pStateDescriptors[0x4];
    static u8 pMessageStorageDescriptors[0x4];
    /* 0x04c */ u8 unk4C;
    /* 0x04d */ u8 pad4D[0x3];
    /* 0x050 */ KDCameraHeroData* unk50;
    /* 0x054 */ KDCameraDeltaStagesEx* unk54;
    /* 0x058 */ KDMessageStorage* unk58;
    /* 0x05c */ u8 pad5C[0x4];
    /* 0x060 */ Matrix unk60;
    /* 0x0a0 */ KDCameraPoint* unkA0;
    /* 0x0a4 */ KDCameraPoint* unkA4;
    /* 0x0a8 */ f32 unkA8;
    /* 0x0ac */ u8 padAC[0x4];
    /* 0x0b0 */ f64 unkB0;
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
    /* 0x110 */ f32 unk110;
    /* 0x114 */ f32 unk114;
    /* 0x118 */ f32 unk118;
    /* 0x11c */ f32 unk11C;
    /* 0x120 */ void* unk120;
    /* 0x124 */ f32 unk124;
    /* 0x128 */ f32 unk128;
    /* 0x12c */ f32 unk12C;
    /* 0x130 */ f32 unk130;
    /* 0x134 */ u8 pad134[0x4];
    /* 0x138 */ KDCameraHeroMoveYaw* unk138;
    /* 0x13c */ u8 unk13C;
    /* 0x13d */ u8 unk13D;
    /* 0x13e */ u8 pad13E[0x2];
    /* 0x140 */ KDCameraJumpTargetOffset* unk140;
    /* 0x144 */ u8 pad144[0x4];
    /* 0x148 */ f32 unk148;
    /* 0x14c */ f32 unk14C;
    /* 0x150 */ f32 unk150;
    /* 0x154 */ u8 pad154[0x4];
    /* 0x158 */ s32 unk158;
    /* 0x15c */ KDCameraStateStack* unk15C;
    /* 0x160 */ KDCameraStateChangeRequest* unk160;
    /* 0x164 */ s32 unk164;
    /* 0x168 */ f32 unk168;
    /* 0x16c */ u8 pad16C[0x4];
    /* 0x170 */ f32 unk170;
    /* 0x174 */ u8 unk174;
    /* 0x175 */ u8 pad175[0x3];
    /* 0x178 */ s32 unk178;
    /* 0x17c */ u32 unk17C;
    /* 0x180 */ u8 unk180;
    /* 0x181 */ u8 pad181[0x7];
    /* 0x188 */ f32 unk188;
    /* 0x18c */ f32 unk18C;
    /* 0x190 */ f32 unk190;
    /* 0x194 */ u8 pad194[0x4];
    /* 0x198 */ f32 unk198;
    /* 0x19c */ f32 unk19C;
    /* 0x1a0 */ f32 unk1A0;
    /* 0x1a4 */ u8 pad1A4[0x4];
    /* 0x1a8 */ f32 unk1A8;
    /* 0x1ac */ f32 unk1AC;
    /* 0x1b0 */ f32 unk1B0;
    /* 0x1b4 */ u8 pad1B4[0x4];
    /* 0x1b8 */ f32 unk1B8;
    /* 0x1bc */ f32 unk1BC;
    /* 0x1c0 */ f32 unk1C0;
    /* 0x1c4 */ u8 pad1C4[0x4];
    /* 0x1c8 */ f32 unk1C8;
    /* 0x1cc */ f32 unk1CC;
    /* 0x1d0 */ f32 unk1D0;
    /* 0x1d4 */ u8 pad1D4[0x4];
    /* 0x1d8 */ f64 unk1D8;
    /* 0x1e0 */ f32 unk1E0;
    /* 0x1e4 */ u8 pad1E4[0x4];
    /* 0x1e8 */ f32 unk1E8;
    /* 0x1ec */ u8 unk1EC;
    /* 0x1ed */ u8 unk1ED;
    /* 0x1ee */ u8 pad1EE[0x2];
    /* 0x1f0 */ s32 unk1F0;
    /* 0x1f4 */ s8 unk1F4;
    /* 0x1f5 */ u8 pad1F5[0x3];
    /* 0x1f8 */ KDCamera* unk1F8;
    /* 0x1fc */ s32 unk1FC;
    /* 0x200 */ KDCollisionObject* unk200;
    /* 0x204 */ u8 unk204;
    /* 0x205 */ u8 pad205[0x3];
    /* 0x208 */ f32 unk208;
    /* 0x20c */ f32 unk20C;
};

class KDCameraDescriptor : public MKPropDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    /* 0x048 */ u8 pad48[0x18];
    /* 0x060 */ s32 unk60;
    /* 0x064 */ s32 unk64;
    /* 0x068 */ s32 unk68;
    /* 0x06c */ s32 unk6C;
    /* 0x070 */ f32 unk70;
    /* 0x074 */ f32 unk74;
    /* 0x078 */ f32 unk78;
    /* 0x07c */ f32 unk7C;
    /* 0x080 */ f32 unk80;
    /* 0x084 */ f32 unk84;
    /* 0x088 */ f32 unk88;
    /* 0x08c */ f32 unk8C;
    /* 0x090 */ f32 unk90;
    /* 0x094 */ s32 unk94;
    /* 0x098 */ s32 unk98;
    /* 0x09c */ s32 unk9C;
    /* 0x0a0 */ s32 unkA0;
    /* 0x0a4 */ f32* unkA4;
    /* 0x0a8 */ s32 unkA8;
};

class KDCameraStateChangeRequest {
public:
    /* 0x000 */ u8 pad0[0x7c];
    /* 0x07c */ s32 unk7C;
};

extern u8 cameraCollPushOut[0x4];
// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#include <m2c_macros.h>

inline KDCamera::~KDCamera() {
    s32 temp_cr0_eq_5151;

    temp_cr0_eq_5151 = this == NULL;
    if (temp_cr0_eq_5151 == 0) {
        if (temp_cr0_eq_5151 == 0) {
        }
    }
}

inline void KDCamera::GetDir(bool arg0) {
    void *temp_r4_1263;

    temp_r4_1263 = M2C_FIELD(arg0, void **, 8);
    M2C_FIELD(this, f64 *, 0) = (f64) M2C_FIELD(temp_r4_1263, f64 *, 0x20);
    M2C_FIELD(this, f64 *, 8) = (f64) M2C_FIELD(temp_r4_1263, f64 *, 0x28);
}

#if 0 // DRAFT: undefined identifier '__vptr'
inline f32 KDCamera::GetIdealFieldOfView() {
    M2C_FIELD(this->__vptr, M2C_UNK (**)(KDCamera *), 0x50)(this);
}
#endif

inline void KDCamera::PostStateEnter() {

}

inline void KDCamera::PreStateExit() {

}

inline void KDCamera::PostStateExit() {
    this->unk158 = 0;
}

inline void KDCamera::PreStateUpdate() {

}

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'MKCollisionResult'
inline s32 KDCamera::IgnoreCollision(MKCollisionResult &arg0) {
    return (arg0.unk44 & M2C_FIELD(M2C_FIELD(this->unk0, void **, 0xA4), s32 *, 0x18)) != 0;
}
#endif

#if 0 // DRAFT: undefined identifier 'unkspC'
inline void KDCamera::GetYaw() {
    f64 sp10;
    f64 sp8;
    void *temp_r3_2251;

    temp_r3_2251 = this->unk8;
    sp8 = M2C_FIELD(temp_r3_2251, f64 *, 0x20);
    sp10 = M2C_FIELD(temp_r3_2251, f64 *, 0x28);
    if ((((f32) sp10 * (f32) sp10) + (((f32) sp8 * (f32) sp8) + (unkspC * unkspC))) != 0.0f) {
        NormaliseAngle(KDMath_GetYaw(*((MKVector3 *) &sp8)));
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unksp34'
inline void KDCamera::GetXZDir() {
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 sp8;
    f32 var_f4_2648;
    f32 var_f5_2670;
    f64 temp_f1_2675;
    f64 temp_f1_2681;
    f64 temp_f1_2685;
    s32 temp_r4_2704;
    s32 var_r0_2714;
    void *temp_r4_2649;

    var_f4_2648 = 0.0f;
    temp_r4_2649 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), void **, 8);
    sp14 = 0.0f;
    sp40 = M2C_FIELD(temp_r4_2649, f64 *, 0x20);
    sp48 = M2C_FIELD(temp_r4_2649, f64 *, 0x28);
    sp10 = (f32) sp40;
    sp18 = (f32) sp48;
    sp30 = (f64) sp10;
    sp38 = (f64) sp18;
    var_f5_2670 = ((f32) sp38 * (f32) sp38) + (((f32) sp30 * (f32) sp30) + (unksp34 * unksp34));
    if (var_f5_2670 > 1e-12f) {
        if (var_f5_2670 > 0.0f) {
            temp_f1_2675 = __frsqrte(var_f5_2670);
            temp_f1_2681 = 0.5 * temp_f1_2675 * -(((f64) var_f5_2670 * (temp_f1_2675 * temp_f1_2675)) - 3.0);
            temp_f1_2685 = 0.5 * temp_f1_2681 * -(((f64) var_f5_2670 * (temp_f1_2681 * temp_f1_2681)) - 3.0);
            var_f5_2670 = (f32) ((f64) var_f5_2670 * (0.5 * temp_f1_2685 * -(((f64) var_f5_2670 * (temp_f1_2685 * temp_f1_2685)) - 3.0)));
        } else if (var_f5_2670 < M2C_BITWISE(f32, 0.0)) {
            var_f5_2670 = __float_nan;
        } else {
            sp8 = var_f5_2670;
            temp_r4_2704 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r4_2704) {                 /* irregular */
            case 0x7F800000:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_2714 = 1;
                } else {
                    var_r0_2714 = 2;
                }
                break;
            case 0x0:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_2714 = 5;
                } else {
                    var_r0_2714 = 3;
                }
                break;
            default:
                var_r0_2714 = 4;
                break;
            }
            if (var_r0_2714 == 1) {
                var_f5_2670 = __float_nan;
            }
        }
        var_f4_2648 = 1.0f / var_f5_2670;
    }
    sp24 = unksp34 * var_f4_2648;
    sp20 = (f32) sp30 * var_f4_2648;
    sp28 = (f32) sp38 * var_f4_2648;
    M2C_FIELD(this, f64 *, 0) = (f64) sp20;
    M2C_FIELD(this, f64 *, 8) = (f64) sp28;
}
#endif

inline void KDCamera::GetTarget() {
    void *temp_r4_2903;

    temp_r4_2903 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), void **, 0xA4);
    M2C_FIELD(this, f64 *, 0) = (f64) M2C_FIELD(temp_r4_2903, f64 *, 0);
    M2C_FIELD(this, f64 *, 8) = (f64) M2C_FIELD(temp_r4_2903, f64 *, 8);
}

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline void KDCamera::GetFieldOfView() {
    return M2C_FIELD(this->unk0, f32 *, 0x70);
}
#endif

inline f32 KDCamera::GetDefaultDeltaTime() {
    return 0.2f;
}

inline void KDCamera::PostStateUpdate() {

}

inline void KDCamera::CollSlideUpdate(const MKVector3 &arg0) {

}

inline f32 *KDCamera::GetForceDirectionPtr() {
    f32 temp_f1_2284;
    f32 temp_f2_2283;
    f32 temp_f3_2286;

    temp_f2_2283 = this->unk128;
    temp_f1_2284 = this->unk12C;
    temp_f3_2286 = this->unk130;
    if (((temp_f3_2286 * temp_f3_2286) + ((temp_f2_2283 * temp_f2_2283) + (temp_f1_2284 * temp_f1_2284))) != 0.0f) {
        return &this->unk128;
    }
    return NULL;
}

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline void KDCamera::IsUnderwater() {
    return 0;
}
#endif

#endif  // SPYRO_SOURCE_KDCAMERA_H
