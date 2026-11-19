#ifndef SPYRO_SOURCE_ENEMYDEATHFX_H
#define SPYRO_SOURCE_ENEMYDEATHFX_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"

class Corona;
class EnemyDeathFX;
class MKProp;
class MKVector3;

class EnemyDeathFX : public MKProp {  // base: ctor/dtor vtable stores
public:
    virtual ~EnemyDeathFX(void);
    virtual void Init(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Update(void);
    virtual void Draw(void);
    void Trigger(int *, const MKVector3 &, float, int);
    /* 0x04c */ u8 pad4C[0x4];
    /* 0x050 */ f64 unk50;
    /* 0x058 */ f64 unk58;
    /* 0x060 */ f32 unk60;
    /* 0x064 */ Corona* unk64;
    /* 0x068 */ f32 unk68;
    /* 0x06c */ u8 unk6C;
};

#endif  // SPYRO_SOURCE_ENEMYDEATHFX_H
