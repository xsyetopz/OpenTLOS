#ifndef SPYRO_SOURCE_HITFX_H
#define SPYRO_SOURCE_HITFX_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"

class HitFX;
class MKMaterial;
class MKProp;
class MKVector3;
class MKVector4;
class ManagedLight;

class HitFX : public MKProp {  // base: ctor/dtor vtable stores
public:
    virtual ~HitFX(void);
    virtual void Init(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Update(void);
    virtual void Draw(void);
    void Trigger(const MKVector3 &, const MKVector3 &, const MKVector4 &, int);
    /* 0x04c */ f32 unk4C;
    /* 0x050 */ u8 unk50;
    /* 0x051 */ u8 pad51[0x7];
    /* 0x058 */ f64 unk58;
    /* 0x060 */ f64 unk60;
    /* 0x068 */ f32 unk68;
    /* 0x06c */ f32 unk6C;
    /* 0x070 */ f32 unk70;
    /* 0x074 */ u8 pad74[0x4];
    /* 0x078 */ void* unk78;
    /* 0x07c */ void* unk7C;
    /* 0x080 */ void* unk80;
    /* 0x084 */ ManagedLight* unk84;
    /* 0x088 */ f32 unk88;
    /* 0x08c */ MKMaterial* unk8C;
    /* 0x090 */ f32 unk90;
    /* 0x094 */ f32 unk94;
};

#endif  // SPYRO_SOURCE_HITFX_H
