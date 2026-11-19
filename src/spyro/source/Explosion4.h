#ifndef SPYRO_SOURCE_EXPLOSION4_H
#define SPYRO_SOURCE_EXPLOSION4_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"
#include "spyro/source/FlyingBurningBits.h"

class Explosion4;
class Explosion4Descriptor;
class FlyingBurningBits;
class MKIniLine;
class MKModel;
class MKProp;
class MKPropDescriptor;
class MKVector3;
class ManagedLight;

class Explosion4 : public MKProp {  // base: ctor/dtor vtable stores
public:
    virtual ~Explosion4(void);
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Update(void);
    virtual void Draw(void);
    void Trigger(const MKVector3 &, float, bool, MKProp *, int, bool, bool, bool, bool);
    /* 0x04c */ ManagedLight* unk4C;
    /* 0x050 */ f32 unk50;
    /* 0x054 */ s32 unk54;
    /* 0x058 */ f32 unk58;
    /* 0x05c */ FlyingBurningBits unk5C;
    /* 0x064 */ f32 unk64;
    /* 0x068 */ f64 unk68;
    /* 0x070 */ f64 unk70;
    /* 0x078 */ f32 unk78;
    /* 0x07c */ f32 unk7C;
    /* 0x080 */ f32 unk80;
    /* 0x084 */ u8 pad84[0x4];
    /* 0x088 */ s32 unk88;
    /* 0x08c */ s32 unk8C;
    /* 0x090 */ f32 unk90;
    /* 0x094 */ u8 unk94;
    /* 0x095 */ u8 pad95[0x3];
    /* 0x098 */ u32* unk98;
    /* 0x09c */ f32 unk9C;
    /* 0x0a0 */ f32 unkA0;
    /* 0x0a4 */ f32 unkA4;
    /* 0x0a8 */ u8 unkA8;
};

class Explosion4Descriptor : public MKPropDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void Deinit(void);
    /* 0x048 */ u8 pad48[0x18];
    /* 0x060 */ s32 unk60;
    /* 0x064 */ s32 unk64;
    /* 0x068 */ MKModel* unk68;
    /* 0x06c */ s32 unk6C;
    /* 0x070 */ s32 unk70;
};

#endif  // SPYRO_SOURCE_EXPLOSION4_H
