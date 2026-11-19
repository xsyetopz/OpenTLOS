#ifndef SPYRO_SOURCE_BARRICADE_H
#define SPYRO_SOURCE_BARRICADE_H

#include <dolphin/types.h>
#include "spyro/source/Shatterable.h"

class BarricadeProp;
class MKMessage;
class MKVector3;
class Shatterable;

class BarricadeProp : public Shatterable {  // base: base ctor call
public:
    virtual ~BarricadeProp(void);
    virtual void Init(void);
    virtual s32 LoadDone(void);
    virtual void Deinit(void);
    virtual f32 Resolve(void);
    virtual void * Update(void);
    virtual void Message(MKMessage *);
    virtual s32 GetMoveToPoint(const MKVector3 &, MKVector3 *);
    virtual s32 GetLookToPoint(const MKVector3 &, MKVector3 *);
    BarricadeProp(void);
    /* 0x1a8 */ s32 unk1A8;
    /* 0x1ac */ u8 unk1AC;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: undefined identifier 'unkC8'
inline BarricadeProp::~BarricadeProp() {
    this->unkC8 = &__vt.unk48;
}
#endif

#if 0 // DRAFT: undefined identifier 'unkC8'
inline BarricadeProp::BarricadeProp() {
    this->unkC8 = &__vt + 0x48;
}
#endif

#endif  // SPYRO_SOURCE_BARRICADE_H
