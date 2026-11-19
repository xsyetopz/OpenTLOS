#ifndef SPYRO_SOURCE_DYNAMITEEXPLOSION_H
#define SPYRO_SOURCE_DYNAMITEEXPLOSION_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"

class DynamiteExplosion;
class DynamiteExplosionDescriptor;
class MKProp;
class MKPropDescriptor;
class MKVector3;

class DynamiteExplosion : public MKProp {  // base: ctor/dtor vtable stores
public:
    class Explosion;
    virtual ~DynamiteExplosion(void);
    virtual void Init(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Update(void);
    virtual void Draw(void);
    u8 UpdateElec(DynamiteExplosion::Explosion *);
    u8 UpdateIce(DynamiteExplosion::Explosion *);
    u8 UpdateEarth(DynamiteExplosion::Explosion *);
    u8 UpdateFire(DynamiteExplosion::Explosion *);
    void TriggerElec(const MKVector3 &, float, bool);
    void TriggerIce(const MKVector3 &, float, bool);
    void TriggerEarth(const MKVector3 &, float, bool);
    void TriggerFire(const MKVector3 &, float, bool);
    void Trigger(const MKVector3 &, float, bool, int, MKProp *);
    /* 0x04c */ MKPropDescriptor* unk4C;
    /* 0x050 */ DynamiteExplosion::Explosion** unk50;
};

class DynamiteExplosionDescriptor : public MKPropDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
    virtual void Deinit(void);
    /* 0x048 */ u8 pad48[0x18];
    /* 0x060 */ s32 unk60;
    /* 0x064 */ s32 unk64;
    /* 0x068 */ s32 unk68;
    /* 0x06c */ s32 unk6C;
    /* 0x070 */ s32 unk70;
    /* 0x074 */ s32 unk74;
    /* 0x078 */ s32 unk78;
    /* 0x07c */ s32 unk7C;
    /* 0x080 */ s32 unk80;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline DynamiteExplosion::~DynamiteExplosion() {
    s32 temp_cr0_eq_15;

    temp_cr0_eq_15 = this == NULL;
    if (temp_cr0_eq_15 == 0) {
        if (temp_cr0_eq_15 == 0) {
        }
    }
}

#endif  // SPYRO_SOURCE_DYNAMITEEXPLOSION_H
