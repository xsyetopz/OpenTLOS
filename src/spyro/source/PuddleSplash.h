#ifndef SPYRO_SOURCE_PUDDLESPLASH_H
#define SPYRO_SOURCE_PUDDLESPLASH_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"

class MKProp;
class MKPropDescriptor;
class MKVector3;
class PuddleSplash;
class PuddleSplashDescriptor;

class PuddleSplash : public MKProp {  // base: ctor/dtor vtable stores
public:
    virtual ~PuddleSplash(void);
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Update(void);
    virtual void Draw(void);
    void Emit(const MKVector3 &, const float &, bool);
    /* 0x04c */ void* unk4C;
};

class PuddleSplashDescriptor : public MKPropDescriptor {  // base: inlined ctor vtable stores
public:
    virtual void Init(void);
    virtual void Deinit(void);
    /* 0x044 */ u8 pad44[0x1c];
    /* 0x060 */ s32 unk60;
    /* 0x064 */ s32 unk64;
    /* 0x068 */ s32 unk68;
    /* 0x06c */ s32 unk6C;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline PuddleSplash::~PuddleSplash() {
    s32 temp_cr0_eq_15;

    temp_cr0_eq_15 = this == NULL;
    if (temp_cr0_eq_15 == 0) {
        if (temp_cr0_eq_15 == 0) {
        }
    }
}

#endif  // SPYRO_SOURCE_PUDDLESPLASH_H
