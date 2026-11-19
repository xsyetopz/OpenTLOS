#ifndef SPYRO_SOURCE_ZAPCAGE_H
#define SPYRO_SOURCE_ZAPCAGE_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"

class MKProp;
class ZapCage;

class ZapCage : public MKProp {  // base: ctor/dtor vtable stores
public:
    virtual ~ZapCage(void);
    virtual void Init(void);
    virtual void Deinit(void);
    virtual void Reset(void);
    virtual void * Update(void);
    void Trigger(MKProp *, float);
    /* 0x04c */ s32 unk4C;
    /* 0x050 */ f32 unk50;
    /* 0x054 */ MKProp* unk54;
    /* 0x058 */ f32 unk58;
    /* 0x05c */ f32 unk5C;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline ZapCage::~ZapCage() {
    s32 temp_cr0_eq_15;

    temp_cr0_eq_15 = this == NULL;
    if (temp_cr0_eq_15 == 0) {
        if (temp_cr0_eq_15 == 0) {
        }
    }
}

#endif  // SPYRO_SOURCE_ZAPCAGE_H
