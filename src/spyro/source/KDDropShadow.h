#ifndef SPYRO_SOURCE_KDDROPSHADOW_H
#define SPYRO_SOURCE_KDDROPSHADOW_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"

class KDDropShadow;
class KDDropShadowDescriptor;
class MKHeap;
class MKIniLine;
class MKProp;
class MKPropDescriptor;
class Matrix;

class KDDropShadow : public MKProp {  // base: ctor/dtor vtable stores
public:
    virtual ~KDDropShadow(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Reset(void);
    virtual void Draw(void);
    /* 0x04c */ MKHeap* unk4C;
    /* 0x050 */ Matrix* unk50;
    /* 0x054 */ Matrix* unk54;
};

class KDDropShadowDescriptor : public MKPropDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    /* 0x044 */ u8 pad44[0x1c];
    /* 0x060 */ s32 unk60;
    /* 0x064 */ f32 unk64;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline KDDropShadow::~KDDropShadow() {
    s32 temp_cr0_eq_15;

    temp_cr0_eq_15 = this == NULL;
    if (temp_cr0_eq_15 == 0) {
        if (temp_cr0_eq_15 == 0) {
        }
    }
}

#endif  // SPYRO_SOURCE_KDDROPSHADOW_H
