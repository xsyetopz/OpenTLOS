#ifndef SPYRO_SOURCE_BIGBEETLEHIVE_H
#define SPYRO_SOURCE_BIGBEETLEHIVE_H

#include <dolphin/types.h>
#include "spyro/source/Shatterable.h"

class BigBeetleHive;
class BigBeetleHiveDescriptor;
class MKIniLine;
class MKMessage;
class MKVector3;
class Shatterable;
class ShatterableDescriptor;

class BigBeetleHive : public Shatterable {  // base: base ctor call
public:
    virtual ~BigBeetleHive(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual s32 LoadDone(void);
    virtual f32 Resolve(void);
    virtual void * Update(void);
    virtual void Message(MKMessage *);
    virtual void Shatter(bool, MKVector3 *, int, MKVector3 *);
    BigBeetleHive(void);
    void EmitGoopDrips(void);
    void UpdateAttachedNests(void);
    /* 0x1a8 */ void* unk1A8;
    /* 0x1ac */ u8 pad1AC[0x3c];
    /* 0x1e8 */ f32 unk1E8;
};

class BigBeetleHiveDescriptor : public ShatterableDescriptor {  // base: base ctor call
public:
    virtual void Init(void);
    virtual void LoadDone(void);
    BigBeetleHiveDescriptor(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: undefined identifier 'unkC8'
inline BigBeetleHive::~BigBeetleHive() {
    this->unkC8 = &__vt.unk48;
}
#endif

#if 0 // DRAFT: undefined identifier 'unkC8'
inline BigBeetleHive::BigBeetleHive() {
    this->unkC8 = &__vt + 0x48;
}
#endif

inline BigBeetleHiveDescriptor::BigBeetleHiveDescriptor() {
}

#endif  // SPYRO_SOURCE_BIGBEETLEHIVE_H
