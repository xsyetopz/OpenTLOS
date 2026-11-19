#ifndef SPYRO_SOURCE_DYNAMITE_H
#define SPYRO_SOURCE_DYNAMITE_H

#include <dolphin/types.h>
#include "common/Source/MKCollision.h"
#include "common/Source/MKProp.h"
#include "spyro/source/Projectile.h"

class Dynamite;
class DynamiteDescriptor;
class MKCollisionInfo;
class MKCollisionResult;
class MKIniLine;
class MKMessage;
class MKProp;
class MKPropDescriptor;
class Projectile;

class Dynamite : public Projectile {  // base: vtable prefix
public:
    virtual ~Dynamite(void);
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Reset(void);
    virtual void Update(void);
    virtual void Message(MKMessage *);
    virtual void Disable(void);
    virtual void Activate(void);
    virtual void Deactivate(void);
    virtual void Collided(MKCollisionResult &);
    virtual void SetExplodeOnContact(bool);
    virtual void SetExplodeNearHero(bool, float);
    virtual void SetExplodeTimer(float);
    Dynamite(void);
    void PlatformDetach(void);
    void PlatformAttach(MKProp *, MKCollisionInfo *);
    void SetInitialState(void);
    Dynamite * CreateInstance(int);
    /* 0x14d */ u8 pad14D[0x3];
    /* 0x150 */ s32 unk150;
    /* 0x154 */ u8 pad154[0x10];
    /* 0x164 */ MKProp* unk164;
    /* 0x168 */ f32 unk168;
    /* 0x16c */ f32 unk16C;
    /* 0x170 */ f32 unk170;
    /* 0x174 */ f32 unk174;
    /* 0x178 */ f32 unk178;
    /* 0x17c */ f32 unk17C;
    /* 0x180 */ s32 unk180;
    /* 0x184 */ u8 unk184;
    /* 0x185 */ u8 unk185;
    /* 0x186 */ u8 pad186[0x2];
    /* 0x188 */ MKCollisionInfo unk188;
    /* 0x198 */ f64 unk198;
    /* 0x1a0 */ f64 unk1A0;
};

class DynamiteDescriptor : public MKPropDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    DynamiteDescriptor(void);
    /* 0x048 */ u8 pad48[0xa8];
    /* 0x0f0 */ s32 unkF0;
    /* 0x0f4 */ s32 unkF4;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#include <m2c_macros.h>

#if 0 // DRAFT: undefined identifier 'unk154'
inline Dynamite::Dynamite() {
    M2C_UNK *temp_r0_23670;

    temp_r0_23670 = &this->unk154;
    this->unk150 = 0;
    M2C_FIELD(this, s32 *, 0x154) = 0;
    this->unk158 = 0;
    this->unk15C = temp_r0_23670;
    this->unk160 = temp_r0_23670;
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk154'
inline Dynamite::~Dynamite() {
    M2C_UNK *temp_r0_23;
    M2C_UNK *temp_r4_26;

    if (this != NULL) {
        if (&this->unk154 != NULL) {
            temp_r0_23 = this->unk15C;
            if (temp_r0_23 != NULL) {
                temp_r4_26 = &this->unk154;
                if (temp_r0_23 != temp_r4_26) {
                    M2C_FIELD(this->unk160, M2C_UNK **, 8) = temp_r0_23;
                    M2C_FIELD(this->unk15C, M2C_UNK **, 0xC) = (M2C_UNK *) this->unk160;
                    this->unk160 = temp_r4_26;
                    this->unk15C = temp_r4_26;
                }
            }
        }
        if (&this->unk150 != NULL) {
            KDSound_Stop(&this->unk150);
        }
    }
}
#endif

inline void Dynamite::SetExplodeTimer(float arg0) {
    this->unk168 = arg0;
}

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline DynamiteDescriptor::DynamiteDescriptor() {
    return this;
}
#endif

#endif  // SPYRO_SOURCE_DYNAMITE_H
