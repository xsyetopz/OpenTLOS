#ifndef SPYRO_SOURCE_ASSAULTCANNON_H
#define SPYRO_SOURCE_ASSAULTCANNON_H

#include <dolphin/types.h>
#include "common/Source/MKVector3.h"
#include "spyro/source/EnergyBeam.h"
#include "spyro/source/KDStateMachine.h"
#include "spyro/source/ShatterablePlatform.h"
#include "spyro/source/ShatterablePlatformDescriptor.h"

class AssaultCannon;
class AssaultCannonDescriptor;
class AssaultCannon_cpp;
class MKDynamicBone;
class MKHeap;
class MKIniLine;
class MKMessage;
class MKVector3;
class ShatterablePlatform;
class ShatterablePlatformDescriptor;

class AssaultCannon : public ShatterablePlatform {  // base: base ctor call
public:
    virtual ~AssaultCannon(void);
    virtual void Init(void);
    virtual s32 LoadDone(void);
    virtual void Deinit(void);
    virtual void * Update(void);
    virtual void Draw(void);
    virtual void Message(MKMessage *);
    virtual void GetProp(void);
    virtual s32 GetEnemy(void);
    virtual s32 IsHero(void);
    virtual s32 IsFriend(void);
    virtual s32 IsEnemy(void);
    virtual s32 GetMoveToPoint(const MKVector3 &, MKVector3 *);
    virtual s32 GetLookToPoint(const MKVector3 &, MKVector3 *);
    virtual s32 GetAimPoint(const MKVector3 &, MKVector3 *);
    virtual void GetVel(void);
    virtual f32 GetCollisionRadius(void);
    virtual f32 GetCollisionHeight(void);
    virtual f32 GetTimeLastHit(void);
    AssaultCannon(void);
    void CalcSpikeBeamPositions(void);
    void CalcBarrelBeamPositions(void);
    void FreeElecBeams(void);
    void AllocElecBeams(void);
    void EmitShootingFX(void);
    void UpdateTurretBone(MKDynamicBone *, void *);
    void StateDeadExit(void);
    void StateDeadUpdate(void);
    void StateDeadEnter(void);
    void StateFireExit(void);
    void StateFireUpdate(void);
    void StateFireEnter(void);
    void StateTurnToFaceExit(void);
    void StateTurnToFaceUpdate(void);
    void StateTurnToFaceEnter(void);
    void StateIdleExit(void);
    void StateIdleUpdate(void);
    void StateIdleEnter(void);
    u64 UpdateTurning(MKVector3);
    void SetAnim(int, int, float);
    void TakeDamage(float, const MKVector3 &);
    void SetDefaults(void);
    static u8 states[0xb4];
    /* 0x218 */ KDStateMachine<AssaultCannon> unk218;
    /* 0x219 */ u8 pad219[0x17];
    /* 0x230 */ MKVector3 unk230;
    /* 0x240 */ f64 unk240;
    /* 0x248 */ f64 unk248;
    /* 0x250 */ f64 unk250;
    /* 0x258 */ f64 unk258;
    /* 0x260 */ f32 unk260;
    /* 0x264 */ u8 pad264[0x4];
    /* 0x268 */ s32 unk268;
    /* 0x26c */ s32 unk26C;
    /* 0x270 */ u8 pad270[0x24];
    /* 0x294 */ s32 unk294;
    /* 0x298 */ u8 pad298[0x24];
    /* 0x2bc */ u32 unk2BC;
    /* 0x2c0 */ u32 unk2C0;
    /* 0x2c4 */ u32 unk2C4;
    /* 0x2c8 */ u32 unk2C8;
    /* 0x2cc */ u32 unk2CC;
    /* 0x2d0 */ u32 unk2D0;
    /* 0x2d4 */ u32 unk2D4;
    /* 0x2d8 */ f32 unk2D8;
    /* 0x2dc */ f32 unk2DC;
    /* 0x2e0 */ void* unk2E0;
    /* 0x2e4 */ f32 unk2E4;
    /* 0x2e8 */ s32 unk2E8;
    /* 0x2ec */ f32 unk2EC;
    /* 0x2f0 */ u8 unk2F0;
    /* 0x2f1 */ u8 unk2F1;
    /* 0x2f2 */ u8 pad2F2[0x2];
    /* 0x2f4 */ f32 unk2F4;
    /* 0x2f8 */ s32 unk2F8;
    /* 0x2fc */ EnergyBeam::Beam* unk2FC;
    /* 0x300 */ EnergyBeam::Beam* unk300;
    /* 0x304 */ u8 pad304[0x4];
    /* 0x308 */ MKVector3 unk308;
    /* 0x318 */ MKVector3 unk318;
    /* 0x328 */ f64 unk328;
    /* 0x330 */ f64 unk330;
    /* 0x338 */ f64 unk338;
    /* 0x340 */ f64 unk340;
    /* 0x348 */ f64 unk348;
    /* 0x350 */ f32 unk350;
    /* 0x354 */ u8 pad354[0x4];
    /* 0x358 */ f64 unk358;
    /* 0x360 */ f64 unk360;
};

