#ifndef SPYRO_SOURCE_GUARDTOWER_H
#define SPYRO_SOURCE_GUARDTOWER_H

#include <dolphin/types.h>
#include "spyro/source/LavaSmashProp.h"

class GuardTower;
class LavaSmashProp;

class GuardTower : public LavaSmashProp {  // base: base ctor call
public:
    virtual ~GuardTower(void);
    virtual void Init(void);
    virtual void Update(void);
    GuardTower(void);
    /* 0x208 */ f32 unk208;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: undefined identifier 'unkC8'
inline GuardTower::GuardTower() {
    this->unkC8 = &__vt + 0x48;
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier 'unkC8'
inline GuardTower::~GuardTower() {
    this->unkC8 = &__vt.unk48;
}
#endif

#endif  // SPYRO_SOURCE_GUARDTOWER_H
