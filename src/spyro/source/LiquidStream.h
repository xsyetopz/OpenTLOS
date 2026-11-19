#ifndef SPYRO_SOURCE_LIQUIDSTREAM_H
#define SPYRO_SOURCE_LIQUIDSTREAM_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"

class LiquidStream;
class MKProp;

class LiquidStream : public MKProp {  // base: ctor/dtor vtable stores
public:
    virtual ~LiquidStream(void);
    virtual void Init(void);
    virtual void Deinit(void);
    virtual void Update(void);
    virtual void Draw(void);
    /* 0x04c */ s32 unk4C;
    /* 0x050 */ void* unk50;
    /* 0x054 */ u8 pad54[0x4];
    /* 0x058 */ f32 unk58;
    /* 0x05c */ f32 unk5C;
    /* 0x060 */ u8 unk60;
    /* 0x061 */ u8 pad61[0x7];
    /* 0x068 */ f64 unk68;
    /* 0x070 */ f64 unk70;
    /* 0x078 */ f64 unk78;
    /* 0x080 */ f64 unk80;
    /* 0x088 */ f64 unk88;
    /* 0x090 */ f64 unk90;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline LiquidStream::~LiquidStream() {
    s32 temp_cr0_eq_15;

    temp_cr0_eq_15 = this == NULL;
    if (temp_cr0_eq_15 == 0) {
        if (temp_cr0_eq_15 == 0) {
        }
    }
}

#endif  // SPYRO_SOURCE_LIQUIDSTREAM_H
