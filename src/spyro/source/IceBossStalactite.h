#ifndef SPYRO_SOURCE_ICEBOSSSTALACTITE_H
#define SPYRO_SOURCE_ICEBOSSSTALACTITE_H

#include <dolphin/types.h>
#include "common/Source/MKVector3.h"
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

class IceBossStalactite : public Shatterable {  // base: base ctor call
public:
    virtual ~IceBossStalactite(void);
    virtual s32 LoadDone(void);
    virtual void * Update(void);
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
    /* 0x1a8 */ f64 unk1A8;
    /* 0x1b0 */ f64 unk1B0;
    /* 0x1b8 */ f32 unk1B8;
    /* 0x1bc */ f32 unk1BC;
    /* 0x1c0 */ f32 unk1C0;
    /* 0x1c4 */ u8 pad1C4[0x4];
    /* 0x1c8 */ f64 unk1C8;
    /* 0x1d0 */ f64 unk1D0;
    /* 0x1d8 */ f64 unk1D8;
    /* 0x1e0 */ f64 unk1E0;
    /* 0x1e8 */ f64 unk1E8;
    /* 0x1f0 */ f64 unk1F0;
    /* 0x1f8 */ MKVector3 unk1F8;
    /* 0x208 */ f64 unk208;
    /* 0x210 */ f32 unk210;
    /* 0x214 */ u8 pad214[0x4];
    /* 0x218 */ f32 unk218;
    /* 0x21c */ MKProp* unk21C;
    /* 0x220 */ IceBossStalactiteSpawner* unk220;
    /* 0x224 */ void* unk224;
    /* 0x228 */ f32 unk228;
    /* 0x22c */ f32 unk22C;
    /* 0x230 */ s32 unk230;
    /* 0x234 */ f32 unk234;
    /* 0x238 */ f32 unk238;
    /* 0x23c */ f32 unk23C;
    /* 0x240 */ s32 unk240;
    /* 0x244 */ u8 unk244;
    /* 0x245 */ u8 unk245;
    /* 0x246 */ u8 unk246;
};

class IceBossStalactiteDescriptor : public ShatterableDescriptor {  // base: base ctor call
public:
    virtual void LoadDone(void);
    IceBossStalactiteDescriptor(void);
};

class IceBossStalactiteSpawner {
public:
    MKVector3 GetSpawnPoint(const MKVector3 &, int);
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
    /* 0x018 */ f64 unk18;
    /* 0x020 */ s32 unk20;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: undefined identifier 'unkC8'
inline IceBossStalactite::IceBossStalactite() {
    this->unkC8 = &__vt + 0x48;
}
#endif

#if 0 // DRAFT: undefined identifier 'unkC8'
inline IceBossStalactite::~IceBossStalactite() {
    this->unkC8 = &__vt.unk48;
}
#endif

inline IceBossStalactiteDescriptor::IceBossStalactiteDescriptor() {
}

#endif  // SPYRO_SOURCE_ICEBOSSSTALACTITE_H
