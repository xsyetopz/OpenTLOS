#ifndef SPYRO_SOURCE_BALL_H
#define SPYRO_SOURCE_BALL_H

#include <dolphin/types.h>
#include "spyro/source/GameProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/Shadow.h"

class Ball;
class BallDescriptor;
class Ball_cpp;
class Catapult;
class GameProp;
class KDPropExDescriptor;
class MKCollisionInfo;
class MKIniLine;
class MKMessage;
class MKProp;
class MKVector3;
class Matrix;
class Shadow;
class SnowballTree;

class Ball : public GameProp {  // base: vtable prefix
public:
    class State;
    virtual ~Ball(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Reset(void);
    virtual void Update(void);
    virtual void Message(MKMessage *);
    virtual void pure_slot16() = 0;  // name unknown: no descendant fills this slot
    virtual void pure_slot17() = 0;  // name unknown: no descendant fills this slot
    virtual void GetProp(void);
    virtual s32 GetEnemy(void);
    virtual s32 IsHero(void);
    virtual s32 IsFriend(void);
    virtual s32 IsEnemy(void);
    virtual s32 IsShatterable(void);
    virtual s32 IsDead(void);
    virtual s32 GetMoveToPoint(const MKVector3 &, MKVector3 *);
    virtual s32 GetLookToPoint(const MKVector3 &, MKVector3 *);
    virtual s32 GetAimPoint(const MKVector3 &, MKVector3 *);
    virtual void GetVel(void);
    virtual MKCollisionInfo * GetCollisionInfo(void);
    virtual f32 GetCollisionRadius(void);
    virtual f32 GetCollisionHeight(void);
    virtual s32 IsAttacking(void);
    virtual f32 GetTimeLastHit(void);
    Ball(void);
    void BridgeHit(float, float);
    void PlatformAttach(MKProp *, MKCollisionInfo *);
    void PlatformDetach(void);
    void PlatformUpdate(void);
    void SetParentTree(SnowballTree *, int, MKVector3 &, float);
    void SetGroup(int);
    void FindClosestGroup(void);
    u8 MeleeHit(MKProp *, float, bool &);
    void SmashHit(MKProp *);
    void Smash(void);
    void SetState(Ball::State);
    void Fire(MKVector3 &);
    void SetPhysicsOn(bool);
    void CheckForSiegeTowers(void);
    void CheckForRamps(void);
    void CheckForCatapults(void);
    void CheckForHero(void);
    void UpdateShadow(void);
    void UpdateOrientation(void);
    void UpdateMeltingGrowing(void);
    void PushOutOfThings(void);
    void UpdatePhysics(void);
    void SetWorldMatrix(const Matrix *);
    void DropFromTree(void);
    void PutInTree(void);
    /* 0x0c4 */ u8 padC4[0x4];
    /* 0x0c8 */ s32* unkC8;
    /* 0x0cc */ u8 padCC[0x4];
    /* 0x0d0 */ f64 unkD0;
    /* 0x0d8 */ f64 unkD8;
    /* 0x0e0 */ f64 unkE0;
    /* 0x0e8 */ f32 unkE8;
    /* 0x0ec */ u8 padEC[0x4];
    /* 0x0f0 */ f64 unkF0;
    /* 0x0f8 */ f32 unkF8;
    /* 0x0fc */ u8 padFC[0x4];
    /* 0x100 */ f64 unk100;
    /* 0x108 */ f32 unk108;
    /* 0x10c */ u8 pad10C[0x4];
    /* 0x110 */ f64 unk110;
    /* 0x118 */ f64 unk118;
    /* 0x120 */ f32 unk120;
    /* 0x124 */ f32 unk124;
    /* 0x128 */ f32 unk128;
    /* 0x12c */ u8 pad12C[0x4];
    /* 0x130 */ f64 unk130;
    /* 0x138 */ f32 unk138;
    /* 0x13c */ u8 pad13C[0x4];
    /* 0x140 */ f64 unk140;
    /* 0x148 */ f64 unk148;
    /* 0x150 */ f64 unk150;
    /* 0x158 */ f64 unk158;
    /* 0x160 */ f64 unk160;
    /* 0x168 */ f64 unk168;
    /* 0x170 */ f64 unk170;
    /* 0x178 */ f64 unk178;
    /* 0x180 */ f32 unk180;
    /* 0x184 */ f32 unk184;
    /* 0x188 */ s32 unk188;
    /* 0x18c */ s32 unk18C;
    /* 0x190 */ f32 unk190;
    /* 0x194 */ u32 unk194;
    /* 0x198 */ void* unk198;
    /* 0x19c */ s32 unk19C;
    /* 0x1a0 */ u8 unk1A0;
    /* 0x1a1 */ u8 pad1A1[0x7];
    /* 0x1a8 */ Shadow unk1A8;
    /* 0x1d5 */ u8 pad1D5[0x3];
    /* 0x1d8 */ s32 unk1D8;
    /* 0x1dc */ u8 pad1DC[0x24];
    /* 0x200 */ s32 unk200;
    /* 0x204 */ u8 pad204[0x24];
    /* 0x228 */ Catapult* unk228;
    /* 0x22c */ SnowballTree* unk22C;
    /* 0x230 */ void* unk230;
    /* 0x234 */ MKProp* unk234;
    /* 0x238 */ u8 pad238[0x28];
    /* 0x260 */ Ball* unk260;
    /* 0x264 */ void* unk264;
    /* 0x268 */ u8 pad268[0x8];
    /* 0x270 */ s32 unk270;
    /* 0x274 */ f32 unk274;
    /* 0x278 */ f32 unk278;
    /* 0x27c */ f32 unk27C;
    /* 0x280 */ f32 unk280;
    /* 0x284 */ f32 unk284;
    /* 0x288 */ f32 unk288;
    /* 0x28c */ f32 unk28C;
    /* 0x290 */ s32 unk290;
    /* 0x294 */ s32 unk294;
    /* 0x298 */ s32 unk298;
    /* 0x29c */ f32 unk29C;
    /* 0x2a0 */ f32 unk2A0;
    /* 0x2a4 */ u32 unk2A4;
    /* 0x2a8 */ s32 unk2A8;
    /* 0x2ac */ u8 unk2AC;
};

class BallDescriptor : public KDPropExDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    BallDescriptor(void);
    /* 0x0c0 */ u8 padC0[0x24];
    /* 0x0e4 */ s32 unkE4;
    /* 0x0e8 */ s32 unkE8;
    /* 0x0ec */ s32 unkEC;
    /* 0x0f0 */ s32 unkF0;
    /* 0x0f4 */ s32 unkF4;
    /* 0x0f8 */ s32 unkF8;
    /* 0x0fc */ s32 unkFC;
    /* 0x100 */ s32 unk100;
    /* 0x104 */ s32 unk104;
    /* 0x108 */ s32 unk108;
    /* 0x10c */ f32 unk10C;
    /* 0x110 */ f32 unk110;
    /* 0x114 */ f32 unk114;
    /* 0x118 */ f32 unk118;
    /* 0x11c */ f32 unk11C;
    /* 0x120 */ s32 unk120;
    /* 0x124 */ u32 unk124;
};

