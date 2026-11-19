#ifndef SPYRO_SOURCE_COLLECTABLE2_H
#define SPYRO_SOURCE_COLLECTABLE2_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"
#include "spyro/source/KDSpline.h"

class Collectable2;
class Collectable2Descriptor;
class Collectable2_cpp;
class Corona;
class KDUniformSpline;
class MKMessage;
class MKProp;
class MKPropDescriptor;
class MKVector3;
class Matrix;

class Collectable2 : public MKProp {  // base: ctor/dtor vtable stores
public:
    virtual ~Collectable2(void);
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Update(void);
    virtual void Draw(void);
    virtual void Message(MKMessage *);
    void Collect(void);
    void InitData(const Matrix &, const MKVector3 *, const MKVector3 *, float, float, float);
    /* 0x04c */ KDUniformSpline unk4C;
    /* 0x060 */ f32 unk60;
    /* 0x064 */ MKVector3* unk64;
    /* 0x068 */ MKVector3* unk68;
    /* 0x06c */ f32 unk6C;
    /* 0x070 */ f32 unk70;
    /* 0x074 */ Corona* unk74;
    /* 0x078 */ f32 unk78;
};

class Collectable2Descriptor : public MKPropDescriptor {  // base: inlined ctor vtable stores
public:
    virtual void Init(void);
};

class Collectable2_cpp {
public:
    void __sinit(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline Collectable2::~Collectable2() {
    s32 temp_cr0_eq_877;

    temp_cr0_eq_877 = this == NULL;
    if (temp_cr0_eq_877 == 0) {
        if (temp_cr0_eq_877 == 0) {
        }
    }
}

#endif  // SPYRO_SOURCE_COLLECTABLE2_H
