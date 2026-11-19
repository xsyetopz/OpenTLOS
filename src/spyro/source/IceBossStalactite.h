#ifndef SPYRO_SOURCE_ICEBOSSSTALACTITE_H
#define SPYRO_SOURCE_ICEBOSSSTALACTITE_H

#include <dolphin/types.h>
#include "spyro/source/Shatterable.h"

class IceBossStalactite;
class IceBossStalactiteDescriptor;
class IceBossStalactiteSpawner;
class MKCollisionResult;
class MKMessage;
class MKProp;
class MKVector3;
class Shatterable;
class ShatterableDescriptor;

class IceBossStalactite : public Shatterable {  // base: vtable prefix
public:
    virtual ~IceBossStalactite(void);
    virtual void LoadDone(void);
    virtual void Update(void);
    virtual void Draw(void);
    virtual void Message(MKMessage *);
    IceBossStalactite(void);
    void Collided(MKCollisionResult *);
    void StickInGround(const MKVector3 &);
    void Fire(const MKVector3 &);
    void Drop(bool, bool);
    void Spawn(const MKVector3 &, bool, bool);
    void Shatter(bool, MKVector3 *, int, MKVector3 *);
    void MeltFX(void);
};

class IceBossStalactiteDescriptor : public ShatterableDescriptor {  // base: vtable prefix
public:
    virtual void LoadDone(void);
    IceBossStalactiteDescriptor(void);
    /* 0x16c */ s32 unk16C;
};

class IceBossStalactiteSpawner {
public:
    void GetSpawnPoint(const MKVector3 &, int);
    void Fire(const MKVector3 &);
    void DropIndividual(int, bool);
    void SpawnSingleAtPos(const MKVector3 &);
    void Spawn(const MKVector3 &);
    void Reset(void);
    void LoadDone(void);
    void Deinit(void);
    void Init(MKProp *, int, int);
    /* 0x000 */ f64 unk0;
    /* 0x008 */ f64 unk8;
    /* 0x010 */ IceBossStalactite*** unk10;
    /* 0x014 */ MKProp* unk14;
    /* 0x018 */ u8 pad18[0x4];
    /* 0x01c */ f32 unk1C;
    /* 0x020 */ s32 unk20;
};

#endif  // SPYRO_SOURCE_ICEBOSSSTALACTITE_H
