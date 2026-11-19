#ifndef SPYRO_SOURCE_SHATTERABLEBOAT_H
#define SPYRO_SOURCE_SHATTERABLEBOAT_H

#include <dolphin/types.h>
#include "spyro/source/ShatterablePlatform.h"
#include "spyro/source/ShatterablePlatformDescriptor.h"

class MKAnim;
class MKAnimScript;
class MKIniLine;
class MKMessage;
class MKModel;
class MKProp;
class MKVector3;
class ShatterableBoat;
class ShatterableBoatDescriptor;
class ShatterablePlatform;
class ShatterablePlatformDescriptor;
class WaterSurfaceFX;

class ShatterableBoat : public ShatterablePlatform {  // base: base ctor call
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
    /* 0x218 */ s32 unk218;
    /* 0x21c */ u8 pad21C[0x4];
    /* 0x220 */ f32 unk220;
    /* 0x224 */ s32 unk224;
    /* 0x228 */ u8 pad228[0x4];
    /* 0x22c */ f32 unk22C;
    /* 0x230 */ f32 unk230;
    /* 0x234 */ s32 unk234;
    /* 0x238 */ s32 unk238;
    /* 0x23c */ f32 unk23C;
    /* 0x240 */ MKProp* unk240;
    /* 0x244 */ WaterSurfaceFX* unk244;
    /* 0x248 */ f32 unk248;
    /* 0x24c */ MKAnimScript* unk24C;
    /* 0x250 */ MKAnim* unk250;
    /* 0x254 */ MKAnim* unk254;
    /* 0x258 */ MKAnimScript* unk258;
    /* 0x25c */ MKAnim* unk25C;
    /* 0x260 */ MKAnim* unk260;
    /* 0x264 */ u8 pad264[0xac];
    /* 0x310 */ MKModel* unk310;
    /* 0x314 */ f32 unk314;
    /* 0x318 */ f32 unk318;
    /* 0x31c */ f32 unk31C;
    /* 0x320 */ f32 unk320;
    /* 0x324 */ u8 pad324[0x4];
    /* 0x328 */ f64 unk328;
    /* 0x330 */ f64 unk330;
    /* 0x338 */ s32 unk338;
    /* 0x33c */ u8 pad33C[0x24];
    /* 0x360 */ s32 unk360;
    /* 0x364 */ s32 unk364;
};

class ShatterableBoatDescriptor : public ShatterablePlatformDescriptor {  // base: base ctor call
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    ShatterableBoatDescriptor(void);
    /* 0x170 */ s32 unk170;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#include <m2c_macros.h>

#if 0 // DRAFT: undefined identifier 'unkC8'
inline ShatterableBoat::ShatterableBoat() {
    this->unkC8 = &__vt + 0x48;
    this->unk218 = 0;
    this->unk21C = 0;
    this->unk220 = 0.0f;
    this->unk224 = 0;
    this->unk338 = 0;
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier 'unkC8'
inline ShatterableBoat::~ShatterableBoat() {
    this->unkC8 = &__vt.unk48;
    if ((&this->unk338 != NULL) && (&this->unk338 != NULL)) {
        KDSound_Stop((int *) &this->unk338);
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
