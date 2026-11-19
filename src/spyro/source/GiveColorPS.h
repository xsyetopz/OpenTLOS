#ifndef SPYRO_SOURCE_GIVECOLORPS_H
#define SPYRO_SOURCE_GIVECOLORPS_H

#include <dolphin/types.h>
#include "common/Source/MKParticleSystem.h"

class GiveColorPS;
class MKParticleSystem;

class GiveColorPS : public MKParticleSystem {  // base: ctor/dtor vtable stores
public:
    virtual ~GiveColorPS(void);
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void UpdateParticles(void);
    GiveColorPS(void);
    /* 0x138 */ u8 pad138[0x8];
    /* 0x140 */ s32 unk140;
    /* 0x144 */ u8 pad144[0x14];
    /* 0x158 */ f64 unk158;
    /* 0x160 */ f64 unk160;
    /* 0x168 */ f64 unk168;
    /* 0x170 */ f64 unk170;
    /* 0x178 */ u8 pad178[0x10];
    /* 0x188 */ u8 unk188;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: undefined identifier 'unk144'
inline GiveColorPS::GiveColorPS() {
    this->unk140 = 0;
    this->unk144 = 0;
    this->unk148 = 0.0f;
    this->unk14C = 0;
    return this;
}
#endif

inline GiveColorPS::~GiveColorPS() {
    s32 temp_cr0_eq_15;

    temp_cr0_eq_15 = this == NULL;
    if (temp_cr0_eq_15 == 0) {
        if (temp_cr0_eq_15 == 0) {
            if (temp_cr0_eq_15 == 0) {
                if (temp_cr0_eq_15 == 0) {
                }
            }
        }
    }
}

#endif  // SPYRO_SOURCE_GIVECOLORPS_H
