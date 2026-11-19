#ifndef SPYRO_SOURCE_TESLATOWER_H
#define SPYRO_SOURCE_TESLATOWER_H

#include <dolphin/types.h>
#include "common/Source/Matrix.h"
#include "spyro/source/KDProp.h"

class KDProp;
class KDPropDescriptor;
class MKDynamicBone;
class MKIniLine;
class MKMaterial;
class MKMessage;
class MKVector3;
class Matrix;
class TeslaTower;
class TeslaTowerDescriptor;

class TeslaTower : public KDProp {  // base: ctor/dtor vtable stores
public:
    virtual ~TeslaTower(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Update(void);
    virtual void Draw(void);
    virtual void Message(MKMessage *);
    void UpdateTurretTurning(void);
    void ZapTarget(const MKVector3 &, const MKVector3 &);
    u8 FindZapTargets(bool);
    void DrawLightCone(void);
    void UpdateTurretBone(MKDynamicBone *, void *);
    /* 0x089 */ u8 pad89[0x7];
    /* 0x090 */ Matrix unk90;
    /* 0x11c */ u8 pad11C[0x20];
    /* 0x13c */ s32 unk13C;
    /* 0x140 */ u8 pad140[0x24];
    /* 0x164 */ s32 unk164;
    /* 0x168 */ u8 pad168[0x24];
    /* 0x18c */ s32 unk18C;
    /* 0x190 */ u8 pad190[0x28];
    /* 0x1b8 */ f64 unk1B8;
    /* 0x1c0 */ f64 unk1C0;
    /* 0x1c8 */ f32 unk1C8;
};

class TeslaTowerDescriptor : public KDPropDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    /* 0x06d */ u8 pad6D[0x3];
    /* 0x070 */ s32 unk70;
    /* 0x074 */ MKMaterial* unk74;
    /* 0x078 */ s32 unk78;
};

#endif  // SPYRO_SOURCE_TESLATOWER_H
