#ifndef SPYRO_SOURCE_FROZENGROUNDPROP_H
#define SPYRO_SOURCE_FROZENGROUNDPROP_H

#include <dolphin/types.h>
#include "spyro/source/KDProp.h"

class FrozenGroundProp;
class KDProp;

class FrozenGroundProp : public KDProp {  // base: ctor/dtor vtable stores
public:
    virtual ~FrozenGroundProp(void);
    virtual void Init(void);
    virtual void Deinit(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline FrozenGroundProp::~FrozenGroundProp() {
    s32 temp_cr0_eq_15;

    temp_cr0_eq_15 = this == NULL;
    if (temp_cr0_eq_15 == 0) {
        if (temp_cr0_eq_15 == 0) {
            if (temp_cr0_eq_15 == 0) {
            }
        }
    }
}

#endif  // SPYRO_SOURCE_FROZENGROUNDPROP_H
