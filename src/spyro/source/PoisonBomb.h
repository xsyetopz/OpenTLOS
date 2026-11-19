#ifndef SPYRO_SOURCE_POISONBOMB_H
#define SPYRO_SOURCE_POISONBOMB_H

#include <dolphin/types.h>
#include "spyro/source/Projectile.h"

class MKCollisionInfo;
class MKCollisionResult;
class MKMaterial;
class MKMessage;
class MKModel;
class MKProp;
class MKVector3;
class PoisonBomb;
class PoisonBombDescriptor;
class Projectile;
class ProjectileDescriptor;

class PoisonBomb : public Projectile {  // base: base ctor call
public:
    virtual ~PoisonBomb(void);
    virtual void Init(void);
    virtual void Deinit(void);
    virtual void Reset(void);
    virtual void Update(void);
    virtual void Draw(void);
    virtual void Message(MKMessage *);
    virtual void Disable(void);
    virtual void Activate(void);
    virtual void Deactivate(void);
    virtual void FireAtTarget(const MKVector3 &, const MKVector3 &, float, MKProp *, int, int);
    virtual void Collided(MKCollisionResult &);
    virtual void SetExplodeOnContact(bool);
    virtual void SetExplodeNearHero(bool, float);
    virtual void SetExplodeTimer(float);
    PoisonBomb(void);
    void EmitPoison(void);
    void EmitPoisonTrail(void);
    void PlatformDetach(void);
    void PlatformAttach(MKProp *, MKCollisionInfo *);
    void SetInitialState(void);
    PoisonBomb * CreateInstance(void);
    /* 0x150 */ u8 unk150;
    /* 0x151 */ u8 pad151[0x7];
    /* 0x158 */ void* unk158;
    /* 0x15c */ void* unk15C;
    /* 0x160 */ f32 unk160;
    /* 0x164 */ f32 unk164;
    /* 0x168 */ f32 unk168;
    /* 0x16c */ f32 unk16C;
    /* 0x170 */ s32 unk170;
    /* 0x174 */ u8 unk174;
    /* 0x175 */ u8 pad175[0x3];
    /* 0x178 */ MKProp* unk178;
    /* 0x17c */ f32 unk17C;
    /* 0x180 */ s32 unk180;
    /* 0x184 */ f32 unk184;
    /* 0x188 */ f32 unk188;
    /* 0x18c */ f32 unk18C;
    /* 0x190 */ s32 unk190;
    /* 0x194 */ u8 pad194[0x24];
    /* 0x1b8 */ s32 unk1B8;
    /* 0x1bc */ f32 unk1BC;
    /* 0x1c0 */ u8 unk1C0;
    /* 0x1c1 */ u8 pad1C1[0x3];
    /* 0x1c4 */ MKModel* unk1C4;
    /* 0x1c8 */ f32 unk1C8;
    /* 0x1cc */ MKMaterial* unk1CC;
    /* 0x1d0 */ f32 unk1D0;
};

class PoisonBombDescriptor : public ProjectileDescriptor {  // base: base ctor call
public:
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    PoisonBombDescriptor(void);
    /* 0x0f0 */ s32 unkF0;
    /* 0x0f4 */ s32 unkF4;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#include <m2c_macros.h>

#if 0 // DRAFT: undefined identifier 'unk154'
inline PoisonBomb::PoisonBomb() {
    u8 *temp_r0_22553;

    temp_r0_22553 = &this->unk150;
    M2C_FIELD(this, s32 *, 0x150) = 0;
    this->unk154 = 0;
    this->unk158 = temp_r0_22553;
    this->unk15C = temp_r0_22553;
    this->unk190 = 0;
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier 'KDSound_Stop'
inline PoisonBomb::~PoisonBomb() {
    u8 *temp_r4_33;
    void *temp_r0_30;

    if (this != NULL) {
        if ((&this->unk190 != NULL) && (&this->unk190 != NULL)) {
            KDSound_Stop(&this->unk190);
        }
        if (&this->unk150 != NULL) {
            temp_r0_30 = this->unk158;
            if (temp_r0_30 != NULL) {
                temp_r4_33 = &this->unk150;
                if (temp_r0_30 != temp_r4_33) {
                    M2C_FIELD(this->unk15C, void **, 8) = temp_r0_30;
                    M2C_FIELD(this->unk158, void **, 0xC) = (void *) this->unk15C;
                    this->unk15C = temp_r4_33;
                    this->unk158 = temp_r4_33;
                }
            }
        }
    }
}
#endif

inline void PoisonBomb::SetExplodeTimer(float arg0) {

}

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline PoisonBombDescriptor::PoisonBombDescriptor() {
    return this;
}
#endif

#endif  // SPYRO_SOURCE_POISONBOMB_H
