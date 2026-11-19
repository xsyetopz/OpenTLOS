#ifndef SPYRO_SOURCE_EARTHSHOCKWAVE_H
#define SPYRO_SOURCE_EARTHSHOCKWAVE_H

#include <dolphin/types.h>
#include "spyro/source/KDProp.h"

class EarthShockwave;
class KDProp;
class MKVector3;
class MKVector4;

class EarthShockwave : public KDProp {  // base: ctor/dtor vtable stores
public:
    virtual ~EarthShockwave(void);
    virtual void Init(void);
    virtual void Deinit(void);
    virtual void * Update(void);
    virtual void Draw(void);
    void Trigger(const MKVector3 &, float, bool, MKVector4);
    /* 0x090 */ f64 unk90;
    /* 0x098 */ f64 unk98;
    /* 0x0a0 */ f32 unkA0;
    /* 0x0a4 */ f32 unkA4;
    /* 0x0a8 */ s32 unkA8;
    /* 0x0ac */ u8 unkAC;
    /* 0x0ad */ u8 padAD[0x3];
    /* 0x0b0 */ f64 unkB0;
    /* 0x0b8 */ f64 unkB8;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline EarthShockwave::~EarthShockwave() {
    s32 temp_cr0_eq_15;

    temp_cr0_eq_15 = this == NULL;
    if (temp_cr0_eq_15 == 0) {
        if (temp_cr0_eq_15 == 0) {
            if (temp_cr0_eq_15 == 0) {
            }
        }
    }
}

#endif  // SPYRO_SOURCE_EARTHSHOCKWAVE_H
