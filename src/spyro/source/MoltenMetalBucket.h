#ifndef SPYRO_SOURCE_MOLTENMETALBUCKET_H
#define SPYRO_SOURCE_MOLTENMETALBUCKET_H

#include <dolphin/types.h>
#include "spyro/source/GameMessages.h"
#include "spyro/source/GameProp.h"

class BreathHitMessage;
class GameProp;
class GamePropDescriptor;
class LiquidFX;
class MKIniLine;
class MKMaterial;
class MKMessage;
class MoltenMetalBucket;
class MoltenMetalBucketDescriptor;

class MoltenMetalBucket : public GameProp {  // base: base ctor call
public:
    virtual ~MoltenMetalBucket(void);
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Update(void);
    virtual void Message(MKMessage *);
    MoltenMetalBucket(void);
    void Stop(void);
    void Start(void);
    void PourStop(void);
    void Pour(void);
    /* 0x0c8 */ f64 unkC8;
    /* 0x0d0 */ f32 unkD0;
    /* 0x0d4 */ u8 padD4[0x4];
    /* 0x0d8 */ f64 unkD8;
    /* 0x0e0 */ f64 unkE0;
    /* 0x0e8 */ u8 unkE8;
    /* 0x0e9 */ u8 padE9[0x3];
    /* 0x0ec */ s32 unkEC;
    /* 0x0f0 */ u8 padF0[0x24];
    /* 0x114 */ s32 unk114;
    /* 0x118 */ u8 pad118[0x24];
    /* 0x13c */ s32 unk13C;
    /* 0x140 */ u8 pad140[0x28];
    /* 0x168 */ f64 unk168;
    /* 0x170 */ f64 unk170;
    /* 0x178 */ u8 unk178;
    /* 0x179 */ u8 pad179[0x3];
    /* 0x17c */ LiquidFX* unk17C;
    /* 0x180 */ BreathHitMessage unk180;
};

class MoltenMetalBucketDescriptor : public GamePropDescriptor {  // base: base ctor call
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void Deinit(void);
    virtual void Resolve(void);
    MoltenMetalBucketDescriptor(void);
    /* 0x0e8 */ s32 unkE8;
    /* 0x0ec */ MKMaterial* unkEC;
    /* 0x0f0 */ s32 unkF0;
    /* 0x0f4 */ s32 unkF4;
    /* 0x0f8 */ s32 unkF8;
    /* 0x0fc */ s32 unkFC;
    /* 0x100 */ s32 unk100;
    /* 0x104 */ s32 unk104;
    /* 0x108 */ s32 unk108;
    /* 0x10c */ s32 unk10C;
    /* 0x110 */ f32 unk110;
    /* 0x114 */ f32 unk114;
    /* 0x118 */ f32 unk118;
    /* 0x11c */ f32 unk11C;
    /* 0x120 */ f32 unk120;
    /* 0x124 */ f32 unk124;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline MoltenMetalBucket::MoltenMetalBucket() {
    this->unkEC = 0;
    this->unk114 = 0;
    this->unk13C = 0;
    this->unk180.unk4 = 0;
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier 'KDSound_Stop'
inline MoltenMetalBucket::~MoltenMetalBucket() {
    if ((&this->unk13C != NULL) && (&this->unk13C != NULL)) {
        KDSound_Stop((int *) &this->unk13C);
    }
    if ((&this->unk114 != NULL) && (&this->unk114 != NULL)) {
        KDSound_Stop((int *) &this->unk114);
    }
    if ((&this->unkEC != NULL) && (&this->unkEC != NULL)) {
        KDSound_Stop((int *) &this->unkEC);
    }
}
#endif

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline MoltenMetalBucketDescriptor::MoltenMetalBucketDescriptor() {
    return this;
}
#endif

#endif  // SPYRO_SOURCE_MOLTENMETALBUCKET_H
