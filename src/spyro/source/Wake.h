#ifndef SPYRO_SOURCE_WAKE_H
#define SPYRO_SOURCE_WAKE_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"
#include "common/Source/Matrix.h"

class MKMaterial;
class MKProp;
class Matrix;
class Wake;

class Wake : public MKProp {  // base: ctor/dtor vtable stores
public:
    virtual ~Wake(void);
    virtual void Init(void);
    virtual void Deinit(void);
    virtual void Reset(void);
    virtual void * Update(void);
    virtual void Draw(void);
    s32 GetWakeLength(int);
    /* 0x04c */ MKMaterial* unk4C;
    /* 0x050 */ s32 unk50;
    /* 0x054 */ s32 unk54;
    /* 0x058 */ s32 unk58;
    /* 0x05c */ void* unk5C;
    /* 0x060 */ Matrix unk60;
    /* 0x0a0 */ f32 unkA0;
    /* 0x0a4 */ f32 unkA4;
    /* 0x0a8 */ f32 unkA8;
    /* 0x0ac */ u8 padAC[0x4];
    /* 0x0b0 */ f64 unkB0;
    /* 0x0b8 */ f64 unkB8;
    /* 0x0c0 */ u32 unkC0;
    /* 0x0c4 */ f32 unkC4;
    /* 0x0c8 */ u8 padC8[0x4];
    /* 0x0cc */ f32 unkCC;
    /* 0x0d0 */ f32 unkD0;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline Wake::~Wake() {
    s32 temp_cr0_eq_15;

    temp_cr0_eq_15 = this == NULL;
    if (temp_cr0_eq_15 == 0) {
        if (temp_cr0_eq_15 == 0) {
        }
    }
}

#endif  // SPYRO_SOURCE_WAKE_H
