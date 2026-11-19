#ifndef SPYRO_SOURCE_DAMAGESHIELDEFFECT_H
#define SPYRO_SOURCE_DAMAGESHIELDEFFECT_H

#include <dolphin/types.h>
#include "spyro/source/KDProp.h"

class DamageShieldEffect;
class KDProp;
class MKMaterial;
class MKVector3;
class Texture;

class DamageShieldEffect : public KDProp {  // base: ctor/dtor vtable stores
public:
    virtual ~DamageShieldEffect(void);
    virtual void Init(void);
    virtual void Deinit(void);
    virtual void Update(void);
    virtual void Draw(void);
    void SpawnRipple(const MKVector3 &, float);
    void DrawRipples(void);
    /* 0x089 */ u8 pad89[0x7];
    /* 0x090 */ Texture* unk90;
    /* 0x094 */ MKMaterial* unk94;
    /* 0x098 */ MKMaterial* unk98;
    /* 0x09c */ f32 unk9C;
    /* 0x0a0 */ u8 padA0[0x1e0];
    /* 0x280 */ s32 unk280;
    /* 0x284 */ f32 unk284;
    /* 0x288 */ f32 unk288;
};

#endif  // SPYRO_SOURCE_DAMAGESHIELDEFFECT_H
