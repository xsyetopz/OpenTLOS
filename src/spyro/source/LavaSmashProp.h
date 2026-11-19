#ifndef SPYRO_SOURCE_LAVASMASHPROP_H
#define SPYRO_SOURCE_LAVASMASHPROP_H

#include <dolphin/types.h>
#include "spyro/source/Shatterable.h"

class LavaSmashProp;
class LavaSmashPropDescriptor;
class MKIniLine;
class MKMessage;
class Shatterable;
class ShatterableDescriptor;

class LavaSmashProp : public Shatterable {  // base: vtable prefix
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
};

class LavaSmashPropDescriptor : public ShatterableDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    LavaSmashPropDescriptor(void);
    /* 0x16c */ f32 unk16C;
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
    this->unk198 = 0.0f;
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier 'unkC8'
inline LavaSmashProp::~LavaSmashProp() {
    this->unkC8 = &__vt + 0x48;
    if ((&this->unk198 != NULL) && (&this->unk198 != NULL)) {
        KDSound_Stop((s32 *) &this->unk198);
    }
}
#endif

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline LavaSmashPropDescriptor::LavaSmashPropDescriptor() {
    return this;
}
#endif

#endif  // SPYRO_SOURCE_LAVASMASHPROP_H
