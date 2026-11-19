#ifndef SPYRO_SOURCE_ICEBOSSSTOMP_H
#define SPYRO_SOURCE_ICEBOSSSTOMP_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"
#include "spyro/source/Projectile.h"

class IceBossStomp;
class IceBossStompDescriptor;
class MKCollisionResult;
class MKHeap;
class MKIniLine;
class MKProp;
class MKPropDescriptor;
class MKVector3;
class ManagedLight;
class Projectile;

class IceBossStomp : public Projectile {  // base: vtable prefix
public:
    virtual ~IceBossStomp(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Update(void);
    virtual void Draw(void);
    virtual void Disable(void);
    virtual void Activate(void);
    virtual void Deactivate(void);
    virtual void Fire(const MKVector3 &, const MKVector3 &, MKProp *, int, int);
    virtual void Collided(MKCollisionResult &);
    IceBossStomp(void);
    void ShatterIceShards(void);
    void UpdateIceCrystals(void);
    void EmitSnowRing(void);
    void SpawnIceCrystal(const MKVector3 &);
    MKProp * CreateInstance(int);
    /* 0x14d */ u8 pad14D[0x13];
    /* 0x160 */ ManagedLight* unk160;
    /* 0x164 */ MKHeap* unk164;
    /* 0x168 */ f32 unk168;
    /* 0x16c */ f32 unk16C;
    /* 0x170 */ void* unk170;
};

class IceBossStompDescriptor : public MKPropDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    IceBossStompDescriptor(void);
    /* 0x048 */ u8 pad48[0xa8];
    /* 0x0f0 */ s32 unkF0;
    /* 0x0f4 */ s32 unkF4;
    /* 0x0f8 */ s8* unkF8;
    /* 0x0fc */ s32 unkFC;
};

#endif  // SPYRO_SOURCE_ICEBOSSSTOMP_H
