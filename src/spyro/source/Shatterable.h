#ifndef SPYRO_SOURCE_SHATTERABLE_H
#define SPYRO_SOURCE_SHATTERABLE_H

#include <dolphin/types.h>
#include "spyro/source/EventMessage.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/GlowingPropManager.h"
#include "spyro/source/Shadow.h"
#include "unplaced_enums.h"

class Attachment;
class DataMap;
class EventMessage;
class GameProp;
class GamePropDescriptor;
class GlowingProp;
class KDSoundPlayer;
class MKCollisionInfo;
class MKIniLine;
class MKMessage;
class MKProp;
class MKSceneManager;
class MKVector3;
class MKVector4;
class Shadow;
class Shatterable;
class ShatterableDescriptor;

class Shatterable : public GameProp {  // base: base ctor call
public:
    virtual ~Shatterable(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Reset(void);
    virtual void Update(void);
    virtual void Draw(void);
    virtual void Message(MKMessage *);
    virtual void pure_slot16() = 0;  // name unknown: no descendant fills this slot
    virtual void pure_slot17() = 0;  // name unknown: no descendant fills this slot
    virtual void Shatter(bool, MKVector3 *, int, MKVector3 *, bool, bool);
    virtual void PostShatter(void);
    virtual void DestroyShatterable(void);
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
    virtual void GetCollisionInfo(void);
    virtual f32 GetCollisionRadius(void);
    virtual f32 GetCollisionHeight(void);
    virtual s32 IsAttacking(void);
    virtual f32 GetTimeLastHit(void);
    Shatterable(void);
    void ResetPercentageShattered(void);
    void SpawnGems(int);
    void TriggerShatterFX(void);
    void SetSmashPropState(SmashPropState);
    void PlatformDetach(void);
    void PlatformAttach(MKProp *, MKCollisionInfo *);
    void SetStateAnim(int);
    void EnableCollision(void);
    void DisableCollision(void);
    u8 AbleToRespawn(void);
    /* 0x0c8 */ u8 padC8[0x8];
    /* 0x0d0 */ Shadow unkD0;
    /* 0x100 */ KDSoundPlayer* unk100;
    /* 0x104 */ u8 pad104[0x14];
    /* 0x118 */ GlowingProp unk118;
    /* 0x130 */ f64 unk130;
    /* 0x138 */ f64 unk138;
    /* 0x140 */ u8 pad140[0x10];
    /* 0x150 */ u8 unk150;
    /* 0x151 */ u8 pad151[0x3];
    /* 0x154 */ Attachment* unk154;
    /* 0x158 */ void* unk158;
    /* 0x15c */ EventMessage unk15C;
    /* 0x160 */ EventMessage unk160;
    /* 0x164 */ EventMessage unk164;
    /* 0x168 */ void* unk168;
    /* 0x16c */ s32 unk16C;
    /* 0x170 */ MKProp* unk170;
    /* 0x174 */ MKSceneManager* unk174;
    /* 0x178 */ f32 unk178;
    /* 0x17c */ s32 unk17C;
    /* 0x180 */ s32 unk180;
    /* 0x184 */ MKSceneManager* unk184;
    /* 0x188 */ f32 unk188;
    /* 0x18c */ f32 unk18C;
    /* 0x190 */ s32 unk190;
    /* 0x194 */ s32 unk194;
    /* 0x198 */ f32 unk198;
    /* 0x19c */ u8 unk19C;
    /* 0x19d */ u8 unk19D;
    /* 0x19e */ u8 unk19E;
    /* 0x19f */ u8 unk19F;
    /* 0x1a0 */ u8 unk1A0;
    /* 0x1a1 */ u8 unk1A1;
    /* 0x1a2 */ u8 unk1A2;
};

class ShatterableDescriptor : public GamePropDescriptor {  // base: base ctor call
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    ShatterableDescriptor(void);
    void EmitHitEffects(const MKVector3 &, const MKVector3 &, const MKVector4 &, MKProp *, int);
    /* 0x0e8 */ s8* unkE8;
    /* 0x0ec */ s8* unkEC;
    /* 0x0f0 */ f32 unkF0;
    /* 0x0f4 */ s32 unkF4;
    /* 0x0f8 */ u8 unkF8;
    /* 0x0f9 */ u8 padF9[0x3];
    /* 0x0fc */ s32 unkFC;
    /* 0x100 */ s32 unk100;
    /* 0x104 */ s32 unk104;
    /* 0x108 */ u8 unk108;
    /* 0x109 */ u8 pad109[0x3];
    /* 0x10c */ s32 unk10C;
    /* 0x110 */ s8* unk110;
    /* 0x114 */ u8 unk114;
    /* 0x115 */ u8 unk115;
    /* 0x116 */ u8 pad116[0x2];
    /* 0x118 */ u8 unk118;
    /* 0x119 */ u8 pad119[0x3];
    /* 0x11c */ void* unk11C;
    /* 0x120 */ u8 pad120[0xc];
    /* 0x12c */ s32 unk12C;
    /* 0x130 */ f32 unk130;
    /* 0x134 */ f32 unk134;
    /* 0x138 */ f32 unk138;
    /* 0x13c */ f32 unk13C;
    /* 0x140 */ f32 unk140;
    /* 0x144 */ f32 unk144;
    /* 0x148 */ f32 unk148;
    /* 0x14c */ f32 unk14C;
    /* 0x150 */ f32 unk150;
    /* 0x154 */ f32 unk154;
    /* 0x158 */ s32 unk158;
    /* 0x15c */ s32 unk15C;
    /* 0x160 */ s32 unk160;
    /* 0x164 */ u8 unk164;
    /* 0x165 */ u8 unk165;
    /* 0x166 */ u8 unk166;
    /* 0x167 */ u8 pad167[0x1];
    /* 0x168 */ s32 unk168;
};

extern DataMap ShatterableHitFXDataMap;
// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#include <m2c_macros.h>

#if 0 // DRAFT: undefined identifier 'vtableC8'
inline Shatterable::~Shatterable() {
    Attachment *temp_r0_18991;
    M2C_UNK *temp_r0_19007;
    M2C_UNK *temp_r4_19010;
    u8 *temp_r4_18994;

    if (this != NULL) {
        this->vtableC8 = &__vt + 0x48;
        if (&this->unk164 != NULL) {
            this->unk164.Deinit();
        }
        if (&this->unk160 != NULL) {
            this->unk160.Deinit();
        }
        if (&this->unk15C != NULL) {
            this->unk15C.Deinit();
        }
        if (&this->unk150 != NULL) {
            temp_r0_18991 = this->unk154;
            if (temp_r0_18991 != NULL) {
                temp_r4_18994 = &this->unk150;
                if (temp_r0_18991 != temp_r4_18994) {
                    M2C_FIELD(this->unk158, Attachment **, 4) = temp_r0_18991;
                    this->unk154->unk8 = (Attachment *) this->unk158;
                    this->unk158 = temp_r4_18994;
                    this->unk154 = (Attachment *) temp_r4_18994;
                }
            }
        }
        if (&this->unk140 != NULL) {
            temp_r0_19007 = this->unk148;
            if (temp_r0_19007 != NULL) {
                temp_r4_19010 = &this->unk140;
                if (temp_r0_19007 != temp_r4_19010) {
                    M2C_FIELD(this->unk14C, M2C_UNK **, 8) = temp_r0_19007;
                    M2C_FIELD(this->unk148, M2C_UNK **, 0xC) = (M2C_UNK *) this->unk14C;
                    this->unk14C = temp_r4_19010;
                    this->unk148 = temp_r4_19010;
                }
            }
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'vtableC8'
inline Shatterable::Shatterable() {
    M2C_UNK *temp_r4_19055;
    u8 *temp_r0_19056;

    this->vtableC8 = &__vt;
    this->unkCC = -1;
    temp_r4_19055 = &this->unk140;
    temp_r0_19056 = &this->unk150;
    this->vtableC8 = &__vt + 0x48;
    M2C_FIELD(this, s32 *, 0x140) = 0;
    this->unk144 = 0;
    this->unk148 = temp_r4_19055;
    this->unk14C = temp_r4_19055;
    M2C_FIELD(this, s32 *, 0x150) = 0;
    this->unk154 = (Attachment *) temp_r0_19056;
    this->unk158 = temp_r0_19056;
    this->unk15C.unk0 = 0;
    this->unk15C.Init();
    this->unk160.unk0 = 0;
    this->unk160.Init();
    this->unk164.unk0 = 0;
    this->unk164.Init();
    return this;
}
#endif

inline s32 Shatterable::IsAttacking() {
    return 0;
}

inline f32 Shatterable::GetTimeLastHit() {
    return 0.0f;
}

inline f32 Shatterable::GetCollisionHeight() {
    return 200.0f;
}

inline f32 Shatterable::GetCollisionRadius() {
    return 100.0f;
}

inline void Shatterable::GetCollisionInfo() {

}

inline void Shatterable::GetVel() {
    M2C_FIELD(this, f64 *, 0) = (f64) M2C_FIELD(&MKVector3::zero, f64 *, 0);
    M2C_FIELD(this, f64 *, 8) = (f64) M2C_FIELD(&MKVector3::zero, f64 *, 8);
}

inline s32 Shatterable::GetLookToPoint(const MKVector3 &arg0, MKVector3 *arg1) {
    return 0;
}

inline s32 Shatterable::GetMoveToPoint(const MKVector3 &arg0, MKVector3 *arg1) {
    return 0;
}

inline s32 Shatterable::IsDead() {
    return this->unk17C == 3;
}

inline s32 Shatterable::IsShatterable() {
    return 1;
}

inline s32 Shatterable::IsEnemy() {
    return 0;
}

inline s32 Shatterable::IsFriend() {
    return 0;
}

inline s32 Shatterable::IsHero() {
    return 0;
}

inline s32 Shatterable::GetEnemy() {
    return 0;
}

inline void Shatterable::GetProp() {

}

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline ShatterableDescriptor::ShatterableDescriptor() {
    return this;
}
#endif

#endif  // SPYRO_SOURCE_SHATTERABLE_H