class Ball_cpp {
public:
    void __sinit(void);
};

void Ball_InitModule(void);
// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#include <m2c_macros.h>

#if 0 // DRAFT: undefined identifier '__vt'
inline Ball::~Ball() {
    M2C_UNK *temp_r4_28;
    MKProp **temp_r0_41;
    MKProp **temp_r4_44;
    void *temp_r0_25;

    if (this != NULL) {
        this->unkC8 = &__vt.unk48;
        if (&this->unk248 != NULL) {
            temp_r0_25 = this->unk264;
            if (temp_r0_25 != NULL) {
                temp_r4_28 = &this->unk248;
                if (temp_r0_25 != temp_r4_28) {
                    M2C_FIELD(this->unk26C, void **, 0x20) = temp_r0_25;
                    M2C_FIELD(this->unk264, M2C_UNK **, 0x24) = (M2C_UNK *) this->unk26C;
                    this->unk26C = temp_r4_28;
                    this->unk264 = temp_r4_28;
                }
            }
        }
        if (&this->unk234 != NULL) {
            temp_r0_41 = this->unk240;
            if (temp_r0_41 != NULL) {
                temp_r4_44 = &this->unk234;
                if (temp_r0_41 != temp_r4_44) {
                    M2C_FIELD(this->unk244, MKProp ***, 8) = temp_r0_41;
                    M2C_FIELD(this->unk240, MKProp ***, 0xC) = (MKProp **) this->unk244;
                    this->unk244 = temp_r4_44;
                    this->unk240 = temp_r4_44;
                }
            }
        }
        if ((&this->unk200 != NULL) && (&this->unk200 != NULL)) {
            KDSound_Stop(&this->unk200);
        }
        if ((&this->unk1D8 != NULL) && (&this->unk1D8 != NULL)) {
            KDSound_Stop(&this->unk1D8);
        }
    }
}
#endif

