#ifndef SPYRO_SOURCE_ICEBREATHFX_H
#define SPYRO_SOURCE_ICEBREATHFX_H

#include <dolphin/types.h>
#include "spyro/source/BaseBreathFX.h"
#include "spyro/source/GameMessages.h"

class BaseBreathFX;
class BreathHitMessage;
class FuryFXIce;
class FuryFXIce2;
class IceBreathFX;
class IceExplosion;
class LiquidFX;
class MKModel;
class MKProp;
class MKVector3;
class ManagedLight;
class Matrix;

class IceBreathFX : public BaseBreathFX {  // base: ctor/dtor vtable stores
public:
    virtual ~IceBreathFX(void);
    virtual void Init(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Update(void);
    virtual void Draw(void);
    IceBreathFX(void);
    void ResetFury(void);
    void DrawWallIceShards(void);
    void UpdateWallIceShards(void);
    void SpawnWallIceShard(const MKVector3 &, const MKVector3 &, float);
    u8 ShootIceShard(const MKVector3 &, const MKVector3 &, const MKVector3 &);
    u8 Trigger(MKProp *, const MKVector3 &, const MKVector3 &, const MKVector3 &, const float &, const int &);
    /* 0x0a4 */ u8 padA4[0x4];
    /* 0x0a8 */ Matrix** unkA8;
    /* 0x0ac */ f32 unkAC;
    /* 0x0b0 */ s32 unkB0;
    /* 0x0b4 */ MKModel* unkB4;
    /* 0x0b8 */ BreathHitMessage unkB8;
    /* 0x109 */ u8 pad109[0x7];
    /* 0x110 */ BreathHitMessage unk110;
    /* 0x161 */ u8 pad161[0x7];
    /* 0x168 */ ManagedLight* unk168;
    /* 0x16c */ f32 unk16C;
    /* 0x170 */ FuryFXIce* unk170;
    /* 0x174 */ FuryFXIce2* unk174;
    /* 0x178 */ IceExplosion* unk178;
    /* 0x17c */ Matrix** unk17C;
    /* 0x180 */ LiquidFX* unk180;
    /* 0x184 */ LiquidFX* unk184;
    /* 0x188 */ LiquidFX* unk188;
    /* 0x18c */ f32 unk18C;
    /* 0x190 */ u32 unk190;
    /* 0x194 */ f32 unk194;
    /* 0x198 */ f32 unk198;
    /* 0x19c */ u8 unk19C;
    /* 0x19d */ u8 pad19D[0x3];
    /* 0x1a0 */ f32 unk1A0;
    /* 0x1a4 */ f32 unk1A4;
    /* 0x1a8 */ f32 unk1A8;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: undefined identifier 'unk4'
inline IceBreathFX::IceBreathFX() {
    this->unkB8.unk4 = 0;
    this->unk110.unk0 = 0;
    return this;
}
#endif

inline IceBreathFX::~IceBreathFX() {
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

#endif  // SPYRO_SOURCE_ICEBREATHFX_H
