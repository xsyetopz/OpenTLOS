#ifndef SPYRO_SOURCE_ELEMENTALRING_H
#define SPYRO_SOURCE_ELEMENTALRING_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"

class ElementalRing;
class ElementalRingDescriptor;
class KDSoundFlangedFader;
class MKMessage;
class MKProp;
class MKPropDescriptor;
class MKVector3;

class ElementalRing : public MKProp {  // base: ctor/dtor vtable stores
public:
    virtual ~ElementalRing(void);
    virtual void Init(void);
    virtual void Deinit(void);
    virtual void Update(void);
    virtual void Draw(void);
    virtual void Message(MKMessage *);
    void Trigger(const MKVector3 &, const MKVector3 &, int, bool, MKProp *, float, float, float, float);
    /* 0x04c */ KDSoundFlangedFader** unk4C;
    /* 0x050 */ f32 unk50;
};

class ElementalRingDescriptor : public MKPropDescriptor {  // base: inlined ctor vtable stores
public:
    virtual void Init(void);
    virtual void Deinit(void);
    /* 0x044 */ u8 pad44[0x1c];
    /* 0x060 */ s32 unk60;
    /* 0x064 */ s32 unk64;
    /* 0x068 */ s32 unk68;
    /* 0x06c */ s32 unk6C;
    /* 0x070 */ s32 unk70;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline ElementalRing::~ElementalRing() {
    s32 temp_cr0_eq_15;

    temp_cr0_eq_15 = this == NULL;
    if (temp_cr0_eq_15 == 0) {
        if (temp_cr0_eq_15 == 0) {
        }
    }
}

#endif  // SPYRO_SOURCE_ELEMENTALRING_H
