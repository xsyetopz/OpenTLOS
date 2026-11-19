#ifndef SPYRO_SOURCE_KDMATRIXREFPROPERTY_H
#define SPYRO_SOURCE_KDMATRIXREFPROPERTY_H

#include <dolphin/types.h>
#include "spyro/source/KDMatrixProperty.h"

class KDMatrixProperty;
class KDMatrixRefProperty;
class Matrix;

class KDMatrixRefProperty : public KDMatrixProperty {  // base: ctor/dtor vtable stores
public:
    virtual void * GetClassInfo(void) const;
    virtual s32 GetInstanceDataSize(void) const;
    virtual void InitInstance(void);
    virtual void GetPos(void) const;
    virtual s32 GetPosRef(void) const;
    virtual s32 GetMatrixRef(void) const;
    virtual void GetMatrix(Matrix *) const;
    KDMatrixRefProperty(void);
    static KDMatrixRefProperty classInfo;
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ s32 unk8;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#include <m2c_macros.h>

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline KDMatrixRefProperty::KDMatrixRefProperty() {
    this->unk4 = NULL;
    this->unkC = NULL;
    this->unk8 = 0;
    return this;
}
#endif

inline s32 KDMatrixRefProperty::GetInstanceDataSize() const {
    return 4;
}

#if 0 // DRAFT: pointer/array required
inline void KDMatrixRefProperty::InitInstance() {
    *(*KDProperty::pInstanceMem + this->unk8) = 0;
}
#endif

#if 0 // DRAFT: pointer/array required
inline s32 KDMatrixRefProperty::GetMatrixRef() const {
    return *(*KDProperty::pInstanceMem + this->unk8);
}
#endif

#if 0 // DRAFT: pointer/array required
inline void KDMatrixRefProperty::GetMatrix(Matrix *arg0) const {
    M2C_STRUCT_COPY(arg0, *(*KDProperty::pInstanceMem + this->unk8), 0x40);
}
#endif

#if 0 // DRAFT: pointer/array required
inline void KDMatrixRefProperty::GetPos() const {
    void *temp_r4_24102;

    temp_r4_24102 = *(*KDProperty::pInstanceMem + M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), s32 *, 8));
    M2C_FIELD(this, f64 *, 0) = (f64) M2C_FIELD(temp_r4_24102, f64 *, 0x30);
    M2C_FIELD(this, f64 *, 8) = (f64) M2C_FIELD(temp_r4_24102, f64 *, 0x38);
}
#endif

#if 0 // DRAFT: pointer/array required
inline s32 KDMatrixRefProperty::GetPosRef() const {
    return *(*KDProperty::pInstanceMem + this->unk8) + 0x30;
}
#endif

inline void *KDMatrixRefProperty::GetClassInfo() const {
    return &KDMatrixRefProperty::classInfo;
}

#endif  // SPYRO_SOURCE_KDMATRIXREFPROPERTY_H