inline s32 Ball::IsAttacking() {
    return 0;
}

inline f32 Ball::GetTimeLastHit() {
    return 0.0f;
}

inline f32 Ball::GetCollisionHeight() {
    return 200.0f;
}

inline f32 Ball::GetCollisionRadius() {
    return 100.0f;
}

inline MKCollisionInfo *Ball::GetCollisionInfo() {
    return &this->unk70;
}

#if 0 // DRAFT: undefined identifier 'zero'
inline void Ball::GetVel() {
    M2C_FIELD(this, f64 *, 0) = (f64) M2C_FIELD(&zero, f64 *, 0);
    M2C_FIELD(this, f64 *, 8) = (f64) M2C_FIELD(&zero, f64 *, 8);
}
#endif

inline s32 Ball::GetAimPoint(const MKVector3 &arg0, MKVector3 *arg1) {
    return 0;
}

inline s32 Ball::GetLookToPoint(const MKVector3 &arg0, MKVector3 *arg1) {
    return 0;
}

inline s32 Ball::GetMoveToPoint(const MKVector3 &arg0, MKVector3 *arg1) {
    return 0;
}

inline s32 Ball::IsDead() {
    return 0;
}

inline s32 Ball::IsShatterable() {
    return 0;
}

inline s32 Ball::IsEnemy() {
    return 0;
}

inline s32 Ball::IsFriend() {
    return 0;
}

inline s32 Ball::IsHero() {
    return 0;
}

inline s32 Ball::GetEnemy() {
    return 0;
}

inline void Ball::GetProp() {

}

#if 0 // DRAFT: undefined identifier '__vt'
inline Ball::Ball() {
    M2C_UNK *temp_r0_20650;
    MKProp **temp_r4_20649;

    this->unkC8 = &__vt.unk0;
    this->unkCC = -1;
    temp_r4_20649 = &this->unk234;
    temp_r0_20650 = &this->unk248;
    this->unkC8 = &__vt + 0x48;
    this->unk1D8 = 0;
    this->unk200 = 0;
    this->unk234 = NULL;
    this->unk23C = 0;
    this->unk240 = temp_r4_20649;
    this->unk244 = temp_r4_20649;
    this->unk260 = 0;
    this->unk260 = NULL;
    this->unk264 = temp_r0_20650;
    this->unk26C = temp_r0_20650;
    this->unk25C = 0;
    this->unk258 = 0.0f;
    return this;
}
#endif

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline BallDescriptor::BallDescriptor() {
    this->unk124 = 0;
    return this;
}
#endif

#endif  // SPYRO_SOURCE_BALL_H
