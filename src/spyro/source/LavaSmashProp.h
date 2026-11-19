#ifndef SPYRO_SOURCE_LAVASMASHPROP_H
#define SPYRO_SOURCE_LAVASMASHPROP_H

#include <dolphin/types.h>
#include "common/Source/MKVector3.h"
#include "spyro/source/Shatterable.h"

class LavaSmashProp;
class LavaSmashPropDescriptor;
class MKIniLine;
class MKMessage;
class MKVector3;
class Shatterable;
class ShatterableDescriptor;

class LavaSmashProp : public Shatterable {  // base: base ctor call
public:
    virtual ~LavaSmashProp(void);
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Reset(void);
    virtual void Update(void);
    virtual void Message(MKMessage *);
    virtual void PostShatter(void);
    LavaSmashProp(void);
    /* 0x1a8 */ s32 unk1A8;
    /* 0x1ac */ u8 pad1AC[0x24];
    /* 0x1d0 */ u8 unk1D0;
    /* 0x1d1 */ u8 pad1D1[0x7];
    /* 0x1d8 */ f64 unk1D8;
    /* 0x1e0 */ f32 unk1E0;
    /* 0x1e4 */ u8 pad1E4[0x4];
    /* 0x1e8 */ MKVector3 unk1E8;
    /* 0x1f8 */ f32 unk1F8;
    /* 0x1fc */ f32 unk1FC;
    /* 0x200 */ f32 unk200;
    /* 0x204 */ f32 unk204;
};

class LavaSmashPropDescriptor : public ShatterableDescriptor {  // base: base ctor call
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    LavaSmashPropDescriptor(void);
    /* 0x170 */ f32 unk170;
    /* 0x174 */ f32 unk174;
    /* 0x178 */ f32 unk178;
    /* 0x17c */ s32 unk17C;
    /* 0x180 */ f32 unk180;
    /* 0x184 */ f32 unk184;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: undefined identifier 'unkC8'
inline LavaSmashProp::LavaSmashProp() {
    this->unkC8 = &__vt + 0x48;
    this->unk1A8 = 0;
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier 'unkC8'
inline LavaSmashProp::~LavaSmashProp() {
    this->unkC8 = &__vt + 0x48;
    if ((&this->unk1A8 != NULL) && (&this->unk1A8 != NULL)) {
        KDSound_Stop(&this->unk1A8);
    }
}
#endif

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline LavaSmashPropDescriptor::LavaSmashPropDescriptor() {
    return this;
}
#endif

#endif  // SPYRO_SOURCE_LAVASMASHPROP_H
