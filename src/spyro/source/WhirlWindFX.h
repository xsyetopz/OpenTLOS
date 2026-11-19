#ifndef SPYRO_SOURCE_WHIRLWINDFX_H
#define SPYRO_SOURCE_WHIRLWINDFX_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"

class MKHeap;
class MKProp;
class WhirlWindFX;

class WhirlWindFX : public MKProp {  // base: ctor/dtor vtable stores
public:
    class WhirlWind;
    virtual ~WhirlWindFX(void);
    virtual void Init(void);
    virtual void Deinit(void);
    virtual void * Update(void);
    virtual void Draw(void);
    static void DrawWhirlWind(WhirlWindFX::WhirlWind *);
    /* 0x04c */ MKHeap* unk4C;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline WhirlWindFX::~WhirlWindFX() {
    s32 temp_cr0_eq_15;

    temp_cr0_eq_15 = this == NULL;
    if (temp_cr0_eq_15 == 0) {
        if (temp_cr0_eq_15 == 0) {
        }
    }
}

#endif  // SPYRO_SOURCE_WHIRLWINDFX_H
