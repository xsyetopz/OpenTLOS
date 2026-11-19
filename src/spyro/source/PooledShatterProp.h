#ifndef SPYRO_SOURCE_POOLEDSHATTERPROP_H
#define SPYRO_SOURCE_POOLEDSHATTERPROP_H

#include <dolphin/types.h>
#include "spyro/source/Shatterable.h"

class PooledShatterProp;
class Shatterable;

class PooledShatterProp : public Shatterable {  // base: base ctor call
public:
    virtual ~PooledShatterProp(void);
    virtual void * Update(void);
    PooledShatterProp(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: undefined identifier 'unkC8'
inline PooledShatterProp::PooledShatterProp() {
    this->unkC8 = &__vt + 0x48;
}
#endif

#if 0 // DRAFT: undefined identifier 'unkC8'
inline PooledShatterProp::~PooledShatterProp() {
    this->unkC8 = &__vt + 0x48;
}
#endif

#endif  // SPYRO_SOURCE_POOLEDSHATTERPROP_H
