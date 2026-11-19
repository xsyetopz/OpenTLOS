#ifndef SPYRO_SOURCE_SHATTERABLEBOAT_H
#define SPYRO_SOURCE_SHATTERABLEBOAT_H

#include <dolphin/types.h>
#include "spyro/source/Shatterable.h"
#include "spyro/source/ShatterablePlatform.h"

class MKIniLine;
class MKMessage;
class MKVector3;
class ShatterableBoat;
class ShatterableBoatDescriptor;
class ShatterableDescriptor;
class ShatterablePlatform;

class ShatterableBoat : public ShatterablePlatform {  // base: vtable prefix
public:
    virtual ~ShatterableBoat(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Update(void);
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
    virtual void UpdateMove(void);
    ShatterableBoat(void);
    void SetDefaults(void);
    void EmitWaterSpray(void);
    void InitOars(void);
};

class ShatterableBoatDescriptor : public ShatterableDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    ShatterableBoatDescriptor(void);
    /* 0x16c */ s32 unk16C;
    /* 0x170 */ s32 unk170;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#include <m2c_macros.h>

#if 0 // DRAFT: undefined identifier 'unkC8'
inline ShatterableBoat::ShatterableBoat() {
    this->unkC8 = &__vt + 0x48;
    this->unk218 = 0;
    this->unk21C = 0;
    M2C_FIELD(this, f32 *, 0x220) = 0.0f;
    M2C_FIELD(this, s32 *, 0x224) = 0;
    this->unk320 = 0.0f;
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier 'unkC8'
inline ShatterableBoat::~ShatterableBoat() {
    this->unkC8 = &__vt.unk48;
    if ((&this->unk320 != NULL) && (&this->unk320 != NULL)) {
        KDSound_Stop((s32 *) &this->unk320);
    }
}
#endif

inline f32 ShatterableBoat::GetTimeLastHit() {
    return 0.0f;
}

inline f32 ShatterableBoat::GetCollisionHeight() {
    return 300.0f;
}

inline f32 ShatterableBoat::GetCollisionRadius() {
    return 100.0f;
}

inline void ShatterableBoat::GetVel() {
    M2C_FIELD(this, f64 *, 0) = (f64) M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), f64 *, 0x318);
    M2C_FIELD(this, f64 *, 8) = (f64) M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), f64 *, 0x320);
}

inline s32 ShatterableBoat::GetMoveToPoint(const MKVector3 &arg0, MKVector3 *arg1) {
    f64 sp10;
    f64 sp8;
    f64 temp_f0_84;
    f64 temp_f1_83;
    void *temp_r4_81;

    temp_r4_81 = this->unk8;
    temp_f1_83 = M2C_FIELD(temp_r4_81, f64 *, 0x30);
    temp_f0_84 = M2C_FIELD(temp_r4_81, f64 *, 0x38);
    sp8 = temp_f1_83;
    M2C_FIELD(arg1, f64 *, 0) = temp_f1_83;
    sp10 = temp_f0_84;
    M2C_FIELD(arg1, f64 *, 8) = temp_f0_84;
    return 1;
}

inline s32 ShatterableBoat::IsEnemy() {
    return 1;
}

inline s32 ShatterableBoat::IsFriend() {
    return 0;
}

inline s32 ShatterableBoat::IsHero() {
    return 0;
}

inline s32 ShatterableBoat::GetEnemy() {
    return 0;
}

inline void ShatterableBoat::GetProp() {

}

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline ShatterableBoatDescriptor::ShatterableBoatDescriptor() {
    return this;
}
#endif

#endif  // SPYRO_SOURCE_SHATTERABLEBOAT_H
