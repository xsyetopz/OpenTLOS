#ifndef SPYRO_SOURCE_ELECTRICSPARKS_H
#define SPYRO_SOURCE_ELECTRICSPARKS_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"

class ElectricSparks;
class MKMaterial;
class MKModel;
class MKProp;
class MKVector3;

class ElectricSparks : public MKProp {  // base: ctor/dtor vtable stores
public:
    virtual ~ElectricSparks(void);
    virtual void Init(void);
    virtual void Deinit(void);
    virtual void Update(void);
    virtual void Draw(void);
    void Emit(const MKVector3 &, const MKVector3 &, float, bool);
    /* 0x04c */ void* unk4C;
    /* 0x050 */ MKMaterial* unk50;
    /* 0x054 */ MKModel* unk54;
    /* 0x058 */ MKModel* unk58;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline ElectricSparks::~ElectricSparks() {
    s32 temp_cr0_eq_15;

    temp_cr0_eq_15 = this == NULL;
    if (temp_cr0_eq_15 == 0) {
        if (temp_cr0_eq_15 == 0) {
        }
    }
}

#endif  // SPYRO_SOURCE_ELECTRICSPARKS_H
