#ifndef SPYRO_SOURCE_SWARM_H
#define SPYRO_SOURCE_SWARM_H

#include <dolphin/types.h>
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "spyro/source/KDProp.h"

class KDProp;
class KDPropDescriptor;
class MKIniLine;
class MKMessage;
class MKVector3;
class MKVector4;
class Matrix;
class SwarmEntity;
class SwarmProp;
class SwarmPropDescriptor;

class SwarmEntity {
public:
    /* 0x000 */ f64 unk0;
    /* 0x008 */ f64 unk8;
    /* 0x010 */ f64 unk10;
    /* 0x018 */ f64 unk18;
    /* 0x020 */ f64 unk20;
    /* 0x028 */ f64 unk28;
    /* 0x030 */ f32 unk30;
    /* 0x034 */ void* unk34;
};

class SwarmProp : public KDProp {  // base: ctor/dtor vtable stores
public:
    virtual ~SwarmProp(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Reset(void);
    virtual void Update(void);
    virtual void Draw(void);
    virtual void Message(MKMessage *);
    void DrawEntity(SwarmEntity *, const Matrix &, const MKVector4 &, float);
    /* 0x089 */ u8 pad89[0x7];
    /* 0x090 */ Matrix unk90;
    /* 0x0d0 */ MKVector3 unkD0;
    /* 0x0e0 */ u8 padE0[0x8];
    /* 0x0e8 */ f64 unkE8;
    /* 0x0f0 */ s32 unkF0;
    /* 0x0f4 */ SwarmEntity** unkF4;
};

class SwarmPropDescriptor : public KDPropDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
    /* 0x06d */ u8 pad6D[0xb];
    /* 0x078 */ f64 unk78;
    /* 0x080 */ f64 unk80;
    /* 0x088 */ f64 unk88;
    /* 0x090 */ s32 unk90;
};

#endif  // SPYRO_SOURCE_SWARM_H
