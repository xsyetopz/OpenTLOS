#ifndef SPYRO_SOURCE_ELECZAPCRYSTAL_H
#define SPYRO_SOURCE_ELECZAPCRYSTAL_H

#include <dolphin/types.h>
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "spyro/source/KDProp.h"

class ElecZapCrystal;
class KDProp;
class MKVector3;
class MKVector4;

class ElecZapCrystal : public KDProp {  // base: ctor/dtor vtable stores
public:
    virtual ~ElecZapCrystal(void);
    virtual void Init(void);
    virtual s32 LoadDone(void);
    virtual void Deinit(void);
    virtual void * Update(void);
    virtual void Draw(void);
    void TriggerSubObjFader(int, float);
    /* 0x090 */ s32 unk90;
    /* 0x094 */ u8 pad94[0x1c];
    /* 0x0b0 */ void* unkB0;
    /* 0x0b4 */ s32 unkB4;
    /* 0x0b8 */ s32 unkB8;
    /* 0x0bc */ f32 unkBC;
    /* 0x0c0 */ f32 unkC0;
    /* 0x0c4 */ u8 padC4[0x4];
    /* 0x0c8 */ MKVector4 unkC8;
    /* 0x0d8 */ MKVector3 unkD8;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline ElecZapCrystal::~ElecZapCrystal() {
    s32 temp_cr0_eq_15;

    temp_cr0_eq_15 = this == NULL;
    if (temp_cr0_eq_15 == 0) {
        if (temp_cr0_eq_15 == 0) {
            if (temp_cr0_eq_15 == 0) {
            }
        }
    }
}

#endif  // SPYRO_SOURCE_ELECZAPCRYSTAL_H