class AssaultCannonDescriptor : public ShatterablePlatformDescriptor {  // base: base ctor call
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    AssaultCannonDescriptor(void);
    /* 0x170 */ u8 pad170[0x4];
    /* 0x174 */ s32 unk174;
    /* 0x178 */ MKHeap* unk178;
    /* 0x17c */ void* unk17C;
    /* 0x180 */ s32 unk180;
    /* 0x184 */ s32 unk184;
    /* 0x188 */ s32 unk188;
    /* 0x18c */ s32 unk18C;
    /* 0x190 */ s32 unk190;
    /* 0x194 */ s32 unk194;
    /* 0x198 */ f32 unk198;
    /* 0x19c */ f32 unk19C;
    /* 0x1a0 */ f32 unk1A0;
    /* 0x1a4 */ f32 unk1A4;
    /* 0x1a8 */ s32 unk1A8;
};

class AssaultCannon_cpp {
public:
    void __sinit(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#include <m2c_macros.h>

#if 0 // DRAFT: undefined identifier 'unkC8'
inline AssaultCannon::~AssaultCannon() {
    this->unkC8 = &__vt.unk48;
    if ((&this->unk294 != NULL) && (&this->unk294 != NULL)) {
        KDSound_Stop((int *) &this->unk294);
    }
    if ((&this->unk26C != NULL) && (&this->unk26C != NULL)) {
        KDSound_Stop((int *) &this->unk26C);
    }
}
#endif

inline f32 AssaultCannon::GetTimeLastHit() {
    return 0.0f;
}

inline f32 AssaultCannon::GetCollisionHeight() {
    return 200.0f;
}

inline f32 AssaultCannon::GetCollisionRadius() {
    return 200.0f;
}

inline void AssaultCannon::GetVel() {
    M2C_FIELD(this, f64 *, 0) = (f64) M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), f64 *, 0x358);
    M2C_FIELD(this, f64 *, 8) = (f64) M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), f64 *, 0x360);
}

inline s32 AssaultCannon::GetMoveToPoint(const MKVector3 &arg0, MKVector3 *arg1) {
    f64 sp10;
    f64 sp8;
    f64 temp_f0_97;
    f64 temp_f1_96;
    void *temp_r4_94;

    temp_r4_94 = this->unk8;
    temp_f1_96 = M2C_FIELD(temp_r4_94, f64 *, 0x30);
    temp_f0_97 = M2C_FIELD(temp_r4_94, f64 *, 0x38);
    sp8 = temp_f1_96;
    M2C_FIELD(arg1, f64 *, 0) = temp_f1_96;
    sp10 = temp_f0_97;
    M2C_FIELD(arg1, f64 *, 8) = temp_f0_97;
    return 1;
}

inline s32 AssaultCannon::IsEnemy() {
    return ((u32) M2C_FIELD(this->unk0, u32 *, 0xC) >> 3U) & 1;
}

inline s32 AssaultCannon::IsFriend() {
    return ((u32) M2C_FIELD(this->unk0, u32 *, 0xC) >> 2U) & 1;
}

inline s32 AssaultCannon::IsHero() {
    return 0;
}

inline s32 AssaultCannon::GetEnemy() {
    return 0;
}

inline void AssaultCannon::GetProp() {

}

#if 0 // DRAFT: undefined identifier 'unkC8'
inline AssaultCannon::AssaultCannon() {
    this->unkC8 = &__vt + 0x48;
    this->unk218 = -1;
    this->unk21C = -1;
    this->unk220 = 0;
    this->unk224 = 0;
    this->unk26C = 0;
    this->unk294 = 0;
}
#endif

inline AssaultCannonDescriptor::AssaultCannonDescriptor() {
}

#endif  // SPYRO_SOURCE_ASSAULTCANNON_H
