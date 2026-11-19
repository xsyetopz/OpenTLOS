#ifndef SPYRO_SOURCE_WATERTRICKLEEMITTER_H
#define SPYRO_SOURCE_WATERTRICKLEEMITTER_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"
#include "common/Source/Matrix.h"
#include "spyro/source/KDPath.h"

class KDPathSegment;
class MKIniLine;
class MKProp;
class MKPropDescriptor;
class Matrix;
class WaterTrickleEmitter;
class WaterTrickleEmitterDescriptor;

class WaterTrickleEmitter : public MKProp {  // base: ctor/dtor vtable stores
public:
    virtual ~WaterTrickleEmitter(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Update(void);
    /* 0x04c */ KDPathSegment unk4C;
    /* 0x080 */ f32 unk80;
    /* 0x084 */ s32 unk84;
    /* 0x088 */ f32 unk88;
    /* 0x08c */ f32 unk8C;
    /* 0x090 */ f32 unk90;
    /* 0x094 */ u8 unk94;
    /* 0x095 */ u8 pad95[0xb];
    /* 0x0a0 */ Matrix unkA0;
};

class WaterTrickleEmitterDescriptor : public MKPropDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
    /* 0x048 */ u8 pad48[0x20];
    /* 0x068 */ f64 unk68;
    /* 0x070 */ f64 unk70;
    /* 0x078 */ f64 unk78;
};

#endif  // SPYRO_SOURCE_WATERTRICKLEEMITTER_H
