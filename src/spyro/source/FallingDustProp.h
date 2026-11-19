#ifndef SPYRO_SOURCE_FALLINGDUSTPROP_H
#define SPYRO_SOURCE_FALLINGDUSTPROP_H

#include <dolphin/types.h>
#include "common/Source/MKVector4.h"
#include "spyro/source/KDProp.h"

class FallingDustProp;
class FallingDustPropDescriptor;
class KDProp;
class KDPropDescriptor;
class MKMaterial;
class MKMessage;
class MKVector4;

class FallingDustProp : public KDProp {  // base: ctor/dtor vtable stores
public:
    virtual ~FallingDustProp(void);
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Update(void);
    virtual void Draw(void);
    virtual void Message(MKMessage *);
    void Trigger(void);
    /* 0x090 */ s32 unk90;
    /* 0x094 */ s32 unk94;
    /* 0x098 */ s32 unk98;
    /* 0x09c */ s32 unk9C;
    /* 0x0a0 */ f32 unkA0;
    /* 0x0a4 */ s32 unkA4;
    /* 0x0a8 */ MKMaterial* unkA8;
    /* 0x0ac */ f32 unkAC;
    /* 0x0b0 */ MKVector4 unkB0;
};

class FallingDustPropDescriptor : public KDPropDescriptor {  // base: inlined ctor vtable stores
public:
    virtual void Init(void);
    /* 0x070 */ s32 unk70;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline FallingDustProp::~FallingDustProp() {
    s32 temp_cr0_eq_15;

    temp_cr0_eq_15 = this == NULL;
    if (temp_cr0_eq_15 == 0) {
        if (temp_cr0_eq_15 == 0) {
            if (temp_cr0_eq_15 == 0) {
            }
        }
    }
}

#endif  // SPYRO_SOURCE_FALLINGDUSTPROP_H
