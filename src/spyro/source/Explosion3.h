#ifndef SPYRO_SOURCE_EXPLOSION3_H
#define SPYRO_SOURCE_EXPLOSION3_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"

class ExpShock;
class ExpSmokeAndFlamesPS;
class Explosion3;
class Explosion3Descriptor;
class ExplosionFX;
class MKIniLine;
class MKProp;
class MKPropDescriptor;
class MKVector3;
class ManagedLight;

class Explosion3 : public MKProp {  // base: ctor/dtor vtable stores
public:
    virtual ~Explosion3(void);
    virtual void Init(void);
    virtual s32 LoadDone(void);
    virtual void Deinit(void);
    virtual f32 Resolve(void);
    virtual void * Update(void);
    void Trigger(const MKVector3 &, const float &, bool, bool, const MKVector3 &, MKProp *);
    /* 0x04c */ ExpSmokeAndFlamesPS* unk4C;
    /* 0x050 */ ExpShock* unk50;
    /* 0x054 */ ExplosionFX* unk54;
    /* 0x058 */ ManagedLight* unk58;
    /* 0x05c */ s32 unk5C;
    /* 0x060 */ f32 unk60;
    /* 0x064 */ f32 unk64;
    /* 0x068 */ s32 unk68;
    /* 0x06c */ s32 unk6C;
    /* 0x070 */ u8 unk70;
};

class Explosion3Descriptor : public MKPropDescriptor {  // base: inlined ctor vtable stores
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    /* 0x044 */ u8 pad44[0x1c];
    /* 0x060 */ s32 unk60;
    /* 0x064 */ s32 unk64;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline Explosion3::~Explosion3() {
    s32 temp_cr0_eq_15;

    temp_cr0_eq_15 = this == NULL;
    if (temp_cr0_eq_15 == 0) {
        if (temp_cr0_eq_15 == 0) {
        }
    }
}

#endif  // SPYRO_SOURCE_EXPLOSION3_H
