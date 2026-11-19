#ifndef SPYRO_SOURCE_FURYFX_H
#define SPYRO_SOURCE_FURYFX_H

#include <dolphin/types.h>
#include "spyro/source/KDProp.h"

class FuryFX;
class KDProp;

class FuryFX : public KDProp {  // base: ctor/dtor vtable stores
public:
    virtual ~FuryFX(void);
    virtual void Init(void);
    virtual void Deinit(void);
    virtual f32 Resolve(void);
    virtual void * Update(void);
    virtual void Draw(void);
    void SetDefaults(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline FuryFX::~FuryFX() {
    s32 temp_cr0_eq_9392;

    temp_cr0_eq_9392 = this == NULL;
    if (temp_cr0_eq_9392 == 0) {
        if (temp_cr0_eq_9392 == 0) {
            if (temp_cr0_eq_9392 == 0) {
            }
        }
    }
}

#endif  // SPYRO_SOURCE_FURYFX_H
