#ifndef SPYRO_SOURCE_EARTHBREATHFX_H
#define SPYRO_SOURCE_EARTHBREATHFX_H

#include <dolphin/types.h>
#include "common/Source/Matrix.h"
#include "spyro/source/BaseBreathFX.h"
#include "spyro/source/GameMessages.h"

class BaseBreathFX;
class BreathHitMessage;
class EarthBreathFX;
class FuryFXEarth;
class FuryFXEarth2;
class MKMaterial;
class MKModel;
class MKProp;
class MKPropDescriptor;
class MKVector3;
class ManagedLight;
class Matrix;

class EarthBreathFX : public BaseBreathFX {  // base: ctor/dtor vtable stores
public:
    virtual ~EarthBreathFX(void);
    virtual void Init(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Update(void);
    virtual void Draw(void);
    EarthBreathFX(void);
    u8 ShootEarthBomb(const MKVector3 &, const MKVector3 &, const MKVector3 &, bool);
    void ResetFury(void);
    void DrawShotgunMuzzelFlash(void);
    s32 ShootShotgun(const MKVector3 &, const MKVector3 &, const MKVector3 &);
    s32 Trigger(MKProp *, const MKVector3 &, const MKVector3 &, const MKVector3 &, int, bool);
    void DrawSeedBullets(void);
    void UpdateSeedBullets(void);
    void * SpawnSeedBullet(const MKVector3 &, const MKVector3 &, const MKVector3 &, float, bool);
    /* 0x0a8 */ f32 unkA8;
    /* 0x0ac */ f32 unkAC;
    /* 0x0b0 */ s8 unkB0;
    /* 0x0b1 */ u8 padB1[0x3];
    /* 0x0b4 */ MKMaterial* unkB4;
    /* 0x0b8 */ ManagedLight* unkB8;
    /* 0x0bc */ f32 unkBC;
    /* 0x0c0 */ FuryFXEarth* unkC0;
    /* 0x0c4 */ FuryFXEarth2* unkC4;
    /* 0x0c8 */ MKVector3** unkC8;
    /* 0x0cc */ u8 padCC[0x4];
    /* 0x0d0 */ BreathHitMessage unkD0;
    /* 0x124 */ u8 pad124[0x4];
    /* 0x128 */ MKModel* unk128;
    /* 0x12c */ f32 unk12C;
    /* 0x130 */ f64 unk130;
    /* 0x138 */ f64 unk138;
    /* 0x140 */ MKModel* unk140;
    /* 0x144 */ u8 pad144[0x8];
    /* 0x14c */ u8 unk14C;
    /* 0x14d */ u8 pad14D[0x3];
    /* 0x150 */ Matrix unk150;
    /* 0x190 */ MKPropDescriptor* unk190;
    /* 0x194 */ f32 unk194;
    /* 0x198 */ u8 unk198;
    /* 0x199 */ u8 pad199[0x3];
    /* 0x19c */ f32 unk19C;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline EarthBreathFX::EarthBreathFX() {
    this->unkD0.unk4 = 0;
    return this;
}
#endif

inline EarthBreathFX::~EarthBreathFX() {
    s32 temp_cr0_eq_15;

    temp_cr0_eq_15 = this == NULL;
    if (temp_cr0_eq_15 == 0) {
        if (temp_cr0_eq_15 == 0) {
            if (temp_cr0_eq_15 == 0) {
                if (temp_cr0_eq_15 == 0) {
                }
            }
        }
    }
}

#endif  // SPYRO_SOURCE_EARTHBREATHFX_H
